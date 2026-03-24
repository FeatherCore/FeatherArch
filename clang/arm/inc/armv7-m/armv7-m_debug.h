/*
 * ARM Architecture - ARMv7-M Debug Architecture
 *
 * ============================================================================
 * File: armv7-m_debug.h
 * Description: ARMv7-M Debug Architecture register definitions and function declarations
 * 描述: ARMv7-M 调试架构寄存器定义和函数声明
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter C1: Debug Architecture
 *     * C1.1 Introduction to Armv7-M debug (page C1-682)
 *       - Invasive debug: halt processor, DebugMonitor exception
 *       - Non-invasive debug: ITM application trace, program trace and profiling
 *     * C1.2 The Debug Access Port (page C1-686)
 *       - ADIv5 interface for debugger access
 *       - ROM Table for component identification
 *     * C1.3 Armv7-M debug features (page C1-679)
 *       - Local reset, processor halt, step, register access
 *       - Software/hardware breakpoints, watchpoints
 *     * C1.4 Debug and reset (page C1-694)
 *       - Debug state behavior during reset
 *     * C1.5 Debug event behavior (page C1-695)
 *       - Debug event types and prioritization
 *       - Debug stepping mechanism
 *     * C1.6 Debug system registers (page C1-699)
 *       - DFSR, DHCSR, DCRSR, DCRDR, DEMCR registers
 *     * C1.7 The Instrumentation Trace Macrocell (page C1-709)
 *       - ITM stimulus ports, trace enable, privilege control
 *       - Local and global timestamp support
 *     * C1.8 The Data Watchpoint and Trace unit (page C1-719)
 *       - DWT comparators for watchpoints and data tracing
 *       - PC sampling, exception trace, profiling counters
 *       - CYCCNT cycle counter
 *     * C1.9 Embedded Trace Macrocell support (page C1-749)
 *       - Instruction tracing support
 *     * C1.10 Trace Port Interface Unit (page C1-750)
 *       - TPIU for external trace interface
 *     * C1.11 Flash Patch and Breakpoint unit (page C1-755)
 *       - FPB for code patching and breakpoints
 *       - Instruction and literal address remapping
 *
 * Debug Component Address Map (Table C1-1, page C1-683):
 *   - ITM:  0xE0000000-0xE0000FFF
 *   - DWT:  0xE0001000-0xE0001FFF
 *   - FPB:  0xE0002000-0xE0002FFF
 *   - SCS:  0xE000ED00-0xE000EFFF (includes DCB at 0xE000EDF0)
 *   - TPIU: 0xE0040000-0xE0040FFF
 *   - ETM:  0xE0041000-0xE0041FFF
 *   - ROM:  0xE00FF000-0xE00FFFFF
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
 * Reference: Table C1-1 PPB debug related regions (page C1-683)
 * ============================================================================
 */

#define ITM_BASE_ADDR             0xE0000000UL  /* Instrumentation Trace Macrocell */
#define DWT_BASE_ADDR             0xE0001000UL  /* Data Watchpoint and Trace unit */
#define FPB_BASE_ADDR             0xE0002000UL  /* Flash Patch and Breakpoint Unit */
#define TPIU_BASE_ADDR            0xE0040000UL  /* Trace Port Interface Unit */
#define ETM_BASE_ADDR             0xE0041000UL  /* Embedded Trace Macrocell */
#define ROM_TABLE_ADDR            0xE00FF000UL  /* ROM Table */

/*
 * ============================================================================
 * ITM (Instrumentation Trace Macrocell) Register Definitions
 * ITM 寄存器定义
 * Reference: C1.7 The Instrumentation Trace Macrocell (page C1-709)
 *            Table C1-11 ITM register summary (page C1-713)
 * ============================================================================
 */

/**
 * ITM Stimulus Port Register n (ITM_STIMn)
 * Address: 0xE0000000 + 4*n (n = 0-255)
 * Reference: Arm(R) v7-M ARM, C1.7.3 Stimulus Port registers (page C1-714)
 * 
 * Purpose: Software writes to these registers to generate Instrumentation packets.
 * Bit[0]: FIFO ready status (read), Reserved (write)
 * Bits[31:0]: Stimulus data
 */
#define ITM_STIM(n)               (*(volatile uint32_t *)(ITM_BASE_ADDR + ((n) * 4)))

/**
 * ITM Trace Enable Register n (ITM_TERn)
 * Address: 0xE0000E00 + 4*n (n = 0-7)
 * Reference: Arm(R) v7-M ARM, C1.7.4 Trace Enable Registers (page C1-714)
 * 
 * Purpose: Each bit enables the corresponding stimulus port.
 * Bit[n]: Enable stimulus port (32*n + n)
 */
#define ITM_TER(n)                (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xE00 + ((n) * 4)))

/**
 * ITM Trace Privilege Register (ITM_TPR)
 * Address: 0xE0000E40
 * Reference: Arm(R) v7-M ARM, C1.7.5 Trace Privilege Register (page C1-715)
 * 
 * Purpose: Defines privilege level for stimulus ports.
 * Bit[n]: Privilege bit for stimulus ports 8*n to 8*n+7
 *         0 = Unprivileged access permitted
 *         1 = Privileged access only
 */
#define ITM_TPR                   (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xE40))

/**
 * ITM Trace Control Register (ITM_TCR)
 * Address: 0xE0000E80
 * Reference: Arm(R) v7-M ARM, C1.7.6 Trace Control Register (page C1-716)
 * 
 * Purpose: Main control register for ITM operation.
 */
#define ITM_TCR                   (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xE80))

/**
 * ITM Integration Mode Control Register (ITM_ITMCR)
 * Address: 0xE0000F00
 * Reference: Arm(R) v7-M ARM, Integration testing (page C1-718)
 */
