/*
 * ARM Cortex-M55 Core Peripheral Access Layer
 * ARM Cortex-M55 核心外设访问层
 *
 * ============================================================================
 * File: core_cm55.h
 * Description: ARM Cortex-M55 core peripheral access layer definitions
 * 描述: ARM Cortex-M55 核心外设访问层定义
 *
 * This file defines all NVIC, SysTick, SCB, FPU, MPU, PMU, TrustZone, Helium functions for ARM Cortex-M55.
 * 本文件定义了 ARM Cortex-M55 的所有 NVIC、SysTick、SCB、FPU、MPU、PMU、TrustZone、Helium 函数。
 *
 * Dependency Hierarchy / 依赖层次:
 *   core_cm55.h → armv8m.h → armv8m.c
 *   (Cortex-M55 specific) (ARMv8-M)  (Implementation)
 *
 * Reference Documents / 参考文档:
 *   1. Arm® v8-M Architecture Reference Manual
 *      - Chapter B3: Programmers' Model
 *      - Chapter B4: Floating-point Support
 *      - Chapter B5: Vector Extension
 *      - Chapter B10: The Armv8-M Protected Memory System Architecture
 *      - Chapter B11: The System Timer, SysTick
 *      - Chapter B12: Nested Vectored Interrupt Controller
 *      - Chapter B13: Debug
 *      - Chapter B14: Debug and Trace Components
 *      - Chapter B15: The Performance Monitors Extension
 *
 *   2. Arm® Cortex™-M55 Devices Generic User Guide
 *      - Chapter 3.1 (Programmer's model)
 *      - Chapter 3.3 (Exception model)
 *      - Chapter 3.3.4 (Vector table)
 *      - Chapter 3.4 (Security state switches)
 *      - Chapter 3.7 (Arm®v8.1‑M MVE overview)
 *      - Chapter 5.2 (Nested Vectored Interrupt Controller)
 *      - Chapter 5.2.6 (Interrupt Target Non-secure Registers)
 *      - Chapter 5.3 (System Control and Implementation Control Block)
 *      - Chapter 5.3.10 (CPUID Base Register)
 *      - Chapter 5.3.13 (Coprocessor Access Control Register)
 *      - Chapter 5.3.35 (Vector Table Offset Register)
 *      - Chapter 5.4 (System timer, SysTick)
 *      - Chapter 5.5 (Cache maintenance operations)
 *      - Chapter 5.6.1 (Security Attribution Unit)
 *      - Chapter 5.6.2 (Memory Protection Unit)
 *      - Chapter 7 (Performance Monitoring Unit Extension support)
 *
 *   3. Arm® Cortex®-M55 Processor Technical Reference Manual
 *      - Chapter 4 (Processor Registers)
 *      - Chapter 4.6 (Exceptions)
 *      - Chapter 5.4 (CPUID, CPUID Base Register)
 *      - Chapter 6 (Initialization)
 *      - Chapter 17 (Performance Monitoring Unit Extension support)
 *
 *   4. Arm-Cortex-M55-Processor-Datasheet
 *      - Feature configuration
 *      - Memory map
 *
 * Note:
 *   This file depends on armv8m.h for architecture abstraction.
 *   本文件依赖于 armv8m.h 提供架构抽象层。
 *
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 ARM Architecture Team. All rights reserved.
 */

#ifndef __CORE_CM55_H_GENERIC
#define __CORE_CM55_H_GENERIC

#include "armv8m.h"
#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif

/*
 * ============================================================================
 * CMSIS Defines
 * CMSIS 定义
 *
 * This section provides Cortex-M55 specific configuration and identification.
 * These defines are used by CMSIS-compliant device drivers and provide
 * information about the processor core configuration.
 *
 * CMSIS (Cortex Microcontroller Software Interface Standard) provides:
 *   - Consistent software interface definitions
 *   - Processor identification
 *   - Device peripheral access
 *   - Debug access
 *
 * CMSIS（Cortex 微控制器软件接口标准）提供:
 *   - 一致的软件接口定义
 *   - 处理器识别
 *   - 设备外设访问
 *   - 调试访问
 *
 * Reference: Arm® Cortex™-M55 Devices Generic User Guide
 *           Chapter 3.1 (Programmer's model)
 *           Chapter 3.1.6 (The Cortex Microcontroller Software Interface Standard)
 * Reference: Arm® Cortex®-M55 Processor Technical Reference Manual
 *           Chapter 4 (Processor Registers)
 * 参考: Arm® Cortex™-M55 GUG
 *       第 3.1 章（程序员模型）
 *       第 3.1.6 章（Cortex 微控制器软件接口标准）
 *       Arm® Cortex®-M55 TRM
 *       第 4 章（处理器寄存器）
 * ============================================================================
 */

/**
 * __CM55_REV - Cortex-M55 Core Revision
 * Cortex-M55 核心版本
 *
 * This define specifies the revision of the Cortex-M55 processor core.
 * The revision number is encoded in the CPUID register (Bits [23:20]).
 *
 * Revision encoding / 版本编码:
 *   - r0p0: Major revision 0, Minor revision 0
 *   - r1p0: Major revision 1, Minor revision 0
 *   - etc.
 *
 * The revision can be read from the CPUID register at address 0xE000ED00.
 * 此定义指定 Cortex-M55 处理器核心的版本。
 * 版本号在 CPUID 寄存器的位 [23:20] 中编码。
 *
 * Reference: Arm® Cortex™-M55 Devices Generic User Guide
 *           Chapter 5.3.10 (CPUID Base Register)
 * Reference: Arm® Cortex®-M55 Processor Technical Reference Manual
 *           Chapter 5.4 (CPUID, CPUID Base Register)
 *           Chapter 5.2 (CPUID register summary)
 * 参考: Arm® Cortex™-M55 GUG
 *       第 5.3.10 章（CPUID 基址寄存器）
 *       Arm® Cortex®-M55 TRM
 *       第 5.4 章（CPUID，CPUID 基址寄存器）
 *       第 5.2 章（CPUID 寄存器摘要）
 */
#define __CM55_REV                 0x0001U

