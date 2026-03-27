/*
 * arm_v7m_cm7_systick.h
 * Cortex-M7 System Timer (SysTick) Definitions
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
 * @note This file reuses Armv7-M generic SysTick definitions.
 */

#ifndef ARM_V7M_CM7_SYSTICK_H
#define ARM_V7M_CM7_SYSTICK_H

#include <stdint.h>
#include "../arm_v7m_systick.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Compiler Abstraction - Inline Definition
 *============================================================================*/

#if defined(__clang__)
    #define ARM_V7M_CM7_SYSTICK_INLINE static inline __attribute__((always_inline))
#else
    #error "This library requires Clang/LLVM compiler."
#endif

/*============================================================================*
 * Type Aliases
 *============================================================================*/

typedef arm_v7m_systick_regs_t      arm_v7m_cm7_systick_regs_t;

/*============================================================================*
 * Constant Aliases - Control Register Bits
 *============================================================================*/

/* ENABLE: Counter enable */
#define ARM_V7M_CM7_SYSTICK_CTRL_ENABLE_Pos        ARM_V7M_SYSTICK_CTRL_ENABLE_Pos
#define ARM_V7M_CM7_SYSTICK_CTRL_ENABLE_Msk        ARM_V7M_SYSTICK_CTRL_ENABLE_Msk

/* TICKINT: SysTick exception request enable */
#define ARM_V7M_CM7_SYSTICK_CTRL_TICKINT_Pos       ARM_V7M_SYSTICK_CTRL_TICKINT_Pos
#define ARM_V7M_CM7_SYSTICK_CTRL_TICKINT_Msk       ARM_V7M_SYSTICK_CTRL_TICKINT_Msk

/* CLKSOURCE: Clock source selection */
#define ARM_V7M_CM7_SYSTICK_CTRL_CLKSOURCE_Pos     ARM_V7M_SYSTICK_CTRL_CLKSOURCE_Pos
#define ARM_V7M_CM7_SYSTICK_CTRL_CLKSOURCE_Msk     ARM_V7M_SYSTICK_CTRL_CLKSOURCE_Msk

/* COUNTFLAG: Returns 1 if timer counted to 0 since last time this was read */
#define ARM_V7M_CM7_SYSTICK_CTRL_COUNTFLAG_Pos     ARM_V7M_SYSTICK_CTRL_COUNTFLAG_Pos
#define ARM_V7M_CM7_SYSTICK_CTRL_COUNTFLAG_Msk     ARM_V7M_SYSTICK_CTRL_COUNTFLAG_Msk

/*============================================================================*
 * Constant Aliases - Load Register Bits
 *============================================================================*/

#define ARM_V7M_CM7_SYSTICK_LOAD_RELOAD_Pos        ARM_V7M_SYSTICK_LOAD_RELOAD_Pos
#define ARM_V7M_CM7_SYSTICK_LOAD_RELOAD_Msk        ARM_V7M_SYSTICK_LOAD_RELOAD_Msk

/* Maximum reload value (24-bit) */
#define ARM_V7M_CM7_SYSTICK_MAX_RELOAD             ARM_V7M_SYSTICK_MAX_RELOAD

/*============================================================================*
 * Constant Aliases - Value Register Bits
 *============================================================================*/

#define ARM_V7M_CM7_SYSTICK_VAL_CURRENT_Pos        ARM_V7M_SYSTICK_VAL_CURRENT_Pos
#define ARM_V7M_CM7_SYSTICK_VAL_CURRENT_Msk        ARM_V7M_SYSTICK_VAL_CURRENT_Msk

/*============================================================================*
 * Constant Aliases - Calibration Register Bits
 *============================================================================*/

/* NOREF: Indicates whether the IMPLEMENTATION DEFINED reference clock is implemented */
#define ARM_V7M_CM7_SYSTICK_CALIB_NOREF_Pos        ARM_V7M_SYSTICK_CALIB_NOREF_Pos
#define ARM_V7M_CM7_SYSTICK_CALIB_NOREF_Msk        ARM_V7M_SYSTICK_CALIB_NOREF_Msk

