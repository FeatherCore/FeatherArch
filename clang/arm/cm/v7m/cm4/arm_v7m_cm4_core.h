/*
 * arm_v7m_cm4_core.h
 * Cortex-M4 Core Register Definitions
 * 
 * Reference: ARMv7-M Architecture Reference Manual
 *            - Section A2.3: Arm core registers on page A2-33
 *            - Section A2.3.2: The Application Program Status Register (APSR) on page A2-35
 *            - Section A2.3.3: The special-purpose Program Status Registers, xPSR on page A2-37
 *            - Section A2.3.4: The special-purpose mask registers on page A2-38
 *            - Section A2.3.5: The special-purpose CONTROL register on page A2-39
 *            - Section A3.4: Bit-band operations on page A3-71
 *            - Section B1.4: Registers on page B1-516
 *            - Section B1.4.1: The Arm core registers on page B1-516
 *            - Section B1.4.2: The special-purpose Program Status Registers, xPSR on page B1-516
 *            - Section B1.4.3: The special-purpose mask registers on page B1-528
 *            - Section B1.4.4: The special-purpose CONTROL register on page B1-519
 *            - Section B5.2: Armv7-M system instruction descriptions on page B5-672
 * 
 *            Cortex-M4 Devices Generic User Guide
 *            - Chapter 2: The Cortex-M4 Processor
 *            - Section 2.1: Programmers model on page 2-2
 *            - Section 2.1.3: Core registers on page 2-3
 *            - Table 2-2: Core register set summary on page 2-3
 *            - Section 2.1.4: Stack Pointer on page 2-4
 *            - Section 2.1.5: Program Status Register on page 2-4
 *            - Section 2.1.6: Application Program Status Register on page 2-5
 *            - Section 2.1.7: Interrupt Program Status Register on page 2-6
 *            - Section 2.1.8: Execution Program Status Register on page 2-6
 *            - Section 2.1.9: Exception mask registers (PRIMASK, FAULTMASK, BASEPRI) on page 2-7
 *            - Section 2.1.10: CONTROL register on page 2-9
 * 
 *            Cortex-M4 Technical Reference Manual
 *            - Chapter 3.8: Processor core registers on page 3-8
 *            - Section 3.8.1: Core register set summary on page 3-9
 *            - Section 3.8.2: Stack Pointer on page 3-10
 *            - Section 3.8.3: Program Status Register on page 3-10
 *            - Section 3.8.4: Application Program Status Register on page 3-11
 *            - Section 3.8.5: Interrupt Program Status Register on page 3-11
 *            - Section 3.8.6: Execution Program Status Register on page 3-11
 *            - Section 3.8.7: Exception mask registers on page 3-11
 *            - Section 3.8.8: CONTROL register on page 3-12
 * 
 * @note Cortex-M4 is a standard Armv7-M implementation.
 *       Basic core registers reuse generic Armv7-M definitions from arm_v7m_core.h
 */

#ifndef ARM_V7M_CM4_CORE_H
#define ARM_V7M_CM4_CORE_H

#include <stdint.h>
#include "../arm_v7m_core.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Type Aliases - Map CM4 types to generic Armv7-M types
 *============================================================================*/

typedef arm_v7m_core_regs_t     arm_v7m_cm4_core_regs_t;

/*============================================================================*
 * Inline Function Wrappers - Core Register Access
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4
 *            Cortex-M4 Devices Generic User Guide, Section 2.1
 *============================================================================*/

/**
 * @brief Get Main Stack Pointer (MSP)
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.1
 *            Cortex-M4 Devices Generic User Guide, Section 2.1.4
 * @return Current MSP value
 */
static inline uint32_t arm_v7m_cm4_get_msp(void) {
    return arm_v7m_get_msp();
}

/**
 * @brief Set Main Stack Pointer (MSP)
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.1
 *            Cortex-M4 Devices Generic User Guide, Section 2.1.4
 * @param value New MSP value
 */
static inline void arm_v7m_cm4_set_msp(uint32_t value) {
    arm_v7m_set_msp(value);
}

/**
 * @brief Get Process Stack Pointer (PSP)
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.1
 *            Cortex-M4 Devices Generic User Guide, Section 2.1.4
 * @return Current PSP value
 */
static inline uint32_t arm_v7m_cm4_get_psp(void) {
    return arm_v7m_get_psp();
}

/**
 * @brief Set Process Stack Pointer (PSP)
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.1
 *            Cortex-M4 Devices Generic User Guide, Section 2.1.4
 * @param value New PSP value
 */
static inline void arm_v7m_cm4_set_psp(uint32_t value) {
    arm_v7m_set_psp(value);
}

