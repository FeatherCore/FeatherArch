/*
 * ARM Architecture - ARMv7-M System Control Block (SCB) Implementation
 *
 * ============================================================================
 * File: armv7-m_scb.c
 * Description: ARMv7-M System Control Block function implementations
 * 描述: ARMv7-M 系统控制块函数实现
 *
 * This file provides implementations for the System Control Block (SCB) functions
 * as described in Chapter B1.4 and B3.2 of the Architecture Reference Manual.
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1: System Level Programmers' Model
 *     * B1.4 Registers (page B1-516)
 *       - B1.4.1 The Arm core registers (page B1-516)
 *       - B1.4.2 The special-purpose Program Status Registers, xPSR (page B1-516)
 *   - Chapter B3: System Address Map
 *     * B3.2 System Control Space (SCS) (page B3-595)
 *       - B3.2.1 About the System Control Block (page B3-595)
 *       - B3.2.2 System control and ID registers (page B3-596)
 *       - Table B3-4 Summary of SCB registers (page B3-596)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_scb.h"

/*
 * ============================================================================
 * CPUID Register Functions
 * CPUID 寄存器函数
 * ============================================================================
 */

/**
 * @brief Get CPUID register value
 * @return CPUID value
 *
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 *   - CPUID Base Register identifies the processor
 * Reference: Chapter B3.2.3 CPUID Base Register (page B3-598)
 *   - IMPLEMENTER[31:24]: Implementer code (0x41 = ARM)
 *   - VARIANT[23:20]: Variant number
 *   - ARCHITECTURE[19:16]: Architecture code (0xF = ARMv7-M)
 *   - PARTNO[15:4]: Part number
 *   - REVISION[3:0]: Revision number
 */
uint32_t scb_get_cpuid(void)
{
    return SCB_CPUID;
}

/**
 * @brief Get implementer code from CPUID
 * @return Implementer code (0x41 = ARM)
 *
 * Reference: Chapter B3.2.3 CPUID Base Register (page B3-598)
 *   - IMPLEMENTER[31:24]: Implementer code
 *   - 0x41 = ARM
 */
uint8_t scb_get_implementer(void)
{
    return (uint8_t)((SCB_CPUID & CPUID_IMPLEMENTER_Msk) >> CPUID_IMPLEMENTER_Pos);
}

/**
 * @brief Get variant number from CPUID
 * @return Variant number
 *
 * Reference: Chapter B3.2.3 CPUID Base Register (page B3-598)
 *   - VARIANT[23:20]: Variant number (rNpX)
 */
uint8_t scb_get_variant(void)
{
    return (uint8_t)((SCB_CPUID & CPUID_VARIANT_Msk) >> CPUID_VARIANT_Pos);
}

/**
 * @brief Get architecture code from CPUID
 * @return Architecture code (0xF = ARMv7-M)
 *
 * Reference: Chapter B3.2.3 CPUID Base Register (page B3-598)
 *   - ARCHITECTURE[19:16]: Architecture code
 *   - 0xF = ARMv7-M
 */
uint8_t scb_get_architecture(void)
{
    return (uint8_t)((SCB_CPUID & CPUID_ARCHITECTURE_Msk) >> CPUID_ARCHITECTURE_Pos);
}

/**
 * @brief Get part number from CPUID
 * @return Part number
 *
 * Reference: Chapter B3.2.3 CPUID Base Register (page B3-598)
 *   - PARTNO[15:4]: Part number
 *   - 0xC20 = Cortex-M0
 *   - 0xC60 = Cortex-M0+
 *   - 0xC21 = Cortex-M1
 *   - 0xC23 = Cortex-M3
 *   - 0xC24 = Cortex-M4
 *   - 0xC27 = Cortex-M7
 */
uint16_t scb_get_partno(void)
{
    return (uint16_t)((SCB_CPUID & CPUID_PARTNO_Msk) >> CPUID_PARTNO_Pos);
}

/**
 * @brief Get revision number from CPUID
 * @return Revision number
 *
 * Reference: Chapter B3.2.3 CPUID Base Register (page B3-598)
 *   - REVISION[3:0]: Revision number
 */
uint8_t scb_get_revision(void)
{
    return (uint8_t)((SCB_CPUID & CPUID_REVISION_Msk) >> CPUID_REVISION_Pos);
}

