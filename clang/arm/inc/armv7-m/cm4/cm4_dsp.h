/*
 * ARM Architecture - Cortex-M4 DSP Extensions
 *
 * ============================================================================
 * File: cm4_dsp.h
 * Description: Cortex-M4 DSP instruction inline functions (wrapper for armv7-m_dsp.h)
 * 描述: Cortex-M4 DSP 指令内联函数（armv7-m_dsp.h 的包装层）
 *
 * This file provides CM4-specific naming conventions while delegating
 * all actual definitions to armv7-m_dsp.h.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 3.4 Cortex-M4 DSP instructions
 *
 * Implementation: All functionality is provided by armv7-m/armv7-m_dsp.h
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_DSP_H__
#define __CM4_DSP_H__

#include <stdint.h>

/* Include the underlying ARMv7-M implementation */
#include "armv7-m/armv7-m_dsp.h"

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
 * Implementation: Delegates to dsp_smmla() in armv7-m_dsp.c
 */
static inline int32_t cm4_smmla(int32_t x, int32_t y, int32_t acc)
{
    return dsp_smmla(x, y, acc);
}

/**
 * @brief Signed Most Significant Word Multiply Accumulate (Rounded)
 * SMMLAR instruction - acc + (((x * y) + 0x80000000) >> 32)
 * Implementation: Delegates to dsp_smmlar() in armv7-m_dsp.c
 */
static inline int32_t cm4_smmlar(int32_t x, int32_t y, int32_t acc)
{
    return dsp_smmlar(x, y, acc);
}

/**
 * @brief Signed Most Significant Word Multiply Subtract
 * SMMLS instruction - acc - ((x * y) >> 32)
 * Implementation: Delegates to dsp_smmls() in armv7-m_dsp.c
 */
static inline int32_t cm4_smmls(int32_t x, int32_t y, int32_t acc)
{
    return dsp_smmls(x, y, acc);
}

/**
 * @brief Signed Most Significant Word Multiply Subtract (Rounded)
 * SMMLSR instruction - acc - (((x * y) + 0x80000000) >> 32)
 * Implementation: Delegates to dsp_smmlsr() in armv7-m_dsp.c
 */
static inline int32_t cm4_smmlsr(int32_t x, int32_t y, int32_t acc)
{
    return dsp_smmlsr(x, y, acc);
}

/**
 * @brief Signed Most Significant Word Multiply
 * SMMUL instruction - (x * y) >> 32
 * Implementation: Delegates to dsp_smmul() in armv7-m_dsp.c
 */
static inline int32_t cm4_smmul(int32_t x, int32_t y)
{
    return dsp_smmul(x, y);
}

/**
 * @brief Signed Most Significant Word Multiply (Rounded)
 * SMMULR instruction - ((x * y) + 0x80000000) >> 32
 * Implementation: Delegates to dsp_smmulr() in armv7-m_dsp.c
 */