/* SKEW: Indicates whether the 10ms calibration value is exact */
#define ARM_V7M_CM7_SYSTICK_CALIB_SKEW_Pos         ARM_V7M_SYSTICK_CALIB_SKEW_Pos
#define ARM_V7M_CM7_SYSTICK_CALIB_SKEW_Msk         ARM_V7M_SYSTICK_CALIB_SKEW_Msk

/* TENMS: 10ms calibration value */
#define ARM_V7M_CM7_SYSTICK_CALIB_TENMS_Pos        ARM_V7M_SYSTICK_CALIB_TENMS_Pos
#define ARM_V7M_CM7_SYSTICK_CALIB_TENMS_Msk        ARM_V7M_SYSTICK_CALIB_TENMS_Msk

/*============================================================================*
 * Constant Aliases - Clock Source Values
 *============================================================================*/

#define ARM_V7M_CM7_SYSTICK_CLKSOURCE_EXTERNAL     ARM_V7M_SYSTICK_CLKSOURCE_EXTERNAL
#define ARM_V7M_CM7_SYSTICK_CLKSOURCE_PROCESSOR    ARM_V7M_SYSTICK_CLKSOURCE_PROCESSOR

/*============================================================================*
 * Inline Functions - SysTick Basic Operations (Aliased from generic)
 *============================================================================*/

/**
 * @brief Enable SysTick counter
 */
ARM_V7M_CM7_SYSTICK_INLINE void arm_v7m_cm7_systick_enable(void)
{
    arm_v7m_systick_enable();
}

/**
 * @brief Disable SysTick counter
 */
ARM_V7M_CM7_SYSTICK_INLINE void arm_v7m_cm7_systick_disable(void)
{
    arm_v7m_systick_disable();
}

/**
 * @brief Enable SysTick exception request (TICKINT)
 */
ARM_V7M_CM7_SYSTICK_INLINE void arm_v7m_cm7_systick_enable_interrupt(void)
{
    arm_v7m_systick_enable_interrupt();
}

/**
 * @brief Disable SysTick exception request (TICKINT)
 */
ARM_V7M_CM7_SYSTICK_INLINE void arm_v7m_cm7_systick_disable_interrupt(void)
{
    arm_v7m_systick_disable_interrupt();
}

/**
 * @brief Set SysTick clock source
 * @param source Clock source (ARM_V7M_CM7_SYSTICK_CLKSOURCE_EXTERNAL or ARM_V7M_CM7_SYSTICK_CLKSOURCE_PROCESSOR)
 */
ARM_V7M_CM7_SYSTICK_INLINE void arm_v7m_cm7_systick_set_clock_source(uint32_t source)
{
    arm_v7m_systick_set_clock_source(source);
}

/**
 * @brief Get SysTick clock source
 * @return Current clock source
 */
ARM_V7M_CM7_SYSTICK_INLINE uint32_t arm_v7m_cm7_systick_get_clock_source(void)
{
    return arm_v7m_systick_get_clock_source();
}

/**
 * @brief Check if counter has counted to zero (COUNTFLAG)
 * @return 1 if counted to zero, 0 otherwise
 * @note Reading this bit clears it to zero
 */
ARM_V7M_CM7_SYSTICK_INLINE uint32_t arm_v7m_cm7_systick_get_count_flag(void)
{
    return arm_v7m_systick_get_count_flag();
}

/**
 * @brief Get current counter value
 * @return Current value of the counter (0-0xFFFFFF)
 */
ARM_V7M_CM7_SYSTICK_INLINE uint32_t arm_v7m_cm7_systick_get_count(void)
{
    return arm_v7m_systick_get_count();
}

/**
 * @brief Clear current counter value
 * @note Writing any value clears the counter and COUNTFLAG to zero
 */
ARM_V7M_CM7_SYSTICK_INLINE void arm_v7m_cm7_systick_clear_count(void)
{
    arm_v7m_systick_clear_count();
}

/**
 * @brief Get reload value
 * @return Current reload value
 */
ARM_V7M_CM7_SYSTICK_INLINE uint32_t arm_v7m_cm7_systick_get_reload(void)
{
    return arm_v7m_systick_get_reload();
}

/**
 * @brief Set reload value
 * @param value Reload value (0-0xFFFFFF)
 * @note Value of 0 disables the counter on next wrap
 */
ARM_V7M_CM7_SYSTICK_INLINE void arm_v7m_cm7_systick_set_reload(uint32_t value)
{
    arm_v7m_systick_set_reload(value);
}

