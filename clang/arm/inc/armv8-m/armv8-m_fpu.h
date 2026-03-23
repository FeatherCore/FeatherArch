/*
 * ARM Architecture - ARMv8-M FPU (Floating-Point Unit)
 *
 * ============================================================================
 * File: armv8m_fpu.h
 * Description: ARMv8-M FPU register definitions and function declarations
 * 描述: ARMv8-M FPU 寄存器定义和函数声明
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B4: Floating-point Support
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V8M_FPU_H__
#define __ARCH_ARM_V8M_FPU_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv8-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * FPU Base Address
 * FPU 基地址
 * ============================================================================
 */

#define FPU_BASE_ADDR             0xE000EF30UL

/*
 * ============================================================================
 * FPU Register Definitions
 * FPU 寄存器定义
 * ============================================================================
 */

/**
 * Floating-Point Context Control Register (FPCCR)
 * 浮点上下文控制寄存器
 */
#define FPU_FPCCR                 (*(volatile uint32_t *)(0xE000EF34UL))

/**
 * Floating-Point Context Address Register (FPCAR)
 * 浮点上下文地址寄存器
 */
#define FPU_FPCAR                 (*(volatile uint32_t *)(0xE000EF38UL))

/**
 * Floating-Point Default Status Control Register (FPSCR)
 * 浮点默认状态控制寄存器
 */
#define FPU_FPSCR                 (*(volatile uint32_t *)(0xE000EF3CUL))

/**
 * Coprocessor Access Control Register (CPACR)
 * 协处理器访问控制寄存器
 */
#define FPU_CPACR                 (*(volatile uint32_t *)(0xE000ED88UL))

/**
 * Floating-Point Feature Registers (MVFR0-MVFR2)
 * 浮点特性寄存器
 */
#define FPU_MVFR0                 (*(volatile uint32_t *)(0xE000EF40UL))
#define FPU_MVFR1                 (*(volatile uint32_t *)(0xE000EF44UL))
#define FPU_MVFR2                 (*(volatile uint32_t *)(0xE000EF48UL))

/*
 * ============================================================================
 * FPU Register Bit Definitions
 * FPU 寄存器位定义
 * ============================================================================
 */

/**
 * FPCCR Register Bits
 * FPCCR 寄存器位
 */
#define FPU_FPCCR_ASPEN_Pos       31U
#define FPU_FPCCR_ASPEN_Msk       (1UL << FPU_FPCCR_ASPEN_Pos)
#define FPU_FPCCR_LSPEN_Pos       30U
#define FPU_FPCCR_LSPEN_Msk       (1UL << FPU_FPCCR_LSPEN_Pos)
#define FPU_FPCCR_LSPENS_Pos      29U
#define FPU_FPCCR_LSPENS_Msk      (1UL << FPU_FPCCR_LSPENS_Pos)
#define FPU_FPCCR_CLRONRET_Pos    28U
#define FPU_FPCCR_CLRONRET_Msk    (1UL << FPU_FPCCR_CLRONRET_Pos)
#define FPU_FPCCR_CLRONRETS_Pos   27U
#define FPU_FPCCR_CLRONRETS_Msk   (1UL << FPU_FPCCR_CLRONRETS_Pos)
#define FPU_FPCCR_TS_Pos          26U
#define FPU_FPCCR_TS_Msk          (1UL << FPU_FPCCR_TS_Pos)
#define FPU_FPCCR_UFRDY_Pos       10U
#define FPU_FPCCR_UFRDY_Msk       (1UL << FPU_FPCCR_UFRDY_Pos)
#define FPU_FPCCR_SPLIMVIOL_Pos   9U
#define FPU_FPCCR_SPLIMVIOL_Msk   (1UL << FPU_FPCCR_SPLIMVIOL_Pos)
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
 * FPSCR Register Bits
 * FPSCR 寄存器位
 */
#define FPU_FPSCR_N_Pos           31U
#define FPU_FPSCR_N_Msk           (1UL << FPU_FPSCR_N_Pos)
#define FPU_FPSCR_Z_Pos           30U
#define FPU_FPSCR_Z_Msk           (1UL << FPU_FPSCR_Z_Pos)
#define FPU_FPSCR_C_Pos           29U
#define FPU_FPSCR_C_Msk           (1UL << FPU_FPSCR_C_Pos)
#define FPU_FPSCR_V_Pos           28U
#define FPU_FPSCR_V_Msk           (1UL << FPU_FPSCR_V_Pos)
#define FPU_FPSCR_AHP_Pos         26U
#define FPU_FPSCR_AHP_Msk         (1UL << FPU_FPSCR_AHP_Pos)
#define FPU_FPSCR_DN_Pos          25U
#define FPU_FPSCR_DN_Msk          (1UL << FPU_FPSCR_DN_Pos)
#define FPU_FPSCR_FZ_Pos          24U
#define FPU_FPSCR_FZ_Msk          (1UL << FPU_FPSCR_FZ_Pos)
#define FPU_FPSCR_RMode_Pos       22U
#define FPU_FPSCR_RMode_Msk       (3UL << FPU_FPSCR_RMode_Pos)
#define FPU_FPSCR_IDC_Pos         7U
#define FPU_FPSCR_IDC_Msk         (1UL << FPU_FPSCR_IDC_Pos)
#define FPU_FPSCR_IXC_Pos         4U
#define FPU_FPSCR_IXC_Msk         (1UL << FPU_FPSCR_IXC_Pos)
#define FPU_FPSCR_UFC_Pos         3U
#define FPU_FPSCR_UFC_Msk         (1UL << FPU_FPSCR_UFC_Pos)
#define FPU_FPSCR_OFC_Pos         2U
#define FPU_FPSCR_OFC_Msk         (1UL << FPU_FPSCR_OFC_Pos)
#define FPU_FPSCR_DZC_Pos         1U
#define FPU_FPSCR_DZC_Msk         (1UL << FPU_FPSCR_DZC_Pos)
#define FPU_FPSCR_IOC_Pos         0U
#define FPU_FPSCR_IOC_Msk         (1UL << FPU_FPSCR_IOC_Pos)

/**
 * CPACR Register Bits
 * CPACR 寄存器位
 */
#define FPU_CPACR_CP11_Pos        22U
#define FPU_CPACR_CP11_Msk        (3UL << FPU_CPACR_CP11_Pos)
#define FPU_CPACR_CP10_Pos        20U
#define FPU_CPACR_CP10_Msk        (3UL << FPU_CPACR_CP10_Pos)

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
 * @brief Get FPSCR value
 * @return FPSCR value
 */
uint32_t fpu_get_fpscr(void);

/**
 * @brief Set FPSCR value
 * @param fpscr New FPSCR value
 */
void fpu_set_fpscr(uint32_t fpscr);

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

/**
 * @brief Clear all exception flags
 */
void fpu_clear_exceptions(void);

/**
 * @brief Get exception flags
 * @return Exception flags
 */
uint32_t fpu_get_exceptions(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V8M_FPU_H__ */
