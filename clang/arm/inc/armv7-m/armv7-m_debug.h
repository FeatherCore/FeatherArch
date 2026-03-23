/*
 * ARM Architecture - ARMv7-M Debug and Trace
 *
 * ============================================================================
 * File: armv7-m_debug.h
 * Description: ARMv7-M debug and trace component definitions
 * 描述: ARMv7-M 调试和跟踪组件定义
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual
 *   - Chapter B10: Debug
 *   - Chapter B11: Debug and Trace Components
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_DEBUG_H__
#define __ARCH_ARM_V7M_DEBUG_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv7-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * Debug Base Addresses
 * 调试基地址
 * ============================================================================
 */

#define DWT_BASE_ADDR             0xE0001000UL
#define ITM_BASE_ADDR             0xE0000000UL
#define TPIU_BASE_ADDR            0xE0040000UL
#define ETM_BASE_ADDR             0xE0041000UL
#define FP_BASE_ADDR              0xE0002000UL  /* Flash Patch and Breakpoint Unit */

/*
 * ============================================================================
 * DWT (Data Watchpoint and Trace) Register Definitions
 * DWT 寄存器定义
 * ============================================================================
 */

/**
 * DWT Control Register (DWT_CTRL)
 * DWT 控制寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.58
 */
#define DWT_CTRL                  (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x000))

/**
 * DWT Cycle Count Register (DWT_CYCCNT)
 * DWT 周期计数寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.59
 */
#define DWT_CYCCNT                (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x004))

/**
 * DWT CPI Count Register (DWT_CPICNT)
 * DWT CPI计数寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.57
 */
#define DWT_CPICNT                (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x008))

/**
 * DWT Exception Overhead Count Register (DWT_EXCCNT)
 * DWT 异常开销计数寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.62
 */
#define DWT_EXCCNT                (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x00C))

/**
 * DWT Sleep Count Register (DWT_SLEEPCNT)
 * DWT 休眠计数寄存器
 */
#define DWT_SLEEPCNT              (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x010))

/**
 * DWT LSU Count Register (DWT_LSUCNT)
 * DWT LSU计数寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.67
 */
#define DWT_LSUCNT                (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x014))

/**
 * DWT Folded Instruction Count Register (DWT_FOLDCNT)
 * DWT 折叠指令计数寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.63
 */
#define DWT_FOLDCNT               (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x018))

/**
 * DWT Program Counter Sample Register (DWT_PCSR)
 * DWT 程序计数器采样寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.68
 */
#define DWT_PCSR                  (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x01C))

/**
 * DWT Comparator Register n (DWT_COMPn)
 * DWT 比较器寄存器n
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.56
 */
#define DWT_COMP(n)               (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x020 + ((n) * 0x10)))

/**
 * DWT Comparator Function Register n (DWT_FUNCTIONn)
 * DWT 比较器功能寄存器n
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.64
 */
#define DWT_FUNCTION(n)           (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x028 + ((n) * 0x10)))

/**
 * DWT Comparator Value Mask Register n (DWT_VMASKn)
 * DWT 比较器值掩码寄存器n
 */
#define DWT_VMASK(n)              (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x02C + ((n) * 0x10)))

/**
 * DWT Software Lock Access Register (DWT_LAR)
 * DWT 软件锁访问寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.65
 */
#define DWT_LAR                   (*(volatile uint32_t *)(DWT_BASE_ADDR + 0xFB0))

/**
 * DWT Software Lock Status Register (DWT_LSR)
 * DWT 软件锁状态寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.66
 */
#define DWT_LSR                   (*(volatile uint32_t *)(DWT_BASE_ADDR + 0xFB4))

/**
 * DWT Device Architecture Register (DWT_DEVARCH)
 * DWT 设备架构寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.60
 */
#define DWT_DEVARCH               (*(volatile uint32_t *)(DWT_BASE_ADDR + 0xFBC))

/**
 * DWT Device Type Register (DWT_DEVTYPE)
 * DWT 设备类型寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.61
 */
