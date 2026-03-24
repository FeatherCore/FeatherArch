/*
 * ARM Architecture - Cortex-M4 DWT (Data Watchpoint and Trace) Registers
 *
 * ============================================================================
 * File: cm4_dwt.h
 * Description: Cortex-M4 DWT register definitions
 * 描述: Cortex-M4 DWT 寄存器定义
 *
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual (100166_0001_04_en)
 *   - Chapter 9 Data Watchpoint and Trace Unit (page 9-83)
 *   - Table 9-1 DWT register summary (page 9-85)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_DWT_H__
#define __CM4_DWT_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * DWT Registers Base Address
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 * ============================================================================
 */

#define CM4_DWT_BASE_ADDR             0xE0001000UL

/*
 * ============================================================================
 * DWT Control Register (DWT_CTRL)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 * Address: 0xE0001000
 * ============================================================================
 */

#define DWT_CTRL                      (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x000))

/* DWT_CTRL bit definitions */
#define DWT_CTRL_CYCCNTENA_Pos        0U
#define DWT_CTRL_CYCCNTENA_Msk        (1UL << DWT_CTRL_CYCCNTENA_Pos)

/* DWT_CTRL reset values - Reference: Table 9-1 (page 9-85) */
#define DWT_CTRL_RESET_4_COMP         0x40000000UL
#define DWT_CTRL_RESET_4_WP           0x4F000000UL
#define DWT_CTRL_RESET_1_COMP         0x10000000UL
#define DWT_CTRL_RESET_1_WP           0x1F000000UL
#define DWT_CTRL_RESET_NONE           0x00000000UL

/*
 * ============================================================================
 * DWT Cycle Count Register (DWT_CYCCNT)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 * Address: 0xE0001004
 * Reset value: 0x00000000
 * ============================================================================
 */

#define DWT_CYCCNT                    (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x004))

/*
 * ============================================================================
 * DWT CPI Count Register (DWT_CPICNT)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 * Address: 0xE0001008
 * ============================================================================
 */

#define DWT_CPICNT                    (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x008))

/*
 * ============================================================================
 * DWT Exception Overhead Count Register (DWT_EXCCNT)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 * Address: 0xE000100C
 * ============================================================================
 */

#define DWT_EXCCNT                    (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x00C))

/*
 * ============================================================================
 * DWT Sleep Count Register (DWT_SLEEPCNT)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 * Address: 0xE0001010
 * ============================================================================
 */

#define DWT_SLEEPCNT                  (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x010))

/*
 * ============================================================================
 * DWT LSU Count Register (DWT_LSUCNT)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 * Address: 0xE0001014
 * ============================================================================
 */

#define DWT_LSUCNT                    (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x014))

/*
 * ============================================================================
 * DWT Folded-instruction Count Register (DWT_FOLDCNT)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 * Address: 0xE0001018
 * ============================================================================
 */

#define DWT_FOLDCNT                   (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x018))

/*
 * ============================================================================
 * DWT Program Counter Sample Register (DWT_PCSR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 * Address: 0xE000101C
 * ============================================================================
 */

#define DWT_PCSR                      (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x01C))

/*
 * ============================================================================
 * DWT Comparator Registers (DWT_COMP0-DWT_COMP3)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 * ============================================================================
 */

#define DWT_COMP0                     (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x020))
#define DWT_COMP1                     (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x030))
#define DWT_COMP2                     (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x040))
#define DWT_COMP3                     (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x050))

/*
 * ============================================================================
 * DWT Mask Registers (DWT_MASK0-DWT_MASK3)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 * ============================================================================
 */

#define DWT_MASK0                     (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x024))
#define DWT_MASK1                     (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x034))
#define DWT_MASK2                     (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x044))
#define DWT_MASK3                     (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x054))

/* DWT_MASK maximum mask size - Reference: Table 9-1 (page 9-85) */
#define DWT_MASK_MAX_SIZE             0x8000UL

