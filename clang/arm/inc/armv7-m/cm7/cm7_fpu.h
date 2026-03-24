/*
 * ARM Architecture - Cortex-M7 FPU Extension
 *
 * ============================================================================
 * File: cm7_fpu.h
 * Description: Cortex-M7 Floating-Point Unit (FPv5) definitions and functions
 * 描述: Cortex-M7 浮点单元 (FPv5) 定义和函数
 *
 * The Cortex-M7 FPU implements the FPv5 floating-point extensions:
 * - Single-precision (32-bit) floating-point operations
 * - Optional double-precision (64-bit) floating-point operations
 * - Conversion between fixed-point and floating-point
 * - Floating-point constant instructions
 * - IEEE 754-2008 compliant
 *
 * @reference Arm Cortex-M7 Processor Technical Reference Manual
 *   - Section 3.2 Register summary, Table 3-1 System control registers
 *   - Section 3.3.13 Floating-point Extension registers
 *
 * @reference Arm Cortex-M7 Devices Generic User Guide
 *   - Section 4.7 Floating Point Unit
 *   - Section 3.11 Floating-point instructions
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef CM7_FPU_H
#define CM7_FPU_H

#include <stdint.h>
#include "core_cm7.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================================
 * FPU System Registers
 * Reference: Arm Cortex-M7 Devices Generic User Guide, Section 4.7
 * ============================================================================ */

/**
 * @brief Coprocessor Access Control Register (CPACR)
 * Address: 0xE000ED88
 * Type: RW, Privileged
 * Purpose: Specifies access privileges for coprocessors
 */
#define CM7_CPACR                 (*(volatile uint32_t *)(0xE000ED88UL))

/**
 * @brief Floating-point Context Control Register (FPCCR)
 * Address: 0xE000EF34
 * Type: RW, Privileged
 * Purpose: Sets or returns FPU control data
 */
#define CM7_FPCCR                 (*(volatile uint32_t *)(0xE000EF34UL))

/**
 * @brief Floating-point Context Address Register (FPCAR)
 * Address: 0xE000EF38
 * Type: RW, Privileged
 * Purpose: Holds the location of the unpopulated floating-point register space
 */
#define CM7_FPCAR                 (*(volatile uint32_t *)(0xE000EF38UL))

/**
 * @brief Floating-point Default Status Control Register (FPDSCR)
 * Address: 0xE000EF3C
 * Type: RW, Privileged
 * Purpose: Holds the default values for the floating-point status control data
 */
#define CM7_FPDSCR                (*(volatile uint32_t *)(0xE000EF3CUL))

/**
 * @brief Media and FP Feature Register 0 (MVFR0)
 * Address: 0xE000EF40
 * Type: RO, Privileged
 * Purpose: Describes the features provided by the FPU
 */
#define CM7_MVFR0                 (*(volatile uint32_t *)(0xE000EF40UL))

/**
 * @brief Media and FP Feature Register 1 (MVFR1)
 * Address: 0xE000EF44
 * Type: RO, Privileged
 * Purpose: Describes the features provided by the FPU
 */
#define CM7_MVFR1                 (*(volatile uint32_t *)(0xE000EF44UL))

/**
 * @brief Media and FP Feature Register 2 (MVFR2)
 * Address: 0xE000EF48
 * Type: RO, Privileged
 * Purpose: Describes the features provided by the FPU
 */
#define CM7_MVFR2                 (*(volatile uint32_t *)(0xE000EF48UL))

/* ============================================================================
 * CPACR Bit Definitions
 * Reference: Arm Cortex-M7 Devices Generic User Guide, Section 4.7.1
 * ============================================================================ */

/**
 * @brief CP10 access privileges
 * Bits [21:20]
 * 0b00: Access denied
 * 0b01: Privileged access only
 * 0b10: Reserved
 * 0b11: Full access
 */
#define CM7_CPACR_CP10_Pos        20U
#define CM7_CPACR_CP10_Msk        (0x3UL << CM7_CPACR_CP10_Pos)
#define CM7_CPACR_CP10_DENY       (0x0UL << CM7_CPACR_CP10_Pos)
#define CM7_CPACR_CP10_PRIV       (0x1UL << CM7_CPACR_CP10_Pos)
#define CM7_CPACR_CP10_FULL       (0x3UL << CM7_CPACR_CP10_Pos)

