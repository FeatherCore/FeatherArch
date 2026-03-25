/*
 * ARM Architecture - Cortex-M4 FPU (Floating Point Unit)
 *
 * ============================================================================
 * File: cm4_fpu.h
 * Description: Cortex-M4 FPU register definitions (wrapper for armv7-m_fpu.h)
 * 描述: Cortex-M4 FPU 寄存器定义（armv7-m_fpu.h 的包装层）
 *
 * This file provides CM4-specific naming conventions while delegating
 * all actual definitions to armv7-m_fpu.h.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.6 Floating Point Unit (page 4-48)
 *   - Table 4-49 Cortex-M4 Floating Point system registers (page 4-48)
 *
 * Implementation: All functionality is provided by armv7-m/armv7-m_fpu.h
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_FPU_H__
#define __CM4_FPU_H__

#include <stdint.h>

/* Include the underlying ARMv7-M implementation */
#include "armv7-m/armv7-m_fpu.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * FPU Base Address
 * FPU 基地址
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-49 (page 4-48)
 * ============================================================================
 */

#define CM4_FPU_BASE_ADDR             FPU_BASE_ADDR

/*
 * ============================================================================
 * FPU Register Aliases - Map CM4 naming to ARMv7-M naming
 * FPU 寄存器别名 - 将 CM4 命名映射到 ARMv7-M 命名
 * ============================================================================
 */

/* Floating-Point Context Control Register */
#define FPU_FPCCR                     FPU_FPCCR

/* FPCCR bit definitions */
#define FPU_FPCCR_ASPEN_Pos           FPCCR_ASPEN_Pos
#define FPU_FPCCR_ASPEN_Msk           FPCCR_ASPEN_Msk
#define FPU_FPCCR_LSPEN_Pos           FPCCR_LSPEN_Pos
#define FPU_FPCCR_LSPEN_Msk           FPCCR_LSPEN_Msk
#define FPU_FPCCR_MONRDY_Pos          FPCCR_MONRDY_Pos
#define FPU_FPCCR_MONRDY_Msk          FPCCR_MONRDY_Msk
#define FPU_FPCCR_BFRDY_Pos           FPCCR_BFRDY_Pos
#define FPU_FPCCR_BFRDY_Msk           FPCCR_BFRDY_Msk
#define FPU_FPCCR_MMRDY_Pos           FPCCR_MMRDY_Pos
#define FPU_FPCCR_MMRDY_Msk           FPCCR_MMRDY_Msk
#define FPU_FPCCR_HFRDY_Pos           FPCCR_HFRDY_Pos
#define FPU_FPCCR_HFRDY_Msk           FPCCR_HFRDY_Msk
#define FPU_FPCCR_THREAD_Pos          FPCCR_THREAD_Pos
#define FPU_FPCCR_THREAD_Msk          FPCCR_THREAD_Msk
#define FPU_FPCCR_USER_Pos            FPCCR_USER_Pos
#define FPU_FPCCR_USER_Msk            FPCCR_USER_Msk
#define FPU_FPCCR_LSPACT_Pos          FPCCR_LSPACT_Pos
#define FPU_FPCCR_LSPACT_Msk          FPCCR_LSPACT_Msk

/* Floating-Point Context Address Register */
#define FPU_FPCAR                     FPU_FPCAR

/* FPCAR bit definitions */
#define FPU_FPCAR_ADDRESS_Pos         FPCAR_ADDRESS_Pos
#define FPU_FPCAR_ADDRESS_Msk         FPCAR_ADDRESS_Msk

/* Floating-Point Default Status Control Register */
#define FPU_FPDSCR                    FPU_FPDSCR

/* FPDSCR bit definitions */
#define FPU_FPDSCR_AHP_Pos            FPDSCR_AHP_Pos
#define FPU_FPDSCR_AHP_Msk            FPDSCR_AHP_Msk
#define FPU_FPDSCR_DN_Pos             FPDSCR_DN_Pos
#define FPU_FPDSCR_DN_Msk             FPDSCR_DN_Msk
#define FPU_FPDSCR_FZ_Pos             FPDSCR_FZ_Pos
#define FPU_FPDSCR_FZ_Msk             FPDSCR_FZ_Msk
#define FPU_FPDSCR_RMode_Pos          FPDSCR_RMode_Pos
#define FPU_FPDSCR_RMode_Msk          FPDSCR_RMode_Msk

