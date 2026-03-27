/*
 * arm_v7m_cm7_cache.h
 * Cortex-M7 Cache Maintenance Operations Definitions
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
 *            - Section 4.5.1: Cache Level ID Register on page 4-38
 *            - Section 4.5.2: Cache Type Register on page 4-38
 *            - Section 4.5.3: Cache Size ID Register on page 4-39
 *            - Section 4.5.4: Cache Size Selection Register on page 4-40
 *            - Chapter 4.8: Cache maintenance operations on page 4-61
 *            - Table 4-64: Cache maintenance operation registers on page 4-61
 *            - Section 4.3.5: Configuration and Control Register (CCR) - IC/DC bits on page 4-19
 *            Cortex-M7 Technical Reference Manual, Chapter 5.9 and Section 3.3
 *            - Chapter 5.9: L1 caches on page 5-41
 *            - Section 3.3: Cache and branch predictor maintenance registers on page 3-8
 *            - Table 3-3: Cache and branch predictor maintenance operations on page 3-8
 *
 * @note This file wraps the generic Armv7-M cache implementation for Cortex-M7.
 *       Cache is optional in ARMv7-M but standard in Cortex-M7.
 */

#ifndef ARM_V7M_CM7_CACHE_H
#define ARM_V7M_CM7_CACHE_H

#include <stdint.h>
#include "../arm_v7m_cache.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Compiler Abstraction - Inline Definition
 *============================================================================*/

#if defined(__clang__)
    #define ARM_V7M_CM7_CACHE_INLINE static inline __attribute__((always_inline))
#else
    #error "This library requires Clang/LLVM compiler."
#endif

/*============================================================================*
 * Type Aliases
 *============================================================================*/

typedef arm_v7m_cache_info_t    arm_v7m_cm7_cache_info_t;

/*============================================================================*
 * Constant Aliases - CCR Register Bit Definitions
 *============================================================================*/

#define ARM_V7M_CM7_CCR_IC_Pos          ARM_V7M_CCR_IC_Pos
#define ARM_V7M_CM7_CCR_IC_Msk          ARM_V7M_CCR_IC_Msk
#define ARM_V7M_CM7_CCR_DC_Pos          ARM_V7M_CCR_DC_Pos
#define ARM_V7M_CM7_CCR_DC_Msk          ARM_V7M_CCR_DC_Msk

/*============================================================================*
 * Constant Aliases - CCSIDR Register Bit Definitions
 *============================================================================*/

#define ARM_V7M_CM7_CCSIDR_LINESIZE_Pos         ARM_V7M_CCSIDR_LINESIZE_Pos
#define ARM_V7M_CM7_CCSIDR_LINESIZE_Msk         ARM_V7M_CCSIDR_LINESIZE_Msk
#define ARM_V7M_CM7_CCSIDR_ASSOCIATIVITY_Pos    ARM_V7M_CCSIDR_ASSOCIATIVITY_Pos
#define ARM_V7M_CM7_CCSIDR_ASSOCIATIVITY_Msk    ARM_V7M_CCSIDR_ASSOCIATIVITY_Msk
#define ARM_V7M_CM7_CCSIDR_NUMSETS_Pos          ARM_V7M_CCSIDR_NUMSETS_Pos
#define ARM_V7M_CM7_CCSIDR_NUMSETS_Msk          ARM_V7M_CCSIDR_NUMSETS_Msk
#define ARM_V7M_CM7_CCSIDR_WA_Pos               ARM_V7M_CCSIDR_WA_Pos
#define ARM_V7M_CM7_CCSIDR_WA_Msk               ARM_V7M_CCSIDR_WA_Msk
#define ARM_V7M_CM7_CCSIDR_RA_Pos               ARM_V7M_CCSIDR_RA_Pos
#define ARM_V7M_CM7_CCSIDR_RA_Msk               ARM_V7M_CCSIDR_RA_Msk
#define ARM_V7M_CM7_CCSIDR_WB_Pos               ARM_V7M_CCSIDR_WB_Pos
#define ARM_V7M_CM7_CCSIDR_WB_Msk               ARM_V7M_CCSIDR_WB_Msk
#define ARM_V7M_CM7_CCSIDR_WT_Pos               ARM_V7M_CCSIDR_WT_Pos
#define ARM_V7M_CM7_CCSIDR_WT_Msk               ARM_V7M_CCSIDR_WT_Msk

