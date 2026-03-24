/*
 * ARM Architecture - Cortex-M4 SCB (System Control Block)
 *
 * ============================================================================
 * File: cm4_scb.h
 * Description: Cortex-M4 SCB register definitions
 * 描述: Cortex-M4 SCB 寄存器定义
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.3 System control block (page 4-10)
 *   - Table 4-12 SCB registers summary (page 4-11)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_SCB_H__
#define __CM4_SCB_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * SCB Base Address
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-12 (page 4-11)
 * ============================================================================
 */

#define CM4_SCB_BASE_ADDR             0xE000ED00UL

/*
 * ============================================================================
 * Auxiliary Control Register (ACTLR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 4-2 (page 4-53)
 * Address: 0xE000E008
 * ============================================================================
 */

#define SCB_ACTLR                     (*(volatile uint32_t *)(0xE000E008UL))

/* ACTLR bit definitions - Reference: Table 4-2 (page 4-53) */
#define SCB_ACTLR_DISMCYCINT_Pos      0U
#define SCB_ACTLR_DISMCYCINT_Msk      (1UL << SCB_ACTLR_DISMCYCINT_Pos)

#define SCB_ACTLR_DISDEFWBUF_Pos      1U
#define SCB_ACTLR_DISDEFWBUF_Msk      (1UL << SCB_ACTLR_DISDEFWBUF_Pos)

#define SCB_ACTLR_DISFOLD_Pos         2U
#define SCB_ACTLR_DISFOLD_Msk         (1UL << SCB_ACTLR_DISFOLD_Pos)

#define SCB_ACTLR_DISFPCA_Pos         8U
#define SCB_ACTLR_DISFPCA_Msk         (1UL << SCB_ACTLR_DISFPCA_Pos)

#define SCB_ACTLR_DISOOFP_Pos         9U
#define SCB_ACTLR_DISOOFP_Msk         (1UL << SCB_ACTLR_DISOOFP_Pos)

/*
 * ============================================================================
 * CPUID Base Register (CPUID)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 4-3 (page 4-54)
 * Address: 0xE000ED00
 * ============================================================================
 */

#define SCB_CPUID                     (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x000))

/* CPUID bit definitions - Reference: Table 4-3 (page 4-54) */
#define SCB_CPUID_REVISION_Pos        0U
#define SCB_CPUID_REVISION_Msk        (0xFUL << SCB_CPUID_REVISION_Pos)

#define SCB_CPUID_PARTNO_Pos          4U
#define SCB_CPUID_PARTNO_Msk          (0xFFFUL << SCB_CPUID_PARTNO_Pos)

#define SCB_CPUID_CONSTANT_Pos        16U
#define SCB_CPUID_CONSTANT_Msk        (0xFUL << SCB_CPUID_CONSTANT_Pos)

#define SCB_CPUID_VARIANT_Pos         20U
#define SCB_CPUID_VARIANT_Msk         (0xFUL << SCB_CPUID_VARIANT_Pos)

#define SCB_CPUID_IMPLEMENTER_Pos     24U
#define SCB_CPUID_IMPLEMENTER_Msk     (0xFFUL << SCB_CPUID_IMPLEMENTER_Pos)

/* Cortex-M4 specific values - Reference: Table 4-3 (page 4-54) */
#define SCB_CPUID_IMPLEMENTER_ARM     0x41UL
#define SCB_CPUID_VARIANT_R0          0x0UL
#define SCB_CPUID_CONSTANT_VALUE      0xFUL
#define SCB_CPUID_PARTNO_CORTEX_M4    0xC24UL
#define SCB_CPUID_REVISION_P1         0x1UL

/*
 * ============================================================================
 * Interrupt Control and State Register (ICSR)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-15 (page 4-14)
 * Address: 0xE000ED04
 * ============================================================================
 */

#define SCB_ICSR                      (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x004))

/* ICSR bit definitions - Reference: Table 4-15 (page 4-14) */
#define SCB_ICSR_VECTACTIVE_Pos       0U
#define SCB_ICSR_VECTACTIVE_Msk       (0x1FFUL << SCB_ICSR_VECTACTIVE_Pos)

#define SCB_ICSR_RETTOBASE_Pos        11U
#define SCB_ICSR_RETTOBASE_Msk        (1UL << SCB_ICSR_RETTOBASE_Pos)

