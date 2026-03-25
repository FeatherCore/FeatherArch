/**
 * @file cm85_fpu.h
 * @brief Cortex-M85 Floating-Point Unit (FPU)
 *
 * @note Reference: Arm Cortex-M85 Devices Generic User Guide, Chapter 5.12
 * @note Reference: Arm Cortex-M85 Processor TRM, Chapter 15
 */

#ifndef CM85_FPU_H
#define CM85_FPU_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* FPU register structure */
typedef struct {
    volatile uint32_t FPCCR;        /* Floating-Point Context Control Register */
    volatile uint32_t FPCAR;        /* Floating-Point Context Address Register */
    volatile uint32_t FPDSCR;       /* Floating-Point Default Status Control Register */
    volatile uint32_t MVFR0;        /* Media and VFP Feature Register 0 */
    volatile uint32_t MVFR1;        /* Media and VFP Feature Register 1 */
    volatile uint32_t MVFR2;        /* Media and VFP Feature Register 2 */
} cm85_fpu_reg_t;

#define CM85_FPU_BASE       (0xE000EF34UL)
#define CM85_FPU            ((cm85_fpu_reg_t *)CM85_FPU_BASE)

/* FPCCR bit definitions */
#define CM85_FPU_FPCCR_LSPACT_Pos       0U
#define CM85_FPU_FPCCR_LSPACT_Msk       (1UL << CM85_FPU_FPCCR_LSPACT_Pos)
#define CM85_FPU_FPCCR_USER_Pos         1U
#define CM85_FPU_FPCCR_USER_Msk         (1UL << CM85_FPU_FPCCR_USER_Pos)
#define CM85_FPU_FPCCR_THREAD_Pos       3U
#define CM85_FPU_FPCCR_THREAD_Msk       (1UL << CM85_FPU_FPCCR_THREAD_Pos)
#define CM85_FPU_FPCCR_HFRDY_Pos        4U
#define CM85_FPU_FPCCR_HFRDY_Msk        (1UL << CM85_FPU_FPCCR_HFRDY_Pos)
#define CM85_FPU_FPCCR_MMRDY_Pos        5U
#define CM85_FPU_FPCCR_MMRDY_Msk        (1UL << CM85_FPU_FPCCR_MMRDY_Pos)
#define CM85_FPU_FPCCR_BFRDY_Pos        6U
#define CM85_FPU_FPCCR_BFRDY_Msk        (1UL << CM85_FPU_FPCCR_BFRDY_Pos)
#define CM85_FPU_FPCCR_SFRDY_Pos        7U
#define CM85_FPU_FPCCR_SFRDY_Msk        (1UL << CM85_FPU_FPCCR_SFRDY_Pos)
#define CM85_FPU_FPCCR_MONRDY_Pos       8U
#define CM85_FPU_FPCCR_MONRDY_Msk       (1UL << CM85_FPU_FPCCR_MONRDY_Pos)
#define CM85_FPU_FPCCR_LSPEN_Pos        30U
#define CM85_FPU_FPCCR_LSPEN_Msk        (1UL << CM85_FPU_FPCCR_LSPEN_Pos)
#define CM85_FPU_FPCCR_ASPEN_Pos        31U
#define CM85_FPU_FPCCR_ASPEN_Msk        (1UL << CM85_FPU_FPCCR_ASPEN_Pos)

