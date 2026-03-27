/*
 * arm_v7m_cm7.c
 * Cortex-M7 Architecture Abstraction Layer - Main Implementation
 * 
 * Reference: ARMv7-M Architecture Reference Manual
 *            - Chapter A1: ARMv7-M Architecture Overview
 *            - Section B1.6: Reset management on page B1-529
 *            - Section B1.4.2: Interrupt control on page B1-527
 *            - Section B1.5.3: Wait For Interrupt on page B1-531
 *            - Section B1.5.4: Wait For Event and Send Event on page B1-532
 *            - Section A3.7.3: Memory barriers on page A3-81
 *            - Section A3.5: Exclusive access on page A3-75
 * 
 *            Cortex-M7 Devices Generic User Guide
 *            - Chapter 1: Introduction on page 1-2
 *            - Section 1.1: About the Cortex-M7 processor and core peripherals on page 1-2
 *            - Chapter 2: The Cortex-M7 Processor
 *            - Section 2.1: Programmers model on page 2-2
 *            - Section 2.5: Power management on page 2-31
 *            - Chapter 4: Cortex-M7 Peripherals on page 4-2
 *            - Section 4.1: About the Cortex-M7 peripherals on page 4-2
 *            - Section 4.8: Cache control on page 4-61
 *            - Section 4.9.1: ITCMCR and DTCMCR on page 4-67
 * 
 *            Cortex-M7 Technical Reference Manual
 *            - Chapter 1: Introduction on page 1-2
 *            - Section 1.1: About the Cortex-M7 processor on page 1-2
 *            - Chapter 2: Programmers Model on page 2-2
 *            - Chapter 5.8: TCM interfaces on page 5-36
 *            - Chapter 5.9: L1 caches on page 5-41
 */

#include "arm_v7m_cm7.h"

/*============================================================================*
 * CM7 Extended Initialization
 *============================================================================*/

/**
 * @brief Extended initialization for Cortex-M7
 * 
 * Initializes CM7-specific features:
 * - Cache (I-Cache and D-Cache)
 * - TCM (ITCM and DTCM)
 * 
 * According to Cortex-M7 Devices Generic User Guide:
 * - Section 4.8: Cache control on page 4-61
 * - Section 4.9.1: ITCMCR and DTCMCR on page 4-67
 * 
 * @note Call this after arm_v7m_cm7_init() for full CM7 initialization.
 */
void arm_v7m_cm7_init_extended(void)
{
    /* Initialize TCM first (before cache, as TCM is not cached) */
    arm_v7m_cm7_tcm_init();
    
    /* Initialize cache */
    arm_v7m_cm7_cache_init();
}

/**
 * @brief Initialize Cortex-M7 cache
 * 
 * According to Cortex-M7 Devices Generic User Guide, Section 4.8 on page 4-61:
 * - Invalidate I-Cache before enabling
 * - Invalidate D-Cache before enabling
 * - Enable I-Cache and D-Cache
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.7.3:
 * - Use DSB to ensure cache operations complete
 * - Use ISB to ensure subsequent instructions use new cache state
 */
void arm_v7m_cm7_cache_init(void)
{
    /* Data Synchronization Barrier to ensure all previous operations complete */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Invalidate I-Cache */
    arm_v7m_cm7_cache_iciallu();
    
    /* Invalidate D-Cache */
    arm_v7m_cm7_cache_invalidate_dcache();
    
    /* Data Synchronization Barrier to ensure cache invalidation completes */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Instruction Synchronization Barrier to flush pipeline */
    __asm__ volatile ("isb" ::: "memory");
    
    /* Enable I-Cache */
    arm_v7m_cm7_cache_enable_icache();
    
    /* Enable D-Cache */
    arm_v7m_cm7_cache_enable_dcache();
    
    /* Data Synchronization Barrier to ensure cache enable completes */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Instruction Synchronization Barrier to flush pipeline */
    __asm__ volatile ("isb" ::: "memory");
}

/**
 * @brief Initialize Cortex-M7 TCM
 * 
 * According to Cortex-M7 Devices Generic User Guide, Section 4.9.1 on page 4-67:
 * - Check if TCM is implemented by reading SZ field
 * - Enable ITCM and DTCM if present
 * 
 * According to Cortex-M7 Technical Reference Manual, Section 4.1.5 on page 4-5:
 * - TCM interfaces can be enabled at reset by external signal
 * - If disabled at reset, software can enable them
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.7.3:
 * - Use DSB/ISB barriers when changing TCM state
 */
void arm_v7m_cm7_tcm_init(void)
{
    /* Data Synchronization Barrier to ensure all previous operations complete */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Check and enable ITCM if implemented */
    if (arm_v7m_cm7_itcm_is_implemented()) {
        arm_v7m_cm7_itcm_enable();
    }
    
    /* Check and enable DTCM if implemented */
    if (arm_v7m_cm7_dtcm_is_implemented()) {
        arm_v7m_cm7_dtcm_enable();
    }
    
    /* Data Synchronization Barrier to ensure TCM enable completes */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Instruction Synchronization Barrier to flush pipeline */
    __asm__ volatile ("isb" ::: "memory");
}
