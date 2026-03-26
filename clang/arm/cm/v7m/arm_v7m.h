/*
 * armv7m.h
 * Armv7-M Architecture Abstraction Layer - Master Header
 * Reference: ARMv7-M Architecture Reference Manual
 */

#ifndef ARM_V7M_H
#define ARM_V7M_H

#include <stdint.h>

#include "arm_v7m_instr.h"
#include "arm_v7m_core.h"
#include "arm_v7m_nvic.h"
#include "arm_v7m_systick.h"
#include "arm_v7m_scb.h"
#include "arm_v7m_mpu.h"
#include "arm_v7m_fpu.h"
#include "arm_v7m_debug.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Architecture Version Information
 *============================================================================*/

#define ARM_V7M_ARCH_VERSION_MAJOR   7
#define ARM_V7M_ARCH_VERSION_MINOR   0
#define ARM_V7M_ARCH_PROFILE         'M'

/*============================================================================*
 * Global Initialization and Control
 *============================================================================*/

void arm_v7m_init(void);

/* 
 * The following functions are provided by arm_v7m_core.h as inline functions:
 * - arm_v7m_enable_irq() / arm_v7m_disable_irq()
 * - arm_v7m_wfi() / arm_v7m_wfe() / arm_v7m_sev()
 * - arm_v7m_dmb() / arm_v7m_dsb() / arm_v7m_isb()
 * 
 * For compatibility, the following aliases are provided:
 */
#define arm_v7m_wait_for_interrupt          arm_v7m_wfi
#define arm_v7m_wait_for_event              arm_v7m_wfe
#define arm_v7m_send_event                   arm_v7m_sev
#define arm_v7m_data_memory_barrier          arm_v7m_dmb
#define arm_v7m_data_synchronization_barrier arm_v7m_dsb
#define arm_v7m_instruction_synchronization_barrier arm_v7m_isb

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_H */
