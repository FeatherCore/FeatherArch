/*
 * ARM Architecture - Cortex-M4 MPU (Memory Protection Unit)
 *
 * ============================================================================
 * File: cm4_mpu.h
 * Description: Cortex-M4 MPU register definitions
 * 描述: Cortex-M4 MPU 寄存器定义
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.5 Optional Memory Protection Unit (page 4-37)
 *   - Table 4-38 MPU registers summary (page 4-38)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_MPU_H__
#define __CM4_MPU_H__

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * MPU Base Address
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-38 (page 4-38)
 * ============================================================================
 */

#define CM4_MPU_BASE_ADDR             0xE000ED90UL

/*
 * ============================================================================
 * MPU Type Register (MPU_TYPE)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-39 (page 4-38)
 * Address: 0xE000ED90
 * ============================================================================
 */

#define MPU_TYPE                      (*(volatile uint32_t *)(CM4_MPU_BASE_ADDR + 0x000))

/* MPU_TYPE bit definitions - Reference: Table 4-39 (page 4-38) */
#define MPU_TYPE_SEPARATE_Pos         0U
#define MPU_TYPE_SEPARATE_Msk         (1UL << MPU_TYPE_SEPARATE_Pos)

#define MPU_TYPE_DREGION_Pos          8U
#define MPU_TYPE_DREGION_Msk          (0xFFUL << MPU_TYPE_DREGION_Pos)

#define MPU_TYPE_IREGION_Pos          16U
#define MPU_TYPE_IREGION_Msk          (0xFFUL << MPU_TYPE_IREGION_Pos)

/* Cortex-M4 specific values */
#define MPU_TYPE_DREGION_8            0x08UL
#define MPU_TYPE_SEPARATE_UNIFIED     0UL

/*
 * ============================================================================
 * MPU Control Register (MPU_CTRL)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-40 (page 4-39)
 * Address: 0xE000ED94
 * ============================================================================
 */

#define MPU_CTRL                      (*(volatile uint32_t *)(CM4_MPU_BASE_ADDR + 0x004))

/* MPU_CTRL bit definitions - Reference: Table 4-40 (page 4-39) */
#define MPU_CTRL_ENABLE_Pos           0U
#define MPU_CTRL_ENABLE_Msk           (1UL << MPU_CTRL_ENABLE_Pos)

#define MPU_CTRL_HFNMIENA_Pos         1U
#define MPU_CTRL_HFNMIENA_Msk         (1UL << MPU_CTRL_HFNMIENA_Pos)

#define MPU_CTRL_PRIVDEFENA_Pos       2U
#define MPU_CTRL_PRIVDEFENA_Msk       (1UL << MPU_CTRL_PRIVDEFENA_Pos)

/*
 * ============================================================================
 * MPU Region Number Register (MPU_RNR)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-41 (page 4-40)
 * Address: 0xE000ED98
 * ============================================================================
 */

#define MPU_RNR                       (*(volatile uint32_t *)(CM4_MPU_BASE_ADDR + 0x008))

/* MPU_RNR bit definitions - Reference: Table 4-41 (page 4-40) */
#define MPU_RNR_REGION_Pos            0U
#define MPU_RNR_REGION_Msk            (0xFFUL << MPU_RNR_REGION_Pos)

/*
 * ============================================================================
 * MPU Region Base Address Register (MPU_RBAR)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-42 (page 4-40)
 * Address: 0xE000ED9C
 * ============================================================================
 */

#define MPU_RBAR                      (*(volatile uint32_t *)(CM4_MPU_BASE_ADDR + 0x00C))

/* MPU_RBAR bit definitions - Reference: Table 4-42 (page 4-40) */
#define MPU_RBAR_REGION_Pos           0U
#define MPU_RBAR_REGION_Msk           (0xFUL << MPU_RBAR_REGION_Pos)

#define MPU_RBAR_VALID_Pos            4U
#define MPU_RBAR_VALID_Msk            (1UL << MPU_RBAR_VALID_Pos)

#define MPU_RBAR_ADDR_Pos             5U
#define MPU_RBAR_ADDR_Msk             (0x7FFFFFFUL << MPU_RBAR_ADDR_Pos)

/*
 * ============================================================================
 * MPU Region Attribute and Size Register (MPU_RASR)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-43 (page 4-41)
 * Address: 0xE000EDA0
 * ============================================================================
 */

#define MPU_RASR                      (*(volatile uint32_t *)(CM4_MPU_BASE_ADDR + 0x010))

/* MPU_RASR bit definitions - Reference: Table 4-43 (page 4-41) */
#define MPU_RASR_ENABLE_Pos           0U
#define MPU_RASR_ENABLE_Msk           (1UL << MPU_RASR_ENABLE_Pos)

#define MPU_RASR_SIZE_Pos             1U
#define MPU_RASR_SIZE_Msk             (0x1FUL << MPU_RASR_SIZE_Pos)

#define MPU_RASR_SRD_Pos              8U
#define MPU_RASR_SRD_Msk              (0xFFUL << MPU_RASR_SRD_Pos)

#define MPU_RASR_B_Pos                16U
#define MPU_RASR_B_Msk                (1UL << MPU_RASR_B_Pos)

#define MPU_RASR_C_Pos                17U
#define MPU_RASR_C_Msk                (1UL << MPU_RASR_C_Pos)

#define MPU_RASR_S_Pos                18U
#define MPU_RASR_S_Msk                (1UL << MPU_RASR_S_Pos)

#define MPU_RASR_TEX_Pos              19U
#define MPU_RASR_TEX_Msk              (7UL << MPU_RASR_TEX_Pos)

