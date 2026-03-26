/*
 * arm_v7m_debug.h
 * Debug Support Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Part C
 *   - Section C1.6: Debug system registers
 *   - Section C1.7: The Instrumentation Trace Macrocell
 *   - Section C1.8: The Data Watchpoint and Trace unit
 *   - Section C1.10: Trace Port Interface Unit
 *   - Section C1.11: Flash Patch and Breakpoint unit
 */

#ifndef ARM_V7M_DEBUG_H
#define ARM_V7M_DEBUG_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Compiler Abstraction - Inline Definition
 * This library only supports Clang/LLVM compiler
 *============================================================================*/

#if defined(__clang__)
    #define ARM_V7M_DEBUG_INLINE static inline __attribute__((always_inline))
#else
    #error "This library requires Clang/LLVM compiler. Please use clang to compile this code."
#endif

/*============================================================================*
 * Debug Base Addresses (Architecture defined)
 * Reference: ARMv7-M Architecture Reference Manual, Table C1-10, C1-719
 *============================================================================*/

#define ARM_V7M_DEBUG_BASE          0xE000EDF0UL
#define ARM_V7M_DWT_BASE            0xE0001000UL
#define ARM_V7M_ITM_BASE            0xE0000000UL
#define ARM_V7M_FPB_BASE            0xE0002000UL
#define ARM_V7M_TPIU_BASE           0xE0040000UL

/*============================================================================*
 * Debug Register Offsets
 *============================================================================*/

#define ARM_V7M_DEBUG_DHCSR_OFFSET  0x00
#define ARM_V7M_DEBUG_DCRSR_OFFSET  0x04
#define ARM_V7M_DEBUG_DCRDR_OFFSET  0x08
#define ARM_V7M_DEBUG_DEMCR_OFFSET  0x0C

/*============================================================================*
 * DHCSR (Debug Halting Control and Status Register) Bit Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section C1.6.2
 * Address: 0xE000EDF0
 *============================================================================*/

/* Debug Key - must write 0xA05F to bits [31:16] to enable write access */
#define ARM_V7M_DHCSR_DBGKEY_Pos        16U
#define ARM_V7M_DHCSR_DBGKEY_Msk        (0xFFFFUL << ARM_V7M_DHCSR_DBGKEY_Pos)
#define ARM_V7M_DHCSR_DBGKEY            (0xA05FUL << ARM_V7M_DHCSR_DBGKEY_Pos)

/* Status Bits (Read-only) */
#define ARM_V7M_DHCSR_S_RESET_ST_Pos    25U
#define ARM_V7M_DHCSR_S_RESET_ST_Msk    (1UL << ARM_V7M_DHCSR_S_RESET_ST_Pos)

#define ARM_V7M_DHCSR_S_RETIRE_ST_Pos   24U
#define ARM_V7M_DHCSR_S_RETIRE_ST_Msk   (1UL << ARM_V7M_DHCSR_S_RETIRE_ST_Pos)

#define ARM_V7M_DHCSR_S_LOCKUP_Pos      19U
#define ARM_V7M_DHCSR_S_LOCKUP_Msk      (1UL << ARM_V7M_DHCSR_S_LOCKUP_Pos)

#define ARM_V7M_DHCSR_S_SLEEP_Pos       18U
#define ARM_V7M_DHCSR_S_SLEEP_Msk       (1UL << ARM_V7M_DHCSR_S_SLEEP_Pos)

#define ARM_V7M_DHCSR_S_HALT_Pos        17U
#define ARM_V7M_DHCSR_S_HALT_Msk        (1UL << ARM_V7M_DHCSR_S_HALT_Pos)

#define ARM_V7M_DHCSR_S_REGRDY_Pos      16U
#define ARM_V7M_DHCSR_S_REGRDY_Msk      (1UL << ARM_V7M_DHCSR_S_REGRDY_Pos)

/* Control Bits (Read/Write) */
#define ARM_V7M_DHCSR_C_SNAPSTALL_Pos   5U
#define ARM_V7M_DHCSR_C_SNAPSTALL_Msk   (1UL << ARM_V7M_DHCSR_C_SNAPSTALL_Pos)

#define ARM_V7M_DHCSR_C_MASKINTS_Pos    3U
#define ARM_V7M_DHCSR_C_MASKINTS_Msk    (1UL << ARM_V7M_DHCSR_C_MASKINTS_Pos)

#define ARM_V7M_DHCSR_C_STEP_Pos        2U
#define ARM_V7M_DHCSR_C_STEP_Msk        (1UL << ARM_V7M_DHCSR_C_STEP_Pos)

#define ARM_V7M_DHCSR_C_HALT_Pos        1U
#define ARM_V7M_DHCSR_C_HALT_Msk        (1UL << ARM_V7M_DHCSR_C_HALT_Pos)

