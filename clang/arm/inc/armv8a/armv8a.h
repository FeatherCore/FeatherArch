/*
 * FeatherCore Architecture - ARMv8-A (Cortex-A53/A72/A78) Support
 *
 * ============================================================================
 * 文件: armv8a.h
 * 描述: ARMv8-A 架构特定定义和函数声明
 *
 * ARMv8-A 架构概述:
 *   ARMv8-A 是 64 位应用处理器架构，是 ARM 首款支持 64 位执行的架构。
 *   同时支持 32 位 (AArch32) 和 64 位 (AArch64) 执行状态。
 *
 * 支持的处理器:
 *   - Cortex-A53: 高能效 big.LITTLE 小核
 *   - Cortex-A72: 高性能核心
 *   - Cortex-A78: 现代化高性能核心
 *   - Cortex-A710: ARMv9-A 性能核心
 *   - Cortex-A510: ARMv9-A 高能效核心
 *
 * 主要特性:
 *   - 64位执行状态 (AArch64)
 *   - 32位兼容模式 (AArch32)
 *   - 虚拟内存管理系统 (MMU)
 *   - TrustZone 安全扩展
 *   - NEON SIMD 引擎
 *   - 密码学扩展 (Crypto)
 *   - SVE/SVE2 可伸缩矢量扩展 (ARMv9)
 *   - 增强型 GIC 中断控制器
 *
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 FeatherCore Team. All rights reserved.
 */

#ifndef FEATHERCORE_ARCH_ARM_V8A_H
#define FEATHERCORE_ARCH_ARM_V8A_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define FEATHERCORE_ARCH_ARM_V8A

/*
 * ============================================================================
 * ARMv8-A 任务上下文结构体 (64-bit)
 * ============================================================================
 *
 * ARMv8-A AArch64 任务上下文使用 64 位寄存器 (X0-X30, SP)
 */

typedef struct {
    uint64_t x0;
    uint64_t x1;
    uint64_t x2;
    uint64_t x3;
    uint64_t x4;
    uint64_t x5;
    uint64_t x6;
    uint64_t x7;
    uint64_t x8;
    uint64_t x9;
    uint64_t x10;
    uint64_t x11;
    uint64_t x12;
    uint64_t x13;
    uint64_t x14;
    uint64_t x15;
    uint64_t x16;
    uint64_t x17;
    uint64_t x18;
    uint64_t x19;
    uint64_t x20;
    uint64_t x21;
    uint64_t x22;
    uint64_t x23;
    uint64_t x24;
    uint64_t x25;
    uint64_t x26;
    uint64_t x27;
    uint64_t x28;
    uint64_t sp_el0;
    uint64_t sp_el1;
    uint64_t elr_el1;
    uint64_t spsr_el1;
} ArmV8aTaskContext;

/*
 * ============================================================================
 * ARMv8-A 核心寄存器访问函数声明
 * ============================================================================
 */

/**
 * @brief 获取当前异常级别 (CurrentEL)
 * @return 当前异常级别 (0=EL0, 1=EL1, 2=EL2, 3=EL3)
 */
uint64_t arch_armv8a_get_currentel(void);

/**
 * @brief 获取 SCTLR_EL1 寄存器
 * @return 系统控制寄存器值
 */
uint64_t arch_armv8a_get_sctlr_el1(void);

/**
 * @brief 设置 SCTLR_EL1 寄存器
 * @param val: 系统控制寄存器值
 */
void arch_armv8a_set_sctlr_el1(uint64_t val);

/**
 * @brief 获取 TCR_EL1 寄存器
 * @return 转换控制寄存器值
 */
uint64_t arch_armv8a_get_tcr_el1(void);

/**
 * @brief 设置 TCR_EL1 寄存器
 * @param val: 转换控制寄存器值
 */
void arch_armv8a_set_tcr_el1(uint64_t val);

/**
 * @brief 获取 TTBR0_EL1 寄存器
 * @return 转换表基地址寄存器 0
 */
uint64_t arch_armv8a_get_ttbr0_el1(void);

/**
 * @brief 设置 TTBR0_EL1 寄存器
 * @param val: 转换表基地址
 */
