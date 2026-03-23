/*
 * ARM Architecture - ARMv7-M Core Registers
 *
 * ============================================================================
 * File: armv7-m_core.h
 * Description: ARMv7-M core register definitions and inline functions
 * 描述: ARMv7-M 核心寄存器定义和内联函数
 *
 * This file provides definitions for ARMv7-M core registers including:
 * - CONTROL, MSP, PSP, PRIMASK, BASEPRI, FAULTMASK
 * - Status registers (APSR, IPSR, xPSR)
 * - Memory barrier instructions
 * - Low power mode instructions
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1.4 - Registers
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_CORE_H__
#define __ARCH_ARM_V7M_CORE_H__

#include &lt;stdint.h&gt;
#include &lt;stdbool.h&gt;
#include "armv7-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * ARMv7-M Core Register Bit Definitions
 * ARMv7-M 核心寄存器位定义
 *
 * Reference: Chapter B1.4 - Registers
 * ============================================================================
 */

/**
 * CONTROL register bit definitions
 * CONTROL 寄存器位定义
 *
 * CONTROL Register (bits):
 *   [0] nPRIV    - Non-privileged execution level
 *   [1] SPSEL    - Stack pointer select (0=MSP, 1=PSP)
 *   [2] FPCA     - Floating-point context active
 */
#define CONTROL_nPRIV_Pos          0U
#define CONTROL_nPRIV_Msk         (1UL &lt;&lt; CONTROL_nPRIV_Pos)
#define CONTROL_SPSEL_Pos          1U
#define CONTROL_SPSEL_Msk          (1UL &lt;&lt; CONTROL_SPSEL_Pos)
#define CONTROL_FPCA_Pos           2U
#define CONTROL_FPCA_Msk           (1UL &lt;&lt; CONTROL_FPCA_Pos)

/**
 * @brief CONTROL_nPRIV bit: Non-privileged execution level
 * 0: Privileged execution / 特权执行
 * 1: Non-privileged execution / 非特权执行
 */
#define CONTROL_nPRIV              (1UL &lt;&lt; CONTROL_nPRIV_Pos)

/**
 * @brief CONTROL_SPSEL bit: Stack pointer select
 * 0: Use MSP (Main Stack Pointer) / 使用 MSP
 * 1: Use PSP (Process Stack Pointer) / 使用 PSP
 */
#define CONTROL_SPSEL              (1UL &lt;&lt; CONTROL_SPSEL_Pos)

/**
 * @brief CONTROL_FPCA bit: Floating-point context active
 * 0: No floating-point context active
 * 1: Floating-point context active
 */
#define CONTROL_FPCA               (1UL &lt;&lt; CONTROL_FPCA_Pos)

/**
 * PRIMASK register bit definitions
 * PRIMASK 寄存器位定义
 */
#define PRIMASK_Pos                0U
#define PRIMASK_Msk              (1UL &lt;&lt; PRIMASK_Pos)
#define PRIMASK                  (1UL &lt;&lt; PRIMASK_Pos)

/**
 * FAULTMASK register bit definitions
 * FAULTMASK 寄存器位定义
 */
#define FAULTMASK_Pos             0U
#define FAULTMASK_Msk            (1UL &lt;&lt; FAULTMASK_Pos)
#define FAULTMASK                (1UL &lt;&lt; FAULTMASK_Pos)

/**
 * BASEPRI register bit definitions
 * BASEPRI 寄存器位定义
 */
#define BASEPRI_Pos               0U
#define BASEPRI_Msk              (0xFFUL &lt;&lt; BASEPRI_Pos)
#define BASEPRI                  (0xFFUL &lt;&lt; BASEPRI_Pos)

/**
 * xPSR register bit definitions
 * xPSR 寄存器位定义
 *
 * APSR bits [31:28]: N, Z, C, V, Q
 * APSR bits [19:16]: GE[3:0] (SIMD instructions, ARMv7E-M only)
 * IPSR bits [8:0]: Exception number
 * EPSR bits [24]: T, EPSR bits [26:25]: ICI/IT
 */
