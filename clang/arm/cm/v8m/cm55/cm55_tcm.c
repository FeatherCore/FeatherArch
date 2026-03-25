/*
 * cm55_tcm.c
 * Cortex-M55 Tightly-Coupled Memory (TCM) Implementation
 * Reference: Cortex-M55 Technical Reference Manual, Chapter 5, 10
 */

#include "cm55_tcm.h"

/*============================================================================*
 * TCM Base Address (Architecture defined)
 *============================================================================*/
#define TCM_BASE            0xE000EF90UL
#define TGU_BASE            0xE000EFA0UL

#define TCM                 ((cm55_tcm_regs_t *)TCM_BASE)
#define TGU                 ((cm55_tgu_regs_t *)TGU_BASE)

/*============================================================================*
 * TCM Implementation
 *============================================================================*/

void cm55_itcm_enable(void)
{
    /* TODO: Set EN bit in ITCMCR */
}

void cm55_itcm_disable(void)
{
    /* TODO: Clear EN bit in ITCMCR */
}

void cm55_itcm_set_size(uint32_t size)
{
    /* TODO: Write SZ field in ITCMCR */
    (void)size;
}

uint32_t cm55_itcm_get_size(void)
{
    /* TODO: Read SZ field from ITCMCR */
    return 0;
}

void cm55_dtcm_enable(void)
{
    /* TODO: Set EN bit in DTCMCR */
}

void cm55_dtcm_disable(void)
{
    /* TODO: Clear EN bit in DTCMCR */
}

void cm55_dtcm_set_size(uint32_t size)
{
    /* TODO: Write SZ field in DTCMCR */
    (void)size;
}

uint32_t cm55_dtcm_get_size(void)
{
    /* TODO: Read SZ field from DTCMCR */
    return 0;
}

/*============================================================================*
 * TGU Implementation
 *============================================================================*/

void cm55_itgu_enable(void)
{
    /* TODO: Set EN bit in ITGU_CTRL */
}

void cm55_itgu_disable(void)
{
    /* TODO: Clear EN bit in ITGU_CTRL */
}

void cm55_itgu_set_lut(uint32_t index, uint32_t value)
{
    /* TODO: Write to ITGU_LUT */
    (void)index;
    (void)value;
}

uint32_t cm55_itgu_get_lut(uint32_t index)
{
    /* TODO: Read from ITGU_LUT */
    (void)index;
    return 0;
}

void cm55_dtgu_enable(void)
{
    /* TODO: Set EN bit in DTGU_CTRL */
}

void cm55_dtgu_disable(void)
{
    /* TODO: Clear EN bit in DTGU_CTRL */
}

void cm55_dtgu_set_lut(uint32_t index, uint32_t value)
{
    /* TODO: Write to DTGU_LUT */
    (void)index;
    (void)value;
}

uint32_t cm55_dtgu_get_lut(uint32_t index)
{
    /* TODO: Read from DTGU_LUT */
    (void)index;
    return 0;
}
