/*
 * arm_v7m_fpu.h
 * Floating-Point Unit (FPU) Definitions
 * Reference: ARMv7-M Architecture Reference Manual
 *            - Section A2.5: The optional floating-point extension
 *            - Section B3.2.21: Floating Point Context Control Register, FPCCR on page B3-615
 *            - Section B3.2.22: Floating Point Context Address Register, FPCAR on page B3-617
 *            - Section B3.2.23: Floating Point Default Status Control Register, FPDSCR on page B3-617
 */

#ifndef ARM_V7M_FPU_H
#define ARM_V7M_FPU_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * FPU Base Address (Architecture defined)
 * Reference: ARMv7-M Architecture Reference Manual, Table B3-5
 *============================================================================*/
#define FPU_BASE            0xE000EF30UL

/*============================================================================*
 * FPU Type Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Table B3-5
 *============================================================================*/

typedef struct {
    uint32_t RESERVED0[1];                  /*!< Offset: 0x00       Reserved */
    volatile uint32_t FPCCR;                /*!< Offset: 0x04 (R/W) Floating Point Context Control Register */
    volatile uint32_t FPCAR;                /*!< Offset: 0x08 (R/W) Floating Point Context Address Register */
    volatile uint32_t FPDSCR;               /*!< Offset: 0x0C (R/W) Floating Point Default Status Control Register */
    volatile const uint32_t MVFR0;          /*!< Offset: 0x10 (R/ ) Media and FP Feature Register 0 */
    volatile const uint32_t MVFR1;          /*!< Offset: 0x14 (R/ ) Media and FP Feature Register 1 */
    volatile const uint32_t MVFR2;          /*!< Offset: 0x18 (R/ ) Media and FP Feature Register 2 */
} arm_v7m_fpu_regs_t;

#define FPU                 ((arm_v7m_fpu_regs_t *)FPU_BASE)

/*============================================================================*
 * FPU FPCCR Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.21
 *============================================================================*/

/* ASPEN: Automatic State Preservation Enable */
#define FPU_FPCCR_ASPEN_Pos           31U
#define FPU_FPCCR_ASPEN_Msk          (1UL << FPU_FPCCR_ASPEN_Pos)

/* LSPEN: Lazy State Preservation Enable */
#define FPU_FPCCR_LSPEN_Pos           30U
#define FPU_FPCCR_LSPEN_Msk          (1UL << FPU_FPCCR_LSPEN_Pos)

/* MONRDY: DebugMonitor Ready */
#define FPU_FPCCR_MONRDY_Pos           8U
#define FPU_FPCCR_MONRDY_Msk         (1UL << FPU_FPCCR_MONRDY_Pos)

/* BFRDY: BusFault Ready */
#define FPU_FPCCR_BFRDY_Pos            6U
#define FPU_FPCCR_BFRDY_Msk          (1UL << FPU_FPCCR_BFRDY_Pos)

/* MMRDY: MemManage Ready */
#define FPU_FPCCR_MMRDY_Pos            5U
#define FPU_FPCCR_MMRDY_Msk          (1UL << FPU_FPCCR_MMRDY_Pos)

/* HFRDY: HardFault Ready */
#define FPU_FPCCR_HFRDY_Pos            4U
#define FPU_FPCCR_HFRDY_Msk          (1UL << FPU_FPCCR_HFRDY_Pos)

/* THREAD: Thread Mode */
#define FPU_FPCCR_THREAD_Pos           3U
#define FPU_FPCCR_THREAD_Msk         (1UL << FPU_FPCCR_THREAD_Pos)

/* USER: User Privilege Level */
#define FPU_FPCCR_USER_Pos             1U
#define FPU_FPCCR_USER_Msk           (1UL << FPU_FPCCR_USER_Pos)

/* LSPACT: Lazy State Preservation Active */
#define FPU_FPCCR_LSPACT_Pos           0U
#define FPU_FPCCR_LSPACT_Msk         (1UL << FPU_FPCCR_LSPACT_Pos)

/*============================================================================*
 * FPU FPCAR Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.22
 *============================================================================*/
#define FPU_FPCAR_ADDRESS_Pos          3U
#define FPU_FPCAR_ADDRESS_Msk        (0x1FFFFFFFUL << FPU_FPCAR_ADDRESS_Pos)