/*
 * ============================================================================
 * Interrupt Number Definition
 * 中断号定义
 *
 * This section defines the interrupt number enumeration for the Cortex-M55 processor.
 * Interrupt numbers are used to identify and configure exceptions and interrupts
 * in the NVIC (Nested Vectored Interrupt Controller).
 *
 * 本节定义 Cortex-M55 处理器的中断号枚举。
 * 中断号用于在 NVIC（嵌套向量中断控制器）中识别和配置异常和中断。
 *
 * Cortex-M55 Interrupt Features / Cortex-M55 中断特性:
 *   - Up to 480 interrupt requests (IRQ0-IRQ479)
 *     最多 480 个中断请求（IRQ0-IRQ479）
 *   - 16 configurable priority levels for external interrupts
 *     外部中断的 16 个可配置优先级级别
 *   - Optional target state configuration (Secure/Non-Secure) via NVIC_ITNS
 *     通过 NVIC_ITNS 可选目标状态配置（安全/非安全）
 *   - Integrated NVIC with wake-up interrupt controller support
 *     集成 NVIC，支持唤醒中断控制器
 *
 * Exception Model / 异常模型:
 *   - Exception numbers 1-15: System exceptions (处理器异常)
 *     These have fixed priority and cannot be configured by software.
 *     这些具有固定优先级，不能由软件配置。
 *
 *   - Exception number 0: No exception (无异常)
 *
 *   - Exception numbers 16-495: External interrupts (外部中断)
 *     IRQ0-IRQ479 are available on Cortex-M55 (depends on implementation)
 *     IRQ0-IRQ479 在 Cortex-M55 上可用（取决于实现）
 *
 * Priority Overview / 优先级概述:
 *   - Negative values: Higher priority than any external interrupt
 *     负值：比任何外部中断更高的优先级
 *   - IRQ0 has highest priority among external interrupts
 *     IRQ0 在外部中断中具有最高优先级
 *
 * TrustZone Notes / TrustZone 说明:
 *   - SecureFault_IRQn is only present when TrustZone is implemented
 *   - SecureFault_IRQn 仅在实现 TrustZone 时存在
 *   - NVIC_ITNS register controls target state (Secure/Non-Secure) for each IRQ
 *     NVIC_ITNS 寄存器控制每个 IRQ 的目标状态（安全/非安全）
 *
 * Reference: Arm® Cortex™-M55 Devices Generic User Guide
 *           Chapter 3.3.4 (Vector table)
 *           Chapter 5.2 (Nested Vectored Interrupt Controller)
 *           Chapter 5.2.6 (Interrupt Target Non-secure Registers)
 * Reference: Arm® Cortex®-M55 Processor Technical Reference Manual
 *           Chapter 4.6 (Exceptions)
 * 参考: Arm® Cortex™-M55 GUG
 *       第 3.3.4 章（向量表）
 *       第 5.2 章（嵌套向量中断控制器）
 *       第 5.2.6 章（中断目标非安全寄存器）
 *       Arm® Cortex®-M55 TRM
 *       第 4.6 章（异常）
 * ============================================================================
 */

/**
 * IRQn_Type - Interrupt Number Enumeration
 * IRQn_Type - 中断号枚举
 *
 * This enumeration defines all exception and interrupt numbers for the Cortex-M55.
 * The values correspond to the exception numbers used in the ARM architecture.
 *
 * Exception Number Assignment / 异常号分配:
 *   -14: NonMaskableInt (NMI) - 不可屏蔽中断
 *   -13: HardFault - 硬件故障
 *   -12: MemoryManagement - 内存管理
 *   -11: BusFault - 总线故障
 *   -10: UsageFault - 使用故障
 *    -9: SecureFault - 安全故障 (TrustZone only)
 *    -5: SVCall - 系统调用
 *    -4: DebugMonitor - 调试监控
 *    -2: PendSV - 挂起系统调用
 *    -1: SysTick - 系统滴答
 *     0+: IRQ0-IRQn - External interrupts (外部中断)
 *
 * Usage in NVIC functions / 在 NVIC 函数中的用法:
 *   NVIC_EnableIRQ(IRQ0_IRQn);  // Enable IRQ0
 *   NVIC_SetPriority(SysTick_IRQn, 0);  // Set SysTick priority
 *   NVIC_SetTargetState(IRQ5_IRQn);  // Set IRQ5 to Non-Secure target
 *
 * Note: Not all Cortex-M55 implementations support all interrupts.
 *       The actual number of interrupts depends on the chip implementation.
 *       Maximum supported is 480 interrupts (IRQ0-IRQ479).
 * 注意：并非所有 Cortex-M55 实现都支持所有中断。
 *       实际的中断数量取决于芯片实现。
 *       最大支持 480 个中断（IRQ0-IRQ479）。
 */
