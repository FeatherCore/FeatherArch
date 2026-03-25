/**
 * @file cm85_epu.h
 * @brief Cortex-M85 Extension Processing Unit (EPU)
 *
 * @note Reference: Arm Cortex-M85 Processor TRM, Chapter 3.1.2
 * @note EPU handles floating-point and MVE vector operations
 */

#ifndef CM85_EPU_H
#define CM85_EPU_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* EPU Control Register (EPUCR) */
#define CM85_EPUCR_BASE     (0xE000E300UL)
#define CM85_EPUCR          (*(volatile uint32_t *)CM85_EPUCR_BASE)

/* EPUCR bit definitions */
#define CM85_EPUCR_EN_Pos           0U
#define CM85_EPUCR_EN_Msk           (1UL << CM85_EPUCR_EN_Pos)
#define CM85_EPUCR_FPDIS_Pos        1U
#define CM85_EPUCR_FPDIS_Msk        (1UL << CM85_EPUCR_FPDIS_Pos)
#define CM85_EPUCR_MVEDIS_Pos       2U
#define CM85_EPUCR_MVEDIS_Msk       (1UL << CM85_EPUCR_MVEDIS_Pos)

/* EPU Status Register (EPUSR) */
#define CM85_EPUSR_BASE     (0xE000E304UL)
#define CM85_EPUSR          (*(volatile uint32_t *)CM85_EPUSR_BASE)

/* EPU initialization and control */
int cm85_epu_init(void);
void cm85_epu_deinit(void);
void cm85_epu_enable(void);
void cm85_epu_disable(void);
bool cm85_epu_is_enabled(void);

/* EPU feature control */
void cm85_epu_enable_fp(void);
void cm85_epu_disable_fp(void);
void cm85_epu_enable_mve(void);
void cm85_epu_disable_mve(void);

/* EPU power management */
void cm85_epu_power_down(void);
void cm85_epu_power_up(void);
bool cm85_epu_is_powered(void);

/* EPU status */
uint32_t cm85_epu_get_status(void);
void cm85_epu_clear_status(uint32_t mask);

#ifdef __cplusplus
}
#endif

#endif /* CM85_EPU_H */
