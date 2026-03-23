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
 *   - Chapter B3.4 - Nested Vectored Interrupt Controller, NVIC
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_NVIC_H__
#define __ARCH_ARM_V7M_NVIC_H__

#include &lt;stdint.h&gt;
#include &lt;stdbool.h&gt;
#include "armv7-m_config.h"

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

/*
 * ============================================================================
 * NVIC Register Definitions
 * NVIC 寄存器定义
 * ============================================================================
 */

/**
 * Interrupt Set Enable Registers (ISER[0-7])
 * 中断使能设置寄存器
 * Reference: Chapter B3.4 - Nested Vectored Interrupt Controller, NVIC
 */
#define NVIC_ISER_BASE            (NVIC_BASE_ADDR + 0x000)
#define NVIC_ISER(n)              (*(volatile uint32_t *)(NVIC_ISER_BASE + ((n) * 4)))

/**
 * Interrupt Clear Enable Registers (ICER[0-7])
 * 中断使能清除寄存器
 * Reference: Chapter B3.4 - Nested Vectored Interrupt Controller, NVIC
 */
#define NVIC_ICER_BASE            (NVIC_BASE_ADDR + 0x080)
#define NVIC_ICER(n)              (*(volatile uint32_t *)(NVIC_ICER_BASE + ((n) * 4)))

/**
 * Interrupt Set Pending Registers (ISPR[0-7])
 * 中断挂起设置寄存器
 * Reference: Chapter B3.4 - Nested Vectored Interrupt Controller, NVIC
 */
#define NVIC_ISPR_BASE            (NVIC_BASE_ADDR + 0x100)
#define NVIC_ISPR(n)              (*(volatile uint32_t *)(NVIC_ISPR_BASE + ((n) * 4)))

/**
 * Interrupt Clear Pending Registers (ICPR[0-7])
 * 中断挂起清除寄存器
 * Reference: Chapter B3.4 - Nested Vectored Interrupt Controller, NVIC
 */
#define NVIC_ICPR_BASE            (NVIC_BASE_ADDR + 0x180)
#define NVIC_ICPR(n)              (*(volatile uint32_t *)(NVIC_ICPR_BASE + ((n) * 4)))

/**
 * Interrupt Active Bit Registers (IABR[0-7])
 * 中断活动位寄存器
 * Reference: Chapter B3.4 - Nested Vectored Interrupt Controller, NVIC
 */
#define NVIC_IABR_BASE            (NVIC_BASE_ADDR + 0x200)
#define NVIC_IABR(n)              (*(volatile uint32_t *)(NVIC_IABR_BASE + ((n) * 4)))

/**
 * Interrupt Priority Registers (IPR[0-239])
 * 中断优先级寄存器
 * Reference: Chapter B3.4 - Nested Vectored Interrupt Controller, NVIC
 */
#define NVIC_IPR_BASE             (NVIC_BASE_ADDR + 0x300)
#define NVIC_IPR(n)               (*(volatile uint8_t *)(NVIC_IPR_BASE + (n)))

/*
 * ============================================================================
 * SCB (System Control Block) Register Definitions
 * 系统控制块寄存器定义
 * ============================================================================
 */

/**
 * CPUID Base Register
 * CPUID 基址寄存器
 * Reference: Chapter B4.1 - About the CPUID scheme
 */
#define SCB_CPUID                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x00))

/**
 * Interrupt Control and State Register (ICSR)
 * 中断控制和状态寄存器
 * Reference: Chapter B3 - System Address Map
 */
#define SCB_ICSR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x04))

/**
 * Vector Table Offset Register (VTOR)
 * 向量表偏移寄存器
 * Reference: Chapter B3 - System Address Map
 */
#define SCB_VTOR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x08))

/**
 * Application Interrupt and Reset Control Register (AIRCR)
 * 应用中断和复位控制寄存器
 * Reference: Chapter B3 - System Address Map
 */
#define SCB_AIRCR                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x0C))

