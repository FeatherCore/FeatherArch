/*
 * arm_v8m_cm85_core.h
 * Cortex-M85 Core Register Definitions
 * Reference: Cortex-M85 Devices Generic User Guide
 *            Cortex-M85 Technical Reference Manual
 *
 * @note Cortex-M85 extends CM55 with PACBTI and enhanced features.
 *       Basic core registers reuse generic Armv8-M definitions.
 */

#ifndef ARM_V8M_CM85_CORE_H
#define ARM_V8M_CM85_CORE_H

#include <stdint.h>
#include "../arm_v8m_core.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Type Aliases - Basic Core Registers (same as generic Armv8-M)
 *============================================================================*/

typedef arm_v8m_core_regs_t         arm_v8m_cm85_core_regs_t;
typedef arm_v8m_security_state_t    arm_v8m_cm85_security_state_t;

/*============================================================================*
 * Constant Aliases
 *============================================================================*/

#define ARM_V8M_CM85_STATE_SECURE       ARM_V8M_STATE_SECURE
#define ARM_V8M_CM85_STATE_NONSECURE    ARM_V8M_STATE_NONSECURE

/*============================================================================*
 * Inline Function Wrappers - Core Register Access (reuse generic)
 *============================================================================*/

static inline uint32_t arm_v8m_cm85_get_msp(void) {
    return arm_v8m_get_msp();
}

static inline void arm_v8m_cm85_set_msp(uint32_t value) {
    arm_v8m_set_msp(value);
}

static inline uint32_t arm_v8m_cm85_get_psp(void) {
    return arm_v8m_get_psp();
}

static inline void arm_v8m_cm85_set_psp(uint32_t value) {
    arm_v8m_set_psp(value);
}

static inline uint32_t arm_v8m_cm85_get_msplim(void) {
    return arm_v8m_get_msplim();
}

static inline void arm_v8m_cm85_set_msplim(uint32_t value) {
    arm_v8m_set_msplim(value);
}

static inline uint32_t arm_v8m_cm85_get_psplim(void) {
    return arm_v8m_get_psplim();
}

static inline void arm_v8m_cm85_set_psplim(uint32_t value) {
    arm_v8m_set_psplim(value);
}

static inline uint32_t arm_v8m_cm85_get_primask(void) {
    return arm_v8m_get_primask();
}

static inline void arm_v8m_cm85_set_primask(uint32_t value) {
    arm_v8m_set_primask(value);
}

static inline uint32_t arm_v8m_cm85_get_faultmask(void) {
    return arm_v8m_get_faultmask();
}

static inline void arm_v8m_cm85_set_faultmask(uint32_t value) {
    arm_v8m_set_faultmask(value);
}

static inline uint32_t arm_v8m_cm85_get_basepri(void) {
    return arm_v8m_get_basepri();
}

static inline void arm_v8m_cm85_set_basepri(uint32_t value) {
    arm_v8m_set_basepri(value);
}

static inline uint32_t arm_v8m_cm85_get_control(void) {
    return arm_v8m_get_control();
}

static inline void arm_v8m_cm85_set_control(uint32_t value) {
    arm_v8m_set_control(value);
}

/*============================================================================*
 * Security State Functions - TrustZone (reuse generic)
 *============================================================================*/

static inline arm_v8m_cm85_security_state_t arm_v8m_cm85_get_security_state(void) {
    return arm_v8m_get_security_state();
}

static inline void arm_v8m_cm85_set_security_state(arm_v8m_cm85_security_state_t state) {
    arm_v8m_set_security_state((arm_v8m_security_state_t)state);
}

static inline uint32_t arm_v8m_cm85_get_msp_s(void) {
    return arm_v8m_get_msp_s();
}

static inline void arm_v8m_cm85_set_msp_s(uint32_t value) {
    arm_v8m_set_msp_s(value);
}

static inline uint32_t arm_v8m_cm85_get_psp_s(void) {
    return arm_v8m_get_psp_s();
}

static inline void arm_v8m_cm85_set_psp_s(uint32_t value) {
    arm_v8m_set_psp_s(value);
}

static inline uint32_t arm_v8m_cm85_get_msplim_s(void) {
    return arm_v8m_get_msplim_s();
}

static inline void arm_v8m_cm85_set_msplim_s(uint32_t value) {
    arm_v8m_set_msplim_s(value);
}

static inline uint32_t arm_v8m_cm85_get_psplim_s(void) {
    return arm_v8m_get_psplim_s();
}

static inline void arm_v8m_cm85_set_psplim_s(uint32_t value) {
    arm_v8m_set_psplim_s(value);
}

/*============================================================================*
 * TT Instruction - Test Target
 *============================================================================*/

uint32_t arm_v8m_cm85_tt(uint32_t addr);
uint32_t arm_v8m_cm85_ttt(uint32_t addr);
uint32_t arm_v8m_cm85_tta(uint32_t addr);
uint32_t arm_v8m_cm85_ttat(uint32_t addr);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM85_CORE_H */