/*============================================================================*
 * Constant Aliases - CSSELR Register Bit Definitions
 *============================================================================*/

#define ARM_V7M_CM7_CSSELR_IND_Pos      ARM_V7M_CSSELR_IND_Pos
#define ARM_V7M_CM7_CSSELR_IND_Msk      ARM_V7M_CSSELR_IND_Msk
#define ARM_V7M_CM7_CSSELR_LEVEL_Pos    ARM_V7M_CSSELR_LEVEL_Pos
#define ARM_V7M_CM7_CSSELR_LEVEL_Msk    ARM_V7M_CSSELR_LEVEL_Msk

#define ARM_V7M_CM7_CSSELR_IND_DATA     ARM_V7M_CSSELR_IND_DATA
#define ARM_V7M_CM7_CSSELR_IND_INSTR    ARM_V7M_CSSELR_IND_INSTR

/*============================================================================*
 * Constant Aliases - CLIDR Register Bit Definitions
 *============================================================================*/

#define ARM_V7M_CM7_CLIDR_CTYPE1_Pos    ARM_V7M_CLIDR_CTYPE1_Pos
#define ARM_V7M_CM7_CLIDR_CTYPE1_Msk    ARM_V7M_CLIDR_CTYPE1_Msk
#define ARM_V7M_CM7_CLIDR_CTYPE2_Pos    ARM_V7M_CLIDR_CTYPE2_Pos
#define ARM_V7M_CM7_CLIDR_CTYPE2_Msk    ARM_V7M_CLIDR_CTYPE2_Msk
#define ARM_V7M_CM7_CLIDR_CTYPE3_Pos    ARM_V7M_CLIDR_CTYPE3_Pos
#define ARM_V7M_CM7_CLIDR_CTYPE3_Msk    ARM_V7M_CLIDR_CTYPE3_Msk
#define ARM_V7M_CM7_CLIDR_CTYPE4_Pos    ARM_V7M_CLIDR_CTYPE4_Pos
#define ARM_V7M_CM7_CLIDR_CTYPE4_Msk    ARM_V7M_CLIDR_CTYPE4_Msk
#define ARM_V7M_CM7_CLIDR_CTYPE5_Pos    ARM_V7M_CLIDR_CTYPE5_Pos
#define ARM_V7M_CM7_CLIDR_CTYPE5_Msk    ARM_V7M_CLIDR_CTYPE5_Msk
#define ARM_V7M_CM7_CLIDR_CTYPE6_Pos    ARM_V7M_CLIDR_CTYPE6_Pos
#define ARM_V7M_CM7_CLIDR_CTYPE6_Msk    ARM_V7M_CLIDR_CTYPE6_Msk
#define ARM_V7M_CM7_CLIDR_CTYPE7_Pos    ARM_V7M_CLIDR_CTYPE7_Pos
#define ARM_V7M_CM7_CLIDR_CTYPE7_Msk    ARM_V7M_CLIDR_CTYPE7_Msk
#define ARM_V7M_CM7_CLIDR_LOUIS_Pos     ARM_V7M_CLIDR_LOUIS_Pos
#define ARM_V7M_CM7_CLIDR_LOUIS_Msk     ARM_V7M_CLIDR_LOUIS_Msk
#define ARM_V7M_CM7_CLIDR_LOC_Pos       ARM_V7M_CLIDR_LOC_Pos
#define ARM_V7M_CM7_CLIDR_LOC_Msk       ARM_V7M_CLIDR_LOC_Msk
#define ARM_V7M_CM7_CLIDR_LOUU_Pos      ARM_V7M_CLIDR_LOUU_Pos
#define ARM_V7M_CM7_CLIDR_LOUU_Msk      ARM_V7M_CLIDR_LOUU_Msk
#define ARM_V7M_CM7_CLIDR_ICB_Pos       ARM_V7M_CLIDR_ICB_Pos
#define ARM_V7M_CM7_CLIDR_ICB_Msk       ARM_V7M_CLIDR_ICB_Msk

