/*
 * ARM Architecture - ARMv8-M DSP Extension
 *
 * ============================================================================
 * File: armv8-m_dsp.c
 * Description: ARMv8-M DSP (Digital Signal Processing) Extension implementation
 * 描述: ARMv8-M DSP (数字信号处理) 扩展实现
 *
 * This file provides implementations for DSP Extension helper functions.
 * Most DSP operations are implemented as inline functions in armv8-m_dsp.h
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B4 - Floating-point Support
 *   - Chapter B5 - MVE (Helium) Vector Extension
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv8-m/armv8-m_dsp.h"
#include "armv8-m/armv8-m_core.h"

/*
 * ============================================================================
 * DSP Initialization
 * DSP 初始化
 * ============================================================================
 */

/**
 * @brief Initialize DSP extension
 * 初始化DSP扩展
 * Reference: Arm(R) v8-M ARM, B4 - DSP Extension
 */
void dsp_init(void)
{
    dsp_clear_q_flag();
}

/**
 * @brief Initialize DSP with TrustZone awareness
 * 初始化DSP (支持TrustZone)
 * Clears Q flag in both Secure and Non-secure states if applicable.
 */
void dsp_init_tz(void)
{
    dsp_clear_q_flag();
#if defined(__TZ_PRESENT) && (__TZ_PRESENT == 1)
    /* In ARMv8-M with TrustZone, DSP state is banked */
    /* Secure state DSP operations don't affect Non-secure state */
#endif
}

/*
 * ============================================================================
 * SIMD Helper Functions
 * SIMD 辅助函数
 * ============================================================================
 */

uint32_t dsp_pack16(uint16_t lo, uint16_t hi)
{
    return ((uint32_t)hi << 16) | lo;
}

void dsp_unpack16(uint32_t val, uint16_t *lo, uint16_t *hi)
{
    if (lo) {
        *lo = (uint16_t)(val & 0xFFFF);
    }
    if (hi) {
        *hi = (uint16_t)(val >> 16);
    }
}

uint32_t dsp_pack8(uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3)
{
    return ((uint32_t)b3 << 24) | ((uint32_t)b2 << 16) | 
           ((uint32_t)b1 << 8) | b0;
}

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

void dsp_complex_mac(int32_t acc_real, int32_t acc_imag,
                     uint32_t a, uint32_t b,
                     int32_t *result_real, int32_t *result_imag)
{
    int16_t a_real = (int16_t)(a & 0xFFFF);
    int16_t a_imag = (int16_t)(a >> 16);
    int16_t b_real = (int16_t)(b & 0xFFFF);
    int16_t b_imag = (int16_t)(b >> 16);
    
    int32_t real = acc_real + (a_real * b_real) - (a_imag * b_imag);
    int32_t imag = acc_imag + (a_real * b_imag) + (a_imag * b_real);
    
    if (result_real) {
        *result_real = real;
    }
    if (result_imag) {
        *result_imag = imag;
    }
}

void dsp_complex_mac_sat(int32_t acc_real, int32_t acc_imag,
                         uint32_t a, uint32_t b,
                         int32_t *result_real, int32_t *result_imag)
{
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
 * FIR Filter Helpers
 * FIR滤波器辅助函数
 * ============================================================================
 */

int32_t dsp_fir_tap(int32_t acc, int16_t coeff, int16_t sample)
{
    return acc + ((int32_t)coeff * (int32_t)sample);
}

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

int32_t dsp_dot_product16(const int16_t *a, const int16_t *b, uint32_t len)
{
    int32_t sum = 0;
    uint32_t i;
    
    for (i = 0; i + 1 < len; i += 2) {
        uint32_t a_packed = ((uint32_t)(uint16_t)a[i+1] << 16) | (uint16_t)a[i];
        uint32_t b_packed = ((uint32_t)(uint16_t)b[i+1] << 16) | (uint16_t)b[i];
        sum = dsp_smlad(sum, a_packed, b_packed);
    }
    
    if (i < len) {
        sum += (int32_t)a[i] * (int32_t)b[i];
    }
    
    return sum;
}

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

void dsp_matrix_mult2x2(const int16_t *a, const int16_t *b, int32_t *c)
{
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

/*
 * ============================================================================
 * ARMv8-M Specific DSP Features
 * ARMv8-M 特定 DSP 功能
 * ============================================================================
 */

#if defined(__ARM_FEATURE_MVE) && (__ARM_FEATURE_MVE > 0)

/**
 * @brief Check if MVE is available (runtime check)
 * MVE可用性运行时检查
 * @return 1 if MVE is available, 0 otherwise
 */
uint32_t dsp_mve_check_available(void)
{
    /* Check MVFR0 register for MVE support */
    uint32_t mvfr0;
    __asm__ volatile (
        "mrs %0, mvfr0"
        : "=r" (mvfr0)
    );
    /* Bits [3:0] indicate MVE support */
    return ((mvfr0 & 0xF) != 0) ? 1U : 0U;
}

/**
 * @brief Enable MVE
 * 启用MVE
 * Enables the MVE coprocessor.
 */
void dsp_mve_enable(void)
{
    /* Enable CP10 and CP11 for MVE access */
    uint32_t cpacr = 0;
    __asm__ volatile (
        "mrs %0, cpacr"
        : "=r" (cpacr)
    );
    cpacr |= (0x3 << 20) | (0x3 << 22); /* Enable CP10 and CP11 */
    __asm__ volatile (
        "msr cpacr, %0"
        :
        : "r" (cpacr)
    );
    __asm__ volatile ("isb");
}

/**
 * @brief Disable MVE
 * 禁用MVE
 */
void dsp_mve_disable(void)
{
    uint32_t cpacr = 0;
    __asm__ volatile (
        "mrs %0, cpacr"
        : "=r" (cpacr)
    );
    cpacr &= ~((0x3 << 20) | (0x3 << 22)); /* Disable CP10 and CP11 */
    __asm__ volatile (
        "msr cpacr, %0"
        :
        : "r" (cpacr)
    );
    __asm__ volatile ("isb");
}

#endif /* __ARM_FEATURE_MVE */
