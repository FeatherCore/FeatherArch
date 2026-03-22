/*
 * FeatherCore - ARM Cortex-M0+ Core Peripheral Access Layer
 * FeatherCore - ARM Cortex-M0+ 核心外设访问层
 *
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2024 FeatherCore Team. All rights reserved.
 *
 * Description:
 *   This file defines all NVIC, SysTick, SCB and FPU functions for ARM Cortex-M0+.
 *   本文件定义了 ARM Cortex-M0+ 的所有 NVIC、SysTick、SCB 和 FPU 函数。
 *
 * Documentation:
 *   ARM Cortex-M0+ Devices Generic User Guide
 *   ARMv6-M Architecture Reference Manual
 *
 * Note:
 *   This file depends on armv6m.h for architecture abstraction.
 *   本文件依赖于 armv6m.h 提供架构抽象层。
 */

#ifndef __CORE_CM0PLUS_H_GENERIC
#define __CORE_CM0PLUS_H_GENERIC

#include "armv6m.h"
#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif

/*
 * ============================================================================
 * CMSIS Defines
 * ============================================================================
 */

#define __CM0PLUS_REV              0x0001U
#define __MPU_PRESENT             1U
#define __VTOR_PRESENT            1U
#define __NVIC_PRIO_BITS          2U
#define __Vendor_SysTickConfig    0U
#define __FPU_PRESENT             0U
#define __SYSTICK_PRESENT         1U

/*
 * ============================================================================
 * Interrupt Number Definition
 * ============================================================================
 */

typedef enum {
    NonMaskableInt_IRQn         = -14,
    HardFault_IRQn              = -13,
    SVCall_IRQn                 = -5,
    PendSV_IRQn                 = -2,
    SysTick_IRQn                = -1,
    IRQ0_IRQn                   = 0,
    IRQ1_IRQn                   = 1,
    IRQ2_IRQn                   = 2,
    IRQ3_IRQn                   = 3,
    IRQ4_IRQn                   = 4,
    IRQ5_IRQn                   = 5,
    IRQ6_IRQn                   = 6,
    IRQ7_IRQn                   = 7,
    IRQ8_IRQn                   = 8,
    IRQ9_IRQn                   = 9,
    IRQ10_IRQn                  = 10,
    IRQ11_IRQn                  = 11,
    IRQ12_IRQn                  = 12,
    IRQ13_IRQn                  = 13,
    IRQ14_IRQn                  = 14,
    IRQ15_IRQn                  = 15,
    IRQ16_IRQn                  = 16,
    IRQ17_IRQn                  = 17,
    IRQ18_IRQn                  = 18,
    IRQ19_IRQn                  = 19,
    IRQ20_IRQn                  = 20,
    IRQ21_IRQn                  = 21,
    IRQ22_IRQn                  = 22,
    IRQ23_IRQn                  = 23,
    IRQ24_IRQn                  = 24,
    IRQ25_IRQn                  = 25,
    IRQ26_IRQn                  = 26,
    IRQ27_IRQn                  = 27,
    IRQ28_IRQn                  = 28,
    IRQ29_IRQn                  = 29,
    IRQ30_IRQn                  = 30,
    IRQ31_IRQn                  = 31
} IRQn_Type;

/*
 * ============================================================================
 * Processor Core Models
 * ============================================================================
 */

typedef struct {
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r4;
    uint32_t r5;
    uint32_t r6;
    uint32_t r7;
    uint32_t r8;
    uint32_t r9;
    uint32_t r10;
    uint32_t r11;
    uint32_t r12;
    uint32_t sp;
    uint32_t lr;
    uint32_t pc;
    uint32_t xpsr;
} CoreDebug_Type;

/*
 * ============================================================================
 * NVIC Functions
 * ============================================================================
 */

/**
 * @brief 使能指定中断
 * @brief Enable a device-specific interrupt
 * @param IRQn: 中断号 (IRQ0-IRQ31, 负值用于系统异常)
 */
