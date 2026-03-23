/*
 * ARM Architecture - ARMv7-M SysTick Timer
 *
 * ============================================================================
 * File: armv7-m_systick.h
 * Description: ARMv7-M SysTick timer definitions and function declarations
 * 描述: ARMv7-M SysTick 定时器定义和函数声明
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual
 *   - Chapter B8: The System Timer, SysTick
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_SYSTICK_H__
#define __ARCH_ARM_V7M_SYSTICK_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv7-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * SysTick Base Address
 * SysTick 基地址
 * ============================================================================
 */

#define SYSTICK_BASE_ADDR         0xE000E010UL

/*
 * ============================================================================
 * SysTick Register Definitions
 * SysTick 寄存器定义
 * ============================================================================
 */

/**
 * SysTick Control and Status Register (SYST_CSR)
 * SysTick 控制和状态寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, B8.2.1
 */
#define SYST_CSR                  (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x00))

/**
 * SysTick Reload Value Register (SYST_RVR)
 * SysTick 重载值寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, B8.2.2
 */
#define SYST_RVR                  (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x04))

/**
 * SysTick Current Value Register (SYST_CVR)
 * SysTick 当前值寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, B8.2.3
 */
#define SYST_CVR                  (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x08))

/**
 * SysTick Calibration Value Register (SYST_CALIB)
 * SysTick 校准值寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, B8.2.4
 */
#define SYST_CALIB                (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x0C))

/*
 * ============================================================================
 * SysTick Register Bit Definitions
 * SysTick 寄存器位定义
 * ============================================================================
 */

/**
 * SYST_CSR Register Bits
 * SYST_CSR 寄存器位
 */
#define SYST_CSR_COUNTFLAG_Pos    16U
#define SYST_CSR_COUNTFLAG_Msk    (1UL << SYST_CSR_COUNTFLAG_Pos)
#define SYST_CSR_CLKSOURCE_Pos    2U
#define SYST_CSR_CLKSOURCE_Msk    (1UL << SYST_CSR_CLKSOURCE_Pos)
#define SYST_CSR_TICKINT_Pos      1U
#define SYST_CSR_TICKINT_Msk      (1UL << SYST_CSR_TICKINT_Pos)
#define SYST_CSR_ENABLE_Pos       0U
#define SYST_CSR_ENABLE_Msk       (1UL << SYST_CSR_ENABLE_Pos)

/**
 * SYST_RVR Register Bits
 * SYST_RVR 寄存器位
 */
#define SYST_RVR_RELOAD_Pos       0U
#define SYST_RVR_RELOAD_Msk       (0xFFFFFFUL << SYST_RVR_RELOAD_Pos)

/**
 * SYST_CVR Register Bits
 * SYST_CVR 寄存器位
 */
#define SYST_CVR_CURRENT_Pos      0U
#define SYST_CVR_CURRENT_Msk      (0xFFFFFFUL << SYST_CVR_CURRENT_Pos)

/**
 * SYST_CALIB Register Bits
 * SYST_CALIB 寄存器位
 */
#define SYST_CALIB_NOREF_Pos      31U
#define SYST_CALIB_NOREF_Msk      (1UL << SYST_CALIB_NOREF_Pos)
#define SYST_CALIB_SKEW_Pos       30U
#define SYST_CALIB_SKEW_Msk       (1UL << SYST_CALIB_SKEW_Pos)
#define SYST_CALIB_TENMS_Pos      0U
#define SYST_CALIB_TENMS_Msk      (0xFFFFFFUL << SYST_CALIB_TENMS_Pos)

/**
 * Clock Source Selection
 * 时钟源选择
 */
#define SYST_CLKSOURCE_EXTERNAL   0U  /* External reference clock */
#define SYST_CLKSOURCE_PROCESSOR  1U  /* Processor clock */

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Configure and start SysTick timer
 * @param ticks Number of ticks between interrupts (1-0xFFFFFF)
 * @param use_processor_clock 1 = use processor clock, 0 = use external clock
 * @param enable_interrupt 1 = enable interrupt, 0 = disable interrupt
 * @return 0 on success, 1 if ticks is invalid
 */
uint32_t systick_config(uint32_t ticks, uint8_t use_processor_clock, uint8_t enable_interrupt);

/**
 * @brief Get SysTick current value
 * @return Current counter value
 */
static inline uint32_t systick_get_value(void) {
    return SYST_CVR;
}

/**
 * @brief Set SysTick reload value
 * @param value Reload value (1-0xFFFFFF)
 */
static inline void systick_set_reload(uint32_t value) {
    SYST_RVR = (value & SYST_RVR_RELOAD_Msk);
}

/**
 * @brief Get SysTick reload value
 * @return Reload value
 */
static inline uint32_t systick_get_reload(void) {
    return SYST_RVR;
}

/**
 * @brief Enable SysTick counter
 */
static inline void systick_enable(void) {
    SYST_CSR |= SYST_CSR_ENABLE_Msk;
}

/**
 * @brief Disable SysTick counter
 */
static inline void systick_disable(void) {
    SYST_CSR &= ~SYST_CSR_ENABLE_Msk;
}

/**
 * @brief Enable SysTick interrupt
 */
static inline void systick_enable_interrupt(void) {
    SYST_CSR |= SYST_CSR_TICKINT_Msk;
}

/**
 * @brief Disable SysTick interrupt
 */
static inline void systick_disable_interrupt(void) {
    SYST_CSR &= ~SYST_CSR_TICKINT_Msk;
}

/**
 * @brief Set SysTick clock source
 * @param source SYST_CLKSOURCE_EXTERNAL or SYST_CLKSOURCE_PROCESSOR
 */
static inline void systick_set_clock_source(uint8_t source) {
    if (source == SYST_CLKSOURCE_PROCESSOR) {
        SYST_CSR |= SYST_CSR_CLKSOURCE_Msk;
    } else {
        SYST_CSR &= ~SYST_CSR_CLKSOURCE_Msk;
    }
}

/**
 * @brief Get SysTick count flag
 * @return 1 if counter reached zero since last read, 0 otherwise
 */
static inline uint32_t systick_get_count_flag(void) {
    return (SYST_CSR & SYST_CSR_COUNTFLAG_Msk) ? 1U : 0U;
}

/**
 * @brief Get SysTick calibration value
 * @return Calibration value
 */
static inline uint32_t systick_get_calib(void) {
    return SYST_CALIB;
}

/**
 * @brief Check if external reference clock is available
 * @return 1 if available, 0 if not
 */
static inline uint32_t systick_has_external_clock(void) {
    return (SYST_CALIB & SYST_CALIB_NOREF_Msk) ? 0U : 1U;
}

/**
 * @brief Reset SysTick counter
 */
static inline void systick_reset(void) {
    SYST_CVR = 0U;
}

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_SYSTICK_H__ */
