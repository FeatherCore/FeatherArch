/*
 * FeatherCore Architecture - ARMv7-A (Cortex-A5/A7/A8/A9/A15) Support
 *
 * ============================================================================
 * 文件: armv7a.h
 * 描述: ARMv7-A 架构特定定义和函数声明
 *
 * ARMv7-A 架构概述:
 *   ARMv7-A 是应用处理器架构，广泛应用于智能手机、平板电脑等领域。
 *   支持虚拟内存管理、NEON SIMD 引擎和 VFPv3/VFPv4 浮点单元。
 *
 * 支持的处理器:
 *   - Cortex-A5: 低功耗应用处理器
 *   - Cortex-A7: 高效应用处理器 (大小核系统中的小核)
 *   - Cortex-A8: 单核高性能处理器
 *   - Cortex-A9: 多核高性能处理器
 *   - Cortex-A15: 高性能超标量处理器
 *
 * 主要特性:
 *   - 8-15 级流水线
 *   - 虚拟内存管理系统 (MMU)
 *   - TrustZone 安全扩展
 *   - NEON SIMD 引擎
 *   - VFPv3/VFPv4 浮点单元
 *   - 1级/2级缓存 (ICache/DCache)
 *   - 分支预测单元 (BTB, BHT, RAS)
 *   - GIC 中断控制器接口
 *
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 FeatherCore Team. All rights reserved.
 */

#ifndef FEATHERCORE_ARCH_ARM_V7A_H
#define FEATHERCORE_ARCH_ARM_V7A_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * ARMv7-A 配置宏定义
 * ============================================================================
 */

#define FEATHERCORE_ARCH_ARM_V7A

/*
 * ============================================================================
 * ARMv7-A 处理器模式枚举
 * ============================================================================
 *
 * ARMv7-A 有多种处理器模式:
 *   - USR (User): 用户模式
 *   - FIQ: 快速中断模式
 *   - IRQ: 中断模式
 *   - SVC (Supervisor): 超级用户模式
 *   - ABT (Abort): 数据/指令异常模式
 *   - UND (Undefined): 未定义指令模式
 *   - SYS (System): 系统模式
 */

typedef enum {
    ARM_V7A_MODE_USR = 0x10,
    ARM_V7A_MODE_FIQ = 0x11,
    ARM_V7A_MODE_IRQ = 0x12,
    ARM_V7A_MODE_SVC = 0x13,
    ARM_V7A_MODE_ABT = 0x17,
    ARM_V7A_MODE_UND = 0x1B,
    ARM_V7A_MODE_SYS = 0x1F,
} ArmV7aMode;

/*
 * ============================================================================
 * ARMv7-A 任务上下文结构体
 * ============================================================================
 *
 * ARMv7-A 任务上下文需要保存所有银行式寄存器。
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
    uint32_t sp_usr;
    uint32_t lr_usr;
    uint32_t sp;
    uint32_t lr;
    uint32_t pc;
    uint32_t cpsr;
    uint32_t spsr_fiq;
    uint32_t r8_fiq;
    uint32_t r9_fiq;
    uint32_t r10_fiq;
    uint32_t r11_fiq;
    uint32_t r12_fiq;
    uint32_t sp_fiq;
    uint32_t lr_fiq;
    uint32_t spsr_irq;
    uint32_t sp_irq;
    uint32_t lr_irq;
    uint32_t spsr_svc;
    uint32_t sp_svc;
    uint32_t lr_svc;
} ArmV7aTaskContext;

/*
 * ============================================================================
 * ARMv7-A 核心寄存器访问函数声明
 * ============================================================================
 */

/**
 * @brief 获取 CPSR (Current Program Status Register)
 * @return CPSR 当前值
 */
uint32_t arch_armv7a_get_cpsr(void);

/**
 * @brief 设置 CPSR
 * @param cpsr: CPSR 新值
 */
void arch_armv7a_set_cpsr(uint32_t cpsr);

/**
 * @brief 切换处理器模式
 * @param mode: 目标模式
 */
void arch_armv7a_set_mode(ArmV7aMode mode);

/**
 * @brief 获取当前处理器模式
 * @return 当前模式
 */
ArmV7aMode arch_armv7a_get_mode(void);

