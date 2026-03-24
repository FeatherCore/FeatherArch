/*
 * ARM Architecture - ARMv7-M ROM Table Implementation
 *
 * ============================================================================
 * File: armv7-m_rom_table.c
 * Description: ARMv7-M ROM Table function implementations
 * 描述: ARMv7-M ROM Table 函数实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B3.2.3: ROM table (page B3-600)
 *     * ROM table structure and entry format
 *     * ROM table entry: Bit[0]=Present, Bits[11:2]=Address offset
 *   - Appendix D1: Armv7-M CoreSight Infrastructure IDs (page D1-765)
 *     * D1.1 CoreSight infrastructure IDs for an Armv7-M implementation
 *       - Component ID registers (CID0-CID3) at offsets 0xFF0-0xFFF
 *       - ROM table Component Class = 0x1 in CID1[7:4]
 *       - CID0=0x0D, CID1=0x10, CID2=0x05, CID3=0xB1
 *     * Table D1-1: Component and Peripheral ID register formats (page D1-766)
 *       - Component ID preamble values for validation
 *   - Chapter C1.2.2: The Armv7-M ROM Table (page C1-686)
 *     * Table C1-3: Armv7-M DAP accessible ROM table
 *       - Entry format and component base address calculation
 *       - Entry 0: SCS at 0xE000E000
 *       - Entry 1: DWT at 0xE0001000
 *       - Entry 2: FPB at 0xE0002000
 *       - Entry 3: ITM at 0xE0000000
 *       - Entry 4: TPIU at 0xE0040000
 *       - Entry 5: ETM at 0xE0041000
 *
 * ROM Table Entry Format (B3.2.3, page B3-600):
 *   - Bit[0]: Present bit (1 = component present, 0 = component absent)
 *   - Bits[11:2]: Address offset (right-shifted by 2, signed)
 *   - Bits[31:12]: Reserved
 *
 * Component Base Address Calculation:
 *   base_addr = ROM_TABLE_BASE_ADDR + (entry_value & ~0xFFF)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_rom_table.h"

/*
 * ============================================================================
 * ROM Table Component ID Values
 * ROM表组件ID值
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 * ============================================================================
 */

/**
 * @brief Validate ROM table by checking Component ID
 * 通过检查组件ID验证ROM表
 * @return true if valid ROM table
 *
 * Checks CID0-CID3 for valid ROM table preamble values:
 * - CID0 should be 0x0D (preamble byte 0)
 * - CID1 should be 0x10 (Component Class=0x1 for ROM Table, preamble=0x0)
 * - CID2 should be 0x05 (preamble byte 2)
 * - CID3 should be 0xB1 (preamble byte 3)
 *
 * Reference: D1.1 CoreSight infrastructure IDs (page D1-765)
 *            Table D1-1 Component and Peripheral ID register formats (page D1-766)
 */
bool rom_table_validate(void)
{
    uint32_t cidr0 = ROM_CIDR0;
    uint32_t cidr1 = ROM_CIDR1;
    uint32_t cidr2 = ROM_CIDR2;
    uint32_t cidr3 = ROM_CIDR3;
    
    /* Check CID0 preamble: should be 0x0D */
    if ((cidr0 & 0xFF) != ROM_TABLE_CID0_VALUE) {
        return false;
    }
    
    /* Check CID1: Class=0x1 (ROM Table), Preamble=0x0 */
    if ((cidr1 & 0xFF) != ROM_TABLE_CID1_VALUE) {
        return false;
    }
    
    /* Check CID2 preamble: should be 0x05 */
    if ((cidr2 & 0xFF) != ROM_TABLE_CID2_VALUE) {
        return false;
    }
    
    /* Check CID3 preamble: should be 0xB1 */
    if ((cidr3 & 0xFF) != ROM_TABLE_CID3_VALUE) {
        return false;
    }
    
    return true;
}

