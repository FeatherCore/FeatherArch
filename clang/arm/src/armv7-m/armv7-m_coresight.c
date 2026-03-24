/*
 * ARM Architecture - ARMv7-M CoreSight Component Identification Implementation
 *
 * ============================================================================
 * File: armv7-m_coresight.c
 * Description: ARMv7-M CoreSight Component and Peripheral ID Register Functions
 * 描述: ARMv7-M CoreSight 组件和外围设备ID寄存器函数实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Appendix D1: Armv7-M CoreSight Infrastructure IDs (page D1-765)
 *     * D1.1 CoreSight infrastructure IDs for an Armv7-M implementation
 *       - Component ID validation using CID0-CID3 preamble values
 *       - Peripheral ID extraction (Part Number, JEP106 ID, Revision)
 *       - Component size calculation from PID4 4KB count
 *     * Table D1-1: Component and Peripheral ID register formats
 *       - CID0: 0x0D, CID1: 0xX0, CID2: 0x05, CID3: 0xB1
 *       - PID0-PID3: Part Number [11:0], JEP106 ID [6:0], Revision [3:0]
 *       - PID4: 4KB count [3:0], JEP106 continuation [3:0]
 *     * Table D1-2: CoreSight Software Lock registers
 *       - LAR unlock key: 0xC5ACCE55
 *       - LSR status bits: LOCK_IMP, LOCK_STAT, LOCK_8BIT
 *
 * Component Identification Process:
 *   1. Read CID0-CID3 and verify preamble values
 *   2. Extract Component Class from CID1[7:4]
 *   3. Read PID0-PID4 to get Part Number and designer info
 *   4. Calculate component size from PID4 4KB count
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_coresight.h"

/*
 * ============================================================================
 * Component ID Preamble Values
 * 组件ID前导码值
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 * ============================================================================
 */

/**
 * @brief Validate CoreSight component by checking Component ID
 * 通过检查组件ID验证CoreSight组件
 * @param base Component base address
 * @return true if valid CoreSight component
 *
 * Checks CID0-CID3 for valid preamble values:
 * - CID0 should be 0x0D (preamble byte 0)
 * - CID1 should have preamble 0x00 in bits[3:0]
 * - CID2 should be 0x05 (preamble byte 2)
 * - CID3 should be 0xB1 (preamble byte 3)
 *
 * Reference: D1.1 CoreSight infrastructure IDs (page D1-765)
 */
bool coresight_validate_component(uint32_t base)
{
    uint8_t cid0, cid1, cid2, cid3;

    /* Read Component ID registers */
    cid0 = (uint8_t)CORESIGHT_GET_CID0(base);
    cid1 = (uint8_t)CORESIGHT_GET_CID1(base);
    cid2 = (uint8_t)CORESIGHT_GET_CID2(base);
    cid3 = (uint8_t)CORESIGHT_GET_CID3(base);

    /* Check preamble values */
    if (cid0 != CORESIGHT_CID0_VALUE) {
        return false;
    }

    if ((cid1 & CORESIGHT_CID_PREAMBLE_MASK) != (CORESIGHT_CID1_VALUE & CORESIGHT_CID_PREAMBLE_MASK)) {
        return false;
    }

    if (cid2 != CORESIGHT_CID2_VALUE) {
        return false;
    }

    if (cid3 != CORESIGHT_CID3_VALUE) {
        return false;
    }

    return true;
}

/**
 * @brief Get component size in bytes
 * 获取组件大小（字节）
 * @param base Component base address
 * @return Component size in bytes
 *
 * Calculates component size from PID4 4KB count field.
 * Size = 4KB * (2 ^ 4KB_count)
 *
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 */
uint32_t coresight_get_component_size(uint32_t base)
{
    uint8_t count_4kb = coresight_get_4kb_count(base);

    /* Size = 4KB * (2 ^ count_4kb) */
    return 4096U * (1U << count_4kb);
}

/**
 * @brief Read all Component ID registers
 * 读取所有组件ID寄存器
 * @param base Component base address
 * @param cid Pointer to store CID values (4 elements: CID0-CID3)
 *
 * Reference: D1.1 CoreSight infrastructure IDs (page D1-765)
 */
void coresight_read_cid(uint32_t base, uint8_t *cid)
{
    if (cid == NULL) {
        return;
    }

    cid[0] = (uint8_t)CORESIGHT_GET_CID0(base);
    cid[1] = (uint8_t)CORESIGHT_GET_CID1(base);
    cid[2] = (uint8_t)CORESIGHT_GET_CID2(base);
    cid[3] = (uint8_t)CORESIGHT_GET_CID3(base);
}

/**
 * @brief Read all Peripheral ID registers
 * 读取所有外围设备ID寄存器
 * @param base Component base address
 * @param pid Pointer to store PID values (8 elements for PID0-PID7)
 *
 * Note: PID5-PID7 are reserved and read as 0.
 *
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 */
void coresight_read_pid(uint32_t base, uint8_t *pid)
{
    if (pid == NULL) {
        return;
    }

    pid[0] = (uint8_t)CORESIGHT_GET_PID0(base);
    pid[1] = (uint8_t)CORESIGHT_GET_PID1(base);
    pid[2] = (uint8_t)CORESIGHT_GET_PID2(base);
    pid[3] = (uint8_t)CORESIGHT_GET_PID3(base);
    pid[4] = (uint8_t)CORESIGHT_GET_PID4(base);
    /* PID5-PID7 are reserved, read as 0 */
    pid[5] = 0;
    pid[6] = 0;
    pid[7] = 0;
}

/*
 * ============================================================================
 * Known CoreSight Component Part Numbers
 * 已知CoreSight组件部件编号
 * These are common part numbers for Armv7-M debug components
 * ============================================================================
 */

#define CORESIGHT_PART_NUMBER_ITM     0x001U  /*!< ITM Part Number */
#define CORESIGHT_PART_NUMBER_DWT     0x002U  /*!< DWT Part Number */
#define CORESIGHT_PART_NUMBER_FPB     0x003U  /*!< FPB Part Number */
#define CORESIGHT_PART_NUMBER_SCS     0x000U  /*!< SCS Part Number (varies) */
#define CORESIGHT_PART_NUMBER_TPIU    0x9A1U  /*!< TPIU Part Number */
#define CORESIGHT_PART_NUMBER_ETM     0x9A0U  /*!< ETM Part Number */
#define CORESIGHT_PART_NUMBER_ROM     0x001U  /*!< ROM Table Part Number (with Class 0x1) */

/**
 * @brief Identify CoreSight component
 * 识别CoreSight组件
 * @param base Component base address
 * @return Component type identifier
 *
 * Uses Part Number and Component Class to identify the component type.
 * Returns a 32-bit identifier with class in upper 16 bits and part number in lower 16 bits.
 */
uint32_t coresight_identify_component(uint32_t base)
{
    uint8_t component_class;
    uint16_t part_number;

    /* Validate component first */
    if (!coresight_validate_component(base)) {
        return 0xFFFFFFFFU;  /* Invalid component */
    }

    /* Get component class and part number */
    component_class = coresight_get_component_class(base);
    part_number = coresight_get_part_number(base);

    /* Return combined identifier: (class << 16) | part_number */
    return ((uint32_t)component_class << 16) | part_number;
}
