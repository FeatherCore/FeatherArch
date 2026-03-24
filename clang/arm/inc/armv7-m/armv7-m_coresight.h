/*
 * ARM Architecture - ARMv7-M CoreSight Component Identification
 *
 * ============================================================================
 * File: armv7-m_coresight.h
 * Description: ARMv7-M CoreSight Component and Peripheral ID Register Definitions
 * 描述: ARMv7-M CoreSight 组件和外围设备ID寄存器定义
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Appendix D1: Armv7-M CoreSight Infrastructure IDs (page D1-765)
 *     * D1.1 CoreSight infrastructure IDs for an Armv7-M implementation
 *       - Component ID registers (CID0-CID3) at offsets 0xFF0-0xFFF
 *       - Peripheral ID registers (PID0-PID4) at offsets 0xFD0-0xFEF
 *       - CoreSight management registers at offsets 0xF00-0xFCF
 *       - Device-specific registers at offsets 0x000-0xEFF
 *     * Table D1-1: Component and Peripheral ID register formats
 *       - CID0: 0x0D (Preamble)
 *       - CID1: 0xX0 (Component Class [7:4], Preamble [3:0])
 *       - CID2: 0x05 (Preamble)
 *       - CID3: 0xB1 (Preamble)
 *       - PID0-PID3: Part Number, JEP106 ID, Revision
 *       - PID4: 4KB count, JEP106 continuation code
 *     * Table D1-2: CoreSight Software Lock registers
 *       - LAR (Lock Access Register) at offset 0xFB0 (WO)
 *       - LSR (Lock Status Register) at offset 0xFB4 (RO)
 *
 * CoreSight Component Classes:
 *   - 0x0: Generic verification component
 *   - 0x1: ROM table
 *   - 0x9: Debug component
 *   - 0xB: Peripheral test block
 *   - 0xE: Generic IP component
 *   - 0xF: CoreLink, PrimeCell, or other component
 *
 * Armv7-M CoreSight Components:
 *   - ITM:  0xE0000000-0xE0000FFF (Instrumentation Trace Macrocell)
 *   - DWT:  0xE0001000-0xE0001FFF (Data Watchpoint and Trace)
 *   - FPB:  0xE0002000-0xE0002FFF (Flash Patch and Breakpoint)
 *   - SCS:  0xE000ED00-0xE000EFFF (System Control Space)
 *   - TPIU: 0xE0040000-0xE0040FFF (Trace Port Interface Unit)
 *   - ETM:  0xE0041000-0xE0041FFF (Embedded Trace Macrocell)
 *   - ROM:  0xE00FF000-0xE00FFFFF (ROM Table)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_CORESIGHT_H__
#define __ARCH_ARM_V7M_CORESIGHT_H__

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * CoreSight Register Offset Definitions
 * CoreSight 寄存器偏移定义
 * Reference: D1.1 CoreSight infrastructure IDs (page D1-765)
 * ============================================================================
 */

/* Component ID register offsets */
#define CORESIGHT_CID0_OFFSET     0xFF0U     /*!< Component ID0 offset */
#define CORESIGHT_CID1_OFFSET     0xFF4U     /*!< Component ID1 offset */
#define CORESIGHT_CID2_OFFSET     0xFF8U     /*!< Component ID2 offset */
#define CORESIGHT_CID3_OFFSET     0xFFCU     /*!< Component ID3 offset */

/* Peripheral ID register offsets */
#define CORESIGHT_PID0_OFFSET     0xFE0U     /*!< Peripheral ID0 offset */
#define CORESIGHT_PID1_OFFSET     0xFE4U     /*!< Peripheral ID1 offset */
#define CORESIGHT_PID2_OFFSET     0xFE8U     /*!< Peripheral ID2 offset */
#define CORESIGHT_PID3_OFFSET     0xFECU     /*!< Peripheral ID3 offset */
#define CORESIGHT_PID4_OFFSET     0xFD0U     /*!< Peripheral ID4 offset */
#define CORESIGHT_PID5_OFFSET     0xFD4U     /*!< Peripheral ID5 offset (Reserved) */
#define CORESIGHT_PID6_OFFSET     0xFD8U     /*!< Peripheral ID6 offset (Reserved) */
#define CORESIGHT_PID7_OFFSET     0xFDCU     /*!< Peripheral ID7 offset (Reserved) */

