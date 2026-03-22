/*
 * ARM Architecture - ARMv7-M (Cortex-M3/M4) Support
 *
 * ============================================================================
 * File: armv7m.h
 * Description: ARMv7-M architecture specific definitions and function declarations
 * 描述: ARMv7-M 架构特定定义和函数声明
 *
 * ARMv7-M Architecture Overview:
 *   ARMv7-M is a high-performance microcontroller architecture widely used in
 *   industrial control, automotive electronics and other fields.
 *   ARMv7-M 是高性能微控制器架构，广泛应用于工业控制、汽车电子等领域。
 *
 *   It supports the full Thumb-2 instruction set with DSP extension and
 *   optional floating point unit.
 *   支持完整的 Thumb-2 指令集，具有 DSP 扩展和可选的浮点单元。
 *
 * Supported Processors:
 *   - Cortex-M3: Classic ARMv7-M processor, 3-stage pipeline, widely used
 *   - Cortex-M4: ARMv7-EM processor, 3-stage pipeline, supports DSP and optional FPU
 *
 * Key Features:
 *   - 3-stage pipeline (Cortex-M3) / 6-stage pipeline (Cortex-M4)
 *   - Thumb-2 instruction set
 *   - Nested Vector Interrupt Controller (NVIC), up to 256 interrupts
 *   - Memory Protection Unit (MPU)
 *   - Optional FPU (single precision) - Cortex-M4
 *   - DSP instruction extension - Cortex-M4
 *   - Bit operation instructions (BB, BLX, etc.)
 *   - Hardware multiplier (32/64 bit)
 *   - Debug components (DWT, ITM, FPB)
 *
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 FeatherCore Team. All rights reserved.
 */

#ifndef __ARCH_ARM_V7M_H__
#define __ARCH_ARM_V7M_H__

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * ARMv7-M Configuration Macros
 * ARMv7-M 配置宏定义
 * ============================================================================
 */

/**
 * ARMv7-M Architecture Identifier
 * ARMv7-M 架构标识符
 */
#define __ARM_ARCH_V7M__ 1

/**
 * MPU Present Flag: 1 = MPU is present
 * MPU 存在标志: 1 = MPU 存在
 */
#define __MPU_PRESENT             1U

/**
 * VTOR Present Flag: 1 = Vector Table Offset Register is present
 * VTOR 存在标志: 1 = 向量表偏移寄存器存在
 */
#define __VTOR_PRESENT            1U

/**
 * Number of Priority Bits: 4 bits for priority (0-15)
 * 优先级位数: 4 位优先级 (0-15)
 */
#define __NVIC_PRIO_BITS          4U

/**
 * Vendor SysTick Config: 0 = Use standard implementation
 * 供应商 SysTick 配置: 0 = 使用标准实现
 */
#define __Vendor_SysTickConfig    0U

/**
 * FPU Present: 1 = FPU is present (Cortex-M4)
 * FPU 存在: 1 = FPU 存在 (Cortex-M4)
 */
#define __FPU_PRESENT             1U

/**
 * FPU Double Precision: 0 = Single precision only
 * FPU 双精度: 0 = 仅单精度
 */
#define __FPU_DP                 0U

/**
 * Number of interrupts supported
 * 支持的中断数量
 */
#define __ARM_NUM_INTERRUPTS      256U

/*
 * ============================================================================
 * ARMv7-M Task Context Structure
 * ARMv7-M 任务上下文结构体
 *
 * Task context is used to save and restore task execution state.
 * ARMv7-M has more registers than ARMv6-M.
 * 任务上下文用于保存和恢复任务执行状态。
 * ARMv7-M 比 ARMv6-M 有更多的寄存器。
 *
 * Members:
 *   r0-r12: General purpose registers (通用寄存器)
 *   sp:     Stack Pointer (栈指针)
 *   lr:     Link Register (连接寄存器)
 *   pc:     Program Counter (程序计数器)
 *   xpsr:   Program Status Register (程序状态寄存器)
 *   control: Control Register (控制寄存器)
 *   primask: Priority Mask Register (中断屏蔽寄存器)
 *   basepri: Base Priority Register (基础优先级屏蔽寄存器)
 *   faultmask: Fault Mask Register (故障屏蔽寄存器)
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
    uint32_t basepri;
    uint32_t faultmask;
} ArmV7mTaskContext;

/*
 * ============================================================================
 * ARMv7-M Exception Frame Structure
 * ARMv7-M 异常帧结构体
 *
 * When an exception occurs, the CPU automatically pushes the following
 * registers onto the stack:
 * 当异常发生时，CPU 自动将以下寄存器压入栈:
 *   r0, r1, r2, r3, r12, lr, pc, xpsr
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
} ArmV7mExceptionFrame;

/*
 * ============================================================================
 * ARMv7-M Core Register Access Functions Declaration
 * ARMv7-M 核心寄存器访问函数声明
 */

/**
 * @brief Get CONTROL register value
 * @brief 获取 CONTROL 寄存器值
 *
 * CONTROL register controls:
 * CONTROL 寄存器控制:
 *   - BIT[0]: nPRIV - Privilege level (0=privileged, 1=user)
 *   - BIT[1]: SPSEL - Stack pointer select (0=MSP, 1=PSP)
 *   - BIT[2]: FPCA - FPU active state (M4 only)
 *
 * @return Current CONTROL register value
 * @return CONTROL 寄存器当前值
 */
uint32_t arch_armv7m_get_control(void);

/**
 * @brief Set CONTROL register value
 * @brief 设置 CONTROL 寄存器值
 *
 * @param control: New CONTROL register value
 * @param control: CONTROL 寄存器新值
 */
void arch_armv7m_set_control(uint32_t control);

/**
 * @brief Get Main Stack Pointer (MSP)
 * @brief 获取主栈指针 (MSP)
 *
 * @return Current MSP value
 * @return MSP 当前值
 */
uint32_t arch_armv7m_get_msp(void);

