/*
 * ARM Architecture - ARMv8-M ROM Table Implementation
 *
 * ============================================================================
 * File: armv8-m_rom_table.c
 * Description: ARMv8-M ROM Table implementation for CoreSight component discovery
 * 描述: ARMv8-M ROM Table 实现，用于 CoreSight 组件发现
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B13.2.1: ROM table
 *   - Chapter D1.2: ROM Table Register Definitions
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv8-m/armv8-m_rom_table.h"

/*
 * ============================================================================
 * Component Information Table
 * 组件信息表
 * ============================================================================
 */

static const rom_component_info_t rom_component_table[ROM_COMP_COUNT] = {
    [ROM_COMP_SCS]  = { ROM_TABLE_ENTRY0_OFFSET, 0xE000E000UL, "SCS",  false },
    [ROM_COMP_DWT]  = { ROM_TABLE_ENTRY1_OFFSET, 0xE0001000UL, "DWT",  false },
    [ROM_COMP_FPB]  = { ROM_TABLE_ENTRY2_OFFSET, 0xE0002000UL, "FPB",  false },
    [ROM_COMP_ITM]  = { ROM_TABLE_ENTRY3_OFFSET, 0xE0000000UL, "ITM",  true  },
    [ROM_COMP_TPIU] = { ROM_TABLE_ENTRY4_OFFSET, 0xE0040000UL, "TPIU", true  },
    [ROM_COMP_ETM]  = { ROM_TABLE_ENTRY5_OFFSET, 0xE0041000UL, "ETM",  true  },
    [ROM_COMP_MTB]  = { 0x000,                     0x00000000UL, "MTB",  true  },
    [ROM_COMP_CTI]  = { 0x000,                     0x00000000UL, "CTI",  true  }
};

/*
 * ============================================================================
 * ROM Table Functions
 * ROM Table 函数
 * ============================================================================
 */

/**
 * @brief Initialize ROM table access
 * 初始化 ROM Table 访问
 */
void rom_table_init(void)
{
    /* ROM table is read-only, no initialization required */
    /* Verify ROM table is valid */
    (void)rom_table_validate();
}

/**
 * @brief Check if ROM table is present
 * 检查 ROM Table 是否存在
 * @return true if ROM table is present
 */
bool rom_table_is_present(void)
{
    return rom_table_validate();
}

/**
 * @brief Get component base address from ROM table entry
 * 从 ROM Table 条目获取组件基地址
 * @param entry_offset ROM table entry offset
 * @return Component base address, 0 if not present
 */
uint32_t rom_table_get_component_base(uint32_t entry_offset)
{
    volatile uint32_t *entry_ptr = (volatile uint32_t *)(ROM_TABLE_BASE_ADDR + entry_offset);
    uint32_t entry_value = *entry_ptr;
    
    /* Check if component is present */
    if ((entry_value & ROM_ENTRY_PRESENT_Msk) != ROM_ENTRY_PRESENT) {
        return 0UL;
    }
    
    /* Calculate component base address from offset */
    int32_t offset = (int32_t)(entry_value & ~0xFFFUL);
    return (uint32_t)((int32_t)ROM_TABLE_BASE_ADDR + offset);
}

/**
 * @brief Check if component is present
 * 检查组件是否存在
 * @param component Component identifier
 * @return true if component is present
 */
bool rom_table_component_is_present(rom_component_t component)
{
    if (component >= ROM_COMP_COUNT) {
        return false;
    }
    
    const rom_component_info_t *info = &rom_component_table[component];
    
    /* For components with known entry offsets */
    if (info->entry_offset != 0) {
        uint32_t entry_value = *(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + info->entry_offset);
        return (entry_value & ROM_ENTRY_PRESENT_Msk) == ROM_ENTRY_PRESENT;
    }
    
    /* For optional components without fixed entries, check at known address */
    /* This is implementation-specific */
    return false;
}

/**
 * @brief Get component base address
 * 获取组件基地址
 * @param component Component identifier
 * @return Component base address, 0 if not present
 */
