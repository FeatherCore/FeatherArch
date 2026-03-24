/*
 * ARM Architecture - ARMv7-M ETM (Embedded Trace Macrocell)
 *
 * ============================================================================
 * File: armv7-m_etm.h
 * Description: ARMv7-M ETMv3 register definitions and function declarations
 * 描述: ARMv7-M ETMv3 寄存器定义和函数声明
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter C1.9: Embedded Trace Macrocell support (page C1-749)
 *     * ETM architecture version (ETMv3 for Armv7-M)
 *     * ETM as optional debug component
 *     * Instruction trace generation
 *   - Chapter C1.10: Trace Port Interface Unit (page C1-750)
 *     * TPIU as companion to ETM for external trace output
 *     * TPIU registers for trace port configuration
 *   - Appendix D1: Armv7-M CoreSight Infrastructure IDs (page D1-765)
 *     * D1.1 CoreSight infrastructure IDs
 *       - ETM base address: 0xE0041000
 *       - Component ID registers at offsets 0xFF0-0xFFF
 *       - CID0=0x0D, CID1=0x90 (Class=0x9 Debug), CID2=0x05, CID3=0xB1
 *     * Table D1-1: Component and Peripheral ID register formats (page D1-766)
 *       - Component Class 0x9 = Debug component
 *
 * ETM Base Address: 0xE0041000
 * ETM is an optional component for instruction tracing in Armv7-M.
 * When implemented, ETM provides real-time instruction trace generation.
 *
 * CoreSight Component Address Map (Table C1-1, page C1-683):
 *   - ETM:  0xE0041000-0xE0041FFF (Embedded Trace Macrocell)
 *   - TPIU: 0xE0040000-0xE0040FFF (Trace Port Interface Unit)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_ETM_H__
#define __ARCH_ARM_V7M_ETM_H__

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * ETM Base Address
 * ETM 基地址
 * Reference: Table C1-1 PPB debug related regions (page C1-683)
 * ============================================================================
 */

#define ETM_BASE_ADDR             0xE0041000UL  /*!< ETM base address */

/*
 * ============================================================================
 * ETM Register Definitions
 * ETM 寄存器定义
 * Reference: C1.9 Embedded Trace Macrocell support (page C1-749)
 *            ETM Architecture Specification (ETMv3)
 * ============================================================================
 */

/**
 * ETM Control Register (ETM_CR)
 * Address: 0xE0041000
 * Reference: ETM Architecture Specification, ETM Control Register
 *
 * Purpose: Main control register for ETM operation.
 */
#define ETM_CR                    (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x000))

/**
 * ETM Configuration Code Register (ETM_CCR)
 * Address: 0xE0041004
 * Reference: ETM Architecture Specification, Configuration Code Register
 *
 * Purpose: Indicates ETM configuration and capabilities.
 */
#define ETM_CCR                   (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x004))

/**
 * ETM Trigger Event Register (ETM_TRIGGER)
 * Address: 0xE0041008
 * Reference: ETM Architecture Specification, Trigger Event Register
 *
 * Purpose: Defines the trigger event for the ETM.
 */
#define ETM_TRIGGER               (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x008))

/**
 * ETM Status Register (ETM_SR)
 * Address: 0xE0041010
 * Reference: ETM Architecture Specification, Status Register
 *
 * Purpose: Provides ETM status information.
 */
#define ETM_SR                    (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x010))

/**
 * ETM System Configuration Register (ETM_SCR)
 * Address: 0xE0041014
 * Reference: ETM Architecture Specification, System Configuration Register
 *
 * Purpose: Configures system-specific ETM features.
 */
#define ETM_SCR                   (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x014))

/**
 * ETM TraceEnable Start/Stop Control Register (ETM_TSSCR)
 * Address: 0xE0041018
 * Reference: ETM Architecture Specification, TraceEnable Start/Stop Control Register
 *
 * Purpose: Controls trace enable start/stop events.
 */
