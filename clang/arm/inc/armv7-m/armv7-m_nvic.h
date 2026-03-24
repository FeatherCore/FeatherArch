/*
 * ARM Architecture - ARMv7-M NVIC (Nested Vectored Interrupt Controller)
 *
 * ============================================================================
 * File: armv7-m_nvic.h
 * Description: ARMv7-M NVIC register definitions and function declarations
 * 描述: ARMv7-M NVIC 寄存器定义和函数声明
 *
 * This file provides definitions for the Nested Vectored Interrupt Controller:
 * - NVIC register definitions
 * - SCB (System Control Block) register definitions
 * - Interrupt enable/disable/pending functions
 * - Priority management functions
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter A2: Application Level Programmers' Model
 *     * A2.4 Exceptions, faults and interrupts (page A2-33)
 *       - A2.4.1 System-related events
 *       - NVIC controls external interrupts
 *       - PendSV for deferred supervisor calls
 *       - Reference: Chapter A2.3.4 Privileged execution (page A2-32)
 *         * All exceptions execute as privileged code in Handler mode
 *   - Chapter A3: Arm Architecture Memory Model
 *     * A3.1 Address space (page A3-64)
 *       - Memory-mapped NVIC registers in SCS (System Control Space)
 *   - Chapter A4: The Armv7-M Instruction Set
 *     * A4.3 Branch instructions (page A4-106)
 *       - Exception entry uses hardware stacking and vector fetch
 *     * A4.9 Exception-generating instructions (page A4-119)
 *       - SVC instruction for supervisor calls
 *       - BKPT instruction for breakpoints
 *   - Chapter B3.4 - Nested Vectored Interrupt Controller, NVIC
 *   - Table B3-4 Summary of SCB registers (page B3-596)
 *   - Table B3-6 Summary of system control and ID registers not in the SCB (page B3-597)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_NVIC_H__
#define __ARCH_ARM_V7M_NVIC_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv7-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * NVIC Base Addresses
 * NVIC 基地址
 * Reference: Table B3-3 SCS address space regions (page B3-595)
 * ============================================================================
 */

#define SCS_BASE_ADDR             0xE000E000UL
#define NVIC_BASE_ADDR            0xE000E100UL
#define SCB_BASE_ADDR             0xE000ED00UL

/*
 * ============================================================================
 * System Control and ID Registers (not in SCB)
 * 系统控制和ID寄存器 (不在SCB中)
 * Reference: Table B3-6 Summary of system control and ID registers not in the SCB
 * ============================================================================
 */

/**
 * Interrupt Controller Type Register (ICTR)
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-618
 */
#define SCS_ICTR                  (*(volatile uint32_t *)(SCS_BASE_ADDR + 0x004))

/**
 * Auxiliary Control Register (ACTLR)
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-618
 */
#define SCS_ACTLR                 (*(volatile uint32_t *)(SCS_BASE_ADDR + 0x008))

/**
 * Software Triggered Interrupt Register (STIR)
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-619
 */
#define SCS_STIR                  (*(volatile uint32_t *)(0xE000EF00UL))

/*
 * ============================================================================
 * NVIC Register Definitions
 * NVIC 寄存器定义
 * Reference: Chapter B3.4 - Nested Vectored Interrupt Controller, NVIC
 * ============================================================================
 */

/**
 * Interrupt Set Enable Registers (NVIC_ISER0-NVIC_ISER15)
 * 中断使能设置寄存器
 * Address: 0xE000E100-0xE000E13C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-628
 */
#define NVIC_ISER_BASE            (NVIC_BASE_ADDR + 0x000)
#define NVIC_ISER(n)              (*(volatile uint32_t *)(NVIC_ISER_BASE + ((n) * 4)))

/**
 * Interrupt Clear Enable Registers (NVIC_ICER0-NVIC_ICER15)
 * 中断使能清除寄存器
 * Address: 0xE000E180-0xE000E1BC
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-629
 */
#define NVIC_ICER_BASE            (NVIC_BASE_ADDR + 0x080)
#define NVIC_ICER(n)              (*(volatile uint32_t *)(NVIC_ICER_BASE + ((n) * 4)))

