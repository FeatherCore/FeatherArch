/*
 * ARM Architecture - ARMv7-M Debug and Trace
 *
 * ============================================================================
 * File: armv7-m_debug.c
 * Description: ARMv7-M debug and trace function implementations
 * 描述: ARMv7-M 调试和跟踪函数实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter C1: Debug
 *   - Table C1-21 DWT register summary (page C1-736)
 *   - Table C1-11 ITM register summary (page C1-713)
 *   - Table C1-22 FPB register summary (page C1-756)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_debug.h"

/*
 * ============================================================================
 * DWT (Data Watchpoint and Trace) Functions
 * DWT 函数
 * Reference: Chapter C1.8 - The Data Watchpoint and Trace unit
 * ============================================================================
 */

void dwt_enable(void)
{
    DWT_CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

void dwt_disable(void)
{
    DWT_CTRL &= ~DWT_CTRL_CYCCNTENA_Msk;
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
    if (comp < dwt_get_num_comparators()) {
        DWT_COMP(comp) = addr;
        DWT_FUNCTION(comp) = action & DWT_FUNCTION_FUNCTION_Msk;
    }
}

void dwt_enable_comparator(uint32_t comp)
{
    if (comp < dwt_get_num_comparators()) {
        uint32_t function = DWT_FUNCTION(comp);
        function &= ~DWT_FUNCTION_FUNCTION_Msk;
        function |= DWT_FUNCTION_FUNCTION_INSTR_ADDR;
        DWT_FUNCTION(comp) = function;
    }
}

void dwt_disable_comparator(uint32_t comp)
{
    if (comp < dwt_get_num_comparators()) {
        DWT_FUNCTION(comp) = DWT_FUNCTION_FUNCTION_DISABLED;
    }
}

/*
 * ============================================================================
 * ITM (Instrumentation Trace Macrocell) Functions
 * ITM 函数
 * Reference: Chapter C1.7 - The Instrumentation Trace Macrocell
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
        return ch;
    }
    return -1;
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
 * Reference: Chapter C1.11 - Flash Patch and Breakpoint unit
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
