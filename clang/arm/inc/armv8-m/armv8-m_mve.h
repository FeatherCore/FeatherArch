/*
 * ARM Architecture - ARMv8-M MVE (M-Profile Vector Extension)
 *
 * ============================================================================
 * File: armv8m_mve.h
 * Description: ARMv8-M MVE (Helium) definitions
 * 描述: ARMv8-M MVE (Helium) 定义
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B5: Vector Extension
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V8M_MVE_H__
#define __ARCH_ARM_V8M_MVE_H__

#include <stdint.h>
#include "armv8-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * MVE Vector Registers
 * MVE 向量寄存器
 * ============================================================================
 */

/**
 * MVE vector registers (Q0-Q7)
 * Each Q register is 128 bits and can be viewed as:
 * - 16 x 8-bit elements
 * - 8 x 16-bit elements
 * - 4 x 32-bit elements
 */

typedef union {
    int8_t   s8[16];
    int16_t  s16[8];
    int32_t  s32[4];
    uint8_t  u8[16];
    uint16_t u16[8];
    uint32_t u32[4];
    float    f32[4];
} mve_vec_t;

/*
 * ============================================================================
 * MVE Control and Status Registers
 * MVE 控制和状态寄存器
 * ============================================================================
 */

/**
 * FPSCR bits specific to MVE
 * FPSCR 中 MVE 特定的位
 */
#define FPSCR_APSR_GE_Pos         16U
#define FPSCR_APSR_GE_Msk         (0xFUL << FPSCR_APSR_GE_Pos)
#define FPSCR_LTPSIZE_Pos         16U
#define FPSCR_LTPSIZE_Msk         (0x7UL << FPSCR_LTPSIZE_Pos)
#define FPSCR_V_Pos               28U
#define FPSCR_V_Msk               (1UL << FPSCR_V_Pos)
#define FPSCR_C_Pos               29U
#define FPSCR_C_Msk               (1UL << FPSCR_C_Pos)
#define FPSCR_Z_Pos               30U
#define FPSCR_Z_Msk               (1UL << FPSCR_Z_Pos)
#define FPSCR_N_Pos               31U
#define FPSCR_N_Msk               (1UL << FPSCR_N_Pos)

/*
 * ============================================================================
 * MVE Predication
 * MVE 预测执行
 * ============================================================================
 */

/**
 * VPR (Vector Predication Register)
 * VPR (向量预测寄存器)
 */
#define VPR_P0_Pos                0U
#define VPR_P0_Msk                (0xFFFFUL << VPR_P0_Pos)
#define VPR_MASK01_Pos            16U
#define VPR_MASK01_Msk            (3UL << VPR_MASK01_Pos)
#define VPR_MASK23_Pos            18U
#define VPR_MASK23_Msk            (3UL << VPR_MASK23_Pos)

/*
 * ============================================================================
 * MVE Function Declarations
 * MVE 函数声明
 * ============================================================================
 */

/**
 * @brief Check if MVE is present
 * @return true if MVE is present
 */
bool mve_is_present(void);

/**
 * @brief Check if MVE floating-point is present
 * @return true if MVE floating-point is present
 */
bool mve_fp_is_present(void);

/**
 * @brief Enable MVE
 */
void mve_enable(void);

/**
 * @brief Disable MVE
 */
void mve_disable(void);

/**
 * @brief Get MVE vector length
 * @return Vector length in bytes (typically 16)
 */
uint32_t mve_get_vector_length(void);

/**
 * @brief Set VPR (Vector Predication Register)
 * @param vpr New VPR value
 */
void mve_set_vpr(uint32_t vpr);

/**
 * @brief Get VPR (Vector Predication Register)
 * @return Current VPR value
 */
uint32_t mve_get_vpr(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V8M_MVE_H__ */
