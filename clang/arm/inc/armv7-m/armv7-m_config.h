/*
 * ARM Architecture - ARMv7-M Configuration
 *
 * ============================================================================
 * File: armv7-m_config.h
 * Description: ARMv7-M architecture configuration macros
 * 描述: ARMv7-M 架构配置宏定义
 *
 * This file provides configuration options for ARMv7-M architecture features.
 * Modify these definitions based on your specific processor implementation.
 * 本文件提供 ARMv7-M 架构功能的配置选项。根据您的具体处理器实现修改这些定义。
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_CONFIG_H__
#define __ARCH_ARM_V7M_CONFIG_H__

#include &lt;stdint.h&gt;

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * ARMv7-M Architecture Version Configuration
 * ARMv7-M 架构版本配置
 * ============================================================================
 */

/**
 * ARMv7-M Architecture Identifier
 * ARMv7-M 架构标识符
 * Reference: Chapter A1.2 - The Armv7-M architecture profile
 */
#define __ARM_ARCH_V7M__              1

/**
 * ARMv7-M Variant Identifier
 * ARMv7-M 变体标识符
 * ARMv7-M: Base profile
 * ARMv7E-M: With DSP extension
 */
#ifndef __ARM_ARCH_V7EM__
#define __ARM_ARCH_V7EM__             0
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
 * Reference: Chapter B3.5 - Protected Memory System Architecture, PMSAv7
 */
#ifndef __MPU_PRESENT
#define __MPU_PRESENT                 1U
#endif

/**
 * Number of MPU Regions (0-8)
 * MPU 区域数量 (0-8)
 * Reference: Chapter B3.5 - Protected Memory System Architecture, PMSAv7
 */
#ifndef __MPU_REGION_NUM
#define __MPU_REGION_NUM              8U
#endif

/**
 * VTOR Present Flag: 1 = Vector Table Offset Register is present
 * VTOR 存在标志: 1 = 向量表偏移寄存器存在
 * Reference: Chapter B3 - System Address Map
 */
#ifndef __VTOR_PRESENT
#define __VTOR_PRESENT                1U
#endif

/**
 * Number of Priority Bits: 3-8 bits for priority
 * 优先级位数: 3-8 位优先级
 * Reference: Chapter B3.4 - Nested Vectored Interrupt Controller, NVIC
 */
#ifndef __NVIC_PRIO_BITS
#define __NVIC_PRIO_BITS              4U
#endif

/**
 * Number of interrupts supported (1-240)
 * 支持的中断数量 (1-240)
 * Reference: Chapter B3.4 - Nested Vectored Interrupt Controller, NVIC
 */
#ifndef __ARM_NUM_INTERRUPTS
#define __ARM_NUM_INTERRUPTS          32U
#endif

/**
 * Vendor SysTick Config: 0 = Use standard implementation
 * 供应商 SysTick 配置: 0 = 使用标准实现
 * Reference: Chapter B3.3 - The system timer, SysTick
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
 * Reference: Chapter A2.5 - The optional Floating-point Extension
 */
#ifndef __FPU_PRESENT
#define __FPU_PRESENT                 0U
#endif

/**
 * FPU Double Precision: 0 = Single precision only (FPv4-SP), 1 = Double precision supported (FPv5)
 * FPU 双精度: 0 = 仅单精度 (FPv4-SP), 1 = 支持双精度 (FPv5)
 * Reference: Chapter A1.3 - Architecture extensions
 */
#ifndef __FPU_DP
#define __FPU_DP                      0U
#endif

/**
 * FPU Architecture Version
 * FPU 架构版本
 * 0 = FPv4-SP-D16-M (single precision only)
 * 1 = FPv5-SP-D16-M (single precision)
 * 2 = FPv5-D16-M (single and double precision)
 */
#ifndef __FPU_ARCH
#define __FPU_ARCH                    0U
#endif

/*
 * ============================================================================
 * DSP Extension Configuration
 * DSP 扩展配置
 * ============================================================================
 */

/**
 * DSP Extension Present: 0 = No DSP, 1 = DSP extension is present (ARMv7E-M)
 * DSP 扩展存在: 0 = 无 DSP, 1 = DSP 扩展存在 (ARMv7E-M)
 * Reference: Chapter A1.3 - Architecture extensions
 */