/* CoreSight management register offsets */
#define CORESIGHT_LAR_OFFSET      0xFB0U     /*!< Lock Access Register offset (WO) */
#define CORESIGHT_LSR_OFFSET      0xFB4U     /*!< Lock Status Register offset (RO) */

/*
 * ============================================================================
 * Component ID Register Values
 * 组件ID寄存器值
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 * ============================================================================
 */

/* Component ID preamble values */
#define CORESIGHT_CID0_VALUE      0x0DU      /*!< CID0: Preamble byte 0 */
#define CORESIGHT_CID1_VALUE      0x00U      /*!< CID1: Preamble byte 1 (Class in bits[7:4]) */
#define CORESIGHT_CID2_VALUE      0x05U      /*!< CID2: Preamble byte 2 */
#define CORESIGHT_CID3_VALUE      0xB1U      /*!< CID3: Preamble byte 3 */

/* Component Class values (bits[7:4] of CID1) */
#define CORESIGHT_CLASS_GENERIC_VERIF   0x00U  /*!< Generic verification component */
#define CORESIGHT_CLASS_ROM_TABLE       0x01U  /*!< ROM table */
#define CORESIGHT_CLASS_DEBUG           0x09U  /*!< Debug component */
#define CORESIGHT_CLASS_TEST_BLOCK      0x0BU  /*!< Peripheral test block */
#define CORESIGHT_CLASS_GENERIC_IP      0x0EU  /*!< Generic IP component */
#define CORESIGHT_CLASS_CORELINK        0x0FU  /*!< CoreLink, PrimeCell, or other */

/* Component ID mask */
#define CORESIGHT_CID_CLASS_MASK  0xF0U      /*!< Component class mask in CID1 */
#define CORESIGHT_CID_PREAMBLE_MASK 0x0FU   /*!< Preamble mask in CID1 */

/*
 * ============================================================================
 * Peripheral ID Register Bit Definitions
 * 外围设备ID寄存器位定义
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 * ============================================================================
 */

/* PID0: Part Number [7:0] */
#define CORESIGHT_PID0_PART_NUM_Pos   0U
#define CORESIGHT_PID0_PART_NUM_Msk   (0xFFUL << CORESIGHT_PID0_PART_NUM_Pos)

/* PID1: JEP106 ID [3:0], Part Number [11:8] */
#define CORESIGHT_PID1_JEP106_ID_Pos      4U
#define CORESIGHT_PID1_JEP106_ID_Msk      (0x0FUL << CORESIGHT_PID1_JEP106_ID_Pos)
#define CORESIGHT_PID1_PART_NUM_HI_Pos    0U
#define CORESIGHT_PID1_PART_NUM_HI_Msk    (0x0FUL << CORESIGHT_PID1_PART_NUM_HI_Pos)

/* PID2: Revision [7:4], JEDEC [3], JEP106 ID [6:4] */
#define CORESIGHT_PID2_REVISION_Pos       4U
#define CORESIGHT_PID2_REVISION_Msk       (0x0FUL << CORESIGHT_PID2_REVISION_Pos)
#define CORESIGHT_PID2_JEDEC_Pos          3U
#define CORESIGHT_PID2_JEDEC_Msk          (1UL << CORESIGHT_PID2_JEDEC_Pos)
#define CORESIGHT_PID2_JEP106_ID_HI_Pos   0U
#define CORESIGHT_PID2_JEP106_ID_HI_Msk   (0x07UL << CORESIGHT_PID2_JEP106_ID_HI_Pos)

/* PID3: RevAnd [7:4], Customer Modified [3:0] */
#define CORESIGHT_PID3_REVAND_Pos         4U
#define CORESIGHT_PID3_REVAND_Msk         (0x0FUL << CORESIGHT_PID3_REVAND_Pos)
#define CORESIGHT_PID3_CMOD_Pos           0U
#define CORESIGHT_PID3_CMOD_Msk           (0x0FUL << CORESIGHT_PID3_CMOD_Pos)

