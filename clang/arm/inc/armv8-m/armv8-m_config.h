/*
 * ARM Architecture - ARMv8-M Configuration
 *
 * ============================================================================
 * File: armv8m_config.h
 * Description: ARMv8-M architecture configuration macros
 * 描述: ARMv8-M 架构配置宏定义
 *
 * This file provides configuration options for ARMv8-M architecture features.
 * Modify these definitions based on your specific processor implementation.
 * 本文件提供 ARMv8-M 架构功能的配置选项。根据您的具体处理器实现修改这些定义。
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual (DDI0553B.z)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V8M_CONFIG_H__
#define __ARCH_ARM_V8M_CONFIG_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * ARMv8-M Architecture Version Configuration
 * ARMv8-M 架构版本配置
 * ============================================================================
 */

/**
 * ARMv8-M Architecture Identifier
 * ARMv8-M 架构标识符
 */
#define __ARM_ARCH_V8M__              1

/**
 * ARMv8-M Mainline (1) or Baseline (0)
 * ARMv8-M 主线 (1) 或基线 (0)
 * Mainline supports all features including TrustZone
 * 主线支持包括 TrustZone 在内的所有功能
 */
#ifndef __ARM_ARCH_V8M_MAINLINE__
#define __ARM_ARCH_V8M_MAINLINE__     1
#endif

/**
 * ARMv8.1-M Architecture Extension
 * ARMv8.1-M 架构扩展
 * Adds MVE, Loops, Branch Future, etc.
 * 添加 MVE、循环、分支未来等功能
 */
#ifndef __ARM_ARCH_V8_1M__
#define __ARM_ARCH_V8_1M__            1
#endif

/*
 * ============================================================================
 * Core Features Configuration
 * 核心功能配置
 * ============================================================================
 */

/**
 * MPU Present Flag: 1 = MPU is present
 * MPU 存在标志: 1 = MPU 存在
 */
#ifndef __MPU_PRESENT
#define __MPU_PRESENT                 1U
#endif

/**
 * Number of MPU Regions (0-16)
 * MPU 区域数量 (0-16)
 */
#ifndef __MPU_REGION_NUM
#define __MPU_REGION_NUM              8U
#endif

/**
 * VTOR Present Flag: 1 = Vector Table Offset Register is present
 * VTOR 存在标志: 1 = 向量表偏移寄存器存在
 */
#ifndef __VTOR_PRESENT
#define __VTOR_PRESENT                1U
#endif

/**
 * Number of Priority Bits: 3-8 bits for priority
 * 优先级位数: 3-8 位优先级
 */
#ifndef __NVIC_PRIO_BITS
#define __NVIC_PRIO_BITS              8U
#endif

/**
 * Number of interrupts supported (1-480)
 * 支持的中断数量 (1-480)
 */
#ifndef __ARM_NUM_INTERRUPTS
#define __ARM_NUM_INTERRUPTS          256U
#endif

/**
 * Vendor SysTick Config: 0 = Use standard implementation
 * 供应商 SysTick 配置: 0 = 使用标准实现
 */
#ifndef __Vendor_SysTickConfig
#define __Vendor_SysTickConfig        0U
#endif

/*
 * ============================================================================
 * Floating-Point Unit (FPU) Configuration
 * 浮点单元 (FPU) 配置
 * ============================================================================
 */

/**
 * FPU Present: 0 = No FPU, 1 = FPU is present
 * FPU 存在: 0 = 无 FPU, 1 = FPU 存在
 */
#ifndef __FPU_PRESENT
#define __FPU_PRESENT                 1U
#endif

/**
 * FPU Double Precision: 0 = Single precision only, 1 = Double precision supported
 * FPU 双精度: 0 = 仅单精度, 1 = 支持双精度
 */
#ifndef __FPU_DP
#define __FPU_DP                      0U
#endif

/**
 * FPU Architecture Version
 * FPU 架构版本
 * 0 = FPv5 with single precision
 * 1 = FPv5 with single and double precision
 */
#ifndef __FPU_ARCH
#define __FPU_ARCH                    0U
#endif

/*
 * ============================================================================
 * MVE (Helium) Vector Extension Configuration
 * MVE (Helium) 向量扩展配置
 * ============================================================================
 */

/**
 * MVE Present: 0 = No MVE, 1 = MVE is present
 * MVE 存在: 0 = 无 MVE, 1 = MVE 存在
 */
