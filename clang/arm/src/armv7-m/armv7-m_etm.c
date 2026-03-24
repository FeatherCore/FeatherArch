/*
 * ARM Architecture - ARMv7-M ETM (Embedded Trace Macrocell) Implementation
 *
 * ============================================================================
 * File: armv7-m_etm.c
 * Description: ARMv7-M ETMv3 function implementations
 * 描述: ARMv7-M ETMv3 函数实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter C1.9: Embedded Trace Macrocell support (page C1-749)
 *     * ETM as optional debug component for instruction tracing
 *     * ETMv3 architecture for Armv7-M profile
 *     * Real-time instruction trace generation
 *   - Appendix D1: Armv7-M CoreSight Infrastructure IDs (page D1-765)
 *     * D1.1 CoreSight infrastructure IDs
 *       - ETM Component ID validation using CID0-CID3
 *       - CID0=0x0D, CID1=0x90 (Class=0x9 Debug), CID2=0x05, CID3=0xB1
 *     * Table D1-1: Component and Peripheral ID register formats (page D1-766)
 *       - Component Class 0x9 = Debug component
 *
 * ETM provides real-time instruction trace generation for debugging.
 * It is an optional component in Armv7-M implementations.
 *
 * ETM Base Address: 0xE0041000
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_etm.h"

/*
 * ============================================================================
 * ETM Component ID Values
 * ETM 组件ID值
 * Reference: D1.1 CoreSight infrastructure IDs (page D1-765)
 *            Table D1-1 Component and Peripheral ID register formats (page D1-766)
 * ============================================================================
 */

/**
 * @brief Initialize ETM
 * 初始化ETM
 *
 * Initializes ETM with default settings:
 * 1. Check if ETM is present using Component ID validation
 * 2. If present, disable ETM
 * 3. Wait for power management standby to clear
 * 4. Clear control and configuration registers
 *
 * This function ensures ETM is in a known state before configuration.
 *
 * Reference: C1.9 Embedded Trace Macrocell support (page C1-749)
 *            ETM Architecture Specification, ETM Control Register
 */
void etm_init(void)
{
    /* Check if ETM is present using Component ID validation */
    if (!etm_is_present()) {
        return;
    }
    
    /* Disable ETM first */
    etm_disable();
    
    /* Wait for power management standby to clear */
    /* ETM_SR.PMSTANDBY must be 0 before accessing other registers */
    etm_wait_standby_clear();
    
    /* Clear control register */
    ETM_CR = 0;
    
    /* Clear trace enable event register */
    ETM_TEEVR = 0;
    
    /* Clear trace enable control register */
    ETM_TECR1 = 0;
}

/**
 * @brief Enable ETM
 * 使能ETM
 *
 * Sets ETM_CR.ETMEN to enable instruction tracing.
 * When enabled, ETM generates instruction trace packets
 * based on configured trace enable events.
 *
 * Reference: ETM Architecture Specification, ETM Control Register
 */
void etm_enable(void)
{
    ETM_CR |= ETM_CR_ETMEN_Msk;
}

/**
 * @brief Disable ETM
 * 禁用ETM
 *
 * Clears ETM_CR.ETMEN to disable instruction tracing.
 * When disabled, ETM stops generating trace packets
 * but maintains current configuration.
 *
 * Reference: ETM Architecture Specification, ETM Control Register
 */
void etm_disable(void)
{
    ETM_CR &= ~ETM_CR_ETMEN_Msk;
}

/**
 * @brief Check if ETM is present
 * 检查ETM是否存在
 * @return true if ETM is implemented and accessible
 *
 * Validates ETM by checking Component ID registers:
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
bool etm_is_present(void)
{
    uint32_t cidr0 = ETM_CIDR0;
    uint32_t cidr1 = ETM_CIDR1;
    uint32_t cidr2 = ETM_CIDR2;
    uint32_t cidr3 = ETM_CIDR3;
    
    /* Check CID0 preamble: should be 0x0D */
    if ((cidr0 & 0xFF) != ETM_CID0_VALUE) {
        return false;
    }
    
    /* Check CID1: Class=0x9 (Debug component), Preamble=0x0 */
    if ((cidr1 & 0xFF) != ETM_CID1_VALUE) {
        return false;
    }
    
    /* Check CID2 preamble: should be 0x05 */
    if ((cidr2 & 0xFF) != ETM_CID2_VALUE) {
        return false;
    }
    
    /* Check CID3 preamble: should be 0xB1 */
    if ((cidr3 & 0xFF) != ETM_CID3_VALUE) {
        return false;
    }
    
    return true;
}

/**
 * @brief Check if ETM is enabled
 * 检查ETM是否使能
 * @return true if ETM_CR.ETMEN is set
 *
 * Returns the current enable state of ETM.
 * When enabled, ETM generates instruction trace packets.
 *
 * Reference: ETM Architecture Specification, ETM Control Register
 */
bool etm_is_enabled(void)
{
    return (ETM_CR & ETM_CR_ETMEN_Msk) != 0;
}

/**
 * @brief Generate software trigger
 * 生成软件触发
 *
 * Writes to ETM_TRIGGER to generate a software trigger event.
 * This can be used to trigger trace capture or other ETM actions
 * based on software control.
 *
 * Reference: ETM Architecture Specification, Trigger Event Register
 */
void etm_software_trigger(void)
{
    ETM_TRIGGER = 1;
}
