/*
 * ARM Architecture - ARMv8-M Core Registers
 *
 * ============================================================================
 * File: armv8m_core.h
 * Description: ARMv8-M core register definitions and inline functions
 * 描述: ARMv8-M 核心寄存器定义和内联函数
 *
 * This file provides definitions for ARMv8-M core registers including:
 * - CONTROL, MSP, PSP, PRIMASK, BASEPRI, FAULTMASK
 * - Stack limit registers (MSPLIM, PSPLIM)
 * - Status registers (APSR, IPSR, xPSR)
 * - Memory barrier instructions
 * - Low power mode instructions
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B3: Programmers' Model
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V8M_CORE_H__
#define __ARCH_ARM_V8M_CORE_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv8m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * ARMv8-M Core Register Bit Definitions
 * ARMv8-M 核心寄存器位定义
 *
 * Reference: Arm(R) v8-M ARM Chapter B3 (Programmers' Model)
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
 *   [3] SFPA     - Secure floating-point active (TrustZone)
 *   [4] BTI_EN   - Branch target identification enable (privileged)
 *   [5] UBTI_EN  - Unprivileged branch target identification enable
 *   [6] PAC_EN   - Pointer authentication code enable (privileged)
 *   [7] UPAC_EN  - Unprivileged pointer authentication code enable
 */
#define CONTROL_nPRIV_Pos          0U
#define CONTROL_nPRIV_Msk         (1UL << CONTROL_nPRIV_Pos)
#define CONTROL_SPSEL_Pos          1U
#define CONTROL_SPSEL_Msk          (1UL << CONTROL_SPSEL_Pos)
#define CONTROL_FPCA_Pos           2U
#define CONTROL_FPCA_Msk           (1UL << CONTROL_FPCA_Pos)
#define CONTROL_SFPA_Pos           3U
#define CONTROL_SFPA_Msk           (1UL << CONTROL_SFPA_Pos)
#define CONTROL_BTI_EN_Pos         4U
#define CONTROL_BTI_EN_Msk         (1UL << CONTROL_BTI_EN_Pos)
#define CONTROL_UBTI_EN_Pos        5U
#define CONTROL_UBTI_EN_Msk        (1UL << CONTROL_UBTI_EN_Pos)
#define CONTROL_PAC_EN_Pos         6U
#define CONTROL_PAC_EN_Msk         (1UL << CONTROL_PAC_EN_Pos)
#define CONTROL_UPAC_EN_Pos        7U
#define CONTROL_UPAC_EN_Msk        (1UL << CONTROL_UPAC_EN_Pos)

/**
 * @brief CONTROL_nPRIV bit: Non-privileged execution level
 * 0: Privileged execution / 特权执行
 * 1: Non-privileged execution / 非特权执行
 */
#define CONTROL_nPRIV              (1UL << CONTROL_nPRIV_Pos)

/**
 * @brief CONTROL_SPSEL bit: Stack pointer select
 * 0: Use MSP (Main Stack Pointer) / 使用 MSP
 * 1: Use PSP (Process Stack Pointer) / 使用 PSP
 */
#define CONTROL_SPSEL              (1UL << CONTROL_SPSEL_Pos)

/**
 * @brief CONTROL_FPCA bit: Floating-point context active
 * 0: No floating-point context active
 * 1: Floating-point context active
 */
#define CONTROL_FPCA               (1UL << CONTROL_FPCA_Pos)

/**
 * @brief CONTROL_SFPA bit: Secure floating-point active (TrustZone)
 */
#define CONTROL_SFPA               (1UL << CONTROL_SFPA_Pos)

/**
 * @brief CONTROL_BTI_EN bit: Branch target identification enable
 */
#define CONTROL_BTI_EN             (1UL << CONTROL_BTI_EN_Pos)

/**
 * @brief CONTROL_UBTI_EN bit: Unprivileged BTI enable
 */
#define CONTROL_UBTI_EN            (1UL << CONTROL_UBTI_EN_Pos)

/**
 * @brief CONTROL_PAC_EN bit: Pointer authentication code enable
 */
#define CONTROL_PAC_EN             (1UL << CONTROL_PAC_EN_Pos)

/**
 * @brief CONTROL_UPAC_EN bit: Unprivileged PAC enable
 */
#define CONTROL_UPAC_EN            (1UL << CONTROL_UPAC_EN_Pos)

/**
 * PRIMASK register bit definitions
 * PRIMASK 寄存器位定义
 */
#define PRIMASK_Pos                0U
#define PRIMASK_Msk              (1UL << PRIMASK_Pos)
#define PRIMASK                  (1UL << PRIMASK_Pos)

/**
 * FAULTMASK register bit definitions
 * FAULTMASK 寄存器位定义
 */
#define FAULTMASK_Pos             0U
#define FAULTMASK_Msk            (1UL << FAULTMASK_Pos)
#define FAULTMASK                (1UL << FAULTMASK_Pos)

/**
 * BASEPRI register bit definitions
 * BASEPRI 寄存器位定义
 */
#define BASEPRI_Pos               0U
#define BASEPRI_Msk              (0xFFUL << BASEPRI_Pos)
#define BASEPRI                  (0xFFUL << BASEPRI_Pos)