#define ARM_V7M_CM7_CLIDR_CTYPE_NONE    ARM_V7M_CLIDR_CTYPE_NONE
#define ARM_V7M_CM7_CLIDR_CTYPE_ICACHE  ARM_V7M_CLIDR_CTYPE_ICACHE
#define ARM_V7M_CM7_CLIDR_CTYPE_DCACHE  ARM_V7M_CLIDR_CTYPE_DCACHE
#define ARM_V7M_CM7_CLIDR_CTYPE_UNIFIED ARM_V7M_CLIDR_CTYPE_UNIFIED
#define ARM_V7M_CM7_CLIDR_CTYPE_HARVARD ARM_V7M_CLIDR_CTYPE_HARVARD

/*============================================================================*
 * Constant Aliases - CTR Register Bit Definitions
 *============================================================================*/

#define ARM_V7M_CM7_CTR_IMINLINE_Pos    ARM_V7M_CTR_IMINLINE_Pos
#define ARM_V7M_CM7_CTR_IMINLINE_Msk    ARM_V7M_CTR_IMINLINE_Msk
#define ARM_V7M_CM7_CTR_L1IP_Pos        ARM_V7M_CTR_L1IP_Pos
#define ARM_V7M_CM7_CTR_L1IP_Msk        ARM_V7M_CTR_L1IP_Msk
#define ARM_V7M_CM7_CTR_DMINLINE_Pos    ARM_V7M_CTR_DMINLINE_Pos
#define ARM_V7M_CM7_CTR_DMINLINE_Msk    ARM_V7M_CTR_DMINLINE_Msk
#define ARM_V7M_CM7_CTR_ERG_Pos         ARM_V7M_CTR_ERG_Pos
#define ARM_V7M_CM7_CTR_ERG_Msk         ARM_V7M_CTR_ERG_Msk
#define ARM_V7M_CM7_CTR_CWG_Pos         ARM_V7M_CTR_CWG_Pos
#define ARM_V7M_CM7_CTR_CWG_Msk         ARM_V7M_CTR_CWG_Msk
#define ARM_V7M_CM7_CTR_FORMAT_Pos      ARM_V7M_CTR_FORMAT_Pos
#define ARM_V7M_CM7_CTR_FORMAT_Msk      ARM_V7M_CTR_FORMAT_Msk

/*============================================================================*
 * Inline Functions - Cache ID Register Access (Aliased from generic)
 *============================================================================*/

/**
 * @brief Get Cache Level ID Register (CLIDR)
 * @return CLIDR value
 */
ARM_V7M_CM7_CACHE_INLINE uint32_t arm_v7m_cm7_cache_get_clidr(void)
{
    return arm_v7m_cache_get_clidr();
}

/**
 * @brief Get Cache Type Register (CTR)
 * @return CTR value
 */
ARM_V7M_CM7_CACHE_INLINE uint32_t arm_v7m_cm7_cache_get_ctr(void)
{
    return arm_v7m_cache_get_ctr();
}

/**
 * @brief Get Cache Size ID Register (CCSIDR)
 * @return CCSIDR value
 */
ARM_V7M_CM7_CACHE_INLINE uint32_t arm_v7m_cm7_cache_get_ccsidr(void)
{
    return arm_v7m_cache_get_ccsidr();
}

/**
 * @brief Get Cache Size Selection Register (CSSELR)
 * @return CSSELR value
 */
ARM_V7M_CM7_CACHE_INLINE uint32_t arm_v7m_cm7_cache_get_csselr(void)
{
    return arm_v7m_cache_get_csselr();
}

/**
 * @brief Set Cache Size Selection Register (CSSELR)
 * @param value CSSELR value
 */
ARM_V7M_CM7_CACHE_INLINE void arm_v7m_cm7_cache_set_csselr(uint32_t value)
{
    arm_v7m_cache_set_csselr(value);
}

/*============================================================================*
 * Inline Functions - Cache Maintenance Operations (Low-level, Aliased from generic)
 *============================================================================*/

/**
 * @brief Instruction Cache Invalidate All to PoU (ICIALLU)
 */
ARM_V7M_CM7_CACHE_INLINE void arm_v7m_cm7_iciallu(void)
{
    arm_v7m_iciallu();
}

/**
 * @brief Instruction Cache line Invalidate by Address to PoU (ICIMVAU)
 * @param addr Address to invalidate
 */