#define SCB_ICSR_VECTPENDING_Pos      12U
#define SCB_ICSR_VECTPENDING_Msk      (0x1FFUL << SCB_ICSR_VECTPENDING_Pos)

#define SCB_ICSR_ISRPENDING_Pos       22U
#define SCB_ICSR_ISRPENDING_Msk       (1UL << SCB_ICSR_ISRPENDING_Pos)

#define SCB_ICSR_PENDSTCLR_Pos        25U
#define SCB_ICSR_PENDSTCLR_Msk        (1UL << SCB_ICSR_PENDSTCLR_Pos)

#define SCB_ICSR_PENDSTSET_Pos        26U
#define SCB_ICSR_PENDSTSET_Msk        (1UL << SCB_ICSR_PENDSTSET_Pos)

#define SCB_ICSR_PENDSVCLR_Pos        27U
#define SCB_ICSR_PENDSVCLR_Msk        (1UL << SCB_ICSR_PENDSVCLR_Pos)

#define SCB_ICSR_PENDSVSET_Pos        28U
#define SCB_ICSR_PENDSVSET_Msk        (1UL << SCB_ICSR_PENDSVSET_Pos)

#define SCB_ICSR_NMIPENDSET_Pos       31U
#define SCB_ICSR_NMIPENDSET_Msk       (1UL << SCB_ICSR_NMIPENDSET_Pos)

/*
 * ============================================================================
 * Vector Table Offset Register (VTOR)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-16 (page 4-16)
 * Address: 0xE000ED08
 * ============================================================================
 */

#define SCB_VTOR                      (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x008))

/* VTOR bit definitions - Reference: Table 4-16 (page 4-16) */
#define SCB_VTOR_TBLOFF_Pos           7U
#define SCB_VTOR_TBLOFF_Msk           (0x1FFFFFFUL << SCB_VTOR_TBLOFF_Pos)

/*
 * ============================================================================
 * Application Interrupt and Reset Control Register (AIRCR)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-17 (page 4-17)
 * Address: 0xE000ED0C
 * ============================================================================
 */

#define SCB_AIRCR                     (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x00C))

/* AIRCR bit definitions - Reference: Table 4-17 (page 4-17) */
#define SCB_AIRCR_VECTRESET_Pos       0U
#define SCB_AIRCR_VECTRESET_Msk       (1UL << SCB_AIRCR_VECTRESET_Pos)

#define SCB_AIRCR_VECTCLRACTIVE_Pos   1U
#define SCB_AIRCR_VECTCLRACTIVE_Msk   (1UL << SCB_AIRCR_VECTCLRACTIVE_Pos)

#define SCB_AIRCR_SYSRESETREQ_Pos     2U
#define SCB_AIRCR_SYSRESETREQ_Msk     (1UL << SCB_AIRCR_SYSRESETREQ_Pos)

#define SCB_AIRCR_PRIGROUP_Pos        8U
#define SCB_AIRCR_PRIGROUP_Msk        (7UL << SCB_AIRCR_PRIGROUP_Pos)

#define SCB_AIRCR_ENDIANNESS_Pos      15U
#define SCB_AIRCR_ENDIANNESS_Msk      (1UL << SCB_AIRCR_ENDIANNESS_Pos)

#define SCB_AIRCR_VECTKEY_Pos         16U
#define SCB_AIRCR_VECTKEY_Msk         (0xFFFFUL << SCB_AIRCR_VECTKEY_Pos)

#define SCB_AIRCR_VECTKEYSTAT_Pos     16U
#define SCB_AIRCR_VECTKEYSTAT_Msk     (0xFFFFUL << SCB_AIRCR_VECTKEYSTAT_Pos)

#define SCB_AIRCR_VECTKEY_VALUE       0x05FAUL

/*
 * ============================================================================
 * System Control Register (SCR)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-19 (page 4-19)
 * Address: 0xE000ED10
 * ============================================================================
 */

#define SCB_SCR                       (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x010))

/* SCR bit definitions - Reference: Table 4-19 (page 4-19) */
#define SCB_SCR_SLEEPONEXIT_Pos       1U
#define SCB_SCR_SLEEPONEXIT_Msk       (1UL << SCB_SCR_SLEEPONEXIT_Pos)

