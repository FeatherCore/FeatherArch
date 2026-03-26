/**
 * @file arm_v8m_cm85_scb.h
 * @brief Cortex-M85 System Control Block (SCB)
 *
 * @note Reference: Arm Cortex-M85 Devices Generic User Guide, Chapter 5.3
 * @note Reference: Arm Cortex-M85 Processor TRM, Chapter 5
 */

#ifndef ARM_V8M_CM85_SCB_H
#define ARM_V8M_CM85_SCB_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SCB register structure */
typedef struct {
    volatile uint32_t CPUID;        /* CPUID Base Register */
    volatile uint32_t ICSR;         /* Interrupt Control and State Register */
    volatile uint32_t VTOR;         /* Vector Table Offset Register */
    volatile uint32_t AIRCR;        /* Application Interrupt and Reset Control Register */
    volatile uint32_t SCR;          /* System Control Register */
    volatile uint32_t CCR;          /* Configuration and Control Register */
    volatile uint32_t SHPR[3];      /* System Handler Priority Registers */
    volatile uint32_t SHCSR;        /* System Handler Control and State Register */
    volatile uint32_t CFSR;         /* Configurable Fault Status Register */
    volatile uint32_t HFSR;         /* HardFault Status Register */
    volatile uint32_t DFSR;         /* Debug Fault Status Register */
    volatile uint32_t MMFAR;        /* MemManage Fault Address Register */
    volatile uint32_t BFAR;         /* BusFault Address Register */
    volatile uint32_t AFSR;         /* Auxiliary Fault Status Register */
    volatile uint32_t ID_PFR[2];    /* Processor Feature Registers */
    volatile uint32_t ID_DFR;       /* Debug Feature Register */
    volatile uint32_t ID_AFR;       /* Auxiliary Feature Register */
    volatile uint32_t ID_MFR[4];    /* Memory Model Feature Registers */
    volatile uint32_t ID_ISAR[5];   /* Instruction Set Attribute Registers */
    uint32_t RESERVED0[1];
    volatile uint32_t CLIDR;        /* Cache Level ID Register */
    volatile uint32_t CTR;          /* Cache Type Register */
    volatile uint32_t CCSIDR;       /* Current Cache Size ID Register */
    volatile uint32_t CSSELR;       /* Cache Size Selection Register */
    volatile uint32_t CPACR;        /* Coprocessor Access Control Register */
    volatile uint32_t NSACR;        /* Non-secure Access Control Register */
} arm_v8m_cm85_scb_reg_t;

#define ARM_V8M_CM85_SCB_BASE       (0xE000ED00UL)
#define ARM_V8M_CM85_SCB            ((arm_v8m_cm85_scb_reg_t *)ARM_V8M_CM85_SCB_BASE)

/* CPUID Register */
#define ARM_V8M_CM85_SCB_CPUID_IMPLEMENTER_Pos      24U
#define ARM_V8M_CM85_SCB_CPUID_IMPLEMENTER_Msk      (0xFFUL << ARM_V8M_CM85_SCB_CPUID_IMPLEMENTER_Pos)
#define ARM_V8M_CM85_SCB_CPUID_VARIANT_Pos          20U
#define ARM_V8M_CM85_SCB_CPUID_VARIANT_Msk          (0xFUL << ARM_V8M_CM85_SCB_CPUID_VARIANT_Pos)
#define ARM_V8M_CM85_SCB_CPUID_ARCHITECTURE_Pos     16U
#define ARM_V8M_CM85_SCB_CPUID_ARCHITECTURE_Msk     (0xFUL << ARM_V8M_CM85_SCB_CPUID_ARCHITECTURE_Pos)
#define ARM_V8M_CM85_SCB_CPUID_PARTNO_Pos           4U
#define ARM_V8M_CM85_SCB_CPUID_PARTNO_Msk           (0xFFFUL << ARM_V8M_CM85_SCB_CPUID_PARTNO_Pos)
#define ARM_V8M_CM85_SCB_CPUID_REVISION_Pos         0U
#define ARM_V8M_CM85_SCB_CPUID_REVISION_Msk         (0xFUL << ARM_V8M_CM85_SCB_CPUID_REVISION_Pos)

