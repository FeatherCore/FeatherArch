/*
 * ARM Architecture - ARMv7-M ROM Table
 *
 * ============================================================================
 * File: armv7-m_rom_table.h
 * Description: ARMv7-M ROM Table definitions for CoreSight component discovery
 * 描述: ARMv7-M ROM Table 定义，用于 CoreSight 组件发现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B3.2.3: ROM table (page B3-600)
 *     * ROM table structure and entries
 *     * ROM table entry format (address offset and present bit)
 *   - Appendix D1: Armv7-M CoreSight Infrastructure IDs (page D1-765)
 *     * D1.1 CoreSight infrastructure IDs for an Armv7-M implementation
 *       - Component ID registers (CID0-CID3) at offsets 0xFF0-0xFFF
 *       - Peripheral ID registers (PID0-PID4) at offsets 0xFD0-0xFEF
 *       - ROM table uses Component Class 0x1 in CID1[7:4]
 *     * Table D1-1: Component and Peripheral ID register formats
 *       - CID0: 0x0D, CID1: 0x10 (Class=ROM Table), CID2: 0x05, CID3: 0xB1
 *       - PID0-PID3: Part Number, JEP106 ID, Revision
 *       - PID4: 4KB count, JEP106 continuation code
 *     * Table D1-2: CoreSight Software Lock registers
 *       - LAR (Lock Access Register) at offset 0xFB0 (WO)
 *       - LSR (Lock Status Register) at offset 0xFB4 (RO)
 *   - Chapter C1.2.2: The Armv7-M ROM Table (page C1-686)
 *     * Table C1-3: Armv7-M DAP accessible ROM table
 *       - Entry 0: SCS (System Control Space) at 0xE000E000
 *       - Entry 1: DWT (Data Watchpoint and Trace) at 0xE0001000
 *       - Entry 2: FPB (Flash Patch and Breakpoint) at 0xE0002000
 *       - Entry 3: ITM (Instrumentation Trace Macrocell) at 0xE0000000
 *       - Entry 4: TPIU (Trace Port Interface Unit) at 0xE0040000
 *       - Entry 5: ETM (Embedded Trace Macrocell) at 0xE0041000
 *       - Entry 6: End of table marker (0x00000000)
 *
 * ROM Table Entry Format:
 *   - Bit[0]: Present bit (1 = component present, 0 = component absent)
 *   - Bits[11:2]: Address offset (right-shifted by 2)
 *   - Bits[31:12]: Reserved
 *
 * ROM Table Base Address: 0xE00FF000
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_ROM_TABLE_H__
#define __ARCH_ARM_V7M_ROM_TABLE_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv7-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * ROM Table Base Address
 * ROM表基地址
 * Reference: C1.2.2 The Armv7-M ROM Table (page C1-686)
 * ============================================================================
 */

#define ROM_TABLE_BASE_ADDR       0xE00FF000UL

/*
 * ============================================================================
 * ROM Table Entry Offsets
 * ROM表条目偏移
 * Reference: Table C1-3 Armv7-M DAP accessible ROM table (page C1-686)
 * ============================================================================
 */

#define ROM_ENTRY_SCS_OFFSET      0x000U     /*!< SCS entry offset */
#define ROM_ENTRY_DWT_OFFSET      0x004U     /*!< DWT entry offset */
#define ROM_ENTRY_FPB_OFFSET      0x008U     /*!< FPB entry offset */
#define ROM_ENTRY_ITM_OFFSET      0x00CU     /*!< ITM entry offset */
#define ROM_ENTRY_TPIU_OFFSET     0x010U     /*!< TPIU entry offset */
#define ROM_ENTRY_ETM_OFFSET      0x014U     /*!< ETM entry offset */
#define ROM_ENTRY_END_OFFSET      0x018U     /*!< End of table marker offset */

/*
 * ============================================================================
 * ROM Table Entry Registers
 * ROM表条目寄存器
 * Reference: Table C1-3 Armv7-M DAP accessible ROM table (page C1-686)
 * ============================================================================
 */

#define ROM_ENTRY_SCS             (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + ROM_ENTRY_SCS_OFFSET))   /*!< SCS ROM entry */
#define ROM_ENTRY_DWT             (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + ROM_ENTRY_DWT_OFFSET))   /*!< DWT ROM entry */
#define ROM_ENTRY_FPB             (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + ROM_ENTRY_FPB_OFFSET))   /*!< FPB ROM entry */
#define ROM_ENTRY_ITM             (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + ROM_ENTRY_ITM_OFFSET))   /*!< ITM ROM entry */
#define ROM_ENTRY_TPIU            (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + ROM_ENTRY_TPIU_OFFSET))  /*!< TPIU ROM entry */
#define ROM_ENTRY_ETM             (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + ROM_ENTRY_ETM_OFFSET))   /*!< ETM ROM entry */
#define ROM_ENTRY_END             (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + ROM_ENTRY_END_OFFSET))   /*!< End of table marker */

