/*
 * arm_v7m_cm7_nvic.c
 * Cortex-M7 Nested Vectored Interrupt Controller (NVIC) Implementation
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.4
 *            - Nested Vectored Interrupt Controller, NVIC on page B3-624
 *            Cortex-M7 Devices Generic User Guide, Chapter 4.2
 *            - Nested Vectored Interrupt Controller on page 4-3
 *            Cortex-M7 Technical Reference Manual, Chapter 7
 *            - Nested Vectored Interrupt Controller on page 7-1
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

/**
 * @brief Get the highest priority pending interrupt
 * @return Highest priority pending interrupt number, or ARM_V7M_CM7_NVIC_NUM_IRQN if none
 * @note Traverses ISPR and IPR registers to find highest priority pending interrupt
 *       This function delegates to the generic arm_v7m implementation.
 */
uint32_t arm_v7m_cm7_nvic_get_highest_pending_irq(void)
{
    return arm_v7m_nvic_get_highest_pending_irq();
}
