/*
 * ARM Architecture - Cortex-M4 Initialization
 *
 * ============================================================================
 * File: cm4_init.c
 * Description: Cortex-M4 specific initialization functions
 * 描述: Cortex-M4 特定初始化功能
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553)
 *   - Chapter 1: Introduction
 *   - Chapter 2: The Cortex-M4 Processor
 *   - Chapter 3: Cortex-M4 Instructions
 *   - Chapter 4: Cortex-M4 Peripherals
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include <stdbool.h>
#include "armv7-m/cm4/cm4.h"
#include "armv7-m/armv7-m_nvic.h"
#include "armv7-m/armv7-m_fpu.h"

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
 * 4. Configure bit-banding if needed
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
 * Reference: Cortex-M4 TRM, Chapter 9 - Data Watchpoint and Trace Unit
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
 * Reference: Generic User Guide, Section 2.5 - Power management
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
 * Reference: Generic User Guide, Section 2.5 - Power management
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

/**
 * @brief Enter Sleep-on-Exit mode
 * 进入退出时睡眠模式
 *
 * When set, the processor enters sleep mode on return from an ISR.
 * Reference: Generic User Guide, Section 2.5 - Power management
 */
void cm4_sleep_on_exit_enable(void)
{
    SCB_SCR |= SCB_SCR_SLEEPONEXIT_Msk;
}

/**
 * @brief Disable Sleep-on-Exit mode
 * 禁用退出时睡眠模式
 */
void cm4_sleep_on_exit_disable(void)
{
    SCB_SCR &= ~SCB_SCR_SLEEPONEXIT_Msk;
}

/* ============================================================================
 * Cortex-M4 Fault Handling
 * Cortex-M4 故障处理
 * ============================================================================ */

/**
 * @brief Enable all configurable faults
 * 启用所有可配置故障
 * Reference: Generic User Guide, Section 2.4 - Fault handling
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
 * @return Combined fault status (CFSR value)
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

/**
 * @brief Get HardFault status
 * 获取 HardFault 状态
 * @return HFSR value
 */
uint32_t cm4_fault_get_hardfault_status(void)
{
    return SCB_HFSR;
}

/**
 * @brief Clear HardFault status
 * 清除 HardFault 状态
 */
void cm4_fault_clear_hardfault(void)
{
    SCB_HFSR = 0xFFFFFFFF;
}

/**
 * @brief Get MemManage fault address
 * 获取 MemManage 故障地址
 * @return MMFAR value
 */
uint32_t cm4_fault_get_memmanage_addr(void)
{
    return SCB_MMFAR;
}

/**
 * @brief Get BusFault address
 * 获取 BusFault 地址
 * @return BFAR value
 */
uint32_t cm4_fault_get_busfault_addr(void)
{
    return SCB_BFAR;
}

/* ============================================================================
 * Cortex-M4 Bit-Banding Support
 * Cortex-M4 位带支持
 * ============================================================================ */

#if (__BITBAND_PRESENT == 1)

/**
 * @brief Set bit using bit-banding (SRAM region)
 * 使用位带设置位 (SRAM 区域)
 * @param addr Byte address in SRAM bit-band region (0x20000000-0x200FFFFF)
 * @param bit Bit number (0-31)
 * Reference: Generic User Guide, Section 2.2 - Memory model, Bit-banding
 */
void cm4_bitband_sram_set(volatile void *addr, uint32_t bit)
{
    *BITBAND_SRAM_PTR(addr, bit) = 1;
}

/**
 * @brief Clear bit using bit-banding (SRAM region)
 * 使用位带清除位 (SRAM 区域)
 * @param addr Byte address in SRAM bit-band region
 * @param bit Bit number (0-31)
 */
void cm4_bitband_sram_clear(volatile void *addr, uint32_t bit)
{
    *BITBAND_SRAM_PTR(addr, bit) = 0;
}

/**
 * @brief Read bit using bit-banding (SRAM region)
 * 使用位带读取位 (SRAM 区域)
 * @param addr Byte address in SRAM bit-band region
 * @param bit Bit number (0-31)
 * @return Bit value (0 or 1)
 */
uint32_t cm4_bitband_sram_read(volatile void *addr, uint32_t bit)
{
    return *BITBAND_SRAM_PTR(addr, bit);
}

/**
 * @brief Toggle bit using bit-banding (SRAM region)
 * 使用位带翻转位 (SRAM 区域)
 * @param addr Byte address in SRAM bit-band region
 * @param bit Bit number (0-31)
 */
void cm4_bitband_sram_toggle(volatile void *addr, uint32_t bit)
{
    volatile uint32_t *ptr = BITBAND_SRAM_PTR(addr, bit);
    *ptr = ~(*ptr);
}

/**
 * @brief Set bit using bit-banding (Peripheral region)
 * 使用位带设置位 (外设区域)
 * @param addr Byte address in peripheral bit-band region (0x40000000-0x400FFFFF)
 * @param bit Bit number (0-31)
 * Reference: Generic User Guide, Section 2.2 - Memory model, Bit-banding
 */
