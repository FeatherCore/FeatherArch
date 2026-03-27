/*
 * arm_v7m_cm4.c
 * Cortex-M4 Architecture Abstraction Layer - Main Implementation
 * 
 * Reference: ARMv7-M Architecture Reference Manual
 *            - Chapter A1: ARMv7-M Architecture Overview
 *            - Section B1.6: Reset management on page B1-529
 *            - Section B1.4.2: Interrupt control on page B1-527
 *            - Section B1.5.3: Wait For Interrupt on page B1-531
 *            - Section B1.5.4: Wait For Event and Send Event on page B1-532
 *            - Section A3.7.3: Memory barriers on page A3-81
 *            - Section A3.5: Exclusive access on page A3-75
 * 
 *            Cortex-M4 Devices Generic User Guide
 *            - Chapter 1: Introduction on page 1-2
 *            - Chapter 2: The Cortex-M4 Processor
 *            - Section 2.1: Programmers model on page 2-2
 *            - Section 2.5: Power management on page 2-31
 *            - Chapter 4: Cortex-M4 Peripherals on page 4-2
 *            - Section 4.5: Optional Memory Protection Unit on page 4-37
 *            - Section 4.6: Floating Point Unit (FPU) on page 4-48
 * 
 *            Cortex-M4 Technical Reference Manual
 *            - Chapter 1: Introduction on page 1-2
 *            - Chapter 2: Programmers Model on page 2-2
 *            - Chapter 3: System Control on page 3-2
 * 
 * @note Cortex-M4 is a standard Armv7-M implementation.
 *       This file wraps the generic Armv7-M implementation.
 */

#include "arm_v7m_cm4.h"

/*============================================================================*
 * Global Initialization
 *============================================================================*/

/**
 * @brief Initialize the Cortex-M4 processor
 * 
 * According to Cortex-M4 Devices Generic User Guide, Section 4.1 on page 4-2:
 * - Configure vector table offset
 * - Set up priority grouping
 * - Initialize SysTick if needed
 * - Configure MPU if present
 * - Enable FPU if present
 * 
 * @note This is a wrapper around arm_v7m_init() for compatibility.
 */
void arm_v7m_cm4_init(void)
{
    arm_v7m_init();
}

/*============================================================================*
 * Interrupt Control
 *============================================================================*/

/**
 * @brief Enable interrupts (clear PRIMASK)
 * 
 * According to ARMv7-M Architecture Reference Manual, Section B1.4.2:
 * - Clears PRIMASK using CPSIE i instruction
 */
void arm_v7m_cm4_enable_irq(void)
{
    arm_v7m_enable_irq();
}

/**
 * @brief Disable interrupts (set PRIMASK)
 * 
 * According to ARMv7-M Architecture Reference Manual, Section B1.4.2:
 * - Sets PRIMASK using CPSID i instruction
 */
void arm_v7m_cm4_disable_irq(void)
{
    arm_v7m_disable_irq();
}

/*============================================================================*
 * Power Management
 *============================================================================*/

/**
 * @brief Wait For Interrupt
 * 
 * According to ARMv7-M Architecture Reference Manual, Section B1.5.3:
 * - Suspends execution until interrupt, debug request, or reset
 */
void arm_v7m_cm4_wait_for_interrupt(void)
{
    arm_v7m_wait_for_interrupt();
}

/**
 * @brief Wait For Event
 * 
 * According to ARMv7-M Architecture Reference Manual, Section B1.5.4:
 * - Suspends execution until event, interrupt, debug request, or reset
 */
void arm_v7m_cm4_wait_for_event(void)
{
    arm_v7m_wait_for_event();
}

/**
 * @brief Send Event
 * 
 * According to ARMv7-M Architecture Reference Manual, Section B1.5.4:
 * - Generates a wake-up event
 */
void arm_v7m_cm4_send_event(void)
{
    arm_v7m_send_event();
}

/*============================================================================*
 * Memory Barriers
 *============================================================================*/

/**
 * @brief Data Memory Barrier
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.7.3:
 * - Ensures memory access ordering
 */
void arm_v7m_cm4_data_memory_barrier(void)
{
    arm_v7m_data_memory_barrier();
}

/**
 * @brief Data Synchronization Barrier
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.7.3:
 * - Ensures completion of memory accesses
 */
void arm_v7m_cm4_data_synchronization_barrier(void)
{
    arm_v7m_data_synchronization_barrier();
}

/**
 * @brief Instruction Synchronization Barrier
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.7.3:
 * - Flushes the pipeline
 */
void arm_v7m_cm4_instruction_synchronization_barrier(void)
{
    arm_v7m_instruction_synchronization_barrier();
}

/*============================================================================*
 * Exclusive Access (LDREX/STREX)
 *============================================================================*/

/**
 * @brief Load-Exclusive
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.5:
 * - Loads value from memory and marks exclusive access
 * @param addr Address to load from
 * @return Loaded value
 */
uint32_t arm_v7m_cm4_ldrex(uint32_t *addr)
{
    return arm_v7m_ldrex(addr);
}

/**
 * @brief Store-Exclusive
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.5:
 * - Stores value to memory if exclusive access is still valid
 * @param value Value to store
 * @param addr Address to store to
 * @return 0 if store succeeded, 1 if failed
 */
uint32_t arm_v7m_cm4_strex(uint32_t value, uint32_t *addr)
{
    return arm_v7m_strex(value, addr);
}

/**
 * @brief Clear-Exclusive
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.5:
 * - Clears the exclusive access tag
 */
void arm_v7m_cm4_clrex(void)
{
    arm_v7m_clrex();
}

/*============================================================================*
 * Bit-Band Operations
 *============================================================================*/

/**
 * @brief Set a bit using bit-band alias
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.4:
 * - Sets a single bit in the bit-band alias region
 * @param addr Address of the word containing the bit
 * @param bit Bit number (0-31)
 */
void arm_v7m_cm4_bitband_set(volatile uint32_t *addr, uint32_t bit)
{
    arm_v7m_bitband_set(addr, bit);
}

/**
 * @brief Clear a bit using bit-band alias
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.4:
 * - Clears a single bit in the bit-band alias region
 * @param addr Address of the word containing the bit
 * @param bit Bit number (0-31)
 */
void arm_v7m_cm4_bitband_clear(volatile uint32_t *addr, uint32_t bit)
{
    arm_v7m_bitband_clear(addr, bit);
}

/**
 * @brief Read a bit using bit-band alias
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.4:
 * - Reads a single bit from the bit-band alias region
 * @param addr Address of the word containing the bit
 * @param bit Bit number (0-31)
 * @return Bit value (0 or 1)
 */
uint32_t arm_v7m_cm4_bitband_read(volatile uint32_t *addr, uint32_t bit)
{
    return arm_v7m_bitband_read(addr, bit);
}

/**
 * @brief Toggle a bit using bit-band alias
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.4:
 * - Toggles a single bit in the bit-band alias region
 * @param addr Address of the word containing the bit
 * @param bit Bit number (0-31)
 */
void arm_v7m_cm4_bitband_toggle(volatile uint32_t *addr, uint32_t bit)
{
    arm_v7m_bitband_toggle(addr, bit);
}
