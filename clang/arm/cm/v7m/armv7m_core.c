/*
 * arm_v7m_core.c
 * Armv7-M Core Register Implementation
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4, B5.2
 *
 * Special Register Encodings (SYSm field):
 * - APSR:     0  (0b00000:000)
 * - IAPSR:    1  (0b00000:001)
 * - EAPSR:    2  (0b00000:010)
 * - XPSR:     3  (0b00000:011)
 * - IPSR:     5  (0b00000:101)
 * - EPSR:     6  (0b00000:110)
 * - IEPSR:    7  (0b00000:111)
 * - MSP:      8  (0b00001:000)
 * - PSP:      9  (0b00001:001)
 * - PRIMASK:  16 (0b00010:000)
 * - BASEPRI:  17 (0b00010:001)
 * - BASEPRI_MAX: 18 (0b00010:010)
 * - FAULTMASK: 19 (0b00010:011)
 * - CONTROL:  20 (0b00010:100)
 */

#include "armv7m_core.h"

/*============================================================================*
 * Main Stack Pointer (MSP) Access Functions
 * SYSm = 8 (0b00001:000)
 *============================================================================*/

uint32_t arm_v7m_get_msp(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, msp" : "=r" (result));
    return result;
}

void arm_v7m_set_msp(uint32_t value)
{
    __asm volatile ("MSR msp, %0" : : "r" (value));
}

/*============================================================================*
 * Process Stack Pointer (PSP) Access Functions
 * SYSm = 9 (0b00001:001)
 *============================================================================*/

uint32_t arm_v7m_get_psp(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, psp" : "=r" (result));
    return result;
}

void arm_v7m_set_psp(uint32_t value)
{
    __asm volatile ("MSR psp, %0" : : "r" (value));
}

/*============================================================================*
 * Priority Mask Register (PRIMASK) Access Functions
 * SYSm = 16 (0b00010:000)
 *============================================================================*/

uint32_t arm_v7m_get_primask(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, primask" : "=r" (result));
    return result;
}

void arm_v7m_set_primask(uint32_t value)
{
    __asm volatile ("MSR primask, %0" : : "r" (value));
}

/*============================================================================*
 * Fault Mask Register (FAULTMASK) Access Functions
 * SYSm = 19 (0b00010:011)
 *============================================================================*/

uint32_t arm_v7m_get_faultmask(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, faultmask" : "=r" (result));
    return result;
}

void arm_v7m_set_faultmask(uint32_t value)
{
    __asm volatile ("MSR faultmask, %0" : : "r" (value));
}

/*============================================================================*
 * Base Priority Register (BASEPRI) Access Functions
 * SYSm = 17 (0b00010:001)
 *============================================================================*/

uint32_t arm_v7m_get_basepri(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, basepri" : "=r" (result));
    return result;
}

void arm_v7m_set_basepri(uint32_t value)
{
    __asm volatile ("MSR basepri, %0" : : "r" (value));
}

/*============================================================================*
 * Base Priority Max Register (BASEPRI_MAX) Write Function
 * SYSm = 18 (0b00010:010)
 * Write-only: Only increases BASEPRI, ignored if would reduce it
 *============================================================================*/

void arm_v7m_set_basepri_max(uint32_t value)
{
    __asm volatile ("MSR basepri_max, %0" : : "r" (value));
}

/*============================================================================*
 * Control Register (CONTROL) Access Functions
 * SYSm = 20 (0b00010:100)
 *============================================================================*/

uint32_t arm_v7m_get_control(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, control" : "=r" (result));
    return result;
}

void arm_v7m_set_control(uint32_t value)
{
    __asm volatile ("MSR control, %0" : : "r" (value));
    /* ISB required after CONTROL write to ensure instruction fetch correctness */
    __asm volatile ("ISB");
}

/*============================================================================*
 * Application Program Status Register (APSR) Access Functions
 * SYSm = 0 (0b00000:000)
 *============================================================================*/

uint32_t arm_v7m_get_apsr(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, apsr" : "=r" (result));
    return result;
}

/* Set APSR with _nzcvq qualifier (N, Z, C, V, Q bits) - Recommended approach */
void arm_v7m_set_apsr(uint32_t value)
{
    __asm volatile ("MSR apsr_nzcvq, %0" : : "r" (value));
}

/* Set APSR with _nzcvq qualifier (N, Z, C, V, Q bits) */
void arm_v7m_set_apsr_nzcvq(uint32_t value)
{
    __asm volatile ("MSR apsr_nzcvq, %0" : : "r" (value));
}

/*============================================================================*
 * Interrupt Program Status Register (IPSR) Read Function
 * SYSm = 5 (0b00000:101)
 * Read-only: Contains the current exception number
 *============================================================================*/

uint32_t arm_v7m_get_ipsr(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, ipsr" : "=r" (result));
    return result;
}

/*============================================================================*
 * Execution Program Status Register (EPSR) Read Function
 * SYSm = 6 (0b00000:110)
 * Read-only: EPSR bits read as zero during normal execution
 *============================================================================*/

uint32_t arm_v7m_get_epsr(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, epsr" : "=r" (result));
    return result;
}

/*============================================================================*
 * Composite XPSR Register Access Functions
 * SYSm = 3 (0b00000:011)
 * Combines APSR, IPSR, and EPSR
 *============================================================================*/

uint32_t arm_v7m_get_xpsr(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, xpsr" : "=r" (result));
    return result;
}

/* Set XPSR - Note: Only APSR portion is writable, IPSR/EPSR are read-only */
void arm_v7m_set_xpsr(uint32_t value)
{
    /* Write to APSR portion only (bits 31:27), IPSR and EPSR are read-only */
    __asm volatile ("MSR apsr_nzcvq, %0" : : "r" (value));
}

/*============================================================================*
 * Interrupt Enable/Disable Functions (CPS Instructions)
 *============================================================================*/

/* Enable Interrupts: CPSIE i - Clears PRIMASK */
void arm_v7m_enable_irq(void)
{
    __asm volatile ("CPSIE i" : : : "memory");
}

/* Disable Interrupts: CPSID i - Sets PRIMASK */
void arm_v7m_disable_irq(void)
{
    __asm volatile ("CPSID i" : : : "memory");
}

/* Enable Faults: CPSIE f - Clears FAULTMASK */
void arm_v7m_enable_fault(void)
{
    __asm volatile ("CPSIE f" : : : "memory");
}

/* Disable Faults: CPSID f - Sets FAULTMASK */
void arm_v7m_disable_fault(void)
{
    __asm volatile ("CPSID f" : : : "memory");
}

/*============================================================================*
 * Memory Barrier Instructions
 *============================================================================*/

/* Instruction Synchronization Barrier */
void arm_v7m_isb(void)
{
    __asm volatile ("ISB" : : : "memory");
}

/* Data Synchronization Barrier */
void arm_v7m_dsb(void)
{
    __asm volatile ("DSB" : : : "memory");
}

/* Data Memory Barrier */
void arm_v7m_dmb(void)
{
    __asm volatile ("DMB" : : : "memory");
}
