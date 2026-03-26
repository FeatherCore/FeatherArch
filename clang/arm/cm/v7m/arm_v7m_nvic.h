/*
 * arm_v7m_nvic.h
 * Nested Vectored Interrupt Controller (NVIC) Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.4
 */

#ifndef ARM_V7M_NVIC_H
#define ARM_V7M_NVIC_H

#include <stdint.h>
#include "arm_v7m_scb.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * NVIC Base Address (Architecture defined)
 * Reference: ARMv7-M Architecture Reference Manual, Table B3-8
 *============================================================================*/
#define NVIC_BASE           0xE000E100UL
#define ICTR_BASE           0xE000E004UL
#define STIR_BASE           0xE000EF00UL

/*============================================================================*
 * Interrupt Number Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.5
 *============================================================================*/

/* Cortex-M 内部异常号 (异常号 1-15) */
typedef enum {
    /* 异常号 0 保留 */
    NonMaskableInt_IRQn     = -14,    /*!< 2  Non Maskable Interrupt              */
    HardFault_IRQn          = -13,    /*!< 3  Hard Fault Interrupt                */
    MemoryManagement_IRQn   = -12,    /*!< 4  Memory Management Interrupt         */
    BusFault_IRQn           = -11,    /*!< 5  Bus Fault Interrupt                 */
    UsageFault_IRQn         = -10,    /*!< 6  Usage Fault Interrupt               */
    /* 异常号 7-10 保留 */
    SVCall_IRQn             = -5,     /*!< 11 SV Call Interrupt                   */
    DebugMonitor_IRQn       = -4,     /*!< 12 Debug Monitor Interrupt             */
    /* 异常号 13 保留 */
    PendSV_IRQn             = -2,     /*!< 14 Pend SV Interrupt                   */
    SysTick_IRQn            = -1,     /*!< 15 System Tick Interrupt               */
    /* 外部中断从 0 开始对应异常号 16 */
} arm_v7m_exception_t;

/* 外部中断号范围: 0 - 495 (对应异常号 16 - 511) */
#define NVIC_MIN_IRQN               0U
#define NVIC_MAX_IRQN               495U
#define NVIC_NUM_IRQN               496U

/* 中断号与异常号转换宏 */
#define NVIC_IRQn_TO_EXCNUM(irqn)   ((int32_t)(irqn) + 16)
#define NVIC_EXCNUM_TO_IRQn(excnum) ((uint32_t)(excnum) - 16U)

/*============================================================================*
 * Internal Helper Macros
 *============================================================================*/

/**
 * @brief Calculate the register index for a given interrupt number
 * Each register (ISER, ICER, etc.) manages 32 interrupts
 */
#define NVIC_REG_INDEX(irqn)        ((irqn) >> 5U)

/**
 * @brief Calculate the bit position within a register for a given interrupt number
 */
#define NVIC_BIT_POS(irqn)          ((irqn) & 0x1FU)

/**
 * @brief Calculate the IPR register index for a given interrupt number
 * Each IPR register manages 4 interrupts (4 x 8-bit priority fields)
 */
#define NVIC_IPR_INDEX(irqn)        ((irqn) >> 2U)

/**
 * @brief Calculate the byte position within an IPR register for a given interrupt number
 * Each interrupt has an 8-bit priority field within the 32-bit IPR register
 */
#define NVIC_IPR_BYTE_POS(irqn)     (((irqn) & 0x03U) * 8U)

/*============================================================================*
 * ICTR (Interrupt Controller Type Register) Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.24
 * Address: 0xE000E004
 *============================================================================*/
#define ICTR                ((volatile uint32_t *)ICTR_BASE)

/* ICTR Register Bits */
#define ICTR_INTLINESNUM_Pos        0U
#define ICTR_INTLINESNUM_Msk        (0xFUL << ICTR_INTLINESNUM_Pos)

/*============================================================================*
 * STIR (Software Triggered Interrupt Register) Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.26
 * Address: 0xE000EF00
 *============================================================================*/
#define STIR                ((volatile uint32_t *)STIR_BASE)

/* STIR Register Bits */
#define STIR_INTID_Pos              0U
#define STIR_INTID_Msk              (0x1FFUL << STIR_INTID_Pos)

/*============================================================================*
 * NVIC Type Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Table B3-8
 *============================================================================*/

