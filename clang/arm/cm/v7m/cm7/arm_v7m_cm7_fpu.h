/*
 * arm_v7m_cm7_fpu.h
 * Cortex-M7 Floating-Point Unit (FPU) Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section A2.5
 *            - The optional Floating-point Extension on page A2-34
 *            - Section B3.2.21: Floating Point Context Control Register, FPCCR on page B3-615
 *            - Section B3.2.22: Floating Point Context Address Register, FPCAR on page B3-617
 *            - Section B3.2.23: Floating Point Default Status Control Register, FPDSCR on page B3-617
 *            - Section B4.7.2: Media and FP Feature Register 0, MVFR0 on page B4-662
 *            - Section B4.7.3: Media and FP Feature Register 1, MVFR1 on page B4-663
 *            Cortex-M7 Devices Generic User Guide, Chapter 4.7
 *            - Floating Point Unit on page 4-55
 *            - Section 4.7.1: Coprocessor Access Control Register on page 4-55
 *            - Section 4.7.2: Floating-point Context Control Register on page 4-56
 *            - Section 4.7.3: Floating-point Context Address Register on page 4-57
 *            - Section 4.7.4: Floating-point Status Control Register on page 4-58
 *            - Section 4.7.5: Enabling the FPU on page 4-59
 *            Cortex-M7 Technical Reference Manual, Chapter 8
 *            - Floating Point Unit on page 8-1
 *            - Section 8.1: About the FPU on page 8-2
 *            - Section 8.2: FPU functional description on page 8-3
 *            - Section 8.3: FPU programmers model on page 8-5
 *
 * @note This file reuses Armv7-M generic FPU definitions.
 */

#ifndef ARM_V7M_CM7_FPU_H
#define ARM_V7M_CM7_FPU_H

#include <stdint.h>
#include "../arm_v7m_fpu.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Compiler Abstraction - Inline Definition
 *============================================================================*/

#if defined(__clang__)
    #define ARM_V7M_CM7_FPU_INLINE static inline __attribute__((always_inline))
#else
    #error "This library requires Clang/LLVM compiler."
#endif

/*============================================================================*
 * Type Aliases
 *============================================================================*/

typedef arm_v7m_fpu_regs_t      arm_v7m_cm7_fpu_regs_t;

/*============================================================================*
 * Constant Aliases - FPCCR Bit Definitions
 *============================================================================*/

#define ARM_V7M_CM7_FPU_FPCCR_ASPEN_Pos        ARM_V7M_FPU_FPCCR_ASPEN_Pos
#define ARM_V7M_CM7_FPU_FPCCR_ASPEN_Msk        ARM_V7M_FPU_FPCCR_ASPEN_Msk
#define ARM_V7M_CM7_FPU_FPCCR_LSPEN_Pos        ARM_V7M_FPU_FPCCR_LSPEN_Pos
#define ARM_V7M_CM7_FPU_FPCCR_LSPEN_Msk        ARM_V7M_FPU_FPCCR_LSPEN_Msk
#define ARM_V7M_CM7_FPU_FPCCR_MONRDY_Pos       ARM_V7M_FPU_FPCCR_MONRDY_Pos
#define ARM_V7M_CM7_FPU_FPCCR_MONRDY_Msk       ARM_V7M_FPU_FPCCR_MONRDY_Msk
#define ARM_V7M_CM7_FPU_FPCCR_BFRDY_Pos        ARM_V7M_FPU_FPCCR_BFRDY_Pos
#define ARM_V7M_CM7_FPU_FPCCR_BFRDY_Msk        ARM_V7M_FPU_FPCCR_BFRDY_Msk
#define ARM_V7M_CM7_FPU_FPCCR_MMRDY_Pos        ARM_V7M_FPU_FPCCR_MMRDY_Pos
#define ARM_V7M_CM7_FPU_FPCCR_MMRDY_Msk        ARM_V7M_FPU_FPCCR_MMRDY_Msk
#define ARM_V7M_CM7_FPU_FPCCR_HFRDY_Pos        ARM_V7M_FPU_FPCCR_HFRDY_Pos
#define ARM_V7M_CM7_FPU_FPCCR_HFRDY_Msk        ARM_V7M_FPU_FPCCR_HFRDY_Msk
#define ARM_V7M_CM7_FPU_FPCCR_THREAD_Pos       ARM_V7M_FPU_FPCCR_THREAD_Pos
#define ARM_V7M_CM7_FPU_FPCCR_THREAD_Msk       ARM_V7M_FPU_FPCCR_THREAD_Msk
#define ARM_V7M_CM7_FPU_FPCCR_USER_Pos         ARM_V7M_FPU_FPCCR_USER_Pos
#define ARM_V7M_CM7_FPU_FPCCR_USER_Msk         ARM_V7M_FPU_FPCCR_USER_Msk
#define ARM_V7M_CM7_FPU_FPCCR_LSPACT_Pos       ARM_V7M_FPU_FPCCR_LSPACT_Pos
#define ARM_V7M_CM7_FPU_FPCCR_LSPACT_Msk       ARM_V7M_FPU_FPCCR_LSPACT_Msk

