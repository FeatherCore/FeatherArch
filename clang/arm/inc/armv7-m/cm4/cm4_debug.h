/*
 * ARM Architecture - Cortex-M4 Debug Support
 *
 * ============================================================================
 * File: cm4_debug.h
 * Description: Cortex-M4 Debug register definitions (wrapper for armv7-m_debug.h)
 * 描述: Cortex-M4 Debug 寄存器定义（armv7-m_debug.h 的包装层）
 *
 * This file provides CM4-specific naming conventions while delegating
 * all actual definitions to armv7-m_debug.h.
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 4.7 Debug system (page 4-53)
 *   - Table 4-54 Debug registers (page 4-54)
 *
 * Implementation: All functionality is provided by armv7-m/armv7-m_debug.h
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_DEBUG_H__
#define __CM4_DEBUG_H__

#include <stdint.h>

/* Include the underlying ARMv7-M implementation */
#include "armv7-m/armv7-m_debug.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * Debug Base Address Alias
 * Debug 基地址别名
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 4-54 (page 4-54)
 * ============================================================================
 */

#define CM4_DEBUG_BASE_ADDR           DEBUG_BASE_ADDR

/*
 * ============================================================================
 * Debug Register Aliases - Map CM4 naming to ARMv7-M naming
 * Debug 寄存器别名 - 将 CM4 命名映射到 ARMv7-M 命名
 * ============================================================================
 */

/* Debug Halting Control and Status Register */
#define DEBUG_DHCSR                   DEBUG_DHCSR

/* DHCSR bit definitions */
#define DEBUG_DHCSR_DBGKEY_Pos        DHCSR_DBGKEY_Pos
#define DEBUG_DHCSR_DBGKEY_Msk        DHCSR_DBGKEY_Msk
#define DEBUG_DHCSR_S_RESET_ST_Pos    DHCSR_S_RESET_ST_Pos
#define DEBUG_DHCSR_S_RESET_ST_Msk    DHCSR_S_RESET_ST_Msk
#define DEBUG_DHCSR_S_RETIRE_ST_Pos   DHCSR_S_RETIRE_ST_Pos
#define DEBUG_DHCSR_S_RETIRE_ST_Msk   DHCSR_S_RETIRE_ST_Msk
#define DEBUG_DHCSR_S_LOCKUP_Pos      DHCSR_S_LOCKUP_Pos
#define DEBUG_DHCSR_S_LOCKUP_Msk      DHCSR_S_LOCKUP_Msk
#define DEBUG_DHCSR_S_SLEEP_Pos       DHCSR_S_SLEEP_Pos
#define DEBUG_DHCSR_S_SLEEP_Msk       DHCSR_S_SLEEP_Msk
#define DEBUG_DHCSR_S_HALT_Pos        DHCSR_S_HALT_Pos
#define DEBUG_DHCSR_S_HALT_Msk        DHCSR_S_HALT_Msk
#define DEBUG_DHCSR_S_REGRDY_Pos      DHCSR_S_REGRDY_Pos
#define DEBUG_DHCSR_S_REGRDY_Msk      DHCSR_S_REGRDY_Msk
#define DEBUG_DHCSR_C_SNAPSTALL_Pos   DHCSR_C_SNAPSTALL_Pos
#define DEBUG_DHCSR_C_SNAPSTALL_Msk   DHCSR_C_SNAPSTALL_Msk
#define DEBUG_DHCSR_C_MASKINTS_Pos    DHCSR_C_MASKINTS_Pos
#define DEBUG_DHCSR_C_MASKINTS_Msk    DHCSR_C_MASKINTS_Msk
#define DEBUG_DHCSR_C_STEP_Pos        DHCSR_C_STEP_Pos
#define DEBUG_DHCSR_C_STEP_Msk        DHCSR_C_STEP_Msk
#define DEBUG_DHCSR_C_HALT_Pos        DHCSR_C_HALT_Pos
#define DEBUG_DHCSR_C_HALT_Msk        DHCSR_C_HALT_Msk
#define DEBUG_DHCSR_C_DEBUGEN_Pos     DHCSR_C_DEBUGEN_Pos
#define DEBUG_DHCSR_C_DEBUGEN_Msk     DHCSR_C_DEBUGEN_Msk

