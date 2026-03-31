/*
 * Copyright (c) 2009-2024 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * CMSIS Cortex-M23 Core Peripheral Access Layer Header File
 * ARMv8-M Baseline Architecture
 */

#![allow(non_snake_case)]
#![allow(non_camel_case_types)]
#![allow(non_upper_case_globals)]

/// Cortex-M Core
pub const __CORTEX_M: u32 = 23;
/// FPU not present
pub const __FPU_USED: u32 = 0;
/// MPU not present by default
pub const __MPU_PRESENT: u32 = 0;
/// VTOR present
pub const __VTOR_PRESENT: u32 = 1;
/// Cortex-M23 revision
pub const __CM23_REV: u32 = 0x0000;
/// Number of priority bits
pub const __NVIC_PRIO_BITS: u32 = 2;
/// Use vendor specific SysTick config
pub const __Vendor_SysTickConfig: u32 = 0;

/* ========================================================================= */
/* ============                 Processor Id               ============ */
/* ========================================================================= */

/// Processor Family: Cortex-M23
pub const CMSIS_CPU: &str = "Cortex-M23";

/* ========================================================================= */
/* ============             Interrupt Numbers              ============ */
/* ========================================================================= */

/// Non Maskable Interrupt
pub const NonMaskableInt_IRQn: i32 = -14;
/// Hard Fault Interrupt
pub const HardFault_IRQn: i32 = -13;
/// SV Call Interrupt
pub const SVCall_IRQn: i32 = -5;
/// Pend SV Interrupt
pub const PendSV_IRQn: i32 = -2;
/// System Tick Interrupt
pub const SysTick_IRQn: i32 = -1;

/* ========================================================================= */
/* ============             Register Abstraction             ============ */
/* ========================================================================= */

/**
 * \brief Union type to access the Application Program Status Register (APSR).
 */
#[repr(C)]
pub union APSR_Type {
    /// Structure used for bit access
    pub b: APSR_b,
    /// Type used for word access
    pub w: u32,
}

/// APSR Register bitfield structure
#[repr(C)]
#[derive(Default, Clone, Copy)]
pub struct APSR_b {
    /// bit:  0..26  Reserved
    pub _reserved0: u32,
    /// bit:     27  Saturation condition flag
    pub Q: u32,
    /// bit:     28  Overflow condition code flag
    pub V: u32,
    /// bit:     29  Carry condition code flag
    pub C: u32,
    /// bit:     30  Zero condition code flag
    pub Z: u32,
    /// bit:     31  Negative condition code flag
    pub N: u32,
}

/** \brief APSR Register Definitions */
pub const APSR_N_Pos: u32 = 31;
pub const APSR_N_Msk: u32 = 1 << APSR_N_Pos;
pub const APSR_Z_Pos: u32 = 30;
pub const APSR_Z_Msk: u32 = 1 << APSR_Z_Pos;
pub const APSR_C_Pos: u32 = 29;
pub const APSR_C_Msk: u32 = 1 << APSR_C_Pos;
pub const APSR_V_Pos: u32 = 28;
pub const APSR_V_Msk: u32 = 1 << APSR_V_Pos;
pub const APSR_Q_Pos: u32 = 27;
pub const APSR_Q_Msk: u32 = 1 << APSR_Q_Pos;

/**
 * \brief Union type to access the Interrupt Program Status Register (IPSR).
 */
#[repr(C)]
pub union IPSR_Type {
    /// Structure used for bit access
    pub b: IPSR_b,
    /// Type used for word access
    pub w: u32,
}

/// IPSR Register bitfield structure
#[repr(C)]
#[derive(Default, Clone, Copy)]
pub struct IPSR_b {
    /// bit:  0.. 8  Exception number
    pub ISR: u32,
    /// bit:  9..31  Reserved
    pub _reserved0: u32,
}

/** \brief IPSR Register Definitions */
pub const IPSR_ISR_Pos: u32 = 0;
pub const IPSR_ISR_Msk: u32 = 0x1FF << IPSR_ISR_Pos;

/**
 * \brief Union type to access the Special-Purpose Program Status Registers (xPSR).
 */
#[repr(C)]
pub union xPSR_Type {
    /// Structure used for bit access
    pub b: xPSR_b,
    /// Type used for word access
    pub w: u32,
}

