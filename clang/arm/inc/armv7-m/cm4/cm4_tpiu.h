/*
 * ARM Architecture - Cortex-M4 TPIU (Trace Port Interface Unit)
 *
 * ============================================================================
 * File: cm4_tpiu.h
 * Description: Cortex-M4 TPIU register definitions (wrapper for armv7-m_tpiu.h)
 * 描述: Cortex-M4 TPIU 寄存器定义（armv7-m_tpiu.h 的包装层）
 *
 * This file provides CM4-specific naming conventions while delegating
 * all actual definitions to armv7-m_tpiu.h.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.9 Trace Port Interface Unit (page 4-65)
 *   - Table 4-61 TPIU registers summary (page 4-65)
 *
 * Implementation: All functionality is provided by armv7-m/armv7-m_tpiu.h
 * Note: All register definitions are directly available from armv7-m_tpiu.h
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_TPIU_H__
#define __CM4_TPIU_H__

#include <stdint.h>

/* Include the underlying ARMv7-M implementation */
/* This provides all TPIU register definitions and bit fields */
#include "armv7-m/armv7-m_tpiu.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * TPIU Base Address Alias
 * TPIU 基地址别名
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-61 (page 4-65)
 * ============================================================================
 */

#define CM4_TPIU_BASE_ADDR            TPIU_BASE_ADDR

/*
 * ============================================================================
 * TPIU Register Definitions (Directly from armv7-m_tpiu.h)
 * The following registers are directly available from armv7-m_tpiu.h:
 * - TPIU_SSPSR - Supported Port Size Register
 * - TPIU_CSPSR - Current Port Size Register
 * - TPIU_ACPR - Asynchronous Clock Prescaler Register
 * - TPIU_SPPR - Selected Pin Protocol Register
 * - TPIU_FFCR - Formatter and Flush Control Register
 * - TPIU_FSCR - Formatter Synchronization Counter Register
 * - TPIU_CLAIMSET - Claim Tag Set Register
 * - TPIU_CLAIMCLR - Claim Tag Clear Register
 * - TPIU_DEVID - Device ID Register
 * - TPIU_DEVTYPE - Device Type Identifier Register
 *
 * Bit definitions are also available:
 * - TPIU_CSPSR_PORTSIZE_Pos, TPIU_CSPSR_PORTSIZE_Msk
 * - TPIU_ACPR_SWOSCALER_Pos, TPIU_ACPR_SWOSCALER_Msk
 * - TPIU_SPPR_TXMODE_Pos, TPIU_SPPR_TXMODE_Msk
 * - TPIU_TXMODE_SYNC, TPIU_TXMODE_ASYNC_SWO_MANCHESTER, TPIU_TXMODE_ASYNC_SWO_NRZ
 * - TPIU_FFCR_*, TPIU_FSCR_*, TPIU_CLAIMSET_*, TPIU_CLAIMCLR_*
 * - TPIU_DEVID_*, TPIU_DEVTYPE_*
 * ============================================================================
 */

/*
 * ============================================================================
 * TPIU Function Wrapper Declarations
 * TPIU 函数包装器声明
 * Implementation: Delegates to functions in armv7-m_tpiu.c
 * ============================================================================
 */

/**
 * @brief Initialize TPIU
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.9 (page 4-65)
 * Implementation: Delegates to tpiu_init() in armv7-m_tpiu.c
 */
static inline void cm4_tpiu_init(void)
{
    tpiu_init();
}

/**
 * @brief Set TPIU port size
 * @param port_size Port size value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.9.2 (page 4-66)
 * Implementation: Delegates to tpiu_set_port_size() in armv7-m_tpiu.c
 */
static inline void cm4_tpiu_set_port_size(uint32_t port_size)
{
    tpiu_set_port_size(port_size);
}

/**
 * @brief Get TPIU port size
 * @return Current port size value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.9.2 (page 4-66)
 * Implementation: Delegates to tpiu_get_port_size() in armv7-m_tpiu.c
 */
static inline uint32_t cm4_tpiu_get_port_size(void)
{
    return tpiu_get_port_size();
}

/**
 * @brief Set asynchronous clock prescaler
 * @param prescaler Prescaler value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.9.3 (page 4-67)
 * Implementation: Delegates to tpiu_set_acpr() in armv7-m_tpiu.c
 */
static inline void cm4_tpiu_set_acpr(uint32_t prescaler)
{
    tpiu_set_acpr(prescaler);
}

/**
 * @brief Get asynchronous clock prescaler
 * @return Current prescaler value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.9.3 (page 4-67)
 * Implementation: Delegates to tpiu_get_acpr() in armv7-m_tpiu.c
 */
static inline uint32_t cm4_tpiu_get_acpr(void)
{
    return tpiu_get_acpr();
}

/**
 * @brief Set pin protocol
 * @param protocol Protocol type (TPIU_TXMODE_*)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.9.4 (page 4-67)
 * Implementation: Delegates to tpiu_set_pin_protocol() in armv7-m_tpiu.c
 */
static inline void cm4_tpiu_set_pin_protocol(uint32_t protocol)
{
    tpiu_set_pin_protocol(protocol);
}

/**
 * @brief Get pin protocol
 * @return Current protocol type
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.9.4 (page 4-67)
 * Implementation: Delegates to tpiu_get_pin_protocol() in armv7-m_tpiu.c
 */
static inline uint32_t cm4_tpiu_get_pin_protocol(void)
{
    return tpiu_get_pin_protocol();
}

/**
 * @brief Enable formatter
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.9.5 (page 4-68)
 * Implementation: Delegates to tpiu_enable_formatter() in armv7-m_tpiu.c
 */
static inline void cm4_tpiu_enable_formatter(void)
{
    tpiu_enable_formatter();
}

/**
 * @brief Disable formatter
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.9.5 (page 4-68)
 * Implementation: Delegates to tpiu_disable_formatter() in armv7-m_tpiu.c
 */
static inline void cm4_tpiu_disable_formatter(void)
{
    tpiu_disable_formatter();
}

/**
 * @brief Enable flush on trigger
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.9.5 (page 4-68)
 * Implementation: Delegates to tpiu_enable_flush_on_trigger() in armv7-m_tpiu.c
 */
static inline void cm4_tpiu_enable_flush_on_trigger(void)
{
    tpiu_enable_flush_on_trigger();
}

/**
 * @brief Disable flush on trigger
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.9.5 (page 4-68)
 * Implementation: Delegates to tpiu_disable_flush_on_trigger() in armv7-m_tpiu.c
 */
static inline void cm4_tpiu_disable_flush_on_trigger(void)
{
    tpiu_disable_flush_on_trigger();
}

/**
 * @brief Get TPIU device ID
 * @return Device ID value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.9.7 (page 4-69)
 * Implementation: Delegates to tpiu_get_device_id() in armv7-m_tpiu.c
 */
static inline uint32_t cm4_tpiu_get_device_id(void)
{
    return tpiu_get_device_id();
}

/**
 * @brief Check if TPIU is present
 * @return 1 if present, 0 if not
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.9 (page 4-65)
 * Implementation: Delegates to tpiu_is_present() in armv7-m_tpiu.c
 */
static inline int cm4_tpiu_is_present(void)
{
    return tpiu_is_present();
}

#ifdef __cplusplus
}
#endif

#endif /* __CM4_TPIU_H__ */
