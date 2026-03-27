/*
 * arm_v7m_cm7_scb.h
 * Cortex-M7 System Control Block (SCB) Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2
 *            - System Control Block (SCB) registers on page B3-597
 *            - Section B3.2.2: CPUID Base Register, CPUID on page B3-598
 *            - Section B3.2.3: Interrupt Control and State Register, ICSR on page B3-599
 *            - Section B3.2.4: Vector Table Offset Register, VTOR on page B3-601
 *            - Section B3.2.5: Application Interrupt and Reset Control Register, AIRCR on page B3-601
 *            - Section B3.2.6: System Control Register, SCR on page B3-603
 *            - Section B3.2.7: Configuration and Control Register, CCR on page B3-604
 *            - Section B3.2.8: System Handler Priority Registers, SHPR on page B3-605
 *            - Section B3.2.9: System Handler Control and State Register, SHCSR on page B3-607
 *            - Section B3.2.10: Configurable Fault Status Register, CFSR on page B3-609
 *            - Section B3.2.11: HardFault Status Register, HFSR on page B3-612
 *            - Section B3.2.12: MemManage Fault Address Register, MMFAR on page B3-613
 *            - Section B3.2.13: BusFault Address Register, BFAR on page B3-614
 *            - Section B3.2.14: Auxiliary Fault Status Register, AFSR on page B3-614
 *            - Section B3.2.15: Coprocessor Access Control Register, CPACR on page B3-614
 *            Cortex-M7 Devices Generic User Guide, Chapter 4.3
 *            - System control block on page 4-11
 *            - Section 4.3.1: Auxiliary Control Register on page 4-11
 *            - Section 4.3.2: CPUID Base Register on page 4-13
 *            - Section 4.3.3: Interrupt Control and State Register on page 4-14
 *            - Section 4.3.4: Vector Table Offset Register on page 4-17
 *            - Section 4.3.5: Application Interrupt and Reset Control Register on page 4-17
 *            - Section 4.3.6: System Control Register on page 4-20
 *            - Section 4.3.7: Configuration and Control Register on page 4-20
 *            - Section 4.3.8: System Handler Priority Registers on page 4-23
 *            - Section 4.3.9: System Handler Control and State Register on page 4-24
 *            - Section 4.3.10: Configurable Fault Status Register on page 4-25
 *            - Section 4.3.11: HardFault Status Register on page 4-31
 *            - Section 4.3.12: MemManage Fault Address Register on page 4-31
 *            - Section 4.3.13: BusFault Address Register on page 4-32
 *            - Section 4.7.1: Coprocessor Access Control Register on page 4-55
 *            Cortex-M7 Technical Reference Manual, Chapter 3
 *            - System Control on page 3-1
 *            - Section 3.1: About system control on page 3-2
 *            - Section 3.2: Register summary on page 3-3
 *            - Section 3.3: Register descriptions on page 3-6
 *
 * @note This file reuses Armv7-M generic SCB definitions.
 */

#ifndef ARM_V7M_CM7_SCB_H
#define ARM_V7M_CM7_SCB_H

#include <stdint.h>
#include "../arm_v7m_scb.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Compiler Abstraction - Inline Definition
 *============================================================================*/

#if defined(__clang__)
    #define ARM_V7M_CM7_SCB_INLINE static inline __attribute__((always_inline))
#else
    #error "This library requires Clang/LLVM compiler."
#endif

/*============================================================================*
 * Type Aliases
 *============================================================================*/

typedef arm_v7m_scb_regs_t      arm_v7m_cm7_scb_regs_t;

/*============================================================================*
 * Constant Aliases - SCB Register Bit Definitions
 *============================================================================*/

/* CPUID Register */
#define ARM_V7M_CM7_SCB_CPUID_IMPLEMENTER_Pos     SCB_CPUID_IMPLEMENTER_Pos
#define ARM_V7M_CM7_SCB_CPUID_IMPLEMENTER_Msk     SCB_CPUID_IMPLEMENTER_Msk
#define ARM_V7M_CM7_SCB_CPUID_VARIANT_Pos         SCB_CPUID_VARIANT_Pos
#define ARM_V7M_CM7_SCB_CPUID_VARIANT_Msk         SCB_CPUID_VARIANT_Msk
#define ARM_V7M_CM7_SCB_CPUID_ARCHITECTURE_Pos    SCB_CPUID_ARCHITECTURE_Pos
#define ARM_V7M_CM7_SCB_CPUID_ARCHITECTURE_Msk    SCB_CPUID_ARCHITECTURE_Msk
#define ARM_V7M_CM7_SCB_CPUID_PARTNO_Pos          SCB_CPUID_PARTNO_Pos
#define ARM_V7M_CM7_SCB_CPUID_PARTNO_Msk          SCB_CPUID_PARTNO_Msk
#define ARM_V7M_CM7_SCB_CPUID_REVISION_Pos        SCB_CPUID_REVISION_Pos
#define ARM_V7M_CM7_SCB_CPUID_REVISION_Msk        SCB_CPUID_REVISION_Msk

