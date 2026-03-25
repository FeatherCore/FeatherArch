/*
 * cm55_ras.h
 * Cortex-M55 Reliability, Availability, and Serviceability (RAS) Definitions
 * Reference: Cortex-M55 Technical Reference Manual, Chapter 12
 */

#ifndef CM55_RAS_H
#define CM55_RAS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * RAS Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t ESB;
    volatile uint32_t IESB;
} cm55_ras_regs_t;

/*============================================================================*
 * Error Bank Register Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t IEBR0;
    volatile uint32_t IEBR1;
    volatile uint32_t DEBR0;
    volatile uint32_t DEBR1;
    volatile uint32_t TEBR0;
    volatile uint32_t TEBR1;
} cm55_error_bank_regs_t;

/*============================================================================*
 * RAS API Functions (Template)
 *============================================================================*/

uint32_t cm55_ras_is_present(void);
void cm55_ras_enable(void);
void cm55_ras_disable(void);

/* Error Synchronization Barrier */
void cm55_ras_esb(void);
void cm55_ras_implicit_esb_enable(void);
void cm55_ras_implicit_esb_disable(void);

/* Error Bank Functions */
uint32_t cm55_ras_get_iebr0(void);
uint32_t cm55_ras_get_iebr1(void);
uint32_t cm55_ras_get_debr0(void);
uint32_t cm55_ras_get_debr1(void);
uint32_t cm55_ras_get_tebr0(void);
uint32_t cm55_ras_get_tebr1(void);
void cm55_ras_clear_error_banks(void);

#ifdef __cplusplus
}
#endif

#endif /* CM55_RAS_H */
