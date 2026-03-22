/*
 * ARM Architecture - ARMv8-M (Cortex-M23/M33/M55/M85) Support
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
 *   1. ARMv8-M Architecture Reference Manual (ARM DDI 0553B)
 *      - Chapter B1: Processor Memory Model (B1.1-B1.5)
 *      - Chapter B2: Programmer's Model (B2.1-B2.9)
 *      - Chapter B3: System Control Registers (B3.1-B3.5)
 *      - Chapter B4: Memory Protection Unit (B4.1-B4.5)
 *      - Chapter B5: Security Attribution Unit (B5.1-B5.5)
 *      - Chapter B6: Debug and Trace (B6.1-B6.5)
 *
 *   2. ARM Cortex-M33 Devices Generic User Guide (DUI 0552A)
 *      - Chapter 4.2: System Control Block (SCB) registers
 *      - Chapter 4.3: Nested Vectored Interrupt Controller (NVIC)
 *      - Chapter 4.4: System Timer (SysTick)
 *      - Chapter 4.5: Memory Protection Unit (MPU)
 *      - Chapter 6: Security Attribution Unit (SAU)
 *      - Chapter 7: Instrumentation Trace Macrocell (ITM)
 *
 *   3. ARM Cortex-M33 Processor Technical Reference Manual (ARM DDI 0550A)
 *      - Chapter 4: Processor Registers
 *      - Chapter 11: Performance Monitor Unit (PMU)
 *
 *   4. ARM Cortex-M33 Processor Datasheet (V2)
 *      - Feature configuration
 *      - Memory map
 *      - Timing specifications
 *
 * ARMv8-M Architecture Overview:
 *   ARMv8-M is ARM's latest microcontroller architecture, divided into two branches:
 *   ARMv8-M 是 ARM 最新的微控制器架构，分为两个分支:
 *     - ARMv8-M Baseline: Similar to ARMv6-M extension
 *       ARMv8-M Baseline: 类似于 ARMv6-M 的扩展
 *     - ARMv8-M Mainline: Complete ARMv8-M implementation with TrustZone security
 *       ARMv8-M Mainline: 完整的 ARMv8-M 实现，支持 TrustZone 安全扩展
 *
 * Supported Processors:
 *   - Cortex-M23: ARMv8-M Baseline, ultra-low cost security MCU
 *   - Cortex-M33: ARMv8-M Mainline, mainstream security MCU
 *   - Cortex-M35P: Security MCU with physical security features
 *   - Cortex-M55: First MCU with Helium DSP extension
 *   - Cortex-M85: Latest high-performance MCU with Helium and TrustZone
 *
 * Key Features:
 *   - TrustZone Security Extension (Mainline) - ARMv8-M ARM Section B5
 *   - MPU Memory Protection Unit - ARMv8-M ARM Section B4
 *   - Optional FPU (single/double precision) - ARMv8-M ARM Section B3.2
 *   - DSP instruction extension
 *   - Helium SIMD extension (M55, M85)
 *   - PMU Performance Monitor Unit (M55, M85) - ARMv8-M ARM Section B6.3
 *   - Enhanced Interrupt Controller - ARMv8-M ARM Section B3.3
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
 * PMU Present: 1 = PMU is present (Cortex-M55/M85)
 * PMU 存在: 1 = PMU 存在 (Cortex-M55/M85)
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
 * DSP Extension Present: 1 = DSP extension is present (M55/M85)
 * DSP 扩展存在: 1 = DSP 扩展存在 (M55/M85)
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
 * Reference: ARMv8-M ARM Section B2.2 (Special Registers)
 *            ARM Cortex-M33 GUG Chapter 4.2 (System Control Block)
 * 参考: ARMv8-M ARM 第 B2.2 节 (特殊寄存器)
 *       ARM Cortex-M33 GUG 第 4.2 章 (系统控制块)
 * ============================================================================
 */

/**
 * CONTROL register bit definitions
 * CONTROL 寄存器位定义
 * Reference: ARMv8-M ARM B2.2.4 / ARM Cortex-M33 GUG 4.2.8
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
 * PRIMASK register bit definitions
 * PRIMASK 寄存器位定义
 * Reference: ARMv8-M ARM B2.2.6 / ARM Cortex-M33 GUG 4.2.10
 */
