/*
 * FeatherCore Architecture - ARMv7-M Implementation
 *
 * ============================================================================
 * 文件: armv7m.c
 * 描述: ARMv7-M 架构 (Cortex-M3/M4) 的具体实现
 *
 * ARMv7-M 架构特性:
 *   - 高性能微控制器架构
 *   - Thumb-2 指令集
 *   - NVIC 中断控制器 (最多 256 个中断)
 *   - MPU 内存保护单元
 *   - 可选 FPU (单精度浮点) - Cortex-M4
 *
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 FeatherCore Team. All rights reserved.
 */

#include "armv7m.h"
#include <stdint.h>

/*
 * ============================================================================
 * ARMv7-M 寄存器基地址定义
 * ============================================================================
 */

#define NVIC_BASE_ADDR     0xE000E100UL
#define NVIC_ISER(n)       (*(volatile uint32_t *)(NVIC_BASE_ADDR + (n) * 4))
#define NVIC_ICER(n)       (*(volatile uint32_t *)(NVIC_BASE_ADDR + 0x80 + (n) * 4))
#define NVIC_ISPR(n)       (*(volatile uint32_t *)(NVIC_BASE_ADDR + 0x100 + (n) * 4))
#define NVIC_ICPR(n)       (*(volatile uint32_t *)(NVIC_BASE_ADDR + 0x180 + (n) * 4))
#define NVIC_IPR_BASE      0xE000E400UL
#define NVIC_IPR(n)        (*(volatile uint8_t *)(NVIC_IPR_BASE + (n)))

#define SCB_BASE_ADDR      0xE000ED00UL
#define SCB_AIRCR          (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x0C))

#define MPU_BASE_ADDR      0xE000ED90UL
#define MPU_CTRL           (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x04))
#define MPU_RNR            (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x00))
#define MPU_RBAR           (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x08))
#define MPU_RASR           (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x0C))
#define MPU_TYPE           (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x00))

#define SCB_VTOR           (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x08))
#define SCB_ICSR           (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x04))
#define SCB_CPUID          (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x00))
#define SCB_SCR            (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x10))
#define SCB_CCR            (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x14))

#define SYSTICK_BASE_ADDR  0xE000E010UL
#define SYSTICK_CTRL       (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x00))
#define SYSTICK_LOAD       (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x04))
#define SYSTICK_VAL        (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x08))
#define SYSTICK_CALIB      (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x0C))

#define ITM_BASE_ADDR      0xE0000000UL
#define ITM_CTRL           (*(volatile uint32_t *)(ITM_BASE_ADDR + 0x00))
#define ITM_TPR            (*(volatile uint32_t *)(ITM_BASE_ADDR + 0x20))
#define ITM_TER           (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xE00))
#define ITM_STIM(n)       (*(volatile uint32_t *)(ITM_BASE_ADDR + (n) * 4))

/*
 * ============================================================================
 * ARMv7-M 核心寄存器访问实现
 * ============================================================================
 */

/**
 * @brief 获取 CONTROL 寄存器值
 */
uint32_t arch_armv7m_get_control(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, control" : "=r" (result));
    return result;
}

/**
 * @brief 设置 CONTROL 寄存器值
 */
void arch_armv7m_set_control(uint32_t control) {
    __asm__ volatile ("MSR control, %0" : : "r" (control) : "memory");
}

/**
 * @brief 获取主栈指针 (MSP)
 */
uint32_t arch_armv7m_get_msp(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, msp" : "=r" (result));
    return result;
}

/**
 * @brief 设置主栈指针 (MSP)
 */
void arch_armv7m_set_msp(uint32_t msp) {
    __asm__ volatile ("MSR msp, %0" : : "r" (msp) : "memory");
}

/**
 * @brief 获取进程栈指针 (PSP)
 */
uint32_t arch_armv7m_get_psp(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, psp" : "=r" (result));
    return result;
}

/**
 * @brief 设置进程栈指针 (PSP)
 */
