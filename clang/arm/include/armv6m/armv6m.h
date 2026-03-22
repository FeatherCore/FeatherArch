/*
 * FeatherCore Architecture - ARMv6-M (Cortex-M0/M0+) Support
 *
 * ============================================================================
 * 文件: armv6m.h
 * 描述: ARMv6-M 架构特定定义和函数声明
 *
 * ARMv6-M 架构概述:
 *   ARMv6-M 是 ARM 处理器系列中最精简的架构，专为超低成本 MCU 设计。
 *   仅支持 Thumb 指令集，不支持 ARM 指令集。
 *
 * 支持的处理器:
 *   - Cortex-M0: 最早的超低成本 32 位处理器，2 级流水线
 *   - Cortex-M0+: 增强型 Cortex-M0，3 级流水线，增加更多调试特性
 *
 * 主要特性:
 *   - 2-3 级流水线
 *   - 仅支持 Thumb 指令集 (包括 Thumb-2)
 *   - 嵌套向量中断控制器 (NVIC)
 *   - 可选 MPU (仅 Cortex-M0+)
 *   - 最多 32 个中断源
 *   - 4 种睡眠模式
 *
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 FeatherCore Team. All rights reserved.
 */

#ifndef FEATHERCORE_ARCH_ARM_V6M_H
#define FEATHERCORE_ARCH_ARM_V6M_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * ARMv6-M 配置宏定义
 * ============================================================================
 */

#define FEATHERCORE_ARCH_ARM_V6M

/*
 * ============================================================================
 * ARMv6-M 任务上下文结构体
 * ============================================================================
 *
 * 任务上下文用于保存和恢复任务执行状态。
 * ARMv6-M 是最小的 ARM 架构，寄存器较少。
 *
 * 成员说明:
 *   r0-r12: 通用寄存器
 *   sp:     栈指针 (SP)
 *   lr:     连接寄存器 (Link Register)
 *   pc:     程序计数器 (Program Counter)
 *   xpsr:   程序状态寄存器 (xPSR)
 *   control: 控制寄存器
 *   primask: 中断屏蔽寄存器
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
    uint32_t control;
    uint32_t primask;
} ArmV6mTaskContext;

/*
 * ============================================================================
 * ARMv6-M 异常帧结构体
 * ============================================================================
 *
 * 当异常发生时，CPU 自动将以下寄存器压入栈:
 *   r0, r1, r2, r3, r12, lr, pc, xpsr
 * 这 8 个寄存器构成异常帧。
 */

typedef struct {
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r12;
    uint32_t lr;
    uint32_t pc;
    uint32_t xpsr;
} ArmV6mExceptionFrame;

/*
 * ============================================================================
 * ARMv6-M 核心寄存器访问函数声明
 * ============================================================================
 */

/**
 * @brief 获取 CONTROL 寄存器值
 * @return CONTROL 寄存器当前值
 *
 * CONTROL 寄存器控制:
 *   - BIT[0]: nPRIV - 特权级别 (0=特权, 1=用户)
 *   - BIT[1]: SPSEL - 栈指针选择 (0=MSP, 1=PSP)
 */
uint32_t arch_armv6m_get_control(void);

/**
 * @brief 设置 CONTROL 寄存器值
 * @param control: CONTROL 寄存器新值
 */
void arch_armv6m_set_control(uint32_t control);

/**
 * @brief 获取主栈指针 (MSP)
 * @return MSP 当前值
 */
uint32_t arch_armv6m_get_msp(void);

/**
 * @brief 设置主栈指针 (MSP)
 * @param msp: MSP 新值
 */
void arch_armv6m_set_msp(uint32_t msp);

/**
 * @brief 获取进程栈指针 (PSP)
 * @return PSP 当前值
 */
uint32_t arch_armv6m_get_psp(void);

/**
 * @brief 设置进程栈指针 (PSP)
 * @param psp: PSP 新值
 */
