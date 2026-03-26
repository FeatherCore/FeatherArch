/*
 * arm_v7m_scb.c
 * System Control Block (SCB) Implementation
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2
 */

#include "arm_v7m_scb.h"

/*============================================================================*
 * SCB Base Address (Architecture defined)
 *============================================================================*/
#define SCB_BASE            0xE000ED00UL

#define SCB                 ((arm_v7m_scb_regs_t *)SCB_BASE)

/*============================================================================*
 * SCB Implementation
 *============================================================================*/

void arm_v7m_scb_set_vector_table(uint32_t offset)
{
    /* TODO: Write to VTOR register */
    (void)offset;
}

uint32_t arm_v7m_scb_get_vector_table(void)
{
    /* TODO: Read VTOR register */
    return 0;
}

void arm_v7m_scb_system_reset(void)
{
    /* TODO: Write to AIRCR with SYSRESETREQ and VECTKEY */
}

void arm_v7m_scb_set_priority_grouping(uint32_t priority_group)
{
    /* TODO: Write PRIGROUP field in AIRCR */
    (void)priority_group;
}

uint32_t arm_v7m_scb_get_priority_grouping(void)
{
    /* TODO: Read PRIGROUP field from AIRCR */
    return 0;
}

void arm_v7m_scb_enable_fault_irq(void)
{
    /* TODO: Set FAULTMASK */
}

void arm_v7m_scb_disable_fault_irq(void)
{
    /* TODO: Clear FAULTMASK */
}

void arm_v7m_scb_clear_fault_status(void)
{
    /* TODO: Clear CFSR, HFSR, DFSR registers */
}
