/*
 * ARM Architecture - Cortex-M4 Memory Model
 *
 * ============================================================================
 * File: cm4_memory.h
 * Description: Cortex-M4 memory model definitions
 * 描述: Cortex-M4 内存模型定义
 *
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide (DUI 0553B)
 *   - Chapter 2.2 Memory model (page 2-10)
 *   - Table 2-11 Memory access behavior (page 2-14)
 *   - Chapter 2.2.1 Memory regions, types and attributes (page 2-12)
 *   - Chapter 2.2.2 Memory system ordering of memory accesses (page 2-13)
 *   - Chapter 2.2.3 Behavior of memory accesses (page 2-14)
 *   - Chapter 2.2.4 Software ordering of memory accesses (page 2-15)
 *   - Chapter 2.2.5 Optional bit-banding (page 2-16)
 *   - Table 2-13 SRAM memory bit-banding regions (page 2-16)
 *   - Table 2-14 Peripheral memory bit-banding regions (page 2-16)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_CM4_MEMORY_H__
#define __ARCH_ARM_CM4_MEMORY_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * Memory Map
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Table 2-11 (page 2-14)
 * ============================================================================
 */

/* Code region (512MB) - Executable, Normal memory
 * Reference: Table 2-11 (page 2-14), Address range 0x00000000-0x1FFFFFFF
 */
#define CM4_MEMORY_CODE_BASE              0x00000000UL
#define CM4_MEMORY_CODE_SIZE              0x20000000UL
#define CM4_MEMORY_CODE_END               (CM4_MEMORY_CODE_BASE + CM4_MEMORY_CODE_SIZE - 1)

/* SRAM region (512MB) - Executable, Normal memory
 * Reference: Table 2-11 (page 2-14), Address range 0x20000000-0x3FFFFFFF
 */
#define CM4_MEMORY_SRAM_BASE              0x20000000UL
#define CM4_MEMORY_SRAM_SIZE              0x20000000UL
#define CM4_MEMORY_SRAM_END               (CM4_MEMORY_SRAM_BASE + CM4_MEMORY_SRAM_SIZE - 1)

/* Peripheral region (512MB) - Non-executable, Device memory
 * Reference: Table 2-11 (page 2-14), Address range 0x40000000-0x5FFFFFFF
 */
#define CM4_MEMORY_PERIPHERAL_BASE        0x40000000UL
#define CM4_MEMORY_PERIPHERAL_SIZE        0x20000000UL
#define CM4_MEMORY_PERIPHERAL_END         (CM4_MEMORY_PERIPHERAL_BASE + CM4_MEMORY_PERIPHERAL_SIZE - 1)

/* External RAM region (1GB) - Executable, Normal memory
 * Reference: Table 2-11 (page 2-14), Address range 0x60000000-0x9FFFFFFF
 */
#define CM4_MEMORY_EXTERNAL_RAM_BASE      0x60000000UL
#define CM4_MEMORY_EXTERNAL_RAM_SIZE      0x40000000UL
#define CM4_MEMORY_EXTERNAL_RAM_END       (CM4_MEMORY_EXTERNAL_RAM_BASE + CM4_MEMORY_EXTERNAL_RAM_SIZE - 1)

/* External Device region (1GB) - Non-executable, Device memory
 * Reference: Table 2-11 (page 2-14), Address range 0xA0000000-0xDFFFFFFF
 */
#define CM4_MEMORY_EXTERNAL_DEVICE_BASE   0xA0000000UL
#define CM4_MEMORY_EXTERNAL_DEVICE_SIZE   0x40000000UL
#define CM4_MEMORY_EXTERNAL_DEVICE_END    (CM4_MEMORY_EXTERNAL_DEVICE_BASE + CM4_MEMORY_EXTERNAL_DEVICE_SIZE - 1)

/* Private Peripheral Bus (1MB) - Non-executable, Strongly-ordered memory
 * Reference: Table 2-11 (page 2-14), Address range 0xE0000000-0xE00FFFFF
 */
#define CM4_MEMORY_PPB_BASE               0xE0000000UL
#define CM4_MEMORY_PPB_SIZE               0x00100000UL
#define CM4_MEMORY_PPB_END                (CM4_MEMORY_PPB_BASE + CM4_MEMORY_PPB_SIZE - 1)

/* Vendor-specific region (511MB)
 * Reference: Table 2-11 (page 2-14), Address range 0xE0100000-0xFFFFFFFF
 */
