/*
 * ARM Architecture - Cortex-M4 MPU (Memory Protection Unit)
 *
 * ============================================================================
 * File: cm4_mpu.h
 * Description: Cortex-M4 MPU register definitions (wrapper for armv7-m_mpu.h)
 * 描述: Cortex-M4 MPU 寄存器定义（armv7-m_mpu.h 的包装层）
 *
 * This file provides CM4-specific naming conventions while delegating
 * all actual definitions and implementations to armv7-m_mpu.h.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.5 Optional Memory Protection Unit (page 4-37)
 *   - Table 4-38 MPU registers summary (page 4-38)
 *
 * Implementation: All functionality is provided by armv7-m/armv7-m_mpu.h
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_MPU_H__
#define __CM4_MPU_H__

#include <stdint.h>
#include <stdbool.h>

/* Include the underlying ARMv7-M implementation */
#include "armv7-m/armv7-m_mpu.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * MPU Base Address Alias
 * MPU 基地址别名
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-38 (page 4-38)
 * ============================================================================
 */

#define CM4_MPU_BASE_ADDR             MPU_BASE_ADDR

/*
 * ============================================================================
 * Register Aliases - Map CM4 naming to ARMv7-M naming
 * 寄存器别名 - 将 CM4 命名映射到 ARMv7-M 命名
 * ============================================================================
 */

/* MPU Type Register (MPU_TYPE) */
#define MPU_TYPE                      MPU_TYPE

/* MPU Control Register (MPU_CTRL) */
#define MPU_CTRL                      MPU_CTRL

/* MPU Region Number Register (MPU_RNR) */
#define MPU_RNR                       MPU_RNR

/* MPU Region Base Address Register (MPU_RBAR) */
#define MPU_RBAR                      MPU_RBAR

/* MPU Region Attribute and Size Register (MPU_RASR) */
#define MPU_RASR                      MPU_RASR

/* MPU Region Alias Registers */
#define MPU_RBAR_A1                   MPU_RBAR_A1
#define MPU_RASR_A1                   MPU_RASR_A1
#define MPU_RBAR_A2                   MPU_RBAR_A2
#define MPU_RASR_A2                   MPU_RASR_A2
#define MPU_RBAR_A3                   MPU_RBAR_A3
#define MPU_RASR_A3                   MPU_RASR_A3

/*
 * ============================================================================
 * MPU Register Bit Definitions (Aliases)
 * MPU 寄存器位定义（别名）
 * ============================================================================
 */

/* MPU_TYPE Register Bits */
#define MPU_TYPE_IREGION_Pos          MPU_TYPE_IREGION_Pos
#define MPU_TYPE_IREGION_Msk          MPU_TYPE_IREGION_Msk
#define MPU_TYPE_DREGION_Pos          MPU_TYPE_DREGION_Pos
#define MPU_TYPE_DREGION_Msk          MPU_TYPE_DREGION_Msk
#define MPU_TYPE_SEPARATE_Pos         MPU_TYPE_SEPARATE_Pos
#define MPU_TYPE_SEPARATE_Msk         MPU_TYPE_SEPARATE_Msk

/* MPU_CTRL Register Bits */
#define MPU_CTRL_ENABLE_Pos           MPU_CTRL_ENABLE_Pos
#define MPU_CTRL_ENABLE_Msk           MPU_CTRL_ENABLE_Msk
#define MPU_CTRL_HFNMIENA_Pos         MPU_CTRL_HFNMIENA_Pos
#define MPU_CTRL_HFNMIENA_Msk         MPU_CTRL_HFNMIENA_Msk
#define MPU_CTRL_PRIVDEFENA_Pos       MPU_CTRL_PRIVDEFENA_Pos
#define MPU_CTRL_PRIVDEFENA_Msk       MPU_CTRL_PRIVDEFENA_Msk

/* MPU_RNR Register Bits */
#define MPU_RNR_REGION_Pos            MPU_RNR_REGION_Pos
#define MPU_RNR_REGION_Msk            MPU_RNR_REGION_Msk

/* MPU_RBAR Register Bits */
#define MPU_RBAR_REGION_Pos           MPU_RBAR_REGION_Pos
#define MPU_RBAR_REGION_Msk           MPU_RBAR_REGION_Msk
#define MPU_RBAR_VALID_Pos            MPU_RBAR_VALID_Pos
#define MPU_RBAR_VALID_Msk            MPU_RBAR_VALID_Msk
#define MPU_RBAR_ADDR_Pos             MPU_RBAR_ADDR_Pos
#define MPU_RBAR_ADDR_Msk             MPU_RBAR_ADDR_Msk