#define SCB_SCR_SLEEPDEEP_Pos         2U
#define SCB_SCR_SLEEPDEEP_Msk         (1UL << SCB_SCR_SLEEPDEEP_Pos)

#define SCB_SCR_SEVONPEND_Pos         4U
#define SCB_SCR_SEVONPEND_Msk         (1UL << SCB_SCR_SEVONPEND_Pos)

/*
 * ============================================================================
 * Configuration and Control Register (CCR)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-20 (page 4-20)
 * Address: 0xE000ED14
 * ============================================================================
 */

#define SCB_CCR                       (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x014))

/* CCR bit definitions - Reference: Table 4-20 (page 4-20) */
#define SCB_CCR_NONBASETHRDENA_Pos    0U
#define SCB_CCR_NONBASETHRDENA_Msk    (1UL << SCB_CCR_NONBASETHRDENA_Pos)

#define SCB_CCR_USERSETMPEND_Pos      1U
#define SCB_CCR_USERSETMPEND_Msk      (1UL << SCB_CCR_USERSETMPEND_Pos)

#define SCB_CCR_UNALIGN_TRP_Pos       3U
#define SCB_CCR_UNALIGN_TRP_Msk       (1UL << SCB_CCR_UNALIGN_TRP_Pos)

#define SCB_CCR_DIV_0_TRP_Pos         4U
#define SCB_CCR_DIV_0_TRP_Msk         (1UL << SCB_CCR_DIV_0_TRP_Pos)

#define SCB_CCR_BFHFNMIGN_Pos         8U
#define SCB_CCR_BFHFNMIGN_Msk         (1UL << SCB_CCR_BFHFNMIGN_Pos)

#define SCB_CCR_STKALIGN_Pos          9U
#define SCB_CCR_STKALIGN_Msk          (1UL << SCB_CCR_STKALIGN_Pos)

/*
 * ============================================================================
 * System Handler Priority Registers (SHPR1-SHPR3)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-21, 4-22, 4-23 (page 4-21, 4-22)
 * Address: 0xE000ED18-0xE000ED23
 * ============================================================================
 */

#define SCB_SHPR1                     (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x018))
#define SCB_SHPR2                     (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x01C))
#define SCB_SHPR3                     (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x020))

/* SHPR1 bit definitions - Reference: Table 4-21 (page 4-21) */
#define SCB_SHPR1_PRI_4_Pos           0U
#define SCB_SHPR1_PRI_4_Msk           (0xFFUL << SCB_SHPR1_PRI_4_Pos)

#define SCB_SHPR1_PRI_5_Pos           8U
#define SCB_SHPR1_PRI_5_Msk           (0xFFUL << SCB_SHPR1_PRI_5_Pos)

#define SCB_SHPR1_PRI_6_Pos           16U
#define SCB_SHPR1_PRI_6_Msk           (0xFFUL << SCB_SHPR1_PRI_6_Pos)

/* SHPR2 bit definitions - Reference: Table 4-22 (page 4-22) */
#define SCB_SHPR2_PRI_11_Pos          24U
#define SCB_SHPR2_PRI_11_Msk          (0xFFUL << SCB_SHPR2_PRI_11_Pos)

/* SHPR3 bit definitions - Reference: Table 4-23 (page 4-22) */
#define SCB_SHPR3_PRI_14_Pos          16U
#define SCB_SHPR3_PRI_14_Msk          (0xFFUL << SCB_SHPR3_PRI_14_Pos)

#define SCB_SHPR3_PRI_15_Pos          24U
#define SCB_SHPR3_PRI_15_Msk          (0xFFUL << SCB_SHPR3_PRI_15_Pos)

/*
 * ============================================================================
 * System Handler Control and State Register (SHCSR)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-24 (page 4-23)
 * Address: 0xE000ED24
 * ============================================================================
 */

#define SCB_SHCSR                     (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x024))

/* SHCSR bit definitions - Reference: Table 4-24 (page 4-23) */
#define SCB_SHCSR_MEMFAULTACT_Pos     0U
#define SCB_SHCSR_MEMFAULTACT_Msk     (1UL << SCB_SHCSR_MEMFAULTACT_Pos)

