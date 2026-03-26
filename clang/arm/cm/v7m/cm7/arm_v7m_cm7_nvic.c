/*
 * arm_v7m_cm7_nvic.c
 * Cortex-M7 Nested Vectored Interrupt Controller (NVIC) Implementation
 * Reference: Cortex-M7 Devices Generic User Guide, Chapter 4.2
 *            Cortex-M7 Technical Reference Manual, Chapter 7
 *
 * @note Cortex-M7 NVIC is identical to generic Armv7-M NVIC.
 *       Most functions are implemented as static inline in arm_v7m_cm7_nvic.h.
 *       This file contains non-inline implementations of batch operations.
 */

#include "arm_v7m_cm7_nvic.h"

/*============================================================================*
 * NVIC Batch Operations
 *============================================================================*/

/**
 * @brief Enable multiple interrupts in a single operation
 * @param irqn_array Array of interrupt numbers
 * @param count Number of interrupts in the array
 * @note Iterates through the array and enables each interrupt individually.
 *       This is useful for initializing multiple interrupts at once.
 */
void arm_v7m_cm7_nvic_enable_irq_batch(const uint32_t *irqn_array, uint32_t count)
{
    uint32_t i;
    
    if (irqn_array != (void *)0) {
        for (i = 0; i < count; i++) {
            arm_v7m_cm7_nvic_enable_irq(irqn_array[i]);
        }
    }
}

/**
 * @brief Disable multiple interrupts in a single operation
 * @param irqn_array Array of interrupt numbers
 * @param count Number of interrupts in the array
 * @note Iterates through the array and disables each interrupt individually.
 *       This is useful for shutting down multiple interrupts at once.
 */
void arm_v7m_cm7_nvic_disable_irq_batch(const uint32_t *irqn_array, uint32_t count)
{
    uint32_t i;
    
    if (irqn_array != (void *)0) {
        for (i = 0; i < count; i++) {
            arm_v7m_cm7_nvic_disable_irq(irqn_array[i]);
        }
    }
}
