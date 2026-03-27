/*
 * arm_v7m_scb.h
 * System Control Block (SCB) Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2
 */

#ifndef ARM_V7M_SCB_H
#define ARM_V7M_SCB_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * SCB Base Address (Architecture defined)
 * Reference: ARMv7-M Architecture Reference Manual, Table B3-4
 *============================================================================*/
#define SCB_BASE            0xE000ED00UL

/*============================================================================*
 * SCB Type Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Table B3-4
 *============================================================================*/

typedef struct {
    volatile const uint32_t CPUID;          /*!< Offset: 0x000 (R/ )  CPUID Base Register                                   */
    volatile uint32_t ICSR;                 /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register                  */
    volatile uint32_t VTOR;                 /*!< Offset: 0x008 (R/W)  Vector Table Offset Register                          */
    volatile uint32_t AIRCR;                /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register      */
    volatile uint32_t SCR;                  /*!< Offset: 0x010 (R/W)  System Control Register                               */
    volatile uint32_t CCR;                  /*!< Offset: 0x014 (R/W)  Configuration and Control Register                    */
    volatile uint8_t  SHP[12];              /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15)*/
    volatile uint32_t SHCSR;                /*!< Offset: 0x024 (R/W)  System Handler Control and State Register             */
    volatile uint32_t CFSR;                 /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register                    */
    volatile uint32_t HFSR;                 /*!< Offset: 0x02C (R/W)  HardFault Status Register                             */
    volatile uint32_t DFSR;                 /*!< Offset: 0x030 (R/W)  Debug Fault Status Register                           */
    volatile uint32_t MMFAR;                /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register                      */
    volatile uint32_t BFAR;                 /*!< Offset: 0x038 (R/W)  BusFault Address Register                             */
    volatile uint32_t AFSR;                 /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register                       */
    volatile const uint32_t ID_PFR[2];      /*!< Offset: 0x040 (R/ )  Processor Feature Register 0-1, ID_PFR0/1            */
    volatile const uint32_t ID_DFR0;        /*!< Offset: 0x048 (R/ )  Debug Feature Register 0, ID_DFR0                     */
    volatile const uint32_t ID_AFR0;        /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register 0, ID_AFR0                 */
    volatile const uint32_t ID_MMFR[4];     /*!< Offset: 0x050 (R/ )  Memory Model Feature Register 0-3, ID_MMFR0-3         */
    volatile const uint32_t ID_ISAR[5];     /*!< Offset: 0x060 (R/ )  Instruction Set Attribute Register 0-4, ID_ISAR0-4    */
    volatile const uint32_t ID_ISAR5;       /*!< Offset: 0x074 (R/ )  Instruction Set Attribute Register 5, Reserved RAZ    */
    uint32_t RESERVED0[5];                  /*!< Offset: 0x078-0x084  Reserved                                              */
    volatile uint32_t CPACR;                /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register                   */
} arm_v7m_scb_regs_t;

#define SCB                 ((arm_v7m_scb_regs_t *)SCB_BASE)

/*============================================================================*
 * SCB CPUID Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.3
 *============================================================================*/
#define SCB_CPUID_IMPLEMENTER_Pos     24U
#define SCB_CPUID_IMPLEMENTER_Msk     (0xFFUL << SCB_CPUID_IMPLEMENTER_Pos)
#define SCB_CPUID_VARIANT_Pos         20U
#define SCB_CPUID_VARIANT_Msk         (0xFUL << SCB_CPUID_VARIANT_Pos)
#define SCB_CPUID_ARCHITECTURE_Pos    16U
#define SCB_CPUID_ARCHITECTURE_Msk    (0xFUL << SCB_CPUID_ARCHITECTURE_Pos)
#define SCB_CPUID_PARTNO_Pos           4U
#define SCB_CPUID_PARTNO_Msk          (0xFFFUL << SCB_CPUID_PARTNO_Pos)
#define SCB_CPUID_REVISION_Pos         0U
#define SCB_CPUID_REVISION_Msk        (0xFUL << SCB_CPUID_REVISION_Pos)

