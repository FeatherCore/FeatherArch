/*
 * FeatherCore Architecture - ARMv7-R Implementation
 * FeatherCore 架构 - ARMv7-R 实现
 *
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2024 FeatherCore Team. All rights reserved.
 *
 * Description:
 *   This file provides ARMv7-R architecture-specific implementations.
 *   ARMv7-R is the Real-time profile, designed for real-time embedded
 *   systems requiring predictable interrupt latency and high reliability.
 *   支持的功能包括:
 *     - CPSR (Current Program Status Register) 操作
 *     - 处理器模式切换 (User, FIQ, IRQ, Supervisor, Abort, Undefined)
 *     - 中断管理 (IRQ/FIQ)
 *     - 内存屏障指令 (DSB, DMB, ISB)
 *     - 低功耗指令 (WFI, WFE, SEV)
 *     - 缓存管理 (I-Cache, D-Cache)
 *     - MMU/MPU 管理
 *     - FPU (Floating Point Unit) 管理
 *     - 任务上下文管理
 *
 * Note:
 *   ARMv7-R 使用 MPU (Memory Protection Unit) 而不是 MMU
 *   这与 ARMv7-A 不同,MPU 不支持虚拟内存地址转换
 *   但支持内存区域保护和缓存控制
 *
 * Supported Devices:
 *   - Cortex-R4, Cortex-R5, Cortex-R7, Cortex-R8
 *   - Cortex-R52, Cortex-R82
 */

#include "armv7r.h"
#include <stdint.h>

/**
 * @brief 获取 CPSR (Current Program Status Register) 寄存器的值
 * @brief Get CPSR (Current Program Status Register) value
 *
 * CPSR 包含:
 *   - 处理器模式位 (M[4:0])
 *   - ARM/Thumb 状态位 (T)
 *   - 中断使能位 (I, F)
 *   - 条件标志位 (N, Z, C, V)
 *   - Q 标志位 (DSP 扩展)
 *
 * @return uint32_t CPSR 寄存器的值
 */
uint32_t arch_armv7r_get_cpsr(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, CPSR" : "=r" (result));
    return result;
}

/**
 * @brief 设置 CPSR (Current Program Status Register) 寄存器的值
 * @brief Set CPSR (Current Program Status Register) value
 *
 * @param cpsr 要设置的 CPSR 值
 */
void arch_armv7r_set_cpsr(uint32_t cpsr) {
    __asm__ volatile ("MSR CPSR, %0" : : "r" (cpsr) : "memory");
}

/**
 * @brief 设置处理器运行模式
 * @brief Set processor execution mode
 *
 * ARMv7-R 支持多种处理器模式:
 *   - USR (User Mode): 用户模式
 *   - FIQ (FIQ Mode): 快速中断模式,拥有独立寄存器 r8-r12
 *   - IRQ (IRQ Mode): 普通中断模式
 *   - SVC (Supervisor Mode): 超级用户模式
 *   - ABT (Abort Mode): 中止模式 (数据/指令预取中止)
 *   - UND (Undefined Mode): 未定义指令模式
 *   - SYS (System Mode): 系统模式,与用户模式共享寄存器
 *
 * @param mode 要切换到的目标模式
 */
void arch_armv7r_set_mode(ArmV7rMode mode) {
    uint32_t cpsr = arch_armv7r_get_cpsr();
    cpsr = (cpsr & ~0x1FUL) | mode;
    arch_armv7r_set_cpsr(cpsr);
}

/**
 * @brief 获取当前处理器运行模式
 * @brief Get current processor execution mode
 *
 * @return ArmV7rMode 当前处理器模式
 */
ArmV7rMode arch_armv7r_get_mode(void) {
    return (ArmV7rMode)(arch_armv7r_get_cpsr() & 0x1FUL);
}

/**
 * @brief 获取当前特权级别
 * @brief Get current privilege level
 *
 * ARMv7-R 有两个特权级别:
 *   - PL0 (User Mode): 非特权级别
 *   - PL1 (Privileged): 特权级别
 *
 * @return uint32_t 0 表示用户模式 (PL0), 1 表示特权模式 (PL1)
 */
uint32_t arch_armv7r_get_privilege_level(void) {
    ArmV7rMode mode = arch_armv7r_get_mode();
    return (mode == ARM_V7R_MODE_USR) ? 0 : 1;
}

