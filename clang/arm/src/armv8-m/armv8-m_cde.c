/*
 * ARM Architecture - ARMv8-M CDE (Custom Datapath Extension)
 *
 * ============================================================================
 * File: armv8m_cde.c
 * Description: ARMv8-M CDE function implementations
 * 描述: ARMv8-M CDE 函数实现
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter A1.4.1: CDE - The Custom Datapath Extension
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv8m_cde.h"
#include "armv8m_fpu.h"

/*
 * ============================================================================
 * CDE Control Functions
 * CDE 控制函数
 * ============================================================================
 */

void cde_enable_coproc(uint32_t coproc)
{
    if (coproc < 4) {
        uint32_t cpacr = FPU_CPACR;
        uint32_t shift = 20 + (coproc * 2);
        cpacr &= ~(3UL << shift);
        cpacr |= (CPACR_CP_FULL_ACCESS << shift);
        FPU_CPACR = cpacr;
        
        __asm__ volatile("dsb");
        __asm__ volatile("isb");
    }
}

void cde_disable_coproc(uint32_t coproc)
{
    if (coproc < 4) {
        uint32_t cpacr = FPU_CPACR;
        uint32_t shift = 20 + (coproc * 2);
        cpacr &= ~(3UL << shift);
        FPU_CPACR = cpacr;
        
        __asm__ volatile("dsb");
        __asm__ volatile("isb");
    }
}

bool cde_is_present(void)
{
    return false;
}

uint32_t cde_get_num_coprocessors(void)
{
    return 0;
}
