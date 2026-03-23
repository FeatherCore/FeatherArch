/*
 * ARM Architecture - ARMv7-M Debug and Trace
 *
 * ============================================================================
 * File: armv7-m_debug.h
 * Description: ARMv7-M debug and trace component definitions
 * 描述: ARMv7-M 调试和跟踪组件定义
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter C1: Debug
 *   - Table C1-21 DWT register summary (page C1-736)
 *   - Table C1-11 ITM register summary (page C1-713)
 *   - Table C1-22 FPB register summary (page C1-756)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_DEBUG_H__
#define __ARCH_ARM_V7M_DEBUG_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv7-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * Debug Base Addresses
 * 调试基地址
 * Reference: Table C1-10 Debug register regions (page C1-699)
 * ============================================================================
 */

#define DWT_BASE_ADDR             0xE0001000UL
#define ITM_BASE_ADDR             0xE0000000UL
#define FPB_BASE_ADDR             0xE0002000UL  /* Flash Patch and Breakpoint Unit */

/*
 * ============================================================================
 * DWT (Data Watchpoint and Trace) Register Definitions
 * DWT 寄存器定义
 * Reference: Table C1-21 DWT register summary (page C1-736)
 * ============================================================================
 */

/**
 * DWT Control Register (DWT_CTRL)
 * Address: 0xE0001000
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-737
 */
#define DWT_CTRL                  (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x000))

/**
 * DWT Cycle Count Register (DWT_CYCCNT)
 * Address: 0xE0001004
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-741
 */
#define DWT_CYCCNT                (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x004))

/**
 * DWT CPI Count Register (DWT_CPICNT)
 * Address: 0xE0001008
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-741
 */
#define DWT_CPICNT                (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x008))

/**
 * DWT Exception Overhead Count Register (DWT_EXCCNT)
 * Address: 0xE000100C
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-742
 */
#define DWT_EXCCNT                (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x00C))

/**
 * DWT Sleep Count Register (DWT_SLEEPCNT)
 * Address: 0xE0001010
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-742
 */
#define DWT_SLEEPCNT              (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x010))

/**
 * DWT LSU Count Register (DWT_LSUCNT)
 * Address: 0xE0001014
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-743
 */
#define DWT_LSUCNT                (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x014))

/**
 * DWT Folded Instruction Count Register (DWT_FOLDCNT)
 * Address: 0xE0001018
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-744
 */
#define DWT_FOLDCNT               (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x018))

/**
 * DWT Program Counter Sample Register (DWT_PCSR)
 * Address: 0xE000101C
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-745
 */
#define DWT_PCSR                  (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x01C))

/**
 * DWT Comparator Register n (DWT_COMPn)
 * Address: 0xE0001020 + 16*n
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-745
 */
#define DWT_COMP(n)               (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x020 + ((n) * 0x10)))

/**
 * DWT Comparator Mask Register n (DWT_MASKn)
 * Address: 0xE0001024 + 16*n
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-745
 */
#define DWT_MASK(n)               (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x024 + ((n) * 0x10)))

/**
 * DWT Comparator Function Register n (DWT_FUNCTIONn)
 * Address: 0xE0001028 + 16*n
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-746
 */
#define DWT_FUNCTION(n)           (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x028 + ((n) * 0x10)))

/*
 * ============================================================================
 * ITM (Instrumentation Trace Macrocell) Register Definitions
 * ITM 寄存器定义
 * Reference: Table C1-11 ITM register summary (page C1-713)
 * ============================================================================
 */

/**
 * ITM Stimulus Port Register n (ITM_STIMn)
 * Address: 0xE0000000 + 4*n
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-714
 */
#define ITM_STIM(n)               (*(volatile uint32_t *)(ITM_BASE_ADDR + ((n) * 4)))

/**
 * ITM Trace Enable Register n (ITM_TERn)
 * Address: 0xE0000E00 + 4*n
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-715
 */
#define ITM_TER(n)                (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xE00 + ((n) * 4)))

/**
 * ITM Trace Privilege Register (ITM_TPR)
 * Address: 0xE0000E40
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-716
 */
#define ITM_TPR                   (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xE40))

/**
 * ITM Trace Control Register (ITM_TCR)
 * Address: 0xE0000E80
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-716
 */
#define ITM_TCR                   (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xE80))

/*
 * ============================================================================
 * FPB (Flash Patch and Breakpoint) Register Definitions
 * FPB 寄存器定义
 * Reference: Table C1-22 FPB register summary (page C1-756)
 * ============================================================================
 */

