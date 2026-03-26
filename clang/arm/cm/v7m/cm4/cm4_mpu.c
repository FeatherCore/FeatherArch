/*
 * arm_v7m_cm4_mpu.c
 * Cortex-M4 Memory Protection Unit (MPU) Implementation
 * Reference: Cortex-M4 Devices Generic User Guide, Chapter 4.5
 */

#include "arm_v7m_cm4_mpu.h"

/*============================================================================*
 * MPU Base Address (Architecture defined)
 *============================================================================*/
#define MPU_BASE            0xE000ED90UL

#define MPU                 ((arm_v7m_cm4_mpu_regs_t *)MPU_BASE)

/*============================================================================*
 * MPU Implementation
 *============================================================================*/

void arm_v7m_cm4_mpu_enable(void)
{
    /* TODO: Set ENABLE bit in MPU_CTRL, may need DSB/ISB */
}

void arm_v7m_cm4_mpu_disable(void)
{
    /* TODO: Clear ENABLE bit in MPU_CTRL, may need DSB/ISB */
}

uint32_t arm_v7m_cm4_mpu_get_region_count(void)
{
    /* TODO: Read DREGION field from MPU_TYPE */
    return 0;
}

void arm_v7m_cm4_mpu_select_region(uint32_t region_num)
{
    /* TODO: Write to MPU_RNR */
    (void)region_num;
}

void arm_v7m_cm4_mpu_set_region(uint32_t base_addr, uint32_t size, uint32_t attrs)
{
    /* TODO: Configure MPU_RBAR and MPU_RASR */
    (void)base_addr;
    (void)size;
    (void)attrs;
}

void arm_v7m_cm4_mpu_disable_region(uint32_t region_num)
{
    /* TODO: Disable region by clearing ENABLE bit in RASR */
    (void)region_num;
}
