/*
 * arm_v7m_cm7_cache.c
 * Cortex-M7 Cache Maintenance Operations Implementation
 * Reference: Cortex-M7 Devices Generic User Guide, Chapter 4.8
 */

#include "arm_v7m_cm7_cache.h"

/*============================================================================*
 * Cache Base Addresses (Architecture defined)
 *============================================================================*/
#define CACHE_BASE          0xE000EF50UL
#define CACHE_ID_BASE       0xE000ED00UL

#define CACHE               ((arm_v7m_cm7_cache_regs_t *)CACHE_BASE)
#define CACHE_ID            ((arm_v7m_cm7_cache_id_regs_t *)(CACHE_ID_BASE + 0x80))

/*============================================================================*
 * I-Cache Operations
 *============================================================================*/

void arm_v7m_cm7_iciallu(void)
{
    /* TODO: Execute ICIALLU instruction to invalidate all I-Cache */
}

void arm_v7m_cm7_icimvau(uint32_t addr)
{
    /* TODO: Execute ICIMVAU instruction to invalidate I-Cache line by address */
    (void)addr;
}

void arm_v7m_cm7_icache_enable(void)
{
    /* TODO: Set ICI bit in CCR */
}

void arm_v7m_cm7_icache_disable(void)
{
    /* TODO: Clear ICI bit in CCR */
}

void arm_v7m_cm7_icache_invalidate_all(void)
{
    /* TODO: Execute ICIALLU */
}

void arm_v7m_cm7_icache_invalidate_line(uint32_t addr)
{
    /* TODO: Execute ICIMVAU */
    (void)addr;
}

/*============================================================================*
 * D-Cache Operations
 *============================================================================*/

void arm_v7m_cm7_dcimvac(uint32_t addr)
{
    /* TODO: Execute DCIMVAC instruction to invalidate D-Cache line by address */
    (void)addr;
}

void arm_v7m_cm7_dcisw(uint32_t set_way)
{
    /* TODO: Execute DCISW instruction to invalidate D-Cache line by set/way */
    (void)set_way;
}

void arm_v7m_cm7_dccmvau(uint32_t addr)
{
    /* TODO: Execute DCCMVAU instruction to clean D-Cache line by address to PoU */
    (void)addr;
}

void arm_v7m_cm7_dccmvac(uint32_t addr)
{
    /* TODO: Execute DCCMVAC instruction to clean D-Cache line by address to PoC */
    (void)addr;
}

void arm_v7m_cm7_dccsw(uint32_t set_way)
{
    /* TODO: Execute DCCSW instruction to clean D-Cache line by set/way */
    (void)set_way;
}

void arm_v7m_cm7_dccimvac(uint32_t addr)
{
    /* TODO: Execute DCCIMVAC instruction to clean and invalidate D-Cache line by address */
    (void)addr;
}

void arm_v7m_cm7_dccisw(uint32_t set_way)
{
    /* TODO: Execute DCCISW instruction to clean and invalidate D-Cache line by set/way */
    (void)set_way;
}

void arm_v7m_cm7_dcache_enable(void)
{
    /* TODO: Set DC bit in CCR */
}

void arm_v7m_cm7_dcache_disable(void)
{
    /* TODO: Clear DC bit in CCR */
}

void arm_v7m_cm7_dcache_invalidate_all(void)
{
    /* TODO: Execute DCISW for all sets and ways */
}

void arm_v7m_cm7_dcache_clean_all(void)
{
    /* TODO: Execute DCCSW for all sets and ways */
}

void arm_v7m_cm7_dcache_clean_invalidate_all(void)
{
    /* TODO: Execute DCCISW for all sets and ways */
}

void arm_v7m_cm7_dcache_invalidate_line(uint32_t addr)
{
    /* TODO: Execute DCIMVAC */
    (void)addr;
}

void arm_v7m_cm7_dcache_clean_line(uint32_t addr)
{
    /* TODO: Execute DCCMVAC */
    (void)addr;
}

void arm_v7m_cm7_dcache_clean_invalidate_line(uint32_t addr)
{
    /* TODO: Execute DCCIMVAC */
    (void)addr;
}

/*============================================================================*
 * Cache ID Functions
 *============================================================================*/

uint32_t arm_v7m_cm7_cache_get_ccsidr(void)
{
    /* TODO: Read CCSIDR register */
    return 0;
}

void arm_v7m_cm7_cache_set_csselr(uint32_t level)
{
    /* TODO: Write CSSELR register */
    (void)level;
}

uint32_t arm_v7m_cm7_cache_get_csselr(void)
{
    /* TODO: Read CSSELR register */
    return 0;
}
