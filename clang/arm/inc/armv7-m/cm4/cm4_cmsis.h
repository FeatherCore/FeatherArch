/*
 * ARM Architecture - Cortex-M4 CMSIS Intrinsic Functions
 *
 * ============================================================================
 * File: cm4_cmsis.h
 * Description: Cortex-M4 CMSIS intrinsic function definitions
 * 描述: Cortex-M4 CMSIS 内联函数定义
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 3.2 CMSIS functions (page 3-9)
 *   - Table 3-2 CMSIS functions to generate some Cortex-M4 instructions (page 3-9)
 *   - Table 3-3 CMSIS functions to access the special registers (page 3-9)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_CMSIS_H__
#define __CM4_CMSIS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * CMSIS Functions to Generate Cortex-M4 Instructions
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * ============================================================================
 */

/**
 * @brief Enable IRQ
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Instruction: CPSIE I
 */
static inline void __enable_irq(void)
{
    __asm__ volatile ("CPSIE I" ::: "memory");
}

/**
 * @brief Disable IRQ
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Instruction: CPSID I
 */
static inline void __disable_irq(void)
{
    __asm__ volatile ("CPSID I" ::: "memory");
}

/**
 * @brief Enable Fault IRQ
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Instruction: CPSIE F
 */
static inline void __enable_fault_irq(void)
{
    __asm__ volatile ("CPSIE F" ::: "memory");
}

/**
 * @brief Disable Fault IRQ
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Instruction: CPSID F
 */
static inline void __disable_fault_irq(void)
{
    __asm__ volatile ("CPSID F" ::: "memory");
}

/**
 * @brief Instruction Synchronization Barrier
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Instruction: ISB
 */
static inline void __ISB(void)
{
    __asm__ volatile ("ISB" ::: "memory");
}

/**
 * @brief Data Synchronization Barrier
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Instruction: DSB
 */
static inline void __DSB(void)
{
    __asm__ volatile ("DSB" ::: "memory");
}

/**
 * @brief Data Memory Barrier
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Instruction: DMB
 */
static inline void __DMB(void)
{
    __asm__ volatile ("DMB" ::: "memory");
}

/**
 * @brief Reverse byte order (32-bit)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Instruction: REV
 */
static inline uint32_t __REV(uint32_t value)
{
    uint32_t result;
    __asm__ volatile ("REV %0, %1" : "=r" (result) : "r" (value));
    return result;
}

/**
 * @brief Reverse byte order in each halfword independently
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Instruction: REV16
 */
static inline uint32_t __REV16(uint32_t value)
{
    uint32_t result;
    __asm__ volatile ("REV16 %0, %1" : "=r" (result) : "r" (value));
    return result;
}

/**
 * @brief Reverse byte order in bottom halfword and sign extend
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Instruction: REVSH
 */
static inline int32_t __REVSH(int32_t value)
{
    int32_t result;
    __asm__ volatile ("REVSH %0, %1" : "=r" (result) : "r" (value));
    return result;
}

/**
 * @brief Reverse bits
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Instruction: RBIT
 */
static inline uint32_t __RBIT(uint32_t value)
{
    uint32_t result;
    __asm__ volatile ("RBIT %0, %1" : "=r" (result) : "r" (value));
    return result;
}

/**
 * @brief Send Event
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Instruction: SEV
 */
static inline void __SEV(void)
{
    __asm__ volatile ("SEV" ::: "memory");
}

/**
 * @brief Wait For Event
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Instruction: WFE
 */
static inline void __WFE(void)
{
    __asm__ volatile ("WFE" ::: "memory");
}

/**
 * @brief Wait For Interrupt
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-2 (page 3-9)
 * Instruction: WFI
 */
static inline void __WFI(void)
{
    __asm__ volatile ("WFI" ::: "memory");
}

/*
 * ============================================================================
 * CMSIS Functions to Access Special Registers
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-3 (page 3-9)
 * ============================================================================
 */

/**
 * @brief Get PRIMASK
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-3 (page 3-9)
 */
