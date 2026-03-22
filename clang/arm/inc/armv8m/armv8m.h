/*
 * ARM Architecture - ARMv8-M Support
 *
 * ============================================================================
 * File: armv8m.h
 * Description: ARMv8-M architecture specific definitions and function declarations
 * 描述: ARMv8-M 架构特定定义和函数声明
 *
 * This file provides complete ARMv8-M architecture definitions aligned with
 * ARMv8-M Architecture Reference Manual (ARMv8-M ARM).
 * 本文件提供与 ARMv8-M 架构参考手册 (ARMv8-M ARM) 对齐的完整 ARMv8-M 架构定义。
 *
 * Reference Documents / 参考文档:
 *   1. Arm® v8-M Architecture Reference Manual
 *      - Chapter B3: Programmers' Model
 *      - Chapter B4: Floating-point Support
 *      - Chapter B10: The Armv8-M Protected Memory System Architecture
 *      - Chapter B11: The System Timer, SysTick
 *      - Chapter B12: Nested Vectored Interrupt Controller
 *      - Chapter B13: Debug
 *      - Chapter B14: Debug and Trace Components
 *      - Chapter B15: The Performance Monitors Extension
 *
 * ARMv8-M Architecture Overview:
 *   ARMv8-M is ARM's microcontroller architecture, divided into two branches:
 *   ARMv8-M 是 ARM 的微控制器架构，分为两个分支:
 *     - ARMv8-M Baseline: Similar to ARMv6-M extension
 *       ARMv8-M Baseline: 类似于 ARMv6-M 的扩展
 *     - ARMv8-M Mainline: Complete ARMv8-M implementation with TrustZone security
 *       ARMv8-M Mainline: 完整的 ARMv8-M 实现，支持 TrustZone 安全扩展
 *
 * Key Features:
 *   - TrustZone Security Extension (Mainline) - ARMv8-M ARM Chapter B10
 *   - MPU Memory Protection Unit - ARMv8-M ARM Chapter B10
 *   - Optional FPU (single/double precision) - ARMv8-M ARM Chapter B4
 *   - DSP instruction extension
 *   - Optional SIMD extension
 *   - Optional PMU Performance Monitor Unit - ARMv8-M ARM Chapter B15
 *   - Enhanced Interrupt Controller - ARMv8-M ARM Chapter B12
 *   - Hardware Divide (SDIV/UDIV)
 *   - Bit Field Instructions (BB, BFC, BFI, CLZ, etc.)
 *
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 ARM Architecture Team. All rights reserved.
 */

#ifndef __ARCH_ARM_V8M_H__
#define __ARCH_ARM_V8M_H__

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * ARMv8-M Configuration Macros
 * ARMv8-M 配置宏定义
 * ============================================================================
 */

/**
 * ARMv8-M Architecture Identifier
 * ARMv8-M 架构标识符
 */
#define __ARM_ARCH_V8M__ 1

/**
 * ARMv8-M Mainline (1) or Baseline (0)
 * ARMv8-M 主线 (1) 或基线 (0)
 */
#define __ARM_ARCH_V8M_MAINLINE__ 1

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
 * Number of Priority Bits: 8 bits for priority (0-255)
 * 优先级位数: 8 位优先级 (0-255)
 */
#define __NVIC_PRIO_BITS          8U

/**
 * Vendor SysTick Config: 0 = Use standard implementation
 * 供应商 SysTick 配置: 0 = 使用标准实现
 */
#define __Vendor_SysTickConfig    0U

/**
 * FPU Present: 1 = FPU is present
 * FPU 存在: 1 = FPU 存在
 */
#define __FPU_PRESENT             1U

/**
 * FPU Double Precision: 1 = Double precision supported
 * FPU 双精度: 1 = 支持双精度
 */
#define __FPU_DP                 1U

/**
 * Number of interrupts supported
 * 支持的中断数量
 */
#define __ARM_NUM_INTERRUPTS      256U

/**
 * PMU Present: 1 = PMU is present (optional)
 * PMU 存在: 1 = PMU 存在 (可选)
 */
#define __PMU_PRESENT             1U

/**
 * TrustZone Present: 1 = TrustZone/SAU is present (ARMv8-M Mainline)
 * TrustZone 存在: 1 = TrustZone/SAU 存在 (ARMv8-M Mainline)
 */
#define __TZ_PRESENT              1U

/**
 * Number of SAU regions supported (0-8)
 * 支持的 SAU 区域数量 (0-8)
 */
#define __SAU_REGIONS_NUM         8U

/**
 * DSP Extension Present: 1 = DSP extension is present (optional)
 * DSP 扩展存在: 1 = DSP 扩展存在 (可选)
 */
#define __DSP_PRESENT             1U

/**
 * Number of breakpoints supported
 * 支持的断点数量
 */
#define __NUM_BRP                 8U

/**
 * Number of watchpoints supported
 * 支持的观察点数量
 */
#define __NUM_WRP                 4U

/**
 * DWT Present: 1 = Data Watchpoint and Trace is present
 * DWT 存在: 1 = 数据观察点和跟踪存在
 */
#define __DWT_PRESENT             1U

/**
 * ITM Present: 1 = Instrumentation Trace Macrocell is present
 * ITM 存在: 1 = 仪表跟踪宏单元存在
 */
#define __ITM_PRESENT             1U

/**
 * ETM Present: 1 = Embedded Trace Macrocell is present (optional)
 * ETM 存在: 1 = 嵌入式跟踪宏单元存在 (可选)
 */
#define __ETM_PRESENT             1U

/*
 * ============================================================================
 * ARMv8-M Core Register Bit Definitions
 * ARMv8-M 核心寄存器位定义
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 * ============================================================================
 */

/**
 * CONTROL register bit definitions
 * CONTROL 寄存器位定义
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 */
#define CONTROL_nPRIV_Pos          0U
#define CONTROL_nPRIV_Msk         (1UL << CONTROL_nPRIV_Pos)
#define CONTROL_SPSEL_Pos         1U
#define CONTROL_SPSEL_Msk         (1UL << CONTROL_SPSEL_Pos)
#define CONTROL_FPCA_Pos          2U
#define CONTROL_FPCA_Msk          (1UL << CONTROL_FPCA_Pos)
#define CONTROL_SFPA_Pos          4U
#define CONTROL_SFPA_Msk          (1UL << CONTROL_SFPA_Pos)

/**
 * @brief CONTROL_nPRIV bit: Non-privileged execution level
 * @brief CONTROL_nPRIV 位：非特权执行级别
 * 0: Privileged execution / 特权执行
 * 1: Non-privileged execution / 非特权执行
 */
#define CONTROL_nPRIV              (1UL << CONTROL_nPRIV_Pos)

/**
 * @brief CONTROL_SPSEL bit: Stack pointer select
 * @brief CONTROL_SPSEL 位：栈指针选择
 * 0: Use MSP (Main Stack Pointer) / 使用 MSP (主栈指针)
 * 1: Use PSP (Process Stack Pointer) / 使用 PSP (进程栈指针)
 */
#define CONTROL_SPSEL              (1UL << CONTROL_SPSEL_Pos)

/**
 * @brief CONTROL_FPCA bit: Floating-point context active
 * @brief CONTROL_FPCA 位：浮点上下文激活
 * 0: No floating-point context active / 无浮点上下文激活
 * 1: Floating-point context active / 浮点上下文激活
 */
#define CONTROL_FPCA               (1UL << CONTROL_FPCA_Pos)

/**
 * @brief CONTROL_SFPA bit: Secure floating-point active
 * @brief CONTROL_SFPA 位：安全浮点激活
 * 0: Secure floating-point not active / 安全浮点未激活
 * 1: Secure floating-point active / 安全浮点激活
 */
#define CONTROL_SFPA               (1UL << CONTROL_SFPA_Pos)

/**
 * PRIMASK register bit definitions
 * PRIMASK 寄存器位定义
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 */
#define PRIMASK_Pos                0U
#define PRIMASK_Msk              (1UL << PRIMASK_Pos)

/**
 * @brief PRIMASK bit: Priority mask
 * @brief PRIMASK 位：优先级掩码
 * 0: Interrupts enabled / 中断使能
 * 1: Interrupts disabled (except NMI and HardFault) / 中断禁用（除 NMI 和 HardFault 外）
 */
#define PRIMASK                  (1UL << PRIMASK_Pos)

/**
 * FAULTMASK register bit definitions
 * FAULTMASK 寄存器位定义
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 */
#define FAULTMASK_Pos             0U
#define FAULTMASK_Msk            (1UL << FAULTMASK_Pos)

/**
 * @brief FAULTMASK bit: Fault mask
 * @brief FAULTMASK 位：故障掩码
 * 0: Fault interrupts enabled / 故障中断使能
 * 1: Fault interrupts disabled (only NMI enabled) / 故障中断禁用（仅 NMI 使能）
 */
#define FAULTMASK                (1UL << FAULTMASK_Pos)

/**
 * BASEPRI register bit definitions
 * BASEPRI 寄存器位定义
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 */
#define BASEPRI_Pos               0U
#define BASEPRI_Msk              (0xFFUL << BASEPRI_Pos)

/**
 * @brief BASEPRI: Base priority level
 * @brief BASEPRI：基础优先级级别
 * 0: No priority masking / 无优先级屏蔽
 * 1-255: Mask interrupts with priority <= BASEPRI / 屏蔽优先级 <= BASEPRI 的中断
 */
#define BASEPRI                  (0xFFUL << BASEPRI_Pos)

/**
 * xPSR register bit definitions
 * xPSR 寄存器位定义
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 */
#define xPSR_N_Pos               31U
#define xPSR_N_Msk              (1UL << xPSR_N_Pos)
#define xPSR_Z_Pos               30U
#define xPSR_Z_Msk              (1UL << xPSR_Z_Pos)
#define xPSR_C_Pos               29U
#define xPSR_C_Msk              (1UL << xPSR_C_Pos)
#define xPSR_V_Pos               28U
#define xPSR_V_Msk              (1UL << xPSR_V_Pos)
#define xPSR_Q_Pos               27U
#define xPSR_Q_Msk              (1UL << xPSR_Q_Pos)
#define xPSR_IC_Pos              26U
#define xPSR_IC_Msk             (1UL << xPSR_IC_Pos)
#define xPSR_Exception_Pos        0U
#define xPSR_Exception_Msk       (0x1FFUL << xPSR_Exception_Pos)

/**
 * @brief xPSR_N: Negative condition flag
 * @brief xPSR_N：负条件标志
 * 1: Result negative / 结果为负
 * 0: Result positive or zero / 结果为正或零
 */
#define xPSR_N                   (1UL << xPSR_N_Pos)

/**
 * @brief xPSR_Z: Zero condition flag
 * @brief xPSR_Z：零条件标志
 * 1: Result is zero / 结果为零
 * 0: Result is not zero / 结果不为零
 */
#define xPSR_Z                   (1UL << xPSR_Z_Pos)

/**
 * @brief xPSR_C: Carry condition flag
 * @brief xPSR_C：进位条件标志
 * 1: Carry occurred / 发生进位
 * 0: No carry / 无进位
 */
#define xPSR_C                   (1UL << xPSR_C_Pos)

/**
 * @brief xPSR_V: Overflow condition flag
 * @brief xPSR_V：溢出条件标志
 * 1: Overflow occurred / 发生溢出
 * 0: No overflow / 无溢出
 */
#define xPSR_V                   (1UL << xPSR_V_Pos)

/**
 * @brief xPSR_Q: Saturation flag
 * @brief xPSR_Q：饱和标志
 * 1: Saturation occurred / 发生饱和
 * 0: No saturation / 无饱和
 */
#define xPSR_Q                   (1UL << xPSR_Q_Pos)

/**
 * @brief xPSR_IC: Interrupt-continuable instruction
 * @brief xPSR_IC：中断可继续指令
 * Indicates if an interrupt-continuable instruction is in progress / 表示是否有中断可继续指令正在执行
 */
#define xPSR_IC                  (1UL << xPSR_IC_Pos)

/**
 * @brief xPSR_Exception: Exception number
 * @brief xPSR_Exception：异常号
 * Indicates the current exception being executed / 表示当前正在执行的异常
 */
#define xPSR_Exception           (0x1FFUL << xPSR_Exception_Pos)

/*
 * ============================================================================
 * ARMv8-M NVIC Register Bit Definitions
 * ARMv8-M NVIC 寄存器位定义
 *
 * Reference: ARMv8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: ARMv8-M ARM 第 B12 章 (嵌套向量中断控制器)
 * ============================================================================
 */

/**
 * SCB_AIRCR register bit definitions
 * SCB_AIRCR 寄存器位定义
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 */
#define SCB_AIRCR_VECTKEY_Pos          16U
#define SCB_AIRCR_VECTKEY_Msk          (0xFFFFUL << SCB_AIRCR_VECTKEY_Pos)
#define SCB_AIRCR_VECTKEYSTAT_Pos      16U
#define SCB_AIRCR_VECTKEYSTAT_Msk      (0xFFFFUL << SCB_AIRCR_VECTKEYSTAT_Pos)
#define SCB_AIRCR_ENDIANESS_Pos        15U
#define SCB_AIRCR_ENDIANESS_Msk        (1UL << SCB_AIRCR_ENDIANESS_Pos)
#define SCB_AIRCR_PRIGROUP_Pos          8U
#define SCB_AIRCR_PRIGROUP_Msk          (7UL << SCB_AIRCR_PRIGROUP_Pos)
#define SCB_AIRCR_SYSRESETREQ_Pos       2U
#define SCB_AIRCR_SYSRESETREQ_Msk       (1UL << SCB_AIRCR_SYSRESETREQ_Pos)
#define SCB_AIRCR_VECTCLRACTIVE_Pos     1U
#define SCB_AIRCR_VECTCLRACTIVE_Msk    (1UL << SCB_AIRCR_VECTCLRACTIVE_Pos)
#define SCB_AIRCR_VECTRESET_Pos         0U
#define SCB_AIRCR_VECTRESET_Msk        (1UL << SCB_AIRCR_VECTRESET_Pos)

/**
 * @brief SCB_AIRCR_VECTKEY: Vector key (must be 0x5FA to write)
 * @brief SCB_AIRCR_VECTKEY：向量密钥（必须为 0x5FA 才能写入）
 * Key value to protect against accidental writes / 防止意外写入的密钥值
 */
#define SCB_AIRCR_VECTKEY             (0x5FAUL << SCB_AIRCR_VECTKEY_Pos)

/**
 * @brief SCB_AIRCR_VECTKEYSTAT: Vector key status
 * @brief SCB_AIRCR_VECTKEYSTAT：向量密钥状态
 * Reads as 0xFA05 / 读取值为 0xFA05
 */
#define SCB_AIRCR_VECTKEYSTAT         (0xFA05UL << SCB_AIRCR_VECTKEYSTAT_Pos)

/**
 * @brief SCB_AIRCR_ENDIANESS: Data endianness bit
 * @brief SCB_AIRCR_ENDIANESS：数据大小端位
 * 0: Little-endian / 小端
 * 1: Big-endian / 大端
 */
#define SCB_AIRCR_ENDIANESS           (1UL << SCB_AIRCR_ENDIANESS_Pos)

/**
 * @brief SCB_AIRCR_PRIGROUP: Priority grouping field
 * @brief SCB_AIRCR_PRIGROUP：优先级分组字段
 * Determines how the 8-bit priority is split into preemption priority and sub-priority
 * 确定 8 位优先级如何拆分为抢占优先级和子优先级
 */
#define SCB_AIRCR_PRIGROUP            (7UL << SCB_AIRCR_PRIGROUP_Pos)

/**
 * @brief SCB_AIRCR_SYSRESETREQ: System reset request
 * @brief SCB_AIRCR_SYSRESETREQ：系统复位请求
 * 1: Request system reset / 请求系统复位
 */
#define SCB_AIRCR_SYSRESETREQ         (1UL << SCB_AIRCR_SYSRESETREQ_Pos)

/**
 * @brief SCB_AIRCR_VECTCLRACTIVE: Clear active exception
 * @brief SCB_AIRCR_VECTCLRACTIVE：清除活动异常
 * 1: Clear all active state information for exceptions / 清除所有异常的活动状态信息
 */
#define SCB_AIRCR_VECTCLRACTIVE       (1UL << SCB_AIRCR_VECTCLRACTIVE_Pos)

/**
 * @brief SCB_AIRCR_VECTRESET: Local reset
 * @brief SCB_AIRCR_VECTRESET：本地复位
 * 1: Reset the processor core (local reset) / 复位处理器核心（本地复位）
 */
#define SCB_AIRCR_VECTRESET           (1UL << SCB_AIRCR_VECTRESET_Pos)

/**
 * SCB_SCR register bit definitions
 * SCB_SCR 寄存器位定义
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 */
#define SCB_SCR_SLEEPONEXIT_Pos         1U
#define SCB_SCR_SLEEPONEXIT_Msk        (1UL << SCB_SCR_SLEEPONEXIT_Pos)
#define SCB_SCR_SLEEPDEEP_Pos           2U
#define SCB_SCR_SLEEPDEEP_Msk          (1UL << SCB_SCR_SLEEPDEEP_Pos)
#define SCB_SCR_SEVONPEND_Pos           4U
#define SCB_SCR_SEVONPEND_Msk          (1UL << SCB_SCR_SEVONPEND_Pos)

/**
 * @brief SCB_SCR_SLEEPONEXIT: Sleep-on-exit bit
 * @brief SCB_SCR_SLEEPONEXIT：退出时进入睡眠位
 * 1: Enter sleep mode when returning from Handler mode / 从 Handler 模式返回时进入睡眠模式
 * 0: Do not sleep on exit / 退出时不进入睡眠
 */
#define SCB_SCR_SLEEPONEXIT            (1UL << SCB_SCR_SLEEPONEXIT_Pos)

/**
 * @brief SCB_SCR_SLEEPDEEP: Deep sleep enable bit
 * @brief SCB_SCR_SLEEPDEEP：深度睡眠使能位
 * 1: Use deep sleep mode / 使用深度睡眠模式
 * 0: Use sleep mode / 使用睡眠模式
 */
#define SCB_SCR_SLEEPDEEP              (1UL << SCB_SCR_SLEEPDEEP_Pos)

/**
 * @brief SCB_SCR_SEVONPEND: Send event on pending interrupt bit
 * @brief SCB_SCR_SEVONPEND：挂起中断时发送事件位
 * 1: Send event when interrupt becomes pending / 当中断变为挂起时发送事件
 * 0: Only send event on explicit SEV instruction / 仅在显式 SEV 指令时发送事件
 */
#define SCB_SCR_SEVONPEND              (1UL << SCB_SCR_SEVONPEND_Pos)

/**
 * SCB_CCR register bit definitions
 * SCB_CCR 寄存器位定义
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 */
#define SCB_CCR_STKALIGN_Pos            9U
#define SCB_CCR_STKALIGN_Msk           (1UL << SCB_CCR_STKALIGN_Pos)
#define SCB_CCR_FPEXC_Pos              10U
#define SCB_CCR_FPEXC_Msk             (1UL << SCB_CCR_FPEXC_Pos)
#define SCB_CCR_DIV_0_Pos              4U
#define SCB_CCR_DIV_0_Msk             (1UL << SCB_CCR_DIV_0_Pos)
#define SCB_CCR_UNALIGNED_Pos          3U
#define SCB_CCR_UNALIGNED_Msk         (1UL << SCB_CCR_UNALIGNED_Pos)
#define SCB_CCR_NOCP_Pos               8U
#define SCB_CCR_NOCP_Msk              (1UL << SCB_CCR_NOCP_Pos)

/**
 * @brief SCB_CCR_STKALIGN: Stack alignment bit
 * @brief SCB_CCR_STKALIGN：栈对齐位
 * 1: 8-byte stack alignment on exception entry / 异常入口时 8 字节栈对齐
 * 0: 4-byte stack alignment / 4 字节栈对齐
 */
#define SCB_CCR_STKALIGN               (1UL << SCB_CCR_STKALIGN_Pos)

/**
 * @brief SCB_CCR_FPEXC: FPU exception enable bit
 * @brief SCB_CCR_FPEXC：FPU 异常使能位
 * 1: Enable FPU exceptions / 使能 FPU 异常
 * 0: Disable FPU exceptions / 禁用 FPU 异常
 */
#define SCB_CCR_FPEXC                  (1UL << SCB_CCR_FPEXC_Pos)

/**
 * @brief SCB_CCR_DIV_0: Divide by zero trap enable bit
 * @brief SCB_CCR_DIV_0：除零陷阱使能位
 * 1: Trap on divide by zero / 除零时触发陷阱
 * 0: Do not trap on divide by zero / 除零时不触发陷阱
 */
#define SCB_CCR_DIV_0                  (1UL << SCB_CCR_DIV_0_Pos)

/**
 * @brief SCB_CCR_UNALIGNED: Unaligned access trap enable bit
 * @brief SCB_CCR_UNALIGNED：未对齐访问陷阱使能位
 * 1: Trap on unaligned access / 未对齐访问时触发陷阱
 * 0: Do not trap on unaligned access / 未对齐访问时不触发陷阱
 */
#define SCB_CCR_UNALIGNED              (1UL << SCB_CCR_UNALIGNED_Pos)

/**
 * @brief SCB_CCR_NOCP: No coprocessor trap enable bit
 * @brief SCB_CCR_NOCP：无协处理器陷阱使能位
 * 1: Trap on coprocessor access when coprocessor not present / 协处理器不存在时访问触发陷阱
 * 0: Do not trap / 不触发陷阱
 */
#define SCB_CCR_NOCP                   (1UL << SCB_CCR_NOCP_Pos)

/**
 * SysTick Control and Status Register bits
 * SysTick 控制和状态寄存器位
 * Reference: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (系统定时器, SysTick)
 */
#define SYSTICK_CTRL_COUNTFLAG_Pos     16U
#define SYSTICK_CTRL_COUNTFLAG_Msk     (1UL << SYSTICK_CTRL_COUNTFLAG_Pos)
#define SYSTICK_CTRL_CLKSOURCE_Pos      2U
#define SYSTICK_CTRL_CLKSOURCE_Msk     (1UL << SYSTICK_CTRL_CLKSOURCE_Pos)
#define SYSTICK_CTRL_TICKINT_Pos        1U
#define SYSTICK_CTRL_TICKINT_Msk       (1UL << SYSTICK_CTRL_TICKINT_Pos)
#define SYSTICK_CTRL_ENABLE_Pos         0U
#define SYSTICK_CTRL_ENABLE_Msk        (1UL << SYSTICK_CTRL_ENABLE_Pos)

/**
 * @brief SYSTICK_CTRL_COUNTFLAG: Count flag
 * @brief SYSTICK_CTRL_COUNTFLAG：计数标志
 * 1: Timer counted to 0 since last read / 自上次读取以来定时器计数到 0
 * 0: Timer not counted to 0 / 定时器未计数到 0
 */
#define SYSTICK_CTRL_COUNTFLAG         (1UL << SYSTICK_CTRL_COUNTFLAG_Pos)

/**
 * @brief SYSTICK_CTRL_CLKSOURCE: Clock source select
 * @brief SYSTICK_CTRL_CLKSOURCE：时钟源选择
 * 0: External reference clock / 外部参考时钟
 * 1: Processor clock / 处理器时钟
 */
#define SYSTICK_CTRL_CLKSOURCE         (1UL << SYSTICK_CTRL_CLKSOURCE_Pos)

/**
 * @brief SYSTICK_CTRL_TICKINT: Tick interrupt enable
 * @brief SYSTICK_CTRL_TICKINT：Tick 中断使能
 * 1: Enable SysTick exception / 使能 SysTick 异常
 * 0: Disable SysTick exception / 禁用 SysTick 异常
 */
#define SYSTICK_CTRL_TICKINT           (1UL << SYSTICK_CTRL_TICKINT_Pos)

/**
 * @brief SYSTICK_CTRL_ENABLE: Counter enable
 * @brief SYSTICK_CTRL_ENABLE：计数器使能
 * 1: Counter enabled / 计数器使能
 * 0: Counter disabled / 计数器禁用
 */
#define SYSTICK_CTRL_ENABLE            (1UL << SYSTICK_CTRL_ENABLE_Pos)

/**
 * SysTick Calibration Register bits
 * SysTick 校准寄存器位
 * Reference: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (系统定时器, SysTick)
 */
#define SYSTICK_CALIB_NOREF_Pos         31U
#define SYSTICK_CALIB_NOREF_Msk        (1UL << SYSTICK_CALIB_NOREF_Pos)
#define SYSTICK_CALIB_SKEW_Pos          30U
#define SYSTICK_CALIB_SKEW_Msk         (1UL << SYSTICK_CALIB_SKEW_Pos)
#define SYSTICK_CALIB_TENMS_Pos          0U
#define SYSTICK_CALIB_TENMS_Msk        (0xFFFFFFUL << SYSTICK_CALIB_TENMS_Pos)

/**
 * @brief SYSTICK_CALIB_NOREF: No reference clock
 * @brief SYSTICK_CALIB_NOREF：无参考时钟
 * 1: No external reference clock provided / 未提供外部参考时钟
 * 0: External reference clock provided / 提供外部参考时钟
 */
#define SYSTICK_CALIB_NOREF            (1UL << SYSTICK_CALIB_NOREF_Pos)

/**
 * @brief SYSTICK_CALIB_SKEW: Calibration value skew
 * @brief SYSTICK_CALIB_SKEW：校准值偏差
 * 1: Calibration value is not exactly 10ms / 校准值不精确为 10ms
 * 0: Calibration value is exactly 10ms / 校准值精确为 10ms
 */
#define SYSTICK_CALIB_SKEW             (1UL << SYSTICK_CALIB_SKEW_Pos)

/**
 * @brief SYSTICK_CALIB_TENMS: 10ms calibration value
 * @brief SYSTICK_CALIB_TENMS：10ms 校准值
 * Number of clock cycles for 10ms / 10ms 的时钟周期数
 */
#define SYSTICK_CALIB_TENMS            (0xFFFFFFUL << SYSTICK_CALIB_TENMS_Pos)

/**
 * MPU Control Register bits
 * MPU 控制寄存器位
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 */
#define MPU_CTRL_ENABLE_Pos              0U
#define MPU_CTRL_ENABLE_Msk             (1UL << MPU_CTRL_ENABLE_Pos)
#define MPU_CTRL_HFNMIENA_Pos           1U
#define MPU_CTRL_HFNMIENA_Msk           (1UL << MPU_CTRL_HFNMIENA_Pos)
#define MPU_CTRL_PRIVDEFENA_Pos         2U
#define MPU_CTRL_PRIVDEFENA_Msk         (1UL << MPU_CTRL_PRIVDEFENA_Pos)

/**
 * @brief MPU_CTRL_ENABLE: MPU enable bit
 * @brief MPU_CTRL_ENABLE：MPU 使能位
 * 1: MPU enabled / MPU 使能
 * 0: MPU disabled / MPU 禁用
 */
