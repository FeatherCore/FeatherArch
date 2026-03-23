/*
 * ARM Architecture - ARMv7-M MPU (Memory Protection Unit)
 *
 * ============================================================================
 * File: armv7-m_mpu.c
 * Description: ARMv7-M MPU function implementations
 * 描述: ARMv7-M MPU 函数实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual
 *   - Chapter B3.5: Protected Memory System Architecture, PMSAv7
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_mpu.h"

/*
 * ============================================================================
 * MPU Initialization and Control
 * MPU 初始化和控制
 * ============================================================================
 */

void mpu_enable(uint8_t privdefena, uint8_t hfnmiena)
{
    uint32_t ctrl = 0;
    
    if (privdefena) {
        ctrl |= MPU_CTRL_PRIVDEFENA;
    }
    
    if (hfnmiena) {
        ctrl |= MPU_CTRL_HFNMIENA;
    }
    
    ctrl |= MPU_CTRL_ENABLE;
    MPU_CTRL = ctrl;
}

void mpu_disable(void)
{
    MPU_CTRL &= ~MPU_CTRL_ENABLE;
}

uint32_t mpu_get_num_regions(void)
{
    return (MPU_TYPE & MPU_TYPE_DREGION_Msk) >> MPU_TYPE_DREGION_Pos;
}

/*
 * ============================================================================
 * MPU Region Configuration
 * MPU 区域配置
 * ============================================================================
 */

void mpu_configure_region(uint8_t region, uint32_t addr, uint8_t size,
                      uint8_t ap, uint8_t tex, uint8_t s,
                      uint8_t c, uint8_t b, uint8_t xn)
{
    uint32_t rbar;
    uint32_t rasr;
    
    MPU_RNR = region;
    
    rbar = addr & MPU_RBAR_ADDR_Msk;
    rbar |= MPU_RBAR_VALID;
    rbar |= region;
    MPU_RBAR = rbar;
    
    rasr = ((uint32_t)size << MPU_RASR_SIZE_Pos);
    rasr |= ((uint32_t)ap << MPU_RASR_AP_Pos);
    rasr |= ((uint32_t)tex << MPU_RASR_TEX_Pos);
    rasr |= ((uint32_t)s << MPU_RASR_S_Pos);
    rasr |= ((uint32_t)c << MPU_RASR_C_Pos);
    rasr |= ((uint32_t)b << MPU_RASR_B_Pos);
    if (xn) {
        rasr |= MPU_RASR_XN;
    }
    rasr |= MPU_RASR_ENABLE;
    MPU_RASR = rasr;
}

void mpu_enable_region(uint8_t region)
{
    MPU_RNR = region;
    MPU_RASR |= MPU_RASR_ENABLE;
}

void mpu_disable_region(uint8_t region)
{
    MPU_RNR = region;
    MPU_RASR &= ~MPU_RASR_ENABLE;
}
