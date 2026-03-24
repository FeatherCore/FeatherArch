/*
 * ARM Architecture - ARMv8-M ROM Table
 *
 * ============================================================================
 * File: armv8-m_rom_table.h
 * Description: ARMv8-M ROM Table definitions for CoreSight component discovery
 * 描述: ARMv8-M ROM Table 定义，用于 CoreSight 组件发现
 *
 * The ROM table provides a mechanism to identify the debug infrastructure
 * supported by the implementation. It contains entries pointing to debug
 * components like ITM, DWT, FPB, ETM, TPIU, etc.
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B13.2.1: ROM table
 *   - Chapter D1.2: ROM Table Register Definitions
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V8M_ROM_TABLE_H__
#define __ARCH_ARM_V8M_ROM_TABLE_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv8-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * ROM Table Base Address
 * ROM Table 基地址
 * ============================================================================
 */

/**
 * ROM Table Base Address
 * ROM Table 基地址
 * Reference: Arm(R) v8-M ARM, B13.2.1
 */
#define ROM_TABLE_BASE_ADDR       0xE00FF000UL

/*
 * ============================================================================
 * ROM Table Entry Offsets
 * ROM Table 条目偏移
 * ============================================================================
 */

/**
 * ROM Table Entry Offsets
 * ROM Table 条目偏移地址
 * Reference: Arm(R) v8-M ARM, B13.2.1
 */
#define ROM_TABLE_ENTRY0_OFFSET   0x000  /* SCS (System Control Space) */
#define ROM_TABLE_ENTRY1_OFFSET   0x004  /* DWT (Data Watchpoint and Trace) */
#define ROM_TABLE_ENTRY2_OFFSET   0x008  /* FPB (Flash Patch and Breakpoint) */
#define ROM_TABLE_ENTRY3_OFFSET   0x00C  /* ITM (Instrumentation Trace Macrocell) - if Main Extension */
#define ROM_TABLE_ENTRY4_OFFSET   0x010  /* TPIU (Trace Port Interface Unit) */
#define ROM_TABLE_ENTRY5_OFFSET   0x014  /* ETM (Embedded Trace Macrocell) */
#define ROM_TABLE_ENTRY6_OFFSET   0x018  /* Reserved */
#define ROM_TABLE_ENTRY7_OFFSET   0x01C  /* End of Table Marker */

/*
 * ============================================================================
 * ROM Table Register Definitions
 * ROM Table 寄存器定义
 * ============================================================================
 */

/**
 * ROM Table Entry n (ROM_ENTRYn)
 * ROM Table 条目 n
 * Reference: Arm(R) v8-M ARM, D1.2.65
 */
#define ROM_ENTRY0                (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + ROM_TABLE_ENTRY0_OFFSET))
#define ROM_ENTRY1                (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + ROM_TABLE_ENTRY1_OFFSET))
#define ROM_ENTRY2                (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + ROM_TABLE_ENTRY2_OFFSET))
#define ROM_ENTRY3                (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + ROM_TABLE_ENTRY3_OFFSET))
#define ROM_ENTRY4                (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + ROM_TABLE_ENTRY4_OFFSET))
#define ROM_ENTRY5                (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + ROM_TABLE_ENTRY5_OFFSET))
#define ROM_ENTRY6                (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + ROM_TABLE_ENTRY6_OFFSET))
#define ROM_ENTRY7                (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + ROM_TABLE_ENTRY7_OFFSET))

/**
 * ROM Table Memory Type Register (ROM_MEMTYPE)
 * ROM Table 内存类型寄存器
 * Reference: Arm(R) v8-M ARM, D1.2.66
 */
#define ROM_MEMTYPE               (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFCC))

/**
 * ROM Table Peripheral Identification Registers (ROM_PIDRn)
 * ROM Table 外设标识寄存器
 * Reference: Arm(R) v8-M ARM, D1.2.67 - D1.2.74
 */
#define ROM_PIDR4                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFD0))
#define ROM_PIDR5                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFD4))
#define ROM_PIDR6                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFD8))
#define ROM_PIDR7                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFDC))
#define ROM_PIDR0                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFE0))
#define ROM_PIDR1                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFE4))
#define ROM_PIDR2                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFE8))
#define ROM_PIDR3                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFEC))

/**
 * ROM Table Component Identification Registers (ROM_CIDRn)
 * ROM Table 组件标识寄存器
 * Reference: Arm(R) v8-M ARM, D1.2.48 - D1.2.51
 */
#define ROM_CIDR0                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFF0))
#define ROM_CIDR1                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFF4))
#define ROM_CIDR2                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFF8))
#define ROM_CIDR3                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFFC))

/*
 * ============================================================================
 * ROM Table Entry Bit Definitions
 * ROM Table 条目位定义
 * ============================================================================
 */

/**
 * ROM Entry Bit Definitions
 * ROM 条目位定义
 * Reference: Arm(R) v8-M ARM, B13.2.1
 */
#define ROM_ENTRY_PRESENT_Pos     0U
#define ROM_ENTRY_PRESENT_Msk     (0x3UL << ROM_ENTRY_PRESENT_Pos)
#define ROM_ENTRY_PRESENT         0x1UL  /* Component present */
#define ROM_ENTRY_ABSENT          0x0UL  /* Component absent */
#define ROM_ENTRY_END_MARKER      0x0UL  /* End of table marker */

#define ROM_ENTRY_OFFSET_Pos      12U
#define ROM_ENTRY_OFFSET_Msk      (0xFFFFF000UL << ROM_ENTRY_OFFSET_Pos)