/* Media and FP Feature Register 0 */
#define FPU_MVFR0                     FPU_MVFR0

/* MVFR0 bit definitions */
#define FPU_MVFR0_A_SIMD_registers_Pos  MVFR0_A_SIMD_registers_Pos
#define FPU_MVFR0_A_SIMD_registers_Msk  MVFR0_A_SIMD_registers_Msk
#define FPU_MVFR0_Single_precision_Pos  MVFR0_Single_precision_Pos
#define FPU_MVFR0_Single_precision_Msk  MVFR0_Single_precision_Msk
#define FPU_MVFR0_Double_precision_Pos  MVFR0_Double_precision_Pos
#define FPU_MVFR0_Double_precision_Msk  MVFR0_Double_precision_Msk
#define FPU_MVFR0_FP_excep_trapping_Pos MVFR0_FP_excep_trapping_Pos
#define FPU_MVFR0_FP_excep_trapping_Msk MVFR0_FP_excep_trapping_Msk
#define FPU_MVFR0_Divide_Pos            MVFR0_Divide_Pos
#define FPU_MVFR0_Divide_Msk            MVFR0_Divide_Msk
#define FPU_MVFR0_Square_root_Pos       MVFR0_Square_root_Pos
#define FPU_MVFR0_Square_root_Msk       MVFR0_Square_root_Msk
#define FPU_MVFR0_Short_vectors_Pos     MVFR0_Short_vectors_Pos
#define FPU_MVFR0_Short_vectors_Msk     MVFR0_Short_vectors_Msk
#define FPU_MVFR0_FP_rounding_modes_Pos MVFR0_FP_rounding_modes_Pos
#define FPU_MVFR0_FP_rounding_modes_Msk MVFR0_FP_rounding_modes_Msk

/* Media and FP Feature Register 1 */
#define FPU_MVFR1                     FPU_MVFR1

/* MVFR1 bit definitions */
#define FPU_MVFR1_FP_fused_MAC_Pos      MVFR1_FP_fused_MAC_Pos
#define FPU_MVFR1_FP_fused_MAC_Msk      MVFR1_FP_fused_MAC_Msk
#define FPU_MVFR1_FP_HPFP_Pos           MVFR1_FP_HPFP_Pos
#define FPU_MVFR1_FP_HPFP_Msk           MVFR1_FP_HPFP_Msk
#define FPU_MVFR1_D_NaN_mode_Pos        MVFR1_D_NaN_mode_Pos
#define FPU_MVFR1_D_NaN_mode_Msk        MVFR1_D_NaN_mode_Msk
#define FPU_MVFR1_FTZ_mode_Pos          MVFR1_FTZ_mode_Pos
#define FPU_MVFR1_FTZ_mode_Msk          MVFR1_FTZ_mode_Msk

/* Rounding Mode definitions */
#define FPU_ROUND_NEAREST             FPU_ROUND_NEAREST
#define FPU_ROUND_PLUSINF             FPU_ROUND_PLUSINF
#define FPU_ROUND_MINUSINF            FPU_ROUND_MINUSINF
#define FPU_ROUND_TOWARDZERO          FPU_ROUND_TOWARDZERO

/*
 * ============================================================================
 * Function Aliases - Map CM4 naming to ARMv7-M naming
 * 函数别名 - 将 CM4 命名映射到 ARMv7-M 命名
 * ============================================================================
 */

/**
 * @brief Enable FPU
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.6.6 (page 4-52)
 * Implementation: Delegates to fpu_enable() in armv7-m_fpu.c
 */
static inline void cm4_fpu_enable(void)
{
    fpu_enable();
}

/**
 * @brief Disable FPU
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.6.6 (page 4-52)
 * Implementation: Delegates to fpu_disable() in armv7-m_fpu.c
 */
static inline void cm4_fpu_disable(void)
{
    fpu_disable();
}

/**
 * @brief Check if FPU is enabled
 * @return 1 if enabled, 0 if disabled
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.6.6 (page 4-52)
 * Implementation: Delegates to fpu_is_enabled() in armv7-m_fpu.c
 */
