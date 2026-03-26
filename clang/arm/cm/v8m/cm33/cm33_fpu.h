/*
 * arm_v8m_cm33_fpu.h
 * Cortex-M33 Floating-Point Unit (FPU) Definitions
 * Reference: Cortex-M33 Technical Reference Manual, Chapter 4
 *
 * @note This file reuses Armv8-M generic FPU definitions.
 */

#ifndef ARM_V8M_CM33_FPU_H
#define ARM_V8M_CM33_FPU_H

#include <stdint.h>
#include "../armv8m_fpu.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Type Aliases
 *============================================================================*/

typedef arm_v8m_fpu_regs_t      arm_v8m_cm33_fpu_regs_t;

/*============================================================================*
 * Constant Aliases - FPCCR Bit Definitions
 *============================================================================*/

#define ARM_V8M_CM33_FPU_FPCCR_ASPEN_Pos        ARM_V8M_FPU_FPCCR_ASPEN_Pos
#define ARM_V8M_CM33_FPU_FPCCR_ASPEN_Msk        ARM_V8M_FPU_FPCCR_ASPEN_Msk
#define ARM_V8M_CM33_FPU_FPCCR_LSPEN_Pos        ARM_V8M_FPU_FPCCR_LSPEN_Pos
#define ARM_V8M_CM33_FPU_FPCCR_LSPEN_Msk        ARM_V8M_FPU_FPCCR_LSPEN_Msk
#define ARM_V8M_CM33_FPU_FPCCR_MONRDY_Pos       ARM_V8M_FPU_FPCCR_MONRDY_Pos
#define ARM_V8M_CM33_FPU_FPCCR_MONRDY_Msk       ARM_V8M_FPU_FPCCR_MONRDY_Msk
#define ARM_V8M_CM33_FPU_FPCCR_BFRDY_Pos        ARM_V8M_FPU_FPCCR_BFRDY_Pos
#define ARM_V8M_CM33_FPU_FPCCR_BFRDY_Msk        ARM_V8M_FPU_FPCCR_BFRDY_Msk
#define ARM_V8M_CM33_FPU_FPCCR_MMRDY_Pos        ARM_V8M_FPU_FPCCR_MMRDY_Pos
#define ARM_V8M_CM33_FPU_FPCCR_MMRDY_Msk        ARM_V8M_FPU_FPCCR_MMRDY_Msk
#define ARM_V8M_CM33_FPU_FPCCR_HFRDY_Pos        ARM_V8M_FPU_FPCCR_HFRDY_Pos
#define ARM_V8M_CM33_FPU_FPCCR_HFRDY_Msk        ARM_V8M_FPU_FPCCR_HFRDY_Msk
#define ARM_V8M_CM33_FPU_FPCCR_THREAD_Pos       ARM_V8M_FPU_FPCCR_THREAD_Pos
#define ARM_V8M_CM33_FPU_FPCCR_THREAD_Msk       ARM_V8M_FPU_FPCCR_THREAD_Msk
#define ARM_V8M_CM33_FPU_FPCCR_USER_Pos         ARM_V8M_FPU_FPCCR_USER_Pos
#define ARM_V8M_CM33_FPU_FPCCR_USER_Msk         ARM_V8M_FPU_FPCCR_USER_Msk
#define ARM_V8M_CM33_FPU_FPCCR_LSPACT_Pos       ARM_V8M_FPU_FPCCR_LSPACT_Pos
#define ARM_V8M_CM33_FPU_FPCCR_LSPACT_Msk       ARM_V8M_FPU_FPCCR_LSPACT_Msk

/*============================================================================*
 * Inline Function Wrappers - FPU Operations
 *============================================================================*/

static inline void arm_v8m_cm33_fpu_enable(void) {
    arm_v8m_fpu_enable();
}

static inline void arm_v8m_cm33_fpu_disable(void) {
    arm_v8m_fpu_disable();
}

static inline uint32_t arm_v8m_cm33_fpu_is_present(void) {
    return arm_v8m_fpu_is_present();
}

static inline uint32_t arm_v8m_cm33_fpu_has_double_precision(void) {
    return arm_v8m_fpu_has_double_precision();
}

static inline uint32_t arm_v8m_cm33_fpu_has_half_precision(void) {
    return arm_v8m_fpu_has_half_precision();
}

static inline void arm_v8m_cm33_fpu_set_auto_save(uint32_t enable) {
    arm_v8m_fpu_set_auto_save(enable);
}

static inline void arm_v8m_cm33_fpu_lazy_stacking_enable(void) {
    arm_v8m_fpu_lazy_stacking_enable();
}

static inline void arm_v8m_cm33_fpu_lazy_stacking_disable(void) {
    arm_v8m_fpu_lazy_stacking_disable();
}

static inline void arm_v8m_cm33_fpu_set_default_fpccr(uint32_t value) {
    arm_v8m_fpu_set_default_fpccr(value);
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM33_FPU_H */
