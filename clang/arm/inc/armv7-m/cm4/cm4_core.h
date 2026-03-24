/*
 * ARM Architecture - Cortex-M4 Core Registers
 *
 * ============================================================================
 * File: cm4_core.h
 * Description: Cortex-M4 core register definitions and inline functions
 * 描述: Cortex-M4 核心寄存器定义和内联函数
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 2.1.3: Core registers (page 2-3)
 *   - Table 2-2: Core register set summary (page 2-3)
 *   - Table 2-4: APSR bit assignments (page 2-5)
 *   - Table 2-5: IPSR bit assignments (page 2-6)
 *   - Table 2-6: EPSR bit assignments (page 2-6)
 *   - Table 2-7: PRIMASK register bit assignments (page 2-8)
 *   - Table 2-8: FAULTMASK register bit assignments (page 2-8)
 *   - Table 2-9: BASEPRI register bit assignments (page 2-9)
 *   - Table 2-10: CONTROL register bit assignments (page 2-9)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_CM4_CORE_H__
#define __ARCH_ARM_CM4_CORE_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * APSR - Application Program Status Register
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-4 (page 2-5)
 * ============================================================================
 */

/* APSR bit positions */
#define APSR_N_Pos                        31U
#define APSR_Z_Pos                        30U
#define APSR_C_Pos                        29U
#define APSR_V_Pos                        28U
#define APSR_Q_Pos                        27U
#define APSR_GE_Pos                       16U

/* APSR bit masks */
#define APSR_N_Msk                        (1UL << APSR_N_Pos)
#define APSR_Z_Msk                        (1UL << APSR_Z_Pos)
#define APSR_C_Msk                        (1UL << APSR_C_Pos)
#define APSR_V_Msk                        (1UL << APSR_V_Pos)
#define APSR_Q_Msk                        (1UL << APSR_Q_Pos)
#define APSR_GE_Msk                       (0xFUL << APSR_GE_Pos)

/*
 * ============================================================================
 * IPSR - Interrupt Program Status Register
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-5 (page 2-6)
 * ============================================================================
 */

/* IPSR bit positions */
#define IPSR_ISR_Pos                      0U

/* IPSR bit masks */
#define IPSR_ISR_Msk                      (0x1FFUL << IPSR_ISR_Pos)

/* Exception number definitions */
#define IPSR_ISR_THREAD                   0U    /* Thread mode */
#define IPSR_ISR_NMI                      2U    /* NMI */
#define IPSR_ISR_HARDFAULT                3U    /* HardFault */
#define IPSR_ISR_MEMMANAGE                4U    /* MemManage */
#define IPSR_ISR_BUSFAULT                 5U    /* BusFault */
#define IPSR_ISR_USAGEFAULT               6U    /* UsageFault */
#define IPSR_ISR_SVCALL                   11U   /* SVCall */
#define IPSR_ISR_DEBUGMON                 12U   /* Debug Monitor */
#define IPSR_ISR_PENDSV                   14U   /* PendSV */
#define IPSR_ISR_SYSTICK                  15U   /* SysTick */
#define IPSR_ISR_IRQ0                     16U   /* IRQ0 start */

/*
 * ============================================================================
 * EPSR - Execution Program Status Register
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-6 (page 2-6)
 * ============================================================================
 */

/* EPSR bit positions */
#define EPSR_ICI_IT_Pos                   10U
#define EPSR_T_Pos                        24U

/* EPSR bit masks */
#define EPSR_ICI_IT_Msk                   (0x3FUL << EPSR_ICI_IT_Pos)
#define EPSR_T_Msk                        (1UL << EPSR_T_Pos)

/*
 * ============================================================================
 * PRIMASK - Priority Mask Register
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-7 (page 2-8)
 * ============================================================================
 */

/* PRIMASK bit positions */
#define PRIMASK_PRIMASK_Pos               0U

/* PRIMASK bit masks */
#define PRIMASK_PRIMASK_Msk               (1UL << PRIMASK_PRIMASK_Pos)

/*
 * ============================================================================
 * FAULTMASK - Fault Mask Register
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-8 (page 2-8)
 * ============================================================================
 */

/* FAULTMASK bit positions */
#define FAULTMASK_FAULTMASK_Pos           0U

/* FAULTMASK bit masks */
#define FAULTMASK_FAULTMASK_Msk           (1UL << FAULTMASK_FAULTMASK_Pos)

/*
 * ============================================================================
 * BASEPRI - Base Priority Mask Register
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-9 (page 2-9)
 * ============================================================================
 */

/* BASEPRI bit positions */
#define BASEPRI_BASEPRI_Pos               0U

