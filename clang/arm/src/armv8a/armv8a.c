/*
 * FeatherCore Architecture - ARMv8-A Implementation
 * FeatherCore 架构 - ARMv8-A 实现
 *
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2024 FeatherCore Team. All rights reserved.
 *
 * Description:
 *   This file provides ARMv8-A architecture-specific implementations.
 *   ARMv8-A is the 64-bit Application profile, supporting AArch64 (64-bit)
 *   and AArch32 (32-bit) execution states. It is designed for high-performance
 *   applications like smartphones, servers, and embedded systems.
 *   支持的功能包括:
 *     - 64位寄存器访问 (X0-X30, SP, PC)
 *     - 异常级别 (EL0-EL3) 管理
 *     - 系统寄存器访问 (SCTLR_EL1, TCR_EL1, TTBR0_EL1, etc.)
 *     - 中断管理 (DAIF)
 *     - 内存屏障指令 (DSB, DMB, ISB)
 *     - 低功耗指令 (WFI, WFE, SEV)
 *     - 缓存管理 (I-Cache, D-Cache)
 *     - MMU 管理 (EL1)
 *     - FPU/SIMD 管理 (CPACR_EL1)
 *     - 任务上下文管理
 *
 * Supported Devices:
 *   - Cortex-A34, Cortex-A35, Cortex-A53, Cortex-A55
 *   - Cortex-A57, Cortex-A72, Cortex-A73, Cortex-A75, Cortex-A76
 *   - Cortex-A77, Cortex-A78, Cortex-A710, Cortex-A715
 *   - Cortex-A520, Cortex-A720, Cortex-A725
 */

#include "armv8a.h"
#include <stdint.h>

/**
 * @brief 获取当前异常级别 (CurrentEL)
 * @brief Get Current Exception Level
 *
 * ARMv8-A 有 4 个异常级别 (Exception Levels):
 *   - EL0: 用户态 (User mode)
 *   - EL1: 内核态/超级用户 (Kernel/Supervisor mode)
 *   - EL2: 虚拟机监控器 (Hypervisor)
 *   - EL3: 安全监控器 (Secure Monitor)
 *
 * 返回值:
 *   - 0b00: EL0
 *   - 0b01: EL1
 *   - 0b10: EL2
 *   - 0b11: EL3
 *
 * @return uint64_t 当前异常级别
 */
uint64_t arch_armv8a_get_currentel(void) {
    uint64_t result;
    __asm__ volatile ("MRS %0, CurrentEL" : "=r" (result));
    return result;
}

/**
 * @brief 获取 SCTLR_EL1 (System Control Register, EL1)
 * @brief Get SCTLR_EL1 (System Control Register, EL1)
 *
 * SCTLR_EL1 是 EL1 级别的系统控制寄存器,包含:
 *   - M: MMU 使能位
 *   - A: 对齐检查使能位
 *   - C: D-Cache 使能位
 *   - I: I-Cache 使能位
 *   - WXN: Write-permanent XN
 *   - nTWE: Trap WFE
 *   - 等等
 *
 * @return uint64_t SCTLR_EL1 的值
 */
uint64_t arch_armv8a_get_sctlr_el1(void) {
    uint64_t result;
    __asm__ volatile ("MRS %0, SCTLR_EL1" : "=r" (result));
    return result;
}

/**
 * @brief 设置 SCTLR_EL1 (System Control Register, EL1)
 * @brief Set SCTLR_EL1 (System Control Register, EL1)
 *
 * @param val 要设置的 SCTLR_EL1 值
 */
void arch_armv8a_set_sctlr_el1(uint64_t val) {
    __asm__ volatile ("MSR SCTLR_EL1, %0" : : "r" (val) : "memory");
}

/**
 * @brief 获取 TCR_EL1 (Translation Control Register, EL1)
 * @brief Get TCR_EL1 (Translation Control Register, EL1)
 *
 * TCR_EL1 控制页表转换:
 *   - T0SZ: TTBR0_EL1 转换表大小
 *   - T1SZ: TTBR1_EL1 转换表大小
 *   - IRGN0/1: 内部缓存共享属性
 *   - ORGN0/1: 外部缓存共享属性
 *   - SH0/1: 可共享属性
 *   - TG0/1: 页大小 (4KB, 16KB, 64KB)
 *   - IPS: 中间物理地址宽度
 *
 * @return uint64_t TCR_EL1 的值
 */
