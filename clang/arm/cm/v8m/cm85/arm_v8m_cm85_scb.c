/**
 * @file arm_v8m_cm85_scb.c
 * @brief Cortex-M85 SCB implementation
 */

#include "arm_v8m_cm85_scb.h"

/* TODO: Implement SCB functions */

uint32_t arm_v8m_cm85_scb_get_cpuid(void)
{
    /* TODO: Get CPUID */
    return 0;
}

void arm_v8m_cm85_scb_set_vtor(uint32_t offset)
{
    /* TODO: Set VTOR */
    (void)offset;
}

uint32_t arm_v8m_cm85_scb_get_vtor(void)
{
    /* TODO: Get VTOR */
    return 0;
}

void arm_v8m_cm85_scb_system_reset(void)
{
    /* TODO: System reset */
}

void arm_v8m_cm85_scb_system_reset_secure(void)
{
    /* TODO: Secure system reset */
}

void arm_v8m_cm85_scb_set_pendsv(void)
{
    /* TODO: Set PendSV */
}

void arm_v8m_cm85_scb_clear_pendsv(void)
{
    /* TODO: Clear PendSV */
}

void arm_v8m_cm85_scb_set_nmi(void)
{
    /* TODO: Set NMI */
}

uint32_t arm_v8m_cm85_scb_get_vectactive(void)
{
    /* TODO: Get VECTACTIVE */
    return 0;
}

void arm_v8m_cm85_scb_set_sleepmode(arm_v8m_cm85_scb_sleepmode_t mode)
{
    /* TODO: Set sleep mode */
    (void)mode;
}

void arm_v8m_cm85_scb_enable_sleeponexit(void)
{
    /* TODO: Enable sleep on exit */
}

void arm_v8m_cm85_scb_disable_sleeponexit(void)
{
    /* TODO: Disable sleep on exit */
}

void arm_v8m_cm85_scb_enable_sevonpend(void)
{
    /* TODO: Enable SEV on pend */
}

void arm_v8m_cm85_scb_disable_sevonpend(void)
{
    /* TODO: Disable SEV on pend */
}

void arm_v8m_cm85_scb_enable_faults(void)
{
    /* TODO: Enable fault handlers */
}

void arm_v8m_cm85_scb_disable_faults(void)
{
    /* TODO: Disable fault handlers */
}

uint32_t arm_v8m_cm85_scb_get_fault_status(void)
{
    /* TODO: Get fault status */
    return 0;
}

void arm_v8m_cm85_scb_clear_fault_status(uint32_t mask)
{
    /* TODO: Clear fault status */
    (void)mask;
}

uint32_t arm_v8m_cm85_scb_get_hardfault_status(void)
{
    /* TODO: Get HardFault status */
    return 0;
}

void arm_v8m_cm85_scb_clear_hardfault_status(uint32_t mask)
{
    /* TODO: Clear HardFault status */
    (void)mask;
}

uint32_t arm_v8m_cm85_scb_get_mmfar(void)
{
    /* TODO: Get MMFAR */
    return 0;
}

uint32_t arm_v8m_cm85_scb_get_bfar(void)
{
    /* TODO: Get BFAR */
    return 0;
}

bool arm_v8m_cm85_scb_has_fpu(void)
{
    /* TODO: Check FPU support */
    return false;
}

bool arm_v8m_cm85_scb_has_mve(void)
{
    /* TODO: Check MVE support */
    return false;
}

bool arm_v8m_cm85_scb_has_dsp(void)
{
    /* TODO: Check DSP support */
    return false;
}

bool arm_v8m_cm85_scb_has_security(void)
{
    /* TODO: Check TrustZone support */
    return false;
}

bool arm_v8m_cm85_scb_has_mpu(void)
{
    /* TODO: Check MPU support */
    return false;
}

bool arm_v8m_cm85_scb_has_cache(void)
{
    /* TODO: Check cache support */
    return false;
}

void arm_v8m_cm85_scb_enable_icache(void)
{
    /* TODO: Enable I-cache */
}

void arm_v8m_cm85_scb_disable_icache(void)
{
    /* TODO: Disable I-cache */
}

void arm_v8m_cm85_scb_enable_dcache(void)
{
    /* TODO: Enable D-cache */
}

void arm_v8m_cm85_scb_disable_dcache(void)
{
    /* TODO: Disable D-cache */
}

void arm_v8m_cm85_scb_enable_branch_prediction(void)
{
    /* TODO: Enable branch prediction */
}

void arm_v8m_cm85_scb_disable_branch_prediction(void)
{
    /* TODO: Disable branch prediction */
}

void arm_v8m_cm85_scb_set_cpacr(uint32_t value)
{
    /* TODO: Set CPACR */
    (void)value;
}

uint32_t arm_v8m_cm85_scb_get_cpacr(void)
{
    /* TODO: Get CPACR */
    return 0;
}

void arm_v8m_cm85_scb_enable_coproc(uint32_t cp)
{
    /* TODO: Enable coprocessor access */
    (void)cp;
}

void arm_v8m_cm85_scb_disable_coproc(uint32_t cp)
{
    /* TODO: Disable coprocessor access */
    (void)cp;
}

#ifdef __ARM_FEATURE_CMSE
void arm_v8m_cm85_scb_set_nsacr(uint32_t value)
{
    /* TODO: Set NSACR */
    (void)value;
}

uint32_t arm_v8m_cm85_scb_get_nsacr(void)
{
    /* TODO: Get NSACR */
    return 0;
}
#endif
