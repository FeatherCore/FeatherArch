/*
 * ARM Architecture - ARMv8-M MVE (M-Profile Vector Extension)
 *
 * ============================================================================
 * File: armv8m_mve.c
 * Description: ARMv8-M MVE (Helium) function implementations
 * 描述: ARMv8-M MVE (Helium) 函数实现
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B5: Vector Extension
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv8m_mve.h"
#include "armv8m_fpu.h"

/*
 * ============================================================================
 * MVE Detection and Control
 * MVE 检测和控制
 * ============================================================================
 */

bool mve_is_present(void)
{
    uint32_t mvfr0 = FPU_MVFR0;
    return ((mvfr0 >> 24) & 0xF) != 0;
}

bool mve_fp_is_present(void)
{
    uint32_t mvfr1 = FPU_MVFR1;
    return ((mvfr1 >> 28) & 0xF) != 0;
}

void mve_enable(void)
{
    uint32_t cpacr = FPU_CPACR;
    cpacr &= ~(FPU_CPACR_CP11_Msk | FPU_CPACR_CP10_Msk);
    cpacr |= (CPACR_CP_FULL_ACCESS << FPU_CPACR_CP11_Pos) | 
             (CPACR_CP_FULL_ACCESS << FPU_CPACR_CP10_Pos);
    FPU_CPACR = cpacr;
    
    __asm__ volatile("dsb");
    __asm__ volatile("isb");
}

void mve_disable(void)
{
    uint32_t cpacr = FPU_CPACR;
    cpacr &= ~(FPU_CPACR_CP11_Msk | FPU_CPACR_CP10_Msk);
    FPU_CPACR = cpacr;
    
    __asm__ volatile("dsb");
    __asm__ volatile("isb");
}

uint32_t mve_get_vector_length(void)
{
    return 16;
}

void mve_set_vpr(uint32_t vpr)
{
    __asm__ volatile("MSR VPR, %0" : : "r" (vpr));
}

uint32_t mve_get_vpr(void)
{
    uint32_t vpr;
    __asm__ volatile("MRS %0, VPR" : "=r" (vpr));
    return vpr;
}