#ifndef __DSP_PRESENT
#define __DSP_PRESENT                 0U
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
 * Reference: Chapter C1 - Armv7-M Debug
 */
#ifndef __DEBUG_PRESENT
#define __DEBUG_PRESENT               1U
#endif

/**
 * DWT Present: 0 = No DWT, 1 = Data Watchpoint and Trace is present
 * DWT 存在: 0 = 无 DWT, 1 = 数据观察点和跟踪存在
 * Reference: Chapter C1.8 - The Data Watchpoint and Trace unit
 */
#ifndef __DWT_PRESENT
#define __DWT_PRESENT                 1U
#endif

/**
 * Number of DWT Comparators (0-4)
 * DWT 比较器数量 (0-4)
 * Reference: Chapter C1.8 - The Data Watchpoint and Trace unit
 */
#ifndef __DWT_NUM_COMPARATORS
#define __DWT_NUM_COMPARATORS         4U
#endif

/**
 * ITM Present: 0 = No ITM, 1 = Instrumentation Trace Macrocell is present
 * ITM 存在: 0 = 无 ITM, 1 = 仪表跟踪宏单元存在
 * Reference: Chapter C1.7 - The Instrumentation Trace Macrocell
 */
#ifndef __ITM_PRESENT
#define __ITM_PRESENT                 1U
#endif

/**
 * Number of ITM Stimulus Ports (1-32)
 * ITM 刺激端口数量 (1-32)
 * Reference: Chapter C1.7 - The Instrumentation Trace Macrocell
 */
#ifndef __ITM_NUM_STIM_PORTS
#define __ITM_NUM_STIM_PORTS          32U
#endif

/**
 * ETM Present: 0 = No ETM, 1 = Embedded Trace Macrocell is present
 * ETM 存在: 0 = 无 ETM, 1 = 嵌入式跟踪宏单元存在
 * Reference: Chapter C1.9 - Embedded Trace Macrocell support
 */
#ifndef __ETM_PRESENT
#define __ETM_PRESENT                 0U
#endif

/**
 * TPIU Present: 0 = No TPIU, 1 = Trace Port Interface Unit is present
 * TPIU 存在: 0 = 无 TPIU, 1 = 跟踪端口接口单元存在
 * Reference: Chapter C1.10 - Trace Port Interface Unit
 */
#ifndef __TPIU_PRESENT
#define __TPIU_PRESENT                0U
#endif

/**
 * FPB Present: 0 = No FPB, 1 = Flash Patch and Breakpoint unit is present
 * FPB 存在: 0 = 无 FPB, 1 = Flash 补丁和断点单元存在
 * Reference: Chapter C1.11 - Flash Patch and Breakpoint unit
 */
#ifndef __FPB_PRESENT
#define __FPB_PRESENT                 1U
#endif

/**
 * Number of breakpoints supported
 * 支持的断点数量
 */
#ifndef __NUM_BRP
#define __NUM_BRP                     6U
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
 * Cache Configuration
 * 缓存配置
 * ============================================================================
 */

/**
 * I-Cache Present: 0 = No I-Cache, 1 = Instruction Cache is present
 * I-Cache 存在: 0 = 无 I-Cache, 1 = 指令缓存存在
 * Reference: Chapter A3.8 - Caches and memory hierarchy
 */
#ifndef __ICACHE_PRESENT
#define __ICACHE_PRESENT              0U
#endif

/**
 * D-Cache Present: 0 = No D-Cache, 1 = Data Cache is present
 * D-Cache 存在: 0 = 无 D-Cache, 1 = 数据缓存存在
 * Reference: Chapter A3.8 - Caches and memory hierarchy
 */
#ifndef __DCACHE_PRESENT
#define __DCACHE_PRESENT              0U
#endif

/*
 * ============================================================================
 * Architecture Feature Checks
 * 架构功能检查
 * ============================================================================
 */

/**
 * Check if DSP extension is available with ARMv7-M (requires ARMv7E-M)
 * 检查 ARMv7-M 是否支持 DSP 扩展 (需要 ARMv7E-M)
 */
#if (__DSP_PRESENT == 1) &amp;&amp; (__ARM_ARCH_V7EM__ == 0)
#error "DSP extension is only available on ARMv7E-M"
#endif

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_CONFIG_H__ */
