/*
 * ARM Architecture - Cortex-M4 Condition Codes
 *
 * ============================================================================
 * File: cm4_condition.h
 * Description: Cortex-M4 condition code definitions (wrapper for armv7-m_core.h)
 * 描述: Cortex-M4 条件码定义（armv7-m_core.h 的包装层）
 *
 * This file provides CM4-specific naming conventions while delegating
 * all actual definitions to armv7-m_core.h.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 3.3.1 Conditional execution (page 3-26)
 *   - Table 3-1 Condition code suffixes (page 3-26)
 *
 * Implementation: All functionality is provided by armv7-m/armv7-m_core.h
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_CONDITION_H__
#define __CM4_CONDITION_H__

#include <stdint.h>

/* Include the underlying ARMv7-M implementation */
#include "armv7-m/armv7-m_core.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * Condition Code Aliases - Map CM4 naming to ARMv7-M naming
 * 条件码别名 - 将 CM4 命名映射到 ARMv7-M 命名
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-1 (page 3-26)
 * ============================================================================
 */

#define CM4_COND_EQ                   ARMV7M_COND_EQ   /* Equal */
#define CM4_COND_NE                   ARMV7M_COND_NE   /* Not equal */
#define CM4_COND_CS                   ARMV7M_COND_CS   /* Carry set (unsigned higher or same) */
#define CM4_COND_HS                   ARMV7M_COND_HS   /* Unsigned higher or same (alias for CS) */
#define CM4_COND_CC                   ARMV7M_COND_CC   /* Carry clear (unsigned lower) */
#define CM4_COND_LO                   ARMV7M_COND_LO   /* Unsigned lower (alias for CC) */
#define CM4_COND_MI                   ARMV7M_COND_MI   /* Negative */
#define CM4_COND_PL                   ARMV7M_COND_PL   /* Positive or zero */
#define CM4_COND_VS                   ARMV7M_COND_VS   /* Overflow */
#define CM4_COND_VC                   ARMV7M_COND_VC   /* No overflow */
#define CM4_COND_HI                   ARMV7M_COND_HI   /* Unsigned higher */
#define CM4_COND_LS                   ARMV7M_COND_LS   /* Unsigned lower or same */
#define CM4_COND_GE                   ARMV7M_COND_GE   /* Signed greater than or equal */
#define CM4_COND_LT                   ARMV7M_COND_LT   /* Signed less than */
#define CM4_COND_GT                   ARMV7M_COND_GT   /* Signed greater than */
#define CM4_COND_LE                   ARMV7M_COND_LE   /* Signed less than or equal */
#define CM4_COND_AL                   ARMV7M_COND_AL   /* Always (default) */

/*
 * ============================================================================
 * APSR (Application Program Status Register) Bit Aliases
 * APSR 位别名
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 * ============================================================================
 */

/* Negative flag */
#define CM4_APSR_N_Pos                xPSR_N_Pos
#define CM4_APSR_N_Msk                xPSR_N_Msk

/* Zero flag */
#define CM4_APSR_Z_Pos                xPSR_Z_Pos
#define CM4_APSR_Z_Msk                xPSR_Z_Msk

/* Carry flag */
#define CM4_APSR_C_Pos                xPSR_C_Pos
#define CM4_APSR_C_Msk                xPSR_C_Msk

/* Overflow flag */
#define CM4_APSR_V_Pos                xPSR_V_Pos
#define CM4_APSR_V_Msk                xPSR_V_Msk

/* Saturation flag (DSP extension) */
#define CM4_APSR_Q_Pos                xPSR_Q_Pos
#define CM4_APSR_Q_Msk                xPSR_Q_Msk

/* Greater than or Equal flags (DSP extension) */
#define CM4_APSR_GE_Pos               xPSR_GE_Pos
#define CM4_APSR_GE_Msk               xPSR_GE_Msk

/*
 * ============================================================================
 * IPSR (Interrupt Program Status Register) Bit Aliases
 * IPSR 位别名
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 * ============================================================================
 */

#define CM4_IPSR_ISR_Pos              IPSR_ISR_Pos
#define CM4_IPSR_ISR_Msk              IPSR_ISR_Msk

/*
 * ============================================================================
 * EPSR (Execution Program Status Register) Bit Aliases
 * EPSR 位别名
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 * ============================================================================
 */

#define CM4_EPSR_ICI_IT_Pos           EPSR_ICI_IT_Pos
#define CM4_EPSR_ICI_IT_Msk           EPSR_ICI_IT_Msk
#define CM4_EPSR_T_Pos                EPSR_T_Pos
#define CM4_EPSR_T_Msk                EPSR_T_Msk

/*
 * ============================================================================
 * xPSR Combined Register Bit Aliases
 * xPSR 组合寄存器位别名
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 * ============================================================================
 */

/* All flags from APSR */
#define CM4_xPSR_N_Pos                xPSR_N_Pos
#define CM4_xPSR_N_Msk                xPSR_N_Msk
#define CM4_xPSR_Z_Pos                xPSR_Z_Pos
#define CM4_xPSR_Z_Msk                xPSR_Z_Msk
#define CM4_xPSR_C_Pos                xPSR_C_Pos
#define CM4_xPSR_C_Msk                xPSR_C_Msk
#define CM4_xPSR_V_Pos                xPSR_V_Pos
#define CM4_xPSR_V_Msk                xPSR_V_Msk
#define CM4_xPSR_Q_Pos                xPSR_Q_Pos
#define CM4_xPSR_Q_Msk                xPSR_Q_Msk
#define CM4_xPSR_GE_Pos               xPSR_GE_Pos
#define CM4_xPSR_GE_Msk               xPSR_GE_Msk

/* Exception number from IPSR */
#define CM4_xPSR_ISR_Pos              xPSR_ISR_Pos
#define CM4_xPSR_ISR_Msk              xPSR_ISR_Msk

/* ICI/IT state from EPSR */
#define CM4_xPSR_ICI_IT_Pos           xPSR_ICI_IT_Pos
#define CM4_xPSR_ICI_IT_Msk           xPSR_ICI_IT_Msk

/* Thumb state bit from EPSR */
#define CM4_xPSR_T_Pos                xPSR_T_Pos
#define CM4_xPSR_T_Msk                xPSR_T_Msk

/*
 * ============================================================================
 * CONTROL Register Bit Aliases
 * CONTROL 寄存器位别名
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-3 (page 2-5)
 * ============================================================================
 */

/* Thread mode privilege level */
#define CM4_CONTROL_nPRIV_Pos         CONTROL_nPRIV_Pos
#define CM4_CONTROL_nPRIV_Msk         CONTROL_nPRIV_Msk

/* Stack pointer selection */
#define CM4_CONTROL_SPSEL_Pos         CONTROL_SPSEL_Pos
#define CM4_CONTROL_SPSEL_Msk         CONTROL_SPSEL_Msk

/* Floating-point context active */
#define CM4_CONTROL_FPCA_Pos          CONTROL_FPCA_Pos
#define CM4_CONTROL_FPCA_Msk          CONTROL_FPCA_Msk

#ifdef __cplusplus
}
#endif

#endif /* __CM4_CONDITION_H__ */
