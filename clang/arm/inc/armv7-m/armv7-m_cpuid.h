/*
 * ARM Architecture - ARMv7-M CPUID Registers
 *
 * ============================================================================
 * File: armv7-m_cpuid.h
 * Description: ARMv7-M CPUID register definitions
 * 描述: ARMv7-M CPUID 寄存器定义
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B4: The CPUID Scheme
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_CPUID_H__
#define __ARCH_ARM_V7M_CPUID_H__

#include <stdint.h>
#include "armv7-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * CPUID Base Register (CPUID)
 * Address: 0xE000ED00
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-598
 * ============================================================================
 */

#define SCB_CPUID                 (*(volatile uint32_t *)(0xE000ED00UL))

/* CPUID Register Bit Definitions */
#define CPUID_IMPLEMENTER_Pos     24U
#define CPUID_IMPLEMENTER_Msk     (0xFFUL << CPUID_IMPLEMENTER_Pos)
#define CPUID_VARIANT_Pos         20U
#define CPUID_VARIANT_Msk         (0xFUL << CPUID_VARIANT_Pos)
#define CPUID_ARCHITECTURE_Pos    16U
#define CPUID_ARCHITECTURE_Msk    (0xFUL << CPUID_ARCHITECTURE_Pos)
#define CPUID_PARTNO_Pos          4U
#define CPUID_PARTNO_Msk          (0xFFFUL << CPUID_PARTNO_Pos)
#define CPUID_REVISION_Pos        0U
#define CPUID_REVISION_Msk        (0xFUL << CPUID_REVISION_Pos)

/* Implementer Codes */
#define CPUID_IMPLEMENTER_ARM     0x41U

/* Architecture Codes */
#define CPUID_ARCHITECTURE_ARMV7M 0xFU

/*
 * ============================================================================
 * Processor Feature ID Registers (ID_PFR0, ID_PFR1)
 * Address: 0xE000ED40, 0xE000ED44
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-646
 * ============================================================================
 */

#define SCB_ID_PFR0               (*(volatile uint32_t *)(0xE000ED40UL))
#define SCB_ID_PFR1               (*(volatile uint32_t *)(0xE000ED44UL))

/* ID_PFR0 Bit Definitions */
#define ID_PFR0_STATE0_Pos        0U
#define ID_PFR0_STATE0_Msk        (0xFUL << ID_PFR0_STATE0_Pos)
#define ID_PFR0_STATE1_Pos        4U
#define ID_PFR0_STATE1_Msk        (0xFUL << ID_PFR0_STATE1_Pos)
#define ID_PFR0_STATE2_Pos        8U
#define ID_PFR0_STATE2_Msk        (0xFUL << ID_PFR0_STATE2_Pos)
#define ID_PFR0_STATE3_Pos        12U
#define ID_PFR0_STATE3_Msk        (0xFUL << ID_PFR0_STATE3_Pos)

/* ID_PFR1 Bit Definitions */
#define ID_PFR1_PROGMOD_Pos       0U
#define ID_PFR1_PROGMOD_Msk       (0xFUL << ID_PFR1_PROGMOD_Pos)
#define ID_PFR1_SECURITY_Pos      4U
#define ID_PFR1_SECURITY_Msk      (0xFUL << ID_PFR1_SECURITY_Pos)
#define ID_PFR1_MPROGMOD_Pos      8U
#define ID_PFR1_MPROGMOD_Msk      (0xFUL << ID_PFR1_MPROGMOD_Pos)

/*
 * ============================================================================
 * Debug Feature ID Register (ID_DFR0)
 * Address: 0xE000ED48
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-648
 * ============================================================================
 */

#define SCB_ID_DFR0               (*(volatile uint32_t *)(0xE000ED48UL))

/* ID_DFR0 Bit Definitions */
#define ID_DFR0_DEBUGMODEL_Pos    0U
#define ID_DFR0_DEBUGMODEL_Msk    (0xFUL << ID_DFR0_DEBUGMODEL_Pos)

/*
 * ============================================================================
 * Auxiliary Feature ID Register (ID_AFR0)
 * Address: 0xE000ED4C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-649
 * ============================================================================
 */

