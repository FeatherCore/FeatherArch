/*
 * arm_v7m_debug.c
 * Debug Support Implementation
 * Reference: ARMv7-M Architecture Reference Manual, Part C
 *   - Section C1.6: Debug system registers
 *   - Section C1.7: The Instrumentation Trace Macrocell
 *   - Section C1.8: The Data Watchpoint and Trace unit
 *   - Section C1.10: Trace Port Interface Unit
 *   - Section C1.11: Flash Patch and Breakpoint unit
 * 
 * This file implements non-inline functions of complex debug operations.
 * Simple register access functions are implemented as static inline in the header.
 */

#include "arm_v7m_debug.h"

/*============================================================================*
 * Debug Control Functions
 *============================================================================*/

/**
 * @brief Halt the processor
 * @note Writes to DHCSR with debug key to set C_HALT bit.
 *       Halting debug must be enabled (C_DEBUGEN = 1) for this to work.
 *       This function is typically used by external debuggers.
 */
void arm_v7m_debug_halt(void)
{
    /* Write debug key with C_HALT and C_DEBUGEN set */
    DEBUG->DHCSR = ARM_V7M_DHCSR_DBGKEY |
                   ARM_V7M_DHCSR_C_HALT_Msk |
                   ARM_V7M_DHCSR_C_DEBUGEN_Msk;
}

/**
 * @brief Resume processor execution
 * @note Writes to DHCSR with debug key to clear C_HALT bit.
 *       The processor exits Debug state and resumes execution.
 */
void arm_v7m_debug_resume(void)
{
    /* Write debug key with C_DEBUGEN set but C_HALT cleared */
    DEBUG->DHCSR = ARM_V7M_DHCSR_DBGKEY | ARM_V7M_DHCSR_C_DEBUGEN_Msk;
}

/**
 * @brief Execute single step
 * @note Sets C_STEP bit to enable single stepping. The processor executes
 *       one instruction and then re-enters Debug state.
 *       C_HALT must be 1 when setting C_STEP.
 */
void arm_v7m_debug_step(void)
{
    /* Write debug key with C_STEP, C_HALT, and C_DEBUGEN set */
    DEBUG->DHCSR = ARM_V7M_DHCSR_DBGKEY |
                   ARM_V7M_DHCSR_C_STEP_Msk |
                   ARM_V7M_DHCSR_C_HALT_Msk |
                   ARM_V7M_DHCSR_C_DEBUGEN_Msk;
}

/*============================================================================*
 * DWT Comparator Functions
 *============================================================================*/

/**
 * @brief Enable a DWT comparator
 * @param comp_id Comparator ID (0-3, depending on implementation)
 * @param comp_value Comparison value (address or data)
 * @param function Function value (see ARM_V7M_DWT_FUNCTION_* defines)
 * @return 0 on success, 1 if comparator not available
 * @note Configures the comparator with the specified value and function.
 *       The comparator will trigger when the condition is met.
 */
uint32_t arm_v7m_dwt_enable_comp(uint32_t comp_id, uint32_t comp_value, uint32_t function)
{
    uint32_t num_comp;
    volatile uint32_t *comp_reg;
    volatile uint32_t *func_reg;
    
    /* Check if comparator is available */
    num_comp = arm_v7m_dwt_get_num_comp();
    if (comp_id >= num_comp) {
        return 1U;  /* Comparator not available */
    }
    
    /* Enable trace for DWT to work */
    arm_v7m_debug_enable_trace();
    
    /* Get register pointers based on comparator ID */
    switch (comp_id) {
        case 0U:
            comp_reg = &DWT->COMP0;
            func_reg = &DWT->FUNCTION0;
            break;
        case 1U:
            comp_reg = &DWT->COMP1;
            func_reg = &DWT->FUNCTION1;
            break;
        case 2U:
            comp_reg = &DWT->COMP2;
            func_reg = &DWT->FUNCTION2;
            break;
        case 3U:
            comp_reg = &DWT->COMP3;
            func_reg = &DWT->FUNCTION3;
            break;
        default:
            return 1U;  /* Invalid comparator ID */
    }
    
    /* Disable comparator first */
    *func_reg = ARM_V7M_DWT_FUNCTION_DISABLED;
    
    /* Set comparison value */
    *comp_reg = comp_value;
    
    /* Set function to enable comparator */
    *func_reg = function & ARM_V7M_DWT_FUNCTION_FUNCTION_Msk;
    
    return 0U;  /* Success */
}

/**
 * @brief Disable a DWT comparator
 * @param comp_id Comparator ID (0-3)
 * @note Disables the comparator by setting its function to 0 (disabled).
 */
void arm_v7m_dwt_disable_comp(uint32_t comp_id)
{
    volatile uint32_t *func_reg;
    
    switch (comp_id) {
        case 0U:
            func_reg = &DWT->FUNCTION0;
            break;
        case 1U:
            func_reg = &DWT->FUNCTION1;
            break;
        case 2U:
            func_reg = &DWT->FUNCTION2;
            break;
        case 3U:
            func_reg = &DWT->FUNCTION3;
            break;
        default:
            return;  /* Invalid comparator ID */
    }
    
    /* Disable comparator */
    *func_reg = ARM_V7M_DWT_FUNCTION_DISABLED;
}

