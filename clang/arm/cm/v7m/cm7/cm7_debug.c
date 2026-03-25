/*
 * cm7_debug.c
 * Cortex-M7 Debug Support Implementation
 * Reference: Cortex-M7 Technical Reference Manual, Chapters 9-13
 */

#include "cm7_debug.h"

/*============================================================================*
 * Debug Base Addresses (Architecture defined)
 *============================================================================*/
#define DEBUG_BASE          0xE000EDF0UL
#define DWT_BASE            0xE0001000UL
#define FPB_BASE            0xE0002000UL
#define CTI_BASE            0xE0042000UL

#define DEBUG               ((cm7_debug_regs_t *)DEBUG_BASE)
#define DWT                 ((cm7_dwt_regs_t *)DWT_BASE)
#define FPB                 ((cm7_fpb_regs_t *)FPB_BASE)
#define CTI                 ((cm7_cti_regs_t *)CTI_BASE)

/*============================================================================*
 * Debug Implementation
 *============================================================================*/

void cm7_debug_enable_trace(void)
{
    /* TODO: Enable TRCENA in DEMCR */
}

void cm7_debug_disable_trace(void)
{
    /* TODO: Disable TRCENA in DEMCR */
}

uint32_t cm7_debug_is_halted(void)
{
    /* TODO: Check S_HALT bit in DHCSR */
    return 0;
}

void cm7_debug_halt(void)
{
    /* TODO: Set C_HALT in DHCSR with debug key */
}

void cm7_debug_resume(void)
{
    /* TODO: Clear C_HALT in DHCSR with debug key */
}

void cm7_debug_step(void)
{
    /* TODO: Set C_STEP in DHCSR with debug key */
}

/*============================================================================*
 * DWT Implementation
 *============================================================================*/

void cm7_dwt_enable_cyccnt(void)
{
    /* TODO: Enable CYCCNTENA in DWT_CTRL */
}

void cm7_dwt_disable_cyccnt(void)
{
    /* TODO: Disable CYCCNTENA in DWT_CTRL */
}

uint32_t cm7_dwt_get_cyccnt(void)
{
    /* TODO: Read DWT_CYCCNT */
    return 0;
}

void cm7_dwt_set_cyccnt(uint32_t value)
{
    /* TODO: Write DWT_CYCCNT */
    (void)value;
}

void cm7_dwt_enable_exception_trace(void)
{
    /* TODO: Enable EXCTRCENA in DWT_CTRL */
}

void cm7_dwt_enable_pc_sampling(uint32_t interval)
{
    /* TODO: Configure PC sampling with given interval */
    (void)interval;
}

/*============================================================================*
 * FPB Implementation
 *============================================================================*/

void cm7_fpb_enable(void)
{
    /* TODO: Set ENABLE bit in FPB_CTRL */
}

void cm7_fpb_disable(void)
{
    /* TODO: Clear ENABLE bit in FPB_CTRL */
}

void cm7_fpb_set_breakpoint(uint32_t comp_id, uint32_t addr)
{
    /* TODO: Configure FPB_COMP register */
    (void)comp_id;
    (void)addr;
}

void cm7_fpb_clear_breakpoint(uint32_t comp_id)
{
    /* TODO: Clear FPB_COMP register */
    (void)comp_id;
}

/*============================================================================*
 * CTI Implementation
 *============================================================================*/

void cm7_cti_enable(void)
{
    /* TODO: Set GLBEN bit in CTICONTROL */
}

void cm7_cti_disable(void)
{
    /* TODO: Clear GLBEN bit in CTICONTROL */
}

void cm7_cti_trigger_output(uint32_t channel)
{
    /* TODO: Set trigger output in CTIAPPPULSE */
    (void)channel;
}

void cm7_cti_clear_trigger(uint32_t channel)
{
    /* TODO: Clear trigger in CTIAPPCLEAR */
    (void)channel;
}
