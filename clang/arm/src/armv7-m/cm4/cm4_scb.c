/*
 * ARM Architecture - Cortex-M4 SCB Implementation
 *
 * ============================================================================
 * File: cm4_scb.c
 * Description: Cortex-M4 SCB function implementations
 * 描述: Cortex-M4 SCB 函数实现
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.3 System control block (page 4-10)
 *   - Table 4-12 SCB registers summary (page 4-11)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include "armv7-m/cm4/cm4_scb.h"

/**
 * @brief Set vector table offset
 * @param offset Vector table offset address (must be aligned to 128 bytes)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.4 (page 4-16)
 */
void cm4_scb_set_vtor(uint32_t offset)
{
    SCB_VTOR = offset & SCB_VTOR_TBLOFF_Msk;
}

/**
 * @brief Get vector table offset
 * @return Vector table offset address
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.4 (page 4-16)
 */
uint32_t cm4_scb_get_vtor(void)
{
    return SCB_VTOR & SCB_VTOR_TBLOFF_Msk;
}

/**
 * @brief System reset request
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.5 (page 4-17)
 */
void cm4_scb_system_reset(void)
{
    SCB_AIRCR = SCB_AIRCR_VECTKEY_VALUE | SCB_AIRCR_SYSRESETREQ_Msk;
    __asm__ volatile ("DSB" ::: "memory");
    while(1);
}

/**
 * @brief Set priority grouping
 * @param group Priority grouping value (0-7)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.5 (page 4-17)
 */
void cm4_scb_set_priority_grouping(uint32_t group)
{
    uint32_t reg_value = SCB_AIRCR;
    reg_value &= ~(SCB_AIRCR_VECTKEY_Msk | SCB_AIRCR_PRIGROUP_Msk);
    reg_value |= (SCB_AIRCR_VECTKEY_VALUE | ((group & 7) << SCB_AIRCR_PRIGROUP_Pos));
    SCB_AIRCR = reg_value;
}

/**
 * @brief Get priority grouping
 * @return Priority grouping value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.5 (page 4-17)
 */
uint32_t cm4_scb_get_priority_grouping(void)
{
    return (SCB_AIRCR & SCB_AIRCR_PRIGROUP_Msk) >> SCB_AIRCR_PRIGROUP_Pos;
}

/**
 * @brief Enable MemManage fault
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.9 (page 4-23)
 */
void cm4_scb_enable_memfault(void)
{
    SCB_SHCSR |= SCB_SHCSR_MEMFAULTENA_Msk;
}

/**
 * @brief Enable BusFault
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.9 (page 4-23)
 */
void cm4_scb_enable_busfault(void)
{
    SCB_SHCSR |= SCB_SHCSR_BUSFAULTENA_Msk;
}

/**
 * @brief Enable UsageFault
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.9 (page 4-23)
 */
void cm4_scb_enable_usagefault(void)
{
    SCB_SHCSR |= SCB_SHCSR_USGFAULTENA_Msk;
}

/**
 * @brief Get CPUID
 * @return CPUID register value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.3.2 (page 4-13)
 */
uint32_t cm4_scb_get_cpuid(void)
{
    return SCB_CPUID;
}