typedef enum {
    /* System Exceptions (negative values) / 系统异常（负值) */
    /* These have fixed priority and are handled before any external interrupt */
    /* 这些具有固定优先级，在任何外部中断之前处理 */
    NonMaskableInt_IRQn         = -14,  /*!< Non Maskable Interrupt / 不可屏蔽中断 */
                                          /* Highest priority exception after reset */
                                          /* 复位后最高优先级异常 */
    HardFault_IRQn              = -13,  /*!< Hard Fault Interrupt / 硬件故障中断 */
                                          /* Occurs on all fault exceptions */
                                          /* 所有故障异常发生时触发 */
    MemoryManagement_IRQn       = -12,  /*!< Memory Management Interrupt / 内存管理中断 */
                                          /* MPU violation or default memory map violation */
                                          /* MPU 违规或默认内存映射违规 */
    BusFault_IRQn               = -11,  /*!< Bus Fault Interrupt / 总线故障中断 */
                                          /* Prefetch abort or data abort on bus interface */
                                          /* 总线接口上的预取中止或数据中止 */
    UsageFault_IRQn             = -10,  /*!< Usage Fault Interrupt / 使用故障中断 */
                                          /* Undefined instruction, illegal state, etc. */
                                          /* 未定义指令、非法状态等 */
    SecureFault_IRQn            = -9,   /*!< Secure Fault Interrupt (TrustZone) / 安全故障中断 (TrustZone) */
                                          /* Only present when TrustZone Security Extension is implemented */
                                          /* 仅在实现 TrustZone 安全扩展时存在 */
    SVCall_IRQn                 = -5,   /*!< SV Call Interrupt / 系统调用中断 */
                                          /* Supervisor call via SVC instruction */
                                          /* 通过 SVC 指令进行主管调用 */
    DebugMonitor_IRQn           = -4,   /*!< Debug Monitor Interrupt / 调试监控中断 */
                                          /* Debug monitor exception */
                                          /* 调试监控异常 */
    PendSV_IRQn                 = -2,   /*!< Pend SV Interrupt / 挂起系统调用中断 */
                                          /* Request for system service */
                                          /* 系统服务请求 */
    SysTick_IRQn                = -1,   /*!< System Tick Interrupt / 系统滴答中断 */
                                          /* SysTick timer output */
                                          /* SysTick 定时器输出 */

    /* External Interrupts (positive values) / 外部中断（正值) */
    /* The actual number of available IRQs is implementation defined */
    /* 实际可用的 IRQ 数量由实现定义 */
    IRQ0_IRQn                   = 0,    /*!< External Interrupt 0 / 外部中断 0 */
                                          /* Highest priority external interrupt */
                                          /* 最高优先级外部中断 */
    IRQ1_IRQn                   = 1,    /*!< External Interrupt 1 / 外部中断 1 */
    IRQ2_IRQn                   = 2,    /*!< External Interrupt 2 / 外部中断 2 */
    IRQ3_IRQn                   = 3,    /*!< External Interrupt 3 / 外部中断 3 */
    IRQ4_IRQn                   = 4,    /*!< External Interrupt 4 / 外部中断 4 */
    IRQ5_IRQn                   = 5,    /*!< External Interrupt 5 / 外部中断 5 */
    IRQ6_IRQn                   = 6,    /*!< External Interrupt 6 / 外部中断 6 */
    IRQ7_IRQn                   = 7,    /*!< External Interrupt 7 / 外部中断 7 */
    IRQ8_IRQn                   = 8,    /*!< External Interrupt 8 / 外部中断 8 */
    IRQ9_IRQn                   = 9,    /*!< External Interrupt 9 / 外部中断 9 */
    IRQ10_IRQn                  = 10,   /*!< External Interrupt 10 / 外部中断 10 */
    IRQ11_IRQn                  = 11,  /*!< External Interrupt 11 / 外部中断 11 */
    IRQ12_IRQn                  = 12,  /*!< External Interrupt 12 / 外部中断 12 */
    IRQ13_IRQn                  = 13,  /*!< External Interrupt 13 / 外部中断 13 */
    IRQ14_IRQn                  = 14,  /*!< External Interrupt 14 / 外部中断 14 */
    IRQ15_IRQn                  = 15,  /*!< External Interrupt 15 / 外部中断 15 */
    IRQ16_IRQn                  = 16,  /*!< External Interrupt 16 / 外部中断 16 */
    IRQ17_IRQn                  = 17,  /*!< External Interrupt 17 / 外部中断 17 */
    IRQ18_IRQn                  = 18,
    IRQ19_IRQn                  = 19,
    IRQ20_IRQn                  = 20,
    IRQ21_IRQn                  = 21,
    IRQ22_IRQn                  = 22,
    IRQ23_IRQn                  = 23,
    IRQ24_IRQn                  = 24,
    IRQ25_IRQn                  = 25,
    IRQ26_IRQn                  = 26,
    IRQ27_IRQn                  = 27,
    IRQ28_IRQn                  = 28,
    IRQ29_IRQn                  = 29,
    IRQ30_IRQn                  = 30,
    IRQ31_IRQn                  = 31,
    IRQ32_IRQn                  = 32,
    IRQ33_IRQn                  = 33,
    IRQ34_IRQn                  = 34,
    IRQ35_IRQn                  = 35,
    IRQ36_IRQn                  = 36,
    IRQ37_IRQn                  = 37,
    IRQ38_IRQn                  = 38,
    IRQ39_IRQn                  = 39,
    IRQ40_IRQn                  = 40,
    IRQ41_IRQn                  = 41,
    IRQ42_IRQn                  = 42,
    IRQ43_IRQn                  = 43,
    IRQ44_IRQn                  = 44,
    IRQ45_IRQn                  = 45,
    IRQ46_IRQn                  = 46,
    IRQ47_IRQn                  = 47,
    IRQ48_IRQn                  = 48,
    IRQ49_IRQn                  = 49,
    IRQ50_IRQn                  = 50,
    IRQ51_IRQn                  = 51,
    IRQ52_IRQn                  = 52,
    IRQ53_IRQn                  = 53,
    IRQ54_IRQn                  = 54,
    IRQ55_IRQn                  = 55,
    IRQ56_IRQn                  = 56,
    IRQ57_IRQn                  = 57,
    IRQ58_IRQn                  = 58,
    IRQ59_IRQn                  = 59,
    IRQ60_IRQn                  = 60,
    IRQ61_IRQn                  = 61,
    IRQ62_IRQn                  = 62,
    IRQ63_IRQn                  = 63,
    IRQ64_IRQn                  = 64,
    IRQ65_IRQn                  = 65,
    IRQ66_IRQn                  = 66,
    IRQ67_IRQn                  = 67,
    IRQ68_IRQn                  = 68,
    IRQ69_IRQn                  = 69,
    IRQ70_IRQn                  = 70,
    IRQ71_IRQn                  = 71,
    IRQ72_IRQn                  = 72,
    IRQ73_IRQn                  = 73,
    IRQ74_IRQn                  = 74,
    IRQ75_IRQn                  = 75,
    IRQ76_IRQn                  = 76,
    IRQ77_IRQn                  = 77,
    IRQ78_IRQn                  = 78,
    IRQ79_IRQn                  = 79,
    IRQ80_IRQn                  = 80,
    IRQ81_IRQn                  = 81,
    IRQ82_IRQn                  = 82,
    IRQ83_IRQn                  = 83,
    IRQ84_IRQn                  = 84,
    IRQ85_IRQn                  = 85,
    IRQ86_IRQn                  = 86,
    IRQ87_IRQn                  = 87,
    IRQ88_IRQn                  = 88,
    IRQ89_IRQn                  = 89,
    IRQ90_IRQn                  = 90,
    IRQ91_IRQn                  = 91,
    IRQ92_IRQn                  = 92,
    IRQ93_IRQn                  = 93,
    IRQ94_IRQn                  = 94,
    IRQ95_IRQn                  = 95,
    IRQ96_IRQn                  = 96,
    IRQ97_IRQn                  = 97,
    IRQ98_IRQn                  = 98,
    IRQ99_IRQn                  = 99,
    IRQ100_IRQn                 = 100,
    IRQ101_IRQn                 = 101,
    IRQ102_IRQn                 = 102,
    IRQ103_IRQn                 = 103,
    IRQ104_IRQn                 = 104,
    IRQ105_IRQn                 = 105,
    IRQ106_IRQn                 = 106,
    IRQ107_IRQn                 = 107,
    IRQ108_IRQn                 = 108,
    IRQ109_IRQn                 = 109,
    IRQ110_IRQn                 = 110,
    IRQ111_IRQn                 = 111,
    IRQ112_IRQn                 = 112,
    IRQ113_IRQn                 = 113,
    IRQ114_IRQn                 = 114,
    IRQ115_IRQn                 = 115,
    IRQ116_IRQn                 = 116,
    IRQ117_IRQn                 = 117,
    IRQ118_IRQn                 = 118,
    IRQ119_IRQn                 = 119,
    IRQ120_IRQn                 = 120,
    IRQ121_IRQn                 = 121,
    IRQ122_IRQn                 = 122,
    IRQ123_IRQn                 = 123,
    IRQ124_IRQn                 = 124,
    IRQ125_IRQn                 = 125,
    IRQ126_IRQn                 = 126,
    IRQ127_IRQn                 = 127,
    IRQ128_IRQn                 = 128,
    IRQ129_IRQn                 = 129,
    IRQ130_IRQn                 = 130,
    IRQ131_IRQn                 = 131,
    IRQ132_IRQn                 = 132,
    IRQ133_IRQn                 = 133,
    IRQ134_IRQn                 = 134,
    IRQ135_IRQn                 = 135,
    IRQ136_IRQn                 = 136,
    IRQ137_IRQn                 = 137,
    IRQ138_IRQn                 = 138,
    IRQ139_IRQn                 = 139,
    IRQ140_IRQn                 = 140,
    IRQ141_IRQn                 = 141,
    IRQ142_IRQn                 = 142,
    IRQ143_IRQn                 = 143,
    IRQ144_IRQn                 = 144,
    IRQ145_IRQn                 = 145,
    IRQ146_IRQn                 = 146,
    IRQ147_IRQn                 = 147,
    IRQ148_IRQn                 = 148,
    IRQ149_IRQn                 = 149,
    IRQ150_IRQn                 = 150,
    IRQ151_IRQn                 = 151,
    IRQ152_IRQn                 = 152,
    IRQ153_IRQn                 = 153,
    IRQ154_IRQn                 = 154,
    IRQ155_IRQn                 = 155,
    IRQ156_IRQn                 = 156,
    IRQ157_IRQn                 = 157,
    IRQ158_IRQn                 = 158,
    IRQ159_IRQn                 = 159,
    IRQ160_IRQn                 = 160,
    IRQ161_IRQn                 = 161,
    IRQ162_IRQn                 = 162,
    IRQ163_IRQn                 = 163,
    IRQ164_IRQn                 = 164,
    IRQ165_IRQn                 = 165,
    IRQ166_IRQn                 = 166,
    IRQ167_IRQn                 = 167,
    IRQ168_IRQn                 = 168,
    IRQ169_IRQn                 = 169,
    IRQ170_IRQn                 = 170,
    IRQ171_IRQn                 = 171,
    IRQ172_IRQn                 = 172,
    IRQ173_IRQn                 = 173,
    IRQ174_IRQn                 = 174,
    IRQ175_IRQn                 = 175,
    IRQ176_IRQn                 = 176,
    IRQ177_IRQn                 = 177,
    IRQ178_IRQn                 = 178,
    IRQ179_IRQn                 = 179,
    IRQ180_IRQn                 = 180,
    IRQ181_IRQn                 = 181,
    IRQ182_IRQn                 = 182,
    IRQ183_IRQn                 = 183,
    IRQ184_IRQn                 = 184,
    IRQ185_IRQn                 = 185,
    IRQ186_IRQn                 = 186,
    IRQ187_IRQn                 = 187,
    IRQ188_IRQn                 = 188,
    IRQ189_IRQn                 = 189,
    IRQ190_IRQn                 = 190,
    IRQ191_IRQn                 = 191,
    IRQ192_IRQn                 = 192,
    IRQ193_IRQn                 = 193,
    IRQ194_IRQn                 = 194,
    IRQ195_IRQn                 = 195,
    IRQ196_IRQn                 = 196,
    IRQ197_IRQn                 = 197,
    IRQ198_IRQn                 = 198,
    IRQ199_IRQn                 = 199,
    IRQ200_IRQn                 = 200,
    IRQ201_IRQn                 = 201,
    IRQ202_IRQn                 = 202,
    IRQ203_IRQn                 = 203,
    IRQ204_IRQn                 = 204,
    IRQ205_IRQn                 = 205,
    IRQ206_IRQn                 = 206,
    IRQ207_IRQn                 = 207,
    IRQ208_IRQn                 = 208,
    IRQ209_IRQn                 = 209,
    IRQ210_IRQn                 = 210,
    IRQ211_IRQn                 = 211,
    IRQ212_IRQn                 = 212,
    IRQ213_IRQn                 = 213,
    IRQ214_IRQn                 = 214,
    IRQ215_IRQn                 = 215,
    IRQ216_IRQn                 = 216,
    IRQ217_IRQn                 = 217,
    IRQ218_IRQn                 = 218,
    IRQ219_IRQn                 = 219,
    IRQ220_IRQn                 = 220,
    IRQ221_IRQn                 = 221,
    IRQ222_IRQn                 = 222,
    IRQ223_IRQn                 = 223,
    IRQ224_IRQn                 = 224,
    IRQ225_IRQn                 = 225,
    IRQ226_IRQn                 = 226,
    IRQ227_IRQn                 = 227,
    IRQ228_IRQn                 = 228,
    IRQ229_IRQn                 = 229,
    IRQ230_IRQn                 = 230,
    IRQ231_IRQn                 = 231,
    IRQ232_IRQn                 = 232,
    IRQ233_IRQn                 = 233,
    IRQ234_IRQn                 = 234,
    IRQ235_IRQn                 = 235,
    IRQ236_IRQn                 = 236,
    IRQ237_IRQn                 = 237,
    IRQ238_IRQn                 = 238,
    IRQ239_IRQn                 = 239,
    IRQ240_IRQn                 = 240,
    IRQ241_IRQn                 = 241,
    IRQ242_IRQn                 = 242,
    IRQ243_IRQn                 = 243,
    IRQ244_IRQn                 = 244,
    IRQ245_IRQn                 = 245,
    IRQ246_IRQn                 = 246,
    IRQ247_IRQn                 = 247,
    IRQ248_IRQn                 = 248,
    IRQ249_IRQn                 = 249,
    IRQ250_IRQn                 = 250,
    IRQ251_IRQn                 = 251,
    IRQ252_IRQn                 = 252,
    IRQ253_IRQn                 = 253,
    IRQ254_IRQn                 = 254  /*!< External Interrupt 254 / 外部中断 254 */
                                        /*!< Maximum IRQ number defined in this header / 此头文件中定义的最大 IRQ 号 */
} IRQn_Type;

