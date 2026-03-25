/*
 * ARM Architecture - Cortex-M4 Core Register Access
 *
 * ============================================================================
 * File: cm4_core.h
 * Description: Cortex-M4 core register access functions (wrapper for armv7-m_core.h)
 * 描述: Cortex-M4 核心寄存器访问函数（armv7-m_core.h 的包装层）
 *
 * This file provides CM4-specific naming conventions while delegating
 * all actual definitions to armv7-m_core.h.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 2 The Cortex-M4 Processor (page 2-1)
 *   - Chapter 3 The Cortex-M4 Instruction Set (page 3-1)
 *
 * Implementation: All functionality is provided by armv7-m/armv7-m_core.h
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_CORE_H__
#define __CM4_CORE_H__

#include <stdint.h>

/* Include the underlying ARMv7-M implementation */
#include "armv7-m/armv7-m_core.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * Core Register Aliases - Map CM4 naming to ARMv7-M naming
 * 核心寄存器别名 - 将 CM4 命名映射到 ARMv7-M 命名
 * ============================================================================
 */

/* APSR - Application Program Status Register */
#define CM4_APSR                      APSR

/* IPSR - Interrupt Program Status Register */
#define CM4_IPSR                      IPSR

/* EPSR - Execution Program Status Register */
#define CM4_EPSR                      EPSR

/* xPSR - Combined Program Status Register */
#define CM4_xPSR                      xPSR

/* MSP - Main Stack Pointer */
#define CM4_MSP                       MSP

/* PSP - Process Stack Pointer */
#define CM4_PSP                       PSP

/* PRIMASK - Priority Mask Register */
#define CM4_PRIMASK                   PRIMASK

/* BASEPRI - Base Priority Mask Register */
#define CM4_BASEPRI                   BASEPRI

/* FAULTMASK - Fault Mask Register */
#define CM4_FAULTMASK                 FAULTMASK

/* CONTROL - Control Register */
#define CM4_CONTROL                   CONTROL

/*
 * ============================================================================
 * Core Register Access Functions
 * 核心寄存器访问函数
 * Implementation: Delegates to armv7-m_core.h functions
 * ============================================================================
 */

/**
 * @brief Get APSR value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.2 (page 2-3)
 * Implementation: Delegates to __get_APSR() in armv7-m_core.h
 */
static inline uint32_t cm4_get_APSR(void)
{
    return __get_APSR();
}

/**
 * @brief Get IPSR value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.2 (page 2-3)
 * Implementation: Delegates to __get_IPSR() in armv7-m_core.h
 */
static inline uint32_t cm4_get_IPSR(void)
{
    return __get_IPSR();
}

/**
 * @brief Get xPSR value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.2 (page 2-3)
 * Implementation: Delegates to __get_xPSR() in armv7-m_core.h
 */
static inline uint32_t cm4_get_xPSR(void)
{
    return __get_xPSR();
}

/**
 * @brief Get MSP value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.3 (page 2-5)
 * Implementation: Delegates to __get_MSP() in armv7-m_core.h
 */
static inline uint32_t cm4_get_MSP(void)
{
    return __get_MSP();
}

/**
 * @brief Set MSP value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.3 (page 2-5)
 * Implementation: Delegates to __set_MSP() in armv7-m_core.h
 */
static inline void cm4_set_MSP(uint32_t topOfMainStack)
{
    __set_MSP(topOfMainStack);
}

/**
 * @brief Get PSP value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.3 (page 2-5)
 * Implementation: Delegates to __get_PSP() in armv7-m_core.h
 */
static inline uint32_t cm4_get_PSP(void)
{
    return __get_PSP();
}

/**
 * @brief Set PSP value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.3 (page 2-5)
 * Implementation: Delegates to __set_PSP() in armv7-m_core.h
 */
static inline void cm4_set_PSP(uint32_t topOfProcStack)
{
    __set_PSP(topOfProcStack);
}

/**
 * @brief Get PRIMASK value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.4 (page 2-6)
 * Implementation: Delegates to __get_PRIMASK() in armv7-m_core.h
 */
static inline uint32_t cm4_get_PRIMASK(void)
{
    return __get_PRIMASK();
}

/**
 * @brief Set PRIMASK value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.4 (page 2-6)
 * Implementation: Delegates to __set_PRIMASK() in armv7-m_core.h
 */
