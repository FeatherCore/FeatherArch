/*
 * arm_v8m_cm55_debug.c
 * Cortex-M55 Debug Support Implementation
 * Reference: Cortex-M55 Technical Reference Manual, Chapter 18
 */

#include "arm_v8m_cm55_debug.h"

/*============================================================================*
 * Debug Base Addresses (Architecture defined)
 *============================================================================*/
#define DEBUG_BASE          0xE000EDF0UL
#define DWT_BASE            0xE0001000UL
#define BPU_BASE            0xE0002000UL

#define DEBUG               ((arm_v8m_cm55_debug_regs_t *)DEBUG_BASE)
#define DWT                 ((arm_v8m_cm55_dwt_regs_t *)DWT_BASE)
#define BPU                 ((arm_v8m_cm55_bpu_regs_t *)BPU_BASE)

/*============================================================================*
 * Debug Implementation
 *============================================================================*/

void arm_v8m_cm55_debug_enable_trace(void)
{
    /* TODO: Enable TRCENA in DEMCR */
}

void arm_v8m_cm55_debug_disable_trace(void)
{
    /* TODO: Disable TRCENA in DEMCR */
}

uint32_t arm_v8m_cm55_debug_is_halted(void)
{
    /* TODO: Check S_HALT bit in DHCSR */
    return 0;
}

void arm_v8m_cm55_debug_halt(void)
{
    /* TODO: Set C_HALT in DHCSR with debug key */
}

void arm_v8m_cm55_debug_resume(void)
{
    /* TODO: Clear C_HALT in DHCSR with debug key */
}

void arm_v8m_cm55_debug_step(void)
{
    /* TODO: Set C_STEP in DHCSR with debug key */
}

/*============================================================================*
 * DWT Implementation
 *============================================================================*/

void arm_v8m_cm55_dwt_enable_cyccnt(void)
{
    /* TODO: Enable CYCCNTENA in DWT_CTRL */
}

void arm_v8m_cm55_dwt_disable_cyccnt(void)
{
    /* TODO: Disable CYCCNTENA in DWT_CTRL */
}

uint32_t arm_v8m_cm55_dwt_get_cyccnt(void)
{
    /* TODO: Read DWT_CYCCNT */
    return 0;
}

void arm_v8m_cm55_dwt_set_cyccnt(uint32_t value)
{
    /* TODO: Write DWT_CYCCNT */
    (void)value;
}

void arm_v8m_cm55_dwt_enable_exception_trace(void)
{
    /* TODO: Enable EXCTRCENA in DWT_CTRL */
}

void arm_v8m_cm55_dwt_enable_pc_sampling(uint32_t interval)
{
    /* TODO: Configure PC sampling with given interval */
    (void)interval;
}

/*============================================================================*
 * BPU Implementation
 *============================================================================*/

void arm_v8m_cm55_bpu_enable(void)
{
    /* TODO: Set ENABLE bit in BPU_CTRL */
}

void arm_v8m_cm55_bpu_disable(void)
{
    /* TODO: Clear ENABLE bit in BPU_CTRL */
}

void arm_v8m_cm55_bpu_set_breakpoint(uint32_t comp_id, uint32_t addr)
{
    /* TODO: Configure BPU_COMP register */
    (void)comp_id;
    (void)addr;
}

void arm_v8m_cm55_bpu_clear_breakpoint(uint32_t comp_id)
{
    /* TODO: Clear BPU_COMP register */
    (void)comp_id;
}

/*============================================================================*
 * Debug Authentication
 *============================================================================*/

uint32_t arm_v8m_cm55_debug_get_auth_status(void)
{
    /* TODO: Read debug authentication status */
    return 0;
}

void arm_v8m_cm55_debug_set_auth(uint32_t dbgen, uint32_t spiden)
{
    /* TODO: Set debug authentication */
    (void)dbgen;
    (void)spiden;
}
