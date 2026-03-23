/*
 * ARM Architecture - ARMv7-M Cache Operations
 *
 * ============================================================================
 * File: armv7-m_cache.c
 * Description: ARMv7-M cache maintenance operation implementations
 * 描述: ARMv7-M 缓存维护操作实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B3.2 - Cache maintenance operations
 *   - Table B3-32 Cache maintenance operations (page B3-620)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_cache.h"
#include "armv7-m/armv7-m_nvic.h"

#if (__ICACHE_PRESENT == 1) || (__DCACHE_PRESENT == 1)

/*
 * ============================================================================
 * Instruction Cache Control
 * 指令缓存控制
 * Reference: Chapter B3.2 - Cache maintenance operations
 * ============================================================================
 */

#if (__ICACHE_PRESENT == 1)
/**
 * @brief Enable Instruction Cache
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-604 (CCR.IC bit)
 */
void icache_enable(void)
{
    SCB_CCR |= SCB_CCR_IC_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Disable Instruction Cache
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-604 (CCR.IC bit)
 */
void icache_disable(void)
{
    SCB_CCR &= ~SCB_CCR_IC_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Invalidate entire Instruction Cache
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620 (ICIALLU)
 */
void icache_invalidate_all(void)
{
    __IALLU();
}

/**
 * @brief Invalidate Instruction Cache by address
 * @param addr Address to invalidate
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620 (ICIMVAU)
 */
void icache_invalidate_by_addr(uint32_t addr)
{
    __IINVA(addr);
}

/**
 * @brief Check if Instruction Cache is enabled
 * @return 1 if enabled, 0 if disabled
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-604 (CCR.IC bit)
 */
uint32_t icache_is_enabled(void)
{
    return (SCB_CCR & SCB_CCR_IC_Msk) ? 1U : 0U;
}
#endif

/*
 * ============================================================================
 * Data Cache Control
 * 数据缓存控制
 * Reference: Chapter B3.2 - Cache maintenance operations
 * ============================================================================
 */

#if (__DCACHE_PRESENT == 1)
/**
 * @brief Enable Data Cache
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-604 (CCR.DC bit)
 */
void dcache_enable(void)
{
    SCB_CCR |= SCB_CCR_DC_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Disable Data Cache
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-604 (CCR.DC bit)
 */
void dcache_disable(void)
{
    dcache_clean_invalidate_all();
    SCB_CCR &= ~SCB_CCR_DC_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Clean entire Data Cache
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620 (DCCSW)
 */
void dcache_clean_all(void)
{
    uint32_t ccsidr;
    uint32_t sets;
    uint32_t ways;
    uint32_t set;
    uint32_t way;
    
    /* Select data cache */
    SCB_CSSELR = 0;
    __DSB();
    
    ccsidr = SCB_CCSIDR;
    
    sets = ((ccsidr >> 13) & 0x7FFF) + 1;
    ways = ((ccsidr >> 3) & 0x3FF) + 1;
    
    for (way = 0; way < ways; way++) {
        for (set = 0; set < sets; set++) {
            uint32_t sw = ((way & 0x3FF) << 30) | ((set & 0x7FFF) << 5);
            __DCCSW(sw);
        }
    }
    
    __DSB();
    __ISB();
}

/**
 * @brief Invalidate entire Data Cache
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620 (DCISW)
 */
void dcache_invalidate_all(void)
{
    uint32_t ccsidr;
    uint32_t sets;
    uint32_t ways;
    uint32_t set;
    uint32_t way;
    
    /* Select data cache */
    SCB_CSSELR = 0;
    __DSB();
    
    ccsidr = SCB_CCSIDR;
    
    sets = ((ccsidr >> 13) & 0x7FFF) + 1;
    ways = ((ccsidr >> 3) & 0x3FF) + 1;
    
    for (way = 0; way < ways; way++) {
        for (set = 0; set < sets; set++) {
            uint32_t sw = ((way & 0x3FF) << 30) | ((set & 0x7FFF) << 5);
            __DCISW(sw);
        }
    }
    
    __DSB();
    __ISB();
}

/**
 * @brief Clean and invalidate entire Data Cache
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620 (DCCISW)
 */
void dcache_clean_invalidate_all(void)
{
    uint32_t ccsidr;
    uint32_t sets;
    uint32_t ways;
    uint32_t set;
    uint32_t way;
    
    /* Select data cache */
    SCB_CSSELR = 0;
    __DSB();
    
    ccsidr = SCB_CCSIDR;
    
    sets = ((ccsidr >> 13) & 0x7FFF) + 1;
    ways = ((ccsidr >> 3) & 0x3FF) + 1;
    
    for (way = 0; way < ways; way++) {
        for (set = 0; set < sets; set++) {
            uint32_t sw = ((way & 0x3FF) << 30) | ((set & 0x7FFF) << 5);
            __DCCISW(sw);
        }
    }
    
    __DSB();
    __ISB();
}

/*
 * ============================================================================
 * Data Cache Range Operations
 * 数据缓存范围操作
 * Reference: Chapter B3.2 - Cache maintenance operations
 * ============================================================================
 */

/**
 * @brief Clean a range of Data Cache
 * @param addr Start address
 * @param size Size in bytes
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620 (DCCMVAC)
 */
void dcache_clean_range(uint32_t addr, uint32_t size)
{
    uint32_t end_addr = addr + size;
    uint32_t ccsidr;
    uint32_t line_size;
    
    /* Select data cache */
    SCB_CSSELR = 0;
    __DSB();
    
    ccsidr = SCB_CCSIDR;
    line_size = 4 << ((ccsidr & 0x7) + 2);
    
    addr &= ~(line_size - 1);
    
    while (addr < end_addr) {
        __DCCMVAC(addr);
        addr += line_size;
    }
    
    __DSB();
    __ISB();
}

/**
 * @brief Invalidate a range of Data Cache
 * @param addr Start address
 * @param size Size in bytes
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620 (DCIMVAC)
 */
void dcache_invalidate_range(uint32_t addr, uint32_t size)
{
    uint32_t end_addr = addr + size;
    uint32_t ccsidr;
    uint32_t line_size;
    
    /* Select data cache */
    SCB_CSSELR = 0;
    __DSB();
    
    ccsidr = SCB_CCSIDR;
    line_size = 4 << ((ccsidr & 0x7) + 2);
    
    addr &= ~(line_size - 1);
    
    while (addr < end_addr) {
        __DCIMVAC(addr);
        addr += line_size;
    }
    
    __DSB();
    __ISB();
}

/**
 * @brief Clean and invalidate a range of Data Cache
 * @param addr Start address
 * @param size Size in bytes
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620 (DCCIMVAC)
 */
void dcache_clean_invalidate_range(uint32_t addr, uint32_t size)
{
    uint32_t end_addr = addr + size;
    uint32_t ccsidr;
    uint32_t line_size;
    
    /* Select data cache */
    SCB_CSSELR = 0;
    __DSB();
    
    ccsidr = SCB_CCSIDR;
    line_size = 4 << ((ccsidr & 0x7) + 2);
    
    addr &= ~(line_size - 1);
    
    while (addr < end_addr) {
        __DCCIMVAC(addr);
        addr += line_size;
    }
    
    __DSB();
    __ISB();
}

/**
 * @brief Clean Data Cache by address to Point of Unification
 * @param addr Address to clean
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620 (DCCMVAU)
 */
void dcache_clean_by_addr_pou(uint32_t addr)
{
    __DCCMVAU(addr);
}

/**
 * @brief Check if Data Cache is enabled
 * @return 1 if enabled, 0 if disabled
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-604 (CCR.DC bit)
 */
uint32_t dcache_is_enabled(void)
{
    return (SCB_CCR & SCB_CCR_DC_Msk) ? 1U : 0U;
}
#endif

/*
 * ============================================================================
 * Branch Predictor Control
 * 分支预测器控制
 * Reference: Chapter B3.2 - Cache maintenance operations
 * ============================================================================
 */

/**
 * @brief Invalidate all branch predictors
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620 (BPIALL)
 */
void bpiall_invalidate(void)
{
    __BPIALL();
}

#endif /* (__ICACHE_PRESENT == 1) || (__DCACHE_PRESENT == 1) */
