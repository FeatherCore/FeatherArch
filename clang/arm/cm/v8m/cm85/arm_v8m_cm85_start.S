/**
 * @file arm_v8m_cm85_start.S
 * @brief Cortex-M85 specific startup code
 *
 * Cortex-M85 features:
 * - ARMv8.1-M architecture (highest performance Cortex-M)
 * - TrustZone Security Extension
 * - MVE (Helium) vector extension with enhanced performance
 * - Optional FPU (single and double precision)
 * - Instruction and Data Cache
 * - Tightly Coupled Memory (TCM)
 * - Enhanced EPU (Extension Processing Unit)
 * - RAS (Reliability, Availability, Serviceability)
 * - PMU (Performance Monitoring Unit)
 * - PACBTI (Pointer Authentication and Branch Target Identification)
 * - External Coprocessor Interface
 */

#ifndef ARM_V8M_CM85_START_S
#define ARM_V8M_CM85_START_S

/* ============================================================================
 * Cortex-M85 Specific Initialization
 * ============================================================================
 */

    .syntax unified
    .arch armv8.1-m.main
    .thumb

/* ============================================================================
 * CM85 Vector Table Extensions
 * ============================================================================
 */

    .section .vectors.cm85, "ax"
    .align 2

    /* External Interrupts 0-15 (CM85 specific) */
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
 * CM85 System Initialization
 * ============================================================================
 */

    .section .text.arm_v8m_cm85_init
    .align 2
    .globl ARM_V8M_CM85_Init
    .type ARM_V8M_CM85_Init, %function

ARM_V8M_CM85_Init:
    /* Push link register */
    push {lr}

    /* Initialize stack limit registers */
    movs r0, #0
    msr psplim, r0
    msr msplim, r0

    /* Enable FPU if present */
    bl ARM_V8M_CM85_EnableFPU

    /* Initialize MVE (Helium) - enhanced for CM85 */
    bl ARM_V8M_CM85_InitMVE

    /* Initialize Cache - with direct cache access */
    bl ARM_V8M_CM85_InitCache

    /* Initialize TCM */
    bl ARM_V8M_CM85_InitTCM

    /* Initialize Enhanced EPU */
    bl ARM_V8M_CM85_InitEPU

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
    bl ARM_V8M_CM85_InitTrustZone

    /* Initialize RAS - enhanced for CM85 */
    bl ARM_V8M_CM85_InitRAS

    /* Initialize PMU - enhanced for CM85 */
    bl ARM_V8M_CM85_InitPMU

    /* Initialize PACBTI */
    bl ARM_V8M_CM85_InitPACBTI

    /* Initialize Coprocessor Interface */
    bl ARM_V8M_CM85_InitCoproc

    /* Pop link register and return */
    pop {pc}

    .size ARM_V8M_CM85_Init, . - ARM_V8M_CM85_Init

/* ============================================================================
 * CM85 FPU Initialization
 * ============================================================================
 */

    .section .text.arm_v8m_cm85_fpu
    .align 2
    .type ARM_V8M_CM85_EnableFPU, %function

ARM_V8M_CM85_EnableFPU:
    /* Enable CP10 and CP11 (FPU coprocessors) */
    ldr r0, =0xE000ED88       /* CPACR address */
    ldr r1, [r0]
    orr r1, r1, #0x00F00000   /* Set CP10 and CP11 full access */
    str r1, [r0]

    /* Enable FP lazy state preservation */
    ldr r0, =0xE000EF34       /* FPCCR address */
    ldr r1, [r0]
    orr r1, r1, #0xC0000000   /* Enable ASPEN and LSPEN */
    str r1, [r0]

    /* Barrier instructions */
    dsb
    isb

    bx lr

    .size ARM_V8M_CM85_EnableFPU, . - ARM_V8M_CM85_EnableFPU

/* ============================================================================
 * CM85 MVE (Helium) Initialization - Enhanced
 * ============================================================================
 */

    .section .text.arm_v8m_cm85_mve
    .align 2
    .type ARM_V8M_CM85_InitMVE, %function