/**
 * @brief Set Main Stack Pointer (MSP)
 * @brief 设置主栈指针 (MSP)
 *
 * @param msp: New MSP value
 * @param msp: MSP 新值
 */
void arch_armv7m_set_msp(uint32_t msp);

/**
 * @brief Get Process Stack Pointer (PSP)
 * @brief 获取进程栈指针 (PSP)
 *
 * @return Current PSP value
 * @return PSP 当前值
 */
uint32_t arch_armv7m_get_psp(void);

/**
 * @brief Set Process Stack Pointer (PSP)
 * @brief 设置进程栈指针 (PSP)
 *
 * @param psp: New PSP value
 * @param psp: PSP 新值
 */
void arch_armv7m_set_psp(uint32_t psp);

/**
 * @brief Get PRIMASK register
 * @brief 获取 PRIMASK 寄存器
 *
 * PRIMASK is used to mask all configurable priority interrupts
 * PRIMASK 用于屏蔽所有可配置优先级的中断
 *
 * @return Current PRIMASK value
 * @return PRIMASK 当前值
 */
uint32_t arch_armv7m_get_primask(void);

/**
 * @brief Set PRIMASK register
 * @brief 设置 PRIMASK 寄存器
 *
 * @param primask: New PRIMASK value
 * @param primask: PRIMASK 新值
 */
void arch_armv7m_set_primask(uint32_t primask);

/**
 * @brief Get BASEPRI register
 * @brief 获取 BASEPRI 寄存器
 *
 * BASEPRI sets the minimum priority for interrupt masking
 * BASEPRI 设置中断屏蔽的最低优先级
 *
 * @return Current BASEPRI value
 * @return BASEPRI 当前值
 */
uint32_t arch_armv7m_get_basepri(void);

/**
 * @brief Set BASEPRI register
 * @brief 设置 BASEPRI 寄存器
 *
 * @param basepri: New BASEPRI value (0=not masked)
 * @param basepri: BASEPRI 新值 (0=不屏蔽)
 */
void arch_armv7m_set_basepri(uint32_t basepri);

/**
 * @brief Get FAULTMASK register
 * @brief 获取 FAULTMASK 寄存器
 *
 * FAULTMASK is used to mask all interrupts including NMI
 * FAULTMASK 用于屏蔽所有中断，包括 NMI
 *
 * @return Current FAULTMASK value
 * @return FAULTMASK 当前值
 */
uint32_t arch_armv7m_get_faultmask(void);

/**
 * @brief Set FAULTMASK register
 * @brief 设置 FAULTMASK 寄存器
 *
 * @param faultmask: New FAULTMASK value
 * @param faultmask: FAULTMASK 新值
 */
void arch_armv7m_set_faultmask(uint32_t faultmask);

/*
 * ============================================================================
 * ARMv7-M Status Register Access Functions
 * ARMv7-M 状态寄存器访问函数
 * ============================================================================
 */

/**
 * @brief Get IPSR register
 * @brief 获取 IPSR 寄存器
 *
 * IPSR contains the exception type number of the current interrupt service routine.
 * IPSR 包含当前中断服务例程的异常类型号。
 *
 * @return Current IPSR value (exception number)
 * @return 当前 IPSR 值 (异常号)
 */
uint32_t arch_armv7m_get_ipsr(void);

/**
 * @brief Get APSR register
 * @brief 获取 APSR 寄存器
 *
 * APSR contains the flags from the previous instruction execution.
 * APSR 包含上一条指令执行后的标志位。
 *
 * @return Current APSR value
 * @return 当前 APSR 值
 */
uint32_t arch_armv7m_get_apsr(void);

/**
 * @brief Get xPSR register
 * @brief 获取 xPSR 寄存器
 *
 * xPSR contains the combined Application, Interrupt, and Execution PSR registers.
 * xPSR 包含组合的应用、中断和执行 PSR 寄存器。
 *
 * @return Current xPSR value
 * @return 当前 xPSR 值
 */
uint32_t arch_armv7m_get_xpsr(void);

/*
 * ============================================================================
 * ARMv7-M Memory Barrier Functions Declaration
 * ARMv7-M 内存屏障函数声明
 */

/**
 * @brief Data Synchronization Barrier (DSB)
 * @brief 数据同步屏障 (DSB)
 *
 * Ensures all memory accesses before this instruction complete before
 * any subsequent instructions execute.
 * 确保此指令之前的所有内存访问在后续指令执行之前完成。
 */
void arch_armv7m_dsb(void);

/**
 * @brief Instruction Synchronization Barrier (ISB)
 * @brief 指令同步屏障 (ISB)
 *
 * Flushes the pipeline and ensures all instructions before this
 * point are completed.
 * 清空流水线并确保此点之前的所有指令都已完成。
 */
void arch_armv7m_isb(void);

/**
 * @brief Data Memory Barrier (DMB)
 * @brief 数据内存屏障 (DMB)
 *
 * Ensures all memory accesses before this instruction complete before
 * any subsequent memory accesses execute.
 * 确保此指令之前的所有内存访问在后续内存访问执行之前完成。
 */
void arch_armv7m_dmb(void);

/*
 * ============================================================================
 * ARMv7-M Low Power Mode Functions Declaration
 * ARMv7-M 低功耗模式函数声明
 */

/**
 * @brief Wait For Interrupt (WFI)
 * @brief 等待中断 (WFI)
 *
 * Places the processor in a low power state until an interrupt occurs.
 * 将处理器置于低功耗状态，直到发生中断。
 */
void arch_armv7m_wfi(void);

/**
 * @brief Wait For Event (WFE)
 * @brief 等待事件 (WFE)
 *
 * Places the processor in a low power state until an event occurs.
 * 将处理器置于低功耗状态，直到发生事件。
 */
void arch_armv7m_wfe(void);

/**
 * @brief Send Event (SEV)
 * @brief 发送事件 (SEV)
 *
 * Sends an event signal to all processors.
 * 向所有处理器发送事件信号。
 */
