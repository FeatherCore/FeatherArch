/*
 * cm4_core.h
 * Cortex-M4 Core Register Definitions
 * Reference: Cortex-M4 Devices Generic User Guide, Chapter 2.1
 *            Cortex-M4 Technical Reference Manual, Chapter 3.8
 */

#ifndef CM4_CORE_H
#define CM4_CORE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Core Register Type Definitions
 *============================================================================*/

typedef struct {
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r4;
    uint32_t r5;
    uint32_t r6;
    uint32_t r7;
    uint32_t r8;
    uint32_t r9;
    uint32_t r10;
    uint32_t r11;
    uint32_t r12;
    uint32_t sp;
    uint32_t lr;
    uint32_t pc;
    uint32_t xpsr;
} cm4_core_regs_t;

/*============================================================================*
 * Special-Purpose Register Access Functions (Template)
 *============================================================================*/

uint32_t cm4_get_msp(void);
void cm4_set_msp(uint32_t value);
uint32_t cm4_get_psp(void);
void cm4_set_psp(uint32_t value);
uint32_t cm4_get_primask(void);
void cm4_set_primask(uint32_t value);
uint32_t cm4_get_faultmask(void);
void cm4_set_faultmask(uint32_t value);
uint32_t cm4_get_basepri(void);
void cm4_set_basepri(uint32_t value);
uint32_t cm4_get_control(void);
void cm4_set_control(uint32_t value);

/*============================================================================*
 * APSR Register Access (Template)
 *============================================================================*/

uint32_t cm4_get_apsr(void);
void cm4_set_apsr(uint32_t value);
uint32_t cm4_get_ipsr(void);
uint32_t cm4_get_epsr(void);

#ifdef __cplusplus
}
#endif

#endif /* CM4_CORE_H */