/**
 * Total number of IRQs defined in this header
 * 此头文件中定义的 IRQ 总数
 *
 * This constant represents the maximum number of interrupt requests (IRQs)
 * supported by this CMSIS device header.
 *
 * Note: The actual Cortex-M55 hardware may support up to 480 interrupts (IRQ0-IRQ479).
 *       This value is used for static allocation and should match the
 *       actual interrupt controller implementation.
 *       This implementation defines 255 IRQs (IRQ0-IRQ254) for a conservative default.
 *
 * 此常量表示此 CMSIS 设备头支持的中断请求 (IRQ) 的最大数量。
 *
 * 注意：实际的 Cortex-M55 硬件最多支持 480 个中断（IRQ0-IRQ479）。
 *       此值用于静态分配，应与实际的中断控制器实现匹配。
 *       此实现定义了 255 个 IRQ（IRQ0-IRQ254）作为保守默认值。
 *
 * Reference: Arm® Cortex™-M55 Devices Generic User Guide
 *            Chapter 4.3 (NVIC) - "up to 480 interrupts"
 * 参考: Arm® Cortex™-M55 GUG
 *       第 4.3 章 (NVIC) - "最多 480 个中断"
 */
#define __ARM_NUM_INTERRUPTS        255U

/*
 * ============================================================================
 * CMSIS-like Function Aliases
 * CMSIS 类函数别名
 *
 * These macros provide CMSIS-compatible function names that map to the
 * ARMv8-M architecture functions in armv8m.h.
 * 这些宏提供与 CMSIS 兼容的函数名，映射到 armv8m.h 中的 ARMv8-M 架构函数。
 *
 * Reference: Arm® Cortex™-M55 Devices Generic User Guide Chapter 4
 * 参考: Arm® Cortex™-M55 GUG 第 4 章
 * ============================================================================
 */

