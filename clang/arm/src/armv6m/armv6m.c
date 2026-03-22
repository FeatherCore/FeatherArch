/*
 * FeatherCore Architecture - ARMv6-M Implementation
 *
 * ============================================================================
 * 文件: armv6m.c
 * 描述: ARMv6-M 架构 (Cortex-M0/M0+) 的具体实现
 *
 * ARMv6-M 架构特性:
 *   - 最精简的 ARM 架构
 *   - 仅支持 Thumb 指令集
 *   - NVIC 中断控制器 (最多 32 个中断)
 *   - 可选 MPU (仅 Cortex-M0+)
 *
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 FeatherCore Team. All rights reserved.
 */

#include "armv6m.h"
#include <stdint.h>

/*
 * ============================================================================
 * ARMv6-M 寄存器基地址定义
 * ============================================================================
 */

#define NVIC_BASE_ADDR     0xE000E100UL
#define NVIC_ISER          (*(volatile uint32_t *)(NVIC_BASE_ADDR + 0x00))
#define NVIC_ICER          (*(volatile uint32_t *)(NVIC_BASE_ADDR + 0x80))
#define NVIC_ISPR          (*(volatile uint32_t *)(NVIC_BASE_ADDR + 0x100))
#define NVIC_ICPR          (*(volatile uint32_t *)(NVIC_BASE_ADDR + 0x180))
#define NVIC_IPR_BASE      0xE000E400UL
#define NVIC_IPR(n)        (*(volatile uint8_t *)(NVIC_IPR_BASE + (n)))

#define SCB_BASE_ADDR      0xE000ED00UL
#define SCB_VTOR           (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x08))
#define SCB_AIRCR          (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x0C))
#define SCB_ICSR           (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x04))

#define SYSTICK_BASE_ADDR  0xE000E010UL
#define SYSTICK_CTRL       (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x00))
#define SYSTICK_LOAD       (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x04))
#define SYSTICK_VAL        (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x08))
#define SYSTICK_CALIB      (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x0C))

#define ITM_BASE_ADDR      0xE0000000UL
#define ITM_CTRL           (*(volatile uint32_t *)(ITM_BASE_ADDR + 0x00))
#define ITM_TPR            (*(volatile uint32_t *)(ITM_BASE_ADDR + 0x20))
#define ITM_TER           (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xE00))
#define ITM_BASE          (*(volatile uint32_t *)(ITM_BASE_ADDR + 0x0))

#define ITM_STIM_BASE      0xE0000000UL
#define ITM_STIM(n)       (*(volatile uint32_t *)(ITM_STIM_BASE + (n) * 4))

/*
 * ============================================================================
 * ARMv6-M 核心寄存器访问实现
 * ============================================================================
 */

/**
 * @brief 获取 CONTROL 寄存器值
 */
uint32_t arch_armv6m_get_control(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, control" : "=r" (result));
    return result;
}

/**
 * @brief 设置 CONTROL 寄存器值
 */
void arch_armv6m_set_control(uint32_t control) {
    __asm__ volatile ("MSR control, %0" : : "r" (control) : "memory");
}

/**
 * @brief 获取主栈指针 (MSP)
 */
uint32_t arch_armv6m_get_msp(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, msp" : "=r" (result));
    return result;
}

/**
 * @brief 设置主栈指针 (MSP)
 */
void arch_armv6m_set_msp(uint32_t msp) {
    __asm__ volatile ("MSR msp, %0" : : "r" (msp) : "memory");
}

/**
 * @brief 获取进程栈指针 (PSP)
 */
uint32_t arch_armv6m_get_psp(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, psp" : "=r" (result));
    return result;
}

/**
 * @brief 设置进程栈指针 (PSP)
 */
void arch_armv6m_set_psp(uint32_t psp) {
    __asm__ volatile ("MSR psp, %0" : : "r" (psp) : "memory");
}

/**
 * @brief 获取 PRIMASK 寄存器
 */
uint32_t arch_armv6m_get_primask(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, primask" : "=r" (result));
    return result;
}

/**
 * @brief 设置 PRIMASK 寄存器
 */