/**
 * xPSR register bit definitions
 * xPSR 寄存器位定义
 *
 * APSR bits [31:28]: N, Z, C, V, Q
 * APSR bits [19:16]: GE[3:0] (SIMD instructions)
 * IPSR bits [8:0]: Exception number
 * EPSR bits [26:25,15:10]: T, ICI/IT
 */
#define xPSR_N_Pos               31U
#define xPSR_N_Msk              (1UL << xPSR_N_Pos)
#define xPSR_Z_Pos               30U
#define xPSR_Z_Msk              (1UL << xPSR_Z_Pos)
#define xPSR_C_Pos               29U
#define xPSR_C_Msk              (1UL << xPSR_C_Pos)
#define xPSR_V_Pos               28U
#define xPSR_V_Msk              (1UL << xPSR_V_Pos)
#define xPSR_Q_Pos               27U
#define xPSR_Q_Msk              (1UL << xPSR_Q_Pos)
#define xPSR_GE_Pos              16U
#define xPSR_GE_Msk             (0xFUL << xPSR_GE_Pos)
#define xPSR_IC_Pos              25U
#define xPSR_IC_Msk             (1UL << xPSR_IC_Pos)
#define xPSR_T_Pos               24U
#define xPSR_T_Msk              (1UL << xPSR_T_Pos)
#define xPSR_Exception_Pos        0U
#define xPSR_Exception_Msk       (0x1FFUL << xPSR_Exception_Pos)

/* xPSR Flag bits */
#define xPSR_N                   (1UL << xPSR_N_Pos)
#define xPSR_Z                   (1UL << xPSR_Z_Pos)
#define xPSR_C                   (1UL << xPSR_C_Pos)
#define xPSR_V                   (1UL << xPSR_V_Pos)
#define xPSR_Q                   (1UL << xPSR_Q_Pos)
#define xPSR_GE                  (0xFUL << xPSR_GE_Pos)
#define xPSR_T                   (1UL << xPSR_T_Pos)
#define xPSR_IC                  (1UL << xPSR_IC_Pos)
#define xPSR_Exception           (0x1FFUL << xPSR_Exception_Pos)

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
 * @brief Get MSPLIM register (MSP Limit)
 * @return Current MSPLIM value
 */
static inline uint32_t __get_MSPLIM(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, msplim" : "=r" (result));
    return result;
}

/**
 * @brief Set MSPLIM register
 * @param msplim New MSPLIM value
 */
static inline void __set_MSPLIM(uint32_t msplim) {
    __asm__ volatile ("MSR msplim, %0" : : "r" (msplim) : "memory");
}

/**
 * @brief Get PSPLIM register (PSP Limit)
 * @return Current PSPLIM value
 */
static inline uint32_t __get_PSPLIM(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, psplim" : "=r" (result));
    return result;
}

/**
 * @brief Set PSPLIM register
 * @param psplim New PSPLIM value
 */
static inline void __set_PSPLIM(uint32_t psplim) {
    __asm__ volatile ("MSR psplim, %0" : : "r" (psplim) : "memory");
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
 */
static inline void __ISB(void) {
    __asm__ volatile ("isb 0xF" ::: "memory");
}

/**
 * @brief Data Synchronization Barrier (DSB)
 * Ensures completion of all explicit memory accesses
 */
static inline void __DSB(void) {
    __asm__ volatile ("dsb 0xF" ::: "memory");
}

/**
 * @brief Data Memory Barrier (DMB)
 * Ensures ordering of memory accesses
 */
static inline void __DMB(void) {
    __asm__ volatile ("dmb 0xF" ::: "memory");
}

/**
 * @brief Speculative Store Bypass Barrier (SSBB)
 * Prevents speculative loads from bypassing stores
 */
static inline void __SSBB(void) {
    __asm__ volatile ("ssbb" ::: "memory");
}

/**
 * @brief Physical Speculative Store Bypass Barrier (PSSBB)
 */
static inline void __PSSBB(void) {
    __asm__ volatile ("pssbb" ::: "memory");
}

/**
 * @brief Consumption of Speculative Data Barrier (CSDB)
 */
static inline void __CSDB(void) {
    __asm__ volatile ("csdb" ::: "memory");
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
 */
static inline void __WFI(void) {
    __asm__ volatile ("wfi" ::: "memory");
}

/**
 * @brief Wait For Event (WFE)
 * Suspends execution until an event occurs
 */
static inline void __WFE(void) {
    __asm__ volatile ("wfe" ::: "memory");
}

/**
 * @brief Send Event (SEV)
 * Sends an event to all cores in a multiprocessor system
 */
static inline void __SEV(void) {
    __asm__ volatile ("sev" ::: "memory");
}

/**
 * @brief Send Event Local (SEVL)
 * Sets the local event register
 */
static inline void __SEVL(void) {
    __asm__ volatile ("sevl" ::: "memory");
}

/**
 * @brief Get Event Register
 * @return 1 if event register is set, 0 otherwise
 */
static inline uint32_t __get_EVENTREGISTER(void) {
    uint32_t result;
    __asm__ volatile ("mrs %0, eventregister" : "=r" (result));
    return result;
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

/*
 * ============================================================================
 * Function Prototypes for Non-Inline Functions
 * 非内联函数原型
 * ============================================================================
 */

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V8M_CORE_H__ */