#define SCB_SHCSR_BUSFAULTACT_Pos     1U
#define SCB_SHCSR_BUSFAULTACT_Msk     (1UL << SCB_SHCSR_BUSFAULTACT_Pos)

#define SCB_SHCSR_USGFAULTACT_Pos     3U
#define SCB_SHCSR_USGFAULTACT_Msk     (1UL << SCB_SHCSR_USGFAULTACT_Pos)

#define SCB_SHCSR_SVCALLACT_Pos       7U
#define SCB_SHCSR_SVCALLACT_Msk       (1UL << SCB_SHCSR_SVCALLACT_Pos)

#define SCB_SHCSR_MONITORACT_Pos      8U
#define SCB_SHCSR_MONITORACT_Msk      (1UL << SCB_SHCSR_MONITORACT_Pos)

#define SCB_SHCSR_PENDSVACT_Pos       10U
#define SCB_SHCSR_PENDSVACT_Msk       (1UL << SCB_SHCSR_PENDSVACT_Pos)

#define SCB_SHCSR_SYSTICKACT_Pos      11U
#define SCB_SHCSR_SYSTICKACT_Msk      (1UL << SCB_SHCSR_SYSTICKACT_Pos)

#define SCB_SHCSR_USGFAULTPENDED_Pos  12U
#define SCB_SHCSR_USGFAULTPENDED_Msk  (1UL << SCB_SHCSR_USGFAULTPENDED_Pos)

#define SCB_SHCSR_MEMFAULTPENDED_Pos  13U
#define SCB_SHCSR_MEMFAULTPENDED_Msk  (1UL << SCB_SHCSR_MEMFAULTPENDED_Pos)

#define SCB_SHCSR_BUSFAULTPENDED_Pos  14U
#define SCB_SHCSR_BUSFAULTPENDED_Msk  (1UL << SCB_SHCSR_BUSFAULTPENDED_Pos)

#define SCB_SHCSR_SVCALLPENDED_Pos    15U
#define SCB_SHCSR_SVCALLPENDED_Msk    (1UL << SCB_SHCSR_SVCALLPENDED_Pos)

#define SCB_SHCSR_MEMFAULTENA_Pos     16U
#define SCB_SHCSR_MEMFAULTENA_Msk     (1UL << SCB_SHCSR_MEMFAULTENA_Pos)

#define SCB_SHCSR_BUSFAULTENA_Pos     17U
#define SCB_SHCSR_BUSFAULTENA_Msk     (1UL << SCB_SHCSR_BUSFAULTENA_Pos)

#define SCB_SHCSR_USGFAULTENA_Pos     18U
#define SCB_SHCSR_USGFAULTENA_Msk     (1UL << SCB_SHCSR_USGFAULTENA_Pos)

/*
 * ============================================================================
 * Configurable Fault Status Register (CFSR)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.10 (page 4-24)
 * Address: 0xE000ED28
 * ============================================================================
 */

#define SCB_CFSR                      (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x028))

/* CFSR subregisters */
#define SCB_MMFSR                     (*(volatile uint8_t *)(CM4_SCB_BASE_ADDR + 0x028))
#define SCB_BFSR                      (*(volatile uint8_t *)(CM4_SCB_BASE_ADDR + 0x029))
#define SCB_UFSR                      (*(volatile uint16_t *)(CM4_SCB_BASE_ADDR + 0x02A))

/* MMFSR bit definitions - Reference: Table 4-25 (page 4-25) */
#define SCB_MMFSR_IACCVIOL_Pos        0U
#define SCB_MMFSR_IACCVIOL_Msk        (1UL << SCB_MMFSR_IACCVIOL_Pos)

#define SCB_MMFSR_DACCVIOL_Pos        1U
#define SCB_MMFSR_DACCVIOL_Msk        (1UL << SCB_MMFSR_DACCVIOL_Pos)

#define SCB_MMFSR_MUNSTKERR_Pos       3U
#define SCB_MMFSR_MUNSTKERR_Msk       (1UL << SCB_MMFSR_MUNSTKERR_Pos)

#define SCB_MMFSR_MSTKERR_Pos         4U
#define SCB_MMFSR_MSTKERR_Msk         (1UL << SCB_MMFSR_MSTKERR_Pos)

#define SCB_MMFSR_MLSPERR_Pos         5U
#define SCB_MMFSR_MLSPERR_Msk         (1UL << SCB_MMFSR_MLSPERR_Pos)

