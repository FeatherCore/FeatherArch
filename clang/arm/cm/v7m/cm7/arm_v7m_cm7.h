/*
 * cm7.h
 * Cortex-M7 Architecture Abstraction Layer - Master Header
 * Reference: Cortex-M7 Devices Generic User Guide
 *            Cortex-M7 Technical Reference Manual
 *
 * @note Cortex-M7 extends standard Armv7-M with Cache and TCM.
 *       Common features reuse generic Armv7-M definitions.
 *       Extended features have CM7-specific implementations.
 */

#ifndef ARM_V7M_CM7_H
#define ARM_V7M_CM7_H

#include <stdint.h>

/* Include generic Armv7-M definitions */
#include "../arm_v7m.h"

/* Include CM7-specific wrappers for common features */
#include "arm_v7m_cm7_core.h"
#include "arm_v7m_cm7_nvic.h"
#include "arm_v7m_cm7_systick.h"
#include "arm_v7m_cm7_scb.h"
#include "arm_v7m_cm7_mpu.h"
#include "arm_v7m_cm7_fpu.h"
#include "arm_v7m_cm7_debug.h"

/* Include CM7-specific extended features */
#include "arm_v7m_cm7_cache.h"
#include "arm_v7m_cm7_tcm.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Processor Version Information
 *============================================================================*/

#define ARM_V7M_CM7_PROCESSOR_VERSION      0x410FC270  /* r0p0 */
#define ARM_V7M_CM7_IMPLEMENTER_ARM        0x41
#define ARM_V7M_CM7_VARIANT                0x0
#define ARM_V7M_CM7_REVISION               0x0

/*============================================================================*
 * Global Initialization and Control (reuse generic)
 *============================================================================*/

static inline void arm_v7m_cm7_init(void) {
    arm_v7m_init();
}

static inline void arm_v7m_cm7_enable_irq(void) {
    arm_v7m_enable_irq();
}

static inline void arm_v7m_cm7_disable_irq(void) {
    arm_v7m_disable_irq();
}

static inline void arm_v7m_cm7_wait_for_interrupt(void) {
    arm_v7m_wait_for_interrupt();
}

static inline void arm_v7m_cm7_wait_for_event(void) {
    arm_v7m_wait_for_event();
}

static inline void arm_v7m_cm7_send_event(void) {
    arm_v7m_send_event();
}

/*============================================================================*
 * Memory Barriers (reuse generic)
 *============================================================================*/

static inline void arm_v7m_cm7_data_memory_barrier(void) {
    arm_v7m_data_memory_barrier();
}

static inline void arm_v7m_cm7_data_synchronization_barrier(void) {
    arm_v7m_data_synchronization_barrier();
}

static inline void arm_v7m_cm7_instruction_synchronization_barrier(void) {
    arm_v7m_instruction_synchronization_barrier();
}

/*============================================================================*
 * Exclusive Access (reuse generic)
 *============================================================================*/

static inline uint32_t arm_v7m_cm7_ldrex(uint32_t *addr) {
    return arm_v7m_ldrex(addr);
}

static inline uint32_t arm_v7m_cm7_strex(uint32_t value, uint32_t *addr) {
    return arm_v7m_strex(value, addr);
}

static inline void arm_v7m_cm7_clrex(void) {
    arm_v7m_clrex();
}

/*============================================================================*
 * CM7 Extended Initialization
 *============================================================================*/

void arm_v7m_cm7_init_extended(void);
void arm_v7m_cm7_cache_init(void);
void arm_v7m_cm7_tcm_init(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM7_H */
