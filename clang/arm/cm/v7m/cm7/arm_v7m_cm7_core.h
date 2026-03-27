/*
 * arm_v7m_cm7_core.h
 * Cortex-M7 Core Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual
 *            - Section B1.4: Registers on page B1-514
 *            - Section B1.4.1: Arm core registers on page B1-514
 *            - Section B1.4.2: The special-purpose Program Status Registers, xPSR on page B1-516
 *            - Section B1.4.3: The special-purpose mask registers on page B1-528
 *            - Section B1.4.4: The special-purpose CONTROL register on page B1-519
 *            - Section A2.3: Arm core registers on page A2-33
 *            - Section A2.3.1: Arm core registers on page A2-33
 *            - Section A2.3.2: The Application Program Status Register (APSR) on page A2-35
 *            - Section A2.3.3: The special-purpose Program Status Registers, xPSR on page A2-37
 *            - Section A2.3.4: The special-purpose mask registers on page A2-38
 *            - Section A2.3.5: The special-purpose CONTROL register on page A2-39
 *            - Section B5.2: System Instruction Descriptions on page B5-678
 *            Cortex-M7 Devices Generic User Guide, Chapter 2.1
 *            - Core register set summary on page 2-3
 *            - Stack Pointer on page 2-4
 *            - Program Status Register on page 2-4
 *            - Application Program Status Register on page 2-5
 *            - Interrupt Program Status Register on page 2-6
 *            - Execution Program Status Register on page 2-6
 *            - Exception mask registers (PRIMASK, FAULTMASK, BASEPRI) on page 2-7
 *            - Priority Mask Register on page 2-8
 *            - Fault Mask Register on page 2-8
 *            - Base Priority Mask Register on page 2-8
 *            - CONTROL register on page 2-9
 *            Cortex-M7 Technical Reference Manual, Chapter 2.6
 *            - Processor core registers on page 2-9
 *            - Core register set summary on page 2-9
 *            - Stack Pointer on page 2-10
 *            - Program Status Register on page 2-10
 *            - Application Program Status Register on page 2-11
 *            - Interrupt Program Status Register on page 2-11
 *            - Execution Program Status Register on page 2-11
 *            - Exception mask registers on page 2-11
 *            - CONTROL register on page 2-12
 *
 * @note Cortex-M7 extends standard Armv7-M with Cache and TCM.
 *       Basic core registers reuse generic Armv7-M definitions from arm_v7m_core.h
 */

#ifndef ARM_V7M_CM7_CORE_H
#define ARM_V7M_CM7_CORE_H

#include <stdint.h>
#include "../arm_v7m_core.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Compiler Abstraction - Inline Definition
 *============================================================================*/

#if defined(__clang__)
    #define ARM_V7M_CM7_CORE_INLINE static inline __attribute__((always_inline))
#else
    #error "This library requires Clang/LLVM compiler."
#endif

/*============================================================================*
 * Type Aliases - Basic Core Registers (same as generic Armv7-M)
 *============================================================================*/

typedef arm_v7m_core_regs_t     arm_v7m_cm7_core_regs_t;

/*============================================================================*
 * Inline Function Wrappers - Core Register Access (reuse generic)
 *============================================================================*/

/**
 * @brief Get Main Stack Pointer (MSP)
 * @return Current MSP value
 */
ARM_V7M_CM7_CORE_INLINE uint32_t arm_v7m_cm7_get_msp(void) {
    return arm_v7m_get_msp();
}

/**
 * @brief Set Main Stack Pointer (MSP)
 * @param value New MSP value
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_set_msp(uint32_t value) {
    arm_v7m_set_msp(value);
}

/**
 * @brief Get Process Stack Pointer (PSP)
 * @return Current PSP value
 */
ARM_V7M_CM7_CORE_INLINE uint32_t arm_v7m_cm7_get_psp(void) {
    return arm_v7m_get_psp();
}

/**
 * @brief Set Process Stack Pointer (PSP)
 * @param value New PSP value
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_set_psp(uint32_t value) {
    arm_v7m_set_psp(value);
}

/**
 * @brief Get PRIMASK register
 * @return Current PRIMASK value
 */
ARM_V7M_CM7_CORE_INLINE uint32_t arm_v7m_cm7_get_primask(void) {
    return arm_v7m_get_primask();
}

/**
 * @brief Set PRIMASK register
 * @param value New PRIMASK value
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_set_primask(uint32_t value) {
    arm_v7m_set_primask(value);
}

/**
 * @brief Get FAULTMASK register
 * @return Current FAULTMASK value
 */
ARM_V7M_CM7_CORE_INLINE uint32_t arm_v7m_cm7_get_faultmask(void) {
    return arm_v7m_get_faultmask();
}

/**
 * @brief Set FAULTMASK register
 * @param value New FAULTMASK value
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_set_faultmask(uint32_t value) {
    arm_v7m_set_faultmask(value);
}

/**
 * @brief Get BASEPRI register
 * @return Current BASEPRI value
 */
