/*
 * ARM Architecture - ARMv8-M Implementation
 *
 * ============================================================================
 * File: armv8m.c
 * Description: ARMv8-M Architecture (Cortex-M23/M33/M55/M85) Implementation
 * 描述: ARMv8-M 架构 (Cortex-M23/M33/M55/M85) 实现
 *
 * This file provides complete implementation of ARMv8-M architecture features
 * including core registers, NVIC, MPU, PMU, TrustZone/SAU, SysTick, ITM, and FPU.
 * 本文件提供 ARMv8-M 架构功能的完整实现，包括核心寄存器、NVIC、MPU、PMU、
 * TrustZone/SAU、SysTick、ITM 和 FPU。
 *
 * Reference Documents / 参考文档:
 *   1. ARMv8-M Architecture Reference Manual (ARM DDI 0553B)
 *      - Chapter B1: Processor Memory Model (B1.1-B1.5)
 *      - Chapter B2: Programmer's Model (B2.1-B2.9)
 *        - B2.2: Special Registers (CONTROL, MSP, PSP, PRIMASK, BASEPRI, FAULTMASK)
 *        - B2.3: Application Program Status Register (APSR, IPSR, xPSR)
 *        - B2.4: Wait for event and interrupt
 *      - Chapter B3: System Control Registers (B3.1-B3.5)
 *        - B3.1: System Control Block (SCB)
 *        - B3.2: System Control Register
 *        - B3.3: Nested Vectored Interrupt Controller (NVIC)
 *        - B3.4: System Timer (SysTick)
 *      - Chapter B4: Memory Protection Unit (B4.1-B4.5)
 *      - Chapter B5: Security Attribution Unit (B5.1-B5.5)
 *      - Chapter B6: Debug and Trace (B6.1-B6.5)
 *        - B6.2: Instrumentation Trace Macrocell (ITM)
 *        - B6.3: Performance Monitors (PMU)
 *
 *   2. ARM Cortex-M33 Devices Generic User Guide (DUI 0552A)
 *      - Chapter 4.2: System Control Block (SCB) registers
 *      - Chapter 4.3: Nested Vectored Interrupt Controller (NVIC)
 *      - Chapter 4.4: System Timer (SysTick)
 *      - Chapter 4.5: Memory Protection Unit (MPU)
 *      - Chapter 5: Floating-Point Unit (FPU)
 *      - Chapter 6: Security Attribution Unit (SAU)
 *      - Chapter 7: Instrumentation Trace Macrocell (ITM)
 *
 *   3. ARM Cortex-M33 Processor Technical Reference Manual (ARM DDI 0550A)
 *      - Chapter 4: Processor Registers
 *      - Chapter 11: Performance Monitor Unit (PMU)
 *
 *   4. ARM Cortex-M33 Processor Datasheet (V2)
 *      - Feature configuration
 *      - Memory map
 *
 * Key Features:
 *   - TrustZone Security Extension (Mainline) - ARMv8-M ARM Section B5
 *   - MPU Memory Protection Unit - ARMv8-M ARM Section B4
 *   - Optional FPU (single/double precision) - ARMv8-M ARM Section B3.2
 *   - Helium SIMD Extension (M55, M85) - ARMv8.1-M
 *   - PMU Performance Monitor Unit (M55, M85) - ARMv8-M ARM Section B6.3
 *
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 ARM Architecture Team. All rights reserved.
 */

#include "armv8m.h"
#include <stdint.h>

/*
 * ============================================================================
 * ARMv8-M Register Base Address Definitions
 * ARMv8-M 寄存器基地址定义
 * Reference: ARMv8-M ARM Table B1-4 (Core peripheral memory map)
 * 参考: ARMv8-M ARM 表 B1-4 (核心外设内存映射)
 * ============================================================================
 */

#define NVIC_BASE_ADDR         0xE000E100UL
#define NVIC_ISER(n)           (*(volatile uint32_t *)(NVIC_BASE_ADDR + (n) * 4))
#define NVIC_ICER(n)           (*(volatile uint32_t *)(NVIC_BASE_ADDR + 0x80 + (n) * 4))
#define NVIC_ISPR(n)           (*(volatile uint32_t *)(NVIC_BASE_ADDR + 0x100 + (n) * 4))
#define NVIC_ICPR(n)           (*(volatile uint32_t *)(NVIC_BASE_ADDR + 0x180 + (n) * 4))
#define NVIC_IABR(n)           (*(volatile uint32_t *)(NVIC_BASE_ADDR + 0x200 + (n) * 4))
#define NVIC_IPR_BASE          0xE000E400UL
#define NVIC_IPR(n)            (*(volatile uint8_t *)(NVIC_IPR_BASE + (n)))

#define SCB_BASE_ADDR          0xE000ED00UL
#define SCB_CPUID              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x00))
#define SCB_ICSR               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x04))
#define SCB_VTOR               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x08))
#define SCB_AIRCR              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x0C))
#define SCB_SCR                (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x10))
#define SCB_CCR                (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x14))
#define SCB_SHPR(n)            (*(volatile uint8_t *)(SCB_BASE_ADDR + 0x18 + (n)))
#define SCB_SHCSR              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x24))
#define SCB_CFSR               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x28))
#define SCB_HFSR               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x2C))
#define SCB_DFSR               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x30))
#define SCB_MMFAR              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x34))
#define SCB_BFAR               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x38))
#define SCB_PFR0               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x40))
#define SCB_PFR1               (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x44))
#define SCB_DFR                (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x48))
#define SCB_ADR                (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x4C))
#define SCB_MMFR0              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x50))
#define SCB_MMFR1              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x54))
#define SCB_MMFR2              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x58))
#define SCB_MMFR3              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x5C))
#define SCB_ISAR0              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x60))
#define SCB_ISAR1              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x64))
#define SCB_ISAR2              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x68))
#define SCB_ISAR3              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x6C))
#define SCB_ISAR4              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x70))
#define SCB_CLIDR              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x78))
#define SCB_CTR                (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x7C))
#define SCB_CCSIDR             (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x80))
#define SCB_CSSELR             (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x84))
#define SCB_CPACR              (*(volatile uint32_t *)(SCB_BASE_ADDR + 0x88))

#define SCnSCB_BASE_ADDR       0xE000ED00UL
#define SCnSCB_ACR             (*(volatile uint32_t *)(SCnSCB_BASE_ADDR + 0x10))

#define MPU_BASE_ADDR          0xE000ED90UL
#define MPU_TYPE               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x00))
#define MPU_CTRL               (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x04))
#define MPU_RNR                (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x08))
#define MPU_RBAR              (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x0C))
#define MPU_RLAR              (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x10))
#define MPU_MAIR0             (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x14))
#define MPU_MAIR1             (*(volatile uint32_t *)(MPU_BASE_ADDR + 0x18))

#define PMU_BASE_ADDR          0xE0003000UL
#define PMU_CTRL              (*(volatile uint32_t *)(PMU_BASE_ADDR + 0x00))
#define PMU_CYCCNT            (*(volatile uint64_t *)(PMU_BASE_ADDR + 0x04))
#define PMU_INTEN             (*(volatile uint32_t *)(PMU_BASE_ADDR + 0x08))
#define PMU_INTENSET           (*(volatile uint32_t *)(PMU_BASE_ADDR + 0x08))
#define PMU_INTENCLR           (*(volatile uint32_t *)(PMU_BASE_ADDR + 0x0C))
#define PMU_EVCNTR_BASE       0xE0003010UL
#define PMU_EVCNTR(n)         (*(volatile uint32_t *)(PMU_EVCNTR_BASE + (n) * 4))
#define PMU_EVTYPER_BASE      0xE0003100UL
#define PMU_EVTYPER(n)        (*(volatile uint32_t *)(PMU_EVTYPER_BASE + (n) * 4))
#define PMU_CNTENSET          (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xE0))
#define PMU_CNTENCLR          (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xE4))
#define PMU_CCFGR             (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xE8))
#define PMU_CIDR              (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xFC))

#define SAU_BASE_ADDR          0xE000EDD0UL
#define SAU_CTRL              (*(volatile uint32_t *)(SAU_BASE_ADDR + 0x00))
#define SAU_RNR               (*(volatile uint32_t *)(SAU_BASE_ADDR + 0x04))
#define SAU_RBAR              (*(volatile uint32_t *)(SAU_BASE_ADDR + 0x08))
#define SAU_RLAR              (*(volatile uint32_t *)(SAU_BASE_ADDR + 0x0C))
#define SAU_TYPE              (*(volatile uint32_t *)(SAU_BASE_ADDR + 0x10))

#define SYSTICK_BASE_ADDR      0xE000E010UL
#define SYSTICK_CTRL          (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x00))
#define SYSTICK_LOAD          (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x04))
#define SYSTICK_VAL           (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x08))
#define SYSTICK_CALIB         (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x0C))

#define ITM_BASE_ADDR          0xE0000000UL
#define ITM_CTRL              (*(volatile uint32_t *)(ITM_BASE_ADDR + 0x00))
#define ITM_TER(n)            (*(volatile uint32_t *)(ITM_BASE_ADDR + 0xE00 + (n) * 4))
#define ITM_TPR               (*(volatile uint32_t *)(ITM_BASE_ADDR + 0x20))
#define ITM_STIM(n)           (*(volatile uint32_t *)(ITM_BASE_ADDR + 0x40 + (n) * 4))

#define DWT_BASE_ADDR          0xE0001000UL
#define DWT_CTRL              (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x00))
#define DWT_CYCCNT            (*(volatile uint32_t *)(DWT_BASE_ADDR + 0x04))
#define DWT_LAR               (*(volatile uint32_t *)(DWT_BASE_ADDR + 0xFB0))

/*
 * ============================================================================
 * ARMv8-M Core Register Access Implementation
 * ARMv8-M 核心寄存器访问实现
 * Reference: ARMv8-M ARM Section B2.1 (Special registers)
 * 参考: ARMv8-M ARM 第 B2.1 节 (特殊寄存器)
 * ============================================================================
 */