void arch_armv7m_sev(void);

/*
 * ============================================================================
 * ARMv7-M NVIC Interrupt Management Functions Declaration
 * ARMv7-M NVIC 中断管理函数声明
 */

/**
 * @brief Enable a specific interrupt
 * @brief 使能指定中断
 *
 * @param irq: Interrupt number (0-239)
 * @param irq: 中断号 (0-239)
 */
void arch_armv7m_enable_irq(uint8_t irq);

/**
 * @brief Disable a specific interrupt
 * @brief 禁用指定中断
 *
 * @param irq: Interrupt number (0-239)
 * @param irq: 中断号 (0-239)
 */
void arch_armv7m_disable_irq(uint8_t irq);

/**
 * @brief Set interrupt priority
 * @brief 设置中断优先级
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @param priority: Priority (0-255)
 * @param priority: 优先级 (0-255)
 */
void arch_armv7m_set_priority(uint8_t irq, uint8_t priority);

/**
 * @brief Get interrupt priority
 * @brief 获取中断优先级
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @return Interrupt priority
 * @return 中断优先级
 */
uint8_t arch_armv7m_get_priority(uint8_t irq);

/**
 * @brief Set interrupt pending status
 * @brief 设置中断挂起状态
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 */
void arch_armv7m_set_pending(uint8_t irq);

/**
 * @brief Clear interrupt pending status
 * @brief 清除中断挂起状态
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 */
void arch_armv7m_clear_pending(uint8_t irq);

/**
 * @brief Set priority grouping
 * @brief 设置优先级分组
 *
 * @param group: Priority grouping (0-7)
 * @param group: 优先级分组 (0-7)
 */
void arch_armv7m_set_priority_grouping(uint32_t group);

/*
 * ============================================================================
 * ARMv7-M System Control Functions Declaration
 * ARMv7-M 系统控制函数声明
 */

/**
 * @brief Trigger system reset
 * @brief 触发系统复位
 */
void arch_armv7m_system_reset(void);

/*
 * ============================================================================
 * ARMv7-M FPU Functions Declaration (Cortex-M4)
 * ARMv7-M FPU 函数声明 (Cortex-M4)
 */

/**
 * @brief Enable FPU
 * @brief 使能 FPU
 *
 * Enables CP10 and CP11 coprocessor access in CPACR register
 * 在 CPACR 寄存器中启用 CP10 和 CP11 协处理器访问
 */
void arch_armv7m_enable_fpu(void);

/**
 * @brief Disable FPU
 * @brief 禁用 FPU
 */
void arch_armv7m_disable_fpu(void);

/*
 * ============================================================================
 * ARMv7-M MPU Functions Declaration
 * ARMv7-M MPU 函数声明
 */

/**
 * @brief Get MPU type
 * @brief 获取 MPU 类型
 *
 * @return MPU type register value
 * @return MPU 类型寄存器值
 */
uint32_t arch_armv7m_mpu_get_type(void);

/**
 * @brief Initialize MPU
 * @brief 初始化 MPU
 */
void arch_armv7m_mpu_init(void);

/**
 * @brief Enable MPU
 * @brief 使能 MPU
 *
 * @param default_map: Enable default memory map for privileged mode
 * @param default_map: 为特权模式启用默认内存映射
 */
void arch_armv7m_mpu_enable(bool default_map);

/**
 * @brief Disable MPU
 * @brief 禁用 MPU
 */
void arch_armv7m_mpu_disable(void);

/**
 * @brief Set MPU region
 * @brief 设置 MPU 区域
 *
 * @param rnr: Region number
 * @param rnr: 区域编号
 * @param rbar: Region Base Address Register
 * @param rbar: 区域基地址寄存器
 * @param rasr: Region Attribute and Size Register
 * @param rasr: 区域属性和大小寄存器
 */
void arch_armv7m_mpu_set_region(uint32_t rnr, uint32_t rbar, uint32_t rasr);

/**
 * @brief Clear MPU region
 * @brief 清除 MPU 区域
 *
 * @param rnr: Region number
 * @param rnr: 区域编号
 */
void arch_armv7m_mpu_clr_region(uint32_t rnr);

/**
 * @brief Get number of MPU regions
 * @brief 获取 MPU 区域数量
 *
 * @return Number of regions
 * @return 区域数量
 */
uint32_t arch_armv7m_mpu_get_num_regions(void);

/*
 * ============================================================================
 * ARMv7-M Initialization and Context Switch Functions Declaration
 * ARMv7-M 初始化和上下文切换函数声明
 */

/**
 * @brief ARMv7-M architecture initialization
 * @brief ARMv7-M 架构初始化
 */
void arch_armv7m_init(void);

/**
 * @brief ARMv7-M vector table setup
 * @brief ARMv7-M 向量表设置
 */
void arch_armv7m_setup_vector_table(void);

/**
 * @brief Initialize user task context
 * @brief 初始化用户任务上下文
 *
 * @param context: Pointer to task context
 * @param context: 任务上下文指针
 * @param entry_point: Task entry address
 * @param entry_point: 任务入口地址
 * @param arg: Argument passed to task
 * @param arg: 传递给任务的参数
 */
void arch_armv7m_init_user_context(ArmV7mTaskContext *context, uint32_t entry_point, uint32_t arg);

/**
 * @brief Context switch
 * @brief 上下文切换
 *
 * @param from: Source context
 * @param from: 源上下文
 * @param to: Target context
 * @param to: 目标上下文
 * @return Switched address
 * @return 切换后的地址
 */
void* arch_armv7m_switch_context(void *from, void *to);

/**
 * @brief Start first task
 * @brief 启动第一个任务
 *
 * @param context: Task context
 * @param context: 任务上下文
 * @return Does not return
 * @return 不返回
 */
void* arch_armv7m_start_first_task(void *context);

/**
 * @brief Jump to kernel
 * @brief 跳转到内核
 *
 * @param vector_table_addr: Vector table address
 * @param vector_table_addr: 向量表地址
 * @return Does not return
 * @return 不返回
 */