void arch_armv8a_set_ttbr0_el1(uint64_t val);

/**
 * @brief 获取 MAIR_EL1 寄存器
 * @return 内存属性间接寄存器
 */
uint64_t arch_armv8a_get_mair_el1(void);

/**
 * @brief 设置 MAIR_EL1 寄存器
 * @param val: 内存属性值
 */
void arch_armv8a_set_mair_el1(uint64_t val);

/**
 * @brief 获取 VBAR_EL1 寄存器
 * @return 向量基地址寄存器
 */
uint64_t arch_armv8a_get_vbar_el1(void);

/**
 * @brief 设置 VBAR_EL1 寄存器
 * @param val: 向量表基地址
 */
void arch_armv8a_set_vbar_el1(uint64_t val);

/**
 * @brief 获取 SPSR_EL1 寄存器
 * @return 保存的程序状态寄存器
 */
uint64_t arch_armv8a_get_spsr_el1(void);

/**
 * @brief 设置 SPSR_EL1 寄存器
 * @param val: 保存的程序状态值
 */
void arch_armv8a_set_spsr_el1(uint64_t val);

/**
 * @brief 获取 ELR_EL1 寄存器
 * @return 异常链接寄存器
 */
uint64_t arch_armv8a_get_elr_el1(void);

/**
 * @brief 设置 ELR_EL1 寄存器
 * @param val: 异常返回地址
 */
void arch_armv8a_set_elr_el1(uint64_t val);

/*
 * ============================================================================
 * ARMv8-A 缓存管理函数声明
 * ============================================================================
 */

/**
 * @brief 使能指令缓存 (I-Cache)
 */
void arch_armv8a_enable_icache_el1(void);

/**
 * @brief 禁用指令缓存
 */
void arch_armv8a_disable_icache_el1(void);

/**
 * @brief 使能数据缓存 (D-Cache)
 */
void arch_armv8a_enable_dcache_el1(void);

/**
 * @brief 禁用数据缓存
 */
void arch_armv8a_disable_dcache_el1(void);

/**
 * @brief 使能 MMU
 */
void arch_armv8a_enable_mmu_el1(void);

/**
 * @brief 禁用 MMU
 */
void arch_armv8a_disable_mmu_el1(void);

/**
 * @brief 无效化 TLB
 */
void arch_armv8a_tlbi_vmalle1(void);

/*
 * ============================================================================
 * ARMv8-A 内存屏障函数声明
 * ============================================================================
 */

/**
 * @brief 数据同步屏障
 */
void arch_armv8a_dsb(void);

/**
 * @brief 指令同步屏障
 */
void arch_armv8a_isb(void);

/**
 * @brief 数据内存屏障
 */
void arch_armv8a_dmb(void);

/*
 * ============================================================================
 * ARMv8-A 低功耗模式函数声明
 * ============================================================================
 */

/**
 * @brief 等待中断
 */
void arch_armv8a_wfi(void);

/**
 * @brief 等待事件
 */
void arch_armv8a_wfe(void);

/**
 * @brief 发送事件
 */
void arch_armv8a_sev(void);

/*
 * ============================================================================
 * ARMv8-A 中断管理函数声明
 * ============================================================================
 */

/**
 * @brief 使能 IRQ
 */
void arch_armv8a_enable_irq(void);

/**
 * @brief 禁用 IRQ
 */
void arch_armv8a_disable_irq(void);

/*
 * ============================================================================
 * ARMv8-A FPU 函数声明
 * ============================================================================
 */

/**
 * @brief 使能 FPU
 */
void arch_armv8a_enable_fpu(void);

/**
 * @brief 禁用 FPU
 */
void arch_armv8a_disable_fpu(void);

/*
 * ============================================================================
 * ARMv8-A 初始化和上下文切换函数声明
 * ============================================================================
 */

/**
 * @brief ARMv8-A 架构初始化
 */
void arch_armv8a_init(void);

/**
 * @brief ARMv8-A 向量表设置
 */
void arch_armv8a_setup_vector_table(void);

/**
 * @brief 初始化用户任务上下文
 * @param context: 任务上下文
 * @param entry_point: 入口地址
 * @param arg: 参数
 */
