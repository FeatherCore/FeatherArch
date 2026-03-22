/*
 * FeatherCore Architecture - ARMv7-A Implementation
 * FeatherCore 架构 - ARMv7-A 实现
 *
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2024 FeatherCore Team. All rights reserved.
 *
 * Description:
 *   This file provides ARMv7-A architecture-specific implementations.
 *   ARMv7-A is the Application profile, designed for high-performance
 *   applications like smartphones, tablets, and embedded systems.
 *   支持的功能包括:
 *     - CPSR (Current Program Status Register) 操作
 *     - 处理器模式切换 (User, System, Supervisor, etc.)
 *     - 中断管理 (IRQ/FIQ)
 *     - 内存屏障指令 (DSB, DMB, ISB)
 *     - 低功耗指令 (WFI, WFE, SEV)
 *     - 缓存管理 (I-Cache, D-Cache)
 *     - MMU 管理
 *     - FPU (Floating Point Unit) 管理
 *     - 任务上下文管理
 *
 * Supported Devices:
 *   - Cortex-A5, Cortex-A7, Cortex-A8, Cortex-A9, Cortex-A12, Cortex-A15
 */

#include "armv7a.h"
#include <stdint.h>

/**
 * @brief 获取 CPSR (Current Program Status Register) 寄存器的值
 * @brief Get CPSR (Current Program Status Register) value
 *
 * CPSR 包含:
 *   - 处理器模式位 (M[4:0])
 *   - ARM/Thumb 状态位
 *   - 中断使能位 (I, F)
 *   - 条件标志位 (N, Z, C, V)
 *
 * @return uint32_t CPSR 寄存器的值
 */
