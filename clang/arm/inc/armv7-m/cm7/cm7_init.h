/*
 * ARM Architecture - Cortex-M7 Initialization
 *
 * ============================================================================
 * File: cm7_init.h
 * Description: Cortex-M7 initialization and system control functions
 * 描述: Cortex-M7 初始化和系统控制函数
 *
 * @reference Arm Cortex-M7 Processor Technical Reference Manual
 *   - Section 3.2 Register summary, Table 3-1 System control registers
 *   - Section 3.3.1 Auxiliary Control Register
 *
 * @reference Arm Cortex-M7 Devices Generic User Guide
 *   - Section 2.1 Programmers model
 *   - Section 2.5 Power management
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef CM7_INIT_H
#define CM7_INIT_H

#include <stdint.h>
#include "core_cm7.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================================
 * System Control Functions
 * 系统控制函数
 * ============================================================================ */

/**
 * @brief Initialize the Cortex-M7 processor
 * 初始化 Cortex-M7 处理器
 *
 * This function performs the following initialization steps:
 * 1. Enable ITCM and DTCM if present
 * 2. Enable caches if present
 * 3. Configure FPU if present
 * 4. Initialize system control registers
 *
 * @reference Arm Cortex-M7 Devices Generic User Guide, Section 1.1
 */
void cm7_init(void);

/**
 * @brief Deinitialize the Cortex-M7 processor
 * 反初始化 Cortex-M7 处理器
 *
 * This function disables caches, TCM, and FPU.
 */
void cm7_deinit(void);

/* ============================================================================
 * Cache Control Functions
 * 缓存控制函数
 * ============================================================================ */

#if (__ICACHE_PRESENT == 1)
/**
 * @brief Enable Instruction Cache
 * 使能指令缓存
 *
 * @reference Arm Cortex-M7 Devices Generic User Guide, Section 4.8
 */
void cm7_icache_enable(void);

/**
 * @brief Disable Instruction Cache
 * 禁用指令缓存
 */
void cm7_icache_disable(void);

/**
 * @brief Invalidate Instruction Cache
 * 使指令缓存失效
 *
 * Invalidates the entire instruction cache.
 */
void cm7_icache_invalidate(void);
#endif /* __ICACHE_PRESENT */

#if (__DCACHE_PRESENT == 1)
/**
 * @brief Enable Data Cache
 * 使能数据缓存
 *
 * @reference Arm Cortex-M7 Devices Generic User Guide, Section 4.8
 */
void cm7_dcache_enable(void);

/**
 * @brief Disable Data Cache
 * 禁用数据缓存
 */
void cm7_dcache_disable(void);

/**
 * @brief Invalidate Data Cache
 * 使数据缓存失效
 *
 * Invalidates the entire data cache.
 */
void cm7_dcache_invalidate(void);

/**
 * @brief Clean Data Cache
 * 清理数据缓存
 *
 * Cleans the entire data cache (write back dirty data).
 */
void cm7_dcache_clean(void);

/**
 * @brief Clean and Invalidate Data Cache
 * 清理并使数据缓存失效
 *
 * Cleans and invalidates the entire data cache.
 */
void cm7_dcache_clean_invalidate(void);

/**
 * @brief Invalidate Data Cache by Address
 * 按地址使数据缓存失效
 *
 * @param addr Start address
 * @param size Size in bytes
 */
void cm7_dcache_invalidate_by_addr(uint32_t addr, uint32_t size);

/**
 * @brief Clean Data Cache by Address
 * 按地址清理数据缓存
 *
 * @param addr Start address
 * @param size Size in bytes
 */
void cm7_dcache_clean_by_addr(uint32_t addr, uint32_t size);

/**
 * @brief Clean and Invalidate Data Cache by Address
 * 按地址清理并使数据缓存失效
 *
 * @param addr Start address
 * @param size Size in bytes
 */
void cm7_dcache_clean_invalidate_by_addr(uint32_t addr, uint32_t size);
#endif /* __DCACHE_PRESENT */

/* ============================================================================
 * TCM Control Functions
 * TCM 控制函数
 * ============================================================================ */

#if (__ITCM_PRESENT == 1)
/**
 * @brief Enable Instruction TCM
 * 使能指令 TCM
 *
 * @reference Arm Cortex-M7 Processor Technical Reference Manual, Section 3.3.6
 */
void cm7_itcm_enable(void);

/**
 * @brief Disable Instruction TCM
 * 禁用指令 TCM
 */
void cm7_itcm_disable(void);
#endif /* __ITCM_PRESENT */

#if (__DTCM_PRESENT == 1)
/**
 * @brief Enable Data TCM
 * 使能数据 TCM
 *
 * @reference Arm Cortex-M7 Processor Technical Reference Manual, Section 3.3.6
 */
void cm7_dtcm_enable(void);

/**
 * @brief Disable Data TCM
 * 禁用数据 TCM
 */
void cm7_dtcm_disable(void);
#endif /* __DTCM_PRESENT */

/* ============================================================================
 * Power Management Functions
 * 电源管理函数
 * ============================================================================ */

/**
 * @brief Enter Sleep Mode
 * 进入睡眠模式
 *
 * Suspends execution until wakeup event occurs.
 * @reference Arm Cortex-M7 Devices Generic User Guide, Section 2.5
 */
void cm7_sleep(void);

/**
 * @brief Enter Deep Sleep Mode
 * 进入深度睡眠模式
 *
 * Suspends execution and may power down additional components.
 */
void cm7_deep_sleep(void);

/**
 * @brief Wait For Interrupt
 * 等待中断
 *
 * Suspends execution until an interrupt occurs.
 */
void cm7_wfi(void);

/**
 * @brief Wait For Event
 * 等待事件
 *
 * Suspends execution until an event occurs.
 */
void cm7_wfe(void);

/**
 * @brief Send Event
 * 发送事件
 *
 * Sends an event to wake up processors in WFE.
 */
void cm7_sev(void);

/* ============================================================================
 * System Information Functions
 * 系统信息函数
 * ============================================================================ */

/**
 * @brief Get CPUID
 * 获取 CPUID
 *
 * @return CPUID register value
 */
uint32_t cm7_get_cpuid(void);

/**
 * @brief Get cache type information
 * 获取缓存类型信息
 *
 * @return CTR register value
 */
uint32_t cm7_get_cache_type(void);

/**
 * @brief Get cache size ID
 * 获取缓存大小 ID
 *
 * @param cache_type 0 = Data cache, 1 = Instruction cache
 * @return CCSIDR register value
 */
uint32_t cm7_get_cache_size_id(uint32_t cache_type);

#ifdef __cplusplus
}
#endif

#endif /* CM7_INIT_H */
