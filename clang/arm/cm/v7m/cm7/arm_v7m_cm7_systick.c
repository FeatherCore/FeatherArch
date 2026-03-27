/*
 * arm_v7m_cm7_systick.c
 * Cortex-M7 System Timer (SysTick) Implementation
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.3
 *            - The system timer, SysTick on page B3-620
 *            - Section B3.3.1: SysTick operation on page B3-620
 *            - Section B3.3.2: System timer register support in the SCS on page B3-621
 *            - Section B3.3.3: SysTick Control and Status Register, SYST_CSR on page B3-621
 *            - Section B3.3.4: SysTick Reload Value Register, SYST_RVR on page B3-622
 *            - Section B3.3.5: SysTick Current Value Register, SYST_CVR on page B3-622
 *            - Section B3.3.6: SysTick Calibration value Register, SYST_CALIB on page B3-623
 *            - Table B3-7: SysTick register summary on page B3-621
 *            Cortex-M7 Devices Generic User Guide, Chapter 4.4
 *            - System timer, SysTick on page 4-32
 *            - Section 4.4.1: SysTick Control and Status Register on page 4-33
 *            - Section 4.4.2: SysTick Reload Value Register on page 4-34
 *            - Section 4.4.3: SysTick Current Value Register on page 4-34
 *            - Section 4.4.4: SysTick Calibration Value Register on page 4-35
 *            - Table 4-36: SysTick register summary on page 4-32
 *            Cortex-M7 Technical Reference Manual
 *            - Section 2.4.1: System timer on page 2-12
 *            - Section 4.1.2: System Timer (SysTick) on page 4-5
 *
 * This file wraps the generic Armv7-M SysTick implementation for Cortex-M7.
 * All functions delegate to the generic v7m implementation.
 *
 * @note This file wraps the generic Armv7-M SysTick implementation.
 */

#include "arm_v7m_cm7_systick.h"

/*============================================================================*
 * SysTick Initialization
 *============================================================================*/

/**
 * @brief Initialize and start SysTick with specified reload value
 *
 * According to ARMv7-M Architecture Reference Manual, Section B3.3:
 * - SysTick is a 24-bit decrementing counter
 * - When enabled, counts down from reload value to 0
 * - On reaching 0, reloads and continues counting
 * - Can generate SysTick exception when counting to 0
 *
 * According to Cortex-M7 Devices Generic User Guide, Section 4.4:
 * - The counter is enabled by setting ENABLE bit in CTRL register
 * - TICKINT bit enables SysTick exception generation
 * - CLKSOURCE selects between external reference clock and processor clock
 *
 * @param reload_value Reload value (0-0xFFFFFF)
 * @param use_processor_clock 1 to use processor clock, 0 for external clock
 * @param enable_interrupt 1 to enable SysTick interrupt, 0 to disable
 */
void arm_v7m_cm7_systick_init(uint32_t reload_value, uint32_t use_processor_clock, uint32_t enable_interrupt)
{
    arm_v7m_systick_init(reload_value, use_processor_clock, enable_interrupt);
}

/*============================================================================*
 * SysTick Calculation Functions
 *============================================================================*/

/**
 * @brief Calculate reload value for desired time period
 *
 * According to ARMv7-M Architecture Reference Manual, Section B3.3.1:
 * - The timer counts down from reload value to 0
 * - For N ticks, reload value should be N-1
 * - Maximum reload value is 0xFFFFFF (24-bit)
 *
 * @param ms Time period in milliseconds
 * @param clock_freq_hz Clock frequency in Hz
 * @return Reload value (capped at ARM_V7M_CM7_SYSTICK_MAX_RELOAD)
 */
uint32_t arm_v7m_cm7_systick_calc_reload_for_ms(uint32_t ms, uint32_t clock_freq_hz)
{
    return arm_v7m_systick_calc_reload_for_ms(ms, clock_freq_hz);
}

/*============================================================================*
 * SysTick Delay Functions
 *============================================================================*/

/**
 * @brief Delay for specified number of SysTick ticks (busy wait)
 *
 * According to ARMv7-M Architecture Reference Manual, Section B3.3.3:
 * - COUNTFLAG is set when the counter reaches zero
 * - Reading CTRL register clears COUNTFLAG
 *
 * @param ticks Number of ticks to delay
 */
void arm_v7m_cm7_systick_delay_ticks(uint32_t ticks)
{
    arm_v7m_systick_delay_ticks(ticks);
}

/*============================================================================*
 * SysTick Calibration Functions
 *============================================================================*/

/**
 * @brief Initialize SysTick using calibration value for 10ms timing
 *
 * According to ARMv7-M Architecture Reference Manual, Section B3.3.6:
 * - TENMS field optionally holds reload value for 10ms timing
 * - If TENMS is 0, calibration value is not known
 * - NOREF bit indicates if external reference clock is implemented
 * - SKEW bit indicates if 10ms calibration value is exact
 *
 * According to Cortex-M7 Devices Generic User Guide, Section 4.4.4:
 * - The calibration value is device-specific
 * - Can be used to achieve 10ms timing without knowing system clock
 *
 * @param enable_interrupt 1 to enable SysTick interrupt, 0 to disable
 * @return 0 on success, 1 if calibration value is not available
 */
uint32_t arm_v7m_cm7_systick_init_calibrated(uint32_t enable_interrupt)
{
    return arm_v7m_systick_init_calibrated(enable_interrupt);
}

/**
 * @brief Calculate reload value using calibration value
 *
 * Uses the TENMS calibration value to calculate reload value for desired frequency.
 * Formula: reload = (TENMS * 100 / hz) - 1
 *
 * @param hz Desired frequency in Hz (e.g., 100 for 100Hz = 10ms period)
 * @return Reload value, or 0 if calibration value is not available
 */
uint32_t arm_v7m_cm7_systick_calc_reload_from_calib(uint32_t hz)
{
    return arm_v7m_systick_calc_reload_from_calib(hz);
}
