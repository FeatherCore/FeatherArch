/*
 * arm_v7m_systick.h
 * System Timer (SysTick) Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.3
 */

#ifndef ARM_V7M_SYSTICK_H
#define ARM_V7M_SYSTICK_H

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
} arm_v7m_systick_regs_t;

/*============================================================================*
 * SysTick Control Register Bit Definitions
 *============================================================================*/

#define ARM_V7M_SYSTICK_CTRL_ENABLE_Pos      0
#define ARM_V7M_SYSTICK_CTRL_ENABLE_Msk      (1UL << ARM_V7M_SYSTICK_CTRL_ENABLE_Pos)
#define ARM_V7M_SYSTICK_CTRL_TICKINT_Pos     1
#define ARM_V7M_SYSTICK_CTRL_TICKINT_Msk     (1UL << ARM_V7M_SYSTICK_CTRL_TICKINT_Pos)
#define ARM_V7M_SYSTICK_CTRL_CLKSOURCE_Pos   2
#define ARM_V7M_SYSTICK_CTRL_CLKSOURCE_Msk   (1UL << ARM_V7M_SYSTICK_CTRL_CLKSOURCE_Pos)
#define ARM_V7M_SYSTICK_CTRL_COUNTFLAG_Pos   16
#define ARM_V7M_SYSTICK_CTRL_COUNTFLAG_Msk   (1UL << ARM_V7M_SYSTICK_CTRL_COUNTFLAG_Pos)

/*============================================================================*
 * SysTick API Functions (Template)
 *============================================================================*/

void arm_v7m_systick_init(uint32_t reload_value);
void arm_v7m_systick_enable(void);
void arm_v7m_systick_disable(void);
uint32_t arm_v7m_systick_get_count(void);
uint32_t arm_v7m_systick_get_reload(void);
void arm_v7m_systick_set_reload(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_SYSTICK_H */
