/*
 * ARM Architecture - Cortex-M4 DWT Implementation
 *
 * ============================================================================
 * File: cm4_dwt.c
 * Description: Cortex-M4 DWT function implementations
 * 描述: Cortex-M4 DWT 函数实现
 *
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual (100166_0001_04_en)
 *   - Chapter 9 Data Watchpoint and Trace Unit (page 9-83)
 *   - Table 9-1 DWT register summary (page 9-85)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include "armv7-m/cm4/cm4_dwt.h"

/**
 * @brief Enable DWT cycle counter
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 9.1 (page 9-84)
 */
void cm4_dwt_enable_cycle_counter(void)
{
    DWT_CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

/**
 * @brief Disable DWT cycle counter
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 9.1 (page 9-84)
 */
void cm4_dwt_disable_cycle_counter(void)
{
    DWT_CTRL &= ~DWT_CTRL_CYCCNTENA_Msk;
}

/**
 * @brief Get DWT cycle count
 * @return Current cycle count
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 */
uint32_t cm4_dwt_get_cycle_count(void)
{
    return DWT_CYCCNT;
}

/**
 * @brief Reset DWT cycle counter
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 */
void cm4_dwt_reset_cycle_counter(void)
{
    DWT_CYCCNT = 0;
}

/**
 * @brief Configure DWT comparator
 * @param comp Comparator number (0-3)
 * @param value Comparator value
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 */
void cm4_dwt_set_comparator(uint32_t comp, uint32_t value)
{
    volatile uint32_t *comp_reg = (volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x020 + (comp * 0x10));
    *comp_reg = value;
}

/**
 * @brief Configure DWT comparator mask
 * @param comp Comparator number (0-3)
 * @param mask Mask value (0-15)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 */
void cm4_dwt_set_comparator_mask(uint32_t comp, uint32_t mask)
{
    volatile uint32_t *mask_reg = (volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x024 + (comp * 0x10));
    *mask_reg = mask & 0x0F;
}

/**
 * @brief Configure DWT comparator function
 * @param comp Comparator number (0-3)
 * @param function Function value
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 */
void cm4_dwt_set_comparator_function(uint32_t comp, uint32_t function)
{
    volatile uint32_t *func_reg = (volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x028 + (comp * 0x10));
    *func_reg = function & 0x0F;
}

/**
 * @brief Get sampled PC value
 * @return PC sample value
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 */
uint32_t cm4_dwt_get_pc_sample(void)
{
    return DWT_PCSR;
}