/*
 * ============================================================================
 * ROM Table Memory Type Register
 * ROM表内存类型寄存器
 * Reference: D1.1 CoreSight infrastructure IDs (page D1-765)
 * ============================================================================
 */

#define ROM_MEMTYPE               (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFCC))

/*
 * ============================================================================
 * ROM Table Peripheral ID Registers
 * ROM表外围设备ID寄存器
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 * ============================================================================
 */

#define ROM_PIDR4                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFD0))  /*!< Peripheral ID4 */
#define ROM_PIDR0                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFE0))  /*!< Peripheral ID0 */
#define ROM_PIDR1                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFE4))  /*!< Peripheral ID1 */
#define ROM_PIDR2                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFE8))  /*!< Peripheral ID2 */
#define ROM_PIDR3                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFEC))  /*!< Peripheral ID3 */

/*
 * ============================================================================
 * ROM Table Component ID Registers
 * ROM表组件ID寄存器
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 * ============================================================================
 */

#define ROM_CIDR0                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFF0))  /*!< Component ID0 */
#define ROM_CIDR1                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFF4))  /*!< Component ID1 */
#define ROM_CIDR2                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFF8))  /*!< Component ID2 */
#define ROM_CIDR3                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFFC))  /*!< Component ID3 */

/*
 * ============================================================================
 * ROM Table Entry Bit Definitions
 * ROM表条目位定义
 * Reference: B3.2.3 ROM table (page B3-600)
 * ============================================================================
 */

#define ROM_ENTRY_PRESENT_Pos     0U
#define ROM_ENTRY_PRESENT_Msk     (1UL << ROM_ENTRY_PRESENT_Pos)  /*!< Present bit mask */
#define ROM_ENTRY_PRESENT         0x1UL                           /*!< Component present */
#define ROM_ENTRY_ABSENT          0x0UL                           /*!< Component absent */
#define ROM_ENTRY_ADDR_OFFSET_Pos 2U
#define ROM_ENTRY_ADDR_OFFSET_Msk (0x3FFUL << ROM_ENTRY_ADDR_OFFSET_Pos)  /*!< Address offset mask */

/*
 * ============================================================================
 * ROM Table Component ID Values
 * ROM表组件ID值
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 * ============================================================================
 */

#define ROM_TABLE_CID0_VALUE      0x0DU  /*!< CID0: Preamble byte 0 */
#define ROM_TABLE_CID1_VALUE      0x10U  /*!< CID1: Class=0x1 (ROM Table), Preamble=0x0 */
#define ROM_TABLE_CID2_VALUE      0x05U  /*!< CID2: Preamble byte 2 */
#define ROM_TABLE_CID3_VALUE      0xB1U  /*!< CID3: Preamble byte 3 */

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Validate ROM table by checking Component ID
 * 通过检查组件ID验证ROM表
 * @return true if valid ROM table
 *
 * Checks CID0-CID3 for valid ROM table preamble values.
 * ROM table has Component Class 0x1 in CID1[7:4].
 *
 * Reference: D1.1 CoreSight infrastructure IDs (page D1-765)
 */
bool rom_table_validate(void);

/**
 * @brief Get component base address from ROM table entry
 * 从ROM表条目获取组件基地址
 * @param entry_offset ROM table entry offset
 * @return Component base address or 0 if not present
 *
 * Reference: B3.2.3 ROM table (page B3-600)
 */
uint32_t rom_table_get_component_base(uint32_t entry_offset);

/**
 * @brief Check if component is present in ROM table
 * 检查ROM表中组件是否存在
 * @param entry_offset ROM table entry offset
 * @return true if component is present
 *
 * Reference: B3.2.3 ROM table (page B3-600)
 */
static inline bool rom_table_component_present(uint32_t entry_offset) {
    return (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + entry_offset) & ROM_ENTRY_PRESENT_Msk) != 0U;
}

/**
 * @brief Get number of entries in ROM table
 * 获取ROM表条目数量
 * @return Number of valid entries before end marker
 *
 * Scans ROM table until end marker (0x00000000) is found.
 * Reference: Table C1-3 Armv7-M DAP accessible ROM table (page C1-686)
 */
uint32_t rom_table_get_entry_count(void);

/**
 * @brief Check if SCS is present
 * 检查SCS是否存在
 * @return true if SCS is present
 *
 * Reference: Table C1-3 Armv7-M DAP accessible ROM table (page C1-686)
 */
static inline bool rom_table_scs_present(void) {
    return rom_table_component_present(ROM_ENTRY_SCS_OFFSET);
}