/*============================================================================*
 * FPU FPDSCR Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.23
 *            - Floating Point Default Status Control Register, FPDSCR on page B3-617
 *============================================================================*/

/* AHP: Alternative Half-Precision */
#define FPU_FPDSCR_AHP_Pos            26U
#define FPU_FPDSCR_AHP_Msk          (1UL << FPU_FPDSCR_AHP_Pos)

/* DN: Default NaN */
#define FPU_FPDSCR_DN_Pos             25U
#define FPU_FPDSCR_DN_Msk           (1UL << FPU_FPDSCR_DN_Pos)

/* FZ: Flush-to-Zero */
#define FPU_FPDSCR_FZ_Pos             24U
#define FPU_FPDSCR_FZ_Msk           (1UL << FPU_FPDSCR_FZ_Pos)

/* RMode: Rounding Mode */
#define FPU_FPDSCR_RMode_Pos          22U
#define FPU_FPDSCR_RMode_Msk        (3UL << FPU_FPDSCR_RMode_Pos)

/* Rounding Mode Values */
#define FPU_FPDSCR_RMode_RN         0x0U  /*!< Round to Nearest (RN) */
#define FPU_FPDSCR_RMode_RP         0x1U  /*!< Round towards Plus Infinity (RP) */
#define FPU_FPDSCR_RMode_RM         0x2U  /*!< Round towards Minus Infinity (RM) */
#define FPU_FPDSCR_RMode_RZ         0x3U  /*!< Round towards Zero (RZ) */

/*============================================================================*
 * FPU MVFR0 Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B4.7.2
 *            - Media and FP Feature Register 0, MVFR0 on page B4-662
 *============================================================================*/

/* FP rounding modes */
#define FPU_MVFR0_FP_rounding_modes_Pos  28U
#define FPU_MVFR0_FP_rounding_modes_Msk (0xFUL << FPU_MVFR0_FP_rounding_modes_Pos)

/* Short vectors */
#define FPU_MVFR0_Short_vectors_Pos      24U
#define FPU_MVFR0_Short_vectors_Msk     (0xFUL << FPU_MVFR0_Short_vectors_Pos)

/* Square root */
#define FPU_MVFR0_Square_root_Pos        20U
#define FPU_MVFR0_Square_root_Msk       (0xFUL << FPU_MVFR0_Square_root_Pos)

/* Divide */
#define FPU_MVFR0_Divide_Pos             16U
#define FPU_MVFR0_Divide_Msk            (0xFUL << FPU_MVFR0_Divide_Pos)

/* FP exception trapping */
#define FPU_MVFR0_FP_excep_trapping_Pos  12U
#define FPU_MVFR0_FP_excep_trapping_Msk (0xFUL << FPU_MVFR0_FP_excep_trapping_Pos)

/* Double-precision */
#define FPU_MVFR0_Double_precision_Pos    8U
#define FPU_MVFR0_Double_precision_Msk  (0xFUL << FPU_MVFR0_Double_precision_Pos)

/* Single-precision */
#define FPU_MVFR0_Single_precision_Pos    4U
#define FPU_MVFR0_Single_precision_Msk  (0xFUL << FPU_MVFR0_Single_precision_Pos)

/* A_SIMD registers */
#define FPU_MVFR0_A_SIMD_registers_Pos    0U
#define FPU_MVFR0_A_SIMD_registers_Msk  (0xFUL << FPU_MVFR0_A_SIMD_registers_Pos)

/*============================================================================*
 * FPU MVFR1 Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B4.7.3
 *            - Media and FP Feature Register 1, MVFR1 on page B4-663
 *============================================================================*/

/* FP fused MAC */
#define FPU_MVFR1_FP_fused_MAC_Pos       28U
#define FPU_MVFR1_FP_fused_MAC_Msk      (0xFUL << FPU_MVFR1_FP_fused_MAC_Pos)

/* FP HPFP */
#define FPU_MVFR1_FP_HPFP_Pos            24U
#define FPU_MVFR1_FP_HPFP_Msk           (0xFUL << FPU_MVFR1_FP_HPFP_Pos)

/* D_NaN mode */
#define FPU_MVFR1_D_NaN_mode_Pos          4U
#define FPU_MVFR1_D_NaN_mode_Msk        (0xFUL << FPU_MVFR1_D_NaN_mode_Pos)

