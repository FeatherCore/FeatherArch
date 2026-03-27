/*
 * arm_v7m_cm4_systick.c
 * Cortex-M4 System Timer (SysTick) Implementation
 * 
 * Reference: ARMv7-M Architecture Reference Manual
 *            - Section B3.3: System Timer, SysTick on page B3-596
 *            - Section B3.3.1: SysTick register summary on page B3-596
 * 
 *            Cortex-M4 Devices Generic User Guide
 *            - Chapter 4.4: System Timer, SysTick on page 4-32
 *            - Section 4.4.1: SysTick register summary on page 4-33
 * 
 *            Cortex-M4 Technical Reference Manual
 *            - Chapter 4.4: System Timer, SysTick on page 4-4
 * 
 * @note Cortex-M4 SysTick is identical to generic Armv7-M SysTick.
 *       All functions are implemented as static inline in arm_v7m_cm4_systick.h
 *       to eliminate function call overhead.
 *       This file is kept for compatibility and potential future extensions.
 */

#include "arm_v7m_cm4_systick.h"

/*
 * All SysTick functions are implemented as static inline in arm_v7m_cm4_systick.h
 * for optimal performance.
 *
 * The following functions are available as inline functions in the header:
 * - arm_v7m_cm4_systick_init()
 * - arm_v7m_cm4_systick_enable() / arm_v7m_cm4_systick_disable()
 * - arm_v7m_cm4_systick_get_count()
 * - arm_v7m_cm4_systick_set_reload() / arm_v7m_cm4_systick_get_reload()
 * - arm_v7m_cm4_systick_get_calib()
 */
