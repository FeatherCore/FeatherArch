/*
 * ARM Architecture - Cortex-M4 ITM Implementation
 *
 * ============================================================================
 * File: cm4_itm.c
 * Description: Cortex-M4 ITM function implementations (wrapper for armv7-m_debug.c)
 * 描述: Cortex-M4 ITM 函数实现（armv7-m_debug.c 的包装层）
 *
 * This file is a placeholder. All ITM functionality is provided by:
 * - armv7-m/armv7-m_debug.h (ITM register definitions)
 * - armv7-m/armv7-m_debug.c (ITM function implementations)
 *
 * The CM4-specific functions (cm4_itm_*) are implemented as static inline
 * wrappers in cm4_itm.h, which delegate to the ARMv7-M implementations.
 *
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual (100166_0001_04_en)
 *   - Chapter 10 Instrumentation Trace Macrocell Unit (page 10-87)
 *   - Table 10-1 ITM register summary (page 10-89)
 *
 * Implementation Location:
 *   - Header: armv7-m/armv7-m_debug.h
 *   - Source: armv7-m/armv7-m_debug.c
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/cm4/cm4_itm.h"

/*
 * All ITM functions are implemented as static inline wrappers in cm4_itm.h.
 * They delegate to the corresponding functions in armv7-m_debug.c:
 *
 * cm4_itm_enable()                    -> itm_enable()
 * cm4_itm_disable()                   -> itm_disable()
 * cm4_itm_send_char(port, ch)         -> itm_send_char(port, ch)
 * cm4_itm_send_word(port, value)      -> itm_send_word(port, value)
 * cm4_itm_port_ready(port)            -> itm_port_ready(port)
 * cm4_itm_enable_port(port)           -> itm_enable_port(port)
 * cm4_itm_disable_port(port)          -> itm_disable_port(port)
 *
 * Additional functions available in armv7-m_debug.c:
 * - itm_init()
 * - itm_is_enabled()
 * - itm_send_buffer(port, buf, len)
 * - itm_send_string(port, str)
 * - itm_set_trace_bus_id(id)
 * - itm_get_trace_bus_id()
 * - itm_enable_timestamp()
 * - itm_disable_timestamp()
 * - itm_enable_sync()
 * - itm_disable_sync()
 * - itm_enable_dwt_tx()
 * - itm_disable_dwt_tx()
 * - itm_enable_swo_mode()
 * - itm_disable_swo_mode()
 * - itm_set_timestamp_prescaler(div)
 * - itm_enable_stall()
 * - itm_disable_stall()
 * - itm_is_busy()
 * - itm_set_privilege_mask(mask)
 * - itm_get_privilege_mask()
 */
