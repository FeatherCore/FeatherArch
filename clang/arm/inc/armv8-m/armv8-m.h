/*
 * ARM Architecture - ARMv8-M Support
 *
 * ============================================================================
 * File: armv8m.h
 * Description: ARMv8-M architecture main header file
 * 描述: ARMv8-M 架构主头文件
 *
 * This is the main header file for ARMv8-M architecture support.
 * It includes all modular header files for different ARMv8-M components.
 * 这是 ARMv8-M 架构支持的主头文件，包含所有模块化头文件。
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual (DDI0553B.z)
 *   - Part A: Architecture Introduction and Overview
 *   - Part B: Architecture Rules
 *   - Part C: Instruction Set Specification
 *   - Part D: Register and Payload Specification
 *   - Part E: Pseudocode Specification
 *   - Part F: ITM and DWT Packet Protocol Specification
 *
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 ARM Architecture Team. All rights reserved.
 */

#ifndef __ARCH_ARM_V8M_H__
#define __ARCH_ARM_V8M_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * Configuration
 * 配置
 * ============================================================================
 */
#include "armv8-m_config.h"

/*
 * ============================================================================
 * Core Components (Always Included)
 * 核心组件 (始终包含)
 * ============================================================================
 */

/**
 * Core Registers and Basic Instructions
 * 核心寄存器和基本指令
 * Reference: Chapter B3 - Programmers' Model
 */
#include "armv8-m_core.h"

/**
 * NVIC - Nested Vectored Interrupt Controller
 * NVIC - 嵌套向量中断控制器
 * Reference: Chapter B12 - Nested Vectored Interrupt Controller
 */
#include "armv8-m_nvic.h"

/**
 * MPU - Memory Protection Unit
 * MPU - 内存保护单元
 * Reference: Chapter B10 - The Armv8-M Protected Memory System Architecture
 */
#if (__MPU_PRESENT == 1)
#include "armv8-m_mpu.h"
#endif

/*
 * ============================================================================
 * System Components (Optional)
 * 系统组件 (可选)
 * ============================================================================
 */

/**
 * SysTick - System Timer
 * SysTick - 系统定时器
 * Reference: Chapter B11 - The System Timer, SysTick
 */
#if (__Vendor_SysTickConfig == 0)
#include "armv8-m_systick.h"
#endif

/**
 * FPU - Floating-Point Unit
 * FPU - 浮点单元
 * Reference: Chapter B4 - Floating-point Support
 */
#if (__FPU_PRESENT == 1)
#include "armv8-m_fpu.h"
#endif

/**
 * MVE - M-Profile Vector Extension (Helium)
 * MVE - M-Profile 向量扩展 (Helium)
 * Reference: Chapter B5 - Vector Extension
 */
#if (__MVE_PRESENT == 1)
#include "armv8-m_mve.h"
#endif

/**
 * TrustZone Security Extension
 * TrustZone 安全扩展
 * Reference: Chapter B10 - The Armv8-M Protected Memory System Architecture
 */
#if (__TZ_PRESENT == 1)
#include "armv8-m_trustzone.h"
#endif

/**
 * PMU - Performance Monitor Unit
 * PMU - 性能监视单元
 * Reference: Chapter B15 - The Performance Monitors Extension
 */
#if (__PMU_PRESENT == 1)
#include "armv8-m_pmu.h"
#endif

/**
 * Debug and Trace Components
 * 调试和跟踪组件
 * Reference: Chapter B13 - Debug, Chapter B14 - Debug and Trace Components
 */
#if (__DEBUG_PRESENT == 1)
#include "armv8-m_debug.h"
#endif

/**
 * TPIU - Trace Port Interface Unit
 * TPIU - 跟踪端口接口单元
 * Reference: Chapter D1.1.31 Trace Port Interface Unit
 */
#if (__TPIU_PRESENT == 1)
#include "armv8-m_tpiu.h"
#endif

/**
 * PACBTI - Pointer Authentication and Branch Target Identification
 * PACBTI - 指针认证和分支目标识别
 * Reference: Chapter B6 - Pointer authentication and branch target identification Extension
 */
#if (__PACBTI_PRESENT == 1)
#include "armv8-m_pacbti.h"
#endif

/**
 * RAS - Reliability, Availability, and Serviceability Extension
 * RAS - 可靠性、可用性和可维护性扩展
 * Reference: Chapter B16 - Reliability, Availability, and Serviceability (RAS) Extension
 */
#if (__RAS_PRESENT == 1)
#include "armv8-m_ras.h"
#endif

/**
 * CDE - Custom Datapath Extension
 * CDE - 自定义数据路径扩展
 * Reference: Chapter A1.4.1 - CDE - The Custom Datapath Extension
 */
#if (__CDE_PRESENT == 1)
#include "armv8-m_cde.h"
#endif

/**
 * Cache Maintenance Operations
 * 缓存维护操作
 * Reference: Chapter B3 - Programmers' Model (Cache maintenance operations)
 */
#if (__ICACHE_PRESENT == 1) || (__DCACHE_PRESENT == 1)
#include "armv8-m_cache.h"
#endif



/*
 * ============================================================================
 * Version Information
 * 版本信息
 * ============================================================================
 */

/**
 * ARMv8-M Architecture Version
 * ARMv8-M 架构版本
 */
#define ARM_V8M_ARCH_VERSION_MAJOR    1
#define ARM_V8M_ARCH_VERSION_MINOR    0
#define ARM_V8M_ARCH_VERSION_PATCH    0

/**
 * Get version string
 * 获取版本字符串
 */
#define ARM_V8M_ARCH_VERSION_STRING   "1.0.0"

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V8M_H__ */
