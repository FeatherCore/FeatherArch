/*
 * arm_v7m_cache.c
 * ARMv7-M Cache Maintenance Operations Implementation
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
 *
 * @note Cache support is optional in ARMv7-M architecture.
 *       Not all ARMv7-M implementations include cache.
 */

#include "arm_v7m_cache.h"

/*============================================================================*
 * CCR Register Access
 *============================================================================*/

/**
 * @brief Get CCR register value
 * @return CCR value
 */
static uint32_t arm_v7m_get_ccr(void)
{
    return *(volatile uint32_t *)ARM_V7M_CCR_BASE;
}

/**
 * @brief Set CCR register value
 * @param value CCR value to write
 */
static void arm_v7m_set_ccr(uint32_t value)
{
    *(volatile uint32_t *)ARM_V7M_CCR_BASE = value;
    __asm__ volatile ("dsb" ::: "memory");
}

/*============================================================================*
 * I-Cache Operations
 *============================================================================*/

/**
 * @brief Enable Instruction Cache
 *
 * According to ARMv7-M Architecture Reference Manual, Section B2.3.1:
 * - The I-Cache is enabled by setting the IC bit in the CCR register
 * - Must invalidate the I-Cache before enabling
 */
void arm_v7m_icache_enable(void)
{
    uint32_t ccr;

    /* Check if already enabled */
    if (arm_v7m_icache_is_enabled()) {
        return;
    }

    /* Invalidate I-Cache before enabling */
    arm_v7m_icache_invalidate_all();

    /* Enable I-Cache by setting IC bit in CCR */
    ccr = arm_v7m_get_ccr();
    ccr |= ARM_V7M_CCR_IC_Msk;
    arm_v7m_set_ccr(ccr);
}

/**
 * @brief Disable Instruction Cache
 */
void arm_v7m_icache_disable(void)
{
    uint32_t ccr;

    /* Disable I-Cache by clearing IC bit in CCR */
    ccr = arm_v7m_get_ccr();
    ccr &= ~ARM_V7M_CCR_IC_Msk;
    arm_v7m_set_ccr(ccr);

    /* Memory barrier to ensure disable takes effect */
    __asm__ volatile ("dsb" ::: "memory");
    __asm__ volatile ("isb" ::: "memory");
}

/**
 * @brief Invalidate all Instruction Cache entries
 */
void arm_v7m_icache_invalidate_all(void)
{
    arm_v7m_iciallu();
}

/**
 * @brief Invalidate Instruction Cache line by address
 * @param addr Address to invalidate
 */
void arm_v7m_icache_invalidate_line(uint32_t addr)
{
    arm_v7m_icimvau(addr);
}

/**
 * @brief Check if Instruction Cache is enabled
 * @return 1 if enabled, 0 if disabled
 */
uint32_t arm_v7m_icache_is_enabled(void)
{
    return (arm_v7m_get_ccr() & ARM_V7M_CCR_IC_Msk) ? 1U : 0U;
}

/*============================================================================*
 * D-Cache Operations
 *============================================================================*/

/**
 * @brief Enable Data Cache
 *
 * According to ARMv7-M Architecture Reference Manual, Section B2.3.1:
 * - The D-Cache is enabled by setting the DC bit in the CCR register
 * - Must invalidate the D-Cache before enabling
 */
void arm_v7m_dcache_enable(void)
{
    uint32_t ccr;

    /* Check if already enabled */
    if (arm_v7m_dcache_is_enabled()) {
        return;
    }

    /* Invalidate D-Cache before enabling */
    arm_v7m_dcache_invalidate_all();

    /* Enable D-Cache by setting DC bit in CCR */
    ccr = arm_v7m_get_ccr();
    ccr |= ARM_V7M_CCR_DC_Msk;
    arm_v7m_set_ccr(ccr);
}

/**
 * @brief Disable Data Cache
 */
