/*
 * ARM Architecture - ARMv7-M Support
 *
 * ============================================================================
 * File: armv7-m.h
 * Description: ARMv7-M architecture main header file
 * 描述: ARMv7-M 架构主头文件
 *
 * This is the main header file for ARMv7-M architecture support.
 * It includes all modular header files for different ARMv7-M components.
 * 这是 ARMv7-M 架构支持的主头文件，包含所有模块化头文件。
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Part A: Application Level Architecture
 *   - Part B: System Level Architecture
 *   - Part C: Debug Architecture
 *
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 ARM Architecture Team. All rights reserved.
 */

#ifndef __ARCH_ARM_V7M_H__
#define __ARCH_ARM_V7M_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * Configuration
 * 配置
 * ============================================================================
 */
#include "armv7-m_config.h"

/*
 * ============================================================================
 * Core Components (Always Included)
 * 核心组件 (始终包含)
 * ============================================================================
 */

/**
 * Core Registers and Basic Instructions
 * 核心寄存器和基本指令
 * Reference: Chapter B1.4 - Registers
 */
#include "armv7-m_core.h"

/**
 * NVIC - Nested Vectored Interrupt Controller
 * NVIC - 嵌套向量中断控制器
 * Reference: Chapter B3.4 - Nested Vectored Interrupt Controller, NVIC
 */
#include "armv7-m_nvic.h"

/**
 * MPU - Memory Protection Unit (PMSAv7)
 * MPU - 内存保护单元 (PMSAv7)
 * Reference: Chapter B3.5 - Protected Memory System Architecture, PMSAv7
 */
#if (__MPU_PRESENT == 1)
#include "armv7-m_mpu.h"
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
 * Reference: Chapter B3.3 - The system timer, SysTick
 */
#if (__Vendor_SysTickConfig == 0)
#include "armv7-m_systick.h"
#endif

/**
 * FPU - Floating-Point Unit
 * FPU - 浮点单元
 * Reference: Chapter A2.5 - The optional Floating-point Extension
 */
#if (__FPU_PRESENT == 1)
#include "armv7-m_fpu.h"
#endif

/**
 * Debug and Trace Components
 * 调试和跟踪组件
 * Reference: Chapter C1 - Armv7-M Debug
 */
#if (__DEBUG_PRESENT == 1)
#include "armv7-m_debug.h"
#endif

/**
 * TPIU - Trace Port Interface Unit
 * TPIU - 跟踪端口接口单元
 * Reference: Chapter C1.10 - Trace Port Interface Unit
 */
#if (__TPIU_PRESENT == 1)
#include "armv7-m_tpiu.h"
#endif

/*
 * ============================================================================
 * Version Information
 * 版本信息
 * ============================================================================
 */

/**
 * ARMv7-M Architecture Version
 * ARMv7-M 架构版本
 */
#define ARM_V7M_ARCH_VERSION_MAJOR    1
#define ARM_V7M_ARCH_VERSION_MINOR    0
#define ARM_V7M_ARCH_VERSION_PATCH    0

/**
 * Get version string
 * 获取版本字符串
 */
#define ARM_V7M_ARCH_VERSION_STRING   "1.0.0"

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_H__ */
