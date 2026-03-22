/*
 * FeatherCore Architecture - ARM Clang/LLVM Backend
 *
 * ============================================================================
 * 文件: arch_arm.h
 * 描述: ARM 架构公共头文件，提供架构检测宏和公共 API
 *
 * 支持的架构:
 *   M-Profile (微控制器):
 *     - ARMv6-M   : Cortex-M0, Cortex-M0+
 *     - ARMv7-M   : Cortex-M3, Cortex-M4
 *     - ARMv8-M   : Cortex-M23 (Baseline), Cortex-M33/M55 (Mainline)
 *
 *   A-Profile (应用处理器):
 *     - ARMv7-A   : Cortex-A5, Cortex-A7, Cortex-A8, Cortex-A15
 *     - ARMv8-A   : Cortex-A53, Cortex-A72, Cortex-A78
 *
 *   R-Profile (实时处理器):
 *     - ARMv7-R   : Cortex-R4, Cortex-R5, Cortex-R7
 *     - ARMv8-R   : Cortex-R52
 *
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 FeatherCore Team. All rights reserved.
 */

#ifndef FEATHERCORE_ARCH_ARM_H
#define FEATHERCORE_ARCH_ARM_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define FEATHERCORE_ARCH_ARM_VERSION_MAJOR  1
#define FEATHERCORE_ARCH_ARM_VERSION_MINOR  0

#if defined(__ARM_ARCH_6M__) || defined(__ARM_ARCH_6SM__)
    #define FEATHERCORE_ARCH_ARM_PROFILE_M
    #define FEATHERCORE_ARCH_ARM_SUBARCH     "ARMv6-M"
    #include "armv6m/armv6m.h"

#elif defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
    #define FEATHERCORE_ARCH_ARM_PROFILE_M
    #define FEATHERCORE_ARCH_ARM_SUBARCH     "ARMv7-M"
    #include "armv7m/armv7m.h"

#elif defined(__ARM_ARCH_8M_BASE__) || defined(__ARM_ARCH_8M_MAIN__) || defined(__ARM_ARCH_8_1M_MAIN__)
    #define FEATHERCORE_ARCH_ARM_PROFILE_M
    #define FEATHERCORE_ARCH_ARM_SUBARCH     "ARMv8-M"
    #include "armv8m/armv8m.h"

#elif defined(__ARM_ARCH_7A__)
    #define FEATHERCORE_ARCH_ARM_PROFILE_A
    #define FEATHERCORE_ARCH_ARM_SUBARCH     "ARMv7-A"
    #include "armv7a/armv7a.h"

#elif defined(__ARM_ARCH_8A__) || defined(__ARM_ARCH_9A__) || defined(__ARM_ARCH_10A__)
    #define FEATHERCORE_ARCH_ARM_PROFILE_A
    #define FEATHERCORE_ARCH_ARM_SUBARCH     "ARMv8-A"
    #include "armv8a/armv8a.h"

#elif defined(__ARM_ARCH_7R__)
    #define FEATHERCORE_ARCH_ARM_PROFILE_R
    #define FEATHERCORE_ARCH_ARM_SUBARCH     "ARMv7-R"
    #include "armv7r/armv7r.h"

#elif defined(__ARM_ARCH_8R__)
    #define FEATHERCORE_ARCH_ARM_PROFILE_R
    #define FEATHERCORE_ARCH_ARM_SUBARCH     "ARMv8-R"
    #include "armv7r/armv7r.h"

#else
    #error "FeatherCore ARM: Unsupported ARM architecture"
#endif

void arch_arm_init(void);
void arch_arm_setup_vector_table(void);
void arch_arm_dsb(void);
void arch_arm_isb(void);
void arch_arm_dmb(void);
void arch_arm_wfi(void);
void arch_arm_wfe(void);
void arch_arm_sev(void);
uint32_t arch_arm_get_privilege_level(void);
bool arch_arm_is_secure_state(void);
const char* arch_arm_get_arch_name(void);

#ifdef __cplusplus
}
#endif

#endif /* FEATHERCORE_ARCH_ARM_H */
