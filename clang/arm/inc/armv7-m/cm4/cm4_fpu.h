/*
 * ARM Architecture - Cortex-M4 FPU (Floating-Point Unit) Registers
 *
 * ============================================================================
 * File: cm4_fpu.h
 * Description: Cortex-M4 FPU register definitions
 * 描述: Cortex-M4 FPU 寄存器定义
 *
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual (100166_0001_04_en)
 *   - Chapter 7 Floating-Point Unit (page 7-65)
 *   - Table 7-4 Cortex-M4 Floating Point system registers (page 7-71)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_FPU_H__
#define __CM4_FPU_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * FPU System Registers Base Address
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 7-4 (page 7-71)
 * ============================================================================
 */

#define CM4_FPU_BASE_ADDR             0xE000EF34UL

/*
 * ============================================================================
 * FP Context Control Register (FPCCR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 7-4 (page 7-71)
 * Address: 0xE000EF34
 * Reset value: 0xC0000000
 * ============================================================================
 */

#define FPU_FPCCR                     (*(volatile uint32_t *)(CM4_FPU_BASE_ADDR + 0x000))

/* FPCCR bit definitions */
#define FPU_FPCCR_LSPACT_Pos          0U
#define FPU_FPCCR_LSPACT_Msk          (1UL << FPU_FPCCR_LSPACT_Pos)

#define FPU_FPCCR_USER_Pos            1U
#define FPU_FPCCR_USER_Msk            (1UL << FPU_FPCCR_USER_Pos)

#define FPU_FPCCR_THREAD_Pos          3U
#define FPU_FPCCR_THREAD_Msk          (1UL << FPU_FPCCR_THREAD_Pos)

#define FPU_FPCCR_HFRDY_Pos           4U
#define FPU_FPCCR_HFRDY_Msk           (1UL << FPU_FPCCR_HFRDY_Pos)

#define FPU_FPCCR_MMRDY_Pos           5U
#define FPU_FPCCR_MMRDY_Msk           (1UL << FPU_FPCCR_MMRDY_Pos)

#define FPU_FPCCR_BFRDY_Pos           6U
#define FPU_FPCCR_BFRDY_Msk           (1UL << FPU_FPCCR_BFRDY_Pos)

#define FPU_FPCCR_MONRDY_Pos          8U
#define FPU_FPCCR_MONRDY_Msk          (1UL << FPU_FPCCR_MONRDY_Pos)

#define FPU_FPCCR_LSPEN_Pos           30U
#define FPU_FPCCR_LSPEN_Msk           (1UL << FPU_FPCCR_LSPEN_Pos)

#define FPU_FPCCR_ASPEN_Pos           31U
#define FPU_FPCCR_ASPEN_Msk           (1UL << FPU_FPCCR_ASPEN_Pos)

/*
 * ============================================================================
 * FP Context Address Register (FPCAR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 7-4 (page 7-71)
 * Address: 0xE000EF38
 * ============================================================================
 */

#define FPU_FPCAR                     (*(volatile uint32_t *)(CM4_FPU_BASE_ADDR + 0x004))

/* FPCAR bit definitions */
#define FPU_FPCAR_ADDRESS_Pos         3U
#define FPU_FPCAR_ADDRESS_Msk         (0x1FFFFFFFUL << FPU_FPCAR_ADDRESS_Pos)

/*
 * ============================================================================
 * FP Default Status Control Register (FPDSCR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 7-4 (page 7-71)
 * Address: 0xE000EF3C
 * Reset value: 0x00000000
 * ============================================================================
 */

#define FPU_FPDSCR                    (*(volatile uint32_t *)(CM4_FPU_BASE_ADDR + 0x008))

/* FPDSCR bit definitions - Reference: FPSCR bit definitions */
#define FPU_FPDSCR_IOC_Pos            0U
#define FPU_FPDSCR_IOC_Msk            (1UL << FPU_FPDSCR_IOC_Pos)

#define FPU_FPDSCR_DZC_Pos            1U
#define FPU_FPDSCR_DZC_Msk            (1UL << FPU_FPDSCR_DZC_Pos)

