/*
 * arm_v8m_sau.h
 * Armv8-M Security Attribution Unit (SAU) Definitions
 * Reference: Armv8-M Architecture Reference Manual, Chapter B10.3
 */

#ifndef ARM_V8M_SAU_H
#define ARM_V8M_SAU_H

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
} arm_v8m_sau_regs_t;

/*============================================================================*
 * SAU Control Register Bit Definitions
 *============================================================================*/

#define ARM_V8M_SAU_CTRL_ENABLE_Pos      0
#define ARM_V8M_SAU_CTRL_ENABLE_Msk      (1UL << ARM_V8M_SAU_CTRL_ENABLE_Pos)
#define ARM_V8M_SAU_CTRL_ALLNS_Pos       1
#define ARM_V8M_SAU_CTRL_ALLNS_Msk       (1UL << ARM_V8M_SAU_CTRL_ALLNS_Pos)

/*============================================================================*
 * SAU API Functions (Template)
 *============================================================================*/

void arm_v8m_sau_enable(void);
void arm_v8m_sau_disable(void);
uint32_t arm_v8m_sau_get_region_count(void);
void arm_v8m_sau_select_region(uint32_t region_num);
void arm_v8m_sau_set_region(uint32_t base_addr, uint32_t limit_addr, uint32_t attrs);
void arm_v8m_sau_disable_region(uint32_t region_num);
void arm_v8m_sau_set_all_ns(uint32_t enable);
uint32_t arm_v8m_sau_get_sfsr(void);
void arm_v8m_sau_clear_sfsr(void);
uint32_t arm_v8m_sau_get_sfar(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_SAU_H */
