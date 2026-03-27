/*
 * arm_v7m_cm7_fpu.c
 * Cortex-M7 Floating-Point Unit (FPU) Implementation
 * Reference: ARMv7-M Architecture Reference Manual, Section A2.5
 *            - The optional Floating-point Extension on page A2-34
 *            - Section B3.2.19: Coprocessor Access Control Register, CPACR on page B3-614
 *            - Section B3.2.21: Floating Point Context Control Register, FPCCR on page B3-615
 *            - Section B3.2.23: Floating Point Default Status Control Register, FPDSCR on page B3-617
 *            - Section B4.7.2: Media and FP Feature Register 0, MVFR0 on page B4-662
 *            - Section B4.7.3: Media and FP Feature Register 1, MVFR1 on page B4-663
 *            Cortex-M7 Devices Generic User Guide, Chapter 4.7
 *            - Floating Point Unit on page 4-55
 *            - Section 4.7.1: Coprocessor Access Control Register on page 4-55
 *            - Section 4.7.2: Floating-point Context Control Register on page 4-56
 *            - Section 4.7.5: Enabling the FPU on page 4-59
 *            Cortex-M7 Technical Reference Manual, Chapter 8
 *            - Floating Point Unit on page 8-1
 *            - Section 8.1: About the FPU on page 8-2
 *            - Section 8.2: FPU functional description on page 8-3
 *            - Section 8.3: FPU programmers model on page 8-5
 */

#include "arm_v7m_cm7_fpu.h"

/*============================================================================*
 * Non-Inline Functions - Complex Operations
 *============================================================================*/

/**
 * @brief Enable FPU
 * 
 * According to ARMv7-M Architecture Reference Manual and Cortex-M7 documentation:
 * 1. Set CP10 and CP11 in CPACR to Full Access (0b11)
 * 2. Enable automatic state preservation (ASPEN) in FPCCR
 * 3. Enable lazy stacking (LSPEN) in FPCCR
 * 4. Execute DSB and ISB barriers to ensure the changes take effect
 * 
 * @note Must be called before using FPU instructions
 * @note Must be executed in privileged mode
 * @reference Cortex-M7 Devices Generic User Guide, Section 4.7.5
 *            - Enabling the FPU on page 4-59
 *            ARMv7-M Architecture Reference Manual, Section B3.2.19
 *            - Coprocessor Access Control Register, CPACR on page B3-614
 *            Section B3.2.21
 *            - Floating Point Context Control Register, FPCCR on page B3-615
 */
void arm_v7m_cm7_fpu_enable(void)
{
    /* Memory barrier to ensure all previous memory accesses complete */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Enable CP10 and CP11 full access in CPACR */
    /* This grants full access to the floating-point coprocessor */
    arm_v7m_cm7_fpu_enable_cp10_cp11();
    
    /* Memory barrier after CPACR write */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Enable automatic state preservation and lazy stacking */
    arm_v7m_cm7_fpu_enable_auto_save();
    arm_v7m_cm7_fpu_enable_lazy_stacking();
    
    /* Memory barrier after FPCCR write */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Instruction Synchronization Barrier to ensure subsequent instructions */
    /* use the new FPU configuration */
    __asm__ volatile ("isb" ::: "memory");
}

/**
 * @brief Disable FPU
 * 
 * According to ARMv7-M Architecture Reference Manual:
 * 1. Disable automatic state preservation (ASPEN) in FPCCR
 * 2. Disable lazy stacking (LSPEN) in FPCCR
 * 3. Clear CP10 and CP11 in CPACR to Access Denied (0b00)
 * 4. Execute DSB and ISB barriers to ensure the changes take effect
 * 
 * @note Must be executed in privileged mode
 * @reference ARMv7-M Architecture Reference Manual, Section B3.2.19
 *            - Coprocessor Access Control Register, CPACR on page B3-614
 *            Section B3.2.21
 *            - Floating Point Context Control Register, FPCCR on page B3-615
 */
void arm_v7m_cm7_fpu_disable(void)
{
    /* Memory barrier to ensure all previous memory accesses complete */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Disable automatic state preservation and lazy stacking */
    arm_v7m_cm7_fpu_disable_auto_save();
    arm_v7m_cm7_fpu_disable_lazy_stacking();
    
    /* Memory barrier after FPCCR write */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Disable CP10 and CP11 access in CPACR */
    arm_v7m_cm7_fpu_disable_cp10_cp11();
    
    /* Memory barrier after CPACR write */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Instruction Synchronization Barrier to ensure subsequent instructions */
    /* use the new FPU configuration */
    __asm__ volatile ("isb" ::: "memory");
}
