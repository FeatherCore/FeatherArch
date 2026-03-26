/*
 * arm_v7m_mpu.h
 * Memory Protection Unit (MPU) Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.5 (PMSAv7)
 */

#ifndef ARM_V7M_MPU_H
#define ARM_V7M_MPU_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Compiler Abstraction - Inline Definition
 * This library only supports Clang/LLVM compiler
 *============================================================================*/

#if defined(__clang__)
    #define ARM_V7M_MPU_INLINE static inline __attribute__((always_inline))
#else
    #error "This library requires Clang/LLVM compiler. Please use clang to compile this code."
#endif

/*============================================================================*
 * MPU Base Address (Architecture defined)
 * Reference: ARMv7-M Architecture Reference Manual, Table B3-11
 *============================================================================*/

#define ARM_V7M_MPU_BASE            0xE000ED90UL

/*============================================================================*
 * MPU Register Offsets
 *============================================================================*/

#define ARM_V7M_MPU_TYPE_OFFSET     0x00
#define ARM_V7M_MPU_CTRL_OFFSET     0x04
#define ARM_V7M_MPU_RNR_OFFSET      0x08
#define ARM_V7M_MPU_RBAR_OFFSET     0x0C
#define ARM_V7M_MPU_RASR_OFFSET     0x10

/*============================================================================*
 * MPU Alias Register Offsets (for efficient multi-region configuration)
 * Reference: B3.5.10 MPU alias register support
 *============================================================================*/

#define ARM_V7M_MPU_RBAR_A1_OFFSET  0x14
#define ARM_V7M_MPU_RASR_A1_OFFSET  0x18
#define ARM_V7M_MPU_RBAR_A2_OFFSET  0x1C
#define ARM_V7M_MPU_RASR_A2_OFFSET  0x20
#define ARM_V7M_MPU_RBAR_A3_OFFSET  0x24
#define ARM_V7M_MPU_RASR_A3_OFFSET  0x28

/*============================================================================*
 * MPU_TYPE Register Bit Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.5.5
 *============================================================================*/

#define ARM_V7M_MPU_TYPE_DREGION_Pos    8U
#define ARM_V7M_MPU_TYPE_DREGION_Msk    (0xFFUL << ARM_V7M_MPU_TYPE_DREGION_Pos)

#define ARM_V7M_MPU_TYPE_IREGION_Pos    16U
#define ARM_V7M_MPU_TYPE_IREGION_Msk    (0xFFUL << ARM_V7M_MPU_TYPE_IREGION_Pos)

#define ARM_V7M_MPU_TYPE_SEPARATE_Pos   0U
#define ARM_V7M_MPU_TYPE_SEPARATE_Msk   (1UL << ARM_V7M_MPU_TYPE_SEPARATE_Pos)

/*============================================================================*
 * MPU_CTRL Register Bit Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.5.6
 *============================================================================*/

#define ARM_V7M_MPU_CTRL_PRIVDEFENA_Pos 2U
#define ARM_V7M_MPU_CTRL_PRIVDEFENA_Msk (1UL << ARM_V7M_MPU_CTRL_PRIVDEFENA_Pos)

#define ARM_V7M_MPU_CTRL_HFNMIENA_Pos   1U
#define ARM_V7M_MPU_CTRL_HFNMIENA_Msk   (1UL << ARM_V7M_MPU_CTRL_HFNMIENA_Pos)

#define ARM_V7M_MPU_CTRL_ENABLE_Pos     0U
#define ARM_V7M_MPU_CTRL_ENABLE_Msk     (1UL << ARM_V7M_MPU_CTRL_ENABLE_Pos)

/*============================================================================*
 * MPU_RNR Register Bit Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.5.7
 *============================================================================*/

#define ARM_V7M_MPU_RNR_REGION_Pos      0U
#define ARM_V7M_MPU_RNR_REGION_Msk      (0xFFUL << ARM_V7M_MPU_RNR_REGION_Pos)

/*============================================================================*
 * MPU_RBAR Register Bit Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.5.8
 *============================================================================*/

#define ARM_V7M_MPU_RBAR_ADDR_Pos       5U
#define ARM_V7M_MPU_RBAR_ADDR_Msk       (0x7FFFFFFUL << ARM_V7M_MPU_RBAR_ADDR_Pos)

