/*
 * ARM Cortex-M33 Core Peripheral Access Layer Implementation
 * ARM Cortex-M33 核心外设访问层实现
 *
 * ============================================================================
 * File: core_cm33.c
 * Description: ARM Cortex-M33 core peripheral access layer implementation
 * 描述: ARM Cortex-M33 核心外设访问层实现
 *
 * This file provides complete implementation for ARM Cortex-M33 processor.
 * 本文件为 ARM Cortex-M33 处理器提供完整实现。
 *
 * Dependency Hierarchy / 依赖层次:
 *   core_cm33.c → core_cm33.h → armv8m.h → armv8m.c
 *   (This file) (Cortex-M33) (ARMv8-M)  (Implementation)
 *
 * Reference Documents / 参考文档:
 *   1. ARMv8-M Architecture Reference Manual (ARM DDI 0553B)
 *      - Chapter B2: Programmer's Model (Special Registers)
 *      - Chapter B3: System Control Registers
 *      - Chapter B4: Memory Protection Unit (MPU)
 *      - Chapter B5: Security Attribution Unit (SAU)
 *      - Chapter B6: Debug and Trace
 *
 *   2. ARM Cortex-M33 Devices Generic User Guide (DUI 0552A)
 *      - Chapter 4.2: System Control Block (SCB) registers
 *      - Chapter 4.3: Nested Vectored Interrupt Controller (NVIC)
 *      - Chapter 4.4: System Timer (SysTick)
 *      - Chapter 4.5: Memory Protection Unit (MPU)
 *      - Chapter 5: Floating-Point Unit (FPU)
 *      - Chapter 6: Security Attribution Unit (SAU)
 *      - Chapter 7: Instrumentation Trace Macrocell (ITM)
 *
 *   3. ARM Cortex-M33 Processor Technical Reference Manual (ARM DDI 0550A)
 *      - Chapter 4: Processor Registers
 *      - Chapter 11: Performance Monitor Unit (PMU)
 *
 *   4. ARM Cortex-M33 Processor Datasheet (V2)
 *      - Feature configuration
 *      - Memory map
 *
 * Cortex-M33 Features:
 *   - ARMv8-M Mainline architecture (ARMv8.0-M)
 *   - TrustZone Security Extension
 *   - Optional FPU (single/double precision)
 *   - MPU with 8 regions
 *   - DSP instructions (SIMD)
 *   - Hardware Integer Divide
 *   - Embedded Trace Macrocell (ETM) optional
 *   - Performance Monitor Unit (PMU)
 *
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 ARM Architecture Team. All rights reserved.
 */

#include "core_cm33.h"

/*
 * ============================================================================
 * Cortex-M33 Core ID Definitions
 * Cortex-M33 核心ID定义
 * Reference: ARM Cortex-M33 TRM Section 4.2 (CPUID)
 * 参考: ARM Cortex-M33 TRM 第 4.2 节 (CPUID)
 * ============================================================================
 */

/**
 * Cortex-M33 Revision
 * Cortex-M33 版本
 */
#define __CM33_REV         0x0000U

/**
 * Cortex-M33 Processor number
 * Cortex-M33 处理器编号
 */
#define __CORTEX_M          33U

/*
 * ============================================================================
 * NVIC Interrupt Controller Functions
 * NVIC 中断控制器函数
 * Reference: ARM Cortex-M33 Generic User Guide Chapter 4.3
 * 参考: ARM Cortex-M33 通用用户指南 第 4.3 章
 * ============================================================================
 */

/**
 * @brief Enable interrupt
 * @brief 使能中断
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.3.9 (NVIC_ISER)
 * 参考: ARM Cortex-M33 GUG 第 4.3.9 节 (NVIC_ISER)
 *
 * @param IRQn: Interrupt number
 * @param IRQn: 中断号
 */
void NVIC_EnableIRQ(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        arch_armv8m_enable_irq((uint8_t)IRQn);
    }
}

/**
 * @brief Disable interrupt
 * @brief 禁用中断
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.3.10 (NVIC_ICER)
 * 参考: ARM Cortex-M33 GUG 第 4.3.10 节 (NVIC_ICER)
 *
 * @param IRQn: Interrupt number
 * @param IRQn: 中断号
 */
void NVIC_DisableIRQ(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        arch_armv8m_disable_irq((uint8_t)IRQn);
    }
}

/**
 * @brief Get enabled status of interrupt
 * @brief 获取中断使能状态
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.3.9 (NVIC_ISER) and 4.3.10 (NVIC_ICER)
 * 参考: ARM Cortex-M33 GUG 第 4.3.9 节和第 4.3.10 节
 *
 * @param IRQn: Interrupt number
 * @param IRQn: 中断号
 * @return Interrupt enable status (0 = disabled, 1 = enabled)
 * @return 中断使能状态 (0 = 禁用, 1 = 使能)
 */
uint32_t NVIC_GetEnabledIRQ(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        return arch_armv8m_get_enable_irq((uint8_t)IRQn);
    }
    return 0;
}

/**
 * @brief Get pending status of interrupt
 * @brief 获取中断挂起状态
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.3.13 (NVIC_ISPR)
 * 参考: ARM Cortex-M33 GUG 第 4.3.13 节 (NVIC_ISPR)
 *
 * @param IRQn: Interrupt number
 * @param IRQn: 中断号
 * @return Interrupt pending status (0 = not pending, 1 = pending)
 * @return 中断挂起状态 (0 = 未挂起, 1 = 挂起)
 */
uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        return arch_armv8m_get_pending_irq((uint8_t)IRQn);
    }
    return 0;
}

/**
 * @brief Set pending interrupt
 * @brief 设置中断挂起
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.3.13 (NVIC_ISPR)
 * 参考: ARM Cortex-M33 GUG 第 4.3.13 节 (NVIC_ISPR)
 *
 * @param IRQn: Interrupt number
 * @param IRQn: 中断号
 */
