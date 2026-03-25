/*
 * cm55_epu.c
 * Cortex-M55 Extension Processing Unit (EPU) Implementation
 * Reference: Cortex-M55 Technical Reference Manual, Chapter 11
 */

#include "cm55_epu.h"

/*============================================================================*
 * EPU Base Address (Architecture defined)
 *============================================================================*/
#define EPU_BASE            0xE000EE00UL

#define EPU                 ((cm55_epu_regs_t *)EPU_BASE)

/*============================================================================*
 * EPU Implementation
 *============================================================================*/

uint32_t cm55_epu_is_present(void)
{
    /* TODO: Check ID_DFR for EPU support */
    return 0;
}

void cm55_epu_enable(void)
{
    /* TODO: Set EN bit in EPUCR */
}

void cm55_epu_disable(void)
{
    /* TODO: Clear EN bit in EPUCR */
}

uint32_t cm55_epu_get_status(void)
{
    /* TODO: Read EPUSR */
    return 0;
}

void cm55_epu_send_command(uint32_t cmd)
{
    /* TODO: Write to EPUIR */
    (void)cmd;
}

uint32_t cm55_epu_get_response(void)
{
    /* TODO: Read response from EPU */
    return 0;
}