/**
 * System Control Register (SCR)
 * 系统控制寄存器
 * Reference: Chapter B3 - System Address Map
 */
#define SCB_SCR                   (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x10))

/**
 * Configuration and Control Register (CCR)
 * 配置和控制寄存器
 * Reference: Chapter B3 - System Address Map
 */
#define SCB_CCR                   (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x14))

/**
 * System Handler Priority Registers (SHPR[0-2])
 * 系统处理程序优先级寄存器
 * Reference: Chapter B3 - System Address Map
 */
#define SCB_SHPR1                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x18))
#define SCB_SHPR2                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x1C))
#define SCB_SHPR3                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x20))

/**
 * System Handler Control and State Register (SHCSR)
 * 系统处理程序控制和状态寄存器
 * Reference: Chapter B3 - System Address Map
 */
#define SCB_SHCSR                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x24))

/**
 * Configurable Fault Status Register (CFSR)
 * 可配置故障状态寄存器
 * Reference: Chapter B3 - System Address Map
 */
#define SCB_CFSR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x28))

/**
 * HardFault Status Register (HFSR)
 * HardFault 状态寄存器
 * Reference: Chapter B3 - System Address Map
 */
#define SCB_HFSR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x2C))

/**
 * Debug Fault Status Register (DFSR)
 * 调试故障状态寄存器
 * Reference: Chapter B3 - System Address Map
 */
#define SCB_DFSR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x30))

/**
 * MemManage Fault Address Register (MMFAR)
 * 内存管理故障地址寄存器
 * Reference: Chapter B3 - System Address Map
 */
#define SCB_MMFAR                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x34))

/**
 * BusFault Address Register (BFAR)
 * 总线故障地址寄存器
 * Reference: Chapter B3 - System Address Map
 */
#define SCB_BFAR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x38))

/**
 * Auxiliary Fault Status Register (AFSR)
 * 辅助故障状态寄存器
 * Reference: Chapter B3 - System Address Map
 */
#define SCB_AFSR                  (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x3C))

/**
 * Processor Feature Register 0 (ID_PFR0)
 * 处理器特性寄存器0
 * Reference: Chapter B4 - The CPUID Scheme
 */
#define SCB_ID_PFR0               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x40))

/**
 * Processor Feature Register 1 (ID_PFR1)
 * 处理器特性寄存器1
 * Reference: Chapter B4 - The CPUID Scheme
 */
#define SCB_ID_PFR1               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x44))

/**
 * Debug Feature Register 0 (ID_DFR0)
 * 调试特性寄存器0
 * Reference: Chapter B4 - The CPUID Scheme
 */
#define SCB_ID_DFR0               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x48))

/**
 * Auxiliary Feature Register 0 (ID_AFR0)
 * 辅助特性寄存器0
 * Reference: Chapter B4 - The CPUID Scheme
 */
#define SCB_ID_AFR0               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x4C))

/**
 * Memory Model Feature Register 0 (ID_MMFR0)
 * 内存模型特性寄存器0
 * Reference: Chapter B4 - The CPUID Scheme
 */
#define SCB_ID_MMFR0              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x50))

/**
 * Memory Model Feature Register 1 (ID_MMFR1)
 * 内存模型特性寄存器1
 * Reference: Chapter B4 - The CPUID Scheme
 */
#define SCB_ID_MMFR1              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x54))

/**
 * Memory Model Feature Register 2 (ID_MMFR2)
 * 内存模型特性寄存器2
 * Reference: Chapter B4 - The CPUID Scheme
 */
#define SCB_ID_MMFR2              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x58))

/**
 * Memory Model Feature Register 3 (ID_MMFR3)
 * 内存模型特性寄存器3
 * Reference: Chapter B4 - The CPUID Scheme
 */
#define SCB_ID_MMFR3              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x5C))

/**
 * Instruction Set Attribute Register 0 (ID_ISAR0)
 * 指令集属性寄存器0
 * Reference: Chapter B4 - The CPUID Scheme
 */