/*============================================================================*
 * SCB ICSR Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.4
 *============================================================================*/
#define SCB_ICSR_NMIPENDSET_Pos       31U
#define SCB_ICSR_NMIPENDSET_Msk       (1UL << SCB_ICSR_NMIPENDSET_Pos)
#define SCB_ICSR_PENDSVSET_Pos        28U
#define SCB_ICSR_PENDSVSET_Msk        (1UL << SCB_ICSR_PENDSVSET_Pos)
#define SCB_ICSR_PENDSVCLR_Pos        27U
#define SCB_ICSR_PENDSVCLR_Msk        (1UL << SCB_ICSR_PENDSVCLR_Pos)
#define SCB_ICSR_PENDSTSET_Pos        26U
#define SCB_ICSR_PENDSTSET_Msk        (1UL << SCB_ICSR_PENDSTSET_Pos)
#define SCB_ICSR_PENDSTCLR_Pos        25U
#define SCB_ICSR_PENDSTCLR_Msk        (1UL << SCB_ICSR_PENDSTCLR_Pos)
#define SCB_ICSR_ISRPREEMPT_Pos       23U
#define SCB_ICSR_ISRPREEMPT_Msk       (1UL << SCB_ICSR_ISRPREEMPT_Pos)
#define SCB_ICSR_ISRPENDING_Pos       22U
#define SCB_ICSR_ISRPENDING_Msk       (1UL << SCB_ICSR_ISRPENDING_Pos)
#define SCB_ICSR_VECTPENDING_Pos      12U
#define SCB_ICSR_VECTPENDING_Msk      (0x1FFUL << SCB_ICSR_VECTPENDING_Pos)
#define SCB_ICSR_RETTOBASE_Pos        11U
#define SCB_ICSR_RETTOBASE_Msk        (1UL << SCB_ICSR_RETTOBASE_Pos)
#define SCB_ICSR_VECTACTIVE_Pos        0U
#define SCB_ICSR_VECTACTIVE_Msk       (0x1FFUL << SCB_ICSR_VECTACTIVE_Pos)

/*============================================================================*
 * SCB VTOR Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.5
 *============================================================================*/
#define SCB_VTOR_TBLOFF_Pos            7U
#define SCB_VTOR_TBLOFF_Msk           (0x1FFFFFFUL << SCB_VTOR_TBLOFF_Pos)

/*============================================================================*
 * SCB AIRCR Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.6
 *============================================================================*/
#define SCB_AIRCR_VECTKEY_Pos         16U
#define SCB_AIRCR_VECTKEY_Msk         (0xFFFFUL << SCB_AIRCR_VECTKEY_Pos)
#define SCB_AIRCR_VECTKEYSTAT_Pos     16U
#define SCB_AIRCR_VECTKEYSTAT_Msk     (0xFFFFUL << SCB_AIRCR_VECTKEYSTAT_Pos)
#define SCB_AIRCR_ENDIANESS_Pos       15U
#define SCB_AIRCR_ENDIANESS_Msk       (1UL << SCB_AIRCR_ENDIANESS_Pos)
#define SCB_AIRCR_PRIGROUP_Pos         8U
#define SCB_AIRCR_PRIGROUP_Msk        (7UL << SCB_AIRCR_PRIGROUP_Pos)
#define SCB_AIRCR_SYSRESETREQ_Pos      2U
#define SCB_AIRCR_SYSRESETREQ_Msk     (1UL << SCB_AIRCR_SYSRESETREQ_Pos)
#define SCB_AIRCR_VECTCLRACTIVE_Pos    1U
#define SCB_AIRCR_VECTCLRACTIVE_Msk   (1UL << SCB_AIRCR_VECTCLRACTIVE_Pos)
#define SCB_AIRCR_VECTRESET_Pos        0U
#define SCB_AIRCR_VECTRESET_Msk       (1UL << SCB_AIRCR_VECTRESET_Pos)

/* VECTKEY value for AIRCR register writes */
#define SCB_AIRCR_VECTKEY_VALUE       (0x05FAUL)