uint64_t arch_armv8a_get_tcr_el1(void) {
    uint64_t result;
    __asm__ volatile ("MRS %0, TCR_EL1" : "=r" (result));
    return result;
}

/**
 * @brief 设置 TCR_EL1 (Translation Control Register, EL1)
 * @brief Set TCR_EL1 (Translation Control Register, EL1)
 *
 * @param val 要设置的 TCR_EL1 值
 */
void arch_armv8a_set_tcr_el1(uint64_t val) {
    __asm__ volatile ("MSR TCR_EL1, %0" : : "r" (val) : "memory");
}

/**
 * @brief 获取 TTBR0_EL1 (Translation Table Base Register 0, EL1)
 * @brief Get TTBR0_EL1 (Translation Table Base Register 0, EL1)
 *
 * TTBR0_EL1 包含第一级页表的基地址
 * 用于 0x0000FFFF_FFFFFFFF 以下地址的转换
 *
 * @return uint64_t TTBR0_EL1 的值
 */
uint64_t arch_armv8a_get_ttbr0_el1(void) {
    uint64_t result;
    __asm__ volatile ("MRS %0, TTBR0_EL1" : "=r" (result));
    return result;
}

/**
 * @brief 设置 TTBR0_EL1 (Translation Table Base Register 0, EL1)
 * @brief Set TTBR0_EL1 (Translation Table Base Register 0, EL1)
 *
 * @param val 页表基地址
 */
void arch_armv8a_set_ttbr0_el1(uint64_t val) {
    __asm__ volatile ("MSR TTBR0_EL1, %0" : : "r" (val) : "memory");
}

/**
 * @brief 获取 MAIR_EL1 (Memory Attribute Indirection Register, EL1)
 * @brief Get MAIR_EL1 (Memory Attribute Indirection Register, EL1)
 *
 * MAIR_EL1 定义内存属性索引 (Attr0-Attr7)
 * 每个 Attr 可以配置为:
 *   - Strongly Ordered
 *   - Device
 *   - Normal (Write-Through/Write-Back, Read-Allocate/Write-Allocate)
 *
 * @return uint64_t MAIR_EL1 的值
 */
uint64_t arch_armv8a_get_mair_el1(void) {
    uint64_t result;
    __asm__ volatile ("MRS %0, MAIR_EL1" : "=r" (result));
    return result;
}

/**
 * @brief 设置 MAIR_EL1 (Memory Attribute Indirection Register, EL1)
 * @brief Set MAIR_EL1 (Memory Attribute Indirection Register, EL1)
 *
 * @param val 内存属性配置
 */
void arch_armv8a_set_mair_el1(uint64_t val) {
    __asm__ volatile ("MSR MAIR_EL1, %0" : : "r" (val) : "memory");
}

/**
 * @brief 获取 VBAR_EL1 (Vector Base Address Register, EL1)
 * @brief Get VBAR_EL1 (Vector Base Address Register, EL1)
 *
 * VBAR_EL1 定义 EL1 级别的异常向量基地址
 *
 * @return uint64_t VBAR_EL1 的值
 */
uint64_t arch_armv8a_get_vbar_el1(void) {
    uint64_t result;
    __asm__ volatile ("MRS %0, VBAR_EL1" : "=r" (result));
    return result;
}

/**
 * @brief 设置 VBAR_EL1 (Vector Base Address Register, EL1)
 * @brief Set VBAR_EL1 (Vector Base Address Register, EL1)
 *
 * @param val 异常向量基地址
 */
void arch_armv8a_set_vbar_el1(uint64_t val) {
    __asm__ volatile ("MSR VBAR_EL1, %0" : : "r" (val) : "memory");
}

/**
 * @brief 获取 SPSR_EL1 (Saved Program Status Register, EL1)
 * @brief Get SPSR_EL1 (Saved Program Status Register, EL1)
 *
 * SPSR_EL1 保存从异常返回时的处理器状态
 *
 * @return uint64_t SPSR_EL1 的值
 */
