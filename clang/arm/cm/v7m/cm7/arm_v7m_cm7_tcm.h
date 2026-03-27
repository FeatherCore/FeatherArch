/*
 * arm_v7m_cm7_tcm.h
 * Cortex-M7 Tightly-Coupled Memory (TCM) Definitions
 * 
 * Reference: Cortex-M7 Devices Generic User Guide
 *            - Chapter 4.9: Access control on page 4-66
 *            - Section 4.9.1: Instruction and Data Tightly-Coupled Memory Control Registers on page 4-67
 *              * ITCMCR at address 0xE000EF90
 *              * DTCMCR at address 0xE000EF94
 *            - Section 4.9.2: AHBP Control Register on page 4-69
 *              * AHBPCR at address 0xE000EF98
 *            - Section 4.9.3: L1 Cache Control Register on page 4-70
 *              * CACR at address 0xE000EF9C
 *            - Section 4.9.4: AHB Slave Control Register on page 4-72
 *              * AHBSCR at address 0xE000EFA0
 *            - Section 4.9.5: Auxiliary Bus Fault Status register on page 4-73
 *              * ABFSR at address 0xE000EFA8
 * 
 *            Cortex-M7 Technical Reference Manual
 *            - Chapter 5.8: TCM interfaces on page 5-36
 *            - Section 4.1.5: Enabling the TCM on page 4-5
 *            - Section 1.3.6: TCM interface on page 1-11
 * 
 *            ARMv7-M Architecture Reference Manual
 *            - Section B3.2.15: Coprocessor Access Control Register, CPACR on page B3-614
 *            - Table B3-4: SCB registers summary (0xE000EF90-0xE000EFCF marked as IMPLEMENTATION DEFINED)
 * 
 * @note TCM is Cortex-M7 specific and not part of the base ARMv7-M architecture.
 *       The address range 0xE000EF90-0xE000EFCF is IMPLEMENTATION DEFINED in ARMv7-M.
 */

#ifndef ARM_V7M_CM7_TCM_H
#define ARM_V7M_CM7_TCM_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Compiler Abstraction - Inline Definition
 *============================================================================*/

#if defined(__clang__)
    #define ARM_V7M_CM7_TCM_INLINE static inline __attribute__((always_inline))
#else
    #error "This library requires Clang/LLVM compiler."
#endif

/*============================================================================*
 * TCM Base Address
 * Reference: Cortex-M7 Devices Generic User Guide, Table 4-68 on page 4-66
 *============================================================================*/

#define ARM_V7M_CM7_TCM_BASE            0xE000EF90UL

/*============================================================================*
 * TCM Control Register Type Definitions
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9 on page 4-66
 *============================================================================*/

typedef struct {
    volatile uint32_t ITCMCR;           /*!< Offset: 0x00 (R/W)  Instruction TCM Control Register */
    volatile uint32_t DTCMCR;           /*!< Offset: 0x04 (R/W)  Data TCM Control Register */
    volatile uint32_t AHBPCR;           /*!< Offset: 0x08 (R/W)  AHBP Control Register */
    volatile uint32_t CACR;             /*!< Offset: 0x0C (R/W)  L1 Cache Control Register */
    volatile uint32_t AHBSCR;           /*!< Offset: 0x10 (R/W)  AHB Slave Control Register */
    volatile uint32_t RESERVED0;        /*!< Offset: 0x14        Reserved */
    volatile uint32_t ABFSR;            /*!< Offset: 0x18 (R/W)  Auxiliary Bus Fault Status Register */
} arm_v7m_cm7_tcm_regs_t;

#define ARM_V7M_CM7_TCM                 ((arm_v7m_cm7_tcm_regs_t *)ARM_V7M_CM7_TCM_BASE)

/*============================================================================*
 * ITCMCR Bit Definitions
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.1 on page 4-67
 *            Table 4-69: ITCMCR and DTCMCR bit assignments
 *============================================================================*/

#define ARM_V7M_CM7_ITCMCR_EN_Pos               0U
#define ARM_V7M_CM7_ITCMCR_EN_Msk               (1UL << ARM_V7M_CM7_ITCMCR_EN_Pos)

