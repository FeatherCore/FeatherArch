/*
 * arm_v7m_cm7_mpu.c
 * Cortex-M7 Memory Protection Unit (MPU) Implementation
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
 *            - Section 4.1.1: Initializing the MPU on page 4-5
 *
 * This file wraps the generic Armv7-M MPU implementation for Cortex-M7.
 * Simple functions are implemented as inline in arm_v7m_cm7_mpu.h.
 * Complex functions requiring memory barriers are implemented here.
 *
 * @note This file wraps the generic Armv7-M MPU implementation.
 */

#include "arm_v7m_cm7_mpu.h"

/*============================================================================*
 * MPU Enable/Disable with Memory Barriers
 *============================================================================*/

/**
 * @brief Enable the MPU with specified control flags
 *
 * According to ARMv7-M Architecture Reference Manual, Section B3.5.6:
 * - ENABLE bit (bit 0) enables the MPU
 * - PRIVDEFENA bit (bit 2) enables the default memory map for privileged access
 * - HFNMIENA bit (bit 1) enables MPU during hard fault, NMI, and FAULTMASK
 *
 * According to Cortex-M7 Devices Generic User Guide, Section 4.6.2:
 * - Use a DSB, followed by an ISB instruction or exception return to ensure
 *   that the new MPU settings take effect.
 *
 * @param flags Combination of ARM_V7M_CM7_MPU_ENABLE_PRIVDEFENA and/or
 *              ARM_V7M_CM7_MPU_ENABLE_HFNMIENA
 */
void arm_v7m_cm7_mpu_enable(uint32_t flags)
{
    arm_v7m_mpu_enable(flags);
}

/**
 * @brief Disable the MPU
 *
 * According to ARMv7-M Architecture Reference Manual, Section B3.5.6:
 * - Clearing ENABLE bit disables the MPU
 * - When disabled, privileged and unprivileged accesses use the default memory map
 *
 * According to Cortex-M7 Devices Generic User Guide, Section 4.6.2:
 * - Use a DSB, followed by an ISB instruction to ensure all pending memory
 *   accesses complete before the MPU is disabled.
 */
void arm_v7m_cm7_mpu_disable(void)
{
    arm_v7m_mpu_disable();
}

/*============================================================================*
 * MPU Capability Query
 *============================================================================*/

/**
 * @brief Get the minimum supported region size
 *
 * According to ARMv7-M Architecture Reference Manual, Section B3.5.4:
 * - Software can find the minimum size by writing all ones to
 *   MPU_RBAR[31:5] and reading back the value.
 *
 * @return Minimum region size in bytes
 */
uint32_t arm_v7m_cm7_mpu_get_min_region_size(void)
{
    return arm_v7m_mpu_get_min_region_size();
}

/**
 * @brief Calculate the SIZE field value for a given region size
 *
 * According to ARMv7-M Architecture Reference Manual, Section B3.5.9:
 * - SIZE field determines the region size: 2^(SIZE+1) bytes
 * - Minimum SIZE is 4 (32 bytes), maximum is 31 (4GB)
 *
 * @param size Region size in bytes (must be power of 2, >= 32)
 * @return SIZE field value (4-31), or -1 if invalid size
 */
int arm_v7m_cm7_mpu_calc_size_code(uint32_t size)
{
    return arm_v7m_mpu_calc_size_code(size);
}

/*============================================================================*
 * Region Configuration
 *============================================================================*/

/**
 * @brief Configure the currently selected MPU region
 *
 * According to ARMv7-M Architecture Reference Manual:
 * - Section B3.5.8: MPU_RBAR contains the base address (bits [31:5])
 * - Section B3.5.9: MPU_RASR contains attributes, size, and enable bit
 *
 * According to Cortex-M7 Devices Generic User Guide, Section 4.6.5:
 * - Region size is 2^(SIZE+1) bytes
 * - Base address must be aligned to region size
 *
 * @param base_addr Region base address (must be aligned to region size)
 * @param size_code SIZE field value (4-31, for 32 bytes to 4GB)
 * @param attrs Region attributes (AP, TEX, S, C, B, XN fields combined)
 */
