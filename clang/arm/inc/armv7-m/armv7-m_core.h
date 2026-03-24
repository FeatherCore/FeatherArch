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
 * - Instruction set support (A4-A5)
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter A1: Introduction
 *     * A1.2 The Armv7-M architecture profile (page A1-21)
 *     * A1.3 Architecture extensions (page A1-22)
 *   - Chapter A2: Application Level Programmers' Model
 *     * A2.1 About the application level programmers' model (page A2-24)
 *     * A2.2 Arm processor data types and arithmetic (page A2-25)
 *     * A2.3 Registers and Execution state (page A2-30)
 *       - A2.3.1 Arm core registers (R0-R12, SP/LR/PC)
 *       - A2.3.2 The Application Program Status Register (APSR)
 *       - A2.3.3 Execution state support (Thumb state only)
 *       - A2.3.4 Privileged execution (Thread mode vs Handler mode)
 *     * A2.4 Exceptions, faults and interrupts (page A2-33)
 *   - Chapter A3: Arm Architecture Memory Model
 *     * A3.1 Address space (page A3-64)
 *     * A3.2 Alignment support (page A3-65)
 *     * A3.3 Endian support (page A3-67)
 *     * A3.4 Synchronization and semaphores (page A3-70)
 *       - LDREX, STREX, CLREX instructions
 *     * A3.7 Memory access order (page A3-89)
 *       - Memory barriers (DMB, DSB, ISB)
 *   - Chapter A4: The Armv7-M Instruction Set
 *     * A4.1 About the instruction set (page A4-102)
 *       - Thumb-2 technology with 16-bit and 32-bit instructions
 *       - Interworking support (bit[0] of address)
 *     * A4.2 Unified Assembler Language (page A4-104)
 *     * A4.3 Branch instructions (page A4-106)
 *       - B, BL, BX, BLX, CBZ, CBNZ, TBB, TBH
 *     * A4.4 Data-processing instructions (page A4-107)
 *       - Shift instructions: LSL, LSR, ASR, ROR, RRX
 *       - Standard data-processing: ADD, SUB, AND, ORR, etc.
 *     * A4.5 Status register access instructions (page A4-114)
 *     * A4.6 Load and store instructions (page A4-115)
 *     * A4.7 Load Multiple and Store Multiple (page A4-117)
 *     * A4.8 Miscellaneous instructions (page A4-118)
 *       - NOP, YIELD, WFI, WFE, SEV, SVC, BKPT
 *       - DMB, DSB, ISB, CLREX
 *   - Chapter A5: The Thumb Instruction Set Encoding
 *     * A5.1 Thumb instruction set encoding (page A5-126)
 *       - 16-bit vs 32-bit instruction identification
 *       - bits[15:11] = 0b11101/11110/11111 indicate 32-bit
 *     * A5.2 16-bit Thumb instruction encoding (page A5-129)
 *     * A5.3 32-bit Thumb instruction encoding (page A5-137)
 *   - Chapter A7: Instruction Details
 *     * A7.1 Format of instruction descriptions (page A7-172)
 *       - Instruction section title, introduction, encodings
 *       - Assembler syntax, pseudocode, exception information
 *     * A7.2 Standard assembler syntax fields (page A7-177)
 *       - <c> condition field (default AL - always)
 *       - <q> qualifier field (.N narrow, .W wide)
 *     * A7.3 Conditional execution (page A7-178)
 *       - Table A7-1 Condition codes (EQ, NE, CS, CC, MI, PL, VS, VC, HI, LS, GE, LT, GT, LE, AL)
 *       - Condition flags evaluation (N, Z, C, V)
 *       - A7.3.3 ITSTATE (page A7-179)
 *         * IT[7:5] - Base condition for IT block
 *         * IT[4:0] - Size of IT block and condition bits
 *         * Table A7-2 Effect of IT Execution state bits
 *     * A7.4 Shifts applied to a register (page A7-182)
 *       - LSL, LSR, ASR, ROR, RRX
 *     * A7.5 Memory accesses (page A7-184)
 *     * A7.6 Hint instructions (page A7-185)
 *       - NOP, YIELD, WFE, WFI, SEV
 *     * A7.7 Alphabetical list of Armv7-M Thumb instructions (page A7-186)
 *   - Chapter B1: System Level Programmers' Model
 *     * B1.1 Introduction to the system level (page B1-510)
 *     * B1.2 About the Armv7-M memory mapped architecture (page B1-511)
 *       - Private Peripheral Bus (PPB) at 0xE0000000-0xE00FFFFF
 *       - System Control Space (SCS) at 0xE000E000-0xE000EFFF
 *     * B1.3 Overview of system level terminology and operation (page B1-512)
 *       - B1.3.1 Modes, privilege and stacks (page B1-512)
 *         * Thread mode vs Handler mode
 *         * Privileged vs Unprivileged execution
 *         * Main stack (MSP) vs Process stack (PSP)
 *       - B1.3.2 Exceptions (page B1-513)
 *         * Exception categories: Reset, SVCall, Fault, Interrupt
 *         * Exception states: Inactive, Pending, Active, Active and pending
 *       - B1.3.3 Execution state (page B1-515)
 *       - B1.3.4 Debug state (page B1-515)
 *     * B1.4 Registers (page B1-516)
 *       - B1.4.1 The Arm core registers (page B1-516)
 *         * SP_main (MSP) and SP_process (PSP)
 *       - B1.4.2 The special-purpose Program Status Registers, xPSR (page B1-516)
 *         * APSR, IPSR, EPSR
 *   - Chapter B2: System Memory Model
 *     * B2.1 About the system memory model (page B2-570)
 *     * B2.2 Caches and branch predictors (page B2-571)
 *       - B2.2.1 Cache identification (page B2-571)
 *       - B2.2.2 Cache enabling and disabling (page B2-572)
 *       - B2.2.3 Cache behavior (page B2-572)
 *       - B2.2.4 Branch predictors (page B2-574)
 *   - Chapter B3: System Address Map
 *     * B3.1 The system address map (page B3-592)
 *       - Table B3-1 Armv7-M address map
 *       - Code, SRAM, Peripheral, RAM, Device regions
 *     * B3.2 System Control Space (SCS) (page B3-595)
 *       - Table B3-3 SCS address space regions
 *       - Table B3-4 Summary of SCB registers
 *       - System control and ID registers
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_CORE_H__
#define __ARCH_ARM_V7M_CORE_H__

