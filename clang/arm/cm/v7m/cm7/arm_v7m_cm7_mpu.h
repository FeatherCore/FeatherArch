/*
 * arm_v7m_cm7_mpu.h
 * Cortex-M7 Memory Protection Unit (MPU) Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.5 (PMSAv7)
 *            - Protected Memory System Architecture, PMSAv7 on page B3-632
 *            - Section B3.5.1: Relation of the MPU to the system memory map on page B3-632
 *            - Section B3.5.2: Behavior when the MPU is disabled on page B3-632
 *            - Section B3.5.3: PMSAv7-compliant MPU operation on page B3-633
 *            - Section B3.5.4: Register support for PMSAv7 in the SCS on page B3-635
 *            - Section B3.5.5: MPU Type Register, MPU_TYPE on page B3-636
 *            - Section B3.5.6: MPU Control Register, MPU_CTRL on page B3-637
 *            - Section B3.5.7: MPU Region Number Register, MPU_RNR on page B3-639
 *            - Section B3.5.8: MPU Region Base Address Register, MPU_RBAR on page B3-639
 *            - Section B3.5.9: MPU Region Attribute and Size Register, MPU_RASR on page B3-640
 *            - Table B3-12: Memory attribute encoding on page B3-638
 *            - Table B3-14: Access permission encoding on page B3-641
 *            Cortex-M7 Devices Generic User Guide, Chapter 4.6
 *            - Optional Memory Protection Unit on page 4-43
 *            - Section 4.6.1: MPU Type Register on page 4-44
 *            - Section 4.6.2: MPU Control Register on page 4-45
 *            - Section 4.6.3: MPU Region Number Register on page 4-47
 *            - Section 4.6.4: MPU Region Base Address Register on page 4-47
 *            - Section 4.6.5: MPU Region Attribute and Size Register on page 4-48
 *            - Table 4-47: MPU region attributes on page 4-44
 *            - Table 4-48: MPU registers summary on page 4-44
 *            Cortex-M7 Technical Reference Manual, Chapter 6
 *            - Memory Protection Unit on page 6-1
 *            - Section 6.1: About the MPU on page 6-2
 *            - Section 6.2: MPU functional description on page 6-3
 *            - Section 6.3: MPU programmers model on page 6-4
 *
 * @note This file reuses Armv7-M generic MPU definitions.
 */

#ifndef ARM_V7M_CM7_MPU_H
#define ARM_V7M_CM7_MPU_H

#include <stdint.h>
#include "../arm_v7m_mpu.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Compiler Abstraction - Inline Definition
 *============================================================================*/

#if defined(__clang__)
    #define ARM_V7M_CM7_MPU_INLINE static inline __attribute__((always_inline))
#else
    #error "This library requires Clang/LLVM compiler."
#endif

/*============================================================================*
 * Type Aliases
 *============================================================================*/

typedef arm_v7m_mpu_regs_t      arm_v7m_cm7_mpu_regs_t;
typedef arm_v7m_mpu_region_cfg_t arm_v7m_cm7_mpu_region_cfg_t;

/*============================================================================*
 * Constant Aliases - MPU Register Bit Definitions
 *============================================================================*/

/* MPU_TYPE Register */
#define ARM_V7M_CM7_MPU_TYPE_DREGION_Pos    ARM_V7M_MPU_TYPE_DREGION_Pos
#define ARM_V7M_CM7_MPU_TYPE_DREGION_Msk    ARM_V7M_MPU_TYPE_DREGION_Msk
#define ARM_V7M_CM7_MPU_TYPE_IREGION_Pos    ARM_V7M_MPU_TYPE_IREGION_Pos
#define ARM_V7M_CM7_MPU_TYPE_IREGION_Msk    ARM_V7M_MPU_TYPE_IREGION_Msk
#define ARM_V7M_CM7_MPU_TYPE_SEPARATE_Pos   ARM_V7M_MPU_TYPE_SEPARATE_Pos
#define ARM_V7M_CM7_MPU_TYPE_SEPARATE_Msk   ARM_V7M_MPU_TYPE_SEPARATE_Msk

/* MPU_CTRL Register */
#define ARM_V7M_CM7_MPU_CTRL_PRIVDEFENA_Pos ARM_V7M_MPU_CTRL_PRIVDEFENA_Pos
#define ARM_V7M_CM7_MPU_CTRL_PRIVDEFENA_Msk ARM_V7M_MPU_CTRL_PRIVDEFENA_Msk
#define ARM_V7M_CM7_MPU_CTRL_HFNMIENA_Pos   ARM_V7M_MPU_CTRL_HFNMIENA_Pos
#define ARM_V7M_CM7_MPU_CTRL_HFNMIENA_Msk   ARM_V7M_MPU_CTRL_HFNMIENA_Msk
#define ARM_V7M_CM7_MPU_CTRL_ENABLE_Pos     ARM_V7M_MPU_CTRL_ENABLE_Pos
#define ARM_V7M_CM7_MPU_CTRL_ENABLE_Msk     ARM_V7M_MPU_CTRL_ENABLE_Msk

/* MPU_RNR Register */
#define ARM_V7M_CM7_MPU_RNR_REGION_Pos      ARM_V7M_MPU_RNR_REGION_Pos
#define ARM_V7M_CM7_MPU_RNR_REGION_Msk      ARM_V7M_MPU_RNR_REGION_Msk

/* MPU_RBAR Register */
#define ARM_V7M_CM7_MPU_RBAR_ADDR_Pos       ARM_V7M_MPU_RBAR_ADDR_Pos
#define ARM_V7M_CM7_MPU_RBAR_ADDR_Msk       ARM_V7M_MPU_RBAR_ADDR_Msk
#define ARM_V7M_CM7_MPU_RBAR_VALID_Pos      ARM_V7M_MPU_RBAR_VALID_Pos
#define ARM_V7M_CM7_MPU_RBAR_VALID_Msk      ARM_V7M_MPU_RBAR_VALID_Msk
#define ARM_V7M_CM7_MPU_RBAR_REGION_Pos     ARM_V7M_MPU_RBAR_REGION_Pos
#define ARM_V7M_CM7_MPU_RBAR_REGION_Msk     ARM_V7M_MPU_RBAR_REGION_Msk

/* MPU_RASR Register */
#define ARM_V7M_CM7_MPU_RASR_ATTRS_Pos      ARM_V7M_MPU_RASR_ATTRS_Pos
#define ARM_V7M_CM7_MPU_RASR_ATTRS_Msk      ARM_V7M_MPU_RASR_ATTRS_Msk
#define ARM_V7M_CM7_MPU_RASR_XN_Pos         ARM_V7M_MPU_RASR_XN_Pos
#define ARM_V7M_CM7_MPU_RASR_XN_Msk         ARM_V7M_MPU_RASR_XN_Msk
#define ARM_V7M_CM7_MPU_RASR_AP_Pos         ARM_V7M_MPU_RASR_AP_Pos
#define ARM_V7M_CM7_MPU_RASR_AP_Msk         ARM_V7M_MPU_RASR_AP_Msk
#define ARM_V7M_CM7_MPU_RASR_TEX_Pos        ARM_V7M_MPU_RASR_TEX_Pos
#define ARM_V7M_CM7_MPU_RASR_TEX_Msk        ARM_V7M_MPU_RASR_TEX_Msk
#define ARM_V7M_CM7_MPU_RASR_S_Pos          ARM_V7M_MPU_RASR_S_Pos
#define ARM_V7M_CM7_MPU_RASR_S_Msk          ARM_V7M_MPU_RASR_S_Msk
#define ARM_V7M_CM7_MPU_RASR_C_Pos          ARM_V7M_MPU_RASR_C_Pos
#define ARM_V7M_CM7_MPU_RASR_C_Msk          ARM_V7M_MPU_RASR_C_Msk
#define ARM_V7M_CM7_MPU_RASR_B_Pos          ARM_V7M_MPU_RASR_B_Pos
#define ARM_V7M_CM7_MPU_RASR_B_Msk          ARM_V7M_MPU_RASR_B_Msk
#define ARM_V7M_CM7_MPU_RASR_SRD_Pos        ARM_V7M_MPU_RASR_SRD_Pos
#define ARM_V7M_CM7_MPU_RASR_SRD_Msk        ARM_V7M_MPU_RASR_SRD_Msk
#define ARM_V7M_CM7_MPU_RASR_SIZE_Pos       ARM_V7M_MPU_RASR_SIZE_Pos
#define ARM_V7M_CM7_MPU_RASR_SIZE_Msk       ARM_V7M_MPU_RASR_SIZE_Msk
#define ARM_V7M_CM7_MPU_RASR_ENABLE_Pos     ARM_V7M_MPU_RASR_ENABLE_Pos
#define ARM_V7M_CM7_MPU_RASR_ENABLE_Msk     ARM_V7M_MPU_RASR_ENABLE_Msk

/*============================================================================*
 * Constant Aliases - Region Size Definitions
 *============================================================================*/

#define ARM_V7M_CM7_MPU_REGION_SIZE_32B     ARM_V7M_MPU_REGION_SIZE_32B
#define ARM_V7M_CM7_MPU_REGION_SIZE_64B     ARM_V7M_MPU_REGION_SIZE_64B
#define ARM_V7M_CM7_MPU_REGION_SIZE_128B    ARM_V7M_MPU_REGION_SIZE_128B
#define ARM_V7M_CM7_MPU_REGION_SIZE_256B    ARM_V7M_MPU_REGION_SIZE_256B
#define ARM_V7M_CM7_MPU_REGION_SIZE_512B    ARM_V7M_MPU_REGION_SIZE_512B
#define ARM_V7M_CM7_MPU_REGION_SIZE_1KB     ARM_V7M_MPU_REGION_SIZE_1KB
#define ARM_V7M_CM7_MPU_REGION_SIZE_2KB     ARM_V7M_MPU_REGION_SIZE_2KB
#define ARM_V7M_CM7_MPU_REGION_SIZE_4KB     ARM_V7M_MPU_REGION_SIZE_4KB
#define ARM_V7M_CM7_MPU_REGION_SIZE_8KB     ARM_V7M_MPU_REGION_SIZE_8KB
#define ARM_V7M_CM7_MPU_REGION_SIZE_16KB    ARM_V7M_MPU_REGION_SIZE_16KB
#define ARM_V7M_CM7_MPU_REGION_SIZE_32KB    ARM_V7M_MPU_REGION_SIZE_32KB
#define ARM_V7M_CM7_MPU_REGION_SIZE_64KB    ARM_V7M_MPU_REGION_SIZE_64KB
#define ARM_V7M_CM7_MPU_REGION_SIZE_128KB   ARM_V7M_MPU_REGION_SIZE_128KB
#define ARM_V7M_CM7_MPU_REGION_SIZE_256KB   ARM_V7M_MPU_REGION_SIZE_256KB
#define ARM_V7M_CM7_MPU_REGION_SIZE_512KB   ARM_V7M_MPU_REGION_SIZE_512KB
#define ARM_V7M_CM7_MPU_REGION_SIZE_1MB     ARM_V7M_MPU_REGION_SIZE_1MB
#define ARM_V7M_CM7_MPU_REGION_SIZE_2MB     ARM_V7M_MPU_REGION_SIZE_2MB
#define ARM_V7M_CM7_MPU_REGION_SIZE_4MB     ARM_V7M_MPU_REGION_SIZE_4MB
#define ARM_V7M_CM7_MPU_REGION_SIZE_8MB     ARM_V7M_MPU_REGION_SIZE_8MB
#define ARM_V7M_CM7_MPU_REGION_SIZE_16MB    ARM_V7M_MPU_REGION_SIZE_16MB
#define ARM_V7M_CM7_MPU_REGION_SIZE_32MB    ARM_V7M_MPU_REGION_SIZE_32MB
#define ARM_V7M_CM7_MPU_REGION_SIZE_64MB    ARM_V7M_MPU_REGION_SIZE_64MB
#define ARM_V7M_CM7_MPU_REGION_SIZE_128MB   ARM_V7M_MPU_REGION_SIZE_128MB
#define ARM_V7M_CM7_MPU_REGION_SIZE_256MB   ARM_V7M_MPU_REGION_SIZE_256MB
#define ARM_V7M_CM7_MPU_REGION_SIZE_512MB   ARM_V7M_MPU_REGION_SIZE_512MB
#define ARM_V7M_CM7_MPU_REGION_SIZE_1GB     ARM_V7M_MPU_REGION_SIZE_1GB
#define ARM_V7M_CM7_MPU_REGION_SIZE_2GB     ARM_V7M_MPU_REGION_SIZE_2GB
#define ARM_V7M_CM7_MPU_REGION_SIZE_4GB     ARM_V7M_MPU_REGION_SIZE_4GB

/*============================================================================*
 * Constant Aliases - Access Permission Definitions
 *============================================================================*/

#define ARM_V7M_CM7_MPU_AP_NONE             ARM_V7M_MPU_AP_NONE
#define ARM_V7M_CM7_MPU_AP_PRIV_RW          ARM_V7M_MPU_AP_PRIV_RW
#define ARM_V7M_CM7_MPU_AP_PRIV_RW_USER_RO  ARM_V7M_MPU_AP_PRIV_RW_USER_RO
#define ARM_V7M_CM7_MPU_AP_FULL_ACCESS      ARM_V7M_MPU_AP_FULL_ACCESS
#define ARM_V7M_CM7_MPU_AP_PRIV_RO          ARM_V7M_MPU_AP_PRIV_RO
#define ARM_V7M_CM7_MPU_AP_RO               ARM_V7M_MPU_AP_RO

/*============================================================================*
 * Constant Aliases - Memory Attribute Definitions
 *============================================================================*/

#define ARM_V7M_CM7_MPU_ATTR_STRONGLY_ORDERED   ARM_V7M_MPU_ATTR_STRONGLY_ORDERED
#define ARM_V7M_CM7_MPU_ATTR_DEVICE_SHARED      ARM_V7M_MPU_ATTR_DEVICE_SHARED
#define ARM_V7M_CM7_MPU_ATTR_DEVICE             ARM_V7M_MPU_ATTR_DEVICE
#define ARM_V7M_CM7_MPU_ATTR_NORMAL             ARM_V7M_MPU_ATTR_NORMAL
#define ARM_V7M_CM7_MPU_ATTR_NORMAL_WB_WRA      ARM_V7M_MPU_ATTR_NORMAL_WB_WRA
#define ARM_V7M_CM7_MPU_ATTR_NORMAL_WT          ARM_V7M_MPU_ATTR_NORMAL_WT
#define ARM_V7M_CM7_MPU_ATTR_NORMAL_WB          ARM_V7M_MPU_ATTR_NORMAL_WB

/*============================================================================*
 * Constant Aliases - Shareable and Execute Never Definitions
 *============================================================================*/

#define ARM_V7M_CM7_MPU_SHAREABLE           ARM_V7M_MPU_SHAREABLE
#define ARM_V7M_CM7_MPU_NON_SHAREABLE       ARM_V7M_MPU_NON_SHAREABLE
#define ARM_V7M_CM7_MPU_XN                  ARM_V7M_MPU_XN
#define ARM_V7M_CM7_MPU_EXEC_OK             ARM_V7M_MPU_EXEC_OK

/*============================================================================*
 * Constant Aliases - Predefined Attribute Combinations
 *============================================================================*/

#define ARM_V7M_CM7_MPU_ATTR_NORMAL_CACHEABLE     ARM_V7M_MPU_ATTR_NORMAL_CACHEABLE
#define ARM_V7M_CM7_MPU_ATTR_NORMAL_CACHEABLE_XN  ARM_V7M_MPU_ATTR_NORMAL_CACHEABLE_XN
#define ARM_V7M_CM7_MPU_ATTR_NORMAL_NONCACHE      ARM_V7M_MPU_ATTR_NORMAL_NONCACHE
#define ARM_V7M_CM7_MPU_ATTR_DEVICE               ARM_V7M_MPU_ATTR_DEVICE
#define ARM_V7M_CM7_MPU_ATTR_DEVICE_NONSHARE      ARM_V7M_MPU_ATTR_DEVICE_NONSHARE
#define ARM_V7M_CM7_MPU_ATTR_STRONGLY_ORDERED     ARM_V7M_MPU_ATTR_STRONGLY_ORDERED
#define ARM_V7M_CM7_MPU_ATTR_FLASH                ARM_V7M_MPU_ATTR_FLASH
#define ARM_V7M_CM7_MPU_ATTR_SRAM                 ARM_V7M_MPU_ATTR_SRAM
#define ARM_V7M_CM7_MPU_ATTR_PERIPHERAL           ARM_V7M_MPU_ATTR_PERIPHERAL

/*============================================================================*
 * Constant Aliases - Enable Flags
 *============================================================================*/

#define ARM_V7M_CM7_MPU_ENABLE_PRIVDEFENA   ARM_V7M_MPU_ENABLE_PRIVDEFENA
#define ARM_V7M_CM7_MPU_ENABLE_HFNMIENA     ARM_V7M_MPU_ENABLE_HFNMIENA

/*============================================================================*
 * CM7 Specific - MPU Alias Register Offsets
 * Reference: Cortex-M7 Technical Reference Manual, Section 6.3
 *            - MPU alias register support on page 6-4
 *============================================================================*/

#define ARM_V7M_CM7_MPU_RBAR_A1_OFFSET      ARM_V7M_MPU_RBAR_A1_OFFSET
#define ARM_V7M_CM7_MPU_RASR_A1_OFFSET      ARM_V7M_MPU_RASR_A1_OFFSET
#define ARM_V7M_CM7_MPU_RBAR_A2_OFFSET      ARM_V7M_MPU_RBAR_A2_OFFSET
#define ARM_V7M_CM7_MPU_RASR_A2_OFFSET      ARM_V7M_MPU_RASR_A2_OFFSET
#define ARM_V7M_CM7_MPU_RBAR_A3_OFFSET      ARM_V7M_MPU_RBAR_A3_OFFSET
#define ARM_V7M_CM7_MPU_RASR_A3_OFFSET      ARM_V7M_MPU_RASR_A3_OFFSET

/*============================================================================*
 * Helper Macro Aliases
 *============================================================================*/

#define ARM_V7M_CM7_MPU_BUILD_ATTR(ap, tex, s, c, b, xn) \
    ARM_V7M_MPU_BUILD_ATTR(ap, tex, s, c, b, xn)

#define ARM_V7M_CM7_MPU_BUILD_RASR(attrs, srd, size, enable) \
    ARM_V7M_MPU_BUILD_RASR(attrs, srd, size, enable)

#define ARM_V7M_CM7_MPU_BUILD_RBAR(addr, region) \
    ARM_V7M_MPU_BUILD_RBAR(addr, region)

/*============================================================================*
 * Inline Functions - MPU Basic Operations (Aliased from generic)
 *============================================================================*/

/**
 * @brief Check if MPU is present
 * @return 1 if MPU is present, 0 otherwise
 */
ARM_V7M_CM7_MPU_INLINE uint32_t arm_v7m_cm7_mpu_is_present(void)
{
    return arm_v7m_mpu_is_present();
}

/**
 * @brief Get the number of MPU regions supported
 * @return Number of supported regions (0 if MPU not implemented)
 */
ARM_V7M_CM7_MPU_INLINE uint32_t arm_v7m_cm7_mpu_get_region_count(void)
{
    return arm_v7m_mpu_get_region_count();
}

/**
 * @brief Select the MPU region to configure
 * @param region_num Region number to select (0 to region_count-1)
 */
ARM_V7M_CM7_MPU_INLINE void arm_v7m_cm7_mpu_select_region(uint32_t region_num)
{
    arm_v7m_mpu_select_region(region_num);
}

/**
 * @brief Calculate region size from SIZE field value
 * @param size_code SIZE field value (4-31)
 * @return Region size in bytes
 */
ARM_V7M_CM7_MPU_INLINE uint32_t arm_v7m_cm7_mpu_calc_region_size(uint32_t size_code)
{
    return arm_v7m_mpu_calc_region_size(size_code);
}

/**
 * @brief Check if address is aligned to specified size
 * @param addr Address to check
 * @param size Alignment size (must be power of 2)
 * @return 1 if aligned, 0 if not
 */
ARM_V7M_CM7_MPU_INLINE uint32_t arm_v7m_cm7_mpu_is_aligned(uint32_t addr, uint32_t size)
{
    return arm_v7m_mpu_is_aligned(addr, size);
}

/**
 * @brief Validate region configuration
 * @param base_addr Region base address
 * @param size_code Region size code (ARM_V7M_CM7_MPU_REGION_SIZE_*)
 * @return 1 if valid, 0 if invalid
 */
ARM_V7M_CM7_MPU_INLINE uint32_t arm_v7m_cm7_mpu_validate_region_cfg(uint32_t base_addr, uint32_t size_code)
{
    return arm_v7m_mpu_validate_region_cfg(base_addr, size_code);
}

/**
 * @brief Get MPU Type Register
 * @return MPU_TYPE value
 */
ARM_V7M_CM7_MPU_INLINE uint32_t arm_v7m_cm7_mpu_get_type(void)
{
    return arm_v7m_mpu_get_type();
}

/**
 * @brief Get MPU Control Register
 * @return MPU_CTRL value
 */
ARM_V7M_CM7_MPU_INLINE uint32_t arm_v7m_cm7_mpu_get_ctrl(void)
{
    return arm_v7m_mpu_get_ctrl();
}

/**
 * @brief Set MPU Control Register
 * @param value Value to write
 */
ARM_V7M_CM7_MPU_INLINE void arm_v7m_cm7_mpu_set_ctrl(uint32_t value)
{
    arm_v7m_mpu_set_ctrl(value);
}

/**
 * @brief Get MPU Region Number Register
 * @return MPU_RNR value
 */
ARM_V7M_CM7_MPU_INLINE uint32_t arm_v7m_cm7_mpu_get_rnr(void)
{
    return arm_v7m_mpu_get_rnr();
}

/**
 * @brief Set MPU Region Number Register
 * @param value Value to write
 */
ARM_V7M_CM7_MPU_INLINE void arm_v7m_cm7_mpu_set_rnr(uint32_t value)
{
    arm_v7m_mpu_set_rnr(value);
}

/**
 * @brief Get MPU Region Base Address Register
 * @return MPU_RBAR value
 */
ARM_V7M_CM7_MPU_INLINE uint32_t arm_v7m_cm7_mpu_get_rbar(void)
{
    return arm_v7m_mpu_get_rbar();
}

/**
 * @brief Set MPU Region Base Address Register
 * @param value Value to write
 */
ARM_V7M_CM7_MPU_INLINE void arm_v7m_cm7_mpu_set_rbar(uint32_t value)
{
    arm_v7m_mpu_set_rbar(value);
}

/**
 * @brief Get MPU Region Attribute and Size Register
 * @return MPU_RASR value
 */
ARM_V7M_CM7_MPU_INLINE uint32_t arm_v7m_cm7_mpu_get_rasr(void)
{
    return arm_v7m_mpu_get_rasr();
}

/**
 * @brief Set MPU Region Attribute and Size Register
 * @param value Value to write
 */
ARM_V7M_CM7_MPU_INLINE void arm_v7m_cm7_mpu_set_rasr(uint32_t value)
{
    arm_v7m_mpu_set_rasr(value);
}

/*============================================================================*
 * CM7 Specific - MPU Alias Register Access
 * Reference: Cortex-M7 Technical Reference Manual, Section 6.3
 *            - MPU alias registers (MPU_RBAR_A1/2/3, MPU_RASR_A1/2/3) on page 6-4
 *            - These alias registers enable efficient multi-region programming
 *              without changing MPU_RNR between each region configuration.
 *============================================================================*/

/**
 * @brief Get MPU Region Base Address Alias Register 1
 * @return MPU_RBAR_A1 value
 */
ARM_V7M_CM7_MPU_INLINE uint32_t arm_v7m_cm7_mpu_get_rbar_a1(void)
{
    return *(volatile uint32_t *)(ARM_V7M_MPU_BASE + ARM_V7M_CM7_MPU_RBAR_A1_OFFSET);
}

/**
 * @brief Set MPU Region Base Address Alias Register 1
 * @param value Value to write
 */
ARM_V7M_CM7_MPU_INLINE void arm_v7m_cm7_mpu_set_rbar_a1(uint32_t value)
{
    *(volatile uint32_t *)(ARM_V7M_MPU_BASE + ARM_V7M_CM7_MPU_RBAR_A1_OFFSET) = value;
}

/**
 * @brief Get MPU Region Attribute and Size Alias Register 1
 * @return MPU_RASR_A1 value
 */
ARM_V7M_CM7_MPU_INLINE uint32_t arm_v7m_cm7_mpu_get_rasr_a1(void)
{
    return *(volatile uint32_t *)(ARM_V7M_MPU_BASE + ARM_V7M_CM7_MPU_RASR_A1_OFFSET);
}

/**
 * @brief Set MPU Region Attribute and Size Alias Register 1
 * @param value Value to write
 */
ARM_V7M_CM7_MPU_INLINE void arm_v7m_cm7_mpu_set_rasr_a1(uint32_t value)
{
    *(volatile uint32_t *)(ARM_V7M_MPU_BASE + ARM_V7M_CM7_MPU_RASR_A1_OFFSET) = value;
}

/**
 * @brief Get MPU Region Base Address Alias Register 2
 * @return MPU_RBAR_A2 value
 */
ARM_V7M_CM7_MPU_INLINE uint32_t arm_v7m_cm7_mpu_get_rbar_a2(void)
{
    return *(volatile uint32_t *)(ARM_V7M_MPU_BASE + ARM_V7M_CM7_MPU_RBAR_A2_OFFSET);
}

/**
 * @brief Set MPU Region Base Address Alias Register 2
 * @param value Value to write
 */
ARM_V7M_CM7_MPU_INLINE void arm_v7m_cm7_mpu_set_rbar_a2(uint32_t value)
{
    *(volatile uint32_t *)(ARM_V7M_MPU_BASE + ARM_V7M_CM7_MPU_RBAR_A2_OFFSET) = value;
}

/**
 * @brief Get MPU Region Attribute and Size Alias Register 2
 * @return MPU_RASR_A2 value
 */
ARM_V7M_CM7_MPU_INLINE uint32_t arm_v7m_cm7_mpu_get_rasr_a2(void)
{
    return *(volatile uint32_t *)(ARM_V7M_MPU_BASE + ARM_V7M_CM7_MPU_RASR_A2_OFFSET);
}

/**
 * @brief Set MPU Region Attribute and Size Alias Register 2
 * @param value Value to write
 */
ARM_V7M_CM7_MPU_INLINE void arm_v7m_cm7_mpu_set_rasr_a2(uint32_t value)
{
    *(volatile uint32_t *)(ARM_V7M_MPU_BASE + ARM_V7M_CM7_MPU_RASR_A2_OFFSET) = value;
}

/**
 * @brief Get MPU Region Base Address Alias Register 3
 * @return MPU_RBAR_A3 value
 */
ARM_V7M_CM7_MPU_INLINE uint32_t arm_v7m_cm7_mpu_get_rbar_a3(void)
{
    return *(volatile uint32_t *)(ARM_V7M_MPU_BASE + ARM_V7M_CM7_MPU_RBAR_A3_OFFSET);
}

/**
 * @brief Set MPU Region Base Address Alias Register 3
 * @param value Value to write
 */
ARM_V7M_CM7_MPU_INLINE void arm_v7m_cm7_mpu_set_rbar_a3(uint32_t value)
{
    *(volatile uint32_t *)(ARM_V7M_MPU_BASE + ARM_V7M_CM7_MPU_RBAR_A3_OFFSET) = value;
}

/**
 * @brief Get MPU Region Attribute and Size Alias Register 3
 * @return MPU_RASR_A3 value
 */
ARM_V7M_CM7_MPU_INLINE uint32_t arm_v7m_cm7_mpu_get_rasr_a3(void)
{
    return *(volatile uint32_t *)(ARM_V7M_MPU_BASE + ARM_V7M_CM7_MPU_RASR_A3_OFFSET);
}

/**
 * @brief Set MPU Region Attribute and Size Alias Register 3
 * @param value Value to write
 */
ARM_V7M_CM7_MPU_INLINE void arm_v7m_cm7_mpu_set_rasr_a3(uint32_t value)
{
    *(volatile uint32_t *)(ARM_V7M_MPU_BASE + ARM_V7M_CM7_MPU_RASR_A3_OFFSET) = value;
}

/**
 * @brief Configure multiple MPU regions using alias registers (up to 4 regions)
 *
 * According to ARMv7-M Architecture Reference Manual, Section B3.5.4:
 * - Alias registers allow efficient programming of up to 4 regions
 * - Write RBAR, then RASR, RBAR_A1, RASR_A1, RBAR_A2, RASR_A2, RBAR_A3, RASR_A3
 * - The region number in RBAR.REGION is incremented automatically after each write
 *
 * @param region_num Starting region number (0-15)
 * @param rbar_values Array of 1-4 RBAR values (base addresses with VALID and REGION bits)
 * @param rasr_values Array of 1-4 RASR values (attributes and size)
 * @param count Number of regions to configure (1-4)
 */
ARM_V7M_CM7_MPU_INLINE void arm_v7m_cm7_mpu_set_regions_alias(uint32_t region_num,
                                                                const uint32_t *rbar_values,
                                                                const uint32_t *rasr_values,
                                                                uint32_t count)
{
    if (count == 0U || count > 4U || rbar_values == (void *)0 || rasr_values == (void *)0) {
        return;
    }

    /* Set starting region number in RNR */
    arm_v7m_cm7_mpu_set_rnr(region_num);

    /* Write first region (RBAR, RASR) */
    arm_v7m_cm7_mpu_set_rbar(rbar_values[0]);
    arm_v7m_cm7_mpu_set_rasr(rasr_values[0]);

    /* Write additional regions using alias registers if count > 1 */
    if (count > 1U) {
        arm_v7m_cm7_mpu_set_rbar_a1(rbar_values[1]);
        arm_v7m_cm7_mpu_set_rasr_a1(rasr_values[1]);
    }
    if (count > 2U) {
        arm_v7m_cm7_mpu_set_rbar_a2(rbar_values[2]);
        arm_v7m_cm7_mpu_set_rasr_a2(rasr_values[2]);
    }
    if (count > 3U) {
        arm_v7m_cm7_mpu_set_rbar_a3(rbar_values[3]);
        arm_v7m_cm7_mpu_set_rasr_a3(rasr_values[3]);
    }
}

/*============================================================================*
 * Non-Inline Functions - Complex MPU Operations
 *============================================================================*/

/**
 * @brief Enable the MPU with specified control flags
 * @param flags Combination of ARM_V7M_CM7_MPU_ENABLE_PRIVDEFENA and/or
 *              ARM_V7M_CM7_MPU_ENABLE_HFNMIENA
 * @note DSB and ISB barriers are required to ensure MPU configuration
 *       takes effect before subsequent memory accesses.
 */
void arm_v7m_cm7_mpu_enable(uint32_t flags);

/**
 * @brief Disable the MPU
 * @note DSB and ISB barriers are required to ensure all pending memory
 *       accesses complete before the MPU is disabled.
 */
void arm_v7m_cm7_mpu_disable(void);

/**
 * @brief Get the minimum supported region size
 * @return Minimum region size in bytes
 */
uint32_t arm_v7m_cm7_mpu_get_min_region_size(void);

/**
 * @brief Calculate the SIZE field value for a given region size
 * @param size Region size in bytes (must be power of 2, >= 32)
 * @return SIZE field value (4-31), or -1 if invalid size
 */
int arm_v7m_cm7_mpu_calc_size_code(uint32_t size);

/**
 * @brief Configure the currently selected MPU region
 * @param base_addr Region base address (must be aligned to region size)
 * @param size_code SIZE field value (4-31, for 32 bytes to 4GB)
 * @param attrs Region attributes (AP, TEX, S, C, B, XN fields combined)
 */
void arm_v7m_cm7_mpu_set_region(uint32_t base_addr, uint32_t size_code, uint32_t attrs);

/**
 * @brief Configure a specific MPU region with extended options
 * @param region_num Region number to configure (0-15)
 * @param base_addr Region base address (must be aligned to region size)
 * @param size_code SIZE field value (4-31)
 * @param attrs Region attributes (AP, TEX, S, C, B, XN fields combined)
 * @param srd Subregion disable bits (8 bits, only valid for regions >= 256 bytes)
 */
void arm_v7m_cm7_mpu_set_region_ex(uint32_t region_num, uint32_t base_addr,
                                    uint32_t size_code, uint32_t attrs, uint32_t srd);

/**
 * @brief Configure multiple MPU regions using alias registers
 * @param regions Array of region configurations
 * @param count Number of regions to configure (1-4)
 */
void arm_v7m_cm7_mpu_set_regions(const arm_v7m_cm7_mpu_region_cfg_t *regions, uint32_t count);

/**
 * @brief Disable a specific MPU region
 * @param region_num Region number to disable
 */
void arm_v7m_cm7_mpu_disable_region(uint32_t region_num);

/**
 * @brief Get MemManage fault status
 * @return MMFSR value (8-bit status)
 */
uint32_t arm_v7m_cm7_mpu_get_fault_status(void);

/**
 * @brief Get MemManage fault address
 * @return Fault address
 */
uint32_t arm_v7m_cm7_mpu_get_fault_address(void);

/**
 * @brief Clear MemManage fault status
 */
void arm_v7m_cm7_mpu_clear_fault_status(void);

/**
 * @brief Check if fault address is valid
 * @return 1 if MMFAR contains valid fault address, 0 otherwise
 */
uint32_t arm_v7m_cm7_mpu_fault_addr_valid(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM7_MPU_H */