/*
 * ============================================================================
 * Vector Table Functions
 * 向量表函数
 * ============================================================================
 */

/**
 * @brief Set vector table offset
 * @param offset Vector table base offset (must be aligned to 256 bytes)
 *
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 *   - VTOR sets the vector table base address
 * Reference: Chapter B3.2.7 Vector Table Offset Register (page B3-601)
 *   - TBLOFF[31:7]: Vector table base offset
 *   - Must be aligned to 256 bytes
 *   - Bits[6:0] are reserved, SBZ
 */
void scb_set_vtor(uint32_t offset)
{
    /* Ensure alignment to 256 bytes (bits[6:0] must be zero) */
    SCB_VTOR = offset & VTOR_TBLOFF_Msk;
}

/**
 * @brief Get vector table offset
 * @return Current vector table offset
 *
 * Reference: Chapter B3.2.7 Vector Table Offset Register (page B3-601)
 */
uint32_t scb_get_vtor(void)
{
    return SCB_VTOR & VTOR_TBLOFF_Msk;
}

/*
 * ============================================================================
 * System Control Functions
 * 系统控制函数
 * ============================================================================
 */

/**
 * @brief Request system reset
 *
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 *   - AIRCR.SYSRESETREQ requests a system reset
 * Reference: Chapter B3.2.6 Application Interrupt and Reset Control Register (page B3-601)
 *   - VECTKEY[31:16]: Register key (must write 0x05FA)
 *   - SYSRESETREQ[2]: System reset request
 *   - Writes to AIRCR must include the VECTKEY value
 *
 * Note: This function does not return if the reset is successful
 */
void scb_system_reset(void)
{
    /* Write VECTKEY | SYSRESETREQ */
    SCB_AIRCR = (AIRCR_VECTKEY_VALUE << AIRCR_VECTKEY_Pos) | AIRCR_SYSRESETREQ_Msk;

    /* Wait for reset */
    while (1) {
        __asm__ volatile ("nop");
    }
}

/**
 * @brief Set priority grouping
 * @param group Priority grouping value (0-7)
 *
 * Reference: Chapter B1.5.4 Priority grouping (page B1-527)
 *   - PRIGROUP determines the split of group priority and subpriority
 *   - Group priority determines preemption
 *   - Subpriority determines order within a group
 * Reference: Chapter B3.2.6 Application Interrupt and Reset Control Register (page B3-601)
 *   - PRIGROUP[10:8]: Interrupt priority grouping field
 *
 * Priority grouping values:
 *   0: 7 bits group priority, 1 bit subpriority
 *   1: 6 bits group priority, 2 bits subpriority
 *   2: 5 bits group priority, 3 bits subpriority
 *   3: 4 bits group priority, 4 bits subpriority
 *   4: 3 bits group priority, 5 bits subpriority
 *   5: 2 bits group priority, 6 bits subpriority
 *   6: 1 bit group priority, 7 bits subpriority
 *   7: 0 bits group priority, 8 bits subpriority (no preemption)
 */
void scb_set_priority_grouping(uint32_t group)
{
    uint32_t reg_value;

    /* Read current value */
    reg_value = SCB_AIRCR;

    /* Clear PRIGROUP field */
    reg_value &= ~AIRCR_PRIGROUP_Msk;

    /* Set new PRIGROUP value */
    reg_value |= ((group & 0x07) << AIRCR_PRIGROUP_Pos);

    /* Add VECTKEY for write */
    reg_value |= (AIRCR_VECTKEY_VALUE << AIRCR_VECTKEY_Pos);

    SCB_AIRCR = reg_value;
}

/**
 * @brief Get priority grouping
 * @return Current priority grouping value (0-7)
 *
 * Reference: Chapter B1.5.4 Priority grouping (page B1-527)
 * Reference: Chapter B3.2.6 Application Interrupt and Reset Control Register (page B3-601)
 */
uint32_t scb_get_priority_grouping(void)
{
    return (SCB_AIRCR & AIRCR_PRIGROUP_Msk) >> AIRCR_PRIGROUP_Pos;
}

/*
 * ============================================================================
 * Fault Handler Enable/Disable Functions
 * 故障处理程序使能/禁用函数
 * ============================================================================
 */

