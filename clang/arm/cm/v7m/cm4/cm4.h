/*
 * cm4.h
 * Cortex-M4 Architecture Abstraction Layer - Master Header
 * Reference: Cortex-M4 Devices Generic User Guide
 *            Cortex-M4 Technical Reference Manual
 */

#ifndef CM4_H
#define CM4_H

#include <stdint.h>

#include "cm4_core.h"
#include "cm4_nvic.h"
#include "cm4_systick.h"
#include "cm4_scb.h"
#include "cm4_mpu.h"
#include "cm4_fpu.h"
#include "cm4_debug.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Processor Version Information
 *============================================================================*/

#define CM4_PROCESSOR_VERSION       0x410FC241  /* r0p1 */
#define CM4_IMPLEMENTER_ARM         0x41
#define CM4_VARIANT                 0x0
#define CM4_REVISION                0x1

/*============================================================================*
 * Global Initialization and Control
 *============================================================================*/

void cm4_init(void);
void cm4_enable_irq(void);
void cm4_disable_irq(void);
void cm4_wait_for_interrupt(void);
void cm4_wait_for_event(void);
void cm4_send_event(void);

/*============================================================================*
 * Memory Barriers
 *============================================================================*/

void cm4_data_memory_barrier(void);
void cm4_data_synchronization_barrier(void);
void cm4_instruction_synchronization_barrier(void);

/*============================================================================*
 * Exclusive Access (LDREX/STREX)
 *============================================================================*/

uint32_t cm4_ldrex(uint32_t *addr);
uint32_t cm4_strex(uint32_t value, uint32_t *addr);
void cm4_clrex(void);

/*============================================================================*
 * Bit-Band Operations
 *============================================================================*/

void cm4_bitband_set(volatile uint32_t *addr, uint32_t bit);
void cm4_bitband_clear(volatile uint32_t *addr, uint32_t bit);
uint32_t cm4_bitband_read(volatile uint32_t *addr, uint32_t bit);

#ifdef __cplusplus
}
#endif

#endif /* CM4_H */