/**
 * @brief 使能 IRQ (普通中断)
 * @brief Enable IRQ (Interrupt Request)
 *
 * 通过清除 CPSR 中的 I 位来使能 IRQ 中断
 * CPSR[7] = 0 表示 IRQ 中断使能
 */
void arch_armv7r_enable_irq(void) {
    uint32_t cpsr = arch_armv7r_get_cpsr();
    cpsr &= ~0x80;
    arch_armv7r_set_cpsr(cpsr);
}

/**
 * @brief 禁用 IRQ (普通中断)
 * @brief Disable IRQ (Interrupt Request)
 *
 * 通过设置 CPSR 中的 I 位来禁用 IRQ 中断
 * CPSR[7] = 1 表示 IRQ 中断禁用
 */
void arch_armv7r_disable_irq(void) {
    uint32_t cpsr = arch_armv7r_get_cpsr();
    cpsr |= 0x80;
    arch_armv7r_set_cpsr(cpsr);
}

/**
 * @brief 使能 FIQ (快速中断)
 * @brief Enable FIQ (Fast Interrupt Request)
 *
 * 通过清除 CPSR 中的 F 位来使能 FIQ 中断
 * CPSR[6] = 0 表示 FIQ 中断使能
 * FIQ 比 IRQ 具有更高的优先级和更低的延迟
 */
void arch_armv7r_enable_fiq(void) {
    uint32_t cpsr = arch_armv7r_get_cpsr();
    cpsr &= ~0x40;
    arch_armv7r_set_cpsr(cpsr);
}

/**
 * @brief 禁用 FIQ (快速中断)
 * @brief Disable FIQ (Fast Interrupt Request)
 *
 * 通过设置 CPSR 中的 F 位来禁用 FIQ 中断
 * CPSR[6] = 1 表示 FIQ 中断禁用
 */
void arch_armv7r_disable_fiq(void) {
    uint32_t cpsr = arch_armv7r_get_cpsr();
    cpsr |= 0x40;
    arch_armv7r_set_cpsr(cpsr);
}

/**
 * @brief DSB (Data Synchronization Barrier) - 数据同步屏障
 * @brief Data Synchronization Barrier
 *
 * 确保所有之前的内存访问指令都完成后再执行后续指令
 * 在使用 MCR 指令修改 CP15 寄存器后必须使用 DSB
 *
 * 使用场景:
 *   - 修改缓存/MPU 配置后
 *   - 处理器间通信
 *   - DMA 操作同步
 */
void arch_armv7r_dsb(void) {
    __asm__ volatile ("dsb sy" : : : "memory");
}

/**
 * @brief ISB (Instruction Synchronization Barrier) - 指令同步屏障
 * @brief Instruction Synchronization Barrier
 *
 * 刷新流水线,确保所有之前的指令都执行完成
 * ISB 会清空流水线并重新取指
 *
 * 使用场景:
 *   - 修改系统控制寄存器后
 *   - 切换特权级别后
 *   - 自修改代码执行后
 */
void arch_armv7r_isb(void) {
    __asm__ volatile ("isb sy" : : : "memory");
}

/**
 * @brief DMB (Data Memory Barrier) - 数据内存屏障
 * @brief Data Memory Barrier
 *
 * 确保所有之前的内存访问指令都完成后再执行后续内存访问指令
 * DMB 不需要等待之前的指令完成,只需要保证内存访问顺序
 */
void arch_armv7r_dmb(void) {
    __asm__ volatile ("dmb sy" : : : "memory");
}

/**
 * @brief WFI (Wait For Interrupt) - 等待中断
 * @brief Wait For Interrupt
 *
 * 使处理器进入低功耗状态,直到发生中断或其他唤醒事件
 * 用于实现动态功耗管理
 * 注意: 在实时系统中需要谨慎使用 WFI
 */
void arch_armv7r_wfi(void) {
    __asm__ volatile ("wfi" : : : "memory");
}

/**
 * @brief WFE (Wait For Event) - 等待事件
 * @brief Wait For Event
 *
 * 使处理器进入低功耗状态,直到发生事件
 * 通常用于多处理器之间的同步
 */
void arch_armv7r_wfe(void) {
    __asm__ volatile ("wfe" : : : "memory");
}

