/*
 * arm_v8m_cm55_pwr.c
 * Cortex-M55 Power Management Implementation
 * Reference: Cortex-M55 Technical Reference Manual, Chapter 7
 */

#include "arm_v8m_cm55_pwr.h"

/*============================================================================*
 * Power Base Address (Architecture defined)
 *============================================================================*/
#define PWR_BASE            0xE000EE20UL

#define PWR                 ((arm_v8m_cm55_pwr_regs_t *)PWR_BASE)

/*============================================================================*
 * Power Implementation
 *============================================================================*/

void arm_v8m_cm55_pwr_set_mode(arm_v8m_cm55_pwr_mode_t mode)
{
    /* TODO: Configure power mode */
    (void)mode;
}

arm_v8m_cm55_pwr_mode_t arm_v8m_cm55_pwr_get_mode(void)
{
    /* TODO: Read current power mode */
    return ARM_V8M_CM55_PWR_MODE_RUN;
}

void arm_v8m_cm55_pwr_enable_wfi(void)
{
    /* TODO: Configure WFI behavior */
}

void arm_v8m_cm55_pwr_enable_wfe(void)
{
    /* TODO: Configure WFE behavior */
}

void arm_v8m_cm55_pwr_set_epu_low_power(uint32_t mode)
{
    /* TODO: Set EPU low power mode in CPDLPSTATE */
    (void)mode;
}

void arm_v8m_cm55_pwr_set_ram_low_power(uint32_t mode)
{
    /* TODO: Set RAM low power mode in CPDLPSTATE */
    (void)mode;
}

/*============================================================================*
 * P-Channel Interface
 *============================================================================*/

void arm_v8m_cm55_pwr_pchannel_request(uint32_t state)
{
    /* TODO: Request P-Channel state transition */
    (void)state;
}

uint32_t arm_v8m_cm55_pwr_pchannel_get_state(void)
{
    /* TODO: Read P-Channel current state */
    return 0;
}

/*============================================================================*
 * Q-Channel Interface
 *============================================================================*/

void arm_v8m_cm55_pwr_qchannel_request(uint32_t state)
{
    /* TODO: Request Q-Channel state transition */
    (void)state;
}

uint32_t arm_v8m_cm55_pwr_qchannel_get_state(void)
{
    /* TODO: Read Q-Channel current state */
    return 0;
}
