/*
 * ARM Architecture - ARMv8-M MPU (Memory Protection Unit)
 *
 * ============================================================================
 * File: armv8m_mpu.c
 * Description: ARMv8-M MPU function implementations
 * 描述: ARMv8-M MPU 函数实现
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B10: The Armv8-M Protected Memory System Architecture
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv8m_mpu.h"

/*
 * ============================================================================
 * MPU Initialization and Control
 * MPU 初始化和控制
 * ============================================================================
 */

void mpu_init(void)
{
    /* Disable MPU first */
    mpu_disable();
    
    /* Clear all MPU regions */
    uint32_t num_regions = mpu_get_type();
    for (uint32_t i = 0; i < num_regions; i++) {
        mpu_clear_region(i);
    }
    
    /* Clear MAIR registers */
    MPU_MAIR0 = 0;
    MPU_MAIR1 = 0;
}

void mpu_enable(bool default_map, bool hardfault_nmi)
{
    uint32_t ctrl = 0;
    
    if (default_map) {
        ctrl |= MPU_CTRL_PRIVDEFENA_Msk;
    }
    
    if (hardfault_nmi) {
        ctrl |= MPU_CTRL_HFNMIENA_Msk;
    }
    
    ctrl |= MPU_CTRL_ENABLE_Msk;
    MPU_CTRL = ctrl;
}

void mpu_disable(void)
{
    MPU_CTRL &= ~MPU_CTRL_ENABLE_Msk;
}

uint32_t mpu_get_type(void)
{
    return (MPU_TYPE & MPU_TYPE_DREGION_Msk) >> MPU_TYPE_DREGION_Pos;
}

/*
 * ============================================================================
 * Memory Attribute Configuration
 * 内存属性配置
 * ============================================================================
 */

void mpu_set_mem_attr(uint8_t idx, uint8_t attr)
{
    if (idx < 4) {
        uint32_t shift = idx * 8;
        uint32_t mask = 0xFFUL << shift;
        MPU_MAIR0 = (MPU_MAIR0 & ~mask) | ((uint32_t)attr << shift);
    } else {
        uint32_t shift = (idx - 4) * 8;
        uint32_t mask = 0xFFUL << shift;
        MPU_MAIR1 = (MPU_MAIR1 & ~mask) | ((uint32_t)attr << shift);
    }
}

uint8_t mpu_get_mem_attr(uint8_t idx)
{
    if (idx < 4) {
        uint32_t shift = idx * 8;
        return (uint8_t)((MPU_MAIR0 >> shift) & 0xFF);
    } else {
        uint32_t shift = (idx - 4) * 8;
        return (uint8_t)((MPU_MAIR1 >> shift) & 0xFF);
    }
}

/*
 * ============================================================================
 * MPU Region Configuration
 * MPU 区域配置
 * ============================================================================
 */

void mpu_configure_region(uint32_t rnr, const mpu_region_cfg_t *cfg)
{
    uint32_t rbar = mpu_build_rbar(cfg->base_addr, cfg->shareability, 
                                      cfg->access_perm, cfg->execute_never);
    uint32_t rlar = mpu_build_rlar(cfg->limit_addr, cfg->attr_idx, cfg->enable);
    
    mpu_set_region(rnr, rbar, rlar);
}

void mpu_set_region(uint32_t rnr, uint32_t rbar, uint32_t rlar)
{
    MPU_RNR = rnr;
    MPU_RBAR = rbar;
    MPU_RLAR = rlar;
}

void mpu_clear_region(uint32_t rnr)
{
    MPU_RNR = rnr;
    MPU_RLAR = 0;
}

void mpu_enable_region(uint32_t rnr)
{
    MPU_RNR = rnr;
    MPU_RLAR |= MPU_RLAR_EN_Msk;
}

void mpu_disable_region(uint32_t rnr)
{
    MPU_RNR = rnr;
    MPU_RLAR &= ~MPU_RLAR_EN_Msk;
}

void mpu_load_regions(uint32_t rnr, const ARM_MPU_Region_t *table, uint32_t count)
{
    for (uint32_t i = 0; i < count; i++) {
        mpu_set_region(rnr + i, table[i].RBAR, table[i].RLAR);
    }
}

int32_t mpu_get_region_for_address(uint32_t addr)
{
    uint32_t num_regions = mpu_get_type();
    
    for (uint32_t i = 0; i < num_regions; i++) {
        MPU_RNR = i;
        uint32_t rbar = MPU_RBAR;
        uint32_t rlar = MPU_RLAR;
        
        if (!(rlar & MPU_RLAR_EN_Msk)) {
            continue;
        }
        
        uint32_t base = rbar & MPU_RBAR_BASE_Msk;
        uint32_t limit = rlar & MPU_RLAR_LIMIT_Msk;
        
        if (addr >= base && addr <= limit) {
            return (int32_t)i;
        }
    }
    
    return -1;
}

/*
 * ============================================================================
 * Non-Secure MPU Functions (TrustZone)
 * 非安全 MPU 函数 (TrustZone)
 * ============================================================================
 */

#if (__TZ_PRESENT == 1)

void mpu_enable_ns(uint32_t mpu_control)
{
    MPU_NS_CTRL = mpu_control;
}

void mpu_disable_ns(void)
{
    MPU_NS_CTRL &= ~MPU_CTRL_ENABLE_Msk;
}

void mpu_set_mem_attr_ns(uint8_t idx, uint8_t attr)
{
    if (idx < 4) {
        uint32_t shift = idx * 8;
        uint32_t mask = 0xFFUL << shift;
        MPU_NS_MAIR0 = (MPU_NS_MAIR0 & ~mask) | ((uint32_t)attr << shift);
    } else {
        uint32_t shift = (idx - 4) * 8;
        uint32_t mask = 0xFFUL << shift;
        MPU_NS_MAIR1 = (MPU_NS_MAIR1 & ~mask) | ((uint32_t)attr << shift);
    }
}

void mpu_set_region_ns(uint32_t rnr, uint32_t rbar, uint32_t rlar)
{
    MPU_NS_RNR = rnr;
    MPU_NS_RBAR = rbar;
    MPU_NS_RLAR = rlar;
}

void mpu_clear_region_ns(uint32_t rnr)
{
    MPU_NS_RNR = rnr;
    MPU_NS_RLAR = 0;
}

void mpu_load_regions_ns(uint32_t rnr, const ARM_MPU_Region_t *table, uint32_t count)
{
    for (uint32_t i = 0; i < count; i++) {
        mpu_set_region_ns(rnr + i, table[i].RBAR, table[i].RLAR);
    }
}

#endif /* __TZ_PRESENT */
