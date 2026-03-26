/*
 * arm_v8m_cm33_cde.h
 * Cortex-M33 Custom Datapath Extension (CDE) Definitions
 * Reference: Cortex-M33 Technical Reference Manual
 *
 * @note CDE is specific to Cortex-M33 and not part of generic Armv8-M.
 *       This is a placeholder for CDE-specific functionality.
 */

#ifndef ARM_V8M_CM33_CDE_H
#define ARM_V8M_CM33_CDE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * CDE Type Definitions
 *============================================================================*/

/* CDE register structure - CM33 specific */
typedef struct {
    volatile uint32_t CDE_CCR;      /* CDE Configuration and Control Register */
    volatile uint32_t CDE_CVR[4];   /* CDE Value Registers */
} arm_v8m_cm33_cde_regs_t;

/*============================================================================*
 * CDE API Functions (Template)
 *============================================================================*/

void arm_v8m_cm33_cde_enable(void);
void arm_v8m_cm33_cde_disable(void);
uint32_t arm_v8m_cm33_cde_is_present(void);
void arm_v8m_cm33_cde_set_value(uint32_t reg_num, uint32_t value);
uint32_t arm_v8m_cm33_cde_get_value(uint32_t reg_num);
void arm_v8m_cm33_cde_execute(uint32_t opcode);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM33_CDE_H */
