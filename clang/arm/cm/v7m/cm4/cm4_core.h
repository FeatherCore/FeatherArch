/*
 * arm_v7m_cm4_core.h
 * Cortex-M4 Core Register Definitions
 * Reference: Cortex-M4 Devices Generic User Guide, Chapter 2.1
 *            Cortex-M4 Technical Reference Manual, Chapter 3.8
 *
 * @note This file reuses Armv7-M generic definitions as Cortex-M4
 *       is a standard Armv7-M implementation.
 */

#ifndef ARM_V7M_CM4_CORE_H
#define ARM_V7M_CM4_CORE_H

#include <stdint.h>
#include "../armv7m_core.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Type Aliases - Map CM4 types to generic Armv7-M types
 *============================================================================*/

typedef arm_v7m_core_regs_t     arm_v7m_cm4_core_regs_t;

/*============================================================================*
 * Inline Function Wrappers - Core Register Access
 *============================================================================*/

static inline uint32_t arm_v7m_cm4_get_msp(void) {
    return arm_v7m_get_msp();
}

static inline void arm_v7m_cm4_set_msp(uint32_t value) {
    arm_v7m_set_msp(value);
}

static inline uint32_t arm_v7m_cm4_get_psp(void) {
    return arm_v7m_get_psp();
}

static inline void arm_v7m_cm4_set_psp(uint32_t value) {
    arm_v7m_set_psp(value);
}

static inline uint32_t arm_v7m_cm4_get_primask(void) {
    return arm_v7m_get_primask();
}

static inline void arm_v7m_cm4_set_primask(uint32_t value) {
    arm_v7m_set_primask(value);
}

static inline uint32_t arm_v7m_cm4_get_faultmask(void) {
    return arm_v7m_get_faultmask();
}

static inline void arm_v7m_cm4_set_faultmask(uint32_t value) {
    arm_v7m_set_faultmask(value);
}

static inline uint32_t arm_v7m_cm4_get_basepri(void) {
    return arm_v7m_get_basepri();
}

static inline void arm_v7m_cm4_set_basepri(uint32_t value) {
    arm_v7m_set_basepri(value);
}

static inline uint32_t arm_v7m_cm4_get_control(void) {
    return arm_v7m_get_control();
}

static inline void arm_v7m_cm4_set_control(uint32_t value) {
    arm_v7m_set_control(value);
}

/*============================================================================*
 * APSR/IPSR/EPSR Register Access - Reuse generic implementations
 *============================================================================*/

static inline uint32_t arm_v7m_cm4_get_apsr(void) {
    return arm_v7m_get_apsr();
}

static inline void arm_v7m_cm4_set_apsr(uint32_t value) {
    arm_v7m_set_apsr(value);
}

static inline uint32_t arm_v7m_cm4_get_ipsr(void) {
    return arm_v7m_get_ipsr();
}

static inline uint32_t arm_v7m_cm4_get_epsr(void) {
    return arm_v7m_get_epsr();
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM4_CORE_H */
