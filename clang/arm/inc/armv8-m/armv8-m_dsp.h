/*
 * ARM Architecture - ARMv8-M DSP Extension
 *
 * ============================================================================
 * File: armv8-m_dsp.h
 * Description: ARMv8-M DSP (Digital Signal Processing) Extension definitions
 * 描述: ARMv8-M DSP (数字信号处理) 扩展定义
 *
 * This file provides definitions for the DSP Extension in ARMv8-M:
 * - Legacy ARMv7E-M DSP instructions (backward compatible)
 * - Enhanced DSP features for ARMv8-M
 * - Integration with MVE (Helium) when available
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B4 - Floating-point Support
 *   - Chapter B5 - MVE (Helium) Vector Extension
 *   - DSP instructions inherited from ARMv7E-M
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V8M_DSP_H__
#define __ARCH_ARM_V8M_DSP_H__

#include <stdint.h>
#include "armv8-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * DSP Extension Availability Check
 * DSP 扩展可用性检查
 * ============================================================================
 */

#if (__DSP_PRESENT == 0)
#error "DSP extension is not configured. Define __DSP_PRESENT=1 to use DSP features."
#endif

/*
 * ============================================================================
 * SIMD Data Types (ARMv8-M compatible)
 * SIMD 数据类型 (ARMv8-M 兼容)
 * ============================================================================
 */

/**
 * @brief 16-bit x 2 SIMD type
 * 两个16位整数的SIMD类型
 */
typedef union {
    int16_t  s16[2];
    uint16_t u16[2];
    int32_t  s32;
    uint32_t u32;
} simd16x2_t;

/**
 * @brief 8-bit x 4 SIMD type
 * 四个8位整数的SIMD类型
 */
typedef union {
    int8_t   s8[4];
    uint8_t  u8[4];
    int32_t  s32;
    uint32_t u32;
} simd8x4_t;

/*
 * ============================================================================
 * Saturating Arithmetic Functions
 * 饱和运算函数
 * ============================================================================
 */

/**
 * @brief Signed Saturate
 * 有符号饱和
 * Reference: Arm(R) v8-M ARM, SSAT instruction
 */
static inline int32_t dsp_ssat(int32_t value, uint32_t sat) {
    int32_t result;
    __asm__ volatile (
        "ssat %0, %1, %2"
        : "=r" (result)
        : "I" (sat), "r" (value)
    );
    return result;
}

/**
 * @brief Unsigned Saturate
 * 无符号饱和
 * Reference: Arm(R) v8-M ARM, USAT instruction
 */
static inline uint32_t dsp_usat(int32_t value, uint32_t sat) {
    uint32_t result;
    __asm__ volatile (
        "usat %0, %1, %2"
        : "=r" (result)
        : "I" (sat), "r" (value)
    );
    return result;
}

/**
 * @brief Signed Saturate 16-bit
 * 有符号16位饱和
 * Reference: Arm(R) v8-M ARM, SSAT16 instruction
 */
static inline uint32_t dsp_ssat16(uint32_t value, uint32_t sat) {
    uint32_t result;
    __asm__ volatile (
        "ssat16 %0, %1, %2"
        : "=r" (result)
        : "I" (sat), "r" (value)
    );
    return result;
}

/**
 * @brief Unsigned Saturate 16-bit
 * 无符号16位饱和
 * Reference: Arm(R) v8-M ARM, USAT16 instruction
 */
static inline uint32_t dsp_usat16(uint32_t value, uint32_t sat) {
    uint32_t result;
    __asm__ volatile (
        "usat16 %0, %1, %2"
        : "=r" (result)
        : "I" (sat), "r" (value)
    );
    return result;
}

/**
 * @brief Saturating Add
 * 饱和加法
 * Reference: Arm(R) v8-M ARM, QADD instruction
 */
