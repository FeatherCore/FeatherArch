/*
 * ARM Architecture - ARMv8-M NVIC (Nested Vectored Interrupt Controller)
 *
 * ============================================================================
 * File: armv8m_nvic.h
 * Description: ARMv8-M NVIC register definitions and function declarations
 * 描述: ARMv8-M NVIC 寄存器定义和函数声明
 *
 * This file provides definitions for the Nested Vectored Interrupt Controller:
 * - NVIC register definitions
 * - SCB (System Control Block) register definitions
 * - Interrupt enable/disable/pending functions
 * - Priority management functions
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B12: Nested Vectored Interrupt Controller
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V8M_NVIC_H__
#define __ARCH_ARM_V8M_NVIC_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv8-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * NVIC Base Addresses
 * NVIC 基地址
 * ============================================================================
 */

#define NVIC_BASE_ADDR            0xE000E100UL
#define SCB_BASE_ADDR             0xE000ED00UL
#define SCB_NS_BASE_ADDR          0xE002ED00UL
#define NVIC_NS_BASE_ADDR         0xE002E100UL

/*
 * ============================================================================
 * NVIC Register Definitions
 * NVIC 寄存器定义
 * ============================================================================
 */

/**
 * Interrupt Set Enable Registers (ISER[0-15])
 * 中断使能设置寄存器
 */
#define NVIC_ISER_BASE            (NVIC_BASE_ADDR + 0x000)
#define NVIC_ISER(n)              (*(volatile uint32_t *)(NVIC_ISER_BASE + ((n) * 4)))

/**
 * Interrupt Clear Enable Registers (ICER[0-15])
 * 中断使能清除寄存器
 */
#define NVIC_ICER_BASE            (NVIC_BASE_ADDR + 0x080)
#define NVIC_ICER(n)              (*(volatile uint32_t *)(NVIC_ICER_BASE + ((n) * 4)))

/**
 * Interrupt Set Pending Registers (ISPR[0-15])
 * 中断挂起设置寄存器
 */
#define NVIC_ISPR_BASE            (NVIC_BASE_ADDR + 0x100)
#define NVIC_ISPR(n)              (*(volatile uint32_t *)(NVIC_ISPR_BASE + ((n) * 4)))

/**
 * Interrupt Clear Pending Registers (ICPR[0-15])
 * 中断挂起清除寄存器
 */
#define NVIC_ICPR_BASE            (NVIC_BASE_ADDR + 0x180)
#define NVIC_ICPR(n)              (*(volatile uint32_t *)(NVIC_ICPR_BASE + ((n) * 4)))

/**
 * Interrupt Active Bit Registers (IABR[0-15])
 * 中断活动位寄存器
 */
#define NVIC_IABR_BASE            (NVIC_BASE_ADDR + 0x200)
#define NVIC_IABR(n)              (*(volatile uint32_t *)(NVIC_IABR_BASE + ((n) * 4)))

/**
 * Interrupt Target Non-Secure Registers (ITNS[0-15])
 * 中断目标非安全寄存器 (TrustZone)
 */
#define NVIC_ITNS_BASE            (NVIC_BASE_ADDR + 0x280)
#define NVIC_ITNS(n)              (*(volatile uint32_t *)(NVIC_ITNS_BASE + ((n) * 4)))

/**
 * Interrupt Priority Registers (IPR[0-479])
 * 中断优先级寄存器
 */
#define NVIC_IPR_BASE             (NVIC_BASE_ADDR + 0x400)
#define NVIC_IPR(n)               (*(volatile uint8_t *)(NVIC_IPR_BASE + (n)))

/*
 * ============================================================================
 * Non-Secure NVIC Register Definitions (TrustZone)
 * 非安全 NVIC 寄存器定义 (TrustZone)
 * ============================================================================
 */

#if (__TZ_PRESENT == 1)
#define NVIC_NS_ISER(n)           (*(volatile uint32_t *)(NVIC_NS_BASE_ADDR + ((n) * 4)))
#define NVIC_NS_ICER(n)           (*(volatile uint32_t *)(NVIC_NS_BASE_ADDR + 0x80 + ((n) * 4)))
#define NVIC_NS_ISPR(n)           (*(volatile uint32_t *)(NVIC_NS_BASE_ADDR + 0x100 + ((n) * 4)))
#define NVIC_NS_ICPR(n)           (*(volatile uint32_t *)(NVIC_NS_BASE_ADDR + 0x180 + ((n) * 4)))
#define NVIC_NS_IABR(n)           (*(volatile uint32_t *)(NVIC_NS_BASE_ADDR + 0x200 + ((n) * 4)))
#define NVIC_NS_IPR(n)            (*(volatile uint8_t *)(NVIC_NS_BASE_ADDR + 0x300 + (n)))
#endif