/*
 * ============================================================================
 * DWT Function Registers (DWT_FUNCTION0-DWT_FUNCTION3)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 * ============================================================================
 */

#define DWT_FUNCTION0                 (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x028))
#define DWT_FUNCTION1                 (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x038))
#define DWT_FUNCTION2                 (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x048))
#define DWT_FUNCTION3                 (*(volatile uint32_t *)(CM4_DWT_BASE_ADDR + 0x058))

/* DWT_FUNCTION reset value - Reference: Table 9-1 (page 9-85) */
#define DWT_FUNCTION_RESET_VALUE      0x00000000UL

/* DWT_FUNCTION bit definitions */
#define DWT_FUNCTION_FUNCTION_Pos     0U
#define DWT_FUNCTION_FUNCTION_Msk     (0xFUL << DWT_FUNCTION_FUNCTION_Pos)

#define DWT_FUNCTION_DATAVMATCH_Pos   8U
#define DWT_FUNCTION_DATAVMATCH_Msk   (1UL << DWT_FUNCTION_DATAVMATCH_Pos)

#define DWT_FUNCTION_DATAVSIZE_Pos    10U
#define DWT_FUNCTION_DATAVSIZE_Msk    (3UL << DWT_FUNCTION_DATAVSIZE_Pos)

#define DWT_FUNCTION_DATAVADDR0_Pos   12U
#define DWT_FUNCTION_DATAVADDR0_Msk   (0xFUL << DWT_FUNCTION_DATAVADDR0_Pos)

#define DWT_FUNCTION_DATAVADDR1_Pos   16U
#define DWT_FUNCTION_DATAVADDR1_Msk   (0xFUL << DWT_FUNCTION_DATAVADDR1_Pos)

#define DWT_FUNCTION_MATCHED_Pos      24U
#define DWT_FUNCTION_MATCHED_Msk      (1UL << DWT_FUNCTION_MATCHED_Pos)

/* DWT_FUNCTION values */
#define DWT_FUNCTION_DISABLED         0x0UL
#define DWT_FUNCTION_WP_CYCLE         0x1UL
#define DWT_FUNCTION_WP_DATA_RO       0x2UL
#define DWT_FUNCTION_WP_DATA_WO       0x3UL
#define DWT_FUNCTION_WP_DATA_RW       0x4UL
#define DWT_FUNCTION_WP_INST          0x8UL
#define DWT_FUNCTION_ETM_TRIGGER      0x9UL

/*
 * ============================================================================
 * DWT Function Declarations
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 9 (page 9-83)
 * ============================================================================
 */

/**
 * @brief Enable DWT cycle counter
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 9.1 (page 9-84)
 */
void cm4_dwt_enable_cycle_counter(void);

/**
 * @brief Disable DWT cycle counter
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 9.1 (page 9-84)
 */
void cm4_dwt_disable_cycle_counter(void);

/**
 * @brief Get DWT cycle count
 * @return Current cycle count
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 */
uint32_t cm4_dwt_get_cycle_count(void);

/**
 * @brief Reset DWT cycle counter
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 */
void cm4_dwt_reset_cycle_counter(void);

/**
 * @brief Configure DWT comparator
 * @param comp Comparator number (0-3)
 * @param value Comparator value
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 */
void cm4_dwt_set_comparator(uint32_t comp, uint32_t value);

/**
 * @brief Configure DWT comparator mask
 * @param comp Comparator number (0-3)
 * @param mask Mask value (0-15)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 */
void cm4_dwt_set_comparator_mask(uint32_t comp, uint32_t mask);

/**
 * @brief Configure DWT comparator function
 * @param comp Comparator number (0-3)
 * @param function Function value
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 */
void cm4_dwt_set_comparator_function(uint32_t comp, uint32_t function);

/**
 * @brief Get sampled PC value
 * @return PC sample value
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 9-1 (page 9-85)
 */
uint32_t cm4_dwt_get_pc_sample(void);

#ifdef __cplusplus
}
#endif

#endif /* __CM4_DWT_H__ */
