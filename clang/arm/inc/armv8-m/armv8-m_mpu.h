/*
 * ARM Architecture - ARMv8-M MPU (Memory Protection Unit)
 *
 * ============================================================================
 * File: armv8m_mpu.h
 * Description: ARMv8-M MPU register definitions and function declarations
 * 描述: ARMv8-M MPU 寄存器定义和函数声明
 *
 * This file provides definitions for the Memory Protection Unit:
 * - MPU register definitions
 * - Memory attribute definitions
 * - Region configuration functions
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B10: The Armv8-M Protected Memory System Architecture
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V8M_MPU_H__
#define __ARCH_ARM_V8M_MPU_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv8m_config.h"

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
#define MPU_NS_BASE_ADDR          0xE002ED90UL

/*
 * ============================================================================
 * MPU Register Definitions
 * MPU 寄存器定义
 * ============================================================================
 */

/**
 * MPU Type Register (MPU_TYPE)
 * MPU 类型寄存器
 */
#define MPU_TYPE                  (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x00))

/**
 * MPU Control Register (MPU_CTRL)
 * MPU 控制寄存器
 */
#define MPU_CTRL                  (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x04))

/**
 * MPU Region Number Register (MPU_RNR)
 * MPU 区域编号寄存器
 */
#define MPU_RNR                   (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x08))

/**
 * MPU Region Base Address Register (MPU_RBAR)
 * MPU 区域基地址寄存器
 */
#define MPU_RBAR                  (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x0C))

/**
 * MPU Region Limit Address Register (MPU_RLAR)
 * MPU 区域限制地址寄存器
 */
#define MPU_RLAR                  (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x10))

/**
 * MPU Region Base Address Register Alias 1-3 (MPU_RBAR_A1-A3)
 * MPU 区域基地址寄存器别名 1-3
 */
#define MPU_RBAR_A1               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x14))
#define MPU_RBAR_A2               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x18))
#define MPU_RBAR_A3               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x1C))

/**
 * MPU Region Limit Address Register Alias 1-3 (MPU_RLAR_A1-A3)
 * MPU 区域限制地址寄存器别名 1-3
 */
#define MPU_RLAR_A1               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x20))
#define MPU_RLAR_A2               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x24))
#define MPU_RLAR_A3               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x28))

/**
 * MPU Memory Attribute Indirection Register 0 (MPU_MAIR0)
 * MPU 内存属性间接寄存器 0
 */
#define MPU_MAIR0                 (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x30))

/**
 * MPU Memory Attribute Indirection Register 1 (MPU_MAIR1)
 * MPU 内存属性间接寄存器 1
 */
#define MPU_MAIR1                 (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x34))

/*
 * ============================================================================
 * Non-Secure MPU Register Definitions (TrustZone)
 * 非安全 MPU 寄存器定义 (TrustZone)
 * ============================================================================
 */

#if (__TZ_PRESENT == 1)
#define MPU_NS_TYPE               (*(volatile uint32_t *)(MPU_NS_BASE_ADDR + 0x00))
#define MPU_NS_CTRL               (*(volatile uint32_t *)(MPU_NS_BASE_ADDR + 0x04))
#define MPU_NS_RNR                (*(volatile uint32_t *)(MPU_NS_BASE_ADDR + 0x08))
#define MPU_NS_RBAR               (*(volatile uint32_t *)(MPU_NS_BASE_ADDR + 0x0C))
#define MPU_NS_RLAR               (*(volatile uint32_t *)(MPU_NS_BASE_ADDR + 0x10))
#define MPU_NS_MAIR0              (*(volatile uint32_t *)(MPU_NS_BASE_ADDR + 0x30))
#define MPU_NS_MAIR1              (*(volatile uint32_t *)(MPU_NS_BASE_ADDR + 0x34))
#endif

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
#define MPU_TYPE_DREGION_Msk      (0xFFUL << MPU_TYPE_DREGION_Pos)
#define MPU_TYPE_SEPARATE_Pos     0U
#define MPU_TYPE_SEPARATE_Msk     (1UL << MPU_TYPE_SEPARATE_Pos)