#define ITM_ITMCR                 (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xF00))

/**
 * ITM Integration Mode Read Register (ITM_IIR)
 * Address: 0xE0000F04
 */
#define ITM_IIR                   (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xF04))

/**
 * ITM Integration Mode Write Register (ITM_IMCR)
 * Address: 0xE0000F08
 */
#define ITM_IMCR                  (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xF08))

/*
 * ============================================================================
 * ITM Register Bit Definitions
 * ITM 寄存器位定义
 * Reference: C1.7.6 Trace Control Register, ITM_TCR (page C1-716)
 * ============================================================================
 */

#define ITM_TCR_BUSY_Pos          23U
#define ITM_TCR_BUSY_Msk          (1UL << ITM_TCR_BUSY_Pos)           /*!< ITM busy flag (read-only) */
#define ITM_TCR_TRACEBUSID_Pos    16U
#define ITM_TCR_TRACEBUSID_Msk    (0x7FUL << ITM_TCR_TRACEBUSID_Pos)  /*!< Trace bus ID for multi-source trace */
#define ITM_TCR_GTSFREQ_Pos       10U
#define ITM_TCR_GTSFREQ_Msk       (3UL << ITM_TCR_GTSFREQ_Pos)        /*!< Global timestamp frequency */
#define ITM_TCR_TSPRESCALE_Pos    8U
#define ITM_TCR_TSPRESCALE_Msk    (3UL << ITM_TCR_TSPRESCALE_Pos)     /*!< Local timestamp prescaler */
#define ITM_TCR_SWOENA_Pos        4U
#define ITM_TCR_SWOENA_Msk        (1UL << ITM_TCR_SWOENA_Pos)         /*!< SWO encoding mode enable */
#define ITM_TCR_TXENA_Pos         3U
#define ITM_TCR_TXENA_Msk         (1UL << ITM_TCR_TXENA_Pos)          /*!< DWT packets transmission enable */
#define ITM_TCR_SYNCENA_Pos       2U
#define ITM_TCR_SYNCENA_Msk       (1UL << ITM_TCR_SYNCENA_Pos)        /*!< Synchronization packet enable */
#define ITM_TCR_TSENA_Pos         1U
#define ITM_TCR_TSENA_Msk         (1UL << ITM_TCR_TSENA_Pos)          /*!< Local timestamp enable */
#define ITM_TCR_ITMENA_Pos        0U
#define ITM_TCR_ITMENA_Msk        (1UL << ITM_TCR_ITMENA_Pos)         /*!< ITM global enable */

/* TSPRESCALE values */
#define ITM_TCR_TSPRESCALE_DIV1   0x0U  /*!< No prescaling */
#define ITM_TCR_TSPRESCALE_DIV4   0x1U  /*!< Divide by 4 */
#define ITM_TCR_TSPRESCALE_DIV16  0x2U  /*!< Divide by 16 */
#define ITM_TCR_TSPRESCALE_DIV64  0x3U  /*!< Divide by 64 */

/* GTSFREQ values */
#define ITM_TCR_GTSFREQ_DISABLE   0x0U  /*!< Disable global timestamps */
#define ITM_TCR_GTSFREQ_GEN_128   0x1U  /*!< Generate every 128 cycles */
#define ITM_TCR_GTSFREQ_GEN_8192  0x2U  /*!< Generate every 8192 cycles */
#define ITM_TCR_GTSFREQ_GEN_DWT   0x3U  /*!< Generate on DWT synchronization event */

/*
 * ============================================================================
 * DWT (Data Watchpoint and Trace) Register Definitions
 * DWT 寄存器定义
 * Reference: C1.8 The Data Watchpoint and Trace unit (page C1-719)
 *            Table C1-21 DWT register summary (page C1-736)
 * ============================================================================
 */

/**
 * DWT Control Register (DWT_CTRL)
 * Address: 0xE0001000
 * Reference: Arm(R) v7-M ARM, C1.8.7 Control register, DWT_CTRL (page C1-737)
 * 
 * Purpose: Main control register for DWT operation and capability detection.
 */
#define DWT_CTRL                  (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x000))

/**
 * DWT Cycle Count Register (DWT_CYCCNT)
 * Address: 0xE0001004
 * Reference: Arm(R) v7-M ARM, C1.8.9 Cycle Count register, DWT_CYCCNT (page C1-741)
 * 
 * Purpose: 32-bit cycle counter for performance profiling.
 */
#define DWT_CYCCNT                (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x004))

/**
 * DWT CPI Count Register (DWT_CPICNT)
 * Address: 0xE0001008
 * Reference: Arm(R) v7-M ARM, C1.8.10 CPI Count register, DWT_CPICNT (page C1-741)
 * 
 * Purpose: Counts additional cycles required to execute multi-cycle instructions.
 */
#define DWT_CPICNT                (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x008))

/**
 * DWT Exception Overhead Count Register (DWT_EXCCNT)
 * Address: 0xE000100C
 * Reference: Arm(R) v7-M ARM, C1.8.11 Exception Overhead Count register, DWT_EXCCNT (page C1-742)
 * 
 * Purpose: Counts cycles spent in exception processing overhead.
 */
#define DWT_EXCCNT                (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x00C))

/**
 * DWT Sleep Count Register (DWT_SLEEPCNT)
 * Address: 0xE0001010
 * Reference: Arm(R) v7-M ARM, C1.8.12 Sleep Count register, DWT_SLEEPCNT (page C1-742)
 * 
 * Purpose: Counts cycles spent sleeping (CLK gated).
 */
#define DWT_SLEEPCNT              (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x010))