#define NVIC_SetPriorityGrouping      arch_armv8m_set_priority_grouping
#define NVIC_GetPriorityGrouping      arch_armv8m_get_priority_grouping
#define NVIC_EnableIRQ(irq)           arch_armv8m_enable_irq((uint8_t)(irq))
#define NVIC_GetEnableIRQ            arch_armv8m_get_enable_irq
#define NVIC_DisableIRQ(irq)          arch_armv8m_disable_irq((uint8_t)(irq))
#define NVIC_GetPendingIRQ           arch_armv8m_get_pending_irq
#define NVIC_SetPendingIRQ(irq)       arch_armv8m_set_pending((uint8_t)(irq))
#define NVIC_ClearPendingIRQ(irq)     arch_armv8m_clear_pending((uint8_t)(irq))
#define NVIC_GetActive               arch_armv8m_get_active_irq
#define NVIC_SetPriority(irq, prio)   arch_armv8m_set_priority((uint8_t)(irq), (uint8_t)(prio))
#define NVIC_GetPriority             arch_armv8m_get_priority
#define NVIC_EncodePriority          arch_armv8m_encode_priority
#define NVIC_DecodePriority          arch_armv8m_decode_priority
#define NVIC_SetVector               arch_armv8m_set_vector
#define NVIC_GetVector               arch_armv8m_get_vector
#define NVIC_SystemReset             arch_armv8m_system_reset

#define SysTick_Config               arch_armv8m_systick_config
#define SysTick_GetValue             arch_armv8m_systick_get_value
#define SysTick_SetReload            arch_armv8m_systick_set_reload
#define SysTick_GetReload            arch_armv8m_systick_get_reload
#define SysTick_EnableIRQ            arch_armv8m_systick_enable_irq
#define SysTick_DisableIRQ           arch_armv8m_systick_disable_irq
#define SysTick_Enable               arch_armv8m_systick_enable
#define SysTick_Disable              arch_armv8m_systick_disable
#define SysTick_GetCalib             arch_armv8m_systick_get_calib

#define FPU_Enable                   arch_armv8m_enable_fpu
#define FPU_Disable                  arch_armv8m_disable_fpu
#define SCB_GetFPUType               arch_armv8m_scb_get_fpu_type

