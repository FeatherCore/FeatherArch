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
 * CMSIS ARMv8-A Core Peripheral Access Layer Header File
 */

#![allow(non_snake_case)]
#![allow(non_camel_case_types)]
#![allow(non_upper_case_globals)]

/// ARMv8-A Architecture
pub const __ARM_V8A: u32 = 1;
/// FPU used
pub const __FPU_USED: u32 = 0;
/// GIC present
pub const __GIC_PRESENT: u32 = 1;
/// TIM present
pub const __TIM_PRESENT: u32 = 1;
/// L2C present
pub const __L2C_PRESENT: u32 = 0;

/* ========================================================================= */
/* ============                 Processor Id               ============ */
/* ========================================================================= */

/// Processor Family: ARMv8-A
pub const CMSIS_CPU: &str = "ARMv8-A";

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
    /// bit:  0.. 3  Mode field
    pub M: u32,
    /// bit:  4.. 5  Reserved
    pub _reserved0: u32,
    /// bit:      6  FIQ mask bit
    pub F: u32,
    /// bit:      7  IRQ mask bit
    pub I: u32,
    /// bit:      8  Asynchronous abort mask bit
    pub A: u32,
    /// bit:      9  Endianness execution state bit
    pub E: u32,
    /// bit: 10..15  Reserved
    pub _reserved1: u32,
    /// bit: 16..19  Greater than or Equal flags
    pub GE: u32,
    /// bit:     20  Reserved
    pub _reserved2: u32,
    /// bit:     21  Data Independent Timing
    pub DIT: u32,
    /// bit:     22  Privileged Access Never
    pub PAN: u32,
    /// bit:     23  Speculative Store Bypass Safe
    pub SSBS: u32,
    /// bit: 24..26  Reserved
    pub _reserved3: u32,
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
pub const CPSR_SSBS_Pos: u32 = 23;
pub const CPSR_SSBS_Msk: u32 = 1 << CPSR_SSBS_Pos;
pub const CPSR_PAN_Pos: u32 = 22;
pub const CPSR_PAN_Msk: u32 = 1 << CPSR_PAN_Pos;
pub const CPSR_DIT_Pos: u32 = 21;
pub const CPSR_DIT_Msk: u32 = 1 << CPSR_DIT_Pos;
pub const CPSR_GE_Pos: u32 = 16;
pub const CPSR_GE_Msk: u32 = 0xF << CPSR_GE_Pos;
pub const CPSR_E_Pos: u32 = 9;
pub const CPSR_E_Msk: u32 = 1 << CPSR_E_Pos;
pub const CPSR_A_Pos: u32 = 8;
pub const CPSR_A_Msk: u32 = 1 << CPSR_A_Pos;
pub const CPSR_I_Pos: u32 = 7;
pub const CPSR_I_Msk: u32 = 1 << CPSR_I_Pos;
pub const CPSR_F_Pos: u32 = 6;
pub const CPSR_F_Msk: u32 = 1 << CPSR_F_Pos;
pub const CPSR_M_Pos: u32 = 0;
pub const CPSR_M_Msk: u32 = 0xF << CPSR_M_Pos;

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

/// Union type to access the System Control Register (SCTLR_EL1).
#[repr(C)]
pub union SCTLR_EL1_Type {
    /// Structure used for bit access
    pub b: SCTLR_EL1_b,
    /// Type used for word access
    pub w: u64,
}

/// SCTLR_EL1 Register bitfield structure
#[repr(C)]
#[derive(Default, Clone, Copy)]
pub struct SCTLR_EL1_b {
    /// bit:      0  MMU enable
    pub M: u64,
    /// bit:      1  Alignment check enable
    pub A: u64,
    /// bit:      2  Cache enable
    pub C: u64,
    /// bit:      3  SP Alignment check enable
    pub SA: u64,
    /// bit:  4.. 5  Reserved
    pub _reserved0: u64,
    /// bit:      6  Non-aligned access
    pub nAA: u64,
    /// bit:  7..10  Reserved
    pub _reserved1: u64,
    /// bit:     11  Exception Exit is Context Synchronizing
    pub EOS: u64,
    /// bit:     12  Instruction cache enable
    pub I: u64,
    /// bit:     13  EnDB
    pub EnDB: u64,
    /// bit: 14..15  Reserved
    pub _reserved2: u64,
    /// bit:     16  Reserved
    pub _reserved3: u64,
    /// bit:     17  Reserved
    pub _reserved4: u64,
    /// bit:     18  Reserved
    pub _reserved5: u64,
    /// bit:     19  Write permission implies XN
    pub WXN: u64,
    /// bit:     20  Reserved
    pub _reserved6: u64,
    /// bit:     21  IESB
    pub IESB: u64,
    /// bit:     22  EIS
    pub EIS: u64,
    /// bit:     23  Reserved
    pub _reserved7: u64,
    /// bit:     24  Reserved
    pub _reserved8: u64,
    /// bit:     25  Exception Endianness
    pub EE: u64,
    /// bit:     26  Reserved
    pub _reserved9: u64,
    /// bit:     27  EnDA
    pub EnDA: u64,
    /// bit: 28..29  Reserved
    pub _reserved10: u64,
    /// bit:     30  EnIB
    pub EnIB: u64,
    /// bit:     31  EnIA
    pub EnIA: u64,
    /// bit: 32..35  Reserved
    pub _reserved11: u64,
    /// bit:     36  BT
    pub BT: u64,
    /// bit:     37  ITFSB
    pub ITFSB: u64,
    /// bit: 38..39  Reserved
    pub _reserved12: u64,
    /// bit: 40..41  TCF
    pub TCF: u64,
    /// bit:     42  Reserved
    pub _reserved13: u64,
    /// bit:     43  ATA
    pub ATA: u64,
    /// bit:     44  DSSBS
    pub DSSBS: u64,
    /// bit: 45..63  Reserved
    pub _reserved14: u64,
}