/*============================================================================*
 * Constant Aliases - FPDSCR Bit Definitions
 *============================================================================*/

#define ARM_V7M_CM7_FPU_FPDSCR_AHP_Pos         ARM_V7M_FPU_FPDSCR_AHP_Pos
#define ARM_V7M_CM7_FPU_FPDSCR_AHP_Msk         ARM_V7M_FPU_FPDSCR_AHP_Msk
#define ARM_V7M_CM7_FPU_FPDSCR_DN_Pos          ARM_V7M_FPU_FPDSCR_DN_Pos
#define ARM_V7M_CM7_FPU_FPDSCR_DN_Msk          ARM_V7M_FPU_FPDSCR_DN_Msk
#define ARM_V7M_CM7_FPU_FPDSCR_FZ_Pos          ARM_V7M_FPU_FPDSCR_FZ_Pos
#define ARM_V7M_CM7_FPU_FPDSCR_FZ_Msk          ARM_V7M_FPU_FPDSCR_FZ_Msk
#define ARM_V7M_CM7_FPU_FPDSCR_RMode_Pos       ARM_V7M_FPU_FPDSCR_RMode_Pos
#define ARM_V7M_CM7_FPU_FPDSCR_RMode_Msk       ARM_V7M_FPU_FPDSCR_RMode_Msk

/* Rounding Mode Values */
#define ARM_V7M_CM7_FPU_FPDSCR_RMode_RN        FPU_FPDSCR_RMode_RN
#define ARM_V7M_CM7_FPU_FPDSCR_RMode_RP        FPU_FPDSCR_RMode_RP
#define ARM_V7M_CM7_FPU_FPDSCR_RMode_RM        FPU_FPDSCR_RMode_RM
#define ARM_V7M_CM7_FPU_FPDSCR_RMode_RZ        FPU_FPDSCR_RMode_RZ

/*============================================================================*
 * Constant Aliases - MVFR0 Bit Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B4.7.2
 *============================================================================*/

#define ARM_V7M_CM7_FPU_MVFR0_FP_rounding_modes_Pos  FPU_MVFR0_FP_rounding_modes_Pos
#define ARM_V7M_CM7_FPU_MVFR0_FP_rounding_modes_Msk  FPU_MVFR0_FP_rounding_modes_Msk
#define ARM_V7M_CM7_FPU_MVFR0_Short_vectors_Pos      FPU_MVFR0_Short_vectors_Pos
#define ARM_V7M_CM7_FPU_MVFR0_Short_vectors_Msk      FPU_MVFR0_Short_vectors_Msk
#define ARM_V7M_CM7_FPU_MVFR0_Square_root_Pos        FPU_MVFR0_Square_root_Pos
#define ARM_V7M_CM7_FPU_MVFR0_Square_root_Msk        FPU_MVFR0_Square_root_Msk
#define ARM_V7M_CM7_FPU_MVFR0_Divide_Pos             FPU_MVFR0_Divide_Pos
#define ARM_V7M_CM7_FPU_MVFR0_Divide_Msk             FPU_MVFR0_Divide_Msk
#define ARM_V7M_CM7_FPU_MVFR0_FP_excep_trapping_Pos  FPU_MVFR0_FP_excep_trapping_Pos
#define ARM_V7M_CM7_FPU_MVFR0_FP_excep_trapping_Msk  FPU_MVFR0_FP_excep_trapping_Msk
#define ARM_V7M_CM7_FPU_MVFR0_Double_precision_Pos   FPU_MVFR0_Double_precision_Pos
#define ARM_V7M_CM7_FPU_MVFR0_Double_precision_Msk   FPU_MVFR0_Double_precision_Msk
#define ARM_V7M_CM7_FPU_MVFR0_Single_precision_Pos   FPU_MVFR0_Single_precision_Pos
#define ARM_V7M_CM7_FPU_MVFR0_Single_precision_Msk   FPU_MVFR0_Single_precision_Msk
#define ARM_V7M_CM7_FPU_MVFR0_A_SIMD_registers_Pos   FPU_MVFR0_A_SIMD_registers_Pos
#define ARM_V7M_CM7_FPU_MVFR0_A_SIMD_registers_Msk   FPU_MVFR0_A_SIMD_registers_Msk