#define ARM_V7M_CM7_ITCMCR_RMW_Pos              1U
#define ARM_V7M_CM7_ITCMCR_RMW_Msk              (1UL << ARM_V7M_CM7_ITCMCR_RMW_Pos)

#define ARM_V7M_CM7_ITCMCR_RETEN_Pos            2U
#define ARM_V7M_CM7_ITCMCR_RETEN_Msk            (1UL << ARM_V7M_CM7_ITCMCR_RETEN_Pos)

#define ARM_V7M_CM7_ITCMCR_SZ_Pos               3U
#define ARM_V7M_CM7_ITCMCR_SZ_Msk               (0xFUL << ARM_V7M_CM7_ITCMCR_SZ_Pos)

/*============================================================================*
 * DTCMCR Bit Definitions
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.1 on page 4-67
 *            Table 4-69: ITCMCR and DTCMCR bit assignments
 *============================================================================*/

#define ARM_V7M_CM7_DTCMCR_EN_Pos               0U
#define ARM_V7M_CM7_DTCMCR_EN_Msk               (1UL << ARM_V7M_CM7_DTCMCR_EN_Pos)

#define ARM_V7M_CM7_DTCMCR_RMW_Pos              1U
#define ARM_V7M_CM7_DTCMCR_RMW_Msk              (1UL << ARM_V7M_CM7_DTCMCR_RMW_Pos)

#define ARM_V7M_CM7_DTCMCR_RETEN_Pos            2U
#define ARM_V7M_CM7_DTCMCR_RETEN_Msk            (1UL << ARM_V7M_CM7_DTCMCR_RETEN_Pos)

#define ARM_V7M_CM7_DTCMCR_SZ_Pos               3U
#define ARM_V7M_CM7_DTCMCR_SZ_Msk               (0xFUL << ARM_V7M_CM7_DTCMCR_SZ_Pos)

/*============================================================================*
 * TCM Size Definitions
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.1 on page 4-67
 *            Table 4-69: SZ field encoding
 *============================================================================*/

#define ARM_V7M_CM7_TCM_SIZE_0KB                0x0UL   /*!< No TCM implemented */
#define ARM_V7M_CM7_TCM_SIZE_4KB                0x3UL   /*!< 4KB TCM */
#define ARM_V7M_CM7_TCM_SIZE_8KB                0x4UL   /*!< 8KB TCM */
#define ARM_V7M_CM7_TCM_SIZE_16KB               0x5UL   /*!< 16KB TCM */
#define ARM_V7M_CM7_TCM_SIZE_32KB               0x6UL   /*!< 32KB TCM */
#define ARM_V7M_CM7_TCM_SIZE_64KB               0x7UL   /*!< 64KB TCM */
#define ARM_V7M_CM7_TCM_SIZE_128KB              0x8UL   /*!< 128KB TCM */
#define ARM_V7M_CM7_TCM_SIZE_256KB              0x9UL   /*!< 256KB TCM */
#define ARM_V7M_CM7_TCM_SIZE_512KB              0xAUL   /*!< 512KB TCM */
#define ARM_V7M_CM7_TCM_SIZE_1MB                0xBUL   /*!< 1MB TCM */
#define ARM_V7M_CM7_TCM_SIZE_2MB                0xCUL   /*!< 2MB TCM */
#define ARM_V7M_CM7_TCM_SIZE_4MB                0xDUL   /*!< 4MB TCM */
#define ARM_V7M_CM7_TCM_SIZE_8MB                0xEUL   /*!< 8MB TCM */
#define ARM_V7M_CM7_TCM_SIZE_16MB               0xFUL   /*!< 16MB TCM */

/*============================================================================*
 * AHBPCR Bit Definitions
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.2 on page 4-69
 *            Table 4-70: AHBPCR bit assignments
 *============================================================================*/

#define ARM_V7M_CM7_AHBPCR_EN_Pos               0U
#define ARM_V7M_CM7_AHBPCR_EN_Msk               (1UL << ARM_V7M_CM7_AHBPCR_EN_Pos)

#define ARM_V7M_CM7_AHBPCR_SZ_Pos               1U
#define ARM_V7M_CM7_AHBPCR_SZ_Msk               (0x7UL << ARM_V7M_CM7_AHBPCR_SZ_Pos)

