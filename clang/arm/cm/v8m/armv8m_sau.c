/*
 * armv8m_sau.c
 * Armv8-M Security Attribution Unit (SAU) Implementation
 * Reference: Armv8-M Architecture Reference Manual, Chapter B10.3
 */

#include "armv8m_sau.h"

/*============================================================================*
 * SAU Base Address (Architecture defined)
 *============================================================================*/
#define SAU_BASE            0xE000EDD0UL

#define SAU                 ((armv8m_sau_regs_t *)SAU_BASE)

/*============================================================================*
 * SAU Implementation
 *============================================================================*/

void armv8m_sau_enable(void)
{
    /* TODO: Set ENABLE bit in SAU_CTRL */
}

void armv8m_sau_disable(void)
{
    /* TODO: Clear ENABLE bit in SAU_CTRL */
}

uint32_t armv8m_sau_get_region_count(void)
{
    /* TODO: Read SREGION field from SAU_TYPE */
    return 0;
}

void armv8m_sau_select_region(uint32_t region_num)
{
    /* TODO: Write to SAU_RNR */
    (void)region_num;
}

void armv8m_sau_set_region(uint32_t base_addr, uint32_t limit_addr, uint32_t attrs)
{
    /* TODO: Configure SAU_RBAR and SAU_RLAR */
    (void)base_addr;
    (void)limit_addr;
    (void)attrs;
}

void armv8m_sau_disable_region(uint32_t region_num)
{
    /* TODO: Disable region by clearing ENABLE bit in RLAR */
    (void)region_num;
}

void armv8m_sau_set_all_ns(uint32_t enable)
{
    /* TODO: Set ALLNS bit in SAU_CTRL */
    (void)enable;
}

uint32_t armv8m_sau_get_sfsr(void)
{
    /* TODO: Read SAU_SFSR */
    return 0;
}

void armv8m_sau_clear_sfsr(void)
{
    /* TODO: Write to clear SAU_SFSR */
}

uint32_t armv8m_sau_get_sfar(void)
{
    /* TODO: Read SAU_SFAR */
    return 0;
}
