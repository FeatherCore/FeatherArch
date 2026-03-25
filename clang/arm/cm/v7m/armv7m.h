/*
 * armv7m.h
 * Armv7-M Architecture Abstraction Layer - Master Header
 * Reference: ARMv7-M Architecture Reference Manual
 */

#ifndef ARMV7M_H
#define ARMV7M_H

#include <stdint.h>

#include "armv7m_core.h"
#include "armv7m_nvic.h"
#include "armv7m_systick.h"
#include "armv7m_scb.h"
#include "armv7m_mpu.h"
#include "armv7m_fpu.h"
#include "armv7m_debug.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Architecture Version Information
 *============================================================================*/

#define ARMV7M_ARCH_VERSION_MAJOR   7
#define ARMV7M_ARCH_VERSION_MINOR   0
#define ARMV7M_ARCH_PROFILE         'M'

/*============================================================================*
 * Global Initialization and Control
 *============================================================================*/

void armv7m_init(void);
void armv7m_enable_irq(void);
void armv7m_disable_irq(void);
void armv7m_wait_for_interrupt(void);
void armv7m_wait_for_event(void);
void armv7m_send_event(void);
void armv7m_data_memory_barrier(void);
void armv7m_data_synchronization_barrier(void);
void armv7m_instruction_synchronization_barrier(void);

#ifdef __cplusplus
}
#endif

#endif /* ARMV7M_H */
