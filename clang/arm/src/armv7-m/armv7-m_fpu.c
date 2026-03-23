/*
 * ARM Architecture - ARMv7-M FPU (Floating-Point Unit)
 *
 * ============================================================================
 * File: armv7-m_fpu.c
 * Description: ARMv7-M FPU function implementations
 * 描述: ARMv7-M FPU 函数实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B4: Floating-point Support
 *   - Table B3-5 Summary of additional SCB registers for the FP extension (page B3-597)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_fpu.h"
#include "armv7-m/armv7-m_nvic.h"

/*
 * ============================================================================
 * FPU Enable/Disable
 * FPU 启用/禁用
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-614 (CPACR register)
 * ============================================================================
 */

void fpu_enable(void)
{
    uint32_t cpacr = SCB_CPACR;
    
    cpacr &= ~(CPACR_CP11_Msk | CPACR_CP10_Msk);
    cpacr |= (CPACR_CP_FULL_ACCESS << CPACR_CP11_Pos) | 
             (CPACR_CP_FULL_ACCESS << CPACR_CP10_Pos);
    
    SCB_CPACR = cpacr;
    
    __asm__ volatile("dsb" ::: "memory");
    __asm__ volatile("isb" ::: "memory");
}

void fpu_disable(void)
{
    uint32_t cpacr = SCB_CPACR;
    
    cpacr &= ~(CPACR_CP11_Msk | CPACR_CP10_Msk);
    
    SCB_CPACR = cpacr;
    
    __asm__ volatile("dsb" ::: "memory");
    __asm__ volatile("isb" ::: "memory");
}

bool fpu_is_enabled(void)
{
    uint32_t cpacr = SCB_CPACR;
    uint32_t cp10 = (cpacr & CPACR_CP10_Msk) >> CPACR_CP10_Pos;
    uint32_t cp11 = (cpacr & CPACR_CP11_Msk) >> CPACR_CP11_Pos;
    
    return (cp10 == CPACR_CP_FULL_ACCESS) && (cp11 == CPACR_CP_FULL_ACCESS);
}

/*
 * ============================================================================
 * FPU Type Identification
 * FPU 类型识别
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-662 (MVFR0 register)
 * ============================================================================
 */

uint32_t fpu_get_type(void)
{
    uint32_t mvfr0 = FPU_MVFR0;
    
    /* Check FP rounding modes support */
    if ((mvfr0 & 0xF) == 0) {
        return 0;  /* No FPU */
    }
    
    /* Check double precision support */
    if ((mvfr0 & 0xF0) == 0) {
        return 1;  /* Single precision only */
    }
    
    return 2;  /* Single and double precision */
}

/*
 * ============================================================================
 * Lazy State Preservation
 * 惰性状态保存
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-615 (FPCCR register)
 * ============================================================================
 */

void fpu_enable_lazy_preservation(void)
{
    FPU_FPCCR |= FPU_FPCCR_ASPEN_Msk | FPU_FPCCR_LSPEN_Msk;
}

void fpu_disable_lazy_preservation(void)
{
    FPU_FPCCR &= ~(FPU_FPCCR_ASPEN_Msk | FPU_FPCCR_LSPEN_Msk);
}

/*
 * ============================================================================
 * FPDSCR Configuration
 * FPU 默认状态控制寄存器配置
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-617 (FPDSCR register)
 * ============================================================================
 */

uint32_t fpu_get_fpdscr(void)
{
    return FPU_FPDSCR;
}

void fpu_set_fpdscr(uint32_t fpdscr)
{
    FPU_FPDSCR = fpdscr;
}

void fpu_set_rounding_mode(uint32_t mode)
{
    uint32_t fpdscr = FPU_FPDSCR;
    fpdscr &= ~FPU_FPDSCR_RMode_Msk;
    fpdscr |= (mode << FPU_FPDSCR_RMode_Pos);
    FPU_FPDSCR = fpdscr;
}

void fpu_enable_flush_to_zero(void)
{
    FPU_FPDSCR |= FPU_FPDSCR_FZ_Msk;
}

void fpu_disable_flush_to_zero(void)
{
    FPU_FPDSCR &= ~FPU_FPDSCR_FZ_Msk;
}

void fpu_enable_default_nan(void)
{
    FPU_FPDSCR |= FPU_FPDSCR_DN_Msk;
}

void fpu_disable_default_nan(void)
{
    FPU_FPDSCR &= ~FPU_FPDSCR_DN_Msk;
}