/* ICSR Register */
#define ARM_V7M_CM7_SCB_ICSR_NMIPENDSET_Pos       SCB_ICSR_NMIPENDSET_Pos
#define ARM_V7M_CM7_SCB_ICSR_NMIPENDSET_Msk       SCB_ICSR_NMIPENDSET_Msk
#define ARM_V7M_CM7_SCB_ICSR_PENDSVSET_Pos        SCB_ICSR_PENDSVSET_Pos
#define ARM_V7M_CM7_SCB_ICSR_PENDSVSET_Msk        SCB_ICSR_PENDSVSET_Msk
#define ARM_V7M_CM7_SCB_ICSR_PENDSVCLR_Pos        SCB_ICSR_PENDSVCLR_Pos
#define ARM_V7M_CM7_SCB_ICSR_PENDSVCLR_Msk        SCB_ICSR_PENDSVCLR_Msk
#define ARM_V7M_CM7_SCB_ICSR_PENDSTSET_Pos        SCB_ICSR_PENDSTSET_Pos
#define ARM_V7M_CM7_SCB_ICSR_PENDSTSET_Msk        SCB_ICSR_PENDSTSET_Msk
#define ARM_V7M_CM7_SCB_ICSR_PENDSTCLR_Pos        SCB_ICSR_PENDSTCLR_Pos
#define ARM_V7M_CM7_SCB_ICSR_PENDSTCLR_Msk        SCB_ICSR_PENDSTCLR_Msk
#define ARM_V7M_CM7_SCB_ICSR_ISRPREEMPT_Pos       SCB_ICSR_ISRPREEMPT_Pos
#define ARM_V7M_CM7_SCB_ICSR_ISRPREEMPT_Msk       SCB_ICSR_ISRPREEMPT_Msk
#define ARM_V7M_CM7_SCB_ICSR_ISRPENDING_Pos       SCB_ICSR_ISRPENDING_Pos
#define ARM_V7M_CM7_SCB_ICSR_ISRPENDING_Msk       SCB_ICSR_ISRPENDING_Msk
#define ARM_V7M_CM7_SCB_ICSR_VECTPENDING_Pos      SCB_ICSR_VECTPENDING_Pos
#define ARM_V7M_CM7_SCB_ICSR_VECTPENDING_Msk      SCB_ICSR_VECTPENDING_Msk
#define ARM_V7M_CM7_SCB_ICSR_RETTOBASE_Pos        SCB_ICSR_RETTOBASE_Pos
#define ARM_V7M_CM7_SCB_ICSR_RETTOBASE_Msk        SCB_ICSR_RETTOBASE_Msk
#define ARM_V7M_CM7_SCB_ICSR_VECTACTIVE_Pos       SCB_ICSR_VECTACTIVE_Pos
#define ARM_V7M_CM7_SCB_ICSR_VECTACTIVE_Msk       SCB_ICSR_VECTACTIVE_Msk

/* VTOR Register */
#define ARM_V7M_CM7_SCB_VTOR_TBLOFF_Pos           SCB_VTOR_TBLOFF_Pos
#define ARM_V7M_CM7_SCB_VTOR_TBLOFF_Msk           SCB_VTOR_TBLOFF_Msk

/* AIRCR Register */
#define ARM_V7M_CM7_SCB_AIRCR_VECTKEY_Pos         SCB_AIRCR_VECTKEY_Pos
#define ARM_V7M_CM7_SCB_AIRCR_VECTKEY_Msk         SCB_AIRCR_VECTKEY_Msk
#define ARM_V7M_CM7_SCB_AIRCR_VECTKEYSTAT_Pos     SCB_AIRCR_VECTKEYSTAT_Pos
#define ARM_V7M_CM7_SCB_AIRCR_VECTKEYSTAT_Msk     SCB_AIRCR_VECTKEYSTAT_Msk
#define ARM_V7M_CM7_SCB_AIRCR_ENDIANESS_Pos       SCB_AIRCR_ENDIANESS_Pos
#define ARM_V7M_CM7_SCB_AIRCR_ENDIANESS_Msk       SCB_AIRCR_ENDIANESS_Msk
#define ARM_V7M_CM7_SCB_AIRCR_PRIGROUP_Pos        SCB_AIRCR_PRIGROUP_Pos
#define ARM_V7M_CM7_SCB_AIRCR_PRIGROUP_Msk        SCB_AIRCR_PRIGROUP_Msk
#define ARM_V7M_CM7_SCB_AIRCR_SYSRESETREQ_Pos     SCB_AIRCR_SYSRESETREQ_Pos
#define ARM_V7M_CM7_SCB_AIRCR_SYSRESETREQ_Msk     SCB_AIRCR_SYSRESETREQ_Msk
#define ARM_V7M_CM7_SCB_AIRCR_VECTCLRACTIVE_Pos   SCB_AIRCR_VECTCLRACTIVE_Pos
#define ARM_V7M_CM7_SCB_AIRCR_VECTCLRACTIVE_Msk   SCB_AIRCR_VECTCLRACTIVE_Msk
#define ARM_V7M_CM7_SCB_AIRCR_VECTRESET_Pos       SCB_AIRCR_VECTRESET_Pos
#define ARM_V7M_CM7_SCB_AIRCR_VECTRESET_Msk       SCB_AIRCR_VECTRESET_Msk