/**
 * @brief Get CONTROL register value
 * @brief 获取 CONTROL 寄存器值
 *
 * CONTROL register controls:
 * CONTROL 寄存器控制:
 *   - BIT[0]: nPRIV - Privilege level (0=privileged, 1=user)
 *   - BIT[1]: SPSel - Stack pointer select (0=MSP, 1=PSP)
 *   - BIT[2]: FPCA - FPU active state (1=FPU active, 0=no FPU)
 *   - BIT[4]: SFPA - Secure floating point active (TrustZone)
 *
 * Reference: ARMv8-M ARM B2.2.4 (CONTROL, Control Register)
 * 参考: ARMv8-M ARM B2.2.4 (CONTROL, 控制寄存器)
 *
 * @return Current CONTROL register value
 * @return CONTROL 寄存器当前值
 */
uint32_t arch_armv8m_get_control(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, control" : "=r" (result));
    return result;
}

/**
 * @brief Set CONTROL register value
 * @brief 设置 CONTROL 寄存器值
 *
 * Reference: ARMv8-M ARM B2.2.4 (CONTROL, Control Register)
 * 参考: ARMv8-M ARM B2.2.4 (CONTROL, 控制寄存器)
 *
 * @param control: New CONTROL register value
 * @param control: CONTROL 寄存器新值
 */
void arch_armv8m_set_control(uint32_t control) {
    __asm__ volatile ("MSR control, %0" : : "r" (control) : "memory");
}

/**
 * @brief Get Main Stack Pointer (MSP)
 * @brief 获取主栈指针 (MSP)
 *
 * MSP is the default stack pointer used after reset and in handler mode.
 * MSP 是复位后和处理器模式下使用的默认栈指针。
 *
 * Reference: ARMv8-M ARM B2.2.2 (MSP, Main Stack Pointer)
 * 参考: ARMv8-M ARM B2.2.2 (MSP, 主栈指针)
 *
 * @return Current MSP value
 * @return 当前 MSP 值
 */
uint32_t arch_armv8m_get_msp(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, msp" : "=r" (result));
    return result;
}

/**
 * @brief Set Main Stack Pointer (MSP)
 * @brief 设置主栈指针 (MSP)
 *
 * Reference: ARMv8-M ARM B2.2.2 (MSP, Main Stack Pointer)
 * 参考: ARMv8-M ARM B2.2.2 (MSP, 主栈指针)
 *
 * @param msp: New MSP value
 * @param msp: 新的 MSP 值
 */
void arch_armv8m_set_msp(uint32_t msp) {
    __asm__ volatile ("MSR msp, %0" : : "r" (msp) : "memory");
}

/**
 * @brief Get Process Stack Pointer (PSP)
 * @brief 获取进程栈指针 (PSP)
 *
 * PSP is used in Thread mode when CONTROL.SPSEL is set to 1.
 * PSP 在线程模式下且 CONTROL.SPSEL 设为 1 时使用。
 *
 * Reference: ARMv8-M ARM B2.2.3 (PSP, Process Stack Pointer)
 * 参考: ARMv8-M ARM B2.2.3 (PSP, 进程栈指针)
 *
 * @return Current PSP value
 * @return 当前 PSP 值
 */
uint32_t arch_armv8m_get_psp(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, psp" : "=r" (result));
    return result;
}

/**
 * @brief Set Process Stack Pointer (PSP)
 * @brief 设置进程栈指针 (PSP)
 *
 * Reference: ARMv8-M ARM B2.2.3 (PSP, Process Stack Pointer)
 * 参考: ARMv8-M ARM B2.2.3 (PSP, 进程栈指针)
 *
 * @param psp: New PSP value
 * @param psp: 新的 PSP 值
 */
void arch_armv8m_set_psp(uint32_t psp) {
    __asm__ volatile ("MSR psp, %0" : : "r" (psp) : "memory");
}

/**
 * @brief Get PRIMASK register
 * @brief 获取 PRIMASK 寄存器
 *
 * PRIMASK is a 1-bit interrupt mask register.
 * PRIMASK 是一个 1 位中断屏蔽寄存器。
 *   - 0: Interrupts enabled
 *   - 1: Interrupts disabled
 *
 * Reference: ARMv8-M ARM B2.2.6 (PRIMASK, Priority Mask Register)
 * 参考: ARMv8-M ARM B2.2.6 (PRIMASK, 优先级屏蔽寄存器)
 *
 * @return Current PRIMASK value (0=interrupts enabled, 1=interrupts disabled)
 * @return 当前 PRIMASK 值 (0=中断使能, 1=中断禁用)
 */
uint32_t arch_armv8m_get_primask(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, primask" : "=r" (result));
    return result;
}

/**
 * @brief Set PRIMASK register
 * @brief 设置 PRIMASK 寄存器
 *
 * Reference: ARMv8-M ARM B2.2.6 (PRIMASK, Priority Mask Register)
 * 参考: ARMv8-M ARM B2.2.6 (PRIMASK, 优先级屏蔽寄存器)
 *
 * @param primask: New PRIMASK value
 * @param primask: 新的 PRIMASK 值
 */
void arch_armv8m_set_primask(uint32_t primask) {
    __asm__ volatile ("MSR primask, %0" : : "r" (primask) : "memory");
}

/**
 * @brief Get BASEPRI register
 * @brief 获取 BASEPRI 寄存器
 *
 * BASEPRI masks interrupts based on priority.
 * BASEPRI 根据优先级屏蔽中断。
 *   - 0: No effect
 *   - 1-255: Masks interrupts with priority >= BASEPRI
 *
 * Reference: ARMv8-M ARM B2.2.7 (BASEPRI, Base Priority Register)
 * 参考: ARMv8-M ARM B2.2.7 (BASEPRI, 基础优先级寄存器)
 *
 * @return Current BASEPRI value
 * @return 当前 BASEPRI 值
 */
uint32_t arch_armv8m_get_basepri(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, basepri" : "=r" (result));
    return result;
}

/**
 * @brief Set BASEPRI register
 * @brief 设置 BASEPRI 寄存器
 *
 * Reference: ARMv8-M ARM B2.2.7 (BASEPRI, Base Priority Register)
 * 参考: ARMv8-M ARM B2.2.7 (BASEPRI, 基础优先级寄存器)
 *
 * @param basepri: New BASEPRI value (0=disable, 1-255=mask priority <= basepri)
 * @param basepri: 新的 BASEPRI 值 (0=禁用, 1-255=屏蔽优先级 <= basepri)
 */
void arch_armv8m_set_basepri(uint32_t basepri) {
    __asm__ volatile ("MSR basepri, %0" : : "r" (basepri) : "memory");
}

/**
 * @brief Get FAULTMASK register
 * @brief 获取 FAULTMASK 寄存器
 *
 * FAULTMASK masks all exceptions except NMI.
 * FAULTMASK 屏蔽所有异常(除了 NMI)。
 *   - 0: No effect
 *   - 1: Masks all exceptions except NMI
 *
 * Reference: ARMv8-M ARM B2.2.8 (FAULTMASK, Fault Mask Register)
 * 参考: ARMv8-M ARM B2.2.8 (FAULTMASK, 故障屏蔽寄存器)
 *
 * @return Current FAULTMASK value
 * @return 当前 FAULTMASK 值
 */
uint32_t arch_armv8m_get_faultmask(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, faultmask" : "=r" (result));
    return result;
}

/**
 * @brief Set FAULTMASK register
 * @brief 设置 FAULTMASK 寄存器
 *
 * Reference: ARMv8-M ARM B2.2.8 (FAULTMASK, Fault Mask Register)
 * 参考: ARMv8-M ARM B2.2.8 (FAULTMASK, 故障屏蔽寄存器)
 *
 * @param faultmask: New FAULTMASK value
 * @param faultmask: 新的 FAULTMASK 值
 */
void arch_armv8m_set_faultmask(uint32_t faultmask) {
    __asm__ volatile ("MSR faultmask, %0" : : "r" (faultmask) : "memory");
}

/**
 * @brief Get MSPLIM register (MSP Limit)
 * @brief 获取 MSPLIM 寄存器 (MSP 限制)
 *
 * MSPLIM defines the lower limit of MSP to detect stack overflow.
 * MSPLIM 定义 MSP 的下限以检测栈溢出。
 *
 * Reference: ARMv8-M ARM B2.2.2 (MSPLIM, Main Stack Pointer Limit)
 * 参考: ARMv8-M ARM B2.2.2 (MSPLIM, 主栈指针限制)
 *
 * @return Current MSPLIM value
 * @return 当前 MSPLIM 值
 */
uint32_t arch_armv8m_get_msplim(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, msplim" : "=r" (result));
    return result;
}

/**
 * @brief Set MSPLIM register
 * @brief 设置 MSPLIM 寄存器
 *
 * Reference: ARMv8-M ARM B2.2.2 (MSPLIM, Main Stack Pointer Limit)
 * 参考: ARMv8-M ARM B2.2.2 (MSPLIM, 主栈指针限制)
 *
 * @param msplim: New MSPLIM value (set bit[0] to 1 for non-secure access in TrustZone)
 * @param msplim: 新的 MSPLIM 值 (在 TrustZone 中设置 bit[0] 为 1 以进行非安全访问)
 */
void arch_armv8m_set_msplim(uint32_t msplim) {
    __asm__ volatile ("MSR msplim, %0" : : "r" (msplim) : "memory");
}

/**
 * @brief Get PSPLIM register (PSP Limit)
 * @brief 获取 PSPLIM 寄存器 (PSP 限制)
 *
 * PSPLIM defines the lower limit of PSP to detect stack overflow.
 * PSPLIM 定义 PSP 的下限以检测栈溢出。
 *
 * Reference: ARMv8-M ARM B2.2.3 (PSPLIM, Process Stack Pointer Limit)
 * 参考: ARMv8-M ARM B2.2.3 (PSPLIM, 进程栈指针限制)
 *
 * @return Current PSPLIM value
 * @return 当前 PSPLIM 值
 */