#define ARM_V7M_DHCSR_C_DEBUGEN_Pos     0U
#define ARM_V7M_DHCSR_C_DEBUGEN_Msk     (1UL << ARM_V7M_DHCSR_C_DEBUGEN_Pos)

/*============================================================================*
 * DCRSR (Debug Core Register Selector Register) Bit Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section C1.6.3
 * Address: 0xE000EDF4
 *============================================================================*/

#define ARM_V7M_DCRSR_REGWnR_Pos        16U
#define ARM_V7M_DCRSR_REGWnR_Msk        (1UL << ARM_V7M_DCRSR_REGWnR_Pos)

#define ARM_V7M_DCRSR_REGSEL_Pos        0U
#define ARM_V7M_DCRSR_REGSEL_Msk        (0x7FUL << ARM_V7M_DCRSR_REGSEL_Pos)

/* Register Selector Values */
#define ARM_V7M_DCRSR_REG_R0            0x00U
#define ARM_V7M_DCRSR_REG_R1            0x01U
#define ARM_V7M_DCRSR_REG_R2            0x02U
#define ARM_V7M_DCRSR_REG_R3            0x03U
#define ARM_V7M_DCRSR_REG_R4            0x04U
#define ARM_V7M_DCRSR_REG_R5            0x05U
#define ARM_V7M_DCRSR_REG_R6            0x06U
#define ARM_V7M_DCRSR_REG_R7            0x07U
#define ARM_V7M_DCRSR_REG_R8            0x08U
#define ARM_V7M_DCRSR_REG_R9            0x09U
#define ARM_V7M_DCRSR_REG_R10           0x0AU
#define ARM_V7M_DCRSR_REG_R11           0x0BU
#define ARM_V7M_DCRSR_REG_R12           0x0CU
#define ARM_V7M_DCRSR_REG_SP            0x0DU
#define ARM_V7M_DCRSR_REG_LR            0x0EU
#define ARM_V7M_DCRSR_REG_DEBUGRET      0x0FU
#define ARM_V7M_DCRSR_REG_XPSR          0x10U
#define ARM_V7M_DCRSR_REG_MSP           0x11U
#define ARM_V7M_DCRSR_REG_PSP           0x12U
#define ARM_V7M_DCRSR_REG_CTRL          0x14U
#define ARM_V7M_DCRSR_REG_FPSCR         0x21U
#define ARM_V7M_DCRSR_REG_S0            0x40U

/*============================================================================*
 * DEMCR (Debug Exception and Monitor Control Register) Bit Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section C1.6.5
 * Address: 0xE000EDFC
 *============================================================================*/

#define ARM_V7M_DEMCR_TRCENA_Pos        24U
#define ARM_V7M_DEMCR_TRCENA_Msk        (1UL << ARM_V7M_DEMCR_TRCENA_Pos)

#define ARM_V7M_DEMCR_MON_REQ_Pos       19U
#define ARM_V7M_DEMCR_MON_REQ_Msk       (1UL << ARM_V7M_DEMCR_MON_REQ_Pos)

#define ARM_V7M_DEMCR_MON_STEP_Pos      18U
#define ARM_V7M_DEMCR_MON_STEP_Msk      (1UL << ARM_V7M_DEMCR_MON_STEP_Pos)

#define ARM_V7M_DEMCR_MON_PEND_Pos      17U
#define ARM_V7M_DEMCR_MON_PEND_Msk      (1UL << ARM_V7M_DEMCR_MON_PEND_Pos)

#define ARM_V7M_DEMCR_MON_EN_Pos        16U
#define ARM_V7M_DEMCR_MON_EN_Msk        (1UL << ARM_V7M_DEMCR_MON_EN_Pos)

/* Vector Catch Bits */
#define ARM_V7M_DEMCR_VC_HARDERR_Pos    10U
#define ARM_V7M_DEMCR_VC_HARDERR_Msk    (1UL << ARM_V7M_DEMCR_VC_HARDERR_Pos)

#define ARM_V7M_DEMCR_VC_INTERR_Pos     9U
#define ARM_V7M_DEMCR_VC_INTERR_Msk     (1UL << ARM_V7M_DEMCR_VC_INTERR_Pos)

#define ARM_V7M_DEMCR_VC_BUSERR_Pos     8U
#define ARM_V7M_DEMCR_VC_BUSERR_Msk     (1UL << ARM_V7M_DEMCR_VC_BUSERR_Pos)

#define ARM_V7M_DEMCR_VC_STATERR_Pos    7U
#define ARM_V7M_DEMCR_VC_STATERR_Msk    (1UL << ARM_V7M_DEMCR_VC_STATERR_Pos)

#define ARM_V7M_DEMCR_VC_CHKERR_Pos     6U
#define ARM_V7M_DEMCR_VC_CHKERR_Msk     (1UL << ARM_V7M_DEMCR_VC_CHKERR_Pos)

#define ARM_V7M_DEMCR_VC_NOCPERR_Pos    5U
#define ARM_V7M_DEMCR_VC_NOCPERR_Msk    (1UL << ARM_V7M_DEMCR_VC_NOCPERR_Pos)

