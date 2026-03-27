/*
 * arm_v7m_cm7_nvic.h
 * Cortex-M7 Nested Vectored Interrupt Controller (NVIC) Definitions
 * Reference: Cortex-M7 Devices Generic User Guide, Chapter 4.2
 *            Cortex-M7 Technical Reference Manual, Chapter 7
 *
 * @note Cortex-M7 NVIC is identical to generic Armv7-M NVIC.
 *       This file provides CM7-specific wrappers for NVIC operations.
 */

#ifndef ARM_V7M_CM7_NVIC_H
#define ARM_V7M_CM7_NVIC_H

#include <stdint.h>
#include "../arm_v7m_nvic.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Compiler Abstraction - Inline Definition
 *============================================================================*/

#if defined(__clang__)
    #define ARM_V7M_CM7_NVIC_INLINE static inline __attribute__((always_inline))
#else
    #error "This library requires Clang/LLVM compiler."
#endif

/*============================================================================*
 * Type Aliases
 *============================================================================*/

typedef arm_v7m_nvic_regs_t     arm_v7m_cm7_nvic_regs_t;
typedef arm_v7m_exception_t     arm_v7m_cm7_exception_t;

/*============================================================================*
 * Constant Aliases
 *============================================================================*/

#define ARM_V7M_CM7_NVIC_MIN_IRQN       NVIC_MIN_IRQN
#define ARM_V7M_CM7_NVIC_MAX_IRQN       NVIC_MAX_IRQN
#define ARM_V7M_CM7_NVIC_NUM_IRQN       NVIC_NUM_IRQN

/*============================================================================*
 * Inline Function Wrappers - NVIC Operations
 *============================================================================*/

/**
 * @brief Enable an external interrupt
 * @param irqn External interrupt number (0-495)
 * @note Sets the appropriate bit in NVIC_ISER register
 *       Reference: Cortex-M7 Devices Generic User Guide, Section 4.2.2
 */
ARM_V7M_CM7_NVIC_INLINE void arm_v7m_cm7_nvic_enable_irq(uint32_t irqn) {
    arm_v7m_nvic_enable_irq(irqn);
}

/**
 * @brief Disable an external interrupt
 * @param irqn External interrupt number (0-495)
 * @note Sets the appropriate bit in NVIC_ICER register
 *       Reference: Cortex-M7 Devices Generic User Guide, Section 4.2.3
 */
ARM_V7M_CM7_NVIC_INLINE void arm_v7m_cm7_nvic_disable_irq(uint32_t irqn) {
    arm_v7m_nvic_disable_irq(irqn);
}

/**
 * @brief Get the enable status of an external interrupt
 * @param irqn External interrupt number (0-495)
 * @return 1 if enabled, 0 if disabled
 * @note Reads the appropriate bit from NVIC_ISER register
 *       Reference: Cortex-M7 Devices Generic User Guide, Section 4.2.2
 */
ARM_V7M_CM7_NVIC_INLINE uint32_t arm_v7m_cm7_nvic_get_enable_irq(uint32_t irqn) {
    return arm_v7m_nvic_get_enable_irq(irqn);
}

/**
 * @brief Get the pending status of an external interrupt
 * @param irqn External interrupt number (0-495)
 * @return 1 if pending, 0 if not pending
 * @note Reads the appropriate bit from NVIC_ISPR register
 *       Reference: Cortex-M7 Devices Generic User Guide, Section 4.2.4
 */
ARM_V7M_CM7_NVIC_INLINE uint32_t arm_v7m_cm7_nvic_get_pending_irq(uint32_t irqn) {
    return arm_v7m_nvic_get_pending_irq(irqn);
}

/**
 * @brief Set an external interrupt to pending state
 * @param irqn External interrupt number (0-495)
 * @note Sets the appropriate bit in NVIC_ISPR register
 *       Reference: Cortex-M7 Devices Generic User Guide, Section 4.2.4
 */
ARM_V7M_CM7_NVIC_INLINE void arm_v7m_cm7_nvic_set_pending_irq(uint32_t irqn) {
    arm_v7m_nvic_set_pending_irq(irqn);
}

/**
 * @brief Clear the pending status of an external interrupt
 * @param irqn External interrupt number (0-495)
 * @note Sets the appropriate bit in NVIC_ICPR register
 *       Reference: Cortex-M7 Devices Generic User Guide, Section 4.2.5
 */
ARM_V7M_CM7_NVIC_INLINE void arm_v7m_cm7_nvic_clear_pending_irq(uint32_t irqn) {
    arm_v7m_nvic_clear_pending_irq(irqn);
}

/**
 * @brief Get the active status of an external interrupt
 * @param irqn External interrupt number (0-495)
 * @return 1 if active, 0 if not active
 * @note Reads the appropriate bit from NVIC_IABR register
 *       Reference: Cortex-M7 Devices Generic User Guide, Section 4.2.6
 */
ARM_V7M_CM7_NVIC_INLINE uint32_t arm_v7m_cm7_nvic_get_active_irq(uint32_t irqn) {
    return arm_v7m_nvic_get_active_irq(irqn);
}

