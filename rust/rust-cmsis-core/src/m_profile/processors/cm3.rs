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
 * CMSIS Cortex-M3 Core Peripheral Access Layer Header File
 */

#![allow(non_snake_case)]
#![allow(non_camel_case_types)]
#![allow(non_upper_case_globals)]

/// Cortex-M Core
pub const __CORTEX_M: u32 = 3;
/// FPU not present
pub const __FPU_USED: u32 = 0;
/// MPU not present by default
pub const __MPU_PRESENT: u32 = 0;
/// VTOR present
pub const __VTOR_PRESENT: u32 = 1;
/// Cortex-M3 revision
pub const __CM3_REV: u32 = 0x0200;
/// Number of priority bits
pub const __NVIC_PRIO_BITS: u32 = 3;
/// Use vendor specific SysTick config
pub const __Vendor_SysTickConfig: u32 = 0;

/* ========================================================================= */
/* ============                 Processor Id               ============ */
/* ========================================================================= */

/// Processor Family: Cortex-M3
pub const CMSIS_CPU: &str = "Cortex-M3";

/* ========================================================================= */
/* ============             Interrupt Numbers              ============ */
/* ========================================================================= */

/// Non Maskable Interrupt
pub const NonMaskableInt_IRQn: i32 = -14;
/// Hard Fault Interrupt
pub const HardFault_IRQn: i32 = -13;
/// Memory Management Interrupt
pub const MemoryManagement_IRQn: i32 = -12;
/// Bus Fault Interrupt
pub const BusFault_IRQn: i32 = -11;
/// Usage Fault Interrupt
pub const UsageFault_IRQn: i32 = -10;
/// SV Call Interrupt
pub const SVCall_IRQn: i32 = -5;
/// Debug Monitor Interrupt
pub const DebugMonitor_IRQn: i32 = -4;
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
    /// bit:      9  Reserved
    pub _reserved0: u32,
    /// bit: 10..15  ICI/IT part 1
    pub ICI_IT_1: u32,
    /// bit: 16..23  Reserved
    pub _reserved1: u32,
    /// bit:     24  Thumb bit
    pub T: u32,
    /// bit: 25..26  ICI/IT part 2
    pub ICI_IT_2: u32,
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
pub const xPSR_ICI_IT_2_Pos: u32 = 25;
pub const xPSR_ICI_IT_2_Msk: u32 = 3 << xPSR_ICI_IT_2_Pos;
pub const xPSR_T_Pos: u32 = 24;
pub const xPSR_T_Msk: u32 = 1 << xPSR_T_Pos;
pub const xPSR_ICI_IT_1_Pos: u32 = 10;
pub const xPSR_ICI_IT_1_Msk: u32 = 0x3F << xPSR_ICI_IT_1_Pos;
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
    pub ISER: [u32; 8],
    _reserved0: [u32; 24],
    /// Offset: 0x080 (R/W)  Interrupt Clear Enable Register
    pub ICER: [u32; 8],
    _reserved1: [u32; 24],
    /// Offset: 0x100 (R/W)  Interrupt Set Pending Register
    pub ISPR: [u32; 8],
    _reserved2: [u32; 24],
    /// Offset: 0x180 (R/W)  Interrupt Clear Pending Register
    pub ICPR: [u32; 8],
    _reserved3: [u32; 24],
    /// Offset: 0x200 (R/W)  Interrupt Active bit Register
    pub IABR: [u32; 8],
    _reserved4: [u32; 56],
    /// Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide)
    pub IPR: [u8; 240],
    _reserved5: [u32; 644],
    /// Offset: 0xE00 ( /W)  Software Trigger Interrupt Register
    pub STIR: u32,
}

/** \brief NVIC Software Triggered Interrupt Register Definitions */
pub const NVIC_STIR_INTID_Pos: u32 = 0;
pub const NVIC_STIR_INTID_Msk: u32 = 0x1FF << NVIC_STIR_INTID_Pos;

/**
 * \brief Structure type to access the System Control Block (SCB).
 */
