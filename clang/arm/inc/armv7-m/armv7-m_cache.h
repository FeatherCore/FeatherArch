/*
 * ARM Architecture - ARMv7-M Cache Operations
 *
 * ============================================================================
 * File: armv7-m_cache.h
 * Description: ARMv7-M cache maintenance operations
 * 描述: ARMv7-M 缓存维护操作
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B3.2 - Cache maintenance operations
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_CACHE_H__
#define __ARCH_ARM_V7M_CACHE_H__

#include <stdint.h>
#include "armv7-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

#if (__ICACHE_PRESENT == 1) || (__DCACHE_PRESENT == 1)

/*
 * ============================================================================
 * Cache Maintenance Operations
 * 缓存维护操作
 * ============================================================================
 */

/**
 * @brief Invalidate all instruction cache to PoU
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B3.2 - Cache maintenance operations
 */
static inline void __IALLU(void) {
    __asm__ volatile ("IALLU" ::: "memory");
}

/**
 * @brief Invalidate instruction cache by address to PoU
 * @param addr Address to invalidate
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B3.2 - Cache maintenance operations
 */
static inline void __IINVA(uint32_t addr) {
    __asm__ volatile ("ICIMVAU %0" : : "r" (addr) : "memory");
}

/**
 * @brief Clean data cache by address to PoU
 * @param addr Address to clean
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B3.2 - Cache maintenance operations
 */
static inline void __DCCMVAU(uint32_t addr) {
    __asm__ volatile ("DCCMVAU %0" : : "r" (addr) : "memory");
}

/**
 * @brief Invalidate data cache by address to PoC
 * @param addr Address to invalidate
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B3.2 - Cache maintenance operations
 */
static inline void __DCIMVAC(uint32_t addr) {
    __asm__ volatile ("DCIMVAC %0" : : "r" (addr) : "memory");
}

/**
 * @brief Clean data cache by address to PoC
 * @param addr Address to clean
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B3.2 - Cache maintenance operations
 */
static inline void __DCCMVAC(uint32_t addr) {
    __asm__ volatile ("DCCMVAC %0" : : "r" (addr) : "memory");
}

/**
 * @brief Clean and invalidate data cache by address to PoC
 * @param addr Address to clean and invalidate
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B3.2 - Cache maintenance operations
 */
static inline void __DCCIMVAC(uint32_t addr) {
    __asm__ volatile ("DCCIMVAC %0" : : "r" (addr) : "memory");
}

/**
 * @brief Clean data cache by set/way
 * @param sw Set/way value
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B3.2 - Cache maintenance operations
 */
static inline void __DCCSW(uint32_t sw) {
    __asm__ volatile ("DCCSW %0" : : "r" (sw) : "memory");
}

/**
 * @brief Invalidate data cache by set/way
 * @param sw Set/way value
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B3.2 - Cache maintenance operations
 */
static inline void __DCISW(uint32_t sw) {
    __asm__ volatile ("DCISW %0" : : "r" (sw) : "memory");
}

/**
 * @brief Clean and invalidate data cache by set/way
 * @param sw Set/way value
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B3.2 - Cache maintenance operations
 */
static inline void __DCCISW(uint32_t sw) {
    __asm__ volatile ("DCCISW %0" : : "r" (sw) : "memory");
}

/**
 * @brief Invalidate branch predictor
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B3.2 - Cache maintenance operations
 */
static inline void __BPIALL(void) {
    __asm__ volatile ("BPIALL" ::: "memory");
}

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

#if (__ICACHE_PRESENT == 1)
/**
 * @brief Enable Instruction Cache
 */
void icache_enable(void);

/**
 * @brief Disable Instruction Cache
 */
void icache_disable(void);

/**
 * @brief Invalidate entire Instruction Cache
 */
void icache_invalidate_all(void);
#endif

#if (__DCACHE_PRESENT == 1)
/**
 * @brief Enable Data Cache
 */
void dcache_enable(void);

/**
 * @brief Disable Data Cache
 */
void dcache_disable(void);

/**
 * @brief Clean entire Data Cache
 */
void dcache_clean_all(void);

/**
 * @brief Invalidate entire Data Cache
 */
void dcache_invalidate_all(void);

/**
 * @brief Clean and invalidate entire Data Cache
 */
void dcache_clean_invalidate_all(void);

/**
 * @brief Clean a range of Data Cache
 * @param addr Start address
 * @param size Size in bytes
 */
void dcache_clean_range(uint32_t addr, uint32_t size);

/**
 * @brief Invalidate a range of Data Cache
 * @param addr Start address
 * @param size Size in bytes
 */
void dcache_invalidate_range(uint32_t addr, uint32_t size);

/**
 * @brief Clean and invalidate a range of Data Cache
 * @param addr Start address
 * @param size Size in bytes
 */
void dcache_clean_invalidate_range(uint32_t addr, uint32_t size);
#endif

#endif /* (__ICACHE_PRESENT == 1) || (__DCACHE_PRESENT == 1) */

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_CACHE_H__ */