/* PID4: 4KB Count [7:4], JEP106 Continuation [3:0] */
#define CORESIGHT_PID4_4KB_COUNT_Pos      4U
#define CORESIGHT_PID4_4KB_COUNT_Msk      (0x0FUL << CORESIGHT_PID4_4KB_COUNT_Pos)
#define CORESIGHT_PID4_JEP106_CONT_Pos    0U
#define CORESIGHT_PID4_JEP106_CONT_Msk    (0x0FUL << CORESIGHT_PID4_JEP106_CONT_Pos)

/*
 * ============================================================================
 * Lock Access Register (LAR) Definitions
 * 锁定访问寄存器定义
 * Reference: Table D1-2 CoreSight Software Lock registers (page D1-767)
 * ============================================================================
 */

/* Lock Access Register key values */
#define CORESIGHT_LAR_UNLOCK_KEY      0xC5ACCE55U  /*!< Unlock key (WO) */
#define CORESIGHT_LAR_LOCK_KEY        0x00000000U  /*!< Lock key (WO) */

/*
 * ============================================================================
 * Lock Status Register (LSR) Bit Definitions
 * 锁定状态寄存器位定义
 * Reference: Table D1-2 CoreSight Software Lock registers (page D1-767)
 * ============================================================================
 */

#define CORESIGHT_LSR_LOCK_IMP_Pos    0U
#define CORESIGHT_LSR_LOCK_IMP_Msk    (1UL << CORESIGHT_LSR_LOCK_IMP_Pos)  /*!< Lock mechanism implemented */
#define CORESIGHT_LSR_LOCK_STAT_Pos   1U
#define CORESIGHT_LSR_LOCK_STAT_Msk   (1UL << CORESIGHT_LSR_LOCK_STAT_Pos) /*!< Lock status: 1=locked, 0=unlocked */
#define CORESIGHT_LSR_LOCK_8BIT_Pos   2U
#define CORESIGHT_LSR_LOCK_8BIT_Msk   (1UL << CORESIGHT_LSR_LOCK_8BIT_Pos) /*!< 8-bit lock access implemented */

/*
 * ============================================================================
 * CoreSight Component Base Addresses
 * CoreSight 组件基地址
 * Reference: C1.2.2 The Armv7-M ROM Table (page C1-686)
 * ============================================================================
 */

#define CORESIGHT_ITM_BASE        0xE0000000UL  /*!< ITM base address */
#define CORESIGHT_DWT_BASE        0xE0001000UL  /*!< DWT base address */
#define CORESIGHT_FPB_BASE        0xE0002000UL  /*!< FPB base address */
#define CORESIGHT_SCS_BASE        0xE000E000UL  /*!< SCS base address */
#define CORESIGHT_TPIU_BASE       0xE0040000UL  /*!< TPIU base address */
#define CORESIGHT_ETM_BASE        0xE0041000UL  /*!< ETM base address */
#define CORESIGHT_ROM_BASE        0xE00FF000UL  /*!< ROM Table base address */

/*
 * ============================================================================
 * CoreSight Component ID Register Access Macros
 * CoreSight 组件ID寄存器访问宏
 * ============================================================================
 */

/**
 * @brief Get Component ID0 register value
 * 获取组件ID0寄存器值
 * @param base Component base address
 * @return CID0 value
 */
#define CORESIGHT_GET_CID0(base)      (*(volatile uint32_t *)((base) + CORESIGHT_CID0_OFFSET))

/**
 * @brief Get Component ID1 register value
 * 获取组件ID1寄存器值
 * @param base Component base address
 * @return CID1 value
 */
#define CORESIGHT_GET_CID1(base)      (*(volatile uint32_t *)((base) + CORESIGHT_CID1_OFFSET))

/**
 * @brief Get Component ID2 register value
 * 获取组件ID2寄存器值
 * @param base Component base address
 * @return CID2 value
 */
#define CORESIGHT_GET_CID2(base)      (*(volatile uint32_t *)((base) + CORESIGHT_CID2_OFFSET))

/**
 * @brief Get Component ID3 register value
 * 获取组件ID3寄存器值
 * @param base Component base address
 * @return CID3 value
 */
#define CORESIGHT_GET_CID3(base)      (*(volatile uint32_t *)((base) + CORESIGHT_CID3_OFFSET))

/**
 * @brief Get Peripheral ID0 register value
 * 获取外围设备ID0寄存器值
 * @param base Component base address
 * @return PID0 value
 */
