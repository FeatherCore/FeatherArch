/*
 * ARM Architecture - ARMv7-M DSP Extension
 *
 * ============================================================================
 * File: armv7-m_dsp.c
 * Description: ARMv7-M DSP (Digital Signal Processing) Extension implementation
 * 描述: ARMv7-M DSP (数字信号处理) 扩展实现
 *
 * This file provides implementations for DSP Extension helper functions.
 * Most DSP operations are implemented as inline functions in armv7-m_dsp.h
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
 *       - Pseudocode details of saturation
 *     * A2.3.2 The Application Program Status Register (APSR) (page A2-31)
 *       - GE[3:0] flags for SIMD operations
 *       - Q flag for saturation detection (sticky bit)
 *   - Chapter A4.4 Data-processing instructions (page A4-107)
 *     * A4.4.3 Multiply instructions (page A4-109)
 *       - Table A4-6 Signed multiply instructions, Armv7-M DSP extension
 *         * SMLAD, SMLADX, SMLSD, SMLSDX (Dual multiply accumulate/subtract)
 *         * SMUAD, SMUADX, SMUSD, SMUSDX (Dual multiply add/subtract)
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

#include "armv7-m/armv7-m_dsp.h"
#include "armv7-m/armv7-m_core.h"

/*
 * ============================================================================
 * DSP Initialization
 * DSP 初始化
 * ============================================================================
 */

/**
 * @brief Initialize DSP extension
 * 初始化DSP扩展
 * Enables DSP instructions by ensuring the processor is in appropriate mode.
 *
 * Reference: Chapter A1.3 Architecture extensions (page A1-22)
 *   - DSP extension adds saturating and unsigned SIMD instructions
 *   - Armv7E-M implementation includes DSP extension
 *   - Reference: Chapter A2.3.2 The Application Program Status Register (APSR) (page A2-31)
 *     * Q flag is sticky - must be cleared explicitly
 */
void dsp_init(void)
{
    /* DSP instructions are always available on ARMv7E-M when __DSP_PRESENT is set */
    /* No special initialization required, but we clear the Q flag */
    dsp_clear_q_flag();
}

/**
 * @brief Check if DSP extension is available
 * 检查DSP扩展是否可用
 * @return 1 if DSP is available, 0 otherwise
 */
uint32_t dsp_is_available(void)
{
    return (__DSP_PRESENT != 0) ? 1U : 0U;
}

/*
 * ============================================================================
 * SIMD Helper Functions
 * SIMD 辅助函数
 * ============================================================================
 */

/**
 * @brief Pack two 16-bit values into 32-bit register
 * 将两个16位值打包到32位寄存器
 * @param lo Lower 16-bit value
 * @param hi Upper 16-bit value
 * @return Packed 32-bit value
 */
uint32_t dsp_pack16(uint16_t lo, uint16_t hi)
{
    return ((uint32_t)hi << 16) | lo;
}

/**
 * @brief Unpack 32-bit value into two 16-bit values
 * 将32位值解包为两个16位值
 * @param val 32-bit packed value
 * @param lo Pointer to store lower 16-bit value
 * @param hi Pointer to store upper 16-bit value
 */
void dsp_unpack16(uint32_t val, uint16_t *lo, uint16_t *hi)
{
    if (lo) {
        *lo = (uint16_t)(val & 0xFFFF);
    }
    if (hi) {
        *hi = (uint16_t)(val >> 16);
    }
}

/**
 * @brief Pack four 8-bit values into 32-bit register
 * 将四个8位值打包到32位寄存器
 */
uint32_t dsp_pack8(uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3)
{
    return ((uint32_t)b3 << 24) | ((uint32_t)b2 << 16) | 
           ((uint32_t)b1 << 8) | b0;
}

/**
 * @brief Unpack 32-bit value into four 8-bit values
 * 将32位值解包为四个8位值
 */
void dsp_unpack8(uint32_t val, uint8_t *b0, uint8_t *b1, uint8_t *b2, uint8_t *b3)
{
    if (b0) {
        *b0 = (uint8_t)(val & 0xFF);
    }
    if (b1) {
        *b1 = (uint8_t)((val >> 8) & 0xFF);
    }
    if (b2) {
        *b2 = (uint8_t)((val >> 16) & 0xFF);
    }
    if (b3) {
        *b3 = (uint8_t)((val >> 24) & 0xFF);
    }
}

/*
 * ============================================================================
 * Complex Math Operations
 * 复数数学运算
 * ============================================================================
 */

/**
 * @brief Complex multiply-accumulate (16-bit)
 * 复数乘累加(16位)
 * Performs complex MAC operation: acc += (a + bi) * (c + di)
 * Reference: Arm(R) v7-M ARM, A7-360, SMLAD instruction
 *
 * @param acc_real Real part accumulator
 * @param acc_imag Imaginary part accumulator
 * @param a First complex number (packed: imag|real)
 * @param b Second complex number (packed: imag|real)
 * @param result_real Output real part
 * @param result_imag Output imaginary part
 */
void dsp_complex_mac(int32_t acc_real, int32_t acc_imag,
                     uint32_t a, uint32_t b,
                     int32_t *result_real, int32_t *result_imag)
{
    /* Extract components */
    int16_t a_real = (int16_t)(a & 0xFFFF);
    int16_t a_imag = (int16_t)(a >> 16);
    int16_t b_real = (int16_t)(b & 0xFFFF);
    int16_t b_imag = (int16_t)(b >> 16);
    
    /* Complex multiplication: (a+bi)(c+di) = (ac-bd) + (ad+bc)i */
    int32_t real = acc_real + (a_real * b_real) - (a_imag * b_imag);
    int32_t imag = acc_imag + (a_real * b_imag) + (a_imag * b_real);
    
    if (result_real) {
        *result_real = real;
    }
    if (result_imag) {
        *result_imag = imag;
    }
}

