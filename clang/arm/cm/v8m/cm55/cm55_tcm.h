/*
 * cm55_tcm.h
 * Cortex-M55 Tightly-Coupled Memory (TCM) Definitions
 * Reference: Cortex-M55 Technical Reference Manual, Chapter 5, 10
 */

#ifndef CM55_TCM_H
#define CM55_TCM_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * TCM Control Register Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t ITCMCR;
    volatile uint32_t DTCMCR;
} cm55_tcm_regs_t;

/*============================================================================*
 * TCM Gate Unit (TGU) Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t ITGU_CTRL;
    volatile uint32_t ITGU_CFG;
    volatile uint32_t ITGU_LUT[16];
    volatile uint32_t DTGU_CTRL;
    volatile uint32_t DTGU_CFG;
    volatile uint32_t DTGU_LUT[16];
} cm55_tgu_regs_t;

/*============================================================================*
 * ITCMCR Bit Definitions
 *============================================================================*/

#define CM55_ITCMCR_EN_Pos              0
#define CM55_ITCMCR_EN_Msk              (1UL << CM55_ITCMCR_EN_Pos)
#define CM55_ITCMCR_SZ_Pos              3
#define CM55_ITCMCR_SZ_Msk              (0xFUL << CM55_ITCMCR_SZ_Pos)

/*============================================================================*
 * DTCMCR Bit Definitions
 *============================================================================*/

#define CM55_DTCMCR_EN_Pos              0
#define CM55_DTCMCR_EN_Msk              (1UL << CM55_DTCMCR_EN_Pos)
#define CM55_DTCMCR_SZ_Pos              3
#define CM55_DTCMCR_SZ_Msk              (0xFUL << CM55_DTCMCR_SZ_Pos)

/*============================================================================*
 * TCM API Functions (Template)
 *============================================================================*/

/* ITCM Functions */
void cm55_itcm_enable(void);
void cm55_itcm_disable(void);
void cm55_itcm_set_size(uint32_t size);
uint32_t cm55_itcm_get_size(void);

/* DTCM Functions */
void cm55_dtcm_enable(void);
void cm55_dtcm_disable(void);
void cm55_dtcm_set_size(uint32_t size);
uint32_t cm55_dtcm_get_size(void);

/*============================================================================*
 * TGU API Functions (Template)
 *============================================================================*/

void cm55_itgu_enable(void);
void cm55_itgu_disable(void);
void cm55_itgu_set_lut(uint32_t index, uint32_t value);
uint32_t cm55_itgu_get_lut(uint32_t index);

void cm55_dtgu_enable(void);
void cm55_dtgu_disable(void);
void cm55_dtgu_set_lut(uint32_t index, uint32_t value);
uint32_t cm55_dtgu_get_lut(uint32_t index);

#ifdef __cplusplus
}
#endif

#endif /* CM55_TCM_H */