/* Flush-to-zero mode */
#define FPU_MVFR1_FtZ_mode_Pos            0U
#define FPU_MVFR1_FtZ_mode_Msk          (0xFUL << FPU_MVFR1_FtZ_mode_Pos)

/*============================================================================*
 * FPU MVFR2 Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B4.7.4
 *            - Media and FP Feature Register 2, MVFR2 on page B4-664
 *============================================================================*/

/* VFP_Misc */
#define FPU_MVFR2_VFP_Misc_Pos            4U
#define FPU_MVFR2_VFP_Misc_Msk          (0xFUL << FPU_MVFR2_VFP_Misc_Pos)

/*============================================================================*
 * FPU Feature Detection Values
 *============================================================================*/

/* MVFR0 Single-precision values */
#define FPU_MVFR0_SP_NOT_SUPPORTED    0x0U  /*!< Single-precision not supported */
#define FPU_MVFR0_SP_SUPPORTED        0x2U  /*!< Single-precision supported */

/* MVFR0 Double-precision values */
#define FPU_MVFR0_DP_NOT_SUPPORTED    0x0U  /*!< Double-precision not supported */
#define FPU_MVFR0_DP_SUPPORTED        0x2U  /*!< Double-precision supported */

/* MVFR1 Half-precision values */
#define FPU_MVFR1_HP_NOT_SUPPORTED    0x0U  /*!< Half-precision not supported */
#define FPU_MVFR1_HP_SUPPORTED        0x2U  /*!< Half-precision supported */

/*============================================================================*
 * Inline Functions - FPU Control
 *============================================================================*/

/**
 * @brief Check if FPU is present by reading MVFR0
 * @return 1 if FPU is present, 0 otherwise
 */
static inline uint32_t arm_v7m_fpu_is_present(void)
{
    return ((FPU->MVFR0 & FPU_MVFR0_A_SIMD_registers_Msk) != 0U) ? 1U : 0U;
}

/**
 * @brief Check if single-precision FPU is supported
 * @return 1 if supported, 0 otherwise
 */
static inline uint32_t arm_v7m_fpu_is_single_precision(void)
{
    return ((FPU->MVFR0 & FPU_MVFR0_Single_precision_Msk) >> FPU_MVFR0_Single_precision_Pos) == FPU_MVFR0_SP_SUPPORTED;
}

/**
 * @brief Check if double-precision FPU is supported
 * @return 1 if supported, 0 otherwise
 */
static inline uint32_t arm_v7m_fpu_is_double_precision(void)
{
    return ((FPU->MVFR0 & FPU_MVFR0_Double_precision_Msk) >> FPU_MVFR0_Double_precision_Pos) == FPU_MVFR0_DP_SUPPORTED;
}

/**
 * @brief Check if half-precision FPU is supported
 * @return 1 if supported, 0 otherwise
 */
static inline uint32_t arm_v7m_fpu_is_half_precision(void)
{
    return ((FPU->MVFR1 & FPU_MVFR1_FP_HPFP_Msk) >> FPU_MVFR1_FP_HPFP_Pos) == FPU_MVFR1_HP_SUPPORTED;
}

/**
 * @brief Get FPCCR register value
 * @return FPCCR value
 */
static inline uint32_t arm_v7m_fpu_get_fpccr(void)
{
    return FPU->FPCCR;
}

/**
 * @brief Set FPCCR register value
 * @param value Value to write
 */
static inline void arm_v7m_fpu_set_fpccr(uint32_t value)
{
    FPU->FPCCR = value;
}

/**
 * @brief Get FPCAR register value
 * @return FPCAR value
 */
static inline uint32_t arm_v7m_fpu_get_fpcar(void)
{
    return FPU->FPCAR;
}

/**
 * @brief Set FPCAR register value
 * @param value Value to write
 */
static inline void arm_v7m_fpu_set_fpcar(uint32_t value)
{
    FPU->FPCAR = value;
}

/**
 * @brief Get FPDSCR register value
 * @return FPDSCR value
 */
static inline uint32_t arm_v7m_fpu_get_fpdscr(void)
{
    return FPU->FPDSCR;
}

/**
 * @brief Set FPDSCR register value
 * @param value Value to write
 */
static inline void arm_v7m_fpu_set_fpdscr(uint32_t value)
{
    FPU->FPDSCR = value;
}

/**
 * @brief Get MVFR0 register value
 * @return MVFR0 value
 */
static inline uint32_t arm_v7m_fpu_get_mvfr0(void)
{
    return FPU->MVFR0;
}

