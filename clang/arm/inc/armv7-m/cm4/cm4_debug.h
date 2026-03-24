/*
 * ARM Architecture - Cortex-M4 Debug Registers
 *
 * ============================================================================
 * File: cm4_debug.h
 * Description: Cortex-M4 debug register definitions
 * 描述: Cortex-M4 调试寄存器定义
 *
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual (100166_0001_04_en)
 *   - Chapter 8 Debug (page 8-72)
 *   - Table 8-4 Debug registers (page 8-77)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_DEBUG_H__
#define __CM4_DEBUG_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * Debug Registers Base Address
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 8-4 (page 8-77)
 * ============================================================================
 */

#define CM4_DEBUG_BASE_ADDR           0xE000EDF0UL

/*
 * ============================================================================
 * Debug Fault Status Register (DFSR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 8-4 (page 8-77)
 * Address: 0xE000ED30
 * Reset value: 0x00000000 (Power-on reset only)
 * ============================================================================
 */

#define DEBUG_DFSR                    (*(volatile uint32_t *)(0xE000ED30UL))

/* DFSR bit definitions */
#define DEBUG_DFSR_HALTED_Pos         0U
#define DEBUG_DFSR_HALTED_Msk         (1UL << DEBUG_DFSR_HALTED_Pos)

#define DEBUG_DFSR_BKPT_Pos           1U
#define DEBUG_DFSR_BKPT_Msk           (1UL << DEBUG_DFSR_BKPT_Pos)

#define DEBUG_DFSR_DWTTRAP_Pos        2U
#define DEBUG_DFSR_DWTTRAP_Msk        (1UL << DEBUG_DFSR_DWTTRAP_Pos)

#define DEBUG_DFSR_VCATCH_Pos         3U
#define DEBUG_DFSR_VCATCH_Msk         (1UL << DEBUG_DFSR_VCATCH_Pos)

#define DEBUG_DFSR_EXTERNAL_Pos       4U
#define DEBUG_DFSR_EXTERNAL_Msk       (1UL << DEBUG_DFSR_EXTERNAL_Pos)

/*
 * ============================================================================
 * Debug Halting Control and Status Register (DHCSR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 8-4 (page 8-77)
 * Address: 0xE000EDF0
 * Reset value: 0x00000000
 * ============================================================================
 */

#define DEBUG_DHCSR                   (*(volatile uint32_t *)(CM4_DEBUG_BASE_ADDR + 0x000))

/* DHCSR bit definitions */
#define DEBUG_DHCSR_C_DEBUGEN_Pos     0U
#define DEBUG_DHCSR_C_DEBUGEN_Msk     (1UL << DEBUG_DHCSR_C_DEBUGEN_Pos)

#define DEBUG_DHCSR_C_HALT_Pos        1U
#define DEBUG_DHCSR_C_HALT_Msk        (1UL << DEBUG_DHCSR_C_HALT_Pos)

#define DEBUG_DHCSR_C_STEP_Pos        2U
#define DEBUG_DHCSR_C_STEP_Msk        (1UL << DEBUG_DHCSR_C_STEP_Pos)

#define DEBUG_DHCSR_C_MASKINTS_Pos    3U
#define DEBUG_DHCSR_C_MASKINTS_Msk    (1UL << DEBUG_DHCSR_C_MASKINTS_Pos)

#define DEBUG_DHCSR_C_SNAPSTALL_Pos   5U
#define DEBUG_DHCSR_C_SNAPSTALL_Msk   (1UL << DEBUG_DHCSR_C_SNAPSTALL_Pos)

#define DEBUG_DHCSR_S_REGRDY_Pos      16U
#define DEBUG_DHCSR_S_REGRDY_Msk      (1UL << DEBUG_DHCSR_S_REGRDY_Pos)

#define DEBUG_DHCSR_S_HALT_Pos        17U
#define DEBUG_DHCSR_S_HALT_Msk        (1UL << DEBUG_DHCSR_S_HALT_Pos)

