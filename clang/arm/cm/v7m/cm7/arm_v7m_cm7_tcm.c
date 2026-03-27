/*
 * arm_v7m_cm7_tcm.c
 * Cortex-M7 Tightly-Coupled Memory (TCM) Implementation
 * 
 * Reference: Cortex-M7 Devices Generic User Guide
 *            - Chapter 4.9: Access control on page 4-66
 *            - Section 4.9.1: Instruction and Data Tightly-Coupled Memory Control Registers on page 4-67
 *              * ITCMCR at address 0xE000EF90
 *              * DTCMCR at address 0xE000EF94
 *            - Section 4.9.2: AHBP Control Register on page 4-69
 *              * AHBPCR at address 0xE000EF98
 *            - Section 4.9.3: L1 Cache Control Register on page 4-70
 *              * CACR at address 0xE000EF9C
 *            - Section 4.9.4: AHB Slave Control Register on page 4-72
 *              * AHBSCR at address 0xE000EFA0
 *            - Section 4.9.5: Auxiliary Bus Fault Status register on page 4-73
 *              * ABFSR at address 0xE000EFA8
 * 
 *            Cortex-M7 Technical Reference Manual
 *            - Chapter 5.8: TCM interfaces on page 5-36
 *            - Section 4.1.5: Enabling the TCM on page 4-5
 *            - Section 1.3.6: TCM interface on page 1-11
 * 
 *            ARMv7-M Architecture Reference Manual
 *            - Section A3.7.3: Memory barriers on page A3-81
 *            - Section B3.2.15: Coprocessor Access Control Register, CPACR on page B3-614
 *            - Table B3-4: SCB registers summary (0xE000EF90-0xE000EFCF marked as IMPLEMENTATION DEFINED)
 * 
 * @note TCM is Cortex-M7 specific and not part of the base ARMv7-M architecture.
 *       The address range 0xE000EF90-0xE000EFCF is IMPLEMENTATION DEFINED in ARMv7-M.
 */

#include "arm_v7m_cm7_tcm.h"

/*============================================================================*
 * TCM Enable/Disable Operations
 *============================================================================*/

/**
 * @brief Enable both ITCM and DTCM with proper memory barriers
 * 
 * According to Cortex-M7 Devices Generic User Guide, Section 4.9.1 on page 4-67:
 * - When a TCM is disabled all accesses are made to the AXI master
 * - When enabled, accesses are mapped to the TCM interfaces
 * 
 * According to Cortex-M7 Technical Reference Manual, Section 4.1.5 on page 4-5:
 * - The TCM interfaces can be enabled at reset in the system by an external signal
 * - If disabled at reset, software can enable them using ITCMCR and DTCMCR
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.7.3 on page A3-81:
 * - DSB ensures all memory accesses complete before subsequent instructions
 * - ISB flushes the pipeline and ensures subsequent instructions use new context
 */
void arm_v7m_cm7_tcm_enable(void)
{
    /* Data Synchronization Barrier to ensure all previous memory accesses complete */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Enable Instruction TCM */
    ARM_V7M_CM7_TCM->ITCMCR |= ARM_V7M_CM7_ITCMCR_EN_Msk;
    
    /* Enable Data TCM */
    ARM_V7M_CM7_TCM->DTCMCR |= ARM_V7M_CM7_DTCMCR_EN_Msk;
    
    /* Data Synchronization Barrier to ensure TCM enable completes */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Instruction Synchronization Barrier to flush pipeline */
    __asm__ volatile ("isb" ::: "memory");
}

/**
 * @brief Disable both ITCM and DTCM with proper memory barriers
 * 
 * @warning Disabling TCM when code or data is being accessed from TCM can cause
 *          a fault. Ensure no active TCM accesses before disabling.
 */
void arm_v7m_cm7_tcm_disable(void)
{
    /* Data Synchronization Barrier to ensure all previous memory accesses complete */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Disable Instruction TCM */
    ARM_V7M_CM7_TCM->ITCMCR &= ~ARM_V7M_CM7_ITCMCR_EN_Msk;
    
    /* Disable Data TCM */
    ARM_V7M_CM7_TCM->DTCMCR &= ~ARM_V7M_CM7_DTCMCR_EN_Msk;
    
    /* Data Synchronization Barrier to ensure TCM disable completes */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Instruction Synchronization Barrier to flush pipeline */
    __asm__ volatile ("isb" ::: "memory");
}
