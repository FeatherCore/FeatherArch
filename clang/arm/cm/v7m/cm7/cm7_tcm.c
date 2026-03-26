/*
 * arm_v7m_cm7_tcm.c
 * Cortex-M7 Tightly-Coupled Memory (TCM) Implementation
 * Reference: Cortex-M7 Technical Reference Manual, Chapter 5.8
 */

#include "arm_v7m_cm7_tcm.h"

/*============================================================================*
 * TCM Base Address (Architecture defined)
 *============================================================================*/
#define TCM_BASE            0xE000EF90UL

#define TCM                 ((arm_v7m_cm7_tcm_regs_t *)TCM_BASE)

/*============================================================================*
 * ITCM Functions
 *============================================================================*/

void arm_v7m_cm7_itcm_enable(void)
{
    /* TODO: Set EN bit in ITCMCR */
}

void arm_v7m_cm7_itcm_disable(void)
{
    /* TODO: Clear EN bit in ITCMCR */
}

void arm_v7m_cm7_itcm_set_size(uint32_t size)
{
    /* TODO: Write SZ field in ITCMCR */
    (void)size;
}

uint32_t arm_v7m_cm7_itcm_get_size(void)
{
    /* TODO: Read SZ field from ITCMCR */
    return 0;
}

/*============================================================================*
 * DTCM Functions
 *============================================================================*/

void arm_v7m_cm7_dtcm_enable(void)
{
    /* TODO: Set EN bit in DTCMCR */
}

void arm_v7m_cm7_dtcm_disable(void)
{
    /* TODO: Clear EN bit in DTCMCR */
}

void arm_v7m_cm7_dtcm_set_size(uint32_t size)
{
    /* TODO: Write SZ field in DTCMCR */
    (void)size;
}

uint32_t arm_v7m_cm7_dtcm_get_size(void)
{
    /* TODO: Read SZ field from DTCMCR */
    return 0;
}

/*============================================================================*
 * AHB Peripheral Control
 *============================================================================*/

void arm_v7m_cm7_ahbpc_enable(void)
{
    /* TODO: Set EN bit in AHBPCR */
}

void arm_v7m_cm7_ahbpc_disable(void)
{
    /* TODO: Clear EN bit in AHBPCR */
}

/*============================================================================*
 * CACR - Cache Control
 *============================================================================*/

void arm_v7m_cm7_cacr_set_siwu(uint32_t enable)
{
    /* TODO: Set SIWT bit in CACR */
    (void)enable;
}

void arm_v7m_cm7_cacr_set_ecor(uint32_t enable)
{
    /* TODO: Set ECOR bit in CACR */
    (void)enable;
}

void arm_v7m_cm7_cacr_set_dcor(uint32_t enable)
{
    /* TODO: Set DCOR bit in CACR */
    (void)enable;
}