uint64_t arch_armv8a_get_spsr_el1(void) {
    uint64_t result;
    __asm__ volatile ("MRS %0, SPSR_EL1" : "=r" (result));
    return result;
}

/**
 * @brief 设置 SPSR_EL1 (Saved Program Status Register, EL1)
 * @brief Set SPSR_EL1 (Saved Program Status Register, EL1)
 *
 * @param val 要保存的处理器状态
 */
void arch_armv8a_set_spsr_el1(uint64_t val) {
    __asm__ volatile ("MSR SPSR_EL1, %0" : : "r" (val) : "memory");
}

/**
 * @brief 获取 ELR_EL1 (Exception Link Register, EL1)
 * @brief Get ELR_EL1 (Exception Link Register, EL1)
 *
 * ELR_EL1 保存异常返回地址
 *
 * @return uint64_t ELR_EL1 的值
 */
uint64_t arch_armv8a_get_elr_el1(void) {
    uint64_t result;
    __asm__ volatile ("MRS %0, ELR_EL1" : "=r" (result));
    return result;
}

/**
 * @brief 设置 ELR_EL1 (Exception Link Register, EL1)
 * @brief Set ELR_EL1 (Exception Link Register, EL1)
 *
 * @param val 异常返回地址
 */
void arch_armv8a_set_elr_el1(uint64_t val) {
    __asm__ volatile ("MSR ELR_EL1, %0" : : "r" (val) : "memory");
}

/**
 * @brief 使能 EL1 级别的指令缓存 (I-Cache)
 * @brief Enable EL1 Instruction Cache (I-Cache)
 *
 * 通过设置 SCTLR_EL1 的 I 位 (bit 12)
 */
void arch_armv8a_enable_icache_el1(void) {
    uint64_t sctlr = arch_armv8a_get_sctlr_el1();
    sctlr |= (1UL << 12);
    arch_armv8a_set_sctlr_el1(sctlr);
    arch_armv8a_dsb();
    arch_armv8a_isb();
}

/**
 * @brief 禁用 EL1 级别的指令缓存 (I-Cache)
 * @brief Disable EL1 Instruction Cache (I-Cache)
 */
void arch_armv8a_disable_icache_el1(void) {
    uint64_t sctlr = arch_armv8a_get_sctlr_el1();
    sctlr &= ~(1UL << 12);
    arch_armv8a_set_sctlr_el1(sctlr);
    arch_armv8a_dsb();
    arch_armv8a_isb();
}

/**
 * @brief 使能 EL1 级别的数据缓存 (D-Cache)
 * @brief Enable EL1 Data Cache (D-Cache)
 *
 * 通过设置 SCTLR_EL1 的 C 位 (bit 2)
 */
void arch_armv8a_enable_dcache_el1(void) {
    uint64_t sctlr = arch_armv8a_get_sctlr_el1();
    sctlr |= (1UL << 2);
    arch_armv8a_set_sctlr_el1(sctlr);
    arch_armv8a_dsb();
    arch_armv8a_isb();
}

/**
 * @brief 禁用 EL1 级别的数据缓存 (D-Cache)
 * @brief Disable EL1 Data Cache (D-Cache)
 */
void arch_armv8a_disable_dcache_el1(void) {
    uint64_t sctlr = arch_armv8a_get_sctlr_el1();
    sctlr &= ~(1UL << 2);
    arch_armv8a_set_sctlr_el1(sctlr);
    arch_armv8a_dsb();
    arch_armv8a_isb();
}

/**
 * @brief 使能 EL1 级别的 MMU
 * @brief Enable EL1 MMU
 *
 * 启用 MMU 前需要先设置:
 *   - TTBR0_EL1 (页表基地址)
 *   - TCR_EL1 (转换控制)
 *   - MAIR_EL1 (内存属性)
 *
 * SCTLR_EL1[0] = 1 表示启用 MMU
 */