/**
 * Interrupt Set Pending Registers (NVIC_ISPR0-NVIC_ISPR15)
 * 中断挂起设置寄存器
 * Address: 0xE000E200-0xE000E23C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-629
 */
#define NVIC_ISPR_BASE            (NVIC_BASE_ADDR + 0x100)
#define NVIC_ISPR(n)              (*(volatile uint32_t *)(NVIC_ISPR_BASE + ((n) * 4)))

/**
 * Interrupt Clear Pending Registers (NVIC_ICPR0-NVIC_ICPR15)
 * 中断挂起清除寄存器
 * Address: 0xE000E280-0xE000E2BC
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-630
 */
#define NVIC_ICPR_BASE            (NVIC_BASE_ADDR + 0x180)
#define NVIC_ICPR(n)              (*(volatile uint32_t *)(NVIC_ICPR_BASE + ((n) * 4)))

/**
 * Interrupt Active Bit Registers (NVIC_IABR0-NVIC_IABR15)
 * 中断活动位寄存器
 * Address: 0xE000E300-0xE000E33C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-630
 */
#define NVIC_IABR_BASE            (NVIC_BASE_ADDR + 0x200)
#define NVIC_IABR(n)              (*(volatile uint32_t *)(NVIC_IABR_BASE + ((n) * 4)))

/**
 * Interrupt Priority Registers (NVIC_IPR0-NVIC_IPR59)
 * 中断优先级寄存器
 * Address: 0xE000E400-0xE000E4EC
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-631
 */
#define NVIC_IPR_BASE             (NVIC_BASE_ADDR + 0x300)
#define NVIC_IPR(n)               (*(volatile uint8_t *)(NVIC_IPR_BASE + (n)))

/*
 * ============================================================================
 * SCB (System Control Block) Register Definitions
 * 系统控制块寄存器定义
 * Reference: Table B3-4 Summary of SCB registers (page B3-596)
 * ============================================================================
 */

/**
 * CPUID Base Register
 * Address: 0xE000ED00
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-598
 */
#define SCB_CPUID                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x00))

/**
 * Interrupt Control and State Register (ICSR)
 * Address: 0xE000ED04
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-599
 */
#define SCB_ICSR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x04))

/**
 * Vector Table Offset Register (VTOR)
 * Address: 0xE000ED08
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-601
 */
#define SCB_VTOR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x08))

/**
 * Application Interrupt and Reset Control Register (AIRCR)
 * Address: 0xE000ED0C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-601
 */
#define SCB_AIRCR                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x0C))

/**
 * System Control Register (SCR)
 * Address: 0xE000ED10
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-603
 */
#define SCB_SCR                   (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x10))

/**
 * Configuration and Control Register (CCR)
 * Address: 0xE000ED14
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-604
 */
#define SCB_CCR                   (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x14))

/**
 * System Handler Priority Register 1 (SHPR1)
 * Address: 0xE000ED18
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-606
 */
#define SCB_SHPR1                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x18))

/**
 * System Handler Priority Register 2 (SHPR2)
 * Address: 0xE000ED1C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-606
 */
#define SCB_SHPR2                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x1C))

/**
 * System Handler Priority Register 3 (SHPR3)
 * Address: 0xE000ED20
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-607
 */
#define SCB_SHPR3                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x20))

/**
 * System Handler Control and State Register (SHCSR)
 * Address: 0xE000ED24
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-607
 */
#define SCB_SHCSR                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x24))

/**
 * Configurable Fault Status Register (CFSR)
 * Address: 0xE000ED28
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-609
 */
#define SCB_CFSR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x28))

/**
 * HardFault Status Register (HFSR)
 * Address: 0xE000ED2C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-612
 */
#define SCB_HFSR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x2C))

/**
 * Debug Fault Status Register (DFSR)
 * Address: 0xE000ED30
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-699
 */
#define SCB_DFSR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x30))

/**
 * MemManage Fault Address Register (MMFAR)
 * Address: 0xE000ED34
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-613
 */
#define SCB_MMFAR                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x34))

/**
 * BusFault Address Register (BFAR)
 * Address: 0xE000ED38
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-614
 */
#define SCB_BFAR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x38))