/* Feature Detection Values */
#define ARM_V7M_CM7_FPU_MVFR0_SP_NOT_SUPPORTED     FPU_MVFR0_SP_NOT_SUPPORTED
#define ARM_V7M_CM7_FPU_MVFR0_SP_SUPPORTED         FPU_MVFR0_SP_SUPPORTED
#define ARM_V7M_CM7_FPU_MVFR0_DP_NOT_SUPPORTED     FPU_MVFR0_DP_NOT_SUPPORTED
#define ARM_V7M_CM7_FPU_MVFR0_DP_SUPPORTED         FPU_MVFR0_DP_SUPPORTED

/*============================================================================*
 * Constant Aliases - MVFR1 Bit Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B4.7.3
 *============================================================================*/

#define ARM_V7M_CM7_FPU_MVFR1_FP_fused_MAC_Pos       FPU_MVFR1_FP_fused_MAC_Pos
#define ARM_V7M_CM7_FPU_MVFR1_FP_fused_MAC_Msk       FPU_MVFR1_FP_fused_MAC_Msk
#define ARM_V7M_CM7_FPU_MVFR1_FP_HPFP_Pos            FPU_MVFR1_FP_HPFP_Pos
#define ARM_V7M_CM7_FPU_MVFR1_FP_HPFP_Msk            FPU_MVFR1_FP_HPFP_Msk
#define ARM_V7M_CM7_FPU_MVFR1_D_NaN_mode_Pos         FPU_MVFR1_D_NaN_mode_Pos
#define ARM_V7M_CM7_FPU_MVFR1_D_NaN_mode_Msk         FPU_MVFR1_D_NaN_mode_Msk
#define ARM_V7M_CM7_FPU_MVFR1_FtZ_mode_Pos           FPU_MVFR1_FtZ_mode_Pos
#define ARM_V7M_CM7_FPU_MVFR1_FtZ_mode_Msk           FPU_MVFR1_FtZ_mode_Msk

#define ARM_V7M_CM7_FPU_MVFR1_HP_NOT_SUPPORTED       FPU_MVFR1_HP_NOT_SUPPORTED
#define ARM_V7M_CM7_FPU_MVFR1_HP_SUPPORTED           FPU_MVFR1_HP_SUPPORTED

/*============================================================================*
 * SCB CPACR Register Definitions for FPU Access
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.19
 *            - Coprocessor Access Control Register, CPACR on page B3-614
 *============================================================================*/

#define ARM_V7M_CM7_FPU_CPACR_CP10_Pos            20U
#define ARM_V7M_CM7_FPU_CPACR_CP10_Msk          (3UL << ARM_V7M_CM7_FPU_CPACR_CP10_Pos)
#define ARM_V7M_CM7_FPU_CPACR_CP11_Pos            22U
#define ARM_V7M_CM7_FPU_CPACR_CP11_Msk          (3UL << ARM_V7M_CM7_FPU_CPACR_CP11_Pos)

/* CPACR Access Values */
#define ARM_V7M_CM7_FPU_CPACR_CP_ACCESS_DENIED    0x0U
#define ARM_V7M_CM7_FPU_CPACR_CP_PRIV_ACCESS      0x1U
#define ARM_V7M_CM7_FPU_CPACR_CP_RESERVED         0x2U
#define ARM_V7M_CM7_FPU_CPACR_CP_FULL_ACCESS      0x3U

/*============================================================================*
 * Inline Functions - CP10/CP11 Access Control
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.19
 *============================================================================*/

