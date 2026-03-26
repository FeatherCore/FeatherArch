/*
 * arm_v8m_cm33_sau.h
 * Cortex-M33 Security Attribution Unit (SAU) Definitions
 * Reference: Cortex-M33 Technical Reference Manual, Chapter 4
 *
 * @note This file reuses Armv8-M generic SAU definitions.
 */

#ifndef ARM_V8M_CM33_SAU_H
#define ARM_V8M_CM33_SAU_H

#include <stdint.h>
#include "../armv8m_sau.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Type Aliases
 *============================================================================*/

typedef arm_v8m_sau_regs_t      arm_v8m_cm33_sau_regs_t;

/*============================================================================*
 * Constant Aliases - Control Register Bits
 *============================================================================*/

#define ARM_V8M_CM33_SAU_CTRL_ENABLE_Pos        ARM_V8M_SAU_CTRL_ENABLE_Pos
#define ARM_V8M_CM33_SAU_CTRL_ENABLE_Msk        ARM_V8M_SAU_CTRL_ENABLE_Msk
#define ARM_V8M_CM33_SAU_CTRL_ALLNS_Pos         ARM_V8M_SAU_CTRL_ALLNS_Pos
#define ARM_V8M_CM33_SAU_CTRL_ALLNS_Msk         ARM_V8M_SAU_CTRL_ALLNS_Msk

/*============================================================================*
 * Inline Function Wrappers - SAU Operations
 *============================================================================*/

static inline void arm_v8m_cm33_sau_enable(void) {
    arm_v8m_sau_enable();
}

static inline void arm_v8m_cm33_sau_disable(void) {
    arm_v8m_sau_disable();
}

static inline uint32_t arm_v8m_cm33_sau_get_region_count(void) {
    return arm_v8m_sau_get_region_count();
}

static inline void arm_v8m_cm33_sau_select_region(uint32_t region_num) {
    arm_v8m_sau_select_region(region_num);
}

static inline void arm_v8m_cm33_sau_set_region(uint32_t base_addr, uint32_t limit_addr, uint32_t attrs) {
    arm_v8m_sau_set_region(base_addr, limit_addr, attrs);
}

static inline void arm_v8m_cm33_sau_disable_region(uint32_t region_num) {
    arm_v8m_sau_disable_region(region_num);
}

static inline void arm_v8m_cm33_sau_set_all_ns(uint32_t enable) {
    arm_v8m_sau_set_all_ns(enable);
}

static inline uint32_t arm_v8m_cm33_sau_get_sfsr(void) {
    return arm_v8m_sau_get_sfsr();
}

static inline void arm_v8m_cm33_sau_clear_sfsr(void) {
    arm_v8m_sau_clear_sfsr();
}

static inline uint32_t arm_v8m_cm33_sau_get_sfar(void) {
    return arm_v8m_sau_get_sfar();
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM33_SAU_H */
