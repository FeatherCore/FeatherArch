/*
 * armv8m_systick.c
 * Armv8-M System Timer (SysTick) Implementation
 * Reference: Armv8-M Architecture Reference Manual, Chapter B11
 */

#include "armv8m_systick.h"

/*============================================================================*
 * SysTick Base Address (Architecture defined)
 *============================================================================*/
#define SYSTICK_BASE        0xE000E010UL

#define SYSTICK             ((armv8m_systick_regs_t *)SYSTICK_BASE)

/*============================================================================*
 * SysTick Implementation
 *============================================================================*/

void armv8m_systick_init(uint32_t reload_value)
{
    /* TODO: Configure and enable SysTick */
    (void)reload_value;
}

void armv8m_systick_enable(void)
{
    /* TODO: Set ENABLE bit in CTRL register */
}

void armv8m_systick_disable(void)
{
    /* TODO: Clear ENABLE bit in CTRL register */
}

uint32_t armv8m_systick_get_count(void)
{
    /* TODO: Read VAL register */
    return 0;
}

void armv8m_systick_set_reload(uint32_t value)
{
    /* TODO: Write LOAD register */
    (void)value;
}

uint32_t armv8m_systick_get_reload(void)
{
    /* TODO: Read LOAD register */
    return 0;
}

uint32_t armv8m_systick_get_calib(void)
{
    /* TODO: Read CALIB register */
    return 0;
}

/*============================================================================*
 * SysTick Security Functions - Armv8-M TrustZone
 *============================================================================*/

void armv8m_systick_set_ns_access(uint32_t enable)
{
    /* TODO: Configure SysTick access for Non-secure state */
    (void)enable;
}

uint32_t armv8m_systick_get_ns_access(void)
{
    /* TODO: Read SysTick access configuration */
    return 0;
}