/**
 * @brief Enable CP10 and CP11 full access in CPACR
 * @note This enables access to the floating-point coprocessor
 * @note Must be executed in privileged mode
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_enable_cp10_cp11(void) {
    volatile uint32_t *cpacr = (volatile uint32_t *)0xE000ED88UL;
    *cpacr |= ((ARM_V7M_CM7_FPU_CPACR_CP_FULL_ACCESS << ARM_V7M_CM7_FPU_CPACR_CP10_Pos) |
               (ARM_V7M_CM7_FPU_CPACR_CP_FULL_ACCESS << ARM_V7M_CM7_FPU_CPACR_CP11_Pos));
}

/**
 * @brief Disable CP10 and CP11 access in CPACR
 * @note This disables access to the floating-point coprocessor
 * @note Must be executed in privileged mode
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_disable_cp10_cp11(void) {
    volatile uint32_t *cpacr = (volatile uint32_t *)0xE000ED88UL;
    *cpacr &= ~((ARM_V7M_CM7_FPU_CPACR_CP10_Msk) | (ARM_V7M_CM7_FPU_CPACR_CP11_Msk));
}

/*============================================================================*
 * Inline Functions - FPU Register Access
 *============================================================================*/

/**
 * @brief Check if FPU is present
 * @return 1 if FPU is present, 0 otherwise
 * @reference ARMv7-M Architecture Reference Manual, Section B4.7.2
 */
ARM_V7M_CM7_FPU_INLINE uint32_t arm_v7m_cm7_fpu_is_present(void) {
    return arm_v7m_fpu_is_present();
}

/**
 * @brief Check if single-precision FPU is supported
 * @return 1 if supported, 0 otherwise
 * @reference ARMv7-M Architecture Reference Manual, Section B4.7.2
 */
ARM_V7M_CM7_FPU_INLINE uint32_t arm_v7m_cm7_fpu_is_single_precision(void) {
    return arm_v7m_fpu_is_single_precision();
}

/**
 * @brief Check if double-precision FPU is supported
 * @return 1 if supported, 0 otherwise
 * @reference ARMv7-M Architecture Reference Manual, Section B4.7.2
 */
ARM_V7M_CM7_FPU_INLINE uint32_t arm_v7m_cm7_fpu_is_double_precision(void) {
    return arm_v7m_fpu_is_double_precision();
}

/**
 * @brief Check if half-precision FPU is supported
 * @return 1 if supported, 0 otherwise
 * @reference ARMv7-M Architecture Reference Manual, Section B4.7.3
 */
ARM_V7M_CM7_FPU_INLINE uint32_t arm_v7m_cm7_fpu_is_half_precision(void) {
    return arm_v7m_fpu_is_half_precision();
}

/**
 * @brief Get FPCCR register value
 * @return Current FPCCR value
 * @reference ARMv7-M Architecture Reference Manual, Section B3.2.21
 */
ARM_V7M_CM7_FPU_INLINE uint32_t arm_v7m_cm7_fpu_get_fpccr(void) {
    return arm_v7m_fpu_get_fpccr();
}

/**
 * @brief Set FPCCR register value
 * @param value Value to write
 * @reference ARMv7-M Architecture Reference Manual, Section B3.2.21
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_set_fpccr(uint32_t value) {
    arm_v7m_fpu_set_fpccr(value);
}

/**
 * @brief Get FPCAR register value
 * @return Current FPCAR value
 * @reference ARMv7-M Architecture Reference Manual, Section B3.2.22
 */
ARM_V7M_CM7_FPU_INLINE uint32_t arm_v7m_cm7_fpu_get_fpcar(void) {
    return arm_v7m_fpu_get_fpcar();
}

/**
 * @brief Set FPCAR register value
 * @param value Value to write
 * @reference ARMv7-M Architecture Reference Manual, Section B3.2.22
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_set_fpcar(uint32_t value) {
    arm_v7m_fpu_set_fpcar(value);
}

/**
 * @brief Get FPDSCR register value
 * @return Current FPDSCR value
 * @reference ARMv7-M Architecture Reference Manual, Section B3.2.23
 */
ARM_V7M_CM7_FPU_INLINE uint32_t arm_v7m_cm7_fpu_get_fpdscr(void) {
    return arm_v7m_fpu_get_fpdscr();
}