/**
 * Flash Patch Control Register (FP_CTRL)
 * Address: 0xE0002000
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-756
 */
#define FP_CTRL                   (*(volatile uint32_t *)(FPB_BASE_ADDR + 0x000))

/**
 * Flash Patch Remap Register (FP_REMAP)
 * Address: 0xE0002004
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-758
 */
#define FP_REMAP                  (*(volatile uint32_t *)(FPB_BASE_ADDR + 0x004))

/**
 * Flash Patch Comparator Register n (FP_COMPn)
 * Address: 0xE0002008 + 4*n
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-758
 */
#define FP_COMP(n)                (*(volatile uint32_t *)(FPB_BASE_ADDR + 0x008 + ((n) * 4)))

/*
 * ============================================================================
 * DWT Register Bit Definitions
 * DWT 寄存器位定义
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-737
 * ============================================================================
 */

#define DWT_CTRL_NUMCOMP_Pos      28U
#define DWT_CTRL_NUMCOMP_Msk      (0xFUL << DWT_CTRL_NUMCOMP_Pos)
#define DWT_CTRL_NOTRCPKT_Pos     27U
#define DWT_CTRL_NOTRCPKT_Msk     (1UL << DWT_CTRL_NOTRCPKT_Pos)
#define DWT_CTRL_NOEXTTRIG_Pos    26U
#define DWT_CTRL_NOEXTTRIG_Msk    (1UL << DWT_CTRL_NOEXTTRIG_Pos)
#define DWT_CTRL_NOCYCCNT_Pos     25U
#define DWT_CTRL_NOCYCCNT_Msk     (1UL << DWT_CTRL_NOCYCCNT_Pos)
#define DWT_CTRL_NOPRFCNT_Pos     24U
#define DWT_CTRL_NOPRFCNT_Msk     (1UL << DWT_CTRL_NOPRFCNT_Pos)
#define DWT_CTRL_CYCEVTENA_Pos    22U
#define DWT_CTRL_CYCEVTENA_Msk    (1UL << DWT_CTRL_CYCEVTENA_Pos)
#define DWT_CTRL_FOLDEVTENA_Pos   21U
#define DWT_CTRL_FOLDEVTENA_Msk   (1UL << DWT_CTRL_FOLDEVTENA_Pos)
#define DWT_CTRL_LSUEVTENA_Pos    20U
#define DWT_CTRL_LSUEVTENA_Msk    (1UL << DWT_CTRL_LSUEVTENA_Pos)
#define DWT_CTRL_SLEEPEVTENA_Pos  19U
#define DWT_CTRL_SLEEPEVTENA_Msk  (1UL << DWT_CTRL_SLEEPEVTENA_Pos)
#define DWT_CTRL_EXCEVTENA_Pos    18U
#define DWT_CTRL_EXCEVTENA_Msk    (1UL << DWT_CTRL_EXCEVTENA_Pos)
#define DWT_CTRL_CPIEVTENA_Pos    17U
#define DWT_CTRL_CPIEVTENA_Msk    (1UL << DWT_CTRL_CPIEVTENA_Pos)
#define DWT_CTRL_EXCTRCENA_Pos    16U
#define DWT_CTRL_EXCTRCENA_Msk    (1UL << DWT_CTRL_EXCTRCENA_Pos)
#define DWT_CTRL_PCSAMPLENA_Pos   12U
#define DWT_CTRL_PCSAMPLENA_Msk   (1UL << DWT_CTRL_PCSAMPLENA_Pos)
#define DWT_CTRL_SYNCTAP_Pos      10U
#define DWT_CTRL_SYNCTAP_Msk      (3UL << DWT_CTRL_SYNCTAP_Pos)
#define DWT_CTRL_CYCTAP_Pos       9U
#define DWT_CTRL_CYCTAP_Msk       (1UL << DWT_CTRL_CYCTAP_Pos)
#define DWT_CTRL_POSTINIT_Pos     5U
#define DWT_CTRL_POSTINIT_Msk     (0xFUL << DWT_CTRL_POSTINIT_Pos)
#define DWT_CTRL_POSTPRESET_Pos   1U
#define DWT_CTRL_POSTPRESET_Msk   (0xFUL << DWT_CTRL_POSTPRESET_Pos)
#define DWT_CTRL_CYCCNTENA_Pos    0U
#define DWT_CTRL_CYCCNTENA_Msk    (1UL << DWT_CTRL_CYCCNTENA_Pos)

