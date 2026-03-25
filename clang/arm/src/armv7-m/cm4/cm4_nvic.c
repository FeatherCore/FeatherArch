/*
 * ARM Architecture - Cortex-M4 NVIC Implementation
 *
 * ============================================================================
 * File: cm4_nvic.c
 * Description: Cortex-M4 NVIC function implementations (wrapper for armv7-m_nvic.c)
 * 描述: Cortex-M4 NVIC 函数实现（armv7-m_nvic.c 的包装层）
 *
 * This file is a placeholder. All NVIC functionality is provided by:
 * - armv7-m/armv7-m_nvic.h (register definitions)
 * - armv7-m/armv7-m_nvic.c (function implementations)
 *
 * The CM4-specific functions (cm4_nvic_*) are implemented as static inline
 * wrappers in cm4_nvic.h, which delegate to the ARMv7-M implementations.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.2 Nested Vectored Interrupt Controller (page 4-3)
 *   - Table 4-2 NVIC register map (page 4-3)
 *
 * Implementation Location:
 *   - Header: armv7-m/armv7-m_nvic.h
 *   - Source: armv7-m/armv7-m_nvic.c
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/cm4/cm4_nvic.h"

/*
 * All NVIC functions are implemented as static inline wrappers in cm4_nvic.h.
 * They delegate to the corresponding functions in armv7-m_nvic.c:
 *
 * cm4_nvic_enable_irq(irq)       -> nvic_enable_irq(irq)
 * cm4_nvic_disable_irq(irq)      -> nvic_disable_irq(irq)
 * cm4_nvic_get_enable_irq(irq)   -> nvic_get_enable_irq(irq)
 * cm4_nvic_set_pending(irq)      -> nvic_set_pending(irq)
 * cm4_nvic_clear_pending(irq)    -> nvic_clear_pending(irq)
 * cm4_nvic_get_pending(irq)      -> nvic_get_pending(irq)
 * cm4_nvic_get_active(irq)       -> nvic_get_active(irq)
 * cm4_nvic_set_priority(irq, p)  -> nvic_set_priority(irq, p)
 * cm4_nvic_get_priority(irq)     -> nvic_get_priority(irq)
 * cm4_nvic_trigger_irq(irq)      -> Direct NVIC_STIR register access
 *
 * Additional functions available in armv7-m_nvic.c:
 * - nvic_set_priority_grouping(group)
 * - nvic_get_priority_grouping()
 * - nvic_encode_priority(group, preempt, sub)
 * - nvic_decode_priority(priority, group, &preempt, &sub)
 * - nvic_system_reset()
 */
