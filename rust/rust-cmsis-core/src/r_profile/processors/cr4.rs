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
 * CMSIS ARMv7-R Core Peripheral Access Layer Header File
 */

#![allow(non_snake_case)]
#![allow(non_camel_case_types)]
#![allow(non_upper_case_globals)]

/// ARMv7-R Architecture
pub const __ARM_V7R: u32 = 1;
/// FPU used
pub const __FPU_USED: u32 = 0;
/// MPU present
pub const __MPU_PRESENT: u32 = 0;
/// GIC present
pub const __GIC_PRESENT: u32 = 1;
/// VIC present
pub const __VIC_PRESENT: u32 = 0;
/// I-Cache present
pub const __ICACHE_PRESENT: u32 = 0;
/// D-Cache present
pub const __DCACHE_PRESENT: u32 = 0;
/// DTCM present
pub const __DTCM_PRESENT: u32 = 0;
/// ECC present
pub const __ECC_PRESENT: u32 = 0;

/* ========================================================================= */
/* ============                 Processor Id               ============ */
/* ========================================================================= */

/// Processor Family: ARMv7-R
pub const CMSIS_CPU: &str = "ARMv7-R";

/* ========================================================================= */
/* ============                 IO Definitions               ============ */
/* ========================================================================= */

/// Defines 'read only' permissions
pub type __I = u32;
/// Defines 'write only' permissions
pub type __O = u32;
/// Defines 'read / write' permissions
pub type __IO = u32;
/// Defines 'read only' structure member permissions
pub type __IM = u32;
/// Defines 'write only' structure member permissions
pub type __OM = u32;
/// Defines 'read / write' structure member permissions
pub type __IOM = u32;

/* ========================================================================= */
/* ============            CPSR Register (Current Program Status)              ============ */
/* ========================================================================= */

/// Union type to access the Current Program Status Register (CPSR).
#[repr(C)]
pub union CPSR_Type {
    /// Structure used for bit access
    pub b: CPSR_b,
    /// Type used for word access
    pub w: u32,
}