uint32_t rom_table_get_component_address(rom_component_t component)
{
    if (component >= ROM_COMP_COUNT) {
        return 0UL;
    }
    
    if (!rom_table_component_is_present(component)) {
        return 0UL;
    }
    
    const rom_component_info_t *info = &rom_component_table[component];
    
    /* For components with known entry offsets, read from ROM table */
    if (info->entry_offset != 0) {
        return rom_table_get_component_base(info->entry_offset);
    }
    
    /* Return default base address */
    return info->component_base;
}

/**
 * @brief Validate ROM table (check CIDR values)
 * 验证 ROM Table (检查 CIDR 值)
 * @return true if ROM table is valid
 */
bool rom_table_validate(void)
{
    /* Check Component ID registers for CoreSight ROM table signature */
    uint32_t cidr0 = ROM_CIDR0;
    uint32_t cidr1 = ROM_CIDR1;
    uint32_t cidr2 = ROM_CIDR2;
    uint32_t cidr3 = ROM_CIDR3;
    
    /* Validate CIDR preamble bytes */
    if ((cidr0 & 0xFF) != ROM_CIDR0_VALUE) {
        return false;
    }
    
    if ((cidr1 & 0xFF) != ROM_CIDR1_VALUE) {
        return false;
    }
    
    if ((cidr2 & 0xFF) != ROM_CIDR2_VALUE) {
        return false;
    }
    
    if ((cidr3 & 0xFF) != ROM_CIDR3_VALUE) {
        return false;
    }
    
    return true;
}

/**
 * @brief Get ROM table peripheral ID
 * 获取 ROM Table 外设 ID
 * @return 64-bit peripheral ID
 */
uint64_t rom_table_get_peripheral_id(void)
{
    uint64_t pid = 0;
    
    pid |= ((uint64_t)(ROM_PIDR0 & 0xFF) << 0);
    pid |= ((uint64_t)(ROM_PIDR1 & 0xFF) << 8);
    pid |= ((uint64_t)(ROM_PIDR2 & 0xFF) << 16);
    pid |= ((uint64_t)(ROM_PIDR3 & 0xFF) << 24);
    pid |= ((uint64_t)(ROM_PIDR4 & 0xFF) << 32);
    
    return pid;
}

/**
 * @brief Check if system memory is accessible through ROM table
 * 检查系统内存是否可通过 ROM Table 访问
 * @return true if system memory is accessible
 */
bool rom_table_system_memory_present(void)
{
    return (ROM_MEMTYPE & ROM_MEMTYPE_SYSMEM_Msk) != 0;
}

/**
 * @brief Scan ROM table and print component information
 * 扫描 ROM Table 并打印组件信息
 * (Debug/development function)
 */
void rom_table_scan(void)
{
    /* Scan all ROM table entries */
    for (uint32_t offset = 0; offset < 0x20; offset += 4) {
        uint32_t entry = *(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + offset);
        
        /* Check for end marker */
        if (entry == 0) {
            break;
        }
        
        /* Check if component is present */
        if ((entry & ROM_ENTRY_PRESENT_Msk) == ROM_ENTRY_PRESENT) {
            /* Calculate component address */
            int32_t addr_offset = (int32_t)(entry & ~0xFFFUL);
            uint32_t comp_addr = (uint32_t)((int32_t)ROM_TABLE_BASE_ADDR + addr_offset);
            
            /* Determine component name based on offset */
            const char *comp_name = "Unknown";
            switch (offset) {
                case ROM_TABLE_ENTRY0_OFFSET: comp_name = "SCS"; break;
                case ROM_TABLE_ENTRY1_OFFSET: comp_name = "DWT"; break;
                case ROM_TABLE_ENTRY2_OFFSET: comp_name = "FPB"; break;
                case ROM_TABLE_ENTRY3_OFFSET: comp_name = "ITM"; break;
                case ROM_TABLE_ENTRY4_OFFSET: comp_name = "TPIU"; break;
                case ROM_TABLE_ENTRY5_OFFSET: comp_name = "ETM"; break;
                case ROM_TABLE_ENTRY6_OFFSET: comp_name = "Reserved"; break;
                case ROM_TABLE_ENTRY7_OFFSET: comp_name = "End"; break;
            }
            
            /* Output via ITM if available, otherwise store in debug buffer */
            /* In a real implementation, this would use ITM_SendChar or similar */
            (void)comp_name;
            (void)comp_addr;
        }
    }
}