static inline int32_t dsp_qadd(int32_t x, int32_t y) {
    int32_t result;
    __asm__ volatile (
        "qadd %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Saturating Subtract
 * 饱和减法
 * Reference: Arm(R) v8-M ARM, QSUB instruction
 */
static inline int32_t dsp_qsub(int32_t x, int32_t y) {
    int32_t result;
    __asm__ volatile (
        "qsub %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Saturating Double Multiply Add
 * 饱和双倍乘加
 * Reference: Arm(R) v8-M ARM, QDADD instruction
 */
static inline int32_t dsp_qdadd(int32_t acc, int32_t x) {
    int32_t result;
    __asm__ volatile (
        "qdadd %0, %1, %2"
        : "=r" (result)
        : "r" (acc), "r" (x)
    );
    return result;
}

/**
 * @brief Saturating Double Multiply Subtract
 * 饱和双倍乘减
 * Reference: Arm(R) v8-M ARM, QDSUB instruction
 */
static inline int32_t dsp_qdsub(int32_t acc, int32_t x) {
    int32_t result;
    __asm__ volatile (
        "qdsub %0, %1, %2"
        : "=r" (result)
        : "r" (acc), "r" (x)
    );
    return result;
}

/*
 * ============================================================================
 * Parallel Addition/Subtraction Functions
 * 并行加减法函数
 * ============================================================================
 */

/**
 * @brief Signed Add 16-bit (Parallel)
 * 有符号并行16位加法
 * Reference: Arm(R) v8-M ARM, SADD16 instruction
 */
static inline uint32_t dsp_sadd16(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "sadd16 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Signed Subtract 16-bit (Parallel)
 * 有符号并行16位减法
 * Reference: Arm(R) v8-M ARM, SSUB16 instruction
 */
static inline uint32_t dsp_ssub16(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "ssub16 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Signed Add 8-bit (Parallel)
 * 有符号并行8位加法
 * Reference: Arm(R) v8-M ARM, SADD8 instruction
 */
static inline uint32_t dsp_sadd8(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "sadd8 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Signed Subtract 8-bit (Parallel)
 * 有符号并行8位减法
 * Reference: Arm(R) v8-M ARM, SSUB8 instruction
 */
static inline uint32_t dsp_ssub8(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "ssub8 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Unsigned Add 16-bit (Parallel)
 * 无符号并行16位加法
 * Reference: Arm(R) v8-M ARM, UADD16 instruction
 */
static inline uint32_t dsp_uadd16(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "uadd16 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Unsigned Subtract 16-bit (Parallel)
 * 无符号并行16位减法
 * Reference: Arm(R) v8-M ARM, USUB16 instruction
 */
static inline uint32_t dsp_usub16(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "usub16 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Unsigned Add 8-bit (Parallel)
 * 无符号并行8位加法
 * Reference: Arm(R) v8-M ARM, UADD8 instruction
 */
static inline uint32_t dsp_uadd8(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "uadd8 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Unsigned Subtract 8-bit (Parallel)
 * 无符号并行8位减法
 * Reference: Arm(R) v8-M ARM, USUB8 instruction
 */
static inline uint32_t dsp_usub8(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "usub8 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/*
 * ============================================================================
 * Saturating Parallel Addition/Subtraction
 * 饱和并行加减法
 * ============================================================================
 */

static inline uint32_t dsp_qadd16(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "qadd16 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

static inline uint32_t dsp_qsub16(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "qsub16 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

static inline uint32_t dsp_qadd8(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "qadd8 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

static inline uint32_t dsp_qsub8(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "qsub8 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/*
 * ============================================================================
 * Halving Parallel Addition/Subtraction
 * 折半并行加减法
 * ============================================================================
 */

static inline uint32_t dsp_shadd16(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "shadd16 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

static inline uint32_t dsp_shsub16(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "shsub16 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

static inline uint32_t dsp_shadd8(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "shadd8 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

static inline uint32_t dsp_shsub8(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "shsub8 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/*
 * ============================================================================
 * Multiply-Accumulate Functions
 * 乘累加函数
 * ============================================================================
 */

static inline int64_t dsp_smlal(int64_t acc, int32_t x, int32_t y) {
    int32_t acc_lo = (int32_t)acc;
    int32_t acc_hi = (int32_t)(acc >> 32);
    __asm__ volatile (
        "smlal %0, %1, %2, %3"
        : "+r" (acc_lo), "+r" (acc_hi)
        : "r" (x), "r" (y)
    );
    return ((int64_t)acc_hi << 32) | (uint32_t)acc_lo;
}

static inline int32_t dsp_smlad(int32_t acc, uint32_t x, uint32_t y) {
    int32_t result;
    __asm__ volatile (
        "smlad %0, %1, %2, %3"
        : "=r" (result)
        : "r" (x), "r" (y), "r" (acc)
    );
    return result;
}

static inline int32_t dsp_smladx(int32_t acc, uint32_t x, uint32_t y) {
    int32_t result;
    __asm__ volatile (
        "smladx %0, %1, %2, %3"
        : "=r" (result)
        : "r" (x), "r" (y), "r" (acc)
    );
    return result;
}

static inline int32_t dsp_smlsd(int32_t acc, uint32_t x, uint32_t y) {
    int32_t result;
    __asm__ volatile (
        "smlsd %0, %1, %2, %3"
        : "=r" (result)
        : "r" (x), "r" (y), "r" (acc)
    );
    return result;
}

static inline int32_t dsp_smlsdx(int32_t acc, uint32_t x, uint32_t y) {
    int32_t result;
    __asm__ volatile (
        "smlsdx %0, %1, %2, %3"
        : "=r" (result)
        : "r" (x), "r" (y), "r" (acc)
    );
    return result;
}

static inline int32_t dsp_smuad(uint32_t x, uint32_t y) {
    int32_t result;
    __asm__ volatile (
        "smuad %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

static inline int32_t dsp_smuadx(uint32_t x, uint32_t y) {
    int32_t result;
    __asm__ volatile (
        "smuadx %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

static inline int32_t dsp_smusd(uint32_t x, uint32_t y) {
    int32_t result;
    __asm__ volatile (
        "smusd %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

static inline int32_t dsp_smusdx(uint32_t x, uint32_t y) {
    int32_t result;
    __asm__ volatile (
        "smusdx %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/*
 * ============================================================================
 * Packing and Unpacking Functions
 * 打包和解包函数
 * ============================================================================
 */

static inline uint32_t dsp_pkhbt(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "pkhbt %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

static inline uint32_t dsp_pkhtb(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "pkhtb %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

static inline int32_t dsp_sxtb(int32_t x) {
    int32_t result;
    __asm__ volatile (
        "sxtb %0, %1"
        : "=r" (result)
        : "r" (x)
    );
    return result;
}

static inline int32_t dsp_sxth(int32_t x) {
    int32_t result;
    __asm__ volatile (
        "sxth %0, %1"
        : "=r" (result)
        : "r" (x)
    );
    return result;
}

static inline uint32_t dsp_sxtb16(uint32_t x) {
    uint32_t result;
    __asm__ volatile (
        "sxtb16 %0, %1"
        : "=r" (result)
        : "r" (x)
    );
    return result;
}

static inline uint32_t dsp_uxtb(uint32_t x) {
    uint32_t result;
    __asm__ volatile (
        "uxtb %0, %1"
        : "=r" (result)
        : "r" (x)
    );
    return result;
}

static inline uint32_t dsp_uxth(uint32_t x) {
    uint32_t result;
    __asm__ volatile (
        "uxth %0, %1"
        : "=r" (result)
        : "r" (x)
    );
    return result;
}

static inline uint32_t dsp_uxtb16(uint32_t x) {
    uint32_t result;
    __asm__ volatile (
        "uxtb16 %0, %1"
        : "=r" (result)
        : "r" (x)
    );
    return result;
}

/*
 * ============================================================================
 * Selection Functions
 * 选择函数
 * ============================================================================
 */

static inline uint32_t dsp_sel(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "sel %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/*
 * ============================================================================
 * Q Flag Access Functions
 * Q标志访问函数
 * ============================================================================
 */

static inline uint32_t dsp_get_q_flag(void) {
    uint32_t apsr;
    __asm__ volatile (
        "mrs %0, apsr"
        : "=r" (apsr)
    );
    return (apsr >> 27) & 1;
}

static inline void dsp_clear_q_flag(void) {
    __asm__ volatile (
        "msr apsr_nzcvq, %0"
        :
        : "r" (0)
    );
}

/*
 * ============================================================================
 * ARMv8-M Specific DSP Features
 * ARMv8-M 特定 DSP 功能
 * ============================================================================
 */

/**
 * @brief Check if DSP is available
 * 检查DSP是否可用
 * @return 1 if available, 0 otherwise
 */
static inline uint32_t dsp_is_available(void) {
    return (__DSP_PRESENT != 0) ? 1U : 0U;
}

/**
 * @brief Check if MVE (Helium) is available
 * 检查MVE是否可用
 * @return 1 if available, 0 otherwise
 */
static inline uint32_t dsp_mve_is_available(void) {
#if (__ARM_FEATURE_MVE & 1)
    return 1U;
#else
    return 0U;
#endif
}

/**
 * @brief Check if MVE floating-point is available
 * 检查MVE浮点是否可用
 * @return 1 if available, 0 otherwise
 */
static inline uint32_t dsp_mve_fp_is_available(void) {
#if (__ARM_FEATURE_MVE & 2)
    return 1U;
#else
    return 0U;
#endif
}

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V8M_DSP_H__ */
