/*
 * ARM Architecture - Cortex-M4 Debug Implementation
 *
 * ============================================================================
 * File: cm4_debug.c
 * Description: Cortex-M4 Debug function implementations
 * 描述: Cortex-M4 调试函数实现
 *
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual (100166_0001_04_en)
 *   - Chapter 8 Debug (page 8-72)
 *   - Table 8-4 Debug registers (page 8-77)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include "armv7-m/cm4/cm4_debug.h"

/**
 * @brief Enable debug
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 8.1 (page 8-72)
 */
void cm4_debug_enable(void)
{
    DEBUG_DHCSR = (DEBUG_DHCSR_DBGKEY_VALUE << DEBUG_DHCSR_DBGKEY_Pos) | DEBUG_DHCSR_C_DEBUGEN_Msk;
}

/**
 * @brief Disable debug
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 8.1 (page 8-72)
 */
void cm4_debug_disable(void)
{
    DEBUG_DHCSR = (DEBUG_DHCSR_DBGKEY_VALUE << DEBUG_DHCSR_DBGKEY_Pos);
}

/**
 * @brief Halt the processor
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 8.1 (page 8-72)
 */
void cm4_debug_halt(void)
{
    DEBUG_DHCSR = (DEBUG_DHCSR_DBGKEY_VALUE << DEBUG_DHCSR_DBGKEY_Pos) |
                  DEBUG_DHCSR_C_DEBUGEN_Msk | DEBUG_DHCSR_C_HALT_Msk;
}

/**
 * @brief Check if processor is halted
 * @return 1 if halted, 0 if not
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 8.1 (page 8-72)
 */
int cm4_debug_is_halted(void)
{
    return (DEBUG_DHCSR & DEBUG_DHCSR_S_HALT_Msk) ? 1 : 0;
}

/**
 * @brief Enable trace
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 8.1 (page 8-72)
 */
void cm4_debug_enable_trace(void)
{
    DEBUG_DEMCR |= DEBUG_DEMCR_TRCENA_Msk;
}

/**
 * @brief Disable trace
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 8.1 (page 8-72)
 */
void cm4_debug_disable_trace(void)
{
    DEBUG_DEMCR &= ~DEBUG_DEMCR_TRCENA_Msk;
}