#define DWT_DEVTYPE               (*(volatile uint32_t *)(DWT_BASE_ADDR + 0xFCC))

/**
 * DWT Peripheral Identification Register 4 (DWT_PIDR4)
 * DWT 外设标识寄存器4
 */
#define DWT_PIDR4                 (*(volatile uint32_t *)(DWT_BASE_ADDR + 0xFD0))

/**
 * DWT Peripheral Identification Register 5 (DWT_PIDR5)
 * DWT 外设标识寄存器5
 */
#define DWT_PIDR5                 (*(volatile uint32_t *)(DWT_BASE_ADDR + 0xFD4))

/**
 * DWT Peripheral Identification Register 6 (DWT_PIDR6)
 * DWT 外设标识寄存器6
 */
#define DWT_PIDR6                 (*(volatile uint32_t *)(DWT_BASE_ADDR + 0xFD8))

/**
 * DWT Peripheral Identification Register 7 (DWT_PIDR7)
 * DWT 外设标识寄存器7
 */
#define DWT_PIDR7                 (*(volatile uint32_t *)(DWT_BASE_ADDR + 0xFDC))

/**
 * DWT Peripheral Identification Register 0 (DWT_PIDR0)
 * DWT 外设标识寄存器0
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.69
 */
#define DWT_PIDR0                 (*(volatile uint32_t *)(DWT_BASE_ADDR + 0xFE0))

/**
 * DWT Peripheral Identification Register 1 (DWT_PIDR1)
 * DWT 外设标识寄存器1
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.70
 */
#define DWT_PIDR1                 (*(volatile uint32_t *)(DWT_BASE_ADDR + 0xFE4))

/**
 * DWT Peripheral Identification Register 2 (DWT_PIDR2)
 * DWT 外设标识寄存器2
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.71
 */
#define DWT_PIDR2                 (*(volatile uint32_t *)(DWT_BASE_ADDR + 0xFE8))

/**
 * DWT Peripheral Identification Register 3 (DWT_PIDR3)
 * DWT 外设标识寄存器3
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.72
 */
#define DWT_PIDR3                 (*(volatile uint32_t *)(DWT_BASE_ADDR + 0xFEC))

/**
 * DWT Component Identification Register 0 (DWT_CIDR0)
 * DWT 组件标识寄存器0
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.52
 */
#define DWT_CIDR0                 (*(volatile uint32_t *)(DWT_BASE_ADDR + 0xFF0))

/**
 * DWT Component Identification Register 1 (DWT_CIDR1)
 * DWT 组件标识寄存器1
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.53
 */
#define DWT_CIDR1                 (*(volatile uint32_t *)(DWT_BASE_ADDR + 0xFF4))

/**
 * DWT Component Identification Register 2 (DWT_CIDR2)
 * DWT 组件标识寄存器2
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.54
 */
#define DWT_CIDR2                 (*(volatile uint32_t *)(DWT_BASE_ADDR + 0xFF8))

/**
 * DWT Component Identification Register 3 (DWT_CIDR3)
 * DWT 组件标识寄存器3
 * Reference: Arm(R) v7-M Architecture Reference Manual, D1.2.55
 */
#define DWT_CIDR3                 (*(volatile uint32_t *)(DWT_BASE_ADDR + 0xFFC))

/*
 * ============================================================================
 * ITM (Instrumentation Trace Macrocell) Register Definitions
 * ITM 寄存器定义
 * ============================================================================
 */

/**
 * ITM Stimulus Port Register n (ITM_STIMn)
 * ITM 激励端口寄存器n
 */
#define ITM_STIM(n)               (*(volatile uint32_t *)(ITM_BASE_ADDR + ((n) * 4)))

/**
 * ITM Trace Enable Register n (ITM_TERn)
 * ITM 跟踪使能寄存器n
 */
#define ITM_TER(n)                (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xE00 + ((n) * 4)))

/**
 * ITM Trace Privilege Register (ITM_TPR)
 * ITM 跟踪特权寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual
 */
#define ITM_TPR                   (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xE40))

