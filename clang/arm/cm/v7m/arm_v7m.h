/*
 * arm_v7m.h
 * Armv7-M Architecture Abstraction Layer - Master Header
 * 
 * Reference: ARMv7-M Architecture Reference Manual
 *            - Chapter A1: ARMv7-M Architecture Overview
 *            - Section A2.1: Processor core registers on page A2-33
 *            - Section A3: Memory model on page A3-57
 *            - Section A3.4: Bit-band operations on page A3-71
 *            - Section A3.5: Exclusive access on page A3-75
 *            - Section A3.7.3: Memory barriers on page A3-81
 *            - Section B1.4.2: Interrupt control on page B1-527
 *            - Section B1.5: Power management on page B1-530
 *            - Section B1.5.3: Wait For Interrupt on page B1-531
 *            - Section B1.5.4: Wait For Event and Send Event on page B1-532
 * 
 *            Cortex-M7 Devices Generic User Guide
 *            - Chapter 1: Introduction on page 1-2
 *            - Chapter 2: The Cortex-M7 Processor
 *            - Section 2.1: Programmers model on page 2-2
 *            - Section 2.2: Memory model on page 2-12
 *            - Section 2.5: Power management on page 2-31
 * 
 *            Cortex-M7 Technical Reference Manual
 *            - Chapter 1: Introduction on page 1-2
 *            - Section 1.1: About the Cortex-M7 processor on page 1-2
 *            - Chapter 2: Programmers Model on page 2-2
 *            - Section 2.1: About the programmers model on page 2-2
 *            - Section 2.3: Register set on page 2-6
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

/**
 * @brief Initialize the ARMv7-M processor
 * 
 * According to ARMv7-M Architecture Reference Manual, Section B1.6:
 * - Configure vector table offset
 * - Set up priority grouping
 * - Initialize core peripherals as needed
 * 
 * @note This function should be called early in the startup sequence.
 */
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