#ifndef __MVE_PRESENT
#define __MVE_PRESENT                 1U
#endif

/**
 * MVE Floating-Point Support
 * MVE 浮点支持
 * 0 = Integer MVE only, 1 = MVE with floating-point
 */
#ifndef __MVE_FP_PRESENT
#define __MVE_FP_PRESENT              1U
#endif

/*
 * ============================================================================
 * TrustZone Security Extension Configuration
 * TrustZone 安全扩展配置
 * ============================================================================
 */

/**
 * TrustZone Present: 0 = No TrustZone, 1 = TrustZone/SAU is present
 * TrustZone 存在: 0 = 无 TrustZone, 1 = TrustZone/SAU 存在
 * Only available on ARMv8-M Mainline
 * 仅在 ARMv8-M Mainline 上可用
 */
#ifndef __TZ_PRESENT
#define __TZ_PRESENT                  1U
#endif

/**
 * Number of SAU regions supported (0-8)
 * 支持的 SAU 区域数量 (0-8)
 */
#ifndef __SAU_REGIONS_NUM
#define __SAU_REGIONS_NUM             8U
#endif

/**
 * Number of IDAU regions (implementation defined)
 * IDAU 区域数量 (实现定义)
 */
#ifndef __IDAU_REGIONS_NUM
#define __IDAU_REGIONS_NUM            0U
#endif

/*
 * ============================================================================
 * Performance Monitor Unit (PMU) Configuration
 * 性能监视单元 (PMU) 配置
 * ============================================================================
 */

/**
 * PMU Present: 0 = No PMU, 1 = PMU is present
 * PMU 存在: 0 = 无 PMU, 1 = PMU 存在
 */
#ifndef __PMU_PRESENT
#define __PMU_PRESENT                 1U
#endif

/**
 * Number of PMU Event Counters (0-31)
 * PMU 事件计数器数量 (0-31)
 */
#ifndef __PMU_NUM_COUNTERS
#define __PMU_NUM_COUNTERS            8U
#endif

/*
 * ============================================================================
 * DSP Extension Configuration
 * DSP 扩展配置
 * ============================================================================
 */

/**
 * DSP Extension Present: 0 = No DSP, 1 = DSP extension is present
 * DSP 扩展存在: 0 = 无 DSP, 1 = DSP 扩展存在
 */
#ifndef __DSP_PRESENT
#define __DSP_PRESENT                 1U
#endif

/*
 * ============================================================================
 * Debug and Trace Configuration
 * 调试和跟踪配置
 * ============================================================================
 */

/**
 * Debug Present: 0 = No debug, 1 = Debug is present
 * 调试存在: 0 = 无调试, 1 = 调试存在
 */
#ifndef __DEBUG_PRESENT
#define __DEBUG_PRESENT               1U
#endif

/**
 * DWT Present: 0 = No DWT, 1 = Data Watchpoint and Trace is present
 * DWT 存在: 0 = 无 DWT, 1 = 数据观察点和跟踪存在
 */
#ifndef __DWT_PRESENT
#define __DWT_PRESENT                 1U
#endif

/**
 * Number of DWT Comparators (0-15)
 * DWT 比较器数量 (0-15)
 */
#ifndef __DWT_NUM_COMPARATORS
#define __DWT_NUM_COMPARATORS         4U
#endif

/**
 * ITM Present: 0 = No ITM, 1 = Instrumentation Trace Macrocell is present
 * ITM 存在: 0 = 无 ITM, 1 = 仪表跟踪宏单元存在
 */
#ifndef __ITM_PRESENT
#define __ITM_PRESENT                 1U
#endif

/**
 * Number of ITM Stimulus Ports (1-256)
 * ITM 刺激端口数量 (1-256)
 */
#ifndef __ITM_NUM_STIM_PORTS
#define __ITM_NUM_STIM_PORTS          32U
#endif

/**
 * ETM Present: 0 = No ETM, 1 = Embedded Trace Macrocell is present
 * ETM 存在: 0 = 无 ETM, 1 = 嵌入式跟踪宏单元存在
 */
#ifndef __ETM_PRESENT
#define __ETM_PRESENT                 0U
#endif

/**
 * TPIU Present: 0 = No TPIU, 1 = Trace Port Interface Unit is present
 * TPIU 存在: 0 = 无 TPIU, 1 = 跟踪端口接口单元存在
 */