/*
 * ============================================================================
 * SCB (System Control Block) Register Definitions
 * 系统控制块寄存器定义
 * ============================================================================
 */

/**
 * CPUID Base Register
 * CPUID 基址寄存器
 */
#define SCB_CPUID                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x00))

/**
 * Interrupt Control and State Register (ICSR)
 * 中断控制和状态寄存器
 */
#define SCB_ICSR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x04))

/**
 * Vector Table Offset Register (VTOR)
 * 向量表偏移寄存器
 */
#define SCB_VTOR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x08))

/**
 * Application Interrupt and Reset Control Register (AIRCR)
 * 应用中断和复位控制寄存器
 */
#define SCB_AIRCR                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x0C))

/**
 * System Control Register (SCR)
 * 系统控制寄存器
 */
#define SCB_SCR                   (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x10))

/**
 * Configuration and Control Register (CCR)
 * 配置和控制寄存器
 */
#define SCB_CCR                   (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x14))

/**
 * System Handler Priority Registers (SHPR[0-2])
 * 系统处理程序优先级寄存器
 */
#define SCB_SHPR1                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x18))
#define SCB_SHPR2                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x1C))
#define SCB_SHPR3                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x20))

/**
 * System Handler Control and State Register (SHCSR)
 * 系统处理程序控制和状态寄存器
 */
#define SCB_SHCSR                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x24))

/**
 * Configurable Fault Status Register (CFSR)
 * 可配置故障状态寄存器
 */
#define SCB_CFSR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x28))

/**
 * HardFault Status Register (HFSR)
 * HardFault 状态寄存器
 */
#define SCB_HFSR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x2C))

/**
 * Debug Fault Status Register (DFSR)
 * 调试故障状态寄存器
 */
#define SCB_DFSR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x30))

/**
 * MemManage Fault Address Register (MMFAR)
 * 内存管理故障地址寄存器
 */
#define SCB_MMFAR                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x34))

/**
 * BusFault Address Register (BFAR)
 * 总线故障地址寄存器
 */
#define SCB_BFAR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x38))

/**
 * Auxiliary Fault Status Register (AFSR)
 * 辅助故障状态寄存器
 */
#define SCB_AFSR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x3C))

/**
 * Cache Size ID Register (CCSIDR)
 * 缓存大小ID寄存器
 */
#define SCB_CCSIDR                (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x80))

/**
 * Cache Size Selection Register (CSSELR)
 * 缓存大小选择寄存器
 */
#define SCB_CSSELR                (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x84))

/**
 * Revision ID Register (REVIDR)
 * 修订ID寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.11
 */
#define SCB_REVIDR                (*(volatile uint32_t *)(SCB_BASE_ADDR - 0x04))

/**
 * Processor Feature Register 0 (ID_PFR0)
 * 处理器特性寄存器0
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.11
 */
#define SCB_ID_PFR0               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x40))

/**
 * Processor Feature Register 1 (ID_PFR1)
 * 处理器特性寄存器1
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.11
 */
#define SCB_ID_PFR1               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x44))

/**
 * Debug Feature Register 0 (ID_DFR0)
 * 调试特性寄存器0
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.11
 */
#define SCB_ID_DFR0               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x48))

/**
 * Auxiliary Feature Register 0 (ID_AFR0)
 * 辅助特性寄存器0
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.11
 */
#define SCB_ID_AFR0               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x4C))

/**
 * Memory Model Feature Register 0 (ID_MMFR0)
 * 内存模型特性寄存器0
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.11
 */
#define SCB_ID_MMFR0              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x50))

/**
 * Memory Model Feature Register 1 (ID_MMFR1)
 * 内存模型特性寄存器1
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.11
 */
#define SCB_ID_MMFR1              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x54))

/**
 * Memory Model Feature Register 2 (ID_MMFR2)
 * 内存模型特性寄存器2
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.11
 */
#define SCB_ID_MMFR2              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x58))

/**
 * Memory Model Feature Register 3 (ID_MMFR3)
 * 内存模型特性寄存器3
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.11
 */
#define SCB_ID_MMFR3              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x5C))

/**
 * Instruction Set Attribute Register 0 (ID_ISAR0)
 * 指令集属性寄存器0
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.11
 */
#define SCB_ID_ISAR0              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x60))

/**
 * Instruction Set Attribute Register 1 (ID_ISAR1)
 * 指令集属性寄存器1
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.11
 */
#define SCB_ID_ISAR1              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x64))