void arch_armv6m_set_psp(uint32_t psp);

/**
 * @brief 获取 PRIMASK 寄存器
 * @return PRIMASK 当前值
 *
 * PRIMASK 用于屏蔽所有可配置优先级的中断
 */
uint32_t arch_armv6m_get_primask(void);

/**
 * @brief 设置 PRIMASK 寄存器
 * @param primask: PRIMASK 新值
 */
void arch_armv6m_set_primask(uint32_t primask);

/*
 * ============================================================================
 * ARMv6-M 内存屏障函数声明
 * ============================================================================
 */

/**
 * @brief 数据同步屏障 (Data Synchronization Barrier)
 * @details 确保所有在 DSB 之前的显式内存访问完成后，才执行后续指令
 */
void arch_armv6m_dsb(void);

/**
 * @brief 指令同步屏障 (Instruction Synchronization Barrier)
 * @details 刷新流水线，确保后续指令从内存重新获取
 */
void arch_armv6m_isb(void);

/**
 * @brief 数据内存屏障 (Data Memory Barrier)
 * @details 确保所有内存访问按程序顺序完成
 */
void arch_armv6m_dmb(void);

/*
 * ============================================================================
 * ARMv6-M 低功耗模式函数声明
 * ============================================================================
 */

/**
 * @brief 等待中断 (Wait For Interrupt)
 * @details 处理器进入低功耗模式，等待中断唤醒
 */
void arch_armv6m_wfi(void);

/**
 * @brief 等待事件 (Wait For Event)
 * @details 处理器进入低功耗模式，等待事件唤醒
 */
void arch_armv6m_wfe(void);

/**
 * @brief 发送事件 (Send Event)
 * @details 向所有处理器发送事件
 */
void arch_armv6m_sev(void);

/*
 * ============================================================================
 * ARMv6-M NVIC 中断管理函数声明
 * ============================================================================
 */

/**
 * @brief 使能指定中断
 * @param irq: 中断号 (0-31)
 */
void arch_armv6m_enable_irq(uint8_t irq);

/**
 * @brief 禁用指定中断
 * @param irq: 中断号 (0-31)
 */
void arch_armv6m_disable_irq(uint8_t irq);

/**
 * @brief 设置中断优先级
 * @param irq: 中断号
 * @param priority: 优先级 (0-3, 数值越小优先级越高)
 */
void arch_armv6m_set_priority(uint8_t irq, uint8_t priority);

/**
 * @brief 获取中断优先级
 * @param irq: 中断号
 * @return 中断优先级
 */
uint8_t arch_armv6m_get_priority(uint8_t irq);

/**
 * @brief 设置中断挂起状态
 * @param irq: 中断号
 */
void arch_armv6m_set_pending(uint8_t irq);

/**
 * @brief 清除中断挂起状态
 * @param irq: 中断号
 */
void arch_armv6m_clear_pending(uint8_t irq);

/*
 * ============================================================================
 * ARMv6-M 系统控制函数声明
 * ============================================================================
 */

/**
 * @brief 触发系统复位
 */
void arch_armv6m_system_reset(void);

/**
 * @brief 获取 CPU ID
 * @return CPU ID 寄存器值
 */
uint32_t arch_armv6m_get_cpuid(void);

/**
 * @brief 设置向量表基地址
 * @param base: 向量表基地址
 */
void arch_armv6m_set_vector_table(uint32_t base);

/*
 * ============================================================================
 * ARMv6-M 初始化和上下文切换函数声明
 * ============================================================================
 */

/**
 * @brief ARMv6-M 架构初始化
 */
void arch_armv6m_init(void);

/**
 * @brief ARMv6-M 向量表设置
 */
void arch_armv6m_setup_vector_table(void);

/**
 * @brief 初始化用户任务上下文
 * @param context: 任务上下文指针
 * @param entry_point: 任务入口地址
 * @param arg: 传递给任务的参数
 */
