/*
 * arm_v7m_instr.h
 * Armv7-M Instruction Set Inline Assembly Macros and Functions
 * Reference: ARMv7-M Architecture Reference Manual
 *   - Section A4.4: Data-processing Instructions
 *   - Section A5.2: Load and Store Instructions
 *   - Section A5.4: Load and Store Multiple Instructions
 *   - Section A6.5: Floating-point Instructions
 *   - Section A7.7: Instruction Details
 *
 * This header provides inline assembly macros and static inline functions
 * for all ARMv7-M instructions. It is designed to be a pure header file
 * that can be included without linking.
 */

#ifndef ARM_V7M_INSTR_H
#define ARM_V7M_INSTR_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Helper Macros for Inline Assembly
 * This library only supports Clang/LLVM compiler
 *============================================================================*/

#if defined(__clang__)
    #define ARM_V7M_INLINE static inline __attribute__((always_inline))
#else
    #error "This library requires Clang/LLVM compiler. Please use clang to compile this code."
#endif

/*============================================================================*
 * Bit Manipulation Instructions
 * Reference: Section A7.7 - REV, REV16, REVSH, RBIT, CLZ
 *============================================================================*/

/* Reverse bytes in word */
ARM_V7M_INLINE uint32_t arm_v7m_rev(uint32_t value)
{
    uint32_t result;
    __asm volatile ("REV %0, %1" : "=r" (result) : "r" (value));
    return result;
}

/* Reverse bytes in packed halfwords */
ARM_V7M_INLINE uint32_t arm_v7m_rev16(uint32_t value)
{
    uint32_t result;
    __asm volatile ("REV16 %0, %1" : "=r" (result) : "r" (value));
    return result;
}

/* Reverse bytes in halfword and sign extend */
ARM_V7M_INLINE uint32_t arm_v7m_revsh(uint32_t value)
{
    uint32_t result;
    __asm volatile ("REVSH %0, %1" : "=r" (result) : "r" (value));
    return result;
}

/* Reverse bits */
ARM_V7M_INLINE uint32_t arm_v7m_rbit(uint32_t value)
{
    uint32_t result;
    __asm volatile ("RBIT %0, %1" : "=r" (result) : "r" (value));
    return result;
}

/* Count leading zeros */
ARM_V7M_INLINE uint32_t arm_v7m_clz(uint32_t value)
{
    uint32_t result;
    __asm volatile ("CLZ %0, %1" : "=r" (result) : "r" (value));
    return result;
}

/*============================================================================*
 * Division Instructions
 * Reference: Section A7.7 - SDIV, UDIV
 *============================================================================*/

/* Signed division */
ARM_V7M_INLINE int32_t arm_v7m_sdiv(int32_t dividend, int32_t divisor)
{
    int32_t result;
    __asm volatile ("SDIV %0, %1, %2" : "=r" (result) : "r" (dividend), "r" (divisor));
    return result;
}

/* Unsigned division */
ARM_V7M_INLINE uint32_t arm_v7m_udiv(uint32_t dividend, uint32_t divisor)
{
    uint32_t result;
    __asm volatile ("UDIV %0, %1, %2" : "=r" (result) : "r" (dividend), "r" (divisor));
    return result;
}

/*============================================================================*
 * Exclusive Monitor Operations
 * Reference: Section A7.7 - LDREX, STREX, CLREX
 *============================================================================*/

/* Exclusive load word */
ARM_V7M_INLINE uint32_t arm_v7m_ldrex(uint32_t *addr)
{
    uint32_t result;
    __asm volatile ("LDREX %0, [%1]" : "=r" (result) : "r" (addr));
    return result;
}

/* Exclusive load byte */
ARM_V7M_INLINE uint8_t arm_v7m_ldrexb(uint8_t *addr)
{
    uint8_t result;
    __asm volatile ("LDREXB %0, [%1]" : "=r" (result) : "r" (addr));
    return result;
}

/* Exclusive load halfword */
ARM_V7M_INLINE uint16_t arm_v7m_ldrexh(uint16_t *addr)
{
    uint16_t result;
    __asm volatile ("LDREXH %0, [%1]" : "=r" (result) : "r" (addr));
    return result;
}

/* Exclusive store word - returns 0 on success, 1 on failure */
ARM_V7M_INLINE int arm_v7m_strex(uint32_t value, uint32_t *addr)
{
    int result;
    __asm volatile ("STREX %0, %2, [%1]" : "=r" (result) : "r" (addr), "r" (value));
    return result;
}

/* Exclusive store byte - returns 0 on success, 1 on failure */
ARM_V7M_INLINE int arm_v7m_strexb(uint8_t value, uint8_t *addr)
{
    int result;
    __asm volatile ("STREXB %0, %2, [%1]" : "=r" (result) : "r" (addr), "r" (value));
    return result;
}

/* Exclusive store halfword - returns 0 on success, 1 on failure */
ARM_V7M_INLINE int arm_v7m_strexh(uint16_t value, uint16_t *addr)
{
    int result;
    __asm volatile ("STREXH %0, %2, [%1]" : "=r" (result) : "r" (addr), "r" (value));
    return result;
}

/* Clear exclusive monitor */
ARM_V7M_INLINE void arm_v7m_clrex(void)
{
    __asm volatile ("CLREX" : : : "memory");
}

/*============================================================================*
 * Saturating Arithmetic Instructions
 * Reference: Section A7.7 - SSAT, USAT, SSAT16, USAT16, QADD, QSUB
 *============================================================================*/

/* Signed Saturate - saturates to signed range -(2^(sat-1)) to +(2^(sat-1)-1) */
ARM_V7M_INLINE int32_t arm_v7m_ssat(int32_t value, uint32_t sat)
{
    int32_t result;
    __asm volatile ("SSAT %0, %1, %2" : "=r" (result) : "i" (sat), "r" (value));
    return result;
}

/* Unsigned Saturate - saturates to unsigned range 0 to (2^sat - 1) */
ARM_V7M_INLINE uint32_t arm_v7m_usat(int32_t value, uint32_t sat)
{
    uint32_t result;
    __asm volatile ("USAT %0, %1, %2" : "=r" (result) : "i" (sat), "r" (value));
    return result;
}

/* Signed Saturate 16 - saturates two 16-bit values */
ARM_V7M_INLINE int32_t arm_v7m_ssat16(int32_t value, uint32_t sat)
{
    int32_t result;
    __asm volatile ("SSAT16 %0, %1, %2" : "=r" (result) : "i" (sat), "r" (value));
    return result;
}

/* Unsigned Saturate 16 - saturates two 16-bit values */
ARM_V7M_INLINE uint32_t arm_v7m_usat16(int32_t value, uint32_t sat)
{
    uint32_t result;
    __asm volatile ("USAT16 %0, %1, %2" : "=r" (result) : "i" (sat), "r" (value));
    return result;
}