/**
 * ITM Trace Control Register (ITM_TCR)
 * ITM 跟踪控制寄存器
 */
#define ITM_TCR                   (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xE80))

/**
 * ITM Integration Read Register (ITM_ITREAD)
 * ITM 集成读寄存器
 */
#define ITM_ITREAD                (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xEF0))

/**
 * ITM Integration Write Register (ITM_ITWRITE)
 * ITM 集成写寄存器
 */
#define ITM_ITWRITE               (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xEF8))

/**
 * ITM Integration Mode Control Register (ITM_ITCTRL)
 * ITM 集成模式控制寄存器
 */
#define ITM_ITCTRL                (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xF00))

/**
 * ITM Software Lock Access Register (ITM_LAR)
 * ITM 软件锁访问寄存器
 */
#define ITM_LAR                   (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xFB0))

/**
 * ITM Software Lock Status Register (ITM_LSR)
 * ITM 软件锁状态寄存器
 */
#define ITM_LSR                   (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xFB4))

/**
 * ITM Device Architecture Register (ITM_DEVARCH)
 * ITM 设备架构寄存器
 */
#define ITM_DEVARCH               (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xFBC))

/**
 * ITM Device Type Register (ITM_DEVTYPE)
 * ITM 设备类型寄存器
 */
#define ITM_DEVTYPE               (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xFCC))

/**
 * ITM Peripheral Identification Register 4 (ITM_PIDR4)
 * ITM 外设标识寄存器4
 */
#define ITM_PIDR4                 (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xFD0))

/**
 * ITM Peripheral Identification Register 5 (ITM_PIDR5)
 * ITM 外设标识寄存器5
 */
#define ITM_PIDR5                 (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xFD4))

/**
 * ITM Peripheral Identification Register 6 (ITM_PIDR6)
 * ITM 外设标识寄存器6
 */
#define ITM_PIDR6                 (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xFD8))

/**
 * ITM Peripheral Identification Register 7 (ITM_PIDR7)
 * ITM 外设标识寄存器7
 */
#define ITM_PIDR7                 (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xFDC))

/**
 * ITM Peripheral Identification Register 0 (ITM_PIDR0)
 * ITM 外设标识寄存器0
 */
#define ITM_PIDR0                 (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xFE0))

/**
 * ITM Peripheral Identification Register 1 (ITM_PIDR1)
 * ITM 外设标识寄存器1
 */
#define ITM_PIDR1                 (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xFE4))

/**
 * ITM Peripheral Identification Register 2 (ITM_PIDR2)
 * ITM 外设标识寄存器2
 */
#define ITM_PIDR2                 (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xFE8))

/**
 * ITM Peripheral Identification Register 3 (ITM_PIDR3)
 * ITM 外设标识寄存器3
 */
#define ITM_PIDR3                 (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xFEC))

/**
 * ITM Component Identification Register 0 (ITM_CIDR0)
 * ITM 组件标识寄存器0
 */
#define ITM_CIDR0                 (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xFF0))

/**
 * ITM Component Identification Register 1 (ITM_CIDR1)
 * ITM 组件标识寄存器1
 */
#define ITM_CIDR1                 (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xFF4))

/**
 * ITM Component Identification Register 2 (ITM_CIDR2)
 * ITM 组件标识寄存器2
 */
#define ITM_CIDR2                 (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xFF8))

/**
 * ITM Component Identification Register 3 (ITM_CIDR3)
 * ITM 组件标识寄存器3
 */
#define ITM_CIDR3                 (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xFFC))

/*
 * ============================================================================
 * FPB (Flash Patch and Breakpoint) Register Definitions
 * FPB 寄存器定义
 * ============================================================================
 */

/**
 * Flash Patch Control Register (FP_CTRL)
 * Flash补丁控制寄存器
 */
#define FP_CTRL                   (*(volatile uint32_t *)(FP_BASE_ADDR + 0x000))

/**
 * Flash Patch Remap Register (FP_REMAP)
 * Flash补丁重映射寄存器
 */
