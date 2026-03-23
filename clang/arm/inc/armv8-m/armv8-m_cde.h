/*
 * ARM Architecture - ARMv8-M CDE (Custom Datapath Extension)
 *
 * ============================================================================
 * File: armv8m_cde.h
 * Description: ARMv8-M CDE definitions
 * 描述: ARMv8-M CDE 定义
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter A1.4.1: CDE - The Custom Datapath Extension
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V8M_CDE_H__
#define __ARCH_ARM_V8M_CDE_H__

#include <stdint.h>
#include "armv8m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * CDE Function Declarations
 * CDE 函数声明
 * ============================================================================
 */

/**
 * @brief Enable CDE coprocessor
 * @param coproc Coprocessor number (0-3)
 */
void cde_enable_coproc(uint32_t coproc);

/**
 * @brief Disable CDE coprocessor
 * @param coproc Coprocessor number (0-3)
 */
void cde_disable_coproc(uint32_t coproc);

/**
 * @brief Check if CDE is present
 * @return true if present
 */
bool cde_is_present(void);

/**
 * @brief Get number of CDE coprocessors
 * @return Number of coprocessors
 */
uint32_t cde_get_num_coprocessors(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V8M_CDE_H__ */