#define ARM_V7M_CM7_SCB_AIRCR_VECTKEY_VALUE       SCB_AIRCR_VECTKEY_VALUE

/* Priority Grouping */
#define ARM_V7M_CM7_SCB_PRIORITYGROUP_0           SCB_PRIORITYGROUP_0
#define ARM_V7M_CM7_SCB_PRIORITYGROUP_1           SCB_PRIORITYGROUP_1
#define ARM_V7M_CM7_SCB_PRIORITYGROUP_2           SCB_PRIORITYGROUP_2
#define ARM_V7M_CM7_SCB_PRIORITYGROUP_3           SCB_PRIORITYGROUP_3
#define ARM_V7M_CM7_SCB_PRIORITYGROUP_4           SCB_PRIORITYGROUP_4
#define ARM_V7M_CM7_SCB_PRIORITYGROUP_5           SCB_PRIORITYGROUP_5
#define ARM_V7M_CM7_SCB_PRIORITYGROUP_6           SCB_PRIORITYGROUP_6
#define ARM_V7M_CM7_SCB_PRIORITYGROUP_7           SCB_PRIORITYGROUP_7

/* SCR Register */
#define ARM_V7M_CM7_SCB_SCR_SEVONPEND_Pos         SCB_SCR_SEVONPEND_Pos
#define ARM_V7M_CM7_SCB_SCR_SEVONPEND_Msk         SCB_SCR_SEVONPEND_Msk
#define ARM_V7M_CM7_SCB_SCR_SLEEPDEEP_Pos         SCB_SCR_SLEEPDEEP_Pos
#define ARM_V7M_CM7_SCB_SCR_SLEEPDEEP_Msk         SCB_SCR_SLEEPDEEP_Msk
#define ARM_V7M_CM7_SCB_SCR_SLEEPONEXIT_Pos       SCB_SCR_SLEEPONEXIT_Pos
#define ARM_V7M_CM7_SCB_SCR_SLEEPONEXIT_Msk       SCB_SCR_SLEEPONEXIT_Msk

/* CCR Register */
#define ARM_V7M_CM7_SCB_CCR_STKALIGN_Pos          SCB_CCR_STKALIGN_Pos
#define ARM_V7M_CM7_SCB_CCR_STKALIGN_Msk          SCB_CCR_STKALIGN_Msk
#define ARM_V7M_CM7_SCB_CCR_BFHFNMIGN_Pos         SCB_CCR_BFHFNMIGN_Pos
#define ARM_V7M_CM7_SCB_CCR_BFHFNMIGN_Msk         SCB_CCR_BFHFNMIGN_Msk
#define ARM_V7M_CM7_SCB_CCR_DIV_0_TRP_Pos         SCB_CCR_DIV_0_TRP_Pos
#define ARM_V7M_CM7_SCB_CCR_DIV_0_TRP_Msk         SCB_CCR_DIV_0_TRP_Msk
#define ARM_V7M_CM7_SCB_CCR_UNALIGN_TRP_Pos       SCB_CCR_UNALIGN_TRP_Pos
#define ARM_V7M_CM7_SCB_CCR_UNALIGN_TRP_Msk       SCB_CCR_UNALIGN_TRP_Msk
#define ARM_V7M_CM7_SCB_CCR_USERSETMPEND_Pos      SCB_CCR_USERSETMPEND_Pos
#define ARM_V7M_CM7_SCB_CCR_USERSETMPEND_Msk      SCB_CCR_USERSETMPEND_Msk
#define ARM_V7M_CM7_SCB_CCR_NONBASETHRDENA_Pos    SCB_CCR_NONBASETHRDENA_Pos
#define ARM_V7M_CM7_SCB_CCR_NONBASETHRDENA_Msk    SCB_CCR_NONBASETHRDENA_Msk

