/*
 * ARM Architecture - ARMv7-M SysTick Timer
 *
 * ============================================================================
 * File: armv7-m_systick.c
 * Description: ARMv7-M SysTick timer function implementations
 * 描述: ARMv7-M SysTick 定时器函数实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
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
