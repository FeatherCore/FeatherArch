/*
 * cm33_sau.h
 * Cortex-M33 Security Attribution Unit (SAU) Definitions
 * Reference: Cortex-M33 Technical Reference Manual, Chapter 4
 */

#ifndef CM33_SAU_H
#define CM33_SAU_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * SAU Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t TYPE;
    volatile uint32_t RNR;
    volatile uint32_t RBAR;
    volatile uint32_t RLAR;
    volatile uint32_t SFSR;
    volatile uint32_t SFAR;
} cm33_sau_regs_t;

/*============================================================================*
 * SAU Control Register Bit Definitions
 *============================================================================*/

#define CM33_SAU_CTRL_ENABLE_Pos        0
#define CM33_SAU_CTRL_ENABLE_Msk        (1UL << CM33_SAU_CTRL_ENABLE_Pos)
#define CM33_SAU_CTRL_ALLNS_Pos         1
#define CM33_SAU_CTRL_ALLNS_Msk         (1UL << CM33_SAU_CTRL_ALLNS_Pos)

/*============================================================================*
 * SAU API Functions (Template)
 *============================================================================*/

void cm33_sau_enable(void);
void cm33_sau_disable(void);
uint32_t cm33_sau_get_region_count(void);
void cm33_sau_select_region(uint32_t region_num);
void cm33_sau_set_region(uint32_t base_addr, uint32_t limit_addr, uint32_t attrs);
void cm33_sau_disable_region(uint32_t region_num);
void cm33_sau_set_all_ns(uint32_t enable);
uint32_t cm33_sau_get_sfsr(void);
void cm33_sau_clear_sfsr(void);
uint32_t cm33_sau_get_sfar(void);

#ifdef __cplusplus
}
#endif

#endif /* CM33_SAU_H */
