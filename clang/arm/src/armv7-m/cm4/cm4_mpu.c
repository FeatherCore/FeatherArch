/*
 * ARM Architecture - Cortex-M4 MPU Implementation
 *
 * ============================================================================
 * File: cm4_mpu.c
 * Description: Cortex-M4 MPU function implementations (wrapper for armv7-m_mpu.c)
 * 描述: Cortex-M4 MPU 函数实现（armv7-m_mpu.c 的包装层）
 *
 * This file is a placeholder. All MPU functionality is provided by:
 * - armv7-m/armv7-m_mpu.h (register definitions)
 * - armv7-m/armv7-m_mpu.c (function implementations)
 *
 * The CM4-specific functions (cm4_mpu_*) are implemented as static inline
 * wrappers in cm4_mpu.h, which delegate to the ARMv7-M implementations.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.5 Optional Memory Protection Unit (page 4-37)
 *   - Table 4-38 MPU registers summary (page 4-38)
 *
 * Implementation Location:
 *   - Header: armv7-m/armv7-m_mpu.h
 *   - Source: armv7-m/armv7-m_mpu.c
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/cm4/cm4_mpu.h"

/*
 * All MPU functions are implemented as static inline wrappers in cm4_mpu.h.
 * They delegate to the corresponding functions in armv7-m_mpu.c:
 *
 * cm4_mpu_enable()                          -> mpu_enable()
 * cm4_mpu_disable()                         -> mpu_disable()
 * cm4_mpu_enable_with_default_map()         -> mpu_enable_with_default_map()
 * cm4_mpu_select_region(region)             -> mpu_select_region(region)
 * cm4_mpu_set_region_base(addr)             -> mpu_set_region_base(addr)
 * cm4_mpu_set_region_attr(size, srd, attr, ap, xn, enable) -> mpu_set_region_attr(size, srd, attr, ap, xn, enable)
 * cm4_mpu_configure_region(region, base, size, srd, attr, ap, xn) -> mpu_configure_region(region, base, size, attr, srd)
 * cm4_mpu_disable_region(region)            -> mpu_disable_region(region)
 * cm4_mpu_get_region_count()                -> mpu_get_num_regions()
 * cm4_mpu_is_present()                      -> mpu_is_present()
 *
 * Additional functions available in armv7-m_mpu.c:
 * - mpu_get_type()
 * - mpu_get_ctrl()
 * - mpu_set_ctrl(ctrl)
 * - mpu_get_rnr()
 * - mpu_get_rbar()
 * - mpu_set_rbar(rbar)
 * - mpu_get_rasr()
 * - mpu_set_rasr(rasr)
 * - mpu_get_region_base()
 * - mpu_get_region_size(region)
 * - mpu_get_region_attr(region)
 * - mpu_is_region_enabled(region)
 * - mpu_enable_dregion()
 * - mpu_disable_dregion()
 * - mpu_enable_hfnmi()
 * - mpu_disable_hfnmi()
 * - mpu_enable_priv_default()
 * - mpu_disable_priv_default()
 * - mpu_check_addr(addr)
 */
