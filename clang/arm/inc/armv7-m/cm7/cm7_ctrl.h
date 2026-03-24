/**
 * @file cm7_ctrl.h
 * @brief Cortex-M7 Control Registers
 *
 * @reference Arm Cortex-M7 Processor Technical Reference Manual
 *   - Section 3.2 Register summary, Table 3-1 System control registers
 *   - Section 3.3.1 Auxiliary Control Register
 *   - Section 3.3.8 L1 Cache Control Register
 *   - Section 3.3.9 Auxiliary Bus Fault Status Register
 *   - Section 3.3.10 Instruction Error bank Register 0-1
 *   - Section 3.3.11 Data Error bank Register 0-1
 */

#ifndef CM7_CTRL_H
#define CM7_CTRL_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Auxiliary Control Register (ACTLR)
 * Reference: Arm Cortex-M7 Processor Technical Reference Manual, Section 3.3.1
 *============================================================================*/

/**
 * ACTLR - Auxiliary Control Register
 * Address: 0xE000E008
 * Type: RW
 * Reset: 0x00000000
 * Reference: Table 3-1 System control registers
 * Purpose: Provides implementation defined configuration and control options for the processor.
 */
#define CM7_ACTLR                 (*(volatile uint32_t *)(0xE000E008UL))

/* ACTLR Bit Assignments - Reference: Table 3-3 ACTLR bit assignments */

/**
 * DISFOLD - Disables instruction folding
 * Bit [2]
 * Reference: Table 3-3 ACTLR bit assignments
 * 0: Normal operation.
 */
#define CM7_ACTLR_DISFOLD_Pos         2U
#define CM7_ACTLR_DISFOLD_Msk         (1UL << CM7_ACTLR_DISFOLD_Pos)

/**
 * FPEXCODIS - Disables FPU exception outputs
 * Bit [10]
 * Reference: Table 3-3 ACTLR bit assignments
 * 0: Normal operation.
 * 1: FPU exception outputs are disabled.
 */
#define CM7_ACTLR_FPEXCODIS_Pos       10U
#define CM7_ACTLR_FPEXCODIS_Msk       (1UL << CM7_ACTLR_FPEXCODIS_Pos)

/**
 * DISRAMODE - Disables dynamic read allocate mode for Write-Back Write-Allocate memory regions
 * Bit [11]
 * Reference: Table 3-3 ACTLR bit assignments
 * 0: Normal operation.
 * 1: Dynamic disabled.
 */
#define CM7_ACTLR_DISRAMODE_Pos       11U
#define CM7_ACTLR_DISRAMODE_Msk       (1UL << CM7_ACTLR_DISRAMODE_Pos)

/**
 * DISITMATBFLUSH - Disables ITM and DWT ATB flush
 * Bit [12]
 * Reference: Table 3-3 ACTLR bit assignments
 * 1: ITM and DWT ATB flush disabled. AFVALID is ignored and AFREADY is held HIGH.
 * Note: This bit is always 1 and therefore RAO/WI.
 */
#define CM7_ACTLR_DISITMATBFLUSH_Pos  12U
#define CM7_ACTLR_DISITMATBFLUSH_Msk  (1UL << CM7_ACTLR_DISITMATBFLUSH_Pos)

/**
 * DISBTACREAD - Disables BTAC read
 * Bit [13]
 * Reference: Table 3-3 ACTLR bit assignments
 * 0: Normal operation.
 * 1: BTAC is not used and only static branch prediction can occur.
 */
#define CM7_ACTLR_DISBTACREAD_Pos     13U
#define CM7_ACTLR_DISBTACREAD_Msk     (1UL << CM7_ACTLR_DISBTACREAD_Pos)

/**
 * DISBTACALLOC - Disables BTAC allocation
 * Bit [14]
 * Reference: Table 3-3 ACTLR bit assignments
 * 0: Normal operation.
 * 1: No new entries are allocated in Branch Target Address Cache (BTAC), but existing entries can be updated.
 */
#define CM7_ACTLR_DISBTACALLOC_Pos    14U
#define CM7_ACTLR_DISBTACALLOC_Msk    (1UL << CM7_ACTLR_DISBTACALLOC_Pos)