#define CM4_MEMORY_VENDOR_BASE            0xE0100000UL
#define CM4_MEMORY_VENDOR_SIZE            0x1FF00000UL
#define CM4_MEMORY_VENDOR_END             (CM4_MEMORY_VENDOR_BASE + CM4_MEMORY_VENDOR_SIZE - 1)

/*
 * ============================================================================
 * Bit-banding Regions
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.5 (page 2-16)
 * ============================================================================
 */

/* SRAM Bit-band region (1MB)
 * Reference: Table 2-13 (page 2-16), Address range 0x20000000-0x200FFFFF
 */
#define CM4_SRAM_BITBAND_BASE             0x20000000UL
#define CM4_SRAM_BITBAND_SIZE             0x00100000UL

/* SRAM Bit-band alias region (32MB)
 * Reference: Table 2-13 (page 2-16), Address range 0x22000000-0x23FFFFFF
 */
#define CM4_SRAM_BITBAND_ALIAS_BASE       0x22000000UL
#define CM4_SRAM_BITBAND_ALIAS_SIZE       0x02000000UL

/* Peripheral Bit-band region (1MB)
 * Reference: Table 2-14 (page 2-16), Address range 0x40000000-0x400FFFFF
 */
#define CM4_PERIPHERAL_BITBAND_BASE       0x40000000UL
#define CM4_PERIPHERAL_BITBAND_SIZE       0x00100000UL

/* Peripheral Bit-band alias region (32MB)
 * Reference: Table 2-14 (page 2-16), Address range 0x42000000-0x43FFFFFF
 */
#define CM4_PERIPHERAL_BITBAND_ALIAS_BASE 0x42000000UL
#define CM4_PERIPHERAL_BITBAND_ALIAS_SIZE 0x02000000UL

/*
 * ============================================================================
 * Bit-banding Calculation
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.5 (page 2-16)
 *
 * Formula from page 2-16:
 * bit_word_offset = (byte_offset x 32) + (bit_number x 4)
 * bit_word_addr = bit_band_base + bit_word_offset
 * ============================================================================
 */

/**
 * @brief Calculate bit-band alias address for SRAM
 * @param addr Byte address in SRAM bit-band region (0x20000000-0x200FFFFF)
 * @param bit Bit number (0-7)
 * @return Bit-band alias address
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.5 (page 2-16)
 */
static inline uint32_t cm4_sram_bitband_addr(uint32_t addr, uint32_t bit)
{
    return (CM4_SRAM_BITBAND_ALIAS_BASE + ((addr - CM4_SRAM_BITBAND_BASE) * 32) + (bit * 4));
}

/**
 * @brief Calculate bit-band alias address for Peripheral
 * @param addr Byte address in Peripheral bit-band region (0x40000000-0x400FFFFF)
 * @param bit Bit number (0-7)
 * @return Bit-band alias address
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.5 (page 2-16)
 */
static inline uint32_t cm4_peripheral_bitband_addr(uint32_t addr, uint32_t bit)
{
    return (CM4_PERIPHERAL_BITBAND_ALIAS_BASE + ((addr - CM4_PERIPHERAL_BITBAND_BASE) * 32) + (bit * 4));
}

/**
 * @brief Set a bit using bit-band access (SRAM)
 * @param addr Byte address in SRAM bit-band region
 * @param bit Bit number (0-7)
 * @param value Value to write (0 or 1)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.5 (page 2-16)
 * Note: Bit[0] of the value written determines the value written to the targeted bit
 */
static inline void cm4_sram_bitband_write(uint32_t addr, uint32_t bit, uint32_t value)
{
    volatile uint32_t *bitband = (volatile uint32_t *)cm4_sram_bitband_addr(addr, bit);
    *bitband = (value & 0x1);
}

/**
 * @brief Read a bit using bit-band access (SRAM)
 * @param addr Byte address in SRAM bit-band region
 * @param bit Bit number (0-7)
 * @return Bit value (0 or 1)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.5 (page 2-16)
 * Note: Reading returns 0x00000000 or 0x00000001
 */
static inline uint32_t cm4_sram_bitband_read(uint32_t addr, uint32_t bit)
{
    volatile uint32_t *bitband = (volatile uint32_t *)cm4_sram_bitband_addr(addr, bit);
    return *bitband;
}

/**
 * @brief Set a bit using bit-band access (Peripheral)
 * @param addr Byte address in Peripheral bit-band region
 * @param bit Bit number (0-7)
 * @param value Value to write (0 or 1)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.5 (page 2-16)
 */
