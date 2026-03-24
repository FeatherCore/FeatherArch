/*
 * ARM Architecture - Cortex-M4 TPIU (Trace Port Interface Unit) Registers
 *
 * ============================================================================
 * File: cm4_tpiu.h
 * Description: Cortex-M4 TPIU register definitions
 * 描述: Cortex-M4 TPIU 寄存器定义
 *
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual (100166_0001_04_en)
 *   - Chapter 11 Trace Port Interface Unit (page 11-91)
 *   - Table 11-1 TPIU registers (page 11-95)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_TPIU_H__
#define __CM4_TPIU_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * TPIU Registers Base Address
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-1 (page 11-95)
 * ============================================================================
 */

#define CM4_TPIU_BASE_ADDR            0xE0040000UL

/*
 * ============================================================================
 * TPIU Supported Parallel Port Size Register (TPIU_SSPSR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-1 (page 11-95)
 * Address: 0xE0040000
 * Reset value: 0x0xx
 * ============================================================================
 */

#define TPIU_SSPSR                    (*(volatile uint32_t *)(CM4_TPIU_BASE_ADDR + 0x000))

/*
 * ============================================================================
 * TPIU Current Parallel Port Size Register (TPIU_CSPSR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-1 (page 11-95)
 * Address: 0xE0040004
 * Reset value: 0x01
 * ============================================================================
 */

#define TPIU_CSPSR                    (*(volatile uint32_t *)(CM4_TPIU_BASE_ADDR + 0x004))

/*
 * ============================================================================
 * TPIU Asynchronous Clock Prescaler Register (TPIU_ACPR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-1 (page 11-95), Table 11-2 (page 11-96)
 * Address: 0xE0040010
 * Reset value: 0x0000
 * ============================================================================
 */

#define TPIU_ACPR                     (*(volatile uint32_t *)(CM4_TPIU_BASE_ADDR + 0x010))

/* TPIU_ACPR bit definitions - Reference: Table 11-2 (page 11-96) */
#define TPIU_ACPR_PRESCALER_Pos       0U
#define TPIU_ACPR_PRESCALER_Msk       (0x1FFFUL << TPIU_ACPR_PRESCALER_Pos)

/*
 * ============================================================================
 * TPIU Selected Pin Protocol Register (TPIU_SPPR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-1 (page 11-95)
 * Address: 0xE00400F0
 * Reset value: 0x01
 * ============================================================================
 */

#define TPIU_SPPR                     (*(volatile uint32_t *)(CM4_TPIU_BASE_ADDR + 0x0F0))

/* TPIU_SPPR values */
#define TPIU_SPPR_SYNC                0x0UL
#define TPIU_SPPR_SWO_MANCHESTER      0x1UL
#define TPIU_SPPR_SWO_NRZ             0x2UL

/*
 * ============================================================================
 * TPIU Formatter and Flush Status Register (TPIU_FFSR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-1 (page 11-95), Table 11-3 (page 11-97)
 * Address: 0xE0040300
 * Reset value: 0x08
 * ============================================================================
 */

#define TPIU_FFSR                     (*(volatile uint32_t *)(CM4_TPIU_BASE_ADDR + 0x300))

/* TPIU_FFSR bit definitions - Reference: Table 11-3 (page 11-97) */
#define TPIU_FFSR_FlInProg_Pos        0U
#define TPIU_FFSR_FlInProg_Msk        (1UL << TPIU_FFSR_FlInProg_Pos)

#define TPIU_FFSR_FtStopped_Pos       1U
#define TPIU_FFSR_FtStopped_Msk       (1UL << TPIU_FFSR_FtStopped_Pos)

#define TPIU_FFSR_TCPresent_Pos       2U
#define TPIU_FFSR_TCPresent_Msk       (1UL << TPIU_FFSR_TCPresent_Pos)

#define TPIU_FFSR_FtNonStop_Pos       3U
#define TPIU_FFSR_FtNonStop_Msk       (1UL << TPIU_FFSR_FtNonStop_Pos)

/*
 * ============================================================================
 * TPIU Formatter and Flush Control Register (TPIU_FFCR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-1 (page 11-95)
 * Address: 0xE0040304
 * Reset value: 0x102
 * ============================================================================
 */

#define TPIU_FFCR                     (*(volatile uint32_t *)(CM4_TPIU_BASE_ADDR + 0x304))

/* TPIU_FFCR bit definitions */
#define TPIU_FFCR_EnFCont_Pos         1U
#define TPIU_FFCR_EnFCont_Msk         (1UL << TPIU_FFCR_EnFCont_Pos)

#define TPIU_FFCR_TrigIn_Pos          8U
#define TPIU_FFCR_TrigIn_Msk          (1UL << TPIU_FFCR_TrigIn_Pos)

/*
 * ============================================================================
 * TPIU Formatter Synchronization Counter Register (TPIU_FSCR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-1 (page 11-95)
 * Address: 0xE0040308
 * Reset value: 0x00
 * ============================================================================
 */

#define TPIU_FSCR                     (*(volatile uint32_t *)(CM4_TPIU_BASE_ADDR + 0x308))

/*
 * ============================================================================
 * TPIU Device ID Register (TPIU_DEVID)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-1 (page 11-95)
 * Address: 0xE0040FC8
 * Reset value: 0xCA0 or 0xCA1
 * ============================================================================
 */

#define TPIU_DEVID                    (*(volatile uint32_t *)(CM4_TPIU_BASE_ADDR + 0xFC8))

/* TPIU_DEVID reset values - Reference: Table 11-1 (page 11-95) */
#define TPIU_DEVID_RESET_ITM_ONLY     0xCA0UL
#define TPIU_DEVID_RESET_ITM_ETM      0xCA1UL

/*
 * ============================================================================
 * TPIU Device Type Register (TPIU_DEVTYPE)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-1 (page 11-95)
 * Address: 0xE0040FCC
 * Reset value: 0x11
 * ============================================================================
 */

#define TPIU_DEVTYPE                  (*(volatile uint32_t *)(CM4_TPIU_BASE_ADDR + 0xFCC))

/* TPIU_DEVTYPE reset value - Reference: Table 11-1 (page 11-95) */
#define TPIU_DEVTYPE_RESET_VALUE      0x11UL

/*
 * ============================================================================
 * TPIU Function Declarations
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 11 (page 11-91)
 * ============================================================================
 */

/**
 * @brief Set SWO baud rate prescaler
 * @param prescaler Prescaler value (0-8191)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-2 (page 11-96)
 */
void cm4_tpiu_set_prescaler(uint32_t prescaler);

/**
 * @brief Set pin protocol
 * @param protocol Protocol (0=sync, 1=Manchester, 2=NRZ)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-1 (page 11-95)
 */
void cm4_tpiu_set_pin_protocol(uint32_t protocol);

/**
 * @brief Enable formatter
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-1 (page 11-95)
 */
void cm4_tpiu_enable_formatter(void);

/**
 * @brief Disable formatter
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-1 (page 11-95)
 */
void cm4_tpiu_disable_formatter(void);

/**
 * @brief Get TPIU device ID
 * @return Device ID value
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 11-1 (page 11-95)
 */
uint32_t cm4_tpiu_get_devid(void);

#ifdef __cplusplus
}
#endif

#endif /* __CM4_TPIU_H__ */