typedef struct {
    /* Interrupt Set-Enable Registers: 0xE000E100 - 0xE000E13C */
    volatile uint32_t ISER[16];
    /* Reserved: 0xE000E140 - 0xE000E17C */
    uint32_t RESERVED0[16];
    /* Interrupt Clear-Enable Registers: 0xE000E180 - 0xE000E1BC */
    volatile uint32_t ICER[16];
    /* Reserved: 0xE000E1C0 - 0xE000E1FC */
    uint32_t RESERVED1[16];
    /* Interrupt Set-Pending Registers: 0xE000E200 - 0xE000E23C */
    volatile uint32_t ISPR[16];
    /* Reserved: 0xE000E240 - 0xE000E27C */
    uint32_t RESERVED2[16];
    /* Interrupt Clear-Pending Registers: 0xE000E280 - 0xE000E2BC */
    volatile uint32_t ICPR[16];
    /* Reserved: 0xE000E2C0 - 0xE000E2FC */
    uint32_t RESERVED3[16];
    /* Interrupt Active Bit Registers: 0xE000E300 - 0xE000E33C */
    volatile uint32_t IABR[16];
    /* Reserved: 0xE000E340 - 0xE000E3FC */
    uint32_t RESERVED4[16];
    /* Interrupt Priority Registers: 0xE000E400 - 0xE000E5EC */
    /* Each IPR register holds 4 priority fields (8-bit each) for 4 interrupts */
    volatile uint32_t IPR[124];
} arm_v7m_nvic_regs_t;

#define NVIC                ((arm_v7m_nvic_regs_t *)NVIC_BASE)

/*============================================================================*
 * Inline Functions - Basic Interrupt Control
 * These are simple register operations suitable for inlining
 *============================================================================*/

/**
 * @brief Enable an external interrupt
 * @param irqn External interrupt number (0-495)
 */
static inline void arm_v7m_nvic_enable_irq(uint32_t irqn)
{
    if (irqn <= NVIC_MAX_IRQN) {
        NVIC->ISER[NVIC_REG_INDEX(irqn)] = (1UL << NVIC_BIT_POS(irqn));
    }
}

/**
 * @brief Disable an external interrupt
 * @param irqn External interrupt number (0-495)
 */
static inline void arm_v7m_nvic_disable_irq(uint32_t irqn)
{
    if (irqn <= NVIC_MAX_IRQN) {
        NVIC->ICER[NVIC_REG_INDEX(irqn)] = (1UL << NVIC_BIT_POS(irqn));
    }
}

/**
 * @brief Get the enable status of an external interrupt
 * @param irqn External interrupt number (0-495)
 * @return 1 if enabled, 0 if disabled
 */
static inline uint32_t arm_v7m_nvic_get_enable_irq(uint32_t irqn)
{
    return (irqn <= NVIC_MAX_IRQN) ?
        ((NVIC->ISER[NVIC_REG_INDEX(irqn)] >> NVIC_BIT_POS(irqn)) & 1UL) : 0U;
}

/**
 * @brief Get the pending status of an external interrupt
 * @param irqn External interrupt number (0-495)
 * @return 1 if pending, 0 if not pending
 */
static inline uint32_t arm_v7m_nvic_get_pending_irq(uint32_t irqn)
{
    return (irqn <= NVIC_MAX_IRQN) ?
        ((NVIC->ISPR[NVIC_REG_INDEX(irqn)] >> NVIC_BIT_POS(irqn)) & 1UL) : 0U;
}

/**
 * @brief Set an external interrupt to pending state
 * @param irqn External interrupt number (0-495)
 */
static inline void arm_v7m_nvic_set_pending_irq(uint32_t irqn)
{
    if (irqn <= NVIC_MAX_IRQN) {
        NVIC->ISPR[NVIC_REG_INDEX(irqn)] = (1UL << NVIC_BIT_POS(irqn));
    }
}

/**
 * @brief Clear the pending status of an external interrupt
 * @param irqn External interrupt number (0-495)
 */
static inline void arm_v7m_nvic_clear_pending_irq(uint32_t irqn)
{
    if (irqn <= NVIC_MAX_IRQN) {
        NVIC->ICPR[NVIC_REG_INDEX(irqn)] = (1UL << NVIC_BIT_POS(irqn));
    }
}