#define MPU_GetType                  arch_armv8m_mpu_get_type
#define MPU_GetNumRegions            arch_armv8m_mpu_get_num_regions
#define MPU_SetMemoryAttribute       arch_armv8m_mpu_set_mem_attr
#define MPU_Enable                   arch_armv8m_mpu_enable
#define MPU_Disable                  arch_armv8m_mpu_disable
#define MPU_SetRegion                arch_armv8m_mpu_set_region
#define MPU_ClearRegion              arch_armv8m_mpu_clr_region
#define ARM_MPU_Enable               arch_armv8m_mpu_enable
#define ARM_MPU_Disable              arch_armv8m_mpu_disable
#define ARM_MPU_SetMemAttr           arch_armv8m_mpu_set_mem_attr
#define ARM_MPU_SetMemAttrEx         arch_armv8m_mpu_set_mem_attr_ex
#define ARM_MPU_SetRegion            arch_armv8m_mpu_set_region_ex
#define ARM_MPU_SetRegionEx          arch_armv8m_mpu_set_region_ex
#define ARM_MPU_ClrRegion            arch_armv8m_mpu_clr_region_ex
#define ARM_MPU_ClrRegionEx          arch_armv8m_mpu_clr_region_ex
#define ARM_MPU_Load                 arch_armv8m_mpu_load
#define ARM_MPU_LoadEx               arch_armv8m_mpu_load_ex
#define ARM_MPU_TYPE                 arch_armv8m_mpu_get_type
#define ARM_MPU_Enable_NS            arch_armv8m_mpu_enable_ns
#define ARM_MPU_Disable_NS           arch_armv8m_mpu_disable_ns
#define ARM_MPU_SetMemAttr_NS        arch_armv8m_mpu_set_mem_attr_ns
#define ARM_MPU_SetRegion_NS         arch_armv8m_mpu_set_region_ns
#define ARM_MPU_ClrRegion_NS         arch_armv8m_mpu_clr_region_ns
#define ARM_MPU_Load_NS              arch_armv8m_mpu_load_ns

#define SAU_Enable                   arch_armv8m_tz_sau_enable
#define SAU_Disable                  arch_armv8m_tz_sau_disable
#define SAU_SetRegion                arch_armv8m_tz_sau_set_region
#define SAU_GetType()                (SAU->TYPE)

#define SCB_GetCPUID()               (SCB->CPUID)
#define SCB_GetICSR()                (SCB->ICSR)
#define SCB_GetVTOR()                (SCB->VTOR)
#define SCB_SetVTOR(vtors)           (SCB->VTOR = (vtors))
#define SCB_GetSCR()                 (SCB->SCR)
#define SCB_SetSCR(scr)              (SCB->SCR = (scr))
#define SCB_GetCCR()                 (SCB->CCR)
#define SCB_GetCFSR()                (SCB->CFSR)
#define SCB_GetHFSR()                (SCB->HFSR)
#define SCB_GetMMFAR()               (SCB->MMFAR)
#define SCB_GetBFAR()                (SCB->BFAR)
#define SCB_GetSHCSR()               (SCB->SHCSR)
#define SCB_GetCPACR()               (SCB->CPACR)
#define SCB_SetCPACR(cpacr)          (SCB->CPACR = (cpacr))

#define ITM_SendChar                 arch_armv8m_itm_send_char
#define ITM_ReceiveChar              arch_armv8m_itm_receive_char
#define ITM_CheckChar                arch_armv8m_itm_check_char
#define ITM_Enable                   arch_armv8m_itm_enable

/*
 * ============================================================================
 * Cache Maintenance Function Aliases
 * Cache 维护函数别名
 * ============================================================================
 */

#define SCB_InvalidateICache        arch_armv8m_icache_invalidate_all
#define SCB_InvalidateICache_by_Addr(addr) arch_armv8m_icache_invalidate_mva((uint32_t)(addr))
#define SCB_InvalidateDCache_by_Addr(addr) arch_armv8m_dcache_invalidate_mva((uint32_t)(addr))
#define SCB_InvalidateDCache_by_Sw(sw) arch_armv8m_dcache_invalidate_sw(sw)
#define SCB_CleanDCache_by_Addr(addr) arch_armv8m_dcache_clean_mva((uint32_t)(addr))
#define SCB_CleanDCache_by_Addr_poc(addr) arch_armv8m_dcache_clean_mva_poc((uint32_t)(addr))
#define SCB_CleanDCache_by_Sw(sw) arch_armv8m_dcache_clean_sw(sw)
#define SCB_CleanInvalidateDCache_by_Addr(addr) arch_armv8m_dcache_clean_invalidate_mva((uint32_t)(addr))
#define SCB_CleanInvalidateDCache_by_Sw(sw) arch_armv8m_dcache_clean_invalidate_sw(sw)

/*
 * ============================================================================
 * TrustZone NVIC Non-Secure Function Aliases
 * TrustZone NVIC 非安全函数别名
 * ============================================================================
 */

#define NVIC_SetPriorityGrouping_NS arch_armv8m_tz_nvic_set_priority_grouping_ns
#define NVIC_GetPriorityGrouping_NS arch_armv8m_tz_nvic_get_priority_grouping_ns
#define NVIC_EnableIRQ_NS           arch_armv8m_tz_nvic_enable_irq_ns
#define NVIC_DisableIRQ_NS          arch_armv8m_tz_nvic_disable_irq_ns
#define NVIC_SetPendingIRQ_NS       arch_armv8m_tz_nvic_set_pending_ns
#define NVIC_ClearPendingIRQ_NS     arch_armv8m_tz_nvic_clear_pending_ns
#define NVIC_GetPendingIRQ_NS       arch_armv8m_tz_nvic_get_pending_ns
#define NVIC_GetActive_NS           arch_armv8m_tz_nvic_get_active_ns
#define NVIC_SetPriority_NS         arch_armv8m_tz_nvic_set_priority_ns
#define NVIC_GetPriority_NS         arch_armv8m_tz_nvic_get_priority_ns

/*
 * ============================================================================
 * PMU Functions
 * PMU 函数
 *
 * Reference: Arm® Cortex™-M55 Devices Generic User Guide
 *           Chapter 7 (Performance Monitoring Unit Extension support)
 * Reference: Arm® Cortex®-M55 Processor Technical Reference Manual
 *           Chapter 17 (Performance Monitoring Unit Extension support)
 * 参考: Arm® Cortex™-M55 GUG
 *       第 7 章（性能监控单元扩展支持）
 *       Arm® Cortex®-M55 TRM
 *       第 17 章（性能监控单元扩展支持）
 * ============================================================================
 */

