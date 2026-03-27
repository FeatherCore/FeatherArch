/*
 * arm_v7m_systick.h
 * System Timer (SysTick) Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.3
 */

#ifndef ARM_V7M_SYSTICK_H
#define ARM_V7M_SYSTICK_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * SysTick Base Address (Architecture defined)
 * Reference: ARMv7-M Architecture Reference Manual, Table B3-7
 *            - SysTick register summary on page B3-621
 *============================================================================*/
#define SYSTICK_BASE        0xE000E010UL

/*============================================================================*
 * SysTick Type Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Table B3-7
 *            - SysTick register summary on page B3-621
 *============================================================================*/

typedef struct {
    volatile uint32_t CTRL;                 /*!< Offset: 0x00 (R/W)  SysTick Control and Status Register */
    volatile uint32_t LOAD;                 /*!< Offset: 0x04 (R/W)  SysTick Reload Value Register */
    volatile uint32_t VAL;                  /*!< Offset: 0x08 (R/W)  SysTick Current Value Register */
    volatile const uint32_t CALIB;          /*!< Offset: 0x0C (R/ )  SysTick Calibration Value Register */
} arm_v7m_systick_regs_t;

#define SYSTICK             ((arm_v7m_systick_regs_t *)SYSTICK_BASE)

/*============================================================================*
 * SysTick CTRL Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.3.3
 *============================================================================*/

/* ENABLE: Counter enable */
#define SYSTICK_CTRL_ENABLE_Pos          0U
#define SYSTICK_CTRL_ENABLE_Msk         (1UL << SYSTICK_CTRL_ENABLE_Pos)

/* TICKINT: SysTick exception request enable */
#define SYSTICK_CTRL_TICKINT_Pos         1U
#define SYSTICK_CTRL_TICKINT_Msk        (1UL << SYSTICK_CTRL_TICKINT_Pos)

/* CLKSOURCE: Clock source selection */
#define SYSTICK_CTRL_CLKSOURCE_Pos       2U
#define SYSTICK_CTRL_CLKSOURCE_Msk      (1UL << SYSTICK_CTRL_CLKSOURCE_Pos)

/* COUNTFLAG: Returns 1 if timer counted to 0 since last time this was read */
#define SYSTICK_CTRL_COUNTFLAG_Pos      16U
#define SYSTICK_CTRL_COUNTFLAG_Msk      (1UL << SYSTICK_CTRL_COUNTFLAG_Pos)

/* Clock Source Values */
#define SYSTICK_CLKSOURCE_EXTERNAL      0U  /*!< External reference clock */
#define SYSTICK_CLKSOURCE_PROCESSOR     1U  /*!< Processor clock (AHB clock) */

/*============================================================================*
 * SysTick LOAD Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.3.4
 *============================================================================*/
#define SYSTICK_LOAD_RELOAD_Pos          0U
#define SYSTICK_LOAD_RELOAD_Msk         (0xFFFFFFUL << SYSTICK_LOAD_RELOAD_Pos)

/* Maximum reload value (24-bit) */
#define SYSTICK_MAX_RELOAD              0x00FFFFFFUL

/*============================================================================*
 * SysTick VAL Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.3.5
 *============================================================================*/
#define SYSTICK_VAL_CURRENT_Pos          0U
#define SYSTICK_VAL_CURRENT_Msk         (0xFFFFFFUL << SYSTICK_VAL_CURRENT_Pos)

/*============================================================================*
 * SysTick CALIB Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.3.6
 *============================================================================*/

/* NOREF: Indicates whether the IMPLEMENTATION DEFINED reference clock is implemented */
#define SYSTICK_CALIB_NOREF_Pos         31U
#define SYSTICK_CALIB_NOREF_Msk        (1UL << SYSTICK_CALIB_NOREF_Pos)

/* SKEW: Indicates whether the 10ms calibration value is exact */
#define SYSTICK_CALIB_SKEW_Pos          30U
#define SYSTICK_CALIB_SKEW_Msk         (1UL << SYSTICK_CALIB_SKEW_Pos)

/* TENMS: 10ms calibration value */
#define SYSTICK_CALIB_TENMS_Pos          0U
#define SYSTICK_CALIB_TENMS_Msk        (0xFFFFFFUL << SYSTICK_CALIB_TENMS_Pos)

