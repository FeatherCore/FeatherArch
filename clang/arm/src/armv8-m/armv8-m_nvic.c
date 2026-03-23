/*
 * ARM Architecture - ARMv8-M NVIC Implementation
 *
 * ============================================================================
 * File: armv8-m_nvic.c
 * Description: ARMv8-M NVIC functions implementation
 * 描述: ARMv8-M NVIC 函数实现
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B12: Nested Vectored Interrupt Controller
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 ARM Architecture Team. All rights reserved.
 */

#include "armv8-m/armv8-m_nvic.h"
#include "armv8-m/armv8-m_core.h"

/*
 * ============================================================================
 * NVIC Interrupt Control Functions
 * NVIC 中断控制函数
 * ============================================================================
 */

/**
 * @brief Enable specified interrupt
 * @param irq Interrupt number (0 to __ARM_NUM_INTERRUPTS-1)
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller) - ISER register
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
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller) - ICER register
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
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller) - ISER register
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
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller) - ISPR register
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
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller) - ICPR register
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
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller) - ISPR register
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
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller) - IABR register
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
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller) - IPR register
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
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller) - IPR register
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
 * ============================================================================
 */

/**
 * @brief Set priority grouping
 * @param priority_group Priority grouping value (0-7)
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller) - AIRCR register
 */
void nvic_set_priority_grouping(uint32_t priority_group) {
    uint32_t aircr;
    priority_group &= 0x7UL;
    aircr = SCB_AIRCR;
    aircr &= ~(SCB_AIRCR_VECTKEY_Msk | (0x7UL << 8));
    aircr |= (SCB_AIRCR_VECTKEY_VALUE | (priority_group << 8));
    SCB_AIRCR = aircr;
}

/**
 * @brief Get priority grouping
 * @return Priority grouping value
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller) - AIRCR register
 */
uint32_t nvic_get_priority_grouping(void) {
    return (SCB_AIRCR >> 8) & 0x7UL;
}

/**
 * @brief Encode priority
 * @param priority_group Priority grouping
 * @param preempt_priority Preemption priority
 * @param sub_priority Sub-priority
 * @return Encoded priority value
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 */
uint32_t nvic_encode_priority(uint32_t priority_group, uint32_t preempt_priority, uint32_t sub_priority) {
    uint32_t preempt_bits;
    uint32_t sub_bits;
    uint32_t priority;

    switch (priority_group) {
        case 0:
            preempt_bits = 0;
            sub_bits = __NVIC_PRIO_BITS;
            break;
        case 1:
            preempt_bits = 1;
            sub_bits = __NVIC_PRIO_BITS - 1;
            break;
        case 2:
            preempt_bits = 2;
            sub_bits = __NVIC_PRIO_BITS - 2;
            break;
        case 3:
            preempt_bits = 3;
            sub_bits = __NVIC_PRIO_BITS - 3;
            break;
        case 4:
            preempt_bits = 4;
            sub_bits = __NVIC_PRIO_BITS - 4;
            break;
        case 5:
            preempt_bits = 5;
            sub_bits = __NVIC_PRIO_BITS - 5;
            break;
        case 6:
            preempt_bits = 6;
            sub_bits = __NVIC_PRIO_BITS - 6;
            break;
        case 7:
        default:
            preempt_bits = __NVIC_PRIO_BITS;
            sub_bits = 0;
            break;
    }

    preempt_priority &= ((1UL << preempt_bits) - 1UL);
    sub_priority &= ((1UL << sub_bits) - 1UL);

    priority = (preempt_priority << sub_bits) | sub_priority;
    priority <<= (8 - __NVIC_PRIO_BITS);

    return priority;
}

