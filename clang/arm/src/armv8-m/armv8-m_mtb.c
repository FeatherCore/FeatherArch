/*
 * ARM Architecture - ARMv8-M MTB Implementation
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv8-m/armv8-m_mtb.h"

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

void mtb_set_trace_buffer(uint32_t base_addr, uint32_t size)
{
    mtb_disable();
    mtb_init(base_addr, size);
}

bool mtb_is_present(void)
{
    return (MTB_BASE != 0);
}