/// xPSR Register bitfield structure
#[repr(C)]
#[derive(Default, Clone, Copy)]
pub struct xPSR_b {
    /// bit:  0.. 8  Exception number
    pub ISR: u32,
    /// bit:  9..23  Reserved
    pub _reserved0: u32,
    /// bit:     24  Thumb bit
    pub T: u32,
    /// bit: 25..26  Reserved
    pub _reserved1: u32,
    /// bit:     27  Saturation condition flag
    pub Q: u32,
    /// bit:     28  Overflow condition code flag
    pub V: u32,
    /// bit:     29  Carry condition code flag
    pub C: u32,
    /// bit:     30  Zero condition code flag
    pub Z: u32,
    /// bit:     31  Negative condition code flag
    pub N: u32,
}

/** \brief xPSR Register Definitions */
pub const xPSR_N_Pos: u32 = 31;
pub const xPSR_N_Msk: u32 = 1 << xPSR_N_Pos;
pub const xPSR_Z_Pos: u32 = 30;
pub const xPSR_Z_Msk: u32 = 1 << xPSR_Z_Pos;
pub const xPSR_C_Pos: u32 = 29;
pub const xPSR_C_Msk: u32 = 1 << xPSR_C_Pos;
pub const xPSR_V_Pos: u32 = 28;
pub const xPSR_V_Msk: u32 = 1 << xPSR_V_Pos;
pub const xPSR_Q_Pos: u32 = 27;
pub const xPSR_Q_Msk: u32 = 1 << xPSR_Q_Pos;
pub const xPSR_T_Pos: u32 = 24;
pub const xPSR_T_Msk: u32 = 1 << xPSR_T_Pos;
pub const xPSR_ISR_Pos: u32 = 0;
pub const xPSR_ISR_Msk: u32 = 0x1FF << xPSR_ISR_Pos;

/**
 * \brief Union type to access the Control Registers (CONTROL).
 */
#[repr(C)]
pub union CONTROL_Type {
    /// Structure used for bit access
    pub b: CONTROL_b,
    /// Type used for word access
    pub w: u32,
}

/// CONTROL Register bitfield structure
#[repr(C)]
#[derive(Default, Clone, Copy)]
pub struct CONTROL_b {
    /// bit:      0  Execution privilege in Thread mode
    pub nPRIV: u32,
    /// bit:      1  Stack to be used
    pub SPSEL: u32,
    /// bit:  2..31  Reserved
    pub _reserved1: u32,
}

/** \brief CONTROL Register Definitions */
pub const CONTROL_SPSEL_Pos: u32 = 1;
pub const CONTROL_SPSEL_Msk: u32 = 1 << CONTROL_SPSEL_Pos;
pub const CONTROL_nPRIV_Pos: u32 = 0;
pub const CONTROL_nPRIV_Msk: u32 = 1 << CONTROL_nPRIV_Pos;

/**
 * \brief Structure type to access the Nested Vectored Interrupt Controller (NVIC).
 */
#[repr(C)]
pub struct NVIC_Type {
    /// Offset: 0x000 (R/W)  Interrupt Set Enable Register
    pub ISER: [u32; 1],
    _reserved0: [u32; 31],
    /// Offset: 0x080 (R/W)  Interrupt Clear Enable Register
    pub ICER: [u32; 1],
    _reserved1: [u32; 31],
    /// Offset: 0x100 (R/W)  Interrupt Set Pending Register
    pub ISPR: [u32; 1],
    _reserved2: [u32; 31],
    /// Offset: 0x180 (R/W)  Interrupt Clear Pending Register
    pub ICPR: [u32; 1],
    _reserved3: [u32; 31],
    _reserved4: [u32; 64],
    /// Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide)
    pub IPR: [u8; 8],
}

/**
 * \brief Structure type to access the System Control Block (SCB).
 */
#[repr(C)]
pub struct SCB_Type {
    /// Offset: 0x000 (R/ )  CPUID Base Register
    pub CPUID: u32,
    /// Offset: 0x004 (R/W)  Interrupt Control and State Register
    pub ICSR: u32,
    _reserved0: [u32; 2],
    /// Offset: 0x010 (R/W)  System Control Register
    pub SCR: u32,
    /// Offset: 0x014 (R/W)  Configuration Control Register
    pub CCR: u32,
    _reserved1: [u32; 2],
    /// Offset: 0x020 (R/W)  System Handler Control and State Register
    pub SHCSR: u32,
}