/**
 * MPU_CTRL Register Bits
 * MPU_CTRL 寄存器位
 */
#define MPU_CTRL_PRIVDEFENA_Pos   2U
#define MPU_CTRL_PRIVDEFENA_Msk   (1UL << MPU_CTRL_PRIVDEFENA_Pos)
#define MPU_CTRL_HFNMIENA_Pos     1U
#define MPU_CTRL_HFNMIENA_Msk     (1UL << MPU_CTRL_HFNMIENA_Pos)
#define MPU_CTRL_ENABLE_Pos       0U
#define MPU_CTRL_ENABLE_Msk       (1UL << MPU_CTRL_ENABLE_Pos)

/**
 * MPU_RBAR Register Bits
 * MPU_RBAR 寄存器位
 */
#define MPU_RBAR_BASE_Pos         5U
#define MPU_RBAR_BASE_Msk         (0x7FFFFFFUL << MPU_RBAR_BASE_Pos)
#define MPU_RBAR_SH_Pos           3U
#define MPU_RBAR_SH_Msk           (3UL << MPU_RBAR_SH_Pos)
#define MPU_RBAR_AP_Pos           1U
#define MPU_RBAR_AP_Msk           (3UL << MPU_RBAR_AP_Pos)
#define MPU_RBAR_XN_Pos           0U
#define MPU_RBAR_XN_Msk           (1UL << MPU_RBAR_XN_Pos)

/**
 * MPU_RLAR Register Bits
 * MPU_RLAR 寄存器位
 */
#define MPU_RLAR_LIMIT_Pos        5U
#define MPU_RLAR_LIMIT_Msk        (0x7FFFFFFUL << MPU_RLAR_LIMIT_Pos)
#define MPU_RLAR_ATTRIDX_Pos      1U
#define MPU_RLAR_ATTRIDX_Msk      (7UL << MPU_RLAR_ATTRIDX_Pos)
#define MPU_RLAR_EN_Pos           0U
#define MPU_RLAR_EN_Msk           (1UL << MPU_RLAR_EN_Pos)

/*
 * ============================================================================
 * MPU Region Configuration Constants
 * MPU 区域配置常量
 * ============================================================================
 */

/**
 * Shareability Attributes
 * 共享属性
 */
#define MPU_SH_NON_SHAREABLE      0x0U  /* Non-shareable */
#define MPU_SH_OUTER_SHAREABLE    0x2U  /* Outer shareable */
#define MPU_SH_INNER_SHAREABLE    0x3U  /* Inner shareable */

/**
 * Access Permission Attributes
 * 访问权限属性
 */
#define MPU_AP_RW_PRIV_ONLY       0x0U  /* Read/Write, Privileged only */
#define MPU_AP_RW_PRIV_UNPRIV     0x1U  /* Read/Write, Privileged and Unprivileged */
#define MPU_AP_RO_PRIV_ONLY       0x2U  /* Read-Only, Privileged only */
#define MPU_AP_RO_PRIV_UNPRIV     0x3U  /* Read-Only, Privileged and Unprivileged */

/**
 * Execute Never Attribute
 * 永不执行属性
 */
#define MPU_XN_EXEC_OK            0x0U  /* Execution permitted */
#define MPU_XN_EXEC_NEVER         0x1U  /* Execution not permitted */

/**
 * Memory Attribute Index
 * 内存属性索引
 */
#define MPU_ATTR_INDEX_0          0x0U
#define MPU_ATTR_INDEX_1          0x1U
#define MPU_ATTR_INDEX_2          0x2U
#define MPU_ATTR_INDEX_3          0x3U
#define MPU_ATTR_INDEX_4          0x4U
#define MPU_ATTR_INDEX_5          0x5U
#define MPU_ATTR_INDEX_6          0x6U
#define MPU_ATTR_INDEX_7          0x7U

