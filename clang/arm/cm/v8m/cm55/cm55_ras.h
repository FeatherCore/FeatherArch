/*
 * arm_v8m_cm55_ras.h
 * Cortex-M55 Reliability, Availability, and Serviceability (RAS) Definitions
 * Reference: Cortex-M55 Technical Reference Manual, Chapter 4
 *
 * @note This file reuses Armv8-M generic RAS definitions.
 */

#ifndef ARM_V8M_CM55_RAS_H
#define ARM_V8M_CM55_RAS_H

#include <stdint.h>
#include "../armv8m_ras.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Type Aliases
 *============================================================================*/

typedef arm_v8m_ras_regs_t      arm_v8m_cm55_ras_regs_t;
typedef arm_v8m_ras_error_t     arm_v8m_cm55_ras_error_t;

/*============================================================================*
 * Constant Aliases - Error Record IDs
 *============================================================================*/

#define ARM_V8M_CM55_RAS_ERROR_CPU    ARM_V8M_RAS_ERROR_CPU

/*============================================================================*
 * Inline Function Wrappers - RAS Operations
 *============================================================================*/

static inline void arm_v8m_cm55_ras_enable(void) {
    arm_v8m_ras_enable();
}

static inline void arm_v8m_cm55_ras_disable(void) {
    arm_v8m_ras_disable();
}

static inline void arm_v8m_cm55_ras_select_error_record(uint32_t record_id) {
    arm_v8m_ras_select_error_record(record_id);
}

static inline uint32_t arm_v8m_cm55_ras_get_error_status(void) {
    return arm_v8m_ras_get_error_status();
}

static inline void arm_v8m_cm55_ras_clear_error_status(void) {
    arm_v8m_ras_clear_error_status();
}

static inline uint64_t arm_v8m_cm55_ras_get_error_address(void) {
    return arm_v8m_ras_get_error_address();
}

static inline uint32_t arm_v8m_cm55_ras_get_error_misc0(void) {
    return arm_v8m_ras_get_error_misc0();
}

static inline uint32_t arm_v8m_cm55_ras_get_error_misc1(void) {
    return arm_v8m_ras_get_error_misc1();
}

static inline void arm_v8m_cm55_ras_inject_error(arm_v8m_cm55_ras_error_t *error) {
    arm_v8m_ras_inject_error((arm_v8m_ras_error_t *)error);
}

static inline uint32_t arm_v8m_cm55_ras_get_fault_status(void) {
    return arm_v8m_ras_get_fault_status();
}

static inline void arm_v8m_cm55_ras_clear_fault_status(void) {
    arm_v8m_ras_clear_fault_status();
}

static inline uint32_t arm_v8m_cm55_ras_get_fault_address(void) {
    return arm_v8m_ras_get_fault_address();
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM55_RAS_H */