#define FPU_FPDSCR_OFC_Pos            2U
#define FPU_FPDSCR_OFC_Msk            (1UL << FPU_FPDSCR_OFC_Pos)

#define FPU_FPDSCR_UFC_Pos            3U
#define FPU_FPDSCR_UFC_Msk            (1UL << FPU_FPDSCR_UFC_Pos)

#define FPU_FPDSCR_IXC_Pos            4U
#define FPU_FPDSCR_IXC_Msk            (1UL << FPU_FPDSCR_IXC_Pos)

#define FPU_FPDSCR_IDC_Pos            7U
#define FPU_FPDSCR_IDC_Msk            (1UL << FPU_FPDSCR_IDC_Pos)

#define FPU_FPDSCR_RMode_Pos          22U
#define FPU_FPDSCR_RMode_Msk          (3UL << FPU_FPDSCR_RMode_Pos)

#define FPU_FPDSCR_FZ_Pos             24U
#define FPU_FPDSCR_FZ_Msk             (1UL << FPU_FPDSCR_FZ_Pos)

#define FPU_FPDSCR_DN_Pos             25U
#define FPU_FPDSCR_DN_Msk             (1UL << FPU_FPDSCR_DN_Pos)

#define FPU_FPDSCR_AHP_Pos            26U
#define FPU_FPDSCR_AHP_Msk            (1UL << FPU_FPDSCR_AHP_Pos)

/* RMode values */
#define FPU_FPDSCR_RMode_RN           0UL
#define FPU_FPDSCR_RMode_RP           1UL
#define FPU_FPDSCR_RMode_RM           2UL
#define FPU_FPDSCR_RMode_RZ           3UL

/*
 * ============================================================================
 * Media and VFP Feature Register 0 (MVFR0)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 7-4 (page 7-71)
 * Address: 0xE000EF40
 * Reset value: 0x10110021
 * ============================================================================
 */

#define FPU_MVFR0                     (*(volatile uint32_t *)(CM4_FPU_BASE_ADDR + 0x00C))

/* MVFR0 reset value - Reference: Table 7-4 (page 7-71) */
#define FPU_MVFR0_RESET_VALUE         0x10110021UL

/*
 * ============================================================================
 * Media and VFP Feature Register 1 (MVFR1)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 7-4 (page 7-71)
 * Address: 0xE000EF44
 * Reset value: 0x11000011
 * ============================================================================
 */

#define FPU_MVFR1                     (*(volatile uint32_t *)(CM4_FPU_BASE_ADDR + 0x010))

/* MVFR1 reset value - Reference: Table 7-4 (page 7-71) */
#define FPU_MVFR1_RESET_VALUE         0x11000011UL

/*
 * ============================================================================
 * FPU Function Declarations
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 7.3.2 (page 7-71)
 * ============================================================================
 */

/**
 * @brief Enable FPU
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 7.3.2 (page 7-71)
 */
void cm4_fpu_enable(void);

/**
 * @brief Disable FPU
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 7.3.2 (page 7-71)
 */
void cm4_fpu_disable(void);

/**
 * @brief Enable lazy stacking
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 7.2.7 (page 7-70)
 */
void cm4_fpu_enable_lazy_stacking(void);

/**
 * @brief Disable lazy stacking
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 7.2.7 (page 7-70)
 */
void cm4_fpu_disable_lazy_stacking(void);

/**
 * @brief Check if lazy stacking is active
 * @return 1 if active, 0 if not
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 7.2.7 (page 7-70)
 */
int cm4_fpu_is_lazy_active(void);

/**
 * @brief Get FPU feature register 0
 * @return MVFR0 value
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 7-4 (page 7-71)
 */
uint32_t cm4_fpu_get_mvfr0(void);

/**
 * @brief Get FPU feature register 1
 * @return MVFR1 value
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 7-4 (page 7-71)
 */
uint32_t cm4_fpu_get_mvfr1(void);

#ifdef __cplusplus
}
#endif

#endif /* __CM4_FPU_H__ */