#define MPU_CTRL_ENABLE                 (1UL << MPU_CTRL_ENABLE_Pos)

/**
 * @brief MPU_CTRL_HFNMIENA: MPU enable during HardFault and NMI
 * @brief MPU_CTRL_HFNMIENA：HardFault 和 NMI 期间 MPU 使能
 * 1: MPU enabled during HardFault and NMI / HardFault 和 NMI 期间 MPU 使能
 * 0: MPU disabled during HardFault and NMI / HardFault 和 NMI 期间 MPU 禁用
 */
#define MPU_CTRL_HFNMIENA              (1UL << MPU_CTRL_HFNMIENA_Pos)

/**
 * @brief MPU_CTRL_PRIVDEFENA: Privileged default memory map enable
 * @brief MPU_CTRL_PRIVDEFENA：特权默认内存映射使能
 * 1: Enable privileged software default memory map / 使能特权软件默认内存映射
 * 0: Disable privileged software default memory map / 禁用特权软件默认内存映射
 */
#define MPU_CTRL_PRIVDEFENA            (1UL << MPU_CTRL_PRIVDEFENA_Pos)

/**
 * MPU Region Attribute and Size Register bits
 * MPU 区域属性和大小寄存器位
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 */
#define MPU_RBAR_VALID_Pos              4U
#define MPU_RBAR_VALID_Msk             (1UL << MPU_RBAR_VALID_Pos)
#define MPU_RBAR_REGION_Pos             0U
#define MPU_RBAR_REGION_Msk            (0xFUL << MPU_RBAR_REGION_Pos)

#define MPU_RLAR_ATTRINDEX_Pos          3U
#define MPU_RLAR_ATTRINDEX_Msk         (7UL << MPU_RLAR_ATTRINDEX_Pos)
#define MPU_RLAR_XN_Pos                 4U
#define MPU_RLAR_XN_Msk                (1UL << MPU_RLAR_XN_Pos)
#define MPU_RLAR_ENABLE_Pos             0U
#define MPU_RLAR_ENABLE_Msk            (1UL << MPU_RLAR_ENABLE_Pos)

/**
 * @brief MPU_RBAR_VALID: Region valid bit
 * @brief MPU_RBAR_VALID：区域有效位
 * 1: Region number valid / 区域编号有效
 * 0: Region number not valid / 区域编号无效
 */
#define MPU_RBAR_VALID                 (1UL << MPU_RBAR_VALID_Pos)

/**
 * @brief MPU_RBAR_REGION: Region number
 * @brief MPU_RBAR_REGION：区域编号
 * Selects the region number to configure / 选择要配置的区域编号
 */
#define MPU_RBAR_REGION                (0xFUL << MPU_RBAR_REGION_Pos)

/**
 * @brief MPU_RLAR_ATTRINDEX: Attribute index
 * @brief MPU_RLAR_ATTRINDEX：属性索引
 * Selects memory attribute from MAIR registers / 从 MAIR 寄存器选择内存属性
 */
#define MPU_RLAR_ATTRINDEX             (7UL << MPU_RLAR_ATTRINDEX_Pos)

/**
 * @brief MPU_RLAR_XN: Execute never bit
 * @brief MPU_RLAR_XN：永不执行位
 * 1: Region not executable / 区域不可执行
 * 0: Region executable / 区域可执行
 */
#define MPU_RLAR_XN                    (1UL << MPU_RLAR_XN_Pos)

/**
 * @brief MPU_RLAR_ENABLE: Region enable bit
 * @brief MPU_RLAR_ENABLE：区域使能位
 * 1: Region enabled / 区域使能
 * 0: Region disabled / 区域禁用
 */
#define MPU_RLAR_ENABLE                (1UL << MPU_RLAR_ENABLE_Pos)

/**
 * MPU Memory Attribute Indirection Register definitions
 * MPU 内存属性间接寄存器定义
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 */
#define MPU_MAIR0_Attr0_Pos             0U
#define MPU_MAIR0_Attr0_Msk            (0xFFUL << MPU_MAIR0_Attr0_Pos)
#define MPU_MAIR0_Attr1_Pos             8U
#define MPU_MAIR0_Attr1_Msk            (0xFFUL << MPU_MAIR0_Attr1_Pos)
#define MPU_MAIR0_Attr2_Pos            16U
#define MPU_MAIR0_Attr2_Msk            (0xFFUL << MPU_MAIR0_Attr2_Pos)
#define MPU_MAIR0_Attr3_Pos            24U
#define MPU_MAIR0_Attr3_Msk            (0xFFUL << MPU_MAIR0_Attr3_Pos)

#define MPU_MAIR1_Attr4_Pos             0U
#define MPU_MAIR1_Attr4_Msk            (0xFFUL << MPU_MAIR1_Attr4_Pos)
#define MPU_MAIR1_Attr5_Pos             8U
#define MPU_MAIR1_Attr5_Msk            (0xFFUL << MPU_MAIR1_Attr5_Pos)
#define MPU_MAIR1_Attr6_Pos            16U
#define MPU_MAIR1_Attr6_Msk            (0xFFUL << MPU_MAIR1_Attr6_Pos)
#define MPU_MAIR1_Attr7_Pos            24U
#define MPU_MAIR1_Attr7_Msk            (0xFFUL << MPU_MAIR1_Attr7_Pos)

/**
 * SAU Control Register bits
 * SAU 控制寄存器位
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 */
#define SAU_CTRL_ENABLE_Pos              0U
#define SAU_CTRL_ENABLE_Msk             (1UL << SAU_CTRL_ENABLE_Pos)
#define SAU_CTRL_ALLNS_Pos              1U
#define SAU_CTRL_ALLNS_Msk             (1UL << SAU_CTRL_ALLNS_Pos)

/**
 * @brief SAU_CTRL_ENABLE: SAU enable bit
 * @brief SAU_CTRL_ENABLE：SAU 使能位
 * 1: SAU enabled / SAU 使能
 * 0: SAU disabled / SAU 禁用
 */
#define SAU_CTRL_ENABLE                 (1UL << SAU_CTRL_ENABLE_Pos)

/**
 * @brief SAU_CTRL_ALLNS: All Non-Secure bit
 * @brief SAU_CTRL_ALLNS：全部非安全位
 * 1: All memory is Non-Secure except SAU regions / 除 SAU 区域外全部内存为非安全
 * 0: Use SAU regions for security attribution / 使用 SAU 区域进行安全属性设置
 */
#define SAU_CTRL_ALLNS                  (1UL << SAU_CTRL_ALLNS_Pos)

/**
 * SAU Region Register bits
 * SAU 区域寄存器位
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 */
#define SAU_RNR_REGION_Pos              0U
#define SAU_RNR_REGION_Msk             (0xFUL << SAU_RNR_REGION_Pos)

#define SAU_RBAR_BADDR_Pos              5U
#define SAU_RBAR_BADDR_Msk             (0x7FFFFFFUL << SAU_RBAR_BADDR_Pos)
#define SAU_RBAR_VALID_Pos              4U
#define SAU_RBAR_VALID_Msk             (1UL << SAU_RBAR_VALID_Pos)

#define SAU_RLAR_LADDR_Pos              5U
#define SAU_RLAR_LADDR_Msk             (0x7FFFFFFUL << SAU_RLAR_LADDR_Pos)
#define SAU_RLAR_NSC_Pos                3U
#define SAU_RLAR_NSC_Msk               (1UL << SAU_RLAR_NSC_Pos)
#define SAU_RLAR_ENABLE_Pos             0U
#define SAU_RLAR_ENABLE_Msk            (1UL << SAU_RLAR_ENABLE_Pos)

/**
 * @brief SAU_RNR_REGION: Region number
 * @brief SAU_RNR_REGION：区域编号
 * Selects the SAU region number to configure / 选择要配置的 SAU 区域编号
 */
#define SAU_RNR_REGION                 (0xFUL << SAU_RNR_REGION_Pos)

/**
 * @brief SAU_RBAR_BADDR: Base address
 * @brief SAU_RBAR_BADDR：基地址
 * Region base address (32-byte aligned) / 区域基地址（32 字节对齐）
 */
#define SAU_RBAR_BADDR                 (0x7FFFFFFUL << SAU_RBAR_BADDR_Pos)

/**
 * @brief SAU_RBAR_VALID: Region valid bit
 * @brief SAU_RBAR_VALID：区域有效位
 * 1: Region number valid / 区域编号有效
 * 0: Region number not valid / 区域编号无效
 */
#define SAU_RBAR_VALID                 (1UL << SAU_RBAR_VALID_Pos)

/**
 * @brief SAU_RLAR_LADDR: Limit address
 * @brief SAU_RLAR_LADDR：限地址
 * Region limit address (32-byte aligned) / 区域限地址（32 字节对齐）
 */
#define SAU_RLAR_LADDR                 (0x7FFFFFFUL << SAU_RLAR_LADDR_Pos)

/**
 * @brief SAU_RLAR_NSC: Non-Secure Callable bit
 * @brief SAU_RLAR_NSC：非安全可调用位
 * 1: Region is Non-Secure Callable / 区域为非安全可调用
 * 0: Region is Secure or Non-Secure / 区域为安全或非安全
 */
#define SAU_RLAR_NSC                   (1UL << SAU_RLAR_NSC_Pos)

/**
 * @brief SAU_RLAR_ENABLE: Region enable bit
 * @brief SAU_RLAR_ENABLE：区域使能位
 * 1: Region enabled / 区域使能
 * 0: Region disabled / 区域禁用
 */
#define SAU_RLAR_ENABLE                (1UL << SAU_RLAR_ENABLE_Pos)

/**
 * PMU Control Register bits
 * PMU 控制寄存器位
 * Reference: Arm® v8-M ARM Chapter B15 (The Performance Monitors Extension)
 * 参考: Arm® v8-M ARM Chapter B15 (性能监视器扩展)
 */
#define PMU_CTRL_E_Pos                 0U
#define PMU_CTRL_E_Msk                (1UL << PMU_CTRL_E_Pos)
#define PMU_CTRL_P_Pos                 1U
#define PMU_CTRL_P_Msk                (1UL << PMU_CTRL_P_Pos)
#define PMU_CTRL_C_Pos                 2U
#define PMU_CTRL_C_Msk                (1UL << PMU_CTRL_C_Pos)
#define PMU_CTRL_DP_Pos                5U
#define PMU_CTRL_DP_Msk               (1UL << PMU_CTRL_DP_Pos)
#define PMU_CTRL_FZO_Pos               9U
#define PMU_CTRL_FZO_Msk              (1UL << PMU_CTRL_FZO_Pos)
#define PMU_CTRL_TRO_Pos              11U
#define PMU_CTRL_TRO_Msk             (1UL << PMU_CTRL_TRO_Pos)

/**
 * @brief PMU_CTRL_E: Enable all counters
 * @brief PMU_CTRL_E：使能所有计数器
 * 1: All counters enabled / 所有计数器使能
 * 0: All counters disabled / 所有计数器禁用
 */
#define PMU_CTRL_E                    (1UL << PMU_CTRL_E_Pos)

/**
 * @brief PMU_CTRL_P: Event counter reset
 * @brief PMU_CTRL_P：事件计数器复位
 * 1: Reset all event counters / 复位所有事件计数器
 * 0: No action / 无动作
 */
#define PMU_CTRL_P                    (1UL << PMU_CTRL_P_Pos)

/**
 * @brief PMU_CTRL_C: Cycle counter reset
 * @brief PMU_CTRL_C：周期计数器复位
 * 1: Reset cycle counter / 复位周期计数器
 * 0: No action / 无动作
 */
#define PMU_CTRL_C                    (1UL << PMU_CTRL_C_Pos)

/**
 * @brief PMU_CTRL_DP: Disable cycle counter in debug
 * @brief PMU_CTRL_DP：调试时禁用周期计数器
 * 1: Cycle counter disabled in debug / 调试时周期计数器禁用
 * 0: Cycle counter enabled in debug / 调试时周期计数器使能
 */
#define PMU_CTRL_DP                   (1UL << PMU_CTRL_DP_Pos)

/**
 * @brief PMU_CTRL_FZO: Freeze counters on overflow
 * @brief PMU_CTRL_FZO：溢出时冻结计数器
 * 1: Freeze counters on overflow / 溢出时冻结计数器
 * 0: Do not freeze counters on overflow / 溢出时不冻结计数器
 */
#define PMU_CTRL_FZO                  (1UL << PMU_CTRL_FZO_Pos)

/**
 * @brief PMU_CTRL_TRO: Trace request override
 * @brief PMU_CTRL_TRO：跟踪请求覆盖
 * 1: Trace request override enabled / 跟踪请求覆盖使能
 * 0: Trace request override disabled / 跟踪请求覆盖禁用
 */
#define PMU_CTRL_TRO                  (1UL << PMU_CTRL_TRO_Pos)

/**
 * PMU Events
 * PMU 事件
 * Reference: Arm® v8-M ARM Chapter B15 (The Performance Monitors Extension)
 * 参考: Arm® v8-M ARM 第 B15 章 (性能监视器扩展)
 */
#define PMU_EVENT_SW_INCR                            0x0000             /*!< Software update to the PMU_SWINC register, architecturally executed and condition code check pass */
#define PMU_EVENT_L1I_CACHE_REFILL                   0x0001             /*!< L1 I-Cache refill */
#define PMU_EVENT_L1D_CACHE_REFILL                   0x0003             /*!< L1 D-Cache refill */
#define PMU_EVENT_L1D_CACHE                          0x0004             /*!< L1 D-Cache access */
#define PMU_EVENT_LD_RETIRED                         0x0006             /*!< Memory-reading instruction architecturally executed and condition code check pass */
#define PMU_EVENT_ST_RETIRED                         0x0007             /*!< Memory-writing instruction architecturally executed and condition code check pass */
#define PMU_EVENT_INST_RETIRED                       0x0008             /*!< Instruction architecturally executed */
#define PMU_EVENT_EXC_TAKEN                          0x0009             /*!< Exception entry */
#define PMU_EVENT_EXC_RETURN                         0x000A             /*!< Exception return instruction architecturally executed and the condition code check pass */
#define PMU_EVENT_PC_WRITE_RETIRED                   0x000C             /*!< Software change to the Program Counter (PC). Instruction is architecturally executed and condition code check pass */
#define PMU_EVENT_BR_IMMED_RETIRED                   0x000D             /*!< Immediate branch architecturally executed */
#define PMU_EVENT_BR_RETURN_RETIRED                  0x000E             /*!< Function return instruction architecturally executed and the condition code check pass */
#define PMU_EVENT_UNALIGNED_LDST_RETIRED             0x000F             /*!< Unaligned memory memory-reading or memory-writing instruction architecturally executed and condition code check pass */
#define PMU_EVENT_BR_MIS_PRED                        0x0010             /*!< Mispredicted or not predicted branch speculatively executed */
#define PMU_EVENT_CPU_CYCLES                         0x0011             /*!< Cycle */
#define PMU_EVENT_BR_PRED                            0x0012             /*!< Predictable branch speculatively executed */
#define PMU_EVENT_MEM_ACCESS                         0x0013             /*!< Data memory access */
#define PMU_EVENT_L1I_CACHE                          0x0014             /*!< Level 1 instruction cache access */
#define PMU_EVENT_L1D_CACHE_WB                       0x0015             /*!< Level 1 data cache write-back */
#define PMU_EVENT_L2D_CACHE                          0x0016             /*!< Level 2 data cache access */
#define PMU_EVENT_L2D_CACHE_REFILL                   0x0017             /*!< Level 2 data cache refill */
#define PMU_EVENT_L2D_CACHE_WB                       0x0018             /*!< Level 2 data cache write-back */
#define PMU_EVENT_BUS_ACCESS                         0x0019             /*!< Bus access */
#define PMU_EVENT_MEMORY_ERROR                       0x001A             /*!< Local memory error */
#define PMU_EVENT_INST_SPEC                          0x001B             /*!< Instruction speculatively executed */
#define PMU_EVENT_BUS_CYCLES                         0x001D             /*!< Bus cycles */
#define PMU_EVENT_CHAIN                              0x001E             /*!< For an odd numbered counter, increment when an overflow occurs on the preceding even-numbered counter on the same PE */
#define PMU_EVENT_L1D_CACHE_ALLOCATE                 0x001F             /*!< Level 1 data cache allocation without refill */
#define PMU_EVENT_L2D_CACHE_ALLOCATE                 0x0020             /*!< Level 2 data cache allocation without refill */
#define PMU_EVENT_BR_RETIRED                         0x0021             /*!< Branch instruction architecturally executed */
#define PMU_EVENT_BR_MIS_PRED_RETIRED                0x0022             /*!< Mispredicted branch instruction architecturally executed */
#define PMU_EVENT_STALL_FRONTEND                     0x0023             /*!< No operation issued because of the frontend */
#define PMU_EVENT_STALL_BACKEND                      0x0024             /*!< No operation issued because of the backend */
#define PMU_EVENT_L2I_CACHE                          0x0027             /*!< Level 2 instruction cache access */
#define PMU_EVENT_L2I_CACHE_REFILL                   0x0028             /*!< Level 2 instruction cache refill */
#define PMU_EVENT_L3D_CACHE_ALLOCATE                 0x0029             /*!< Level 3 data cache allocation without refill */
#define PMU_EVENT_L3D_CACHE_REFILL                   0x002A             /*!< Level 3 data cache refill */
#define PMU_EVENT_L3D_CACHE                          0x002B             /*!< Level 3 data cache access */
#define PMU_EVENT_L3D_CACHE_WB                       0x002C             /*!< Level 3 data cache write-back */
#define PMU_EVENT_LL_CACHE_RD                        0x0036             /*!< Last level data cache read */
#define PMU_EVENT_LL_CACHE_MISS_RD                   0x0037             /*!< Last level data cache read miss */
#define PMU_EVENT_L1D_CACHE_MISS_RD                  0x0039             /*!< Level 1 data cache read miss */
#define PMU_EVENT_OP_COMPLETE                        0x003A             /*!< Operation retired */
#define PMU_EVENT_OP_SPEC                            0x003B             /*!< Operation speculatively executed */
#define PMU_EVENT_STALL                              0x003C             /*!< Stall cycle for instruction or operation not sent for execution */
#define PMU_EVENT_STALL_OP_BACKEND                   0x003D             /*!< Stall cycle for instruction or operation not sent for execution due to pipeline backend */
#define PMU_EVENT_STALL_OP_FRONTEND                  0x003E             /*!< Stall cycle for instruction or operation not sent for execution due to pipeline frontend */
#define PMU_EVENT_STALL_OP                           0x003F             /*!< Instruction or operation slots not occupied each cycle */
#define PMU_EVENT_L1D_CACHE_RD                       0x0040             /*!< Level 1 data cache read */

/**
 * PMU Events - Armv8.1-M Extensions (Loop, Branch Future, Security, DWT)
 * PMU 事件 - Armv8.1-M 扩展（循环、分支未来、安全、DWT）
 * Reference: Arm® v8-M ARM Chapter B15 (The Performance Monitors Extension)
 */
#define PMU_EVENT_LE_RETIRED                         0x0100             /*!< Loop end instruction executed */
#define PMU_EVENT_LE_SPEC                            0x0101             /*!< Loop end instruction speculatively executed */
#define PMU_EVENT_BF_RETIRED                         0x0104             /*!< Branch future instruction architecturally executed and condition code check pass */
#define PMU_EVENT_BF_SPEC                            0x0105             /*!< Branch future instruction speculatively executed and condition code check pass */
#define PMU_EVENT_LE_CANCEL                          0x0108             /*!< Loop end instruction not taken */
#define PMU_EVENT_BF_CANCEL                          0x0109             /*!< Branch future instruction not taken */
#define PMU_EVENT_SE_CALL_S                          0x0114             /*!< Call to secure function, resulting in Security state change */
#define PMU_EVENT_SE_CALL_NS                         0x0115             /*!< Call to non-secure function, resulting in Security state change */
#define PMU_EVENT_DWT_CMPMATCH0                      0x0118             /*!< DWT comparator 0 match */
#define PMU_EVENT_DWT_CMPMATCH1                      0x0119             /*!< DWT comparator 1 match */
#define PMU_EVENT_DWT_CMPMATCH2                      0x011A             /*!< DWT comparator 2 match */
#define PMU_EVENT_DWT_CMPMATCH3                      0x011B             /*!< DWT comparator 3 match */

/**
 * PMU Events - MVE (Helium) Extensions
 * PMU 事件 - MVE (Helium) 扩展
 * Reference: Arm® v8-M ARM Chapter B15 (The Performance Monitors Extension)
 */
#define PMU_EVENT_MVE_INST_RETIRED                   0x0200             /*!< MVE instruction architecturally executed */
#define PMU_EVENT_MVE_INST_SPEC                      0x0201             /*!< MVE instruction speculatively executed */
#define PMU_EVENT_MVE_FP_RETIRED                     0x0204             /*!< MVE floating-point instruction architecturally executed */
#define PMU_EVENT_MVE_FP_SPEC                        0x0205             /*!< MVE floating-point instruction speculatively executed */
#define PMU_EVENT_MVE_FP_HP_RETIRED                  0x0208             /*!< MVE half-precision floating-point instruction architecturally executed */
#define PMU_EVENT_MVE_FP_HP_SPEC                     0x0209             /*!< MVE half-precision floating-point instruction speculatively executed */
#define PMU_EVENT_MVE_FP_SP_RETIRED                  0x020C             /*!< MVE single-precision floating-point instruction architecturally executed */
#define PMU_EVENT_MVE_FP_SP_SPEC                     0x020D             /*!< MVE single-precision floating-point instruction speculatively executed */
#define PMU_EVENT_MVE_FP_MAC_RETIRED                 0x0214             /*!< MVE floating-point multiply or multiply-accumulate instruction architecturally executed */
#define PMU_EVENT_MVE_FP_MAC_SPEC                    0x0215             /*!< MVE floating-point multiply or multiply-accumulate instruction speculatively executed */
#define PMU_EVENT_MVE_INT_RETIRED                    0x0224             /*!< MVE integer instruction architecturally executed */
#define PMU_EVENT_MVE_INT_SPEC                       0x0225             /*!< MVE integer instruction speculatively executed */
#define PMU_EVENT_MVE_INT_MAC_RETIRED                0x0228             /*!< MVE multiply or multiply-accumulate instruction architecturally executed */
#define PMU_EVENT_MVE_INT_MAC_SPEC                   0x0229             /*!< MVE multiply or multiply-accumulate instruction speculatively executed */
#define PMU_EVENT_MVE_LDST_RETIRED                   0x0238             /*!< MVE load or store instruction architecturally executed */
#define PMU_EVENT_MVE_LDST_SPEC                      0x0239             /*!< MVE load or store instruction speculatively executed */
#define PMU_EVENT_MVE_LD_RETIRED                     0x023C             /*!< MVE load instruction architecturally executed */
#define PMU_EVENT_MVE_LD_SPEC                        0x023D             /*!< MVE load instruction speculatively executed */
#define PMU_EVENT_MVE_ST_RETIRED                     0x0240             /*!< MVE store instruction architecturally executed */
#define PMU_EVENT_MVE_ST_SPEC                        0x0241             /*!< MVE store instruction speculatively executed */
#define PMU_EVENT_MVE_LDST_CONTIG_RETIRED            0x0244             /*!< MVE contiguous load or store instruction architecturally executed */
#define PMU_EVENT_MVE_LDST_CONTIG_SPEC               0x0245             /*!< MVE contiguous load or store instruction speculatively executed */
#define PMU_EVENT_MVE_LD_CONTIG_RETIRED              0x0248             /*!< MVE contiguous load instruction architecturally executed */
#define PMU_EVENT_MVE_LD_CONTIG_SPEC                 0x0249             /*!< MVE contiguous load instruction speculatively executed */
#define PMU_EVENT_MVE_ST_CONTIG_RETIRED              0x024C             /*!< MVE contiguous store instruction architecturally executed */
#define PMU_EVENT_MVE_ST_CONTIG_SPEC                 0x024D             /*!< MVE contiguous store instruction speculatively executed */
#define PMU_EVENT_MVE_LDST_NONCONTIG_RETIRED         0x0250             /*!< MVE non-contiguous load or store instruction architecturally executed */
#define PMU_EVENT_MVE_LDST_NONCONTIG_SPEC            0x0251             /*!< MVE non-contiguous load or store instruction speculatively executed */
#define PMU_EVENT_MVE_LD_NONCONTIG_RETIRED           0x0254             /*!< MVE non-contiguous load instruction architecturally executed */
#define PMU_EVENT_MVE_LD_NONCONTIG_SPEC              0x0255             /*!< MVE non-contiguous load instruction speculatively executed */
#define PMU_EVENT_MVE_ST_NONCONTIG_RETIRED           0x0258             /*!< MVE non-contiguous store instruction architecturally executed */
#define PMU_EVENT_MVE_ST_NONCONTIG_SPEC              0x0259             /*!< MVE non-contiguous store instruction speculatively executed */
#define PMU_EVENT_MVE_LDST_MULTI_RETIRED             0x025C             /*!< MVE memory instruction targeting multiple registers architecturally executed */
#define PMU_EVENT_MVE_LDST_MULTI_SPEC                0x025D             /*!< MVE memory instruction targeting multiple registers speculatively executed */
#define PMU_EVENT_MVE_LD_MULTI_RETIRED               0x0260             /*!< MVE memory load instruction targeting multiple registers architecturally executed */
#define PMU_EVENT_MVE_LD_MULTI_SPEC                  0x0261             /*!< MVE memory load instruction targeting multiple registers speculatively executed */
#define PMU_EVENT_MVE_ST_MULTI_RETIRED               0x0262             /*!< MVE memory store instruction targeting multiple registers architecturally executed */
#define PMU_EVENT_MVE_ST_MULTI_SPEC                  0x0265             /*!< MVE memory store instruction targeting multiple registers speculatively executed */
#define PMU_EVENT_MVE_LDST_UNALIGNED_RETIRED         0x028C             /*!< MVE unaligned memory load or store instruction architecturally executed */
#define PMU_EVENT_MVE_LDST_UNALIGNED_SPEC            0x028D             /*!< MVE unaligned memory load or store instruction speculatively executed */
#define PMU_EVENT_MVE_LD_UNALIGNED_RETIRED           0x0290             /*!< MVE unaligned load instruction architecturally executed */
#define PMU_EVENT_MVE_LD_UNALIGNED_SPEC              0x0291             /*!< MVE unaligned load instruction speculatively executed */
#define PMU_EVENT_MVE_ST_UNALIGNED_RETIRED           0x0294             /*!< MVE unaligned store instruction architecturally executed */
#define PMU_EVENT_MVE_ST_UNALIGNED_SPEC              0x0295             /*!< MVE unaligned store instruction speculatively executed */
#define PMU_EVENT_MVE_LDST_UNALIGNED_NONCONTIG_RETIRED 0x0298             /*!< MVE unaligned noncontiguous load or store instruction architecturally executed */
#define PMU_EVENT_MVE_LDST_UNALIGNED_NONCONTIG_SPEC    0x0299             /*!< MVE unaligned noncontiguous load or store instruction speculatively executed */
#define PMU_EVENT_MVE_VREDUCE_RETIRED                0x02A0             /*!< MVE vector reduction instruction architecturally executed */
#define PMU_EVENT_MVE_VREDUCE_SPEC                   0x02A1             /*!< MVE vector reduction instruction speculatively executed */
#define PMU_EVENT_MVE_VREDUCE_FP_RETIRED             0x02A4             /*!< MVE floating-point vector reduction instruction architecturally executed */
#define PMU_EVENT_MVE_VREDUCE_FP_SPEC                0x02A5             /*!< MVE floating-point vector reduction instruction speculatively executed */
#define PMU_EVENT_MVE_VREDUCE_INT_RETIRED            0x02A8             /*!< MVE integer vector reduction instruction architecturally executed */
#define PMU_EVENT_MVE_VREDUCE_INT_SPEC               0x02A9             /*!< MVE integer vector reduction instruction speculatively executed */
#define PMU_EVENT_MVE_PRED                            0x02B8             /*!< Cycles where one or more predicated beats architecturally executed */
#define PMU_EVENT_MVE_STALL                           0x02CC             /*!< Stall cycles caused by an MVE instruction */
#define PMU_EVENT_MVE_STALL_RESOURCE                  0x02CD             /*!< Stall cycles caused by an MVE instruction because of resource conflicts */
#define PMU_EVENT_MVE_STALL_RESOURCE_MEM              0x02CE             /*!< Stall cycles caused by an MVE instruction because of memory resource conflicts */
#define PMU_EVENT_MVE_STALL_RESOURCE_FP               0x02CF             /*!< Stall cycles caused by an MVE instruction because of floating-point resource conflicts */
#define PMU_EVENT_MVE_STALL_RESOURCE_INT              0x02D0             /*!< Stall cycles caused by an MVE instruction because of integer resource conflicts */
#define PMU_EVENT_MVE_STALL_BREAK                     0x02D3             /*!< Stall cycles caused by an MVE chain break */
#define PMU_EVENT_MVE_STALL_DEPENDENCY                0x02D4             /*!< Stall cycles caused by MVE register dependency */

