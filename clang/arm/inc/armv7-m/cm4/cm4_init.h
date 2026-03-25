/*
 * ARM Architecture - Cortex-M4 Initialization
 *
 * ============================================================================
 * File: cm4_init.h
 * Description: Cortex-M4 specific initialization and utility functions
 *              (wrapper for armv7-m functions where applicable)
 * 描述: Cortex-M4 特定初始化和工具函数（在适用情况下包装 armv7-m 函数）
 *
 * This file provides CM4-specific functionality while delegating
 * common ARMv7-M features to armv7-m headers.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 2.1 Programmers model (page 2-2)
 *   - Chapter 2.2 Memory model (page 2-10)
 *   - Chapter 2.4 Fault handling (page 2-29)
 *   - Chapter 2.5 Power management (page 2-32)
 *
 * Implementation:
 *   - CM4-specific features: Bit-banding, system init
 *   - Common ARMv7-M features: Delegated to armv7-m headers
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_INIT_H__
#define __CM4_INIT_H__

#include <stdint.h>
#include <stdbool.h>

/* Include ARMv7-M core functionality */
#include "armv7-m/armv7-m_core.h"
#include "armv7-m/armv7-m_scb.h"
#include "armv7-m/armv7-m_dwt.h"
#include "armv7-m/armv7-m_debug.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================================
 * Cortex-M4 System Initialization
 * Cortex-M4 系统初始化
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1 (page 2-2)
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
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1 (page 2-2)
 */
void cm4_system_init(void);

/**
 * @brief Pre-main initialization hook
 * Pre-main 初始化钩子
 *
 * This function is called before main() by the startup code.
 * It performs essential Cortex-M4 initialization.
 */
void cm4_pre_main_init(void);

/* ============================================================================
 * Cortex-M4 Cycle Counter (DWT)
 * Cortex-M4 周期计数器 (DWT)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.8 (page 4-59)
 * ============================================================================ */

/**
 * @brief Enable DWT cycle counter
 * 启用 DWT 周期计数器
 */
void cm4_dwt_enable(void);

/**
 * @brief Disable DWT cycle counter
 * 禁用 DWT 周期计数器
 */
void cm4_dwt_disable(void);

/**
 * @brief Reset DWT cycle counter
 * 复位 DWT 周期计数器
 */
void cm4_dwt_reset(void);

/**
 * @brief Get DWT cycle counter value
 * 获取 DWT 周期计数器值
 * @return Current cycle count
 */
uint32_t cm4_dwt_get_cycles(void);

/* ============================================================================
 * Cortex-M4 Sleep Mode
 * Cortex-M4 睡眠模式
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.5 (page 2-32)
 * ============================================================================ */

/**
 * @brief Enter Sleep mode
 * 进入睡眠模式
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.5 (page 2-32)
 */
void cm4_sleep(void);

/**
 * @brief Enter Deep Sleep mode
 * 进入深度睡眠模式
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.5 (page 2-32)
 */
void cm4_deep_sleep(void);

/**
 * @brief Enable Sleep-on-Exit mode
 * 启用退出时睡眠模式
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.5 (page 2-32)
 */
void cm4_sleep_on_exit_enable(void);

/**
 * @brief Disable Sleep-on-Exit mode
 * 禁用退出时睡眠模式
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.5 (page 2-32)
 */
void cm4_sleep_on_exit_disable(void);

/* ============================================================================
 * Cortex-M4 Fault Handling
 * Cortex-M4 故障处理
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.4 (page 2-29)
 * ============================================================================ */

/**
 * @brief Enable all configurable faults
 * 启用所有可配置故障
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.4 (page 2-29)
 */
void cm4_fault_enable_all(void);

/**
 * @brief Disable all configurable faults
 * 禁用所有可配置故障
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.4 (page 2-29)
 */
void cm4_fault_disable_all(void);

/**
 * @brief Get fault status
 * 获取故障状态
 * @return Combined fault status (CFSR value)
 */
uint32_t cm4_fault_get_status(void);

/**
 * @brief Clear all fault status
 * 清除所有故障状态
 */
void cm4_fault_clear_all(void);

/**
 * @brief Get HardFault status
 * 获取 HardFault 状态
 * @return HFSR value
 */
uint32_t cm4_fault_get_hardfault_status(void);

/**
 * @brief Clear HardFault status
 * 清除 HardFault 状态
 */
void cm4_fault_clear_hardfault(void);

/**
 * @brief Get MemManage fault address
 * 获取 MemManage 故障地址
 * @return MMFAR value
 */
uint32_t cm4_fault_get_memmanage_addr(void);

/**
 * @brief Get BusFault address
 * 获取 BusFault 地址
 * @return BFAR value
 */