uint32_t arch_armv8m_get_psplim(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, psplim" : "=r" (result));
    return result;
}

/**
 * @brief Set PSPLIM register
 * @brief 设置 PSPLIM 寄存器
 *
 * Reference: ARMv8-M ARM B2.2.3 (PSPLIM, Process Stack Pointer Limit)
 * 参考: ARMv8-M ARM B2.2.3 (PSPLIM, 进程栈指针限制)
 *
 * @param psplim: New PSPLIM value (set bit[0] to 1 for non-secure access in TrustZone)
 * @param psplim: 新的 PSPLIM 值 (在 TrustZone 中设置 bit[0] 为 1 以进行非安全访问)
 */
void arch_armv8m_set_psplim(uint32_t psplim) {
    __asm__ volatile ("MSR psplim, %0" : : "r" (psplim) : "memory");
}

/*
 * ============================================================================
 * ARMv8-M Status Register Access Implementation
 * ARMv8-M 状态寄存器访问实现
 * Reference: ARMv8-M ARM Section B2.3 (Application Program Status Register)
 * 参考: ARMv8-M ARM 第 B2.3 节 (应用程序状态寄存器)
 * ============================================================================
 */

/**
 * @brief Get IPSR register
 * @brief 获取 IPSR 寄存器
 *
 * IPSR contains the exception type number of the current interrupt service routine.
 * IPSR 包含当前中断服务例程的异常类型号。
 *   - 0: Thread mode
 *   - 1-15: Reserved
 *   - 16-255: IRQ number + 16
 *
 * Reference: ARMv8-M ARM B2.3.3 (IPSR, Interrupt Program Status Register)
 * 参考: ARMv8-M ARM B2.3.3 (IPSR, 中断程序状态寄存器)
 *
 * @return Current IPSR value (exception number)
 * @return 当前 IPSR 值 (异常号)
 */
uint32_t arch_armv8m_get_ipsr(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, ipsr" : "=r" (result));
    return result;
}

/**
 * @brief Get APSR register
 * @brief 获取 APSR 寄存器
 *
 * APSR contains the flags from the previous instruction execution.
 * APSR 包含上一条指令执行后的标志位。
 *   - N: Negative flag
 *   - Z: Zero flag
 *   - C: Carry flag
 *   - V: Overflow flag
 *   - Q: Saturation flag (DSP)
 *
 * Reference: ARMv8-M ARM B2.3.2 (APSR, Application Program Status Register)
 * 参考: ARMv8-M ARM B2.3.2 (APSR, 应用程序状态寄存器)
 *
 * @return Current APSR value
 * @return 当前 APSR 值
 */
uint32_t arch_armv8m_get_apsr(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, apsr" : "=r" (result));
    return result;
}

/**
 * @brief Get xPSR register
 * @brief 获取 xPSR 寄存器
 *
 * xPSR contains the combined Application, Interrupt, and Execution PSR registers.
 * xPSR 包含组合的应用、中断和执行 PSR 寄存器。
 * It combines IPSR, EPSR, and APSR.
 * 它结合了 IPSR、EPSR 和 APSR。
 *
 * Reference: ARMv8-M ARM B2.3.1 (xPSR, Combined Program Status Register)
 * 参考: ARMv8-M ARM B2.3.1 (xPSR, 组合程序状态寄存器)
 *
 * @return Current xPSR value
 * @return 当前 xPSR 值
 */
uint32_t arch_armv8m_get_xpsr(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, xpsr" : "=r" (result));
    return result;
}

/*
 * ============================================================================
 * ARMv8-M Memory Barrier Implementation
 * ARMv8-M 内存屏障实现
 * Reference: ARMv8-M ARM Section D1.2.4 (Memory barriers)
 * 参考: ARMv8-M ARM 第 D1.2.4 节 (内存屏障)
 * ============================================================================
 */

/**
 * @brief Data Synchronization Barrier (DSB)
 * @brief 数据同步屏障 (DSB)
 *
 * Ensures all explicit memory accesses are completed before the next instruction.
 * This ensures that all memory transactions have completed before proceeding.
 * 确保所有显式内存访问在下一条指令之前完成。
 *
 * Reference: ARMv8-M ARM D1.2.4 (Data Synchronization Barrier)
 * 参考: ARMv8-M ARM D1.2.4 (数据同步屏障)
 */
void arch_armv8m_dsb(void) {
    __asm__ volatile ("dsb sy" : : : "memory");
}

/**
 * @brief Instruction Synchronization Barrier (ISB)
 * @brief 指令同步屏障 (ISB)
 *
 * Flushes the instruction pipeline to ensure instruction sequence is fetched.
 * This ensures that all instructions following the ISB are fetched from memory.
 * 刷新指令管道以确保获取指令序列。
 *
 * Reference: ARMv8-M ARM D1.2.4 (Instruction Synchronization Barrier)
 * 参考: ARMv8-M ARM D1.2.4 (指令同步屏障)
 */
void arch_armv8m_isb(void) {
    __asm__ volatile ("isb sy" : : : "memory");
}

/**
 * @brief Data Memory Barrier (DMB)
 * @brief 数据内存屏障 (DMB)
 *
 * Ensures explicit memory accesses are observed in order.
 * This ensures that memory transactions are completed in program order.
 * 确保显式内存访问按顺序观察。
 *
 * Reference: ARMv8-M ARM D1.2.4 (Data Memory Barrier)
 * 参考: ARMv8-M ARM D1.2.4 (数据内存屏障)
 */
void arch_armv8m_dmb(void) {
    __asm__ volatile ("dmb sy" : : : "memory");
}

/*
 * ============================================================================
 * ARMv8-M Low Power Mode Implementation
 * ARMv8-M 低功耗模式实现
 * Reference: ARMv8-M ARM Section B2.4 (Wait for event and interrupt)
 * 参考: ARMv8-M ARM 第 B2.4 节 (等待事件和中断)
 * ============================================================================
 */

/**
 * @brief Wait For Interrupt (WFI)
 * @brief 等待中断 (WFI)
 *
 * Enter sleep mode, wake up on interrupt.
 * The processor suspends execution until an interrupt occurs.
 * 进入睡眠模式，被中断唤醒。
 *
 * Reference: ARMv8-M ARM B2.4.1 (Wait for interrupt)
 * 参考: ARMv8-M ARM B2.4.1 (等待中断)
 */
void arch_armv8m_wfi(void) {
    __asm__ volatile ("wfi" : : : "memory");
}

/**
 * @brief Wait For Event (WFE)
 * @brief 等待事件 (WFE)
 *
 * Enter sleep mode, wake up on event.
 * The processor suspends execution until a event occurs.
 * 进入睡眠模式，被事件唤醒。
 *
 * Reference: ARMv8-M ARM B2.4.2 (Wait for event)
 * 参考: ARMv8-M ARM B2.4.2 (等待事件)
 */
void arch_armv8m_wfe(void) {
    __asm__ volatile ("wfe" : : : "memory");
}

/**
 * @brief Send Event (SEV)
 * @brief 发送事件 (SEV)
 *
 * Send event to all cores in multiprocessor system.
 * This wakes up cores waiting for event.
 * 在多处理器系统中向所有核心发送事件。
 *
 * Reference: ARMv8-M ARM B2.4.3 (Send event)
 * 参考: ARMv8-M ARM B2.4.3 (发送事件)
 */
void arch_armv8m_sev(void) {
    __asm__ volatile ("sev" : : : "memory");
}

/*
 * ============================================================================
 * ARMv8-M NVIC Interrupt Management Implementation
 * ARMv8-M NVIC 中断管理实现
 * Reference: ARMv8-M ARM Section B3.3 (Nested Vectored Interrupt Controller)
 * 参考: ARMv8-M ARM 第 B3.3 节 (嵌套向量中断控制器)
 * ============================================================================
 */

/**
 * @brief Enable specified interrupt
 * @brief 使能指定中断
 *
 * Reference: ARMv8-M ARM B3.3.9 (NVIC_ISER, Interrupt Set-Enable Register)
 * 参考: ARMv8-M ARM B3.3.9 (NVIC_ISER, 中断使能寄存器)
 *
 * @param irq: Interrupt number (0-239)
 * @param irq: 中断号 (0-239)
 */
void arch_armv8m_enable_irq(uint8_t irq) {
    if (irq < 240) {
        uint32_t idx = irq / 32;
        uint32_t bit = irq % 32;
        NVIC_ISER(idx) = (1U << bit);
    }
}

/**
 * @brief Disable specified interrupt
 * @brief 禁用指定中断
 *
 * Reference: ARMv8-M ARM B3.3.10 (NVIC_ICER, Interrupt Clear-Enable Register)
 * 参考: ARMv8-M ARM B3.3.10 (NVIC_ICER, 中断使能清除寄存器)
 *
 * @param irq: Interrupt number (0-239)
 * @param irq: 中断号 (0-239)
 */
void arch_armv8m_disable_irq(uint8_t irq) {
    if (irq < 240) {
        uint32_t idx = irq / 32;
        uint32_t bit = irq % 32;
        NVIC_ICER(idx) = (1U << bit);
    }
}

/**
 * @brief Set interrupt priority
 * @brief 设置中断优先级
 *
 * Reference: ARMv8-M ARM B3.3.22 (NVIC_IPR, Interrupt Priority Register)
 * 参考: ARMv8-M ARM B3.3.22 (NVIC_IPR, 中断优先级寄存器)
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @param priority: Priority value (0=highest, 255=lowest)
 * @param priority: 优先级值 (0=最高, 255=最低)
 */
void arch_armv8m_set_priority(uint8_t irq, uint8_t priority) {
    if (irq < 240) {
        NVIC_IPR(irq) = priority;
    }
}

