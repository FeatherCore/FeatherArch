/*
 * arm_v8m_debug.c
 * Armv8-M Debug Support Implementation
 * Reference: Armv8-M Architecture Reference Manual, Chapters B13-B14
 */

#include "arm_v8m_debug.h"

/*============================================================================*
 * Debug Base Addresses (Architecture defined)
 *============================================================================*/
#define DEBUG_BASE          0xE000EDF0UL
#define DWT_BASE            0xE0001000UL
#define FPB_BASE            0xE0002000UL

#define DEBUG               ((arm_v8m_debug_regs_t *)DEBUG_BASE)
#define DWT                 ((arm_v8m_dwt_regs_t *)DWT_BASE)
#define FPB                 ((arm_v8m_fpb_regs_t *)FPB_BASE)

/*============================================================================*
 * Debug Implementation
 *============================================================================*/

void arm_v8m_debug_enable_trace(void)
{
    /* TODO: Enable TRCENA in DEMCR */
}

void arm_v8m_debug_disable_trace(void)
{
    /* TODO: Disable TRCENA in DEMCR */
}

uint32_t arm_v8m_debug_is_halted(void)
{
    /* TODO: Check S_HALT bit in DHCSR */
    return 0;
}

void arm_v8m_debug_halt(void)
{
    /* TODO: Set C_HALT in DHCSR with debug key */
}

void arm_v8m_debug_resume(void)
{
    /* TODO: Clear C_HALT in DHCSR with debug key */
}

void arm_v8m_debug_step(void)
{
    /* TODO: Set C_STEP in DHCSR with debug key */
}

/*============================================================================*
 * DWT Implementation
 *============================================================================*/

void arm_v8m_dwt_enable_cyccnt(void)
{
    /* TODO: Enable CYCCNTENA in DWT_CTRL */
}

void arm_v8m_dwt_disable_cyccnt(void)
{
    /* TODO: Disable CYCCNTENA in DWT_CTRL */
}

uint32_t arm_v8m_dwt_get_cyccnt(void)
{
    /* TODO: Read DWT_CYCCNT */
    return 0;
}

void arm_v8m_dwt_set_cyccnt(uint32_t value)
{
    /* TODO: Write DWT_CYCCNT */
    (void)value;
}

void arm_v8m_dwt_enable_exception_trace(void)
{
    /* TODO: Enable EXCTRCENA in DWT_CTRL */
}

void arm_v8m_dwt_enable_pc_sampling(uint32_t interval)
{
    /* TODO: Configure PC sampling with given interval */
    (void)interval;
}

/*============================================================================*
 * FPB Implementation
 *============================================================================*/

void arm_v8m_fpb_enable(void)
{
    /* TODO: Set ENABLE bit in FPB_CTRL */
}

void arm_v8m_fpb_disable(void)
{
    /* TODO: Clear ENABLE bit in FPB_CTRL */
}

void arm_v8m_fpb_set_breakpoint(uint32_t comp_id, uint32_t addr)
{
    /* TODO: Configure FPB_COMP register */
    (void)comp_id;
    (void)addr;
}

void arm_v8m_fpb_clear_breakpoint(uint32_t comp_id)
{
    /* TODO: Clear FPB_COMP register */
    (void)comp_id;
}

/*============================================================================*
 * Debug Authentication
 *============================================================================*/

uint32_t arm_v8m_debug_get_auth_status(void)
{
    /* TODO: Read debug authentication status */
    return 0;
}

void arm_v8m_debug_set_auth(uint32_t dbgen, uint32_t spiden)
{
    /* TODO: Set debug authentication */
    (void)dbgen;
    (void)spiden;
}