/* Priority Grouping */
#define SCB_PRIORITYGROUP_0           (0x00000007U) /*!< 0 bits for pre-emption priority, 8 bits for subpriority */
#define SCB_PRIORITYGROUP_1           (0x00000006U) /*!< 1 bits for pre-emption priority, 7 bits for subpriority */
#define SCB_PRIORITYGROUP_2           (0x00000005U) /*!< 2 bits for pre-emption priority, 6 bits for subpriority */
#define SCB_PRIORITYGROUP_3           (0x00000004U) /*!< 3 bits for pre-emption priority, 5 bits for subpriority */
#define SCB_PRIORITYGROUP_4           (0x00000003U) /*!< 4 bits for pre-emption priority, 4 bits for subpriority */
#define SCB_PRIORITYGROUP_5           (0x00000002U) /*!< 5 bits for pre-emption priority, 3 bits for subpriority */
#define SCB_PRIORITYGROUP_6           (0x00000001U) /*!< 6 bits for pre-emption priority, 2 bits for subpriority */
#define SCB_PRIORITYGROUP_7           (0x00000000U) /*!< 7 bits for pre-emption priority, 1 bits for subpriority */

/*============================================================================*
 * SCB SCR Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.7
 *============================================================================*/
#define SCB_SCR_SEVONPEND_Pos          4U
#define SCB_SCR_SEVONPEND_Msk         (1UL << SCB_SCR_SEVONPEND_Pos)
#define SCB_SCR_SLEEPDEEP_Pos          2U
#define SCB_SCR_SLEEPDEEP_Msk         (1UL << SCB_SCR_SLEEPDEEP_Pos)
#define SCB_SCR_SLEEPONEXIT_Pos        1U
#define SCB_SCR_SLEEPONEXIT_Msk       (1UL << SCB_SCR_SLEEPONEXIT_Pos)

/*============================================================================*
 * SCB CCR Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.8
 *============================================================================*/
#define SCB_CCR_STKALIGN_Pos           9U
#define SCB_CCR_STKALIGN_Msk          (1UL << SCB_CCR_STKALIGN_Pos)
#define SCB_CCR_BFHFNMIGN_Pos          8U
#define SCB_CCR_BFHFNMIGN_Msk         (1UL << SCB_CCR_BFHFNMIGN_Pos)
#define SCB_CCR_DIV_0_TRP_Pos          4U
#define SCB_CCR_DIV_0_TRP_Msk         (1UL << SCB_CCR_DIV_0_TRP_Pos)
#define SCB_CCR_UNALIGN_TRP_Pos        3U
#define SCB_CCR_UNALIGN_TRP_Msk       (1UL << SCB_CCR_UNALIGN_TRP_Pos)
#define SCB_CCR_USERSETMPEND_Pos       1U
#define SCB_CCR_USERSETMPEND_Msk      (1UL << SCB_CCR_USERSETMPEND_Pos)
#define SCB_CCR_NONBASETHRDENA_Pos     0U
#define SCB_CCR_NONBASETHRDENA_Msk    (1UL << SCB_CCR_NONBASETHRDENA_Pos)

/*============================================================================*
 * SCB SHCSR Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.13
 *            - System Handler Control and State Register, SHCSR on page B3-607
 *============================================================================*/
