/*
 * arm_v8m_cm55_nvic.h
 * Cortex-M55 Nested Vectored Interrupt Controller (NVIC) Definitions
 * Reference: Cortex-M55 Devices Generic User Guide, Chapter 4.4
 *            Cortex-M55 Technical Reference Manual, Chapter 5
 *
 * @note This file reuses Armv8-M generic NVIC definitions.
 */

#ifndef ARM_V8M_CM55_NVIC_H
#define ARM_V8M_CM55_NVIC_H

#include <stdint.h>
#include "../arm_v8m_nvic.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Type Aliases
 *============================================================================*/

typedef arm_v8m_nvic_regs_t     arm_v8m_cm55_nvic_regs_t;

/*============================================================================*
 * Inline Function Wrappers - NVIC Operations
 *============================================================================*/

static inline void arm_v8m_cm55_nvic_enable_irq(uint32_t irqn) {
    arm_v8m_nvic_enable_irq(irqn);
}

static inline void arm_v8m_cm55_nvic_disable_irq(uint32_t irqn) {
    arm_v8m_nvic_disable_irq(irqn);
}

static inline uint32_t arm_v8m_cm55_nvic_get_pending_irq(uint32_t irqn) {
    return arm_v8m_nvic_get_pending_irq(irqn);
}

static inline void arm_v8m_cm55_nvic_set_pending_irq(uint32_t irqn) {
    arm_v8m_nvic_set_pending_irq(irqn);
}

static inline void arm_v8m_cm55_nvic_clear_pending_irq(uint32_t irqn) {
    arm_v8m_nvic_clear_pending_irq(irqn);
}

static inline uint32_t arm_v8m_cm55_nvic_get_active_irq(uint32_t irqn) {
    return arm_v8m_nvic_get_active_irq(irqn);
}

static inline void arm_v8m_cm55_nvic_set_priority(uint32_t irqn, uint32_t priority) {
    arm_v8m_nvic_set_priority(irqn, priority);
}

static inline uint32_t arm_v8m_cm55_nvic_get_priority(uint32_t irqn) {
    return arm_v8m_nvic_get_priority(irqn);
}

static inline void arm_v8m_cm55_nvic_trigger_irq(uint32_t irqn) {
    arm_v8m_nvic_trigger_irq(irqn);
}

/*============================================================================*
 * Security Functions - TrustZone
 *============================================================================*/

static inline void arm_v8m_cm55_nvic_enable_irq_s(uint32_t irqn) {
    arm_v8m_nvic_enable_irq_s(irqn);
}

static inline void arm_v8m_cm55_nvic_disable_irq_s(uint32_t irqn) {
    arm_v8m_nvic_disable_irq_s(irqn);
}

static inline void arm_v8m_cm55_nvic_set_priority_s(uint32_t irqn, uint32_t priority) {
    arm_v8m_nvic_set_priority_s(irqn, priority);
}

static inline uint32_t arm_v8m_cm55_nvic_get_priority_s(uint32_t irqn) {
    return arm_v8m_nvic_get_priority_s(irqn);
}

static inline void arm_v8m_cm55_nvic_set_irq_target_state(uint32_t irqn, uint32_t state) {
    arm_v8m_nvic_set_irq_target_state(irqn, state);
}

static inline uint32_t arm_v8m_cm55_nvic_get_irq_target_state(uint32_t irqn) {
    return arm_v8m_nvic_get_irq_target_state(irqn);
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM55_NVIC_H */
