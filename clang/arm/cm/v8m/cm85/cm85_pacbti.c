/**
 * @file cm85_pacbti.c
 * @brief Cortex-M85 PACBTI implementation
 */

#include "cm85_pacbti.h"

/* TODO: Implement PACBTI functions */

int cm85_pacbti_init(void)
{
    /* TODO: Initialize PACBTI */
    return 0;
}

void cm85_pacbti_deinit(void)
{
    /* TODO: Deinitialize PACBTI */
}

bool cm85_pacbti_is_present(void)
{
    /* TODO: Check if PACBTI is present */
    return false;
}

void cm85_pacbti_set_priv_key(const uint32_t key[4])
{
    /* TODO: Set privileged PAC key */
    (void)key;
}

void cm85_pacbti_get_priv_key(uint32_t key[4])
{
    /* TODO: Get privileged PAC key */
    if (key) {
        key[0] = 0;
        key[1] = 0;
        key[2] = 0;
        key[3] = 0;
    }
}

void cm85_pacbti_set_unpriv_key(const uint32_t key[4])
{
    /* TODO: Set unprivileged PAC key */
    (void)key;
}

void cm85_pacbti_get_unpriv_key(uint32_t key[4])
{
    /* TODO: Get unprivileged PAC key */
    if (key) {
        key[0] = 0;
        key[1] = 0;
        key[2] = 0;
        key[3] = 0;
    }
}

void cm85_pacbti_clear_keys(void)
{
    /* TODO: Clear all PAC keys */
}

uint32_t cm85_pacbti_pac(uint32_t ptr, uint32_t modifier)
{
    /* TODO: Compute PAC for pointer */
    (void)modifier;
    return ptr;
}

uint32_t cm85_pacbti_aut(uint32_t ptr, uint32_t modifier)
{
    /* TODO: Authenticate PAC in pointer */
    (void)modifier;
    return ptr;
}

uint32_t cm85_pacbti_pacga(uint32_t ptr, uint32_t modifier)
{
    /* TODO: Compute PAC and add to pointer */
    (void)modifier;
    return ptr;
}

uint32_t cm85_pacbti_xpac(uint32_t ptr)
{
    /* TODO: Strip PAC from pointer */
    return ptr;
}

void cm85_pacbti_bti(void)
{
    /* TODO: BTI instruction */
}

void cm85_pacbti_btic(void)
{
    /* TODO: BTI clearing instruction */
}

void cm85_pacbti_enable_bti(void)
{
    /* TODO: Enable BTI */
}

void cm85_pacbti_disable_bti(void)
{
    /* TODO: Disable BTI */
}

bool cm85_pacbti_bti_enabled(void)
{
    /* TODO: Check if BTI is enabled */
    return false;
}

void cm85_pacbti_enable_pac(void)
{
    /* TODO: Enable PAC */
}

void cm85_pacbti_disable_pac(void)
{
    /* TODO: Disable PAC */
}

bool cm85_pacbti_pac_enabled(void)
{
    /* TODO: Check if PAC is enabled */
    return false;
}

#ifdef __ARM_FEATURE_CMSE
void cm85_pacbti_set_priv_key_ns(const uint32_t key[4])
{
    /* TODO: Set Non-secure privileged PAC key */
    (void)key;
}

void cm85_pacbti_get_priv_key_ns(uint32_t key[4])
{
    /* TODO: Get Non-secure privileged PAC key */
    if (key) {
        key[0] = 0;
        key[1] = 0;
        key[2] = 0;
        key[3] = 0;
    }
}
#endif