void NVIC_SetPendingIRQ(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        arch_armv8m_set_pending((uint8_t)IRQn);
    }
}

/**
 * @brief Clear pending interrupt
 * @brief 清除中断挂起
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.3.14 (NVIC_ICPR)
 * 参考: ARM Cortex-M33 GUG 第 4.3.14 节 (NVIC_ICPR)
 *
 * @param IRQn: Interrupt number
 * @param IRQn: 中断号
 */
void NVIC_ClearPendingIRQ(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        arch_armv8m_clear_pending((uint8_t)IRQn);
    }
}

/**
 * @brief Get active interrupt status
 * @brief 获取活动中断状态
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.3.11 (NVIC_IABR)
 * 参考: ARM Cortex-M33 GUG 第 4.3.11 节 (NVIC_IABR)
 *
 * @param IRQn: Interrupt number
 * @param IRQn: 中断号
 * @return Active status (0 = not active, 1 = active)
 * @return 活动状态 (0 = 未活动, 1 = 活动)
 */
uint32_t NVIC_GetActive(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        return arch_armv8m_get_active_irq();
    }
    return 0;
}

/**
 * @brief Set interrupt priority
 * @brief 设置中断优先级
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.3.22 (NVIC_IPR)
 * 参考: ARM Cortex-M33 GUG 第 4.3.22 节 (NVIC_IPR)
 *
 * @param IRQn: Interrupt number
 * @param IRQn: 中断号
 * @param priority: Priority to set
 * @param priority: 要设置的优先级
 */
void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority) {
    if ((int32_t)(IRQn) >= 0) {
        arch_armv8m_set_priority((uint8_t)IRQn, (uint8_t)priority);
    }
}

/**
 * @brief Get interrupt priority
 * @brief 获取中断优先级
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.3.22 (NVIC_IPR)
 * 参考: ARM Cortex-M33 GUG 第 4.3.22 节 (NVIC_IPR)
 *
 * @param IRQn: Interrupt number
 * @param IRQn: 中断号
 * @return Current priority value
 * @return 当前优先级值
 */
uint32_t NVIC_GetPriority(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        return arch_armv8m_get_priority((uint8_t)IRQn);
    }
    return 0;
}

/**
 * @brief Encode priority
 * @brief 编码优先级
 *
 * @param PriorityGroup: Priority grouping
 * @param PriorityGroup: 优先级分组
 * @param PreemptPriority: Preemption priority
 * @param PreemptPriority: 抢占优先级
 * @param SubPriority: Sub-priority
 * @param SubPriority: 子优先级
 * @return Encoded priority value
 * @return 编码后的优先级值
 */
uint32_t NVIC_EncodePriority(uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority) {
    return arch_armv8m_encode_priority(PriorityGroup, PreemptPriority, SubPriority);
}

/**
 * @brief Decode priority
 * @brief 解码优先级
 *
 * @param Priority: Encoded priority value
 * @param Priority: 编码后的优先级值
 * @param PriorityGroup: Priority grouping
 * @param PriorityGroup: 优先级分组
 * @param pPreemptPriority: Pointer to preemption priority
 * @param pPreemptPriority: 抢占优先级指针
 * @param pSubPriority: Pointer to sub-priority
 * @param pSubPriority: 子优先级指针
 */
void NVIC_DecodePriority(uint32_t Priority, uint32_t PriorityGroup, uint32_t *pPreemptPriority, uint32_t *pSubPriority) {
    arch_armv8m_decode_priority(Priority, PriorityGroup, pPreemptPriority, pSubPriority);
}

/**
 * @brief Set interrupt vector
 * @brief 设置中断向量
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.2.18 (Vector Table Offset Register)
 * 参考: ARM Cortex-M33 GUG 第 4.2.18 节 (向量表偏移寄存器)
 *
 * @param IRQn: Interrupt number
 * @param IRQn: 中断号
 * @param vector: Vector address
 * @param vector: 向量地址
 */
void NVIC_SetVector(IRQn_Type IRQn, uint32_t vector) {
    arch_armv8m_set_vector((uint8_t)IRQn, vector);
}

/**
 * @brief Get interrupt vector
 * @brief 获取中断向量
 *
 * @param IRQn: Interrupt number
 * @param IRQn: 中断号
 * @return Vector address
 * @return 向量地址
 */
uint32_t NVIC_GetVector(IRQn_Type IRQn) {
    return arch_armv8m_get_vector((uint8_t)IRQn);
}

/**
 * @brief System reset
 * @brief 系统复位
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.3.1 (AIRCR)
 * 参考: ARM Cortex-M33 GUG 第 4.3.1 节 (AIRCR)
 */
void NVIC_SystemReset(void) {
    arch_armv8m_system_reset();
}

/**
 * @brief Set priority grouping
 * @brief 设置优先级分组
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.3.1 (AIRCR)
 * 参考: ARM Cortex-M33 GUG 第 4.3.1 节 (AIRCR)
 *
 * @param PriorityGroup: Priority grouping value
 * @param PriorityGroup: 优先级分组值
 */
void NVIC_SetPriorityGrouping(uint32_t PriorityGroup) {
    arch_armv8m_set_priority_grouping(PriorityGroup);
}

/**
 * @brief Get priority grouping
 * @brief 获取优先级分组
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.3.1 (AIRCR)
 * 参考: ARM Cortex-M33 GUG 第 4.3.1 节 (AIRCR)
 *
 * @return Priority grouping value
 * @return 优先级分组值
 */
uint32_t NVIC_GetPriorityGrouping(void) {
    return arch_armv8m_get_priority_grouping();
}

/*
 * ============================================================================
 * SysTick Timer Functions
 * SysTick 定时器函数
 * Reference: ARM Cortex-M33 Generic User Guide Chapter 4.4
 * 参考: ARM Cortex-M33 通用用户指南 第 4.4 章
 * ============================================================================
 */