#define FP_REMAP                  (*(volatile uint32_t *)(FP_BASE_ADDR + 0x004))

/**
 * Flash Patch Comparator Register n (FP_COMPn)
 * Flash补丁比较器寄存器n
 */
#define FP_COMP(n)                (*(volatile uint32_t *)(FP_BASE_ADDR + 0x008 + ((n) * 4)))

/**
 * FPB Software Lock Access Register (FP_LAR)
 * FPB 软件锁访问寄存器
 */
#define FP_LAR                    (*(volatile uint32_t *)(FP_BASE_ADDR + 0xFB0))

/**
 * FPB Software Lock Status Register (FP_LSR)
 * FPB 软件锁状态寄存器
 */
#define FP_LSR                    (*(volatile uint32_t *)(FP_BASE_ADDR + 0xFB4))

/**
 * FPB Device Architecture Register (FP_DEVARCH)
 * FPB 设备架构寄存器
 */
#define FP_DEVARCH                (*(volatile uint32_t *)(FP_BASE_ADDR + 0xFBC))

/**
 * FPB Device Type Register (FP_DEVTYPE)
 * FPB 设备类型寄存器
 */
#define FP_DEVTYPE                (*(volatile uint32_t *)(FP_BASE_ADDR + 0xFCC))

/**
 * FPB Peripheral Identification Register 4 (FP_PIDR4)
 * FPB 外设标识寄存器4
 */
#define FP_PIDR4                  (*(volatile uint32_t *)(FP_BASE_ADDR + 0xFD0))

/**
 * FPB Peripheral Identification Register 5 (FP_PIDR5)
 * FPB 外设标识寄存器5
 */
#define FP_PIDR5                  (*(volatile uint32_t *)(FP_BASE_ADDR + 0xFD4))

/**
 * FPB Peripheral Identification Register 6 (FP_PIDR6)
 * FPB 外设标识寄存器6
 */
#define FP_PIDR6                  (*(volatile uint32_t *)(FP_BASE_ADDR + 0xFD8))

/**
 * FPB Peripheral Identification Register 7 (FP_PIDR7)
 * FPB 外设标识寄存器7
 */
#define FP_PIDR7                  (*(volatile uint32_t *)(FP_BASE_ADDR + 0xFDC))

/**
 * FPB Peripheral Identification Register 0 (FP_PIDR0)
 * FPB 外设标识寄存器0
 */
#define FP_PIDR0                  (*(volatile uint32_t *)(FP_BASE_ADDR + 0xFE0))

/**
 * FPB Peripheral Identification Register 1 (FP_PIDR1)
 * FPB 外设标识寄存器1
 */
#define FP_PIDR1                  (*(volatile uint32_t *)(FP_BASE_ADDR + 0xFE4))

/**
 * FPB Peripheral Identification Register 2 (FP_PIDR2)
 * FPB 外设标识寄存器2
 */
#define FP_PIDR2                  (*(volatile uint32_t *)(FP_BASE_ADDR + 0xFE8))

/**
 * FPB Peripheral Identification Register 3 (FP_PIDR3)
 * FPB 外设标识寄存器3
 */
#define FP_PIDR3                  (*(volatile uint32_t *)(FP_BASE_ADDR + 0xFEC))

/**
 * FPB Component Identification Register 0 (FP_CIDR0)
 * FPB 组件标识寄存器0
 */
#define FP_CIDR0                  (*(volatile uint32_t *)(FP_BASE_ADDR + 0xFF0))

/**
 * FPB Component Identification Register 1 (FP_CIDR1)
 * FPB 组件标识寄存器1
 */
#define FP_CIDR1                  (*(volatile uint32_t *)(FP_BASE_ADDR + 0xFF4))

/**
 * FPB Component Identification Register 2 (FP_CIDR2)
 * FPB 组件标识寄存器2
 */
#define FP_CIDR2                  (*(volatile uint32_t *)(FP_BASE_ADDR + 0xFF8))

/**
 * FPB Component Identification Register 3 (FP_CIDR3)
 * FPB 组件标识寄存器3
 */
