/*
 * arm_v8m_ras.h
 * Armv8-M Reliability, Availability, and Serviceability (RAS) Extension
 * Reference: Armv8-M Architecture Reference Manual, Chapter B16
 */

#ifndef ARM_V8M_RAS_H
#define ARM_V8M_RAS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * RAS Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t ESB;
    volatile uint32_t IESB;
} arm_v8m_ras_regs_t;

/*============================================================================*
 * RAS Error Record Type
 *============================================================================*/

typedef struct {
    volatile uint64_t ERR_ADDR;
    volatile uint32_t ERR_CTRL;
    volatile uint32_t ERR_STATUS;
    volatile uint32_t ERR_MISC0;
    volatile uint32_t ERR_MISC1;
} arm_v8m_ras_error_record_t;

/*============================================================================*
 * RAS API Functions (Template)
 *============================================================================*/

uint32_t arm_v8m_ras_is_present(void);
void arm_v8m_ras_enable(void);
void arm_v8m_ras_disable(void);

/* Error Synchronization Barrier */
void arm_v8m_ras_esb(void);
void arm_v8m_ras_implicit_esb_enable(void);
void arm_v8m_ras_implicit_esb_disable(void);

/* Error Record Functions */
void arm_v8m_ras_select_error_record(uint32_t record_num);
uint32_t arm_v8m_ras_get_error_status(void);
void arm_v8m_ras_clear_error_status(void);
uint64_t arm_v8m_ras_get_error_address(void);
void arm_v8m_ras_clear_error_address(void);

/* Fault Handling */
uint32_t arm_v8m_ras_get_fault_status(void);
void arm_v8m_ras_clear_fault_status(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_RAS_H */
