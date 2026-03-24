/*
 * ARM Architecture - ARMv7-M Instruction Details
 *
 * ============================================================================
 * File: armv7-m_instr.h
 * Description: ARMv7-M instruction details and encoding information
 * 描述: ARMv7-M 指令详情和编码信息
 *
 * This file provides detailed information about Armv7-M Thumb instructions
 * as described in Chapter A7 of the Architecture Reference Manual.
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter A7: Instruction Details
 *     * A7.1 Format of instruction descriptions (page A7-172)
 *       - Instruction section title, introduction, encodings
 *       - Assembler syntax, pseudocode, exception information
 *     * A7.2 Standard assembler syntax fields (page A7-177)
 *       - <c> condition field (default AL - always)
 *       - <q> qualifier field (.N narrow, .W wide)
 *     * A7.3 Conditional execution (page A7-178)
 *       - Table A7-1 Condition codes
 *         * EQ, NE, CS/HS, CC/LO, MI, PL, VS, VC
 *         * HI, LS, GE, LT, GT, LE, AL
 *       - Condition flags: N (Negative), Z (Zero), C (Carry), V (Overflow)
 *       - A7.3.3 ITSTATE (page A7-179)
 *         * IT[7:5] - Base condition for IT block
 *         * IT[4:0] - Size of IT block and condition bits
 *         * Table A7-2 Effect of IT Execution state bits
 *     * A7.4 Shifts applied to a register (page A7-182)
 *       - LSL (Logical Shift Left)
 *       - LSR (Logical Shift Right)
 *       - ASR (Arithmetic Shift Right)
 *       - ROR (Rotate Right)
 *       - RRX (Rotate Right with Extend)
 *     * A7.5 Memory accesses (page A7-184)
 *       - Alignment requirements
 *       - Endianness
 *       - Memory attributes
 *     * A7.6 Hint instructions (page A7-185)
 *       - NOP - No Operation
 *       - YIELD - Yield hint
 *       - WFE - Wait For Event
 *       - WFI - Wait For Interrupt
 *       - SEV - Send Event
 *     * A7.7 Alphabetical list of Armv7-M Thumb instructions (page A7-186)
 *       - Complete list of all instructions with detailed descriptions
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_INSTR_H__
#define __ARCH_ARM_V7M_INSTR_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * Instruction Encoding Information (A7.1)
 * 指令编码信息
 * ============================================================================
 */

/**
 * @brief Instruction encoding types
 * Reference: Chapter A7.1.3 Instruction encodings (page A7-172)
 */
typedef enum {
    ARMV7M_ENC_T1 = 1,  /* T1 encoding - typically 16-bit */
    ARMV7M_ENC_T2 = 2,  /* T2 encoding - typically 16-bit or 32-bit */
    ARMV7M_ENC_T3 = 3,  /* T3 encoding - typically 32-bit */
    ARMV7M_ENC_T4 = 4,  /* T4 encoding - typically 32-bit */
} armv7m_encoding_t;

/**
 * @brief Architecture variants for instructions
 * Reference: Chapter A7.1.3 Instruction encodings (page A7-172)
 */
typedef enum {
    ARMV7M_ARCH_ALL = 0,        /* All versions of Thumb instruction set */
    ARMV7M_ARCH_V5T = 1,        /* Armv5T* - Thumb instruction support */
    ARMV7M_ARCH_V6M = 2,        /* Armv6-M - Thumb-only microcontroller */
    ARMV7M_ARCH_V7M = 3,        /* Armv7-M - Thumb-2 technology */
    ARMV7M_ARCH_V7EM = 4,       /* Armv7E-M - with DSP extension */
    ARMV7M_ARCH_V8M = 5,        /* Armv8-M */
} armv7m_arch_variant_t;

/*
 * ============================================================================
 * Standard Assembler Syntax Fields (A7.2)
 * 标准汇编语法字段
 * ============================================================================
 */

/**
 * @brief Assembler qualifiers
 * Reference: Chapter A7.2 Standard assembler syntax fields (page A7-177)
 */
typedef enum {
    ARMV7M_QUAL_NONE = 0,   /* No qualifier - assembler selects encoding */
    ARMV7M_QUAL_N = 1,      /* .N - Narrow, must use 16-bit encoding */
    ARMV7M_QUAL_W = 2,      /* .W - Wide, must use 32-bit encoding */
} armv7m_qualifier_t;

/**
 * @brief Shift types for register operands
 * Reference: Chapter A7.4 Shifts applied to a register (page A7-182)
 */