/**
 * PMU Events - TCM, ETM, CTI Events
 * PMU 事件 - TCM、ETM、CTI 事件
 * Reference: Arm® v8-M ARM Chapter B15 (The Performance Monitors Extension)
 */
#define PMU_EVENT_ITCM_ACCESS                         0x4007             /*!< Instruction TCM access */
#define PMU_EVENT_DTCM_ACCESS                         0x4008             /*!< Data TCM access */
#define PMU_EVENT_TRCEXTOUT0                          0x4010             /*!< ETM external output 0 */
#define PMU_EVENT_TRCEXTOUT1                          0x4011             /*!< ETM external output 1 */
#define PMU_EVENT_TRCEXTOUT2                          0x4012             /*!< ETM external output 2 */
#define PMU_EVENT_TRCEXTOUT3                          0x4013             /*!< ETM external output 3 */
#define PMU_EVENT_CTI_TRIGOUT4                        0x4018             /*!< Cross-trigger Interface output trigger 4 */
#define PMU_EVENT_CTI_TRIGOUT5                        0x4019             /*!< Cross-trigger Interface output trigger 5 */
#define PMU_EVENT_CTI_TRIGOUT6                        0x401A             /*!< Cross-trigger Interface output trigger 6 */
#define PMU_EVENT_CTI_TRIGOUT7                        0x401B             /*!< Cross-trigger Interface output trigger 7 */

/**
 * ITM Control Register bits
 * ITM 控制寄存器位
 * Reference: Arm® v8-M ARM Chapter B14 (Debug and Trace Components) 7.2.3
 * 参考: Arm® v8-M ARM Chapter B14 (调试和跟踪组件) 7.2.3
 */
#define ITM_CTRL_ITMENA_Pos              0U
#define ITM_CTRL_ITMENA_Msk             (1UL << ITM_CTRL_ITMENA_Pos)
#define ITM_CTRL_TRCENA_Pos             2U
#define ITM_CTRL_TRCENA_Msk            (1UL << ITM_CTRL_TRCENA_Pos)
#define ITM_CTRL_BUSY_Pos               7U
#define ITM_CTRL_BUSY_Msk              (1UL << ITM_CTRL_BUSY_Pos)

/**
 * @brief ITM_CTRL_ITMENA: ITM enable bit
 * @brief ITM_CTRL_ITMENA：ITM 使能位
 * 1: ITM enabled / ITM 使能
 * 0: ITM disabled / ITM 禁用
 */
#define ITM_CTRL_ITMENA                 (1UL << ITM_CTRL_ITMENA_Pos)

/**
 * @brief ITM_CTRL_TRCENA: Trace enable bit
 * @brief ITM_CTRL_TRCENA：跟踪使能位
 * 1: Trace enabled / 跟踪使能
 * 0: Trace disabled / 跟踪禁用
 */
#define ITM_CTRL_TRCENA                (1UL << ITM_CTRL_TRCENA_Pos)

/**
 * @brief ITM_CTRL_BUSY: Busy flag
 * @brief ITM_CTRL_BUSY：忙标志
 * 1: ITM is busy / ITM 忙
 * 0: ITM is not busy / ITM 不忙
 */
#define ITM_CTRL_BUSY                  (1UL << ITM_CTRL_BUSY_Pos)

/**
 * FPU Coprocessor Access Control bits
 * FPU 协处理器访问控制位
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 */
#define CPACR_CP10_Pos                  20U
#define CPACR_CP10_Msk                 (3UL << CPACR_CP10_Pos)
#define CPACR_CP11_Pos                  22U
#define CPACR_CP11_Msk                 (3UL << CPACR_CP11_Pos)

/**
 * @brief CPACR_CP10: Coprocessor 10 access control
 * @brief CPACR_CP10：协处理器 10 访问控制
 * 00: No access / 无访问权限
 * 01: Privileged access only / 仅特权访问
 * 10: Reserved / 保留
 * 11: Full access / 完全访问
 */
#define CPACR_CP10                     (3UL << CPACR_CP10_Pos)

/**
 * @brief CPACR_CP11: Coprocessor 11 access control
 * @brief CPACR_CP11：协处理器 11 访问控制
 * 00: No access / 无访问权限
 * 01: Privileged access only / 仅特权访问
 * 10: Reserved / 保留
 * 11: Full access / 完全访问
 */
#define CPACR_CP11                     (3UL << CPACR_CP11_Pos)

/**
 * MPU Memory Attribute definitions
 * MPU 内存属性定义
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture) 4.5.7
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构) 4.5.7
 *
 * Device memory attributes:
 * 设备内存属性:
 *   - nG: non Gathering (不聚合)
 *   - nR: non Re-ordering (不重排序)
 *   - nE: non Early Write Acknowledgement (不提前写确认)
 *
 * Normal memory attributes:
 * 普通内存属性:
 *   - I: Inner cacheability (内部缓存性)
 *   - O: Outer cacheability (外部缓存性)
 *   - WB: Write Back (写回)
 *   - WT: Write Through (写通)
 *   - RA: Read Allocate (读分配)
 *   - WA: Write Allocate (写分配)
 *   - NC: Non-Cacheable (不可缓存)
 */

/**
 * @brief MPU_DEVICE_nGnRnE: Device memory, non Gathering, non Re-ordering, non Early Write Acknowledgement
 * @brief MPU_DEVICE_nGnRnE：设备内存，不聚合，不重排序，不提前写确认
 */
#define MPU_DEVICE_nGnRnE              0x00U

/**
 * @brief MPU_DEVICE_nGnRE: Device memory, non Gathering, non Re-ordering, Early Write Acknowledgement
 * @brief MPU_DEVICE_nGnRE：设备内存，不聚合，不重排序，提前写确认
 */
#define MPU_DEVICE_nGnRE               0x04U

/**
 * @brief MPU_DEVICE_nGRE: Device memory, non Gathering, Re-ordering, Early Write Acknowledgement
 * @brief MPU_DEVICE_nGRE：设备内存，不聚合，重排序，提前写确认
 */
#define MPU_DEVICE_nGRE                0x08U

/**
 * @brief MPU_DEVICE_GRE: Device memory, Gathering, Re-ordering, Early Write Acknowledgement
 * @brief MPU_DEVICE_GRE：设备内存，聚合，重排序，提前写确认
 */
#define MPU_DEVICE_GRE                 0x0CU

/**
 * @brief MPU_NORMAL_MEMORY_IWBWA_OWBWA: Normal memory, Inner Write-Back Write-Allocate, Outer Write-Back Write-Allocate
 * @brief MPU_NORMAL_MEMORY_IWBWA_OWBWA：普通内存，内部写回写分配，外部写回写分配
 */
#define MPU_NORMAL_MEMORY_IWBWA_OWBWA   0xF0U

/**
 * @brief MPU_NORMAL_MEMORY_IWBWA_OWBNA: Normal memory, Inner Write-Back Write-Allocate, Outer Write-Back No-Allocate
 * @brief MPU_NORMAL_MEMORY_IWBWA_OWBNA：普通内存，内部写回写分配，外部写回不分配
 */
#define MPU_NORMAL_MEMORY_IWBWA_OWBNA   0xE0U

/**
 * @brief MPU_NORMAL_MEMORY_IBTFA: Normal memory, Inner Write-Back Transient, Outer Write-Back Transient
 * @brief MPU_NORMAL_MEMORY_IBTFA：普通内存，内部写回临时，外部写回临时
 */
#define MPU_NORMAL_MEMORY_IBTFA         0xB0U

/**
 * @brief MPU_NORMAL_MEMORY_IWBWA_NC: Normal memory, Inner Write-Back Write-Allocate, Outer Non-Cacheable
 * @brief MPU_NORMAL_MEMORY_IWBWA_NC：普通内存，内部写回写分配，外部不可缓存
 */
#define MPU_NORMAL_MEMORY_IWBWA_NC      0xD0U

/**
 * @brief MPU_NORMAL_MEMORY_IBTFA_NC: Normal memory, Inner Write-Back Transient, Outer Non-Cacheable
 * @brief MPU_NORMAL_MEMORY_IBTFA_NC：普通内存，内部写回临时，外部不可缓存
 */
#define MPU_NORMAL_MEMORY_IBTFA_NC      0x90U

/**
 * @brief MPU_NORMAL_MEMORY_IWBNWA_OWBWA: Normal memory, Inner Write-Back No-Allocate, Outer Write-Back Write-Allocate
 * @brief MPU_NORMAL_MEMORY_IWBNWA_OWBWA：普通内存，内部写回不分配，外部写回写分配
 */
#define MPU_NORMAL_MEMORY_IWBNWA_OWBWA  0xC0U

/**
 * @brief MPU_NORMAL_MEMORY_IWBNWA_OWBNA: Normal memory, Inner Write-Back No-Allocate, Outer Write-Back No-Allocate
 * @brief MPU_NORMAL_MEMORY_IWBNWA_OWBNA：普通内存，内部写回不分配，外部写回不分配
 */
#define MPU_NORMAL_MEMORY_IWBNWA_OWBNA  0x80U

/**
 * @brief MPU_NORMAL_MEMORY_IWBNWA_NC: Normal memory, Inner Write-Back No-Allocate, Outer Non-Cacheable
 * @brief MPU_NORMAL_MEMORY_IWBNWA_NC：普通内存，内部写回不分配，外部不可缓存
 */
#define MPU_NORMAL_MEMORY_IWBNWA_NC    0x40U

/**
 * @brief MPU_NORMAL_NONCACHEABLE: Normal memory, Non-Cacheable
 * @brief MPU_NORMAL_NONCACHEABLE：普通内存，不可缓存
 */
#define MPU_NORMAL_NONCACHEABLE         0x00U

/**
 * MPU Configuration Macros (CMSIS 6 style)
 * MPU 配置宏 (CMSIS 6 风格)
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 */

/** \brief Attribute for device memory (outer only) */
#define ARM_MPU_ATTR_DEVICE                           ( 0U )

/** \brief Attribute for non-cacheable, normal memory */
#define ARM_MPU_ATTR_NON_CACHEABLE                    ( 4U )

/** \brief Attribute for Normal memory, Outer and Inner cacheability.
* \param NT Non-Transient: Set to 1 for Non-transient data. Set to 0 for Transient data.
* \param WB Write-Back: Set to 1 to use a Write-Back policy. Set to 0 to use a Write-Through policy.
* \param RA Read Allocation: Set to 1 to enable cache allocation on read miss. Set to 0 to disable cache allocation on read miss.
* \param WA Write Allocation: Set to 1 to enable cache allocation on write miss. Set to 0 to disable cache allocation on write miss.
*/
#define ARM_MPU_ATTR_MEMORY_(NT, WB, RA, WA) \
  ((((NT) & 1U) << 3U) | (((WB) & 1U) << 2U) | (((RA) & 1U) << 1U) | ((WA) & 1U))

/** \brief Device memory type non Gathering, non Re-ordering, non Early Write Acknowledgement */
#define ARM_MPU_ATTR_DEVICE_nGnRnE (0U)

/** \brief Device memory type non Gathering, non Re-ordering, Early Write Acknowledgement */
#define ARM_MPU_ATTR_DEVICE_nGnRE  (1U)

/** \brief Device memory type non Gathering, Re-ordering, Early Write Acknowledgement */
#define ARM_MPU_ATTR_DEVICE_nGRE   (2U)

/** \brief Device memory type Gathering, Re-ordering, Early Write Acknowledgement */
#define ARM_MPU_ATTR_DEVICE_GRE    (3U)

/** \brief Normal memory outer-cacheable and inner-cacheable attributes
* WT = Write Through, WB = Write Back, TR = Transient, RA = Read-Allocate, WA = Write Allocate
*/
#define MPU_ATTR_NORMAL_OUTER_NON_CACHEABLE (0b0100)
#define MPU_ATTR_NORMAL_OUTER_WT_TR_RA      (0b0010)
#define MPU_ATTR_NORMAL_OUTER_WT_TR_WA      (0b0001)
#define MPU_ATTR_NORMAL_OUTER_WT_TR_RA_WA   (0b0011)
#define MPU_ATTR_NORMAL_OUTER_WT_RA         (0b1010)
#define MPU_ATTR_NORMAL_OUTER_WT_WA         (0b1001)
#define MPU_ATTR_NORMAL_OUTER_WT_RA_WA      (0b1011)
#define MPU_ATTR_NORMAL_OUTER_WB_TR_RA      (0b0110)
#define MPU_ATTR_NORMAL_OUTER_WB_TR_WA      (0b0101)
#define MPU_ATTR_NORMAL_OUTER_WB_TR_RA_WA   (0b0111)
#define MPU_ATTR_NORMAL_OUTER_WB_RA         (0b1110)
#define MPU_ATTR_NORMAL_OUTER_WB_WA         (0b1101)
#define MPU_ATTR_NORMAL_OUTER_WB_RA_WA      (0b1111)
#define MPU_ATTR_NORMAL_INNER_NON_CACHEABLE (0b0100)
#define MPU_ATTR_NORMAL_INNER_WT_TR_RA      (0b0010)
#define MPU_ATTR_NORMAL_INNER_WT_TR_WA      (0b0001)
#define MPU_ATTR_NORMAL_INNER_WT_TR_RA_WA   (0b0011)
#define MPU_ATTR_NORMAL_INNER_WT_RA         (0b1010)
#define MPU_ATTR_NORMAL_INNER_WT_WA         (0b1001)
#define MPU_ATTR_NORMAL_INNER_WT_RA_WA      (0b1011)
#define MPU_ATTR_NORMAL_INNER_WB_TR_RA      (0b0110)
#define MPU_ATTR_NORMAL_INNER_WB_TR_WA      (0b0101)
#define MPU_ATTR_NORMAL_INNER_WB_TR_RA_WA   (0b0111)
#define MPU_ATTR_NORMAL_INNER_WB_RA         (0b1110)
#define MPU_ATTR_NORMAL_INNER_WB_WA         (0b1101)
#define MPU_ATTR_NORMAL_INNER_WB_RA_WA      (0b1111)

/** \brief Memory Attribute
* \param O Outer memory attributes
* \param I O == ARM_MPU_ATTR_DEVICE: Device memory attributes, else: Inner memory attributes
*/
#define ARM_MPU_ATTR(O, I) ((((O) & 0xFU) << 4U) | ((((O) & 0xFU) != 0U) ? ((I) & 0xFU) : (((I) & 0x3U) << 2U)))

/** \brief Shareability */
/** \brief Normal memory, non-shareable  */
#define ARM_MPU_SH_NON   (0U)

/** \brief Normal memory, outer shareable  */
#define ARM_MPU_SH_OUTER (2U)

/** \brief Normal memory, inner shareable  */
#define ARM_MPU_SH_INNER (3U)

/** \brief Access permissions */
/** \brief Normal memory, read/write */
#define ARM_MPU_AP_RW (0U)

/** \brief Normal memory, read-only */
#define ARM_MPU_AP_RO (1U)

/** \brief Normal memory, any privilege level */
#define ARM_MPU_AP_NP (1U)

/** \brief Normal memory, privileged access only */
#define ARM_MPU_AP_PO (0U)

/** \brief Memory access permissions
* \param RO Read-Only: Set to 1 for read-only memory. Set to 0 for a read/write memory.
* \param NP Non-Privileged: Set to 1 for non-privileged memory. Set to 0 for privileged memory.
*/
#define ARM_MPU_AP_(RO, NP) ((((RO) & 1U) << 1U) | ((NP) & 1U))

/** \brief Execute-never */
/** \brief Normal memory, Execution not permitted */
#define ARM_MPU_XN (1U)

/** \brief Normal memory, Execution only permitted if read permitted */
#define ARM_MPU_EX (0U)

/**
 * MPU RBAR and RLAR register bit definitions for macro usage
 * MPU RBAR 和 RLAR 寄存器位定义，用于宏
 */
#define MPU_RBAR_BASE_Pos               5U
#define MPU_RBAR_BASE_Msk               (0x7FFFFFFUL << MPU_RBAR_BASE_Pos)
#define MPU_RBAR_SH_Pos                 3U
#define MPU_RBAR_SH_Msk                 (3UL << MPU_RBAR_SH_Pos)
#define MPU_RBAR_AP_Pos                 1U
#define MPU_RBAR_AP_Msk                 (3UL << MPU_RBAR_AP_Pos)
#define MPU_RBAR_XN_Pos                 0U
#define MPU_RBAR_XN_Msk                 (1UL << MPU_RBAR_XN_Pos)

#define MPU_RLAR_LIMIT_Pos              5U
#define MPU_RLAR_LIMIT_Msk              (0x7FFFFFFUL << MPU_RLAR_LIMIT_Pos)
#define MPU_RLAR_AttrIndx_Pos           1U
#define MPU_RLAR_AttrIndx_Msk           (7UL << MPU_RLAR_AttrIndx_Pos)
#define MPU_RLAR_EN_Pos                 0U
#define MPU_RLAR_EN_Msk                 (1UL << MPU_RLAR_EN_Pos)

#define MPU_TYPE_RALIASES               4U

/** \brief Region Base Address Register value
* \param BASE The base address bits [31:5] of a memory region. The value is zero extended. Effective address gets 32 byte aligned.
* \param SH Defines the Shareability domain for this memory region.
* \param RO Read-Only: Set to 1 for a read-only memory region. Set to 0 for a read/write memory region.
* \param NP Non-Privileged: Set to 1 for a non-privileged memory region. Set to 0 for privileged memory region.
* \param XN eXecute Never: Set to 1 for a non-executable memory region. Set to 0 for an executable memory region.
*/
#define ARM_MPU_RBAR(BASE, SH, RO, NP, XN) \
  (((BASE) & MPU_RBAR_BASE_Msk) | \
  (((SH) << MPU_RBAR_SH_Pos) & MPU_RBAR_SH_Msk) | \
  ((ARM_MPU_AP_(RO, NP) << MPU_RBAR_AP_Pos) & MPU_RBAR_AP_Msk) | \
  (((XN) << MPU_RBAR_XN_Pos) & MPU_RBAR_XN_Msk))

/** \brief Region Limit Address Register value
* \param LIMIT The limit address bits [31:5] for this memory region. The value is one extended.
* \param IDX The attribute index to be associated with this memory region.
*/
#define ARM_MPU_RLAR(LIMIT, IDX) \
  (((LIMIT) & MPU_RLAR_LIMIT_Msk) | \
  (((IDX) << MPU_RLAR_AttrIndx_Pos) & MPU_RLAR_AttrIndx_Msk) | \
  (MPU_RLAR_EN_Msk))

/**
* Struct for a single MPU Region
* 单个 MPU 区域结构体
*/
typedef struct {
  uint32_t RBAR;                   /*!< Region Base Address Register value */
  uint32_t RLAR;                   /*!< Region Limit Address Register value */
} ARM_MPU_Region_t;

/*
 * ============================================================================
 * ARMv8-M Task Context Structure
 * ARMv8-M 任务上下文结构体
 *
 * Task context is used to save and restore task execution state.
 * ARMv8-M adds MSP/PSP limit registers compared to ARMv7-M.
 * 任务上下文用于保存和恢复任务执行状态。
 * ARMv8-M 比 ARMv7-M 增加了 MSP/PSP 限制寄存器。
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
 *   msplim:  MSP Limit Register (MSP 限制寄存器)
 *   psplim:  PSP Limit Register (PSP 限制寄存器)
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
    uint32_t msplim;
    uint32_t psplim;
} ArmV8mTaskContext;

/*
 * ============================================================================
 * ARMv8-M Exception Frame Structure
 * ARMv8-M 异常帧结构体
 *
 * Exception frame is pushed onto the stack when an exception occurs.
 * 发生异常时，异常帧被压入栈中。
 *
 * Members:
 *   r0-r3:  General purpose registers (通用寄存器)
 *   r12:    Register R12 (寄存器 R12)
 *   lr:     Link Register (连接寄存器)
 *   pc:     Program Counter (程序计数器)
 *   xpsr:   Program Status Register (程序状态寄存器)
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
} ArmV8mExceptionFrame;

/*
 * ============================================================================
 * ARMv8-M Core Register Access Functions
 * ARMv8-M 核心寄存器访问函数
 * ============================================================================
 */

/**
 * @brief Get CONTROL register value
 * @brief 获取 CONTROL 寄存器值
 *
 * CONTROL register controls:
 * CONTROL 寄存器控制:
 *   - BIT[0]: nPRIV - Privilege level (0=privileged, 1=user)
 *   - BIT[1]: SPSel - Stack pointer select (0=MSP, 1=PSP)
 *   - BIT[2]: FPCA - FPU active state (1=FPU active, 0=no FPU)
 *   - BIT[4]: SFPA - Secure floating point active (TrustZone)
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @return Current CONTROL register value
 * @return CONTROL 寄存器当前值
 */
uint32_t arch_armv8m_get_control(void);

/**
 * @brief Set CONTROL register value
 * @brief 设置 CONTROL 寄存器值
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @param control: New CONTROL register value
 * @param control: CONTROL 寄存器新值
 */
void arch_armv8m_set_control(uint32_t control);

/**
 * @brief Get Main Stack Pointer (MSP)
 * @brief 获取主栈指针 (MSP)
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @return Current MSP value
 * @return 当前 MSP 值
 */
uint32_t arch_armv8m_get_msp(void);

/**
 * @brief Set Main Stack Pointer (MSP)
 * @brief 设置主栈指针 (MSP)
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @param msp: New MSP value
 * @param msp: 新的 MSP 值
 */
void arch_armv8m_set_msp(uint32_t msp);

/**
 * @brief Get Process Stack Pointer (PSP)
 * @brief 获取进程栈指针 (PSP)
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @return Current PSP value
 * @return 当前 PSP 值
 */
uint32_t arch_armv8m_get_psp(void);

/**
 * @brief Set Process Stack Pointer (PSP)
 * @brief 设置进程栈指针 (PSP)
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @param psp: New PSP value
 * @param psp: 新的 PSP 值
 */
void arch_armv8m_set_psp(uint32_t psp);

/**
 * @brief Get PRIMASK register
 * @brief 获取 PRIMASK 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @return Current PRIMASK value (0=interrupts enabled, 1=interrupts disabled)
 * @return 当前 PRIMASK 值 (0=中断使能, 1=中断禁用)
 */
uint32_t arch_armv8m_get_primask(void);

/**
 * @brief Set PRIMASK register
 * @brief 设置 PRIMASK 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @param primask: New PRIMASK value
 * @param primask: 新的 PRIMASK 值
 */
void arch_armv8m_set_primask(uint32_t primask);

/**
 * @brief Get BASEPRI register
 * @brief 获取 BASEPRI 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @return Current BASEPRI value
 * @return 当前 BASEPRI 值
 */
uint32_t arch_armv8m_get_basepri(void);

/**
 * @brief Set BASEPRI register
 * @brief 设置 BASEPRI 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @param basepri: New BASEPRI value (0=disable, 1-255=mask priority <= basepri)
 * @param basepri: 新的 BASEPRI 值 (0=禁用, 1-255=屏蔽优先级 <= basepri)
 */
void arch_armv8m_set_basepri(uint32_t basepri);

/**
 * @brief Get FAULTMASK register
 * @brief 获取 FAULTMASK 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @return Current FAULTMASK value
 * @return 当前 FAULTMASK 值
 */
uint32_t arch_armv8m_get_faultmask(void);

/**
 * @brief Set FAULTMASK register
 * @brief 设置 FAULTMASK 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @param faultmask: New FAULTMASK value
 * @param faultmask: 新的 FAULTMASK 值
 */
void arch_armv8m_set_faultmask(uint32_t faultmask);

/**
 * @brief Get MSPLIM register (MSP Limit)
 * @brief 获取 MSPLIM 寄存器 (MSP 限制)
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @return Current MSPLIM value
 * @return 当前 MSPLIM 值
 */
uint32_t arch_armv8m_get_msplim(void);

/**
 * @brief Set MSPLIM register
 * @brief 设置 MSPLIM 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @param msplim: New MSPLIM value
 * @param msplim: 新的 MSPLIM 值
 */
void arch_armv8m_set_msplim(uint32_t msplim);

/**
 * @brief Get PSPLIM register (PSP Limit)
 * @brief 获取 PSPLIM 寄存器 (PSP 限制)
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @return Current PSPLIM value
 * @return 当前 PSPLIM 值
 */
uint32_t arch_armv8m_get_psplim(void);

/**
 * @brief Set PSPLIM register
 * @brief 设置 PSPLIM 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @param psplim: New PSPLIM value
 * @param psplim: 新的 PSPLIM 值
 */
void arch_armv8m_set_psplim(uint32_t psplim);