/**
 * Auxiliary Fault Status Register (AFSR)
 * Address: 0xE000ED3C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-614
 */
#define SCB_AFSR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x3C))

/**
 * Processor Feature Register 0 (ID_PFR0)
 * Address: 0xE000ED40
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-646
 */
#define SCB_ID_PFR0               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x40))

/**
 * Processor Feature Register 1 (ID_PFR1)
 * Address: 0xE000ED44
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-646
 */
#define SCB_ID_PFR1               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x44))

/**
 * Debug Feature Register 0 (ID_DFR0)
 * Address: 0xE000ED48
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-648
 */
#define SCB_ID_DFR0               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x48))

/**
 * Auxiliary Feature Register 0 (ID_AFR0)
 * Address: 0xE000ED4C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-649
 */
#define SCB_ID_AFR0               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x4C))

/**
 * Memory Model Feature Register 0 (ID_MMFR0)
 * Address: 0xE000ED50
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-650
 */
#define SCB_ID_MMFR0              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x50))

/**
 * Memory Model Feature Register 1 (ID_MMFR1)
 * Address: 0xE000ED54
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-650
 */
#define SCB_ID_MMFR1              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x54))

/**
 * Memory Model Feature Register 2 (ID_MMFR2)
 * Address: 0xE000ED58
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-650
 */
#define SCB_ID_MMFR2              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x58))

/**
 * Memory Model Feature Register 3 (ID_MMFR3)
 * Address: 0xE000ED5C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-650
 */
#define SCB_ID_MMFR3              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x5C))

/**
 * Instruction Set Attribute Register 0 (ID_ISAR0)
 * Address: 0xE000ED60
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-653
 */
#define SCB_ID_ISAR0              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x60))

/**
 * Instruction Set Attribute Register 1 (ID_ISAR1)
 * Address: 0xE000ED64
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-653
 */
#define SCB_ID_ISAR1              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x64))

/**
 * Instruction Set Attribute Register 2 (ID_ISAR2)
 * Address: 0xE000ED68
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-653
 */
#define SCB_ID_ISAR2              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x68))

/**
 * Instruction Set Attribute Register 3 (ID_ISAR3)
 * Address: 0xE000ED6C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-653
 */
#define SCB_ID_ISAR3              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x6C))

/**
 * Instruction Set Attribute Register 4 (ID_ISAR4)
 * Address: 0xE000ED70
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-653
 */
#define SCB_ID_ISAR4              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x70))

/**
 * Cache Level ID Register (CLIDR)
 * Address: 0xE000ED78
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-665
 */
#define SCB_CLIDR                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x78))

/**
 * Cache Type Register (CTR)
 * Address: 0xE000ED7C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-665
 */
#define SCB_CTR                   (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x7C))

/**
 * Cache Size ID Register (CCSIDR)
 * Address: 0xE000ED80
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-665
 */
#define SCB_CCSIDR                (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x80))

/**
 * Cache Size Selection Register (CSSELR)
 * Address: 0xE000ED84
 * Reference: Arm(R) v7-M Architecture Reference Manual, B4-665
 */
#define SCB_CSSELR                (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x84))

/**
 * Coprocessor Access Control Register (CPACR)
 * Address: 0xE000ED88
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-614
 */
#define SCB_CPACR                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x88))

/*
 * ============================================================================
 * SCB Register Bit Definitions
 * SCB 寄存器位定义
 * ============================================================================
 */

/**
 * ICSR (Interrupt Control and State Register) bit definitions
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-599
 */
#define SCB_ICSR_VECTACTIVE_Pos   0U
#define SCB_ICSR_VECTACTIVE_Msk  (0x1FFUL << SCB_ICSR_VECTACTIVE_Pos)
#define SCB_ICSR_VECTACTIVE       SCB_ICSR_VECTACTIVE_Msk

#define SCB_ICSR_RETTOBASE_Pos    11U
#define SCB_ICSR_RETTOBASE_Msk   (1UL << SCB_ICSR_RETTOBASE_Pos)
#define SCB_ICSR_RETTOBASE        SCB_ICSR_RETTOBASE_Msk