/* AHBPCR SZ field values */
#define ARM_V7M_CM7_AHBPCR_SZ_64MB              (0x1UL << ARM_V7M_CM7_AHBPCR_SZ_Pos)   /*!< 64MB AHBP region */
#define ARM_V7M_CM7_AHBPCR_SZ_128MB             (0x2UL << ARM_V7M_CM7_AHBPCR_SZ_Pos)   /*!< 128MB AHBP region */
#define ARM_V7M_CM7_AHBPCR_SZ_256MB             (0x3UL << ARM_V7M_CM7_AHBPCR_SZ_Pos)   /*!< 256MB AHBP region */
#define ARM_V7M_CM7_AHBPCR_SZ_512MB             (0x4UL << ARM_V7M_CM7_AHBPCR_SZ_Pos)   /*!< 512MB AHBP region */

/*============================================================================*
 * CACR Bit Definitions
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.3 on page 4-70
 *            Table 4-71: CACR bit assignments
 *============================================================================*/

#define ARM_V7M_CM7_CACR_ECCEN_Pos              0U
#define ARM_V7M_CM7_CACR_ECCEN_Msk              (1UL << ARM_V7M_CM7_CACR_ECCEN_Pos)

#define ARM_V7M_CM7_CACR_DBPWR_Pos              1U
#define ARM_V7M_CM7_CACR_DBPWR_Msk              (1UL << ARM_V7M_CM7_CACR_DBPWR_Pos)

#define ARM_V7M_CM7_CACR_SIWT_Pos               2U
#define ARM_V7M_CM7_CACR_SIWT_Msk               (1UL << ARM_V7M_CM7_CACR_SIWT_Pos)

#define ARM_V7M_CM7_CACR_DCOR_Pos               3U
#define ARM_V7M_CM7_CACR_DCOR_Msk               (1UL << ARM_V7M_CM7_CACR_DCOR_Pos)

#define ARM_V7M_CM7_CACR_ECOR_Pos               4U
#define ARM_V7M_CM7_CACR_ECOR_Msk               (1UL << ARM_V7M_CM7_CACR_ECOR_Msk)

/*============================================================================*
 * AHBSCR Bit Definitions
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.4 on page 4-72
 *            Table 4-72: AHBSCR bit assignments
 *============================================================================*/

#define ARM_V7M_CM7_AHBSCR_CTL_Pos              0U
#define ARM_V7M_CM7_AHBSCR_CTL_Msk              (0x3UL << ARM_V7M_CM7_AHBSCR_CTL_Pos)

#define ARM_V7M_CM7_AHBSCR_CTL_AHBS_DEMOTED     0x0UL   /*!< AHBS access priority demoted */
#define ARM_V7M_CM7_AHBSCR_CTL_SOFTWARE_DEMOTED 0x1UL   /*!< Software access priority demoted */
#define ARM_V7M_CM7_AHBSCR_CTL_FAIRNESS_COUNTER 0x2UL   /*!< Fairness counter based demotion */
#define ARM_V7M_CM7_AHBSCR_CTL_NO_DEMOTION      0x3UL   /*!< No demotion, AHBS has highest priority */

#define ARM_V7M_CM7_AHBSCR_TPRI_Pos             2U
#define ARM_V7M_CM7_AHBSCR_TPRI_Msk             (0x1FFUL << ARM_V7M_CM7_AHBSCR_TPRI_Pos)

#define ARM_V7M_CM7_AHBSCR_INITCOUNT_Pos        11U
#define ARM_V7M_CM7_AHBSCR_INITCOUNT_Msk        (0x1FUL << ARM_V7M_CM7_AHBSCR_INITCOUNT_Pos)

/*============================================================================*
 * ABFSR Bit Definitions
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.5 on page 4-73
 *            Table 4-73: ABFSR bit assignments
 *============================================================================*/

#define ARM_V7M_CM7_ABFSR_ITCM_Pos              0U
#define ARM_V7M_CM7_ABFSR_ITCM_Msk              (1UL << ARM_V7M_CM7_ABFSR_ITCM_Pos)

#define ARM_V7M_CM7_ABFSR_DTCM_Pos              1U
#define ARM_V7M_CM7_ABFSR_DTCM_Msk              (1UL << ARM_V7M_CM7_ABFSR_DTCM_Pos)

