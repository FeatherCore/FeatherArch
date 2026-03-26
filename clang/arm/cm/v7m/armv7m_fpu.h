/*
 * arm_v7m_fpu.h
 * Floating-Point Unit (FPU) Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section A2.5
 */

#ifndef ARM_V7M_FPU_H
#define ARM_V7M_FPU_H

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
} arm_v7m_fpu_regs_t;

/*============================================================================*
 * FPU Control Register Bit Definitions
 *============================================================================*/

#define ARM_V7M_FPU_FPCCR_ASPNET_Pos     31
#define ARM_V7M_FPU_FPCCR_ASPNET_Msk     (1UL << ARM_V7M_FPU_FPCCR_ASPNET_Pos)
#define ARM_V7M_FPU_FPCCR_LSPACT_Pos     0
#define ARM_V7M_FPU_FPCCR_LSPACT_Msk     (1UL << ARM_V7M_FPU_FPCCR_LSPACT_Pos)
#define ARM_V7M_FPU_FPCCR_USER_Pos       1
#define ARM_V7M_FPU_FPCCR_USER_Msk       (1UL << ARM_V7M_FPU_FPCCR_USER_Pos)

/*============================================================================*
 * FPU API Functions (Template)
 *============================================================================*/

void arm_v7m_fpu_enable(void);
void arm_v7m_fpu_disable(void);
uint32_t arm_v7m_fpu_is_present(void);
void arm_v7m_fpu_set_auto_save(uint32_t enable);
void arm_v7m_fpu_lazy_stacking_enable(void);
void arm_v7m_fpu_lazy_stacking_disable(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_FPU_H */
