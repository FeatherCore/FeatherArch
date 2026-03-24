/*
 * ARM Architecture - Cortex-M7 Tightly-Coupled Memory (TCM)
 *
 * ============================================================================
 * File: cm7_tcm.c
 * Description: Cortex-M7 Tightly-Coupled Memory (TCM) Control implementation
 * 描述: Cortex-M7 紧耦合内存 (TCM) 控制实现
 *
 * @reference Arm Cortex-M7 Processor Technical Reference Manual
 *   - Section 3.2 Register summary, Table 3-1 System control registers
 *   - Section 3.3.6 Instruction and Data Tightly-Coupled Memory Control Registers
 *   - Section 3.3.7 AHBP Control Register
 *   - Section 3.3.12 AHB Slave Control Register
 *
 * @reference Arm Cortex-M7 Devices Generic User Guide
 *   - Section 4.5 Processor features
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/cm7/cm7_tcm.h"

/* ============================================================================
 * TCM Information Functions
 * TCM 信息函数
 * ============================================================================ */

#if (__ITCM_PRESENT == 1)
/**
 * @brief Get ITCM size
 * 获取 ITCM 大小
 *
 * @return ITCM size in bytes
 */
uint32_t cm7_itcm_get_size(void)
{
    uint32_t sz = (CM7_ITCMCR & CM7_TCMCR_SZ_Msk) >> CM7_TCMCR_SZ_Pos;

    switch (sz) {
        case 0x0U: return 0U;           /* No TCM */
        case 0x3U: return 4U * 1024U;   /* 4KB */
        case 0x4U: return 8U * 1024U;   /* 8KB */
        case 0x5U: return 16U * 1024U;  /* 16KB */
        case 0x6U: return 32U * 1024U;  /* 32KB */
        case 0x7U: return 64U * 1024U;  /* 64KB */
        case 0x8U: return 128U * 1024U; /* 128KB */
        case 0x9U: return 256U * 1024U; /* 256KB */
        case 0xAU: return 512U * 1024U; /* 512KB */
        case 0xBU: return 1U * 1024U * 1024U; /* 1MB */
        case 0xCU: return 2U * 1024U * 1024U; /* 2MB */
        case 0xDU: return 4U * 1024U * 1024U; /* 4MB */
        case 0xEU: return 8U * 1024U * 1024U; /* 8MB */
        case 0xFU: return 16U * 1024U * 1024U; /* 16MB */
        default: return 0U;
    }
}

/**
 * @brief Check if ITCM is enabled
 * 检查 ITCM 是否使能
 *
 * @return 1 if enabled, 0 otherwise
 */
uint32_t cm7_itcm_is_enabled(void)
{
    return (CM7_ITCMCR & CM7_TCMCR_EN_Msk) ? 1U : 0U;
}

/**
 * @brief Enable ITCM Read-Modify-Write mode
 * 使能 ITCM 读-修改-写模式
 */
