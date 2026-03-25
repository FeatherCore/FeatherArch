/*
 * armv7m_core.c
 * Armv7-M Core Register Implementation
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4
 */

#include "armv7m_core.h"

/*============================================================================*
 * Special-Purpose Register Access Functions
 *============================================================================*/

uint32_t armv7m_get_msp(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void armv7m_set_msp(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t armv7m_get_psp(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void armv7m_set_psp(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t armv7m_get_primask(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void armv7m_set_primask(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t armv7m_get_control(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void armv7m_set_control(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}