#define SCB_SHCSR_USGFAULTENA_Pos     18U
#define SCB_SHCSR_USGFAULTENA_Msk     (1UL << SCB_SHCSR_USGFAULTENA_Pos)
#define SCB_SHCSR_BUSFAULTENA_Pos     17U
#define SCB_SHCSR_BUSFAULTENA_Msk     (1UL << SCB_SHCSR_BUSFAULTENA_Pos)
#define SCB_SHCSR_MEMFAULTENA_Pos     16U
#define SCB_SHCSR_MEMFAULTENA_Msk     (1UL << SCB_SHCSR_MEMFAULTENA_Pos)
#define SCB_SHCSR_SVCALLPENDED_Pos    15U
#define SCB_SHCSR_SVCALLPENDED_Msk    (1UL << SCB_SHCSR_SVCALLPENDED_Pos)
#define SCB_SHCSR_BUSFAULTPENDED_Pos  14U
#define SCB_SHCSR_BUSFAULTPENDED_Msk  (1UL << SCB_SHCSR_BUSFAULTPENDED_Pos)
#define SCB_SHCSR_MEMFAULTPENDED_Pos  13U
#define SCB_SHCSR_MEMFAULTPENDED_Msk  (1UL << SCB_SHCSR_MEMFAULTPENDED_Pos)
#define SCB_SHCSR_USGFAULTPENDED_Pos  12U
#define SCB_SHCSR_USGFAULTPENDED_Msk  (1UL << SCB_SHCSR_USGFAULTPENDED_Pos)
#define SCB_SHCSR_SYSTICKACT_Pos      11U
#define SCB_SHCSR_SYSTICKACT_Msk      (1UL << SCB_SHCSR_SYSTICKACT_Pos)
#define SCB_SHCSR_PENDSVACT_Pos       10U
#define SCB_SHCSR_PENDSVACT_Msk       (1UL << SCB_SHCSR_PENDSVACT_Pos)
#define SCB_SHCSR_MONITORACT_Pos       8U
#define SCB_SHCSR_MONITORACT_Msk      (1UL << SCB_SHCSR_MONITORACT_Pos)
#define SCB_SHCSR_SVCALLACT_Pos        7U
#define SCB_SHCSR_SVCALLACT_Msk       (1UL << SCB_SHCSR_SVCALLACT_Pos)
#define SCB_SHCSR_USGFAULTACT_Pos      3U
#define SCB_SHCSR_USGFAULTACT_Msk     (1UL << SCB_SHCSR_USGFAULTACT_Pos)
#define SCB_SHCSR_BUSFAULTACT_Pos      1U
#define SCB_SHCSR_BUSFAULTACT_Msk     (1UL << SCB_SHCSR_BUSFAULTACT_Pos)
#define SCB_SHCSR_MEMFAULTACT_Pos      0U
#define SCB_SHCSR_MEMFAULTACT_Msk     (1UL << SCB_SHCSR_MEMFAULTACT_Pos)

/*============================================================================*
 * SCB CFSR Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.14
 *            - Configurable Fault Status Register, CFSR on page B3-609
 *============================================================================*/
/* MemManage Fault Status Register (MMFSR) - Lower 8 bits of CFSR */
#define SCB_CFSR_MMARVALID_Pos        (7U + 0U)
#define SCB_CFSR_MMARVALID_Msk        (1UL << SCB_CFSR_MMARVALID_Pos)
#define SCB_CFSR_MLSPERR_Pos          (5U + 0U)
#define SCB_CFSR_MLSPERR_Msk          (1UL << SCB_CFSR_MLSPERR_Pos)
#define SCB_CFSR_MSTKERR_Pos          (4U + 0U)
#define SCB_CFSR_MSTKERR_Msk          (1UL << SCB_CFSR_MSTKERR_Pos)
#define SCB_CFSR_MUNSTKERR_Pos        (3U + 0U)
#define SCB_CFSR_MUNSTKERR_Msk        (1UL << SCB_CFSR_MUNSTKERR_Pos)
#define SCB_CFSR_DACCVIOL_Pos         (1U + 0U)
#define SCB_CFSR_DACCVIOL_Msk         (1UL << SCB_CFSR_DACCVIOL_Pos)
#define SCB_CFSR_IACCVIOL_Pos         (0U + 0U)
#define SCB_CFSR_IACCVIOL_Msk         (1UL << SCB_CFSR_IACCVIOL_Pos)

