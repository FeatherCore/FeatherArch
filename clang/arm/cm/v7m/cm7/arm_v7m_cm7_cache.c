/*
 * arm_v7m_cm7_cache.c
 * Cortex-M7 Cache Maintenance Operations Implementation
 * Reference: ARMv7-M Architecture Reference Manual
 *            - Section B2.2: Cacheability attributes on page B2-570
 *            - Section B2.3: Caches on page B2-572
 *            - Section B2.3.1: Cache enabling and disabling on page B2-573
 *            - Section B2.3.2: Cache behavior at reset on page B2-574
 *            - Section B2.3.3: Cache maintenance operations on page B2-575
 *            - Section B3.2.16: Cache Size Selection Register, CSSELR on page B3-616
 *            - Section B3.2.17: Cache Size ID Register, CCSIDR on page B3-617
 *            - Section B3.2.18: Cache Level ID Register, CLIDR on page B3-618
 *            - Section B3.2.19: Cache Type Register, CTR on page B3-619
 *            - Section B3.2.20: Configuration and Control Register, CCR on page B3-619
 *            - Table B3-15: Cache maintenance operations on page B3-615
 *            Cortex-M7 Devices Generic User Guide, Chapter 4.5 and 4.8
 *            - Chapter 4.5: Optional processor feature registers on page 4-37
 *            - Chapter 4.8: Cache maintenance operations on page 4-61
 *            - Section 4.3.5: Configuration and Control Register (CCR) - IC/DC bits on page 4-19
 *            Cortex-M7 Technical Reference Manual, Chapter 5.9 and Section 3.3
 *            - Chapter 5.9: L1 caches on page 5-41
 *            - Section 3.3: Cache and branch predictor maintenance registers on page 3-8
 *            - Table 3-3: Cache and branch predictor maintenance operations on page 3-8
 *
 * This file wraps the generic Armv7-M cache implementation for Cortex-M7.
 * All functions delegate to the generic v7m implementation.
 *
 * @note Cache is optional in ARMv7-M but standard in Cortex-M7.
 */

#include "arm_v7m_cm7_cache.h"

/*============================================================================*
 * I-Cache Operations
 *============================================================================*/

/**
 * @brief Enable Instruction Cache
 */
void arm_v7m_cm7_icache_enable(void)
{
    arm_v7m_icache_enable();
}

/**
 * @brief Disable Instruction Cache
 */
void arm_v7m_cm7_icache_disable(void)
{
    arm_v7m_icache_disable();
}

/**
 * @brief Invalidate all Instruction Cache entries
 */
void arm_v7m_cm7_icache_invalidate_all(void)
{
    arm_v7m_icache_invalidate_all();
}

/**
 * @brief Invalidate Instruction Cache line by address
 * @param addr Address to invalidate
 */
void arm_v7m_cm7_icache_invalidate_line(uint32_t addr)
{
    arm_v7m_icache_invalidate_line(addr);
}

/**
 * @brief Check if Instruction Cache is enabled
 * @return 1 if enabled, 0 if disabled
 */
uint32_t arm_v7m_cm7_icache_is_enabled(void)
{
    return arm_v7m_icache_is_enabled();
}

/*============================================================================*
 * D-Cache Operations
 *============================================================================*/

/**
 * @brief Enable Data Cache
 */
void arm_v7m_cm7_dcache_enable(void)
{
    arm_v7m_dcache_enable();
}

/**
 * @brief Disable Data Cache
 */
void arm_v7m_cm7_dcache_disable(void)
{
    arm_v7m_dcache_disable();
}

/**
 * @brief Invalidate all Data Cache entries
 */
void arm_v7m_cm7_dcache_invalidate_all(void)
{
    arm_v7m_dcache_invalidate_all();
}

/**
 * @brief Clean all Data Cache entries
 */
void arm_v7m_cm7_dcache_clean_all(void)
{
    arm_v7m_dcache_clean_all();
}

