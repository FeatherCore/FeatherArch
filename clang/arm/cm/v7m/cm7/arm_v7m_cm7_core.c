/*
 * arm_v7m_cm7_core.c
 * Cortex-M7 Core Register Implementation
 * Reference: ARMv7-M Architecture Reference Manual
 *            - Section B1.4: Registers on page B1-514
 *            - Section B1.4.1: Arm core registers on page B1-514
 *            - Section B1.4.2: The special-purpose Program Status Registers, xPSR on page B1-516
 *            - Section B1.4.3: The special-purpose mask registers on page B1-528
 *            - Section B1.4.4: The special-purpose CONTROL register on page B1-519
 *            - Section B5.2: System Instruction Descriptions on page B5-678
 *            Cortex-M7 Devices Generic User Guide, Chapter 2.1
 *            - Core register set summary on page 2-3
 *            - Stack Pointer on page 2-4
 *            - Program Status Register on page 2-4
 *            - Exception mask registers (PRIMASK, FAULTMASK, BASEPRI) on page 2-7
 *            - CONTROL register on page 2-9
 *            Cortex-M7 Technical Reference Manual, Chapter 2.6
 *            - Processor core registers on page 2-9
 *            - Core register set summary on page 2-9
 *            - Exception mask registers on page 2-11
 *            - CONTROL register on page 2-12
 *
 * @note Cortex-M7 core registers are identical to generic Armv7-M.
 *       All functions are implemented as static inline in arm_v7m_cm7_core.h
 *       to eliminate function call overhead.
 *       This file is kept for compatibility and potential future extensions.
 */

#include "arm_v7m_cm7_core.h"

/*
 * All core register access functions are implemented as static inline
 * in arm_v7m_cm7_core.h for optimal performance.
 *
 * The following functions are available as inline functions in the header:
 * - arm_v7m_cm7_get_msp() / arm_v7m_cm7_set_msp()
 * - arm_v7m_cm7_get_psp() / arm_v7m_cm7_set_psp()
 * - arm_v7m_cm7_get_primask() / arm_v7m_cm7_set_primask()
 * - arm_v7m_cm7_get_faultmask() / arm_v7m_cm7_set_faultmask()
 * - arm_v7m_cm7_get_basepri() / arm_v7m_cm7_set_basepri()
 * - arm_v7m_cm7_set_basepri_max()
 * - arm_v7m_cm7_get_control() / arm_v7m_cm7_set_control()
 * - arm_v7m_cm7_get_apsr() / arm_v7m_cm7_set_apsr()
 * - arm_v7m_cm7_get_ipsr() / arm_v7m_cm7_get_epsr()
 * - arm_v7m_cm7_get_xpsr() / arm_v7m_cm7_set_xpsr()
 * - arm_v7m_cm7_get_iapsr() / arm_v7m_cm7_get_eapsr() / arm_v7m_cm7_get_iepsr()
 * - arm_v7m_cm7_enable_irq() / arm_v7m_cm7_disable_irq()
 * - arm_v7m_cm7_enable_fault() / arm_v7m_cm7_disable_fault()
 * - arm_v7m_cm7_isb() / arm_v7m_cm7_dsb() / arm_v7m_cm7_dmb()
 * - arm_v7m_cm7_wfi() / arm_v7m_cm7_wfe() / arm_v7m_cm7_sev()
 * - arm_v7m_cm7_get_exception_number() / arm_v7m_cm7_is_in_handler_mode()
 * - arm_v7m_cm7_get_current_sp()
 * - arm_v7m_cm7_is_privileged()
 * - arm_v7m_cm7_set_unprivileged() / arm_v7m_cm7_set_privileged()
 * - arm_v7m_cm7_use_psp() / arm_v7m_cm7_use_msp()
 * - arm_v7m_cm7_get_npriv() / arm_v7m_cm7_get_spsel() / arm_v7m_cm7_get_fpca()
 * - arm_v7m_cm7_set_fpca()
 */