/**
 * Instruction Set Attribute Register 2 (ID_ISAR2)
 * 指令集属性寄存器2
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.11
 */
#define SCB_ID_ISAR2              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x68))

/**
 * Instruction Set Attribute Register 3 (ID_ISAR3)
 * 指令集属性寄存器3
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.11
 */
#define SCB_ID_ISAR3              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x6C))

/**
 * Instruction Set Attribute Register 4 (ID_ISAR4)
 * 指令集属性寄存器4
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.11
 */
#define SCB_ID_ISAR4              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x70))

/**
 * Instruction Set Attribute Register 5 (ID_ISAR5)
 * 指令集属性寄存器5
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.11
 */
#define SCB_ID_ISAR5              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x74))

/**
 * Cache Level ID Register (CLIDR)
 * 缓存级别ID寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.11
 */
#define SCB_CLIDR                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x78))

/**
 * Cache Type Register (CTR)
 * 缓存类型寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.11
 */
#define SCB_CTR                   (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x7C))

/**
 * Coprocessor Access Control Register (CPACR)
 * 协处理器访问控制寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.11
 */
#define SCB_CPACR                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x88))

/**
 * Non-secure Access Control Register (NSACR)
 * 非安全访问控制寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.11
 */
#define SCB_NSACR                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x8C))

/*
 * ============================================================================
 * Implementation Control Block Register Definitions
 * 实现控制块寄存器定义
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.8
 * ============================================================================
 */

#define ICB_BASE_ADDR             0xE000E000UL
#define ICB_NS_BASE_ADDR          0xE002E000UL

/**
 * Interrupt Controller Type Register (ICTR)
 * 中断控制器类型寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.8
 */
#define ICB_ICTR                  (*(volatile uint32_t *)(ICB_BASE_ADDR + 0x004))
#define ICB_NS_ICTR               (*(volatile uint32_t *)(ICB_NS_BASE_ADDR + 0x004))

/**
 * Auxiliary Control Register (ACTLR)
 * 辅助控制寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.8
 */
#define ICB_ACTLR                 (*(volatile uint32_t *)(ICB_BASE_ADDR + 0x008))
#define ICB_NS_ACTLR              (*(volatile uint32_t *)(ICB_NS_BASE_ADDR + 0x008))

/**
 * Coprocessor Power Control Register (CPPWR)
 * 协处理器电源控制寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.8
 */
#define ICB_CPPWR                 (*(volatile uint32_t *)(ICB_BASE_ADDR + 0x00C))
#define ICB_NS_CPPWR              (*(volatile uint32_t *)(ICB_NS_BASE_ADDR + 0x00C))

/*
 * ============================================================================
 * Debug Identification Block Register Definitions
 * 调试标识块寄存器定义
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.19
 * ============================================================================
 */

#define DIB_BASE_ADDR             0xE000EFB0UL
#define DIB_NS_BASE_ADDR          0xE002EFB0UL

/**
 * SCS Software Lock Access Register (DLAR)
 * SCS 软件锁访问寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.19
 */
#define DIB_DLAR                  (*(volatile uint32_t *)(DIB_BASE_ADDR + 0x000))
#define DIB_NS_DLAR               (*(volatile uint32_t *)(DIB_NS_BASE_ADDR + 0x000))

/**
 * SCS Software Lock Status Register (DLSR)
 * SCS 软件锁状态寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.19
 */
#define DIB_DLSR                  (*(volatile uint32_t *)(DIB_BASE_ADDR + 0x004))
#define DIB_NS_DLSR               (*(volatile uint32_t *)(DIB_NS_BASE_ADDR + 0x004))

/**
 * Debug Authentication Status Register (DAUTHSTATUS)
 * 调试认证状态寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.19
 */
#define DIB_DAUTHSTATUS           (*(volatile uint32_t *)(DIB_BASE_ADDR + 0x008))
#define DIB_NS_DAUTHSTATUS        (*(volatile uint32_t *)(DIB_NS_BASE_ADDR + 0x008))

/**
 * SCS Device Architecture Register (DDEVARCH)
 * SCS 设备架构寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.19
 */
#define DIB_DDEVARCH              (*(volatile uint32_t *)(DIB_BASE_ADDR + 0x00C))
#define DIB_NS_DDEVARCH           (*(volatile uint32_t *)(DIB_NS_BASE_ADDR + 0x00C))

/**
 * SCS Device Type Register (DDEVTYPE)
 * SCS 设备类型寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.19
 */
#define DIB_DDEVTYPE              (*(volatile uint32_t *)(DIB_BASE_ADDR + 0x01C))
#define DIB_NS_DDEVTYPE           (*(volatile uint32_t *)(DIB_NS_BASE_ADDR + 0x01C))

