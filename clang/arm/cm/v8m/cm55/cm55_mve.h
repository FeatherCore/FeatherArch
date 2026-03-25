/*
 * cm55_mve.h
 * Cortex-M55 M-Profile Vector Extension (MVE) Definitions
 * Reference: Cortex-M55 Devices Generic User Guide, Chapter 3.7
 *            Cortex-M55 Technical Reference Manual, Chapter 16
 */

#ifndef CM55_MVE_H
#define CM55_MVE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * MVE Type Definitions
 *============================================================================*/

typedef struct {
    volatile const uint32_t MVFR0;
    volatile const uint32_t MVFR1;
    volatile const uint32_t MVFR2;
} cm55_mve_regs_t;

/*============================================================================*
 * Vector Register File (Q0-Q7 for MVE)
 *============================================================================*/

typedef struct {
    uint32_t q[4];
} cm55_vec128_t;

/*============================================================================*
 * MVE API Functions (Template)
 *============================================================================*/

uint32_t cm55_mve_is_present(void);
uint32_t cm55_mve_has_int(void);
uint32_t cm55_mve_has_fp(void);
void cm55_mve_enable(void);
void cm55_mve_disable(void);

/* Vector Load/Store */
void cm55_mve_vldm(uint32_t *addr, uint32_t num_regs);
void cm55_mve_vstm(uint32_t *addr, uint32_t num_regs);

/* Predication */
void cm55_mve_set_vpr(uint32_t value);
uint32_t cm55_mve_get_vpr(void);
void cm55_mve_set_fpscr(uint32_t value);
uint32_t cm55_mve_get_fpscr(void);

/* Low Overhead Loop */
void cm55_mve_set_lpstart(uint32_t addr);
void cm55_mve_set_lpend(uint32_t addr);
void cm55_mve_set_lpcnt(uint32_t count);

#ifdef __cplusplus
}
#endif

#endif /* CM55_MVE_H */
