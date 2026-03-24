/*
 * ARM Architecture - Cortex-M4 Condition Code Definitions
 *
 * ============================================================================
 * File: cm4_condition.h
 * Description: Cortex-M4 condition code suffix definitions
 * 描述: Cortex-M4 条件码后缀定义
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 3.3.7 Conditional execution (page 3-18)
 *   - Table 3-4 Condition code suffixes (page 3-19)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_CONDITION_H__
#define __CM4_CONDITION_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * Condition Code Suffixes
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-4 (page 3-19)
 * ============================================================================
 */

/* EQ - Equal, Z=1
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-4 (page 3-19)
 */
#define CM4_COND_EQ     0x0

/* NE - Not equal, Z=0
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-4 (page 3-19)
 */
#define CM4_COND_NE     0x1

/* CS/HS - Higher or same, unsigned, C=1
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-4 (page 3-19)
 */
#define CM4_COND_CS     0x2
#define CM4_COND_HS     0x2

/* CC/LO - Lower, unsigned, C=0
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-4 (page 3-19)
 */
#define CM4_COND_CC     0x3
#define CM4_COND_LO     0x3

/* MI - Negative, N=1
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-4 (page 3-19)
 */
#define CM4_COND_MI     0x4

/* PL - Positive or zero, N=0
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-4 (page 3-19)
 */
#define CM4_COND_PL     0x5

/* VS - Overflow, V=1
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-4 (page 3-19)
 */
#define CM4_COND_VS     0x6

/* VC - No overflow, V=0
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-4 (page 3-19)
 */
#define CM4_COND_VC     0x7

/* HI - Higher, unsigned, C=1 and Z=0
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-4 (page 3-19)
 */
#define CM4_COND_HI     0x8

/* LS - Lower or same, unsigned, C=0 or Z=1
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-4 (page 3-19)
 */
#define CM4_COND_LS     0x9

/* GE - Greater than or equal, signed, N=V
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-4 (page 3-19)
 */
#define CM4_COND_GE     0xA

/* LT - Less than, signed, N!=V
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-4 (page 3-19)
 */
#define CM4_COND_LT     0xB

/* GT - Greater than, signed, Z=0 and N=V
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-4 (page 3-19)
 */
#define CM4_COND_GT     0xC

/* LE - Less than or equal, signed, Z=1 and N!=V
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-4 (page 3-19)
 */
#define CM4_COND_LE     0xD

/* AL - Always (default), can have any value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-4 (page 3-19)
 */
#define CM4_COND_AL     0xE

/*
 * ============================================================================
 * Condition Flag Definitions (APSR bits)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.3.7 (page 3-18)
 * ============================================================================
 */

/* N flag - Negative flag, bit 31 of APSR
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.3.7 (page 3-18)
 */
#define CM4_APSR_N_Pos      31U
#define CM4_APSR_N_Msk      (1UL << CM4_APSR_N_Pos)

/* Z flag - Zero flag, bit 30 of APSR
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.3.7 (page 3-18)
 */
#define CM4_APSR_Z_Pos      30U
#define CM4_APSR_Z_Msk      (1UL << CM4_APSR_Z_Pos)

/* C flag - Carry flag, bit 29 of APSR
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.3.7 (page 3-18)
 */
#define CM4_APSR_C_Pos      29U
#define CM4_APSR_C_Msk      (1UL << CM4_APSR_C_Pos)

/* V flag - Overflow flag, bit 28 of APSR
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.3.7 (page 3-18)
 */
#define CM4_APSR_V_Pos      28U
#define CM4_APSR_V_Msk      (1UL << CM4_APSR_V_Pos)

/* Q flag - Saturation flag, bit 27 of APSR
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.3 (page 2-5)
 */
#define CM4_APSR_Q_Pos      27U
#define CM4_APSR_Q_Msk      (1UL << CM4_APSR_Q_Pos)

/* GE flags - Greater than or Equal flags, bits 16-19 of APSR
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.3 (page 2-5)
 */
#define CM4_APSR_GE_Pos     16U
#define CM4_APSR_GE_Msk     (0xFUL << CM4_APSR_GE_Pos)

#ifdef __cplusplus
}
#endif

#endif /* __CM4_CONDITION_H__ */
