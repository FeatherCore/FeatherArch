/*
 * arm_v8m_mve.h
 * Armv8-M M-Profile Vector Extension (MVE) Definitions
 * Reference: Armv8-M Architecture Reference Manual, Chapter B5
 */

#ifndef ARM_V8M_MVE_H
#define ARM_V8M_MVE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * MVE Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t MVFR0;
    volatile uint32_t MVFR1;
    volatile uint32_t MVFR2;
} arm_v8m_mve_regs_t;

/*============================================================================*
 * Vector Register File (Q0-Q7 for MVE)
 *============================================================================*/

typedef struct {
    uint32_t q[4];
} arm_v8m_vec128_t;

/*============================================================================*
 * MVE API Functions (Template)
 *============================================================================*/

uint32_t arm_v8m_mve_is_present(void);
uint32_t arm_v8m_mve_has_int(void);
uint32_t arm_v8m_mve_has_fp(void);
void arm_v8m_mve_enable(void);
void arm_v8m_mve_disable(void);

/* Vector Load/Store */
void arm_v8m_mve_vldm(uint32_t *addr, uint32_t num_regs);
void arm_v8m_mve_vstm(uint32_t *addr, uint32_t num_regs);

/* Predication */
void arm_v8m_mve_set_vpr(uint32_t value);
uint32_t arm_v8m_mve_get_vpr(void);
void arm_v8m_mve_set_fpscr(uint32_t value);
uint32_t arm_v8m_mve_get_fpscr(void);

/* Low Overhead Loop */
void arm_v8m_mve_set_lpstart(uint32_t addr);
void arm_v8m_mve_set_lpend(uint32_t addr);
void arm_v8m_mve_set_lpcnt(uint32_t count);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_MVE_H */