#define DEBUG_DHCSR_S_SLEEP_Pos       18U
#define DEBUG_DHCSR_S_SLEEP_Msk       (1UL << DEBUG_DHCSR_S_SLEEP_Pos)

#define DEBUG_DHCSR_S_LOCKUP_Pos      19U
#define DEBUG_DHCSR_S_LOCKUP_Msk      (1UL << DEBUG_DHCSR_S_LOCKUP_Pos)

#define DEBUG_DHCSR_S_RETIRE_ST_Pos   24U
#define DEBUG_DHCSR_S_RETIRE_ST_Msk   (1UL << DEBUG_DHCSR_S_RETIRE_ST_Pos)

#define DEBUG_DHCSR_S_RESET_ST_Pos    25U
#define DEBUG_DHCSR_S_RESET_ST_Msk    (1UL << DEBUG_DHCSR_S_RESET_ST_Pos)

/* DHCSR write key */
#define DEBUG_DHCSR_DBGKEY_Pos        16U
#define DEBUG_DHCSR_DBGKEY_Msk        (0xFFFFUL << DEBUG_DHCSR_DBGKEY_Pos)
#define DEBUG_DHCSR_DBGKEY_VALUE      0xA05FUL

/*
 * ============================================================================
 * Debug Core Register Selector Register (DCRSR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 8-4 (page 8-77)
 * Address: 0xE000EDF4
 * ============================================================================
 */

#define DEBUG_DCRSR                   (*(volatile uint32_t *)(CM4_DEBUG_BASE_ADDR + 0x004))

/* DCRSR bit definitions */
#define DEBUG_DCRSR_REGSEL_Pos        0U
#define DEBUG_DCRSR_REGSEL_Msk        (0x1FUL << DEBUG_DCRSR_REGSEL_Pos)

#define DEBUG_DCRSR_REGWnR_Pos        16U
#define DEBUG_DCRSR_REGWnR_Msk        (1UL << DEBUG_DCRSR_REGWnR_Pos)

/* Register selectors */
#define DEBUG_DCRSR_REGSEL_R0         0x00UL
#define DEBUG_DCRSR_REGSEL_R1         0x01UL
#define DEBUG_DCRSR_REGSEL_R2         0x02UL
#define DEBUG_DCRSR_REGSEL_R3         0x03UL
#define DEBUG_DCRSR_REGSEL_R4         0x04UL
#define DEBUG_DCRSR_REGSEL_R5         0x05UL
#define DEBUG_DCRSR_REGSEL_R6         0x06UL
#define DEBUG_DCRSR_REGSEL_R7         0x07UL
#define DEBUG_DCRSR_REGSEL_R8         0x08UL
#define DEBUG_DCRSR_REGSEL_R9         0x09UL
#define DEBUG_DCRSR_REGSEL_R10        0x0AUL
#define DEBUG_DCRSR_REGSEL_R11        0x0BUL
#define DEBUG_DCRSR_REGSEL_R12        0x0CUL
#define DEBUG_DCRSR_REGSEL_SP         0x0DUL
#define DEBUG_DCRSR_REGSEL_LR         0x0EUL
#define DEBUG_DCRSR_REGSEL_DBGRET     0x0FUL
#define DEBUG_DCRSR_REGSEL_XPSR       0x10UL
#define DEBUG_DCRSR_REGSEL_MSP        0x11UL
#define DEBUG_DCRSR_REGSEL_PSP        0x12UL
#define DEBUG_DCRSR_REGSEL_CTRL       0x14UL
#define DEBUG_DCRSR_REGSEL_FPSCR      0x21UL
#define DEBUG_DCRSR_REGSEL_S0         0x40UL
#define DEBUG_DCRSR_REGSEL_S31        0x5FUL

/*
 * ============================================================================
 * Debug Core Register Data Register (DCRDR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 8-4 (page 8-77)
 * Address: 0xE000EDF8
 * ============================================================================
 */

#define DEBUG_DCRDR                   (*(volatile uint32_t *)(CM4_DEBUG_BASE_ADDR + 0x008))

