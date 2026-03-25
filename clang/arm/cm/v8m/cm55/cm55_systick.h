/*
 * cm55_systick.h
 * Cortex-M55 System Timer (SysTick) Definitions
 * Reference: Cortex-M55 Devices Generic User Guide, Chapter 4.3
 */

#ifndef CM55_SYSTICK_H
#define CM55_SYSTICK_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * SysTick Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VAL;
    volatile const uint32_t CALIB;
} cm55_systick_regs_t;

/*============================================================================*
 * SysTick Control Register Bit Definitions
 *============================================================================*/

#define CM55_SYSTICK_CTRL_ENABLE_Pos        0
#define CM55_SYSTICK_CTRL_ENABLE_Msk        (1UL << CM55_SYSTICK_CTRL_ENABLE_Pos)
#define CM55_SYSTICK_CTRL_TICKINT_Pos       1
#define CM55_SYSTICK_CTRL_TICKINT_Msk       (1UL << CM55_SYSTICK_CTRL_TICKINT_Pos)
#define CM55_SYSTICK_CTRL_CLKSOURCE_Pos     2
#define CM55_SYSTICK_CTRL_CLKSOURCE_Msk     (1UL << CM55_SYSTICK_CTRL_CLKSOURCE_Pos)
#define CM55_SYSTICK_CTRL_COUNTFLAG_Pos     16
#define CM55_SYSTICK_CTRL_COUNTFLAG_Msk     (1UL << CM55_SYSTICK_CTRL_COUNTFLAG_Pos)

/*============================================================================*
 * SysTick API Functions (Template)
 *============================================================================*/

void cm55_systick_init(uint32_t reload_value);
void cm55_systick_enable(void);
void cm55_systick_disable(void);
uint32_t cm55_systick_get_count(void);
void cm55_systick_set_reload(uint32_t value);
uint32_t cm55_systick_get_reload(void);
uint32_t cm55_systick_get_calib(void);

/*============================================================================*
 * SysTick Security Functions (Template) - TrustZone
 *============================================================================*/

void cm55_systick_set_ns_access(uint32_t enable);
uint32_t cm55_systick_get_ns_access(void);

#ifdef __cplusplus
}
#endif

#endif /* CM55_SYSTICK_H */