/**
 * @brief SysTick configuration
 * @brief SysTick 配置
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.4.1 (SysTick Control and Status Register)
 * 参考: ARM Cortex-M33 GUG 第 4.4.1 节 (SysTick 控制和状态寄存器)
 *
 * @param ticks: Number of ticks between interrupts
 * @param ticks: 中断之间的tick数
 * @return 1 = configuration failed, 0 = success
 * @return 1 = 配置失败, 0 = 成功
 */
uint32_t SysTick_Config(uint32_t ticks) {
    return arch_armv8m_systick_config(ticks);
}

/**
 * @brief Get SysTick current value
 * @brief 获取 SysTick 当前值
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.4.3 (SysTick Current Value Register)
 * 参考: ARM Cortex-M33 GUG 第 4.4.3 节 (SysTick 当前值寄存器)
 *
 * @return Current counter value
 * @return 当前计数器值
 */
uint32_t SysTick_GetValue(void) {
    return arch_armv8m_systick_get_value();
}

/**
 * @brief Set SysTick reload value
 * @brief 设置 SysTick 重新加载值
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.4.2 (SysTick Reload Value Register)
 * 参考: ARM Cortex-M33 GUG 第 4.4.2 节 (SysTick 重新加载值寄存器)
 *
 * @param value: Reload value
 * @param value: 重新加载值
 */
void SysTick_SetReload(uint32_t value) {
    arch_armv8m_systick_set_reload(value);
}

/**
 * @brief Get SysTick reload value
 * @brief 获取 SysTick 重新加载值
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.4.2 (SysTick Reload Value Register)
 * 参考: ARM Cortex-M33 GUG 第 4.4.2 节 (SysTick 重新加载值寄存器)
 *
 * @return Reload value
 * @return 重新加载值
 */
uint32_t SysTick_GetReload(void) {
    return arch_armv8m_systick_get_reload();
}

/**
 * @brief Enable SysTick interrupt
 * @brief 使能 SysTick 中断
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.4.1 (SysTick Control and Status Register)
 * 参考: ARM Cortex-M33 GUG 第 4.4.1 节 (SysTick 控制和状态寄存器)
 */
void SysTick_EnableIRQ(void) {
    arch_armv8m_systick_enable_irq();
}

/**
 * @brief Disable SysTick interrupt
 * @brief 禁用 SysTick 中断
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.4.1 (SysTick Control and Status Register)
 * 参考: ARM Cortex-M33 GUG 第 4.4.1 节 (SysTick 控制和状态寄存器)
 */
void SysTick_DisableIRQ(void) {
    arch_armv8m_systick_disable_irq();
}

/**
 * @brief Enable SysTick timer
 * @brief 使能 SysTick 定时器
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.4.1 (SysTick Control and Status Register)
 * 参考: ARM Cortex-M33 GUG 第 4.4.1 节 (SysTick 控制和状态寄存器)
 */
void SysTick_Enable(void) {
    arch_armv8m_systick_enable();
}

/**
 * @brief Disable SysTick timer
 * @brief 禁用 SysTick 定时器
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.4.1 (SysTick Control and Status Register)
 * 参考: ARM Cortex-M33 GUG 第 4.4.1 节 (SysTick 控制和状态寄存器)
 */
void SysTick_Disable(void) {
    arch_armv8m_systick_disable();
}

/**
 * @brief Get SysTick calibration value
 * @brief 获取 SysTick 校准值
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.4.4 (SysTick Calibration Register)
 * 参考: ARM Cortex-M33 GUG 第 4.4.4 节 (SysTick 校准寄存器)
 *
 * @return Calibration value
 * @return 校准值
 */
uint32_t SysTick_GetCalib(void) {
    return arch_armv8m_systick_get_calib();
}

/*
 * ============================================================================
 * SCB (System Control Block) Functions
 * SCB (系统控制块) 函数
 * Reference: ARM Cortex-M33 Generic User Guide Chapter 4.2
 * 参考: ARM Cortex-M33 通用用户指南 第 4.2 章
 * ============================================================================
 */

/**
 * @brief Get FPU type
 * @brief 获取 FPU 类型
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.2.13 (MVFR0)
 * 参考: ARM Cortex-M33 GUG 第 4.2.13 节 (MVFR0)
 *
 * @return FPU type: 0 = no FPU, 1 = single precision, 2 = double precision
 * @return FPU 类型: 0 = 无 FPU, 1 = 单精度, 2 = 双精度
 */
uint32_t SCB_GetFPUType(void) {
    return arch_armv8m_scb_get_fpu_type();
}

/**
 * @brief Get SCB CPUID
 * @brief 获取 SCB CPUID
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.2.1 (CPUID Register)
 * 参考: ARM Cortex-M33 GUG 第 4.2.1 节 (CPUID 寄存器)
 *
 * @return CPUID value
 * @return CPUID 值
 */
uint32_t SCB_GetCPUID(void) {
    return SCB->CPUID;
}

/**
 * @brief Get ICSR (Interrupt Control and State Register)
 * @brief 获取 ICSR (中断控制和状态寄存器)
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.2.3 (ICSR)
 * 参考: ARM Cortex-M33 GUG 第 4.2.3 节 (ICSR)
 *
 * @return ICSR value
 * @return ICSR 值
 */
uint32_t SCB_GetICSR(void) {
    return SCB->ICSR;
}

/**
 * @brief Get VTOR (Vector Table Offset Register)
 * @brief 获取 VTOR (向量表偏移寄存器)
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.2.18 (VTOR)
 * 参考: ARM Cortex-M33 GUG 第 4.2.18 节 (VTOR)
 *
 * @return VTOR value
 * @return VTOR 值
 */
uint32_t SCB_GetVTOR(void) {
    return SCB->VTOR;
}

/**
 * @brief Set VTOR (Vector Table Offset Register)
 * @brief 设置 VTOR (向量表偏移寄存器)
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.2.18 (VTOR)
 * 参考: ARM Cortex-M33 GUG 第 4.2.18 节 (VTOR)
 *
 * @param vtors: Vector table offset
 * @param vtors: 向量表偏移
 */
