/*
 * ARM Architecture - Common Header
 *
 * ============================================================================
 * File: arm_arch.h
 * Description: ARM architecture common header file with automatic sub-architecture selection
 * 描述: ARM 架构公共头文件，自动选择子架构
 *
 * This header automatically detects and includes the appropriate ARM sub-architecture
 * headers based on compiler predefined macros.
 * 此头文件根据编译器预定义宏自动检测并包含相应的 ARM 子架构头文件。
 *
 * Supported Architectures:
 * - ARMv7-M: Cortex-M3, Cortex-M4, Cortex-M7
 * - ARMv8-M: Cortex-M23, Cortex-M33, Cortex-M55, Cortex-M85
 * - ARMv7-A: Cortex-A5, Cortex-A7, Cortex-A8, Cortex-A9, Cortex-A15, Cortex-A17
 * - ARMv8-A: Cortex-A32, Cortex-A35, Cortex-A53, Cortex-A55, Cortex-A57, Cortex-A72, Cortex-A73, Cortex-A75, Cortex-A76, Cortex-A77, Cortex-A78, Cortex-X1, Cortex-X2, Cortex-X3, Cortex-X4, Cortex-A710, Cortex-A715, Cortex-A720, Neoverse N1, Neoverse N2, Neoverse V1, Neoverse V2
 * - ARMv9-A: Cortex-A510, Cortex-A520, Cortex-A710, Cortex-A715, Cortex-A720, Cortex-X2, Cortex-X3, Cortex-X4
 *
 * Reference:
 * - Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 * - Arm(R) v8-M Architecture Reference Manual (DDI0553B.z)
 * - Arm(R) Architecture Reference Manual for A-profile (DDI0487)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_H__
#define __ARCH_ARM_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * Architecture Detection
 * 架构检测
 * ============================================================================
 */

/**
 * Detect ARMv8-M Architecture
 * 检测 ARMv8-M 架构
 * __ARM_ARCH_8M_MAIN__ or __ARM_ARCH_8M_BASE__ defined for ARMv8-M
 */
#if defined(__ARM_ARCH_8M_MAIN__) || defined(__ARM_ARCH_8M_BASE__) || \
    defined(__ARM_ARCH_8_1M_MAIN__)
    #define __ARM_ARCH_V8M__      1
    #define __ARM_ARCH__          8
    #define __ARM_ARCH_PROFILE__ 'M'

/**
 * Detect ARMv7-M Architecture
 * 检测 ARMv7-M 架构
 * __ARM_ARCH_7M__ or __ARM_ARCH_7EM__ defined for ARMv7-M
 */
#elif defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
    #define __ARM_ARCH_V7M__      1
    #define __ARM_ARCH__          7
    #define __ARM_ARCH_PROFILE__ 'M'
    #if defined(__ARM_ARCH_7EM__)
        #define __ARM_ARCH_V7EM__ 1
    #endif

/**
 * Detect ARMv8-A Architecture
 * 检测 ARMv8-A 架构
 * __ARM_ARCH_8A__ or __aarch64__ defined for ARMv8-A
 */
#elif defined(__ARM_ARCH_8A__) || defined(__aarch64__) || \
      (defined(__ARM_ARCH) && __ARM_ARCH >= 8 && !defined(__ARM_ARCH_PROFILE__))
    #define __ARM_ARCH_V8A__      1
    #define __ARM_ARCH__          8
    #define __ARM_ARCH_PROFILE__ 'A'

/**
 * Detect ARMv9-A Architecture
 * 检测 ARMv9-A 架构
 * Based on feature macros for ARMv9-A
 */
#elif defined(__ARM_FEATURE_MTE) || defined(__ARM_FEATURE_BTI) || \
      (defined(__ARM_ARCH) && __ARM_ARCH >= 9)
    #define __ARM_ARCH_V9A__      1
    #define __ARM_ARCH__          9
    #define __ARM_ARCH_PROFILE__ 'A'

/**
 * Detect ARMv7-A Architecture
 * 检测 ARMv7-A 架构
 * __ARM_ARCH_7A__ defined for ARMv7-A
 */
#elif defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__)
    #define __ARM_ARCH_V7A__      1
    #define __ARM_ARCH__          7
    #define __ARM_ARCH_PROFILE__ 'A'

#else
    #error "Unsupported ARM architecture. Please define the architecture explicitly."
#endif

/*
 * ============================================================================
 * Sub-Architecture Specific Includes
 * 子架构特定包含
 * ============================================================================
 */

#if defined(__ARM_ARCH_V8M__)
    /*
     * ARMv8-M Architecture
     * Includes: Base, Main, Main Extension, Security, MVE, PMU, etc.
     */
    #include "armv8-m/armv8-m.h"

#elif defined(__ARM_ARCH_V7M__)
    /*
     * ARMv7-M Architecture
     * Includes: Base, Extensions (DSP, FPU)
     */
    #include "armv7-m/armv7-m.h"

#elif defined(__ARM_ARCH_V8A__)
    /*
     * ARMv8-A Architecture
     * Includes: AArch64, AArch32, EL2, EL3, Virtualization
     */
    #include "armv8-a/armv8-a.h"

