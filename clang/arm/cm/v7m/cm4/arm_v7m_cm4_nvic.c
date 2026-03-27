/*
 * arm_v7m_cm4_nvic.c
 * Cortex-M4 Nested Vectored Interrupt Controller (NVIC) Implementation
 * 
 * Reference: ARMv7-M Architecture Reference Manual
 *            - Section B3.4: Nested Vectored Interrupt Controller on page B3-597
 *            - Section B3.4.1: NVIC register summary on page B3-597
 *            - Section B3.4.2: NVIC register descriptions on page B3-598
 * 
 *            Cortex-M4 Devices Generic User Guide
 *            - Chapter 4.2: Nested Vectored Interrupt Controller on page 4-4
 *            - Section 4.2.1: NVIC register summary on page 4-5
 * 
 *            Cortex-M4 Technical Reference Manual
 *            - Chapter 4.2: Nested Vectored Interrupt Controller on page 4-2
 * 
 * @note Cortex-M4 NVIC is identical to generic Armv7-M NVIC.
 *       All functions are implemented as static inline in arm_v7m_cm4_nvic.h
 *       to eliminate function call overhead.
 *       This file is kept for compatibility and potential future extensions.
 */

#include "arm_v7m_cm4_nvic.h"

/*
 * All NVIC functions are implemented as static inline in arm_v7m_cm4_nvic.h
 * for optimal performance.
 *
 * The following functions are available as inline functions in the header:
 * - arm_v7m_cm4_nvic_enable_irq() / arm_v7m_cm4_nvic_disable_irq()
 * - arm_v7m_cm4_nvic_get_pending_irq() / arm_v7m_cm4_nvic_set_pending_irq()
 * - arm_v7m_cm4_nvic_clear_pending_irq()
 * - arm_v7m_cm4_nvic_get_active_irq()
 * - arm_v7m_cm4_nvic_set_priority() / arm_v7m_cm4_nvic_get_priority()
 * - arm_v7m_cm4_nvic_system_reset()
 */
