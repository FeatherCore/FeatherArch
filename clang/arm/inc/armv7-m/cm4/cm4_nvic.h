/*
 * ARM Architecture - Cortex-M4 NVIC (Nested Vectored Interrupt Controller)
 *
 * ============================================================================
 * File: cm4_nvic.h
 * Description: Cortex-M4 NVIC register definitions (wrapper for armv7-m_nvic.h)
 * 描述: Cortex-M4 NVIC 寄存器定义（armv7-m_nvic.h 的包装层）
 *
 * This file provides CM4-specific naming conventions while delegating
 * all actual definitions to armv7-m_nvic.h.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.2 Nested Vectored Interrupt Controller (page 4-3)
 *   - Table 4-1 NVIC registers summary (page 4-3)
 *   - Table 4-2 NVIC register map (page 4-3)
 *
 * Implementation: All functionality is provided by armv7-m/armv7-m_nvic.h
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_NVIC_H__
#define __CM4_NVIC_H__

#include <stdint.h>
#include <stdbool.h>

/* Include the underlying ARMv7-M implementation */
#include "armv7-m/armv7-m_nvic.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * NVIC Base Address Alias
 * NVIC 基地址别名
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-2 (page 4-3)
 * ============================================================================
 */

#define CM4_NVIC_BASE_ADDR            ARMV7M_NVIC_BASE

/*
 * ============================================================================
 * Register Aliases - Map CM4 naming to ARMv7-M naming
 * 寄存器别名 - 将 CM4 命名映射到 ARMv7-M 命名
 * ============================================================================
 */

/* Interrupt Set-Enable Registers */
#define NVIC_ISER0                    NVIC_ISER(0)
#define NVIC_ISER1                    NVIC_ISER(1)
#define NVIC_ISER2                    NVIC_ISER(2)
#define NVIC_ISER3                    NVIC_ISER(3)
#define NVIC_ISER4                    NVIC_ISER(4)
#define NVIC_ISER5                    NVIC_ISER(5)
#define NVIC_ISER6                    NVIC_ISER(6)
#define NVIC_ISER7                    NVIC_ISER(7)

/* Interrupt Clear-Enable Registers */
#define NVIC_ICER0                    NVIC_ICER(0)
#define NVIC_ICER1                    NVIC_ICER(1)
#define NVIC_ICER2                    NVIC_ICER(2)
#define NVIC_ICER3                    NVIC_ICER(3)
#define NVIC_ICER4                    NVIC_ICER(4)
#define NVIC_ICER5                    NVIC_ICER(5)
#define NVIC_ICER6                    NVIC_ICER(6)
#define NVIC_ICER7                    NVIC_ICER(7)

/* Interrupt Set-Pending Registers */
#define NVIC_ISPR0                    NVIC_ISPR(0)
#define NVIC_ISPR1                    NVIC_ISPR(1)
#define NVIC_ISPR2                    NVIC_ISPR(2)
#define NVIC_ISPR3                    NVIC_ISPR(3)
#define NVIC_ISPR4                    NVIC_ISPR(4)
#define NVIC_ISPR5                    NVIC_ISPR(5)
#define NVIC_ISPR6                    NVIC_ISPR(6)
#define NVIC_ISPR7                    NVIC_ISPR(7)

/* Interrupt Clear-Pending Registers */
#define NVIC_ICPR0                    NVIC_ICPR(0)
#define NVIC_ICPR1                    NVIC_ICPR(1)
#define NVIC_ICPR2                    NVIC_ICPR(2)
#define NVIC_ICPR3                    NVIC_ICPR(3)
#define NVIC_ICPR4                    NVIC_ICPR(4)
#define NVIC_ICPR5                    NVIC_ICPR(5)
#define NVIC_ICPR6                    NVIC_ICPR(6)
#define NVIC_ICPR7                    NVIC_ICPR(7)

/* Interrupt Active Bit Registers */
#define NVIC_IABR0                    NVIC_IABR(0)
#define NVIC_IABR1                    NVIC_IABR(1)
#define NVIC_IABR2                    NVIC_IABR(2)
#define NVIC_IABR3                    NVIC_IABR(3)
#define NVIC_IABR4                    NVIC_IABR(4)
#define NVIC_IABR5                    NVIC_IABR(5)
#define NVIC_IABR6                    NVIC_IABR(6)
#define NVIC_IABR7                    NVIC_IABR(7)