/**
 * @brief Saturating complex multiply-accumulate
 * 饱和复数乘累加
 * Uses DSP instructions for efficient saturated complex MAC.
 */
void dsp_complex_mac_sat(int32_t acc_real, int32_t acc_imag,
                         uint32_t a, uint32_t b,
                         int32_t *result_real, int32_t *result_imag)
{
    /* Use SMUAD for real part: a_real*b_real + a_imag*b_imag */
    /* Use SMUSDX for imaginary part: a_real*b_imag - a_imag*b_real */
    
    int32_t real_part = dsp_smuad(a, b);
    int32_t imag_part = dsp_smusdx(a, b);
    
    if (result_real) {
        *result_real = dsp_qadd(acc_real, real_part);
    }
    if (result_imag) {
        *result_imag = dsp_qadd(acc_imag, imag_part);
    }
}

/*
 * ============================================================================
 * FIR Filter Helper
 * FIR滤波器辅助函数
 * ============================================================================
 */

/**
 * @brief Single tap FIR filter computation
 * 单抽头FIR滤波器计算
 * Performs one tap of FIR filter: acc += coeff * sample
 * Uses DSP dual multiply-accumulate for efficiency.
 *
 * @param acc Current accumulator value
 * @param coeff Filter coefficient (16-bit)
 * @param sample Input sample (16-bit)
 * @return Updated accumulator
 */
int32_t dsp_fir_tap(int32_t acc, int16_t coeff, int16_t sample)
{
    return acc + ((int32_t)coeff * (int32_t)sample);
}

/**
 * @brief Dual tap FIR filter computation
 * 双抽头FIR滤波器计算
 * Processes two taps simultaneously using SMLAD instruction.
 *
 * @param acc Current accumulator value
 * @param coeffs Packed coefficients (coeff1 | coeff0)
 * @param samples Packed samples (sample1 | sample0)
 * @return Updated accumulator
 */
int32_t dsp_fir_dual_tap(int32_t acc, uint32_t coeffs, uint32_t samples)
{
    return dsp_smlad(acc, coeffs, samples);
}

/*
 * ============================================================================
 * Dot Product
 * 点积运算
 * ============================================================================
 */

/**
 * @brief 16-bit dot product
 * 16位点积
 * Computes dot product of two 16-bit vectors.
 *
 * @param a First vector (16-bit elements)
 * @param b Second vector (16-bit elements)
 * @param len Vector length (must be even)
 * @return Dot product result
 */
int32_t dsp_dot_product16(const int16_t *a, const int16_t *b, uint32_t len)
{
    int32_t sum = 0;
    uint32_t i;
    
    /* Process pairs using SMLAD for efficiency */
    for (i = 0; i + 1 < len; i += 2) {
        uint32_t a_packed = ((uint32_t)(uint16_t)a[i+1] << 16) | (uint16_t)a[i];
        uint32_t b_packed = ((uint32_t)(uint16_t)b[i+1] << 16) | (uint16_t)b[i];
        sum = dsp_smlad(sum, a_packed, b_packed);
    }
    
    /* Handle odd element if present */
    if (i < len) {
        sum += (int32_t)a[i] * (int32_t)b[i];
    }
    
    return sum;
}

/**
 * @brief Saturating 16-bit dot product
 * 饱和16位点积
 */
int32_t dsp_dot_product16_sat(const int16_t *a, const int16_t *b, uint32_t len)
{
    int32_t sum = dsp_dot_product16(a, b, len);
    return dsp_ssat(sum, 32);
}

/*
 * ============================================================================
 * Matrix Operations
 * 矩阵运算
 * ============================================================================
 */

/**
 * @brief 2x2 matrix multiply (16-bit elements)
 * 2x2矩阵乘法(16位元素)
 * Computes C = A * B where A, B, C are 2x2 matrices.
 */
void dsp_matrix_mult2x2(const int16_t *a, const int16_t *b, int32_t *c)
{
    /* C[0] = A[0]*B[0] + A[1]*B[2] */
    /* C[1] = A[0]*B[1] + A[1]*B[3] */
    /* C[2] = A[2]*B[0] + A[3]*B[2] */
    /* C[3] = A[2]*B[1] + A[3]*B[3] */
    
    uint32_t a_row0 = ((uint32_t)(uint16_t)a[1] << 16) | (uint16_t)a[0];
    uint32_t a_row1 = ((uint32_t)(uint16_t)a[3] << 16) | (uint16_t)a[2];
    uint32_t b_col0 = ((uint32_t)(uint16_t)b[2] << 16) | (uint16_t)b[0];
    uint32_t b_col1 = ((uint32_t)(uint16_t)b[3] << 16) | (uint16_t)b[1];
    uint32_t b_col2 = ((uint32_t)(uint16_t)b[2] << 16) | (uint16_t)b[1];
    uint32_t b_col3 = ((uint32_t)(uint16_t)b[3] << 16) | (uint16_t)b[2];
    
    c[0] = dsp_smuad(a_row0, b_col0);
    c[1] = dsp_smuad(a_row0, b_col1);
    c[2] = dsp_smuad(a_row1, b_col2);
    c[3] = dsp_smuad(a_row1, b_col3);
}