#define ARM_V7M_CM7_ABFSR_AHBP_Pos              2U
#define ARM_V7M_CM7_ABFSR_AHBP_Msk              (1UL << ARM_V7M_CM7_ABFSR_AHBP_Pos)

#define ARM_V7M_CM7_ABFSR_AXIM_Pos              3U
#define ARM_V7M_CM7_ABFSR_AXIM_Msk              (1UL << ARM_V7M_CM7_ABFSR_AXIM_Pos)

#define ARM_V7M_CM7_ABFSR_EPPB_Pos              4U
#define ARM_V7M_CM7_ABFSR_EPPB_Msk              (1UL << ARM_V7M_CM7_ABFSR_EPPB_Pos)

#define ARM_V7M_CM7_ABFSR_AXIMTYPE_Pos          8U
#define ARM_V7M_CM7_ABFSR_AXIMTYPE_Msk          (0x3UL << ARM_V7M_CM7_ABFSR_AXIMTYPE_Pos)

/*============================================================================*
 * Inline Functions - ITCM Operations
 *============================================================================*/

/**
 * @brief Enable Instruction TCM
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.1 on page 4-67
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_itcm_enable(void)
{
    ARM_V7M_CM7_TCM->ITCMCR |= ARM_V7M_CM7_ITCMCR_EN_Msk;
}

/**
 * @brief Disable Instruction TCM
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.1 on page 4-67
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_itcm_disable(void)
{
    ARM_V7M_CM7_TCM->ITCMCR &= ~ARM_V7M_CM7_ITCMCR_EN_Msk;
}

/**
 * @brief Check if Instruction TCM is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_itcm_is_enabled(void)
{
    return (ARM_V7M_CM7_TCM->ITCMCR & ARM_V7M_CM7_ITCMCR_EN_Msk) ? 1U : 0U;
}

/**
 * @brief Get Instruction TCM size
 * @return TCM size code (0-15), see ARM_V7M_CM7_TCM_SIZE_* definitions
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_itcm_get_size(void)
{
    return (ARM_V7M_CM7_TCM->ITCMCR & ARM_V7M_CM7_ITCMCR_SZ_Msk) >> ARM_V7M_CM7_ITCMCR_SZ_Pos;
}

/**
 * @brief Enable ITCM Read-Modify-Write
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.1 on page 4-67
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_itcm_enable_rmw(void)
{
    ARM_V7M_CM7_TCM->ITCMCR |= ARM_V7M_CM7_ITCMCR_RMW_Msk;
}

/**
 * @brief Disable ITCM Read-Modify-Write
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_itcm_disable_rmw(void)
{
    ARM_V7M_CM7_TCM->ITCMCR &= ~ARM_V7M_CM7_ITCMCR_RMW_Msk;
}

/**
 * @brief Enable ITCM Retry Phase
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.1 on page 4-67
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_itcm_enable_reten(void)
{
    ARM_V7M_CM7_TCM->ITCMCR |= ARM_V7M_CM7_ITCMCR_RETEN_Msk;
}

/**
 * @brief Disable ITCM Retry Phase
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_itcm_disable_reten(void)
{
    ARM_V7M_CM7_TCM->ITCMCR &= ~ARM_V7M_CM7_ITCMCR_RETEN_Msk;
}

/**
 * @brief Get ITCM Control Register value
 * @return ITCMCR value
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_itcm_get_cr(void)
{
    return ARM_V7M_CM7_TCM->ITCMCR;
}

/**
 * @brief Set ITCM Control Register value
 * @param value Value to write
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_itcm_set_cr(uint32_t value)
{
    ARM_V7M_CM7_TCM->ITCMCR = value;
}

/*============================================================================*
 * Inline Functions - DTCM Operations
 *============================================================================*/