/**
 * @brief Check if DWT is present
 * 检查DWT是否存在
 * @return true if DWT is present
 *
 * Reference: Table C1-3 Armv7-M DAP accessible ROM table (page C1-686)
 */
static inline bool rom_table_dwt_present(void) {
    return rom_table_component_present(ROM_ENTRY_DWT_OFFSET);
}

/**
 * @brief Check if FPB is present
 * 检查FPB是否存在
 * @return true if FPB is present
 *
 * Reference: Table C1-3 Armv7-M DAP accessible ROM table (page C1-686)
 */
static inline bool rom_table_fpb_present(void) {
    return rom_table_component_present(ROM_ENTRY_FPB_OFFSET);
}

/**
 * @brief Check if ITM is present
 * 检查ITM是否存在
 * @return true if ITM is present
 *
 * Reference: Table C1-3 Armv7-M DAP accessible ROM table (page C1-686)
 */
static inline bool rom_table_itm_present(void) {
    return rom_table_component_present(ROM_ENTRY_ITM_OFFSET);
}

/**
 * @brief Check if TPIU is present
 * 检查TPIU是否存在
 * @return true if TPIU is present
 *
 * Reference: Table C1-3 Armv7-M DAP accessible ROM table (page C1-686)
 */
static inline bool rom_table_tpiu_present(void) {
    return rom_table_component_present(ROM_ENTRY_TPIU_OFFSET);
}

/**
 * @brief Check if ETM is present
 * 检查ETM是否存在
 * @return true if ETM is present
 *
 * Reference: Table C1-3 Armv7-M DAP accessible ROM table (page C1-686)
 */
static inline bool rom_table_etm_present(void) {
    return rom_table_component_present(ROM_ENTRY_ETM_OFFSET);
}

/**
 * @brief Get SCS base address from ROM table
 * 从ROM表获取SCS基地址
 * @return SCS base address or 0 if not present
 *
 * Reference: Table C1-3 Armv7-M DAP accessible ROM table (page C1-686)
 */
static inline uint32_t rom_table_get_scs_base(void) {
    return rom_table_get_component_base(ROM_ENTRY_SCS_OFFSET);
}

/**
 * @brief Get DWT base address from ROM table
 * 从ROM表获取DWT基地址
 * @return DWT base address or 0 if not present
 *
 * Reference: Table C1-3 Armv7-M DAP accessible ROM table (page C1-686)
 */
static inline uint32_t rom_table_get_dwt_base(void) {
    return rom_table_get_component_base(ROM_ENTRY_DWT_OFFSET);
}

/**
 * @brief Get FPB base address from ROM table
 * 从ROM表获取FPB基地址
 * @return FPB base address or 0 if not present
 *
 * Reference: Table C1-3 Armv7-M DAP accessible ROM table (page C1-686)
 */
static inline uint32_t rom_table_get_fpb_base(void) {
    return rom_table_get_component_base(ROM_ENTRY_FPB_OFFSET);
}

/**
 * @brief Get ITM base address from ROM table
 * 从ROM表获取ITM基地址
 * @return ITM base address or 0 if not present
 *
 * Reference: Table C1-3 Armv7-M DAP accessible ROM table (page C1-686)
 */
static inline uint32_t rom_table_get_itm_base(void) {
    return rom_table_get_component_base(ROM_ENTRY_ITM_OFFSET);
}

/**
 * @brief Get TPIU base address from ROM table
 * 从ROM表获取TPIU基地址
 * @return TPIU base address or 0 if not present
 *
 * Reference: Table C1-3 Armv7-M DAP accessible ROM table (page C1-686)
 */
static inline uint32_t rom_table_get_tpiu_base(void) {
    return rom_table_get_component_base(ROM_ENTRY_TPIU_OFFSET);
}

/**
 * @brief Get ETM base address from ROM table
 * 从ROM表获取ETM基地址
 * @return ETM base address or 0 if not present
 *
 * Reference: Table C1-3 Armv7-M DAP accessible ROM table (page C1-686)
 */
static inline uint32_t rom_table_get_etm_base(void) {
    return rom_table_get_component_base(ROM_ENTRY_ETM_OFFSET);
}

/**
 * @brief Read ROM table Component ID registers
 * 读取ROM表组件ID寄存器
 * @param cid Pointer to store CID values (4 elements)
 *
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 */
void rom_table_read_cid(uint8_t *cid);

/**
 * @brief Read ROM table Peripheral ID registers
 * 读取ROM表外围设备ID寄存器
 * @param pid Pointer to store PID values (8 elements for PID0-PID7)
 *
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 */
void rom_table_read_pid(uint8_t *pid);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_ROM_TABLE_H__ */
