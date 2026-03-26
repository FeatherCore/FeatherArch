/*
 * arm_v8m_cm33_core.h
 * Cortex-M33 Core Register Definitions
 * Reference: Cortex-M33 Devices Generic User Guide, Chapter 2.1
 *            Cortex-M33 Technical Reference Manual, Chapter 2
 *
 * @note This file reuses Armv8-M generic definitions as Cortex-M33
 *       is a standard Armv8-M implementation without extensions.
 */

#ifndef ARM_V8M_CM33_CORE_H
#define ARM_V8M_CM33_CORE_H

#include <stdint.h>
#include "../arm_v8m_core.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Type Aliases - Map CM33 types to generic Armv8-M types
 *============================================================================*/

typedef arm_v8m_core_regs_t         arm_v8m_cm33_core_regs_t;
typedef arm_v8m_security_state_t    arm_v8m_cm33_security_state_t;

/*============================================================================*
 * Constant Aliases
 *============================================================================*/

#define ARM_V8M_CM33_STATE_SECURE       ARM_V8M_STATE_SECURE
#define ARM_V8M_CM33_STATE_NONSECURE    ARM_V8M_STATE_NONSECURE

/*============================================================================*
 * Inline Function Wrappers - Core Register Access
 *============================================================================*/

static inline uint32_t arm_v8m_cm33_get_msp(void) {
    return arm_v8m_get_msp();
}

static inline void arm_v8m_cm33_set_msp(uint32_t value) {
    arm_v8m_set_msp(value);
}

static inline uint32_t arm_v8m_cm33_get_psp(void) {
    return arm_v8m_get_psp();
}

static inline void arm_v8m_cm33_set_psp(uint32_t value) {
    arm_v8m_set_psp(value);
}

static inline uint32_t arm_v8m_cm33_get_msplim(void) {
    return arm_v8m_get_msplim();
}

static inline void arm_v8m_cm33_set_msplim(uint32_t value) {
    arm_v8m_set_msplim(value);
}

static inline uint32_t arm_v8m_cm33_get_psplim(void) {
    return arm_v8m_get_psplim();
}

static inline void arm_v8m_cm33_set_psplim(uint32_t value) {
    arm_v8m_set_psplim(value);
}

static inline uint32_t arm_v8m_cm33_get_primask(void) {
    return arm_v8m_get_primask();
}

static inline void arm_v8m_cm33_set_primask(uint32_t value) {
    arm_v8m_set_primask(value);
}

static inline uint32_t arm_v8m_cm33_get_faultmask(void) {
    return arm_v8m_get_faultmask();
}

static inline void arm_v8m_cm33_set_faultmask(uint32_t value) {
    arm_v8m_set_faultmask(value);
}

static inline uint32_t arm_v8m_cm33_get_basepri(void) {
    return arm_v8m_get_basepri();
}

static inline void arm_v8m_cm33_set_basepri(uint32_t value) {
    arm_v8m_set_basepri(value);
}

static inline uint32_t arm_v8m_cm33_get_control(void) {
    return arm_v8m_get_control();
}

static inline void arm_v8m_cm33_set_control(uint32_t value) {
    arm_v8m_set_control(value);
}

/*============================================================================*
 * Security State Functions - TrustZone
 *============================================================================*/

static inline arm_v8m_cm33_security_state_t arm_v8m_cm33_get_security_state(void) {
    return arm_v8m_get_security_state();
}

static inline void arm_v8m_cm33_set_security_state(arm_v8m_cm33_security_state_t state) {
    arm_v8m_set_security_state((arm_v8m_security_state_t)state);
}

static inline uint32_t arm_v8m_cm33_get_msp_s(void) {
    return arm_v8m_get_msp_s();
}

static inline void arm_v8m_cm33_set_msp_s(uint32_t value) {
    arm_v8m_set_msp_s(value);
}

static inline uint32_t arm_v8m_cm33_get_psp_s(void) {
    return arm_v8m_get_psp_s();
}

static inline void arm_v8m_cm33_set_psp_s(uint32_t value) {
    arm_v8m_set_psp_s(value);
}

static inline uint32_t arm_v8m_cm33_get_msplim_s(void) {
    return arm_v8m_get_msplim_s();
}

static inline void arm_v8m_cm33_set_msplim_s(uint32_t value) {
    arm_v8m_set_msplim_s(value);
}

static inline uint32_t arm_v8m_cm33_get_psplim_s(void) {
    return arm_v8m_get_psplim_s();
}

static inline void arm_v8m_cm33_set_psplim_s(uint32_t value) {
    arm_v8m_set_psplim_s(value);
}

/*============================================================================*
 * TT Instruction - Test Target (Armv8-M Security Extension)
 *============================================================================*/

uint32_t arm_v8m_cm33_tt(uint32_t addr);
uint32_t arm_v8m_cm33_ttt(uint32_t addr);
uint32_t arm_v8m_cm33_tta(uint32_t addr);
uint32_t arm_v8m_cm33_ttat(uint32_t addr);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM33_CORE_H */