#define xPSR_N_Pos               31U
#define xPSR_N_Msk              (1UL &lt;&lt; xPSR_N_Pos)
#define xPSR_Z_Pos               30U
#define xPSR_Z_Msk              (1UL &lt;&lt; xPSR_Z_Pos)
#define xPSR_C_Pos               29U
#define xPSR_C_Msk              (1UL &lt;&lt; xPSR_C_Pos)
#define xPSR_V_Pos               28U
#define xPSR_V_Msk              (1UL &lt;&lt; xPSR_V_Pos)
#define xPSR_Q_Pos               27U
#define xPSR_Q_Msk              (1UL &lt;&lt; xPSR_Q_Pos)
#define xPSR_GE_Pos              16U
#define xPSR_GE_Msk             (0xFUL &lt;&lt; xPSR_GE_Pos)
#define xPSR_T_Pos               24U
#define xPSR_T_Msk              (1UL &lt;&lt; xPSR_T_Pos)
#define xPSR_Exception_Pos        0U
#define xPSR_Exception_Msk       (0x1FFUL &lt;&lt; xPSR_Exception_Pos)

/* xPSR Flag bits */
#define xPSR_N                   (1UL &lt;&lt; xPSR_N_Pos)
#define xPSR_Z                   (1UL &lt;&lt; xPSR_Z_Pos)
#define xPSR_C                   (1UL &lt;&lt; xPSR_C_Pos)
#define xPSR_V                   (1UL &lt;&lt; xPSR_V_Pos)
#define xPSR_Q                   (1UL &lt;&lt; xPSR_Q_Pos)
#define xPSR_GE                  (0xFUL &lt;&lt; xPSR_GE_Pos)
#define xPSR_T                   (1UL &lt;&lt; xPSR_T_Pos)
#define xPSR_Exception           (0x1FFUL &lt;&lt; xPSR_Exception_Pos)

/*
 * ============================================================================
 * Core Register Access Functions
 * 核心寄存器访问函数
 * ============================================================================
 */

/**
 * @brief Get CONTROL register value
 * @return Current CONTROL register value
 */
static inline uint32_t __get_CONTROL(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, control" : "=r" (result));
    return result;
}

/**
 * @brief Set CONTROL register value
 * @param control New CONTROL register value
 */
static inline void __set_CONTROL(uint32_t control) {
    __asm__ volatile ("MSR control, %0" : : "r" (control) : "memory");
}

/**
 * @brief Get Main Stack Pointer (MSP)
 * @return Current MSP value
 */
static inline uint32_t __get_MSP(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, msp" : "=r" (result));
    return result;
}

/**
 * @brief Set Main Stack Pointer (MSP)
 * @param msp New MSP value
 */
static inline void __set_MSP(uint32_t msp) {
    __asm__ volatile ("MSR msp, %0" : : "r" (msp) : "memory");
}

/**
 * @brief Get Process Stack Pointer (PSP)
 * @return Current PSP value
 */
static inline uint32_t __get_PSP(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, psp" : "=r" (result));
    return result;
}

/**
 * @brief Set Process Stack Pointer (PSP)
 * @param psp New PSP value
 */
static inline void __set_PSP(uint32_t psp) {
    __asm__ volatile ("MSR psp, %0" : : "r" (psp) : "memory");
}

/**
 * @brief Get PRIMASK register
 * @return Current PRIMASK value
 */
static inline uint32_t __get_PRIMASK(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, primask" : "=r" (result));
    return result;
}

/**
 * @brief Set PRIMASK register
 * @param primask New PRIMASK value
 */
static inline void __set_PRIMASK(uint32_t primask) {
    __asm__ volatile ("MSR primask, %0" : : "r" (primask) : "memory");
}

/**
 * @brief Get BASEPRI register
 * @return Current BASEPRI value
 */
static inline uint32_t __get_BASEPRI(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, basepri" : "=r" (result));
    return result;
}

/**
 * @brief Set BASEPRI register
 * @param basepri New BASEPRI value
 */
static inline void __set_BASEPRI(uint32_t basepri) {
    __asm__ volatile ("MSR basepri, %0" : : "r" (basepri) : "memory");
}

/**
 * @brief Get FAULTMASK register
 * @return Current FAULTMASK value
 */
static inline uint32_t __get_FAULTMASK(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, faultmask" : "=r" (result));
    return result;
}

/**
 * @brief Set FAULTMASK register
 * @param faultmask New FAULTMASK value
 */
static inline void __set_FAULTMASK(uint32_t faultmask) {
    __asm__ volatile ("MSR faultmask, %0" : : "r" (faultmask) : "memory");
}

/**
 * @brief Get IPSR register
 * @return Current IPSR value (exception number)
 */
static inline uint32_t __get_IPSR(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, ipsr" : "=r" (result));
    return result;
}