/* ICSR Register */
#define ARM_V8M_CM85_SCB_ICSR_NMIPENDSET_Pos        31U
#define ARM_V8M_CM85_SCB_ICSR_NMIPENDSET_Msk        (1UL << ARM_V8M_CM85_SCB_ICSR_NMIPENDSET_Pos)
#define ARM_V8M_CM85_SCB_ICSR_PENDSVSET_Pos         28U
#define ARM_V8M_CM85_SCB_ICSR_PENDSVSET_Msk         (1UL << ARM_V8M_CM85_SCB_ICSR_PENDSVSET_Pos)
#define ARM_V8M_CM85_SCB_ICSR_PENDSVCLR_Pos         27U
#define ARM_V8M_CM85_SCB_ICSR_PENDSVCLR_Msk         (1UL << ARM_V8M_CM85_SCB_ICSR_PENDSVCLR_Pos)
#define ARM_V8M_CM85_SCB_ICSR_PENDSTSET_Pos         26U
#define ARM_V8M_CM85_SCB_ICSR_PENDSTSET_Msk         (1UL << ARM_V8M_CM85_SCB_ICSR_PENDSTSET_Pos)
#define ARM_V8M_CM85_SCB_ICSR_PENDSTCLR_Pos         25U
#define ARM_V8M_CM85_SCB_ICSR_PENDSTCLR_Msk         (1UL << ARM_V8M_CM85_SCB_ICSR_PENDSTCLR_Pos)
#define ARM_V8M_CM85_SCB_ICSR_VECTACTIVE_Pos        0U
#define ARM_V8M_CM85_SCB_ICSR_VECTACTIVE_Msk        (0x1FFUL << ARM_V8M_CM85_SCB_ICSR_VECTACTIVE_Pos)

/* VTOR Register */
#define ARM_V8M_CM85_SCB_VTOR_TBLOFF_Pos            7U
#define ARM_V8M_CM85_SCB_VTOR_TBLOFF_Msk            (0x1FFFFFFUL << ARM_V8M_CM85_SCB_VTOR_TBLOFF_Pos)

/* AIRCR Register */
#define ARM_V8M_CM85_SCB_AIRCR_VECTKEY_Pos          16U
#define ARM_V8M_CM85_SCB_AIRCR_VECTKEY_Msk          (0xFFFFUL << ARM_V8M_CM85_SCB_AIRCR_VECTKEY_Pos)
#define ARM_V8M_CM85_SCB_AIRCR_VECTKEYSTAT_Pos      16U
#define ARM_V8M_CM85_SCB_AIRCR_VECTKEYSTAT_Msk      (0xFFFFUL << ARM_V8M_CM85_SCB_AIRCR_VECTKEYSTAT_Pos)
#define ARM_V8M_CM85_SCB_AIRCR_ENDIANNESS_Pos       15U
#define ARM_V8M_CM85_SCB_AIRCR_ENDIANNESS_Msk       (1UL << ARM_V8M_CM85_SCB_AIRCR_ENDIANNESS_Pos)
#define ARM_V8M_CM85_SCB_AIRCR_PRIS_Pos             14U
#define ARM_V8M_CM85_SCB_AIRCR_PRIS_Msk             (1UL << ARM_V8M_CM85_SCB_AIRCR_PRIS_Pos)
#define ARM_V8M_CM85_SCB_AIRCR_BFHFNMINS_Pos        13U
#define ARM_V8M_CM85_SCB_AIRCR_BFHFNMINS_Msk        (1UL << ARM_V8M_CM85_SCB_AIRCR_BFHFNMINS_Pos)
#define ARM_V8M_CM85_SCB_AIRCR_SYSRESETREQS_Pos     3U
#define ARM_V8M_CM85_SCB_AIRCR_SYSRESETREQS_Msk     (1UL << ARM_V8M_CM85_SCB_AIRCR_SYSRESETREQS_Pos)
#define ARM_V8M_CM85_SCB_AIRCR_SYSRESETREQ_Pos      2U
#define ARM_V8M_CM85_SCB_AIRCR_SYSRESETREQ_Msk      (1UL << ARM_V8M_CM85_SCB_AIRCR_SYSRESETREQ_Pos)
#define ARM_V8M_CM85_SCB_AIRCR_VECTCLRACTIVE_Pos    1U
#define ARM_V8M_CM85_SCB_AIRCR_VECTCLRACTIVE_Msk    (1UL << ARM_V8M_CM85_SCB_AIRCR_VECTCLRACTIVE_Pos)

#define ARM_V8M_CM85_SCB_AIRCR_VECTKEY_VALUE        (0x05FAUL)

