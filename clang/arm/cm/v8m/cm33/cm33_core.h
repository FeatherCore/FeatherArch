/*
 * cm33_core.h
 * Cortex-M33 Core Register Definitions
 * Reference: Cortex-M33 Devices Generic User Guide, Chapter 2.1
 *            Cortex-M33 Technical Reference Manual, Chapter 2
 */

#ifndef CM33_CORE_H
#define CM33_CORE_H

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
} cm33_core_regs_t;

/*============================================================================*
 * Security State Definitions
 *============================================================================*/

typedef enum {
    CM33_STATE_SECURE = 0,
    CM33_STATE_NONSECURE = 1
} cm33_security_state_t;

/*============================================================================*
 * Special-Purpose Register Access Functions (Template)
 *============================================================================*/

uint32_t cm33_get_msp(void);
void cm33_set_msp(uint32_t value);
uint32_t cm33_get_psp(void);
void cm33_set_psp(uint32_t value);
uint32_t cm33_get_msplim(void);
void cm33_set_msplim(uint32_t value);
uint32_t cm33_get_psplim(void);
void cm33_set_psplim(uint32_t value);
uint32_t cm33_get_primask(void);
void cm33_set_primask(uint32_t value);
uint32_t cm33_get_faultmask(void);
void cm33_set_faultmask(uint32_t value);
uint32_t cm33_get_basepri(void);
void cm33_set_basepri(uint32_t value);
uint32_t cm33_get_control(void);
void cm33_set_control(uint32_t value);

/*============================================================================*
 * Security State Functions (Template) - TrustZone
 *============================================================================*/

cm33_security_state_t cm33_get_security_state(void);
void cm33_set_security_state(cm33_security_state_t state);
uint32_t cm33_get_msp_s(void);
void cm33_set_msp_s(uint32_t value);
uint32_t cm33_get_psp_s(void);
void cm33_set_psp_s(uint32_t value);
uint32_t cm33_get_msplim_s(void);
void cm33_set_msplim_s(uint32_t value);
uint32_t cm33_get_psplim_s(void);
void cm33_set_psplim_s(uint32_t value);

/*============================================================================*
 * TT Instruction - Test Target (Template)
 *============================================================================*/
uint32_t cm33_tt(uint32_t addr);
uint32_t cm33_ttt(uint32_t addr);
uint32_t cm33_tta(uint32_t addr);
uint32_t cm33_ttat(uint32_t addr);

#ifdef __cplusplus
}
#endif

#endif /* CM33_CORE_H */
