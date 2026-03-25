/*
 * armv7m_nvic.h
 * Nested Vectored Interrupt Controller (NVIC) Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.4
 */

#ifndef ARMV7M_NVIC_H
#define ARMV7M_NVIC_H

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
    volatile uint32_t IPR[124];
} armv7m_nvic_regs_t;

/*============================================================================*
 * NVIC API Functions (Template)
 *============================================================================*/

void armv7m_nvic_enable_irq(uint32_t irqn);
void armv7m_nvic_disable_irq(uint32_t irqn);
uint32_t armv7m_nvic_get_pending_irq(uint32_t irqn);
void armv7m_nvic_set_pending_irq(uint32_t irqn);
void armv7m_nvic_clear_pending_irq(uint32_t irqn);
uint32_t armv7m_nvic_get_active_irq(uint32_t irqn);
void armv7m_nvic_set_priority(uint32_t irqn, uint32_t priority);
uint32_t armv7m_nvic_get_priority(uint32_t irqn);
void armv7m_nvic_system_reset(void);

#ifdef __cplusplus
}
#endif

#endif /* ARMV7M_NVIC_H */