/**
 * @brief Get PRIMASK register
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.3
 *            Cortex-M4 Devices Generic User Guide, Section 2.1.9
 * @return Current PRIMASK value
 */
static inline uint32_t arm_v7m_cm4_get_primask(void) {
    return arm_v7m_get_primask();
}

/**
 * @brief Set PRIMASK register
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.3
 *            Cortex-M4 Devices Generic User Guide, Section 2.1.9
 * @param value New PRIMASK value
 */
static inline void arm_v7m_cm4_set_primask(uint32_t value) {
    arm_v7m_set_primask(value);
}

/**
 * @brief Get FAULTMASK register
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.3
 *            Cortex-M4 Devices Generic User Guide, Section 2.1.9
 * @return Current FAULTMASK value
 */
static inline uint32_t arm_v7m_cm4_get_faultmask(void) {
    return arm_v7m_get_faultmask();
}

/**
 * @brief Set FAULTMASK register
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.3
 *            Cortex-M4 Devices Generic User Guide, Section 2.1.9
 * @param value New FAULTMASK value
 */
static inline void arm_v7m_cm4_set_faultmask(uint32_t value) {
    arm_v7m_set_faultmask(value);
}

/**
 * @brief Get BASEPRI register
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.3
 *            Cortex-M4 Devices Generic User Guide, Section 2.1.9
 * @return Current BASEPRI value
 */
static inline uint32_t arm_v7m_cm4_get_basepri(void) {
    return arm_v7m_get_basepri();
}

/**
 * @brief Set BASEPRI register
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.3
 *            Cortex-M4 Devices Generic User Guide, Section 2.1.9
 * @param value New BASEPRI value
 */
static inline void arm_v7m_cm4_set_basepri(uint32_t value) {
    arm_v7m_set_basepri(value);
}

/**
 * @brief Get CONTROL register
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.4
 *            Cortex-M4 Devices Generic User Guide, Section 2.1.10
 * @return Current CONTROL register value
 */
static inline uint32_t arm_v7m_cm4_get_control(void) {
    return arm_v7m_get_control();
}

/**
 * @brief Set CONTROL register
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.4
 *            Cortex-M4 Devices Generic User Guide, Section 2.1.10
 * @param value New CONTROL register value
 * @note After writing to CONTROL, an ISB instruction is required to ensure
 *       subsequent instructions use the new configuration.
 */
static inline void arm_v7m_cm4_set_control(uint32_t value) {
    arm_v7m_set_control(value);
}

/*============================================================================*
 * APSR/IPSR/EPSR Register Access
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.2
 *            Cortex-M4 Devices Generic User Guide, Section 2.1.5-2.1.8
 *============================================================================*/

/**
 * @brief Get APSR (Application Program Status Register)
 * Reference: ARMv7-M Architecture Reference Manual, Section A2.3.2
 *            Cortex-M4 Devices Generic User Guide, Section 2.1.6
 * @return Current APSR value
 */
static inline uint32_t arm_v7m_cm4_get_apsr(void) {
    return arm_v7m_get_apsr();
}

/**
 * @brief Set APSR (N, Z, C, V, Q bits)
 * Reference: ARMv7-M Architecture Reference Manual, Section A2.3.2
 *            Cortex-M4 Devices Generic User Guide, Section 2.1.6
 * @param value New APSR value
 */
static inline void arm_v7m_cm4_set_apsr(uint32_t value) {
    arm_v7m_set_apsr(value);
}

/**
 * @brief Set APSR with nzcvq qualifier (N, Z, C, V, Q bits)
 * Reference: ARMv7-M Architecture Reference Manual, Section A2.3.2
 * @param value New APSR value
 */
static inline void arm_v7m_cm4_set_apsr_nzcvq(uint32_t value) {
    arm_v7m_set_apsr_nzcvq(value);
}

/**
 * @brief Set APSR with g qualifier (GE[3:0] bits, DSP Extension)
 * Reference: ARMv7-M Architecture Reference Manual, Section A2.3.2
 * @param value New APSR GE bits value
 */
static inline void arm_v7m_cm4_set_apsr_g(uint32_t value) {
    arm_v7m_set_apsr_g(value);
}

/**
 * @brief Set APSR with nzcvqg qualifier (N, Z, C, V, Q, GE bits)
 * Reference: ARMv7-M Architecture Reference Manual, Section A2.3.2
 * @param value New APSR value
 */
static inline void arm_v7m_cm4_set_apsr_nzcvqg(uint32_t value) {
    arm_v7m_set_apsr_nzcvqg(value);
}

