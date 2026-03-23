/*
 * ARM Architecture - ARMv7-M Core Implementation
 *
 * ============================================================================
 * File: armv7-m_core.c
 * Description: ARMv7-M core functions implementation
 * 描述: ARMv7-M 核心函数实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers
 *   - Chapter B1.5 - The instruction set
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 ARM Architecture Team. All rights reserved.
 */

#include "armv7-m/armv7-m_core.h"

/*
 * ============================================================================
 * CONTROL Register Helpers
 * CONTROL 寄存器辅助函数
 * ============================================================================
 */

/**
 * @brief Set nPRIV bit (enter non-privileged mode)
 * 0: Privileged execution / 特权执行
 * 1: Non-privileged execution / 非特权执行
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers - CONTROL register
 */
void armv7m_enter_non_privileged(void) {
    uint32_t control = __get_CONTROL();
    control |= CONTROL_nPRIV;
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Clear nPRIV bit (enter privileged mode)
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers - CONTROL register
 */
void armv7m_enter_privileged(void) {
    uint32_t control = __get_CONTROL();
    control &= ~CONTROL_nPRIV;
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Select PSP as current stack pointer
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers - CONTROL register
 */
void armv7m_select_psp(void) {
    uint32_t control = __get_CONTROL();
    control |= CONTROL_SPSEL;
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Select MSP as current stack pointer
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers - CONTROL register
 */
void armv7m_select_msp(void) {
    uint32_t control = __get_CONTROL();
    control &= ~CONTROL_SPSEL;
    __set_CONTROL(control);
    __ISB();
}

#if (__FPU_PRESENT == 1)
/**
 * @brief Set FPCA bit (mark floating-point context active)
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers - CONTROL register
 */
void armv7m_set_fp_context_active(void) {
    uint32_t control = __get_CONTROL();
    control |= CONTROL_FPCA;
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Clear FPCA bit (mark floating-point context inactive)
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers - CONTROL register
 */
void armv7m_clear_fp_context_active(void) {
    uint32_t control = __get_CONTROL();
    control &= ~CONTROL_FPCA;
    __set_CONTROL(control);
    __ISB();
}
#endif

/*
 * ============================================================================
 * APSR Flag Helpers
 * APSR 标志辅助函数
 * ============================================================================
 */

/**
 * @brief Get N flag (Negative)
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers - APSR register
 */
uint32_t armv7m_get_flag_n(void) {
    return (__get_APSR() & xPSR_N) ? 1U : 0U;
}

/**
 * @brief Get Z flag (Zero)
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers - APSR register
 */
uint32_t armv7m_get_flag_z(void) {
    return (__get_APSR() & xPSR_Z) ? 1U : 0U;
}

/**
 * @brief Get C flag (Carry)
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers - APSR register
 */
uint32_t armv7m_get_flag_c(void) {
    return (__get_APSR() & xPSR_C) ? 1U : 0U;
}

/**
 * @brief Get V flag (Overflow)
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers - APSR register
 */
uint32_t armv7m_get_flag_v(void) {
    return (__get_APSR() & xPSR_V) ? 1U : 0U;
}

/**
 * @brief Get Q flag (Saturation)
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers - APSR register
 */
uint32_t armv7m_get_flag_q(void) {
    return (__get_APSR() & xPSR_Q) ? 1U : 0U;
}

/**
 * @brief Clear Q flag
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers - APSR register
 */
void armv7m_clear_flag_q(void) {
    __asm__ volatile ("msr apsr_nzcvq, %0" : : "r" (0UL) : "cc");
}

/*
 * ============================================================================
 * Exception and Interrupt Helpers
 * 异常和中断辅助函数
 * ============================================================================
 */

/**
 * @brief Enable interrupts (clear PRIMASK)
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers - PRIMASK register
 */
void armv7m_enable_interrupts(void) {
    __set_PRIMASK(0);
}

/**
 * @brief Disable interrupts (set PRIMASK)
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers - PRIMASK register
 */
void armv7m_disable_interrupts(void) {
    __set_PRIMASK(1);
}

/**
 * @brief Enable interrupts with priority masking
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers - BASEPRI register
 */
void armv7m_set_basepri(uint8_t priority) {
    __set_BASEPRI(priority);
}

/**
 * @brief Clear BASEPRI (enable all interrupts)
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers - BASEPRI register
 */
void armv7m_clear_basepri(void) {
    __set_BASEPRI(0);
}

/**
 * @brief Enable FAULTMASK (disable all interrupts including NMI)
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers - FAULTMASK register
 */
void armv7m_set_faultmask(void) {
    __set_FAULTMASK(1);
}

/**
 * @brief Clear FAULTMASK
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers - FAULTMASK register
 */
void armv7m_clear_faultmask(void) {
    __set_FAULTMASK(0);
}

/**
 * @brief Get current exception number
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers - IPSR register
 */
uint32_t armv7m_get_exception_number(void) {
    return __get_IPSR();
}


