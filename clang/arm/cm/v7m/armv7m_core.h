/*
 * arm_v7m_core.h
 * Armv7-M Core Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4, B5.2
 */

#ifndef ARM_V7M_CORE_H
#define ARM_V7M_CORE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Core Register Type Definitions
 *============================================================================*/

typedef struct {
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r4;
    uint32_t r5;
    uint32_t r6;
    uint32_t r7;
    uint32_t r8;
    uint32_t r9;
    uint32_t r10;
    uint32_t r11;
    uint32_t r12;
    uint32_t sp;
    uint32_t lr;
    uint32_t pc;
    uint32_t xpsr;
} arm_v7m_core_regs_t;

/*============================================================================*
 * APSR Register Bit Definitions
 *============================================================================*/

#define ARM_V7M_APSR_N_Pos                 31U
#define ARM_V7M_APSR_N_Msk                 (1UL << ARM_V7M_APSR_N_Pos)

#define ARM_V7M_APSR_Z_Pos                 30U
#define ARM_V7M_APSR_Z_Msk                 (1UL << ARM_V7M_APSR_Z_Pos)

#define ARM_V7M_APSR_C_Pos                 29U
#define ARM_V7M_APSR_C_Msk                 (1UL << ARM_V7M_APSR_C_Pos)

#define ARM_V7M_APSR_V_Pos                 28U
#define ARM_V7M_APSR_V_Msk                 (1UL << ARM_V7M_APSR_V_Pos)

#define ARM_V7M_APSR_Q_Pos                 27U
#define ARM_V7M_APSR_Q_Msk                 (1UL << ARM_V7M_APSR_Q_Pos)

/*============================================================================*
 * IPSR Register Bit Definitions
 *============================================================================*/

#define ARM_V7M_IPSR_ISR_Pos                0U
#define ARM_V7M_IPSR_ISR_Msk               (0x1FFUL << ARM_V7M_IPSR_ISR_Pos)

/*============================================================================*
 * EPSR Register Bit Definitions
 *============================================================================*/

#define ARM_V7M_EPSR_ICI_IT_1_Pos          10U
#define ARM_V7M_EPSR_ICI_IT_1_Msk          (0x3FUL << ARM_V7M_EPSR_ICI_IT_1_Pos)

#define ARM_V7M_EPSR_T_Pos                 24U
#define ARM_V7M_EPSR_T_Msk                 (1UL << ARM_V7M_EPSR_T_Pos)

#define ARM_V7M_EPSR_ICI_IT_2_Pos          25U
#define ARM_V7M_EPSR_ICI_IT_2_Msk          (0x3UL << ARM_V7M_EPSR_ICI_IT_2_Pos)

/*============================================================================*
 * CONTROL Register Bit Definitions
 *============================================================================*/

#define ARM_V7M_CONTROL_nPRIV_Pos           0U
#define ARM_V7M_CONTROL_nPRIV_Msk          (1UL << ARM_V7M_CONTROL_nPRIV_Pos)

#define ARM_V7M_CONTROL_SPSEL_Pos           1U
#define ARM_V7M_CONTROL_SPSEL_Msk          (1UL << ARM_V7M_CONTROL_SPSEL_Pos)

#define ARM_V7M_CONTROL_FPCA_Pos            2U
#define ARM_V7M_CONTROL_FPCA_Msk           (1UL << ARM_V7M_CONTROL_FPCA_Pos)

/*============================================================================*
 * Special-Purpose Register Access Functions
 *============================================================================*/

/* Main Stack Pointer (MSP) */
uint32_t arm_v7m_get_msp(void);
void arm_v7m_set_msp(uint32_t value);

/* Process Stack Pointer (PSP) */
uint32_t arm_v7m_get_psp(void);
void arm_v7m_set_psp(uint32_t value);

/* Priority Mask Register (PRIMASK) */
uint32_t arm_v7m_get_primask(void);
void arm_v7m_set_primask(uint32_t value);

/* Fault Mask Register (FAULTMASK) */
uint32_t arm_v7m_get_faultmask(void);
void arm_v7m_set_faultmask(uint32_t value);

/* Base Priority Register (BASEPRI) */
uint32_t arm_v7m_get_basepri(void);
void arm_v7m_set_basepri(uint32_t value);

/* Base Priority Max Register (BASEPRI_MAX) - Write only */
void arm_v7m_set_basepri_max(uint32_t value);

/* Control Register (CONTROL) */
uint32_t arm_v7m_get_control(void);
void arm_v7m_set_control(uint32_t value);

/*============================================================================*
 * APSR/IPSR/EPSR/XPSR Register Access
 *============================================================================*/

/* Application Program Status Register (APSR) */
uint32_t arm_v7m_get_apsr(void);
void arm_v7m_set_apsr(uint32_t value);
void arm_v7m_set_apsr_nzcvq(uint32_t value);

/* Interrupt Program Status Register (IPSR) - Read only */
uint32_t arm_v7m_get_ipsr(void);

/* Execution Program Status Register (EPSR) - Read only */
uint32_t arm_v7m_get_epsr(void);

/* Composite XPSR Register */
uint32_t arm_v7m_get_xpsr(void);
void arm_v7m_set_xpsr(uint32_t value);

/*============================================================================*
 * Interrupt Enable/Disable Functions (CPS Instructions)
 *============================================================================*/

/* Enable Interrupts (Clear PRIMASK) */
void arm_v7m_enable_irq(void);

/* Disable Interrupts (Set PRIMASK) */
void arm_v7m_disable_irq(void);

/* Enable Faults (Clear FAULTMASK) */
void arm_v7m_enable_fault(void);

/* Disable Faults (Set FAULTMASK) */
void arm_v7m_disable_fault(void);

/*============================================================================*
 * Instruction Synchronization Barrier
 *============================================================================*/

void arm_v7m_isb(void);
void arm_v7m_dsb(void);
void arm_v7m_dmb(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CORE_H */
