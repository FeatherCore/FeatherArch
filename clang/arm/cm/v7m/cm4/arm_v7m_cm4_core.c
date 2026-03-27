/*
 * arm_v7m_cm4_core.c
 * Cortex-M4 Core Register Implementation
 * 
 * Reference: ARMv7-M Architecture Reference Manual
 *            - Section B1.4: Registers on page B1-516
 *            - Section B1.4.1: The Arm core registers on page B1-516
 *            - Section B1.4.2: The special-purpose Program Status Registers, xPSR on page B1-516
 *            - Section B1.4.3: The special-purpose mask registers on page B1-528
 *            - Section B1.4.4: The special-purpose CONTROL register on page B1-519
 *            - Section B5.2: Armv7-M system instruction descriptions on page B5-672
 * 
 *            Cortex-M4 Devices Generic User Guide
 *            - Chapter 2: The Cortex-M4 Processor
 *            - Section 2.1: Programmers model on page 2-2
 *            - Section 2.1.3: Core registers on page 2-3
 *            - Section 2.1.4: Stack Pointer on page 2-4
 *            - Section 2.1.5: Program Status Register on page 2-4
 *            - Section 2.1.6: Application Program Status Register on page 2-5
 *            - Section 2.1.7: Interrupt Program Status Register on page 2-6
 *            - Section 2.1.8: Execution Program Status Register on page 2-6
 *            - Section 2.1.9: Exception mask registers (PRIMASK, FAULTMASK, BASEPRI) on page 2-7
 *            - Section 2.1.10: CONTROL register on page 2-9
 * 
 *            Cortex-M4 Technical Reference Manual
 *            - Chapter 3.8: Processor core registers on page 3-8
 *            - Section 3.8.1: Core register set summary on page 3-9
 *            - Section 3.8.2: Stack Pointer on page 3-10
 *            - Section 3.8.3: Program Status Register on page 3-10
 *            - Section 3.8.4: Application Program Status Register on page 3-11
 *            - Section 3.8.5: Interrupt Program Status Register on page 3-11
 *            - Section 3.8.6: Execution Program Status Register on page 3-11
 *            - Section 3.8.7: Exception mask registers on page 3-11
 *            - Section 3.8.8: CONTROL register on page 3-12
 * 
 * @note Cortex-M4 core registers are identical to generic Armv7-M.
 *       All functions are implemented as static inline in arm_v7m_cm4_core.h
 *       to eliminate function call overhead.
 *       This file is kept for compatibility and potential future extensions.
 */

#include "arm_v7m_cm4_core.h"

/*
 * All core register access functions are implemented as static inline
 * in arm_v7m_cm4_core.h for optimal performance.
 *
 * The following functions are available as inline functions in the header:
 * - arm_v7m_cm4_get_msp() / arm_v7m_cm4_set_msp()
 * - arm_v7m_cm4_get_psp() / arm_v7m_cm4_set_psp()
 * - arm_v7m_cm4_get_primask() / arm_v7m_cm4_set_primask()
 * - arm_v7m_cm4_get_faultmask() / arm_v7m_cm4_set_faultmask()
 * - arm_v7m_cm4_get_basepri() / arm_v7m_cm4_set_basepri()
 * - arm_v7m_cm4_set_basepri_max()
 * - arm_v7m_cm4_get_control() / arm_v7m_cm4_set_control()
 * - arm_v7m_cm4_get_apsr() / arm_v7m_cm4_set_apsr()
 * - arm_v7m_cm4_set_apsr_nzcvq() / arm_v7m_cm4_set_apsr_g() / arm_v7m_cm4_set_apsr_nzcvqg()
 * - arm_v7m_cm4_get_ipsr() / arm_v7m_cm4_get_epsr()
 * - arm_v7m_cm4_get_xpsr() / arm_v7m_cm4_set_xpsr()
 * - arm_v7m_cm4_get_iapsr() / arm_v7m_cm4_get_eapsr() / arm_v7m_cm4_get_iepsr()
 * - arm_v7m_cm4_enable_irq() / arm_v7m_cm4_disable_irq()
 * - arm_v7m_cm4_enable_fault() / arm_v7m_cm4_disable_fault()
 * - arm_v7m_cm4_isb() / arm_v7m_cm4_dsb() / arm_v7m_cm4_dmb()
 * - arm_v7m_cm4_wfi() / arm_v7m_cm4_wfe() / arm_v7m_cm4_sev()
 * - arm_v7m_cm4_get_exception_number() / arm_v7m_cm4_is_in_handler_mode()
 * - arm_v7m_cm4_get_current_sp()
 * - arm_v7m_cm4_is_privileged()
 * - arm_v7m_cm4_set_unprivileged() / arm_v7m_cm4_set_privileged()
 * - arm_v7m_cm4_use_psp() / arm_v7m_cm4_use_msp()
 * - arm_v7m_cm4_get_npriv() / arm_v7m_cm4_get_spsel() / arm_v7m_cm4_get_fpca()
 * - arm_v7m_cm4_set_fpca()
 * - arm_v7m_cm4_bitband_set() / arm_v7m_cm4_bitband_clear()
 * - arm_v7m_cm4_bitband_read() / arm_v7m_cm4_bitband_toggle()
 */