#define FP_CIDR3                  (*(volatile uint32_t *)(FP_BASE_ADDR + 0xFFC))

/*
 * ============================================================================
 * DWT Register Bit Definitions
 * DWT 寄存器位定义
 * ============================================================================
 */

#define DWT_CTRL_NUMCOMP_Pos      28U
#define DWT_CTRL_NUMCOMP_Msk      (0xFUL << DWT_CTRL_NUMCOMP_Pos)
#define DWT_CTRL_NOTRCPKT_Pos     27U
#define DWT_CTRL_NOTRCPKT_Msk     (1UL << DWT_CTRL_NOTRCPKT_Pos)
#define DWT_CTRL_NOEXTTRIG_Pos    26U
#define DWT_CTRL_NOEXTTRIG_Msk    (1UL << DWT_CTRL_NOEXTTRIG_Pos)
#define DWT_CTRL_NOCYCCNT_Pos     25U
#define DWT_CTRL_NOCYCCNT_Msk     (1UL << DWT_CTRL_NOCYCCNT_Pos)
#define DWT_CTRL_NOPRFCNT_Pos     24U
#define DWT_CTRL_NOPRFCNT_Msk     (1UL << DWT_CTRL_NOPRFCNT_Pos)
#define DWT_CTRL_CYCDISS_Pos      23U
#define DWT_CTRL_CYCDISS_Msk      (1UL << DWT_CTRL_CYCDISS_Pos)
#define DWT_CTRL_CYCEVTENA_Pos    22U
#define DWT_CTRL_CYCEVTENA_Msk    (1UL << DWT_CTRL_CYCEVTENA_Pos)
#define DWT_CTRL_FOLDEVTENA_Pos   21U
#define DWT_CTRL_FOLDEVTENA_Msk   (1UL << DWT_CTRL_FOLDEVTENA_Pos)
#define DWT_CTRL_LSUEVTENA_Pos    20U
#define DWT_CTRL_LSUEVTENA_Msk    (1UL << DWT_CTRL_LSUEVTENA_Pos)
#define DWT_CTRL_SLEEPEVTENA_Pos  19U
#define DWT_CTRL_SLEEPEVTENA_Msk  (1UL << DWT_CTRL_SLEEPEVTENA_Pos)
#define DWT_CTRL_EXCEVTENA_Pos    18U
#define DWT_CTRL_EXCEVTENA_Msk    (1UL << DWT_CTRL_EXCEVTENA_Pos)
#define DWT_CTRL_CPIEVTENA_Pos    17U
#define DWT_CTRL_CPIEVTENA_Msk    (1UL << DWT_CTRL_CPIEVTENA_Pos)
#define DWT_CTRL_EXCTRCENA_Pos    16U
#define DWT_CTRL_EXCTRCENA_Msk    (1UL << DWT_CTRL_EXCTRCENA_Pos)
#define DWT_CTRL_PCSAMPLENA_Pos   12U
#define DWT_CTRL_PCSAMPLENA_Msk   (1UL << DWT_CTRL_PCSAMPLENA_Pos)
#define DWT_CTRL_SYNCTAP_Pos      10U
#define DWT_CTRL_SYNCTAP_Msk      (3UL << DWT_CTRL_SYNCTAP_Pos)
#define DWT_CTRL_CYCTAP_Pos       9U
#define DWT_CTRL_CYCTAP_Msk       (1UL << DWT_CTRL_CYCTAP_Pos)
#define DWT_CTRL_POSTINIT_Pos     5U
#define DWT_CTRL_POSTINIT_Msk     (0xFUL << DWT_CTRL_POSTINIT_Pos)
#define DWT_CTRL_POSTPRESET_Pos   1U
#define DWT_CTRL_POSTPRESET_Msk   (0xFUL << DWT_CTRL_POSTPRESET_Pos)
#define DWT_CTRL_CYCCNTENA_Pos    0U
#define DWT_CTRL_CYCCNTENA_Msk    (1UL << DWT_CTRL_CYCCNTENA_Pos)