#define PRIMASK_Pos                0U
#define PRIMASK_Msk              (1UL << PRIMASK_Pos)

/**
 * FAULTMASK register bit definitions
 * FAULTMASK 寄存器位定义
 * Reference: ARMv8-M ARM B2.2.8 / ARM Cortex-M33 GUG 4.2.11
 */
#define FAULTMASK_Pos             0U
#define FAULTMASK_Msk            (1UL << FAULTMASK_Pos)

/**
 * BASEPRI register bit definitions
 * BASEPRI 寄存器位定义
 * Reference: ARMv8-M ARM B2.2.7 / ARM Cortex-M33 GUG 4.2.9
 */
#define BASEPRI_Pos               0U
#define BASEPRI_Msk              (0xFFUL << BASEPRI_Pos)

/**
 * xPSR register bit definitions
 * xPSR 寄存器位定义
 * Reference: ARMv8-M ARM B2.3 / ARM Cortex-M33 GUG 4.2.5
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

/*
 * ============================================================================
 * ARMv8-M NVIC Register Bit Definitions
 * ARMv8-M NVIC 寄存器位定义
 *
 * Reference: ARMv8-M ARM Section B3.3 (Nested Vectored Interrupt Controller)
 *            ARM Cortex-M33 GUG Chapter 4.3
 * 参考: ARMv8-M ARM 第 B3.3 节 (嵌套向量中断控制器)
 *       ARM Cortex-M33 GUG 第 4.3 章
 * ============================================================================
 */

/**
 * SCB_AIRCR register bit definitions
 * SCB_AIRCR 寄存器位定义
 * Reference: ARMv8-M ARM B3.3.1 / ARM Cortex-M33 GUG 4.3.1
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
 * SCB_SCR register bit definitions
 * SCB_SCR 寄存器位定义
 * Reference: ARMv8-M ARM B3.2.6 / ARM Cortex-M33 GUG 4.2.11
 */
#define SCB_SCR_SLEEPONEXIT_Pos         1U
#define SCB_SCR_SLEEPONEXIT_Msk        (1UL << SCB_SCR_SLEEPONEXIT_Pos)
#define SCB_SCR_SLEEPDEEP_Pos           2U
#define SCB_SCR_SLEEPDEEP_Msk          (1UL << SCB_SCR_SLEEPDEEP_Pos)
#define SCB_SCR_SEVONPEND_Pos           4U
#define SCB_SCR_SEVONPEND_Msk          (1UL << SCB_SCR_SEVONPEND_Pos)

/**
 * SCB_CCR register bit definitions
 * SCB_CCR 寄存器位定义
 * Reference: ARMv8-M ARM B3.2.7 / ARM Cortex-M33 GUG 4.2.12
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
 * SysTick Control and Status Register bits
 * SysTick 控制和状态寄存器位
 * Reference: ARMv8-M ARM B3.4.1 / ARM Cortex-M33 GUG 4.4.1
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
 * SysTick Calibration Register bits
 * SysTick 校准寄存器位
 * Reference: ARMv8-M ARM B3.4.4 / ARM Cortex-M33 GUG 4.4.4
 */
#define SYSTICK_CALIB_NOREF_Pos         31U
#define SYSTICK_CALIB_NOREF_Msk        (1UL << SYSTICK_CALIB_NOREF_Pos)
#define SYSTICK_CALIB_SKEW_Pos          30U
#define SYSTICK_CALIB_SKEW_Msk         (1UL << SYSTICK_CALIB_SKEW_Pos)
#define SYSTICK_CALIB_TENMS_Pos          0U
#define SYSTICK_CALIB_TENMS_Msk        (0xFFFFFFUL << SYSTICK_CALIB_TENMS_Pos)

/**
 * MPU Control Register bits
 * MPU 控制寄存器位
 * Reference: ARMv8-M ARM B4.3.2 / ARM Cortex-M33 GUG 4.5.2
 */
#define MPU_CTRL_ENABLE_Pos              0U
#define MPU_CTRL_ENABLE_Msk             (1UL << MPU_CTRL_ENABLE_Pos)
#define MPU_CTRL_HFNMIENA_Pos           1U
#define MPU_CTRL_HFNMIENA_Msk           (1UL << MPU_CTRL_HFNMIENA_Pos)
#define MPU_CTRL_PRIVDEFENA_Pos         2U
#define MPU_CTRL_PRIVDEFENA_Msk         (1UL << MPU_CTRL_PRIVDEFENA_Pos)