void SCB_SetVTOR(uint32_t vtors) {
    SCB->VTOR = vtors;
}

/**
 * @brief Get AIRCR (Application Interrupt and Reset Control Register)
 * @brief 获取 AIRCR (应用中断和复位控制寄存器)
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.3.1 (AIRCR)
 * 参考: ARM Cortex-M33 GUG 第 4.3.1 节 (AIRCR)
 *
 * @return AIRCR value
 * @return AIRCR 值
 */
uint32_t SCB_GetAIRCR(void) {
    return SCB->AIRCR;
}

/**
 * @brief Set AIRCR (Application Interrupt and Reset Control Register)
 * @brief 设置 AIRCR (应用中断和复位控制寄存器)
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.3.1 (AIRCR)
 * 参考: ARM Cortex-M33 GUG 第 4.3.1 节 (AIRCR)
 *
 * @param aircr: AIRCR value
 * @param aircr: AIRCR 值
 */
void SCB_SetAIRCR(uint32_t aircr) {
    SCB->AIRCR = aircr;
}

/**
 * @brief Get SCR (System Control Register)
 * @brief 获取 SCR (系统控制寄存器)
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.2.11 (SCR)
 * 参考: ARM Cortex-M33 GUG 第 4.2.11 节 (SCR)
 *
 * @return SCR value
 * @return SCR 值
 */
uint32_t SCB_GetSCR(void) {
    return SCB->SCR;
}

/**
 * @brief Set SCR (System Control Register)
 * @brief 设置 SCR (系统控制寄存器)
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.2.11 (SCR)
 * 参考: ARM Cortex-M33 GUG 第 4.2.11 节 (SCR)
 *
 * @param scr: SCR value
 * @param scr: SCR 值
 */
void SCB_SetSCR(uint32_t scr) {
    SCB->SCR = scr;
}

/**
 * @brief Get CCR (Configuration and Control Register)
 * @brief 获取 CCR (配置和控制寄存器)
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.2.12 (CCR)
 * 参考: ARM Cortex-M33 GUG 第 4.2.12 节 (CCR)
 *
 * @return CCR value
 * @return CCR 值
 */
uint32_t SCB_GetCCR(void) {
    return SCB->CCR;
}

/**
 * @brief Get CFSR (Configurable Fault Status Register)
 * @brief 获取 CFSR (可配置故障状态寄存器)
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.3.8 (CFSR)
 * 参考: ARM Cortex-M33 GUG 第 4.3.8 节 (CFSR)
 *
 * @return CFSR value
 * @return CFSR 值
 */
uint32_t SCB_GetCFSR(void) {
    return SCB->CFSR;
}

/**
 * @brief Get HFSR (HardFault Status Register)
 * @brief 获取 HFSR (硬故障状态寄存器)
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.3.9 (HFSR)
 * 参考: ARM Cortex-M33 GUG 第 4.3.9 节 (HFSR)
 *
 * @return HFSR value
 * @return HFSR 值
 */
uint32_t SCB_GetHFSR(void) {
    return SCB->HFSR;
}

/**
 * @brief Get MMFAR (MemManage Fault Address Register)
 * @brief 获取 MMFAR (存储管理故障地址寄存器)
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.3.10 (MMFAR)
 * 参考: ARM Cortex-M33 GUG 第 4.3.10 节 (MMFAR)
 *
 * @return MMFAR value
 * @return MMFAR 值
 */
uint32_t SCB_GetMMFAR(void) {
    return SCB->MMFAR;
}

/**
 * @brief Get BFAR (Bus Fault Address Register)
 * @brief 获取 BFAR (总线故障地址寄存器)
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.3.11 (BFAR)
 * 参考: ARM Cortex-M33 GUG 第 4.3.11 节 (BFAR)
 *
 * @return BFAR value
 * @return BFAR 值
 */
uint32_t SCB_GetBFAR(void) {
    return SCB->BFAR;
}

/**
 * @brief Get SHCSR (System Handler Control and State Register)
 * @brief 获取 SHCSR (系统处理程序控制和状态寄存器)
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.3.6 (SHCSR)
 * 参考: ARM Cortex-M33 GUG 第 4.3.6 节 (SHCSR)
 *
 * @return SHCSR value
 * @return SHCSR 值
 */
uint32_t SCB_GetSHCSR(void) {
    return SCB->SHCSR;
}

/**
 * @brief Get CPACR (Coprocessor Access Control Register)
 * @brief 获取 CPACR (协处理器访问控制寄存器)
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.2.14 (CPACR)
 * 参考: ARM Cortex-M33 GUG 第 4.2.14 节 (CPACR)
 *
 * @return CPACR value
 * @return CPACR 值
 */
uint32_t SCB_GetCPACR(void) {
    return SCB->CPACR;
}

/**
 * @brief Set CPACR (Coprocessor Access Control Register)
 * @brief 设置 CPACR (协处理器访问控制寄存器)
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.2.14 (CPACR)
 * 参考: ARM Cortex-M33 GUG 第 4.2.14 节 (CPACR)
 *
 * @param cpacr: CPACR value
 * @param cpacr: CPACR 值
 */
void SCB_SetCPACR(uint32_t cpacr) {
    SCB->CPACR = cpacr;
}

/**
 * @brief Get FPSCR (Floating-Point Status Control Register)
 * @brief 获取 FPSCR (浮点状态控制寄存器)
 *
 * Reference: ARM Cortex-M33 GUG Chapter 5.1 (FP registers)
 * 参考: ARM Cortex-M33 GUG 第 5.1 节 (FP 寄存器)
 *
 * @return FPSCR value
 * @return FPSCR 值
 */