/**
 * SCS Peripheral Identification Register 4 (DPIDR4)
 * SCS 外设标识寄存器4
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.19
 */
#define DIB_DPIDR4                (*(volatile uint32_t *)(DIB_BASE_ADDR + 0x020))
#define DIB_NS_DPIDR4             (*(volatile uint32_t *)(DIB_NS_BASE_ADDR + 0x020))

/**
 * SCS Peripheral Identification Register 5 (DPIDR5)
 * SCS 外设标识寄存器5
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.19
 */
#define DIB_DPIDR5                (*(volatile uint32_t *)(DIB_BASE_ADDR + 0x024))
#define DIB_NS_DPIDR5             (*(volatile uint32_t *)(DIB_NS_BASE_ADDR + 0x024))

/**
 * SCS Peripheral Identification Register 6 (DPIDR6)
 * SCS 外设标识寄存器6
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.19
 */
#define DIB_DPIDR6                (*(volatile uint32_t *)(DIB_BASE_ADDR + 0x028))
#define DIB_NS_DPIDR6             (*(volatile uint32_t *)(DIB_NS_BASE_ADDR + 0x028))

/**
 * SCS Peripheral Identification Register 7 (DPIDR7)
 * SCS 外设标识寄存器7
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.19
 */
#define DIB_DPIDR7                (*(volatile uint32_t *)(DIB_BASE_ADDR + 0x02C))
#define DIB_NS_DPIDR7             (*(volatile uint32_t *)(DIB_NS_BASE_ADDR + 0x02C))

/**
 * SCS Peripheral Identification Register 0 (DPIDR0)
 * SCS 外设标识寄存器0
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.19
 */
#define DIB_DPIDR0                (*(volatile uint32_t *)(DIB_BASE_ADDR + 0x030))
#define DIB_NS_DPIDR0             (*(volatile uint32_t *)(DIB_NS_BASE_ADDR + 0x030))

/**
 * SCS Peripheral Identification Register 1 (DPIDR1)
 * SCS 外设标识寄存器1
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.19
 */
#define DIB_DPIDR1                (*(volatile uint32_t *)(DIB_BASE_ADDR + 0x034))
#define DIB_NS_DPIDR1             (*(volatile uint32_t *)(DIB_NS_BASE_ADDR + 0x034))

/**
 * SCS Peripheral Identification Register 2 (DPIDR2)
 * SCS 外设标识寄存器2
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.19
 */
#define DIB_DPIDR2                (*(volatile uint32_t *)(DIB_BASE_ADDR + 0x038))
#define DIB_NS_DPIDR2             (*(volatile uint32_t *)(DIB_NS_BASE_ADDR + 0x038))

/**
 * SCS Peripheral Identification Register 3 (DPIDR3)
 * SCS 外设标识寄存器3
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.19
 */
#define DIB_DPIDR3                (*(volatile uint32_t *)(DIB_BASE_ADDR + 0x03C))
#define DIB_NS_DPIDR3             (*(volatile uint32_t *)(DIB_NS_BASE_ADDR + 0x03C))

/**
 * SCS Component Identification Register 0 (DCIDR0)
 * SCS 组件标识寄存器0
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.19
 */
#define DIB_DCIDR0                (*(volatile uint32_t *)(DIB_BASE_ADDR + 0x040))
#define DIB_NS_DCIDR0             (*(volatile uint32_t *)(DIB_NS_BASE_ADDR + 0x040))

/**
 * SCS Component Identification Register 1 (DCIDR1)
 * SCS 组件标识寄存器1
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.19
 */
#define DIB_DCIDR1                (*(volatile uint32_t *)(DIB_BASE_ADDR + 0x044))
#define DIB_NS_DCIDR1             (*(volatile uint32_t *)(DIB_NS_BASE_ADDR + 0x044))

/**
 * SCS Component Identification Register 2 (DCIDR2)
 * SCS 组件标识寄存器2
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.19
 */
#define DIB_DCIDR2                (*(volatile uint32_t *)(DIB_BASE_ADDR + 0x048))
#define DIB_NS_DCIDR2             (*(volatile uint32_t *)(DIB_NS_BASE_ADDR + 0x048))

/**
 * SCS Component Identification Register 3 (DCIDR3)
 * SCS 组件标识寄存器3
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.19
 */
#define DIB_DCIDR3                (*(volatile uint32_t *)(DIB_BASE_ADDR + 0x04C))
#define DIB_NS_DCIDR3             (*(volatile uint32_t *)(DIB_NS_BASE_ADDR + 0x04C))

