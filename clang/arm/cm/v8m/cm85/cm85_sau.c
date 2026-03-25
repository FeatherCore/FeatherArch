/**
 * @file cm85_sau.c
 * @brief Cortex-M85 SAU implementation
 */

#include "cm85_sau.h"

/* TODO: Implement SAU functions */

int cm85_sau_init(void)
{
    /* TODO: Initialize SAU */
    return 0;
}

void cm85_sau_deinit(void)
{
    /* TODO: Deinitialize SAU */
}

void cm85_sau_enable(void)
{
    /* TODO: Enable SAU */
}

void cm85_sau_disable(void)
{
    /* TODO: Disable SAU */
}

bool cm85_sau_is_enabled(void)
{
    /* TODO: Check if SAU is enabled */
    return false;
}

void cm85_sau_set_allns(bool allns)
{
    /* TODO: Set ALLNS bit */
    (void)allns;
}

uint32_t cm85_sau_get_num_regions(void)
{
    /* TODO: Get number of SAU regions */
    return 0;
}

void cm85_sau_select_region(uint32_t region)
{
    /* TODO: Select SAU region */
    (void)region;
}

uint32_t cm85_sau_get_selected_region(void)
{
    /* TODO: Get selected SAU region */
    return 0;
}

int cm85_sau_configure_region(uint32_t region, const cm85_sau_region_config_t *config)
{
    /* TODO: Configure SAU region */
    (void)region;
    (void)config;
    return 0;
}

void cm85_sau_enable_region(uint32_t region)
{
    /* TODO: Enable SAU region */
    (void)region;
}

void cm85_sau_disable_region(uint32_t region)
{
    /* TODO: Disable SAU region */
    (void)region;
}

uint32_t cm85_sau_get_fault_status(void)
{
    /* TODO: Get SFSR */
    return 0;
}

void cm85_sau_clear_fault_status(uint32_t mask)
{
    /* TODO: Clear SFSR bits */
    (void)mask;
}

uint32_t cm85_sau_get_fault_address(void)
{
    /* TODO: Get SFAR */
    return 0;
}

bool cm85_sau_is_fault_address_valid(void)
{
    /* TODO: Check SFARVALID bit */
    return false;
}

void cm85_sau_sg(void)
{
    /* TODO: Secure Gateway - typically implemented as inline assembly */
}

cm85_sau_attr_t cm85_sau_check_address(uint32_t addr)
{
    /* TODO: Check address security attribution */
    (void)addr;
    return CM85_SAU_ATTR_NONSECURE;
}
