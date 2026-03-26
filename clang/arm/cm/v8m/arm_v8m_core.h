/*
 * arm_v8m_core.h
 * Armv8-M Core Register Definitions
 * Reference: Armv8-M Architecture Reference Manual, Chapter B3
 */

#ifndef ARM_V8M_CORE_H
#define ARM_V8M_CORE_H

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
} arm_v8m_core_regs_t;

/*============================================================================*
 * Security State Definitions
 *============================================================================*/

typedef enum {
    ARM_V8M_STATE_SECURE = 0,
    ARM_V8M_STATE_NONSECURE = 1
} arm_v8m_security_state_t;

/*============================================================================*
 * Special-Purpose Register Access Functions (Template)
 *============================================================================*/

uint32_t arm_v8m_get_msp(void);
void arm_v8m_set_msp(uint32_t value);
uint32_t arm_v8m_get_psp(void);
void arm_v8m_set_psp(uint32_t value);
uint32_t arm_v8m_get_msplim(void);
void arm_v8m_set_msplim(uint32_t value);
uint32_t arm_v8m_get_psplim(void);
void arm_v8m_set_psplim(uint32_t value);
uint32_t arm_v8m_get_primask(void);
void arm_v8m_set_primask(uint32_t value);
uint32_t arm_v8m_get_faultmask(void);
void arm_v8m_set_faultmask(uint32_t value);
uint32_t arm_v8m_get_basepri(void);
void arm_v8m_set_basepri(uint32_t value);
uint32_t arm_v8m_get_control(void);
void arm_v8m_set_control(uint32_t value);

/*============================================================================*
 * Security State Functions (Template)
 *============================================================================*/

arm_v8m_security_state_t arm_v8m_get_security_state(void);
void arm_v8m_set_security_state(arm_v8m_security_state_t state);
uint32_t arm_v8m_get_msp_s(void);
void arm_v8m_set_msp_s(uint32_t value);
uint32_t arm_v8m_get_psp_s(void);
void arm_v8m_set_psp_s(uint32_t value);
uint32_t arm_v8m_get_msplim_s(void);
void arm_v8m_set_msplim_s(uint32_t value);
uint32_t arm_v8m_get_psplim_s(void);
void arm_v8m_set_psplim_s(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CORE_H */