/**
 * @brief Get MVFR1 register value
 * @return MVFR1 value
 */
static inline uint32_t arm_v7m_fpu_get_mvfr1(void)
{
    return FPU->MVFR1;
}

/**
 * @brief Get MVFR2 register value
 * @return MVFR2 value
 */
static inline uint32_t arm_v7m_fpu_get_mvfr2(void)
{
    return FPU->MVFR2;
}

/**
 * @brief Enable automatic state preservation (ASPEN)
 */
static inline void arm_v7m_fpu_enable_auto_save(void)
{
    FPU->FPCCR |= FPU_FPCCR_ASPEN_Msk;
}

/**
 * @brief Disable automatic state preservation (ASPEN)
 */
static inline void arm_v7m_fpu_disable_auto_save(void)
{
    FPU->FPCCR &= ~FPU_FPCCR_ASPEN_Msk;
}

/**
 * @brief Enable lazy stacking (LSPEN)
 */
static inline void arm_v7m_fpu_enable_lazy_stacking(void)
{
    FPU->FPCCR |= FPU_FPCCR_LSPEN_Msk;
}

/**
 * @brief Disable lazy stacking (LSPEN)
 */
static inline void arm_v7m_fpu_disable_lazy_stacking(void)
{
    FPU->FPCCR &= ~FPU_FPCCR_LSPEN_Msk;
}

/**
 * @brief Check if lazy state preservation is active
 * @return 1 if active, 0 otherwise
 */
static inline uint32_t arm_v7m_fpu_is_lazy_stacking_active(void)
{
    return (FPU->FPCCR & FPU_FPCCR_LSPACT_Msk) ? 1U : 0U;
}

/**
 * @brief Clear lazy state preservation active bit
 */
static inline void arm_v7m_fpu_clear_lazy_stacking_active(void)
{
    FPU->FPCCR &= ~FPU_FPCCR_LSPACT_Msk;
}

/**
 * @brief Set FPDSCR rounding mode
 * @param mode Rounding mode (FPU_FPDSCR_RMode_RN, RP, RM, RZ)
 */
static inline void arm_v7m_fpu_set_rounding_mode(uint32_t mode)
{
    FPU->FPDSCR = (FPU->FPDSCR & ~FPU_FPDSCR_RMode_Msk) | 
                  ((mode & 3U) << FPU_FPDSCR_RMode_Pos);
}

/**
 * @brief Get FPDSCR default rounding mode
 * @return Default rounding mode (used when exception occurs)
 * @note This is the default value, actual runtime control is via FPSCR
 */
static inline uint32_t arm_v7m_fpu_get_default_rounding_mode(void)
{
    return (FPU->FPDSCR & FPU_FPDSCR_RMode_Msk) >> FPU_FPDSCR_RMode_Pos;
}

/**
 * @brief Set FPDSCR default rounding mode
 * @param mode Default rounding mode (FPU_FPDSCR_RMode_RN, RP, RM, RZ)
 * @note This sets the default value, actual runtime control is via FPSCR
 */
static inline void arm_v7m_fpu_set_default_rounding_mode(uint32_t mode)
{
    FPU->FPDSCR = (FPU->FPDSCR & ~FPU_FPDSCR_RMode_Msk) | 
                  ((mode & 3U) << FPU_FPDSCR_RMode_Pos);
}

/*============================================================================*
 * FPSCR Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section A2.5
 *            - Floating-point Status and Control Register, FPSCR on page A2-37
 *============================================================================*/

/* Condition flags */
#define FPU_FPSCR_N_Pos               31U
#define FPU_FPSCR_N_Msk              (1UL << FPU_FPSCR_N_Pos)
#define FPU_FPSCR_Z_Pos               30U
#define FPU_FPSCR_Z_Msk              (1UL << FPU_FPSCR_Z_Pos)
#define FPU_FPSCR_C_Pos               29U
#define FPU_FPSCR_C_Msk              (1UL << FPU_FPSCR_C_Pos)
#define FPU_FPSCR_V_Pos               28U
#define FPU_FPSCR_V_Msk              (1UL << FPU_FPSCR_V_Pos)