static inline void cm4_set_PRIMASK(uint32_t priMask)
{
    __set_PRIMASK(priMask);
}

/**
 * @brief Get BASEPRI value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.4 (page 2-6)
 * Implementation: Delegates to __get_BASEPRI() in armv7-m_core.h
 */
static inline uint32_t cm4_get_BASEPRI(void)
{
    return __get_BASEPRI();
}

/**
 * @brief Set BASEPRI value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.4 (page 2-6)
 * Implementation: Delegates to __set_BASEPRI() in armv7-m_core.h
 */
static inline void cm4_set_BASEPRI(uint32_t basePri)
{
    __set_BASEPRI(basePri);
}

/**
 * @brief Get FAULTMASK value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.4 (page 2-6)
 * Implementation: Delegates to __get_FAULTMASK() in armv7-m_core.h
 */
static inline uint32_t cm4_get_FAULTMASK(void)
{
    return __get_FAULTMASK();
}

/**
 * @brief Set FAULTMASK value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.4 (page 2-6)
 * Implementation: Delegates to __set_FAULTMASK() in armv7-m_core.h
 */
static inline void cm4_set_FAULTMASK(uint32_t faultMask)
{
    __set_FAULTMASK(faultMask);
}

/**
 * @brief Get CONTROL value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.4 (page 2-6)
 * Implementation: Delegates to __get_CONTROL() in armv7-m_core.h
 */
static inline uint32_t cm4_get_CONTROL(void)
{
    return __get_CONTROL();
}

/**
 * @brief Set CONTROL value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.4 (page 2-6)
 * Implementation: Delegates to __set_CONTROL() in armv7-m_core.h
 */
static inline void cm4_set_CONTROL(uint32_t control)
{
    __set_CONTROL(control);
}

/*
 * ============================================================================
 * Stack Pointer Selection
 * 堆栈指针选择
 * ============================================================================
 */

/**
 * @brief Select main stack pointer
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.3 (page 2-5)
 * Implementation: Delegates to armv7m_select_msp() in armv7-m_core.h
 */
static inline void cm4_select_msp(void)
{
    armv7m_select_msp();
}

/**
 * @brief Select process stack pointer
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.3 (page 2-5)
 * Implementation: Delegates to armv7m_select_psp() in armv7-m_core.h
 */
static inline void cm4_select_psp(void)
{
    armv7m_select_psp();
}

/**
 * @brief Check if currently using process stack
 * @return 1 if using PSP, 0 if using MSP
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.3 (page 2-5)
 * Implementation: Delegates to armv7m_is_psp_selected() in armv7-m_core.h
 */
static inline int cm4_is_psp_selected(void)
{
    return armv7m_is_psp_selected();
}

/*
 * ============================================================================
 * Privilege Level Control
 * 特权级别控制
 * ============================================================================
 */

/**
 * @brief Enter unprivileged (user) mode
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.4 (page 2-6)
 * Implementation: Delegates to armv7m_enter_unprivileged() in armv7-m_core.h
 */
static inline void cm4_enter_unprivileged(void)
{
    armv7m_enter_unprivileged();
}

/**
 * @brief Enter privileged mode
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.4 (page 2-6)
 * Implementation: Delegates to armv7m_enter_privileged() in armv7-m_core.h
 */
static inline void cm4_enter_privileged(void)
{
    armv7m_enter_privileged();
}

/**
 * @brief Check if currently in unprivileged mode
 * @return 1 if unprivileged, 0 if privileged
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.4 (page 2-6)
 * Implementation: Delegates to armv7m_is_unprivileged() in armv7-m_core.h
 */
static inline int cm4_is_unprivileged(void)
{
    return armv7m_is_unprivileged();
}

/*
 * ============================================================================
 * Floating-Point Context Control
 * 浮点上下文控制
 * ============================================================================
 */

/**
 * @brief Check if floating-point context is active
 * @return 1 if FPU context is active, 0 otherwise
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.4 (page 2-6)
 * Implementation: Delegates to armv7m_is_fp_active() in armv7-m_core.h
 */
static inline int cm4_is_fp_active(void)
{
    return armv7m_is_fp_active();
}

#ifdef __cplusplus
}
#endif

#endif /* __CM4_CORE_H__ */
