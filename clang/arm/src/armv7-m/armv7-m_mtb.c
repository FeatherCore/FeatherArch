/*
 * ARM Architecture - ARMv7-M MTB Implementation
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_mtb.h"

void mtb_init(uint32_t base_addr, uint32_t buffer_size)
{
    MTB_BASE = base_addr;
    uint32_t mask = 0;
    while ((1U << (mask + 4)) < buffer_size && mask < 0x1F) {
        mask++;
    }
    MTB_MASTER = (mask & MTB_MASTER_MASK_Msk);
}

void mtb_enable(void)
{
    MTB_MASTER |= MTB_MASTER_EN_Msk;
}

void mtb_disable(void)
{
    MTB_MASTER &= ~MTB_MASTER_EN_Msk;
}

bool mtb_is_present(void)
{
    return (MTB_BASE != 0);
}
