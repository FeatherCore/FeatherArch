/*
 * ARM Architecture - ARMv7-M NVIC Implementation
 *
 * ============================================================================
 * File: armv7-m_nvic.c
 * Description: ARMv7-M NVIC and SCB functions implementation
 * 描述: ARMv7-M NVIC 和 SCB 函数实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter A2: Application Level Programmers' Model
 *     * A2.4 Exceptions, faults and interrupts (page A2-33)
 *       - A2.4.1 System-related events
 *       - NVIC controls external interrupts (IRQ0+)
 *       - PendSV for deferred supervisor calls
 *       - Reference: Chapter A2.3.4 Privileged execution (page A2-32)
 *         * All exceptions execute as privileged code in Handler mode
 *         * Exception entry/exit automatically switches to Handler mode
 *   - Chapter A3: Arm Architecture Memory Model
 *     * A3.1 Address space (page A3-64)
 *       - Memory-mapped NVIC registers in SCS (System Control Space)
 *       - NVIC registers at 0xE000E100-0xE000E4EF
 *   - Chapter B3.4: Nested Vectored Interrupt Controller, NVIC
 *   - Chapter B3.2: System Control Space (SCS)
 *   - Table B3-4 Summary of SCB registers (page B3-596)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

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
 * Reference: Chapter A2.4 Exceptions, faults and interrupts (page A2-33)
 *   - A2.4.1 System-related events
 *   - NVIC controls external interrupts (IRQ0+)
 *   - Interrupts can be enabled/disabled individually
 *   - Reference: Chapter A2.3.4 Privileged execution (page A2-32)
 *     * Interrupt handlers execute in Handler mode with privileged access
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - ISER register
 */
void nvic_enable_irq(uint8_t irq) {
    if (irq < __ARM_NUM_INTERRUPTS) {
        uint32_t reg_idx = irq / 32;
        uint32_t bit_idx = irq % 32;
        NVIC_ISER(reg_idx) = (1UL << bit_idx);
    }
}

/**
 * @brief Disable specified interrupt
 * @param irq Interrupt number
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - ICER register
 */
void nvic_disable_irq(uint8_t irq) {
    if (irq < __ARM_NUM_INTERRUPTS) {
        uint32_t reg_idx = irq / 32;
        uint32_t bit_idx = irq % 32;
        NVIC_ICER(reg_idx) = (1UL << bit_idx);
    }
}

/**
 * @brief Get interrupt enable status
 * @param irq Interrupt number
 * @return 1 if enabled, 0 if disabled
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - ISER register
 */
uint32_t nvic_get_enable_irq(uint8_t irq) {
    if (irq < __ARM_NUM_INTERRUPTS) {
        uint32_t reg_idx = irq / 32;
        uint32_t bit_idx = irq % 32;
        return (NVIC_ISER(reg_idx) & (1UL << bit_idx)) ? 1U : 0U;
    }
    return 0U;
}

/**
 * @brief Set interrupt pending status
 * @param irq Interrupt number
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - ISPR register
 */
void nvic_set_pending(uint8_t irq) {
    if (irq < __ARM_NUM_INTERRUPTS) {
        uint32_t reg_idx = irq / 32;
        uint32_t bit_idx = irq % 32;
        NVIC_ISPR(reg_idx) = (1UL << bit_idx);
    }
}

/**
 * @brief Clear interrupt pending status
 * @param irq Interrupt number
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - ICPR register
 */
void nvic_clear_pending(uint8_t irq) {
    if (irq < __ARM_NUM_INTERRUPTS) {
        uint32_t reg_idx = irq / 32;
        uint32_t bit_idx = irq % 32;
        NVIC_ICPR(reg_idx) = (1UL << bit_idx);
    }
}

/**
 * @brief Get interrupt pending status
 * @param irq Interrupt number
 * @return 1 if pending, 0 if not pending
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - ISPR register
 */
uint32_t nvic_get_pending(uint8_t irq) {
    if (irq < __ARM_NUM_INTERRUPTS) {
        uint32_t reg_idx = irq / 32;
        uint32_t bit_idx = irq % 32;
        return (NVIC_ISPR(reg_idx) & (1UL << bit_idx)) ? 1U : 0U;
    }
    return 0U;
}

/**
 * @brief Get active interrupt status
 * @param irq Interrupt number
 * @return 1 if active, 0 if not active
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - IABR register
 */
uint32_t nvic_get_active(uint8_t irq) {
    if (irq < __ARM_NUM_INTERRUPTS) {
        uint32_t reg_idx = irq / 32;
        uint32_t bit_idx = irq % 32;
        return (NVIC_IABR(reg_idx) & (1UL << bit_idx)) ? 1U : 0U;
    }
    return 0U;
}

