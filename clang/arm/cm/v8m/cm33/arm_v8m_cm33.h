/*
 * cm33.h
 * Cortex-M33 Architecture Abstraction Layer - Master Header
 * Reference: Cortex-M33 Devices Generic User Guide
 *            Cortex-M33 Technical Reference Manual
 *
 * @note Cortex-M33 is a standard Armv8-M implementation.
 *       All generic Armv8-M features are reused through type aliases
 *       and inline wrapper functions.
 */

#ifndef ARM_V8M_CM33_H
#define ARM_V8M_CM33_H

#include <stdint.h>

/* Include generic Armv8-M definitions */
#include "../arm_v8m.h"

/* Include CM33-specific wrappers */
#include "arm_v8m_cm33_core.h"
#include "arm_v8m_cm33_nvic.h"
#include "arm_v8m_cm33_systick.h"
#include "arm_v8m_cm33_scb.h"
#include "arm_v8m_cm33_mpu.h"
#include "arm_v8m_cm33_sau.h"
#include "arm_v8m_cm33_fpu.h"
#include "arm_v8m_cm33_cde.h"
#include "arm_v8m_cm33_debug.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Processor Version Information
 *============================================================================*/

#define ARM_V8M_CM33_PROCESSOR_VERSION      0x410FD213  /* r1p0 */
#define ARM_V8M_CM33_IMPLEMENTER_ARM        0x41
#define ARM_V8M_CM33_VARIANT                0x0
#define ARM_V8M_CM33_REVISION               0x0

/*============================================================================*
 * Global Initialization and Control
 *============================================================================*/

static inline void arm_v8m_cm33_init(void) {
    arm_v8m_init();
}

static inline void arm_v8m_cm33_enable_irq(void) {
    arm_v8m_enable_irq();
}

static inline void arm_v8m_cm33_disable_irq(void) {
    arm_v8m_disable_irq();
}

static inline void arm_v8m_cm33_wait_for_interrupt(void) {
    arm_v8m_wait_for_interrupt();
}

static inline void arm_v8m_cm33_wait_for_event(void) {
    arm_v8m_wait_for_event();
}

static inline void arm_v8m_cm33_send_event(void) {
    arm_v8m_send_event();
}

/*============================================================================*
 * Memory Barriers
 *============================================================================*/

static inline void arm_v8m_cm33_data_memory_barrier(void) {
    arm_v8m_data_memory_barrier();
}

static inline void arm_v8m_cm33_data_synchronization_barrier(void) {
    arm_v8m_data_synchronization_barrier();
}

static inline void arm_v8m_cm33_instruction_synchronization_barrier(void) {
    arm_v8m_instruction_synchronization_barrier();
}

/*============================================================================*
 * Exclusive Access (LDREX/STREX)
 *============================================================================*/

static inline uint32_t arm_v8m_cm33_ldrex(uint32_t *addr) {
    return arm_v8m_ldrex(addr);
}

static inline uint32_t arm_v8m_cm33_strex(uint32_t value, uint32_t *addr) {
    return arm_v8m_strex(value, addr);
}

static inline void arm_v8m_cm33_clrex(void) {
    arm_v8m_clrex();
}

/*============================================================================*
 * Load-Acquire/Store-Release (Armv8-M)
 *============================================================================*/

static inline uint32_t arm_v8m_cm33_lda(uint32_t *addr) {
    return arm_v8m_lda(addr);
}

static inline void arm_v8m_cm33_stl(uint32_t value, uint32_t *addr) {
    arm_v8m_stl(value, addr);
}

static inline uint32_t arm_v8m_cm33_ldaex(uint32_t *addr) {
    return arm_v8m_ldaex(addr);
}

static inline uint32_t arm_v8m_cm33_stlex(uint32_t value, uint32_t *addr) {
    return arm_v8m_stlex(value, addr);
}

/*============================================================================*
 * Security State Transition (TrustZone)
 *============================================================================*/

static inline void arm_v8m_cm33_sg(void) {
    arm_v8m_sg();
}

static inline void arm_v8m_cm33_bxns(uint32_t addr) {
    arm_v8m_bxns(addr);
}

static inline void arm_v8m_cm33_blxns(uint32_t addr) {
    arm_v8m_blxns(addr);
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM33_H */