/* FPSCR bit definitions */
#define CM85_FPU_FPSCR_IOC_Pos          0U
#define CM85_FPU_FPSCR_IOC_Msk          (1UL << CM85_FPU_FPSCR_IOC_Pos)
#define CM85_FPU_FPSCR_DZC_Pos          1U
#define CM85_FPU_FPSCR_DZC_Msk          (1UL << CM85_FPU_FPSCR_DZC_Pos)
#define CM85_FPU_FPSCR_OFC_Pos          2U
#define CM85_FPU_FPSCR_OFC_Msk          (1UL << CM85_FPU_FPSCR_OFC_Pos)
#define CM85_FPU_FPSCR_UFC_Pos          3U
#define CM85_FPU_FPSCR_UFC_Msk          (1UL << CM85_FPU_FPSCR_UFC_Pos)
#define CM85_FPU_FPSCR_IXC_Pos          4U
#define CM85_FPU_FPSCR_IXC_Msk          (1UL << CM85_FPU_FPSCR_IXC_Pos)
#define CM85_FPU_FPSCR_IDC_Pos          7U
#define CM85_FPU_FPSCR_IDC_Msk          (1UL << CM85_FPU_FPSCR_IDC_Pos)
#define CM85_FPU_FPSCR_RMode_Pos        22U
#define CM85_FPU_FPSCR_RMode_Msk        (3UL << CM85_FPU_FPSCR_RMode_Pos)
#define CM85_FPU_FPSCR_FZ_Pos           24U
#define CM85_FPU_FPSCR_FZ_Msk           (1UL << CM85_FPU_FPSCR_FZ_Pos)
#define CM85_FPU_FPSCR_DN_Pos           25U
#define CM85_FPU_FPSCR_DN_Msk           (1UL << CM85_FPU_FPSCR_DN_Pos)
#define CM85_FPU_FPSCR_AHP_Pos          26U
#define CM85_FPU_FPSCR_AHP_Msk          (1UL << CM85_FPU_FPSCR_AHP_Pos)
#define CM85_FPU_FPSCR_QC_Pos           27U
#define CM85_FPU_FPSCR_QC_Msk           (1UL << CM85_FPU_FPSCR_QC_Pos)
#define CM85_FPU_FPSCR_V_Pos            28U
#define CM85_FPU_FPSCR_V_Msk            (1UL << CM85_FPU_FPSCR_V_Pos)
#define CM85_FPU_FPSCR_C_Pos            29U
#define CM85_FPU_FPSCR_C_Msk            (1UL << CM85_FPU_FPSCR_C_Pos)
#define CM85_FPU_FPSCR_Z_Pos            30U
#define CM85_FPU_FPSCR_Z_Msk            (1UL << CM85_FPU_FPSCR_Z_Pos)
#define CM85_FPU_FPSCR_N_Pos            31U
#define CM85_FPU_FPSCR_N_Msk            (1UL << CM85_FPU_FPSCR_N_Pos)

/* Rounding modes */
typedef enum {
    CM85_FPU_ROUND_NEAREST = 0,     /* Round to nearest */
    CM85_FPU_ROUND_PLUSINF = 1,     /* Round toward plus infinity */
    CM85_FPU_ROUND_MINUSINF = 2,    /* Round toward minus infinity */
    CM85_FPU_ROUND_ZERO = 3         /* Round toward zero */
} cm85_fpu_round_mode_t;

/* FPU initialization and control */
int cm85_fpu_init(void);
void cm85_fpu_deinit(void);
void cm85_fpu_enable(void);
void cm85_fpu_disable(void);
bool cm85_fpu_is_enabled(void);
bool cm85_fpu_is_present(void);

/* Lazy state preservation */
void cm85_fpu_enable_lazy_preserve(void);
void cm85_fpu_disable_lazy_preserve(void);
bool cm85_fpu_lazy_preserve_active(void);

/* Automatic state preservation */
void cm85_fpu_enable_auto_state(void);
void cm85_fpu_disable_auto_state(void);

/* FPSCR access */
uint32_t cm85_fpu_get_fpscr(void);
void cm85_fpu_set_fpscr(uint32_t fpscr);

/* Rounding mode */
void cm85_fpu_set_round_mode(cm85_fpu_round_mode_t mode);
cm85_fpu_round_mode_t cm85_fpu_get_round_mode(void);

/* Exception control */
void cm85_fpu_enable_exceptions(uint32_t exceptions);
void cm85_fpu_disable_exceptions(uint32_t exceptions);
uint32_t cm85_fpu_get_exception_status(void);
void cm85_fpu_clear_exception_status(uint32_t exceptions);

/* Flush-to-zero and default NaN */
void cm85_fpu_set_flush_to_zero(bool enable);
bool cm85_fpu_get_flush_to_zero(void);
void cm85_fpu_set_default_nan(bool enable);
bool cm85_fpu_get_default_nan(void);
void cm85_fpu_set_alt_half_precision(bool enable);
bool cm85_fpu_get_alt_half_precision(void);

/* Feature detection */
bool cm85_fpu_has_fp16(void);
bool cm85_fpu_has_fp32(void);
bool cm85_fpu_has_fp64(void);

#ifdef __cplusplus
}
#endif

#endif /* CM85_FPU_H */