#define SCB_ID_ISAR0              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x60))

/**
 * Instruction Set Attribute Register 1 (ID_ISAR1)
 * 指令集属性寄存器1
 * Reference: Chapter B4 - The CPUID Scheme
 */
#define SCB_ID_ISAR1              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x64))

/**
 * Instruction Set Attribute Register 2 (ID_ISAR2)
 * 指令集属性寄存器2
 * Reference: Chapter B4 - The CPUID Scheme
 */
#define SCB_ID_ISAR2              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x68))

/**
 * Instruction Set Attribute Register 3 (ID_ISAR3)
 * 指令集属性寄存器3
 * Reference: Chapter B4 - The CPUID Scheme
 */
#define SCB_ID_ISAR3              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x6C))

/**
 * Instruction Set Attribute Register 4 (ID_ISAR4)
 * 指令集属性寄存器4
 * Reference: Chapter B4 - The CPUID Scheme
 */
#define SCB_ID_ISAR4              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x70))

/**
 * Instruction Set Attribute Register 5 (ID_ISAR5)
 * 指令集属性寄存器5
 * Reference: Chapter B4 - The CPUID Scheme
 */
#define SCB_ID_ISAR5              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x74))

/**
 * Cache Level ID Register (CLIDR)
 * 缓存级别ID寄存器
 * Reference: Chapter B4 - The CPUID Scheme
 */
#define SCB_CLIDR                 (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x78))

/**
 * Cache Type Register (CTR)
 * 缓存类型寄存器
 * Reference: Chapter B4 - The CPUID Scheme
 */
#define SCB_CTR                   (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x7C))

/**
 * Cache Size ID Register (CCSIDR)
 * 缓存大小ID寄存器
 * Reference: Chapter B4 - The CPUID Scheme
 */
#define SCB_CCSIDR                (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x80))

/**
 * Cache Size Selection Register (CSSELR)
 * 缓存大小选择寄存器
 * Reference: Chapter B4 - The CPUID Scheme
 */
#define SCB_CSSELR                (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x84))

/**
 * Coprocessor Access Control Register (CPACR)
 * 协处理器访问控制寄存器
 * Reference: Chapter B4 - The CPUID Scheme
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
 */
#define SCB_ICSR_VECTACTIVE_Pos   0U
#define SCB_ICSR_VECTACTIVE_Msk  (0x1FFUL &lt;&lt; SCB_ICSR_VECTACTIVE_Pos)
#define SCB_ICSR_VECTACTIVE       SCB_ICSR_VECTACTIVE_Msk

#define SCB_ICSR_RETTOBASE_Pos    11U
#define SCB_ICSR_RETTOBASE_Msk   (1UL &lt;&lt; SCB_ICSR_RETTOBASE_Pos)
#define SCB_ICSR_RETTOBASE        SCB_ICSR_RETTOBASE_Msk

#define SCB_ICSR_VECTPENDING_Pos  12U
#define SCB_ICSR_VECTPENDING_Msk (0x1FFUL &lt;&lt; SCB_ICSR_VECTPENDING_Pos)
#define SCB_ICSR_VECTPENDING      SCB_ICSR_VECTPENDING_Msk

#define SCB_ICSR_ISRPENDING_Pos   22U
#define SCB_ICSR_ISRPENDING_Msk  (1UL &lt;&lt; SCB_ICSR_ISRPENDING_Pos)
#define SCB_ICSR_ISRPENDING       SCB_ICSR_ISRPENDING_Msk

#define SCB_ICSR_PENDSTCLR_Pos    25U
#define SCB_ICSR_PENDSTCLR_Msk   (1UL &lt;&lt; SCB_ICSR_PENDSTCLR_Pos)
#define SCB_ICSR_PENDSTCLR        SCB_ICSR_PENDSTCLR_Msk

#define SCB_ICSR_PENDSTSET_Pos    26U
#define SCB_ICSR_PENDSTSET_Msk   (1UL &lt;&lt; SCB_ICSR_PENDSTSET_Pos)
#define SCB_ICSR_PENDSTSET        SCB_ICSR_PENDSTSET_Msk

