/*
 * ARM Architecture - ARMv7-M MPU (Memory Protection Unit)
 *
 * ============================================================================
 * File: armv7-m_mpu.h
 * Description: ARMv7-M MPU register definitions and function declarations
 * 描述: ARMv7-M MPU 寄存器定义和函数声明
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter A2: Application Level Programmers' Model
 *     * A2.3.4 Privileged execution (page A2-32)
 *       - MPU controls access rights for privileged vs unprivileged execution
 *   - Chapter A3: Arm Architecture Memory Model
 *     * A3.1 Address space (page A3-64)
 *       - 32-bit flat address space (0 to 2^32-1)
 *     * A3.2 Alignment support (page A3-65)
 *       - MPU regions must be aligned to region size
 *     * A3.5 Memory types and attributes (page A3-78)
 *       - Normal, Device, Strongly-ordered memory types
 *       - Shareability and cacheability attributes
 *     * A3.6 Access rights (page A3-87)
 *       - Memory access permissions (AP bits)
 *   - Chapter B1: System Level Programmers' Model
 *     * B1.3.1 Modes, privilege and stacks (page B1-512)
 *       - MPU controls access rights for privileged vs unprivileged execution
 *     * B1.5.6 Fault behavior (page B1-531)
 *       - MPU faults generate MemManage exceptions
 *   - Chapter B3: System Address Map
 *     * B3.5 Protected Memory System Architecture, PMSAv7 (page B3-632)
 *       - B3.5.1 PMSAv7 architecture (page B3-632)
 *       - B3.5.2 Memory region attributes (page B3-633)
 *       - Table B3-11 MPU register summary (page B3-635)
 *       - B3.5.3 MPU register descriptions (page B3-635)
 *         * MPU_TYPE - MPU Type Register
 *         * MPU_CTRL - MPU Control Register
 *         * MPU_RNR - MPU Region Number Register
 *         * MPU_RBAR - MPU Region Base Address Register
 *         * MPU_RASR - MPU Region Attribute and Size Register
 *       - B3.5.4 Memory region programming (page B3-641)
 *       - B3.5.5 Updates to the MPU region structure (page B3-643)
 *       - B3.5.6 MPU access permission attributes (page B3-644)
 *         * Table B3-12 AP encoding and access permissions
 *       - B3.5.7 MPU matching against the system address map (page B3-645)
 *       - B3.5.8 MPU faults (page B3-645)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_MPU_H__
#define __ARCH_ARM_V7M_MPU_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv7-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * MPU Base Address
 * MPU 基地址
 * Reference: Table B3-3 SCS address space regions (page B3-595)
 * ============================================================================
 */

#define MPU_BASE_ADDR             0xE000ED90UL

/*
 * ============================================================================
 * MPU Register Definitions
 * MPU 寄存器定义
 * Reference: Table B3-11 MPU register summary (page B3-635)
 * ============================================================================
 */

/**
 * MPU Type Register (MPU_TYPE)
 * Address: 0xE000ED90
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-635
 */
#define MPU_TYPE                  (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x00))

/**
 * MPU Control Register (MPU_CTRL)
 * Address: 0xE000ED94
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-636
 */
#define MPU_CTRL                  (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x04))

/**
 * MPU Region Number Register (MPU_RNR)
 * Address: 0xE000ED98
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-638
 */
#define MPU_RNR                   (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x08))

/**
 * MPU Region Base Address Register (MPU_RBAR)
 * Address: 0xE000ED9C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-638
 */
#define MPU_RBAR                  (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x0C))

/**
 * MPU Region Attribute and Size Register (MPU_RASR)
 * Address: 0xE000EDA0
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-639
 */
#define MPU_RASR                  (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x10))

/**
 * MPU Region Base Address Register Alias 1 (MPU_RBAR_A1)
 * Address: 0xE000EDA4
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-638
 */
#define MPU_RBAR_A1               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x14))

/**
 * MPU Region Attribute and Size Register Alias 1 (MPU_RASR_A1)
 * Address: 0xE000EDA8
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-639
 */
#define MPU_RASR_A1               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x18))

/**
 * MPU Region Base Address Register Alias 2 (MPU_RBAR_A2)
 * Address: 0xE000EDAC
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-638
 */
#define MPU_RBAR_A2               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x1C))

/**
 * MPU Region Attribute and Size Register Alias 2 (MPU_RASR_A2)
 * Address: 0xE000EDB0
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-639
 */
#define MPU_RASR_A2               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x20))

/**
 * MPU Region Base Address Register Alias 3 (MPU_RBAR_A3)
 * Address: 0xE000EDB4
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-638
 */
