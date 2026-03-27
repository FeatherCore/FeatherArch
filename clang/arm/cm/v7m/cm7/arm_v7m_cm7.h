/*
 * arm_v7m_cm7.h
 * Cortex-M7 Architecture Abstraction Layer - Master Header
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
 * 
 *            Cortex-M7 Devices Generic User Guide
 *            - Chapter 1: Introduction on page 1-2
 *            - Section 1.1: About the Cortex-M7 processor and core peripherals on page 1-2
 *            - Chapter 2: The Cortex-M7 Processor
 *            - Section 2.1: Programmers model on page 2-2
 *            - Section 2.2: Memory model on page 2-12
 *            - Section 2.5: Power management on page 2-31
 *            - Chapter 4: Cortex-M7 Peripherals on page 4-2
 *            - Section 4.1: About the Cortex-M7 peripherals on page 4-2
 *            - Appendix A: Cortex-M7 processor options on page A-2
 * 
 *            Cortex-M7 Technical Reference Manual
 *            - Chapter 1: Introduction on page 1-2
 *            - Section 1.1: About the Cortex-M7 processor on page 1-2
 *            - Section 1.2: Component blocks on page 1-6
 *            - Chapter 2: Programmers Model on page 2-2
 *            - Section 2.1: About the programmers model on page 2-2
 *            - Section 2.3: Register set on page 2-6
 *            - Section 2.4: Memory model and memory attributes on page 2-7
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
#include "arm_v7m_cm7_ahb.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Processor Version Information
 *============================================================================*/

#define ARM_V7M_CM7_PROCESSOR_VERSION      0x410FC270U  /* r0p0 */
#define ARM_V7M_CM7_IMPLEMENTER_ARM        0x41U
#define ARM_V7M_CM7_VARIANT                0x0U
#define ARM_V7M_CM7_REVISION               0x0U

/*============================================================================*
 * Global Initialization and Control (reuse generic)
 *============================================================================*/

/**
 * @brief Initialize the Cortex-M7 processor
 * 
 * According to Cortex-M7 Devices Generic User Guide, Section 4.1 on page 4-2:
 * - Configure vector table
 * - Set up priority grouping
 * - Initialize SysTick if needed
 * - Configure MPU if present
 * - Enable I-Cache and D-Cache if present
 * - Configure ITCM/DTCM if present
 * - Enable FPU if present
 * 
 * @note This is a wrapper around arm_v7m_init() for compatibility.
 */
static inline void arm_v7m_cm7_init(void) {
    arm_v7m_init();
}

/**
 * @brief Enable interrupts
 * 
 * According to ARMv7-M Architecture Reference Manual, Section B1.4.2:
 * - Clears PRIMASK using CPSIE i instruction
 */
static inline void arm_v7m_cm7_enable_irq(void) {
    arm_v7m_enable_irq();
}

/**
 * @brief Disable interrupts
 * 
 * According to ARMv7-M Architecture Reference Manual, Section B1.4.2:
 * - Sets PRIMASK using CPSID i instruction
 */
static inline void arm_v7m_cm7_disable_irq(void) {
    arm_v7m_disable_irq();
}

/**
 * @brief Wait For Interrupt
 * 
 * According to ARMv7-M Architecture Reference Manual, Section B1.5.3:
 * - Suspends execution until interrupt, debug request, or reset
 */
static inline void arm_v7m_cm7_wait_for_interrupt(void) {
    arm_v7m_wait_for_interrupt();
}

/**
 * @brief Wait For Event
 * 
 * According to ARMv7-M Architecture Reference Manual, Section B1.5.4:
 * - Suspends execution until event, interrupt, debug request, or reset
 */
static inline void arm_v7m_cm7_wait_for_event(void) {
    arm_v7m_wait_for_event();
}

/**
 * @brief Send Event
 * 
 * According to ARMv7-M Architecture Reference Manual, Section B1.5.4:
 * - Generates a wake-up event
 */
static inline void arm_v7m_cm7_send_event(void) {
    arm_v7m_send_event();
}

/*============================================================================*
 * Memory Barriers (reuse generic)
 *============================================================================*/

/**
 * @brief Data Memory Barrier
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.7.3:
 * - Ensures memory access ordering
 */
static inline void arm_v7m_cm7_data_memory_barrier(void) {
    arm_v7m_data_memory_barrier();
}

/**
 * @brief Data Synchronization Barrier
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.7.3:
 * - Ensures completion of memory accesses
 */
static inline void arm_v7m_cm7_data_synchronization_barrier(void) {
    arm_v7m_data_synchronization_barrier();
}

/**
 * @brief Instruction Synchronization Barrier
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.7.3:
 * - Flushes the pipeline
 */
static inline void arm_v7m_cm7_instruction_synchronization_barrier(void) {
    arm_v7m_instruction_synchronization_barrier();
}

/*============================================================================*
 * Exclusive Access (reuse generic)
 *============================================================================*/

/**
 * @brief Load-Exclusive
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.5:
 * - Loads value from memory and marks exclusive access
 * @param addr Address to load from
 * @return Loaded value
 */
static inline uint32_t arm_v7m_cm7_ldrex(uint32_t *addr) {
    return arm_v7m_ldrex(addr);
}

/**
 * @brief Store-Exclusive
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.5:
 * - Stores value to memory if exclusive access is still valid
 * @param value Value to store
 * @param addr Address to store to
 * @return 0 if store succeeded, 1 if failed
 */
static inline uint32_t arm_v7m_cm7_strex(uint32_t value, uint32_t *addr) {
    return arm_v7m_strex(value, addr);
}

/**
 * @brief Clear-Exclusive
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.5:
 * - Clears the exclusive access tag
 */
static inline void arm_v7m_cm7_clrex(void) {
    arm_v7m_clrex();
}

/*============================================================================*
 * CM7 Extended Initialization
 *============================================================================*/

/**
 * @brief Extended initialization for Cortex-M7
 * 
 * Initializes CM7-specific features:
 * - Cache (I-Cache and D-Cache)
 * - TCM (ITCM and DTCM)
 * - AHB interface configuration
 * 
 * @note Call this after arm_v7m_cm7_init() for full CM7 initialization.
 */
void arm_v7m_cm7_init_extended(void);

/**
 * @brief Initialize Cortex-M7 cache
 * 
 * According to Cortex-M7 Devices Generic User Guide, Section 4.8 on page 4-61:
 * - Enables I-Cache and D-Cache
 * - Invalidates cache contents
 */
void arm_v7m_cm7_cache_init(void);

/**
 * @brief Initialize Cortex-M7 TCM
 * 
 * According to Cortex-M7 Devices Generic User Guide, Section 4.9.1 on page 4-67:
 * - Enables ITCM and DTCM if present
 */
void arm_v7m_cm7_tcm_init(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM7_H */