void* arch_armv7m_jump_to_kernel(uint32_t vector_table_addr);

/*
 * ============================================================================
 * ARMv7-M NVIC Extended Functions Declaration
 * ARMv7-M NVIC 扩展函数声明
 */

/**
 * @brief Get enable status for a specific interrupt
 * @brief 获取指定中断的使能状态
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @return 1=enabled, 0=disabled
 * @return 1=使能, 0=禁用
 */
uint32_t arch_armv7m_get_enable_irq(uint8_t irq);

/**
 * @brief Get pending status for a specific interrupt
 * @brief 获取中断待处理状态
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @return 1=pending, 0=not pending
 * @return 1=挂起, 0=未挂起
 */
uint32_t arch_armv7m_get_pending_irq(uint8_t irq);

/**
 * @brief Get currently executing interrupt
 * @brief 获取当前正在执行的中断
 *
 * @return Currently executing interrupt number
 * @return 正在执行的中断号
 */
uint32_t arch_armv7m_get_active_irq(void);

/**
 * @brief Get priority grouping
 * @brief 获取优先级分组
 *
 * @return Priority grouping value
 * @return 优先级分组值
 */
uint32_t arch_armv7m_get_priority_grouping(void);

/**
 * @brief Set priority grouping
 * @brief 设置优先级分组
 *
 * @param priority_group: Priority grouping value
 * @param priority_group: 优先级分组值
 */
void arch_armv7m_set_priority_grouping(uint32_t priority_group);

/**
 * @brief Encode priority
 * @brief 编码优先级
 *
 * @param priority_group: Priority grouping
 * @param priority_group: 优先级分组
 * @param preempt_priority: Preemption priority
 * @param preempt_priority: 抢占优先级
 * @param sub_priority: Sub-priority
 * @param sub_priority: 子优先级
 * @return Encoded priority value
 * @return 编码后的优先级值
 */
uint32_t arch_armv7m_encode_priority(uint32_t priority_group, uint32_t preempt_priority, uint32_t sub_priority);

/**
 * @brief Decode priority
 * @brief 解码优先级
 *
 * @param priority: Encoded priority
 * @param priority: 编码的优先级
 * @param priority_group: Priority grouping
 * @param priority_group: 优先级分组
 * @param preempt_priority: Output preemption priority
 * @param preempt_priority: 输出抢占优先级
 * @param sub_priority: Output sub-priority
 * @param sub_priority: 输出子优先级
 */
void arch_armv7m_decode_priority(uint32_t priority, uint32_t priority_group, uint32_t *preempt_priority, uint32_t *sub_priority);

/**
 * @brief Set interrupt vector
 * @brief 设置中断向量
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @param vector: Interrupt handler address
 * @param vector: 中断处理函数地址
 */
void arch_armv7m_set_vector(uint8_t irq, uint32_t vector);

/**
 * @brief Get interrupt vector
 * @brief 获取中断向量
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @return Interrupt handler address
 * @return 中断处理函数地址
 */
uint32_t arch_armv7m_get_vector(uint8_t irq);

/*
 * ============================================================================
 * ARMv7-M SysTick Functions Declaration
 * ARMv7-M SysTick 函数声明
 */

/**
 * @brief SysTick configuration
 * @brief SysTick 配置
 *
 * @param ticks: Load value
 * @param ticks: 加载值
 * @return 0=success, 1=failure
 * @return 0=成功, 1=失败
 */
uint32_t arch_armv7m_systick_config(uint32_t ticks);

/**
 * @brief Get SysTick current value
 * @brief 获取 SysTick 当前值
 *
 * @return Current counter value
 * @return 当前计数值
 */
uint32_t arch_armv7m_systick_get_value(void);

/**
 * @brief Set SysTick reload value
 * @brief 设置 SysTick 加载值
 *
 * @param value: Reload value
 * @param value: 加载值
 */
void arch_armv7m_systick_set_reload(uint32_t value);

/**
 * @brief Get SysTick reload value
 * @brief 获取 SysTick 加载值
 *
 * @return Reload value
 * @return 加载值
 */
uint32_t arch_armv7m_systick_get_reload(void);

/**
 * @brief Enable SysTick interrupt
 * @brief 使能 SysTick 中断
 */
void arch_armv7m_systick_enable_irq(void);

/**
 * @brief Disable SysTick interrupt
 * @brief 禁用 SysTick 中断
 */
void arch_armv7m_systick_disable_irq(void);

/**
 * @brief Enable SysTick timer
 * @brief 使能 SysTick 定时器
 */
void arch_armv7m_systick_enable(void);

/**
 * @brief Disable SysTick timer
 * @brief 禁用 SysTick 定时器
 */
void arch_armv7m_systick_disable(void);

/**
 * @brief Get SysTick calibration value
 * @brief 获取 SysTick 校准值
 *
 * @return Calibration value
 * @return 校准值
 */
uint32_t arch_armv7m_systick_get_calib(void);

/*
 * ============================================================================
 * ARMv7-M ITM Functions Declaration
 * ARMv7-M ITM 函数声明
 */

/**
 * @brief ITM send character
 * @brief ITM 发送字符
 *
 * @param ch: Character to send
 * @param ch: 要发送的字符
 * @return Character sent
 * @return 发送的字符
 */
uint32_t arch_armv7m_itm_send_char(uint32_t ch);

/**
 * @brief ITM receive character
 * @brief ITM 接收字符
 *
 * @return Received character, -1 if no data
 * @return 接收的字符,如果没有数据返回 -1
 */
int32_t arch_armv7m_itm_receive_char(void);

/**
 * @brief ITM check if character is available
 * @brief ITM 检查是否有字符可用
 *
 * @return 1=data available, 0=no data
 * @return 1=有数据, 0=无数据
 */
int32_t arch_armv7m_itm_check_char(void);

