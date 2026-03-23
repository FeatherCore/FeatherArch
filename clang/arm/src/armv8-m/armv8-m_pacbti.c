/*
 * ARM Architecture - ARMv8-M PACBTI (Pointer Authentication and Branch Target Identification)
 *
 * ============================================================================
 * File: armv8m_pacbti.c
 * Description: ARMv8-M PACBTI function implementations
 * 描述: ARMv8-M PACBTI 函数实现
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B6: Pointer authentication and branch target identification Extension
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv8-m/armv8-m_pacbti.h"
#include "armv8-m/armv8-m_core.h"

/*
 * ============================================================================
 * PAC (Pointer Authentication Code) Functions
 * PAC 函数
 * ============================================================================
 */

void pac_enable(void)
{
    uint32_t control = __get_CONTROL();
    control |= (1UL << 4);
    __set_CONTROL(control);
}

void pac_disable(void)
{
    uint32_t control = __get_CONTROL();
    control &= ~(1UL << 4);
    __set_CONTROL(control);
}

bool pac_is_enabled(void)
{
    uint32_t control = __get_CONTROL();
    return (control & (1UL << 4)) != 0;
}

/*
 * ============================================================================
 * BTI (Branch Target Identification) Functions
 * BTI 函数
 * ============================================================================
 */

void bti_enable(void)
{
    uint32_t control = __get_CONTROL();
    control |= (1UL << 5);
    __set_CONTROL(control);
}

void bti_disable(void)
{
    uint32_t control = __get_CONTROL();
    control &= ~(1UL << 5);
    __set_CONTROL(control);
}

bool bti_is_enabled(void)
{
    uint32_t control = __get_CONTROL();
    return (control & (1UL << 5)) != 0;
}
