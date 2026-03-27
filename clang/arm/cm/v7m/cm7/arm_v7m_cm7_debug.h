/*
 * arm_v7m_cm7_debug.h
 * Cortex-M7 Debug Support Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Part C
 *            - Section C1.6: Debug system registers on page C1-699
 *            - Section C1.6.2: Debug Halting Control and Status Register, DHCSR on page C1-700
 *            - Section C1.6.3: Debug Core Register Selector Register, DCRSR on page C1-703
 *            - Section C1.6.4: Debug Core Register Data Register, DCRDR on page C1-704
 *            - Section C1.6.5: Debug Exception and Monitor Control Register, DEMCR on page C1-706
 *            - Section C1.7: The Instrumentation Trace Macrocell (ITM) on page C1-709
 *            - Section C1.8: The Data Watchpoint and Trace unit (DWT) on page C1-717
 *            - Section C1.10: Trace Port Interface Unit (TPIU) on page C1-736
 *            - Section C1.11: Flash Patch and Breakpoint unit (FPB) on page C1-742
 *            Cortex-M7 Devices Generic User Guide, Chapter 10
 *            - About debug on page 10-2
 *            - Debug register summary on page 10-2
 *            Cortex-M7 Technical Reference Manual
 *            - Chapter 9: Debug on page 9-1
 *            - Chapter 10: Cross Trigger Interface (CTI) on page 10-1
 *            - Chapter 11: Data Watchpoint and Trace Unit (DWT) on page 11-1
 *            - Chapter 12: Instrumentation Trace Macrocell Unit (ITM) on page 12-1
 *
 * @note This file reuses Armv7-M generic debug definitions.
 */

#ifndef ARM_V7M_CM7_DEBUG_H
#define ARM_V7M_CM7_DEBUG_H

#include <stdint.h>
#include "../arm_v7m_debug.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Compiler Abstraction - Inline Definition
 *============================================================================*/

#if defined(__clang__)
    #define ARM_V7M_CM7_DEBUG_INLINE static inline __attribute__((always_inline))
#else
    #error "This library requires Clang/LLVM compiler."
#endif

/*============================================================================*
 * Type Aliases
 *============================================================================*/

typedef arm_v7m_debug_regs_t        arm_v7m_cm7_debug_regs_t;
typedef arm_v7m_dwt_regs_t          arm_v7m_cm7_dwt_regs_t;
typedef arm_v7m_itm_regs_t          arm_v7m_cm7_itm_regs_t;
typedef arm_v7m_fpb_regs_t          arm_v7m_cm7_fpb_regs_t;
typedef arm_v7m_tpiu_regs_t         arm_v7m_cm7_tpiu_regs_t;

/*============================================================================*
 * Constant Aliases - DHCSR (Debug Halting Control and Status Register)
 *============================================================================*/

/* Debug Key */
#define ARM_V7M_CM7_DHCSR_DBGKEY_Pos            ARM_V7M_DHCSR_DBGKEY_Pos
#define ARM_V7M_CM7_DHCSR_DBGKEY_Msk            ARM_V7M_DHCSR_DBGKEY_Msk
#define ARM_V7M_CM7_DHCSR_DBGKEY                ARM_V7M_DHCSR_DBGKEY

/* Status Bits */
#define ARM_V7M_CM7_DHCSR_S_RESET_ST_Pos        ARM_V7M_DHCSR_S_RESET_ST_Pos
#define ARM_V7M_CM7_DHCSR_S_RESET_ST_Msk        ARM_V7M_DHCSR_S_RESET_ST_Msk
#define ARM_V7M_CM7_DHCSR_S_RETIRE_ST_Pos       ARM_V7M_DHCSR_S_RETIRE_ST_Pos
#define ARM_V7M_CM7_DHCSR_S_RETIRE_ST_Msk       ARM_V7M_DHCSR_S_RETIRE_ST_Msk
#define ARM_V7M_CM7_DHCSR_S_LOCKUP_Pos          ARM_V7M_DHCSR_S_LOCKUP_Pos
#define ARM_V7M_CM7_DHCSR_S_LOCKUP_Msk          ARM_V7M_DHCSR_S_LOCKUP_Msk
#define ARM_V7M_CM7_DHCSR_S_SLEEP_Pos           ARM_V7M_DHCSR_S_SLEEP_Pos
#define ARM_V7M_CM7_DHCSR_S_SLEEP_Msk           ARM_V7M_DHCSR_S_SLEEP_Msk
#define ARM_V7M_CM7_DHCSR_S_HALT_Pos            ARM_V7M_DHCSR_S_HALT_Pos
#define ARM_V7M_CM7_DHCSR_S_HALT_Msk            ARM_V7M_DHCSR_S_HALT_Msk
#define ARM_V7M_CM7_DHCSR_S_REGRDY_Pos          ARM_V7M_DHCSR_S_REGRDY_Pos
#define ARM_V7M_CM7_DHCSR_S_REGRDY_Msk          ARM_V7M_DHCSR_S_REGRDY_Msk

