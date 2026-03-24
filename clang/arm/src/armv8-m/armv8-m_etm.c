/*
 * ARM Architecture - ARMv8-M ETMv4 Implementation
 *
 * ============================================================================
 * File: armv8-m_etm.c
 * Description: ARMv8-M ETMv4 (Embedded Trace Macrocell) implementation
 * 描述: ARMv8-M ETMv4 实现
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B13.5: Embedded Trace Macrocell
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv8-m/armv8-m_etm.h"

/*
 * ============================================================================
 * ETM Functions
 * ============================================================================
 */

void etm_init(void)
{
    if (!etm_is_present()) {
        return;
    }
    
    /* Disable tracing during configuration */
    etm_disable();
    
    /* Wait for ETM to be idle */
    etm_wait_for_idle();
    
    /* Set default trace ID */
    etm_set_trace_id(0x01);
    
    /* Configure default settings */
    ETM_CR = 0;
    ETM_VICTLR = 0;
}

void etm_enable(void)
{
    if (!etm_check_auth()) {
        return;
    }
    
    /* Wait for ETM to be idle */
    etm_wait_for_idle();
    
    /* Set trace start bit */
    ETM_CR |= ETM_CR_TRACESTART_Msk;
}

void etm_disable(void)
{
    /* Set trace stop bit */
    ETM_CR |= ETM_CR_TRACESTOP_Msk;
    
    /* Wait for ETM to be idle */
    etm_wait_for_idle();
}

bool etm_is_present(void)
{
    /* Check Component ID registers */
    uint32_t cidr0 = ETM_CIDR0;
    uint32_t cidr1 = ETM_CIDR1;
    uint32_t cidr2 = ETM_CIDR2;
    uint32_t cidr3 = ETM_CIDR3;
    
    /* CoreSight component ID preamble */
    if ((cidr0 & 0xFF) != 0x0D) return false;
    if ((cidr1 & 0xFF) != 0x90) return false;
    if ((cidr2 & 0xFF) != 0x05) return false;
    if ((cidr3 & 0xFF) != 0xB1) return false;
    
    return true;
}

bool etm_is_enabled(void)
{
    return (ETM_SR & ETM_SR_STARTSTOP_Msk) != 0;
}

void etm_set_trace_id(uint8_t id)
{
    /* Trace ID must be in range 1-127 */
    if (id == 0 || id > 127) {
        return;
    }
    
    ETM_TRCTRACEIDR = id;
}

uint8_t etm_get_trace_id(void)
{
    return (uint8_t)(ETM_TRCTRACEIDR & 0x7F);
}

void etm_configure_instruction_trace(bool enable)
{
    if (enable) {
        /* Enable instruction tracing in ViewInst control */
        ETM_VICTLR |= 0x1;
    } else {
        ETM_VICTLR &= ~0x1;
    }
}

void etm_configure_exception_level(uint8_t secure_mask, uint8_t nonsecure_mask)
{
    uint32_t cr = ETM_CR;
    
    /* Clear existing exception level bits */
    cr &= ~(ETM_CR_EXLEVEL_S_Msk | ETM_CR_EXLEVEL_NS_Msk);
    
    /* Set new exception level masks */
    cr |= ((secure_mask & 0xF) << ETM_CR_EXLEVEL_S_Pos);
    cr |= ((nonsecure_mask & 0xF) << ETM_CR_EXLEVEL_NS_Pos);
    
    ETM_CR = cr;
}

void etm_enable_timestamp(bool enable)
{
    if (enable) {
        ETM_CR |= ETM_CR_TSTAMPEN_Msk;
    } else {
        ETM_CR &= ~ETM_CR_TSTAMPEN_Msk;
    }
}

bool etm_check_auth(void)
{
    uint32_t authstat = ETM_AUTHSTAT;
    
    /* Check non-secure invasive debug */
    uint32_t nsid = (authstat & ETM_AUTHSTAT_NSID_Msk) >> ETM_AUTHSTAT_NSID_Pos;
    
    return nsid == ETM_AUTH_ENABLE;
}

void etm_wait_for_idle(void)
{
    /* Wait for IDLE bit to be set */
    while ((ETM_SR & ETM_SR_IDLE_Msk) == 0) {
        __asm__ volatile ("nop");
    }
}

void etm_software_trigger(void)
{
    /* Generate software trigger */
    /* In ETMv4, this is done through the TRIVR register */
    /* For now, this is a placeholder */
}
