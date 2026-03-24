/*
 * ARM Architecture - ARMv7-M MPU (Memory Protection Unit)
 *
 * ============================================================================
 * File: armv7-m_mpu.c
 * Description: ARMv7-M MPU function implementations
 * 描述: ARMv7-M MPU 函数实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter A2: Application Level Programmers' Model
 *     * A2.3.4 Privileged execution (page A2-32)
 *       - MPU controls access rights for privileged vs unprivileged execution
 *       - Thread mode privilege controlled by nPRIV bit
 *   - Chapter A3: Arm Architecture Memory Model
 *     * A3.1 Address space (page A3-64)
 *       - 32-bit flat address space (0 to 2^32-1)
 *     * A3.2 Alignment support (page A3-65)
 *       - MPU regions must be aligned to region size
 *       - Region size must be power of 2, minimum 32 bytes
 *     * A3.5 Memory types and attributes (page A3-78)
 *       - Normal, Device, Strongly-ordered memory types
 *       - Shareability and cacheability attributes
 *       - TEX, C, B, S bits for memory attributes
 *     * A3.6 Access rights (page A3-87)
 *       - Memory access permissions (AP bits)
 *       - Privileged vs unprivileged access control
 *     * A3.7 Memory access order (page A3-89)
 *       - DSB and ISB required after MPU configuration changes
 *   - Chapter B3.5: Protected Memory System Architecture, PMSAv7
 *   - Table B3-11 MPU register summary (page B3-635)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_mpu.h"

/*
 * ============================================================================
 * MPU Initialization and Control
 * MPU 初始化和控制
 * Reference: Chapter B3.5 - Protected Memory System Architecture, PMSAv7
 * ============================================================================
 */

/**
 * @brief Enable MPU
 *
 * Reference: Chapter A3.7 Memory access order (page A3-89)
 *   - DSB and ISB required after enabling MPU
 *   - Ensures subsequent memory accesses use new MPU settings
 * Reference: Chapter A2.3.4 Privileged execution (page A2-32)
 *   - MPU controls access rights for privileged vs unprivileged execution
 * Reference: Arm(R) v7-M ARM Chapter B3.5 (Protected Memory System Architecture) - MPU_CTRL register
 */
