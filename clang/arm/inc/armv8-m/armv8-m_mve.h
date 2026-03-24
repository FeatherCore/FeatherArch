/*
 * ARM Architecture - ARMv8-M MVE (M-Profile Vector Extension)
 *
 * ============================================================================
 * File: armv8-m_mve.h
 * Description: ARMv8-M MVE (Helium) Vector Extension definitions
 * 描述: ARMv8-M MVE (Helium) 矢量扩展定义
 *
 * This file provides comprehensive definitions for the MVE (Helium) extension:
 * - Vector register types and operations
 * - Vector load/store operations
 * - Vector arithmetic operations
 * - Vector predication and lane operations
 * - Vector reduction operations
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual (DDI0553B.z)
 *   - Chapter B5: Vector Extension
 *   - Chapter C2.4: MVE Instruction Details
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V8M_MVE_H__
#define __ARCH_ARM_V8M_MVE_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv8-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * MVE Availability Check
 * MVE 可用性检查
 * ============================================================================
 */

#if (__MVE_PRESENT == 0)
#error "MVE extension is not configured. Define __MVE_PRESENT=1 to use MVE features."
#endif

/*
 * ============================================================================
 * MVE Vector Types
 * MVE 矢量类型
 * ============================================================================
 */

/**
 * @brief 128-bit MVE vector register type
 * 128位MVE矢量寄存器类型
 * 
 * MVE provides 8 vector registers (Q0-Q7), each 128 bits wide.
 * Each register can be viewed as:
 * - 16 x 8-bit elements
 * - 8 x 16-bit elements  
 * - 4 x 32-bit elements
 * - 2 x 64-bit elements
 */
typedef union {
    int8_t   s8[16];
    int16_t  s16[8];
    int32_t  s32[4];
    int64_t  s64[2];
    uint8_t  u8[16];
    uint16_t u16[8];
    uint32_t u32[4];
    uint64_t u64[2];
    float    f32[4];
} mve_vec_t;

/**
 * @brief MVE vector predicate type
 * MVE矢量预测类型
 * 
 * The VPR (Vector Predication Register) controls which lanes are active.
 * P0 field (bits [15:0]) contains the predicate mask.
 */
typedef uint32_t mve_pred_t;

/*
 * ============================================================================
 * MVE Control and Status Registers
 * MVE 控制和状态寄存器
 * ============================================================================
 */

/**
 * @brief MVFR0 - Media and VFP Feature Register 0
 * Reference: Arm(R) v8-M ARM, B5.2.1
 */
#define MVFR0                   (*(volatile uint32_t *)(0xE000EF40UL))

/**
 * @brief MVFR1 - Media and VFP Feature Register 1
 * Reference: Arm(R) v8-M ARM, B5.2.2
 */
#define MVFR1                   (*(volatile uint32_t *)(0xE000EF44UL))

/**
 * @brief MVFR2 - Media and VFP Feature Register 2
 * Reference: Arm(R) v8-M ARM, B5.2.3
 */
#define MVFR2                   (*(volatile uint32_t *)(0xE000EF48UL))

/**
 * @brief VPR - Vector Predication Register
 * Reference: Arm(R) v8-M ARM, B5.2.4
 */
#define VPR                     (*(volatile uint32_t *)(0xE000EF3CUL))

/**
 * @brief P0 - Predicate Register 0 (alias for VPR[15:0])
 * Reference: Arm(R) v8-M ARM, B5.2.4
 */
#define P0                      (*(volatile uint16_t *)(0xE000EF3CUL))

/*
 * ============================================================================
 * MVFR Register Bit Definitions
 * MVFR 寄存器位定义
 * ============================================================================
 */

/* MVFR0 bits */
#define MVFR0_SIMDReg_Pos       0U
#define MVFR0_SIMDReg_Msk       (0xFUL << MVFR0_SIMDReg_Msk)
#define MVFR0_FPSP_Pos          4U
#define MVFR0_FPSP_Msk          (0xFUL << MVFR0_FPSP_Pos)
#define MVFR0_FPDP_Pos          8U
#define MVFR0_FPDP_Msk          (0xFUL << MVFR0_FPDP_Pos)

/* MVFR1 bits */
#define MVFR1_MVE_Pos           8U
#define MVFR1_MVE_Msk           (0xFUL << MVFR1_MVE_Pos)
#define MVFR1_MVE_NONE          0x0U
#define MVFR1_MVE_INTEGER       0x1U
#define MVFR1_MVE_FLOAT         0x2U

/* VPR bits */
#define VPR_P0_Pos              0U
#define VPR_P0_Msk              (0xFFFFUL << VPR_P0_Pos)
#define VPR_MASK01_Pos          16U
#define VPR_MASK01_Msk          (0x3UL << VPR_MASK01_Pos)
#define VPR_MASK23_Pos          18U
#define VPR_MASK23_Msk          (0x3UL << VPR_MASK23_Pos)

/*
 * ============================================================================
 * MVE Feature Detection
 * MVE 功能检测
 * ============================================================================
 */

/**
 * @brief Check if MVE is present at runtime
 * 运行时检查MVE是否存在
 * @return true if MVE is present
 * Reference: Arm(R) v8-M ARM, B5.2.2 MVFR1.MVE
 */