ARM_V8M_CM85_InitMVE:
    /* Enable MVE in CPACR */
    ldr r0, =0xE000ED88       /* CPACR address */
    ldr r1, [r0]
    orr r1, r1, #0x00C00000   /* Enable MVE (CP10/CP11 in full access) */
    str r1, [r0]

    /* Clear VPR (Vector Predication Register) */
    movs r0, #0
    msr vpr, r0

    /* Clear ECI bits in EPSR */
    mrs r0, epsr
    bic r0, r0, #0x0000FC00   /* Clear ECI/ICI bits */
    msr epsr, r0

    /* Barrier */
    dsb
    isb

    bx lr

    .size ARM_V8M_CM85_InitMVE, . - ARM_V8M_CM85_InitMVE

/* ============================================================================
 * CM85 Cache Initialization - with Direct Cache Access
 * ============================================================================
 */

    .section .text.arm_v8m_cm85_cache
    .align 2
    .type ARM_V8M_CM85_InitCache, %function

ARM_V8M_CM85_InitCache:
    /* Invalidate I-Cache before enabling */
    ldr r0, =0xE000EF50       /* ICIALLU address */
    movs r1, #0
    str r1, [r0]

    /* Enable I-Cache */
    ldr r0, =0xE000ED14       /* SCB->CCR address */
    ldr r1, [r0]
    orr r1, r1, #0x00020000   /* Set IC bit (bit 17) */
    str r1, [r0]

    /* Invalidate D-Cache before enabling */
    /* This is a simplified version - full implementation would require
     * iterating through all cache sets and ways */

    /* Enable D-Cache */
    ldr r1, [r0]
    orr r1, r1, #0x00010000   /* Set DC bit (bit 16) */
    str r1, [r0]

    /* Enable branch prediction */
    ldr r1, [r0]
    orr r1, r1, #0x00040000   /* Set BP bit (bit 18) */
    str r1, [r0]

    /* Barrier */
    dsb
    isb

    bx lr

    .size ARM_V8M_CM85_InitCache, . - ARM_V8M_CM85_InitCache

/* ============================================================================
 * CM85 TCM Initialization
 * ============================================================================
 */

    .section .text.arm_v8m_cm85_tcm
    .align 2
    .type ARM_V8M_CM85_InitTCM, %function

ARM_V8M_CM85_InitTCM:
    /* Enable ITCM with RMW (Read-Modify-Write) and retention */
    ldr r0, =0xE001E010       /* ITCMCR address */
    movs r1, #0x07            /* Enable ITCM, RMW, Retention */
    str r1, [r0]

    /* Enable DTCM with RMW and retention */
    ldr r0, =0xE001E014       /* DTCMCR address */
    movs r1, #0x07            /* Enable DTCM, RMW, Retention */
    str r1, [r0]

    /* Barrier */
    dsb
    isb

    bx lr

    .size ARM_V8M_CM85_InitTCM, . - ARM_V8M_CM85_InitTCM

/* ============================================================================
 * CM85 Enhanced EPU Initialization
 * ============================================================================
 */

    .section .text.arm_v8m_cm85_epu
    .align 2
    .type ARM_V8M_CM85_InitEPU, %function

ARM_V8M_CM85_InitEPU:
    /* Enable EPU with FP and MVE support */
    ldr r0, =0xE000E300       /* EPUCR address */
    movs r1, #0x01            /* Enable EPU */
    str r1, [r0]

    /* Barrier */
    dsb
    isb

    bx lr

    .size ARM_V8M_CM85_InitEPU, . - ARM_V8M_CM85_InitEPU

/* ============================================================================
 * CM85 TrustZone Initialization
 * ============================================================================
 */

    .section .text.arm_v8m_cm85_tz
    .align 2
    .type ARM_V8M_CM85_InitTrustZone, %function

ARM_V8M_CM85_InitTrustZone:
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

    .size ARM_V8M_CM85_InitTrustZone, . - ARM_V8M_CM85_InitTrustZone

/* ============================================================================
 * CM85 RAS Initialization - Enhanced
 * ============================================================================
 */

    .section .text.arm_v8m_cm85_ras
    .align 2
    .type ARM_V8M_CM85_InitRAS, %function

ARM_V8M_CM85_InitRAS:
    /* Enable RAS error detection and correction */
    ldr r0, =0xE0005000       /* ERRCTRL address */
    movs r1, #0x03            /* Enable error recording and correction */
    str r1, [r0]

    /* Clear error bank registers */
    movs r1, #0
    ldr r0, =0xE001E120       /* IEBR0 address */
    str r1, [r0]
    ldr r0, =0xE001E124       /* IEBR1 address */
    str r1, [r0]
    ldr r0, =0xE001E128       /* DEBR0 address */
    str r1, [r0]
    ldr r0, =0xE001E12C       /* DEBR1 address */
    str r1, [r0]

    bx lr

    .size ARM_V8M_CM85_InitRAS, . - ARM_V8M_CM85_InitRAS

