/*
 * cm4.h
 * Cortex-M4 Architecture Abstraction Layer - Master Header
 * Reference: Cortex-M4 Devices Generic User Guide
 *            Cortex-M4 Technical Reference Manual
 *
 * @note Cortex-M4 is a standard Armv7-M implementation.
 *       All generic Armv7-M features are reused through type aliases
 *       and inline wrapper functions.
 */

#ifndef ARM_V7M_CM4_H
#define ARM_V7M_CM4_H

#include <stdint.h>

/* Include generic Armv7-M definitions */
#include "../armv7m.h"

/* Include CM4-specific wrappers */
#include "arm_v7m_cm4_core.h"
#include "arm_v7m_cm4_nvic.h"
#include "arm_v7m_cm4_systick.h"
#include "arm_v7m_cm4_scb.h"
#include "arm_v7m_cm4_mpu.h"
#include "arm_v7m_cm4_fpu.h"
#include "arm_v7m_cm4_debug.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Processor Version Information
 *============================================================================*/

#define ARM_V7M_CM4_PROCESSOR_VERSION      0x410FC240  /* r0p0 */
#define ARM_V7M_CM4_IMPLEMENTER_ARM        0x41
#define ARM_V7M_CM4_VARIANT                0x0
#define ARM_V7M_CM4_REVISION               0x0

/*============================================================================*
 * Global Initialization and Control (reuse generic)
 *============================================================================*/

static inline void arm_v7m_cm4_init(void) {
    arm_v7m_init();
}

static inline void arm_v7m_cm4_enable_irq(void) {
    arm_v7m_enable_irq();
}

static inline void arm_v7m_cm4_disable_irq(void) {
    arm_v7m_disable_irq();
}

static inline void arm_v7m_cm4_wait_for_interrupt(void) {
    arm_v7m_wait_for_interrupt();
}

static inline void arm_v7m_cm4_wait_for_event(void) {
    arm_v7m_wait_for_event();
}

static inline void arm_v7m_cm4_send_event(void) {
    arm_v7m_send_event();
}

/*============================================================================*
 * Memory Barriers (reuse generic)
 *============================================================================*/

static inline void arm_v7m_cm4_data_memory_barrier(void) {
    arm_v7m_data_memory_barrier();
}

static inline void arm_v7m_cm4_data_synchronization_barrier(void) {
    arm_v7m_data_synchronization_barrier();
}

static inline void arm_v7m_cm4_instruction_synchronization_barrier(void) {
    arm_v7m_instruction_synchronization_barrier();
}

/*============================================================================*
 * Exclusive Access (reuse generic)
 *============================================================================*/

static inline uint32_t arm_v7m_cm4_ldrex(uint32_t *addr) {
    return arm_v7m_ldrex(addr);
}

static inline uint32_t arm_v7m_cm4_strex(uint32_t value, uint32_t *addr) {
    return arm_v7m_strex(value, addr);
}

static inline void arm_v7m_cm4_clrex(void) {
    arm_v7m_clrex();
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM4_H */