void arch_armv8a_enable_mmu_el1(void) {
    uint64_t sctlr = arch_armv8a_get_sctlr_el1();
    sctlr |= 0x1;
    arch_armv8a_set_sctlr_el1(sctlr);
    arch_armv8a_dsb();
    arch_armv8a_isb();
}

/**
 * @brief 禁用 EL1 级别的 MMU
 * @brief Disable EL1 MMU
 */
void arch_armv8a_disable_mmu_el1(void) {
    uint64_t sctlr = arch_armv8a_get_sctlr_el1();
    sctlr &= ~0x1;
    arch_armv8a_set_sctlr_el1(sctlr);
    arch_armv8a_dsb();
    arch_armv8a_isb();
}

/**
 * @brief 无效化 EL1 级别的所有 TLB 条目
 * @brief Invalidate all EL1 TLB entries
 *
 * TLBI VMALLE1 - TLB Invalidate All, EL1
 * 在修改页表后需要调用此函数使 TLB 失效
 */
void arch_armv8a_tlbi_vmalle1(void) {
    __asm__ volatile ("tlbi vmalle1" : : : "memory");
    arch_armv8a_dsb();
    arch_armv8a_isb();
}

/**
 * @brief DSB (Data Synchronization Barrier) - 数据同步屏障
 * @brief Data Synchronization Barrier
 *
 * 确保所有之前的内存访问指令都完成后再执行后续指令
 * 'sy' 表示系统级别的同步
 */
void arch_armv8a_dsb(void) {
    __asm__ volatile ("dsb sy" : : : "memory");
}

/**
 * @brief ISB (Instruction Synchronization Barrier) - 指令同步屏障
 * @brief Instruction Synchronization Barrier
 *
 * 刷新流水线,确保所有之前的指令都执行完成
 * ISB 会清空流水线并重新取指
 */
void arch_armv8a_isb(void) {
    __asm__ volatile ("isb sy" : : : "memory");
}

/**
 * @brief DMB (Data Memory Barrier) - 数据内存屏障
 * @brief Data Memory Barrier
 *
 * 确保所有之前的内存访问指令都完成后再执行后续内存访问指令
 */
void arch_armv8a_dmb(void) {
    __asm__ volatile ("dmb sy" : : : "memory");
}

/**
 * @brief WFI (Wait For Interrupt) - 等待中断
 * @brief Wait For Interrupt
 *
 * 使处理器进入低功耗状态,直到发生中断或其他唤醒事件
 */
void arch_armv8a_wfi(void) {
    __asm__ volatile ("wfi" : : : "memory");
}

/**
 * @brief WFE (Wait For Event) - 等待事件
 * @brief Wait For Event
 *
 * 使处理器进入低功耗状态,直到发生事件
 * 用于多处理器之间的同步
 */
void arch_armv8a_wfe(void) {
    __asm__ volatile ("wfe" : : : "memory");
}

/**
 * @brief SEV (Send Event) - 发送事件
 * @brief Send Event
 *
 * 向所有处理器发送事件信号
 */
void arch_armv8a_sev(void) {
    __asm__ volatile ("sev" : : : "memory");
}

/**
 * @brief 使能 IRQ 中断
 * @brief Enable IRQ interrupt
 *
 * 通过清除 DAIF 寄存器的 I 位 (bit 1)
 * DAIF[1]: I - IRQ 中断掩码
 */
void arch_armv8a_enable_irq(void) {
    __asm__ volatile ("msr daifclr, #0x2" : : : "memory");
}

/**
 * @brief 禁用 IRQ 中断
 * @brief Disable IRQ interrupt
 *
 * 通过设置 DAIF 寄存器的 I 位 (bit 1)
 */
void arch_armv8a_disable_irq(void) {
    __asm__ volatile ("msr daifset, #0x2" : : : "memory");
}

/**
 * @brief 使能 FPU 和 SIMD 单元
 * @brief Enable FPU and SIMD unit
 *
 * 通过设置 CPACR_EL1 (Coprocessor Access Control Register)
 * CPACR_EL1[20-21]: CP10 (FPU) 控制
 * CPACR_EL1[22-23]: CP11 (SIMD) 控制
 * 0x3 = Full access (PL0 and PL1)
 */
