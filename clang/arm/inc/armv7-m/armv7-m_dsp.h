/*
 * ARM Architecture - ARMv7-M DSP Extension
 *
 * ============================================================================
 * File: armv7-m_dsp.h
 * Description: ARMv7-M DSP (Digital Signal Processing) Extension definitions
 * 描述: ARMv7-M DSP (数字信号处理) 扩展定义
 *
 * This file provides definitions for the DSP Extension (ARMv7E-M):
 * - SIMD instructions
 * - Saturation instructions
 * - Multiply-accumulate instructions
 * - Packing/unpacking instructions
 * - Parallel addition/subtraction instructions
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter A1: Introduction
 *     * A1.3 Architecture extensions (page A1-22)
 *       - DSP extension adds saturating and unsigned SIMD instructions
 *       - Armv7E-M implementation includes DSP extension
 *   - Chapter A2: Application Level Programmers' Model
 *     * A2.2 Arm processor data types and arithmetic (page A2-25)
 *       - SIMD data types: 8-bit x 4, 16-bit x 2 operations
 *       - Saturation arithmetic (Q flag in APSR)
 *     * A2.3.2 The Application Program Status Register (APSR) (page A2-31)
 *       - GE[3:0] flags for SIMD operations
 *       - Q flag for saturation detection
 *   - Chapter A4.4 Data-processing instructions (page A4-107)
 *     * A4.4.3 Multiply instructions (page A4-109)
 *       - Table A4-6 Signed multiply instructions, Armv7-M DSP extension
 *         * SMLAD, SMLADX, SMLSD, SMLSDX (Dual multiply accumulate/subtract)
 *         * SMUAD, SMUADX, SMUSD, SMUSDX (Dual multiply add/subtract)
 *       - Table A4-8 Unsigned multiply instructions, Armv7-M DSP extension
 *         * UMAAL
 *     * A4.4.4 Saturating instructions (page A4-110)
 *       - Table A4-10 Halfword saturating instructions, Armv7-M DSP extension
 *         * SSAT16, USAT16
 *       - Table A4-11 Saturating addition and subtraction instructions
 *         * QADD, QSUB, QDADD, QDSUB
 *     * A4.4.5 Packing and unpacking instructions (page A4-111)
 *       - Table A4-13 Packing and unpacking instructions, Armv7-M DSP extension
 *         * PKHBT, PKHTB (Pack Halfword)
 *         * SXTAB, SXTAB16, SXTAH, SXTB16 (Signed extend and add)
 *         * UXTAB, UXTAB16, UXTAH, UXTB16 (Unsigned extend and add)
 *     * A4.4.7 Parallel addition and subtraction instructions, DSP extension (page A4-112)
 *       - Table A4-14 Parallel addition and subtraction instructions
 *         * Prefixes: S (Signed), Q (Saturating), SH (Signed Halving)
 *         *           U (Unsigned), UQ (Unsigned Saturating), UH (Unsigned Halving)
 *         * Operations: ADD16, ASX, SAX, SUB16, ADD8, SUB8
 *     * A4.4.8 Miscellaneous data-processing instructions (page A4-113)
 *       - Table A4-16 Miscellaneous data-processing instructions, Armv7-M DSP extension
 *         * SEL (Select Bytes using GE flags)
 *         * USAD8, USADA8 (Unsigned Sum of Absolute Differences)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_DSP_H__
#define __ARCH_ARM_V7M_DSP_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * DSP Extension Availability Check
 * DSP 扩展可用性检查
 *
 * Note: This header can be included even when DSP is not present.
 * The dsp_is_available() function can be used to check DSP support at runtime.
 * 注意: 即使DSP不存在也可以包含此头文件。
 * 可以使用 dsp_is_available() 函数在运行时检查DSP支持。
 * ============================================================================
 */