void arch_armv6m_init_user_context(ArmV6mTaskContext *context, uint32_t entry_point, uint32_t arg);

/**
 * @brief 上下文切换
 * @param from: 源上下文
 * @param to: 目标上下文
 * @return 切换后的地址
 */
void* arch_armv6m_switch_context(void *from, void *to);

/**
 * @brief 启动第一个任务
 * @param context: 任务上下文
 * @return 不返回
 */
void* arch_armv6m_start_first_task(void *context);

/**
 * @brief 跳转到内核
 * @param vector_table_addr: 向量表地址
 * @return 不返回
 */
void* arch_armv6m_jump_to_kernel(uint32_t vector_table_addr);

/*
 * ============================================================================
 * ARMv6-M NVIC 扩展函数声明
 * ============================================================================
 */

/**
 * @brief 获取指定中断的使能状态
 * @param irq: 中断号
 * @return 1=使能, 0=禁用
 */
uint32_t arch_armv6m_get_enable_irq(uint8_t irq);

/**
 * @brief 获取中断待处理状态
 * @param irq: 中断号
 * @return 1=挂起, 0=未挂起
 */
uint32_t arch_armv6m_get_pending_irq(uint8_t irq);

/**
 * @brief 获取当前正在执行的中断
 * @return 正在执行的中断号
 */
uint32_t arch_armv6m_get_active_irq(void);

/**
 * @brief 获取优先级分组
 * @return 优先级分组值
 */
uint32_t arch_armv6m_get_priority_grouping(void);

/**
 * @brief 设置优先级分组
 * @param priority_group: 优先级分组值
 */
void arch_armv6m_set_priority_grouping(uint32_t priority_group);

/**
 * @brief 编码优先级
 * @param priority_group: 优先级分组
 * @param preempt_priority: 抢占优先级
 * @param sub_priority: 子优先级
 * @return 编码后的优先级值
 */
uint32_t arch_armv6m_encode_priority(uint32_t priority_group, uint32_t preempt_priority, uint32_t sub_priority);

/**
 * @brief 解码优先级
 * @param priority: 编码的优先级
 * @param priority_group: 优先级分组
 * @param preempt_priority: 抢占优先级输出
 * @param sub_priority: 子优先级输出
 */
void arch_armv6m_decode_priority(uint32_t priority, uint32_t priority_group, uint32_t *preempt_priority, uint32_t *sub_priority);

/**
 * @brief 设置中断向量
 * @param irq: 中断号
 * @param vector: 中断处理函数地址
 */
void arch_armv6m_set_vector(uint8_t irq, uint32_t vector);

/**
 * @brief 获取中断向量
 * @param irq: 中断号
 * @return 中断处理函数地址
 */
uint32_t arch_armv6m_get_vector(uint8_t irq);

/*
 * ============================================================================
 * ARMv6-M SysTick 函数声明
 * ============================================================================
 */

/**
 * @brief SysTick 配置
 * @param ticks: 加载值
 * @return 0=成功, 1=失败
 *
 * 配置 SysTick 定时器并使能中断
 */
uint32_t arch_armv6m_systick_config(uint32_t ticks);

/**
 * @brief 获取 SysTick 当前值
 * @return 当前计数值
 */
uint32_t arch_armv6m_systick_get_value(void);

/**
 * @brief 设置 SysTick 加载值
 * @param value: 加载值
 */
void arch_armv6m_systick_set_reload(uint32_t value);

/**
 * @brief 获取 SysTick 加载值
 * @return 加载值
 */
uint32_t arch_armv6m_systick_get_reload(void);

/**
 * @brief 使能 SysTick 中断
 */
void arch_armv6m_systick_enable_irq(void);

/**
 * @brief 禁用 SysTick 中断
 */
void arch_armv6m_systick_disable_irq(void);

/**
 * @brief 使能 SysTick 定时器
 */
