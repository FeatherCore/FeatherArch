/*
 * ARM Architecture - Cortex-M7 Initialization
 *
 * ============================================================================
 * File: cm7_init.c
 * Description: Cortex-M7 initialization and system control functions
 * 描述: Cortex-M7 初始化和系统控制函数实现
 *
 * @reference Arm Cortex-M7 Processor Technical Reference Manual
 *   - Section 3.2 Register summary, Table 3-1 System control registers
 *   - Section 3.3.1 Auxiliary Control Register
 *   - Section 3.3.6 Instruction and Data Tightly-Coupled Memory Control Registers
 *
 * @reference Arm Cortex-M7 Devices Generic User Guide
 *   - Section 2.1 Programmers model
 *   - Section 2.5 Power management
 *   - Section 4.8 Cache maintenance operations
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/cm7/cm7_init.h"
#include "armv7-m/cm7/cm7_cache.h"
#include "armv7-m/cm7/cm7_tcm.h"
#include "armv7-m/cm7/cm7_ctrl.h"
#include "armv7-m/armv7-m_core.h"

/* ============================================================================
 * System Control Functions
 * 系统控制函数
 * ============================================================================ */

/**
 * @brief Initialize the Cortex-M7 processor
 * 初始化 Cortex-M7 处理器
 */
void cm7_init(void)
{
    /* Enable ITCM if present */
#if (__ITCM_PRESENT == 1)
    cm7_itcm_enable();
#endif

    /* Enable DTCM if present */
#if (__DTCM_PRESENT == 1)
    cm7_dtcm_enable();
#endif

    /* Enable caches if present */
#if (__DCACHE_PRESENT == 1)
    cm7_dcache_invalidate();
    cm7_dcache_enable();
#endif

#if (__ICACHE_PRESENT == 1)
    cm7_icache_invalidate();
    cm7_icache_enable();
#endif

    /* Configure FPU if present */
#if (__FPU_PRESENT == 1)
    /* Enable CP10 and CP11 coprocessors for FPU access */
    SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2));
    __DSB();
    __ISB();
#endif
}

/**
 * @brief Deinitialize the Cortex-M7 processor
 * 反初始化 Cortex-M7 处理器
 */
void cm7_deinit(void)
{
    /* Disable caches */
#if (__DCACHE_PRESENT == 1)
    cm7_dcache_clean_invalidate();
    cm7_dcache_disable();
#endif

#if (__ICACHE_PRESENT == 1)
    cm7_icache_invalidate();
    cm7_icache_disable();
#endif

    /* Disable TCM */
#if (__ITCM_PRESENT == 1)
    cm7_itcm_disable();
#endif

#if (__DTCM_PRESENT == 1)
    cm7_dtcm_disable();
#endif
}

/* ============================================================================
 * Cache Control Functions
 * 缓存控制函数
 * ============================================================================ */

#if (__ICACHE_PRESENT == 1)
/**
 * @brief Enable Instruction Cache
 * 使能指令缓存
 */
