/*
 * arm_v8m_cm85_pacbti.h
 * Cortex-M85 Pointer Authentication and Branch Target Identification (PACBTI)
 * Reference: Cortex-M85 Technical Reference Manual
 *
 * @note PACBTI is specific to Cortex-M85 for security hardening.
 */

#ifndef ARM_V8M_CM85_PACBTI_H
#define ARM_V8M_CM85_PACBTI_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * PACBTI Configuration Register Definitions
 *============================================================================*/

#define ARM_V8M_CM85_PACBTI_CTRL_EN_Pos         0U
#define ARM_V8M_CM85_PACBTI_CTRL_EN_Msk         (1UL << ARM_V8M_CM85_PACBTI_CTRL_EN_Pos)
#define ARM_V8M_CM85_PACBTI_CTRL_BTI_EN_Pos     1U
#define ARM_V8M_CM85_PACBTI_CTRL_BTI_EN_Msk     (1UL << ARM_V8M_CM85_PACBTI_CTRL_BTI_EN_Msk)
#define ARM_V8M_CM85_PACBTI_CTRL_KEY_SEL_Pos    2U
#define ARM_V8M_CM85_PACBTI_CTRL_KEY_SEL_Msk    (1UL << ARM_V8M_CM85_PACBTI_CTRL_KEY_SEL_Pos)

/*============================================================================*
 * PACBTI API Functions
 *============================================================================*/

void arm_v8m_cm85_pacbti_enable(void);
void arm_v8m_cm85_pacbti_disable(void);
void arm_v8m_cm85_pacbti_bti_enable(void);
void arm_v8m_cm85_pacbti_bti_disable(void);

uint32_t arm_v8m_cm85_pacbti_is_present(void);
uint32_t arm_v8m_cm85_pacbti_has_bti(void);

void arm_v8m_cm85_pacbti_set_key(uint32_t key_lo, uint32_t key_hi);
void arm_v8m_cm85_pacbti_get_key(uint32_t *key_lo, uint32_t *key_hi);

void arm_v8m_cm85_pacbti_set_ns_key(uint32_t key_lo, uint32_t key_hi);
void arm_v8m_cm85_pacbti_get_ns_key(uint32_t *key_lo, uint32_t *key_hi);

uint32_t arm_v8m_cm85_pacbti_sign_lr(uint32_t modifier);
void arm_v8m_cm85_pacbti_aut_lr(uint32_t modifier);

uint32_t arm_v8m_cm85_pacbti_get_fault_status(void);
void arm_v8m_cm85_pacbti_clear_fault_status(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM85_PACBTI_H */