#define SCB_ID_AFR0               (*(volatile uint32_t *)(0xE000ED4CUL))

/* ID_AFR0 Bit Definitions */
#define ID_AFR0_IMPDEF0_Pos       0U
#define ID_AFR0_IMPDEF0_Msk       (0xFUL << ID_AFR0_IMPDEF0_Pos)
#define ID_AFR0_IMPDEF1_Pos       4U
#define ID_AFR0_IMPDEF1_Msk       (0xFUL << ID_AFR0_IMPDEF1_Pos)
#define ID_AFR0_IMPDEF2_Pos       8U
#define ID_AFR0_IMPDEF2_Msk       (0xFUL << ID_AFR0_IMPDEF2_Pos)
#define ID_AFR0_IMPDEF3_Pos       12U
#define ID_AFR0_IMPDEF3_Msk       (0xFUL << ID_AFR0_IMPDEF3_Pos)

/*
 * ============================================================================
 * Memory Model Feature Registers (ID_MMFR0-3)
 * Address: 0xE000ED50-0xE000ED5C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-650
 * ============================================================================
 */

#define SCB_ID_MMFR0              (*(volatile uint32_t *)(0xE000ED50UL))
#define SCB_ID_MMFR1              (*(volatile uint32_t *)(0xE000ED54UL))
#define SCB_ID_MMFR2              (*(volatile uint32_t *)(0xE000ED58UL))
#define SCB_ID_MMFR3              (*(volatile uint32_t *)(0xE000ED5CUL))

/* ID_MMFR0 Bit Definitions */
#define ID_MMFR0_VMSA_Pos         0U
#define ID_MMFR0_VMSA_Msk         (0xFUL << ID_MMFR0_VMSA_Pos)
#define ID_MMFR0_PMSA_Pos         4U
#define ID_MMFR0_PMSA_Msk         (0xFUL << ID_MMFR0_PMSA_Pos)
#define ID_MMFR0_CACHE_Pos        8U
#define ID_MMFR0_CACHE_Msk        (0xFUL << ID_MMFR0_CACHE_Pos)
#define ID_MMFR0_OUTERSHR_Pos     12U
#define ID_MMFR0_OUTERSHR_Msk     (0xFUL << ID_MMFR0_OUTERSHR_Pos)
#define ID_MMFR0_SHRVEC_Pos       16U
#define ID_MMFR0_SHRVEC_Msk       (0xFUL << ID_MMFR0_SHRVEC_Pos)
#define ID_MMFR0_TCM_Pos          20U
#define ID_MMFR0_TCM_Msk          (0xFUL << ID_MMFR0_TCM_Pos)
#define ID_MMFR0_AUXREG_Pos       24U
#define ID_MMFR0_AUXREG_Msk       (0xFUL << ID_MMFR0_AUXREG_Pos)
#define ID_MMFR0_FCSE_Pos         28U
#define ID_MMFR0_FCSE_Msk         (0xFUL << ID_MMFR0_FCSE_Pos)

/* ID_MMFR1 Bit Definitions */
#define ID_MMFR1_L1VA_Pos         0U
#define ID_MMFR1_L1VA_Msk         (0xFUL << ID_MMFR1_L1VA_Pos)
#define ID_MMFR1_L1UNI_Pos        4U
#define ID_MMFR1_L1UNI_Msk        (0xFUL << ID_MMFR1_L1UNI_Pos)
#define ID_MMFR1_L1HARV_Pos       8U
#define ID_MMFR1_L1HARV_Msk       (0xFUL << ID_MMFR1_L1HARV_Pos)
#define ID_MMFR1_L1MAINT_Pos      12U
#define ID_MMFR1_L1MAINT_Msk      (0xFUL << ID_MMFR1_L1MAINT_Pos)

