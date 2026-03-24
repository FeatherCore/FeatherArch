/*
 * ARM Architecture - Cortex-M4 NVIC (Nested Vectored Interrupt Controller)
 *
 * ============================================================================
 * File: cm4_nvic.h
 * Description: Cortex-M4 NVIC register definitions
 * 描述: Cortex-M4 NVIC 寄存器定义
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.2 Nested Vectored Interrupt Controller (page 4-3)
 *   - Table 4-1 NVIC registers summary (page 4-3)
 *   - Table 4-2 NVIC register map (page 4-3)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_NVIC_H__
#define __CM4_NVIC_H__

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * NVIC Base Address
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-2 (page 4-3)
 * ============================================================================
 */

#define CM4_NVIC_BASE_ADDR            0xE000E100UL

/*
 * ============================================================================
 * Interrupt Controller Type Register (ICTR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 6-1 (page 6-62), Table 6-2 (page 6-63)
 * Address: 0xE000E004
 * ============================================================================
 */

#define NVIC_ICTR                     (*(volatile uint32_t *)(0xE000E004UL))

/* ICTR bit definitions - Reference: Table 6-2 (page 6-63) */
#define NVIC_ICTR_INTLINESNUM_Pos     0U
#define NVIC_ICTR_INTLINESNUM_Msk     (0xFUL << NVIC_ICTR_INTLINESNUM_Pos)

/* ICTR INTLINESNUM values - Reference: Table 6-2 (page 6-63) */
#define NVIC_ICTR_INTLINESNUM_32      0x0UL
#define NVIC_ICTR_INTLINESNUM_64      0x1UL
#define NVIC_ICTR_INTLINESNUM_96      0x2UL
#define NVIC_ICTR_INTLINESNUM_128     0x3UL
#define NVIC_ICTR_INTLINESNUM_160     0x4UL
#define NVIC_ICTR_INTLINESNUM_192     0x5UL
#define NVIC_ICTR_INTLINESNUM_224     0x6UL
#define NVIC_ICTR_INTLINESNUM_240     0x7UL

/*
 * ============================================================================
 * Interrupt Set-Enable Registers (NVIC_ISER0-NVIC_ISER7)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-2 (page 4-3)
 * Address: 0xE000E100-0xE000E11C
 * ============================================================================
 */

#define NVIC_ISER0                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x000))
#define NVIC_ISER1                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x004))
#define NVIC_ISER2                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x008))
#define NVIC_ISER3                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x00C))
#define NVIC_ISER4                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x010))
#define NVIC_ISER5                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x014))
#define NVIC_ISER6                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x018))
#define NVIC_ISER7                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x01C))

/*
 * ============================================================================
 * Interrupt Clear-Enable Registers (NVIC_ICER0-NVIC_ICER7)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-2 (page 4-3)
 * Address: 0xE000E180-0xE000E19C
 * ============================================================================
 */

#define NVIC_ICER0                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x080))
#define NVIC_ICER1                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x084))
#define NVIC_ICER2                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x088))
#define NVIC_ICER3                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x08C))
#define NVIC_ICER4                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x090))
#define NVIC_ICER5                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x094))
#define NVIC_ICER6                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x098))
#define NVIC_ICER7                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x09C))

/*
 * ============================================================================
 * Interrupt Set-Pending Registers (NVIC_ISPR0-NVIC_ISPR7)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-2 (page 4-3)
 * Address: 0xE000E200-0xE000E21C
 * ============================================================================
 */

#define NVIC_ISPR0                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x100))
#define NVIC_ISPR1                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x104))
#define NVIC_ISPR2                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x108))
#define NVIC_ISPR3                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x10C))
#define NVIC_ISPR4                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x110))
#define NVIC_ISPR5                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x114))
#define NVIC_ISPR6                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x118))
#define NVIC_ISPR7                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x11C))

