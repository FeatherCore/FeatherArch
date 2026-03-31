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
 * CMSIS Cortex-M7 Core Peripheral Access Layer Header File
 */

#![allow(non_snake_case)]
#![allow(non_camel_case_types)]
#![allow(non_upper_case_globals)]

/// Cortex-M Core
pub const __CORTEX_M: u32 = 7;
/// FPU not present by default
pub const __FPU_USED: u32 = 0;
/// MPU not present by default
pub const __MPU_PRESENT: u32 = 0;
/// VTOR present
pub const __VTOR_PRESENT: u32 = 1;
/// Cortex-M7 revision
pub const __CM7_REV: u32 = 0x0000;
/// Number of priority bits
pub const __NVIC_PRIO_BITS: u32 = 4;
/// Use vendor specific SysTick config
pub const __Vendor_SysTickConfig: u32 = 0;

/* ========================================================================= */
/* ============                 Processor Id               ============ */
/* ========================================================================= */

/// Processor Family: Cortex-M7
pub const CMSIS_CPU: &str = "Cortex-M7";

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

/// Union type to access the Application Program Status Register (APSR).
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
    /// bit:  0..15  Reserved
    pub _reserved0: u32,
    /// bit: 16..19  Greater than or Equal flags
    pub GE: u32,
    /// bit: 20..26  Reserved
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

/// APSR Register Definitions
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
pub const APSR_GE_Pos: u32 = 16;
pub const APSR_GE_Msk: u32 = 0xF << APSR_GE_Pos;

/// Union type to access the Interrupt Program Status Register (IPSR).
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

/// IPSR Register Definitions
pub const IPSR_ISR_Pos: u32 = 0;
pub const IPSR_ISR_Msk: u32 = 0x1FF << IPSR_ISR_Pos;

/// Union type to access the Special-Purpose Program Status Registers (xPSR).
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
    /// bit:  9..15  Reserved
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

/// xPSR Register Definitions
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

/// Union type to access the Control Registers (CONTROL).
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
    /// bit:      2  FPU extension active flag
    pub FPCA: u32,
    /// bit:  3..31  Reserved
    pub _reserved0: u32,
}

/// CONTROL Register Definitions
pub const CONTROL_FPCA_Pos: u32 = 2;
pub const CONTROL_FPCA_Msk: u32 = 1 << CONTROL_FPCA_Pos;
pub const CONTROL_SPSEL_Pos: u32 = 1;
pub const CONTROL_SPSEL_Msk: u32 = 1 << CONTROL_SPSEL_Pos;
pub const CONTROL_nPRIV_Pos: u32 = 0;
pub const CONTROL_nPRIV_Msk: u32 = 1 << CONTROL_nPRIV_Pos;

/// Union type to access the Floating Point Status and Control Register (FPSCR).
#[repr(C)]
pub union FPSCR_Type {
    /// Structure used for bit access
    pub b: FPSCR_b,
    /// Type used for word access
    pub w: u32,
}

/// FPSCR Register bitfield structure
#[repr(C)]
#[derive(Default, Clone, Copy)]
pub struct FPSCR_b {
    /// bit:   0..27  Reserved
    pub _reserved0: u32,
    /// bit:     28  Inexact exception flag
    pub IXC: u32,
    /// bit:     29  Underflow exception flag
    pub UFC: u32,
    /// bit:     30  Overflow exception flag
    pub OFC: u32,
    /// bit:     31  Division by Zero exception flag
    pub DZC: u32,
    /// bit:     32  Invalid Operation exception flag
    pub IOC: u32,
}

/// FPSCR Register Definitions
pub const FPSCR_IOC_Pos: u32 = 0;
pub const FPSCR_IOC_Msk: u32 = 1 << FPSCR_IOC_Pos;
pub const FPSCR_DZC_Pos: u32 = 1;
pub const FPSCR_DZC_Msk: u32 = 1 << FPSCR_DZC_Pos;
pub const FPSCR_OFC_Pos: u32 = 2;
pub const FPSCR_OFC_Msk: u32 = 1 << FPSCR_OFC_Pos;
pub const FPSCR_UFC_Pos: u32 = 3;
pub const FPSCR_UFC_Msk: u32 = 1 << FPSCR_UFC_Pos;
pub const FPSCR_IXC_Pos: u32 = 4;
pub const FPSCR_IXC_Msk: u32 = 1 << FPSCR_IXC_Pos;