/* DWT_FUNCTION Register Bits */
#define DWT_FUNCTION_MATCHED_Pos  24U
#define DWT_FUNCTION_MATCHED_Msk  (1UL << DWT_FUNCTION_MATCHED_Pos)
#define DWT_FUNCTION_DATAVMATCH_Pos 8U
#define DWT_FUNCTION_DATAVMATCH_Msk (1UL << DWT_FUNCTION_DATAVMATCH_Pos)
#define DWT_FUNCTION_CYCMATCH_Pos 7U
#define DWT_FUNCTION_CYCMATCH_Msk (1UL << DWT_FUNCTION_CYCMATCH_Pos)
#define DWT_FUNCTION_EMITRANGE_Pos 5U
#define DWT_FUNCTION_EMITRANGE_Msk (1UL << DWT_FUNCTION_EMITRANGE_Pos)
#define DWT_FUNCTION_FUNCTION_Pos 0U
#define DWT_FUNCTION_FUNCTION_Msk (0xFUL << DWT_FUNCTION_FUNCTION_Pos)

/* DWT Function Values */
#define DWT_FUNCTION_FUNCTION_DISABLED     0x0U
#define DWT_FUNCTION_FUNCTION_CYCCNT       0x1U  /* Comparator 0 only */
#define DWT_FUNCTION_FUNCTION_INSTR_ADDR   0x4U
#define DWT_FUNCTION_FUNCTION_INSTR_ADDR2  0x8U
#define DWT_FUNCTION_FUNCTION_DATA_ADDR_RD 0x5U
#define DWT_FUNCTION_FUNCTION_DATA_ADDR_WR 0x6U
#define DWT_FUNCTION_FUNCTION_DATA_ADDR_RW 0x7U
#define DWT_FUNCTION_FUNCTION_DATA_VAL_RD  0x9U
#define DWT_FUNCTION_FUNCTION_DATA_VAL_WR  0xAU
#define DWT_FUNCTION_FUNCTION_DATA_VAL_RW  0xBU
#define DWT_FUNCTION_FUNCTION_PC_TRACE     0xCU
#define DWT_FUNCTION_FUNCTION_PC_DATA_RD   0xDU
#define DWT_FUNCTION_FUNCTION_PC_DATA_WR   0xEU
#define DWT_FUNCTION_FUNCTION_PC_DATA_RW   0xFU

/*
 * ============================================================================
 * ITM Register Bit Definitions
 * ITM 寄存器位定义
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-716
 * ============================================================================
 */

#define ITM_TCR_BUSY_Pos          23U
#define ITM_TCR_BUSY_Msk          (1UL << ITM_TCR_BUSY_Pos)
#define ITM_TCR_TRACEBUSID_Pos    16U
#define ITM_TCR_TRACEBUSID_Msk    (0x7FUL << ITM_TCR_TRACEBUSID_Pos)
#define ITM_TCR_GTSFREQ_Pos       10U
#define ITM_TCR_GTSFREQ_Msk       (3UL << ITM_TCR_GTSFREQ_Pos)
#define ITM_TCR_TSPRESCALE_Pos    8U
#define ITM_TCR_TSPRESCALE_Msk    (3UL << ITM_TCR_TSPRESCALE_Pos)
#define ITM_TCR_SWOENA_Pos        4U
#define ITM_TCR_SWOENA_Msk        (1UL << ITM_TCR_SWOENA_Pos)
#define ITM_TCR_TXENA_Pos         3U
#define ITM_TCR_TXENA_Msk         (1UL << ITM_TCR_TXENA_Pos)
#define ITM_TCR_SYNCENA_Pos       2U
#define ITM_TCR_SYNCENA_Msk       (1UL << ITM_TCR_SYNCENA_Pos)
#define ITM_TCR_TSENA_Pos         1U
#define ITM_TCR_TSENA_Msk         (1UL << ITM_TCR_TSENA_Pos)
#define ITM_TCR_ITMENA_Pos        0U
#define ITM_TCR_ITMENA_Msk        (1UL << ITM_TCR_ITMENA_Pos)

/*
 * ============================================================================
 * FPB Register Bit Definitions
 * FPB 寄存器位定义
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-756
 * ============================================================================
 */

