/*
 * ARM Architecture - ARMv8-M TPIU (Trace Port Interface Unit)
 *
 * ============================================================================
 * File: armv8-m_tpiu.c
 * Description: ARMv8-M TPIU functions
 * 描述: ARMv8-M 跟踪端口接口单元函数
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter D1.1.31 Trace Port Interface Unit
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv8-m/armv8-m_tpiu.h"

void tpiu_enable(void)
{
    TPIU_LAR = 0xC5ACCE55UL;
}

void tpiu_disable(void)
{
    TPIU_LAR = 0x00000000UL;
}

void tpiu_set_protocol(uint32_t protocol)
{
    uint32_t value = TPIU_SPPR;
    value &= ~TPIU_SPPR_PROTOCOL_Msk;
    value |= (protocol << TPIU_SPPR_PROTOCOL_Pos) & TPIU_SPPR_PROTOCOL_Msk;
    TPIU_SPPR = value;
}

void tpiu_set_prescaler(uint32_t prescaler)
{
    TPIU_ACPR = prescaler;
}

void tpiu_flush(void)
{
    uint32_t value = TPIU_FFCR;
    value |= TPIU_FFCR_FOnMan_Msk;
    TPIU_FFCR = value;
    
    while ((TPIU_FFSR & TPIU_FFSR_FtInProgress_Msk) != 0)
    {
        __asm__ volatile ("nop");
    }
}
