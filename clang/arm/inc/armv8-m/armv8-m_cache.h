/*
 * ARM Architecture - ARMv8-M Cache Operations
 *
 * ============================================================================
 * File: armv8m_cache.h
 * Description: ARMv8-M cache maintenance operations
 * 描述: ARMv8-M 缓存维护操作
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B3: Programmers' Model (Cache maintenance operations)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V8M_CACHE_H__
#define __ARCH_ARM_V8M_CACHE_H__

#include <stdint.h>
#include "armv8-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * Cache Maintenance Operations Register Definitions
 * 缓存维护操作寄存器定义
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.18
 * ============================================================================
 */

#define CMO_BASE_ADDR             0xE000EF50UL
#define CMO_NS_BASE_ADDR          0xE002EF50UL

/**
 * Instruction Cache Invalidate All to PoU (ICIALLU)
 * 指令缓存全部无效到PoU
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.18
 */
#define CMO_ICIALLU               (*(volatile uint32_t *)(CMO_BASE_ADDR + 0x000))
#define CMO_NS_ICIALLU            (*(volatile uint32_t *)(CMO_NS_BASE_ADDR + 0x000))

/**
 * Instruction Cache line Invalidate by Address to PoU (ICIMVAU)
 * 指令缓存行按地址无效到PoU
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.18
 */
#define CMO_ICIMVAU               (*(volatile uint32_t *)(CMO_BASE_ADDR + 0x008))
#define CMO_NS_ICIMVAU            (*(volatile uint32_t *)(CMO_NS_BASE_ADDR + 0x008))

/**
 * Data Cache line Invalidate by Address to PoC (DCIMVAC)
 * 数据缓存行按地址无效到PoC
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.18
 */
#define CMO_DCIMVAC               (*(volatile uint32_t *)(CMO_BASE_ADDR + 0x00C))
#define CMO_NS_DCIMVAC            (*(volatile uint32_t *)(CMO_NS_BASE_ADDR + 0x00C))

/**
 * Data Cache line Invalidate by Set/Way (DCISW)
 * 数据缓存行按组/路无效
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.18
 */
#define CMO_DCISW                 (*(volatile uint32_t *)(CMO_BASE_ADDR + 0x010))
#define CMO_NS_DCISW              (*(volatile uint32_t *)(CMO_NS_BASE_ADDR + 0x010))

/**
 * Data Cache line Clean by address to PoU (DCCMVAU)
 * 数据缓存行按地址清理到PoU
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.18
 */
#define CMO_DCCMVAU               (*(volatile uint32_t *)(CMO_BASE_ADDR + 0x014))
#define CMO_NS_DCCMVAU            (*(volatile uint32_t *)(CMO_NS_BASE_ADDR + 0x014))

/**
 * Data Cache line Clean by Address to PoC (DCCMVAC)
 * 数据缓存行按地址清理到PoC
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.18
 */
#define CMO_DCCMVAC               (*(volatile uint32_t *)(CMO_BASE_ADDR + 0x018))
#define CMO_NS_DCCMVAC            (*(volatile uint32_t *)(CMO_NS_BASE_ADDR + 0x018))

/**
 * Data Cache Clean line by Set/Way (DCCSW)
 * 数据缓存行按组/路清理
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.18
 */
#define CMO_DCCSW                 (*(volatile uint32_t *)(CMO_BASE_ADDR + 0x01C))
#define CMO_NS_DCCSW              (*(volatile uint32_t *)(CMO_NS_BASE_ADDR + 0x01C))

/**
 * Data Cache line Clean and Invalidate by Address to PoC (DCCIMVAC)
 * 数据缓存行按地址清理并无效到PoC
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.18
 */
#define CMO_DCCIMVAC              (*(volatile uint32_t *)(CMO_BASE_ADDR + 0x020))
#define CMO_NS_DCCIMVAC           (*(volatile uint32_t *)(CMO_NS_BASE_ADDR + 0x020))

/**
 * Data Cache line Clean and Invalidate by Set/Way (DCCISW)
 * 数据缓存行按组/路清理并无效
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.18
 */
#define CMO_DCCISW                (*(volatile uint32_t *)(CMO_BASE_ADDR + 0x024))
#define CMO_NS_DCCISW             (*(volatile uint32_t *)(CMO_NS_BASE_ADDR + 0x024))