/* MPU_RASR Register Bits */
#define MPU_RASR_ENABLE_Pos           MPU_RASR_ENABLE_Pos
#define MPU_RASR_ENABLE_Msk           MPU_RASR_ENABLE_Msk
#define MPU_RASR_SIZE_Pos             MPU_RASR_SIZE_Pos
#define MPU_RASR_SIZE_Msk             MPU_RASR_SIZE_Msk
#define MPU_RASR_SRD_Pos              MPU_RASR_SRD_Pos
#define MPU_RASR_SRD_Msk              MPU_RASR_SRD_Msk
#define MPU_RASR_ATTRS_Pos            MPU_RASR_ATTRS_Pos
#define MPU_RASR_ATTRS_Msk            MPU_RASR_ATTRS_Msk
#define MPU_RASR_B_Pos                MPU_RASR_B_Pos
#define MPU_RASR_B_Msk                MPU_RASR_B_Msk
#define MPU_RASR_C_Pos                MPU_RASR_C_Pos
#define MPU_RASR_C_Msk                MPU_RASR_C_Msk
#define MPU_RASR_S_Pos                MPU_RASR_S_Pos
#define MPU_RASR_S_Msk                MPU_RASR_S_Msk
#define MPU_RASR_TEX_Pos              MPU_RASR_TEX_Pos
#define MPU_RASR_TEX_Msk              MPU_RASR_TEX_Msk
#define MPU_RASR_AP_Pos               MPU_RASR_AP_Pos
#define MPU_RASR_AP_Msk               MPU_RASR_AP_Msk
#define MPU_RASR_XN_Pos               MPU_RASR_XN_Pos
#define MPU_RASR_XN_Msk               MPU_RASR_XN_Msk

/*
 * ============================================================================
 * MPU Region Size Definitions (Aliases)
 * MPU 区域大小定义（别名）
 * ============================================================================
 */

#define MPU_SIZE_32B                  MPU_REGION_SIZE_32B
#define MPU_SIZE_64B                  MPU_REGION_SIZE_64B
#define MPU_SIZE_128B                 MPU_REGION_SIZE_128B
#define MPU_SIZE_256B                 MPU_REGION_SIZE_256B
#define MPU_SIZE_512B                 MPU_REGION_SIZE_512B
#define MPU_SIZE_1KB                  MPU_REGION_SIZE_1KB
#define MPU_SIZE_2KB                  MPU_REGION_SIZE_2KB
#define MPU_SIZE_4KB                  MPU_REGION_SIZE_4KB
#define MPU_SIZE_8KB                  MPU_REGION_SIZE_8KB
#define MPU_SIZE_16KB                 MPU_REGION_SIZE_16KB
#define MPU_SIZE_32KB                 MPU_REGION_SIZE_32KB
#define MPU_SIZE_64KB                 MPU_REGION_SIZE_64KB
#define MPU_SIZE_128KB                MPU_REGION_SIZE_128KB
#define MPU_SIZE_256KB                MPU_REGION_SIZE_256KB
#define MPU_SIZE_512KB                MPU_REGION_SIZE_512KB
#define MPU_SIZE_1MB                  MPU_REGION_SIZE_1MB
#define MPU_SIZE_2MB                  MPU_REGION_SIZE_2MB
#define MPU_SIZE_4MB                  MPU_REGION_SIZE_4MB
#define MPU_SIZE_8MB                  MPU_REGION_SIZE_8MB
#define MPU_SIZE_16MB                 MPU_REGION_SIZE_16MB
#define MPU_SIZE_32MB                 MPU_REGION_SIZE_32MB
#define MPU_SIZE_64MB                 MPU_REGION_SIZE_64MB
#define MPU_SIZE_128MB                MPU_REGION_SIZE_128MB
#define MPU_SIZE_256MB                MPU_REGION_SIZE_256MB
#define MPU_SIZE_512MB                MPU_REGION_SIZE_512MB
#define MPU_SIZE_1GB                  MPU_REGION_SIZE_1GB
#define MPU_SIZE_2GB                  MPU_REGION_SIZE_2GB
#define MPU_SIZE_4GB                  MPU_REGION_SIZE_4GB

/*
 * ============================================================================
 * MPU Access Permission Definitions (Aliases)
 * MPU 访问权限定义（别名）
 * ============================================================================
 */

#define MPU_AP_NO_ACCESS              MPU_AP_NO_ACCESS
#define MPU_AP_PRIV_RW                MPU_AP_PRIV_RW
#define MPU_AP_PRIV_RW_USER_RO        MPU_AP_PRIV_RW_USER_RO
#define MPU_AP_PRIV_RW_USER_RW        MPU_AP_PRIV_RW_USER_RW
#define MPU_AP_RESERVED               MPU_AP_RESERVED
#define MPU_AP_PRIV_RO                MPU_AP_PRIV_RO
#define MPU_AP_PRIV_RO_USER_RO        MPU_AP_PRIV_RO_USER_RO
#define MPU_AP_RO                     MPU_AP_RO

/*
 * ============================================================================
 * MPU Memory Attributes (Aliases)
 * MPU 内存属性（别名）
 * ============================================================================
 */

