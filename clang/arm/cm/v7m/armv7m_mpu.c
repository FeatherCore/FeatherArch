/*
 * armv7m_mpu.c
 * Memory Protection Unit (MPU) Implementation
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.5 (PMSAv7)
 */

#include "armv7m_mpu.h"

/*============================================================================*
 * MPU Base Address (Architecture defined)
 *============================================================================*/
#define MPU_BASE            0xE000ED90UL

#define MPU                 ((armv7m_mpu_regs_t *)MPU_BASE)

/*============================================================================*
 * MPU Implementation
 *============================================================================*/

void armv7m_mpu_enable(void)
{
    /* TODO: Set ENABLE bit in MPU_CTRL, may need DSB/ISB */
}

void armv7m_mpu_disable(void)
{
    /* TODO: Clear ENABLE bit in MPU_CTRL, may need DSB/ISB */
}

uint32_t armv7m_mpu_get_region_count(void)
{
    /* TODO: Read DREGION field from MPU_TYPE */
    return 0;
}

void armv7m_mpu_select_region(uint32_t region_num)
{
    /* TODO: Write to MPU_RNR */
    (void)region_num;
}

void armv7m_mpu_set_region(uint32_t base_addr, uint32_t size, uint32_t attrs)
{
    /* TODO: Configure MPU_RBAR and MPU_RASR */
    (void)base_addr;
    (void)size;
    (void)attrs;
}

void armv7m_mpu_disable_region(uint32_t region_num)
{
    /* TODO: Disable region by clearing ENABLE bit in RASR */
    (void)region_num;
}
