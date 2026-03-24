/*
 * ARM Architecture - Cortex-M4 TPIU Implementation
 *
 * ============================================================================
 * File: cm4_tpiu.c
 * Description: Cortex-M4 TPIU function implementations
 * 描述: Cortex-M4 TPIU 函数实现
 *
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual (100166_0001_04_en)
 *   - Chapter 11 Trace Port Interface Unit (page 11-91)
 *   - Table 11-1 TPIU registers (page 11-95)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include "armv7-m/cm4/cm4_tpiu.h"

/**
 * @brief Set SWO baud rate prescaler
 * @param prescaler Prescaler value (0-8191)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-2 (page 11-96)
 */
void cm4_tpiu_set_prescaler(uint32_t prescaler)
{
    TPIU_ACPR = prescaler & TPIU_ACPR_PRESCALER_Msk;
}

/**
 * @brief Set pin protocol
 * @param protocol Protocol (0=sync, 1=Manchester, 2=NRZ)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-1 (page 11-95)
 */
void cm4_tpiu_set_pin_protocol(uint32_t protocol)
{
    TPIU_SPPR = protocol & 0x3;
}

/**
 * @brief Enable formatter
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-1 (page 11-95)
 */
void cm4_tpiu_enable_formatter(void)
{
    TPIU_FFCR |= TPIU_FFCR_EnFCont_Msk;
}

/**
 * @brief Disable formatter
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-1 (page 11-95)
 */
void cm4_tpiu_disable_formatter(void)
{
    TPIU_FFCR &= ~TPIU_FFCR_EnFCont_Msk;
}

/**
 * @brief Get TPIU device ID
 * @return Device ID value
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-1 (page 11-95)
 */
uint32_t cm4_tpiu_get_devid(void)
{
    return TPIU_DEVID;
}
