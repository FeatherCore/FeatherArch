/*
 * ARM Architecture - ARMv7-M FPU (Floating-Point Unit)
 *
 * ============================================================================
 * File: armv7-m_fpu.c
 * Description: ARMv7-M FPU function implementations
 * 描述: ARMv7-M FPU 函数实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter A1: Introduction
 *     * A1.3 Architecture extensions (page A1-22)
 *       - Floating-point Extension (FPv4-SP, FPv5)
 *   - Chapter A2: Application Level Programmers' Model
 *     * A2.5 The optional Floating-point Extension (page A2-34)
 *       - A2.5.1 Floating-point standards, and terminology
 *       - A2.5.2 The FP extension registers (S0-S31, D0-D15)
 *       - A2.5.3 Floating-point Status and Control Register (FPSCR)
 *     * A2.6 Coprocessor support (page A2-61)
 *       - CP10 and CP11 access control
 *   - Chapter A3: Arm Architecture Memory Model
 *     * A3.7 Memory access order (page A3-89)
 *       - DSB and ISB required after CPACR modification
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
 *
 * Reference: Chapter A2.6 Coprocessor support (page A2-61)
 *   - CP10 and CP11 support the Floating-point Extension
 *   - Software must enable access to both CP10 and CP11 before using FP
 *   - CPACR controls coprocessor access privileges
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-614 (CPACR register)
 * ============================================================================
 */

/**
 * @brief Enable FPU by granting full access to CP10 and CP11
 *
 * Reference: Chapter A2.6 Coprocessor support (page A2-61)
 *   - Must enable both CP10 and CP11 for FPU to work
 *   - Access levels: 0=Deny, 1=Privileged only, 3=Full access
 *   - Reference: Chapter A3.7 Memory access order (page A3-89)
 *     * DSB and ISB required after modifying CPACR
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

/**
 * @brief Disable FPU by removing access to CP10 and CP11
 *
 * Reference: Chapter A2.6 Coprocessor support (page A2-61)
 *   - Disabling CP10/CP11 access prevents FPU instruction execution
 *   - Any FP instruction will generate NOCP UsageFault when disabled
 *   - Reference: Chapter A3.7 Memory access order (page A3-89)
 *     * DSB and ISB required after modifying CPACR
 */
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
 *
 * Reference: Chapter A1.3 Architecture extensions (page A1-22)
 *   - FPv4-SP: Single-precision only implementation
 *   - FPv5: Adds optional double-precision and additional instructions
 *   - Table A1-1 Floating-point Extension full characterizations
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-662 (MVFR0 register)
 * ============================================================================
 */

/**
 * @brief Get FPU type based on MVFR0 register
 * @return 0 = none, 1 = single precision, 2 = double precision
 *
 * Reference: Chapter A2.5 The optional Floating-point Extension (page A2-34)
 *   - FPv4-SP supports single-precision only
 *   - FPv5 adds optional double-precision support
 *   - MVFR0 register indicates supported features
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
 *
 * Reference: Chapter A2.5.3 Floating-point Status and Control Register, FPSCR (page A2-36)
 *   - FPDSCR provides default values for FPSCR on exception entry
 *   - Controls rounding mode, flush-to-zero, default NaN
 *   - Reference: Chapter A2.5.1 Floating-point standards, and terminology (page A2-34)
 *     * IEEE 754 compliance and rounding modes
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-617 (FPDSCR register)
 * ============================================================================
 */

/**
 * @brief Get FPDSCR value
 * @return FPDSCR value
 *
 * Reference: Chapter A2.5.3 Floating-point Status and Control Register (page A2-36)
 *   - FPDSCR provides default FPSCR values for exception handlers
 *   - Contains rounding mode, flush-to-zero, and default NaN settings
 */
uint32_t fpu_get_fpdscr(void)
{
    return FPU_FPDSCR;
}

void fpu_set_fpdscr(uint32_t fpdscr)
{
    FPU_FPDSCR = fpdscr;
}

/**
 * @brief Set FPU rounding mode
 * @param mode Rounding mode (FPU_ROUND_*)
 *
 * Reference: Chapter A2.5.1 Floating-point standards, and terminology (page A2-34)
 *   - Rounding modes per IEEE 754 standard:
 *     * 0 = Round to Nearest (RN) - roundTiesToEven
 *     * 1 = Round towards Plus Infinity (RP)
 *     * 2 = Round towards Minus Infinity (RM)
 *     * 3 = Round towards Zero (RZ)
 *   - Affects how inexact floating-point results are rounded
 */
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