/* Control Bits */
#define ARM_V7M_CM7_DHCSR_C_SNAPSTALL_Pos       ARM_V7M_DHCSR_C_SNAPSTALL_Pos
#define ARM_V7M_CM7_DHCSR_C_SNAPSTALL_Msk       ARM_V7M_DHCSR_C_SNAPSTALL_Msk
#define ARM_V7M_CM7_DHCSR_C_MASKINTS_Pos        ARM_V7M_DHCSR_C_MASKINTS_Pos
#define ARM_V7M_CM7_DHCSR_C_MASKINTS_Msk        ARM_V7M_DHCSR_C_MASKINTS_Msk
#define ARM_V7M_CM7_DHCSR_C_STEP_Pos            ARM_V7M_DHCSR_C_STEP_Pos
#define ARM_V7M_CM7_DHCSR_C_STEP_Msk            ARM_V7M_DHCSR_C_STEP_Msk
#define ARM_V7M_CM7_DHCSR_C_HALT_Pos            ARM_V7M_DHCSR_C_HALT_Pos
#define ARM_V7M_CM7_DHCSR_C_HALT_Msk            ARM_V7M_DHCSR_C_HALT_Msk
#define ARM_V7M_CM7_DHCSR_C_DEBUGEN_Pos         ARM_V7M_DHCSR_C_DEBUGEN_Pos
#define ARM_V7M_CM7_DHCSR_C_DEBUGEN_Msk         ARM_V7M_DHCSR_C_DEBUGEN_Msk

/*============================================================================*
 * Constant Aliases - DCRSR (Debug Core Register Selector Register)
 *============================================================================*/

#define ARM_V7M_CM7_DCRSR_REGWnR_Pos            ARM_V7M_DCRSR_REGWnR_Pos
#define ARM_V7M_CM7_DCRSR_REGWnR_Msk            ARM_V7M_DCRSR_REGWnR_Msk
#define ARM_V7M_CM7_DCRSR_REGSEL_Pos            ARM_V7M_DCRSR_REGSEL_Pos
#define ARM_V7M_CM7_DCRSR_REGSEL_Msk            ARM_V7M_DCRSR_REGSEL_Msk

/* Register Selector Values */
#define ARM_V7M_CM7_DCRSR_REG_R0                ARM_V7M_DCRSR_REG_R0
#define ARM_V7M_CM7_DCRSR_REG_R1                ARM_V7M_DCRSR_REG_R1
#define ARM_V7M_CM7_DCRSR_REG_R2                ARM_V7M_DCRSR_REG_R2
#define ARM_V7M_CM7_DCRSR_REG_R3                ARM_V7M_DCRSR_REG_R3
#define ARM_V7M_CM7_DCRSR_REG_R4                ARM_V7M_DCRSR_REG_R4
#define ARM_V7M_CM7_DCRSR_REG_R5                ARM_V7M_DCRSR_REG_R5
#define ARM_V7M_CM7_DCRSR_REG_R6                ARM_V7M_DCRSR_REG_R6
#define ARM_V7M_CM7_DCRSR_REG_R7                ARM_V7M_DCRSR_REG_R7
#define ARM_V7M_CM7_DCRSR_REG_R8                ARM_V7M_DCRSR_REG_R8
#define ARM_V7M_CM7_DCRSR_REG_R9                ARM_V7M_DCRSR_REG_R9
#define ARM_V7M_CM7_DCRSR_REG_R10               ARM_V7M_DCRSR_REG_R10
#define ARM_V7M_CM7_DCRSR_REG_R11               ARM_V7M_DCRSR_REG_R11
#define ARM_V7M_CM7_DCRSR_REG_R12               ARM_V7M_DCRSR_REG_R12
#define ARM_V7M_CM7_DCRSR_REG_SP                ARM_V7M_DCRSR_REG_SP
#define ARM_V7M_CM7_DCRSR_REG_LR                ARM_V7M_DCRSR_REG_LR
#define ARM_V7M_CM7_DCRSR_REG_DEBUGRET          ARM_V7M_DCRSR_REG_DEBUGRET
#define ARM_V7M_CM7_DCRSR_REG_XPSR              ARM_V7M_DCRSR_REG_XPSR
#define ARM_V7M_CM7_DCRSR_REG_MSP               ARM_V7M_DCRSR_REG_MSP
#define ARM_V7M_CM7_DCRSR_REG_PSP               ARM_V7M_DCRSR_REG_PSP
#define ARM_V7M_CM7_DCRSR_REG_CTRL              ARM_V7M_DCRSR_REG_CTRL
#define ARM_V7M_CM7_DCRSR_REG_FPSCR             ARM_V7M_DCRSR_REG_FPSCR
#define ARM_V7M_CM7_DCRSR_REG_S0                ARM_V7M_DCRSR_REG_S0

/*============================================================================*
 * Constant Aliases - DEMCR (Debug Exception and Monitor Control Register)
 *============================================================================*/

