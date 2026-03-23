/*
 * ARM Architecture - ARMv7-M FPU (Floating-Point Unit)
 *
 * ============================================================================
 * File: armv7-m_fpu.c
 * Description: ARMv7-M FPU function implementations
 * 描述: ARMv7-M FPU 函数实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual
 *   - Chapter B4: Floating-point Support
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_fpu.h"

/*
 * ============================================================================
 * FPU Enable/Disable
 * FPU 启用/禁用
 * ============================================================================
 */

void fpu_enable(void)
{
    uint32_t cpacr = FPU_CPACR;
    
    cpacr &= ~(FPU_CPACR_CP11_Msk | FPU_CPACR_CP10_Msk);
    cpacr |= (CPACR_CP_FULL_ACCESS << FPU_CPACR_CP11_Pos) | 
             (CPACR_CP_FULL_ACCESS << FPU_CPACR_CP10_Pos);
    
    FPU_CPACR = cpacr;
    
    __asm__ volatile("dsb");
    __asm__ volatile("isb");
}

void fpu_disable(void)
{
    uint32_t cpacr = FPU_CPACR;
    
    cpacr &= ~(FPU_CPACR_CP11_Msk | FPU_CPACR_CP10_Msk);
    
    FPU_CPACR = cpacr;
    
    __asm__ volatile("dsb");
    __asm__ volatile("isb");
}

bool fpu_is_enabled(void)
{
    uint32_t cpacr = FPU_CPACR;
    uint32_t cp10 = (cpacr & FPU_CPACR_CP10_Msk) >> FPU_CPACR_CP10_Pos;
    uint32_t cp11 = (cpacr & FPU_CPACR_CP11_Msk) >> FPU_CPACR_CP11_Pos;
    
    return (cp10 == CPACR_CP_FULL_ACCESS) && (cp11 == CPACR_CP_FULL_ACCESS);
}

/*
 * ============================================================================
 * FPU Type Identification
 * FPU 类型识别
 * ============================================================================
 */

uint32_t fpu_get_type(void)
{
    uint32_t mvfr0 = FPU_MVFR0;
    
    if ((mvfr0 & 0xF) == 0) {
        return 0;
    }
    
    if ((mvfr0 & 0xF0) == 0) {
        return 1;
    }
    
    return 2;
}

/*
 * ============================================================================
 * Lazy State Preservation
 * 惰性状态保存
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
 * FPSCR Configuration
 * FPSCR 配置
 * ============================================================================
 */

uint32_t fpu_get_fpscr(void)
{
    return FPU_FPSCR;
}

void fpu_set_fpscr(uint32_t fpscr)
{
    FPU_FPSCR = fpscr;
}

void fpu_set_rounding_mode(uint32_t mode)
{
    uint32_t fpscr = FPU_FPSCR;
    fpscr &= ~FPU_FPSCR_RMode_Msk;
    fpscr |= (mode << FPU_FPSCR_RMode_Pos);
    FPU_FPSCR = fpscr;
}

void fpu_enable_flush_to_zero(void)
{
    FPU_FPSCR |= FPU_FPSCR_FZ_Msk;
}

void fpu_disable_flush_to_zero(void)
{
    FPU_FPSCR &= ~FPU_FPSCR_FZ_Msk;
}

void fpu_enable_default_nan(void)
{
    FPU_FPSCR |= FPU_FPSCR_DN_Msk;
}

void fpu_disable_default_nan(void)
{
    FPU_FPSCR &= ~FPU_FPSCR_DN_Msk;
}

/*
 * ============================================================================
 * Exception Handling
 * 异常处理
 * ============================================================================
 */

void fpu_clear_exceptions(void)
{
    uint32_t fpscr = FPU_FPSCR;
    fpscr &= ~(FPU_FPSCR_IOC_Msk | FPU_FPSCR_DZC_Msk | FPU_FPSCR_OFC_Msk | 
               FPU_FPSCR_UFC_Msk | FPU_FPSCR_IXC_Msk | FPU_FPSCR_IDC_Msk);
    FPU_FPSCR = fpscr;
}

uint32_t fpu_get_exceptions(void)
{
    return FPU_FPSCR & (FPU_FPSCR_IOC_Msk | FPU_FPSCR_DZC_Msk | FPU_FPSCR_OFC_Msk | 
                        FPU_FPSCR_UFC_Msk | FPU_FPSCR_IXC_Msk | FPU_FPSCR_IDC_Msk);
}
