/*
 * ARM Architecture - Cortex-M4 FPU Implementation
 *
 * ============================================================================
 * File: cm4_fpu.c
 * Description: Cortex-M4 FPU function implementations (wrapper for armv7-m_fpu.c)
 * 描述: Cortex-M4 FPU 函数实现（armv7-m_fpu.c 的包装层）
 *
 * This file is a placeholder. All FPU functionality is provided by:
 * - armv7-m/armv7-m_fpu.h (register definitions)
 * - armv7-m/armv7-m_fpu.c (function implementations)
 *
 * The CM4-specific functions (cm4_fpu_*) are implemented as static inline
 * wrappers in cm4_fpu.h, which delegate to the ARMv7-M implementations.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.6 Floating Point Unit (page 4-48)
 *   - Table 4-49 Cortex-M4 Floating Point system registers (page 4-48)
 *
 * Implementation Location:
 *   - Header: armv7-m/armv7-m_fpu.h
 *   - Source: armv7-m/armv7-m_fpu.c
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/cm4/cm4_fpu.h"

/*
 * All FPU functions are implemented as static inline wrappers in cm4_fpu.h.
 * They delegate to the corresponding functions in armv7-m_fpu.c:
 *
 * cm4_fpu_enable()                          -> fpu_enable()
 * cm4_fpu_disable()                         -> fpu_disable()
 * cm4_fpu_is_enabled()                      -> fpu_is_enabled()
 * cm4_fpu_enable_lazy_state_preservation()  -> fpu_enable_lazy_state_preservation()
 * cm4_fpu_disable_lazy_state_preservation() -> fpu_disable_lazy_state_preservation()
 * cm4_fpu_enable_auto_state_preservation()  -> fpu_enable_auto_state_preservation()
 * cm4_fpu_disable_auto_state_preservation() -> fpu_disable_auto_state_preservation()
 * cm4_fpu_get_lazy_state_active()           -> fpu_get_lazy_state_active()
 * cm4_fpu_set_default_rounding_mode(mode)   -> fpu_set_default_rounding_mode(mode)
 * cm4_fpu_get_default_rounding_mode()       -> fpu_get_default_rounding_mode()
 * cm4_fpu_enable_default_ftz()              -> fpu_enable_default_ftz()
 * cm4_fpu_disable_default_ftz()             -> fpu_disable_default_ftz()
 * cm4_fpu_enable_default_dnan()             -> fpu_enable_default_dnan()
 * cm4_fpu_disable_default_dnan()            -> fpu_disable_default_dnan()
 * cm4_fpu_is_present()                      -> fpu_is_present()
 *
 * Additional functions available in armv7-m_fpu.c:
 * - fpu_get_fpccr()
 * - fpu_set_fpccr(fpccr)
 * - fpu_get_fpcar()
 * - fpu_set_fpcar(fpcar)
 * - fpu_get_fpdscr()
 * - fpu_set_fpdscr(fpdscr)
 * - fpu_get_mvfr0()
 * - fpu_get_mvfr1()
 * - fpu_get_fpscr()
 * - fpu_set_fpscr(fpscr)
 */