/// SCTLR_EL1 Register Definitions
pub const SCTLR_EL1_M_Pos: u32 = 0;
pub const SCTLR_EL1_M_Msk: u64 = 1 << SCTLR_EL1_M_Pos;
pub const SCTLR_EL1_A_Pos: u32 = 1;
pub const SCTLR_EL1_A_Msk: u64 = 1 << SCTLR_EL1_A_Pos;
pub const SCTLR_EL1_C_Pos: u32 = 2;
pub const SCTLR_EL1_C_Msk: u64 = 1 << SCTLR_EL1_C_Pos;
pub const SCTLR_EL1_SA_Pos: u32 = 3;
pub const SCTLR_EL1_SA_Msk: u64 = 1 << SCTLR_EL1_SA_Pos;
pub const SCTLR_EL1_nAA_Pos: u32 = 6;
pub const SCTLR_EL1_nAA_Msk: u64 = 1 << SCTLR_EL1_nAA_Pos;
pub const SCTLR_EL1_I_Pos: u32 = 12;
pub const SCTLR_EL1_I_Msk: u64 = 1 << SCTLR_EL1_I_Pos;
pub const SCTLR_EL1_WXN_Pos: u32 = 19;
pub const SCTLR_EL1_WXN_Msk: u64 = 1 << SCTLR_EL1_WXN_Pos;
pub const SCTLR_EL1_EE_Pos: u32 = 25;
pub const SCTLR_EL1_EE_Msk: u64 = 1 << SCTLR_EL1_EE_Pos;
pub const SCTLR_EL1_E_Pos: u32 = 9;
pub const SCTLR_EL1_E_Msk: u64 = 1 << SCTLR_EL1_E_Pos;

/* ========================================================================= */
/* ============            MPIDR_EL1 Register (Multiprocessor Affinity)              ============ */
/* ========================================================================= */

/// Union type to access the Multiprocessor Affinity Register (MPIDR_EL1).
#[repr(C)]
pub union MPIDR_EL1_Type {
    /// Structure used for bit access
    pub b: MPIDR_EL1_b,
    /// Type used for word access
    pub w: u64,
}

/// MPIDR_EL1 Register bitfield structure
#[repr(C)]
#[derive(Default, Clone, Copy)]
pub struct MPIDR_EL1_b {
    /// bit:  0.. 7  Affinity level 0
    pub Aff0: u64,
    /// bit:  8..15  Affinity level 1
    pub Aff1: u64,
    /// bit: 16..23  Affinity level 2
    pub Aff2: u64,
    /// bit:     24  Multithreading
    pub MT: u64,
    /// bit: 25..29  Reserved
    pub _reserved0: u64,
    /// bit:     30  Uniprocessor or AMP
    pub U: u64,
    /// bit:     31  Reserved
    pub _reserved1: u64,
    /// bit: 32..39  Affinity level 3
    pub Aff3: u64,
    /// bit: 40..63  Reserved
    pub _reserved2: u64,
}

/// MPIDR_EL1 Register Definitions
pub const MPIDR_AFFLVL_MASK: u64 = 0xFF;
pub const MPIDR_AFF0_SHIFT: u64 = 0;
pub const MPIDR_AFF1_SHIFT: u64 = 8;
pub const MPIDR_AFF2_SHIFT: u64 = 16;
pub const MPIDR_AFF3_SHIFT: u64 = 32;

/* ========================================================================= */
/* ============            Helper Macros              ============ */
/* ========================================================================= */

#[inline(always)]
pub const fn _VAL2FLD(field: u64, value: u64) -> u64 {
    (value << field) & (field << 1)
}

#[inline(always)]
pub const fn _FLD2VAL(field: u64, value: u64) -> u64 {
    (value & (field << 1)) >> field
}
