/*
 * cm7_nvic.h
 * Cortex-M7 Nested Vectored Interrupt Controller (NVIC) Definitions
 * Reference: Cortex-M7 Devices Generic User Guide, Chapter 4.2
 *            Cortex-M7 Technical Reference Manual, Chapter 7
 */

#ifndef CM7_NVIC_H
#define CM7_NVIC_H

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
} cm7_nvic_regs_t;

/*============================================================================*
 * NVIC API Functions (Template)
 *============================================================================*/

void cm7_nvic_enable_irq(uint32_t irqn);
void cm7_nvic_disable_irq(uint32_t irqn);
uint32_t cm7_nvic_get_pending_irq(uint32_t irqn);
void cm7_nvic_set_pending_irq(uint32_t irqn);
void cm7_nvic_clear_pending_irq(uint32_t irqn);
uint32_t cm7_nvic_get_active_irq(uint32_t irqn);
void cm7_nvic_set_priority(uint32_t irqn, uint32_t priority);
uint32_t cm7_nvic_get_priority(uint32_t irqn);
void cm7_nvic_trigger_irq(uint32_t irqn);

#ifdef __cplusplus
}
#endif

#endif /* CM7_NVIC_H */