/**
 * @brief SEV (Send Event) - 发送事件
 * @brief Send Event
 *
 * 向所有处理器发送事件信号
 * 用于唤醒正在等待 WFE 的处理器
 */
void arch_armv7r_sev(void) {
    __asm__ volatile ("sev" : : : "memory");
}

/**
 * @brief 使能指令缓存 (I-Cache)
 * @brief Enable Instruction Cache (I-Cache)
 *
 * 通过设置 SCTLR (System Control Register) 的 I 位 (bit 12)
 * 使能指令缓存可以显著提高指令执行效率
 */
void arch_armv7r_enable_icache(void) {
    uint32_t sctlr;
    __asm__ volatile ("MRC p15, 0, %0, c1, c0, 0" : "=r" (sctlr));
    sctlr |= (1UL << 12);
    __asm__ volatile ("MCR p15, 0, %0, c1, c0, 0" : : "r" (sctlr) : "memory");
    arch_armv7r_dsb();
    arch_armv7r_isb();
}

/**
 * @brief 禁用指令缓存 (I-Cache)
 * @brief Disable Instruction Cache (I-Cache)
 *
 * 通过清除 SCTLR 的 I 位来禁用指令缓存
 */
void arch_armv7r_disable_icache(void) {
    uint32_t sctlr;
    __asm__ volatile ("MRC p15, 0, %0, c1, c0, 0" : "=r" (sctlr));
    sctlr &= ~(1UL << 12);
    __asm__ volatile ("MCR p15, 0, %0, c1, c0, 0" : : "r" (sctlr) : "memory");
    arch_armv7r_dsb();
    arch_armv7r_isb();
}

/**
 * @brief 使能数据缓存 (D-Cache)
 * @brief Enable Data Cache (D-Cache)
 *
 * 通过设置 SCTLR 的 C 位 (bit 2) 来使能数据缓存
 */
void arch_armv7r_enable_dcache(void) {
    uint32_t sctlr;
    __asm__ volatile ("MRC p15, 0, %0, c1, c0, 0" : "=r" (sctlr));
    sctlr |= (1UL << 2);
    __asm__ volatile ("MCR p15, 0, %0, c1, c0, 0" : : "r" (sctlr) : "memory");
    arch_armv7r_dsb();
    arch_armv7r_isb();
}

/**
 * @brief 禁用数据缓存 (D-Cache)
 * @brief Disable Data Cache (D-Cache)
 *
 * 通过清除 SCTLR 的 C 位来禁用数据缓存
 */
void arch_armv7r_disable_dcache(void) {
    uint32_t sctlr;
    __asm__ volatile ("MRC p15, 0, %0, c1, c0, 0" : "=r" (sctlr));
    sctlr &= ~(1UL << 2);
    __asm__ volatile ("MCR p15, 0, %0, c1, c0, 0" : : "r" (sctlr) : "memory");
    arch_armv7r_dsb();
    arch_armv7r_isb();
}

/**
 * @brief 无效化整个指令缓存 (I-Cache)
 * @brief Invalidate entire Instruction Cache
 *
 * 无效化 I-Cache 中的所有内容
 * 在执行自修改代码或代码更新后需要调用此函数
 * ICIALLU - Invalidate All Instruction Caches to Point of Unification
 */
void arch_armv7r_invalidate_icache_all(void) {
    __asm__ volatile ("MCR p15, 0, %0, c7, c5, 0" : : "r" (0) : "memory");
    arch_armv7r_dsb();
    arch_armv7r_isb();
}

/**
 * @brief 无效化整个数据缓存 (D-Cache)
 * @brief Invalidate entire Data Cache
 *
 * 无效化 D-Cache 中的所有内容
 * 注意: 失效前应先清理缓存 (Clean) 以避免数据丢失
 */
void arch_armv7r_invalidate_dcache_all(void) {
    for (uint32_t way = 0; way < 16; way++) {
        for (uint32_t set = 0; set < 64; set++) {
            uint32_t val = (way << 30) | (set << 5);
            __asm__ volatile ("MCR p15, 0, %0, c7, c6, 1" : : "r" (val) : "memory");
        }
    }
    arch_armv7r_dsb();
}