/* SHCSR Register */
#define ARM_V7M_CM7_SCB_SHCSR_USGFAULTENA_Pos     SCB_SHCSR_USGFAULTENA_Pos
#define ARM_V7M_CM7_SCB_SHCSR_USGFAULTENA_Msk     SCB_SHCSR_USGFAULTENA_Msk
#define ARM_V7M_CM7_SCB_SHCSR_BUSFAULTENA_Pos     SCB_SHCSR_BUSFAULTENA_Pos
#define ARM_V7M_CM7_SCB_SHCSR_BUSFAULTENA_Msk     SCB_SHCSR_BUSFAULTENA_Msk
#define ARM_V7M_CM7_SCB_SHCSR_MEMFAULTENA_Pos     SCB_SHCSR_MEMFAULTENA_Pos
#define ARM_V7M_CM7_SCB_SHCSR_MEMFAULTENA_Msk     SCB_SHCSR_MEMFAULTENA_Msk
#define ARM_V7M_CM7_SCB_SHCSR_SVCALLPENDED_Pos    SCB_SHCSR_SVCALLPENDED_Pos
#define ARM_V7M_CM7_SCB_SHCSR_SVCALLPENDED_Msk    SCB_SHCSR_SVCALLPENDED_Msk
#define ARM_V7M_CM7_SCB_SHCSR_BUSFAULTPENDED_Pos  SCB_SHCSR_BUSFAULTPENDED_Pos
#define ARM_V7M_CM7_SCB_SHCSR_BUSFAULTPENDED_Msk  SCB_SHCSR_BUSFAULTPENDED_Msk
#define ARM_V7M_CM7_SCB_SHCSR_MEMFAULTPENDED_Pos  SCB_SHCSR_MEMFAULTPENDED_Pos
#define ARM_V7M_CM7_SCB_SHCSR_MEMFAULTPENDED_Msk  SCB_SHCSR_MEMFAULTPENDED_Msk
#define ARM_V7M_CM7_SCB_SHCSR_USGFAULTPENDED_Pos  SCB_SHCSR_USGFAULTPENDED_Pos
#define ARM_V7M_CM7_SCB_SHCSR_USGFAULTPENDED_Msk  SCB_SHCSR_USGFAULTPENDED_Msk
#define ARM_V7M_CM7_SCB_SHCSR_SYSTICKACT_Pos      SCB_SHCSR_SYSTICKACT_Pos
#define ARM_V7M_CM7_SCB_SHCSR_SYSTICKACT_Msk      SCB_SHCSR_SYSTICKACT_Msk
#define ARM_V7M_CM7_SCB_SHCSR_PENDSVACT_Pos       SCB_SHCSR_PENDSVACT_Pos
#define ARM_V7M_CM7_SCB_SHCSR_PENDSVACT_Msk       SCB_SHCSR_PENDSVACT_Msk
#define ARM_V7M_CM7_SCB_SHCSR_MONITORACT_Pos      SCB_SHCSR_MONITORACT_Pos
#define ARM_V7M_CM7_SCB_SHCSR_MONITORACT_Msk      SCB_SHCSR_MONITORACT_Msk
#define ARM_V7M_CM7_SCB_SHCSR_SVCALLACT_Pos       SCB_SHCSR_SVCALLACT_Pos
#define ARM_V7M_CM7_SCB_SHCSR_SVCALLACT_Msk       SCB_SHCSR_SVCALLACT_Msk
#define ARM_V7M_CM7_SCB_SHCSR_USGFAULTACT_Pos     SCB_SHCSR_USGFAULTACT_Pos
#define ARM_V7M_CM7_SCB_SHCSR_USGFAULTACT_Msk     SCB_SHCSR_USGFAULTACT_Msk
#define ARM_V7M_CM7_SCB_SHCSR_BUSFAULTACT_Pos     SCB_SHCSR_BUSFAULTACT_Pos
#define ARM_V7M_CM7_SCB_SHCSR_BUSFAULTACT_Msk     SCB_SHCSR_BUSFAULTACT_Msk
#define ARM_V7M_CM7_SCB_SHCSR_MEMFAULTACT_Pos     SCB_SHCSR_MEMFAULTACT_Pos
#define ARM_V7M_CM7_SCB_SHCSR_MEMFAULTACT_Msk     SCB_SHCSR_MEMFAULTACT_Msk

