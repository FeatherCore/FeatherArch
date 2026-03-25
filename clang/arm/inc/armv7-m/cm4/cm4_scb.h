/*
 * ARM Architecture - Cortex-M4 SCB (System Control Block)
 *
 * ============================================================================
 * File: cm4_scb.h
 * Description: Cortex-M4 SCB register definitions (wrapper for armv7-m_scb.h)
 * 描述: Cortex-M4 SCB 寄存器定义（armv7-m_scb.h 的包装层）
 *
 * This file provides CM4-specific naming conventions while delegating
 * all actual definitions to armv7-m_scb.h.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.3 System control block (page 4-10)
 *   - Table 4-12 SCB registers summary (page 4-11)
 *
 * Implementation: All functionality is provided by armv7-m/armv7-m_scb.h
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_SCB_H__
#define __CM4_SCB_H__

#include <stdint.h>

/* Include the underlying ARMv7-M implementation */
#include "armv7-m/armv7-m_scb.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * SCB Base Address Alias
 * SCB 基地址别名
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-12 (page 4-11)
 * ============================================================================
 */

#define CM4_SCB_BASE_ADDR             SCB_BASE_ADDR

/*
 * ============================================================================
 * Register Aliases - Map CM4 naming to ARMv7-M naming
 * 寄存器别名 - 将 CM4 命名映射到 ARMv7-M 命名
 * ============================================================================
 */

/* Auxiliary Control Register */
#define SCB_ACTLR                     (*(volatile uint32_t *)(0xE000E008UL))

/* ACTLR bit definitions */
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

/* SCB Registers - already defined in armv7-m_scb.h */
/* SCB_CPUID, SCB_ICSR, SCB_VTOR, SCB_AIRCR, SCB_SCR, SCB_CCR, etc. */

/* CPUID bit definitions - CM4 specific values */
#define SCB_CPUID_REVISION_Pos        CPUID_REVISION_Pos
#define SCB_CPUID_REVISION_Msk        CPUID_REVISION_Msk
#define SCB_CPUID_PARTNO_Pos          CPUID_PARTNO_Pos
#define SCB_CPUID_PARTNO_Msk          CPUID_PARTNO_Msk
#define SCB_CPUID_CONSTANT_Pos        CPUID_ARCHITECTURE_Pos
#define SCB_CPUID_CONSTANT_Msk        CPUID_ARCHITECTURE_Msk
#define SCB_CPUID_VARIANT_Pos         CPUID_VARIANT_Pos
#define SCB_CPUID_VARIANT_Msk         CPUID_VARIANT_Msk
#define SCB_CPUID_IMPLEMENTER_Pos     CPUID_IMPLEMENTER_Pos
#define SCB_CPUID_IMPLEMENTER_Msk     CPUID_IMPLEMENTER_Msk

/* Cortex-M4 specific values */
#define SCB_CPUID_IMPLEMENTER_ARM     0x41UL
#define SCB_CPUID_VARIANT_R0          0x0UL
#define SCB_CPUID_CONSTANT_VALUE      0xFUL
#define SCB_CPUID_PARTNO_CORTEX_M4    0xC24UL
#define SCB_CPUID_REVISION_P1         0x1UL