/*
 * ============================================================================
 * ARMv8-M Status Register Access Functions
 * ARMv8-M 状态寄存器访问函数
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
uint32_t arch_armv8m_get_ipsr(void);

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
uint32_t arch_armv8m_get_apsr(void);

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
uint32_t arch_armv8m_get_xpsr(void);

/*
 * ============================================================================
 * ARMv8-M Memory Barrier Functions
 * ARMv8-M 内存屏障函数
 * ============================================================================
 */

/**
 * @brief Data Synchronization Barrier (DSB)
 * @brief 数据同步屏障 (DSB)
 *
 * Ensures all explicit memory accesses are completed before the next instruction.
 * 确保所有显式内存访问在下一条指令之前完成。
 */
void arch_armv8m_dsb(void);

/**
 * @brief Instruction Synchronization Barrier (ISB)
 * @brief 指令同步屏障 (ISB)
 *
 * Flushes the instruction pipeline to ensure instruction sequence is fetched.
 * 刷新指令管道以确保获取指令序列。
 */
void arch_armv8m_isb(void);

/**
 * @brief Data Memory Barrier (DMB)
 * @brief 数据内存屏障 (DMB)
 *
 * Ensures explicit memory accesses are observed in order.
 * 确保显式内存访问按顺序观察。
 */
void arch_armv8m_dmb(void);

/*
 * ============================================================================
 * ARMv8-M Low Power Mode Functions
 * ARMv8-M 低功耗模式函数
 * ============================================================================
 */

/**
 * @brief Wait For Interrupt (WFI)
 * @brief 等待中断 (WFI)
 *
 * Enter sleep mode, wake up on interrupt.
 * 进入睡眠模式，被中断唤醒。
 */
void arch_armv8m_wfi(void);

/**
 * @brief Wait For Event (WFE)
 * @brief 等待事件 (WFE)
 *
 * Enter sleep mode, wake up on event.
 * 进入睡眠模式，被事件唤醒。
 */
void arch_armv8m_wfe(void);

/**
 * @brief Send Event (SEV)
 * @brief 发送事件 (SEV)
 *
 * Send event to all cores in multiprocessor system.
 * 在多处理器系统中向所有核心发送事件。
 */
void arch_armv8m_sev(void);

/*
 * ============================================================================
 * ARMv8-M NVIC Interrupt Management Functions
 * ARMv8-M NVIC 中断管理函数
 * ============================================================================
 */

/**
 * @brief Enable specified interrupt
 * @brief 使能指定中断
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM Chapter B12 (嵌套向量中断控制器)
 *
 * @param irq: Interrupt number (0-239)
 * @param irq: 中断号 (0-239)
 */
void arch_armv8m_enable_irq(uint8_t irq);

/**
 * @brief Disable specified interrupt
 * @brief 禁用指定中断
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM Chapter B12 (嵌套向量中断控制器)
 *
 * @param irq: Interrupt number (0-239)
 * @param irq: 中断号 (0-239)
 */
void arch_armv8m_disable_irq(uint8_t irq);

/**
 * @brief Set interrupt priority
 * @brief 设置中断优先级
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM Chapter B12 (嵌套向量中断控制器)
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @param priority: Priority value (0=highest, 255=lowest)
 * @param priority: 优先级值 (0=最高, 255=最低)
 */
void arch_armv8m_set_priority(uint8_t irq, uint8_t priority);

/**
 * @brief Get interrupt priority
 * @brief 获取中断优先级
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @return Priority value
 * @return 优先级值
 */
uint8_t arch_armv8m_get_priority(uint8_t irq);

/**
 * @brief Set interrupt pending status
 * @brief 设置中断挂起状态
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 */
void arch_armv8m_set_pending(uint8_t irq);

/**
 * @brief Clear interrupt pending status
 * @brief 清除中断挂起状态
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 */
void arch_armv8m_clear_pending(uint8_t irq);

/**
 * @brief Get enable status of specified interrupt
 * @brief 获取指定中断的使能状态
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @return Enable status (0=disabled, 1=enabled)
 * @return 使能状态 (0=禁用, 1=使能)
 */
uint32_t arch_armv8m_get_enable_irq(uint8_t irq);

/**
 * @brief Get pending status of specified interrupt
 * @brief 获取指定中断的挂起状态
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @return Pending status (0=not pending, 1=pending)
 * @return 挂起状态 (0=未挂起, 1=挂起)
 */
uint32_t arch_armv8m_get_pending_irq(uint8_t irq);

/**
 * @brief Get currently executing interrupt
 * @brief 获取当前正在执行的中断
 *
 * @return Active interrupt number
 * @return 活动中断号
 */
uint32_t arch_armv8m_get_active_irq(void);

/**
 * @brief Get priority grouping
 * @brief 获取优先级分组
 *
 * @return Priority grouping value
 * @return 优先级分组值
 */
uint32_t arch_armv8m_get_priority_grouping(void);

/**
 * @brief Set priority grouping
 * @brief 设置优先级分组
 *
 * @param priority_group: Priority grouping value
 * @param priority_group: 优先级分组值
 */
void arch_armv8m_set_priority_grouping(uint32_t priority_group);

/**
 * @brief Encode priority
 * @brief 编码优先级
 *
 * @param priority_group: Priority grouping value
 * @param priority_group: 优先级分组值
 * @param preempt_priority: Preemption priority
 * @param preempt_priority: 抢占优先级
 * @param sub_priority: Sub-priority
 * @param sub_priority: 子优先级
 * @return Encoded priority value
 * @return 编码后的优先级值
 */
uint32_t arch_armv8m_encode_priority(uint32_t priority_group, uint32_t preempt_priority, uint32_t sub_priority);

/**
 * @brief Decode priority
 * @brief 解码优先级
 *
 * @param priority: Encoded priority value
 * @param priority: 编码后的优先级值
 * @param priority_group: Priority grouping value
 * @param priority_group: 优先级分组值
 * @param preempt_priority: Output preemption priority
 * @param preempt_priority: 输出抢占优先级
 * @param sub_priority: Output sub-priority
 * @param sub_priority: 输出子优先级
 */
void arch_armv8m_decode_priority(uint32_t priority, uint32_t priority_group, uint32_t *preempt_priority, uint32_t *sub_priority);

/**
 * @brief Set interrupt vector
 * @brief 设置中断向量
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @param vector: Vector address
 * @param vector: 向量地址
 */
void arch_armv8m_set_vector(uint8_t irq, uint32_t vector);

/**
 * @brief Get interrupt vector
 * @brief 获取中断向量
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @return Vector address
 * @return 向量地址
 */
uint32_t arch_armv8m_get_vector(uint8_t irq);

/*
 * ============================================================================
 * ARMv8-M MPU (Memory Protection Unit) Functions
 * ARMv8-M MPU (内存保护单元) 函数
 * ============================================================================
 */

/**
 * @brief Get MPU type
 * @brief 获取 MPU 类型
 *
 * MPU_TYPE register contains:
 * MPU_TYPE 寄存器包含:
 *   - IREGION: Number of instruction regions
 *   - DREGION: Number of data regions
 *   - SEPARATE: Instruction/Data separation flag
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @return MPU type register value
 * @return MPU 类型寄存器值
 */
uint32_t arch_armv8m_mpu_get_type(void);

/**
 * @brief Initialize MPU
 * @brief 初始化 MPU
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 */
void arch_armv8m_mpu_init(void);

/**
 * @brief Enable MPU
 * @brief 使能 MPU
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @param default_map: Use default memory map (true=enable, false=disable)
 * @param default_map: 使用默认内存映射 (true=启用, false=禁用)
 *
 * MPU_Control register bits:
 * MPU_Control 寄存器位:
 *   - ENABLE: MPU enable bit
 *   - HFNMIENA: Enable during NMI and HardFault
 *   - PRIVDEFENA: Privileged default memory map
 */
void arch_armv8m_mpu_enable(bool default_map);

/**
 * @brief Disable MPU
 * @brief 禁用 MPU
 */
void arch_armv8m_mpu_disable(void);

/**
 * @brief Set MPU memory attribute
 * @brief 设置 MPU 内存属性
 *
 * @param idx: Attribute index (0-7)
 * @param idx: 属性索引 (0-7)
 * @param attr: Memory attribute
 * @param attr: 内存属性
 *
 * Memory attribute encoding:
 * 内存属性编码:
 *   - Attr[7:4]: Outer Attr
 *   - Attr[3:0]: Inner Attr
 *   - Each Attr contains:
 *     - [3]: 1=forced cache policy, 0=device/uncached
 *     - [2]: Write-through/Write-back
 *     - [1]: Read allocate
 *     - [0]: Write allocate
 */
void arch_armv8m_mpu_set_mem_attr(uint8_t idx, uint8_t attr);

/**
 * @brief Set MPU region
 * @brief 设置 MPU 区域
 *
 * @param rnr: Region number (0-15)
 * @param rnr: 区域编号 (0-15)
 * @param rbar: Region Base Address Register
 * @param rbar: 区域基地址寄存器
 * @param rlar: Region Limit Register
 * @param rlar: 区域限制寄存器
 *
 * RBAR:
 * RBAR:
 *   - [31:5]: Base address (must be 32-byte aligned)
 *   - [31:5]: 基地址 (必须对齐到 32 字节)
 *   - [4:1]: Subregion disable bits
 *   - [4:1]: 子区域禁用位
 *   - [0]: VALID
 *   - [4:0]: REGION
 *
 * RLAR:
 * RLAR:
 *   - [31:5]: Limit address
 *   - [31:5]: 限地址
 *   - [4]: XN (Execute Never)
 *   - [3]: AP (Access permissions)
 *   - [2:1]: SH (Shareability)
 *   - [0]: ENABLE
 */
void arch_armv8m_mpu_set_region(uint32_t rnr, uint32_t rbar, uint32_t rlar);

/**
 * @brief Clear MPU region
 * @brief 清除 MPU 区域
 *
 * @param rnr: Region number
 * @param rnr: 区域编号
 */
void arch_armv8m_mpu_clr_region(uint32_t rnr);

/**
 * @brief Get MPU region count
 * @brief 获取 MPU 区域数量
 *
 * @return Number of data regions
 * @return 数据区域数量
 */
uint32_t arch_armv8m_mpu_get_num_regions(void);

/**
 * @brief Load MPU regions from table
 * @brief 从表加载 MPU 区域
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @param rnr: First region number to configure
 * @param rnr: 要配置的第一个区域编号
 * @param table: Pointer to MPU configuration table
 * @param table: 指向 MPU 配置表的指针
 * @param cnt: Number of regions to configure
 * @param cnt: 要配置的区域数量
 */
void arch_armv8m_mpu_load(uint32_t rnr, ARM_MPU_Region_t const* table, uint32_t cnt);

/**
 * @brief Load MPU regions from table (extended)
 * @brief 从表加载 MPU 区域（扩展版）
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @param mpu: Pointer to MPU registers
 * @param mpu: 指向 MPU 寄存器的指针
 * @param rnr: First region number to configure
 * @param rnr: 要配置的第一个区域编号
 * @param table: Pointer to MPU configuration table
 * @param table: 指向 MPU 配置表的指针
 * @param cnt: Number of regions to configure
 * @param cnt: 要配置的区域数量
 */
void arch_armv8m_mpu_load_ex(MPU_Type* mpu, uint32_t rnr, ARM_MPU_Region_t const* table, uint32_t cnt);

/**
 * @brief Set memory attribute (extended)
 * @brief 设置内存属性（扩展版）
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @param mpu: Pointer to MPU registers
 * @param mpu: 指向 MPU 寄存器的指针
 * @param idx: Attribute index (0-7)
 * @param idx: 属性索引 (0-7)
 * @param attr: Memory attribute
 * @param attr: 内存属性
 */
void arch_armv8m_mpu_set_mem_attr_ex(MPU_Type* mpu, uint8_t idx, uint8_t attr);

/**
 * @brief Set MPU region (extended)
 * @brief 设置 MPU 区域（扩展版）
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @param mpu: Pointer to MPU registers
 * @param mpu: 指向 MPU 寄存器的指针
 * @param rnr: Region number (0-15)
 * @param rnr: 区域编号 (0-15)
 * @param rbar: Region Base Address Register
 * @param rbar: 区域基地址寄存器
 * @param rlar: Region Limit Register
 * @param rlar: 区域限制寄存器
 */
void arch_armv8m_mpu_set_region_ex(MPU_Type* mpu, uint32_t rnr, uint32_t rbar, uint32_t rlar);

/**
 * @brief Clear MPU region (extended)
 * @brief 清除 MPU 区域（扩展版）
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @param mpu: Pointer to MPU registers
 * @param mpu: 指向 MPU 寄存器的指针
 * @param rnr: Region number
 * @param rnr: 区域编号
 */
void arch_armv8m_mpu_clr_region_ex(MPU_Type* mpu, uint32_t rnr);

#ifdef __TZ_PRESENT
/**
 * @brief Enable Non-secure MPU
 * @brief 使能非安全 MPU
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @param mpu_control: Default access permissions for unconfigured regions
 * @param mpu_control: 未配置区域的默认访问权限
 */
void arch_armv8m_mpu_enable_ns(uint32_t mpu_control);

/**
 * @brief Disable Non-secure MPU
 * @brief 禁用非安全 MPU
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 */
void arch_armv8m_mpu_disable_ns(void);

/**
 * @brief Set Non-secure MPU memory attribute
 * @brief 设置非安全 MPU 内存属性
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @param idx: Attribute index (0-7)
 * @param idx: 属性索引 (0-7)
 * @param attr: Memory attribute
 * @param attr: 内存属性
 */
void arch_armv8m_mpu_set_mem_attr_ns(uint8_t idx, uint8_t attr);

/**
 * @brief Set Non-secure MPU region
 * @brief 设置非安全 MPU 区域
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @param rnr: Region number (0-15)
 * @param rnr: 区域编号 (0-15)
 * @param rbar: Region Base Address Register
 * @param rbar: 区域基地址寄存器
 * @param rlar: Region Limit Register
 * @param rlar: 区域限制寄存器
 */
void arch_armv8m_mpu_set_region_ns(uint32_t rnr, uint32_t rbar, uint32_t rlar);

/**
 * @brief Clear Non-secure MPU region
 * @brief 清除非安全 MPU 区域
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @param rnr: Region number
 * @param rnr: 区域编号
 */
void arch_armv8m_mpu_clr_region_ns(uint32_t rnr);

/**
 * @brief Load Non-secure MPU regions from table
 * @brief 从表加载非安全 MPU 区域
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @param rnr: First region number to configure
 * @param rnr: 要配置的第一个区域编号
 * @param table: Pointer to MPU configuration table
 * @param table: 指向 MPU 配置表的指针
 * @param cnt: Number of regions to configure
 * @param cnt: 要配置的区域数量
 */
void arch_armv8m_mpu_load_ns(uint32_t rnr, ARM_MPU_Region_t const* table, uint32_t cnt);
#endif

/*
 * ============================================================================
 * ARMv8-M PMU (Performance Monitor Unit) Functions
 * ARMv8-M PMU (性能监视单元) 函数
 *
 * PMU is optional feature.
 * PMU 是可选功能。
 * Reference: ARMv8-M ARM Chapter B15 (The Performance Monitors Extension)
 * 参考: ARMv8-M ARM Chapter B15 (性能监视器扩展)
 * ============================================================================
 */

/**
 * @brief Enable PMU
 * @brief 使能 PMU
 *
 * Reference: Arm® v8-M ARM Chapter B15 (The Performance Monitors Extension)
 * 参考: Arm® v8-M ARM Chapter B15 (性能监视器扩展)
 */
void arch_armv8m_pmu_enable(void);

/**
 * @brief Disable PMU
 * @brief 禁用 PMU
 *
 * Reference: Arm® v8-M ARM Chapter B15 (The Performance Monitors Extension)
 * 参考: Arm® v8-M ARM Chapter B15 (性能监视器扩展)
 */
void arch_armv8m_pmu_disable(void);

/**
 * @brief Reset cycle counter
 * @brief 复位 cycle 计数器
 */
void arch_armv8m_pmu_cyccnt_reset(void);

/**
 * @brief Reset all event counters
 * @brief 复位所有事件计数器
 */
void arch_armv8m_pmu_evcntr_all_reset(void);

/**
 * @brief Enable counters
 * @brief 使能计数器
 *
 * @param mask: Counter mask (bit0=Cycle, bit1-31=event counters)
 * @param mask: 计数器掩码 (bit0=Cycle, bit1-31=事件计数器)
 */
void arch_armv8m_pmu_cntr_enable(uint32_t mask);

/**
 * @brief Disable counters
 * @brief 禁用计数器
 *
 * @param mask: Counter mask
 * @param mask: 计数器掩码
 */
void arch_armv8m_pmu_cntr_disable(uint32_t mask);

/**
 * @brief Get cycle counter value
 * @brief 获取 cycle 计数器值
 *
 * @return Cycle count
 * @return Cycle 计数
 */
uint32_t arch_armv8m_pmu_get_ccntr(void);

/**
 * @brief Get event counter value
 * @brief 获取事件计数器值
 *
 * @param num: Counter number (0-30)
 * @param num: 计数器编号 (0-30)
 * @return Event count value
 * @return 事件计数值
 */
uint32_t arch_armv8m_pmu_get_evcntr(uint32_t num);

/**
 * @brief Set event type
 * @brief 设置事件类型
 *
 * @param num: Counter number
 * @param num: 计数器编号
 * @param type: Event type
 * @param type: 事件类型
 */
void arch_armv8m_pmu_set_evtyper(uint32_t num, uint32_t type);

/**
 * @brief Get overflow status
 * @brief 获取溢出状态
 *
 * @return Overflow status mask
 * @return 溢出状态掩码
 */
uint32_t arch_armv8m_pmu_get_cntr_ovs(void);

/**
 * @brief Set overflow interrupt enable
 * @brief 设置溢出中断使能
 *
 * @param mask: Counter mask
 * @param mask: 计数器掩码
 */
void arch_armv8m_pmu_set_cntr_irq_enable(uint32_t mask);

/**
 * @brief Clear overflow interrupt enable
 * @brief 清除溢出中断使能
 *
 * @param mask: Counter mask
 * @param mask: 计数器掩码
 */
void arch_armv8m_pmu_set_cntr_irq_disable(uint32_t mask);

/**
 * @brief Software increment event counter
 * @brief 软件递增事件计数器
 *
 * Reference: Arm® v8-M ARM Chapter B15 (The Performance Monitors Extension)
 * 参考: Arm® v8-M ARM 第 B15 章 (性能监视器扩展)
 *
 * @param mask: Counters to increment
 * @param mask: 要递增的计数器
 */
void arch_armv8m_pmu_cntr_increment(uint32_t mask);

/**
 * @brief Clear counter overflow status
 * @brief 清除计数器溢出状态
 *
 * Reference: Arm® v8-M ARM Chapter B15 (The Performance Monitors Extension)
 * 参考: Arm® v8-M ARM 第 B15 章 (性能监视器扩展)
 *
 * @param mask: Overflow status bits to clear
 * @param mask: 要清除的溢出状态位
 */
void arch_armv8m_pmu_set_cntr_ovs(uint32_t mask);



/*
 * ============================================================================
 * ARMv8-M TrustZone (TZ) Functions
 * ARMv8-M TrustZone (TZ) 函数
 *
 * TrustZone is only supported on ARMv8-M Mainline
 * TrustZone 仅在 ARMv8-M Mainline 上支持
 * Reference: ARMv8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: ARMv8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 * ============================================================================
 */

/**
 * @brief Enable SAU (Security Attribution Unit)
 * @brief 使能 SAU (安全属性单元)
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 */
void arch_armv8m_tz_sau_enable(void);

/**
 * @brief Disable SAU
 * @brief 禁用 SAU
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 */
void arch_armv8m_tz_sau_disable(void);

/**
 * @brief Set SAU region count
 * @brief 设置 SAU 区域数量
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @param n: Region count (0-8)
 * @param n: 区域数量 (0-8)
 */
void arch_armv8m_tz_sau_set_region_count(uint32_t n);

/**
 * @brief Set SAU region
 * @brief 设置 SAU 区域
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @param rnr: Region number
 * @param rnr: 区域编号
 * @param rbar: Base address
 * @param rbar: 基地址
 * @param rlar: Limit address and attributes
 * @param rlar: 限地址和属性
 */
void arch_armv8m_tz_sau_set_region(uint32_t rnr, uint32_t rbar, uint32_t rlar);

/*
 * ============================================================================
 * ARMv8-M TrustZone (TZ) Non-Secure Functions
 * ARMv8-M TrustZone (TZ) 非安全区域函数
 *
 * These functions access non-secure registers when in secure state.
 * These functions are only available on ARMv8-M Mainline with TrustZone.
 * 这些函数在安全状态下访问非安全寄存器。
 * 这些函数仅在具有 TrustZone 的 ARMv8-M Mainline 上可用。
 * ============================================================================
 */

/**
 * @brief Get CONTROL register (Non-Secure)
 * @brief 获取 CONTROL 寄存器 (非安全)
 *
 * Returns the content of the non-secure Control Register when in secure mode.
 * 在安全模式下返回非安全 Control 寄存器的值。
 *
 * @return Non-secure CONTROL register value
 * @return 非安全 CONTROL 寄存器值
 */
uint32_t arch_armv8m_tz_get_control_ns(void);

/**
 * @brief Set CONTROL register (Non-Secure)
 * @brief 设置 CONTROL 寄存器 (非安全)
 *
 * Writes to the non-secure Control Register when in secure state.
 * 在安全状态下写入非安全 Control 寄存器。
 *
 * @param control: Non-secure CONTROL value
 * @param control: 非安全 CONTROL 值
 */
void arch_armv8m_tz_set_control_ns(uint32_t control);

/**
 * @brief Get PSP register (Non-Secure)
 * @brief 获取 PSP 寄存器 (非安全)
 *
 * Returns the current value of the non-secure Process Stack Pointer (PSP) when in secure state.
 * 在安全状态下返回非安全进程栈指针 (PSP) 的当前值。
 *
 * @return Non-secure PSP value
 * @return 非安全 PSP 值
 */
uint32_t arch_armv8m_tz_get_psp_ns(void);

/**
 * @brief Set PSP register (Non-Secure)
 * @brief 设置 PSP 寄存器 (非安全)
 *
 * Assigns the given value to the non-secure Process Stack Pointer (PSP) when in secure state.
 * 在安全状态下为非安全进程栈指针 (PSP) 分配给定值。
 *
 * @param psp: Non-secure PSP value
 * @param psp: 非安全 PSP 值
 */
void arch_armv8m_tz_set_psp_ns(uint32_t psp);

/**
 * @brief Get MSP register (Non-Secure)
 * @brief 获取 MSP 寄存器 (非安全)
 *
 * Returns the current value of the non-secure Main Stack Pointer (MSP) when in secure state.
 * 在安全状态下返回非安全主栈指针 (MSP) 的当前值。
 *
 * @return Non-secure MSP value
 * @return 非安全 MSP 值
 */
uint32_t arch_armv8m_tz_get_msp_ns(void);

/**
 * @brief Set MSP register (Non-Secure)
 * @brief 设置 MSP 寄存器 (非安全)
 *
 * Assigns the given value to the non-secure Main Stack Pointer (MSP) when in secure state.
 * 在安全状态下为非安全主栈指针 (MSP) 分配给定值。
 *
 * @param msp: Non-secure MSP value
 * @param msp: 非安全 MSP 值
 */
void arch_armv8m_tz_set_msp_ns(uint32_t msp);

/**
 * @brief Get PRIMASK register (Non-Secure)
 * @brief 获取 PRIMASK 寄存器 (非安全)
 *
 * Returns the current state of the non-secure priority mask bit from the Priority Mask Register when in secure state.
 * 在安全状态下从优先级屏蔽寄存器返回非安全优先级屏蔽位的当前状态。
 *
 * @return Non-secure PRIMASK value
 * @return 非安全 PRIMASK 值
 */
uint32_t arch_armv8m_tz_get_primask_ns(void);

/**
 * @brief Set PRIMASK register (Non-Secure)
 * @brief 设置 PRIMASK 寄存器 (非安全)
 *
 * Assigns the given value to the non-secure Priority Mask Register when in secure state.
 * 在安全状态下为非安全优先级屏蔽寄存器分配给定值。
 *
 * @param primask: Non-secure PRIMASK value
 * @param primask: 非安全 PRIMASK 值
 */
void arch_armv8m_tz_set_primask_ns(uint32_t primask);

/**
 * @brief Get BASEPRI register (Non-Secure)
 * @brief 获取 BASEPRI 寄存器 (非安全)
 *
 * Returns the current value of the non-secure Base Priority register when in secure state.
 * 在安全状态下返回非安全基础优先级寄存器的当前值。
 *
 * @return Non-secure BASEPRI value
 * @return 非安全 BASEPRI 值
 */
uint32_t arch_armv8m_tz_get_basepri_ns(void);

/**
 * @brief Set BASEPRI register (Non-Secure)
 * @brief 设置 BASEPRI 寄存器 (非安全)
 *
 * Assigns the given value to the non-secure Base Priority register when in secure state.
 * 在安全状态下为非安全基础优先级寄存器分配给定值。
 *
 * @param basepri: Non-secure BASEPRI value
 * @param basepri: 非安全 BASEPRI 值
 */
void arch_armv8m_tz_set_basepri_ns(uint32_t basepri);

/**
 * @brief Get FAULTMASK register (Non-Secure)
 * @brief 获取 FAULTMASK 寄存器 (非安全)
 *
 * Returns the current value of the non-secure Fault Mask register when in secure state.
 * 在安全状态下返回非安全故障屏蔽寄存器的当前值。
 *
 * @return Non-secure FAULTMASK value
 * @return 非安全 FAULTMASK 值
 */
uint32_t arch_armv8m_tz_get_faultmask_ns(void);

/**
 * @brief Set FAULTMASK register (Non-Secure)
 * @brief 设置 FAULTMASK 寄存器 (非安全)
 *
 * Assigns the given value to the non-secure Fault Mask register when in secure state.
 * 在安全状态下为非安全故障屏蔽寄存器分配给定值。
 *
 * @param faultmask: Non-secure FAULTMASK value
 * @param faultmask: 非安全 FAULTMASK 值
 */
void arch_armv8m_tz_set_faultmask_ns(uint32_t faultmask);

/**
 * @brief Get PSPLIM register (Non-Secure)
 * @brief 获取 PSPLIM 寄存器 (非安全)
 *
 * Returns the current value of the non-secure Process Stack Pointer Limit (PSPLIM) when in secure state.
 * 在安全状态下返回非安全进程栈指针限制 (PSPLIM) 的当前值。
 *
 * @return Non-secure PSPLIM value
 * @return 非安全 PSPLIM 值
 */
uint32_t arch_armv8m_tz_get_psplim_ns(void);

