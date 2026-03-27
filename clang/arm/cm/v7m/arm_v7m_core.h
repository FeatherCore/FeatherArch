/*
 * arm_v7m_core.h
 * Armv7-M Core Register and System Control Definitions
 * Reference: ARMv7-M Architecture Reference Manual
 *   - Section B1.4: Registers
 *   - Section B5.2: System Instruction Descriptions
 *
 * This header provides:
 * 1. Core register bit definitions (APSR, IPSR, EPSR, CONTROL)
 * 2. Special-purpose register access functions (MRS/MSR instructions) - INLINE
 * 3. System control functions (CPS, barriers, power management) - INLINE
 * 4. Helper functions for privilege and stack management
 *
 * For instruction set operations, include arm_v7m_instr.h
 */

#ifndef ARM_V7M_CORE_H
#define ARM_V7M_CORE_H

#include <stdint.h>
#include "arm_v7m_instr.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Compiler Abstraction - Inline Definition
 * This library only supports Clang/LLVM compiler
 *============================================================================*/

#if defined(__clang__)
    #define ARM_V7M_CORE_INLINE static inline __attribute__((always_inline))
#else
    #error "This library requires Clang/LLVM compiler. Please use clang to compile this code."
#endif

/*============================================================================*
 * Core Register Type Definitions
 *============================================================================*/

typedef struct {
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r4;
    uint32_t r5;
    uint32_t r6;
    uint32_t r7;
    uint32_t r8;
    uint32_t r9;
    uint32_t r10;
    uint32_t r11;
    uint32_t r12;
    uint32_t sp;
    uint32_t lr;
    uint32_t pc;
    uint32_t xpsr;
} arm_v7m_core_regs_t;

/*============================================================================*
 * APSR Register Bit Definitions
 *============================================================================*/

#define ARM_V7M_APSR_N_Pos                 31U
#define ARM_V7M_APSR_N_Msk                 (1UL << ARM_V7M_APSR_N_Pos)

#define ARM_V7M_APSR_Z_Pos                 30U
#define ARM_V7M_APSR_Z_Msk                 (1UL << ARM_V7M_APSR_Z_Pos)

#define ARM_V7M_APSR_C_Pos                 29U
#define ARM_V7M_APSR_C_Msk                 (1UL << ARM_V7M_APSR_C_Pos)

#define ARM_V7M_APSR_V_Pos                 28U
#define ARM_V7M_APSR_V_Msk                 (1UL << ARM_V7M_APSR_V_Pos)

#define ARM_V7M_APSR_Q_Pos                 27U
#define ARM_V7M_APSR_Q_Msk                 (1UL << ARM_V7M_APSR_Q_Pos)

/* APSR GE bits (DSP Extension - Armv7E-M only) - Section B1.4.2 */
#define ARM_V7M_APSR_GE_Pos                16U
#define ARM_V7M_APSR_GE_Msk                (0xFUL << ARM_V7M_APSR_GE_Pos)

/*============================================================================*
 * IPSR Register Bit Definitions
 *============================================================================*/

#define ARM_V7M_IPSR_ISR_Pos                0U
#define ARM_V7M_IPSR_ISR_Msk               (0x1FFUL << ARM_V7M_IPSR_ISR_Pos)

/*============================================================================*
 * EPSR Register Bit Definitions
 *============================================================================*/

#define ARM_V7M_EPSR_ICI_IT_1_Pos          10U
#define ARM_V7M_EPSR_ICI_IT_1_Msk          (0x3FUL << ARM_V7M_EPSR_ICI_IT_1_Pos)

#define ARM_V7M_EPSR_T_Pos                 24U
#define ARM_V7M_EPSR_T_Msk                 (1UL << ARM_V7M_EPSR_T_Pos)

#define ARM_V7M_EPSR_ICI_IT_2_Pos          25U
#define ARM_V7M_EPSR_ICI_IT_2_Msk          (0x3UL << ARM_V7M_EPSR_ICI_IT_2_Pos)

/*============================================================================*
 * CONTROL Register Bit Definitions
 *============================================================================*/