/**
 * DISCRITAXIRUR - Disables critical AXI Read-Under-Read
 * Bit [15]
 * Reference: Table 3-3 ACTLR bit assignments
 * 0: Normal operation.
 * 1: An AXI read to Strongly-ordered or Device memory, or an LDREX to shared memory,
 *    is not put on AXI if there are any outstanding reads on AXI.
 */
#define CM7_ACTLR_DISCRITAXIRUR_Pos   15U
#define CM7_ACTLR_DISCRITAXIRUR_Msk   (1UL << CM7_ACTLR_DISCRITAXIRUR_Pos)

/**
 * DISDI - Disables dual-issue
 * Bits [20:16]
 * Reference: Table 3-3 ACTLR bit assignments
 * 0: Normal operation.
 * 1: Nothing can be dual-issued when this instruction type is in channel 0.
 * Bit [20]: VFP
 * Bit [19]: Integer MAC and MUL
 * Bit [18]: Loads to PC
 * Bit [17]: Indirect branches, but not loads to PC
 * Bit [16]: Direct branches
 */
#define CM7_ACTLR_DISDI_Pos           16U
#define CM7_ACTLR_DISDI_Msk           (0x1FUL << CM7_ACTLR_DISDI_Pos)
#define CM7_ACTLR_DISDI_VFP           (1UL << 20U)
#define CM7_ACTLR_DISDI_MAC           (1UL << 19U)
#define CM7_ACTLR_DISDI_LDPC          (1UL << 18U)
#define CM7_ACTLR_DISDI_IBR           (1UL << 17U)
#define CM7_ACTLR_DISDI_DBR           (1UL << 16U)

/**
 * DISISSCH1 - Disables issue in channel 1
 * Bits [25:21]
 * Reference: Table 3-3 ACTLR bit assignments
 * 0: Normal operation.
 * 1: Instruction type must not be issued in channel 1.
 * Bit [25]: VFP
 * Bit [24]: Integer MAC and MUL
 * Bit [23]: Loads to PC
 * Bit [22]: Indirect branches, but not loads to PC
 * Bit [21]: Direct branches
 */
#define CM7_ACTLR_DISISSCH1_Pos       21U
#define CM7_ACTLR_DISISSCH1_Msk       (0x1FUL << CM7_ACTLR_DISISSCH1_Pos)
#define CM7_ACTLR_DISISSCH1_VFP       (1UL << 25U)
#define CM7_ACTLR_DISISSCH1_MAC       (1UL << 24U)
#define CM7_ACTLR_DISISSCH1_LDPC      (1UL << 23U)
#define CM7_ACTLR_DISISSCH1_IBR       (1UL << 22U)
#define CM7_ACTLR_DISISSCH1_DBR       (1UL << 21U)

/**
 * DISDYNADD - Disables dynamic allocation of ADD and SUB instructions
 * Bit [26]
 * Reference: Table 3-3 ACTLR bit assignments
 * 0: Normal operation. Some ADD and SUB instructions are resolved in EX1.
 * 1: All ADD and SUB instructions are resolved in EX2.
 */
#define CM7_ACTLR_DISDYNADD_Pos       26U
#define CM7_ACTLR_DISDYNADD_Msk       (1UL << CM7_ACTLR_DISDYNADD_Pos)

/**
 * DISCRITAXIRUW - Disable critical AXI read-under-write
 * Bit [27]
 * Reference: Table 3-3 ACTLR bit assignments
 * 0: Normal operation. This is backwards compatible with r0.
 * 1: AXI reads to DEV/SO memory. Exclusive reads to shared memory are not initiated
 *    on the AXIM AR channel until all outstanding stores on AXI are complete.
 */
#define CM7_ACTLR_DISCRITAXIRUW_Pos   27U
#define CM7_ACTLR_DISCRITAXIRUW_Msk   (1UL << CM7_ACTLR_DISCRITAXIRUW_Pos)

/**
 * DISFPUISSOPT - Disables FPU issuing optimization
 * Bit [28]
 * Reference: Table 3-3 ACTLR bit assignments
 * 0: Normal operation.
 */
#define CM7_ACTLR_DISFPUISSOPT_Pos    28U
#define CM7_ACTLR_DISFPUISSOPT_Msk    (1UL << CM7_ACTLR_DISFPUISSOPT_Pos)