#define ARM_V7M_MPU_RBAR_VALID_Pos      4U
#define ARM_V7M_MPU_RBAR_VALID_Msk      (1UL << ARM_V7M_MPU_RBAR_VALID_Pos)

#define ARM_V7M_MPU_RBAR_REGION_Pos     0U
#define ARM_V7M_MPU_RBAR_REGION_Msk     (0x0FUL << ARM_V7M_MPU_RBAR_REGION_Pos)

/*============================================================================*
 * MPU_RASR Register Bit Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.5.9
 *============================================================================*/

/* Attributes field (bits [31:16]) */
#define ARM_V7M_MPU_RASR_ATTRS_Pos      16U
#define ARM_V7M_MPU_RASR_ATTRS_Msk      (0xFFFFUL << ARM_V7M_MPU_RASR_ATTRS_Pos)

/* XN (Execute Never) bit */
#define ARM_V7M_MPU_RASR_XN_Pos         28U
#define ARM_V7M_MPU_RASR_XN_Msk         (1UL << ARM_V7M_MPU_RASR_XN_Pos)

/* AP (Access Permission) bits */
#define ARM_V7M_MPU_RASR_AP_Pos         24U
#define ARM_V7M_MPU_RASR_AP_Msk         (0x07UL << ARM_V7M_MPU_RASR_AP_Pos)

/* TEX (Type Extension) bits */
#define ARM_V7M_MPU_RASR_TEX_Pos        19U
#define ARM_V7M_MPU_RASR_TEX_Msk        (0x07UL << ARM_V7M_MPU_RASR_TEX_Pos)

/* S (Shareable) bit */
#define ARM_V7M_MPU_RASR_S_Pos          18U
#define ARM_V7M_MPU_RASR_S_Msk          (1UL << ARM_V7M_MPU_RASR_S_Pos)

/* C (Cacheable) bit */
#define ARM_V7M_MPU_RASR_C_Pos          17U
#define ARM_V7M_MPU_RASR_C_Msk          (1UL << ARM_V7M_MPU_RASR_C_Pos)

/* B (Bufferable) bit */
#define ARM_V7M_MPU_RASR_B_Pos          16U
#define ARM_V7M_MPU_RASR_B_Msk          (1UL << ARM_V7M_MPU_RASR_B_Pos)

/* SRD (Subregion Disable) bits */
#define ARM_V7M_MPU_RASR_SRD_Pos        8U
#define ARM_V7M_MPU_RASR_SRD_Msk        (0xFFUL << ARM_V7M_MPU_RASR_SRD_Pos)

/* SIZE field */
#define ARM_V7M_MPU_RASR_SIZE_Pos       1U
#define ARM_V7M_MPU_RASR_SIZE_Msk       (0x1FUL << ARM_V7M_MPU_RASR_SIZE_Pos)

/* ENABLE bit */
#define ARM_V7M_MPU_RASR_ENABLE_Pos     0U
#define ARM_V7M_MPU_RASR_ENABLE_Msk     (1UL << ARM_V7M_MPU_RASR_ENABLE_Pos)

/*============================================================================*
 * MemManage Fault Status Register (MMFSR) Definitions
 * Part of CFSR register at 0xE000ED28
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.2.14
 *============================================================================*/

#define ARM_V7M_MMFSR_MMARVALID_Pos     7U
#define ARM_V7M_MMFSR_MMARVALID_Msk     (1UL << ARM_V7M_MMFSR_MMARVALID_Pos)

#define ARM_V7M_MMFSR_MLSPERR_Pos       5U
#define ARM_V7M_MMFSR_MLSPERR_Msk       (1UL << ARM_V7M_MMFSR_MLSPERR_Pos)

#define ARM_V7M_MMFSR_MSTKERR_Pos       4U
#define ARM_V7M_MMFSR_MSTKERR_Msk       (1UL << ARM_V7M_MMFSR_MSTKERR_Pos)

#define ARM_V7M_MMFSR_MUNSTKERR_Pos     3U
#define ARM_V7M_MMFSR_MUNSTKERR_Msk     (1UL << ARM_V7M_MMFSR_MUNSTKERR_Pos)