#define MPU_RBAR_A3               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x24))

/**
 * MPU Region Attribute and Size Register Alias 3 (MPU_RASR_A3)
 * Address: 0xE000EDB8
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-639
 */
#define MPU_RASR_A3               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x28))

/*
 * ============================================================================
 * MPU Register Bit Definitions
 * MPU 寄存器位定义
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-635
 * ============================================================================
 */

/**
 * MPU_TYPE Register Bits
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-635
 */
#define MPU_TYPE_IREGION_Pos      16U
#define MPU_TYPE_IREGION_Msk      (0xFFUL << MPU_TYPE_IREGION_Pos)
#define MPU_TYPE_DREGION_Pos      8U
#define MPU_TYPE_DREGION_Msk      (0xFFUL << MPU_TYPE_DREGION_Pos)
#define MPU_TYPE_SEPARATE_Pos     0U
#define MPU_TYPE_SEPARATE_Msk     (1UL << MPU_TYPE_SEPARATE_Pos)

/**
 * MPU_CTRL Register Bits
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-636
 */
#define MPU_CTRL_PRIVDEFENA_Pos   2U
#define MPU_CTRL_PRIVDEFENA_Msk   (1UL << MPU_CTRL_PRIVDEFENA_Pos)
#define MPU_CTRL_HFNMIENA_Pos     1U
#define MPU_CTRL_HFNMIENA_Msk     (1UL << MPU_CTRL_HFNMIENA_Pos)
#define MPU_CTRL_ENABLE_Pos       0U
#define MPU_CTRL_ENABLE_Msk       (1UL << MPU_CTRL_ENABLE_Pos)

/**
 * MPU_RNR Register Bits
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-638
 */
#define MPU_RNR_REGION_Pos        0U
#define MPU_RNR_REGION_Msk        (0xFFUL << MPU_RNR_REGION_Pos)

/**
 * MPU_RBAR Register Bits
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-638
 */
#define MPU_RBAR_ADDR_Pos         5U
#define MPU_RBAR_ADDR_Msk         (0x7FFFFFFUL << MPU_RBAR_ADDR_Pos)
#define MPU_RBAR_VALID_Pos        4U
#define MPU_RBAR_VALID_Msk        (1UL << MPU_RBAR_VALID_Pos)
#define MPU_RBAR_REGION_Pos       0U
#define MPU_RBAR_REGION_Msk       (0xFUL << MPU_RBAR_REGION_Pos)

/**
 * MPU_RASR Register Bits
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-639
 */
#define MPU_RASR_ATTRS_Pos        16U
#define MPU_RASR_ATTRS_Msk        (0xFFFFUL << MPU_RASR_ATTRS_Pos)
#define MPU_RASR_SRD_Pos          8U
#define MPU_RASR_SRD_Msk          (0xFFUL << MPU_RASR_SRD_Pos)
#define MPU_RASR_SIZE_Pos         1U
#define MPU_RASR_SIZE_Msk         (0x1FUL << MPU_RASR_SIZE_Pos)
#define MPU_RASR_ENABLE_Pos       0U
#define MPU_RASR_ENABLE_Msk       (1UL << MPU_RASR_ENABLE_Pos)

/**
 * MPU_RASR.ATTRS Subfield Bits
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-639
 */
#define MPU_RASR_XN_Pos           28U
#define MPU_RASR_XN_Msk           (1UL << MPU_RASR_XN_Pos)
#define MPU_RASR_AP_Pos           24U
#define MPU_RASR_AP_Msk           (0x7UL << MPU_RASR_AP_Pos)
#define MPU_RASR_TEX_Pos          19U
#define MPU_RASR_TEX_Msk          (0x7UL << MPU_RASR_TEX_Pos)
#define MPU_RASR_S_Pos            18U
#define MPU_RASR_S_Msk            (1UL << MPU_RASR_S_Pos)
#define MPU_RASR_C_Pos            17U
#define MPU_RASR_C_Msk            (1UL << MPU_RASR_C_Pos)
#define MPU_RASR_B_Pos            16U
#define MPU_RASR_B_Msk            (1UL << MPU_RASR_B_Pos)

/*
 * ============================================================================
 * MPU Region Size Definitions
 * MPU 区域大小定义
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-639
 * ============================================================================
 */

