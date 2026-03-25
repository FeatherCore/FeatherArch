/*
 * cm7.h
 * Cortex-M7 Architecture Abstraction Layer - Master Header
 * Reference: Cortex-M7 Devices Generic User Guide
 *            Cortex-M7 Technical Reference Manual
 */

#ifndef CM7_H
#define CM7_H

#include <stdint.h>

#include "cm7_core.h"
#include "cm7_nvic.h"
#include "cm7_systick.h"
#include "cm7_scb.h"
#include "cm7_mpu.h"
#include "cm7_cache.h"
#include "cm7_tcm.h"
#include "cm7_fpu.h"
#include "cm7_debug.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Processor Version Information
 *============================================================================*/

#define CM7_PROCESSOR_VERSION       0x410FC271  /* r1p2 */
#define CM7_IMPLEMENTER_ARM         0x41
#define CM7_VARIANT                 0x0
#define CM7_REVISION                0x2

/*============================================================================*
 * Global Initialization and Control
 *============================================================================*/

void cm7_init(void);
void cm7_enable_irq(void);
void cm7_disable_irq(void);
void cm7_wait_for_interrupt(void);
void cm7_wait_for_event(void);
void cm7_send_event(void);

/*============================================================================*
 * Memory Barriers
 *============================================================================*/

void cm7_data_memory_barrier(void);
void cm7_data_synchronization_barrier(void);
void cm7_instruction_synchronization_barrier(void);

/*============================================================================*
 * Exclusive Access (LDREX/STREX)
 *============================================================================*/

uint32_t cm7_ldrex(uint32_t *addr);
uint32_t cm7_strex(uint32_t value, uint32_t *addr);
void cm7_clrex(void);

/*============================================================================*
 * Bit-Band Operations
 *============================================================================*/

void cm7_bitband_set(volatile uint32_t *addr, uint32_t bit);
void cm7_bitband_clear(volatile uint32_t *addr, uint32_t bit);
uint32_t cm7_bitband_read(volatile uint32_t *addr, uint32_t bit);

#ifdef __cplusplus
}
#endif

#endif /* CM7_H */