/* BusFault Status Register (BFSR) - Middle 8 bits of CFSR */
#define SCB_CFSR_BFARVALID_Pos        (7U + 8U)
#define SCB_CFSR_BFARVALID_Msk        (1UL << SCB_CFSR_BFARVALID_Pos)
#define SCB_CFSR_LSPERR_Pos           (5U + 8U)
#define SCB_CFSR_LSPERR_Msk           (1UL << SCB_CFSR_LSPERR_Pos)
#define SCB_CFSR_STKERR_Pos           (4U + 8U)
#define SCB_CFSR_STKERR_Msk           (1UL << SCB_CFSR_STKERR_Pos)
#define SCB_CFSR_UNSTKERR_Pos         (3U + 8U)
#define SCB_CFSR_UNSTKERR_Msk         (1UL << SCB_CFSR_UNSTKERR_Pos)
#define SCB_CFSR_IMPRECISERR_Pos      (2U + 8U)
#define SCB_CFSR_IMPRECISERR_Msk      (1UL << SCB_CFSR_IMPRECISERR_Pos)
#define SCB_CFSR_PRECISERR_Pos        (1U + 8U)
#define SCB_CFSR_PRECISERR_Msk        (1UL << SCB_CFSR_PRECISERR_Pos)
#define SCB_CFSR_IBUSERR_Pos          (0U + 8U)
#define SCB_CFSR_IBUSERR_Msk          (1UL << SCB_CFSR_IBUSERR_Pos)

/* UsageFault Status Register (UFSR) - Upper 16 bits of CFSR */
#define SCB_CFSR_DIVBYZERO_Pos        (9U + 16U)
#define SCB_CFSR_DIVBYZERO_Msk        (1UL << SCB_CFSR_DIVBYZERO_Pos)
#define SCB_CFSR_UNALIGNED_Pos        (8U + 16U)
#define SCB_CFSR_UNALIGNED_Msk        (1UL << SCB_CFSR_UNALIGNED_Pos)
#define SCB_CFSR_NOCP_Pos             (3U + 16U)
#define SCB_CFSR_NOCP_Msk             (1UL << SCB_CFSR_NOCP_Pos)
#define SCB_CFSR_INVPC_Pos            (2U + 16U)
#define SCB_CFSR_INVPC_Msk            (1UL << SCB_CFSR_INVPC_Pos)
#define SCB_CFSR_INVSTATE_Pos         (1U + 16U)
#define SCB_CFSR_INVSTATE_Msk         (1UL << SCB_CFSR_INVSTATE_Pos)
#define SCB_CFSR_UNDEFINSTR_Pos       (0U + 16U)
#define SCB_CFSR_UNDEFINSTR_Msk       (1UL << SCB_CFSR_UNDEFINSTR_Pos)

/*============================================================================*
 * SCB HFSR Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.15
 *            - HardFault Status Register, HFSR on page B3-612
 *============================================================================*/
#define SCB_HFSR_DEBUGEVT_Pos         31U
#define SCB_HFSR_DEBUGEVT_Msk         (1UL << SCB_HFSR_DEBUGEVT_Pos)
#define SCB_HFSR_FORCED_Pos           30U
#define SCB_HFSR_FORCED_Msk           (1UL << SCB_HFSR_FORCED_Pos)
#define SCB_HFSR_VECTTBL_Pos           1U
#define SCB_HFSR_VECTTBL_Msk          (1UL << SCB_HFSR_VECTTBL_Pos)

/*============================================================================*
 * SCB DFSR Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section C1.6.4
 *============================================================================*/
#define SCB_DFSR_EXTERNAL_Pos          4U
#define SCB_DFSR_EXTERNAL_Msk         (1UL << SCB_DFSR_EXTERNAL_Pos)
#define SCB_DFSR_VCATCH_Pos            3U
#define SCB_DFSR_VCATCH_Msk           (1UL << SCB_DFSR_VCATCH_Pos)
#define SCB_DFSR_DWTTRAP_Pos           2U
#define SCB_DFSR_DWTTRAP_Msk          (1UL << SCB_DFSR_DWTTRAP_Pos)
#define SCB_DFSR_BKPT_Pos              1U
#define SCB_DFSR_BKPT_Msk             (1UL << SCB_DFSR_BKPT_Pos)
#define SCB_DFSR_HALTED_Pos            0U
#define SCB_DFSR_HALTED_Msk           (1UL << SCB_DFSR_HALTED_Pos)

/*============================================================================*
 * SCB CPACR Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.19
 *            - Coprocessor Access Control Register, CPACR on page B3-614
 *============================================================================*/