/**
 * DWT LSU Count Register (DWT_LSUCNT)
 * Address: 0xE0001014
 * Reference: Arm(R) v7-M ARM, C1.8.13 LSU Count register, DWT_LSUCNT (page C1-743)
 * 
 * Purpose: Counts additional cycles required for Load/Store unit operations.
 */
#define DWT_LSUCNT                (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x014))

/**
 * DWT Folded Instruction Count Register (DWT_FOLDCNT)
 * Address: 0xE0001018
 * Reference: Arm(R) v7-M ARM, C1.8.14 Folded-instruction Count register, DWT_FOLDCNT (page C1-744)
 * 
 * Purpose: Counts folded instructions (instructions that execute in zero cycles).
 */
#define DWT_FOLDCNT               (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x018))

/**
 * DWT Program Counter Sample Register (DWT_PCSR)
 * Address: 0xE000101C
 * Reference: Arm(R) v7-M ARM, C1.8.15 Program Counter Sample Register, DWT_PCSR (page C1-745)
 * 
 * Purpose: Samples the PC value for profiling.
 */
#define DWT_PCSR                  (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x01C))

/**
 * DWT Comparator Register n (DWT_COMPn)
 * Address: 0xE0001020 + 16*n (n = 0-14)
 * Reference: Arm(R) v7-M ARM, C1.8.16 Comparator registers, DWT_COMPn (page C1-745)
 * 
 * Purpose: Holds the comparison value for comparator n.
 */
#define DWT_COMP(n)               (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x020 + ((n) * 0x10)))

/**
 * DWT Comparator Mask Register n (DWT_MASKn)
 * Address: 0xE0001024 + 16*n (n = 0-14)
 * Reference: Arm(R) v7-M ARM, C1.8.17 Comparator Mask registers, DWT_MASKn (page C1-745)
 * 
 * Purpose: Holds the address mask for comparator n.
 */
#define DWT_MASK(n)               (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x024 + ((n) * 0x10)))

/**
 * DWT Comparator Function Register n (DWT_FUNCTIONn)
 * Address: 0xE0001028 + 16*n (n = 0-14)
 * Reference: Arm(R) v7-M ARM, C1.8.17 Comparator Function registers, DWT_FUNCTIONn (page C1-746)
 * 
 * Purpose: Defines the operation of comparator n.
 */
#define DWT_FUNCTION(n)           (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x028 + ((n) * 0x10)))

/**
 * DWT Comparator Function Register n (DWT_FUNCTIONn) - continued
 * Some implementations may have additional registers at offset 0x02C
 */
#define DWT_FUNCTION_EXT(n)       (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x02C + ((n) * 0x10)))

/*
 * ============================================================================
 * DWT Register Bit Definitions
 * DWT 寄存器位定义
 * Reference: C1.8.7 Control register, DWT_CTRL (page C1-737)
 * ============================================================================
 */

/* DWT_CTRL bits */
#define DWT_CTRL_NUMCOMP_Pos      28U
#define DWT_CTRL_NUMCOMP_Msk      (0xFUL << DWT_CTRL_NUMCOMP_Pos)     /*!< Number of comparators implemented */
#define DWT_CTRL_NOTRCPKT_Pos     27U
#define DWT_CTRL_NOTRCPKT_Msk     (1UL << DWT_CTRL_NOTRCPKT_Pos)      /*!< No trace packets support */
#define DWT_CTRL_NOEXTTRIG_Pos    26U
#define DWT_CTRL_NOEXTTRIG_Msk    (1UL << DWT_CTRL_NOEXTTRIG_Pos)     /*!< No external trigger support */
#define DWT_CTRL_NOCYCCNT_Pos     25U
#define DWT_CTRL_NOCYCCNT_Msk     (1UL << DWT_CTRL_NOCYCCNT_Pos)      /*!< No cycle counter support */
#define DWT_CTRL_NOPRFCNT_Pos     24U
#define DWT_CTRL_NOPRFCNT_Msk     (1UL << DWT_CTRL_NOPRFCNT_Pos)      /*!< No profiling counters support */
#define DWT_CTRL_CYCEVTENA_Pos    22U
#define DWT_CTRL_CYCEVTENA_Msk    (1UL << DWT_CTRL_CYCEVTENA_Pos)     /*!< Cycle count event enable */
#define DWT_CTRL_FOLDEVTENA_Pos   21U
#define DWT_CTRL_FOLDEVTENA_Msk   (1UL << DWT_CTRL_FOLDEVTENA_Pos)    /*!< Folded instruction event enable */
#define DWT_CTRL_LSUEVTENA_Pos    20U
#define DWT_CTRL_LSUEVTENA_Msk    (1UL << DWT_CTRL_LSUEVTENA_Pos)     /*!< LSU event enable */
#define DWT_CTRL_SLEEPEVTENA_Pos  19U
#define DWT_CTRL_SLEEPEVTENA_Msk  (1UL << DWT_CTRL_SLEEPEVTENA_Pos)   /*!< Sleep event enable */
#define DWT_CTRL_EXCEVTENA_Pos    18U
#define DWT_CTRL_EXCEVTENA_Msk    (1UL << DWT_CTRL_EXCEVTENA_Pos)     /*!< Exception event enable */
#define DWT_CTRL_CPIEVTENA_Pos    17U
#define DWT_CTRL_CPIEVTENA_Msk    (1UL << DWT_CTRL_CPIEVTENA_Pos)     /*!< CPI event enable */
#define DWT_CTRL_EXCTRCENA_Pos    16U
#define DWT_CTRL_EXCTRCENA_Msk    (1UL << DWT_CTRL_EXCTRCENA_Pos)     /*!< Exception trace enable */
#define DWT_CTRL_PCSAMPLENA_Pos   12U
#define DWT_CTRL_PCSAMPLENA_Msk   (1UL << DWT_CTRL_PCSAMPLENA_Pos)    /*!< PC sample enable */
#define DWT_CTRL_SYNCTAP_Pos      10U
#define DWT_CTRL_SYNCTAP_Msk      (3UL << DWT_CTRL_SYNCTAP_Pos)       /*!< Synchronization packet tap */
#define DWT_CTRL_CYCTAP_Pos       9U
#define DWT_CTRL_CYCTAP_Msk       (1UL << DWT_CTRL_CYCTAP_Pos)        /*!< Cycle count tap */
#define DWT_CTRL_POSTINIT_Pos     5U
#define DWT_CTRL_POSTINIT_Msk     (0xFUL << DWT_CTRL_POSTINIT_Pos)    /*!< Post-init counter value */
#define DWT_CTRL_POSTPRESET_Pos   1U
#define DWT_CTRL_POSTPRESET_Msk   (0xFUL << DWT_CTRL_POSTPRESET_Pos)  /*!< Post-set counter reload value */
#define DWT_CTRL_CYCCNTENA_Pos    0U
#define DWT_CTRL_CYCCNTENA_Msk    (1UL << DWT_CTRL_CYCCNTENA_Pos)     /*!< Cycle counter enable */

