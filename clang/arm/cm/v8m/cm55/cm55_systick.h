/*
 * arm_v8m_cm55_systick.h
 * Cortex-M55 System Timer (SysTick) Definitions
 * Reference: Cortex-M55 Devices Generic User Guide, Chapter 4.5
 *
 * @note This file reuses Armv8-M generic SysTick definitions.
 */

#ifndef ARM_V8M_CM55_SYSTICK_H
#define ARM_V8M_CM55_SYSTICK_H

#include <stdint.h>
#include "../armv8m_systick.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Type Aliases
 *============================================================================*/

typedef arm_v8m_systick_regs_t      arm_v8m_cm55_systick_regs_t;

/*============================================================================*
 * Constant Aliases - Control Register Bits
 *============================================================================*/

#define ARM_V8M_CM55_SYSTICK_CTRL_ENABLE_Pos        ARM_V8M_SYSTICK_CTRL_ENABLE_Pos
#define ARM_V8M_CM55_SYSTICK_CTRL_ENABLE_Msk        ARM_V8M_SYSTICK_CTRL_ENABLE_Msk
#define ARM_V8M_CM55_SYSTICK_CTRL_TICKINT_Pos       ARM_V8M_SYSTICK_CTRL_TICKINT_Pos
#define ARM_V8M_CM55_SYSTICK_CTRL_TICKINT_Msk       ARM_V8M_SYSTICK_CTRL_TICKINT_Msk
#define ARM_V8M_CM55_SYSTICK_CTRL_CLKSOURCE_Pos     ARM_V8M_SYSTICK_CTRL_CLKSOURCE_Pos
#define ARM_V8M_CM55_SYSTICK_CTRL_CLKSOURCE_Msk     ARM_V8M_SYSTICK_CTRL_CLKSOURCE_Msk
#define ARM_V8M_CM55_SYSTICK_CTRL_COUNTFLAG_Pos     ARM_V8M_SYSTICK_CTRL_COUNTFLAG_Pos
#define ARM_V8M_CM55_SYSTICK_CTRL_COUNTFLAG_Msk     ARM_V8M_SYSTICK_CTRL_COUNTFLAG_Msk

/*============================================================================*
 * Inline Function Wrappers - SysTick Operations
 *============================================================================*/

static inline void arm_v8m_cm55_systick_init(uint32_t reload_value) {
    arm_v8m_systick_init(reload_value);
}

static inline void arm_v8m_cm55_systick_enable(void) {
    arm_v8m_systick_enable();
}

static inline void arm_v8m_cm55_systick_disable(void) {
    arm_v8m_systick_disable();
}

static inline uint32_t arm_v8m_cm55_systick_get_count(void) {
    return arm_v8m_systick_get_count();
}

static inline void arm_v8m_cm55_systick_set_reload(uint32_t value) {
    arm_v8m_systick_set_reload(value);
}

static inline uint32_t arm_v8m_cm55_systick_get_reload(void) {
    return arm_v8m_systick_get_reload();
}

static inline uint32_t arm_v8m_cm55_systick_get_calib(void) {
    return arm_v8m_systick_get_calib();
}

/*============================================================================*
 * Security Functions - TrustZone
 *============================================================================*/

static inline void arm_v8m_cm55_systick_set_ns_access(uint32_t enable) {
    arm_v8m_systick_set_ns_access(enable);
}

static inline uint32_t arm_v8m_cm55_systick_get_ns_access(void) {
    return arm_v8m_systick_get_ns_access();
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM55_SYSTICK_H */