#define CORESIGHT_GET_PID0(base)      (*(volatile uint32_t *)((base) + CORESIGHT_PID0_OFFSET))

/**
 * @brief Get Peripheral ID1 register value
 * 获取外围设备ID1寄存器值
 * @param base Component base address
 * @return PID1 value
 */
#define CORESIGHT_GET_PID1(base)      (*(volatile uint32_t *)((base) + CORESIGHT_PID1_OFFSET))

/**
 * @brief Get Peripheral ID2 register value
 * 获取外围设备ID2寄存器值
 * @param base Component base address
 * @return PID2 value
 */
#define CORESIGHT_GET_PID2(base)      (*(volatile uint32_t *)((base) + CORESIGHT_PID2_OFFSET))

/**
 * @brief Get Peripheral ID3 register value
 * 获取外围设备ID3寄存器值
 * @param base Component base address
 * @return PID3 value
 */
#define CORESIGHT_GET_PID3(base)      (*(volatile uint32_t *)((base) + CORESIGHT_PID3_OFFSET))

/**
 * @brief Get Peripheral ID4 register value
 * 获取外围设备ID4寄存器值
 * @param base Component base address
 * @return PID4 value
 */
#define CORESIGHT_GET_PID4(base)      (*(volatile uint32_t *)((base) + CORESIGHT_PID4_OFFSET))

/**
 * @brief Get Lock Status Register value
 * 获取锁定状态寄存器值
 * @param base Component base address
 * @return LSR value
 */
#define CORESIGHT_GET_LSR(base)       (*(volatile uint32_t *)((base) + CORESIGHT_LSR_OFFSET))

/**
 * @brief Write Lock Access Register
 * 写入锁定访问寄存器
 * @param base Component base address
 * @param key Lock key (CORESIGHT_LAR_UNLOCK_KEY or CORESIGHT_LAR_LOCK_KEY)
 */
#define CORESIGHT_SET_LAR(base, key)  (*(volatile uint32_t *)((base) + CORESIGHT_LAR_OFFSET) = (key))

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Validate CoreSight component by checking Component ID
 * 通过检查组件ID验证CoreSight组件
 * @param base Component base address
 * @return true if valid CoreSight component
 * 
 * Checks CID0-CID3 for valid preamble values.
 * Reference: D1.1 CoreSight infrastructure IDs (page D1-765)
 */
bool coresight_validate_component(uint32_t base);

/**
 * @brief Get Component Class from CID1
 * 从CID1获取组件类别
 * @param base Component base address
 * @return Component class value (0x0-0xF)
 * 
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 */
static inline uint8_t coresight_get_component_class(uint32_t base) {
    return (uint8_t)((CORESIGHT_GET_CID1(base) & CORESIGHT_CID_CLASS_MASK) >> 4);
}

/**
 * @brief Check if component is a ROM table
 * 检查组件是否为ROM表
 * @param base Component base address
 * @return true if component class is ROM table (0x1)
 */
static inline bool coresight_is_rom_table(uint32_t base) {
    return coresight_get_component_class(base) == CORESIGHT_CLASS_ROM_TABLE;
}

/**
 * @brief Check if component is a debug component
 * 检查组件是否为调试组件
 * @param base Component base address
 * @return true if component class is debug (0x9)
 */
static inline bool coresight_is_debug_component(uint32_t base) {
    return coresight_get_component_class(base) == CORESIGHT_CLASS_DEBUG;
}

/**
 * @brief Get Part Number from PID0 and PID1
 * 从PID0和PID1获取部件编号
 * @param base Component base address
 * @return 12-bit part number
 * 
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 */
static inline uint16_t coresight_get_part_number(uint32_t base) {
    uint32_t pid0 = CORESIGHT_GET_PID0(base);
    uint32_t pid1 = CORESIGHT_GET_PID1(base);
    return (uint16_t)(((pid1 & CORESIGHT_PID1_PART_NUM_HI_Msk) << 8) |
                      (pid0 & CORESIGHT_PID0_PART_NUM_Msk));
}