/**
 * @brief Enable Data TCM
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.1 on page 4-67
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_dtcm_enable(void)
{
    ARM_V7M_CM7_TCM->DTCMCR |= ARM_V7M_CM7_DTCMCR_EN_Msk;
}

/**
 * @brief Disable Data TCM
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.1 on page 4-67
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_dtcm_disable(void)
{
    ARM_V7M_CM7_TCM->DTCMCR &= ~ARM_V7M_CM7_DTCMCR_EN_Msk;
}

/**
 * @brief Check if Data TCM is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_dtcm_is_enabled(void)
{
    return (ARM_V7M_CM7_TCM->DTCMCR & ARM_V7M_CM7_DTCMCR_EN_Msk) ? 1U : 0U;
}

/**
 * @brief Get Data TCM size
 * @return TCM size code (0-15), see ARM_V7M_CM7_TCM_SIZE_* definitions
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_dtcm_get_size(void)
{
    return (ARM_V7M_CM7_TCM->DTCMCR & ARM_V7M_CM7_DTCMCR_SZ_Msk) >> ARM_V7M_CM7_DTCMCR_SZ_Pos;
}

/**
 * @brief Enable DTCM Read-Modify-Write
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.1 on page 4-67
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_dtcm_enable_rmw(void)
{
    ARM_V7M_CM7_TCM->DTCMCR |= ARM_V7M_CM7_DTCMCR_RMW_Msk;
}

/**
 * @brief Disable DTCM Read-Modify-Write
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_dtcm_disable_rmw(void)
{
    ARM_V7M_CM7_TCM->DTCMCR &= ~ARM_V7M_CM7_DTCMCR_RMW_Msk;
}

/**
 * @brief Enable DTCM Retry Phase
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.1 on page 4-67
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_dtcm_enable_reten(void)
{
    ARM_V7M_CM7_TCM->DTCMCR |= ARM_V7M_CM7_DTCMCR_RETEN_Msk;
}

/**
 * @brief Disable DTCM Retry Phase
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_dtcm_disable_reten(void)
{
    ARM_V7M_CM7_TCM->DTCMCR &= ~ARM_V7M_CM7_DTCMCR_RETEN_Msk;
}

/**
 * @brief Get DTCM Control Register value
 * @return DTCMCR value
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_dtcm_get_cr(void)
{
    return ARM_V7M_CM7_TCM->DTCMCR;
}

/**
 * @brief Set DTCM Control Register value
 * @param value Value to write
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_dtcm_set_cr(uint32_t value)
{
    ARM_V7M_CM7_TCM->DTCMCR = value;
}

/*============================================================================*
 * Inline Functions - AHB Peripheral Control Operations
 *============================================================================*/

/**
 * @brief Enable AHB Peripheral interface
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.2 on page 4-69
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_ahbpc_enable(void)
{
    ARM_V7M_CM7_TCM->AHBPCR |= ARM_V7M_CM7_AHBPCR_EN_Msk;
}

/**
 * @brief Disable AHB Peripheral interface
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.2 on page 4-69
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_ahbpc_disable(void)
{
    ARM_V7M_CM7_TCM->AHBPCR &= ~ARM_V7M_CM7_AHBPCR_EN_Msk;
}

/**
 * @brief Check if AHB Peripheral interface is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_ahbpc_is_enabled(void)
{
    return (ARM_V7M_CM7_TCM->AHBPCR & ARM_V7M_CM7_AHBPCR_EN_Msk) ? 1U : 0U;
}

/**
 * @brief Get AHB Peripheral region size
 * @return Size code, see ARM_V7M_CM7_AHBPCR_SZ_* definitions
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_ahbpc_get_size(void)
{
    return (ARM_V7M_CM7_TCM->AHBPCR & ARM_V7M_CM7_AHBPCR_SZ_Msk) >> ARM_V7M_CM7_AHBPCR_SZ_Pos;
}

/**
 * @brief Get AHBPCR value
 * @return AHBPCR value
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_ahbpc_get_cr(void)
{
    return ARM_V7M_CM7_TCM->AHBPCR;
}

/**
 * @brief Set AHBPCR value
 * @param value Value to write
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_ahbpc_set_cr(uint32_t value)
{
    ARM_V7M_CM7_TCM->AHBPCR = value;
}

/*============================================================================*
 * Inline Functions - Cache Control (CACR) Operations
 *============================================================================*/