#define ETM_TSSCR                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x018))

/**
 * ETM TraceEnable Event Register (ETM_TEEVR)
 * Address: 0xE0041020
 * Reference: ETM Architecture Specification, TraceEnable Event Register
 *
 * Purpose: Defines the trace enable event.
 */
#define ETM_TEEVR                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x020))

/**
 * ETM TraceEnable Control 1 Register (ETM_TECR1)
 * Address: 0xE0041024
 * Reference: ETM Architecture Specification, TraceEnable Control 1 Register
 *
 * Purpose: Controls trace enable functionality.
 */
#define ETM_TECR1                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x024))

/**
 * ETM TraceEnable Control 2 Register (ETM_TECR2)
 * Address: 0xE0041028
 * Reference: ETM Architecture Specification, TraceEnable Control 2 Register
 *
 * Purpose: Additional trace enable controls.
 */
#define ETM_TECR2                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x028))

/**
 * ETM ID Register 2 (ETM_IDR2)
 * Address: 0xE004102C
 * Reference: ETM Architecture Specification, ID Register 2
 *
 * Purpose: Provides ETM implementation identification.
 */
#define ETM_IDR2                  (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x02C))

/**
 * ETM ID Register (ETM_IDR)
 * Address: 0xE00411E4
 * Reference: ETM Architecture Specification, ID Register
 *
 * Purpose: Provides ETM architecture version and capabilities.
 */
#define ETM_IDR                   (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x1E4))

/*
 * ============================================================================
 * ETM Component ID Registers
 * ETM 组件ID寄存器
 * Reference: D1.1 CoreSight infrastructure IDs (page D1-765)
 *            Table D1-1 Component and Peripheral ID register formats (page D1-766)
 * ============================================================================
 */

#define ETM_CIDR0                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFF0))  /*!< Component ID0 */
#define ETM_CIDR1                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFF4))  /*!< Component ID1 */
#define ETM_CIDR2                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFF8))  /*!< Component ID2 */
#define ETM_CIDR3                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFFC))  /*!< Component ID3 */

/* ETM Component ID values (Component Class 0x9 = Debug component) */
#define ETM_CID0_VALUE            0x0DU  /*!< CID0: Preamble byte 0 */
#define ETM_CID1_VALUE            0x90U  /*!< CID1: Class=0x9 (Debug), Preamble=0x0 */
#define ETM_CID2_VALUE            0x05U  /*!< CID2: Preamble byte 2 */
#define ETM_CID3_VALUE            0xB1U  /*!< CID3: Preamble byte 3 */

/*
 * ============================================================================
 * ETM Control Register (ETM_CR) Bit Definitions
 * ETM 控制寄存器位定义
 * Reference: ETM Architecture Specification, ETM Control Register
 * ============================================================================
 */

#define ETM_CR_ETMEN_Pos          0U
#define ETM_CR_ETMEN_Msk          (1UL << ETM_CR_ETMEN_Pos)           /*!< ETM enable */
#define ETM_CR_POWERDOWN_Pos      0U
#define ETM_CR_POWERDOWN_Msk      (1UL << ETM_CR_POWERDOWN_Pos)       /*!< ETM power down (legacy) */
#define ETM_CR_STALL_Pos          7U
#define ETM_CR_STALL_Msk          (1UL << ETM_CR_STALL_Pos)           /*!< Stall processor on FIFO full */
#define ETM_CR_BRANCH_OUTPUT_Pos  8U
#define ETM_CR_BRANCH_OUTPUT_Msk  (1UL << ETM_CR_BRANCH_OUTPUT_Pos)   /*!< Branch output enable */
#define ETM_CR_DEBUGREQ_Pos       9U
#define ETM_CR_DEBUGREQ_Msk       (1UL << ETM_CR_DEBUGREQ_Pos)        /*!< Debug request control */