/* SCR Register */
#define ARM_V8M_CM85_SCB_SCR_SEVONPEND_Pos          4U
#define ARM_V8M_CM85_SCB_SCR_SEVONPEND_Msk          (1UL << ARM_V8M_CM85_SCB_SCR_SEVONPEND_Pos)
#define ARM_V8M_CM85_SCB_SCR_SLEEPDEEPS_Pos         3U
#define ARM_V8M_CM85_SCB_SCR_SLEEPDEEPS_Msk         (1UL << ARM_V8M_CM85_SCB_SCR_SLEEPDEEPS_Pos)
#define ARM_V8M_CM85_SCB_SCR_SLEEPDEEP_Pos          2U
#define ARM_V8M_CM85_SCB_SCR_SLEEPDEEP_Msk          (1UL << ARM_V8M_CM85_SCB_SCR_SLEEPDEEP_Pos)
#define ARM_V8M_CM85_SCB_SCR_SLEEPONEXIT_Pos        1U
#define ARM_V8M_CM85_SCB_SCR_SLEEPONEXIT_Msk        (1UL << ARM_V8M_CM85_SCB_SCR_SLEEPONEXIT_Pos)

/* CCR Register */
#define ARM_V8M_CM85_SCB_CCR_BP_Pos                 18U
#define ARM_V8M_CM85_SCB_CCR_BP_Msk                 (1UL << ARM_V8M_CM85_SCB_CCR_BP_Pos)
#define ARM_V8M_CM85_SCB_CCR_IC_Pos                 17U
#define ARM_V8M_CM85_SCB_CCR_IC_Msk                 (1UL << ARM_V8M_CM85_SCB_CCR_IC_Pos)
#define ARM_V8M_CM85_SCB_CCR_DC_Pos                 16U
#define ARM_V8M_CM85_SCB_CCR_DC_Msk                 (1UL << ARM_V8M_CM85_SCB_CCR_DC_Pos)
#define ARM_V8M_CM85_SCB_CCR_STKOFHFNMIGN_Pos       10U
#define ARM_V8M_CM85_SCB_CCR_STKOFHFNMIGN_Msk       (1UL << ARM_V8M_CM85_SCB_CCR_STKOFHFNMIGN_Pos)
#define ARM_V8M_CM85_SCB_CCR_BFHFNMIGN_Pos          8U
#define ARM_V8M_CM85_SCB_CCR_BFHFNMIGN_Msk          (1UL << ARM_V8M_CM85_SCB_CCR_BFHFNMIGN_Pos)
#define ARM_V8M_CM85_SCB_CCR_DIV_0_TRP_Pos          4U
#define ARM_V8M_CM85_SCB_CCR_DIV_0_TRP_Msk          (1UL << ARM_V8M_CM85_SCB_CCR_DIV_0_TRP_Pos)
#define ARM_V8M_CM85_SCB_CCR_UNALIGN_TRP_Pos        3U
#define ARM_V8M_CM85_SCB_CCR_UNALIGN_TRP_Msk        (1UL << ARM_V8M_CM85_SCB_CCR_UNALIGN_TRP_Pos)