/**
 * @brief Get the active status of an external interrupt
 * @param irqn External interrupt number (0-495)
 * @return 1 if active, 0 if not active
 */
static inline uint32_t arm_v7m_nvic_get_active_irq(uint32_t irqn)
{
    return (irqn <= NVIC_MAX_IRQN) ?
        ((NVIC->IABR[NVIC_REG_INDEX(irqn)] >> NVIC_BIT_POS(irqn)) & 1UL) : 0U;
}

/*============================================================================*
 * Inline Functions - Priority Management (Simple Operations)
 *============================================================================*/

/**
 * @brief Set the priority of an external interrupt
 * @param irqn External interrupt number (0-495)
 * @param priority Priority value (0-255, lower value = higher priority)
 */
static inline void arm_v7m_nvic_set_priority(uint32_t irqn, uint32_t priority)
{
    if (irqn <= NVIC_MAX_IRQN) {
        uint32_t ipr_idx = NVIC_IPR_INDEX(irqn);
        uint32_t byte_pos = NVIC_IPR_BYTE_POS(irqn);
        uint32_t mask = 0xFFUL << byte_pos;
        
        NVIC->IPR[ipr_idx] = (NVIC->IPR[ipr_idx] & ~mask) | 
                             ((priority & 0xFFUL) << byte_pos);
    }
}

/**
 * @brief Get the priority of an external interrupt
 * @param irqn External interrupt number (0-495)
 * @return Priority value (0-255)
 */
static inline uint32_t arm_v7m_nvic_get_priority(uint32_t irqn)
{
    return (irqn <= NVIC_MAX_IRQN) ?
        ((NVIC->IPR[NVIC_IPR_INDEX(irqn)] >> NVIC_IPR_BYTE_POS(irqn)) & 0xFFUL) : 0U;
}

/*============================================================================*
 * Inline Functions - System Information
 *============================================================================*/

/**
 * @brief Get the number of implemented external interrupts
 * @return Number of interrupts (32-496, in steps of 32)
 */
static inline uint32_t arm_v7m_nvic_get_irq_count(void)
{
    return (((*ICTR & ICTR_INTLINESNUM_Msk) >> ICTR_INTLINESNUM_Pos) + 1U) * 32U;
}

/**
 * @brief Trigger an external interrupt using STIR
 * @param irqn External interrupt number (0-495)
 */
static inline void arm_v7m_nvic_trigger_irq_stir(uint32_t irqn)
{
    if (irqn <= NVIC_MAX_IRQN) {
        *STIR = irqn & STIR_INTID_Msk;
    }
}

/*============================================================================*
 * Inline Functions - Global Interrupt Control
 *============================================================================*/

/**
 * @brief Disable all interrupts globally
 * @note Sets PRIMASK
 */
static inline void arm_v7m_nvic_disable_all_irqs(void)
{
    __asm__ volatile ("cpsid i" ::: "memory");
}

/**
 * @brief Enable all interrupts globally
 * @note Clears PRIMASK
 */
static inline void arm_v7m_nvic_enable_all_irqs(void)
{
    __asm__ volatile ("cpsie i" ::: "memory");
}

/**
 * @brief Get global interrupt enable state
 * @return 1 if interrupts are enabled, 0 if disabled
 */
static inline uint32_t arm_v7m_nvic_get_all_irqs_enabled(void)
{
    uint32_t primask;
    __asm__ volatile ("mrs %0, primask" : "=r" (primask));
    return (primask == 0U) ? 1U : 0U;
}

/*============================================================================*
 * Non-Inline Functions - Complex Operations
 * These functions are implemented in the source file
 *============================================================================*/

/**
 * @brief Enable multiple interrupts in a single operation
 * @param irqn_array Array of interrupt numbers
 * @param count Number of interrupts in the array
 */
void arm_v7m_nvic_enable_irq_batch(const uint32_t *irqn_array, uint32_t count);

/**
 * @brief Disable multiple interrupts in a single operation
 * @param irqn_array Array of interrupt numbers
 * @param count Number of interrupts in the array
 */
void arm_v7m_nvic_disable_irq_batch(const uint32_t *irqn_array, uint32_t count);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_NVIC_H */