/*============================================================================*
 * L1 Cache Control Register (CM7_CACR)
 * Reference: Arm Cortex-M7 Processor Technical Reference Manual, Section 3.3.8
 *============================================================================*/

/**
 * CM7_CACR - L1 Cache Control Register
 * Address: 0xE000EF9C
 * Type: RW, Privileged
 * Reference: Table 3-1 System control registers
 * Purpose: Controls the L1 ECC and the L1 cache coherency usage model.
 */
#define CM7_CACR                  (*(volatile uint32_t *)(0xE000EF9CUL))

/* CM7_CACR Bit Assignments - Reference: Table 3-11 CM7_CACR bit assignments */

/**
 * SIWT - Shared cacheable-is-WT for data cache
 * Bit [0]
 * Reference: Table 3-11 CM7_CACR bit assignments
 * 0: Normal Cacheable Shared locations are treated as being Non-cacheable.
 *    Programmed inner cacheability attributes are ignored. This is the default mode
 *    of operation for Shared memory.
 * 1: Normal Cacheable shared locations are treated as Write-Through.
 *    Programmed inner cacheability attributes are ignored.
 */
#define CM7_CACR_SIWT_Pos         0U
#define CM7_CACR_SIWT_Msk         (1UL << CM7_CACR_SIWT_Pos)

/**
 * ECCDIS - Enables ECC in the instruction and data cache
 * Bit [1]
 * Reference: Table 3-11 CM7_CACR bit assignments
 * 0: Enables ECC in the instruction and data cache.
 * 1: Disables ECC in the instruction and data cache.
 */
#define CM7_CACR_ECCDIS_Pos       1U
#define CM7_CACR_ECCDIS_Msk       (1UL << CM7_CACR_ECCDIS_Pos)

/**
 * FORCEWT - Enables Force Write-Through in the data cache
 * Bit [2]
 * Reference: Table 3-11 CM7_CACR bit assignments
 * 0: Disables Force Write-Through.
 * 1: Enables Force Write-Through. All Cacheable memory regions are treated as Write-Through.
 */
#define CM7_CACR_FORCEWT_Pos      2U
#define CM7_CACR_FORCEWT_Msk      (1UL << CM7_CACR_FORCEWT_Pos)

/*============================================================================*
 * Auxiliary Bus Fault Status Register (CM7_ABFSR)
 * Reference: Arm Cortex-M7 Processor Technical Reference Manual, Section 3.3.9
 *============================================================================*/

/**
 * CM7_ABFSR - Auxiliary Bus Fault Status Register
 * Address: 0xE000EFA8
 * Type: RW, Privileged
 * Reference: Table 3-1 System control registers
 * Purpose: Stores information on the source of asynchronous bus faults.
 */
#define CM7_ABFSR                 (*(volatile uint32_t *)(0xE000EFA8UL))

/* CM7_ABFSR Bit Assignments - Reference: Table 3-12 CM7_ABFSR bit assignments */

/**
 * ITCM - Asynchronous fault on ITCM interface
 * Bit [0]
 * Reference: Table 3-12 CM7_ABFSR bit assignments
 */
#define CM7_ABFSR_ITCM_Pos        0U
#define CM7_ABFSR_ITCM_Msk        (1UL << CM7_ABFSR_ITCM_Pos)

/**
 * DTCM - Asynchronous fault on DTCM interface
 * Bit [1]
 * Reference: Table 3-12 CM7_ABFSR bit assignments
 */
#define CM7_ABFSR_DTCM_Pos        1U
#define CM7_ABFSR_DTCM_Msk        (1UL << CM7_ABFSR_DTCM_Pos)

/**
 * AHBP - Asynchronous fault on AHBP interface
 * Bit [2]
 * Reference: Table 3-12 CM7_ABFSR bit assignments
 */
#define CM7_ABFSR_AHBP_Pos        2U
#define CM7_ABFSR_AHBP_Msk        (1UL << CM7_ABFSR_AHBP_Pos)

/**
 * AXIM - Asynchronous fault on AXIM interface
 * Bit [3]
 * Reference: Table 3-12 CM7_ABFSR bit assignments
 */
