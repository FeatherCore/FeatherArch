/*
 * cm4_scb.c
 * Cortex-M4 System Control Block (SCB) Implementation
 * Reference: Cortex-M4 Devices Generic User Guide, Chapter 4.3
 */

#include "cm4_scb.h"

/*============================================================================*
 * SCB Base Address (Architecture defined)
 *============================================================================*/
#define SCB_BASE            0xE000ED00UL

#define SCB                 ((cm4_scb_regs_t *)SCB_BASE)

/*============================================================================*
 * SCB Implementation
 *============================================================================*/

void cm4_scb_set_vector_table(uint32_t offset)
{
    /* TODO: Write to VTOR register */
    (void)offset;
}

uint32_t cm4_scb_get_vector_table(void)
{
    /* TODO: Read VTOR register */
    return 0;
}

void cm4_scb_system_reset(void)
{
    /* TODO: Write to AIRCR with SYSRESETREQ and VECTKEY */
}

void cm4_scb_set_priority_grouping(uint32_t priority_group)
{
    /* TODO: Write PRIGROUP field in AIRCR */
    (void)priority_group;
}

uint32_t cm4_scb_get_priority_grouping(void)
{
    /* TODO: Read PRIGROUP field from AIRCR */
    return 0;
}

void cm4_scb_enable_fault(uint32_t fault)
{
    /* TODO: Set fault enable bits in SHCSR */
    (void)fault;
}

void cm4_scb_disable_fault(uint32_t fault)
{
    /* TODO: Clear fault enable bits in SHCSR */
    (void)fault;
}

uint32_t cm4_scb_get_fault_status(void)
{
    /* TODO: Read CFSR and HFSR */
    return 0;
}

void cm4_scb_clear_fault_status(void)
{
    /* TODO: Clear CFSR, HFSR, DFSR registers */
}