#[repr(C)]
pub struct SCB_Type {
    /// Offset: 0x000 (R/ )  CPUID Base Register
    pub CPUID: u32,
    /// Offset: 0x004 (R/W)  Interrupt Control and State Register
    pub ICSR: u32,
    /// Offset: 0x008 (R/W)  Vector Table Offset Register
    pub VTOR: u32,
    /// Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register
    pub AIRCR: u32,
    /// Offset: 0x010 (R/W)  System Control Register
    pub SCR: u32,
    /// Offset: 0x014 (R/W)  Configuration Control Register
    pub CCR: u32,
    /// Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15)
    pub SHPR: [u8; 12],
    /// Offset: 0x024 (R/W)  System Handler Control and State Register
    pub SHCSR: u32,
    /// Offset: 0x028 (R/W)  Configurable Fault Status Register
    pub CFSR: u32,
    /// Offset: 0x02C (R/W)  HardFault Status Register
    pub HFSR: u32,
    /// Offset: 0x030 (R/W)  Debug Fault Status Register
    pub DFSR: u32,
    /// Offset: 0x034 (R/W)  MemManage Fault Address Register
    pub MMFAR: u32,
    /// Offset: 0x038 (R/W)  BusFault Address Register
    pub BFAR: u32,
    /// Offset: 0x03C (R/W)  Auxiliary Fault Status Register
    pub AFSR: u32,
    /// Offset: 0x040 (R/ )  Processor Feature Register
    pub ID_PFR: [u32; 2],
    /// Offset: 0x048 (R/ )  Debug Feature Register
    pub ID_DFR: u32,
    /// Offset: 0x04C (R/ )  Auxiliary Feature Register
    pub ID_AFR: u32,
    /// Offset: 0x050 (R/ )  Memory Model Feature Register
    pub ID_MMFR: [u32; 4],
    /// Offset: 0x060 (R/ )  Instruction Set Attributes Register
    pub ID_ISAR: [u32; 5],
    _reserved0: [u32; 5],
    /// Offset: 0x088 (R/W)  Coprocessor Access Control Register
    pub CPACR: u32,
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
pub const SCB_ICSR_RETTOBASE_Pos: u32 = 11;
pub const SCB_ICSR_RETTOBASE_Msk: u32 = 1 << SCB_ICSR_RETTOBASE_Pos;
pub const SCB_ICSR_VECTACTIVE_Pos: u32 = 0;
pub const SCB_ICSR_VECTACTIVE_Msk: u32 = 0x1FF << SCB_ICSR_VECTACTIVE_Pos;

/** \brief SCB Vector Table Offset Register Definitions */
pub const SCB_VTOR_TBLOFF_Pos: u32 = 7;
pub const SCB_VTOR_TBLOFF_Msk: u32 = 0x1FFFFFF << SCB_VTOR_TBLOFF_Pos;

/** \brief SCB Application Interrupt and Reset Control Register Definitions */
pub const SCB_AIRCR_VECTKEY_Pos: u32 = 16;
pub const SCB_AIRCR_VECTKEY_Msk: u32 = 0xFFFF << SCB_AIRCR_VECTKEY_Pos;
pub const SCB_AIRCR_VECTKEYSTAT_Pos: u32 = 16;
pub const SCB_AIRCR_VECTKEYSTAT_Msk: u32 = 0xFFFF << SCB_AIRCR_VECTKEYSTAT_Pos;
pub const SCB_AIRCR_ENDIANESS_Pos: u32 = 15;
pub const SCB_AIRCR_ENDIANESS_Msk: u32 = 1 << SCB_AIRCR_ENDIANESS_Pos;
pub const SCB_AIRCR_PRIGROUP_Pos: u32 = 8;
pub const SCB_AIRCR_PRIGROUP_Msk: u32 = 7 << SCB_AIRCR_PRIGROUP_Pos;
pub const SCB_AIRCR_SYSRESETREQ_Pos: u32 = 2;
pub const SCB_AIRCR_SYSRESETREQ_Msk: u32 = 1 << SCB_AIRCR_SYSRESETREQ_Pos;
pub const SCB_AIRCR_VECTCLRACTIVE_Pos: u32 = 1;
pub const SCB_AIRCR_VECTCLRACTIVE_Msk: u32 = 1 << SCB_AIRCR_VECTCLRACTIVE_Pos;
pub const SCB_AIRCR_VECTRESET_Pos: u32 = 0;
pub const SCB_AIRCR_VECTRESET_Msk: u32 = 1 << SCB_AIRCR_VECTRESET_Pos;

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
pub const SCB_CCR_BFHFNMIGN_Pos: u32 = 8;
pub const SCB_CCR_BFHFNMIGN_Msk: u32 = 1 << SCB_CCR_BFHFNMIGN_Pos;
pub const SCB_CCR_DIV_0_TRP_Pos: u32 = 4;
pub const SCB_CCR_DIV_0_TRP_Msk: u32 = 1 << SCB_CCR_DIV_0_TRP_Pos;
pub const SCB_CCR_UNALIGN_TRP_Pos: u32 = 3;
pub const SCB_CCR_UNALIGN_TRP_Msk: u32 = 1 << SCB_CCR_UNALIGN_TRP_Pos;
pub const SCB_CCR_USERSETMPEND_Pos: u32 = 1;
pub const SCB_CCR_USERSETMPEND_Msk: u32 = 1 << SCB_CCR_USERSETMPEND_Pos;
pub const SCB_CCR_NONBASETHRDENA_Pos: u32 = 0;
pub const SCB_CCR_NONBASETHRDENA_Msk: u32 = 1 << SCB_CCR_NONBASETHRDENA_Pos;

/** \brief SCB System Handler Control and State Register Definitions */
pub const SCB_SHCSR_USGFAULTENA_Pos: u32 = 18;
pub const SCB_SHCSR_USGFAULTENA_Msk: u32 = 1 << SCB_SHCSR_USGFAULTENA_Pos;
pub const SCB_SHCSR_BUSFAULTENA_Pos: u32 = 17;
pub const SCB_SHCSR_BUSFAULTENA_Msk: u32 = 1 << SCB_SHCSR_BUSFAULTENA_Pos;
pub const SCB_SHCSR_MEMFAULTENA_Pos: u32 = 16;
pub const SCB_SHCSR_MEMFAULTENA_Msk: u32 = 1 << SCB_SHCSR_MEMFAULTENA_Pos;
pub const SCB_SHCSR_SVCALLPENDED_Pos: u32 = 15;
pub const SCB_SHCSR_SVCALLPENDED_Msk: u32 = 1 << SCB_SHCSR_SVCALLPENDED_Pos;
pub const SCB_SHCSR_BUSFAULTPENDED_Pos: u32 = 14;
pub const SCB_SHCSR_BUSFAULTPENDED_Msk: u32 = 1 << SCB_SHCSR_BUSFAULTPENDED_Pos;
pub const SCB_SHCSR_MEMFAULTPENDED_Pos: u32 = 13;
pub const SCB_SHCSR_MEMFAULTPENDED_Msk: u32 = 1 << SCB_SHCSR_MEMFAULTPENDED_Pos;
pub const SCB_SHCSR_USGFAULTPENDED_Pos: u32 = 12;
pub const SCB_SHCSR_USGFAULTPENDED_Msk: u32 = 1 << SCB_SHCSR_USGFAULTPENDED_Pos;
pub const SCB_SHCSR_SYSTICKACT_Pos: u32 = 11;
pub const SCB_SHCSR_SYSTICKACT_Msk: u32 = 1 << SCB_SHCSR_SYSTICKACT_Pos;
pub const SCB_SHCSR_PENDSVACT_Pos: u32 = 10;
pub const SCB_SHCSR_PENDSVACT_Msk: u32 = 1 << SCB_SHCSR_PENDSVACT_Pos;
pub const SCB_SHCSR_MONITORACT_Pos: u32 = 8;
pub const SCB_SHCSR_MONITORACT_Msk: u32 = 1 << SCB_SHCSR_MONITORACT_Pos;
pub const SCB_SHCSR_SVCALLACT_Pos: u32 = 7;
pub const SCB_SHCSR_SVCALLACT_Msk: u32 = 1 << SCB_SHCSR_SVCALLACT_Pos;
pub const SCB_SHCSR_USGFAULTACT_Pos: u32 = 3;
pub const SCB_SHCSR_USGFAULTACT_Msk: u32 = 1 << SCB_SHCSR_USGFAULTACT_Pos;
pub const SCB_SHCSR_BUSFAULTACT_Pos: u32 = 1;
pub const SCB_SHCSR_BUSFAULTACT_Msk: u32 = 1 << SCB_SHCSR_BUSFAULTACT_Pos;
pub const SCB_SHCSR_MEMFAULTACT_Pos: u32 = 0;
pub const SCB_SHCSR_MEMFAULTACT_Msk: u32 = 1 << SCB_SHCSR_MEMFAULTACT_Pos;

/** \brief SCB Configurable Fault Status Register Definitions */
pub const SCB_CFSR_USGFAULTSR_Pos: u32 = 16;
pub const SCB_CFSR_USGFAULTSR_Msk: u32 = 0xFFFF << SCB_CFSR_USGFAULTSR_Pos;
pub const SCB_CFSR_BUSFAULTSR_Pos: u32 = 8;
pub const SCB_CFSR_BUSFAULTSR_Msk: u32 = 0xFF << SCB_CFSR_BUSFAULTSR_Pos;
pub const SCB_CFSR_MEMFAULTSR_Pos: u32 = 0;
pub const SCB_CFSR_MEMFAULTSR_Msk: u32 = 0xFF << SCB_CFSR_MEMFAULTSR_Pos;

/** \brief SCB Hard Fault Status Register Definitions */
pub const SCB_HFSR_DEBUGEVT_Pos: u32 = 31;
pub const SCB_HFSR_DEBUGEVT_Msk: u32 = 1 << SCB_HFSR_DEBUGEVT_Pos;
pub const SCB_HFSR_FORCED_Pos: u32 = 30;
pub const SCB_HFSR_FORCED_Msk: u32 = 1 << SCB_HFSR_FORCED_Pos;
pub const SCB_HFSR_VECTTBL_Pos: u32 = 1;
pub const SCB_HFSR_VECTTBL_Msk: u32 = 1 << SCB_HFSR_VECTTBL_Pos;

/** \brief SCB Debug Fault Status Register Definitions */
pub const SCB_DFSR_EXTERNAL_Pos: u32 = 4;
pub const SCB_DFSR_EXTERNAL_Msk: u32 = 1 << SCB_DFSR_EXTERNAL_Pos;
pub const SCB_DFSR_VCATCH_Pos: u32 = 3;
pub const SCB_DFSR_VCATCH_Msk: u32 = 1 << SCB_DFSR_VCATCH_Pos;
pub const SCB_DFSR_DWTTRAP_Pos: u32 = 2;
pub const SCB_DFSR_DWTTRAP_Msk: u32 = 1 << SCB_DFSR_DWTTRAP_Pos;
pub const SCB_DFSR_BKPT_Pos: u32 = 1;
pub const SCB_DFSR_BKPT_Msk: u32 = 1 << SCB_DFSR_BKPT_Pos;
pub const SCB_DFSR_HALTED_Pos: u32 = 0;
pub const SCB_DFSR_HALTED_Msk: u32 = 1 << SCB_DFSR_HALTED_Pos;

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

/**
 * \brief Structure type to access the Debug Control Block Registers (DCB).
 */
#[repr(C)]
pub struct DCB_Type {
    /// Offset: 0x000 (R/W)  Debug Halting Control and Status Register
    pub DHCSR: u32,
    /// Offset: 0x004 ( /W)  Debug Core Register Selector Register
    pub DCRSR: u32,
    /// Offset: 0x008 (R/W)  Debug Core Register Data Register
    pub DCRDR: u32,
    /// Offset: 0x00C (R/W)  Debug Exception and Monitor Control Register
    pub DEMCR: u32,
}

/** \brief DCB Debug Halting Control and Status Register Definitions */
pub const DCB_DHCSR_DBGKEY_Pos: u32 = 16;
pub const DCB_DHCSR_DBGKEY_Msk: u32 = 0xFFFF << DCB_DHCSR_DBGKEY_Pos;
pub const DCB_DHCSR_S_RESET_ST_Pos: u32 = 25;
pub const DCB_DHCSR_S_RESET_ST_Msk: u32 = 1 << DCB_DHCSR_S_RESET_ST_Pos;
pub const DCB_DHCSR_S_RETIRE_ST_Pos: u32 = 24;
pub const DCB_DHCSR_S_RETIRE_ST_Msk: u32 = 1 << DCB_DHCSR_S_RETIRE_ST_Pos;
pub const DCB_DHCSR_S_LOCKUP_Pos: u32 = 19;
pub const DCB_DHCSR_S_LOCKUP_Msk: u32 = 1 << DCB_DHCSR_S_LOCKUP_Pos;
pub const DCB_DHCSR_S_SLEEP_Pos: u32 = 18;
pub const DCB_DHCSR_S_SLEEP_Msk: u32 = 1 << DCB_DHCSR_S_SLEEP_Pos;
pub const DCB_DHCSR_S_HALT_Pos: u32 = 17;
pub const DCB_DHCSR_S_HALT_Msk: u32 = 1 << DCB_DHCSR_S_HALT_Pos;
pub const DCB_DHCSR_S_REGRDY_Pos: u32 = 16;
pub const DCB_DHCSR_S_REGRDY_Msk: u32 = 1 << DCB_DHCSR_S_REGRDY_Pos;
pub const DCB_DHCSR_C_SNAPSTALL_Pos: u32 = 5;
pub const DCB_DHCSR_C_SNAPSTALL_Msk: u32 = 1 << DCB_DHCSR_C_SNAPSTALL_Pos;
pub const DCB_DHCSR_C_MASKINTS_Pos: u32 = 3;
pub const DCB_DHCSR_C_MASKINTS_Msk: u32 = 1 << DCB_DHCSR_C_MASKINTS_Pos;
pub const DCB_DHCSR_C_STEP_Pos: u32 = 2;
pub const DCB_DHCSR_C_STEP_Msk: u32 = 1 << DCB_DHCSR_C_STEP_Pos;
pub const DCB_DHCSR_C_HALT_Pos: u32 = 1;
pub const DCB_DHCSR_C_HALT_Msk: u32 = 1 << DCB_DHCSR_C_HALT_Pos;
pub const DCB_DHCSR_C_DEBUGEN_Pos: u32 = 0;
pub const DCB_DHCSR_C_DEBUGEN_Msk: u32 = 1 << DCB_DHCSR_C_DEBUGEN_Pos;

/** \brief DCB Debug Exception and Monitor Control Register Definitions */
pub const DCB_DEMCR_TRCENA_Pos: u32 = 24;
pub const DCB_DEMCR_TRCENA_Msk: u32 = 1 << DCB_DEMCR_TRCENA_Pos;
pub const DCB_DEMCR_MON_REQ_Pos: u32 = 19;
pub const DCB_DEMCR_MON_REQ_Msk: u32 = 1 << DCB_DEMCR_MON_REQ_Pos;
pub const DCB_DEMCR_MON_STEP_Pos: u32 = 18;
pub const DCB_DEMCR_MON_STEP_Msk: u32 = 1 << DCB_DEMCR_MON_STEP_Pos;
pub const DCB_DEMCR_MON_PEND_Pos: u32 = 17;
pub const DCB_DEMCR_MON_PEND_Msk: u32 = 1 << DCB_DEMCR_MON_PEND_Pos;
pub const DCB_DEMCR_MON_EN_Pos: u32 = 16;
pub const DCB_DEMCR_MON_EN_Msk: u32 = 1 << DCB_DEMCR_MON_EN_Pos;
pub const DCB_DEMCR_VC_HARDERR_Pos: u32 = 10;
pub const DCB_DEMCR_VC_HARDERR_Msk: u32 = 1 << DCB_DEMCR_VC_HARDERR_Pos;
pub const DCB_DEMCR_VC_INTERR_Pos: u32 = 9;
pub const DCB_DEMCR_VC_INTERR_Msk: u32 = 1 << DCB_DEMCR_VC_INTERR_Pos;
pub const DCB_DEMCR_VC_BUSERR_Pos: u32 = 8;
pub const DCB_DEMCR_VC_BUSERR_Msk: u32 = 1 << DCB_DEMCR_VC_BUSERR_Pos;
pub const DCB_DEMCR_VC_STATERR_Pos: u32 = 7;
pub const DCB_DEMCR_VC_STATERR_Msk: u32 = 1 << DCB_DEMCR_VC_STATERR_Pos;
pub const DCB_DEMCR_VC_CHKERR_Pos: u32 = 6;
pub const DCB_DEMCR_VC_CHKERR_Msk: u32 = 1 << DCB_DEMCR_VC_CHKERR_Pos;
pub const DCB_DEMCR_VC_NOCPERR_Pos: u32 = 5;
pub const DCB_DEMCR_VC_NOCPERR_Msk: u32 = 1 << DCB_DEMCR_VC_NOCPERR_Pos;
pub const DCB_DEMCR_VC_MMERR_Pos: u32 = 4;
pub const DCB_DEMCR_VC_MMERR_Msk: u32 = 1 << DCB_DEMCR_VC_MMERR_Pos;
pub const DCB_DEMCR_VC_CORERESET_Pos: u32 = 0;
pub const DCB_DEMCR_VC_CORERESET_Msk: u32 = 1 << DCB_DEMCR_VC_CORERESET_Pos;

/* Memory mapping of Core Hardware */
pub const SCS_BASE: u32 = 0xE000E000;
pub const ITM_BASE: u32 = 0xE0000000;
pub const DWT_BASE: u32 = 0xE0001000;
pub const TPIU_BASE: u32 = 0xE0040000;
pub const DCB_BASE: u32 = 0xE000EDF0;
pub const SysTick_BASE: u32 = SCS_BASE + 0x0010;
pub const NVIC_BASE: u32 = SCS_BASE + 0x0100;
pub const SCB_BASE: u32 = SCS_BASE + 0x0D00;