#define ARM_V7M_CONTROL_nPRIV_Pos           0U
#define ARM_V7M_CONTROL_nPRIV_Msk          (1UL << ARM_V7M_CONTROL_nPRIV_Pos)

#define ARM_V7M_CONTROL_SPSEL_Pos           1U
#define ARM_V7M_CONTROL_SPSEL_Msk          (1UL << ARM_V7M_CONTROL_SPSEL_Pos)

#define ARM_V7M_CONTROL_FPCA_Pos            2U
#define ARM_V7M_CONTROL_FPCA_Msk           (1UL << ARM_V7M_CONTROL_FPCA_Pos)

/*============================================================================*
 * Special-Purpose Register Access Functions (INLINE)
 * Reference: Section B5.2 - MRS, MSR instructions
 *============================================================================*/

/* Main Stack Pointer (MSP) - SYSm = 8 */
ARM_V7M_CORE_INLINE uint32_t arm_v7m_get_msp(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, msp" : "=r" (result));
    return result;
}

ARM_V7M_CORE_INLINE void arm_v7m_set_msp(uint32_t value)
{
    __asm volatile ("MSR msp, %0" : : "r" (value));
}

/* Process Stack Pointer (PSP) - SYSm = 9 */
ARM_V7M_CORE_INLINE uint32_t arm_v7m_get_psp(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, psp" : "=r" (result));
    return result;
}

ARM_V7M_CORE_INLINE void arm_v7m_set_psp(uint32_t value)
{
    __asm volatile ("MSR psp, %0" : : "r" (value));
}

/* Priority Mask Register (PRIMASK) - SYSm = 16 */
ARM_V7M_CORE_INLINE uint32_t arm_v7m_get_primask(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, primask" : "=r" (result));
    return result;
}

ARM_V7M_CORE_INLINE void arm_v7m_set_primask(uint32_t value)
{
    __asm volatile ("MSR primask, %0" : : "r" (value));
}

/* Fault Mask Register (FAULTMASK) - SYSm = 19 */
ARM_V7M_CORE_INLINE uint32_t arm_v7m_get_faultmask(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, faultmask" : "=r" (result));
    return result;
}

ARM_V7M_CORE_INLINE void arm_v7m_set_faultmask(uint32_t value)
{
    __asm volatile ("MSR faultmask, %0" : : "r" (value));
}

/* Base Priority Register (BASEPRI) - SYSm = 17 */
ARM_V7M_CORE_INLINE uint32_t arm_v7m_get_basepri(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, basepri" : "=r" (result));
    return result;
}

ARM_V7M_CORE_INLINE void arm_v7m_set_basepri(uint32_t value)
{
    __asm volatile ("MSR basepri, %0" : : "r" (value));
}

/* Base Priority Max Register (BASEPRI_MAX) - SYSm = 18, Write only */
ARM_V7M_CORE_INLINE void arm_v7m_set_basepri_max(uint32_t value)
{
    __asm volatile ("MSR basepri_max, %0" : : "r" (value));
}

/* Control Register (CONTROL) - SYSm = 20 */
ARM_V7M_CORE_INLINE uint32_t arm_v7m_get_control(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, control" : "=r" (result));
    return result;
}

/* Note: set_control is NOT inline because it requires ISB after write */
void arm_v7m_set_control(uint32_t value);

/*============================================================================*
 * APSR/IPSR/EPSR/XPSR Register Access (INLINE)
 *============================================================================*/

/* Application Program Status Register (APSR) - SYSm = 0 */
ARM_V7M_CORE_INLINE uint32_t arm_v7m_get_apsr(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, apsr" : "=r" (result));
    return result;
}

ARM_V7M_CORE_INLINE void arm_v7m_set_apsr(uint32_t value)
{
    __asm volatile ("MSR apsr_nzcvq, %0" : : "r" (value));
}

ARM_V7M_CORE_INLINE void arm_v7m_set_apsr_nzcvq(uint32_t value)
{
    __asm volatile ("MSR apsr_nzcvq, %0" : : "r" (value));
}