/**
 * @brief Get component base address from ROM table entry
 * 从ROM表条目获取组件基地址
 * @param entry_offset ROM table entry offset
 * @return Component base address or 0 if not present
 *
 * Calculates component base address from ROM table entry:
 * 1. Read entry value at ROM_TABLE_BASE_ADDR + entry_offset
 * 2. Check present bit (bit[0])
 * 3. Extract signed address offset from bits[31:2] (sign-extended)
 * 4. Add offset to ROM_TABLE_BASE_ADDR
 *
 * Reference: B3.2.3 ROM table (page B3-600)
 *            Table C1-3 Armv7-M DAP accessible ROM table (page C1-686)
 */
uint32_t rom_table_get_component_base(uint32_t entry_offset)
{
    uint32_t entry_value = *(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + entry_offset);
    
    /* Check if component is present (bit[0] = 1) */
    if ((entry_value & ROM_ENTRY_PRESENT_Msk) != ROM_ENTRY_PRESENT) {
        return 0UL;
    }
    
    /* Extract signed address offset from bits[31:2] and sign-extend */
    int32_t offset = (int32_t)(entry_value & ~0xFFFUL);
    
    /* Calculate component base address */
    return (uint32_t)((int32_t)ROM_TABLE_BASE_ADDR + offset);
}

/**
 * @brief Get number of entries in ROM table
 * 获取ROM表条目数量
 * @return Number of valid entries before end marker
 *
 * Scans ROM table entries until end marker (0x00000000) is found.
 * Maximum scan depth is 48 entries (48 * 4 = 192 bytes, within 4KB block).
 *
 * Reference: Table C1-3 Armv7-M DAP accessible ROM table (page C1-686)
 */
uint32_t rom_table_get_entry_count(void)
{
    uint32_t count = 0;
    uint32_t offset = 0;
    
    /* Scan until end marker (0x00000000) or maximum entries reached */
    while (offset < 0xC0) {  /* Max 48 entries (48 * 4 = 192 bytes) */
        uint32_t entry = *(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + offset);
        
        /* End marker is 0x00000000 */
        if (entry == 0x00000000) {
            break;
        }
        
        count++;
        offset += 4;
    }
    
    return count;
}

/**
 * @brief Read ROM table Component ID registers
 * 读取ROM表组件ID寄存器
 * @param cid Pointer to store CID values (4 elements: CID0-CID3)
 *
 * Reads all Component ID registers from ROM table for validation.
 *
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 */
void rom_table_read_cid(uint8_t *cid)
{
    if (cid == NULL) {
        return;
    }
    
    cid[0] = (uint8_t)(ROM_CIDR0 & 0xFF);
    cid[1] = (uint8_t)(ROM_CIDR1 & 0xFF);
    cid[2] = (uint8_t)(ROM_CIDR2 & 0xFF);
    cid[3] = (uint8_t)(ROM_CIDR3 & 0xFF);
}

/**
 * @brief Read ROM table Peripheral ID registers
 * 读取ROM表外围设备ID寄存器
 * @param pid Pointer to store PID values (8 elements for PID0-PID7)
 *
 * Reads all Peripheral ID registers from ROM table.
 * Note: PID5-PID7 are reserved and read as 0.
 *
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 */
void rom_table_read_pid(uint8_t *pid)
{
    if (pid == NULL) {
        return;
    }
    
    pid[0] = (uint8_t)(ROM_PIDR0 & 0xFF);
    pid[1] = (uint8_t)(ROM_PIDR1 & 0xFF);
    pid[2] = (uint8_t)(ROM_PIDR2 & 0xFF);
    pid[3] = (uint8_t)(ROM_PIDR3 & 0xFF);
    pid[4] = (uint8_t)(ROM_PIDR4 & 0xFF);
    /* PID5-PID7 are reserved, read as 0 */
    pid[5] = 0;
    pid[6] = 0;
    pid[7] = 0;
}
