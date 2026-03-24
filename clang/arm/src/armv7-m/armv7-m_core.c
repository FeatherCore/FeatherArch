/*
 * ARM Architecture - ARMv7-M Core Implementation
 *
 * ============================================================================
 * File: armv7-m_core.c
 * Description: ARMv7-M core functions implementation
 * 描述: ARMv7-M 核心函数实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter A1: Introduction
 *     * A1.2 The Armv7-M architecture profile (page A1-21)
 *   - Chapter A2: Application Level Programmers' Model
 *     * A2.1 About the application level programmers' model (page A2-24)
 *     * A2.3 Registers and Execution state (page A2-30)
 *       - A2.3.1 Arm core registers
 *       - A2.3.2 The Application Program Status Register (APSR)
 *       - A2.3.4 Privileged execution
 *     * A2.4 Exceptions, faults and interrupts (page A2-33)
 *   - Chapter A3: Arm Architecture Memory Model
 *     * A3.1 Address space (page A3-64)
 *     * A3.7 Memory access order (page A3-89)
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
 *       - Saturating instructions (SSAT, USAT)
 *       - Divide instructions (SDIV, UDIV)
 *       - Bit field instructions (BFC, BFI, SBFX, UBFX)
 *       - Reverse and bit reverse instructions (REV, REV16, REVSH, RBIT)
 *       - Count Leading Zeros (CLZ)
 *     * A4.5 Status register access instructions (page A4-114)
 *     * A4.6 Load and store instructions (page A4-115)
 *     * A4.7 Load Multiple and Store Multiple (page A4-117)
 *     * A4.8 Miscellaneous instructions (page A4-118)
 *       - NOP, YIELD, WFI, WFE, SEV, SVC, BKPT
 *       - DMB, DSB, ISB, CLREX
 *     * A4.9 Exception-generating instructions (page A4-119)
 *       - SVC, BKPT
 *   - Chapter A5: The Thumb Instruction Set Encoding
 *     * A5.1 Thumb instruction set encoding (page A5-126)
 *       - 16-bit vs 32-bit instruction identification
 *       - bits[15:11] = 0b11101/11110/11111 indicate 32-bit
 *     * A5.2 16-bit Thumb instruction encoding (page A5-129)
 *     * A5.3 32-bit Thumb instruction encoding (page A5-137)
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
 *     * B1.4 Registers (page B1-516)
 *       - B1.4.1 The Arm core registers (page B1-516)
 *         * SP_main (MSP) and SP_process (PSP)
 *       - B1.4.2 The special-purpose Program Status Registers, xPSR (page B1-516)
 *         * APSR, IPSR, EPSR
 *     * B1.5 Armv7-M exception model (page B1-519)
 *       - Exception number definition (Table B1-4)
 *       - Exception return (page B1-524)
 *       - Exception entry, exit, and priority (page B1-525)
 *       - Priority grouping (page B1-527)
 *   - Chapter B2: System Memory Model
 *     * B2.1 About the system memory model (page B2-570)
 *     * B2.2 Caches and branch predictors (page B2-571)
 *       - B2.2.1 Cache identification (page B2-571)
 *       - B2.2.2 Cache enabling and disabling (page B2-572)
 *       - B2.2.3 Cache behavior (page B2-572)
 *   - Chapter B3: System Address Map
 *     * B3.1 The system address map (page B3-592)
 *       - Table B3-1 Armv7-M address map
 *       - Code, SRAM, Peripheral, RAM, Device regions
 *     * B3.2 System Control Space (SCS) (page B3-595)
 *       - Table B3-3 SCS address space regions
 *       - Table B3-4 Summary of SCB registers
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
 *
 * Reference: Chapter A2.3.4 Privileged execution (page A2-32)
 *   - Thread mode can execute in privileged or unprivileged manner
 *   - nPRIV bit controls privilege level in Thread mode
 *   - When nPRIV=1, code runs unprivileged (limited access to system resources)
 *   - Used by OS to protect system from malfunctioning applications
 *   - Reference: Chapter A2.1 About the application level programmers' model (page A2-24)
 *     * Application usually runs unprivileged for protection
 *
 * Note: ISB required after changing CONTROL register
 * Reference: Chapter A3.7 Memory access order (page A3-89)
 */
