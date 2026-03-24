/*
 * ARM Architecture - Cortex-M4 FPU Implementation
 *
 * ============================================================================
 * File: cm4_fpu.c
 * Description: Cortex-M4 FPU function implementations
 * 描述: Cortex-M4 FPU 函数实现
 *
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual (100166_0001_04_en)
 *   - Chapter 7 Floating-Point Unit (page 7-65)
 *   - Table 7-4 Cortex-M4 Floating Point system registers (page 7-71)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include "armv7-m/cm4/cm4_fpu.h"
#include "armv7-m/cm4/cm4_scb.h"

/**
 * @brief Enable FPU
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 7.3.2 (page 7-71)
 */
void cm4_fpu_enable(void)
{
    SCB_CPACR |= (SCB_CPACR_CP_FULL_ACCESS << SCB_CPACR_CP10_Pos) |
                 (SCB_CPACR_CP_FULL_ACCESS << SCB_CPACR_CP11_Pos);
    __asm__ volatile ("DSB" ::: "memory");
    __asm__ volatile ("ISB" ::: "memory");
}

/**
 * @brief Disable FPU
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 7.3.2 (page 7-71)
 */
void cm4_fpu_disable(void)
{
    SCB_CPACR &= ~((SCB_CPACR_CP_FULL_ACCESS << SCB_CPACR_CP10_Pos) |
                   (SCB_CPACR_CP_FULL_ACCESS << SCB_CPACR_CP11_Pos));
    __asm__ volatile ("DSB" ::: "memory");
    __asm__ volatile ("ISB" ::: "memory");
}

/**
 * @brief Enable lazy stacking
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 7.2.7 (page 7-70)
 */
void cm4_fpu_enable_lazy_stacking(void)
{
    FPU_FPCCR |= FPU_FPCCR_LSPEN_Msk;
}

/**
 * @brief Disable lazy stacking
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 7.2.7 (page 7-70)
 */
void cm4_fpu_disable_lazy_stacking(void)
{
    FPU_FPCCR &= ~FPU_FPCCR_LSPEN_Msk;
}

/**
 * @brief Check if lazy stacking is active
 * @return 1 if active, 0 if not
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 7.2.7 (page 7-70)
 */
int cm4_fpu_is_lazy_active(void)
{
    return (FPU_FPCCR & FPU_FPCCR_LSPACT_Msk) ? 1 : 0;
}

/**
 * @brief Get FPU feature register 0
 * @return MVFR0 value
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 7-4 (page 7-71)
 */
uint32_t cm4_fpu_get_mvfr0(void)
{
    return FPU_MVFR0;
}

/**
 * @brief Get FPU feature register 1
 * @return MVFR1 value
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 7-4 (page 7-71)
 */
uint32_t cm4_fpu_get_mvfr1(void)
{
    return FPU_MVFR1;
}
