/*
 * ARM Architecture - ARMv7-M TPIU (Trace Port Interface Unit)
 *
 * ============================================================================
 * File: armv7-m_tpiu.h
 * Description: ARMv7-M TPIU definitions
 * 描述: ARMv7-M 跟踪端口接口单元定义
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter C1.10: Trace Port Interface Unit
 *   - Table C1-23 TPIU registers (page C1-750)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_TPIU_H__
#define __ARCH_ARM_V7M_TPIU_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * TPIU Base Address
 * TPIU 基地址
 * Reference: Table C1-10 Debug register regions (page C1-699)
 * ============================================================================
 */

#define TPIU_BASE_ADDR            0xE0040000UL

/*
 * ============================================================================
 * TPIU Register Definitions
 * TPIU 寄存器定义
 * Reference: Table C1-23 TPIU registers (page C1-750)
 * ============================================================================
 */

/**
 * TPIU Supported Parallel Port Sizes Register (TPIU_SSPSR)
 * Address: 0xE0040000
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-751
 */
#define TPIU_SSPSR               (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0x000))

/**
 * TPIU Current Parallel Port Sizes Register (TPIU_CSPSR)
 * Address: 0xE0040004
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-751
 */
#define TPIU_CSPSR               (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0x004))

/**
 * TPIU Asynchronous Clock Prescaler Register (TPIU_ACPR)
 * Address: 0xE0040010
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-751
 */
#define TPIU_ACPR                (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0x010))

/**
 * TPIU Selected Pin Protocol Register (TPIU_SPPR)
 * Address: 0xE00400F0
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-752
 */
#define TPIU_SPPR                (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0x0F0))

/**
 * TPIU Formatter and Flush Status Register (TPIU_FFSR)
 * Address: 0xE0040300
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-752
 */
#define TPIU_FFSR                (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0x300))

/**
 * TPIU Formatter and Flush Control Register (TPIU_FFCR)
 * Address: 0xE0040304
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-753
 */
#define TPIU_FFCR                (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0x304))

/**
 * TPIU Claim Tag Set Register (TPIU_CLAIMSET)
 * Address: 0xE0040FA0
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-753
 */
#define TPIU_CLAIMSET            (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFA0))

/**
 * TPIU Claim Tag Clear Register (TPIU_CLAIMCLR)
 * Address: 0xE0040FA4
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-753
 */
#define TPIU_CLAIMCLR            (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFA4))

/**
 * TPIU Device Identifier Register (TPIU_DEVID)
 * Address: 0xE0040FC8
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-754
 */
#define TPIU_DEVID               (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFC8))

/*
 * ============================================================================
 * TPIU Register Bit Definitions
 * TPIU 寄存器位定义
 * Reference: Arm(R) v7-M Architecture Reference Manual, C1-752
 * ============================================================================
 */

/* TPIU_SPPR Selected Pin Protocol Register Bits */
#define TPIU_SPPR_PROTOCOL_Pos    0U
#define TPIU_SPPR_PROTOCOL_Msk    (0x3UL << TPIU_SPPR_PROTOCOL_Pos)
#define TPIU_SPPR_PROTOCOL_TRACEPORT 0x0U
#define TPIU_SPPR_PROTOCOL_MANCHESTER 0x1U
#define TPIU_SPPR_PROTOCOL_NRZ     0x2U

/* TPIU_FFSR Formatter and Flush Status Register Bits */
#define TPIU_FFSR_TCPresent_Pos   3U
#define TPIU_FFSR_TCPresent_Msk   (1UL << TPIU_FFSR_TCPresent_Pos)
#define TPIU_FFSR_FtStopped_Pos   2U
#define TPIU_FFSR_FtStopped_Msk   (1UL << TPIU_FFSR_FtStopped_Pos)
#define TPIU_FFSR_FtInProgress_Pos 1U
#define TPIU_FFSR_FtInProgress_Msk (1UL << TPIU_FFSR_FtInProgress_Pos)
#define TPIU_FFSR_FlInProgress_Pos 0U
#define TPIU_FFSR_FlInProgress_Msk (1UL << TPIU_FFSR_FlInProgress_Pos)

/* TPIU_FFCR Formatter and Flush Control Register Bits */
#define TPIU_FFCR_TrigIn_Pos     8U
#define TPIU_FFCR_TrigIn_Msk     (1UL << TPIU_FFCR_TrigIn_Pos)
#define TPIU_FFCR_FOnMan_Pos      6U
#define TPIU_FFCR_FOnMan_Msk      (1UL << TPIU_FFCR_FOnMan_Pos)
#define TPIU_FFCR_EnFCont_Pos      1U
#define TPIU_FFCR_EnFCont_Msk      (1UL << TPIU_FFCR_EnFCont_Pos)
#define TPIU_FFCR_EnFC_Pos        0U
#define TPIU_FFCR_EnFC_Msk        (1UL << TPIU_FFCR_EnFC_Pos)

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Enable TPIU
 */
void tpiu_enable(void);

/**
 * @brief Disable TPIU
 */
void tpiu_disable(void);

/**
 * @brief Set TPIU pin protocol
 * @param protocol Protocol to use (0-2)
 */
void tpiu_set_protocol(uint32_t protocol);

/**
 * @brief Set TPIU prescaler
 * @param prescaler Prescaler value
 */
void tpiu_set_prescaler(uint32_t prescaler);

/**
 * @brief Flush TPIU
 */
void tpiu_flush(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_TPIU_H__ */
