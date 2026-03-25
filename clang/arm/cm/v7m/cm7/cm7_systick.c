/*
 * cm7_systick.c
 * Cortex-M7 System Timer (SysTick) Implementation
 * Reference: Cortex-M7 Devices Generic User Guide, Chapter 4.4
 */

#include "cm7_systick.h"

/*============================================================================*
 * SysTick Base Address (Architecture defined)
 *============================================================================*/
#define SYSTICK_BASE        0xE000E010UL

#define SYSTICK             ((cm7_systick_regs_t *)SYSTICK_BASE)

/*============================================================================*
 * SysTick Implementation
 *============================================================================*/

void cm7_systick_init(uint32_t reload_value)
{
    /* TODO: Configure and enable SysTick */
    (void)reload_value;
}

void cm7_systick_enable(void)
{
    /* TODO: Set ENABLE bit in CTRL register */
}

void cm7_systick_disable(void)
{
    /* TODO: Clear ENABLE bit in CTRL register */
}

uint32_t cm7_systick_get_count(void)
{
    /* TODO: Read VAL register */
    return 0;
}

void cm7_systick_set_reload(uint32_t value)
{
    /* TODO: Write LOAD register */
    (void)value;
}

uint32_t cm7_systick_get_reload(void)
{
    /* TODO: Read LOAD register */
    return 0;
}

uint32_t cm7_systick_get_calib(void)
{
    /* TODO: Read CALIB register */
    return 0;
}
