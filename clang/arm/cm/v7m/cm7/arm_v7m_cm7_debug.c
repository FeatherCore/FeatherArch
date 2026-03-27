/*
 * arm_v7m_cm7_debug.c
 * Cortex-M7 Debug Support Implementation
 * Reference: ARMv7-M Architecture Reference Manual, Part C
 *            - Section C1.6: Debug system registers on page C1-699
 *            - Section C1.6.2: Debug Halting Control and Status Register, DHCSR on page C1-700
 *            - Section C1.6.3: Debug Core Register Selector Register, DCRSR on page C1-703
 *            - Section C1.6.4: Debug Core Register Data Register, DCRDR on page C1-704
 *            - Section C1.6.5: Debug Exception and Monitor Control Register, DEMCR on page C1-706
 *            - Section C1.7: The Instrumentation Trace Macrocell (ITM) on page C1-709
 *            - Section C1.8: The Data Watchpoint and Trace unit (DWT) on page C1-717
 *            - Section C1.10: Trace Port Interface Unit (TPIU) on page C1-736
 *            - Section C1.11: Flash Patch and Breakpoint unit (FPB) on page C1-742
 *            Cortex-M7 Devices Generic User Guide, Chapter 10
 *            - About debug on page 10-2
 *            - Debug register summary on page 10-2
 *            Cortex-M7 Technical Reference Manual
 *            - Chapter 9: Debug on page 9-1
 *            - Chapter 10: Cross Trigger Interface (CTI) on page 10-1
 *            - Chapter 11: Data Watchpoint and Trace Unit (DWT) on page 11-1
 *            - Chapter 12: Instrumentation Trace Macrocell Unit (ITM) on page 12-1
 *
 * This file wraps the generic Armv7-M debug implementation for Cortex-M7.
 * All functions delegate to the generic v7m implementation.
 *
 * @note This file wraps the generic Armv7-M debug implementation.
 */

#include "arm_v7m_cm7_debug.h"

/*============================================================================*
 * Debug Control Functions
 *============================================================================*/

/**
 * @brief Halt the processor
 *
 * According to ARMv7-M Architecture Reference Manual, Section C1.6.2:
 * - Writes to DHCSR with debug key to set C_HALT bit
 * - Halting debug must be enabled (C_DEBUGEN = 1) for this to work
 * - This function is typically used by external debuggers
 */
void arm_v7m_cm7_debug_halt(void)
{
    arm_v7m_debug_halt();
}

/**
 * @brief Resume processor execution
 *
 * According to ARMv7-M Architecture Reference Manual, Section C1.6.2:
 * - Writes to DHCSR with debug key to clear C_HALT bit
 * - The processor exits Debug state and resumes execution
 */
void arm_v7m_cm7_debug_resume(void)
{
    arm_v7m_debug_resume();
}

/**
 * @brief Execute single step
 *
 * According to ARMv7-M Architecture Reference Manual, Section C1.6.2:
 * - Sets C_STEP bit to enable single stepping
 * - The processor executes one instruction and then re-enters Debug state
 * - C_HALT must be 1 when setting C_STEP
 */
void arm_v7m_cm7_debug_step(void)
{
    arm_v7m_debug_step();
}

/*============================================================================*
 * DWT Comparator Functions
 *============================================================================*/

/**
 * @brief Enable a DWT comparator
 *
 * According to ARMv7-M Architecture Reference Manual, Section C1.8:
 * - Configures the comparator with the specified value and function
 * - The comparator will trigger when the condition is met
 *
 * @param comp_id Comparator ID (0-3, depending on implementation)
 * @param comp_value Comparison value (address or data)
 * @param function Function value (see ARM_V7M_CM7_DWT_FUNCTION_* defines)
 * @return 0 on success, 1 if comparator not available
 */
uint32_t arm_v7m_cm7_dwt_enable_comp(uint32_t comp_id, uint32_t comp_value, uint32_t function)
{
    return arm_v7m_dwt_enable_comp(comp_id, comp_value, function);
}

/**
 * @brief Disable a DWT comparator
 *
 * @param comp_id Comparator ID (0-3)
 */
void arm_v7m_cm7_dwt_disable_comp(uint32_t comp_id)
{
    arm_v7m_dwt_disable_comp(comp_id);
}

/*============================================================================*
 * DWT Performance Counter Functions
 *============================================================================*/

