/**
 * @file cm85_mpu.h
 * @brief Cortex-M85 Memory Protection Unit (MPU)
 *
 * @note Reference: Arm Cortex-M85 Devices Generic User Guide, Chapter 5.6.2
 * @note Reference: Arm Cortex-M85 Processor TRM, Chapter 9.3
 */

#ifndef CM85_MPU_H
#define CM85_MPU_H

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
} cm85_mpu_reg_t;

#define CM85_MPU_BASE       (0xE000ED90UL)
#define CM85_MPU            ((cm85_mpu_reg_t *)CM85_MPU_BASE)

/* MPU TYPE register bit definitions */
#define CM85_MPU_TYPE_SEPARATE_Pos      0U
#define CM85_MPU_TYPE_SEPARATE_Msk      (1UL << CM85_MPU_TYPE_SEPARATE_Pos)
#define CM85_MPU_TYPE_DREGION_Pos       8U
#define CM85_MPU_TYPE_DREGION_Msk       (0xFFUL << CM85_MPU_TYPE_DREGION_Pos)

/* MPU CTRL register bit definitions */
#define CM85_MPU_CTRL_ENABLE_Pos        0U
#define CM85_MPU_CTRL_ENABLE_Msk        (1UL << CM85_MPU_CTRL_ENABLE_Pos)
#define CM85_MPU_CTRL_HFNMIENA_Pos      1U
#define CM85_MPU_CTRL_HFNMIENA_Msk      (1UL << CM85_MPU_CTRL_HFNMIENA_Pos)
#define CM85_MPU_CTRL_PRIVDEFENA_Pos    2U
#define CM85_MPU_CTRL_PRIVDEFENA_Msk    (1UL << CM85_MPU_CTRL_PRIVDEFENA_Pos)

/* MPU RBAR register bit definitions */
#define CM85_MPU_RBAR_BASE_Pos          5U
#define CM85_MPU_RBAR_BASE_Msk          (0x7FFFFFFUL << CM85_MPU_RBAR_BASE_Pos)
#define CM85_MPU_RBAR_SH_Pos            3U
#define CM85_MPU_RBAR_SH_Msk            (0x3UL << CM85_MPU_RBAR_SH_Pos)
#define CM85_MPU_RBAR_AP_Pos            1U
#define CM85_MPU_RBAR_AP_Msk            (0x3UL << CM85_MPU_RBAR_AP_Pos)
#define CM85_MPU_RBAR_XN_Pos            0U
#define CM85_MPU_RBAR_XN_Msk            (1UL << CM85_MPU_RBAR_XN_Pos)

/* MPU RLAR register bit definitions */
#define CM85_MPU_RLAR_LIMIT_Pos         5U
#define CM85_MPU_RLAR_LIMIT_Msk         (0x7FFFFFFUL << CM85_MPU_RLAR_LIMIT_Pos)
#define CM85_MPU_RLAR_ATTRINDX_Pos      1U
#define CM85_MPU_RLAR_ATTRINDX_Msk      (0x7UL << CM85_MPU_RLAR_ATTRINDX_Pos)
#define CM85_MPU_RLAR_EN_Pos            0U
#define CM85_MPU_RLAR_EN_Msk            (1UL << CM85_MPU_RLAR_EN_Pos)

/* Shareability values */
typedef enum {
    CM85_MPU_SHARE_NON = 0,     /* Non-shareable */
    CM85_MPU_SHARE_RESERVED = 1,
    CM85_MPU_SHARE_OUTER = 2,   /* Outer shareable */
    CM85_MPU_SHARE_INNER = 3    /* Inner shareable */
} cm85_mpu_share_t;

/* Access permission values */
typedef enum {
    CM85_MPU_AP_RW_PRIV = 0,    /* Read/Write, Privileged only */
    CM85_MPU_AP_RW_ALL = 1,     /* Read/Write, Any privilege */
    CM85_MPU_AP_RO_PRIV = 2,    /* Read-only, Privileged only */
    CM85_MPU_AP_RO_ALL = 3      /* Read-only, Any privilege */
} cm85_mpu_ap_t;

/* Memory attribute index */
typedef enum {
    CM85_MPU_ATTRINDX_0 = 0,
    CM85_MPU_ATTRINDX_1 = 1,
    CM85_MPU_ATTRINDX_2 = 2,
    CM85_MPU_ATTRINDX_3 = 3,
    CM85_MPU_ATTRINDX_4 = 4,
    CM85_MPU_ATTRINDX_5 = 5,
    CM85_MPU_ATTRINDX_6 = 6,
    CM85_MPU_ATTRINDX_7 = 7
} cm85_mpu_attrindx_t;

/* MPU region configuration */
typedef struct {
    uint32_t base_addr;
    uint32_t limit_addr;
    cm85_mpu_share_t share;
    cm85_mpu_ap_t ap;
    cm85_mpu_attrindx_t attrindx;
    bool xn;                    /* Execute never */
    bool enable;
} cm85_mpu_region_config_t;

/* MPU initialization and control */
int cm85_mpu_init(void);
void cm85_mpu_deinit(void);
void cm85_mpu_enable(void);
void cm85_mpu_disable(void);
bool cm85_mpu_is_enabled(void);
void cm85_mpu_enable_hfnmi(void);
void cm85_mpu_disable_hfnmi(void);
void cm85_mpu_enable_privdef(void);
void cm85_mpu_disable_privdef(void);

/* Region configuration */
uint32_t cm85_mpu_get_num_regions(void);
void cm85_mpu_select_region(uint32_t region);
uint32_t cm85_mpu_get_selected_region(void);
int cm85_mpu_configure_region(uint32_t region, const cm85_mpu_region_config_t *config);
void cm85_mpu_enable_region(uint32_t region);
void cm85_mpu_disable_region(uint32_t region);

/* Memory attributes (MAIR) */
void cm85_mpu_set_attr(uint32_t attrindx, uint8_t attr);
uint8_t cm85_mpu_get_attr(uint32_t attrindx);

/* Predefined memory attributes */
#define CM85_MPU_ATTR_DEVICE_nGnRnE     0x00
#define CM85_MPU_ATTR_DEVICE_nGnRE      0x04
#define CM85_MPU_ATTR_DEVICE_nGRE       0x08
#define CM85_MPU_ATTR_DEVICE_GRE        0x0C
#define CM85_MPU_ATTR_NORMAL_NC         0x44
#define CM85_MPU_ATTR_NORMAL_WT         0xBB
#define CM85_MPU_ATTR_NORMAL_WB         0xFF

/* Non-secure MPU access */
#ifdef __ARM_FEATURE_CMSE
#define CM85_MPU_NS_BASE    (0xE002ED90UL)
#define CM85_MPU_NS         ((cm85_mpu_reg_t *)CM85_MPU_NS_BASE)

void cm85_mpu_enable_ns(void);
void cm85_mpu_disable_ns(void);
int cm85_mpu_configure_region_ns(uint32_t region, const cm85_mpu_region_config_t *config);
#endif

#ifdef __cplusplus
}
#endif

#endif /* CM85_MPU_H */