#define SCB_MMFSR_MMARVALID_Pos       7U
#define SCB_MMFSR_MMARVALID_Msk       (1UL << SCB_MMFSR_MMARVALID_Pos)

/* BFSR bit definitions - Reference: Table 4-26 (page 4-26) */
#define SCB_BFSR_IBUSERR_Pos          0U
#define SCB_BFSR_IBUSERR_Msk          (1UL << SCB_BFSR_IBUSERR_Pos)

#define SCB_BFSR_PRECISERR_Pos        1U
#define SCB_BFSR_PRECISERR_Msk        (1UL << SCB_BFSR_PRECISERR_Pos)

#define SCB_BFSR_IMPRECISERR_Pos      2U
#define SCB_BFSR_IMPRECISERR_Msk      (1UL << SCB_BFSR_IMPRECISERR_Pos)

#define SCB_BFSR_UNSTKERR_Pos         3U
#define SCB_BFSR_UNSTKERR_Msk         (1UL << SCB_BFSR_UNSTKERR_Pos)

#define SCB_BFSR_STKERR_Pos           4U
#define SCB_BFSR_STKERR_Msk           (1UL << SCB_BFSR_STKERR_Pos)

#define SCB_BFSR_LSPERR_Pos           5U
#define SCB_BFSR_LSPERR_Msk           (1UL << SCB_BFSR_LSPERR_Pos)

#define SCB_BFSR_BFARVALID_Pos        7U
#define SCB_BFSR_BFARVALID_Msk        (1UL << SCB_BFSR_BFARVALID_Pos)

/* UFSR bit definitions - Reference: Table 4-27 (page 4-28) */
#define SCB_UFSR_UNDEFINSTR_Pos       0U
#define SCB_UFSR_UNDEFINSTR_Msk       (1UL << SCB_UFSR_UNDEFINSTR_Pos)

#define SCB_UFSR_INVSTATE_Pos         1U
#define SCB_UFSR_INVSTATE_Msk         (1UL << SCB_UFSR_INVSTATE_Pos)

#define SCB_UFSR_INVPC_Pos            2U
#define SCB_UFSR_INVPC_Msk            (1UL << SCB_UFSR_INVPC_Pos)

#define SCB_UFSR_NOCP_Pos             3U
#define SCB_UFSR_NOCP_Msk             (1UL << SCB_UFSR_NOCP_Pos)

#define SCB_UFSR_UNALIGNED_Pos        8U
#define SCB_UFSR_UNALIGNED_Msk        (1UL << SCB_UFSR_UNALIGNED_Pos)

#define SCB_UFSR_DIVBYZERO_Pos        9U
#define SCB_UFSR_DIVBYZERO_Msk        (1UL << SCB_UFSR_DIVBYZERO_Pos)

/*
 * ============================================================================
 * HardFault Status Register (HFSR)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-28 (page 4-30)
 * Address: 0xE000ED2C
 * ============================================================================
 */

#define SCB_HFSR                      (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x02C))

/* HFSR bit definitions - Reference: Table 4-28 (page 4-30) */
#define SCB_HFSR_VECTTBL_Pos          1U
#define SCB_HFSR_VECTTBL_Msk          (1UL << SCB_HFSR_VECTTBL_Pos)

#define SCB_HFSR_FORCED_Pos           30U
#define SCB_HFSR_FORCED_Msk           (1UL << SCB_HFSR_FORCED_Pos)

#define SCB_HFSR_DEBUGEVT_Pos         31U
#define SCB_HFSR_DEBUGEVT_Msk         (1UL << SCB_HFSR_DEBUGEVT_Pos)

/*
 * ============================================================================
 * Debug Fault Status Register (DFSR)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (for debug)
 * Address: 0xE000ED30
 * ============================================================================
 */

#define SCB_DFSR                      (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x030))

/*
 * ============================================================================
 * MemManage Fault Address Register (MMFAR)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-29 (page 4-30)
 * Address: 0xE000ED34
 * ============================================================================
 */

#define SCB_MMFAR                     (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x034))

/*
 * ============================================================================
 * BusFault Address Register (BFAR)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-30 (page 4-30)
 * Address: 0xE000ED38
 * ============================================================================
 */