/* ========================================================================= */
/* ============                  NVIC Registers              ============ */
/* ========================================================================= */

/// Structure type to access the Nested Vectored Interrupt Controller (NVIC).
#[repr(C)]
#[derive(Clone, Copy)]
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

/// NVIC Software Triggered Interrupt Register Definitions
pub const NVIC_STIR_INTID_Pos: u32 = 0;
pub const NVIC_STIR_INTID_Msk: u32 = 0x1FF << NVIC_STIR_INTID_Pos;

/* ========================================================================= */
/* ============                  SCB Registers              ============ */
/* ========================================================================= */

/// Structure type to access the System Control Block (SCB).
#[repr(C)]
#[derive(Clone, Copy)]
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
    _reserved0: [u32; 1],
    /// Offset: 0x078 (R/ )  Cache Level ID register
    pub CLIDR: u32,
    /// Offset: 0x07C (R/ )  Cache Type register
    pub CTR: u32,
    /// Offset: 0x080 (R/ )  Cache Size ID Register
    pub CCSIDR: u32,
    /// Offset: 0x084 (R/W)  Cache Size Selection Register
    pub CSSELR: u32,
    /// Offset: 0x088 (R/W)  Coprocessor Access Control Register
    pub CPACR: u32,
    _reserved1: [u32; 93],
    /// Offset: 0x200 ( /W)  Software Triggered Interrupt Register
    pub STIR: u32,
    _reserved2: [u32; 15],
    /// Offset: 0x240 (R/ )  Media and VFP Feature Register 0
    pub MVFR0: u32,
    /// Offset: 0x244 (R/ )  Media and VFP Feature Register 1
    pub MVFR1: u32,
    /// Offset: 0x248 (R/ )  Media and VFP Feature Register 2
    pub MVFR2: u32,
    _reserved3: [u32; 1],
    /// Offset: 0x250 ( /W)  I-Cache Invalidate All to PoU
    pub ICIALLU: u32,
    _reserved4: [u32; 1],
    /// Offset: 0x258 ( /W)  I-Cache Invalidate by MVA to PoU
    pub ICIMVAU: u32,
    /// Offset: 0x25C ( /W)  D-Cache Invalidate by MVA to PoC
    pub DCIMVAC: u32,
    /// Offset: 0x260 ( /W)  D-Cache Invalidate by Set-way
    pub DCISW: u32,
    /// Offset: 0x264 ( /W)  D-Cache Clean by MVA to PoU
    pub DCCMVAU: u32,
    /// Offset: 0x268 ( /W)  D-Cache Clean by MVA to PoC
    pub DCCMVAC: u32,
    /// Offset: 0x26C ( /W)  D-Cache Clean by Set-way
    pub DCCSW: u32,
    /// Offset: 0x270 ( /W)  D-Cache Clean and Invalidate by MVA to PoC
    pub DCCIMVAC: u32,
    /// Offset: 0x274 ( /W)  D-Cache Clean and Invalidate by Set-way
    pub DCCISW: u32,
    /// Offset: 0x278 ( /W)  Branch Predictor Invalidate All
    pub BPIALL: u32,
    _reserved5: [u32; 5],
    /// Offset: 0x290 (R/W)  Instruction Tightly-Coupled Memory Control Register
    pub ITCMCR: u32,
    /// Offset: 0x294 (R/W)  Data Tightly-Coupled Memory Control Registers
    pub DTCMCR: u32,
    /// Offset: 0x298 (R/W)  AHBP Control Register
    pub AHBPCR: u32,
    /// Offset: 0x29C (R/W)  L1 Cache Control Register
    pub CACR: u32,
    /// Offset: 0x2A0 (R/W)  AHB Slave Control Register
    pub AHBSCR: u32,
    _reserved6: [u32; 1],
    /// Offset: 0x2A8 (R/W)  Auxiliary Bus Fault Status Register
    pub ABFSR: u32,
}

/// SCB CPUID Register Definitions
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

/// SCB Interrupt Control State Register Definitions
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