/**
 * @brief Enable UsageFault
 *
 * Reference: Chapter B3.2.13 System Handler Control and State Register (page B3-607)
 *   - USGFAULTENA[18]: UsageFault enable
 * Reference: Chapter B1.5.6 Fault behavior (page B1-531)
 *   - UsageFault exceptions are not active by default
 *   - Must be enabled in SHCSR before they can occur
 */
void scb_enable_usage_fault(void)
{
    SCB_SHCSR |= SHCSR_USGFAULTENA_Msk;
}

/**
 * @brief Disable UsageFault
 *
 * Reference: Chapter B3.2.13 System Handler Control and State Register (page B3-607)
 *   - USGFAULTENA[18]: UsageFault enable
 */
void scb_disable_usage_fault(void)
{
    SCB_SHCSR &= ~SHCSR_USGFAULTENA_Msk;
}

/**
 * @brief Enable BusFault
 *
 * Reference: Chapter B3.2.13 System Handler Control and State Register (page B3-607)
 *   - BUSFAULTENA[17]: BusFault enable
 * Reference: Chapter B1.5.6 Fault behavior (page B1-531)
 *   - BusFault exceptions are not active by default
 *   - Must be enabled in SHCSR before they can occur
 */
void scb_enable_bus_fault(void)
{
    SCB_SHCSR |= SHCSR_BUSFAULTENA_Msk;
}

/**
 * @brief Disable BusFault
 *
 * Reference: Chapter B3.2.13 System Handler Control and State Register (page B3-607)
 *   - BUSFAULTENA[17]: BusFault enable
 */
void scb_disable_bus_fault(void)
{
    SCB_SHCSR &= ~SHCSR_BUSFAULTENA_Msk;
}

/**
 * @brief Enable MemManage
 *
 * Reference: Chapter B3.2.13 System Handler Control and State Register (page B3-607)
 *   - MEMFAULTENA[16]: MemManage enable
 * Reference: Chapter B1.5.6 Fault behavior (page B1-531)
 *   - MemManage exceptions are not active by default
 *   - Must be enabled in SHCSR before they can occur
 */
void scb_enable_memmanage(void)
{
    SCB_SHCSR |= SHCSR_MEMFAULTENA_Msk;
}

/**
 * @brief Disable MemManage
 *
 * Reference: Chapter B3.2.13 System Handler Control and State Register (page B3-607)
 *   - MEMFAULTENA[16]: MemManage enable
 */
void scb_disable_memmanage(void)
{
    SCB_SHCSR &= ~SHCSR_MEMFAULTENA_Msk;
}

/*
 * ============================================================================
 * Exception Status Functions
 * 异常状态函数
 * ============================================================================
 */

/**
 * @brief Get active exception number
 * @return Active exception number (0 = Thread mode)
 *
 * Reference: Chapter B1.4.2 The IPSR (page B1-516)
 *   - IPSR[8:0] contains the current exception number
 *   - 0 = Thread mode
 *   - 1 = Reset
 *   - 2 = NMI
 *   - 3 = HardFault
 *   - etc.
 * Reference: Chapter B3.2.5 Interrupt Control and State Register (page B3-599)
 *   - VECTACTIVE[8:0]: Active exception number
 */
uint32_t scb_get_active_exception(void)
{
    return (SCB_ICSR & ICSR_VECTACTIVE_Msk) >> ICSR_VECTACTIVE_Pos;
}

/**
 * @brief Get pending exception number
 * @return Pending exception number (0 = no pending exception)
 *
 * Reference: Chapter B3.2.5 Interrupt Control and State Register (page B3-599)
 *   - VECTPENDING[20:12]: Pending exception number
 *   - 0 = no pending exception
 */
uint32_t scb_get_pending_exception(void)
{
    return (SCB_ICSR & ICSR_VECTPENDING_Msk) >> ICSR_VECTPENDING_Pos;
}

/*
 * ============================================================================
 * Additional SCB Functions
 * 额外的 SCB 函数
 * ============================================================================
 */

/**
 * @brief Check if in Handler mode
 * @return 1 if in Handler mode, 0 if in Thread mode
 *
 * Reference: Chapter B1.3.1 Modes, privilege and stacks (page B1-512)
 *   - Handler mode: executing an exception handler
 *   - Thread mode: executing application code
 */