static inline void cm4_peripheral_bitband_write(uint32_t addr, uint32_t bit, uint32_t value)
{
    volatile uint32_t *bitband = (volatile uint32_t *)cm4_peripheral_bitband_addr(addr, bit);
    *bitband = (value & 0x1);
}

/**
 * @brief Read a bit using bit-band access (Peripheral)
 * @param addr Byte address in Peripheral bit-band region
 * @param bit Bit number (0-7)
 * @return Bit value (0 or 1)
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.5 (page 2-16)
 */
static inline uint32_t cm4_peripheral_bitband_read(uint32_t addr, uint32_t bit)
{
    volatile uint32_t *bitband = (volatile uint32_t *)cm4_peripheral_bitband_addr(addr, bit);
    return *bitband;
}

/*
 * ============================================================================
 * Memory Barrier Instructions
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.4 (page 2-15)
 * ============================================================================
 */

/**
 * @brief Data Memory Barrier
 * Ensures that outstanding memory transactions complete before subsequent
 * memory transactions.
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.4 (page 2-15)
 */
static inline void cm4_dmb(void)
{
    __asm__ volatile ("DMB" ::: "memory");
}

/**
 * @brief Data Synchronization Barrier
 * Ensures that outstanding memory transactions complete before subsequent
 * instructions execute.
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.4 (page 2-15)
 */
static inline void cm4_dsb(void)
{
    __asm__ volatile ("DSB" ::: "memory");
}

/**
 * @brief Instruction Synchronization Barrier
 * Ensures that the effect of all completed memory transactions is recognizable
 * by subsequent instructions.
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.4 (page 2-15)
 */
static inline void cm4_isb(void)
{
    __asm__ volatile ("ISB" ::: "memory");
}

/*
 * ============================================================================
 * Memory Type Definitions
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.1 (page 2-12)
 * ============================================================================
 */

/* Memory types - Reference: Chapter 2.2.1 (page 2-12) */
#define CM4_MEMORY_TYPE_NORMAL            0U
#define CM4_MEMORY_TYPE_DEVICE            1U
#define CM4_MEMORY_TYPE_STRONGLY_ORDERED  2U

/* Memory attributes */
#define CM4_MEMORY_ATTR_NON_CACHEABLE     0U
#define CM4_MEMORY_ATTR_WRITE_THROUGH     1U
#define CM4_MEMORY_ATTR_WRITE_BACK        2U

/* Shareability - Reference: Chapter 2.2.1 (page 2-12) */
#define CM4_MEMORY_NON_SHAREABLE          0U
#define CM4_MEMORY_SHAREABLE              1U

/* Execute Never (XN) - Reference: Chapter 2.2.1 (page 2-12) */
#define CM4_MEMORY_EXECUTE_NEVER          0U
#define CM4_MEMORY_EXECUTE_OK             1U

/*
 * ============================================================================
 * Memory Access Functions
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.2.3 (page 2-14)
 * ============================================================================
 */

/**
 * @brief Read 8-bit value from memory
 * @param addr Memory address
 * @return 8-bit value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.5 (page 2-10)
 */
static inline uint8_t cm4_read8(uint32_t addr)
{
    return *((volatile uint8_t *)addr);
}

/**
 * @brief Read 16-bit value from memory
 * @param addr Memory address
 * @return 16-bit value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.5 (page 2-10)
 */
static inline uint16_t cm4_read16(uint32_t addr)
{
    return *((volatile uint16_t *)addr);
}

/**
 * @brief Read 32-bit value from memory
 * @param addr Memory address
 * @return 32-bit value
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.5 (page 2-10)
 */
static inline uint32_t cm4_read32(uint32_t addr)
{
    return *((volatile uint32_t *)addr);
}

/**
 * @brief Write 8-bit value to memory
 * @param addr Memory address
 * @param value Value to write
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.5 (page 2-10)
 */
static inline void cm4_write8(uint32_t addr, uint8_t value)
{
    *((volatile uint8_t *)addr) = value;
}

/**
 * @brief Write 16-bit value to memory
 * @param addr Memory address
 * @param value Value to write
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.5 (page 2-10)
 */
static inline void cm4_write16(uint32_t addr, uint16_t value)
{
    *((volatile uint16_t *)addr) = value;
}

/**
 * @brief Write 32-bit value to memory
 * @param addr Memory address
 * @param value Value to write
 * Reference: Arm(R) Cortex-M4 Devices Generic User Guide, Chapter 2.1.5 (page 2-10)
 */
static inline void cm4_write32(uint32_t addr, uint32_t value)
{
    *((volatile uint32_t *)addr) = value;
}

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_CM4_MEMORY_H__ */