/// SCB Vector Table Offset Register Definitions
pub const SCB_VTOR_TBLOFF_Pos: u32 = 7;
pub const SCB_VTOR_TBLOFF_Msk: u32 = 0x1FFFFFF << SCB_VTOR_TBLOFF_Pos;

/// SCB Application Interrupt and Reset Control Register Definitions
pub const SCB_AIRCR_VECTKEY_Pos: u32 = 16;
pub const SCB_AIRCR_VECTKEY_Msk: u32 = 0xFFFF << SCB_AIRCR_VECTKEY_Pos;
pub const SCB_AIRCR_VECTKEYSTAT_Pos: u32 = 16;
pub const SCB_AIRCR_VECTKEYSTAT_Msk: u32 = 0xFFFF << SCB_AIRCR_VECTKEYSTAT_Pos;
pub const SCB_AIRCR_ENDIANNESS_Pos: u32 = 15;
pub const SCB_AIRCR_ENDIANNESS_Msk: u32 = 1 << SCB_AIRCR_ENDIANNESS_Pos;
pub const SCB_AIRCR_PRIGROUP_Pos: u32 = 8;
pub const SCB_AIRCR_PRIGROUP_Msk: u32 = 7 << SCB_AIRCR_PRIGROUP_Pos;
pub const SCB_AIRCR_SYSRESETREQ_Pos: u32 = 2;
pub const SCB_AIRCR_SYSRESETREQ_Msk: u32 = 1 << SCB_AIRCR_SYSRESETREQ_Pos;
pub const SCB_AIRCR_VECTCLRACTIVE_Pos: u32 = 1;
pub const SCB_AIRCR_VECTCLRACTIVE_Msk: u32 = 1 << SCB_AIRCR_VECTCLRACTIVE_Pos;
pub const SCB_AIRCR_VECTRESET_Pos: u32 = 0;
pub const SCB_AIRCR_VECTRESET_Msk: u32 = 1 << SCB_AIRCR_VECTRESET_Pos;

/// SCB System Control Register Definitions
pub const SCB_SCR_SEVONPEND_Pos: u32 = 4;
pub const SCB_SCR_SEVONPEND_Msk: u32 = 1 << SCB_SCR_SEVONPEND_Pos;
pub const SCB_SCR_SLEEPDEEP_Pos: u32 = 2;
pub const SCB_SCR_SLEEPDEEP_Msk: u32 = 1 << SCB_SCR_SLEEPDEEP_Pos;
pub const SCB_SCR_SLEEPONEXIT_Pos: u32 = 1;
pub const SCB_SCR_SLEEPONEXIT_Msk: u32 = 1 << SCB_SCR_SLEEPONEXIT_Pos;

/// SCB Configuration Control Register Definitions
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

/// SCB System Handler Control and State Register Definitions
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

/// SCB Configurable Fault Status Register Definitions
pub const SCB_CFSR_USGFAULTSR_Pos: u32 = 16;
pub const SCB_CFSR_USGFAULTSR_Msk: u32 = 0xFFFF << SCB_CFSR_USGFAULTSR_Pos;
pub const SCB_CFSR_BUSFAULTSR_Pos: u32 = 8;
pub const SCB_CFSR_BUSFAULTSR_Msk: u32 = 0xFF << SCB_CFSR_BUSFAULTSR_Pos;
pub const SCB_CFSR_MEMFAULTSR_Pos: u32 = 0;
pub const SCB_CFSR_MEMFAULTSR_Msk: u32 = 0xFF << SCB_CFSR_MEMFAULTSR_Pos;

/// SCB Hard Fault Status Register Definitions
pub const SCB_HFSR_DEBUGEVT_Pos: u32 = 31;
pub const SCB_HFSR_DEBUGEVT_Msk: u32 = 1 << SCB_HFSR_DEBUGEVT_Pos;
pub const SCB_HFSR_FORCED_Pos: u32 = 30;
pub const SCB_HFSR_FORCED_Msk: u32 = 1 << SCB_HFSR_FORCED_Pos;
pub const SCB_HFSR_VECTTBL_Pos: u32 = 1;
pub const SCB_HFSR_VECTTBL_Msk: u32 = 1 << SCB_HFSR_VECTTBL_Pos;

/// SCB Debug Fault Status Register Definitions
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

