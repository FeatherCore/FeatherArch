/*
 * ARM Architecture - ARMv7-M MTB (Micro Trace Buffer)
 *
 * ============================================================================
 * File: armv7-m_mtb.h
 * Description: ARMv7-M MTB register definitions and function declarations
 * 描述: ARMv7-M MTB 寄存器定义和函数声明
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
 *     * Alternative to ETM for systems without external trace port
 *     * Stores branch trace packets in system RAM
 *
 * MTB Base Address: 0xE0043000 (implementation defined, may vary)
 * MTB is an optional component for low-cost instruction tracing.
 * When implemented, MTB stores branch trace packets in a circular buffer
 * located in system memory.
 *
 * CoreSight Component Address Map:
 *   - MTB:  0xE0043000-0xE0043FFF (Micro Trace Buffer, optional)
 *
 * MTB vs ETM:
 *   - MTB: On-chip trace buffer, stores trace in system RAM
 *   - ETM: External trace output via TPIU
 *   - Both provide instruction trace but with different output methods
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_MTB_H__
#define __ARCH_ARM_V7M_MTB_H__

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * MTB Base Address
 * MTB 基地址
 * Note: MTB base address is implementation defined
 * Typical address: 0xE0043000
 * ============================================================================
 */

#define MTB_BASE_ADDR             0xE0043000UL  /*!< MTB base address (implementation defined) */

/*
 * ============================================================================
 * MTB Register Definitions
 * MTB 寄存器定义
 * Reference: MTB Technical Reference Manual
 * ============================================================================
 */

/**
 * MTB Position Register (MTB_POSITION)
 * Address: 0xE0043000
 * Reference: MTB Technical Reference Manual
 *
 * Purpose: Indicates the current write position in the trace buffer.
 * Automatically increments as trace packets are written.
 */
#define MTB_POSITION              (*(volatile uint32_t *)(MTB_BASE_ADDR + 0x000))

/**
 * MTB Master Register (MTB_MASTER)
 * Address: 0xE0043004
 * Reference: MTB Technical Reference Manual
 *
 * Purpose: Main control register for MTB operation.
 * Controls enable, halt request, wrap mode, and buffer size mask.
 */
#define MTB_MASTER                (*(volatile uint32_t *)(MTB_BASE_ADDR + 0x004))

/**
 * MTB Flow Register (MTB_FLOW)
 * Address: 0xE0043008
 * Reference: MTB Technical Reference Manual
 *
 * Purpose: Controls watermark level for automatic halt and watermark interrupt.
 */
#define MTB_FLOW                  (*(volatile uint32_t *)(MTB_BASE_ADDR + 0x008))

/**
 * MTB Base Register (MTB_BASE)
 * Address: 0xE004300C
 * Reference: MTB Technical Reference Manual
 *
 * Purpose: Holds the base address of the trace buffer in system memory.
 * Must be configured before enabling MTB.
 */
#define MTB_BASE                  (*(volatile uint32_t *)(MTB_BASE_ADDR + 0x00C))

/*
 * ============================================================================
 * MTB Component ID Registers
 * MTB 组件ID寄存器
 * Reference: D1.1 CoreSight infrastructure IDs (page D1-765)
 *            Table D1-1 Component and Peripheral ID register formats (page D1-766)
 * ============================================================================
 */

#define MTB_CIDR0                 (*(volatile uint32_t *)(MTB_BASE_ADDR + 0xFF0))  /*!< Component ID0 */
#define MTB_CIDR1                 (*(volatile uint32_t *)(MTB_BASE_ADDR + 0xFF4))  /*!< Component ID1 */
#define MTB_CIDR2                 (*(volatile uint32_t *)(MTB_BASE_ADDR + 0xFF8))  /*!< Component ID2 */
#define MTB_CIDR3                 (*(volatile uint32_t *)(MTB_BASE_ADDR + 0xFFC))  /*!< Component ID3 */