#define ARM_V7M_CM7_DEMCR_TRCENA_Pos            ARM_V7M_DEMCR_TRCENA_Pos
#define ARM_V7M_CM7_DEMCR_TRCENA_Msk            ARM_V7M_DEMCR_TRCENA_Msk
#define ARM_V7M_CM7_DEMCR_MON_REQ_Pos           ARM_V7M_DEMCR_MON_REQ_Pos
#define ARM_V7M_CM7_DEMCR_MON_REQ_Msk           ARM_V7M_DEMCR_MON_REQ_Msk
#define ARM_V7M_CM7_DEMCR_MON_STEP_Pos          ARM_V7M_DEMCR_MON_STEP_Pos
#define ARM_V7M_CM7_DEMCR_MON_STEP_Msk          ARM_V7M_DEMCR_MON_STEP_Msk
#define ARM_V7M_CM7_DEMCR_MON_PEND_Pos          ARM_V7M_DEMCR_MON_PEND_Pos
#define ARM_V7M_CM7_DEMCR_MON_PEND_Msk          ARM_V7M_DEMCR_MON_PEND_Msk
#define ARM_V7M_CM7_DEMCR_MON_EN_Pos            ARM_V7M_DEMCR_MON_EN_Pos
#define ARM_V7M_CM7_DEMCR_MON_EN_Msk            ARM_V7M_DEMCR_MON_EN_Msk

/* Vector Catch Bits */
#define ARM_V7M_CM7_DEMCR_VC_HARDERR_Pos        ARM_V7M_DEMCR_VC_HARDERR_Pos
#define ARM_V7M_CM7_DEMCR_VC_HARDERR_Msk        ARM_V7M_DEMCR_VC_HARDERR_Msk
#define ARM_V7M_CM7_DEMCR_VC_INTERR_Pos         ARM_V7M_DEMCR_VC_INTERR_Pos
#define ARM_V7M_CM7_DEMCR_VC_INTERR_Msk         ARM_V7M_DEMCR_VC_INTERR_Msk
#define ARM_V7M_CM7_DEMCR_VC_BUSERR_Pos         ARM_V7M_DEMCR_VC_BUSERR_Pos
#define ARM_V7M_CM7_DEMCR_VC_BUSERR_Msk         ARM_V7M_DEMCR_VC_BUSERR_Msk
#define ARM_V7M_CM7_DEMCR_VC_STATERR_Pos        ARM_V7M_DEMCR_VC_STATERR_Pos
#define ARM_V7M_CM7_DEMCR_VC_STATERR_Msk        ARM_V7M_DEMCR_VC_STATERR_Msk
#define ARM_V7M_CM7_DEMCR_VC_CHKERR_Pos         ARM_V7M_DEMCR_VC_CHKERR_Pos
#define ARM_V7M_CM7_DEMCR_VC_CHKERR_Msk         ARM_V7M_DEMCR_VC_CHKERR_Msk
#define ARM_V7M_CM7_DEMCR_VC_NOCPERR_Pos        ARM_V7M_DEMCR_VC_NOCPERR_Pos
#define ARM_V7M_CM7_DEMCR_VC_NOCPERR_Msk        ARM_V7M_DEMCR_VC_NOCPERR_Msk
#define ARM_V7M_CM7_DEMCR_VC_MMERR_Pos          ARM_V7M_DEMCR_VC_MMERR_Pos
#define ARM_V7M_CM7_DEMCR_VC_MMERR_Msk          ARM_V7M_DEMCR_VC_MMERR_Msk
#define ARM_V7M_CM7_DEMCR_VC_CORERESET_Pos      ARM_V7M_DEMCR_VC_CORERESET_Pos
#define ARM_V7M_CM7_DEMCR_VC_CORERESET_Msk      ARM_V7M_DEMCR_VC_CORERESET_Msk

/*============================================================================*
 * Constant Aliases - DWT_CTRL (DWT Control Register)
 *============================================================================*/

#define ARM_V7M_CM7_DWT_CTRL_NUMCOMP_Pos        ARM_V7M_DWT_CTRL_NUMCOMP_Pos
#define ARM_V7M_CM7_DWT_CTRL_NUMCOMP_Msk        ARM_V7M_DWT_CTRL_NUMCOMP_Msk
#define ARM_V7M_CM7_DWT_CTRL_NOTRCPKT_Pos       ARM_V7M_DWT_CTRL_NOTRCPKT_Pos
#define ARM_V7M_CM7_DWT_CTRL_NOTRCPKT_Msk       ARM_V7M_DWT_CTRL_NOTRCPKT_Msk
#define ARM_V7M_CM7_DWT_CTRL_NOEXTTRIG_Pos      ARM_V7M_DWT_CTRL_NOEXTTRIG_Pos
#define ARM_V7M_CM7_DWT_CTRL_NOEXTTRIG_Msk      ARM_V7M_DWT_CTRL_NOEXTTRIG_Msk
#define ARM_V7M_CM7_DWT_CTRL_NOCYCCNT_Pos       ARM_V7M_DWT_CTRL_NOCYCCNT_Pos
#define ARM_V7M_CM7_DWT_CTRL_NOCYCCNT_Msk       ARM_V7M_DWT_CTRL_NOCYCCNT_Msk
#define ARM_V7M_CM7_DWT_CTRL_NOPRFCNT_Pos       ARM_V7M_DWT_CTRL_NOPRFCNT_Pos
#define ARM_V7M_CM7_DWT_CTRL_NOPRFCNT_Msk       ARM_V7M_DWT_CTRL_NOPRFCNT_Msk
#define ARM_V7M_CM7_DWT_CTRL_CYCCNTENA_Pos      ARM_V7M_DWT_CTRL_CYCCNTENA_Pos
#define ARM_V7M_CM7_DWT_CTRL_CYCCNTENA_Msk      ARM_V7M_DWT_CTRL_CYCCNTENA_Msk