/**
 * @brief Get APSR register
 * @return Current APSR value
 */
static inline uint32_t __get_APSR(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, apsr" : "=r" (result));
    return result;
}

/**
 * @brief Get xPSR register
 * @return Current xPSR value
 */
static inline uint32_t __get_xPSR(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, xpsr" : "=r" (result));
    return result;
}

/*
 * ============================================================================
 * Memory Barrier Instructions
 * 内存屏障指令
 * ============================================================================
 */

/**
 * @brief Instruction Synchronization Barrier (ISB)
 * Flushes the pipeline and ensures context synchronization
 * Reference: Chapter A3.7.3 - Memory barriers
 */
static inline void __ISB(void) {
    __asm__ volatile ("isb 0xF" ::: "memory");
}

/**
 * @brief Data Synchronization Barrier (DSB)
 * Ensures completion of all explicit memory accesses
 * Reference: Chapter A3.7.3 - Memory barriers
 */
static inline void __DSB(void) {
    __asm__ volatile ("dsb 0xF" ::: "memory");
}

/**
 * @brief Data Memory Barrier (DMB)
 * Ensures ordering of memory accesses
 * Reference: Chapter A3.7.3 - Memory barriers
 */
static inline void __DMB(void) {
    __asm__ volatile ("dmb 0xF" ::: "memory");
}

/**
 * @brief Consumption of Speculative Data Barrier (CSDB)
 * Reference: Chapter A3.7.3 - Memory barriers
 */
static inline void __CSDB(void) {
    __asm__ volatile ("csdb" ::: "memory");
}

/**
 * @brief Physical Speculative Store Bypass Barrier (PSSBB)
 * Reference: Chapter A3.7.3 - Memory barriers
 */
static inline void __PSSBB(void) {
    __asm__ volatile ("pssbb" ::: "memory");
}

/**
 * @brief Speculative Store Bypass Barrier (SSBB)
 * Reference: Chapter A3.7.3 - Memory barriers
 */
static inline void __SSBB(void) {
    __asm__ volatile ("ssbb" ::: "memory");
}

/*
 * ============================================================================
 * Low Power Mode Instructions
 * 低功耗模式指令
 * ============================================================================
 */

/**
 * @brief Wait For Interrupt (WFI)
 * Suspends execution until an interrupt occurs
 * Reference: Chapter B1.5.19 - Wait For Interrupt
 */
static inline void __WFI(void) {
    __asm__ volatile ("wfi" ::: "memory");
}

/**
 * @brief Wait For Event (WFE)
 * Suspends execution until an event occurs
 * Reference: Chapter B1.5.18 - Wait For Event and Send Event
 */
static inline void __WFE(void) {
    __asm__ volatile ("wfe" ::: "memory");
}

/**
 * @brief Send Event (SEV)
 * Sends an event to all cores in a multiprocessor system
 * Reference: Chapter B1.5.18 - Wait For Event and Send Event
 */
static inline void __SEV(void) {
    __asm__ volatile ("sev" ::: "memory");
}

/*
 * ============================================================================
 * No Operation and Debug Hints
 * 空操作和调试提示
 * ============================================================================
 */

/**
 * @brief No Operation (NOP)
 */
static inline void __NOP(void) {
    __asm__ volatile ("nop");
}

/**
 * @brief Breakpoint instruction (BKPT)
 * @param val Breakpoint value (0-255)
 */
static inline void __BKPT(uint8_t val) {
    __asm__ volatile ("bkpt %0" : : "I" (val));
}

/**
 * @brief Enable interrupts
 */
static inline void __enable_interrupts(void) {
    __asm__ volatile ("cpsie i" ::: "memory");
}

/**
 * @brief Disable interrupts
 */
static inline void __disable_interrupts(void) {
    __asm__ volatile ("cpsid i" ::: "memory");
}

/**
 * @brief Enable interrupts and faults
 */
static inline void __enable_fault_irq(void) {
    __asm__ volatile ("cpsie f" ::: "memory");
}

/**
 * @brief Disable interrupts and faults
 */
static inline void __disable_fault_irq(void) {
    __asm__ volatile ("cpsid f" ::: "memory");
}

/*
 * ============================================================================
 * Exclusive Access Instructions
 * 独占访问指令
 * ============================================================================
 */

/**
 * @brief Load Exclusive word
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter A3.4 - Synchronization and semaphores
 */