/* DWT_FUNCTION Register Bits */
#define DWT_FUNCTION_MATCHED_Pos  24U
#define DWT_FUNCTION_MATCHED_Msk  (1UL << DWT_FUNCTION_MATCHED_Pos)   /*!< Comparator matched (read-only) */
#define DWT_FUNCTION_DATAVADDR1_Pos 16U
#define DWT_FUNCTION_DATAVADDR1_Msk (0xFUL << DWT_FUNCTION_DATAVADDR1_Pos) /*!< Data value address 1 */
#define DWT_FUNCTION_DATAVADDR0_Pos 12U
#define DWT_FUNCTION_DATAVADDR0_Msk (0xFUL << DWT_FUNCTION_DATAVADDR0_Pos) /*!< Data value address 0 */
#define DWT_FUNCTION_DATAVSIZE_Pos 10U
#define DWT_FUNCTION_DATAVSIZE_Msk (3UL << DWT_FUNCTION_DATAVSIZE_Pos) /*!< Data value size */
#define DWT_FUNCTION_LNK1ENA_Pos  9U
#define DWT_FUNCTION_LNK1ENA_Msk  (1UL << DWT_FUNCTION_LNK1ENA_Pos)   /*!< Link comparator 1 enable */
#define DWT_FUNCTION_DATAVMATCH_Pos 8U
#define DWT_FUNCTION_DATAVMATCH_Msk (1UL << DWT_FUNCTION_DATAVMATCH_Pos) /*!< Data value match */
#define DWT_FUNCTION_CYCMATCH_Pos 7U
#define DWT_FUNCTION_CYCMATCH_Msk (1UL << DWT_FUNCTION_CYCMATCH_Pos)  /*!< Cycle count match (COMP0 only) */
#define DWT_FUNCTION_EMITRANGE_Pos 5U
#define DWT_FUNCTION_EMITRANGE_Msk (1UL << DWT_FUNCTION_EMITRANGE_Pos) /*!< Emit range data trace */
#define DWT_FUNCTION_FUNCTION_Pos 0U
#define DWT_FUNCTION_FUNCTION_Msk (0xFUL << DWT_FUNCTION_FUNCTION_Pos) /*!< Function select */

/* DWT Function Values - Table C1-14, C1-15, C1-16 (pages C1-721 to C1-726) */
#define DWT_FUNCTION_FUNCTION_DISABLED     0x0U  /*!< Disabled */
#define DWT_FUNCTION_FUNCTION_CYCCNT       0x1U  /*!< Cycle count comparison (COMP0 only) */
#define DWT_FUNCTION_FUNCTION_INSTR_ADDR   0x4U  /*!< Instruction address match -> watchpoint */
#define DWT_FUNCTION_FUNCTION_INSTR_ADDR2  0x8U  /*!< Instruction address match -> debug event */
#define DWT_FUNCTION_FUNCTION_DATA_ADDR_RD 0x5U  /*!< Data address match on read -> watchpoint */
#define DWT_FUNCTION_FUNCTION_DATA_ADDR_WR 0x6U  /*!< Data address match on write -> watchpoint */
#define DWT_FUNCTION_FUNCTION_DATA_ADDR_RW 0x7U  /*!< Data address match on R/W -> watchpoint */
#define DWT_FUNCTION_FUNCTION_DATA_VAL_RD  0x9U  /*!< Data value match on read -> watchpoint */
#define DWT_FUNCTION_FUNCTION_DATA_VAL_WR  0xAU  /*!< Data value match on write -> watchpoint */
#define DWT_FUNCTION_FUNCTION_DATA_VAL_RW  0xBU  /*!< Data value match on R/W -> watchpoint */
#define DWT_FUNCTION_FUNCTION_PC_TRACE     0xCU  /*!< PC match -> data trace PC value packet */
#define DWT_FUNCTION_FUNCTION_PC_DATA_RD   0xDU  /*!< PC match + data read -> data trace packet */
#define DWT_FUNCTION_FUNCTION_PC_DATA_WR   0xEU  /*!< PC match + data write -> data trace packet */
#define DWT_FUNCTION_FUNCTION_PC_DATA_RW   0xFU  /*!< PC match + data R/W -> data trace packet */

/* DATAVSIZE values */
#define DWT_FUNCTION_DATAVSIZE_BYTE   0x0U  /*!< Byte access */
#define DWT_FUNCTION_DATAVSIZE_HALF   0x1U  /*!< Halfword access */
#define DWT_FUNCTION_DATAVSIZE_WORD   0x2U  /*!< Word access */