/* BASEPRI bit masks */
#define BASEPRI_BASEPRI_Msk               (0xFFUL << BASEPRI_BASEPRI_Pos)

/*
 * ============================================================================
 * CONTROL - Control Register
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-10 (page 2-9)
 * ============================================================================
 */

/* CONTROL bit positions */
#define CONTROL_nPRIV_Pos                 0U
#define CONTROL_SPSEL_Pos                 1U
#define CONTROL_FPCA_Pos                  2U

/* CONTROL bit masks */
#define CONTROL_nPRIV_Msk                 (1UL << CONTROL_nPRIV_Pos)
#define CONTROL_SPSEL_Msk                 (1UL << CONTROL_SPSEL_Pos)
#define CONTROL_FPCA_Msk                  (1UL << CONTROL_FPCA_Pos)

/* CONTROL register values */
#define CONTROL_nPRIV_PRIV                0U    /* Privileged level */
#define CONTROL_nPRIV_UNPRIV              1U    /* Unprivileged level */
#define CONTROL_SPSEL_MSP                 0U    /* Use MSP */
#define CONTROL_SPSEL_PSP                 1U    /* Use PSP */
#define CONTROL_FPCA_NOFP                 0U    /* No floating-point context */
#define CONTROL_FPCA_FP                   1U    /* Floating-point context active */

/*
 * ============================================================================
 * Core Register Access Functions
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.3 (page 2-3)
 * ============================================================================
 */

/**
 * @brief Get APSR register value
 * @return APSR value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline uint32_t cm4_get_apsr(void)
{
    uint32_t result;
    __asm__ volatile ("MRS %0, apsr" : "=r" (result));
    return result;
}

/**
 * @brief Get IPSR register value
 * @return IPSR value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline uint32_t cm4_get_ipsr(void)
{
    uint32_t result;
    __asm__ volatile ("MRS %0, ipsr" : "=r" (result));
    return result;
}

/**
 * @brief Get PSR register value
 * @return PSR value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline uint32_t cm4_get_psr(void)
{
    uint32_t result;
    __asm__ volatile ("MRS %0, psr" : "=r" (result));
    return result;
}

/**
 * @brief Get PRIMASK register value
 * @return PRIMASK value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline uint32_t cm4_get_primask(void)
{
    uint32_t result;
    __asm__ volatile ("MRS %0, primask" : "=r" (result));
    return result;
}

/**
 * @brief Set PRIMASK register value
 * @param primask PRIMASK value to set
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline void cm4_set_primask(uint32_t primask)
{
    __asm__ volatile ("MSR primask, %0" : : "r" (primask) : "memory");
}

/**
 * @brief Get FAULTMASK register value
 * @return FAULTMASK value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline uint32_t cm4_get_faultmask(void)
{
    uint32_t result;
    __asm__ volatile ("MRS %0, faultmask" : "=r" (result));
    return result;
}

/**
 * @brief Set FAULTMASK register value
 * @param faultmask FAULTMASK value to set
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline void cm4_set_faultmask(uint32_t faultmask)
{
    __asm__ volatile ("MSR faultmask, %0" : : "r" (faultmask) : "memory");
}

/**
 * @brief Get BASEPRI register value
 * @return BASEPRI value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline uint32_t cm4_get_basepri(void)
{
    uint32_t result;
    __asm__ volatile ("MRS %0, basepri" : "=r" (result));
    return result;
}

/**
 * @brief Set BASEPRI register value
 * @param basepri BASEPRI value to set
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline void cm4_set_basepri(uint32_t basepri)
{
    __asm__ volatile ("MSR basepri, %0" : : "r" (basepri) : "memory");
}

/**
 * @brief Get CONTROL register value
 * @return CONTROL value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline uint32_t cm4_get_control(void)
{
    uint32_t result;
    __asm__ volatile ("MRS %0, control" : "=r" (result));
    return result;
}

/**
 * @brief Set CONTROL register value
 * @param control CONTROL value to set
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline void cm4_set_control(uint32_t control)
{
    __asm__ volatile ("MSR control, %0" : : "r" (control) : "memory");
}

/**
 * @brief Get Main Stack Pointer (MSP)
 * @return MSP value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline uint32_t cm4_get_msp(void)
{
    uint32_t result;
    __asm__ volatile ("MRS %0, msp" : "=r" (result));
    return result;
}

/**
 * @brief Set Main Stack Pointer (MSP)
 * @param msp MSP value to set
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline void cm4_set_msp(uint32_t msp)
{
    __asm__ volatile ("MSR msp, %0" : : "r" (msp) : "memory");
}

/**
 * @brief Get Process Stack Pointer (PSP)
 * @return PSP value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline uint32_t cm4_get_psp(void)
{
    uint32_t result;
    __asm__ volatile ("MRS %0, psp" : "=r" (result));
    return result;
}

/**
 * @brief Set Process Stack Pointer (PSP)
 * @param psp PSP value to set
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline void cm4_set_psp(uint32_t psp)
{
    __asm__ volatile ("MSR psp, %0" : : "r" (psp) : "memory");
}

/**
 * @brief Get Link Register (LR)
 * @return LR value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline uint32_t cm4_get_lr(void)
{
    uint32_t result;
    __asm__ volatile ("MOV %0, lr" : "=r" (result));
    return result;
}

/**
 * @brief Get Program Counter (PC)
 * @return PC value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-2 (page 2-3)
 */
