/**
 * @file cm85_nvic.c
 * @brief Cortex-M85 NVIC implementation
 */

#include "cm85_nvic.h"
#include "cm85_core.h"

/* TODO: Implement NVIC functions */

int cm85_nvic_init(void)
{
    /* TODO: Initialize NVIC */
    return 0;
}

void cm85_nvic_deinit(void)
{
    /* TODO: Deinitialize NVIC */
}

void cm85_nvic_enable_irq(cm85_nvic_irqn_t irqn)
{
    /* TODO: Enable interrupt */
    (void)irqn;
}

void cm85_nvic_disable_irq(cm85_nvic_irqn_t irqn)
{
    /* TODO: Disable interrupt */
    (void)irqn;
}

bool cm85_nvic_is_enabled(cm85_nvic_irqn_t irqn)
{
    /* TODO: Check if interrupt is enabled */
    (void)irqn;
    return false;
}

void cm85_nvic_set_pending(cm85_nvic_irqn_t irqn)
{
    /* TODO: Set interrupt pending */
    (void)irqn;
}

void cm85_nvic_clear_pending(cm85_nvic_irqn_t irqn)
{
    /* TODO: Clear interrupt pending */
    (void)irqn;
}

bool cm85_nvic_is_pending(cm85_nvic_irqn_t irqn)
{
    /* TODO: Check if interrupt is pending */
    (void)irqn;
    return false;
}

bool cm85_nvic_is_active(cm85_nvic_irqn_t irqn)
{
    /* TODO: Check if interrupt is active */
    (void)irqn;
    return false;
}

void cm85_nvic_set_priority(cm85_nvic_irqn_t irqn, uint32_t priority)
{
    /* TODO: Set interrupt priority */
    (void)irqn;
    (void)priority;
}

uint32_t cm85_nvic_get_priority(cm85_nvic_irqn_t irqn)
{
    /* TODO: Get interrupt priority */
    (void)irqn;
    return 0;
}

void cm85_nvic_set_priority_grouping(cm85_nvic_prio_group_t group)
{
    /* TODO: Set priority grouping */
    (void)group;
}

cm85_nvic_prio_group_t cm85_nvic_get_priority_grouping(void)
{
    /* TODO: Get priority grouping */
    return CM85_NVIC_PRIO_GROUP_0;
}

uint32_t cm85_nvic_encode_priority(cm85_nvic_prio_group_t group, 
                                    uint32_t preempt_prio, 
                                    uint32_t sub_prio)
{
    /* TODO: Encode priority value */
    (void)group;
    (void)preempt_prio;
    (void)sub_prio;
    return 0;
}

void cm85_nvic_decode_priority(uint32_t priority, 
                                cm85_nvic_prio_group_t group,
                                uint32_t *preempt_prio, 
                                uint32_t *sub_prio)
{
    /* TODO: Decode priority value */
    (void)priority;
    (void)group;
    if (preempt_prio) *preempt_prio = 0;
    if (sub_prio) *sub_prio = 0;
}

void cm85_nvic_system_reset(void)
{
    /* TODO: Perform system reset */
}

#ifdef __ARM_FEATURE_CMSE
void cm85_nvic_enable_irq_ns(cm85_nvic_irqn_t irqn)
{
    /* TODO: Enable Non-secure interrupt */
    (void)irqn;
}

void cm85_nvic_disable_irq_ns(cm85_nvic_irqn_t irqn)
{
    /* TODO: Disable Non-secure interrupt */
    (void)irqn;
}

void cm85_nvic_set_priority_ns(cm85_nvic_irqn_t irqn, uint32_t priority)
{
    /* TODO: Set Non-secure interrupt priority */
    (void)irqn;
    (void)priority;
}

uint32_t cm85_nvic_get_priority_ns(cm85_nvic_irqn_t irqn)
{
    /* TODO: Get Non-secure interrupt priority */
    (void)irqn;
    return 0;
}
#endif
