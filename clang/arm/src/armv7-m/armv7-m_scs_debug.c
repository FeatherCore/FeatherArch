/*
 * ARM Architecture - ARMv7-M SCS Debug Implementation
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_scs_debug.h"

void scs_debug_enable(void)
{
    DHCSR = (DHCSR_DBGKEY_VALUE << DHCSR_DBGKEY_Pos) | DHCSR_C_DEBUGEN_Msk;
}

void scs_debug_disable(void)
{
    DHCSR = (DHCSR_DBGKEY_VALUE << DHCSR_DBGKEY_Pos);
}

void scs_debug_halt(void)
{
    DHCSR = (DHCSR_DBGKEY_VALUE << DHCSR_DBGKEY_Pos) | DHCSR_C_DEBUGEN_Msk | DHCSR_C_HALT_Msk;
    while (!scs_debug_is_halted()) {
        __asm__ volatile ("nop");
    }
}

void scs_debug_resume(void)
{
    uint32_t dhcsr = DHCSR;
    dhcsr &= ~(DHCSR_C_HALT_Msk | DHCSR_C_STEP_Msk);
    DHCSR = (DHCSR_DBGKEY_VALUE << DHCSR_DBGKEY_Pos) | (dhcsr & 0xFFFF);
}

void scs_debug_step(void)
{
    DHCSR = (DHCSR_DBGKEY_VALUE << DHCSR_DBGKEY_Pos) | DHCSR_C_DEBUGEN_Msk | DHCSR_C_HALT_Msk | DHCSR_C_STEP_Msk;
}

bool scs_debug_is_halted(void)
{
    return (DHCSR & DHCSR_S_HALT_Msk) != 0;
}

bool scs_debug_is_lockup(void)
{
    return (DHCSR & DHCSR_S_LOCKUP_Msk) != 0;
}

bool scs_debug_is_sleeping(void)
{
    return (DHCSR & DHCSR_S_SLEEP_Msk) != 0;
}

void scs_debug_enable_monitor(void)
{
    DEMCR |= DEMCR_MON_EN_Msk;
}

void scs_debug_disable_monitor(void)
{
    DEMCR &= ~DEMCR_MON_EN_Msk;
}

void scs_debug_enable_trace(void)
{
    DEMCR |= DEMCR_TRCENA_Msk;
}

void scs_debug_disable_trace(void)
{
    DEMCR &= ~DEMCR_TRCENA_Msk;
}