#define SCB_BFAR                      (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x038))

/*
 * ============================================================================
 * Auxiliary Fault Status Register (AFSR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 4-4 (page 4-55)
 * Address: 0xE000ED3C
 * ============================================================================
 */

#define SCB_AFSR                      (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x03C))

/* AFSR bit definitions - Reference: Table 4-4 (page 4-55) */
#define SCB_AFSR_AUXFAULT_Pos         0U
#define SCB_AFSR_AUXFAULT_Msk         (0xFFFFFFFFUL << SCB_AFSR_AUXFAULT_Pos)

/*
 * ============================================================================
 * Processor Feature Register 0 (ID_PFR0)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 4-1 (page 4-51)
 * Address: 0xE000ED40
 * ============================================================================
 */

#define SCB_ID_PFR0                   (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x040))

/* ID_PFR0 reset value - Reference: Table 4-1 (page 4-51) */
#define SCB_ID_PFR0_RESET_VALUE       0x00000030UL

/*
 * ============================================================================
 * Processor Feature Register 1 (ID_PFR1)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 4-1 (page 4-51)
 * Address: 0xE000ED44
 * ============================================================================
 */

#define SCB_ID_PFR1                   (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x044))

/* ID_PFR1 reset value - Reference: Table 4-1 (page 4-51) */
#define SCB_ID_PFR1_RESET_VALUE       0x00000200UL

/*
 * ============================================================================
 * Debug Features Register 0 (ID_DFR0)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 4-1 (page 4-51)
 * Address: 0xE000ED48
 * ============================================================================
 */

#define SCB_ID_DFR0                   (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x048))

/* ID_DFR0 reset value - Reference: Table 4-1 (page 4-51) */
#define SCB_ID_DFR0_RESET_VALUE       0x00100000UL

/*
 * ============================================================================
 * Auxiliary Features Register 0 (ID_AFR0)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 4-1 (page 4-51)
 * Address: 0xE000ED4C
 * ============================================================================
 */

#define SCB_ID_AFR0                   (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x04C))

/* ID_AFR0 reset value - Reference: Table 4-1 (page 4-51) */
#define SCB_ID_AFR0_RESET_VALUE       0x00000000UL

/*
 * ============================================================================
 * Memory Model Feature Register 0 (ID_MMFR0)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 4-1 (page 4-51)
 * Address: 0xE000ED50
 * ============================================================================
 */

#define SCB_ID_MMFR0                  (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x050))

/* ID_MMFR0 reset value - Reference: Table 4-1 (page 4-51) */
#define SCB_ID_MMFR0_RESET_VALUE      0x00100030UL

/*
 * ============================================================================
 * Memory Model Feature Register 1 (ID_MMFR1)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 4-1 (page 4-51)
 * Address: 0xE000ED54
 * ============================================================================
 */

#define SCB_ID_MMFR1                  (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x054))

/* ID_MMFR1 reset value - Reference: Table 4-1 (page 4-51) */
#define SCB_ID_MMFR1_RESET_VALUE      0x00000000UL

/*
 * ============================================================================
 * Memory Model Feature Register 2 (ID_MMFR2)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 4-1 (page 4-51)
 * Address: 0xE000ED58
 * ============================================================================
 */

#define SCB_ID_MMFR2                  (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x058))

/* ID_MMFR2 reset value - Reference: Table 4-1 (page 4-51) */
#define SCB_ID_MMFR2_RESET_VALUE      0x01000000UL

/*
 * ============================================================================
 * Memory Model Feature Register 3 (ID_MMFR3)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 4-1 (page 4-51)
 * Address: 0xE000ED5C
 * ============================================================================
 */

#define SCB_ID_MMFR3                  (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x05C))

/* ID_MMFR3 reset value - Reference: Table 4-1 (page 4-51) */
#define SCB_ID_MMFR3_RESET_VALUE      0x00000000UL

/*
 * ============================================================================
 * Instruction Set Attributes Register 0 (ID_ISAR0)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 4-1 (page 4-51)
 * Address: 0xE000ED60
 * ============================================================================
 */

#define SCB_ID_ISAR0                  (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x060))

/* ID_ISAR0 reset value - Reference: Table 4-1 (page 4-51) */
#define SCB_ID_ISAR0_RESET_VALUE      0x01141110UL