#define SCB_ICSR_VECTPENDING_Pos  12U
#define SCB_ICSR_VECTPENDING_Msk (0x1FFUL << SCB_ICSR_VECTPENDING_Pos)
#define SCB_ICSR_VECTPENDING      SCB_ICSR_VECTPENDING_Msk

#define SCB_ICSR_ISRPENDING_Pos   22U
#define SCB_ICSR_ISRPENDING_Msk  (1UL << SCB_ICSR_ISRPENDING_Pos)
#define SCB_ICSR_ISRPENDING       SCB_ICSR_ISRPENDING_Msk

#define SCB_ICSR_PENDSTCLR_Pos    25U
#define SCB_ICSR_PENDSTCLR_Msk   (1UL << SCB_ICSR_PENDSTCLR_Pos)
#define SCB_ICSR_PENDSTCLR        SCB_ICSR_PENDSTCLR_Msk

#define SCB_ICSR_PENDSTSET_Pos    26U
#define SCB_ICSR_PENDSTSET_Msk   (1UL << SCB_ICSR_PENDSTSET_Pos)
#define SCB_ICSR_PENDSTSET        SCB_ICSR_PENDSTSET_Msk

#define SCB_ICSR_PENDSVCLR_Pos    27U
#define SCB_ICSR_PENDSVCLR_Msk   (1UL << SCB_ICSR_PENDSVCLR_Pos)
#define SCB_ICSR_PENDSVCLR        SCB_ICSR_PENDSVCLR_Msk

#define SCB_ICSR_PENDSVSET_Pos    28U
#define SCB_ICSR_PENDSVSET_Msk   (1UL << SCB_ICSR_PENDSVSET_Pos)
#define SCB_ICSR_PENDSVSET        SCB_ICSR_PENDSVSET_Msk

#define SCB_ICSR_NMIPENDSET_Pos  31U
#define SCB_ICSR_NMIPENDSET_Msk  (1UL << SCB_ICSR_NMIPENDSET_Pos)
#define SCB_ICSR_NMIPENDSET       SCB_ICSR_NMIPENDSET_Msk

/**
 * AIRCR (Application Interrupt and Reset Control Register) bit definitions
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-601
 */
#define SCB_AIRCR_VECTRESET_Pos   0U
#define SCB_AIRCR_VECTRESET_Msk  (1UL << SCB_AIRCR_VECTRESET_Pos)
#define SCB_AIRCR_VECTRESET       SCB_AIRCR_VECTRESET_Msk

#define SCB_AIRCR_VECTCLRACTIVE_Pos  1U
#define SCB_AIRCR_VECTCLRACTIVE_Msk (1UL << SCB_AIRCR_VECTCLRACTIVE_Pos)
#define SCB_AIRCR_VECTCLRACTIVE  SCB_AIRCR_VECTCLRACTIVE_Msk

#define SCB_AIRCR_SYSRESETREQ_Pos  2U
#define SCB_AIRCR_SYSRESETREQ_Msk (1UL << SCB_AIRCR_SYSRESETREQ_Pos)
#define SCB_AIRCR_SYSRESETREQ    SCB_AIRCR_SYSRESETREQ_Msk

#define SCB_AIRCR_PRIGROUP_Pos   8U
#define SCB_AIRCR_PRIGROUP_Msk  (0x7UL << SCB_AIRCR_PRIGROUP_Pos)
#define SCB_AIRCR_PRIGROUP       SCB_AIRCR_PRIGROUP_Msk

#define SCB_AIRCR_ENDIANESS_Pos  15U
#define SCB_AIRCR_ENDIANESS_Msk (1UL << SCB_AIRCR_ENDIANESS_Pos)
#define SCB_AIRCR_ENDIANESS      SCB_AIRCR_ENDIANESS_Msk

#define SCB_AIRCR_VECTKEY_Pos    16U
#define SCB_AIRCR_VECTKEY_Msk   (0xFFFFUL << SCB_AIRCR_VECTKEY_Pos)
#define SCB_AIRCR_VECTKEY        SCB_AIRCR_VECTKEY_Msk
#define SCB_AIRCR_VECTKEYSTAT    (0x5FAUL << SCB_AIRCR_VECTKEY_Pos)
#define SCB_AIRCR_VECTKEY_VALUE  (0x5FAUL << SCB_AIRCR_VECTKEY_Pos)