/*============================================================================*
 * Constant Aliases - DWT_FUNCTION (Comparator Function Register)
 *============================================================================*/

#define ARM_V7M_CM7_DWT_FUNCTION_DATAVMATCH_Pos ARM_V7M_DWT_FUNCTION_DATAVMATCH_Pos
#define ARM_V7M_CM7_DWT_FUNCTION_DATAVMATCH_Msk ARM_V7M_DWT_FUNCTION_DATAVMATCH_Msk
#define ARM_V7M_CM7_DWT_FUNCTION_CYCMATCH_Pos   ARM_V7M_DWT_FUNCTION_CYCMATCH_Pos
#define ARM_V7M_CM7_DWT_FUNCTION_CYCMATCH_Msk   ARM_V7M_DWT_FUNCTION_CYCMATCH_Msk
#define ARM_V7M_CM7_DWT_FUNCTION_EMITRANGE_Pos  ARM_V7M_DWT_FUNCTION_EMITRANGE_Pos
#define ARM_V7M_CM7_DWT_FUNCTION_EMITRANGE_Msk  ARM_V7M_DWT_FUNCTION_EMITRANGE_Msk
#define ARM_V7M_CM7_DWT_FUNCTION_FUNCTION_Pos   ARM_V7M_DWT_FUNCTION_FUNCTION_Pos
#define ARM_V7M_CM7_DWT_FUNCTION_FUNCTION_Msk   ARM_V7M_DWT_FUNCTION_FUNCTION_Msk

/* Function Values */
#define ARM_V7M_CM7_DWT_FUNCTION_DISABLED       ARM_V7M_DWT_FUNCTION_DISABLED
#define ARM_V7M_CM7_DWT_FUNCTION_PC_SAMPLE      ARM_V7M_DWT_FUNCTION_PC_SAMPLE
#define ARM_V7M_CM7_DWT_FUNCTION_DATA_RW        ARM_V7M_DWT_FUNCTION_DATA_RW
#define ARM_V7M_CM7_DWT_FUNCTION_DATA_RWP       ARM_V7M_DWT_FUNCTION_DATA_RWP
#define ARM_V7M_CM7_DWT_FUNCTION_PC_WATCH       ARM_V7M_DWT_FUNCTION_PC_WATCH
#define ARM_V7M_CM7_DWT_FUNCTION_DATA_R_WATCH   ARM_V7M_DWT_FUNCTION_DATA_R_WATCH
#define ARM_V7M_CM7_DWT_FUNCTION_DATA_W_WATCH   ARM_V7M_DWT_FUNCTION_DATA_W_WATCH
#define ARM_V7M_CM7_DWT_FUNCTION_DATA_RW_WATCH  ARM_V7M_DWT_FUNCTION_DATA_RW_WATCH

/*============================================================================*
 * Constant Aliases - ITM Registers
 *============================================================================*/

/* ITM_TCR (Trace Control Register) */
#define ARM_V7M_CM7_ITM_TCR_BUSY_Pos            ARM_V7M_ITM_TCR_BUSY_Pos
#define ARM_V7M_CM7_ITM_TCR_BUSY_Msk            ARM_V7M_ITM_TCR_BUSY_Msk
#define ARM_V7M_CM7_ITM_TCR_TRACEBUSID_Pos      ARM_V7M_ITM_TCR_TRACEBUSID_Pos
#define ARM_V7M_CM7_ITM_TCR_TRACEBUSID_Msk      ARM_V7M_ITM_TCR_TRACEBUSID_Msk
#define ARM_V7M_CM7_ITM_TCR_GTSFREQ_Pos         ARM_V7M_ITM_TCR_GTSFREQ_Pos
#define ARM_V7M_CM7_ITM_TCR_GTSFREQ_Msk         ARM_V7M_ITM_TCR_GTSFREQ_Msk
#define ARM_V7M_CM7_ITM_TCR_TSPRESCALE_Pos      ARM_V7M_ITM_TCR_TSPRESCALE_Pos
#define ARM_V7M_CM7_ITM_TCR_TSPRESCALE_Msk      ARM_V7M_ITM_TCR_TSPRESCALE_Msk
#define ARM_V7M_CM7_ITM_TCR_SWOENA_Pos          ARM_V7M_ITM_TCR_SWOENA_Pos
#define ARM_V7M_CM7_ITM_TCR_SWOENA_Msk          ARM_V7M_ITM_TCR_SWOENA_Msk
#define ARM_V7M_CM7_ITM_TCR_TXENA_Pos           ARM_V7M_ITM_TCR_TXENA_Pos
#define ARM_V7M_CM7_ITM_TCR_TXENA_Msk           ARM_V7M_ITM_TCR_TXENA_Msk
#define ARM_V7M_CM7_ITM_TCR_SYNCENA_Pos         ARM_V7M_ITM_TCR_SYNCENA_Pos
#define ARM_V7M_CM7_ITM_TCR_SYNCENA_Msk         ARM_V7M_ITM_TCR_SYNCENA_Msk
#define ARM_V7M_CM7_ITM_TCR_TSENA_Pos           ARM_V7M_ITM_TCR_TSENA_Pos
#define ARM_V7M_CM7_ITM_TCR_TSENA_Msk           ARM_V7M_ITM_TCR_TSENA_Msk
#define ARM_V7M_CM7_ITM_TCR_ITMENA_Pos          ARM_V7M_ITM_TCR_ITMENA_Pos
#define ARM_V7M_CM7_ITM_TCR_ITMENA_Msk          ARM_V7M_ITM_TCR_ITMENA_Msk

