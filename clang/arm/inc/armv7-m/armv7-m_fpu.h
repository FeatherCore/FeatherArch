/*
 * ARM Architecture - ARMv7-M FPU (Floating-Point Unit)
 *
 * ============================================================================
 * File: armv7-m_fpu.h
 * Description: ARMv7-M FPU register definitions and function declarations
 * 描述: ARMv7-M FPU 寄存器定义和函数声明
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Table B3-5 Summary of additional SCB registers for the FP extension (page B3-597)
 *   - Chapter B4: Floating-point Support
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_FPU_H__
#define __ARCH_ARM_V7M_FPU_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv7-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * FPU Register Definitions
 * FPU 寄存器定义
 * Reference: Table B3-5 Summary of additional SCB registers for the FP extension
 * ============================================================================
 */

/**
 * Floating-Point Context Control Register (FPCCR)
 * Address: 0xE000EF34
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-615
 */
#define FPU_FPCCR                 (*(volatile uint32_t *)(0xE000EF34UL))

/**
 * Floating-Point Context Address Register (FPCAR)
 * Address: 0xE000EF38
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-617
 */
#define FPU_FPCAR                 (*(volatile uint32_t *)(0xE000EF38UL))

/**
 * Floating-Point Default Status Control Register (FPDSCR)
 * Address: 0xE000EF3C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-617
 */
#define FPU_FPDSCR                (*(volatile uint32_t *)(0xE000EF3CUL))

/**
 * Media and FP Feature Register 0 (MVFR0)
 * Address: 0xE000EF40
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-662
 */
#define FPU_MVFR0                 (*(volatile uint32_t *)(0xE000EF40UL))

/**
 * Media and FP Feature Register 1 (MVFR1)
 * Address: 0xE000EF44
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-663
 */
#define FPU_MVFR1                 (*(volatile uint32_t *)(0xE000EF44UL))

/**
 * Media and FP Feature Register 2 (MVFR2)
 * Address: 0xE000EF48
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-664
 */
#define FPU_MVFR2                 (*(volatile uint32_t *)(0xE000EF48UL))

/*
 * ============================================================================
 * FPU Register Bit Definitions
 * FPU 寄存器位定义
 * ============================================================================
 */

/**
 * FPCCR Register Bits
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-615
 */
#define FPU_FPCCR_ASPEN_Pos       31U
#define FPU_FPCCR_ASPEN_Msk       (1UL << FPU_FPCCR_ASPEN_Pos)
#define FPU_FPCCR_LSPEN_Pos       30U
#define FPU_FPCCR_LSPEN_Msk       (1UL << FPU_FPCCR_LSPEN_Pos)
#define FPU_FPCCR_MONRDY_Pos      8U
#define FPU_FPCCR_MONRDY_Msk      (1UL << FPU_FPCCR_MONRDY_Pos)
#define FPU_FPCCR_SFRDY_Pos       7U
#define FPU_FPCCR_SFRDY_Msk       (1UL << FPU_FPCCR_SFRDY_Pos)
#define FPU_FPCCR_BFRDY_Pos       6U
#define FPU_FPCCR_BFRDY_Msk       (1UL << FPU_FPCCR_BFRDY_Pos)
#define FPU_FPCCR_MMRDY_Pos       5U
#define FPU_FPCCR_MMRDY_Msk       (1UL << FPU_FPCCR_MMRDY_Pos)
#define FPU_FPCCR_HFRDY_Pos       4U
#define FPU_FPCCR_HFRDY_Msk       (1UL << FPU_FPCCR_HFRDY_Pos)
#define FPU_FPCCR_THREAD_Pos      3U
#define FPU_FPCCR_THREAD_Msk      (1UL << FPU_FPCCR_THREAD_Pos)
#define FPU_FPCCR_S_Pos           2U
#define FPU_FPCCR_S_Msk           (1UL << FPU_FPCCR_S_Pos)
#define FPU_FPCCR_USER_Pos        1U
#define FPU_FPCCR_USER_Msk        (1UL << FPU_FPCCR_USER_Pos)
#define FPU_FPCCR_LSPACT_Pos      0U
#define FPU_FPCCR_LSPACT_Msk      (1UL << FPU_FPCCR_LSPACT_Pos)

/**
 * FPDSCR Register Bits
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-617
 */
