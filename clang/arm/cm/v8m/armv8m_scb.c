/*
 * armv8m_scb.c
 * Armv8-M System Control Block (SCB) Implementation
 * Reference: Armv8-M Architecture Reference Manual, Chapter B3
 */

#include "armv8m_scb.h"

/*============================================================================*
 * SCB Base Address (Architecture defined)
 *============================================================================*/
#define SCB_BASE            0xE000ED00UL

#define SCB                 ((armv8m_scb_regs_t *)SCB_BASE)

/*============================================================================*
 * SCB Implementation
 *============================================================================*/

void armv8m_scb_set_vector_table(uint32_t offset)
{
    /* TODO: Write to VTOR register */
    (void)offset;
}

uint32_t armv8m_scb_get_vector_table(void)
{
    /* TODO: Read VTOR register */
    return 0;
}

void armv8m_scb_system_reset(void)
{
    /* TODO: Write to AIRCR with SYSRESETREQ and VECTKEY */
}

void armv8m_scb_set_priority_grouping(uint32_t priority_group)
{
    /* TODO: Write PRIGROUP field in AIRCR */
    (void)priority_group;
}

uint32_t armv8m_scb_get_priority_grouping(void)
{
    /* TODO: Read PRIGROUP field from AIRCR */
    return 0;
}

void armv8m_scb_enable_fault(uint32_t fault)
{
    /* TODO: Set fault enable bits in SHCSR */
    (void)fault;
}

void armv8m_scb_disable_fault(uint32_t fault)
{
    /* TODO: Clear fault enable bits in SHCSR */
    (void)fault;
}

uint32_t armv8m_scb_get_fault_status(void)
{
    /* TODO: Read CFSR and HFSR */
    return 0;
}

void armv8m_scb_clear_fault_status(void)
{
    /* TODO: Clear CFSR, HFSR, DFSR registers */
}

/*============================================================================*
 * SCB Security Functions - Armv8-M TrustZone
 *============================================================================*/

void armv8m_scb_set_vector_table_s(uint32_t offset)
{
    /* TODO: Write to VTOR_S register from secure state */
    (void)offset;
}

uint32_t armv8m_scb_get_vector_table_s(void)
{
    /* TODO: Read VTOR_S register from secure state */
    return 0;
}

void armv8m_scb_system_reset_s(void)
{
    /* TODO: Write to AIRCR with SYSRESETREQS from secure state */
}

void armv8m_scb_set_aircr_s(uint32_t value)
{
    /* TODO: Write to AIRCR_S register from secure state */
    (void)value;
}

uint32_t armv8m_scb_get_aircr_s(void)
{
    /* TODO: Read AIRCR_S register from secure state */
    return 0;
}