/**
 * @brief Clean and Invalidate all Data Cache entries
 */
void arm_v7m_cm7_dcache_clean_invalidate_all(void)
{
    arm_v7m_dcache_clean_invalidate_all();
}

/**
 * @brief Invalidate Data Cache line by address
 * @param addr Address to invalidate
 */
void arm_v7m_cm7_dcache_invalidate_line(uint32_t addr)
{
    arm_v7m_dcache_invalidate_line(addr);
}

/**
 * @brief Clean Data Cache line by address
 * @param addr Address to clean
 */
void arm_v7m_cm7_dcache_clean_line(uint32_t addr)
{
    arm_v7m_dcache_clean_line(addr);
}

/**
 * @brief Clean and Invalidate Data Cache line by address
 * @param addr Address to clean and invalidate
 */
void arm_v7m_cm7_dcache_clean_invalidate_line(uint32_t addr)
{
    arm_v7m_dcache_clean_invalidate_line(addr);
}

/**
 * @brief Check if Data Cache is enabled
 * @return 1 if enabled, 0 if disabled
 */
uint32_t arm_v7m_cm7_dcache_is_enabled(void)
{
    return arm_v7m_dcache_is_enabled();
}

/*============================================================================*
 * Cache Info Functions
 *============================================================================*/

/**
 * @brief Get cache information
 * @param level Cache level (0 for L1)
 * @param ind Cache type (0=data, 1=instruction)
 * @param info Pointer to cache info structure to fill
 * @return 0 on success, 1 if cache not present
 */
uint32_t arm_v7m_cm7_cache_get_info(uint32_t level, uint32_t ind, arm_v7m_cm7_cache_info_t *info)
{
    return arm_v7m_cache_get_info(level, ind, (arm_v7m_cache_info_t *)info);
}

/**
 * @brief Get cache line size
 * @param level Cache level (0 for L1)
 * @param ind Cache type (0=data, 1=instruction)
 * @return Cache line size in bytes, or 0 if cache not present
 */
uint32_t arm_v7m_cm7_cache_get_line_size(uint32_t level, uint32_t ind)
{
    return arm_v7m_cache_get_line_size(level, ind);
}

/**
 * @brief Get I-Cache information
 * @param info Pointer to cache info structure to fill
 * @return 0 on success, 1 if I-Cache not present
 */
uint32_t arm_v7m_cm7_icache_get_info(arm_v7m_cm7_cache_info_t *info)
{
    return arm_v7m_icache_get_info((arm_v7m_cache_info_t *)info);
}

/**
 * @brief Get D-Cache information
 * @param info Pointer to cache info structure to fill
 * @return 0 on success, 1 if D-Cache not present
 */
uint32_t arm_v7m_cm7_dcache_get_info(arm_v7m_cm7_cache_info_t *info)
{
    return arm_v7m_dcache_get_info((arm_v7m_cache_info_t *)info);
}

/*============================================================================*
 * Cache Maintenance Range Functions
 *============================================================================*/

/**
 * @brief Invalidate D-Cache range
 * @param start Start address (inclusive)
 * @param end End address (exclusive)
 */
void arm_v7m_cm7_dcache_invalidate_range(uint32_t start, uint32_t end)
{
    arm_v7m_dcache_invalidate_range(start, end);
}

/**
 * @brief Clean D-Cache range
 * @param start Start address (inclusive)
 * @param end End address (exclusive)
 */
void arm_v7m_cm7_dcache_clean_range(uint32_t start, uint32_t end)
{
    arm_v7m_dcache_clean_range(start, end);
}

/**
 * @brief Clean and Invalidate D-Cache range
 * @param start Start address (inclusive)
 * @param end End address (exclusive)
 */
void arm_v7m_cm7_dcache_clean_invalidate_range(uint32_t start, uint32_t end)
{
    arm_v7m_dcache_clean_invalidate_range(start, end);
}
