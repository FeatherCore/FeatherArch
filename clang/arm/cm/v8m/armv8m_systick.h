/*
 * armv8m_systick.h
 * Armv8-M System Timer (SysTick) Definitions
 * Reference: Armv8-M Architecture Reference Manual, Chapter B11
 */

#ifndef ARMV8M_SYSTICK_H
#define ARMV8M_SYSTICK_H

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
} armv8m_systick_regs_t;

/*============================================================================*
 * SysTick Control Register Bit Definitions
 *============================================================================*/

#define ARMV8M_SYSTICK_CTRL_ENABLE_Pos      0
#define ARMV8M_SYSTICK_CTRL_ENABLE_Msk      (1UL << ARMV8M_SYSTICK_CTRL_ENABLE_Pos)
#define ARMV8M_SYSTICK_CTRL_TICKINT_Pos     1
#define ARMV8M_SYSTICK_CTRL_TICKINT_Msk     (1UL << ARMV8M_SYSTICK_CTRL_TICKINT_Pos)
#define ARMV8M_SYSTICK_CTRL_CLKSOURCE_Pos   2
#define ARMV8M_SYSTICK_CTRL_CLKSOURCE_Msk   (1UL << ARMV8M_SYSTICK_CTRL_CLKSOURCE_Pos)
#define ARMV8M_SYSTICK_CTRL_COUNTFLAG_Pos   16
#define ARMV8M_SYSTICK_CTRL_COUNTFLAG_Msk   (1UL << ARMV8M_SYSTICK_CTRL_COUNTFLAG_Pos)

/*============================================================================*
 * SysTick API Functions (Template)
 *============================================================================*/

void armv8m_systick_init(uint32_t reload_value);
void armv8m_systick_enable(void);
void armv8m_systick_disable(void);
uint32_t armv8m_systick_get_count(void);
void armv8m_systick_set_reload(uint32_t value);
uint32_t armv8m_systick_get_reload(void);
uint32_t armv8m_systick_get_calib(void);

/*============================================================================*
 * SysTick Security Functions (Template) - Armv8-M TrustZone
 *============================================================================*/

void armv8m_systick_set_ns_access(uint32_t enable);
uint32_t armv8m_systick_get_ns_access(void);

#ifdef __cplusplus
}
#endif

#endif /* ARMV8M_SYSTICK_H */
