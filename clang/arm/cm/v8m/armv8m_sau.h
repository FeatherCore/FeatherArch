/*
 * armv8m_sau.h
 * Armv8-M Security Attribution Unit (SAU) Definitions
 * Reference: Armv8-M Architecture Reference Manual, Chapter B10.3
 */

#ifndef ARMV8M_SAU_H
#define ARMV8M_SAU_H

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
} armv8m_sau_regs_t;

/*============================================================================*
 * SAU Control Register Bit Definitions
 *============================================================================*/

#define ARMV8M_SAU_CTRL_ENABLE_Pos      0
#define ARMV8M_SAU_CTRL_ENABLE_Msk      (1UL << ARMV8M_SAU_CTRL_ENABLE_Pos)
#define ARMV8M_SAU_CTRL_ALLNS_Pos       1
#define ARMV8M_SAU_CTRL_ALLNS_Msk       (1UL << ARMV8M_SAU_CTRL_ALLNS_Pos)

/*============================================================================*
 * SAU API Functions (Template)
 *============================================================================*/

void armv8m_sau_enable(void);
void armv8m_sau_disable(void);
uint32_t armv8m_sau_get_region_count(void);
void armv8m_sau_select_region(uint32_t region_num);
void armv8m_sau_set_region(uint32_t base_addr, uint32_t limit_addr, uint32_t attrs);
void armv8m_sau_disable_region(uint32_t region_num);
void armv8m_sau_set_all_ns(uint32_t enable);
uint32_t armv8m_sau_get_sfsr(void);
void armv8m_sau_clear_sfsr(void);
uint32_t armv8m_sau_get_sfar(void);

#ifdef __cplusplus
}
#endif

#endif /* ARMV8M_SAU_H */