typedef enum {
    ARMV7M_SHIFT_LSL = 0,   /* Logical Shift Left */
    ARMV7M_SHIFT_LSR = 1,   /* Logical Shift Right */
    ARMV7M_SHIFT_ASR = 2,   /* Arithmetic Shift Right */
    ARMV7M_SHIFT_ROR = 3,   /* Rotate Right */
    ARMV7M_SHIFT_RRX = 4,   /* Rotate Right with Extend */
} armv7m_shift_type_t;

/**
 * @brief Shift operation structure
 * Reference: Chapter A7.4 Shifts applied to a register (page A7-182)
 */
typedef struct {
    armv7m_shift_type_t type;   /* Shift type */
    uint8_t amount;             /* Shift amount (0-31 for LSL/LSR/ASR/ROR) */
} armv7m_shift_t;

/*
 * ============================================================================
 * Memory Access Information (A7.5)
 * 内存访问信息
 * ============================================================================
 */

/**
 * @brief Memory access types
 * Reference: Chapter A7.5 Memory accesses (page A7-184)
 */
typedef enum {
    ARMV7M_MEM_ACCESS_NORMAL = 0,       /* Normal memory access */
    ARMV7M_MEM_ACCESS_UNPRIVILEGED = 1, /* Unprivileged memory access (LDRT/STRT) */
    ARMV7M_MEM_ACCESS_EXCLUSIVE = 2,    /* Exclusive access (LDREX/STREX) */
} armv7m_mem_access_type_t;

/**
 * @brief Memory access attributes
 * Reference: Chapter A7.5 Memory accesses (page A7-184)
 */
typedef struct {
    armv7m_mem_access_type_t type;  /* Access type */
    uint8_t size;                   /* Access size in bytes (1, 2, or 4) */
    uint8_t align;                  /* Alignment requirement */
} armv7m_mem_access_t;

/*
 * ============================================================================
 * Hint Instructions (A7.6)
 * 提示指令
 * ============================================================================
 */

/**
 * @brief Hint instruction types
 * Reference: Chapter A7.6 Hint instructions (page A7-185)
 */
typedef enum {
    ARMV7M_HINT_NOP = 0,    /* NOP - No Operation */
    ARMV7M_HINT_YIELD = 1,  /* YIELD - Yield hint */
    ARMV7M_HINT_WFE = 2,    /* WFE - Wait For Event */
    ARMV7M_HINT_WFI = 3,    /* WFI - Wait For Interrupt */
    ARMV7M_HINT_SEV = 4,    /* SEV - Send Event */
} armv7m_hint_t;

/**
 * @brief Execute hint instruction
 * @param hint Hint type
 *
 * Reference: Chapter A7.6 Hint instructions (page A7-185)
 */
static inline void armv7m_hint(armv7m_hint_t hint) {
    switch (hint) {
        case ARMV7M_HINT_NOP:
            __asm__ volatile ("nop");
            break;
        case ARMV7M_HINT_YIELD:
            __asm__ volatile ("yield");
            break;
        case ARMV7M_HINT_WFE:
            __asm__ volatile ("wfe");
            break;
        case ARMV7M_HINT_WFI:
            __asm__ volatile ("wfi");
            break;
        case ARMV7M_HINT_SEV:
            __asm__ volatile ("sev");
            break;
        default:
            break;
    }
}

/*
 * ============================================================================
 * Shift Operations (A7.4)
 * 移位操作
 * ============================================================================
 */

/**
 * @brief Perform Logical Shift Left
 * @param value Value to shift
 * @param amount Shift amount (0-31)
 * @return Shifted result
 *
 * Reference: Chapter A7.4 Shifts applied to a register (page A7-182)
 */
static inline uint32_t armv7m_shift_lsl(uint32_t value, uint8_t amount) {
    if (amount == 0) return value;
    if (amount >= 32) return 0;
    return value << amount;
}

/**
 * @brief Perform Logical Shift Right
 * @param value Value to shift
 * @param amount Shift amount (0-31)
 * @return Shifted result
 *
 * Reference: Chapter A7.4 Shifts applied to a register (page A7-182)
 */
static inline uint32_t armv7m_shift_lsr(uint32_t value, uint8_t amount) {
    if (amount == 0) return value;
    if (amount >= 32) return 0;
    return value >> amount;
}

/**
 * @brief Perform Arithmetic Shift Right
 * @param value Value to shift
 * @param amount Shift amount (0-31)
 * @return Shifted result
 *
 * Reference: Chapter A7.4 Shifts applied to a register (page A7-182)
 */