void arch_armv7m_set_psp(uint32_t psp) {
    __asm__ volatile ("MSR psp, %0" : : "r" (psp) : "memory");
}

/**
 * @brief 获取 PRIMASK 寄存器
 */
uint32_t arch_armv7m_get_primask(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, primask" : "=r" (result));
    return result;
}

/**
 * @brief 设置 PRIMASK 寄存器
 */
void arch_armv7m_set_primask(uint32_t primask) {
    __asm__ volatile ("MSR primask, %0" : : "r" (primask) : "memory");
}

/**
 * @brief 获取 BASEPRI 寄存器
 */
uint32_t arch_armv7m_get_basepri(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, basepri" : "=r" (result));
    return result;
}

/**
 * @brief 设置 BASEPRI 寄存器
 */
void arch_armv7m_set_basepri(uint32_t basepri) {
    __asm__ volatile ("MSR basepri, %0" : : "r" (basepri) : "memory");
}

/**
 * @brief 获取 FAULTMASK 寄存器
 */
uint32_t arch_armv7m_get_faultmask(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, faultmask" : "=r" (result));
    return result;
}

/**
 * @brief 设置 FAULTMASK 寄存器
 */
void arch_armv7m_set_faultmask(uint32_t faultmask) {
    __asm__ volatile ("MSR faultmask, %0" : : "r" (faultmask) : "memory");
}

/*
 * ============================================================================
 * 内存屏障实现
 * ============================================================================
 */

/**
 * @brief 数据同步屏障
 */
void arch_armv7m_dsb(void) {
    __asm__ volatile ("dsb sy" : : : "memory");
}

/**
 * @brief 指令同步屏障
 */
void arch_armv7m_isb(void) {
    __asm__ volatile ("isb sy" : : : "memory");
}

/**
 * @brief 数据内存屏障
 */
void arch_armv7m_dmb(void) {
    __asm__ volatile ("dmb sy" : : : "memory");
}

/*
 * ============================================================================
 * 低功耗模式实现
 * ============================================================================
 */

/**
 * @brief 等待中断
 */
void arch_armv7m_wfi(void) {
    __asm__ volatile ("wfi" : : : "memory");
}

/**
 * @brief 等待事件
 */
void arch_armv7m_wfe(void) {
    __asm__ volatile ("wfe" : : : "memory");
}

/**
 * @brief 发送事件
 */
void arch_armv7m_sev(void) {
    __asm__ volatile ("sev" : : : "memory");
}

/*
 * ============================================================================
 * NVIC 中断管理实现
 * ============================================================================
 */

/**
 * @brief 使能指定中断
 * @param irq: 中断号 (0-239)
 */
void arch_armv7m_enable_irq(uint8_t irq) {
    if (irq < 240) {
        uint32_t idx = irq / 32;
        uint32_t bit = irq % 32;
        NVIC_ISER(idx) = (1U << bit);
    }
}

/**
 * @brief 禁用指定中断
 */
void arch_armv7m_disable_irq(uint8_t irq) {
    if (irq < 240) {
        uint32_t idx = irq / 32;
        uint32_t bit = irq % 32;
        NVIC_ICER(idx) = (1U << bit);
    }
}

/**
 * @brief 设置中断优先级
 */
void arch_armv7m_set_priority(uint8_t irq, uint8_t priority) {
    if (irq < 240) {
        NVIC_IPR(irq) = priority;
    }
}

/**
 * @brief 获取中断优先级
 */
uint8_t arch_armv7m_get_priority(uint8_t irq) {
    if (irq < 240) {
        return NVIC_IPR(irq);
    }
    return 0;
}

/**
 * @brief 设置中断挂起状态
 */
void arch_armv7m_set_pending(uint8_t irq) {
    if (irq < 240) {
        uint32_t idx = irq / 32;
        uint32_t bit = irq % 32;
        NVIC_ISPR(idx) = (1U << bit);
    }
}

