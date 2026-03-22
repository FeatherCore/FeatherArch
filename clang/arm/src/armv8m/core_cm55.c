/*
 * ARM Cortex-M55 Core Peripheral Access Layer Implementation
 * ARM Cortex-M55 核心外设访问层实现
 *
 * ============================================================================
 * File: core_cm55.c
 * Description: ARM Cortex-M55 core peripheral access layer implementation
 * 描述: ARM Cortex-M55 核心外设访问层实现
 *
 * This file provides ARM Cortex-M55 specific implementation.
 * 本文件提供 ARM Cortex-M55 特定实现。
 *
 * Dependency Hierarchy / 依赖层次:
 *   core_cm55.c → core_cm55.h → armv8m.h → armv8m.c
 *   (This file) (Cortex-M55) (ARMv8-M)  (Implementation)
 *
 * Reference Documents / 参考文档:
 *   1. Arm® v8-M Architecture Reference Manual
 *      - Chapter B3: Programmers' Model
 *      - Chapter B4: Floating-point Support
 *      - Chapter B5: Vector Extension
 *
 *   2. Arm® Cortex™-M55 Devices Generic User Guide
 *      - Chapter 4.2: System Control Block (SCB) registers
 *      - Chapter 4.3: Nested Vectored Interrupt Controller (NVIC)
 *      - Chapter 8: Performance Monitor Unit (PMU)
 *      - Chapter 9: Helium (MVE) Extension
 *
 *   3. Arm® Cortex®-M55 Processor Technical Reference Manual
 *      - Chapter 4: Processor Registers
 *      - Chapter 11: Performance Monitor Unit (PMU)
 *
 *   4. Arm-Cortex-M55-Processor-Datasheet
 *      - Feature configuration
 *      - Memory map
 *
 * Cortex-M55 Features:
 *   - ARMv8.1-M Mainline architecture
 *   - TrustZone Security Extension
 *   - Optional FPU (single/double precision)
 *   - MPU with 16 regions
 *   - Helium (MVE) SIMD extension
 *   - DSP instructions (SIMD)
 *   - Hardware Integer Divide
 *   - Embedded Trace Macrocell (ETM) optional
 *   - Performance Monitor Unit (PMU) with 31 counters
 *
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 ARM Architecture Team. All rights reserved.
 */

#include "core_cm55.h"

/*
 * ============================================================================
 * Cortex-M55 Core ID Definitions
 * Cortex-M55 核心ID定义
 * Reference: Arm® Cortex®-M55 TRM Section 4.2 (CPUID)
 * 参考: Arm® Cortex®-M55 TRM 第 4.2 节 (CPUID)
 * ============================================================================
 */

/**
 * Cortex-M55 Revision
 * Cortex-M55 版本
 */
#define __CM55_REV         0x0001U

/**
 * Cortex-M55 Processor number
 * Cortex-M55 处理器编号
 */
#define __CORTEX_M          55U

/*
 * ============================================================================
 * NVIC Interrupt Controller Functions - Cortex-M55 Specific
 * NVIC 中断控制器函数 - Cortex-M55 特有
 * Reference: Arm® Cortex™-M55 GUG 4.3.27 (NVIC_ITNS)
 * 参考: Arm® Cortex™-M55 GUG 4.3.27 (NVIC_ITNS)
 * ============================================================================
 */

/**
 * @brief Get NVIC target state
 * @brief 获取 NVIC 目标状态
 *
 * Reference: Arm® Cortex™-M55 GUG 4.3.27 (NVIC_ITNS)
 * 参考: Arm® Cortex™-M55 GUG 4.3.27 (NVIC_ITNS)
 *
 * @param IRQn: Interrupt number
 * @param IRQn: 中断号
 * @return Target state (0 = secure, 1 = non-secure)
 * @return 目标状态 (0 = 安全, 1 = 非安全)
 */
uint32_t NVIC_GetTargetState(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        return((uint32_t)(((NVIC->ITNS[tmp] >> (((uint32_t)(int32_t)IRQn) & 0x1FUL)) & 1U)));
    }
    return 0;
}

/**
 * @brief Set NVIC target state
 * @brief 设置 NVIC 目标状态
 *
 * Reference: Arm® Cortex™-M55 GUG 4.3.27 (NVIC_ITNS)
 * 参考: Arm® Cortex™-M55 GUG 4.3.27 (NVIC_ITNS)
 *
 * @param IRQn: Interrupt number
 * @param IRQn: 中断号
 * @return Success status
 * @return 成功状态
 */
uint32_t NVIC_SetTargetState(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        NVIC->ITNS[tmp] |= (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
        return((uint32_t)(1UL));
    }
    return 0;
}

/**
 * @brief Clear NVIC target state
 * @brief 清除 NVIC 目标状态
 *
 * Reference: Arm® Cortex™-M55 GUG 4.3.27 (NVIC_ITNS)
 * 参考: Arm® Cortex™-M55 GUG 4.3.27 (NVIC_ITNS)
 *
 * @param IRQn: Interrupt number
 * @param IRQn: 中断号
 * @return Success status
 * @return 成功状态
 */
uint32_t NVIC_ClearTargetState(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        NVIC->ITNS[tmp] &= ~(uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
        return((uint32_t)(1UL));
    }
    return 0;
}

/*
 * ============================================================================
 * Initialization Functions
 * 初始化函数
 * ============================================================================
 */

/**
 * @brief Initialize Cortex-M55 core
 * @brief 初始化 Cortex-M55 核心
 *
 * This function initializes the Cortex-M55 core including:
 * 本函数初始化 Cortex-M55 核心包括:
 *   - FPU enable
 *   - MPU initialization
 *   - Memory barriers
 *
 * Reference: Arm® Cortex™-M55 Devices Generic User Guide and TRM
 * 参考: Arm® Cortex™-M55 GUG 和 TRM
 */
void Core_Init(void) {
    arch_armv8m_init();
}

/**
 * @brief Setup vector table for Cortex-M55
 * @brief 为 Cortex-M55 设置向量表
 *
 * Reference: Arm® Cortex™-M55 Devices Generic User Guide Chapter 4.2.18 (VTOR)
 * 参考: Arm® Cortex™-M55 GUG 第 4.2.18 章 (VTOR)
 */
void Core_SetupVectorTable(void) {
    arch_armv8m_setup_vector_table();
}
