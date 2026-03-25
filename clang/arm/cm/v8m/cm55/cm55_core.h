/*
 * cm55_core.h
 * Cortex-M55 Core Register Definitions
 * Reference: Cortex-M55 Devices Generic User Guide, Chapter 3.1
 *            Cortex-M55 Technical Reference Manual, Chapter 4
 */

#ifndef CM55_CORE_H
#define CM55_CORE_H

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
} cm55_core_regs_t;

/*============================================================================*
 * Security State Definitions
 *============================================================================*/

typedef enum {
    CM55_STATE_SECURE = 0,
    CM55_STATE_NONSECURE = 1
} cm55_security_state_t;

/*============================================================================*
 * Special-Purpose Register Access Functions (Template)
 *============================================================================*/

uint32_t cm55_get_msp(void);
void cm55_set_msp(uint32_t value);
uint32_t cm55_get_psp(void);
void cm55_set_psp(uint32_t value);
uint32_t cm55_get_msplim(void);
void cm55_set_msplim(uint32_t value);
uint32_t cm55_get_psplim(void);
void cm55_set_psplim(uint32_t value);
uint32_t cm55_get_primask(void);
void cm55_set_primask(uint32_t value);
uint32_t cm55_get_faultmask(void);
void cm55_set_faultmask(uint32_t value);
uint32_t cm55_get_basepri(void);
void cm55_set_basepri(uint32_t value);
uint32_t cm55_get_control(void);
void cm55_set_control(uint32_t value);

/*============================================================================*
 * Security State Functions (Template) - TrustZone
 *============================================================================*/

cm55_security_state_t cm55_get_security_state(void);
void cm55_set_security_state(cm55_security_state_t state);
uint32_t cm55_get_msp_s(void);
void cm55_set_msp_s(uint32_t value);
uint32_t cm55_get_psp_s(void);
void cm55_set_psp_s(uint32_t value);
uint32_t cm55_get_msplim_s(void);
void cm55_set_msplim_s(uint32_t value);
uint32_t cm55_get_psplim_s(void);
void cm55_set_psplim_s(uint32_t value);

/*============================================================================*
 * TT Instruction - Test Target (Template)
 *============================================================================*/
uint32_t cm55_tt(uint32_t addr);
uint32_t cm55_ttt(uint32_t addr);
uint32_t cm55_tta(uint32_t addr);
uint32_t cm55_ttat(uint32_t addr);

#ifdef __cplusplus
}
#endif

#endif /* CM55_CORE_H */
