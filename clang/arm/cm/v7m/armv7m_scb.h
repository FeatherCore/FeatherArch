/*
 * arm_v7m_scb.h
 * System Control Block (SCB) Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2
 */

#ifndef ARM_V7M_SCB_H
#define ARM_V7M_SCB_H

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
    volatile uint32_t SHPR[3];
    volatile uint32_t SHCSR;
    volatile uint32_t CFSR;
    volatile uint32_t HFSR;
    volatile uint32_t DFSR;
    volatile uint32_t MMFAR;
    volatile uint32_t BFAR;
    volatile uint32_t AFSR;
    volatile const uint32_t ID_PFR[2];
    volatile const uint32_t ID_DFR;
    volatile const uint32_t ID_AFR;
    volatile const uint32_t ID_MFR[4];
    volatile const uint32_t ID_ISAR[5];
    uint32_t RESERVED0[1];
    volatile const uint32_t CLIDR;
    volatile const uint32_t CTR;
    volatile const uint32_t CCSIDR;
    volatile uint32_t CSSELR;
    volatile uint32_t CPACR;
} arm_v7m_scb_regs_t;

/*============================================================================*
 * SCB API Functions (Template)
 *============================================================================*/

void arm_v7m_scb_set_vector_table(uint32_t offset);
uint32_t arm_v7m_scb_get_vector_table(void);
void arm_v7m_scb_system_reset(void);
void arm_v7m_scb_set_priority_grouping(uint32_t priority_group);
uint32_t arm_v7m_scb_get_priority_grouping(void);
void arm_v7m_scb_enable_fault_irq(void);
void arm_v7m_scb_disable_fault_irq(void);
void arm_v7m_scb_clear_fault_status(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_SCB_H */
