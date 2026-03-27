/*
 * arm_v7m_cache.h
 * ARMv7-M Cache Maintenance Operations Definitions
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

#ifndef ARM_V7M_CACHE_H
#define ARM_V7M_CACHE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Compiler Abstraction - Inline Definition
 *============================================================================*/

#if defined(__clang__)
    #define ARM_V7M_CACHE_INLINE static inline __attribute__((always_inline))
#else
    #error "This library requires Clang/LLVM compiler."
#endif

/*============================================================================*
 * Cache Register Base Addresses
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2
 *============================================================================*/

#define ARM_V7M_CACHE_MAINT_BASE        0xE000EF50UL
#define ARM_V7M_CACHE_ID_BASE           0xE000ED78UL
#define ARM_V7M_CCR_BASE                0xE000ED14UL

/*============================================================================*
 * Cache Maintenance Register Offsets
 * Reference: ARMv7-M Architecture Reference Manual, Table B3-15
 *============================================================================*/

#define ARM_V7M_ICIALLU_OFFSET          0x00
#define ARM_V7M_ICIMVAU_OFFSET          0x08
#define ARM_V7M_DCIMVAC_OFFSET          0x0C
#define ARM_V7M_DCISW_OFFSET            0x10
#define ARM_V7M_DCCMVAU_OFFSET          0x14
#define ARM_V7M_DCCMVAC_OFFSET          0x18
#define ARM_V7M_DCCSW_OFFSET            0x1C
#define ARM_V7M_DCCIMVAC_OFFSET         0x20
#define ARM_V7M_DCCISW_OFFSET           0x24

/*============================================================================*
 * Cache ID Register Offsets
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2
 *============================================================================*/

#define ARM_V7M_CLIDR_OFFSET            0x00
#define ARM_V7M_CTR_OFFSET              0x04
#define ARM_V7M_CCSIDR_OFFSET           0x08
#define ARM_V7M_CSSELR_OFFSET           0x0C

/*============================================================================*
 * CCR Register Bit Definitions (Cache Enable Bits)
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.20
 *============================================================================*/

#define ARM_V7M_CCR_IC_Pos              17U
#define ARM_V7M_CCR_IC_Msk              (1UL << ARM_V7M_CCR_IC_Pos)

#define ARM_V7M_CCR_DC_Pos              16U
#define ARM_V7M_CCR_DC_Msk              (1UL << ARM_V7M_CCR_DC_Pos)

/*============================================================================*
 * CCSIDR Register Bit Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.17
 *============================================================================*/

#define ARM_V7M_CCSIDR_LINESIZE_Pos         0U
#define ARM_V7M_CCSIDR_LINESIZE_Msk         (0x7UL << ARM_V7M_CCSIDR_LINESIZE_Pos)

#define ARM_V7M_CCSIDR_ASSOCIATIVITY_Pos    3U
#define ARM_V7M_CCSIDR_ASSOCIATIVITY_Msk    (0x3FFUL << ARM_V7M_CCSIDR_ASSOCIATIVITY_Pos)

#define ARM_V7M_CCSIDR_NUMSETS_Pos          13U
#define ARM_V7M_CCSIDR_NUMSETS_Msk          (0x7FFFUL << ARM_V7M_CCSIDR_NUMSETS_Pos)

#define ARM_V7M_CCSIDR_WA_Pos               28U
#define ARM_V7M_CCSIDR_WA_Msk               (1UL << ARM_V7M_CCSIDR_WA_Pos)

#define ARM_V7M_CCSIDR_RA_Pos               29U
#define ARM_V7M_CCSIDR_RA_Msk               (1UL << ARM_V7M_CCSIDR_RA_Pos)

#define ARM_V7M_CCSIDR_WB_Pos               30U
#define ARM_V7M_CCSIDR_WB_Msk               (1UL << ARM_V7M_CCSIDR_WB_Pos)

#define ARM_V7M_CCSIDR_WT_Pos               31U
#define ARM_V7M_CCSIDR_WT_Msk               (1UL << ARM_V7M_CCSIDR_WT_Pos)

/*============================================================================*
 * CSSELR Register Bit Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.16
 *============================================================================*/

#define ARM_V7M_CSSELR_IND_Pos          0U
#define ARM_V7M_CSSELR_IND_Msk          (1UL << ARM_V7M_CSSELR_IND_Pos)