int scb_in_handler_mode(void)
{
    return ((SCB_ICSR & ICSR_VECTACTIVE_Msk) != 0);
}

/**
 * @brief Get the number of implemented priority bits
 * @return Number of priority bits (3-8)
 *
 * Reference: Chapter B1.5.4 Priority grouping (page B1-527)
 *   - The number of priority bits is implementation defined
 *   - Minimum 3 bits (8 priority levels)
 *   - Maximum 8 bits (256 priority levels)
 */
uint32_t scb_get_priority_bits(void)
{
    /* Read SHPR1 and check which bits are writable */
    uint32_t original = SCB_SHPR1;
    SCB_SHPR1 = 0xFF;
    uint32_t implemented = SCB_SHPR1;
    SCB_SHPR1 = original;

    /* Count implemented bits */
    uint32_t bits = 0;
    while (implemented) {
        bits++;
        implemented >>= 1;
    }

    return bits;
}

/**
 * @brief Clear all fault status registers
 *
 * Reference: Chapter B3.2.14 Configurable Fault Status Register (page B3-609)
 * Reference: Chapter B3.2.15 HardFault Status Register (page B3-612)
 */
void scb_clear_fault_status(void)
{
    /* Clear CFSR (write 1 to clear) */
    SCB_CFSR = 0xFFFFFFFF;

    /* Clear HFSR (write 1 to clear) */
    SCB_HFSR = 0xFFFFFFFF;

    /* Clear DFSR (write 1 to clear) */
    SCB_DFSR = 0xFFFFFFFF;
}

/**
 * @brief Get MemManage fault address
 * @return MemManage fault address (valid only if MMARVALID is set)
 *
 * Reference: Chapter B3.2.17 MemManage Fault Address Register (page B3-613)
 */
uint32_t scb_get_mmfar(void)
{
    return SCB_MMFAR;
}

/**
 * @brief Get BusFault address
 * @return BusFault address (valid only if BFARVALID is set)
 *
 * Reference: Chapter B3.2.18 BusFault Address Register (page B3-614)
 */
uint32_t scb_get_bfar(void)
{
    return SCB_BFAR;
}

/**
 * @brief Check if MMFAR is valid
 * @return 1 if valid, 0 if not valid
 *
 * Reference: Chapter B3.2.14 Configurable Fault Status Register (page B3-609)
 *   - MMFSR.MMARVALID[7]: MMFAR valid flag
 */
int scb_mmfar_valid(void)
{
    return (CFSR_MMFSR & MMFSR_MMARVALID_Msk) ? 1 : 0;
}

/**
 * @brief Check if BFAR is valid
 * @return 1 if valid, 0 if not valid
 *
 * Reference: Chapter B3.2.14 Configurable Fault Status Register (page B3-609)
 *   - BFSR.BFARVALID[7]: BFAR valid flag
 */
int scb_bfar_valid(void)
{
    return (CFSR_BFSR & BFSR_BFARVALID_Msk) ? 1 : 0;
}

/**
 * @brief Trigger a PendSV exception
 *
 * Reference: Chapter B3.2.5 Interrupt Control and State Register (page B3-599)
 *   - PENDSVSET[28]: PendSV set-pending bit
 */
void scb_trigger_pendsv(void)
{
    SCB_ICSR = ICSR_PENDSVSET_Msk;
}

/**
 * @brief Clear PendSV pending status
 *
 * Reference: Chapter B3.2.5 Interrupt Control and State Register (page B3-599)
 *   - PENDSVCLR[27]: PendSV clear-pending bit
 */
void scb_clear_pendsv(void)
{
    SCB_ICSR = ICSR_PENDSVCLR_Msk;
}

/**
 * @brief Trigger a SysTick exception
 *
 * Reference: Chapter B3.2.5 Interrupt Control and State Register (page B3-599)
 *   - PENDSTSET[26]: SysTick set-pending bit
 */
void scb_trigger_systick(void)
{
    SCB_ICSR = ICSR_PENDSTSET_Msk;
}

/**
 * @brief Clear SysTick pending status
 *
 * Reference: Chapter B3.2.5 Interrupt Control and State Register (page B3-599)
 *   - PENDSTCLR[25]: SysTick clear-pending bit
 */