/* Strongly-ordered */
#define MPU_ATTR_STRONGLY_ORDERED     MPU_ATTR_STRONGLY_ORDERED

/* Device memory */
#define MPU_ATTR_DEVICE_SHARED        MPU_ATTR_DEVICE_SHARED
#define MPU_ATTR_DEVICE_NONSHARED     MPU_ATTR_DEVICE_NONSHARED

/* Normal memory, Non-cacheable */
#define MPU_ATTR_NORMAL_NONCACHE      MPU_ATTR_NORMAL_NONCACHE

/* Normal memory, Write-Through */
#define MPU_ATTR_NORMAL_WT            MPU_ATTR_NORMAL_WT

/* Normal memory, Write-Back */
#define MPU_ATTR_NORMAL_WB            MPU_ATTR_NORMAL_WB

/* Normal memory, Write-Back with allocate */
#define MPU_ATTR_NORMAL_WB_ALLOC      MPU_ATTR_NORMAL_WB_ALLOC

/* Shareable attribute */
#define MPU_ATTR_SHAREABLE            MPU_ATTR_SHAREABLE
#define MPU_ATTR_NON_SHAREABLE        MPU_ATTR_NON_SHAREABLE

/* Execute Never attribute */
#define MPU_ATTR_XN                   MPU_ATTR_XN
#define MPU_ATTR_EXEC_OK              MPU_ATTR_EXEC_OK

/*
 * ============================================================================
 * MPU Function Wrapper Declarations
 * MPU 函数包装器声明
 * Implementation: Delegates to functions in armv7-m_mpu.c
 * ============================================================================
 */

/**
 * @brief Enable MPU
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.2 (page 4-39)
 * Implementation: Delegates to mpu_enable() in armv7-m_mpu.c
 */
static inline void cm4_mpu_enable(void)
{
    mpu_enable();
}

/**
 * @brief Disable MPU
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.2 (page 4-39)
 * Implementation: Delegates to mpu_disable() in armv7-m_mpu.c
 */
static inline void cm4_mpu_disable(void)
{
    mpu_disable();
}

/**
 * @brief Enable MPU with default memory map for privileged access
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.2 (page 4-39)
 * Implementation: Delegates to mpu_enable_with_default_map() in armv7-m_mpu.c
 */
static inline void cm4_mpu_enable_with_default_map(void)
{
    mpu_enable_with_default_map();
}

/**
 * @brief Select MPU region
 * @param region Region number (0-7)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.3 (page 4-40)
 * Implementation: Delegates to mpu_select_region() in armv7-m_mpu.c
 */
static inline void cm4_mpu_select_region(uint32_t region)
{
    mpu_select_region(region);
}

/**
 * @brief Set region base address
 * @param addr Base address (must be aligned to region size)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.4 (page 4-40)
 * Implementation: Delegates to mpu_set_region_base() in armv7-m_mpu.c
 */
static inline void cm4_mpu_set_region_base(uint32_t addr)
{
    mpu_set_region_base(addr);
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
 * Implementation: Delegates to mpu_set_region_attr() in armv7-m_mpu.c
 */
static inline void cm4_mpu_set_region_attr(uint32_t size, uint32_t srd, uint32_t attr, uint32_t ap, uint32_t xn, uint32_t enable)
{
    mpu_set_region_attr(size, srd, attr, ap, xn, enable);
}

/**
 * @brief Configure a complete MPU region
 * @param region Region number (0-7)
 * @param base Base address
 * @param size Region size
 * @param attr Memory attributes
 * @param srd Subregion disable bits
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5 (page 4-37)
 * Implementation: Delegates to mpu_configure_region() in armv7-m_mpu.c
 */
static inline void cm4_mpu_configure_region(uint32_t region, uint32_t base, uint32_t size, uint32_t attr, uint32_t srd)
{
    mpu_configure_region(region, base, size, attr, srd);
}

/**
 * @brief Disable a region
 * @param region Region number (0-7)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.5 (page 4-41)
 * Implementation: Delegates to mpu_disable_region() in armv7-m_mpu.c
 */
static inline void cm4_mpu_disable_region(uint32_t region)
{
    mpu_disable_region(region);
}

/**
 * @brief Get number of supported regions
 * @return Number of regions (should be 8 for Cortex-M4)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.1 (page 4-38)
 * Implementation: Delegates to mpu_get_num_regions() in armv7-m_mpu.c
 */
static inline uint32_t cm4_mpu_get_region_count(void)
{
    return mpu_get_num_regions();
}

/**
 * @brief Check if MPU is present
 * @return 1 if present, 0 if not
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.1 (page 4-38)
 * Implementation: Delegates to mpu_is_present() in armv7-m_mpu.c
 */
static inline int cm4_mpu_is_present(void)
{
    return mpu_is_present();
}

#ifdef __cplusplus
}
#endif

#endif /* __CM4_MPU_H__ */