#define ARM_V7M_DEMCR_VC_MMERR_Pos      4U
#define ARM_V7M_DEMCR_VC_MMERR_Msk      (1UL << ARM_V7M_DEMCR_VC_MMERR_Pos)

#define ARM_V7M_DEMCR_VC_CORERESET_Pos  0U
#define ARM_V7M_DEMCR_VC_CORERESET_Msk  (1UL << ARM_V7M_DEMCR_VC_CORERESET_Pos)

/*============================================================================*
 * DWT_CTRL (DWT Control Register) Bit Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section C1.8.4
 * Address: 0xE0001000
 *============================================================================*/

#define ARM_V7M_DWT_CTRL_NUMCOMP_Pos    28U
#define ARM_V7M_DWT_CTRL_NUMCOMP_Msk    (0xFUL << ARM_V7M_DWT_CTRL_NUMCOMP_Pos)

#define ARM_V7M_DWT_CTRL_NOTRCPKT_Pos   27U
#define ARM_V7M_DWT_CTRL_NOTRCPKT_Msk   (1UL << ARM_V7M_DWT_CTRL_NOTRCPKT_Pos)

#define ARM_V7M_DWT_CTRL_NOEXTTRIG_Pos  26U
#define ARM_V7M_DWT_CTRL_NOEXTTRIG_Msk  (1UL << ARM_V7M_DWT_CTRL_NOEXTTRIG_Pos)

#define ARM_V7M_DWT_CTRL_NOCYCCNT_Pos   25U
#define ARM_V7M_DWT_CTRL_NOCYCCNT_Msk   (1UL << ARM_V7M_DWT_CTRL_NOCYCCNT_Pos)

#define ARM_V7M_DWT_CTRL_NOPRFCNT_Pos   24U
#define ARM_V7M_DWT_CTRL_NOPRFCNT_Msk   (1UL << ARM_V7M_DWT_CTRL_NOPRFCNT_Pos)

#define ARM_V7M_DWT_CTRL_CYCCNTENA_Pos  0U
#define ARM_V7M_DWT_CTRL_CYCCNTENA_Msk  (1UL << ARM_V7M_DWT_CTRL_CYCCNTENA_Pos)

/*============================================================================*
 * DWT_FUNCTION (Comparator Function Register) Bit Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section C1.8
 *============================================================================*/

#define ARM_V7M_DWT_FUNCTION_DATAVMATCH_Pos 8U
#define ARM_V7M_DWT_FUNCTION_DATAVMATCH_Msk (1UL << ARM_V7M_DWT_FUNCTION_DATAVMATCH_Pos)

#define ARM_V7M_DWT_FUNCTION_CYCMATCH_Pos   7U
#define ARM_V7M_DWT_FUNCTION_CYCMATCH_Msk   (1UL << ARM_V7M_DWT_FUNCTION_CYCMATCH_Pos)

#define ARM_V7M_DWT_FUNCTION_EMITRANGE_Pos  5U
#define ARM_V7M_DWT_FUNCTION_EMITRANGE_Msk  (1UL << ARM_V7M_DWT_FUNCTION_EMITRANGE_Pos)

#define ARM_V7M_DWT_FUNCTION_FUNCTION_Pos   0U
#define ARM_V7M_DWT_FUNCTION_FUNCTION_Msk   (0xFUL << ARM_V7M_DWT_FUNCTION_FUNCTION_Pos)

/* Function Values */
#define ARM_V7M_DWT_FUNCTION_DISABLED       0x0U
#define ARM_V7M_DWT_FUNCTION_PC_SAMPLE      0x1U
#define ARM_V7M_DWT_FUNCTION_DATA_RW        0x2U
#define ARM_V7M_DWT_FUNCTION_DATA_RWP       0x3U
#define ARM_V7M_DWT_FUNCTION_PC_WATCH       0x4U
#define ARM_V7M_DWT_FUNCTION_DATA_R_WATCH   0x5U
#define ARM_V7M_DWT_FUNCTION_DATA_W_WATCH   0x6U
#define ARM_V7M_DWT_FUNCTION_DATA_RW_WATCH  0x7U

/*============================================================================*
 * ITM Register Bit Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section C1.7
 *============================================================================*/

/* ITM_TCR (Trace Control Register) */
#define ARM_V7M_ITM_TCR_BUSY_Pos        23U
#define ARM_V7M_ITM_TCR_BUSY_Msk        (1UL << ARM_V7M_ITM_TCR_BUSY_Pos)

#define ARM_V7M_ITM_TCR_TRACEBUSID_Pos  16U
#define ARM_V7M_ITM_TCR_TRACEBUSID_Msk  (0x7FUL << ARM_V7M_ITM_TCR_TRACEBUSID_Pos)

