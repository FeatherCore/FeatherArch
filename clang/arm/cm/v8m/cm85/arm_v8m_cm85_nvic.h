/**
 * @file arm_v8m_cm85_nvic.h
 * @brief Cortex-M85 Nested Vectored Interrupt Controller (NVIC)
 *
 * @note Reference: Arm Cortex-M85 Devices Generic User Guide, Chapter 5.2
 * @note Reference: Arm Cortex-M85 Processor TRM, Chapter 12
 */

#ifndef ARM_V8M_CM85_NVIC_H
#define ARM_V8M_CM85_NVIC_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* NVIC interrupt number type */
typedef enum {
    /* Cortex-M85 processor exceptions */
    ARM_V8M_CM85_NVIC_NONMASKABLEINT_IRQn   = -14,
    ARM_V8M_CM85_NVIC_HARDFAULT_IRQn        = -13,
    ARM_V8M_CM85_NVIC_MEMMANAGE_IRQn        = -12,
    ARM_V8M_CM85_NVIC_BUSFAULT_IRQn         = -11,
    ARM_V8M_CM85_NVIC_USAGEFAULT_IRQn       = -10,
    ARM_V8M_CM85_NVIC_SECUREFAULT_IRQn      = -9,
    ARM_V8M_CM85_NVIC_SVCALL_IRQn           = -5,
    ARM_V8M_CM85_NVIC_DEBUGMONITOR_IRQn     = -4,
    ARM_V8M_CM85_NVIC_PENDSV_IRQn           = -2,
    ARM_V8M_CM85_NVIC_SYSTICK_IRQn          = -1,
    /* External interrupts start at 0 */
    ARM_V8M_CM85_NVIC_EXTI0_IRQn            = 0,
    /* TODO: Add device-specific external interrupt definitions */
} arm_v8m_cm85_nvic_irqn_t;

/* NVIC configuration structure */
typedef struct {
    uint32_t irqn;
    uint32_t priority;
    bool enable;
} arm_v8m_cm85_nvic_config_t;

/* NVIC initialization and configuration */
int arm_v8m_cm85_nvic_init(void);
void arm_v8m_cm85_nvic_deinit(void);

/* Interrupt enable/disable */
void arm_v8m_cm85_nvic_enable_irq(arm_v8m_cm85_nvic_irqn_t irqn);
void arm_v8m_cm85_nvic_disable_irq(arm_v8m_cm85_nvic_irqn_t irqn);
bool arm_v8m_cm85_nvic_is_enabled(arm_v8m_cm85_nvic_irqn_t irqn);

/* Interrupt pending status */
void arm_v8m_cm85_nvic_set_pending(arm_v8m_cm85_nvic_irqn_t irqn);
void arm_v8m_cm85_nvic_clear_pending(arm_v8m_cm85_nvic_irqn_t irqn);
bool arm_v8m_cm85_nvic_is_pending(arm_v8m_cm85_nvic_irqn_t irqn);
bool arm_v8m_cm85_nvic_is_active(arm_v8m_cm85_nvic_irqn_t irqn);

/* Interrupt priority */
void arm_v8m_cm85_nvic_set_priority(arm_v8m_cm85_nvic_irqn_t irqn, uint32_t priority);
uint32_t arm_v8m_cm85_nvic_get_priority(arm_v8m_cm85_nvic_irqn_t irqn);

/* Priority grouping */
typedef enum {
    ARM_V8M_CM85_NVIC_PRIO_GROUP_0 = 0,  /* 0 bits for pre-emption, 8 for subpriority */
    ARM_V8M_CM85_NVIC_PRIO_GROUP_1 = 1,  /* 1 bits for pre-emption, 7 for subpriority */
    ARM_V8M_CM85_NVIC_PRIO_GROUP_2 = 2,  /* 2 bits for pre-emption, 6 for subpriority */
    ARM_V8M_CM85_NVIC_PRIO_GROUP_3 = 3,  /* 3 bits for pre-emption, 5 for subpriority */
    ARM_V8M_CM85_NVIC_PRIO_GROUP_4 = 4,  /* 4 bits for pre-emption, 4 for subpriority */
    ARM_V8M_CM85_NVIC_PRIO_GROUP_5 = 5,  /* 5 bits for pre-emption, 3 for subpriority */
    ARM_V8M_CM85_NVIC_PRIO_GROUP_6 = 6,  /* 6 bits for pre-emption, 2 for subpriority */
    ARM_V8M_CM85_NVIC_PRIO_GROUP_7 = 7   /* 7 bits for pre-emption, 1 for subpriority */
} arm_v8m_cm85_nvic_prio_group_t;

void arm_v8m_cm85_nvic_set_priority_grouping(arm_v8m_cm85_nvic_prio_group_t group);
arm_v8m_cm85_nvic_prio_group_t arm_v8m_cm85_nvic_get_priority_grouping(void);

/* Encode/decode priority values */
uint32_t arm_v8m_cm85_nvic_encode_priority(arm_v8m_cm85_nvic_prio_group_t group, 
                                    uint32_t preempt_prio, 
                                    uint32_t sub_prio);
void arm_v8m_cm85_nvic_decode_priority(uint32_t priority, 
                                arm_v8m_cm85_nvic_prio_group_t group,
                                uint32_t *preempt_prio, 
                                uint32_t *sub_prio);

/* System reset */
void arm_v8m_cm85_nvic_system_reset(void);

/* Secure/Non-secure NVIC access (when TrustZone is implemented) */
#ifdef __ARM_FEATURE_CMSE
void arm_v8m_cm85_nvic_enable_irq_ns(arm_v8m_cm85_nvic_irqn_t irqn);
void arm_v8m_cm85_nvic_disable_irq_ns(arm_v8m_cm85_nvic_irqn_t irqn);
void arm_v8m_cm85_nvic_set_priority_ns(arm_v8m_cm85_nvic_irqn_t irqn, uint32_t priority);
uint32_t arm_v8m_cm85_nvic_get_priority_ns(arm_v8m_cm85_nvic_irqn_t irqn);
#endif

/* NVIC register structure - TODO: Define based on implementation */
typedef struct {
    volatile uint32_t ISER[16];      /* Interrupt Set Enable Registers */
    uint32_t RESERVED0[16];
    volatile uint32_t ICER[16];      /* Interrupt Clear Enable Registers */
    uint32_t RESERVED1[16];
    volatile uint32_t ISPR[16];      /* Interrupt Set Pending Registers */
    uint32_t RESERVED2[16];
    volatile uint32_t ICPR[16];      /* Interrupt Clear Pending Registers */
    uint32_t RESERVED3[16];
    volatile uint32_t IABR[16];      /* Interrupt Active Bit Registers */
    uint32_t RESERVED4[48];
    volatile uint32_t IPR[124];      /* Interrupt Priority Registers */
    uint32_t RESERVED5[696];
    volatile uint32_t STIR;          /* Software Trigger Interrupt Register */
} arm_v8m_cm85_nvic_reg_t;

#define ARM_V8M_CM85_NVIC_BASE      (0xE000E100UL)
#define ARM_V8M_CM85_NVIC           ((arm_v8m_cm85_nvic_reg_t *)ARM_V8M_CM85_NVIC_BASE)

/* Priority bits implemented (Cortex-M85 implements 8 bits) */
#define ARM_V8M_CM85_NVIC_PRIO_BITS     8
#define ARM_V8M_CM85_NVIC_PRIO_MASK     ((1UL << ARM_V8M_CM85_NVIC_PRIO_BITS) - 1)

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM85_NVIC_H */
