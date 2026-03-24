/*
 * ARM Architecture - Cortex-M7 Core Definitions
 *
 * ============================================================================
 * File: core_cm7.h
 * Description: Cortex-M7 processor core definitions and configuration
 * 描述: Cortex-M7 处理器核心定义和配置
 *
 * The Cortex-M7 processor is based on ARMv7E-M architecture and features:
 * - ARMv7E-M instruction set with DSP extensions
 * - Optional Floating Point Unit (FPU) with FPv5 (single or double precision)
 * - Optional Memory Protection Unit (MPU) with 8 or 16 regions
 * - Integrated Instruction and Data Cache
 * - Tightly-Coupled Memory (ITCM and DTCM)
 * - Nested Vectored Interrupt Controller (NVIC)
 * - Branch Target Address Cache (BTAC)
 * - Dual-issue capability
 *
 * @reference Arm Cortex-M7 Processor Technical Reference Manual
 *   - Section 1.1 About the Cortex-M7 processor
 *   - Section 3.2 Register summary, Table 3-1 System control registers
 *   - Section 3.3.2 CPUID Base Register
 *
 * @reference Arm Cortex-M7 Devices Generic User Guide
 *   - Section 1.1 About the Cortex-M7 processor and core peripherals
 *   - Section 4.5 Processor features
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CORE_CM7_H__
#define __CORE_CM7_H__

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================================
 * Cortex-M7 Configuration
 * Reference: Arm Cortex-M7 Processor Technical Reference Manual, Section 1.1
 * ============================================================================ */

/**
 * @brief Cortex-M7 processor identification
 * Reference: Arm Cortex-M7 Processor Technical Reference Manual, Section 3.3.2
 * CPUID.PARTNO = 0xC27 indicates Cortex-M7
 */
#ifndef __CORTEX_M
#define __CORTEX_M              7U
#endif

/**
 * @brief ARMv7E-M Architecture
 * Reference: Arm Cortex-M7 Devices Generic User Guide, Section 1.1
 * The Cortex-M7 processor implements a version of the Thumb instruction set
 * based on Thumb-2 technology (ARMv7E-M)
 */
#ifndef __ARM_ARCH
#define __ARM_ARCH              7U
#endif

#ifndef __ARM_ARCH_PROFILE
#define __ARM_ARCH_PROFILE     'M'
#endif

/* ============================================================================
 * Cortex-M7 Feature Configuration
 * Reference: Arm Cortex-M7 Devices Generic User Guide, Section 1.1
 * ============================================================================ */

/**
 * @brief DSP Extension Present
 * DSP 扩展存在
 * Reference: Arm Cortex-M7 Devices Generic User Guide, Section 1.1
 * Cortex-M7 always has DSP extension
 */
#ifndef __DSP_PRESENT
#define __DSP_PRESENT           1U
#endif

/**
 * @brief FPU Present
 * FPU 存在
 * Reference: Arm Cortex-M7 Devices Generic User Guide, Section 1.1
 * Optional single-precision, or both single-precision and double-precision
 */
#ifndef __FPU_PRESENT
#define __FPU_PRESENT           1U
#endif

/**
 * @brief FPU Double Precision Support
 * FPU 双精度支持
 * Reference: Arm Cortex-M7 Devices Generic User Guide, Section 1.1
 * 0 = Single precision only, 1 = Single and Double precision
 */
#ifndef __FPU_DP
#define __FPU_DP                1U  /* Default to support both SP and DP */
#endif

/**
 * @brief MPU Present
 * MPU 存在
 * Reference: Arm Cortex-M7 Devices Generic User Guide, Section 1.1
 * Optional Memory Protection Unit
 */
#ifndef __MPU_PRESENT
#define __MPU_PRESENT           1U
#endif

/**
 * @brief Number of MPU Regions
 * MPU 区域数量
 * Reference: Arm Cortex-M7 Devices Generic User Guide, Section 4.6
 * Cortex-M7 supports 8 or 16 regions
 */