#define MPU_RASR_AP_Pos               24U
#define MPU_RASR_AP_Msk               (7UL << MPU_RASR_AP_Pos)

#define MPU_RASR_XN_Pos               28U
#define MPU_RASR_XN_Msk               (1UL << MPU_RASR_XN_Pos)

/*
 * ============================================================================
 * MPU Region Alias Registers
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-38 (page 4-38)
 * ============================================================================
 */

#define MPU_RBAR_A1                   (*(volatile uint32_t *)(CM4_MPU_BASE_ADDR + 0x014))
#define MPU_RASR_A1                   (*(volatile uint32_t *)(CM4_MPU_BASE_ADDR + 0x018))
#define MPU_RBAR_A2                   (*(volatile uint32_t *)(CM4_MPU_BASE_ADDR + 0x01C))
#define MPU_RASR_A2                   (*(volatile uint32_t *)(CM4_MPU_BASE_ADDR + 0x020))
#define MPU_RBAR_A3                   (*(volatile uint32_t *)(CM4_MPU_BASE_ADDR + 0x024))
#define MPU_RASR_A3                   (*(volatile uint32_t *)(CM4_MPU_BASE_ADDR + 0x028))

/*
 * ============================================================================
 * MPU Access Permission Attributes
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-47 (page 4-44)
 * ============================================================================
 */

/* AP field values - Reference: Table 4-47 (page 4-44) */
#define MPU_AP_NO_ACCESS              0x0UL
#define MPU_AP_PRIV_RW                0x1UL
#define MPU_AP_RW                     0x3UL
#define MPU_AP_PRIV_RO                0x5UL
#define MPU_AP_RO                     0x6UL

/*
 * ============================================================================
 * MPU Memory Attributes (TEX, C, B, S)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-45 (page 4-43)
 * ============================================================================
 */

/* Memory type encodings - Reference: Table 4-45 (page 4-43) */
#define MPU_ATTR_STRONGLY_ORDERED     0x00UL
#define MPU_ATTR_SHARED_DEVICE        0x01UL
#define MPU_ATTR_NORMAL_WT            0x02UL
#define MPU_ATTR_NORMAL_WB            0x03UL
#define MPU_ATTR_NORMAL_NONCACHE      0x04UL
#define MPU_ATTR_NONSHARED_DEVICE     0x10UL

/*
 * ============================================================================
 * MPU Size Values
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-44 (page 4-42)
 * ============================================================================
 */

/* SIZE field values - Reference: Table 4-44 (page 4-42) */
#define MPU_SIZE_32B                  4UL
#define MPU_SIZE_64B                  5UL
#define MPU_SIZE_128B                 6UL
#define MPU_SIZE_256B                 7UL
#define MPU_SIZE_512B                 8UL
#define MPU_SIZE_1KB                  9UL
#define MPU_SIZE_2KB                  10UL
#define MPU_SIZE_4KB                  11UL
#define MPU_SIZE_8KB                  12UL
#define MPU_SIZE_16KB                 13UL
#define MPU_SIZE_32KB                 14UL
#define MPU_SIZE_64KB                 15UL
#define MPU_SIZE_128KB                16UL
#define MPU_SIZE_256KB                17UL
#define MPU_SIZE_512KB                18UL
#define MPU_SIZE_1MB                  19UL
#define MPU_SIZE_2MB                  20UL
#define MPU_SIZE_4MB                  21UL
#define MPU_SIZE_8MB                  22UL
#define MPU_SIZE_16MB                 23UL
#define MPU_SIZE_32MB                 24UL
#define MPU_SIZE_64MB                 25UL
#define MPU_SIZE_128MB                26UL
#define MPU_SIZE_256MB                27UL
#define MPU_SIZE_512MB                28UL
#define MPU_SIZE_1GB                  29UL
#define MPU_SIZE_2GB                  30UL
#define MPU_SIZE_4GB                  31UL

/*
 * ============================================================================
 * MPU Function Declarations
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5 (page 4-37)
 * ============================================================================
 */

/**
 * @brief Enable MPU
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.2 (page 4-39)
 */
void cm4_mpu_enable(void);

/**
 * @brief Disable MPU
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.2 (page 4-39)
 */
void cm4_mpu_disable(void);

/**
 * @brief Enable MPU with default memory map for privileged access
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.2 (page 4-39)
 */
void cm4_mpu_enable_with_default_map(void);

/**
 * @brief Select MPU region
 * @param region Region number (0-7)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.3 (page 4-40)
 */
void cm4_mpu_select_region(uint32_t region);

/**
 * @brief Set region base address
 * @param addr Base address (must be aligned to region size)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.4 (page 4-40)
 */
void cm4_mpu_set_region_base(uint32_t addr);

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
void cm4_mpu_set_region_attr(uint32_t size, uint32_t srd, uint32_t attr, uint32_t ap, uint32_t xn, uint32_t enable);

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
void cm4_mpu_configure_region(uint32_t region, uint32_t base, uint32_t size, uint32_t srd, uint32_t attr, uint32_t ap, uint32_t xn);

/**
 * @brief Disable a region
 * @param region Region number (0-7)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.5 (page 4-41)
 */
void cm4_mpu_disable_region(uint32_t region);

/**
 * @brief Get number of supported regions
 * @return Number of regions (should be 8 for Cortex-M4)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.1 (page 4-38)
 */
uint32_t cm4_mpu_get_region_count(void);

/**
 * @brief Check if MPU is present
 * @return 1 if present, 0 if not
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.5.1 (page 4-38)
 */
int cm4_mpu_is_present(void);

#ifdef __cplusplus
}
#endif

#endif /* __CM4_MPU_H__ */
