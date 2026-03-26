/*
 * arm_v8m_cm55_debug.h
 * Cortex-M55 Debug Support Definitions
 * Reference: Cortex-M55 Technical Reference Manual, Chapter 12
 *
 * @note This file reuses Armv8-M generic debug definitions.
 */

#ifndef ARM_V8M_CM55_DEBUG_H
#define ARM_V8M_CM55_DEBUG_H

#include <stdint.h>
#include "../armv8m_debug.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Inline Function Wrappers - Debug Operations
 *============================================================================*/

static inline void arm_v8m_cm55_debug_enable_trace(void) {
    arm_v8m_debug_enable_trace();
}

static inline void arm_v8m_cm55_debug_disable_trace(void) {
    arm_v8m_debug_disable_trace();
}

static inline uint32_t arm_v8m_cm55_debug_is_halted(void) {
    return arm_v8m_debug_is_halted();
}

static inline void arm_v8m_cm55_debug_halt(void) {
    arm_v8m_debug_halt();
}

static inline void arm_v8m_cm55_debug_resume(void) {
    arm_v8m_debug_resume();
}

static inline void arm_v8m_cm55_debug_step(void) {
    arm_v8m_debug_step();
}

/*============================================================================*
 * DWT (Data Watchpoint and Trace) Wrappers
 *============================================================================*/

static inline void arm_v8m_cm55_dwt_enable_cyccnt(void) {
    arm_v8m_dwt_enable_cyccnt();
}

static inline void arm_v8m_cm55_dwt_disable_cyccnt(void) {
    arm_v8m_dwt_disable_cyccnt();
}

static inline uint32_t arm_v8m_cm55_dwt_get_cyccnt(void) {
    return arm_v8m_dwt_get_cyccnt();
}

static inline void arm_v8m_cm55_dwt_set_cyccnt(uint32_t value) {
    arm_v8m_dwt_set_cyccnt(value);
}

static inline void arm_v8m_cm55_dwt_enable_exception_trace(void) {
    arm_v8m_dwt_enable_exception_trace();
}

static inline void arm_v8m_cm55_dwt_enable_pc_sampling(uint32_t interval) {
    arm_v8m_dwt_enable_pc_sampling(interval);
}

/*============================================================================*
 * FPB (Flash Patch and Breakpoint) Wrappers
 *============================================================================*/

static inline void arm_v8m_cm55_fpb_enable(void) {
    arm_v8m_fpb_enable();
}

static inline void arm_v8m_cm55_fpb_disable(void) {
    arm_v8m_fpb_disable();
}

static inline void arm_v8m_cm55_fpb_set_breakpoint(uint32_t comp_id, uint32_t addr) {
    arm_v8m_fpb_set_breakpoint(comp_id, addr);
}

static inline void arm_v8m_cm55_fpb_clear_breakpoint(uint32_t comp_id) {
    arm_v8m_fpb_clear_breakpoint(comp_id);
}

/*============================================================================*
 * Authentication Status Wrappers
 *============================================================================*/

static inline uint32_t arm_v8m_cm55_debug_get_auth_status(void) {
    return arm_v8m_debug_get_auth_status();
}

static inline void arm_v8m_cm55_debug_set_auth(uint32_t dbgen, uint32_t spiden) {
    arm_v8m_debug_set_auth(dbgen, spiden);
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM55_DEBUG_H */