void mpu_enable(void)
{
    MPU_CTRL |= MPU_CTRL_ENABLE_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Disable MPU
 *
 * Reference: Chapter A3.7 Memory access order (page A3-89)
 *   - DSB and ISB required after disabling MPU
 *   - Ensures all pending memory accesses complete
 * Reference: Chapter A2.3.4 Privileged execution (page A2-32)
 *   - When disabled, all accesses use default memory map permissions
 * Reference: Arm(R) v7-M ARM Chapter B3.5 (Protected Memory System Architecture) - MPU_CTRL register
 */
void mpu_disable(void)
{
    MPU_CTRL &= ~MPU_CTRL_ENABLE_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Check if MPU is enabled
 * @return true if enabled, false otherwise
 * Reference: Arm(R) v7-M ARM Chapter B3.5 (Protected Memory System Architecture) - MPU_CTRL register
 */
bool mpu_is_enabled(void)
{
    return (MPU_CTRL & MPU_CTRL_ENABLE_Msk) ? true : false;
}

/**
 * @brief Get number of MPU regions
 * @return Number of regions
 * Reference: Arm(R) v7-M ARM Chapter B3.5 (Protected Memory System Architecture) - MPU_TYPE register
 */
uint32_t mpu_get_num_regions(void)
{
    return (MPU_TYPE & MPU_TYPE_DREGION_Msk) >> MPU_TYPE_DREGION_Pos;
}

/*
 * ============================================================================
 * MPU Region Configuration
 * MPU 区域配置
 * Reference: Chapter B3.5 - Protected Memory System Architecture, PMSAv7
 * ============================================================================
 */

/**
 * @brief Configure MPU region
 * @param region Region number (0 to MPU_DREGION-1)
 * @param base_addr Region base address (must be aligned to region size)
 * @param size Region size (MPU_REGION_SIZE_*)
 * @param attributes Region attributes (combination of MPU_ATTR_*)
 * @param srd Subregion disable mask (0-255)
 * @return 0 on success, -1 on error
 * Reference: Arm(R) v7-M ARM Chapter B3.5 (Protected Memory System Architecture) - MPU_RBAR, MPU_RASR registers
 */
int32_t mpu_configure_region(uint32_t region, uint32_t base_addr, uint32_t size, uint32_t attributes, uint8_t srd)
{
    if (region >= mpu_get_num_regions()) {
        return -1;
    }
    
    if (size < MPU_REGION_SIZE_32B || size > MPU_REGION_SIZE_4GB) {
        return -1;
    }
    
    /* Check address alignment */
    uint32_t region_size_bytes = 1UL << (size + 1);
    if ((base_addr & (region_size_bytes - 1)) != 0) {
        return -1;
    }
    
    MPU_RNR = region;
    
    /* Set base address with VALID bit and region number */
    uint32_t rbar = (base_addr & MPU_RBAR_ADDR_Msk) | MPU_RBAR_VALID_Msk | (region & MPU_RBAR_REGION_Msk);
    MPU_RBAR = rbar;
    
    /* Set attributes, size, subregion disable, and enable */
    uint32_t rasr = attributes | ((uint32_t)srd << MPU_RASR_SRD_Pos) | 
                    ((size << MPU_RASR_SIZE_Pos) & MPU_RASR_SIZE_Msk) | MPU_RASR_ENABLE_Msk;
    MPU_RASR = rasr;
    
    return 0;
}

/**
 * @brief Enable MPU region
 * @param region Region number
 * Reference: Arm(R) v7-M ARM Chapter B3.5 (Protected Memory System Architecture) - MPU_RASR register
 */
void mpu_enable_region(uint32_t region)
{
    if (region < mpu_get_num_regions()) {
        MPU_RNR = region;
        MPU_RASR |= MPU_RASR_ENABLE_Msk;
    }
}

/**
 * @brief Disable MPU region
 * @param region Region number
 * Reference: Arm(R) v7-M ARM Chapter B3.5 (Protected Memory System Architecture) - MPU_RASR register
 */
void mpu_disable_region(uint32_t region)
{
    if (region < mpu_get_num_regions()) {
        MPU_RNR = region;
        MPU_RASR &= ~MPU_RASR_ENABLE_Msk;
    }
}

/**
 * @brief Set MPU region base address
 * @param region Region number
 * @param addr Base address
 * Reference: Arm(R) v7-M ARM Chapter B3.5 (Protected Memory System Architecture) - MPU_RBAR register
 */
void mpu_set_region_base(uint32_t region, uint32_t addr)
{
    if (region < mpu_get_num_regions()) {
        MPU_RNR = region;
        uint32_t rbar = (addr & MPU_RBAR_ADDR_Msk) | MPU_RBAR_VALID_Msk | (region & MPU_RBAR_REGION_Msk);
        MPU_RBAR = rbar;
    }
}

/**
 * @brief Set MPU region attributes
 * @param region Region number
 * @param size Region size
 * @param attributes Region attributes
 * @param srd Subregion disable mask
 * Reference: Arm(R) v7-M ARM Chapter B3.5 (Protected Memory System Architecture) - MPU_RASR register
 */
void mpu_set_region_attr(uint32_t region, uint32_t size, uint32_t attributes, uint8_t srd)
{
    if (region < mpu_get_num_regions()) {
        MPU_RNR = region;
        uint32_t rasr = MPU_RASR & MPU_RASR_ENABLE_Msk; /* Keep enable bit */
        rasr |= attributes | ((uint32_t)srd << MPU_RASR_SRD_Pos) | 
                ((size << MPU_RASR_SIZE_Pos) & MPU_RASR_SIZE_Msk);
        MPU_RASR = rasr;
    }
}

/**
 * @brief Set default memory map for privileged access
 * @param enable true to enable, false to disable
 * Reference: Arm(R) v7-M ARM Chapter B3.5 (Protected Memory System Architecture) - MPU_CTRL.PRIVDEFENA
 */
void mpu_set_priv_default(bool enable)
{
    if (enable) {
        MPU_CTRL |= MPU_CTRL_PRIVDEFENA_Msk;
    } else {
        MPU_CTRL &= ~MPU_CTRL_PRIVDEFENA_Msk;
    }
}

/**
 * @brief Enable MPU for HardFault and NMI handlers
 * @param enable true to enable, false to disable
 * Reference: Arm(R) v7-M ARM Chapter B3.5 (Protected Memory System Architecture) - MPU_CTRL.HFNMIENA
 */
void mpu_enable_for_hardfault_nmi(bool enable)
{
    if (enable) {
        MPU_CTRL |= MPU_CTRL_HFNMIENA_Msk;
    } else {
        MPU_CTRL &= ~MPU_CTRL_HFNMIENA_Msk;
    }
}

/**
 * @brief Calculate region size encoding from actual size in bytes
 * @param size Size in bytes
 * @return Size encoding for MPU_RASR, or 0 if invalid
 * Reference: Arm(R) v7-M ARM Chapter B3.5 (Protected Memory System Architecture) - MPU_RASR.SIZE
 */
uint32_t mpu_calc_size(uint32_t size)
{
    if (size < 32 || size > 0x80000000) {
        return 0;
    }
    
    uint32_t size_encoding = 4;
    while ((1UL << (size_encoding + 1)) < size) {
        size_encoding++;
    }
    
    return size_encoding;
}

/**
 * @brief Check if address is aligned to size
 * @param addr Address to check
 * @param size Size in bytes
 * @return true if aligned, false otherwise
 */
bool mpu_is_addr_aligned(uint32_t addr, uint32_t size)
{
    return (addr & (size - 1)) == 0;
}

/**
 * @brief Get MPU region base address
 * @param region Region number
 * @return Base address
 * Reference: Arm(R) v7-M ARM Chapter B3.5 (Protected Memory System Architecture) - MPU_RBAR register
 */
uint32_t mpu_get_region_base(uint32_t region)
{
    if (region < mpu_get_num_regions()) {
        MPU_RNR = region;
        return MPU_RBAR & MPU_RBAR_ADDR_Msk;
    }
    return 0;
}

/**
 * @brief Get MPU region attributes
 * @param region Region number
 * @return Region attributes
 * Reference: Arm(R) v7-M ARM Chapter B3.5 (Protected Memory System Architecture) - MPU_RASR register
 */
uint32_t mpu_get_region_attr(uint32_t region)
{
    if (region < mpu_get_num_regions()) {
        MPU_RNR = region;
        return MPU_RASR;
    }
    return 0;
}

/**
 * @brief Check if MPU region is enabled
 * @param region Region number
 * @return true if enabled, false otherwise
 * Reference: Arm(R) v7-M ARM Chapter B3.5 (Protected Memory System Architecture) - MPU_RASR register
 */
bool mpu_is_region_enabled(uint32_t region)
{
    if (region < mpu_get_num_regions()) {
        MPU_RNR = region;
        return (MPU_RASR & MPU_RASR_ENABLE_Msk) ? true : false;
    }
    return false;
}

/**
 * @brief Configure MPU region with detailed attributes
 * @param region Region number
 * @param base_addr Region base address
 * @param size Region size encoding
 * @param ap Access permission
 * @param tex Type extension
 * @param s Shareable
 * @param c Cacheable
 * @param b Bufferable
 * @param xn Execute never
 * @param srd Subregion disable
 * @return 0 on success, -1 on error
 * Reference: Arm(R) v7-M ARM Chapter B3.5 (Protected Memory System Architecture) - MPU_RASR register
 */
int32_t mpu_configure_region_ex(uint32_t region, uint32_t base_addr, uint32_t size,
                                uint32_t ap, uint32_t tex, uint32_t s, uint32_t c, 
                                uint32_t b, uint32_t xn, uint8_t srd)
{
    if (region >= mpu_get_num_regions()) {
        return -1;
    }
    
    uint32_t attributes = ((xn << MPU_RASR_XN_Pos) & MPU_RASR_XN_Msk) |
                          ((ap << MPU_RASR_AP_Pos) & MPU_RASR_AP_Msk) |
                          ((tex << MPU_RASR_TEX_Pos) & MPU_RASR_TEX_Msk) |
                          ((s << MPU_RASR_S_Pos) & MPU_RASR_S_Msk) |
                          ((c << MPU_RASR_C_Pos) & MPU_RASR_C_Msk) |
                          ((b << MPU_RASR_B_Pos) & MPU_RASR_B_Msk);
    
    return mpu_configure_region(region, base_addr, size, attributes, srd);
}
