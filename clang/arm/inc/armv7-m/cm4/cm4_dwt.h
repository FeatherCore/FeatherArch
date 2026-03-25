/*
 * ARM Architecture - Cortex-M4 DWT (Data Watchpoint and Trace)
 *
 * ============================================================================
 * File: cm4_dwt.h
 * Description: Cortex-M4 DWT register definitions (wrapper for armv7-m_dwt.h)
 * 描述: Cortex-M4 DWT 寄存器定义（armv7-m_dwt.h 的包装层）
 *
 * This file provides CM4-specific naming conventions while delegating
 * all actual definitions to armv7-m_dwt.h.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.8 Data Watchpoint and Trace unit (page 4-59)
 *   - Table 4-57 DWT registers summary (page 4-59)
 *
 * Implementation: All functionality is provided by armv7-m/armv7-m_dwt.h
 * Note: All register definitions are directly available from armv7-m_dwt.h
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_DWT_H__
#define __CM4_DWT_H__

#include <stdint.h>

/* Include the underlying ARMv7-M implementation */
/* This provides all DWT register definitions and bit fields */
#include "armv7-m/armv7-m_dwt.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * DWT Base Address Alias
 * DWT 基地址别名
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-57 (page 4-59)
 * ============================================================================
 */

#define CM4_DWT_BASE_ADDR             DWT_BASE_ADDR

/*
 * ============================================================================
 * DWT Register Definitions (Directly from armv7-m_dwt.h)
 * The following registers are directly available from armv7-m_dwt.h:
 * - DWT_CTRL - Control Register
 * - DWT_CYCCNT - Cycle Count Register
 * - DWT_CPICNT - CPI Count Register
 * - DWT_EXCCNT - Exception Overhead Count Register
 * - DWT_SLEEPCNT - Sleep Count Register
 * - DWT_LSUCNT - LSU Count Register
 * - DWT_FOLDCNT - Fold Count Register
 * - DWT_PCSR - Program Counter Sample Register
 * - DWT_COMP0-DWT_COMP3 - Comparator Registers
 * - DWT_MASK0-DWT_MASK3 - Mask Registers
 * - DWT_FUNCTION0-DWT_FUNCTION3 - Function Registers
 *
 * Bit definitions are also available:
 * - DWT_CTRL_*, DWT_FUNCTION_*, DWT_DATAVSIZE_*
 * ============================================================================
 */

/*
 * ============================================================================
 * DWT Function Wrapper Declarations
 * DWT 函数包装器声明
 * Implementation: Delegates to functions in armv7-m_dwt.c
 * ============================================================================
 */

/**
 * @brief Initialize DWT
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.8 (page 4-59)
 * Implementation: Delegates to dwt_init() in armv7-m_dwt.c
 */
static inline void cm4_dwt_init(void)
{
    dwt_init();
}

/**
 * @brief Enable DWT cycle counter
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.8.1 (page 4-60)
 * Implementation: Delegates to dwt_enable_cycle_counter() in armv7-m_dwt.c
 */
static inline void cm4_dwt_enable_cycle_counter(void)
{
    dwt_enable_cycle_counter();
}

/**
 * @brief Disable DWT cycle counter
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.8.1 (page 4-60)
 * Implementation: Delegates to dwt_disable_cycle_counter() in armv7-m_dwt.c
 */
static inline void cm4_dwt_disable_cycle_counter(void)
{
    dwt_disable_cycle_counter();
}

/**
 * @brief Get cycle count
 * @return Current cycle count value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.8.1 (page 4-60)
 * Implementation: Delegates to dwt_get_cycle_count() in armv7-m_dwt.c
 */
static inline uint32_t cm4_dwt_get_cycle_count(void)
{
    return dwt_get_cycle_count();
}

/**
 * @brief Set cycle count
 * @param count Value to set
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.8.1 (page 4-60)
 * Implementation: Delegates to dwt_set_cycle_count() in armv7-m_dwt.c
 */
static inline void cm4_dwt_set_cycle_count(uint32_t count)
{
    dwt_set_cycle_count(count);
}

/**
 * @brief Reset cycle counter
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.8.1 (page 4-60)
 * Implementation: Delegates to dwt_reset_cycle_counter() in armv7-m_dwt.c
 */
static inline void cm4_dwt_reset_cycle_counter(void)
{
    dwt_reset_cycle_counter();
}

/**
 * @brief Configure comparator
 * @param comp Comparator number (0-3)
 * @param value Comparison value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.8.2 (page 4-62)
 * Implementation: Delegates to dwt_set_comparator() in armv7-m_dwt.c
 */
static inline void cm4_dwt_set_comparator(uint32_t comp, uint32_t value)
{
    dwt_set_comparator(comp, value);
}

/**
 * @brief Get comparator value
 * @param comp Comparator number (0-3)
 * @return Current comparator value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.8.2 (page 4-62)
 * Implementation: Delegates to dwt_get_comparator() in armv7-m_dwt.c
 */
static inline uint32_t cm4_dwt_get_comparator(uint32_t comp)
{
    return dwt_get_comparator(comp);
}

/**
 * @brief Configure comparator mask
 * @param comp Comparator number (0-3)
 * @param mask Mask value (0-31)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.8.2 (page 4-62)
 * Implementation: Delegates to dwt_set_comparator_mask() in armv7-m_dwt.c
 */
static inline void cm4_dwt_set_comparator_mask(uint32_t comp, uint32_t mask)
{
    dwt_set_comparator_mask(comp, mask);
}

/**
 * @brief Configure comparator function
 * @param comp Comparator number (0-3)
 * @param function Function type (DWT_FUNCTION_*)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.8.2 (page 4-62)
 * Implementation: Delegates to dwt_set_comparator_function() in armv7-m_dwt.c
 */
static inline void cm4_dwt_set_comparator_function(uint32_t comp, uint32_t function)
{
    dwt_set_comparator_function(comp, function);
}

/**
 * @brief Enable comparator
 * @param comp Comparator number (0-3)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.8.2 (page 4-62)
 * Implementation: Delegates to dwt_enable_comparator() in armv7-m_dwt.c
 */
static inline void cm4_dwt_enable_comparator(uint32_t comp)
{
    dwt_enable_comparator(comp);
}

/**
 * @brief Disable comparator
 * @param comp Comparator number (0-3)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.8.2 (page 4-62)
 * Implementation: Delegates to dwt_disable_comparator() in armv7-m_dwt.c
 */
static inline void cm4_dwt_disable_comparator(uint32_t comp)
{
    dwt_disable_comparator(comp);
}

/**
 * @brief Check if comparator matched
 * @param comp Comparator number (0-3)
 * @return 1 if matched, 0 otherwise
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.8.2 (page 4-62)
 * Implementation: Delegates to dwt_comparator_matched() in armv7-m_dwt.c
 */
static inline int cm4_dwt_comparator_matched(uint32_t comp)
{
    return dwt_comparator_matched(comp);
}

/**
 * @brief Get number of comparators
 * @return Number of comparators
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.8 (page 4-59)
 * Implementation: Delegates to dwt_get_num_comparators() in armv7-m_dwt.c
 */
static inline uint32_t cm4_dwt_get_num_comparators(void)
{
    return dwt_get_num_comparators();
}

/**
 * @brief Check if DWT is present
 * @return 1 if present, 0 if not
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.8 (page 4-59)
 * Implementation: Delegates to dwt_is_present() in armv7-m_dwt.c
 */
static inline int cm4_dwt_is_present(void)
{
    return dwt_is_present();
}

#ifdef __cplusplus
}
#endif

#endif /* __CM4_DWT_H__ */