#define FPU_FPDSCR_AHP_Pos        26U
#define FPU_FPDSCR_AHP_Msk        (1UL << FPU_FPDSCR_AHP_Pos)
#define FPU_FPDSCR_DN_Pos         25U
#define FPU_FPDSCR_DN_Msk         (1UL << FPU_FPDSCR_DN_Pos)
#define FPU_FPDSCR_FZ_Pos         24U
#define FPU_FPDSCR_FZ_Msk         (1UL << FPU_FPDSCR_FZ_Pos)
#define FPU_FPDSCR_RMode_Pos      22U
#define FPU_FPDSCR_RMode_Msk      (3UL << FPU_FPDSCR_RMode_Pos)

/*
 * ============================================================================
 * Coprocessor Access Control Register (CPACR)
 * Located in SCB at 0xE000ED88
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-614
 * ============================================================================
 */

/**
 * CPACR Register Bits
 */
#define CPACR_CP11_Pos            22U
#define CPACR_CP11_Msk            (3UL << CPACR_CP11_Pos)
#define CPACR_CP10_Pos            20U
#define CPACR_CP10_Msk            (3UL << CPACR_CP10_Pos)

/* CP10/CP11 Access Values */
#define CPACR_CP_DISABLE          0x0U  /* Access denied */
#define CPACR_CP_PRIV_ONLY        0x1U  /* Privileged access only */
#define CPACR_CP_RESERVED         0x2U  /* Reserved */
#define CPACR_CP_FULL_ACCESS      0x3U  /* Full access */

/**
 * Rounding Modes
 * 舍入模式
 */
#define FPU_ROUND_NEAREST         0x0U  /* Round to nearest */
#define FPU_ROUND_PLUS_INF        0x1U  /* Round towards plus infinity */
#define FPU_ROUND_MINUS_INF       0x2U  /* Round towards minus infinity */
#define FPU_ROUND_ZERO            0x3U  /* Round towards zero */

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Enable FPU
 */
void fpu_enable(void);

/**
 * @brief Disable FPU
 */
void fpu_disable(void);

/**
 * @brief Check if FPU is enabled
 * @return true if enabled, false otherwise
 */
bool fpu_is_enabled(void);

/**
 * @brief Get FPU type
 * @return 0 = none, 1 = single precision, 2 = double precision
 */
uint32_t fpu_get_type(void);

/**
 * @brief Enable automatic lazy state preservation
 */
void fpu_enable_lazy_preservation(void);

/**
 * @brief Disable automatic lazy state preservation
 */
void fpu_disable_lazy_preservation(void);

/**
 * @brief Get FPDSCR value
 * @return FPDSCR value
 */
uint32_t fpu_get_fpdscr(void);

/**
 * @brief Set FPDSCR value
 * @param fpdscr New FPDSCR value
 */
void fpu_set_fpdscr(uint32_t fpdscr);

/**
 * @brief Set rounding mode
 * @param mode Rounding mode (FPU_ROUND_*)
 */
void fpu_set_rounding_mode(uint32_t mode);

/**
 * @brief Enable flush-to-zero mode
 */
void fpu_enable_flush_to_zero(void);

/**
 * @brief Disable flush-to-zero mode
 */
void fpu_disable_flush_to_zero(void);

/**
 * @brief Enable default NaN mode
 */
void fpu_enable_default_nan(void);

/**
 * @brief Disable default NaN mode
 */
void fpu_disable_default_nan(void);

/*
 * ============================================================================
 * Floating-Point Register Access Functions
 * 浮点寄存器访问函数
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4.2
 * ============================================================================
 */

/**
 * @brief Get Floating-point Single-precision Register Sn (n = 0-31)
 * @param n Register number (0-31)
 * @return Register value
 */