/* SHCSR Register */
#define ARM_V8M_CM85_SCB_SHCSR_HARDFAULTPENDED_Pos  21U
#define ARM_V8M_CM85_SCB_SHCSR_HARDFAULTPENDED_Msk  (1UL << ARM_V8M_CM85_SCB_SHCSR_HARDFAULTPENDED_Pos)
#define ARM_V8M_CM85_SCB_SHCSR_SECUREFAULTPENDED_Pos 20U
#define ARM_V8M_CM85_SCB_SHCSR_SECUREFAULTPENDED_Msk (1UL << ARM_V8M_CM85_SCB_SHCSR_SECUREFAULTPENDED_Pos)
#define ARM_V8M_CM85_SCB_SHCSR_SECUREFAULTENA_Pos   19U
#define ARM_V8M_CM85_SCB_SHCSR_SECUREFAULTENA_Msk   (1UL << ARM_V8M_CM85_SCB_SHCSR_SECUREFAULTENA_Pos)
#define ARM_V8M_CM85_SCB_SHCSR_USGFAULTENA_Pos      18U
#define ARM_V8M_CM85_SCB_SHCSR_USGFAULTENA_Msk      (1UL << ARM_V8M_CM85_SCB_SHCSR_USGFAULTENA_Pos)
#define ARM_V8M_CM85_SCB_SHCSR_BUSFAULTENA_Pos      17U
#define ARM_V8M_CM85_SCB_SHCSR_BUSFAULTENA_Msk      (1UL << ARM_V8M_CM85_SCB_SHCSR_BUSFAULTENA_Pos)
#define ARM_V8M_CM85_SCB_SHCSR_MEMFAULTENA_Pos      16U
#define ARM_V8M_CM85_SCB_SHCSR_MEMFAULTENA_Msk      (1UL << ARM_V8M_CM85_SCB_SHCSR_MEMFAULTENA_Pos)
#define ARM_V8M_CM85_SCB_SHCSR_SVCALLPENDED_Pos     15U
#define ARM_V8M_CM85_SCB_SHCSR_SVCALLPENDED_Msk     (1UL << ARM_V8M_CM85_SCB_SHCSR_SVCALLPENDED_Pos)
#define ARM_V8M_CM85_SCB_SHCSR_BUSFAULTPENDED_Pos   14U
#define ARM_V8M_CM85_SCB_SHCSR_BUSFAULTPENDED_Msk   (1UL << ARM_V8M_CM85_SCB_SHCSR_BUSFAULTPENDED_Pos)
#define ARM_V8M_CM85_SCB_SHCSR_MEMFAULTPENDED_Pos   13U
#define ARM_V8M_CM85_SCB_SHCSR_MEMFAULTPENDED_Msk   (1UL << ARM_V8M_CM85_SCB_SHCSR_MEMFAULTPENDED_Pos)
#define ARM_V8M_CM85_SCB_SHCSR_USGFAULTPENDED_Pos   12U
#define ARM_V8M_CM85_SCB_SHCSR_USGFAULTPENDED_Msk   (1UL << ARM_V8M_CM85_SCB_SHCSR_USGFAULTPENDED_Pos)
#define ARM_V8M_CM85_SCB_SHCSR_SYSTICKACT_Pos       11U
#define ARM_V8M_CM85_SCB_SHCSR_SYSTICKACT_Msk       (1UL << ARM_V8M_CM85_SCB_SHCSR_SYSTICKACT_Pos)
#define ARM_V8M_CM85_SCB_SHCSR_PENDSVACT_Pos        10U
#define ARM_V8M_CM85_SCB_SHCSR_PENDSVACT_Msk        (1UL << ARM_V8M_CM85_SCB_SHCSR_PENDSVACT_Pos)
#define ARM_V8M_CM85_SCB_SHCSR_MONITORACT_Pos       8U
#define ARM_V8M_CM85_SCB_SHCSR_MONITORACT_Msk       (1UL << ARM_V8M_CM85_SCB_SHCSR_MONITORACT_Pos)
#define ARM_V8M_CM85_SCB_SHCSR_SVCALLACT_Pos        7U
#define ARM_V8M_CM85_SCB_SHCSR_SVCALLACT_Msk        (1UL << ARM_V8M_CM85_SCB_SHCSR_SVCALLACT_Pos)
#define ARM_V8M_CM85_SCB_SHCSR_NMIACT_Pos           5U
#define ARM_V8M_CM85_SCB_SHCSR_NMIACT_Msk           (1UL << ARM_V8M_CM85_SCB_SHCSR_NMIACT_Pos)
#define ARM_V8M_CM85_SCB_SHCSR_SECUREFAULTACT_Pos   4U
#define ARM_V8M_CM85_SCB_SHCSR_SECUREFAULTACT_Msk   (1UL << ARM_V8M_CM85_SCB_SHCSR_SECUREFAULTACT_Pos)
#define ARM_V8M_CM85_SCB_SHCSR_USGFAULTACT_Pos      3U
#define ARM_V8M_CM85_SCB_SHCSR_USGFAULTACT_Msk      (1UL << ARM_V8M_CM85_SCB_SHCSR_USGFAULTACT_Pos)
#define ARM_V8M_CM85_SCB_SHCSR_HARDFAULTACT_Pos     2U
#define ARM_V8M_CM85_SCB_SHCSR_HARDFAULTACT_Msk     (1UL << ARM_V8M_CM85_SCB_SHCSR_HARDFAULTACT_Pos)
#define ARM_V8M_CM85_SCB_SHCSR_BUSFAULTACT_Pos      1U
#define ARM_V8M_CM85_SCB_SHCSR_BUSFAULTACT_Msk      (1UL << ARM_V8M_CM85_SCB_SHCSR_BUSFAULTACT_Pos)
#define ARM_V8M_CM85_SCB_SHCSR_MEMFAULTACT_Pos      0U
#define ARM_V8M_CM85_SCB_SHCSR_MEMFAULTACT_Msk      (1UL << ARM_V8M_CM85_SCB_SHCSR_MEMFAULTACT_Pos)

/* CFSR Register - Combined MemManage, BusFault, UsageFault */
#define ARM_V8M_CM85_SCB_CFSR_MMFSR_Pos             0U
#define ARM_V8M_CM85_SCB_CFSR_MMFSR_Msk             (0xFFUL << ARM_V8M_CM85_SCB_CFSR_MMFSR_Pos)
#define ARM_V8M_CM85_SCB_CFSR_BFSR_Pos              8U
#define ARM_V8M_CM85_SCB_CFSR_BFSR_Msk              (0xFFUL << ARM_V8M_CM85_SCB_CFSR_BFSR_Pos)
#define ARM_V8M_CM85_SCB_CFSR_UFSR_Pos              16U
#define ARM_V8M_CM85_SCB_CFSR_UFSR_Msk              (0xFFFFUL << ARM_V8M_CM85_SCB_CFSR_UFSR_Pos)