/**
 * @brief Decode priority
 * @param priority Encoded priority
 * @param priority_group Priority grouping
 * @param preempt_priority Output preemption priority
 * @param sub_priority Output sub-priority
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 */
void nvic_decode_priority(uint32_t priority, uint32_t priority_group, uint32_t *preempt_priority, uint32_t *sub_priority) {
    uint32_t preempt_bits;
    uint32_t sub_bits;

    priority >>= (8 - __NVIC_PRIO_BITS);

    switch (priority_group) {
        case 0:
            preempt_bits = 0;
            sub_bits = __NVIC_PRIO_BITS;
            break;
        case 1:
            preempt_bits = 1;
            sub_bits = __NVIC_PRIO_BITS - 1;
            break;
        case 2:
            preempt_bits = 2;
            sub_bits = __NVIC_PRIO_BITS - 2;
            break;
        case 3:
            preempt_bits = 3;
            sub_bits = __NVIC_PRIO_BITS - 3;
            break;
        case 4:
            preempt_bits = 4;
            sub_bits = __NVIC_PRIO_BITS - 4;
            break;
        case 5:
            preempt_bits = 5;
            sub_bits = __NVIC_PRIO_BITS - 5;
            break;
        case 6:
            preempt_bits = 6;
            sub_bits = __NVIC_PRIO_BITS - 6;
            break;
        case 7:
        default:
            preempt_bits = __NVIC_PRIO_BITS;
            sub_bits = 0;
            break;
    }

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
 * ============================================================================
 */

/**
 * @brief System reset
 * Reference: Arm(R) v8-M ARM Chapter B1 (Resets) - AIRCR register
 */
void nvic_system_reset(void) {
    uint32_t aircr;
    __disable_interrupts();
    aircr = SCB_AIRCR;
    aircr &= ~SCB_AIRCR_VECTKEY_Msk;
    aircr |= SCB_AIRCR_VECTKEY_VALUE | SCB_AIRCR_SYSRESETREQ_Msk;
    SCB_AIRCR = aircr;
    __DSB();
    __ISB();
    while (1) {
        __NOP();
    }
}

/**
 * @brief Set vector table offset
 * @param offset Vector table offset address
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller) - VTOR register
 */
void scb_set_vtor(uint32_t offset) {
    SCB_VTOR = offset;
    __DSB();
    __ISB();
}

/**
 * @brief Get vector table offset
 * @return Vector table offset address
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller) - VTOR register
 */
uint32_t scb_get_vtor(void) {
    return SCB_VTOR;
}

/*
 * ============================================================================
 * TrustZone Non-Secure NVIC Functions
 * TrustZone 非安全 NVIC 函数
 * ============================================================================
 */

#if (__TZ_PRESENT == 1)

/**
 * @brief Enable specified interrupt (Non-Secure)
 * @param irq Interrupt number
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 */
void nvic_enable_irq_ns(uint8_t irq) {
    if (irq < __ARM_NUM_INTERRUPTS) {
        uint32_t reg_idx = irq / 32;
        uint32_t bit_idx = irq % 32;
        NVIC_NS_ISER(reg_idx) = (1UL << bit_idx);
    }
}

/**
 * @brief Disable specified interrupt (Non-Secure)
 * @param irq Interrupt number
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 */
void nvic_disable_irq_ns(uint8_t irq) {
    if (irq < __ARM_NUM_INTERRUPTS) {
        uint32_t reg_idx = irq / 32;
        uint32_t bit_idx = irq % 32;
        NVIC_NS_ICER(reg_idx) = (1UL << bit_idx);
    }
}

/**
 * @brief Set interrupt pending status (Non-Secure)
 * @param irq Interrupt number
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 */
void nvic_set_pending_ns(uint8_t irq) {
    if (irq < __ARM_NUM_INTERRUPTS) {
        uint32_t reg_idx = irq / 32;
        uint32_t bit_idx = irq % 32;
        NVIC_NS_ISPR(reg_idx) = (1UL << bit_idx);
    }
}

/**
 * @brief Clear interrupt pending status (Non-Secure)
 * @param irq Interrupt number
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 */
void nvic_clear_pending_ns(uint8_t irq) {
    if (irq < __ARM_NUM_INTERRUPTS) {
        uint32_t reg_idx = irq / 32;
        uint32_t bit_idx = irq % 32;
        NVIC_NS_ICPR(reg_idx) = (1UL << bit_idx);
    }
}

/**
 * @brief Get interrupt pending status (Non-Secure)
 * @param irq Interrupt number
 * @return 1 if pending, 0 if not pending
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 */
uint32_t nvic_get_pending_ns(uint8_t irq) {
    if (irq < __ARM_NUM_INTERRUPTS) {
        uint32_t reg_idx = irq / 32;
        uint32_t bit_idx = irq % 32;
        return (NVIC_NS_ISPR(reg_idx) & (1UL << bit_idx)) ? 1U : 0U;
    }
    return 0U;
}

/**
 * @brief Get active interrupt status (Non-Secure)
 * @param irq Interrupt number
 * @return 1 if active, 0 if not active
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 */
uint32_t nvic_get_active_ns(uint8_t irq) {
    if (irq < __ARM_NUM_INTERRUPTS) {
        uint32_t reg_idx = irq / 32;
        uint32_t bit_idx = irq % 32;
        return (NVIC_NS_IABR(reg_idx) & (1UL << bit_idx)) ? 1U : 0U;
    }
    return 0U;
}

/**
 * @brief Set interrupt priority (Non-Secure)
 * @param irq Interrupt number
 * @param priority Priority value
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 */
void nvic_set_priority_ns(uint8_t irq, uint8_t priority) {
    if (irq < __ARM_NUM_INTERRUPTS) {
        NVIC_NS_IPR(irq) = priority;
    }
}

/**
 * @brief Get interrupt priority (Non-Secure)
 * @param irq Interrupt number
 * @return Priority value
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 */
uint8_t nvic_get_priority_ns(uint8_t irq) {
    if (irq < __ARM_NUM_INTERRUPTS) {
        return NVIC_NS_IPR(irq);
    }
    return 0xFF;
}

/**
 * @brief Set priority grouping (Non-Secure)
 * @param priority_group Priority grouping value (0-7)
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 */
void nvic_set_priority_grouping_ns(uint32_t priority_group) {
    uint32_t aircr;
    priority_group &= 0x7UL;
    aircr = SCB_NS_AIRCR;
    aircr &= ~(SCB_AIRCR_VECTKEY_Msk | (0x7UL << 8));
    aircr |= (SCB_AIRCR_VECTKEY_VALUE | (priority_group << 8));
    SCB_NS_AIRCR = aircr;
}

/**
 * @brief Get priority grouping (Non-Secure)
 * @return Priority grouping value
 * Reference: Arm(R) v8-M ARM Chapter B12 (Nested Vectored Interrupt Controller)
 */
uint32_t nvic_get_priority_grouping_ns(void) {
    return (SCB_NS_AIRCR >> 8) & 0x7UL;
}

#endif /* __TZ_PRESENT */