/**
 * @brief Get IPSR (Interrupt Program Status Register)
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.2
 *            Cortex-M4 Devices Generic User Guide, Section 2.1.7
 * @return Current IPSR value (exception number)
 */
static inline uint32_t arm_v7m_cm4_get_ipsr(void) {
    return arm_v7m_get_ipsr();
}

/**
 * @brief Get EPSR (Execution Program Status Register)
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.2
 *            Cortex-M4 Devices Generic User Guide, Section 2.1.8
 * @return Current EPSR value
 * @note EPSR reads as zero when using MRS instruction.
 */
static inline uint32_t arm_v7m_cm4_get_epsr(void) {
    return arm_v7m_get_epsr();
}

/**
 * @brief Get XPSR (combined APSR + IPSR + EPSR)
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.2
 * @return Current XPSR value
 */
static inline uint32_t arm_v7m_cm4_get_xpsr(void) {
    return arm_v7m_get_xpsr();
}

/**
 * @brief Set XPSR
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.2
 * @param value New XPSR value
 */
static inline void arm_v7m_cm4_set_xpsr(uint32_t value) {
    arm_v7m_set_xpsr(value);
}

/**
 * @brief Get IAPSR (Interrupt + Application PSR)
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.2
 * @return Current IAPSR value
 */
static inline uint32_t arm_v7m_cm4_get_iapsr(void) {
    return arm_v7m_get_iapsr();
}

/**
 * @brief Get EAPSR (Execution + Application PSR)
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.2
 * @return Current EAPSR value
 */
static inline uint32_t arm_v7m_cm4_get_eapsr(void) {
    return arm_v7m_get_eapsr();
}

/**
 * @brief Get IEPSR (Interrupt + Execution PSR)
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.2
 * @return Current IEPSR value
 */
static inline uint32_t arm_v7m_cm4_get_iepsr(void) {
    return arm_v7m_get_iepsr();
}

/*============================================================================*
 * BASEPRI_MAX Register Access
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.3
 *============================================================================*/

/**
 * @brief Set BASEPRI_MAX register (conditional write)
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.3
 * @param value New BASEPRI value (only written if value is higher priority)
 * @note Only updates BASEPRI if the new value is non-zero and has higher priority
 *       (lower numeric value) than the current BASEPRI.
 */
static inline void arm_v7m_cm4_set_basepri_max(uint32_t value) {
    arm_v7m_set_basepri_max(value);
}

/*============================================================================*
 * Interrupt and Fault Control
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.3
 *============================================================================*/

/**
 * @brief Enable interrupts (clear PRIMASK)
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.3
 */
static inline void arm_v7m_cm4_enable_irq(void) {
    arm_v7m_enable_irq();
}

/**
 * @brief Disable interrupts (set PRIMASK)
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.3
 */
static inline void arm_v7m_cm4_disable_irq(void) {
    arm_v7m_disable_irq();
}

/**
 * @brief Enable faults (clear FAULTMASK)
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.3
 */
static inline void arm_v7m_cm4_enable_fault(void) {
    arm_v7m_enable_fault();
}

/**
 * @brief Disable faults (set FAULTMASK)
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.3
 */
static inline void arm_v7m_cm4_disable_fault(void) {
    arm_v7m_disable_fault();
}

/*============================================================================*
 * Memory Barrier Instructions
 * Reference: ARMv7-M Architecture Reference Manual, Section A3.7.3
 *============================================================================*/

/**
 * @brief Instruction Synchronization Barrier
 * Reference: ARMv7-M Architecture Reference Manual, Section A3.7.3
 */
static inline void arm_v7m_cm4_isb(void) {
    arm_v7m_isb();
}

/**
 * @brief Data Synchronization Barrier
 * Reference: ARMv7-M Architecture Reference Manual, Section A3.7.3
 */
static inline void arm_v7m_cm4_dsb(void) {
    arm_v7m_dsb();
}

/**
 * @brief Data Memory Barrier
 * Reference: ARMv7-M Architecture Reference Manual, Section A3.7.3
 */
static inline void arm_v7m_cm4_dmb(void) {
    arm_v7m_dmb();
}

/*============================================================================*
 * Power Management Instructions
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.5
 *============================================================================*/

/**
 * @brief Wait For Interrupt
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.5.3
 */
static inline void arm_v7m_cm4_wfi(void) {
    arm_v7m_wfi();
}

/**
 * @brief Wait For Event
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.5.4
 */
static inline void arm_v7m_cm4_wfe(void) {
    arm_v7m_wfe();
}

/**
 * @brief Send Event
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.5.4
 */
static inline void arm_v7m_cm4_sev(void) {
    arm_v7m_sev();
}

/*============================================================================*
 * Helper Functions
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4
 *============================================================================*/