/*============================================================================*
 * Inline Functions - SysTick Basic Operations
 *============================================================================*/

/**
 * @brief Enable SysTick counter
 */
static inline void arm_v7m_systick_enable(void)
{
    SYSTICK->CTRL |= SYSTICK_CTRL_ENABLE_Msk;
}

/**
 * @brief Disable SysTick counter
 */
static inline void arm_v7m_systick_disable(void)
{
    SYSTICK->CTRL &= ~SYSTICK_CTRL_ENABLE_Msk;
}

/**
 * @brief Enable SysTick exception request (TICKINT)
 */
static inline void arm_v7m_systick_enable_interrupt(void)
{
    SYSTICK->CTRL |= SYSTICK_CTRL_TICKINT_Msk;
}

/**
 * @brief Disable SysTick exception request (TICKINT)
 */
static inline void arm_v7m_systick_disable_interrupt(void)
{
    SYSTICK->CTRL &= ~SYSTICK_CTRL_TICKINT_Msk;
}

/**
 * @brief Set SysTick clock source
 * @param source Clock source (SYSTICK_CLKSOURCE_EXTERNAL or SYSTICK_CLKSOURCE_PROCESSOR)
 */
static inline void arm_v7m_systick_set_clock_source(uint32_t source)
{
    if (source == SYSTICK_CLKSOURCE_PROCESSOR) {
        SYSTICK->CTRL |= SYSTICK_CTRL_CLKSOURCE_Msk;
    } else {
        SYSTICK->CTRL &= ~SYSTICK_CTRL_CLKSOURCE_Msk;
    }
}

/**
 * @brief Get SysTick clock source
 * @return Current clock source
 */
static inline uint32_t arm_v7m_systick_get_clock_source(void)
{
    return (SYSTICK->CTRL & SYSTICK_CTRL_CLKSOURCE_Msk) ? SYSTICK_CLKSOURCE_PROCESSOR : SYSTICK_CLKSOURCE_EXTERNAL;
}

/**
 * @brief Check if counter has counted to zero (COUNTFLAG)
 * @return 1 if counted to zero, 0 otherwise
 * @note Reading this bit clears it to zero
 */
static inline uint32_t arm_v7m_systick_get_count_flag(void)
{
    return (SYSTICK->CTRL & SYSTICK_CTRL_COUNTFLAG_Msk) ? 1U : 0U;
}

/**
 * @brief Get current counter value
 * @return Current value of the counter (0-0xFFFFFF)
 */
static inline uint32_t arm_v7m_systick_get_count(void)
{
    return SYSTICK->VAL & SYSTICK_VAL_CURRENT_Msk;
}

/**
 * @brief Clear current counter value
 * @note Writing any value clears the counter and COUNTFLAG to zero
 */
static inline void arm_v7m_systick_clear_count(void)
{
    SYSTICK->VAL = 0U;
}

/**
 * @brief Get reload value
 * @return Current reload value
 */
static inline uint32_t arm_v7m_systick_get_reload(void)
{
    return SYSTICK->LOAD & SYSTICK_LOAD_RELOAD_Msk;
}

/**
 * @brief Set reload value
 * @param value Reload value (0-0xFFFFFF)
 * @note Value of 0 disables the counter on next wrap
 */
static inline void arm_v7m_systick_set_reload(uint32_t value)
{
    SYSTICK->LOAD = value & SYSTICK_LOAD_RELOAD_Msk;
}

/**
 * @brief Get calibration value (TENMS)
 * @return 10ms calibration value
 */
static inline uint32_t arm_v7m_systick_get_calib_tenms(void)
{
    return SYSTICK->CALIB & SYSTICK_CALIB_TENMS_Msk;
}

/**
 * @brief Check if external reference clock is available
 * @return 1 if no external reference clock, 0 if available
 */
static inline uint32_t arm_v7m_systick_is_noref(void)
{
    return (SYSTICK->CALIB & SYSTICK_CALIB_NOREF_Msk) ? 1U : 0U;
}

