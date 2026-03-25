/*
 * ARM Architecture - Cortex-M4 Debug Implementation
 *
 * ============================================================================
 * File: cm4_debug.c
 * Description: Cortex-M4 Debug function implementations (wrapper for armv7-m_debug.c)
 * 描述: Cortex-M4 Debug 函数实现（armv7-m_debug.c 的包装层）
 *
 * This file is a placeholder. All Debug functionality is provided by:
 * - armv7-m/armv7-m_debug.h (register definitions)
 * - armv7-m/armv7-m_debug.c (function implementations)
 *
 * The CM4-specific functions (cm4_debug_*) are implemented as static inline
 * wrappers in cm4_debug.h, which delegate to the ARMv7-M implementations.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.7 Debug system (page 4-53)
 *   - Table 4-54 Debug registers (page 4-54)
 *
 * Implementation Location:
 *   - Header: armv7-m/armv7-m_debug.h
 *   - Source: armv7-m/armv7-m_debug.c
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/cm4/cm4_debug.h"

/*
 * All Debug functions are implemented as static inline wrappers in cm4_debug.h.
 * They delegate to the corresponding functions in armv7-m_debug.c:
 *
 * cm4_debug_enable()                    -> debug_enable()
 * cm4_debug_disable()                   -> debug_disable()
 * cm4_debug_is_enabled()                -> debug_is_enabled()
 * cm4_debug_halt()                      -> debug_halt()
 * cm4_debug_resume()                    -> debug_resume()
 * cm4_debug_is_halted()                 -> debug_is_halted()
 * cm4_debug_step()                      -> debug_step()
 * cm4_debug_enable_trace()              -> debug_enable_trace()
 * cm4_debug_disable_trace()             -> debug_disable_trace()
 * cm4_debug_is_trace_enabled()          -> debug_is_trace_enabled()
 * cm4_debug_enable_monitor()            -> debug_enable_monitor()
 * cm4_debug_disable_monitor()           -> debug_disable_monitor()
 * cm4_debug_enable_vc_harderr()         -> debug_enable_vc_harderr()
 * cm4_debug_disable_vc_harderr()        -> debug_disable_vc_harderr()
 * cm4_debug_enable_vc_reset()           -> debug_enable_vc_reset()
 * cm4_debug_disable_vc_reset()          -> debug_disable_vc_reset()
 *
 * Additional functions available in armv7-m_debug.c:
 * - debug_get_dhcsr()
 * - debug_set_dhcsr(dhcsr)
 * - debug_get_dcrsr()
 * - debug_set_dcrsr(dcrsr)
 * - debug_get_dcrdr()
 * - debug_set_dcrdr(dcrdr)
 * - debug_get_demcr()
 * - debug_set_demcr(demcr)
 * - debug_is_reset_st()
 * - debug_is_retire_st()
 * - debug_is_lockup()
 * - debug_is_sleep()
 * - debug_is_regrdy()
 * - debug_mask_interrupts(mask)
 * - debug_is_interrupts_masked()
 */