/**
 * @brief CP11 access privileges
 * Bits [23:22]
 * 0b00: Access denied
 * 0b01: Privileged access only
 * 0b10: Reserved
 * 0b11: Full access
 */
#define CM7_CPACR_CP11_Pos        22U
#define CM7_CPACR_CP11_Msk        (0x3UL << CM7_CPACR_CP11_Pos)
#define CM7_CPACR_CP11_DENY       (0x0UL << CM7_CPACR_CP11_Pos)
#define CM7_CPACR_CP11_PRIV       (0x1UL << CM7_CPACR_CP11_Pos)
#define CM7_CPACR_CP11_FULL       (0x3UL << CM7_CPACR_CP11_Pos)

/* ============================================================================
 * FPCCR Bit Definitions
 * Reference: Arm Cortex-M7 Devices Generic User Guide, Section 4.7.2
 * ============================================================================ */

/**
 * @brief Lazy state preservation enable
 * Bit [30]
 */
#define CM7_FPCCR_LSPEN_Pos       30U
#define CM7_FPCCR_LSPEN_Msk       (1UL << CM7_FPCCR_LSPEN_Pos)

/**
 * @brief Automatic state preservation enable
 * Bit [31]
 */
#define CM7_FPCCR_ASPEN_Pos       31U
#define CM7_FPCCR_ASPEN_Msk       (1UL << CM7_FPCCR_ASPEN_Pos)

/**
 * @brief Lazy state preservation active
 * Bit [0]
 */
#define CM7_FPCCR_LSPACT_Pos      0U
#define CM7_FPCCR_LSPACT_Msk      (1UL << CM7_FPCCR_LSPACT_Pos)

/**
 * @brief User privilege level
 * Bit [1]
 */
#define CM7_FPCCR_USER_Pos        1U
#define CM7_FPCCR_USER_Msk        (1UL << CM7_FPCCR_USER_Pos)

/**
 * @brief Thread mode
 * Bit [3]
 */
#define CM7_FPCCR_THREAD_Pos      3U
#define CM7_FPCCR_THREAD_Msk      (1UL << CM7_FPCCR_THREAD_Pos)

/**
 * @brief HardFault handler ready
 * Bit [4]
 */
#define CM7_FPCCR_HFRDY_Pos       4U
#define CM7_FPCCR_HFRDY_Msk       (1UL << CM7_FPCCR_HFRDY_Pos)

/**
 * @brief MemManage handler ready
 * Bit [5]
 */
#define CM7_FPCCR_MMRDY_Pos       5U
#define CM7_FPCCR_MMRDY_Msk       (1UL << CM7_FPCCR_MMRDY_Pos)

/**
 * @brief BusFault handler ready
 * Bit [6]
 */
#define CM7_FPCCR_BFRDY_Pos       6U
#define CM7_FPCCR_BFRDY_Msk       (1UL << CM7_FPCCR_BFRDY_Pos)

/**
 * @brief Monitor ready
 * Bit [8]
 */
#define CM7_FPCCR_MONRDY_Pos      8U
#define CM7_FPCCR_MONRDY_Msk      (1UL << CM7_FPCCR_MONRDY_Pos)

/* ============================================================================
 * FPDSCR Bit Definitions
 * Reference: Arm Cortex-M7 Devices Generic User Guide, Section 4.7.4
 * ============================================================================ */

/**
 * @brief Default value for RMode (Rounding Mode)
 * Bits [23:22]
 * 0b00: Round to Nearest (RN)
 * 0b01: Round towards Plus Infinity (RP)
 * 0b10: Round towards Minus Infinity (RM)
 * 0b11: Round towards Zero (RZ)
 */
#define CM7_FPDSCR_RMode_Pos      22U
#define CM7_FPDSCR_RMode_Msk      (0x3UL << CM7_FPDSCR_RMode_Pos)
#define CM7_FPDSCR_RMode_RN       (0x0UL << CM7_FPDSCR_RMode_Pos)
#define CM7_FPDSCR_RMode_RP       (0x1UL << CM7_FPDSCR_RMode_Pos)
#define CM7_FPDSCR_RMode_RM       (0x2UL << CM7_FPDSCR_RMode_Pos)
#define CM7_FPDSCR_RMode_RZ       (0x3UL << CM7_FPDSCR_RMode_Pos)

/**
 * @brief Default value for FZ (Flush-to-Zero)
 * Bit [24]
 */