/* ============================================================================
 * CM85 PMU Initialization - Enhanced
 * ============================================================================
 */

    .section .text.arm_v8m_cm85_pmu
    .align 2
    .type ARM_V8M_CM85_InitPMU, %function

ARM_V8M_CM85_InitPMU:
    /* Enable PMU */
    ldr r0, =0xE0003000       /* PMUCTRL address */
    movs r1, #0x01            /* Enable PMU */
    str r1, [r0]

    /* Enable cycle counter */
    ldr r0, =0xE0003004       /* PMCNTENSET address */
    movs r1, #0x80000000      /* Enable cycle counter (bit 31) */
    str r1, [r0]

    /* Configure event counters for CM85-specific events */
    /* Event 0: MVE instructions retired */
    ldr r0, =0xE0003200       /* PMEVTYPER0 address */
    movs r1, #0x80            /* MVE_INST_RETIRED event */
    str r1, [r0]

    /* Enable event counter 0 */
    ldr r0, =0xE0003004       /* PMCNTENSET address */
    movs r1, #0x01            /* Enable counter 0 */
    str r1, [r0]

    bx lr

    .size ARM_V8M_CM85_InitPMU, . - ARM_V8M_CM85_InitPMU

/* ============================================================================
 * CM85 PACBTI Initialization
 * ============================================================================
 */

    .section .text.arm_v8m_cm85_pacbti
    .align 2
    .type ARM_V8M_CM85_InitPACBTI, %function

ARM_V8M_CM85_InitPACBTI:
    /* Check if PACBTI is implemented */
    ldr r0, =0xE000ED90       /* ID_PFR0 address */
    ldr r1, [r0]
    tst r1, #0x00F00000       /* Check PACBTI bits */
    beq .L_pacbti_done

    /* Initialize PAC keys */
    /* Note: In a real implementation, keys should be generated randomly
     * or provided by the secure boot process */

    /* Clear PAC keys initially */
    movs r0, #0
    ldr r1, =0xE000EF90       /* PAC_KEY_P_0 address */
    str r0, [r1]
    str r0, [r1, #4]          /* PAC_KEY_P_1 */
    str r0, [r1, #8]          /* PAC_KEY_P_2 */
    str r0, [r1, #12]         /* PAC_KEY_P_3 */

    ldr r1, =0xE000EFA0       /* PAC_KEY_U_0 address */
    str r0, [r1]
    str r0, [r1, #4]          /* PAC_KEY_U_1 */
    str r0, [r1, #8]          /* PAC_KEY_U_2 */
    str r0, [r1, #12]         /* PAC_KEY_U_3 */

.L_pacbti_done:
    bx lr

    .size ARM_V8M_CM85_InitPACBTI, . - ARM_V8M_CM85_InitPACBTI

/* ============================================================================
 * CM85 Coprocessor Interface Initialization
 * ============================================================================
 */

    .section .text.arm_v8m_cm85_coproc
    .align 2
    .type ARM_V8M_CM85_InitCoproc, %function

ARM_V8M_CM85_InitCoproc:
    /* Enable coprocessor access in CPACR */
    ldr r0, =0xE000ED88       /* CPACR address */
    ldr r1, [r0]

    /* Enable CP0-CP7 for external coprocessor access */
    orr r1, r1, #0x00000003   /* CP0: full access */
    orr r1, r1, #0x0000000C   /* CP1: full access */
    orr r1, r1, #0x00000030   /* CP2: full access */
    orr r1, r1, #0x000000C0   /* CP3: full access */
    orr r1, r1, #0x00000300   /* CP4: full access */
    orr r1, r1, #0x00000C00   /* CP5: full access */
    orr r1, r1, #0x00003000   /* CP6: full access */
    orr r1, r1, #0x0000C000   /* CP7: full access */

    str r1, [r0]

    /* Barrier */
    dsb
    isb

    bx lr

    .size ARM_V8M_CM85_InitCoproc, . - ARM_V8M_CM85_InitCoproc

/* ============================================================================
 * CM85 Default Interrupt Handlers
 * ============================================================================
 */

    .section .text.arm_v8m_cm85_handlers, "ax"
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

#endif /* ARM_V8M_CM85_START_S */
