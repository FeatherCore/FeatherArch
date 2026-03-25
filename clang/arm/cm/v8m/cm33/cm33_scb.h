/*
 * cm33_scb.h
 * Cortex-M33 System Control Block (SCB) Definitions
 * Reference: Cortex-M33 Devices Generic User Guide, Chapter 4.2
 *            Cortex-M33 Technical Reference Manual, Chapter 3
 */

#ifndef CM33_SCB_H
#define CM33_SCB_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * SCB Type Definitions
 *============================================================================*/

typedef struct {
    volatile const uint32_t CPUID;
    volatile uint32_t ICSR;
    volatile uint32_t VTOR;
    volatile uint32_t AIRCR;
    volatile uint32_t SCR;
    volatile uint32_t CCR;
    volatile uint8_t  SHP[12];
    volatile uint32_t SHCSR;
    volatile uint32_t CFSR;
    volatile uint32_t HFSR;
    volatile uint32_t DFSR;
    volatile uint32_t MMFAR;
    volatile uint32_t BFAR;
    volatile uint32_t AFSR;
    volatile const uint32_t ID_PFR[2];
    volatile const uint32_t ID_DFR;
    volatile const uint32_t ID_ADR;
    volatile const uint32_t ID_MMFR[4];
    volatile const uint32_t ID_ISAR[5];
    uint32_t RESERVED0[5];
    volatile uint32_t CPACR;
} cm33_scb_regs_t;

/*============================================================================*
 * SCB API Functions (Template)
 *============================================================================*/

void cm33_scb_set_vector_table(uint32_t offset);
uint32_t cm33_scb_get_vector_table(void);
void cm33_scb_system_reset(void);
void cm33_scb_set_priority_grouping(uint32_t priority_group);
uint32_t cm33_scb_get_priority_grouping(void);
void cm33_scb_enable_fault(uint32_t fault);
void cm33_scb_disable_fault(uint32_t fault);
uint32_t cm33_scb_get_fault_status(void);
void cm33_scb_clear_fault_status(void);

/*============================================================================*
 * SCB Security Functions (Template) - TrustZone
 *============================================================================*/

void cm33_scb_set_vector_table_s(uint32_t offset);
uint32_t cm33_scb_get_vector_table_s(void);
void cm33_scb_system_reset_s(void);
void cm33_scb_set_aircr_s(uint32_t value);
uint32_t cm33_scb_get_aircr_s(void);

#ifdef __cplusplus
}
#endif

#endif /* CM33_SCB_H */