#define ARM_V7M_ITM_TCR_GTSFREQ_Pos     10U
#define ARM_V7M_ITM_TCR_GTSFREQ_Msk     (0x3UL << ARM_V7M_ITM_TCR_GTSFREQ_Pos)

#define ARM_V7M_ITM_TCR_TSPRESCALE_Pos  8U
#define ARM_V7M_ITM_TCR_TSPRESCALE_Msk  (0x3UL << ARM_V7M_ITM_TCR_TSPRESCALE_Pos)

#define ARM_V7M_ITM_TCR_SWOENA_Pos      4U
#define ARM_V7M_ITM_TCR_SWOENA_Msk      (1UL << ARM_V7M_ITM_TCR_SWOENA_Pos)

#define ARM_V7M_ITM_TCR_TXENA_Pos       3U
#define ARM_V7M_ITM_TCR_TXENA_Msk       (1UL << ARM_V7M_ITM_TCR_TXENA_Pos)

#define ARM_V7M_ITM_TCR_SYNCENA_Pos     2U
#define ARM_V7M_ITM_TCR_SYNCENA_Msk     (1UL << ARM_V7M_ITM_TCR_SYNCENA_Pos)

#define ARM_V7M_ITM_TCR_TSENA_Pos       1U
#define ARM_V7M_ITM_TCR_TSENA_Msk       (1UL << ARM_V7M_ITM_TCR_TSENA_Pos)

#define ARM_V7M_ITM_TCR_ITMENA_Pos      0U
#define ARM_V7M_ITM_TCR_ITMENA_Msk      (1UL << ARM_V7M_ITM_TCR_ITMENA_Pos)

/* ITM_TPR (Trace Privilege Register) */
#define ARM_V7M_ITM_TPR_PRIVMASK_Pos    0U
#define ARM_V7M_ITM_TPR_PRIVMASK_Msk    (0xFUL << ARM_V7M_ITM_TPR_PRIVMASK_Pos)

/* ITM_STIM (Stimulus Port) */
#define ARM_V7M_ITM_STIM_FIFOREADY_Pos  0U
#define ARM_V7M_ITM_STIM_FIFOREADY_Msk  (1UL << ARM_V7M_ITM_STIM_FIFOREADY_Pos)

/*============================================================================*
 * FPB Register Bit Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section C1.11
 *============================================================================*/

/* FP_CTRL (Flash Patch Control Register) */
#define ARM_V7M_FP_CTRL_REV_Pos         28U
#define ARM_V7M_FP_CTRL_REV_Msk         (0xFUL << ARM_V7M_FP_CTRL_REV_Pos)

#define ARM_V7M_FP_CTRL_SW_Pos          1U
#define ARM_V7M_FP_CTRL_SW_Msk          (1UL << ARM_V7M_FP_CTRL_SW_Pos)

#define ARM_V7M_FP_CTRL_ENABLE_Pos      0U
#define ARM_V7M_FP_CTRL_ENABLE_Msk      (1UL << ARM_V7M_FP_CTRL_ENABLE_Pos)

/* FP_COMP (Flash Patch Comparator Register) */
#define ARM_V7M_FP_COMP_REPLACE_Pos     30U
#define ARM_V7M_FP_COMP_REPLACE_Msk     (0x3UL << ARM_V7M_FP_COMP_REPLACE_Pos)

#define ARM_V7M_FP_COMP_COMP_Pos        0U
#define ARM_V7M_FP_COMP_COMP_Msk        (0x1FFFFFFUL << ARM_V7M_FP_COMP_COMP_Pos)

/* Replace Values */
#define ARM_V7M_FP_COMP_REPLACE_NONE    0x0U
#define ARM_V7M_FP_COMP_REPLACE_BKPT    0x1U
#define ARM_V7M_FP_COMP_REPLACE_PATCH   0x2U

/*============================================================================*
 * TPIU Register Bit Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section C1.10
 *============================================================================*/

/* TPIU_SSPSR (Supported Parallel Port Sizes Register) */
#define ARM_V7M_TPIU_SSPSR_SWIDTH_Pos   0U
#define ARM_V7M_TPIU_SSPSR_SWIDTH_Msk   (0xFFFFUL << ARM_V7M_TPIU_SSPSR_SWIDTH_Pos)

/* TPIU_CSPSR (Current Parallel Port Size Register) */
#define ARM_V7M_TPIU_CSPSR_CWIDTH_Pos   0U
#define ARM_V7M_TPIU_CSPSR_CWIDTH_Msk   (0xFFFFUL << ARM_V7M_TPIU_CSPSR_CWIDTH_Pos)

/* TPIU_ACPR (Asynchronous Clock Prescaler Register) */
#define ARM_V7M_TPIU_ACPR_PRESCALER_Pos 0U
#define ARM_V7M_TPIU_ACPR_PRESCALER_Msk (0x1FFFUL << ARM_V7M_TPIU_ACPR_PRESCALER_Pos)