/*
 * ============================================================================
 * Interrupt Clear-Pending Registers (NVIC_ICPR0-NVIC_ICPR7)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-2 (page 4-3)
 * Address: 0xE000E280-0xE000E29C
 * ============================================================================
 */

#define NVIC_ICPR0                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x180))
#define NVIC_ICPR1                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x184))
#define NVIC_ICPR2                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x188))
#define NVIC_ICPR3                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x18C))
#define NVIC_ICPR4                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x190))
#define NVIC_ICPR5                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x194))
#define NVIC_ICPR6                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x198))
#define NVIC_ICPR7                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x19C))

/*
 * ============================================================================
 * Interrupt Active Bit Registers (NVIC_IABR0-NVIC_IABR7)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-2 (page 4-3)
 * Address: 0xE000E300-0xE000E31C
 * ============================================================================
 */

#define NVIC_IABR0                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x200))
#define NVIC_IABR1                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x204))
#define NVIC_IABR2                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x208))
#define NVIC_IABR3                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x20C))
#define NVIC_IABR4                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x210))
#define NVIC_IABR5                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x214))
#define NVIC_IABR6                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x218))
#define NVIC_IABR7                    (*(volatile uint32_t *)(CM4_NVIC_BASE_ADDR + 0x21C))

/*
 * ============================================================================
 * Interrupt Priority Registers (NVIC_IPR0-NVIC_IPR59)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-2 (page 4-3)
 * Address: 0xE000E400-0xE000E4EC
 * ============================================================================
 */

#define NVIC_IPR_BASE                 (CM4_NVIC_BASE_ADDR + 0x300)
#define NVIC_IPR(n)                   (*(volatile uint8_t *)(NVIC_IPR_BASE + (n)))

/*
 * ============================================================================
 * Software Triggered Interrupt Register (STIR)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-2 (page 4-3)
 * Address: 0xE000EF00
 * ============================================================================
 */

#define NVIC_STIR                     (*(volatile uint32_t *)(0xE000EF00UL))

/*
 * ============================================================================
 * NVIC Function Declarations
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 * ============================================================================
 */

/**
 * @brief Enable specified interrupt
 * @param irq Interrupt number (0-239)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
void cm4_nvic_enable_irq(uint32_t irq);

/**
 * @brief Disable specified interrupt
 * @param irq Interrupt number
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
void cm4_nvic_disable_irq(uint32_t irq);

/**
 * @brief Get interrupt enable status
 * @param irq Interrupt number
 * @return 1 if enabled, 0 if disabled
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
uint32_t cm4_nvic_get_enable_irq(uint32_t irq);

/**
 * @brief Set interrupt pending status
 * @param irq Interrupt number
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
void cm4_nvic_set_pending(uint32_t irq);

/**
 * @brief Clear interrupt pending status
 * @param irq Interrupt number
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
void cm4_nvic_clear_pending(uint32_t irq);

/**
 * @brief Get interrupt pending status
 * @param irq Interrupt number
 * @return 1 if pending, 0 if not pending
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
uint32_t cm4_nvic_get_pending(uint32_t irq);

/**
 * @brief Get active interrupt status
 * @param irq Interrupt number
 * @return 1 if active, 0 if not active
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
uint32_t cm4_nvic_get_active(uint32_t irq);

/**
 * @brief Set interrupt priority
 * @param irq Interrupt number
 * @param priority Priority value (0-255, lower is higher priority)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
void cm4_nvic_set_priority(uint32_t irq, uint32_t priority);

/**
 * @brief Get interrupt priority
 * @param irq Interrupt number
 * @return Priority value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
uint32_t cm4_nvic_get_priority(uint32_t irq);

/**
 * @brief Trigger interrupt by software
 * @param irq Interrupt number
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
void cm4_nvic_trigger_irq(uint32_t irq);

#ifdef __cplusplus
}
#endif

#endif /* __CM4_NVIC_H__ */