/**
 * Branch Predictor Invalidate All (BPIALL)
 * 分支预测器全部无效
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.18
 */
#define CMO_BPIALL                (*(volatile uint32_t *)(CMO_BASE_ADDR + 0x028))
#define CMO_NS_BPIALL             (*(volatile uint32_t *)(CMO_NS_BASE_ADDR + 0x028))

/*
 * ============================================================================
 * Cache Maintenance Operations
 * 缓存维护操作
 * ============================================================================
 */

/**
 * @brief Invalidate all instruction cache to PoU
 */
static inline void __IINVALL(void) {
    __asm__ volatile ("IALLU" ::: "memory");
}

/**
 * @brief Invalidate instruction cache by address to PoU
 * @param addr Address to invalidate
 */
static inline void __IINVA(uint32_t addr) {
    __asm__ volatile ("ICIALLU" ::: "memory");
}

/**
 * @brief Clean data cache by address to PoU
 * @param addr Address to clean
 */
static inline void __DCMVAC(uint32_t addr) {
    __asm__ volatile ("DCCMVAC %0" : : "r" (addr) : "memory");
}

/**
 * @brief Invalidate data cache by address to PoC
 * @param addr Address to invalidate
 */
static inline void __DCIMVAC(uint32_t addr) {
    __asm__ volatile ("DCIMVAC %0" : : "r" (addr) : "memory");
}

/**
 * @brief Clean and invalidate data cache by address to PoC
 * @param addr Address to clean and invalidate
 */
static inline void __DCCIMVAC(uint32_t addr) {
    __asm__ volatile ("DCCIMVAC %0" : : "r" (addr) : "memory");
}

/**
 * @brief Clean data cache by set/way
 * @param setway Set/way value
 */
static inline void __DCCSW(uint32_t setway) {
    __asm__ volatile ("DCCSW %0" : : "r" (setway) : "memory");
}

/**
 * @brief Invalidate data cache by set/way
 * @param setway Set/way value
 */
static inline void __DCISW(uint32_t setway) {
    __asm__ volatile ("DCISW %0" : : "r" (setway) : "memory");
}

/**
 * @brief Clean and invalidate data cache by set/way
 * @param setway Set/way value
 */
static inline void __DCCISW(uint32_t setway) {
    __asm__ volatile ("DCCISW %0" : : "r" (setway) : "memory");
}

/*
 * ============================================================================
 * Branch Prediction Operations
 * 分支预测操作
 * ============================================================================
 */

/**
 * @brief Invalidate all branch predictors
 */
static inline void __BPIALL(void) {
    __asm__ volatile ("BPIALL" ::: "memory");
}

/**
 * @brief Invalidate branch predictor by address
 * @param addr Address to invalidate
 */
static inline void __BPIMVA(uint32_t addr) {
    __asm__ volatile ("BPIMVA %0" : : "r" (addr) : "memory");
}

/*
 * ============================================================================
 * Cache Control Functions
 * 缓存控制函数
 * ============================================================================
 */

/**
 * @brief Enable instruction cache
 */
void icache_enable(void);

/**
 * @brief Disable instruction cache
 */
void icache_disable(void);

/**
 * @brief Invalidate entire instruction cache
 */
void icache_invalidate_all(void);

/**
 * @brief Enable data cache
 */
void dcache_enable(void);

/**
 * @brief Disable data cache
 */
void dcache_disable(void);

/**
 * @brief Clean entire data cache
 */
void dcache_clean_all(void);

/**
 * @brief Invalidate entire data cache
 */
void dcache_invalidate_all(void);

/**
 * @brief Clean and invalidate entire data cache
 */
void dcache_clean_invalidate_all(void);

/**
 * @brief Clean data cache by address range
 * @param addr Start address
 * @param size Size in bytes
 */
void dcache_clean_range(uint32_t addr, uint32_t size);

/**
 * @brief Invalidate data cache by address range
 * @param addr Start address
 * @param size Size in bytes
 */
void dcache_invalidate_range(uint32_t addr, uint32_t size);

/**
 * @brief Clean and invalidate data cache by address range
 * @param addr Start address
 * @param size Size in bytes
 */
void dcache_clean_invalidate_range(uint32_t addr, uint32_t size);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V8M_CACHE_H__ */
