/**
 * @file arm_v8m_cm85_cache.c
 * @brief Cortex-M85 Cache implementation
 */

#include "arm_v8m_cm85_cache.h"
#include "arm_v8m_cm85_scb.h"

/* TODO: Implement Cache functions */

void arm_v8m_cm85_cache_enable_icache(void)
{
    /* TODO: Enable I-cache via SCB CCR */
}

void arm_v8m_cm85_cache_disable_icache(void)
{
    /* TODO: Disable I-cache via SCB CCR */
}

bool arm_v8m_cm85_cache_icache_enabled(void)
{
    /* TODO: Check if I-cache is enabled */
    return false;
}

void arm_v8m_cm85_cache_enable_dcache(void)
{
    /* TODO: Enable D-cache via SCB CCR */
}

void arm_v8m_cm85_cache_disable_dcache(void)
{
    /* TODO: Disable D-cache via SCB CCR */
}

bool arm_v8m_cm85_cache_dcache_enabled(void)
{
    /* TODO: Check if D-cache is enabled */
    return false;
}

void arm_v8m_cm85_cache_iciallu(void)
{
    /* TODO: Invalidate all I-cache */
}

void arm_v8m_cm85_cache_icimvau(uint32_t addr)
{
    /* TODO: Invalidate I-cache line by address */
    (void)addr;
}

void arm_v8m_cm85_cache_dcimvac(uint32_t addr)
{
    /* TODO: Invalidate D-cache line by address to PoC */
    (void)addr;
}

void arm_v8m_cm85_cache_dcisw(uint32_t setway)
{
    /* TODO: Invalidate D-cache line by set/way */
    (void)setway;
}

void arm_v8m_cm85_cache_dccmvau(uint32_t addr)
{
    /* TODO: Clean D-cache line by address to PoU */
    (void)addr;
}

void arm_v8m_cm85_cache_dccmvac(uint32_t addr)
{
    /* TODO: Clean D-cache line by address to PoC */
    (void)addr;
}

void arm_v8m_cm85_cache_dccsw(uint32_t setway)
{
    /* TODO: Clean D-cache line by set/way */
    (void)setway;
}

void arm_v8m_cm85_cache_dccimvac(uint32_t addr)
{
    /* TODO: Clean and Invalidate D-cache line by address to PoC */
    (void)addr;
}

void arm_v8m_cm85_cache_dccisw(uint32_t setway)
{
    /* TODO: Clean and Invalidate D-cache line by set/way */
    (void)setway;
}

void arm_v8m_cm85_cache_invalidate_dcache_range(uint32_t addr, uint32_t size)
{
    /* TODO: Invalidate D-cache range */
    (void)addr;
    (void)size;
}

void arm_v8m_cm85_cache_clean_dcache_range(uint32_t addr, uint32_t size)
{
    /* TODO: Clean D-cache range */
    (void)addr;
    (void)size;
}

void arm_v8m_cm85_cache_clean_invalidate_dcache_range(uint32_t addr, uint32_t size)
{
    /* TODO: Clean and Invalidate D-cache range */
    (void)addr;
    (void)size;
}

void arm_v8m_cm85_cache_bpiall(void)
{
    /* TODO: Invalidate all branch predictors */
}

void arm_v8m_cm85_cache_enable_branch_prediction(void)
{
    /* TODO: Enable branch prediction via SCB CCR */
}

void arm_v8m_cm85_cache_disable_branch_prediction(void)
{
    /* TODO: Disable branch prediction via SCB CCR */
}

void arm_v8m_cm85_cache_get_icache_info(arm_v8m_cm85_cache_info_t *info)
{
    /* TODO: Get I-cache information */
    if (info) {
        info->linesize = 0;
        info->ways = 0;
        info->sets = 0;
        info->size = 0;
    }
}

void arm_v8m_cm85_cache_get_dcache_info(arm_v8m_cm85_cache_info_t *info)
{
    /* TODO: Get D-cache information */
    if (info) {
        info->linesize = 0;
        info->ways = 0;
        info->sets = 0;
        info->size = 0;
    }
}

uint32_t arm_v8m_cm85_cache_get_clidr(void)
{
    /* TODO: Get CLIDR */
    return 0;
}

uint32_t arm_v8m_cm85_cache_get_ccsidr(uint32_t level, bool icache)
{
    /* TODO: Get CCSIDR for specified level */
    (void)level;
    (void)icache;
    return 0;
}

uint32_t arm_v8m_cm85_cache_get_ctr(void)
{
    /* TODO: Get CTR */
    return 0;
}

void arm_v8m_cm85_cache_dca_icache(uint32_t addr)
{
    /* TODO: Direct cache access for I-cache */
    (void)addr;
}

void arm_v8m_cm85_cache_dca_dcache(uint32_t addr)
{
    /* TODO: Direct cache access for D-cache */
    (void)addr;
}
