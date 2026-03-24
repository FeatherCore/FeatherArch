/*
 * ARM Architecture - ARMv7-M NVIC (Nested Vectored Interrupt Controller)
 *
 * ============================================================================
 * File: armv7-m_nvic.c
 * Description: ARMv7-M NVIC function implementations
 * 描述: ARMv7-M NVIC 函数实现
 *
 * This file provides implementations for NVIC functions:
 * - Interrupt enable/disable/pending
 * - Priority management
 * - Priority grouping
 *
 * SCB (System Control Block) functions are implemented in armv7-m_scb.c
 * This file includes scb.c implementations for backward compatibility.
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B3.4: Nested Vectored Interrupt Controller, NVIC
 *     * B3.4.1 NVIC register summary (page B3-627)
 *       - NVIC_ISER: Interrupt Set Enable Registers
 *       - NVIC_ICER: Interrupt Clear Enable Registers
 *       - NVIC_ISPR: Interrupt Set Pending Registers
 *       - NVIC_ICPR: Interrupt Clear Pending Registers
 *       - NVIC_IABR: Interrupt Active Bit Registers
 *       - NVIC_IPR: Interrupt Priority Registers
 *     * B3.4.2 NVIC register descriptions
 *       - ISER: Enable interrupts (page B3-628)
 *       - ICER: Disable interrupts (page B3-629)
 *       - ISPR: Set pending state (page B3-629)
 *       - ICPR: Clear pending state (page B3-630)
 *       - IABR: Active bit status (page B3-630)
 *       - IPR: Priority configuration (page B3-631)
 *   - Chapter B3.2: System Control Space (SCS)
 *     * B3.2.2: SCB register summary (page B3-596)
 *       - AIRCR: Application Interrupt and Reset Control Register
 *       - VTOR: Vector Table Offset Register
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stddef.h>
#include "armv7-m/armv7-m_nvic.h"
#include "armv7-m/armv7-m_core.h"
#include "armv7-m/armv7-m_scb.h"

/*
 * ============================================================================
 * NVIC Interrupt Control Functions
 * NVIC 中断控制函数
 * Reference: Chapter B3.4 - Nested Vectored Interrupt Controller, NVIC
 * ============================================================================
 */

/**
 * @brief Enable specified interrupt
 * @param irq Interrupt number (0 to __ARM_NUM_INTERRUPTS-1)
 *
 * Sets the corresponding bit in NVIC_ISER to enable the interrupt.
 *
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - ISER register
 */
void nvic_enable_irq(uint8_t irq)
{
    NVIC_ISER(irq / 32) = (1UL << (irq % 32));
}

/**
 * @brief Disable specified interrupt
 * @param irq Interrupt number
 *
 * Sets the corresponding bit in NVIC_ICER to disable the interrupt.
 *
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - ICER register
 */
void nvic_disable_irq(uint8_t irq)
{
    NVIC_ICER(irq / 32) = (1UL << (irq % 32));
}

/**
 * @brief Get interrupt enable status
 * @param irq Interrupt number
 * @return 1 if enabled, 0 if disabled
 *
 * Reads the corresponding bit from NVIC_ISER.
 *
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - ISER register
 */
uint32_t nvic_get_enable_irq(uint8_t irq)
{
    return (NVIC_ISER(irq / 32) & (1UL << (irq % 32))) ? 1U : 0U;
}

/**
 * @brief Set interrupt pending status
 * @param irq Interrupt number
 *
 * Sets the corresponding bit in NVIC_ISPR to pend the interrupt.
 *
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - ISPR register
 */
void nvic_set_pending(uint8_t irq)
{
    NVIC_ISPR(irq / 32) = (1UL << (irq % 32));
}

/**
 * @brief Clear interrupt pending status
 * @param irq Interrupt number
 *
 * Sets the corresponding bit in NVIC_ICPR to clear pending state.
 *
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - ICPR register
 */
void nvic_clear_pending(uint8_t irq)
{
    NVIC_ICPR(irq / 32) = (1UL << (irq % 32));
}

/**
 * @brief Get interrupt pending status
 * @param irq Interrupt number
 * @return 1 if pending, 0 if not pending
 *
 * Reads the corresponding bit from NVIC_ISPR.
 *
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - ISPR register
 */
uint32_t nvic_get_pending(uint8_t irq)
{
    return (NVIC_ISPR(irq / 32) & (1UL << (irq % 32))) ? 1U : 0U;
}

/**
 * @brief Get active interrupt status
 * @param irq Interrupt number
 * @return 1 if active, 0 if not active
 *
 * Reads the corresponding bit from NVIC_IABR.
 *
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - IABR register
 */