/**
 * @brief 无效化整个 TLB (Translation Lookaside Buffer)
 * @brief Invalidate entire TLB
 *
 * TLB 是段/页表查找的缓存
 * 注意: ARMv7-R 通常使用 MPU 而非 MMU,TLB 主要用于缓存
 * 在修改内存属性后需要使 TLB 失效
 */
void arch_armv7r_invalidate_tlb_all(void) {
    __asm__ volatile ("MCR p15, 0, %0, c8, c7, 0" : : "r" (0) : "memory");
    arch_armv7r_dsb();
    arch_armv7r_isb();
}

/**
 * @brief 使能 MMU
 * @brief Enable MMU
 *
 * 注意: ARMv7-R 主要使用 MPU,但某些 Cortex-R 处理器支持 MMU
 * 如果支持,启用 MMU 前需要:
 *   1. 设置 TTBR0 (Translation Table Base Register 0)
 *   2. 设置 DACR (Domain Access Control Register)
 *   3. 可选: 设置其他相关寄存器
 *
 * SCTLR[0] = 1 表示启用 MMU
 */
void arch_armv7r_enable_mmu(void) {
    uint32_t sctlr;
    __asm__ volatile ("MRC p15, 0, %0, c1, c0, 0" : "=r" (sctlr));
    sctlr |= 0x1;
    __asm__ volatile ("MCR p15, 0, %0, c1, c0, 0" : : "r" (sctlr) : "memory");
    arch_armv7r_dsb();
    arch_armv7r_isb();
}

/**
 * @brief 禁用 MMU
 * @brief Disable MMU
 *
 * 禁用 MMU 前需要:
 *   1. 清理并无效化 D-Cache
 *   2. 无效化 TLB
 * 以确保内存一致性
 */
void arch_armv7r_disable_mmu(void) {
    uint32_t sctlr;
    __asm__ volatile ("MRC p15, 0, %0, c1, c0, 0" : "=r" (sctlr));
    sctlr &= ~0x1;
    __asm__ volatile ("MCR p15, 0, %0, c1, c0, 0" : : "r" (sctlr) : "memory");
    arch_armv7r_dsb();
    arch_armv7r_isb();
}

/**
 * @brief 设置 TTBR0 (Translation Table Base Register 0)
 * @brief Set TTBR0 (Translation Table Base Register 0)
 *
 * TTBR0 包含第一级页表的基地址
 * 需要 16KB 对齐
 *
 * @param ttbr0 页表基地址
 */
void arch_armv7r_set_ttbr0(uint32_t ttbr0) {
    __asm__ volatile ("MCR p15, 0, %0, c2, c0, 0" : : "r" (ttbr0) : "memory");
    arch_armv7r_dsb();
}

/**
 * @brief 设置 DACR (Domain Access Control Register)
 * @brief Set DACR (Domain Access Control Register)
 *
 * DACR 定义 16 个域的访问权限
 * 每个域占 2 位:
 *   - 00: 无访问权限
 *   - 01: 客户端 - 检查页表中的权限位
 *   - 10: 保留
 *   - 11: 管理 - 无条件允许访问
 *
 * @param dacr 域访问控制值
 */
void arch_armv7r_set_dacr(uint32_t dacr) {
    __asm__ volatile ("MCR p15, 0, %0, c3, c0, 0" : : "r" (dacr) : "memory");
    arch_armv7r_dsb();
}

/**
 * @brief 设置 VBAR (Vector Base Address Register)
 * @brief Set VBAR (Vector Base Address Register)
 *
 * VBAR 定义异常向量的基地址
 * 默认为 0x00000000
 *
 * @param vbar 异常向量基地址
 */
void arch_armv7r_set_vbar(uint32_t vbar) {
    __asm__ volatile ("MCR p15, 0, %0, c12, c0, 0" : : "r" (vbar) : "memory");
    arch_armv7r_dsb();
}

/**
 * @brief 使能 FPU (浮点单元)
 * @brief Enable FPU (Floating Point Unit)
 *
 * ARMv7-R 支持 VFPv3 (Vector Floating Point) 硬件浮点单元
 * 需要在 CPACR (Coprocessor Access Control Register) 中使能访问
 *
 * CPACR[20-21]: CP10 (FPU) 控制
 * CPACR[22-23]: CP11 控制
 *
 * 注意: ARMv7-R 通常使用 VFPv3-d16 或 VFPv3-d32
 */