/**
 * MPU Region Attribute and Size Register bits
 * MPU 区域属性和大小寄存器位
 * Reference: ARMv8-M ARM B4.3.4-4.3.5 / ARM Cortex-M33 GUG 4.5.3-4.5.5
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
 * MPU Memory Attribute Indirection Register definitions
 * MPU 内存属性间接寄存器定义
 * Reference: ARMv8-M ARM B4.3.7-4.3.8 / ARM Cortex-M33 GUG 4.5.7
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
 * Reference: ARMv8-M ARM B5.3.1 / ARM Cortex-M33 GUG 6.3.1
 */
#define SAU_CTRL_ENABLE_Pos              0U
#define SAU_CTRL_ENABLE_Msk             (1UL << SAU_CTRL_ENABLE_Pos)
#define SAU_CTRL_ALLNS_Pos              1U
#define SAU_CTRL_ALLNS_Msk             (1UL << SAU_CTRL_ALLNS_Pos)

/**
 * SAU Region Register bits
 * SAU 区域寄存器位
 * Reference: ARMv8-M ARM B5.3.3-5.3.5 / ARM Cortex-M33 GUG 6.3.3-6.3.5
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
 * PMU Control Register bits
 * PMU 控制寄存器位
 * Reference: ARMv8-M ARM B6.3.1 / ARM Cortex-M33 TRM 11.3.1
 */
#define PMU_CTRL_ENABLE_Pos              0U
#define PMU_CTRL_ENABLE_Msk             (1UL << PMU_CTRL_ENABLE_Pos)
#define PMU_CTRL_EVENTCNT_Pos            1U
#define PMU_CTRL_EVENTCNT_Msk           (1UL << PMU_CTRL_EVENTCNT_Pos)
#define PMU_CTRL_CYCCNT_Pos             2U
#define PMU_CTRL_CYCCNT_Msk            (1UL << PMU_CTRL_CYCCNT_Pos)
#define PMU_CTRL_DIFFCNT_Pos           3U
#define PMU_CTRL_DIFFCNT_Msk           (1UL << PMU_CTRL_DIFFCNT_Pos)

/**
 * ITM Control Register bits
 * ITM 控制寄存器位
 * Reference: ARMv8-M ARM B6.2.3 / ARM Cortex-M33 GUG 7.2.3
 */
#define ITM_CTRL_ITMENA_Pos              0U
#define ITM_CTRL_ITMENA_Msk             (1UL << ITM_CTRL_ITMENA_Pos)
#define ITM_CTRL_TRCENA_Pos             2U
#define ITM_CTRL_TRCENA_Msk            (1UL << ITM_CTRL_TRCENA_Pos)
#define ITM_CTRL_BUSY_Pos               7U
#define ITM_CTRL_BUSY_Msk              (1UL << ITM_CTRL_BUSY_Pos)

/**
 * FPU Coprocessor Access Control bits
 * FPU 协处理器访问控制位
 * Reference: ARMv8-M ARM B3.2.14 / ARM Cortex-M33 GUG 4.2.14
 */
#define CPACR_CP10_Pos                  20U
#define CPACR_CP10_Msk                 (3UL << CPACR_CP10_Pos)
#define CPACR_CP11_Pos                  22U
#define CPACR_CP11_Msk                 (3UL << CPACR_CP11_Pos)

/**
 * MPU Memory Attribute definitions
 * MPU 内存属性定义
 * Reference: ARMv8-M ARM B4.3.7 / ARM Cortex-M33 GUG 4.5.7
 */
#define MPU_DEVICE_nGnRnE              0x00U
#define MPU_DEVICE_nGnRE               0x04U
#define MPU_DEVICE_nGRE                0x08U
#define MPU_DEVICE_GRE                 0x0CU

