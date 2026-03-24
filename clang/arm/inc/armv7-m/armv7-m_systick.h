/*
 * ARM Architecture - ARMv7-M SysTick Timer
 *
 * ============================================================================
 * File: armv7-m_systick.h
 * Description: ARMv7-M SysTick timer definitions and function declarations
 * 描述: ARMv7-M SysTick 定时器定义和函数声明
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter A2: Application Level Programmers' Model
 *     * A2.4 Exceptions, faults and interrupts (page A2-33)
 *       - A2.4.1 System-related events
 *       - SysTick is a system timer for OS scheduling
 *       - Associated interrupt for periodic tasks
 *       - Reference: Chapter A2.3.4 Privileged execution (page A2-32)
 *         * SysTick handler runs in Handler mode with privileged access
 *   - Chapter A3: Arm Architecture Memory Model
 *     * A3.1 Address space (page A3-64)
 *       - Memory-mapped SysTick registers in SCS
 *   - Chapter B3.3 - The system timer, SysTick
 *   - Table B3-7 SysTick register summary (page B3-621)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_SYSTICK_H__
#define __ARCH_ARM_V7M_SYSTICK_H__

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * SysTick Base Address
 * SysTick 基地址
 * Reference: Table B3-3 SCS address space regions (page B3-595)
 * ============================================================================
 */

#define SYSTICK_BASE_ADDR         0xE000E010UL

/*
 * ============================================================================
 * SysTick Register Definitions
 * SysTick 寄存器定义
 * Reference: Table B3-7 SysTick register summary (page B3-621)
 * ============================================================================
 */

/**
 * SysTick Control and Status Register (SYST_CSR)
 * Address: 0xE000E010
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-621
 */
#define SYST_CSR                  (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x00))

/**
 * SysTick Reload Value Register (SYST_RVR)
 * Address: 0xE000E014
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-622
 */
#define SYST_RVR                  (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x04))

/**
 * SysTick Current Value Register (SYST_CVR)
 * Address: 0xE000E018
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-622
 */
#define SYST_CVR                  (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x08))

/**
 * SysTick Calibration Value Register (SYST_CALIB)
 * Address: 0xE000E01C
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-623
 */
#define SYST_CALIB                (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x0C))

/*
 * ============================================================================
 * SysTick Register Bit Definitions
 * SysTick 寄存器位定义
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-621
 * ============================================================================
 */

/**
 * SYST_CSR Register Bits
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-621
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
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-622
 */
#define SYST_RVR_RELOAD_Pos       0U
#define SYST_RVR_RELOAD_Msk       (0xFFFFFFUL << SYST_RVR_RELOAD_Pos)

/**
 * SYST_CVR Register Bits
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-622
 */
#define SYST_CVR_CURRENT_Pos      0U
#define SYST_CVR_CURRENT_Msk      (0xFFFFFFUL << SYST_CVR_CURRENT_Pos)

/**
 * SYST_CALIB Register Bits
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-623
 */
#define SYST_CALIB_NOREF_Pos      31U
#define SYST_CALIB_NOREF_Msk      (1UL << SYST_CALIB_NOREF_Pos)
#define SYST_CALIB_SKEW_Pos       30U
#define SYST_CALIB_SKEW_Msk       (1UL << SYST_CALIB_SKEW_Pos)
#define SYST_CALIB_TENMS_Pos      0U
#define SYST_CALIB_TENMS_Msk      (0xFFFFFFUL << SYST_CALIB_TENMS_Pos)

/**
 * Clock Source Selection
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-621
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
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-621
 */
uint32_t systick_config(uint32_t ticks, uint8_t use_processor_clock, uint8_t enable_interrupt);

/**
 * @brief Get SysTick current value
 * @return Current counter value
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-622
 */
uint32_t systick_get_value(void);

/**
 * @brief Set SysTick reload value
 * @param value Reload value (1-0xFFFFFF)
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-622
 */
void systick_set_reload(uint32_t value);

/**
 * @brief Get SysTick reload value
 * @return Reload value
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-622
 */
static inline uint32_t systick_get_reload(void) {
    return SYST_RVR;
}

/**
 * @brief Enable SysTick counter
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-621
 */
void systick_enable(void);

/**
 * @brief Disable SysTick counter
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-621
 */
void systick_disable(void);

/**
 * @brief Enable SysTick interrupt
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-621
 */
static inline void systick_enable_interrupt(void) {
    SYST_CSR |= SYST_CSR_TICKINT_Msk;
}

/**
 * @brief Disable SysTick interrupt
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-621
 */
static inline void systick_disable_interrupt(void) {
    SYST_CSR &= ~SYST_CSR_TICKINT_Msk;
}

/**
 * @brief Set SysTick clock source
 * @param source SYST_CLKSOURCE_EXTERNAL or SYST_CLKSOURCE_PROCESSOR
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-621
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
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-621
 */
uint32_t systick_get_count_flag(void);

/**
 * @brief Get SysTick calibration value
 * @return Calibration value
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-623
 */
uint32_t systick_get_calib(void);

/**
 * @brief Check if external reference clock is available
 * @return 1 if available, 0 if not
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-623
 */
uint32_t systick_has_external_clock(void);

/**
 * @brief Reset SysTick counter
 * Reference: Arm(R) v7-M Architecture Reference Manual, B3-622
 */
void systick_reset(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_SYSTICK_H__ */
