/*
 * arm_v7m_cm7_nvic.h
 * Cortex-M7 Nested Vectored Interrupt Controller (NVIC) Definitions
 * Reference: Cortex-M7 Devices Generic User Guide, Chapter 4.2
 *
 * @note This file reuses Armv7-M generic NVIC definitions.
 */

#ifndef ARM_V7M_CM7_NVIC_H
#define ARM_V7M_CM7_NVIC_H

#include <stdint.h>
#include "../arm_v7m_nvic.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Type Aliases
 *============================================================================*/

typedef arm_v7m_nvic_regs_t     arm_v7m_cm7_nvic_regs_t;

/*============================================================================*
 * Inline Function Wrappers - NVIC Operations
 *============================================================================*/

static inline void arm_v7m_cm7_nvic_enable_irq(uint32_t irqn) {
    arm_v7m_nvic_enable_irq(irqn);
}

static inline void arm_v7m_cm7_nvic_disable_irq(uint32_t irqn) {
    arm_v7m_nvic_disable_irq(irqn);
}

static inline uint32_t arm_v7m_cm7_nvic_get_pending_irq(uint32_t irqn) {
    return arm_v7m_nvic_get_pending_irq(irqn);
}

static inline void arm_v7m_cm7_nvic_set_pending_irq(uint32_t irqn) {
    arm_v7m_nvic_set_pending_irq(irqn);
}

static inline void arm_v7m_cm7_nvic_clear_pending_irq(uint32_t irqn) {
    arm_v7m_nvic_clear_pending_irq(irqn);
}

static inline uint32_t arm_v7m_cm7_nvic_get_active_irq(uint32_t irqn) {
    return arm_v7m_nvic_get_active_irq(irqn);
}

static inline void arm_v7m_cm7_nvic_set_priority(uint32_t irqn, uint32_t priority) {
    arm_v7m_nvic_set_priority(irqn, priority);
}

static inline uint32_t arm_v7m_cm7_nvic_get_priority(uint32_t irqn) {
    return arm_v7m_nvic_get_priority(irqn);
}

static inline void arm_v7m_cm7_nvic_system_reset(void) {
    arm_v7m_nvic_system_reset();
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM7_NVIC_H */