/**
 * @brief 清除中断挂起状态
 */
void arch_armv7m_clear_pending(uint8_t irq) {
    if (irq < 240) {
        uint32_t idx = irq / 32;
        uint32_t bit = irq % 32;
        NVIC_ICPR(idx) = (1U << bit);
    }
}

/**
 * @brief 设置优先级分组
 */
void arch_armv7m_set_priority_grouping(uint32_t group) {
    uint32_t val = SCB_AIRCR;
    val = (val & ~(0x7UL << 8)) | (0x5FA << 16) | ((group & 0x7) << 8);
    SCB_AIRCR = val;
}

/*
 * ============================================================================
 * 系统控制实现
 * ============================================================================
 */

/**
 * @brief 触发系统复位
 */
void arch_armv7m_system_reset(void) {
    uint32_t val = SCB_AIRCR;
    val = (val & ~(0x7UL << 8)) | (0x5FA << 16) | (1UL << 2);
    SCB_AIRCR = val;
    __asm__ volatile ("dsb");
    for (;;) { __asm__ volatile ("nop"); }
}

/*
 * ============================================================================
 * FPU 实现
 * ============================================================================
 */

/**
 * @brief 使能 FPU
 */
void arch_armv7m_enable_fpu(void) {
    uint32_t cpacr;
    __asm__ volatile ("MRS %0, CPACR" : "=r" (cpacr));
    cpacr |= (0x3UL << 20) | (0x3UL << 22);
    __asm__ volatile ("MSR CPACR, %0" : : "r" (cpacr) : "memory");
    arch_armv7m_dsb();
    arch_armv7m_isb();
}

/**
 * @brief 禁用 FPU
 */
void arch_armv7m_disable_fpu(void) {
    uint32_t cpacr;
    __asm__ volatile ("MRS %0, CPACR" : "=r" (cpacr));
    cpacr &= ~((0x3UL << 20) | (0x3UL << 22));
    __asm__ volatile ("MSR CPACR, %0" : : "r" (cpacr) : "memory");
    arch_armv7m_dsb();
    arch_armv7m_isb();
}

/*
 * ============================================================================
 * MPU 实现
 * ============================================================================
 */

/**
 * @brief 初始化 MPU
 */
void arch_armv7m_mpu_init(void) {
    arch_armv7m_mpu_disable();
}

/**
 * @brief 使能 MPU
 */
void arch_armv7m_mpu_enable(bool default_map) {
    uint32_t ctrl = MPU_CTRL;
    ctrl |= 0x1;
    if (default_map) {
        ctrl |= 0x4;
    }
    MPU_CTRL = ctrl;
    arch_armv7m_dsb();
    arch_armv7m_isb();
}

/**
 * @brief 禁用 MPU
 */
void arch_armv7m_mpu_disable(void) {
    MPU_CTRL &= ~0x1;
    arch_armv7m_dsb();
    arch_armv7m_isb();
}

/**
 * @brief 获取 MPU 类型
 * @return MPU 类型寄存器值
 */
uint32_t arch_armv7m_mpu_get_type(void) {
    return MPU_TYPE;
}

/**
 * @brief 设置 MPU 区域
 * @param rnr: 区域编号
 * @param rbar: 区域基地址寄存器
 * @param rasr: 区域属性和大小寄存器
 *
 * RBAR:
 *   - [31:5]: 基地址
 *   - [4:0]: REGION
 *
 * RASR:
 *   - [31:29]: 保留
 *   - [28]: XN (Execute Never)
 *   - [27:24]: Reserved
 *   - [23:21]: AP (访问权限)
 *   - [20:19,17:18,15:8]: 保留
 *   - [7:1]: SRD (子区域禁用)
 *   - [0]: ENABLE
 */
void arch_armv7m_mpu_set_region(uint32_t rnr, uint32_t rbar, uint32_t rasr) {
    MPU_RNR = rnr;
    MPU_RBAR = rbar;
    MPU_RASR = rasr;
    arch_armv7m_dsb();
}