/* DWT_FUNCTION Register Bits */
#define DWT_FUNCTION_ID_Pos       27U
#define DWT_FUNCTION_ID_Msk       (0x1FUL << DWT_FUNCTION_ID_Pos)
#define DWT_FUNCTION_MATCHED_Pos  24U
#define DWT_FUNCTION_MATCHED_Msk  (1UL << DWT_FUNCTION_MATCHED_Pos)
#define DWT_FUNCTION_DATAVSIZE_Pos 10U
#define DWT_FUNCTION_DATAVSIZE_Msk (3UL << DWT_FUNCTION_DATAVSIZE_Pos)
#define DWT_FUNCTION_ACTION_Pos   0U
#define DWT_FUNCTION_ACTION_Msk   (0xFUL << DWT_FUNCTION_ACTION_Pos)

/* DWT Function Actions */
#define DWT_FUNCTION_ACTION_NONE      0x0U
#define DWT_FUNCTION_ACTION_WATCHPOINT 0x1U
#define DWT_FUNCTION_ACTION_DEBUG_EVENT 0x2U
#define DWT_FUNCTION_ACTION_TRACE_PC  0x4U
#define DWT_FUNCTION_ACTION_TRACE_DATA 0x5U
#define DWT_FUNCTION_ACTION_TRACE_PC_DATA 0x6U

/*
 * ============================================================================
 * ITM Register Bit Definitions
 * ITM 寄存器位定义
 * ============================================================================
 */

#define ITM_TCR_BUSY_Pos          23U
#define ITM_TCR_BUSY_Msk          (1UL << ITM_TCR_BUSY_Pos)
#define ITM_TCR_TRACEBUSID_Pos    16U
#define ITM_TCR_TRACEBUSID_Msk    (0x7FUL << ITM_TCR_TRACEBUSID_Pos)
#define ITM_TCR_GTSFREQ_Pos       10U
#define ITM_TCR_GTSFREQ_Msk       (3UL << ITM_TCR_GTSFREQ_Pos)
#define ITM_TCR_TSPRESCALE_Pos    8U
#define ITM_TCR_TSPRESCALE_Msk    (3UL << ITM_TCR_TSPRESCALE_Pos)
#define ITM_TCR_STALLENA_Pos      5U
#define ITM_TCR_STALLENA_Msk      (1UL << ITM_TCR_STALLENA_Pos)
#define ITM_TCR_SWOENA_Pos        4U
#define ITM_TCR_SWOENA_Msk        (1UL << ITM_TCR_SWOENA_Pos)
#define ITM_TCR_DWTENA_Pos        3U
#define ITM_TCR_DWTENA_Msk        (1UL << ITM_TCR_DWTENA_Pos)
#define ITM_TCR_SYNCENA_Pos       2U
#define ITM_TCR_SYNCENA_Msk       (1UL << ITM_TCR_SYNCENA_Pos)
#define ITM_TCR_TSENA_Pos         1U
#define ITM_TCR_TSENA_Msk         (1UL << ITM_TCR_TSENA_Pos)
#define ITM_TCR_ITMENA_Pos        0U
#define ITM_TCR_ITMENA_Msk        (1UL << ITM_TCR_ITMENA_Pos)

/*
 * ============================================================================
 * FPB Register Bit Definitions
 * FPB 寄存器位定义
 * ============================================================================
 */

#define FP_CTRL_NUM_CODE_Pos      8U
#define FP_CTRL_NUM_CODE_Msk      (0xFUL << FP_CTRL_NUM_CODE_Pos)
#define FP_CTRL_NUM_LIT_Pos       4U
#define FP_CTRL_NUM_LIT_Msk       (0xFUL << FP_CTRL_NUM_LIT_Pos)
#define FP_CTRL_KEY_Pos           1U
#define FP_CTRL_KEY_Msk           (1UL << FP_CTRL_KEY_Pos)
#define FP_CTRL_ENABLE_Pos        0U
#define FP_CTRL_ENABLE_Msk        (1UL << FP_CTRL_ENABLE_Pos)

