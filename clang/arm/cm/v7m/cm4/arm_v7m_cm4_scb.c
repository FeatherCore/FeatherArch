/*
 * arm_v7m_cm4_scb.c
 * Cortex-M4 System Control Block (SCB) Implementation
 * 
 * Reference: ARMv7-M Architecture Reference Manual
 *            - Section B3.2: System Control Block on page B3-601
 *            - Section B3.2.1: SCB register summary on page B3-602
 * 
 *            Cortex-M4 Devices Generic User Guide
 *            - Chapter 4.3: System Control Block on page 4-12
 *            - Section 4.3.1: SCB register summary on page 4-13
 * 
 *            Cortex-M4 Technical Reference Manual
 *            - Chapter 4.3: System Control Block on page 4-3
 * 
 * @note Cortex-M4 SCB is identical to generic Armv7-M SCB.
 *       All functions are implemented as static inline in arm_v7m_cm4_scb.h
 *       to eliminate function call overhead.
 *       This file is kept for compatibility and potential future extensions.
 */

#include "arm_v7m_cm4_scb.h"

/*
 * All SCB functions are implemented as static inline in arm_v7m_cm4_scb.h
 * for optimal performance.
 *
 * The following functions are available as inline functions in the header:
 * - arm_v7m_cm4_scb_set_vector_table() / arm_v7m_cm4_scb_get_vector_table()
 * - arm_v7m_cm4_scb_system_reset()
 * - arm_v7m_cm4_scb_set_priority_grouping() / arm_v7m_cm4_scb_get_priority_grouping()
 * - arm_v7m_cm4_scb_enable_fault() / arm_v7m_cm4_scb_disable_fault()
 * - arm_v7m_cm4_scb_get_fault_status() / arm_v7m_cm4_scb_clear_fault_status()
 */
