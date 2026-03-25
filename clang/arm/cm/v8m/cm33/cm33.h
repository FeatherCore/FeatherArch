/*
 * cm33.h
 * Cortex-M33 Architecture Abstraction Layer - Master Header
 * Reference: Cortex-M33 Devices Generic User Guide
 *            Cortex-M33 Technical Reference Manual
 */

#ifndef CM33_H
#define CM33_H

#include <stdint.h>

#include "cm33_core.h"
#include "cm33_nvic.h"
#include "cm33_systick.h"
#include "cm33_scb.h"
#include "cm33_mpu.h"
#include "cm33_sau.h"
#include "cm33_fpu.h"
#include "cm33_cde.h"
#include "cm33_debug.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Processor Version Information
 *============================================================================*/

#define CM33_PROCESSOR_VERSION      0x410FD213  /* r1p0 */
#define CM33_IMPLEMENTER_ARM        0x41
#define CM33_VARIANT                0x0
#define CM33_REVISION               0x0

/*============================================================================*
 * Global Initialization and Control
 *============================================================================*/

void cm33_init(void);
void cm33_enable_irq(void);
void cm33_disable_irq(void);
void cm33_wait_for_interrupt(void);
void cm33_wait_for_event(void);
void cm33_send_event(void);

/*============================================================================*
 * Memory Barriers
 *============================================================================*/

void cm33_data_memory_barrier(void);
void cm33_data_synchronization_barrier(void);
void cm33_instruction_synchronization_barrier(void);

/*============================================================================*
 * Exclusive Access (LDREX/STREX)
 *============================================================================*/

uint32_t cm33_ldrex(uint32_t *addr);
uint32_t cm33_strex(uint32_t value, uint32_t *addr);
void cm33_clrex(void);

/*============================================================================*
 * Load-Acquire/Store-Release (Armv8-M)
 *============================================================================*/

uint32_t cm33_lda(uint32_t *addr);
void cm33_stl(uint32_t value, uint32_t *addr);
uint32_t cm33_ldaex(uint32_t *addr);
uint32_t cm33_stlex(uint32_t value, uint32_t *addr);

/*============================================================================*
 * Security State Transition (TrustZone)
 *============================================================================*/

void cm33_sg(void);
void cm33_bxns(uint32_t addr);
void cm33_blxns(uint32_t addr);

#ifdef __cplusplus
}
#endif

#endif /* CM33_H */