/*
 * ============================================================================
 * Memory Attribute Encoding (MAIR)
 * 内存属性编码 (MAIR)
 * ============================================================================
 */

/**
 * Device Memory Attributes
 * 设备内存属性
 */
#define MAIR_ATTR_DEVICE_nGnRnE   0x00U  /* Device, non-Gathering, non-Reordering, no Early write acknowledgement */
#define MAIR_ATTR_DEVICE_nGnRE    0x04U  /* Device, non-Gathering, non-Reordering, Early write acknowledgement */
#define MAIR_ATTR_DEVICE_nGRE     0x08U  /* Device, non-Gathering, Reordering, Early write acknowledgement */
#define MAIR_ATTR_DEVICE_GRE      0x0CU  /* Device, Gathering, Reordering, Early write acknowledgement */

/**
 * Normal Memory Inner Cache Attributes
 * 普通内存内部缓存属性
 */
#define MAIR_ATTR_NORMAL_INNER_NON_CACHEABLE    0x04U
#define MAIR_ATTR_NORMAL_INNER_WB_RA_WA         0xFFU  /* Write-Back, Read-Allocate, Write-Allocate */
#define MAIR_ATTR_NORMAL_INNER_WT_RA            0xBBU  /* Write-Through, Read-Allocate */
#define MAIR_ATTR_NORMAL_INNER_WB_RA            0xF7U  /* Write-Back, Read-Allocate */

/**
 * Normal Memory Outer Cache Attributes
 * 普通内存外部缓存属性
 */
#define MAIR_ATTR_NORMAL_OUTER_NON_CACHEABLE    0x04U
#define MAIR_ATTR_NORMAL_OUTER_WB_RA_WA         0xFFU  /* Write-Back, Read-Allocate, Write-Allocate */
#define MAIR_ATTR_NORMAL_OUTER_WT_RA            0xBBU  /* Write-Through, Read-Allocate */
#define MAIR_ATTR_NORMAL_OUTER_WB_RA            0xF7U  /* Write-Back, Read-Allocate */

/**
 * MAIR Attribute Macros
 * MAIR 属性宏
 */
#define MAIR_ATTR_NORMAL(inner, outer)  (((inner) << 4) | (outer))
#define MAIR_ATTR_DEVICE(type)          (type)

/*
 * ============================================================================
 * MPU Type Definitions
 * MPU 类型定义
 * ============================================================================
 */

/**
 * MPU Region Structure
 * MPU 区域结构体
 */
typedef struct {
    uint32_t RBAR;  /*!< Region Base Address Register */
    uint32_t RLAR;  /*!< Region Limit Address Register */
} ARM_MPU_Region_t;

/**
 * MPU Region Configuration Structure
 * MPU 区域配置结构体
 */
typedef struct {
    uint32_t base_addr;     /*!< Region base address (32-byte aligned) */
    uint32_t limit_addr;    /*!< Region limit address */
    uint8_t  attr_idx;      /*!< Memory attribute index (0-7) */
    uint8_t  shareability;  /*!< Shareability attribute */
    uint8_t  access_perm;   /*!< Access permission */
    uint8_t  execute_never; /*!< Execute never attribute */
    uint8_t  enable;        /*!< Region enable */
} mpu_region_cfg_t;

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Initialize MPU
 */
void mpu_init(void);

/**
 * @brief Enable MPU
 * @param default_map Enable privileged default memory map
 * @param hardfault_nmi Enable MPU during HardFault and NMI handlers
 */
void mpu_enable(bool default_map, bool hardfault_nmi);

/**
 * @brief Disable MPU
 */
void mpu_disable(void);

/**
 * @brief Get MPU type (number of regions)
 * @return Number of MPU regions
 */
uint32_t mpu_get_type(void);