/* Control bits */
#define FPU_FPSCR_AHP_Pos             26U
#define FPU_FPSCR_AHP_Msk            (1UL << FPU_FPSCR_AHP_Pos)
#define FPU_FPSCR_DN_Pos              25U
#define FPU_FPSCR_DN_Msk             (1UL << FPU_FPSCR_DN_Pos)
#define FPU_FPSCR_FZ_Pos              24U
#define FPU_FPSCR_FZ_Msk             (1UL << FPU_FPSCR_FZ_Pos)
#define FPU_FPSCR_RMode_Pos           22U
#define FPU_FPSCR_RMode_Msk          (3UL << FPU_FPSCR_RMode_Pos)

/* Cumulative exception flags */
#define FPU_FPSCR_IDC_Pos              7U
#define FPU_FPSCR_IDC_Msk            (1UL << FPU_FPSCR_IDC_Pos)
#define FPU_FPSCR_IXC_Pos              4U
#define FPU_FPSCR_IXC_Msk            (1UL << FPU_FPSCR_IXC_Pos)
#define FPU_FPSCR_UFC_Pos              3U
#define FPU_FPSCR_UFC_Msk            (1UL << FPU_FPSCR_UFC_Pos)
#define FPU_FPSCR_OFC_Pos              2U
#define FPU_FPSCR_OFC_Msk            (1UL << FPU_FPSCR_OFC_Pos)
#define FPU_FPSCR_DZC_Pos              1U
#define FPU_FPSCR_DZC_Msk            (1UL << FPU_FPSCR_DZC_Pos)
#define FPU_FPSCR_IOC_Pos              0U
#define FPU_FPSCR_IOC_Msk            (1UL << FPU_FPSCR_IOC_Pos)

/* All cumulative exception flags */
#define FPU_FPSCR_CUMULATIVE_EXCEPTIONS_Msk (FPU_FPSCR_IDC_Msk | FPU_FPSCR_IXC_Msk | \
                                             FPU_FPSCR_UFC_Msk | FPU_FPSCR_OFC_Msk | \
                                             FPU_FPSCR_DZC_Msk | FPU_FPSCR_IOC_Msk)

/*============================================================================*
 * Inline Functions - FPSCR Access
 *============================================================================*/

/**
 * @brief Get FPSCR (Floating-Point Status and Control Register)
 * @return FPSCR value
 * @note Uses VMRS instruction
 */
static inline uint32_t arm_v7m_fpu_get_fpscr(void)
{
    uint32_t fpscr;
    __asm__ volatile ("vmrs %0, fpscr" : "=r" (fpscr));
    return fpscr;
}

/**
 * @brief Set FPSCR (Floating-Point Status and Control Register)
 * @param fpscr Value to write
 * @note Uses VMSR instruction
 */
static inline void arm_v7m_fpu_set_fpscr(uint32_t fpscr)
{
    __asm__ volatile ("vmsr fpscr, %0" :: "r" (fpscr));
}

/**
 * @brief Get FPSCR condition flags (N, Z, C, V)
 * @return Condition flags in bits [31:28]
 */
static inline uint32_t arm_v7m_fpu_get_condition_flags(void)
{
    return arm_v7m_fpu_get_fpscr() & (FPU_FPSCR_N_Msk | FPU_FPSCR_Z_Msk | 
                                       FPU_FPSCR_C_Msk | FPU_FPSCR_V_Msk);
}

/**
 * @brief Clear all cumulative exception flags in FPSCR
 */
static inline void arm_v7m_fpu_clear_exceptions(void)
{
    uint32_t fpscr = arm_v7m_fpu_get_fpscr();
    fpscr &= ~FPU_FPSCR_CUMULATIVE_EXCEPTIONS_Msk;
    arm_v7m_fpu_set_fpscr(fpscr);
}

/**
 * @brief Check if Input Denormal exception occurred
 * @return 1 if exception occurred, 0 otherwise
 */
static inline uint32_t arm_v7m_fpu_is_idc_exception(void)
{
    return (arm_v7m_fpu_get_fpscr() & FPU_FPSCR_IDC_Msk) ? 1U : 0U;
}

/**
 * @brief Check if Inexact exception occurred
 * @return 1 if exception occurred, 0 otherwise
 */
static inline uint32_t arm_v7m_fpu_is_ixc_exception(void)
{
    return (arm_v7m_fpu_get_fpscr() & FPU_FPSCR_IXC_Msk) ? 1U : 0U;
}

/**
 * @brief Check if Underflow exception occurred
 * @return 1 if exception occurred, 0 otherwise
 */