/* Set APSR with _g qualifier (GE[3:0] bits, DSP Extension - Armv7E-M only) */
ARM_V7M_CORE_INLINE void arm_v7m_set_apsr_g(uint32_t value)
{
    __asm volatile ("MSR apsr_g, %0" : : "r" (value));
}

/* Set APSR with _nzcvqg qualifier (N, Z, C, V, Q, GE bits, DSP Extension) */
ARM_V7M_CORE_INLINE void arm_v7m_set_apsr_nzcvqg(uint32_t value)
{
    __asm volatile ("MSR apsr_nzcvqg, %0" : : "r" (value));
}

/* Interrupt Program Status Register (IPSR) - SYSm = 5, Read only */
ARM_V7M_CORE_INLINE uint32_t arm_v7m_get_ipsr(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, ipsr" : "=r" (result));
    return result;
}

/* Execution Program Status Register (EPSR) - SYSm = 6, Read only */
ARM_V7M_CORE_INLINE uint32_t arm_v7m_get_epsr(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, epsr" : "=r" (result));
    return result;
}

/* Composite XPSR Register - SYSm = 3 */
ARM_V7M_CORE_INLINE uint32_t arm_v7m_get_xpsr(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, xpsr" : "=r" (result));
    return result;
}

ARM_V7M_CORE_INLINE void arm_v7m_set_xpsr(uint32_t value)
{
    __asm volatile ("MSR apsr_nzcvq, %0" : : "r" (value));
}

/*============================================================================*
 * Composite Special-Purpose Register Access (INLINE)
 * Reference: Section B1.4.2 - IAPSR, EAPSR, IEPSR
 *============================================================================*/

/* IAPSR - Interrupt + Application PSR (IPSR + APSR) - SYSm = 1 */
ARM_V7M_CORE_INLINE uint32_t arm_v7m_get_iapsr(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, iapsr" : "=r" (result));
    return result;
}

ARM_V7M_CORE_INLINE void arm_v7m_set_iapsr_nzcvq(uint32_t value)
{
    __asm volatile ("MSR apsr_nzcvq, %0" : : "r" (value));
}

/* EAPSR - Execution + Application PSR (EPSR + APSR) - SYSm = 2 */
ARM_V7M_CORE_INLINE uint32_t arm_v7m_get_eapsr(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, eapsr" : "=r" (result));
    return result;
}

ARM_V7M_CORE_INLINE void arm_v7m_set_eapsr_nzcvq(uint32_t value)
{
    __asm volatile ("MSR apsr_nzcvq, %0" : : "r" (value));
}

/* IEPSR - Interrupt + Execution PSR (IPSR + EPSR) - SYSm = 7, Read-only */
ARM_V7M_CORE_INLINE uint32_t arm_v7m_get_iepsr(void)
{
    uint32_t result;
    __asm volatile ("MRS %0, iepsr" : "=r" (result));
    return result;
}

/*============================================================================*
 * Interrupt Enable/Disable Functions (CPS Instructions) (INLINE)
 * Reference: Section B5.2 - CPS instruction
 *============================================================================*/

/* Enable Interrupts (Clear PRIMASK) */
ARM_V7M_CORE_INLINE void arm_v7m_enable_irq(void)
{
    __asm volatile ("CPSIE i" : : : "memory");
}

/* Disable Interrupts (Set PRIMASK) */
ARM_V7M_CORE_INLINE void arm_v7m_disable_irq(void)
{
    __asm volatile ("CPSID i" : : : "memory");
}

/* Enable Faults (Clear FAULTMASK) */
ARM_V7M_CORE_INLINE void arm_v7m_enable_fault(void)
{
    __asm volatile ("CPSIE f" : : : "memory");
}

/* Disable Faults (Set FAULTMASK) */
ARM_V7M_CORE_INLINE void arm_v7m_disable_fault(void)
{
    __asm volatile ("CPSID f" : : : "memory");
}