#define MPU_NORMAL_MEMORY_IWBWA_OWBWA   0xF0U
#define MPU_NORMAL_MEMORY_IWBWA_OWBNA   0xE0U
#define MPU_NORMAL_MEMORY_IBTFA         0xB0U
#define MPU_NORMAL_MEMORY_IWBWA_NC      0xD0U
#define MPU_NORMAL_MEMORY_IBTFA_NC      0x90U
#define MPU_NORMAL_MEMORY_IWBNWA_OWBWA  0xC0U
#define MPU_NORMAL_MEMORY_IWBNWA_OWBNA  0x80U
#define MPU_NORMAL_MEMORY_IWBNWA_NC    0x40U
#define MPU_NORMAL_NONCACHEABLE         0x00U

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
 * Reference: ARMv8-M ARM B2.2.4 (CONTROL, Control Register)
 * 参考: ARMv8-M ARM B2.2.4 (CONTROL, 控制寄存器)
 *
 * @return Current CONTROL register value
 * @return CONTROL 寄存器当前值
 */
uint32_t arch_armv8m_get_control(void);

/**
 * @brief Set CONTROL register value
 * @brief 设置 CONTROL 寄存器值
 *
 * Reference: ARMv8-M ARM B2.2.4 (CONTROL, Control Register)
 * 参考: ARMv8-M ARM B2.2.4 (CONTROL, 控制寄存器)
 *
 * @param control: New CONTROL register value
 * @param control: CONTROL 寄存器新值
 */
void arch_armv8m_set_control(uint32_t control);

/**
 * @brief Get Main Stack Pointer (MSP)
 * @brief 获取主栈指针 (MSP)
 *
 * Reference: ARMv8-M ARM B2.2.2 (MSP, Main Stack Pointer)
 * 参考: ARMv8-M ARM B2.2.2 (MSP, 主栈指针)
 *
 * @return Current MSP value
 * @return 当前 MSP 值
 */
uint32_t arch_armv8m_get_msp(void);

/**
 * @brief Set Main Stack Pointer (MSP)
 * @brief 设置主栈指针 (MSP)
 *
 * Reference: ARMv8-M ARM B2.2.2 (MSP, Main Stack Pointer)
 * 参考: ARMv8-M ARM B2.2.2 (MSP, 主栈指针)
 *
 * @param msp: New MSP value
 * @param msp: 新的 MSP 值
 */
void arch_armv8m_set_msp(uint32_t msp);

/**
 * @brief Get Process Stack Pointer (PSP)
 * @brief 获取进程栈指针 (PSP)
 *
 * Reference: ARMv8-M ARM B2.2.3 (PSP, Process Stack Pointer)
 * 参考: ARMv8-M ARM B2.2.3 (PSP, 进程栈指针)
 *
 * @return Current PSP value
 * @return 当前 PSP 值
 */
uint32_t arch_armv8m_get_psp(void);

/**
 * @brief Set Process Stack Pointer (PSP)
 * @brief 设置进程栈指针 (PSP)
 *
 * Reference: ARMv8-M ARM B2.2.3 (PSP, Process Stack Pointer)
 * 参考: ARMv8-M ARM B2.2.3 (PSP, 进程栈指针)
 *
 * @param psp: New PSP value
 * @param psp: 新的 PSP 值
 */
void arch_armv8m_set_psp(uint32_t psp);

/**
 * @brief Get PRIMASK register
 * @brief 获取 PRIMASK 寄存器
 *
 * Reference: ARMv8-M ARM B2.2.6 (PRIMASK, Priority Mask Register)
 * 参考: ARMv8-M ARM B2.2.6 (PRIMASK, 优先级屏蔽寄存器)
 *
 * @return Current PRIMASK value (0=interrupts enabled, 1=interrupts disabled)
 * @return 当前 PRIMASK 值 (0=中断使能, 1=中断禁用)
 */
uint32_t arch_armv8m_get_primask(void);

/**
 * @brief Set PRIMASK register
 * @brief 设置 PRIMASK 寄存器
 *
 * Reference: ARMv8-M ARM B2.2.6 (PRIMASK, Priority Mask Register)
 * 参考: ARMv8-M ARM B2.2.6 (PRIMASK, 优先级屏蔽寄存器)
 *
 * @param primask: New PRIMASK value
 * @param primask: 新的 PRIMASK 值
 */
void arch_armv8m_set_primask(uint32_t primask);

/**
 * @brief Get BASEPRI register
 * @brief 获取 BASEPRI 寄存器
 *
 * Reference: ARMv8-M ARM B2.2.7 (BASEPRI, Base Priority Register)
 * 参考: ARMv8-M ARM B2.2.7 (BASEPRI, 基础优先级寄存器)
 *
 * @return Current BASEPRI value
 * @return 当前 BASEPRI 值
 */
