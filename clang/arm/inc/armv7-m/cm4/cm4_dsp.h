/*
 * ARM Architecture - Cortex-M4 DSP Specific Functions
 *
 * ============================================================================
 * File: cm4_dsp.h
 * Description: Cortex-M4 specific DSP functions (ARMv7E-M extensions)
 * 描述: Cortex-M4 特定 DSP 功能 (ARMv7E-M 扩展)
 *
 * IMPORTANT: This file ONLY contains DSP functions specific to Cortex-M4
 * that are NOT in armv7-m/armv7-m_dsp.h.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide
 *            Arm(R) Cortex-M4 Processor Technical Reference Manual
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_DSP_H__
#define __CM4_DSP_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * Cortex-M4 Most Significant Word Multiply (ARMv7E-M specific)
 * Reference: Generic User Guide, Section 3.5.72 - 3.5.74
 * ============================================================================
 */

/**
 * @brief Signed Most Significant Word Multiply Accumulate
 * SMMLA instruction - acc + ((x * y) >> 32)
 */
static inline int32_t cm4_smmla(int32_t x, int32_t y, int32_t acc) {
    int32_t result;
    __asm__ volatile (
        "smmla %0, %1, %2, %3"
        : "=r" (result)
        : "r" (x), "r" (y), "r" (acc)
    );
    return result;
}

/**
 * @brief Signed Most Significant Word Multiply Accumulate (Rounded)
 * SMMLAR instruction - acc + (((x * y) + 0x80000000) >> 32)
 */
static inline int32_t cm4_smmlar(int32_t x, int32_t y, int32_t acc) {
    int32_t result;
    __asm__ volatile (
        "smmlar %0, %1, %2, %3"
        : "=r" (result)
        : "r" (x), "r" (y), "r" (acc)
    );
    return result;
}

/**
 * @brief Signed Most Significant Word Multiply Subtract
 * SMMLS instruction - acc - ((x * y) >> 32)
 */
static inline int32_t cm4_smmls(int32_t x, int32_t y, int32_t acc) {
    int32_t result;
    __asm__ volatile (
        "smmls %0, %1, %2, %3"
        : "=r" (result)
        : "r" (x), "r" (y), "r" (acc)
    );
    return result;
}

/**
 * @brief Signed Most Significant Word Multiply Subtract (Rounded)
 * SMMLSR instruction - acc - (((x * y) + 0x80000000) >> 32)
 */
static inline int32_t cm4_smmlsr(int32_t x, int32_t y, int32_t acc) {
    int32_t result;
    __asm__ volatile (
        "smmlsr %0, %1, %2, %3"
        : "=r" (result)
        : "r" (x), "r" (y), "r" (acc)
    );
    return result;
}

/**
 * @brief Signed Most Significant Word Multiply
 * SMMUL instruction - (x * y) >> 32
 */
