/*
 * ARM Architecture - Cortex-M7 Top-Level Header
 *
 * ============================================================================
 * File: cm7.h
 * Description: Cortex-M7 top-level header file
 * 描述: Cortex-M7 顶层头文件
 *
 * This header includes all Cortex-M7 specific components:
 * - Core definitions and configuration
 * - Cache maintenance operations
 * - Tightly-Coupled Memory (TCM) control
 * - Control registers (ACTLR, CACR, ABFSR, etc.)
 * - Initialization and system control functions
 * - FPU (FPv5) functions
 *
 * @reference Arm Cortex-M7 Processor Technical Reference Manual
 *   - Section 1.1 About the Cortex-M7 processor
 *   - Section 3.2 Register summary, Table 3-1 System control registers
 *
 * @reference Arm Cortex-M7 Devices Generic User Guide
 *   - Section 1.1 About the Cortex-M7 processor and core peripherals
 *   - Section 4.8 Cache maintenance operations
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM7_H__
#define __CM7_H__

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================================
 * Cortex-M7 Core Configuration
 * Reference: Arm Cortex-M7 Processor Technical Reference Manual, Section 1.1
 * ============================================================================ */

#include "core_cm7.h"

/* ============================================================================
 * Cortex-M7 Initialization and System Control
 * Cortex-M7 初始化和系统控制
 * ============================================================================ */

#include "cm7_init.h"

/* ============================================================================
 * Cortex-M7 Cache Operations
 * Reference: Arm Cortex-M7 Devices Generic User Guide, Section 4.8
 * Reference: Arm Cortex-M7 Processor Technical Reference Manual, Section 3.3
 * ============================================================================ */

#if (__ICACHE_PRESENT == 1) || (__DCACHE_PRESENT == 1)
#include "cm7_cache.h"
#endif

/* ============================================================================
 * Cortex-M7 Tightly-Coupled Memory (TCM)
 * Reference: Arm Cortex-M7 Processor Technical Reference Manual, Section 3.3.6
 * ============================================================================ */

#if (__ITCM_PRESENT == 1) || (__DTCM_PRESENT == 1)
#include "cm7_tcm.h"
#endif

/* ============================================================================
 * Cortex-M7 Control Registers
 * Reference: Arm Cortex-M7 Processor Technical Reference Manual, Section 3.3
 *   - ACTLR: Auxiliary Control Register (Section 3.3.1)
 *   - CACR: L1 Cache Control Register (Section 3.3.8)
 *   - ABFSR: Auxiliary Bus Fault Status Register (Section 3.3.9)
 *   - IEBR0/1: Instruction Error Bank Registers (Section 3.3.10)
 *   - DEBR0/1: Data Error Bank Registers (Section 3.3.11)
 * ============================================================================ */

#include "cm7_ctrl.h"

/* ============================================================================
 * Cortex-M7 FPU Extension (FPv5)
 * Cortex-M7 FPU 扩展 (FPv5)
 * ============================================================================ */

#if (__FPU_PRESENT == 1)
#include "cm7_fpu.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CM7_H__ */