#define SCB_ICSR_PENDSVCLR_Pos    27U
#define SCB_ICSR_PENDSVCLR_Msk   (1UL &lt;&lt; SCB_ICSR_PENDSVCLR_Pos)
#define SCB_ICSR_PENDSVCLR        SCB_ICSR_PENDSVCLR_Msk

#define SCB_ICSR_PENDSVSET_Pos    28U
#define SCB_ICSR_PENDSVSET_Msk   (1UL &lt;&lt; SCB_ICSR_PENDSVSET_Pos)
#define SCB_ICSR_PENDSVSET        SCB_ICSR_PENDSVSET_Msk

#define SCB_ICSR_NMIPENDSET_Pos  31U
#define SCB_ICSR_NMIPENDSET_Msk  (1UL &lt;&lt; SCB_ICSR_NMIPENDSET_Pos)
#define SCB_ICSR_NMIPENDSET       SCB_ICSR_NMIPENDSET_Msk

/**
 * AIRCR (Application Interrupt and Reset Control Register) bit definitions
 */
#define SCB_AIRCR_VECTRESET_Pos   0U
#define SCB_AIRCR_VECTRESET_Msk  (1UL &lt;&lt; SCB_AIRCR_VECTRESET_Pos)
#define SCB_AIRCR_VECTRESET       SCB_AIRCR_VECTRESET_Msk

#define SCB_AIRCR_VECTCLRACTIVE_Pos  1U
#define SCB_AIRCR_VECTCLRACTIVE_Msk (1UL &lt;&lt; SCB_AIRCR_VECTCLRACTIVE_Pos)
#define SCB_AIRCR_VECTCLRACTIVE  SCB_AIRCR_VECTCLRACTIVE_Msk

#define SCB_AIRCR_SYSRESETREQ_Pos  2U
#define SCB_AIRCR_SYSRESETREQ_Msk (1UL &lt;&lt; SCB_AIRCR_SYSRESETREQ_Pos)
#define SCB_AIRCR_SYSRESETREQ    SCB_AIRCR_SYSRESETREQ_Msk

#define SCB_AIRCR_PRIGROUP_Pos   8U
#define SCB_AIRCR_PRIGROUP_Msk  (0x7UL &lt;&lt; SCB_AIRCR_PRIGROUP_Pos)
#define SCB_AIRCR_PRIGROUP       SCB_AIRCR_PRIGROUP_Msk

#define SCB_AIRCR_ENDIANESS_Pos  15U
#define SCB_AIRCR_ENDIANESS_Msk (1UL &lt;&lt; SCB_AIRCR_ENDIANESS_Pos)
#define SCB_AIRCR_ENDIANESS      SCB_AIRCR_ENDIANESS_Msk

#define SCB_AIRCR_VECTKEY_Pos    16U
#define SCB_AIRCR_VECTKEY_Msk   (0xFFFFUL &lt;&lt; SCB_AIRCR_VECTKEY_Pos)
#define SCB_AIRCR_VECTKEY        SCB_AIRCR_VECTKEY_Msk
#define SCB_AIRCR_VECTKEYSTAT    (0x5FAUL &lt;&lt; SCB_AIRCR_VECTKEY_Pos)

/**
 * SCR (System Control Register) bit definitions
 */
#define SCB_SCR_SLEEPONEXIT_Pos   1U
#define SCB_SCR_SLEEPONEXIT_Msk  (1UL &lt;&lt; SCB_SCR_SLEEPONEXIT_Pos)
#define SCB_SCR_SLEEPONEXIT       SCB_SCR_SLEEPONEXIT_Msk

#define SCB_SCR_SLEEPDEEP_Pos    2U
#define SCB_SCR_SLEEPDEEP_Msk   (1UL &lt;&lt; SCB_SCR_SLEEPDEEP_Pos)
#define SCB_SCR_SLEEPDEEP        SCB_SCR_SLEEPDEEP_Msk

