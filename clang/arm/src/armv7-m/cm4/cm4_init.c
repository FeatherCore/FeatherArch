/*
 * ARM Architecture - Cortex-M4 Initialization
 *
 * ============================================================================
 * File: cm4_init.c
 * Description: Cortex-M4 specific initialization functions
 * 描述: Cortex-M4 特定初始化功能
 *
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual
 *            Arm(R) Cortex-M4 Devices Generic User Guide
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/cm4/cm4.h"

/* ============================================================================
 * Cortex-M4 System Initialization
 * Cortex-M4 系统初始化
 * ============================================================================ */

/**
 * @brief Initialize Cortex-M4 system
 * 初始化 Cortex-M4 系统
 *
 * This function performs Cortex-M4 specific initialization:
 * 1. Enable FPU if present
 * 2. Configure lazy stacking
 * 3. Initialize DSP features
 */
void cm4_system_init(void)
{
#if (__FPU_PRESENT == 1)
    /* Enable FPU - use armv7-m_fpu.h functions */
    fpu_enable();
    fpu_enable_lazy_preservation();
#endif

    /* Clear any pending exceptions */
    SCB_ICSR |= SCB_ICSR_PENDSVCLR_Msk;
    SCB_ICSR |= SCB_ICSR_PENDSTCLR_Msk;
}

/**
 * @brief Pre-main initialization hook
 * Pre-main 初始化钩子
 *
 * This function is called before main() by the startup code.
 * It performs essential Cortex-M4 initialization.
 */
void cm4_pre_main_init(void)
{
    /* Initialize system */
    cm4_system_init();

    /* Set priority grouping (optional) */
    /* NVIC_SetPriorityGrouping(0x03); */
}

/* ============================================================================
 * Cortex-M4 Cycle Counter
 * Cortex-M4 周期计数器
 * ============================================================================ */

/**
 * @brief Enable DWT cycle counter
 * 启用 DWT 周期计数器
 *
 * The DWT cycle counter can be used for profiling and timing measurements.
 */
void cm4_dwt_enable(void)
{
    /* Enable TRCENA in DEMCR */
    DEMCR |= DEMCR_TRCENA_Msk;

    /* Enable cycle counter */
    DWT_CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

/**
 * @brief Disable DWT cycle counter
 * 禁用 DWT 周期计数器
 */
void cm4_dwt_disable(void)
{
    /* Disable cycle counter */
    DWT_CTRL &= ~DWT_CTRL_CYCCNTENA_Msk;
}

/**
 * @brief Reset DWT cycle counter
 * 复位 DWT 周期计数器
 */
void cm4_dwt_reset(void)
{
    /* Reset cycle counter */
    DWT_CYCCNT = 0;
}

/**
 * @brief Get DWT cycle counter value
 * 获取 DWT 周期计数器值
 * @return Current cycle count
 */
uint32_t cm4_dwt_get_cycles(void)
{
    return DWT_CYCCNT;
}

/* ============================================================================
 * Cortex-M4 Sleep Mode
 * Cortex-M4 睡眠模式
 * ============================================================================ */

/**
 * @brief Enter Sleep mode
 * 进入睡眠模式
 *
 * In Sleep mode, the processor clock is stopped.
 * Wake up on interrupt or event.
 */
void cm4_sleep(void)
{
    __asm__ volatile (
        "wfi\n"
        ::: "memory"
    );
}

/**
 * @brief Enter Deep Sleep mode
 * 进入深度睡眠模式
 *
 * In Deep Sleep mode, the system clock is stopped.
 * Wake up on interrupt or event.
 */
void cm4_deep_sleep(void)
{
    /* Set SLEEPDEEP bit in SCR */
    SCB_SCR |= SCB_SCR_SLEEPDEEP_Msk;

    __asm__ volatile (
        "wfi\n"
        ::: "memory"
    );

    /* Clear SLEEPDEEP bit */
    SCB_SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
}

/* ============================================================================
 * Cortex-M4 Fault Handling
 * Cortex-M4 故障处理
 * ============================================================================ */

/**
 * @brief Enable all configurable faults
 * 启用所有可配置故障
 */
void cm4_fault_enable_all(void)
{
    /* Enable MemManage, BusFault, and UsageFault */
    SCB_SHCSR |= (SCB_SHCSR_MEMFAULTENA_Msk |
                  SCB_SHCSR_BUSFAULTENA_Msk |
                  SCB_SHCSR_USGFAULTENA_Msk);
}

/**
 * @brief Disable all configurable faults
 * 禁用所有可配置故障
 */
void cm4_fault_disable_all(void)
{
    /* Disable MemManage, BusFault, and UsageFault */
    SCB_SHCSR &= ~(SCB_SHCSR_MEMFAULTENA_Msk |
                   SCB_SHCSR_BUSFAULTENA_Msk |
                   SCB_SHCSR_USGFAULTENA_Msk);
}

/**
 * @brief Get fault status
 * 获取故障状态
 * @return Combined fault status
 */
uint32_t cm4_fault_get_status(void)
{
    return (SCB_CFSR);
}

/**
 * @brief Clear all fault status
 * 清除所有故障状态
 */
void cm4_fault_clear_all(void)
{
    SCB_CFSR = 0xFFFFFFFF;
}