void arch_armv8a_enable_fpu(void) {
    uint64_t cpacr;
    __asm__ volatile ("MRS %0, CPACR_EL1" : "=r" (cpacr));
    cpacr |= (0x3UL << 20) | (0x3UL << 22);
    __asm__ volatile ("MSR CPACR_EL1, %0" : : "r" (cpacr) : "memory");
    arch_armv8a_dsb();
    arch_armv8a_isb();
}

/**
 * @brief 禁用 FPU 和 SIMD 单元
 * @brief Disable FPU and SIMD unit
 */
void arch_armv8a_disable_fpu(void) {
    uint64_t cpacr;
    __asm__ volatile ("MRS %0, CPACR_EL1" : "=r" (cpacr));
    cpacr &= ~((0x3UL << 20) | (0x3UL << 22));
    __asm__ volatile ("MSR CPACR_EL1, %0" : : "r" (cpacr) : "memory");
    arch_armv8a_dsb();
    arch_armv8a_isb();
}

/**
 * @brief 初始化 ARMv8-A 架构
 * @brief Initialize ARMv8-A architecture
 *
 * 执行基本的架构初始化:
 *   1. 数据同步屏障 (DSB)
 *   2. 数据内存屏障 (DMB)
 *   3. 使能指令缓存
 *   4. 使能数据缓存
 *   5. 使能 FPU/SIMD
 *   6. 数据同步屏障
 *   7. 数据内存屏障
 */
void arch_armv8a_init(void) {
    arch_armv8a_dsb();
    arch_armv8a_dmb();
    arch_armv8a_enable_icache_el1();
    arch_armv8a_enable_dcache_el1();
    arch_armv8a_enable_fpu();
    arch_armv8a_dsb();
    arch_armv8a_dmb();
}

/**
 * @brief 设置异常向量表
 * @brief Setup Vector Table
 *
 * 将 VBAR_EL1 设置为应用程序的向量表基地址
 */
void arch_armv8a_setup_vector_table(void) {
    extern uint64_t _vector_table_base;
    arch_armv8a_set_vbar_el1((uint64_t)&_vector_table_base);
}

/**
 * @brief 初始化用户任务上下文
 * @brief Initialize user task context
 *
 * 创建一个新的 64 位任务上下文,设置初始寄存器值
 *
 * ARMv8-A AArch64 寄存器:
 *   - X0-X7: 参数寄存器
 *   - X8: 子程序返回地址
 *   - X9-X15: 临时寄存器
 *   - X16-X17: IP0, IP1 (Intra-Procedure Call)
 *   - X18: 平台寄存器
 *   - X19-X28: 保存的寄存器
 *   - X29: Frame Pointer (FP)
 *   - X30: Link Register (LR)
 *   - SP: Stack Pointer
 *
 * @param context 任务上下文结构体指针
 * @param entry_point 任务入口地址 (PC -> ELR_EL1)
 * @param arg 传递给任务的参数 (X0)
 */
void arch_armv8a_init_user_context(ArmV8aTaskContext *context, uint64_t entry_point, uint64_t arg) {
    if (context == NULL) {
        return;
    }
    context->x0 = arg;
    context->x1 = 0;
    context->x2 = 0;
    context->x3 = 0;
    context->x4 = 0;
    context->x5 = 0;
    context->x6 = 0;
    context->x7 = 0;
    context->x8 = 0;
    context->x9 = 0;
    context->x10 = 0;
    context->x11 = 0;
    context->x12 = 0;
    context->x13 = 0;
    context->x14 = 0;
    context->x15 = 0;
    context->x16 = 0;
    context->x17 = 0;
    context->x18 = 0;
    context->x19 = 0;
    context->x20 = 0;
    context->x21 = 0;
    context->x22 = 0;
    context->x23 = 0;
    context->x24 = 0;
    context->x25 = 0;
    context->x26 = 0;
    context->x27 = 0;
    context->x28 = 0;
    context->elr_el1 = entry_point;
    context->spsr_el1 = 0;
}

