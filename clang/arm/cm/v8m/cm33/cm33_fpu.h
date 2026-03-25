/*
 * cm33_fpu.h
 * Cortex-M33 Floating-Point Unit (FPU) Definitions
 * Reference: Cortex-M33 Devices Generic User Guide, Chapter 3.12
 *            Cortex-M33 Technical Reference Manual, Chapter 6
 */

#ifndef CM33_FPU_H
#define CM33_FPU_H

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
} cm33_fpu_regs_t;

/*============================================================================*
 * FPU Control Register Bit Definitions
 *============================================================================*/

#define CM33_FPU_FPCCR_ASPEN_Pos        31
#define CM33_FPU_FPCCR_ASPEN_Msk        (1UL << CM33_FPU_FPCCR_ASPEN_Pos)
#define CM33_FPU_FPCCR_LSPEN_Pos        30
#define CM33_FPU_FPCCR_LSPEN_Msk        (1UL << CM33_FPU_FPCCR_LSPEN_Pos)
#define CM33_FPU_FPCCR_MONRDY_Pos       8
#define CM33_FPU_FPCCR_MONRDY_Msk       (1UL << CM33_FPU_FPCCR_MONRDY_Pos)
#define CM33_FPU_FPCCR_BFRDY_Pos        6
#define CM33_FPU_FPCCR_BFRDY_Msk        (1UL << CM33_FPU_FPCCR_BFRDY_Pos)
#define CM33_FPU_FPCCR_MMRDY_Pos        5
#define CM33_FPU_FPCCR_MMRDY_Msk        (1UL << CM33_FPU_FPCCR_MMRDY_Pos)
#define CM33_FPU_FPCCR_HFRDY_Pos        4
#define CM33_FPU_FPCCR_HFRDY_Msk        (1UL << CM33_FPU_FPCCR_HFRDY_Pos)
#define CM33_FPU_FPCCR_THREAD_Pos       3
#define CM33_FPU_FPCCR_THREAD_Msk       (1UL << CM33_FPU_FPCCR_THREAD_Pos)
#define CM33_FPU_FPCCR_USER_Pos         1
#define CM33_FPU_FPCCR_USER_Msk         (1UL << CM33_FPU_FPCCR_USER_Pos)
#define CM33_FPU_FPCCR_LSPACT_Pos       0
#define CM33_FPU_FPCCR_LSPACT_Msk       (1UL << CM33_FPU_FPCCR_LSPACT_Pos)

/*============================================================================*
 * FPU API Functions (Template)
 *============================================================================*/

void cm33_fpu_enable(void);
void cm33_fpu_disable(void);
uint32_t cm33_fpu_is_present(void);
void cm33_fpu_set_auto_save(uint32_t enable);
void cm33_fpu_lazy_stacking_enable(void);
void cm33_fpu_lazy_stacking_disable(void);
void cm33_fpu_set_default_fpccr(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* CM33_FPU_H */
