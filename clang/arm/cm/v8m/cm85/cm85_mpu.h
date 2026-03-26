/**
 * @file arm_v8m_cm85_mpu.h
 * @brief Cortex-M85 Memory Protection Unit (MPU)
 *
 * @note Reference: Arm Cortex-M85 Devices Generic User Guide, Chapter 5.6.2
 * @note Reference: Arm Cortex-M85 Processor TRM, Chapter 9.3
 */

#ifndef ARM_V8M_CM85_MPU_H
#define ARM_V8M_CM85_MPU_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MPU Type Register */
typedef struct {
    volatile uint32_t TYPE;         /* MPU Type Register */
    volatile uint32_t CTRL;         /* MPU Control Register */
    volatile uint32_t RNR;          /* MPU Region Number Register */
    volatile uint32_t RBAR;         /* MPU Region Base Address Register */
    volatile uint32_t RLAR;         /* MPU Region Limit Address Register */
    uint32_t RESERVED0[7];
    volatile uint32_t RBAR_A1;      /* MPU Region Base Address Register Alias 1 */
    volatile uint32_t RLAR_A1;      /* MPU Region Limit Address Register Alias 1 */
    volatile uint32_t RBAR_A2;      /* MPU Region Base Address Register Alias 2 */
    volatile uint32_t RLAR_A2;      /* MPU Region Limit Address Register Alias 2 */
    volatile uint32_t RBAR_A3;      /* MPU Region Base Address Register Alias 3 */
    volatile uint32_t RLAR_A3;      /* MPU Region Limit Address Register Alias 3 */
    volatile uint32_t MAIR0;        /* MPU Memory Attribute Indirection Register 0 */
    volatile uint32_t MAIR1;        /* MPU Memory Attribute Indirection Register 1 */
} arm_v8m_cm85_mpu_reg_t;

#define ARM_V8M_CM85_MPU_BASE       (0xE000ED90UL)
#define ARM_V8M_CM85_MPU            ((arm_v8m_cm85_mpu_reg_t *)ARM_V8M_CM85_MPU_BASE)

/* MPU TYPE register bit definitions */
#define ARM_V8M_CM85_MPU_TYPE_SEPARATE_Pos      0U
#define ARM_V8M_CM85_MPU_TYPE_SEPARATE_Msk      (1UL << ARM_V8M_CM85_MPU_TYPE_SEPARATE_Pos)
#define ARM_V8M_CM85_MPU_TYPE_DREGION_Pos       8U
#define ARM_V8M_CM85_MPU_TYPE_DREGION_Msk       (0xFFUL << ARM_V8M_CM85_MPU_TYPE_DREGION_Pos)

/* MPU CTRL register bit definitions */
#define ARM_V8M_CM85_MPU_CTRL_ENABLE_Pos        0U
#define ARM_V8M_CM85_MPU_CTRL_ENABLE_Msk        (1UL << ARM_V8M_CM85_MPU_CTRL_ENABLE_Pos)
#define ARM_V8M_CM85_MPU_CTRL_HFNMIENA_Pos      1U
#define ARM_V8M_CM85_MPU_CTRL_HFNMIENA_Msk      (1UL << ARM_V8M_CM85_MPU_CTRL_HFNMIENA_Pos)
#define ARM_V8M_CM85_MPU_CTRL_PRIVDEFENA_Pos    2U
#define ARM_V8M_CM85_MPU_CTRL_PRIVDEFENA_Msk    (1UL << ARM_V8M_CM85_MPU_CTRL_PRIVDEFENA_Pos)

/* MPU RBAR register bit definitions */
#define ARM_V8M_CM85_MPU_RBAR_BASE_Pos          5U
#define ARM_V8M_CM85_MPU_RBAR_BASE_Msk          (0x7FFFFFFUL << ARM_V8M_CM85_MPU_RBAR_BASE_Pos)
#define ARM_V8M_CM85_MPU_RBAR_SH_Pos            3U
#define ARM_V8M_CM85_MPU_RBAR_SH_Msk            (0x3UL << ARM_V8M_CM85_MPU_RBAR_SH_Pos)
#define ARM_V8M_CM85_MPU_RBAR_AP_Pos            1U
#define ARM_V8M_CM85_MPU_RBAR_AP_Msk            (0x3UL << ARM_V8M_CM85_MPU_RBAR_AP_Pos)
#define ARM_V8M_CM85_MPU_RBAR_XN_Pos            0U
#define ARM_V8M_CM85_MPU_RBAR_XN_Msk            (1UL << ARM_V8M_CM85_MPU_RBAR_XN_Pos)

/* MPU RLAR register bit definitions */
#define ARM_V8M_CM85_MPU_RLAR_LIMIT_Pos         5U
#define ARM_V8M_CM85_MPU_RLAR_LIMIT_Msk         (0x7FFFFFFUL << ARM_V8M_CM85_MPU_RLAR_LIMIT_Pos)
#define ARM_V8M_CM85_MPU_RLAR_ATTRINDX_Pos      1U
#define ARM_V8M_CM85_MPU_RLAR_ATTRINDX_Msk      (0x7UL << ARM_V8M_CM85_MPU_RLAR_ATTRINDX_Pos)
#define ARM_V8M_CM85_MPU_RLAR_EN_Pos            0U
#define ARM_V8M_CM85_MPU_RLAR_EN_Msk            (1UL << ARM_V8M_CM85_MPU_RLAR_EN_Pos)

