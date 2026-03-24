/*
 * ARM Architecture - ARMv7-M MTB (Micro Trace Buffer) Implementation
 *
 * ============================================================================
 * File: armv7-m_mtb.c
 * Description: ARMv7-M MTB function implementations
 * 描述: ARMv7-M MTB 函数实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Appendix D1: Armv7-M CoreSight Infrastructure IDs (page D1-765)
 *     * D1.1 CoreSight infrastructure IDs for an Armv7-M implementation
 *       - MTB is an optional CoreSight debug component
 *       - Component ID registers at offsets 0xFF0-0xFFF
 *       - CID0=0x0D, CID1=0x90 (Class=0x9 Debug), CID2=0x05, CID3=0xB1
 *     * Table D1-1: Component and Peripheral ID register formats (page D1-766)
 *       - Component Class 0x9 = Debug component
 *
 *   - MTB is described in separate MTB technical reference manual
 *     * MTB provides on-chip trace buffer for instruction trace
 *     * Stores branch trace packets in system RAM
 *     * MTB_MASTER.MASK field determines buffer size: 2^(MASK+4) bytes
 *     * MTB_BASE register points to trace buffer in system memory
 *
 * MTB provides a low-cost alternative to ETM for instruction tracing.
 * Unlike ETM which outputs trace via external pins (TPIU), MTB stores
 * trace packets in a circular buffer located in system RAM.
 *
 * MTB Base Address: 0xE0043000 (implementation defined)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_mtb.h"

/*
 * ============================================================================
 * MTB Component ID Values
 * MTB 组件ID值
 * Reference: D1.1 CoreSight infrastructure IDs (page D1-765)
 *            Table D1-1 Component and Peripheral ID register formats (page D1-766)
 * ============================================================================
 */

/**
 * @brief Initialize MTB
 * 初始化MTB
 * @param base_addr Base address of trace buffer in system memory
 * @param buffer_size Size of trace buffer in bytes (must be power of 2, min 16 bytes)
 *
 * Configures MTB with trace buffer location and size:
 * 1. Sets MTB_BASE to the buffer base address in system memory
 * 2. Calculates appropriate mask value for buffer size
 *    - Buffer size = 2^(MASK+4) bytes
 *    - MASK = log2(buffer_size) - 4
 * 3. Configures MTB_MASTER with calculated mask
 *
 * The buffer must be aligned to its size boundary and located in
 * writable system memory. Minimum buffer size is 16 bytes.
 *
 * Reference: MTB Technical Reference Manual
 */
void mtb_init(uint32_t base_addr, uint32_t buffer_size)
{
    /* Set trace buffer base address in system memory */
    MTB_BASE = base_addr;

    /*
     * Calculate mask value for buffer size.
     * Buffer size = 2^(MASK+4) bytes
     * So MASK = log2(buffer_size) - 4
     *
     * Examples:
     * - buffer_size = 16 bytes (2^4), MASK = 0
     * - buffer_size = 32 bytes (2^5), MASK = 1
     * - buffer_size = 64 bytes (2^6), MASK = 2
     * - buffer_size = 2KB (2^11), MASK = 7
     */
    uint32_t mask = 0;
    while ((1U << (mask + 4)) < buffer_size && mask < 0x1F) {
        mask++;
    }

    /* Configure MTB_MASTER with calculated mask (MTB disabled by default) */
    MTB_MASTER = (mask & MTB_MASTER_MASK_Msk);
}

/**
 * @brief Enable MTB
 * 使能MTB
 *
 * Sets MTB_MASTER.EN to enable trace packet generation.
 * When enabled, MTB starts writing branch trace packets to the
 * configured buffer in system memory.
 *
 * MTB records branch packets containing:
 * - Source address of the branch
 * - Destination address of the branch
 * - Type of branch (taken/not taken, exception, etc.)
 *
 * Reference: MTB Technical Reference Manual
 */
void mtb_enable(void)
{
    MTB_MASTER |= MTB_MASTER_EN_Msk;
}

/**
 * @brief Disable MTB
 * 禁用MTB
 *
 * Clears MTB_MASTER.EN to disable trace packet generation.
 * When disabled, MTB stops writing trace packets but maintains
 * current configuration and buffer contents.
 *
 * Reference: MTB Technical Reference Manual
 */
void mtb_disable(void)
{
    MTB_MASTER &= ~MTB_MASTER_EN_Msk;
}

/**
 * @brief Check if MTB is present
 * 检查MTB是否存在
 * @return true if MTB is implemented and accessible
 *
 * Validates MTB by checking Component ID registers:
 * - CID0 should be 0x0D (preamble byte 0)
 * - CID1 should be 0x90 (Component Class 0x9 = Debug component, preamble 0x0)
 * - CID2 should be 0x05 (preamble byte 2)
 * - CID3 should be 0xB1 (preamble byte 3)
 *
 * Component Class 0x9 indicates a debug component per CoreSight specification.
 *
 * Reference: D1.1 CoreSight infrastructure IDs (page D1-765)
 *            Table D1-1 Component and Peripheral ID register formats (page D1-766)
 */
bool mtb_is_present(void)
{
    uint32_t cidr0 = MTB_CIDR0;
    uint32_t cidr1 = MTB_CIDR1;
    uint32_t cidr2 = MTB_CIDR2;
    uint32_t cidr3 = MTB_CIDR3;

    /* Check CID0 preamble: should be 0x0D */
    if ((cidr0 & 0xFF) != MTB_CID0_VALUE) {
        return false;
    }

    /* Check CID1: Class=0x9 (Debug component), Preamble=0x0 */
    if ((cidr1 & 0xFF) != MTB_CID1_VALUE) {
        return false;
    }

    /* Check CID2 preamble: should be 0x05 */
    if ((cidr2 & 0xFF) != MTB_CID2_VALUE) {
        return false;
    }

    /* Check CID3 preamble: should be 0xB1 */
    if ((cidr3 & 0xFF) != MTB_CID3_VALUE) {
        return false;
    }

    return true;
}