void arm_v7m_cm7_mpu_set_region(uint32_t base_addr, uint32_t size_code, uint32_t attrs)
{
    arm_v7m_mpu_set_region(base_addr, size_code, attrs);
}

/**
 * @brief Configure a specific MPU region with extended options
 *
 * According to ARMv7-M Architecture Reference Manual, Section B3.5.8:
 * - VALID bit (bit 4) in RBAR allows updating a specific region without
 *   first writing to MPU_RNR
 * - REGION field (bits [3:0]) specifies the region number when VALID=1
 *
 * @param region_num Region number to configure (0-15)
 * @param base_addr Region base address (must be aligned to region size)
 * @param size_code SIZE field value (4-31)
 * @param attrs Region attributes (AP, TEX, S, C, B, XN fields combined)
 * @param srd Subregion disable bits (8 bits, only valid for regions >= 256 bytes)
 */
void arm_v7m_cm7_mpu_set_region_ex(uint32_t region_num, uint32_t base_addr,
                                    uint32_t size_code, uint32_t attrs, uint32_t srd)
{
    arm_v7m_mpu_set_region_ex(region_num, base_addr, size_code, attrs, srd);
}

/**
 * @brief Configure multiple MPU regions using alias registers
 *
 * According to ARMv7-M Architecture Reference Manual, Section B3.5.4:
 * - MPU alias registers (MPU_RBAR_A1/2/3 and MPU_RASR_A1/2/3) allow
 *   efficient configuration of up to 4 regions
 * - This is useful for context switching or initial setup
 *
 * According to Cortex-M7 Technical Reference Manual, Section 6.3:
 * - The MPU supports alias registers for efficient multi-region programming
 *
 * @param regions Array of region configurations
 * @param count Number of regions to configure (1-4)
 */
void arm_v7m_cm7_mpu_set_regions(const arm_v7m_cm7_mpu_region_cfg_t *regions, uint32_t count)
{
    arm_v7m_mpu_set_regions((const arm_v7m_mpu_region_cfg_t *)regions, count);
}

/*============================================================================*
 * Region Disable
 *============================================================================*/

/**
 * @brief Disable a specific MPU region
 *
 * According to ARMv7-M Architecture Reference Manual, Section B3.5.4:
 * - All MPU_RASR registers must be programmed as either enabled or
 *   disabled before enabling the MPU using the MPU_CTRL register.
 *
 * @param region_num Region number to disable
 */
void arm_v7m_cm7_mpu_disable_region(uint32_t region_num)
{
    arm_v7m_mpu_disable_region(region_num);
}

/*============================================================================*
 * MemManage Fault Status Functions
 *============================================================================*/

/**
 * @brief Get MemManage fault status
 *
 * According to ARMv7-M Architecture Reference Manual, Section B3.2.14:
 * - MMFSR is part of CFSR (bits [7:0])
 * - Shows the status of MPU faults
 *
 * @return MMFSR value (8-bit status)
 */
uint32_t arm_v7m_cm7_mpu_get_fault_status(void)
{
    return arm_v7m_mpu_get_fault_status();
}

/**
 * @brief Get MemManage fault address
 *
 * According to ARMv7-M Architecture Reference Manual, Section B3.2.12:
 * - MMFAR contains the address of the memory location that caused an MPU fault
 * - Only valid if MMARVALID bit is set in MMFSR
 *
 * @return Fault address
 */
uint32_t arm_v7m_cm7_mpu_get_fault_address(void)
{
    return arm_v7m_mpu_get_fault_address();
}

/**
 * @brief Clear MemManage fault status
 *
 * According to ARMv7-M Architecture Reference Manual, Section B3.2.14:
 * - Writing 1s to MMFSR bits clears the fault status
 */
void arm_v7m_cm7_mpu_clear_fault_status(void)
{
    arm_v7m_mpu_clear_fault_status();
}

/**
 * @brief Check if fault address is valid
 *
 * According to ARMv7-M Architecture Reference Manual, Section B3.2.14:
 * - MMARVALID bit (bit 7) of MMFSR indicates if MMFAR contains valid address
 *
 * @return 1 if MMFAR contains valid fault address, 0 otherwise
 */
uint32_t arm_v7m_cm7_mpu_fault_addr_valid(void)
{
    return arm_v7m_mpu_fault_addr_valid();
}