/**
 * @brief 清除 MPU 区域
 * @param rnr: 区域编号
 */
void arch_armv7m_mpu_clr_region(uint32_t rnr) {
    MPU_RNR = rnr;
    MPU_RASR = 0;
    arch_armv7m_dsb();
}

/**
 * @brief 获取 MPU 区域数量
 * @return 区域数量
 */
uint32_t arch_armv7m_mpu_get_num_regions(void) {
    return (MPU_TYPE >> 8) & 0xFFUL;
}

/*
 * ============================================================================
 * ARMv7-M NVIC 扩展函数实现
 * ============================================================================
 */

/**
 * @brief 获取指定中断的使能状态
 */
uint32_t arch_armv7m_get_enable_irq(uint8_t irq) {
    if (irq < 32) {
        return (NVIC_ISER >> irq) & 0x1U;
    } else if (irq < 64) {
        return (NVIC_ISER1 >> (irq - 32)) & 0x1U;
    }
    return 0;
}

/**
 * @brief 获取中断待处理状态
 */
uint32_t arch_armv7m_get_pending_irq(uint8_t irq) {
    if (irq < 32) {
        return (NVIC_ISPR >> irq) & 0x1U;
    } else if (irq < 64) {
        return (NVIC_ISPR1 >> (irq - 32)) & 0x1U;
    }
    return 0;
}

/**
 * @brief 获取当前正在执行的中断
 */
uint32_t arch_armv7m_get_active_irq(void) {
    return (SCB_ICSR & 0x1FFU) - 16;
}

/**
 * @brief 获取优先级分组
 */
uint32_t arch_armv7m_get_priority_grouping(void) {
    return (SCB_AIRCR >> 8) & 0x7U;
}

/**
 * @brief 设置优先级分组
 */
void arch_armv7m_set_priority_grouping(uint32_t priority_group) {
    uint32_t val = SCB_AIRCR;
    val = (val & ~(0x7UL << 8)) | (0x5FAUL << 16) | ((priority_group & 0x7UL) << 8);
    SCB_AIRCR = val;
}

/**
 * @brief 编码优先级
 */
uint32_t arch_armv7m_encode_priority(uint32_t priority_group, uint32_t preempt_priority, uint32_t sub_priority) {
    uint32_t priority_group_tmp = priority_group & 0x7UL;
    uint32_t PreemptPriorityBits = 7UL - priority_group_tmp;
    uint32_t SubPriorityBits = (priority_group_tmp + 4) < 7UL ? 0UL : (priority_group_tmp - 7UL + 4);
    return ((preempt_priority << SubPriorityBits) | sub_priority);
}

/**
 * @brief 解码优先级
 */
void arch_armv7m_decode_priority(uint32_t priority, uint32_t priority_group, uint32_t *preempt_priority, uint32_t *sub_priority) {
    uint32_t priority_group_tmp = priority_group & 0x7UL;
    uint32_t PreemptPriorityBits = 7UL - priority_group_tmp;
    uint32_t SubPriorityBits = (priority_group_tmp + 4) < 7UL ? 0UL : (priority_group_tmp - 7UL + 4);
    *preempt_priority = priority >> SubPriorityBits;
    *sub_priority = priority & ((1UL << SubPriorityBits) - 1UL);
}

/**
 * @brief 设置中断向量
 */
void arch_armv7m_set_vector(uint8_t irq, uint32_t vector) {
    volatile uint32_t *vector_table = (volatile uint32_t *)SCB_VTOR;
    if (irq < 16) {
        vector_table[irq + 16] = vector;
    }
}

/**
 * @brief 获取中断向量
 */
uint32_t arch_armv7m_get_vector(uint8_t irq) {
    volatile uint32_t *vector_table = (volatile uint32_t *)SCB_VTOR;
    if (irq < 16) {
        return vector_table[irq + 16];
    }
    return 0;
}

