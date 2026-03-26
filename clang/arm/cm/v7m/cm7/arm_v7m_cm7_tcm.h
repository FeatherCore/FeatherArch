/*
 * arm_v7m_cm7_tcm.h
 * Cortex-M7 Tightly-Coupled Memory (TCM) Definitions
 * Reference: Cortex-M7 Technical Reference Manual, Chapter 5.8
 */

#ifndef ARM_V7M_CM7_TCM_H
#define ARM_V7M_CM7_TCM_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * TCM Control Register Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t ITCMCR;
    volatile uint32_t DTCMCR;
    volatile uint32_t AHBPCR;
    volatile uint32_t CACR;
    volatile uint32_t AHBSCR;
    uint32_t RESERVED0[1];
    volatile uint32_t ABFSR;
} arm_v7m_cm7_tcm_regs_t;

/*============================================================================*
 * ITCMCR Bit Definitions
 *============================================================================*/

#define ARM_V7M_CM7_ITCMCR_EN_Pos               0
#define ARM_V7M_CM7_ITCMCR_EN_Msk               (1UL << ARM_V7M_CM7_ITCMCR_EN_Pos)
#define ARM_V7M_CM7_ITCMCR_RMW_Pos              1
#define ARM_V7M_CM7_ITCMCR_RMW_Msk              (1UL << ARM_V7M_CM7_ITCMCR_RMW_Pos)
#define ARM_V7M_CM7_ITCMCR_RETEN_Pos            2
#define ARM_V7M_CM7_ITCMCR_RETEN_Msk            (1UL << ARM_V7M_CM7_ITCMCR_RETEN_Pos)
#define ARM_V7M_CM7_ITCMCR_SZ_Pos               3
#define ARM_V7M_CM7_ITCMCR_SZ_Msk               (0xFUL << ARM_V7M_CM7_ITCMCR_SZ_Pos)

/*============================================================================*
 * DTCMCR Bit Definitions
 *============================================================================*/

#define ARM_V7M_CM7_DTCMCR_EN_Pos               0
#define ARM_V7M_CM7_DTCMCR_EN_Msk               (1UL << ARM_V7M_CM7_DTCMCR_EN_Pos)
#define ARM_V7M_CM7_DTCMCR_RMW_Pos              1
#define ARM_V7M_CM7_DTCMCR_RMW_Msk              (1UL << ARM_V7M_CM7_DTCMCR_RMW_Pos)
#define ARM_V7M_CM7_DTCMCR_RETEN_Pos            2
#define ARM_V7M_CM7_DTCMCR_RETEN_Msk            (1UL << ARM_V7M_CM7_DTCMCR_RETEN_Pos)
#define ARM_V7M_CM7_DTCMCR_SZ_Pos               3
#define ARM_V7M_CM7_DTCMCR_SZ_Msk               (0xFUL << ARM_V7M_CM7_DTCMCR_SZ_Pos)

/*============================================================================*
 * TCM Size Definitions
 *============================================================================*/

#define ARM_V7M_CM7_TCM_SIZE_0KB                0x0
#define ARM_V7M_CM7_TCM_SIZE_4KB                0x3
#define ARM_V7M_CM7_TCM_SIZE_8KB                0x4
#define ARM_V7M_CM7_TCM_SIZE_16KB               0x5
#define ARM_V7M_CM7_TCM_SIZE_32KB               0x6
#define ARM_V7M_CM7_TCM_SIZE_64KB               0x7
#define ARM_V7M_CM7_TCM_SIZE_128KB              0x8
#define ARM_V7M_CM7_TCM_SIZE_256KB              0x9
#define ARM_V7M_CM7_TCM_SIZE_512KB              0xA
#define ARM_V7M_CM7_TCM_SIZE_1MB                0xB
#define ARM_V7M_CM7_TCM_SIZE_2MB                0xC
#define ARM_V7M_CM7_TCM_SIZE_4MB                0xD
#define ARM_V7M_CM7_TCM_SIZE_8MB                0xE
#define ARM_V7M_CM7_TCM_SIZE_16MB               0xF

/*============================================================================*
 * TCM API Functions (Template)
 *============================================================================*/

/* ITCM Functions */
void arm_v7m_cm7_itcm_enable(void);
void arm_v7m_cm7_itcm_disable(void);
void arm_v7m_cm7_itcm_set_size(uint32_t size);
uint32_t arm_v7m_cm7_itcm_get_size(void);

/* DTCM Functions */
void arm_v7m_cm7_dtcm_enable(void);
void arm_v7m_cm7_dtcm_disable(void);
void arm_v7m_cm7_dtcm_set_size(uint32_t size);
uint32_t arm_v7m_cm7_dtcm_get_size(void);

/* AHB Peripheral Control */
void arm_v7m_cm7_ahbpc_enable(void);
void arm_v7m_cm7_ahbpc_disable(void);

/* CACR - Cache Control */
void arm_v7m_cm7_cacr_set_siwu(uint32_t enable);
void arm_v7m_cm7_cacr_set_ecor(uint32_t enable);
void arm_v7m_cm7_cacr_set_dcor(uint32_t enable);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM7_TCM_H */