static inline bool mve_is_present(void) {
    return ((MVFR1 & MVFR1_MVE_Msk) >> MVFR1_MVE_Pos) != 0;
}

/**
 * @brief Check if MVE integer operations are supported
 * 检查是否支持MVE整数操作
 * @return true if MVE-I is present
 */
static inline bool mve_integer_is_present(void) {
    uint32_t mve = (MVFR1 & MVFR1_MVE_Msk) >> MVFR1_MVE_Pos;
    return (mve == MVFR1_MVE_INTEGER) || (mve == MVFR1_MVE_FLOAT);
}

/**
 * @brief Check if MVE floating-point operations are supported
 * 检查是否支持MVE浮点操作
 * @return true if MVE-F is present
 */
static inline bool mve_fp_is_present(void) {
    return ((MVFR1 & MVFR1_MVE_Msk) >> MVFR1_MVE_Pos) == MVFR1_MVE_FLOAT;
}

/*
 * ============================================================================
 * MVE Enable/Disable
 * MVE 启用/禁用
 * ============================================================================
 */

/**
 * @brief Enable MVE
 * 启用MVE
 * Enables CP10 and CP11 for MVE access.
 * Reference: Arm(R) v8-M ARM, B5.1.1 MVE Enabling
 */
static inline void mve_enable(void) {
    uint32_t cpacr;
    __asm__ volatile (
        "mrs %0, cpacr\n"
        "orr %0, %0, #(0xF << 20)\n"  /* Enable CP10 and CP11 */
        "msr cpacr, %0\n"
        "isb"
        : "=r" (cpacr)
    );
}

/**
 * @brief Disable MVE
 * 禁用MVE
 */
static inline void mve_disable(void) {
    uint32_t cpacr;
    __asm__ volatile (
        "mrs %0, cpacr\n"
        "bic %0, %0, #(0xF << 20)\n"  /* Disable CP10 and CP11 */
        "msr cpacr, %0\n"
        "isb"
        : "=r" (cpacr)
    );
}

/*
 * ============================================================================
 * Vector Predication Operations
 * 矢量预测操作
 * ============================================================================
 */

/**
 * @brief Set VPR (Vector Predication Register)
 * 设置VPR
 * @param vpr New VPR value
 * Reference: Arm(R) v8-M ARM, B5.2.4
 */
static inline void mve_set_vpr(uint32_t vpr) {
    VPR = vpr;
    __asm__ volatile ("isb" ::: "memory");
}

/**
 * @brief Get VPR (Vector Predication Register)
 * 获取VPR
 * @return Current VPR value
 */
static inline uint32_t mve_get_vpr(void) {
    return VPR;
}

/**
 * @brief Set P0 predicate mask
 * 设置P0预测掩码
 * @param p0 New P0 value (16-bit mask)
 */
static inline void mve_set_p0(uint16_t p0) {
    P0 = p0;
    __asm__ volatile ("isb" ::: "memory");
}

/**
 * @brief Get P0 predicate mask
 * 获取P0预测掩码
 * @return Current P0 value
 */
static inline uint16_t mve_get_p0(void) {
    return P0;
}

/**
 * @brief Create predicate mask for all lanes active (8-bit elements)
 * 创建所有通道激活的预测掩码(8位元素)
 * @return Predicate mask with all 16 lanes active
 */
static inline uint16_t mve_pred_all_8(void) {
    return 0xFFFF;
}

/**
 * @brief Create predicate mask for all lanes active (16-bit elements)
 * 创建所有通道激活的预测掩码(16位元素)
 * @return Predicate mask with all 8 lanes active
 */
static inline uint16_t mve_pred_all_16(void) {
    return 0x00FF;
}

/**
 * @brief Create predicate mask for all lanes active (32-bit elements)
 * 创建所有通道激活的预测掩码(32位元素)
 * @return Predicate mask with all 4 lanes active
 */
static inline uint16_t mve_pred_all_32(void) {
    return 0x000F;
}

/*
 * ============================================================================
 * Vector Load Operations
 * 矢量加载操作
 * ============================================================================
 */

/**
 * @brief Vector load 8-bit elements
 * 矢量加载8位元素
 * Loads 16 x 8-bit values into a vector register.
 * Reference: Arm(R) v8-M ARM, C2.4.365 VLDRB
 *
 * @param addr Base address
 * @return Loaded vector
 */
static inline mve_vec_t mve_vldrb(const int8_t *addr) {
    mve_vec_t result;
    __asm__ volatile (
        "vldrb.8 %0, [%1]"
        : "=w" (result)
        : "r" (addr)
        : "memory"
    );
    return result;
}

/**
 * @brief Vector load 16-bit elements
 * 矢量加载16位元素
 * Loads 8 x 16-bit values into a vector register.
 * Reference: Arm(R) v8-M ARM, C2.4.365 VLDRH
 *
 * @param addr Base address
 * @return Loaded vector
 */
static inline mve_vec_t mve_vldrh(const int16_t *addr) {
    mve_vec_t result;
    __asm__ volatile (
        "vldrh.16 %0, [%1]"
        : "=w" (result)
        : "r" (addr)
        : "memory"
    );
    return result;
}