#define ARM_V7M_MMFSR_DACCVIOL_Pos      1U
#define ARM_V7M_MMFSR_DACCVIOL_Msk      (1UL << ARM_V7M_MMFSR_DACCVIOL_Pos)

#define ARM_V7M_MMFSR_IACCVIOL_Pos      0U
#define ARM_V7M_MMFSR_IACCVIOL_Msk      (1UL << ARM_V7M_MMFSR_IACCVIOL_Pos)

/*============================================================================*
 * Access Permission (AP) Encoding
 * Reference: ARMv7-M Architecture Reference Manual, Table B3-15
 *============================================================================*/

#define ARM_V7M_MPU_AP_NONE             0x00U  /* No access */
#define ARM_V7M_MPU_AP_PRIV_RW          0x01U  /* Privileged: RW, Unprivileged: None */
#define ARM_V7M_MPU_AP_PRIV_RW_USER_RO  0x02U  /* Privileged: RW, Unprivileged: RO */
#define ARM_V7M_MPU_AP_FULL_ACCESS      0x03U  /* Privileged: RW, Unprivileged: RW */
#define ARM_V7M_MPU_AP_PRIV_RO          0x05U  /* Privileged: RO, Unprivileged: None */
#define ARM_V7M_MPU_AP_RO               0x06U  /* Privileged: RO, Unprivileged: RO */

/*============================================================================*
 * Memory Attribute Encodings (TEX, C, B, S)
 * Reference: ARMv7-M Architecture Reference Manual, Table B3-13
 *============================================================================*/

/* Strongly-ordered memory: TEX=000, C=0, B=0 */
#define ARM_V7M_MPU_ATTR_STRONGLY_ORDERED   0x00U

/* Device memory (shareable): TEX=000, C=0, B=1 */
#define ARM_V7M_MPU_ATTR_DEVICE_SHARED      0x01U

/* Device memory (non-shareable): TEX=010, C=0, B=0 */
#define ARM_V7M_MPU_ATTR_DEVICE             0x02U

/* Normal memory (non-cacheable): TEX=001, C=0, B=0 */
#define ARM_V7M_MPU_ATTR_NORMAL             0x04U

/* Normal memory (write-back, write/read allocate): TEX=001, C=1, B=1 */
#define ARM_V7M_MPU_ATTR_NORMAL_WB_WRA      0x07U

/* Normal memory (write-through, no write allocate): TEX=000, C=1, B=0 */
#define ARM_V7M_MPU_ATTR_NORMAL_WT          0x02U

/* Normal memory (write-back, no write allocate): TEX=000, C=1, B=1 */
#define ARM_V7M_MPU_ATTR_NORMAL_WB          0x03U

/*============================================================================*
 * Shareable Bit
 *============================================================================*/

#define ARM_V7M_MPU_SHAREABLE           (1UL << ARM_V7M_MPU_RASR_S_Pos)
#define ARM_V7M_MPU_NON_SHAREABLE       0UL

/*============================================================================*
 * Execute Never Bit
 *============================================================================*/

#define ARM_V7M_MPU_XN                  (1UL << ARM_V7M_MPU_RASR_XN_Pos)
#define ARM_V7M_MPU_EXEC_OK             0UL

/*============================================================================*
 * Region Size Constants (SIZE field value for 2^(SIZE+1) bytes)
 * Minimum size is 32 bytes (SIZE=4), maximum is 4GB (SIZE=31)
 *============================================================================*/

