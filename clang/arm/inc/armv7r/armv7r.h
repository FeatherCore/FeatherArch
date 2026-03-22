/*
 * FeatherCore Architecture - ARMv7-R/ARMv8-R (Cortex-R4/R5/R7/R52) Support
 *
 * ============================================================================
 * 文件: armv7r.h
 * 描述: ARMv7-R 和 ARMv8-R 架构特定定义和函数声明
 *
 * ARMv7-R/ARMv8-R 架构概述:
 *   ARM R-Profile 是实时处理器架构，专为高性能实时应用设计。
 *   具有确定性的中断响应和内存访问延迟。
 *
 * 支持的处理器:
 *   ARMv7-R:
 *   - Cortex-R4: 高性能实时处理器
 *   - Cortex-R5: 双核锁步实时处理器
 *   - Cortex-R7: 多核实时处理器
 *   - Cortex-R8: 增强型多核实时处理器
 *
 *   ARMv8-R:
 *   - Cortex-R52: ARMv8-R 实时处理器，集成安全功能
 *
 * 主要特性:
 *   - MPU 内存保护单元
 *   - 指令/数据缓存 (可选)
 *   - TCM (Tight Coupled Memory) 接口
 *   - 浮点单元 (可选 VFPv3)
 *   - DSP 扩展
 *   - 锁步核 (Lock-step) 支持
 *
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 FeatherCore Team. All rights reserved.
 */

#ifndef FEATHERCORE_ARCH_ARM_V7R_H
#define FEATHERCORE_ARCH_ARM_V7R_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define FEATHERCORE_ARCH_ARM_V7R

/*
 * ============================================================================
 * ARMv7-R 处理器模式枚举
 * ============================================================================
 */

typedef enum {
    ARM_V7R_MODE_USR = 0x10,
    ARM_V7R_MODE_FIQ = 0x11,
    ARM_V7R_MODE_IRQ = 0x12,
    ARM_V7R_MODE_SVC = 0x13,
    ARM_V7R_MODE_ABT = 0x17,
    ARM_V7R_MODE_UND = 0x1B,
    ARM_V7R_MODE_SYS = 0x1F,
} ArmV7rMode;

/*
 * ============================================================================
 * ARMv7-R 任务上下文结构体
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
} ArmV7rTaskContext;

/*
 * ============================================================================
 * ARMv7-R 核心寄存器访问函数声明
 * ============================================================================
 */

/**
 * @brief 获取 CPSR (Current Program Status Register)
 * @return CPSR 当前值
 */
uint32_t arch_armv7r_get_cpsr(void);

/**
 * @brief 设置 CPSR
 * @param cpsr: CPSR 新值
 */
void arch_armv7r_set_cpsr(uint32_t cpsr);

/**
 * @brief 切换处理器模式
 * @param mode: 目标模式
 */
void arch_armv7r_set_mode(ArmV7rMode mode);

/**
 * @brief 获取当前处理器模式
 * @return 当前模式
 */
ArmV7rMode arch_armv7r_get_mode(void);

/**
 * @brief 获取当前特权级别
 * @return 0=用户模式, 1=特权模式
 */
uint32_t arch_armv7r_get_privilege_level(void);

/*
 * ============================================================================
 * ARMv7-R 中断管理函数声明
 * ============================================================================
 */

/**
 * @brief 使能 IRQ 中断
 */
void arch_armv7r_enable_irq(void);

/**
 * @brief 禁用 IRQ 中断
 */
void arch_armv7r_disable_irq(void);

/**
 * @brief 使能 FIQ 中断
 */
void arch_armv7r_enable_fiq(void);

/**
 * @brief 禁用 FIQ 中断
 */
void arch_armv7r_disable_fiq(void);

/*
 * ============================================================================
 * ARMv7-R 内存屏障函数声明
 * ============================================================================
 */

/**
 * @brief 数据同步屏障 (Data Synchronization Barrier)
 */
void arch_armv7r_dsb(void);

