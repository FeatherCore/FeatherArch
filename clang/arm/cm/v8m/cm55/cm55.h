/*
 * cm55.h
 * Cortex-M55 Architecture Abstraction Layer - Master Header
 * Reference: Cortex-M55 Devices Generic User Guide
 *            Cortex-M55 Technical Reference Manual
 */

#ifndef CM55_H
#define CM55_H

#include <stdint.h>

#include "cm55_core.h"
#include "cm55_nvic.h"
#include "cm55_systick.h"
#include "cm55_scb.h"
#include "cm55_mpu.h"
#include "cm55_sau.h"
#include "cm55_cache.h"
#include "cm55_tcm.h"
#include "cm55_fpu.h"
#include "cm55_mve.h"
#include "cm55_cde.h"
#include "cm55_epu.h"
#include "cm55_ras.h"
#include "cm55_pwr.h"
#include "cm55_debug.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Processor Version Information
 *============================================================================*/

#define CM55_PROCESSOR_VERSION      0x410FD231  /* r1p1 */
#define CM55_IMPLEMENTER_ARM        0x41
#define CM55_VARIANT                0x0
#define CM55_REVISION               0x1

/*============================================================================*
 * Global Initialization and Control
 *============================================================================*/

void cm55_init(void);
void cm55_enable_irq(void);
void cm55_disable_irq(void);
void cm55_wait_for_interrupt(void);
void cm55_wait_for_event(void);
void cm55_send_event(void);

/*============================================================================*
 * Memory Barriers
 *============================================================================*/

void cm55_data_memory_barrier(void);
void cm55_data_synchronization_barrier(void);
void cm55_instruction_synchronization_barrier(void);

/*============================================================================*
 * Exclusive Access (LDREX/STREX)
 *============================================================================*/

uint32_t cm55_ldrex(uint32_t *addr);
uint32_t cm55_strex(uint32_t value, uint32_t *addr);
void cm55_clrex(void);

/*============================================================================*
 * Load-Acquire/Store-Release (Armv8-M)
 *============================================================================*/

uint32_t cm55_lda(uint32_t *addr);
void cm55_stl(uint32_t value, uint32_t *addr);
uint32_t cm55_ldaex(uint32_t *addr);
uint32_t cm55_stlex(uint32_t value, uint32_t *addr);

/*============================================================================*
 * Security State Transition (TrustZone)
 *============================================================================*/

void cm55_sg(void);
void cm55_bxns(uint32_t addr);
void cm55_blxns(uint32_t addr);

#ifdef __cplusplus
}
#endif

#endif /* CM55_H */