#define ARM_V7M_MPU_REGION_SIZE_32B     4U
#define ARM_V7M_MPU_REGION_SIZE_64B     5U
#define ARM_V7M_MPU_REGION_SIZE_128B    6U
#define ARM_V7M_MPU_REGION_SIZE_256B    7U
#define ARM_V7M_MPU_REGION_SIZE_512B    8U
#define ARM_V7M_MPU_REGION_SIZE_1KB     9U
#define ARM_V7M_MPU_REGION_SIZE_2KB     10U
#define ARM_V7M_MPU_REGION_SIZE_4KB     11U
#define ARM_V7M_MPU_REGION_SIZE_8KB     12U
#define ARM_V7M_MPU_REGION_SIZE_16KB    13U
#define ARM_V7M_MPU_REGION_SIZE_32KB    14U
#define ARM_V7M_MPU_REGION_SIZE_64KB    15U
#define ARM_V7M_MPU_REGION_SIZE_128KB   16U
#define ARM_V7M_MPU_REGION_SIZE_256KB   17U
#define ARM_V7M_MPU_REGION_SIZE_512KB   18U
#define ARM_V7M_MPU_REGION_SIZE_1MB     19U
#define ARM_V7M_MPU_REGION_SIZE_2MB     20U
#define ARM_V7M_MPU_REGION_SIZE_4MB     21U
#define ARM_V7M_MPU_REGION_SIZE_8MB     22U
#define ARM_V7M_MPU_REGION_SIZE_16MB    23U
#define ARM_V7M_MPU_REGION_SIZE_32MB    24U
#define ARM_V7M_MPU_REGION_SIZE_64MB    25U
#define ARM_V7M_MPU_REGION_SIZE_128MB   26U
#define ARM_V7M_MPU_REGION_SIZE_256MB   27U
#define ARM_V7M_MPU_REGION_SIZE_512MB   28U
#define ARM_V7M_MPU_REGION_SIZE_1GB     29U
#define ARM_V7M_MPU_REGION_SIZE_2GB     30U
#define ARM_V7M_MPU_REGION_SIZE_4GB     31U

/*============================================================================*
 * Helper Macros for Building RASR Attributes
 *============================================================================*/

/**
 * @brief Build RASR attribute field from individual components
 * @param ap  Access permission (ARM_V7M_MPU_AP_*)
 * @param tex Type extension (0-7)
 * @param s   Shareable (0 or 1)
 * @param c   Cacheable (0 or 1)
 * @param b   Bufferable (0 or 1)
 * @param xn  Execute never (0 or 1)
 */
#define ARM_V7M_MPU_BUILD_ATTR(ap, tex, s, c, b, xn) \
    (((uint32_t)(xn)  << ARM_V7M_MPU_RASR_XN_Pos)  | \
     ((uint32_t)(ap)  << ARM_V7M_MPU_RASR_AP_Pos)  | \
     ((uint32_t)(tex) << ARM_V7M_MPU_RASR_TEX_Pos) | \
     ((uint32_t)(s)   << ARM_V7M_MPU_RASR_S_Pos)   | \
     ((uint32_t)(c)   << ARM_V7M_MPU_RASR_C_Pos)   | \
     ((uint32_t)(b)   << ARM_V7M_MPU_RASR_B_Pos))

/**
 * @brief Build complete RASR value
 * @param attrs  Attributes from ARM_V7M_MPU_BUILD_ATTR
 * @param srd    Subregion disable bits (0-255)
 * @param size   Region size code (ARM_V7M_MPU_REGION_SIZE_*)
 * @param enable Region enable (0 or 1)
 */
#define ARM_V7M_MPU_BUILD_RASR(attrs, srd, size, enable) \
    (((uint32_t)(attrs) << ARM_V7M_MPU_RASR_ATTRS_Pos) | \
     ((uint32_t)(srd)   << ARM_V7M_MPU_RASR_SRD_Pos)   | \
     ((uint32_t)(size)  << ARM_V7M_MPU_RASR_SIZE_Pos)  | \
     ((uint32_t)(enable) << ARM_V7M_MPU_RASR_ENABLE_Pos))

/**
 * @brief Build RBAR value with VALID bit set
 * @param addr   Base address (must be aligned to region size)
 * @param region Region number (0-15)
 */
#define ARM_V7M_MPU_BUILD_RBAR(addr, region) \
    (((uint32_t)(addr) & ARM_V7M_MPU_RBAR_ADDR_Msk) | \
     ARM_V7M_MPU_RBAR_VALID_Msk | \
     ((uint32_t)(region) & ARM_V7M_MPU_RBAR_REGION_Msk))

/*============================================================================*
 * Predefined Common Attribute Combinations
 *============================================================================*/

/* Normal memory, cacheable, shareable, full access, executable */
#define ARM_V7M_MPU_ATTR_NORMAL_CACHEABLE \
    ARM_V7M_MPU_BUILD_ATTR(ARM_V7M_MPU_AP_FULL_ACCESS, 0x01U, 1U, 1U, 1U, 0U)

