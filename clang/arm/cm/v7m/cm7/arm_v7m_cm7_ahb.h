/*
 * arm_v7m_cm7_ahb.h
 * Cortex-M7 AHB Interface Control Definitions
 * Reference: Cortex-M7 Processor Technical Reference Manual, Chapter 3.3
 *            - Section 3.3.7: AHBP Control Register (CM7_AHBPCR)
 *            - Section 3.3.9: Auxiliary Bus Fault Status Register (CM7_ABFSR)
 *            - Section 3.3.10: AHB Slave Control Register (CM7_AHBSCR)
 *
 * @note These registers control the Cortex-M7 specific AHB interfaces:
 *       - AHBP: AHB-Lite Peripheral interface (low-latency peripheral access)
 *       - AHBS: AHB-Lite Slave interface (DMA access to TCMs)
 *       - AXIM: AXI Master interface (high-performance memory access)
 */

#ifndef ARM_V7M_CM7_AHB_H
#define ARM_V7M_CM7_AHB_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Compiler Abstraction - Inline Definition
 *============================================================================*/

#if defined(__clang__)
    #define ARM_V7M_CM7_AHB_INLINE static inline __attribute__((always_inline))
#else
    #error "This library requires Clang/LLVM compiler."
#endif

/*============================================================================*
 * AHB Interface Control Register Base Address
 * Reference: Cortex-M7 TRM, Table 3-1
 *============================================================================*/

#define ARM_V7M_CM7_AHB_BASE        0xE000EF90UL

/*============================================================================*
 * AHB Interface Control Register Structure
 * Reference: Cortex-M7 TRM, Table 3-1
 *============================================================================*/

typedef struct {
    uint32_t RESERVED0[2];      /*!< Offset: 0x000-0x004 Reserved */
    volatile uint32_t AHBPCR;   /*!< Offset: 0x008 (R/W) AHBP Control Register */
    volatile uint32_t CACR;     /*!< Offset: 0x00C (R/W) L1 Cache Control Register */
    volatile uint32_t AHBSCR;   /*!< Offset: 0x010 (R/W) AHB Slave Control Register */
    uint32_t RESERVED1[1];      /*!< Offset: 0x014 Reserved */
    volatile uint32_t ABFSR;    /*!< Offset: 0x018 (R/W) Auxiliary Bus Fault Status Register */
} arm_v7m_cm7_ahb_regs_t;

#define ARM_V7M_CM7_AHB     ((arm_v7m_cm7_ahb_regs_t *)ARM_V7M_CM7_AHB_BASE)

/*============================================================================*
 * AHBP Control Register (CM7_AHBPCR) Bit Definitions
 * Reference: Cortex-M7 TRM, Section 3.3.7
 *============================================================================*/

/* AHBP Size - Read-only, reflects implementation configuration */
#define ARM_V7M_CM7_AHBPCR_SZ_Pos       1U
#define ARM_V7M_CM7_AHBPCR_SZ_Msk       (0x7UL << ARM_V7M_CM7_AHBPCR_SZ_Pos)

/* AHBP Size Values */
#define ARM_V7M_CM7_AHBPCR_SZ_0MB       0x0U  /*!< AHBP disabled (0MB) */
#define ARM_V7M_CM7_AHBPCR_SZ_64MB      0x1U  /*!< 64MB AHBP region */
#define ARM_V7M_CM7_AHBPCR_SZ_128MB     0x2U  /*!< 128MB AHBP region */
#define ARM_V7M_CM7_AHBPCR_SZ_256MB     0x3U  /*!< 256MB AHBP region */
#define ARM_V7M_CM7_AHBPCR_SZ_512MB     0x4U  /*!< 512MB AHBP region */

/* AHBP Enable */
#define ARM_V7M_CM7_AHBPCR_EN_Pos       0U
#define ARM_V7M_CM7_AHBPCR_EN_Msk       (1UL << ARM_V7M_CM7_AHBPCR_EN_Pos)

