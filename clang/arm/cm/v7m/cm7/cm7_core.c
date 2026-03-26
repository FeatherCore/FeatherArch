/*
 * arm_v7m_cm7_core.c
 * Cortex-M7 Core Register Implementation
 * Reference: Cortex-M7 Devices Generic User Guide, Chapter 2.1
 */

#include "arm_v7m_cm7_core.h"

/*============================================================================*
 * Special-Purpose Register Access Functions
 *============================================================================*/

uint32_t arm_v7m_cm7_get_msp(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void arm_v7m_cm7_set_msp(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t arm_v7m_cm7_get_psp(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void arm_v7m_cm7_set_psp(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t arm_v7m_cm7_get_primask(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void arm_v7m_cm7_set_primask(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t arm_v7m_cm7_get_faultmask(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void arm_v7m_cm7_set_faultmask(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t arm_v7m_cm7_get_basepri(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void arm_v7m_cm7_set_basepri(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t arm_v7m_cm7_get_control(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void arm_v7m_cm7_set_control(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

/*============================================================================*
 * APSR Register Access
 *============================================================================*/

uint32_t arm_v7m_cm7_get_apsr(void)
{
    /* TODO: Implement using MRS APSR instruction */
    return 0;
}

void arm_v7m_cm7_set_apsr(uint32_t value)
{
    /* TODO: Implement using MSR APSR instruction */
    (void)value;
}

uint32_t arm_v7m_cm7_get_ipsr(void)
{
    /* TODO: Implement using MRS IPSR instruction */
    return 0;
}

uint32_t arm_v7m_cm7_get_epsr(void)
{
    /* TODO: Implement using MRS EPSR instruction */
    return 0;
}
