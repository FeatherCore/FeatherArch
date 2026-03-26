/*
 * arm_v7m_core.c
 * Armv7-M Core Register and System Control Implementation
 * Reference: ARMv7-M Architecture Reference Manual
 *   - Section B1.4: Registers
 *   - Section B5.2: System Instruction Descriptions
 *
 * This file implements non-inline functions that require:
 * 1. Multiple instructions (e.g., set_control with ISB)
 * 2. Complex logic (e.g., privilege checking)
 * 3. Functions that modify CONTROL register bits
 *
 * Simple register access functions are defined as inline in arm_v7m_core.h
 */

#include "arm_v7m_core.h"

/*============================================================================*
 * Control Register (CONTROL) - SYSm = 20
 * Note: set_control is NOT inline because it requires ISB after write
 *============================================================================*/

void arm_v7m_set_control(uint32_t value)
{
    __asm volatile ("MSR control, %0" : : "r" (value));
    /* ISB required after CONTROL write to ensure instruction fetch correctness */
    __asm volatile ("ISB");
}

/*============================================================================*
 * Helper Functions (NON-INLINE - complex logic)
 *============================================================================*/

/* Check if current execution is privileged */
int arm_v7m_is_privileged(void)
{
    /* In Handler mode, always privileged */
    if (arm_v7m_is_in_handler_mode()) {
        return 1;
    }
    /* In Thread mode, check CONTROL.nPRIV */
    return (arm_v7m_get_control() & ARM_V7M_CONTROL_nPRIV_Msk) == 0;
}

/* Set Thread mode to unprivileged */
void arm_v7m_set_unprivileged(void)
{
    uint32_t control = arm_v7m_get_control();
    control |= ARM_V7M_CONTROL_nPRIV_Msk;
    arm_v7m_set_control(control);
}

/* Set Thread mode to privileged */
void arm_v7m_set_privileged(void)
{
    uint32_t control = arm_v7m_get_control();
    control &= ~ARM_V7M_CONTROL_nPRIV_Msk;
    arm_v7m_set_control(control);
}

/* Use Process Stack Pointer (PSP) */
void arm_v7m_use_psp(void)
{
    uint32_t control = arm_v7m_get_control();
    control |= ARM_V7M_CONTROL_SPSEL_Msk;
    arm_v7m_set_control(control);
}

/* Use Main Stack Pointer (MSP) */
void arm_v7m_use_msp(void)
{
    uint32_t control = arm_v7m_get_control();
    control &= ~ARM_V7M_CONTROL_SPSEL_Msk;
    arm_v7m_set_control(control);
}

/*============================================================================*
 * CONTROL Register Bit Access Helper Functions
 * Reference: Section B1.4.4 - CONTROL register
 *============================================================================*/

/* Set CONTROL.FPCA bit - typically used by exception handler */
void arm_v7m_set_fpca(int value)
{
    uint32_t control = arm_v7m_get_control();
    if (value) {
        control |= ARM_V7M_CONTROL_FPCA_Msk;
    } else {
        control &= ~ARM_V7M_CONTROL_FPCA_Msk;
    }
    arm_v7m_set_control(control);
}