/**
 * SCR (System Control Register) bit definitions
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-603
 */
#define SCB_SCR_SLEEPONEXIT_Pos   1U
#define SCB_SCR_SLEEPONEXIT_Msk  (1UL << SCB_SCR_SLEEPONEXIT_Pos)
#define SCB_SCR_SLEEPONEXIT       SCB_SCR_SLEEPONEXIT_Msk

#define SCB_SCR_SLEEPDEEP_Pos    2U
#define SCB_SCR_SLEEPDEEP_Msk   (1UL << SCB_SCR_SLEEPDEEP_Pos)
#define SCB_SCR_SLEEPDEEP        SCB_SCR_SLEEPDEEP_Msk

#define SCB_SCR_SEVONPEND_Pos    4U
#define SCB_SCR_SEVONPEND_Msk   (1UL << SCB_SCR_SEVONPEND_Pos)
#define SCB_SCR_SEVONPEND        SCB_SCR_SEVONPEND_Msk

/**
 * CCR (Configuration and Control Register) bit definitions
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-604
 */
#define SCB_CCR_NONBASETHRDENA_Pos  0U
#define SCB_CCR_NONBASETHRDENA_Msk (1UL << SCB_CCR_NONBASETHRDENA_Pos)
#define SCB_CCR_NONBASETHRDENA  SCB_CCR_NONBASETHRDENA_Msk

#define SCB_CCR_USERSETMPEND_Pos  1U
#define SCB_CCR_USERSETMPEND_Msk (1UL << SCB_CCR_USERSETMPEND_Pos)
#define SCB_CCR_USERSETMPEND     SCB_CCR_USERSETMPEND_Msk

#define SCB_CCR_UNALIGN_TRP_Pos  3U
#define SCB_CCR_UNALIGN_TRP_Msk (1UL << SCB_CCR_UNALIGN_TRP_Pos)
#define SCB_CCR_UNALIGN_TRP      SCB_CCR_UNALIGN_TRP_Msk

#define SCB_CCR_DIV_0_TRP_Pos    4U
#define SCB_CCR_DIV_0_TRP_Msk   (1UL << SCB_CCR_DIV_0_TRP_Pos)
#define SCB_CCR_DIV_0_TRP        SCB_CCR_DIV_0_TRP_Msk

#define SCB_CCR_BFHFNMIGN_Pos    8U
#define SCB_CCR_BFHFNMIGN_Msk   (1UL << SCB_CCR_BFHFNMIGN_Pos)
#define SCB_CCR_BFHFNMIGN        SCB_CCR_BFHFNMIGN_Msk

#define SCB_CCR_STKALIGN_Pos     9U
#define SCB_CCR_STKALIGN_Msk    (1UL << SCB_CCR_STKALIGN_Pos)
#define SCB_CCR_STKALIGN         SCB_CCR_STKALIGN_Msk

#define SCB_CCR_DC_Pos          16U
#define SCB_CCR_DC_Msk          (1UL << SCB_CCR_DC_Pos)
#define SCB_CCR_DC              SCB_CCR_DC_Msk

#define SCB_CCR_IC_Pos          17U
#define SCB_CCR_IC_Msk          (1UL << SCB_CCR_IC_Pos)
#define SCB_CCR_IC              SCB_CCR_IC_Msk

#define SCB_CCR_BP_Pos          18U
#define SCB_CCR_BP_Msk          (1UL << SCB_CCR_BP_Pos)
#define SCB_CCR_BP              SCB_CCR_BP_Msk

/*
 * ============================================================================
 * NVIC Function Declarations
 * NVIC 函数声明
 * ============================================================================
 */

/**
 * @brief Enable specified interrupt
 * @param irq Interrupt number (0 to __ARM_NUM_INTERRUPTS-1)
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - ISER register
 */
void nvic_enable_irq(uint8_t irq);

/**
 * @brief Disable specified interrupt
 * @param irq Interrupt number
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - ICER register
 */
void nvic_disable_irq(uint8_t irq);

/**
 * @brief Get interrupt enable status
 * @param irq Interrupt number
 * @return 1 if enabled, 0 if disabled
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - ISER register
 */