/**
 * @brief Set interrupt priority
 * @param irq Interrupt number
 * @param priority Priority value (0=highest, 255=lowest)
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - IPR register
 */
void nvic_set_priority(uint8_t irq, uint8_t priority) {
    if (irq < __ARM_NUM_INTERRUPTS) {
        NVIC_IPR(irq) = priority;
    }
}

/**
 * @brief Get interrupt priority
 * @param irq Interrupt number
 * @return Priority value
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - IPR register
 */
uint8_t nvic_get_priority(uint8_t irq) {
    if (irq < __ARM_NUM_INTERRUPTS) {
        return NVIC_IPR(irq);
    }
    return 0xFF;
}

/*
 * ============================================================================
 * Priority Grouping Functions
 * 优先级分组函数
 * Reference: Chapter B3.4 - Nested Vectored Interrupt Controller, NVIC
 * ============================================================================
 */

/**
 * @brief Set priority grouping
 * @param priority_group Priority grouping value (0-7)
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - AIRCR register
 */
void nvic_set_priority_grouping(uint32_t priority_group) {
    uint32_t aircr;
    priority_group &= 0x7UL;
    aircr = SCB_AIRCR;
    aircr &= ~(SCB_AIRCR_VECTKEY_Msk | SCB_AIRCR_PRIGROUP_Msk);
    aircr |= (SCB_AIRCR_VECTKEY_VALUE | (priority_group << SCB_AIRCR_PRIGROUP_Pos));
    SCB_AIRCR = aircr;
}

/**
 * @brief Get priority grouping
 * @return Priority grouping value
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller) - AIRCR register
 */
uint32_t nvic_get_priority_grouping(void) {
    return (SCB_AIRCR & SCB_AIRCR_PRIGROUP_Msk) >> SCB_AIRCR_PRIGROUP_Pos;
}

/**
 * @brief Encode priority
 * @param priority_group Priority grouping
 * @param preempt_priority Preemption priority
 * @param sub_priority Sub-priority
 * @return Encoded priority value
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller)
 */
uint32_t nvic_encode_priority(uint32_t priority_group, uint32_t preempt_priority, uint32_t sub_priority) {
    uint32_t preempt_bits = 7 - priority_group;
    uint32_t sub_bits = priority_group + 1;
    
    if (preempt_bits > __NVIC_PRIO_BITS) {
        preempt_bits = __NVIC_PRIO_BITS;
    }
    
    preempt_priority &= ((1UL << preempt_bits) - 1UL);
    sub_priority &= ((1UL << sub_bits) - 1UL);
    
    return ((preempt_priority << sub_bits) | sub_priority) << (8 - __NVIC_PRIO_BITS);
}

/**
 * @brief Decode priority
 * @param priority Encoded priority
 * @param priority_group Priority grouping
 * @param preempt_priority Output preemption priority
 * @param sub_priority Output sub-priority
 * Reference: Arm(R) v7-M ARM Chapter B3.4 (Nested Vectored Interrupt Controller)
 */