uint32_t arch_armv8m_get_basepri(void);

/**
 * @brief Set BASEPRI register
 * @brief 设置 BASEPRI 寄存器
 *
 * Reference: ARMv8-M ARM B2.2.7 (BASEPRI, Base Priority Register)
 * 参考: ARMv8-M ARM B2.2.7 (BASEPRI, 基础优先级寄存器)
 *
 * @param basepri: New BASEPRI value (0=disable, 1-255=mask priority <= basepri)
 * @param basepri: 新的 BASEPRI 值 (0=禁用, 1-255=屏蔽优先级 <= basepri)
 */
void arch_armv8m_set_basepri(uint32_t basepri);

/**
 * @brief Get FAULTMASK register
 * @brief 获取 FAULTMASK 寄存器
 *
 * Reference: ARMv8-M ARM B2.2.8 (FAULTMASK, Fault Mask Register)
 * 参考: ARMv8-M ARM B2.2.8 (FAULTMASK, 故障屏蔽寄存器)
 *
 * @return Current FAULTMASK value
 * @return 当前 FAULTMASK 值
 */
uint32_t arch_armv8m_get_faultmask(void);

/**
 * @brief Set FAULTMASK register
 * @brief 设置 FAULTMASK 寄存器
 *
 * Reference: ARMv8-M ARM B2.2.8 (FAULTMASK, Fault Mask Register)
 * 参考: ARMv8-M ARM B2.2.8 (FAULTMASK, 故障屏蔽寄存器)
 *
 * @param faultmask: New FAULTMASK value
 * @param faultmask: 新的 FAULTMASK 值
 */
void arch_armv8m_set_faultmask(uint32_t faultmask);

/**
 * @brief Get MSPLIM register (MSP Limit)
 * @brief 获取 MSPLIM 寄存器 (MSP 限制)
 *
 * Reference: ARMv8-M ARM B2.2.2 (MSPLIM, Main Stack Pointer Limit)
 * 参考: ARMv8-M ARM B2.2.2 (MSPLIM, 主栈指针限制)
 *
 * @return Current MSPLIM value
 * @return 当前 MSPLIM 值
 */
uint32_t arch_armv8m_get_msplim(void);

/**
 * @brief Set MSPLIM register
 * @brief 设置 MSPLIM 寄存器
 *
 * Reference: ARMv8-M ARM B2.2.2 (MSPLIM, Main Stack Pointer Limit)
 * 参考: ARMv8-M ARM B2.2.2 (MSPLIM, 主栈指针限制)
 *
 * @param msplim: New MSPLIM value
 * @param msplim: 新的 MSPLIM 值
 */
void arch_armv8m_set_msplim(uint32_t msplim);

/**
 * @brief Get PSPLIM register (PSP Limit)
 * @brief 获取 PSPLIM 寄存器 (PSP 限制)
 *
 * Reference: ARMv8-M ARM B2.2.3 (PSPLIM, Process Stack Pointer Limit)
 * 参考: ARMv8-M ARM B2.2.3 (PSPLIM, 进程栈指针限制)
 *
 * @return Current PSPLIM value
 * @return 当前 PSPLIM 值
 */
uint32_t arch_armv8m_get_psplim(void);

/**
 * @brief Set PSPLIM register
 * @brief 设置 PSPLIM 寄存器
 *
 * Reference: ARMv8-M ARM B2.2.3 (PSPLIM, Process Stack Pointer Limit)
 * 参考: ARMv8-M ARM B2.2.3 (PSPLIM, 进程栈指针限制)
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
 * Reference: ARMv8-M ARM B3.3.9 (NVIC_ISER, Interrupt Set-Enable Register)
 * 参考: ARMv8-M ARM B3.3.9 (NVIC_ISER, 中断使能寄存器)
 *
 * @param irq: Interrupt number (0-239)
 * @param irq: 中断号 (0-239)
 */
void arch_armv8m_enable_irq(uint8_t irq);

