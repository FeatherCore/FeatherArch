/*
 * ARM Architecture - Cortex-M4 FPU Specific Functions
 *
 * ============================================================================
 * File: cm4_fpu.h
 * Description: Cortex-M4 specific FPU (FPv4-SP) functions
 * 描述: Cortex-M4 特定 FPU (FPv4-SP) 功能
 *
 * IMPORTANT: This file ONLY contains FPU functions specific to Cortex-M4.
 * Generic ARMv7-M FPU functions are in armv7-m/armv7-m_fpu.h
 *
 * Cortex-M4 specific FPU features:
 * - MVFR0/MVFR1 feature detection (FPv4-SP capability detection)
 *
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 4
 *            Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.3
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_FPU_H__
#define __CM4_FPU_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * Cortex-M4 FPU Feature Detection (FPv4-SP specific)
 * Cortex-M4 FPU 特性检测 (FPv4-SP 特定)
 * ============================================================================
 *
 * These functions use MVFR0/MVFR1 registers to detect FPv4-SP capabilities.
 * Reference: Arm(R) Cortex-M4 TRM, Section 4.3.7
 */

/**
 * @brief Check if single-precision floating-point is supported
 * 检查是否支持单精度浮点
 * @return 1 if supported, 0 otherwise
 */
static inline uint32_t cm4_fpu_has_single_precision(void) {
    uint32_t mvfr0 = (*(volatile uint32_t *)(0xE000EF40UL));
    return (mvfr0 & 0xF) == 0x2;
}

/**
 * @brief Check if double-precision floating-point is supported
 * 检查是否支持双精度浮点
 * @return 1 if supported, 0 otherwise (always 0 for Cortex-M4)
 */
static inline uint32_t cm4_fpu_has_double_precision(void) {
    uint32_t mvfr0 = (*(volatile uint32_t *)(0xE000EF40UL));
    return ((mvfr0 >> 4) & 0xF) == 0x0;
}

/**
 * @brief Check if FPv4-SP short vectors are supported
 * 检查是否支持 FPv4-SP 短向量
 * @return 1 if supported, 0 otherwise
 */
static inline uint32_t cm4_fpu_has_short_vectors(void) {
    uint32_t mvfr0 = (*(volatile uint32_t *)(0xE000EF40UL));
    return ((mvfr0 >> 8) & 0xF) == 0x1;
}

/**
 * @brief Check if square root is supported
 * 检查是否支持平方根
 * @return 1 if supported, 0 otherwise
 */
static inline uint32_t cm4_fpu_has_sqrt(void) {
    uint32_t mvfr0 = (*(volatile uint32_t *)(0xE000EF40UL));
    return ((mvfr0 >> 12) & 0xF) == 0x1;
}

/**
 * @brief Check if divide is supported
 * 检查是否支持除法
 * @return 1 if supported, 0 otherwise
 */
static inline uint32_t cm4_fpu_has_divide(void) {
    uint32_t mvfr0 = (*(volatile uint32_t *)(0xE000EF40UL));
    return ((mvfr0 >> 16) & 0xF) == 0x1;
}

/**
 * @brief Check if FPv4-SP exception trapping is supported
 * 检查是否支持 FPv4-SP 异常捕获
 * @return 1 if supported, 0 otherwise
 */
static inline uint32_t cm4_fpu_has_fp_except_trapping(void) {
    uint32_t mvfr0 = (*(volatile uint32_t *)(0xE000EF40UL));
    return ((mvfr0 >> 20) & 0xF) == 0x0;
}

/**
 * @brief Check if FPv4-SP double-precision is supported
 * 检查是否支持 FPv4-SP 双精度
 * @return 1 if supported, 0 otherwise
 */
static inline uint32_t cm4_fpu_has_fp_double_precision(void) {
    uint32_t mvfr0 = (*(volatile uint32_t *)(0xE000EF40UL));
    return ((mvfr0 >> 24) & 0xF) == 0x0;
}

/**
 * @brief Check if FPv4-SP half-precision is supported
 * 检查是否支持 FPv4-SP 半精度
 * @return 1 if supported, 0 otherwise
 */
static inline uint32_t cm4_fpu_has_fp_half_precision(void) {
    uint32_t mvfr0 = (*(volatile uint32_t *)(0xE000EF40UL));
    return ((mvfr0 >> 28) & 0xF) == 0x1;
}

/**
 * @brief Check if FPv4-SP fused MAC is supported
 * 检查是否支持 FPv4-SP 融合乘加
 * @return 1 if supported, 0 otherwise
 */
static inline uint32_t cm4_fpu_has_fp_fused_mac(void) {
    uint32_t mvfr1 = (*(volatile uint32_t *)(0xE000EF44UL));
    return (mvfr1 & 0xF) == 0x1;
}

#ifdef __cplusplus
}
#endif

#endif /* __CM4_FPU_H__ */