/**
 * @brief Enable L1 Cache ECC
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.3 on page 4-70
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_cacr_enable_ecc(void)
{
    ARM_V7M_CM7_TCM->CACR |= ARM_V7M_CM7_CACR_ECCEN_Msk;
}

/**
 * @brief Disable L1 Cache ECC
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.3 on page 4-70
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_cacr_disable_ecc(void)
{
    ARM_V7M_CM7_TCM->CACR &= ~ARM_V7M_CM7_CACR_ECCEN_Msk;
}

/**
 * @brief Check if L1 Cache ECC is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_cacr_ecc_is_enabled(void)
{
    return (ARM_V7M_CM7_TCM->CACR & ARM_V7M_CM7_CACR_ECCEN_Msk) ? 1U : 0U;
}

/**
 * @brief Enable Store Instruction Weakly-ordered to Strongly-ordered (SIWT)
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.3 on page 4-70
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_cacr_enable_siwt(void)
{
    ARM_V7M_CM7_TCM->CACR |= ARM_V7M_CM7_CACR_SIWT_Msk;
}

/**
 * @brief Disable Store Instruction Weakly-ordered to Strongly-ordered (SIWT)
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_cacr_disable_siwt(void)
{
    ARM_V7M_CM7_TCM->CACR &= ~ARM_V7M_CM7_CACR_SIWT_Msk;
}

/**
 * @brief Enable Data Cache Outer coherency (DCOR)
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.3 on page 4-70
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_cacr_enable_dcor(void)
{
    ARM_V7M_CM7_TCM->CACR |= ARM_V7M_CM7_CACR_DCOR_Msk;
}

/**
 * @brief Disable Data Cache Outer coherency (DCOR)
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_cacr_disable_dcor(void)
{
    ARM_V7M_CM7_TCM->CACR &= ~ARM_V7M_CM7_CACR_DCOR_Msk;
}

/**
 * @brief Enable Instruction Cache Outer coherency (ECOR)
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.3 on page 4-70
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_cacr_enable_ecor(void)
{
    ARM_V7M_CM7_TCM->CACR |= ARM_V7M_CM7_CACR_ECOR_Msk;
}

/**
 * @brief Disable Instruction Cache Outer coherency (ECOR)
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_cacr_disable_ecor(void)
{
    ARM_V7M_CM7_TCM->CACR &= ~ARM_V7M_CM7_CACR_ECOR_Msk;
}

/**
 * @brief Get CACR value
 * @return CACR value
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_cacr_get_cr(void)
{
    return ARM_V7M_CM7_TCM->CACR;
}

/**
 * @brief Set CACR value
 * @param value Value to write
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_cacr_set_cr(uint32_t value)
{
    ARM_V7M_CM7_TCM->CACR = value;
}

/*============================================================================*
 * Inline Functions - AHB Slave Control (AHBSCR) Operations
 *============================================================================*/

/**
 * @brief Get AHBSCR value
 * @return AHBSCR value
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_ahbscr_get(void)
{
    return ARM_V7M_CM7_TCM->AHBSCR;
}

/**
 * @brief Set AHBSCR value
 * @param value Value to write
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_ahbscr_set(uint32_t value)
{
    ARM_V7M_CM7_TCM->AHBSCR = value;
}

/**
 * @brief Set AHB Slave control mode
 * @param mode Control mode, see ARM_V7M_CM7_AHBSCR_CTL_* definitions
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_ahbscr_set_ctl(uint32_t mode)
{
    uint32_t reg = ARM_V7M_CM7_TCM->AHBSCR;
    reg &= ~ARM_V7M_CM7_AHBSCR_CTL_Msk;
    reg |= (mode << ARM_V7M_CM7_AHBSCR_CTL_Pos) & ARM_V7M_CM7_AHBSCR_CTL_Msk;
    ARM_V7M_CM7_TCM->AHBSCR = reg;
}

/**
 * @brief Set AHB Slave threshold priority
 * @param priority Priority threshold value (0-511)
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_ahbscr_set_tpri(uint32_t priority)
{
    uint32_t reg = ARM_V7M_CM7_TCM->AHBSCR;
    reg &= ~ARM_V7M_CM7_AHBSCR_TPRI_Msk;
    reg |= (priority << ARM_V7M_CM7_AHBSCR_TPRI_Pos) & ARM_V7M_CM7_AHBSCR_TPRI_Msk;
    ARM_V7M_CM7_TCM->AHBSCR = reg;
}

/**
 * @brief Set AHB Slave initial count value
 * @param count Initial count value (0-31)
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_ahbscr_set_initcount(uint32_t count)
{
    uint32_t reg = ARM_V7M_CM7_TCM->AHBSCR;
    reg &= ~ARM_V7M_CM7_AHBSCR_INITCOUNT_Msk;
    reg |= (count << ARM_V7M_CM7_AHBSCR_INITCOUNT_Pos) & ARM_V7M_CM7_AHBSCR_INITCOUNT_Msk;
    ARM_V7M_CM7_TCM->AHBSCR = reg;
}

/*============================================================================*
 * Inline Functions - Auxiliary Bus Fault Status (ABFSR) Operations
 *============================================================================*/

