/**
 * @file arm_v8m_cm85_tcm.c
 * @brief Cortex-M85 TCM implementation
 */

#include "arm_v8m_cm85_tcm.h"

/* TODO: Implement TCM functions */

int arm_v8m_cm85_tcm_init(void)
{
    /* TODO: Initialize TCM */
    return 0;
}

void arm_v8m_cm85_tcm_deinit(void)
{
    /* TODO: Deinitialize TCM */
}

void arm_v8m_cm85_tcm_itcm_enable(void)
{
    /* TODO: Enable ITCM */
}

void arm_v8m_cm85_tcm_itcm_disable(void)
{
    /* TODO: Disable ITCM */
}

bool arm_v8m_cm85_tcm_itcm_is_enabled(void)
{
    /* TODO: Check if ITCM is enabled */
    return false;
}

void arm_v8m_cm85_tcm_itcm_set_rmw(bool enable)
{
    /* TODO: Set ITCM RMW */
    (void)enable;
}

void arm_v8m_cm85_tcm_itcm_set_reten(bool enable)
{
    /* TODO: Set ITCM retention */
    (void)enable;
}

arm_v8m_cm85_tcm_size_t arm_v8m_cm85_tcm_itcm_get_size(void)
{
    /* TODO: Get ITCM size */
    return ARM_V8M_CM85_TCM_SIZE_NONE;
}

uint32_t arm_v8m_cm85_tcm_itcm_get_base(void)
{
    /* TODO: Get ITCM base address */
    return 0x00000000UL;
}

void arm_v8m_cm85_tcm_dtcm_enable(void)
{
    /* TODO: Enable DTCM */
}

void arm_v8m_cm85_tcm_dtcm_disable(void)
{
    /* TODO: Disable DTCM */
}

bool arm_v8m_cm85_tcm_dtcm_is_enabled(void)
{
    /* TODO: Check if DTCM is enabled */
    return false;
}

void arm_v8m_cm85_tcm_dtcm_set_rmw(bool enable)
{
    /* TODO: Set DTCM RMW */
    (void)enable;
}

void arm_v8m_cm85_tcm_dtcm_set_reten(bool enable)
{
    /* TODO: Set DTCM retention */
    (void)enable;
}

arm_v8m_cm85_tcm_size_t arm_v8m_cm85_tcm_dtcm_get_size(void)
{
    /* TODO: Get DTCM size */
    return ARM_V8M_CM85_TCM_SIZE_NONE;
}

uint32_t arm_v8m_cm85_tcm_dtcm_get_base(void)
{
    /* TODO: Get DTCM base address */
    return 0x20000000UL;
}

void arm_v8m_cm85_tcm_itgu_enable(void)
{
    /* TODO: Enable ITGU */
}

void arm_v8m_cm85_tcm_itgu_disable(void)
{
    /* TODO: Disable ITGU */
}

void arm_v8m_cm85_tcm_dtgu_enable(void)
{
    /* TODO: Enable DTGU */
}

void arm_v8m_cm85_tcm_dtgu_disable(void)
{
    /* TODO: Disable DTGU */
}

uint32_t arm_v8m_cm85_tcm_itgu_get_num_blocks(void)
{
    /* TODO: Get ITGU number of blocks */
    return 0;
}

uint32_t arm_v8m_cm85_tcm_itgu_get_block_size(void)
{
    /* TODO: Get ITGU block size */
    return 0;
}

void arm_v8m_cm85_tcm_itgu_set_block_attr(uint32_t block, arm_v8m_cm85_tgu_attr_t attr)
{
    /* TODO: Set ITGU block attribute */
    (void)block;
    (void)attr;
}

arm_v8m_cm85_tgu_attr_t arm_v8m_cm85_tcm_itgu_get_block_attr(uint32_t block)
{
    /* TODO: Get ITGU block attribute */
    (void)block;
    return ARM_V8M_CM85_TGU_SECURE;
}

uint32_t arm_v8m_cm85_tcm_dtgu_get_num_blocks(void)
{
    /* TODO: Get DTGU number of blocks */
    return 0;
}

uint32_t arm_v8m_cm85_tcm_dtgu_get_block_size(void)
{
    /* TODO: Get DTGU block size */
    return 0;
}

void arm_v8m_cm85_tcm_dtgu_set_block_attr(uint32_t block, arm_v8m_cm85_tgu_attr_t attr)
{
    /* TODO: Set DTGU block attribute */
    (void)block;
    (void)attr;
}

arm_v8m_cm85_tgu_attr_t arm_v8m_cm85_tcm_dtgu_get_block_attr(uint32_t block)
{
    /* TODO: Get DTGU block attribute */
    (void)block;
    return ARM_V8M_CM85_TGU_SECURE;
}

uint32_t arm_v8m_cm85_tcm_get_iebr(uint32_t index)
{
    /* TODO: Get IEBR */
    (void)index;
    return 0;
}

uint32_t arm_v8m_cm85_tcm_get_debr(uint32_t index)
{
    /* TODO: Get DEBR */
    (void)index;
    return 0;
}

uint32_t arm_v8m_cm85_tcm_get_tebr(uint32_t index)
{
    /* TODO: Get TEBR */
    (void)index;
    return 0;
}

void arm_v8m_cm85_tcm_clear_iebr(uint32_t index)
{
    /* TODO: Clear IEBR */
    (void)index;
}

void arm_v8m_cm85_tcm_clear_debr(uint32_t index)
{
    /* TODO: Clear DEBR */
    (void)index;
}

void arm_v8m_cm85_tcm_clear_tebr(uint32_t index)
{
    /* TODO: Clear TEBR */
    (void)index;
}