void armv7m_enter_non_privileged(void) {
    uint32_t control = __get_CONTROL();
    control |= CONTROL_nPRIV;
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Clear nPRIV bit (enter privileged mode)
 *
 * Reference: Chapter A2.3.4 Privileged execution (page A2-32)
 *   - Thread mode can execute in privileged or unprivileged manner
 *   - nPRIV bit controls privilege level in Thread mode
 *   - When nPRIV=0, code runs privileged (full access to system resources)
 *   - Privileged execution required to manage system resources
 *   - All exceptions execute as privileged code in Handler mode
 *
 * Note: ISB required after changing CONTROL register
 * Reference: Chapter A3.7 Memory access order (page A3-89)
 */
void armv7m_enter_privileged(void) {
    uint32_t control = __get_CONTROL();
    control &= ~CONTROL_nPRIV;
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Select PSP as current stack pointer
 *
 * Reference: Chapter A2.3.1 Arm core registers (page A2-30)
 *   - SP (R13) is the Stack Pointer
 *   - Two stack pointers: MSP (Main) and PSP (Process)
 *   - CONTROL.SPSEL bit selects which stack pointer to use
 *   - SPSEL=1: Use PSP (Process Stack Pointer)
 *   - Used for separating privileged and unprivileged stack usage
 *   - Reference: Chapter A2.3.4 Privileged execution (page A2-32)
 *     * OS typically uses MSP for privileged code, PSP for applications
 *
 * Note: ISB required after changing CONTROL register
 * Reference: Chapter A3.7 Memory access order (page A3-89)
 */
void armv7m_select_psp(void) {
    uint32_t control = __get_CONTROL();
    control |= CONTROL_SPSEL;
    __set_CONTROL(control);
    __ISB();
}

/**
 * @brief Select MSP as current stack pointer
 *
 * Reference: Chapter A2.3.1 Arm core registers (page A2-30)
 *   - SP (R13) is the Stack Pointer
 *   - Two stack pointers: MSP (Main) and PSP (Process)
 *   - CONTROL.SPSEL bit selects which stack pointer to use
 *   - SPSEL=0: Use MSP (Main Stack Pointer)
 *   - MSP is the default stack pointer after reset
 *   - Used for exception handling and privileged code
 *   - Reference: Chapter A2.3.4 Privileged execution (page A2-32)
 *     * All exceptions execute using MSP in Handler mode
 *
 * Note: ISB required after changing CONTROL register
 * Reference: Chapter A3.7 Memory access order (page A3-89)
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
 *
 * Reference: Chapter A2.3.2 The Application Program Status Register (APSR) (page A2-31)
 *   - N (Negative) flag, bit[31]
 *   - Set to bit[31] of the result of the instruction
 *   - If result is regarded as two's complement signed integer:
 *     * N == 1 if result is negative
 *     * N == 0 if result is positive or zero
 *   - Used for conditional execution and signed arithmetic
 */
uint32_t armv7m_get_flag_n(void) {
    return (__get_APSR() & xPSR_N) ? 1U : 0U;
}

/**
 * @brief Get Z flag (Zero)
 *
 * Reference: Chapter A2.3.2 The Application Program Status Register (APSR) (page A2-31)
 *   - Z (Zero) flag, bit[30]
 *   - Set to 1 if the result of the instruction is zero
 *   - Set to 0 otherwise
 *   - A result of zero often indicates an equal result from a comparison
 *   - Used for conditional execution and comparison operations
 */
uint32_t armv7m_get_flag_z(void) {
    return (__get_APSR() & xPSR_Z) ? 1U : 0U;
}

/**
 * @brief Get C flag (Carry)
 *
 * Reference: Chapter A2.3.2 The Application Program Status Register (APSR) (page A2-31)
 *   - C (Carry) flag, bit[29]
 *   - Set to 1 if the instruction results in a carry condition
 *   - Example: unsigned overflow on an addition
 *   - Reference: Chapter A2.2 Arm processor data types and arithmetic (page A2-25)
 *     * Used in multi-word arithmetic and shift operations
 *   - Used for conditional execution and unsigned arithmetic
 */
uint32_t armv7m_get_flag_c(void) {
    return (__get_APSR() & xPSR_C) ? 1U : 0U;
}

/**
 * @brief Get V flag (Overflow)
 *
 * Reference: Chapter A2.3.2 The Application Program Status Register (APSR) (page A2-31)
 *   - V (Overflow) flag, bit[28]
 *   - Set to 1 if the instruction results in an overflow condition
 *   - Example: signed overflow on an addition
 *   - Reference: Chapter A2.2 Arm processor data types and arithmetic (page A2-25)
 *     * Used for signed arithmetic overflow detection
 *   - Used for conditional execution and signed arithmetic
 */
uint32_t armv7m_get_flag_v(void) {
    return (__get_APSR() & xPSR_V) ? 1U : 0U;
}

/**
 * @brief Get Q flag (Saturation)
 *
 * Reference: Chapter A2.3.2 The Application Program Status Register (APSR) (page A2-31)
 *   - Q (Saturation) flag, bit[27]
 *   - Set to 1 if SSAT or USAT instruction changes input value for signed/unsigned range
 *   - In processors with DSP extension, set on some multiply overflows
 *   - Reference: Chapter A1.3 Architecture extensions (page A1-22)
 *     * DSP extension adds saturating and SIMD instructions
 *   - Used for saturation arithmetic (common in signal processing)
 *   - Sticky flag - remains set until explicitly cleared
 */
uint32_t armv7m_get_flag_q(void) {
    return (__get_APSR() & xPSR_Q) ? 1U : 0U;
}

/**
 * @brief Clear Q flag
 *
 * Reference: Chapter A2.3.2 The Application Program Status Register (APSR) (page A2-31)
 *   - Q flag is sticky - remains set until explicitly cleared
 *   - Cleared by writing to APSR
 *   - Reference: Chapter A2.2 Arm processor data types and arithmetic (page A2-25)
 *     * Pseudocode details of saturation
 *   - Must be cleared before starting new saturation operations
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
 *
 * Reference: Chapter A2.4 Exceptions, faults and interrupts (page A2-33)
 *   - A2.4.1 System-related events
 *   - PRIMASK controls interrupt masking
 *   - PRIMASK = 0: Interrupts enabled (configurable priority)
 *   - PRIMASK = 1: All configurable priority interrupts disabled
 *   - Does not affect NMI, HardFault, or reset
 *   - Reference: Chapter A2.3.4 Privileged execution (page A2-32)
 *     * Used for critical section protection
 */
void armv7m_enable_interrupts(void) {
    __set_PRIMASK(0);
}

/**
 * @brief Disable interrupts (set PRIMASK)
 *
 * Reference: Chapter A2.4 Exceptions, faults and interrupts (page A2-33)
 *   - A2.4.1 System-related events
 *   - PRIMASK controls interrupt masking
 *   - PRIMASK = 1: All configurable priority interrupts disabled
 *   - Used for critical sections where interrupts must not occur
 *   - Does not affect NMI, HardFault, or reset
 *   - Automatically set on exception entry (if not tail-chained)
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
 *
 * Reference: Chapter A2.4 Exceptions, faults and interrupts (page A2-33)
 *   - IPSR contains the current exception number
 *   - 0 = Thread mode (no exception active)
 *   - 1 = Reset
 *   - 2 = NMI
 *   - 3 = HardFault
 *   - 4-10 = Reserved
 *   - 11 = SVCall
 *   - 12-13 = Reserved
 *   - 14 = PendSV
 *   - 15 = SysTick
 *   - 16+ = External interrupts (IRQ0+)
 *   - Reference: Chapter A2.3.2 The Application Program Status Register (APSR) (page A2-31)
 *     * IPSR is part of xPSR (bits [8:0])
 */
uint32_t armv7m_get_exception_number(void) {
    return __get_IPSR();
}

/*
 * ============================================================================
 * Instruction Set Support (Chapter A4-A5)
 * 指令集支持 (A4-A5章节)
 * ============================================================================
 */

/**
 * @brief Check if instruction should execute based on condition flags
 * @param cond Condition code (0-15)
 * @param apsr APSR register value
 * @return 1 if condition passes, 0 otherwise
 *
 * Reference: Chapter A4.1.2 Conditional execution (page A4-103)
 *   - Condition checked against N, Z, C, V flags in APSR
 *   - Table A4-1 Condition codes
 *
 * Condition codes:
 *   0 (EQ): Z == 1         Equal
 *   1 (NE): Z == 0         Not equal
 *   2 (CS): C == 1         Carry set
 *   3 (CC): C == 0         Carry clear
 *   4 (MI): N == 1         Negative
 *   5 (PL): N == 0         Positive or zero
 *   6 (VS): V == 1         Overflow
 *   7 (VC): V == 0         No overflow
 *   8 (HI): C == 1 && Z == 0       Higher (unsigned)
 *   9 (LS): C == 0 || Z == 1       Lower or same (unsigned)
 *  10 (GE): N == V                 Greater or equal (signed)
 *  11 (LT): N != V                 Less than (signed)
 *  12 (GT): Z == 0 && N == V       Greater than (signed)
 *  13 (LE): Z == 1 || N != V       Less or equal (signed)
 *  14 (AL): Always                 Always (unconditional)
 *  15: Reserved
 */
int armv7m_condition_passed(uint8_t cond, uint32_t apsr) {
    uint32_t n = (apsr & xPSR_N) ? 1 : 0;
    uint32_t z = (apsr & xPSR_Z) ? 1 : 0;
    uint32_t c = (apsr & xPSR_C) ? 1 : 0;
    uint32_t v = (apsr & xPSR_V) ? 1 : 0;

    switch (cond & 0x0F) {
        case 0x0: return z;                    /* EQ */
        case 0x1: return !z;                   /* NE */
        case 0x2: return c;                    /* CS */
        case 0x3: return !c;                   /* CC */
        case 0x4: return n;                    /* MI */
        case 0x5: return !n;                   /* PL */
        case 0x6: return v;                    /* VS */
        case 0x7: return !v;                   /* VC */
        case 0x8: return c && !z;              /* HI */
        case 0x9: return !c || z;              /* LS */
        case 0xA: return n == v;               /* GE */
        case 0xB: return n != v;               /* LT */
        case 0xC: return !z && (n == v);       /* GT */
        case 0xD: return z || (n != v);        /* LE */
        case 0xE: return 1;                    /* AL - Always */
        case 0xF: return 1;                    /* Reserved, behaves as always */
        default:  return 1;
    }
}

/**
 * @brief Decode 16-bit Thumb instruction opcode
 * @param hw Halfword instruction
 * @return Instruction class
 *
 * Reference: Chapter A5.2 16-bit Thumb instruction encoding (page A5-129)
 *   - Table A5-1 16-bit Thumb instruction encoding
 */
armv7m_instr_class_t armv7m_decode_16bit(uint16_t hw) {
    uint8_t opcode = (hw >> 10) & 0x3F;

    if ((opcode & 0x30) == 0x00) {
        return ARMV7M_INSTR_SHIFT_ADD_SUB_MOV_CMP;
    } else if (opcode == 0x10) {
        return ARMV7M_INSTR_DATA_PROC;
    } else if (opcode == 0x11) {
        return ARMV7M_INSTR_SPECIAL_DATA_BRANCH;
    } else if ((opcode & 0x3E) == 0x24) {
        return ARMV7M_INSTR_LDR_LITERAL;
    } else if ((opcode & 0x38) == 0x28 || (opcode & 0x38) == 0x30 ||
               (opcode & 0x38) == 0x38) {
        return ARMV7M_INSTR_LOAD_STORE_SINGLE;
    } else if ((opcode & 0x3E) == 0x28) {
        return ARMV7M_INSTR_ADR_PC_REL;
    } else if ((opcode & 0x3E) == 0x2A) {
        return ARMV7M_INSTR_ADR_SP_REL;
    } else if ((opcode & 0x3C) == 0x2C) {
        return ARMV7M_INSTR_MISC_16BIT;
    } else if ((opcode & 0x3E) == 0x30) {
        return ARMV7M_INSTR_STM;
    } else if ((opcode & 0x3E) == 0x32) {
        return ARMV7M_INSTR_LDM;
    } else if ((opcode & 0x3C) == 0x34) {
        return ARMV7M_INSTR_COND_BRANCH_SVC;
    } else if ((opcode & 0x3E) == 0x38) {
        return ARMV7M_INSTR_UNCOND_BRANCH;
    } else {
        return ARMV7M_INSTR_UNDEFINED;
    }
}

/**
 * @brief Get instruction size
 * @param addr Instruction address (must be halfword-aligned)
 * @return Instruction size in bytes (2 or 4)
 *
 * Reference: Chapter A5.1 Thumb instruction set encoding (page A5-126)
 *   - 32-bit instruction if bits[15:11] = 0b11101/11110/11111
 *   - Otherwise 16-bit instruction
 */
uint8_t armv7m_get_instruction_size(uint32_t addr) {
    uint16_t hw = *(volatile uint16_t *)addr;
    return armv7m_is_32bit_instruction(hw) ? 4 : 2;
}


