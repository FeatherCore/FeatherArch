/*
 * ARM Architecture - ARMv7-M FPU (Floating-Point Unit)
 *
 * ============================================================================
 * File: armv7-m_fpu.h
 * Description: ARMv7-M FPU register definitions and function declarations
 * 描述: ARMv7-M FPU 寄存器定义和函数声明
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Table B3-5 Summary of additional SCB registers for the FP extension (page B3-597)
 *   - Chapter B4: Floating-point Support
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_FPU_H__
#define __ARCH_ARM_V7M_FPU_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv7-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * FPU Register Definitions
 * FPU 寄存器定义
 * Reference: Table B3-5 Summary of additional SCB registers for the FP extension
 * ============================================================================
 */

/**
 * Floating-Point Context Control Register (FPCCR)
 * Address: 0xE000EF34
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-615
 */
#define FPU_FPCCR                 (*(volatile uint32_t *)(0xE000EF34UL))

/**
 * Floating-Point Context Address Register (FPCAR)
 * Address: 0xE000EF38
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-617
 */
#define FPU_FPCAR                 (*(volatile uint32_t *)(0xE000EF38UL))

/**
 * Floating-Point Default Status Control Register (FPDSCR)
 * Address: 0xE000EF3C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-617
 */
#define FPU_FPDSCR                (*(volatile uint32_t *)(0xE000EF3CUL))

/**
 * Media and FP Feature Register 0 (MVFR0)
 * Address: 0xE000EF40
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-662
 */
#define FPU_MVFR0                 (*(volatile uint32_t *)(0xE000EF40UL))

/**
 * Media and FP Feature Register 1 (MVFR1)
 * Address: 0xE000EF44
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-663
 */
#define FPU_MVFR1                 (*(volatile uint32_t *)(0xE000EF44UL))

/**
 * Media and FP Feature Register 2 (MVFR2)
 * Address: 0xE000EF48
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-664
 */
#define FPU_MVFR2                 (*(volatile uint32_t *)(0xE000EF48UL))

/*
 * ============================================================================
 * FPU Register Bit Definitions
 * FPU 寄存器位定义
 * ============================================================================
 */

/**
 * FPCCR Register Bits
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-615
 */
#define FPU_FPCCR_ASPEN_Pos       31U
#define FPU_FPCCR_ASPEN_Msk       (1UL << FPU_FPCCR_ASPEN_Pos)
#define FPU_FPCCR_LSPEN_Pos       30U
#define FPU_FPCCR_LSPEN_Msk       (1UL << FPU_FPCCR_LSPEN_Pos)
#define FPU_FPCCR_MONRDY_Pos      8U
#define FPU_FPCCR_MONRDY_Msk      (1UL << FPU_FPCCR_MONRDY_Pos)
#define FPU_FPCCR_SFRDY_Pos       7U
#define FPU_FPCCR_SFRDY_Msk       (1UL << FPU_FPCCR_SFRDY_Pos)
#define FPU_FPCCR_BFRDY_Pos       6U
#define FPU_FPCCR_BFRDY_Msk       (1UL << FPU_FPCCR_BFRDY_Pos)
#define FPU_FPCCR_MMRDY_Pos       5U
#define FPU_FPCCR_MMRDY_Msk       (1UL << FPU_FPCCR_MMRDY_Pos)
#define FPU_FPCCR_HFRDY_Pos       4U
#define FPU_FPCCR_HFRDY_Msk       (1UL << FPU_FPCCR_HFRDY_Pos)
#define FPU_FPCCR_THREAD_Pos      3U
#define FPU_FPCCR_THREAD_Msk      (1UL << FPU_FPCCR_THREAD_Pos)
#define FPU_FPCCR_S_Pos           2U
#define FPU_FPCCR_S_Msk           (1UL << FPU_FPCCR_S_Pos)
#define FPU_FPCCR_USER_Pos        1U
#define FPU_FPCCR_USER_Msk        (1UL << FPU_FPCCR_USER_Pos)
#define FPU_FPCCR_LSPACT_Pos      0U
#define FPU_FPCCR_LSPACT_Msk      (1UL << FPU_FPCCR_LSPACT_Pos)

/**
 * FPDSCR Register Bits
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-617
 */
#define FPU_FPDSCR_AHP_Pos        26U
#define FPU_FPDSCR_AHP_Msk        (1UL << FPU_FPDSCR_AHP_Pos)
#define FPU_FPDSCR_DN_Pos         25U
#define FPU_FPDSCR_DN_Msk         (1UL << FPU_FPDSCR_DN_Pos)
#define FPU_FPDSCR_FZ_Pos         24U
#define FPU_FPDSCR_FZ_Msk         (1UL << FPU_FPDSCR_FZ_Pos)
#define FPU_FPDSCR_RMode_Pos      22U
#define FPU_FPDSCR_RMode_Msk      (3UL << FPU_FPDSCR_RMode_Pos)

/*
 * ============================================================================
 * Coprocessor Access Control Register (CPACR)
 * Located in SCB at 0xE000ED88
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-614
 * ============================================================================
 */

/**
 * CPACR Register Bits
 */
#define CPACR_CP11_Pos            22U
#define CPACR_CP11_Msk            (3UL << CPACR_CP11_Pos)
#define CPACR_CP10_Pos            20U
#define CPACR_CP10_Msk            (3UL << CPACR_CP10_Pos)

/* CP10/CP11 Access Values */
#define CPACR_CP_DISABLE          0x0U  /* Access denied */
#define CPACR_CP_PRIV_ONLY        0x1U  /* Privileged access only */
#define CPACR_CP_RESERVED         0x2U  /* Reserved */
#define CPACR_CP_FULL_ACCESS      0x3U  /* Full access */

/**
 * Rounding Modes
 * 舍入模式
 */
#define FPU_ROUND_NEAREST         0x0U  /* Round to nearest */
#define FPU_ROUND_PLUS_INF        0x1U  /* Round towards plus infinity */
#define FPU_ROUND_MINUS_INF       0x2U  /* Round towards minus infinity */
#define FPU_ROUND_ZERO            0x3U  /* Round towards zero */

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Enable FPU
 */
void fpu_enable(void);

/**
 * @brief Disable FPU
 */
void fpu_disable(void);

/**
 * @brief Check if FPU is enabled
 * @return true if enabled, false otherwise
 */
bool fpu_is_enabled(void);

/**
 * @brief Get FPU type
 * @return 0 = none, 1 = single precision, 2 = double precision
 */
uint32_t fpu_get_type(void);

/**
 * @brief Enable automatic lazy state preservation
 */
void fpu_enable_lazy_preservation(void);

/**
 * @brief Disable automatic lazy state preservation
 */
void fpu_disable_lazy_preservation(void);

/**
 * @brief Get FPDSCR value
 * @return FPDSCR value
 */
uint32_t fpu_get_fpdscr(void);

/**
 * @brief Set FPDSCR value
 * @param fpdscr New FPDSCR value
 */
void fpu_set_fpdscr(uint32_t fpdscr);

/**
 * @brief Set rounding mode
 * @param mode Rounding mode (FPU_ROUND_*)
 */
void fpu_set_rounding_mode(uint32_t mode);

/**
 * @brief Enable flush-to-zero mode
 */
void fpu_enable_flush_to_zero(void);

/**
 * @brief Disable flush-to-zero mode
 */
void fpu_disable_flush_to_zero(void);

/**
 * @brief Enable default NaN mode
 */
void fpu_enable_default_nan(void);

/**
 * @brief Disable default NaN mode
 */
void fpu_disable_default_nan(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_FPU_H__ */