/**
 * @brief 获取当前特权级别
 * @return 0=用户模式, 1=特权模式
 */
uint32_t arch_armv7a_get_privilege_level(void);

/*
 * ============================================================================
 * ARMv7-A 中断管理函数声明
 * ============================================================================
 */

/**
 * @brief 使能 IRQ 中断
 */
void arch_armv7a_enable_irq(void);

/**
 * @brief 禁用 IRQ 中断
 */
void arch_armv7a_disable_irq(void);

/**
 * @brief 使能 FIQ 中断
 */
void arch_armv7a_enable_fiq(void);

/**
 * @brief 禁用 FIQ 中断
 */
void arch_armv7a_disable_fiq(void);

/*
 * ============================================================================
 * ARMv7-A 内存屏障函数声明
 * ============================================================================
 */

/**
 * @brief 数据同步屏障 (Data Synchronization Barrier)
 */
void arch_armv7a_dsb(void);

/**
 * @brief 指令同步屏障 (Instruction Synchronization Barrier)
 */
void arch_armv7a_isb(void);

/**
 * @brief 数据内存屏障 (Data Memory Barrier)
 */
void arch_armv7a_dmb(void);

/*
 * ============================================================================
 * ARMv7-A 低功耗模式函数声明
 * ============================================================================
 */

/**
 * @brief 等待中断 (Wait For Interrupt)
 */
void arch_armv7a_wfi(void);

/**
 * @brief 等待事件 (Wait For Event)
 */
void arch_armv7a_wfe(void);

/**
 * @brief 发送事件 (Send Event)
 */
void arch_armv7a_sev(void);

/*
 * ============================================================================
 * ARMv7-A 缓存管理函数声明
 * ============================================================================
 */

/**
 * @brief 使能指令缓存 (I-Cache)
 */
void arch_armv7a_enable_icache(void);

/**
 * @brief 禁用指令缓存
 */
void arch_armv7a_disable_icache(void);

/**
 * @brief 使能数据缓存 (D-Cache)
 */
void arch_armv7a_enable_dcache(void);

/**
 * @brief 禁用数据缓存
 */
void arch_armv7a_disable_dcache(void);

/**
 * @brief 无效化指令缓存
 */
void arch_armv7a_invalidate_icache_all(void);

/**
 * @brief 无效化数据缓存
 */
void arch_armv7a_invalidate_dcache_all(void);

/**
 * @brief 清理并无效化数据缓存
 */
void arch_armv7a_clean_invalidate_dcache_all(void);

/**
 * @brief 无效化整个 TLB
 */
void arch_armv7a_invalidate_tlb_all(void);

/*
 * ============================================================================
 * ARMv7-A MMU 函数声明
 * ============================================================================
 */

/**
 * @brief 获取 SCTLR (System Control Register)
 * @return SCTLR 值
 */
uint32_t arch_armv7a_get_sctlr(void);

/**
 * @brief 设置 SCTLR (System Control Register)
 * @param val: SCTLR 值
 */
void arch_armv7a_set_sctlr(uint32_t val);

/**
 * @brief 使能 MMU
 */
void arch_armv7a_enable_mmu(void);

/**
 * @brief 禁用 MMU
 */
void arch_armv7a_disable_mmu(void);

/**
 * @brief 获取 TTBR0 (Translation Table Base Register 0)
 * @return TTBR0 值
 */
uint32_t arch_armv7a_get_ttbr0(void);

/**
 * @brief 设置 TTBR0 (Translation Table Base Register 0)
 * @param ttbr0: 页表基地址
 */
void arch_armv7a_set_ttbr0(uint32_t ttbr0);

/**
 * @brief 获取 DACR (Domain Access Control Register)
 * @return DACR 值
 */
uint32_t arch_armv7a_get_dacr(void);

/**
 * @brief 设置 DACR (Domain Access Control Register)
 * @param dacr: 域访问控制值
 */
void arch_armv7a_set_dacr(uint32_t dacr);

/**
 * @brief 获取 VBAR (Vector Base Address Register)
 * @return VBAR 值
 */
uint32_t arch_armv7a_get_vbar(void);

/**
 * @brief 设置 VBAR (Vector Base Address Register)
 * @param vbar: 向量表基地址
 */
void arch_armv7a_set_vbar(uint32_t vbar);