#define FP_CTRL_NUM_CODE_Pos      8U
#define FP_CTRL_NUM_CODE_Msk      (0xFUL << FP_CTRL_NUM_CODE_Pos)
#define FP_CTRL_NUM_LIT_Pos       4U
#define FP_CTRL_NUM_LIT_Msk       (0xFUL << FP_CTRL_NUM_LIT_Pos)
#define FP_CTRL_KEY_Pos           1U
#define FP_CTRL_KEY_Msk           (1UL << FP_CTRL_KEY_Pos)
#define FP_CTRL_ENABLE_Pos        0U
#define FP_CTRL_ENABLE_Msk        (1UL << FP_CTRL_ENABLE_Pos)

#define FP_COMP_REPLACE_Pos       30U
#define FP_COMP_REPLACE_Msk       (3UL << FP_COMP_REPLACE_Pos)
#define FP_COMP_COMP_Pos          2U
#define FP_COMP_COMP_Msk          (0x1FFFFFFFUL << FP_COMP_COMP_Pos)
#define FP_COMP_ENABLE_Pos        0U
#define FP_COMP_ENABLE_Msk        (1UL << FP_COMP_ENABLE_Pos)

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Enable DWT
 */
void dwt_enable(void);

/**
 * @brief Disable DWT
 */
void dwt_disable(void);

/**
 * @brief Enable DWT cycle counter
 */
void dwt_enable_cycle_counter(void);

/**
 * @brief Disable DWT cycle counter
 */
void dwt_disable_cycle_counter(void);

/**
 * @brief Get DWT cycle counter value
 * @return Cycle count
 */
static inline uint32_t dwt_get_cycle_counter(void) {
    return DWT_CYCCNT;
}

/**
 * @brief Reset DWT cycle counter
 */
static inline void dwt_reset_cycle_counter(void) {
    DWT_CYCCNT = 0U;
}

/**
 * @brief Get number of DWT comparators
 * @return Number of comparators
 */
static inline uint32_t dwt_get_num_comparators(void) {
    return (DWT_CTRL & DWT_CTRL_NUMCOMP_Msk) >> DWT_CTRL_NUMCOMP_Pos;
}

/**
 * @brief Configure DWT comparator
 * @param comp Comparator number
 * @param addr Address to compare
 * @param action Action to take on match
 */
void dwt_configure_comparator(uint32_t comp, uint32_t addr, uint32_t action);

/**
 * @brief Enable DWT comparator
 * @param comp Comparator number
 */
void dwt_enable_comparator(uint32_t comp);

/**
 * @brief Disable DWT comparator
 * @param comp Comparator number
 */
void dwt_disable_comparator(uint32_t comp);

/**
 * @brief Enable ITM
 */
void itm_enable(void);

/**
 * @brief Disable ITM
 */
void itm_disable(void);

/**
 * @brief Check if ITM stimulus port is ready
 * @param port Port number (0-31)
 * @return true if ready
 */
static inline bool itm_stimulus_port_ready(uint32_t port) {
    return (ITM_STIM(port) & 0x1U) != 0U;
}

/**
 * @brief Write to ITM stimulus port
 * @param port Port number (0-31)
 * @param value Value to write
 */
static inline void itm_stimulus_port_write(uint32_t port, uint32_t value) {
    ITM_STIM(port) = value;
}

/**
 * @brief Send character via ITM
 * @param ch Character to send
 * @return Character sent
 */
int32_t itm_send_char(int32_t ch);

/**
 * @brief Receive character via ITM
 * @return Character received or -1 if no data
 */
int32_t itm_receive_char(void);

/**
 * @brief Enable ITM stimulus port
 * @param port Port number
 */
void itm_enable_stimulus_port(uint32_t port);

/**
 * @brief Disable ITM stimulus port
 * @param port Port number
 */
void itm_disable_stimulus_port(uint32_t port);

/**
 * @brief Enable FPB
 */
void fpb_enable(void);

/**
 * @brief Disable FPB
 */
void fpb_disable(void);

/**
 * @brief Set FPB breakpoint
 * @param bp Breakpoint number
 * @param addr Address
 * @return 0 on success, -1 on error
 */
int32_t fpb_set_breakpoint(uint32_t bp, uint32_t addr);

/**
 * @brief Clear FPB breakpoint
 * @param bp Breakpoint number
 */
void fpb_clear_breakpoint(uint32_t bp);

/**
 * @brief Get number of FPB breakpoints
 * @return Number of breakpoints
 */
uint32_t fpb_get_num_breakpoints(void);

/**
 * @brief Get number of FPB literal comparators
 * @return Number of literal comparators
 */
uint32_t fpb_get_num_literals(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_DEBUG_H__ */