uint32_t nvic_get_enable_irq(uint8_t irq);

/**
 * @brief Set interrupt pending status
 * @param irq Interrupt number
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - ISPR register
 */
void nvic_set_pending(uint8_t irq);

/**
 * @brief Clear interrupt pending status
 * @param irq Interrupt number
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - ICPR register
 */
void nvic_clear_pending(uint8_t irq);

/**
 * @brief Get interrupt pending status
 * @param irq Interrupt number
 * @return 1 if pending, 0 if not pending
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - ISPR register
 */
uint32_t nvic_get_pending(uint8_t irq);

/**
 * @brief Get active interrupt status
 * @param irq Interrupt number
 * @return 1 if active, 0 if not active
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - IABR register
 */
uint32_t nvic_get_active(uint8_t irq);

/**
 * @brief Set interrupt priority
 * @param irq Interrupt number
 * @param priority Priority value (0=highest, 255=lowest)
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - IPR register
 */
void nvic_set_priority(uint8_t irq, uint8_t priority);

/**
 * @brief Get interrupt priority
 * @param irq Interrupt number
 * @return Priority value
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - IPR register
 */
uint8_t nvic_get_priority(uint8_t irq);

/**
 * @brief Set priority grouping
 * @param priority_group Priority grouping value (0-7)
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - AIRCR register
 */
void nvic_set_priority_grouping(uint32_t priority_group);

/**
 * @brief Get priority grouping
 * @return Priority grouping value
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - AIRCR register
 */
uint32_t nvic_get_priority_grouping(void);

/**
 * @brief Encode priority
 * @param priority_group Priority grouping
 * @param preempt_priority Preemption priority
 * @param sub_priority Sub-priority
 * @return Encoded priority value
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller)
 */
uint32_t nvic_encode_priority(uint32_t priority_group, uint32_t preempt_priority, uint32_t sub_priority);

/**
 * @brief Decode priority
 * @param priority Encoded priority
 * @param priority_group Priority grouping
 * @param preempt_priority Output preemption priority
 * @param sub_priority Output sub-priority
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller)
 */
void nvic_decode_priority(uint32_t priority, uint32_t priority_group, uint32_t *preempt_priority, uint32_t *sub_priority);

/**
 * @brief System reset
 * Reference: Arm(R) v7-M ARM Chapter B1.5 (Resets) - AIRCR register
 */
void nvic_system_reset(void);

/**
 * @brief Set vector table offset
 * @param offset Vector table offset address
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - VTOR register
 */
void scb_set_vtor(uint32_t offset);

/**
 * @brief Get vector table offset
 * @return Vector table offset address
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - VTOR register
 */
uint32_t scb_get_vtor(void);

/*
 * ============================================================================
 * SCB System Handler Functions
 * SCB 系统处理函数声明
 * Reference: Chapter B3.2 - System Control Space (SCS)
 * ============================================================================
 */

/**
 * @brief Set system handler priority
 * @param handler System handler number (0-15)
 * @param priority Priority value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - SHPR registers
 */
void scb_set_shpr(uint8_t handler, uint8_t priority);

/**
 * @brief Get system handler priority
 * @param handler System handler number (0-15)
 * @return Priority value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - SHPR registers
 */
uint8_t scb_get_shpr(uint8_t handler);

/**
 * @brief Enable system handler
 * @param handler System handler to enable
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - SHCSR register
 */
void scb_enable_system_handler(uint32_t handler);

/**
 * @brief Disable system handler
 * @param handler System handler to disable
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - SHCSR register
 */
void scb_disable_system_handler(uint32_t handler);

/**
 * @brief Get system handler pending status
 * @param handler System handler
 * @return 1 if pending, 0 otherwise
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - SHCSR register
 */
uint32_t scb_get_system_handler_pending(uint32_t handler);

/**
 * @brief Set system handler pending
 * @param handler System handler
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - ICSR register
 */
void scb_set_system_handler_pending(uint32_t handler);

/**
 * @brief Clear system handler pending
 * @param handler System handler
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - ICSR register
 */
void scb_clear_system_handler_pending(uint32_t handler);

/*
 * ============================================================================
 * SCB Fault Status Functions
 * SCB 故障状态函数声明
 * Reference: Chapter B3.2 - System Control Space (SCS)
 * ============================================================================
 */