void nvic_decode_priority(uint32_t priority, uint32_t priority_group, uint32_t *preempt_priority, uint32_t *sub_priority) {
    uint32_t preempt_bits = 7 - priority_group;
    uint32_t sub_bits = priority_group + 1;
    
    if (preempt_bits > __NVIC_PRIO_BITS) {
        preempt_bits = __NVIC_PRIO_BITS;
    }
    
    priority >>= (8 - __NVIC_PRIO_BITS);
    
    if (preempt_priority) {
        *preempt_priority = (priority >> sub_bits) & ((1UL << preempt_bits) - 1UL);
    }
    if (sub_priority) {
        *sub_priority = priority & ((1UL << sub_bits) - 1UL);
    }
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
void nvic_system_reset(void) {
    scb_system_reset();
}

/**
 * @brief Set vector table offset
 * @param offset Vector table offset address
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - VTOR register
 * 
 * Note: This function is kept in nvic.c for backward compatibility.
 * For new code, use scb_set_vtor() from armv7-m_scb.c
 */
void scb_set_vtor(uint32_t offset) {
    SCB_VTOR = offset;
    __DSB();
    __ISB();
}

/**
 * @brief Get vector table offset
 * @return Vector table offset address
 * Reference: Arm(R) v7-M ARM Chapter B3.2 (System Control Space) - VTOR register
 * 
 * Note: This function is kept in nvic.c for backward compatibility.
 * For new code, use scb_get_vtor() from armv7-m_scb.c
 */
uint32_t scb_get_vtor(void) {
    return SCB_VTOR;
}

/*
 * ============================================================================
 * SCB System Handler Functions
 * SCB 系统处理函数
 * Reference: Chapter B3.2 - System Control Space (SCS)
 * 
 * Note: These functions are wrappers around armv7-m_scb.c implementations
 * for backward compatibility. For new code, use functions from armv7-m_scb.c
 * ============================================================================
 */

void scb_set_shpr(uint8_t handler, uint8_t priority) {
    volatile uint8_t *shpr = (volatile uint8_t *)&SCB_SHPR1;
    if (handler < 12) {
        shpr[handler + 4] = priority;
    }
}

uint8_t scb_get_shpr(uint8_t handler) {
    volatile uint8_t *shpr = (volatile uint8_t *)&SCB_SHPR1;
    if (handler < 12) {
        return shpr[handler + 4];
    }
    return 0;
}

void scb_enable_system_handler(uint32_t handler) {
    SCB_SHCSR |= handler;
}

void scb_disable_system_handler(uint32_t handler) {
    SCB_SHCSR &= ~handler;
}

uint32_t scb_get_system_handler_pending(uint32_t handler) {
    return (SCB_SHCSR & handler) ? 1U : 0U;
}

void scb_set_system_handler_pending(uint32_t handler) {
    if (handler == SCB_ICSR_NMIPENDSET_Msk) {
        SCB_ICSR = handler;
    } else if (handler == SCB_ICSR_PENDSVSET_Msk) {
        SCB_ICSR = handler;
    } else if (handler == SCB_ICSR_PENDSTSET_Msk) {
        SCB_ICSR = handler;
    }
}

void scb_clear_system_handler_pending(uint32_t handler) {
    if (handler == SCB_ICSR_PENDSVCLR_Msk) {
        SCB_ICSR = handler;
    } else if (handler == SCB_ICSR_PENDSTCLR_Msk) {
        SCB_ICSR = handler;
    }
}

/*
 * ============================================================================
 * SCB Fault Status Functions
 * SCB 故障状态函数
 * Reference: Chapter B3.2 - System Control Space (SCS)
 * ============================================================================
 */

uint32_t scb_get_cfsr(void) {
    return SCB_CFSR;
}

void scb_clear_cfsr(void) {
    SCB_CFSR = 0xFFFFFFFF;
}

uint32_t scb_get_hfsr(void) {
    return SCB_HFSR;
}

void scb_clear_hfsr(void) {
    SCB_HFSR = 0xFFFFFFFF;
}

uint32_t scb_get_dfsr(void) {
    return SCB_DFSR;
}

void scb_clear_dfsr(void) {
    SCB_DFSR = 0xFFFFFFFF;
}

uint32_t scb_get_mmfar(void) {
    return SCB_MMFAR;
}

uint32_t scb_get_bfar(void) {
    return SCB_BFAR;
}

uint32_t scb_get_afsr(void) {
    return SCB_AFSR;
}

void scb_set_afsr(uint32_t value) {
    SCB_AFSR = value;
}

/*
 * ============================================================================
 * SCB System Control Functions
 * SCB 系统控制函数
 * Reference: Chapter B3.2 - System Control Space (SCS)
 * ============================================================================
 */

void scb_set_scr(uint32_t value) {
    SCB_SCR = value;
}

uint32_t scb_get_scr(void) {
    return SCB_SCR;
}

void scb_set_ccr(uint32_t value) {
    SCB_CCR = value;
}

uint32_t scb_get_ccr(void) {
    return SCB_CCR;
}

uint32_t scb_get_cpuid(void) {
    return SCB_CPUID;
}

uint32_t scb_get_icsr(void) {
    return SCB_ICSR;
}

void scb_set_icsr(uint32_t value) {
    SCB_ICSR = value;
}

void scb_set_cpacr(uint32_t cp10, uint32_t cp11) {
    uint32_t cpacr = SCB_CPACR;
    cpacr &= ~(CPACR_CP10_Msk | CPACR_CP11_Msk);
    cpacr |= ((cp10 << CPACR_CP10_Pos) | (cp11 << CPACR_CP11_Pos));
    SCB_CPACR = cpacr;
    __DSB();
    __ISB();
}

uint32_t scb_get_cpacr(void) {
    return SCB_CPACR;
}

/*
 * ============================================================================
 * SCB Cache Control Functions
 * SCB 缓存控制函数
 * Reference: Chapter B3.2 - System Control Space (SCS)
 * ============================================================================
 */

uint32_t scb_get_clidr(void) {
    return SCB_CLIDR;
}

uint32_t scb_get_ctr(void) {
    return SCB_CTR;
}

uint32_t scb_get_ccsidr(void) {
    return SCB_CCSIDR;
}

void scb_set_csselr(uint32_t value) {
    SCB_CSSELR = value;
}

uint32_t scb_get_csselr(void) {
    return SCB_CSSELR;
}