#ifndef __MPU_NUM_REGIONS
#define __MPU_NUM_REGIONS       16U
#endif

/**
 * @brief Instruction Cache Present
 * Reference: Arm Cortex-M7 Devices Generic User Guide, Section 1.1
 * Optional integrated instruction cache
 */
#ifndef __ICACHE_PRESENT
#define __ICACHE_PRESENT        1U
#endif

/**
 * @brief Data Cache Present
 * Reference: Arm Cortex-M7 Devices Generic User Guide, Section 1.1
 * Optional integrated data cache
 */
#ifndef __DCACHE_PRESENT
#define __DCACHE_PRESENT        1U
#endif

/**
 * @brief ITCM Present
 * Reference: Arm Cortex-M7 Devices Generic User Guide, Section 1.1
 * Optional Instruction Tightly-Coupled Memory
 */
#ifndef __ITCM_PRESENT
#define __ITCM_PRESENT          1U
#endif

/**
 * @brief DTCM Present
 * Reference: Arm Cortex-M7 Devices Generic User Guide, Section 1.1
 * Optional Data Tightly-Coupled Memory
 */
#ifndef __DTCM_PRESENT
#define __DTCM_PRESENT          1U
#endif

/**
 * @brief NVIC Priority Bits
 * NVIC 优先级位数
 * Reference: Arm Cortex-M7 Devices Generic User Guide, Section 4.2
 * Cortex-M7 supports 4-8 bits (16-256 priority levels)
 */
#ifndef __NVIC_PRIO_BITS
#define __NVIC_PRIO_BITS        4U
#endif

/**
 * @brief Vendor SysTick Config
 * 供应商 SysTick 配置
 */
#ifndef __Vendor_SysTickConfig
#define __Vendor_SysTickConfig  0U
#endif

/* ============================================================================
 * Cortex-M7 CPUID Register Values
 * Reference: Arm Cortex-M7 Processor Technical Reference Manual, Section 3.3.2
 * Table 3-4 CPUID bit assignments
 * ============================================================================ */

/**
 * @brief CPUID IMPLEMENTER value
 * Reference: Table 3-4 CPUID bit assignments
 * 0x41 = Arm
 */
#define __CM7_IMPLEMENTER       0x41U

/**
 * @brief CPUID PARTNO value
 * Reference: Table 3-4 CPUID bit assignments
 * 0xC27 = Cortex-M7
 */
#define __CM7_PARTNO            0xC27U

/**
 * @brief CPUID ARCHITECTURE value
 * Reference: Table 3-4 CPUID bit assignments
 * 0xF = ARMv7-M
 */
#define __CM7_ARCHITECTURE      0xFU

/**
 * @brief CPUID VARIANT value (implementation defined)
 * Reference: Table 3-4 CPUID bit assignments
 */
#define __CM7_VARIANT           0x0U

/**
 * @brief CPUID REVISION value (implementation defined)
 * Reference: Table 3-4 CPUID bit assignments
 */
#define __CM7_REVISION          0x0U

/* ============================================================================
 * Cortex-M7 Instruction Set Features
 * Cortex-M7 指令集特性
 * ============================================================================ */

/**
 * @brief Cortex-M7 supports DSP instructions
 * Cortex-M7 支持 DSP 指令
 */
#define __CM7_DSP_INSTRUCTIONS      1

/**
 * @brief Cortex-M7 supports SIMD instructions
 * Cortex-M7 支持 SIMD 指令
 */
#define __CM7_SIMD_INSTRUCTIONS     1

/**
 * @brief Cortex-M7 supports saturating instructions
 * Cortex-M7 支持饱和指令
 */
#define __CM7_SAT_INSTRUCTIONS      1

/**
 * @brief Cortex-M7 supports exclusive access instructions
 * Cortex-M7 支持独占访问指令
 */
#define __CM7_EXCLUSIVE_ACCESS      1

