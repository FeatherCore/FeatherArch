/**
 * @file cm85_tcm.h
 * @brief Cortex-M85 Tightly-Coupled Memory (TCM) and TGU
 *
 * @note Reference: Arm Cortex-M85 Devices Generic User Guide, Chapter 5.8.5-5.8.6
 * @note Reference: Arm Cortex-M85 Processor TRM, Chapter 10.8
 */

#ifndef CM85_TCM_H
#define CM85_TCM_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* TCM Control Registers */
typedef struct {
    volatile uint32_t ITCMCR;       /* ITCM Control Register */
    volatile uint32_t DTCMCR;       /* DTCM Control Register */
} cm85_tcm_reg_t;

#define CM85_TCM_BASE       (0xE001E010UL)
#define CM85_TCM            ((cm85_tcm_reg_t *)CM85_TCM_BASE)

/* ITCMCR/DTCMCR bit definitions */
#define CM85_TCMCR_EN_Pos           0U
#define CM85_TCMCR_EN_Msk           (1UL << CM85_TCMCR_EN_Pos)
#define CM85_TCMCR_RMW_Pos          1U
#define CM85_TCMCR_RMW_Msk          (1UL << CM85_TCMCR_RMW_Pos)
#define CM85_TCMCR_RETEN_Pos        2U
#define CM85_TCMCR_RETEN_Msk        (1UL << CM85_TCMCR_RETEN_Pos)
#define CM85_TCMCR_SZ_Pos           3U
#define CM85_TCMCR_SZ_Msk           (0xFUL << CM85_TCMCR_SZ_Pos)

/* TCM sizes */
typedef enum {
    CM85_TCM_SIZE_NONE = 0x0,
    CM85_TCM_SIZE_4KB = 0x3,
    CM85_TCM_SIZE_8KB = 0x4,
    CM85_TCM_SIZE_16KB = 0x5,
    CM85_TCM_SIZE_32KB = 0x6,
    CM85_TCM_SIZE_64KB = 0x7,
    CM85_TCM_SIZE_128KB = 0x8,
    CM85_TCM_SIZE_256KB = 0x9,
    CM85_TCM_SIZE_512KB = 0xA,
    CM85_TCM_SIZE_1MB = 0xB,
    CM85_TCM_SIZE_2MB = 0xC,
    CM85_TCM_SIZE_4MB = 0xD,
    CM85_TCM_SIZE_8MB = 0xE,
    CM85_TCM_SIZE_16MB = 0xF
} cm85_tcm_size_t;

/* TGU (TCM Gate Unit) Registers */
typedef struct {
    volatile uint32_t CTRL;         /* TGU Control Register */
    volatile uint32_t CFG;          /* TGU Configuration Register */
    uint32_t RESERVED[2];
    volatile uint32_t LUT[16];      /* TGU Look Up Table Registers */
} cm85_tgu_reg_t;

#define CM85_ITGU_BASE      (0xE001E500UL)
#define CM85_DTGU_BASE      (0xE001E600UL)
#define CM85_ITGU           ((cm85_tgu_reg_t *)CM85_ITGU_BASE)
#define CM85_DTGU           ((cm85_tgu_reg_t *)CM85_DTGU_BASE)

/* TGU CTRL bit definitions */
#define CM85_TGU_CTRL_EN_Pos        0U
#define CM85_TGU_CTRL_EN_Msk        (1UL << CM85_TGU_CTRL_EN_Pos)
#define CM85_TGU_CTRL_HALTEN_Pos    1U
#define CM85_TGU_CTRL_HALTEN_Msk    (1UL << CM85_TGU_CTRL_HALTEN_Pos)

/* TGU CFG bit definitions */
#define CM85_TGU_CFG_BLKSZ_Pos      8U
#define CM85_TGU_CFG_BLKSZ_Msk      (0xFUL << CM85_TGU_CFG_BLKSZ_Pos)
#define CM85_TGU_CFG_NUMBLKS_Pos    0U
#define CM85_TGU_CFG_NUMBLKS_Msk    (0x1FUL << CM85_TGU_CFG_NUMBLKS_Pos)

/* TGU LUT bit definitions */
#define CM85_TGU_LUT_NS_Pos         0U
#define CM85_TGU_LUT_NS_Msk         (0x3UL << CM85_TGU_LUT_NS_Pos)

/* TGU security attributes */
typedef enum {
    CM85_TGU_SECURE = 0,
    CM85_TGU_NONSECURE = 1,
    CM85_TGU_NSC = 2
} cm85_tgu_attr_t;

/* TCM initialization and control */
int cm85_tcm_init(void);
void cm85_tcm_deinit(void);

/* ITCM control */
void cm85_tcm_itcm_enable(void);
void cm85_tcm_itcm_disable(void);
bool cm85_tcm_itcm_is_enabled(void);
void cm85_tcm_itcm_set_rmw(bool enable);
void cm85_tcm_itcm_set_reten(bool enable);
cm85_tcm_size_t cm85_tcm_itcm_get_size(void);
uint32_t cm85_tcm_itcm_get_base(void);

/* DTCM control */
void cm85_tcm_dtcm_enable(void);
void cm85_tcm_dtcm_disable(void);
bool cm85_tcm_dtcm_is_enabled(void);
void cm85_tcm_dtcm_set_rmw(bool enable);
void cm85_tcm_dtcm_set_reten(bool enable);
cm85_tcm_size_t cm85_tcm_dtcm_get_size(void);
uint32_t cm85_tcm_dtcm_get_base(void);

/* TGU control */
void cm85_tcm_itgu_enable(void);
void cm85_tcm_itgu_disable(void);
void cm85_tcm_dtgu_enable(void);
void cm85_tcm_dtgu_disable(void);

/* TGU LUT configuration */
uint32_t cm85_tcm_itgu_get_num_blocks(void);
uint32_t cm85_tcm_itgu_get_block_size(void);
void cm85_tcm_itgu_set_block_attr(uint32_t block, cm85_tgu_attr_t attr);
cm85_tgu_attr_t cm85_tcm_itgu_get_block_attr(uint32_t block);

uint32_t cm85_tcm_dtgu_get_num_blocks(void);
uint32_t cm85_tcm_dtgu_get_block_size(void);
void cm85_tcm_dtgu_set_block_attr(uint32_t block, cm85_tgu_attr_t attr);
cm85_tgu_attr_t cm85_tcm_dtgu_get_block_attr(uint32_t block);

/* Error Bank Registers */
typedef struct {
    volatile uint32_t IEBR[2];      /* Instruction Error Bank Registers */
    volatile uint32_t DEBR[2];      /* Data Error Bank Registers */
    volatile uint32_t TEBR[2];      /* TCM Error Bank Registers */
} cm85_tcm_err_reg_t;

#define CM85_TCM_ERR_BASE   (0xE001E120UL)
#define CM85_TCM_ERR        ((cm85_tcm_err_reg_t *)CM85_TCM_ERR_BASE)

/* Error bank access */
uint32_t cm85_tcm_get_iebr(uint32_t index);
uint32_t cm85_tcm_get_debr(uint32_t index);
uint32_t cm85_tcm_get_tebr(uint32_t index);
void cm85_tcm_clear_iebr(uint32_t index);
void cm85_tcm_clear_debr(uint32_t index);
void cm85_tcm_clear_tebr(uint32_t index);

#ifdef __cplusplus
}
#endif

#endif /* CM85_TCM_H */