/* Interrupt Priority Register - already defined as NVIC_IPR(irq) in armv7-m_nvic.h */

/* Software Triggered Interrupt Register - already defined as NVIC_STIR in armv7-m_nvic.h */

/*
 * ============================================================================
 * Function Aliases - Map CM4 naming to ARMv7-M naming
 * 函数别名 - 将 CM4 命名映射到 ARMv7-M 命名
 * ============================================================================
 */

/**
 * @brief Enable specified interrupt
 * @param irq Interrupt number (0-239)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 * Implementation: Delegates to nvic_enable_irq() in armv7-m_nvic.c
 */
static inline void cm4_nvic_enable_irq(uint32_t irq)
{
    nvic_enable_irq((uint8_t)irq);
}

/**
 * @brief Disable specified interrupt
 * @param irq Interrupt number (0-239)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 * Implementation: Delegates to nvic_disable_irq() in armv7-m_nvic.c
 */
static inline void cm4_nvic_disable_irq(uint32_t irq)
{
    nvic_disable_irq((uint8_t)irq);
}

/**
 * @brief Get interrupt enable status
 * @param irq Interrupt number (0-239)
 * @return 1 if enabled, 0 if disabled
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 * Implementation: Delegates to nvic_get_enable_irq() in armv7-m_nvic.c
 */
static inline uint32_t cm4_nvic_get_enable_irq(uint32_t irq)
{
    return nvic_get_enable_irq((uint8_t)irq);
}

/**
 * @brief Set interrupt pending status
 * @param irq Interrupt number (0-239)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 * Implementation: Delegates to nvic_set_pending() in armv7-m_nvic.c
 */
static inline void cm4_nvic_set_pending(uint32_t irq)
{
    nvic_set_pending((uint8_t)irq);
}

/**
 * @brief Clear interrupt pending status
 * @param irq Interrupt number (0-239)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 * Implementation: Delegates to nvic_clear_pending() in armv7-m_nvic.c
 */
static inline void cm4_nvic_clear_pending(uint32_t irq)
{
    nvic_clear_pending((uint8_t)irq);
}

/**
 * @brief Get interrupt pending status
 * @param irq Interrupt number (0-239)
 * @return 1 if pending, 0 if not pending
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 * Implementation: Delegates to nvic_get_pending() in armv7-m_nvic.c
 */
static inline uint32_t cm4_nvic_get_pending(uint32_t irq)
{
    return nvic_get_pending((uint8_t)irq);
}

/**
 * @brief Get active interrupt status
 * @param irq Interrupt number (0-239)
 * @return 1 if active, 0 if not active
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 * Implementation: Delegates to nvic_get_active() in armv7-m_nvic.c
 */
static inline uint32_t cm4_nvic_get_active(uint32_t irq)
{
    return nvic_get_active((uint8_t)irq);
}

/**
 * @brief Set interrupt priority
 * @param irq Interrupt number (0-239)
 * @param priority Priority value (0-255, lower is higher priority)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 * Implementation: Delegates to nvic_set_priority() in armv7-m_nvic.c
 */
static inline void cm4_nvic_set_priority(uint32_t irq, uint32_t priority)
{
    nvic_set_priority((uint8_t)irq, (uint8_t)priority);
}

/**
 * @brief Get interrupt priority
 * @param irq Interrupt number (0-239)
 * @return Priority value (0-255)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 * Implementation: Delegates to nvic_get_priority() in armv7-m_nvic.c
 */
static inline uint32_t cm4_nvic_get_priority(uint32_t irq)
{
    return nvic_get_priority((uint8_t)irq);
}

/**
 * @brief Trigger interrupt by software
 * @param irq Interrupt number (0-239)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 * Implementation: Direct register access using NVIC_STIR from armv7-m_nvic.h
 */
static inline void cm4_nvic_trigger_irq(uint32_t irq)
{
    NVIC_STIR = irq & 0x1FF;
}

#ifdef __cplusplus
}
#endif

#endif /* __CM4_NVIC_H__ */
