/*
 * ARM Architecture - Cortex-M4 SysTick Timer
 *
 * ============================================================================
 * File: cm4_systick.h
 * Description: Cortex-M4 SysTick timer register definitions
 * 描述: Cortex-M4 SysTick 定时器寄存器定义
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.4 System timer, SysTick (page 4-32)
 *   - Table 4-32 System timer registers summary (page 4-33)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_SYSTICK_H__
#define __CM4_SYSTICK_H__

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * SysTick Base Address
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-32 (page 4-33)
 * ============================================================================
 */

#define CM4_SYSTICK_BASE_ADDR         0xE000E010UL

/*
 * ============================================================================
 * SysTick Control and Status Register (SYST_CSR)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-33 (page 4-33)
 * Address: 0xE000E010
 * ============================================================================
 */

#define SYST_CSR                      (*(volatile uint32_t *)(CM4_SYSTICK_BASE_ADDR + 0x000))

/* SYST_CSR bit definitions - Reference: Table 4-33 (page 4-33) */
#define SYST_CSR_ENABLE_Pos           0U
#define SYST_CSR_ENABLE_Msk           (1UL << SYST_CSR_ENABLE_Pos)

#define SYST_CSR_TICKINT_Pos          1U
#define SYST_CSR_TICKINT_Msk          (1UL << SYST_CSR_TICKINT_Pos)

#define SYST_CSR_CLKSOURCE_Pos        2U
#define SYST_CSR_CLKSOURCE_Msk        (1UL << SYST_CSR_CLKSOURCE_Pos)

#define SYST_CSR_COUNTFLAG_Pos        16U
#define SYST_CSR_COUNTFLAG_Msk        (1UL << SYST_CSR_COUNTFLAG_Pos)

/*
 * ============================================================================
 * SysTick Reload Value Register (SYST_RVR)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-34 (page 4-34)
 * Address: 0xE000E014
 * ============================================================================
 */

#define SYST_RVR                      (*(volatile uint32_t *)(CM4_SYSTICK_BASE_ADDR + 0x004))

/* SYST_RVR bit definitions - Reference: Table 4-34 (page 4-34) */
#define SYST_RVR_RELOAD_Pos           0U
#define SYST_RVR_RELOAD_Msk           (0xFFFFFFUL << SYST_RVR_RELOAD_Pos)

/*
 * ============================================================================
 * SysTick Current Value Register (SYST_CVR)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-35 (page 4-35)
 * Address: 0xE000E018
 * ============================================================================
 */

#define SYST_CVR                      (*(volatile uint32_t *)(CM4_SYSTICK_BASE_ADDR + 0x008))

/* SYST_CVR bit definitions - Reference: Table 4-35 (page 4-35) */
#define SYST_CVR_CURRENT_Pos          0U
#define SYST_CVR_CURRENT_Msk          (0xFFFFFFUL << SYST_CVR_CURRENT_Pos)

/*
 * ============================================================================
 * SysTick Calibration Value Register (SYST_CALIB)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-36 (page 4-35)
 * Address: 0xE000E01C
 * ============================================================================
 */

#define SYST_CALIB                    (*(volatile uint32_t *)(CM4_SYSTICK_BASE_ADDR + 0x00C))

/* SYST_CALIB bit definitions - Reference: Table 4-36 (page 4-35) */
#define SYST_CALIB_TENMS_Pos          0U
#define SYST_CALIB_TENMS_Msk          (0xFFFFFFUL << SYST_CALIB_TENMS_Pos)

#define SYST_CALIB_SKEW_Pos           30U
#define SYST_CALIB_SKEW_Msk           (1UL << SYST_CALIB_SKEW_Pos)

#define SYST_CALIB_NOREF_Pos          31U
#define SYST_CALIB_NOREF_Msk          (1UL << SYST_CALIB_NOREF_Pos)

/*
 * ============================================================================
 * SysTick Function Declarations
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4 (page 4-32)
 * ============================================================================
 */

/**
 * @brief Initialize SysTick timer
 * @param reload_value Reload value (0x00000001-0x00FFFFFF)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.2 (page 4-34)
 */
void cm4_systick_init(uint32_t reload_value);

/**
 * @brief Enable SysTick counter
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.1 (page 4-33)
 */
void cm4_systick_enable(void);

/**
 * @brief Disable SysTick counter
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.1 (page 4-33)
 */
void cm4_systick_disable(void);

/**
 * @brief Set reload value
 * @param value Reload value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.2 (page 4-34)
 */
void cm4_systick_set_reload(uint32_t value);

/**
 * @brief Get reload value
 * @return Current reload value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.2 (page 4-34)
 */
uint32_t cm4_systick_get_reload(void);

/**
 * @brief Get current value
 * @return Current counter value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.3 (page 4-35)
 */
uint32_t cm4_systick_get_value(void);

/**
 * @brief Clear current value (reset to 0)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.3 (page 4-35)
 */
void cm4_systick_clear(void);

/**
 * @brief Enable SysTick interrupt
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.1 (page 4-33)
 */
void cm4_systick_enable_interrupt(void);

/**
 * @brief Disable SysTick interrupt
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.1 (page 4-33)
 */
void cm4_systick_disable_interrupt(void);

/**
 * @brief Check if counter has counted to 0
 * @return 1 if counted to 0, 0 otherwise
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.1 (page 4-33)
 */
int cm4_systick_get_countflag(void);

/**
 * @brief Set clock source
 * @param use_processor_clock 1 = processor clock, 0 = external clock
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.1 (page 4-33)
 */
void cm4_systick_set_clock_source(int use_processor_clock);

/**
 * @brief Get calibration value
 * @return Calibration value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.4 (page 4-35)
 */
uint32_t cm4_systick_get_calibration(void);

/**
 * @brief Check if reference clock is provided
 * @return 1 if no reference clock, 0 if reference clock provided
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.4 (page 4-35)
 */
int cm4_systick_is_noref(void);

/**
 * @brief Check if TENMS value is exact
 * @return 1 if inexact, 0 if exact
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.4.4 (page 4-35)
 */
int cm4_systick_is_skew(void);

#ifdef __cplusplus
}
#endif

#endif /* __CM4_SYSTICK_H__ */
