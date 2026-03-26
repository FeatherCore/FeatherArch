/*
 * arm_v8m_fpu.h
 * Armv8-M Floating-Point Unit (FPU) Definitions
 * Reference: Armv8-M Architecture Reference Manual, Chapter B4
 */

#ifndef ARM_V8M_FPU_H
#define ARM_V8M_FPU_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * FPU Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t FPCCR;
    volatile uint32_t FPCAR;
    volatile uint32_t FPDSCR;
    volatile const uint32_t MVFR0;
    volatile const uint32_t MVFR1;
    volatile const uint32_t MVFR2;
} arm_v8m_fpu_regs_t;

/*============================================================================*
 * FPU Control Register Bit Definitions
 *============================================================================*/

#define ARM_V8M_FPU_FPCCR_ASPEN_Pos      31
#define ARM_V8M_FPU_FPCCR_ASPEN_Msk      (1UL << ARM_V8M_FPU_FPCCR_ASPEN_Pos)
#define ARM_V8M_FPU_FPCCR_LSPEN_Pos      30
#define ARM_V8M_FPU_FPCCR_LSPEN_Msk      (1UL << ARM_V8M_FPU_FPCCR_LSPEN_Pos)
#define ARM_V8M_FPU_FPCCR_MONRDY_Pos     8
#define ARM_V8M_FPU_FPCCR_MONRDY_Msk     (1UL << ARM_V8M_FPU_FPCCR_MONRDY_Pos)
#define ARM_V8M_FPU_FPCCR_BFRDY_Pos      6
#define ARM_V8M_FPU_FPCCR_BFRDY_Msk      (1UL << ARM_V8M_FPU_FPCCR_BFRDY_Pos)
#define ARM_V8M_FPU_FPCCR_MMRDY_Pos      5
#define ARM_V8M_FPU_FPCCR_MMRDY_Msk      (1UL << ARM_V8M_FPU_FPCCR_MMRDY_Pos)
#define ARM_V8M_FPU_FPCCR_HFRDY_Pos      4
#define ARM_V8M_FPU_FPCCR_HFRDY_Msk      (1UL << ARM_V8M_FPU_FPCCR_HFRDY_Pos)
#define ARM_V8M_FPU_FPCCR_THREAD_Pos     3
#define ARM_V8M_FPU_FPCCR_THREAD_Msk     (1UL << ARM_V8M_FPU_FPCCR_THREAD_Pos)
#define ARM_V8M_FPU_FPCCR_USER_Pos       1
#define ARM_V8M_FPU_FPCCR_USER_Msk       (1UL << ARM_V8M_FPU_FPCCR_USER_Pos)
#define ARM_V8M_FPU_FPCCR_LSPACT_Pos     0
#define ARM_V8M_FPU_FPCCR_LSPACT_Msk     (1UL << ARM_V8M_FPU_FPCCR_LSPACT_Pos)

/*============================================================================*
 * FPU API Functions (Template)
 *============================================================================*/

void arm_v8m_fpu_enable(void);
void arm_v8m_fpu_disable(void);
uint32_t arm_v8m_fpu_is_present(void);
uint32_t arm_v8m_fpu_has_double_precision(void);
uint32_t arm_v8m_fpu_has_half_precision(void);
void arm_v8m_fpu_set_auto_save(uint32_t enable);
void arm_v8m_fpu_lazy_stacking_enable(void);
void arm_v8m_fpu_lazy_stacking_disable(void);
void arm_v8m_fpu_set_default_fpccr(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_FPU_H */