static inline uint32_t __get_Sn(uint32_t n) {
    uint32_t result;
    switch (n) {
        case 0:  __asm__ volatile ("VMOV %0, s0"  : "=r" (result)); break;
        case 1:  __asm__ volatile ("VMOV %0, s1"  : "=r" (result)); break;
        case 2:  __asm__ volatile ("VMOV %0, s2"  : "=r" (result)); break;
        case 3:  __asm__ volatile ("VMOV %0, s3"  : "=r" (result)); break;
        case 4:  __asm__ volatile ("VMOV %0, s4"  : "=r" (result)); break;
        case 5:  __asm__ volatile ("VMOV %0, s5"  : "=r" (result)); break;
        case 6:  __asm__ volatile ("VMOV %0, s6"  : "=r" (result)); break;
        case 7:  __asm__ volatile ("VMOV %0, s7"  : "=r" (result)); break;
        case 8:  __asm__ volatile ("VMOV %0, s8"  : "=r" (result)); break;
        case 9:  __asm__ volatile ("VMOV %0, s9"  : "=r" (result)); break;
        case 10: __asm__ volatile ("VMOV %0, s10" : "=r" (result)); break;
        case 11: __asm__ volatile ("VMOV %0, s11" : "=r" (result)); break;
        case 12: __asm__ volatile ("VMOV %0, s12" : "=r" (result)); break;
        case 13: __asm__ volatile ("VMOV %0, s13" : "=r" (result)); break;
        case 14: __asm__ volatile ("VMOV %0, s14" : "=r" (result)); break;
        case 15: __asm__ volatile ("VMOV %0, s15" : "=r" (result)); break;
        case 16: __asm__ volatile ("VMOV %0, s16" : "=r" (result)); break;
        case 17: __asm__ volatile ("VMOV %0, s17" : "=r" (result)); break;
        case 18: __asm__ volatile ("VMOV %0, s18" : "=r" (result)); break;
        case 19: __asm__ volatile ("VMOV %0, s19" : "=r" (result)); break;
        case 20: __asm__ volatile ("VMOV %0, s20" : "=r" (result)); break;
        case 21: __asm__ volatile ("VMOV %0, s21" : "=r" (result)); break;
        case 22: __asm__ volatile ("VMOV %0, s22" : "=r" (result)); break;
        case 23: __asm__ volatile ("VMOV %0, s23" : "=r" (result)); break;
        case 24: __asm__ volatile ("VMOV %0, s24" : "=r" (result)); break;
        case 25: __asm__ volatile ("VMOV %0, s25" : "=r" (result)); break;
        case 26: __asm__ volatile ("VMOV %0, s26" : "=r" (result)); break;
        case 27: __asm__ volatile ("VMOV %0, s27" : "=r" (result)); break;
        case 28: __asm__ volatile ("VMOV %0, s28" : "=r" (result)); break;
        case 29: __asm__ volatile ("VMOV %0, s29" : "=r" (result)); break;
        case 30: __asm__ volatile ("VMOV %0, s30" : "=r" (result)); break;
        case 31: __asm__ volatile ("VMOV %0, s31" : "=r" (result)); break;
        default: result = 0; break;
    }
    return result;
}

/**
 * @brief Set Floating-point Single-precision Register Sn (n = 0-31)
 * @param n Register number (0-31)
 * @param value Value to write
 */
static inline void __set_Sn(uint32_t n, uint32_t value) {
    switch (n) {
        case 0:  __asm__ volatile ("VMOV s0, %0"  : : "r" (value)); break;
        case 1:  __asm__ volatile ("VMOV s1, %0"  : : "r" (value)); break;
        case 2:  __asm__ volatile ("VMOV s2, %0"  : : "r" (value)); break;
        case 3:  __asm__ volatile ("VMOV s3, %0"  : : "r" (value)); break;
        case 4:  __asm__ volatile ("VMOV s4, %0"  : : "r" (value)); break;
        case 5:  __asm__ volatile ("VMOV s5, %0"  : : "r" (value)); break;
        case 6:  __asm__ volatile ("VMOV s6, %0"  : : "r" (value)); break;
        case 7:  __asm__ volatile ("VMOV s7, %0"  : : "r" (value)); break;
        case 8:  __asm__ volatile ("VMOV s8, %0"  : : "r" (value)); break;
        case 9:  __asm__ volatile ("VMOV s9, %0"  : : "r" (value)); break;
        case 10: __asm__ volatile ("VMOV s10, %0" : : "r" (value)); break;
        case 11: __asm__ volatile ("VMOV s11, %0" : : "r" (value)); break;
        case 12: __asm__ volatile ("VMOV s12, %0" : : "r" (value)); break;
        case 13: __asm__ volatile ("VMOV s13, %0" : : "r" (value)); break;
        case 14: __asm__ volatile ("VMOV s14, %0" : : "r" (value)); break;
        case 15: __asm__ volatile ("VMOV s15, %0" : : "r" (value)); break;
        case 16: __asm__ volatile ("VMOV s16, %0" : : "r" (value)); break;
        case 17: __asm__ volatile ("VMOV s17, %0" : : "r" (value)); break;
        case 18: __asm__ volatile ("VMOV s18, %0" : : "r" (value)); break;
        case 19: __asm__ volatile ("VMOV s19, %0" : : "r" (value)); break;
        case 20: __asm__ volatile ("VMOV s20, %0" : : "r" (value)); break;
        case 21: __asm__ volatile ("VMOV s21, %0" : : "r" (value)); break;
        case 22: __asm__ volatile ("VMOV s22, %0" : : "r" (value)); break;
        case 23: __asm__ volatile ("VMOV s23, %0" : : "r" (value)); break;
        case 24: __asm__ volatile ("VMOV s24, %0" : : "r" (value)); break;
        case 25: __asm__ volatile ("VMOV s25, %0" : : "r" (value)); break;
        case 26: __asm__ volatile ("VMOV s26, %0" : : "r" (value)); break;
        case 27: __asm__ volatile ("VMOV s27, %0" : : "r" (value)); break;
        case 28: __asm__ volatile ("VMOV s28, %0" : : "r" (value)); break;
        case 29: __asm__ volatile ("VMOV s29, %0" : : "r" (value)); break;
        case 30: __asm__ volatile ("VMOV s30, %0" : : "r" (value)); break;
        case 31: __asm__ volatile ("VMOV s31, %0" : : "r" (value)); break;
        default: break;
    }
}