/*
 * ============================================================================
 * Debug Exception and Monitor Control Register (DEMCR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 8-4 (page 8-77)
 * Address: 0xE000EDFC
 * Reset value: 0x00000000
 * ============================================================================
 */

#define DEBUG_DEMCR                   (*(volatile uint32_t *)(CM4_DEBUG_BASE_ADDR + 0x00C))

/* DEMCR bit definitions */
#define DEBUG_DEMCR_VC_CORERESET_Pos  0U
#define DEBUG_DEMCR_VC_CORERESET_Msk  (1UL << DEBUG_DEMCR_VC_CORERESET_Pos)

#define DEBUG_DEMCR_VC_MMERR_Pos      4U
#define DEBUG_DEMCR_VC_MMERR_Msk      (1UL << DEBUG_DEMCR_VC_MMERR_Pos)

#define DEBUG_DEMCR_VC_NOCPERR_Pos    5U
#define DEBUG_DEMCR_VC_NOCPERR_Msk    (1UL << DEBUG_DEMCR_VC_NOCPERR_Pos)

#define DEBUG_DEMCR_VC_CHKERR_Pos     6U
#define DEBUG_DEMCR_VC_CHKERR_Msk     (1UL << DEBUG_DEMCR_VC_CHKERR_Pos)

#define DEBUG_DEMCR_VC_STATERR_Pos    7U
#define DEBUG_DEMCR_VC_STATERR_Msk    (1UL << DEBUG_DEMCR_VC_STATERR_Pos)

#define DEBUG_DEMCR_VC_BUSERR_Pos     8U
#define DEBUG_DEMCR_VC_BUSERR_Msk     (1UL << DEBUG_DEMCR_VC_BUSERR_Pos)

#define DEBUG_DEMCR_VC_INTERR_Pos     9U
#define DEBUG_DEMCR_VC_INTERR_Msk     (1UL << DEBUG_DEMCR_VC_INTERR_Pos)

#define DEBUG_DEMCR_VC_HARDERR_Pos    10U
#define DEBUG_DEMCR_VC_HARDERR_Msk    (1UL << DEBUG_DEMCR_VC_HARDERR_Pos)

#define DEBUG_DEMCR_MON_EN_Pos        16U
#define DEBUG_DEMCR_MON_EN_Msk        (1UL << DEBUG_DEMCR_MON_EN_Pos)

#define DEBUG_DEMCR_MON_PEND_Pos      17U
#define DEBUG_DEMCR_MON_PEND_Msk      (1UL << DEBUG_DEMCR_MON_PEND_Pos)

#define DEBUG_DEMCR_MON_STEP_Pos      18U
#define DEBUG_DEMCR_MON_STEP_Msk      (1UL << DEBUG_DEMCR_MON_STEP_Pos)

#define DEBUG_DEMCR_MON_REQ_Pos       19U
#define DEBUG_DEMCR_MON_REQ_Msk       (1UL << DEBUG_DEMCR_MON_REQ_Pos)

#define DEBUG_DEMCR_TRCENA_Pos        24U
#define DEBUG_DEMCR_TRCENA_Msk        (1UL << DEBUG_DEMCR_TRCENA_Pos)

/*
 * ============================================================================
 * Debug Function Declarations
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 8 (page 8-72)
 * ============================================================================
 */

/**
 * @brief Enable debug
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 8.1 (page 8-72)
 */
void cm4_debug_enable(void);

/**
 * @brief Disable debug
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 8.1 (page 8-72)
 */
void cm4_debug_disable(void);

/**
 * @brief Halt the processor
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 8.1 (page 8-72)
 */
void cm4_debug_halt(void);

/**
 * @brief Check if processor is halted
 * @return 1 if halted, 0 if not
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 8.1 (page 8-72)
 */
int cm4_debug_is_halted(void);

/**
 * @brief Enable trace
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 8.1 (page 8-72)
 */
void cm4_debug_enable_trace(void);

/**
 * @brief Disable trace
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 8.1 (page 8-72)
 */
void cm4_debug_disable_trace(void);

#ifdef __cplusplus
}
#endif

#endif /* __CM4_DEBUG_H__ */
