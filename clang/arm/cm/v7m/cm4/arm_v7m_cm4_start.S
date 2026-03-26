/**
 * @file arm_v7m_cm4_start.S
 * @brief Cortex-M4 specific startup code
 *
 * Cortex-M4 features:
 * - ARMv7-M architecture
 * - DSP instructions
 * - Optional single-precision FPU
 */

#ifndef ARM_V7M_CM4_START_S
#define ARM_V7M_CM4_START_S

/* ============================================================================
 * Cortex-M4 Specific Initialization
 * ============================================================================
 */

    .syntax unified
    .arch armv7e-m
    .fpu softvfp
    .thumb

/* ============================================================================
 * CM4 Vector Table Extensions
 * ============================================================================
 * Extend the base ARMv7-M vector table with CM4-specific interrupt handlers
 */

    .section .vectors.cm4, "ax"
    .align 2

    /* External Interrupts 0-15 (CM4 specific) */
    .word WWDG_IRQHandler
    .word PVD_IRQHandler
    .word TAMP_STAMP_IRQHandler
    .word RTC_WKUP_IRQHandler
    .word FLASH_IRQHandler
    .word RCC_IRQHandler
    .word EXTI0_IRQHandler
    .word EXTI1_IRQHandler
    .word EXTI2_IRQHandler
    .word EXTI3_IRQHandler
    .word EXTI4_IRQHandler
    .word DMA1_Stream0_IRQHandler
    .word DMA1_Stream1_IRQHandler
    .word DMA1_Stream2_IRQHandler
    .word DMA1_Stream3_IRQHandler
    .word DMA1_Stream4_IRQHandler

/* ============================================================================
 * CM4 System Initialization
 * ============================================================================
 */

    .section .text.arm_v7m_cm4_init
    .align 2
    .globl ARM_V7M_CM4_Init
    .type ARM_V7M_CM4_Init, %function

ARM_V7M_CM4_Init:
    /* Push link register */
    push {lr}

    /* Enable FPU if present */
    bl ARM_V7M_CM4_EnableFPU

    /* Configure NVIC priority grouping */
    /* Default: 4 bits for preemption, 0 bits for subpriority */
    ldr r0, =0xE000ED0C       /* SCB->AIRCR address */
    ldr r1, =0x05FA0000       /* VECTKEY value */
    orr r1, r1, #0x00000300   /* PRIGROUP = 3 (4 bits preemption) */
    str r1, [r0]

    /* Enable fault handlers */
    ldr r0, =0xE000ED24       /* SCB->SHCSR address */
    ldr r1, [r0]
    orr r1, r1, #0x00070000   /* Enable MemFault, BusFault, UsageFault */
    str r1, [r0]

    /* Pop link register and return */
    pop {pc}

    .size ARM_V7M_CM4_Init, . - ARM_V7M_CM4_Init

/* ============================================================================
 * CM4 FPU Initialization
 * ============================================================================
 */

    .section .text.arm_v7m_cm4_fpu
    .align 2
    .type ARM_V7M_CM4_EnableFPU, %function

ARM_V7M_CM4_EnableFPU:
    /* Check if FPU is present by reading CPACR */
    ldr r0, =0xE000ED88       /* CPACR address */
    ldr r1, [r0]

    /* Enable CP10 and CP11 (FPU coprocessors) */
    orr r1, r1, #0x00F00000   /* Set CP10 and CP11 full access */
    str r1, [r0]

    /* Barrier instructions to ensure FPU is enabled */
    dsb
    isb

    bx lr

    .size ARM_V7M_CM4_EnableFPU, . - ARM_V7M_CM4_EnableFPU

/* ============================================================================
 * CM4 Default Interrupt Handlers
 * ============================================================================
 */

    .section .text.arm_v7m_cm4_handlers, "ax"
    .align 2

    .weak WWDG_IRQHandler
    .type WWDG_IRQHandler, %function
WWDG_IRQHandler:
    b WWDG_IRQHandler

    .weak PVD_IRQHandler
    .type PVD_IRQHandler, %function
PVD_IRQHandler:
    b PVD_IRQHandler

    .weak TAMP_STAMP_IRQHandler
    .type TAMP_STAMP_IRQHandler, %function
TAMP_STAMP_IRQHandler:
    b TAMP_STAMP_IRQHandler

    .weak RTC_WKUP_IRQHandler
    .type RTC_WKUP_IRQHandler, %function
RTC_WKUP_IRQHandler:
    b RTC_WKUP_IRQHandler

    .weak FLASH_IRQHandler
    .type FLASH_IRQHandler, %function
FLASH_IRQHandler:
    b FLASH_IRQHandler

    .weak RCC_IRQHandler
    .type RCC_IRQHandler, %function
RCC_IRQHandler:
    b RCC_IRQHandler

    .weak EXTI0_IRQHandler
    .type EXTI0_IRQHandler, %function
EXTI0_IRQHandler:
    b EXTI0_IRQHandler

    .weak EXTI1_IRQHandler
    .type EXTI1_IRQHandler, %function
EXTI1_IRQHandler:
    b EXTI1_IRQHandler

    .weak EXTI2_IRQHandler
    .type EXTI2_IRQHandler, %function
EXTI2_IRQHandler:
    b EXTI2_IRQHandler

    .weak EXTI3_IRQHandler
    .type EXTI3_IRQHandler, %function
EXTI3_IRQHandler:
    b EXTI3_IRQHandler

    .weak EXTI4_IRQHandler
    .type EXTI4_IRQHandler, %function
EXTI4_IRQHandler:
    b EXTI4_IRQHandler

    .weak DMA1_Stream0_IRQHandler
    .type DMA1_Stream0_IRQHandler, %function
DMA1_Stream0_IRQHandler:
    b DMA1_Stream0_IRQHandler

    .weak DMA1_Stream1_IRQHandler
    .type DMA1_Stream1_IRQHandler, %function
DMA1_Stream1_IRQHandler:
    b DMA1_Stream1_IRQHandler

    .weak DMA1_Stream2_IRQHandler
    .type DMA1_Stream2_IRQHandler, %function
DMA1_Stream2_IRQHandler:
    b DMA1_Stream2_IRQHandler

    .weak DMA1_Stream3_IRQHandler
    .type DMA1_Stream3_IRQHandler, %function
DMA1_Stream3_IRQHandler:
    b DMA1_Stream3_IRQHandler

    .weak DMA1_Stream4_IRQHandler
    .type DMA1_Stream4_IRQHandler, %function
DMA1_Stream4_IRQHandler:
    b DMA1_Stream4_IRQHandler

#endif /* ARM_V7M_CM4_START_S */