/*
 * ============================================================================
 * SCB Register Bit Definitions
 * SCB 寄存器位定义
 * ============================================================================
 */

/**
 * ICSR Register Bits
 * ICSR 寄存器位
 */
#define SCB_ICSR_NMIPENDSET_Pos   31U
#define SCB_ICSR_NMIPENDSET_Msk   (1UL << SCB_ICSR_NMIPENDSET_Pos)
#define SCB_ICSR_PENDSVSET_Pos    28U
#define SCB_ICSR_PENDSVSET_Msk    (1UL << SCB_ICSR_PENDSVSET_Pos)
#define SCB_ICSR_PENDSVCLR_Pos    27U
#define SCB_ICSR_PENDSVCLR_Msk    (1UL << SCB_ICSR_PENDSVCLR_Pos)
#define SCB_ICSR_PENDSTSET_Pos    26U
#define SCB_ICSR_PENDSTSET_Msk    (1UL << SCB_ICSR_PENDSTSET_Pos)
#define SCB_ICSR_PENDSTCLR_Pos    25U
#define SCB_ICSR_PENDSTCLR_Msk    (1UL << SCB_ICSR_PENDSTCLR_Pos)
#define SCB_ICSR_STTNS_Pos        24U
#define SCB_ICSR_STTNS_Msk        (1UL << SCB_ICSR_STTNS_Pos)
#define SCB_ICSR_ISRPREEMPT_Pos   23U
#define SCB_ICSR_ISRPREEMPT_Msk   (1UL << SCB_ICSR_ISRPREEMPT_Pos)
#define SCB_ICSR_ISRPENDING_Pos   22U
#define SCB_ICSR_ISRPENDING_Msk   (1UL << SCB_ICSR_ISRPENDING_Pos)
#define SCB_ICSR_VECTPENDING_Pos  12U
#define SCB_ICSR_VECTPENDING_Msk  (0x1FFUL << SCB_ICSR_VECTPENDING_Pos)
#define SCB_ICSR_RETTOBASE_Pos    11U
#define SCB_ICSR_RETTOBASE_Msk    (1UL << SCB_ICSR_RETTOBASE_Pos)
#define SCB_ICSR_VECTACTIVE_Pos   0U
#define SCB_ICSR_VECTACTIVE_Msk   (0x1FFUL << SCB_ICSR_VECTACTIVE_Pos)

/**
 * AIRCR Register Bits
 * AIRCR 寄存器位
 */
#define SCB_AIRCR_VECTKEY_Pos     16U
#define SCB_AIRCR_VECTKEY_Msk     (0xFFFFUL << SCB_AIRCR_VECTKEY_Pos)
#define SCB_AIRCR_VECTKEYSTAT_Pos 16U
#define SCB_AIRCR_VECTKEYSTAT_Msk (0xFFFFUL << SCB_AIRCR_VECTKEYSTAT_Pos)
#define SCB_AIRCR_ENDIANESS_Pos   15U
#define SCB_AIRCR_ENDIANESS_Msk   (1UL << SCB_AIRCR_ENDIANESS_Pos)
#define SCB_AIRCR_PRIS_Pos        14U
#define SCB_AIRCR_PRIS_Msk        (1UL << SCB_AIRCR_PRIS_Pos)
#define SCB_AIRCR_BFHFNMINS_Pos   13U
#define SCB_AIRCR_BFHFNMINS_Msk   (1UL << SCB_AIRCR_BFHFNMINS_Pos)
#define SCB_AIRCR_SYSRESETREQS_Pos 3U
#define SCB_AIRCR_SYSRESETREQS_Msk (1UL << SCB_AIRCR_SYSRESETREQS_Pos)
#define SCB_AIRCR_SYSRESETREQ_Pos 2U
#define SCB_AIRCR_SYSRESETREQ_Msk (1UL << SCB_AIRCR_SYSRESETREQ_Pos)
#define SCB_AIRCR_VECTCLRACTIVE_Pos 1U
#define SCB_AIRCR_VECTCLRACTIVE_Msk (1UL << SCB_AIRCR_VECTCLRACTIVE_Pos)

/**
 * AIRCR Write Key Value
 * AIRCR 写入密钥值
 */
#define SCB_AIRCR_VECTKEY_VALUE   (0x5FAUL << SCB_AIRCR_VECTKEY_Pos)

/**
 * SCR Register Bits
 * SCR 寄存器位
 */
