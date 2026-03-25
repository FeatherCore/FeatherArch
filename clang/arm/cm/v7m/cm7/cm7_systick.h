/*
 * cm7_systick.h
 * Cortex-M7 System Timer (SysTick) Definitions
 * Reference: Cortex-M7 Devices Generic User Guide, Chapter 4.4
 */

#ifndef CM7_SYSTICK_H
#define CM7_SYSTICK_H

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
} cm7_systick_regs_t;

/*============================================================================*
 * SysTick Control Register Bit Definitions
 *============================================================================*/

#define CM7_SYSTICK_CTRL_ENABLE_Pos         0
#define CM7_SYSTICK_CTRL_ENABLE_Msk         (1UL << CM7_SYSTICK_CTRL_ENABLE_Pos)
#define CM7_SYSTICK_CTRL_TICKINT_Pos        1
#define CM7_SYSTICK_CTRL_TICKINT_Msk        (1UL << CM7_SYSTICK_CTRL_TICKINT_Pos)
#define CM7_SYSTICK_CTRL_CLKSOURCE_Pos      2
#define CM7_SYSTICK_CTRL_CLKSOURCE_Msk      (1UL << CM7_SYSTICK_CTRL_CLKSOURCE_Pos)
#define CM7_SYSTICK_CTRL_COUNTFLAG_Pos      16
#define CM7_SYSTICK_CTRL_COUNTFLAG_Msk      (1UL << CM7_SYSTICK_CTRL_COUNTFLAG_Pos)

/*============================================================================*
 * SysTick API Functions (Template)
 *============================================================================*/

void cm7_systick_init(uint32_t reload_value);
void cm7_systick_enable(void);
void cm7_systick_disable(void);
uint32_t cm7_systick_get_count(void);
void cm7_systick_set_reload(uint32_t value);
uint32_t cm7_systick_get_reload(void);
uint32_t cm7_systick_get_calib(void);

#ifdef __cplusplus
}
#endif

#endif /* CM7_SYSTICK_H */
