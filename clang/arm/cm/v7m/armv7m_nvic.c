/*
 * arm_v7m_nvic.c
 * Nested Vectored Interrupt Controller (NVIC) Implementation
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.4
 */

#include "arm_v7m_nvic.h"

/*============================================================================*
 * NVIC Base Address (Architecture defined)
 *============================================================================*/
#define NVIC_BASE           0xE000E100UL
#define SCB_BASE            0xE000ED00UL

#define NVIC                ((arm_v7m_nvic_regs_t *)NVIC_BASE)

/*============================================================================*
 * NVIC Implementation
 *============================================================================*/

void arm_v7m_nvic_enable_irq(uint32_t irqn)
{
    /* TODO: Set appropriate bit in ISER register */
    (void)irqn;
}

void arm_v7m_nvic_disable_irq(uint32_t irqn)
{
    /* TODO: Set appropriate bit in ICER register */
    (void)irqn;
}

uint32_t arm_v7m_nvic_get_pending_irq(uint32_t irqn)
{
    /* TODO: Read appropriate bit in ISPR register */
    (void)irqn;
    return 0;
}

void arm_v7m_nvic_set_pending_irq(uint32_t irqn)
{
    /* TODO: Set appropriate bit in ISPR register */
    (void)irqn;
}

void arm_v7m_nvic_clear_pending_irq(uint32_t irqn)
{
    /* TODO: Set appropriate bit in ICPR register */
    (void)irqn;
}

uint32_t arm_v7m_nvic_get_active_irq(uint32_t irqn)
{
    /* TODO: Read appropriate bit in IABR register */
    (void)irqn;
    return 0;
}

void arm_v7m_nvic_set_priority(uint32_t irqn, uint32_t priority)
{
    /* TODO: Write to IPR register */
    (void)irqn;
    (void)priority;
}

uint32_t arm_v7m_nvic_get_priority(uint32_t irqn)
{
    /* TODO: Read from IPR register */
    (void)irqn;
    return 0;
}

void arm_v7m_nvic_system_reset(void)
{
    /* TODO: Write to SCB->AIRCR with SYSRESETREQ */
}