/// SCB Cache Level ID Register Definitions
pub const SCB_CLIDR_LOUU_Pos: u32 = 27;
pub const SCB_CLIDR_LOUU_Msk: u32 = 7 << SCB_CLIDR_LOUU_Pos;
pub const SCB_CLIDR_LOC_Pos: u32 = 24;
pub const SCB_CLIDR_LOC_Msk: u32 = 7 << SCB_CLIDR_LOC_Pos;

/// SCB Cache Type Register Definitions
pub const SCB_CTR_FORMAT_Pos: u32 = 29;
pub const SCB_CTR_FORMAT_Msk: u32 = 7 << SCB_CTR_FORMAT_Pos;
pub const SCB_CTR_CWG_Pos: u32 = 24;
pub const SCB_CTR_CWG_Msk: u32 = 0xF << SCB_CTR_CWG_Pos;
pub const SCB_CTR_ERG_Pos: u32 = 20;
pub const SCB_CTR_ERG_Msk: u32 = 0xF << SCB_CTR_ERG_Pos;
pub const SCB_CTR_DMINLINE_Pos: u32 = 16;
pub const SCB_CTR_DMINLINE_Msk: u32 = 0xF << SCB_CTR_DMINLINE_Pos;
pub const SCB_CTR_IMINLINE_Pos: u32 = 0;
pub const SCB_CTR_IMINLINE_Msk: u32 = 0xF << SCB_CTR_IMINLINE_Pos;

/// SCB Cache Size Selection Register Definitions
pub const SCB_CSSELR_LEVEL_Pos: u32 = 1;
pub const SCB_CSSELR_LEVEL_Msk: u32 = 7 << SCB_CSSELR_LEVEL_Pos;
pub const SCB_CSSELR_IND_Pos: u32 = 0;
pub const SCB_CSSELR_IND_Msk: u32 = 1 << SCB_CSSELR_IND_Pos;

/// SCB D-Cache line Invalidate by Set-way Register Definitions
pub const SCB_DCISW_LEVEL_Pos: u32 = 1;
pub const SCB_DCISW_LEVEL_Msk: u32 = 7 << SCB_DCISW_LEVEL_Pos;
pub const SCB_DCISW_WAY_Pos: u32 = 30;
pub const SCB_DCISW_WAY_Msk: u32 = 3 << SCB_DCISW_WAY_Pos;
pub const SCB_DCISW_SET_Pos: u32 = 5;
pub const SCB_DCISW_SET_Msk: u32 = 0xFF << SCB_DCISW_SET_Pos;

/// SCB D-Cache Clean line by Set-way Register Definitions
pub const SCB_DCCSW_LEVEL_Pos: u32 = 1;
pub const SCB_DCCSW_LEVEL_Msk: u32 = 7 << SCB_DCCSW_LEVEL_Pos;
pub const SCB_DCCSW_WAY_Pos: u32 = 30;
pub const SCB_DCCSW_WAY_Msk: u32 = 3 << SCB_DCCSW_WAY_Pos;
pub const SCB_DCCSW_SET_Pos: u32 = 5;
pub const SCB_DCCSW_SET_Msk: u32 = 0xFF << SCB_DCCSW_SET_Pos;

/// SCB D-Cache Clean and Invalidate by Set-way Register Definitions
pub const SCB_DCCISW_LEVEL_Pos: u32 = 1;
pub const SCB_DCCISW_LEVEL_Msk: u32 = 7 << SCB_DCCISW_LEVEL_Pos;
pub const SCB_DCCISW_WAY_Pos: u32 = 30;
pub const SCB_DCCISW_WAY_Msk: u32 = 3 << SCB_DCCISW_WAY_Pos;
pub const SCB_DCCISW_SET_Pos: u32 = 5;
pub const SCB_DCCISW_SET_Msk: u32 = 0xFF << SCB_DCCISW_SET_Pos;

/// SCB Instruction Tightly-Coupled Memory Control Register Definitions
pub const SCB_ITCMCR_SZ_Pos: u32 = 3;
pub const SCB_ITCMCR_SZ_Msk: u32 = 0xF << SCB_ITCMCR_SZ_Pos;
pub const SCB_ITCMCR_RETEN_Pos: u32 = 2;
pub const SCB_ITCMCR_RETEN_Msk: u32 = 1 << SCB_ITCMCR_RETEN_Pos;
pub const SCB_ITCMCR_RMW_Pos: u32 = 1;
pub const SCB_ITCMCR_RMW_Msk: u32 = 1 << SCB_ITCMCR_RMW_Pos;
pub const SCB_ITCMCR_EN_Pos: u32 = 0;
pub const SCB_ITCMCR_EN_Msk: u32 = 1 << SCB_ITCMCR_EN_Pos;

