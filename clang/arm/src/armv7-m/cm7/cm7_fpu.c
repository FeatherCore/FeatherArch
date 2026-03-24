/*
 * ARM Architecture - Cortex-M7 FPU Extension
 *
 * ============================================================================
 * File: cm7_fpu.c
 * Description: Cortex-M7 Floating-Point Unit (FPv5) functions implementation
 * 描述: Cortex-M7 浮点单元 (FPv5) 函数实现
 *
 * @reference Arm Cortex-M7 Processor Technical Reference Manual
 *   - Section 3.2 Register summary, Table 3-1 System control registers
 *   - Section 3.3.13 Floating-point Extension registers
 *
 * @reference Arm Cortex-M7 Devices Generic User Guide
 *   - Section 4.7 Floating Point Unit
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/cm7/cm7_fpu.h"

/* ============================================================================
 * FPU Control Functions
 * FPU 控制函数
 * ============================================================================ */

/**
 * @brief Enable FPU
 * 使能 FPU
 */
void cm7_fpu_enable(void)
{
    /* Enable CP10 and CP11 coprocessors for full access */
    CM7_CPACR |= (CM7_CPACR_CP10_FULL | CM7_CPACR_CP11_FULL);
    __DSB();
    __ISB();
}

/**
 * @brief Disable FPU
 * 禁用 FPU
 */
void cm7_fpu_disable(void)
{
    /* Disable CP10 and CP11 coprocessors */
    CM7_CPACR &= ~(CM7_CPACR_CP10_Msk | CM7_CPACR_CP11_Msk);
    __DSB();
    __ISB();
}

/**
 * @brief Enable lazy FPU context preservation
 * 使能延迟 FPU 上下文保存
 */
void cm7_fpu_lazy_preservation_enable(void)
{
    CM7_FPCCR |= CM7_FPCCR_LSPEN_Msk;
    __DSB();
}

/**
 * @brief Disable lazy FPU context preservation
 * 禁用延迟 FPU 上下文保存
 */
void cm7_fpu_lazy_preservation_disable(void)
{
    CM7_FPCCR &= ~CM7_FPCCR_LSPEN_Msk;
    __DSB();
}

/**
 * @brief Enable automatic FPU state preservation
 * 使能自动 FPU 状态保存
 */
void cm7_fpu_auto_preservation_enable(void)
{
    CM7_FPCCR |= CM7_FPCCR_ASPEN_Msk;
    __DSB();
}

/**
 * @brief Disable automatic FPU state preservation
 * 禁用自动 FPU 状态保存
 */
void cm7_fpu_auto_preservation_disable(void)
{
    CM7_FPCCR &= ~CM7_FPCCR_ASPEN_Msk;
    __DSB();
}

/* ============================================================================
 * FPU Configuration Functions
 * FPU 配置函数
 * ============================================================================ */

/**
 * @brief Set FPU rounding mode
 * 设置 FPU 舍入模式
 */
void cm7_fpu_set_rounding_mode(uint32_t mode)
{
    uint32_t fpscr;

    /* Read current FPSCR using VMRS instruction */
    __ASM volatile ("vmrs %0, fpscr" : "=r" (fpscr));

    /* Clear and set rounding mode bits */
    fpscr &= ~CM7_FPSCR_RMode_Msk;
    fpscr |= (mode << CM7_FPSCR_RMode_Pos) & CM7_FPSCR_RMode_Msk;

    /* Write back to FPSCR using VMSR instruction */
    __ASM volatile ("vmsr fpscr, %0" : : "r" (fpscr));
    __ISB();
}

/**
 * @brief Get FPU rounding mode
 * 获取 FPU 舍入模式
 */
uint32_t cm7_fpu_get_rounding_mode(void)
{
    uint32_t fpscr;

    /* Read FPSCR using VMRS instruction */
    __ASM volatile ("vmrs %0, fpscr" : "=r" (fpscr));

    return (fpscr & CM7_FPSCR_RMode_Msk) >> CM7_FPSCR_RMode_Pos;
}

/**
 * @brief Enable Flush-to-Zero mode
 * 使能 Flush-to-Zero 模式
 */
void cm7_fpu_ftz_enable(void)
{
    uint32_t fpscr;

    /* Read current FPSCR */
    __ASM volatile ("vmrs %0, fpscr" : "=r" (fpscr));

    /* Set FZ bit */
    fpscr |= CM7_FPSCR_FZ_Msk;

    /* Write back to FPSCR */
    __ASM volatile ("vmsr fpscr, %0" : : "r" (fpscr));
    __ISB();
}

/**
 * @brief Disable Flush-to-Zero mode
 * 禁用 Flush-to-Zero 模式
 */
void cm7_fpu_ftz_disable(void)
{
    uint32_t fpscr;

    /* Read current FPSCR */
    __ASM volatile ("vmrs %0, fpscr" : "=r" (fpscr));

    /* Clear FZ bit */
    fpscr &= ~CM7_FPSCR_FZ_Msk;

    /* Write back to FPSCR */
    __ASM volatile ("vmsr fpscr, %0" : : "r" (fpscr));
    __ISB();
}

/**
 * @brief Enable Default NaN mode
 * 使能 Default NaN 模式
 */
void cm7_fpu_dnan_enable(void)
{
    uint32_t fpscr;

    /* Read current FPSCR */
    __ASM volatile ("vmrs %0, fpscr" : "=r" (fpscr));

    /* Set DN bit */
    fpscr |= CM7_FPSCR_DN_Msk;

    /* Write back to FPSCR */
    __ASM volatile ("vmsr fpscr, %0" : : "r" (fpscr));
    __ISB();
}

/**
 * @brief Disable Default NaN mode
 * 禁用 Default NaN 模式
 */
void cm7_fpu_dnan_disable(void)
{
    uint32_t fpscr;

    /* Read current FPSCR */
    __ASM volatile ("vmrs %0, fpscr" : "=r" (fpscr));

    /* Clear DN bit */
    fpscr &= ~CM7_FPSCR_DN_Msk;

    /* Write back to FPSCR */
    __ASM volatile ("vmsr fpscr, %0" : : "r" (fpscr));
    __ISB();
}

/* ============================================================================
 * FPU Information Functions
 * FPU 信息函数
 * ============================================================================ */

/**
 * @brief Check if double-precision is supported
 * 检查是否支持双精度
 */
uint32_t cm7_fpu_has_double_precision(void)
{
    uint32_t mvfr0 = CM7_MVFR0;
    uint32_t dp_value = (mvfr0 & CM7_MVFR0_Double_precision_Msk) >> CM7_MVFR0_Double_precision_Pos;

    /* dp_value == 0x2 means double-precision is supported */
    return (dp_value == 0x2U) ? 1U : 0U;
}

/**
 * @brief Get FPU feature information
 * 获取 FPU 特性信息
 */
uint32_t cm7_fpu_get_feature(uint32_t reg)
{
    uint32_t value = 0U;

    switch (reg) {
        case 0U:
            value = CM7_MVFR0;
            break;
        case 1U:
            value = CM7_MVFR1;
            break;
        case 2U:
            value = CM7_MVFR2;
            break;
        default:
            value = 0U;
            break;
    }

    return value;
}