/* HFSR Register */
#define ARM_V8M_CM85_SCB_HFSR_DEBUGEVT_Pos          31U
#define ARM_V8M_CM85_SCB_HFSR_DEBUGEVT_Msk          (1UL << ARM_V8M_CM85_SCB_HFSR_DEBUGEVT_Pos)
#define ARM_V8M_CM85_SCB_HFSR_FORCED_Pos            30U
#define ARM_V8M_CM85_SCB_HFSR_FORCED_Msk            (1UL << ARM_V8M_CM85_SCB_HFSR_FORCED_Pos)
#define ARM_V8M_CM85_SCB_HFSR_VECTTBL_Pos           1U
#define ARM_V8M_CM85_SCB_HFSR_VECTTBL_Msk           (1UL << ARM_V8M_CM85_SCB_HFSR_VECTTBL_Pos)

/* SCB API functions */
uint32_t arm_v8m_cm85_scb_get_cpuid(void);
void arm_v8m_cm85_scb_set_vtor(uint32_t offset);
uint32_t arm_v8m_cm85_scb_get_vtor(void);
void arm_v8m_cm85_scb_system_reset(void);
void arm_v8m_cm85_scb_system_reset_secure(void);

/* ICSR operations */
void arm_v8m_cm85_scb_set_pendsv(void);
void arm_v8m_cm85_scb_clear_pendsv(void);
void arm_v8m_cm85_scb_set_nmi(void);
uint32_t arm_v8m_cm85_scb_get_vectactive(void);

/* Sleep mode configuration */
typedef enum {
    ARM_V8M_CM85_SCB_SLEEPMODE_SLEEP = 0,
    ARM_V8M_CM85_SCB_SLEEPMODE_DEEPSLEEP = 1
} arm_v8m_cm85_scb_sleepmode_t;

void arm_v8m_cm85_scb_set_sleepmode(arm_v8m_cm85_scb_sleepmode_t mode);
void arm_v8m_cm85_scb_enable_sleeponexit(void);
void arm_v8m_cm85_scb_disable_sleeponexit(void);
void arm_v8m_cm85_scb_enable_sevonpend(void);
void arm_v8m_cm85_scb_disable_sevonpend(void);

/* Fault handling */
void arm_v8m_cm85_scb_enable_faults(void);
void arm_v8m_cm85_scb_disable_faults(void);
uint32_t arm_v8m_cm85_scb_get_fault_status(void);
void arm_v8m_cm85_scb_clear_fault_status(uint32_t mask);
uint32_t arm_v8m_cm85_scb_get_hardfault_status(void);
void arm_v8m_cm85_scb_clear_hardfault_status(uint32_t mask);
uint32_t arm_v8m_cm85_scb_get_mmfar(void);
uint32_t arm_v8m_cm85_scb_get_bfar(void);

/* Feature identification */
bool arm_v8m_cm85_scb_has_fpu(void);
bool arm_v8m_cm85_scb_has_mve(void);
bool arm_v8m_cm85_scb_has_dsp(void);
bool arm_v8m_cm85_scb_has_security(void);
bool arm_v8m_cm85_scb_has_mpu(void);
bool arm_v8m_cm85_scb_has_cache(void);

/* Cache control via SCB CCR */
void arm_v8m_cm85_scb_enable_icache(void);
void arm_v8m_cm85_scb_disable_icache(void);
void arm_v8m_cm85_scb_enable_dcache(void);
void arm_v8m_cm85_scb_disable_dcache(void);
void arm_v8m_cm85_scb_enable_branch_prediction(void);
void arm_v8m_cm85_scb_disable_branch_prediction(void);

/* Coprocessor access control */
void arm_v8m_cm85_scb_set_cpacr(uint32_t value);
uint32_t arm_v8m_cm85_scb_get_cpacr(void);
void arm_v8m_cm85_scb_enable_coproc(uint32_t cp);
void arm_v8m_cm85_scb_disable_coproc(uint32_t cp);

#ifdef __ARM_FEATURE_CMSE
void arm_v8m_cm85_scb_set_nsacr(uint32_t value);
uint32_t arm_v8m_cm85_scb_get_nsacr(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM85_SCB_H */