/// SCB Data Tightly-Coupled Memory Control Register Definitions
pub const SCB_DTCMCR_SZ_Pos: u32 = 3;
pub const SCB_DTCMCR_SZ_Msk: u32 = 0xF << SCB_DTCMCR_SZ_Pos;
pub const SCB_DTCMCR_RETEN_Pos: u32 = 2;
pub const SCB_DTCMCR_RETEN_Msk: u32 = 1 << SCB_DTCMCR_RETEN_Pos;
pub const SCB_DTCMCR_RMW_Pos: u32 = 1;
pub const SCB_DTCMCR_RMW_Msk: u32 = 1 << SCB_DTCMCR_RMW_Pos;
pub const SCB_DTCMCR_EN_Pos: u32 = 0;
pub const SCB_DTCMCR_EN_Msk: u32 = 1 << SCB_DTCMCR_EN_Pos;

/// SCB AHBP Control Register Definitions
pub const SCB_AHBPCR_SZ_Pos: u32 = 1;
pub const SCB_AHBPCR_SZ_Msk: u32 = 0x7 << SCB_AHBPCR_SZ_Pos;
pub const SCB_AHBPCR_EN_Pos: u32 = 0;
pub const SCB_AHBPCR_EN_Msk: u32 = 1 << SCB_AHBPCR_EN_Pos;

/// SCB L1 Cache Control Register Definitions
pub const SCB_CACR_DCCLEAN_Pos: u32 = 16;
pub const SCB_CACR_DCCLEAN_Msk: u32 = 1 << SCB_CACR_DCCLEAN_Pos;
pub const SCB_CACR_DCACTIVE_Pos: u32 = 14;
pub const SCB_CACR_DCACTIVE_Msk: u32 = 1 << SCB_CACR_DCACTIVE_Pos;
pub const SCB_CACR_ICACTIVE_Pos: u32 = 13;
pub const SCB_CACR_ICACTIVE_Msk: u32 = 1 << SCB_CACR_ICACTIVE_Pos;
pub const SCB_CACR_EIR_Pos: u32 = 8;
pub const SCB_CACR_EIR_Msk: u32 = 1 << SCB_CACR_EIR_Pos;
pub const SCB_CACR_FORCEWT_Pos: u32 = 0;
pub const SCB_CACR_FORCEWT_Msk: u32 = 1 << SCB_CACR_FORCEWT_Pos;

/// SCB AHB Slave Control Register Definitions
pub const SCB_AHBSCR_FTTLBDIS_Pos: u32 = 9;
pub const SCB_AHBSCR_FTTLBDIS_Msk: u32 = 1 << SCB_AHBSCR_FTTLBDIS_Pos;
pub const SCB_AHBSCR_CTLBDIS_Pos: u32 = 8;
pub const SCB_AHBSCR_CTLBDIS_Msk: u32 = 1 << SCB_AHBSCR_CTLBDIS_Pos;
pub const SCB_AHBSCR_INITCOUNT_Pos: u32 = 0;
pub const SCB_AHBSCR_INITCOUNT_Msk: u32 = 0xFF << SCB_AHBSCR_INITCOUNT_Pos;

/// SCB Auxiliary Bus Fault Status Register Definitions
pub const SCB_ABFSR_IMPEC_Pos: u32 = 8;
pub const SCB_ABFSR_IMPEC_Msk: u32 = 1 << SCB_ABFSR_IMPEC_Pos;
pub const SCB_ABFSR_PREC_Pos: u32 = 4;
pub const SCB_ABFSR_PREC_Msk: u32 = 1 << SCB_ABFSR_PREC_Pos;
pub const SCB_ABFSR_BUTC_Pos: u32 = 3;
pub const SCB_ABFSR_BUTC_Msk: u32 = 1 << SCB_ABFSR_BUTC_Pos;
pub const SCB_ABFSR_BTIMC_Pos: u32 = 2;
pub const SCB_ABFSR_BTIMC_Msk: u32 = 1 << SCB_ABFSR_BTIMC_Pos;
pub const SCB_ABFSR_ABSTR_Pos: u32 = 0;
pub const SCB_ABFSR_ABSTR_Msk: u32 = 1 << SCB_ABFSR_ABSTR_Pos;

