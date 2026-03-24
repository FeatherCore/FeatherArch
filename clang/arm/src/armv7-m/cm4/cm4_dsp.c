/*
 * ARM Architecture - Cortex-M4 DSP Functions
 *
 * ============================================================================
 * File: cm4_dsp.c
 * Description: Cortex-M4 DSP instruction implementations
 * 描述: Cortex-M4 DSP 指令实现
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553)
 *   - Chapter 3.4: Cortex-M4 DSP instructions
 *   - Chapter 2.1.1: Processor registers
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include <stdbool.h>
#include "armv7-m/cm4/cm4.h"

#if (__DSP_PRESENT == 1)

/* ============================================================================
 * DSP FIR Filter Implementation
 * DSP FIR 滤波器实现
 * ============================================================================ */

/**
 * @brief FIR filter (16-bit coefficients, 16-bit data)
 * FIR 滤波器 (16位系数, 16位数据)
 * @param pState State buffer (numTaps + blockSize - 1 samples)
 * @param pCoeffs Filter coefficients (numTaps coefficients)
 * @param pSrc Input signal
 * @param pDst Output signal
 * @param blockSize Number of samples to process
 * @param numTaps Number of filter taps
 */
void cm4_dsp_fir_q15(
    int16_t *pState,
    const int16_t *pCoeffs,
    const int16_t *pSrc,
    int16_t *pDst,
    uint32_t blockSize,
    uint32_t numTaps
)
{
    int16_t *pStateCur = pState + numTaps - 1;
    int64_t acc;
    uint32_t i, j;

    for (i = 0; i < blockSize; i++) {
        /* Copy input sample to state buffer */
        *pStateCur++ = *pSrc++;

        /* Compute filter output */
        acc = 0;
        for (j = 0; j < numTaps; j++) {
            acc += (int32_t)pState[j] * (int32_t)pCoeffs[j];
        }

        /* Store result with saturation */
        *pDst++ = (int16_t)(acc >> 15);

        /* Shift state buffer */
        for (j = 0; j < numTaps - 1; j++) {
            pState[j] = pState[j + 1];
        }
        pStateCur = pState + numTaps - 1;
    }
}

/**
 * @brief FIR filter (32-bit coefficients, 32-bit data)
 * FIR 滤波器 (32位系数, 32位数据)
 * @param pState State buffer
 * @param pCoeffs Filter coefficients
 * @param pSrc Input signal
 * @param pDst Output signal
 * @param blockSize Number of samples to process
 * @param numTaps Number of filter taps
 */
void cm4_dsp_fir_q31(
    int32_t *pState,
    const int32_t *pCoeffs,
    const int32_t *pSrc,
    int32_t *pDst,
    uint32_t blockSize,
    uint32_t numTaps
)
{
    int32_t *pStateCur = pState + numTaps - 1;
    int64_t acc;
    uint32_t i, j;

    for (i = 0; i < blockSize; i++) {
        /* Copy input sample to state buffer */
        *pStateCur++ = *pSrc++;

        /* Compute filter output */
        acc = 0;
        for (j = 0; j < numTaps; j++) {
            acc += (int64_t)pState[j] * (int64_t)pCoeffs[j];
        }

        /* Store result with saturation */
        *pDst++ = (int32_t)(acc >> 31);

        /* Shift state buffer */
        for (j = 0; j < numTaps - 1; j++) {
            pState[j] = pState[j + 1];
        }
        pStateCur = pState + numTaps - 1;
    }
}

/* ============================================================================
 * DSP IIR Filter Implementation (Biquad)
 * DSP IIR 滤波器实现 (双二阶)
 * ============================================================================ */

/**
 * @brief Biquad IIR filter (Direct Form 1, 16-bit)
 * 双二阶 IIR 滤波器 (直接形式1, 16位)
 * @param pState State buffer (2 * numStages values)
 * @param pCoeffs Coefficients (5 * numStages values: b0, b1, b2, a1, a2)
 * @param pSrc Input signal
 * @param pDst Output signal
 * @param blockSize Number of samples
 * @param numStages Number of biquad stages
 */
void cm4_dsp_biquad_q15(
    int16_t *pState,
    const int16_t *pCoeffs,
    const int16_t *pSrc,
    int16_t *pDst,
    uint32_t blockSize,
    uint32_t numStages
)
{
    int16_t *pStateCur = pState;
    int32_t acc;
    int16_t x0, y0;
    uint32_t i, stage;

    for (i = 0; i < blockSize; i++) {
        x0 = *pSrc++;

        for (stage = 0; stage < numStages; stage++) {
            /* Compute output */
            acc = (int32_t)pCoeffs[0] * x0 +
                  (int32_t)pCoeffs[1] * pStateCur[0] +
                  (int32_t)pCoeffs[2] * pStateCur[1] -
                  (int32_t)pCoeffs[3] * pStateCur[2] -
                  (int32_t)pCoeffs[4] * pStateCur[3];

            y0 = (int16_t)(acc >> 15);

            /* Update state */
            pStateCur[1] = pStateCur[0];
            pStateCur[0] = x0;
            pStateCur[3] = pStateCur[2];
            pStateCur[2] = y0;

            x0 = y0;
            pStateCur += 4;
        }

        *pDst++ = x0;
        pStateCur = pState;
    }
}

