/*
 * ARM Architecture - ARMv8-M Debug and Trace
 *
 * ============================================================================
 * File: armv8m_debug.c
 * Description: ARMv8-M debug and trace function implementations
 * 描述: ARMv8-M 调试和跟踪函数实现
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B13: Debug
 *   - Chapter B14: Debug and Trace Components
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv8-m/armv8-m_debug.h"

/*
 * ============================================================================
 * DWT (Data Watchpoint and Trace) Functions
 * DWT 函数
 * ============================================================================
 */

void dwt_enable(void)
{
    DWT_CTRL |= (DWT_CTRL_CYCCNTENA_Msk);
}

void dwt_disable(void)
{
    DWT_CTRL &= ~(DWT_CTRL_CYCCNTENA_Msk);
}

void dwt_enable_cycle_counter(void)
{
    DWT_CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

void dwt_disable_cycle_counter(void)
{
    DWT_CTRL &= ~DWT_CTRL_CYCCNTENA_Msk;
}

void dwt_configure_comparator(uint32_t comp, uint32_t addr, uint32_t action)
{
    DWT_COMP(comp) = addr;
    DWT_FUNCTION(comp) = action & DWT_FUNCTION_ACTION_Msk;
}

void dwt_enable_comparator(uint32_t comp)
{
    DWT_FUNCTION(comp) |= DWT_FUNCTION_ACTION_WATCHPOINT;
}

void dwt_disable_comparator(uint32_t comp)
{
    DWT_FUNCTION(comp) &= ~DWT_FUNCTION_ACTION_Msk;
}

/*
 * ============================================================================
 * ITM (Instrumentation Trace Macrocell) Functions
 * ITM 函数
 * ============================================================================
 */

void itm_enable(void)
{
    ITM_TCR = ITM_TCR_ITMENA_Msk;
}

void itm_disable(void)
{
    ITM_TCR &= ~ITM_TCR_ITMENA_Msk;
}

int32_t itm_send_char(int32_t ch)
{
    if (ITM_STIM(0) & 0x1U) {
        ITM_STIM(0) = (uint8_t)ch;
    }
    return ch;
}

int32_t itm_receive_char(void)
{
    return -1;
}

void itm_enable_stimulus_port(uint32_t port)
{
    if (port < 32) {
        ITM_TER(port / 32) |= (1UL << (port % 32));
    }
}

void itm_disable_stimulus_port(uint32_t port)
{
    if (port < 32) {
        ITM_TER(port / 32) &= ~(1UL << (port % 32));
    }
}

/*
 * ============================================================================
 * FPB (Flash Patch and Breakpoint) Functions
 * FPB 函数
 * ============================================================================
 */

void fpb_enable(void)
{
    FP_CTRL |= FP_CTRL_ENABLE_Msk;
}

void fpb_disable(void)
{
    FP_CTRL &= ~FP_CTRL_ENABLE_Msk;
}

int32_t fpb_set_breakpoint(uint32_t bp, uint32_t addr)
{
    if (bp >= fpb_get_num_breakpoints()) {
        return -1;
    }
    
    FP_COMP(bp) = (addr & FP_COMP_COMP_Msk) | FP_COMP_ENABLE_Msk;
    return 0;
}

void fpb_clear_breakpoint(uint32_t bp)
{
    if (bp < fpb_get_num_breakpoints()) {
        FP_COMP(bp) = 0;
    }
}

uint32_t fpb_get_num_breakpoints(void)
{
    return (FP_CTRL & FP_CTRL_NUM_CODE_Msk) >> FP_CTRL_NUM_CODE_Pos;
}

uint32_t fpb_get_num_literals(void)
{
    return (FP_CTRL & FP_CTRL_NUM_LIT_Msk) >> FP_CTRL_NUM_LIT_Pos;
}
