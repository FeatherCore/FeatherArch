/*
 * ARM Architecture - ARMv7-M MPU (Memory Protection Unit)
 *
 * ============================================================================
 * File: armv7-m_mpu.h
 * Description: ARMv7-M MPU register definitions and function declarations
 * 描述: ARMv7-M MPU 寄存器定义和函数声明
 *
 * This file provides definitions for the Memory Protection Unit:
 * - MPU register definitions
 * - Memory attribute definitions
 * - Region configuration functions
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B3.5 - Protected Memory System Architecture, PMSAv7
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_MPU_H__
#define __ARCH_ARM_V7M_MPU_H__

#include &lt;stdint.h&gt;
#include &lt;stdbool.h&gt;
#include "armv7-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * MPU Base Addresses
 * MPU 基地址
 * ============================================================================
 */

#define MPU_BASE_ADDR             0xE000ED90UL

/*
 * ============================================================================
 * MPU Register Definitions
 * MPU 寄存器定义
 * ============================================================================
 */

/**
 * MPU Type Register (MPU_TYPE)
 * MPU 类型寄存器
 * Reference: Chapter B3.5 - Protected Memory System Architecture, PMSAv7
 */
#define MPU_TYPE                  (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x00))

/**
 * MPU Control Register (MPU_CTRL)
 * MPU 控制寄存器
 * Reference: Chapter B3.5 - Protected Memory System Architecture, PMSAv7
 */
#define MPU_CTRL                  (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x04))

/**
 * MPU Region Number Register (MPU_RNR)
 * MPU 区域编号寄存器
 * Reference: Chapter B3.5 - Protected Memory System Architecture, PMSAv7
 */
#define MPU_RNR                   (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x08))

/**
 * MPU Region Base Address Register (MPU_RBAR)
 * MPU 区域基地址寄存器
 * Reference: Chapter B3.5 - Protected Memory System Architecture, PMSAv7
 */
#define MPU_RBAR                  (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x0C))

/**
 * MPU Region Attribute and Size Register (MPU_RASR)
 * MPU 区域属性和大小寄存器
 * Reference: Chapter B3.5 - Protected Memory System Architecture, PMSAv7
 */
#define MPU_RASR                  (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x10))

/**
 * MPU Region Base Address Register Alias 1-3 (MPU_RBAR_A1-A3)
 * MPU 区域基地址寄存器别名 1-3
 * Reference: Chapter B3.5 - Protected Memory System Architecture, PMSAv7
 */
#define MPU_RBAR_A1               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x14))
#define MPU_RBAR_A2               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x18))
#define MPU_RBAR_A3               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x1C))

/**
 * MPU Region Attribute and Size Register Alias 1-3 (MPU_RASR_A1-A3)
 * MPU 区域属性和大小寄存器别名 1-3
 * Reference: Chapter B3.5 - Protected Memory System Architecture, PMSAv7
 */
#define MPU_RASR_A1               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x18))
#define MPU_RASR_A2               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x20))
#define MPU_RASR_A3               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x28))

/*
 * ============================================================================
 * MPU Register Bit Definitions
 * MPU 寄存器位定义
 * ============================================================================
 */

/**
 * MPU_TYPE Register Bits
 * MPU_TYPE 寄存器位
 */
#define MPU_TYPE_DREGION_Pos      8U
#define MPU_TYPE_DREGION_Msk      (0xFFUL &lt;&lt; MPU_TYPE_DREGION_Pos)
#define MPU_TYPE_IREGION_Pos      16U
#define MPU_TYPE_IREGION_Msk      (0xFFUL &lt;&lt; MPU_TYPE_IREGION_Pos)
#define MPU_TYPE_SEPARATE_Pos     0U
#define MPU_TYPE_SEPARATE_Msk     (1UL &lt;&lt; MPU_TYPE_SEPARATE_Pos)

/**
 * MPU_CTRL Register Bits
 * MPU_CTRL 寄存器位
 */
#define MPU_CTRL_PRIVDEFENA_Pos   2U
#define MPU_CTRL_PRIVDEFENA_Msk   (1UL &lt;&lt; MPU_CTRL_PRIVDEFENA_Pos)
#define MPU_CTRL_HFNMIENA_Pos     1U
#define MPU_CTRL_HFNMIENA_Msk     (1UL &lt;&lt; MPU_CTRL_HFNMIENA_Pos)
#define MPU_CTRL_ENABLE_Pos       0U
#define MPU_CTRL_ENABLE_Msk       (1UL &lt;&lt; MPU_CTRL_ENABLE_Pos)