/**
 * @brief Get ABFSR value
 * @return ABFSR value
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_abfsr_get(void)
{
    return ARM_V7M_CM7_TCM->ABFSR;
}

/**
 * @brief Clear ABFSR by writing any value
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.5 on page 4-73
 */
ARM_V7M_CM7_TCM_INLINE void arm_v7m_cm7_abfsr_clear(void)
{
    ARM_V7M_CM7_TCM->ABFSR = 0xFFFFFFFFUL;
}

/**
 * @brief Check if ITCM had an asynchronous fault
 * @return 1 if fault occurred, 0 otherwise
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_abfsr_itcm_fault(void)
{
    return (ARM_V7M_CM7_TCM->ABFSR & ARM_V7M_CM7_ABFSR_ITCM_Msk) ? 1U : 0U;
}

/**
 * @brief Check if DTCM had an asynchronous fault
 * @return 1 if fault occurred, 0 otherwise
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_abfsr_dtcm_fault(void)
{
    return (ARM_V7M_CM7_TCM->ABFSR & ARM_V7M_CM7_ABFSR_DTCM_Msk) ? 1U : 0U;
}

/**
 * @brief Check if AHBP had an asynchronous fault
 * @return 1 if fault occurred, 0 otherwise
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_abfsr_ahbp_fault(void)
{
    return (ARM_V7M_CM7_TCM->ABFSR & ARM_V7M_CM7_ABFSR_AHBP_Msk) ? 1U : 0U;
}

/**
 * @brief Check if AXIM had an asynchronous fault
 * @return 1 if fault occurred, 0 otherwise
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_abfsr_axim_fault(void)
{
    return (ARM_V7M_CM7_TCM->ABFSR & ARM_V7M_CM7_ABFSR_AXIM_Msk) ? 1U : 0U;
}

/**
 * @brief Check if EPPB had an asynchronous fault
 * @return 1 if fault occurred, 0 otherwise
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_abfsr_eppb_fault(void)
{
    return (ARM_V7M_CM7_TCM->ABFSR & ARM_V7M_CM7_ABFSR_EPPB_Msk) ? 1U : 0U;
}

/**
 * @brief Get AXIM fault type
 * @return Fault type code (0-3)
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_abfsr_get_axim_type(void)
{
    return (ARM_V7M_CM7_TCM->ABFSR & ARM_V7M_CM7_ABFSR_AXIMTYPE_Msk) >> ARM_V7M_CM7_ABFSR_AXIMTYPE_Pos;
}

/*============================================================================*
 * Inline Functions - TCM Utility Operations
 *============================================================================*/

