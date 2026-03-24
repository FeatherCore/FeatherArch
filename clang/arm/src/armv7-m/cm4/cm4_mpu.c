/*
 * ARM Architecture - Cortex-M4 MPU Implementation
 *
 * ============================================================================
 * File: cm4_mpu.c
 * Description: Cortex-M4 MPU function implementations
 * 描述: Cortex-M4 MPU 函数实现
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.5 Optional Memory Protection Unit (page 4-37)
 *   - Table 4-38 MPU registers summary (page 4-38)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include "armv7-m/cm4/cm4_mpu.h"

/**
 * @brief Enable MPU
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.2 (page 4-39)
 */
void cm4_mpu_enable(void)
{
    MPU_CTRL |= MPU_CTRL_ENABLE_Msk;
}

/**
 * @brief Disable MPU
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.2 (page 4-39)
 */
void cm4_mpu_disable(void)
{
    MPU_CTRL &= ~MPU_CTRL_ENABLE_Msk;
}

/**
 * @brief Enable MPU with default memory map for privileged access
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.2 (page 4-39)
 */
void cm4_mpu_enable_with_default_map(void)
{
    MPU_CTRL |= MPU_CTRL_ENABLE_Msk | MPU_CTRL_PRIVDEFENA_Msk;
}

/**
 * @brief Select MPU region
 * @param region Region number (0-7)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.3 (page 4-40)
 */
void cm4_mpu_select_region(uint32_t region)
{
    MPU_RNR = region & MPU_RNR_REGION_Msk;
}

/**
 * @brief Set region base address
 * @param addr Base address (must be aligned to region size)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.4 (page 4-40)
 */
void cm4_mpu_set_region_base(uint32_t addr)
{
    MPU_RBAR = addr & MPU_RBAR_ADDR_Msk;
}

/**
 * @brief Set region size and attributes
 * @param size Region size (MPU_SIZE_* values)
 * @param srd Subregion disable bits (8 bits)
 * @param attr Memory attributes
 * @param ap Access permissions
 * @param xn Execute never bit
 * @param enable Enable region
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.5 (page 4-41)
 */
void cm4_mpu_set_region_attr(uint32_t size, uint32_t srd, uint32_t attr, uint32_t ap, uint32_t xn, uint32_t enable)
{
    uint32_t rasr = (size << MPU_RASR_SIZE_Pos) |
                    ((srd & 0xFF) << MPU_RASR_SRD_Pos) |
                    ((attr & 0x7) << MPU_RASR_TEX_Pos) |
                    ((ap & 0x7) << MPU_RASR_AP_Pos) |
                    ((xn & 1) << MPU_RASR_XN_Pos) |
                    (enable & 1);
    MPU_RASR = rasr;
}

/**
 * @brief Configure a complete MPU region
 * @param region Region number (0-7)
 * @param base Base address
 * @param size Region size
 * @param srd Subregion disable bits
 * @param attr Memory attributes
 * @param ap Access permissions
 * @param xn Execute never
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5 (page 4-37)
 */
void cm4_mpu_configure_region(uint32_t region, uint32_t base, uint32_t size, uint32_t srd, uint32_t attr, uint32_t ap, uint32_t xn)
{
    cm4_mpu_select_region(region);
    cm4_mpu_set_region_base(base);
    cm4_mpu_set_region_attr(size, srd, attr, ap, xn, 1);
}

/**
 * @brief Disable a region
 * @param region Region number (0-7)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.5 (page 4-41)
 */
void cm4_mpu_disable_region(uint32_t region)
{
    cm4_mpu_select_region(region);
    MPU_RASR &= ~MPU_RASR_ENABLE_Msk;
}

/**
 * @brief Get number of supported regions
 * @return Number of regions (should be 8 for Cortex-M4)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.1 (page 4-38)
 */
uint32_t cm4_mpu_get_region_count(void)
{
    return (MPU_TYPE & MPU_TYPE_DREGION_Msk) >> MPU_TYPE_DREGION_Pos;
}

/**
 * @brief Check if MPU is present
 * @return 1 if present, 0 if not
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.1 (page 4-38)
 */
int cm4_mpu_is_present(void)
{
    return (MPU_TYPE & MPU_TYPE_DREGION_Msk) ? 1 : 0;
}
