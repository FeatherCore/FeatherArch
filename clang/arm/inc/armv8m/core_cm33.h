/*
 * ARM Cortex-M33 Core Peripheral Access Layer
 * ARM Cortex-M33 核心外设访问层
 *
 * ============================================================================
 * File: core_cm33.h
 * Description: ARM Cortex-M33 core peripheral access layer definitions
 * 描述: ARM Cortex-M33 核心外设访问层定义
 *
 * This file defines all NVIC, SysTick, SCB, FPU, MPU, TrustZone functions for ARM Cortex-M33.
 * 本文件定义了 ARM Cortex-M33 的所有 NVIC、SysTick、SCB、FPU、MPU、TrustZone 函数。
 *
 * Dependency Hierarchy / 依赖层次:
 *   core_cm33.h → armv8m.h (includes all common inline functions)
 *   (Cortex-M33 specific) (ARMv8-M architecture abstraction layer)
 *
 * Reference Documents / 参考文档:
 *   1. Arm® Cortex™-M33 Devices Generic User Guide (Document ID: 100235)
 *      - Chapter 2: The Cortex®-M33 Processor
 *      - Chapter 4: The Cortex®-M33 Peripherals
 *      - Chapter 4.2: System Control Block (SCB)
 *      - Chapter 4.3: System timer, SysTick
 *      - Chapter 4.4: Nested Vectored Interrupt Controller (NVIC)
 *      - Chapter 4.5: Security Attribution and Memory Protection
 *      - Chapter 4.6: Floating-Point Unit (FPU)
 *
 *   2. Arm® Cortex®-M33 Processor Technical Reference Manual (Document ID: 100230)
 *      - Chapter 1: Introduction
 *      - Chapter 2: Programmers Model
 *      - Chapter 3: System Control
 *      - Chapter 4: Security Attribution and Memory Protection
 *      - Chapter 5: Nested Vectored Interrupt Controller
 *      - Chapter 6: Floating-Point Unit
 *      - Chapter 11: Data Watchpoint and Trace Unit
 *
 *   3. Arm-Cortex-M33-Processor-Datasheet-V2
 *      - Feature configuration options
 *      - Processor block diagram
 *      - Power, Performance and Area
 *
 * Note:
 *   This file depends on armv8m.h for architecture abstraction.
 *   本文件依赖于 armv8m.h 提供架构抽象层。
 *   All common inline functions are now defined in armv8m.h to avoid duplication.
 *   所有通用内联函数现在都在 armv8m.h 中定义以避免重复。
 *
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 ARM Architecture Team. All rights reserved.
 */

#ifndef __CORE_CM33_H_GENERIC
#define __CORE_CM33_H_GENERIC

#include "armv8m.h"
#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif

/*
 * ============================================================================
 * CMSIS Defines
 * CMSIS 定义
 * ============================================================================
 */

/*
 * ============================================================================
 * Cortex-M33 Core Revision and CPUID
 * Cortex-M33 核心版本和 CPUID
 * Reference: Arm® Cortex®-M33 TRM Chapter 4.2 (CPUID)
 * 参考: Arm® Cortex®-M33 TRM 第 4.2 章 (CPUID)
 * ============================================================================
 */

/**
 * Cortex-M33 Core Revision
 * Cortex-M33 核心版本
 * r1p0: 0x0001
 */
#define __CM33_REV                 0x0001U

/**
 * Cortex-M33 CPUID Base Register Reset Value
 * Cortex-M33 CPUID 基址寄存器复位值
 * Reference: Arm® Cortex®-M33 TRM Section 1.9 (Product Revisions)
 * 参考: Arm® Cortex®-M33 TRM 第 1.9 节 (产品修订)
 * CPUID = 0x411FD210 for r1p0
 */
#define __CM33_CPUID               0x411FD210U