/* ITM_TPR (Trace Privilege Register) */
#define ARM_V7M_CM7_ITM_TPR_PRIVMASK_Pos        ARM_V7M_ITM_TPR_PRIVMASK_Pos
#define ARM_V7M_CM7_ITM_TPR_PRIVMASK_Msk        ARM_V7M_ITM_TPR_PRIVMASK_Msk

/* ITM_STIM (Stimulus Port) */
#define ARM_V7M_CM7_ITM_STIM_FIFOREADY_Pos      ARM_V7M_ITM_STIM_FIFOREADY_Pos
#define ARM_V7M_CM7_ITM_STIM_FIFOREADY_Msk      ARM_V7M_ITM_STIM_FIFOREADY_Msk

/*============================================================================*
 * Constant Aliases - FPB Registers
 *============================================================================*/

/* FP_CTRL (Flash Patch Control Register) */
#define ARM_V7M_CM7_FP_CTRL_REV_Pos             ARM_V7M_FP_CTRL_REV_Pos
#define ARM_V7M_CM7_FP_CTRL_REV_Msk             ARM_V7M_FP_CTRL_REV_Msk
#define ARM_V7M_CM7_FP_CTRL_SW_Pos              ARM_V7M_FP_CTRL_SW_Pos
#define ARM_V7M_CM7_FP_CTRL_SW_Msk              ARM_V7M_FP_CTRL_SW_Msk
#define ARM_V7M_CM7_FP_CTRL_ENABLE_Pos          ARM_V7M_FP_CTRL_ENABLE_Pos
#define ARM_V7M_CM7_FP_CTRL_ENABLE_Msk          ARM_V7M_FP_CTRL_ENABLE_Msk

/* FP_COMP (Flash Patch Comparator Register) */
#define ARM_V7M_CM7_FP_COMP_REPLACE_Pos         ARM_V7M_FP_COMP_REPLACE_Pos
#define ARM_V7M_CM7_FP_COMP_REPLACE_Msk         ARM_V7M_FP_COMP_REPLACE_Msk
#define ARM_V7M_CM7_FP_COMP_COMP_Pos            ARM_V7M_FP_COMP_COMP_Pos
#define ARM_V7M_CM7_FP_COMP_COMP_Msk            ARM_V7M_FP_COMP_COMP_Msk

/* Replace Values */
#define ARM_V7M_CM7_FP_COMP_REPLACE_NONE        ARM_V7M_FP_COMP_REPLACE_NONE
#define ARM_V7M_CM7_FP_COMP_REPLACE_BKPT        ARM_V7M_FP_COMP_REPLACE_BKPT
#define ARM_V7M_CM7_FP_COMP_REPLACE_PATCH       ARM_V7M_FP_COMP_REPLACE_PATCH

/*============================================================================*
 * Constant Aliases - TPIU Registers
 *============================================================================*/

/* TPIU_SSPSR (Supported Parallel Port Sizes Register) */
#define ARM_V7M_CM7_TPIU_SSPSR_SWIDTH_Pos       ARM_V7M_TPIU_SSPSR_SWIDTH_Pos
#define ARM_V7M_CM7_TPIU_SSPSR_SWIDTH_Msk       ARM_V7M_TPIU_SSPSR_SWIDTH_Msk

/* TPIU_CSPSR (Current Parallel Port Size Register) */
#define ARM_V7M_CM7_TPIU_CSPSR_CWIDTH_Pos       ARM_V7M_TPIU_CSPSR_CWIDTH_Pos
#define ARM_V7M_CM7_TPIU_CSPSR_CWIDTH_Msk       ARM_V7M_TPIU_CSPSR_CWIDTH_Msk