/* ROM Entry Component Addresses (relative to ROM table base, negative offsets) */
#define ROM_ENTRY_SCS_OFFSET      0xFFF0F000  /* Points to SCS at 0xE000E000 */
#define ROM_ENTRY_DWT_OFFSET      0xFFF02000  /* Points to DWT at 0xE0001000 */
#define ROM_ENTRY_FPB_OFFSET      0xFFF03000  /* Points to FPB at 0xE0002000 */
#define ROM_ENTRY_ITM_OFFSET      0xFFF01000  /* Points to ITM at 0xE0000000 */
#define ROM_ENTRY_TPIU_OFFSET     0xFFF41000  /* Points to TPIU at 0xE0040000 */
#define ROM_ENTRY_ETM_OFFSET      0xFFF42000  /* Points to ETM at 0xE0041000 */

/*
 * ============================================================================
 * ROM Table Component Identification Values
 * ROM Table 组件标识值
 * ============================================================================
 */

/**
 * ROM Table Component ID Values (CoreSight compliant)
 * ROM Table 组件 ID 值 (CoreSight 兼容)
 */
#define ROM_CIDR0_VALUE           0x0DUL  /* Preamble byte 0 */
#define ROM_CIDR1_VALUE           0x10UL  /* Preamble byte 1, Class = 0x1 (ROM table) */
#define ROM_CIDR2_VALUE           0x05UL  /* Preamble byte 2 */
#define ROM_CIDR3_VALUE           0xB1UL  /* Preamble byte 3 */

/**
 * ROM Table Peripheral ID Values
 * ROM Table 外设 ID 值
 */
#define ROM_PIDR0_PART_NUM        0x00UL  /* Part number [7:0] */
#define ROM_PIDR1_PART_NUM        0x00UL  /* Part number [11:8] */
#define ROM_PIDR1_JEP106_ID       0x40UL  /* JEP106 identity code [3:0] */
#define ROM_PIDR2_JEP106_ID       0x0BUL  /* JEP106 identity code [6:4] */
#define ROM_PIDR2_REVISION        0x00UL  /* Revision */
#define ROM_PIDR3_CUSTOMER_MOD    0x00UL  /* Customer modified */
#define ROM_PIDR3_REV_AND         0x00UL  /* Customer modification number */
#define ROM_PIDR4_DESIGNER        0x04UL  /* 4KB count */
#define ROM_PIDR4_JEP106_CONT     0x00UL  /* JEP106 continuation code */

/*
 * ============================================================================
 * ROM Table Memory Type Register Bit Definitions
 * ROM Table 内存类型寄存器位定义
 * ============================================================================
 */

#define ROM_MEMTYPE_SYSMEM_Pos    0U
#define ROM_MEMTYPE_SYSMEM_Msk    (1UL << ROM_MEMTYPE_SYSMEM_Pos)
#define ROM_MEMTYPE_SYSMEM        (1UL << ROM_MEMTYPE_SYSMEM_Pos)  /* System memory present */

/*
 * ============================================================================
 * ROM Table Component IDs
 * ROM Table 组件 ID
 * ============================================================================
 */

typedef enum {
    ROM_COMP_SCS = 0,   /* System Control Space */
    ROM_COMP_DWT,       /* Data Watchpoint and Trace */
    ROM_COMP_FPB,       /* Flash Patch and Breakpoint */
    ROM_COMP_ITM,       /* Instrumentation Trace Macrocell */
    ROM_COMP_TPIU,      /* Trace Port Interface Unit */
    ROM_COMP_ETM,       /* Embedded Trace Macrocell */
    ROM_COMP_MTB,       /* Micro Trace Buffer */
    ROM_COMP_CTI,       /* Cross-trigger Interface */
    ROM_COMP_COUNT
} rom_component_t;

/*
 * ============================================================================
 * ROM Table Component Information Structure
 * ROM Table 组件信息结构
 * ============================================================================
 */

typedef struct {
    uint32_t entry_offset;      /* ROM table entry offset */
    uint32_t component_base;    /* Component base address */
    const char *name;           /* Component name */
    bool is_optional;           /* Whether component is optional */
} rom_component_info_t;

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Initialize ROM table access
 * 初始化 ROM Table 访问
 */
void rom_table_init(void);

/**
 * @brief Check if ROM table is present
 * 检查 ROM Table 是否存在
 * @return true if ROM table is present
 */
bool rom_table_is_present(void);

/**
 * @brief Get component base address from ROM table entry
 * 从 ROM Table 条目获取组件基地址
 * @param entry_offset ROM table entry offset
 * @return Component base address, 0 if not present
 */
uint32_t rom_table_get_component_base(uint32_t entry_offset);

/**
 * @brief Check if component is present
 * 检查组件是否存在
 * @param component Component identifier
 * @return true if component is present
 */
bool rom_table_component_is_present(rom_component_t component);

/**
 * @brief Get component base address
 * 获取组件基地址
 * @param component Component identifier
 * @return Component base address, 0 if not present
 */
uint32_t rom_table_get_component_address(rom_component_t component);

/**
 * @brief Validate ROM table (check CIDR values)
 * 验证 ROM Table (检查 CIDR 值)
 * @return true if ROM table is valid
 */
bool rom_table_validate(void);

/**
 * @brief Get ROM table peripheral ID
 * 获取 ROM Table 外设 ID
 * @return 64-bit peripheral ID
 */
uint64_t rom_table_get_peripheral_id(void);

/**
 * @brief Check if system memory is accessible through ROM table
 * 检查系统内存是否可通过 ROM Table 访问
 * @return true if system memory is accessible
 */
bool rom_table_system_memory_present(void);

/**
 * @brief Scan ROM table and print component information
 * 扫描 ROM Table 并打印组件信息
 * (Debug/development function)
 */
void rom_table_scan(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V8M_ROM_TABLE_H__ */