/* CFSR Register */
#define ARM_V7M_CM7_SCB_CFSR_MMARVALID_Pos        SCB_CFSR_MMARVALID_Pos
#define ARM_V7M_CM7_SCB_CFSR_MMARVALID_Msk        SCB_CFSR_MMARVALID_Msk
#define ARM_V7M_CM7_SCB_CFSR_MLSPERR_Pos          SCB_CFSR_MLSPERR_Pos
#define ARM_V7M_CM7_SCB_CFSR_MLSPERR_Msk          SCB_CFSR_MLSPERR_Msk
#define ARM_V7M_CM7_SCB_CFSR_MSTKERR_Pos          SCB_CFSR_MSTKERR_Pos
#define ARM_V7M_CM7_SCB_CFSR_MSTKERR_Msk          SCB_CFSR_MSTKERR_Msk
#define ARM_V7M_CM7_SCB_CFSR_MUNSTKERR_Pos        SCB_CFSR_MUNSTKERR_Pos
#define ARM_V7M_CM7_SCB_CFSR_MUNSTKERR_Msk        SCB_CFSR_MUNSTKERR_Msk
#define ARM_V7M_CM7_SCB_CFSR_DACCVIOL_Pos         SCB_CFSR_DACCVIOL_Pos
#define ARM_V7M_CM7_SCB_CFSR_DACCVIOL_Msk         SCB_CFSR_DACCVIOL_Msk
#define ARM_V7M_CM7_SCB_CFSR_IACCVIOL_Pos         SCB_CFSR_IACCVIOL_Pos
#define ARM_V7M_CM7_SCB_CFSR_IACCVIOL_Msk         SCB_CFSR_IACCVIOL_Msk
#define ARM_V7M_CM7_SCB_CFSR_BFARVALID_Pos        SCB_CFSR_BFARVALID_Pos
#define ARM_V7M_CM7_SCB_CFSR_BFARVALID_Msk        SCB_CFSR_BFARVALID_Msk
#define ARM_V7M_CM7_SCB_CFSR_LSPERR_Pos           SCB_CFSR_LSPERR_Pos
#define ARM_V7M_CM7_SCB_CFSR_LSPERR_Msk           SCB_CFSR_LSPERR_Msk
#define ARM_V7M_CM7_SCB_CFSR_STKERR_Pos           SCB_CFSR_STKERR_Pos
#define ARM_V7M_CM7_SCB_CFSR_STKERR_Msk           SCB_CFSR_STKERR_Msk
#define ARM_V7M_CM7_SCB_CFSR_UNSTKERR_Pos         SCB_CFSR_UNSTKERR_Pos
#define ARM_V7M_CM7_SCB_CFSR_UNSTKERR_Msk         SCB_CFSR_UNSTKERR_Msk
#define ARM_V7M_CM7_SCB_CFSR_IMPRECISERR_Pos      SCB_CFSR_IMPRECISERR_Pos
#define ARM_V7M_CM7_SCB_CFSR_IMPRECISERR_Msk      SCB_CFSR_IMPRECISERR_Msk
#define ARM_V7M_CM7_SCB_CFSR_PRECISERR_Pos        SCB_CFSR_PRECISERR_Pos
#define ARM_V7M_CM7_SCB_CFSR_PRECISERR_Msk        SCB_CFSR_PRECISERR_Msk
#define ARM_V7M_CM7_SCB_CFSR_IBUSERR_Pos          SCB_CFSR_IBUSERR_Pos
#define ARM_V7M_CM7_SCB_CFSR_IBUSERR_Msk          SCB_CFSR_IBUSERR_Msk
#define ARM_V7M_CM7_SCB_CFSR_DIVBYZERO_Pos        SCB_CFSR_DIVBYZERO_Pos
#define ARM_V7M_CM7_SCB_CFSR_DIVBYZERO_Msk        SCB_CFSR_DIVBYZERO_Msk
#define ARM_V7M_CM7_SCB_CFSR_UNALIGNED_Pos        SCB_CFSR_UNALIGNED_Pos
#define ARM_V7M_CM7_SCB_CFSR_UNALIGNED_Msk        SCB_CFSR_UNALIGNED_Msk
#define ARM_V7M_CM7_SCB_CFSR_NOCP_Pos             SCB_CFSR_NOCP_Pos
#define ARM_V7M_CM7_SCB_CFSR_NOCP_Msk             SCB_CFSR_NOCP_Msk
#define ARM_V7M_CM7_SCB_CFSR_INVPC_Pos            SCB_CFSR_INVPC_Pos
#define ARM_V7M_CM7_SCB_CFSR_INVPC_Msk            SCB_CFSR_INVPC_Msk
#define ARM_V7M_CM7_SCB_CFSR_INVSTATE_Pos         SCB_CFSR_INVSTATE_Pos
#define ARM_V7M_CM7_SCB_CFSR_INVSTATE_Msk         SCB_CFSR_INVSTATE_Msk
#define ARM_V7M_CM7_SCB_CFSR_UNDEFINSTR_Pos       SCB_CFSR_UNDEFINSTR_Pos
#define ARM_V7M_CM7_SCB_CFSR_UNDEFINSTR_Msk       SCB_CFSR_UNDEFINSTR_Msk