/* TPIU_SPPR (Selected Pin Protocol Register) */
#define ARM_V7M_TPIU_SPPR_TXMODE_Pos    0U
#define ARM_V7M_TPIU_SPPR_TXMODE_Msk    (0x3UL << ARM_V7M_TPIU_SPPR_TXMODE_Pos)

#define ARM_V7M_TPIU_SPPR_TXMODE_PARALLEL   0x0U
#define ARM_V7M_TPIU_SPPR_TXMODE_SWO_MAN    0x1U
#define ARM_V7M_TPIU_SPPR_TXMODE_SWO_NRZ    0x2U

/*============================================================================*
 * Debug Core Register Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t DHCSR;        /*!< Offset: 0x00 (R/W)  Debug Halting Control and Status Register */
    volatile uint32_t DCRSR;        /*!< Offset: 0x04 (W)    Debug Core Register Selector Register */
    volatile uint32_t DCRDR;        /*!< Offset: 0x08 (R/W)  Debug Core Register Data Register */
    volatile uint32_t DEMCR;        /*!< Offset: 0x0C (R/W)  Debug Exception and Monitor Control Register */
} arm_v7m_debug_regs_t;

#define DEBUG               ((arm_v7m_debug_regs_t *)ARM_V7M_DEBUG_BASE)

/*============================================================================*
 * DWT Type Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section C1.8
 *============================================================================*/

typedef struct {
    volatile uint32_t CTRL;         /*!< Offset: 0x000 (R/W)  Control Register */
    volatile uint32_t CYCCNT;       /*!< Offset: 0x004 (R/W)  Cycle Count Register */
    volatile uint32_t CPICNT;       /*!< Offset: 0x008 (R/W)  CPI Count Register */
    volatile uint32_t EXCCNT;       /*!< Offset: 0x00C (R/W)  Exception Overhead Count Register */
    volatile uint32_t SLEEPCNT;     /*!< Offset: 0x010 (R/W)  Sleep Count Register */
    volatile uint32_t LSUCNT;       /*!< Offset: 0x014 (R/W)  LSU Count Register */
    volatile uint32_t FOLDCNT;      /*!< Offset: 0x018 (R/W)  Folded-instruction Count Register */
    volatile uint32_t PCSR;         /*!< Offset: 0x01C (R/ )  Program Counter Sample Register */
    volatile uint32_t COMP0;        /*!< Offset: 0x020 (R/W)  Comparator Register 0 */
    volatile uint32_t MASK0;        /*!< Offset: 0x024 (R/W)  Mask Register 0 */
    volatile uint32_t FUNCTION0;    /*!< Offset: 0x028 (R/W)  Function Register 0 */
    volatile uint32_t RESERVED0[1];
    volatile uint32_t COMP1;        /*!< Offset: 0x030 (R/W)  Comparator Register 1 */
    volatile uint32_t MASK1;        /*!< Offset: 0x034 (R/W)  Mask Register 1 */
    volatile uint32_t FUNCTION1;    /*!< Offset: 0x038 (R/W)  Function Register 1 */
    volatile uint32_t RESERVED1[1];
    volatile uint32_t COMP2;        /*!< Offset: 0x040 (R/W)  Comparator Register 2 */
    volatile uint32_t MASK2;        /*!< Offset: 0x044 (R/W)  Mask Register 2 */
    volatile uint32_t FUNCTION2;    /*!< Offset: 0x048 (R/W)  Function Register 2 */
    volatile uint32_t RESERVED2[1];
    volatile uint32_t COMP3;        /*!< Offset: 0x050 (R/W)  Comparator Register 3 */
    volatile uint32_t MASK3;        /*!< Offset: 0x054 (R/W)  Mask Register 3 */
    volatile uint32_t FUNCTION3;    /*!< Offset: 0x058 (R/W)  Function Register 3 */
} arm_v7m_dwt_regs_t;

#define DWT                 ((arm_v7m_dwt_regs_t *)ARM_V7M_DWT_BASE)

/*============================================================================*
 * ITM Type Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section C1.7
 *============================================================================*/

typedef struct {
    volatile uint32_t STIM[256];    /*!< Offset: 0x000-0x3FC (R/W)  Stimulus Port Registers */
    volatile uint32_t RESERVED0[640];
    volatile uint32_t TER[8];       /*!< Offset: 0xE00-0xE1C (R/W)  Trace Enable Registers */
    volatile uint32_t RESERVED1[8];
    volatile uint32_t TPR;          /*!< Offset: 0xE40 (R/W)  Trace Privilege Register */
    volatile uint32_t RESERVED2[15];
    volatile uint32_t TCR;          /*!< Offset: 0xE80 (R/W)  Trace Control Register */
} arm_v7m_itm_regs_t;

#define ITM                 ((arm_v7m_itm_regs_t *)ARM_V7M_ITM_BASE)

/*============================================================================*
 * FPB Type Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section C1.11
 *============================================================================*/

