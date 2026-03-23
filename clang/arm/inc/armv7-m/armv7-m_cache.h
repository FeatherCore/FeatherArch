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
 *   - Table B3-32 Cache maintenance operations (page B3-620)
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
 * Cache Maintenance Operation Registers
 * 缓存维护操作寄存器
 * Reference: Table B3-32 Cache maintenance operations (page B3-620)
 * ============================================================================
 */

/**
 * ICIALLU - I-cache invalidate all to PoU
 * Address: 0xE000EF50
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620
 */
#define ICIALLU                   (*(volatile uint32_t *)(0xE000EF50UL))

/**
 * ICIMVAU - I-cache invalidate by MVA to PoU
 * Address: 0xE000EF58
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620
 */
#define ICIMVAU                   (*(volatile uint32_t *)(0xE000EF58UL))

/**
 * DCIMVAC - D-cache invalidate by MVA to PoC
 * Address: 0xE000EF5C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620
 */
#define DCIMVAC                   (*(volatile uint32_t *)(0xE000EF5CUL))

/**
 * DCISW - D-cache invalidate by set-way
 * Address: 0xE000EF60
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620
 */
#define DCISW                     (*(volatile uint32_t *)(0xE000EF60UL))

/**
 * DCCMVAU - D-cache clean by MVA to PoU
 * Address: 0xE000EF64
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620
 */
#define DCCMVAU                   (*(volatile uint32_t *)(0xE000EF64UL))

/**
 * DCCMVAC - D-cache clean by MVA to PoC
 * Address: 0xE000EF68
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620
 */
#define DCCMVAC                   (*(volatile uint32_t *)(0xE000EF68UL))

/**
 * DCCSW - D-cache clean by set-way
 * Address: 0xE000EF6C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620
 */
#define DCCSW                     (*(volatile uint32_t *)(0xE000EF6CUL))

/**
 * DCCIMVAC - D-cache clean and invalidate by MVA to PoC
 * Address: 0xE000EF70
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620
 */
#define DCCIMVAC                  (*(volatile uint32_t *)(0xE000EF70UL))

/**
 * DCCISW - D-cache clean and invalidate by set-way
 * Address: 0xE000EF74
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620
 */
#define DCCISW                    (*(volatile uint32_t *)(0xE000EF74UL))

/**
 * BPIALL - Branch predictor invalidate all
 * Address: 0xE000EF78
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620
 */
#define BPIALL                    (*(volatile uint32_t *)(0xE000EF78UL))

/*
 * ============================================================================
 * Cache Maintenance Operations
 * 缓存维护操作
 * Reference: Chapter B3.2 - Cache maintenance operations
 * ============================================================================
 */

/**
 * @brief Invalidate all instruction cache to PoU
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Table B3-32 Cache maintenance operations (page B3-620)
 */
static inline void __IALLU(void) {
    ICIALLU = 0U;
    __asm__ volatile ("dsb" ::: "memory");
    __asm__ volatile ("isb" ::: "memory");
}

/**
 * @brief Invalidate instruction cache by address to PoU
 * @param addr Address to invalidate
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Table B3-32 Cache maintenance operations (page B3-620)
 */
static inline void __IINVA(uint32_t addr) {
    ICIMVAU = addr;
    __asm__ volatile ("dsb" ::: "memory");
}

/**
 * @brief Clean data cache by address to PoU
 * @param addr Address to clean
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Table B3-32 Cache maintenance operations (page B3-620)
 */
static inline void __DCCMVAU(uint32_t addr) {
    DCCMVAU = addr;
    __asm__ volatile ("dsb" ::: "memory");
}

/**
 * @brief Invalidate data cache by address to PoC
 * @param addr Address to invalidate
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Table B3-32 Cache maintenance operations (page B3-620)
 */
static inline void __DCIMVAC(uint32_t addr) {
    DCIMVAC = addr;
    __asm__ volatile ("dsb" ::: "memory");
}

/**
 * @brief Clean data cache by address to PoC
 * @param addr Address to clean
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Table B3-32 Cache maintenance operations (page B3-620)
 */
static inline void __DCCMVAC(uint32_t addr) {
    DCCMVAC = addr;
    __asm__ volatile ("dsb" ::: "memory");
}

/**
 * @brief Clean and invalidate data cache by address to PoC
 * @param addr Address to clean and invalidate
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Table B3-32 Cache maintenance operations (page B3-620)
 */
static inline void __DCCIMVAC(uint32_t addr) {
    DCCIMVAC = addr;
    __asm__ volatile ("dsb" ::: "memory");
}

/**
 * @brief Clean data cache by set/way
 * @param sw Set/way value
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Table B3-32 Cache maintenance operations (page B3-620)
 */
static inline void __DCCSW(uint32_t sw) {
    DCCSW = sw;
    __asm__ volatile ("dsb" ::: "memory");
}

/**
 * @brief Invalidate data cache by set/way
 * @param sw Set/way value
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Table B3-32 Cache maintenance operations (page B3-620)
 */
static inline void __DCISW(uint32_t sw) {
    DCISW = sw;
    __asm__ volatile ("dsb" ::: "memory");
}

/**
 * @brief Clean and invalidate data cache by set/way
 * @param sw Set/way value
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Table B3-32 Cache maintenance operations (page B3-620)
 */
static inline void __DCCISW(uint32_t sw) {
    DCCISW = sw;
    __asm__ volatile ("dsb" ::: "memory");
}

/**
 * @brief Invalidate branch predictor
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Table B3-32 Cache maintenance operations (page B3-620)
 */
static inline void __BPIALL(void) {
    BPIALL = 0U;
    __asm__ volatile ("dsb" ::: "memory");
    __asm__ volatile ("isb" ::: "memory");
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
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-604 (CCR.IC bit)
 */
void icache_enable(void);

/**
 * @brief Disable Instruction Cache
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-604 (CCR.IC bit)
 */
void icache_disable(void);

/**
 * @brief Invalidate entire Instruction Cache
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620 (ICIALLU)
 */
void icache_invalidate_all(void);
#endif

#if (__DCACHE_PRESENT == 1)
/**
 * @brief Enable Data Cache
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-604 (CCR.DC bit)
 */
void dcache_enable(void);

/**
 * @brief Disable Data Cache
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-604 (CCR.DC bit)
 */
void dcache_disable(void);

/**
 * @brief Clean entire Data Cache
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620 (DCCSW)
 */
void dcache_clean_all(void);

/**
 * @brief Invalidate entire Data Cache
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620 (DCISW)
 */
void dcache_invalidate_all(void);

/**
 * @brief Clean and invalidate entire Data Cache
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620 (DCCISW)
 */
void dcache_clean_invalidate_all(void);

/**
 * @brief Clean a range of Data Cache
 * @param addr Start address
 * @param size Size in bytes
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620 (DCCMVAC)
 */
void dcache_clean_range(uint32_t addr, uint32_t size);

/**
 * @brief Invalidate a range of Data Cache
 * @param addr Start address
 * @param size Size in bytes
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620 (DCIMVAC)
 */
void dcache_invalidate_range(uint32_t addr, uint32_t size);

/**
 * @brief Clean and invalidate a range of Data Cache
 * @param addr Start address
 * @param size Size in bytes
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-620 (DCCIMVAC)
 */
void dcache_clean_invalidate_range(uint32_t addr, uint32_t size);
#endif

#endif /* (__ICACHE_PRESENT == 1) || (__DCACHE_PRESENT == 1) */

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_CACHE_H__ */
