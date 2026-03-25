/**
 * @file cm55_start.S
 * @brief Cortex-M55 specific startup code
 *
 * Cortex-M55 features:
 * - ARMv8.1-M architecture
 * - TrustZone Security Extension
 * - MVE (Helium) vector extension
 * - Optional FPU
 * - Instruction and Data Cache
 * - Tightly Coupled Memory (TCM)
 * - EPU (Extension Processing Unit)
 * - RAS (Reliability, Availability, Serviceability)
 * - PMU (Performance Monitoring Unit)
 */

#ifndef CM55_START_S
#define CM55_START_S

/* ============================================================================
 * Cortex-M55 Specific Initialization
 * ============================================================================
 */

    .syntax unified
    .arch armv8.1-m.main
    .thumb

/* ============================================================================
 * CM55 Vector Table Extensions
 * ============================================================================
 */

    .section .vectors.cm55, "ax"
    .align 2

    /* External Interrupts 0-15 (CM55 specific) */
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
 * CM55 System Initialization
 * ============================================================================
 */

    .section .text.cm55_init
    .align 2
    .globl CM55_Init
    .type CM55_Init, %function

CM55_Init:
    /* Push link register */
    push {lr}

    /* Initialize stack limit registers */
    movs r0, #0
    msr psplim, r0
    msr msplim, r0

    /* Enable FPU if present */
    bl CM55_EnableFPU

    /* Initialize MVE (Helium) */
    bl CM55_InitMVE

    /* Initialize Cache */
    bl CM55_InitCache

    /* Initialize TCM */
    bl CM55_InitTCM

    /* Initialize EPU */
    bl CM55_InitEPU

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

    /* Initialize TrustZone */
    bl CM55_InitTrustZone

    /* Initialize RAS */
    bl CM55_InitRAS

    /* Initialize PMU */
    bl CM55_InitPMU

    /* Pop link register and return */
    pop {pc}

    .size CM55_Init, . - CM55_Init

/* ============================================================================
 * CM55 FPU Initialization
 * ============================================================================
 */

    .section .text.cm55_fpu
    .align 2
    .type CM55_EnableFPU, %function

CM55_EnableFPU:
    /* Enable CP10 and CP11 (FPU coprocessors) */
    ldr r0, =0xE000ED88       /* CPACR address */
    ldr r1, [r0]
    orr r1, r1, #0x00F00000   /* Set CP10 and CP11 full access */
    str r1, [r0]

    /* Barrier instructions */
    dsb
    isb

    bx lr

    .size CM55_EnableFPU, . - CM55_EnableFPU

/* ============================================================================
 * CM55 MVE (Helium) Initialization
 * ============================================================================
 */

    .section .text.cm55_mve
    .align 2
    .type CM55_InitMVE, %function

CM55_InitMVE:
    /* Enable MVE in CPACR */
    ldr r0, =0xE000ED88       /* CPACR address */
    ldr r1, [r0]
    orr r1, r1, #0x00C00000   /* Enable MVE (CP10/CP11 in full access) */
    str r1, [r0]

    /* Clear VPR (Vector Predication Register) */
    movs r0, #0
    msr vpr, r0

    /* Barrier */
    dsb
    isb

    bx lr

    .size CM55_InitMVE, . - CM55_InitMVE

/* ============================================================================
 * CM55 Cache Initialization
 * ============================================================================
 */

    .section .text.cm55_cache
    .align 2
    .type CM55_InitCache, %function

CM55_InitCache:
    /* Enable I-Cache */
    ldr r0, =0xE000ED14       /* SCB->CCR address */
    ldr r1, [r0]
    orr r1, r1, #0x00020000   /* Set IC bit (bit 17) */
    str r1, [r0]

    /* Enable D-Cache */
    ldr r1, [r0]
    orr r1, r1, #0x00010000   /* Set DC bit (bit 16) */
    str r1, [r0]

    /* Barrier */
    dsb
    isb

    bx lr

    .size CM55_InitCache, . - CM55_InitCache

/* ============================================================================
 * CM55 TCM Initialization
 * ============================================================================
 */

    .section .text.cm55_tcm
    .align 2
    .type CM55_InitTCM, %function

CM55_InitTCM:
    /* Enable ITCM and DTCM */
    ldr r0, =0xE001E010       /* ITCMCR address */
    movs r1, #0x01            /* Enable ITCM */
    str r1, [r0]

    ldr r0, =0xE001E014       /* DTCMCR address */
    movs r1, #0x01            /* Enable DTCM */
    str r1, [r0]

    /* Barrier */
    dsb
    isb

    bx lr

    .size CM55_InitTCM, . - CM55_InitTCM

/* ============================================================================
 * CM55 EPU Initialization
 * ============================================================================
 */

    .section .text.cm55_epu
    .align 2
    .type CM55_InitEPU, %function

CM55_InitEPU:
    /* Enable EPU */
    ldr r0, =0xE000E300       /* EPUCR address */
    movs r1, #0x01            /* Enable EPU */
    str r1, [r0]

    /* Barrier */
    dsb
    isb

    bx lr

    .size CM55_InitEPU, . - CM55_InitEPU

/* ============================================================================
 * CM55 TrustZone Initialization
 * ============================================================================
 */

    .section .text.cm55_tz
    .align 2
    .type CM55_InitTrustZone, %function

CM55_InitTrustZone:
    /* Check if running in secure state */
    mrs r0, control
    tst r0, #0x02
    bne .L_tz_done

    /* Enable SAU */
    ldr r0, =0xE000EDD0       /* SAU_CTRL address */
    movs r1, #0x01
    str r1, [r0]

    /* Configure TGU (TCM Gate Unit) for secure/non-secure access */
    /* ITGU */
    ldr r0, =0xE001E500       /* ITGU_CTRL address */
    movs r1, #0x01            /* Enable ITGU */
    str r1, [r0]

    /* DTGU */
    ldr r0, =0xE001E600       /* DTGU_CTRL address */
    movs r1, #0x01            /* Enable DTGU */
    str r1, [r0]

    /* Barrier */
    dsb
    isb

.L_tz_done:
    bx lr

    .size CM55_InitTrustZone, . - CM55_InitTrustZone

/* ============================================================================
 * CM55 RAS Initialization
 * ============================================================================
 */

    .section .text.cm55_ras
    .align 2
    .type CM55_InitRAS, %function

CM55_InitRAS:
    /* Enable RAS error detection */
    ldr r0, =0xE0005000       /* ERRCTRL address */
    movs r1, #0x01            /* Enable error recording */
    str r1, [r0]

    bx lr

    .size CM55_InitRAS, . - CM55_InitRAS

/* ============================================================================
 * CM55 PMU Initialization
 * ============================================================================
 */

    .section .text.cm55_pmu
    .align 2
    .type CM55_InitPMU, %function

CM55_InitPMU:
    /* Enable PMU */
    ldr r0, =0xE0003000       /* PMUCTRL address */
    movs r1, #0x01            /* Enable PMU */
    str r1, [r0]

    /* Enable cycle counter */
    ldr r0, =0xE0003004       /* PMCNTENSET address */
    movs r1, #0x80000000      /* Enable cycle counter (bit 31) */
    str r1, [r0]

    bx lr

    .size CM55_InitPMU, . - CM55_InitPMU

/* ============================================================================
 * CM55 Default Interrupt Handlers
 * ============================================================================
 */

    .section .text.cm55_handlers, "ax"
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

#endif /* CM55_START_S */
