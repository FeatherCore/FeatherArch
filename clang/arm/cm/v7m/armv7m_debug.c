/*
 * armv7m_debug.c
 * Debug Support Implementation
 * Reference: ARMv7-M Architecture Reference Manual, Part C
 */

#include "armv7m_debug.h"

/*============================================================================*
 * Debug Base Addresses (Architecture defined)
 *============================================================================*/
#define DEBUG_BASE          0xE000EDF0UL
#define DWT_BASE            0xE0001000UL

#define DEBUG               ((armv7m_debug_regs_t *)DEBUG_BASE)
#define DWT                 ((armv7m_dwt_regs_t *)DWT_BASE)

/*============================================================================*
 * Debug Implementation
 *============================================================================*/

void armv7m_debug_enable_trace(void)
{
    /* TODO: Enable TRCENA in DEMCR */
}

void armv7m_debug_disable_trace(void)
{
    /* TODO: Disable TRCENA in DEMCR */
}

uint32_t armv7m_debug_is_halted(void)
{
    /* TODO: Check S_HALT bit in DHCSR */
    return 0;
}

void armv7m_debug_halt(void)
{
    /* TODO: Set C_HALT in DHCSR with debug key */
}

void armv7m_debug_resume(void)
{
    /* TODO: Clear C_HALT in DHCSR with debug key */
}

void armv7m_dwt_enable_cyccnt(void)
{
    /* TODO: Enable CYCCNTENA in DWT_CTRL */
}

uint32_t armv7m_dwt_get_cyccnt(void)
{
    /* TODO: Read DWT_CYCCNT */
    return 0;
}

void armv7m_dwt_set_cyccnt(uint32_t value)
{
    /* TODO: Write DWT_CYCCNT */
    (void)value;
}
