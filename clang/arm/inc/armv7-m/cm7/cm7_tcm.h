/**
 * @file cm7_tcm.h
 * @brief Cortex-M7 Tightly-Coupled Memory (TCM) Control Registers
 *
 * @reference Arm Cortex-M7 Processor Technical Reference Manual
 *   - Section 3.2 Register summary, Table 3-1 System control registers
 *   - Section 3.3.6 Instruction and Data Tightly-Coupled Memory Control Registers
 *   - Section 3.3.7 AHBP Control Register
 *   - Section 3.3.12 AHB Slave Control Register
 */

#ifndef CM7_TCM_H
#define CM7_TCM_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Instruction and Data Tightly-Coupled Memory Control Registers
 * Reference: Arm Cortex-M7 Processor Technical Reference Manual, Section 3.3.6
 *============================================================================*/

/**
 * CM7_ITCMCR - Instruction TCM Control Register
 * Address: 0xE000EF90
 * Type: RW, Privileged
 * Reference: Table 3-1 System control registers
 * Purpose: Controls whether an access is mapped to TCM or AXIM interface.
 */
#define CM7_ITCMCR                (*(volatile uint32_t *)(0xE000EF90UL))

/**
 * CM7_DTCMCR - Data TCM Control Register
 * Address: 0xE000EF94
 * Type: RW, Privileged
 * Reference: Table 3-1 System control registers
 * Purpose: Controls whether an access is mapped to TCM or AXIM interface.
 */
#define CM7_DTCMCR                (*(volatile uint32_t *)(0xE000EF94UL))

/* CM7_ITCMCR and CM7_DTCMCR Bit Assignments - Reference: Table 3-9 */

/**
 * EN - TCM enable
 * Bit [0]
 * Reference: Table 3-9 CM7_ITCMCR and CM7_DTCMCR bit assignments
 * 0: TCM disabled. When a TCM is disabled all accesses are made to the AXIM interface.
 * 1: TCM enabled.
 */
#define CM7_TCMCR_EN_Pos          0U
#define CM7_TCMCR_EN_Msk          (1UL << CM7_TCMCR_EN_Pos)

/**
 * RMW - Read-Modify-Write (RMW) enable
 * Bit [1]
 * Reference: Table 3-9 CM7_ITCMCR and CM7_DTCMCR bit assignments
 * 0: RMW disabled.
 * 1: RMW enabled. Indicates that all writes to TCM, that are not the full width of the
 *    TCM RAM, use a RMW sequence.
 */
#define CM7_TCMCR_RMW_Pos         1U
#define CM7_TCMCR_RMW_Msk         (1UL << CM7_TCMCR_RMW_Pos)

/**
 * RETEN - Retry phase enable
 * Bit [2]
 * Reference: Table 3-9 CM7_ITCMCR and CM7_DTCMCR bit assignments
 * 0: Retry phase disabled.
 * 1: Retry phase enabled. When enabled the processor guarantees to honor the retry output
 *    on the corresponding TCM interface, re-executing the instruction that performed the TCM access.
 */
#define CM7_TCMCR_RETEN_Pos       2U
#define CM7_TCMCR_RETEN_Msk       (1UL << CM7_TCMCR_RETEN_Pos)

/**
 * SZ - TCM size
 * Bits [6:3], RO
 * Reference: Table 3-9 CM7_ITCMCR and CM7_DTCMCR bit assignments
 */
#define CM7_TCMCR_SZ_Pos          3U
#define CM7_TCMCR_SZ_Msk          (0xFUL << CM7_TCMCR_SZ_Pos)

/* SZ values - Reference: Table 3-9 */
#define CM7_TCMCR_SZ_NONE         0x0U   /* 0b0000: No TCM implemented */
#define CM7_TCMCR_SZ_4KB          0x3U   /* 0b0011: 4KB */
#define CM7_TCMCR_SZ_8KB          0x4U   /* 0b0100: 8KB */
#define CM7_TCMCR_SZ_16KB         0x5U   /* 0b0101: 16KB */
#define CM7_TCMCR_SZ_32KB         0x6U   /* 0b0110: 32KB */
#define CM7_TCMCR_SZ_64KB         0x7U   /* 0b0111: 64KB */
#define CM7_TCMCR_SZ_128KB        0x8U   /* 0b1000: 128KB */
#define CM7_TCMCR_SZ_256KB        0x9U   /* 0b1001: 256KB */
#define CM7_TCMCR_SZ_512KB        0xAU   /* 0b1010: 512KB */
#define CM7_TCMCR_SZ_1MB          0xBU   /* 0b1011: 1MB */
#define CM7_TCMCR_SZ_2MB          0xCU   /* 0b1100: 2MB */
#define CM7_TCMCR_SZ_4MB          0xDU   /* 0b1101: 4MB */
#define CM7_TCMCR_SZ_8MB          0xEU   /* 0b1110: 8MB */
#define CM7_TCMCR_SZ_16MB         0xFU   /* 0b1111: 16MB */