#include <stdint.h>
#include <stdbool.h>
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
 * Reference: Chapter A2.3.4 Privileged execution (page A2-32)
 *   - Thread mode is the fundamental mode for application execution
 *   - Can execute in privileged or unprivileged manner
 *   - All exceptions execute as privileged code in Handler mode
 *
 * CONTROL Register (bits):
 *   [0] nPRIV    - Non-privileged execution level
 *                  0: Privileged execution (可以访问所有资源)
 *                  1: Non-privileged execution (受限访问，用于应用程序)
 *   [1] SPSEL    - Stack pointer select (0=MSP, 1=PSP)
 *                  Reference: Chapter A2.3.1 Arm core registers (page A2-30)
 *   [2] FPCA     - Floating-point context active
 *                  Reference: Chapter A2.5 The optional Floating-point Extension (page A2-34)
 */
#define CONTROL_nPRIV_Pos          0U
#define CONTROL_nPRIV_Msk         (1UL << CONTROL_nPRIV_Pos)
#define CONTROL_SPSEL_Pos          1U
#define CONTROL_SPSEL_Msk          (1UL << CONTROL_SPSEL_Pos)
#define CONTROL_FPCA_Pos           2U
#define CONTROL_FPCA_Msk           (1UL << CONTROL_FPCA_Pos)

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
 * Reference: Chapter A2.3.2 The Application Program Status Register (APSR) (page A2-31)
 *   - N, Z, C, V, Q flags can be updated by many instructions
 *   - GE[3:0] used by SIMD instructions (DSP extension, Armv7E-M only)
 *
 * APSR bits [31:28]: N, Z, C, V, Q
 *   N (bit[31]): Negative condition flag - set to bit[31] of result
 *   Z (bit[30]): Zero condition flag - set to 1 if result is zero
 *   C (bit[29]): Carry condition flag - set on unsigned overflow
 *   V (bit[28]): Overflow condition flag - set on signed overflow
 *   Q (bit[27]): Saturation flag - set by SSAT/USAT or SIMD multiply overflow
 *
 * APSR bits [19:16]: GE[3:0] (SIMD instructions, ARMv7E-M only)
 *   Reference: Chapter A2.2 Arm processor data types and arithmetic (page A2-25)
 *
 * IPSR bits [8:0]: Exception number
 *   Reference: Chapter A2.4 Exceptions, faults and interrupts (page A2-33)
 *
 * EPSR bits [24]: T (Thumb state bit)
 *   Reference: Chapter A2.3.3 Execution state support (page A2-32)
 *   - Armv7-M only executes Thumb instructions (T bit always 1 in normal execution)
 * EPSR bits [26:25]: ICI/IT
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