void arch_armv8a_init_user_context(ArmV8aTaskContext *context, uint64_t entry_point, uint64_t arg);

/**
 * @brief 上下文切换
 */
void* arch_armv8a_switch_context(void *from, void *to);

/**
 * @brief 启动第一个任务
 */
void* arch_armv8a_start_first_task(void *context);

/**
 * @brief 跳转到内核
 */
void* arch_armv8a_jump_to_kernel(uint64_t vector_table_addr);

/*
 * ============================================================================
 * ARMv8-A GICv2/GICv3 函数声明
 * ============================================================================
 */

/**
 * @brief GIC 初始化
 */
void arch_armv8a_gic_init(void);

/**
 * @brief 使能中断
 */
void arch_armv8a_gic_enable_irq(uint32_t irq);

/**
 * @brief 禁用中断
 */
void arch_armv8a_gic_disable_irq(uint32_t irq);

/**
 * @brief 设置中断优先级
 */
void arch_armv8a_gic_set_priority(uint32_t irq, uint32_t priority);

/**
 * @brief 获取中断优先级
 */
uint32_t arch_armv8a_gic_get_priority(uint32_t irq);

/**
 * @brief 设置中断目标 CPU
 */
void arch_armv8a_gic_set_target(uint32_t irq, uint32_t cpu_target);

/**
 * @brief 发送软件中断 (SGI)
 */
void arch_armv8a_gic_send_sgi(uint32_t irq, uint32_t cpu_target);

/**
 * @brief 获取中断待处理状态
 */
uint32_t arch_armv8a_gic_get_pending(uint32_t irq);

/**
 * @brief 设置中断挂起状态
 */
void arch_armv8a_gic_set_pending(uint32_t irq);

/**
 * @brief 清除中断挂起状态
 */
void arch_armv8a_gic_clear_pending(uint32_t irq);

/**
 * @brief 获取当前正在执行的中断
 */
uint32_t arch_armv8a_gic_get_active_irq(void);

/**
 * @brief GIC 使能
 */
void arch_armv8a_gic_enable(void);

/**
 * @brief GIC 禁用
 */
void arch_armv8a_gic_disable(void);

/*
 * ============================================================================
 * ARMv8-A Generic Timer 函数声明
 * ============================================================================
 */

/**
 * @brief 获取CNTFRQ 寄存器 (计数频率)
 */
uint64_t arch_armv8a_get_cntfrq(void);

/**
 * @brief 设置CNTFRQ 寄存器 (计数频率)
 */
void arch_armv8a_set_cntfrq(uint64_t freq);

/**
 * @brief 获取 CNTPCT 寄存器 (物理计数器)
 */
uint64_t arch_armv8a_get_cntpct(void);

/**
 * @brief 获取 CNTVCT 寄存器 (虚拟计数器)
 */
uint64_t arch_armv8a_get_cntvct(void);

/**
 * @brief 获取 CNTP_TVAL 寄存器 (物理定时器值)
 */
uint32_t arch_armv8a_get_cntp_tval(void);

/**
 * @brief 设置 CNTP_TVAL 寄存器 (物理定时器值)
 */
void arch_armv8a_set_cntp_tval(uint32_t value);

/**
 * @brief 获取 CNTP_CTL 寄存器 (物理定时器控制)
 */
uint32_t arch_armv8a_get_cntp_ctl(void);

/**
 * @brief 设置 CNTP_CTL 寄存器 (物理定时器控制)
 */
void arch_armv8a_set_cntp_ctl(uint32_t value);

/**
 * @brief 获取 CNTV_TVAL 寄存器 (虚拟定时器值)
 */
uint32_t arch_armv8a_get_cntv_tval(void);

/**
 * @brief 设置 CNTV_TVAL 寄存器 (虚拟定时器值)
 */
void arch_armv8a_set_cntv_tval(uint32_t value);

/**
 * @brief 获取 CNTV_CTL 寄存器 (虚拟定时器控制)
 */
uint32_t arch_armv8a_get_cntv_ctl(void);

/**
 * @brief 设置 CNTV_CTL 寄存器 (虚拟定时器控制)
 */
void arch_armv8a_set_cntv_ctl(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif
