/*
 * arm_v7m_mpu.c
 * Memory Protection Unit (MPU) Implementation
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.5 (PMSAv7)
 * 
 * This file implements non-inline functions of complex MPU operations.
 * Simple register access functions are implemented as static inline in the header.
 */

#include "arm_v7m_mpu.h"
#include "arm_v7m_scb.h"

/*============================================================================*
 * MPU Enable/Disable
 *============================================================================*/

/**
 * @brief Enable the MPU with specified control flags
 * @param flags Combination of ARM_V7M_MPU_ENABLE_PRIVDEFENA and/or
 *              ARM_V7M_MPU_ENABLE_HFNMIENA
 * @note DSB and ISB barriers are required to ensure MPU configuration
 *       takes effect before subsequent memory accesses.
 */
void arm_v7m_mpu_enable(uint32_t flags)
{
    uint32_t ctrl;

    /* Build control register value with ENABLE bit set */
    ctrl = ARM_V7M_MPU_CTRL_ENABLE_Msk | (flags & (ARM_V7M_MPU_CTRL_PRIVDEFENA_Msk |
                                                  ARM_V7M_MPU_CTRL_HFNMIENA_Msk));

    MPU->CTRL = ctrl;

    /* Data Synchronization Barrier to ensure write completes */
    __asm__ volatile ("dsb" ::: "memory");
    /* Instruction Synchronization Barrier to ensure subsequent instructions
     * use the new MPU settings */
    __asm__ volatile ("isb" ::: "memory");
}

/**
 * @brief Disable the MPU
 * @note DSB and ISB barriers are required to ensure all pending memory
 *       accesses complete before the MPU is disabled.
 */
void arm_v7m_mpu_disable(void)
{
    /* Data Synchronization Barrier to complete pending memory accesses */
    __asm__ volatile ("dsb" ::: "memory");

    /* Clear ENABLE bit */
    MPU->CTRL = 0U;

    /* Instruction Synchronization Barrier to ensure subsequent instructions
     * use the default memory map */
    __asm__ volatile ("isb" ::: "memory");
}

/*============================================================================*
 * MPU Capability Query
 *============================================================================*/

/**
 * @brief Get the minimum supported region size
 * @return Minimum region size in bytes
 * @note Software can find the minimum size by writing all ones to
 *       MPU_RBAR[31:5] and reading back the value.
 */
uint32_t arm_v7m_mpu_get_min_region_size(void)
{
    uint32_t original_rnr;
    uint32_t original_rbar;
    uint32_t test_value;
    uint32_t min_size;
    int trailing_zeros;

    /* Save current region selection */
    original_rnr = MPU->RNR;

    /* Select region 0 for test */
    MPU->RNR = 0U;
    original_rbar = MPU->RBAR;

    /* Write all ones to ADDR field (bits [31:5]) */
    MPU->RBAR = ARM_V7M_MPU_RBAR_ADDR_Msk;

    /* Read back to see what was actually stored */
    test_value = (MPU->RBAR & ARM_V7M_MPU_RBAR_ADDR_Msk) >> ARM_V7M_MPU_RBAR_ADDR_Pos;

    /* Restore original values */
    MPU->RBAR = original_rbar;
    MPU->RNR = original_rnr;

    /* Count trailing zeros to determine minimum alignment */
    trailing_zeros = 0;
    while ((test_value & 1U) == 0U && trailing_zeros < 27) {
        test_value >>= 1U;
        trailing_zeros++;
    }

    /* Minimum region size is 2^5 = 32 bytes, plus trailing zeros */
    min_size = 1U << (5U + (uint32_t)trailing_zeros);

    return min_size;
}

/*============================================================================*
 * Region Configuration
 *============================================================================*/

/**
 * @brief Calculate the SIZE field value for a given region size
 * @param size Region size in bytes (must be power of 2, >= 32)
 * @return SIZE field value (4-31), or -1 if invalid size
 * @note Region size in bytes = 2^(SIZE+1)
 */
int arm_v7m_mpu_calc_size_code(uint32_t size)
{
    int size_code;

    /* Minimum size is 32 bytes */
    if (size < 32U) {
        return -1;
    }

    /* Check if size is power of 2 */
    if ((size & (size - 1U)) != 0U) {
        return -1;
    }

    /* Calculate SIZE field: size = 2^(SIZE+1) */
    size_code = 0;
    while (size > 1U) {
        size >>= 1U;
        size_code++;
    }

    /* SIZE field is size_code - 1 */
    size_code = size_code - 1;

    /* Valid range is 4 to 31 (32 bytes to 4GB) */
    if (size_code < 4 || size_code > 31) {
        return -1;
    }

    return size_code;
}

/**
 * @brief Configure the currently selected MPU region
 * @param base_addr Region base address (must be aligned to region size)
 * @param size_code SIZE field value (4-31, for 32 bytes to 4GB)
 * @param attrs Region attributes (AP, TEX, S, C, B, XN fields combined)
 */
void arm_v7m_mpu_set_region(uint32_t base_addr, uint32_t size_code, uint32_t attrs)
{
    uint32_t rasr;

    /* Configure base address - ADDR field is bits [31:5] */
    MPU->RBAR = base_addr & ARM_V7M_MPU_RBAR_ADDR_Msk;

    /* Build RASR value:
     * - attrs contains XN, AP, TEX, S, C, B fields in correct positions
     * - size_code is SIZE field value (bits [5:1])
     * - ENABLE bit set to enable the region
     */
    rasr = (attrs & ARM_V7M_MPU_RASR_ATTRS_Msk) |
           ((size_code << ARM_V7M_MPU_RASR_SIZE_Pos) & ARM_V7M_MPU_RASR_SIZE_Msk) |
           ARM_V7M_MPU_RASR_ENABLE_Msk;

    MPU->RASR = rasr;
}

/**
 * @brief Configure a specific MPU region with extended options
 * @param region_num Region number to configure (0-15)
 * @param base_addr Region base address (must be aligned to region size)
 * @param size_code SIZE field value (4-31)
 * @param attrs Region attributes (AP, TEX, S, C, B, XN fields combined)
 * @param srd Subregion disable bits (8 bits, only valid for regions >= 256 bytes)
 * @note This function uses MPU_RBAR.VALID bit to update a specific region
 *       without first writing to MPU_RNR.
 */
void arm_v7m_mpu_set_region_ex(uint32_t region_num, uint32_t base_addr,
                                uint32_t size_code, uint32_t attrs, uint32_t srd)
{
    uint32_t rbar;
    uint32_t rasr;

    /* Build RBAR with VALID bit set to update specified region:
     * - VALID=1: Use REGION field to specify region number
     * - ADDR: Base address bits [31:5]
     * - REGION: Region number bits [3:0]
     */
    rbar = (base_addr & ARM_V7M_MPU_RBAR_ADDR_Msk) |
           ARM_V7M_MPU_RBAR_VALID_Msk |
           (region_num & ARM_V7M_MPU_RBAR_REGION_Msk);

    MPU->RBAR = rbar;

    /* Build RASR value with subregion disable bits */
    rasr = (attrs & ARM_V7M_MPU_RASR_ATTRS_Msk) |
           ((srd << ARM_V7M_MPU_RASR_SRD_Pos) & ARM_V7M_MPU_RASR_SRD_Msk) |
           ((size_code << ARM_V7M_MPU_RASR_SIZE_Pos) & ARM_V7M_MPU_RASR_SIZE_Msk) |
           ARM_V7M_MPU_RASR_ENABLE_Msk;

    MPU->RASR = rasr;
}

/*============================================================================*
 * Multi-Region Configuration (Alias Registers)
 *============================================================================*/

/**
 * @brief Configure multiple MPU regions using alias registers
 * @param regions Array of region configurations
 * @param count Number of regions to configure (1-4)
 * @note This function uses MPU alias registers (MPU_RBAR_A1/2/3 and
 *       MPU_RASR_A1/2/3) to efficiently configure up to 4 regions.
 *       This is useful for context switching or initial setup.
 */
void arm_v7m_mpu_set_regions(const arm_v7m_mpu_region_cfg_t *regions, uint32_t count)
{
    volatile uint32_t *rbar_alias[4];
    volatile uint32_t *rasr_alias[4];
    uint32_t i;
    uint32_t rbar;
    uint32_t rasr;

    /* Alias register addresses */
    rbar_alias[0] = &MPU->RBAR;
    rbar_alias[1] = (volatile uint32_t *)(ARM_V7M_MPU_BASE + ARM_V7M_MPU_RBAR_A1_OFFSET);
    rbar_alias[2] = (volatile uint32_t *)(ARM_V7M_MPU_BASE + ARM_V7M_MPU_RBAR_A2_OFFSET);
    rbar_alias[3] = (volatile uint32_t *)(ARM_V7M_MPU_BASE + ARM_V7M_MPU_RBAR_A3_OFFSET);

    rasr_alias[0] = &MPU->RASR;
    rasr_alias[1] = (volatile uint32_t *)(ARM_V7M_MPU_BASE + ARM_V7M_MPU_RASR_A1_OFFSET);
    rasr_alias[2] = (volatile uint32_t *)(ARM_V7M_MPU_BASE + ARM_V7M_MPU_RASR_A2_OFFSET);
    rasr_alias[3] = (volatile uint32_t *)(ARM_V7M_MPU_BASE + ARM_V7M_MPU_RASR_A3_OFFSET);

    /* Limit to maximum 4 regions */
    if (count > 4U) {
        count = 4U;
    }

    /* Configure each region using alias registers */
    for (i = 0U; i < count; i++) {
        /* Build RBAR with VALID bit for regions 1-3 */
        if (i == 0U) {
            /* First region: don't use VALID bit, select via RNR */
            MPU->RNR = regions[i].base_addr & ARM_V7M_MPU_RNR_REGION_Msk;
            rbar = regions[i].base_addr & ARM_V7M_MPU_RBAR_ADDR_Msk;
        } else {
            /* Subsequent regions: use VALID bit to specify region number */
            rbar = (regions[i].base_addr & ARM_V7M_MPU_RBAR_ADDR_Msk) |
                   ARM_V7M_MPU_RBAR_VALID_Msk |
                   (regions[i].base_addr & ARM_V7M_MPU_RBAR_REGION_Msk);
        }

        /* Build RASR value */
        rasr = (regions[i].attrs & ARM_V7M_MPU_RASR_ATTRS_Msk) |
               ((regions[i].srd << ARM_V7M_MPU_RASR_SRD_Pos) & ARM_V7M_MPU_RASR_SRD_Msk) |
               ((regions[i].size_code << ARM_V7M_MPU_RASR_SIZE_Pos) & ARM_V7M_MPU_RASR_SIZE_Msk);

        if (regions[i].enable) {
            rasr |= ARM_V7M_MPU_RASR_ENABLE_Msk;
        }

        /* Write to alias registers */
        *rbar_alias[i] = rbar;
        *rasr_alias[i] = rasr;
    }

    /* Memory barrier to ensure configuration takes effect */
    __asm__ volatile ("dsb" ::: "memory");
}

/*============================================================================*
 * Region Disable
 *============================================================================*/

/**
 * @brief Disable a specific MPU region
 * @param region_num Region number to disable
 * @note Per ARMv7-M Architecture Reference Manual, Section B3.5.4:
 *       "All MPU_RASR registers must be programmed as either enabled or
 *       disabled before enabling the MPU using the MPU_CTRL register."
 */
void arm_v7m_mpu_disable_region(uint32_t region_num)
{
    /* Select the region */
    arm_v7m_mpu_select_region(region_num);

    /* Clear ENABLE bit to disable the region */
    MPU->RASR = 0U;
}

/*============================================================================*
 * MemManage Fault Status Functions
 *============================================================================*/

/**
 * @brief Get MemManage fault status
 * @return MMFSR value (8-bit status)
 * @note Reads the MMFSR which is part of CFSR.
 */
uint32_t arm_v7m_mpu_get_fault_status(void)
{
    return SCB->CFSR & SCB_CFSR_MMFSR_Msk;
}

/**
 * @brief Get MemManage fault address
 * @return Fault address
 * @note Reads the MMFAR. Only valid if MMARVALID bit is set in MMFSR.
 */
uint32_t arm_v7m_mpu_get_fault_address(void)
{
    return SCB->MMFAR;
}

/**
 * @brief Clear MemManage fault status
 * @note Writes 1s to clear the fault status bits.
 */
void arm_v7m_mpu_clear_fault_status(void)
{
    /* Write 1s to clear the fault bits */
    SCB->CFSR = SCB_CFSR_MMFSR_Msk;
}

/**
 * @brief Check if fault address is valid
 * @return 1 if MMFAR contains valid fault address, 0 otherwise
 */
uint32_t arm_v7m_mpu_fault_addr_valid(void)
{
    return (arm_v7m_mpu_get_fault_status() & ARM_V7M_MMFSR_MMARVALID_Msk) ? 1U : 0U;
}