/**
 * @brief Set memory attribute
 * @param idx Attribute index (0-7)
 * @param attr Memory attribute value
 */
void mpu_set_mem_attr(uint8_t idx, uint8_t attr);

/**
 * @brief Get memory attribute
 * @param idx Attribute index (0-7)
 * @return Memory attribute value
 */
uint8_t mpu_get_mem_attr(uint8_t idx);

/**
 * @brief Configure MPU region
 * @param rnr Region number
 * @param cfg Region configuration
 */
void mpu_configure_region(uint32_t rnr, const mpu_region_cfg_t *cfg);

/**
 * @brief Set MPU region
 * @param rnr Region number
 * @param rbar Region Base Address Register value
 * @param rlar Region Limit Address Register value
 */
void mpu_set_region(uint32_t rnr, uint32_t rbar, uint32_t rlar);

/**
 * @brief Clear MPU region
 * @param rnr Region number
 */
void mpu_clear_region(uint32_t rnr);

/**
 * @brief Enable MPU region
 * @param rnr Region number
 */
void mpu_enable_region(uint32_t rnr);

/**
 * @brief Disable MPU region
 * @param rnr Region number
 */
void mpu_disable_region(uint32_t rnr);

/**
 * @brief Load multiple MPU regions from table
 * @param rnr First region number to configure
 * @param table Pointer to MPU configuration table
 * @param count Number of regions to configure
 */
void mpu_load_regions(uint32_t rnr, const ARM_MPU_Region_t *table, uint32_t count);

/**
 * @brief Check if address is in MPU region
 * @param addr Address to check
 * @return Region number if found, -1 if not found
 */
int32_t mpu_get_region_for_address(uint32_t addr);

/*
 * ============================================================================
 * Non-Secure MPU Functions (TrustZone)
 * 非安全 MPU 函数 (TrustZone)
 * ============================================================================
 */

#if (__TZ_PRESENT == 1)

void mpu_enable_ns(uint32_t mpu_control);
void mpu_disable_ns(void);
void mpu_set_mem_attr_ns(uint8_t idx, uint8_t attr);
void mpu_set_region_ns(uint32_t rnr, uint32_t rbar, uint32_t rlar);
void mpu_clear_region_ns(uint32_t rnr);
void mpu_load_regions_ns(uint32_t rnr, const ARM_MPU_Region_t *table, uint32_t count);

#endif /* __TZ_PRESENT */

/*
 * ============================================================================
 * Inline Helper Functions
 * 内联辅助函数
 * ============================================================================
 */

/**
 * @brief Build RBAR value from components
 * @param base Base address (32-byte aligned)
 * @param sh Shareability
 * @param ap Access permission
 * @param xn Execute never
 * @return RBAR value
 */
static inline uint32_t mpu_build_rbar(uint32_t base, uint8_t sh, uint8_t ap, uint8_t xn) {
    return ((base & MPU_RBAR_BASE_Msk) |
            ((sh << MPU_RBAR_SH_Pos) & MPU_RBAR_SH_Msk) |
            ((ap << MPU_RBAR_AP_Pos) & MPU_RBAR_AP_Msk) |
            ((xn << MPU_RBAR_XN_Pos) & MPU_RBAR_XN_Msk));
}

/**
 * @brief Build RLAR value from components
 * @param limit Limit address
 * @param attr_idx Attribute index
 * @param enable Region enable
 * @return RLAR value
 */
static inline uint32_t mpu_build_rlar(uint32_t limit, uint8_t attr_idx, uint8_t enable) {
    return ((limit & MPU_RLAR_LIMIT_Msk) |
            ((attr_idx << MPU_RLAR_ATTRIDX_Pos) & MPU_RLAR_ATTRIDX_Msk) |
            ((enable << MPU_RLAR_EN_Pos) & MPU_RLAR_EN_Msk));
}

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V8M_MPU_H__ */