/*============================================================================*
 * L1 Cache Control Register (CM7_CACR) Bit Definitions
 * Reference: Cortex-M7 TRM, Section 3.3.8
 *============================================================================*/

/* Force Write-Through in data cache */
#define ARM_V7M_CM7_CACR_FORCEWT_Pos    2U
#define ARM_V7M_CM7_CACR_FORCEWT_Msk    (1UL << ARM_V7M_CM7_CACR_FORCEWT_Pos)

/* ECC Disable in instruction and data cache */
#define ARM_V7M_CM7_CACR_ECCDIS_Pos     1U
#define ARM_V7M_CM7_CACR_ECCDIS_Msk     (1UL << ARM_V7M_CM7_CACR_ECCDIS_Pos)

/* Shared cacheable-is-Write-Through for data cache */
#define ARM_V7M_CM7_CACR_SIWT_Pos       0U
#define ARM_V7M_CM7_CACR_SIWT_Msk       (1UL << ARM_V7M_CM7_CACR_SIWT_Pos)

/*============================================================================*
 * AHB Slave Control Register (CM7_AHBSCR) Bit Definitions
 * Reference: Cortex-M7 TRM, Section 3.3.10
 *============================================================================*/

/* Fairness counter initialization value */
#define ARM_V7M_CM7_AHBSCR_INITCOUNT_Pos   11U
#define ARM_V7M_CM7_AHBSCR_INITCOUNT_Msk   (0x1FUL << ARM_V7M_CM7_AHBSCR_INITCOUNT_Pos)

/* Threshold execution priority for AHBS traffic demotion */
#define ARM_V7M_CM7_AHBSCR_TPRI_Pos        2U
#define ARM_V7M_CM7_AHBSCR_TPRI_Msk        (0x1FFUL << ARM_V7M_CM7_AHBSCR_TPRI_Pos)

/* AHBS prioritization control */
#define ARM_V7M_CM7_AHBSCR_CTL_Pos         0U
#define ARM_V7M_CM7_AHBSCR_CTL_Msk         (0x3UL << ARM_V7M_CM7_AHBSCR_CTL_Pos)

/* CTL Values */
#define ARM_V7M_CM7_AHBSCR_CTL_AHBS_DEMOTE    0x0U  /*!< AHBS access priority demoted (reset value) */
#define ARM_V7M_CM7_AHBSCR_CTL_SW_DEMOTE      0x1U  /*!< Software access priority demoted */
#define ARM_V7M_CM7_AHBSCR_CTL_THRESHOLD      0x2U  /*!< Priority demotion based on threshold */
#define ARM_V7M_CM7_AHBSCR_CTL_SIGNAL         0x3U  /*!< AHBSPRI signal controls priority */

/*============================================================================*
 * Auxiliary Bus Fault Status Register (CM7_ABFSR) Bit Definitions
 * Reference: Cortex-M7 TRM, Section 3.3.9
 *============================================================================*/

/* AXIM Interface Fault Type */
#define ARM_V7M_CM7_ABFSR_AXIMTYPE_Pos  8U
#define ARM_V7M_CM7_ABFSR_AXIMTYPE_Msk  (0x3UL << ARM_V7M_CM7_ABFSR_AXIMTYPE_Pos)

/* AXIMTYPE Values */
#define ARM_V7M_CM7_ABFSR_AXIMTYPE_OKAY     0x0U  /*!< OKAY response */
#define ARM_V7M_CM7_ABFSR_AXIMTYPE_EXOKAY   0x1U  /*!< EXOKAY response */
#define ARM_V7M_CM7_ABFSR_AXIMTYPE_SLVERR   0x2U  /*!< SLVERR response */
#define ARM_V7M_CM7_ABFSR_AXIMTYPE_DECERR   0x3U  /*!< DECERR response */

/* EPPB Interface Asynchronous Fault */
#define ARM_V7M_CM7_ABFSR_EPPB_Pos      4U
#define ARM_V7M_CM7_ABFSR_EPPB_Msk      (1UL << ARM_V7M_CM7_ABFSR_EPPB_Pos)

