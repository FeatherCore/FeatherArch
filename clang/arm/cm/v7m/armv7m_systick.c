/*
 * arm_v7m_systick.c
 * System Timer (SysTick) Implementation
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.3
 */

#include "arm_v7m_systick.h"

/*============================================================================*
 * SysTick Base Address (Architecture defined)
 *============================================================================*/
#define SYSTICK_BASE        0xE000E010UL

#define SYSTICK             ((arm_v7m_systick_regs_t *)SYSTICK_BASE)

/*============================================================================*
 * SysTick Implementation
 *============================================================================*/

void arm_v7m_systick_init(uint32_t reload_value)
{
    /* TODO: Configure and enable SysTick */
    (void)reload_value;
}

void arm_v7m_systick_enable(void)
{
    /* TODO: Set ENABLE bit in CTRL register */
}

void arm_v7m_systick_disable(void)
{
    /* TODO: Clear ENABLE bit in CTRL register */
}

uint32_t arm_v7m_systick_get_count(void)
{
    /* TODO: Read VAL register */
    return 0;
}

uint32_t arm_v7m_systick_get_reload(void)
{
    /* TODO: Read LOAD register */
    return 0;
}

void arm_v7m_systick_set_reload(uint32_t value)
{
    /* TODO: Write LOAD register */
    (void)value;
}
