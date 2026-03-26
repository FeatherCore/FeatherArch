/*
 * arm_v7m_cm7_scb.h
 * Cortex-M7 System Control Block (SCB) Definitions
 * Reference: Cortex-M7 Devices Generic User Guide, Chapter 4.3
 *
 * @note This file reuses Armv7-M generic SCB definitions.
 */

#ifndef ARM_V7M_CM7_SCB_H
#define ARM_V7M_CM7_SCB_H

#include <stdint.h>
#include "../armv7m_scb.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Type Aliases
 *============================================================================*/

typedef arm_v7m_scb_regs_t      arm_v7m_cm7_scb_regs_t;

/*============================================================================*
 * Inline Function Wrappers - SCB Operations
 *============================================================================*/

static inline void arm_v7m_cm7_scb_set_vector_table(uint32_t offset) {
    arm_v7m_scb_set_vector_table(offset);
}

static inline uint32_t arm_v7m_cm7_scb_get_vector_table(void) {
    return arm_v7m_scb_get_vector_table();
}

static inline void arm_v7m_cm7_scb_system_reset(void) {
    arm_v7m_scb_system_reset();
}

static inline void arm_v7m_cm7_scb_set_priority_grouping(uint32_t priority_group) {
    arm_v7m_scb_set_priority_grouping(priority_group);
}

static inline uint32_t arm_v7m_cm7_scb_get_priority_grouping(void) {
    return arm_v7m_scb_get_priority_grouping();
}

static inline void arm_v7m_cm7_scb_enable_fault(uint32_t fault) {
    arm_v7m_scb_enable_fault(fault);
}

static inline void arm_v7m_cm7_scb_disable_fault(uint32_t fault) {
    arm_v7m_scb_disable_fault(fault);
}

static inline uint32_t arm_v7m_cm7_scb_get_fault_status(void) {
    return arm_v7m_scb_get_fault_status();
}

static inline void arm_v7m_cm7_scb_clear_fault_status(void) {
    arm_v7m_scb_clear_fault_status();
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM7_SCB_H */