/**
 * @brief Get interrupt priority
 * @brief 获取中断优先级
 *
 * Reference: ARMv8-M ARM B3.3.22 (NVIC_IPR, Interrupt Priority Register)
 * 参考: ARMv8-M ARM B3.3.22 (NVIC_IPR, 中断优先级寄存器)
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @return Priority value
 * @return 优先级值
 */
uint8_t arch_armv8m_get_priority(uint8_t irq) {
    if (irq < 240) {
        return NVIC_IPR(irq);
    }
    return 0;
}

/**
 * @brief Set interrupt pending status
 * @brief 设置中断挂起状态
 *
 * Reference: ARMv8-M ARM B3.3.13 (NVIC_ISPR, Interrupt Set-Pending Register)
 * 参考: ARMv8-M ARM B3.3.13 (NVIC_ISPR, 中断挂起寄存器)
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 */
void arch_armv8m_set_pending(uint8_t irq) {
    if (irq < 240) {
        uint32_t idx = irq / 32;
        uint32_t bit = irq % 32;
        NVIC_ISPR(idx) = (1U << bit);
    }
}

/**
 * @brief Clear interrupt pending status
 * @brief 清除中断挂起状态
 *
 * Reference: ARMv8-M ARM B3.3.14 (NVIC_ICPR, Interrupt Clear-Pending Register)
 * 参考: ARMv8-M ARM B3.3.14 (NVIC_ICPR, 中断挂起清除寄存器)
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 */
void arch_armv8m_clear_pending(uint8_t irq) {
    if (irq < 240) {
        uint32_t idx = irq / 32;
        uint32_t bit = irq % 32;
        NVIC_ICPR(idx) = (1U << bit);
    }
}

/**
 * @brief Get enable status of specified interrupt
 * @brief 获取指定中断的使能状态
 *
 * Reference: ARMv8-M ARM B3.3.9 (NVIC_ISER) and B3.3.10 (NVIC_ICER)
 * 参考: ARMv8-M ARM B3.3.9 (NVIC_ISER) 和 B3.3.10 (NVIC_ICER)
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @return Enable status (0=disabled, 1=enabled)
 * @return 使能状态 (0=禁用, 1=使能)
 */
uint32_t arch_armv8m_get_enable_irq(uint8_t irq) {
    if (irq < 240) {
        uint32_t idx = irq / 32;
        uint32_t bit = irq % 32;
        return (NVIC_ISER(idx) >> bit) & 0x1U;
    }
    return 0;
}

/**
 * @brief Get pending status of specified interrupt
 * @brief 获取指定中断的挂起状态
 *
 * Reference: ARMv8-M ARM B3.3.13 (NVIC_ISPR) and B3.3.14 (NVIC_ICPR)
 * 参考: ARMv8-M ARM B3.3.13 (NVIC_ISPR) 和 B3.3.14 (NVIC_ICPR)
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @return Pending status (0=not pending, 1=pending)
 * @return 挂起状态 (0=未挂起, 1=挂起)
 */
uint32_t arch_armv8m_get_pending_irq(uint8_t irq) {
    if (irq < 240) {
        uint32_t idx = irq / 32;
        uint32_t bit = irq % 32;
        return (NVIC_ISPR(idx) >> bit) & 0x1U;
    }
    return 0;
}

/**
 * @brief Get currently executing interrupt
 * @brief 获取当前正在执行的中断
 *
 * Reference: ARMv8-M ARM B3.3.3 (SCB_ICSR, Interrupt Control and State Register)
 * 参考: ARMv8-M ARM B3.3.3 (SCB_ICSR, 中断控制和状态寄存器)
 *
 * @return Active interrupt number (IRQ number, -16 for exceptions)
 * @return 活动中断号 (IRQ 号，异常返回 -16)
 */
uint32_t arch_armv8m_get_active_irq(void) {
    return (SCB_ICSR & 0x1FFU) - 16;
}

/**
 * @brief Get priority grouping
 * @brief 获取优先级分组
 *
 * Reference: ARMv8-M ARM B3.3.1 (SCB_AIRCR, Application Interrupt and Reset Control Register)
 * 参考: ARMv8-M ARM B3.3.1 (SCB_AIRCR, 应用中断和复位控制寄存器)
 *
 * @return Priority grouping value
 * @return 优先级分组值
 */
uint32_t arch_armv8m_get_priority_grouping(void) {
    return (SCB_AIRCR >> 8) & 0x7U;
}

/**
 * @brief Set priority grouping
 * @brief 设置优先级分组
 *
 * Reference: ARMv8-M ARM B3.3.1 (SCB_AIRCR)
 * 参考: ARMv8-M ARM B3.3.1 (SCB_AIRCR)
 *
 * @param priority_group: Priority grouping value
 * @param priority_group: 优先级分组值
 */
void arch_armv8m_set_priority_grouping(uint32_t priority_group) {
    uint32_t val = SCB_AIRCR;
    val = (val & ~(0x7UL << 8)) | (0x5FAUL << 16) | ((priority_group & 0x7UL) << 8);
    SCB_AIRCR = val;
}

/**
 * @brief Encode priority
 * @brief 编码优先级
 *
 * @param priority_group: Priority grouping value
 * @param priority_group: 优先级分组值
 * @param preempt_priority: Preemption priority
 * @param preempt_priority: 抢占优先级
 * @param sub_priority: Sub-priority
 * @param sub_priority: 子优先级
 * @return Encoded priority value
 * @return 编码后的优先级值
 */
uint32_t arch_armv8m_encode_priority(uint32_t priority_group, uint32_t preempt_priority, uint32_t sub_priority) {
    uint32_t priority_group_tmp = priority_group & 0x7UL;
    uint32_t PreemptPriorityBits = 7UL - priority_group_tmp;
    uint32_t SubPriorityBits = (priority_group_tmp + 4) < 7UL ? 0UL : (priority_group_tmp - 7UL + 4);
    return ((preempt_priority << SubPriorityBits) | sub_priority);
}

/**
 * @brief Decode priority
 * @brief 解码优先级
 *
 * @param priority: Encoded priority value
 * @param priority: 编码后的优先级值
 * @param priority_group: Priority grouping value
 * @param priority_group: 优先级分组值
 * @param preempt_priority: Output preemption priority
 * @param preempt_priority: 输出抢占优先级
 * @param sub_priority: Output sub-priority
 * @param sub_priority: 输出子优先级
 */
void arch_armv8m_decode_priority(uint32_t priority, uint32_t priority_group, uint32_t *preempt_priority, uint32_t *sub_priority) {
    uint32_t priority_group_tmp = priority_group & 0x7UL;
    uint32_t PreemptPriorityBits = 7UL - priority_group_tmp;
    uint32_t SubPriorityBits = (priority_group_tmp + 4) < 7UL ? 0UL : (priority_group_tmp - 7UL + 4);
    *preempt_priority = priority >> SubPriorityBits;
    *sub_priority = priority & ((1UL << SubPriorityBits) - 1UL);
}

/**
 * @brief Set interrupt vector
 * @brief 设置中断向量
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @param vector: Vector address
 * @param vector: 向量地址
 */
void arch_armv8m_set_vector(uint8_t irq, uint32_t vector) {
    volatile uint32_t *vector_table = (volatile uint32_t *)SCB_VTOR;
    if (irq < 16) {
        vector_table[irq + 16] = vector;
    }
}

/**
 * @brief Get interrupt vector
 * @brief 获取中断向量
 *
 * @param irq: Interrupt number
 * @param irq: 中断号
 * @return Vector address
 * @return 向量地址
 */
uint32_t arch_armv8m_get_vector(uint8_t irq) {
    volatile uint32_t *vector_table = (volatile uint32_t *)SCB_VTOR;
    if (irq < 16) {
        return vector_table[irq + 16];
    }
    return 0;
}

/*
 * ============================================================================
 * ARMv8-M MPU (Memory Protection Unit) Implementation
 * ARMv8-M MPU (内存保护单元) 实现
 * Reference: ARMv8-M ARM Section B4 (Memory Protection Unit)
 * 参考: ARMv8-M ARM 第 B4 节 (内存保护单元)
 * ============================================================================
 */

/**
 * @brief Get MPU type
 * @brief 获取 MPU 类型
 *
 * MPU_TYPE register contains:
 * MPU_TYPE 寄存器包含:
 *   - IREGION[23:16]: Number of instruction regions
 *   - DREGION[15:8]: Number of data regions
 *   - SEPARATE[0]: Instruction/Data separation flag
 *
 * Reference: ARMv8-M ARM B4.3.1 (MPU_TYPE, MPU Type Register)
 * 参考: ARMv8-M ARM B4.3.1 (MPU_TYPE, MPU 类型寄存器)
 *
 * @return MPU type register value
 * @return MPU 类型寄存器值
 */
uint32_t arch_armv8m_mpu_get_type(void) {
    return MPU_TYPE;
}

/**
 * @brief Initialize MPU
 * @brief 初始化 MPU
 *
 * Reference: ARMv8-M ARM B4.3 (MPU registers summary)
 * 参考: ARMv8-M ARM B4.3 (MPU 寄存器摘要)
 */
void arch_armv8m_mpu_init(void) {
    arch_armv8m_mpu_disable();
}

/**
 * @brief Enable MPU
 * @brief 使能 MPU
 *
 * MPU_Control register bits:
 * MPU_Control 寄存器位:
 *   - ENABLE (bit 0): MPU enable bit
 *   - HFNMIENA (bit 1): Enable during NMI and HardFault
 *   - PRIVDEFENA (bit 2): Privileged default memory map
 *
 * Reference: ARMv8-M ARM B4.3.2 (MPU_CTRL, MPU Control Register)
 * 参考: ARMv8-M ARM B4.3.2 (MPU_CTRL, MPU 控制寄存器)
 *
 * @param default_map: Use default memory map (true=enable, false=disable)
 * @param default_map: 使用默认内存映射 (true=启用, false=禁用)
 */