/* Debug Core Register Selector Register */
#define DEBUG_DCRSR                   DEBUG_DCRSR

/* DCRSR bit definitions */
#define DEBUG_DCRSR_REGWnR_Pos        DCRSR_REGWnR_Pos
#define DEBUG_DCRSR_REGWnR_Msk        DCRSR_REGWnR_Msk
#define DEBUG_DCRSR_REGSEL_Pos        DCRSR_REGSEL_Pos
#define DEBUG_DCRSR_REGSEL_Msk        DCRSR_REGSEL_Msk

/* Debug Core Register Data Register */
#define DEBUG_DCRDR                   DEBUG_DCRDR

/* Debug Exception and Monitor Control Register */
#define DEBUG_DEMCR                   DEBUG_DEMCR

/* DEMCR bit definitions */
#define DEBUG_DEMCR_TRCENA_Pos        DEMCR_TRCENA_Pos
#define DEBUG_DEMCR_TRCENA_Msk        DEMCR_TRCENA_Msk
#define DEBUG_DEMCR_MON_REQ_Pos       DEMCR_MON_REQ_Pos
#define DEBUG_DEMCR_MON_REQ_Msk       DEMCR_MON_REQ_Msk
#define DEBUG_DEMCR_MON_STEP_Pos      DEMCR_MON_STEP_Pos
#define DEBUG_DEMCR_MON_STEP_Msk      DEMCR_MON_STEP_Msk
#define DEBUG_DEMCR_MON_PEND_Pos      DEMCR_MON_PEND_Pos
#define DEBUG_DEMCR_MON_PEND_Msk      DEMCR_MON_PEND_Msk
#define DEBUG_DEMCR_MON_EN_Pos        DEMCR_MON_EN_Pos
#define DEBUG_DEMCR_MON_EN_Msk        DEMCR_MON_EN_Msk
#define DEBUG_DEMCR_VC_HARDERR_Pos    DEMCR_VC_HARDERR_Pos
#define DEBUG_DEMCR_VC_HARDERR_Msk    DEMCR_VC_HARDERR_Msk
#define DEBUG_DEMCR_VC_INTERR_Pos     DEMCR_VC_INTERR_Pos
#define DEBUG_DEMCR_VC_INTERR_Msk     DEMCR_VC_INTERR_Msk
#define DEBUG_DEMCR_VC_BUSERR_Pos     DEMCR_VC_BUSERR_Pos
#define DEBUG_DEMCR_VC_BUSERR_Msk     DEMCR_VC_BUSERR_Msk
#define DEBUG_DEMCR_VC_STATERR_Pos    DEMCR_VC_STATERR_Pos
#define DEBUG_DEMCR_VC_STATERR_Msk    DEMCR_VC_STATERR_Msk
#define DEBUG_DEMCR_VC_CHKERR_Pos     DEMCR_VC_CHKERR_Pos
#define DEBUG_DEMCR_VC_CHKERR_Msk     DEMCR_VC_CHKERR_Msk
#define DEBUG_DEMCR_VC_NOCPERR_Pos    DEMCR_VC_NOCPERR_Pos
#define DEBUG_DEMCR_VC_NOCPERR_Msk    DEMCR_VC_NOCPERR_Msk
#define DEBUG_DEMCR_VC_MMERR_Pos      DEMCR_VC_MMERR_Pos
#define DEBUG_DEMCR_VC_MMERR_Msk      DEMCR_VC_MMERR_Msk
#define DEBUG_DEMCR_VC_CORERESET_Pos  DEMCR_VC_CORERESET_Pos
#define DEBUG_DEMCR_VC_CORERESET_Msk  DEMCR_VC_CORERESET_Msk

/*
 * ============================================================================
 * Function Aliases - Map CM4 naming to ARMv7-M naming
 * 函数别名 - 将 CM4 命名映射到 ARMv7-M 命名
 * ============================================================================
 */

/**
 * @brief Enable debug mode
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.7.1 (page 4-54)
 * Implementation: Delegates to debug_enable() in armv7-m_debug.c
 */
static inline void cm4_debug_enable(void)
{
    debug_enable();
}

