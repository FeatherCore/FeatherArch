/*
 * ARM Architecture - Cortex-M4 ITM Implementation
 *
 * ============================================================================
 * File: cm4_itm.c
 * Description: Cortex-M4 ITM function implementations
 * 描述: Cortex-M4 ITM 函数实现
 *
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual (100166_0001_04_en)
 *   - Chapter 10 Instrumentation Trace Macrocell Unit (page 10-87)
 *   - Table 10-1 ITM register summary (page 10-89)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include "armv7-m/cm4/cm4_itm.h"

/**
 * @brief Enable ITM
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 10.1 (page 10-88)
 */
void cm4_itm_enable(void)
{
    ITM_TCR |= ITM_TCR_ITMENA_Msk;
}

/**
 * @brief Disable ITM
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 10.1 (page 10-88)
 */
void cm4_itm_disable(void)
{
    ITM_TCR &= ~ITM_TCR_ITMENA_Msk;
}

/**
 * @brief Send character via ITM
 * @param port Stimulus port (0-31)
 * @param ch Character to send
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 */
void cm4_itm_send_char(uint32_t port, uint8_t ch)
{
    if (port < 32) {
        volatile uint32_t *stim = (volatile uint32_t *)(CM4_ITM_BASE_ADDR + (port * 4));
        *stim = ch;
    }
}

/**
 * @brief Send 32-bit word via ITM
 * @param port Stimulus port (0-31)
 * @param value Value to send
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 */
void cm4_itm_send_word(uint32_t port, uint32_t value)
{
    if (port < 32) {
        volatile uint32_t *stim = (volatile uint32_t *)(CM4_ITM_BASE_ADDR + (port * 4));
        *stim = value;
    }
}

/**
 * @brief Check if ITM port is ready
 * @param port Stimulus port (0-31)
 * @return 1 if ready, 0 if not
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 */
int cm4_itm_port_ready(uint32_t port)
{
    if (port < 32) {
        volatile uint32_t *stim = (volatile uint32_t *)(CM4_ITM_BASE_ADDR + (port * 4));
        return (*stim & 1) ? 1 : 0;
    }
    return 0;
}

/**
 * @brief Enable ITM stimulus port
 * @param port Stimulus port (0-31)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 */
void cm4_itm_enable_port(uint32_t port)
{
    if (port < 32) {
        ITM_TER |= (1UL << port);
    }
}

/**
 * @brief Disable ITM stimulus port
 * @param port Stimulus port (0-31)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 */
void cm4_itm_disable_port(uint32_t port)
{
    if (port < 32) {
        ITM_TER &= ~(1UL << port);
    }
}
