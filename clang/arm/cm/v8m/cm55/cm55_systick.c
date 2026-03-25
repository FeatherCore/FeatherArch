/*
 * cm55_systick.c
 * Cortex-M55 System Timer (SysTick) Implementation
 * Reference: Cortex-M55 Devices Generic User Guide, Chapter 4.3
 */

#include "cm55_systick.h"

/*============================================================================*
 * SysTick Base Address (Architecture defined)
 *============================================================================*/
#define SYSTICK_BASE        0xE000E010UL

#define SYSTICK             ((cm55_systick_regs_t *)SYSTICK_BASE)

/*============================================================================*
 * SysTick Implementation
 *============================================================================*/

void cm55_systick_init(uint32_t reload_value)
{
    /* TODO: Configure and enable SysTick */
    (void)reload_value;
}

void cm55_systick_enable(void)
{
    /* TODO: Set ENABLE bit in CTRL register */
}

void cm55_systick_disable(void)
{
    /* TODO: Clear ENABLE bit in CTRL register */
}

uint32_t cm55_systick_get_count(void)
{
    /* TODO: Read VAL register */
    return 0;
}

void cm55_systick_set_reload(uint32_t value)
{
    /* TODO: Write LOAD register */
    (void)value;
}

uint32_t cm55_systick_get_reload(void)
{
    /* TODO: Read LOAD register */
    return 0;
}

uint32_t cm55_systick_get_calib(void)
{
    /* TODO: Read CALIB register */
    return 0;
}

/*============================================================================*
 * SysTick Security Functions - TrustZone
 *============================================================================*/

void cm55_systick_set_ns_access(uint32_t enable)
{
    /* TODO: Configure SysTick access for Non-secure state */
    (void)enable;
}

uint32_t cm55_systick_get_ns_access(void)
{
    /* TODO: Read SysTick access configuration */
    return 0;
}