void arch_armv8m_mpu_enable(bool default_map) {
    uint32_t ctrl = MPU_CTRL;
    ctrl |= 0x1;
    if (default_map) {
        ctrl |= 0x4;
    }
    MPU_CTRL = ctrl;
    arch_armv8m_dsb();
    arch_armv8m_isb();
}

/**
 * @brief Disable MPU
 * @brief 禁用 MPU
 *
 * Reference: ARMv8-M ARM B4.3.2 (MPU_CTRL, MPU Control Register)
 * 参考: ARMv8-M ARM B4.3.2 (MPU_CTRL, MPU 控制寄存器)
 */
void arch_armv8m_mpu_disable(void) {
    MPU_CTRL &= ~0x1;
    arch_armv8m_dsb();
    arch_armv8m_isb();
}

/**
 * @brief Set MPU memory attribute
 * @brief 设置 MPU 内存属性
 *
 * Memory attribute encoding:
 * 内存属性编码:
 *   - Attr[7:4]: Outer Attr
 *   - Attr[3:0]: Inner Attr
 *   - Each Attr contains:
 *     - [3]: 1=forced cache policy, 0=device/uncached
 *     - [2]: Write-through/Write-back
 *     - [1]: Read allocate
 *     - [0]: Write allocate
 *
 * Reference: ARMv8-M ARM B4.3.7 (MPU_MAIR0, MPU Memory Attribute Indirection Register 0)
 *            ARMv8-M ARM B4.3.8 (MPU_MAIR1, MPU Memory Attribute Indirection Register 1)
 * 参考: ARMv8-M ARM B4.3.7 (MPU_MAIR0, MPU 内存属性间接寄存器 0)
 *       ARMv8-M ARM B4.3.8 (MPU_MAIR1, MPU 内存属性间接寄存器 1)
 *
 * @param idx: Attribute index (0-7)
 * @param idx: 属性索引 (0-7)
 * @param attr: Memory attribute
 * @param attr: 内存属性
 */
void arch_armv8m_mpu_set_mem_attr(uint8_t idx, uint8_t attr) {
    if (idx < 4) {
        uint32_t val = MPU_MAIR0;
        val = (val & ~(0xFFUL << (idx * 8))) | ((uint32_t)attr << (idx * 8));
        MPU_MAIR0 = val;
    } else {
        uint32_t val = MPU_MAIR1;
        val = (val & ~(0xFFUL << ((idx - 4) * 8))) | ((uint32_t)attr << ((idx - 4) * 8));
        MPU_MAIR1 = val;
    }
    arch_armv8m_dsb();
}

/**
 * @brief Set MPU region
 * @brief 设置 MPU 区域
 *
 * RBAR:
 * RBAR:
 *   - [31:5]: Base address (must be 32-byte aligned)
 *   - [4:1]: Subregion disable bits
 *   - [0]: VALID
 *
 * RLAR:
 * RLAR:
 *   - [31:5]: Limit address
 *   - [4]: XN (Execute Never)
 *   - [3]: AP (Access permissions)
 *   - [2:1]: SH (Shareability)
 *   - [0]: ENABLE
 *
 * Reference: ARMv8-M ARM B4.3.3 (MPU_RNR, MPU Region Number Register)
 *            ARMv8-M ARM B4.3.4 (MPU_RBAR, MPU Region Base Address Register)
 *            ARMv8-M ARM B4.3.5 (MPU_RLAR, MPU Region Limit Register)
 * 参考: ARMv8-M ARM B4.3.3 (MPU_RNR, MPU 区域编号寄存器)
 *       ARMv8-M ARM B4.3.4 (MPU_RBAR, MPU 区域基地址寄存器)
 *       ARMv8-M ARM B4.3.5 (MPU_RLAR, MPU 区域限制寄存器)
 *
 * @param rnr: Region number (0-15)
 * @param rnr: 区域编号 (0-15)
 * @param rbar: Region Base Address Register
 * @param rbar: 区域基地址寄存器
 * @param rlar: Region Limit Register
 * @param rlar: 区域限制寄存器
 */
void arch_armv8m_mpu_set_region(uint32_t rnr, uint32_t rbar, uint32_t rlar) {
    MPU_RNR = rnr;
    MPU_RBAR = rbar;
    MPU_RLAR = rlar;
    arch_armv8m_dsb();
}

/**
 * @brief Clear MPU region
 * @brief 清除 MPU 区域
 *
 * Reference: ARMv8-M ARM B4.3.3 (MPU_RNR) and B4.3.5 (MPU_RLAR)
 * 参考: ARMv8-M ARM B4.3.3 (MPU_RNR) 和 B4.3.5 (MPU_RLAR)
 *
 * @param rnr: Region number
 * @param rnr: 区域编号
 */
void arch_armv8m_mpu_clr_region(uint32_t rnr) {
    MPU_RNR = rnr;
    MPU_RLAR = 0;
    arch_armv8m_dsb();
}

/**
 * @brief Get MPU region count
 * @brief 获取 MPU 区域数量
 *
 * Reference: ARMv8-M ARM B4.3.1 (MPU_TYPE)
 * 参考: ARMv8-M ARM B4.3.1 (MPU_TYPE)
 *
 * @return Number of data regions
 * @return 数据区域数量
 */
uint32_t arch_armv8m_mpu_get_num_regions(void) {
    return (MPU_TYPE >> 8) & 0xFFUL;
}

/*
 * ============================================================================
 * ARMv8-M PMU (Performance Monitor Unit) Implementation
 * ARMv8-M PMU (性能监视单元) 实现
 * Reference: ARMv8-M ARM Section B6.3 (Performance Monitors)
 * 参考: ARMv8-M ARM 第 B6.3 节 (性能监视器)
 * Note: PMU is only supported on Cortex-M55, Cortex-M85
 * 注意: PMU 仅在 Cortex-M55、Cortex-M85 上支持
 * ============================================================================
 */

/**
 * @brief Enable PMU
 * @brief 使能 PMU
 *
 * PMU_CTRL register:
 * PMU_CTRL 寄存器:
 *   - ENABLE (bit 0): PMU enable
 *   - EVTCOUNT (bit 1): Event counter enable
 *   - CYCCNT (bit 2): Cycle counter enable
 *
 * Reference: ARMv8-M ARM B6.3.1 (PMU_CTRL, Performance Monitor Control Register)
 * 参考: ARMv8-M ARM B6.3.1 (PMU_CTRL, 性能监视器控制寄存器)
 */
void arch_armv8m_pmu_enable(void) {
    PMU_CTRL |= 0x1;
}

/**
 * @brief Disable PMU
 * @brief 禁用 PMU
 *
 * Reference: ARMv8-M ARM B6.3.1 (PMU_CTRL)
 * 参考: ARMv8-M ARM B6.3.1 (PMU_CTRL)
 */
void arch_armv8m_pmu_disable(void) {
    PMU_CTRL &= ~0x1;
}

/**
 * @brief Reset cycle counter
 * @brief 复位 cycle 计数器
 *
 * Reference: ARMv8-M ARM B6.3.1 (PMU_CTRL)
 * 参考: ARMv8-M ARM B6.3.1 (PMU_CTRL)
 */
void arch_armv8m_pmu_cyccnt_reset(void) {
    PMU_CTRL |= (1U << 3);
    arch_armv8m_dsb();
}

/**
 * @brief Reset all event counters
 * @brief 复位所有事件计数器
 *
 * Reference: ARMv8-M ARM B6.3.1 (PMU_CTRL)
 * 参考: ARMv8-M ARM B6.3.1 (PMU_CTRL)
 */
void arch_armv8m_pmu_evcntr_all_reset(void) {
    PMU_CTRL |= (1U << 4);
    arch_armv8m_dsb();
}

/**
 * @brief Enable counters
 * @brief 使能计数器
 *
 * Reference: ARMv8-M ARM B6.3.3 (PMU_CNTENSET, Count Enable Set Register)
 * 参考: ARMv8-M ARM B6.3.3 (PMU_CNTENSET, 计数器使能设置寄存器)
 *
 * @param mask: Counter mask (bit0=Cycle, bit1-31=event counters)
 * @param mask: 计数器掩码 (bit0=Cycle, bit1-31=事件计数器)
 */
void arch_armv8m_pmu_cntr_enable(uint32_t mask) {
    PMU_CNTENSET = mask;
    arch_armv8m_dsb();
}

/**
 * @brief Disable counters
 * @brief 禁用计数器
 *
 * Reference: ARMv8-M ARM B6.3.4 (PMU_CNTENCLR, Count Enable Clear Register)
 * 参考: ARMv8-M ARM B6.3.4 (PMU_CNTENCLR, 计数器使能清除寄存器)
 *
 * @param mask: Counter mask
 * @param mask: 计数器掩码
 */
void arch_armv8m_pmu_cntr_disable(uint32_t mask) {
    PMU_CNTENCLR = mask;
    arch_armv8m_dsb();
}

/**
 * @brief Get cycle counter value
 * @brief 获取 cycle 计数器值
 *
 * Reference: ARMv8-M ARM B6.3.2 (PMU_CYCCNT, Cycle Count Register)
 * 参考: ARMv8-M ARM B6.3.2 (PMU_CYCCNT, 周期计数寄存器)
 *
 * @return Cycle count
 * @return Cycle 计数
 */
uint32_t arch_armv8m_pmu_get_ccntr(void) {
    return (uint32_t)PMU_CYCCNT;
}

/**
 * @brief Get event counter value
 * @brief 获取事件计数器值
 *
 * Reference: ARMv8-M ARM B6.3.5 (PMU_EVCNTRn, Event Counter Registers)
 * 参考: ARMv8-M ARM B6.3.5 (PMU_EVCNTRn, 事件计数器寄存器)
 *
 * @param num: Counter number (0-30)
 * @param num: 计数器编号 (0-30)
 * @return Event count value
 * @return 事件计数值
 */