void cm7_itcm_rmw_enable(void)
{
    CM7_ITCMCR |= CM7_TCMCR_RMW_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Disable ITCM Read-Modify-Write mode
 * 禁用 ITCM 读-修改-写模式
 */
void cm7_itcm_rmw_disable(void)
{
    CM7_ITCMCR &= ~CM7_TCMCR_RMW_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Enable ITCM retry phase
 * 使能 ITCM 重试阶段
 */
void cm7_itcm_reten_enable(void)
{
    CM7_ITCMCR |= CM7_TCMCR_RETEN_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Disable ITCM retry phase
 * 禁用 ITCM 重试阶段
 */
void cm7_itcm_reten_disable(void)
{
    CM7_ITCMCR &= ~CM7_TCMCR_RETEN_Msk;
    __DSB();
    __ISB();
}
#endif /* __ITCM_PRESENT */

#if (__DTCM_PRESENT == 1)
/**
 * @brief Get DTCM size
 * 获取 DTCM 大小
 *
 * @return DTCM size in bytes
 */
uint32_t cm7_dtcm_get_size(void)
{
    uint32_t sz = (CM7_DTCMCR & CM7_TCMCR_SZ_Msk) >> CM7_TCMCR_SZ_Pos;

    switch (sz) {
        case 0x0U: return 0U;           /* No TCM */
        case 0x3U: return 4U * 1024U;   /* 4KB */
        case 0x4U: return 8U * 1024U;   /* 8KB */
        case 0x5U: return 16U * 1024U;  /* 16KB */
        case 0x6U: return 32U * 1024U;  /* 32KB */
        case 0x7U: return 64U * 1024U;  /* 64KB */
        case 0x8U: return 128U * 1024U; /* 128KB */
        case 0x9U: return 256U * 1024U; /* 256KB */
        case 0xAU: return 512U * 1024U; /* 512KB */
        case 0xBU: return 1U * 1024U * 1024U; /* 1MB */
        case 0xCU: return 2U * 1024U * 1024U; /* 2MB */
        case 0xDU: return 4U * 1024U * 1024U; /* 4MB */
        case 0xEU: return 8U * 1024U * 1024U; /* 8MB */
        case 0xFU: return 16U * 1024U * 1024U; /* 16MB */
        default: return 0U;
    }
}

/**
 * @brief Check if DTCM is enabled
 * 检查 DTCM 是否使能
 *
 * @return 1 if enabled, 0 otherwise
 */
uint32_t cm7_dtcm_is_enabled(void)
{
    return (CM7_DTCMCR & CM7_TCMCR_EN_Msk) ? 1U : 0U;
}

/**
 * @brief Enable DTCM Read-Modify-Write mode
 * 使能 DTCM 读-修改-写模式
 */
void cm7_dtcm_rmw_enable(void)
{
    CM7_DTCMCR |= CM7_TCMCR_RMW_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Disable DTCM Read-Modify-Write mode
 * 禁用 DTCM 读-修改-写模式
 */
void cm7_dtcm_rmw_disable(void)
{
    CM7_DTCMCR &= ~CM7_TCMCR_RMW_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Enable DTCM retry phase
 * 使能 DTCM 重试阶段
 */
void cm7_dtcm_reten_enable(void)
{
    CM7_DTCMCR |= CM7_TCMCR_RETEN_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Disable DTCM retry phase
 * 禁用 DTCM 重试阶段
 */
void cm7_dtcm_reten_disable(void)
{
    CM7_DTCMCR &= ~CM7_TCMCR_RETEN_Msk;
    __DSB();
    __ISB();
}
#endif /* __DTCM_PRESENT */

/* ============================================================================
 * AHBP Control Functions
 * AHBP 控制函数
 * ============================================================================ */

/**
 * @brief Enable AHBP
 * 使能 AHBP
 */
void cm7_ahbp_enable(void)
{
    CM7_AHBPCR |= CM7_AHBPCR_EN_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Disable AHBP
 * 禁用 AHBP
 */
void cm7_ahbp_disable(void)
{
    CM7_AHBPCR &= ~CM7_AHBPCR_EN_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief Get AHBP size
 * 获取 AHBP 大小
 *
 * @return AHBP size in bytes
 */
uint32_t cm7_ahbp_get_size(void)
{
    uint32_t sz = (CM7_AHBPCR & CM7_AHBPCR_SZ_Msk) >> CM7_AHBPCR_SZ_Pos;

    switch (sz) {
        case 0x0U: return 0U;                    /* Disabled */
        case 0x1U: return 64U * 1024U * 1024U;   /* 64MB */
        case 0x2U: return 128U * 1024U * 1024U;  /* 128MB */
        case 0x3U: return 256U * 1024U * 1024U;  /* 256MB */
        case 0x4U: return 512U * 1024U * 1024U;  /* 512MB */
        default: return 0U;
    }
}

/* ============================================================================
 * AHB Slave Control Functions
 * AHB 从设备控制函数
 * ============================================================================ */

/**
 * @brief Set AHB slave control
 * 设置 AHB 从设备控制
 *
 * @param ctl Control value (0-3)
 */
void cm7_ahbscr_set_ctl(uint32_t ctl)
{
    uint32_t reg = CM7_AHBSCR;
    reg &= ~CM7_AHBSCR_CTL_Msk;
    reg |= (ctl << CM7_AHBSCR_CTL_Pos) & CM7_AHBSCR_CTL_Msk;
    CM7_AHBSCR = reg;
    __DSB();
}

/**
 * @brief Get AHB slave control
 * 获取 AHB 从设备控制
 *
 * @return Control value
 */
uint32_t cm7_ahbscr_get_ctl(void)
{
    return (CM7_AHBSCR & CM7_AHBSCR_CTL_Msk) >> CM7_AHBSCR_CTL_Pos;
}

/**
 * @brief Set AHB slave threshold priority
 * 设置 AHB 从设备阈值优先级
 *
 * @param tpri Threshold priority value
 */
void cm7_ahbscr_set_tpri(uint32_t tpri)
{
    uint32_t reg = CM7_AHBSCR;
    reg &= ~CM7_AHBSCR_TPRI_Msk;
    reg |= (tpri << CM7_AHBSCR_TPRI_Pos) & CM7_AHBSCR_TPRI_Msk;
    CM7_AHBSCR = reg;
    __DSB();
}

/**
 * @brief Get AHB slave threshold priority
 * 获取 AHB 从设备阈值优先级
 *
 * @return Threshold priority value
 */
uint32_t cm7_ahbscr_get_tpri(void)
{
    return (CM7_AHBSCR & CM7_AHBSCR_TPRI_Msk) >> CM7_AHBSCR_TPRI_Pos;
}

/**
 * @brief Set AHB slave fairness counter initialization value
 * 设置 AHB 从设备公平计数器初始值
 *
 * @param initcount Initialization value (0-31)
 */
void cm7_ahbscr_set_initcount(uint32_t initcount)
{
    uint32_t reg = CM7_AHBSCR;
    reg &= ~CM7_AHBSCR_INITCOUNT_Msk;
    reg |= (initcount << CM7_AHBSCR_INITCOUNT_Pos) & CM7_AHBSCR_INITCOUNT_Msk;
    CM7_AHBSCR = reg;
    __DSB();
}

/**
 * @brief Get AHB slave fairness counter initialization value
 * 获取 AHB 从设备公平计数器初始值
 *
 * @return Initialization value
 */
uint32_t cm7_ahbscr_get_initcount(void)
{
    return (CM7_AHBSCR & CM7_AHBSCR_INITCOUNT_Msk) >> CM7_AHBSCR_INITCOUNT_Pos;
}