/*
 * ============================================================================
 * Interrupt Number Definition
 * 中断号定义
 * Reference: Arm® Cortex™-M33 Devices Generic User Guide Chapter 4.4 (NVIC)
 * 参考: Arm® Cortex™-M33 GUG 第 4.4 章 (NVIC)
 * ============================================================================
 */

typedef enum {
    NonMaskableInt_IRQn         = -14,  /*!< Non Maskable Interrupt / 不可屏蔽中断 */
    HardFault_IRQn              = -13,  /*!< Hard Fault Interrupt / 硬件故障中断 */
    MemoryManagement_IRQn       = -12,  /*!< Memory Management Interrupt / 内存管理中断 */
    BusFault_IRQn               = -11,  /*!< Bus Fault Interrupt / 总线故障中断 */
    UsageFault_IRQn             = -10,  /*!< Usage Fault Interrupt / 使用故障中断 */
    SecureFault_IRQn            = -9,   /*!< Secure Fault Interrupt (TrustZone) / 安全故障中断 (TrustZone) */
    SVCall_IRQn                 = -5,   /*!< SV Call Interrupt / 系统调用中断 */
    DebugMonitor_IRQn           = -4,   /*!< Debug Monitor Interrupt / 调试监控中断 */
    PendSV_IRQn                 = -2,   /*!< Pend SV Interrupt / 挂起系统调用中断 */
    SysTick_IRQn                = -1,   /*!< System Tick Interrupt / 系统滴答中断 */
    IRQ0_IRQn                   = 0,    /*!< External Interrupt 0 / 外部中断 0 */
    IRQ1_IRQn                   = 1,
    IRQ2_IRQn                   = 2,
    IRQ3_IRQn                   = 3,
    IRQ4_IRQn                   = 4,
    IRQ5_IRQn                   = 5,
    IRQ6_IRQn                   = 6,
    IRQ7_IRQn                   = 7,
    IRQ8_IRQn                   = 8,
    IRQ9_IRQn                   = 9,
    IRQ10_IRQn                  = 10,
    IRQ11_IRQn                  = 11,
    IRQ12_IRQn                  = 12,
    IRQ13_IRQn                  = 13,
    IRQ14_IRQn                  = 14,
    IRQ15_IRQn                  = 15,
    IRQ16_IRQn                  = 16,
    IRQ17_IRQn                  = 17,
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
    IRQ254_IRQn                 = 254
} IRQn_Type;

/*
 * ============================================================================
 * CMSIS-like Function Aliases
 * CMSIS 类函数别名
 *
 * These macros provide CMSIS-compatible function names that map to the
 * ARMv8-M architecture functions in armv8m.h.
 * 这些宏提供与 CMSIS 兼容的函数名，映射到 armv8m.h 中的 ARMv8-M 架构函数。
 *
 * Reference: Arm® Cortex™-M33 Devices Generic User Guide Chapter 4
 * 参考: Arm® Cortex™-M33 GUG 第 4 章
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
 * Cortex-M33 Specific Additional Functions
 * Cortex-M33 特定附加函数
 *
 * These functions are specific to Cortex-M33 and are not in armv8m.h
 * 这些函数是 Cortex-M33 特有的，不在 armv8m.h 中
 * ============================================================================
 */

/**
 * @brief Initialize Cortex-M33 core
 * @brief 初始化 Cortex-M33 核心
 *
 * Reference: Arm® Cortex™-M33 Devices Generic User Guide Chapter 4
 * 参考: Arm® Cortex™-M33 GUG 第 4 章
 */
void Core_Init(void);

/**
 * @brief Setup vector table for Cortex-M33
 * @brief 为 Cortex-M33 设置向量表
 *
 * Reference: Arm® Cortex™-M33 Devices Generic User Guide Chapter 4.2.18 (VTOR)
 * 参考: Arm® Cortex™-M33 GUG 第 4.2.18 章 (VTOR)
 */
void Core_SetupVectorTable(void);

#ifdef __cplusplus
}
#endif

#endif
