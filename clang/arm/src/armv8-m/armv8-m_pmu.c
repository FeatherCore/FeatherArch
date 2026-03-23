/*
 * ARM Architecture - ARMv8-M PMU (Performance Monitor Unit)
 *
 * ============================================================================
 * File: armv8m_pmu.c
 * Description: ARMv8-M PMU function implementations
 * 描述: ARMv8-M PMU 函数实现
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B15: The Performance Monitors Extension
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv8m_pmu.h"

/*
 * ============================================================================
 * PMU Control Functions
 * PMU 控制函数
 * ============================================================================
 */

void pmu_enable(void)
{
    PMU_CTRL |= PMU_CTRL_E_Msk;
}

void pmu_disable(void)
{
    PMU_CTRL &= ~PMU_CTRL_E_Msk;
}

void pmu_reset_counters(void)
{
    PMU_CTRL |= PMU_CTRL_C_Msk;
    PMU_CTRL &= ~PMU_CTRL_C_Msk;
}

void pmu_reset_cycle_counter(void)
{
    PMU_CCNTR = 0;
}

uint32_t pmu_get_num_counters(void)
{
    return (PMU_TYPE & PMU_TYPE_NCNTR_Msk) >> PMU_TYPE_NCNTR_Pos;
}

/*
 * ============================================================================
 * PMU Counter Configuration
 * PMU 计数器配置
 * ============================================================================
 */

void pmu_configure_counter(uint32_t counter, uint32_t event)
{
    PMU_SELR = counter;
    PMU_EVTYPER(counter) = event;
}

void pmu_enable_counter(uint32_t counter)
{
    PMU_CNTENSET = (1UL << counter);
}

void pmu_disable_counter(uint32_t counter)
{
    PMU_CNTENCLR = (1UL << counter);
}

uint32_t pmu_get_counter_value(uint32_t counter)
{
    PMU_SELR = counter;
    return PMU_EVCNTR(counter);
}

void pmu_set_counter_value(uint32_t counter, uint32_t value)
{
    PMU_SELR = counter;
    PMU_EVCNTR(counter) = value;
}

/*
 * ============================================================================
 * PMU Cycle Counter
 * PMU 周期计数器
 * ============================================================================
 */

void pmu_enable_cycle_counter(void)
{
    PMU_CNTENSET = (1UL << 31);
}

void pmu_disable_cycle_counter(void)
{
    PMU_CNTENCLR = (1UL << 31);
}

uint32_t pmu_get_cycle_counter(void)
{
    return PMU_CCNTR;
}

void pmu_set_cycle_counter(uint32_t value)
{
    PMU_CCNTR = value;
}

/*
 * ============================================================================
 * PMU Overflow and Interrupts
 * PMU 溢出和中断
 * ============================================================================
 */

uint32_t pmu_get_overflow_status(void)
{
    return PMU_OVSCLR;
}

void pmu_clear_overflow(uint32_t flags)
{
    PMU_OVSCLR = flags;
}

void pmu_enable_overflow_interrupt(uint32_t counter)
{
    PMU_INTENSET = (1UL << counter);
}

void pmu_disable_overflow_interrupt(uint32_t counter)
{
    PMU_INTENCLR = (1UL << counter);
}

/*
 * ============================================================================
 * PMU Event Support Check
 * PMU 事件支持检查
 * ============================================================================
 */

bool pmu_is_event_supported(uint32_t event)
{
    if (event < 32) {
        return (PMU_CEID0 & (1UL << event)) != 0;
    } else if (event < 64) {
        return (PMU_CEID1 & (1UL << (event - 32))) != 0;
    }
    return false;
}