uint32_t arch_armv7a_get_cpsr(void) {
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
void arch_armv7a_set_cpsr(uint32_t cpsr) {
    __asm__ volatile ("MSR CPSR, %0" : : "r" (cpsr) : "memory");
}

/**
 * @brief 设置处理器运行模式
 * @brief Set processor execution mode
 *
 * ARMv7-A 支持多种处理器模式:
 *   - USR (User Mode): 用户模式, 非特权模式
 *   - FIQ (FIQ Mode): 快速中断模式
 *   - IRQ (IRQ Mode): 普通中断模式
 *   - SVC (Supervisor Mode): 超级用户模式, 系统调用
 *   - ABT (Abort Mode): 中止模式
 *   - UND (Undefined Mode): 未定义指令模式
 *   - SYS (System Mode): 系统模式, 特权用户模式
 *
 * @param mode 要切换到的目标模式
 */
void arch_armv7a_set_mode(ArmV7aMode mode) {
    uint32_t cpsr = arch_armv7a_get_cpsr();
    cpsr = (cpsr & ~0x1FUL) | mode;
    arch_armv7a_set_cpsr(cpsr);
}

/**
 * @brief 获取当前处理器运行模式
 * @brief Get current processor execution mode
 *
 * @return ArmV7aMode 当前处理器模式
 */
ArmV7aMode arch_armv7a_get_mode(void) {
    return (ArmV7aMode)(arch_armv7a_get_cpsr() & 0x1FUL);
}

/**
 * @brief 获取当前特权级别
 * @brief Get current privilege level
 *
 * ARMv7-A 有两个特权级别:
 *   - PL0 (User Mode): 非特权级别
 *   - PL1 (Privileged): 特权级别 (包括 SVC, FIQ, IRQ, ABT, UND, SYS)
 *
 * @return uint32_t 0 表示用户模式 (PL0), 1 表示特权模式 (PL1)
 */
uint32_t arch_armv7a_get_privilege_level(void) {
    ArmV7aMode mode = arch_armv7a_get_mode();
    return (mode == ARM_V7A_MODE_USR) ? 0 : 1;
}

/**
 * @brief 使能 IRQ (普通中断)
 * @brief Enable IRQ (Interrupt Request)
 *
 * 通过清除 CPSR 中的 I 位来使能 IRQ 中断
 * CPSR[7] = 0 表示 IRQ 中断使能
 */
void arch_armv7a_enable_irq(void) {
    uint32_t cpsr = arch_armv7a_get_cpsr();
    cpsr &= ~0x80;
    arch_armv7a_set_cpsr(cpsr);
}

/**
 * @brief 禁用 IRQ (普通中断)
 * @brief Disable IRQ (Interrupt Request)
 *
 * 通过设置 CPSR 中的 I 位来禁用 IRQ 中断
 * CPSR[7] = 1 表示 IRQ 中断禁用
 */
void arch_armv7a_disable_irq(void) {
    uint32_t cpsr = arch_armv7a_get_cpsr();
    cpsr |= 0x80;
    arch_armv7a_set_cpsr(cpsr);
}

/**
 * @brief 使能 FIQ (快速中断)
 * @brief Enable FIQ (Fast Interrupt Request)
 *
 * 通过清除 CPSR 中的 F 位来使能 FIQ 中断
 * CPSR[6] = 0 表示 FIQ 中断使能
 * FIQ 比 IRQ 具有更高的优先级
 */
void arch_armv7a_enable_fiq(void) {
    uint32_t cpsr = arch_armv7a_get_cpsr();
    cpsr &= ~0x40;
    arch_armv7a_set_cpsr(cpsr);
}

/**
 * @brief 禁用 FIQ (快速中断)
 * @brief Disable FIQ (Fast Interrupt Request)
 *
 * 通过设置 CPSR 中的 F 位来禁用 FIQ 中断
 * CPSR[6] = 1 表示 FIQ 中断禁用
 */
void arch_armv7a_disable_fiq(void) {
    uint32_t cpsr = arch_armv7a_get_cpsr();
    cpsr |= 0x40;
    arch_armv7a_set_cpsr(cpsr);
}

/**
 * @brief DSB (Data Synchronization Barrier) - 数据同步屏障
 * @brief Data Synchronization Barrier
 *
 * 确保所有之前的内存访问指令都完成后再执行后续指令
 * 在使用 MCR 指令修改 CP15 寄存器后必须使用 DSB
 *
 * 使用场景:
 *   - 修改 MMU 配置后
 *   - 修改缓存/TLB 后
 *   - 处理器间通信
 */
void arch_armv7a_dsb(void) {
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
 *   - 修改 MMU 配置后
 *   - 切换特权级别后
 */
void arch_armv7a_isb(void) {
    __asm__ volatile ("isb sy" : : : "memory");
}

/**
 * @brief DMB (Data Memory Barrier) - 数据内存屏障
 * @brief Data Memory Barrier
 *
 * 确保所有之前的内存访问指令都完成后再执行后续内存访问指令
 * DMB 不需要等待之前的指令完成,只需要保证内存访问顺序
 */
void arch_armv7a_dmb(void) {
    __asm__ volatile ("dmb sy" : : : "memory");
}

/**
 * @brief WFI (Wait For Interrupt) - 等待中断
 * @brief Wait For Interrupt
 *
 * 使处理器进入低功耗状态,直到发生中断或其他唤醒事件
 * 用于实现动态功耗管理
 */
void arch_armv7a_wfi(void) {
    __asm__ volatile ("wfi" : : : "memory");
}

/**
 * @brief WFE (Wait For Event) - 等待事件
 * @brief Wait For Event
 *
 * 使处理器进入低功耗状态,直到发生事件
 * 通常用于多处理器之间的同步
 */
void arch_armv7a_wfe(void) {
    __asm__ volatile ("wfe" : : : "memory");
}

/**
 * @brief SEV (Send Event) - 发送事件
 * @brief Send Event
 *
 * 向所有处理器发送事件信号
 * 用于唤醒正在等待 WFE 的处理器
 */
void arch_armv7a_sev(void) {
    __asm__ volatile ("sev" : : : "memory");
}

/**
 * @brief 使能指令缓存 (I-Cache)
 * @brief Enable Instruction Cache (I-Cache)
 *
 * 通过设置 SCTLR (System Control Register) 的 I 位 (bit 12)
 * 使能指令缓存可以显著提高指令执行效率
 */
void arch_armv7a_enable_icache(void) {
    uint32_t sctlr;
    __asm__ volatile ("MRC p15, 0, %0, c1, c0, 0" : "=r" (sctlr));
    sctlr |= (1UL << 12);
    __asm__ volatile ("MCR p15, 0, %0, c1, c0, 0" : : "r" (sctlr) : "memory");
    arch_armv7a_dsb();
    arch_armv7a_isb();
}

/**
 * @brief 禁用指令缓存 (I-Cache)
 * @brief Disable Instruction Cache (I-Cache)
 *
 * 通过清除 SCTLR 的 I 位来禁用指令缓存
 */
void arch_armv7a_disable_icache(void) {
    uint32_t sctlr;
    __asm__ volatile ("MRC p15, 0, %0, c1, c0, 0" : "=r" (sctlr));
    sctlr &= ~(1UL << 12);
    __asm__ volatile ("MCR p15, 0, %0, c1, c0, 0" : : "r" (sctlr) : "memory");
    arch_armv7a_dsb();
    arch_armv7a_isb();
}

/**
 * @brief 使能数据缓存 (D-Cache)
 * @brief Enable Data Cache (D-Cache)
 *
 * 通过设置 SCTLR 的 C 位 (bit 2) 来使能数据缓存
 * 数据缓存可以显著提高数据访问效率
 */
void arch_armv7a_enable_dcache(void) {
    uint32_t sctlr;
    __asm__ volatile ("MRC p15, 0, %0, c1, c0, 0" : "=r" (sctlr));
    sctlr |= (1UL << 2);
    __asm__ volatile ("MCR p15, 0, %0, c1, c0, 0" : : "r" (sctlr) : "memory");
    arch_armv7a_dsb();
    arch_armv7a_isb();
}

/**
 * @brief 禁用数据缓存 (D-Cache)
 * @brief Disable Data Cache (D-Cache)
 *
 * 通过清除 SCTLR 的 C 位来禁用数据缓存
 */
void arch_armv7a_disable_dcache(void) {
    uint32_t sctlr;
    __asm__ volatile ("MRC p15, 0, %0, c1, c0, 0" : "=r" (sctlr));
    sctlr &= ~(1UL << 2);
    __asm__ volatile ("MCR p15, 0, %0, c1, c0, 0" : : "r" (sctlr) : "memory");
    arch_armv7a_dsb();
    arch_armv7a_isb();
}

/**
 * @brief 无效化整个指令缓存 (I-Cache)
 * @brief Invalidate entire Instruction Cache
 *
 * 无效化 I-Cache 中的所有内容
 * 在执行自修改代码或代码更新后需要调用此函数
 * ICIALLU - Invalidate All Instruction Caches to Point of Unification
 */
void arch_armv7a_invalidate_icache_all(void) {
    __asm__ volatile ("MCR p15, 0, %0, c7, c5, 0" : : "r" (0) : "memory");
    arch_armv7a_dsb();
    arch_armv7a_isb();
}

/**
 * @brief 无效化整个数据缓存 (D-Cache)
 * @brief Invalidate entire Data Cache
 *
 * 无效化 D-Cache 中的所有内容
 * 使用 DCIALLU (DC Invalidate All to Point of Unification)
 * 注意: 失效前应先清理缓存 (Clean) 以避免数据丢失
 */
void arch_armv7a_invalidate_dcache_all(void) {
    for (uint32_t way = 0; way < 16; way++) {
        for (uint32_t set = 0; set < 64; set++) {
            uint32_t val = (way << 30) | (set << 5);
            __asm__ volatile ("MCR p15, 0, %0, c7, c6, 1" : : "r" (val) : "memory");
        }
    }
    arch_armv7a_dsb();
}

/**
 * @brief 清理并无效化整个数据缓存 (D-Cache)
 * @brief Clean and Invalidate entire Data Cache
 *
 * 先清理 D-Cache (写回内存),然后无效化
 * 在禁用 D-Cache 或 MMU 前必须调用此函数
 * DCCIMVAC - Data Cache Clean and Invalidate by Modified Virtual Address to Point of Coherency
 */
void arch_armv7a_clean_invalidate_dcache_all(void) {
    for (uint32_t way = 0; way < 16; way++) {
        for (uint32_t set = 0; set < 64; set++) {
            uint32_t val = (way << 30) | (set << 5);
            __asm__ volatile ("MCR p15, 0, %0, c7, c14, 1" : : "r" (val) : "memory");
        }
    }
    arch_armv7a_dsb();
}

/**
 * @brief 无效化整个 TLB (Translation Lookaside Buffer)
 * @brief Invalidate entire TLB
 *
 * TLB 是页表查找的缓存
 * 在修改页表后需要使 TLB 失效
 * TLBIALL - TLB Invalidate All
 */
void arch_armv7a_invalidate_tlb_all(void) {
    __asm__ volatile ("MCR p15, 0, %0, c8, c7, 0" : : "r" (0) : "memory");
    arch_armv7a_dsb();
    arch_armv7a_isb();
}

/**
 * @brief 使能 MMU (Memory Management Unit)
 * @brief Enable MMU (Memory Management Unit)
 *
 * MMU 负责虚拟地址到物理地址的转换
 * 启用 MMU 前需要:
 *   1. 设置 TTBR0 (Translation Table Base Register 0)
 *   2. 设置 DACR (Domain Access Control Register)
 *   3. 可选: 设置其他相关寄存器
 *
 * SCTLR[0] = 1 表示启用 MMU
 */
void arch_armv7a_enable_mmu(void) {
    uint32_t sctlr;
    __asm__ volatile ("MRC p15, 0, %0, c1, c0, 0" : "=r" (sctlr));
    sctlr |= 0x1;
    __asm__ volatile ("MCR p15, 0, %0, c1, c0, 0" : : "r" (sctlr) : "memory");
    arch_armv7a_dsb();
    arch_armv7a_isb();
}

/**
 * @brief 禁用 MMU (Memory Management Unit)
 * @brief Disable MMU (Memory Management Unit)
 *
 * 禁用 MMU 前需要:
 *   1. 清理并无效化 D-Cache
 *   2. 无效化 TLB
 * 以确保内存一致性
 *
 * SCTLR[0] = 0 表示禁用 MMU
 */
void arch_armv7a_disable_mmu(void) {
    arch_armv7a_clean_invalidate_dcache_all();
    arch_armv7a_invalidate_tlb_all();
    uint32_t sctlr;
    __asm__ volatile ("MRC p15, 0, %0, c1, c0, 0" : "=r" (sctlr));
    sctlr &= ~0x1;
    __asm__ volatile ("MCR p15, 0, %0, c1, c0, 0" : : "r" (sctlr) : "memory");
    arch_armv7a_dsb();
    arch_armv7a_isb();
}

/**
 * @brief 设置 TTBR0 (Translation Table Base Register 0)
 * @brief Set TTBR0 (Translation Table Base Register 0)
 *
 * TTBR0 包含第一级页表的基地址
 * 用于 0x00000000 - 0x7FFFFFFF 虚拟地址范围的页表查找
 * 需要 16KB 对齐
 *
 * @param ttbr0 页表基地址
 */
void arch_armv7a_set_ttbr0(uint32_t ttbr0) {
    __asm__ volatile ("MCR p15, 0, %0, c2, c0, 0" : : "r" (ttbr0) : "memory");
    arch_armv7a_dsb();
}

/**
 * @brief 设置 DACR (Domain Access Control Register)
 * @brief Set DACR (Domain Access Control Register)
 *
 * DACR 定义 16 个域的访问权限
 * 每个域占 2 位:
 *   - 00: 无访问权限 (No access)
 *   - 01: 客户端 (Client) - 检查页表中的权限位
 *   - 10: 保留 (Reserved)
 *   - 11: 管理 (Manager) - 无条件允许访问
 *
 * @param dacr 域访问控制值
 */
void arch_armv7a_set_dacr(uint32_t dacr) {
    __asm__ volatile ("MCR p15, 0, %0, c3, c0, 0" : : "r" (dacr) : "memory");
    arch_armv7a_dsb();
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
void arch_armv7a_set_vbar(uint32_t vbar) {
    __asm__ volatile ("MCR p15, 0, %0, c12, c0, 0" : : "r" (vbar) : "memory");
    arch_armv7a_dsb();
}

/**
 * @brief 获取 SCTLR (System Control Register)
 * @return SCTLR 值
 */
uint32_t arch_armv7a_get_sctlr(void) {
    uint32_t result;
    __asm__ volatile ("MRC p15, 0, %0, c1, c0, 0" : "=r" (result));
    return result;
}

/**
 * @brief 设置 SCTLR (System Control Register)
 * @param val: SCTLR 值
 */
void arch_armv7a_set_sctlr(uint32_t val) {
    __asm__ volatile ("MCR p15, 0, %0, c1, c0, 0" : : "r" (val) : "memory");
    arch_armv7a_dsb();
}

/**
 * @brief 获取 TTBR0 (Translation Table Base Register 0)
 * @return TTBR0 值
 */
uint32_t arch_armv7a_get_ttbr0(void) {
    uint32_t result;
    __asm__ volatile ("MRC p15, 0, %0, c2, c0, 0" : "=r" (result));
    return result;
}

/**
 * @brief 获取 DACR (Domain Access Control Register)
 * @return DACR 值
 */
uint32_t arch_armv7a_get_dacr(void) {
    uint32_t result;
    __asm__ volatile ("MRC p15, 0, %0, c3, c0, 0" : "=r" (result));
    return result;
}

/**
 * @brief 获取 VBAR (Vector Base Address Register)
 * @return VBAR 值
 */
uint32_t arch_armv7a_get_vbar(void) {
    uint32_t result;
    __asm__ volatile ("MRC p15, 0, %0, c12, c0, 0" : "=r" (result));
    return result;
}

/**
 * @brief 设置 TTBR1 (Translation Table Base Register 1)
 * @param ttbr1: 页表基地址
 */
void arch_armv7a_set_ttbr1(uint32_t ttbr1) {
    __asm__ volatile ("MCR p15, 0, %0, c2, c0, 1" : : "r" (ttbr1) : "memory");
    arch_armv7a_dsb();
}

/**
 * @brief 获取 TTBR1
 * @return TTBR1 值
 */
uint32_t arch_armv7a_get_ttbr1(void) {
    uint32_t result;
    __asm__ volatile ("MRC p15, 0, %0, c2, c0, 1" : "=r" (result));
    return result;
}

/**
 * @brief 设置 TTBCR (Translation Table Base Control Register)
 * @param ttbcr: TTBCR 值
 */
void arch_armv7a_set_ttbcr(uint32_t ttbcr) {
    __asm__ volatile ("MCR p15, 0, %0, c2, c0, 2" : : "r" (ttbcr) : "memory");
    arch_armv7a_dsb();
}

/**
 * @brief 获取 TTBCR
 * @return TTBCR 值
 */
uint32_t arch_armv7a_get_ttbcr(void) {
    uint32_t result;
    __asm__ volatile ("MRC p15, 0, %0, c2, c0, 2" : "=r" (result));
    return result;
}

/**
 * @brief 获取 DFSR (Data Fault Status Register)
 * @return DFSR 值
 */
uint32_t arch_armv7a_get_dfsr(void) {
    uint32_t result;
    __asm__ volatile ("MRC p15, 0, %0, c5, c0, 0" : "=r" (result));
    return result;
}

/**
 * @brief 获取 IFSR (Instruction Fault Status Register)
 * @return IFSR 值
 */
uint32_t arch_armv7a_get_ifsr(void) {
    uint32_t result;
    __asm__ volatile ("MRC p15, 0, %0, c5, c0, 1" : "=r" (result));
    return result;
}

/**
 * @brief 获取 DFAR (Data Fault Address Register)
 * @return DFAR 值
 */
uint32_t arch_armv7a_get_dfar(void) {
    uint32_t result;
    __asm__ volatile ("MRC p15, 0, %0, c6, c0, 0" : "=r" (result));
    return result;
}

/**
 * @brief 获取 IFAR (Instruction Fault Address Register)
 * @return IFAR 值
 */
uint32_t arch_armv7a_get_ifar(void) {
    uint32_t result;
    __asm__ volatile ("MRC p15, 0, %0, c6, c0, 2" : "=r" (result));
    return result;
}

/**
 * @brief 使能 FPU (浮点单元)
 * @brief Enable FPU (Floating Point Unit)
 *
 * ARMv7-A 支持 VFPv3 (Vector Floating Point) 或 NEON SIMD 单元
 * 需要在 CPACR (Coprocessor Access Control Register) 中使能访问
 *
 * CPACR[20-21]: CP10 (FPU) 控制
 * CPACR[22-23]: CP11 (NEON) 控制
 */
void arch_armv7a_enable_fpu(void) {
    uint32_t cpacr;
    __asm__ volatile ("MRC p15, 0, %0, c1, c0, 2" : "=r" (cpacr));
    cpacr |= (0x3UL << 20) | (0x3UL << 22);
    __asm__ volatile ("MCR p15, 0, %0, c1, c0, 2" : : "r" (cpacr) : "memory");
    arch_armv7a_dsb();
    arch_armv7a_isb();
}

/**
 * @brief 禁用 FPU (浮点单元)
 * @brief Disable FPU (Floating Point Unit)
 *
 * 禁用 FPU 访问以节省功耗或确保代码不使用浮点运算
 */
void arch_armv7a_disable_fpu(void) {
    uint32_t cpacr;
    __asm__ volatile ("MRC p15, 0, %0, c1, c0, 2" : "=r" (cpacr));
    cpacr &= ~((0x3UL << 20) | (0x3UL << 22));
    __asm__ volatile ("MCR p15, 0, %0, c1, c0, 2" : : "r" (cpacr) : "memory");
    arch_armv7a_dsb();
    arch_armv7a_isb();
}

/**
 * @brief 初始化 ARMv7-A 架构
 * @brief Initialize ARMv7-A architecture
 *
 * 执行基本的架构初始化:
 *   1. 数据内存屏障
 *   2. 使能指令缓存
 *   3. 使能数据缓存
 *   4. 使能 FPU
 */
void arch_armv7a_init(void) {
    arch_armv7a_dsb();
    arch_armv7a_dmb();
    arch_armv7a_enable_icache();
    arch_armv7a_enable_dcache();
    arch_armv7a_enable_fpu();
    arch_armv7a_dsb();
    arch_armv7a_dmb();
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
void arch_armv7a_setup_vector_table(void) {
    extern uint32_t _vector_table_base;
    arch_armv7a_set_vbar((uint32_t)&_vector_table_base);
}

/**
 * @brief 初始化用户任务上下文
 * @brief Initialize user task context
 *
 * 创建一个新的任务上下文,设置初始寄存器值
 * 主要用于任务创建或任务切换
 *
 * @param context 任务上下文结构体指针
 * @param entry_point 任务入口地址 (PC)
 * @param arg 传递给任务的参数 (R0)
 */
void arch_armv7a_init_user_context(ArmV7aTaskContext *context, uint32_t entry_point, uint32_t arg) {
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
    context->cpsr = ARM_V7A_MODE_USR;
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
void* arch_armv7a_switch_context(void *from, void *to) {
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
void* arch_armv7a_start_first_task(void *context) {
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
void* arch_armv7a_jump_to_kernel(uint32_t vector_table_addr) {
    (void)vector_table_addr;
    __builtin_unreachable();
}

/*
 * ============================================================================
 * ARMv7-A GIC (Generic Interrupt Controller) 实现
 * ============================================================================
 */

#define GICD_BASE_ADDR     0xFFFEC000UL
#define GICC_BASE_ADDR     0xFFFEC100UL

#define GICD_CTLR         (*(volatile uint32_t *)(GICD_BASE_ADDR + 0x00))
#define GICD_TYPER        (*(volatile uint32_t *)(GICD_BASE_ADDR + 0x04))
#define GICD_IGROUPR(n)   (*(volatile uint32_t *)(GICD_BASE_ADDR + 0x080 + (n) * 4))
#define GICD_ISENABLER(n) (*(volatile uint32_t *)(GICD_BASE_ADDR + 0x100 + (n) * 4))
#define GICD_ICENABLER(n) (*(volatile uint32_t *)(GICD_BASE_ADDR + 0x180 + (n) * 4))
#define GICD_ISPENDR(n)   (*(volatile uint32_t *)(GICD_BASE_ADDR + 0x200 + (n) * 4))
#define GICD_ICPENDR(n)   (*(volatile uint32_t *)(GICD_BASE_ADDR + 0x280 + (n) * 4))
#define GICD_IPRIORITYR(n)(*(volatile uint32_t *)(GICD_BASE_ADDR + 0x400 + (n) * 4))
#define GICD_ITARGETSR(n) (*(volatile uint32_t *)(GICD_BASE_ADDR + 0x800 + (n) * 4))

#define GICC_CTLR         (*(volatile uint32_t *)(GICC_BASE_ADDR + 0x00))
#define GICC_PMR          (*(volatile uint32_t *)(GICC_BASE_ADDR + 0x04))
#define GICC_IAR          (*(volatile uint32_t *)(GICC_BASE_ADDR + 0x0C))
#define GICC_EOIR         (*(volatile uint32_t *)(GICC_BASE_ADDR + 0x10))

/**
 * @brief GIC 初始化
 */
void arch_armv7a_gic_init(void) {
    GICC_CTLR = 0;
    GICD_CTLR = 0;
    arch_armv7a_dsb();
    arch_armv7a_isb();
}

/**
 * @brief GIC 使能
 */
void arch_armv7a_gic_enable(void) {
    GICC_CTLR |= 0x1;
    GICD_CTLR |= 0x1;
    arch_armv7a_dsb();
    arch_armv7a_isb();
}

/**
 * @brief GIC 禁用
 */
void arch_armv7a_gic_disable(void) {
    GICC_CTLR &= ~0x1;
    GICD_CTLR &= ~0x1;
    arch_armv7a_dsb();
}

/**
 * @brief 使能中断
 */
void arch_armv7a_gic_enable_irq(uint32_t irq) {
    if (irq < 32) {
        GICD_ISENABLER(0) = (1U << irq);
    } else {
        GICD_ISENABLER(irq / 32) = (1U << (irq % 32));
    }
    arch_armv7a_dsb();
}

/**
 * @brief 禁用中断
 */
void arch_armv7a_gic_disable_irq(uint32_t irq) {
    if (irq < 32) {
        GICD_ICENABLER(0) = (1U << irq);
    } else {
        GICD_ICENABLER(irq / 32) = (1U << (irq % 32));
    }
    arch_armv7a_dsb();
}

/**
 * @brief 设置中断优先级
 */
void arch_armv7a_gic_set_priority(uint32_t irq, uint32_t priority) {
    uint32_t idx = irq / 4;
    uint32_t shift = (irq % 4) * 8;
    uint32_t val = GICD_IPRIORITYR(idx);
    val = (val & ~(0xFFUL << shift)) | ((priority & 0xFFUL) << shift);
    GICD_IPRIORITYR(idx) = val;
    arch_armv7a_dsb();
}

/**
 * @brief 获取中断优先级
 */
uint32_t arch_armv7a_gic_get_priority(uint32_t irq) {
    uint32_t idx = irq / 4;
    uint32_t shift = (irq % 4) * 8;
    return (GICD_IPRIORITYR(idx) >> shift) & 0xFFUL;
}

/**
 * @brief 设置中断目标 CPU
 */
void arch_armv7a_gic_set_target(uint32_t irq, uint32_t cpu_target) {
    uint32_t idx = irq / 4;
    uint32_t shift = (irq % 4) * 8;
    uint32_t val = GICD_ITARGETSR(idx);
    val = (val & ~(0xFFUL << shift)) | ((cpu_target & 0xFFUL) << shift);
    GICD_ITARGETSR(idx) = val;
    arch_armv7a_dsb();
}

/**
 * @brief 发送软件中断 (SGI)
 */
void arch_armv7a_gic_send_sgi(uint32_t irq, uint32_t cpu_target) {
    if (irq < 16) {
        uint32_t val = (cpu_target << 16) | irq;
        __asm__ volatile ("MCR p15, 0, %0, c12, c11, 0" : : "r" (val) : "memory");
        arch_armv7a_dsb();
    }
}

/**
 * @brief 获取中断待处理状态
 */
uint32_t arch_armv7a_gic_get_pending(uint32_t irq) {
    if (irq < 32) {
        return (GICD_ISPENDR(0) >> irq) & 0x1U;
    }
    return 0;
}

/**
 * @brief 设置中断挂起状态
 */
void arch_armv7a_gic_set_pending(uint32_t irq) {
    if (irq < 32) {
        GICD_ISPENDR(0) = (1U << irq);
    } else {
        GICD_ISPENDR(irq / 32) = (1U << (irq % 32));
    }
    arch_armv7a_dsb();
}

/**
 * @brief 清除中断挂起状态
 */
void arch_armv7a_gic_clear_pending(uint32_t irq) {
    if (irq < 32) {
        GICD_ICPENDR(0) = (1U << irq);
    } else {
        GICD_ICPENDR(irq / 32) = (1U << (irq % 32));
    }
    arch_armv7a_dsb();
}

/**
 * @brief 获取当前正在执行的中断
 */
uint32_t arch_armv7a_gic_get_active_irq(void) {
    uint32_t iar = GICC_IAR;
    return iar & 0x3FFUL;
}

/*
 * ============================================================================
 * ARMv7-A Generic Timer 实现
 * ============================================================================
 */

/**
 * @brief 获取CNTFRQ 寄存器 (计数频率)
 */
uint64_t arch_armv7a_get_cntfrq(void) {
    uint64_t result;
    __asm__ volatile ("MRS %0, CNTFRQ_EL0" : "=r" (result));
    return result;
}

/**
 * @brief 设置CNTFRQ 寄存器 (计数频率)
 */
void arch_armv7a_set_cntfrq(uint64_t freq) {
    __asm__ volatile ("MSR CNTFRQ_EL0, %0" : : "r" (freq) : "memory");
}

/**
 * @brief 获取 CNTPCT 寄存器 (物理计数器)
 */
uint64_t arch_armv7a_get_cntpct(void) {
    uint64_t result;
    __asm__ volatile ("MRS %0, CNTPCT_EL0" : "=r" (result));
    return result;
}

/**
 * @brief 获取 CNTVCT 寄存器 (虚拟计数器)
 */
uint64_t arch_armv7a_get_cntvct(void) {
    uint64_t result;
    __asm__ volatile ("MRS %0, CNTVCT_EL0" : "=r" (result));
    return result;
}

/**
 * @brief 获取 CNTP_TVAL 寄存器 (物理定时器值)
 */
uint32_t arch_armv7a_get_cntp_tval(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, CNTP_TVAL_EL0" : "=r" (result));
    return result;
}

/**
 * @brief 设置 CNTP_TVAL 寄存器 (物理定时器值)
 */
void arch_armv7a_set_cntp_tval(uint32_t value) {
    __asm__ volatile ("MSR CNTP_TVAL_EL0, %0" : : "r" (value) : "memory");
}

/**
 * @brief 获取 CNTP_CTL 寄存器 (物理定时器控制)
 */
uint32_t arch_armv7a_get_cntp_ctl(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, CNTP_CTL_EL0" : "=r" (result));
    return result;
}

/**
 * @brief 设置 CNTP_CTL 寄存器 (物理定时器控制)
 */
void arch_armv7a_set_cntp_ctl(uint32_t value) {
    __asm__ volatile ("MSR CNTP_CTL_EL0, %0" : : "r" (value) : "memory");
}

/**
 * @brief 获取 CNTV_TVAL 寄存器 (虚拟定时器值)
 */
uint32_t arch_armv7a_get_cntv_tval(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, CNTV_TVAL_EL0" : "=r" (result));
    return result;
}

/**
 * @brief 设置 CNTV_TVAL 寄存器 (虚拟定时器值)
 */
void arch_armv7a_set_cntv_tval(uint32_t value) {
    __asm__ volatile ("MSR CNTV_TVAL_EL0, %0" : : "r" (value) : "memory");
}

/**
 * @brief 获取 CNTV_CTL 寄存器 (虚拟定时器控制)
 */
uint32_t arch_armv7a_get_cntv_ctl(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, CNTV_CTL_EL0" : "=r" (result));
    return result;
}

/**
 * @brief 设置 CNTV_CTL 寄存器 (虚拟定时器控制)
 */
void arch_armv7a_set_cntv_ctl(uint32_t value) {
    __asm__ volatile ("MSR CNTV_CTL_EL0, %0" : : "r" (value) : "memory");
}