#define FP_COMP_REPLACE_Pos       30U
#define FP_COMP_REPLACE_Msk       (3UL << FP_COMP_REPLACE_Pos)
#define FP_COMP_COMP_Pos          2U
#define FP_COMP_COMP_Msk          (0x1FFFFFFFUL << FP_COMP_COMP_Pos)
#define FP_COMP_ENABLE_Pos        0U
#define FP_COMP_ENABLE_Msk        (1UL << FP_COMP_ENABLE_Pos)

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Enable DWT
 */
void dwt_enable(void);

/**
 * @brief Disable DWT
 */
void dwt_disable(void);

/**
 * @brief Enable DWT cycle counter
 */
void dwt_enable_cycle_counter(void);

/**
 * @brief Disable DWT cycle counter
 */
void dwt_disable_cycle_counter(void);

/**
 * @brief Get DWT cycle counter value
 * @return Cycle count
 */
static inline uint32_t dwt_get_cycle_counter(void) {
    return DWT_CYCCNT;
}

/**
 * @brief Reset DWT cycle counter
 */
static inline void dwt_reset_cycle_counter(void) {
    DWT_CYCCNT = 0U;
}

/**
 * @brief Get number of DWT comparators
 * @return Number of comparators
 */
static inline uint32_t dwt_get_num_comparators(void) {
    return (DWT_CTRL & DWT_CTRL_NUMCOMP_Msk) >> DWT_CTRL_NUMCOMP_Pos;
}

/**
 * @brief Configure DWT comparator
 * @param comp Comparator number
 * @param addr Address to compare
 * @param action Action to take on match
 */
void dwt_configure_comparator(uint32_t comp, uint32_t addr, uint32_t action);

/**
 * @brief Enable DWT comparator
 * @param comp Comparator number
 */
void dwt_enable_comparator(uint32_t comp);

/**
 * @brief Disable DWT comparator
 * @param comp Comparator number
 */
void dwt_disable_comparator(uint32_t comp);

/**
 * @brief Enable ITM
 */
void itm_enable(void);

/**
 * @brief Disable ITM
 */
void itm_disable(void);

/**
 * @brief Check if ITM stimulus port is ready
 * @param port Port number (0-31)
 * @return true if ready
 */
static inline bool itm_stimulus_port_ready(uint32_t port) {
    return (ITM_STIM(port) & 0x1U) != 0U;
}

/**
 * @brief Write to ITM stimulus port
 * @param port Port number (0-31)
 * @param value Value to write
 */
static inline void itm_stimulus_port_write(uint32_t port, uint32_t value) {
    ITM_STIM(port) = value;
}

/**
 * @brief Send character via ITM
 * @param ch Character to send
 * @return Character sent
 */
int32_t itm_send_char(int32_t ch);

/**
 * @brief Receive character via ITM
 * @return Character received or -1 if no data
 */
int32_t itm_receive_char(void);

/**
 * @brief Enable ITM stimulus port
 * @param port Port number
 */
void itm_enable_stimulus_port(uint32_t port);

/**
 * @brief Disable ITM stimulus port
 * @param port Port number
 */
void itm_disable_stimulus_port(uint32_t port);

/**
 * @brief Enable FPB
 */
void fpb_enable(void);

/**
 * @brief Disable FPB
 */
void fpb_disable(void);

/**
 * @brief Set FPB breakpoint
 * @param bp Breakpoint number
 * @param addr Address
 * @return 0 on success, -1 on error
 */
int32_t fpb_set_breakpoint(uint32_t bp, uint32_t addr);

/**
 * @brief Clear FPB breakpoint
 * @param bp Breakpoint number
 */
void fpb_clear_breakpoint(uint32_t bp);

/**
 * @brief Get number of FPB breakpoints
 * @return Number of breakpoints
 */
uint32_t fpb_get_num_breakpoints(void);

/**
 * @brief Get number of FPB literal comparators
 * @return Number of literal comparators
 */
uint32_t fpb_get_num_literals(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_DEBUG_H__ */