#define MPU_REGION_SIZE_32B       0x04U  /* 2^(4+1) = 32 bytes */
#define MPU_REGION_SIZE_64B       0x05U  /* 2^(5+1) = 64 bytes */
#define MPU_REGION_SIZE_128B      0x06U  /* 2^(6+1) = 128 bytes */
#define MPU_REGION_SIZE_256B      0x07U  /* 2^(7+1) = 256 bytes */
#define MPU_REGION_SIZE_512B      0x08U  /* 2^(8+1) = 512 bytes */
#define MPU_REGION_SIZE_1KB       0x09U  /* 2^(9+1) = 1KB */
#define MPU_REGION_SIZE_2KB       0x0AU  /* 2^(10+1) = 2KB */
#define MPU_REGION_SIZE_4KB       0x0BU  /* 2^(11+1) = 4KB */
#define MPU_REGION_SIZE_8KB       0x0CU  /* 2^(12+1) = 8KB */
#define MPU_REGION_SIZE_16KB      0x0DU  /* 2^(13+1) = 16KB */
#define MPU_REGION_SIZE_32KB      0x0EU  /* 2^(14+1) = 32KB */
#define MPU_REGION_SIZE_64KB      0x0FU  /* 2^(15+1) = 64KB */
#define MPU_REGION_SIZE_128KB     0x10U  /* 2^(16+1) = 128KB */
#define MPU_REGION_SIZE_256KB     0x11U  /* 2^(17+1) = 256KB */
#define MPU_REGION_SIZE_512KB     0x12U  /* 2^(18+1) = 512KB */
#define MPU_REGION_SIZE_1MB       0x13U  /* 2^(19+1) = 1MB */
#define MPU_REGION_SIZE_2MB       0x14U  /* 2^(20+1) = 2MB */
#define MPU_REGION_SIZE_4MB       0x15U  /* 2^(21+1) = 4MB */
#define MPU_REGION_SIZE_8MB       0x16U  /* 2^(22+1) = 8MB */
#define MPU_REGION_SIZE_16MB      0x17U  /* 2^(23+1) = 16MB */
#define MPU_REGION_SIZE_32MB      0x18U  /* 2^(24+1) = 32MB */
#define MPU_REGION_SIZE_64MB      0x19U  /* 2^(25+1) = 64MB */
#define MPU_REGION_SIZE_128MB     0x1AU  /* 2^(26+1) = 128MB */
#define MPU_REGION_SIZE_256MB     0x1BU  /* 2^(27+1) = 256MB */
#define MPU_REGION_SIZE_512MB     0x1CU  /* 2^(28+1) = 512MB */
#define MPU_REGION_SIZE_1GB       0x1DU  /* 2^(29+1) = 1GB */
#define MPU_REGION_SIZE_2GB       0x1EU  /* 2^(30+1) = 2GB */
#define MPU_REGION_SIZE_4GB       0x1FU  /* 2^(31+1) = 4GB */

/*
 * ============================================================================
 * MPU Access Permission Definitions
 * MPU 访问权限定义
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-642
 * ============================================================================
 */

#define MPU_AP_NO_ACCESS          0x0U  /* No access */
#define MPU_AP_PRIV_RW            0x1U  /* Privileged: RW, User: No access */
#define MPU_AP_PRIV_RW_USER_RO    0x2U  /* Privileged: RW, User: RO */
#define MPU_AP_PRIV_RW_USER_RW    0x3U  /* Privileged: RW, User: RW */
#define MPU_AP_RESERVED           0x4U  /* Reserved */
#define MPU_AP_PRIV_RO            0x5U  /* Privileged: RO, User: No access */
#define MPU_AP_PRIV_RO_USER_RO    0x6U  /* Privileged: RO, User: RO */
#define MPU_AP_RO                 0x7U  /* RO (same as 0x6) */

/*
 * ============================================================================
 * MPU Memory Type Definitions
 * MPU 内存类型定义
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-641 (Table B3-13)
 * ============================================================================
 */

/* Strongly-ordered */
#define MPU_ATTR_STRONGLY_ORDERED (0x0UL << MPU_RASR_TEX_Pos)

/* Device memory */
#define MPU_ATTR_DEVICE_SHARED    (0x0UL << MPU_RASR_TEX_Pos) | MPU_RASR_B_Msk
#define MPU_ATTR_DEVICE_NONSHARED ((0x2UL << MPU_RASR_TEX_Pos) | (0x0UL << MPU_RASR_B_Pos))

/* Normal memory, Non-cacheable */
#define MPU_ATTR_NORMAL_NONCACHE  ((0x1UL << MPU_RASR_TEX_Pos) | (0x0UL << MPU_RASR_C_Pos) | (0x0UL << MPU_RASR_B_Pos))

/* Normal memory, Write-Through */
#define MPU_ATTR_NORMAL_WT        ((0x0UL << MPU_RASR_TEX_Pos) | MPU_RASR_C_Msk)