/* AXIM Interface Asynchronous Fault */
#define ARM_V7M_CM7_ABFSR_AXIM_Pos      3U
#define ARM_V7M_CM7_ABFSR_AXIM_Msk      (1UL << ARM_V7M_CM7_ABFSR_AXIM_Pos)

/* AHBP Interface Asynchronous Fault */
#define ARM_V7M_CM7_ABFSR_AHBP_Pos      2U
#define ARM_V7M_CM7_ABFSR_AHBP_Msk      (1UL << ARM_V7M_CM7_ABFSR_AHBP_Pos)

/* DTCM Interface Asynchronous Fault */
#define ARM_V7M_CM7_ABFSR_DTCM_Pos      1U
#define ARM_V7M_CM7_ABFSR_DTCM_Msk      (1UL << ARM_V7M_CM7_ABFSR_DTCM_Pos)

/* ITCM Interface Asynchronous Fault */
#define ARM_V7M_CM7_ABFSR_ITCM_Pos      0U
#define ARM_V7M_CM7_ABFSR_ITCM_Msk      (1UL << ARM_V7M_CM7_ABFSR_ITCM_Pos)

/*============================================================================*
 * AHBP Control Functions
 * Reference: Cortex-M7 TRM, Section 3.3.7
 *============================================================================*/

/**
 * @brief Get AHBP Control Register value
 * @return Current AHBPCR value
 */
ARM_V7M_CM7_AHB_INLINE uint32_t arm_v7m_cm7_ahb_get_ahbpcr(void)
{
    return ARM_V7M_CM7_AHB->AHBPCR;
}

/**
 * @brief Set AHBP Control Register value
 * @param value Value to write to AHBPCR
 * @note Only EN bit is writable. SZ bits are read-only.
 */
ARM_V7M_CM7_AHB_INLINE void arm_v7m_cm7_ahb_set_ahbpcr(uint32_t value)
{
    ARM_V7M_CM7_AHB->AHBPCR = value;
}

/**
 * @brief Enable AHBP interface
 * @note When enabled, peripheral accesses in the AHBP region go to AHBP interface.
 *       When disabled, all accesses go to AXIM interface.
 */
ARM_V7M_CM7_AHB_INLINE void arm_v7m_cm7_ahb_enable_ahbp(void)
{
    ARM_V7M_CM7_AHB->AHBPCR |= ARM_V7M_CM7_AHBPCR_EN_Msk;
}

/**
 * @brief Disable AHBP interface
 * @note All accesses in the AHBP region will go to AXIM interface.
 */
ARM_V7M_CM7_AHB_INLINE void arm_v7m_cm7_ahb_disable_ahbp(void)
{
    ARM_V7M_CM7_AHB->AHBPCR &= ~ARM_V7M_CM7_AHBPCR_EN_Msk;
}

/**
 * @brief Check if AHBP interface is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_CM7_AHB_INLINE int arm_v7m_cm7_ahb_is_ahbp_enabled(void)
{
    return (ARM_V7M_CM7_AHB->AHBPCR & ARM_V7M_CM7_AHBPCR_EN_Msk) ? 1 : 0;
}

/**
 * @brief Get AHBP region size
 * @return AHBP size value (0-4 corresponding to 0MB, 64MB, 128MB, 256MB, 512MB)
 * @note This is a read-only field reflecting the implementation configuration.
 */
ARM_V7M_CM7_AHB_INLINE uint32_t arm_v7m_cm7_ahb_get_ahbp_size(void)
{
    return (ARM_V7M_CM7_AHB->AHBPCR & ARM_V7M_CM7_AHBPCR_SZ_Msk) >> ARM_V7M_CM7_AHBPCR_SZ_Pos;
}

/**
 * @brief Get AHBP region size in MB
 * @return AHBP size in MB (0, 64, 128, 256, or 512)
 */
uint32_t arm_v7m_cm7_ahb_get_ahbp_size_mb(void);

/*============================================================================*
 * L1 Cache Control Functions
 * Reference: Cortex-M7 TRM, Section 3.3.8
 *============================================================================*/