ARM_V7M_CM7_CORE_INLINE uint32_t arm_v7m_cm7_get_basepri(void) {
    return arm_v7m_get_basepri();
}

/**
 * @brief Set BASEPRI register
 * @param value New BASEPRI value
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_set_basepri(uint32_t value) {
    arm_v7m_set_basepri(value);
}

/**
 * @brief Set BASEPRI_MAX register (conditional write)
 * @param value New BASEPRI value (only written if value is higher priority)
 * @note Only updates BASEPRI if the new value is non-zero and has higher priority
 *       (lower numeric value) than the current BASEPRI.
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_set_basepri_max(uint32_t value) {
    arm_v7m_set_basepri_max(value);
}

/**
 * @brief Get CONTROL register
 * @return Current CONTROL register value
 */
ARM_V7M_CM7_CORE_INLINE uint32_t arm_v7m_cm7_get_control(void) {
    return arm_v7m_get_control();
}

/**
 * @brief Set CONTROL register
 * @param value New CONTROL register value
 * @note After writing to CONTROL, an ISB instruction is required to ensure
 *       subsequent instructions use the new configuration.
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_set_control(uint32_t value) {
    arm_v7m_set_control(value);
}

/*============================================================================*
 * APSR/IPSR/EPSR Register Access - Reuse generic implementations
 *============================================================================*/

/**
 * @brief Get APSR (Application Program Status Register)
 * @return Current APSR value
 */
ARM_V7M_CM7_CORE_INLINE uint32_t arm_v7m_cm7_get_apsr(void) {
    return arm_v7m_get_apsr();
}

/**
 * @brief Set APSR (N, Z, C, V, Q bits)
 * @param value New APSR value
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_set_apsr(uint32_t value) {
    arm_v7m_set_apsr(value);
}

/**
 * @brief Set APSR with nzcvq qualifier (N, Z, C, V, Q bits)
 * @param value New APSR value
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_set_apsr_nzcvq(uint32_t value) {
    arm_v7m_set_apsr_nzcvq(value);
}

/**
 * @brief Set APSR with g qualifier (GE[3:0] bits, DSP Extension)
 * @param value New APSR GE bits value
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_set_apsr_g(uint32_t value) {
    arm_v7m_set_apsr_g(value);
}

/**
 * @brief Set APSR with nzcvqg qualifier (N, Z, C, V, Q, GE bits)
 * @param value New APSR value
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_set_apsr_nzcvqg(uint32_t value) {
    arm_v7m_set_apsr_nzcvqg(value);
}

/**
 * @brief Get IPSR (Interrupt Program Status Register)
 * @return Current IPSR value (exception number)
 */
ARM_V7M_CM7_CORE_INLINE uint32_t arm_v7m_cm7_get_ipsr(void) {
    return arm_v7m_get_ipsr();
}

/**
 * @brief Get EPSR (Execution Program Status Register)
 * @return Current EPSR value
 * @note EPSR reads as zero when using MRS instruction.
 */
ARM_V7M_CM7_CORE_INLINE uint32_t arm_v7m_cm7_get_epsr(void) {
    return arm_v7m_get_epsr();
}

/**
 * @brief Get XPSR (combined APSR + IPSR + EPSR)
 * @return Current XPSR value
 */
ARM_V7M_CM7_CORE_INLINE uint32_t arm_v7m_cm7_get_xpsr(void) {
    return arm_v7m_get_xpsr();
}

/**
 * @brief Set XPSR
 * @param value New XPSR value
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_set_xpsr(uint32_t value) {
    arm_v7m_set_xpsr(value);
}

/*============================================================================*
 * Composite PSR Register Access
 *============================================================================*/

/**
 * @brief Get IAPSR (Interrupt + Application PSR)
 * @return Current IAPSR value
 */
ARM_V7M_CM7_CORE_INLINE uint32_t arm_v7m_cm7_get_iapsr(void) {
    return arm_v7m_get_iapsr();
}

/**
 * @brief Get EAPSR (Execution + Application PSR)
 * @return Current EAPSR value
 */
ARM_V7M_CM7_CORE_INLINE uint32_t arm_v7m_cm7_get_eapsr(void) {
    return arm_v7m_get_eapsr();
}

/**
 * @brief Get IEPSR (Interrupt + Execution PSR)
 * @return Current IEPSR value
 */
ARM_V7M_CM7_CORE_INLINE uint32_t arm_v7m_cm7_get_iepsr(void) {
    return arm_v7m_get_iepsr();
}

/*============================================================================*
 * Interrupt and Fault Control
 *============================================================================*/

/**
 * @brief Enable interrupts (clear PRIMASK)
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_enable_irq(void) {
    arm_v7m_enable_irq();
}

/**
 * @brief Disable interrupts (set PRIMASK)
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_disable_irq(void) {
    arm_v7m_disable_irq();
}

/**
 * @brief Enable faults (clear FAULTMASK)
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_enable_fault(void) {
    arm_v7m_enable_fault();
}

/**
 * @brief Disable faults (set FAULTMASK)
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_disable_fault(void) {
    arm_v7m_disable_fault();
}

/*============================================================================*
 * Memory Barrier Instructions
 *============================================================================*/

