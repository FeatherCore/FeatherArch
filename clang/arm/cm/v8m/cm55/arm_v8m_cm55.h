/*
 * cm55.h
 * Cortex-M55 Architecture Abstraction Layer - Master Header
 * Reference: Cortex-M55 Devices Generic User Guide
 *            Cortex-M55 Technical Reference Manual
 *
 * @note Cortex-M55 extends standard Armv8-M with MVE, Cache, TCM, PMU, RAS.
 *       Common features reuse generic Armv8-M definitions.
 *       Extended features have CM55-specific implementations.
 */

#ifndef ARM_V8M_CM55_H
#define ARM_V8M_CM55_H

#include <stdint.h>

/* Include generic Armv8-M definitions */
#include "../arm_v8m.h"

/* Include CM55-specific wrappers for common features */
#include "arm_v8m_cm55_core.h"
#include "arm_v8m_cm55_nvic.h"
#include "arm_v8m_cm55_systick.h"
#include "arm_v8m_cm55_scb.h"
#include "arm_v8m_cm55_mpu.h"
#include "arm_v8m_cm55_sau.h"
#include "arm_v8m_cm55_fpu.h"
#include "arm_v8m_cm55_debug.h"

/* Include CM55-specific extended features */
#include "arm_v8m_cm55_mve.h"
#include "arm_v8m_cm55_cache.h"
#include "arm_v8m_cm55_tcm.h"
#include "arm_v8m_cm55_pmu.h"
#include "arm_v8m_cm55_ras.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Processor Version Information
 *============================================================================*/

#define ARM_V8M_CM55_PROCESSOR_VERSION      0x410FD220  /* r0p0 */
#define ARM_V8M_CM55_IMPLEMENTER_ARM        0x41
#define ARM_V8M_CM55_VARIANT                0x0
#define ARM_V8M_CM55_REVISION               0x0

/*============================================================================*
 * Global Initialization and Control (reuse generic)
 *============================================================================*/

static inline void arm_v8m_cm55_init(void) {
    arm_v8m_init();
}

static inline void arm_v8m_cm55_enable_irq(void) {
    arm_v8m_enable_irq();
}

static inline void arm_v8m_cm55_disable_irq(void) {
    arm_v8m_disable_irq();
}

static inline void arm_v8m_cm55_wait_for_interrupt(void) {
    arm_v8m_wait_for_interrupt();
}

static inline void arm_v8m_cm55_wait_for_event(void) {
    arm_v8m_wait_for_event();
}

static inline void arm_v8m_cm55_send_event(void) {
    arm_v8m_send_event();
}

/*============================================================================*
 * Memory Barriers (reuse generic)
 *============================================================================*/

static inline void arm_v8m_cm55_data_memory_barrier(void) {
    arm_v8m_data_memory_barrier();
}

static inline void arm_v8m_cm55_data_synchronization_barrier(void) {
    arm_v8m_data_synchronization_barrier();
}

static inline void arm_v8m_cm55_instruction_synchronization_barrier(void) {
    arm_v8m_instruction_synchronization_barrier();
}

/*============================================================================*
 * Exclusive Access (reuse generic)
 *============================================================================*/

static inline uint32_t arm_v8m_cm55_ldrex(uint32_t *addr) {
    return arm_v8m_ldrex(addr);
}

static inline uint32_t arm_v8m_cm55_strex(uint32_t value, uint32_t *addr) {
    return arm_v8m_strex(value, addr);
}

static inline void arm_v8m_cm55_clrex(void) {
    arm_v8m_clrex();
}

/*============================================================================*
 * Load-Acquire/Store-Release (reuse generic)
 *============================================================================*/

static inline uint32_t arm_v8m_cm55_lda(uint32_t *addr) {
    return arm_v8m_lda(addr);
}

static inline void arm_v8m_cm55_stl(uint32_t value, uint32_t *addr) {
    arm_v8m_stl(value, addr);
}

static inline uint32_t arm_v8m_cm55_ldaex(uint32_t *addr) {
    return arm_v8m_ldaex(addr);
}

static inline uint32_t arm_v8m_cm55_stlex(uint32_t value, uint32_t *addr) {
    return arm_v8m_stlex(value, addr);
}

/*============================================================================*
 * Security State Transition (reuse generic)
 *============================================================================*/

static inline void arm_v8m_cm55_sg(void) {
    arm_v8m_sg();
}

static inline void arm_v8m_cm55_bxns(uint32_t addr) {
    arm_v8m_bxns(addr);
}

static inline void arm_v8m_cm55_blxns(uint32_t addr) {
    arm_v8m_blxns(addr);
}

/*============================================================================*
 * CM55 Extended Initialization
 *============================================================================*/

void arm_v8m_cm55_init_extended(void);
void arm_v8m_cm55_cache_init(void);
void arm_v8m_cm55_tcm_init(void);
void arm_v8m_cm55_mve_init(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM55_H */