/* Saturating Add - adds two signed 32-bit integers with saturation */
ARM_V7M_INLINE int32_t arm_v7m_qadd(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("QADD %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Saturating Subtract - subtracts two signed 32-bit integers with saturation */
ARM_V7M_INLINE int32_t arm_v7m_qsub(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("QSUB %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/*============================================================================*
 * Sign/Zero Extension Instructions
 * Reference: Section A7.7 - SXTB, SXTH, UXTB, UXTH, SXTB16, UXTB16
 *============================================================================*/

/* Sign Extend Byte - extends 8-bit to 32-bit with sign */
ARM_V7M_INLINE int32_t arm_v7m_sxtb(int32_t value)
{
    int32_t result;
    __asm volatile ("SXTB %0, %1" : "=r" (result) : "r" (value));
    return result;
}

/* Sign Extend Halfword - extends 16-bit to 32-bit with sign */
ARM_V7M_INLINE int32_t arm_v7m_sxth(int32_t value)
{
    int32_t result;
    __asm volatile ("SXTH %0, %1" : "=r" (result) : "r" (value));
    return result;
}

/* Zero Extend Byte - extends 8-bit to 32-bit with zero */
ARM_V7M_INLINE uint32_t arm_v7m_uxtb(uint32_t value)
{
    uint32_t result;
    __asm volatile ("UXTB %0, %1" : "=r" (result) : "r" (value));
    return result;
}

/* Zero Extend Halfword - extends 16-bit to 32-bit with zero */
ARM_V7M_INLINE uint32_t arm_v7m_uxth(uint32_t value)
{
    uint32_t result;
    __asm volatile ("UXTH %0, %1" : "=r" (result) : "r" (value));
    return result;
}

/* Sign Extend Bytes to 16 - sign extends two bytes to two 16-bit halfwords */
ARM_V7M_INLINE int32_t arm_v7m_sxtb16(int32_t value)
{
    int32_t result;
    __asm volatile ("SXTB16 %0, %1" : "=r" (result) : "r" (value));
    return result;
}

/* Zero Extend Bytes to 16 - zero extends two bytes to two 16-bit halfwords */
ARM_V7M_INLINE uint32_t arm_v7m_uxtb16(uint32_t value)
{
    uint32_t result;
    __asm volatile ("UXTB16 %0, %1" : "=r" (result) : "r" (value));
    return result;
}

/*============================================================================*
 * Bit-field Instructions
 * Reference: Section A7.7 - BFC, BFI, SBFX, UBFX
 *============================================================================*/

/* Bit Field Clear - clears bits from lsb to lsb+width-1 */
ARM_V7M_INLINE uint32_t arm_v7m_bfc(uint32_t value, uint32_t lsb, uint32_t width)
{
    uint32_t result = value;
    __asm volatile ("BFC %0, %1, %2" : "+r" (result) : "i" (lsb), "i" (width));
    return result;
}

/* Bit Field Insert - inserts bits from src into dest at position lsb */
ARM_V7M_INLINE uint32_t arm_v7m_bfi(uint32_t dest, uint32_t src, uint32_t lsb, uint32_t width)
{
    uint32_t result = dest;
    __asm volatile ("BFI %0, %1, %2, %3" : "+r" (result) : "r" (src), "i" (lsb), "i" (width));
    return result;
}

/* Signed Bit Field Extract - extracts width bits from lsb with sign extension */
ARM_V7M_INLINE int32_t arm_v7m_sbfx(int32_t value, uint32_t lsb, uint32_t width)
{
    int32_t result;
    __asm volatile ("SBFX %0, %1, %2, %3" : "=r" (result) : "r" (value), "i" (lsb), "i" (width));
    return result;
}

/* Unsigned Bit Field Extract - extracts width bits from lsb with zero extension */
ARM_V7M_INLINE uint32_t arm_v7m_ubfx(uint32_t value, uint32_t lsb, uint32_t width)
{
    uint32_t result;
    __asm volatile ("UBFX %0, %1, %2, %3" : "=r" (result) : "r" (value), "i" (lsb), "i" (width));
    return result;
}

/*============================================================================*
 * Multiply-Accumulate Instructions
 * Reference: Section A7.7 - MLA, MLS
 *============================================================================*/

/* Multiply and Accumulate - result = a + (b * c) */
ARM_V7M_INLINE int32_t arm_v7m_mla(int32_t a, int32_t b, int32_t c)
{
    int32_t result;
    __asm volatile ("MLA %0, %1, %2, %3" : "=r" (result) : "r" (b), "r" (c), "r" (a));
    return result;
}

/* Multiply and Subtract - result = a - (b * c) */
ARM_V7M_INLINE int32_t arm_v7m_mls(int32_t a, int32_t b, int32_t c)
{
    int32_t result;
    __asm volatile ("MLS %0, %1, %2, %3" : "=r" (result) : "r" (b), "r" (c), "r" (a));
    return result;
}

/*============================================================================*
 * Shift and Rotate Instructions
 * Reference: Section A7.7 - LSL, LSR, ASR, ROR, RRX
 *============================================================================*/

/* Logical Shift Left */
ARM_V7M_INLINE uint32_t arm_v7m_lsl(uint32_t value, uint32_t shift)
{
    uint32_t result;
    __asm volatile ("LSL %0, %1, %2" : "=r" (result) : "r" (value), "r" (shift));
    return result;
}

/* Logical Shift Right */
ARM_V7M_INLINE uint32_t arm_v7m_lsr(uint32_t value, uint32_t shift)
{
    uint32_t result;
    __asm volatile ("LSR %0, %1, %2" : "=r" (result) : "r" (value), "r" (shift));
    return result;
}

/* Arithmetic Shift Right */
ARM_V7M_INLINE int32_t arm_v7m_asr(int32_t value, uint32_t shift)
{
    int32_t result;
    __asm volatile ("ASR %0, %1, %2" : "=r" (result) : "r" (value), "r" (shift));
    return result;
}

/* Rotate Right */
ARM_V7M_INLINE uint32_t arm_v7m_ror(uint32_t value, uint32_t shift)
{
    uint32_t result;
    __asm volatile ("ROR %0, %1, %2" : "=r" (result) : "r" (value), "r" (shift));
    return result;
}

/* Rotate Right with Extend (includes carry bit) */
ARM_V7M_INLINE uint32_t arm_v7m_rrx(uint32_t value)
{
    uint32_t result;
    __asm volatile ("RRX %0, %1" : "=r" (result) : "r" (value));
    return result;
}

/*============================================================================*
 * Long Multiply Instructions
 * Reference: Section A7.7 - SMULL, UMULL, SMLAL, UMLAL, UMAAL
 *============================================================================*/

/* Signed Long Multiply - 64-bit result of a * b */
ARM_V7M_INLINE int64_t arm_v7m_smull(int32_t a, int32_t b)
{
    int32_t lo, hi;
    __asm volatile ("SMULL %0, %1, %2, %3" : "=r" (lo), "=r" (hi) : "r" (a), "r" (b));
    return ((int64_t)hi << 32) | (uint32_t)lo;
}

/* Unsigned Long Multiply - 64-bit result of a * b */
ARM_V7M_INLINE uint64_t arm_v7m_umull(uint32_t a, uint32_t b)
{
    uint32_t lo, hi;
    __asm volatile ("UMULL %0, %1, %2, %3" : "=r" (lo), "=r" (hi) : "r" (a), "r" (b));
    return ((uint64_t)hi << 32) | lo;
}

/* Signed Multiply-Accumulate Long - 64-bit accumulate */
ARM_V7M_INLINE int64_t arm_v7m_smlal(int64_t acc, int32_t a, int32_t b)
{
    int32_t lo = (int32_t)acc;
    int32_t hi = (int32_t)(acc >> 32);
    __asm volatile ("SMLAL %0, %1, %2, %3" : "+r" (lo), "+r" (hi) : "r" (a), "r" (b));
    return ((int64_t)hi << 32) | (uint32_t)lo;
}

/* Unsigned Multiply-Accumulate Long - 64-bit accumulate */
ARM_V7M_INLINE uint64_t arm_v7m_umlal(uint64_t acc, uint32_t a, uint32_t b)
{
    uint32_t lo = (uint32_t)acc;
    uint32_t hi = (uint32_t)(acc >> 32);
    __asm volatile ("UMLAL %0, %1, %2, %3" : "+r" (lo), "+r" (hi) : "r" (a), "r" (b));
    return ((uint64_t)hi << 32) | lo;
}

/* Unsigned Multiply-Accumulate Accumulate Long - acc = acc + (a * b) + lo */
ARM_V7M_INLINE uint64_t arm_v7m_umaal(uint32_t a, uint32_t b, uint32_t *lo_inout, uint32_t *hi_inout)
{
    uint32_t lo = *lo_inout;
    uint32_t hi = *hi_inout;
    __asm volatile ("UMAAL %0, %1, %2, %3" : "+r" (lo), "+r" (hi) : "r" (a), "r" (b));
    *lo_inout = lo;
    *hi_inout = hi;
    return ((uint64_t)hi << 32) | lo;
}

/*============================================================================*
 * SIMD Parallel Add/Subtract Instructions
 * Reference: Section A7.7 - SADD16, SSUB16, SADD8, SSUB8, UADD16, USUB16, UADD8, USUB8
 *============================================================================*/

/* Signed Add 16 - two 16-bit additions in parallel */
ARM_V7M_INLINE int32_t arm_v7m_sadd16(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SADD16 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Signed Subtract 16 - two 16-bit subtractions in parallel */
ARM_V7M_INLINE int32_t arm_v7m_ssub16(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SSUB16 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Signed Add 8 - four 8-bit additions in parallel */
ARM_V7M_INLINE int32_t arm_v7m_sadd8(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SADD8 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Signed Subtract 8 - four 8-bit subtractions in parallel */
ARM_V7M_INLINE int32_t arm_v7m_ssub8(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SSUB8 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Unsigned Add 16 - two 16-bit additions in parallel */
ARM_V7M_INLINE uint32_t arm_v7m_uadd16(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("UADD16 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Unsigned Subtract 16 - two 16-bit subtractions in parallel */
ARM_V7M_INLINE uint32_t arm_v7m_usub16(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("USUB16 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Unsigned Add 8 - four 8-bit additions in parallel */
ARM_V7M_INLINE uint32_t arm_v7m_uadd8(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("UADD8 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Unsigned Subtract 8 - four 8-bit subtractions in parallel */
ARM_V7M_INLINE uint32_t arm_v7m_usub8(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("USUB8 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/*============================================================================*
 * Saturating SIMD Instructions
 * Reference: Section A7.7 - QADD16, QSUB16, QADD8, QSUB8, UQADD16, UQSUB16, UQADD8, UQSUB8
 *============================================================================*/

/* Saturating Signed Add 16 - two 16-bit additions with saturation */
ARM_V7M_INLINE int32_t arm_v7m_qadd16(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("QADD16 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Saturating Signed Subtract 16 - two 16-bit subtractions with saturation */
ARM_V7M_INLINE int32_t arm_v7m_qsub16(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("QSUB16 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Saturating Signed Add 8 - four 8-bit additions with saturation */
ARM_V7M_INLINE int32_t arm_v7m_qadd8(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("QADD8 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Saturating Signed Subtract 8 - four 8-bit subtractions with saturation */
ARM_V7M_INLINE int32_t arm_v7m_qsub8(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("QSUB8 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Saturating Unsigned Add 16 - two 16-bit additions with saturation */
ARM_V7M_INLINE uint32_t arm_v7m_uqadd16(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("UQADD16 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Saturating Unsigned Subtract 16 - two 16-bit subtractions with saturation */
ARM_V7M_INLINE uint32_t arm_v7m_uqsub16(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("UQSUB16 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Saturating Unsigned Add 8 - four 8-bit additions with saturation */
ARM_V7M_INLINE uint32_t arm_v7m_uqadd8(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("UQADD8 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Saturating Unsigned Subtract 8 - four 8-bit subtractions with saturation */
ARM_V7M_INLINE uint32_t arm_v7m_uqsub8(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("UQSUB8 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/*============================================================================*
 * Halving SIMD Instructions
 * Reference: Section A7.7 - SHADD16, SHSUB16, SHADD8, SHSUB8, UHADD16, UHSUB16, UHADD8, UHSUB8
 *============================================================================*/

/* Signed Halving Add 16 - two 16-bit additions, result halved */
ARM_V7M_INLINE int32_t arm_v7m_shadd16(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SHADD16 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Signed Halving Subtract 16 - two 16-bit subtractions, result halved */
ARM_V7M_INLINE int32_t arm_v7m_shsub16(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SHSUB16 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Signed Halving Add 8 - four 8-bit additions, result halved */
ARM_V7M_INLINE int32_t arm_v7m_shadd8(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SHADD8 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Signed Halving Subtract 8 - four 8-bit subtractions, result halved */
ARM_V7M_INLINE int32_t arm_v7m_shsub8(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SHSUB8 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Unsigned Halving Add 16 - two 16-bit additions, result halved */
ARM_V7M_INLINE uint32_t arm_v7m_uhadd16(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("UHADD16 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Unsigned Halving Subtract 16 - two 16-bit subtractions, result halved */
ARM_V7M_INLINE uint32_t arm_v7m_uhsub16(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("UHSUB16 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Unsigned Halving Add 8 - four 8-bit additions, result halved */
ARM_V7M_INLINE uint32_t arm_v7m_uhadd8(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("UHADD8 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Unsigned Halving Subtract 8 - four 8-bit subtractions, result halved */
ARM_V7M_INLINE uint32_t arm_v7m_uhsub8(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("UHSUB8 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/*============================================================================*
 * Pack Halfword Instructions
 * Reference: Section A7.7 - PKHBT, PKHTB
 *============================================================================*/

/* Pack Halfword Bottom Top - packs bottom halfword of a with top halfword of b */
ARM_V7M_INLINE uint32_t arm_v7m_pkhbt(uint32_t a, uint32_t b, uint32_t shift)
{
    uint32_t result;
    __asm volatile ("PKHBT %0, %1, %2, LSL %3" : "=r" (result) : "r" (a), "r" (b), "i" (shift));
    return result;
}

/* Pack Halfword Top Bottom - packs top halfword of a with bottom halfword of b */
ARM_V7M_INLINE uint32_t arm_v7m_pkhtb(uint32_t a, uint32_t b, uint32_t shift)
{
    uint32_t result;
    __asm volatile ("PKHTB %0, %1, %2, ASR %3" : "=r" (result) : "r" (a), "r" (b), "i" (shift));
    return result;
}

/*============================================================================*
 * Signed Multiply (Halfword) Instructions
 * Reference: Section A7.7 - SMULBB, SMULBT, SMULTB, SMULTT
 *============================================================================*/

/* Signed Multiply Bottom Bottom - multiplies bottom halfwords */
ARM_V7M_INLINE int32_t arm_v7m_smulbb(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMULBB %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Signed Multiply Bottom Top - multiplies bottom halfword of a with top halfword of b */
ARM_V7M_INLINE int32_t arm_v7m_smulbt(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMULBT %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Signed Multiply Top Bottom - multiplies top halfword of a with bottom halfword of b */
ARM_V7M_INLINE int32_t arm_v7m_smultb(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMULTB %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Signed Multiply Top Top - multiplies top halfwords */
ARM_V7M_INLINE int32_t arm_v7m_smultt(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMULTT %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/*============================================================================*
 * Signed Multiply (Word x Halfword) Instructions
 * Reference: Section A7.7 - SMULWB, SMULWT
 *============================================================================*/

/* Signed Multiply Word Bottom - multiplies word with bottom halfword */
ARM_V7M_INLINE int32_t arm_v7m_smulwb(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMULWB %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Signed Multiply Word Top - multiplies word with top halfword */
ARM_V7M_INLINE int32_t arm_v7m_smulwt(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMULWT %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/*============================================================================*
 * Signed Dual Multiply-Add Instructions
 * Reference: Section A7.7 - SMUAD, SMUADX, SMUSD, SMUSDX
 *============================================================================*/

/* Signed Dual Multiply-Add - multiplies and adds two 16-bit pairs */
ARM_V7M_INLINE int32_t arm_v7m_smuad(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMUAD %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Signed Dual Multiply-Add Exchange - multiplies with exchange and adds */
ARM_V7M_INLINE int32_t arm_v7m_smuadx(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMUADX %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Signed Dual Multiply-Subtract - multiplies and subtracts two 16-bit pairs */
ARM_V7M_INLINE int32_t arm_v7m_smusd(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMUSD %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Signed Dual Multiply-Subtract Exchange - multiplies with exchange and subtracts */
ARM_V7M_INLINE int32_t arm_v7m_smusdx(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMUSDX %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/*============================================================================*
 * Signed Multiply-Accumulate (Halfword) Instructions
 * Reference: Section A7.7 - SMLABB, SMLABT, SMLATB, SMLATT
 *============================================================================*/

/* Signed Multiply-Accumulate Bottom Bottom */
ARM_V7M_INLINE int32_t arm_v7m_smlabb(int32_t acc, int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMLABB %0, %1, %2, %3" : "=r" (result) : "r" (a), "r" (b), "r" (acc));
    return result;
}

/* Signed Multiply-Accumulate Bottom Top */
ARM_V7M_INLINE int32_t arm_v7m_smlabt(int32_t acc, int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMLABT %0, %1, %2, %3" : "=r" (result) : "r" (a), "r" (b), "r" (acc));
    return result;
}

/* Signed Multiply-Accumulate Top Bottom */
ARM_V7M_INLINE int32_t arm_v7m_smlatb(int32_t acc, int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMLATB %0, %1, %2, %3" : "=r" (result) : "r" (a), "r" (b), "r" (acc));
    return result;
}

/* Signed Multiply-Accumulate Top Top */
ARM_V7M_INLINE int32_t arm_v7m_smlatt(int32_t acc, int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMLATT %0, %1, %2, %3" : "=r" (result) : "r" (a), "r" (b), "r" (acc));
    return result;
}

/*============================================================================*
 * Signed Multiply-Accumulate (Word x Halfword) Instructions
 * Reference: Section A7.7 - SMLAWB, SMLAWT
 *============================================================================*/

/* Signed Multiply-Accumulate Word Bottom */
ARM_V7M_INLINE int32_t arm_v7m_smlawb(int32_t acc, int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMLAWB %0, %1, %2, %3" : "=r" (result) : "r" (a), "r" (b), "r" (acc));
    return result;
}

/* Signed Multiply-Accumulate Word Top */
ARM_V7M_INLINE int32_t arm_v7m_smlawt(int32_t acc, int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMLAWT %0, %1, %2, %3" : "=r" (result) : "r" (a), "r" (b), "r" (acc));
    return result;
}

/*============================================================================*
 * Signed Dual Multiply-Accumulate Instructions
 * Reference: Section A7.7 - SMLAD, SMLADX, SMLALD, SMLALDX
 *============================================================================*/

/* Signed Dual Multiply-Accumulate */
ARM_V7M_INLINE int32_t arm_v7m_smlad(int32_t acc, int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMLAD %0, %1, %2, %3" : "=r" (result) : "r" (a), "r" (b), "r" (acc));
    return result;
}

/* Signed Dual Multiply-Accumulate Exchange */
ARM_V7M_INLINE int32_t arm_v7m_smladx(int32_t acc, int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMLADX %0, %1, %2, %3" : "=r" (result) : "r" (a), "r" (b), "r" (acc));
    return result;
}

/* Signed Dual Multiply-Accumulate Long */
ARM_V7M_INLINE int64_t arm_v7m_smlald(int64_t acc, int32_t a, int32_t b)
{
    int32_t lo = (int32_t)acc;
    int32_t hi = (int32_t)(acc >> 32);
    __asm volatile ("SMLALD %0, %1, %2, %3" : "+r" (lo), "+r" (hi) : "r" (a), "r" (b));
    return ((int64_t)hi << 32) | (uint32_t)lo;
}

/* Signed Dual Multiply-Accumulate Long Exchange */
ARM_V7M_INLINE int64_t arm_v7m_smlaldx(int64_t acc, int32_t a, int32_t b)
{
    int32_t lo = (int32_t)acc;
    int32_t hi = (int32_t)(acc >> 32);
    __asm volatile ("SMLALDX %0, %1, %2, %3" : "+r" (lo), "+r" (hi) : "r" (a), "r" (b));
    return ((int64_t)hi << 32) | (uint32_t)lo;
}

/*============================================================================*
 * Signed Dual Multiply-Subtract Instructions
 * Reference: Section A7.7 - SMLSD, SMLSDX, SMLSLD, SMLSLDX
 *============================================================================*/

/* Signed Dual Multiply-Subtract */
ARM_V7M_INLINE int32_t arm_v7m_smlsd(int32_t acc, int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMLSD %0, %1, %2, %3" : "=r" (result) : "r" (a), "r" (b), "r" (acc));
    return result;
}

/* Signed Dual Multiply-Subtract Exchange */
ARM_V7M_INLINE int32_t arm_v7m_smlsdx(int32_t acc, int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMLSDX %0, %1, %2, %3" : "=r" (result) : "r" (a), "r" (b), "r" (acc));
    return result;
}

/* Signed Dual Multiply-Subtract Long */
ARM_V7M_INLINE int64_t arm_v7m_smlsld(int64_t acc, int32_t a, int32_t b)
{
    int32_t lo = (int32_t)acc;
    int32_t hi = (int32_t)(acc >> 32);
    __asm volatile ("SMLSLD %0, %1, %2, %3" : "+r" (lo), "+r" (hi) : "r" (a), "r" (b));
    return ((int64_t)hi << 32) | (uint32_t)lo;
}

/* Signed Dual Multiply-Subtract Long Exchange */
ARM_V7M_INLINE int64_t arm_v7m_smlsldx(int64_t acc, int32_t a, int32_t b)
{
    int32_t lo = (int32_t)acc;
    int32_t hi = (int32_t)(acc >> 32);
    __asm volatile ("SMLSLDX %0, %1, %2, %3" : "+r" (lo), "+r" (hi) : "r" (a), "r" (b));
    return ((int64_t)hi << 32) | (uint32_t)lo;
}

/*============================================================================*
 * Signed Most Significant Word Multiply Instructions
 * Reference: Section A7.7 - SMMUL, SMMULR, SMMLA, SMMLAR, SMMLS, SMMLSR
 *============================================================================*/

/* Signed Most Significant Word Multiply - returns top 32 bits of 64-bit result */
ARM_V7M_INLINE int32_t arm_v7m_smmul(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMMUL %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Signed Most Significant Word Multiply Rounded */
ARM_V7M_INLINE int32_t arm_v7m_smmulr(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMMULR %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Signed Most Significant Word Multiply-Accumulate */
ARM_V7M_INLINE int32_t arm_v7m_smmla(int32_t acc, int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMMLA %0, %1, %2, %3" : "=r" (result) : "r" (a), "r" (b), "r" (acc));
    return result;
}

/* Signed Most Significant Word Multiply-Accumulate Rounded */
ARM_V7M_INLINE int32_t arm_v7m_smmlar(int32_t acc, int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMMLAR %0, %1, %2, %3" : "=r" (result) : "r" (a), "r" (b), "r" (acc));
    return result;
}

/* Signed Most Significant Word Multiply-Subtract */
ARM_V7M_INLINE int32_t arm_v7m_smmls(int32_t acc, int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMMLS %0, %1, %2, %3" : "=r" (result) : "r" (a), "r" (b), "r" (acc));
    return result;
}

/* Signed Most Significant Word Multiply-Subtract Rounded */
ARM_V7M_INLINE int32_t arm_v7m_smmlsr(int32_t acc, int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SMMLSR %0, %1, %2, %3" : "=r" (result) : "r" (a), "r" (b), "r" (acc));
    return result;
}

/*============================================================================*
 * Select and Sum of Absolute Differences Instructions
 * Reference: Section A7.7 - SEL, USAD8, USADA8
 *============================================================================*/

/* Select - selects bytes from a or b based on GE flags */
ARM_V7M_INLINE uint32_t arm_v7m_sel(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("SEL %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Unsigned Sum of Absolute Differences 8 - sums absolute differences of 4 bytes */
ARM_V7M_INLINE uint32_t arm_v7m_usad8(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("USAD8 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Unsigned Sum of Absolute Differences and Accumulate 8 */
ARM_V7M_INLINE uint32_t arm_v7m_usada8(uint32_t acc, uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("USADA8 %0, %1, %2, %3" : "=r" (result) : "r" (a), "r" (b), "r" (acc));
    return result;
}

/*============================================================================*
 * Basic Arithmetic Instructions
 * Reference: Section A7.7 - ADC, ADCS, SBC, SBCS, RSB, RSBS
 *============================================================================*/

/* Add with Carry - result = a + b + C flag */
ARM_V7M_INLINE uint32_t arm_v7m_adc(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("ADC %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Add with Carry and Set flags */
ARM_V7M_INLINE uint32_t arm_v7m_adcs(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("ADCS %0, %1, %2" : "=r" (result) : "r" (a), "r" (b) : "cc");
    return result;
}

/* Subtract with Carry - result = a - b - NOT(C flag) */
ARM_V7M_INLINE uint32_t arm_v7m_sbc(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("SBC %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Subtract with Carry and Set flags */
ARM_V7M_INLINE uint32_t arm_v7m_sbcs(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("SBCS %0, %1, %2" : "=r" (result) : "r" (a), "r" (b) : "cc");
    return result;
}

/* Reverse Subtract - result = b - a */
ARM_V7M_INLINE uint32_t arm_v7m_rsb(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("RSB %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Reverse Subtract and Set flags */
ARM_V7M_INLINE uint32_t arm_v7m_rsbs(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("RSBS %0, %1, %2" : "=r" (result) : "r" (a), "r" (b) : "cc");
    return result;
}

/*============================================================================*
 * Basic Logical Instructions
 * Reference: Section A7.7 - AND, ANDS, ORR, ORRS, EOR, EORS, BIC, BICS, ORN, ORNS
 *============================================================================*/

/* Bitwise AND */
ARM_V7M_INLINE uint32_t arm_v7m_and(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("AND %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Bitwise AND and Set flags */
ARM_V7M_INLINE uint32_t arm_v7m_ands(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("ANDS %0, %1, %2" : "=r" (result) : "r" (a), "r" (b) : "cc");
    return result;
}

/* Bitwise OR */
ARM_V7M_INLINE uint32_t arm_v7m_orr(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("ORR %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Bitwise OR and Set flags */
ARM_V7M_INLINE uint32_t arm_v7m_orrs(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("ORRS %0, %1, %2" : "=r" (result) : "r" (a), "r" (b) : "cc");
    return result;
}

/* Bitwise Exclusive OR */
ARM_V7M_INLINE uint32_t arm_v7m_eor(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("EOR %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Bitwise Exclusive OR and Set flags */
ARM_V7M_INLINE uint32_t arm_v7m_eors(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("EORS %0, %1, %2" : "=r" (result) : "r" (a), "r" (b) : "cc");
    return result;
}

/* Bit Clear - a AND NOT b */
ARM_V7M_INLINE uint32_t arm_v7m_bic(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("BIC %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Bit Clear and Set flags */
ARM_V7M_INLINE uint32_t arm_v7m_bics(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("BICS %0, %1, %2" : "=r" (result) : "r" (a), "r" (b) : "cc");
    return result;
}

/* Bitwise OR NOT - a OR NOT b */
ARM_V7M_INLINE uint32_t arm_v7m_orn(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("ORN %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Bitwise OR NOT and Set flags */
ARM_V7M_INLINE uint32_t arm_v7m_orns(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("ORNS %0, %1, %2" : "=r" (result) : "r" (a), "r" (b) : "cc");
    return result;
}

/*============================================================================*
 * Compare Instructions
 * Reference: Section A7.7 - CMP, CMN
 *============================================================================*/

/* Compare - sets flags based on a - b */
ARM_V7M_INLINE void arm_v7m_cmp(uint32_t a, uint32_t b)
{
    __asm volatile ("CMP %0, %1" : : "r" (a), "r" (b) : "cc");
}

/* Compare Negative - sets flags based on a + b */
ARM_V7M_INLINE void arm_v7m_cmn(uint32_t a, uint32_t b)
{
    __asm volatile ("CMN %0, %1" : : "r" (a), "r" (b) : "cc");
}

/*============================================================================*
 * Test Instructions
 * Reference: Section A7.7 - TST, TEQ
 *============================================================================*/

/* Test - sets flags based on a AND b */
ARM_V7M_INLINE void arm_v7m_tst(uint32_t a, uint32_t b)
{
    __asm volatile ("TST %0, %1" : : "r" (a), "r" (b) : "cc");
}

/* Test Equivalence - sets flags based on a EOR b */
ARM_V7M_INLINE void arm_v7m_teq(uint32_t a, uint32_t b)
{
    __asm volatile ("TEQ %0, %1" : : "r" (a), "r" (b) : "cc");
}

/*============================================================================*
 * Move Instructions
 * Reference: Section A7.7 - MOV, MOVS, MVN, MVNS
 *============================================================================*/

/* Move - copies value to result */
ARM_V7M_INLINE uint32_t arm_v7m_mov(uint32_t value)
{
    uint32_t result;
    __asm volatile ("MOV %0, %1" : "=r" (result) : "r" (value));
    return result;
}

/* Move and Set flags */
ARM_V7M_INLINE uint32_t arm_v7m_movs(uint32_t value)
{
    uint32_t result;
    __asm volatile ("MOVS %0, %1" : "=r" (result) : "r" (value) : "cc");
    return result;
}

/* Move NOT - copies bitwise NOT of value to result */
ARM_V7M_INLINE uint32_t arm_v7m_mvn(uint32_t value)
{
    uint32_t result;
    __asm volatile ("MVN %0, %1" : "=r" (result) : "r" (value));
    return result;
}

/* Move NOT and Set flags */
ARM_V7M_INLINE uint32_t arm_v7m_mvns(uint32_t value)
{
    uint32_t result;
    __asm volatile ("MVNS %0, %1" : "=r" (result) : "r" (value) : "cc");
    return result;
}

/*============================================================================*
 * Multiply Instructions
 * Reference: Section A7.7 - MUL, MULS
 *============================================================================*/

/* Multiply - 32-bit result of a * b */
ARM_V7M_INLINE uint32_t arm_v7m_mul(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("MUL %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Multiply and Set flags */
ARM_V7M_INLINE uint32_t arm_v7m_muls(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("MULS %0, %1, %2" : "=r" (result) : "r" (a), "r" (b) : "cc");
    return result;
}

/*============================================================================*
 * Branch Instructions
 * Reference: Section A7.7 - BX, BLX
 *============================================================================*/

/* Branch and Exchange - branches to address in register, changes to Thumb mode */
ARM_V7M_INLINE void arm_v7m_bx(void *addr)
{
    __asm volatile ("BX %0" : : "r" (addr));
}

/* Branch with Link and Exchange - branches to address, saves return address */
ARM_V7M_INLINE void arm_v7m_blx(void *addr)
{
    __asm volatile ("BLX %0" : : "r" (addr));
}

/*============================================================================*
 * Table Branch Instructions
 * Reference: Section A7.7 - TBB, TBH
 *============================================================================*/

/* Table Branch Byte - branch using byte offset table */
ARM_V7M_INLINE void arm_v7m_tbb(uint8_t *table, uint32_t index)
{
    __asm volatile ("TBB [%0, %1]" : : "r" (table), "r" (index));
}

/* Table Branch Halfword - branch using halfword offset table */
ARM_V7M_INLINE void arm_v7m_tbh(uint16_t *table, uint32_t index)
{
    __asm volatile ("TBH [%0, %1, LSL #1]" : : "r" (table), "r" (index));
}

/*============================================================================*
 * Speculative Execution Barrier Instructions
 * Reference: Section A7.7 - CSDB, SSBB, PSSBB
 *============================================================================*/

/* Consumption of Speculative Data Barrier */
ARM_V7M_INLINE void arm_v7m_csdb(void)
{
    __asm volatile ("CSDB" : : : "memory");
}

/* Speculative Store Bypass Barrier */
ARM_V7M_INLINE void arm_v7m_ssbb(void)
{
    __asm volatile ("SSBB" : : : "memory");
}

/* Physical Speculative Store Bypass Barrier */
ARM_V7M_INLINE void arm_v7m_pssbb(void)
{
    __asm volatile ("PSSBB" : : : "memory");
}

/*============================================================================*
 * Memory Prefetch Instructions
 * Reference: Section A7.7 - PLD, PLI
 *============================================================================*/

/* Preload Data - hints to prefetch data from memory */
ARM_V7M_INLINE void arm_v7m_pld(void *addr)
{
    __asm volatile ("PLD [%0]" : : "r" (addr));
}

/* Preload Instruction - hints to prefetch instruction from memory */
ARM_V7M_INLINE void arm_v7m_pli(void *addr)
{
    __asm volatile ("PLI [%0]" : : "r" (addr));
}

/*============================================================================*
 * SIMD Exchange Add/Subtract Instructions
 * Reference: Section A7.7 - SASX, SSAX, UASX, USAX
 *============================================================================*/

/* Signed Add Subtract Exchange - exchanges halfwords then adds/subtracts */
ARM_V7M_INLINE int32_t arm_v7m_sasx(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SASX %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Signed Subtract Add Exchange */
ARM_V7M_INLINE int32_t arm_v7m_ssax(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SSAX %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Unsigned Add Subtract Exchange */
ARM_V7M_INLINE uint32_t arm_v7m_uasx(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("UASX %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Unsigned Subtract Add Exchange */
ARM_V7M_INLINE uint32_t arm_v7m_usax(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("USAX %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/*============================================================================*
 * Extend and Add Instructions
 * Reference: Section A7.7 - SXTAB, SXTAH, UXTAB, UXTAH, SXTAB16, UXTAB16
 *============================================================================*/

/* Sign Extend and Add Byte */
ARM_V7M_INLINE int32_t arm_v7m_sxtab(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SXTAB %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Sign Extend and Add Halfword */
ARM_V7M_INLINE int32_t arm_v7m_sxtah(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SXTAH %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Zero Extend and Add Byte */
ARM_V7M_INLINE uint32_t arm_v7m_uxtab(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("UXTAB %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Zero Extend and Add Halfword */
ARM_V7M_INLINE uint32_t arm_v7m_uxtah(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("UXTAH %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Sign Extend and Add Bytes to 16 */
ARM_V7M_INLINE int32_t arm_v7m_sxtab16(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("SXTAB16 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Zero Extend and Add Bytes to 16 */
ARM_V7M_INLINE uint32_t arm_v7m_uxtab16(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("UXTAB16 %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/*============================================================================*
 * Saturating Exchange Instructions
 * Reference: Section A7.7 - QASX, QSAX, UQASX, UQSAX
 *============================================================================*/

/* Saturating Signed Add Subtract Exchange */
ARM_V7M_INLINE int32_t arm_v7m_qasx(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("QASX %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Saturating Signed Subtract Add Exchange */
ARM_V7M_INLINE int32_t arm_v7m_qsax(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("QSAX %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Saturating Unsigned Add Subtract Exchange */
ARM_V7M_INLINE uint32_t arm_v7m_uqasx(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("UQASX %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Saturating Unsigned Subtract Add Exchange */
ARM_V7M_INLINE uint32_t arm_v7m_uqsax(uint32_t a, uint32_t b)
{
    uint32_t result;
    __asm volatile ("UQSAX %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/*============================================================================*
 * Saturating Double Multiply-Add Instructions
 * Reference: Section A7.7 - QDADD, QDSUB
 *============================================================================*/

/* Saturating Double and Add - result = a + SAT(2 * b) */
ARM_V7M_INLINE int32_t arm_v7m_qdadd(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("QDADD %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/* Saturating Double and Subtract - result = a - SAT(2 * b) */
ARM_V7M_INLINE int32_t arm_v7m_qdsub(int32_t a, int32_t b)
{
    int32_t result;
    __asm volatile ("QDSUB %0, %1, %2" : "=r" (result) : "r" (a), "r" (b));
    return result;
}

/*============================================================================*
 * Debug and Hint Instructions
 * Reference: Section A7.7 - DBG, YIELD
 *============================================================================*/

/* Debug - provides a hint to debug systems */
ARM_V7M_INLINE void arm_v7m_dbg(uint32_t option)
{
    __asm volatile ("DBG %0" : : "i" (option));
}

/* Yield - hint to yield execution in multithreading */
ARM_V7M_INLINE void arm_v7m_yield(void)
{
    __asm volatile ("YIELD" : : : "memory");
}

/*============================================================================*
 * Load Instructions
 * Reference: Section A7.7 - LDR, LDRB, LDRH, LDRSB, LDRSH, LDRD
 *============================================================================*/

/* Load Word - loads 32-bit word from memory */
ARM_V7M_INLINE uint32_t arm_v7m_ldr(uint32_t *addr)
{
    uint32_t result;
    __asm volatile ("LDR %0, [%1]" : "=r" (result) : "r" (addr));
    return result;
}

/* Load Byte - loads 8-bit byte from memory */
ARM_V7M_INLINE uint8_t arm_v7m_ldrb(uint8_t *addr)
{
    uint8_t result;
    __asm volatile ("LDRB %0, [%1]" : "=r" (result) : "r" (addr));
    return result;
}

/* Load Halfword - loads 16-bit halfword from memory */
ARM_V7M_INLINE uint16_t arm_v7m_ldrh(uint16_t *addr)
{
    uint16_t result;
    __asm volatile ("LDRH %0, [%1]" : "=r" (result) : "r" (addr));
    return result;
}

/* Load Signed Byte - loads 8-bit byte with sign extension */
ARM_V7M_INLINE int32_t arm_v7m_ldrsb(int8_t *addr)
{
    int32_t result;
    __asm volatile ("LDRSB %0, [%1]" : "=r" (result) : "r" (addr));
    return result;
}

/* Load Signed Halfword - loads 16-bit halfword with sign extension */
ARM_V7M_INLINE int32_t arm_v7m_ldrsh(int16_t *addr)
{
    int32_t result;
    __asm volatile ("LDRSH %0, [%1]" : "=r" (result) : "r" (addr));
    return result;
}

/* Load Doubleword - loads 64-bit value from memory */
ARM_V7M_INLINE uint64_t arm_v7m_ldrd(uint64_t *addr)
{
    uint32_t lo, hi;
    __asm volatile ("LDRD %0, %1, [%2]" : "=r" (lo), "=r" (hi) : "r" (addr));
    return ((uint64_t)hi << 32) | lo;
}

/*============================================================================*
 * Store Instructions
 * Reference: Section A7.7 - STR, STRB, STRH, STRD
 *============================================================================*/

/* Store Word - stores 32-bit word to memory */
ARM_V7M_INLINE void arm_v7m_str(uint32_t value, uint32_t *addr)
{
    __asm volatile ("STR %0, [%1]" : : "r" (value), "r" (addr) : "memory");
}

/* Store Byte - stores 8-bit byte to memory */
ARM_V7M_INLINE void arm_v7m_strb(uint8_t value, uint8_t *addr)
{
    __asm volatile ("STRB %0, [%1]" : : "r" (value), "r" (addr) : "memory");
}

/* Store Halfword - stores 16-bit halfword to memory */
ARM_V7M_INLINE void arm_v7m_strh(uint16_t value, uint16_t *addr)
{
    __asm volatile ("STRH %0, [%1]" : : "r" (value), "r" (addr) : "memory");
}

/* Store Doubleword - stores 64-bit value to memory */
ARM_V7M_INLINE void arm_v7m_strd(uint64_t value, uint64_t *addr)
{
    uint32_t lo = (uint32_t)value;
    uint32_t hi = (uint32_t)(value >> 32);
    __asm volatile ("STRD %0, %1, [%2]" : : "r" (lo), "r" (hi), "r" (addr) : "memory");
}

/*============================================================================*
 * Floating-Point Instructions
 * Reference: Section A6.5 - VFP/Neon Instructions
 *============================================================================*/

/* Floating-Point Add */
ARM_V7M_INLINE float arm_v7m_vadd_f32(float a, float b)
{
    float result;
    __asm volatile ("VADD.F32 %0, %1, %2" : "=t" (result) : "t" (a), "t" (b));
    return result;
}

/* Floating-Point Subtract */
ARM_V7M_INLINE float arm_v7m_vsub_f32(float a, float b)
{
    float result;
    __asm volatile ("VSUB.F32 %0, %1, %2" : "=t" (result) : "t" (a), "t" (b));
    return result;
}

/* Floating-Point Multiply */
ARM_V7M_INLINE float arm_v7m_vmul_f32(float a, float b)
{
    float result;
    __asm volatile ("VMUL.F32 %0, %1, %2" : "=t" (result) : "t" (a), "t" (b));
    return result;
}

/* Floating-Point Divide */
ARM_V7M_INLINE float arm_v7m_vdiv_f32(float a, float b)
{
    float result;
    __asm volatile ("VDIV.F32 %0, %1, %2" : "=t" (result) : "t" (a), "t" (b));
    return result;
}

/* Floating-Point Absolute */
ARM_V7M_INLINE float arm_v7m_vabs_f32(float a)
{
    float result;
    __asm volatile ("VABS.F32 %0, %1" : "=t" (result) : "t" (a));
    return result;
}

/* Floating-Point Negate */
ARM_V7M_INLINE float arm_v7m_vneg_f32(float a)
{
    float result;
    __asm volatile ("VNEG.F32 %0, %1" : "=t" (result) : "t" (a));
    return result;
}

/* Floating-Point Square Root */
ARM_V7M_INLINE float arm_v7m_vsqrt_f32(float a)
{
    float result;
    __asm volatile ("VSQRT.F32 %0, %1" : "=t" (result) : "t" (a));
    return result;
}

/* Floating-Point Compare */
ARM_V7M_INLINE void arm_v7m_vcmp_f32(float a, float b)
{
    __asm volatile ("VCMP.F32 %0, %1" : : "t" (a), "t" (b));
}

/* Floating-Point Compare with Exception */
ARM_V7M_INLINE void arm_v7m_vcmpe_f32(float a, float b)
{
    __asm volatile ("VCMPE.F32 %0, %1" : : "t" (a), "t" (b));
}

/* Floating-Point Convert (various conversions) */
ARM_V7M_INLINE int32_t arm_v7m_vcvt_s32_f32(float a)
{
    int32_t result;
    __asm volatile ("VCVT.S32.F32 %0, %1" : "=t" (result) : "t" (a));
    return result;
}

ARM_V7M_INLINE uint32_t arm_v7m_vcvt_u32_f32(float a)
{
    uint32_t result;
    __asm volatile ("VCVT.U32.F32 %0, %1" : "=t" (result) : "t" (a));
    return result;
}

ARM_V7M_INLINE float arm_v7m_vcvt_f32_s32(int32_t a)
{
    float result;
    __asm volatile ("VCVT.F32.S32 %0, %1" : "=t" (result) : "t" (a));
    return result;
}

ARM_V7M_INLINE float arm_v7m_vcvt_f32_u32(uint32_t a)
{
    float result;
    __asm volatile ("VCVT.F32.U32 %0, %1" : "=t" (result) : "t" (a));
    return result;
}

/* Floating-Point Multiply-Accumulate */
ARM_V7M_INLINE float arm_v7m_vmla_f32(float acc, float a, float b)
{
    float result = acc;
    __asm volatile ("VMLA.F32 %0, %1, %2" : "+t" (result) : "t" (a), "t" (b));
    return result;
}

/* Floating-Point Multiply-Subtract */
ARM_V7M_INLINE float arm_v7m_vmls_f32(float acc, float a, float b)
{
    float result = acc;
    __asm volatile ("VMLS.F32 %0, %1, %2" : "+t" (result) : "t" (a), "t" (b));
    return result;
}

/* Floating-Point Fused Multiply-Accumulate */
ARM_V7M_INLINE float arm_v7m_vfma_f32(float acc, float a, float b)
{
    float result = acc;
    __asm volatile ("VFMA.F32 %0, %1, %2" : "+t" (result) : "t" (a), "t" (b));
    return result;
}

/* Floating-Point Fused Multiply-Subtract */
ARM_V7M_INLINE float arm_v7m_vfms_f32(float acc, float a, float b)
{
    float result = acc;
    __asm volatile ("VFMS.F32 %0, %1, %2" : "+t" (result) : "t" (a), "t" (b));
    return result;
}

/* Floating-Point Negated Multiply-Accumulate */
ARM_V7M_INLINE float arm_v7m_vnmla_f32(float acc, float a, float b)
{
    float result = acc;
    __asm volatile ("VNMLA.F32 %0, %1, %2" : "+t" (result) : "t" (a), "t" (b));
    return result;
}

/* Floating-Point Negated Multiply-Subtract */
ARM_V7M_INLINE float arm_v7m_vnmls_f32(float acc, float a, float b)
{
    float result = acc;
    __asm volatile ("VNMLS.F32 %0, %1, %2" : "+t" (result) : "t" (a), "t" (b));
    return result;
}

/* Floating-Point Negated Multiply */
ARM_V7M_INLINE float arm_v7m_vnmul_f32(float a, float b)
{
    float result;
    __asm volatile ("VNMUL.F32 %0, %1, %2" : "=t" (result) : "t" (a), "t" (b));
    return result;
}

/* Move to ARM Register from VFP Special Register */
ARM_V7M_INLINE uint32_t arm_v7m_vmrs(uint32_t reg)
{
    uint32_t result;
    switch (reg) {
        case 0: __asm volatile ("VMRS %0, FPSCR" : "=r" (result)); break;
        case 1: __asm volatile ("VMRS %0, FPSID" : "=r" (result)); break;
        case 6: __asm volatile ("VMRS %0, MVFR0" : "=r" (result)); break;
        case 7: __asm volatile ("VMRS %0, MVFR1" : "=r" (result)); break;
        default: result = 0; break;
    }
    return result;
}

/* Move to VFP Special Register from ARM Register */
ARM_V7M_INLINE void arm_v7m_vmsr(uint32_t reg, uint32_t value)
{
    switch (reg) {
        case 0: __asm volatile ("VMSR FPSCR, %0" : : "r" (value)); break;
        case 1: __asm volatile ("VMSR FPSID, %0" : : "r" (value)); break;
        default: break;
    }
}

/* Pop Floating-Point Registers */
ARM_V7M_INLINE void arm_v7m_vpop(uint32_t d, uint32_t count)
{
    __asm volatile ("VPOP {d%0-d%1}" : : "i" (d), "i" (d + count - 1) : "memory");
}

/* Push Floating-Point Registers */
ARM_V7M_INLINE void arm_v7m_vpush(uint32_t d, uint32_t count)
{
    __asm volatile ("VPUSH {d%0-d%1}" : : "i" (d), "i" (d + count - 1) : "memory");
}

/* Floating-Point Round to Nearest (ties to Away) */
ARM_V7M_INLINE float arm_v7m_vrinta_f32(float a)
{
    float result;
    __asm volatile ("VRINTA.F32 %0, %1" : "=t" (result) : "t" (a));
    return result;
}

/* Floating-Point Round to Nearest (ties to Even) */
ARM_V7M_INLINE float arm_v7m_vrintn_f32(float a)
{
    float result;
    __asm volatile ("VRINTN.F32 %0, %1" : "=t" (result) : "t" (a));
    return result;
}

/* Floating-Point Round towards Plus Infinity */
ARM_V7M_INLINE float arm_v7m_vrintp_f32(float a)
{
    float result;
    __asm volatile ("VRINTP.F32 %0, %1" : "=t" (result) : "t" (a));
    return result;
}

/* Floating-Point Round towards Minus Infinity */
ARM_V7M_INLINE float arm_v7m_vrintm_f32(float a)
{
    float result;
    __asm volatile ("VRINTM.F32 %0, %1" : "=t" (result) : "t" (a));
    return result;
}

/* Floating-Point Round using Current Mode */
ARM_V7M_INLINE float arm_v7m_vrintx_f32(float a)
{
    float result;
    __asm volatile ("VRINTX.F32 %0, %1" : "=t" (result) : "t" (a));
    return result;
}

/* Floating-Point Round towards Zero */
ARM_V7M_INLINE float arm_v7m_vrintz_f32(float a)
{
    float result;
    __asm volatile ("VRINTZ.F32 %0, %1" : "=t" (result) : "t" (a));
    return result;
}

/*============================================================================*
 * Coprocessor Instructions
 * Reference: Section A7.7 - CDP, LDC, STC, MCR, MRC, MCRR, MRRC
 *============================================================================*/

/* Coprocessor Data Operation */
ARM_V7M_INLINE void arm_v7m_cdp(uint32_t coproc, uint32_t opc1, uint32_t opc2,
                                 uint32_t crd, uint32_t crn, uint32_t crm)
{
    __asm volatile ("CDP p%0, %1, c%4, c%5, c%6, %2"
                    : : "i" (coproc), "i" (opc1), "i" (opc2),
                      "i" (crd), "i" (crn), "i" (crm));
}

/* Coprocessor Data Operation 2 */
ARM_V7M_INLINE void arm_v7m_cdp2(uint32_t coproc, uint32_t opc1, uint32_t opc2,
                                  uint32_t crd, uint32_t crn, uint32_t crm)
{
    __asm volatile ("CDP2 p%0, %1, c%4, c%5, c%6, %2"
                    : : "i" (coproc), "i" (opc1), "i" (opc2),
                      "i" (crd), "i" (crn), "i" (crm));
}

/* Load Coprocessor */
ARM_V7M_INLINE void arm_v7m_ldc(uint32_t coproc, uint32_t crd, void *addr)
{
    __asm volatile ("LDC p%0, c%1, [%2]" : : "i" (coproc), "i" (crd), "r" (addr));
}

/* Load Coprocessor 2 */
ARM_V7M_INLINE void arm_v7m_ldc2(uint32_t coproc, uint32_t crd, void *addr)
{
    __asm volatile ("LDC2 p%0, c%1, [%2]" : : "i" (coproc), "i" (crd), "r" (addr));
}

/* Store Coprocessor */
ARM_V7M_INLINE void arm_v7m_stc(uint32_t coproc, uint32_t crd, void *addr)
{
    __asm volatile ("STC p%0, c%1, [%2]" : : "i" (coproc), "i" (crd), "r" (addr) : "memory");
}

/* Store Coprocessor 2 */
ARM_V7M_INLINE void arm_v7m_stc2(uint32_t coproc, uint32_t crd, void *addr)
{
    __asm volatile ("STC2 p%0, c%1, [%2]" : : "i" (coproc), "i" (crd), "r" (addr) : "memory");
}

/* Move to Coprocessor from ARM Register */
ARM_V7M_INLINE void arm_v7m_mcr(uint32_t coproc, uint32_t opc1, uint32_t opc2,
                                 uint32_t value, uint32_t crn, uint32_t crm)
{
    __asm volatile ("MCR p%0, %1, %3, c%4, c%5, %2"
                    : : "i" (coproc), "i" (opc1), "i" (opc2),
                      "r" (value), "i" (crn), "i" (crm));
}

/* Move to Coprocessor from ARM Register 2 */
ARM_V7M_INLINE void arm_v7m_mcr2(uint32_t coproc, uint32_t opc1, uint32_t opc2,
                                  uint32_t value, uint32_t crn, uint32_t crm)
{
    __asm volatile ("MCR2 p%0, %1, %3, c%4, c%5, %2"
                    : : "i" (coproc), "i" (opc1), "i" (opc2),
                      "r" (value), "i" (crn), "i" (crm));
}

/* Move to ARM Register from Coprocessor */
ARM_V7M_INLINE uint32_t arm_v7m_mrc(uint32_t coproc, uint32_t opc1, uint32_t opc2,
                                     uint32_t crn, uint32_t crm)
{
    uint32_t result;
    __asm volatile ("MRC p%1, %2, %0, c%4, c%5, %3"
                    : "=r" (result) : "i" (coproc), "i" (opc1), "i" (opc2),
                      "i" (crn), "i" (crm));
    return result;
}

/* Move to ARM Register from Coprocessor 2 */
ARM_V7M_INLINE uint32_t arm_v7m_mrc2(uint32_t coproc, uint32_t opc1, uint32_t opc2,
                                      uint32_t crn, uint32_t crm)
{
    uint32_t result;
    __asm volatile ("MRC2 p%1, %2, %0, c%4, c%5, %3"
                    : "=r" (result) : "i" (coproc), "i" (opc1), "i" (opc2),
                      "i" (crn), "i" (crm));
    return result;
}

/* Move to Coprocessor from two ARM Registers */
ARM_V7M_INLINE void arm_v7m_mcrr(uint32_t coproc, uint32_t opc,
                                  uint32_t lo, uint32_t hi, uint32_t crm)
{
    __asm volatile ("MCRR p%0, %1, %2, %3, c%4"
                    : : "i" (coproc), "i" (opc), "r" (lo), "r" (hi), "i" (crm));
}

/* Move to Coprocessor from two ARM Registers 2 */
ARM_V7M_INLINE void arm_v7m_mcrr2(uint32_t coproc, uint32_t opc,
                                   uint32_t lo, uint32_t hi, uint32_t crm)
{
    __asm volatile ("MCRR2 p%0, %1, %2, %3, c%4"
                    : : "i" (coproc), "i" (opc), "r" (lo), "r" (hi), "i" (crm));
}

/* Move to two ARM Registers from Coprocessor */
ARM_V7M_INLINE uint64_t arm_v7m_mrrc(uint32_t coproc, uint32_t opc, uint32_t crm)
{
    uint32_t lo, hi;
    __asm volatile ("MRRC p%2, %3, %0, %1, c%4"
                    : "=r" (lo), "=r" (hi)
                    : "i" (coproc), "i" (opc), "i" (crm));
    return ((uint64_t)hi << 32) | lo;
}

/* Move to two ARM Registers from Coprocessor 2 */
ARM_V7M_INLINE uint64_t arm_v7m_mrrc2(uint32_t coproc, uint32_t opc, uint32_t crm)
{
    uint32_t lo, hi;
    __asm volatile ("MRRC2 p%2, %3, %0, %1, c%4"
                    : "=r" (lo), "=r" (hi)
                    : "i" (coproc), "i" (opc), "i" (crm));
    return ((uint64_t)hi << 32) | lo;
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_INSTR_H */