/**
 * @brief 获取当前处理器模式
 * @return 模式值
 */
uint32_t arch_armv7a_get_cpsr(void);

/**
 * @brief 设置 CPSR (Current Program Status Register)
 * @param cpsr: CPSR 值
 */
void arch_armv7a_set_cpsr(uint32_t cpsr);

/**
 * @brief 无效化整个指令缓存
 */
void arch_armv7a_invalidate_icache_all(void);

/**
 * @brief 无效化整个数据缓存
 */
void arch_armv7a_invalidate_dcache_all(void);

/**
 * @brief 清理并无效化整个数据缓存
 */
void arch_armv7a_clean_invalidate_dcache_all(void);

/**
 * @brief 无效化 TLB
 */
void arch_armv7a_invalidate_tlb_all(void);

/**
 * @brief 设置 TTBR1 (Translation Table Base Register 1)
 * @param ttbr1: 页表基地址
 */
void arch_armv7a_set_ttbr1(uint32_t ttbr1);

/**
 * @brief 获取 TTBR1
 * @return TTBR1 值
 */
uint32_t arch_armv7a_get_ttbr1(void);

/**
 * @brief 设置 TTBCR (Translation Table Base Control Register)
 * @param ttbcr: TTBCR 值
 */
void arch_armv7a_set_ttbcr(uint32_t ttbcr);

/**
 * @brief 获取 TTBCR
 * @return TTBCR 值
 */
uint32_t arch_armv7a_get_ttbcr(void);

/**
 * @brief 获取 DFSR (Data Fault Status Register)
 * @return DFSR 值
 */
uint32_t arch_armv7a_get_dfsr(void);

/**
 * @brief 获取 IFSR (Instruction Fault Status Register)
 * @return IFSR 值
 */
uint32_t arch_armv7a_get_ifsr(void);

/**
 * @brief 获取 DFAR (Data Fault Address Register)
 * @return DFAR 值
 */
uint32_t arch_armv7a_get_dfar(void);

/**
 * @brief 获取 IFAR (Instruction Fault Address Register)
 * @return IFAR 值
 */
uint32_t arch_armv7a_get_ifar(void);

/*
 * ============================================================================
 * ARMv7-A FPU 函数声明
 * ============================================================================
 */

/**
 * @brief 使能 FPU/NEON
 */
void arch_armv7a_enable_fpu(void);

/**
 * @brief 禁用 FPU/NEON
 */
void arch_armv7a_disable_fpu(void);

/*
 * ============================================================================
 * ARMv7-A 初始化和上下文切换函数声明
 * ============================================================================
 */

/**
 * @brief ARMv7-A 架构初始化
 */
void arch_armv7a_init(void);

/**
 * @brief ARMv7-A 向量表设置
 */
void arch_armv7a_setup_vector_table(void);

/**
 * @brief 初始化用户任务上下文
 * @param context: 任务上下文
 * @param entry_point: 入口地址
 * @param arg: 参数
 */
void arch_armv7a_init_user_context(ArmV7aTaskContext *context, uint32_t entry_point, uint32_t arg);

/**
 * @brief 上下文切换
 * @param from: 源上下文
 * @param to: 目标上下文
 * @return 切换后的地址
 */
void* arch_armv7a_switch_context(void *from, void *to);

/**
 * @brief 启动第一个任务
 * @param context: 任务上下文
 * @return 不返回
 */
void* arch_armv7a_start_first_task(void *context);

/**
 * @brief 跳转到内核
 * @param vector_table_addr: 向量表地址
 * @return 不返回
 */
void* arch_armv7a_jump_to_kernel(uint32_t vector_table_addr);

/*
 * ============================================================================
 * ARMv7-A GIC (Generic Interrupt Controller) 函数声明
 * ============================================================================
 * GIC 是 ARM Cortex-A 系列的标准中断控制器
 */

/**
 * @brief GIC 初始化
 */
void arch_armv7a_gic_init(void);

/**
 * @brief 使能中断
 * @param irq: 中断号
 */
void arch_armv7a_gic_enable_irq(uint32_t irq);

/**
 * @brief 禁用中断
 * @param irq: 中断号
 */
void arch_armv7a_gic_disable_irq(uint32_t irq);