/** \brief SCB CPUID Register Definitions */
pub const SCB_CPUID_IMPLEMENTER_Pos: u32 = 24;
pub const SCB_CPUID_IMPLEMENTER_Msk: u32 = 0xFF << SCB_CPUID_IMPLEMENTER_Pos;
pub const SCB_CPUID_VARIANT_Pos: u32 = 20;
pub const SCB_CPUID_VARIANT_Msk: u32 = 0xF << SCB_CPUID_VARIANT_Pos;
pub const SCB_CPUID_ARCHITECTURE_Pos: u32 = 16;
pub const SCB_CPUID_ARCHITECTURE_Msk: u32 = 0xF << SCB_CPUID_ARCHITECTURE_Pos;
pub const SCB_CPUID_PARTNO_Pos: u32 = 4;
pub const SCB_CPUID_PARTNO_Msk: u32 = 0xFFF << SCB_CPUID_PARTNO_Pos;
pub const SCB_CPUID_REVISION_Pos: u32 = 0;
pub const SCB_CPUID_REVISION_Msk: u32 = 0xF << SCB_CPUID_REVISION_Pos;

/** \brief SCB Interrupt Control State Register Definitions */
pub const SCB_ICSR_NMIPENDSET_Pos: u32 = 31;
pub const SCB_ICSR_NMIPENDSET_Msk: u32 = 1 << SCB_ICSR_NMIPENDSET_Pos;
pub const SCB_ICSR_PENDSVSET_Pos: u32 = 28;
pub const SCB_ICSR_PENDSVSET_Msk: u32 = 1 << SCB_ICSR_PENDSVSET_Pos;
pub const SCB_ICSR_PENDSVCLR_Pos: u32 = 27;
pub const SCB_ICSR_PENDSVCLR_Msk: u32 = 1 << SCB_ICSR_PENDSVCLR_Pos;
pub const SCB_ICSR_PENDSTSET_Pos: u32 = 26;
pub const SCB_ICSR_PENDSTSET_Msk: u32 = 1 << SCB_ICSR_PENDSTSET_Pos;
pub const SCB_ICSR_PENDSTCLR_Pos: u32 = 25;
pub const SCB_ICSR_PENDSTCLR_Msk: u32 = 1 << SCB_ICSR_PENDSTCLR_Pos;
pub const SCB_ICSR_ISRPREEMPT_Pos: u32 = 23;
pub const SCB_ICSR_ISRPREEMPT_Msk: u32 = 1 << SCB_ICSR_ISRPREEMPT_Pos;
pub const SCB_ICSR_ISRPENDING_Pos: u32 = 22;
pub const SCB_ICSR_ISRPENDING_Msk: u32 = 1 << SCB_ICSR_ISRPENDING_Pos;
pub const SCB_ICSR_VECTPENDING_Pos: u32 = 12;
pub const SCB_ICSR_VECTPENDING_Msk: u32 = 0x1FF << SCB_ICSR_VECTPENDING_Pos;
pub const SCB_ICSR_VECTACTIVE_Pos: u32 = 0;
pub const SCB_ICSR_VECTACTIVE_Msk: u32 = 0x1FF << SCB_ICSR_VECTACTIVE_Pos;

/** \brief SCB System Control Register Definitions */
pub const SCB_SCR_SEVONPEND_Pos: u32 = 4;
pub const SCB_SCR_SEVONPEND_Msk: u32 = 1 << SCB_SCR_SEVONPEND_Pos;
pub const SCB_SCR_SLEEPDEEP_Pos: u32 = 2;
pub const SCB_SCR_SLEEPDEEP_Msk: u32 = 1 << SCB_SCR_SLEEPDEEP_Pos;
pub const SCB_SCR_SLEEPONEXIT_Pos: u32 = 1;
pub const SCB_SCR_SLEEPONEXIT_Msk: u32 = 1 << SCB_SCR_SLEEPONEXIT_Pos;