#define ARM_V7M_CSSELR_LEVEL_Pos        1U
#define ARM_V7M_CSSELR_LEVEL_Msk        (0x7UL << ARM_V7M_CSSELR_LEVEL_Pos)

/* CSSELR IND values */
#define ARM_V7M_CSSELR_IND_DATA         0U
#define ARM_V7M_CSSELR_IND_INSTR        1U

/*============================================================================*
 * CLIDR Register Bit Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.18
 *============================================================================*/

#define ARM_V7M_CLIDR_CTYPE1_Pos        0U
#define ARM_V7M_CLIDR_CTYPE1_Msk        (0x7UL << ARM_V7M_CLIDR_CTYPE1_Pos)

#define ARM_V7M_CLIDR_CTYPE2_Pos        3U
#define ARM_V7M_CLIDR_CTYPE2_Msk        (0x7UL << ARM_V7M_CLIDR_CTYPE2_Pos)

#define ARM_V7M_CLIDR_CTYPE3_Pos        6U
#define ARM_V7M_CLIDR_CTYPE3_Msk        (0x7UL << ARM_V7M_CLIDR_CTYPE3_Pos)

#define ARM_V7M_CLIDR_CTYPE4_Pos        9U
#define ARM_V7M_CLIDR_CTYPE4_Msk        (0x7UL << ARM_V7M_CLIDR_CTYPE4_Pos)

#define ARM_V7M_CLIDR_CTYPE5_Pos        12U
#define ARM_V7M_CLIDR_CTYPE5_Msk        (0x7UL << ARM_V7M_CLIDR_CTYPE5_Pos)

#define ARM_V7M_CLIDR_CTYPE6_Pos        15U
#define ARM_V7M_CLIDR_CTYPE6_Msk        (0x7UL << ARM_V7M_CLIDR_CTYPE6_Pos)

#define ARM_V7M_CLIDR_CTYPE7_Pos        18U
#define ARM_V7M_CLIDR_CTYPE7_Msk        (0x7UL << ARM_V7M_CLIDR_CTYPE7_Pos)

#define ARM_V7M_CLIDR_LOUIS_Pos         21U
#define ARM_V7M_CLIDR_LOUIS_Msk         (0x7UL << ARM_V7M_CLIDR_LOUIS_Pos)

#define ARM_V7M_CLIDR_LOC_Pos           24U
#define ARM_V7M_CLIDR_LOC_Msk           (0x7UL << ARM_V7M_CLIDR_LOC_Pos)

#define ARM_V7M_CLIDR_LOUU_Pos          27U
#define ARM_V7M_CLIDR_LOUU_Msk          (0x7UL << ARM_V7M_CLIDR_LOUU_Pos)

#define ARM_V7M_CLIDR_ICB_Pos           30U
#define ARM_V7M_CLIDR_ICB_Msk           (0x3UL << ARM_V7M_CLIDR_ICB_Pos)

/* CLIDR CTYPE values */
#define ARM_V7M_CLIDR_CTYPE_NONE        0U
#define ARM_V7M_CLIDR_CTYPE_ICACHE      1U
#define ARM_V7M_CLIDR_CTYPE_DCACHE      2U
#define ARM_V7M_CLIDR_CTYPE_UNIFIED     3U
#define ARM_V7M_CLIDR_CTYPE_HARVARD     4U

/*============================================================================*
 * CTR Register Bit Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.19
 *============================================================================*/

#define ARM_V7M_CTR_IMINLINE_Pos        0U
#define ARM_V7M_CTR_IMINLINE_Msk        (0xFUL << ARM_V7M_CTR_IMINLINE_Pos)

#define ARM_V7M_CTR_L1IP_Pos            14U
#define ARM_V7M_CTR_L1IP_Msk            (0x3UL << ARM_V7M_CTR_L1IP_Pos)

#define ARM_V7M_CTR_DMINLINE_Pos        16U
#define ARM_V7M_CTR_DMINLINE_Msk        (0xFUL << ARM_V7M_CTR_DMINLINE_Pos)

#define ARM_V7M_CTR_ERG_Pos             20U
#define ARM_V7M_CTR_ERG_Msk             (0xFUL << ARM_V7M_CTR_ERG_Pos)

#define ARM_V7M_CTR_CWG_Pos             24U
#define ARM_V7M_CTR_CWG_Msk             (0xFUL << ARM_V7M_CTR_CWG_Pos)