void arch_armv7r_enable_fpu(void) {
    uint32_t cpacr;
    __asm__ volatile ("MRC p15, 0, %0, c1, c0, 2" : "=r" (cpacr));
    cpacr |= (0x3UL << 20) | (0x3UL << 22);
    __asm__ volatile ("MCR p15, 0, %0, c1, c0, 2" : : "r" (cpacr) : "memory");
    arch_armv7r_dsb();
    arch_armv7r_isb();
}

/**
 * @brief 禁用 FPU (浮点单元)
 * @brief Disable FPU (Floating Point Unit)
 *
 * 禁用 FPU 访问以节省功耗或确保代码不使用浮点运算
 */
void arch_armv7r_disable_fpu(void) {
    uint32_t cpacr;
    __asm__ volatile ("MRC p15, 0, %0, c1, c0, 2" : "=r" (cpacr));
    cpacr &= ~((0x3UL << 20) | (0x3UL << 22));
    __asm__ volatile ("MCR p15, 0, %0, c1, c0, 2" : : "r" (cpacr) : "memory");
    arch_armv7r_dsb();
    arch_armv7r_isb();
}

/**
 * @brief 初始化 ARMv7-R 架构
 * @brief Initialize ARMv7-R architecture
 *
 * 执行基本的架构初始化:
 *   1. 数据同步屏障
 *   2. 数据内存屏障
 *   3. 使能指令缓存
 *   4. 使能数据缓存
 *   5. 使能 FPU
 *
 * 注意: ARMv7-R 通常不使用 MMU,而是使用 MPU
 */
void arch_armv7r_init(void) {
    arch_armv7r_dsb();
    arch_armv7r_dmb();
    arch_armv7r_enable_icache();
    arch_armv7r_enable_dcache();
    arch_armv7r_enable_fpu();
    arch_armv7r_dsb();
    arch_armv7r_dmb();
}

/**
 * @brief 设置异常向量表
 * @brief Setup Vector Table
 *
 * 将 VBAR 设置为应用程序的向量表基地址
 * 异常向量表包含以下入口:
 *   - Reset
 *   - Undefined Instruction
 *   - Software Interrupt (SVC)
 *   - Prefetch Abort
 *   - Data Abort
 *   - IRQ
 *   - FIQ
 */
void arch_armv7r_setup_vector_table(void) {
    extern uint32_t _vector_table_base;
    arch_armv7r_set_vbar((uint32_t)&_vector_table_base);
}

/**
 * @brief 初始化特权任务上下文
 * @brief Initialize privileged task context
 *
 * 创建一个新的任务上下文,设置初始寄存器值
 * ARMv7-R 的任务通常运行在 SVC (Supervisor) 模式
 *
 * @param context 任务上下文结构体指针
 * @param entry_point 任务入口地址 (PC)
 * @param arg 传递给任务的参数 (R0)
 */
void arch_armv7r_init_user_context(ArmV7rTaskContext *context, uint32_t entry_point, uint32_t arg) {
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
    context->cpsr = ARM_V7R_MODE_SVC;
    context->lr = 0xFFFFFFFFUL;
}

/**
 * @brief 切换任务上下文
 * @brief Switch task context
 *
 * 保存当前任务状态并恢复目标任务状态
 * 这是 RTOS 任务切换的核心函数
 *
 * @param from 保存当前任务的上下文
 * @param to 目标任务的上下文
 * @return void* 指向被保存上下文的指针
 */
void* arch_armv7r_switch_context(void *from, void *to) {
    (void)from;
    (void)to;
    return NULL;
}

/**
 * @brief 启动第一个任务
 * @brief Start first task
 *
 * 启动第一个任务,通常在 RTOS 启动时调用
 * 此函数不应该返回
 *
 * @param context 第一个任务的上下文
 * @return void* 不返回
 */
void* arch_armv7r_start_first_task(void *context) {
    (void)context;
    __builtin_unreachable();
}

/**
 * @brief 跳转到内核
 * @brief Jump to kernel
 *
 * 跳转到内核或引导加载程序
 * 此函数不应该返回
 *
 * @param vector_table_addr 内核/引导程序的向量表地址
 * @return void* 不返回
 */
void* arch_armv7r_jump_to_kernel(uint32_t vector_table_addr) {
    (void)vector_table_addr;
    __builtin_unreachable();
}