#define CM7_ABFSR_AXIM_Pos        3U
#define CM7_ABFSR_AXIM_Msk        (1UL << CM7_ABFSR_AXIM_Pos)

/**
 * EPPB - Asynchronous fault on EPPB interface
 * Bit [4]
 * Reference: Table 3-12 CM7_ABFSR bit assignments
 */
#define CM7_ABFSR_EPPB_Pos        4U
#define CM7_ABFSR_EPPB_Msk        (1UL << CM7_ABFSR_EPPB_Pos)

/**
 * AXIMTYPE - Indicates the type of fault on the AXIM interface
 * Bits [9:8]
 * Reference: Table 3-12 CM7_ABFSR bit assignments
 * Only valid when AXIM is 1.
 */
#define CM7_ABFSR_AXIMTYPE_Pos    8U
#define CM7_ABFSR_AXIMTYPE_Msk    (0x3UL << CM7_ABFSR_AXIMTYPE_Pos)

/* AXIMTYPE values - Reference: Table 3-12 */
#define CM7_ABFSR_AXIMTYPE_OKAY   0x0U   /* 0b00: OKAY */
#define CM7_ABFSR_AXIMTYPE_EXOKAY 0x1U   /* 0b01: EXOKAY */
#define CM7_ABFSR_AXIMTYPE_SLVERR 0x2U   /* 0b10: SLVERR */
#define CM7_ABFSR_AXIMTYPE_DECERR 0x3U   /* 0b11: DECERR */

/*============================================================================*
 * Instruction Error Bank Registers (CM7_IEBR0, CM7_IEBR1)
 * Reference: Arm Cortex-M7 Processor Technical Reference Manual, Section 3.3.10
 *============================================================================*/

/**
 * CM7_IEBR0 - Instruction Error Bank Register 0
 * Address: 0xE000EFB0
 * Type: RW, Privileged
 * Reference: Table 3-1 System control registers
 * Purpose: Stores information about the error detected in the instruction cache during a cache lookup.
 * Note: Only present if ECC is present, otherwise RAZ/WI.
 */
#define CM7_IEBR0                 (*(volatile uint32_t *)(0xE000EFB0UL))

/**
 * CM7_IEBR1 - Instruction Error Bank Register 1
 * Address: 0xE000EFB4
 * Type: RW, Privileged
 * Reference: Table 3-1 System control registers
 */
#define CM7_IEBR1                 (*(volatile uint32_t *)(0xE000EFB4UL))

/* IEBR Bit Assignments - Reference: Table 3-13 IEBR0-1 bit assignments */

/**
 * Valid - Indicates whether the entry is valid or not
 * Bit [0]
 * Reference: Table 3-13 IEBR0-1 bit assignments
 * 0: Entry is invalid.
 * 1: Entry is valid.
 * Reset by powerup reset to 0.
 */
#define CM7_IEBR_VALID_Pos        0U
#define CM7_IEBR_VALID_Msk        (1UL << CM7_IEBR_VALID_Pos)

/**
 * Locked - Indicates whether the location is locked or not locked
 * Bit [1]
 * Reference: Table 3-13 IEBR0-1 bit assignments
 * 0: Location is not locked and available for hardware to allocate.
 * 1: Location is locked by software. Hardware is not allowed to allocate to this entry.
 * Reset by powerup reset to 0.
 */
#define CM7_IEBR_LOCKED_Pos       1U
#define CM7_IEBR_LOCKED_Msk       (1UL << CM7_IEBR_LOCKED_Pos)

/**
 * RAM location - Indicates the location in instruction cache RAM
 * Bits [15:2]
 * Reference: Table 3-13 IEBR0-1 bit assignments
 * [14]: Way
 * [13:4]: Index
 * [3:2]: Line doubleword offset
 */
#define CM7_IEBR_LOCATION_Pos     2U
#define CM7_IEBR_LOCATION_Msk     (0x3FFFUL << CM7_IEBR_LOCATION_Pos)

/**
 * RAM bank - Indicates which RAM bank to use
 * Bit [16]
 * Reference: Table 3-13 IEBR0-1 bit assignments
 * 0: Tag RAM
 * 1: Data RAM
 */
