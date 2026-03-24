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
 * - DSP extension functions
 * - FPU (FPv4-SP) functions
 *
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual
 *            Arm(R) Cortex-M4 Devices Generic User Guide
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
 * ============================================================================ */

#include "core_cm4.h"

/* ============================================================================
 * Cortex-M4 DSP Extension
 * Cortex-M4 DSP 扩展
 * ============================================================================ */

#include "cm4_dsp.h"

/* ============================================================================
 * Cortex-M4 FPU Extension (FPv4-SP)
 * Cortex-M4 FPU 扩展 (FPv4-SP)
 * ============================================================================ */

#if (__FPU_PRESENT == 1)
#include "cm4_fpu.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CM4_H__ */
