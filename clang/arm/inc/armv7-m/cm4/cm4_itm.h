/*
 * ARM Architecture - Cortex-M4 ITM (Instrumentation Trace Macrocell)
 *
 * ============================================================================
 * File: cm4_itm.h
 * Description: Cortex-M4 ITM register definitions (wrapper for armv7-m_debug.h)
 * 描述: Cortex-M4 ITM 寄存器定义（armv7-m_debug.h 的包装层）
 *
 * This file provides CM4-specific naming conventions while delegating
 * all actual definitions to armv7-m_debug.h.
 *
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual (100166_0001_04_en)
 *   - Chapter 10 Instrumentation Trace Macrocell Unit (page 10-87)
 *   - Table 10-1 ITM register summary (page 10-89)
 *
 * Implementation: All functionality is provided by armv7-m/armv7-m_debug.h
 * Note: All register definitions are directly available from armv7-m_debug.h
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_ITM_H__
#define __CM4_ITM_H__

#include <stdint.h>

/* Include the underlying ARMv7-M implementation (ITM is part of debug architecture) */
/* This provides all ITM register definitions and bit fields */
#include "armv7-m/armv7-m_debug.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * ITM Base Address Alias
 * ITM 基地址别名
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 * ============================================================================
 */

#define CM4_ITM_BASE_ADDR             ITM_BASE_ADDR

/*
 * ============================================================================
 * ITM Register Definitions (Directly from armv7-m_debug.h)
 * The following registers are directly available from armv7-m_debug.h:
 * - ITM_STIM0-ITM_STIM31 - Stimulus Port Registers
 * - ITM_TER0-ITM_TER7 - Trace Enable Registers
 * - ITM_TPR - Trace Privilege Register
 * - ITM_TCR - Trace Control Register
 *
 * Bit definitions are also available:
 * - ITM_TPR_PRIVMASK_Pos, ITM_TPR_PRIVMASK_Msk
 * - ITM_TCR_ITMENA_Pos, ITM_TCR_ITMENA_Msk
 * - ITM_TCR_TSENA_Pos, ITM_TCR_TSENA_Msk
 * - ITM_TCR_SYNCENA_Pos, ITM_TCR_SYNCENA_Msk
 * - ITM_TCR_TXENA_Pos, ITM_TCR_TXENA_Msk
 * - ITM_TCR_SWOENA_Pos, ITM_TCR_SWOENA_Msk
 * - ITM_TCR_TSPRESCALE_Pos, ITM_TCR_TSPRESCALE_Msk
 * - ITM_TCR_STALLENA_Pos, ITM_TCR_STALLENA_Msk
 * - ITM_TCR_BUSY_Pos, ITM_TCR_BUSY_Msk
 * - ITM_TCR_TRACEBUSID_Pos, ITM_TCR_TRACEBUSID_Msk
 * - ITM_TCR_TSPRESCALE_DIV1, ITM_TCR_TSPRESCALE_DIV4
 * - ITM_TCR_TSPRESCALE_DIV16, ITM_TCR_TSPRESCALE_DIV64
 * ============================================================================
 */

/*
 * ============================================================================
 * ITM Function Wrapper Declarations
 * ITM 函数包装器声明
 * Implementation: Delegates to functions in armv7-m_debug.c
 * ============================================================================
 */

/**
 * @brief Enable ITM
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 10.1 (page 10-88)
 * Implementation: Delegates to itm_enable() in armv7-m_debug.c
 */
static inline void cm4_itm_enable(void)
{
    itm_enable();
}

/**
 * @brief Disable ITM
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 10.1 (page 10-88)
 * Implementation: Delegates to itm_disable() in armv7-m_debug.c
 */
static inline void cm4_itm_disable(void)
{
    itm_disable();
}

/**
 * @brief Send character via ITM
 * @param port Stimulus port (0-31)
 * @param ch Character to send
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 * Implementation: Delegates to itm_send_char() in armv7-m_debug.c
 */
static inline void cm4_itm_send_char(uint32_t port, uint8_t ch)
{
    itm_send_char(port, ch);
}

/**
 * @brief Send 32-bit word via ITM
 * @param port Stimulus port (0-31)
 * @param value Value to send
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 * Implementation: Delegates to itm_send_word() in armv7-m_debug.c
 */
static inline void cm4_itm_send_word(uint32_t port, uint32_t value)
{
    itm_send_word(port, value);
}

/**
 * @brief Check if ITM port is ready
 * @param port Stimulus port (0-31)
 * @return 1 if ready, 0 if not
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 * Implementation: Delegates to itm_port_ready() in armv7-m_debug.c
 */
static inline int cm4_itm_port_ready(uint32_t port)
{
    return itm_port_ready(port);
}

/**
 * @brief Enable ITM stimulus port
 * @param port Stimulus port (0-31)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 * Implementation: Delegates to itm_enable_port() in armv7-m_debug.c
 */
static inline void cm4_itm_enable_port(uint32_t port)
{
    itm_enable_port(port);
}

/**
 * @brief Disable ITM stimulus port
 * @param port Stimulus port (0-31)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 * Implementation: Delegates to itm_disable_port() in armv7-m_debug.c
 */
static inline void cm4_itm_disable_port(uint32_t port)
{
    itm_disable_port(port);
}

#ifdef __cplusplus
}
#endif

#endif /* __CM4_ITM_H__ */
