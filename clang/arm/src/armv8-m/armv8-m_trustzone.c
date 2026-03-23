/*
 * ARM Architecture - ARMv8-M TrustZone Security Extension
 *
 * ============================================================================
 * File: armv8m_trustzone.c
 * Description: ARMv8-M TrustZone security extension function implementations
 * 描述: ARMv8-M TrustZone 安全扩展函数实现
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B10: The Armv8-M Protected Memory System Architecture (SAU)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv8-m/armv8-m_trustzone.h"

/*
 * ============================================================================
 * SAU (Security Attribution Unit) Functions
 * SAU 函数
 * ============================================================================
 */

void sau_enable(void)
{
    SAU_CTRL |= SAU_CTRL_ENABLE_Msk;
}

void sau_disable(void)
{
    SAU_CTRL &= ~SAU_CTRL_ENABLE_Msk;
}

void sau_set_all_nonsecure(bool all_ns)
{
    if (all_ns) {
        SAU_CTRL |= SAU_CTRL_ALLNS_Msk;
    } else {
        SAU_CTRL &= ~SAU_CTRL_ALLNS_Msk;
    }
}

uint32_t sau_get_region_count(void)
{
    return (SAU_TYPE & SAU_TYPE_SREGION_Msk) >> SAU_TYPE_SREGION_Pos;
}

void sau_configure_region(uint32_t rnr, uint32_t base, uint32_t limit, bool nsc, bool enable)
{
    SAU_RNR = rnr;
    SAU_RBAR = base & SAU_RBAR_BADDR_Msk;
    
    uint32_t rlar = limit & SAU_RLAR_LADDR_Msk;
    if (nsc) {
        rlar |= SAU_RLAR_NSC_Msk;
    }
    if (enable) {
        rlar |= SAU_RLAR_ENABLE_Msk;
    }
    SAU_RLAR = rlar;
}

void sau_clear_region(uint32_t rnr)
{
    SAU_RNR = rnr;
    SAU_RLAR = 0;
}

uint32_t sau_get_fault_status(void)
{
    return SFSR;
}

void sau_clear_fault_status(void)
{
    SFSR = 0xFFFFFFFFUL;
}

uint32_t sau_get_fault_address(void)
{
    return SFAR;
}