/*
 * ============================================================================
 * SIMD Data Types
 * SIMD 数据类型
 *
 * Reference: Chapter A2.2 Arm processor data types and arithmetic (page A2-25)
 *   - SIMD instructions operate on multiple data elements in parallel
 *   - 8-bit x 4: Four 8-bit operations in a 32-bit word
 *   - 16-bit x 2: Two 16-bit operations in a 32-bit word
 *   - Reference: Chapter A2.3.2 The Application Program Status Register (APSR)
 *     * GE[3:0] flags indicate results of individual byte/halfword operations
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
 *
 * Reference: Chapter A2.2 Arm processor data types and arithmetic (page A2-25)
 *   - A2.2.1 Integer arithmetic - Pseudocode details of saturation
 *   - Saturating arithmetic prevents overflow by clamping to max/min values
 *   - Q flag (APSR bit[27]) set when saturation occurs
 *   - Reference: Chapter A2.3.2 The Application Program Status Register (APSR)
 *     * Q flag is sticky - remains set until explicitly cleared
 *     * Used by SSAT, USAT, QADD, QSUB instructions
 * ============================================================================
 */

/**
 * @brief Signed Saturate
 * 有符号饱和
 * Saturates a signed value to a signed range specified by the saturate bit position.
 * Reference: Arm(R) v7-M ARM, A7-375, SSAT instruction
 *
 * @param value Value to saturate
 * @param sat Bit position for saturation (1-32)
 * @return Saturated value
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
 * Saturates a signed value to an unsigned range specified by the saturate bit position.
 * Reference: Arm(R) v7-M ARM, A7-444, USAT instruction
 *
 * @param value Value to saturate
 * @param sat Bit position for saturation (0-31)
 * @return Saturated value
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
 * 有符号16位饱和 (双16位)
 * Saturates two 16-bit signed values.
 * Reference: Arm(R) v7-M ARM, A7-376, SSAT16 instruction
 *
 * @param value Two 16-bit values in lower and upper halfwords
 * @param sat Bit position for saturation (1-16)
 * @return Two saturated 16-bit values
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
 * 无符号16位饱和 (双16位)
 * Saturates two 16-bit values to unsigned range.
 * Reference: Arm(R) v7-M ARM, A7-445, USAT16 instruction
 *
 * @param value Two 16-bit values in lower and upper halfwords
 * @param sat Bit position for saturation (0-15)
 * @return Two saturated unsigned 16-bit values
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
 * Adds two signed values with saturation.
 * Reference: Arm(R) v7-M ARM, A7-324, QADD instruction
 *
 * @param x First operand
 * @param y Second operand
 * @return Saturated sum
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
 * Subtracts two signed values with saturation.
 * Reference: Arm(R) v7-M ARM, A7-331, QSUB instruction
 *
 * @param x First operand
 * @param y Second operand
 * @return Saturated difference
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
 * Multiplies two values, doubles the result, and adds to accumulator with saturation.
 * Reference: Arm(R) v7-M ARM, A7-327, QDADD instruction
 *
 * @param acc Accumulator value
 * @param x Multiplicand
 * @return Saturated result
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
 * Multiplies two values, doubles the result, and subtracts from accumulator with saturation.
 * Reference: Arm(R) v7-M ARM, A7-329, QDSUB instruction
 *
 * @param acc Accumulator value
 * @param x Multiplicand
 * @return Saturated result
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
 * Parallel 16-bit Addition/Subtraction Functions
 * 并行16位加减法函数
 * ============================================================================
 */

