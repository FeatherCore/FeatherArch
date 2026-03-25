/**
 * @file armv7m_start.S
 * @brief ARMv7-M Architecture startup code
 *
 * This file contains the common ARMv7-M startup code and selects
 * the specific Cortex-M implementation (CM4 or CM7).
 *
 * ARMv7-M includes: Cortex-M3, Cortex-M4, Cortex-M7
 */

#ifndef ARMV7M_START_S
#define ARMV7M_START_S

/* ============================================================================
 * ARMv7-M Common Startup Code
 * ============================================================================
 */

    .syntax unified
    .arch armv7-m
    .thumb

/* ============================================================================
 * Vector Table
 * ============================================================================
 * The vector table is placed at the beginning of the image (address 0x00000000)
 * It contains:
 * - Initial SP value
 * - Reset handler address
 * - Exception handlers
 * - Interrupt handlers
 */

    .section .vectors, "ax"
    .align 2
    .globl __vectors
    .type __vectors, %object

__vectors:
    /* Initial SP value (top of stack) */
    .word __stack_top

    /* Reset handler */
    .word Reset_Handler

    /* Core exceptions */
    .word NMI_Handler
    .word HardFault_Handler
    .word MemManage_Handler
    .word BusFault_Handler
    .word UsageFault_Handler
    .word 0                           /* Reserved */
    .word 0                           /* Reserved */
    .word 0                           /* Reserved */
    .word 0                           /* Reserved */
    .word SVC_Handler
    .word DebugMon_Handler
    .word 0                           /* Reserved */
    .word PendSV_Handler
    .word SysTick_Handler

    /* External interrupts - device specific */
    /* These will be defined in the specific CM4/CM7 implementation */

    .size __vectors, . - __vectors

/* ============================================================================
 * Reset Handler
 * ============================================================================
 */

    .section .text.Reset_Handler
    .align 2
    .globl Reset_Handler
    .type Reset_Handler, %function

Reset_Handler:
    /* Initialize stack pointer (already done by hardware from vector table) */

    /* Copy data section from Flash to RAM */
    ldr r0, =__data_start
    ldr r1, =__data_load_start
    ldr r2, =__data_size
    cbz r2, .L_zero_bss

.L_copy_data:
    ldr r3, [r1], #4
    str r3, [r0], #4
    subs r2, r2, #4
    bne .L_copy_data

    /* Zero BSS section */
.L_zero_bss:
    ldr r0, =__bss_start
    ldr r1, =__bss_size
    cbz r1, .L_init_system
    movs r2, #0

.L_zero_loop:
    str r2, [r0], #4
    subs r1, r1, #4
    bne .L_zero_loop

    /* System initialization */
.L_init_system:
    /* Call system initialization function */
    bl SystemInit

    /* Call C++ constructors (if any) */
    bl __libc_init_array

    /* Jump to main */
    bl main

    /* If main returns, loop forever */
.L_infinite_loop:
    b .L_infinite_loop

    .size Reset_Handler, . - Reset_Handler

/* ============================================================================
 * Default Exception Handlers
 * ============================================================================
 */

    .section .text.default_handler, "ax"
    .align 2

    .weak NMI_Handler
    .type NMI_Handler, %function
NMI_Handler:
    b NMI_Handler

    .weak HardFault_Handler
    .type HardFault_Handler, %function
HardFault_Handler:
    b HardFault_Handler

    .weak MemManage_Handler
    .type MemManage_Handler, %function
MemManage_Handler:
    b MemManage_Handler

    .weak BusFault_Handler
    .type BusFault_Handler, %function
BusFault_Handler:
    b BusFault_Handler

    .weak UsageFault_Handler
    .type UsageFault_Handler, %function
UsageFault_Handler:
    b UsageFault_Handler

    .weak SVC_Handler
    .type SVC_Handler, %function
SVC_Handler:
    b SVC_Handler

    .weak DebugMon_Handler
    .type DebugMon_Handler, %function
DebugMon_Handler:
    b DebugMon_Handler

    .weak PendSV_Handler
    .type PendSV_Handler, %function
PendSV_Handler:
    b PendSV_Handler

    .weak SysTick_Handler
    .type SysTick_Handler, %function
SysTick_Handler:
    b SysTick_Handler

/* ============================================================================
 * Specific Implementation Selection
 * ============================================================================
 *
 * Select the specific Cortex-M implementation based on target defines:
 * - CORTEX_M4 : Cortex-M4
 * - CORTEX_M7 : Cortex-M7
 */

#if defined(CORTEX_M4)
    #include "cm4/cm4_start.S"
#elif defined(CORTEX_M7)
    #include "cm7/cm7_start.S"
#else
    /* Default: Include generic ARMv7-M initialization */
    /* Specific processor initialization should be done in SystemInit */
#endif

#endif /* ARMV7M_START_S */
