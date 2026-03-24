/*
 * ARM Architecture - Cortex-M7 Control Registers
 *
 * ============================================================================
 * File: cm7_ctrl.c
 * Description: Cortex-M7 Control Registers implementation
 * 描述: Cortex-M7 控制寄存器实现
 *
 * @reference Arm Cortex-M7 Processor Technical Reference Manual
 *   - Section 3.2 Register summary, Table 3-1 System control registers
 *   - Section 3.3.1 Auxiliary Control Register
 *   - Section 3.3.8 L1 Cache Control Register
 *   - Section 3.3.9 Auxiliary Bus Fault Status Register
 *   - Section 3.3.10 Instruction Error bank Register 0-1
 *   - Section 3.3.11 Data Error bank Register 0-1
 *
 * @reference Arm Cortex-M7 Devices Generic User Guide
 *   - Section 4.5 Processor features
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/cm7/cm7_ctrl.h"

/* ============================================================================
 * ACTLR Control Functions
 * ACTLR 控制函数
 * ============================================================================ */

/**
 * @brief Get ACTLR value
 * 获取 ACTLR 值
 */
uint32_t cm7_actlr_get(void)
{
    return CM7_ACTLR;
}

/**
 * @brief Set ACTLR value
 * 设置 ACTLR 值
 */
void cm7_actlr_set(uint32_t value)
{
    CM7_ACTLR = value;
    __DSB();
    __ISB();
}

/**
 * @brief Disable instruction folding
 * 禁用指令折叠
 */