/**
 * @brief 设置中断优先级
 * @param irq: 中断号
 * @param priority: 优先级 (0-255)
 */
void arch_armv7a_gic_set_priority(uint32_t irq, uint32_t priority);

/**
 * @brief 获取中断优先级
 * @param irq: 中断号
 * @return 优先级
 */
uint32_t arch_armv7a_gic_get_priority(uint32_t irq);

/**
 * @brief 设置中断目标 CPU
 * @param irq: 中断号
 * @param cpu_target: CPU 目标掩码
 */
void arch_armv7a_gic_set_target(uint32_t irq, uint32_t cpu_target);

/**
 * @brief 发送软件中断 (SGI)
 * @param irq: SGI 中断号 (0-15)
 * @param cpu_target: 目标 CPU 掩码
 */
void arch_armv7a_gic_send_sgi(uint32_t irq, uint32_t cpu_target);

/**
 * @brief 获取中断待处理状态
 * @param irq: 中断号
 * @return 1=挂起, 0=未挂起
 */
uint32_t arch_armv7a_gic_get_pending(uint32_t irq);

/**
 * @brief 设置中断挂起状态
 * @param irq: 中断号
 */
void arch_armv7a_gic_set_pending(uint32_t irq);

/**
 * @brief 清除中断挂起状态
 * @param irq: 中断号
 */
void arch_armv7a_gic_clear_pending(uint32_t irq);

/**
 * @brief 获取当前正在执行的中断
 * @return 中断号
 */
uint32_t arch_armv7a_gic_get_active_irq(void);

/**
 * @brief GIC 使能
 */
void arch_armv7a_gic_enable(void);

/**
 * @brief GIC 禁用
 */
void arch_armv7a_gic_disable(void);

/*
 * ============================================================================
 * ARMv7-A Generic Timer 函数声明
 * ============================================================================
 * Generic Timer 是 ARM Cortex-A 架构的标准定时器
 */

/**
 * @brief 获取CNTFRQ 寄存器 (计数频率)
 * @return 定时器频率
 */
uint64_t arch_armv7a_get_cntfrq(void);

/**
 * @brief 设置CNTFRQ 寄存器 (计数频率)
 * @param freq: 定时器频率
 */
void arch_armv7a_set_cntfrq(uint64_t freq);

/**
 * @brief 获取 CNTPCT 寄存器 (物理计数器)
 * @return 当前计数器值
 */
uint64_t arch_armv7a_get_cntpct(void);

/**
 * @brief 获取 CNTVCT 寄存器 (虚拟计数器)
 * @return 当前虚拟计数器值
 */
uint64_t arch_armv7a_get_cntvct(void);

/**
 * @brief 获取 CNTP_TVAL 寄存器 (物理定时器值)
 * @return 定时器值
 */
uint32_t arch_armv7a_get_cntp_tval(void);

/**
 * @brief 设置 CNTP_TVAL 寄存器 (物理定时器值)
 * @param value: 定时器值
 */
void arch_armv7a_set_cntp_tval(uint32_t value);

/**
 * @brief 获取 CNTP_CTL 寄存器 (物理定时器控制)
 * @return 控制寄存器值
 */
uint32_t arch_armv7a_get_cntp_ctl(void);

/**
 * @brief 设置 CNTP_CTL 寄存器 (物理定时器控制)
 * @param value: 控制寄存器值
 */
void arch_armv7a_set_cntp_ctl(uint32_t value);

/**
 * @brief 获取 CNTV_TVAL 寄存器 (虚拟定时器值)
 * @return 虚拟定时器值
 */
uint32_t arch_armv7a_get_cntv_tval(void);

/**
 * @brief 设置 CNTV_TVAL 寄存器 (虚拟定时器值)
 * @param value: 虚拟定时器值
 */
void arch_armv7a_set_cntv_tval(uint32_t value);

/**
 * @brief 获取 CNTV_CTL 寄存器 (虚拟定时器控制)
 * @return 控制寄存器值
 */
uint32_t arch_armv7a_get_cntv_ctl(void);

/**
 * @brief 设置 CNTV_CTL 寄存器 (虚拟定时器控制)
 * @param value: 控制寄存器值
 */
void arch_armv7a_set_cntv_ctl(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif
