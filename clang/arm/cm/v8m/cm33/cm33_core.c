/*
 * cm33_core.c
 * Cortex-M33 Core Register Implementation
 * Reference: Cortex-M33 Devices Generic User Guide, Chapter 2.1
 */

#include "cm33_core.h"

/*============================================================================*
 * Special-Purpose Register Access Functions
 *============================================================================*/

uint32_t cm33_get_msp(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void cm33_set_msp(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t cm33_get_psp(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void cm33_set_psp(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t cm33_get_msplim(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void cm33_set_msplim(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t cm33_get_psplim(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void cm33_set_psplim(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t cm33_get_primask(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void cm33_set_primask(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t cm33_get_faultmask(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void cm33_set_faultmask(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t cm33_get_basepri(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void cm33_set_basepri(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

uint32_t cm33_get_control(void)
{
    /* TODO: Implement using MRS instruction */
    return 0;
}

void cm33_set_control(uint32_t value)
{
    /* TODO: Implement using MSR instruction */
    (void)value;
}

/*============================================================================*
 * Security State Functions
 *============================================================================*/

cm33_security_state_t cm33_get_security_state(void)
{
    /* TODO: Read CONTROL register or use TT instruction */
    return CM33_STATE_SECURE;
}

void cm33_set_security_state(cm33_security_state_t state)
{
    /* TODO: Use SG, BXNS, or BLXNS instructions */
    (void)state;
}

uint32_t cm33_get_msp_s(void)
{
    /* TODO: Implement using MRS instruction from secure state */
    return 0;
}

void cm33_set_msp_s(uint32_t value)
{
    /* TODO: Implement using MSR instruction from secure state */
    (void)value;
}

uint32_t cm33_get_psp_s(void)
{
    /* TODO: Implement using MRS instruction from secure state */
    return 0;
}

void cm33_set_psp_s(uint32_t value)
{
    /* TODO: Implement using MSR instruction from secure state */
    (void)value;
}

uint32_t cm33_get_msplim_s(void)
{
    /* TODO: Implement using MRS instruction from secure state */
    return 0;
}

void cm33_set_msplim_s(uint32_t value)
{
    /* TODO: Implement using MSR instruction from secure state */
    (void)value;
}

uint32_t cm33_get_psplim_s(void)
{
    /* TODO: Implement using MRS instruction from secure state */
    return 0;
}

void cm33_set_psplim_s(uint32_t value)
{
    /* TODO: Implement using MSR instruction from secure state */
    (void)value;
}

/*============================================================================*
 * TT Instruction - Test Target
 *============================================================================*/
uint32_t cm33_tt(uint32_t addr)
{
    /* TODO: Execute TT instruction */
    (void)addr;
    return 0;
}

uint32_t cm33_ttt(uint32_t addr)
{
    /* TODO: Execute TTT instruction */
    (void)addr;
    return 0;
}

uint32_t cm33_tta(uint32_t addr)
{
    /* TODO: Execute TTA instruction */
    (void)addr;
    return 0;
}

uint32_t cm33_ttat(uint32_t addr)
{
    /* TODO: Execute TTAT instruction */
    (void)addr;
    return 0;
}