static inline uint32_t arm_v7m_fpu_is_ufc_exception(void)
{
    return (arm_v7m_fpu_get_fpscr() & FPU_FPSCR_UFC_Msk) ? 1U : 0U;
}

/**
 * @brief Check if Overflow exception occurred
 * @return 1 if exception occurred, 0 otherwise
 */
static inline uint32_t arm_v7m_fpu_is_ofc_exception(void)
{
    return (arm_v7m_fpu_get_fpscr() & FPU_FPSCR_OFC_Msk) ? 1U : 0U;
}

/**
 * @brief Check if Division by Zero exception occurred
 * @return 1 if exception occurred, 0 otherwise
 */
static inline uint32_t arm_v7m_fpu_is_dzc_exception(void)
{
    return (arm_v7m_fpu_get_fpscr() & FPU_FPSCR_DZC_Msk) ? 1U : 0U;
}

/**
 * @brief Check if Invalid Operation exception occurred
 * @return 1 if exception occurred, 0 otherwise
 */
static inline uint32_t arm_v7m_fpu_is_ioc_exception(void)
{
    return (arm_v7m_fpu_get_fpscr() & FPU_FPSCR_IOC_Msk) ? 1U : 0U;
}

/**
 * @brief Set FPSCR rounding mode
 * @param mode Rounding mode (0-3)
 */
static inline void arm_v7m_fpu_set_fpscr_rounding_mode(uint32_t mode)
{
    uint32_t fpscr = arm_v7m_fpu_get_fpscr();
    fpscr &= ~FPU_FPSCR_RMode_Msk;
    fpscr |= (mode & 3U) << FPU_FPSCR_RMode_Pos;
    arm_v7m_fpu_set_fpscr(fpscr);
}

/**
 * @brief Get FPSCR rounding mode
 * @return Current rounding mode (0-3)
 */
static inline uint32_t arm_v7m_fpu_get_fpscr_rounding_mode(void)
{
    return (arm_v7m_fpu_get_fpscr() & FPU_FPSCR_RMode_Msk) >> FPU_FPSCR_RMode_Pos;
}

/**
 * @brief Enable flush-to-zero mode in FPSCR
 */
static inline void arm_v7m_fpu_enable_fpscr_fz(void)
{
    arm_v7m_fpu_set_fpscr(arm_v7m_fpu_get_fpscr() | FPU_FPSCR_FZ_Msk);
}

/**
 * @brief Disable flush-to-zero mode in FPSCR
 */
static inline void arm_v7m_fpu_disable_fpscr_fz(void)
{
    arm_v7m_fpu_set_fpscr(arm_v7m_fpu_get_fpscr() & ~FPU_FPSCR_FZ_Msk);
}

/**
 * @brief Enable default NaN mode in FPSCR
 */
static inline void arm_v7m_fpu_enable_fpscr_dn(void)
{
    arm_v7m_fpu_set_fpscr(arm_v7m_fpu_get_fpscr() | FPU_FPSCR_DN_Msk);
}

/**
 * @brief Disable default NaN mode in FPSCR
 */
static inline void arm_v7m_fpu_disable_fpscr_dn(void)
{
    arm_v7m_fpu_set_fpscr(arm_v7m_fpu_get_fpscr() & ~FPU_FPSCR_DN_Msk);
}

/**
 * @brief Enable alternative half-precision mode in FPSCR
 */
static inline void arm_v7m_fpu_enable_fpscr_ahp(void)
{
    arm_v7m_fpu_set_fpscr(arm_v7m_fpu_get_fpscr() | FPU_FPSCR_AHP_Msk);
}

/**
 * @brief Disable alternative half-precision mode in FPSCR
 */
static inline void arm_v7m_fpu_disable_fpscr_ahp(void)
{
    arm_v7m_fpu_set_fpscr(arm_v7m_fpu_get_fpscr() & ~FPU_FPSCR_AHP_Msk);
}

/*============================================================================*
 * Non-Inline Functions
 *============================================================================*/

/**
 * @brief Enable FPU (set CP10/CP11 access in CPACR and enable FPU context)
 * @note Must be called before using FPU instructions
 */
void arm_v7m_fpu_enable(void);

/**
 * @brief Disable FPU (disable FPU context and clear CPACR access bits)
 */
void arm_v7m_fpu_disable(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_FPU_H */
