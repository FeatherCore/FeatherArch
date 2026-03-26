/*
 * arm_v7m_nvic.c
 * Nested Vectored Interrupt Controller (NVIC) Implementation
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.4
 * 
 * This file contains non-inline implementations of complex NVIC operations.
 * Simple register access functions are implemented as static inline in the header.
 */

#include "arm_v7m_nvic.h"

/*============================================================================*
 * NVIC Batch Operations
 *============================================================================*/

/**
 * @brief Enable multiple interrupts in a single operation
 * 
 * @param irqn_array Array of interrupt numbers
 * @param count Number of interrupts in the array
 */
void arm_v7m_nvic_enable_irq_batch(const uint32_t *irqn_array, uint32_t count)
{
    uint32_t i;
    
    if (irqn_array != (void *)0) {
        for (i = 0; i < count; i++) {
            arm_v7m_nvic_enable_irq(irqn_array[i]);
        }
    }
}

/**
 * @brief Disable multiple interrupts in a single operation
 * 
 * @param irqn_array Array of interrupt numbers
 * @param count Number of interrupts in the array
 */
void arm_v7m_nvic_disable_irq_batch(const uint32_t *irqn_array, uint32_t count)
{
    uint32_t i;
    
    if (irqn_array != (void *)0) {
        for (i = 0; i < count; i++) {
            arm_v7m_nvic_disable_irq(irqn_array[i]);
        }
    }
}