static inline int32_t cm4_smmul(int32_t x, int32_t y) {
    int32_t result;
    __asm__ volatile (
        "smmul %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Signed Most Significant Word Multiply (Rounded)
 * SMMULR instruction - ((x * y) + 0x80000000) >> 32
 */
static inline int32_t cm4_smmulr(int32_t x, int32_t y) {
    int32_t result;
    __asm__ volatile (
        "smmulr %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/*
 * ============================================================================
 * Cortex-M4 Word by Halfword Multiply (ARMv7E-M specific)
 * Reference: Generic User Guide, Section 3.5.75 - 3.5.78
 * ============================================================================
 */

/**
 * @brief Signed Multiply (Word by Bottom Halfword)
 * SMULWB instruction - (x * y[15:0]) >> 16
 */
static inline int32_t cm4_smulwb(int32_t x, int32_t y) {
    int32_t result;
    __asm__ volatile (
        "smulwb %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Signed Multiply (Word by Top Halfword)
 * SMULWT instruction - (x * y[31:16]) >> 16
 */
static inline int32_t cm4_smulwt(int32_t x, int32_t y) {
    int32_t result;
    __asm__ volatile (
        "smulwt %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Signed Multiply Accumulate (Word by Bottom Halfword)
 * SMLAWB instruction - acc + ((x * y[15:0]) >> 16)
 */
static inline int32_t cm4_smlawb(int32_t x, int32_t y, int32_t acc) {
    int32_t result;
    __asm__ volatile (
        "smlawb %0, %1, %2, %3"
        : "=r" (result)
        : "r" (x), "r" (y), "r" (acc)
    );
    return result;
}

/**
 * @brief Signed Multiply Accumulate (Word by Top Halfword)
 * SMLAWT instruction - acc + ((x * y[31:16]) >> 16)
 */
static inline int32_t cm4_smlawt(int32_t x, int32_t y, int32_t acc) {
    int32_t result;
    __asm__ volatile (
        "smlawt %0, %1, %2, %3"
        : "=r" (result)
        : "r" (x), "r" (y), "r" (acc)
    );
    return result;
}

/*
 * ============================================================================
 * Cortex-M4 Saturating Add/Subtract with Exchange (ARMv7E-M specific)
 * Reference: Generic User Guide, Section 3.5.47 - 3.5.50
 * ============================================================================
 */

/**
 * @brief Saturating Add and Subtract with Exchange
 * QASX instruction
 */
static inline int32_t cm4_qasx(int32_t x, int32_t y) {
    int32_t result;
    __asm__ volatile (
        "qasx %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Saturating Subtract and Add with Exchange
 * QSAX instruction
 */
static inline int32_t cm4_qsax(int32_t x, int32_t y) {
    int32_t result;
    __asm__ volatile (
        "qsax %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Signed Halving Add and Subtract with Exchange
 * SHASX instruction
 */
static inline int32_t cm4_shasx(int32_t x, int32_t y) {
    int32_t result;
    __asm__ volatile (
        "shasx %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Signed Halving Subtract and Add with Exchange
 * SHSAX instruction
 */
static inline int32_t cm4_shsax(int32_t x, int32_t y) {
    int32_t result;
    __asm__ volatile (
        "shsax %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Unsigned Saturating Add and Subtract with Exchange
 * UQASX instruction
 */
static inline uint32_t cm4_uqasx(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "uqasx %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Unsigned Saturating Subtract and Add with Exchange
 * UQSAX instruction
 */
static inline uint32_t cm4_uqsax(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "uqsax %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Unsigned Halving Add and Subtract with Exchange
 * UHASX instruction
 */
static inline uint32_t cm4_uhasx(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "uhasx %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Unsigned Halving Subtract and Add with Exchange
 * UHSAX instruction
 */
static inline uint32_t cm4_uhsax(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "uhsax %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/*
 * ============================================================================
 * Cortex-M4 Sum of Absolute Differences (ARMv7E-M specific)
 * Reference: Generic User Guide, Section 3.5.69 - 3.5.70
 * ============================================================================
 */

/**
 * @brief Unsigned Sum of Absolute Differences 8-bit
 * USAD8 instruction
 */
static inline uint32_t cm4_usad8(uint32_t x, uint32_t y) {
    uint32_t result;
    __asm__ volatile (
        "usad8 %0, %1, %2"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

/**
 * @brief Unsigned Sum of Absolute Differences and Accumulate 8-bit
 * USADA8 instruction
 */
static inline uint32_t cm4_usada8(uint32_t x, uint32_t y, uint32_t acc) {
    uint32_t result;
    __asm__ volatile (
        "usada8 %0, %1, %2, %3"
        : "=r" (result)
        : "r" (x), "r" (y), "r" (acc)
    );
    return result;
}

/*
 * ============================================================================
 * Cortex-M4 Unsigned Multiply Accumulate Accumulate Long (ARMv7E-M specific)
 * Reference: Generic User Guide, Section 3.5.71
 * ============================================================================
 */

/**
 * @brief Unsigned Multiply Accumulate Accumulate Long
 * UMAAL instruction
 */
static inline void cm4_umaal(uint32_t x, uint32_t y, uint32_t *hi, uint32_t *lo) {
    __asm__ volatile (
        "umaal %0, %1, %2, %3"
        : "+r" (*lo), "+r" (*hi)
        : "r" (x), "r" (y)
    );
}

#ifdef __cplusplus
}
#endif

#endif /* __CM4_DSP_H__ */