/**
 * @brief Signed Add 16-bit (Parallel)
 * 有符号并行16位加法
 * Performs two signed 16-bit additions in parallel.
 * Reference: Arm(R) v7-M ARM, A7-349, SADD16 instruction
 *
 * @param x First operand (two 16-bit values)
 * @param y Second operand (two 16-bit values)
 * @return Two 16-bit sums, updates GE flags
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
 * Performs two signed 16-bit subtractions in parallel.
 * Reference: Arm(R) v7-M ARM, A7-351, SSUB16 instruction
 *
 * @param x First operand (two 16-bit values)
 * @param y Second operand (two 16-bit values)
 * @return Two 16-bit differences, updates GE flags
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
 * Performs four signed 8-bit additions in parallel.
 * Reference: Arm(R) v7-M ARM, A7-350, SADD8 instruction
 *
 * @param x First operand (four 8-bit values)
 * @param y Second operand (four 8-bit values)
 * @return Four 8-bit sums, updates GE flags
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
 * Performs four signed 8-bit subtractions in parallel.
 * Reference: Arm(R) v7-M ARM, A7-352, SSUB8 instruction
 *
 * @param x First operand (four 8-bit values)
 * @param y Second operand (four 8-bit values)
 * @return Four 8-bit differences, updates GE flags
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
 * Performs two unsigned 16-bit additions in parallel.
 * Reference: Arm(R) v7-M ARM, A7-437, UADD16 instruction
 *
 * @param x First operand (two 16-bit values)
 * @param y Second operand (two 16-bit values)
 * @return Two 16-bit sums, updates GE flags
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
 * Performs two unsigned 16-bit subtractions in parallel.
 * Reference: Arm(R) v7-M ARM, A7-439, USUB16 instruction
 *
 * @param x First operand (two 16-bit values)
 * @param y Second operand (two 16-bit values)
 * @return Two 16-bit differences, updates GE flags
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
 * Performs four unsigned 8-bit additions in parallel.
 * Reference: Arm(R) v7-M ARM, A7-438, UADD8 instruction
 *
 * @param x First operand (four 8-bit values)
 * @param y Second operand (four 8-bit values)
 * @return Four 8-bit sums, updates GE flags
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
 * Performs four unsigned 8-bit subtractions in parallel.
 * Reference: Arm(R) v7-M ARM, A7-440, USUB8 instruction
 *
 * @param x First operand (four 8-bit values)
 * @param y Second operand (four 8-bit values)
 * @return Four 8-bit differences, updates GE flags
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
 * Saturating Parallel Addition/Subtraction Functions
 * 饱和并行加减法函数
 * ============================================================================
 */

/**
 * @brief Saturating Signed Add 16-bit (Parallel)
 * 饱和有符号并行16位加法
 * Reference: Arm(R) v7-M ARM, A7-325, QADD16 instruction
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

/**
 * @brief Saturating Signed Subtract 16-bit (Parallel)
 * 饱和有符号并行16位减法
 * Reference: Arm(R) v7-M ARM, A7-333, QSUB16 instruction
 */