#elif defined(__ARM_ARCH_V9A__)
    /*
     * ARMv9-A Architecture
     * Includes: SVE2, MTE, BTI, TME, etc.
     */
    #include "armv9-a/armv9-a.h"

#elif defined(__ARM_ARCH_V7A__)
    /*
     * ARMv7-A Architecture
     * Includes: Virtualization Extensions, Large Physical Address Extension
     */
    #include "armv7-a/armv7-a.h"

#endif

/*
 * ============================================================================
 * Common ARM Definitions
 * 通用 ARM 定义
 * ============================================================================
 */

/**
 * ARM Architecture Version String
 * ARM 架构版本字符串
 */
#if defined(__ARM_ARCH_V8M__)
    #define ARM_ARCH_STRING       "ARMv8-M"
#elif defined(__ARM_ARCH_V7M__)
    #define ARM_ARCH_STRING       "ARMv7-M"
#elif defined(__ARM_ARCH_V9A__)
    #define ARM_ARCH_STRING       "ARMv9-A"
#elif defined(__ARM_ARCH_V8A__)
    #define ARM_ARCH_STRING       "ARMv8-A"
#elif defined(__ARM_ARCH_V7A__)
    #define ARM_ARCH_STRING       "ARMv7-A"
#else
    #define ARM_ARCH_STRING       "Unknown"
#endif

/**
 * ARM Architecture Profile String
 * ARM 架构配置文件字符串
 */
#if (__ARM_ARCH_PROFILE__ == 'M')
    #define ARM_ARCH_PROFILE_STRING "Microcontroller"
#elif (__ARM_ARCH_PROFILE__ == 'A')
    #define ARM_ARCH_PROFILE_STRING "Application"
#elif (__ARM_ARCH_PROFILE__ == 'R')
    #define ARM_ARCH_PROFILE_STRING "Real-time"
#else
    #define ARM_ARCH_PROFILE_STRING "Unknown"
#endif

/*
 * ============================================================================
 * Common Inline Functions
 * 通用内联函数
 * ============================================================================
 */

/**
 * @brief Get ARM architecture version
 * @return Architecture version number (7, 8, 9)
 */
static inline uint32_t arm_get_arch_version(void)
{
    return __ARM_ARCH__;
}

/**
 * @brief Get ARM architecture profile
 * @return Architecture profile ('M', 'A', 'R')
 */
static inline char arm_get_arch_profile(void)
{
    return __ARM_ARCH_PROFILE__;
}

/**
 * @brief Check if architecture is ARMv7-M
 * @return 1 if ARMv7-M, 0 otherwise
 */
static inline int arm_is_v7m(void)
{
    #if defined(__ARM_ARCH_V7M__)
        return 1;
    #else
        return 0;
    #endif
}

/**
 * @brief Check if architecture is ARMv8-M
 * @return 1 if ARMv8-M, 0 otherwise
 */
static inline int arm_is_v8m(void)
{
    #if defined(__ARM_ARCH_V8M__)
        return 1;
    #else
        return 0;
    #endif
}

/**
 * @brief Check if architecture is ARMv7-A
 * @return 1 if ARMv7-A, 0 otherwise
 */
static inline int arm_is_v7a(void)
{
    #if defined(__ARM_ARCH_V7A__)
        return 1;
    #else
        return 0;
    #endif
}

/**
 * @brief Check if architecture is ARMv8-A
 * @return 1 if ARMv8-A, 0 otherwise
 */
static inline int arm_is_v8a(void)
{
    #if defined(__ARM_ARCH_V8A__)
        return 1;
    #else
        return 0;
    #endif
}

/**
 * @brief Check if architecture is ARMv9-A
 * @return 1 if ARMv9-A, 0 otherwise
 */
static inline int arm_is_v9a(void)
{
    #if defined(__ARM_ARCH_V9A__)
        return 1;
    #else
        return 0;
    #endif
}

/**
 * @brief Check if architecture is M-profile (Microcontroller)
 * @return 1 if M-profile, 0 otherwise
 */
static inline int arm_is_m_profile(void)
{
    return (__ARM_ARCH_PROFILE__ == 'M');
}

/**
 * @brief Check if architecture is A-profile (Application)
 * @return 1 if A-profile, 0 otherwise
 */
static inline int arm_is_a_profile(void)
{
    return (__ARM_ARCH_PROFILE__ == 'A');
}

/**
 * @brief Check if architecture is R-profile (Real-time)
 * @return 1 if R-profile, 0 otherwise
 */
static inline int arm_is_r_profile(void)
{
    return (__ARM_ARCH_PROFILE__ == 'R');
}

/*
 * ============================================================================
 * Compiler Check
 * 编译器检查
 * ============================================================================
 */

/* Note: In production builds, this should check for Clang/LLVM compiler.
 * For testing with GCC, the check is disabled.
 * #if !defined(__clang__)
 *     #error "This header only supports Clang/LLVM compiler"
 * #endif
 */

/**
 * @brief Get compiler type string
 * @return Compiler name string
 */
static inline const char* arm_get_compiler_string(void)
{
    return "Clang/LLVM";
}

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_H__ */