static inline uint32_t __get_PRIMASK(void)
{
    uint32_t result;
    __asm__ volatile ("MRS %0, primask" : "=r" (result));
    return result;
}

/**
 * @brief Set PRIMASK
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-3 (page 3-9)
 */
static inline void __set_PRIMASK(uint32_t priMask)
{
    __asm__ volatile ("MSR primask, %0" : : "r" (priMask) : "memory");
}

/**
 * @brief Get FAULTMASK
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-3 (page 3-9)
 */
static inline uint32_t __get_FAULTMASK(void)
{
    uint32_t result;
    __asm__ volatile ("MRS %0, faultmask" : "=r" (result));
    return result;
}

/**
 * @brief Set FAULTMASK
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-3 (page 3-9)
 */
static inline void __set_FAULTMASK(uint32_t faultMask)
{
    __asm__ volatile ("MSR faultmask, %0" : : "r" (faultMask) : "memory");
}

/**
 * @brief Get BASEPRI
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-3 (page 3-9)
 */
static inline uint32_t __get_BASEPRI(void)
{
    uint32_t result;
    __asm__ volatile ("MRS %0, basepri" : "=r" (result));
    return result;
}

/**
 * @brief Set BASEPRI
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-3 (page 3-9)
 */
static inline void __set_BASEPRI(uint32_t basePri)
{
    __asm__ volatile ("MSR basepri, %0" : : "r" (basePri) : "memory");
}

/**
 * @brief Get CONTROL
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-3 (page 3-9)
 */
static inline uint32_t __get_CONTROL(void)
{
    uint32_t result;
    __asm__ volatile ("MRS %0, control" : "=r" (result));
    return result;
}

/**
 * @brief Set CONTROL
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-3 (page 3-9)
 */
static inline void __set_CONTROL(uint32_t control)
{
    __asm__ volatile ("MSR control, %0" : : "r" (control) : "memory");
}

/**
 * @brief Get MSP (Main Stack Pointer)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-3 (page 3-9)
 */
static inline uint32_t __get_MSP(void)
{
    uint32_t result;
    __asm__ volatile ("MRS %0, msp" : "=r" (result));
    return result;
}

/**
 * @brief Set MSP (Main Stack Pointer)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-3 (page 3-9)
 */
static inline void __set_MSP(uint32_t topOfMainStack)
{
    __asm__ volatile ("MSR msp, %0" : : "r" (topOfMainStack) : "memory");
}

/**
 * @brief Get PSP (Process Stack Pointer)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-3 (page 3-9)
 */
static inline uint32_t __get_PSP(void)
{
    uint32_t result;
    __asm__ volatile ("MRS %0, psp" : "=r" (result));
    return result;
}

/**
 * @brief Set PSP (Process Stack Pointer)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 3-3 (page 3-9)
 */
static inline void __set_PSP(uint32_t topOfProcStack)
{
    __asm__ volatile ("MSR psp, %0" : : "r" (topOfProcStack) : "memory");
}

/*
 * ============================================================================
 * Additional CMSIS Functions for APSR Access
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 * ============================================================================
 */

/**
 * @brief Get APSR (Application Program Status Register)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline uint32_t __get_APSR(void)
{
    uint32_t result;
    __asm__ volatile ("MRS %0, apsr" : "=r" (result));
    return result;
}

/**
 * @brief Get IPSR (Interrupt Program Status Register)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline uint32_t __get_IPSR(void)
{
    uint32_t result;
    __asm__ volatile ("MRS %0, ipsr" : "=r" (result));
    return result;
}

/**
 * @brief Get xPSR (Program Status Register)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline uint32_t __get_xPSR(void)
{
    uint32_t result;
    __asm__ volatile ("MRS %0, psr" : "=r" (result));
    return result;
}

/*
 * ============================================================================
 * CMSIS Functions for Exclusive Access
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.4.8 (page 3-36)
 * ============================================================================
 */

/**
 * @brief Load-Exclusive (8-bit)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.4.8 (page 3-36)
 * Instruction: LDREXB
 */
static inline uint8_t __LDREXB(volatile uint8_t *addr)
{
    uint8_t result;
    __asm__ volatile ("LDREXB %0, [%1]" : "=r" (result) : "r" (addr));
    return result;
}