/* ICSR bit definitions */
#define SCB_ICSR_VECTACTIVE_Pos       ICSR_VECTACTIVE_Pos
#define SCB_ICSR_VECTACTIVE_Msk       ICSR_VECTACTIVE_Msk
#define SCB_ICSR_RETTOBASE_Pos        ICSR_RETTOBASE_Pos
#define SCB_ICSR_RETTOBASE_Msk        ICSR_RETTOBASE_Msk
#define SCB_ICSR_VECTPENDING_Pos      ICSR_VECTPENDING_Pos
#define SCB_ICSR_VECTPENDING_Msk      ICSR_VECTPENDING_Msk
#define SCB_ICSR_ISRPENDING_Pos       ICSR_ISRPENDING_Pos
#define SCB_ICSR_ISRPENDING_Msk       ICSR_ISRPENDING_Msk
#define SCB_ICSR_PENDSTCLR_Pos        ICSR_PENDSTCLR_Pos
#define SCB_ICSR_PENDSTCLR_Msk        ICSR_PENDSTCLR_Msk
#define SCB_ICSR_PENDSTSET_Pos        ICSR_PENDSTSET_Pos
#define SCB_ICSR_PENDSTSET_Msk        ICSR_PENDSTSET_Msk
#define SCB_ICSR_PENDSVCLR_Pos        ICSR_PENDSVCLR_Pos
#define SCB_ICSR_PENDSVCLR_Msk        ICSR_PENDSVCLR_Msk
#define SCB_ICSR_PENDSVSET_Pos        ICSR_PENDSVSET_Pos
#define SCB_ICSR_PENDSVSET_Msk        ICSR_PENDSVSET_Msk
#define SCB_ICSR_NMIPENDSET_Pos       ICSR_NMIPENDSET_Pos
#define SCB_ICSR_NMIPENDSET_Msk       ICSR_NMIPENDSET_Msk

/* VTOR bit definitions */
#define SCB_VTOR_TBLOFF_Pos           VTOR_TBLOFF_Pos
#define SCB_VTOR_TBLOFF_Msk           VTOR_TBLOFF_Msk

/* AIRCR bit definitions */
#define SCB_AIRCR_VECTRESET_Pos       AIRCR_VECTRESET_Pos
#define SCB_AIRCR_VECTRESET_Msk       AIRCR_VECTRESET_Msk
#define SCB_AIRCR_VECTCLRACTIVE_Pos   AIRCR_VECTCLRACTIVE_Pos
#define SCB_AIRCR_VECTCLRACTIVE_Msk   AIRCR_VECTCLRACTIVE_Msk
#define SCB_AIRCR_SYSRESETREQ_Pos     AIRCR_SYSRESETREQ_Pos
#define SCB_AIRCR_SYSRESETREQ_Msk     AIRCR_SYSRESETREQ_Msk
#define SCB_AIRCR_PRIGROUP_Pos        AIRCR_PRIGROUP_Pos
#define SCB_AIRCR_PRIGROUP_Msk        AIRCR_PRIGROUP_Msk
#define SCB_AIRCR_ENDIANNESS_Pos      AIRCR_ENDIANNESS_Pos
#define SCB_AIRCR_ENDIANNESS_Msk      AIRCR_ENDIANNESS_Msk
#define SCB_AIRCR_VECTKEY_Pos         AIRCR_VECTKEY_Pos
#define SCB_AIRCR_VECTKEY_Msk         AIRCR_VECTKEY_Msk
#define SCB_AIRCR_VECTKEYSTAT_Pos     AIRCR_VECTKEY_Pos
#define SCB_AIRCR_VECTKEYSTAT_Msk     AIRCR_VECTKEY_Msk
#define SCB_AIRCR_VECTKEY_VALUE       AIRCR_VECTKEY_VALUE

/* SCR bit definitions */
#define SCB_SCR_SLEEPONEXIT_Pos       SCR_SLEEPONEXIT_Pos
#define SCB_SCR_SLEEPONEXIT_Msk       SCR_SLEEPONEXIT_Msk
#define SCB_SCR_SLEEPDEEP_Pos         SCR_SLEEPDEEP_Pos
#define SCB_SCR_SLEEPDEEP_Msk         SCR_SLEEPDEEP_Msk
#define SCB_SCR_SEVONPEND_Pos         SCR_SEVONPEND_Pos
#define SCB_SCR_SEVONPEND_Msk         SCR_SEVONPEND_Msk