/**
 * @brief Get Link Register (LR/R14)
 * @return Current LR value
 */
static inline uint32_t __get_LR(void) {
    uint32_t result;
    __asm__ volatile ("MOV %0, lr" : "=r" (result));
    return result;
}

/**
 * @brief Set Link Register (LR/R14)
 * @param lr New LR value
 */
static inline void __set_LR(uint32_t lr) {
    __asm__ volatile ("MOV lr, %0" : : "r" (lr));
}

/**
 * @brief Get Program Counter (PC/R15)
 * @return Current PC value
 */
static inline uint32_t __get_PC(void) {
    uint32_t result;
    __asm__ volatile ("MOV %0, pc" : "=r" (result));
    return result;
}

/**
 * @brief Get Stack Pointer (SP)
 * @return Current SP value (MSP or PSP depending on CONTROL.SPSEL)
 */
static inline uint32_t __get_SP(void) {
    uint32_t result;
    __asm__ volatile ("MOV %0, sp" : "=r" (result));
    return result;
}

/**
 * @brief Set Stack Pointer (SP)
 * @param sp New SP value
 */
static inline void __set_SP(uint32_t sp) {
    __asm__ volatile ("MOV sp, %0" : : "r" (sp));
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
 *
 * Reference: Chapter A3.7 Memory access order (page A3-89)
 *   - A3.7.3 Memory barriers
 *   - ISB ensures that all subsequent instructions are fetched from cache/memory
 *     after the barrier completes
 *   - Used after changing memory mapping or access permissions
 */
static inline void __ISB(void) {
    __asm__ volatile ("isb 0xF" ::: "memory");
}

/**
 * @brief Data Synchronization Barrier (DSB)
 * Ensures completion of all explicit memory accesses
 *
 * Reference: Chapter A3.7 Memory access order (page A3-89)
 *   - A3.7.3 Memory barriers
 *   - DSB ensures all memory accesses before the barrier complete
 *     before any memory accesses after the barrier start
 *   - Used for memory synchronization between processors
 */
static inline void __DSB(void) {
    __asm__ volatile ("dsb 0xF" ::: "memory");
}

/**
 * @brief Data Memory Barrier (DMB)
 * Ensures ordering of memory accesses
 *
 * Reference: Chapter A3.7 Memory access order (page A3-89)
 *   - A3.7.3 Memory barriers
 *   - DMB ensures relative ordering of memory accesses
 *   - Memory accesses before DMB complete before memory accesses after DMB
 *   - Used for enforcing memory ordering without full synchronization
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
 *
 * Reference: Chapter A2.4 Exceptions, faults and interrupts (page A2-33)
 *   - A2.4.1 System-related events
 *   - WFI instruction support for power management
 *   - Processor enters sleep state until interrupt occurs
 *   - Used for power or performance reasons to suspend current task
 */
static inline void __WFI(void) {
    __asm__ volatile ("wfi" ::: "memory");
}

/**
 * @brief Wait For Event (WFE)
 * Suspends execution until an event occurs
 *
 * Reference: Chapter A2.4 Exceptions, faults and interrupts (page A2-33)
 *   - A2.4.1 System-related events
 *   - WFE instruction support for multiprocessor synchronization
 *   - Processor enters sleep state until event is signaled
 *   - Used with SEV instruction for core-to-core communication
 *   - Reference: Chapter A3.4 Synchronization and semaphores (page A3-70)
 */
static inline void __WFE(void) {
    __asm__ volatile ("wfe" ::: "memory");
}

/**
 * @brief Send Event (SEV)
 * Sends an event to all cores in a multiprocessor system
 *
 * Reference: Chapter A2.4 Exceptions, faults and interrupts (page A2-33)
 *   - A2.4.1 System-related events
 *   - SEV instruction signals an event to all cores
 *   - Used to wake up cores waiting in WFE
 *   - Reference: Chapter A3.4 Synchronization and semaphores (page A3-70)
 *     * Part of exclusive access and multiprocessor synchronization
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
 * Instruction Set Support (Chapter A4-A5)
 * 指令集支持 (A4-A5章节)
 * ============================================================================
 */

/**
 * @brief 16-bit Thumb Instruction Classes (A5.2)
 * Reference: Chapter A5.2 16-bit Thumb instruction encoding (page A5-129)
 *   - Table A5-1 16-bit Thumb instruction encoding
 */
typedef enum {
    ARMV7M_INSTR_SHIFT_ADD_SUB_MOV_CMP = 0,  /* 00xxxx: Shift, add, subtract, move, compare */
    ARMV7M_INSTR_DATA_PROC,                   /* 010000: Data processing */
    ARMV7M_INSTR_SPECIAL_DATA_BRANCH,         /* 010001: Special data instructions and branch */
    ARMV7M_INSTR_LDR_LITERAL,                 /* 01001x: Load from Literal Pool */
    ARMV7M_INSTR_LOAD_STORE_SINGLE,           /* 0101xx, 011xxx, 100xxx: Load/store single data item */
    ARMV7M_INSTR_ADR_PC_REL,                  /* 10100x: Generate PC-relative address */
    ARMV7M_INSTR_ADR_SP_REL,                  /* 10101x: Generate SP-relative address */
    ARMV7M_INSTR_MISC_16BIT,                  /* 1011xx: Miscellaneous 16-bit instructions */
    ARMV7M_INSTR_STM,                         /* 11000x: Store multiple registers */
    ARMV7M_INSTR_LDM,                         /* 11001x: Load multiple registers */
    ARMV7M_INSTR_COND_BRANCH_SVC,             /* 1101xx: Conditional branch and Supervisor Call */
    ARMV7M_INSTR_UNCOND_BRANCH,               /* 11100x: Unconditional Branch */
    ARMV7M_INSTR_UNDEFINED                    /* Undefined/Reserved */
} armv7m_instr_class_t;

/**
 * @brief Condition Codes (A4.1.2)
 * Reference: Chapter A4.1.2 Conditional execution (page A4-103)
 */
typedef enum {
    ARMV7M_COND_EQ = 0x0,  /* Equal: Z == 1 */
    ARMV7M_COND_NE = 0x1,  /* Not equal: Z == 0 */
    ARMV7M_COND_CS = 0x2,  /* Carry set: C == 1 */
    ARMV7M_COND_CC = 0x3,  /* Carry clear: C == 0 */
    ARMV7M_COND_MI = 0x4,  /* Negative: N == 1 */
    ARMV7M_COND_PL = 0x5,  /* Positive or zero: N == 0 */
    ARMV7M_COND_VS = 0x6,  /* Overflow: V == 1 */
    ARMV7M_COND_VC = 0x7,  /* No overflow: V == 0 */
    ARMV7M_COND_HI = 0x8,  /* Higher (unsigned): C == 1 && Z == 0 */
    ARMV7M_COND_LS = 0x9,  /* Lower or same (unsigned): C == 0 || Z == 1 */
    ARMV7M_COND_GE = 0xA,  /* Greater or equal (signed): N == V */
    ARMV7M_COND_LT = 0xB,  /* Less than (signed): N != V */
    ARMV7M_COND_GT = 0xC,  /* Greater than (signed): Z == 0 && N == V */
    ARMV7M_COND_LE = 0xD,  /* Less or equal (signed): Z == 1 || N != V */
    ARMV7M_COND_AL = 0xE,  /* Always (unconditional) */
    ARMV7M_COND_RESERVED = 0xF  /* Reserved */
} armv7m_cond_t;

/*
 * ============================================================================
 * Thumb Instruction Encoding Detection (A5.1)
 * Thumb指令编码检测
 *
 * Reference: Chapter A5.1 Thumb instruction set encoding (page A5-126)
 *   - Thumb instruction stream is halfword-aligned
 *   - 32-bit instruction if bits[15:11] = 0b11101/11110/11111
 *   - Otherwise 16-bit instruction
 * ============================================================================
 */

/**
 * @brief Check if a halfword is the first halfword of a 32-bit Thumb instruction
 * @param hw Halfword value
 * @return 1 if 32-bit instruction, 0 if 16-bit instruction
 *
 * Reference: Chapter A5.1 Thumb instruction set encoding (page A5-126)
 *   - If bits[15:11] take values 0b11101, 0b11110, or 0b11111,
 *     the halfword is the first halfword of a 32-bit instruction
 */
static inline int armv7m_is_32bit_instruction(uint16_t hw) {
    uint8_t opcode = (hw >> 11) & 0x1F;
    return (opcode == 0x1D) || (opcode == 0x1E) || (opcode == 0x1F);
}

/**
 * @brief ITSTATE structure (A7.3.3)
 * Reference: Chapter A7.3.3 ITSTATE (page A7-179)
 *   - IT[7:5]: Base condition for the current IT block (cond_base)
 *   - IT[4:0]: Size of IT block and condition bits for each instruction
 *
 * Table A7-2 Effect of IT Execution state bits:
 *   - 4-instruction IT block: IT[4:0] = P1 P2 P3 P4 1
 *   - 3-instruction IT block: IT[4:0] = P1 P2 P3 1 0
 *   - 2-instruction IT block: IT[4:0] = P1 P2 1 0 0
 *   - 1-instruction IT block: IT[4:0] = P1 1 0 0 0
 *   - Normal execution:       IT[7:0] = 0x00
 */
typedef union {
    uint8_t value;
    struct {
        uint8_t first_cond:1;    /* Bit 0: First condition bit (P1) */
        uint8_t second_cond:1;   /* Bit 1: Second condition bit (P2) */
        uint8_t third_cond:1;    /* Bit 2: Third condition bit (P3) */
        uint8_t fourth_cond:1;   /* Bit 3: Fourth condition bit (P4) */
        uint8_t mask:4;          /* Bits [6:3]: Mask bits */
        uint8_t base_cond:3;     /* Bits [7:5]: Base condition (cond_base) */
    } bits;
} armv7m_itstate_t;

/**
 * @brief Extract condition code from IT instruction
 * @param it_state Current ITSTATE value
 * @return Condition code (0-15)
 *
 * Reference: Chapter A4.1.2 Conditional execution (page A4-103)
 *   - IT instruction makes up to 4 following instructions conditional
 *   - Condition derived from ITSTATE
 * Reference: Chapter A7.3.3 ITSTATE (page A7-179)
 *   - Current condition = {IT[7:5], IT[4]} for first instruction
 */
static inline uint8_t armv7m_it_get_condition(uint8_t it_state) {
    return (it_state >> 4) & 0x0F;
}

/**
 * @brief Check if currently in an IT block
 * @param it_state Current ITSTATE value
 * @return 1 if in IT block, 0 otherwise
 *
 * Reference: Chapter A7.3.3 ITSTATE (page A7-179)
 *   - InITBlock() returns TRUE if ITSTATE.IT[3:0] != '0000'
 */
static inline int armv7m_in_it_block(uint8_t it_state) {
    return (it_state & 0x0F) != 0;
}

/**
 * @brief Check if this is the last instruction in an IT block
 * @param it_state Current ITSTATE value
 * @return 1 if last instruction, 0 otherwise
 *
 * Reference: Chapter A7.3.3 ITSTATE (page A7-179)
 *   - LastInITBlock() returns TRUE if ITSTATE.IT[3:0] == '0001'
 */
static inline int armv7m_last_in_it_block(uint8_t it_state) {
    return (it_state & 0x0F) == 0x01;
}

/**
 * @brief Advance ITSTATE to next instruction
 * @param it_state Pointer to current ITSTATE value
 *
 * Reference: Chapter A7.3.3 ITSTATE (page A7-179)
 *   - ITAdvance() pseudocode:
 *     if ITSTATE.IT[2:0] == '000' then
 *         ITSTATE.IT = '00000000'
 *     else
 *         ITSTATE.IT[4:0] = LSL(ITSTATE.IT[4:0], 1)
 */
static inline void armv7m_it_advance(uint8_t *it_state) {
    if ((*it_state & 0x07) == 0) {
        *it_state = 0;
    } else {
        *it_state = (*it_state & 0xE0) | ((*it_state & 0x1F) << 1);
    }
}

/**
 * @brief Check if instruction should execute based on condition flags
 * @param cond Condition code (0-15)
 * @param apsr APSR register value
 * @return 1 if condition passes, 0 otherwise
 *
 * Reference: Chapter A4.1.2 Conditional execution (page A4-103)
 *   - Condition checked against N, Z, C, V flags in APSR
 */
int armv7m_condition_passed(uint8_t cond, uint32_t apsr);

/*
 * ============================================================================
 * Branch Instructions (A4.3)
 * 分支指令
 *
 * Reference: Chapter A4.3 Branch instructions (page A4-106)
 *   - B: Branch to target address (+/- 1MB)
 *   - BL: Call subroutine (+/- 16MB)
 *   - BX: Branch with instruction set change
 *   - BLX: Call subroutine with instruction set change
 *   - CBZ/CBNZ: Compare and branch on zero/nonzero (0-126B)
 *   - TBB/TBH: Table branch with byte/halfword offsets
 * ============================================================================
 */

/**
 * @brief Branch with link (BL) - Call subroutine
 * @param target Target address
 *
 * Reference: Chapter A4.3 Branch instructions (page A4-106)
 *   - BL stores return address in LR
 *   - Range: +/- 16MB
 *   - Used for subroutine calls
 */
static inline void armv7m_bl(void (*target)(void)) {
    __asm__ volatile (
        "bl %0"
        :
        : "r" (target)
        : "lr", "memory"
    );
}

/**
 * @brief Branch and exchange (BX) - Branch with instruction set change
 * @param target Target address (bit[0] selects instruction set)
 *
 * Reference: Chapter A4.3 Branch instructions (page A4-106)
 *   - BX writes bit[0] of target to EPSR.T
 *   - In Armv7-M, bit[0] must be 1 (Thumb state only)
 */
static inline void armv7m_bx(void (*target)(void)) {
    __asm__ volatile (
        "bx %0"
        :
        : "r" (target)
        : "memory"
    );
}

/**
 * @brief Supervisor Call (SVC) - Generate SVCall exception
 * @param imm Supervisor call number (0-255)
 *
 * Reference: Chapter A4.9 Exception-generating instructions (page A4-119)
 *   - SVC causes an SVCall exception
 *   - Main mechanism for unprivileged code to call OS
 */
static inline void armv7m_svc(uint8_t imm) {
    __asm__ volatile (
        "svc %0"
        :
        : "I" (imm)
        : "memory"
    );
}

/*
 * ============================================================================
 * Data-Processing Instructions (A4.4)
 * 数据处理指令
 *
 * Reference: Chapter A4.4 Data-processing instructions (page A4-107)
 *   - Shift instructions: LSL, LSR, ASR, ROR, RRX
 *   - Standard data-processing: ADD, SUB, AND, ORR, etc.
 *   - Multiply instructions
 *   - Saturating instructions (SSAT, USAT)
 *   - Packing and unpacking instructions
 *   - Divide instructions (SDIV, UDIV)
 * ============================================================================
 */

/**
 * @brief Count Leading Zeros (CLZ)
 * @param value Input value
 * @return Number of leading zeros (0-32)
 *
 * Reference: Chapter A4.4.8 Miscellaneous data-processing instructions (page A4-113)
 *   - CLZ counts the number of binary zero bits before the first binary one bit
 */
static inline uint32_t armv7m_clz(uint32_t value) {
    uint32_t result;
    __asm__ volatile (
        "clz %0, %1"
        : "=r" (result)
        : "r" (value)
    );
    return result;
}

/**
 * @brief Reverse Bits (RBIT)
 * @param value Input value
 * @return Bit-reversed value
 *
 * Reference: Chapter A4.4.8 Miscellaneous data-processing instructions (page A4-113)
 *   - RBIT reverses the bit order in a 32-bit register
 */
static inline uint32_t armv7m_rbit(uint32_t value) {
    uint32_t result;
    __asm__ volatile (
        "rbit %0, %1"
        : "=r" (result)
        : "r" (value)
    );
    return result;
}

/**
 * @brief Byte-Reverse Word (REV)
 * @param value Input value
 * @return Byte-reversed value
 *
 * Reference: Chapter A4.4.8 Miscellaneous data-processing instructions (page A4-113)
 *   - REV reverses the byte order in a 32-bit register
 *   - Used for endianness conversion
 */
static inline uint32_t armv7m_rev(uint32_t value) {
    uint32_t result;
    __asm__ volatile (
        "rev %0, %1"
        : "=r" (result)
        : "r" (value)
    );
    return result;
}

/**
 * @brief Byte-Reverse Packed Halfword (REV16)
 * @param value Input value
 * @return Halfword-reversed value
 *
 * Reference: Chapter A4.4.8 Miscellaneous data-processing instructions (page A4-113)
 *   - REV16 reverses the byte order in each 16-bit halfword
 */
static inline uint32_t armv7m_rev16(uint32_t value) {
    uint32_t result;
    __asm__ volatile (
        "rev16 %0, %1"
        : "=r" (result)
        : "r" (value)
    );
    return result;
}

/**
 * @brief Byte-Reverse Signed Halfword (REVSH)
 * @param value Input value
 * @return Sign-extended byte-reversed halfword
 *
 * Reference: Chapter A4.4.8 Miscellaneous data-processing instructions (page A4-113)
 *   - REVSH reverses the byte order in the lower 16 bits and sign-extends
 */
static inline int32_t armv7m_revsh(int16_t value) {
    int32_t result;
    __asm__ volatile (
        "revsh %0, %1"
        : "=r" (result)
        : "r" (value)
    );
    return result;
}

/**
 * @brief Signed Saturate (SSAT)
 * @param value Value to saturate
 * @param sat Bit position for saturation (1-32)
 * @return Saturated value
 *
 * Reference: Chapter A4.4.4 Saturating instructions (page A4-110)
 *   - SSAT saturates a signed value to a specified bit width
 *   - Sets Q flag if saturation occurs
 */
static inline int32_t armv7m_ssat(int32_t value, uint8_t sat) {
    int32_t result;
    __asm__ volatile (
        "ssat %0, %1, %2"
        : "=r" (result)
        : "I" (sat), "r" (value)
    );
    return result;
}

/**
 * @brief Unsigned Saturate (USAT)
 * @param value Value to saturate
 * @param sat Bit position for saturation (0-31)
 * @return Saturated value
 *
 * Reference: Chapter A4.4.4 Saturating instructions (page A4-110)
 *   - USAT saturates a signed value to an unsigned range
 *   - Sets Q flag if saturation occurs
 */
static inline uint32_t armv7m_usat(int32_t value, uint8_t sat) {
    uint32_t result;
    __asm__ volatile (
        "usat %0, %1, %2"
        : "=r" (result)
        : "I" (sat), "r" (value)
    );
    return result;
}

/**
 * @brief Signed Divide (SDIV)
 * @param dividend Dividend
 * @param divisor Divisor
 * @return Quotient
 *
 * Reference: Chapter A4.4.6 Divide instructions (page A4-112)
 *   - SDIV performs signed integer division
 *   - Hardware implementation in Armv7-M
 */
static inline int32_t armv7m_sdiv(int32_t dividend, int32_t divisor) {
    int32_t result;
    __asm__ volatile (
        "sdiv %0, %1, %2"
        : "=r" (result)
        : "r" (dividend), "r" (divisor)
    );
    return result;
}

/**
 * @brief Unsigned Divide (UDIV)
 * @param dividend Dividend
 * @param divisor Divisor
 * @return Quotient
 *
 * Reference: Chapter A4.4.6 Divide instructions (page A4-112)
 *   - UDIV performs unsigned integer division
 *   - Hardware implementation in Armv7-M
 */
static inline uint32_t armv7m_udiv(uint32_t dividend, uint32_t divisor) {
    uint32_t result;
    __asm__ volatile (
        "udiv %0, %1, %2"
        : "=r" (result)
        : "r" (dividend), "r" (divisor)
    );
    return result;
}

/*
 * ============================================================================
 * Exclusive Access Instructions
 * 独占访问指令
 * ============================================================================
 */

/**
 * @brief Load Exclusive word
 *
 * Reference: Chapter A3.4 Synchronization and semaphores (page A3-70)
 *   - A3.4.1 Exclusive access instructions and Non-shareable memory regions
 *   - LDREX loads value from memory and tags address for exclusive access
 *   - Local monitor transitions to Exclusive Access state
 *   - Used for non-blocking shared memory synchronization primitives
 *   - Must be paired with corresponding STREX instruction
 *   - Reference: Chapter A3.4.5 Load-Exclusive and Store-Exclusive usage restrictions
 *     * Keep LDREX and STREX within 128 bytes for best performance
 */
static inline uint32_t __LDREXW(volatile uint32_t *addr) {
    uint32_t result;
    __asm__ volatile ("ldrex %0, [%1]" : "=r" (result) : "r" (addr) : "memory");
    return result;
}

/**
 * @brief Store Exclusive word
 *
 * Reference: Chapter A3.4 Synchronization and semaphores (page A3-70)
 *   - A3.4.1 Exclusive access instructions and Non-shareable memory regions
 *   - STREX performs conditional store to memory
 *   - Returns status value: 0 = success, 1 = failure
 *   - Store succeeds only if local monitor is in Exclusive Access state
 *   - Local monitor transitions to Open Access state after STREX
 *   - Used with LDREX for atomic read-modify-write operations
 */
static inline uint32_t __STREXW(uint32_t value, volatile uint32_t *addr) {
    uint32_t result;
    __asm__ volatile ("strex %0, %2, [%1]" : "=&r" (result) : "r" (addr), "r" (value) : "memory");
    return result;
}

/**
 * @brief Load Exclusive halfword
 *
 * Reference: Chapter A3.4 Synchronization and semaphores (page A3-70)
 *   - A3.4.1 Exclusive access instructions and Non-shareable memory regions
 *   - LDREXH loads halfword from memory and tags address for exclusive access
 *   - Address must be halfword-aligned
 *   - Returns zero-extended value
 *   - Used for atomic 16-bit operations
 */
static inline uint16_t __LDREXH(volatile uint16_t *addr) {
    uint16_t result;
    __asm__ volatile ("ldrexh %0, [%1]" : "=r" (result) : "r" (addr) : "memory");
    return result;
}

/**
 * @brief Store Exclusive halfword
 *
 * Reference: Chapter A3.4 Synchronization and semaphores (page A3-70)
 *   - A3.4.1 Exclusive access instructions and Non-shareable memory regions
 *   - STREXH performs conditional store of halfword to memory
 *   - Returns status value: 0 = success, 1 = failure
 *   - Address must be halfword-aligned
 *   - Used with LDREXH for atomic 16-bit read-modify-write operations
 */
static inline uint32_t __STREXH(uint16_t value, volatile uint16_t *addr) {
    uint32_t result;
    __asm__ volatile ("strexh %0, %2, [%1]" : "=&r" (result) : "r" (addr), "r" (value) : "memory");
    return result;
}

/**
 * @brief Load Exclusive byte
 *
 * Reference: Chapter A3.4 Synchronization and semaphores (page A3-70)
 *   - A3.4.1 Exclusive access instructions and Non-shareable memory regions
 *   - LDREXB loads byte from memory and tags address for exclusive access
 *   - Returns zero-extended value
 *   - Used for atomic 8-bit operations
 */
static inline uint8_t __LDREXB(volatile uint8_t *addr) {
    uint8_t result;
    __asm__ volatile ("ldrexb %0, [%1]" : "=r" (result) : "r" (addr) : "memory");
    return result;
}

/**
 * @brief Store Exclusive byte
 *
 * Reference: Chapter A3.4 Synchronization and semaphores (page A3-70)
 *   - A3.4.1 Exclusive access instructions and Non-shareable memory regions
 *   - STREXB performs conditional store of byte to memory
 *   - Returns status value: 0 = success, 1 = failure
 *   - Used with LDREXB for atomic 8-bit read-modify-write operations
 */
static inline uint32_t __STREXB(uint8_t value, volatile uint8_t *addr) {
    uint32_t result;
    __asm__ volatile ("strexb %0, %2, [%1]" : "=&r" (result) : "r" (addr), "r" (value) : "memory");
    return result;
}

/**
 * @brief Clear Exclusive
 *
 * Reference: Chapter A3.4 Synchronization and semaphores (page A3-70)
 *   - A3.4.4 Context switch support
 *   - CLREX clears the local monitor to Open Access state
 *   - Automatically executed on exception entry/exit
 *   - Used to force clear exclusive monitor after context switch
 *   - Ensures subsequent STREX will fail (return 1)
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

/*
 * ============================================================================
 * Instruction Set Function Declarations (A4-A5)
 * 指令集函数声明 (A4-A5)
 * ============================================================================
 */

/**
 * @brief Decode 16-bit Thumb instruction opcode
 * @param hw Halfword instruction
 * @return Instruction class
 *
 * Reference: Chapter A5.2 16-bit Thumb instruction encoding (page A5-129)
 */
armv7m_instr_class_t armv7m_decode_16bit(uint16_t hw);

/**
 * @brief Get instruction size
 * @param addr Instruction address (must be halfword-aligned)
 * @return Instruction size in bytes (2 or 4)
 *
 * Reference: Chapter A5.1 Thumb instruction set encoding (page A5-126)
 */
uint8_t armv7m_get_instruction_size(uint32_t addr);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_CORE_H__ */