/* TPIU_ACPR (Asynchronous Clock Prescaler Register) */
#define ARM_V7M_CM7_TPIU_ACPR_PRESCALER_Pos     ARM_V7M_TPIU_ACPR_PRESCALER_Pos
#define ARM_V7M_CM7_TPIU_ACPR_PRESCALER_Msk     ARM_V7M_TPIU_ACPR_PRESCALER_Msk

/* TPIU_SPPR (Selected Pin Protocol Register) */
#define ARM_V7M_CM7_TPIU_SPPR_TXMODE_Pos        ARM_V7M_TPIU_SPPR_TXMODE_Pos
#define ARM_V7M_CM7_TPIU_SPPR_TXMODE_Msk        ARM_V7M_TPIU_SPPR_TXMODE_Msk

#define ARM_V7M_CM7_TPIU_SPPR_TXMODE_PARALLEL   ARM_V7M_TPIU_SPPR_TXMODE_PARALLEL
#define ARM_V7M_CM7_TPIU_SPPR_TXMODE_SWO_MAN    ARM_V7M_TPIU_SPPR_TXMODE_SWO_MAN
#define ARM_V7M_CM7_TPIU_SPPR_TXMODE_SWO_NRZ    ARM_V7M_TPIU_SPPR_TXMODE_SWO_NRZ

/*============================================================================*
 * Inline Functions - Debug Basic Operations (Aliased from generic)
 *============================================================================*/

/**
 * @brief Check if processor is in Debug state (halted)
 * @return 1 if halted, 0 if running
 */
ARM_V7M_CM7_DEBUG_INLINE uint32_t arm_v7m_cm7_debug_is_halted(void)
{
    return arm_v7m_debug_is_halted();
}

/**
 * @brief Check if processor is in sleep state
 * @return 1 if sleeping, 0 if awake
 */
ARM_V7M_CM7_DEBUG_INLINE uint32_t arm_v7m_cm7_debug_is_sleeping(void)
{
    return arm_v7m_debug_is_sleeping();
}

/**
 * @brief Check if processor is in lockup state
 * @return 1 if locked up, 0 otherwise
 */
ARM_V7M_CM7_DEBUG_INLINE uint32_t arm_v7m_cm7_debug_is_locked_up(void)
{
    return arm_v7m_debug_is_locked_up();
}

/**
 * @brief Check if register transfer is ready
 * @return 1 if ready, 0 if busy
 */
ARM_V7M_CM7_DEBUG_INLINE uint32_t arm_v7m_cm7_debug_is_reg_ready(void)
{
    return arm_v7m_debug_is_reg_ready();
}

/**
 * @brief Enable DWT and ITM trace
 */
ARM_V7M_CM7_DEBUG_INLINE void arm_v7m_cm7_debug_enable_trace(void)
{
    arm_v7m_debug_enable_trace();
}

/**
 * @brief Disable DWT and ITM trace
 */
ARM_V7M_CM7_DEBUG_INLINE void arm_v7m_cm7_debug_disable_trace(void)
{
    arm_v7m_debug_disable_trace();
}

/*============================================================================*
 * Inline Functions - DWT Operations (Aliased from generic)
 *============================================================================*/

/**
 * @brief Get the number of DWT comparators
 * @return Number of implemented comparators (0-15)
 */
ARM_V7M_CM7_DEBUG_INLINE uint32_t arm_v7m_cm7_dwt_get_num_comp(void)
{
    return arm_v7m_dwt_get_num_comp();
}

/**
 * @brief Check if DWT cycle counter is implemented
 * @return 1 if implemented, 0 if not
 */
ARM_V7M_CM7_DEBUG_INLINE uint32_t arm_v7m_cm7_dwt_has_cyccnt(void)
{
    return arm_v7m_dwt_has_cyccnt();
}

/**
 * @brief Get DWT cycle count
 * @return Current cycle count value
 */
ARM_V7M_CM7_DEBUG_INLINE uint32_t arm_v7m_cm7_dwt_get_cyccnt(void)
{
    return arm_v7m_dwt_get_cyccnt();
}

/**
 * @brief Set DWT cycle count
 * @param value Value to write to cycle counter
 */
ARM_V7M_CM7_DEBUG_INLINE void arm_v7m_cm7_dwt_set_cyccnt(uint32_t value)
{
    arm_v7m_dwt_set_cyccnt(value);
}

/**
 * @brief Check if DWT cycle counter is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_CM7_DEBUG_INLINE uint32_t arm_v7m_cm7_dwt_is_cyccnt_enabled(void)
{
    return arm_v7m_dwt_is_cyccnt_enabled();
}

/**
 * @brief Enable DWT cycle counter
 */
ARM_V7M_CM7_DEBUG_INLINE void arm_v7m_cm7_dwt_enable_cyccnt(void)
{
    arm_v7m_dwt_enable_cyccnt();
}

/**
 * @brief Disable DWT cycle counter
 */
ARM_V7M_CM7_DEBUG_INLINE void arm_v7m_cm7_dwt_disable_cyccnt(void)
{
    arm_v7m_dwt_disable_cyccnt();
}

/**
 * @brief Get CPI count
 * @return CPI counter value
 */