/**
 * @brief ITM enable
 * @brief ITM 使能
 *
 * @param enable: 1=enable, 0=disable
 * @param enable: 1=使能, 0=禁用
 */
void arch_armv7m_itm_enable(uint32_t enable);

/*
 * ============================================================================
 * ARMv7-M Peripheral Register Structure Definitions
 * ARMv7-M 外设寄存器结构体定义
 */

/**
 * NVIC (Nested Vectored Interrupt Controller) Type Definition
 * NVIC (嵌套向量中断控制器) 类型定义
 *
 * The NVIC provides interrupt enable, disable, pending, priority and
 * active status registers.
 * NVIC 提供中断使能、禁用、挂起、优先级和活动状态寄存器。
 */
typedef struct {
    volatile uint32_t ISER[8U];     /**< Interrupt Set-Enable Register */
    volatile uint32_t RESERVED0[24U];
    volatile uint32_t ICER[8U];     /**< Interrupt Clear-Enable Register */
    volatile uint32_t RESERVED1[24U];
    volatile uint32_t ISPR[8U];     /**< Interrupt Set-Pending Register */
    volatile uint32_t RESERVED2[24U];
    volatile uint32_t ICPR[8U];     /**< Interrupt Clear-Pending Register */
    volatile uint32_t RESERVED3[24U];
    volatile uint32_t IABR[8U];     /**< Interrupt Active Bit Register */
    volatile uint32_t RESERVED4[56U];
    volatile uint8_t  IP[240U];     /**< Interrupt Priority Register */
} NVIC_Type;

/**
 * SCB (System Control Block) Type Definition
 * SCB (系统控制块) 类型定义
 *
 * The SCB provides system configuration and control functions.
 * SCB 提供系统配置和控制功能。
 */
typedef struct {
    volatile uint32_t CPUID;         /**< CPU ID Register */
    volatile uint32_t ICSR;         /**< Interrupt Control and State Register */
    volatile uint32_t VTOR;         /**< Vector Table Offset Register */
    volatile uint32_t AIRCR;        /**< Application Interrupt and Reset Control Register */
    volatile uint32_t SCR;          /**< System Control Register */
    volatile uint32_t CCR;          /**< Configuration Control Register */
    volatile uint8_t  SHP[12U];     /**< System Handler Priority Registers */
    volatile uint32_t SHCSR;        /**< System Handler Control and State Register */
    volatile uint32_t CFSR;         /**< Configurable Fault Status Register */
    volatile uint32_t HFSR;         /**< HardFault Status Register */
    volatile uint32_t DFSR;         /**< Debug Fault Status Register */
    volatile uint32_t MMFAR;        /**< MemManage Fault Address Register */
    volatile uint32_t BFAR;         /**< BusFault Address Register */
    volatile uint32_t AFSR;         /**< Auxiliary Fault Status Register */
    volatile uint32_t ID_PFR[2U];  /**< Processor Feature Register */
    volatile uint32_t ID_DFR;       /**< Debug Feature Register */
    volatile uint32_t ID_ADR;        /**< Auxiliary Feature Register */
    volatile uint32_t ID_MMFR[4U];  /**< Memory Model Feature Register */
    volatile uint32_t ID_ISAR[5U];  /**< Instruction Set Attributes Register */
    volatile uint32_t CLIDR;        /**< Cache Level ID Register */
    volatile uint32_t CTR;           /**< Cache Type Register */
    volatile uint32_t CCSIDR;       /**< Cache Size ID Register */
    volatile uint32_t CSSELR;       /**< Cache Size Selection Register */
    volatile uint32_t CPACR;        /**< Coprocessor Access Control Register */
    volatile uint32_t RESERVED3[93U];
    volatile uint32_t STIR[2U];     /**< Software Triggered Interrupt Register */
    volatile uint32_t MVFR0;        /**< Media and VFP Feature Register 0 */
    volatile uint32_t MVFR1;        /**< Media and VFP Feature Register 1 */
    volatile uint32_t MVFR2;        /**< Media and VFP Feature Register 2 */
    volatile uint32_t RESERVED4[3U];
    volatile uint32_t ICIALLU;      /**< I-Cache Invalidate All to PoU */
    volatile uint32_t RESERVED5;
    volatile uint32_t ICIMVAU;      /**< I-Cache Invalidate by MVA to PoU */
    volatile uint32_t DCIMVAC;      /**< D-Cache Invalidate by MVA to PoC */
    volatile uint32_t DCISW;       /**< D-Cache Invalidate by Set-way */
    volatile uint32_t DCCMVAU;      /**< D-Cache Clean by MVA to PoU */
    volatile uint32_t DCCMVAC;      /**< D-Cache Clean by MVA to PoC */
    volatile uint32_t DCCSW;         /**< D-Cache Clean by Set-way */
    volatile uint32_t DCCIALLU;     /**< D-Cache Invalidate All to PoC */
    volatile uint32_t RESERVED6[6U];
    volatile uint32_t ITCMCR;       /**< ITCM Control Register */
    volatile uint32_t DTCMCR;       /**< DTCM Control Register */
    volatile uint32_t AHBPCR;        /**< AHB Peripheral Control Register */
    volatile uint32_t CACR;          /**< Cache Control Register */
    volatile uint32_t AHBSCR;       /**< AHB Slave Control Register */
    volatile uint32_t RESERVED8[3U];
    volatile uint32_t CFGHCSR;      /**< Configuration and Control Register */
    volatile uint32_t RESERVED9[1U];
    volatile uint32_t HFSR1;        /**< HardFault Status Register 1 */
    volatile uint32_t RESERVED10[1U];
    volatile uint32_t ID_AFR;       /**< Auxiliary Feature Register */
    volatile uint32_t ID_MFR[4U];   /**< Main Feature Register */
    volatile uint32_t ISR[4U];       /**< Interrupt Status Register */
} SCB_Type;

/**
 * SysTick Type Definition
 * SysTick 类型定义
 *
 * The SysTick timer is an integrated system timer.
 * SysTick 定时器是集成系统定时器。
 */