/* Normal memory, Write-Back */
#define MPU_ATTR_NORMAL_WB        ((0x0UL << MPU_RASR_TEX_Pos) | MPU_RASR_C_Msk | MPU_RASR_B_Msk)

/* Normal memory, Write-Back with allocate */
#define MPU_ATTR_NORMAL_WB_ALLOC  ((0x1UL << MPU_RASR_TEX_Pos) | MPU_RASR_C_Msk | MPU_RASR_B_Msk)

/* Shareable attribute */
#define MPU_ATTR_SHAREABLE        MPU_RASR_S_Msk
#define MPU_ATTR_NON_SHAREABLE    0U

/* Execute Never attribute */
#define MPU_ATTR_XN               MPU_RASR_XN_Msk
#define MPU_ATTR_EXEC_OK          0U

/*
 * ============================================================================
 * MPU Function Declarations
 * MPU 函数声明
 * ============================================================================
 */

/**
 * @brief Enable MPU
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-636 (MPU_CTRL register)
 */
void mpu_enable(void);

/**
 * @brief Disable MPU
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-636 (MPU_CTRL register)
 */
void mpu_disable(void);

/**
 * @brief Check if MPU is enabled
 * @return true if enabled, false otherwise
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-636 (MPU_CTRL register)
 */
bool mpu_is_enabled(void);

/**
 * @brief Get number of MPU regions
 * @return Number of regions
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-635 (MPU_TYPE register)
 */
uint32_t mpu_get_num_regions(void);

/**
 * @brief Configure MPU region
 * @param region Region number (0 to MPU_DREGION-1)
 * @param base_addr Region base address (must be aligned to region size)
 * @param size Region size (MPU_REGION_SIZE_*)
 * @param attributes Region attributes (combination of MPU_ATTR_*)
 * @param srd Subregion disable mask (0-255)
 * @return 0 on success, -1 on error
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-638 (MPU_RBAR, MPU_RASR registers)
 */
int32_t mpu_configure_region(uint32_t region, uint32_t base_addr, uint32_t size, uint32_t attributes, uint8_t srd);

/**
 * @brief Enable MPU region
 * @param region Region number
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-639 (MPU_RASR register)
 */
void mpu_enable_region(uint32_t region);

/**
 * @brief Disable MPU region
 * @param region Region number
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-639 (MPU_RASR register)
 */
void mpu_disable_region(uint32_t region);

/**
 * @brief Set MPU region base address
 * @param region Region number
 * @param addr Base address
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-638 (MPU_RBAR register)
 */
void mpu_set_region_base(uint32_t region, uint32_t addr);

/**
 * @brief Set MPU region attributes
 * @param region Region number
 * @param size Region size
 * @param attributes Region attributes
 * @param srd Subregion disable mask
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-639 (MPU_RASR register)
 */
void mpu_set_region_attr(uint32_t region, uint32_t size, uint32_t attributes, uint8_t srd);

/**
 * @brief Set default memory map for privileged access
 * @param enable true to enable, false to disable
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-636 (MPU_CTRL.PRIVDEFENA)
 */
void mpu_set_priv_default(bool enable);

/**
 * @brief Enable MPU for HardFault and NMI handlers
 * @param enable true to enable, false to disable
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-636 (MPU_CTRL.HFNMIENA)
 */
void mpu_enable_for_hardfault_nmi(bool enable);

/**
 * @brief Calculate region size encoding from actual size in bytes
 * @param size Size in bytes
 * @return Size encoding for MPU_RASR
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-639
 */
uint32_t mpu_calc_size(uint32_t size);

/**
 * @brief Check if address is aligned to size
 * @param addr Address to check
 * @param size Size in bytes
 * @return true if aligned, false otherwise
 */
bool mpu_is_addr_aligned(uint32_t addr, uint32_t size);

/**
 * @brief Get MPU region base address
 * @param region Region number
 * @return Base address
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-638 (MPU_RBAR register)
 */
uint32_t mpu_get_region_base(uint32_t region);

/**
 * @brief Get MPU region attributes
 * @param region Region number
 * @return Region attributes
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-639 (MPU_RASR register)
 */
uint32_t mpu_get_region_attr(uint32_t region);

/**
 * @brief Check if MPU region is enabled
 * @param region Region number
 * @return true if enabled, false otherwise
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-639 (MPU_RASR register)
 */
bool mpu_is_region_enabled(uint32_t region);

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
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-639 (MPU_RASR register)
 */
int32_t mpu_configure_region_ex(uint32_t region, uint32_t base_addr, uint32_t size,
                                uint32_t ap, uint32_t tex, uint32_t s, uint32_t c,
                                uint32_t b, uint32_t xn, uint8_t srd);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_MPU_H__ */
