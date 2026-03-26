/*
 * arm_v8m_nvic.h
 * Armv8-M Nested Vectored Interrupt Controller (NVIC) Definitions
 * Reference: Armv8-M Architecture Reference Manual, Chapter B12
 */

#ifndef ARM_V8M_NVIC_H
#define ARM_V8M_NVIC_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * NVIC Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t ISER[16];
    uint32_t RESERVED0[16];
    volatile uint32_t ICER[16];
    uint32_t RSERVED1[16];
    volatile uint32_t ISPR[16];
    uint32_t RESERVED2[16];
    volatile uint32_t ICPR[16];
    uint32_t RESERVED3[16];
    volatile uint32_t IABR[16];
    uint32_t RESERVED4[16];
    volatile uint8_t  IP[496];
    uint32_t RESERVED5[580];
    volatile uint32_t STIR;
} arm_v8m_nvic_regs_t;

/*============================================================================*
 * NVIC API Functions (Template)
 *============================================================================*/

void arm_v8m_nvic_enable_irq(uint32_t irqn);
void arm_v8m_nvic_disable_irq(uint32_t irqn);
uint32_t arm_v8m_nvic_get_pending_irq(uint32_t irqn);
void arm_v8m_nvic_set_pending_irq(uint32_t irqn);
void arm_v8m_nvic_clear_pending_irq(uint32_t irqn);
uint32_t arm_v8m_nvic_get_active_irq(uint32_t irqn);
void arm_v8m_nvic_set_priority(uint32_t irqn, uint32_t priority);
uint32_t arm_v8m_nvic_get_priority(uint32_t irqn);
void arm_v8m_nvic_trigger_irq(uint32_t irqn);

/*============================================================================*
 * NVIC Security Functions (Template) - Armv8-M TrustZone
 *============================================================================*/

void arm_v8m_nvic_enable_irq_s(uint32_t irqn);
void arm_v8m_nvic_disable_irq_s(uint32_t irqn);
void arm_v8m_nvic_set_priority_s(uint32_t irqn, uint32_t priority);
uint32_t arm_v8m_nvic_get_priority_s(uint32_t irqn);
void arm_v8m_nvic_set_irq_target_state(uint32_t irqn, uint32_t state);
uint32_t arm_v8m_nvic_get_irq_target_state(uint32_t irqn);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_NVIC_H */
