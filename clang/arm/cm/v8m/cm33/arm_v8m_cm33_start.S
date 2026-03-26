/**
 * @file arm_v8m_cm33_start.S
 * @brief Cortex-M33 specific startup code
 *
 * Cortex-M33 features:
 * - ARMv8-M architecture with Main Extension
 * - TrustZone Security Extension
 * - Optional FPU
 * - Optional CDE (Custom Datapath Extension)
 * - Stack limit checking (PSPLIM/MSPLIM)
 */

#ifndef ARM_V8M_CM33_START_S
#define ARM_V8M_CM33_START_S

/* ============================================================================
 * Cortex-M33 Specific Initialization
 * ============================================================================
 */

    .syntax unified
    .arch armv8-m.main
    .thumb

/* ============================================================================
 * CM33 Vector Table Extensions
 * ============================================================================
 */

    .section .vectors.cm33, "ax"
    .align 2

    /* External Interrupts 0-15 (CM33 specific) */
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
    .word DMA1_Channel0_IRQHandler
    .word DMA1_Channel1_IRQHandler
    .word DMA1_Channel2_IRQHandler
    .word DMA1_Channel3_IRQHandler
    .word DMA1_Channel4_IRQHandler

/* ============================================================================
 * CM33 System Initialization
 * ============================================================================
 */

    .section .text.arm_v8m_cm33_init
    .align 2
    .globl ARM_V8M_CM33_Init
    .type ARM_V8M_CM33_Init, %function

ARM_V8M_CM33_Init:
    /* Push link register */
    push {lr}

    /* Initialize stack limit registers */
    movs r0, #0
    msr psplim, r0
    msr msplim, r0

    /* Enable FPU if present */
    bl ARM_V8M_CM33_EnableFPU

    /* Configure NVIC priority grouping */
    ldr r0, =0xE000ED0C       /* SCB->AIRCR address */
    ldr r1, =0x05FA0000       /* VECTKEY value */
    orr r1, r1, #0x00000300   /* PRIGROUP = 3 (4 bits preemption) */
    str r1, [r0]

    /* Enable fault handlers including SecureFault */
    ldr r0, =0xE000ED24       /* SCB->SHCSR address */
    ldr r1, [r0]
    orr r1, r1, #0x000F0000   /* Enable MemFault, BusFault, UsageFault, SecureFault */
    str r1, [r0]

    /* Initialize TrustZone if in secure state */
    bl ARM_V8M_CM33_InitTrustZone

    /* Pop link register and return */
    pop {pc}

    .size ARM_V8M_CM33_Init, . - ARM_V8M_CM33_Init

/* ============================================================================
 * CM33 FPU Initialization
 * ============================================================================
 */

    .section .text.arm_v8m_cm33_fpu
    .align 2
    .type ARM_V8M_CM33_EnableFPU, %function

ARM_V8M_CM33_EnableFPU:
    /* Enable CP10 and CP11 (FPU coprocessors) */
    ldr r0, =0xE000ED88       /* CPACR address */
    ldr r1, [r0]
    orr r1, r1, #0x00F00000   /* Set CP10 and CP11 full access */
    str r1, [r0]

    /* Barrier instructions */
    dsb
    isb

    bx lr

    .size ARM_V8M_CM33_EnableFPU, . - ARM_V8M_CM33_EnableFPU

/* ============================================================================
 * CM33 TrustZone Initialization
 * ============================================================================
 */

    .section .text.arm_v8m_cm33_tz
    .align 2
    .type ARM_V8M_CM33_InitTrustZone, %function

ARM_V8M_CM33_InitTrustZone:
    /* Check if running in secure state */
    mrs r0, control
    tst r0, #0x02
    bne .L_tz_done            /* Skip if in non-secure state */

    /* Secure initialization:
     * - Configure SAU (Security Attribution Unit)
     * - Configure IDAU (Implementation Defined Attribution Unit)
     * - Configure secure/non-secure interrupts
     */

    /* Enable SAU */
    ldr r0, =0xE000EDD0       /* SAU_CTRL address */
    movs r1, #0x01            /* Enable SAU */
    str r1, [r0]

    /* Barrier */
    dsb
    isb

.L_tz_done:
    bx lr

    .size ARM_V8M_CM33_InitTrustZone, . - ARM_V8M_CM33_InitTrustZone

/* ============================================================================
 * CM33 Default Interrupt Handlers
 * ============================================================================
 */

    .section .text.arm_v8m_cm33_handlers, "ax"
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

    .weak DMA1_Channel0_IRQHandler
    .type DMA1_Channel0_IRQHandler, %function
DMA1_Channel0_IRQHandler:
    b DMA1_Channel0_IRQHandler

    .weak DMA1_Channel1_IRQHandler
    .type DMA1_Channel1_IRQHandler, %function
DMA1_Channel1_IRQHandler:
    b DMA1_Channel1_IRQHandler

    .weak DMA1_Channel2_IRQHandler
    .type DMA1_Channel2_IRQHandler, %function
DMA1_Channel2_IRQHandler:
    b DMA1_Channel2_IRQHandler

    .weak DMA1_Channel3_IRQHandler
    .type DMA1_Channel3_IRQHandler, %function
DMA1_Channel3_IRQHandler:
    b DMA1_Channel3_IRQHandler

    .weak DMA1_Channel4_IRQHandler
    .type DMA1_Channel4_IRQHandler, %function
DMA1_Channel4_IRQHandler:
    b DMA1_Channel4_IRQHandler

#endif /* ARM_V8M_CM33_START_S */