#define PMU_Enable                   arch_armv8m_pmu_enable
#define PMU_Disable                  arch_armv8m_pmu_disable
#define PMU_ResetCycleCounter        arch_armv8m_pmu_cyccnt_reset
#define PMU_ResetEventCounters      arch_armv8m_pmu_evcntr_all_reset
#define PMU_EnableCounter            arch_armv8m_pmu_cntr_enable
#define PMU_DisableCounter           arch_armv8m_pmu_cntr_disable
#define PMU_GetCycleCount            arch_armv8m_pmu_get_ccntr
#define PMU_GetEventCounter          arch_armv8m_pmu_get_evcntr
#define PMU_SetEventType             arch_armv8m_pmu_set_evtyper
#define PMU_GetOverflowStatus        arch_armv8m_pmu_get_cntr_ovs
#define PMU_EnableOverflowIRQ        arch_armv8m_pmu_set_cntr_irq_enable
#define PMU_DisableOverflowIRQ       arch_armv8m_pmu_set_cntr_irq_disable

/*
 * ============================================================================
 * Cortex-M55 Specific Additional Functions
 * Cortex-M55 特定附加函数
 *
 * These functions are specific to Cortex-M55 and are not in armv8m.h
 * 这些函数是 Cortex-M55 特有的，不在 armv8m.h 中
 * ============================================================================
 */

/**
 * @brief Initialize Cortex-M55 core
 * @brief 初始化 Cortex-M55 核心
 *
 * This function performs the complete initialization sequence for the Cortex-M55 processor core.
 * It enables the core features required for operation and ensures proper synchronization.
 * 本函数执行 Cortex-M55 处理器核心的完整初始化序列。
 *
 * Initialization steps include / 初始化步骤包括:
 *   1. FPU Enable (浮点单元使能):
 *      - The FPU is disabled by default after reset
 *      - Enabling FPU allows the processor to execute floating-point instructions
 *      - CPACR register (Coprocessor Access Control) is configured to grant full access
 *        to CP10 and CP11 (Floating-point registers)
 *      - FPU 在复位后默认禁用
 *      - 使能 FPU 允许处理器执行浮点指令
 *      - 配置 CPACR 寄存器（协处理器访问控制）以授予对 CP10 和 CP11 的完全访问权限
 *
 *   2. MPU Initialization (MPU 初始化):
 *      - The MPU is disabled during configuration
 *      - MPU regions can be configured after initialization
 *      - MPU 在配置期间被禁用
 *      - 可以在初始化后配置 MPU 区域
 *
 *   3. Memory Barriers (内存屏障):
 *      - DSB (Data Synchronization Barrier) ensures all stores complete
 *      - ISB (Instruction Synchronization Barrier) flushes the instruction pipeline
 *      - These barriers ensure proper synchronization of configuration changes
 *      - DSB（数据同步屏障）确保所有存储完成
 *      - ISB（指令同步屏障）刷新指令流水线
 *      - 这些屏障确保配置更改的正确同步
 *
 * Note / 注意:
 *   - This function delegates to arch_armv8m_init() which provides
 *     architecture-generic initialization for ARMv8-M based processors.
 *   - Cortex-M55 also supports Helium (MVE) which requires additional configuration
 *     if the MVE feature is present
 *   - 此函数委托给 arch_armv8m_init()，它为基于 ARMv8-M 的处理器提供架构通用初始化
 *   - Cortex-M55 还支持 Helium (MVE)，如果存在 MVE 功能，则需要额外配置
 *
 * Usage example / 使用示例:
 *   @code
 *   // Early in startup code / 在启动代码早期调用
 *   Core_Init();
 *
 *   // Now configure MPU regions / 现在配置 MPU 区域
 *   MPU_SetRegion(...);
 *   MPU_Enable(...);
 *   @endcode
 *
 * Reference: Arm® Cortex™-M55 Devices Generic User Guide
 *           Chapter 5.3 (System Control and Implementation Control Block)
 *           Chapter 5.3.13 (Coprocessor Access Control Register)
 *           Chapter 5.6.1 (Security Attribution Unit)
 *           Chapter 5.6.2 (Memory Protection Unit)
 * Reference: Arm® Cortex®-M55 Processor Technical Reference Manual
 *           Chapter 6 (Initialization)
 * 参考: Arm® Cortex™-M55 GUG
 *       第 5.3 章（系统控制和实现控制块）
 *       第 5.3.13 章（协处理器访问控制寄存器）
 *       第 5.6.1 章（安全属性单元）
 *       第 5.6.2 章（内存保护单元）
 *       Arm® Cortex®-M55 TRM
 *       第 6 章（初始化）
 */
void Core_Init(void);

/**
 * @brief Setup vector table for Cortex-M55
 * @brief 为 Cortex-M55 设置向量表
 *
 * This function configures the vector table offset register (VTOR) to point to
 * the application's vector table location.
 * 此函数配置向量表偏移寄存器 (VTOR) 以指向应用程序的向量表位置。
 *
 * Vector Table Overview / 向量表概述:
 *   - The vector table contains the initial stack pointer value
 *     and the reset handler address, followed by all exception handlers
 *   - 向量表包含初始栈指针值和复位处理程序地址，然后是所有异常处理程序
 *
 *   - Exception numbers 1-15 (System exceptions):
 *     1: Reset
 *     2: NMI
 *     3: HardFault
 *     4: MemManage
 *     5: BusFault
 *     6: UsageFault
 *     7: Reserved
 *     8: Reserved
 *     9: Reserved
 *     10: Reserved
 *     11: SVCall
 *     12: Debug Monitor
 *     13: Reserved
 *     14: PendSV
 *     15: SysTick
 *   - Exception numbers 16+ (External interrupts IRQ0-IRQn):
 *     Configurable based on chip implementation
 *     可根据芯片实现配置
 *
 * VTOR Register Details / VTOR 寄存器详情:
 *   - Base address: 0xE000ED08
 *   - Bits [31:7]: Vector table base address (aligned to 128 words / 512 bytes)
 *   - Bits [6:0]: Reserved
 *   - When TrustZone is present, bit[7] indicates secure/non-secure vector table
 *   - Cortex-M55 has both Secure and Non-Secure vector tables
 *   - 基地址: 0xE000ED08
 *   - 位 [31:7]: 向量表基地址（对齐到 128 个字 / 512 字节）
 *   - 位 [6:0]: 保留
 *   - 当存在 TrustZone 时，位[7] 指示安全/非安全向量表
 *   - Cortex-M55 同时具有安全和非安全向量表
 *
 * Cortex-M55 Specific / Cortex-M55 特定:
 *   - VTOR_S (Secure Vector Table Offset Register) at 0xE000ED08
 *   - VTOR_NS (Non-Secure Vector Table Offset Register) at 0xE002ED08
 *   - Secure and Non-Secure states have separate vector tables
 *   - 安全和非安全状态具有独立的向量表
 *
 * Note / 注意:
 *   - The vector table must be aligned to 128 words (512 bytes) minimum
 *   - This alignment is required for proper exception handling
 *   - The alignment ensures that bit[7] can be used for TrustZone selection
 *   - 向量表必须至少对齐到 128 个字（512 字节）
 *   - 此对齐是正确异常处理所必需的
 *   - 该对齐确保位[7] 可用于 TrustZone 选择
 *
 * Reference: Arm® Cortex™-M55 Devices Generic User Guide
 *           Chapter 5.3.35 (Vector Table Offset Register)
 *           Chapter 3.3.4 (Vector table)
 * 参考: Arm® Cortex™-M55 GUG
 *       第 5.3.35 章（向量表偏移寄存器）
 *       第 3.3.4 章（向量表）
 */