/*
 * ============================================================================
 * FPB (Flash Patch and Breakpoint) Register Definitions
 * FPB 寄存器定义
 * Reference: C1.11 Flash Patch and Breakpoint unit (page C1-755)
 *            Table C1-23 FPB register summary (page C1-756)
 * ============================================================================
 */

/**
 * Flash Patch Control Register (FP_CTRL)
 * Address: 0xE0002000
 * Reference: Arm(R) v7-M ARM, C1.11.3 Flash Patch Control Register, FP_CTRL (page C1-756)
 * 
 * Purpose: Provides FPB implementation information and global enable.
 */
#define FP_CTRL                   (*(volatile uint32_t *)(FPB_BASE_ADDR + 0x000))

/**
 * Flash Patch Remap Register (FP_REMAP)
 * Address: 0xE0002004
 * Reference: Arm(R) v7-M ARM, C1.11.4 Flash Patch Remap register, FP_REMAP (page C1-758)
 * 
 * Purpose: Defines the base address for remapped code/data.
 */
#define FP_REMAP                  (*(volatile uint32_t *)(FPB_BASE_ADDR + 0x004))

/**
 * Flash Patch Comparator Register n (FP_COMPn)
 * Address: 0xE0002008 + 4*n (n = 0-127 for instruction, 128-142 for literal)
 * Reference: Arm(R) v7-M ARM, C1.11.5 Flash Patch Comparator register, FP_COMPn (page C1-758)
 * 
 * Purpose: Defines breakpoint/remap address for comparator n.
 */
#define FP_COMP(n)                (*(volatile uint32_t *)(FPB_BASE_ADDR + 0x008 + ((n) * 4)))

/*
 * ============================================================================
 * FPB Register Bit Definitions
 * FPB 寄存器位定义
 * Reference: C1.11.3 Flash Patch Control Register, FP_CTRL (page C1-756)
 * ============================================================================
 */

/* FP_CTRL bits */
#define FP_CTRL_REV_Pos           28U
#define FP_CTRL_REV_Msk           (0xFUL << FP_CTRL_REV_Pos)          /*!< FPB architecture revision */
#define FP_CTRL_NUM_CODE2_Pos     12U
#define FP_CTRL_NUM_CODE2_Msk     (0x7UL << FP_CTRL_NUM_CODE2_Pos)    /*!< Number of code comparators [6:4] */
#define FP_CTRL_NUM_LIT_Pos       8U
#define FP_CTRL_NUM_LIT_Msk       (0xFUL << FP_CTRL_NUM_LIT_Pos)      /*!< Number of literal comparators */
#define FP_CTRL_NUM_CODE_Pos      4U
#define FP_CTRL_NUM_CODE_Msk      (0xFUL << FP_CTRL_NUM_CODE_Pos)     /*!< Number of code comparators [3:0] */
#define FP_CTRL_KEY_Pos           1U
#define FP_CTRL_KEY_Msk           (1UL << FP_CTRL_KEY_Pos)            /*!< Key bit for write (must be 1) */
#define FP_CTRL_ENABLE_Pos        0U
#define FP_CTRL_ENABLE_Msk        (1UL << FP_CTRL_ENABLE_Pos)         /*!< FPB unit enable */

/* FP_CTRL REV values */
#define FP_CTRL_REV_V1            0x0U  /*!< FPB version 1 */
#define FP_CTRL_REV_V2            0x1U  /*!< FPB version 2 (supports breakpoints in full 4GB space) */

/* FP_REMAP bits */
#define FP_REMAP_RMPSPT_Pos       29U
#define FP_REMAP_RMPSPT_Msk       (1UL << FP_REMAP_RMPSPT_Pos)        /*!< Remap support indicator */
#define FP_REMAP_REMAP_Pos        5U
#define FP_REMAP_REMAP_Msk        (0x1FFFFFFUL << FP_REMAP_REMAP_Pos) /*!< Remap base address */

/* FP_COMP bits */
#define FP_COMP_REPLACE_Pos       30U
#define FP_COMP_REPLACE_Msk       (3UL << FP_COMP_REPLACE_Pos)        /*!< Replace control (breakpoint location) */
#define FP_COMP_COMP_Pos          2U
#define FP_COMP_COMP_Msk          (0x1FFFFFFFUL << FP_COMP_COMP_Pos)  /*!< Comparison address */
#define FP_COMP_ENABLE_Pos        0U
#define FP_COMP_ENABLE_Msk        (1UL << FP_COMP_ENABLE_Pos)         /*!< Comparator enable */

/* FP_COMP REPLACE values for instruction address comparators */
#define FP_COMP_REPLACE_NONE      0x0U  /*!< No replacement (disabled) */
#define FP_COMP_REPLACE_LOWER     0x1U  /*!< Breakpoint on lower halfword */
#define FP_COMP_REPLACE_UPPER     0x2U  /*!< Breakpoint on upper halfword */
#define FP_COMP_REPLACE_BOTH      0x3U  /*!< Breakpoint on both halfwords */

/*
 * ============================================================================
 * ROM Table Definitions
 * ROM Table 定义
 * Reference: C1.2.2 The Armv7-M ROM Table (page C1-686)
 *            Table C1-3 Armv7-M DAP accessible ROM table (page C1-686)
 * ============================================================================
 */

/* ROM Table definitions are provided by armv7-m_rom_table.h */

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/*
 * ============================================================================
 * ITM Functions
 * ITM 函数
 * Reference: C1.7 The Instrumentation Trace Macrocell (page C1-709)
 * ============================================================================
 */

/**
 * @brief Initialize and enable ITM
 * 初始化并使能ITM
 * Reference: C1.7.1 ITM operation (page C1-709)
 */
void itm_init(void);

/**
 * @brief Enable ITM
 * 使能ITM
 * Reference: C1.7.6 Trace Control Register, ITM_TCR (page C1-716)
 */
