/*
 * arm_v7m_cm7_nvic.c
 * Cortex-M7 Nested Vectored Interrupt Controller (NVIC) Implementation
 * Reference: Cortex-M7 Devices Generic User Guide, Chapter 4.2
 */

#include "arm_v7m_cm7_nvic.h"

/*============================================================================*
 * NVIC Base Address (Architecture defined)
 *============================================================================*/
#define NVIC_BASE           0xE000E100UL

#define NVIC                ((arm_v7m_cm7_nvic_regs_t *)NVIC_BASE)

/*============================================================================*
 * NVIC Implementation
 *============================================================================*/

void arm_v7m_cm7_nvic_enable_irq(uint32_t irqn)
{
    /* TODO: Set appropriate bit in ISER register */
    (void)irqn;
}

void arm_v7m_cm7_nvic_disable_irq(uint32_t irqn)
{
    /* TODO: Set appropriate bit in ICER register */
    (void)irqn;
}

uint32_t arm_v7m_cm7_nvic_get_pending_irq(uint32_t irqn)
{
    /* TODO: Read appropriate bit in ISPR register */
    (void)irqn;
    return 0;
}

void arm_v7m_cm7_nvic_set_pending_irq(uint32_t irqn)
{
    /* TODO: Set appropriate bit in ISPR register */
    (void)irqn;
}

void arm_v7m_cm7_nvic_clear_pending_irq(uint32_t irqn)
{
    /* TODO: Set appropriate bit in ICPR register */
    (void)irqn;
}

uint32_t arm_v7m_cm7_nvic_get_active_irq(uint32_t irqn)
{
    /* TODO: Read appropriate bit in IABR register */
    (void)irqn;
    return 0;
}

void arm_v7m_cm7_nvic_set_priority(uint32_t irqn, uint32_t priority)
{
    /* TODO: Write to IPR register */
    (void)irqn;
    (void)priority;
}

uint32_t arm_v7m_cm7_nvic_get_priority(uint32_t irqn)
{
    /* TODO: Read from IPR register */
    (void)irqn;
    return 0;
}

void arm_v7m_cm7_nvic_trigger_irq(uint32_t irqn)
{
    /* TODO: Write to STIR register */
    (void)irqn;
}
