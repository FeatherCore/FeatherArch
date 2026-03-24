/*
 * ARM Architecture - Cortex-M4 ITM (Instrumentation Trace Macrocell) Registers
 *
 * ============================================================================
 * File: cm4_itm.h
 * Description: Cortex-M4 ITM register definitions
 * 描述: Cortex-M4 ITM 寄存器定义
 *
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual (100166_0001_04_en)
 *   - Chapter 10 Instrumentation Trace Macrocell Unit (page 10-87)
 *   - Table 10-1 ITM register summary (page 10-89)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CM4_ITM_H__
#define __CM4_ITM_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * ITM Registers Base Address
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 * ============================================================================
 */

#define CM4_ITM_BASE_ADDR             0xE0000000UL

/*
 * ============================================================================
 * ITM Stimulus Port Registers (ITM_STIM0-ITM_STIM31)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 * Address: 0xE0000000-0xE000007C
 * ============================================================================
 */

#define ITM_STIM0                     (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x000))
#define ITM_STIM1                     (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x004))
#define ITM_STIM2                     (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x008))
#define ITM_STIM3                     (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x00C))
#define ITM_STIM4                     (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x010))
#define ITM_STIM5                     (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x014))
#define ITM_STIM6                     (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x018))
#define ITM_STIM7                     (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x01C))
#define ITM_STIM8                     (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x020))
#define ITM_STIM9                     (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x024))
#define ITM_STIM10                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x028))
#define ITM_STIM11                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x02C))
#define ITM_STIM12                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x030))
#define ITM_STIM13                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x034))
#define ITM_STIM14                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x038))
#define ITM_STIM15                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x03C))
#define ITM_STIM16                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x040))
#define ITM_STIM17                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x044))
#define ITM_STIM18                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x048))
#define ITM_STIM19                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x04C))
#define ITM_STIM20                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x050))
#define ITM_STIM21                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x054))
#define ITM_STIM22                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x058))
#define ITM_STIM23                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x05C))
#define ITM_STIM24                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x060))
#define ITM_STIM25                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x064))
#define ITM_STIM26                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x068))
#define ITM_STIM27                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x06C))
#define ITM_STIM28                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x070))
#define ITM_STIM29                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x074))
#define ITM_STIM30                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x078))
#define ITM_STIM31                    (*(volatile uint32_t *)(CM4_ITM_BASE_ADDR + 0x07C))

/*
 * ============================================================================
 * ITM Trace Enable Register (ITM_TER)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 * Address: 0xE0000E00
 * Reset value: 0x00000000
 * ============================================================================
 */

#define ITM_TER                       (*(volatile uint32_t *)(0xE0000E00UL))

/*
 * ============================================================================
 * ITM Trace Privilege Register (ITM_TPR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89), Table 10-2 (page 10-90)
 * Address: 0xE0000E40
 * Reset value: 0x00000000
 * ============================================================================
 */

#define ITM_TPR                       (*(volatile uint32_t *)(0xE0000E40UL))

/* ITM_TPR bit definitions - Reference: Table 10-2 (page 10-90) */
#define ITM_TPR_PRIVMASK_Pos          0U
#define ITM_TPR_PRIVMASK_Msk          (0xFUL << ITM_TPR_PRIVMASK_Pos)

/* ITM_TPR PRIVMASK bit mapping - Reference: Table 10-2 (page 10-90) */
#define ITM_TPR_PRIVMASK_STIM0_7      (1UL << 0)
#define ITM_TPR_PRIVMASK_STIM8_15     (1UL << 1)
#define ITM_TPR_PRIVMASK_STIM16_23    (1UL << 2)
#define ITM_TPR_PRIVMASK_STIM24_31    (1UL << 3)

/*
 * ============================================================================
 * ITM Trace Control Register (ITM_TCR)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 * Address: 0xE0000E80
 * Reset value: 0x00000000
 * ============================================================================
 */

#define ITM_TCR                       (*(volatile uint32_t *)(0xE0000E80UL))

/* ITM_TCR bit definitions */
#define ITM_TCR_ITMENA_Pos            0U
#define ITM_TCR_ITMENA_Msk            (1UL << ITM_TCR_ITMENA_Pos)

#define ITM_TCR_TSENA_Pos             1U
#define ITM_TCR_TSENA_Msk             (1UL << ITM_TCR_TSENA_Pos)

#define ITM_TCR_SYNCENA_Pos           2U
#define ITM_TCR_SYNCENA_Msk           (1UL << ITM_TCR_SYNCENA_Pos)

#define ITM_TCR_TXENA_Pos             3U
#define ITM_TCR_TXENA_Msk             (1UL << ITM_TCR_TXENA_Pos)

#define ITM_TCR_SWOENA_Pos            4U
#define ITM_TCR_SWOENA_Msk            (1UL << ITM_TCR_SWOENA_Pos)

#define ITM_TCR_TSPRESCALE_Pos        8U
#define ITM_TCR_TSPRESCALE_Msk        (3UL << ITM_TCR_TSPRESCALE_Pos)

#define ITM_TCR_STALLENA_Pos          5U
#define ITM_TCR_STALLENA_Msk          (1UL << ITM_TCR_STALLENA_Pos)

#define ITM_TCR_BUSY_Pos              23U
#define ITM_TCR_BUSY_Msk              (1UL << ITM_TCR_BUSY_Pos)

#define ITM_TCR_TRACEBUSID_Pos        16U
#define ITM_TCR_TRACEBUSID_Msk        (0x7FUL << ITM_TCR_TRACEBUSID_Pos)

/*
 * ============================================================================
 * ITM Function Declarations
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 10 (page 10-87)
 * ============================================================================
 */

/**
 * @brief Enable ITM
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 10.1 (page 10-88)
 */
void cm4_itm_enable(void);

/**
 * @brief Disable ITM
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Chapter 10.1 (page 10-88)
 */
void cm4_itm_disable(void);

/**
 * @brief Send character via ITM
 * @param port Stimulus port (0-31)
 * @param ch Character to send
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 */
void cm4_itm_send_char(uint32_t port, uint8_t ch);

/**
 * @brief Send 32-bit word via ITM
 * @param port Stimulus port (0-31)
 * @param value Value to send
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 */
void cm4_itm_send_word(uint32_t port, uint32_t value);

/**
 * @brief Check if ITM port is ready
 * @param port Stimulus port (0-31)
 * @return 1 if ready, 0 if not
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 */
int cm4_itm_port_ready(uint32_t port);

/**
 * @brief Enable ITM stimulus port
 * @param port Stimulus port (0-31)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 */
void cm4_itm_enable_port(uint32_t port);

/**
 * @brief Disable ITM stimulus port
 * @param port Stimulus port (0-31)
 * Reference: Arm(R) Cortex-M4 Processor Technical Reference Manual, Table 10-1 (page 10-89)
 */
void cm4_itm_disable_port(uint32_t port);

#ifdef __cplusplus
}
#endif

#endif /* __CM4_ITM_H__ */
