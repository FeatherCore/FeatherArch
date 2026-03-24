/*
 * ARM Architecture - ARMv7-M ROM Table
 *
 * ============================================================================
 * File: armv7-m_rom_table.h
 * Description: ARMv7-M ROM Table definitions for CoreSight component discovery
 * 描述: ARMv7-M ROM Table 定义，用于 CoreSight 组件发现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual
 *   - Chapter B3.2.3: ROM table
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

#define ROM_TABLE_BASE_ADDR       0xE00FF000UL

#define ROM_ENTRY0                (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0x000))
#define ROM_ENTRY1                (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0x004))
#define ROM_ENTRY2                (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0x008))
#define ROM_ENTRY3                (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0x00C))

#define ROM_MEMTYPE               (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFCC))
#define ROM_PIDR4                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFD0))
#define ROM_PIDR0                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFE0))
#define ROM_PIDR1                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFE4))
#define ROM_PIDR2                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFE8))
#define ROM_PIDR3                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFEC))
#define ROM_CIDR0                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFF0))
#define ROM_CIDR1                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFF4))
#define ROM_CIDR2                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFF8))
#define ROM_CIDR3                 (*(volatile uint32_t *)(ROM_TABLE_BASE_ADDR + 0xFFC))

#define ROM_ENTRY_PRESENT         0x1UL
#define ROM_ENTRY_ABSENT          0x0UL

bool rom_table_validate(void);
uint32_t rom_table_get_component_base(uint32_t entry_offset);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_ROM_TABLE_H__ */
