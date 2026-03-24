/*
 * ARM Architecture - Cortex-M4 NVIC Implementation
 *
 * ============================================================================
 * File: cm4_nvic.c
 * Description: Cortex-M4 NVIC function implementations
 * 描述: Cortex-M4 NVIC 函数实现
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.2 Nested Vectored Interrupt Controller (page 4-3)
 *   - Table 4-2 NVIC register map (page 4-3)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include "armv7-m/cm4/cm4_nvic.h"

/**
 * @brief Enable specified interrupt
 * @param irq Interrupt number (0-239)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
void cm4_nvic_enable_irq(uint32_t irq)
{
    NVIC_ISER0 = (1UL << (irq & 0x1F));
}

/**
 * @brief Disable specified interrupt
 * @param irq Interrupt number
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
void cm4_nvic_disable_irq(uint32_t irq)
{
    NVIC_ICER0 = (1UL << (irq & 0x1F));
}

/**
 * @brief Get interrupt enable status
 * @param irq Interrupt number
 * @return 1 if enabled, 0 if disabled
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
uint32_t cm4_nvic_get_enable_irq(uint32_t irq)
{
    return (NVIC_ISER0 >> (irq & 0x1F)) & 1UL;
}

/**
 * @brief Set interrupt pending status
 * @param irq Interrupt number
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
void cm4_nvic_set_pending(uint32_t irq)
{
    NVIC_ISPR0 = (1UL << (irq & 0x1F));
}

/**
 * @brief Clear interrupt pending status
 * @param irq Interrupt number
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
void cm4_nvic_clear_pending(uint32_t irq)
{
    NVIC_ICPR0 = (1UL << (irq & 0x1F));
}

/**
 * @brief Get interrupt pending status
 * @param irq Interrupt number
 * @return 1 if pending, 0 if not pending
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
uint32_t cm4_nvic_get_pending(uint32_t irq)
{
    return (NVIC_ISPR0 >> (irq & 0x1F)) & 1UL;
}

/**
 * @brief Get active interrupt status
 * @param irq Interrupt number
 * @return 1 if active, 0 if not active
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
uint32_t cm4_nvic_get_active(uint32_t irq)
{
    return (NVIC_IABR0 >> (irq & 0x1F)) & 1UL;
}

/**
 * @brief Set interrupt priority
 * @param irq Interrupt number
 * @param priority Priority value (0-255, lower is higher priority)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
void cm4_nvic_set_priority(uint32_t irq, uint32_t priority)
{
    NVIC_IPR(irq) = (uint8_t)(priority & 0xFF);
}

/**
 * @brief Get interrupt priority
 * @param irq Interrupt number
 * @return Priority value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
uint32_t cm4_nvic_get_priority(uint32_t irq)
{
    return NVIC_IPR(irq);
}

/**
 * @brief Trigger interrupt by software
 * @param irq Interrupt number
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.2 (page 4-3)
 */
void cm4_nvic_trigger_irq(uint32_t irq)
{
    NVIC_STIR = irq & 0x1FF;
}