/**
 * @brief Get L1 Cache Control Register value
 * @return Current CACR value
 */
ARM_V7M_CM7_AHB_INLINE uint32_t arm_v7m_cm7_ahb_get_cacr(void)
{
    return ARM_V7M_CM7_AHB->CACR;
}

/**
 * @brief Set L1 Cache Control Register value
 * @param value Value to write to CACR
 */
ARM_V7M_CM7_AHB_INLINE void arm_v7m_cm7_ahb_set_cacr(uint32_t value)
{
    ARM_V7M_CM7_AHB->CACR = value;
}

/**
 * @brief Enable Force Write-Through in data cache
 * @note When enabled, all Cacheable memory regions are treated as Write-Through.
 */
ARM_V7M_CM7_AHB_INLINE void arm_v7m_cm7_ahb_enable_force_write_through(void)
{
    ARM_V7M_CM7_AHB->CACR |= ARM_V7M_CM7_CACR_FORCEWT_Msk;
}

/**
 * @brief Disable Force Write-Through in data cache
 */
ARM_V7M_CM7_AHB_INLINE void arm_v7m_cm7_ahb_disable_force_write_through(void)
{
    ARM_V7M_CM7_AHB->CACR &= ~ARM_V7M_CM7_CACR_FORCEWT_Msk;
}

/**
 * @brief Check if Force Write-Through is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_CM7_AHB_INLINE int arm_v7m_cm7_ahb_is_force_write_through_enabled(void)
{
    return (ARM_V7M_CM7_AHB->CACR & ARM_V7M_CM7_CACR_FORCEWT_Msk) ? 1 : 0;
}

/**
 * @brief Enable ECC in instruction and data cache
 * @note ECC helps detect and correct errors in cache memory.
 */
ARM_V7M_CM7_AHB_INLINE void arm_v7m_cm7_ahb_enable_ecc(void)
{
    ARM_V7M_CM7_AHB->CACR &= ~ARM_V7M_CM7_CACR_ECCDIS_Msk;
}

/**
 * @brief Disable ECC in instruction and data cache
 */
ARM_V7M_CM7_AHB_INLINE void arm_v7m_cm7_ahb_disable_ecc(void)
{
    ARM_V7M_CM7_AHB->CACR |= ARM_V7M_CM7_CACR_ECCDIS_Msk;
}

/**
 * @brief Check if ECC is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_CM7_AHB_INLINE int arm_v7m_cm7_ahb_is_ecc_enabled(void)
{
    return (ARM_V7M_CM7_AHB->CACR & ARM_V7M_CM7_CACR_ECCDIS_Msk) ? 0 : 1;
}

/**
 * @brief Enable Shared cacheable-is-Write-Through mode
 * @note When enabled, Normal Cacheable shared locations are treated as Write-Through.
 *       Useful for heterogeneous MP-systems.
 */
ARM_V7M_CM7_AHB_INLINE void arm_v7m_cm7_ahb_enable_shared_write_through(void)
{
    ARM_V7M_CM7_AHB->CACR |= ARM_V7M_CM7_CACR_SIWT_Msk;
}

/**
 * @brief Disable Shared cacheable-is-Write-Through mode
 * @note Normal Cacheable Shared locations are treated as Non-cacheable.
 */
ARM_V7M_CM7_AHB_INLINE void arm_v7m_cm7_ahb_disable_shared_write_through(void)
{
    ARM_V7M_CM7_AHB->CACR &= ~ARM_V7M_CM7_CACR_SIWT_Msk;
}

/**
 * @brief Check if Shared Write-Through mode is enabled
 * @return 1 if enabled, 0 if disabled
 */
ARM_V7M_CM7_AHB_INLINE int arm_v7m_cm7_ahb_is_shared_write_through_enabled(void)
{
    return (ARM_V7M_CM7_AHB->CACR & ARM_V7M_CM7_CACR_SIWT_Msk) ? 1 : 0;
}

/*============================================================================*
 * AHB Slave Control Functions
 * Reference: Cortex-M7 TRM, Section 3.3.10
 *============================================================================*/