/**
 * @brief Get Configurable Fault Status Register
 * @return CFSR value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - CFSR register
 */
uint32_t scb_get_cfsr(void);

/**
 * @brief Clear Configurable Fault Status Register
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - CFSR register
 */
void scb_clear_cfsr(void);

/**
 * @brief Get HardFault Status Register
 * @return HFSR value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - HFSR register
 */
uint32_t scb_get_hfsr(void);

/**
 * @brief Clear HardFault Status Register
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - HFSR register
 */
void scb_clear_hfsr(void);

/**
 * @brief Get Debug Fault Status Register
 * @return DFSR value
 * Reference: Arm(R) v7-M ARM Chapter C1.6 (Debug) - DFSR register
 */
uint32_t scb_get_dfsr(void);

/**
 * @brief Clear Debug Fault Status Register
 * Reference: Arm(R) v7-M ARM Chapter C1.6 (Debug) - DFSR register
 */
void scb_clear_dfsr(void);

/**
 * @brief Get MemManage Fault Address Register
 * @return MMFAR value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - MMFAR register
 */
uint32_t scb_get_mmfar(void);

/**
 * @brief Get BusFault Address Register
 * @return BFAR value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - BFAR register
 */
uint32_t scb_get_bfar(void);

/**
 * @brief Get Auxiliary Fault Status Register
 * @return AFSR value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - AFSR register
 */
uint32_t scb_get_afsr(void);

/**
 * @brief Set Auxiliary Fault Status Register
 * @param value Value to write
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - AFSR register
 */
void scb_set_afsr(uint32_t value);

/*
 * ============================================================================
 * SCB System Control Functions
 * SCB 系统控制函数声明
 * Reference: Chapter B3.2 - System Control Space (SCS)
 * ============================================================================
 */

/**
 * @brief Set system control register
 * @param value SCR value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - SCR register
 */
void scb_set_scr(uint32_t value);

/**
 * @brief Get system control register
 * @return SCR value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - SCR register
 */
uint32_t scb_get_scr(void);

/**
 * @brief Set configuration and control register
 * @param value CCR value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - CCR register
 */
void scb_set_ccr(uint32_t value);

/**
 * @brief Get configuration and control register
 * @return CCR value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - CCR register
 */
uint32_t scb_get_ccr(void);

/**
 * @brief Get CPUID register
 * @return CPUID value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - CPUID register
 */
uint32_t scb_get_cpuid(void);

/**
 * @brief Get Interrupt Control and State Register
 * @return ICSR value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - ICSR register
 */
uint32_t scb_get_icsr(void);

/**
 * @brief Set Interrupt Control and State Register
 * @param value ICSR value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - ICSR register
 */
void scb_set_icsr(uint32_t value);

/**
 * @brief Set coprocessor access control
 * @param cp10 CP10 access value (0-3)
 * @param cp11 CP11 access value (0-3)
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - CPACR register
 */
void scb_set_cpacr(uint32_t cp10, uint32_t cp11);

/**
 * @brief Get coprocessor access control
 * @return CPACR value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - CPACR register
 */
uint32_t scb_get_cpacr(void);

/*
 * ============================================================================
 * SCB Cache Control Functions
 * SCB 缓存控制函数声明
 * Reference: Chapter B3.2 - System Control Space (SCS)
 * ============================================================================
 */

/**
 * @brief Get Cache Level ID Register
 * @return CLIDR value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - CLIDR register
 */
uint32_t scb_get_clidr(void);

/**
 * @brief Get Cache Type Register
 * @return CTR value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - CTR register
 */
uint32_t scb_get_ctr(void);

/**
 * @brief Get Cache Size ID Register
 * @return CCSIDR value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - CCSIDR register
 */
uint32_t scb_get_ccsidr(void);

/**
 * @brief Set Cache Size Selection Register
 * @param value CSSELR value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - CSSELR register
 */
void scb_set_csselr(uint32_t value);

/**
 * @brief Get Cache Size Selection Register
 * @return CSSELR value
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - CSSELR register
 */
uint32_t scb_get_csselr(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_NVIC_H__ */