static inline int cm4_fpu_is_enabled(void)
{
    return fpu_is_enabled();
}

/**
 * @brief Enable automatic lazy state preservation
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.6.2 (page 4-49)
 * Implementation: Delegates to fpu_enable_lazy_state_preservation() in armv7-m_fpu.c
 */
static inline void cm4_fpu_enable_lazy_state_preservation(void)
{
    fpu_enable_lazy_state_preservation();
}

/**
 * @brief Disable automatic lazy state preservation
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.6.2 (page 4-49)
 * Implementation: Delegates to fpu_disable_lazy_state_preservation() in armv7-m_fpu.c
 */
static inline void cm4_fpu_disable_lazy_state_preservation(void)
{
    fpu_disable_lazy_state_preservation();
}

/**
 * @brief Enable automatic hardware state preservation
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.6.2 (page 4-49)
 * Implementation: Delegates to fpu_enable_auto_state_preservation() in armv7-m_fpu.c
 */
static inline void cm4_fpu_enable_auto_state_preservation(void)
{
    fpu_enable_auto_state_preservation();
}

/**
 * @brief Disable automatic hardware state preservation
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.6.2 (page 4-49)
 * Implementation: Delegates to fpu_disable_auto_state_preservation() in armv7-m_fpu.c
 */
static inline void cm4_fpu_disable_auto_state_preservation(void)
{
    fpu_disable_auto_state_preservation();
}

/**
 * @brief Get FPU lazy state preservation status
 * @return 1 if active, 0 if inactive
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.6.2 (page 4-49)
 * Implementation: Delegates to fpu_get_lazy_state_active() in armv7-m_fpu.c
 */
static inline int cm4_fpu_get_lazy_state_active(void)
{
    return fpu_get_lazy_state_active();
}

/**
 * @brief Set default rounding mode
 * @param mode Rounding mode (FPU_ROUND_*)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.6.5 (page 4-51)
 * Implementation: Delegates to fpu_set_default_rounding_mode() in armv7-m_fpu.c
 */
static inline void cm4_fpu_set_default_rounding_mode(uint32_t mode)
{
    fpu_set_default_rounding_mode(mode);
}

/**
 * @brief Get default rounding mode
 * @return Current rounding mode
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.6.5 (page 4-51)
 * Implementation: Delegates to fpu_get_default_rounding_mode() in armv7-m_fpu.c
 */
static inline uint32_t cm4_fpu_get_default_rounding_mode(void)
{
    return fpu_get_default_rounding_mode();
}

/**
 * @brief Enable default flush-to-zero mode
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.6.5 (page 4-51)
 * Implementation: Delegates to fpu_enable_default_ftz() in armv7-m_fpu.c
 */
static inline void cm4_fpu_enable_default_ftz(void)
{
    fpu_enable_default_ftz();
}

/**
 * @brief Disable default flush-to-zero mode
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.6.5 (page 4-51)
 * Implementation: Delegates to fpu_disable_default_ftz() in armv7-m_fpu.c
 */
static inline void cm4_fpu_disable_default_ftz(void)
{
    fpu_disable_default_ftz();
}

/**
 * @brief Enable default default NaN mode
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.6.5 (page 4-51)
 * Implementation: Delegates to fpu_enable_default_dnan() in armv7-m_fpu.c
 */
static inline void cm4_fpu_enable_default_dnan(void)
{
    fpu_enable_default_dnan();
}

/**
 * @brief Disable default default NaN mode
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.6.5 (page 4-51)
 * Implementation: Delegates to fpu_disable_default_dnan() in armv7-m_fpu.c
 */
static inline void cm4_fpu_disable_default_dnan(void)
{
    fpu_disable_default_dnan();
}

/**
 * @brief Check if FPU is present
 * @return 1 if present, 0 if not
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.6 (page 4-48)
 * Implementation: Delegates to fpu_is_present() in armv7-m_fpu.c
 */
static inline int cm4_fpu_is_present(void)
{
    return fpu_is_present();
}

#ifdef __cplusplus
}
#endif

#endif /* __CM4_FPU_H__ */
