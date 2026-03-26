/*
 * arm_v7m_scb.c
 * System Control Block (SCB) Implementation
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2
 * 
 * This file contains non-inline implementations of complex SCB operations.
 * Simple register access functions are implemented as static inline in the header.
 */

#include "arm_v7m_scb.h"

/*============================================================================*
 * SCB System Control Operations
 *============================================================================*/

/**
 * @brief Trigger a system reset
 * 
 * According to ARMv7-M Architecture Reference Manual, Section B3.2.6:
 * - Must write 0x5FA to VECTKEY field (bits [31:16]) for the write to be accepted
 * - Set SYSRESETREQ bit (bit 2) to request a system reset
 * 
 * @note This function does not return if the reset is successful
 */
void arm_v7m_scb_system_reset(void)
{
    /* Memory barrier to ensure all memory accesses complete before reset */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Write to AIRCR: VECTKEY (0x5FA) | SYSRESETREQ */
    SCB->AIRCR = (SCB_AIRCR_VECTKEY_VALUE << SCB_AIRCR_VECTKEY_Pos) | 
                 SCB_AIRCR_SYSRESETREQ_Msk;
    
    /* Memory barrier after write */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Wait for reset - should not reach here */
    while (1) {
        __asm__ volatile ("nop");
    }
}

/**
 * @brief Set the priority grouping field
 * 
 * According to ARMv7-M Architecture Reference Manual, Section B3.2.6:
 * - PRIGROUP field in AIRCR determines the split between pre-emption and subpriority
 * - Must write VECTKEY (0x5FA) to bits [31:16] for the write to be accepted
 * 
 * @param priority_group Priority grouping field (SCB_PRIORITYGROUP_0 to SCB_PRIORITYGROUP_7)
 */
void arm_v7m_scb_set_priority_grouping(uint32_t priority_group)
{
    uint32_t reg_value;
    
    /* Memory barrier to ensure all memory accesses complete */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Read current AIRCR value, clear PRIGROUP, and set new value with VECTKEY */
    reg_value = SCB->AIRCR;
    reg_value &= ~SCB_AIRCR_PRIGROUP_Msk;
    reg_value |= (SCB_AIRCR_VECTKEY_VALUE << SCB_AIRCR_VECTKEY_Pos) | 
                 ((priority_group & 7U) << SCB_AIRCR_PRIGROUP_Pos);
    SCB->AIRCR = reg_value;
    
    /* Memory barrier after write */
    __asm__ volatile ("dsb" ::: "memory");
}

/*============================================================================*
 * SCB Fault Status Operations
 *============================================================================*/

/**
 * @brief Clear all fault status registers
 * 
 * According to ARMv7-M Architecture Reference Manual:
 * - CFSR, HFSR, DFSR are cleared by writing 1 to the bits that are set
 * - Writing 0 has no effect
 */
void arm_v7m_scb_clear_fault_status(void)
{
    /* Clear all fault status registers by writing the current value back */
    SCB->CFSR = SCB->CFSR;
    SCB->HFSR = SCB->HFSR;
    SCB->DFSR = SCB->DFSR;
}

/*============================================================================*
 * SCB System Handler Priority Operations
 *============================================================================*/

/**
 * @brief Get system handler priority
 * 
 * System handlers use SCB->SHP registers (byte accessible).
 * SHP[0] = MemManage (exception -12)
 * SHP[1] = BusFault (exception -11)
 * SHP[2] = UsageFault (exception -10)
 * SHP[3-6] = Reserved
 * SHP[7] = SVCall (exception -5)
 * SHP[8] = DebugMonitor (exception -4)
 * SHP[9] = Reserved
 * SHP[10] = PendSV (exception -2)
 * SHP[11] = SysTick (exception -1)
 * 
 * @param handler System handler number (0-11 corresponding to SHP array index)
 * @return Priority value (0-255), or 0 if handler is invalid
 */
uint32_t arm_v7m_scb_get_system_handler_priority(uint32_t handler)
{
    if (handler < 12U) {
        return SCB->SHP[handler];
    }
    return 0U;
}

/**
 * @brief Set system handler priority
 * 
 * @param handler System handler number (0-11 corresponding to SHP array index)
 * @param priority Priority value (0-255)
 */
void arm_v7m_scb_set_system_handler_priority(uint32_t handler, uint32_t priority)
{
    if (handler < 12U) {
        SCB->SHP[handler] = (uint8_t)(priority & 0xFFUL);
    }
}
