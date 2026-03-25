/*
 * cm4_nvic.h
 * Cortex-M4 Nested Vectored Interrupt Controller (NVIC) Definitions
 * Reference: Cortex-M4 Devices Generic User Guide, Chapter 4.2
 *            Cortex-M4 Technical Reference Manual, Chapter 6
 */

#ifndef CM4_NVIC_H
#define CM4_NVIC_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * NVIC Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t ISER[8];
    uint32_t RESERVED0[24];
    volatile uint32_t ICER[8];
    uint32_t RSERVED1[24];
    volatile uint32_t ISPR[8];
    uint32_t RESERVED2[24];
    volatile uint32_t ICPR[8];
    uint32_t RESERVED3[24];
    volatile uint32_t IABR[8];
    uint32_t RESERVED4[56];
    volatile uint8_t  IP[240];
    uint32_t RESERVED5[644];
    volatile uint32_t STIR;
} cm4_nvic_regs_t;

/*============================================================================*
 * NVIC API Functions (Template)
 *============================================================================*/

void cm4_nvic_enable_irq(uint32_t irqn);
void cm4_nvic_disable_irq(uint32_t irqn);
uint32_t cm4_nvic_get_pending_irq(uint32_t irqn);
void cm4_nvic_set_pending_irq(uint32_t irqn);
void cm4_nvic_clear_pending_irq(uint32_t irqn);
uint32_t cm4_nvic_get_active_irq(uint32_t irqn);
void cm4_nvic_set_priority(uint32_t irqn, uint32_t priority);
uint32_t cm4_nvic_get_priority(uint32_t irqn);
void cm4_nvic_trigger_irq(uint32_t irqn);

#ifdef __cplusplus
}
#endif

#endif /* CM4_NVIC_H */