/**
 * @brief Cortex-M7 supports dual-issue
 * Cortex-M7 支持双发射
 */
#define __CM7_DUAL_ISSUE            1

/**
 * @brief Cortex-M7 supports branch target address cache (BTAC)
 * Cortex-M7 支持分支目标地址缓存
 */
#define __CM7_BTAC                  1

/* ============================================================================
 * Cortex-M7 FPU Configuration
 * Cortex-M7 FPU 配置
 * ============================================================================ */

#if (__FPU_PRESENT == 1)
/**
 * @brief FPU Type - FPv5
 * FPU 类型 - FPv5
 */
#define __FPU_TYPE                  5U

/**
 * @brief FPU Double Precision Support
 * FPU 双精度支持
 */
#if (__FPU_DP == 1)
#define __FPU_HAS_DOUBLE_PRECISION  1U
#else
#define __FPU_HAS_DOUBLE_PRECISION  0U
#endif

/**
 * @brief FPU Register Count (S0-S31)
 * FPU 寄存器数量 (S0-S31)
 */
#define __FPU_REG_COUNT             32U

/**
 * @brief FPU Double-precision Register Count (D0-D15)
 * FPU 双精度寄存器数量 (D0-D15)
 */
#define __FPU_DREG_COUNT            16U
#endif /* __FPU_PRESENT */

/* ============================================================================
 * Cortex-M7 Cache Configuration
 * Cortex-M7 缓存配置
 * ============================================================================ */

#if (__ICACHE_PRESENT == 1)
/**
 * @brief Instruction Cache Line Size (in bytes)
 * 指令缓存行大小（字节）
 * Reference: Arm Cortex-M7 TRM, typically 32 bytes
 */
#define __CM7_ICACHE_LINE_SIZE      32U
#endif

#if (__DCACHE_PRESENT == 1)
/**
 * @brief Data Cache Line Size (in bytes)
 * 数据缓存行大小（字节）
 * Reference: Arm Cortex-M7 TRM, typically 32 bytes
 */
#define __CM7_DCACHE_LINE_SIZE      32U
#endif

/* ============================================================================
 * Cortex-M7 TCM Configuration
 * Cortex-M7 TCM 配置
 * ============================================================================ */

#if (__ITCM_PRESENT == 1)
/**
 * @brief ITCM Base Address
 * ITCM 基地址
 */
#define __CM7_ITCM_BASE             0x00000000UL

/**
 * @brief ITCM Size (implementation defined, max 16MB)
 * ITCM 大小（实现定义，最大 16MB）
 */
#ifndef __CM7_ITCM_SIZE
#define __CM7_ITCM_SIZE             (512U * 1024U)  /* 512KB default */
#endif
#endif /* __ITCM_PRESENT */

#if (__DTCM_PRESENT == 1)
/**
 * @brief DTCM Base Address
 * DTCM 基地址
 */
#define __CM7_DTCM_BASE             0x20000000UL

/**
 * @brief DTCM Size (implementation defined, max 16MB)
 * DTCM 大小（实现定义，最大 16MB）
 */
#ifndef __CM7_DTCM_SIZE
#define __CM7_DTCM_SIZE             (512U * 1024U)  /* 512KB default */
#endif
#endif /* __DTCM_PRESENT */

/* ============================================================================
 * Cortex-M7 Revision Information
 * Cortex-M7 版本信息
 * ============================================================================ */

/**
 * @brief Cortex-M7 Revision
 * Cortex-M7 版本
 */
#define __CM7_REV                   0x0000U

/**
 * @brief Cortex-M7 Variant
 * Cortex-M7 变体
 */
#define __CM7_VARIANT_ID            0x00U

/**
 * @brief Cortex-M7 Implementer
 * Cortex-M7 实现者 (ARM)
 */
#define __CM7_IMPLEMENTER_ID        0x41U  /* 'A' = ARM */

#ifdef __cplusplus
}
#endif

#endif /* __CORE_CM7_H__ */