/*============================================================================*
 * AHBP Control Register (CM7_AHBPCR)
 * Reference: Arm Cortex-M7 Processor Technical Reference Manual, Section 3.3.7
 *============================================================================*/

/**
 * CM7_AHBPCR - AHBP Control Register
 * Address: 0xE000EF98
 * Type: RW, Privileged
 * Reference: Table 3-1 System control registers
 * Purpose: Controls accesses to AHBP or AXIM interface.
 */
#define CM7_AHBPCR                (*(volatile uint32_t *)(0xE000EF98UL))

/* CM7_AHBPCR Bit Assignments - Reference: Table 3-10 */

/**
 * EN - AHBP enable
 * Bit [0]
 * Reference: Table 3-10 CM7_AHBPCR bit assignments
 * 0: AHBP disabled. When disabled all accesses are made to the AXIM interface.
 * 1: AHBP enabled.
 */
#define CM7_AHBPCR_EN_Pos         0U
#define CM7_AHBPCR_EN_Msk         (1UL << CM7_AHBPCR_EN_Pos)

/**
 * SZ - AHBP size
 * Bits [3:1], RO
 * Reference: Table 3-10 CM7_AHBPCR bit assignments
 */
#define CM7_AHBPCR_SZ_Pos         1U
#define CM7_AHBPCR_SZ_Msk         (0x7UL << CM7_AHBPCR_SZ_Pos)

/* SZ values - Reference: Table 3-10 */
#define CM7_AHBPCR_SZ_DISABLED    0x0U   /* 0b000: 0MB. AHBP disabled */
#define CM7_AHBPCR_SZ_64MB        0x1U   /* 0b001: 64MB */
#define CM7_AHBPCR_SZ_128MB       0x2U   /* 0b010: 128MB */
#define CM7_AHBPCR_SZ_256MB       0x3U   /* 0b011: 256MB */
#define CM7_AHBPCR_SZ_512MB       0x4U   /* 0b100: 512MB */

/*============================================================================*
 * AHB Slave Control Register (CM7_AHBSCR)
 * Reference: Arm Cortex-M7 Processor Technical Reference Manual, Section 3.3.12
 *============================================================================*/

/**
 * CM7_AHBSCR - AHB Slave Control Register
 * Address: 0xE000EFA0
 * Type: RW, Privileged
 * Reference: Table 3-1 System control registers
 * Purpose: Controls the priority between software and AHB slave access to TCMs.
 */
#define CM7_AHBSCR                (*(volatile uint32_t *)(0xE000EFA0UL))

/* CM7_AHBSCR Bit Assignments - Reference: Table 3-15 */

/**
 * CTL - AHBS prioritization control
 * Bits [1:0]
 * Reference: Table 3-15 CM7_AHBSCR bit assignments
 * 0b00: AHBS access priority demoted. This is the reset value.
 * 0b01: Software access priority demoted.
 * 0b10: AHBS access priority demoted by initializing the fairness counter to the
 *       CM7_AHBSCR.INITCOUNT value when the software execution priority is
 *       higher than or equal to the threshold level programmed in CM7_AHBSCR.TPRI.
 * 0b11: AHBSPRI signal has control of access priority.
 */
#define CM7_AHBSCR_CTL_Pos        0U
#define CM7_AHBSCR_CTL_Msk        (0x3UL << CM7_AHBSCR_CTL_Pos)

/* CTL values - Reference: Table 3-15 */
#define CM7_AHBSCR_CTL_AHBS_DEMOTED     0x0U   /* 0b00: AHBS access priority demoted */
#define CM7_AHBSCR_CTL_SW_DEMOTED       0x1U   /* 0b01: Software access priority demoted */
#define CM7_AHBSCR_CTL_FAIRNESS_INIT    0x2U   /* 0b10: AHBS access priority demoted by INITCOUNT */
#define CM7_AHBSCR_CTL_AHBSPRI          0x3U   /* 0b11: AHBSPRI signal has control */

/**
 * TPRI - Threshold execution priority for AHBS traffic demotion
 * Bits [10:2]
 * Reference: Table 3-15 CM7_AHBSCR bit assignments
 */
#define CM7_AHBSCR_TPRI_Pos       2U
#define CM7_AHBSCR_TPRI_Msk       (0x1FFUL << CM7_AHBSCR_TPRI_Pos)

/**
 * INITCOUNT - Fairness counter initialization value
 * Bits [15:11]
 * Reference: Table 3-15 CM7_AHBSCR bit assignments
 * Use to demote access priority of the requestor selected by the CM7_AHBSCR.CTL field.
 */
#define CM7_AHBSCR_INITCOUNT_Pos  11U
#define CM7_AHBSCR_INITCOUNT_Msk  (0x1FUL << CM7_AHBSCR_INITCOUNT_Pos)

#ifdef __cplusplus
}
#endif

#endif /* CM7_TCM_H */
