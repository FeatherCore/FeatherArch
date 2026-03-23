/*
 * ARM Architecture - ARMv7-M TPIU (Trace Port Interface Unit)
 *
 * ============================================================================
 * File: armv7-m_tpiu.c
 * Description: ARMv7-M TPIU function implementations
 * 描述: ARMv7-M TPIU 函数实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual
 *   - Chapter B12: Trace Port Interface Unit
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_tpiu.h"

/*
 * ============================================================================
 * TPIU Functions
 * TPIU 函数
 * ============================================================================
 */

void tpiu_enable(void)
{
    /* TPIU doesn't have a simple enable bit, set default protocol */
    tpiu_set_protocol(TPIU_SPPR_PROTOCOL_NRZ);
}

void tpiu_disable(void)
{
    /* TPIU doesn't have a simple disable bit */
}

void tpiu_set_protocol(uint32_t protocol)
{
    if (protocol <= 2) {
        TPIU_SPPR = (protocol & TPIU_SPPR_PROTOCOL_Msk);
    }
}

void tpiu_set_prescaler(uint32_t prescaler)
{
    TPIU_ACPR = prescaler;
}

void tpiu_flush(void)
{
    /* Trigger a flush by setting the formatter enable then clearing */
    TPIU_FFCR |= TPIU_FFCR_EnFC_Msk;
    __asm__ volatile("dsb");
    __asm__ volatile("isb");
    TPIU_FFCR &= ~TPIU_FFCR_EnFC_Msk;
}