/// CPSR Register bitfield structure
#[repr(C)]
#[derive(Default, Clone, Copy)]
pub struct CPSR_b {
    /// bit:  0.. 4  Mode field
    pub M: u32,
    /// bit:      5  Thumb execution state bit
    pub T: u32,
    /// bit:      6  FIQ mask bit
    pub F: u32,
    /// bit:      7  IRQ mask bit
    pub I: u32,
    /// bit:      8  Asynchronous abort mask bit
    pub A: u32,
    /// bit:      9  Endianness execution state bit
    pub E: u32,
    /// bit: 10..15  If-Then execution state bits 2-7
    pub IT1: u32,
    /// bit: 16..19  Greater than or Equal flags
    pub GE: u32,
    /// bit: 20..23  Reserved
    pub _reserved0: u32,
    /// bit:     24  Jazelle bit
    pub J: u32,
    /// bit: 25..26  If-Then execution state bits 0-1
    pub IT0: u32,
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

/// CPSR Register Definitions
pub const CPSR_N_Pos: u32 = 31;
pub const CPSR_N_Msk: u32 = 1 << CPSR_N_Pos;
pub const CPSR_Z_Pos: u32 = 30;
pub const CPSR_Z_Msk: u32 = 1 << CPSR_Z_Pos;
pub const CPSR_C_Pos: u32 = 29;
pub const CPSR_C_Msk: u32 = 1 << CPSR_C_Pos;
pub const CPSR_V_Pos: u32 = 28;
pub const CPSR_V_Msk: u32 = 1 << CPSR_V_Pos;
pub const CPSR_Q_Pos: u32 = 27;
pub const CPSR_Q_Msk: u32 = 1 << CPSR_Q_Pos;
pub const CPSR_IT0_Pos: u32 = 25;
pub const CPSR_IT0_Msk: u32 = 3 << CPSR_IT0_Pos;
pub const CPSR_J_Pos: u32 = 24;
pub const CPSR_J_Msk: u32 = 1 << CPSR_J_Pos;
pub const CPSR_GE_Pos: u32 = 16;
pub const CPSR_GE_Msk: u32 = 0xF << CPSR_GE_Pos;
pub const CPSR_IT1_Pos: u32 = 10;
pub const CPSR_IT1_Msk: u32 = 0x3F << CPSR_IT1_Pos;
pub const CPSR_E_Pos: u32 = 9;
pub const CPSR_E_Msk: u32 = 1 << CPSR_E_Pos;
pub const CPSR_A_Pos: u32 = 8;
pub const CPSR_A_Msk: u32 = 1 << CPSR_A_Pos;
pub const CPSR_I_Pos: u32 = 7;
pub const CPSR_I_Msk: u32 = 1 << CPSR_I_Pos;
pub const CPSR_F_Pos: u32 = 6;
pub const CPSR_F_Msk: u32 = 1 << CPSR_F_Pos;
pub const CPSR_T_Pos: u32 = 5;
pub const CPSR_T_Msk: u32 = 1 << CPSR_T_Pos;
pub const CPSR_M_Pos: u32 = 0;
pub const CPSR_M_Msk: u32 = 0x1F << CPSR_M_Pos;

/// CPSR Mode values
pub const CPSR_M_USR: u32 = 0x10;
pub const CPSR_M_FIQ: u32 = 0x11;
pub const CPSR_M_IRQ: u32 = 0x12;
pub const CPSR_M_SVC: u32 = 0x13;
pub const CPSR_M_MON: u32 = 0x16;
pub const CPSR_M_ABT: u32 = 0x17;
pub const CPSR_M_HYP: u32 = 0x1A;
pub const CPSR_M_UND: u32 = 0x1B;
pub const CPSR_M_SYS: u32 = 0x1F;

/* ========================================================================= */
/* ============            SCTLR_EL1 Register (System Control)              ============ */
/* ========================================================================= */

/// Union type to access the System Control Register (SCTLR).
#[repr(C)]
pub union SCTLR_Type {
    /// Structure used for bit access
    pub b: SCTLR_b,
    /// Type used for word access
    pub w: u32,
}

/// SCTLR Register bitfield structure
#[repr(C)]
#[derive(Default, Clone, Copy)]
pub struct SCTLR_b {
    /// bit:      0  MMU enable
    pub M: u32,
    /// bit:      1  Alignment check enable
    pub A: u32,
    /// bit:      2  Cache enable
    pub C: u32,
    /// bit:  3.. 4  Reserved
    pub _reserved0: u32,
    /// bit:      5  CP15 barrier enable
    pub CP15BEN: u32,
    /// bit:      6  Reserved
    pub _reserved1: u32,
    /// bit:      7  Endianness model
    pub B: u32,
    /// bit:  8.. 9  Reserved
    pub _reserved2: u32,
    /// bit:     10  SWP and SWPB enable
    pub SW: u32,
    /// bit:     11  Branch prediction enable
    pub Z: u32,
    /// bit:     12  Instruction cache enable
    pub I: u32,
    /// bit:     13  Vectors bit
    pub V: u32,
    /// bit:     14  Round Robin select
    pub RR: u32,
    /// bit: 15..16  Reserved
    pub _reserved3: u32,
    /// bit:     17  Hardware Access flag enable
    pub HA: u32,
    /// bit:     18  Reserved
    pub _reserved4: u32,
    /// bit:     19  Write permission implies XN
    pub WXN: u32,
    /// bit:     20  Unprivileged write permission implies PL1 XN
    pub UWXN: u32,
    /// bit:     21  Fast interrupts configuration enable
    pub FI: u32,
    /// bit:     22  Alignment model
    pub U: u32,
    /// bit:     23  Reserved
    pub _reserved5: u32,
    /// bit:     24  Interrupt Vectors Enable
    pub VE: u32,
    /// bit:     25  Exception Endianness
    pub EE: u32,
    /// bit:     26  Reserved
    pub _reserved6: u32,
    /// bit:     27  Non-maskable FIQ (NMFI) support
    pub NMFI: u32,
    /// bit:     28  TEX remap enable
    pub TRE: u32,
    /// bit:     29  Access flag enable
    pub AFE: u32,
    /// bit:     30  Thumb Exception enable
    pub TE: u32,
    /// bit:     31  Reserved
    pub _reserved7: u32,
}

/// SCTLR Register Definitions
pub const SCTLR_TE_Pos: u32 = 30;
pub const SCTLR_TE_Msk: u32 = 1 << SCTLR_TE_Pos;
pub const SCTLR_AFE_Pos: u32 = 29;
pub const SCTLR_AFE_Msk: u32 = 1 << SCTLR_AFE_Pos;
pub const SCTLR_TRE_Pos: u32 = 28;
pub const SCTLR_TRE_Msk: u32 = 1 << SCTLR_TRE_Pos;
pub const SCTLR_NMFI_Pos: u32 = 27;
pub const SCTLR_NMFI_Msk: u32 = 1 << SCTLR_NMFI_Pos;
pub const SCTLR_EE_Pos: u32 = 25;
pub const SCTLR_EE_Msk: u32 = 1 << SCTLR_EE_Pos;
pub const SCTLR_VE_Pos: u32 = 24;
pub const SCTLR_VE_Msk: u32 = 1 << SCTLR_VE_Pos;
pub const SCTLR_U_Pos: u32 = 22;
pub const SCTLR_U_Msk: u32 = 1 << SCTLR_U_Pos;
pub const SCTLR_FI_Pos: u32 = 21;
pub const SCTLR_FI_Msk: u32 = 1 << SCTLR_FI_Pos;
pub const SCTLR_UWXN_Pos: u32 = 20;
pub const SCTLR_UWXN_Msk: u32 = 1 << SCTLR_UWXN_Pos;
pub const SCTLR_WXN_Pos: u32 = 19;
pub const SCTLR_WXN_Msk: u32 = 1 << SCTLR_WXN_Pos;
pub const SCTLR_HA_Pos: u32 = 17;
pub const SCTLR_HA_Msk: u32 = 1 << SCTLR_HA_Pos;
pub const SCTLR_RR_Pos: u32 = 14;
pub const SCTLR_RR_Msk: u32 = 1 << SCTLR_RR_Pos;
pub const SCTLR_V_Pos: u32 = 13;
pub const SCTLR_V_Msk: u32 = 1 << SCTLR_V_Pos;
pub const SCTLR_I_Pos: u32 = 12;
pub const SCTLR_I_Msk: u32 = 1 << SCTLR_I_Pos;
pub const SCTLR_Z_Pos: u32 = 11;
pub const SCTLR_Z_Msk: u32 = 1 << SCTLR_Z_Pos;
pub const SCTLR_SW_Pos: u32 = 10;
pub const SCTLR_SW_Msk: u32 = 1 << SCTLR_SW_Pos;
pub const SCTLR_B_Pos: u32 = 7;
pub const SCTLR_B_Msk: u32 = 1 << SCTLR_B_Pos;
pub const SCTLR_CP15BEN_Pos: u32 = 5;
pub const SCTLR_CP15BEN_Msk: u32 = 1 << SCTLR_CP15BEN_Pos;
pub const SCTLR_C_Pos: u32 = 2;
pub const SCTLR_C_Msk: u32 = 1 << SCTLR_C_Pos;
pub const SCTLR_A_Pos: u32 = 1;
pub const SCTLR_A_Msk: u32 = 1 << SCTLR_A_Pos;
pub const SCTLR_M_Pos: u32 = 0;
pub const SCTLR_M_Msk: u32 = 1 << SCTLR_M_Pos;

/* ========================================================================= */
/* ============            Helper Macros              ============ */
/* ========================================================================= */

#[inline(always)]
pub const fn _VAL2FLD(field: u32, value: u32) -> u32 {
    (value << field) & (field << 1)
}

#[inline(always)]
pub const fn _FLD2VAL(field: u32, value: u32) -> u32 {
    (value & (field << 1)) >> field
}