/*============================================================================*
 * Memory Barrier Instructions (INLINE)
 * Reference: Section B5.2 - ISB, DSB, DMB instructions
 *============================================================================*/

ARM_V7M_CORE_INLINE void arm_v7m_isb(void)
{
    __asm volatile ("ISB" : : : "memory");
}

ARM_V7M_CORE_INLINE void arm_v7m_dsb(void)
{
    __asm volatile ("DSB" : : : "memory");
}

ARM_V7M_CORE_INLINE void arm_v7m_dmb(void)
{
    __asm volatile ("DMB" : : : "memory");
}

/*============================================================================*
 * Memory Barrier Instructions with Domain Options (INLINE)
 * Reference: ARMv7-M Architecture Reference Manual, Section A3.7.3
 *            - Memory barriers on page A3-92
 *============================================================================*/

ARM_V7M_CORE_INLINE void arm_v7m_dmb_sy(void)
{
    __asm volatile ("DMB SY" : : : "memory");
}

ARM_V7M_CORE_INLINE void arm_v7m_dmb_st(void)
{
    __asm volatile ("DMB ST" : : : "memory");
}

ARM_V7M_CORE_INLINE void arm_v7m_dmb_ld(void)
{
    __asm volatile ("DMB LD" : : : "memory");
}

ARM_V7M_CORE_INLINE void arm_v7m_dsb_sy(void)
{
    __asm volatile ("DSB SY" : : : "memory");
}

ARM_V7M_CORE_INLINE void arm_v7m_dsb_st(void)
{
    __asm volatile ("DSB ST" : : : "memory");
}

ARM_V7M_CORE_INLINE void arm_v7m_dsb_ld(void)
{
    __asm volatile ("DSB LD" : : : "memory");
}

/*============================================================================*
 * Power Management Instructions (INLINE)
 * Reference: Section B5.2 - WFI, WFE, SEV instructions
 *============================================================================*/

ARM_V7M_CORE_INLINE void arm_v7m_wfi(void)
{
    __asm volatile ("WFI" : : : "memory");
}

ARM_V7M_CORE_INLINE void arm_v7m_wfe(void)
{
    __asm volatile ("WFE" : : : "memory");
}

ARM_V7M_CORE_INLINE void arm_v7m_sev(void)
{
    __asm volatile ("SEV" : : : "memory");
}

/*============================================================================*
 * Other System Instructions (INLINE)
 * Reference: Section B5.2 - NOP, BKPT instructions
 *============================================================================*/

ARM_V7M_CORE_INLINE void arm_v7m_nop(void)
{
    __asm volatile ("NOP" : : : "memory");
}

ARM_V7M_CORE_INLINE void arm_v7m_bkpt(uint8_t imm)
{
    __asm volatile ("BKPT %0" : : "i" (imm));
}

/*============================================================================*
 * Exception-Generating Instructions (INLINE)
 * Reference: Section A7.7 - SVC, UDF instructions
 *============================================================================*/

ARM_V7M_CORE_INLINE void arm_v7m_svc(uint8_t imm)
{
    __asm volatile ("SVC %0" : : "i" (imm));
}

ARM_V7M_CORE_INLINE void arm_v7m_udf(uint16_t imm)
{
    __asm volatile ("UDF %0" : : "i" (imm));
}

/*============================================================================*
 * Helper Functions (INLINE - simple wrappers)
 *============================================================================*/

/* Get current exception number from IPSR */
ARM_V7M_CORE_INLINE uint32_t arm_v7m_get_exception_number(void)
{
    return (arm_v7m_get_ipsr() & ARM_V7M_IPSR_ISR_Msk);
}

/* Check if in Handler mode (executing an exception handler) */
ARM_V7M_CORE_INLINE int arm_v7m_is_in_handler_mode(void)
{
    return (arm_v7m_get_ipsr() & ARM_V7M_IPSR_ISR_Msk) != 0;
}

/* Get current stack pointer (MSP or PSP depending on mode and CONTROL) */
ARM_V7M_CORE_INLINE uint32_t arm_v7m_get_current_sp(void)
{
    uint32_t sp;
    __asm volatile ("MOV %0, sp" : "=r" (sp));
    return sp;
}