#define MPU_CTRL_PRIVDEFENA       MPU_CTRL_PRIVDEFENA_Msk
#define MPU_CTRL_HFNMIENA         MPU_CTRL_HFNMIENA_Msk
#define MPU_CTRL_ENABLE           MPU_CTRL_ENABLE_Msk

/**
 * MPU_RBAR Register Bits
 * MPU_RBAR 寄存器位
 */
#define MPU_RBAR_ADDR_Pos         5U
#define MPU_RBAR_ADDR_Msk         (0x7FFFFFFUL &lt;&lt; MPU_RBAR_ADDR_Pos)
#define MPU_RBAR_VALID_Pos        4U
#define MPU_RBAR_VALID_Msk        (1UL &lt;&lt; MPU_RBAR_VALID_Pos)
#define MPU_RBAR_REGION_Pos       0U
#define MPU_RBAR_REGION_Msk       (0xFUL &lt;&lt; MPU_RBAR_REGION_Pos)

#define MPU_RBAR_VALID            MPU_RBAR_VALID_Msk

/**
 * MPU_RASR Register Bits
 * MPU_RASR 寄存器位
 */
#define MPU_RASR_ATTRS_Pos        16U
#define MPU_RASR_ATTRS_Msk        (0xFFFFUL &lt;&lt; MPU_RASR_ATTRS_Pos)
#define MPU_RASR_SR_Pos           18U
#define MPU_RASR_SR_Msk           (1UL &lt;&lt; MPU_RASR_SR_Pos)
#define MPU_RASR_B_Pos            17U
#define MPU_RASR_B_Msk            (1UL &lt;&lt; MPU_RASR_B_Pos)
#define MPU_RASR_C_Pos            16U
#define MPU_RASR_C_Msk            (1UL &lt;&lt; MPU_RASR_C_Pos)
#define MPU_RASR_S_Pos            19U
#define MPU_RASR_S_Msk            (1UL &lt;&lt; MPU_RASR_S_Pos)
#define MPU_RASR_TEX_Pos          19U
#define MPU_RASR_TEX_Msk          (7UL &lt;&lt; MPU_RASR_TEX_Pos)
#define MPU_RASR_AP_Pos           24U
#define MPU_RASR_AP_Msk           (7UL &lt;&lt; MPU_RASR_AP_Pos)
#define MPU_RASR_XN_Pos           28U
#define MPU_RASR_XN_Msk           (1UL &lt;&lt; MPU_RASR_XN_Pos)
#define MPU_RASR_SIZE_Pos         1U
#define MPU_RASR_SIZE_Msk         (0x1FUL &lt;&lt; MPU_RASR_SIZE_Pos)
#define MPU_RASR_ENABLE_Pos       0U
#define MPU_RASR_ENABLE_Msk       (1UL &lt;&lt; MPU_RASR_ENABLE_Pos)

#define MPU_RASR_XN               MPU_RASR_XN_Msk
#define MPU_RASR_ENABLE           MPU_RASR_ENABLE_Msk

/*
 * ============================================================================
 * MPU Region Configuration Constants
 * MPU 区域配置常量
 * ============================================================================
 */

/**
 * Access Permission Attributes
 * 访问权限属性
 */
#define MPU_AP_NO_ACCESS          0x0U  /* No access */
#define MPU_AP_RW_PRIV_ONLY       0x1U  /* Read/Write, Privileged only */
#define MPU_AP_RW_PRIV_UNPRIV     0x2U  /* Read/Write, Privileged and Unprivileged */
#define MPU_AP_RO_PRIV_ONLY       0x5U  /* Read-Only, Privileged only */
#define MPU_AP_RO_PRIV_UNPRIV     0x6U  /* Read-Only, Privileged and Unprivileged */

/**
 * Memory Type Attributes
 * 内存类型属性
 */