#define CM7_FPDSCR_FZ_Pos         24U
#define CM7_FPDSCR_FZ_Msk         (1UL << CM7_FPDSCR_FZ_Pos)

/**
 * @brief Default value for DN (Default NaN)
 * Bit [25]
 */
#define CM7_FPDSCR_DN_Pos         25U
#define CM7_FPDSCR_DN_Msk         (1UL << CM7_FPDSCR_DN_Pos)

/**
 * @brief Default value for AHP (Alternative Half-Precision)
 * Bit [26]
 */
#define CM7_FPDSCR_AHP_Pos        26U
#define CM7_FPDSCR_AHP_Msk        (1UL << CM7_FPDSCR_AHP_Pos)

/* ============================================================================
 * FPSCR Bit Definitions (accessed via VMRS/VMSR)
 * Reference: Arm Cortex-M7 Devices Generic User Guide, Section 4.7.3
 * ============================================================================ */

/**
 * @brief Invalid Operation cumulative exception bit
 * Bit [0]
 */
#define CM7_FPSCR_IOC_Pos         0U
#define CM7_FPSCR_IOC_Msk         (1UL << CM7_FPSCR_IOC_Pos)

/**
 * @brief Division by Zero cumulative exception bit
 * Bit [1]
 */
#define CM7_FPSCR_DZC_Pos         1U
#define CM7_FPSCR_DZC_Msk         (1UL << CM7_FPSCR_DZC_Pos)

/**
 * @brief Overflow cumulative exception bit
 * Bit [2]
 */
#define CM7_FPSCR_OFC_Pos         2U
#define CM7_FPSCR_OFC_Msk         (1UL << CM7_FPSCR_OFC_Pos)

/**
 * @brief Underflow cumulative exception bit
 * Bit [3]
 */
#define CM7_FPSCR_UFC_Pos         3U
#define CM7_FPSCR_UFC_Msk         (1UL << CM7_FPSCR_UFC_Pos)

/**
 * @brief Inexact cumulative exception bit
 * Bit [4]
 */
#define CM7_FPSCR_IXC_Pos         4U
#define CM7_FPSCR_IXC_Msk         (1UL << CM7_FPSCR_IXC_Pos)

/**
 * @brief Input Denormal cumulative exception bit
 * Bit [7]
 */
#define CM7_FPSCR_IDC_Pos         7U
#define CM7_FPSCR_IDC_Msk         (1UL << CM7_FPSCR_IDC_Pos)

/**
 * @brief Rounding Mode
 * Bits [23:22]
 */
#define CM7_FPSCR_RMode_Pos       22U
#define CM7_FPSCR_RMode_Msk       (0x3UL << CM7_FPSCR_RMode_Pos)

/**
 * @brief Flush-to-Zero
 * Bit [24]
 */
#define CM7_FPSCR_FZ_Pos          24U
#define CM7_FPSCR_FZ_Msk          (1UL << CM7_FPSCR_FZ_Pos)

/**
 * @brief Default NaN
 * Bit [25]
 */
#define CM7_FPSCR_DN_Pos          25U
#define CM7_FPSCR_DN_Msk          (1UL << CM7_FPSCR_DN_Pos)

/**
 * @brief Alternative Half-Precision
 * Bit [26]
 */
#define CM7_FPSCR_AHP_Pos         26U
#define CM7_FPSCR_AHP_Msk         (1UL << CM7_FPSCR_AHP_Pos)

/* ============================================================================
 * MVFR0 Feature Bits
 * Reference: Arm Cortex-M7 Devices Generic User Guide
 * ============================================================================ */

/**
 * @brief FP rounding modes
 * Bits [3:0]
 */
#define CM7_MVFR0_FP_rounding_modes_Pos   0U
#define CM7_MVFR0_FP_rounding_modes_Msk   (0xFUL << CM7_MVFR0_FP_rounding_modes_Pos)

/**
 * @brief Short vectors
 * Bits [7:4]
 */
#define CM7_MVFR0_Short_vectors_Pos       4U
#define CM7_MVFR0_Short_vectors_Msk       (0xFUL << CM7_MVFR0_Short_vectors_Pos)

/**
 * @brief Square root
 * Bits [11:8]
 */
#define CM7_MVFR0_Square_root_Pos         8U
#define CM7_MVFR0_Square_root_Msk         (0xFUL << CM7_MVFR0_Square_root_Pos)