typedef struct {
    volatile uint32_t CTRL;         /**< SysTick Control and Status Register */
    volatile uint32_t LOAD;        /**< SysTick Reload Value Register */
    volatile uint32_t VAL;          /**< SysTick Current Value Register */
    volatile uint32_t CALIB;        /**< SysTick Calibration Register */
} SysTick_Type;

/**
 * MPU (Memory Protection Unit) Type Definition
 * MPU (内存保护单元) 类型定义
 *
 * The MPU provides memory protection.
 * MPU 提供内存保护功能。
 */
typedef struct {
    volatile uint32_t TYPE;         /**< MPU Type Register */
    volatile uint32_t CTRL;         /**< MPU Control Register */
    volatile uint32_t RNR;           /**< MPU Region Number Register */
    volatile uint32_t RBAR;         /**< MPU Region Base Address Register */
    volatile uint32_t RASR;         /**< MPU Region Attribute and Size Register */
    volatile uint32_t RSVD;         /**< Reserved */
} MPU_Type;

/**
 * ITM (Instrumentation Trace Macrocell) Type Definition
 * ITM (指令跟踪宏单元) 类型定义
 *
 * The ITM is a software instrumentation trace generator.
 * ITM 是软件仪表跟踪生成器。
 */
typedef struct {
    volatile uint32_t CTRL;         /**< ITM Control Register */
    volatile uint32_t TOKEN;        /**< ITM Token Register */
    volatile uint32_t TPR;           /**< ITM Trace Privilege Register */
    volatile uint32_t RESERVED0;
    volatile uint32_t TER[32U];     /**< ITM Trace Enable Register */
    volatile uint32_t RESERVED1[864U];
    volatile uint32_t PORT[32U];    /**< ITM Stimulus Port Register */
} ITM_Type;

/**
 * FPU Type Definition
 * FPU 类型定义
 */
typedef struct {
    volatile uint32_t CPACR;         /**< Coprocessor Access Control Register */
} FPU_Type;

/**
 * SCnSCB Type Definition
 * SCnSCB 类型定义
 */
typedef struct {
    volatile uint32_t ACR;          /**< Auxiliary Control Register */
    volatile uint32_t NSACR;        /**< Non-Secure Auxiliary Control Register */
} SCnSCB_Type;

/*
 * ============================================================================
 * ARMv7-M Peripheral Register Base Address Definitions
 * ARMv7-M 外设寄存器基地址定义
 */

/**
 * NVIC base address
 * NVIC 基地址
 * Address: 0xE000E100
 */
#define NVIC_BASE_ADDR         0xE000E100UL
#define NVIC                   ((NVIC_Type *) NVIC_BASE_ADDR)

/**
 * SCB base address
 * SCB 基地址
 * Address: 0xE000ED00
 */
#define SCB_BASE_ADDR          0xE000ED00UL
#define SCB                   ((SCB_Type *) SCB_BASE_ADDR)

/**
 * SCB_VTOR: Vector Table Offset Register
 * SCB_VTOR: 向量表偏移寄存器
 */
#define SCB_VTOR             (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x08))

/**
 * SCB_AIRCR: Application Interrupt and Reset Control Register
 * SCB_AIRCR: 应用中断和复位控制寄存器
 */
#define SCB_AIRCR            (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x0C))

/**
 * SCB_CCR: Configuration Control Register
 * SCB_CCR: 配置控制寄存器
 */
#define SCB_CCR              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x14))

/**
 * SCB_CCR_IC_Msk: I-Cache enable bit mask
 * SCB_CCR_IC_Msk: I-Cache 使能位掩码
 */
#define SCB_CCR_IC_Msk       (1UL << 9)

/**
 * SCB_CCR_DC_Msk: D-Cache enable bit mask
 * SCB_CCR_DC_Msk: D-Cache 使能位掩码
 */
#define SCB_CCR_DC_Msk       (1UL << 16)

/**
 * SCB_MVFR0: Media and VFP Feature Register 0
 * SCB_MVFR0: 媒体和 VFP 特性寄存器 0
 */
#define SCB_MVFR0            (*(volatile uint32_t *)(SCB_BASE_ADDR + 0xD80))

/**
 * SysTick base address
 * SysTick 基地址
 * Address: 0xE000E010
 */
#define SYSTICK_BASE_ADDR      0xE000E010UL
#define SysTick               ((SysTick_Type *) SYSTICK_BASE_ADDR)

/**
 * MPU base address
 * MPU 基地址
 * Address: 0xE000ED90
 */
#define MPU_BASE_ADDR          0xE000ED90UL
#define MPU                   ((MPU_Type *) MPU_BASE_ADDR)

/**
 * MPU_CTRL: MPU Control Register
 * MPU_CTRL: MPU 控制寄存器
 */
#define MPU_CTRL              (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x04))

/**
 * MPU_CTRL_ENABLE_Msk: MPU enable bit mask
 * MPU_CTRL_ENABLE_Msk: MPU 使能位掩码
 */
#define MPU_CTRL_ENABLE_Msk   (1UL << 0)

/**
 * MPU_CTRL_PRIVDEFENA_Msk: Default map for privileged enable mask
 * MPU_CTRL_PRIVDEFENA_Msk: 特权默认映射使能掩码
 */
#define MPU_CTRL_PRIVDEFENA_Msk (1UL << 2)

/**
 * MPU_RNR: MPU Region Number Register
 * MPU_RNR: MPU 区域编号寄存器
 */
#define MPU_RNR               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x00))

/**
 * MPU_RBAR: MPU Region Base Address Register
 * MPU_RBAR: MPU 区域基地址寄存器
 */
#define MPU_RBAR              (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x08))

/**
 * MPU_RASR: MPU Region Attribute and Size Register
 * MPU_RASR: MPU 区域属性和大小寄存器
 */
#define MPU_RASR              (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x0C))

/**
 * ITM base address
 * ITM 基地址
 * Address: 0xE0000000
 */