/**
 * @brief Get Floating-point Double-precision Register Dn (n = 0-15)
 * @param n Register number (0-15)
 * @return Register value
 */
static inline uint64_t __get_Dn(uint32_t n) {
    uint64_t result;
    switch (n) {
        case 0:  __asm__ volatile ("VMOV %0, %H0, d0"  : "=r" (result)); break;
        case 1:  __asm__ volatile ("VMOV %0, %H0, d1"  : "=r" (result)); break;
        case 2:  __asm__ volatile ("VMOV %0, %H0, d2"  : "=r" (result)); break;
        case 3:  __asm__ volatile ("VMOV %0, %H0, d3"  : "=r" (result)); break;
        case 4:  __asm__ volatile ("VMOV %0, %H0, d4"  : "=r" (result)); break;
        case 5:  __asm__ volatile ("VMOV %0, %H0, d5"  : "=r" (result)); break;
        case 6:  __asm__ volatile ("VMOV %0, %H0, d6"  : "=r" (result)); break;
        case 7:  __asm__ volatile ("VMOV %0, %H0, d7"  : "=r" (result)); break;
        case 8:  __asm__ volatile ("VMOV %0, %H0, d8"  : "=r" (result)); break;
        case 9:  __asm__ volatile ("VMOV %0, %H0, d9"  : "=r" (result)); break;
        case 10: __asm__ volatile ("VMOV %0, %H0, d10" : "=r" (result)); break;
        case 11: __asm__ volatile ("VMOV %0, %H0, d11" : "=r" (result)); break;
        case 12: __asm__ volatile ("VMOV %0, %H0, d12" : "=r" (result)); break;
        case 13: __asm__ volatile ("VMOV %0, %H0, d13" : "=r" (result)); break;
        case 14: __asm__ volatile ("VMOV %0, %H0, d14" : "=r" (result)); break;
        case 15: __asm__ volatile ("VMOV %0, %H0, d15" : "=r" (result)); break;
        default: result = 0; break;
    }
    return result;
}

/**
 * @brief Set Floating-point Double-precision Register Dn (n = 0-15)
 * @param n Register number (0-15)
 * @param value Value to write
 */
static inline void __set_Dn(uint32_t n, uint64_t value) {
    switch (n) {
        case 0:  __asm__ volatile ("VMOV d0, %0, %H0"  : : "r" (value)); break;
        case 1:  __asm__ volatile ("VMOV d1, %0, %H0"  : : "r" (value)); break;
        case 2:  __asm__ volatile ("VMOV d2, %0, %H0"  : : "r" (value)); break;
        case 3:  __asm__ volatile ("VMOV d3, %0, %H0"  : : "r" (value)); break;
        case 4:  __asm__ volatile ("VMOV d4, %0, %H0"  : : "r" (value)); break;
        case 5:  __asm__ volatile ("VMOV d5, %0, %H0"  : : "r" (value)); break;
        case 6:  __asm__ volatile ("VMOV d6, %0, %H0"  : : "r" (value)); break;
        case 7:  __asm__ volatile ("VMOV d7, %0, %H0"  : : "r" (value)); break;
        case 8:  __asm__ volatile ("VMOV d8, %0, %H0"  : : "r" (value)); break;
        case 9:  __asm__ volatile ("VMOV d9, %0, %H0"  : : "r" (value)); break;
        case 10: __asm__ volatile ("VMOV d10, %0, %H0" : : "r" (value)); break;
        case 11: __asm__ volatile ("VMOV d11, %0, %H0" : : "r" (value)); break;
        case 12: __asm__ volatile ("VMOV d12, %0, %H0" : : "r" (value)); break;
        case 13: __asm__ volatile ("VMOV d13, %0, %H0" : : "r" (value)); break;
        case 14: __asm__ volatile ("VMOV d14, %0, %H0" : : "r" (value)); break;
        case 15: __asm__ volatile ("VMOV d15, %0, %H0" : : "r" (value)); break;
        default: break;
    }
}

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_FPU_H__ */