uint32_t nvic_get_active(uint8_t irq)
{
    return (NVIC_IABR(irq / 32) & (1UL << (irq % 32))) ? 1U : 0U;
}

/**
 * @brief Set interrupt priority
 * @param irq Interrupt number
 * @param priority Priority value (0=highest, 255=lowest)
 *
 * Writes priority value to NVIC_IPR.
 * Only bits[7:4] are used in most implementations (4-bit priority).
 *
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - IPR register
 */
void nvic_set_priority(uint8_t irq, uint8_t priority)
{
    NVIC_IPR(irq) = priority;
}

/**
 * @brief Get interrupt priority
 * @param irq Interrupt number
 * @return Priority value
 *
 * Reads priority value from NVIC_IPR.
 *
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - IPR register
 */
uint8_t nvic_get_priority(uint8_t irq)
{
    return NVIC_IPR(irq);
}

/*
 * ============================================================================
 * NVIC Priority Grouping Functions
 * NVIC 优先级分组函数
 * Reference: Chapter B3.4 - Nested Vectored Interrupt Controller, NVIC
 * ============================================================================
 */

/**
 * @brief Set priority grouping
 * @param priority_group Priority grouping value (0-7)
 *
 * Configures the priority grouping using AIRCR.PRIGROUP.
 * Determines the split between preemption priority and subpriority.
 *
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - AIRCR register
 */
void nvic_set_priority_grouping(uint32_t priority_group)
{
    uint32_t reg_value = SCB_AIRCR;
    reg_value &= ~(AIRCR_VECTKEY_Msk | AIRCR_PRIGROUP_Msk);
    reg_value |= (AIRCR_VECTKEY_VALUE << AIRCR_VECTKEY_Pos) | ((priority_group & 0x7) << AIRCR_PRIGROUP_Pos);
    SCB_AIRCR = reg_value;
}

/**
 * @brief Get priority grouping
 * @return Priority grouping value
 *
 * Reads AIRCR.PRIGROUP to get current priority grouping.
 *
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - AIRCR register
 */
uint32_t nvic_get_priority_grouping(void)
{
    return (SCB_AIRCR & AIRCR_PRIGROUP_Msk) >> AIRCR_PRIGROUP_Pos;
}

/**
 * @brief Encode priority
 * @param priority_group Priority grouping
 * @param preempt_priority Preemption priority
 * @param sub_priority Sub-priority
 * @return Encoded priority value
 *
 * Encodes preemption priority and subpriority into a single priority value
 * based on the priority grouping.
 *
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller)
 */
uint32_t nvic_encode_priority(uint32_t priority_group, uint32_t preempt_priority, uint32_t sub_priority)
{
    uint32_t priority;
    uint32_t preempt_bits;
    uint32_t sub_bits;

    /* Calculate number of bits for each priority type based on grouping */
    preempt_bits = 7 - priority_group;
    sub_bits = priority_group - 3;

    if (preempt_bits > 4) {
        preempt_bits = 4;
    }
    if (sub_bits > 4) {
        sub_bits = 4;
    }

    /* Encode priority */
    priority = ((preempt_priority & ((1UL << preempt_bits) - 1)) << sub_bits) |
               (sub_priority & ((1UL << sub_bits) - 1));

    return priority;
}

/**
 * @brief Decode priority
 * @param priority Encoded priority
 * @param priority_group Priority grouping
 * @param preempt_priority Output preemption priority
 * @param sub_priority Output sub-priority
 *
 * Decodes a priority value into preemption priority and subpriority
 * based on the priority grouping.
 *
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller)
 */
void nvic_decode_priority(uint32_t priority, uint32_t priority_group, uint32_t *preempt_priority, uint32_t *sub_priority)
{
    uint32_t preempt_bits;
    uint32_t sub_bits;

    if (preempt_priority == NULL || sub_priority == NULL) {
        return;
    }

    /* Calculate number of bits for each priority type based on grouping */
    preempt_bits = 7 - priority_group;
    sub_bits = priority_group - 3;

    if (preempt_bits > 4) {
        preempt_bits = 4;
    }
    if (sub_bits > 4) {
        sub_bits = 4;
    }

    /* Decode priority */
    *preempt_priority = (priority >> sub_bits) & ((1UL << preempt_bits) - 1);
    *sub_priority = priority & ((1UL << sub_bits) - 1);
}

/*
 * ============================================================================
 * System Control Functions
 * 系统控制函数
 * Reference: Chapter B3.2 - System Control Space (SCS)
 * ============================================================================
 */

/**
 * @brief System reset
 * Reference: Arm(R) v7-M ARM Chapter B1.5 (Resets) - AIRCR register
 *
 * Note: This function is kept in nvic.c for backward compatibility.
 * For new code, consider using scb_system_reset() from armv7-m_scb.c
 */