/**
 * @brief Disable debug mode
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.7.1 (page 4-54)
 * Implementation: Delegates to debug_disable() in armv7-m_debug.c
 */
static inline void cm4_debug_disable(void)
{
    debug_disable();
}

/**
 * @brief Check if debug is enabled
 * @return 1 if enabled, 0 if disabled
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.7.1 (page 4-54)
 * Implementation: Delegates to debug_is_enabled() in armv7-m_debug.c
 */
static inline int cm4_debug_is_enabled(void)
{
    return debug_is_enabled();
}

/**
 * @brief Halt the processor
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.7.1 (page 4-54)
 * Implementation: Delegates to debug_halt() in armv7-m_debug.c
 */
static inline void cm4_debug_halt(void)
{
    debug_halt();
}

/**
 * @brief Resume the processor
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.7.1 (page 4-54)
 * Implementation: Delegates to debug_resume() in armv7-m_debug.c
 */
static inline void cm4_debug_resume(void)
{
    debug_resume();
}

/**
 * @brief Check if processor is halted
 * @return 1 if halted, 0 if running
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.7.1 (page 4-54)
 * Implementation: Delegates to debug_is_halted() in armv7-m_debug.c
 */
static inline int cm4_debug_is_halted(void)
{
    return debug_is_halted();
}

/**
 * @brief Single step the processor
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.7.1 (page 4-54)
 * Implementation: Delegates to debug_step() in armv7-m_debug.c
 */
static inline void cm4_debug_step(void)
{
    debug_step();
}

/**
 * @brief Enable trace
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.7.4 (page 4-58)
 * Implementation: Delegates to debug_enable_trace() in armv7-m_debug.c
 */
static inline void cm4_debug_enable_trace(void)
{
    debug_enable_trace();
}

/**
 * @brief Disable trace
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.7.4 (page 4-58)
 * Implementation: Delegates to debug_disable_trace() in armv7-m_debug.c
 */
static inline void cm4_debug_disable_trace(void)
{
    debug_disable_trace();
}

/**
 * @brief Check if trace is enabled
 * @return 1 if enabled, 0 if disabled
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.7.4 (page 4-58)
 * Implementation: Delegates to debug_is_trace_enabled() in armv7-m_debug.c
 */
static inline int cm4_debug_is_trace_enabled(void)
{
    return debug_is_trace_enabled();
}

/**
 * @brief Enable monitor mode debug
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.7.4 (page 4-58)
 * Implementation: Delegates to debug_enable_monitor() in armv7-m_debug.c
 */
static inline void cm4_debug_enable_monitor(void)
{
    debug_enable_monitor();
}

/**
 * @brief Disable monitor mode debug
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.7.4 (page 4-58)
 * Implementation: Delegates to debug_disable_monitor() in armv7-m_debug.c
 */
static inline void cm4_debug_disable_monitor(void)
{
    debug_disable_monitor();
}

/**
 * @brief Enable vector catch for HardFault
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.7.4 (page 4-58)
 * Implementation: Delegates to debug_enable_vc_harderr() in armv7-m_debug.c
 */
static inline void cm4_debug_enable_vc_harderr(void)
{
    debug_enable_vc_harderr();
}

/**
 * @brief Disable vector catch for HardFault
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.7.4 (page 4-58)
 * Implementation: Delegates to debug_disable_vc_harderr() in armv7-m_debug.c
 */
static inline void cm4_debug_disable_vc_harderr(void)
{
    debug_disable_vc_harderr();
}

/**
 * @brief Enable vector catch for reset
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.7.4 (page 4-58)
 * Implementation: Delegates to debug_enable_vc_reset() in armv7-m_debug.c
 */
static inline void cm4_debug_enable_vc_reset(void)
{
    debug_enable_vc_reset();
}

/**
 * @brief Disable vector catch for reset
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 4.7.4 (page 4-58)
 * Implementation: Delegates to debug_disable_vc_reset() in armv7-m_debug.c
 */
static inline void cm4_debug_disable_vc_reset(void)
{
    debug_disable_vc_reset();
}

#ifdef __cplusplus
}
#endif

#endif /* __CM4_DEBUG_H__ */