/** \brief SCB Configuration Control Register Definitions */
pub const SCB_CCR_STKALIGN_Pos: u32 = 9;
pub const SCB_CCR_STKALIGN_Msk: u32 = 1 << SCB_CCR_STKALIGN_Pos;
pub const SCB_CCR_UNALIGN_TRP_Pos: u32 = 3;
pub const SCB_CCR_UNALIGN_TRP_Msk: u32 = 1 << SCB_CCR_UNALIGN_TRP_Pos;

/** \brief SCB System Handler Control and State Register Definitions */
pub const SCB_SHCSR_SVCALLPENDED_Pos: u32 = 15;
pub const SCB_SHCSR_SVCALLPENDED_Msk: u32 = 1 << SCB_SHCSR_SVCALLPENDED_Pos;
pub const SCB_SHCSR_SYSTICKACT_Pos: u32 = 11;
pub const SCB_SHCSR_SYSTICKACT_Msk: u32 = 1 << SCB_SHCSR_SYSTICKACT_Pos;
pub const SCB_SHCSR_PENDSVACT_Pos: u32 = 10;
pub const SCB_SHCSR_PENDSVACT_Msk: u32 = 1 << SCB_SHCSR_PENDSVACT_Pos;
pub const SCB_SHCSR_SVCALLACT_Pos: u32 = 7;
pub const SCB_SHCSR_SVCALLACT_Msk: u32 = 1 << SCB_SHCSR_SVCALLACT_Pos;

/**
 * \brief Structure type to access the System Timer (SysTick).
 */
#[repr(C)]
pub struct SysTick_Type {
    /// Offset: 0x000 (R/W)  SysTick Control and Status Register
    pub CTRL: u32,
    /// Offset: 0x004 (R/W)  SysTick Reload Value Register
    pub LOAD: u32,
    /// Offset: 0x008 (R/W)  SysTick Current Value Register
    pub VAL: u32,
    /// Offset: 0x00C (R/ )  SysTick Calibration Register
    pub CALIB: u32,
}

/** \brief SysTick Control / Status Register Definitions */
pub const SysTick_CTRL_COUNTFLAG_Pos: u32 = 16;
pub const SysTick_CTRL_COUNTFLAG_Msk: u32 = 1 << SysTick_CTRL_COUNTFLAG_Pos;
pub const SysTick_CTRL_CLKSOURCE_Pos: u32 = 2;
pub const SysTick_CTRL_CLKSOURCE_Msk: u32 = 1 << SysTick_CTRL_CLKSOURCE_Pos;
pub const SysTick_CTRL_TICKINT_Pos: u32 = 1;
pub const SysTick_CTRL_TICKINT_Msk: u32 = 1 << SysTick_CTRL_TICKINT_Pos;
pub const SysTick_CTRL_ENABLE_Pos: u32 = 0;
pub const SysTick_CTRL_ENABLE_Msk: u32 = 1 << SysTick_CTRL_ENABLE_Pos;

/** \brief SysTick Reload Register Definitions */
pub const SysTick_LOAD_RELOAD_Pos: u32 = 0;
pub const SysTick_LOAD_RELOAD_Msk: u32 = 0xFFFFFF << SysTick_LOAD_RELOAD_Pos;

/** \brief SysTick Current Register Definitions */
pub const SysTick_VAL_CURRENT_Pos: u32 = 0;
pub const SysTick_VAL_CURRENT_Msk: u32 = 0xFFFFFF << SysTick_VAL_CURRENT_Pos;

/** \brief SysTick Calibration Register Definitions */
pub const SysTick_CALIB_NOREF_Pos: u32 = 31;
pub const SysTick_CALIB_NOREF_Msk: u32 = 1 << SysTick_CALIB_NOREF_Pos;
pub const SysTick_CALIB_SKEW_Pos: u32 = 30;
pub const SysTick_CALIB_SKEW_Msk: u32 = 1 << SysTick_CALIB_SKEW_Pos;
pub const SysTick_CALIB_TENMS_Pos: u32 = 0;
pub const SysTick_CALIB_TENMS_Msk: u32 = 0xFFFFFF << SysTick_CALIB_TENMS_Pos;

/* Memory mapping of Core Hardware */
pub const SCS_BASE: u32 = 0xE000E000;
pub const SysTick_BASE: u32 = SCS_BASE + 0x0010;
pub const NVIC_BASE: u32 = SCS_BASE + 0x0100;
pub const SCB_BASE: u32 = SCS_BASE + 0x0D00;