/* ID_MMFR2 Bit Definitions */
#define ID_MMFR2_WFISTALL_Pos     0U
#define ID_MMFR2_WFISTALL_Msk     (0xFUL << ID_MMFR2_WFISTALL_Pos)
#define ID_MMFR2_WAIT_Pos         4U
#define ID_MMFR2_WAIT_Msk         (0xFUL << ID_MMFR2_WAIT_Pos)
#define ID_MMFR2_MEMBARRIER_Pos   8U
#define ID_MMFR2_MEMBARRIER_Msk   (0xFUL << ID_MMFR2_MEMBARRIER_Pos)
#define ID_MMFR2_UNIICTL_Pos      12U
#define ID_MMFR2_UNIICTL_Msk      (0xFUL << ID_MMFR2_UNIICTL_Pos)
#define ID_MMFR2_REGBIT_Pos       16U
#define ID_MMFR2_REGBIT_Msk       (0xFUL << ID_MMFR2_REGBIT_Pos)
#define ID_MMFR2_DLOAD_Pos        20U
#define ID_MMFR2_DLOAD_Msk        (0xFUL << ID_MMFR2_DLOAD_Pos)
#define ID_MMFR2_DSTORE_Pos       24U
#define ID_MMFR2_DSTORE_Msk       (0xFUL << ID_MMFR2_DSTORE_Pos)
#define ID_MMFR2_IINST_Pos        28U
#define ID_MMFR2_IINST_Msk        (0xFUL << ID_MMFR2_IINST_Pos)

/* ID_MMFR3 Bit Definitions */
#define ID_MMFR3_BASELINE_Pos     0U
#define ID_MMFR3_BASELINE_Msk     (0xFUL << ID_MMFR3_BASELINE_Pos)
#define ID_MMFR3_PROFCLUST_Pos    4U
#define ID_MMFR3_PROFCLUST_Msk    (0xFUL << ID_MMFR3_PROFCLUST_Pos)
#define ID_MMFR3_OVERRANGE_Pos    8U
#define ID_MMFR3_OVERRANGE_Msk    (0xFUL << ID_MMFR3_OVERRANGE_Pos)
#define ID_MMFR3_SYNCHPRIM_Pos    12U
#define ID_MMFR3_SYNCHPRIM_Msk    (0xFUL << ID_MMFR3_SYNCHPRIM_Pos)
#define ID_MMFR3_PMSA_Pos         16U
#define ID_MMFR3_PMSA_Msk         (0xFUL << ID_MMFR3_PMSA_Pos)
#define ID_MMFR3_CACHEMAINT_Pos   20U
#define ID_MMFR3_CACHEMAINT_Msk   (0xFUL << ID_MMFR3_CACHEMAINT_Pos)
#define ID_MMFR3_CMAINTVA_Pos     24U
#define ID_MMFR3_CMAINTVA_Msk     (0xFUL << ID_MMFR3_CMAINTVA_Pos)
#define ID_MMFR3_CMAINTSW_Pos     28U
#define ID_MMFR3_CMAINTSW_Msk     (0xFUL << ID_MMFR3_CMAINTSW_Pos)

/*
 * ============================================================================
 * Instruction Set Attribute Registers (ID_ISAR0-4)
 * Address: 0xE000ED60-0xE000ED70
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-653
 * ============================================================================
 */

#define SCB_ID_ISAR0              (*(volatile uint32_t *)(0xE000ED60UL))
#define SCB_ID_ISAR1              (*(volatile uint32_t *)(0xE000ED64UL))
#define SCB_ID_ISAR2              (*(volatile uint32_t *)(0xE000ED68UL))
#define SCB_ID_ISAR3              (*(volatile uint32_t *)(0xE000ED6CUL))
#define SCB_ID_ISAR4              (*(volatile uint32_t *)(0xE000ED70UL))

/* ID_ISAR0 Bit Definitions */
#define ID_ISAR0_SWAP_Pos         0U
#define ID_ISAR0_SWAP_Msk         (0xFUL << ID_ISAR0_SWAP_Pos)
#define ID_ISAR0_BITCOUNT_Pos     4U
#define ID_ISAR0_BITCOUNT_Msk     (0xFUL << ID_ISAR0_BITCOUNT_Pos)
#define ID_ISAR0_BITFIELD_Pos     8U
#define ID_ISAR0_BITFIELD_Msk     (0xFUL << ID_ISAR0_BITFIELD_Pos)
#define ID_ISAR0_CMPBRANCH_Pos    12U
#define ID_ISAR0_CMPBRANCH_Msk    (0xFUL << ID_ISAR0_CMPBRANCH_Pos)
#define ID_ISAR0_COPROC_Pos       16U
#define ID_ISAR0_COPROC_Msk       (0xFUL << ID_ISAR0_COPROC_Pos)
#define ID_ISAR0_DEBUG_Pos        20U
#define ID_ISAR0_DEBUG_Msk        (0xFUL << ID_ISAR0_DEBUG_Pos)
#define ID_ISAR0_DIVIDE_Pos       24U
#define ID_ISAR0_DIVIDE_Msk       (0xFUL << ID_ISAR0_DIVIDE_Pos)