/**
 * @brief 切换任务上下文
 * @brief Switch task context
 *
 * 保存当前任务状态并恢复目标任务状态
 *
 * @param from 保存当前任务的上下文
 * @param to 目标任务的上下文
 * @return void* 指向被保存上下文的指针
 */
void* arch_armv8a_switch_context(void *from, void *to) {
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
void* arch_armv8a_start_first_task(void *context) {
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
void* arch_armv8a_jump_to_kernel(uint64_t vector_table_addr) {
    (void)vector_table_addr;
    __builtin_unreachable();
}

/*
 * ============================================================================
 * ARMv8-A GICv2/GICv3 实现
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
void arch_armv8a_gic_init(void) {
    GICC_CTLR = 0;
    GICD_CTLR = 0;
    arch_armv8a_dsb();
    arch_armv8a_isb();
}

/**
 * @brief GIC 使能
 */
void arch_armv8a_gic_enable(void) {
    GICC_CTLR |= 0x1;
    GICD_CTLR |= 0x1;
    arch_armv8a_dsb();
    arch_armv8a_isb();
}

/**
 * @brief GIC 禁用
 */
void arch_armv8a_gic_disable(void) {
    GICC_CTLR &= ~0x1;
    GICD_CTLR &= ~0x1;
    arch_armv8a_dsb();
}

/**
 * @brief 使能中断
 */
void arch_armv8a_gic_enable_irq(uint32_t irq) {
    if (irq < 32) {
        GICD_ISENABLER(0) = (1U << irq);
    } else {
        GICD_ISENABLER(irq / 32) = (1U << (irq % 32));
    }
    arch_armv8a_dsb();
}

/**
 * @brief 禁用中断
 */
void arch_armv8a_gic_disable_irq(uint32_t irq) {
    if (irq < 32) {
        GICD_ICENABLER(0) = (1U << irq);
    } else {
        GICD_ICENABLER(irq / 32) = (1U << (irq % 32));
    }
    arch_armv8a_dsb();
}

/**
 * @brief 设置中断优先级
 */
void arch_armv8a_gic_set_priority(uint32_t irq, uint32_t priority) {
    uint32_t idx = irq / 4;
    uint32_t shift = (irq % 4) * 8;
    uint32_t val = GICD_IPRIORITYR(idx);
    val = (val & ~(0xFFUL << shift)) | ((priority & 0xFFUL) << shift);
    GICD_IPRIORITYR(idx) = val;
    arch_armv8a_dsb();
}

/**
 * @brief 获取中断优先级
 */
uint32_t arch_armv8a_gic_get_priority(uint32_t irq) {
    uint32_t idx = irq / 4;
    uint32_t shift = (irq % 4) * 8;
    return (GICD_IPRIORITYR(idx) >> shift) & 0xFFUL;
}

/**
 * @brief 设置中断目标 CPU
 */
void arch_armv8a_gic_set_target(uint32_t irq, uint32_t cpu_target) {
    uint32_t idx = irq / 4;
    uint32_t shift = (irq % 4) * 8;
    uint32_t val = GICD_ITARGETSR(idx);
    val = (val & ~(0xFFUL << shift)) | ((cpu_target & 0xFFUL) << shift);
    GICD_ITARGETSR(idx) = val;
    arch_armv8a_dsb();
}

/**
 * @brief 发送软件中断 (SGI)
 */
void arch_armv8a_gic_send_sgi(uint32_t irq, uint32_t cpu_target) {
    if (irq < 16) {
        uint64_t val = ((uint64_t)cpu_target << 48) | irq;
        __asm__ volatile ("MRS %0, ICC_SGI1R_EL1" : "=r" (val));
        val = ((uint64_t)cpu_target << 48) | irq;
        __asm__ volatile ("MSR ICC_SGI1R_EL1, %0" : : "r" (val) : "memory");
        arch_armv8a_dsb();
    }
}

/**
 * @brief 获取中断待处理状态
 */
uint32_t arch_armv8a_gic_get_pending(uint32_t irq) {
    if (irq < 32) {
        return (GICD_ISPENDR(0) >> irq) & 0x1U;
    }
    return 0;
}

/**
 * @brief 设置中断挂起状态
 */
void arch_armv8a_gic_set_pending(uint32_t irq) {
    if (irq < 32) {
        GICD_ISPENDR(0) = (1U << irq);
    } else {
        GICD_ISPENDR(irq / 32) = (1U << (irq % 32));
    }
    arch_armv8a_dsb();
}

/**
 * @brief 清除中断挂起状态
 */
void arch_armv8a_gic_clear_pending(uint32_t irq) {
    if (irq < 32) {
        GICD_ICPENDR(0) = (1U << irq);
    } else {
        GICD_ICPENDR(irq / 32) = (1U << (irq % 32));
    }
    arch_armv8a_dsb();
}

/**
 * @brief 获取当前正在执行的中断
 */
uint32_t arch_armv8a_gic_get_active_irq(void) {
    uint32_t iar = GICC_IAR;
    return iar & 0x3FFUL;
}

/*
 * ============================================================================
 * ARMv8-A Generic Timer 实现
 * ============================================================================
 */

/**
 * @brief 获取CNTFRQ 寄存器 (计数频率)
 */
uint64_t arch_armv8a_get_cntfrq(void) {
    uint64_t result;
    __asm__ volatile ("MRS %0, CNTFRQ_EL0" : "=r" (result));
    return result;
}

/**
 * @brief 设置CNTFRQ 寄存器 (计数频率)
 */
void arch_armv8a_set_cntfrq(uint64_t freq) {
    __asm__ volatile ("MSR CNTFRQ_EL0, %0" : : "r" (freq) : "memory");
}

/**
 * @brief 获取 CNTPCT 寄存器 (物理计数器)
 */
uint64_t arch_armv8a_get_cntpct(void) {
    uint64_t result;
    __asm__ volatile ("MRS %0, CNTPCT_EL0" : "=r" (result));
    return result;
}

/**
 * @brief 获取 CNTVCT 寄存器 (虚拟计数器)
 */
uint64_t arch_armv8a_get_cntvct(void) {
    uint64_t result;
    __asm__ volatile ("MRS %0, CNTVCT_EL0" : "=r" (result));
    return result;
}

/**
 * @brief 获取 CNTP_TVAL 寄存器 (物理定时器值)
 */
uint32_t arch_armv8a_get_cntp_tval(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, CNTP_TVAL_EL0" : "=r" (result));
    return result;
}

/**
 * @brief 设置 CNTP_TVAL 寄存器 (物理定时器值)
 */
void arch_armv8a_set_cntp_tval(uint32_t value) {
    __asm__ volatile ("MSR CNTP_TVAL_EL0, %0" : : "r" (value) : "memory");
}

/**
 * @brief 获取 CNTP_CTL 寄存器 (物理定时器控制)
 */
uint32_t arch_armv8a_get_cntp_ctl(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, CNTP_CTL_EL0" : "=r" (result));
    return result;
}

/**
 * @brief 设置 CNTP_CTL 寄存器 (物理定时器控制)
 */
void arch_armv8a_set_cntp_ctl(uint32_t value) {
    __asm__ volatile ("MSR CNTP_CTL_EL0, %0" : : "r" (value) : "memory");
}

/**
 * @brief 获取 CNTV_TVAL 寄存器 (虚拟定时器值)
 */
uint32_t arch_armv8a_get_cntv_tval(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, CNTV_TVAL_EL0" : "=r" (result));
    return result;
}

/**
 * @brief 设置 CNTV_TVAL 寄存器 (虚拟定时器值)
 */
void arch_armv8a_set_cntv_tval(uint32_t value) {
    __asm__ volatile ("MSR CNTV_TVAL_EL0, %0" : : "r" (value) : "memory");
}

/**
 * @brief 获取 CNTV_CTL 寄存器 (虚拟定时器控制)
 */
uint32_t arch_armv8a_get_cntv_ctl(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, CNTV_CTL_EL0" : "=r" (result));
    return result;
}

/**
 * @brief 设置 CNTV_CTL 寄存器 (虚拟定时器控制)
 */
void arch_armv8a_set_cntv_ctl(uint32_t value) {
    __asm__ volatile ("MSR CNTV_CTL_EL0, %0" : : "r" (value) : "memory");
}