typedef struct {
    volatile uint32_t CTRL;         /*!< Offset: 0x000 (R/W)  Flash Patch Control Register */
    volatile uint32_t REMAP;        /*!< Offset: 0x004 (R/W)  Flash Patch Remap Register */
    volatile uint32_t COMP[128];    /*!< Offset: 0x008+ (R/W)  Flash Patch Comparator Registers */
} arm_v7m_fpb_regs_t;

#define FPB                 ((arm_v7m_fpb_regs_t *)ARM_V7M_FPB_BASE)

/*============================================================================*
 * TPIU Type Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section C1.10
 *============================================================================*/

typedef struct {
    volatile uint32_t SSPSR;        /*!< Offset: 0x000 (R/ )  Supported Parallel Port Sizes Register */
    volatile uint32_t CSPSR;        /*!< Offset: 0x004 (R/W)  Current Parallel Port Size Register */
    volatile uint32_t RESERVED0[2];
    volatile uint32_t ACPR;         /*!< Offset: 0x010 (R/W)  Asynchronous Clock Prescaler Register */
    volatile uint32_t RESERVED1[55];
    volatile uint32_t SPPR;         /*!< Offset: 0x0F0 (R/W)  Selected Pin Protocol Register */
} arm_v7m_tpiu_regs_t;

#define TPIU                ((arm_v7m_tpiu_regs_t *)ARM_V7M_TPIU_BASE)

/*============================================================================*
 * Inline Functions - Debug Basic Operations
 * These are simple register operations suitable for inlining
 *============================================================================*/

/**
 * @brief Check if processor is in Debug state (halted)
 * @return 1 if halted, 0 if running
 */
ARM_V7M_DEBUG_INLINE uint32_t arm_v7m_debug_is_halted(void)
{
    return (DEBUG->DHCSR & ARM_V7M_DHCSR_S_HALT_Msk) ? 1U : 0U;
}

/**
 * @brief Check if processor is in sleep state
 * @return 1 if sleeping, 0 if awake
 */
ARM_V7M_DEBUG_INLINE uint32_t arm_v7m_debug_is_sleeping(void)
{
    return (DEBUG->DHCSR & ARM_V7M_DHCSR_S_SLEEP_Msk) ? 1U : 0U;
}

/**
 * @brief Check if processor is in lockup state
 * @return 1 if locked up, 0 otherwise
 */
ARM_V7M_DEBUG_INLINE uint32_t arm_v7m_debug_is_locked_up(void)
{
    return (DEBUG->DHCSR & ARM_V7M_DHCSR_S_LOCKUP_Msk) ? 1U : 0U;
}

/**
 * @brief Check if register transfer is ready
 * @return 1 if ready, 0 if busy
 */
ARM_V7M_DEBUG_INLINE uint32_t arm_v7m_debug_is_reg_ready(void)
{
    return (DEBUG->DHCSR & ARM_V7M_DHCSR_S_REGRDY_Msk) ? 1U : 0U;
}

/**
 * @brief Enable DWT and ITM trace
 * @note Sets TRCENA bit in DEMCR to enable DWT and ITM units.
 */
ARM_V7M_DEBUG_INLINE void arm_v7m_debug_enable_trace(void)
{
    DEBUG->DEMCR |= ARM_V7M_DEMCR_TRCENA_Msk;
}

/**
 * @brief Disable DWT and ITM trace
 * @note Clears TRCENA bit in DEMCR.
 */
ARM_V7M_DEBUG_INLINE void arm_v7m_debug_disable_trace(void)
{
    DEBUG->DEMCR &= ~ARM_V7M_DEMCR_TRCENA_Msk;
}

/**
 * @brief Get the number of DWT comparators
 * @return Number of implemented comparators (0-15)
 */
ARM_V7M_DEBUG_INLINE uint32_t arm_v7m_dwt_get_num_comp(void)
{
    return (DWT->CTRL & ARM_V7M_DWT_CTRL_NUMCOMP_Msk) >> ARM_V7M_DWT_CTRL_NUMCOMP_Pos;
}

/**
 * @brief Check if DWT cycle counter is implemented
 * @return 1 if implemented, 0 if not
 */
ARM_V7M_DEBUG_INLINE uint32_t arm_v7m_dwt_has_cyccnt(void)
{
    return (DWT->CTRL & ARM_V7M_DWT_CTRL_NOCYCCNT_Msk) ? 0U : 1U;
}

/**
 * @brief Get DWT cycle count
 * @return Current cycle count value
 */
ARM_V7M_DEBUG_INLINE uint32_t arm_v7m_dwt_get_cyccnt(void)
{
    return DWT->CYCCNT;
}

/**
 * @brief Set DWT cycle count
 * @param value Value to write to cycle counter
 */
ARM_V7M_DEBUG_INLINE void arm_v7m_dwt_set_cyccnt(uint32_t value)
{
    DWT->CYCCNT = value;
}