static inline uint32_t dsp_qsub16(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "qsub16 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Saturating Signed Add 8-bit (Parallel)
 * 饱和有符号并行8位加法
 * Reference: Arm(R) v7-M ARM, A7-326, QADD8 instruction
 */
static inline uint32_t dsp_qadd8(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "qadd8 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Saturating Signed Subtract 8-bit (Parallel)
 * 饱和有符号并行8位减法
 * Reference: Arm(R) v7-M ARM, A7-334, QSUB8 instruction
 */
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
 * Halving Parallel Addition/Subtraction Functions
 * 折半并行加减法函数
 * ============================================================================
 */

/**
 * @brief Signed Halving Add 16-bit (Parallel)
 * 有符号折半并行16位加法
 * Adds and shifts right by 1 (divide by 2).
 * Reference: Arm(R) v7-M ARM, A7-353, SHADD16 instruction
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

/**
 * @brief Signed Halving Subtract 16-bit (Parallel)
 * 有符号折半并行16位减法
 * Reference: Arm(R) v7-M ARM, A7-355, SHSUB16 instruction
 */
static inline uint32_t dsp_shsub16(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "shsub16 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Signed Halving Add 8-bit (Parallel)
 * 有符号折半并行8位加法
 * Reference: Arm(R) v7-M ARM, A7-354, SHADD8 instruction
 */
static inline uint32_t dsp_shadd8(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "shadd8 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Signed Halving Subtract 8-bit (Parallel)
 * 有符号折半并行8位减法
 * Reference: Arm(R) v7-M ARM, A7-356, SHSUB8 instruction
 */
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

/**
 * @brief Signed Multiply Accumulate Long
 * 有符号长乘累加
 * Reference: Arm(R) v7-M ARM, A7-361, SMLAL instruction variant
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

/**
 * @brief Signed Multiply Accumulate Dual
 * 有符号双乘累加
 * Performs two 16x16 multiplies and adds to accumulator.
 * Reference: Arm(R) v7-M ARM, A7-360, SMLAD instruction
 *
 * @param acc Accumulator
 * @param x First operand (two 16-bit values)
 * @param y Second operand (two 16-bit values)
 * @return acc + (x[0]*y[0]) + (x[1]*y[1])
 */
static inline int32_t dsp_smlad(int32_t acc, uint32_t x, uint32_t y) {
    int32_t result;
    __asm__ volatile (
        "smlad %0, %1, %2, %3"
        : "=r" (result)
        : "r" (x), "r" (y), "r" (acc)
    );
    return result;
}

/**
 * @brief Signed Multiply Accumulate Dual (Exchange)
 * 有符号双乘累加(交换)
 * Reference: Arm(R) v7-M ARM, A7-360, SMLADX instruction
 */
static inline int32_t dsp_smladx(int32_t acc, uint32_t x, uint32_t y) {
    int32_t result;
    __asm__ volatile (
        "smladx %0, %1, %2, %3"
        : "=r" (result)
        : "r" (x), "r" (y), "r" (acc)
    );
    return result;
}

/**
 * @brief Signed Multiply Subtract Dual
 * 有符号双乘减
 * Reference: Arm(R) v7-M ARM, A7-365, SMLSD instruction
 */
static inline int32_t dsp_smlsd(int32_t acc, uint32_t x, uint32_t y) {
    int32_t result;
    __asm__ volatile (
        "smlsd %0, %1, %2, %3"
        : "=r" (result)
        : "r" (x), "r" (y), "r" (acc)
    );
    return result;
}

/**
 * @brief Signed Multiply Subtract Dual (Exchange)
 * 有符号双乘减(交换)
 * Reference: Arm(R) v7-M ARM, A7-365, SMLSDX instruction
 */
static inline int32_t dsp_smlsdx(int32_t acc, uint32_t x, uint32_t y) {
    int32_t result;
    __asm__ volatile (
        "smlsdx %0, %1, %2, %3"
        : "=r" (result)
        : "r" (x), "r" (y), "r" (acc)
    );
    return result;
}

/**
 * @brief Signed Dual Multiply Add
 * 有符号双乘加
 * Reference: Arm(R) v7-M ARM, A7-370, SMUAD instruction
 */
static inline int32_t dsp_smuad(uint32_t x, uint32_t y) {
    int32_t result;
    __asm__ volatile (
        "smuad %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Signed Dual Multiply Add (Exchange)
 * 有符号双乘加(交换)
 * Reference: Arm(R) v7-M ARM, A7-370, SMUADX instruction
 */
static inline int32_t dsp_smuadx(uint32_t x, uint32_t y) {
    int32_t result;
    __asm__ volatile (
        "smuadx %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Signed Dual Multiply Subtract
 * 有符号双乘减
 * Reference: Arm(R) v7-M ARM, A7-374, SMUSD instruction
 */
static inline int32_t dsp_smusd(uint32_t x, uint32_t y) {
    int32_t result;
    __asm__ volatile (
        "smusd %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Signed Dual Multiply Subtract (Exchange)
 * 有符号双乘减(交换)
 * Reference: Arm(R) v7-M ARM, A7-374, SMUSDX instruction
 */
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

/**
 * @brief Pack Halfword
 * 打包半字
 * Combines halfwords from two registers.
 * Reference: Arm(R) v7-M ARM, A7-312, PKHBT instruction
 *
 * @param x First operand
 * @param y Second operand (lower halfword used)
 * @return Packed result
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

/**
 * @brief Pack Halfword (TB form)
 * 打包半字(TB形式)
 * Reference: Arm(R) v7-M ARM, A7-312, PKHTB instruction
 */
static inline uint32_t dsp_pkhtb(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "pkhtb %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Signed Extend Byte
 * 有符号扩展字节
 * Extends 8-bit to 32-bit.
 * Reference: Arm(R) v7-M ARM, A7-413, SXTB instruction
 */
static inline int32_t dsp_sxtb(int32_t x) {
    int32_t result;
    __asm__ volatile (
        "sxtb %0, %1"
        : "=r" (result)
        : "r" (x)
    );
    return result;
}

/**
 * @brief Signed Extend Halfword
 * 有符号扩展半字
 * Extends 16-bit to 32-bit.
 * Reference: Arm(R) v7-M ARM, A7-415, SXTH instruction
 */
static inline int32_t dsp_sxth(int32_t x) {
    int32_t result;
    __asm__ volatile (
        "sxth %0, %1"
        : "=r" (result)
        : "r" (x)
    );
    return result;
}

/**
 * @brief Signed Extend Byte 16
 * 有符号扩展字节16
 * Dual 8-bit to 16-bit sign extension.
 * Reference: Arm(R) v7-M ARM, A7-414, SXTB16 instruction
 */
static inline uint32_t dsp_sxtb16(uint32_t x) {
    uint32_t result;
    __asm__ volatile (
        "sxtb16 %0, %1"
        : "=r" (result)
        : "r" (x)
    );
    return result;
}

/**
 * @brief Unsigned Extend Byte
 * 无符号扩展字节
 * Reference: Arm(R) v7-M ARM, A7-448, UXTB instruction
 */
static inline uint32_t dsp_uxtb(uint32_t x) {
    uint32_t result;
    __asm__ volatile (
        "uxtb %0, %1"
        : "=r" (result)
        : "r" (x)
    );
    return result;
}

/**
 * @brief Unsigned Extend Halfword
 * 无符号扩展半字
 * Reference: Arm(R) v7-M ARM, A7-450, UXTH instruction
 */
static inline uint32_t dsp_uxth(uint32_t x) {
    uint32_t result;
    __asm__ volatile (
        "uxth %0, %1"
        : "=r" (result)
        : "r" (x)
    );
    return result;
}

/**
 * @brief Unsigned Extend Byte 16
 * 无符号扩展字节16
 * Reference: Arm(R) v7-M ARM, A7-449, UXTB16 instruction
 */
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

/**
 * @brief Select Bytes using GE flags
 * 使用GE标志选择字节
 * Selects each byte based on GE flags.
 * Reference: Arm(R) v7-M ARM, A7-357, SEL instruction
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

/**
 * @brief Get Q flag status
 * 获取Q标志状态
 * Returns 1 if saturation occurred, 0 otherwise.
 * Reference: Arm(R) v7-M ARM, A2-28, APSR.Q flag
 */
static inline uint32_t dsp_get_q_flag(void) {
    uint32_t apsr;
    __asm__ volatile (
        "mrs %0, apsr"
        : "=r" (apsr)
    );
    return (apsr >> 27) & 1;
}

/**
 * @brief Clear Q flag
 * 清除Q标志
 * Reference: Arm(R) v7-M ARM, A2-28, APSR.Q flag
 */
static inline void dsp_clear_q_flag(void) {
    __asm__ volatile (
        "msr apsr_nzcvq, %0"
        :
        : "r" (0)
    );
}

/*
 * ============================================================================
 * DSP Initialization and Helper Functions
 * DSP 初始化和辅助函数 (非内联实现，在 .c 文件中)
 * ============================================================================
 */

/**
 * @brief Initialize DSP extension
 * 初始化DSP扩展
 * Enables DSP instructions by ensuring the processor is in appropriate mode.
 * Reference: Chapter A1.3 Architecture extensions (page A1-22)
 */
void dsp_init(void);

/**
 * @brief Check if DSP extension is available
 * 检查DSP扩展是否可用
 * @return 1 if DSP is available, 0 otherwise
 */
uint32_t dsp_is_available(void);

/**
 * @brief Pack two 16-bit values into 32-bit register
 * 将两个16位值打包到32位寄存器
 * @param lo Lower 16-bit value
 * @param hi Upper 16-bit value
 * @return Packed 32-bit value
 */
uint32_t dsp_pack16(uint16_t lo, uint16_t hi);

/**
 * @brief Unpack 32-bit value into two 16-bit values
 * 将32位值解包为两个16位值
 * @param val 32-bit packed value
 * @param lo Pointer to store lower 16-bit value
 * @param hi Pointer to store upper 16-bit value
 */
void dsp_unpack16(uint32_t val, uint16_t *lo, uint16_t *hi);

/**
 * @brief Pack four 8-bit values into 32-bit register
 * 将四个8位值打包到32位寄存器
 * @param b0 Byte 0
 * @param b1 Byte 1
 * @param b2 Byte 2
 * @param b3 Byte 3
 * @return Packed 32-bit value
 */
uint32_t dsp_pack8(uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * @brief Unpack 32-bit value into four 8-bit values
 * 将32位值解包为四个8位值
 * @param val 32-bit packed value
 * @param b0 Pointer to store byte 0
 * @param b1 Pointer to store byte 1
 * @param b2 Pointer to store byte 2
 * @param b3 Pointer to store byte 3
 */
void dsp_unpack8(uint32_t val, uint8_t *b0, uint8_t *b1, uint8_t *b2, uint8_t *b3);

/**
 * @brief Complex multiply-accumulate (16-bit)
 * 复数乘累加(16位)
 * Performs complex MAC operation: acc += (a + bi) * (c + di)
 * @param acc_real Real part accumulator
 * @param acc_imag Imaginary part accumulator
 * @param a First complex number (packed: imag|real)
 * @param b Second complex number (packed: imag|real)
 * @param result_real Output real part
 * @param result_imag Output imaginary part
 */
void dsp_complex_mac(int32_t acc_real, int32_t acc_imag,
                     uint32_t a, uint32_t b,
                     int32_t *result_real, int32_t *result_imag);

/**
 * @brief Saturating complex multiply-accumulate
 * 饱和复数乘累加
 * Uses DSP instructions for efficient saturated complex MAC.
 */
void dsp_complex_mac_sat(int32_t acc_real, int32_t acc_imag,
                         uint32_t a, uint32_t b,
                         int32_t *result_real, int32_t *result_imag);

/**
 * @brief Single tap FIR filter computation
 * 单抽头FIR滤波器计算
 * @param acc Current accumulator value
 * @param coeff Filter coefficient (16-bit)
 * @param sample Input sample (16-bit)
 * @return Updated accumulator
 */
int32_t dsp_fir_tap(int32_t acc, int16_t coeff, int16_t sample);

/**
 * @brief Dual tap FIR filter computation
 * 双抽头FIR滤波器计算
 * @param acc Current accumulator value
 * @param coeffs Packed coefficients (coeff1 | coeff0)
 * @param samples Packed samples (sample1 | sample0)
 * @return Updated accumulator
 */
int32_t dsp_fir_dual_tap(int32_t acc, uint32_t coeffs, uint32_t samples);

/**
 * @brief 16-bit dot product
 * 16位点积
 * @param a First vector (16-bit elements)
 * @param b Second vector (16-bit elements)
 * @param len Vector length (must be even)
 * @return Dot product result
 */
int32_t dsp_dot_product16(const int16_t *a, const int16_t *b, uint32_t len);

/**
 * @brief Saturating 16-bit dot product
 * 饱和16位点积
 * @param a First vector (16-bit elements)
 * @param b Second vector (16-bit elements)
 * @param len Vector length
 * @return Saturated dot product result
 */
int32_t dsp_dot_product16_sat(const int16_t *a, const int16_t *b, uint32_t len);

/**
 * @brief 2x2 matrix multiply (16-bit elements)
 * 2x2矩阵乘法(16位元素)
 * @param a Input matrix A
 * @param b Input matrix B
 * @param c Output matrix C = A * B
 */
void dsp_matrix_mult2x2(const int16_t *a, const int16_t *b, int32_t *c);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_DSP_H__ */