/* ID_ISAR1 Bit Definitions */
#define ID_ISAR1_ENDIAN_Pos       0U
#define ID_ISAR1_ENDIAN_Msk       (0xFUL << ID_ISAR1_ENDIAN_Pos)
#define ID_ISAR1_EXCEPT_Pos       4U
#define ID_ISAR1_EXCEPT_Msk       (0xFUL << ID_ISAR1_EXCEPT_Pos)
#define ID_ISAR1_EXCEPT_AR_Pos    8U
#define ID_ISAR1_EXCEPT_AR_Msk    (0xFUL << ID_ISAR1_EXCEPT_AR_Pos)
#define ID_ISAR1_EXTEND_Pos       12U
#define ID_ISAR1_EXTEND_Msk       (0xFUL << ID_ISAR1_EXTEND_Pos)
#define ID_ISAR1_IFTHEN_Pos       16U
#define ID_ISAR1_IFTHEN_Msk       (0xFUL << ID_ISAR1_IFTHEN_Pos)
#define ID_ISAR1_IMMEDIATE_Pos    20U
#define ID_ISAR1_IMMEDIATE_Msk    (0xFUL << ID_ISAR1_IMMEDIATE_Pos)
#define ID_ISAR1_INTERWORK_Pos    24U
#define ID_ISAR1_INTERWORK_Msk    (0xFUL << ID_ISAR1_INTERWORK_Pos)
#define ID_ISAR1_JAZELLE_Pos      28U
#define ID_ISAR1_JAZELLE_Msk      (0xFUL << ID_ISAR1_JAZELLE_Pos)

/* ID_ISAR2 Bit Definitions */
#define ID_ISAR2_LOADSTORE_Pos    0U
#define ID_ISAR2_LOADSTORE_Msk    (0xFUL << ID_ISAR2_LOADSTORE_Pos)
#define ID_ISAR2_MEMHINT_Pos      4U
#define ID_ISAR2_MEMHINT_Msk      (0xFUL << ID_ISAR2_MEMHINT_Pos)
#define ID_ISAR2_MULTIACCESSINT_Pos 8U
#define ID_ISAR2_MULTIACCESSINT_Msk (0xFUL << ID_ISAR2_MULTIACCESSINT_Pos)
#define ID_ISAR2_MULT_Pos         12U
#define ID_ISAR2_MULT_Msk         (0xFUL << ID_ISAR2_MULT_Pos)
#define ID_ISAR2_MULTS_Pos        16U
#define ID_ISAR2_MULTS_Msk        (0xFUL << ID_ISAR2_MULTS_Pos)
#define ID_ISAR2_MULTU_Pos        20U
#define ID_ISAR2_MULTU_Msk        (0xFUL << ID_ISAR2_MULTU_Pos)
#define ID_ISAR2_PSR_AR_Pos       24U
#define ID_ISAR2_PSR_AR_Msk       (0xFUL << ID_ISAR2_PSR_AR_Pos)
#define ID_ISAR2_REVERSE_Pos      28U
#define ID_ISAR2_REVERSE_Msk      (0xFUL << ID_ISAR2_REVERSE_Pos)

