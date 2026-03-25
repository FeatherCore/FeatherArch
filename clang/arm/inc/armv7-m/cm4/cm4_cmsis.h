/*
 * ARM Architecture - Cortex-M4 CMSIS Intrinsic Functions
 *
 * ============================================================================
 * File: cm4_cmsis.h
 * Description: Cortex-M4 CMSIS intrinsic function definitions (wrapper for armv7-m_core.h)
 * 描述: Cortex-M4 CMSIS 内联函数定义（armv7-m_core.h 的包装层）
 *
 * This file provides CM4-specific naming conventions while delegating
 * all actual definitions to armv7-m_core.h.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 3.2 CMSIS functions (page 3-9)
 *   - Table 3-2 CMSIS functions to generate some Cortex-M4 instructions (page 3-9)
 *   - Table 3-3 CMSIS functions to access the special registers (page 3-9)
 *
 * Implementation: All functionality is provided by armv7-m/armv7-m_core.h
 * Note: This file only provides functions with different names from armv7-m_core.h.
 *       Functions with the same name are directly available from armv7-m_core.h.
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_CMSIS_H__
#define __CM4_CMSIS_H__

#include <stdint.h>

/* Include the underlying ARMv7-M implementation */
/* This provides: __ISB, __DSB, __DMB, __WFI, __WFE, __SEV, __NOP, __BKPT, __CLREX,
 *                __get_PRIMASK, __set_PRIMASK, __get_FAULTMASK, __set_FAULTMASK,
 *                __get_BASEPRI, __set_BASEPRI, __get_CONTROL, __set_CONTROL,
 *                __get_MSP, __set_MSP, __get_PSP, __set_PSP,
 *                __get_APSR, __get_IPSR, __get_xPSR,
 *                __LDREXB, __LDREXH, __LDREXW, __STREXB, __STREXH, __STREXW,
 *                __enable_interrupts, __disable_interrupts, __enable_fault_irq, __disable_fault_irq,
 *                armv7m_rev, armv7m_rev16, armv7m_revsh, armv7m_rbit, armv7m_ssat, armv7m_usat, armv7m_clz */
#include "armv7-m/armv7-m_core.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * CMSIS Functions with Different Names from armv7-m_core.h
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * ============================================================================
 */

/**
 * @brief Enable IRQ
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Implementation: Delegates to __enable_interrupts() in armv7-m_core.h
 */
static inline void __enable_irq(void)
{
    __enable_interrupts();
}

/**
 * @brief Disable IRQ
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Implementation: Delegates to __disable_interrupts() in armv7-m_core.h
 */
static inline void __disable_irq(void)
{
    __disable_interrupts();
}

/*
 * ============================================================================
 * CMSIS Functions with Same Names (Directly from armv7-m_core.h)
 * The following functions are directly available from armv7-m_core.h:
 * - __ISB(), __DSB(), __DMB() - Memory barriers
 * - __WFI(), __WFE(), __SEV() - Wait and event functions
 * - __NOP(), __BKPT() - Debug functions
 * - __CLREX() - Exclusive access
 * - __get_PRIMASK(), __set_PRIMASK() - PRIMASK access
 * - __get_FAULTMASK(), __set_FAULTMASK() - FAULTMASK access
 * - __get_BASEPRI(), __set_BASEPRI() - BASEPRI access
 * - __get_CONTROL(), __set_CONTROL() - CONTROL access
 * - __get_MSP(), __set_MSP() - MSP access
 * - __get_PSP(), __set_PSP() - PSP access
 * - __get_APSR(), __get_IPSR(), __get_xPSR() - PSR access
 * - __LDREXB(), __LDREXH(), __LDREXW() - Load exclusive
 * - __STREXB(), __STREXH(), __STREXW() - Store exclusive
 * - __enable_fault_irq(), __disable_fault_irq() - Fault control
 */

/*
 * ============================================================================
 * CMSIS Functions for Byte/Bit Operations
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Implementation: Delegates to armv7-m_core.h functions
 * ============================================================================
 */

/**
 * @brief Reverse byte order (32-bit)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Implementation: Delegates to armv7m_rev() in armv7-m_core.h
 */
static inline uint32_t __REV(uint32_t value)
{
    return armv7m_rev(value);
}

/**
 * @brief Reverse byte order in each halfword independently
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Implementation: Delegates to armv7m_rev16() in armv7-m_core.h
 */
static inline uint32_t __REV16(uint32_t value)
{
    return armv7m_rev16(value);
}

/**
 * @brief Reverse byte order in bottom halfword and sign extend
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Implementation: Delegates to armv7m_revsh() in armv7-m_core.h
 */
static inline int32_t __REVSH(int32_t value)
{
    return armv7m_revsh(value);
}

/**
 * @brief Reverse bits
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Implementation: Delegates to armv7m_rbit() in armv7-m_core.h
 */
static inline uint32_t __RBIT(uint32_t value)
{
    return armv7m_rbit(value);
}

/**
 * @brief Signed Saturate
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.8.1 (page 3-96)
 * Implementation: Delegates to armv7m_ssat() in armv7-m_core.h
 */
static inline int32_t __SSAT(int32_t val, uint32_t sat)
{
    return armv7m_ssat(val, sat);
}

/**
 * @brief Unsigned Saturate
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.8.2 (page 3-96)
 * Implementation: Delegates to armv7m_usat() in armv7-m_core.h
 */
static inline uint32_t __USAT(int32_t val, uint32_t sat)
{
    return armv7m_usat(val, sat);
}

/**
 * @brief Count Leading Zeros
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.5.4 (page 3-48)
 * Implementation: Delegates to armv7m_clz() in armv7-m_core.h
 */
static inline uint8_t __CLZ(uint32_t value)
{
    return armv7m_clz(value);
}

#ifdef __cplusplus
}
#endif

#endif /* __CM4_CMSIS_H__ */