#if defined(__FPU_PRESENT) && (__FPU_PRESENT == 1U)
uint32_t SCB_GetFPSCR(void) {
    uint32_t result;
    __asm volatile ("VMRS %0, FPSCR" : "=r" (result));
    return result;
}

/**
 * @brief Set FPSCR (Floating-Point Status Control Register)
 * @brief 设置 FPSCR (浮点状态控制寄存器)
 *
 * Reference: ARM Cortex-M33 GUG Chapter 5.1 (FP registers)
 * 参考: ARM Cortex-M33 GUG 第 5.1 节 (FP 寄存器)
 *
 * @param fpscr: FPSCR value
 * @param fpscr: FPSCR 值
 */
void SCB_SetFPSCR(uint32_t fpscr) {
    __asm volatile ("VMSR FPSCR, %0" : : "r" (fpscr) : "vfpcc");
}
#endif

/*
 * ============================================================================
 * MPU (Memory Protection Unit) Functions
 * MPU (内存保护单元) 函数
 * Reference: ARM Cortex-M33 Generic User Guide Chapter 4.5
 * 参考: ARM Cortex-M33 通用用户指南 第 4.5 章
 * ============================================================================
 */

/**
 * @brief Get MPU type
 * @brief 获取 MPU 类型
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.5.1 (MPU_TYPE)
 * 参考: ARM Cortex-M33 GUG 第 4.5.1 节 (MPU_TYPE)
 *
 * @return MPU type register value
 * @return MPU 类型寄存器值
 */
uint32_t MPU_GetType(void) {
    return arch_armv8m_mpu_get_type();
}

/**
 * @brief Initialize MPU
 * @brief 初始化 MPU
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.5 (MPU)
 * 参考: ARM Cortex-M33 GUG 第 4.5 节 (MPU)
 */
void MPU_Initialize(void) {
    arch_armv8m_mpu_init();
}

/**
 * @brief Enable MPU
 * @brief 使能 MPU
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.5.2 (MPU_CTRL)
 * 参考: ARM Cortex-M33 GUG 第 4.5.2 节 (MPU_CTRL)
 *
 * @param enable_default_map_forPrivileged: Enable default map for privileged access
 * @param enable_default_map_forPrivileged: 为特权访问启用默认映射
 */
void MPU_Enable(bool enable_default_map_forPrivileged) {
    arch_armv8m_mpu_enable(enable_default_map_forPrivileged);
}

/**
 * @brief Disable MPU
 * @brief 禁用 MPU
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.5.2 (MPU_CTRL)
 * 参考: ARM Cortex-M33 GUG 第 4.5.2 节 (MPU_CTRL)
 */
void MPU_Disable(void) {
    arch_armv8m_mpu_disable();
}

/**
 * @brief Set MPU memory attribute
 * @brief 设置 MPU 内存属性
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.5.7 (MPU_MAIR0/MAIR1)
 * 参考: ARM Cortex-M33 GUG 第 4.5.7 节 (MPU_MAIR0/MAIR1)
 *
 * @param idx: Attribute index (0-7)
 * @param idx: 属性索引 (0-7)
 * @param attr: Memory attribute
 * @param attr: 内存属性
 */
void MPU_SetMemoryAttribute(uint8_t idx, uint8_t attr) {
    arch_armv8m_mpu_set_mem_attr(idx, attr);
}

/**
 * @brief Set MPU region
 * @brief 设置 MPU 区域
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.5.3-4.5.5 (MPU_RNR, RBAR, RLAR)
 * 参考: ARM Cortex-M33 GUG 第 4.5.3-4.5.5 节 (MPU_RNR, RBAR, RLAR)
 *
 * @param rnr: Region number
 * @param rnr: 区域编号
 * @param rbar: Region base address register
 * @param rbar: 区域基地址寄存器
 * @param rlar: Region limit register
 * @param rlar: 区域限制寄存器
 */
void MPU_SetRegion(uint32_t rnr, uint32_t rbar, uint32_t rlar) {
    arch_armv8m_mpu_set_region(rnr, rbar, rlar);
}

/**
 * @brief Clear MPU region
 * @brief 清除 MPU 区域
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.5.3 and 4.5.5
 * 参考: ARM Cortex-M33 GUG 第 4.5.3 节和第 4.5.5 节
 *
 * @param rnr: Region number
 * @param rnr: 区域编号
 */
void MPU_ClearRegion(uint32_t rnr) {
    arch_armv8m_mpu_clr_region(rnr);
}

/**
 * @brief Get number of MPU regions
 * @brief 获取 MPU 区域数量
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.5.1 (MPU_TYPE)
 * 参考: ARM Cortex-M33 GUG 第 4.5.1 节 (MPU_TYPE)
 *
 * @return Number of data regions
 * @return 数据区域数量
 */
uint32_t MPU_GetNumRegions(void) {
    return arch_armv8m_mpu_get_num_regions();
}

/*
 * ============================================================================
 * FPU (Floating Point Unit) Functions
 * FPU (浮点单元) 函数
 * Reference: ARM Cortex-M33 Generic User Guide Chapter 5
 * 参考: ARM Cortex-M33 通用用户指南 第 5 章
 * ============================================================================
 */

/**
 * @brief Enable FPU
 * @brief 使能 FPU
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.2.14 (CPACR)
 * 参考: ARM Cortex-M33 GUG 第 4.2.14 节 (CPACR)
 */
void FPU_Enable(void) {
    arch_armv8m_enable_fpu();
}

/**
 * @brief Disable FPU
 * @brief 禁用 FPU
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.2.14 (CPACR)
 * 参考: ARM Cortex-M33 GUG 第 4.2.14 节 (CPACR)
 */
void FPU_Disable(void) {
    arch_armv8m_disable_fpu();
}

/*
 * ============================================================================
 * SAU (Security Attribution Unit) Functions
 * SAU (安全属性单元) 函数
 * Reference: ARM Cortex-M33 Generic User Guide Chapter 6
 * 参考: ARM Cortex-M33 通用用户指南 第 6 章
 * ============================================================================
 */

