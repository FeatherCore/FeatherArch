/*
 * ARM Architecture - ARMv7-M ROM Table Implementation
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_rom_table.h"

bool rom_table_validate(void)
{
    uint32_t cidr0 = ROM_CIDR0;
    uint32_t cidr1 = ROM_CIDR1;
    uint32_t cidr2 = ROM_CIDR2;
    uint32_t cidr3 = ROM_CIDR3;
    
    if ((cidr0 & 0xFF) != 0x0D) return false;
    if ((cidr1 & 0xFF) != 0x10) return false;
    if ((cidr2 & 0xFF) != 0x05) return false;
    if ((cidr3 & 0xFF) != 0xB1) return false;
    
    return true;
}

uint32_t rom_table_get_component_base(uint32_t entry_offset)
{
    uint32_t entry_value = *(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + entry_offset);
    
    if ((entry_value & 0x3) != ROM_ENTRY_PRESENT) {
        return 0UL;
    }
    
    int32_t offset = (int32_t)(entry_value & ~0xFFFUL);
    return (uint32_t)((int32_t)ROM_TABLE_BASE_ADDR + offset);
}