/* ID_ISAR3 Bit Definitions */
#define ID_ISAR3_SATURATE_Pos     0U
#define ID_ISAR3_SATURATE_Msk     (0xFUL << ID_ISAR3_SATURATE_Pos)
#define ID_ISAR3_SIMD_Pos         4U
#define ID_ISAR3_SIMD_Msk         (0xFUL << ID_ISAR3_SIMD_Pos)
#define ID_ISAR3_SVC_Pos          8U
#define ID_ISAR3_SVC_Msk          (0xFUL << ID_ISAR3_SVC_Pos)
#define ID_ISAR3_SYNCHPRIM_Pos    12U
#define ID_ISAR3_SYNCHPRIM_Msk    (0xFUL << ID_ISAR3_SYNCHPRIM_Pos)
#define ID_ISAR3_TABBRANCH_Pos    16U
#define ID_ISAR3_TABBRANCH_Msk    (0xFUL << ID_ISAR3_TABBRANCH_Pos)
#define ID_ISAR3_THUMBCOPROC_Pos  20U
#define ID_ISAR3_THUMBCOPROC_Msk  (0xFUL << ID_ISAR3_THUMBCOPROC_Pos)
#define ID_ISAR3_TRUENOP_Pos      24U
#define ID_ISAR3_TRUENOP_Msk      (0xFUL << ID_ISAR3_TRUENOP_Pos)
#define ID_ISAR3_T32EXC_Pos       28U
#define ID_ISAR3_T32EXC_Msk       (0xFUL << ID_ISAR3_T32EXC_Pos)

/* ID_ISAR4 Bit Definitions */
#define ID_ISAR4_UNPRIV_Pos       0U
#define ID_ISAR4_UNPRIV_Msk       (0xFUL << ID_ISAR4_UNPRIV_Pos)
#define ID_ISAR4_WITHSHIFTS_Pos   4U
#define ID_ISAR4_WITHSHIFTS_Msk   (0xFUL << ID_ISAR4_WITHSHIFTS_Pos)
#define ID_ISAR4_WRITEBACK_Pos    8U
#define ID_ISAR4_WRITEBACK_Msk    (0xFUL << ID_ISAR4_WRITEBACK_Pos)
#define ID_ISAR4_SMC_Pos          12U
#define ID_ISAR4_SMC_Msk          (0xFUL << ID_ISAR4_SMC_Pos)
#define ID_ISAR4_BARRIER_Pos      16U
#define ID_ISAR4_BARRIER_Msk      (0xFUL << ID_ISAR4_BARRIER_Pos)
#define ID_ISAR4_SYNCHPRIM_FRAC_Pos 20U
#define ID_ISAR4_SYNCHPRIM_FRAC_Msk (0xFUL << ID_ISAR4_SYNCHPRIM_FRAC_Pos)
#define ID_ISAR4_PSR_M_Pos        24U
#define ID_ISAR4_PSR_M_Msk        (0xFUL << ID_ISAR4_PSR_M_Pos)

/*
 * ============================================================================
 * Cache Control Identification Registers
 * Address: 0xE000ED78-0xE000ED84
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-665
 * ============================================================================
 */

#define SCB_CLIDR                 (*(volatile uint32_t *)(0xE000ED78UL))
#define SCB_CTR                   (*(volatile uint32_t *)(0xE000ED7CUL))
#define SCB_CCSIDR                (*(volatile uint32_t *)(0xE000ED80UL))
#define SCB_CSSELR                (*(volatile uint32_t *)(0xE000ED84UL))

/* CLIDR Bit Definitions */
#define CLIDR_ICB_Pos             0U
#define CLIDR_ICB_Msk             (0x7UL << CLIDR_ICB_Pos)
#define CLIDR_DCB_Pos             3U
#define CLIDR_DCB_Msk             (0x7UL << CLIDR_DCB_Pos)
#define CLIDR_LOUU_Pos            27U
#define CLIDR_LOUU_Msk            (0x7UL << CLIDR_LOUU_Pos)
#define CLIDR_LOC_Pos             24U
#define CLIDR_LOC_Msk             (0x7UL << CLIDR_LOC_Pos)