/**
 * @brief 指令同步屏障 (Instruction Synchronization Barrier)
 */
void arch_armv7r_isb(void);

/**
 * @brief 数据内存屏障 (Data Memory Barrier)
 */
void arch_armv7r_dmb(void);

/*
 * ============================================================================
 * ARMv7-R 低功耗模式函数声明
 * ============================================================================
 */

/**
 * @brief 等待中断 (Wait For Interrupt)
 */
void arch_armv7r_wfi(void);

/**
 * @brief 等待事件 (Wait For Event)
 */
void arch_armv7r_wfe(void);

/**
 * @brief 发送事件 (Send Event)
 */
void arch_armv7r_sev(void);

/*
 * ============================================================================
 * ARMv7-R 缓存管理函数声明
 * ============================================================================
 */

/**
 * @brief 使能指令缓存 (I-Cache)
 */
void arch_armv7r_enable_icache(void);

/**
 * @brief 禁用指令缓存
 */
void arch_armv7r_disable_icache(void);

/**
 * @brief 使能数据缓存 (D-Cache)
 */
void arch_armv7r_enable_dcache(void);

/**
 * @brief 禁用数据缓存
 */
void arch_armv7r_disable_dcache(void);

/**
 * @brief 无效化指令缓存
 */
void arch_armv7r_invalidate_icache_all(void);

/**
 * @brief 无效化数据缓存
 */
void arch_armv7r_invalidate_dcache_all(void);

/**
 * @brief 无效化整个 TLB
 */
void arch_armv7r_invalidate_tlb_all(void);

/*
 * ============================================================================
 * ARMv7-R MMU/MPU 函数声明
 * ============================================================================
 */

/**
 * @brief 使能 MMU
 */
void arch_armv7r_enable_mmu(void);

/**
 * @brief 禁用 MMU
 */
void arch_armv7r_disable_mmu(void);

/**
 * @brief 设置 TTBR0 (Translation Table Base Register 0)
 * @param ttbr0: 页表基地址
 */
void arch_armv7r_set_ttbr0(uint32_t ttbr0);

/**
 * @brief 设置 DACR (Domain Access Control Register)
 * @param dacr: 域访问控制值
 */
void arch_armv7r_set_dacr(uint32_t dacr);

/**
 * @brief 设置 VBAR (Vector Base Address Register)
 * @param vbar: 向量表基地址
 */
void arch_armv7r_set_vbar(uint32_t vbar);

/*
 * ============================================================================
 * ARMv7-R FPU 函数声明
 * ============================================================================
 */

/**
 * @brief 使能 FPU
 */
void arch_armv7r_enable_fpu(void);

/**
 * @brief 禁用 FPU
 */
void arch_armv7r_disable_fpu(void);

/*
 * ============================================================================
 * ARMv7-R 初始化和上下文切换函数声明
 * ============================================================================
 */

/**
 * @brief ARMv7-R 架构初始化
 */
void arch_armv7r_init(void);

/**
 * @brief ARMv7-R 向量表设置
 */
void arch_armv7r_setup_vector_table(void);

/**
 * @brief 初始化用户任务上下文
 * @param context: 任务上下文
 * @param entry_point: 入口地址
 * @param arg: 参数
 */
void arch_armv7r_init_user_context(ArmV7rTaskContext *context, uint32_t entry_point, uint32_t arg);

/**
 * @brief 上下文切换
 * @param from: 源上下文
 * @param to: 目标上下文
 * @return 切换后的地址
 */
void* arch_armv7r_switch_context(void *from, void *to);

/**
 * @brief 启动第一个任务
 * @param context: 任务上下文
 * @return 不返回
 */
void* arch_armv7r_start_first_task(void *context);

/**
 * @brief 跳转到内核
 * @param vector_table_addr: 向量表地址
 * @return 不返回
 */
void* arch_armv7r_jump_to_kernel(uint32_t vector_table_addr);

#ifdef __cplusplus
}
#endif

#endif