ARM_V7M_CM7_DEBUG_INLINE uint32_t arm_v7m_cm7_dwt_get_cpicnt(void)
{
    return arm_v7m_dwt_get_cpicnt();
}

/**
 * @brief Get exception overhead count
 * @return Exception overhead counter value
 */
ARM_V7M_CM7_DEBUG_INLINE uint32_t arm_v7m_cm7_dwt_get_exccnt(void)
{
    return arm_v7m_dwt_get_exccnt();
}

/**
 * @brief Get sleep count
 * @return Sleep counter value
 */
ARM_V7M_CM7_DEBUG_INLINE uint32_t arm_v7m_cm7_dwt_get_sleepcnt(void)
{
    return arm_v7m_dwt_get_sleepcnt();
}

/**
 * @brief Get LSU count
 * @return LSU counter value
 */
ARM_V7M_CM7_DEBUG_INLINE uint32_t arm_v7m_cm7_dwt_get_lsucnt(void)
{
    return arm_v7m_dwt_get_lsucnt();
}

/**
 * @brief Get folded instruction count
 * @return Folded instruction counter value
 */
ARM_V7M_CM7_DEBUG_INLINE uint32_t arm_v7m_cm7_dwt_get_foldcnt(void)
{
    return arm_v7m_dwt_get_foldcnt();
}

/*============================================================================*
 * Inline Functions - ITM Operations (Aliased from generic)
 *============================================================================*/

/**
 * @brief Check if ITM is busy
 * @return 1 if busy, 0 if idle
 */
ARM_V7M_CM7_DEBUG_INLINE uint32_t arm_v7m_cm7_itm_is_busy(void)
{
    return arm_v7m_itm_is_busy();
}

/**
 * @brief Check if ITM stimulus port is ready
 * @param port Stimulus port number (0-255)
 * @return 1 if ready, 0 if FIFO full
 */
ARM_V7M_CM7_DEBUG_INLINE uint32_t arm_v7m_cm7_itm_is_port_ready(uint32_t port)
{
    return arm_v7m_itm_is_port_ready(port);
}

/**
 * @brief Write to ITM stimulus port
 * @param port Stimulus port number (0-255)
 * @param value Value to write
 */
ARM_V7M_CM7_DEBUG_INLINE void arm_v7m_cm7_itm_write_port(uint32_t port, uint32_t value)
{
    arm_v7m_itm_write_port(port, value);
}

/**
 * @brief Check if ITM is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_CM7_DEBUG_INLINE uint32_t arm_v7m_cm7_itm_is_enabled(void)
{
    return arm_v7m_itm_is_enabled();
}

/**
 * @brief Enable ITM
 */
ARM_V7M_CM7_DEBUG_INLINE void arm_v7m_cm7_itm_enable(void)
{
    arm_v7m_itm_enable();
}

/**
 * @brief Disable ITM
 */
ARM_V7M_CM7_DEBUG_INLINE void arm_v7m_cm7_itm_disable(void)
{
    arm_v7m_itm_disable();
}

/**
 * @brief Enable ITM stimulus port
 * @param port Stimulus port number (0-255)
 */
ARM_V7M_CM7_DEBUG_INLINE void arm_v7m_cm7_itm_enable_port(uint32_t port)
{
    arm_v7m_itm_enable_port(port);
}

/**
 * @brief Disable ITM stimulus port
 * @param port Stimulus port number (0-255)
 */
ARM_V7M_CM7_DEBUG_INLINE void arm_v7m_cm7_itm_disable_port(uint32_t port)
{
    arm_v7m_itm_disable_port(port);
}

/**
 * @brief Send data to ITM stimulus port
 * @param port Stimulus port number (0-255)
 * @param data Data value to send
 */
ARM_V7M_CM7_DEBUG_INLINE void arm_v7m_cm7_itm_send_data(uint32_t port, uint32_t data)
{
    arm_v7m_itm_send_data(port, data);
}

/**
 * @brief Send character to ITM stimulus port
 * @param port Stimulus port number (0-255)
 * @param c Character to send
 */
ARM_V7M_CM7_DEBUG_INLINE void arm_v7m_cm7_itm_send_char(uint32_t port, char c)
{
    arm_v7m_itm_send_char(port, c);
}

/*============================================================================*
 * Inline Functions - FPB Operations (Aliased from generic)
 *============================================================================*/

/**
 * @brief Get FPB revision
 * @return FPB revision number
 */
ARM_V7M_CM7_DEBUG_INLINE uint32_t arm_v7m_cm7_fpb_get_revision(void)
{
    return arm_v7m_fpb_get_revision();
}

/**
 * @brief Check if FPB is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_CM7_DEBUG_INLINE uint32_t arm_v7m_cm7_fpb_is_enabled(void)
{
    return arm_v7m_fpb_is_enabled();
}

/**
 * @brief Enable FPB
 */
ARM_V7M_CM7_DEBUG_INLINE void arm_v7m_cm7_fpb_enable(void)
{
    arm_v7m_fpb_enable();
}

/**
 * @brief Disable FPB
 */
ARM_V7M_CM7_DEBUG_INLINE void arm_v7m_cm7_fpb_disable(void)
{
    arm_v7m_fpb_disable();
}

/**
 * @brief Clear hardware breakpoint
 * @param comp_id Comparator ID (0-127)
 */
ARM_V7M_CM7_DEBUG_INLINE void arm_v7m_cm7_fpb_clear_breakpoint(uint32_t comp_id)
{
    arm_v7m_fpb_clear_breakpoint(comp_id);
}

/**
 * @brief Set FPB remap address
 * @param remap_address Remap base address
 */
ARM_V7M_CM7_DEBUG_INLINE void arm_v7m_cm7_fpb_set_remap(uint32_t remap_address)
{
    arm_v7m_fpb_set_remap(remap_address);
}

/*============================================================================*
 * Inline Functions - TPIU Operations (Aliased from generic)
 *============================================================================*/

/**
 * @brief Set TPIU prescaler
 * @param prescaler Clock prescaler value
 */
ARM_V7M_CM7_DEBUG_INLINE void arm_v7m_cm7_tpiu_set_prescaler(uint32_t prescaler)
{
    arm_v7m_tpiu_set_prescaler(prescaler);
}

/**
 * @brief Get supported TPIU port sizes
 * @return Bit mask of supported port sizes
 */
ARM_V7M_CM7_DEBUG_INLINE uint32_t arm_v7m_cm7_tpiu_get_supported_port_sizes(void)
{
    return arm_v7m_tpiu_get_supported_port_sizes();
}

/*============================================================================*
 * Non-Inline Functions - Complex Debug Operations
 *============================================================================*/

/* Debug control functions */
void arm_v7m_cm7_debug_halt(void);
void arm_v7m_cm7_debug_resume(void);
void arm_v7m_cm7_debug_step(void);

/* DWT comparator functions */
uint32_t arm_v7m_cm7_dwt_enable_comp(uint32_t comp_id, uint32_t comp_value, uint32_t function);
void arm_v7m_cm7_dwt_disable_comp(uint32_t comp_id);

/* DWT performance counter functions */
void arm_v7m_cm7_dwt_enable_perf_counters(void);
void arm_v7m_cm7_dwt_disable_perf_counters(void);
void arm_v7m_cm7_dwt_reset_perf_counters(void);

/* Core register access functions (for debugger use) */
uint32_t arm_v7m_cm7_debug_read_reg(uint32_t regsel);
void arm_v7m_cm7_debug_write_reg(uint32_t regsel, uint32_t value);

/* Vector catch configuration */
void arm_v7m_cm7_debug_enable_vector_catch(uint32_t vc_mask);
void arm_v7m_cm7_debug_disable_vector_catch(uint32_t vc_mask);

/* ITM functions */
uint32_t arm_v7m_cm7_itm_get_num_ports(void);
void arm_v7m_cm7_itm_send_string(uint32_t port, const char *str);

/* FPB functions */
uint32_t arm_v7m_cm7_fpb_get_num_code_comparators(void);
uint32_t arm_v7m_cm7_fpb_get_num_literal_comparators(void);
uint32_t arm_v7m_cm7_fpb_set_breakpoint(uint32_t comp_id, uint32_t address);

/* TPIU functions */
void arm_v7m_cm7_tpiu_enable_swo(uint32_t prescaler);
void arm_v7m_cm7_tpiu_disable_swo(void);

/*============================================================================*
 * CM7 Specific - CTI (Cross Trigger Interface) Operations
 * Reference: Cortex-M7 Technical Reference Manual, Chapter 10
 *            - Cross Trigger Interface (CTI) on page 10-1
 *            - Section 10.3: CTI programmers model on page 10-5
 *============================================================================*/

/* CTI Base Address */
#define ARM_V7M_CM7_CTI_BASE            0xE0042000UL

/* CTI Register Offsets */
#define ARM_V7M_CM7_CTI_CONTROL_OFFSET  0x00
#define ARM_V7M_CM7_CTI_INTACK_OFFSET   0x10
#define ARM_V7M_CM7_CTI_APPPULSE_OFFSET 0x1C

/* CTI Control Register Bits */
#define ARM_V7M_CM7_CTI_CONTROL_ENABLE_Pos  0U
#define ARM_V7M_CM7_CTI_CONTROL_ENABLE_Msk  (1UL << ARM_V7M_CM7_CTI_CONTROL_ENABLE_Pos)

/**
 * @brief Enable CTI
 */
void arm_v7m_cm7_cti_enable(void);

/**
 * @brief Disable CTI
 */
void arm_v7m_cm7_cti_disable(void);

/**
 * @brief Trigger CTI output channel
 * @param channel Channel number (0-7)
 */
void arm_v7m_cm7_cti_trigger_output(uint32_t channel);

/**
 * @brief Clear CTI trigger
 * @param channel Channel number (0-7)
 */
void arm_v7m_cm7_cti_clear_trigger(uint32_t channel);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM7_DEBUG_H */
