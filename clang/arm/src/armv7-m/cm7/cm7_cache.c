/*
 * ARM Architecture - Cortex-M7 Cache Maintenance Operations
 *
 * ============================================================================
 * File: cm7_cache.c
 * Description: Cortex-M7 Cache Maintenance Operations implementation
 * 描述: Cortex-M7 缓存维护操作实现
 *
 * @reference Arm Cortex-M7 Processor Technical Reference Manual
 *   - Section 3.2 Register summary, Table 3-1 System control registers
 *   - Section 3.3.3 Cache Level ID Register
 *   - Section 3.3.4 Cache Size ID Register
 *   - Section 3.3.5 Cache Size Selection Register
 *
 * @reference Arm Cortex-M7 Devices Generic User Guide
 *   - Section 4.8 Cache maintenance operations
 *   - Table 4-64 Cache maintenance operations
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/cm7/cm7_cache.h"

/* ============================================================================
 * Cache Information Functions
 * 缓存信息函数
 * ============================================================================ */

/**
 * @brief Get cache level ID
 * 获取缓存级别 ID
 */
uint32_t cm7_cache_get_clidr(void)
{
    return CM7_CLIDR;
}

/**
 * @brief Get cache type register
 * 获取缓存类型寄存器
 */
uint32_t cm7_cache_get_ctr(void)
{
    return CM7_CTR;
}

/**
 * @brief Get cache size ID
 * 获取缓存大小 ID
 *
 * @param level Cache level (0 = L1)
 * @param ind 0 = Data cache, 1 = Instruction cache
 * @return CCSIDR value
 */
uint32_t cm7_cache_get_ccsidr(uint32_t level, uint32_t ind)
{
    /* Select cache level and type */
    CM7_CSSELR = ((level << CM7_CSSELR_LEVEL_Pos) & CM7_CSSELR_LEVEL_Msk) |
                 ((ind << CM7_CSSELR_IND_Pos) & CM7_CSSELR_IND_Msk);
    __DSB();

    return CM7_CCSIDR;
}

/**
 * @brief Check if instruction cache is present
 * 检查是否存在指令缓存
 */
uint32_t cm7_cache_icache_present(void)
{
    uint32_t clidr = CM7_CLIDR;
    uint32_t ctype1 = (clidr & CM7_CLIDR_CTYPE1_Msk) >> CM7_CLIDR_CTYPE1_Pos;

    return (ctype1 == CM7_CLIDR_CTYPE1_ICACHE) ||
           (ctype1 == CM7_CLIDR_CTYPE1_IDCACHE);
}

/**
 * @brief Check if data cache is present
 * 检查是否存在数据缓存
 */
uint32_t cm7_cache_dcache_present(void)
{
    uint32_t clidr = CM7_CLIDR;
    uint32_t ctype1 = (clidr & CM7_CLIDR_CTYPE1_Msk) >> CM7_CLIDR_CTYPE1_Pos;

    return (ctype1 == CM7_CLIDR_CTYPE1_DCACHE) ||
           (ctype1 == CM7_CLIDR_CTYPE1_IDCACHE);
}

/* ============================================================================
 * Instruction Cache Operations
 * 指令缓存操作
 * ============================================================================ */

#if (__ICACHE_PRESENT == 1)
/**
 * @brief Invalidate instruction cache by address to PoU
 * 按地址使指令缓存失效到 PoU
 *
 * @param addr Address to invalidate (must be 32-byte aligned)
 */
void cm7_icache_invalidate_by_addr(uint32_t addr)
{
    CM7_ICIMVAU = addr;
    __DSB();
    __ISB();
}

/**
 * @brief Invalidate instruction cache by address range
 * 按地址范围使指令缓存失效
 *
 * @param addr Start address
 * @param size Size in bytes
 */
void cm7_icache_invalidate_range(uint32_t addr, uint32_t size)
{
    uint32_t line_size = __CM7_ICACHE_LINE_SIZE;
    uint32_t end_addr = addr + size;

    /* Align address to cache line boundary */
    addr &= ~(line_size - 1);

    while (addr < end_addr) {
        CM7_ICIMVAU = addr;
        addr += line_size;
    }
    __DSB();
    __ISB();
}
#endif /* __ICACHE_PRESENT */

/* ============================================================================
 * Data Cache Operations
 * 数据缓存操作
 * ============================================================================ */

#if (__DCACHE_PRESENT == 1)
/**
 * @brief Clean data cache by address to PoU
 * 按地址清理数据缓存到 PoU
 *
 * @param addr Address to clean (must be 32-byte aligned)
 */
void cm7_dcache_clean_by_addr_pou(uint32_t addr)
{
    CM7_DCCMVAU = addr;
    __DSB();
}

/**
 * @brief Invalidate data cache by address to PoC
 * 按地址使数据缓存失效到 PoC
 *
 * @param addr Address to invalidate (must be 32-byte aligned)
 */
void cm7_dcache_invalidate_by_addr_poc(uint32_t addr)
{
    CM7_DCIMVAC = addr;
    __DSB();
}

/**
 * @brief Clean data cache by address to PoC
 * 按地址清理数据缓存到 PoC
 *
 * @param addr Address to clean (must be 32-byte aligned)
 */
void cm7_dcache_clean_by_addr_poc(uint32_t addr)
{
    CM7_DCCMVAC = addr;
    __DSB();
}

/**
 * @brief Clean and invalidate data cache by address to PoC
 * 按地址清理并使数据缓存失效到 PoC
 *
 * @param addr Address to clean and invalidate (must be 32-byte aligned)
 */
void cm7_dcache_clean_invalidate_by_addr_poc(uint32_t addr)
{
    CM7_DCCIMVAC = addr;
    __DSB();
}
#endif /* __DCACHE_PRESENT */