#define ARM_V7M_CTR_FORMAT_Pos          29U
#define ARM_V7M_CTR_FORMAT_Msk          (0x7UL << ARM_V7M_CTR_FORMAT_Pos)

/*============================================================================*
 * Cache Info Structure
 *============================================================================*/

typedef struct {
    uint32_t line_size;         /* Cache line size in bytes */
    uint32_t num_sets;          /* Number of sets */
    uint32_t associativity;     /* Associativity (ways) */
    uint32_t cache_size;        /* Total cache size in bytes */
    uint32_t write_alloc;       /* Write-allocate supported */
    uint32_t read_alloc;        /* Read-allocate supported */
    uint32_t write_back;        /* Write-back supported */
    uint32_t write_through;     /* Write-through supported */
} arm_v7m_cache_info_t;

/*============================================================================*
 * Inline Functions - Cache ID Register Access
 *============================================================================*/

/**
 * @brief Get Cache Level ID Register (CLIDR)
 * @return CLIDR value
 */
ARM_V7M_CACHE_INLINE uint32_t arm_v7m_cache_get_clidr(void)
{
    return *(volatile const uint32_t *)(ARM_V7M_CACHE_ID_BASE + ARM_V7M_CLIDR_OFFSET);
}

/**
 * @brief Get Cache Type Register (CTR)
 * @return CTR value
 */
ARM_V7M_CACHE_INLINE uint32_t arm_v7m_cache_get_ctr(void)
{
    return *(volatile const uint32_t *)(ARM_V7M_CACHE_ID_BASE + ARM_V7M_CTR_OFFSET);
}

/**
 * @brief Get Cache Size ID Register (CCSIDR)
 * @return CCSIDR value
 */
ARM_V7M_CACHE_INLINE uint32_t arm_v7m_cache_get_ccsidr(void)
{
    return *(volatile const uint32_t *)(ARM_V7M_CACHE_ID_BASE + ARM_V7M_CCSIDR_OFFSET);
}

/**
 * @brief Get Cache Size Selection Register (CSSELR)
 * @return CSSELR value
 */
ARM_V7M_CACHE_INLINE uint32_t arm_v7m_cache_get_csselr(void)
{
    return *(volatile uint32_t *)(ARM_V7M_CACHE_ID_BASE + ARM_V7M_CSSELR_OFFSET);
}

/**
 * @brief Set Cache Size Selection Register (CSSELR)
 * @param value CSSELR value
 */
ARM_V7M_CACHE_INLINE void arm_v7m_cache_set_csselr(uint32_t value)
{
    *(volatile uint32_t *)(ARM_V7M_CACHE_ID_BASE + ARM_V7M_CSSELR_OFFSET) = value;
    __asm__ volatile ("dsb" ::: "memory");
}

/*============================================================================*
 * Inline Functions - Cache Maintenance Operations (Low-level)
 * Reference: ARMv7-M Architecture Reference Manual, Section B2.3.3
 *============================================================================*/

/**
 * @brief Instruction Cache Invalidate All to PoU (ICIALLU)
 * @note Invalidates all instruction cache entries
 */
ARM_V7M_CACHE_INLINE void arm_v7m_iciallu(void)
{
    *(volatile uint32_t *)(ARM_V7M_CACHE_MAINT_BASE + ARM_V7M_ICIALLU_OFFSET) = 0U;
    __asm__ volatile ("dsb" ::: "memory");
    __asm__ volatile ("isb" ::: "memory");
}

/**
 * @brief Instruction Cache line Invalidate by Address to PoU (ICIMVAU)
 * @param addr Address to invalidate (line is determined by address)
 */
ARM_V7M_CACHE_INLINE void arm_v7m_icimvau(uint32_t addr)
{
    *(volatile uint32_t *)(ARM_V7M_CACHE_MAINT_BASE + ARM_V7M_ICIMVAU_OFFSET) = addr;
    __asm__ volatile ("dsb" ::: "memory");
    __asm__ volatile ("isb" ::: "memory");
}

/**
 * @brief Data Cache line Invalidate by Address to PoC (DCIMVAC)
 * @param addr Address to invalidate
 */
ARM_V7M_CACHE_INLINE void arm_v7m_dcimvac(uint32_t addr)
{
    *(volatile uint32_t *)(ARM_V7M_CACHE_MAINT_BASE + ARM_V7M_DCIMVAC_OFFSET) = addr;
    __asm__ volatile ("dsb" ::: "memory");
}