/**
 * @brief Enable SAU
 * @brief 使能 SAU
 *
 * Reference: ARM Cortex-M33 GUG Chapter 6.3.1 (SAU_CTRL)
 * 参考: ARM Cortex-M33 GUG 第 6.3.1 节 (SAU_CTRL)
 */
void SAU_Enable(void) {
    arch_armv8m_tz_sau_enable();
}

/**
 * @brief Disable SAU
 * @brief 禁用 SAU
 *
 * Reference: ARM Cortex-M33 GUG Chapter 6.3.1 (SAU_CTRL)
 * 参考: ARM Cortex-M33 GUG 第 6.3.1 节 (SAU_CTRL)
 */
void SAU_Disable(void) {
    arch_armv8m_tz_sau_disable();
}

/**
 * @brief Set SAU region
 * @brief 设置 SAU 区域
 *
 * Reference: ARM Cortex-M33 GUG Chapter 6.3.3-6.3.5 (SAU_RNR, RBAR, RLAR)
 * 参考: ARM Cortex-M33 GUG 第 6.3.3-6.3.5 节 (SAU_RNR, RBAR, RLAR)
 *
 * @param rnr: Region number
 * @param rnr: 区域编号
 * @param rbar: Region base address
 * @param rbar: 区域基地址
 * @param rlar: Region limit and attributes
 * @param rlar: 区域限制和属性
 */
void SAU_SetRegion(uint32_t rnr, uint32_t rbar, uint32_t rlar) {
    arch_armv8m_tz_sau_set_region(rnr, rbar, rlar);
}

/**
 * @brief Get SAU type
 * @brief 获取 SAU 类型
 *
 * Reference: ARM Cortex-M33 GUG Chapter 6.3.2 (SAU_TYPE)
 * 参考: ARM Cortex-M33 GUG 第 6.3.2 节 (SAU_TYPE)
 *
 * @return SAU type register value
 * @return SAU 类型寄存器值
 */
uint32_t SAU_GetType(void) {
    return SAU->TYPE;
}

/*
 * ============================================================================
 * ITM (Instrumentation Trace Macrocell) Functions
 * ITM (仪表跟踪宏单元) 函数
 * Reference: ARM Cortex-M33 Generic User Guide Chapter 7
 * 参考: ARM Cortex-M33 通用用户指南 第 7 章
 * ============================================================================
 */

/**
 * @brief ITM send character
 * @brief ITM 发送字符
 *
 * Reference: ARM Cortex-M33 GUG Chapter 7.2.2 (ITM_STIM)
 * 参考: ARM Cortex-M33 GUG 第 7.2.2 节 (ITM_STIM)
 *
 * @param ch: Character to send
 * @param ch: 要发送的字符
 * @return Character sent
 * @return 发送的字符
 */
uint32_t ITM_SendChar(uint32_t ch) {
    return arch_armv8m_itm_send_char(ch);
}

/**
 * @brief ITM receive character
 * @brief ITM 接收字符
 *
 * Reference: ARM Cortex-M33 GUG Chapter 7.2.1 (ITM_RXR)
 * 参考: ARM Cortex-M33 GUG 第 7.2.1 节 (ITM_RXR)
 *
 * @return Received character or -1 if no data
 * @return 接收的字符或如果没有数据则返回 -1
 */
int32_t ITM_ReceiveChar(void) {
    return arch_armv8m_itm_receive_char();
}

/**
 * @brief ITM check for character
 * @brief ITM 检查字符
 *
 * Reference: ARM Cortex-M33 GUG Chapter 7.2.1 (ITM_RXR)
 * 参考: ARM Cortex-M33 GUG 第 7.2.1 节 (ITM_RXR)
 *
 * @return 1 = character available, 0 = no character
 * @return 1 = 有字符可用, 0 = 无字符
 */
int32_t ITM_CheckChar(void) {
    return arch_armv8m_itm_check_char();
}

/**
 * @brief ITM enable
 * @brief ITM 使能
 *
 * Reference: ARM Cortex-M33 GUG Chapter 7.2.3 (ITM_TCR)
 * 参考: ARM Cortex-M33 GUG 第 7.2.3 节 (ITM_TCR)
 *
 * @param enable: Enable (1) or disable (0)
 * @param enable: 使能 (1) 或禁用 (0)
 */
void ITM_Enable(uint32_t enable) {
    arch_armv8m_itm_enable(enable);
}

/*
 * ============================================================================
 * PMU (Performance Monitor Unit) Functions
 * PMU (性能监视单元) 函数
 * Reference: ARM Cortex-M33 TRM Chapter 11
 * 参考: ARM Cortex-M33 TRM 第 11 章
 * ============================================================================
 */

/**
 * @brief Enable PMU
 * @brief 使能 PMU
 *
 * Reference: ARM Cortex-M33 TRM Chapter 11.3.1 (PMU_CTRL)
 * 参考: ARM Cortex-M33 TRM 第 11.3.1 节 (PMU_CTRL)
 */
void PMU_Enable(void) {
    arch_armv8m_pmu_enable();
}

/**
 * @brief Disable PMU
 * @brief 禁用 PMU
 *
 * Reference: ARM Cortex-M33 TRM Chapter 11.3.1 (PMU_CTRL)
 * 参考: ARM Cortex-M33 TRM 第 11.3.1 节 (PMU_CTRL)
 */
void PMU_Disable(void) {
    arch_armv8m_pmu_disable();
}

/**
 * @brief Reset cycle counter
 * @brief 复位周期计数器
 *
 * Reference: ARM Cortex-M33 TRM Chapter 11.3.1 (PMU_CTRL)
 * 参考: ARM Cortex-M33 TRM 第 11.3.1 节 (PMU_CTRL)
 */
void PMU_ResetCycleCounter(void) {
    arch_armv8m_pmu_cyccnt_reset();
}