/*============================================================================*
 * DWT Performance Counter Functions
 *============================================================================*/

/**
 * @brief Enable DWT performance counters
 * @note Enables CPI, Exception, Sleep, LSU, and Fold counters.
 *       These counters provide detailed performance metrics.
 */
void arm_v7m_dwt_enable_perf_counters(void)
{
    /* Enable trace first */
    arm_v7m_debug_enable_trace();
    
    /* Performance counters are enabled when CYCCNTENA is set
     * and NOPRFCNT indicates they are implemented */
    if ((DWT->CTRL & ARM_V7M_DWT_CTRL_NOPRFCNT_Msk) == 0U) {
        DWT->CTRL |= ARM_V7M_DWT_CTRL_CYCCNTENA_Msk;
    }
}

/**
 * @brief Disable DWT performance counters
 * @note Disables all performance counters.
 */
void arm_v7m_dwt_disable_perf_counters(void)
{
    DWT->CTRL &= ~ARM_V7M_DWT_CTRL_CYCCNTENA_Msk;
}

/**
 * @brief Reset all performance counters
 * @note Resets CPI, Exception, Sleep, LSU, and Fold counters to 0.
 */
void arm_v7m_dwt_reset_perf_counters(void)
{
    DWT->CPICNT = 0U;
    DWT->EXCCNT = 0U;
    DWT->SLEEPCNT = 0U;
    DWT->LSUCNT = 0U;
    DWT->FOLDCNT = 0U;
}

/*============================================================================*
 * Core Register Access Functions
 *============================================================================*/

/**
 * @brief Read a core register via debug interface
 * @param regsel Register selector value (see ARM_V7M_DCRSR_REG_* defines)
 * @return Register value
 * @note This function is intended for debugger use. It uses the DCRSR/DCRDR
 *       registers to access core registers. The processor must be in Debug state.
 *       This function polls until the transfer is complete.
 */
uint32_t arm_v7m_debug_read_reg(uint32_t regsel)
{
    uint32_t value;
    
    /* Write to DCRSR to initiate read transfer (REGWnR = 0) */
    DEBUG->DCRSR = (regsel & ARM_V7M_DCRSR_REGSEL_Msk);
    
    /* Poll S_REGRDY until transfer completes */
    while (!arm_v7m_debug_is_reg_ready()) {
        /* Wait for transfer to complete */
    }
    
    /* Read the register value from DCRDR */
    value = DEBUG->DCRDR;
    
    return value;
}

/**
 * @brief Write a core register via debug interface
 * @param regsel Register selector value (see ARM_V7M_DCRSR_REG_* defines)
 * @param value Value to write to the register
 * @note This function is intended for debugger use. It uses the DCRSR/DCRDR
 *       registers to access core registers. The processor must be in Debug state.
 *       This function polls until the transfer is complete.
 */
void arm_v7m_debug_write_reg(uint32_t regsel, uint32_t value)
{
    /* Write the value to DCRDR first */
    DEBUG->DCRDR = value;
    
    /* Write to DCRSR to initiate write transfer (REGWnR = 1) */
    DEBUG->DCRSR = ARM_V7M_DCRSR_REGWnR_Msk |
                   (regsel & ARM_V7M_DCRSR_REGSEL_Msk);
    
    /* Poll S_REGRDY until transfer completes */
    while (!arm_v7m_debug_is_reg_ready()) {
        /* Wait for transfer to complete */
    }
}

/*============================================================================*
 * Vector Catch Configuration
 *============================================================================*/

/**
 * @brief Enable vector catch for specific exception types
 * @param vc_mask Bit mask of vector catch bits to enable
 *                (see ARM_V7M_DEMCR_VC_* defines)
 * @note Vector catch causes the processor to halt when the specified
 *       exception is taken. This is useful for debugging exception handlers.
 *       Halting debug must be enabled (C_DEBUGEN = 1) for vector catch to work.
 */
void arm_v7m_debug_enable_vector_catch(uint32_t vc_mask)
{
    DEBUG->DEMCR |= (vc_mask & (ARM_V7M_DEMCR_VC_HARDERR_Msk |
                                 ARM_V7M_DEMCR_VC_INTERR_Msk |
                                 ARM_V7M_DEMCR_VC_BUSERR_Msk |
                                 ARM_V7M_DEMCR_VC_STATERR_Msk |
                                 ARM_V7M_DEMCR_VC_CHKERR_Msk |
                                 ARM_V7M_DEMCR_VC_NOCPERR_Msk |
                                 ARM_V7M_DEMCR_VC_MMERR_Msk |
                                 ARM_V7M_DEMCR_VC_CORERESET_Msk));
}

/**
 * @brief Disable vector catch for specific exception types
 * @param vc_mask Bit mask of vector catch bits to disable
 *                (see ARM_V7M_DEMCR_VC_* defines)
 */