/**
 * @brief Convert TCM size code to actual size in bytes
 * @param size_code TCM size code from ITCMCR/DTCMCR SZ field
 * @return Size in bytes, or 0 if not implemented/invalid
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_tcm_size_to_bytes(uint32_t size_code)
{
    switch (size_code) {
        case ARM_V7M_CM7_TCM_SIZE_0KB:   return 0U;
        case ARM_V7M_CM7_TCM_SIZE_4KB:   return 4096U;
        case ARM_V7M_CM7_TCM_SIZE_8KB:   return 8192U;
        case ARM_V7M_CM7_TCM_SIZE_16KB:  return 16384U;
        case ARM_V7M_CM7_TCM_SIZE_32KB:  return 32768U;
        case ARM_V7M_CM7_TCM_SIZE_64KB:  return 65536U;
        case ARM_V7M_CM7_TCM_SIZE_128KB: return 131072U;
        case ARM_V7M_CM7_TCM_SIZE_256KB: return 262144U;
        case ARM_V7M_CM7_TCM_SIZE_512KB: return 524288U;
        case ARM_V7M_CM7_TCM_SIZE_1MB:   return 1048576U;
        case ARM_V7M_CM7_TCM_SIZE_2MB:   return 2097152U;
        case ARM_V7M_CM7_TCM_SIZE_4MB:   return 4194304U;
        case ARM_V7M_CM7_TCM_SIZE_8MB:   return 8388608U;
        case ARM_V7M_CM7_TCM_SIZE_16MB:  return 16777216U;
        default: return 0U;
    }
}

/**
 * @brief Get Instruction TCM size in bytes
 * @return Size in bytes
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_itcm_get_size_bytes(void)
{
    return arm_v7m_cm7_tcm_size_to_bytes(arm_v7m_cm7_itcm_get_size());
}

/**
 * @brief Get Data TCM size in bytes
 * @return Size in bytes
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_dtcm_get_size_bytes(void)
{
    return arm_v7m_cm7_tcm_size_to_bytes(arm_v7m_cm7_dtcm_get_size());
}

/**
 * @brief Check if Instruction TCM is implemented
 * @return 1 if implemented, 0 if not
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_itcm_is_implemented(void)
{
    return (arm_v7m_cm7_itcm_get_size() != ARM_V7M_CM7_TCM_SIZE_0KB) ? 1U : 0U;
}

/**
 * @brief Check if Data TCM is implemented
 * @return 1 if implemented, 0 if not
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_dtcm_is_implemented(void)
{
    return (arm_v7m_cm7_dtcm_get_size() != ARM_V7M_CM7_TCM_SIZE_0KB) ? 1U : 0U;
}

/**
 * @brief Check if ITCM RMW is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_itcm_rmw_is_enabled(void)
{
    return (ARM_V7M_CM7_TCM->ITCMCR & ARM_V7M_CM7_ITCMCR_RMW_Msk) ? 1U : 0U;
}

/**
 * @brief Check if DTCM RMW is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_dtcm_rmw_is_enabled(void)
{
    return (ARM_V7M_CM7_TCM->DTCMCR & ARM_V7M_CM7_DTCMCR_RMW_Msk) ? 1U : 0U;
}

/**
 * @brief Check if ITCM Retry Phase is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_itcm_reten_is_enabled(void)
{
    return (ARM_V7M_CM7_TCM->ITCMCR & ARM_V7M_CM7_ITCMCR_RETEN_Msk) ? 1U : 0U;
}

/**
 * @brief Check if DTCM Retry Phase is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_dtcm_reten_is_enabled(void)
{
    return (ARM_V7M_CM7_TCM->DTCMCR & ARM_V7M_CM7_DTCMCR_RETEN_Msk) ? 1U : 0U;
}

/**
 * @brief Check if any asynchronous fault is pending in ABFSR
 * @return 1 if any fault pending, 0 if none
 */
ARM_V7M_CM7_TCM_INLINE uint32_t arm_v7m_cm7_abfsr_any_fault_pending(void)
{
    return (ARM_V7M_CM7_TCM->ABFSR & 
            (ARM_V7M_CM7_ABFSR_ITCM_Msk | ARM_V7M_CM7_ABFSR_DTCM_Msk |
             ARM_V7M_CM7_ABFSR_AHBP_Msk | ARM_V7M_CM7_ABFSR_AXIM_Msk |
             ARM_V7M_CM7_ABFSR_EPPB_Msk)) ? 1U : 0U;
}

/*============================================================================*
 * Non-Inline Functions - Complex TCM Operations
 *============================================================================*/

/**
 * @brief Enable both ITCM and DTCM with proper memory barriers
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.1 on page 4-67
 *            Cortex-M7 Technical Reference Manual, Section 4.1.5 on page 4-5
 */
void arm_v7m_cm7_tcm_enable(void);

/**
 * @brief Disable both ITCM and DTCM with proper memory barriers
 */
void arm_v7m_cm7_tcm_disable(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM7_TCM_H */