/* CCR bit definitions */
#define SCB_CCR_NONBASETHRDENA_Pos    CCR_NONBASETHRDENA_Pos
#define SCB_CCR_NONBASETHRDENA_Msk    CCR_NONBASETHRDENA_Msk
#define SCB_CCR_USERSETMPEND_Pos      CCR_USERSETMPEND_Pos
#define SCB_CCR_USERSETMPEND_Msk      CCR_USERSETMPEND_Msk
#define SCB_CCR_UNALIGN_TRP_Pos       CCR_UNALIGN_TRP_Pos
#define SCB_CCR_UNALIGN_TRP_Msk       CCR_UNALIGN_TRP_Msk
#define SCB_CCR_DIV_0_TRP_Pos         CCR_DIV_0_TRP_Pos
#define SCB_CCR_DIV_0_TRP_Msk         CCR_DIV_0_TRP_Msk
#define SCB_CCR_BFHFNMIGN_Pos         CCR_BFHFNMIGN_Pos
#define SCB_CCR_BFHFNMIGN_Msk         CCR_BFHFNMIGN_Msk
#define SCB_CCR_STKALIGN_Pos          CCR_STKALIGN_Pos
#define SCB_CCR_STKALIGN_Msk          CCR_STKALIGN_Msk

/* SHCSR bit definitions */
#define SCB_SHCSR_MEMFAULTACT_Pos     SHCSR_MEMFAULTACT_Pos
#define SCB_SHCSR_MEMFAULTACT_Msk     SHCSR_MEMFAULTACT_Msk
#define SCB_SHCSR_BUSFAULTACT_Pos     SHCSR_BUSFAULTACT_Pos
#define SCB_SHCSR_BUSFAULTACT_Msk     SHCSR_BUSFAULTACT_Msk
#define SCB_SHCSR_USGFAULTACT_Pos     SHCSR_USGFAULTACT_Pos
#define SCB_SHCSR_USGFAULTACT_Msk     SHCSR_USGFAULTACT_Msk
#define SCB_SHCSR_SVCALLACT_Pos       SHCSR_SVCALLACT_Pos
#define SCB_SHCSR_SVCALLACT_Msk       SHCSR_SVCALLACT_Msk
#define SCB_SHCSR_MONITORACT_Pos      SHCSR_MONITORACT_Pos
#define SCB_SHCSR_MONITORACT_Msk      SHCSR_MONITORACT_Msk
#define SCB_SHCSR_PENDSVACT_Pos       SHCSR_PENDSVACT_Pos
#define SCB_SHCSR_PENDSVACT_Msk       SHCSR_PENDSVACT_Msk
#define SCB_SHCSR_SYSTICKACT_Pos      SHCSR_SYSTICKACT_Pos
#define SCB_SHCSR_SYSTICKACT_Msk      SHCSR_SYSTICKACT_Msk
#define SCB_SHCSR_USGFAULTPENDED_Pos  SHCSR_USGFAULTPENDED_Pos
#define SCB_SHCSR_USGFAULTPENDED_Msk  SHCSR_USGFAULTPENDED_Msk
#define SCB_SHCSR_MEMFAULTPENDED_Pos  SHCSR_MEMFAULTPENDED_Pos
#define SCB_SHCSR_MEMFAULTPENDED_Msk  SHCSR_MEMFAULTPENDED_Msk
#define SCB_SHCSR_BUSFAULTPENDED_Pos  SHCSR_BUSFAULTPENDED_Pos
#define SCB_SHCSR_BUSFAULTPENDED_Msk  SHCSR_BUSFAULTPENDED_Msk
#define SCB_SHCSR_SVCALLPENDED_Pos    SHCSR_SVCALLPENDED_Pos
#define SCB_SHCSR_SVCALLPENDED_Msk    SHCSR_SVCALLPENDED_Msk
#define SCB_SHCSR_MEMFAULTENA_Pos     SHCSR_MEMFAULTENA_Pos
#define SCB_SHCSR_MEMFAULTENA_Msk     SHCSR_MEMFAULTENA_Msk
#define SCB_SHCSR_BUSFAULTENA_Pos     SHCSR_BUSFAULTENA_Pos
#define SCB_SHCSR_BUSFAULTENA_Msk     SHCSR_BUSFAULTENA_Msk
#define SCB_SHCSR_USGFAULTENA_Pos     SHCSR_USGFAULTENA_Pos
#define SCB_SHCSR_USGFAULTENA_Msk     SHCSR_USGFAULTENA_Msk

