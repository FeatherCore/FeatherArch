/*
 * arm_v7m.c
 * Armv7-M Architecture Abstraction Layer - Main Implementation
 * 
 * Reference: ARMv7-M Architecture Reference Manual
 *            - Chapter A1: ARMv7-M Architecture Overview
 *            - Section B1.6: Reset management on page B1-529
 *            - Section B1.4.2: Interrupt control on page B1-527
 *            - Section B1.5.3: Wait For Interrupt on page B1-531
 *            - Section B1.5.4: Wait For Event and Send Event on page B1-532
 *            - Section A3.7.3: Memory barriers on page A3-81
 * 
 *            Cortex-M7 Devices Generic User Guide
 *            - Chapter 1: Introduction on page 1-2
 *            - Section 2.1: Programmers model on page 2-2
 *            - Section 2.5: Power management on page 2-31
 * 
 *            Cortex-M7 Technical Reference Manual
 *            - Chapter 1: Introduction on page 1-2
 *            - Chapter 2: Programmers Model on page 2-2
 */

#include "arm_v7m.h"
#include "arm_v7m_core.h"

/*============================================================================*
 * Global Initialization
 *============================================================================*/

/**
 * @brief Initialize the ARMv7-M processor
 * 
 * According to ARMv7-M Architecture Reference Manual, Section B1.6:
 * - Configure vector table offset
 * - Set up priority grouping
 * - Initialize core peripherals as needed
 * 
 * @note This function should be called early in the startup sequence.
 */
void arm_v7m_init(void)
{
    /* Initialize core components */
    arm_v7m_core_init();
}

/*============================================================================*
 * Interrupt Control
 *============================================================================*/

/* Note: arm_v7m_enable_irq/disable_irq are defined in arm_v7m_core.c */
/* They use CPSIE i and CPSID i instructions */

/*============================================================================*
 * Power Management
 *============================================================================*/

/**
 * @brief Wait For Interrupt
 * 
 * According to ARMv7-M Architecture Reference Manual, Section B1.5.3:
 * - Suspends execution until one of the following occurs:
 *   - An interrupt
 *   - A debug request
 *   - A reset
 * 
 * @note This function is implemented as an alias to arm_v7m_wfi() in the header.
 */
void arm_v7m_wait_for_interrupt(void)
{
    arm_v7m_wfi();
}

/**
 * @brief Wait For Event
 * 
 * According to ARMv7-M Architecture Reference Manual, Section B1.5.4:
 * - Suspends execution until one of the following occurs:
 *   - An event
 *   - An interrupt
 *   - A debug request
 *   - A reset
 * 
 * @note This function is implemented as an alias to arm_v7m_wfe() in the header.
 */
void arm_v7m_wait_for_event(void)
{
    arm_v7m_wfe();
}

/**
 * @brief Send Event
 * 
 * According to ARMv7-M Architecture Reference Manual, Section B1.5.4:
 * - Generates a wake-up event
 * - Can wake up processors in WFE state
 * 
 * @note This function is implemented as an alias to arm_v7m_sev() in the header.
 */
void arm_v7m_send_event(void)
{
    arm_v7m_sev();
}

/*============================================================================*
 * Memory Barriers
 *============================================================================*/

/**
 * @brief Data Memory Barrier
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.7.3:
 * - Ensures that all memory accesses before the DMB complete
 *   before any memory accesses after the DMB
 * 
 * @note This function is implemented as an alias to arm_v7m_dmb() in the header.
 */
void arm_v7m_data_memory_barrier(void)
{
    arm_v7m_dmb();
}

/**
 * @brief Data Synchronization Barrier
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.7.3:
 * - Acts as a special kind of memory barrier
 * - No instruction after the DSB can execute until the DSB completes
 * 
 * @note This function is implemented as an alias to arm_v7m_dsb() in the header.
 */
void arm_v7m_data_synchronization_barrier(void)
{
    arm_v7m_dsb();
}

/**
 * @brief Instruction Synchronization Barrier
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.7.3:
 * - Flushes the pipeline in the processor
 * - Ensures that all instructions following the ISB are fetched
 *   from cache or memory after the ISB completes
 * 
 * @note This function is implemented as an alias to arm_v7m_isb() in the header.
 */
void arm_v7m_instruction_synchronization_barrier(void)
{
    arm_v7m_isb();
}