#ifndef __TPIU_PRESENT
#define __TPIU_PRESENT                0U
#endif

/**
 * Number of breakpoints supported
 * 支持的断点数量
 */
#ifndef __NUM_BRP
#define __NUM_BRP                     8U
#endif

/**
 * Number of watchpoints supported
 * 支持的观察点数量
 */
#ifndef __NUM_WRP
#define __NUM_WRP                     4U
#endif

/*
 * ============================================================================
 * PACBTI Extension Configuration
 * 指针认证和分支目标识别扩展配置
 * ============================================================================
 */

/**
 * PACBTI Present: 0 = No PACBTI, 1 = PACBTI is present
 * PACBTI 存在: 0 = 无 PACBTI, 1 = PACBTI 存在
 */
#ifndef __PACBTI_PRESENT
#define __PACBTI_PRESENT              1U
#endif

/*
 * ============================================================================
 * RAS Extension Configuration
 * RAS 扩展配置
 * ============================================================================
 */

/**
 * RAS Present: 0 = No RAS, 1 = RAS Extension is present
 * RAS 存在: 0 = 无 RAS, 1 = RAS 扩展存在
 */
#ifndef __RAS_PRESENT
#define __RAS_PRESENT                 0U
#endif

/*
 * ============================================================================
 * CDE (Custom Datapath Extension) Configuration
 * CDE (自定义数据路径扩展) 配置
 * ============================================================================
 */

/**
 * CDE Present: 0 = No CDE, 1 = CDE is present
 * CDE 存在: 0 = 无 CDE, 1 = CDE 存在
 */
#ifndef __CDE_PRESENT
#define __CDE_PRESENT                 0U
#endif

/**
 * Number of CDE Coprocessors (0-4)
 * CDE 协处理器数量 (0-4)
 */
#ifndef __CDE_NUM_COPS
#define __CDE_NUM_COPS                0U
#endif

/*
 * ============================================================================
 * Cache Configuration
 * 缓存配置
 * ============================================================================
 */

/**
 * I-Cache Present: 0 = No I-Cache, 1 = Instruction Cache is present
 * I-Cache 存在: 0 = 无 I-Cache, 1 = 指令缓存存在
 */
#ifndef __ICACHE_PRESENT
#define __ICACHE_PRESENT              0U
#endif

/**
 * D-Cache Present: 0 = No D-Cache, 1 = Data Cache is present
 * D-Cache 存在: 0 = 无 D-Cache, 1 = 数据缓存存在
 */
#ifndef __DCACHE_PRESENT
#define __DCACHE_PRESENT              0U
#endif

/*
 * ============================================================================
 * Tightly-Coupled Memory (TCM) Configuration
 * 紧耦合内存 (TCM) 配置
 * ============================================================================
 */

/**
 * ITCM Present: 0 = No ITCM, 1 = Instruction TCM is present
 * ITCM 存在: 0 = 无 ITCM, 1 = 指令 TCM 存在
 */
#ifndef __ITCM_PRESENT
#define __ITCM_PRESENT                0U
#endif

/**
 * DTCM Present: 0 = No DTCM, 1 = Data TCM is present
 * DTCM 存在: 0 = 无 DTCM, 1 = 数据 TCM 存在
 */
#ifndef __DTCM_PRESENT
#define __DTCM_PRESENT                0U
#endif

/*
 * ============================================================================
 * Architecture Feature Checks
 * 架构功能检查
 * ============================================================================
 */

/**
 * Check if TrustZone is available
 * 检查 TrustZone 是否可用
 */
#if (__TZ_PRESENT == 1) && (__ARM_ARCH_V8M_MAINLINE__ == 0)
#error "TrustZone is only available on ARMv8-M Mainline"
#endif

/**
 * Check if MVE is available
 * 检查 MVE 是否可用
 */
#if (__MVE_PRESENT == 1) && (__ARM_ARCH_V8_1M__ == 0)
#error "MVE requires ARMv8.1-M architecture"
#endif

/**
 * Check if PACBTI is available
 * 检查 PACBTI 是否可用
 */
#if (__PACBTI_PRESENT == 1) && (__ARM_ARCH_V8M_MAINLINE__ == 0)
#error "PACBTI is only available on ARMv8-M Mainline"
#endif

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V8M_CONFIG_H__ */