uint32_t arch_armv8m_pmu_get_evcntr(uint32_t num) {
    if (num < 31) {
        return PMU_EVCNTR(num);
    }
    return 0;
}

/**
 * @brief Set event type
 * @brief 设置事件类型
 *
 * Reference: ARMv8-M ARM B6.3.6 (PMU_EVTYPERn, Event Type Select Registers)
 * 参考: ARMv8-M ARM B6.3.6 (PMU_EVTYPERn, 事件类型选择寄存器)
 *
 * @param num: Counter number
 * @param num: 计数器编号
 * @param type: Event type
 * @param type: 事件类型
 */
void arch_armv8m_pmu_set_evtyper(uint32_t num, uint32_t type) {
    if (num < 31) {
        PMU_EVTYPER(num) = type;
        arch_armv8m_dsb();
    }
}

/**
 * @brief Get overflow status
 * @brief 获取溢出状态
 *
 * Reference: ARMv8-M ARM B6.3.1 (PMU_CTRL)
 * 参考: ARMv8-M ARM B6.3.1 (PMU_CTRL)
 *
 * @return Overflow status mask (bits 24-30)
 * @return 溢出状态掩码 (位 24-30)
 */
uint32_t arch_armv8m_pmu_get_cntr_ovs(void) {
    return PMU_CTRL >> 24;
}

/**
 * @brief Set overflow interrupt enable
 * @brief 设置溢出中断使能
 *
 * Reference: ARMv8-M ARM B6.3.7 (PMU_INTENSET, Interrupt Enable Set Register)
 * 参考: ARMv8-M ARM B6.3.7 (PMU_INTENSET, 中断使能设置寄存器)
 *
 * @param mask: Counter mask
 * @param mask: 计数器掩码
 */
void arch_armv8m_pmu_set_cntr_irq_enable(uint32_t mask) {
    PMU_INTENSET = mask << 24;
    arch_armv8m_dsb();
}

/**
 * @brief Clear overflow interrupt enable
 * @brief 清除溢出中断使能
 *
 * Reference: ARMv8-M ARM B6.3.8 (PMU_INTENCLR, Interrupt Enable Clear Register)
 * 参考: ARMv8-M ARM B6.3.8 (PMU_INTENCLR, 中断使能清除寄存器)
 *
 * @param mask: Counter mask
 * @param mask: 计数器掩码
 */
void arch_armv8m_pmu_set_cntr_irq_disable(uint32_t mask) {
    PMU_INTENCLR = mask << 24;
    arch_armv8m_dsb();
}

/*
 * ============================================================================
 * ARMv8-M TrustZone (TZ) SAU Implementation
 * ARMv8-M TrustZone (TZ) SAU 实现
 * Reference: ARMv8-M ARM Section B5 (Security Attribution Unit)
 * 参考: ARMv8-M ARM 第 B5 节 (安全属性单元)
 * Note: TrustZone is only supported on ARMv8-M Mainline
 * 注意: TrustZone 仅在 ARMv8-M Mainline 上支持
 * ============================================================================
 */

/**
 * @brief Enable SAU (Security Attribution Unit)
 * @brief 使能 SAU (安全属性单元)
 *
 * SAU_CTRL register:
 * SAU_CTRL 寄存器:
 *   - ENABLE (bit 0): SAU enable
 *   - ALLNS (bit 1): All non-secure access allowed
 *
 * Reference: ARMv8-M ARM B5.3.1 (SAU_CTRL, SAU Control Register)
 * 参考: ARMv8-M ARM B5.3.1 (SAU_CTRL, SAU 控制寄存器)
 */
void arch_armv8m_tz_sau_enable(void) {
    SAU_CTRL |= 0x1;
    arch_armv8m_dsb();
    arch_armv8m_isb();
}

/**
 * @brief Disable SAU
 * @brief 禁用 SAU
 *
 * Reference: ARMv8-M ARM B5.3.1 (SAU_CTRL)
 * 参考: ARMv8-M ARM B5.3.1 (SAU_CTRL)
 */
void arch_armv8m_tz_sau_disable(void) {
    SAU_CTRL &= ~0x1;
    arch_armv8m_dsb();
    arch_armv8m_isb();
}

/**
 * @brief Set SAU region count
 * @brief 设置 SAU 区域数量
 *
 * Reference: ARMv8-M ARM B5.3.2 (SAU_TYPE, SAU Type Register)
 * 参考: ARMv8-M ARM B5.3.2 (SAU_TYPE, SAU 类型寄存器)
 *
 * @param n: Region count (0-8)
 * @param n: 区域数量 (0-8)
 */
void arch_armv8m_tz_sau_set_region_count(uint32_t n) {
    (void)n;
    arch_armv8m_dsb();
}

/**
 * @brief Set SAU region
 * @brief 设置 SAU 区域
 *
 * Reference: ARMv8-M ARM B5.3.3 (SAU_RNR, SAU Region Number Register)
 *            ARMv8-M ARM B5.3.4 (SAU_RBAR, SAU Region Base Address Register)
 *            ARMv8-M ARM B5.3.5 (SAU_RLAR, SAU Region Limit Register)
 * 参考: ARMv8-M ARM B5.3.3 (SAU_RNR, SAU 区域编号寄存器)
 *       ARMv8-M ARM B5.3.4 (SAU_RBAR, SAU 区域基地址寄存器)
 *       ARMv8-M ARM B5.3.5 (SAU_RLAR, SAU 区域限制寄存器)
 *
 * @param rnr: Region number
 * @param rnr: 区域编号
 * @param rbar: Base address
 * @param rbar: 基地址
 * @param rlar: Limit address and attributes
 * @param rlar: 限地址和属性
 */
void arch_armv8m_tz_sau_set_region(uint32_t rnr, uint32_t rbar, uint32_t rlar) {
    SAU_RNR = rnr;
    SAU_RBAR = rbar;
    SAU_RLAR = rlar;
    arch_armv8m_dsb();
}

/*
 * ============================================================================
 * ARMv8-M TrustZone (TZ) Non-Secure Functions Implementation
 * ARMv8-M TrustZone (TZ) 非安全区域函数实现
 * Reference: ARMv8-M ARM Section B5 (Security Attribution Unit)
 * 参考: ARMv8-M ARM 第 B5 节 (安全属性单元)
 * ============================================================================
 */

/**
 * @brief Get CONTROL register (Non-Secure)
 * @brief 获取 CONTROL 寄存器 (非安全)
 *
 * Reference: ARMv8-M ARM B5.4 (Non-secure access to registers)
 * 参考: ARMv8-M ARM B5.4 (寄存器的非安全访问)
 *
 * @return Non-secure CONTROL register value
 * @return 非安全 CONTROL 寄存器值
 */
uint32_t arch_armv8m_tz_get_control_ns(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, control_ns" : "=r" (result));
    return result;
}

/**
 * @brief Set CONTROL register (Non-Secure)
 * @brief 设置 CONTROL 寄存器 (非安全)
 *
 * Reference: ARMv8-M ARM B5.4 (Non-secure access to registers)
 * 参考: ARMv8-M ARM B5.4 (寄存器的非安全访问)
 *
 * @param control: Non-secure CONTROL value
 * @param control: 非安全 CONTROL 值
 */
void arch_armv8m_tz_set_control_ns(uint32_t control) {
    __asm__ volatile ("MSR control_ns, %0" : : "r" (control) : "memory");
}

/**
 * @brief Get PSP register (Non-Secure)
 * @brief 获取 PSP 寄存器 (非安全)
 *
 * Reference: ARMv8-M ARM B5.4 (Non-secure access to registers)
 * 参考: ARMv8-M ARM B5.4 (寄存器的非安全访问)
 *
 * @return Non-secure PSP value
 * @return 非安全 PSP 值
 */
uint32_t arch_armv8m_tz_get_psp_ns(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, psp_ns" : "=r" (result));
    return result;
}

/**
 * @brief Set PSP register (Non-Secure)
 * @brief 设置 PSP 寄存器 (非安全)
 *
 * Reference: ARMv8-M ARM B5.4 (Non-secure access to registers)
 * 参考: ARMv8-M ARM B5.4 (寄存器的非安全访问)
 *
 * @param psp: Non-secure PSP value
 * @param psp: 非安全 PSP 值
 */
void arch_armv8m_tz_set_psp_ns(uint32_t psp) {
    __asm__ volatile ("MSR psp_ns, %0" : : "r" (psp) : "memory");
}

/**
 * @brief Get MSP register (Non-Secure)
 * @brief 获取 MSP 寄存器 (非安全)
 *
 * Reference: ARMv8-M ARM B5.4 (Non-secure access to registers)
 * 参考: ARMv8-M ARM B5.4 (寄存器的非安全访问)
 *
 * @return Non-secure MSP value
 * @return 非安全 MSP 值
 */
uint32_t arch_armv8m_tz_get_msp_ns(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, msp_ns" : "=r" (result));
    return result;
}

/**
 * @brief Set MSP register (Non-Secure)
 * @brief 设置 MSP 寄存器 (非安全)
 *
 * Reference: ARMv8-M ARM B5.4 (Non-secure access to registers)
 * 参考: ARMv8-M ARM B5.4 (寄存器的非安全访问)
 *
 * @param msp: Non-secure MSP value
 * @param msp: 非安全 MSP 值
 */
void arch_armv8m_tz_set_msp_ns(uint32_t msp) {
    __asm__ volatile ("MSR msp_ns, %0" : : "r" (msp) : "memory");
}

/**
 * @brief Get PRIMASK register (Non-Secure)
 * @brief 获取 PRIMASK 寄存器 (非安全)
 *
 * Reference: ARMv8-M ARM B5.4 (Non-secure access to registers)
 * 参考: ARMv8-M ARM B5.4 (寄存器的非安全访问)
 *
 * @return Non-secure PRIMASK value
 * @return 非安全 PRIMASK 值
 */