uint32_t cm4_fault_get_busfault_addr(void);

/* ============================================================================
 * Cortex-M4 Bit-Banding Support
 * Cortex-M4 位带支持
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.5 (page 2-16)
 * ============================================================================ */

#if (__BITBAND_PRESENT == 1)

/* Bit-band base addresses */
#define CM4_BITBAND_SRAM_BASE      (0x20000000UL)
#define CM4_BITBAND_SRAM_ALIAS     (0x22000000UL)
#define CM4_BITBAND_PERIPH_BASE    (0x40000000UL)
#define CM4_BITBAND_PERIPH_ALIAS   (0x42000000UL)

/* Bit-band address calculation macros */
#define CM4_BITBAND_SRAM_ADDR(addr, bit)  ((volatile uint32_t *)((CM4_BITBAND_SRAM_ALIAS + (((uint32_t)(addr) - CM4_BITBAND_SRAM_BASE) * 32) + ((bit) * 4))))
#define CM4_BITBAND_PERIPH_ADDR(addr, bit) ((volatile uint32_t *)((CM4_BITBAND_PERIPH_ALIAS + (((uint32_t)(addr) - CM4_BITBAND_PERIPH_BASE) * 32) + ((bit) * 4))))

/**
 * @brief Set bit using bit-banding (SRAM region)
 * 使用位带设置位 (SRAM 区域)
 * @param addr Byte address in SRAM bit-band region
 * @param bit Bit number (0-7)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.5 (page 2-16)
 */
void cm4_bitband_sram_set(volatile void *addr, uint32_t bit);

/**
 * @brief Clear bit using bit-banding (SRAM region)
 * 使用位带清除位 (SRAM 区域)
 * @param addr Byte address in SRAM bit-band region
 * @param bit Bit number (0-7)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.5 (page 2-16)
 */
void cm4_bitband_sram_clear(volatile void *addr, uint32_t bit);

/**
 * @brief Read bit using bit-banding (SRAM region)
 * 使用位带读取位 (SRAM 区域)
 * @param addr Byte address in SRAM bit-band region
 * @param bit Bit number (0-7)
 * @return Bit value (0 or 1)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.5 (page 2-16)
 */
uint32_t cm4_bitband_sram_read(volatile void *addr, uint32_t bit);

/**
 * @brief Toggle bit using bit-banding (SRAM region)
 * 使用位带翻转位 (SRAM 区域)
 * @param addr Byte address in SRAM bit-band region
 * @param bit Bit number (0-7)
 */
void cm4_bitband_sram_toggle(volatile void *addr, uint32_t bit);

/**
 * @brief Set bit using bit-banding (Peripheral region)
 * 使用位带设置位 (外设区域)
 * @param addr Byte address in peripheral bit-band region
 * @param bit Bit number (0-7)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.5 (page 2-16)
 */
void cm4_bitband_periph_set(volatile void *addr, uint32_t bit);

/**
 * @brief Clear bit using bit-banding (Peripheral region)
 * 使用位带清除位 (外设区域)
 * @param addr Byte address in peripheral bit-band region
 * @param bit Bit number (0-7)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.5 (page 2-16)
 */
void cm4_bitband_periph_clear(volatile void *addr, uint32_t bit);

/**
 * @brief Read bit using bit-banding (Peripheral region)
 * 使用位带读取位 (外设区域)
 * @param addr Byte address in peripheral bit-band region
 * @param bit Bit number (0-7)
 * @return Bit value (0 or 1)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.5 (page 2-16)
 */
uint32_t cm4_bitband_periph_read(volatile void *addr, uint32_t bit);

/**
 * @brief Toggle bit using bit-banding (Peripheral region)
 * 使用位带翻转位 (外设区域)
 * @param addr Byte address in peripheral bit-band region
 * @param bit Bit number (0-7)
 */
void cm4_bitband_periph_toggle(volatile void *addr, uint32_t bit);

#endif /* __BITBAND_PRESENT == 1 */

/* ============================================================================
 * Cortex-M4 Exclusive Access Support
 * Cortex-M4 独占访问支持
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.7 (page 2-18)
 * ============================================================================ */

/**
 * @brief Load-Exclusive (8-bit)
 * 独占加载 (8位)
 * @param addr Address to load from
 * @return Loaded value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.7 (page 2-18)
 */
uint8_t cm4_ldrex8(volatile uint8_t *addr);

/**
 * @brief Load-Exclusive (16-bit)
 * 独占加载 (16位)
 * @param addr Address to load from
 * @return Loaded value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.7 (page 2-18)
 */
uint16_t cm4_ldrex16(volatile uint16_t *addr);