#define SCB_SCR_SEVONPEND_Pos     4U
#define SCB_SCR_SEVONPEND_Msk     (1UL << SCB_SCR_SEVONPEND_Pos)
#define SCB_SCR_SLEEPDEEPS_Pos    3U
#define SCB_SCR_SLEEPDEEPS_Msk    (1UL << SCB_SCR_SLEEPDEEPS_Pos)
#define SCB_SCR_SLEEPDEEP_Pos     2U
#define SCB_SCR_SLEEPDEEP_Msk     (1UL << SCB_SCR_SLEEPDEEP_Pos)
#define SCB_SCR_SLEEPONEXIT_Pos   1U
#define SCB_SCR_SLEEPONEXIT_Msk   (1UL << SCB_SCR_SLEEPONEXIT_Pos)

/**
 * CCR Register Bits
 * CCR 寄存器位
 */
#define SCB_CCR_BP_Pos            18U
#define SCB_CCR_BP_Msk            (1UL << SCB_CCR_BP_Pos)
#define SCB_CCR_IC_Pos            17U
#define SCB_CCR_IC_Msk            (1UL << SCB_CCR_IC_Pos)
#define SCB_CCR_DC_Pos            16U
#define SCB_CCR_DC_Msk            (1UL << SCB_CCR_DC_Pos)
#define SCB_CCR_STKOFHFNMIGN_Pos  10U
#define SCB_CCR_STKOFHFNMIGN_Msk  (1UL << SCB_CCR_STKOFHFNMIGN_Pos)
#define SCB_CCR_BFHFNMIGN_Pos     8U
#define SCB_CCR_BFHFNMIGN_Msk     (1UL << SCB_CCR_BFHFNMIGN_Pos)
#define SCB_CCR_DIV_0_TRP_Pos     4U
#define SCB_CCR_DIV_0_TRP_Msk     (1UL << SCB_CCR_DIV_0_TRP_Pos)
#define SCB_CCR_UNALIGN_TRP_Pos   3U
#define SCB_CCR_UNALIGN_TRP_Msk   (1UL << SCB_CCR_UNALIGN_TRP_Pos)
#define SCB_CCR_USERSETMPEND_Pos  1U
#define SCB_CCR_USERSETMPEND_Msk  (1UL << SCB_CCR_USERSETMPEND_Pos)

/**
 * SHCSR Register Bits
 * SHCSR 寄存器位
 */
#define SCB_SHCSR_HARDFAULTPENDED_Pos  21U
#define SCB_SHCSR_HARDFAULTPENDED_Msk  (1UL << SCB_SHCSR_HARDFAULTPENDED_Pos)
#define SCB_SHCSR_SECUREFAULTPENDED_Pos 20U
#define SCB_SHCSR_SECUREFAULTPENDED_Msk (1UL << SCB_SHCSR_SECUREFAULTPENDED_Pos)
#define SCB_SHCSR_SECUREFAULTENA_Pos   19U
#define SCB_SHCSR_SECUREFAULTENA_Msk   (1UL << SCB_SHCSR_SECUREFAULTENA_Pos)
#define SCB_SHCSR_USGFAULTENA_Pos      18U
#define SCB_SHCSR_USGFAULTENA_Msk      (1UL << SCB_SHCSR_USGFAULTENA_Pos)
#define SCB_SHCSR_BUSFAULTENA_Pos      17U
#define SCB_SHCSR_BUSFAULTENA_Msk      (1UL << SCB_SHCSR_BUSFAULTENA_Pos)
#define SCB_SHCSR_MEMFAULTENA_Pos      16U
#define SCB_SHCSR_MEMFAULTENA_Msk      (1UL << SCB_SHCSR_MEMFAULTENA_Pos)
#define SCB_SHCSR_SVCALLPENDED_Pos     15U
#define SCB_SHCSR_SVCALLPENDED_Msk     (1UL << SCB_SHCSR_SVCALLPENDED_Pos)
#define SCB_SHCSR_BUSFAULTPENDED_Pos   14U
#define SCB_SHCSR_BUSFAULTPENDED_Msk   (1UL << SCB_SHCSR_BUSFAULTPENDED_Pos)
#define SCB_SHCSR_MEMFAULTPENDED_Pos   13U
#define SCB_SHCSR_MEMFAULTPENDED_Msk   (1UL << SCB_SHCSR_MEMFAULTPENDED_Pos)
#define SCB_SHCSR_USGFAULTPENDED_Pos   12U
#define SCB_SHCSR_USGFAULTPENDED_Msk   (1UL << SCB_SHCSR_USGFAULTPENDED_Pos)
#define SCB_SHCSR_SYSTICKACT_Pos       11U
#define SCB_SHCSR_SYSTICKACT_Msk       (1UL << SCB_SHCSR_SYSTICKACT_Pos)
#define SCB_SHCSR_PENDSVACT_Pos        10U
#define SCB_SHCSR_PENDSVACT_Msk        (1UL << SCB_SHCSR_PENDSVACT_Pos)
#define SCB_SHCSR_MONITORACT_Pos       8U
#define SCB_SHCSR_MONITORACT_Msk       (1UL << SCB_SHCSR_MONITORACT_Pos)
#define SCB_SHCSR_SVCALLACT_Pos        7U
#define SCB_SHCSR_SVCALLACT_Msk        (1UL << SCB_SHCSR_SVCALLACT_Pos)
#define SCB_SHCSR_NMIACT_Pos           5U
#define SCB_SHCSR_NMIACT_Msk           (1UL << SCB_SHCSR_NMIACT_Pos)
#define SCB_SHCSR_SECUREFAULTACT_Pos   4U
#define SCB_SHCSR_SECUREFAULTACT_Msk   (1UL << SCB_SHCSR_SECUREFAULTACT_Pos)
#define SCB_SHCSR_USGFAULTACT_Pos      3U
#define SCB_SHCSR_USGFAULTACT_Msk      (1UL << SCB_SHCSR_USGFAULTACT_Pos)
#define SCB_SHCSR_HARDFAULTACT_Pos     2U
#define SCB_SHCSR_HARDFAULTACT_Msk     (1UL << SCB_SHCSR_HARDFAULTACT_Pos)
#define SCB_SHCSR_BUSFAULTACT_Pos      1U
#define SCB_SHCSR_BUSFAULTACT_Msk      (1UL << SCB_SHCSR_BUSFAULTACT_Pos)
#define SCB_SHCSR_MEMFAULTACT_Pos      0U
#define SCB_SHCSR_MEMFAULTACT_Msk      (1UL << SCB_SHCSR_MEMFAULTACT_Pos)