/**
 * @brief Reset all event counters
 * @brief 复位所有事件计数器
 *
 * Reference: ARM Cortex-M33 TRM Chapter 11.3.1 (PMU_CTRL)
 * 参考: ARM Cortex-M33 TRM 第 11.3.1 节 (PMU_CTRL)
 */
void PMU_ResetEventCounters(void) {
    arch_armv8m_pmu_evcntr_all_reset();
}

/**
 * @brief Enable PMU counters
 * @brief 使能 PMU 计数器
 *
 * Reference: ARM Cortex-M33 TRM Chapter 11.3.3 (PMU_CNTENSET)
 * 参考: ARM Cortex-M33 TRM 第 11.3.3 节 (PMU_CNTENSET)
 *
 * @param mask: Counter enable mask
 * @param mask: 计数器使能掩码
 */
void PMU_EnableCounter(uint32_t mask) {
    arch_armv8m_pmu_cntr_enable(mask);
}

/**
 * @brief Disable PMU counters
 * @brief 禁用 PMU 计数器
 *
 * Reference: ARM Cortex-M33 TRM Chapter 11.3.4 (PMU_CNTENCLR)
 * 参考: ARM Cortex-M33 TRM 第 11.3.4 节 (PMU_CNTENCLR)
 *
 * @param mask: Counter disable mask
 * @param mask: 计数器禁用掩码
 */
void PMU_DisableCounter(uint32_t mask) {
    arch_armv8m_pmu_cntr_disable(mask);
}

/**
 * @brief Get cycle counter value
 * @brief 获取周期计数器值
 *
 * Reference: ARM Cortex-M33 TRM Chapter 11.3.2 (PMU_CYCCNT)
 * 参考: ARM Cortex-M33 TRM 第 11.3.2 节 (PMU_CYCCNT)
 *
 * @return Cycle count
 * @return 周期计数
 */
uint32_t PMU_GetCycleCount(void) {
    return arch_armv8m_pmu_get_ccntr();
}

/**
 * @brief Get event counter value
 * @brief 获取事件计数器值
 *
 * Reference: ARM Cortex-M33 TRM Chapter 11.3.5 (PMU_EVCNTR)
 * 参考: ARM Cortex-M33 TRM 第 11.3.5 节 (PMU_EVCNTR)
 *
 * @param counter: Counter number
 * @param counter: 计数器编号
 * @return Event counter value
 * @return 事件计数器值
 */
uint32_t PMU_GetEventCounter(uint32_t counter) {
    return arch_armv8m_pmu_get_evcntr(counter);
}

/**
 * @brief Set event type
 * @brief 设置事件类型
 *
 * Reference: ARM Cortex-M33 TRM Chapter 11.3.6 (PMU_EVTYPER)
 * 参考: ARM Cortex-M33 TRM 第 11.3.6 节 (PMU_EVTYPER)
 *
 * @param counter: Counter number
 * @param counter: 计数器编号
 * @param type: Event type
 * @param type: 事件类型
 */
void PMU_SetEventType(uint32_t counter, uint32_t type) {
    arch_armv8m_pmu_set_evtyper(counter, type);
}

/**
 * @brief Get PMU overflow status
 * @brief 获取 PMU 溢出状态
 *
 * Reference: ARM Cortex-M33 TRM Chapter 11.3.1 (PMU_CTRL)
 * 参考: ARM Cortex-M33 TRM 第 11.3.1 节 (PMU_CTRL)
 *
 * @return Overflow status
 * @return 溢出状态
 */
uint32_t PMU_GetOverflowStatus(void) {
    return arch_armv8m_pmu_get_cntr_ovs();
}

/**
 * @brief Enable PMU overflow interrupt
 * @brief 使能 PMU 溢出中断
 *
 * Reference: ARM Cortex-M33 TRM Chapter 11.3.7 (PMU_INTENSET)
 * 参考: ARM Cortex-M33 TRM 第 11.3.7 节 (PMU_INTENSET)
 *
 * @param mask: Counter overflow interrupt mask
 * @param mask: 计数器溢出中断掩码
 */
void PMU_EnableOverflowIRQ(uint32_t mask) {
    arch_armv8m_pmu_set_cntr_irq_enable(mask);
}

/**
 * @brief Disable PMU overflow interrupt
 * @brief 禁用 PMU 溢出中断
 *
 * Reference: ARM Cortex-M33 TRM Chapter 11.3.8 (PMU_INTENCLR)
 * 参考: ARM Cortex-M33 TRM 第 11.3.8 节 (PMU_INTENCLR)
 *
 * @param mask: Counter overflow interrupt mask
 * @param mask: 计数器溢出中断掩码
 */
void PMU_DisableOverflowIRQ(uint32_t mask) {
    arch_armv8m_pmu_set_cntr_irq_disable(mask);
}

/*
 * ============================================================================
 * TrustZone Non-Secure Functions
 * TrustZone 非安全函数
 * Reference: ARM Cortex-M33 Generic User Guide Chapter 6
 * 参考: ARM Cortex-M33 通用用户指南 第 6 章
 * ============================================================================
 */

/**
 * @brief Get CONTROL register (Non-Secure)
 * @brief 获取 CONTROL 寄存器 (非安全)
 *
 * Reference: ARM Cortex-M33 GUG Chapter 6.4 (Non-secure access to registers)
 * 参考: ARM Cortex-M33 GUG 第 6.4 节 (寄存器的非安全访问)
 *
 * @return Non-secure CONTROL value
 * @return 非安全 CONTROL 值
 */
uint32_t TZ_GetControl_NS(void) {
    return arch_armv8m_tz_get_control_ns();
}

/**
 * @brief Set CONTROL register (Non-Secure)
 * @brief 设置 CONTROL 寄存器 (非安全)
 *
 * @param control: Non-secure CONTROL value
 * @param control: 非安全 CONTROL 值
 */
void TZ_SetControl_NS(uint32_t control) {
    arch_armv8m_tz_set_control_ns(control);
}