#define MPU_TEX_STRONGLY_ORDERED  0x0U  /* Strongly ordered */
#define MPU_TEX_DEVICE            0x0U  /* Device */
#define MPU_TEX_NORMAL            0x1U  /* Normal */
#define MPU_TEX_NORMAL_WT         0x2U  /* Normal, Write-through */
#define MPU_TEX_NORMAL_WB         0x4U  /* Normal, Write-back */

/**
 * Shareable Attribute
 * 共享属性
 */
#define MPU_S_SHAREABLE           1U    /* Shareable */
#define MPU_S_NON_SHAREABLE       0U    /* Non-shareable */

/**
 * Cacheable Attributes
 * 可缓存属性
 */
#define MPU_C_CACHEABLE           1U    /* Cacheable */
#define MPU_C_NON_CACHEABLE       0U    /* Non-cacheable */

/**
 * Bufferable Attribute
 * 可缓冲属性
 */
#define MPU_B_BUFFERABLE          1U    /* Bufferable */
#define MPU_B_NON_BUFFERABLE      0U    /* Non-bufferable */

/**
 * Region Size Values
 * 区域大小值
 */
#define MPU_SIZE_32B              0x04U /* 32 bytes */
#define MPU_SIZE_64B              0x05U /* 64 bytes */
#define MPU_SIZE_128B             0x06U /* 128 bytes */
#define MPU_SIZE_256B             0x07U /* 256 bytes */
#define MPU_SIZE_512B             0x08U /* 512 bytes */
#define MPU_SIZE_1KB              0x09U /* 1KB */
#define MPU_SIZE_2KB              0x0AU /* 2KB */
#define MPU_SIZE_4KB              0x0BU /* 4KB */
#define MPU_SIZE_8KB              0x0CU /* 8KB */
#define MPU_SIZE_16KB             0x0DU /* 16KB */
#define MPU_SIZE_32KB             0x0EU /* 32KB */
#define MPU_SIZE_64KB             0x0FU /* 64KB */
#define MPU_SIZE_128KB            0x10U /* 128KB */
#define MPU_SIZE_256KB            0x11U /* 256KB */
#define MPU_SIZE_512KB            0x12U /* 512KB */
#define MPU_SIZE_1MB              0x13U /* 1MB */
#define MPU_SIZE_2MB              0x14U /* 2MB */
#define MPU_SIZE_4MB              0x15U /* 4MB */
#define MPU_SIZE_8MB              0x16U /* 8MB */
#define MPU_SIZE_16MB             0x17U /* 16MB */
#define MPU_SIZE_32MB             0x18U /* 32MB */
#define MPU_SIZE_64MB             0x19U /* 64MB */
#define MPU_SIZE_128MB            0x1AU /* 128MB */
#define MPU_SIZE_256MB            0x1BU /* 256MB */
#define MPU_SIZE_512MB            0x1CU /* 512MB */
#define MPU_SIZE_1GB              0x1DU /* 1GB */
#define MPU_SIZE_2GB              0x1EU /* 2GB */
#define MPU_SIZE_4GB              0x1FU /* 4GB */

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Enable MPU
 * @param privdefena Enable privileged default memory map
 * @param hfnmiena Enable MPU during HardFault and NMI
 */
void mpu_enable(uint8_t privdefena, uint8_t hfnmiena);

/**
 * @brief Disable MPU
 */
void mpu_disable(void);

/**
 * @brief Configure MPU region
 * @param region Region number (0-7)
 * @param addr Base address (must be aligned to region size)
 * @param size Region size (MPU_SIZE_xxx)
 * @param ap Access permission (MPU_AP_xxx)
 * @param tex TEX field
 * @param s Shareable attribute
 * @param c Cacheable attribute
 * @param b Bufferable attribute
 * @param xn Execute Never attribute
 */
void mpu_configure_region(uint8_t region, uint32_t addr, uint8_t size,
                          uint8_t ap, uint8_t tex, uint8_t s,
                          uint8_t c, uint8_t b, uint8_t xn);

/**
 * @brief Enable MPU region
 * @param region Region number (0-7)
 */
void mpu_enable_region(uint8_t region);

/**
 * @brief Disable MPU region
 * @param region Region number (0-7)
 */
void mpu_disable_region(uint8_t region);

/**
 * @brief Get number of MPU regions
 * @return Number of MPU regions
 */
uint32_t mpu_get_num_regions(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_MPU_H__ */