/**
 * @brief Load-Exclusive (32-bit)
 * 独占加载 (32位)
 * @param addr Address to load from
 * @return Loaded value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.7 (page 2-18)
 */
uint32_t cm4_ldrex32(volatile uint32_t *addr);

/**
 * @brief Store-Exclusive (8-bit)
 * 独占存储 (8位)
 * @param addr Address to store to
 * @param value Value to store
 * @return 0 if store succeeded, 1 if failed
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.7 (page 2-18)
 */
uint32_t cm4_strex8(volatile uint8_t *addr, uint8_t value);

/**
 * @brief Store-Exclusive (16-bit)
 * 独占存储 (16位)
 * @param addr Address to store to
 * @param value Value to store
 * @return 0 if store succeeded, 1 if failed
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.7 (page 2-18)
 */
uint32_t cm4_strex16(volatile uint16_t *addr, uint16_t value);

/**
 * @brief Store-Exclusive (32-bit)
 * 独占存储 (32位)
 * @param addr Address to store to
 * @param value Value to store
 * @return 0 if store succeeded, 1 if failed
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.7 (page 2-18)
 */
uint32_t cm4_strex32(volatile uint32_t *addr, uint32_t value);

/**
 * @brief Clear Exclusive
 * 清除独占标记
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.7 (page 2-18)
 */
void cm4_clrex(void);

/* ============================================================================
 * Cortex-M4 CPUID and System Information
 * Cortex-M4 CPUID 和系统信息
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.3 (page 2-3)
 * ============================================================================ */

/**
 * @brief Get CPUID
 * 获取 CPUID
 * @return CPUID register value
 */
uint32_t cm4_get_cpuid(void);

/**
 * @brief Get Cortex-M4 revision
 * 获取 Cortex-M4 版本
 * @return Revision number
 */
uint32_t cm4_get_revision(void);

/**
 * @brief Get implementer code
 * 获取实现者代码
 * @return Implementer code (0x41 = ARM)
 */
uint32_t cm4_get_implementer(void);

/**
 * @brief Check if running on Cortex-M4
 * 检查是否在 Cortex-M4 上运行
 * @return 1 if Cortex-M4, 0 otherwise
 */
int cm4_is_cortex_m4(void);

/* ============================================================================
 * Cortex-M4 Interrupt Control
 * Cortex-M4 中断控制
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.3 (page 2-7)
 * ============================================================================ */

/**
 * @brief Disable all interrupts (except NMI and HardFault)
 * 禁用所有中断 (除了 NMI 和 HardFault)
 */
void cm4_disable_interrupts(void);

/**
 * @brief Enable all interrupts
 * 启用所有中断
 */
void cm4_enable_interrupts(void);

/**
 * @brief Disable all faults
 * 禁用所有故障
 */
void cm4_disable_faults(void);

/**
 * @brief Enable all faults
 * 启用所有故障
 */
void cm4_enable_faults(void);

/**
 * @brief Get current interrupt state
 * 获取当前中断状态
 * @return 1 if interrupts are enabled, 0 if disabled
 */
int cm4_get_interrupt_state(void);

/* ============================================================================
 * Cortex-M4 Data Synchronization and Instruction Synchronization
 * Cortex-M4 数据同步和指令同步
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.4 (page 2-15)
 * ============================================================================ */

/**
 * @brief Data Synchronization Barrier
 * 数据同步屏障
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.4 (page 2-15)
 */
void cm4_dsb(void);

/**
 * @brief Data Memory Barrier
 * 数据内存屏障
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.4 (page 2-15)
 */
void cm4_dmb(void);

/**
 * @brief Instruction Synchronization Barrier
 * 指令同步屏障
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.4 (page 2-15)
 */
void cm4_isb(void);

/* ============================================================================
 * Cortex-M4 Wait For Interrupt and Event
 * Cortex-M4 等待中断和事件
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.5 (page 2-32)
 * ============================================================================ */

/**
 * @brief Wait For Interrupt
 * 等待中断
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.5 (page 2-32)
 */
void cm4_wfi(void);

/**
 * @brief Wait For Event
 * 等待事件
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.5 (page 2-32)
 */
void cm4_wfe(void);

/**
 * @brief Send Event
 * 发送事件
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.5 (page 2-32)
 */
void cm4_sev(void);

/* ============================================================================
 * Cortex-M4 NOP and Debug
 * Cortex-M4 NOP 和调试
 * ============================================================================ */

/**
 * @brief No Operation
 * 空操作
 */
void cm4_nop(void);

/**
 * @brief Breakpoint
 * 断点
 * @param val Breakpoint value (0-255)
 */
void cm4_bkpt(uint8_t val);

#ifdef __cplusplus
}
#endif

#endif /* __CM4_INIT_H__ */