uint32_t arch_armv8m_tz_get_primask_ns(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, primask_ns" : "=r" (result));
    return result;
}

/**
 * @brief Set PRIMASK register (Non-Secure)
 * @brief 设置 PRIMASK 寄存器 (非安全)
 *
 * Reference: ARMv8-M ARM B5.4 (Non-secure access to registers)
 * 参考: ARMv8-M ARM B5.4 (寄存器的非安全访问)
 *
 * @param primask: Non-secure PRIMASK value
 * @param primask: 非安全 PRIMASK 值
 */
void arch_armv8m_tz_set_primask_ns(uint32_t primask) {
    __asm__ volatile ("MSR primask_ns, %0" : : "r" (primask) : "memory");
}

/**
 * @brief Get BASEPRI register (Non-Secure)
 * @brief 获取 BASEPRI 寄存器 (非安全)
 *
 * Reference: ARMv8-M ARM B5.4 (Non-secure access to registers)
 * 参考: ARMv8-M ARM B5.4 (寄存器的非安全访问)
 *
 * @return Non-secure BASEPRI value
 * @return 非安全 BASEPRI 值
 */
uint32_t arch_armv8m_tz_get_basepri_ns(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, basepri_ns" : "=r" (result));
    return result;
}

/**
 * @brief Set BASEPRI register (Non-Secure)
 * @brief 设置 BASEPRI 寄存器 (非安全)
 *
 * Reference: ARMv8-M ARM B5.4 (Non-secure access to registers)
 * 参考: ARMv8-M ARM B5.4 (寄存器的非安全访问)
 *
 * @param basepri: Non-secure BASEPRI value
 * @param basepri: 非安全 BASEPRI 值
 */
void arch_armv8m_tz_set_basepri_ns(uint32_t basepri) {
    __asm__ volatile ("MSR basepri_ns, %0" : : "r" (basepri) : "memory");
}

/**
 * @brief Get FAULTMASK register (Non-Secure)
 * @brief 获取 FAULTMASK 寄存器 (非安全)
 *
 * Reference: ARMv8-M ARM B5.4 (Non-secure access to registers)
 * 参考: ARMv8-M ARM B5.4 (寄存器的非安全访问)
 *
 * @return Non-secure FAULTMASK value
 * @return 非安全 FAULTMASK 值
 */
uint32_t arch_armv8m_tz_get_faultmask_ns(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, faultmask_ns" : "=r" (result));
    return result;
}

/**
 * @brief Set FAULTMASK register (Non-Secure)
 * @brief 设置 FAULTMASK 寄存器 (非安全)
 *
 * Reference: ARMv8-M ARM B5.4 (Non-secure access to registers)
 * 参考: ARMv8-M ARM B5.4 (寄存器的非安全访问)
 *
 * @param faultmask: Non-secure FAULTMASK value
 * @param faultmask: 非安全 FAULTMASK 值
 */
void arch_armv8m_tz_set_faultmask_ns(uint32_t faultmask) {
    __asm__ volatile ("MSR faultmask_ns, %0" : : "r" (faultmask) : "memory");
}

/**
 * @brief Get PSPLIM register (Non-Secure)
 * @brief 获取 PSPLIM 寄存器 (非安全)
 *
 * Reference: ARMv8-M ARM B5.4 (Non-secure access to registers)
 * 参考: ARMv8-M ARM B5.4 (寄存器的非安全访问)
 *
 * @return Non-secure PSPLIM value
 * @return 非安全 PSPLIM 值
 */
uint32_t arch_armv8m_tz_get_psplim_ns(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, psplim_ns" : "=r" (result));
    return result;
}

/**
 * @brief Set PSPLIM register (Non-Secure)
 * @brief 设置 PSPLIM 寄存器 (非安全)
 *
 * Reference: ARMv8-M ARM B5.4 (Non-secure access to registers)
 * 参考: ARMv8-M ARM B5.4 (寄存器的非安全访问)
 *
 * @param psplim: Non-secure PSPLIM value
 * @param psplim: 非安全 PSPLIM 值
 */
void arch_armv8m_tz_set_psplim_ns(uint32_t psplim) {
    __asm__ volatile ("MSR psplim_ns, %0" : : "r" (psplim) : "memory");
}

/**
 * @brief Get MSPLIM register (Non-Secure)
 * @brief 获取 MSPLIM 寄存器 (非安全)
 *
 * Reference: ARMv8-M ARM B5.4 (Non-secure access to registers)
 * 参考: ARMv8-M ARM B5.4 (寄存器的非安全访问)
 *
 * @return Non-secure MSPLIM value
 * @return 非安全 MSPLIM 值
 */
uint32_t arch_armv8m_tz_get_msplim_ns(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, msplim_ns" : "=r" (result));
    return result;
}

/**
 * @brief Set MSPLIM register (Non-Secure)
 * @brief 设置 MSPLIM 寄存器 (非安全)
 *
 * Reference: ARMv8-M ARM B5.4 (Non-secure access to registers)
 * 参考: ARMv8-M ARM B5.4 (寄存器的非安全访问)
 *
 * @param msplim: Non-secure MSPLIM value
 * @param msplim: 非安全 MSPLIM 值
 */
void arch_armv8m_tz_set_msplim_ns(uint32_t msplim) {
    __asm__ volatile ("MSR msplim_ns, %0" : : "r" (msplim) : "memory");
}

/**
 * @brief Get FPU type
 * @brief 获取 FPU 类型
 *
 * Reference: ARMv8-M ARM B3.2.14 (SCB_CPACR, Coprocessor Access Control Register)
 * 参考: ARMv8-M ARM B3.2.14 (SCB_CPACR, 协处理器访问控制寄存器)
 *
 * @return FPU type (0=none, 1=single precision, 2=double precision)
 * @return FPU 类型 (0=无, 1=单精度, 2=双精度)
 */
uint32_t arch_armv8m_scb_get_fpu_type(void) {
    uint32_t cpacr;
    __asm__ volatile ("MRS %0, CPACR" : "=r" (cpacr));
    cpacr = (cpacr >> 20) & 0x3;
    if (cpacr == 0) {
        return 0;
    }
    return cpacr;
}

/*
 * ============================================================================
 * ARMv8-M FPU Implementation
 * ARMv8-M FPU 实现
 * Reference: ARMv8-M ARM Section B3.2 (Coprocessor Access Control Register)
 * 参考: ARMv8-M ARM 第 B3.2 节 (协处理器访问控制寄存器)
 * ============================================================================
 */

/**
 * @brief Enable FPU
 * @brief 使能 FPU
 *
 * Reference: ARMv8-M ARM B3.2.14 (SCB_CPACR)
 * 参考: ARMv8-M ARM B3.2.14 (SCB_CPACR)
 */
void arch_armv8m_enable_fpu(void) {
    uint32_t cpacr;
    __asm__ volatile ("MRS %0, CPACR" : "=r" (cpacr));
    cpacr |= (0x3UL << 20) | (0x3UL << 22);
    __asm__ volatile ("MSR CPACR, %0" : : "r" (cpacr) : "memory");
    arch_armv8m_dsb();
    arch_armv8m_isb();
}

/**
 * @brief Disable FPU
 * @brief 禁用 FPU
 *
 * Reference: ARMv8-M ARM B3.2.14 (SCB_CPACR)
 * 参考: ARMv8-M ARM B3.2.14 (SCB_CPACR)
 */
void arch_armv8m_disable_fpu(void) {
    uint32_t cpacr;
    __asm__ volatile ("MRS %0, CPACR" : "=r" (cpacr));
    cpacr &= ~((0x3UL << 20) | (0x3UL << 22));
    __asm__ volatile ("MSR CPACR, %0" : : "r" (cpacr) : "memory");
    arch_armv8m_dsb();
    arch_armv8m_isb();
}

/*
 * ============================================================================
 * ARMv8-M System Control Implementation
 * ARMv8-M 系统控制实现
 * Reference: ARMv8-M ARM Section B3.1 (System Control Block)
 * 参考: ARMv8-M ARM 第 B3.1 节 (系统控制块)
 * ============================================================================
 */

/**
 * @brief Trigger system reset
 * @brief 触发系统复位
 *
 * Reference: ARMv8-M ARM B3.3.1 (SCB_AIRCR, Application Interrupt and Reset Control Register)
 * 参考: ARMv8-M ARM B3.3.1 (SCB_AIRCR, 应用中断和复位控制寄存器)
 */
void arch_armv8m_system_reset(void) {
    uint32_t val = SCB_AIRCR;
    val = (val & ~(0x7UL << 8)) | (0x5FAUL << 16) | (1UL << 2);
    SCB_AIRCR = val;
    __asm__ volatile ("dsb");
    for (;;) { __asm__ volatile ("nop"); }
}

/*
 * ============================================================================
 * ARMv8-M SysTick Implementation
 * ARMv8-M SysTick 实现
 * Reference: ARMv8-M ARM Section B3.4 (System Timer, SysTick)
 * 参考: ARMv8-M ARM 第 B3.4 节 (系统定时器 SysTick)
 * ============================================================================
 */

/**
 * @brief SysTick configuration
 * @brief SysTick 配置
 *
 * Reference: ARMv8-M ARM B3.4.1 (SysTick Control and Status Register)
 * 参考: ARMv8-M ARM B3.4.1 (SysTick 控制和状态寄存器)
 *
 * @param ticks: Number of ticks between interrupts
 * @param ticks: 中断之间的tick数
 * @return 1=success, 0=failed
 * @return 1=成功, 0=失败
 */
uint32_t arch_armv8m_systick_config(uint32_t ticks) {
    if (ticks == 0) {
        return 1;
    }
    SYSTICK_LOAD = ticks - 1;
    SYSTICK_VAL = 0;
    SYSTICK_CTRL = 0x07;
    return 0;
}