void arm_v7m_dcache_disable(void)
{
    uint32_t ccr;

    /* Clean and invalidate D-Cache before disabling */
    arm_v7m_dcache_clean_invalidate_all();

    /* Disable D-Cache by clearing DC bit in CCR */
    ccr = arm_v7m_get_ccr();
    ccr &= ~ARM_V7M_CCR_DC_Msk;
    arm_v7m_set_ccr(ccr);

    /* Memory barrier to ensure disable takes effect */
    __asm__ volatile ("dsb" ::: "memory");
}

/**
 * @brief Invalidate all Data Cache entries
 */
void arm_v7m_dcache_invalidate_all(void)
{
    uint32_t ccsidr;
    uint32_t sets;
    uint32_t ways;
    uint32_t set_shift;
    uint32_t way_shift;
    uint32_t set;
    uint32_t way;
    uint32_t set_way;

    /* Get cache info for D-Cache (level 0, data cache) */
    arm_v7m_cache_set_csselr(0U);
    ccsidr = arm_v7m_cache_get_ccsidr();

    /* Extract cache parameters */
    sets = ((ccsidr & ARM_V7M_CCSIDR_NUMSETS_Msk) >> ARM_V7M_CCSIDR_NUMSETS_Pos) + 1U;
    ways = ((ccsidr & ARM_V7M_CCSIDR_ASSOCIATIVITY_Msk) >> ARM_V7M_CCSIDR_ASSOCIATIVITY_Pos) + 1U;

    /* Calculate shifts for set/way encoding */
    set_shift = 4U;
    way_shift = 32U - __builtin_clz(ways - 1U);

    /* Invalidate all sets and ways */
    for (set = 0U; set < sets; set++) {
        for (way = 0U; way < ways; way++) {
            set_way = (way << way_shift) | (set << set_shift);
            arm_v7m_dcisw(set_way);
        }
    }
}

/**
 * @brief Clean all Data Cache entries
 */
void arm_v7m_dcache_clean_all(void)
{
    uint32_t ccsidr;
    uint32_t sets;
    uint32_t ways;
    uint32_t set_shift;
    uint32_t way_shift;
    uint32_t set;
    uint32_t way;
    uint32_t set_way;

    /* Get cache info for D-Cache (level 0, data cache) */
    arm_v7m_cache_set_csselr(0U);
    ccsidr = arm_v7m_cache_get_ccsidr();

    /* Extract cache parameters */
    sets = ((ccsidr & ARM_V7M_CCSIDR_NUMSETS_Msk) >> ARM_V7M_CCSIDR_NUMSETS_Pos) + 1U;
    ways = ((ccsidr & ARM_V7M_CCSIDR_ASSOCIATIVITY_Msk) >> ARM_V7M_CCSIDR_ASSOCIATIVITY_Pos) + 1U;

    /* Calculate shifts for set/way encoding */
    set_shift = 4U;
    way_shift = 32U - __builtin_clz(ways - 1U);

    /* Clean all sets and ways */
    for (set = 0U; set < sets; set++) {
        for (way = 0U; way < ways; way++) {
            set_way = (way << way_shift) | (set << set_shift);
            arm_v7m_dccsw(set_way);
        }
    }
}

/**
 * @brief Clean and Invalidate all Data Cache entries
 */
void arm_v7m_dcache_clean_invalidate_all(void)
{
    uint32_t ccsidr;
    uint32_t sets;
    uint32_t ways;
    uint32_t set_shift;
    uint32_t way_shift;
    uint32_t set;
    uint32_t way;
    uint32_t set_way;

    /* Get cache info for D-Cache (level 0, data cache) */
    arm_v7m_cache_set_csselr(0U);
    ccsidr = arm_v7m_cache_get_ccsidr();

    /* Extract cache parameters */
    sets = ((ccsidr & ARM_V7M_CCSIDR_NUMSETS_Msk) >> ARM_V7M_CCSIDR_NUMSETS_Pos) + 1U;
    ways = ((ccsidr & ARM_V7M_CCSIDR_ASSOCIATIVITY_Msk) >> ARM_V7M_CCSIDR_ASSOCIATIVITY_Pos) + 1U;

    /* Calculate shifts for set/way encoding */
    set_shift = 4U;
    way_shift = 32U - __builtin_clz(ways - 1U);

    /* Clean and invalidate all sets and ways */
    for (set = 0U; set < sets; set++) {
        for (way = 0U; way < ways; way++) {
            set_way = (way << way_shift) | (set << set_shift);
            arm_v7m_dccisw(set_way);
        }
    }
}