#define SCB_CPACR_CP10_Pos            20U
#define SCB_CPACR_CP10_Msk          (3UL << SCB_CPACR_CP10_Pos)
#define SCB_CPACR_CP11_Pos            22U
#define SCB_CPACR_CP11_Msk          (3UL << SCB_CPACR_CP11_Pos)

/* CPACR Access Values */
#define SCB_CPACR_CP_ACCESS_DENIED    0x0U  /*!< Access denied. Any attempted access generates a NOCP UsageFault. */
#define SCB_CPACR_CP_PRIV_ACCESS      0x1U  /*!< Privileged access only. An unprivileged access generates a NOCP UsageFault. */
#define SCB_CPACR_CP_RESERVED         0x2U  /*!< Reserved. Any attempted access generates a NOCP UsageFault. */
#define SCB_CPACR_CP_FULL_ACCESS      0x3U  /*!< Full access. */

/*============================================================================*
 * Inline Functions - Basic SCB Operations
 *============================================================================*/

/**
 * @brief Set the vector table offset
 * @param offset Vector table offset (must be aligned to 128 bytes)
 */
static inline void arm_v7m_scb_set_vector_table(uint32_t offset)
{
    SCB->VTOR = offset & SCB_VTOR_TBLOFF_Msk;
}

/**
 * @brief Get the vector table offset
 * @return Current vector table offset
 */
static inline uint32_t arm_v7m_scb_get_vector_table(void)
{
    return SCB->VTOR & SCB_VTOR_TBLOFF_Msk;
}

/**
 * @brief Get the priority grouping field
 * @return Priority grouping field (0-7)
 */
static inline uint32_t arm_v7m_scb_get_priority_grouping(void)
{
    return (SCB->AIRCR & SCB_AIRCR_PRIGROUP_Msk) >> SCB_AIRCR_PRIGROUP_Pos;
}

/**
 * @brief Get CPUID
 * @return CPUID register value
 */
static inline uint32_t arm_v7m_scb_get_cpuid(void)
{
    return SCB->CPUID;
}

/**
 * @brief Get the current active exception number
 * @return Current active exception number (0-511), 0 means Thread mode
 */
static inline uint32_t arm_v7m_scb_get_active_exception(void)
{
    return (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) >> SCB_ICSR_VECTACTIVE_Pos;
}

/**
 * @brief Get the pending exception number
 * @return Pending exception number (0-511), 0 means no pending exception
 */
static inline uint32_t arm_v7m_scb_get_pending_exception(void)
{
    return (SCB->ICSR & SCB_ICSR_VECTPENDING_Msk) >> SCB_ICSR_VECTPENDING_Pos;
}

/**
 * @brief Set the PendSV exception to pending
 */
static inline void arm_v7m_scb_set_pendsv_pending(void)
{
    SCB->ICSR = SCB_ICSR_PENDSVSET_Msk;
}

/**
 * @brief Clear the PendSV exception pending status
 */
static inline void arm_v7m_scb_clear_pendsv_pending(void)
{
    SCB->ICSR = SCB_ICSR_PENDSVCLR_Msk;
}

/**
 * @brief Set the SysTick exception to pending
 */
static inline void arm_v7m_scb_set_systick_pending(void)
{
    SCB->ICSR = SCB_ICSR_PENDSTSET_Msk;
}

/**
 * @brief Clear the SysTick exception pending status
 */
static inline void arm_v7m_scb_clear_systick_pending(void)
{
    SCB->ICSR = SCB_ICSR_PENDSTCLR_Msk;
}

/**
 * @brief Set the NMI exception to pending
 */
static inline void arm_v7m_scb_set_nmi_pending(void)
{
    SCB->ICSR = SCB_ICSR_NMIPENDSET_Msk;
}

/**
 * @brief Check if an interrupt is pending
 * @return 1 if any interrupt is pending, 0 otherwise
 */
static inline uint32_t arm_v7m_scb_is_interrupt_pending(void)
{
    return (SCB->ICSR & SCB_ICSR_ISRPENDING_Msk) ? 1U : 0U;
}