/**
 * @brief Get current exception number from IPSR
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.2
 * @return Exception number (0 = Thread mode)
 */
static inline uint32_t arm_v7m_cm4_get_exception_number(void) {
    return arm_v7m_get_exception_number();
}

/**
 * @brief Check if in Handler mode
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.2
 * @return 1 if in Handler mode, 0 if in Thread mode
 */
static inline int arm_v7m_cm4_is_in_handler_mode(void) {
    return arm_v7m_is_in_handler_mode();
}

/**
 * @brief Get current stack pointer
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.1
 * @return Current SP value (MSP or PSP depending on mode)
 */
static inline uint32_t arm_v7m_cm4_get_current_sp(void) {
    return arm_v7m_get_current_sp();
}

/**
 * @brief Check if current execution is privileged
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.4
 * @return 1 if privileged, 0 if unprivileged
 */
static inline int arm_v7m_cm4_is_privileged(void) {
    return arm_v7m_is_privileged();
}

/**
 * @brief Set Thread mode to unprivileged
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.4
 */
static inline void arm_v7m_cm4_set_unprivileged(void) {
    arm_v7m_set_unprivileged();
}

/**
 * @brief Set Thread mode to privileged
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.4
 */
static inline void arm_v7m_cm4_set_privileged(void) {
    arm_v7m_set_privileged();
}

/**
 * @brief Use Process Stack Pointer (PSP)
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.4
 */
static inline void arm_v7m_cm4_use_psp(void) {
    arm_v7m_use_psp();
}

/**
 * @brief Use Main Stack Pointer (MSP)
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.4
 */
static inline void arm_v7m_cm4_use_msp(void) {
    arm_v7m_use_msp();
}

/*============================================================================*
 * CONTROL Register Bit Access
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.4
 *============================================================================*/

/**
 * @brief Get CONTROL.nPRIV bit
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.4
 * @return 0 = privileged, 1 = unprivileged
 */
static inline int arm_v7m_cm4_get_npriv(void) {
    return arm_v7m_get_npriv();
}

/**
 * @brief Get CONTROL.SPSEL bit
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.4
 * @return 0 = MSP, 1 = PSP
 */
static inline int arm_v7m_cm4_get_spsel(void) {
    return arm_v7m_get_spsel();
}

/**
 * @brief Get CONTROL.FPCA bit
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.4
 * @return 0 = no FP context, 1 = FP context active
 */
static inline int arm_v7m_cm4_get_fpca(void) {
    return arm_v7m_get_fpca();
}

/**
 * @brief Set CONTROL.FPCA bit
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.4
 * @param value 0 = no FP context, 1 = FP context active
 */
static inline void arm_v7m_cm4_set_fpca(int value) {
    arm_v7m_set_fpca(value);
}

/*============================================================================*
 * Bit-Band Operations
 * Reference: ARMv7-M Architecture Reference Manual, Section A3.4
 *            Cortex-M4 Devices Generic User Guide, Section 2.2.5
 *============================================================================*/

/**
 * @brief Set a bit using bit-band alias
 * Reference: ARMv7-M Architecture Reference Manual, Section A3.4
 * @param addr Address of the word containing the bit
 * @param bit Bit number (0-31)
 */
static inline void arm_v7m_cm4_bitband_set(volatile uint32_t *addr, uint32_t bit) {
    arm_v7m_bitband_set(addr, bit);
}

/**
 * @brief Clear a bit using bit-band alias
 * Reference: ARMv7-M Architecture Reference Manual, Section A3.4
 * @param addr Address of the word containing the bit
 * @param bit Bit number (0-31)
 */
static inline void arm_v7m_cm4_bitband_clear(volatile uint32_t *addr, uint32_t bit) {
    arm_v7m_bitband_clear(addr, bit);
}

/**
 * @brief Read a bit using bit-band alias
 * Reference: ARMv7-M Architecture Reference Manual, Section A3.4
 * @param addr Address of the word containing the bit
 * @param bit Bit number (0-31)
 * @return Bit value (0 or 1)
 */
static inline uint32_t arm_v7m_cm4_bitband_read(volatile uint32_t *addr, uint32_t bit) {
    return arm_v7m_bitband_read(addr, bit);
}

/**
 * @brief Toggle a bit using bit-band alias
 * Reference: ARMv7-M Architecture Reference Manual, Section A3.4
 * @param addr Address of the word containing the bit
 * @param bit Bit number (0-31)
 */
static inline void arm_v7m_cm4_bitband_toggle(volatile uint32_t *addr, uint32_t bit) {
    arm_v7m_bitband_toggle(addr, bit);
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM4_CORE_H */