/* HFSR Register */
#define ARM_V7M_CM7_SCB_HFSR_DEBUGEVT_Pos         SCB_HFSR_DEBUGEVT_Pos
#define ARM_V7M_CM7_SCB_HFSR_DEBUGEVT_Msk         SCB_HFSR_DEBUGEVT_Msk
#define ARM_V7M_CM7_SCB_HFSR_FORCED_Pos           SCB_HFSR_FORCED_Pos
#define ARM_V7M_CM7_SCB_HFSR_FORCED_Msk           SCB_HFSR_FORCED_Msk
#define ARM_V7M_CM7_SCB_HFSR_VECTTBL_Pos          SCB_HFSR_VECTTBL_Pos
#define ARM_V7M_CM7_SCB_HFSR_VECTTBL_Msk          SCB_HFSR_VECTTBL_Msk

/* DFSR Register */
#define ARM_V7M_CM7_SCB_DFSR_EXTERNAL_Pos         SCB_DFSR_EXTERNAL_Pos
#define ARM_V7M_CM7_SCB_DFSR_EXTERNAL_Msk         SCB_DFSR_EXTERNAL_Msk
#define ARM_V7M_CM7_SCB_DFSR_VCATCH_Pos           SCB_DFSR_VCATCH_Pos
#define ARM_V7M_CM7_SCB_DFSR_VCATCH_Msk           SCB_DFSR_VCATCH_Msk
#define ARM_V7M_CM7_SCB_DFSR_DWTTRAP_Pos          SCB_DFSR_DWTTRAP_Pos
#define ARM_V7M_CM7_SCB_DFSR_DWTTRAP_Msk          SCB_DFSR_DWTTRAP_Msk
#define ARM_V7M_CM7_SCB_DFSR_BKPT_Pos             SCB_DFSR_BKPT_Pos
#define ARM_V7M_CM7_SCB_DFSR_BKPT_Msk             SCB_DFSR_BKPT_Msk
#define ARM_V7M_CM7_SCB_DFSR_HALTED_Pos           SCB_DFSR_HALTED_Pos
#define ARM_V7M_CM7_SCB_DFSR_HALTED_Msk           SCB_DFSR_HALTED_Msk

/* CPACR Register */
#define ARM_V7M_CM7_SCB_CPACR_CP10_Pos            SCB_CPACR_CP10_Pos
#define ARM_V7M_CM7_SCB_CPACR_CP10_Msk            SCB_CPACR_CP10_Msk
#define ARM_V7M_CM7_SCB_CPACR_CP11_Pos            SCB_CPACR_CP11_Pos
#define ARM_V7M_CM7_SCB_CPACR_CP11_Msk            SCB_CPACR_CP11_Msk
#define ARM_V7M_CM7_SCB_CPACR_CP_ACCESS_DENIED    SCB_CPACR_CP_ACCESS_DENIED
#define ARM_V7M_CM7_SCB_CPACR_CP_PRIV_ACCESS      SCB_CPACR_CP_PRIV_ACCESS
#define ARM_V7M_CM7_SCB_CPACR_CP_RESERVED         SCB_CPACR_CP_RESERVED
#define ARM_V7M_CM7_SCB_CPACR_CP_FULL_ACCESS      SCB_CPACR_CP_FULL_ACCESS

/*============================================================================*
 * Inline Functions - SCB Operations (Aliased from generic)
 *============================================================================*/

