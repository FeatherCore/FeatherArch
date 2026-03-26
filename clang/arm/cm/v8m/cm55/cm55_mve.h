/*
 * arm_v8m_cm55_mve.h
 * Cortex-M55 M-Profile Vector Extension (MVE) Definitions
 * Reference: Cortex-M55 Technical Reference Manual, Chapter 4
 *
 * @note This file reuses Armv8-M generic MVE definitions.
 */

#ifndef ARM_V8M_CM55_MVE_H
#define ARM_V8M_CM55_MVE_H

#include <stdint.h>
#include "../armv8m_mve.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Type Aliases
 *============================================================================*/

typedef arm_v8m_mve_regs_t      arm_v8m_cm55_mve_regs_t;

/*============================================================================*
 * Constant Aliases
 *============================================================================*/

#define ARM_V8M_CM55_MVE_ENABLE_Pos         ARM_V8M_MVE_ENABLE_Pos
#define ARM_V8M_CM55_MVE_ENABLE_Msk         ARM_V8M_MVE_ENABLE_Msk
#define ARM_V8M_CM55_MVE_RETENTION_Pos      ARM_V8M_MVE_RETENTION_Pos
#define ARM_V8M_CM55_MVE_RETENTION_Msk      ARM_V8M_MVE_RETENTION_Msk

/*============================================================================*
 * Inline Function Wrappers - MVE Operations
 *============================================================================*/

static inline void arm_v8m_cm55_mve_enable(void) {
    arm_v8m_mve_enable();
}

static inline void arm_v8m_cm55_mve_disable(void) {
    arm_v8m_mve_disable();
}

static inline uint32_t arm_v8m_cm55_mve_is_present(void) {
    return arm_v8m_mve_is_present();
}

static inline uint32_t arm_v8m_cm55_mve_has_fp(void) {
    return arm_v8m_mve_has_fp();
}

static inline uint32_t arm_v8m_cm55_mve_has_int(void) {
    return arm_v8m_mve_has_int();
}

static inline void arm_v8m_cm55_mve_set_retention(uint32_t enable) {
    arm_v8m_mve_set_retention(enable);
}

static inline void arm_v8m_cm55_mve_vldm(uint32_t *addr, uint32_t num_regs) {
    arm_v8m_mve_vldm(addr, num_regs);
}

static inline void arm_v8m_cm55_mve_vstm(uint32_t *addr, uint32_t num_regs) {
    arm_v8m_mve_vstm(addr, num_regs);
}

static inline void arm_v8m_cm55_mve_set_lpstart(uint32_t addr) {
    arm_v8m_mve_set_lpstart(addr);
}

static inline void arm_v8m_cm55_mve_set_lpend(uint32_t addr) {
    arm_v8m_mve_set_lpend(addr);
}

static inline void arm_v8m_cm55_mve_set_lpcnt(uint32_t count) {
    arm_v8m_mve_set_lpcnt(count);
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM55_MVE_H */