/**
 * @brief Check if calibration value is exact
 * @return 1 if calibration value is not exact (skewed), 0 if exact
 */
static inline uint32_t arm_v7m_systick_is_skew(void)
{
    return (SYSTICK->CALIB & SYSTICK_CALIB_SKEW_Msk) ? 1U : 0U;
}

/**
 * @brief Check if SysTick is enabled
 * @return 1 if enabled, 0 if disabled
 */
static inline uint32_t arm_v7m_systick_is_enabled(void)
{
    return (SYSTICK->CTRL & SYSTICK_CTRL_ENABLE_Msk) ? 1U : 0U;
}

/**
 * @brief Check if SysTick interrupt is enabled
 * @return 1 if enabled, 0 if disabled
 */
static inline uint32_t arm_v7m_systick_is_interrupt_enabled(void)
{
    return (SYSTICK->CTRL & SYSTICK_CTRL_TICKINT_Msk) ? 1U : 0U;
}

/**
 * @brief Check if calibration value is available (TENMS != 0)
 * @return 1 if calibration value is available, 0 if unknown
 * @note If TENMS is 0, the calibration value is not known
 */
static inline uint32_t arm_v7m_systick_is_calib_available(void)
{
    return (SYSTICK->CALIB & SYSTICK_CALIB_TENMS_Msk) ? 1U : 0U;
}

/**
 * @brief Get the number of ticks elapsed since last call
 * @return Number of ticks elapsed (0 if no wrap occurred)
 * @note This function uses COUNTFLAG to detect wrap and calculate elapsed ticks
 *
 * This function can be used for simple time measurement. Call it periodically
 * to check how many SysTick wraps have occurred.
 */
static inline uint32_t arm_v7m_systick_get_elapsed_ticks(void)
{
    uint32_t ticks = 0U;

    /* Check COUNTFLAG - each set bit indicates one wrap occurred */
    while ((SYSTICK->CTRL & SYSTICK_CTRL_COUNTFLAG_Msk) != 0U) {
        ticks++;
        /* COUNTFLAG is cleared by reading CTRL register */
    }

    return ticks;
}

/*============================================================================*
 * Non-Inline Functions - Complex Operations
 *============================================================================*/

/**
 * @brief Initialize and start SysTick with specified reload value
 * @param reload_value Reload value (0-0xFFFFFF)
 * @param use_processor_clock 1 to use processor clock, 0 for external clock
 * @param enable_interrupt 1 to enable SysTick interrupt, 0 to disable
 * @note This function disables SysTick first, configures it, then enables
 */
void arm_v7m_systick_init(uint32_t reload_value, uint32_t use_processor_clock, uint32_t enable_interrupt);

/**
 * @brief Calculate reload value for desired time period
 * @param ms Time period in milliseconds
 * @param clock_freq_hz Clock frequency in Hz
 * @return Reload value (capped at SYSTICK_MAX_RELOAD)
 * @note Returns 0 if calculation overflows
 */
uint32_t arm_v7m_systick_calc_reload_for_ms(uint32_t ms, uint32_t clock_freq_hz);

/**
 * @brief Delay for specified number of SysTick ticks (busy wait)
 * @param ticks Number of ticks to delay
 * @note This is a blocking delay function
 */
void arm_v7m_systick_delay_ticks(uint32_t ticks);

/**
 * @brief Initialize SysTick using calibration value for 10ms timing
 * @param enable_interrupt 1 to enable SysTick interrupt, 0 to disable
 * @return 0 on success, 1 if calibration value is not available
 * @note Uses the TENMS calibration value from SYST_CALIB register
 */
uint32_t arm_v7m_systick_init_calibrated(uint32_t enable_interrupt);

/**
 * @brief Calculate reload value using calibration value
 * @param hz Desired frequency in Hz (e.g., 100 for 100Hz = 10ms period)
 * @return Reload value, or 0 if calibration value is not available
 * @note This uses the TENMS calibration value to calculate the reload value
 *       for the desired frequency. The formula is:
 *       reload = (TENMS * 100) / (hz / 100) - 1, for hz <= 1000
 */
uint32_t arm_v7m_systick_calc_reload_from_calib(uint32_t hz);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_SYSTICK_H */