/* Shareability values */
typedef enum {
    ARM_V8M_CM85_MPU_SHARE_NON = 0,     /* Non-shareable */
    ARM_V8M_CM85_MPU_SHARE_RESERVED = 1,
    ARM_V8M_CM85_MPU_SHARE_OUTER = 2,   /* Outer shareable */
    ARM_V8M_CM85_MPU_SHARE_INNER = 3    /* Inner shareable */
} arm_v8m_cm85_mpu_share_t;

/* Access permission values */
typedef enum {
    ARM_V8M_CM85_MPU_AP_RW_PRIV = 0,    /* Read/Write, Privileged only */
    ARM_V8M_CM85_MPU_AP_RW_ALL = 1,     /* Read/Write, Any privilege */
    ARM_V8M_CM85_MPU_AP_RO_PRIV = 2,    /* Read-only, Privileged only */
    ARM_V8M_CM85_MPU_AP_RO_ALL = 3      /* Read-only, Any privilege */
} arm_v8m_cm85_mpu_ap_t;

/* Memory attribute index */
typedef enum {
    ARM_V8M_CM85_MPU_ATTRINDX_0 = 0,
    ARM_V8M_CM85_MPU_ATTRINDX_1 = 1,
    ARM_V8M_CM85_MPU_ATTRINDX_2 = 2,
    ARM_V8M_CM85_MPU_ATTRINDX_3 = 3,
    ARM_V8M_CM85_MPU_ATTRINDX_4 = 4,
    ARM_V8M_CM85_MPU_ATTRINDX_5 = 5,
    ARM_V8M_CM85_MPU_ATTRINDX_6 = 6,
    ARM_V8M_CM85_MPU_ATTRINDX_7 = 7
} arm_v8m_cm85_mpu_attrindx_t;

/* MPU region configuration */
typedef struct {
    uint32_t base_addr;
    uint32_t limit_addr;
    arm_v8m_cm85_mpu_share_t share;
    arm_v8m_cm85_mpu_ap_t ap;
    arm_v8m_cm85_mpu_attrindx_t attrindx;
    bool xn;                    /* Execute never */
    bool enable;
} arm_v8m_cm85_mpu_region_config_t;

/* MPU initialization and control */
int arm_v8m_cm85_mpu_init(void);
void arm_v8m_cm85_mpu_deinit(void);
void arm_v8m_cm85_mpu_enable(void);
void arm_v8m_cm85_mpu_disable(void);
bool arm_v8m_cm85_mpu_is_enabled(void);
void arm_v8m_cm85_mpu_enable_hfnmi(void);
void arm_v8m_cm85_mpu_disable_hfnmi(void);
void arm_v8m_cm85_mpu_enable_privdef(void);
void arm_v8m_cm85_mpu_disable_privdef(void);

/* Region configuration */
uint32_t arm_v8m_cm85_mpu_get_num_regions(void);
void arm_v8m_cm85_mpu_select_region(uint32_t region);
uint32_t arm_v8m_cm85_mpu_get_selected_region(void);
int arm_v8m_cm85_mpu_configure_region(uint32_t region, const arm_v8m_cm85_mpu_region_config_t *config);
void arm_v8m_cm85_mpu_enable_region(uint32_t region);
void arm_v8m_cm85_mpu_disable_region(uint32_t region);

/* Memory attributes (MAIR) */
void arm_v8m_cm85_mpu_set_attr(uint32_t attrindx, uint8_t attr);
uint8_t arm_v8m_cm85_mpu_get_attr(uint32_t attrindx);

/* Predefined memory attributes */
#define ARM_V8M_CM85_MPU_ATTR_DEVICE_nGnRnE     0x00
#define ARM_V8M_CM85_MPU_ATTR_DEVICE_nGnRE      0x04
#define ARM_V8M_CM85_MPU_ATTR_DEVICE_nGRE       0x08
#define ARM_V8M_CM85_MPU_ATTR_DEVICE_GRE        0x0C
#define ARM_V8M_CM85_MPU_ATTR_NORMAL_NC         0x44
#define ARM_V8M_CM85_MPU_ATTR_NORMAL_WT         0xBB
#define ARM_V8M_CM85_MPU_ATTR_NORMAL_WB         0xFF

/* Non-secure MPU access */
#ifdef __ARM_FEATURE_CMSE
#define ARM_V8M_CM85_MPU_NS_BASE    (0xE002ED90UL)
#define ARM_V8M_CM85_MPU_NS         ((arm_v8m_cm85_mpu_reg_t *)ARM_V8M_CM85_MPU_NS_BASE)

void arm_v8m_cm85_mpu_enable_ns(void);
void arm_v8m_cm85_mpu_disable_ns(void);
int arm_v8m_cm85_mpu_configure_region_ns(uint32_t region, const arm_v8m_cm85_mpu_region_config_t *config);
#endif

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM85_MPU_H */
