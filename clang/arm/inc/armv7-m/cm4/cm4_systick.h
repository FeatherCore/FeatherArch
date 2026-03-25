/*
 * ARM Architecture - Cortex-M4 SysTick Timer
 *
 * ============================================================================
 * File: cm4_systick.h
 * Description: Cortex-M4 SysTick timer register definitions (wrapper for armv7-m_systick.h)
 * 描述: Cortex-M4 SysTick 定时器寄存器定义（armv7-m_systick.h 的包装层）
 *
 * This file provides CM4-specific naming conventions while delegating
 * all actual definitions to armv7-m_systick.h.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.4 System timer, SysTick (page 4-32)
 *   - Table 4-32 System timer registers summary (page 4-33)
 *
 * Implementation: All functionality is provided by armv7-m/armv7-m_systick.h
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_SYSTICK_H__
#define __CM4_SYSTICK_H__

#include <stdint.h>
#include <stdbool.h>

/* Include the underlying ARMv7-M implementation */
#include "armv7-m/armv7-m_systick.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * SysTick Base Address Alias
 * SysTick 基地址别名
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-32 (page 4-33)
 * ============================================================================
 */

#define CM4_SYSTICK_BASE_ADDR         SYSTICK_BASE_ADDR

/*
 * ============================================================================
 * Register Aliases - Map CM4 naming to ARMv7-M naming
 * 寄存器别名 - 将 CM4 命名映射到 ARMv7-M 命名
 * ============================================================================
 */

/* SysTick Control and Status Register */
#define SYST_CSR                      (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x000))

/* SYST_CSR bit definitions */
#define SYST_CSR_ENABLE_Pos           SYST_CSR_ENABLE_Pos
#define SYST_CSR_ENABLE_Msk           SYST_CSR_ENABLE_Msk
#define SYST_CSR_TICKINT_Pos          SYST_CSR_TICKINT_Pos
#define SYST_CSR_TICKINT_Msk          SYST_CSR_TICKINT_Msk
#define SYST_CSR_CLKSOURCE_Pos        SYST_CSR_CLKSOURCE_Pos
#define SYST_CSR_CLKSOURCE_Msk        SYST_CSR_CLKSOURCE_Msk
#define SYST_CSR_COUNTFLAG_Pos        SYST_CSR_COUNTFLAG_Pos
#define SYST_CSR_COUNTFLAG_Msk        SYST_CSR_COUNTFLAG_Msk

/* SysTick Reload Value Register */
#define SYST_RVR                      (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x004))

/* SYST_RVR bit definitions */
#define SYST_RVR_RELOAD_Pos           SYST_RVR_RELOAD_Pos
#define SYST_RVR_RELOAD_Msk           SYST_RVR_RELOAD_Msk

/* SysTick Current Value Register */
#define SYST_CVR                      (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x008))

/* SYST_CVR bit definitions */
#define SYST_CVR_CURRENT_Pos          SYST_CVR_CURRENT_Pos
#define SYST_CVR_CURRENT_Msk          SYST_CVR_CURRENT_Msk

/* SysTick Calibration Value Register */
#define SYST_CALIB                    (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x00C))

/* SYST_CALIB bit definitions */
#define SYST_CALIB_TENMS_Pos          SYST_CALIB_TENMS_Pos
#define SYST_CALIB_TENMS_Msk          SYST_CALIB_TENMS_Msk
#define SYST_CALIB_SKEW_Pos           SYST_CALIB_SKEW_Pos
#define SYST_CALIB_SKEW_Msk           SYST_CALIB_SKEW_Msk
#define SYST_CALIB_NOREF_Pos          SYST_CALIB_NOREF_Pos
#define SYST_CALIB_NOREF_Msk          SYST_CALIB_NOREF_Msk

/*
 * ============================================================================
 * Function Aliases - Map CM4 naming to ARMv7-M naming
 * 函数别名 - 将 CM4 命名映射到 ARMv7-M 命名
 * ============================================================================
 */

/**
 * @brief Initialize SysTick timer
 * @param reload_value Reload value (0x00000001-0x00FFFFFF)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.2 (page 4-34)
 * Implementation: Delegates to systick_config() in armv7-m_systick.c
 */