/**
 * @brief Check if DWT cycle counter is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_DEBUG_INLINE uint32_t arm_v7m_dwt_is_cyccnt_enabled(void)
{
    return (DWT->CTRL & ARM_V7M_DWT_CTRL_CYCCNTENA_Msk) ? 1U : 0U;
}

/**
 * @brief Enable DWT cycle counter
 * @note Sets CYCCNTENA bit in DWT_CTRL to enable the cycle counter.
 */
ARM_V7M_DEBUG_INLINE void arm_v7m_dwt_enable_cyccnt(void)
{
    DWT->CTRL |= ARM_V7M_DWT_CTRL_CYCCNTENA_Msk;
}

/**
 * @brief Disable DWT cycle counter
 * @note Clears CYCCNTENA bit in DWT_CTRL.
 */
ARM_V7M_DEBUG_INLINE void arm_v7m_dwt_disable_cyccnt(void)
{
    DWT->CTRL &= ~ARM_V7M_DWT_CTRL_CYCCNTENA_Msk;
}

/**
 * @brief Get CPI count
 * @return CPI counter value
 */
ARM_V7M_DEBUG_INLINE uint32_t arm_v7m_dwt_get_cpicnt(void)
{
    return DWT->CPICNT;
}

/**
 * @brief Get exception overhead count
 * @return Exception overhead counter value
 */
ARM_V7M_DEBUG_INLINE uint32_t arm_v7m_dwt_get_exccnt(void)
{
    return DWT->EXCCNT;
}

/**
 * @brief Get sleep count
 * @return Sleep counter value
 */
ARM_V7M_DEBUG_INLINE uint32_t arm_v7m_dwt_get_sleepcnt(void)
{
    return DWT->SLEEPCNT;
}

/**
 * @brief Get LSU count
 * @return LSU counter value
 */
ARM_V7M_DEBUG_INLINE uint32_t arm_v7m_dwt_get_lsucnt(void)
{
    return DWT->LSUCNT;
}

/**
 * @brief Get folded instruction count
 * @return Folded instruction counter value
 */
ARM_V7M_DEBUG_INLINE uint32_t arm_v7m_dwt_get_foldcnt(void)
{
    return DWT->FOLDCNT;
}

/**
 * @brief Check if ITM is busy
 * @return 1 if busy, 0 if idle
 */
ARM_V7M_DEBUG_INLINE uint32_t arm_v7m_itm_is_busy(void)
{
    return (ITM->TCR & ARM_V7M_ITM_TCR_BUSY_Msk) ? 1U : 0U;
}

/**
 * @brief Check if ITM stimulus port is ready
 * @param port Stimulus port number (0-255)
 * @return 1 if ready, 0 if FIFO full
 */
ARM_V7M_DEBUG_INLINE uint32_t arm_v7m_itm_is_port_ready(uint32_t port)
{
    return (ITM->STIM[port] & ARM_V7M_ITM_STIM_FIFOREADY_Msk) ? 1U : 0U;
}

/**
 * @brief Write to ITM stimulus port
 * @param port Stimulus port number (0-255)
 * @param value Value to write
 */
ARM_V7M_DEBUG_INLINE void arm_v7m_itm_write_port(uint32_t port, uint32_t value)
{
    ITM->STIM[port] = value;
}

/**
 * @brief Check if ITM is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_DEBUG_INLINE uint32_t arm_v7m_itm_is_enabled(void)
{
    return (ITM->TCR & ARM_V7M_ITM_TCR_ITMENA_Msk) ? 1U : 0U;
}

/**
 * @brief Enable ITM
 * @note Sets ITMENA bit in ITM_TCR.
 */
ARM_V7M_DEBUG_INLINE void arm_v7m_itm_enable(void)
{
    ITM->TCR |= ARM_V7M_ITM_TCR_ITMENA_Msk;
}

/**
 * @brief Disable ITM
 * @note Clears ITMENA bit in ITM_TCR.
 */
ARM_V7M_DEBUG_INLINE void arm_v7m_itm_disable(void)
{
    ITM->TCR &= ~ARM_V7M_ITM_TCR_ITMENA_Msk;
}

/**
 * @brief Enable ITM stimulus port
 * @param port Stimulus port number (0-255)
 */
ARM_V7M_DEBUG_INLINE void arm_v7m_itm_enable_port(uint32_t port)
{
    uint32_t reg_idx = port >> 5U;
    uint32_t bit_pos = port & 0x1FU;
    
    if (reg_idx < 8U) {
        ITM->TER[reg_idx] |= (1UL << bit_pos);
    }
}

/**
 * @brief Disable ITM stimulus port
 * @param port Stimulus port number (0-255)
 */
ARM_V7M_DEBUG_INLINE void arm_v7m_itm_disable_port(uint32_t port)
{
    uint32_t reg_idx = port >> 5U;
    uint32_t bit_pos = port & 0x1FU;
    
    if (reg_idx < 8U) {
        ITM->TER[reg_idx] &= ~(1UL << bit_pos);
    }
}