/**
 * @brief Set FPDSCR register value
 * @param value Value to write
 * @reference ARMv7-M Architecture Reference Manual, Section B3.2.23
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_set_fpdscr(uint32_t value) {
    arm_v7m_fpu_set_fpdscr(value);
}

/**
 * @brief Get MVFR0 register value
 * @return Current MVFR0 value
 * @reference ARMv7-M Architecture Reference Manual, Section B4.7.2
 */
ARM_V7M_CM7_FPU_INLINE uint32_t arm_v7m_cm7_fpu_get_mvfr0(void) {
    return arm_v7m_fpu_get_mvfr0();
}

/**
 * @brief Get MVFR1 register value
 * @return Current MVFR1 value
 * @reference ARMv7-M Architecture Reference Manual, Section B4.7.3
 */
ARM_V7M_CM7_FPU_INLINE uint32_t arm_v7m_cm7_fpu_get_mvfr1(void) {
    return arm_v7m_fpu_get_mvfr1();
}

/**
 * @brief Get MVFR2 register value
 * @return Current MVFR2 value
 * @reference ARMv7-M Architecture Reference Manual, Section B4.7.4
 */
ARM_V7M_CM7_FPU_INLINE uint32_t arm_v7m_cm7_fpu_get_mvfr2(void) {
    return arm_v7m_fpu_get_mvfr2();
}

/**
 * @brief Enable automatic state preservation (ASPEN)
 * @reference ARMv7-M Architecture Reference Manual, Section B3.2.21
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_enable_auto_save(void) {
    arm_v7m_fpu_enable_auto_save();
}

/**
 * @brief Disable automatic state preservation (ASPEN)
 * @reference ARMv7-M Architecture Reference Manual, Section B3.2.21
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_disable_auto_save(void) {
    arm_v7m_fpu_disable_auto_save();
}

/**
 * @brief Enable lazy stacking (LSPEN)
 * @reference ARMv7-M Architecture Reference Manual, Section B3.2.21
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_enable_lazy_stacking(void) {
    arm_v7m_fpu_enable_lazy_stacking();
}

/**
 * @brief Disable lazy stacking (LSPEN)
 * @reference ARMv7-M Architecture Reference Manual, Section B3.2.21
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_disable_lazy_stacking(void) {
    arm_v7m_fpu_disable_lazy_stacking();
}

/**
 * @brief Check if lazy state preservation is active
 * @return 1 if active, 0 otherwise
 * @reference ARMv7-M Architecture Reference Manual, Section B3.2.21
 */
ARM_V7M_CM7_FPU_INLINE uint32_t arm_v7m_cm7_fpu_is_lazy_stacking_active(void) {
    return arm_v7m_fpu_is_lazy_stacking_active();
}

/**
 * @brief Clear lazy state preservation active bit
 * @reference ARMv7-M Architecture Reference Manual, Section B3.2.21
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_clear_lazy_stacking_active(void) {
    arm_v7m_fpu_clear_lazy_stacking_active();
}

/**
 * @brief Set FPDSCR rounding mode
 * @param mode Rounding mode (ARM_V7M_CM7_FPU_FPDSCR_RMode_RN, RP, RM, RZ)
 * @reference ARMv7-M Architecture Reference Manual, Section B3.2.23
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_set_rounding_mode(uint32_t mode) {
    arm_v7m_fpu_set_rounding_mode(mode);
}

/**
 * @brief Get FPDSCR default rounding mode
 * @return Default rounding mode
 * @reference ARMv7-M Architecture Reference Manual, Section B3.2.23
 */
ARM_V7M_CM7_FPU_INLINE uint32_t arm_v7m_cm7_fpu_get_default_rounding_mode(void) {
    return arm_v7m_fpu_get_default_rounding_mode();
}

/**
 * @brief Set FPDSCR default rounding mode
 * @param mode Default rounding mode
 * @reference ARMv7-M Architecture Reference Manual, Section B3.2.23
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_set_default_rounding_mode(uint32_t mode) {
    arm_v7m_fpu_set_default_rounding_mode(mode);
}

/*============================================================================*
 * FPSCR Access Functions (Aliased from generic)
 *============================================================================*/

/**
 * @brief Get FPSCR (Floating-Point Status and Control Register)
 * @return FPSCR value
 * @reference ARMv7-M Architecture Reference Manual, Section A2.5
 */