/**
 * @brief Get calibration value (TENMS)
 * @return 10ms calibration value
 */
ARM_V7M_CM7_SYSTICK_INLINE uint32_t arm_v7m_cm7_systick_get_calib_tenms(void)
{
    return arm_v7m_systick_get_calib_tenms();
}

/**
 * @brief Check if external reference clock is available
 * @return 1 if no external reference clock, 0 if available
 */
ARM_V7M_CM7_SYSTICK_INLINE uint32_t arm_v7m_cm7_systick_is_noref(void)
{
    return arm_v7m_systick_is_noref();
}

/**
 * @brief Check if calibration value is exact
 * @return 1 if calibration value is not exact (skewed), 0 if exact
 */
ARM_V7M_CM7_SYSTICK_INLINE uint32_t arm_v7m_cm7_systick_is_skew(void)
{
    return arm_v7m_systick_is_skew();
}

/**
 * @brief Check if SysTick is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_CM7_SYSTICK_INLINE uint32_t arm_v7m_cm7_systick_is_enabled(void)
{
    return arm_v7m_systick_is_enabled();
}

/**
 * @brief Check if SysTick interrupt is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_CM7_SYSTICK_INLINE uint32_t arm_v7m_cm7_systick_is_interrupt_enabled(void)
{
    return arm_v7m_systick_is_interrupt_enabled();
}

/**
 * @brief Check if calibration value is available (TENMS != 0)
 * @return 1 if calibration value is available, 0 if unknown
 * @note If TENMS is 0, the calibration value is not known
 */
ARM_V7M_CM7_SYSTICK_INLINE uint32_t arm_v7m_cm7_systick_is_calib_available(void)
{
    return arm_v7m_systick_is_calib_available();
}

/**
 * @brief Get the number of ticks elapsed since last call
 * @return Number of ticks elapsed (0 if no wrap occurred)
 * @note This function uses COUNTFLAG to detect wrap and calculate elapsed ticks
 */
ARM_V7M_CM7_SYSTICK_INLINE uint32_t arm_v7m_cm7_systick_get_elapsed_ticks(void)
{
    return arm_v7m_systick_get_elapsed_ticks();
}

/*============================================================================*
 * Non-Inline Functions - Complex SysTick Operations
 *============================================================================*/

/**
 * @brief Initialize and start SysTick with specified reload value
 * @param reload_value Reload value (0-0xFFFFFF)
 * @param use_processor_clock 1 to use processor clock, 0 for external clock
 * @param enable_interrupt 1 to enable SysTick interrupt, 0 to disable
 * @note This function disables SysTick first, configures it, then enables
 */
void arm_v7m_cm7_systick_init(uint32_t reload_value, uint32_t use_processor_clock, uint32_t enable_interrupt);

/**
 * @brief Calculate reload value for desired time period
 * @param ms Time period in milliseconds
 * @param clock_freq_hz Clock frequency in Hz
 * @return Reload value (capped at ARM_V7M_CM7_SYSTICK_MAX_RELOAD)
 * @note Returns 0 if calculation overflows
 */
uint32_t arm_v7m_cm7_systick_calc_reload_for_ms(uint32_t ms, uint32_t clock_freq_hz);

/**
 * @brief Delay for specified number of SysTick ticks (busy wait)
 * @param ticks Number of ticks to delay
 * @note This is a blocking delay function
 */
void arm_v7m_cm7_systick_delay_ticks(uint32_t ticks);

/**
 * @brief Initialize SysTick using calibration value for 10ms timing
 * @param enable_interrupt 1 to enable SysTick interrupt, 0 to disable
 * @return 0 on success, 1 if calibration value is not available
 * @note Uses the TENMS calibration value from SYST_CALIB register
 */
uint32_t arm_v7m_cm7_systick_init_calibrated(uint32_t enable_interrupt);

/**
 * @brief Calculate reload value using calibration value
 * @param hz Desired frequency in Hz (e.g., 100 for 100Hz = 10ms period)
 * @return Reload value, or 0 if calibration value is not available
 * @note This uses the TENMS calibration value to calculate the reload value
 */
uint32_t arm_v7m_cm7_systick_calc_reload_from_calib(uint32_t hz);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM7_SYSTICK_H */