/**
 * @brief Set PSPLIM register (Non-Secure)
 * @brief 设置 PSPLIM 寄存器 (非安全)
 *
 * Assigns the given value to the non-secure Process Stack Pointer Limit (PSPLIM) when in secure state.
 * 在安全状态下为非安全进程栈指针限制 (PSPLIM) 分配给定值。
 *
 * @param psplim: Non-secure PSPLIM value
 * @param psplim: 非安全 PSPLIM 值
 */
void arch_armv8m_tz_set_psplim_ns(uint32_t psplim);

/**
 * @brief Get MSPLIM register (Non-Secure)
 * @brief 获取 MSPLIM 寄存器 (非安全)
 *
 * Returns the current value of the non-secure Main Stack Pointer Limit (MSPLIM) when in secure state.
 * 在安全状态下返回非安全主栈指针限制 (MSPLIM) 的当前值。
 *
 * @return Non-secure MSPLIM value
 * @return 非安全 MSPLIM 值
 */
uint32_t arch_armv8m_tz_get_msplim_ns(void);

/**
 * @brief Set MSPLIM register (Non-Secure)
 * @brief 设置 MSPLIM 寄存器 (非安全)
 *
 * Assigns the given value to the non-secure Main Stack Pointer Limit (MSPLIM) when in secure state.
 * 在安全状态下为非安全主栈指针限制 (MSPLIM) 分配给定值。
 *
 * @param msplim: Non-secure MSPLIM value
 * @param msplim: 非安全 MSPLIM 值
 */
void arch_armv8m_tz_set_msplim_ns(uint32_t msplim);

/**
 * @brief Get FPU type
 * @brief 获取 FPU 类型
 *
 * @return FPU type (0=none, 1=single precision, 2=double precision)
 * @return FPU 类型 (0=无, 1=单精度, 2=双精度)
 */
uint32_t arch_armv8m_scb_get_fpu_type(void);

/*
 * ============================================================================
 * ARMv8-M FPU Functions
 * ARMv8-M FPU 函数
 * ============================================================================
 */

/**
 * @brief Enable FPU
 * @brief 使能 FPU
 */
void arch_armv8m_enable_fpu(void);

/**
 * @brief Disable FPU
 * @brief 禁用 FPU
 */
void arch_armv8m_disable_fpu(void);

/*
 * ============================================================================
 * ARMv8-M System Control Functions
 * ARMv8-M 系统控制函数
 * ============================================================================
 */

/**
 * @brief Trigger system reset
 * @brief 触发系统复位
 */
void arch_armv8m_system_reset(void);

/*
 * ============================================================================
 * ARMv8-M Initialization and Context Switch Functions
 * ARMv8-M 初始化和上下文切换函数
 * ============================================================================
 */

/**
 * @brief ARMv8-M architecture initialization
 * @brief ARMv8-M 架构初始化
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 */
void arch_armv8m_init(void);

/**
 * @brief ARMv8-M vector table setup
 * @brief ARMv8-M 向量表设置
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 */
void arch_armv8m_setup_vector_table(void);

/**
 * @brief Initialize user task context
 * @brief 初始化用户任务上下文
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @param context: Task context structure
 * @param context: 任务上下文结构体
 * @param entry_point: Task entry point address
 * @param entry_point: 任务入口点地址
 * @param arg: Task argument
 * @param arg: 任务参数
 */
void arch_armv8m_init_user_context(ArmV8mTaskContext *context, uint32_t entry_point, uint32_t arg);

/**
 * @brief Context switch
 * @brief 上下文切换
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @param from: Source context
 * @param from: 源上下文
 * @param to: Target context
 * @param to: 目标上下文
 * @return New current context
 * @return 新的当前上下文
 */
void* arch_armv8m_switch_context(void *from, void *to);

/**
 * @brief Start first task
 * @brief 启动第一个任务
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @param context: Task context
 * @param context: 任务上下文
 * @return New current context
 * @return 新的当前上下文
 */
void* arch_armv8m_start_first_task(void *context);

/**
 * @brief Jump to kernel
 * @brief 跳转到内核
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @param vector_table_addr: Vector table address
 * @param vector_table_addr: 向量表地址
 */
void* arch_armv8m_jump_to_kernel(uint32_t vector_table_addr);

/*
 * ============================================================================
 * ARMv8-M SysTick Functions
 * ARMv8-M SysTick 函数
 * Reference: ARMv8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * ============================================================================
 */

/**
 * @brief SysTick configuration
 * @brief SysTick 配置
 *
 * Reference: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (系统定时器, SysTick)
 *
 * @param ticks: Number of ticks between interrupts
 * @param ticks: 中断之间的tick数
 * @return 1=success, 0=failed
 * @return 1=成功, 0=失败
 */
uint32_t arch_armv8m_systick_config(uint32_t ticks);

/**
 * @brief Get SysTick current value
 * @brief 获取 SysTick 当前值
 *
 * Reference: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (系统定时器, SysTick)
 *
 * @return Current counter value
 * @return 当前计数器值
 */
uint32_t arch_armv8m_systick_get_value(void);

/**
 * @brief Set SysTick reload value
 * @brief 设置 SysTick 加载值
 *
 * @param value: Reload value
 * @param value: 加载值
 */
void arch_armv8m_systick_set_reload(uint32_t value);

/**
 * @brief Get SysTick reload value
 * @brief 获取 SysTick 加载值
 *
 * @return Reload value
 * @return 加载值
 */
uint32_t arch_armv8m_systick_get_reload(void);

/**
 * @brief Enable SysTick interrupt
 * @brief 使能 SysTick 中断
 *
 * Reference: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (系统定时器, SysTick)
 */
void arch_armv8m_systick_enable_irq(void);

/**
 * @brief Disable SysTick interrupt
 * @brief 禁用 SysTick 中断
 *
 * Reference: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (系统定时器, SysTick)
 */
void arch_armv8m_systick_disable_irq(void);

/**
 * @brief Enable SysTick timer
 * @brief 使能 SysTick 定时器
 *
 * Reference: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (系统定时器, SysTick)
 */
void arch_armv8m_systick_enable(void);

/**
 * @brief Disable SysTick timer
 * @brief 禁用 SysTick 定时器
 *
 * Reference: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (系统定时器, SysTick)
 */
void arch_armv8m_systick_disable(void);

/**
 * @brief Get SysTick calibration value
 * @brief 获取 SysTick 校准值
 *
 * Reference: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (系统定时器, SysTick)
 *
 * @return Calibration value
 * @return 校准值
 */
uint32_t arch_armv8m_systick_get_calib(void);

/*
 * ============================================================================
 * ARMv8-M ITM (Instrumentation Trace Macrocell) Functions
 * ARMv8-M ITM (仪表跟踪宏单元) 函数
 * Reference: ARMv8-M ARM Chapter B14 (Debug and Trace Components)
 * 参考: ARMv8-M ARM Chapter B14 (调试和跟踪组件)
 * ============================================================================
 */

/**
 * @brief ITM send character
 * @brief ITM 发送字符
 *
 * Reference: Arm® v8-M ARM Chapter B14 (Debug and Trace Components)
 * 参考: Arm® v8-M ARM Chapter B14 (调试和跟踪组件)
 *
 * @param ch: Character to send
 * @param ch: 要发送的字符
 * @return Character sent (0-255) or 0 if FIFO full
 * @return 发送的字符 (0-255) 或如果 FIFO 满则返回 0
 */
uint32_t arch_armv8m_itm_send_char(uint32_t ch);

/**
 * @brief ITM receive character
 * @brief ITM 接收字符
 *
 * Reference: Arm® v8-M ARM Chapter B14 (Debug and Trace Components)
 * 参考: Arm® v8-M ARM Chapter B14 (调试和跟踪组件)
 *
 * @return Received character or -1 if no data
 * @return 接收的字符或如果没有数据则返回 -1
 */
int32_t arch_armv8m_itm_receive_char(void);

/**
 * @brief ITM check if character is waiting
 * @brief ITM 检查是否有字符等待读取
 *
 * Reference: Arm® v8-M ARM Chapter B14 (Debug and Trace Components)
 * 参考: Arm® v8-M ARM Chapter B14 (调试和跟踪组件)
 *
 * @return 1=data available, 0=no data
 * @return 1=有数据可用, 0=无数据
 */
int32_t arch_armv8m_itm_check_char(void);

/**
 * @brief ITM enable/disable
 * @brief ITM 使能/禁用
 *
 * Reference: Arm® v8-M ARM Chapter B14 (Debug and Trace Components)
 * 参考: Arm® v8-M ARM Chapter B14 (调试和跟踪组件)
 *
 * @param enable: Enable (1) or disable (0)
 * @param enable: 使能 (1) 或禁用 (0)
 */
void arch_armv8m_itm_enable(uint32_t enable);

/*
 * ============================================================================
 * ARMv8-M Cache Maintenance Functions
 * ARMv8-M Cache 维护函数
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM 第 B3 章 (程序员模型)
 * ============================================================================
 */

/**
 * @brief Invalidate I-Cache to PoU
 * @brief 使能 I-Cache 到 PoU 的失效
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM 第 B3 章 (程序员模型)
 */
void arch_armv8m_icache_invalidate_all(void);

/**
 * @brief Invalidate I-Cache by MVA to PoU
 * @brief 通过 MVA 使能 I-Cache 到 PoU 的失效
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM 第 B3 章 (程序员模型)
 *
 * @param mva: Modified Virtual Address
 * @param mva: 修改的虚拟地址
 */
void arch_armv8m_icache_invalidate_mva(uint32_t mva);

/**
 * @brief Invalidate D-Cache by MVA to PoC
 * @brief 通过 MVA 使能 D-Cache 到 PoC 的失效
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM 第 B3 章 (程序员模型)
 *
 * @param mva: Modified Virtual Address
 * @param mva: 修改的虚拟地址
 */
void arch_armv8m_dcache_invalidate_mva(uint32_t mva);

/**
 * @brief Invalidate D-Cache by Set/Way
 * @brief 通过 Set/Way 使能 D-Cache 的失效
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM 第 B3 章 (程序员模型)
 *
 * @param sw: Set/Way value
 * @param sw: Set/Way 值
 */
void arch_armv8m_dcache_invalidate_sw(uint32_t sw);

/**
 * @brief Clean D-Cache by MVA to PoU
 * @brief 通过 MVA 清理 D-Cache 到 PoU
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM 第 B3 章 (程序员模型)
 *
 * @param mva: Modified Virtual Address
 * @param mva: 修改的虚拟地址
 */
void arch_armv8m_dcache_clean_mva(uint32_t mva);

/**
 * @brief Clean D-Cache by MVA to PoC
 * @brief 通过 MVA 清理 D-Cache 到 PoC
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM 第 B3 章 (程序员模型)
 *
 * @param mva: Modified Virtual Address
 * @param mva: 修改的虚拟地址
 */
void arch_armv8m_dcache_clean_mva_poc(uint32_t mva);

/**
 * @brief Clean D-Cache by Set/Way
 * @brief 通过 Set/Way 清理 D-Cache
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM 第 B3 章 (程序员模型)
 *
 * @param sw: Set/Way value
 * @param sw: Set/Way 值
 */
void arch_armv8m_dcache_clean_sw(uint32_t sw);

/**
 * @brief Clean and Invalidate D-Cache by MVA to PoC
 * @brief 通过 MVA 清理并使能 D-Cache 到 PoC 的失效
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM 第 B3 章 (程序员模型)
 *
 * @param mva: Modified Virtual Address
 * @param mva: 修改的虚拟地址
 */
void arch_armv8m_dcache_clean_invalidate_mva(uint32_t mva);

/**
 * @brief Clean and Invalidate D-Cache by Set/Way
 * @brief 通过 Set/Way 清理并使能 D-Cache 的失效
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM 第 B3 章 (程序员模型)
 *
 * @param sw: Set/Way value
 * @param sw: Set/Way 值
 */
void arch_armv8m_dcache_clean_invalidate_sw(uint32_t sw);

/*
 * ============================================================================
 * ARMv8-M TrustZone NVIC Non-Secure Functions
 * ARMv8-M TrustZone NVIC 非安全函数
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM 第 B12 章 (嵌套向量中断控制器)
 * ============================================================================
 */

/**
 * @brief Set Priority Grouping (Non-Secure)
 * @brief 设置优先级分组 (非安全)
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM 第 B12 章 (嵌套向量中断控制器)
 *
 * @param priority_group: Priority grouping value
 * @param priority_group: 优先级分组值
 */
void arch_armv8m_tz_nvic_set_priority_grouping_ns(uint32_t priority_group);

/**
 * @brief Get Priority Grouping (Non-Secure)
 * @brief 获取优先级分组 (非安全)
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM 第 B12 章 (嵌套向量中断控制器)
 *
 * @return Priority grouping value
 * @return 优先级分组值
 */
uint32_t arch_armv8m_tz_nvic_get_priority_grouping_ns(void);

/**
 * @brief Enable Interrupt (Non-Secure)
 * @brief 使能中断 (非安全)
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM 第 B12 章 (嵌套向量中断控制器)
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 */
void arch_armv8m_tz_nvic_enable_irq_ns(uint8_t irq);

/**
 * @brief Disable Interrupt (Non-Secure)
 * @brief 禁用中断 (非安全)
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM 第 B12 章 (嵌套向量中断控制器)
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 */
void arch_armv8m_tz_nvic_disable_irq_ns(uint8_t irq);

/**
 * @brief Set Pending Interrupt (Non-Secure)
 * @brief 设置中断挂起 (非安全)
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM 第 B12 章 (嵌套向量中断控制器)
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 */
void arch_armv8m_tz_nvic_set_pending_ns(uint8_t irq);

/**
 * @brief Clear Pending Interrupt (Non-Secure)
 * @brief 清除中断挂起 (非安全)
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM 第 B12 章 (嵌套向量中断控制器)
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 */
void arch_armv8m_tz_nvic_clear_pending_ns(uint8_t irq);

/**
 * @brief Get Pending Interrupt (Non-Secure)
 * @brief 获取中断挂起 (非安全)
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM 第 B12 章 (嵌套向量中断控制器)
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @return Pending status (0 = not pending, 1 = pending)
 * @return 挂起状态 (0 = 未挂起, 1 = 挂起)
 */
uint32_t arch_armv8m_tz_nvic_get_pending_ns(uint8_t irq);

/**
 * @brief Get Active Interrupt (Non-Secure)
 * @brief 获取活动中断 (非安全)
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM 第 B12 章 (嵌套向量中断控制器)
 *
 * @return Active status
 * @return 活动状态
 */
uint32_t arch_armv8m_tz_nvic_get_active_ns(void);

/**
 * @brief Set Interrupt Priority (Non-Secure)
 * @brief 设置中断优先级 (非安全)
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM 第 B12 章 (嵌套向量中断控制器)
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @param priority: Priority to set
 * @param priority: 要设置的优先级
 */
void arch_armv8m_tz_nvic_set_priority_ns(uint8_t irq, uint8_t priority);

/**
 * @brief Get Interrupt Priority (Non-Secure)
 * @brief 获取中断优先级 (非安全)
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM 第 B12 章 (嵌套向量中断控制器)
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @return Current priority value
 * @return 当前优先级值
 */
uint32_t arch_armv8m_tz_nvic_get_priority_ns(uint8_t irq);

/*
 * ============================================================================
 * ARMv8-M Peripheral Register Structure Definitions
 * ARMv8-M 外设寄存器结构体定义
 * ============================================================================
 */

/**
 * NVIC (Nested Vectored Interrupt Controller) Register Map
 * NVIC (嵌套向量中断控制器) 寄存器映射
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM Chapter B12 (嵌套向量中断控制器)
 *
 * Base Address: 0xE000E100
 *
 * Members:
 *   ISER[16U]: Interrupt Set-Enable Registers
 *   ICER[16U]: Interrupt Clear-Enable Registers
 *   ISPR[16U]: Interrupt Set-Pending Registers
 *   ICPR[16U]: Interrupt Clear-Pending Registers
 *   IABR[16U]: Interrupt Active Bit Registers
 *   ITNS[16U]: Interrupt Non-Secure State Registers (Cortex-M55 specific)
 *   IPR[496U]: Interrupt Priority Registers
 *   STIR: Software Trigger Interrupt Register
 */
typedef struct {
    volatile uint32_t ISER[16U];
    volatile uint32_t RESERVED0[16U];
    volatile uint32_t ICER[16U];
    volatile uint32_t RESERVED1[16U];
    volatile uint32_t ISPR[16U];
    volatile uint32_t RESERVED2[16U];
    volatile uint32_t ICPR[16U];
    volatile uint32_t RESERVED3[16U];
    volatile uint32_t IABR[16U];
    volatile uint32_t RESERVED4[16U];
    volatile uint32_t ITNS[16U];
    volatile uint32_t RESERVED5[16U];
    volatile uint8_t  IPR[496U];
    volatile uint32_t RESERVED6[580U];
    volatile uint32_t STIR;
} NVIC_Type;

/**
 * SCB (System Control Block) Register Map
 * SCB (系统控制块) 寄存器映射
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * Base Address: 0xE000ED00
 *
 * Members:
 *   CPUID: CPU ID Register
 *   ICSR: Interrupt Control and State Register
 *   VTOR: Vector Table Offset Register
 *   AIRCR: Application Interrupt and Reset Control Register
 *   SCR: System Control Register
 *   CCR: Configuration and Control Register
 *   SHP[12U]: System Handler Priority Registers
 *   SHCSR: System Handler Control and State Register
 *   CFSR: Configurable Fault Status Register
 *   HFSR: HardFault Status Register
 *   DFSR: Debug Fault Status Register
 *   MMFAR: MemManage Fault Address Register
 *   BFAR: Bus Fault Address Register
 *   AFSR: Auxiliary Fault Status Register
 *   CPACR: Coprocessor Access Control Register
 *   Etc.
 */
typedef struct {
    volatile uint32_t CPUID;
    volatile uint32_t ICSR;
    volatile uint32_t VTOR;
    volatile uint32_t AIRCR;
    volatile uint32_t SCR;
    volatile uint32_t CCR;
    volatile uint8_t  SHP[12U];
    volatile uint32_t SHCSR;
    volatile uint32_t CFSR;
    volatile uint32_t HFSR;
    volatile uint32_t DFSR;
    volatile uint32_t MMFAR;
    volatile uint32_t BFAR;
    volatile uint32_t AFSR;
    volatile uint32_t ID_PFR[2U];
    volatile uint32_t ID_DFR;
    volatile uint32_t ID_ADR;
    volatile uint32_t ID_MMFR[4U];
    volatile uint32_t ID_ISAR[5U];
    volatile uint32_t CLIDR;
    volatile uint32_t CTR;
    volatile uint32_t CCSIDR;
    volatile uint32_t CSSELR;
    volatile uint32_t CPACR;
    volatile uint32_t RESERVED3[93U];
    volatile uint32_t STIR[2U];
    volatile uint32_t MVFR0;
    volatile uint32_t MVFR1;
    volatile uint32_t MVFR2;
    volatile uint32_t RESERVED4[3U];
    volatile uint32_t ICIALLU;
    volatile uint32_t RESERVED5;
    volatile uint32_t ICIMVAU;
    volatile uint32_t DCIMVAC;
    volatile uint32_t DCISW;
    volatile uint32_t DCCMVAU;
    volatile uint32_t DCCMVAC;
    volatile uint32_t DCCSW;
    volatile uint32_t DCCIALLU;
    volatile uint32_t RESERVED6[6U];
    volatile uint32_t ITCMCR;
    volatile uint32_t DTCMCR;
    volatile uint32_t AHBPCR;
    volatile uint32_t CACR;
    volatile uint32_t AHBSCR;
    volatile uint32_t RESERVED8[3U];
    volatile uint32_t CFGHCSR;
    volatile uint32_t RESERVED9[1U];
    volatile uint32_t HFSR1;
    volatile uint32_t RESERVED10[1U];
    volatile uint32_t ID_AFR;
    volatile uint32_t ID_MFR[4U];
    volatile uint32_t ISR[4U];
} SCB_Type;

/**
 * SysTick (System Timer) Register Map
 * SysTick (系统定时器) 寄存器映射
 *
 * Reference: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (系统定时器, SysTick)
 *
 * Base Address: 0xE000E010
 *
 * Members:
 *   CTRL: Control and Status Register
 *   LOAD: Reload Value Register
 *   VAL: Current Value Register
 *   CALIB: Calibration Register
 */
typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VAL;
    volatile uint32_t CALIB;
} SysTick_Type;

/**
 * MPU (Memory Protection Unit) Register Map
 * MPU (内存保护单元) 寄存器映射
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * Base Address: 0xE000ED90
 *
 * Members:
 *   TYPE: Type Register
 *   CTRL: Control Register
 *   RNR: Region Number Register
 *   RBAR: Region Base Address Register
 *   RLAR: Region Limit Register
 *   MAIR0: Memory Attribute Indirection Register 0
 *   MAIR1: Memory Attribute Indirection Register 1
 */
typedef struct {
    volatile uint32_t TYPE;
    volatile uint32_t CTRL;
    volatile uint32_t RNR;
    volatile uint32_t RBAR;
    volatile uint32_t RLAR;
    volatile uint32_t RESERVED0[3U];
    volatile uint32_t MAIR0;
    volatile uint32_t MAIR1;
} MPU_Type;

/**
 * ITM (Instrumentation Trace Macrocell) Register Map
 * ITM (仪表跟踪宏单元) 寄存器映射
 *
 * Reference: Arm® v8-M ARM Chapter B14 (Debug and Trace Components)
 * 参考: Arm® v8-M ARM Chapter B14 (调试和跟踪组件)
 *
 * Base Address: 0xE0000000
 *
 * Members:
 *   CTRL: Control Register
 *   TOKEN: Token Register
 *   TPR: Trace Privilege Register
 *   TER[32U]: Trace Enable Registers
 *   PORT[32U]: Trace Port Registers
 */
typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t TOKEN;
    volatile uint32_t TPR;
    volatile uint32_t RESERVED0;
    volatile uint32_t TER[32U];
    volatile uint32_t RESERVED1[864U];
    volatile uint32_t PORT[32U];
} ITM_Type;

/**
 * PMU (Performance Monitor Unit) Register Map
 * PMU (性能监视单元) 寄存器映射
 *
 * Reference: Arm® v8-M ARM Chapter B15 (The Performance Monitors Extension)
 * 参考: Arm® v8-M ARM Chapter B15 (性能监视器扩展)
 *
 * Base Address: 0xE0003000
 *
 * Members:
 *   CTRL: Control Register
 *   CNT: Cycle Counter Register
 *   EVTYPER[31U]: Event Type Select Registers
 *   EVCNTR[31U]: Event Count Registers
 */
typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t CNT;
    volatile uint32_t EVTYPER[31U];
    volatile uint32_t RESERVED0;
    volatile uint32_t EVCNTR[31U];
} PMU_Type;

/**
 * SAU (Security Attribution Unit) Register Map
 * SAU (安全属性单元) 寄存器映射
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * Base Address: 0xE000EDD0
 *
 * Members:
 *   CTRL: Control Register
 *   RNR: Region Number Register
 *   RBAR: Region Base Address Register
 *   RLAR: Region Limit Register
 *   TYPE: Type Register
 */
typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t RNR;
    volatile uint32_t RBAR;
    volatile uint32_t RLAR;
    volatile uint32_t TYPE;
} SAU_Type;

/**
 * FPU (Floating Point Unit) Register Map
 * FPU (浮点单元) 寄存器映射
 *
 * Reference: Arm® v8-M ARM Chapter B4 (Floating-point Support)
 * 参考: Arm® v8-M ARM Chapter B4 (浮点支持)
 *
 * Base Address: 0xE000ED88 (CPACR offset)
 *
 * Members:
 *   CPACR: Coprocessor Access Control Register
 */
typedef struct {
    volatile uint32_t CPACR;
} FPU_Type;

/**
 * SCnSCB (System Control) Register Map
 * SCnSCB (系统控制) 寄存器映射
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * Base Address: 0xE000ED10
 *
 * Members:
 *   ACR: Auxiliary Control Register
 *   NSACR: Non-secure Access Control Register
 */
typedef struct {
    volatile uint32_t ACR;
    volatile uint32_t NSACR;
} SCnSCB_Type;

/**
 * ITM Port type for single byte write
 * ITM 端口类型用于单字节写入
 *
 * Reference: Arm® v8-M ARM Chapter B14 (Debug and Trace Components)
 * 参考: Arm® v8-M ARM Chapter B14 (调试和跟踪组件)
 */
typedef union {
    volatile uint8_t  u8;
    volatile uint16_t u16;
    volatile uint32_t u32;
} ITM_Port_Type;

/*
 * ============================================================================
 * ARMv8-M Peripheral Base Address Definitions
 * ARMv8-M 外设基地址定义
 * ============================================================================
 */

/**
 * NVIC base address
 * NVIC 基地址
 * Address: 0xE000E100
 */
#define NVIC_BASE_ADDR         0xE000E100UL

/**
 * NVIC instance
 * NVIC 实例
 */
#define NVIC                  ((NVIC_Type *) NVIC_BASE_ADDR)

/**
 * SCB base address
 * SCB 基地址
 * Address: 0xE000ED00
 */
#define SCB_BASE_ADDR          0xE000ED00UL

/**
 * SCB instance
 * SCB 实例
 */
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
 * SCB_ICSR: Interrupt Control and State Register
 * SCB_ICSR: 中断控制和状态寄存器
 */
#define SCB_ICSR             (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x04))

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

/**
 * SysTick instance
 * SysTick 实例
 */
#define SysTick               ((SysTick_Type *) SYSTICK_BASE_ADDR)

/**
 * MPU base address
 * MPU 基地址
 * Address: 0xE000ED90
 */
#define MPU_BASE_ADDR          0xE000ED90UL

/**
 * MPU instance
 * MPU 实例
 */
#define MPU                   ((MPU_Type *) MPU_BASE_ADDR)

/**
 * MPU_CTRL: MPU Control Register
 * MPU_CTRL: MPU 控制寄存器
 */
#define MPU_CTRL              (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x04))

/**
 * MPU_CTRL_ENABLE_Msk: MPU enable mask
 * MPU_CTRL_ENABLE_Msk: MPU 使能掩码
 */
#define MPU_CTRL_ENABLE_Msk   (1UL << 0)

/**
 * MPU_CTRL_PRIVDEFENA_Msk: Privileged default memory map enable mask
 * MPU_CTRL_PRIVDEFENA_Msk: 特权默认内存映射使能掩码
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
 * MPU_RLAR: MPU Region Limit Register
 * MPU_RLAR: MPU 区域限制寄存器
 */
#define MPU_RLAR              (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x0C))



/**
 * ITM base address
 * ITM 基地址
 * Address: 0xE0000000
 */
#define ITM_BASE_ADDR          0xE0000000UL

/**
 * ITM instance
 * ITM 实例
 */
#define ITM                   ((ITM_Type *) ITM_BASE_ADDR)

/**
 * ITM_TCR: ITM Trace Control Register
 * ITM_TCR: ITM 跟踪控制寄存器
 */
