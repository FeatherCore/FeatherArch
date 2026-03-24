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
 * - Interrupt enable/disable/pending functions
 * - Priority management functions
 *
 * SCB (System Control Block) definitions are provided by armv7-m_scb.h
 * which is included by this file for backward compatibility.
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter A2: Application Level Programmers' Model
 *     * A2.4 Exceptions, faults and interrupts (page A2-33)
 *       - A2.4.1 System-related events
 *       - NVIC controls external interrupts
 *       - PendSV for deferred supervisor calls
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
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_NVIC_H__
#define __ARCH_ARM_V7M_NVIC_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv7-m_config.h"
#include "armv7-m_scb.h"  /* Include SCB definitions */

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

/*
 * ============================================================================
 * Backward Compatibility: SCB Functions
 * 向后兼容: SCB 函数
 *
 * These functions are declared in armv7-m_scb.h and implemented in armv7-m_scb.c
 * They are available here for backward compatibility.
 * ============================================================================
 */

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

/* SCB system handler functions - declared in armv7-m_scb.h */
void scb_set_shpr(uint8_t handler, uint8_t priority);
uint8_t scb_get_shpr(uint8_t handler);
void scb_enable_system_handler(uint32_t handler);
void scb_disable_system_handler(uint32_t handler);
uint32_t scb_get_system_handler_pending(uint32_t handler);
void scb_set_system_handler_pending(uint32_t handler);
void scb_clear_system_handler_pending(uint32_t handler);

/* SCB fault status functions - declared in armv7-m_scb.h */
uint32_t scb_get_cfsr(void);
void scb_clear_cfsr(void);
uint32_t scb_get_hfsr(void);
void scb_clear_hfsr(void);
uint32_t scb_get_dfsr(void);
void scb_clear_dfsr(void);
uint32_t scb_get_mmfar(void);
uint32_t scb_get_bfar(void);
uint32_t scb_get_afsr(void);
void scb_set_afsr(uint32_t value);

/* SCB system control functions - declared in armv7-m_scb.h */
void scb_set_scr(uint32_t value);
uint32_t scb_get_scr(void);
void scb_set_ccr(uint32_t value);
uint32_t scb_get_ccr(void);
uint32_t scb_get_cpuid(void);
uint32_t scb_get_icsr(void);
void scb_set_icsr(uint32_t value);
void scb_set_cpacr(uint32_t cp10, uint32_t cp11);
uint32_t scb_get_cpacr(void);

/* SCB cache control functions - declared in armv7-m_scb.h */
uint32_t scb_get_clidr(void);
uint32_t scb_get_ctr(void);
uint32_t scb_get_ccsidr(void);
void scb_set_csselr(uint32_t value);
uint32_t scb_get_csselr(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_NVIC_H__ */
