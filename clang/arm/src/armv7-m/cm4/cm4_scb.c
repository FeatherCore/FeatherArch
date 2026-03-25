/*
 * ARM Architecture - Cortex-M4 SCB Implementation
 *
 * ============================================================================
 * File: cm4_scb.c
 * Description: Cortex-M4 SCB function implementations (wrapper for armv7-m_scb.c)
 * 描述: Cortex-M4 SCB 函数实现（armv7-m_scb.c 的包装层）
 *
 * This file is a placeholder. All SCB functionality is provided by:
 * - armv7-m/armv7-m_scb.h (register definitions)
 * - armv7-m/armv7-m_scb.c (function implementations)
 *
 * The CM4-specific functions (cm4_scb_*) are implemented as static inline
 * wrappers in cm4_scb.h, which delegate to the ARMv7-M implementations.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.3 System control block (page 4-10)
 *   - Table 4-12 SCB registers summary (page 4-11)
 *
 * Implementation Location:
 *   - Header: armv7-m/armv7-m_scb.h
 *   - Source: armv7-m/armv7-m_scb.c
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/cm4/cm4_scb.h"

/*
 * All SCB functions are implemented as static inline wrappers in cm4_scb.h.
 * They delegate to the corresponding functions in armv7-m_scb.c:
 *
 * cm4_scb_set_vtor(offset)              -> scb_set_vtor(offset)
 * cm4_scb_get_vtor()                    -> scb_get_vtor()
 * cm4_scb_system_reset()                -> scb_system_reset()
 * cm4_scb_set_priority_grouping(group)  -> scb_set_priority_grouping(group)
 * cm4_scb_get_priority_grouping()       -> scb_get_priority_grouping()
 * cm4_scb_enable_memfault()             -> scb_enable_memmanage()
 * cm4_scb_enable_busfault()             -> scb_enable_bus_fault()
 * cm4_scb_enable_usagefault()           -> scb_enable_usage_fault()
 * cm4_scb_get_cpuid()                   -> scb_get_cpuid()
 *
 * Additional functions available in armv7-m_scb.c:
 * - scb_get_implementer()
 * - scb_get_variant()
 * - scb_get_architecture()
 * - scb_get_partno()
 * - scb_get_revision()
 * - scb_disable_usage_fault()
 * - scb_disable_bus_fault()
 * - scb_disable_memmanage()
 * - scb_get_active_exception()
 * - scb_get_pending_exception()
 * - scb_in_handler_mode()
 * - scb_get_priority_bits()
 * - scb_clear_fault_status()
 * - scb_get_mmfar()
 * - scb_get_bfar()
 * - scb_mmfar_valid()
 * - scb_bfar_valid()
 * - scb_trigger_pendsv()
 * - scb_clear_pendsv()
 * - scb_trigger_systick()
 * - scb_clear_systick()
 * - scb_interrupt_pending()
 * - scb_return_to_base()
 * - scb_get_id_pfr0(), scb_get_id_pfr1()
 * - scb_get_id_dfr0(), scb_get_id_afr0()
 * - scb_get_id_mmfr0() - scb_get_id_mmfr3()
 * - scb_get_id_isar0() - scb_get_id_isar4()
 * - scb_get_clidr(), scb_get_ctr()
 * - scb_get_ccsidr(), scb_get_csselr(), scb_set_csselr()
 * - scb_has_thumb2_support(), scb_has_two_stack_support()
 * - scb_has_pmsa_v7()
 */
