/*
 * arm_v7m_cm4_debug.c
 * Cortex-M4 Debug Support Implementation
 * 
 * Reference: ARMv7-M Architecture Reference Manual
 *            - Chapter C1: Debug on page C1-696
 *            - Section C1.6: Debug System Registers on page C1-708
 *            - Section C1.7: Instrumentation Trace Macrocell (ITM) on page C1-714
 *            - Section C1.8: Data Watchpoint and Trace (DWT) on page C1-717
 *            - Section C1.10: Flash Patch and Breakpoint (FPB) on page C1-725
 * 
 *            Cortex-M4 Devices Generic User Guide
 *            - Chapter 10: Debug on page 10-2
 *            - Chapter 11: Debug and Trace Components on page 11-2
 * 
 *            Cortex-M4 Technical Reference Manual
 *            - Chapter 8: Debug on page 8-2
 *            - Chapter 9: Data Watchpoint and Trace Unit on page 9-2
 *            - Chapter 10: Flash Patch and Breakpoint Unit on page 10-2
 *            - Chapter 11: Instrumentation Trace Macrocell on page 11-2
 * 
 * @note Cortex-M4 Debug is identical to generic Armv7-M Debug.
 *       All functions are implemented as static inline in arm_v7m_cm4_debug.h
 *       to eliminate function call overhead.
 *       This file is kept for compatibility and potential future extensions.
 */

#include "arm_v7m_cm4_debug.h"

/*
 * All Debug functions are implemented as static inline in arm_v7m_cm4_debug.h
 * for optimal performance.
 *
 * The following functions are available as inline functions in the header:
 * - arm_v7m_cm4_debug_enable_trace() / arm_v7m_cm4_debug_disable_trace()
 * - arm_v7m_cm4_debug_is_halted()
 * - arm_v7m_cm4_debug_halt() / arm_v7m_cm4_debug_resume()
 * - arm_v7m_cm4_debug_step()
 * - arm_v7m_cm4_dwt_enable_cyccnt() / arm_v7m_cm4_dwt_disable_cyccnt()
 * - arm_v7m_cm4_dwt_get_cyccnt() / arm_v7m_cm4_dwt_set_cyccnt()
 * - arm_v7m_cm4_dwt_enable_exception_trace()
 * - arm_v7m_cm4_dwt_enable_pc_sampling()
 * - arm_v7m_cm4_fpb_enable() / arm_v7m_cm4_fpb_disable()
 * - arm_v7m_cm4_fpb_set_breakpoint() / arm_v7m_cm4_fpb_clear_breakpoint()
 */
