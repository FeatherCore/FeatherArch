/*
 * arm_v8m_cm85_coproc.h
 * Cortex-M85 Coprocessor Interface Definitions
 * Reference: Cortex-M85 Technical Reference Manual
 *
 * @note CM85 supports external coprocessors via CP10/CP11.
 */

#ifndef ARM_V8M_CM85_COPROC_H
#define ARM_V8M_CM85_COPROC_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Coprocessor Access Control Register (CPACR) Definitions
 *============================================================================*/

#define ARM_V8M_CM85_CPACR_CP10_Pos         20U
#define ARM_V8M_CM85_CPACR_CP10_Msk         (3UL << ARM_V8M_CM85_CPACR_CP10_Pos)
#define ARM_V8M_CM85_CPACR_CP11_Pos         22U
#define ARM_V8M_CM85_CPACR_CP11_Msk         (3UL << ARM_V8M_CM85_CPACR_CP11_Pos)

#define ARM_V8M_CM85_CPACR_ACCESS_DENIED    0U
#define ARM_V8M_CM85_CPACR_ACCESS_PRIV      1U
#define ARM_V8M_CM85_CPACR_ACCESS_FULL      3U

/*============================================================================*
 * Coprocessor API Functions
 *============================================================================*/

void arm_v8m_cm85_coproc_enable_cp10(uint32_t access_level);
void arm_v8m_cm85_coproc_enable_cp11(uint32_t access_level);
void arm_v8m_cm85_coproc_disable_cp10(void);
void arm_v8m_cm85_coproc_disable_cp11(void);

uint32_t arm_v8m_cm85_coproc_get_cp10_access(void);
uint32_t arm_v8m_cm85_coproc_get_cp11_access(void);

void arm_v8m_cm85_coproc_set_cp10_access(uint32_t access_level);
void arm_v8m_cm85_coproc_set_cp11_access(uint32_t access_level);

/* Coprocessor instruction wrappers */
uint32_t arm_v8m_cm85_coproc_mrc(uint32_t coproc, uint32_t opcode1, uint32_t crn, uint32_t crm, uint32_t opcode2);
void arm_v8m_cm85_coproc_mcr(uint32_t coproc, uint32_t opcode1, uint32_t crn, uint32_t crm, uint32_t opcode2, uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM85_COPROC_H */