void cm7_icache_enable(void)
{
    /* Invalidate instruction cache first */
    CM7_ICIALLU = 0UL;
    __DSB();
    __ISB();

    /* Enable instruction cache in CCR */
    SCB->CCR |= SCB_CCR_IC_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Disable Instruction Cache
 * 禁用指令缓存
 */
void cm7_icache_disable(void)
{
    /* Disable instruction cache in CCR */
    SCB->CCR &= ~SCB_CCR_IC_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Invalidate Instruction Cache
 * 使指令缓存失效
 */
void cm7_icache_invalidate(void)
{
    CM7_ICIALLU = 0UL;
    __DSB();
    __ISB();
}
#endif /* __ICACHE_PRESENT */

#if (__DCACHE_PRESENT == 1)
/**
 * @brief Enable Data Cache
 * 使能数据缓存
 */
void cm7_dcache_enable(void)
{
    /* Invalidate data cache first */
    cm7_dcache_invalidate();

    /* Enable data cache in CCR */
    SCB->CCR |= SCB_CCR_DC_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Disable Data Cache
 * 禁用数据缓存
 */
void cm7_dcache_disable(void)
{
    /* Clean and invalidate data cache first */
    cm7_dcache_clean_invalidate();

    /* Disable data cache in CCR */
    SCB->CCR &= ~SCB_CCR_DC_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Invalidate Data Cache
 * 使数据缓存失效
 */
void cm7_dcache_invalidate(void)
{
    uint32_t ccsidr;
    uint32_t sets;
    uint32_t ways;

    /* Get cache size ID */
    CM7_CSSELR = 0UL;  /* Select data cache */
    __DSB();
    ccsidr = CM7_CCSIDR;

    sets = ((ccsidr & CM7_CCSIDR_NUMSETS_Msk) >> CM7_CCSIDR_NUMSETS_Pos);
    ways = ((ccsidr & CM7_CCSIDR_ASSOCIATIVITY_Msk) >> CM7_CCSIDR_ASSOCIATIVITY_Pos);

    for (uint32_t way = 0; way <= ways; way++) {
        for (uint32_t set = 0; set <= sets; set++) {
            CM7_DCISW = ((way << 30U) | (set << 4U));
        }
    }
    __DSB();
    __ISB();
}

/**
 * @brief Clean Data Cache
 * 清理数据缓存
 */
void cm7_dcache_clean(void)
{
    uint32_t ccsidr;
    uint32_t sets;
    uint32_t ways;

    /* Get cache size ID */
    CM7_CSSELR = 0UL;  /* Select data cache */
    __DSB();
    ccsidr = CM7_CCSIDR;

    sets = ((ccsidr & CM7_CCSIDR_NUMSETS_Msk) >> CM7_CCSIDR_NUMSETS_Pos);
    ways = ((ccsidr & CM7_CCSIDR_ASSOCIATIVITY_Msk) >> CM7_CCSIDR_ASSOCIATIVITY_Pos);

    for (uint32_t way = 0; way <= ways; way++) {
        for (uint32_t set = 0; set <= sets; set++) {
            CM7_DCCSW = ((way << 30U) | (set << 4U));
        }
    }
    __DSB();
    __ISB();
}

/**
 * @brief Clean and Invalidate Data Cache
 * 清理并使数据缓存失效
 */
void cm7_dcache_clean_invalidate(void)
{
    uint32_t ccsidr;
    uint32_t sets;
    uint32_t ways;

    /* Get cache size ID */
    CM7_CSSELR = 0UL;  /* Select data cache */
    __DSB();
    ccsidr = CM7_CCSIDR;

    sets = ((ccsidr & CM7_CCSIDR_NUMSETS_Msk) >> CM7_CCSIDR_NUMSETS_Pos);
    ways = ((ccsidr & CM7_CCSIDR_ASSOCIATIVITY_Msk) >> CM7_CCSIDR_ASSOCIATIVITY_Pos);

    for (uint32_t way = 0; way <= ways; way++) {
        for (uint32_t set = 0; set <= sets; set++) {
            CM7_DCCISW = ((way << 30U) | (set << 4U));
        }
    }
    __DSB();
    __ISB();
}

/**
 * @brief Invalidate Data Cache by Address
 * 按地址使数据缓存失效
 */
void cm7_dcache_invalidate_by_addr(uint32_t addr, uint32_t size)
{
    uint32_t line_size = __CM7_DCACHE_LINE_SIZE;
    uint32_t end_addr = addr + size;

    /* Align address to cache line boundary */
    addr &= ~(line_size - 1);

    while (addr < end_addr) {
        CM7_DCIMVAC = addr;
        addr += line_size;
    }
    __DSB();
    __ISB();
}

/**
 * @brief Clean Data Cache by Address
 * 按地址清理数据缓存
 */
void cm7_dcache_clean_by_addr(uint32_t addr, uint32_t size)
{
    uint32_t line_size = __CM7_DCACHE_LINE_SIZE;
    uint32_t end_addr = addr + size;

    /* Align address to cache line boundary */
    addr &= ~(line_size - 1);

    while (addr < end_addr) {
        CM7_DCCMVAC = addr;
        addr += line_size;
    }
    __DSB();
    __ISB();
}

/**
 * @brief Clean and Invalidate Data Cache by Address
 * 按地址清理并使数据缓存失效
 */
void cm7_dcache_clean_invalidate_by_addr(uint32_t addr, uint32_t size)
{
    uint32_t line_size = __CM7_DCACHE_LINE_SIZE;
    uint32_t end_addr = addr + size;

    /* Align address to cache line boundary */
    addr &= ~(line_size - 1);

    while (addr < end_addr) {
        CM7_DCCIMVAC = addr;
        addr += line_size;
    }
    __DSB();
    __ISB();
}
#endif /* __DCACHE_PRESENT */

/* ============================================================================
 * TCM Control Functions
 * TCM 控制函数
 * ============================================================================ */

#if (__ITCM_PRESENT == 1)
/**
 * @brief Enable Instruction TCM
 * 使能指令 TCM
 */
void cm7_itcm_enable(void)
{
    CM7_ITCMCR |= CM7_TCMCR_EN_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Disable Instruction TCM
 * 禁用指令 TCM
 */
void cm7_itcm_disable(void)
{
    CM7_ITCMCR &= ~CM7_TCMCR_EN_Msk;
    __DSB();
    __ISB();
}
#endif /* __ITCM_PRESENT */

#if (__DTCM_PRESENT == 1)
/**
 * @brief Enable Data TCM
 * 使能数据 TCM
 */
void cm7_dtcm_enable(void)
{
    CM7_DTCMCR |= CM7_TCMCR_EN_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Disable Data TCM
 * 禁用数据 TCM
 */
void cm7_dtcm_disable(void)
{
    CM7_DTCMCR &= ~CM7_TCMCR_EN_Msk;
    __DSB();
    __ISB();
}
#endif /* __DTCM_PRESENT */

/* ============================================================================
 * Power Management Functions
 * 电源管理函数
 * ============================================================================ */

/**
 * @brief Enter Sleep Mode
 * 进入睡眠模式
 */
void cm7_sleep(void)
{
    SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
    __WFI();
}

/**
 * @brief Enter Deep Sleep Mode
 * 进入深度睡眠模式
 */
void cm7_deep_sleep(void)
{
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    __WFI();
}

/**
 * @brief Wait For Interrupt
 * 等待中断
 */
void cm7_wfi(void)
{
    __WFI();
}

/**
 * @brief Wait For Event
 * 等待事件
 */
void cm7_wfe(void)
{
    __WFE();
}

/**
 * @brief Send Event
 * 发送事件
 */
void cm7_sev(void)
{
    __SEV();
}

/* ============================================================================
 * System Information Functions
 * 系统信息函数
 * ============================================================================ */

/**
 * @brief Get CPUID
 * 获取 CPUID
 */
uint32_t cm7_get_cpuid(void)
{
    return SCB->CPUID;
}

/**
 * @brief Get cache type information
 * 获取缓存类型信息
 */
uint32_t cm7_get_cache_type(void)
{
    return CM7_CTR;
}

/**
 * @brief Get cache size ID
 * 获取缓存大小 ID
 */
uint32_t cm7_get_cache_size_id(uint32_t cache_type)
{
    CM7_CSSELR = cache_type;
    __DSB();
    return CM7_CCSIDR;
}