#define ITM_BASE_ADDR          0xE0000000UL
#define ITM                   ((ITM_Type *) ITM_BASE_ADDR)

/**
 * ITM_TCR: ITM Trace Control Register
 * ITM_TCR: ITM 跟踪控制寄存器
 */
#define ITM_TCR               (*(volatile uint32_t *)(ITM_BASE_ADDR + 0x00))

/**
 * ITM_TCR_ITMENA_Msk: ITM enable bit mask
 * ITM_TCR_ITMENA_Msk: ITM 使能位掩码
 */
#define ITM_TCR_ITMENA_Msk    (1UL << 0)

/**
 * ITM_TER: ITM Trace Enable Register
 * ITM_TER: ITM 跟踪使能寄存器
 */
#define ITM_TER               (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xE00))

/**
 * ITM_RXR: ITM Receive Register
 * ITM_RXR: ITM 接收寄存器
 */
#define ITM_RXR               (*(volatile uint32_t *)(ITM_BASE_ADDR + 0x00))

/**
 * ITM_PORT: ITM Stimulus Port
 * ITM_PORT: ITM 刺激端口
 */
#define ITM_PORT              ((ITM_Port_Type *) ITM_BASE_ADDR)

/**
 * ITM Port Union Type
 * ITM 端口联合类型
 */
typedef union {
    volatile uint8_t  u8;
    volatile uint16_t u16;
    volatile uint32_t u32;
} ITM_Port_Type;

/**
 * SCnSCB base address
 * SCnSCB 基地址
 * Address: 0xE000ED10
 */
#define SCnSCB_BASE_ADDR       0xE000ED00UL
#define SCnSCB                ((SCnSCB_Type *) (SCnSCB_BASE_ADDR + 0x10U))

/**
 * FPU base address
 * FPU 基地址
 * Address: 0xE000ED88
 */
#define FPU_BASE_ADDR          0xE000ED00UL
#define FPU                   ((FPU_Type *) (FPU_BASE_ADDR + 0xD88U))

/*
 * ============================================================================
 * ARMv7-M DSP/SIMD Intrinsics
 * ARMv7-M DSP/SIMD 内在函数
 *
 * These intrinsics provide access to DSP and SIMD instructions available in
 * Cortex-M4, Cortex-M7 and other processors with DSP extension.
 * 这些内在函数提供对具有 DSP 扩展的 Cortex-M4、Cortex-M7 等处理器中
 * DSP 和 SIMD 指令的访问。
 *
 * Note: These are compiler-agnostic wrappers that use GCC/Clang builtins.
 * 注意: 这些是使用 GCC/Clang 内置函数的编译器无关包装器。
 * ============================================================================
 */

#if defined(__ARM_FEATURE_DSP) && (__ARM_FEATURE_DSP == 1)

/**
 * @brief Signed Saturating Add 8 (SADD8)
 * @brief 带符号饱和加法 8 位
 *
 * @param op1: First operand
 * @param op1: 第一个操作数
 * @param op2: Second operand
 * @param op2: 第二个操作数
 * @return Signed saturated result
 * @return 带符号饱和结果
 */
__STATIC_INLINE int32_t __SADD8(int32_t op1, int32_t op2) {
    return __builtin_arm_sadd8(op1, op2);
}

/**
 * @brief Signed Saturating Add 16 (SADD16)
 * @brief 带符号饱和加法 16 位
 *
 * @param op1: First operand
 * @param op1: 第一个操作数
 * @param op2: Second operand
 * @param op2: 第二个操作数
 * @return Signed saturated result
 * @return 带符号饱和结果
 */
__STATIC_INLINE int32_t __SADD16(int32_t op1, int32_t op2) {
    return __builtin_arm_sadd16(op1, op2);
}

/**
 * @brief Signed Saturating Subtract 8 (SSUB8)
 * @brief 带符号饱和减法 8 位
 *
 * @param op1: First operand
 * @param op1: 第一个操作数
 * @param op2: Second operand
 * @param op2: 第二个操作数
 * @return Signed saturated result
 * @return 带符号饱和结果
 */
__STATIC_INLINE int32_t __SSUB8(int32_t op1, int32_t op2) {
    return __builtin_arm_ssub8(op1, op2);
}

/**
 * @brief Signed Saturating Subtract 16 (SSUB16)
 * @brief 带符号饱和减法 16 位
 *
 * @param op1: First operand
 * @param op1: 第一个操作数
 * @param op2: Second operand
 * @param op2: 第二个操作数
 * @return Signed saturated result
 * @return 带符号饱和结果
 */
__STATIC_INLINE int32_t __SSUB16(int32_t op1, int32_t op2) {
    return __builtin_arm_ssub16(op1, op2);
}

/**
 * @brief Signed Halving Add 8 (SHADD8)
 * @brief 带符号折半加法 8 位
 *
 * @param op1: First operand
 * @param op1: 第一个操作数
 * @param op2: Second operand
 * @param op2: 第二个操作数
 * @return Halved result
 * @return 折半结果
 */
__STATIC_INLINE int32_t __SHADD8(int32_t op1, int32_t op2) {
    return __builtin_arm_shadd8(op1, op2);
}

/**
 * @brief Signed Halving Add 16 (SHADD16)
 * @brief 带符号折半加法 16 位
 *
 * @param op1: First operand
 * @param op1: 第一个操作数
 * @param op2: Second operand
 * @param op2: 第二个操作数
 * @return Halved result
 * @return 折半结果
 */
__STATIC_INLINE int32_t __SHADD16(int32_t op1, int32_t op2) {
    return __builtin_arm_shadd16(op1, op2);
}

/**
 * @brief Saturating Add (QADD)
 * @brief 饱和加法
 *
 * @param op1: First operand
 * @param op1: 第一个操作数
 * @param op2: Second operand
 * @param op2: 第二个操作数
 * @return Saturating result
 * @return 饱和结果
 */