/**
 * @brief Send data to ITM stimulus port
 * @param port Stimulus port number (0-255)
 * @param data Data value to send
 */
ARM_V7M_DEBUG_INLINE void arm_v7m_itm_send_data(uint32_t port, uint32_t data)
{
    if (port < 256U) {
        ITM->STIM[port] = data;
    }
}

/**
 * @brief Send character to ITM stimulus port
 * @param port Stimulus port number (0-255)
 * @param c Character to send
 */
ARM_V7M_DEBUG_INLINE void arm_v7m_itm_send_char(uint32_t port, char c)
{
    if (port < 256U) {
        ITM->STIM[port] = (uint32_t)c;
    }
}

/**
 * @brief Get FPB revision
 * @return FPB revision number
 */
ARM_V7M_DEBUG_INLINE uint32_t arm_v7m_fpb_get_revision(void)
{
    return (FPB->CTRL & ARM_V7M_FP_CTRL_REV_Msk) >> ARM_V7M_FP_CTRL_REV_Pos;
}

/**
 * @brief Check if FPB is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_DEBUG_INLINE uint32_t arm_v7m_fpb_is_enabled(void)
{
    return (FPB->CTRL & ARM_V7M_FP_CTRL_ENABLE_Msk) ? 1U : 0U;
}

/**
 * @brief Enable FPB
 * @note Sets ENABLE bit in FP_CTRL.
 */
ARM_V7M_DEBUG_INLINE void arm_v7m_fpb_enable(void)
{
    FPB->CTRL |= ARM_V7M_FP_CTRL_ENABLE_Msk;
}

/**
 * @brief Disable FPB
 * @note Clears ENABLE bit in FP_CTRL.
 */
ARM_V7M_DEBUG_INLINE void arm_v7m_fpb_disable(void)
{
    FPB->CTRL &= ~ARM_V7M_FP_CTRL_ENABLE_Msk;
}

/**
 * @brief Clear hardware breakpoint
 * @param comp_id Comparator ID (0-127)
 */
ARM_V7M_DEBUG_INLINE void arm_v7m_fpb_clear_breakpoint(uint32_t comp_id)
{
    if (comp_id < 128U) {
        FPB->COMP[comp_id] = 0U;
    }
}

/**
 * @brief Set FPB remap address
 * @param remap_address Remap base address
 */
ARM_V7M_DEBUG_INLINE void arm_v7m_fpb_set_remap(uint32_t remap_address)
{
    FPB->REMAP = remap_address;
}

/**
 * @brief Set TPIU prescaler
 * @param prescaler Clock prescaler value
 */
ARM_V7M_DEBUG_INLINE void arm_v7m_tpiu_set_prescaler(uint32_t prescaler)
{
    TPIU->ACPR = prescaler & ARM_V7M_TPIU_ACPR_PRESCALER_Msk;
}

/**
 * @brief Get supported TPIU port sizes
 * @return Bit mask of supported port sizes
 */
ARM_V7M_DEBUG_INLINE uint32_t arm_v7m_tpiu_get_supported_port_sizes(void)
{
    return TPIU->SSPSR & ARM_V7M_TPIU_SSPSR_SWIDTH_Msk;
}

/*============================================================================*
 * Non-Inline Functions - Complex Operations
 * These functions are implemented in the source file
 *============================================================================*/

/* Debug control functions */
void arm_v7m_debug_halt(void);
void arm_v7m_debug_resume(void);
void arm_v7m_debug_step(void);

/* DWT comparator functions */
uint32_t arm_v7m_dwt_enable_comp(uint32_t comp_id, uint32_t comp_value, uint32_t function);
void arm_v7m_dwt_disable_comp(uint32_t comp_id);

/* DWT performance counter functions */
void arm_v7m_dwt_enable_perf_counters(void);
void arm_v7m_dwt_disable_perf_counters(void);
void arm_v7m_dwt_reset_perf_counters(void);

/* Core register access functions (for debugger use) */
uint32_t arm_v7m_debug_read_reg(uint32_t regsel);
void arm_v7m_debug_write_reg(uint32_t regsel, uint32_t value);

/* Vector catch configuration */
void arm_v7m_debug_enable_vector_catch(uint32_t vc_mask);
void arm_v7m_debug_disable_vector_catch(uint32_t vc_mask);

/* ITM functions */
uint32_t arm_v7m_itm_get_num_ports(void);
void arm_v7m_itm_send_string(uint32_t port, const char *str);

/* FPB functions */
uint32_t arm_v7m_fpb_get_num_code_comparators(void);
uint32_t arm_v7m_fpb_get_num_literal_comparators(void);
uint32_t arm_v7m_fpb_set_breakpoint(uint32_t comp_id, uint32_t address);

/* TPIU functions */
void arm_v7m_tpiu_enable_swo(uint32_t prescaler);
void arm_v7m_tpiu_disable_swo(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_DEBUG_H */