#define ITM_TCR              (*(volatile uint32_t *)(ITM_BASE_ADDR + 0x00))

/**
 * ITM_TCR_ITMENA_Msk: ITM enable mask
 * ITM_TCR_ITMENA_Msk: ITM 使能掩码
 */
#define ITM_TCR_ITMENA_Msk   (1UL << 0)

/**
 * ITM_TER: ITM Trace Enable Register
 * ITM_TER: ITM 跟踪使能寄存器
 */
#define ITM_TER              (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xE00))

/**
 * ITM_RXR: ITM Receive Register
 * ITM_RXR: ITM 接收寄存器
 */
#define ITM_RXR              (*(volatile uint32_t *)(ITM_BASE_ADDR + 0x00))

/**
 * ITM Port instance
 * ITM 端口实例
 */
#define ITM_PORT              ((ITM_Port_Type *) ITM_BASE_ADDR)

/**
 * PMU base address
 * PMU 基地址
 * Address: 0xE0003000
 */
#define PMU_BASE_ADDR          0xE0003000UL

/**
 * PMU instance
 * PMU 实例
 */
#define PMU                   ((PMU_Type *) PMU_BASE_ADDR)

/**
 * PMU_CTRL: PMU Control Register
 * PMU_CTRL: PMU 控制寄存器
 */
#define PMU_CTRL             (*(volatile uint32_t *)(PMU_BASE_ADDR + 0x00))

/**
 * PMU_CYCNT: PMU Cycle Counter (64-bit)
 * PMU_CYCNT: PMU Cycle 计数器 (64位)
 */
#define PMU_CYCNT            (*(volatile uint64_t *)(PMU_BASE_ADDR + 0x04))

/**
 * SAU base address
 * SAU 基地址
 * Address: 0xE000EDD0
 */
#define SAU_BASE_ADDR          0xE000EDD0UL

/**
 * SAU instance
 * SAU 实例
 */
#define SAU                   ((SAU_Type *) SAU_BASE_ADDR)

/**
 * SAU_CTRL: SAU Control Register
 * SAU_CTRL: SAU 控制寄存器
 */
#define SAU_CTRL              (*(volatile uint32_t *)(SAU_BASE_ADDR + 0x00))

/**
 * SAU_RNR: SAU Region Number Register
 * SAU_RNR: SAU 区域编号寄存器
 */
#define SAU_RNR               (*(volatile uint32_t *)(SAU_BASE_ADDR + 0x04))

/**
 * SAU_RBAR: SAU Region Base Address Register
 * SAU_RBAR: SAU 区域基地址寄存器
 */
#define SAU_RBAR              (*(volatile uint32_t *)(SAU_BASE_ADDR + 0x08))

/**
 * SAU_RLAR: SAU Region Limit Register
 * SAU_RLAR: SAU 区域限制寄存器
 */
#define SAU_RLAR              (*(volatile uint32_t *)(SAU_BASE_ADDR + 0x0C))

/**
 * SAU_TYPE: SAU Type Register
 * SAU_TYPE: SAU 类型寄存器
 */
#define SAU_TYPE              (*(volatile uint32_t *)(SAU_BASE_ADDR + 0x10))

/**
 * SCnSCB base address
 * SCnSCB 基地址
 * Address: 0xE000ED10
 */
#define SCnSCB_BASE_ADDR       0xE000ED00UL

/**
 * SCnSCB instance
 * SCnSCB 实例
 */
#define SCnSCB                ((SCnSCB_Type *) (SCnSCB_BASE_ADDR + 0x10U))

/**
 * FPU base address
 * FPU 基地址
 * Address: 0xE000ED88
 */
#define FPU_BASE_ADDR          0xE000ED00UL

/**
 * FPU instance
 * FPU 实例
 */
#define FPU                   ((FPU_Type *) (FPU_BASE_ADDR + 0xD88U))

/*
 * ============================================================================
 * ARMv8-M Inline Helper Macros
 * ARMv8-M 内联辅助宏
 * ============================================================================
 */

/**
 * Static inline keyword for compiler-agnostic code
 * 用于编译器无关代码的静态内联关键字
 */
#ifndef __STATIC_INLINE
    #define __STATIC_INLINE static inline
#endif

/**
 * @brief No Operation
 * @brief 空操作
 *
 * Reference: ARMv8-M ARM (General instructions)
 * 参考: ARMv8-M ARM (通用指令)
 */
#ifndef __NOP
    #define __NOP() __asm__ volatile ("nop" : : : "memory")
#endif

/**
 * @brief Data Synchronization Barrier
 * @brief 数据同步屏障
 *
 * Reference: ARMv8-M ARM Chapter B7 (Memory Model)
 * 参考: ARMv8-M ARM Chapter B7 (内存模型)
 */
#ifndef __DSB
    #define __DSB() __asm__ volatile ("dsb sy" : : : "memory")
#endif

/**
 * @brief Instruction Synchronization Barrier
 * @brief 指令同步屏障
 *
 * Reference: ARMv8-M ARM Chapter B7 (Memory Model)
 * 参考: ARMv8-M ARM Chapter B7 (内存模型)
 */
#ifndef __ISB
    #define __ISB() __asm__ volatile ("isb sy" : : : "memory")
#endif

/**
 * @brief Rotate Right
 * @brief 右旋转
 *
 * Reference: Arm® v8-M ARM Chapter B6 (The Thumb instruction set)
 * 参考: Arm® v8-M ARM Chapter B6 (Thumb 指令集)
 */
#ifndef __ROR
__STATIC_INLINE uint32_t __ROR(uint32_t op1, uint32_t op2) {
    return (op1 >> (op2 & 31U)) | (op1 << ((32U - (op2 & 31U)) & 31U));
}
#endif

/**
 * @brief Reverse Bits
 * @brief 位反转
 *
 * Reference: Arm® v8-M ARM Chapter B6 (The Thumb instruction set)
 * 参考: Arm® v8-M ARM Chapter B6 (Thumb 指令集)
 */
#ifndef __RBIT
__STATIC_INLINE uint32_t __RBIT(uint32_t value) {
    uint32_t result;
    __asm__ volatile ("rbit %0, %1" : "=r" (result) : "r" (value) );
    return result;
}
#endif

/**
 * @brief Reverse Bytes (Word)
 * @brief 字节反转（字）
 *
 * Reference: Arm® v8-M ARM Chapter B6 (The Thumb instruction set)
 * 参考: Arm® v8-M ARM Chapter B6 (Thumb 指令集)
 */
#ifndef __REV
__STATIC_INLINE uint32_t __REV(uint32_t value) {
    uint32_t result;
    __asm__ volatile ("rev %0, %1" : "=r" (result) : "r" (value) );
    return result;
}
#endif

/**
 * @brief Reverse Bytes (Halfword)
 * @brief 字节反转（半字）
 *
 * Reference: Arm® v8-M ARM Chapter B6 (The Thumb instruction set)
 * 参考: Arm® v8-M ARM Chapter B6 (Thumb 指令集)
 */
#ifndef __REV16
__STATIC_INLINE uint32_t __REV16(uint32_t value) {
    uint32_t result;
    __asm__ volatile ("rev16 %0, %1" : "=r" (result) : "r" (value) );
    return result;
}
#endif

/**
 * @brief Reverse Bytes in Packed Halfwords
 * @brief 打包半字中的字节反转
 *
 * Reference: Arm® v8-M ARM Chapter B6 (The Thumb instruction set)
 * 参考: Arm® v8-M ARM Chapter B6 (Thumb 指令集)
 */
#ifndef __REVSH
__STATIC_INLINE int32_t __REVSH(int32_t value) {
    int32_t result;
    __asm__ volatile ("revsh %0, %1" : "=r" (result) : "r" (value) );
    return result;
}
#endif

/**
 * @brief Count Leading Zeros
 * @brief 前导零计数
 *
 * Reference: Arm® v8-M ARM Chapter B6 (The Thumb instruction set)
 * 参考: Arm® v8-M ARM Chapter B6 (Thumb 指令集)
 */
#ifndef __CLZ
__STATIC_INLINE uint32_t __CLZ(uint32_t value) {
    uint32_t result;
    __asm__ volatile ("clz %0, %1" : "=r" (result) : "r" (value) );
    return result;
}
#endif

/**
 * @brief Get CPACR (Coprocessor Access Control Register)
 * @brief 获取 CPACR (协处理器访问控制寄存器)
 *
 * Reference: Arm® v8-M ARM Chapter B4 (Floating-point Support)
 * 参考: Arm® v8-M ARM Chapter B4 (浮点支持)
 */
#ifndef __FPU_GetCPACR
    #define __FPU_GetCPACR()         (SCB->CPACR)
#endif

/**
 * @brief Set CPACR (Coprocessor Access Control Register)
 * @brief 设置 CPACR (协处理器访问控制寄存器)
 *
 * Reference: Arm® v8-M ARM Chapter B4 (Floating-point Support)
 * 参考: Arm® v8-M ARM Chapter B4 (浮点支持)
 */
#ifndef __FPU_SetCPACR
    #define __FPU_SetCPACR(cpacr)    (SCB->CPACR = (cpacr))
#endif

/**
 * @brief Get CONTROL register
 * @brief 获取 CONTROL 寄存器
 */
#ifndef __get_CONTROL
    #define __get_CONTROL()       arch_armv8m_get_control()
#endif

/**
 * @brief Set CONTROL register
 * @brief 设置 CONTROL 寄存器
 */
#ifndef __set_CONTROL
    #define __set_CONTROL(control) arch_armv8m_set_control(control)
#endif

/**
 * @brief Get MSP (Main Stack Pointer)
 * @brief 获取 MSP (主栈指针)
 */
#ifndef __get_MSP
    #define __get_MSP()          arch_armv8m_get_msp()
#endif

/**
 * @brief Set MSP (Main Stack Pointer)
 * @brief 设置 MSP (主栈指针)
 */
#ifndef __set_MSP
    #define __set_MSP(msp)       arch_armv8m_set_msp(msp)
#endif

/**
 * @brief Get PSP (Process Stack Pointer)
 * @brief 获取 PSP (进程栈指针)
 */
#ifndef __get_PSP
    #define __get_PSP()          arch_armv8m_get_psp()
#endif

/**
 * @brief Set PSP (Process Stack Pointer)
 * @brief 设置 PSP (进程栈指针)
 */
#ifndef __set_PSP
    #define __set_PSP(psp)       arch_armv8m_set_psp(psp)
#endif

/**
 * @brief Get PRIMASK register
 * @brief 获取 PRIMASK 寄存器
 */
#ifndef __get_PRIMASK
    #define __get_PRIMASK()      arch_armv8m_get_primask()
#endif

/**
 * @brief Set PRIMASK register
 * @brief 设置 PRIMASK 寄存器
 */
#ifndef __set_PRIMASK
    #define __set_PRIMASK(primask) arch_armv8m_set_primask(primask)
#endif

/**
 * @brief Get BASEPRI register
 * @brief 获取 BASEPRI 寄存器
 */
#ifndef __get_BASEPRI
    #define __get_BASEPRI()      arch_armv8m_get_basepri()
#endif

/**
 * @brief Set BASEPRI register
 * @brief 设置 BASEPRI 寄存器
 */
#ifndef __set_BASEPRI
    #define __set_BASEPRI(basepri) arch_armv8m_set_basepri(basepri)
#endif

/**
 * @brief Get FAULTMASK register
 * @brief 获取 FAULTMASK 寄存器
 */
#ifndef __get_FAULTMASK
    #define __get_FAULTMASK()   arch_armv8m_get_faultmask()
#endif

/**
 * @brief Set FAULTMASK register
 * @brief 设置 FAULTMASK 寄存器
 */
#ifndef __set_FAULTMASK
    #define __set_FAULTMASK(faultmask) arch_armv8m_set_faultmask(faultmask)
#endif

/**
 * @brief Wait For Interrupt
 * @brief 等待中断
 */
#ifndef __WFI
    #define __WFI()              arch_armv8m_wfi()
#endif

/**
 * @brief Wait For Event
 * @brief 等待事件
 */
#ifndef __WFE
    #define __WFE()              arch_armv8m_wfe()
#endif

/**
 * @brief Send Event
 * @brief 发送事件
 */
#ifndef __SEV
    #define __SEV()              arch_armv8m_sev()
#endif

/**
 * @brief Get MSPLIM (Main Stack Pointer Limit)
 * @brief 获取 MSPLIM (主栈指针限制)
 */
#ifndef __get_MSPLIM
    #define __get_MSPLIM()       arch_armv8m_get_msplim()
#endif

/**
 * @brief Set MSPLIM (Main Stack Pointer Limit)
 * @brief 设置 MSPLIM (主栈指针限制)
 */
#ifndef __set_MSPLIM
    #define __set_MSPLIM(msplim) arch_armv8m_set_msplim(msplim)
#endif

/**
 * @brief Get PSPLIM (Process Stack Pointer Limit)
 * @brief 获取 PSPLIM (进程栈指针限制)
 */
#ifndef __get_PSPLIM
    #define __get_PSPLIM()       arch_armv8m_get_psplim()
#endif

/**
 * @brief Set PSPLIM (Process Stack Pointer Limit)
 * @brief 设置 PSPLIM (进程栈指针限制)
 */
#ifndef __set_PSPLIM
    #define __set_PSPLIM(psplim) arch_armv8m_set_psplim(psplim)
#endif

/**
 * @brief Get IPSR register
 * @brief 获取 IPSR 寄存器
 */
#ifndef __get_IPSR
    #define __get_IPSR()         arch_armv8m_get_ipsr()
#endif

/**
 * @brief Get APSR register
 * @brief 获取 APSR 寄存器
 */
#ifndef __get_APSR
    #define __get_APSR()         arch_armv8m_get_apsr()
#endif

/**
 * @brief Get xPSR register
 * @brief 获取 xPSR 寄存器
 */
#ifndef __get_xPSR
    #define __get_xPSR()         arch_armv8m_get_xpsr()
#endif

/**
 * @brief Set BASEPRI register with maximum
 * @brief 以最大值设置 BASEPRI 寄存器
 */
#ifndef __set_BASEPRI_MAX
__STATIC_INLINE void __set_BASEPRI_MAX(uint32_t basePri) {
    __asm__ volatile ("MSR basepri_max, %0" : : "r" (basePri) : "memory");
}
#endif

/*
 * ============================================================================
 * ARMv8-M Unprivileged Access Instructions
 * ARMv8-M 未特权访问指令
 * ============================================================================
 */

/**
 * @brief STRBT Unprivileged (8 bit)
 * @brief 未特权存储字节
 */
#ifndef __STRBT
__STATIC_INLINE void __STRBT(uint8_t value, volatile uint8_t *ptr) {
    __asm__ volatile ("strbt %1, %0" : "=Q" (*ptr) : "r" ((uint32_t)value) );
}
#endif

/**
 * @brief STRHT Unprivileged (16 bit)
 * @brief 未特权存储半字
 */
#ifndef __STRHT
__STATIC_INLINE void __STRHT(uint16_t value, volatile uint16_t *ptr) {
    __asm__ volatile ("strht %1, %0" : "=Q" (*ptr) : "r" ((uint32_t)value) );
}
#endif

/**
 * @brief STRT Unprivileged (32 bit)
 * @brief 未特权存储字
 */
#ifndef __STRT
__STATIC_INLINE void __STRT(uint32_t value, volatile uint32_t *ptr) {
    __asm__ volatile ("strt %1, %0" : "=Q" (*ptr) : "r" (value) );
}
#endif

/**
 * @brief LDRBT Unprivileged (8 bit)
 * @brief 未特权读取字节
 *
 * Reference: Arm® v8-M ARM Chapter B6 (The Thumb instruction set)
 * 参考: Arm® v8-M ARM Chapter B6 (Thumb 指令集)
 */
#ifndef __LDRBT
__STATIC_INLINE uint8_t __LDRBT(volatile uint8_t *ptr) {
    uint8_t result;
    __asm__ volatile ("ldrbt %0, %1" : "=r" (result) : "Q" (*ptr) );
    return result;
}
#endif

/**
 * @brief LDRHT Unprivileged (16 bit)
 * @brief 未特权读取半字
 *
 * Reference: Arm® v8-M ARM Chapter B6 (The Thumb instruction set)
 * 参考: Arm® v8-M ARM Chapter B6 (Thumb 指令集)
 */
#ifndef __LDRHT
__STATIC_INLINE uint16_t __LDRHT(volatile uint16_t *ptr) {
    uint16_t result;
    __asm__ volatile ("ldrht %0, %1" : "=r" (result) : "Q" (*ptr) );
    return result;
}
#endif

/**
 * @brief LDRT Unprivileged (32 bit)
 * @brief 未特权读取字
 *
 * Reference: Arm® v8-M ARM Chapter B6 (The Thumb instruction set)
 * 参考: Arm® v8-M ARM Chapter B6 (Thumb 指令集)
 */
#ifndef __LDRT
__STATIC_INLINE uint32_t __LDRT(volatile uint32_t *ptr) {
    uint32_t result;
    __asm__ volatile ("ldrt %0, %1" : "=r" (result) : "Q" (*ptr) );
    return result;
}
#endif

/*
 * ============================================================================
 * ARMv8-M Memory Barrier Variants
 * ARMv8-M 内存屏障变体
 * ============================================================================
 */

/**
 * @brief Data Memory Barrier
 * @brief 数据内存屏障
 */
#ifndef __DMB
    #define __DMB() __asm__ volatile ("dmb sy" : : : "memory")
#endif

/**
 * @brief Data Memory Barrier with options
 * @brief 带选项的数据内存屏障
 */
#ifndef __DMB_OPT
__STATIC_INLINE void __DMB_OPT(uint32_t option) {
    switch (option) {
        case 0: __asm__ volatile ("dmb sy" : : : "memory"); break;
        case 1: __asm__ volatile ("dmb st" : : : "memory"); break;
        case 2: __asm__ volatile ("dmb ld" : : : "memory"); break;
        case 3: __asm__ volatile ("dmb ish" : : : "memory"); break;
        case 4: __asm__ volatile ("dmb ishst" : : : "memory"); break;
        case 5: __asm__ volatile ("dmb ishld" : : : "memory"); break;
        case 6: __asm__ volatile ("dmb nsh" : : : "memory"); break;
        case 7: __asm__ volatile ("dmb nshst" : : : "memory"); break;
        case 8: __asm__ volatile ("dmb nshld" : : : "memory"); break;
        case 9: __asm__ volatile ("dmb osh" : : : "memory"); break;
        case 10: __asm__ volatile ("dmb oshst" : : : "memory"); break;
        case 11: __asm__ volatile ("dmb oshld" : : : "memory"); break;
        default: __asm__ volatile ("dmb sy" : : : "memory"); break;
    }
}
#endif

/**
 * @brief Data Synchronization Barrier with options
 * @brief 带选项的数据同步屏障
 */
#ifndef __DSB_OPT
__STATIC_INLINE void __DSB_OPT(uint32_t option) {
    switch (option) {
        case 0: __asm__ volatile ("dsb sy" : : : "memory"); break;
        case 1: __asm__ volatile ("dsb st" : : : "memory"); break;
        case 2: __asm__ volatile ("dsb ld" : : : "memory"); break;
        case 3: __asm__ volatile ("dsb ish" : : : "memory"); break;
        case 4: __asm__ volatile ("dsb ishst" : : : "memory"); break;
        case 5: __asm__ volatile ("dsb ishld" : : : "memory"); break;
        case 6: __asm__ volatile ("dsb nsh" : : : "memory"); break;
        case 7: __asm__ volatile ("dsb nshst" : : : "memory"); break;
        case 8: __asm__ volatile ("dsb nshld" : : : "memory"); break;
        case 9: __asm__ volatile ("dsb osh" : : : "memory"); break;
        case 10: __asm__ volatile ("dsb oshst" : : : "memory"); break;
        case 11: __asm__ volatile ("dsb oshld" : : : "memory"); break;
        default: __asm__ volatile ("dsb sy" : : : "memory"); break;
    }
}
#endif

/*
 * ============================================================================
 * ARMv8-M DSP/SIMD Intrinsics
 * ARMv8-M DSP/SIMD 内在函数
 *
 * These intrinsics provide access to DSP and SIMD instructions available in
 * ARMv8-M processors with DSP extension.
 * 这些内在函数提供对具有 DSP 扩展的 ARMv8-M 处理器中 DSP 和 SIMD 指令的访问。
 *
 * ARMv8-M also supports optional Helium (MVE) extension for advanced vector
 * processing capabilities.
 * ARMv8-M 还支持可选的 Helium (MVE) 扩展，以提供高级向量处理能力。
 *
 * Note: These are compiler-agnostic wrappers that use GCC/Clang builtins.
 * 注意: 这些是使用 GCC/Clang 内置函数的编译器无关包装器。
 * ============================================================================
 */

#if defined(__ARM_FEATURE_DSP) && (__ARM_FEATURE_DSP == 1)

/**
 * @brief Signed Saturating Add 8 (SADD8)
 * @brief 带符号饱和加法 8 位
 */
__STATIC_INLINE int32_t __SADD8(int32_t op1, int32_t op2) {
    return __builtin_arm_sadd8(op1, op2);
}

/**
 * @brief Signed Saturating Add 16 (SADD16)
 * @brief 带符号饱和加法 16 位
 */
__STATIC_INLINE int32_t __SADD16(int32_t op1, int32_t op2) {
    return __builtin_arm_sadd16(op1, op2);
}

/**
 * @brief Signed Saturating Subtract 8 (SSUB8)
 * @brief 带符号饱和减法 8 位
 */
__STATIC_INLINE int32_t __SSUB8(int32_t op1, int32_t op2) {
    return __builtin_arm_ssub8(op1, op2);
}

/**
 * @brief Signed Saturating Subtract 16 (SSUB16)
 * @brief 带符号饱和减法 16 位
 */
__STATIC_INLINE int32_t __SSUB16(int32_t op1, int32_t op2) {
    return __builtin_arm_ssub16(op1, op2);
}

/**
 * @brief Signed Halving Add 8 (SHADD8)
 * @brief 带符号折半加法 8 位
 */
__STATIC_INLINE int32_t __SHADD8(int32_t op1, int32_t op2) {
    return __builtin_arm_shadd8(op1, op2);
}

/**
 * @brief Signed Halving Add 16 (SHADD16)
 * @brief 带符号折半加法 16 位
 */
__STATIC_INLINE int32_t __SHADD16(int32_t op1, int32_t op2) {
    return __builtin_arm_shadd16(op1, op2);
}

/**
 * @brief Saturating Add (QADD)
 * @brief 饱和加法
 */
__STATIC_INLINE int32_t __QADD(int32_t op1, int32_t op2) {
    return __builtin_arm_qadd(op1, op2);
}

/**
 * @brief Saturating Subtract (QSUB)
 * @brief 饱和减法
 */
__STATIC_INLINE int32_t __QSUB(int32_t op1, int32_t op2) {
    return __builtin_arm_qsub(op1, op2);
}

/**
 * @brief Select Bytes (SEL)
 * @brief 选择字节
 */
__STATIC_INLINE int32_t __SEL(int32_t op1, int32_t op2) {
    return __builtin_arm_sel(op1, op2);
}

/**
 * @brief Signed Multiply Accumulate (SMLAD)
 * @brief 带符号乘加
 */
__STATIC_INLINE int32_t __SMLAD(int32_t op1, int32_t op2, int32_t op3) {
    return __builtin_arm_smlad(op1, op2, op3);
}

/**
 * @brief Signed Multiply Accumulate Long (SMLALD)
 * @brief 带符号长乘加
 */
__STATIC_INLINE int64_t __SMLALD(int32_t op1, int32_t op2, int64_t op3) {
    return __builtin_arm_smlald(op1, op2, op3);
}

/**
 * @brief Signed Multiply Subtract Accumulate (SMLSD)
 * @brief 带符号乘减累加
 */
__STATIC_INLINE int32_t __SMLSD(int32_t op1, int32_t op2, int32_t op3) {
    return __builtin_arm_smlsd(op1, op2, op3);
}

/**
 * @brief Dual Signed Add and Subtract (SASX)
 * @brief 双带符号加法和减法
 */
__STATIC_INLINE int32_t __SASX(int32_t op1, int32_t op2) {
    return __builtin_arm_sasx(op1, op2);
}

/**
 * @brief Signed Shift Right (SSAT)
 * @brief 带符号饱和右移
 */
__STATIC_INLINE int32_t __SSAT(int32_t op1, int32_t sat) {
    return __builtin_arm_ssat(op1, sat);
}

/**
 * @brief Unsigned Shift Right (USAT)
 * @brief 无符号饱和右移
 */
__STATIC_INLINE int32_t __USAT(int32_t op1, int32_t sat) {
    return __builtin_arm_usat(op1, sat);
}

/**
 * @brief Signed Extend Byte (SXTB)
 * @brief 带符号扩展字节
 */
__STATIC_INLINE int32_t __SXTB(int32_t op1) {
    return __builtin_arm_sxtb(op1);
}

/**
 * @brief Signed Extend Halfword (SXTH)
 * @brief 带符号扩展半字
 */
__STATIC_INLINE int32_t __SXTH(int32_t op1) {
    return __builtin_arm_sxth(op1);
}

/**
 * @brief Unsigned Extend Byte (UXTB)
 * @brief 无符号扩展字节
 */
__STATIC_INLINE uint32_t __UXTB(uint32_t op1) {
    return __builtin_arm_uxtb(op1);
}

/**
 * @brief Unsigned Extend Halfword (UXTH)
 * @brief 无符号扩展半字
 */
__STATIC_INLINE uint32_t __UXTH(uint32_t op1) {
    return __builtin_arm_uxth(op1);
}

/**
 * @brief Signed Saturating Add 8 (QADD8)
 * @brief 带符号饱和加法 8 位
 */
__STATIC_INLINE int32_t __QADD8(int32_t op1, int32_t op2) {
    return __builtin_arm_qadd8(op1, op2);
}

/**
 * @brief Signed Saturating Add 16 (QADD16)
 * @brief 带符号饱和加法 16 位
 */
__STATIC_INLINE int32_t __QADD16(int32_t op1, int32_t op2) {
    return __builtin_arm_qadd16(op1, op2);
}

/**
 * @brief Signed Halving Subtract 8 (SHSUB8)
 * @brief 带符号折半减法 8 位
 */
__STATIC_INLINE int32_t __SHSUB8(int32_t op1, int32_t op2) {
    return __builtin_arm_shsub8(op1, op2);
}

/**
 * @brief Signed Halving Subtract 16 (SHSUB16)
 * @brief 带符号折半减法 16 位
 */
__STATIC_INLINE int32_t __SHSUB16(int32_t op1, int32_t op2) {
    return __builtin_arm_shsub16(op1, op2);
}

/**
 * @brief Unsigned Add 8 (UADD8)
 * @brief 无符号加法 8 位
 */