static inline void cm4_systick_init(uint32_t reload_value)
{
    systick_config(reload_value, SYST_CLKSOURCE_PROCESSOR, 1);
}

/**
 * @brief Enable SysTick counter
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.1 (page 4-33)
 * Implementation: Delegates to systick_enable() in armv7-m_systick.c
 */
static inline void cm4_systick_enable(void)
{
    systick_enable();
}

/**
 * @brief Disable SysTick counter
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.1 (page 4-33)
 * Implementation: Delegates to systick_disable() in armv7-m_systick.c
 */
static inline void cm4_systick_disable(void)
{
    systick_disable();
}

/**
 * @brief Set reload value
 * @param value Reload value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.2 (page 4-34)
 * Implementation: Delegates to systick_set_reload() in armv7-m_systick.c
 */
static inline void cm4_systick_set_reload(uint32_t value)
{
    systick_set_reload(value);
}

/**
 * @brief Get reload value
 * @return Current reload value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.2 (page 4-34)
 * Implementation: Delegates to systick_get_reload() in armv7-m_systick.h
 */
static inline uint32_t cm4_systick_get_reload(void)
{
    return systick_get_reload();
}

/**
 * @brief Get current value
 * @return Current counter value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.3 (page 4-35)
 * Implementation: Delegates to systick_get_value() in armv7-m_systick.c
 */
static inline uint32_t cm4_systick_get_value(void)
{
    return systick_get_value();
}

/**
 * @brief Clear current value (reset to 0)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.3 (page 4-35)
 * Implementation: Delegates to systick_reset() in armv7-m_systick.c
 */
static inline void cm4_systick_clear(void)
{
    systick_reset();
}

/**
 * @brief Enable SysTick interrupt
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.1 (page 4-33)
 * Implementation: Direct register access using SYST_CSR from armv7-m_systick.h
 */
static inline void cm4_systick_enable_interrupt(void)
{
    SYST_CSR |= SYST_CSR_TICKINT_Msk;
}

/**
 * @brief Disable SysTick interrupt
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.1 (page 4-33)
 * Implementation: Direct register access using SYST_CSR from armv7-m_systick.h
 */
static inline void cm4_systick_disable_interrupt(void)
{
    SYST_CSR &= ~SYST_CSR_TICKINT_Msk;
}

/**
 * @brief Check if counter has counted to 0
 * @return 1 if counted to 0, 0 otherwise
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.1 (page 4-33)
 * Implementation: Delegates to systick_get_count_flag() in armv7-m_systick.c
 */
static inline int cm4_systick_get_countflag(void)
{
    return systick_get_count_flag() ? 1 : 0;
}

/**
 * @brief Set clock source
 * @param use_processor_clock 1 = processor clock, 0 = external clock
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.1 (page 4-33)
 * Implementation: Delegates to systick_set_clock_source() in armv7-m_systick.h
 */
static inline void cm4_systick_set_clock_source(int use_processor_clock)
{
    systick_set_clock_source(use_processor_clock ? SYST_CLKSOURCE_PROCESSOR : SYST_CLKSOURCE_EXTERNAL);
}

/**
 * @brief Get calibration value
 * @return Calibration value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.4 (page 4-35)
 * Implementation: Delegates to systick_get_calib() in armv7-m_systick.c
 */
static inline uint32_t cm4_systick_get_calibration(void)
{
    return systick_get_calib();
}

/**
 * @brief Check if reference clock is provided
 * @return 1 if no reference clock, 0 if reference clock provided
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.4 (page 4-35)
 * Implementation: Delegates to systick_has_external_clock() in armv7-m_systick.c
 */
static inline int cm4_systick_is_noref(void)
{
    return systick_has_external_clock() ? 0 : 1;
}

/**
 * @brief Check if TENMS value is exact
 * @return 1 if inexact, 0 if exact
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.4 (page 4-35)
 * Implementation: Direct register access using SYST_CALIB from armv7-m_systick.h
 */
static inline int cm4_systick_is_skew(void)
{
    return (SYST_CALIB & SYST_CALIB_SKEW_Msk) ? 1 : 0;
}

#ifdef __cplusplus
}
#endif

#endif /* __CM4_SYSTICK_H__ */