/* MTB Component ID values (Component Class 0x9 = Debug component) */
#define MTB_CID0_VALUE            0x0DU  /*!< CID0: Preamble byte 0 */
#define MTB_CID1_VALUE            0x90U  /*!< CID1: Class=0x9 (Debug), Preamble=0x0 */
#define MTB_CID2_VALUE            0x05U  /*!< CID2: Preamble byte 2 */
#define MTB_CID3_VALUE            0xB1U  /*!< CID3: Preamble byte 3 */

/*
 * ============================================================================
 * MTB Master Register (MTB_MASTER) Bit Definitions
 * MTB 主控寄存器位定义
 * Reference: MTB Technical Reference Manual
 * ============================================================================
 */

#define MTB_MASTER_EN_Pos         31U
#define MTB_MASTER_EN_Msk         (1UL << MTB_MASTER_EN_Pos)           /*!< MTB enable */
#define MTB_MASTER_HALTREQ_Pos    30U
#define MTB_MASTER_HALTREQ_Msk    (1UL << MTB_MASTER_HALTREQ_Pos)      /*!< Halt request on buffer full */
#define MTB_MASTER_WRAP_Pos       29U
#define MTB_MASTER_WRAP_Msk       (1UL << MTB_MASTER_WRAP_Pos)         /*!< Wrap mode enable */
#define MTB_MASTER_MASK_Pos       0U
#define MTB_MASTER_MASK_Msk       (0x1FUL << MTB_MASTER_MASK_Pos)      /*!< Buffer size mask (2^(MASK+4) bytes) */

/*
 * ============================================================================
 * MTB Position Register (MTB_POSITION) Bit Definitions
 * MTB 位置寄存器位定义
 * Reference: MTB Technical Reference Manual
 * ============================================================================
 */

#define MTB_POSITION_WRAP_Pos     29U
#define MTB_POSITION_WRAP_Msk     (1UL << MTB_POSITION_WRAP_Pos)       /*!< Wrap indicator */
#define MTB_POSITION_POINTER_Pos  3U
#define MTB_POSITION_POINTER_Msk  (0x1FFFFFFFUL << MTB_POSITION_POINTER_Pos)  /*!< Trace packet pointer */

/*
 * ============================================================================
 * MTB Flow Register (MTB_FLOW) Bit Definitions
 * MTB 流控寄存器位定义
 * Reference: MTB Technical Reference Manual
 * ============================================================================
 */

#define MTB_FLOW_WATERMARK_Pos    3U
#define MTB_FLOW_WATERMARK_Msk    (0x1FFFFFFFUL << MTB_FLOW_WATERMARK_Pos)  /*!< Watermark level */
#define MTB_FLOW_AUTOHALT_Pos     30U
#define MTB_FLOW_AUTOHALT_Msk     (1UL << MTB_FLOW_AUTOHALT_Pos)       /*!< Auto halt on watermark */
#define MTB_FLOW_WATERMARK_IRQ_Pos 31U
#define MTB_FLOW_WATERMARK_IRQ_Msk (1UL << MTB_FLOW_WATERMARK_IRQ_Pos) /*!< Watermark interrupt enable */

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Initialize MTB
 * 初始化MTB
 * @param base_addr Base address of trace buffer in system memory
 * @param buffer_size Size of trace buffer in bytes (must be power of 2, min 16 bytes)
 *
 * Configures MTB with trace buffer location and size.
 * Calculates appropriate mask value for buffer size.
 *
 * Reference: MTB Technical Reference Manual
 */
void mtb_init(uint32_t base_addr, uint32_t buffer_size);

/**
 * @brief Enable MTB
 * 使能MTB
 *
 * Sets MTB_MASTER.EN to enable trace packet generation.
 * MTB will start writing branch trace packets to the configured buffer.
 *
 * Reference: MTB Technical Reference Manual
 */
void mtb_enable(void);

/**
 * @brief Disable MTB
 * 禁用MTB
 *
 * Clears MTB_MASTER.EN to disable trace packet generation.
 *
 * Reference: MTB Technical Reference Manual
 */
void mtb_disable(void);

