/*
 * ARM Architecture - ARMv7-M SysTick Timer
 *
 * ============================================================================
 * File: armv7-m_systick.c
 * Description: ARMv7-M SysTick timer function implementations
 * 描述: ARMv7-M SysTick 定时器函数实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter A2: Application Level Programmers' Model
 *     * A2.4 Exceptions, faults and interrupts (page A2-33)
 *       - A2.4.1 System-related events
 *       - SysTick is a system timer for OS scheduling
 *       - Associated interrupt for periodic tasks
 *       - Reference: Chapter A2.3.4 Privileged execution (page A2-32)
 *         * SysTick handler runs in Handler mode with privileged access
 *   - Chapter A3: Arm Architecture Memory Model
 *     * A3.1 Address space (page A3-64)
 *       - Memory-mapped SysTick registers in SCS at 0xE000E010-0xE000E01F
 *   - Chapter B3.3 - The system timer, SysTick
 *   - Table B3-7 SysTick register summary (page B3-621)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_systick.h"

/**
 * @brief Configure and start SysTick timer
 * @param ticks Number of ticks between interrupts (1-0xFFFFFF)
 * @param use_processor_clock 1 = use processor clock, 0 = use external clock
 * @param enable_interrupt 1 = enable interrupt, 0 = disable interrupt
 * @return 0 on success, 1 if ticks is invalid
 *
 * Reference: Chapter A2.4 Exceptions, faults and interrupts (page A2-33)
 *   - A2.4.1 System-related events
 *   - SysTick is a system timer for OS scheduling
 *   - Reference: Chapter A2.3.4 Privileged execution (page A2-32)
 *     * SysTick handler runs in Handler mode with privileged access
 * Reference: Chapter A3.1 Address space (page A3-64)
 *   - Memory-mapped SysTick registers in SCS
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-621 (SYST_CSR)
 */
uint32_t systick_config(uint32_t ticks, uint8_t use_processor_clock, uint8_t enable_interrupt)
{
    if (ticks < 1 || ticks > 0xFFFFFFUL) {
        return 1;
    }

    uint32_t csr = 0;

    if (use_processor_clock) {
        csr |= SYST_CSR_CLKSOURCE_Msk;
    }

    if (enable_interrupt) {
        csr |= SYST_CSR_TICKINT_Msk;
    }

    SYST_RVR = (ticks - 1) & SYST_RVR_RELOAD_Msk;
    SYST_CVR = 0;
    SYST_CSR = csr;

    return 0;
}

/**
 * @brief Enable SysTick counter
 *
 * Reference: Chapter A2.4 Exceptions, faults and interrupts (page A2-33)
 *   - A2.4.1 System-related events
 *   - Enables the SysTick counter
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-621 (SYST_CSR.ENABLE)
 */
void systick_enable(void)
{
    SYST_CSR |= SYST_CSR_ENABLE_Msk;
}

/**
 * @brief Disable SysTick counter
 *
 * Reference: Chapter A2.4 Exceptions, faults and interrupts (page A2-33)
 *   - A2.4.1 System-related events
 *   - Disables the SysTick counter
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-621 (SYST_CSR.ENABLE)
 */
void systick_disable(void)
{
    SYST_CSR &= ~SYST_CSR_ENABLE_Msk;
}

/**
 * @brief Get SysTick current value
 * @return Current counter value
 *
 * Reference: Chapter A3.1 Address space (page A3-64)
 *   - SYST_CVR register at 0xE000E018
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-622 (SYST_CVR)
 */
uint32_t systick_get_value(void)
{
    return SYST_CVR;
}

/**
 * @brief Set SysTick reload value
 * @param value Reload value (1-0xFFFFFF)
 *
 * Reference: Chapter A2.4 Exceptions, faults and interrupts (page A2-33)
 *   - A2.4.1 System-related events
 *   - Sets the reload value for periodic interrupts
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-622 (SYST_RVR)
 */
void systick_set_reload(uint32_t value)
{
    SYST_RVR = (value & SYST_RVR_RELOAD_Msk);
}

/**
 * @brief Reset SysTick counter
 *
 * Reference: Chapter A3.1 Address space (page A3-64)
 *   - Writing any value to SYST_CVR clears it to 0
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-622 (SYST_CVR)
 */
void systick_reset(void)
{
    SYST_CVR = 0U;
}

/**
 * @brief Get SysTick count flag
 * @return 1 if counter reached zero since last read, 0 otherwise
 *
 * Reference: Chapter A2.4 Exceptions, faults and interrupts (page A2-33)
 *   - A2.4.1 System-related events
 *   - COUNTFLAG indicates timer has counted to zero
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-621 (SYST_CSR.COUNTFLAG)
 */
uint32_t systick_get_count_flag(void)
{
    return (SYST_CSR & SYST_CSR_COUNTFLAG_Msk) ? 1U : 0U;
}

/**
 * @brief Get SysTick calibration value
 * @return Calibration value
 *
 * Reference: Chapter A3.1 Address space (page A3-64)
 *   - SYST_CALIB register at 0xE000E01C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-623 (SYST_CALIB)
 */
uint32_t systick_get_calib(void)
{
    return SYST_CALIB;
}

/**
 * @brief Check if external reference clock is available
 * @return 1 if available, 0 if not
 *
 * Reference: Chapter A2.4 Exceptions, faults and interrupts (page A2-33)
 *   - A2.4.1 System-related events
 *   - NOREF bit indicates if external reference clock is available
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-623 (SYST_CALIB.NOREF)
 */
uint32_t systick_has_external_clock(void)
{
    return (SYST_CALIB & SYST_CALIB_NOREF_Msk) ? 0U : 1U;
}