ARM_V7M_CM7_FPU_INLINE uint32_t arm_v7m_cm7_fpu_get_fpscr(void) {
    return arm_v7m_fpu_get_fpscr();
}

/**
 * @brief Set FPSCR (Floating-Point Status and Control Register)
 * @param fpscr Value to write
 * @reference ARMv7-M Architecture Reference Manual, Section A2.5
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_set_fpscr(uint32_t fpscr) {
    arm_v7m_fpu_set_fpscr(fpscr);
}

/**
 * @brief Get FPSCR condition flags (N, Z, C, V)
 * @return Condition flags in bits [31:28]
 * @reference ARMv7-M Architecture Reference Manual, Section A2.5
 */
ARM_V7M_CM7_FPU_INLINE uint32_t arm_v7m_cm7_fpu_get_condition_flags(void) {
    return arm_v7m_fpu_get_condition_flags();
}

/**
 * @brief Clear all cumulative exception flags in FPSCR
 * @reference ARMv7-M Architecture Reference Manual, Section A2.5
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_clear_exceptions(void) {
    arm_v7m_fpu_clear_exceptions();
}

/**
 * @brief Set FPSCR rounding mode
 * @param mode Rounding mode (0-3)
 * @reference ARMv7-M Architecture Reference Manual, Section A2.5
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_set_fpscr_rounding_mode(uint32_t mode) {
    arm_v7m_fpu_set_fpscr_rounding_mode(mode);
}

/**
 * @brief Get FPSCR rounding mode
 * @return Current rounding mode (0-3)
 * @reference ARMv7-M Architecture Reference Manual, Section A2.5
 */
ARM_V7M_CM7_FPU_INLINE uint32_t arm_v7m_cm7_fpu_get_fpscr_rounding_mode(void) {
    return arm_v7m_fpu_get_fpscr_rounding_mode();
}

/**
 * @brief Enable flush-to-zero mode in FPSCR
 * @reference ARMv7-M Architecture Reference Manual, Section A2.5
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_enable_fpscr_fz(void) {
    arm_v7m_fpu_enable_fpscr_fz();
}

/**
 * @brief Disable flush-to-zero mode in FPSCR
 * @reference ARMv7-M Architecture Reference Manual, Section A2.5
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_disable_fpscr_fz(void) {
    arm_v7m_fpu_disable_fpscr_fz();
}

/**
 * @brief Enable default NaN mode in FPSCR
 * @reference ARMv7-M Architecture Reference Manual, Section A2.5
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_enable_fpscr_dn(void) {
    arm_v7m_fpu_enable_fpscr_dn();
}

/**
 * @brief Disable default NaN mode in FPSCR
 * @reference ARMv7-M Architecture Reference Manual, Section A2.5
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_disable_fpscr_dn(void) {
    arm_v7m_fpu_disable_fpscr_dn();
}

/**
 * @brief Enable alternative half-precision mode in FPSCR
 * @reference ARMv7-M Architecture Reference Manual, Section A2.5
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_enable_fpscr_ahp(void) {
    arm_v7m_fpu_enable_fpscr_ahp();
}

/**
 * @brief Disable alternative half-precision mode in FPSCR
 * @reference ARMv7-M Architecture Reference Manual, Section A2.5
 */
ARM_V7M_CM7_FPU_INLINE void arm_v7m_cm7_fpu_disable_fpscr_ahp(void) {
    arm_v7m_fpu_disable_fpscr_ahp();
}

/*============================================================================*
 * Non-Inline Functions - Complex Operations
 *============================================================================*/

/**
 * @brief Enable FPU (set CP10/CP11 access and enable FPU context)
 * @note Must be called before using FPU instructions
 * @note Must be executed in privileged mode
 * @reference Cortex-M7 Devices Generic User Guide, Section 4.7.5
 *            ARMv7-M Architecture Reference Manual, Section B3.2.19
 */
void arm_v7m_cm7_fpu_enable(void);

/**
 * @brief Disable FPU (disable FPU context and clear CPACR access bits)
 * @note Must be executed in privileged mode
 * @reference ARMv7-M Architecture Reference Manual, Section B3.2.19
 */
void arm_v7m_cm7_fpu_disable(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM7_FPU_H */