__STATIC_INLINE uint32_t __UADD8(uint32_t op1, uint32_t op2) {
    return __builtin_arm_uadd8(op1, op2);
}

/**
 * @brief Unsigned Add 16 (UADD16)
 * @brief 无符号加法 16 位
 */
__STATIC_INLINE uint32_t __UADD16(uint32_t op1, uint32_t op2) {
    return __builtin_arm_uadd16(op1, op2);
}

/**
 * @brief Unsigned Saturating Add 8 (UQADD8)
 * @brief 无符号饱和加法 8 位
 */
__STATIC_INLINE uint32_t __UQADD8(uint32_t op1, uint32_t op2) {
    return __builtin_arm_uqadd8(op1, op2);
}

/**
 * @brief Unsigned Saturating Add 16 (UQADD16)
 * @brief 无符号饱和加法 16 位
 */
__STATIC_INLINE uint32_t __UQADD16(uint32_t op1, uint32_t op2) {
    return __builtin_arm_uqadd16(op1, op2);
}

/**
 * @brief Unsigned Halving Add 8 (UHADD8)
 * @brief 无符号折半加法 8 位
 */
__STATIC_INLINE uint32_t __UHADD8(uint32_t op1, uint32_t op2) {
    return __builtin_arm_uhadd8(op1, op2);
}

/**
 * @brief Unsigned Halving Add 16 (UHADD16)
 * @brief 无符号折半加法 16 位
 */
__STATIC_INLINE uint32_t __UHADD16(uint32_t op1, uint32_t op2) {
    return __builtin_arm_uhadd16(op1, op2);
}

/**
 * @brief Unsigned Subtract 8 (USUB8)
 * @brief 无符号减法 8 位
 */
__STATIC_INLINE uint32_t __USUB8(uint32_t op1, uint32_t op2) {
    return __builtin_arm_usub8(op1, op2);
}

/**
 * @brief Unsigned Subtract 16 (USUB16)
 * @brief 无符号减法 16 位
 */
__STATIC_INLINE uint32_t __USUB16(uint32_t op1, uint32_t op2) {
    return __builtin_arm_usub16(op1, op2);
}

/**
 * @brief Unsigned Saturating Subtract 8 (UQSUB8)
 * @brief 无符号饱和减法 8 位
 */
__STATIC_INLINE uint32_t __UQSUB8(uint32_t op1, uint32_t op2) {
    return __builtin_arm_uqsub8(op1, op2);
}

/**
 * @brief Unsigned Saturating Subtract 16 (UQSUB16)
 * @brief 无符号饱和减法 16 位
 */
__STATIC_INLINE uint32_t __UQSUB16(uint32_t op1, uint32_t op2) {
    return __builtin_arm_uqsub16(op1, op2);
}

/**
 * @brief Unsigned Halving Subtract 8 (UHSUB8)
 * @brief 无符号折半减法 8 位
 */
__STATIC_INLINE uint32_t __UHSUB8(uint32_t op1, uint32_t op2) {
    return __builtin_arm_uhsub8(op1, op2);
}

/**
 * @brief Unsigned Halving Subtract 16 (UHSUB16)
 * @brief 无符号折半减法 16 位
 */
__STATIC_INLINE uint32_t __UHSUB16(uint32_t op1, uint32_t op2) {
    return __builtin_arm_uhsub16(op1, op2);
}

/**
 * @brief Signed Saturating Subtract 8 (QSUB8)
 * @brief 带符号饱和减法 8 位
 */
__STATIC_INLINE int32_t __QSUB8(int32_t op1, int32_t op2) {
    return __builtin_arm_qsub8(op1, op2);
}

/**
 * @brief Signed Saturating Subtract 16 (QSUB16)
 * @brief 带符号饱和减法 16 位
 */
__STATIC_INLINE int32_t __QSUB16(int32_t op1, int32_t op2) {
    return __builtin_arm_qsub16(op1, op2);
}

/**
 * @brief Unsigned Sum of Absolute Differences (USAD8)
 * @brief 无符号绝对差之和
 */
__STATIC_INLINE uint32_t __USAD8(uint32_t op1, uint32_t op2) {
    return __builtin_arm_usad8(op1, op2);
}

/**
 * @brief Unsigned Sum of Absolute Differences Accumulate (USADA8)
 * @brief 无符号绝对差之和累加
 */
__STATIC_INLINE uint32_t __USADA8(uint32_t op1, uint32_t op2, uint32_t op3) {
    return __builtin_arm_usada8(op1, op2, op3);
}

/**
 * @brief Signed Saturate 16 (SSAT16)
 * @brief 带符号饱和 16 位
 */
__STATIC_INLINE uint32_t __SSAT16(uint32_t op1, uint32_t sat) {
    return __builtin_arm_ssat16(op1, sat);
}

/**
 * @brief Unsigned Saturate 16 (USAT16)
 * @brief 无符号饱和 16 位
 */
__STATIC_INLINE uint32_t __USAT16(uint32_t op1, uint32_t sat) {
    return __builtin_arm_usat16(op1, sat);
}

/**
 * @brief Unsigned Extend Byte 16 (UXTB16)
 * @brief 无符号扩展字节 16 位
 */
__STATIC_INLINE uint32_t __UXTB16(uint32_t op1) {
    return __builtin_arm_uxtb16(op1);
}

/**
 * @brief Unsigned Extend Byte Accumulate 16 (UXTAB16)
 * @brief 无符号扩展字节累加 16 位
 */
__STATIC_INLINE uint32_t __UXTAB16(uint32_t op1, uint32_t op2) {
    return __builtin_arm_uxtab16(op1, op2);
}

/**
 * @brief Signed Extend Byte 16 (SXTB16)
 * @brief 带符号扩展字节 16 位
 */
__STATIC_INLINE int32_t __SXTB16(int32_t op1) {
    return __builtin_arm_sxtb16(op1);
}

/**
 * @brief Signed Extend Byte Accumulate 16 (SXTAB16)
 * @brief 带符号扩展字节累加 16 位
 */
__STATIC_INLINE int32_t __SXTAB16(int32_t op1, int32_t op2) {
    return __builtin_arm_sxtab16(op1, op2);
}

/**
 * @brief Signed Dual Multiply Add (SMUAD)
 * @brief 带符号双乘加
 */
__STATIC_INLINE int32_t __SMUAD(int32_t op1, int32_t op2) {
    return __builtin_arm_smuad(op1, op2);
}

/**
 * @brief Signed Dual Multiply Add Exchange (SMUADX)
 * @brief 带符号双乘加交换
 */
__STATIC_INLINE int32_t __SMUADX(int32_t op1, int32_t op2) {
    return __builtin_arm_smuadx(op1, op2);
}

/**
 * @brief Signed Multiply Accumulate Dual (SMLADX)
 * @brief 带符号乘加双端
 */
__STATIC_INLINE int32_t __SMLADX(int32_t op1, int32_t op2, int32_t op3) {
    return __builtin_arm_smladx(op1, op2, op3);
}

/**
 * @brief Signed Multiply Accumulate Long Dual (SMLALDX)
 * @brief 带符号长乘加双端
 */
__STATIC_INLINE int64_t __SMLALDX(int32_t op1, int32_t op2, int64_t op3) {
    return __builtin_arm_smlaldx(op1, op2, op3);
}

/**
 * @brief Signed Dual Multiply Subtract (SMUSD)
 * @brief 带符号双乘减
 */
__STATIC_INLINE int32_t __SMUSD(int32_t op1, int32_t op2) {
    return __builtin_arm_smusd(op1, op2);
}

/**
 * @brief Signed Dual Multiply Subtract Exchange (SMUSDX)
 * @brief 带符号双乘减交换
 */
__STATIC_INLINE int32_t __SMUSDX(int32_t op1, int32_t op2) {
    return __builtin_arm_smusdx(op1, op2);
}

/**
 * @brief Signed Multiply Subtract Accumulate Dual (SMLSDX)
 * @brief 带符号乘减累加双端
 */
__STATIC_INLINE int32_t __SMLSDX(int32_t op1, int32_t op2, int32_t op3) {
    return __builtin_arm_smlsdx(op1, op2, op3);
}

/**
 * @brief Signed Multiply Subtract Accumulate Long Dual (SMLSLDX)
 * @brief 带符号长乘减累加双端
 */
__STATIC_INLINE int64_t __SMLSLDX(int32_t op1, int32_t op2, int64_t op3) {
    return __builtin_arm_smlsldx(op1, op2, op3);
}

/**
 * @brief Dual Signed Subtract and Add (SSAX)
 * @brief 双带符号减法和加法
 */
__STATIC_INLINE int32_t __SSAX(int32_t op1, int32_t op2) {
    return __builtin_arm_ssax(op1, op2);
}

/**
 * @brief Dual Signed Saturating Subtract and Add (QSAX)
 * @brief 双带符号饱和减法和加法
 */
__STATIC_INLINE int32_t __QSAX(int32_t op1, int32_t op2) {
    return __builtin_arm_qsax(op1, op2);
}

/**
 * @brief Dual Signed Halving Subtract and Add (SHSAX)
 * @brief 双带符号折半减法和加法
 */
__STATIC_INLINE int32_t __SHSAX(int32_t op1, int32_t op2) {
    return __builtin_arm_shsax(op1, op2);
}

/**
 * @brief Dual Unsigned Subtract and Add (USAX)
 * @brief 双无符号减法和加法
 */
__STATIC_INLINE uint32_t __USAX(uint32_t op1, uint32_t op2) {
    return __builtin_arm_usax(op1, op2);
}

/**
 * @brief Dual Unsigned Saturating Subtract and Add (UQSAX)
 * @brief 双无符号饱和减法和加法
 */
__STATIC_INLINE uint32_t __UQSAX(uint32_t op1, uint32_t op2) {
    return __builtin_arm_uqsax(op1, op2);
}

/**
 * @brief Dual Unsigned Halving Subtract and Add (UHSAX)
 * @brief 双无符号折半减法和加法
 */
__STATIC_INLINE uint32_t __UHSAX(uint32_t op1, uint32_t op2) {
    return __builtin_arm_uhsax(op1, op2);
}

/**
 * @brief Dual Signed Add and Subtract (SASX)
 * @brief 双带符号加法和减法
 */
__STATIC_INLINE int32_t __SASX(int32_t op1, int32_t op2) {
    return __builtin_arm_sasx(op1, op2);
}

/**
 * @brief Dual Signed Saturating Add and Subtract (QASX)
 * @brief 双带符号饱和加法和减法
 */
__STATIC_INLINE int32_t __QASX(int32_t op1, int32_t op2) {
    return __builtin_arm_qasx(op1, op2);
}

/**
 * @brief Dual Signed Halving Add and Subtract (SHASX)
 * @brief 双带符号折半加法和减法
 */
__STATIC_INLINE int32_t __SHASX(int32_t op1, int32_t op2) {
    return __builtin_arm_shasx(op1, op2);
}

/**
 * @brief Dual Unsigned Add and Subtract (UASX)
 * @brief 双无符号加法和减法
 */
__STATIC_INLINE uint32_t __UASX(uint32_t op1, uint32_t op2) {
    return __builtin_arm_uasx(op1, op2);
}

/**
 * @brief Dual Unsigned Saturating Add and Subtract (UQASX)
 * @brief 双无符号饱和加法和减法
 */
__STATIC_INLINE uint32_t __UQASX(uint32_t op1, uint32_t op2) {
    return __builtin_arm_uqasx(op1, op2);
}

/**
 * @brief Dual Unsigned Halving Add and Subtract (UHASX)
 * @brief 双无符号折半加法和减法
 */
__STATIC_INLINE uint32_t __UHASX(uint32_t op1, uint32_t op2) {
    return __builtin_arm_uhasx(op1, op2);
}

/**
 * @brief Signed Extend Byte 16 Rotate (SXTB16_RORn)
 * @brief 带符号扩展字节 16 位旋转
 */
#define __SXTB16_RORn(ARG1, ARG2) __SXTB16(__ROR((ARG1), (ARG2)))

/**
 * @brief Signed Extend Byte Accumulate 16 Rotate (SXTAB16_RORn)
 * @brief 带符号扩展字节累加 16 位旋转
 */
#define __SXTAB16_RORn(ARG1, ARG2, ARG3) __SXTAB16((ARG1), __ROR((ARG2), (ARG3)))

/**
 * @brief Signed Multiply Multiply Accumulate (SMMLA)
 * @brief 带符号乘乘累加
 */
__STATIC_INLINE int32_t __SMMLA(int32_t op1, int32_t op2, int32_t op3) {
    int32_t result;
    __asm__ volatile ("smmla %0, %1, %2, %3" : "=r" (result): "r"  (op1), "r" (op2), "r" (op3) );
    return result;
}

/**
 * @brief Pack Halfword Bottom Top
 * @brief 打包半字底到顶
 *
 * Reference: Arm® v8-M ARM Chapter B6 (The Thumb instruction set)
 * 参考: Arm® v8-M ARM Chapter B6 (Thumb 指令集)
 *
 * @param ARG1: First argument (bottom 16 bits)
 * @param ARG1: 第一个参数 (低16位)
 * @param ARG2: Second argument (top 16 bits)
 * @param ARG2: 第二个参数 (高16位)
 * @param ARG3: Shift amount
 * @param ARG3: 移位量
 */
#define __PKHBT(ARG1,ARG2,ARG3) \
    __builtin_arm_pkhbt((ARG1), (ARG2), (ARG3))

/**
 * @brief Pack Halfword Top Bottom
 * @brief 打包半字顶到底
 *
 * Reference: Arm® v8-M ARM Chapter B6 (The Thumb instruction set)
 * 参考: Arm® v8-M ARM Chapter B6 (Thumb 指令集)
 *
 * @param ARG1: First argument (top 16 bits)
 * @param ARG1: 第一个参数 (高16位)
 * @param ARG2: Second argument (bottom 16 bits)
 * @param ARG2: 第二个参数 (低16位)
 * @param ARG3: Shift amount
 * @param ARG3: 移位量
 */
#define __PKHTB(ARG1,ARG2,ARG3) \
    __builtin_arm_pkhtb((ARG1), (ARG2), (ARG3))

#endif /* __ARM_FEATURE_DSP */

#if defined(__ARM_FEATURE_MVE) && (__ARM_FEATURE_MVE == 1)

/*
 * ============================================================================
 * ARMv8.1-M Helium (MVE) Intrinsics
 * ARMv8.1-M Helium (MVE) 内在函数
 *
 * Helium (MVE - M-Profile Vector Extension) provides optional advanced vector
 * processing capabilities.
 * Helium (MVE - M-Profile 向量扩展) 提供可选的高级向量处理能力。
 *
 * Note: MVE intrinsics use __arm_mve_* builtins
 * 注意: MVE 内在函数使用 __arm_mve_* 内置函数
 * ============================================================================
 */

/**
 * @brief MVE Vector integer add
 * @brief MVE 向量整数加法
 */
__STATIC_INLINE int32_t __MVE_ADD(int32_t a, int32_t b) {
    return __builtin_arm_mve_add(a, b);
}

/**
 * @brief MVE Vector saturating add
 * @brief MVE 向量饱和加法
 */
__STATIC_INLINE int32_t __MVE_QADD(int32_t a, int32_t b) {
    return __builtin_arm_mve_qadd(a, b);
}

/**
 * @brief MVE Vector multiply
 * @brief MVE 向量乘法
 */
__STATIC_INLINE int32_t __MVE_MUL(int32_t a, int32_t b) {
    return __builtin_arm_mve_mul(a, b);
}

/**
 * @brief MVE Vector multiply accumulate
 * @brief MVE 向量乘加
 */
__STATIC_INLINE int32_t __MVE_MLA(int32_t a, int32_t b, int32_t c) {
    return __builtin_arm_mve_mla(a, b, c);
}

#endif /* __ARM_FEATURE_MVE */

/*
 * ============================================================================
 * ARMv8-M TrustZone (TZ) Non-Secure Register Access
 * ARMv8-M TrustZone (TZ) 非安全寄存器访问
 *
 * These functions access non-secure registers when in secure state.
 * 这些函数在安全状态下访问非安全寄存器。
 * ============================================================================
 */

#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3)

/**
 * @brief Get CONTROL register (Non-Secure)
 * @brief 获取 CONTROL 寄存器 (非安全)
 */
#ifndef __TZ_get_CONTROL_NS
__STATIC_INLINE uint32_t __TZ_get_CONTROL_NS(void) {
    return arch_armv8m_tz_get_control_ns();
}
#endif

/**
 * @brief Set CONTROL register (Non-Secure)
 * @brief 设置 CONTROL 寄存器 (非安全)
 */
#ifndef __TZ_set_CONTROL_NS
__STATIC_INLINE void __TZ_set_CONTROL_NS(uint32_t control) {
    arch_armv8m_tz_set_control_ns(control);
}
#endif

/**
 * @brief Get PSP register (Non-Secure)
 * @brief 获取 PSP 寄存器 (非安全)
 */
#ifndef __TZ_get_PSP_NS
__STATIC_INLINE uint32_t __TZ_get_PSP_NS(void) {
    return arch_armv8m_tz_get_psp_ns();
}
#endif

/**
 * @brief Set PSP register (Non-Secure)
 * @brief 设置 PSP 寄存器 (非安全)
 */
#ifndef __TZ_set_PSP_NS
__STATIC_INLINE void __TZ_set_PSP_NS(uint32_t psp) {
    arch_armv8m_tz_set_psp_ns(psp);
}
#endif

/**
 * @brief Get MSP register (Non-Secure)
 * @brief 获取 MSP 寄存器 (非安全)
 */
#ifndef __TZ_get_MSP_NS
__STATIC_INLINE uint32_t __TZ_get_MSP_NS(void) {
    return arch_armv8m_tz_get_msp_ns();
}
#endif

/**
 * @brief Set MSP register (Non-Secure)
 * @brief 设置 MSP 寄存器 (非安全)
 */
#ifndef __TZ_set_MSP_NS
__STATIC_INLINE void __TZ_set_MSP_NS(uint32_t msp) {
    arch_armv8m_tz_set_msp_ns(msp);
}
#endif

/**
 * @brief Get SP register (Non-Secure)
 * @brief 获取 SP 寄存器 (非安全)
 */
#ifndef __TZ_get_SP_NS
__STATIC_INLINE uint32_t __TZ_get_SP_NS(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, sp_ns" : "=r" (result) );
    return (result);
}
#endif

/**
 * @brief Set SP register (Non-Secure)
 * @brief 设置 SP 寄存器 (非安全)
 */
#ifndef __TZ_set_SP_NS
__STATIC_INLINE void __TZ_set_SP_NS(uint32_t topOfStack) {
    __asm__ volatile ("MSR sp_ns, %0" : : "r" (topOfStack) : );
}
#endif

/**
 * @brief Get PRIMASK register (Non-Secure)
 * @brief 获取 PRIMASK 寄存器 (非安全)
 */
#ifndef __TZ_get_PRIMASK_NS
__STATIC_INLINE uint32_t __TZ_get_PRIMASK_NS(void) {
    return arch_armv8m_tz_get_primask_ns();
}
#endif

/**
 * @brief Set PRIMASK register (Non-Secure)
 * @brief 设置 PRIMASK 寄存器 (非安全)
 */
#ifndef __TZ_set_PRIMASK_NS
__STATIC_INLINE void __TZ_set_PRIMASK_NS(uint32_t primask) {
    arch_armv8m_tz_set_primask_ns(primask);
}
#endif

/**
 * @brief Get BASEPRI register (Non-Secure)
 * @brief 获取 BASEPRI 寄存器 (非安全)
 */
#ifndef __TZ_get_BASEPRI_NS
__STATIC_INLINE uint32_t __TZ_get_BASEPRI_NS(void) {
    return arch_armv8m_tz_get_basepri_ns();
}
#endif

/**
 * @brief Set BASEPRI register (Non-Secure)
 * @brief 设置 BASEPRI 寄存器 (非安全)
 */
#ifndef __TZ_set_BASEPRI_NS
__STATIC_INLINE void __TZ_set_BASEPRI_NS(uint32_t basepri) {
    arch_armv8m_tz_set_basepri_ns(basepri);
}
#endif

/**
 * @brief Get FAULTMASK register (Non-Secure)
 * @brief 获取 FAULTMASK 寄存器 (非安全)
 */
#ifndef __TZ_get_FAULTMASK_NS
__STATIC_INLINE uint32_t __TZ_get_FAULTMASK_NS(void) {
    return arch_armv8m_tz_get_faultmask_ns();
}
#endif

/**
 * @brief Set FAULTMASK register (Non-Secure)
 * @brief 设置 FAULTMASK 寄存器 (非安全)
 */
#ifndef __TZ_set_FAULTMASK_NS
__STATIC_INLINE void __TZ_set_FAULTMASK_NS(uint32_t faultmask) {
    arch_armv8m_tz_set_faultmask_ns(faultmask);
}
#endif

/**
 * @brief Get PSPLIM register (Non-Secure)
 * @brief 获取 PSPLIM 寄存器 (非安全)
 */
#ifndef __TZ_get_PSPLIM_NS
__STATIC_INLINE uint32_t __TZ_get_PSPLIM_NS(void) {
    return arch_armv8m_tz_get_psplim_ns();
}
#endif

/**
 * @brief Set PSPLIM register (Non-Secure)
 * @brief 设置 PSPLIM 寄存器 (非安全)
 */
#ifndef __TZ_set_PSPLIM_NS
__STATIC_INLINE void __TZ_set_PSPLIM_NS(uint32_t psplim) {
    arch_armv8m_tz_set_psplim_ns(psplim);
}
#endif

/**
 * @brief Get MSPLIM register (Non-Secure)
 * @brief 获取 MSPLIM 寄存器 (非安全)
 */
#ifndef __TZ_get_MSPLIM_NS
__STATIC_INLINE uint32_t __TZ_get_MSPLIM_NS(void) {
    return arch_armv8m_tz_get_msplim_ns();
}
#endif

/**
 * @brief Set MSPLIM register (Non-Secure)
 * @brief 设置 MSPLIM 寄存器 (非安全)
 */
#ifndef __TZ_set_MSPLIM_NS
__STATIC_INLINE void __TZ_set_MSPLIM_NS(uint32_t msplim) {
    arch_armv8m_tz_set_msplim_ns(msplim);
}
#endif

#ifndef __TZ_STACK_SEAL_SIZE
#define __TZ_STACK_SEAL_SIZE      8U
#endif

#ifndef __TZ_STACK_SEAL_VALUE
#define __TZ_STACK_SEAL_VALUE     0xFEF5EDA5FEF5EDA5ULL
#endif

/**
 * @brief Set stack seal value
 * @brief 设置堆栈密封值
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @param stackTop: Top of stack address
 * @param stackTop: 栈顶地址
 */
#ifndef __TZ_set_STACKSEAL_S
__STATIC_INLINE void __TZ_set_STACKSEAL_S(uint32_t* stackTop) {
    *((uint64_t *)stackTop) = __TZ_STACK_SEAL_VALUE;
}
#endif

#endif /* __ARM_FEATURE_CMSE */

/**
 * @brief Set priority grouping
 * @brief 设置优先级分组
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM Chapter B12 (嵌套向量中断控制器)
 *
 * @param PriorityGroup: Priority grouping value (0-7)
 * @param PriorityGroup: 优先级分组值 (0-7)
 */
__STATIC_INLINE void __NVIC_SetPriorityGrouping(uint32_t PriorityGroup) {
    uint32_t reg_value;
    uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);

    reg_value  =  SCB->AIRCR;
    reg_value &= ~((uint32_t)((0x07UL << 8U) | (uint32_t)0x07UL));
    reg_value  = (reg_value                                   |
                  ((uint32_t)0x5FAUL << 16U)                  |
                  (PriorityGroupTmp << 8U)                     );
    SCB->AIRCR = reg_value;
}

/**
 * @brief Get priority grouping
 * @brief 获取优先级分组
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM Chapter B12 (嵌套向量中断控制器)
 *
 * @return Priority grouping value
 * @return 优先级分组值
 */
__STATIC_INLINE uint32_t __NVIC_GetPriorityGrouping(void) {
    return ((uint32_t)((SCB->AIRCR >> 8U) & (uint32_t)0x07UL));
}

/**
 * @brief Enable specified interrupt
 * @brief 使能指定中断
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM Chapter B12 (嵌套向量中断控制器)
 *
 * @param IRQn: Interrupt number (>= 0)
 * @param IRQn: 中断号 (>= 0)
 */
__STATIC_INLINE void __NVIC_EnableIRQ(int32_t IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        NVIC->ISER[tmp] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
    }
}

/**
 * @brief Get enable status of specified interrupt
 * @brief 获取指定中断的使能状态
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM Chapter B12 (嵌套向量中断控制器)
 *
 * @param IRQn: Interrupt number (>= 0)
 * @param IRQn: 中断号 (>= 0)
 * @return Enable status (0=disabled, 1=enabled)
 * @return 使能状态 (0=禁用, 1=使能)
 */
__STATIC_INLINE uint32_t __NVIC_GetEnableIRQ(int32_t IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        return((uint32_t)(((NVIC->ISER[tmp] >> (((uint32_t)(int32_t)IRQn) & 0x1FUL)) & 1U)));
    } else {
        return(0U);
    }
}

/**
 * @brief Disable specified interrupt
 * @brief 禁用指定中断
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM Chapter B12 (嵌套向量中断控制器)
 *
 * @param IRQn: Interrupt number (>= 0)
 * @param IRQn: 中断号 (>= 0)
 */
__STATIC_INLINE void __NVIC_DisableIRQ(int32_t IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        NVIC->ICER[tmp] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
    }
}

/**
 * @brief Get pending status of specified interrupt
 * @brief 获取指定中断的挂起状态
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM Chapter B12 (嵌套向量中断控制器)
 *
 * @param IRQn: Interrupt number (>= 0)
 * @param IRQn: 中断号 (>= 0)
 * @return Pending status (0=not pending, 1=pending)
 * @return 挂起状态 (0=未挂起, 1=挂起)
 */
__STATIC_INLINE uint32_t __NVIC_GetPendingIRQ(int32_t IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        return((uint32_t)(((NVIC->ISPR[tmp] >> (((uint32_t)(int32_t)IRQn) & 0x1FUL)) & 1U)));
    } else {
        return(0U);
    }
}

/**
 * @brief Set interrupt pending status
 * @brief 设置中断挂起状态
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM Chapter B12 (嵌套向量中断控制器)
 *
 * @param IRQn: Interrupt number (>= 0)
 * @param IRQn: 中断号 (>= 0)
 */
__STATIC_INLINE void __NVIC_SetPendingIRQ(int32_t IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        NVIC->ISPR[tmp] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
    }
}

/**
 * @brief Clear interrupt pending status
 * @brief 清除中断挂起状态
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM Chapter B12 (嵌套向量中断控制器)
 *
 * @param IRQn: Interrupt number (>= 0)
 * @param IRQn: 中断号 (>= 0)
 */