#define CM7_IEBR_BANK_Pos         16U
#define CM7_IEBR_BANK_Msk         (1UL << CM7_IEBR_BANK_Pos)
#define CM7_IEBR_BANK_TAG         0U
#define CM7_IEBR_BANK_DATA        1U

/**
 * Type of error - Indicates the error type
 * Bit [17]
 * Reference: Table 3-13 IEBR0-1 bit assignments
 * 0: Correctable error.
 * 1: Non-correctable error.
 */
#define CM7_IEBR_TYPE_Pos         17U
#define CM7_IEBR_TYPE_Msk         (1UL << CM7_IEBR_TYPE_Pos)
#define CM7_IEBR_TYPE_CORRECTABLE     0U
#define CM7_IEBR_TYPE_UNCORRECTABLE   1U

/*============================================================================*
 * Data Error Bank Registers (CM7_DEBR0, CM7_DEBR1)
 * Reference: Arm Cortex-M7 Processor Technical Reference Manual, Section 3.3.11
 *============================================================================*/

/**
 * CM7_DEBR0 - Data Error Bank Register 0
 * Address: 0xE000EFB8
 * Type: RW, Privileged
 * Reference: Table 3-1 System control registers
 * Purpose: Stores information about the error detected in the data cache during a cache lookup.
 * Note: Only present if ECC is present, otherwise RAZ/WI.
 */
#define CM7_DEBR0                 (*(volatile uint32_t *)(0xE000EFB8UL))

/**
 * CM7_DEBR1 - Data Error Bank Register 1
 * Address: 0xE000EFBC
 * Type: RW, Privileged
 * Reference: Table 3-1 System control registers
 */
#define CM7_DEBR1                 (*(volatile uint32_t *)(0xE000EFBCUL))

/* DEBR Bit Assignments - Reference: Table 3-14 DEBR0-1 bit assignments */

/**
 * Valid - Indicates whether the entry is valid or not
 * Bit [0]
 * Reference: Table 3-14 DEBR0-1 bit assignments
 * 0: Entry is invalid.
 * 1: Entry is valid.
 * Reset by powerup reset to 0.
 */
#define CM7_DEBR_VALID_Pos        0U
#define CM7_DEBR_VALID_Msk        (1UL << CM7_DEBR_VALID_Pos)

/**
 * Locked - Indicates whether the location is locked or not locked
 * Bit [1]
 * Reference: Table 3-14 DEBR0-1 bit assignments
 * 0: Location is not locked and available for hardware to allocate.
 * 1: Location is locked by software. Hardware is not allowed to allocate to this entry.
 * Reset by powerup reset to 0.
 */
#define CM7_DEBR_LOCKED_Pos       1U
#define CM7_DEBR_LOCKED_Msk       (1UL << CM7_DEBR_LOCKED_Pos)

/**
 * RAM location - Indicates the data cache RAM location
 * Bits [15:2]
 * Reference: Table 3-14 DEBR0-1 bit assignments
 * [15:14]: Way
 * [13:5]: Index
 * [4:2]: Line word offset
 */
#define CM7_DEBR_LOCATION_Pos     2U
#define CM7_DEBR_LOCATION_Msk     (0x7FFFUL << CM7_DEBR_LOCATION_Pos)

/**
 * RAM bank - Indicates which RAM bank to use
 * Bit [16]
 * Reference: Table 3-14 DEBR0-1 bit assignments
 * 0: Tag RAM
 * 1: Data RAM
 */
#define CM7_DEBR_BANK_Pos         16U
#define CM7_DEBR_BANK_Msk         (1UL << CM7_DEBR_BANK_Pos)
#define CM7_DEBR_BANK_TAG         0U
#define CM7_DEBR_BANK_DATA        1U

/**
 * Type of error - Indicates the error type
 * Bit [17]
 * Reference: Table 3-14 DEBR0-1 bit assignments
 * 0: Correctable error.
 * 1: Non-correctable error.
 */
#define CM7_DEBR_TYPE_Pos         17U
#define CM7_DEBR_TYPE_Msk         (1UL << CM7_DEBR_TYPE_Pos)
#define CM7_DEBR_TYPE_CORRECTABLE     0U
#define CM7_DEBR_TYPE_UNCORRECTABLE   1U

#ifdef __cplusplus
}
#endif

#endif /* CM7_CTRL_H */
