/*
 * ARM Architecture - ARMv8-M CTI Implementation
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv8-m/armv8-m_cti.h"

void cti_init(void)
{
    CTI_CONTROL = 0;
    CTI_APPCLEAR = 0xFF;
    for (int i = 0; i < 8; i++) {
        CTI_INEN(i) = 0;
        CTI_OUTEN(i) = 0;
    }
}

void cti_enable(void)
{
    CTI_CONTROL |= CTI_CONTROL_ENABLE_Msk;
}

void cti_disable(void)
{
    CTI_CONTROL &= ~CTI_CONTROL_ENABLE_Msk;
}

void cti_pulse_channel(uint32_t channel)
{
    if (channel < 8) {
        CTI_APPPULSE = (1U << channel);
    }
}

void cti_map_trigger_to_channel(uint32_t trigger, uint32_t channel)
{
    if (trigger < 8 && channel < 8) {
        CTI_INEN(trigger) |= (1U << channel);
    }
}

void cti_map_channel_to_trigger(uint32_t channel, uint32_t trigger)
{
    if (channel < 8 && trigger < 8) {
        CTI_OUTEN(channel) |= (1U << trigger);
    }
}

bool cti_is_present(void)
{
    return (CTI_CONTROL != 0xFFFFFFFFUL);
}