void scb_clear_systick(void)
{
    SCB_ICSR = ICSR_PENDSTCLR_Msk;
}

/**
 * @brief Check if there are any pending interrupts
 * @return 1 if pending interrupts exist, 0 otherwise
 *
 * Reference: Chapter B3.2.5 Interrupt Control and State Register (page B3-599)
 *   - ISRPENDING[22]: Interrupt pending flag
 */
int scb_interrupt_pending(void)
{
    return (SCB_ICSR & ICSR_ISRPENDING_Msk) ? 1 : 0;
}

/**
 * @brief Check if returning to base level (no preempted exceptions)
 * @return 1 if returning to base, 0 otherwise
 *
 * Reference: Chapter B3.2.5 Interrupt Control and State Register (page B3-599)
 *   - RETTOBASE[11]: Return to base level
 */
int scb_return_to_base(void)
{
    return (SCB_ICSR & ICSR_RETTOBASE_Msk) ? 1 : 0;
}

/*
 * ============================================================================
 * CPUID Feature Register Functions (Chapter B4)
 * CPUID 特性寄存器函数 (B4章节)
 * ============================================================================
 */

/**
 * @brief Get ID_PFR0 register value
 * @return ID_PFR0 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 *   - ID_PFR0: Processor Feature Register 0
 * Reference: Chapter B4.2.1 ID_PFR0 (page B4-646)
 *   - State1[7:4]: Thumb instruction set support
 *   - State0[3:0]: Arm instruction set support
 */
uint32_t scb_get_id_pfr0(void)
{
    return SCB_ID_PFR0;
}

/**
 * @brief Get ID_PFR1 register value
 * @return ID_PFR1 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 *   - ID_PFR1: Processor Feature Register 1
 * Reference: Chapter B4.2.2 ID_PFR1 (page B4-646)
 *   - M-profile programmers' model[11:8]
 */
uint32_t scb_get_id_pfr1(void)
{
    return SCB_ID_PFR1;
}

/**
 * @brief Check if processor supports Thumb-2
 * @return 1 if supported, 0 otherwise
 *
 * Reference: Chapter B4.2.1 ID_PFR0 (page B4-646)
 *   - State1[7:4] = 0x3 indicates Thumb-2 support
 */
int scb_has_thumb2_support(void)
{
    return ((SCB_ID_PFR0 & ID_PFR0_STATE1_Msk) >> ID_PFR0_STATE1_Pos) == ID_PFR0_STATE1_THUMB2;
}

/**
 * @brief Check if processor supports two-stack model
 * @return 1 if supported, 0 otherwise
 *
 * Reference: Chapter B4.2.2 ID_PFR1 (page B4-646)
 *   - M-profile[11:8] = 0x2 indicates two-stack support
 */
int scb_has_two_stack_support(void)
{
    return ((SCB_ID_PFR1 & ID_PFR1_MPROFILE_Msk) >> ID_PFR1_MPROFILE_Pos) == ID_PFR1_MPROFILE_TWO_STACK;
}

/**
 * @brief Get ID_DFR0 register value
 * @return ID_DFR0 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 *   - ID_DFR0: Debug Feature Register 0
 * Reference: Chapter B4.3.1 ID_DFR0 (page B4-648)
 */
uint32_t scb_get_id_dfr0(void)
{
    return SCB_ID_DFR0;
}

/**
 * @brief Get ID_AFR0 register value
 * @return ID_AFR0 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 *   - ID_AFR0: Auxiliary Feature Register 0
 * Reference: Chapter B4.4.1 ID_AFR0 (page B4-649)
 */
uint32_t scb_get_id_afr0(void)
{
    return SCB_ID_AFR0;
}

/**
 * @brief Get ID_MMFR0 register value
 * @return ID_MMFR0 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 *   - ID_MMFR0: Memory Model Feature Register 0
 * Reference: Chapter B4.5.1 ID_MMFR0 (page B4-650)
 */
uint32_t scb_get_id_mmfr0(void)
{
    return SCB_ID_MMFR0;
}

/**
 * @brief Check if processor supports PMSAv7
 * @return 1 if supported, 0 otherwise
 *
 * Reference: Chapter B4.5.1 ID_MMFR0 (page B4-650)
 *   - PMSA[7:4] = 0x3 indicates PMSAv7 support
 */