/* ============================================================================
 * DSP Vector Operations
 * DSP 向量操作
 * ============================================================================ */

/**
 * @brief Vector addition (16-bit)
 * 向量加法 (16位)
 * @param pSrcA First vector
 * @param pSrcB Second vector
 * @param pDst Result vector
 * @param blockSize Number of samples
 */
void cm4_dsp_add_q15(
    const int16_t *pSrcA,
    const int16_t *pSrcB,
    int16_t *pDst,
    uint32_t blockSize
)
{
    uint32_t i;

    for (i = 0; i < blockSize; i++) {
        pDst[i] = pSrcA[i] + pSrcB[i];
    }
}

/**
 * @brief Vector multiplication (16-bit)
 * 向量乘法 (16位)
 * @param pSrcA First vector
 * @param pSrcB Second vector
 * @param pDst Result vector
 * @param blockSize Number of samples
 */
void cm4_dsp_mult_q15(
    const int16_t *pSrcA,
    const int16_t *pSrcB,
    int16_t *pDst,
    uint32_t blockSize
)
{
    uint32_t i;
    int32_t product;

    for (i = 0; i < blockSize; i++) {
        product = (int32_t)pSrcA[i] * (int32_t)pSrcB[i];
        pDst[i] = (int16_t)(product >> 15);
    }
}

/**
 * @brief Vector dot product (16-bit)
 * 向量点积 (16位)
 * @param pSrcA First vector
 * @param pSrcB Second vector
 * @param blockSize Number of samples
 * @return Dot product result
 */
int32_t cm4_dsp_dot_prod_q15(
    const int16_t *pSrcA,
    const int16_t *pSrcB,
    uint32_t blockSize
)
{
    uint32_t i;
    int64_t sum = 0;

    for (i = 0; i < blockSize; i++) {
        sum += (int32_t)pSrcA[i] * (int32_t)pSrcB[i];
    }

    return (int32_t)(sum >> 15);
}

/**
 * @brief Vector scale (16-bit)
 * 向量缩放 (16位)
 * @param pSrc Input vector
 * @param scaleFract Scale factor (Q15)
 * @param shift Number of bits to shift
 * @param pDst Output vector
 * @param blockSize Number of samples
 */
void cm4_dsp_scale_q15(
    const int16_t *pSrc,
    int16_t scaleFract,
    int8_t shift,
    int16_t *pDst,
    uint32_t blockSize
)
{
    uint32_t i;
    int32_t product;

    for (i = 0; i < blockSize; i++) {
        product = (int32_t)pSrc[i] * (int32_t)scaleFract;
        if (shift >= 0) {
            pDst[i] = (int16_t)(product >> (15 - shift));
        } else {
            pDst[i] = (int16_t)(product >> (15 + (-shift)));
        }
    }
}

/* ============================================================================
 * DSP Math Functions
 * DSP 数学函数
 * ============================================================================ */

/**
 * @brief Square root (integer)
 * 平方根 (整数)
 * @param x Input value
 * @return Square root of x
 */
uint16_t cm4_dsp_sqrt_q15(uint32_t x)
{
    uint32_t root = 0;
    uint32_t bit = 1 << 30;

    /* Find highest bit */
    while (bit > x) {
        bit >>= 2;
    }

    while (bit != 0) {
        if (x >= root + bit) {
            x -= root + bit;
            root = (root >> 1) + bit;
        } else {
            root >>= 1;
        }
        bit >>= 2;
    }

    return (uint16_t)root;
}

/**
 * @brief Absolute value (16-bit)
 * 绝对值 (16位)
 * @param x Input value
 * @return Absolute value
 */
int16_t cm4_dsp_abs_q15(int16_t x)
{
    return (x < 0) ? -x : x;
}

/**
 * @brief Absolute value (32-bit)
 * 绝对值 (32位)
 * @param x Input value
 * @return Absolute value
 */
int32_t cm4_dsp_abs_q31(int32_t x)
{
    return (x < 0) ? -x : x;
}

/* ============================================================================
 * DSP Conversion Functions
 * DSP 转换函数
 * ============================================================================ */

/**
 * @brief Convert Q15 to float
 * Q15 转 float
 * @param x Q15 value
 * @return Float value
 */
float cm4_dsp_q15_to_float(int16_t x)
{
    return (float)x / 32768.0f;
}

/**
 * @brief Convert float to Q15
 * float 转 Q15
 * @param x Float value
 * @return Q15 value
 */
int16_t cm4_dsp_float_to_q15(float x)
{
    if (x > 0.999969f) return 32767;
    if (x < -1.0f) return -32768;
    return (int16_t)(x * 32768.0f);
}

/**
 * @brief Convert Q31 to float
 * Q31 转 float
 * @param x Q31 value
 * @return Float value
 */
float cm4_dsp_q31_to_float(int32_t x)
{
    return (float)x / 2147483648.0f;
}

/**
 * @brief Convert float to Q31
 * float 转 Q31
 * @param x Float value
 * @return Q31 value
 */
int32_t cm4_dsp_float_to_q31(float x)
{
    if (x > 0.9999999995f) return 2147483647;
    if (x < -1.0f) return -2147483648;
    return (int32_t)(x * 2147483648.0f);
}

#endif /* __DSP_PRESENT == 1 */