static inline uint32_t cm4_get_pc(void)
{
    uint32_t result;
    __asm__ volatile ("MOV %0, pc" : "=r" (result));
    return result;
}

/*
 * ============================================================================
 * Stack Selection Functions
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-1 (page 2-2)
 * ============================================================================
 */

/**
 * @brief Select Main Stack Pointer (MSP)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-10 (page 2-9)
 */
static inline void cm4_select_msp(void)
{
    uint32_t control = cm4_get_control();
    control &= ~CONTROL_SPSEL_Msk;
    cm4_set_control(control);
    __asm__ volatile ("ISB" ::: "memory");
}

/**
 * @brief Select Process Stack Pointer (PSP)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-10 (page 2-9)
 */
static inline void cm4_select_psp(void)
{
    uint32_t control = cm4_get_control();
    control |= CONTROL_SPSEL_Msk;
    cm4_set_control(control);
    __asm__ volatile ("ISB" ::: "memory");
}

/**
 * @brief Check if using Process Stack Pointer
 * @return 1 if using PSP, 0 if using MSP
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-10 (page 2-9)
 */
static inline int cm4_is_psp_selected(void)
{
    return (cm4_get_control() & CONTROL_SPSEL_Msk) ? 1 : 0;
}

/*
 * ============================================================================
 * Privilege Level Functions
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.1 (page 2-2)
 * ============================================================================
 */

/**
 * @brief Set Thread mode to privileged level
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-10 (page 2-9)
 */
static inline void cm4_set_privileged(void)
{
    uint32_t control = cm4_get_control();
    control &= ~CONTROL_nPRIV_Msk;
    cm4_set_control(control);
}

/**
 * @brief Set Thread mode to unprivileged level
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-10 (page 2-9)
 */
static inline void cm4_set_unprivileged(void)
{
    uint32_t control = cm4_get_control();
    control |= CONTROL_nPRIV_Msk;
    cm4_set_control(control);
}

/**
 * @brief Check if in privileged mode
 * @return 1 if privileged, 0 if unprivileged
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-10 (page 2-9)
 */
static inline int cm4_is_privileged(void)
{
    return (cm4_get_control() & CONTROL_nPRIV_Msk) ? 0 : 1;
}

/*
 * ============================================================================
 * Exception Mask Functions
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.3 (page 2-7)
 * ============================================================================
 */

/**
 * @brief Disable all exceptions with configurable priority
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-7 (page 2-8)
 */
static inline void cm4_disable_irq(void)
{
    __asm__ volatile ("CPSID i" ::: "memory");
}

/**
 * @brief Enable all exceptions with configurable priority
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-7 (page 2-8)
 */
static inline void cm4_enable_irq(void)
{
    __asm__ volatile ("CPSIE i" ::: "memory");
}

/**
 * @brief Disable all exceptions except NMI
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-8 (page 2-8)
 */
static inline void cm4_disable_fault(void)
{
    __asm__ volatile ("CPSID f" ::: "memory");
}

/**
 * @brief Enable all exceptions except NMI
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-8 (page 2-8)
 */
static inline void cm4_enable_fault(void)
{
    __asm__ volatile ("CPSIE f" ::: "memory");
}

/**
 * @brief Set BASEPRI to mask exceptions with priority lower than specified
 * @param basepri Priority value (0-255), 0 = no effect
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-9 (page 2-9)
 */
static inline void cm4_set_basepri_value(uint8_t basepri)
{
    cm4_set_basepri(basepri);
}

/**
 * @brief Clear BASEPRI (enable all exceptions)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-9 (page 2-9)
 */
static inline void cm4_clear_basepri(void)
{
    cm4_set_basepri(0U);
}

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_CM4_CORE_H__ */