/**
 * @brief Invalidate Data Cache line by address
 * @param addr Address to invalidate
 */
void arm_v7m_dcache_invalidate_line(uint32_t addr)
{
    arm_v7m_dcimvac(addr);
}

/**
 * @brief Clean Data Cache line by address
 * @param addr Address to clean
 */
void arm_v7m_dcache_clean_line(uint32_t addr)
{
    arm_v7m_dccmvac(addr);
}

/**
 * @brief Clean and Invalidate Data Cache line by address
 * @param addr Address to clean and invalidate
 */
void arm_v7m_dcache_clean_invalidate_line(uint32_t addr)
{
    arm_v7m_dccimvac(addr);
}

/**
 * @brief Check if Data Cache is enabled
 * @return 1 if enabled, 0 if disabled
 */
uint32_t arm_v7m_dcache_is_enabled(void)
{
    return (arm_v7m_get_ccr() & ARM_V7M_CCR_DC_Msk) ? 1U : 0U;
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
uint32_t arm_v7m_cache_get_info(uint32_t level, uint32_t ind, arm_v7m_cache_info_t *info)
{
    uint32_t ccsidr;
    uint32_t csselr;
    uint32_t line_size;

    if (info == NULL) {
        return 1U;
    }

    /* Select cache to query */
    csselr = (level << ARM_V7M_CSSELR_LEVEL_Pos) |
             (ind << ARM_V7M_CSSELR_IND_Pos);
    arm_v7m_cache_set_csselr(csselr);

    /* Read CCSIDR */
    ccsidr = arm_v7m_cache_get_ccsidr();

    /* Check if cache exists */
    if ((ccsidr & (ARM_V7M_CCSIDR_NUMSETS_Msk | ARM_V7M_CCSIDR_ASSOCIATIVITY_Msk)) == 0U) {
        return 1U;
    }

    /* Extract cache parameters */
    line_size = (1U << (((ccsidr & ARM_V7M_CCSIDR_LINESIZE_Msk) >> ARM_V7M_CCSIDR_LINESIZE_Pos) + 2U)) * 4U;

    info->line_size = line_size;
    info->num_sets = ((ccsidr & ARM_V7M_CCSIDR_NUMSETS_Msk) >> ARM_V7M_CCSIDR_NUMSETS_Pos) + 1U;
    info->associativity = ((ccsidr & ARM_V7M_CCSIDR_ASSOCIATIVITY_Msk) >> ARM_V7M_CCSIDR_ASSOCIATIVITY_Pos) + 1U;
    info->cache_size = info->line_size * info->num_sets * info->associativity;
    info->write_alloc = (ccsidr & ARM_V7M_CCSIDR_WA_Msk) ? 1U : 0U;
    info->read_alloc = (ccsidr & ARM_V7M_CCSIDR_RA_Msk) ? 1U : 0U;
    info->write_back = (ccsidr & ARM_V7M_CCSIDR_WB_Msk) ? 1U : 0U;
    info->write_through = (ccsidr & ARM_V7M_CCSIDR_WT_Msk) ? 1U : 0U;

    return 0U;
}

/**
 * @brief Get cache line size
 * @param level Cache level (0 for L1)
 * @param ind Cache type (0=data, 1=instruction)
 * @return Cache line size in bytes, or 0 if cache not present
 */
uint32_t arm_v7m_cache_get_line_size(uint32_t level, uint32_t ind)
{
    uint32_t ccsidr;
    uint32_t csselr;
    uint32_t line_size;

    /* Select cache to query */
    csselr = (level << ARM_V7M_CSSELR_LEVEL_Pos) |
             (ind << ARM_V7M_CSSELR_IND_Pos);
    arm_v7m_cache_set_csselr(csselr);

    /* Read CCSIDR */
    ccsidr = arm_v7m_cache_get_ccsidr();

    /* Check if cache exists */
    if ((ccsidr & (ARM_V7M_CCSIDR_NUMSETS_Msk | ARM_V7M_CCSIDR_ASSOCIATIVITY_Msk)) == 0U) {
        return 0U;
    }

    /* Line size = 2^(CCSIDR.Linesize + 2) * 4 bytes */
    line_size = (1U << (((ccsidr & ARM_V7M_CCSIDR_LINESIZE_Msk) >> ARM_V7M_CCSIDR_LINESIZE_Pos) + 2U)) * 4U;

    return line_size;
}

/**
 * @brief Get I-Cache information
 * @param info Pointer to cache info structure to fill
 * @return 0 on success, 1 if I-Cache not present
 */
uint32_t arm_v7m_icache_get_info(arm_v7m_cache_info_t *info)
{
    return arm_v7m_cache_get_info(0U, ARM_V7M_CSSELR_IND_INSTR, info);
}

/**
 * @brief Get D-Cache information
 * @param info Pointer to cache info structure to fill
 * @return 0 on success, 1 if D-Cache not present
 */
uint32_t arm_v7m_dcache_get_info(arm_v7m_cache_info_t *info)
{
    return arm_v7m_cache_get_info(0U, ARM_V7M_CSSELR_IND_DATA, info);
}

/*============================================================================*
 * Cache Maintenance Range Functions
 *============================================================================*/

/**
 * @brief Invalidate D-Cache range
 * @param start Start address (inclusive)
 * @param end End address (exclusive)
 */
void arm_v7m_dcache_invalidate_range(uint32_t start, uint32_t end)
{
    uint32_t line_size;
    uint32_t addr;

    /* Get D-Cache line size */
    line_size = arm_v7m_cache_get_line_size(0U, ARM_V7M_CSSELR_IND_DATA);
    if (line_size == 0U) {
        return;
    }

    /* Align start address to cache line boundary */
    addr = start & ~(line_size - 1U);

    /* Invalidate each cache line in the range */
    while (addr < end) {
        arm_v7m_dcimvac(addr);
        addr += line_size;
    }
}

/**
 * @brief Clean D-Cache range
 * @param start Start address (inclusive)
 * @param end End address (exclusive)
 */
void arm_v7m_dcache_clean_range(uint32_t start, uint32_t end)
{
    uint32_t line_size;
    uint32_t addr;

    /* Get D-Cache line size */
    line_size = arm_v7m_cache_get_line_size(0U, ARM_V7M_CSSELR_IND_DATA);
    if (line_size == 0U) {
        return;
    }

    /* Align start address to cache line boundary */
    addr = start & ~(line_size - 1U);

    /* Clean each cache line in the range */
    while (addr < end) {
        arm_v7m_dccmvac(addr);
        addr += line_size;
    }
}

/**
 * @brief Clean and Invalidate D-Cache range
 * @param start Start address (inclusive)
 * @param end End address (exclusive)
 */
void arm_v7m_dcache_clean_invalidate_range(uint32_t start, uint32_t end)
{
    uint32_t line_size;
    uint32_t addr;

    /* Get D-Cache line size */
    line_size = arm_v7m_cache_get_line_size(0U, ARM_V7M_CSSELR_IND_DATA);
    if (line_size == 0U) {
        return;
    }

    /* Align start address to cache line boundary */
    addr = start & ~(line_size - 1U);

    /* Clean and invalidate each cache line in the range */
    while (addr < end) {
        arm_v7m_dccimvac(addr);
        addr += line_size;
    }
}