/*============================================================================*
 * Bit-Band Operations
 * Reference: ARMv7-M Architecture Reference Manual, Section A3.4
 *            - Bit-band operations on page A3-71
 *            - Bit-band alias regions for SRAM and Peripheral memory
 *============================================================================*/

/* Bit-band alias region base addresses */
#define ARM_V7M_BITBAND_SRAM_BASE       0x20000000UL
#define ARM_V7M_BITBAND_SRAM_ALIAS      0x22000000UL
#define ARM_V7M_BITBAND_PERIPH_BASE     0x40000000UL
#define ARM_V7M_BITBAND_PERIPH_ALIAS    0x42000000UL

/**
 * @brief Calculate bit-band alias address
 * 
 * According to ARMv7-M Architecture Reference Manual, Section A3.4:
 * - Bit-band alias address = alias_base + ((byte_offset * 32) + (bit_number * 4))
 * - byte_offset: offset from the bit-band base (0-0xFFFFF for SRAM, 0-0x1FFFFF for Peripheral)
 * - bit_number: bit position (0-31)
 * 
 * @param base Bit-band base address (0x20000000 for SRAM, 0x40000000 for Peripheral)
 * @param addr Target address within bit-band region
 * @param bit Bit number (0-31)
 * @return Bit-band alias address
 */
#define ARM_V7M_BITBAND_ADDR(base, addr, bit) \
    (((uint32_t)(base) & 0xF0000000UL) + 0x02000000UL + \
     ((((uint32_t)(addr) - (uint32_t)(base)) << 5) + ((bit) << 2)))

/**
 * @brief Set a bit using bit-band alias
 * 
 * @param addr Address of the word containing the bit
 * @param bit Bit number (0-31)
 */
ARM_V7M_CORE_INLINE void arm_v7m_bitband_set(volatile uint32_t *addr, uint32_t bit)
{
    uint32_t alias_addr;
    
    if (bit < 32U) {
        if (((uint32_t)addr >= ARM_V7M_BITBAND_SRAM_BASE) && 
            ((uint32_t)addr < (ARM_V7M_BITBAND_SRAM_BASE + 0x00100000UL))) {
            /* SRAM bit-band region */
            alias_addr = ARM_V7M_BITBAND_ADDR(ARM_V7M_BITBAND_SRAM_BASE, addr, bit);
        } else if (((uint32_t)addr >= ARM_V7M_BITBAND_PERIPH_BASE) && 
                   ((uint32_t)addr < (ARM_V7M_BITBAND_PERIPH_BASE + 0x00100000UL))) {
            /* Peripheral bit-band region */
            alias_addr = ARM_V7M_BITBAND_ADDR(ARM_V7M_BITBAND_PERIPH_BASE, addr, bit);
        } else {
            /* Address not in bit-band region, use normal read-modify-write */
            *addr |= (1UL << bit);
            return;
        }
        *(volatile uint32_t *)alias_addr = 1U;
    }
}

/**
 * @brief Clear a bit using bit-band alias
 * 
 * @param addr Address of the word containing the bit
 * @param bit Bit number (0-31)
 */
ARM_V7M_CORE_INLINE void arm_v7m_bitband_clear(volatile uint32_t *addr, uint32_t bit)
{
    uint32_t alias_addr;
    
    if (bit < 32U) {
        if (((uint32_t)addr >= ARM_V7M_BITBAND_SRAM_BASE) && 
            ((uint32_t)addr < (ARM_V7M_BITBAND_SRAM_BASE + 0x00100000UL))) {
            /* SRAM bit-band region */
            alias_addr = ARM_V7M_BITBAND_ADDR(ARM_V7M_BITBAND_SRAM_BASE, addr, bit);
        } else if (((uint32_t)addr >= ARM_V7M_BITBAND_PERIPH_BASE) && 
                   ((uint32_t)addr < (ARM_V7M_BITBAND_PERIPH_BASE + 0x00100000UL))) {
            /* Peripheral bit-band region */
            alias_addr = ARM_V7M_BITBAND_ADDR(ARM_V7M_BITBAND_PERIPH_BASE, addr, bit);
        } else {
            /* Address not in bit-band region, use normal read-modify-write */
            *addr &= ~(1UL << bit);
            return;
        }
        *(volatile uint32_t *)alias_addr = 0U;
    }
}