void itm_enable(void);

/**
 * @brief Disable ITM
 * 禁用ITM
 * Reference: C1.7.6 Trace Control Register, ITM_TCR (page C1-716)
 */
void itm_disable(void);

/**
 * @brief Check if ITM is enabled
 * 检查ITM是否使能
 * @return true if enabled
 */
bool itm_is_enabled(void);

/**
 * @brief Check if ITM stimulus port is ready for write
 * 检查ITM刺激端口是否就绪
 * @param port Port number (0-255)
 * @return true if ready
 * Reference: C1.7.1 ITM operation (page C1-709)
 */
static inline bool itm_stimulus_port_ready(uint32_t port) {
    return (ITM_STIM(port) & 0x1U) != 0U;
}

/**
 * @brief Write to ITM stimulus port (32-bit)
 * 写入ITM刺激端口(32位)
 * @param port Port number (0-255)
 * @param value Value to write
 * Reference: C1.7.3 Stimulus Port registers, ITM_STIM0-ITM_STIM255 (page C1-714)
 */
static inline void itm_stimulus_port_write32(uint32_t port, uint32_t value) {
    ITM_STIM(port) = value;
}

/**
 * @brief Write to ITM stimulus port (16-bit)
 * 写入ITM刺激端口(16位)
 * @param port Port number (0-255)
 * @param value Value to write
 */
static inline void itm_stimulus_port_write16(uint32_t port, uint16_t value) {
    *(volatile uint16_t *)&ITM_STIM(port) = value;
}

/**
 * @brief Write to ITM stimulus port (8-bit)
 * 写入ITM刺激端口(8位)
 * @param port Port number (0-255)
 * @param value Value to write
 */
static inline void itm_stimulus_port_write8(uint32_t port, uint8_t value) {
    *(volatile uint8_t *)&ITM_STIM(port) = value;
}

/**
 * @brief Send character via ITM (port 0)
 * 通过ITM发送字符(端口0)
 * @param ch Character to send
 * @return Character sent or -1 if port not ready
 * Reference: C1.7.1 ITM operation (page C1-709)
 */
int32_t itm_send_char(int32_t ch);

/**
 * @brief Send string via ITM (port 0)
 * 通过ITM发送字符串(端口0)
 * @param str String to send
 * @return Number of characters sent
 */
int32_t itm_send_string(const char *str);

/**
 * @brief Receive character via ITM
 * 通过ITM接收字符
 * @return Character received or -1 if no data
 */
int32_t itm_receive_char(void);

/**
 * @brief Enable ITM stimulus port
 * 使能ITM刺激端口
 * @param port Port number (0-255)
 * Reference: C1.7.4 Trace Enable Registers, ITM_TER0-ITM_TER7 (page C1-714)
 */
void itm_enable_stimulus_port(uint32_t port);

/**
 * @brief Disable ITM stimulus port
 * 禁用ITM刺激端口
 * @param port Port number (0-255)
 * Reference: C1.7.4 Trace Enable Registers, ITM_TER0-ITM_TER7 (page C1-714)
 */
void itm_disable_stimulus_port(uint32_t port);

/**
 * @brief Check if ITM stimulus port is enabled
 * 检查ITM刺激端口是否使能
 * @param port Port number (0-255)
 * @return true if enabled
 */
bool itm_is_stimulus_port_enabled(uint32_t port);

/**
 * @brief Enable local timestamp generation
 * 使能本地时间戳生成
 * Reference: C1.7.1 ITM operation - Local timestamping (page C1-710)
 */
void itm_enable_local_timestamps(void);

/**
 * @brief Disable local timestamp generation
 * 禁用本地时间戳生成
 */
void itm_disable_local_timestamps(void);

/**
 * @brief Set local timestamp prescaler
 * 设置本地时间戳预分频器
 * @param prescale Prescaler value (0=div1, 1=div4, 2=div16, 3=div64)
 * Reference: C1.7.6 Trace Control Register, ITM_TCR (page C1-716)
 */
void itm_set_timestamp_prescaler(uint32_t prescale);

/**
 * @brief Enable DWT packet transmission through ITM
 * 使能通过ITM传输DWT数据包
 * Reference: C1.7.6 Trace Control Register, ITM_TCR (page C1-716)
 */
void itm_enable_dwt_tx(void);

/**
 * @brief Disable DWT packet transmission through ITM
 * 禁用通过ITM传输DWT数据包
 */
void itm_disable_dwt_tx(void);

/*
 * ============================================================================
 * DWT Functions
 * DWT 函数
 * Reference: C1.8 The Data Watchpoint and Trace unit (page C1-719)
 * ============================================================================
 */

/**
 * @brief Initialize DWT
 * 初始化DWT
 * Reference: C1.8 The Data Watchpoint and Trace unit (page C1-719)
 */
void dwt_init(void);

/**
 * @brief Enable DWT
 * 使能DWT
 * Note: DWT is enabled by setting DEMCR.TRCENA=1
 */
void dwt_enable(void);

/**
 * @brief Disable DWT
 * 禁用DWT
 */
void dwt_disable(void);

/**
 * @brief Check if DWT is available
 * 检查DWT是否可用
 * @return true if DWT is implemented
 * Reference: C1.1.1 Debug support in Armv7-M (page C1-683)
 */
bool dwt_is_available(void);

/**
 * @brief Get number of DWT comparators
 * 获取DWT比较器数量
 * @return Number of comparators (0-15)
 * Reference: C1.8.7 Control register, DWT_CTRL (page C1-737)
 */
static inline uint32_t dwt_get_num_comparators(void) {
    return (DWT_CTRL & DWT_CTRL_NUMCOMP_Msk) >> DWT_CTRL_NUMCOMP_Pos;
}