void Core_SetupVectorTable(void);

/**
 * @brief Get NVIC interrupt target state
 * @brief 获取 NVIC 中断目标状态
 *
 * This function reads the NVIC_ITNS register to determine the target Security
 * state (Secure or Non-Secure) for a specific interrupt.
 * 此函数读取 NVIC_ITNS 寄存器以确定特定中断的目标安全状态（安全或非安全）。
 *
 * @param IRQn: Interrupt number (0-479)
 * @param IRQn: 中断号 (0-479)
 * @return Target state:
 *         - 0 = Secure target
 *         - 1 = Non-Secure target
 * @return 目标状态:
 *         - 0 = 安全目标
 *         - 1 = 非安全目标
 *
 * Example / 示例:
 *   @code
 *   uint32_t state = NVIC_GetTargetState(IRQ5_IRQn);
 *   if (state == 0) {
 *       // IRQ5 targets Secure state
 *   } else {
 *       // IRQ5 targets Non-Secure state
 *   }
 *   @endcode
 *
 * Note / 注意:
 *   - For system exceptions (IRQn < 0), this function returns 0 (Secure)
 *   - 对于系统异常（IRQn < 0），此函数返回 0（安全）
 *
 * Reference: Arm® Cortex™-M55 Devices Generic User Guide
 *           Chapter 5.2.6 (Interrupt Target Non-secure Registers)
 * 参考: Arm® Cortex™-M55 GUG
 *       第 5.2.6 章（中断目标非安全寄存器）
 */
uint32_t NVIC_GetTargetState(IRQn_Type IRQn);

/**
 * @brief Set NVIC interrupt target state to Non-Secure
 * @brief 将 NVIC 中断目标状态设置为非安全
 *
 * This function configures a specific interrupt to target the Non-Secure state.
 * 此函数将特定的中断配置为以非安全状态为目标。
 *
 * @param IRQn: Interrupt number (0-479)
 * @param IRQn: 中断号 (0-479)
 * @return Success status:
 *         - 1 = Success
 *         - 0 = Failure (for system exceptions)
 * @return 成功状态:
 *         - 1 = 成功
 *         - 0 = 失败（对于系统异常）
 *
 * Example / 示例:
 *   @code
 *   // Configure IRQ5 to target Non-Secure state
 *   NVIC_SetTargetState(IRQ5_IRQn);
 *
 *   // Now IRQ5 will be handled by Non-Secure handlers
 *   // 现在 IRQ5 将由非安全处理程序处理
 *   @endcode
 *
 * Precondition / 前置条件:
 *   - This function must be called from Secure state
 *   - 此函数必须从安全状态调用
 *
 * Note / 注意:
 *   - For system exceptions (IRQn < 0), this function returns 0 (cannot configure)
 *   - 对于系统异常（IRQn < 0），此函数返回 0（无法配置）
 *
 * Reference: Arm® Cortex™-M55 Devices Generic User Guide
 *           Chapter 5.2.6 (Interrupt Target Non-secure Registers)
 * 参考: Arm® Cortex™-M55 GUG
 *       第 5.2.6 章（中断目标非安全寄存器）
 */
uint32_t NVIC_SetTargetState(IRQn_Type IRQn);

/**
 * @brief Clear NVIC interrupt target state to Secure
 * @brief 清除 NVIC 中断目标状态设置为安全
 *
 * This function configures a specific interrupt to target the Secure state.
 * 此函数将特定的中断配置为以安全状态为目标。
 *
 * @param IRQn: Interrupt number (0-479)
 * @param IRQn: 中断号 (0-479)
 * @return Success status:
 *         - 1 = Success
 *         - 0 = Failure (for system exceptions)
 * @return 成功状态:
 *         - 1 = 成功
 *         - 0 = 失败（对于系统异常）
 *
 * Example / 示例:
 *   @code
 *   // Configure IRQ5 to target Secure state
 *   NVIC_ClearTargetState(IRQ5_IRQn);
 *
 *   // Now IRQ5 will be handled by Secure handlers
 *   // 现在 IRQ5 将由安全处理程序处理
 *   @endcode
 *
 * Precondition / 前置条件:
 *   - This function must be called from Secure state
 *   - 此函数必须从安全状态调用
 *
 * Note / 注意:
 *   - For system exceptions (IRQn < 0), this function returns 0 (cannot configure)
 *   - 对于系统异常（IRQn < 0），此函数返回 0（无法配置）
 *
 * Reference: Arm® Cortex™-M55 Devices Generic User Guide
 *           Chapter 5.2.6 (Interrupt Target Non-secure Registers)
 * 参考: Arm® Cortex™-M55 GUG
 *       第 5.2.6 章（中断目标非安全寄存器）
 */
uint32_t NVIC_ClearTargetState(IRQn_Type IRQn);

#ifdef __cplusplus
}
#endif

#endif