static inline int32_t armv7m_shift_asr(int32_t value, uint8_t amount) {
    if (amount == 0) return value;
    if (amount >= 32) return (value < 0) ? -1 : 0;
    return value >> amount;
}

/**
 * @brief Perform Rotate Right
 * @param value Value to rotate
 * @param amount Rotate amount (0-31)
 * @return Rotated result
 *
 * Reference: Chapter A7.4 Shifts applied to a register (page A7-182)
 */
static inline uint32_t armv7m_shift_ror(uint32_t value, uint8_t amount) {
    if (amount == 0) return value;
    amount &= 0x1F;
    return (value >> amount) | (value << (32 - amount));
}

/**
 * @brief Perform Rotate Right with Extend
 * @param value Value to rotate
 * @param carry_in Carry input
 * @param carry_out Pointer to store carry output
 * @return Rotated result
 *
 * Reference: Chapter A7.4 Shifts applied to a register (page A7-182)
 */
static inline uint32_t armv7m_shift_rrx(uint32_t value, uint8_t carry_in, uint8_t *carry_out) {
    uint32_t result = ((uint32_t)carry_in << 31) | (value >> 1);
    if (carry_out) {
        *carry_out = value & 0x01;
    }
    return result;
}

/*
 * ============================================================================
 * Instruction Classification (A7.7)
 * 指令分类
 * ============================================================================
 */

/**
 * @brief Major instruction categories
 * Reference: Chapter A7.7 Alphabetical list of Armv7-M Thumb instructions
 */
typedef enum {
    ARMV7M_INSTR_CAT_BRANCH = 0,        /* Branch instructions */
    ARMV7M_INSTR_CAT_DATA_PROC,         /* Data processing instructions */
    ARMV7M_INSTR_CAT_LOAD_STORE,        /* Load and store instructions */
    ARMV7M_INSTR_CAT_LOAD_STORE_MULTI,  /* Load/Store Multiple */
    ARMV7M_INSTR_CAT_STATUS,            /* Status register access */
    ARMV7M_INSTR_CAT_EXCEPTION,         /* Exception generating */
    ARMV7M_INSTR_CAT_HINT,              /* Hint instructions */
    ARMV7M_INSTR_CAT_BARRIER,           /* Barrier instructions */
    ARMV7M_INSTR_CAT_COPROC,            /* Coprocessor instructions */
    ARMV7M_INSTR_CAT_FLOAT,             /* Floating-point instructions */
    ARMV7M_INSTR_CAT_DSP,               /* DSP instructions */
    ARMV7M_INSTR_CAT_MISC,              /* Miscellaneous */
} armv7m_instr_category_t;

/**
 * @brief Instruction information structure
 * Reference: Chapter A7.1 Format of instruction descriptions (page A7-172)
 */
typedef struct {
    const char *mnemonic;               /* Instruction mnemonic */
    armv7m_instr_category_t category;   /* Instruction category */
    armv7m_arch_variant_t arch;         /* Architecture variant */
    uint8_t encoding_count;             /* Number of encodings */
    armv7m_encoding_t encodings[4];     /* Available encodings */
    const char *description;            /* Brief description */
} armv7m_instr_info_t;

/*
 * ============================================================================
 * Exception Information (A7.1.6)
 * 异常信息
 * ============================================================================
 */

/**
 * @brief Exception types that can be caused by instructions
 * Reference: Chapter A7.1.6 Exception information (page A7-175)
 */
typedef enum {
    ARMV7M_EXCEPT_NONE = 0,         /* No exception */
    ARMV7M_EXCEPT_MEMMANAGE = 1,    /* MemManage fault */
    ARMV7M_EXCEPT_BUSFAULT = 2,     /* BusFault */
    ARMV7M_EXCEPT_USAGEFAULT = 3,   /* UsageFault */
    ARMV7M_EXCEPT_SVCALL = 4,       /* SVCall */
    ARMV7M_EXCEPT_DEBUGMON = 5,     /* DebugMonitor */
    ARMV7M_EXCEPT_HARD = 6,         /* HardFault (escalation) */
} armv7m_exception_t;

/**
 * @brief Exception information structure
 * Reference: Chapter A7.1.6 Exception information (page A7-175)
 */
typedef struct {
    armv7m_exception_t type;    /* Exception type */
    const char *description;    /* Exception description */
} armv7m_except_info_t;

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_INSTR_H__ */