__STATIC_INLINE void __NVIC_EnableIRQ(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        NVIC_ISER = (1U << ((uint32_t)(IRQn) & 0x1FUL));
    }
}

/**
 * @brief 获取中断使能状态
 * @brief Get the enable status for a device specific interrupt
 * @return 1=使能, 0=禁用
 */
__STATIC_INLINE uint32_t __NVIC_GetEnableIRQ(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        return((uint32_t)(((NVIC_ISER >> ((uint32_t)(IRQn) & 0x1FUL)) & 1U)));
    } else {
        return(0U);
    }
}

/**
 * @brief 禁用指定中断
 * @brief Disable a device-specific interrupt
 * @param IRQn: 中断号
 */
__STATIC_INLINE void __NVIC_DisableIRQ(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        NVIC_ICER = (1U << ((uint32_t)(IRQn) & 0x1FUL));
    }
}

/**
 * @brief 获取中断挂起状态
 * @brief Get the pending status for a device specific interrupt
 * @return 1=挂起, 0=未挂起
 */
__STATIC_INLINE uint32_t __NVIC_GetPendingIRQ(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        return((uint32_t)(((NVIC_ISPR >> ((uint32_t)(IRQn) & 0x1FUL)) & 1U)));
    } else {
        return(0U);
    }
}

/**
 * @brief 设置中断挂起状态
 * @brief Set the pending status for a device specific interrupt
 * @param IRQn: 中断号
 */
__STATIC_INLINE void __NVIC_SetPendingIRQ(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        NVIC_ISPR = (1U << ((uint32_t)(IRQn) & 0x1FUL));
    }
}

/**
 * @brief 清除中断挂起状态
 * @brief Clear the pending status for a device specific interrupt
 * @param IRQn: 中断号
 */
__STATIC_INLINE void __NVIC_ClearPendingIRQ(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        NVIC_ICPR = (1U << ((uint32_t)(IRQn) & 0x1FUL));
    }
}

/**
 * @brief 设置中断优先级
 * @brief Set the priority for a device specific interrupt
 * @param IRQn: 中断号
 * @param priority: 优先级 (0-3)
 */
__STATIC_INLINE void __NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority) {
    if ((int32_t)(IRQn) >= 0) {
        NVIC_IPR[(uint32_t)(IRQn) >> 2U] =
            (uint8_t)((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL);
    }
}

/**
 * @brief 获取中断优先级
 * @brief Get the priority for a device specific interrupt
 * @return 优先级
 */
__STATIC_INLINE uint32_t __NVIC_GetPriority(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        return(((uint32_t)(NVIC_IPR[(uint32_t)(IRQn) >> 2U]) >> (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL);
    } else {
        return(0U);
    }
}

/**
 * @brief 编码优先级
 * @brief Encode priority
 * @return 编码后的优先级
 */
__STATIC_INLINE uint32_t __NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority) {
    uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);
    uint32_t PreemptPriorityBits;
    uint32_t SubPriorityBits;

    PreemptPriorityBits = ((7UL - PriorityGroupTmp) < (uint32_t)(__NVIC_PRIO_BITS)) ?
                          (uint32_t)(7UL - PriorityGroupTmp) : (uint32_t)(__NVIC_PRIO_BITS);
    SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(__NVIC_PRIO_BITS)) < (uint32_t)7UL) ?
                          (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + __NVIC_PRIO_BITS);

    return (
           ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
           ((SubPriority & (uint32_t)((1UL << (SubPriorityBits)) - 1UL))
          );
}

/**
 * @brief 解码优先级
 * @brief Decode priority
 */
