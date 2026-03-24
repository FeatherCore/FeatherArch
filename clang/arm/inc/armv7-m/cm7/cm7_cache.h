/**
 * @file cm7_cache.h
 * @brief Cortex-M7 Cache Maintenance Operations
 *
 * @reference Arm Cortex-M7 Processor Technical Reference Manual
 *   - Section 3.2 Register summary, Table 3-1 System control registers
 *   - Section 3.3.3 Cache Level ID Register
 *   - Section 3.3.4 Cache Size ID Register
 *   - Section 3.3.5 Cache Size Selection Register
 *
 * @reference Arm Cortex-M7 Devices Generic User Guide
 *   - Section 4.8 Cache maintenance operations
 *   - Table 4-64 Cache maintenance operations
 */

#ifndef CM7_CACHE_H
#define CM7_CACHE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Cache Maintenance Operations
 * Reference: Arm Cortex-M7 Devices Generic User Guide, Table 4-64
 *============================================================================*/

/**
 * Instruction cache invalidate all to the Point of Unification
 * Address: 0xE000EF50
 * Type: WO, Privileged
 * Reference: Table 3-1 System control registers
 */
#define CM7_ICIALLU               (*(volatile uint32_t *)(0xE000EF50UL))

/**
 * Instruction cache invalidate by address to the PoU
 * Address: 0xE000EF58
 * Type: WO, Privileged
 * Reference: Table 3-1 System control registers
 */
#define CM7_ICIMVAU               (*(volatile uint32_t *)(0xE000EF58UL))

/**
 * Data cache invalidate by address to the Point of Coherency
 * Address: 0xE000EF5C
 * Type: WO, Privileged
 * Reference: Table 3-1 System control registers
 */
#define CM7_DCIMVAC               (*(volatile uint32_t *)(0xE000EF5CUL))

/**
 * Data cache invalidate by set/way
 * Address: 0xE000EF60
 * Type: WO, Privileged
 * Reference: Table 3-1 System control registers
 */
#define CM7_DCISW                 (*(volatile uint32_t *)(0xE000EF60UL))

/**
 * Data cache clean by address to the PoU
 * Address: 0xE000EF64
 * Type: WO, Privileged
 * Reference: Table 3-1 System control registers
 */
#define CM7_DCCMVAU               (*(volatile uint32_t *)(0xE000EF64UL))

/**
 * Data cache clean by address to the Point of Coherency
 * Address: 0xE000EF68
 * Type: WO, Privileged
 * Reference: Table 3-1 System control registers
 */
#define CM7_DCCMVAC               (*(volatile uint32_t *)(0xE000EF68UL))

/**
 * Data cache clean by set/way
 * Address: 0xE000EF6C
 * Type: WO, Privileged
 * Reference: Table 3-1 System control registers
 */
#define CM7_DCCSW                 (*(volatile uint32_t *)(0xE000EF6CUL))

/**
 * Data cache clean and invalidate by address to the Point of Coherency
 * Address: 0xE000EF70
 * Type: WO, Privileged
 * Reference: Table 3-1 System control registers
 */
#define CM7_DCCIMVAC              (*(volatile uint32_t *)(0xE000EF70UL))

/**
 * Data cache clean and invalidate by set/way
 * Address: 0xE000EF74
 * Type: WO, Privileged
 * Reference: Table 3-1 System control registers
 */
#define CM7_DCCISW                (*(volatile uint32_t *)(0xE000EF74UL))

/*============================================================================*
 * Cache Level ID Register (CLIDR)
 * Reference: Arm Cortex-M7 Processor Technical Reference Manual, Section 3.3.3
 * Address: 0xE000ED78
 * Type: RO, Privileged
 *============================================================================*/
#define CM7_CLIDR                 (*(volatile uint32_t *)(0xE000ED78UL))

/* CLIDR Bit Assignments - Reference: Table 3-5 CLIDR bit assignments */
#define CM7_CLIDR_CTYPE1_Pos      0U
#define CM7_CLIDR_CTYPE1_Msk      (0x7UL << CM7_CLIDR_CTYPE1_Pos)

/* Ctype1 values - Reference: Table 3-5 */
#define CM7_CLIDR_CTYPE1_NO_CACHE     0x0U  /* No instruction or data cache is implemented */
#define CM7_CLIDR_CTYPE1_ICACHE       0x1U  /* Instruction cache is implemented */
#define CM7_CLIDR_CTYPE1_DCACHE       0x2U  /* Data cache is implemented */
#define CM7_CLIDR_CTYPE1_IDCACHE      0x3U  /* Instruction and data cache are implemented */

#define CM7_CLIDR_LOC_Pos         24U
#define CM7_CLIDR_LOC_Msk         (0x7UL << CM7_CLIDR_LOC_Pos)

/* LoC values - Reference: Table 3-5 */
#define CM7_CLIDR_LOC_LEVEL1      0x0U  /* Level 1, if neither instruction nor data cache is implemented */
#define CM7_CLIDR_LOC_LEVEL2      0x1U  /* Level 2, if either cache is implemented */