/**
 * @brief Disable specified interrupt
 * @brief 禁用指定中断
 *
 * Reference: ARMv8-M ARM B3.3.10 (NVIC_ICER, Interrupt Clear-Enable Register)
 * 参考: ARMv8-M ARM B3.3.10 (NVIC_ICER, 中断使能清除寄存器)
 *
 * @param irq: Interrupt number (0-239)
 * @param irq: 中断号 (0-239)
 */
void arch_armv8m_disable_irq(uint8_t irq);

/**
 * @brief Set interrupt priority
 * @brief 设置中断优先级
 *
 * Reference: ARMv8-M ARM B3.3.22 (NVIC_IPR, Interrupt Priority Register)
 * 参考: ARMv8-M ARM B3.3.22 (NVIC_IPR, 中断优先级寄存器)
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
 * Reference: ARMv8-M ARM B4.3.1 (MPU_TYPE, MPU Type Register)
 * 参考: ARMv8-M ARM B4.3.1 (MPU_TYPE, MPU 类型寄存器)
 *
 * @return MPU type register value
 * @return MPU 类型寄存器值
 */
uint32_t arch_armv8m_mpu_get_type(void);

/**
 * @brief Initialize MPU
 * @brief 初始化 MPU
 *
 * Reference: ARMv8-M ARM B4.3 (MPU registers summary)
 * 参考: ARMv8-M ARM B4.3 (MPU 寄存器摘要)
 */
void arch_armv8m_mpu_init(void);

/**
 * @brief Enable MPU
 * @brief 使能 MPU
 *
 * Reference: ARMv8-M ARM B4.3.2 (MPU_CTRL, MPU Control Register)
 * 参考: ARMv8-M ARM B4.3.2 (MPU_CTRL, MPU 控制寄存器)
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

/*
 * ============================================================================
 * ARMv8-M PMU (Performance Monitor Unit) Functions
 * ARMv8-M PMU (性能监视单元) 函数
 *
 * PMU is only supported on Cortex-M55, Cortex-M85, etc.
 * PMU 仅在 Cortex-M55、Cortex-M85 等上支持。
 * Reference: ARMv8-M ARM Section B6.3 (Performance Monitors)
 * 参考: ARMv8-M ARM 第 B6.3 节 (性能监视器)
 * ============================================================================
 */

/**
 * @brief Enable PMU
 * @brief 使能 PMU
 *
 * Reference: ARMv8-M ARM B6.3.1 (PMU_CTRL, Performance Monitor Control Register)
 * 参考: ARMv8-M ARM B6.3.1 (PMU_CTRL, 性能监视器控制寄存器)
 */
void arch_armv8m_pmu_enable(void);

/**
 * @brief Disable PMU
 * @brief 禁用 PMU
 *
 * Reference: ARMv8-M ARM B6.3.1 (PMU_CTRL)
 * 参考: ARMv8-M ARM B6.3.1 (PMU_CTRL)
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

/*
 * ============================================================================
 * ARMv8-M TrustZone (TZ) Functions
 * ARMv8-M TrustZone (TZ) 函数
 *
 * TrustZone is only supported on ARMv8-M Mainline
 * TrustZone 仅在 ARMv8-M Mainline 上支持
 * Reference: ARMv8-M ARM Section B5 (Security Attribution Unit)
 * 参考: ARMv8-M ARM 第 B5 节 (安全属性单元)
 * ============================================================================
 */

/**
 * @brief Enable SAU (Security Attribution Unit)
 * @brief 使能 SAU (安全属性单元)
 *
 * Reference: ARMv8-M ARM B5.3.1 (SAU_CTRL, SAU Control Register)
 * 参考: ARMv8-M ARM B5.3.1 (SAU_CTRL, SAU 控制寄存器)
 */
void arch_armv8m_tz_sau_enable(void);

/**
 * @brief Disable SAU
 * @brief 禁用 SAU
 *
 * Reference: ARMv8-M ARM B5.3.1 (SAU_CTRL)
 * 参考: ARMv8-M ARM B5.3.1 (SAU_CTRL)
 */
void arch_armv8m_tz_sau_disable(void);

/**
 * @brief Set SAU region count
 * @brief 设置 SAU 区域数量
 *
 * Reference: ARMv8-M ARM B5.3.2 (SAU_TYPE, SAU Type Register)
 * 参考: ARMv8-M ARM B5.3.2 (SAU_TYPE, SAU 类型寄存器)
 *
 * @param n: Region count (0-8)
 * @param n: 区域数量 (0-8)
 */