/**
 * @brief Set the priority of an external interrupt
 * @param irqn External interrupt number (0-495)
 * @param priority Priority value (0-255, lower value = higher priority)
 * @note Writes to the appropriate NVIC_IPR register
 *       Reference: Cortex-M7 Devices Generic User Guide, Section 4.2.7
 */
ARM_V7M_CM7_NVIC_INLINE void arm_v7m_cm7_nvic_set_priority(uint32_t irqn, uint32_t priority) {
    arm_v7m_nvic_set_priority(irqn, priority);
}

/**
 * @brief Get the priority of an external interrupt
 * @param irqn External interrupt number (0-495)
 * @return Priority value (0-255)
 * @note Reads from the appropriate NVIC_IPR register
 *       Reference: Cortex-M7 Devices Generic User Guide, Section 4.2.7
 */
ARM_V7M_CM7_NVIC_INLINE uint32_t arm_v7m_cm7_nvic_get_priority(uint32_t irqn) {
    return arm_v7m_nvic_get_priority(irqn);
}

/**
 * @brief Trigger an external interrupt using STIR
 * @param irqn External interrupt number (0-495)
 * @note Writes to the STIR register at 0xE000EF00
 *       Reference: Cortex-M7 Devices Generic User Guide, Section 4.2.8
 */
ARM_V7M_CM7_NVIC_INLINE void arm_v7m_cm7_nvic_trigger_irq(uint32_t irqn) {
    arm_v7m_nvic_trigger_irq_stir(irqn);
}

/**
 * @brief Get the number of implemented external interrupts
 * @return Number of interrupts (32-496, in steps of 32)
 * @note Reads the INTLINESNUM field from ICTR register
 *       Reference: Cortex-M7 Devices Generic User Guide, Section 4.2.1
 */
ARM_V7M_CM7_NVIC_INLINE uint32_t arm_v7m_cm7_nvic_get_irq_count(void) {
    return arm_v7m_nvic_get_irq_count();
}

/**
 * @brief Enable multiple interrupts in a single operation
 * @param irqn_array Array of interrupt numbers
 * @param count Number of interrupts in the array
 * @note This is a batch operation that iterates through the array
 */
void arm_v7m_cm7_nvic_enable_irq_batch(const uint32_t *irqn_array, uint32_t count);

/**
 * @brief Disable multiple interrupts in a single operation
 * @param irqn_array Array of interrupt numbers
 * @param count Number of interrupts in the array
 * @note This is a batch operation that iterates through the array
 */
void arm_v7m_cm7_nvic_disable_irq_batch(const uint32_t *irqn_array, uint32_t count);

/**
 * @brief Disable all interrupts globally
 * @note Sets PRIMASK. This is a CPSID i instruction.
 * @reference Cortex-M7 Devices Generic User Guide, Section 2.1.4
 *            - Priority Mask Register on page 2-8
 */
ARM_V7M_CM7_NVIC_INLINE void arm_v7m_cm7_nvic_disable_all_irqs(void) {
    arm_v7m_nvic_disable_all_irqs();
}

/**
 * @brief Enable all interrupts globally
 * @note Clears PRIMASK. This is a CPSIE i instruction.
 * @reference Cortex-M7 Devices Generic User Guide, Section 2.1.4
 *            - Priority Mask Register on page 2-8
 */
ARM_V7M_CM7_NVIC_INLINE void arm_v7m_cm7_nvic_enable_all_irqs(void) {
    arm_v7m_nvic_enable_all_irqs();
}

/**
 * @brief Get global interrupt enable state
 * @return 1 if interrupts are enabled, 0 if disabled
 * @note Reads PRIMASK register
 * @reference Cortex-M7 Devices Generic User Guide, Section 2.1.4
 *            - Priority Mask Register on page 2-8
 */
ARM_V7M_CM7_NVIC_INLINE uint32_t arm_v7m_cm7_nvic_get_all_irqs_enabled(void) {
    return arm_v7m_nvic_get_all_irqs_enabled();
}

/*============================================================================*
 * Inline Function Wrappers - BASEPRI Control
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.3
 *            - The special-purpose mask registers, BASEPRI on page B1-528
 *            Cortex-M7 Devices Generic User Guide, Section 2.1.4
 *            - Base Priority Mask Register on page 2-8
 *============================================================================*/

/**
 * @brief Set BASEPRI register value
 * @param basepri Priority value (0-255)
 * @note Masks all interrupts with priority >= basepri
 */
ARM_V7M_CM7_NVIC_INLINE void arm_v7m_cm7_nvic_set_basepri(uint32_t basepri) {
    arm_v7m_nvic_set_basepri(basepri);
}

/**
 * @brief Get BASEPRI register value
 * @return Current BASEPRI value
 */
ARM_V7M_CM7_NVIC_INLINE uint32_t arm_v7m_cm7_nvic_get_basepri(void) {
    return arm_v7m_nvic_get_basepri();
}

/**
 * @brief Clear BASEPRI (enable all priority levels)
 */
