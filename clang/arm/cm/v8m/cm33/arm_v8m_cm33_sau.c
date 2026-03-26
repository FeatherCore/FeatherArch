/*
 * arm_v8m_cm33_sau.c
 * Cortex-M33 Security Attribution Unit (SAU) Implementation
 * Reference: Cortex-M33 Technical Reference Manual, Chapter 4
 */

#include "arm_v8m_cm33_sau.h"

/*============================================================================*
 * SAU Base Address (Architecture defined)
 *============================================================================*/
#define SAU_BASE            0xE000EDD0UL

#define SAU                 ((arm_v8m_cm33_sau_regs_t *)SAU_BASE)

/*============================================================================*
 * SAU Implementation
 *============================================================================*/

void arm_v8m_cm33_sau_enable(void)
{
    /* TODO: Set ENABLE bit in SAU_CTRL */
}

void arm_v8m_cm33_sau_disable(void)
{
    /* TODO: Clear ENABLE bit in SAU_CTRL */
}

uint32_t arm_v8m_cm33_sau_get_region_count(void)
{
    /* TODO: Read SREGION field from SAU_TYPE */
    return 0;
}

void arm_v8m_cm33_sau_select_region(uint32_t region_num)
{
    /* TODO: Write to SAU_RNR */
    (void)region_num;
}

void arm_v8m_cm33_sau_set_region(uint32_t base_addr, uint32_t limit_addr, uint32_t attrs)
{
    /* TODO: Configure SAU_RBAR and SAU_RLAR */
    (void)base_addr;
    (void)limit_addr;
    (void)attrs;
}

void arm_v8m_cm33_sau_disable_region(uint32_t region_num)
{
    /* TODO: Disable region by clearing ENABLE bit in RLAR */
    (void)region_num;
}

void arm_v8m_cm33_sau_set_all_ns(uint32_t enable)
{
    /* TODO: Set ALLNS bit in SAU_CTRL */
    (void)enable;
}

uint32_t arm_v8m_cm33_sau_get_sfsr(void)
{
    /* TODO: Read SAU_SFSR */
    return 0;
}

void arm_v8m_cm33_sau_clear_sfsr(void)
{
    /* TODO: Write to clear SAU_SFSR */
}

uint32_t arm_v8m_cm33_sau_get_sfar(void)
{
    /* TODO: Read SAU_SFAR */
    return 0;
}
