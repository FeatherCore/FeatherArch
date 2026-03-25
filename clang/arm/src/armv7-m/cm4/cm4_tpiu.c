/*
 * ARM Architecture - Cortex-M4 TPIU Implementation
 *
 * ============================================================================
 * File: cm4_tpiu.c
 * Description: Cortex-M4 TPIU function implementations (wrapper for armv7-m_tpiu.c)
 * 描述: Cortex-M4 TPIU 函数实现（armv7-m_tpiu.c 的包装层）
 *
 * This file is a placeholder. All TPIU functionality is provided by:
 * - armv7-m/armv7-m_tpiu.h (register definitions)
 * - armv7-m/armv7-m_tpiu.c (function implementations)
 *
 * The CM4-specific functions (cm4_tpiu_*) are implemented as static inline
 * wrappers in cm4_tpiu.h, which delegate to the ARMv7-M implementations.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.9 Trace Port Interface Unit (page 4-65)
 *   - Table 4-61 TPIU registers summary (page 4-65)
 *
 * Implementation Location:
 *   - Header: armv7-m/armv7-m_tpiu.h
 *   - Source: armv7-m/armv7-m_tpiu.c
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/cm4/cm4_tpiu.h"

/*
 * All TPIU functions are implemented as static inline wrappers in cm4_tpiu.h.
 * They delegate to the corresponding functions in armv7-m_tpiu.c:
 *
 * cm4_tpiu_init()                         -> tpiu_init()
 * cm4_tpiu_set_port_size(size)            -> tpiu_set_port_size(size)
 * cm4_tpiu_get_port_size()                -> tpiu_get_port_size()
 * cm4_tpiu_set_acpr(prescaler)            -> tpiu_set_acpr(prescaler)
 * cm4_tpiu_get_acpr()                     -> tpiu_get_acpr()
 * cm4_tpiu_set_pin_protocol(protocol)     -> tpiu_set_pin_protocol(protocol)
 * cm4_tpiu_get_pin_protocol()             -> tpiu_get_pin_protocol()
 * cm4_tpiu_enable_formatter()             -> tpiu_enable_formatter()
 * cm4_tpiu_disable_formatter()            -> tpiu_disable_formatter()
 * cm4_tpiu_enable_flush_on_trigger()      -> tpiu_enable_flush_on_trigger()
 * cm4_tpiu_disable_flush_on_trigger()     -> tpiu_disable_flush_on_trigger()
 * cm4_tpiu_get_device_id()                -> tpiu_get_device_id()
 * cm4_tpiu_is_present()                   -> tpiu_is_present()
 *
 * Additional functions available in armv7-m_tpiu.c:
 * - tpiu_get_sspsr()
 * - tpiu_get_cspsr()
 * - tpiu_set_cspsr(cspsr)
 * - tpiu_get_ffcr()
 * - tpiu_set_ffcr(ffcr)
 * - tpiu_get_fscr()
 * - tpiu_set_fscr(fscr)
 * - tpiu_get_claimset()
 * - tpiu_set_claimset(claim)
 * - tpiu_get_claimclr()
 * - tpiu_set_claimclr(claim)
 * - tpiu_get_devtype()
 */