ARM_V7M_CM7_CACHE_INLINE void arm_v7m_cm7_icimvau(uint32_t addr)
{
    arm_v7m_icimvau(addr);
}

/**
 * @brief Data Cache line Invalidate by Address to PoC (DCIMVAC)
 * @param addr Address to invalidate
 */
ARM_V7M_CM7_CACHE_INLINE void arm_v7m_cm7_dcimvac(uint32_t addr)
{
    arm_v7m_dcimvac(addr);
}

/**
 * @brief Data Cache line Invalidate by Set/Way (DCISW)
 * @param set_way Set/way encoding
 */
ARM_V7M_CM7_CACHE_INLINE void arm_v7m_cm7_dcisw(uint32_t set_way)
{
    arm_v7m_dcisw(set_way);
}

/**
 * @brief Data Cache line Clean by Address to PoU (DCCMVAU)
 * @param addr Address to clean
 */
ARM_V7M_CM7_CACHE_INLINE void arm_v7m_cm7_dccmvau(uint32_t addr)
{
    arm_v7m_dccmvau(addr);
}

/**
 * @brief Data Cache line Clean by Address to PoC (DCCMVAC)
 * @param addr Address to clean
 */
ARM_V7M_CM7_CACHE_INLINE void arm_v7m_cm7_dccmvac(uint32_t addr)
{
    arm_v7m_dccmvac(addr);
}

/**
 * @brief Data Cache line Clean by Set/Way (DCCSW)
 * @param set_way Set/way encoding
 */
ARM_V7M_CM7_CACHE_INLINE void arm_v7m_cm7_dccsw(uint32_t set_way)
{
    arm_v7m_dccsw(set_way);
}

/**
 * @brief Data Cache line Clean and Invalidate by Address to PoC (DCCIMVAC)
 * @param addr Address to clean and invalidate
 */
ARM_V7M_CM7_CACHE_INLINE void arm_v7m_cm7_dccimvac(uint32_t addr)
{
    arm_v7m_dccimvac(addr);
}

/**
 * @brief Data Cache line Clean and Invalidate by Set/Way (DCCISW)
 * @param set_way Set/way encoding
 */
ARM_V7M_CM7_CACHE_INLINE void arm_v7m_cm7_dccisw(uint32_t set_way)
{
    arm_v7m_dccisw(set_way);
}

/*============================================================================*
 * Non-Inline Functions - High-level Cache Operations (Aliased from generic)
 *============================================================================*/

/* I-Cache Operations */
void arm_v7m_cm7_icache_enable(void);
void arm_v7m_cm7_icache_disable(void);
void arm_v7m_cm7_icache_invalidate_all(void);
void arm_v7m_cm7_icache_invalidate_line(uint32_t addr);
uint32_t arm_v7m_cm7_icache_is_enabled(void);

/* D-Cache Operations */
void arm_v7m_cm7_dcache_enable(void);
void arm_v7m_cm7_dcache_disable(void);
void arm_v7m_cm7_dcache_invalidate_all(void);
void arm_v7m_cm7_dcache_clean_all(void);
void arm_v7m_cm7_dcache_clean_invalidate_all(void);
void arm_v7m_cm7_dcache_invalidate_line(uint32_t addr);
void arm_v7m_cm7_dcache_clean_line(uint32_t addr);
void arm_v7m_cm7_dcache_clean_invalidate_line(uint32_t addr);
uint32_t arm_v7m_cm7_dcache_is_enabled(void);

/* Cache Info Functions */
uint32_t arm_v7m_cm7_cache_get_info(uint32_t level, uint32_t ind, arm_v7m_cm7_cache_info_t *info);
uint32_t arm_v7m_cm7_cache_get_line_size(uint32_t level, uint32_t ind);
uint32_t arm_v7m_cm7_icache_get_info(arm_v7m_cm7_cache_info_t *info);
uint32_t arm_v7m_cm7_dcache_get_info(arm_v7m_cm7_cache_info_t *info);

/* Cache Maintenance Range Functions */
void arm_v7m_cm7_dcache_invalidate_range(uint32_t start, uint32_t end);
void arm_v7m_cm7_dcache_clean_range(uint32_t start, uint32_t end);
void arm_v7m_cm7_dcache_clean_invalidate_range(uint32_t start, uint32_t end);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM7_CACHE_H */