/**
 * @brief Check if DWT has cycle counter
 * 检查DWT是否有周期计数器
 * @return true if cycle counter is implemented
 * Reference: C1.8.7 Control register, DWT_CTRL (page C1-737)
 */
static inline bool dwt_has_cycle_counter(void) {
    return (DWT_CTRL & DWT_CTRL_NOCYCCNT_Msk) == 0U;
}

/**
 * @brief Check if DWT has profiling counters
 * 检查DWT是否有性能分析计数器
 * @return true if profiling counters are implemented
 * Reference: C1.8.7 Control register, DWT_CTRL (page C1-737)
 */
static inline bool dwt_has_profiling_counters(void) {
    return (DWT_CTRL & DWT_CTRL_NOPRFCNT_Msk) == 0U;
}

/**
 * @brief Check if DWT has trace support
 * 检查DWT是否有跟踪支持
 * @return true if trace is supported
 * Reference: C1.8.7 Control register, DWT_CTRL (page C1-737)
 */
static inline bool dwt_has_trace_support(void) {
    return (DWT_CTRL & DWT_CTRL_NOTRCPKT_Msk) == 0U;
}

/**
 * @brief Enable DWT cycle counter
 * 使能DWT周期计数器
 * Reference: C1.8.9 Cycle Count register, DWT_CYCCNT (page C1-741)
 */
void dwt_enable_cycle_counter(void);

/**
 * @brief Disable DWT cycle counter
 * 禁用DWT周期计数器
 * Reference: C1.8.9 Cycle Count register, DWT_CYCCNT (page C1-741)
 */
void dwt_disable_cycle_counter(void);

/**
 * @brief Get DWT cycle counter value
 * 获取DWT周期计数器值
 * @return Cycle count
 * Reference: C1.8.9 Cycle Count register, DWT_CYCCNT (page C1-741)
 */
static inline uint32_t dwt_get_cycle_counter(void) {
    return DWT_CYCCNT;
}

/**
 * @brief Set DWT cycle counter value
 * 设置DWT周期计数器值
 * @param value Value to set
 */
static inline void dwt_set_cycle_counter(uint32_t value) {
    DWT_CYCCNT = value;
}

/**
 * @brief Reset DWT cycle counter to 0
 * 复位DWT周期计数器为0
 */
static inline void dwt_reset_cycle_counter(void) {
    DWT_CYCCNT = 0U;
}

/**
 * @brief Get DWT PC sample value
 * 获取DWT PC采样值
 * @return PC sample
 * Reference: C1.8.15 Program Counter Sample Register, DWT_PCSR (page C1-745)
 */
static inline uint32_t dwt_get_pc_sample(void) {
    return DWT_PCSR;
}

/**
 * @brief Configure DWT comparator for address matching
 * 配置DWT比较器进行地址匹配
 * @param comp Comparator number (0-14)
 * @param addr Address to compare
 * @param mask Address mask (0-31, number of bits to mask)
 * @param function Function to perform on match
 * Reference: C1.8.1 The DWT comparators (page C1-720)
 */
void dwt_configure_comparator(uint32_t comp, uint32_t addr, uint32_t mask, uint32_t function);

/**
 * @brief Configure DWT comparator for data value matching
 * 配置DWT比较器进行数据值匹配
 * @param comp Comparator number
 * @param addr Data address
 * @param value Data value to match
 * @param size Data size (0=byte, 1=half, 2=word)
 * @param rw Read/write access type
 * Reference: C1.8.1 The DWT comparators (page C1-720)
 */
void dwt_configure_data_value_match(uint32_t comp, uint32_t addr, uint32_t value, 
                                     uint32_t size, uint32_t rw);

/**
 * @brief Enable DWT comparator
 * 使能DWT比较器
 * @param comp Comparator number
 */
void dwt_enable_comparator(uint32_t comp);

/**
 * @brief Disable DWT comparator
 * 禁用DWT比较器
 * @param comp Comparator number
 */
void dwt_disable_comparator(uint32_t comp);

/**
 * @brief Check if DWT comparator is matched
 * 检查DWT比较器是否匹配
 * @param comp Comparator number
 * @return true if matched
 */
bool dwt_is_comparator_matched(uint32_t comp);

/**
 * @brief Enable exception trace
 * 使能异常跟踪
 * Reference: C1.8.2 Exception trace support (page C1-731)
 */
void dwt_enable_exception_trace(void);

/**
 * @brief Disable exception trace
 * 禁用异常跟踪
 */
void dwt_disable_exception_trace(void);

/**
 * @brief Enable PC sampling
 * 使能PC采样
 * Reference: C1.8.6 Profiling counter support (page C1-734)
 */
void dwt_enable_pc_sampling(void);

/**
 * @brief Disable PC sampling
 * 禁用PC采样
 */
void dwt_disable_pc_sampling(void);

/**
 * @brief Enable profiling counters
 * 使能性能分析计数器
 * Reference: C1.8.6 Profiling counter support (page C1-734)
 */
void dwt_enable_profiling_counters(void);

/**
 * @brief Disable profiling counters
 * 禁用性能分析计数器
 */
void dwt_disable_profiling_counters(void);

/**
 * @brief Get CPI count
 * 获取CPI计数
 * @return CPI count value
 * Reference: C1.8.10 CPI Count register, DWT_CPICNT (page C1-741)
 */
static inline uint8_t dwt_get_cpi_count(void) {
    return (uint8_t)DWT_CPICNT;
}

/**
 * @brief Get exception overhead count
 * 获取异常开销计数
 * @return Exception overhead count
 * Reference: C1.8.11 Exception Overhead Count register, DWT_EXCCNT (page C1-742)
 */
static inline uint8_t dwt_get_exception_count(void) {
    return (uint8_t)DWT_EXCCNT;
}