/**
 * CFSR Register Bits (Consists of UFSR, BFSR, MMFSR)
 * CFSR 寄存器位
 */
#define SCB_CFSR_USGFAULTSR_Pos   16U
#define SCB_CFSR_USGFAULTSR_Msk   (0xFFFFUL << SCB_CFSR_USGFAULTSR_Pos)
#define SCB_CFSR_BUSFAULTSR_Pos   8U
#define SCB_CFSR_BUSFAULTSR_Msk   (0xFFUL << SCB_CFSR_BUSFAULTSR_Pos)
#define SCB_CFSR_MEMFAULTSR_Pos   0U
#define SCB_CFSR_MEMFAULTSR_Msk   (0xFFUL << SCB_CFSR_MEMFAULTSR_Pos)

/**
 * HFSR Register Bits
 * HFSR 寄存器位
 */
#define SCB_HFSR_DEBUGEVT_Pos     31U
#define SCB_HFSR_DEBUGEVT_Msk     (1UL << SCB_HFSR_DEBUGEVT_Pos)
#define SCB_HFSR_FORCED_Pos       30U
#define SCB_HFSR_FORCED_Msk       (1UL << SCB_HFSR_FORCED_Pos)
#define SCB_HFSR_VECTTBL_Pos      1U
#define SCB_HFSR_VECTTBL_Msk      (1UL << SCB_HFSR_VECTTBL_Pos)

/*
 * ============================================================================
 * Exception Numbers
 * 异常编号
 * ============================================================================
 */

/**
 * Exception Types
 * 异常类型
 */
typedef enum {
    /* Cortex-M Processor Exceptions Numbers */
    NonMaskableInt_IRQn       = -14,    /* 2 Non Maskable Interrupt */
    HardFault_IRQn            = -13,    /* 3 Cortex-M Hard Fault Interrupt */
    MemoryManagement_IRQn     = -12,    /* 4 Cortex-M Memory Management Interrupt */
    BusFault_IRQn             = -11,    /* 5 Cortex-M Bus Fault Interrupt */
    UsageFault_IRQn           = -10,    /* 6 Cortex-M Usage Fault Interrupt */
    SecureFault_IRQn          = -9,     /* 7 Cortex-M Secure Fault Interrupt (ARMv8-M) */
    SVCall_IRQn               = -5,     /* 11 Cortex-M SV Call Interrupt */
    DebugMonitor_IRQn         = -4,     /* 12 Cortex-M Debug Monitor Interrupt */
    PendSV_IRQn               = -2,     /* 14 Cortex-M Pend SV Interrupt */
    SysTick_IRQn              = -1,     /* 15 Cortex-M System Tick Interrupt */

    /* Device Specific Interrupt Numbers (0-479) */
    External_IRQn_Start       = 0
} IRQn_Type;

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Enable specified interrupt
 * @param irq Interrupt number (0 to __ARM_NUM_INTERRUPTS-1)
 */