/**
 * @brief Vector load 32-bit elements
 * 矢量加载32位元素
 * Loads 4 x 32-bit values into a vector register.
 * Reference: Arm(R) v8-M ARM, C2.4.365 VLDRW
 *
 * @param addr Base address
 * @return Loaded vector
 */
static inline mve_vec_t mve_vldrw(const int32_t *addr) {
    mve_vec_t result;
    __asm__ volatile (
        "vldrw.32 %0, [%1]"
        : "=w" (result)
        : "r" (addr)
        : "memory"
    );
    return result;
}

/**
 * @brief Vector load 64-bit elements
 * 矢量加载64位元素
 * Loads 2 x 64-bit values into a vector register.
 * Reference: Arm(R) v8-M ARM, C2.4.365 VLDRD
 *
 * @param addr Base address
 * @return Loaded vector
 */
static inline mve_vec_t mve_vldrd(const int64_t *addr) {
    mve_vec_t result;
    __asm__ volatile (
        "vldrd.64 %0, [%1]"
        : "=w" (result)
        : "r" (addr)
        : "memory"
    );
    return result;
}

/*
 * ============================================================================
 * Vector Store Operations
 * 矢量存储操作
 * ============================================================================
 */

/**
 * @brief Vector store 8-bit elements
 * 矢量存储8位元素
 * Stores 16 x 8-bit values from a vector register.
 * Reference: Arm(R) v8-M ARM, C2.4.485 VSTRB
 *
 * @param addr Base address
 * @param vec Vector to store
 */
static inline void mve_vstrb(int8_t *addr, mve_vec_t vec) {
    __asm__ volatile (
        "vstrb.8 %0, [%1]"
        :
        : "w" (vec), "r" (addr)
        : "memory"
    );
}

/**
 * @brief Vector store 16-bit elements
 * 矢量存储16位元素
 * Stores 8 x 16-bit values from a vector register.
 * Reference: Arm(R) v8-M ARM, C2.4.485 VSTRH
 *
 * @param addr Base address
 * @param vec Vector to store
 */
static inline void mve_vstrh(int16_t *addr, mve_vec_t vec) {
    __asm__ volatile (
        "vstrh.16 %0, [%1]"
        :
        : "w" (vec), "r" (addr)
        : "memory"
    );
}

/**
 * @brief Vector store 32-bit elements
 * 矢量存储32位元素
 * Stores 4 x 32-bit values from a vector register.
 * Reference: Arm(R) v8-M ARM, C2.4.485 VSTRW
 *
 * @param addr Base address
 * @param vec Vector to store
 */
static inline void mve_vstrw(int32_t *addr, mve_vec_t vec) {
    __asm__ volatile (
        "vstrw.32 %0, [%1]"
        :
        : "w" (vec), "r" (addr)
        : "memory"
    );
}

/**
 * @brief Vector store 64-bit elements
 * 矢量存储64位元素
 * Stores 2 x 64-bit values from a vector register.
 * Reference: Arm(R) v8-M ARM, C2.4.485 VSTRD
 *
 * @param addr Base address
 * @param vec Vector to store
 */
static inline void mve_vstrd(int64_t *addr, mve_vec_t vec) {
    __asm__ volatile (
        "vstrd.64 %0, [%1]"
        :
        : "w" (vec), "r" (addr)
        : "memory"
    );
}

/*
 * ============================================================================
 * Vector Arithmetic Operations - Integer
 * 矢量算术运算 - 整数
 * ============================================================================
 */

/**
 * @brief Vector add 8-bit elements
 * 矢量加法8位元素
 * Performs 16 x 8-bit additions.
 * Reference: Arm(R) v8-M ARM, C2.4.302 VADD
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vadd_s8(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vadd.i8 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector add 16-bit elements
 * 矢量加法16位元素
 * Performs 8 x 16-bit additions.
 * Reference: Arm(R) v8-M ARM, C2.4.302 VADD
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vadd_s16(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vadd.i16 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector add 32-bit elements
 * 矢量加法32位元素
 * Performs 4 x 32-bit additions.
 * Reference: Arm(R) v8-M ARM, C2.4.302 VADD
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vadd_s32(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vadd.i32 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector subtract 8-bit elements
 * 矢量减法8位元素
 * Performs 16 x 8-bit subtractions.
 * Reference: Arm(R) v8-M ARM, C2.4.506 VSUB
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vsub_s8(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vsub.i8 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector subtract 16-bit elements
 * 矢量减法16位元素
 * Performs 8 x 16-bit subtractions.
 * Reference: Arm(R) v8-M ARM, C2.4.506 VSUB
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vsub_s16(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vsub.i16 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector subtract 32-bit elements
 * 矢量减法32位元素
 * Performs 4 x 32-bit subtractions.
 * Reference: Arm(R) v8-M ARM, C2.4.506 VSUB
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vsub_s32(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vsub.i32 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector multiply 16-bit elements
 * 矢量乘法16位元素
 * Performs 8 x 16-bit multiplications.
 * Reference: Arm(R) v8-M ARM, C2.4.408 VMUL
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vmul_s16(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vmul.i16 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector multiply 32-bit elements
 * 矢量乘法32位元素
 * Performs 4 x 32-bit multiplications.
 * Reference: Arm(R) v8-M ARM, C2.4.408 VMUL
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vmul_s32(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vmul.i32 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/*
 * ============================================================================
 * Vector Arithmetic Operations - Floating-Point
 * 矢量算术运算 - 浮点
 * ============================================================================
 */