/**
 * @brief Instruction Synchronization Barrier
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_isb(void) {
    arm_v7m_isb();
}

/**
 * @brief Data Synchronization Barrier
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_dsb(void) {
    arm_v7m_dsb();
}

/**
 * @brief Data Memory Barrier
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_dmb(void) {
    arm_v7m_dmb();
}

/*============================================================================*
 * Power Management Instructions
 *============================================================================*/

/**
 * @brief Wait For Interrupt
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_wfi(void) {
    arm_v7m_wfi();
}

/**
 * @brief Wait For Event
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_wfe(void) {
    arm_v7m_wfe();
}

/**
 * @brief Send Event
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_sev(void) {
    arm_v7m_sev();
}

/*============================================================================*
 * Helper Functions
 *============================================================================*/

/**
 * @brief Get current exception number from IPSR
 * @return Exception number (0 = Thread mode)
 */
ARM_V7M_CM7_CORE_INLINE uint32_t arm_v7m_cm7_get_exception_number(void) {
    return arm_v7m_get_exception_number();
}

/**
 * @brief Check if in Handler mode
 * @return 1 if in Handler mode, 0 if in Thread mode
 */
ARM_V7M_CM7_CORE_INLINE int arm_v7m_cm7_is_in_handler_mode(void) {
    return arm_v7m_is_in_handler_mode();
}

/**
 * @brief Get current stack pointer
 * @return Current SP value (MSP or PSP depending on mode)
 */
ARM_V7M_CM7_CORE_INLINE uint32_t arm_v7m_cm7_get_current_sp(void) {
    return arm_v7m_get_current_sp();
}

/**
 * @brief Check if current execution is privileged
 * @return 1 if privileged, 0 if unprivileged
 */
ARM_V7M_CM7_CORE_INLINE int arm_v7m_cm7_is_privileged(void) {
    return arm_v7m_is_privileged();
}

/**
 * @brief Set Thread mode to unprivileged
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_set_unprivileged(void) {
    arm_v7m_set_unprivileged();
}

/**
 * @brief Set Thread mode to privileged
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_set_privileged(void) {
    arm_v7m_set_privileged();
}

/**
 * @brief Use Process Stack Pointer (PSP)
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_use_psp(void) {
    arm_v7m_use_psp();
}

/**
 * @brief Use Main Stack Pointer (MSP)
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_use_msp(void) {
    arm_v7m_use_msp();
}

/*============================================================================*
 * CONTROL Register Bit Access
 *============================================================================*/

/**
 * @brief Get CONTROL.nPRIV bit
 * @return 0 = privileged, 1 = unprivileged
 */
ARM_V7M_CM7_CORE_INLINE int arm_v7m_cm7_get_npriv(void) {
    return arm_v7m_get_npriv();
}

/**
 * @brief Get CONTROL.SPSEL bit
 * @return 0 = MSP, 1 = PSP
 */
ARM_V7M_CM7_CORE_INLINE int arm_v7m_cm7_get_spsel(void) {
    return arm_v7m_get_spsel();
}

/**
 * @brief Get CONTROL.FPCA bit
 * @return 0 = no FP context, 1 = FP context active
 */
ARM_V7M_CM7_CORE_INLINE int arm_v7m_cm7_get_fpca(void) {
    return arm_v7m_get_fpca();
}

/**
 * @brief Set CONTROL.FPCA bit
 * @param value 0 = no FP context, 1 = FP context active
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_set_fpca(int value) {
    arm_v7m_set_fpca(value);
}

/*============================================================================*
 * Bit-Band Operations (reuse generic implementation)
 * Reference: ARMv7-M Architecture Reference Manual, Section A3.4
 *============================================================================*/

/**
 * @brief Set a bit using bit-band alias
 * @param addr Address of the word containing the bit
 * @param bit Bit number (0-31)
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_bitband_set(volatile uint32_t *addr, uint32_t bit) {
    arm_v7m_bitband_set(addr, bit);
}

/**
 * @brief Clear a bit using bit-band alias
 * @param addr Address of the word containing the bit
 * @param bit Bit number (0-31)
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_bitband_clear(volatile uint32_t *addr, uint32_t bit) {
    arm_v7m_bitband_clear(addr, bit);
}

/**
 * @brief Read a bit using bit-band alias
 * @param addr Address of the word containing the bit
 * @param bit Bit number (0-31)
 * @return Bit value (0 or 1)
 */
ARM_V7M_CM7_CORE_INLINE uint32_t arm_v7m_cm7_bitband_read(volatile uint32_t *addr, uint32_t bit) {
    return arm_v7m_bitband_read(addr, bit);
}

/**
 * @brief Toggle a bit using bit-band alias
 * @param addr Address of the word containing the bit
 * @param bit Bit number (0-31)
 */
ARM_V7M_CM7_CORE_INLINE void arm_v7m_cm7_bitband_toggle(volatile uint32_t *addr, uint32_t bit) {
    arm_v7m_bitband_toggle(addr, bit);
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM7_CORE_H */