void arch_armv6m_set_primask(uint32_t primask) {
    __asm__ volatile ("MSR primask, %0" : : "r" (primask) : "memory");
}

/*
 * ============================================================================
 * 内存屏障实现
 * ============================================================================
 */

/**
 * @brief 数据同步屏障 (Data Synchronization Barrier)
 * @details 确保所有在 DSB 之前的内存访问完成后，才执行后续指令
 */
void arch_armv6m_dsb(void) {
    __asm__ volatile ("dsb sy" : : : "memory");
}

/**
 * @brief 指令同步屏障 (Instruction Synchronization Barrier)
 * @details 刷新流水线，确保后续指令从内存重新获取
 */
void arch_armv6m_isb(void) {
    __asm__ volatile ("isb sy" : : : "memory");
}

/**
 * @brief 数据内存屏障 (Data Memory Barrier)
 * @details 确保所有内存访问按程序顺序完成
 */
void arch_armv6m_dmb(void) {
    __asm__ volatile ("dmb sy" : : : "memory");
}

/*
 * ============================================================================
 * 低功耗模式实现
 * ============================================================================
 */

/**
 * @brief 等待中断 (Wait For Interrupt)
 * @details 处理器进入低功耗模式，等待中断唤醒
 */
void arch_armv6m_wfi(void) {
    __asm__ volatile ("wfi" : : : "memory");
}

/**
 * @brief 等待事件 (Wait For Event)
 * @details 处理器进入低功耗模式，等待事件唤醒
 */
void arch_armv6m_wfe(void) {
    __asm__ volatile ("wfe" : : : "memory");
}

/**
 * @brief 发送事件 (Send Event)
 * @details 向所有处理器发送事件
 */
void arch_armv6m_sev(void) {
    __asm__ volatile ("sev" : : : "memory");
}

/*
 * ============================================================================
 * NVIC 中断管理实现
 * ============================================================================
 */

/**
 * @brief 使能指定中断
 * @param irq: 中断号 (0-31)
 */
void arch_armv6m_enable_irq(uint8_t irq) {
    if (irq < 32) {
        NVIC_ISER = (1U << irq);
    }
}

/**
 * @brief 禁用指定中断
 * @param irq: 中断号 (0-31)
 */
void arch_armv6m_disable_irq(uint8_t irq) {
    if (irq < 32) {
        NVIC_ICER = (1U << irq);
    }
}

/**
 * @brief 设置中断优先级
 * @param irq: 中断号
 * @param priority: 优先级 (0-3)
 */
void arch_armv6m_set_priority(uint8_t irq, uint8_t priority) {
    if (irq < 32) {
        NVIC_IPR(irq) = priority & 0x03;
    }
}

/**
 * @brief 获取中断优先级
 */
uint8_t arch_armv6m_get_priority(uint8_t irq) {
    if (irq < 32) {
        return NVIC_IPR(irq);
    }
    return 0;
}

/**
 * @brief 设置中断挂起状态
 */
void arch_armv6m_set_pending(uint8_t irq) {
    if (irq < 32) {
        NVIC_ISPR = (1U << irq);
    }
}

/**
 * @brief 清除中断挂起状态
 */
void arch_armv6m_clear_pending(uint8_t irq) {
    if (irq < 32) {
        NVIC_ICPR = (1U << irq);
    }
}

/*
 * ============================================================================
 * NVIC 扩展函数实现
 * ============================================================================
 */

/**
 * @brief 获取指定中断的使能状态
 */
uint32_t arch_armv6m_get_enable_irq(uint8_t irq) {
    if (irq < 32) {
        return (NVIC_ISER >> irq) & 0x1U;
    }
    return 0;
}

/**
 * @brief 获取中断待处理状态
 */
uint32_t arch_armv6m_get_pending_irq(uint8_t irq) {
    if (irq < 32) {
        return (NVIC_ISPR >> irq) & 0x1U;
    }
    return 0;
}

/**
 * @brief 获取当前正在执行的中断
 */
uint32_t arch_armv6m_get_active_irq(void) {
    return (SCB_ICSR & 0x1FFU) - 16;
}

/**
 * @brief 获取优先级分组
 */