__STATIC_INLINE int32_t __QADD(int32_t op1, int32_t op2) {
    return __builtin_arm_qadd(op1, op2);
}

/**
 * @brief Saturating Subtract (QSUB)
 * @brief 饱和减法
 *
 * @param op1: First operand
 * @param op1: 第一个操作数
 * @param op2: Second operand
 * @param op2: 第二个操作数
 * @return Saturating result
 * @return 饱和结果
 */
__STATIC_INLINE int32_t __QSUB(int32_t op1, int32_t op2) {
    return __builtin_arm_qsub(op1, op2);
}

/**
 * @brief Select Bytes (SEL)
 * @brief 选择字节
 *
 * @param op1: First operand
 * @param op1: 第一个操作数
 * @param op2: Second operand
 * @param op2: 第二个操作数
 * @return Selected result
 * @return 选择结果
 */
__STATIC_INLINE int32_t __SEL(int32_t op1, int32_t op2) {
    return __builtin_arm_sel(op1, op2);
}

/**
 * @brief Signed Multiply Accumulate (SMLA)
 * @brief 带符号乘加
 *
 * @param op1: First operand
 * @param op1: 第一个操作数
 * @param op2: Second operand
 * @param op2: 第二个操作数
 * @param op3: Accumulator
 * @param op3: 累加器
 * @return Multiply accumulate result
 * @return 乘加结果
 */
__STATIC_INLINE int32_t __SMLAD(int32_t op1, int32_t op2, int32_t op3) {
    return __builtin_arm_smlad(op1, op2, op3);
}

/**
 * @brief Signed Multiply Accumulate Long (SMLALD)
 * @brief 带符号长乘加
 *
 * @param op1: First operand
 * @param op1: 第一个操作数
 * @param op2: Second operand
 * @param op2: 第二个操作数
 * @param op3: Accumulator (lower 32 bits)
 * @param op3: 累加器 (低 32 位)
 * @return Long multiply accumulate result
 * @return 长乘加结果
 */
__STATIC_INLINE int64_t __SMLALD(int32_t op1, int32_t op2, int64_t op3) {
    return __builtin_arm_smlald(op1, op2, op3);
}

/**
 * @brief Signed Multiply Subtract Accumulate (SMLSD)
 * @brief 带符号乘减累加
 *
 * @param op1: First operand
 * @param op1: 第一个操作数
 * @param op2: Second operand
 * @param op2: 第二个操作数
 * @param op3: Accumulator
 * @param op3: 累加器
 * @return Multiply subtract accumulate result
 * @return 乘减累加结果
 */
__STATIC_INLINE int32_t __SMLSD(int32_t op1, int32_t op2, int32_t op3) {
    return __builtin_arm_smlsd(op1, op2, op3);
}

/**
 * @brief Dual Signed Add and Subtract (SASX/SSAX)
 * @brief 双带符号加法和减法
 *
 * @param op1: First operand
 * @param op1: 第一个操作数
 * @param op2: Second operand
 * @param op2: 第二个操作数
 * @return Add and subtract result
 * @return 加减结果
 */
__STATIC_INLINE int32_t __SASX(int32_t op1, int32_t op2) {
    return __builtin_arm_sasx(op1, op2);
}

/**
 * @brief Signed Shift Right (SSAT)
 * @brief 带符号饱和右移
 *
 * @param op1: Value to shift
 * @param op1: 要移位的值
 * @param sat: Bit position to saturate to
 * @param sat: 饱和到位位置
 * @return Saturated result
 * @return 饱和结果
 */
__STATIC_INLINE int32_t __SSAT(int32_t op1, int32_t sat) {
    return __builtin_arm_ssat(op1, sat);
}

/**
 * @brief Unsigned Shift Right (USAT)
 * @brief 无符号饱和右移
 *
 * @param op1: Value to shift
 * @param op1: 要移位的值
 * @param sat: Bit position to saturate to
 * @param sat: 饱和到位位置
 * @return Saturated result
 * @return 饱和结果
 */
__STATIC_INLINE int32_t __USAT(int32_t op1, int32_t sat) {
    return __builtin_arm_usat(op1, sat);
}

/**
 * @brief Signed Extend Byte (SXTB)
 * @brief 带符号扩展字节
 *
 * @param op1: Value to extend
 * @param op1: 要扩展的值
 * @return Sign extended result
 * @return 符号扩展结果
 */
__STATIC_INLINE int32_t __SXTB(int32_t op1) {
    return __builtin_arm_sxtb(op1);
}

/**
 * @brief Signed Extend Halfword (SXTH)
 * @brief 带符号扩展半字
 *
 * @param op1: Value to extend
 * @param op1: 要扩展的值
 * @return Sign extended result
 * @return 符号扩展结果
 */
__STATIC_INLINE int32_t __SXTH(int32_t op1) {
    return __builtin_arm_sxth(op1);
}

/**
 * @brief Unsigned Extend Byte (UXTB)
 * @brief 无符号扩展字节
 *
 * @param op1: Value to extend
 * @param op1: 要扩展的值
 * @return Zero extended result
 * @return 零扩展结果
 */
__STATIC_INLINE uint32_t __UXTB(uint32_t op1) {
    return __builtin_arm_uxtb(op1);
}

/**
 * @brief Unsigned Extend Halfword (UXTH)
 * @brief 无符号扩展半字
 *
 * @param op1: Value to extend
 * @param op1: 要扩展的值
 * @return Zero extended result
 * @return 零扩展结果
 */
__STATIC_INLINE uint32_t __UXTH(uint32_t op1) {
    return __builtin_arm_uxth(op1);
}

#define __PKHBT(ARG1,ARG2,ARG3) \
    __builtin_arm_pkhbt((ARG1), (ARG2), (ARG3))

#define __PKHTB(ARG1,ARG2,ARG3) \
    __builtin_arm_pkhtb((ARG1), (ARG2), (ARG3))

#endif /* __ARM_FEATURE_DSP */

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_H__ */