/*
 * ============================================================================
 * ETM Status Register (ETM_SR) Bit Definitions
 * ETM 状态寄存器位定义
 * Reference: ETM Architecture Specification, Status Register
 * ============================================================================
 */

#define ETM_SR_PMDEBUG_Pos        0U
#define ETM_SR_PMDEBUG_Msk        (1UL << ETM_SR_PMDEBUG_Pos)         /*!< Prohibit non-invasive debug */
#define ETM_SR_PMSTANDBY_Pos      1U
#define ETM_SR_PMSTANDBY_Msk      (1UL << ETM_SR_PMSTANDBY_Pos)       /*!< Power management standby */
#define ETM_SR_ETH_Pos            3U
#define ETM_SR_ETH_Msk            (1UL << ETM_SR_ETH_Pos)             /*!< ETM halted (FIFO full) */

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Initialize ETM
 * 初始化ETM
 *
 * Initializes ETM with default settings:
 * - Checks if ETM is present using Component ID
 * - Disables ETM
 * - Waits for power management standby to clear
 * - Clears control and configuration registers
 *
 * Reference: C1.9 Embedded Trace Macrocell support (page C1-749)
 */
void etm_init(void);

/**
 * @brief Enable ETM
 * 使能ETM
 *
 * Sets ETM_CR.ETMEN to enable instruction tracing.
 *
 * Reference: ETM Architecture Specification, ETM Control Register
 */
void etm_enable(void);

/**
 * @brief Disable ETM
 * 禁用ETM
 *
 * Clears ETM_CR.ETMEN to disable instruction tracing.
 *
 * Reference: ETM Architecture Specification, ETM Control Register
 */
void etm_disable(void);

/**
 * @brief Check if ETM is present
 * 检查ETM是否存在
 * @return true if ETM is implemented and accessible
 *
 * Validates ETM by checking Component ID registers:
 * - CID0 should be 0x0D
 * - CID1 should be 0x90 (Component Class 0x9 = Debug component)
 * - CID2 should be 0x05
 * - CID3 should be 0xB1
 *
 * Reference: D1.1 CoreSight infrastructure IDs (page D1-765)
 *            Table D1-1 Component and Peripheral ID register formats (page D1-766)
 */
bool etm_is_present(void);

/**
 * @brief Check if ETM is enabled
 * 检查ETM是否使能
 * @return true if ETM_CR.ETMEN is set
 *
 * Reference: ETM Architecture Specification, ETM Control Register
 */
bool etm_is_enabled(void);

/**
 * @brief Generate software trigger
 * 生成软件触发
 *
 * Writes to ETM_TRIGGER to generate a software trigger event.
 *
 * Reference: ETM Architecture Specification, Trigger Event Register
 */
void etm_software_trigger(void);

/**
 * @brief Check if ETM is halted (FIFO full)
 * 检查ETM是否停止(FIFO满)
 * @return true if ETM_SR.ETH is set
 *
 * Reference: ETM Architecture Specification, Status Register
 */
static inline bool etm_is_halted(void) {
    return (ETM_SR & ETM_SR_ETH_Msk) != 0U;
}

/**
 * @brief Check if ETM is in standby mode
 * 检查ETM是否处于待机模式
 * @return true if ETM_SR.PMSTANDBY is set
 *
 * Reference: ETM Architecture Specification, Status Register
 */
static inline bool etm_is_standby(void) {
    return (ETM_SR & ETM_SR_PMSTANDBY_Msk) != 0U;
}

/**
 * @brief Wait for ETM to exit standby mode
 * 等待ETM退出待机模式
 *
 * Polls ETM_SR.PMSTANDBY until cleared.
 *
 * Reference: ETM Architecture Specification, Status Register
 */
static inline void etm_wait_standby_clear(void) {
    while (ETM_SR & ETM_SR_PMSTANDBY_Msk) {
        __asm__ volatile ("nop");
    }
}

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_ETM_H__ */