/**
 * @brief Set the vector table offset
 * @param offset Vector table offset (must be aligned to 128 bytes)
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_set_vector_table(uint32_t offset)
{
    arm_v7m_scb_set_vector_table(offset);
}

/**
 * @brief Get the vector table offset
 * @return Current vector table offset
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_vector_table(void)
{
    return arm_v7m_scb_get_vector_table();
}

/**
 * @brief Get the priority grouping field
 * @return Priority grouping field (0-7)
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_priority_grouping(void)
{
    return arm_v7m_scb_get_priority_grouping();
}

/**
 * @brief Get CPUID
 * @return CPUID register value
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_cpuid(void)
{
    return arm_v7m_scb_get_cpuid();
}

/**
 * @brief Get the current active exception number
 * @return Current active exception number (0-511), 0 means Thread mode
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_active_exception(void)
{
    return arm_v7m_scb_get_active_exception();
}

/**
 * @brief Get the pending exception number
 * @return Pending exception number (0-511), 0 means no pending exception
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_pending_exception(void)
{
    return arm_v7m_scb_get_pending_exception();
}

/**
 * @brief Set the PendSV exception to pending
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_set_pendsv_pending(void)
{
    arm_v7m_scb_set_pendsv_pending();
}

/**
 * @brief Clear the PendSV exception pending status
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_clear_pendsv_pending(void)
{
    arm_v7m_scb_clear_pendsv_pending();
}

/**
 * @brief Set the SysTick exception to pending
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_set_systick_pending(void)
{
    arm_v7m_scb_set_systick_pending();
}

/**
 * @brief Clear the SysTick exception pending status
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_clear_systick_pending(void)
{
    arm_v7m_scb_clear_systick_pending();
}

/**
 * @brief Set the NMI exception to pending
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_set_nmi_pending(void)
{
    arm_v7m_scb_set_nmi_pending();
}

/**
 * @brief Check if an interrupt is pending
 * @return 1 if any interrupt is pending, 0 otherwise
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_is_interrupt_pending(void)
{
    return arm_v7m_scb_is_interrupt_pending();
}

/**
 * @brief Check if returning to base (no active exceptions)
 * @return 1 if returning to base, 0 otherwise
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_is_return_to_base(void)
{
    return arm_v7m_scb_is_return_to_base();
}

/**
 * @brief Enable fault exceptions (MemManage, BusFault, UsageFault)
 * @param fault_mask Bit mask of faults to enable
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_enable_fault_exceptions(uint32_t fault_mask)
{
    arm_v7m_scb_enable_fault_exceptions(fault_mask);
}

/**
 * @brief Disable fault exceptions
 * @param fault_mask Bit mask of faults to disable
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_disable_fault_exceptions(uint32_t fault_mask)
{
    arm_v7m_scb_disable_fault_exceptions(fault_mask);
}

/**
 * @brief Get Configurable Fault Status Register
 * @return CFSR value
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_cfsr(void)
{
    return arm_v7m_scb_get_cfsr();
}

/**
 * @brief Clear Configurable Fault Status Register
 * @param mask Bits to clear (write 1 to clear)
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_clear_cfsr(uint32_t mask)
{
    arm_v7m_scb_clear_cfsr(mask);
}

/**
 * @brief Get HardFault Status Register
 * @return HFSR value
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_hfsr(void)
{
    return arm_v7m_scb_get_hfsr();
}

/**
 * @brief Clear HardFault Status Register
 * @param mask Bits to clear (write 1 to clear)
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_clear_hfsr(uint32_t mask)
{
    arm_v7m_scb_clear_hfsr(mask);
}

/**
 * @brief Get Debug Fault Status Register
 * @return DFSR value
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_dfsr(void)
{
    return arm_v7m_scb_get_dfsr();
}

/**
 * @brief Clear Debug Fault Status Register
 * @param mask Bits to clear (write 1 to clear)
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_clear_dfsr(uint32_t mask)
{
    arm_v7m_scb_clear_dfsr(mask);
}

/**
 * @brief Get MemManage Fault Address Register
 * @return MMFAR value
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_mmfar(void)
{
    return arm_v7m_scb_get_mmfar();
}

/**
 * @brief Get BusFault Address Register
 * @return BFAR value
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_bfar(void)
{
    return arm_v7m_scb_get_bfar();
}

/**
 * @brief Get Auxiliary Fault Status Register
 * @return AFSR value
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_afsr(void)
{
    return arm_v7m_scb_get_afsr();
}

/**
 * @brief Set Auxiliary Fault Status Register
 * @param value Value to write
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_set_afsr(uint32_t value)
{
    arm_v7m_scb_set_afsr(value);
}

/**
 * @brief Get Processor Feature Register 0
 * @return ID_PFR[0] value
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_id_pfr0(void)
{
    return arm_v7m_scb_get_id_pfr0();
}

/**
 * @brief Get Processor Feature Register 1
 * @return ID_PFR[1] value
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_id_pfr1(void)
{
    return arm_v7m_scb_get_id_pfr1();
}

/**
 * @brief Get Debug Feature Register 0
 * @return ID_DFR0 value
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_id_dfr0(void)
{
    return arm_v7m_scb_get_id_dfr0();
}

/**
 * @brief Get Auxiliary Feature Register 0
 * @return ID_AFR0 value
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_id_afr0(void)
{
    return arm_v7m_scb_get_id_afr0();
}

/**
 * @brief Get Memory Model Feature Register
 * @param index Register index (0-3)
 * @return ID_MMFR[index] value
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_id_mmfr(uint32_t index)
{
    return arm_v7m_scb_get_id_mmfr(index);
}

/**
 * @brief Get Instruction Set Attribute Register
 * @param index Register index (0-4)
 * @return ID_ISAR[index] value
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_id_isar(uint32_t index)
{
    return arm_v7m_scb_get_id_isar(index);
}

/**
 * @brief Get CPACR (Coprocessor Access Control Register)
 * @return CPACR value
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_cpacr(void)
{
    return arm_v7m_scb_get_cpacr();
}

/**
 * @brief Set CPACR (Coprocessor Access Control Register)
 * @param value Value to write
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_set_cpacr(uint32_t value)
{
    arm_v7m_scb_set_cpacr(value);
}

/**
 * @brief Enable FPU (set CP10 and CP11 to full access)
 * @note Must be called before using FPU instructions
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_enable_fpu(void)
{
    arm_v7m_scb_enable_fpu();
}

/**
 * @brief Disable FPU (set CP10 and CP11 to access denied)
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_disable_fpu(void)
{
    arm_v7m_scb_disable_fpu();
}

/**
 * @brief Enable deep sleep mode
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_enable_deep_sleep(void)
{
    arm_v7m_scb_enable_deep_sleep();
}

/**
 * @brief Disable deep sleep mode
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_disable_deep_sleep(void)
{
    arm_v7m_scb_disable_deep_sleep();
}

/**
 * @brief Enable sleep-on-exit
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_enable_sleep_on_exit(void)
{
    arm_v7m_scb_enable_sleep_on_exit();
}

/**
 * @brief Disable sleep-on-exit
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_disable_sleep_on_exit(void)
{
    arm_v7m_scb_disable_sleep_on_exit();
}

/**
 * @brief Enable SEVONPEND (send event on pending)
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_enable_sevonpend(void)
{
    SCB->SCR |= ARM_V7M_CM7_SCB_SCR_SEVONPEND_Msk;
}

/**
 * @brief Disable SEVONPEND
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_disable_sevonpend(void)
{
    SCB->SCR &= ~ARM_V7M_CM7_SCB_SCR_SEVONPEND_Msk;
}

/**
 * @brief Get System Control Register (SCR)
 * @return SCR value
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_scr(void)
{
    return SCB->SCR;
}

/**
 * @brief Set System Control Register (SCR)
 * @param value Value to write
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_set_scr(uint32_t value)
{
    SCB->SCR = value;
}

/**
 * @brief Get Configuration and Control Register (CCR)
 * @return CCR value
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_ccr(void)
{
    return SCB->CCR;
}

/**
 * @brief Set Configuration and Control Register (CCR)
 * @param value Value to write
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_set_ccr(uint32_t value)
{
    SCB->CCR = value;
}

/**
 * @brief Enable unaligned access trap
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_enable_unalign_trap(void)
{
    SCB->CCR |= ARM_V7M_CM7_SCB_CCR_UNALIGN_TRP_Msk;
}

/**
 * @brief Disable unaligned access trap
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_disable_unalign_trap(void)
{
    SCB->CCR &= ~ARM_V7M_CM7_SCB_CCR_UNALIGN_TRP_Msk;
}

/**
 * @brief Enable divide by zero trap
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_enable_divbyzero_trap(void)
{
    SCB->CCR |= ARM_V7M_CM7_SCB_CCR_DIV_0_TRP_Msk;
}

/**
 * @brief Disable divide by zero trap
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_disable_divbyzero_trap(void)
{
    SCB->CCR &= ~ARM_V7M_CM7_SCB_CCR_DIV_0_TRP_Msk;
}

/**
 * @brief Enable stack alignment (8-byte alignment on exception entry)
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_enable_stkalign(void)
{
    SCB->CCR |= ARM_V7M_CM7_SCB_CCR_STKALIGN_Msk;
}

/**
 * @brief Disable stack alignment
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_disable_stkalign(void)
{
    SCB->CCR &= ~ARM_V7M_CM7_SCB_CCR_STKALIGN_Msk;
}

/**
 * @brief Get System Handler Control and State Register (SHCSR)
 * @return SHCSR value
 */
