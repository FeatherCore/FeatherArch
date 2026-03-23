/*
 * ARM Architecture - ARMv7-M Cache Operations
 *
 * ============================================================================
 * File: armv7-m_cache.c
 * Description: ARMv7-M cache maintenance operation implementations
 * 描述: ARMv7-M 缓存维护操作实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B3.2 - Cache maintenance operations
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_cache.h"
#include "armv7-m/armv7-m_nvic.h"

#if (__ICACHE_PRESENT == 1) || (__DCACHE_PRESENT == 1)

/*
 * ============================================================================
 * Instruction Cache Control
 * 指令缓存控制
 * ============================================================================
 */

#if (__ICACHE_PRESENT == 1)
void icache_enable(void)
{
    SCB_CCR |= SCB_CCR_IC;
    __asm__ volatile("dsb");
    __asm__ volatile("isb");
}

void icache_disable(void)
{
    SCB_CCR &= ~SCB_CCR_IC;
    __asm__ volatile("dsb");
    __asm__ volatile("isb");
}

void icache_invalidate_all(void)
{
    __IALLU();
    __asm__ volatile("dsb");
    __asm__ volatile("isb");
}
#endif

/*
 * ============================================================================
 * Data Cache Control
 * 数据缓存控制
 * ============================================================================
 */

#if (__DCACHE_PRESENT == 1)
void dcache_enable(void)
{
    SCB_CCR |= SCB_CCR_DC;
    __asm__ volatile("dsb");
    __asm__ volatile("isb");
}

void dcache_disable(void)
{
    dcache_clean_invalidate_all();
    SCB_CCR &= ~SCB_CCR_DC;
    __asm__ volatile("dsb");
    __asm__ volatile("isb");
}

void dcache_clean_all(void)
{
    uint32_t ccsidr;
    uint32_t sets;
    uint32_t ways;
    uint32_t set;
    uint32_t way;
    uint32_t ccr;
    uint32_t csselr;
    
    ccr = SCB_CCR;
    csselr = SCB_CSSELR;
    
    SCB_CSSELR = 0;
    ccsidr = SCB_CCSIDR;
    
    sets = ((ccsidr >> 13) & 0x7FFF) + 1;
    ways = ((ccsidr >> 3) & 0x3FF) + 1;
    
    for (way = 0; way < ways; way++) {
        for (set = 0; set < sets; set++) {
            uint32_t sw = (way << 30) | (set << 5);
            __DCCSW(sw);
        }
    }
    
    __asm__ volatile("dsb");
}

void dcache_invalidate_all(void)
{
    uint32_t ccsidr;
    uint32_t sets;
    uint32_t ways;
    uint32_t set;
    uint32_t way;
    
    SCB_CSSELR = 0;
    ccsidr = SCB_CCSIDR;
    
    sets = ((ccsidr >> 13) & 0x7FFF) + 1;
    ways = ((ccsidr >> 3) & 0x3FF) + 1;
    
    for (way = 0; way < ways; way++) {
        for (set = 0; set < sets; set++) {
            uint32_t sw = (way << 30) | (set << 5);
            __DCISW(sw);
        }
    }
    
    __asm__ volatile("dsb");
}

void dcache_clean_invalidate_all(void)
{
    uint32_t ccsidr;
    uint32_t sets;
    uint32_t ways;
    uint32_t set;
    uint32_t way;
    
    SCB_CSSELR = 0;
    ccsidr = SCB_CCSIDR;
    
    sets = ((ccsidr >> 13) & 0x7FFF) + 1;
    ways = ((ccsidr >> 3) & 0x3FF) + 1;
    
    for (way = 0; way < ways; way++) {
        for (set = 0; set < sets; set++) {
            uint32_t sw = (way << 30) | (set << 5);
            __DCCISW(sw);
        }
    }
    
    __asm__ volatile("dsb");
}

/*
 * ============================================================================
 * Data Cache Range Operations
 * 数据缓存范围操作
 * ============================================================================
 */

void dcache_clean_range(uint32_t addr, uint32_t size)
{
    uint32_t end_addr = addr + size;
    uint32_t ccsidr;
    uint32_t line_size;
    
    SCB_CSSELR = 0;
    ccsidr = SCB_CCSIDR;
    line_size = 4 << ((ccsidr & 0x7) + 2);
    
    addr &= ~(line_size - 1);
    
    while (addr < end_addr) {
        __DCCMVAC(addr);
        addr += line_size;
    }
    
    __asm__ volatile("dsb");
}

void dcache_invalidate_range(uint32_t addr, uint32_t size)
{
    uint32_t end_addr = addr + size;
    uint32_t ccsidr;
    uint32_t line_size;
    
    SCB_CSSELR = 0;
    ccsidr = SCB_CCSIDR;
    line_size = 4 << ((ccsidr & 0x7) + 2);
    
    addr &= ~(line_size - 1);
    
    while (addr < end_addr) {
        __DCIMVAC(addr);
        addr += line_size;
    }
    
    __asm__ volatile("dsb");
}

void dcache_clean_invalidate_range(uint32_t addr, uint32_t size)
{
    uint32_t end_addr = addr + size;
    uint32_t ccsidr;
    uint32_t line_size;
    
    SCB_CSSELR = 0;
    ccsidr = SCB_CCSIDR;
    line_size = 4 << ((ccsidr & 0x7) + 2);
    
    addr &= ~(line_size - 1);
    
    while (addr < end_addr) {
        __DCCIMVAC(addr);
        addr += line_size;
    }
    
    __asm__ volatile("dsb");
}
#endif

#endif /* (__ICACHE_PRESENT == 1) || (__DCACHE_PRESENT == 1) */