/**
 * @brief Get JEP106 ID from PID1 and PID2
 * 从PID1和PID2获取JEP106 ID
 * @param base Component base address
 * @return 7-bit JEP106 ID
 * 
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 */
static inline uint8_t coresight_get_jep106_id(uint32_t base) {
    uint32_t pid1 = CORESIGHT_GET_PID1(base);
    uint32_t pid2 = CORESIGHT_GET_PID2(base);
    return (uint8_t)(((pid2 & CORESIGHT_PID2_JEP106_ID_HI_Msk) << 4) |
                     ((pid1 & CORESIGHT_PID1_JEP106_ID_Msk) >> 4));
}

/**
 * @brief Get Revision from PID2
 * 从PID2获取修订版本
 * @param base Component base address
 * @return 4-bit revision number
 * 
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 */
static inline uint8_t coresight_get_revision(uint32_t base) {
    return (uint8_t)((CORESIGHT_GET_PID2(base) & CORESIGHT_PID2_REVISION_Msk) >> 4);
}

/**
 * @brief Get 4KB Count from PID4
 * 从PID4获取4KB计数
 * @param base Component base address
 * @return 4-bit 4KB count (log2 of memory block size in 4KB units)
 * 
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 */
static inline uint8_t coresight_get_4kb_count(uint32_t base) {
    return (uint8_t)((CORESIGHT_GET_PID4(base) & CORESIGHT_PID4_4KB_COUNT_Msk) >> 4);
}

/**
 * @brief Check if lock mechanism is implemented
 * 检查锁定机制是否实现
 * @param base Component base address
 * @return true if lock mechanism is implemented
 * 
 * Reference: Table D1-2 CoreSight Software Lock registers (page D1-767)
 */
static inline bool coresight_lock_implemented(uint32_t base) {
    return (CORESIGHT_GET_LSR(base) & CORESIGHT_LSR_LOCK_IMP_Msk) != 0U;
}

/**
 * @brief Check if component is locked
 * 检查组件是否锁定
 * @param base Component base address
 * @return true if component is locked
 * 
 * Reference: Table D1-2 CoreSight Software Lock registers (page D1-767)
 */
static inline bool coresight_is_locked(uint32_t base) {
    return (CORESIGHT_GET_LSR(base) & CORESIGHT_LSR_LOCK_STAT_Msk) != 0U;
}

/**
 * @brief Unlock CoreSight component
 * 解锁CoreSight组件
 * @param base Component base address
 * 
 * Writes unlock key to LAR to unlock the component.
 * Reference: Table D1-2 CoreSight Software Lock registers (page D1-767)
 */
static inline void coresight_unlock(uint32_t base) {
    CORESIGHT_SET_LAR(base, CORESIGHT_LAR_UNLOCK_KEY);
}

/**
 * @brief Lock CoreSight component
 * 锁定CoreSight组件
 * @param base Component base address
 * 
 * Writes lock key to LAR to lock the component.
 * Reference: Table D1-2 CoreSight Software Lock registers (page D1-767)
 */
static inline void coresight_lock(uint32_t base) {
    CORESIGHT_SET_LAR(base, CORESIGHT_LAR_LOCK_KEY);
}

/**
 * @brief Get component size in bytes
 * 获取组件大小（字节）
 * @param base Component base address
 * @return Component size in bytes (based on 4KB count)
 * 
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 */
uint32_t coresight_get_component_size(uint32_t base);

/**
 * @brief Read all Component ID registers
 * 读取所有组件ID寄存器
 * @param base Component base address
 * @param cid Pointer to store CID values (4 elements)
 * 
 * Reference: D1.1 CoreSight infrastructure IDs (page D1-765)
 */
void coresight_read_cid(uint32_t base, uint8_t *cid);

/**
 * @brief Read all Peripheral ID registers
 * 读取所有外围设备ID寄存器
 * @param base Component base address
 * @param pid Pointer to store PID values (8 elements for PID0-PID7)
 * 
 * Reference: Table D1-1 Component and Peripheral ID register formats (page D1-766)
 */
void coresight_read_pid(uint32_t base, uint8_t *pid);

/**
 * @brief Identify CoreSight component
 * 识别CoreSight组件
 * @param base Component base address
 * @return Component type identifier
 * 
 * Uses Part Number and Component Class to identify the component type.
 */
uint32_t coresight_identify_component(uint32_t base);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_CORESIGHT_H__ */
