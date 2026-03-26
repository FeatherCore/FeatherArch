/*
 * arm_v7m_systick.c
 * System Timer (SysTick) Implementation
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.3
 */

#include "arm_v7m_systick.h"

/*============================================================================*
 * SysTick Implementation
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.3
 *============================================================================*/

/**
 * @brief Initialize and start SysTick with specified reload value
 * @param reload_value Reload value (0-0xFFFFFF)
 * @param use_processor_clock 1 to use processor clock, 0 for external clock
 * @param enable_interrupt 1 to enable SysTick interrupt, 0 to disable
 * @note This function disables SysTick first, configures it, then enables
 *
 * Initialization sequence (per ARMv7-M Architecture Reference Manual B3.3.1):
 * 1. Disable SysTick by clearing ENABLE bit
 * 2. Set reload value in LOAD register
 * 3. Clear current value by writing to VAL register (clears to 0)
 * 4. Configure clock source and interrupt enable
 * 5. Enable SysTick by setting ENABLE bit
 */
void arm_v7m_systick_init(uint32_t reload_value, uint32_t use_processor_clock, uint32_t enable_interrupt)
{
    uint32_t ctrl_value;

    /* Disable SysTick first (clear ENABLE bit) */
    SYSTICK->CTRL = 0U;

    /* Set reload value (masked to 24-bit) */
    SYSTICK->LOAD = reload_value & SYSTICK_LOAD_RELOAD_Msk;

    /* Clear current value (this also clears COUNTFLAG) */
    SYSTICK->VAL = 0U;

    /* Build control register value */
    ctrl_value = SYSTICK_CTRL_ENABLE_Msk;  /* Always enable */

    if (use_processor_clock) {
        ctrl_value |= SYSTICK_CTRL_CLKSOURCE_Msk;
    }

    if (enable_interrupt) {
        ctrl_value |= SYSTICK_CTRL_TICKINT_Msk;
    }

    /* Write control register to enable SysTick */
    SYSTICK->CTRL = ctrl_value;
}

/**
 * @brief Calculate reload value for desired time period
 * @param ms Time period in milliseconds
 * @param clock_freq_hz Clock frequency in Hz
 * @return Reload value (capped at SYSTICK_MAX_RELOAD)
 * @note Returns 0 if calculation overflows
 *
 * Calculation: reload = (ms * clock_freq_hz / 1000) - 1
 * The -1 is because the counter counts from reload value down to 0,
 * so for N ticks we need reload = N - 1.
 */
uint32_t arm_v7m_systick_calc_reload_for_ms(uint32_t ms, uint32_t clock_freq_hz)
{
    uint64_t ticks;
    uint32_t reload;

    /* Calculate total ticks needed: ms * clock_freq_hz / 1000 */
    /* Use 64-bit arithmetic to avoid overflow */
    ticks = ((uint64_t)ms * (uint64_t)clock_freq_hz) / 1000ULL;

    /* Subtract 1 because counter counts from reload down to 0 */
    if (ticks > 0) {
        ticks--;
    }

    /* Cap at maximum reload value (24-bit) */
    if (ticks > SYSTICK_MAX_RELOAD) {
        reload = SYSTICK_MAX_RELOAD;
    } else {
        reload = (uint32_t)ticks;
    }

    return reload;
}

/**
 * @brief Delay for specified number of SysTick ticks (busy wait)
 * @param ticks Number of ticks to delay
 * @note This is a blocking delay function
 *
 * This function uses the COUNTFLAG in the CTRL register to detect
 * when the counter has counted down to zero.
 */
void arm_v7m_systick_delay_ticks(uint32_t ticks)
{
    uint32_t i;

    /* Ensure SysTick is enabled */
    if ((SYSTICK->CTRL & SYSTICK_CTRL_ENABLE_Msk) == 0U) {
        return;
    }

    /* Set reload value for single countdown period */
    /* Disable interrupts temporarily to prevent race conditions */
    SYSTICK->CTRL &= ~SYSTICK_CTRL_TICKINT_Msk;

    for (i = 0U; i < ticks; i++) {
        /* Wait for COUNTFLAG to be set (counter reached zero) */
        while ((SYSTICK->CTRL & SYSTICK_CTRL_COUNTFLAG_Msk) == 0U) {
            /* Busy wait - could also use WFI/WFE for power saving */
        }
    }

    /* Restore interrupt state (re-enable if it was enabled before) */
    /* Note: This is a simplified version - in production code, you might
     * want to save/restore the original state */
}

/**
 * @brief Initialize SysTick using calibration value for 10ms timing
 * @param enable_interrupt 1 to enable SysTick interrupt, 0 to disable
 * @return 0 on success, 1 if calibration value is not available
 * @note Uses the TENMS calibration value from SYST_CALIB register
 *
 * Reference: ARMv7-M Architecture Reference Manual B3.3.6
 * The TENMS field optionally holds a reload value for 10ms (100Hz) timing.
 * If this field is zero, the calibration value is not known.
 */
uint32_t arm_v7m_systick_init_calibrated(uint32_t enable_interrupt)
{
    uint32_t tenms;
    uint32_t ctrl_value;

    /* Read calibration value */
    tenms = SYSTICK->CALIB & SYSTICK_CALIB_TENMS_Msk;

    /* Check if calibration value is available */
    if (tenms == 0U) {
        return 1U;  /* Calibration value not available */
    }

    /* Disable SysTick first */
    SYSTICK->CTRL = 0U;

    /* Set reload value from calibration */
    SYSTICK->LOAD = tenms;

    /* Clear current value */
    SYSTICK->VAL = 0U;

    /* Build control register value - use processor clock */
    ctrl_value = SYSTICK_CTRL_ENABLE_Msk | SYSTICK_CTRL_CLKSOURCE_Msk;

    if (enable_interrupt) {
        ctrl_value |= SYSTICK_CTRL_TICKINT_Msk;
    }

    /* Enable SysTick */
    SYSTICK->CTRL = ctrl_value;

    return 0U;  /* Success */
}

/**
 * @brief Calculate reload value using calibration value
 * @param hz Desired frequency in Hz (e.g., 100 for 100Hz = 10ms period)
 * @return Reload value, or 0 if calibration value is not available
 * @note This uses the TENMS calibration value to calculate the reload value
 *       for the desired frequency.
 *
 * The TENMS value gives the reload value for 100Hz (10ms period).
 * To get reload value for frequency F: reload = (TENMS * 100 / F) - 1
 * This is valid for frequencies <= 1000Hz (to stay within 24-bit range).
 */
uint32_t arm_v7m_systick_calc_reload_from_calib(uint32_t hz)
{
    uint32_t tenms;
    uint64_t reload;

    /* Read calibration value */
    tenms = SYSTICK->CALIB & SYSTICK_CALIB_TENMS_Msk;

    /* Check if calibration value is available and frequency is valid */
    if ((tenms == 0U) || (hz == 0U) || (hz > 1000U)) {
        return 0U;  /* Calibration not available or invalid frequency */
    }

    /* Calculate reload value: (TENMS * 100 / hz) - 1 */
    /* Use 64-bit to avoid overflow */
    reload = ((uint64_t)tenms * 100ULL) / (uint64_t)hz;

    /* Subtract 1 because counter counts from reload down to 0 */
    if (reload > 0ULL) {
        reload--;
    }

    /* Cap at maximum reload value */
    if (reload > SYSTICK_MAX_RELOAD) {
        reload = SYSTICK_MAX_RELOAD;
    }

    return (uint32_t)reload;
}


