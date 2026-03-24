/*
 * ARM Architecture - Cortex-M4 SysTick Implementation
 *
 * ============================================================================
 * File: cm4_systick.c
 * Description: Cortex-M4 SysTick function implementations
 * 描述: Cortex-M4 SysTick 函数实现
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.4 System timer, SysTick (page 4-32)
 *   - Table 4-32 System timer registers summary (page 4-33)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include "armv7-m/cm4/cm4_systick.h"

/**
 * @brief Initialize SysTick timer
 * @param reload_value Reload value (0x00000001-0x00FFFFFF)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.2 (page 4-34)
 */
void cm4_systick_init(uint32_t reload_value)
{
    SYST_RVR = reload_value & SYST_RVR_RELOAD_Msk;
    SYST_CVR = 0;
    SYST_CSR = SYST_CSR_ENABLE_Msk | SYST_CSR_TICKINT_Msk | SYST_CSR_CLKSOURCE_Msk;
}

/**
 * @brief Enable SysTick counter
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.1 (page 4-33)
 */
void cm4_systick_enable(void)
{
    SYST_CSR |= SYST_CSR_ENABLE_Msk;
}

/**
 * @brief Disable SysTick counter
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.1 (page 4-33)
 */
void cm4_systick_disable(void)
{
    SYST_CSR &= ~SYST_CSR_ENABLE_Msk;
}

/**
 * @brief Set reload value
 * @param value Reload value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.2 (page 4-34)
 */
void cm4_systick_set_reload(uint32_t value)
{
    SYST_RVR = value & SYST_RVR_RELOAD_Msk;
}

/**
 * @brief Get reload value
 * @return Current reload value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.2 (page 4-34)
 */
uint32_t cm4_systick_get_reload(void)
{
    return SYST_RVR & SYST_RVR_RELOAD_Msk;
}

/**
 * @brief Get current value
 * @return Current counter value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.3 (page 4-35)
 */
uint32_t cm4_systick_get_value(void)
{
    return SYST_CVR & SYST_CVR_CURRENT_Msk;
}

/**
 * @brief Clear current value (reset to 0)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.3 (page 4-35)
 */
void cm4_systick_clear(void)
{
    SYST_CVR = 0;
}

/**
 * @brief Enable SysTick interrupt
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.1 (page 4-33)
 */
void cm4_systick_enable_interrupt(void)
{
    SYST_CSR |= SYST_CSR_TICKINT_Msk;
}

/**
 * @brief Disable SysTick interrupt
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.1 (page 4-33)
 */
void cm4_systick_disable_interrupt(void)
{
    SYST_CSR &= ~SYST_CSR_TICKINT_Msk;
}

/**
 * @brief Check if counter has counted to 0
 * @return 1 if counted to 0, 0 otherwise
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.1 (page 4-33)
 */
int cm4_systick_get_countflag(void)
{
    return (SYST_CSR & SYST_CSR_COUNTFLAG_Msk) ? 1 : 0;
}

/**
 * @brief Set clock source
 * @param use_processor_clock 1 = processor clock, 0 = external clock
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.1 (page 4-33)
 */
void cm4_systick_set_clock_source(int use_processor_clock)
{
    if (use_processor_clock) {
        SYST_CSR |= SYST_CSR_CLKSOURCE_Msk;
    } else {
        SYST_CSR &= ~SYST_CSR_CLKSOURCE_Msk;
    }
}

/**
 * @brief Get calibration value
 * @return Calibration value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.4 (page 4-35)
 */
uint32_t cm4_systick_get_calibration(void)
{
    return SYST_CALIB & SYST_CALIB_TENMS_Msk;
}

/**
 * @brief Check if reference clock is provided
 * @return 1 if no reference clock, 0 if reference clock provided
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.4 (page 4-35)
 */
int cm4_systick_is_noref(void)
{
    return (SYST_CALIB & SYST_CALIB_NOREF_Msk) ? 1 : 0;
}

/**
 * @brief Check if TENMS value is exact
 * @return 1 if inexact, 0 if exact
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.4 (page 4-35)
 */
int cm4_systick_is_skew(void)
{
    return (SYST_CALIB & SYST_CALIB_SKEW_Msk) ? 1 : 0;
}