void cm7_actlr_disfold_enable(void)
{
    CM7_ACTLR |= CM7_ACTLR_DISFOLD_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Enable instruction folding (normal operation)
 * 使能指令折叠（正常操作）
 */
void cm7_actlr_disfold_disable(void)
{
    CM7_ACTLR &= ~CM7_ACTLR_DISFOLD_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Disable FPU exception outputs
 * 禁用 FPU 异常输出
 */
void cm7_actlr_fpexcodis_enable(void)
{
    CM7_ACTLR |= CM7_ACTLR_FPEXCODIS_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Enable FPU exception outputs (normal operation)
 * 使能 FPU 异常输出（正常操作）
 */
void cm7_actlr_fpexcodis_disable(void)
{
    CM7_ACTLR &= ~CM7_ACTLR_FPEXCODIS_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Disable dynamic read allocate mode
 * 禁用动态读取分配模式
 */
void cm7_actlr_disramode_enable(void)
{
    CM7_ACTLR |= CM7_ACTLR_DISRAMODE_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Enable dynamic read allocate mode (normal operation)
 * 使能动态读取分配模式（正常操作）
 */
void cm7_actlr_disramode_disable(void)
{
    CM7_ACTLR &= ~CM7_ACTLR_DISRAMODE_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Disable BTAC read
 * 禁用 BTAC 读取
 */
void cm7_actlr_disbtacread_enable(void)
{
    CM7_ACTLR |= CM7_ACTLR_DISBTACREAD_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Enable BTAC read (normal operation)
 * 使能 BTAC 读取（正常操作）
 */
void cm7_actlr_disbtacread_disable(void)
{
    CM7_ACTLR &= ~CM7_ACTLR_DISBTACREAD_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Disable BTAC allocation
 * 禁用 BTAC 分配
 */
void cm7_actlr_disbtacalloc_enable(void)
{
    CM7_ACTLR |= CM7_ACTLR_DISBTACALLOC_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Enable BTAC allocation (normal operation)
 * 使能 BTAC 分配（正常操作）
 */
void cm7_actlr_disbtacalloc_disable(void)
{
    CM7_ACTLR &= ~CM7_ACTLR_DISBTACALLOC_Msk;
    __DSB();
    __ISB();
}

/* ============================================================================
 * CACR Control Functions
 * CACR 控制函数
 * ============================================================================ */

/**
 * @brief Get CACR value
 * 获取 CACR 值
 */
uint32_t cm7_cacr_get(void)
{
    return CM7_CACR;
}

/**
 * @brief Set CACR value
 * 设置 CACR 值
 */
void cm7_cacr_set(uint32_t value)
{
    CM7_CACR = value;
    __DSB();
    __ISB();
}

/**
 * @brief Enable Shared cacheable-is-WT for data cache
 * 使能共享可缓存为写通模式
 */
void cm7_cacr_siwt_enable(void)
{
    CM7_CACR |= CM7_CACR_SIWT_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Disable Shared cacheable-is-WT for data cache (normal operation)
 * 禁用共享可缓存为写通模式（正常操作）
 */
void cm7_cacr_siwt_disable(void)
{
    CM7_CACR &= ~CM7_CACR_SIWT_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Enable ECC in instruction and data cache
 * 使能指令和数据缓存的 ECC
 */
void cm7_cacr_ecc_enable(void)
{
    CM7_CACR &= ~CM7_CACR_ECCDIS_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Disable ECC in instruction and data cache
 * 禁用指令和数据缓存的 ECC
 */
void cm7_cacr_ecc_disable(void)
{
    CM7_CACR |= CM7_CACR_ECCDIS_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Enable Force Write-Through in data cache
 * 使能数据缓存的强制写通
 */
void cm7_cacr_forcewt_enable(void)
{
    CM7_CACR |= CM7_CACR_FORCEWT_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Disable Force Write-Through in data cache (normal operation)
 * 禁用数据缓存的强制写通（正常操作）
 */
void cm7_cacr_forcewt_disable(void)
{
    CM7_CACR &= ~CM7_CACR_FORCEWT_Msk;
    __DSB();
    __ISB();
}

/* ============================================================================
 * ABFSR Control Functions
 * ABFSR 控制函数
 * ============================================================================ */

/**
 * @brief Get ABFSR value
 * 获取 ABFSR 值
 */
uint32_t cm7_abfsr_get(void)
{
    return CM7_ABFSR;
}

/**
 * @brief Clear ABFSR (write to clear)
 * 清除 ABFSR（写清除）
 */
void cm7_abfsr_clear(void)
{
    CM7_ABFSR = 0xFFFFFFFFUL;
    __DSB();
}

/**
 * @brief Check if ITCM asynchronous fault occurred
 * 检查是否发生 ITCM 异步故障
 */
uint32_t cm7_abfsr_itcm_fault(void)
{
    return (CM7_ABFSR & CM7_ABFSR_ITCM_Msk) ? 1U : 0U;
}

/**
 * @brief Check if DTCM asynchronous fault occurred
 * 检查是否发生 DTCM 异步故障
 */
uint32_t cm7_abfsr_dtcm_fault(void)
{
    return (CM7_ABFSR & CM7_ABFSR_DTCM_Msk) ? 1U : 0U;
}

/**
 * @brief Check if AHBP asynchronous fault occurred
 * 检查是否发生 AHBP 异步故障
 */
uint32_t cm7_abfsr_ahbp_fault(void)
{
    return (CM7_ABFSR & CM7_ABFSR_AHBP_Msk) ? 1U : 0U;
}

/**
 * @brief Check if AXIM asynchronous fault occurred
 * 检查是否发生 AXIM 异步故障
 */
uint32_t cm7_abfsr_axim_fault(void)
{
    return (CM7_ABFSR & CM7_ABFSR_AXIM_Msk) ? 1U : 0U;
}

/**
 * @brief Check if EPPB asynchronous fault occurred
 * 检查是否发生 EPPB 异步故障
 */
uint32_t cm7_abfsr_eppb_fault(void)
{
    return (CM7_ABFSR & CM7_ABFSR_EPPB_Msk) ? 1U : 0U;
}

/**
 * @brief Get AXIM fault type
 * 获取 AXIM 故障类型
 */
uint32_t cm7_abfsr_get_axim_type(void)
{
    return (CM7_ABFSR & CM7_ABFSR_AXIMTYPE_Msk) >> CM7_ABFSR_AXIMTYPE_Pos;
}

/* ============================================================================
 * Error Bank Functions (IEBR and DEBR)
 * 错误存储体函数 (IEBR 和 DEBR)
 * ============================================================================ */

/**
 * @brief Get IEBR0 value
 * 获取 IEBR0 值
 */
uint32_t cm7_iebr0_get(void)
{
    return CM7_IEBR0;
}

/**
 * @brief Get IEBR1 value
 * 获取 IEBR1 值
 */
uint32_t cm7_iebr1_get(void)
{
    return CM7_IEBR1;
}

/**
 * @brief Get DEBR0 value
 * 获取 DEBR0 值
 */
uint32_t cm7_debr0_get(void)
{
    return CM7_DEBR0;
}

/**
 * @brief Get DEBR1 value
 * 获取 DEBR1 值
 */
uint32_t cm7_debr1_get(void)
{
    return CM7_DEBR1;
}

/**
 * @brief Clear IEBR0
 * 清除 IEBR0
 */
void cm7_iebr0_clear(void)
{
    CM7_IEBR0 = 0UL;
    __DSB();
}

/**
 * @brief Clear IEBR1
 * 清除 IEBR1
 */
void cm7_iebr1_clear(void)
{
    CM7_IEBR1 = 0UL;
    __DSB();
}

/**
 * @brief Clear DEBR0
 * 清除 DEBR0
 */
void cm7_debr0_clear(void)
{
    CM7_DEBR0 = 0UL;
    __DSB();
}

/**
 * @brief Clear DEBR1
 * 清除 DEBR1
 */
void cm7_debr1_clear(void)
{
    CM7_DEBR1 = 0UL;
    __DSB();
}

/**
 * @brief Check if IEBR entry is valid
 * 检查 IEBR 条目是否有效
 */
uint32_t cm7_iebr_is_valid(uint32_t iebr_value)
{
    return (iebr_value & CM7_IEBR_VALID_Msk) ? 1U : 0U;
}

/**
 * @brief Check if DEBR entry is valid
 * 检查 DEBR 条目是否有效
 */
uint32_t cm7_debr_is_valid(uint32_t debr_value)
{
    return (debr_value & CM7_DEBR_VALID_Msk) ? 1U : 0U;
}

/**
 * @brief Get IEBR error type
 * 获取 IEBR 错误类型
 */
uint32_t cm7_iebr_get_type(uint32_t iebr_value)
{
    return (iebr_value & CM7_IEBR_TYPE_Msk) >> CM7_IEBR_TYPE_Pos;
}

/**
 * @brief Get DEBR error type
 * 获取 DEBR 错误类型
 */
uint32_t cm7_debr_get_type(uint32_t debr_value)
{
    return (debr_value & CM7_DEBR_TYPE_Msk) >> CM7_DEBR_TYPE_Pos;
}