#if (__ARM_FEATURE_MVE & 2)  /* MVE with floating-point */

/**
 * @brief Vector add floating-point elements
 * 矢量加法浮点元素
 * Performs 4 x float additions.
 * Reference: Arm(R) v8-M ARM, C2.4.303 VADD (floating-point)
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vadd_f32(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vadd.f32 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector subtract floating-point elements
 * 矢量减法浮点元素
 * Performs 4 x float subtractions.
 * Reference: Arm(R) v8-M ARM, C2.4.507 VSUB (floating-point)
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vsub_f32(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vsub.f32 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector multiply floating-point elements
 * 矢量乘法浮点元素
 * Performs 4 x float multiplications.
 * Reference: Arm(R) v8-M ARM, C2.4.409 VMUL (floating-point)
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vmul_f32(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vmul.f32 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector multiply-accumulate floating-point elements
 * 矢量乘累加浮点元素
 * Performs 4 x float multiply-accumulate: result = a + (b * c)
 * Reference: Arm(R) v8-M ARM, C2.4.414 VMULH
 *
 * @param a Accumulator
 * @param b First operand
 * @param c Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vmla_f32(mve_vec_t a, mve_vec_t b, mve_vec_t c) {
    mve_vec_t result;
    __asm__ volatile (
        "vmla.f32 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b), "w" (c)
    );
    return result;
}

#endif /* __ARM_FEATURE_MVE & 2 */

/*
 * ============================================================================
 * Vector Reduction Operations
 * 矢量归约操作
 * ============================================================================
 */

/**
 * @brief Vector add across all 8-bit elements
 * 矢量8位元素累加
 * Adds all 16 x 8-bit elements together.
 * Reference: Arm(R) v8-M ARM, C2.4.306 VADDV
 *
 * @param vec Input vector
 * @return Sum of all elements
 */
static inline int16_t mve_vaddv_s8(mve_vec_t vec) {
    int16_t result;
    __asm__ volatile (
        "vaddv.s8 %0, %1"
        : "=r" (result)
        : "w" (vec)
    );
    return result;
}

/**
 * @brief Vector add across all 16-bit elements
 * 矢量16位元素累加
 * Adds all 8 x 16-bit elements together.
 * Reference: Arm(R) v8-M ARM, C2.4.306 VADDV
 *
 * @param vec Input vector
 * @return Sum of all elements
 */
static inline int32_t mve_vaddv_s16(mve_vec_t vec) {
    int32_t result;
    __asm__ volatile (
        "vaddv.s16 %0, %1"
        : "=r" (result)
        : "w" (vec)
    );
    return result;
}

/**
 * @brief Vector add across all 32-bit elements
 * 矢量32位元素累加
 * Adds all 4 x 32-bit elements together.
 * Reference: Arm(R) v8-M ARM, C2.4.305 VADDLV
 *
 * @param vec Input vector
 * @return Sum of all elements
 */
static inline int64_t mve_vaddlv_s32(mve_vec_t vec) {
    int64_t result;
    int32_t result_lo, result_hi;
    __asm__ volatile (
        "vaddlv.s32 %0, %1, %2"
        : "=r" (result_lo), "=r" (result_hi)
        : "w" (vec)
    );
    result = ((int64_t)result_hi << 32) | (uint32_t)result_lo;
    return result;
}

/*
 * ============================================================================
 * Vector Initialization
 * 矢量初始化
 * ============================================================================
 */

/**
 * @brief Create vector from single 8-bit value (duplicate)
 * 从单个8位值创建矢量(复制)
 * Duplicates the value across all 16 lanes.
 *
 * @param val Value to duplicate
 * @return Vector with all elements set to val
 */
static inline mve_vec_t mve_vdup_s8(int8_t val) {
    mve_vec_t result;
    __asm__ volatile (
        "vdup.8 %0, %1"
        : "=w" (result)
        : "r" (val)
    );
    return result;
}

/**
 * @brief Create vector from single 16-bit value (duplicate)
 * 从单个16位值创建矢量(复制)
 * Duplicates the value across all 8 lanes.
 *
 * @param val Value to duplicate
 * @return Vector with all elements set to val
 */
static inline mve_vec_t mve_vdup_s16(int16_t val) {
    mve_vec_t result;
    __asm__ volatile (
        "vdup.16 %0, %1"
        : "=w" (result)
        : "r" (val)
    );
    return result;
}

/**
 * @brief Create vector from single 32-bit value (duplicate)
 * 从单个32位值创建矢量(复制)
 * Duplicates the value across all 4 lanes.
 *
 * @param val Value to duplicate
 * @return Vector with all elements set to val
 */
static inline mve_vec_t mve_vdup_s32(int32_t val) {
    mve_vec_t result;
    __asm__ volatile (
        "vdup.32 %0, %1"
        : "=w" (result)
        : "r" (val)
    );
    return result;
}