__STATIC_INLINE void __NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* const pPreemptPriority, uint32_t* const pSubPriority) {
    uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);
    uint32_t PreemptPriorityBits;
    uint32_t SubPriorityBits;

    PreemptPriorityBits = ((7UL - PriorityGroupTmp) < (uint32_t)(__NVIC_PRIO_BITS)) ?
                          (uint32_t)(7UL - PriorityGroupTmp) : (uint32_t)(__NVIC_PRIO_BITS);
    SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(__NVIC_PRIO_BITS)) < (uint32_t)7UL) ?
                          (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + __NVIC_PRIO_BITS);

    *pPreemptPriority = (Priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
    *pSubPriority     = (Priority & (uint32_t)((1UL << (SubPriorityBits)) - 1UL));
}

/*
 * ============================================================================
 * Vector Table Functions
 * ============================================================================
 */

/**
 * @brief 设置中断向量
 * @brief Set the vector table
 * @param IRQn: 中断号
 * @param vector: 中断处理函数地址
 */
__STATIC_INLINE void __NVIC_SetVector(IRQn_Type IRQn, uint32_t vector) {
    uint32_t *vectors = (uint32_t *)SCB_VTOR;
    vectors[(int16_t)IRQn + 16] = vector;
}

/**
 * @brief 获取中断向量
 * @brief Get the vector table
 * @return 中断处理函数地址
 */
__STATIC_INLINE uint32_t __NVIC_GetVector(IRQn_Type IRQn) {
    uint32_t *vectors = (uint32_t *)SCB_VTOR;
    return vectors[(int16_t)IRQn + 16];
}

/*
 * ============================================================================
 * System Reset Functions
 * ============================================================================
 */

/**
 * @brief 复位系统
 * @brief System Reset
 */
__STATIC_INLINE void __NVIC_SystemReset(void) {
    SCB_AIRCR  = ((0x5FAUL << 16U) | (SCB_AIRCR & (7UL << 8U)) | (1UL << 2U));
    __DSB();
    for(;;) {
        __NOP();
    }
}

/*
 * ============================================================================
 * SysTick Functions
 * ============================================================================
 */

/**
 * @brief SysTick 配置
 * @brief SysTick Configuration
 * @param ticks: 加载值
 * @return 0=成功, 1=失败
 */
__STATIC_INLINE uint32_t SysTick_Config(uint32_t ticks) {
    if ((ticks - 1UL) > 0xFFFFFFUL) {
        return (1UL);
    }
    SysTick->LOAD = (uint32_t)(ticks - 1UL);
    __NVIC_SetPriority(SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL);
    SysTick->VAL  = 0UL;
    SysTick->CTRL = 0x07UL;
    return (0UL);
}

/*
 * ============================================================================
 * FPU Functions (Cortex-M0+ 不支持 FPU)
 * ============================================================================
 */

/**
 * @brief 获取 FPU 类型
 * @brief Get FPU Type
 * @return 0 (Cortex-M0+ 没有 FPU)
 */
__STATIC_INLINE uint32_t SCB_GetFPUType(void) {
    return 0U;
}

/*
 * ============================================================================
 * MPU Functions (Cortex-M0+ 支持 MPU)
 * ============================================================================
 */

/**
 * @brief 使能 MPU
 * @brief Enable MPU
 * @param enable_default_map_forPrivileged: 使能特权模式默认内存映射
 */
__STATIC_INLINE void MPU_Enable(bool enable_default_map_forPrivileged) {
    __DMB();
    MPU->CTRL = MPU_CTRL_ENABLE_Msk;
    if (enable_default_map_forPrivileged) {
        MPU->CTRL |= MPU_CTRL_PRIVDEFENA_Msk;
    }
    __DSB();
    __ISB();
}

/**
 * @brief 禁用 MPU
 * @brief Disable MPU
 */
__STATIC_INLINE void MPU_Disable(void) {
    __DMB();
    MPU->CTRL  &= ~MPU_CTRL_ENABLE_Msk;
    __DSB();
    __ISB();
}

#ifdef __cplusplus
}
#endif

#endif
