/*
 * cm85.h
 * Cortex-M85 Architecture Abstraction Layer - Master Header
 * Reference: Cortex-M85 Devices Generic User Guide
 *            Cortex-M85 Technical Reference Manual
 *
 * @note Cortex-M85 extends CM55 with PACBTI and coprocessor support.
 *       Common features reuse generic Armv8-M definitions.
 *       Extended features have CM85-specific implementations.
 */

#ifndef ARM_V8M_CM85_H
#define ARM_V8M_CM85_H

#include <stdint.h>

/* Include generic Armv8-M definitions */
#include "../armv8m.h"

/* Include CM85-specific wrappers for common features */
#include "arm_v8m_cm85_core.h"
#include "arm_v8m_cm85_nvic.h"
#include "arm_v8m_cm85_systick.h"
#include "arm_v8m_cm85_scb.h"
#include "arm_v8m_cm85_mpu.h"
#include "arm_v8m_cm85_sau.h"
#include "arm_v8m_cm85_fpu.h"
#include "arm_v8m_cm85_debug.h"

/* Include CM85-specific extended features (reuse CM55 wrappers) */
#include "arm_v8m_cm85_mve.h"
#include "arm_v8m_cm85_cache.h"
#include "arm_v8m_cm85_tcm.h"
#include "arm_v8m_cm85_pmu.h"
#include "arm_v8m_cm85_ras.h"

/* Include CM85-specific unique features */
#include "arm_v8m_cm85_pacbti.h"
#include "arm_v8m_cm85_coproc.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Processor Version Information
 *============================================================================*/

#define ARM_V8M_CM85_PROCESSOR_VERSION      0x410FD280  /* r0p0 */
#define ARM_V8M_CM85_IMPLEMENTER_ARM        0x41
#define ARM_V8M_CM85_VARIANT                0x0
#define ARM_V8M_CM85_REVISION               0x0

/*============================================================================*
 * Global Initialization and Control (reuse generic)
 *============================================================================*/

static inline void arm_v8m_cm85_init(void) {
    arm_v8m_init();
}

static inline void arm_v8m_cm85_enable_irq(void) {
    arm_v8m_enable_irq();
}

static inline void arm_v8m_cm85_disable_irq(void) {
    arm_v8m_disable_irq();
}

static inline void arm_v8m_cm85_wait_for_interrupt(void) {
    arm_v8m_wait_for_interrupt();
}

static inline void arm_v8m_cm85_wait_for_event(void) {
    arm_v8m_wait_for_event();
}

static inline void arm_v8m_cm85_send_event(void) {
    arm_v8m_send_event();
}

/*============================================================================*
 * Memory Barriers (reuse generic)
 *============================================================================*/

static inline void arm_v8m_cm85_data_memory_barrier(void) {
    arm_v8m_data_memory_barrier();
}

static inline void arm_v8m_cm85_data_synchronization_barrier(void) {
    arm_v8m_data_synchronization_barrier();
}

static inline void arm_v8m_cm85_instruction_synchronization_barrier(void) {
    arm_v8m_instruction_synchronization_barrier();
}

/*============================================================================*
 * Exclusive Access (reuse generic)
 *============================================================================*/

static inline uint32_t arm_v8m_cm85_ldrex(uint32_t *addr) {
    return arm_v8m_ldrex(addr);
}

static inline uint32_t arm_v8m_cm85_strex(uint32_t value, uint32_t *addr) {
    return arm_v8m_strex(value, addr);
}

static inline void arm_v8m_cm85_clrex(void) {
    arm_v8m_clrex();
}

/*============================================================================*
 * Load-Acquire/Store-Release (reuse generic)
 *============================================================================*/

static inline uint32_t arm_v8m_cm85_lda(uint32_t *addr) {
    return arm_v8m_lda(addr);
}

static inline void arm_v8m_cm85_stl(uint32_t value, uint32_t *addr) {
    arm_v8m_stl(value, addr);
}

static inline uint32_t arm_v8m_cm85_ldaex(uint32_t *addr) {
    return arm_v8m_ldaex(addr);
}

static inline uint32_t arm_v8m_cm85_stlex(uint32_t value, uint32_t *addr) {
    return arm_v8m_stlex(value, addr);
}

/*============================================================================*
 * Security State Transition (reuse generic)
 *============================================================================*/

static inline void arm_v8m_cm85_sg(void) {
    arm_v8m_sg();
}

static inline void arm_v8m_cm85_bxns(uint32_t addr) {
    arm_v8m_bxns(addr);
}

static inline void arm_v8m_cm85_blxns(uint32_t addr) {
    arm_v8m_blxns(addr);
}

/*============================================================================*
 * CM85 Extended Initialization
 *============================================================================*/

void arm_v8m_cm85_init_extended(void);
void arm_v8m_cm85_cache_init(void);
void arm_v8m_cm85_tcm_init(void);
void arm_v8m_cm85_mve_init(void);
void arm_v8m_cm85_pacbti_init(void);
void arm_v8m_cm85_coproc_init(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM85_H */