/**
 * @brief Enable DWT performance counters
 *
 * According to ARMv7-M Architecture Reference Manual, Section C1.8:
 * - Enables CPI, Exception, Sleep, LSU, and Fold counters
 * - These counters provide detailed performance metrics
 */
void arm_v7m_cm7_dwt_enable_perf_counters(void)
{
    arm_v7m_dwt_enable_perf_counters();
}

/**
 * @brief Disable DWT performance counters
 */
void arm_v7m_cm7_dwt_disable_perf_counters(void)
{
    arm_v7m_dwt_disable_perf_counters();
}

/**
 * @brief Reset all performance counters
 *
 * Resets CPI, Exception, Sleep, LSU, and Fold counters to 0
 */
void arm_v7m_cm7_dwt_reset_perf_counters(void)
{
    arm_v7m_dwt_reset_perf_counters();
}

/*============================================================================*
 * Core Register Access Functions
 *============================================================================*/

/**
 * @brief Read a core register via debug interface
 *
 * According to ARMv7-M Architecture Reference Manual, Section C1.6.3:
 * - Uses the DCRSR/DCRDR registers to access core registers
 * - The processor must be in Debug state
 * - This function polls until the transfer is complete
 *
 * @param regsel Register selector value (see ARM_V7M_CM7_DCRSR_REG_* defines)
 * @return Register value
 */
uint32_t arm_v7m_cm7_debug_read_reg(uint32_t regsel)
{
    return arm_v7m_debug_read_reg(regsel);
}

/**
 * @brief Write a core register via debug interface
 *
 * @param regsel Register selector value (see ARM_V7M_CM7_DCRSR_REG_* defines)
 * @param value Value to write to the register
 */
void arm_v7m_cm7_debug_write_reg(uint32_t regsel, uint32_t value)
{
    arm_v7m_debug_write_reg(regsel, value);
}

/*============================================================================*
 * Vector Catch Configuration
 *============================================================================*/

/**
 * @brief Enable vector catch for specific exception types
 *
 * According to ARMv7-M Architecture Reference Manual, Section C1.6.5:
 * - Vector catch causes the processor to halt when the specified exception is taken
 * - This is useful for debugging exception handlers
 * - Halting debug must be enabled (C_DEBUGEN = 1) for vector catch to work
 *
 * @param vc_mask Bit mask of vector catch bits to enable
 *                (see ARM_V7M_CM7_DEMCR_VC_* defines)
 */
void arm_v7m_cm7_debug_enable_vector_catch(uint32_t vc_mask)
{
    arm_v7m_debug_enable_vector_catch(vc_mask);
}

/**
 * @brief Disable vector catch for specific exception types
 * @param vc_mask Bit mask of vector catch bits to disable
 *                (see ARM_V7M_CM7_DEMCR_VC_* defines)
 */
void arm_v7m_cm7_debug_disable_vector_catch(uint32_t vc_mask)
{
    arm_v7m_debug_disable_vector_catch(vc_mask);
}

/*============================================================================*
 * ITM Functions
 *============================================================================*/

/**
 * @brief Get number of ITM stimulus ports
 * @return Number of implemented stimulus ports
 */
uint32_t arm_v7m_cm7_itm_get_num_ports(void)
{
    return arm_v7m_itm_get_num_ports();
}

/**
 * @brief Send string to ITM stimulus port
 *
 * @param port Stimulus port number (0-255)
 * @param str Null-terminated string to send
 */
void arm_v7m_cm7_itm_send_string(uint32_t port, const char *str)
{
    arm_v7m_itm_send_string(port, str);
}

/*============================================================================*
 * FPB Functions
 *============================================================================*/

/**
 * @brief Get number of FPB code comparators
 * @return Number of implemented code comparators
 */
uint32_t arm_v7m_cm7_fpb_get_num_code_comparators(void)
{
    return arm_v7m_fpb_get_num_code_comparators();
}

/**
 * @brief Get number of FPB literal comparators
 * @return Number of implemented literal comparators
 */
uint32_t arm_v7m_cm7_fpb_get_num_literal_comparators(void)
{
    return arm_v7m_fpb_get_num_literal_comparators();
}