/* CTR Bit Definitions */
#define CTR_IMINLINE_Pos          0U
#define CTR_IMINLINE_Msk          (0xFUL << CTR_IMINLINE_Pos)
#define CTR_L1IP_Pos              14U
#define CTR_L1IP_Msk              (0x3UL << CTR_L1IP_Pos)
#define CTR_DMINLINE_Pos          16U
#define CTR_DMINLINE_Msk          (0xFUL << CTR_DMINLINE_Pos)
#define CTR_ERG_Pos               20U
#define CTR_ERG_Msk               (0xFUL << CTR_ERG_Pos)
#define CTR_CWG_Pos               24U
#define CTR_CWG_Msk               (0xFUL << CTR_CWG_Pos)
#define CTR_FORMAT_Pos            29U
#define CTR_FORMAT_Msk            (0x7UL << CTR_FORMAT_Pos)

/* CCSIDR Bit Definitions */
#define CCSIDR_LINESIZE_Pos       0U
#define CCSIDR_LINESIZE_Msk       (0x7UL << CCSIDR_LINESIZE_Pos)
#define CCSIDR_ASSOCIATIVITY_Pos  3U
#define CCSIDR_ASSOCIATIVITY_Msk  (0x3FFUL << CCSIDR_ASSOCIATIVITY_Pos)
#define CCSIDR_NUMSETS_Pos        13U
#define CCSIDR_NUMSETS_Msk        (0x7FFFUL << CCSIDR_NUMSETS_Pos)
#define CCSIDR_WA_Pos             28U
#define CCSIDR_WA_Msk             (1UL << CCSIDR_WA_Pos)
#define CCSIDR_RA_Pos             29U
#define CCSIDR_RA_Msk             (1UL << CCSIDR_RA_Pos)
#define CCSIDR_WB_Pos             30U
#define CCSIDR_WB_Msk             (1UL << CCSIDR_WB_Pos)
#define CCSIDR_WT_Pos             31U
#define CCSIDR_WT_Msk             (1UL << CCSIDR_WT_Pos)

/* CSSELR Bit Definitions */
#define CSSELR_IND_Pos            0U
#define CSSELR_IND_Msk            (1UL << CSSELR_IND_Pos)
#define CSSELR_LEVEL_Pos          1U
#define CSSELR_LEVEL_Msk          (0x7UL << CSSELR_LEVEL_Pos)

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Get CPUID register value
 * @return CPUID value
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-598
 */
static inline uint32_t cpuid_get(void)
{
    return SCB_CPUID;
}

/**
 * @brief Get implementer code
 * @return Implementer code (0x41 for ARM)
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-598
 */
static inline uint32_t cpuid_get_implementer(void)
{
    return (SCB_CPUID & CPUID_IMPLEMENTER_Msk) >> CPUID_IMPLEMENTER_Pos;
}

/**
 * @brief Get variant number
 * @return Variant number
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-598
 */
static inline uint32_t cpuid_get_variant(void)
{
    return (SCB_CPUID & CPUID_VARIANT_Msk) >> CPUID_VARIANT_Pos;
}

/**
 * @brief Get architecture code
 * @return Architecture code (0xF for ARMv7-M)
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-598
 */
static inline uint32_t cpuid_get_architecture(void)
{
    return (SCB_CPUID & CPUID_ARCHITECTURE_Msk) >> CPUID_ARCHITECTURE_Pos;
}

/**
 * @brief Get part number
 * @return Part number
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-598
 */
static inline uint32_t cpuid_get_partno(void)
{
    return (SCB_CPUID & CPUID_PARTNO_Msk) >> CPUID_PARTNO_Pos;
}

/**
 * @brief Get revision number
 * @return Revision number
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-598
 */
static inline uint32_t cpuid_get_revision(void)
{
    return (SCB_CPUID & CPUID_REVISION_Msk) >> CPUID_REVISION_Pos;
}

/**
 * @brief Check if processor is ARM implementation
 * @return 1 if ARM, 0 otherwise
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-598
 */
static inline int cpuid_is_arm(void)
{
    return cpuid_get_implementer() == CPUID_IMPLEMENTER_ARM;
}

/**
 * @brief Check if architecture is ARMv7-M
 * @return 1 if ARMv7-M, 0 otherwise
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-598
 */
static inline int cpuid_is_armv7m(void)
{
    return cpuid_get_architecture() == CPUID_ARCHITECTURE_ARMV7M;
}

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_CPUID_H__ */