/**
 * @brief Check if returning to base (no active exceptions)
 * @return 1 if returning to base, 0 otherwise
 */
static inline uint32_t arm_v7m_scb_is_return_to_base(void)
{
    return (SCB->ICSR & SCB_ICSR_RETTOBASE_Msk) ? 1U : 0U;
}

/**
 * @brief Enable fault exceptions (MemManage, BusFault, UsageFault)
 * @param fault_mask Bit mask of faults to enable (SHCSR_MEMFAULTENA | SHCSR_BUSFAULTENA | SHCSR_USGFAULTENA)
 */
static inline void arm_v7m_scb_enable_fault_exceptions(uint32_t fault_mask)
{
    SCB->SHCSR |= fault_mask;
}

/**
 * @brief Disable fault exceptions
 * @param fault_mask Bit mask of faults to disable
 */
static inline void arm_v7m_scb_disable_fault_exceptions(uint32_t fault_mask)
{
    SCB->SHCSR &= ~fault_mask;
}

/**
 * @brief Get Configurable Fault Status Register
 * @return CFSR value
 */
static inline uint32_t arm_v7m_scb_get_cfsr(void)
{
    return SCB->CFSR;
}

/**
 * @brief Clear Configurable Fault Status Register
 * @param mask Bits to clear (write 1 to clear)
 */
static inline void arm_v7m_scb_clear_cfsr(uint32_t mask)
{
    SCB->CFSR = mask;
}

/**
 * @brief Get HardFault Status Register
 * @return HFSR value
 */
static inline uint32_t arm_v7m_scb_get_hfsr(void)
{
    return SCB->HFSR;
}

/**
 * @brief Clear HardFault Status Register
 * @param mask Bits to clear (write 1 to clear)
 */
static inline void arm_v7m_scb_clear_hfsr(uint32_t mask)
{
    SCB->HFSR = mask;
}

/**
 * @brief Get Debug Fault Status Register
 * @return DFSR value
 */
static inline uint32_t arm_v7m_scb_get_dfsr(void)
{
    return SCB->DFSR;
}

/**
 * @brief Clear Debug Fault Status Register
 * @param mask Bits to clear (write 1 to clear)
 */
static inline void arm_v7m_scb_clear_dfsr(uint32_t mask)
{
    SCB->DFSR = mask;
}

/**
 * @brief Get MemManage Fault Address Register
 * @return MMFAR value
 */
static inline uint32_t arm_v7m_scb_get_mmfar(void)
{
    return SCB->MMFAR;
}

/**
 * @brief Get BusFault Address Register
 * @return BFAR value
 */
static inline uint32_t arm_v7m_scb_get_bfar(void)
{
    return SCB->BFAR;
}

/**
 * @brief Get Auxiliary Fault Status Register
 * @return AFSR value
 * @note AFSR is IMPLEMENTATION DEFINED
 */
static inline uint32_t arm_v7m_scb_get_afsr(void)
{
    return SCB->AFSR;
}

/**
 * @brief Set Auxiliary Fault Status Register
 * @param value Value to write
 * @note AFSR is IMPLEMENTATION DEFINED
 */
static inline void arm_v7m_scb_set_afsr(uint32_t value)
{
    SCB->AFSR = value;
}

/**
 * @brief Get Processor Feature Register 0
 * @return ID_PFR[0] value
 */
static inline uint32_t arm_v7m_scb_get_id_pfr0(void)
{
    return SCB->ID_PFR[0];
}

/**
 * @brief Get Processor Feature Register 1
 * @return ID_PFR[1] value
 */
static inline uint32_t arm_v7m_scb_get_id_pfr1(void)
{
    return SCB->ID_PFR[1];
}

/**
 * @brief Get Debug Feature Register 0
 * @return ID_DFR0 value
 */
static inline uint32_t arm_v7m_scb_get_id_dfr0(void)
{
    return SCB->ID_DFR0;
}

/**
 * @brief Get Auxiliary Feature Register 0
 * @return ID_AFR0 value
 */
static inline uint32_t arm_v7m_scb_get_id_afr0(void)
{
    return SCB->ID_AFR0;
}