void cm4_bitband_periph_set(volatile void *addr, uint32_t bit)
{
    *BITBAND_PERIPH_PTR(addr, bit) = 1;
}

/**
 * @brief Clear bit using bit-banding (Peripheral region)
 * 使用位带清除位 (外设区域)
 * @param addr Byte address in peripheral bit-band region
 * @param bit Bit number (0-31)
 */
void cm4_bitband_periph_clear(volatile void *addr, uint32_t bit)
{
    *BITBAND_PERIPH_PTR(addr, bit) = 0;
}

/**
 * @brief Read bit using bit-banding (Peripheral region)
 * 使用位带读取位 (外设区域)
 * @param addr Byte address in peripheral bit-band region
 * @param bit Bit number (0-31)
 * @return Bit value (0 or 1)
 */
uint32_t cm4_bitband_periph_read(volatile void *addr, uint32_t bit)
{
    return *BITBAND_PERIPH_PTR(addr, bit);
}

/**
 * @brief Toggle bit using bit-banding (Peripheral region)
 * 使用位带翻转位 (外设区域)
 * @param addr Byte address in peripheral bit-band region
 * @param bit Bit number (0-31)
 */
void cm4_bitband_periph_toggle(volatile void *addr, uint32_t bit)
{
    volatile uint32_t *ptr = BITBAND_PERIPH_PTR(addr, bit);
    *ptr = ~(*ptr);
}

#endif /* __BITBAND_PRESENT == 1 */

/* ============================================================================
 * Cortex-M4 Exclusive Access Support
 * Cortex-M4 独占访问支持
 * ============================================================================ */

/**
 * @brief Load-Exclusive (8-bit)
 * 独占加载 (8位)
 * @param addr Address to load from
 * @return Loaded value
 * Reference: Generic User Guide, Section 2.2 - Memory model, Exclusive monitors
 */
uint8_t cm4_ldrex8(volatile uint8_t *addr)
{
    uint8_t result;
    __asm__ volatile (
        "ldrexb %0, [%1]"
        : "=r" (result)
        : "r" (addr)
    );
    return result;
}

/**
 * @brief Load-Exclusive (16-bit)
 * 独占加载 (16位)
 * @param addr Address to load from
 * @return Loaded value
 */
uint16_t cm4_ldrex16(volatile uint16_t *addr)
{
    uint16_t result;
    __asm__ volatile (
        "ldrexh %0, [%1]"
        : "=r" (result)
        : "r" (addr)
    );
    return result;
}

/**
 * @brief Load-Exclusive (32-bit)
 * 独占加载 (32位)
 * @param addr Address to load from
 * @return Loaded value
 */
uint32_t cm4_ldrex32(volatile uint32_t *addr)
{
    uint32_t result;
    __asm__ volatile (
        "ldrex %0, [%1]"
        : "=r" (result)
        : "r" (addr)
    );
    return result;
}

/**
 * @brief Store-Exclusive (8-bit)
 * 独占存储 (8位)
 * @param addr Address to store to
 * @param value Value to store
 * @return 0 if store succeeded, 1 if failed
 */
uint32_t cm4_strex8(volatile uint8_t *addr, uint8_t value)
{
    uint32_t result;
    __asm__ volatile (
        "strexb %0, %2, [%1]"
        : "=r" (result)
        : "r" (addr), "r" (value)
    );
    return result;
}

/**
 * @brief Store-Exclusive (16-bit)
 * 独占存储 (16位)
 * @param addr Address to store to
 * @param value Value to store
 * @return 0 if store succeeded, 1 if failed
 */
uint32_t cm4_strex16(volatile uint16_t *addr, uint16_t value)
{
    uint32_t result;
    __asm__ volatile (
        "strexh %0, %2, [%1]"
        : "=r" (result)
        : "r" (addr), "r" (value)
    );
    return result;
}

/**
 * @brief Store-Exclusive (32-bit)
 * 独占存储 (32位)
 * @param addr Address to store to
 * @param value Value to store
 * @return 0 if store succeeded, 1 if failed
 */
uint32_t cm4_strex32(volatile uint32_t *addr, uint32_t value)
{
    uint32_t result;
    __asm__ volatile (
        "strex %0, %2, [%1]"
        : "=r" (result)
        : "r" (addr), "r" (value)
    );
    return result;
}

/**
 * @brief Clear Exclusive
 * 清除独占标记
 * Clears the local exclusive monitor.
 */
void cm4_clrex(void)
{
    __asm__ volatile (
        "clrex"
    );
}

/* ============================================================================
 * Cortex-M4 CPUID and System Information
 * Cortex-M4 CPUID 和系统信息
 * ============================================================================ */

/**
 * @brief Get CPUID
 * 获取 CPUID
 * @return CPUID register value
 * Reference: Generic User Guide, Section 4.3 - System control block
 */
uint32_t cm4_get_cpuid(void)
{
    return SCB_CPUID;
}