/**
 * @brief Get PSP (Non-Secure)
 * @brief 获取 PSP (非安全)
 *
 * @return Non-secure PSP value
 * @return 非安全 PSP 值
 */
uint32_t TZ_GetPSP_NS(void) {
    return arch_armv8m_tz_get_psp_ns();
}

/**
 * @brief Set PSP (Non-Secure)
 * @brief 设置 PSP (非安全)
 *
 * @param psp: Non-secure PSP value
 * @param psp: 非安全 PSP 值
 */
void TZ_SetPSP_NS(uint32_t psp) {
    arch_armv8m_tz_set_psp_ns(psp);
}

/**
 * @brief Get MSP (Non-Secure)
 * @brief 获取 MSP (非安全)
 *
 * @return Non-secure MSP value
 * @return 非安全 MSP 值
 */
uint32_t TZ_GetMSP_NS(void) {
    return arch_armv8m_tz_get_msp_ns();
}

/**
 * @brief Set MSP (Non-Secure)
 * @brief 设置 MSP (非安全)
 *
 * @param msp: Non-secure MSP value
 * @param msp: 非安全 MSP 值
 */
void TZ_SetMSP_NS(uint32_t msp) {
    arch_armv8m_tz_set_msp_ns(msp);
}

/**
 * @brief Get PRIMASK (Non-Secure)
 * @brief 获取 PRIMASK (非安全)
 *
 * @return Non-secure PRIMASK value
 * @return 非安全 PRIMASK 值
 */
uint32_t TZ_GetPRIMASK_NS(void) {
    return arch_armv8m_tz_get_primask_ns();
}

/**
 * @brief Set PRIMASK (Non-Secure)
 * @brief 设置 PRIMASK (非安全)
 *
 * @param primask: Non-secure PRIMASK value
 * @param primask: 非安全 PRIMASK 值
 */
void TZ_SetPRIMASK_NS(uint32_t primask) {
    arch_armv8m_tz_set_primask_ns(primask);
}

/**
 * @brief Get BASEPRI (Non-Secure)
 * @brief 获取 BASEPRI (非安全)
 *
 * @return Non-secure BASEPRI value
 * @return 非安全 BASEPRI 值
 */
uint32_t TZ_GetBASEPRI_NS(void) {
    return arch_armv8m_tz_get_basepri_ns();
}

/**
 * @brief Set BASEPRI (Non-Secure)
 * @brief 设置 BASEPRI (非安全)
 *
 * @param basepri: Non-secure BASEPRI value
 * @param basepri: 非安全 BASEPRI 值
 */
void TZ_SetBASEPRI_NS(uint32_t basepri) {
    arch_armv8m_tz_set_basepri_ns(basepri);
}

/**
 * @brief Get FAULTMASK (Non-Secure)
 * @brief 获取 FAULTMASK (非安全)
 *
 * @return Non-secure FAULTMASK value
 * @return 非安全 FAULTMASK 值
 */
uint32_t TZ_GetFAULTMASK_NS(void) {
    return arch_armv8m_tz_get_faultmask_ns();
}

/**
 * @brief Set FAULTMASK (Non-Secure)
 * @brief 设置 FAULTMASK (非安全)
 *
 * @param faultmask: Non-secure FAULTMASK value
 * @param faultmask: 非安全 FAULTMASK 值
 */
void TZ_SetFAULTMASK_NS(uint32_t faultmask) {
    arch_armv8m_tz_set_faultmask_ns(faultmask);
}

/**
 * @brief Get PSPLIM (Non-Secure)
 * @brief 获取 PSPLIM (非安全)
 *
 * @return Non-secure PSPLIM value
 * @return 非安全 PSPLIM 值
 */
uint32_t TZ_GetPSPLIM_NS(void) {
    return arch_armv8m_tz_get_psplim_ns();
}

/**
 * @brief Set PSPLIM (Non-Secure)
 * @brief 设置 PSPLIM (非安全)
 *
 * @param psplim: Non-secure PSPLIM value
 * @param psplim: 非安全 PSPLIM 值
 */
void TZ_SetPSPLIM_NS(uint32_t psplim) {
    arch_armv8m_tz_set_psplim_ns(psplim);
}

/**
 * @brief Get MSPLIM (Non-Secure)
 * @brief 获取 MSPLIM (非安全)
 *
 * @return Non-secure MSPLIM value
 * @return 非安全 MSPLIM 值
 */
uint32_t TZ_GetMSPLIM_NS(void) {
    return arch_armv8m_tz_get_msplim_ns();
}

/**
 * @brief Set MSPLIM (Non-Secure)
 * @brief 设置 MSPLIM (非安全)
 *
 * @param msplim: Non-secure MSPLIM value
 * @param msplim: 非安全 MSPLIM 值
 */
void TZ_SetMSPLIM_NS(uint32_t msplim) {
    arch_armv8m_tz_set_msplim_ns(msplim);
}

/*
 * ============================================================================
 * Initialization Functions
 * 初始化函数
 * ============================================================================
 */

/**
 * @brief Initialize Cortex-M33 core
 * @brief 初始化 Cortex-M33 核心
 *
 * This function initializes the Cortex-M33 core including:
 * 本函数初始化 Cortex-M33 核心包括:
 *   - FPU enable
 *   - MPU initialization
 *   - Memory barriers
 *
 * Reference: ARM Cortex-M33 GUG and TRM
 * 参考: ARM Cortex-M33 GUG 和 TRM
 */
void Core_Init(void) {
    arch_armv8m_init();
}

/**
 * @brief Setup vector table
 * @brief 设置向量表
 *
 * Reference: ARM Cortex-M33 GUG Chapter 4.2.18 (VTOR)
 * 参考: ARM Cortex-M33 GUG 第 4.2.18 节 (VTOR)
 */
void Core_SetupVectorTable(void) {
    arch_armv8m_setup_vector_table();
}