/**
 * @brief Divide
 * Bits [15:12]
 */
#define CM7_MVFR0_Divide_Pos              12U
#define CM7_MVFR0_Divide_Msk              (0xFUL << CM7_MVFR0_Divide_Pos)

/**
 * @brief FP exception trapping
 * Bits [19:16]
 */
#define CM7_MVFR0_FP_excep_trapping_Pos   16U
#define CM7_MVFR0_FP_excep_trapping_Msk   (0xFUL << CM7_MVFR0_FP_excep_trapping_Pos)

/**
 * @brief Double-precision
 * Bits [23:20]
 */
#define CM7_MVFR0_Double_precision_Pos    20U
#define CM7_MVFR0_Double_precision_Msk    (0xFUL << CM7_MVFR0_Double_precision_Pos)

/**
 * @brief Single-precision
 * Bits [27:24]
 */
#define CM7_MVFR0_Single_precision_Pos    24U
#define CM7_MVFR0_Single_precision_Msk    (0xFUL << CM7_MVFR0_Single_precision_Pos)

/**
 * @brief A_SIMD registers
 * Bits [31:28]
 */
#define CM7_MVFR0_A_SIMD_registers_Pos    28U
#define CM7_MVFR0_A_SIMD_registers_Msk    (0xFUL << CM7_MVFR0_A_SIMD_registers_Pos)

/* ============================================================================
 * FPU Control Functions
 * FPU 控制函数
 * ============================================================================ */

/**
 * @brief Enable FPU
 * 使能 FPU
 *
 * Enables full access to CP10 and CP11 coprocessors.
 */
void cm7_fpu_enable(void);

/**
 * @brief Disable FPU
 * 禁用 FPU
 *
 * Disables access to CP10 and CP11 coprocessors.
 */
void cm7_fpu_disable(void);

/**
 * @brief Enable lazy FPU context preservation
 * 使能延迟 FPU 上下文保存
 *
 * Reduces interrupt latency by deferring FPU register save until required.
 */
void cm7_fpu_lazy_preservation_enable(void);

/**
 * @brief Disable lazy FPU context preservation
 * 禁用延迟 FPU 上下文保存
 */
void cm7_fpu_lazy_preservation_disable(void);

/**
 * @brief Enable automatic FPU state preservation
 * 使能自动 FPU 状态保存
 */
void cm7_fpu_auto_preservation_enable(void);

/**
 * @brief Disable automatic FPU state preservation
 * 禁用自动 FPU 状态保存
 */
void cm7_fpu_auto_preservation_disable(void);

/* ============================================================================
 * FPU Configuration Functions
 * FPU 配置函数
 * ============================================================================ */

/**
 * @brief Set FPU rounding mode
 * 设置 FPU 舍入模式
 *
 * @param mode Rounding mode (0=RN, 1=RP, 2=RM, 3=RZ)
 */
void cm7_fpu_set_rounding_mode(uint32_t mode);

/**
 * @brief Get FPU rounding mode
 * 获取 FPU 舍入模式
 *
 * @return Current rounding mode
 */
uint32_t cm7_fpu_get_rounding_mode(void);

/**
 * @brief Enable Flush-to-Zero mode
 * 使能 Flush-to-Zero 模式
 */
void cm7_fpu_ftz_enable(void);

/**
 * @brief Disable Flush-to-Zero mode
 * 禁用 Flush-to-Zero 模式
 */
void cm7_fpu_ftz_disable(void);

/**
 * @brief Enable Default NaN mode
 * 使能 Default NaN 模式
 */
void cm7_fpu_dnan_enable(void);

/**
 * @brief Disable Default NaN mode
 * 禁用 Default NaN 模式
 */
void cm7_fpu_dnan_disable(void);

/* ============================================================================
 * FPU Information Functions
 * FPU 信息函数
 * ============================================================================ */

/**
 * @brief Check if double-precision is supported
 * 检查是否支持双精度
 *
 * @return 1 if double-precision is supported, 0 otherwise
 */
uint32_t cm7_fpu_has_double_precision(void);

/**
 * @brief Get FPU feature information
 * 获取 FPU 特性信息
 *
 * @param reg Feature register number (0=MVFR0, 1=MVFR1, 2=MVFR2)
 * @return Feature register value
 */
uint32_t cm7_fpu_get_feature(uint32_t reg);

#ifdef __cplusplus
}
#endif

#endif /* CM7_FPU_H */