/**
 * @brief Set hardware breakpoint
 *
 * According to ARMv7-M Architecture Reference Manual, Section C1.11:
 * - Sets a hardware breakpoint at the specified address
 * - When the processor executes an instruction at this address,
 *   it will halt (if halting debug is enabled) or trigger DebugMonitor
 *
 * @param comp_id Comparator ID (0-127, depending on implementation)
 * @param address Breakpoint address (must be word-aligned for code breakpoints)
 * @return 0 on success, 1 if comparator not available
 */
uint32_t arm_v7m_cm7_fpb_set_breakpoint(uint32_t comp_id, uint32_t address)
{
    return arm_v7m_fpb_set_breakpoint(comp_id, address);
}

/*============================================================================*
 * TPIU Functions
 *============================================================================*/

/**
 * @brief Enable SWO output
 *
 * According to ARMv7-M Architecture Reference Manual, Section C1.10:
 * - Configures the TPIU for SWO (Serial Wire Output) mode
 * - The prescaler divides the processor clock to generate the SWO clock
 * - SWO is used for single-pin trace output
 *
 * @param prescaler Clock prescaler value for SWO baud rate
 */
void arm_v7m_cm7_tpiu_enable_swo(uint32_t prescaler)
{
    arm_v7m_tpiu_enable_swo(prescaler);
}

/**
 * @brief Disable SWO output
 */
void arm_v7m_cm7_tpiu_disable_swo(void)
{
    arm_v7m_tpiu_disable_swo();
}

/*============================================================================*
 * CM7 Specific - CTI (Cross Trigger Interface) Operations
 * Reference: Cortex-M7 Technical Reference Manual, Chapter 10
 *            - Cross Trigger Interface (CTI) on page 10-1
 *============================================================================*/

/**
 * @brief Enable CTI
 *
 * According to Cortex-M7 Technical Reference Manual, Section 10.3:
 * - CTI enables subsystems to cross trigger with each other
 * - CTI Control Register (CTICONTROL) enables the CTI
 *
 * @note CTI is part of the debug system at base address ARM_V7M_CM7_CTI_BASE
 */
void arm_v7m_cm7_cti_enable(void)
{
    /* Enable trace for CTI to work */
    arm_v7m_cm7_debug_enable_trace();

    /* Enable CTI by setting ENABLE bit in CTICONTROL */
    *(volatile uint32_t *)(ARM_V7M_CM7_CTI_BASE + ARM_V7M_CM7_CTI_CONTROL_OFFSET) |=
        ARM_V7M_CM7_CTI_CONTROL_ENABLE_Msk;
}

/**
 * @brief Disable CTI
 *
 * According to Cortex-M7 Technical Reference Manual, Section 10.3:
 * - Clearing ENABLE bit in CTICONTROL disables the CTI
 */
void arm_v7m_cm7_cti_disable(void)
{
    /* Disable CTI by clearing ENABLE bit in CTICONTROL */
    *(volatile uint32_t *)(ARM_V7M_CM7_CTI_BASE + ARM_V7M_CM7_CTI_CONTROL_OFFSET) &=
        ~ARM_V7M_CM7_CTI_CONTROL_ENABLE_Msk;

    /* Also disable trace */
    arm_v7m_cm7_debug_disable_trace();
}

/**
 * @brief Trigger CTI output channel
 *
 * According to Cortex-M7 Technical Reference Manual, Section 10.3:
 * - CTIAPPPULSE register can be used to generate a single pulse on
 *   the selected channel output
 * - Writing a bit to 1 generates a pulse on the corresponding channel
 *
 * @param channel Channel number (0-7)
 */
void arm_v7m_cm7_cti_trigger_output(uint32_t channel)
{
    if (channel < 8U) {
        *(volatile uint32_t *)(ARM_V7M_CM7_CTI_BASE + ARM_V7M_CM7_CTI_APPPULSE_OFFSET) =
            (1U << channel);
    }
}

/**
 * @brief Clear CTI trigger
 *
 * According to Cortex-M7 Technical Reference Manual, Section 10.3:
 * - CTIINTACK register acknowledges trigger events
 * - Writing a bit to 1 clears the corresponding channel interrupt
 *
 * @param channel Channel number (0-7)
 */
void arm_v7m_cm7_cti_clear_trigger(uint32_t channel)
{
    if (channel < 8U) {
        *(volatile uint32_t *)(ARM_V7M_CM7_CTI_BASE + ARM_V7M_CM7_CTI_INTACK_OFFSET) =
            (1U << channel);
    }
}
