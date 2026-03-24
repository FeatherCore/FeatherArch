/*
 * ARM Architecture - Cortex-M4 Top-Level Header
 *
 * ============================================================================
 * File: cm4.h
 * Description: Cortex-M4 top-level header file
 * 描述: Cortex-M4 顶层头文件
 *
 * This header includes all Cortex-M4 specific components:
 * - Core definitions and configuration
 * - Core registers (APSR, IPSR, EPSR, PRIMASK, FAULTMASK, BASEPRI, CONTROL)
 * - Memory model (memory map, bit-banding, memory barriers)
 * - DSP extension functions
 * - FPU (FPv4-SP) functions
 * - Initialization and system control functions
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 1 Introduction (page 1-1)
 *   - Chapter 2 The Cortex-M4 Processor (page 2-1)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_H__
#define __CM4_H__

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================================
 * Cortex-M4 Core Configuration
 * Cortex-M4 核心配置
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 1.1 (page 1-2)
 * ============================================================================ */

#include "core_cm4.h"

/* ============================================================================
 * Cortex-M4 CMSIS Intrinsic Functions
 * Cortex-M4 CMSIS 内联函数
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.2 (page 3-9)
 * ============================================================================ */

#include "cm4_cmsis.h"

/* ============================================================================
 * Cortex-M4 Condition Code Definitions
 * Cortex-M4 条件码定义
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.3.7 (page 3-18)
 * ============================================================================ */

#include "cm4_condition.h"

/* ============================================================================
 * Cortex-M4 Core Registers
 * Cortex-M4 核心寄存器
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.3 (page 2-3)
 * ============================================================================ */

#include "cm4_core.h"

/* ============================================================================
 * Cortex-M4 Memory Model
 * Cortex-M4 内存模型
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2 (page 2-10)
 * ============================================================================ */

#include "cm4_memory.h"

/* ============================================================================
 * Cortex-M4 Initialization and System Control
 * Cortex-M4 初始化和系统控制
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1 (page 2-2)
 * ============================================================================ */

#include "cm4_init.h"

/* ============================================================================
 * Cortex-M4 NVIC (Nested Vectored Interrupt Controller)
 * Cortex-M4 NVIC (嵌套向量中断控制器)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 * ============================================================================ */

#include "cm4_nvic.h"

/* ============================================================================
 * Cortex-M4 SCB (System Control Block)
 * Cortex-M4 SCB (系统控制块)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3 (page 4-10)
 * ============================================================================ */

#include "cm4_scb.h"

/* ============================================================================
 * Cortex-M4 SysTick Timer
 * Cortex-M4 SysTick 定时器
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4 (page 4-32)
 * ============================================================================ */

#include "cm4_systick.h"

/* ============================================================================
 * Cortex-M4 MPU (Memory Protection Unit)
 * Cortex-M4 MPU (内存保护单元)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5 (page 4-37)
 * ============================================================================ */

#if (__MPU_PRESENT == 1)
#include "cm4_mpu.h"
#endif

/* ============================================================================
 * Cortex-M4 DSP Extension
 * Cortex-M4 DSP 扩展
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 1.1 (page 1-2)
 * ============================================================================ */

#include "cm4_dsp.h"

/* ============================================================================
 * Cortex-M4 FPU Extension (FPv4-SP)
 * Cortex-M4 FPU 扩展 (FPv4-SP)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 1.1 (page 1-2)
 * ============================================================================ */

#if (__FPU_PRESENT == 1)
#include "cm4_fpu.h"
#endif

/* ============================================================================
 * Cortex-M4 Debug Registers
 * Cortex-M4 调试寄存器
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 8 (page 8-72)
 * ============================================================================ */

#include "cm4_debug.h"

/* ============================================================================
 * Cortex-M4 DWT (Data Watchpoint and Trace)
 * Cortex-M4 DWT (数据观察点和跟踪)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 9 (page 9-83)
 * ============================================================================ */

#include "cm4_dwt.h"

/* ============================================================================
 * Cortex-M4 ITM (Instrumentation Trace Macrocell)
 * Cortex-M4 ITM (仪器跟踪宏单元)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 10 (page 10-87)
 * ============================================================================ */

#include "cm4_itm.h"

/* ============================================================================
 * Cortex-M4 TPIU (Trace Port Interface Unit)
 * Cortex-M4 TPIU (跟踪端口接口单元)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 11 (page 11-91)
 * ============================================================================ */

#include "cm4_tpiu.h"

#ifdef __cplusplus
}
#endif

#endif /* __CM4_H__ */