/* CFSR subregisters */
#define SCB_MMFSR                     CFSR_MMFSR
#define SCB_BFSR                      CFSR_BFSR
#define SCB_UFSR                      CFSR_UFSR

/* MMFSR bit definitions */
#define SCB_MMFSR_IACCVIOL_Pos        MMFSR_IACCVIOL_Pos
#define SCB_MMFSR_IACCVIOL_Msk        MMFSR_IACCVIOL_Msk
#define SCB_MMFSR_DACCVIOL_Pos        MMFSR_DACCVIOL_Pos
#define SCB_MMFSR_DACCVIOL_Msk        MMFSR_DACCVIOL_Msk
#define SCB_MMFSR_MUNSTKERR_Pos       MMFSR_MUNSTKERR_Pos
#define SCB_MMFSR_MUNSTKERR_Msk       MMFSR_MUNSTKERR_Msk
#define SCB_MMFSR_MSTKERR_Pos         MMFSR_MSTKERR_Pos
#define SCB_MMFSR_MSTKERR_Msk         MMFSR_MSTKERR_Msk
#define SCB_MMFSR_MLSPERR_Pos         MMFSR_MLSPERR_Pos
#define SCB_MMFSR_MLSPERR_Msk         MMFSR_MLSPERR_Msk
#define SCB_MMFSR_MMARVALID_Pos       MMFSR_MMARVALID_Pos
#define SCB_MMFSR_MMARVALID_Msk       MMFSR_MMARVALID_Msk

/* BFSR bit definitions */
#define SCB_BFSR_IBUSERR_Pos          BFSR_IBUSERR_Pos
#define SCB_BFSR_IBUSERR_Msk          BFSR_IBUSERR_Msk
#define SCB_BFSR_PRECISERR_Pos        BFSR_PRECISERR_Pos
#define SCB_BFSR_PRECISERR_Msk        BFSR_PRECISERR_Msk
#define SCB_BFSR_IMPRECISERR_Pos      BFSR_IMPRECISERR_Pos
#define SCB_BFSR_IMPRECISERR_Msk      BFSR_IMPRECISERR_Msk
#define SCB_BFSR_UNSTKERR_Pos         BFSR_UNSTKERR_Pos
#define SCB_BFSR_UNSTKERR_Msk         BFSR_UNSTKERR_Msk
#define SCB_BFSR_STKERR_Pos           BFSR_STKERR_Pos
#define SCB_BFSR_STKERR_Msk           BFSR_STKERR_Msk
#define SCB_BFSR_LSPERR_Pos           BFSR_LSPERR_Pos
#define SCB_BFSR_LSPERR_Msk           BFSR_LSPERR_Msk
#define SCB_BFSR_BFARVALID_Pos        BFSR_BFARVALID_Pos
#define SCB_BFSR_BFARVALID_Msk        BFSR_BFARVALID_Msk

/* UFSR bit definitions */
#define SCB_UFSR_UNDEFINSTR_Pos       UFSR_UNDEFINSTR_Pos
#define SCB_UFSR_UNDEFINSTR_Msk       UFSR_UNDEFINSTR_Msk
#define SCB_UFSR_INVSTATE_Pos         UFSR_INVSTATE_Pos
#define SCB_UFSR_INVSTATE_Msk         UFSR_INVSTATE_Msk
#define SCB_UFSR_INVPC_Pos            UFSR_INVPC_Pos
#define SCB_UFSR_INVPC_Msk            UFSR_INVPC_Msk
#define SCB_UFSR_NOCP_Pos             UFSR_NOCP_Pos
#define SCB_UFSR_NOCP_Msk             UFSR_NOCP_Msk
#define SCB_UFSR_UNALIGNED_Pos        UFSR_UNALIGNED_Pos
#define SCB_UFSR_UNALIGNED_Msk        UFSR_UNALIGNED_Msk
#define SCB_UFSR_DIVBYZERO_Pos        UFSR_DIVBYZERO_Pos
#define SCB_UFSR_DIVBYZERO_Msk        UFSR_DIVBYZERO_Msk

