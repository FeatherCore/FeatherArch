/*
 * arm_v8m_cm33_nvic.c
 * Cortex-M33 Nested Vectored Interrupt Controller (NVIC) Implementation
 * Reference: Cortex-M33 Devices Generic User Guide, Chapter 4.4
 */

#include "arm_v8m_cm33_nvic.h"

/*============================================================================*
 * NVIC Base Address (Architecture defined)
 *============================================================================*/
#define NVIC_BASE           0xE000E100UL

#define NVIC                ((arm_v8m_cm33_nvic_regs_t *)NVIC_BASE)

/*============================================================================*
 * NVIC Implementation
 *============================================================================*/

void arm_v8m_cm33_nvic_enable_irq(uint32_t irqn)
{
    /* TODO: Set appropriate bit in ISER register */
    (void)irqn;
}

void arm_v8m_cm33_nvic_disable_irq(uint32_t irqn)
{
    /* TODO: Set appropriate bit in ICER register */
    (void)irqn;
}

uint32_t arm_v8m_cm33_nvic_get_pending_irq(uint32_t irqn)
{
    /* TODO: Read appropriate bit in ISPR register */
    (void)irqn;
    return 0;
}

void arm_v8m_cm33_nvic_set_pending_irq(uint32_t irqn)
{
    /* TODO: Set appropriate bit in ISPR register */
    (void)irqn;
}

void arm_v8m_cm33_nvic_clear_pending_irq(uint32_t irqn)
{
    /* TODO: Set appropriate bit in ICPR register */
    (void)irqn;
}

uint32_t arm_v8m_cm33_nvic_get_active_irq(uint32_t irqn)
{
    /* TODO: Read appropriate bit in IABR register */
    (void)irqn;
    return 0;
}

void arm_v8m_cm33_nvic_set_priority(uint32_t irqn, uint32_t priority)
{
    /* TODO: Write to IPR register */
    (void)irqn;
    (void)priority;
}

uint32_t arm_v8m_cm33_nvic_get_priority(uint32_t irqn)
{
    /* TODO: Read from IPR register */
    (void)irqn;
    return 0;
}

void arm_v8m_cm33_nvic_trigger_irq(uint32_t irqn)
{
    /* TODO: Write to STIR register */
    (void)irqn;
}

/*============================================================================*
 * NVIC Security Functions - TrustZone
 *============================================================================*/

void arm_v8m_cm33_nvic_enable_irq_s(uint32_t irqn)
{
    /* TODO: Set appropriate bit in ISER register from secure state */
    (void)irqn;
}

void arm_v8m_cm33_nvic_disable_irq_s(uint32_t irqn)
{
    /* TODO: Set appropriate bit in ICER register from secure state */
    (void)irqn;
}

void arm_v8m_cm33_nvic_set_priority_s(uint32_t irqn, uint32_t priority)
{
    /* TODO: Write to IPR register from secure state */
    (void)irqn;
    (void)priority;
}

uint32_t arm_v8m_cm33_nvic_get_priority_s(uint32_t irqn)
{
    /* TODO: Read from IPR register from secure state */
    (void)irqn;
    return 0;
}

void arm_v8m_cm33_nvic_set_irq_target_state(uint32_t irqn, uint32_t state)
{
    /* TODO: Configure NVIC_ITNS register for TrustZone */
    (void)irqn;
    (void)state;
}

uint32_t arm_v8m_cm33_nvic_get_irq_target_state(uint32_t irqn)
{
    /* TODO: Read NVIC_ITNS register for TrustZone */
    (void)irqn;
    return 0;
}
