/*
 * ARM Architecture - ARMv8-M Core Implementation
 *
 * ============================================================================
 * File: armv8-m_core.c
 * Description: ARMv8-M core functions implementation
 * 描述: ARMv8-M 核心函数实现
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B3: Programmers' Model
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 ARM Architecture Team. All rights reserved.
 */

#include "armv8-m/armv8-m_core.h"

/*
 * ============================================================================
 * CONTROL Register Helpers
 * CONTROL 寄存器辅助函数
 * ============================================================================
 */

/**
 * @brief Set nPRIV bit (enter non-privileged mode)
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - CONTROL register
 */
void armv8m_enter_non_privileged(void) {
    uint32_t control = __get_CONTROL();
    control |= CONTROL_nPRIV;
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Clear nPRIV bit (enter privileged mode)
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - CONTROL register
 */
void armv8m_enter_privileged(void) {
    uint32_t control = __get_CONTROL();
    control &= ~CONTROL_nPRIV;
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Select PSP as current stack pointer
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - CONTROL register
 */
void armv8m_select_psp(void) {
    uint32_t control = __get_CONTROL();
    control |= CONTROL_SPSEL;
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Select MSP as current stack pointer
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - CONTROL register
 */
void armv8m_select_msp(void) {
    uint32_t control = __get_CONTROL();
    control &= ~CONTROL_SPSEL;
    __set_CONTROL(control);
    __ISB();
}

#if (__FPU_PRESENT == 1)
/**
 * @brief Set FPCA bit (mark floating-point context active)
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - CONTROL register
 */
void armv8m_set_fp_context_active(void) {
    uint32_t control = __get_CONTROL();
    control |= CONTROL_FPCA;
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Clear FPCA bit (mark floating-point context inactive)
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - CONTROL register
 */
void armv8m_clear_fp_context_active(void) {
    uint32_t control = __get_CONTROL();
    control &= ~CONTROL_FPCA;
    __set_CONTROL(control);
    __ISB();
}
#endif

#if (__PACBTI_PRESENT == 1)
/**
 * @brief Enable PAC (privileged)
 * Reference: Arm(R) v8-M ARM Chapter B6 (Pointer authentication and branch target identification Extension)
 */
void armv8m_enable_pac(void) {
    uint32_t control = __get_CONTROL();
    control |= CONTROL_PAC_EN;
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Disable PAC (privileged)
 * Reference: Arm(R) v8-M ARM Chapter B6 (Pointer authentication and branch target identification Extension)
 */
void armv8m_disable_pac(void) {
    uint32_t control = __get_CONTROL();
    control &= ~CONTROL_PAC_EN;
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Enable PAC (unprivileged)
 * Reference: Arm(R) v8-M ARM Chapter B6 (Pointer authentication and branch target identification Extension)
 */
void armv8m_enable_pac_unprivileged(void) {
    uint32_t control = __get_CONTROL();
    control |= CONTROL_UPAC_EN;
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Disable PAC (unprivileged)
 * Reference: Arm(R) v8-M ARM Chapter B6 (Pointer authentication and branch target identification Extension)
 */
void armv8m_disable_pac_unprivileged(void) {
    uint32_t control = __get_CONTROL();
    control &= ~CONTROL_UPAC_EN;
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Enable BTI (privileged)
 * Reference: Arm(R) v8-M ARM Chapter B6 (Pointer authentication and branch target identification Extension)
 */
void armv8m_enable_bti(void) {
    uint32_t control = __get_CONTROL();
    control |= CONTROL_BTI_EN;
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Disable BTI (privileged)
 * Reference: Arm(R) v8-M ARM Chapter B6 (Pointer authentication and branch target identification Extension)
 */
void armv8m_disable_bti(void) {
    uint32_t control = __get_CONTROL();
    control &= ~CONTROL_BTI_EN;
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Enable BTI (unprivileged)
 * Reference: Arm(R) v8-M ARM Chapter B6 (Pointer authentication and branch target identification Extension)
 */
void armv8m_enable_bti_unprivileged(void) {
    uint32_t control = __get_CONTROL();
    control |= CONTROL_UBTI_EN;
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Disable BTI (unprivileged)
 * Reference: Arm(R) v8-M ARM Chapter B6 (Pointer authentication and branch target identification Extension)
 */
void armv8m_disable_bti_unprivileged(void) {
    uint32_t control = __get_CONTROL();
    control &= ~CONTROL_UBTI_EN;
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
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - APSR register
 */
uint32_t armv8m_get_flag_n(void) {
    return (__get_APSR() & xPSR_N) ? 1U : 0U;
}

/**
 * @brief Get Z flag (Zero)
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - APSR register
 */
uint32_t armv8m_get_flag_z(void) {
    return (__get_APSR() & xPSR_Z) ? 1U : 0U;
}

/**
 * @brief Get C flag (Carry)
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - APSR register
 */
uint32_t armv8m_get_flag_c(void) {
    return (__get_APSR() & xPSR_C) ? 1U : 0U;
}

/**
 * @brief Get V flag (Overflow)
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - APSR register
 */
uint32_t armv8m_get_flag_v(void) {
    return (__get_APSR() & xPSR_V) ? 1U : 0U;
}

/**
 * @brief Get Q flag (Saturation)
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - APSR register
 */
uint32_t armv8m_get_flag_q(void) {
    return (__get_APSR() & xPSR_Q) ? 1U : 0U;
}

/**
 * @brief Clear Q flag
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - APSR register
 */
void armv8m_clear_flag_q(void) {
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
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - PRIMASK register
 */
void armv8m_enable_interrupts(void) {
    __set_PRIMASK(0);
}

/**
 * @brief Disable interrupts (set PRIMASK)
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - PRIMASK register
 */
void armv8m_disable_interrupts(void) {
    __set_PRIMASK(1);
}

/**
 * @brief Enable interrupts with priority masking
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - BASEPRI register
 */
void armv8m_set_basepri(uint8_t priority) {
    __set_BASEPRI(priority);
}

/**
 * @brief Clear BASEPRI (enable all interrupts)
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - BASEPRI register
 */
void armv8m_clear_basepri(void) {
    __set_BASEPRI(0);
}

/**
 * @brief Enable FAULTMASK (disable all interrupts including NMI)
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - FAULTMASK register
 */
void armv8m_set_faultmask(void) {
    __set_FAULTMASK(1);
}

/**
 * @brief Clear FAULTMASK
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - FAULTMASK register
 */
void armv8m_clear_faultmask(void) {
    __set_FAULTMASK(0);
}

/**
 * @brief Get current exception number
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - IPSR register
 */
uint32_t armv8m_get_exception_number(void) {
    return __get_IPSR();
}

/**
 * @brief Check if in Handler mode
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - IPSR register
 */
bool armv8m_in_handler_mode(void) {
    return (__get_IPSR() != 0);
}

/**
 * @brief Check if in Thread mode
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - IPSR register
 */
bool armv8m_in_thread_mode(void) {
    return (__get_IPSR() == 0);
}

/*
 * ============================================================================
 * Stack Limit Helpers
 * 堆栈限制辅助函数
 * ============================================================================
 */

/**
 * @brief Enable MSP limit checking
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - Stack limit checks
 */
void armv8m_enable_msplim(void) {
    uint32_t control = __get_CONTROL();
    control |= (1UL << 8);
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Disable MSP limit checking
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - Stack limit checks
 */
void armv8m_disable_msplim(void) {
    uint32_t control = __get_CONTROL();
    control &= ~(1UL << 8);
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Enable PSP limit checking
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - Stack limit checks
 */
void armv8m_enable_psplim(void) {
    uint32_t control = __get_CONTROL();
    control |= (1UL << 9);
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Disable PSP limit checking
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model) - Stack limit checks
 */
void armv8m_disable_psplim(void) {
    uint32_t control = __get_CONTROL();
    control &= ~(1UL << 9);
    __set_CONTROL(control);
    __ISB();
}

/*
 * ============================================================================
 * Low Power Mode Helpers
 * 低功耗模式辅助函数
 * ============================================================================
 */

/**
 * @brief Enter sleep mode (WFI)
 * Reference: Arm(R) v8-M ARM Chapter B2 (Power Management) - WFI instruction
 */
void armv8m_sleep_wfi(void) {
    __WFI();
}

/**
 * @brief Enter sleep mode (WFE)
 * Reference: Arm(R) v8-M ARM Chapter B2 (Power Management) - WFE instruction
 */
void armv8m_sleep_wfe(void) {
    __WFE();
}

/**
 * @brief Send event (SEV)
 * Reference: Arm(R) v8-M ARM Chapter B2 (Power Management) - SEV instruction
 */
void armv8m_send_event(void) {
    __SEV();
}

/**
 * @brief Send local event (SEVL)
 * Reference: Arm(R) v8-M ARM Chapter B2 (Power Management) - SEVL instruction
 */
void armv8m_send_event_local(void) {
    __SEVL();
}

/*
 * ============================================================================
 * Memory Barrier Helpers
 * 内存屏障辅助函数
 * ============================================================================
 */

/**
 * @brief Full system barrier (DSB + ISB)
 * Reference: Arm(R) v8-M ARM Chapter B7 (Memory Model) - Memory barriers
 */
void armv8m_full_barrier(void) {
    __DSB();
    __ISB();
}

/**
 * @brief Data synchronization barrier with domain
 * Reference: Arm(R) v8-M ARM Chapter B7 (Memory Model) - DSB instruction
 */
void armv8m_dsb(uint32_t domain) {
    __asm__ volatile ("dsb %0" : : "i" (domain) : "memory");
}

/**
 * @brief Data memory barrier with domain
 * Reference: Arm(R) v8-M ARM Chapter B7 (Memory Model) - DMB instruction
 */
void armv8m_dmb(uint32_t domain) {
    __asm__ volatile ("dmb %0" : : "i" (domain) : "memory");
}

/**
 * @brief Instruction synchronization barrier
 * Reference: Arm(R) v8-M ARM Chapter B7 (Memory Model) - ISB instruction
 */
void armv8m_isb(void) {
    __ISB();
}
