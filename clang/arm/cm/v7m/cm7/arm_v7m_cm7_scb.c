/*
 * arm_v7m_cm7_scb.c
 * Cortex-M7 System Control Block (SCB) Implementation
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2
 *            - Section B3.2.5: Application Interrupt and Reset Control Register, AIRCR on page B3-601
 *            - Section B3.2.6: System Control Register, SCR on page B3-603
 *            - Section B3.2.10: Configurable Fault Status Register, CFSR on page B3-609
 *            - Section B3.2.11: HardFault Status Register, HFSR on page B3-612
 *            - Section B3.2.12: MemManage Fault Address Register, MMFAR on page B3-613
 *            - Section B3.2.13: BusFault Address Register, BFAR on page B3-614
 *            - Section B3.2.14: Auxiliary Fault Status Register, AFSR on page B3-614
 *            - Section B3.2.15: Coprocessor Access Control Register, CPACR on page B3-614
 *            Cortex-M7 Devices Generic User Guide, Chapter 4.3
 *            - Section 4.3.5: Application Interrupt and Reset Control Register on page 4-17
 *            - Section 4.3.8: System Handler Priority Registers on page 4-23
 *            - Section 4.3.9: System Handler Control and State Register on page 4-24
 *            - Section 4.3.10: Configurable Fault Status Register on page 4-25
 *            - Section 4.3.11: HardFault Status Register on page 4-31
 *            Cortex-M7 Technical Reference Manual, Chapter 3
 *            - Section 3.3: Register descriptions on page 3-6
 *
 * This file wraps the generic Armv7-M SCB implementation for Cortex-M7.
 * All functions delegate to the generic v7m implementation.
 *
 * @note This file wraps the generic Armv7-M SCB implementation.
 */

#include "arm_v7m_cm7_scb.h"

/*============================================================================*
 * SCB System Control Operations
 *============================================================================*/

/**
 * @brief Trigger a system reset
 * @note This function does not return if the reset is successful
 */
void arm_v7m_cm7_scb_system_reset(void)
{
    arm_v7m_scb_system_reset();
}

/**
 * @brief Set the priority grouping field
 * @param priority_group Priority grouping field (ARM_V7M_CM7_SCB_PRIORITYGROUP_0 to ARM_V7M_CM7_SCB_PRIORITYGROUP_7)
 */
void arm_v7m_cm7_scb_set_priority_grouping(uint32_t priority_group)
{
    arm_v7m_scb_set_priority_grouping(priority_group);
}

/*============================================================================*
 * SCB Fault Status Operations
 *============================================================================*/

/**
 * @brief Clear all fault status registers
 */
void arm_v7m_cm7_scb_clear_fault_status(void)
{
    arm_v7m_scb_clear_fault_status();
}

/*============================================================================*
 * SCB System Handler Priority Operations
 *============================================================================*/

/**
 * @brief Get system handler priority
 * @param handler System handler number (0-11 corresponding to SHP array index)
 * @return Priority value (0-255), or 0 if handler is invalid
 */
uint32_t arm_v7m_cm7_scb_get_system_handler_priority(uint32_t handler)
{
    return arm_v7m_scb_get_system_handler_priority(handler);
}

/**
 * @brief Set system handler priority
 * @param handler System handler number (0-11 corresponding to SHP array index)
 * @param priority Priority value (0-255)
 */
void arm_v7m_cm7_scb_set_system_handler_priority(uint32_t handler, uint32_t priority)
{
    arm_v7m_scb_set_system_handler_priority(handler, priority);
}