uint32_t arch_armv6m_get_priority_grouping(void) {
    return (SCB_AIRCR >> 8) & 0x7U;
}

/**
 * @brief 设置优先级分组
 */
void arch_armv6m_set_priority_grouping(uint32_t priority_group) {
    uint32_t val = SCB_AIRCR;
    val = (val & ~(0x7UL << 8)) | (0x5FAUL << 16) | ((priority_group & 0x7UL) << 8);
    SCB_AIRCR = val;
}

/**
 * @brief 编码优先级
 */
uint32_t arch_armv6m_encode_priority(uint32_t priority_group, uint32_t preempt_priority, uint32_t sub_priority) {
    uint32_t priority_group_tmp = priority_group & 0x7UL;
    uint32_t PreemptPriorityBits = 7UL - priority_group_tmp;
    uint32_t SubPriorityBits = (priority_group_tmp + 4) < 7UL ? 0UL : (priority_group_tmp - 7UL + 4);
    return ((preempt_priority << SubPriorityBits) | sub_priority);
}

/**
 * @brief 解码优先级
 */
void arch_armv6m_decode_priority(uint32_t priority, uint32_t priority_group, uint32_t *preempt_priority, uint32_t *sub_priority) {
    uint32_t priority_group_tmp = priority_group & 0x7UL;
    uint32_t PreemptPriorityBits = 7UL - priority_group_tmp;
    uint32_t SubPriorityBits = (priority_group_tmp + 4) < 7UL ? 0UL : (priority_group_tmp - 7UL + 4);
    *preempt_priority = priority >> SubPriorityBits;
    *sub_priority = priority & ((1UL << SubPriorityBits) - 1UL);
}

/**
 * @brief 设置中断向量
 */
void arch_armv6m_set_vector(uint8_t irq, uint32_t vector) {
    volatile uint32_t *vector_table = (volatile uint32_t *)SCB_VTOR;
    if (irq < 16) {
        vector_table[irq + 16] = vector;
    }
}

/**
 * @brief 获取中断向量
 */
uint32_t arch_armv6m_get_vector(uint8_t irq) {
    volatile uint32_t *vector_table = (volatile uint32_t *)SCB_VTOR;
    if (irq < 16) {
        return vector_table[irq + 16];
    }
    return 0;
}

/*
 * ============================================================================
 * SysTick 实现
 * ============================================================================
 */

/**
 * @brief SysTick 配置
 */
uint32_t arch_armv6m_systick_config(uint32_t ticks) {
    if (ticks == 0) {
        return 1;
    }
    SYSTICK_LOAD = ticks - 1;
    SYSTICK_VAL = 0;
    SYSTICK_CTRL = 0x07;
    return 0;
}

/**
 * @brief 获取 SysTick 当前值
 */
uint32_t arch_armv6m_systick_get_value(void) {
    return SYSTICK_VAL;
}

/**
 * @brief 设置 SysTick 加载值
 */
void arch_armv6m_systick_set_reload(uint32_t value) {
    SYSTICK_LOAD = value;
}

/**
 * @brief 获取 SysTick 加载值
 */
uint32_t arch_armv6m_systick_get_reload(void) {
    return SYSTICK_LOAD;
}

/**
 * @brief 使能 SysTick 中断
 */
void arch_armv6m_systick_enable_irq(void) {
    SYSTICK_CTRL |= 0x02;
}

/**
 * @brief 禁用 SysTick 中断
 */
void arch_armv6m_systick_disable_irq(void) {
    SYSTICK_CTRL &= ~0x02;
}

/**
 * @brief 使能 SysTick 定时器
 */
void arch_armv6m_systick_enable(void) {
    SYSTICK_CTRL |= 0x01;
}

/**
 * @brief 禁用 SysTick 定时器
 */
void arch_armv6m_systick_disable(void) {
    SYSTICK_CTRL &= ~0x01;
}

/**
 * @brief 获取 SysTick 校准值
 */
uint32_t arch_armv6m_systick_get_calib(void) {
    return SYSTICK_CALIB;
}

/*
 * ============================================================================
 * ITM (Instrumentation Trace Macrocell) 实现
 * ============================================================================
 */