/**
 * @brief Get sleep count
 * 获取睡眠计数
 * @return Sleep count
 * Reference: C1.8.12 Sleep Count register, DWT_SLEEPCNT (page C1-742)
 */
static inline uint8_t dwt_get_sleep_count(void) {
    return (uint8_t)DWT_SLEEPCNT;
}

/**
 * @brief Get LSU count
 * 获取LSU计数
 * @return LSU count
 * Reference: C1.8.13 LSU Count register, DWT_LSUCNT (page C1-743)
 */
static inline uint8_t dwt_get_lsu_count(void) {
    return (uint8_t)DWT_LSUCNT;
}

/**
 * @brief Get folded instruction count
 * 获取折叠指令计数
 * @return Folded instruction count
 * Reference: C1.8.14 Folded-instruction Count register, DWT_FOLDCNT (page C1-744)
 */
static inline uint8_t dwt_get_fold_count(void) {
    return (uint8_t)DWT_FOLDCNT;
}

/*
 * ============================================================================
 * FPB Functions
 * FPB 函数
 * Reference: C1.11 Flash Patch and Breakpoint unit (page C1-755)
 * ============================================================================
 */

/**
 * @brief Initialize FPB
 * 初始化FPB
 * Reference: C1.11 Flash Patch and Breakpoint unit (page C1-755)
 */
void fpb_init(void);

/**
 * @brief Enable FPB
 * 使能FPB
 * Reference: C1.11.3 Flash Patch Control Register, FP_CTRL (page C1-756)
 */
void fpb_enable(void);

/**
 * @brief Disable FPB
 * 禁用FPB
 * Reference: C1.11.3 Flash Patch Control Register, FP_CTRL (page C1-756)
 */
void fpb_disable(void);

/**
 * @brief Check if FPB is available
 * 检查FPB是否可用
 * @return true if FPB is implemented
 * Reference: C1.1.1 Debug support in Armv7-M (page C1-683)
 */
bool fpb_is_available(void);

/**
 * @brief Check if FPB remapping is supported
 * 检查FPB是否支持重映射
 * @return true if remapping is supported
 * Reference: C1.11.4 Flash Patch Remap register, FP_REMAP (page C1-758)
 */
bool fpb_has_remap_support(void);

/**
 * @brief Get number of FPB instruction address comparators
 * 获取FPB指令地址比较器数量
 * @return Number of instruction address comparators (0-127)
 * Reference: C1.11.3 Flash Patch Control Register, FP_CTRL (page C1-756)
 */
uint32_t fpb_get_num_code_comparators(void);

/**
 * @brief Get number of FPB literal address comparators
 * 获取FPB文字地址比较器数量
 * @return Number of literal address comparators (0-15)
 * Reference: C1.11.3 Flash Patch Control Register, FP_CTRL (page C1-756)
 */
uint32_t fpb_get_num_literal_comparators(void);

/**
 * @brief Get total number of FPB comparators
 * 获取FPB比较器总数
 * @return Total number of comparators
 */
static inline uint32_t fpb_get_num_comparators(void) {
    return fpb_get_num_code_comparators() + fpb_get_num_literal_comparators();
}

/**
 * @brief Set FPB breakpoint
 * 设置FPB断点
 * @param bp Breakpoint number (0 to NUM_CODE-1)
 * @param addr Address (must be in Code region, first 0.5GB)
 * @param replace Replace control (which halfword to break on)
 * @return 0 on success, -1 on error
 * Reference: C1.11.5 Flash Patch Comparator register, FP_COMPn (page C1-758)
 */
int32_t fpb_set_breakpoint(uint32_t bp, uint32_t addr, uint32_t replace);

/**
 * @brief Clear FPB breakpoint
 * 清除FPB断点
 * @param bp Breakpoint number
 * Reference: C1.11.5 Flash Patch Comparator register, FP_COMPn (page C1-758)
 */
void fpb_clear_breakpoint(uint32_t bp);

/**
 * @brief Set FPB literal remap
 * 设置FPB文字重映射
 * @param lit Literal comparator number (starts at NUM_CODE)
 * @param literal_addr Literal address in Code region
 * @param remap_addr Remap address in SRAM region
 * @return 0 on success, -1 on error
 * Reference: C1.11.1 FPB unit operation (page C1-755)
 */
int32_t fpb_set_literal_remap(uint32_t lit, uint32_t literal_addr, uint32_t remap_addr);

/**
 * @brief Set FPB instruction remap
 * 设置FPB指令重映射
 * @param bp Breakpoint number
 * @param instr_addr Instruction address in Code region
 * @param remap_addr Remap address in SRAM region
 * @return 0 on success, -1 on error
 * Reference: C1.11.1 FPB unit operation (page C1-755)
 */
int32_t fpb_set_instruction_remap(uint32_t bp, uint32_t instr_addr, uint32_t remap_addr);

/**
 * @brief Set FPB remap base address
 * 设置FPB重映射基地址
 * @param base_addr Base address for remapped code (must be 32-byte aligned)
 * Reference: C1.11.4 Flash Patch Remap register, FP_REMAP (page C1-758)
 */
void fpb_set_remap_base(uint32_t base_addr);

/**
 * @brief Get FPB remap base address
 * 获取FPB重映射基地址
 * @return Remap base address
 */
uint32_t fpb_get_remap_base(void);

/**
 * @brief Clear all FPB comparators
 * 清除所有FPB比较器
 */
void fpb_clear_all(void);

/*
 * ============================================================================
 * ROM Table Functions
 * ROM Table 函数
 * Reference: C1.2.2 The Armv7-M ROM Table (page C1-686)
 * ============================================================================
 */

/* ROM Table functions are provided by armv7-m_rom_table.h */

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_DEBUG_H__ */