/*
 * ============================================================================
 * Instruction Set Attributes Register 1 (ID_ISAR1)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 4-1 (page 4-51)
 * Address: 0xE000ED64
 * ============================================================================
 */

#define SCB_ID_ISAR1                  (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x064))

/* ID_ISAR1 reset value - Reference: Table 4-1 (page 4-51) */
#define SCB_ID_ISAR1_RESET_VALUE      0x02112000UL

/*
 * ============================================================================
 * Instruction Set Attributes Register 2 (ID_ISAR2)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 4-1 (page 4-51)
 * Address: 0xE000ED68
 * ============================================================================
 */

#define SCB_ID_ISAR2                  (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x068))

/* ID_ISAR2 reset value - Reference: Table 4-1 (page 4-51) */
#define SCB_ID_ISAR2_RESET_VALUE      0x21232231UL

/*
 * ============================================================================
 * Instruction Set Attributes Register 3 (ID_ISAR3)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 4-1 (page 4-51)
 * Address: 0xE000ED6C
 * ============================================================================
 */

#define SCB_ID_ISAR3                  (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x06C))

/* ID_ISAR3 reset value - Reference: Table 4-1 (page 4-51) */
#define SCB_ID_ISAR3_RESET_VALUE      0x01111131UL

/*
 * ============================================================================
 * Instruction Set Attributes Register 4 (ID_ISAR4)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 4-1 (page 4-51)
 * Address: 0xE000ED70
 * ============================================================================
 */

#define SCB_ID_ISAR4                  (*(volatile uint32_t *)(CM4_SCB_BASE_ADDR + 0x070))

/* ID_ISAR4 reset value - Reference: Table 4-1 (page 4-51) */
#define SCB_ID_ISAR4_RESET_VALUE      0x01310132UL

/*
 * ============================================================================
 * Coprocessor Access Control Register (CPACR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 4-1 (page 4-51)
 * Address: 0xE000ED88
 * ============================================================================
 */

#define SCB_CPACR                     (*(volatile uint32_t *)(0xE000ED88UL))

/* CPACR bit definitions */
#define SCB_CPACR_CP10_Pos            20U
#define SCB_CPACR_CP10_Msk            (3UL << SCB_CPACR_CP10_Pos)

#define SCB_CPACR_CP11_Pos            22U
#define SCB_CPACR_CP11_Msk            (3UL << SCB_CPACR_CP11_Pos)

/* CPACR access values */
#define SCB_CPACR_CP_ACCESS_DENIED    0x0UL
#define SCB_CPACR_CP_PRIV_ACCESS      0x1UL
#define SCB_CPACR_CP_FULL_ACCESS      0x3UL

/*
 * ============================================================================
 * SCB Function Declarations
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3 (page 4-10)
 * ============================================================================
 */

/**
 * @brief Set vector table offset
 * @param offset Vector table offset address (must be aligned to 128 bytes)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.4 (page 4-16)
 */
void cm4_scb_set_vtor(uint32_t offset);

/**
 * @brief Get vector table offset
 * @return Vector table offset address
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.4 (page 4-16)
 */
uint32_t cm4_scb_get_vtor(void);

/**
 * @brief System reset request
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.5 (page 4-17)
 */
void cm4_scb_system_reset(void);

/**
 * @brief Set priority grouping
 * @param group Priority grouping value (0-7)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.5 (page 4-17)
 */
void cm4_scb_set_priority_grouping(uint32_t group);

/**
 * @brief Get priority grouping
 * @return Priority grouping value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.5 (page 4-17)
 */
uint32_t cm4_scb_get_priority_grouping(void);

/**
 * @brief Enable MemManage fault
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.9 (page 4-23)
 */
void cm4_scb_enable_memfault(void);

/**
 * @brief Enable BusFault
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.9 (page 4-23)
 */
void cm4_scb_enable_busfault(void);

/**
 * @brief Enable UsageFault
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.9 (page 4-23)
 */
void cm4_scb_enable_usagefault(void);

/**
 * @brief Get CPUID
 * @return CPUID register value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.2 (page 4-13)
 */
uint32_t cm4_scb_get_cpuid(void);

#ifdef __cplusplus
}
#endif

#endif /* __CM4_SCB_H__ */