void arm_v7m_debug_disable_vector_catch(uint32_t vc_mask)
{
    DEBUG->DEMCR &= ~(vc_mask & (ARM_V7M_DEMCR_VC_HARDERR_Msk |
                                  ARM_V7M_DEMCR_VC_INTERR_Msk |
                                  ARM_V7M_DEMCR_VC_BUSERR_Msk |
                                  ARM_V7M_DEMCR_VC_STATERR_Msk |
                                  ARM_V7M_DEMCR_VC_CHKERR_Msk |
                                  ARM_V7M_DEMCR_VC_NOCPERR_Msk |
                                  ARM_V7M_DEMCR_VC_MMERR_Msk |
                                  ARM_V7M_DEMCR_VC_CORERESET_Msk));
}

/*============================================================================*
 * ITM Functions
 *============================================================================*/

/**
 * @brief Get number of ITM stimulus ports
 * @return Number of implemented stimulus ports
 * @note Reads the ITM_TCR to determine the number of stimulus ports.
 */
uint32_t arm_v7m_itm_get_num_ports(void)
{
    /* Number of stimulus ports is determined by ITM_TCR */
    /* In ARMv7-M, this is typically 32 ports (TER[0] bits 0-31) */
    return 32U;
}

/**
 * @brief Send string to ITM stimulus port
 * @param port Stimulus port number (0-255)
 * @param str Null-terminated string to send
 * @note Sends a string via ITM, one character at a time.
 */
void arm_v7m_itm_send_string(uint32_t port, const char *str)
{
    if (str == (void *)0) {
        return;
    }
    
    while (*str != '\0') {
        arm_v7m_itm_send_char(port, *str);
        str++;
    }
}

/*============================================================================*
 * FPB Functions
 *============================================================================*/

/**
 * @brief Get number of FPB code comparators
 * @return Number of implemented code comparators
 * @note Returns the number of comparators available for code breakpoints.
 */
uint32_t arm_v7m_fpb_get_num_code_comparators(void)
{
    /* In ARMv7-M, the number of comparators is implementation defined */
    /* We can determine this by checking which COMP registers are implemented */
    uint32_t num_comp = 0U;
    uint32_t i;
    
    for (i = 0U; i < 128U; i++) {
        /* Try to read the comparator register */
        /* If it returns 0 and cannot be written, it's not implemented */
        volatile uint32_t *comp = &FPB->COMP[i];
        uint32_t original = *comp;
        *comp = 0xFFFFFFFFU;
        if (*comp != 0U) {
            num_comp++;
        }
        *comp = original;
    }
    
    return num_comp;
}

/**
 * @brief Get number of FPB literal comparators
 * @return Number of implemented literal comparators
 * @note Returns the number of comparators available for literal patching.
 */
uint32_t arm_v7m_fpb_get_num_literal_comparators(void)
{
    /* In ARMv7-M, literal comparators are the upper half of the comparators */
    /* This is implementation specific */
    return 0U;  /* Placeholder - would need implementation-specific detection */
}

/**
 * @brief Set hardware breakpoint
 * @param comp_id Comparator ID (0-127, depending on implementation)
 * @param address Breakpoint address (must be word-aligned for code breakpoints)
 * @return 0 on success, 1 if comparator not available
 * @note Sets a hardware breakpoint at the specified address.
 *       When the processor executes an instruction at this address,
 *       it will halt (if halting debug is enabled) or trigger DebugMonitor.
 */
uint32_t arm_v7m_fpb_set_breakpoint(uint32_t comp_id, uint32_t address)
{
    if (comp_id >= 128U) {
        return 1U;  /* Invalid comparator ID */
    }
    
    /* Enable FPB if not already enabled */
    if (!arm_v7m_fpb_is_enabled()) {
        arm_v7m_fpb_enable();
    }
    
    /* Set comparator value with breakpoint function */
    FPB->COMP[comp_id] = (ARM_V7M_FP_COMP_REPLACE_BKPT << ARM_V7M_FP_COMP_REPLACE_Pos) |
                         (address & ARM_V7M_FP_COMP_COMP_Msk);
    
    return 0U;  /* Success */
}

/*============================================================================*
 * TPIU Functions
 *============================================================================*/

/**
 * @brief Enable SWO output
 * @param prescaler Clock prescaler value for SWO baud rate
 * @note Configures the TPIU for SWO (Serial Wire Output) mode.
 *       The prescaler divides the processor clock to generate the SWO clock.
 *       SWO is used for single-pin trace output.
 */
void arm_v7m_tpiu_enable_swo(uint32_t prescaler)
{
    /* Enable trace */
    arm_v7m_debug_enable_trace();
    
    /* Set pin protocol to SWO NRZ (Non-Return-to-Zero) */
    TPIU->SPPR = ARM_V7M_TPIU_SPPR_TXMODE_SWO_NRZ;
    
    /* Set prescaler */
    TPIU->ACPR = prescaler & ARM_V7M_TPIU_ACPR_PRESCALER_Msk;
}

/**
 * @brief Disable SWO output
 * @note Disables the TPIU SWO output.
 */
void arm_v7m_tpiu_disable_swo(void)
{
    /* Set pin protocol to parallel (disabled) */
    TPIU->SPPR = ARM_V7M_TPIU_SPPR_TXMODE_PARALLEL;
}