/*
 * ============================================================================
 * ARMv7-M SysTick 实现
 * ============================================================================
 */

/**
 * @brief SysTick 配置
 */
uint32_t arch_armv7m_systick_config(uint32_t ticks) {
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
uint32_t arch_armv7m_systick_get_value(void) {
    return SYSTICK_VAL;
}

/**
 * @brief 设置 SysTick 加载值
 */
void arch_armv7m_systick_set_reload(uint32_t value) {
    SYSTICK_LOAD = value;
}

/**
 * @brief 获取 SysTick 加载值
 */
uint32_t arch_armv7m_systick_get_reload(void) {
    return SYSTICK_LOAD;
}

/**
 * @brief 使能 SysTick 中断
 */
void arch_armv7m_systick_enable_irq(void) {
    SYSTICK_CTRL |= 0x02;
}

/**
 * @brief 禁用 SysTick 中断
 */
void arch_armv7m_systick_disable_irq(void) {
    SYSTICK_CTRL &= ~0x02;
}

/**
 * @brief 使能 SysTick 定时器
 */
void arch_armv7m_systick_enable(void) {
    SYSTICK_CTRL |= 0x01;
}

/**
 * @brief 禁用 SysTick 定时器
 */
void arch_armv7m_systick_disable(void) {
    SYSTICK_CTRL &= ~0x01;
}

/**
 * @brief 获取 SysTick 校准值
 */
uint32_t arch_armv7m_systick_get_calib(void) {
    return SYSTICK_CALIB;
}

/*
 * ============================================================================
 * ARMv7-M ITM 实现
 * ============================================================================
 */

#define ITM_RXBUFFER_EMPTY  0x5AA55AA5U

static volatile int32_t ITM_RxBuffer = ITM_RXBUFFER_EMPTY;

/**
 * @brief ITM 发送字符
 */
uint32_t arch_armv7m_itm_send_char(uint32_t ch) {
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
int32_t arch_armv7m_itm_receive_char(void) {
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
int32_t arch_armv7m_itm_check_char(void) {
    if (ITM_RxBuffer == ITM_RXBUFFER_EMPTY) {
        return 0;
    }
    return 1;
}

/**
 * @brief ITM 使能
 */
void arch_armv7m_itm_enable(uint32_t enable) {
    if (enable) {
        ITM_CTRL |= 0x1;
    } else {
        ITM_CTRL &= ~0x1;
    }
}

/*
 * ============================================================================
 * 初始化和上下文切换实现
 * ============================================================================
 */

/**
 * @brief ARMv7-M 架构初始化
 */
void arch_armv7m_init(void) {
    arch_armv7m_dsb();
    arch_armv7m_isb();
    arch_armv7m_enable_fpu();
    arch_armv7m_mpu_init();
    arch_armv7m_dsb();
}

/**
 * @brief ARMv7-M 向量表设置
 */
void arch_armv7m_setup_vector_table(void) {
    extern uint32_t _vector_table_base;
    volatile uint32_t *vtor = (volatile uint32_t *)0xE000ED08;
    *vtor = (uint32_t)&_vector_table_base;
}

/**
 * @brief 初始化用户任务上下文
 */
void arch_armv7m_init_user_context(ArmV7mTaskContext *context, uint32_t entry_point, uint32_t arg) {
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
    context->basepri = 0;
    context->faultmask = 0;
}

/**
 * @brief 上下文切换
 */
void* arch_armv7m_switch_context(void *from, void *to) {
    (void)from;
    (void)to;
    return NULL;
}

/**
 * @brief 启动第一个任务
 */
void* arch_armv7m_start_first_task(void *context) {
    (void)context;
    __builtin_unreachable();
}

/**
 * @brief 跳转到内核
 */
void* arch_armv7m_jump_to_kernel(uint32_t vector_table_addr) {
    (void)vector_table_addr;
    __builtin_unreachable();
}
