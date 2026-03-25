/*
 * armv8m_core.h
 * Armv8-M Core Register Definitions
 * Reference: Armv8-M Architecture Reference Manual, Chapter B3
 */

#ifndef ARMV8M_CORE_H
#define ARMV8M_CORE_H

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
} armv8m_core_regs_t;

/*============================================================================*
 * Security State Definitions
 *============================================================================*/

typedef enum {
    ARMV8M_STATE_SECURE = 0,
    ARMV8M_STATE_NONSECURE = 1
} armv8m_security_state_t;

/*============================================================================*
 * Special-Purpose Register Access Functions (Template)
 *============================================================================*/

uint32_t armv8m_get_msp(void);
void armv8m_set_msp(uint32_t value);
uint32_t armv8m_get_psp(void);
void armv8m_set_psp(uint32_t value);
uint32_t armv8m_get_msplim(void);
void armv8m_set_msplim(uint32_t value);
uint32_t armv8m_get_psplim(void);
void armv8m_set_psplim(uint32_t value);
uint32_t armv8m_get_primask(void);
void armv8m_set_primask(uint32_t value);
uint32_t armv8m_get_faultmask(void);
void armv8m_set_faultmask(uint32_t value);
uint32_t armv8m_get_basepri(void);
void armv8m_set_basepri(uint32_t value);
uint32_t armv8m_get_control(void);
void armv8m_set_control(uint32_t value);

/*============================================================================*
 * Security State Functions (Template)
 *============================================================================*/

armv8m_security_state_t armv8m_get_security_state(void);
void armv8m_set_security_state(armv8m_security_state_t state);
uint32_t armv8m_get_msp_s(void);
void armv8m_set_msp_s(uint32_t value);
uint32_t armv8m_get_psp_s(void);
void armv8m_set_psp_s(uint32_t value);
uint32_t armv8m_get_msplim_s(void);
void armv8m_set_msplim_s(uint32_t value);
uint32_t armv8m_get_psplim_s(void);
void armv8m_set_psplim_s(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* ARMV8M_CORE_H */
