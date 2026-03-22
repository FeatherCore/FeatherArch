/*
 * ARM Cortex-M33 Core Peripheral Access Layer Implementation
 * ARM Cortex-M33 核心外设访问层实现
 *
 * ============================================================================
 * File: core_cm33.c
 * Description: ARM Cortex-M33 core peripheral access layer implementation
 * 描述: ARM Cortex-M33 核心外设访问层实现
 *
 * This file provides ARM Cortex-M33 specific implementation.
 * 本文件提供 ARM Cortex-M33 特定实现。
 *
 * Dependency Hierarchy / 依赖层次:
 *   core_cm33.c → core_cm33.h → armv8m.h → armv8m.c
 *   (This file) (Cortex-M33) (ARMv8-M)  (Implementation)
 *
 * Reference Documents / 参考文档:
 *   1. Arm® Cortex™-M33 Devices Generic User Guide (Document ID: 100235)
 *      - Chapter 2: The Cortex®-M33 Processor
 *      - Chapter 4: The Cortex®-M33 Peripherals
 *
 *   2. Arm® Cortex®-M33 Processor Technical Reference Manual (Document ID: 100230)
 *      - Chapter 1: Introduction
 *      - Chapter 2: Programmers Model
 *
 *   3. Arm-Cortex-M33-Processor-Datasheet-V2
 *      - Feature configuration options
 *
 * Cortex-M33 Features:
 *   - ARMv8-M Mainline architecture with Main Extension
 *   - 3-stage pipeline Harvard architecture
 *   - TrustZone Security Extension (optional)
 *   - Optional FPU (single precision only)
 *   - Optional DSP Extension (SIMD instructions)
 *
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 ARM Architecture Team. All rights reserved.
 */

#include "core_cm33.h"

/*
 * ============================================================================
 * Cortex-M33 Core ID Definitions
 * Cortex-M33 核心ID定义
 * Reference: Arm® Cortex®-M33 TRM Chapter 4.2 (CPUID)
 * 参考: Arm® Cortex®-M33 TRM 第 4.2 章 (CPUID)
 * ============================================================================
 */

/**
 * Cortex-M33 Revision
 * Cortex-M33 版本
 * r1p0: 0x0001
 */
#define __CM33_REV         0x0001U

/**
 * Cortex-M33 Processor number
 * Cortex-M33 处理器编号
 */
#define __CORTEX_M          33U

/**
 * Cortex-M33 CPUID Base Register Reset Value
 * Cortex-M33 CPUID 基址寄存器复位值
 * Reference: Arm® Cortex®-M33 TRM Section 1.9 (Product Revisions)
 * 参考: Arm® Cortex®-M33 TRM 第 1.9 节 (产品修订)
 * CPUID = 0x411FD210 for r1p0
 */
#define __CM33_CPUID       0x411FD210U

/*
 * ============================================================================
 * Initialization Functions
 * 初始化函数
 * ============================================================================
 */

/**
 * @brief Initialize Cortex-M33 core
 * @brief 初始化 Cortex-M33 核心
 *
 * This function initializes the Cortex-M33 core including:
 * 本函数初始化 Cortex-M33 核心包括:
 *   - FPU enable
 *   - MPU initialization
 *   - Memory barriers
 *
 * Reference: Arm® Cortex™-M33 Devices Generic User Guide and TRM
 * 参考: Arm® Cortex™-M33 GUG 和 TRM
 */
void Core_Init(void) {
    arch_armv8m_init();
}

/**
 * @brief Setup vector table for Cortex-M33
 * @brief 为 Cortex-M33 设置向量表
 *
 * Reference: Arm® Cortex™-M33 Devices Generic User Guide Chapter 4.2.18 (VTOR)
 * 参考: Arm® Cortex™-M33 GUG 第 4.2.18 章 (VTOR)
 */
void Core_SetupVectorTable(void) {
    arch_armv8m_setup_vector_table();
}