void arch_armv6m_systick_enable(void);

/**
 * @brief 禁用 SysTick 定时器
 */
void arch_armv6m_systick_disable(void);

/**
 * @brief 获取 SysTick 校准值
 * @return 校准值
 */
uint32_t arch_armv6m_systick_get_calib(void);

/*
 * ============================================================================
 * ARMv6-M ITM (Instrumentation Trace Macrocell) 函数声明
 * ============================================================================
 */

/**
 * @brief ITM 发送字符
 * @param ch: 要发送的字符
 * @return 发送的字符
 */
uint32_t arch_armv6m_itm_send_char(uint32_t ch);

/**
 * @brief ITM 接收字符
 * @return 接收的字符,如果没有数据返回 -1
 */
int32_t arch_armv6m_itm_receive_char(void);

/**
 * @brief ITM 检查是否有字符等待读取
 * @return 1=有数据, 0=无数据
 */
int32_t arch_armv6m_itm_check_char(void);

/**
 * @brief ITM 使能
 * @param enable: 1=使能, 0=禁用
 */
void arch_armv6m_itm_enable(uint32_t enable);

/*
 * ============================================================================
 * ARMv6-M 外设寄存器结构体定义
 * ============================================================================
 */

typedef struct {
    volatile uint32_t ISER[1U];
    volatile uint32_t RESERVED0[31U];
    volatile uint32_t ICER[1U];
    volatile uint32_t RESERVED1[31U];
    volatile uint32_t ISPR[1U];
    volatile uint32_t RESERVED2[31U];
    volatile uint32_t ICPR[1U];
    volatile uint32_t RESERVED3[31U];
    volatile uint32_t IP[8U];
} NVIC_Type;

typedef struct {
    volatile uint32_t CPUID;
    volatile uint32_t ICSR;
    volatile uint32_t RESERVED0;
    volatile uint32_t AIRCR;
    volatile uint32_t SCR;
    volatile uint32_t CCR;
    volatile uint32_t RESERVED1;
    volatile uint32_t SHP[2U];
    volatile uint32_t SHCSR;
} SCB_Type;

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VAL;
    volatile uint32_t CALIB;
} SysTick_Type;

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t RNR;
    volatile uint32_t RBAR;
    volatile uint32_t RLAR;
    volatile uint32_t RESERVED0[3U];
    volatile uint32_t MAIR0;
    volatile uint32_t MAIR1;
} MPU_Type;

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t PRESERVE;
    volatile uint32_t TPR;
    volatile uint32_t RESERVED0;
    volatile uint32_t TER[32U];
} ITM_Type;

#define NVIC_BASE_ADDR         0xE000E100UL
#define NVIC                    ((NVIC_Type *) NVIC_BASE_ADDR)

#define SCB_BASE_ADDR          0xE000ED00UL
#define SCB                     ((SCB_Type *) SCB_BASE_ADDR)
#define SCB_VTOR               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x08))
#define SCB_AIRCR              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x0C))

#define SYSTICK_BASE_ADDR      0xE000E010UL
#define SysTick                ((SysTick_Type *) SYSTICK_BASE_ADDR)

#define MPU_BASE_ADDR          0xE000ED90UL
#define MPU                    ((MPU_Type *) MPU_BASE_ADDR)
#define MPU_CTRL               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x04))
#define MPU_CTRL_ENABLE_Msk    (1UL << 0)
#define MPU_CTRL_PRIVDEFENA_Msk (1UL << 2)

#define ITM_BASE_ADDR          0xE0000000UL
#define ITM                    ((ITM_Type *) ITM_BASE_ADDR)
#define ITM_TCR_ITMENA_Msk     (1UL << 0)

#define SAU_BASE_ADDR          0xE000EDD0UL

#define PMU_BASE_ADDR          0xE0003000UL

#ifdef __cplusplus
}
#endif

#endif
