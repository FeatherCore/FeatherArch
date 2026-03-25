/*
 * cm7_fpu.h
 * Cortex-M7 Floating-Point Unit (FPU) Definitions
 * Reference: Cortex-M7 Devices Generic User Guide, Chapter 4.7
 *            Cortex-M7 Technical Reference Manual, Chapter 8
 */

#ifndef CM7_FPU_H
#define CM7_FPU_H

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
} cm7_fpu_regs_t;

/*============================================================================*
 * FPU Control Register Bit Definitions
 *============================================================================*/

#define CM7_FPU_FPCCR_ASPEN_Pos         31
#define CM7_FPU_FPCCR_ASPEN_Msk         (1UL << CM7_FPU_FPCCR_ASPEN_Pos)
#define CM7_FPU_FPCCR_LSPEN_Pos         30
#define CM7_FPU_FPCCR_LSPEN_Msk         (1UL << CM7_FPU_FPCCR_LSPEN_Pos)
#define CM7_FPU_FPCCR_MONRDY_Pos        8
#define CM7_FPU_FPCCR_MONRDY_Msk        (1UL << CM7_FPU_FPCCR_MONRDY_Pos)
#define CM7_FPU_FPCCR_BFRDY_Pos         6
#define CM7_FPU_FPCCR_BFRDY_Msk         (1UL << CM7_FPU_FPCCR_BFRDY_Pos)
#define CM7_FPU_FPCCR_MMRDY_Pos         5
#define CM7_FPU_FPCCR_MMRDY_Msk         (1UL << CM7_FPU_FPCCR_MMRDY_Pos)
#define CM7_FPU_FPCCR_HFRDY_Pos         4
#define CM7_FPU_FPCCR_HFRDY_Msk         (1UL << CM7_FPU_FPCCR_HFRDY_Pos)
#define CM7_FPU_FPCCR_THREAD_Pos        3
#define CM7_FPU_FPCCR_THREAD_Msk        (1UL << CM7_FPU_FPCCR_THREAD_Pos)
#define CM7_FPU_FPCCR_USER_Pos          1
#define CM7_FPU_FPCCR_USER_Msk          (1UL << CM7_FPU_FPCCR_USER_Pos)
#define CM7_FPU_FPCCR_LSPACT_Pos        0
#define CM7_FPU_FPCCR_LSPACT_Msk        (1UL << CM7_FPU_FPCCR_LSPACT_Pos)

/*============================================================================*
 * FPU API Functions (Template)
 *============================================================================*/

void cm7_fpu_enable(void);
void cm7_fpu_disable(void);
uint32_t cm7_fpu_is_present(void);
uint32_t cm7_fpu_has_double_precision(void);
void cm7_fpu_set_auto_save(uint32_t enable);
void cm7_fpu_lazy_stacking_enable(void);
void cm7_fpu_lazy_stacking_disable(void);
void cm7_fpu_set_default_fpccr(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* CM7_FPU_H */