ARM_V7M_CM7_SCB_INLINE uint32_t arm_v7m_cm7_scb_get_shcsr(void)
{
    return SCB->SHCSR;
}

/**
 * @brief Set System Handler Control and State Register (SHCSR)
 * @param value Value to write
 */
ARM_V7M_CM7_SCB_INLINE void arm_v7m_cm7_scb_set_shcsr(uint32_t value)
{
    SCB->SHCSR = value;
}

/*============================================================================*
 * Non-Inline Functions - Complex SCB Operations
 *============================================================================*/

/**
 * @brief Trigger a system reset
 * @note This function does not return if the reset is successful
 */
void arm_v7m_cm7_scb_system_reset(void);

/**
 * @brief Set the priority grouping field
 * @param priority_group Priority grouping field (ARM_V7M_CM7_SCB_PRIORITYGROUP_0 to _7)
 */
void arm_v7m_cm7_scb_set_priority_grouping(uint32_t priority_group);

/**
 * @brief Clear all fault status registers
 */
void arm_v7m_cm7_scb_clear_fault_status(void);

/**
 * @brief Get system handler priority
 * @param handler System handler number (0-11)
 * @return Priority value (0-255)
 */
uint32_t arm_v7m_cm7_scb_get_system_handler_priority(uint32_t handler);

/**
 * @brief Set system handler priority
 * @param handler System handler number (0-11)
 * @param priority Priority value (0-255)
 */
void arm_v7m_cm7_scb_set_system_handler_priority(uint32_t handler, uint32_t priority);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM7_SCB_H */
