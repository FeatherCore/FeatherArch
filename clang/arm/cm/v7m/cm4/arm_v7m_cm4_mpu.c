/*
 * arm_v7m_cm4_mpu.c
 * Cortex-M4 Memory Protection Unit (MPU) Implementation
 * 
 * Reference: ARMv7-M Architecture Reference Manual
 *            - Section B3.5: Protected Memory System Architecture, PMSAv7 on page B3-632
 *            - Section B3.5.1: Relation of the MPU to the system memory map on page B3-632
 *            - Section B3.5.2: Behavior when the MPU is disabled on page B3-632
 *            - Section B3.5.3: PMSAv7-compliant MPU operation on page B3-633
 *            - Section B3.5.4: Register support for PMSAv7 in the SCS on page B3-635
 * 
 *            Cortex-M4 Devices Generic User Guide
 *            - Chapter 4.5: Optional Memory Protection Unit on page 4-37
 *            - Section 4.5.1: MPU register summary on page 4-38
 * 
 *            Cortex-M4 Technical Reference Manual
 *            - Chapter 6: Memory Protection Unit on page 6-1
 * 
 * @note Cortex-M4 MPU is identical to generic Armv7-M MPU.
 *       All functions are implemented as static inline in arm_v7m_cm4_mpu.h
 *       to eliminate function call overhead.
 *       This file is kept for compatibility and potential future extensions.
 */

#include "arm_v7m_cm4_mpu.h"

/*
 * All MPU functions are implemented as static inline in arm_v7m_cm4_mpu.h
 * for optimal performance.
 *
 * The following functions are available as inline functions in the header:
 * - arm_v7m_cm4_mpu_enable() / arm_v7m_cm4_mpu_disable()
 * - arm_v7m_cm4_mpu_get_region_count()
 * - arm_v7m_cm4_mpu_select_region()
 * - arm_v7m_cm4_mpu_set_region()
 * - arm_v7m_cm4_mpu_disable_region()
 */