__STATIC_INLINE void __NVIC_ClearPendingIRQ(int32_t IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        NVIC->ICPR[tmp] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
    }
}

/**
 * @brief Get active status of specified interrupt
 * @brief 获取指定中断的活动状态
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM Chapter B12 (嵌套向量中断控制器)
 *
 * @param IRQn: Interrupt number (>= 0)
 * @param IRQn: 中断号 (>= 0)
 * @return Active status (0=not active, 1=active)
 * @return 活动状态 (0=未活动, 1=活动)
 */
__STATIC_INLINE uint32_t __NVIC_GetActive(int32_t IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        return((uint32_t)(((NVIC->IABR[tmp] >> (((uint32_t)(int32_t)IRQn) & 0x1FUL)) & 1U)));
    } else {
        return(0U);
    }
}

/**
 * @brief Set interrupt priority
 * @brief 设置中断优先级
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM Chapter B12 (嵌套向量中断控制器)
 *
 * @param IRQn: Interrupt number (>= 0)
 * @param IRQn: 中断号 (>= 0)
 * @param priority: Priority value (0=highest, 255=lowest)
 * @param priority: 优先级值 (0=最高, 255=最低)
 */
__STATIC_INLINE void __NVIC_SetPriority(int32_t IRQn, uint32_t priority) {
    if ((int32_t)(IRQn) >= 0) {
        NVIC->IP[(uint32_t)(IRQn)] =
            (uint8_t)((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL);
    }
}

/**
 * @brief Get interrupt priority
 * @brief 获取中断优先级
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM Chapter B12 (嵌套向量中断控制器)
 *
 * @param IRQn: Interrupt number (>= 0)
 * @param IRQn: 中断号 (>= 0)
 * @return Priority value
 * @return 优先级值
 */
__STATIC_INLINE uint32_t __NVIC_GetPriority(int32_t IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        return(((uint32_t)(NVIC->IP[(uint32_t)(IRQn)] >> (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL));
    } else {
        return(0U);
    }
}

/**
 * @brief Encode priority
 * @brief 编码优先级
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM Chapter B12 (嵌套向量中断控制器)
 *
 * @param PriorityGroup: Priority grouping value
 * @param PriorityGroup: 优先级分组值
 * @param PreemptPriority: Preemption priority
 * @param PreemptPriority: 抢占优先级
 * @param SubPriority: Sub-priority
 * @param SubPriority: 子优先级
 * @return Encoded priority value
 * @return 编码后的优先级值
 */
__STATIC_INLINE uint32_t __NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority) {
    uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);
    uint32_t PreemptPriorityBits;
    uint32_t SubPriorityBits;

    PreemptPriorityBits = ((7UL - PriorityGroupTmp) < (uint32_t)(__NVIC_PRIO_BITS)) ?
                          (uint32_t)(7UL - PriorityGroupTmp) : (uint32_t)(__NVIC_PRIO_BITS);
    SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(__NVIC_PRIO_BITS)) < (uint32_t)7UL) ?
                          (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + __NVIC_PRIO_BITS);

    return (
           ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
           ((SubPriority & (uint32_t)((1UL << (SubPriorityBits)) - 1UL))
          );
}

/**
 * @brief Decode priority
 * @brief 解码优先级
 *
 * Reference: Arm® v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 * 参考: Arm® v8-M ARM Chapter B12 (嵌套向量中断控制器)
 *
 * @param Priority: Encoded priority value
 * @param Priority: 编码后的优先级值
 * @param PriorityGroup: Priority grouping value
 * @param PriorityGroup: 优先级分组值
 * @param pPreemptPriority: Output preemption priority
 * @param pPreemptPriority: 输出抢占优先级
 * @param pSubPriority: Output sub-priority
 * @param pSubPriority: 输出子优先级
 */
__STATIC_INLINE void __NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* const pPreemptPriority, uint32_t* const pSubPriority) {
    uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);
    uint32_t PreemptPriorityBits;
    uint32_t SubPriorityBits;

    PreemptPriorityBits = ((7UL - PriorityGroupTmp) < (uint32_t)(__NVIC_PRIO_BITS)) ?
                          (uint32_t)(7UL - PriorityGroupTmp) : (uint32_t)(__NVIC_PRIO_BITS);
    SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(__NVIC_PRIO_BITS)) < (uint32_t)7UL) ?
                          (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + __NVIC_PRIO_BITS);

    *pPreemptPriority = (Priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
    *pSubPriority     = (Priority & (uint32_t)((1UL << (SubPriorityBits)) - 1UL));
}

/**
 * @brief Set interrupt vector
 * @brief 设置中断向量
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @param IRQn: Interrupt number
 * @param IRQn: 中断号
 * @param vector: Vector address
 * @param vector: 向量地址
 */
__STATIC_INLINE void __NVIC_SetVector(int32_t IRQn, uint32_t vector) {
    uint32_t *vectors = (uint32_t *)SCB->VTOR;
    vectors[(int16_t)IRQn + 16] = vector;
}

/**
 * @brief Get interrupt vector
 * @brief 获取中断向量
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @param IRQn: Interrupt number
 * @param IRQn: 中断号
 * @return Vector address
 * @return 向量地址
 */
__STATIC_INLINE uint32_t __NVIC_GetVector(int32_t IRQn) {
    uint32_t *vectors = (uint32_t *)SCB->VTOR;
    return vectors[(int16_t)IRQn + 16];
}

/**
 * @brief Trigger system reset
 * @brief 触发系统复位
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 */
__STATIC_INLINE void __NVIC_SystemReset(void) {
    SCB->AIRCR  = ((0x5FAUL << 16U) | (SCB->AIRCR & (7UL << 8U)) | (1UL << 2U));
    __DSB();
    for(;;) {
        __NOP();
    }
}

/**
 * @brief SysTick configuration
 * @brief SysTick 配置
 *
 * Reference: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (系统定时器, SysTick)
 *
 * @param ticks: Number of ticks between interrupts
 * @param ticks: 中断之间的tick数
 * @return 1=success, 0=failed
 * @return 1=成功, 0=失败
 */
__STATIC_INLINE uint32_t __SysTick_Config(uint32_t ticks) {
    if ((ticks - 1UL) > 0xFFFFFFUL) {
        return (1UL);
    }
    SysTick->LOAD = (uint32_t)(ticks - 1UL);
    __NVIC_SetPriority(-1, (1UL << __NVIC_PRIO_BITS) - 1UL);
    SysTick->VAL  = 0UL;
    SysTick->CTRL = SYSTICK_CTRL_CLKSOURCE_Msk |
                    SYSTICK_CTRL_TICKINT_Msk   |
                    SYSTICK_CTRL_ENABLE_Msk;
    return (0UL);
}

/**
 * @brief Get SysTick current value
 * @brief 获取 SysTick 当前值
 *
 * Reference: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (系统定时器, SysTick)
 *
 * @return Current counter value
 * @return 当前计数器值
 */
__STATIC_INLINE uint32_t __SysTick_GetValue(void) {
    return SysTick->VAL;
}

/**
 * @brief Set SysTick reload value
 * @brief 设置 SysTick 加载值
 *
 * Reference: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (系统定时器, SysTick)
 *
 * @param value: Reload value
 * @param value: 加载值
 */
__STATIC_INLINE void __SysTick_SetReload(uint32_t value) {
    SysTick->LOAD = value;
}

/**
 * @brief Get SysTick reload value
 * @brief 获取 SysTick 加载值
 *
 * Reference: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (系统定时器, SysTick)
 *
 * @return Reload value
 * @return 加载值
 */
__STATIC_INLINE uint32_t __SysTick_GetReload(void) {
    return SysTick->LOAD;
}

/**
 * @brief Enable SysTick interrupt
 * @brief 使能 SysTick 中断
 *
 * Reference: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (系统定时器, SysTick)
 */
__STATIC_INLINE void __SysTick_EnableIRQ(void) {
    SysTick->CTRL |= SYSTICK_CTRL_TICKINT_Msk;
}

/**
 * @brief Disable SysTick interrupt
 * @brief 禁用 SysTick 中断
 *
 * Reference: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (系统定时器, SysTick)
 */
__STATIC_INLINE void __SysTick_DisableIRQ(void) {
    SysTick->CTRL &= ~SYSTICK_CTRL_TICKINT_Msk;
}

/**
 * @brief Enable SysTick timer
 * @brief 使能 SysTick 定时器
 *
 * Reference: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (系统定时器, SysTick)
 */
__STATIC_INLINE void __SysTick_Enable(void) {
    SysTick->CTRL |= SYSTICK_CTRL_ENABLE_Msk;
}

/**
 * @brief Disable SysTick timer
 * @brief 禁用 SysTick 定时器
 *
 * Reference: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (系统定时器, SysTick)
 */
__STATIC_INLINE void __SysTick_Disable(void) {
    SysTick->CTRL &= ~SYSTICK_CTRL_ENABLE_Msk;
}

/**
 * @brief Get SysTick calibration value
 * @brief 获取 SysTick 校准值
 *
 * Reference: Arm® v8-M ARM Chapter B11 (The System Timer, SysTick)
 * 参考: Arm® v8-M ARM Chapter B11 (系统定时器, SysTick)
 *
 * @return Calibration value
 * @return 校准值
 */
__STATIC_INLINE uint32_t __SysTick_GetCalib(void) {
    return SysTick->CALIB;
}

/**
 * @brief Enable FPU
 * @brief 使能 FPU
 *
 * Reference: Arm® v8-M ARM Chapter B4 (Floating-point Support)
 * 参考: Arm® v8-M ARM Chapter B4 (浮点支持)
 */
__STATIC_INLINE void __FPU_Enable(void) {
    uint32_t cpacr = __FPU_GetCPACR();
    cpacr |= ((3UL << 10U*2U) | (3UL << 11U*2U));
    __FPU_SetCPACR(cpacr);
}

/**
 * @brief Disable FPU
 * @brief 禁用 FPU
 *
 * Reference: Arm® v8-M ARM Chapter B4 (Floating-point Support)
 * 参考: Arm® v8-M ARM Chapter B4 (浮点支持)
 */
__STATIC_INLINE void __FPU_Disable(void) {
    uint32_t cpacr = __FPU_GetCPACR();
    cpacr &= ~((3UL << 10U*2U) | (3UL << 11U*2U));
    __FPU_SetCPACR(cpacr);
}

/**
 * @brief Get FPSCR
 * @brief 获取 FPSCR
 *
 * Reference: Arm® v8-M ARM Chapter B4 (Floating-point Support)
 * 参考: Arm® v8-M ARM Chapter B4 (浮点支持)
 *
 * @return Floating Point Status/Control register value
 * @return 浮点状态/控制寄存器值
 */
#ifndef __get_FPSCR
__STATIC_INLINE uint32_t __get_FPSCR(void) {
#if (defined(__ARM_FP) && (__ARM_FP >= 1))
    return (__builtin_arm_get_fpscr());
#else
    return (0U);
#endif
}
#endif

/**
 * @brief Set FPSCR
 * @brief 设置 FPSCR
 *
 * Reference: Arm® v8-M ARM Chapter B4 (Floating-point Support)
 * 参考: Arm® v8-M ARM Chapter B4 (浮点支持)
 *
 * @param fpscr Floating Point Status/Control value to set
 * @param fpscr 要设置的浮点状态/控制值
 */
#ifndef __set_FPSCR
__STATIC_INLINE void __set_FPSCR(uint32_t fpscr) {
#if (defined(__ARM_FP) && (__ARM_FP >= 1))
    __builtin_arm_set_fpscr(fpscr);
#else
    (void)fpscr;
#endif
}
#endif

/**
 * @brief Get FPCAR (Floating Point Context Address Register)
 * @brief 获取 FPCAR (浮点上下文地址寄存器)
 *
 * Reference: Arm® v8-M ARM Chapter B4 (Floating-point Support)
 * 参考: Arm® v8-M ARM Chapter B4 (浮点支持)
 *
 * @return Floating Point Context Address Register value
 * @return 浮点上下文地址寄存器值
 */
#ifndef __get_FPCAR
__STATIC_INLINE uint32_t __get_FPCAR(void) {
    uint32_t result;
#if (defined(__ARM_FP) && (__ARM_FP >= 1))
    __asm__ volatile ("MRS %0, fpcar" : "=r" (result) );
#else
    result = 0U;
#endif
    return (result);
}
#endif

/**
 * @brief Set FPCAR (Floating Point Context Address Register)
 * @brief 设置 FPCAR (浮点上下文地址寄存器)
 *
 * Reference: Arm® v8-M ARM Chapter B4 (Floating-point Support)
 * 参考: Arm® v8-M ARM Chapter B4 (浮点支持)
 *
 * @param fpcar Floating Point Context Address value to set
 * @param fpcar 要设置的浮点上下文地址值
 */
#ifndef __set_FPCAR
__STATIC_INLINE void __set_FPCAR(uint32_t fpcar) {
#if (defined(__ARM_FP) && (__ARM_FP >= 1))
    __asm__ volatile ("MSR fpcar, %0" : : "r" (fpcar) : "memory");
#else
    (void)fpcar;
#endif
}
#endif

/**
 * @brief Get FPDSCR (Floating Point Default Status Control Register)
 * @brief 获取 FPDSCR (浮点默认状态控制寄存器)
 *
 * Reference: Arm® v8-M ARM Chapter B4 (Floating-point Support)
 * 参考: Arm® v8-M ARM Chapter B4 (浮点支持)
 *
 * @return Floating Point Default Status Control Register value
 * @return 浮点默认状态控制寄存器值
 */
#ifndef __get_FPDSCR
__STATIC_INLINE uint32_t __get_FPDSCR(void) {
    uint32_t result;
#if (defined(__ARM_FP) && (__ARM_FP >= 1))
    __asm__ volatile ("MRS %0, fpdscr" : "=r" (result) );
#else
    result = 0U;
#endif
    return (result);
}
#endif

/**
 * @brief Set FPDSCR (Floating Point Default Status Control Register)
 * @brief 设置 FPDSCR (浮点默认状态控制寄存器)
 *
 * Reference: Arm® v8-M ARM Chapter B4 (Floating-point Support)
 * 参考: Arm® v8-M ARM Chapter B4 (浮点支持)
 *
 * @param fpdscr Floating Point Default Status Control value to set
 * @param fpdscr 要设置的浮点默认状态控制值
 */
#ifndef __set_FPDSCR
__STATIC_INLINE void __set_FPDSCR(uint32_t fpdscr) {
#if (defined(__ARM_FP) && (__ARM_FP >= 1))
    __asm__ volatile ("MSR fpdscr, %0" : : "r" (fpdscr) : "memory");
#else
    (void)fpdscr;
#endif
}
#endif

/**
 * @brief Get MPU type
 * @brief 获取 MPU 类型
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @return MPU type register value
 * @return MPU 类型寄存器值
 */
__STATIC_INLINE uint32_t __MPU_GetType(void) {
    return MPU->TYPE;
}

/**
 * @brief Get MPU region count
 * @brief 获取 MPU 区域数量
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @return Number of data regions
 * @return 数据区域数量
 */
__STATIC_INLINE uint32_t __MPU_GetNumRegions(void) {
    return ((MPU->TYPE >> 8) & 0xFFUL);
}

/**
 * @brief Set MPU memory attribute
 * @brief 设置 MPU 内存属性
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @param idx: Attribute index (0-7)
 * @param idx: 属性索引 (0-7)
 * @param attr: Memory attribute
 * @param attr: 内存属性
 */
__STATIC_INLINE void __MPU_SetMemoryAttribute(uint8_t idx, uint8_t attr) {
    if (idx < 4) {
        MPU->MAIR0 = (MPU->MAIR0 & ~(0xFFUL << (idx * 8))) | ((uint32_t)attr << (idx * 8));
    } else {
        MPU->MAIR1 = (MPU->MAIR1 & ~(0xFFUL << ((idx - 4) * 8))) | ((uint32_t)attr << ((idx - 4) * 8));
    }
}

/**
 * @brief Enable MPU
 * @brief 使能 MPU
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @param enable_default_map_forPrivileged: Use default memory map (true=enable, false=disable)
 * @param enable_default_map_forPrivileged: 使用默认内存映射 (true=启用, false=禁用)
 */
__STATIC_INLINE void __MPU_Enable(bool enable_default_map_forPrivileged) {
    __DMB();
    MPU->CTRL = MPU_CTRL_ENABLE_Msk;
    if (enable_default_map_forPrivileged) {
        MPU->CTRL |= MPU_CTRL_PRIVDEFENA_Msk;
    }
    __DSB();
    __ISB();
}

/**
 * @brief Disable MPU
 * @brief 禁用 MPU
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 */
__STATIC_INLINE void __MPU_Disable(void) {
    __DMB();
    MPU->CTRL  &= ~MPU_CTRL_ENABLE_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Set MPU region
 * @brief 设置 MPU 区域
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @param rnr: Region number (0-15)
 * @param rnr: 区域编号 (0-15)
 * @param rbar: Region Base Address Register
 * @param rbar: 区域基地址寄存器
 * @param rlar: Region Limit Register
 * @param rlar: 区域限制寄存器
 */
__STATIC_INLINE void __MPU_SetRegion(uint32_t rnr, uint32_t rbar, uint32_t rlar) {
    MPU->RNR  = rnr;
    MPU->RBAR = rbar;
    MPU->RLAR = rlar;
}

/**
 * @brief Clear MPU region
 * @brief 清除 MPU 区域
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @param rnr: Region number
 * @param rnr: 区域编号
 */
__STATIC_INLINE void __MPU_ClearRegion(uint32_t rnr) {
    MPU->RNR  = rnr;
    MPU->RBAR = 0U;
    MPU->RLAR = 0U;
}

/**
 * @brief Enable SAU (Security Attribution Unit)
 * @brief 使能 SAU (安全属性单元)
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 */
__STATIC_INLINE void __SAU_Enable(void) {
    SAU->CTRL |= (1UL << 0);
}

/**
 * @brief Disable SAU
 * @brief 禁用 SAU
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 */
__STATIC_INLINE void __SAU_Disable(void) {
    SAU->CTRL &= ~(1UL << 0);
}

/**
 * @brief Set SAU region
 * @brief 设置 SAU 区域
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @param rnr: Region number
 * @param rnr: 区域编号
 * @param rbar: Base address
 * @param rbar: 基地址
 * @param rlar: Limit address and attributes
 * @param rlar: 限地址和属性
 */
__STATIC_INLINE void __SAU_SetRegion(uint32_t rnr, uint32_t rbar, uint32_t rlar) {
    SAU->RNR  = rnr;
    SAU->RBAR = rbar;
    SAU->RLAR = rlar;
}

/**
 * @brief Get SAU type
 * @brief 获取 SAU 类型
 *
 * Reference: Arm® v8-M ARM Chapter B10 (The Armv8-M Protected Memory System Architecture)
 * 参考: Arm® v8-M ARM Chapter B10 (Armv8-M 受保护内存系统架构)
 *
 * @return SAU type register value
 * @return SAU 类型寄存器值
 */
__STATIC_INLINE uint32_t __SAU_GetType(void) {
    return SAU->TYPE;
}

/**
 * @brief Get SCB CPUID register
 * @brief 获取 SCB CPUID 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @return CPUID register value
 * @return CPUID 寄存器值
 */
__STATIC_INLINE uint32_t __SCB_GetCPUID(void) {
    return SCB->CPUID;
}

/**
 * @brief Get SCB ICSR register
 * @brief 获取 SCB ICSR 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @return ICSR register value
 * @return ICSR 寄存器值
 */
__STATIC_INLINE uint32_t __SCB_GetICSR(void) {
    return SCB->ICSR;
}

/**
 * @brief Get SCB VTOR register
 * @brief 获取 SCB VTOR 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @return VTOR register value
 * @return VTOR 寄存器值
 */
__STATIC_INLINE uint32_t __SCB_GetVTOR(void) {
    return SCB->VTOR;
}

/**
 * @brief Set SCB VTOR register
 * @brief 设置 SCB VTOR 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @param vtors: VTOR register value
 * @param vtors: VTOR 寄存器值
 */
__STATIC_INLINE void __SCB_SetVTOR(uint32_t vtors) {
    SCB->VTOR = vtors;
}

/**
 * @brief Get SCB SCR register
 * @brief 获取 SCB SCR 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @return SCR register value
 * @return SCR 寄存器值
 */
__STATIC_INLINE uint32_t __SCB_GetSCR(void) {
    return SCB->SCR;
}

/**
 * @brief Set SCB SCR register
 * @brief 设置 SCB SCR 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @param scr: SCR register value
 * @param scr: SCR 寄存器值
 */
__STATIC_INLINE void __SCB_SetSCR(uint32_t scr) {
    SCB->SCR = scr;
}

/**
 * @brief Get SCB CCR register
 * @brief 获取 SCB CCR 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @return CCR register value
 * @return CCR 寄存器值
 */
__STATIC_INLINE uint32_t __SCB_GetCCR(void) {
    return SCB->CCR;
}

/**
 * @brief Get SCB CFSR register
 * @brief 获取 SCB CFSR 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @return CFSR register value
 * @return CFSR 寄存器值
 */
__STATIC_INLINE uint32_t __SCB_GetCFSR(void) {
    return SCB->CFSR;
}

/**
 * @brief Get SCB HFSR register
 * @brief 获取 SCB HFSR 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @return HFSR register value
 * @return HFSR 寄存器值
 */
__STATIC_INLINE uint32_t __SCB_GetHFSR(void) {
    return SCB->HFSR;
}

/**
 * @brief Get SCB MMFAR register
 * @brief 获取 SCB MMFAR 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @return MMFAR register value
 * @return MMFAR 寄存器值
 */
__STATIC_INLINE uint32_t __SCB_GetMMFAR(void) {
    return SCB->MMFAR;
}

/**
 * @brief Get SCB BFAR register
 * @brief 获取 SCB BFAR 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @return BFAR register value
 * @return BFAR 寄存器值
 */
__STATIC_INLINE uint32_t __SCB_GetBFAR(void) {
    return SCB->BFAR;
}

/**
 * @brief Get SCB SHCSR register
 * @brief 获取 SCB SHCSR 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B3 (Programmers' Model)
 * 参考: Arm® v8-M ARM Chapter B3 (程序员模型)
 *
 * @return SHCSR register value
 * @return SHCSR 寄存器值
 */
__STATIC_INLINE uint32_t __SCB_GetSHCSR(void) {
    return SCB->SHCSR;
}

/**
 * @brief Get SCB CPACR register
 * @brief 获取 SCB CPACR 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B4 (Floating-point Support)
 * 参考: Arm® v8-M ARM Chapter B4 (浮点支持)
 *
 * @return CPACR register value
 * @return CPACR 寄存器值
 */
__STATIC_INLINE uint32_t __SCB_GetCPACR(void) {
    return SCB->CPACR;
}

/**
 * @brief Set SCB CPACR register
 * @brief 设置 SCB CPACR 寄存器
 *
 * Reference: Arm® v8-M ARM Chapter B4 (Floating-point Support)
 * 参考: Arm® v8-M ARM Chapter B4 (浮点支持)
 *
 * @param cpacr: CPACR register value
 * @param cpacr: CPACR 寄存器值
 */
__STATIC_INLINE void __SCB_SetCPACR(uint32_t cpacr) {
    SCB->CPACR = cpacr;
}

/**
 * @brief Get FPU type
 * @brief 获取 FPU 类型
 *
 * Reference: Arm® v8-M ARM Chapter B4 (Floating-point Support)
 * 参考: Arm® v8-M ARM Chapter B4 (浮点支持)
 *
 * @return FPU type (0=none, 1=single precision, 2=double precision)
 * @return FPU 类型 (0=无, 1=单精度, 2=双精度)
 */
__STATIC_INLINE uint32_t __SCB_GetFPUType(void) {
    uint32_t mvfr0 = SCB->MVFR0;
    if      ((mvfr0 & (0xFUL << 0U)) == 0x220U) {
        return(2U);
    }
    else if ((mvfr0 & (0xFUL << 0U)) == 0x020U) {
        return(1U);
    }
    else {
        return(0U);
    }
}

/**
 * @brief ITM send character
 * @brief ITM 发送字符
 *
 * Reference: Arm® v8-M ARM Chapter B14 (Debug and Trace Components)
 * 参考: Arm® v8-M ARM Chapter B14 (调试和跟踪组件)
 *
 * @param ch: Character to send
 * @param ch: 要发送的字符
 * @return Character sent (0-255) or 0 if FIFO full
 * @return 发送的字符 (0-255) 或如果 FIFO 满则返回 0
 */
__STATIC_INLINE uint32_t __ITM_SendChar (uint32_t ch) {
    if (((ITM->CTRL & ITM_CTRL_ITMENA_Msk) != 0UL) &&
        ((ITM->TER[0] & (1UL << 0UL)          ) != 0UL)   ) {
        while (ITM->PORT[0U].u32 == 0UL) {
            __NOP();
        }
        ITM->PORT[0U].u8 = (uint8_t)ch;
    }
    return (ch);
}

/**
 * @brief ITM receive character
 * @brief ITM 接收字符
 *
 * Reference: Arm® v8-M ARM Chapter B14 (Debug and Trace Components)
 * 参考: Arm® v8-M ARM Chapter B14 (调试和跟踪组件)
 *
 * @return Received character or -1 if no data
 * @return 接收的字符或如果没有数据则返回 -1
 */
__STATIC_INLINE int32_t __ITM_ReceiveChar (void) {
    int32_t ch = -1;
    if (ITM->RXR != 0UL) {
        ch = (int32_t)ITM->RXR;
    }
    return (ch);
}

/**
 * @brief ITM check if character is waiting
 * @brief ITM 检查是否有字符等待读取
 *
 * Reference: Arm® v8-M ARM Chapter B14 (Debug and Trace Components)
 * 参考: Arm® v8-M ARM Chapter B14 (调试和跟踪组件)
 *
 * @return 1=data available, 0=no data
 * @return 1=有数据可用, 0=无数据
 */
__STATIC_INLINE int32_t __ITM_CheckChar (void) {
    if (ITM->RXR != 0UL) {
        return(1);
    } else {
        return(0);
    }
}

/**
 * @brief ITM enable/disable
 * @brief ITM 使能/禁用
 *
 * Reference: Arm® v8-M ARM Chapter B14 (Debug and Trace Components)
 * 参考: Arm® v8-M ARM Chapter B14 (调试和跟踪组件)
 *
 * @param enable: Enable (1) or disable (0)
 * @param enable: 使能 (1) 或禁用 (0)
 */
__STATIC_INLINE void __ITM_Enable(uint32_t enable) {
    if (enable != 0UL) {
        ITM->CTRL |= (ITM_CTRL_ITMENA_Msk | ITM_CTRL_TRCENA_Msk);
    } else {
        ITM->CTRL &= ~(ITM_CTRL_ITMENA_Msk | ITM_CTRL_TRCENA_Msk);
    }
}





#ifdef __cplusplus
}
#endif

#endif
