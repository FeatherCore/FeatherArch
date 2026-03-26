/**
 * @file arm_v8m_cm85_mpu.c
 * @brief Cortex-M85 MPU implementation
 */

#include "arm_v8m_cm85_mpu.h"

/* TODO: Implement MPU functions */

int arm_v8m_cm85_mpu_init(void)
{
    /* TODO: Initialize MPU */
    return 0;
}

void arm_v8m_cm85_mpu_deinit(void)
{
    /* TODO: Deinitialize MPU */
}

void arm_v8m_cm85_mpu_enable(void)
{
    /* TODO: Enable MPU */
}

void arm_v8m_cm85_mpu_disable(void)
{
    /* TODO: Disable MPU */
}

bool arm_v8m_cm85_mpu_is_enabled(void)
{
    /* TODO: Check if MPU is enabled */
    return false;
}

void arm_v8m_cm85_mpu_enable_hfnmi(void)
{
    /* TODO: Enable MPU during HardFault/NMI */
}

void arm_v8m_cm85_mpu_disable_hfnmi(void)
{
    /* TODO: Disable MPU during HardFault/NMI */
}

void arm_v8m_cm85_mpu_enable_privdef(void)
{
    /* TODO: Enable privileged default memory map */
}

void arm_v8m_cm85_mpu_disable_privdef(void)
{
    /* TODO: Disable privileged default memory map */
}

uint32_t arm_v8m_cm85_mpu_get_num_regions(void)
{
    /* TODO: Get number of MPU regions */
    return 0;
}

void arm_v8m_cm85_mpu_select_region(uint32_t region)
{
    /* TODO: Select MPU region */
    (void)region;
}

uint32_t arm_v8m_cm85_mpu_get_selected_region(void)
{
    /* TODO: Get selected MPU region */
    return 0;
}

int arm_v8m_cm85_mpu_configure_region(uint32_t region, const arm_v8m_cm85_mpu_region_config_t *config)
{
    /* TODO: Configure MPU region */
    (void)region;
    (void)config;
    return 0;
}

void arm_v8m_cm85_mpu_enable_region(uint32_t region)
{
    /* TODO: Enable MPU region */
    (void)region;
}

void arm_v8m_cm85_mpu_disable_region(uint32_t region)
{
    /* TODO: Disable MPU region */
    (void)region;
}

void arm_v8m_cm85_mpu_set_attr(uint32_t attrindx, uint8_t attr)
{
    /* TODO: Set memory attribute */
    (void)attrindx;
    (void)attr;
}

uint8_t arm_v8m_cm85_mpu_get_attr(uint32_t attrindx)
{
    /* TODO: Get memory attribute */
    (void)attrindx;
    return 0;
}

#ifdef __ARM_FEATURE_CMSE
void arm_v8m_cm85_mpu_enable_ns(void)
{
    /* TODO: Enable Non-secure MPU */
}

void arm_v8m_cm85_mpu_disable_ns(void)
{
    /* TODO: Disable Non-secure MPU */
}

int arm_v8m_cm85_mpu_configure_region_ns(uint32_t region, const arm_v8m_cm85_mpu_region_config_t *config)
{
    /* TODO: Configure Non-secure MPU region */
    (void)region;
    (void)config;
    return 0;
}
#endif