/**
 * @brief Get Cortex-M4 revision
 * 获取 Cortex-M4 版本
 * @return Revision number (rXpY format: X = major, Y = minor)
 */
uint32_t cm4_get_revision(void)
{
    return ((SCB_CPUID & 0x00F00000) >> 20) | ((SCB_CPUID & 0x0000000F) << 4);
}

/**
 * @brief Get implementer code
 * 获取实现者代码
 * @return Implementer code (0x41 = ARM)
 */
uint32_t cm4_get_implementer(void)
{
    return (SCB_CPUID >> 24) & 0xFF;
}

/**
 * @brief Check if running on Cortex-M4
 * 检查是否在 Cortex-M4 上运行
 * @return 1 if Cortex-M4, 0 otherwise
 */
int cm4_is_cortex_m4(void)
{
    uint32_t cpuid = SCB_CPUID;
    /* Check implementer (ARM = 0x41) and part number (Cortex-M4 = 0xC24) */
    return (((cpuid >> 24) & 0xFF) == 0x41) && (((cpuid >> 4) & 0xFFF) == 0xC24);
}

/* ============================================================================
 * Cortex-M4 Interrupt Control
 * Cortex-M4 中断控制
 * ============================================================================ */

/**
 * @brief Disable all interrupts (except NMI and HardFault)
 * 禁用所有中断 (除了 NMI 和 HardFault)
 * Reference: Generic User Guide, Section 2.1 - Programmers model
 */
void cm4_disable_interrupts(void)
{
    __asm__ volatile (
        "cpsid i"
        ::: "memory"
    );
}

/**
 * @brief Enable all interrupts
 * 启用所有中断
 */
void cm4_enable_interrupts(void)
{
    __asm__ volatile (
        "cpsie i"
        ::: "memory"
    );
}

/**
 * @brief Disable all faults
 * 禁用所有故障
 */
void cm4_disable_faults(void)
{
    __asm__ volatile (
        "cpsid f"
        ::: "memory"
    );
}

/**
 * @brief Enable all faults
 * 启用所有故障
 */
void cm4_enable_faults(void)
{
    __asm__ volatile (
        "cpsie f"
        ::: "memory"
    );
}

/**
 * @brief Get current interrupt state
 * 获取当前中断状态
 * @return 1 if interrupts are enabled, 0 if disabled
 */
int cm4_get_interrupt_state(void)
{
    uint32_t primask;
    __asm__ volatile (
        "mrs %0, primask"
        : "=r" (primask)
    );
    return (primask == 0) ? 1 : 0;
}

/* ============================================================================
 * Cortex-M4 Data Synchronization and Instruction Synchronization
 * Cortex-M4 数据同步和指令同步
 * ============================================================================ */

/**
 * @brief Data Synchronization Barrier
 * 数据同步屏障
 * Ensures that all memory accesses are completed before subsequent instructions.
 * Reference: Generic User Guide, Section 3.12 - Miscellaneous instructions
 */
void cm4_dsb(void)
{
    __asm__ volatile (
        "dsb"
        ::: "memory"
    );
}

/**
 * @brief Data Memory Barrier
 * 数据内存屏障
 * Ensures that all memory accesses are completed before subsequent memory accesses.
 */
void cm4_dmb(void)
{
    __asm__ volatile (
        "dmb"
        ::: "memory"
    );
}

/**
 * @brief Instruction Synchronization Barrier
 * 指令同步屏障
 * Ensures that all instructions are completed before subsequent instructions.
 */
void cm4_isb(void)
{
    __asm__ volatile (
        "isb"
        ::: "memory"
    );
}

/* ============================================================================
 * Cortex-M4 Wait For Interrupt and Event
 * Cortex-M4 等待中断和事件
 * ============================================================================ */

/**
 * @brief Wait For Interrupt
 * 等待中断
 * Suspends execution until an interrupt occurs.
 * Reference: Generic User Guide, Section 3.12 - Miscellaneous instructions
 */
void cm4_wfi(void)
{
    __asm__ volatile (
        "wfi"
        ::: "memory"
    );
}

/**
 * @brief Wait For Event
 * 等待事件
 * Suspends execution until an event occurs.
 */
void cm4_wfe(void)
{
    __asm__ volatile (
        "wfe"
        ::: "memory"
    );
}

/**
 * @brief Send Event
 * 发送事件
 * Sends an event to all processors in the system.
 */
void cm4_sev(void)
{
    __asm__ volatile (
        "sev"
        ::: "memory"
    );
}

/* ============================================================================
 * Cortex-M4 NOP and Debug
 * Cortex-M4 NOP 和调试
 * ============================================================================ */

/**
 * @brief No Operation
 * 空操作
 * Can be used for timing delays or alignment.
 */
void cm4_nop(void)
{
    __asm__ volatile (
        "nop"
    );
}

/**
 * @brief Breakpoint
 * 断点
 * Generates a debug breakpoint.
 * @param val Breakpoint value (0-255)
 */
void cm4_bkpt(uint8_t val)
{
    __asm__ volatile (
        "bkpt %0"
        :
        : "I" (val)
    );
}
