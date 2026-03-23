/*
 * ARM Architecture - ARMv7-M SysTick Timer
 *
 * ============================================================================
 * File: armv7-m_systick.c
 * Description: ARMv7-M SysTick timer function implementations
 * 描述: ARMv7-M SysTick 定时器函数实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual
 *   - Chapter B8: The System Timer, SysTick
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_systick.h"

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
