/*
 * ARM Architecture - Cortex-M4 Core Definitions
 *
 * ============================================================================
 * File: core_cm4.h
 * Description: Cortex-M4 processor core definitions and configuration
 * 描述: Cortex-M4 处理器核心定义和配置
 *
 * The Cortex-M4 processor is based on ARMv7E-M architecture and features:
 * - ARMv7E-M instruction set with DSP extensions
 * - Optional Floating Point Unit (FPU) with FPv4-SP
 * - Optional Memory Protection Unit (MPU)
 * - Bit-banding support
 * - Nested Vectored Interrupt Controller (NVIC)
 *
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual (DDI 0439)
 *            Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CORE_CM4_H__
#define __CORE_CM4_H__

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================================
 * Cortex-M4 Configuration
 * Cortex-M4 配置
 * ============================================================================ */

/**
 * @brief Cortex-M4 Core Configuration
 * Cortex-M4 核心配置
 */
#ifndef __CORTEX_M
#define __CORTEX_M              4U
#endif

/**
 * @brief ARMv7E-M Architecture
 * ARMv7E-M 架构
 */
#ifndef __ARM_ARCH
#define __ARM_ARCH              7U
#endif

/**
 * @brief ARMv7E-M Architecture Profile
 * ARMv7E-M 架构配置文件
 */
#ifndef __ARM_ARCH_PROFILE
#define __ARM_ARCH_PROFILE     'M'
#endif

/* ============================================================================
 * Cortex-M4 Feature Configuration
 * Cortex-M4 特性配置
 * ============================================================================ */

/**
 * @brief DSP Extension Present
 * DSP 扩展存在
 * Cortex-M4 always has DSP extension
 */
#ifndef __DSP_PRESENT
#define __DSP_PRESENT           1U
#endif

/**
 * @brief FPU Present
 * FPU 存在
 * Optional on Cortex-M4
 */
#ifndef __FPU_PRESENT
#define __FPU_PRESENT           1U
#endif

/**
 * @brief FPU Version - FPv4-SP (Single Precision)
 * FPU 版本 - FPv4-SP（单精度）
 */
#ifndef __FPU_DP
#define __FPU_DP                0U  /* 0 = Single precision only */
#endif

/**
 * @brief MPU Present
 * MPU 存在
 * Optional on Cortex-M4
 */
#ifndef __MPU_PRESENT
#define __MPU_PRESENT           1U
#endif

/**
 * @brief Number of MPU Regions
 * MPU 区域数量
 * Cortex-M4 supports up to 8 regions
 */
#ifndef __MPU_NUM_REGIONS
#define __MPU_NUM_REGIONS       8U
#endif

/**
 * @brief NVIC Priority Bits
 * NVIC 优先级位数
 * Cortex-M4 supports 4 bits (16 priority levels)
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

/**
 * @brief Bit-banding Present
 * 位带(Bit-banding)存在
 * Cortex-M4 supports bit-banding
 */
#ifndef __BITBAND_PRESENT
#define __BITBAND_PRESENT       1U
#endif

/* ============================================================================
 * Cortex-M4 Bit-banding Definitions
 * Cortex-M4 位带定义
 * ============================================================================ */

/**
 * @brief Bit-banding Base Addresses
 * 位带基地址
 * Reference: Cortex-M4 TRM, Section 3.7 Bit-banding
 */
#define BITBAND_SRAM_BASE           0x20000000UL
#define BITBAND_SRAM_ALIAS_BASE     0x22000000UL
#define BITBAND_PERIPH_BASE         0x40000000UL
#define BITBAND_PERIPH_ALIAS_BASE   0x42000000UL

/**
 * @brief Convert SRAM address to bit-band alias address
 * 将 SRAM 地址转换为位带别名地址
 * @param addr Byte address in SRAM bit-band region (0x20000000-0x200FFFFF)
 * @param bit Bit number (0-31)
 * @return Bit-band alias address
 */
#define BITBAND_SRAM_ADDR(addr, bit) \
    (((((uint32_t)(addr)) - BITBAND_SRAM_BASE) * 32) + ((uint32_t)(bit) * 4) + BITBAND_SRAM_ALIAS_BASE)

/**
 * @brief Convert Peripheral address to bit-band alias address
 * 将外设地址转换为位带别名地址
 * @param addr Byte address in peripheral bit-band region (0x40000000-0x400FFFFF)
 * @param bit Bit number (0-31)
 * @return Bit-band alias address
 */
#define BITBAND_PERIPH_ADDR(addr, bit) \
    (((((uint32_t)(addr)) - BITBAND_PERIPH_BASE) * 32) + ((uint32_t)(bit) * 4) + BITBAND_PERIPH_ALIAS_BASE)

