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

/**
 * @brief Get the highest priority pending interrupt
 * @return Highest priority pending interrupt number, or NVIC_NUM_IRQN if none
 * @note This function traverses ISPR and IPR to find the highest priority pending interrupt
 *
 * Algorithm:
 * 1. Iterate through ISPR registers to find pending interrupts
 * 2. For each pending interrupt, read its priority from IPR
 * 3. Track the interrupt with the lowest priority value (highest urgency)
 * 4. Return the interrupt number with highest priority
 */
uint32_t arm_v7m_nvic_get_highest_pending_irq(void)
{
    uint32_t reg_idx, bit_pos;
    uint32_t highest_irq = NVIC_NUM_IRQN;  /* Invalid IRQ number */
    uint32_t highest_priority = 0xFFFFFFFFU;  /* Lowest priority */
    uint32_t irq_count;
    
    /* Get actual number of implemented interrupts */
    irq_count = arm_v7m_nvic_get_irq_count();
    if (irq_count > NVIC_NUM_IRQN) {
        irq_count = NVIC_NUM_IRQN;
    }
    
    /* Iterate through all ISPR registers */
    for (reg_idx = 0; reg_idx < 16U; reg_idx++) {
        uint32_t ispr_val = NVIC->ISPR[reg_idx];
        
        /* Check each bit in the register */
        while (ispr_val != 0U) {
            /* Find first set bit */
            bit_pos = __builtin_ctz(ispr_val);
            uint32_t irqn = (reg_idx << 5U) + bit_pos;
            
            /* Check if this interrupt is within implemented range */
            if (irqn < irq_count) {
                /* Get priority of this interrupt */
                uint32_t priority = arm_v7m_nvic_get_priority(irqn);
                
                /* Lower priority value = higher urgency */
                if (priority < highest_priority) {
                    highest_priority = priority;
                    highest_irq = irqn;
                }
            }
            
            /* Clear the bit we just processed */
            ispr_val &= ~(1UL << bit_pos);
        }
    }
    
    return highest_irq;
}