static inline int32_t cm4_smmulr(int32_t x, int32_t y)
{
    return dsp_smmulr(x, y);
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
 * Implementation: Delegates to dsp_smulwb() in armv7-m_dsp.c
 */
static inline int32_t cm4_smulwb(int32_t x, int32_t y)
{
    return dsp_smulwb(x, y);
}

/**
 * @brief Signed Multiply (Word by Top Halfword)
 * SMULWT instruction - (x * y[31:16]) >> 16
 * Implementation: Delegates to dsp_smulwt() in armv7-m_dsp.c
 */
static inline int32_t cm4_smulwt(int32_t x, int32_t y)
{
    return dsp_smulwt(x, y);
}

/**
 * @brief Signed Multiply Accumulate (Word by Bottom Halfword)
 * SMLAWB instruction - acc + ((x * y[15:0]) >> 16)
 * Implementation: Delegates to dsp_smlawb() in armv7-m_dsp.c
 */
static inline int32_t cm4_smlawb(int32_t x, int32_t y, int32_t acc)
{
    return dsp_smlawb(x, y, acc);
}

/**
 * @brief Signed Multiply Accumulate (Word by Top Halfword)
 * SMLAWT instruction - acc + ((x * y[31:16]) >> 16)
 * Implementation: Delegates to dsp_smlawt() in armv7-m_dsp.c
 */
static inline int32_t cm4_smlawt(int32_t x, int32_t y, int32_t acc)
{
    return dsp_smlawt(x, y, acc);
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
 * Implementation: Delegates to dsp_qasx() in armv7-m_dsp.c
 */
static inline int32_t cm4_qasx(int32_t x, int32_t y)
{
    return dsp_qasx(x, y);
}

/**
 * @brief Saturating Subtract and Add with Exchange
 * QSAX instruction
 * Implementation: Delegates to dsp_qsax() in armv7-m_dsp.c
 */
static inline int32_t cm4_qsax(int32_t x, int32_t y)
{
    return dsp_qsax(x, y);
}

/**
 * @brief Signed Halving Add and Subtract with Exchange
 * SHASX instruction
 * Implementation: Delegates to dsp_shasx() in armv7-m_dsp.c
 */
static inline int32_t cm4_shasx(int32_t x, int32_t y)
{
    return dsp_shasx(x, y);
}

/**
 * @brief Signed Halving Subtract and Add with Exchange
 * SHSAX instruction
 * Implementation: Delegates to dsp_shsax() in armv7-m_dsp.c
 */
static inline int32_t cm4_shsax(int32_t x, int32_t y)
{
    return dsp_shsax(x, y);
}

/**
 * @brief Unsigned Saturating Add and Subtract with Exchange
 * UQASX instruction
 * Implementation: Delegates to dsp_uqasx() in armv7-m_dsp.c
 */
static inline uint32_t cm4_uqasx(uint32_t x, uint32_t y)
{
    return dsp_uqasx(x, y);
}

/**
 * @brief Unsigned Saturating Subtract and Add with Exchange
 * UQSAX instruction
 * Implementation: Delegates to dsp_uqsax() in armv7-m_dsp.c
 */
static inline uint32_t cm4_uqsax(uint32_t x, uint32_t y)
{
    return dsp_uqsax(x, y);
}

/**
 * @brief Unsigned Halving Add and Subtract with Exchange
 * UHASX instruction
 * Implementation: Delegates to dsp_uhasx() in armv7-m_dsp.c
 */
static inline uint32_t cm4_uhasx(uint32_t x, uint32_t y)
{
    return dsp_uhasx(x, y);
}

/**
 * @brief Unsigned Halving Subtract and Add with Exchange
 * UHSAX instruction
 * Implementation: Delegates to dsp_uhsax() in armv7-m_dsp.c
 */
static inline uint32_t cm4_uhsax(uint32_t x, uint32_t y)
{
    return dsp_uhsax(x, y);
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
 * Implementation: Delegates to dsp_usad8() in armv7-m_dsp.c
 */
static inline uint32_t cm4_usad8(uint32_t x, uint32_t y)
{
    return dsp_usad8(x, y);
}

/**
 * @brief Unsigned Sum of Absolute Differences and Accumulate 8-bit
 * USADA8 instruction
 * Implementation: Delegates to dsp_usada8() in armv7-m_dsp.c
 */
static inline uint32_t cm4_usada8(uint32_t x, uint32_t y, uint32_t acc)
{
    return dsp_usada8(x, y, acc);
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
 * Implementation: Delegates to dsp_umaal() in armv7-m_dsp.c
 */
static inline void cm4_umaal(uint32_t x, uint32_t y, uint32_t *hi, uint32_t *lo)
{
    dsp_umaal(x, y, hi, lo);
}

/*
 * ============================================================================
 * Saturating Operations (ARMv7E-M specific)
 * Reference: Generic User Guide, Section 3.5.51 - 3.5.60
 * ============================================================================
 */

/**
 * @brief Signed Saturate
 * SSAT instruction
 * Implementation: Delegates to dsp_ssat() in armv7-m_dsp.c
 */
static inline int32_t cm4_ssat(int32_t value, uint32_t sat)
{
    return dsp_ssat(value, sat);
}

/**
 * @brief Unsigned Saturate
 * USAT instruction
 * Implementation: Delegates to dsp_usat() in armv7-m_dsp.c
 */
static inline int32_t cm4_usat(int32_t value, uint32_t sat)
{
    return dsp_usat(value, sat);
}

/**
 * @brief Signed Saturate 16-bit
 * SSAT16 instruction
 * Implementation: Delegates to dsp_ssat16() in armv7-m_dsp.c
 */
static inline int32_t cm4_ssat16(int32_t value, uint32_t sat)
{
    return dsp_ssat16(value, sat);
}

/**
 * @brief Unsigned Saturate 16-bit
 * USAT16 instruction
 * Implementation: Delegates to dsp_usat16() in armv7-m_dsp.c
 */
static inline int32_t cm4_usat16(int32_t value, uint32_t sat)
{
    return dsp_usat16(value, sat);
}

/**
 * @brief Signed Saturating Add
 * QADD instruction
 * Implementation: Delegates to dsp_qadd() in armv7-m_dsp.c
 */
static inline int32_t cm4_qadd(int32_t x, int32_t y)
{
    return dsp_qadd(x, y);
}

/**
 * @brief Signed Saturating Subtract
 * QSUB instruction
 * Implementation: Delegates to dsp_qsub() in armv7-m_dsp.c
 */
static inline int32_t cm4_qsub(int32_t x, int32_t y)
{
    return dsp_qsub(x, y);
}

/**
 * @brief Signed Saturating Double and Add
 * QDADD instruction
 * Implementation: Delegates to dsp_qdadd() in armv7-m_dsp.c
 */
static inline int32_t cm4_qdadd(int32_t x, int32_t y)
{
    return dsp_qdadd(x, y);
}

/**
 * @brief Signed Saturating Double and Subtract
 * QDSUB instruction
 * Implementation: Delegates to dsp_qdsub() in armv7-m_dsp.c
 */
static inline int32_t cm4_qdsub(int32_t x, int32_t y)
{
    return dsp_qdsub(x, y);
}

/*
 * ============================================================================
 * SIMD Operations (ARMv7E-M specific)
 * Reference: Generic User Guide, Section 3.5.1 - 3.5.46
 * ============================================================================
 */

/**
 * @brief Signed Add 8-bit
 * SADD8 instruction
 * Implementation: Delegates to dsp_sadd8() in armv7-m_dsp.c
 */
static inline uint32_t cm4_sadd8(uint32_t x, uint32_t y)
{
    return dsp_sadd8(x, y);
}

/**
 * @brief Signed Add 16-bit
 * SADD16 instruction
 * Implementation: Delegates to dsp_sadd16() in armv7-m_dsp.c
 */
static inline uint32_t cm4_sadd16(uint32_t x, uint32_t y)
{
    return dsp_sadd16(x, y);
}

/**
 * @brief Unsigned Add 8-bit
 * UADD8 instruction
 * Implementation: Delegates to dsp_uadd8() in armv7-m_dsp.c
 */
static inline uint32_t cm4_uadd8(uint32_t x, uint32_t y)
{
    return dsp_uadd8(x, y);
}

/**
 * @brief Unsigned Add 16-bit
 * UADD16 instruction
 * Implementation: Delegates to dsp_uadd16() in armv7-m_dsp.c
 */
static inline uint32_t cm4_uadd16(uint32_t x, uint32_t y)
{
    return dsp_uadd16(x, y);
}

/**
 * @brief Signed Subtract 8-bit
 * SSUB8 instruction
 * Implementation: Delegates to dsp_ssub8() in armv7-m_dsp.c
 */
static inline uint32_t cm4_ssub8(uint32_t x, uint32_t y)
{
    return dsp_ssub8(x, y);
}

/**
 * @brief Signed Subtract 16-bit
 * SSUB16 instruction
 * Implementation: Delegates to dsp_ssub16() in armv7-m_dsp.c
 */
static inline uint32_t cm4_ssub16(uint32_t x, uint32_t y)
{
    return dsp_ssub16(x, y);
}

/**
 * @brief Unsigned Subtract 8-bit
 * USUB8 instruction
 * Implementation: Delegates to dsp_usub8() in armv7-m_dsp.c
 */
static inline uint32_t cm4_usub8(uint32_t x, uint32_t y)
{
    return dsp_usub8(x, y);
}

/**
 * @brief Unsigned Subtract 16-bit
 * USUB16 instruction
 * Implementation: Delegates to dsp_usub16() in armv7-m_dsp.c
 */
static inline uint32_t cm4_usub16(uint32_t x, uint32_t y)
{
    return dsp_usub16(x, y);
}

#ifdef __cplusplus
}
#endif

#endif /* __CM4_DSP_H__ */
