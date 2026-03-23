/*
 * ARM Architecture - ARMv7-M TPIU (Trace Port Interface Unit)
 *
 * ============================================================================
 * File: armv7-m_tpiu.h
 * Description: ARMv7-M TPIU definitions
 * 描述: ARMv7-M 跟踪端口接口单元定义
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual
 *   - Chapter B12: Trace Port Interface Unit
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_TPIU_H__
#define __ARCH_ARM_V7M_TPIU_H__

#include <stdint.h>
#include "armv7-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * TPIU Base Address
 * TPIU 基地址
 * ============================================================================
 */

#define TPIU_BASE_ADDR            0xE0040000UL

/*
 * ============================================================================
 * TPIU Register Definitions
 * TPIU 寄存器定义
 * ============================================================================
 */

/**
 * TPIU Supported Parallel Port Sizes Register (TPIU_SSPSR)
 * TPIU 支持的并行端口大小寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, B12.1
 */
#define TPIU_SSPSR               (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0x000))

/**
 * TPIU Current Parallel Port Sizes Register (TPIU_CSPSR)
 * TPIU 当前并行端口大小寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, B12.2
 */
#define TPIU_CSPSR               (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0x004))

/**
 * TPIU Asynchronous Clock Prescaler Register (TPIU_ACPR)
 * TPIU 异步时钟预分频器寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, B12.3
 */
#define TPIU_ACPR                (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0x010))

/**
 * TPIU Selected Pin Protocol Register (TPIU_SPPR)
 * TPIU 选定引脚协议寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, B12.4
 */
#define TPIU_SPPR                (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0x0F0))

/**
 * TPIU Formatter and Flush Status Register (TPIU_FFSR)
 * TPIU 格式化器和刷新状态寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, B12.5
 */
#define TPIU_FFSR                (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0x300))

/**
 * TPIU Formatter and Flush Control Register (TPIU_FFCR)
 * TPIU 格式化器和刷新控制寄存器
 * Reference: Arm(R) v7-M Architecture Reference Manual, B12.6
 */
#define TPIU_FFCR                (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0x304))

/**
 * TPIU Claim Tag Set Register (TPIU_CLAIMSET)
 * TPIU 声明标签设置寄存器
 */
#define TPIU_CLAIMSET            (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFA0))

/**
 * TPIU Claim Tag Clear Register (TPIU_CLAIMCLR)
 * TPIU 声明标签清除寄存器
 */
#define TPIU_CLAIMCLR            (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFA4))

/**
 * TPIU Software Lock Access Register (TPIU_LAR)
 * TPIU 软件锁访问寄存器
 */
#define TPIU_LAR                 (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFB0))

/**
 * TPIU Software Lock Status Register (TPIU_LSR)
 * TPIU 软件锁状态寄存器
 */
#define TPIU_LSR                 (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFB4))

/**
 * TPIU Device Identifier Register (TPIU_DEVID)
 * TPIU 设备标识符寄存器
 */
#define TPIU_DEVID               (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFC8))

/**
 * TPIU Device Type Register (TPIU_DEVTYPE)
 * TPIU 设备类型寄存器
 */
#define TPIU_DEVTYPE             (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFCC))

/**
 * TPIU Peripheral Identification Register 4 (TPIU_PIDR4)
 * TPIU 外设标识寄存器4
 */
#define TPIU_PIDR4               (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFD0))

/**
 * TPIU Peripheral Identification Register 5 (TPIU_PIDR5)
 * TPIU 外设标识寄存器5
 */
#define TPIU_PIDR5               (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFD4))

/**
 * TPIU Peripheral Identification Register 6 (TPIU_PIDR6)
 * TPIU 外设标识寄存器6
 */
#define TPIU_PIDR6               (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFD8))

/**
 * TPIU Peripheral Identification Register 7 (TPIU_PIDR7)
 * TPIU 外设标识寄存器7
 */
#define TPIU_PIDR7               (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFDC))

/**
 * TPIU Peripheral Identification Register 0 (TPIU_PIDR0)
 * TPIU 外设标识寄存器0
 */
#define TPIU_PIDR0               (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFE0))

/**
 * TPIU Peripheral Identification Register 1 (TPIU_PIDR1)
 * TPIU 外设标识寄存器1
 */
#define TPIU_PIDR1               (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFE4))

/**
 * TPIU Peripheral Identification Register 2 (TPIU_PIDR2)
 * TPIU 外设标识寄存器2
 */
#define TPIU_PIDR2               (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFE8))

/**
 * TPIU Peripheral Identification Register 3 (TPIU_PIDR3)
 * TPIU 外设标识寄存器3
 */
#define TPIU_PIDR3               (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFEC))

/**
 * TPIU Component Identification Register 0 (TPIU_CIDR0)
 * TPIU 组件标识寄存器0
 */
#define TPIU_CIDR0               (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFF0))

/**
 * TPIU Component Identification Register 1 (TPIU_CIDR1)
 * TPIU 组件标识寄存器1
 */
#define TPIU_CIDR1               (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFF4))

/**
 * TPIU Component Identification Register 2 (TPIU_CIDR2)
 * TPIU 组件标识寄存器2
 */
#define TPIU_CIDR2               (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFF8))

/**
 * TPIU Component Identification Register 3 (TPIU_CIDR3)
 * TPIU 组件标识寄存器3
 */
#define TPIU_CIDR3               (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0xFFC))

/*
 * ============================================================================
 * TPIU Register Bit Definitions
 * TPIU 寄存器位定义
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