/**
 * @brief Bit-band access macro for SRAM
 * SRAM 位带访问宏
 * @param addr Byte address in SRAM bit-band region
 * @param bit Bit number (0-31)
 * @return Pointer to bit-band alias word
 */
#define BITBAND_SRAM_PTR(addr, bit) \
    ((volatile uint32_t *)BITBAND_SRAM_ADDR(addr, bit))

/**
 * @brief Bit-band access macro for Peripheral
 * 外设位带访问宏
 * @param addr Byte address in peripheral bit-band region
 * @param bit Bit number (0-31)
 * @return Pointer to bit-band alias word
 */
#define BITBAND_PERIPH_PTR(addr, bit) \
    ((volatile uint32_t *)BITBAND_PERIPH_ADDR(addr, bit))

/**
 * @brief Set bit using bit-banding (SRAM)
 * 使用位带设置位 (SRAM)
 */
#define BITBAND_SRAM_SET(addr, bit) \
    (*BITBAND_SRAM_PTR(addr, bit) = 1)

/**
 * @brief Clear bit using bit-banding (SRAM)
 * 使用位带清除位 (SRAM)
 */
#define BITBAND_SRAM_CLR(addr, bit) \
    (*BITBAND_SRAM_PTR(addr, bit) = 0)

/**
 * @brief Read bit using bit-banding (SRAM)
 * 使用位带读取位 (SRAM)
 */
#define BITBAND_SRAM_GET(addr, bit) \
    (*BITBAND_SRAM_PTR(addr, bit))

/**
 * @brief Set bit using bit-banding (Peripheral)
 * 使用位带设置位 (外设)
 */
#define BITBAND_PERIPH_SET(addr, bit) \
    (*BITBAND_PERIPH_PTR(addr, bit) = 1)

/**
 * @brief Clear bit using bit-banding (Peripheral)
 * 使用位带清除位 (外设)
 */
#define BITBAND_PERIPH_CLR(addr, bit) \
    (*BITBAND_PERIPH_PTR(addr, bit) = 0)

/**
 * @brief Read bit using bit-banding (Peripheral)
 * 使用位带读取位 (外设)
 */
#define BITBAND_PERIPH_GET(addr, bit) \
    (*BITBAND_PERIPH_PTR(addr, bit))

/* ============================================================================
 * Cortex-M4 Instruction Set Features
 * Cortex-M4 指令集特性
 * ============================================================================ */

/**
 * @brief Cortex-M4 supports DSP instructions
 * Cortex-M4 支持 DSP 指令
 */
#define __CM4_DSP_INSTRUCTIONS      1

/**
 * @brief Cortex-M4 supports SIMD instructions
 * Cortex-M4 支持 SIMD 指令
 */
#define __CM4_SIMD_INSTRUCTIONS     1

/**
 * @brief Cortex-M4 supports saturating instructions
 * Cortex-M4 支持饱和指令
 */
#define __CM4_SAT_INSTRUCTIONS      1

/**
 * @brief Cortex-M4 supports exclusive access instructions
 * Cortex-M4 支持独占访问指令
 */
#define __CM4_EXCLUSIVE_ACCESS      1

/* ============================================================================
 * Cortex-M4 FPU Configuration
 * Cortex-M4 FPU 配置
 * ============================================================================ */

#if (__FPU_PRESENT == 1)
/**
 * @brief FPU Type - FPv4-SP
 * FPU 类型 - FPv4-SP
 */
#define __FPU_TYPE                  4U

/**
 * @brief FPU Double Precision Support
 * FPU 双精度支持
 */
#define __FPU_HAS_DOUBLE_PRECISION  0U

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
 * Cortex-M4 Cache and Memory Attributes
 * Cortex-M4 缓存和内存属性
 * ============================================================================ */

/**
 * @brief Cortex-M4 does not have cache
 * Cortex-M4 没有缓存
 */
#define __CM4_CACHE_PRESENT         0U

/**
 * @brief Cortex-M4 Write Buffer
 * Cortex-M4 写缓冲
 */
#define __CM4_WRITE_BUFFER          1U

/* ============================================================================
 * Cortex-M4 Revision Information
 * Cortex-M4 版本信息
 * ============================================================================ */

/**
 * @brief Cortex-M4 Revision
 * Cortex-M4 版本
 */
#define __CM4_REV                   0x0001U

/**
 * @brief Cortex-M4 Variant
 * Cortex-M4 变体
 */
#define __CM4_VARIANT               0x00U

/**
 * @brief Cortex-M4 Implementer
 * Cortex-M4 实现者 (ARM)
 */
#define __CM4_IMPLEMENTER           0x41U  /* 'A' = ARM */

/* ============================================================================
 * Include ARMv7-M Core Headers
 * 包含 ARMv7-M 核心头文件
 * ============================================================================ */

#include "../armv7-m.h"

#ifdef __cplusplus
}
#endif

#endif /* __CORE_CM4_H__ */