#define CM7_CLIDR_LOUU_Pos        27U
#define CM7_CLIDR_LOUU_Msk        (0x7UL << CM7_CLIDR_LOUU_Pos)

/* LoUU values - Reference: Table 3-5 */
#define CM7_CLIDR_LOUU_LEVEL1     0x0U  /* Level 1, if neither instruction nor data cache is implemented */
#define CM7_CLIDR_LOUU_LEVEL2     0x1U  /* Level 2, if either cache is implemented */

/*============================================================================*
 * Cache Type Register (CTR)
 * Reference: Arm Cortex-M7 Processor Technical Reference Manual, Section 3.3.4
 * Address: 0xE000ED7C
 * Type: RO, Privileged
 * Reset: 0x8303C003
 *============================================================================*/
#define CM7_CTR                   (*(volatile uint32_t *)(0xE000ED7CUL))

/* CTR Bit Assignments */
#define CM7_CTR_IMINLINE_Pos      0U
#define CM7_CTR_IMINLINE_Msk      (0xFUL << CM7_CTR_IMINLINE_Pos)

#define CM7_CTR_L1IP_Pos          14U
#define CM7_CTR_L1IP_Msk          (0x3UL << CM7_CTR_L1IP_Pos)

#define CM7_CTR_DMINLINE_Pos      16U
#define CM7_CTR_DMINLINE_Msk      (0xFUL << CM7_CTR_DMINLINE_Pos)

#define CM7_CTR_ERG_Pos           20U
#define CM7_CTR_ERG_Msk           (0xFUL << CM7_CTR_ERG_Pos)

#define CM7_CTR_CWG_Pos           24U
#define CM7_CTR_CWG_Msk           (0xFUL << CM7_CTR_CWG_Pos)

#define CM7_CTR_FORMAT_Pos        29U
#define CM7_CTR_FORMAT_Msk        (0x7UL << CM7_CTR_FORMAT_Pos)

/*============================================================================*
 * Cache Size ID Register (CCSIDR)
 * Reference: Arm Cortex-M7 Processor Technical Reference Manual, Section 3.3.4
 * Address: 0xE000ED80
 * Type: RO, Privileged
 *============================================================================*/
#define CM7_CCSIDR                (*(volatile uint32_t *)(0xE000ED80UL))

/* CCSIDR Bit Assignments - Reference: Table 3-6 CCSIDR bit assignments */
#define CM7_CCSIDR_LINESIZE_Pos   0U
#define CM7_CCSIDR_LINESIZE_Msk   (0x7UL << CM7_CCSIDR_LINESIZE_Pos)

#define CM7_CCSIDR_ASSOCIATIVITY_Pos  3U
#define CM7_CCSIDR_ASSOCIATIVITY_Msk  (0x3FFUL << CM7_CCSIDR_ASSOCIATIVITY_Pos)

#define CM7_CCSIDR_NUMSETS_Pos    13U
#define CM7_CCSIDR_NUMSETS_Msk    (0x7FFFUL << CM7_CCSIDR_NUMSETS_Pos)

#define CM7_CCSIDR_WA_Pos         28U
#define CM7_CCSIDR_WA_Msk         (1UL << CM7_CCSIDR_WA_Pos)

#define CM7_CCSIDR_RA_Pos         29U
#define CM7_CCSIDR_RA_Msk         (1UL << CM7_CCSIDR_RA_Pos)

#define CM7_CCSIDR_WB_Pos         30U
#define CM7_CCSIDR_WB_Msk         (1UL << CM7_CCSIDR_WB_Pos)

#define CM7_CCSIDR_WT_Pos         31U
#define CM7_CCSIDR_WT_Msk         (1UL << CM7_CCSIDR_WT_Pos)

/*============================================================================*
 * Cache Size Selection Register (CSSELR)
 * Reference: Arm Cortex-M7 Processor Technical Reference Manual, Section 3.3.5
 * Address: 0xE000ED84
 * Type: RW, Privileged
 *============================================================================*/
#define CM7_CSSELR                (*(volatile uint32_t *)(0xE000ED84UL))

/* CSSELR Bit Assignments */
#define CM7_CSSELR_IND_Pos        0U
#define CM7_CSSELR_IND_Msk        (1UL << CM7_CSSELR_IND_Pos)

/* IND values */
#define CM7_CSSELR_IND_DATA       0U  /* Data cache */
#define CM7_CSSELR_IND_INSTR      1U  /* Instruction cache */

#define CM7_CSSELR_LEVEL_Pos      1U
#define CM7_CSSELR_LEVEL_Msk      (0x7UL << CM7_CSSELR_LEVEL_Pos)

/* LEVEL values */
#define CM7_CSSELR_LEVEL_1        0U  /* Level 1 cache */

#ifdef __cplusplus
}
#endif

#endif /* CM7_CACHE_H */