/* Normal memory, cacheable, shareable, full access, execute never */
#define ARM_V7M_MPU_ATTR_NORMAL_CACHEABLE_XN \
    ARM_V7M_MPU_BUILD_ATTR(ARM_V7M_MPU_AP_FULL_ACCESS, 0x01U, 1U, 1U, 1U, 1U)

/* Normal memory, non-cacheable, full access, executable */
#define ARM_V7M_MPU_ATTR_NORMAL_NONCACHE \
    ARM_V7M_MPU_BUILD_ATTR(ARM_V7M_MPU_AP_FULL_ACCESS, 0x01U, 1U, 0U, 0U, 0U)

/* Device memory, shareable, full access, execute never */
#define ARM_V7M_MPU_ATTR_DEVICE \
    ARM_V7M_MPU_BUILD_ATTR(ARM_V7M_MPU_AP_FULL_ACCESS, 0x00U, 1U, 0U, 1U, 1U)

/* Device memory, non-shareable, full access, execute never */
#define ARM_V7M_MPU_ATTR_DEVICE_NONSHARE \
    ARM_V7M_MPU_BUILD_ATTR(ARM_V7M_MPU_AP_FULL_ACCESS, 0x02U, 0U, 0U, 0U, 1U)

/* Strongly ordered memory, full access, execute never */
#define ARM_V7M_MPU_ATTR_STRONGLY_ORDERED \
    ARM_V7M_MPU_BUILD_ATTR(ARM_V7M_MPU_AP_FULL_ACCESS, 0x00U, 1U, 0U, 0U, 1U)

/* Flash memory: Normal, write-through, full access, executable */
#define ARM_V7M_MPU_ATTR_FLASH \
    ARM_V7M_MPU_BUILD_ATTR(ARM_V7M_MPU_AP_FULL_ACCESS, 0x00U, 0U, 1U, 0U, 0U)

/* SRAM memory: Normal, write-back, full access, executable */
#define ARM_V7M_MPU_ATTR_SRAM \
    ARM_V7M_MPU_BUILD_ATTR(ARM_V7M_MPU_AP_FULL_ACCESS, 0x01U, 1U, 1U, 1U, 0U)

/* Peripheral memory: Device, execute never */
#define ARM_V7M_MPU_ATTR_PERIPHERAL \
    ARM_V7M_MPU_BUILD_ATTR(ARM_V7M_MPU_AP_FULL_ACCESS, 0x00U, 1U, 0U, 1U, 1U)

/*============================================================================*
 * MPU Type Definitions
 *============================================================================*/

typedef struct {
    volatile const uint32_t TYPE;   /*!< Offset: 0x00 (R/ )  MPU Type Register */
    volatile uint32_t CTRL;         /*!< Offset: 0x04 (R/W)  MPU Control Register */
    volatile uint32_t RNR;          /*!< Offset: 0x08 (R/W)  MPU Region Number Register */
    volatile uint32_t RBAR;         /*!< Offset: 0x0C (R/W)  MPU Region Base Address Register */
    volatile uint32_t RASR;         /*!< Offset: 0x10 (R/W)  MPU Region Attribute and Size Register */
} arm_v7m_mpu_regs_t;

#define MPU                 ((arm_v7m_mpu_regs_t *)ARM_V7M_MPU_BASE)

/*============================================================================*
 * MPU Region Configuration Structure
 *============================================================================*/

typedef struct {
    uint32_t base_addr;     /*!< Region base address */
    uint32_t size_code;     /*!< Region size code (ARM_V7M_MPU_REGION_SIZE_*) */
    uint32_t attrs;         /*!< Region attributes (use ARM_V7M_MPU_BUILD_ATTR) */
    uint32_t srd;           /*!< Subregion disable bits (0-255) */
    uint32_t enable;        /*!< Region enable (0 or 1) */
} arm_v7m_mpu_region_cfg_t;

/*============================================================================*
 * Inline Functions - MPU Basic Operations
 * These are simple register operations suitable for inlining
 *============================================================================*/

/**
 * @brief Check if MPU is present
 * @return 1 if MPU is present, 0 otherwise
 */