/**
 * @brief Get Memory Model Feature Register
 * @param index Register index (0-3)
 * @return ID_MMFR[index] value
 */
static inline uint32_t arm_v7m_scb_get_id_mmfr(uint32_t index)
{
    return (index < 4U) ? SCB->ID_MMFR[index] : 0U;
}

/**
 * @brief Get Instruction Set Attribute Register
 * @param index Register index (0-4)
 * @return ID_ISAR[index] value
 */
static inline uint32_t arm_v7m_scb_get_id_isar(uint32_t index)
{
    return (index < 5U) ? SCB->ID_ISAR[index] : 0U;
}

/**
 * @brief Get CPACR (Coprocessor Access Control Register)
 * @return CPACR value
 */
static inline uint32_t arm_v7m_scb_get_cpacr(void)
{
    return SCB->CPACR;
}

/**
 * @brief Set CPACR (Coprocessor Access Control Register)
 * @param value Value to write
 */
static inline void arm_v7m_scb_set_cpacr(uint32_t value)
{
    SCB->CPACR = value;
}

/**
 * @brief Enable FPU (set CP10 and CP11 to full access)
 * @note Must be called before using FPU instructions
 */
static inline void arm_v7m_scb_enable_fpu(void)
{
    SCB->CPACR |= ((SCB_CPACR_CP_FULL_ACCESS << SCB_CPACR_CP10_Pos) |
                   (SCB_CPACR_CP_FULL_ACCESS << SCB_CPACR_CP11_Pos));
}

/**
 * @brief Disable FPU (set CP10 and CP11 to access denied)
 */
static inline void arm_v7m_scb_disable_fpu(void)
{
    SCB->CPACR &= ~((SCB_CPACR_CP10_Msk) | (SCB_CPACR_CP11_Msk));
}

/**
 * @brief Enable deep sleep mode
 */
static inline void arm_v7m_scb_enable_deep_sleep(void)
{
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
}

/**
 * @brief Disable deep sleep mode
 */
static inline void arm_v7m_scb_disable_deep_sleep(void)
{
    SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
}

/**
 * @brief Enable sleep-on-exit
 */
static inline void arm_v7m_scb_enable_sleep_on_exit(void)
{
    SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk;
}

/**
 * @brief Disable sleep-on-exit
 */
static inline void arm_v7m_scb_disable_sleep_on_exit(void)
{
    SCB->SCR &= ~SCB_SCR_SLEEPONEXIT_Msk;
}

/*
 * Note: Fault IRQ control functions are provided by arm_v7m_core.h:
 * - arm_v7m_enable_fault()  - Enable fault IRQ (clear FAULTMASK)
 * - arm_v7m_disable_fault() - Disable fault IRQ (set FAULTMASK)
 * 
 * The following aliases are provided for compatibility:
 */
#define arm_v7m_scb_enable_fault_irq  arm_v7m_enable_fault
#define arm_v7m_scb_disable_fault_irq arm_v7m_disable_fault

/*============================================================================*
 * Non-Inline Functions - Complex SCB Operations
 *============================================================================*/

/**
 * @brief Trigger a system reset
 * @note This function does not return if the reset is successful
 */
void arm_v7m_scb_system_reset(void);

/**
 * @brief Set the priority grouping field
 * @param priority_group Priority grouping field (SCB_PRIORITYGROUP_0 to SCB_PRIORITYGROUP_7)
 */
void arm_v7m_scb_set_priority_grouping(uint32_t priority_group);

/**
 * @brief Clear all fault status registers
 */
void arm_v7m_scb_clear_fault_status(void);

/**
 * @brief Get system handler priority
 * @param handler System handler number (0-11 corresponding to SHP array index)
 * @return Priority value (0-255)
 */
uint32_t arm_v7m_scb_get_system_handler_priority(uint32_t handler);

/**
 * @brief Set system handler priority
 * @param handler System handler number (0-11 corresponding to SHP array index)
 * @param priority Priority value (0-255)
 */
void arm_v7m_scb_set_system_handler_priority(uint32_t handler, uint32_t priority);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_SCB_H */