/**
 * @brief Data Cache line Invalidate by Set/Way (DCISW)
 * @param set_way Set/way encoding
 */
ARM_V7M_CACHE_INLINE void arm_v7m_dcisw(uint32_t set_way)
{
    *(volatile uint32_t *)(ARM_V7M_CACHE_MAINT_BASE + ARM_V7M_DCISW_OFFSET) = set_way;
    __asm__ volatile ("dsb" ::: "memory");
}

/**
 * @brief Data Cache line Clean by Address to PoU (DCCMVAU)
 * @param addr Address to clean
 */
ARM_V7M_CACHE_INLINE void arm_v7m_dccmvau(uint32_t addr)
{
    *(volatile uint32_t *)(ARM_V7M_CACHE_MAINT_BASE + ARM_V7M_DCCMVAU_OFFSET) = addr;
    __asm__ volatile ("dsb" ::: "memory");
}

/**
 * @brief Data Cache line Clean by Address to PoC (DCCMVAC)
 * @param addr Address to clean
 */
ARM_V7M_CACHE_INLINE void arm_v7m_dccmvac(uint32_t addr)
{
    *(volatile uint32_t *)(ARM_V7M_CACHE_MAINT_BASE + ARM_V7M_DCCMVAC_OFFSET) = addr;
    __asm__ volatile ("dsb" ::: "memory");
}

/**
 * @brief Data Cache line Clean by Set/Way (DCCSW)
 * @param set_way Set/way encoding
 */
ARM_V7M_CACHE_INLINE void arm_v7m_dccsw(uint32_t set_way)
{
    *(volatile uint32_t *)(ARM_V7M_CACHE_MAINT_BASE + ARM_V7M_DCCSW_OFFSET) = set_way;
    __asm__ volatile ("dsb" ::: "memory");
}

/**
 * @brief Data Cache line Clean and Invalidate by Address to PoC (DCCIMVAC)
 * @param addr Address to clean and invalidate
 */
ARM_V7M_CACHE_INLINE void arm_v7m_dccimvac(uint32_t addr)
{
    *(volatile uint32_t *)(ARM_V7M_CACHE_MAINT_BASE + ARM_V7M_DCCIMVAC_OFFSET) = addr;
    __asm__ volatile ("dsb" ::: "memory");
}

/**
 * @brief Data Cache line Clean and Invalidate by Set/Way (DCCISW)
 * @param set_way Set/way encoding
 */
ARM_V7M_CACHE_INLINE void arm_v7m_dccisw(uint32_t set_way)
{
    *(volatile uint32_t *)(ARM_V7M_CACHE_MAINT_BASE + ARM_V7M_DCCISW_OFFSET) = set_way;
    __asm__ volatile ("dsb" ::: "memory");
}

/*============================================================================*
 * Non-Inline Functions - High-level Cache Operations
 *============================================================================*/

/* I-Cache Operations */
void arm_v7m_icache_enable(void);
void arm_v7m_icache_disable(void);
void arm_v7m_icache_invalidate_all(void);
void arm_v7m_icache_invalidate_line(uint32_t addr);
uint32_t arm_v7m_icache_is_enabled(void);

/* D-Cache Operations */
void arm_v7m_dcache_enable(void);
void arm_v7m_dcache_disable(void);
void arm_v7m_dcache_invalidate_all(void);
void arm_v7m_dcache_clean_all(void);
void arm_v7m_dcache_clean_invalidate_all(void);
void arm_v7m_dcache_invalidate_line(uint32_t addr);
void arm_v7m_dcache_clean_line(uint32_t addr);
void arm_v7m_dcache_clean_invalidate_line(uint32_t addr);
uint32_t arm_v7m_dcache_is_enabled(void);

/* Cache Info Functions */
uint32_t arm_v7m_cache_get_info(uint32_t level, uint32_t ind, arm_v7m_cache_info_t *info);
uint32_t arm_v7m_cache_get_line_size(uint32_t level, uint32_t ind);
uint32_t arm_v7m_icache_get_info(arm_v7m_cache_info_t *info);
uint32_t arm_v7m_dcache_get_info(arm_v7m_cache_info_t *info);

/* Cache Maintenance Range Functions */
void arm_v7m_dcache_invalidate_range(uint32_t start, uint32_t end);
void arm_v7m_dcache_clean_range(uint32_t start, uint32_t end);
void arm_v7m_dcache_clean_invalidate_range(uint32_t start, uint32_t end);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CACHE_H */