void nvic_system_reset(void)
{
    scb_system_reset();
}

/*
 * ============================================================================
 * Backward Compatibility: SCB Functions
 * 向后兼容: SCB 函数
 *
 * These functions wrap armv7-m_scb.c implementations for backward compatibility.
 * For new code, use functions directly from armv7-m_scb.c
 * ============================================================================
 */

void scb_set_vtor(uint32_t offset)
{
    SCB_VTOR = offset;
    __DSB();
    __ISB();
}

uint32_t scb_get_vtor(void)
{
    return SCB_VTOR;
}

void scb_set_shpr(uint8_t handler, uint8_t priority)
{
    volatile uint8_t *shpr = (volatile uint8_t *)&SCB_SHPR1;
    if (handler < 12) {
        shpr[handler + 4] = priority;
    }
}

uint8_t scb_get_shpr(uint8_t handler)
{
    volatile uint8_t *shpr = (volatile uint8_t *)&SCB_SHPR1;
    if (handler < 12) {
        return shpr[handler + 4];
    }
    return 0;
}

void scb_enable_system_handler(uint32_t handler)
{
    SCB_SHCSR |= handler;
}

void scb_disable_system_handler(uint32_t handler)
{
    SCB_SHCSR &= ~handler;
}

uint32_t scb_get_system_handler_pending(uint32_t handler)
{
    return (SCB_SHCSR & handler) ? 1U : 0U;
}

void scb_set_system_handler_pending(uint32_t handler)
{
    if (handler == ICSR_NMIPENDSET_Msk) {
        SCB_ICSR = handler;
    } else if (handler == ICSR_PENDSVSET_Msk) {
        SCB_ICSR = handler;
    } else if (handler == ICSR_PENDSTSET_Msk) {
        SCB_ICSR = handler;
    }
}

void scb_clear_system_handler_pending(uint32_t handler)
{
    if (handler == ICSR_PENDSVCLR_Msk) {
        SCB_ICSR = handler;
    } else if (handler == ICSR_PENDSTCLR_Msk) {
        SCB_ICSR = handler;
    }
}

uint32_t scb_get_cfsr(void)
{
    return SCB_CFSR;
}

void scb_clear_cfsr(void)
{
    SCB_CFSR = 0xFFFFFFFF;
}

uint32_t scb_get_hfsr(void)
{
    return SCB_HFSR;
}

void scb_clear_hfsr(void)
{
    SCB_HFSR = 0xFFFFFFFF;
}

uint32_t scb_get_dfsr(void)
{
    return SCB_DFSR;
}

void scb_clear_dfsr(void)
{
    SCB_DFSR = 0xFFFFFFFF;
}

uint32_t scb_get_mmfar(void)
{
    return SCB_MMFAR;
}

uint32_t scb_get_bfar(void)
{
    return SCB_BFAR;
}

uint32_t scb_get_afsr(void)
{
    return SCB_AFSR;
}

void scb_set_afsr(uint32_t value)
{
    SCB_AFSR = value;
}

void scb_set_scr(uint32_t value)
{
    SCB_SCR = value;
}

uint32_t scb_get_scr(void)
{
    return SCB_SCR;
}

void scb_set_ccr(uint32_t value)
{
    SCB_CCR = value;
}

uint32_t scb_get_ccr(void)
{
    return SCB_CCR;
}

uint32_t scb_get_cpuid(void)
{
    return SCB_CPUID;
}

uint32_t scb_get_icsr(void)
{
    return SCB_ICSR;
}

void scb_set_icsr(uint32_t value)
{
    SCB_ICSR = value;
}

void scb_set_cpacr(uint32_t cp10, uint32_t cp11)
{
    uint32_t cpacr = SCB_CPACR;
    cpacr &= ~(CPACR_CP10_Msk | CPACR_CP11_Msk);
    cpacr |= ((cp10 << CPACR_CP10_Pos) | (cp11 << CPACR_CP11_Pos));
    SCB_CPACR = cpacr;
    __DSB();
    __ISB();
}

uint32_t scb_get_cpacr(void)
{
    return SCB_CPACR;
}

uint32_t scb_get_clidr(void)
{
    return SCB_CLIDR;
}

uint32_t scb_get_ctr(void)
{
    return SCB_CTR;
}

uint32_t scb_get_ccsidr(void)
{
    return SCB_CCSIDR;
}

void scb_set_csselr(uint32_t value)
{
    SCB_CSSELR = value;
}

uint32_t scb_get_csselr(void)
{
    return SCB_CSSELR;
}
