/*
 * ARM Architecture - Cortex-M4 FPU Functions
 *
 * ============================================================================
 * File: cm4_fpu.c
 * Description: Cortex-M4 FPU (FPv4-SP) non-inline functions
 * 描述: Cortex-M4 FPU (FPv4-SP) 非内联函数
 *
 * IMPORTANT: This file ONLY contains FPU functions specific to Cortex-M4.
 * Generic ARMv7-M FPU functions are in armv7-m/armv7-m_fpu.c
 *
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 4
 *            Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.3
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/cm4/cm4.h"

#if (__FPU_PRESENT == 1)

/* ============================================================================
 * FPU Math Helper Functions
 * FPU 数学辅助函数
 * ============================================================================ */

/**
 * @brief Check if float is NaN
 * 检查浮点数是否为 NaN
 * @param f Float value
 * @return 1 if NaN, 0 otherwise
 */
int cm4_fpu_is_nan(float f)
{
    /* NaN has exponent all 1s and non-zero mantissa */
    uint32_t u = *(uint32_t *)&f;
    return ((u & 0x7F800000) == 0x7F800000) && ((u & 0x007FFFFF) != 0);
}

/**
 * @brief Check if float is infinity
 * 检查浮点数是否为无穷大
 * @param f Float value
 * @return 1 if infinity, 0 otherwise
 */
int cm4_fpu_is_infinity(float f)
{
    /* Infinity has exponent all 1s and zero mantissa */
    uint32_t u = *(uint32_t *)&f;
    return ((u & 0x7F800000) == 0x7F800000) && ((u & 0x007FFFFF) == 0);
}

/**
 * @brief Check if float is finite
 * 检查浮点数是否为有限数
 * @param f Float value
 * @return 1 if finite, 0 otherwise
 */
int cm4_fpu_is_finite(float f)
{
    /* Finite numbers don't have exponent all 1s */
    uint32_t u = *(uint32_t *)&f;
    return (u & 0x7F800000) != 0x7F800000;
}

/**
 * @brief Get float as integer bits
 * 将浮点数作为整数位获取
 * @param f Float value
 * @return Integer representation
 */
uint32_t cm4_fpu_float_to_bits(float f)
{
    return *(uint32_t *)&f;
}

/**
 * @brief Create float from integer bits
 * 从整数位创建浮点数
 * @param bits Integer representation
 * @return Float value
 */
float cm4_fpu_bits_to_float(uint32_t bits)
{
    return *(float *)&bits;
}

#endif /* __FPU_PRESENT == 1 */