#define SCB_SCR_SEVONPEND_Pos    4U
#define SCB_SCR_SEVONPEND_Msk   (1UL &lt;&lt; SCB_SCR_SEVONPEND_Pos)
#define SCB_SCR_SEVONPEND        SCB_SCR_SEVONPEND_Msk

/**
 * CCR (Configuration and Control Register) bit definitions
 */
#define SCB_CCR_NONBASETHRDENA_Pos  0U
#define SCB_CCR_NONBASETHRDENA_Msk (1UL &lt;&lt; SCB_CCR_NONBASETHRDENA_Pos)
#define SCB_CCR_NONBASETHRDENA  SCB_CCR_NONBASETHRDENA_Msk

#define SCB_CCR_USERSETMPEND_Pos  1U
#define SCB_CCR_USERSETMPEND_Msk (1UL &lt;&lt; SCB_CCR_USERSETMPEND_Pos)
#define SCB_CCR_USERSETMPEND     SCB_CCR_USERSETMPEND_Msk

#define SCB_CCR_UNALIGN_TRP_Pos  3U
#define SCB_CCR_UNALIGN_TRP_Msk (1UL &lt;&lt; SCB_CCR_UNALIGN_TRP_Pos)
#define SCB_CCR_UNALIGN_TRP      SCB_CCR_UNALIGN_TRP_Msk

#define SCB_CCR_DIV_0_TRP_Pos    4U
#define SCB_CCR_DIV_0_TRP_Msk   (1UL &lt;&lt; SCB_CCR_DIV_0_TRP_Pos)
#define SCB_CCR_DIV_0_TRP        SCB_CCR_DIV_0_TRP_Msk

#define SCB_CCR_BFHFNMIGN_Pos    8U
#define SCB_CCR_BFHFNMIGN_Msk   (1UL &lt;&lt; SCB_CCR_BFHFNMIGN_Pos)
#define SCB_CCR_BFHFNMIGN        SCB_CCR_BFHFNMIGN_Msk

#define SCB_CCR_STKALIGN_Pos     9U
#define SCB_CCR_STKALIGN_Msk    (1UL &lt;&lt; SCB_CCR_STKALIGN_Pos)
#define SCB_CCR_STKALIGN         SCB_CCR_STKALIGN_Msk

/*
 * ============================================================================
 * NVIC Function Declarations
 * NVIC 函数声明
 * ============================================================================
 */

/**
 * @brief Enable Interrupt
 * @param IRQn External interrupt number
 */
void NVIC_EnableIRQ(uint32_t IRQn);

/**
 * @brief Disable Interrupt
 * @param IRQn External interrupt number
 */
void NVIC_DisableIRQ(uint32_t IRQn);

/**
 * @brief Get Pending Interrupt
 * @param IRQn External interrupt number
 * @return 1 if interrupt pending
 */
uint32_t NVIC_GetPendingIRQ(uint32_t IRQn);

/**
 * @brief Set Pending Interrupt
 * @param IRQn External interrupt number
 */
void NVIC_SetPendingIRQ(uint32_t IRQn);

/**
 * @brief Clear Pending Interrupt
 * @param IRQn External interrupt number
 */
void NVIC_ClearPendingIRQ(uint32_t IRQn);

/**
 * @brief Get Active Interrupt
 * @param IRQn External interrupt number
 * @return 1 if interrupt active
 */
uint32_t NVIC_GetActive(uint32_t IRQn);

/**
 * @brief Set Interrupt Priority
 * @param IRQn External interrupt number
 * @param priority Priority to set
 */
void NVIC_SetPriority(uint32_t IRQn, uint32_t priority);

/**
 * @brief Get Interrupt Priority
 * @param IRQn External interrupt number
 * @return Interrupt priority
 */
uint32_t NVIC_GetPriority(uint32_t IRQn);

/**
 * @brief System Reset
 */
void NVIC_SystemReset(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_NVIC_H__ */