/**
 * @brief Read a bit using bit-band alias
 * 
 * @param addr Address of the word containing the bit
 * @param bit Bit number (0-31)
 * @return Bit value (0 or 1)
 */
ARM_V7M_CORE_INLINE uint32_t arm_v7m_bitband_read(volatile uint32_t *addr, uint32_t bit)
{
    uint32_t alias_addr;
    
    if (bit < 32U) {
        if (((uint32_t)addr >= ARM_V7M_BITBAND_SRAM_BASE) && 
            ((uint32_t)addr < (ARM_V7M_BITBAND_SRAM_BASE + 0x00100000UL))) {
            /* SRAM bit-band region */
            alias_addr = ARM_V7M_BITBAND_ADDR(ARM_V7M_BITBAND_SRAM_BASE, addr, bit);
        } else if (((uint32_t)addr >= ARM_V7M_BITBAND_PERIPH_BASE) && 
                   ((uint32_t)addr < (ARM_V7M_BITBAND_PERIPH_BASE + 0x00100000UL))) {
            /* Peripheral bit-band region */
            alias_addr = ARM_V7M_BITBAND_ADDR(ARM_V7M_BITBAND_PERIPH_BASE, addr, bit);
        } else {
            /* Address not in bit-band region, use normal read */
            return (*addr >> bit) & 1U;
        }
        return *(volatile uint32_t *)alias_addr;
    }
    return 0U;
}

/**
 * @brief Toggle a bit using bit-band alias
 * 
 * @param addr Address of the word containing the bit
 * @param bit Bit number (0-31)
 */
ARM_V7M_CORE_INLINE void arm_v7m_bitband_toggle(volatile uint32_t *addr, uint32_t bit)
{
    uint32_t current = arm_v7m_bitband_read(addr, bit);
    if (current) {
        arm_v7m_bitband_clear(addr, bit);
    } else {
        arm_v7m_bitband_set(addr, bit);
    }
}

/*============================================================================*
 * Helper Functions (NON-INLINE - complex logic)
 *============================================================================*/

/* Check if current execution is privileged */
int arm_v7m_is_privileged(void);

/* Set Thread mode to unprivileged */
void arm_v7m_set_unprivileged(void);

/* Set Thread mode to privileged */
void arm_v7m_set_privileged(void);

/* Use Process Stack Pointer (PSP) */
void arm_v7m_use_psp(void);

/* Use Main Stack Pointer (MSP) */
void arm_v7m_use_msp(void);

/*============================================================================*
 * CONTROL Register Bit Access Helper Functions (INLINE)
 * Reference: Section B1.4.4 - CONTROL register
 *============================================================================*/

/* Get CONTROL.nPRIV bit (0=privileged, 1=unprivileged) */
ARM_V7M_CORE_INLINE int arm_v7m_get_npriv(void)
{
    return (arm_v7m_get_control() & ARM_V7M_CONTROL_nPRIV_Msk) != 0;
}

/* Get CONTROL.SPSEL bit (0=MSP, 1=PSP) */
ARM_V7M_CORE_INLINE int arm_v7m_get_spsel(void)
{
    return (arm_v7m_get_control() & ARM_V7M_CONTROL_SPSEL_Msk) != 0;
}

/* Get CONTROL.FPCA bit (0=no FP context, 1=FP context active) */
ARM_V7M_CORE_INLINE int arm_v7m_get_fpca(void)
{
    return (arm_v7m_get_control() & ARM_V7M_CONTROL_FPCA_Msk) != 0;
}

/* Set CONTROL.FPCA bit - typically used by exception handler */
void arm_v7m_set_fpca(int value);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CORE_H */
