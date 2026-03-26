/*
 * arm_v8m_cm55_tcm.h
 * Cortex-M55 Tightly-Coupled Memory (TCM) Definitions
 * Reference: Cortex-M55 Technical Reference Manual, Chapter 4
 *
 * @note Cortex-M55 has ITCM and DTCM.
 *       This is CM55 specific, not part of generic Armv8-M.
 */

#ifndef ARM_V8M_CM55_TCM_H
#define ARM_V8M_CM55_TCM_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * TCM Configuration Register Definitions
 *============================================================================*/

#define ARM_V8M_CM55_ITCMCR_EN_Pos          0U
#define ARM_V8M_CM55_ITCMCR_EN_Msk          (1UL << ARM_V8M_CM55_ITCMCR_EN_Pos)
#define ARM_V8M_CM55_ITCMCR_RMW_Pos         1U
#define ARM_V8M_CM55_ITCMCR_RMW_Msk         (1UL << ARM_V8M_CM55_ITCMCR_RMW_Pos)
#define ARM_V8M_CM55_ITCMCR_RETEN_Pos       2U
#define ARM_V8M_CM55_ITCMCR_RETEN_Msk       (1UL << ARM_V8M_CM55_ITCMCR_RETEN_Pos)
#define ARM_V8M_CM55_ITCMCR_SZ_Pos          3U
#define ARM_V8M_CM55_ITCMCR_SZ_Msk          (0xFUL << ARM_V8M_CM55_ITCMCR_SZ_Pos)

#define ARM_V8M_CM55_DTCMCR_EN_Pos          0U
#define ARM_V8M_CM55_DTCMCR_EN_Msk          (1UL << ARM_V8M_CM55_DTCMCR_EN_Pos)
#define ARM_V8M_CM55_DTCMCR_RMW_Pos         1U
#define ARM_V8M_CM55_DTCMCR_RMW_Msk         (1UL << ARM_V8M_CM55_DTCMCR_RMW_Pos)
#define ARM_V8M_CM55_DTCMCR_RETEN_Pos       2U
#define ARM_V8M_CM55_DTCMCR_RETEN_Msk       (1UL << ARM_V8M_CM55_DTCMCR_RETEN_Pos)
#define ARM_V8M_CM55_DTCMCR_SZ_Pos          3U
#define ARM_V8M_CM55_DTCMCR_SZ_Msk          (0xFUL << ARM_V8M_CM55_DTCMCR_SZ_Pos)

/*============================================================================*
 * TCM Operations
 *============================================================================*/

void arm_v8m_cm55_itcm_enable(void);
void arm_v8m_cm55_itcm_disable(void);
uint32_t arm_v8m_cm55_itcm_get_size(void);
void arm_v8m_cm55_itcm_set_wait_state(uint32_t enable);

void arm_v8m_cm55_dtcm_enable(void);
void arm_v8m_cm55_dtcm_disable(void);
uint32_t arm_v8m_cm55_dtcm_get_size(void);
void arm_v8m_cm55_dtcm_set_wait_state(uint32_t enable);

/*============================================================================*
 * TCM Information
 *============================================================================*/

uint32_t arm_v8m_cm55_tcm_has_itcm(void);
uint32_t arm_v8m_cm55_tcm_has_dtcm(void);
uint32_t arm_v8m_cm55_tcm_get_base_addr(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM55_TCM_H */