/**
 * @brief Load-Exclusive (16-bit)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.4.8 (page 3-36)
 * Instruction: LDREXH
 */
static inline uint16_t __LDREXH(volatile uint16_t *addr)
{
    uint16_t result;
    __asm__ volatile ("LDREXH %0, [%1]" : "=r" (result) : "r" (addr));
    return result;
}

/**
 * @brief Load-Exclusive (32-bit)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.4.8 (page 3-36)
 * Instruction: LDREX
 */
static inline uint32_t __LDREXW(volatile uint32_t *addr)
{
    uint32_t result;
    __asm__ volatile ("LDREX %0, [%1]" : "=r" (result) : "r" (addr));
    return result;
}

/**
 * @brief Store-Exclusive (8-bit)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.4.8 (page 3-36)
 * Instruction: STREXB
 * @return 0 if store succeeded, 1 if failed
 */
static inline uint32_t __STREXB(uint8_t value, volatile uint8_t *addr)
{
    uint32_t result;
    __asm__ volatile ("STREXB %0, %2, [%1]" : "=r" (result) : "r" (addr), "r" (value));
    return result;
}

/**
 * @brief Store-Exclusive (16-bit)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.4.8 (page 3-36)
 * Instruction: STREXH
 * @return 0 if store succeeded, 1 if failed
 */
static inline uint32_t __STREXH(uint16_t value, volatile uint16_t *addr)
{
    uint32_t result;
    __asm__ volatile ("STREXH %0, %2, [%1]" : "=r" (result) : "r" (addr), "r" (value));
    return result;
}

/**
 * @brief Store-Exclusive (32-bit)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.4.8 (page 3-36)
 * Instruction: STREX
 * @return 0 if store succeeded, 1 if failed
 */
static inline uint32_t __STREXW(uint32_t value, volatile uint32_t *addr)
{
    uint32_t result;
    __asm__ volatile ("STREX %0, %2, [%1]" : "=r" (result) : "r" (addr), "r" (value));
    return result;
}

/**
 * @brief Clear Exclusive
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.4.9 (page 3-38)
 * Instruction: CLREX
 */
static inline void __CLREX(void)
{
    __asm__ volatile ("CLREX" ::: "memory");
}

/*
 * ============================================================================
 * CMSIS Functions for DSP Instructions
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.8 (page 3-95)
 * ============================================================================
 */

/**
 * @brief Signed Saturate
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.8.1 (page 3-96)
 * Instruction: SSAT
 */
static inline int32_t __SSAT(int32_t val, uint32_t sat)
{
    int32_t result;
    __asm__ volatile ("SSAT %0, %1, %2" : "=r" (result) : "I" (sat), "r" (val));
    return result;
}

/**
 * @brief Unsigned Saturate
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.8.2 (page 3-96)
 * Instruction: USAT
 */
static inline uint32_t __USAT(int32_t val, uint32_t sat)
{
    uint32_t result;
    __asm__ volatile ("USAT %0, %1, %2" : "=r" (result) : "I" (sat), "r" (val));
    return result;
}

/**
 * @brief Count Leading Zeros
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.5.4 (page 3-48)
 * Instruction: CLZ
 */
static inline uint8_t __CLZ(uint32_t value)
{
    uint8_t result;
    __asm__ volatile ("CLZ %0, %1" : "=r" (result) : "r" (value));
    return result;
}

/*
 * ============================================================================
 * CMSIS Functions for NOP and BKPT
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide
 * ============================================================================
 */

/**
 * @brief No Operation
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.9.10 (page 3-165)
 * Instruction: NOP
 */
static inline void __NOP(void)
{
    __asm__ volatile ("NOP");
}

/**
 * @brief Breakpoint
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 3.9.1 (page 3-158)
 * Instruction: BKPT
 */
static inline void __BKPT(uint8_t value)
{
    __asm__ volatile ("BKPT %0" : : "I" (value));
}

#ifdef __cplusplus
}
#endif

#endif /* __CM4_CMSIS_H__ */
