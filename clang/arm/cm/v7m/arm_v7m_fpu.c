/*
 * arm_v7m_fpu.c
 * Floating-Point Unit (FPU) Implementation
 * Reference: ARMv7-M Architecture Reference Manual, Section A2.5, B3.2.20-B3.2.23
 * 
 * This file contains non-inline implementations of FPU operations.
 */

#include "arm_v7m_fpu.h"
#include "arm_v7m_scb.h"

/*============================================================================*
 * FPU Control and Access
 *============================================================================*/

/**
 * @brief Enable FPU
 * 
 * According to ARMv7-M Architecture Reference Manual:
 * 1. Set CP10 and CP11 in CPACR to Full Access (0b11)
 * 2. Enable automatic state preservation (ASPEN) in FPCCR
 * 3. Enable lazy stacking (LSPEN) in FPCCR
 * 
 * @note Must be called before using FPU instructions
 */
void arm_v7m_fpu_enable(void)
{
    /* Memory barrier to ensure all previous memory accesses complete */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Enable CP10 and CP11 full access in CPACR */
    arm_v7m_scb_enable_fpu();
    
    /* Memory barrier after CPACR write */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Enable automatic state preservation and lazy stacking */
    FPU->FPCCR |= (FPU_FPCCR_ASPEN_Msk | FPU_FPCCR_LSPEN_Msk);
    
    /* Memory barrier after FPCCR write */
    __asm__ volatile ("dsb" ::: "memory");
}

/**
 * @brief Disable FPU
 * 
 * According to ARMv7-M Architecture Reference Manual:
 * 1. Disable automatic state preservation (ASPEN) in FPCCR
 * 2. Disable lazy stacking (LSPEN) in FPCCR
 * 3. Clear CP10 and CP11 in CPACR to Access Denied (0b00)
 */
void arm_v7m_fpu_disable(void)
{
    /* Memory barrier to ensure all previous memory accesses complete */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Disable automatic state preservation and lazy stacking */
    FPU->FPCCR &= ~(FPU_FPCCR_ASPEN_Msk | FPU_FPCCR_LSPEN_Msk);
    
    /* Memory barrier after FPCCR write */
    __asm__ volatile ("dsb" ::: "memory");
    
    /* Disable CP10 and CP11 access in CPACR */
    arm_v7m_scb_disable_fpu();
    
    /* Memory barrier after CPACR write */
    __asm__ volatile ("dsb" ::: "memory");
}