void arch_armv8m_tz_sau_set_region_count(uint32_t n);

/**
 * @brief Set SAU region
 * @brief 设置 SAU 区域
 *
 * Reference: ARMv8-M ARM B5.3.3 (SAU_RNR, SAU Region Number Register)
 *            ARMv8-M ARM B5.3.4 (SAU_RBAR, SAU Region Base Address Register)
 *            ARMv8-M ARM B5.3.5 (SAU_RLAR, SAU Region Limit Register)
 * 参考: ARMv8-M ARM B5.3.3 (SAU_RNR, SAU 区域编号寄存器)
 *       ARMv8-M ARM B5.3.4 (SAU_RBAR, SAU 区域基地址寄存器)
 *       ARMv8-M ARM B5.3.5 (SAU_RLAR, SAU 区域限制寄存器)
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
 */
void arch_armv8m_init(void);

/**
 * @brief ARMv8-M vector table setup
 * @brief ARMv8-M 向量表设置
 */
void arch_armv8m_setup_vector_table(void);

/**
 * @brief Initialize user task context
 * @brief 初始化用户任务上下文
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
 * @param vector_table_addr: Vector table address
 * @param vector_table_addr: 向量表地址
 */
void* arch_armv8m_jump_to_kernel(uint32_t vector_table_addr);

/*
 * ============================================================================
 * ARMv8-M SysTick Functions
 * ARMv8-M SysTick 函数
 * Reference: ARMv8-M ARM Section B3.4 (System Timer, SysTick)
 * 参考: ARMv8-M ARM 第 B3.4 节 (系统定时器 SysTick)
 * ============================================================================
 */

/**
 * @brief SysTick configuration
 * @brief SysTick 配置
 *
 * Reference: ARMv8-M ARM B3.4.1 (SysTick Control and Status Register)
 * 参考: ARMv8-M ARM B3.4.1 (SysTick 控制和状态寄存器)
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
 * Reference: ARMv8-M ARM B3.4.3 (SysTick Current Value Register)
 * 参考: ARMv8-M ARM B3.4.3 (SysTick 当前值寄存器)
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
 */
void arch_armv8m_systick_enable_irq(void);

/**
 * @brief Disable SysTick interrupt
 * @brief 禁用 SysTick 中断
 */
void arch_armv8m_systick_disable_irq(void);

/**
 * @brief Enable SysTick timer
 * @brief 使能 SysTick 定时器
 */
void arch_armv8m_systick_enable(void);

/**
 * @brief Disable SysTick timer
 * @brief 禁用 SysTick 定时器
 */
void arch_armv8m_systick_disable(void);

/**
 * @brief Get SysTick calibration value
 * @brief 获取 SysTick 校准值
 *
 * @return Calibration value
 * @return 校准值
 */
uint32_t arch_armv8m_systick_get_calib(void);

/*
 * ============================================================================
 * ARMv8-M ITM (Instrumentation Trace Macrocell) Functions
 * ARMv8-M ITM (仪表跟踪宏单元) 函数
 * Reference: ARMv8-M ARM Section B6.2 (Instrumentation Trace Macrocell)
 * 参考: ARMv8-M ARM 第 B6.2 节 (仪表跟踪宏单元)
 * ============================================================================
 */

/**
 * @brief ITM send character
 * @brief ITM 发送字符
 *
 * Reference: ARMv8-M ARM B6.2.2 (ITM_STIM, Stimulus Port Register)
 * 参考: ARMv8-M ARM B6.2.2 (ITM_STIM, 刺激端口寄存器)
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
 * @return Received character or -1 if no data
 * @return 接收的字符或如果没有数据则返回 -1
 */
int32_t arch_armv8m_itm_receive_char(void);

/**
 * @brief ITM check if character is waiting
 * @brief ITM 检查是否有字符等待读取
 *
 * @return 1=data available, 0=no data
 * @return 1=有数据可用, 0=无数据
 */
int32_t arch_armv8m_itm_check_char(void);

/**
 * @brief ITM enable/disable
 * @brief ITM 使能/禁用
 *
 * @param enable: Enable (1) or disable (0)
 * @param enable: 使能 (1) 或禁用 (0)
 */