/**
 * @brief Check if MTB is present
 * 检查MTB是否存在
 * @return true if MTB is implemented and accessible
 *
 * Validates MTB by checking Component ID registers:
 * - CID0 should be 0x0D
 * - CID1 should be 0x90 (Component Class 0x9 = Debug component)
 * - CID2 should be 0x05
 * - CID3 should be 0xB1
 *
 * Reference: D1.1 CoreSight infrastructure IDs (page D1-765)
 *            Table D1-1 Component and Peripheral ID register formats (page D1-766)
 */
bool mtb_is_present(void);

/**
 * @brief Check if MTB is enabled
 * 检查MTB是否使能
 * @return true if MTB_MASTER.EN is set
 *
 * Reference: MTB Technical Reference Manual
 */
static inline bool mtb_is_enabled(void) {
    return (MTB_MASTER & MTB_MASTER_EN_Msk) != 0U;
}

/**
 * @brief Get current MTB position
 * 获取当前MTB位置
 * @return Current write position in trace buffer
 *
 * Returns the current write pointer value from MTB_POSITION.
 *
 * Reference: MTB Technical Reference Manual
 */
static inline uint32_t mtb_get_position(void) {
    return MTB_POSITION;
}

/**
 * @brief Check if MTB buffer has wrapped
 * 检查MTB缓冲区是否已回绕
 * @return true if buffer has wrapped at least once
 *
 * Checks MTB_POSITION.WRAP bit.
 *
 * Reference: MTB Technical Reference Manual
 */
static inline bool mtb_has_wrapped(void) {
    return (MTB_POSITION & MTB_POSITION_WRAP_Msk) != 0U;
}

/**
 * @brief Set MTB watermark level
 * 设置MTB水印级别
 * @param watermark Watermark level (byte offset in buffer)
 *
 * Configures the watermark level for auto-halt or interrupt generation.
 *
 * Reference: MTB Technical Reference Manual
 */
static inline void mtb_set_watermark(uint32_t watermark) {
    MTB_FLOW = (MTB_FLOW & ~MTB_FLOW_WATERMARK_Msk) |
               ((watermark << MTB_FLOW_WATERMARK_Pos) & MTB_FLOW_WATERMARK_Msk);
}

/**
 * @brief Enable MTB auto-halt on watermark
 * 使能MTB水印自动停止
 *
 * Sets MTB_FLOW.AUTOHALT to halt processor when watermark is reached.
 *
 * Reference: MTB Technical Reference Manual
 */
static inline void mtb_enable_autohalt(void) {
    MTB_FLOW |= MTB_FLOW_AUTOHALT_Msk;
}

/**
 * @brief Disable MTB auto-halt on watermark
 * 禁用MTB水印自动停止
 *
 * Reference: MTB Technical Reference Manual
 */
static inline void mtb_disable_autohalt(void) {
    MTB_FLOW &= ~MTB_FLOW_AUTOHALT_Msk;
}

/**
 * @brief Enable MTB wrap mode
 * 使能MTB回绕模式
 *
 * Sets MTB_MASTER.WRAP to enable circular buffer mode.
 * When enabled, MTB wraps to buffer start when full.
 *
 * Reference: MTB Technical Reference Manual
 */
static inline void mtb_enable_wrap(void) {
    MTB_MASTER |= MTB_MASTER_WRAP_Msk;
}

/**
 * @brief Disable MTB wrap mode
 * 禁用MTB回绕模式
 *
 * When disabled, MTB stops tracing when buffer is full.
 *
 * Reference: MTB Technical Reference Manual
 */
static inline void mtb_disable_wrap(void) {
    MTB_MASTER &= ~MTB_MASTER_WRAP_Msk;
}

/**
 * @brief Reset MTB position
 * 复位MTB位置
 *
 * Clears MTB_POSITION to reset write pointer to buffer start.
 *
 * Reference: MTB Technical Reference Manual
 */
static inline void mtb_reset_position(void) {
    MTB_POSITION = 0;
}

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_MTB_H__ */