int scb_has_pmsa_v7(void)
{
    return ((SCB_ID_MMFR0 & ID_MMFR0_PMSA_Msk) >> ID_MMFR0_PMSA_Pos) == ID_MMFR0_PMSA_V7;
}

/**
 * @brief Get ID_MMFR1 register value
 * @return ID_MMFR1 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 *   - ID_MMFR1: Memory Model Feature Register 1
 * Reference: Chapter B4.5.2 ID_MMFR1 (page B4-652)
 */
uint32_t scb_get_id_mmfr1(void)
{
    return SCB_ID_MMFR1;
}

/**
 * @brief Get ID_MMFR2 register value
 * @return ID_MMFR2 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 *   - ID_MMFR2: Memory Model Feature Register 2
 * Reference: Chapter B4.5.3 ID_MMFR2 (page B4-652)
 */
uint32_t scb_get_id_mmfr2(void)
{
    return SCB_ID_MMFR2;
}

/**
 * @brief Get ID_MMFR3 register value
 * @return ID_MMFR3 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 *   - ID_MMFR3: Memory Model Feature Register 3
 * Reference: Chapter B4.5.4 ID_MMFR3 (page B4-653)
 */
uint32_t scb_get_id_mmfr3(void)
{
    return SCB_ID_MMFR3;
}

/**
 * @brief Get ID_ISAR0 register value
 * @return ID_ISAR0 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 *   - ID_ISAR0: Instruction Set Attribute Register 0
 */
uint32_t scb_get_id_isar0(void)
{
    return SCB_ID_ISAR0;
}

/**
 * @brief Get ID_ISAR1 register value
 * @return ID_ISAR1 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 *   - ID_ISAR1: Instruction Set Attribute Register 1
 */
uint32_t scb_get_id_isar1(void)
{
    return SCB_ID_ISAR1;
}

/**
 * @brief Get ID_ISAR2 register value
 * @return ID_ISAR2 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 *   - ID_ISAR2: Instruction Set Attribute Register 2
 */
uint32_t scb_get_id_isar2(void)
{
    return SCB_ID_ISAR2;
}

/**
 * @brief Get ID_ISAR3 register value
 * @return ID_ISAR3 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 *   - ID_ISAR3: Instruction Set Attribute Register 3
 */
uint32_t scb_get_id_isar3(void)
{
    return SCB_ID_ISAR3;
}

/**
 * @brief Get ID_ISAR4 register value
 * @return ID_ISAR4 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 *   - ID_ISAR4: Instruction Set Attribute Register 4
 */
uint32_t scb_get_id_isar4(void)
{
    return SCB_ID_ISAR4;
}

/**
 * @brief Get CLIDR register value
 * @return CLIDR value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 *   - CLIDR: Cache Level ID Register
 * Reference: Chapter B4.8.1 CLIDR (page B4-665)
 */
uint32_t scb_get_clidr(void)
{
    return SCB_CLIDR;
}

/**
 * @brief Get CTR register value
 * @return CTR value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 *   - CTR: Cache Type Register
 * Reference: Chapter B4.8.2 CTR (page B4-667)
 */
uint32_t scb_get_ctr(void)
{
    return SCB_CTR;
}

/**
 * @brief Get CCSIDR register value
 * @return CCSIDR value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 *   - CCSIDR: Cache Size ID Register
 * Reference: Chapter B4.8.3 CCSIDR (page B4-666)
 */
uint32_t scb_get_ccsidr(void)
{
    return SCB_CCSIDR;
}

/**
 * @brief Get CSSELR register value
 * @return CSSELR value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 *   - CSSELR: Cache Size Selection Register
 * Reference: Chapter B4.8.4 CSSELR (page B4-667)
 */
uint32_t scb_get_csselr(void)
{
    return SCB_CSSELR;
}

/**
 * @brief Set CSSELR register value
 * @param value Value to write
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 *   - CSSELR: Cache Size Selection Register
 * Reference: Chapter B4.8.4 CSSELR (page B4-667)
 *   - Selects which cache CCSIDR provides information for
 */
void scb_set_csselr(uint32_t value)
{
    SCB_CSSELR = value;
}
