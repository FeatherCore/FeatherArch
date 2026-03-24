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
 *   - Chapter 1: Introduction
 *   - Chapter 2: The Cortex-M4 Processor
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
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4 (page 4-1)
 * ============================================================================ */

#include "cm4_init.h"

/* ============================================================================
 * Cortex-M4 DSP Extension
 * Cortex-M4 DSP 扩展
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.4 (page 3-10)
 * ============================================================================ */

#include "cm4_dsp.h"

/* ============================================================================
 * Cortex-M4 FPU Extension (FPv4-SP)
 * Cortex-M4 FPU 扩展 (FPv4-SP)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.3 (page 3-8)
 * ============================================================================ */

#if (__FPU_PRESENT == 1)
#include "cm4_fpu.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CM4_H__ */