/* HFSR bit definitions */
#define SCB_HFSR_VECTTBL_Pos          HFSR_VECTTBL_Pos
#define SCB_HFSR_VECTTBL_Msk          HFSR_VECTTBL_Msk
#define SCB_HFSR_FORCED_Pos           HFSR_FORCED_Pos
#define SCB_HFSR_FORCED_Msk           HFSR_FORCED_Msk
#define SCB_HFSR_DEBUGEVT_Pos         HFSR_DEBUGEVT_Pos
#define SCB_HFSR_DEBUGEVT_Msk         HFSR_DEBUGEVT_Msk

/* CPACR bit definitions */
#define SCB_CPACR_CP10_Pos            CPACR_CP10_Pos
#define SCB_CPACR_CP10_Msk            CPACR_CP10_Msk
#define SCB_CPACR_CP11_Pos            CPACR_CP11_Pos
#define SCB_CPACR_CP11_Msk            CPACR_CP11_Msk
#define SCB_CPACR_CP_ACCESS_DENIED    CPACR_ACCESS_DENIED
#define SCB_CPACR_CP_PRIV_ACCESS      CPACR_ACCESS_PRIV
#define SCB_CPACR_CP_FULL_ACCESS      CPACR_ACCESS_FULL

/*
 * ============================================================================
 * Function Aliases - Map CM4 naming to ARMv7-M naming
 * 函数别名 - 将 CM4 命名映射到 ARMv7-M 命名
 * ============================================================================
 */

/**
 * @brief Set vector table offset
 * @param offset Vector table offset address (must be aligned to 128 bytes)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.4 (page 4-16)
 * Implementation: Delegates to scb_set_vtor() in armv7-m_scb.c
 */
static inline void cm4_scb_set_vtor(uint32_t offset)
{
    scb_set_vtor(offset);
}

/**
 * @brief Get vector table offset
 * @return Vector table offset address
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.4 (page 4-16)
 * Implementation: Delegates to scb_get_vtor() in armv7-m_scb.c
 */
static inline uint32_t cm4_scb_get_vtor(void)
{
    return scb_get_vtor();
}

/**
 * @brief System reset request
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.5 (page 4-17)
 * Implementation: Delegates to scb_system_reset() in armv7-m_scb.c
 */
static inline void cm4_scb_system_reset(void)
{
    scb_system_reset();
}

/**
 * @brief Set priority grouping
 * @param group Priority grouping value (0-7)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.5 (page 4-17)
 * Implementation: Delegates to scb_set_priority_grouping() in armv7-m_scb.c
 */
static inline void cm4_scb_set_priority_grouping(uint32_t group)
{
    scb_set_priority_grouping(group);
}

/**
 * @brief Get priority grouping
 * @return Priority grouping value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.5 (page 4-17)
 * Implementation: Delegates to scb_get_priority_grouping() in armv7-m_scb.c
 */
static inline uint32_t cm4_scb_get_priority_grouping(void)
{
    return scb_get_priority_grouping();
}

/**
 * @brief Enable MemManage fault
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.9 (page 4-23)
 * Implementation: Delegates to scb_enable_memmanage() in armv7-m_scb.c
 */
static inline void cm4_scb_enable_memfault(void)
{
    scb_enable_memmanage();
}

/**
 * @brief Enable BusFault
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.9 (page 4-23)
 * Implementation: Delegates to scb_enable_bus_fault() in armv7-m_scb.c
 */
static inline void cm4_scb_enable_busfault(void)
{
    scb_enable_bus_fault();
}

/**
 * @brief Enable UsageFault
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.9 (page 4-23)
 * Implementation: Delegates to scb_enable_usage_fault() in armv7-m_scb.c
 */
static inline void cm4_scb_enable_usagefault(void)
{
    scb_enable_usage_fault();
}

/**
 * @brief Get CPUID
 * @return CPUID register value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.2 (page 4-13)
 * Implementation: Delegates to scb_get_cpuid() in armv7-m_scb.c
 */
static inline uint32_t cm4_scb_get_cpuid(void)
{
    return scb_get_cpuid();
}

#ifdef __cplusplus
}
#endif

#endif /* __CM4_SCB_H__ */
