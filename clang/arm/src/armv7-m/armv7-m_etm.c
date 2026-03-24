/*
 * ARM Architecture - ARMv7-M ETM Implementation
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_etm.h"

void etm_init(void)
{
    if (!etm_is_present()) {
        return;
    }
    
    etm_disable();
    
    while (ETM_SR & ETM_SR_PMSTANDBY_Msk) {
        __asm__ volatile ("nop");
    }
    
    ETM_CR = 0;
    ETM_TEEVR = 0;
    ETM_TECR1 = 0;
}

void etm_enable(void)
{
    ETM_CR |= ETM_CR_ETMEN_Msk;
}

void etm_disable(void)
{
    ETM_CR &= ~ETM_CR_ETMEN_Msk;
}

bool etm_is_present(void)
{
    uint32_t cidr0 = ETM_CIDR0;
    uint32_t cidr1 = ETM_CIDR1;
    uint32_t cidr2 = ETM_CIDR2;
    uint32_t cidr3 = ETM_CIDR3;
    
    if ((cidr0 & 0xFF) != 0x0D) return false;
    if ((cidr1 & 0xFF) != 0x90) return false;
    if ((cidr2 & 0xFF) != 0x05) return false;
    if ((cidr3 & 0xFF) != 0xB1) return false;
    
    return true;
}

bool etm_is_enabled(void)
{
    return (ETM_CR & ETM_CR_ETMEN_Msk) != 0;
}

void etm_software_trigger(void)
{
    ETM_TRIGGER = 1;
}