/// SCB Software Triggered Interrupt Register Definitions
pub const SCB_STIR_INTID_Pos: u32 = 0;
pub const SCB_STIR_INTID_Msk: u32 = 0x1FF << SCB_STIR_INTID_Pos;

/* ========================================================================= */
/* ============              SysTick Registers              ============ */
/* ========================================================================= */

/// Structure type to access the System Timer (SysTick).
#[repr(C)]
#[derive(Default, Clone, Copy)]
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

/// SysTick Control / Status Register Definitions
pub const SysTick_CTRL_COUNTFLAG_Pos: u32 = 16;
pub const SysTick_CTRL_COUNTFLAG_Msk: u32 = 1 << SysTick_CTRL_COUNTFLAG_Pos;
pub const SysTick_CTRL_CLKSOURCE_Pos: u32 = 2;
pub const SysTick_CTRL_CLKSOURCE_Msk: u32 = 1 << SysTick_CTRL_CLKSOURCE_Pos;
pub const SysTick_CTRL_TICKINT_Pos: u32 = 1;
pub const SysTick_CTRL_TICKINT_Msk: u32 = 1 << SysTick_CTRL_TICKINT_Pos;
pub const SysTick_CTRL_ENABLE_Pos: u32 = 0;
pub const SysTick_CTRL_ENABLE_Msk: u32 = 1 << SysTick_CTRL_ENABLE_Pos;

/// SysTick Reload Register Definitions
pub const SysTick_LOAD_RELOAD_Pos: u32 = 0;
pub const SysTick_LOAD_RELOAD_Msk: u32 = 0xFFFFFF << SysTick_LOAD_RELOAD_Pos;

/// SysTick Current Register Definitions
pub const SysTick_VAL_CURRENT_Pos: u32 = 0;
pub const SysTick_VAL_CURRENT_Msk: u32 = 0xFFFFFF << SysTick_VAL_CURRENT_Pos;

/// SysTick Calibration Register Definitions
pub const SysTick_CALIB_NOREF_Pos: u32 = 31;
pub const SysTick_CALIB_NOREF_Msk: u32 = 1 << SysTick_CALIB_NOREF_Pos;
pub const SysTick_CALIB_SKEW_Pos: u32 = 30;
pub const SysTick_CALIB_SKEW_Msk: u32 = 1 << SysTick_CALIB_SKEW_Pos;
pub const SysTick_CALIB_TENMS_Pos: u32 = 0;
pub const SysTick_CALIB_TENMS_Msk: u32 = 0xFFFFFF << SysTick_CALIB_TENMS_Pos;

/* ========================================================================= */
/* ============             Memory Base Addresses              ============ */
/* ========================================================================= */

/// System Control Space Base Address
pub const SCS_BASE: u32 = 0xE000E000;
/// SysTick Base Address
pub const SysTick_BASE: u32 = SCS_BASE + 0x0010;
/// NVIC Base Address
pub const NVIC_BASE: u32 = SCS_BASE + 0x0100;
/// System Control Block Base Address
pub const SCB_BASE: u32 = SCS_BASE + 0x0D00;
/// ITM Base Address
pub const ITM_BASE: u32 = 0xE0000000;
/// DWT Base Address
pub const DWT_BASE: u32 = SCS_BASE + 0x1000;
/// TPIU Base Address
pub const TPIU_BASE: u32 = SCS_BASE + 0x2000;
/// DCB Base Address
pub const DCB_BASE: u32 = 0xE000EDF0;

/// The following EXC_RETURN values are saved the LR on exception entry
pub const EXC_RETURN_HANDLER: u32 = 0xFFFFFFF1;
pub const EXC_RETURN_THREAD_MSP: u32 = 0xFFFFFFF9;
pub const EXC_RETURN_THREAD_PSP: u32 = 0xFFFFFFFD;

pub const NVIC_USER_IRQ_OFFSET: u32 = 16;