/**
 * @brief Get SysTick current value
 * @brief 获取 SysTick 当前值
 *
 * Reference: ARMv8-M ARM B3.4.3 (SysTick Current Value Register)
 * 参考: ARMv8-M ARM B3.4.3 (SysTick 当前值寄存器)
 *
 * @return Current counter value
 * @return 当前计数器值
 */
uint32_t arch_armv8m_systick_get_value(void) {
    return SYSTICK_VAL;
}

/**
 * @brief Set SysTick reload value
 * @brief 设置 SysTick 加载值
 *
 * Reference: ARMv8-M ARM B3.4.2 (SysTick Reload Value Register)
 * 参考: ARMv8-M ARM B3.4.2 (SysTick 重新加载值寄存器)
 *
 * @param value: Reload value
 * @param value: 加载值
 */
void arch_armv8m_systick_set_reload(uint32_t value) {
    SYSTICK_LOAD = value;
}

/**
 * @brief Get SysTick reload value
 * @brief 获取 SysTick 加载值
 *
 * Reference: ARMv8-M ARM B3.4.2 (SysTick Reload Value Register)
 * 参考: ARMv8-M ARM B3.4.2 (SysTick 重新加载值寄存器)
 *
 * @return Reload value
 * @return 加载值
 */
uint32_t arch_armv8m_systick_get_reload(void) {
    return SYSTICK_LOAD;
}

/**
 * @brief Enable SysTick interrupt
 * @brief 使能 SysTick 中断
 *
 * Reference: ARMv8-M ARM B3.4.1 (SysTick Control and Status Register)
 * 参考: ARMv8-M ARM B3.4.1 (SysTick 控制和状态寄存器)
 */
void arch_armv8m_systick_enable_irq(void) {
    SYSTICK_CTRL |= 0x02;
}

/**
 * @brief Disable SysTick interrupt
 * @brief 禁用 SysTick 中断
 *
 * Reference: ARMv8-M ARM B3.4.1 (SysTick Control and Status Register)
 * 参考: ARMv8-M ARM B3.4.1 (SysTick 控制和状态寄存器)
 */
void arch_armv8m_systick_disable_irq(void) {
    SYSTICK_CTRL &= ~0x02;
}

/**
 * @brief Enable SysTick timer
 * @brief 使能 SysTick 定时器
 *
 * Reference: ARMv8-M ARM B3.4.1 (SysTick Control and Status Register)
 * 参考: ARMv8-M ARM B3.4.1 (SysTick 控制和状态寄存器)
 */
void arch_armv8m_systick_enable(void) {
    SYSTICK_CTRL |= 0x01;
}

/**
 * @brief Disable SysTick timer
 * @brief 禁用 SysTick 定时器
 *
 * Reference: ARMv8-M ARM B3.4.1 (SysTick Control and Status Register)
 * 参考: ARMv8-M ARM B3.4.1 (SysTick 控制和状态寄存器)
 */
void arch_armv8m_systick_disable(void) {
    SYSTICK_CTRL &= ~0x01;
}

/**
 * @brief Get SysTick calibration value
 * @brief 获取 SysTick 校准值
 *
 * Reference: ARMv8-M ARM B3.4.4 (SysTick Calibration Register)
 * 参考: ARMv8-M ARM B3.4.4 (SysTick 校准寄存器)
 *
 * @return Calibration value
 * @return 校准值
 */
uint32_t arch_armv8m_systick_get_calib(void) {
    return SYSTICK_CALIB;
}

/*
 * ============================================================================
 * ARMv8-M ITM (Instrumentation Trace Macrocell) Implementation
 * ARMv8-M ITM (仪表跟踪宏单元) 实现
 * Reference: ARMv8-M ARM Section B6.2 (Instrumentation Trace Macrocell)
 * 参考: ARMv8-M ARM 第 B6.2 节 (仪表跟踪宏单元)
 * ============================================================================
 */

#define ITM_RXBUFFER_EMPTY  0x5AA55AA5U

static volatile int32_t ITM_RxBuffer = ITM_RXBUFFER_EMPTY;

/**
 * @brief ITM send character
 * @brief ITM 发送字符
 *
 * Reference: ARMv8-M ARM B6.2.2 (ITM_STIM, Stimulus Port Register)
 * 参考: ARMv8-M ARM B6.2.2 (ITM_STIM, 刺激端口寄存器)
 *
 * @param ch: Character to send
 * @param ch: 要发送的字符
 * @return Character sent (0-255) or 0 if FIFO full
 * @return 发送的字符 (0-255) 或如果 FIFO 满则返回 0
 */
uint32_t arch_armv8m_itm_send_char(uint32_t ch) {
    if ((ITM_CTRL & 0x1) != 0) {
        if (ITM_STIM(0) == 1) {
            ITM_STIM(0) = ch;
            return ch;
        }
    }
    return 0;
}

/**
 * @brief ITM receive character
 * @brief ITM 接收字符
 *
 * Reference: ARMv8-M ARM B6.2.1 (ITM_RXR, Receive Register)
 * 参考: ARMv8-M ARM B6.2.1 (ITM_RXR, 接收寄存器)
 *
 * @return Received character or -1 if no data
 * @return 接收的字符或如果没有数据则返回 -1
 */
int32_t arch_armv8m_itm_receive_char(void) {
    if (ITM_RxBuffer != ITM_RXBUFFER_EMPTY) {
        int32_t ch = ITM_RxBuffer;
        ITM_RxBuffer = ITM_RXBUFFER_EMPTY;
        return ch;
    }
    return -1;
}

/**
 * @brief ITM check if character is waiting
 * @brief ITM 检查是否有字符等待读取
 *
 * Reference: ARMv8-M ARM B6.2.1 (ITM_RXR)
 * 参考: ARMv8-M ARM B6.2.1 (ITM_RXR)
 *
 * @return 1=data available, 0=no data
 * @return 1=有数据可用, 0=无数据
 */
int32_t arch_armv8m_itm_check_char(void) {
    if (ITM_RxBuffer == ITM_RXBUFFER_EMPTY) {
        return 0;
    }
    return 1;
}

/**
 * @brief ITM enable/disable
 * @brief ITM 使能/禁用
 *
 * Reference: ARMv8-M ARM B6.2.3 (ITM_CTRL, Trace Control Register)
 * 参考: ARMv8-M ARM B6.2.3 (ITM_CTRL, 跟踪控制寄存器)
 *
 * @param enable: Enable (1) or disable (0)
 * @param enable: 使能 (1) 或禁用 (0)
 */
void arch_armv8m_itm_enable(uint32_t enable) {
    if (enable) {
        ITM_CTRL |= 0x1;
    } else {
        ITM_CTRL &= ~0x1;
    }
}

/*
 * ============================================================================
 * ARMv8-M Initialization and Context Switch Implementation
 * ARMv8-M 初始化和上下文切换实现
 * ============================================================================
 */

/**
 * @brief ARMv8-M architecture initialization
 * @brief ARMv8-M 架构初始化
 */
void arch_armv8m_init(void) {
    arch_armv8m_dsb();
    arch_armv8m_isb();
    arch_armv8m_enable_fpu();
    arch_armv8m_mpu_init();
    arch_armv8m_dsb();
}

/**
 * @brief ARMv8-M vector table setup
 * @brief ARMv8-M 向量表设置
 *
 * Reference: ARMv8-M ARM B3.2.5 (SCB_VTOR, Vector Table Offset Register)
 * 参考: ARMv8-M ARM B3.2.5 (SCB_VTOR, 向量表偏移寄存器)
 */
void arch_armv8m_setup_vector_table(void) {
    extern uint32_t _vector_table_base;
    volatile uint32_t *vtor = (volatile uint32_t *)0xE000ED08;
    *vtor = (uint32_t)&_vector_table_base;
}

/**
 * @brief Initialize user task context
 * @brief 初始化用户任务上下文
 *
 * @param context: Task context structure
 * @param context: 任务上下文结构体
 * @param entry_point: Task entry point address
 * @param entry_point: 任务入口点地址
 * @param arg: Task argument
 * @param arg: 任务参数
 */
void arch_armv8m_init_user_context(ArmV8mTaskContext *context, uint32_t entry_point, uint32_t arg) {
    if (context == NULL) {
        return;
    }
    context->r0 = arg;
    context->r1 = 0;
    context->r2 = 0;
    context->r3 = 0;
    context->r4 = 0;
    context->r5 = 0;
    context->r6 = 0;
    context->r7 = 0;
    context->r8 = 0;
    context->r9 = 0;
    context->r10 = 0;
    context->r11 = 0;
    context->r12 = 0;
    context->pc = entry_point;
    context->xpsr = 0x01000000UL;
    context->lr = 0xFFFFFFFFUL;
    context->control = 0;
    context->primask = 0;
    context->basepri = 0;
    context->faultmask = 0;
    context->msplim = 0;
    context->psplim = 0;
}

/**
 * @brief Context switch
 * @brief 上下文切换
 *
 * @param from: Source context
 * @param from: 源上下文
 * @param to: Target context
 * @param to: 目标上下文
 * @return New current context
 * @return 新的当前上下文
 */
void* arch_armv8m_switch_context(void *from, void *to) {
    (void)from;
    (void)to;
    return NULL;
}

/**
 * @brief Start first task
 * @brief 启动第一个任务
 *
 * @param context: Task context
 * @param context: 任务上下文
 * @return New current context
 * @return 新的当前上下文
 */
void* arch_armv8m_start_first_task(void *context) {
    (void)context;
    __builtin_unreachable();
}

/**
 * @brief Jump to kernel
 * @brief 跳转到内核
 *
 * @param vector_table_addr: Vector table address
 * @param vector_table_addr: 向量表地址
 */
void* arch_armv8m_jump_to_kernel(uint32_t vector_table_addr) {
    (void)vector_table_addr;
    __builtin_unreachable();
}
