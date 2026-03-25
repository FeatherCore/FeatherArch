/*
 * cm33_mpu.c
 * Cortex-M33 Memory Protection Unit (MPU) Implementation
 * Reference: Cortex-M33 Technical Reference Manual, Chapter 4
 */

#include "cm33_mpu.h"

/*============================================================================*
 * MPU Base Address (Architecture defined)
 *============================================================================*/
#define MPU_BASE            0xE000ED90UL

#define MPU                 ((cm33_mpu_regs_t *)MPU_BASE)

/*============================================================================*
 * MPU Implementation
 *============================================================================*/

void cm33_mpu_enable(void)
{
    /* TODO: Set ENABLE bit in MPU_CTRL, may need DSB/ISB */
}

void cm33_mpu_disable(void)
{
    /* TODO: Clear ENABLE bit in MPU_CTRL, may need DSB/ISB */
}

uint32_t cm33_mpu_get_region_count(void)
{
    /* TODO: Read DREGION field from MPU_TYPE */
    return 0;
}

void cm33_mpu_select_region(uint32_t region_num)
{
    /* TODO: Write to MPU_RNR */
    (void)region_num;
}

void cm33_mpu_set_region(uint32_t base_addr, uint32_t limit_addr, uint32_t attrs)
{
    /* TODO: Configure MPU_RBAR and MPU_RLAR with MAIR attributes */
    (void)base_addr;
    (void)limit_addr;
    (void)attrs;
}

void cm33_mpu_disable_region(uint32_t region_num)
{
    /* TODO: Disable region by clearing ENABLE bit in RLAR */
    (void)region_num;
}

void cm33_mpu_set_mair(uint32_t attr_idx, uint32_t attr)
{
    /* TODO: Write to MAIR0 or MAIR1 */
    (void)attr_idx;
    (void)attr;
}

uint32_t cm33_mpu_get_mair(uint32_t attr_idx)
{
    /* TODO: Read from MAIR0 or MAIR1 */
    (void)attr_idx;
    return 0;
}

/*============================================================================*
 * MPU Security Functions - TrustZone
 *============================================================================*/

void cm33_mpu_enable_s(void)
{
    /* TODO: Set ENABLE bit in MPU_CTRL_S from secure state */
}

void cm33_mpu_disable_s(void)
{
    /* TODO: Clear ENABLE bit in MPU_CTRL_S from secure state */
}

void cm33_mpu_set_region_s(uint32_t base_addr, uint32_t limit_addr, uint32_t attrs)
{
    /* TODO: Configure MPU_RBAR_S and MPU_RLAR_S from secure state */
    (void)base_addr;
    (void)limit_addr;
    (void)attrs;
}
