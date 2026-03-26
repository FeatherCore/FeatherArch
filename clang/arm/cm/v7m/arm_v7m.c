/*
 * armv7m.c
 * Armv7-M Architecture Abstraction Layer - Main Implementation
 * Reference: ARMv7-M Architecture Reference Manual
 */

#include "arm_v7m.h"
#include "arm_v7m_core.h"

/*============================================================================*
 * Global Initialization
 *============================================================================*/

void arm_v7m_init(void)
{
    /* TODO: Initialize core components */
    /* - Configure vector table */
    /* - Set up priority grouping */
    /* - Initialize SysTick if needed */
    /* - Configure MPU if present */
    /* - Enable FPU if present */
}

/*============================================================================*
 * Interrupt Control
 *============================================================================*/

/* Note: arm_v7m_enable_irq/disable_irq are defined in arm_v7m_core.c */
/* They use CPSIE i and CPSID i instructions */

/*============================================================================*
 * Power Management
 *============================================================================*/

void arm_v7m_wait_for_interrupt(void)
{
    arm_v7m_wfi();
}

void arm_v7m_wait_for_event(void)
{
    arm_v7m_wfe();
}

void arm_v7m_send_event(void)
{
    arm_v7m_sev();
}

/*============================================================================*
 * Memory Barriers
 *============================================================================*/

void arm_v7m_data_memory_barrier(void)
{
    arm_v7m_dmb();
}

void arm_v7m_data_synchronization_barrier(void)
{
    arm_v7m_dsb();
}

void arm_v7m_instruction_synchronization_barrier(void)
{
    arm_v7m_isb();
}
