/*
 * ARM Architecture - ARMv8-M RAS (Reliability, Availability, and Serviceability)
 *
 * ============================================================================
 * File: armv8-m_ras.c
 * Description: ARMv8-M RAS extension function implementations
 * 描述: ARMv8-M RAS 扩展函数实现
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter D1.1.7 Reliability, Availability and Serviceability Extension Fault Status Register
 *   - Chapter D1.1.16 Reliability, Availability and Serviceability Extension Fault Status Register
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv8-m_ras.h"

void ras_enable(void)
{
}

void ras_disable(void)
{
}

bool ras_is_present(void)
{
    return (__RAS_PRESENT == 1);
}

uint32_t ras_get_num_error_records(void)
{
    return (ERRDEVID & ERRDEVID_NUM_Msk) >> ERRDEVID_NUM_Pos;
}

bool ras_is_error_record_valid(uint32_t index)
{
    uint32_t num_records = ras_get_num_error_records();
    if (index >= num_records)
    {
        return false;
    }
    return (ERRSTATUS(index) & ERRSTATUS_V_Msk) != 0;
}

void ras_clear_error_record(uint32_t index)
{
    uint32_t num_records = ras_get_num_error_records();
    if (index < num_records)
    {
        ERRSTATUS(index) = 0;
    }
}
