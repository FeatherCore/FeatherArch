/*
 * ARM Architecture - ARMv8-M PACBTI (Pointer Authentication and Branch Target Identification)
 *
 * ============================================================================
 * File: armv8m_pacbti.h
 * Description: ARMv8-M PACBTI definitions
 * 描述: ARMv8-M PACBTI 定义
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B6: Pointer authentication and branch target identification Extension
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V8M_PACBTI_H__
#define __ARCH_ARM_V8M_PACBTI_H__

#include <stdint.h>
#include "armv8m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * PACBTI Control Register Bits
 * PACBTI 控制寄存器位
 * ============================================================================
 */

/**
 * CONTROL register PACBTI bits (already defined in armv8m_core.h)
 * CONTROL 寄存器 PACBTI 位 (已在 armv8m_core.h 中定义)
 */

/*
 * ============================================================================
 * PACBTI Function Declarations
 * PACBTI 函数声明
 * ============================================================================
 */

/**
 * @brief Enable PAC (Pointer Authentication Code)
 */
void pac_enable(void);

/**
 * @brief Disable PAC
 */
void pac_disable(void);

/**
 * @brief Enable BTI (Branch Target Identification)
 */
void bti_enable(void);

/**
 * @brief Disable BTI
 */
void bti_disable(void);

/**
 * @brief Check if PAC is enabled
 * @return true if enabled
 */
bool pac_is_enabled(void);

/**
 * @brief Check if BTI is enabled
 * @return true if enabled
 */
bool bti_is_enabled(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V8M_PACBTI_H__ */
