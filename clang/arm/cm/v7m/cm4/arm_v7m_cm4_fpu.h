/*
 * arm_v7m_cm4_fpu.h
 * Cortex-M4 Floating-Point Unit (FPU) Definitions
 * Reference: Cortex-M4 Devices Generic User Guide, Chapter 4.6
 *
 * @note This file reuses Armv7-M generic FPU definitions.
 */

#ifndef ARM_V7M_CM4_FPU_H
#define ARM_V7M_CM4_FPU_H

#include <stdint.h>
#include "../arm_v7m_fpu.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Type Aliases
 *============================================================================*/

typedef arm_v7m_fpu_regs_t      arm_v7m_cm4_fpu_regs_t;

/*============================================================================*
 * Constant Aliases - FPCCR Bit Definitions
 *============================================================================*/

#define ARM_V7M_CM4_FPU_FPCCR_ASPEN_Pos        ARM_V7M_FPU_FPCCR_ASPEN_Pos
#define ARM_V7M_CM4_FPU_FPCCR_ASPEN_Msk        ARM_V7M_FPU_FPCCR_ASPEN_Msk
#define ARM_V7M_CM4_FPU_FPCCR_LSPEN_Pos        ARM_V7M_FPU_FPCCR_LSPEN_Pos
#define ARM_V7M_CM4_FPU_FPCCR_LSPEN_Msk        ARM_V7M_FPU_FPCCR_LSPEN_Msk
#define ARM_V7M_CM4_FPU_FPCCR_MONRDY_Pos       ARM_V7M_FPU_FPCCR_MONRDY_Pos
#define ARM_V7M_CM4_FPU_FPCCR_MONRDY_Msk       ARM_V7M_FPU_FPCCR_MONRDY_Msk
#define ARM_V7M_CM4_FPU_FPCCR_BFRDY_Pos        ARM_V7M_FPU_FPCCR_BFRDY_Pos
#define ARM_V7M_CM4_FPU_FPCCR_BFRDY_Msk        ARM_V7M_FPU_FPCCR_BFRDY_Msk
#define ARM_V7M_CM4_FPU_FPCCR_MMRDY_Pos        ARM_V7M_FPU_FPCCR_MMRDY_Pos
#define ARM_V7M_CM4_FPU_FPCCR_MMRDY_Msk        ARM_V7M_FPU_FPCCR_MMRDY_Msk
#define ARM_V7M_CM4_FPU_FPCCR_HFRDY_Pos        ARM_V7M_FPU_FPCCR_HFRDY_Pos
#define ARM_V7M_CM4_FPU_FPCCR_HFRDY_Msk        ARM_V7M_FPU_FPCCR_HFRDY_Msk
#define ARM_V7M_CM4_FPU_FPCCR_THREAD_Pos       ARM_V7M_FPU_FPCCR_THREAD_Pos
#define ARM_V7M_CM4_FPU_FPCCR_THREAD_Msk       ARM_V7M_FPU_FPCCR_THREAD_Msk
#define ARM_V7M_CM4_FPU_FPCCR_USER_Pos         ARM_V7M_FPU_FPCCR_USER_Pos
#define ARM_V7M_CM4_FPU_FPCCR_USER_Msk         ARM_V7M_FPU_FPCCR_USER_Msk
#define ARM_V7M_CM4_FPU_FPCCR_LSPACT_Pos       ARM_V7M_FPU_FPCCR_LSPACT_Pos
#define ARM_V7M_CM4_FPU_FPCCR_LSPACT_Msk       ARM_V7M_FPU_FPCCR_LSPACT_Msk

/*============================================================================*
 * Inline Function Wrappers - FPU Operations
 *============================================================================*/

static inline void arm_v7m_cm4_fpu_enable(void) {
    arm_v7m_fpu_enable();
}

static inline void arm_v7m_cm4_fpu_disable(void) {
    arm_v7m_fpu_disable();
}

static inline uint32_t arm_v7m_cm4_fpu_is_present(void) {
    return arm_v7m_fpu_is_present();
}

static inline void arm_v7m_cm4_fpu_set_auto_save(uint32_t enable) {
    arm_v7m_fpu_set_auto_save(enable);
}

static inline void arm_v7m_cm4_fpu_lazy_stacking_enable(void) {
    arm_v7m_fpu_lazy_stacking_enable();
}

static inline void arm_v7m_cm4_fpu_lazy_stacking_disable(void) {
    arm_v7m_fpu_lazy_stacking_disable();
}

static inline void arm_v7m_cm4_fpu_set_default_fpccr(uint32_t value) {
    arm_v7m_fpu_set_default_fpccr(value);
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM4_FPU_H */
