/*
 * armv8m.h
 * Armv8-M Architecture Abstraction Layer - Master Header
 * Reference: Armv8-M Architecture Reference Manual
 */

#ifndef ARM_V8M_H
#define ARM_V8M_H

#include <stdint.h>

#include "arm_v8m_core.h"
#include "arm_v8m_nvic.h"
#include "arm_v8m_systick.h"
#include "arm_v8m_scb.h"
#include "arm_v8m_mpu.h"
#include "arm_v8m_sau.h"
#include "arm_v8m_cache.h"
#include "arm_v8m_fpu.h"
#include "arm_v8m_mve.h"
#include "arm_v8m_pacbti.h"
#include "arm_v8m_pmu.h"
#include "arm_v8m_ras.h"
#include "arm_v8m_debug.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Architecture Version Information
 *============================================================================*/

#define ARM_V8M_ARCH_VERSION_MAJOR   8
#define ARM_V8M_ARCH_VERSION_MINOR   0
#define ARM_V8M_ARCH_PROFILE         'M'

/*============================================================================*
 * Global Initialization and Control
 *============================================================================*/

void arm_v8m_init(void);
void arm_v8m_enable_irq(void);
void arm_v8m_disable_irq(void);
void arm_v8m_wait_for_interrupt(void);
void arm_v8m_wait_for_event(void);
void arm_v8m_send_event(void);

/*============================================================================*
 * Memory Barriers
 *============================================================================*/

void arm_v8m_data_memory_barrier(void);
void arm_v8m_data_synchronization_barrier(void);
void arm_v8m_instruction_synchronization_barrier(void);

/*============================================================================*
 * New Memory Barriers (Armv8-M)
 *============================================================================*/

void arm_v8m_consumption_of_speculative_data_barrier(void);
void arm_v8m_physical_speculative_store_bypass_barrier(void);
void arm_v8m_speculative_store_bypass_barrier(void);

/*============================================================================*
 * Exclusive Access (LDREX/STREX)
 *============================================================================*/

uint32_t arm_v8m_ldrex(uint32_t *addr);
uint32_t arm_v8m_strex(uint32_t value, uint32_t *addr);
void arm_v8m_clrex(void);

/*============================================================================*
 * Load-Acquire/Store-Release (Armv8-M)
 *============================================================================*/

uint32_t arm_v8m_lda(uint32_t *addr);
void arm_v8m_stl(uint32_t value, uint32_t *addr);
uint32_t arm_v8m_ldaex(uint32_t *addr);
uint32_t arm_v8m_stlex(uint32_t value, uint32_t *addr);

/*============================================================================*
 * Bit-Band Operations
 *============================================================================*/

void arm_v8m_bitband_set(volatile uint32_t *addr, uint32_t bit);
void arm_v8m_bitband_clear(volatile uint32_t *addr, uint32_t bit);
uint32_t arm_v8m_bitband_read(volatile uint32_t *addr, uint32_t bit);

/*============================================================================*
 * Stack Limit Check (Armv8-M)
 *============================================================================*/

void arm_v8m_set_psplim(uint32_t limit);
uint32_t arm_v8m_get_psplim(void);
void arm_v8m_set_msplim(uint32_t limit);
uint32_t arm_v8m_get_msplim(void);

/*============================================================================*
 * Low Overhead Loop (Armv8-M MVE)
 *============================================================================*/

void arm_v8m_loop_start(uint32_t loop_addr);
void arm_v8m_loop_end(uint32_t end_addr);
void arm_v8m_loop_count(uint32_t count);

/*============================================================================*
 * Security State Transition (Armv8-M TrustZone)
 *============================================================================*/

void arm_v8m_sg(void);
void arm_v8m_bxns(uint32_t addr);
void arm_v8m_blxns(uint32_t addr);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_H */