void nvic_enable_irq(uint8_t irq);

/**
 * @brief Disable specified interrupt
 * @param irq Interrupt number
 */
void nvic_disable_irq(uint8_t irq);

/**
 * @brief Get interrupt enable status
 * @param irq Interrupt number
 * @return 1 if enabled, 0 if disabled
 */
uint32_t nvic_get_enable_irq(uint8_t irq);

/**
 * @brief Set interrupt pending status
 * @param irq Interrupt number
 */
void nvic_set_pending(uint8_t irq);

/**
 * @brief Clear interrupt pending status
 * @param irq Interrupt number
 */
void nvic_clear_pending(uint8_t irq);

/**
 * @brief Get interrupt pending status
 * @param irq Interrupt number
 * @return 1 if pending, 0 if not pending
 */
uint32_t nvic_get_pending(uint8_t irq);

/**
 * @brief Get active interrupt status
 * @param irq Interrupt number
 * @return 1 if active, 0 if not active
 */
uint32_t nvic_get_active(uint8_t irq);

/**
 * @brief Set interrupt priority
 * @param irq Interrupt number
 * @param priority Priority value (0=highest, 255=lowest)
 */
void nvic_set_priority(uint8_t irq, uint8_t priority);

/**
 * @brief Get interrupt priority
 * @param irq Interrupt number
 * @return Priority value
 */
uint8_t nvic_get_priority(uint8_t irq);

/**
 * @brief Set priority grouping
 * @param priority_group Priority grouping value (0-7)
 */
void nvic_set_priority_grouping(uint32_t priority_group);

/**
 * @brief Get priority grouping
 * @return Priority grouping value
 */
uint32_t nvic_get_priority_grouping(void);

/**
 * @brief Encode priority
 * @param priority_group Priority grouping
 * @param preempt_priority Preemption priority
 * @param sub_priority Sub-priority
 * @return Encoded priority value
 */
uint32_t nvic_encode_priority(uint32_t priority_group, uint32_t preempt_priority, uint32_t sub_priority);

/**
 * @brief Decode priority
 * @param priority Encoded priority
 * @param priority_group Priority grouping
 * @param preempt_priority Output preemption priority
 * @param sub_priority Output sub-priority
 */
void nvic_decode_priority(uint32_t priority, uint32_t priority_group, uint32_t *preempt_priority, uint32_t *sub_priority);

/**
 * @brief System reset
 */
void nvic_system_reset(void);

/**
 * @brief Set vector table offset
 * @param offset Vector table offset address
 */
void scb_set_vtor(uint32_t offset);

/**
 * @brief Get vector table offset
 * @return Vector table offset address
 */
uint32_t scb_get_vtor(void);

/**
 * @brief Get active exception number
 * @return Active exception number
 */
static inline uint32_t scb_get_active_exception(void) {
    return (SCB_ICSR & SCB_ICSR_VECTACTIVE_Msk) >> SCB_ICSR_VECTACTIVE_Pos;
}

/**
 * @brief Set PendSV pending
 */
static inline void scb_set_pendsv_pending(void) {
    SCB_ICSR = SCB_ICSR_PENDSVSET_Msk;
}

/**
 * @brief Clear PendSV pending
 */
static inline void scb_clear_pendsv_pending(void) {
    SCB_ICSR = SCB_ICSR_PENDSVCLR_Msk;
}

/**
 * @brief Set SysTick pending
 */
static inline void scb_set_systick_pending(void) {
    SCB_ICSR = SCB_ICSR_PENDSTSET_Msk;
}

/**
 * @brief Clear SysTick pending
 */
static inline void scb_clear_systick_pending(void) {
    SCB_ICSR = SCB_ICSR_PENDSTCLR_Msk;
}

/*
 * ============================================================================
 * TrustZone Non-Secure NVIC Functions
 * TrustZone 非安全 NVIC 函数
 * ============================================================================
 */

#if (__TZ_PRESENT == 1)

void nvic_enable_irq_ns(uint8_t irq);
void nvic_disable_irq_ns(uint8_t irq);
void nvic_set_pending_ns(uint8_t irq);
void nvic_clear_pending_ns(uint8_t irq);
uint32_t nvic_get_pending_ns(uint8_t irq);
uint32_t nvic_get_active_ns(uint8_t irq);
void nvic_set_priority_ns(uint8_t irq, uint8_t priority);
uint8_t nvic_get_priority_ns(uint8_t irq);
void nvic_set_priority_grouping_ns(uint32_t priority_group);
uint32_t nvic_get_priority_grouping_ns(void);

#endif /* __TZ_PRESENT */

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V8M_NVIC_H__ */