void arch_armv8m_itm_enable(uint32_t enable);

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
 * Base Address: 0xE000E100
 *
 * Members:
 *   ISER[8U]: Interrupt Set-Enable Registers
 *   ICER[8U]: Interrupt Clear-Enable Registers
 *   ISPR[8U]: Interrupt Set-Pending Registers
 *   ICPR[8U]: Interrupt Clear-Pending Registers
 *   IABR[8U]: Interrupt Active Bit Registers
 *   IP[240U]: Interrupt Priority Registers
 */
typedef struct {
    volatile uint32_t ISER[8U];
    volatile uint32_t RESERVED0[24U];
    volatile uint32_t ICER[8U];
    volatile uint32_t RESERVED1[24U];
    volatile uint32_t ISPR[8U];
    volatile uint32_t RESERVED2[24U];
    volatile uint32_t ICPR[8U];
    volatile uint32_t RESERVED3[24U];
    volatile uint32_t IABR[8U];
    volatile uint32_t RESERVED4[56U];
    volatile uint8_t  IP[240U];
} NVIC_Type;

/**
 * SCB (System Control Block) Register Map
 * SCB (系统控制块) 寄存器映射
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
 * Reference: ARMv8-M ARM D1.2.4
 * 参考: ARMv8-M ARM D1.2.4
 */
#ifndef __DSB
    #define __DSB() __asm__ volatile ("dsb sy" : : : "memory")
#endif

/**
 * @brief Instruction Synchronization Barrier
 * @brief 指令同步屏障
 *
 * Reference: ARMv8-M ARM D1.2.4
 * 参考: ARMv8-M ARM D1.2.4
 */
#ifndef __ISB
    #define __ISB() __asm__ volatile ("isb sy" : : : "memory")
#endif

/**
 * @brief Get CPACR (Coprocessor Access Control Register)
 * @brief 获取 CPACR (协处理器访问控制寄存器)
 *
 * Reference: ARMv8-M ARM B3.2.14 (SCB_CPACR)
 * 参考: ARMv8-M ARM B3.2.14 (SCB_CPACR)
 */
#ifndef __FPU_GetCPACR
    #define __FPU_GetCPACR()         (SCB->CPACR)
#endif

/**
 * @brief Set CPACR (Coprocessor Access Control Register)
 * @brief 设置 CPACR (协处理器访问控制寄存器)
 *
 * Reference: ARMv8-M ARM B3.2.14 (SCB_CPACR)
 * 参考: ARMv8-M ARM B3.2.14 (SCB_CPACR)
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

/*
 * ============================================================================
 * ARMv8-M DSP/SIMD Intrinsics
 * ARMv8-M DSP/SIMD 内在函数
 *
 * These intrinsics provide access to DSP and SIMD instructions available in
 * Cortex-M33, Cortex-M55, Cortex-M85 and other processors with DSP extension.
 * 这些内在函数提供对具有 DSP 扩展的 Cortex-M33、Cortex-M55、Cortex-M85 等
 * 处理器中 DSP 和 SIMD 指令的访问。
 *
 * ARMv8-M also supports Helium (MVE) extension on M55/M85 for advanced vector
 * processing capabilities.
 * ARMv8-M 还在 M55/M85 上支持 Helium (MVE) 扩展，以提供高级向量处理能力。
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

#define __PKHBT(ARG1,ARG2,ARG3) \
    __builtin_arm_pkhbt((ARG1), (ARG2), (ARG3))

#define __PKHTB(ARG1,ARG2,ARG3) \
    __builtin_arm_pkhtb((ARG1), (ARG2), (ARG3))

#endif /* __ARM_FEATURE_DSP */

#if defined(__ARM_FEATURE_MVE) && (__ARM_FEATURE_MVE == 1)

/*
 * ============================================================================
 * ARMv8.1-M Helium (MVE) Intrinsics
 * ARMv8.1-M Helium (MVE) 内在函数
 *
 * Helium (MVE - M-Profile Vector Extension) provides advanced vector
 * processing capabilities for Cortex-M55, Cortex-M85 and future processors.
 * Helium (MVE - M-Profile 向量扩展) 为 Cortex-M55、Cortex-M85 及未来
 * 处理器提供高级向量处理能力。
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

#ifdef __cplusplus
}
#endif

#endif
