/*
 * arm_v8m_core.c
 * Armv8-M Core Register Implementation
 * Reference: Armv8-M Architecture Reference Manual, Chapter B3
 */

#include "arm_v8m_core.h"

/*============================================================================*
 * Special-Purpose Register Access Functions
 *============================================================================*/

uint32_t arm_v8m_get_msp(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void arm_v8m_set_msp(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t arm_v8m_get_psp(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void arm_v8m_set_psp(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t arm_v8m_get_msplim(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void arm_v8m_set_msplim(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t arm_v8m_get_psplim(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void arm_v8m_set_psplim(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t arm_v8m_get_primask(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void arm_v8m_set_primask(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t arm_v8m_get_faultmask(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void arm_v8m_set_faultmask(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t arm_v8m_get_basepri(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void arm_v8m_set_basepri(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t arm_v8m_get_control(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void arm_v8m_set_control(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

/*============================================================================*
 * Security State Functions
 *============================================================================*/

arm_v8m_security_state_t arm_v8m_get_security_state(void)
{
    /* TODO: Read CONTROL register or use TT instruction */
    return ARM_V8M_STATE_SECURE;
}

void arm_v8m_set_security_state(arm_v8m_security_state_t state)
{
    /* TODO: Use SG, BXNS, or BLXNS instructions */
    (void)state;
}

uint32_t arm_v8m_get_msp_s(void)
{
    /* TODO: Implement using MRS instruction from secure state */
    return 0;
}

void arm_v8m_set_msp_s(uint32_t value)
{
    /* TODO: Implement using MSR instruction from secure state */
    (void)value;
}

uint32_t arm_v8m_get_psp_s(void)
{
    /* TODO: Implement using MRS instruction from secure state */
    return 0;
}

void arm_v8m_set_psp_s(uint32_t value)
{
    /* TODO: Implement using MSR instruction from secure state */
    (void)value;
}

uint32_t arm_v8m_get_msplim_s(void)
{
    /* TODO: Implement using MRS instruction from secure state */
    return 0;
}

void arm_v8m_set_msplim_s(uint32_t value)
{
    /* TODO: Implement using MSR instruction from secure state */
    (void)value;
}

uint32_t arm_v8m_get_psplim_s(void)
{
    /* TODO: Implement using MRS instruction from secure state */
    return 0;
}

void arm_v8m_set_psplim_s(uint32_t value)
{
    /* TODO: Implement using MSR instruction from secure state */
    (void)value;
}