ARM_V7M_CM7_NVIC_INLINE void arm_v7m_cm7_nvic_clear_basepri(void) {
    arm_v7m_nvic_clear_basepri();
}

/**
 * @brief Raise BASEPRI to mask interrupts up to specified priority
 * @param priority Priority threshold (lower value = higher priority)
 */
ARM_V7M_CM7_NVIC_INLINE void arm_v7m_cm7_nvic_raise_basepri(uint32_t priority) {
    arm_v7m_nvic_raise_basepri(priority);
}

/**
 * @brief Check if BASEPRI is active
 * @return 1 if BASEPRI is non-zero, 0 otherwise
 */
ARM_V7M_CM7_NVIC_INLINE uint32_t arm_v7m_cm7_nvic_is_basepri_active(void) {
    return arm_v7m_nvic_is_basepri_active();
}

/*============================================================================*
 * Inline Function Wrappers - FAULTMASK Control
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4.3
 *            - The special-purpose mask registers, FAULTMASK on page B1-529
 *            Cortex-M7 Devices Generic User Guide, Section 2.1.4
 *            - Fault Mask Register on page 2-8
 *============================================================================*/

/**
 * @brief Disable all fault exceptions
 * @note Sets FAULTMASK. All faults escalate to HardFault.
 */
ARM_V7M_CM7_NVIC_INLINE void arm_v7m_cm7_nvic_disable_faults(void) {
    arm_v7m_nvic_disable_faults();
}

/**
 * @brief Enable fault exceptions
 * @note Clears FAULTMASK
 */
ARM_V7M_CM7_NVIC_INLINE void arm_v7m_cm7_nvic_enable_faults(void) {
    arm_v7m_nvic_enable_faults();
}

/**
 * @brief Get FAULTMASK value
 * @return 1 if faults are disabled, 0 if enabled
 * @reference Cortex-M7 Devices Generic User Guide, Section 2.1.4
 *            - Fault Mask Register on page 2-8
 */
ARM_V7M_CM7_NVIC_INLINE uint32_t arm_v7m_cm7_nvic_get_fault_mask(void) {
    return arm_v7m_nvic_get_fault_mask();
}

/**
 * @brief Check if faults are disabled
 * @return 1 if faults are disabled, 0 if enabled
 * @reference Cortex-M7 Devices Generic User Guide, Section 2.1.4
 *            - Fault Mask Register on page 2-8
 */
ARM_V7M_CM7_NVIC_INLINE uint32_t arm_v7m_cm7_nvic_are_faults_disabled(void) {
    return arm_v7m_nvic_are_faults_disabled();
}

/*============================================================================*
 * Inline Function Wrappers - System Exception Priority
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.3.8
 *            - System Handler Priority Registers on page 4-22
 *            - System Handler Priority Register 1 on page 4-23
 *            - System Handler Priority Register 2 on page 4-23
 *            - System Handler Priority Register 3 on page 4-23
 *============================================================================*/

/**
 * @brief Set priority of a system exception
 * @param excn System exception number (e.g., MemoryManagement_IRQn)
 * @param priority Priority value (0-255)
 */
ARM_V7M_CM7_NVIC_INLINE void arm_v7m_cm7_nvic_set_system_exception_priority(int32_t excn, uint32_t priority) {
    arm_v7m_nvic_set_system_exception_priority(excn, priority);
}

/**
 * @brief Get priority of a system exception
 * @param excn System exception number
 * @return Priority value (0-255)
 */
ARM_V7M_CM7_NVIC_INLINE uint32_t arm_v7m_cm7_nvic_get_system_exception_priority(int32_t excn) {
    return arm_v7m_nvic_get_system_exception_priority(excn);
}

/*============================================================================*
 * Non-Inline Function Declarations
 *============================================================================*/

/**
 * @brief Get the highest priority pending interrupt
 * @return Highest priority pending interrupt number, or ARM_V7M_CM7_NVIC_NUM_IRQN if none
 * @note Traverses ISPR and IPR registers to find highest priority pending interrupt
 */
uint32_t arm_v7m_cm7_nvic_get_highest_pending_irq(void);

/*============================================================================*
 * Exception Number Aliases
 *============================================================================*/

#define ARM_V7M_CM7_NonMaskableInt_IRQn     NonMaskableInt_IRQn
#define ARM_V7M_CM7_HardFault_IRQn          HardFault_IRQn
#define ARM_V7M_CM7_MemoryManagement_IRQn   MemoryManagement_IRQn
#define ARM_V7M_CM7_BusFault_IRQn           BusFault_IRQn
#define ARM_V7M_CM7_UsageFault_IRQn         UsageFault_IRQn
#define ARM_V7M_CM7_SVCall_IRQn             SVCall_IRQn
#define ARM_V7M_CM7_DebugMonitor_IRQn       DebugMonitor_IRQn
#define ARM_V7M_CM7_PendSV_IRQn             PendSV_IRQn
#define ARM_V7M_CM7_SysTick_IRQn            SysTick_IRQn

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM7_NVIC_H */