ARM_V7M_MPU_INLINE uint32_t arm_v7m_mpu_is_present(void)
{
    return ((MPU->TYPE & ARM_V7M_MPU_TYPE_DREGION_Msk) != 0U) ? 1U : 0U;
}

/**
 * @brief Get the number of MPU regions supported
 * @return Number of supported regions (0 if MPU not implemented)
 */
ARM_V7M_MPU_INLINE uint32_t arm_v7m_mpu_get_region_count(void)
{
    return (MPU->TYPE & ARM_V7M_MPU_TYPE_DREGION_Msk) >> ARM_V7M_MPU_TYPE_DREGION_Pos;
}

/**
 * @brief Select the MPU region to configure
 * @param region_num Region number to select (0 to region_count-1)
 */
ARM_V7M_MPU_INLINE void arm_v7m_mpu_select_region(uint32_t region_num)
{
    MPU->RNR = region_num & ARM_V7M_MPU_RNR_REGION_Msk;
}

/**
 * @brief Calculate region size from SIZE field value
 * @param size_code SIZE field value (4-31)
 * @return Region size in bytes
 */
ARM_V7M_MPU_INLINE uint32_t arm_v7m_mpu_calc_region_size(uint32_t size_code)
{
    if (size_code < 4U || size_code > 31U) {
        return 0U;
    }
    return 1U << (size_code + 1U);
}

/**
 * @brief Check if address is aligned to specified size
 * @param addr Address to check
 * @param size Alignment size (must be power of 2)
 * @return 1 if aligned, 0 if not
 */
ARM_V7M_MPU_INLINE uint32_t arm_v7m_mpu_is_aligned(uint32_t addr, uint32_t size)
{
    return ((addr & (size - 1U)) == 0U) ? 1U : 0U;
}

/**
 * @brief Validate region configuration
 * @param base_addr Region base address
 * @param size_code Region size code (ARM_V7M_MPU_REGION_SIZE_*)
 * @return 1 if valid, 0 if invalid
 */
ARM_V7M_MPU_INLINE uint32_t arm_v7m_mpu_validate_region_cfg(uint32_t base_addr, uint32_t size_code)
{
    uint32_t region_size;

    if (size_code < ARM_V7M_MPU_REGION_SIZE_32B || size_code > ARM_V7M_MPU_REGION_SIZE_4GB) {
        return 0U;
    }

    region_size = arm_v7m_mpu_calc_region_size(size_code);
    return arm_v7m_mpu_is_aligned(base_addr, region_size);
}

/*============================================================================*
 * Non-Inline Functions - Complex Operations
 * These functions are implemented in the source file
 *============================================================================*/

/* Enable/disable MPU */
void arm_v7m_mpu_enable(uint32_t flags);
void arm_v7m_mpu_disable(void);

/* Query MPU capabilities */
uint32_t arm_v7m_mpu_get_min_region_size(void);

/* Region configuration */
void arm_v7m_mpu_set_region(uint32_t base_addr, uint32_t size_code, uint32_t attrs);
void arm_v7m_mpu_set_region_ex(uint32_t region_num, uint32_t base_addr, 
                                uint32_t size_code, uint32_t attrs, uint32_t srd);
void arm_v7m_mpu_disable_region(uint32_t region_num);

/* Multi-region configuration using alias registers */
void arm_v7m_mpu_set_regions(const arm_v7m_mpu_region_cfg_t *regions, uint32_t count);

/* Helper functions */
int arm_v7m_mpu_calc_size_code(uint32_t size);

/* MemManage fault status functions */
uint32_t arm_v7m_mpu_get_fault_status(void);
uint32_t arm_v7m_mpu_get_fault_address(void);
void arm_v7m_mpu_clear_fault_status(void);
uint32_t arm_v7m_mpu_fault_addr_valid(void);

/* MPU enable flags for arm_v7m_mpu_enable() */
#define ARM_V7M_MPU_ENABLE_PRIVDEFENA   ARM_V7M_MPU_CTRL_PRIVDEFENA_Msk
#define ARM_V7M_MPU_ENABLE_HFNMIENA     ARM_V7M_MPU_CTRL_HFNMIENA_Msk

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_MPU_H */