/**
 * @brief Create vector from single float value (duplicate)
 * 从单个浮点值创建矢量(复制)
 * Duplicates the value across all 4 lanes.
 *
 * @param val Value to duplicate
 * @return Vector with all elements set to val
 */
static inline mve_vec_t mve_vdup_f32(float val) {
    mve_vec_t result;
    __asm__ volatile (
        "vdup.32 %0, %1"
        : "=w" (result)
        : "r" (*(uint32_t*)&val)
    );
    return result;
}

/*
 * ============================================================================
 * Vector Comparison Operations
 * 矢量比较操作
 * ============================================================================
 */

/**
 * @brief Vector compare equal 8-bit elements
 * 矢量比较相等8位元素
 * Compares 16 x 8-bit elements for equality.
 * Reference: Arm(R) v8-M ARM, C2.4.330 VCEQ
 *
 * @param a First operand
 * @param b Second operand
 * @return Vector with elements set to 0xFF if equal, 0 otherwise
 */
static inline mve_vec_t mve_vceq_s8(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vceq.i8 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector compare equal 16-bit elements
 * 矢量比较相等16位元素
 * Compares 8 x 16-bit elements for equality.
 * Reference: Arm(R) v8-M ARM, C2.4.330 VCEQ
 *
 * @param a First operand
 * @param b Second operand
 * @return Vector with elements set to 0xFFFF if equal, 0 otherwise
 */
static inline mve_vec_t mve_vceq_s16(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vceq.i16 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector compare equal 32-bit elements
 * 矢量比较相等32位元素
 * Compares 4 x 32-bit elements for equality.
 * Reference: Arm(R) v8-M ARM, C2.4.330 VCEQ
 *
 * @param a First operand
 * @param b Second operand
 * @return Vector with elements set to 0xFFFFFFFF if equal, 0 otherwise
 */
static inline mve_vec_t mve_vceq_s32(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vceq.i32 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/*
 * ============================================================================
 * Vector Bitwise Operations
 * 矢量位操作
 * ============================================================================
 */

/**
 * @brief Vector bitwise AND
 * 矢量按位与
 * Performs bitwise AND on all 128 bits.
 * Reference: Arm(R) v8-M ARM, C2.4.312 VAND
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vand(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vand %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector bitwise OR
 * 矢量按位或
 * Performs bitwise OR on all 128 bits.
 * Reference: Arm(R) v8-M ARM, C2.4.404 VORR
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vorr(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vorr %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector bitwise XOR
 * 矢量按位异或
 * Performs bitwise XOR on all 128 bits.
 * Reference: Arm(R) v8-M ARM, C2.4.518 VEOR
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_veor(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "veor %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector bitwise NOT
 * 矢量按位非
 * Performs bitwise NOT on all 128 bits.
 * Reference: Arm(R) v8-M ARM, C2.4.398 VMVN
 *
 * @param a Input vector
 * @return Result vector
 */
static inline mve_vec_t mve_vmvn(mve_vec_t a) {
    mve_vec_t result;
    __asm__ volatile (
        "vmvn %0, %1"
        : "=w" (result)
        : "w" (a)
    );
    return result;
}

/*
 * ============================================================================
 * Vector Shift Operations
 * 矢量移位操作
 * ============================================================================
 */

/**
 * @brief Vector shift left 8-bit elements
 * 矢量左移8位元素
 * Shifts each 8-bit element left by specified amount.
 * Reference: Arm(R) v8-M ARM, C2.4.489 VSHL
 *
 * @param a Input vector
 * @param shift Shift amount (0-7)
 * @return Result vector
 */
static inline mve_vec_t mve_vshl_s8(mve_vec_t a, uint32_t shift) {
    mve_vec_t result;
    __asm__ volatile (
        "vshl.i8 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "i" (shift)
    );
    return result;
}

/**
 * @brief Vector shift left 16-bit elements
 * 矢量左移16位元素
 * Shifts each 16-bit element left by specified amount.
 * Reference: Arm(R) v8-M ARM, C2.4.489 VSHL
 *
 * @param a Input vector
 * @param shift Shift amount (0-15)
 * @return Result vector
 */
static inline mve_vec_t mve_vshl_s16(mve_vec_t a, uint32_t shift) {
    mve_vec_t result;
    __asm__ volatile (
        "vshl.i16 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "i" (shift)
    );
    return result;
}

/**
 * @brief Vector shift left 32-bit elements
 * 矢量左移32位元素
 * Shifts each 32-bit element left by specified amount.
 * Reference: Arm(R) v8-M ARM, C2.4.489 VSHL
 *
 * @param a Input vector
 * @param shift Shift amount (0-31)
 * @return Result vector
 */
static inline mve_vec_t mve_vshl_s32(mve_vec_t a, uint32_t shift) {
    mve_vec_t result;
    __asm__ volatile (
        "vshl.i32 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "i" (shift)
    );
    return result;
}

/*
 * ============================================================================
 * Vector Absolute and Negation
 * 矢量绝对值和取反
 * ============================================================================
 */

/**
 * @brief Vector absolute value 8-bit elements
 * 矢量绝对值8位元素
 * Computes absolute value of each 8-bit element.
 * Reference: Arm(R) v8-M ARM, C2.4.288 VABS
 *
 * @param a Input vector
 * @return Result vector
 */
static inline mve_vec_t mve_vabs_s8(mve_vec_t a) {
    mve_vec_t result;
    __asm__ volatile (
        "vabs.s8 %0, %1"
        : "=w" (result)
        : "w" (a)
    );
    return result;
}

/**
 * @brief Vector absolute value 16-bit elements
 * 矢量绝对值16位元素
 * Computes absolute value of each 16-bit element.
 * Reference: Arm(R) v8-M ARM, C2.4.288 VABS
 *
 * @param a Input vector
 * @return Result vector
 */
static inline mve_vec_t mve_vabs_s16(mve_vec_t a) {
    mve_vec_t result;
    __asm__ volatile (
        "vabs.s16 %0, %1"
        : "=w" (result)
        : "w" (a)
    );
    return result;
}

/**
 * @brief Vector absolute value 32-bit elements
 * 矢量绝对值32位元素
 * Computes absolute value of each 32-bit element.
 * Reference: Arm(R) v8-M ARM, C2.4.288 VABS
 *
 * @param a Input vector
 * @return Result vector
 */
static inline mve_vec_t mve_vabs_s32(mve_vec_t a) {
    mve_vec_t result;
    __asm__ volatile (
        "vabs.s32 %0, %1"
        : "=w" (result)
        : "w" (a)
    );
    return result;
}

/**
 * @brief Vector negate 8-bit elements
 * 矢量取反8位元素
 * Negates each 8-bit element.
 * Reference: Arm(R) v8-M ARM, C2.4.400 VNEG
 *
 * @param a Input vector
 * @return Result vector
 */
static inline mve_vec_t mve_vneg_s8(mve_vec_t a) {
    mve_vec_t result;
    __asm__ volatile (
        "vneg.s8 %0, %1"
        : "=w" (result)
        : "w" (a)
    );
    return result;
}

/**
 * @brief Vector negate 16-bit elements
 * 矢量取反16位元素
 * Negates each 16-bit element.
 * Reference: Arm(R) v8-M ARM, C2.4.400 VNEG
 *
 * @param a Input vector
 * @return Result vector
 */
static inline mve_vec_t mve_vneg_s16(mve_vec_t a) {
    mve_vec_t result;
    __asm__ volatile (
        "vneg.s16 %0, %1"
        : "=w" (result)
        : "w" (a)
    );
    return result;
}

/**
 * @brief Vector negate 32-bit elements
 * 矢量取反32位元素
 * Negates each 32-bit element.
 * Reference: Arm(R) v8-M ARM, C2.4.400 VNEG
 *
 * @param a Input vector
 * @return Result vector
 */
static inline mve_vec_t mve_vneg_s32(mve_vec_t a) {
    mve_vec_t result;
    __asm__ volatile (
        "vneg.s32 %0, %1"
        : "=w" (result)
        : "w" (a)
    );
    return result;
}

/*
 * ============================================================================
 * Vector Min/Max Operations
 * 矢量最小/最大操作
 * ============================================================================
 */

/**
 * @brief Vector minimum 8-bit elements
 * 矢量最小值8位元素
 * Computes minimum of each pair of 8-bit elements.
 * Reference: Arm(R) v8-M ARM, C2.4.390 VMIN
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vmin_s8(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vmin.s8 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector minimum 16-bit elements
 * 矢量最小值16位元素
 * Computes minimum of each pair of 16-bit elements.
 * Reference: Arm(R) v8-M ARM, C2.4.390 VMIN
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vmin_s16(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vmin.s16 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector minimum 32-bit elements
 * 矢量最小值32位元素
 * Computes minimum of each pair of 32-bit elements.
 * Reference: Arm(R) v8-M ARM, C2.4.390 VMIN
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vmin_s32(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vmin.s32 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector maximum 8-bit elements
 * 矢量最大值8位元素
 * Computes maximum of each pair of 8-bit elements.
 * Reference: Arm(R) v8-M ARM, C2.4.388 VMAX
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vmax_s8(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vmax.s8 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector maximum 16-bit elements
 * 矢量最大值16位元素
 * Computes maximum of each pair of 16-bit elements.
 * Reference: Arm(R) v8-M ARM, C2.4.388 VMAX
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vmax_s16(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vmax.s16 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector maximum 32-bit elements
 * 矢量最大值32位元素
 * Computes maximum of each pair of 32-bit elements.
 * Reference: Arm(R) v8-M ARM, C2.4.388 VMAX
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vmax_s32(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vmax.s32 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/*
 * ============================================================================
 * Vector Lane Operations
 * 矢量通道操作
 * ============================================================================
 */

/**
 * @brief Extract vector element (8-bit)
 * 提取矢量元素(8位)
 * Extracts a single 8-bit element from the vector.
 *
 * @param vec Input vector
 * @param lane Lane index (0-15)
 * @return Extracted element
 */
static inline int8_t mve_vext_s8(mve_vec_t vec, uint32_t lane) {
    return vec.s8[lane & 0xF];
}

/**
 * @brief Extract vector element (16-bit)
 * 提取矢量元素(16位)
 * Extracts a single 16-bit element from the vector.
 *
 * @param vec Input vector
 * @param lane Lane index (0-7)
 * @return Extracted element
 */
static inline int16_t mve_vext_s16(mve_vec_t vec, uint32_t lane) {
    return vec.s16[lane & 0x7];
}

/**
 * @brief Extract vector element (32-bit)
 * 提取矢量元素(32位)
 * Extracts a single 32-bit element from the vector.
 *
 * @param vec Input vector
 * @param lane Lane index (0-3)
 * @return Extracted element
 */
static inline int32_t mve_vext_s32(mve_vec_t vec, uint32_t lane) {
    return vec.s32[lane & 0x3];
}

/**
 * @brief Set vector element (8-bit)
 * 设置矢量元素(8位)
 * Sets a single 8-bit element in the vector.
 *
 * @param vec Input vector
 * @param lane Lane index (0-15)
 * @param val Value to set
 * @return Modified vector
 */
static inline mve_vec_t mve_vset_s8(mve_vec_t vec, uint32_t lane, int8_t val) {
    vec.s8[lane & 0xF] = val;
    return vec;
}

/**
 * @brief Set vector element (16-bit)
 * 设置矢量元素(16位)
 * Sets a single 16-bit element in the vector.
 *
 * @param vec Input vector
 * @param lane Lane index (0-7)
 * @param val Value to set
 * @return Modified vector
 */
static inline mve_vec_t mve_vset_s16(mve_vec_t vec, uint32_t lane, int16_t val) {
    vec.s16[lane & 0x7] = val;
    return vec;
}

/**
 * @brief Set vector element (32-bit)
 * 设置矢量元素(32位)
 * Sets a single 32-bit element in the vector.
 *
 * @param vec Input vector
 * @param lane Lane index (0-3)
 * @param val Value to set
 * @return Modified vector
 */
static inline mve_vec_t mve_vset_s32(mve_vec_t vec, uint32_t lane, int32_t val) {
    vec.s32[lane & 0x3] = val;
    return vec;
}

/*
 * ============================================================================
 * Vector Interleaving/De-interleaving Loads and Stores
 * 矢量交错/解交错加载和存储
 * ============================================================================
 */

/**
 * @brief Vector load 2-way interleaved
 * 矢量2路交错加载
 * Loads and de-interleaves 2 vectors.
 * Reference: Arm(R) v8-M ARM, C2.4.360 VLD2
 *
 * @param addr Base address
 * @param vec0 First output vector
 * @param vec1 Second output vector
 */
static inline void mve_vld2_s8(const int8_t *addr, mve_vec_t *vec0, mve_vec_t *vec1) {
    __asm__ volatile (
        "vld2.8 {%0, %1}, [%2]"
        : "=w" (*vec0), "=w" (*vec1)
        : "r" (addr)
        : "memory"
    );
}

/**
 * @brief Vector load 4-way interleaved
 * 矢量4路交错加载
 * Loads and de-interleaves 4 vectors.
 * Reference: Arm(R) v8-M ARM, C2.4.361 VLD4
 *
 * @param addr Base address
 * @param vec0 First output vector
 * @param vec1 Second output vector
 * @param vec2 Third output vector
 * @param vec3 Fourth output vector
 */
static inline void mve_vld4_s8(const int8_t *addr, mve_vec_t *vec0, mve_vec_t *vec1,
                                mve_vec_t *vec2, mve_vec_t *vec3) {
    __asm__ volatile (
        "vld4.8 {%0, %1, %2, %3}, [%4]"
        : "=w" (*vec0), "=w" (*vec1), "=w" (*vec2), "=w" (*vec3)
        : "r" (addr)
        : "memory"
    );
}

/**
 * @brief Vector store 2-way interleaved
 * 矢量2路交错存储
 * Interleaves and stores 2 vectors.
 * Reference: Arm(R) v8-M ARM, C2.4.480 VST2
 *
 * @param addr Base address
 * @param vec0 First input vector
 * @param vec1 Second input vector
 */
static inline void mve_vst2_s8(int8_t *addr, mve_vec_t vec0, mve_vec_t vec1) {
    __asm__ volatile (
        "vst2.8 {%0, %1}, [%2]"
        :
        : "w" (vec0), "w" (vec1), "r" (addr)
        : "memory"
    );
}

/**
 * @brief Vector store 4-way interleaved
 * 矢量4路交错存储
 * Interleaves and stores 4 vectors.
 * Reference: Arm(R) v8-M ARM, C2.4.481 VST4
 *
 * @param addr Base address
 * @param vec0 First input vector
 * @param vec1 Second input vector
 * @param vec2 Third input vector
 * @param vec3 Fourth input vector
 */
static inline void mve_vst4_s8(int8_t *addr, mve_vec_t vec0, mve_vec_t vec1,
                                mve_vec_t vec2, mve_vec_t vec3) {
    __asm__ volatile (
        "vst4.8 {%0, %1, %2, %3}, [%4]"
        :
        : "w" (vec0), "w" (vec1), "w" (vec2), "w" (vec3), "r" (addr)
        : "memory"
    );
}

/*
 * ============================================================================
 * Vector Type Conversions
 * 矢量类型转换
 * ============================================================================
 */

/**
 * @brief Vector narrow 16-bit to 8-bit
 * 矢量窄化16位到8位
 * Narrows 8 x 16-bit elements to 16 x 8-bit elements.
 * Reference: Arm(R) v8-M ARM, C2.4.397 VMOVN
 *
 * @param a First input vector (high elements)
 * @param b Second input vector (low elements)
 * @return Narrowed vector
 */
static inline mve_vec_t mve_vmovn_s16(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vmovn.i16 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector narrow 32-bit to 16-bit
 * 矢量窄化32位到16位
 * Narrows 4 x 32-bit elements to 8 x 16-bit elements.
 * Reference: Arm(R) v8-M ARM, C2.4.397 VMOVN
 *
 * @param a First input vector (high elements)
 * @param b Second input vector (low elements)
 * @return Narrowed vector
 */
static inline mve_vec_t mve_vmovn_s32(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vmovn.i32 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector long multiply 8-bit to 16-bit
 * 矢量长乘8位到16位
 * Multiplies and widens 16 x 8-bit elements to 8 x 16-bit elements.
 * Reference: Arm(R) v8-M ARM, C2.4.412 VMULL
 *
 * @param a First input vector
 * @param b Second input vector
 * @return Result vector (high half)
 */
static inline mve_vec_t mve_vmull_s8(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vmullt.s8 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector long multiply 16-bit to 32-bit
 * 矢量长乘16位到32位
 * Multiplies and widens 8 x 16-bit elements to 4 x 32-bit elements.
 * Reference: Arm(R) v8-M ARM, C2.4.412 VMULL
 *
 * @param a First input vector
 * @param b Second input vector
 * @return Result vector
 */
static inline mve_vec_t mve_vmull_s16(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vmullt.s16 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/*
 * ============================================================================
 * Vector Saturating Operations
 * 矢量饱和操作
 * ============================================================================
 */

/**
 * @brief Vector saturating add 8-bit elements
 * 矢量饱和加法8位元素
 * Performs saturating addition on 16 x 8-bit elements.
 * Reference: Arm(R) v8-M ARM, C2.4.308 VQADD
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vqadd_s8(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vqadd.s8 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector saturating add 16-bit elements
 * 矢量饱和加法16位元素
 * Performs saturating addition on 8 x 16-bit elements.
 * Reference: Arm(R) v8-M ARM, C2.4.308 VQADD
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vqadd_s16(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vqadd.s16 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector saturating add 32-bit elements
 * 矢量饱和加法32位元素
 * Performs saturating addition on 4 x 32-bit elements.
 * Reference: Arm(R) v8-M ARM, C2.4.308 VQADD
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vqadd_s32(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vqadd.s32 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector saturating subtract 8-bit elements
 * 矢量饱和减法8位元素
 * Performs saturating subtraction on 16 x 8-bit elements.
 * Reference: Arm(R) v8-M ARM, C2.4.510 VQSUB
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vqsub_s8(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vqsub.s8 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector saturating subtract 16-bit elements
 * 矢量饱和减法16位元素
 * Performs saturating subtraction on 8 x 16-bit elements.
 * Reference: Arm(R) v8-M ARM, C2.4.510 VQSUB
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vqsub_s16(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vqsub.s16 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/**
 * @brief Vector saturating subtract 32-bit elements
 * 矢量饱和减法32位元素
 * Performs saturating subtraction on 4 x 32-bit elements.
 * Reference: Arm(R) v8-M ARM, C2.4.510 VQSUB
 *
 * @param a First operand
 * @param b Second operand
 * @return Result vector
 */
static inline mve_vec_t mve_vqsub_s32(mve_vec_t a, mve_vec_t b) {
    mve_vec_t result;
    __asm__ volatile (
        "vqsub.s32 %0, %1, %2"
        : "=w" (result)
        : "w" (a), "w" (b)
    );
    return result;
}

/*
 * ============================================================================
 * Utility Functions
 * 工具函数
 * ============================================================================
 */

/**
 * @brief Get vector length in bytes
 * 获取矢量长度(字节)
 * @return Vector length (always 16 for MVE)
 */
static inline uint32_t mve_get_vector_length(void) {
    return 16;
}

/**
 * @brief Get number of lanes for 8-bit elements
 * 获取8位元素的通道数
 * @return Number of lanes (16)
 */
static inline uint32_t mve_get_num_lanes_s8(void) {
    return 16;
}

/**
 * @brief Get number of lanes for 16-bit elements
 * 获取16位元素的通道数
 * @return Number of lanes (8)
 */
static inline uint32_t mve_get_num_lanes_s16(void) {
    return 8;
}

/**
 * @brief Get number of lanes for 32-bit elements
 * 获取32位元素的通道数
 * @return Number of lanes (4)
 */
static inline uint32_t mve_get_num_lanes_s32(void) {
    return 4;
}

/**
 * @brief Initialize MVE for use
 * 初始化MVE
 * Enables MVE and clears the VPR.
 */
static inline void mve_init(void) {
    mve_enable();
    mve_set_vpr(0);
}

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V8M_MVE_H__ */