/**
 * @brief Get AHB Slave Control Register value
 * @return Current AHBSCR value
 */
ARM_V7M_CM7_AHB_INLINE uint32_t arm_v7m_cm7_ahb_get_ahbscr(void)
{
    return ARM_V7M_CM7_AHB->AHBSCR;
}

/**
 * @brief Set AHB Slave Control Register value
 * @param value Value to write to AHBSCR
 */
ARM_V7M_CM7_AHB_INLINE void arm_v7m_cm7_ahb_set_ahbscr(uint32_t value)
{
    ARM_V7M_CM7_AHB->AHBSCR = value;
}

/**
 * @brief Set AHBS prioritization control mode
 * @param mode Control mode (0-3)
 *             0: AHBS access priority demoted
 *             1: Software access priority demoted
 *             2: Threshold-based priority demotion
 *             3: AHBSPRI signal controls priority
 */
ARM_V7M_CM7_AHB_INLINE void arm_v7m_cm7_ahb_set_ahbs_priority_control(uint32_t mode)
{
    uint32_t reg = ARM_V7M_CM7_AHB->AHBSCR;
    reg &= ~ARM_V7M_CM7_AHBSCR_CTL_Msk;
    reg |= (mode << ARM_V7M_CM7_AHBSCR_CTL_Pos) & ARM_V7M_CM7_AHBSCR_CTL_Msk;
    ARM_V7M_CM7_AHB->AHBSCR = reg;
}

/**
 * @brief Get AHBS prioritization control mode
 * @return Current control mode (0-3)
 */
ARM_V7M_CM7_AHB_INLINE uint32_t arm_v7m_cm7_ahb_get_ahbs_priority_control(void)
{
    return (ARM_V7M_CM7_AHB->AHBSCR & ARM_V7M_CM7_AHBSCR_CTL_Msk) >> ARM_V7M_CM7_AHBSCR_CTL_Pos;
}

/**
 * @brief Set fairness counter initialization value
 * @param count Counter value (1-31, must not be 0)
 * @note For round-robin mode, set to 1.
 *       Must not be 0 as it can cause livelock.
 */
ARM_V7M_CM7_AHB_INLINE void arm_v7m_cm7_ahb_set_init_count(uint32_t count)
{
    uint32_t reg = ARM_V7M_CM7_AHB->AHBSCR;
    reg &= ~ARM_V7M_CM7_AHBSCR_INITCOUNT_Msk;
    reg |= (count << ARM_V7M_CM7_AHBSCR_INITCOUNT_Pos) & ARM_V7M_CM7_AHBSCR_INITCOUNT_Msk;
    ARM_V7M_CM7_AHB->AHBSCR = reg;
}

/**
 * @brief Get fairness counter initialization value
 * @return Current counter value
 */
ARM_V7M_CM7_AHB_INLINE uint32_t arm_v7m_cm7_ahb_get_init_count(void)
{
    return (ARM_V7M_CM7_AHB->AHBSCR & ARM_V7M_CM7_AHBSCR_INITCOUNT_Msk) >> ARM_V7M_CM7_AHBSCR_INITCOUNT_Pos;
}

/**
 * @brief Set threshold execution priority for AHBS traffic demotion
 * @param priority Priority value (0-511)
 * @note Priority encoding matches NVIC encoding.
 *       0x1FF = Priority -1 (HardFault)
 *       0x1FE = Priority -2 (NMI)
 */
ARM_V7M_CM7_AHB_INLINE void arm_v7m_cm7_ahb_set_threshold_priority(uint32_t priority)
{
    uint32_t reg = ARM_V7M_CM7_AHB->AHBSCR;
    reg &= ~ARM_V7M_CM7_AHBSCR_TPRI_Msk;
    reg |= (priority << ARM_V7M_CM7_AHBSCR_TPRI_Pos) & ARM_V7M_CM7_AHBSCR_TPRI_Msk;
    ARM_V7M_CM7_AHB->AHBSCR = reg;
}

/**
 * @brief Get threshold execution priority
 * @return Current threshold priority value
 */
