/*
 * arm_v8m_cm33_scb.h
 * Cortex-M33 System Control Block (SCB) Definitions
 * Reference: Cortex-M33 Technical Reference Manual, Chapter 4
 *
 * @note This file reuses Armv8-M generic SCB definitions.
 */

#ifndef ARM_V8M_CM33_SCB_H
#define ARM_V8M_CM33_SCB_H

#include <stdint.h>
#include "../armv8m_scb.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Type Aliases
 *============================================================================*/

typedef arm_v8m_scb_regs_t      arm_v8m_cm33_scb_regs_t;

/*============================================================================*
 * Inline Function Wrappers - SCB Operations
 *============================================================================*/

static inline void arm_v8m_cm33_scb_set_vector_table(uint32_t offset) {
    arm_v8m_scb_set_vector_table(offset);
}

static inline uint32_t arm_v8m_cm33_scb_get_vector_table(void) {
    return arm_v8m_scb_get_vector_table();
}

static inline void arm_v8m_cm33_scb_system_reset(void) {
    arm_v8m_scb_system_reset();
}

static inline void arm_v8m_cm33_scb_set_priority_grouping(uint32_t priority_group) {
    arm_v8m_scb_set_priority_grouping(priority_group);
}

static inline uint32_t arm_v8m_cm33_scb_get_priority_grouping(void) {
    return arm_v8m_scb_get_priority_grouping();
}

static inline void arm_v8m_cm33_scb_enable_fault(uint32_t fault) {
    arm_v8m_scb_enable_fault(fault);
}

static inline void arm_v8m_cm33_scb_disable_fault(uint32_t fault) {
    arm_v8m_scb_disable_fault(fault);
}

static inline uint32_t arm_v8m_cm33_scb_get_fault_status(void) {
    return arm_v8m_scb_get_fault_status();
}

static inline void arm_v8m_cm33_scb_clear_fault_status(void) {
    arm_v8m_scb_clear_fault_status();
}

/*============================================================================*
 * Security Functions - TrustZone
 *============================================================================*/

static inline void arm_v8m_cm33_scb_set_vector_table_s(uint32_t offset) {
    arm_v8m_scb_set_vector_table_s(offset);
}

static inline uint32_t arm_v8m_cm33_scb_get_vector_table_s(void) {
    return arm_v8m_scb_get_vector_table_s();
}

static inline void arm_v8m_cm33_scb_system_reset_s(void) {
    arm_v8m_scb_system_reset_s();
}

static inline void arm_v8m_cm33_scb_set_aircr_s(uint32_t value) {
    arm_v8m_scb_set_aircr_s(value);
}

static inline uint32_t arm_v8m_cm33_scb_get_aircr_s(void) {
    return arm_v8m_scb_get_aircr_s();
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM33_SCB_H */