#define ITM_RXBUFFER_EMPTY  0x5AA55AA5U

static volatile int32_t ITM_RxBuffer = ITM_RXBUFFER_EMPTY;

/**
 * @brief ITM 发送字符
 */
uint32_t arch_armv6m_itm_send_char(uint32_t ch) {
    if ((ITM_CTRL & 0x1) != 0) {
        if (ITM_STIM(0) == 1) {
            ITM_STIM(0) = ch;
            return ch;
        }
    }
    return 0;
}

/**
 * @brief ITM 接收字符
 */
int32_t arch_armv6m_itm_receive_char(void) {
    if (ITM_RxBuffer != ITM_RXBUFFER_EMPTY) {
        int32_t ch = ITM_RxBuffer;
        ITM_RxBuffer = ITM_RXBUFFER_EMPTY;
        return ch;
    }
    return -1;
}

/**
 * @brief ITM 检查是否有字符等待读取
 */
int32_t arch_armv6m_itm_check_char(void) {
    if (ITM_RxBuffer == ITM_RXBUFFER_EMPTY) {
        return 0;
    }
    return 1;
}

/**
 * @brief ITM 使能
 */
void arch_armv6m_itm_enable(uint32_t enable) {
    if (enable) {
        ITM_CTRL |= 0x1;
    } else {
        ITM_CTRL &= ~0x1;
    }
}

/*
 * ============================================================================
 * 系统控制实现
 * ============================================================================
 */

/**
 * @brief 触发系统复位
 * @details 通过 AIRCR 寄存器触发系统复位
 */
void arch_armv6m_system_reset(void) {
    uint32_t val = SCB_AIRCR;
    val = (val & ~(0x7UL << 8)) | (0x5FA << 16) | (1UL << 2);
    SCB_AIRCR = val;
    __asm__ volatile ("dsb");
    for (;;) { __asm__ volatile ("nop"); }
}

/**
 * @brief 获取 CPU ID
 */
uint32_t arch_armv6m_get_cpuid(void) {
    return SCB_VTOR;
}

/**
 * @brief 设置向量表基地址
 */
void arch_armv6m_set_vector_table(uint32_t base) {
    SCB_VTOR = base;
}

/*
 * ============================================================================
 * 初始化和上下文切换实现
 * ============================================================================
 */

/**
 * @brief ARMv6-M 架构初始化
 */
void arch_armv6m_init(void) {
    arch_armv6m_dsb();
    arch_armv6m_isb();
    arch_armv6m_dsb();
}

/**
 * @brief ARMv6-M 向量表设置
 */
void arch_armv6m_setup_vector_table(void) {
    extern uint32_t _vector_table_base;
    SCB_VTOR = (uint32_t)&_vector_table_base;
}

/**
 * @brief 初始化用户任务上下文
 * @param context: 任务上下文指针
 * @param entry_point: 任务入口地址
 * @param arg: 传递给任务的参数
 */
void arch_armv6m_init_user_context(ArmV6mTaskContext *context, uint32_t entry_point, uint32_t arg) {
    if (context == NULL) {
        return;
    }
    context->r0 = arg;
    context->r1 = 0;
    context->r2 = 0;
    context->r3 = 0;
    context->r4 = 0;
    context->r5 = 0;
    context->r6 = 0;
    context->r7 = 0;
    context->r8 = 0;
    context->r9 = 0;
    context->r10 = 0;
    context->r11 = 0;
    context->r12 = 0;
    context->pc = entry_point;
    context->xpsr = 0x01000000UL;
    context->lr = 0xFFFFFFFFUL;
    context->control = 0;
    context->primask = 0;
}

/**
 * @brief 上下文切换
 */
void* arch_armv6m_switch_context(void *from, void *to) {
    (void)from;
    (void)to;
    return NULL;
}

/**
 * @brief 启动第一个任务
 */
void* arch_armv6m_start_first_task(void *context) {
    (void)context;
    __builtin_unreachable();
}

/**
 * @brief 跳转到内核
 */
void* arch_armv6m_jump_to_kernel(uint32_t vector_table_addr) {
    (void)vector_table_addr;
    __builtin_unreachable();
}