ARM_V7M_CM7_AHB_INLINE uint32_t arm_v7m_cm7_ahb_get_threshold_priority(void)
{
    return (ARM_V7M_CM7_AHB->AHBSCR & ARM_V7M_CM7_AHBSCR_TPRI_Msk) >> ARM_V7M_CM7_AHBSCR_TPRI_Pos;
}

/*============================================================================*
 * Auxiliary Bus Fault Status Functions
 * Reference: Cortex-M7 TRM, Section 3.3.9
 *============================================================================*/

/**
 * @brief Get Auxiliary Bus Fault Status Register value
 * @return Current ABFSR value
 * @note This register stores information on the source of asynchronous bus faults.
 *       Only valid when BFSR.IMPRECISERR is set.
 */
ARM_V7M_CM7_AHB_INLINE uint32_t arm_v7m_cm7_ahb_get_abfsr(void)
{
    return ARM_V7M_CM7_AHB->ABFSR;
}

/**
 * @brief Clear Auxiliary Bus Fault Status Register
 * @note Write any value to clear the register.
 */
ARM_V7M_CM7_AHB_INLINE void arm_v7m_cm7_ahb_clear_abfsr(void)
{
    ARM_V7M_CM7_AHB->ABFSR = 0xFFFFFFFFU;
}

/**
 * @brief Check if asynchronous fault occurred on ITCM interface
 * @return 1 if fault occurred, 0 otherwise
 */
ARM_V7M_CM7_AHB_INLINE int arm_v7m_cm7_ahb_has_itcm_fault(void)
{
    return (ARM_V7M_CM7_AHB->ABFSR & ARM_V7M_CM7_ABFSR_ITCM_Msk) ? 1 : 0;
}

/**
 * @brief Check if asynchronous fault occurred on DTCM interface
 * @return 1 if fault occurred, 0 otherwise
 */
ARM_V7M_CM7_AHB_INLINE int arm_v7m_cm7_ahb_has_dtcm_fault(void)
{
    return (ARM_V7M_CM7_AHB->ABFSR & ARM_V7M_CM7_ABFSR_DTCM_Msk) ? 1 : 0;
}

/**
 * @brief Check if asynchronous fault occurred on AHBP interface
 * @return 1 if fault occurred, 0 otherwise
 */
ARM_V7M_CM7_AHB_INLINE int arm_v7m_cm7_ahb_has_ahbp_fault(void)
{
    return (ARM_V7M_CM7_AHB->ABFSR & ARM_V7M_CM7_ABFSR_AHBP_Msk) ? 1 : 0;
}

/**
 * @brief Check if asynchronous fault occurred on AXIM interface
 * @return 1 if fault occurred, 0 otherwise
 */
ARM_V7M_CM7_AHB_INLINE int arm_v7m_cm7_ahb_has_axim_fault(void)
{
    return (ARM_V7M_CM7_AHB->ABFSR & ARM_V7M_CM7_ABFSR_AXIM_Msk) ? 1 : 0;
}

/**
 * @brief Check if asynchronous fault occurred on EPPB interface
 * @return 1 if fault occurred, 0 otherwise
 */
ARM_V7M_CM7_AHB_INLINE int arm_v7m_cm7_ahb_has_eppb_fault(void)
{
    return (ARM_V7M_CM7_AHB->ABFSR & ARM_V7M_CM7_ABFSR_EPPB_Msk) ? 1 : 0;
}

/**
 * @brief Get AXIM interface fault type
 * @return Fault type (0-3: OKAY, EXOKAY, SLVERR, DECERR)
 * @note Only valid when AXIM fault bit is set.
 */
ARM_V7M_CM7_AHB_INLINE uint32_t arm_v7m_cm7_ahb_get_axim_fault_type(void)
{
    return (ARM_V7M_CM7_AHB->ABFSR & ARM_V7M_CM7_ABFSR_AXIMTYPE_Msk) >> ARM_V7M_CM7_ABFSR_AXIMTYPE_Pos;
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM7_AHB_H */