static inline uint32_t __LDREXW(volatile uint32_t *addr) {
    uint32_t result;
    __asm__ volatile ("ldrex %0, [%1]" : "=r" (result) : "r" (addr) : "memory");
    return result;
}

/**
 * @brief Store Exclusive word
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter A3.4 - Synchronization and semaphores
 */
static inline uint32_t __STREXW(uint32_t value, volatile uint32_t *addr) {
    uint32_t result;
    __asm__ volatile ("strex %0, %2, [%1]" : "=&r" (result) : "r" (addr), "r" (value) : "memory");
    return result;
}

/**
 * @brief Load Exclusive halfword
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter A3.4 - Synchronization and semaphores
 */
static inline uint16_t __LDREXH(volatile uint16_t *addr) {
    uint16_t result;
    __asm__ volatile ("ldrexh %0, [%1]" : "=r" (result) : "r" (addr) : "memory");
    return result;
}

/**
 * @brief Store Exclusive halfword
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter A3.4 - Synchronization and semaphores
 */
static inline uint32_t __STREXH(uint16_t value, volatile uint16_t *addr) {
    uint32_t result;
    __asm__ volatile ("strexh %0, %2, [%1]" : "=&r" (result) : "r" (addr), "r" (value) : "memory");
    return result;
}

/**
 * @brief Load Exclusive byte
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter A3.4 - Synchronization and semaphores
 */
static inline uint8_t __LDREXB(volatile uint8_t *addr) {
    uint8_t result;
    __asm__ volatile ("ldrexb %0, [%1]" : "=r" (result) : "r" (addr) : "memory");
    return result;
}

/**
 * @brief Store Exclusive byte
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter A3.4 - Synchronization and semaphores
 */
static inline uint32_t __STREXB(uint8_t value, volatile uint8_t *addr) {
    uint32_t result;
    __asm__ volatile ("strexb %0, %2, [%1]" : "=&r" (result) : "r" (addr), "r" (value) : "memory");
    return result;
}

/**
 * @brief Clear Exclusive
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter A3.4 - Synchronization and semaphores
 */
static inline void __CLREX(void) {
    __asm__ volatile ("clrex" ::: "memory");
}

/*
 * ============================================================================
 * Core Helper Function Declarations
 * 核心辅助函数声明
 * ============================================================================
 */

/**
 * @brief Set nPRIV bit (enter non-privileged mode)
 */
void armv7m_enter_non_privileged(void);

/**
 * @brief Clear nPRIV bit (enter privileged mode)
 */
void armv7m_enter_privileged(void);

/**
 * @brief Select PSP as current stack pointer
 */
void armv7m_select_psp(void);

/**
 * @brief Select MSP as current stack pointer
 */
void armv7m_select_msp(void);

#if (__FPU_PRESENT == 1)
/**
 * @brief Set FPCA bit (mark floating-point context active)
 */
void armv7m_set_fp_context_active(void);

/**
 * @brief Clear FPCA bit (mark floating-point context inactive)
 */
void armv7m_clear_fp_context_active(void);
#endif

/**
 * @brief Get N flag (Negative)
 */
uint32_t armv7m_get_flag_n(void);

/**
 * @brief Get Z flag (Zero)
 */
uint32_t armv7m_get_flag_z(void);

/**
 * @brief Get C flag (Carry)
 */
uint32_t armv7m_get_flag_c(void);

/**
 * @brief Get V flag (Overflow)
 */
uint32_t armv7m_get_flag_v(void);

/**
 * @brief Get Q flag (Saturation)
 */
uint32_t armv7m_get_flag_q(void);

/**
 * @brief Clear Q flag
 */
void armv7m_clear_flag_q(void);

/**
 * @brief Enable interrupts (clear PRIMASK)
 */
void armv7m_enable_interrupts(void);

/**
 * @brief Disable interrupts (set PRIMASK)
 */
void armv7m_disable_interrupts(void);

/**
 * @brief Enable interrupts with priority masking
 */
void armv7m_set_basepri(uint8_t priority);

/**
 * @brief Clear BASEPRI (enable all interrupts)
 */
void armv7m_clear_basepri(void);

/**
 * @brief Enable FAULTMASK (disable all interrupts including NMI)
 */
void armv7m_set_faultmask(void);

/**
 * @brief Clear FAULTMASK
 */
void armv7m_clear_faultmask(void);

/**
 * @brief Get current exception number
 */
uint32_t armv7m_get_exception_number(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_CORE_H__ */
