#![allow(non_snake_case)]
#![allow(asm_sub_register)]

use core::arch::asm;

/* Core Register CPSR */

/// CPSR: N Position
pub const CPSR_N_Pos: u32 = 31;
/// CPSR: N Mask
pub const CPSR_N_Msk: u64 = 1 << CPSR_N_Pos;

/// CPSR: Z Position
pub const CPSR_Z_Pos: u32 = 30;
/// CPSR: Z Mask
pub const CPSR_Z_Msk: u64 = 1 << CPSR_Z_Pos;

/// CPSR: C Position
pub const CPSR_C_Pos: u32 = 29;
/// CPSR: C Mask
pub const CPSR_C_Msk: u64 = 1 << CPSR_C_Pos;

/// CPSR: V Position
pub const CPSR_V_Pos: u32 = 28;
/// CPSR: V Mask
pub const CPSR_V_Msk: u64 = 1 << CPSR_V_Pos;

/// CPSR: Q Position
pub const CPSR_Q_Pos: u32 = 27;
/// CPSR: Q Mask
pub const CPSR_Q_Msk: u64 = 1 << CPSR_Q_Pos;

/// CPSR: SSBS Position
pub const CPSR_SSBS_Pos: u32 = 23;
/// CPSR: SSBS Mask
pub const CPSR_SSBS_Msk: u64 = 1 << CPSR_SSBS_Pos;

/// CPSR: PAN Position
pub const CPSR_PAN_Pos: u32 = 22;
/// CPSR: PAN Mask
pub const CPSR_PAN_Msk: u64 = 1 << CPSR_PAN_Pos;

/// CPSR: DIT Position
pub const CPSR_DIT_Pos: u32 = 21;
/// CPSR: DIT Mask
pub const CPSR_DIT_Msk: u64 = 1 << CPSR_DIT_Pos;

/// CPSR: GE Position
pub const CPSR_GE_Pos: u32 = 16;
/// CPSR: GE Mask
pub const CPSR_GE_Msk: u64 = 0xF << CPSR_GE_Pos;

/// CPSR: E Position
pub const CPSR_E_Pos: u32 = 9;
/// CPSR: E Mask
pub const CPSR_E_Msk: u64 = 1 << CPSR_E_Pos;

/// CPSR: A Position
pub const CPSR_A_Pos: u32 = 8;
/// CPSR: A Mask
pub const CPSR_A_Msk: u64 = 1 << CPSR_A_Pos;

/// CPSR: I Position
pub const CPSR_I_Pos: u32 = 7;
/// CPSR: I Mask
pub const CPSR_I_Msk: u64 = 1 << CPSR_I_Pos;

/// CPSR: F Position
pub const CPSR_F_Pos: u32 = 6;
/// CPSR: F Mask
pub const CPSR_F_Msk: u64 = 1 << CPSR_F_Pos;

/// CPSR: M Position
pub const CPSR_M_Pos: u32 = 0;
/// CPSR: M Mask
pub const CPSR_M_Msk: u64 = 0xF << CPSR_M_Pos;

/// CPSR: M User mode (PL0)
pub const CPSR_M_USR: u32 = 0x10;
/// CPSR: M Fast Interrupt mode (PL1)
pub const CPSR_M_FIQ: u32 = 0x11;
/// CPSR: M Interrupt mode (PL1)
pub const CPSR_M_IRQ: u32 = 0x12;
/// CPSR: M Supervisor mode (PL1)
pub const CPSR_M_SVC: u32 = 0x13;
/// CPSR: M Monitor mode (PL1)
pub const CPSR_M_MON: u32 = 0x16;
/// CPSR: M Abort mode (PL1)
pub const CPSR_M_ABT: u32 = 0x17;
/// CPSR: M Hypervisor mode (PL2)
pub const CPSR_M_HYP: u32 = 0x1A;
/// CPSR: M Undefined mode (PL1)
pub const CPSR_M_UND: u32 = 0x1B;
/// CPSR: M System mode (PL1)
pub const CPSR_M_SYS: u32 = 0x1F;

/* Register SCTLR */

/// SCTLR: TE Position
pub const SCTLR_TE_Pos: u32 = 30;
/// SCTLR: TE Mask
pub const SCTLR_TE_Msk: u64 = 1 << SCTLR_TE_Pos;

/// SCTLR: AFE Position
pub const SCTLR_AFE_Pos: u32 = 29;
/// SCTLR: AFE Mask
pub const SCTLR_AFE_Msk: u64 = 1 << SCTLR_AFE_Pos;

/// SCTLR: TRE Position
pub const SCTLR_TRE_Pos: u32 = 28;
/// SCTLR: TRE Mask
pub const SCTLR_TRE_Msk: u64 = 1 << SCTLR_TRE_Pos;

/// SCTLR: EE Position
pub const SCTLR_EE_Pos: u32 = 25;
/// SCTLR: EE Mask
pub const SCTLR_EE_Msk: u64 = 1 << SCTLR_EE_Pos;

/// SCTLR: UWXN Position
pub const SCTLR_UWXN_Pos: u32 = 20;
/// SCTLR: UWXN Mask
pub const SCTLR_UWXN_Msk: u64 = 1 << SCTLR_UWXN_Pos;

/// SCTLR: WXN Position
pub const SCTLR_WXN_Pos: u32 = 19;
/// SCTLR: WXN Mask
pub const SCTLR_WXN_Msk: u64 = 1 << SCTLR_WXN_Pos;

/// SCTLR: nTWE Position
pub const SCTLR_nTWE_Pos: u32 = 18;
/// SCTLR: nTWE Mask
pub const SCTLR_nTWE_Msk: u64 = 1 << SCTLR_nTWE_Pos;

/// SCTLR: nTWI Position
pub const SCTLR_nTWI_Pos: u32 = 16;
/// SCTLR: nTWI Mask
pub const SCTLR_nTWI_Msk: u64 = 1 << SCTLR_nTWI_Pos;

/// SCTLR: V Position
pub const SCTLR_V_Pos: u32 = 13;
/// SCTLR: V Mask
pub const SCTLR_V_Msk: u64 = 1 << SCTLR_V_Pos;

/// SCTLR: I Position
pub const SCTLR_I_Pos: u32 = 12;
/// SCTLR: I Mask
pub const SCTLR_I_Msk: u64 = 1 << SCTLR_I_Pos;

/// SCTLR: SED Position
pub const SCTLR_SED_Pos: u32 = 8;
/// SCTLR: SED Mask
pub const SCTLR_SED_Msk: u64 = 1 << SCTLR_SED_Pos;

/// SCTLR: ITD Position
pub const SCTLR_ITD_Pos: u32 = 7;
/// SCTLR: ITD Mask
pub const SCTLR_ITD_Msk: u64 = 1 << SCTLR_ITD_Pos;

/// SCTLR: THEE Position
pub const SCTLR_THEE_Pos: u32 = 6;
/// SCTLR: THEE Mask
pub const SCTLR_THEE_Msk: u64 = 1 << SCTLR_THEE_Pos;

/// SCTLR: CP15BEN Position
pub const SCTLR_CP15BEN_Pos: u32 = 5;
/// SCTLR: CP15BEN Mask
pub const SCTLR_CP15BEN_Msk: u64 = 1 << SCTLR_CP15BEN_Pos;

/// SCTLR: C Position
pub const SCTLR_C_Pos: u32 = 2;
/// SCTLR: C Mask
pub const SCTLR_C_Msk: u64 = 1 << SCTLR_C_Pos;

/// SCTLR: A Position
pub const SCTLR_A_Pos: u32 = 1;
/// SCTLR: A Mask
pub const SCTLR_A_Msk: u64 = 1 << SCTLR_A_Pos;

/// SCTLR: M Position
pub const SCTLR_M_Pos: u32 = 0;
/// SCTLR: M Mask
pub const SCTLR_M_Msk: u64 = 1 << SCTLR_M_Pos;

/* Register MPIDR_EL1 */

pub const MPIDR_AFFLVL_MASK: u64 = 0xff;
pub const MPIDR_AFF0_SHIFT: u64 = 0;
pub const MPIDR_AFF1_SHIFT: u64 = 8;
pub const MPIDR_AFF2_SHIFT: u64 = 16;
pub const MPIDR_AFF3_SHIFT: u64 = 32;
pub const MPIDR_MT_MASK: u64 = 0x1;
pub const MPIDR_MT_SHIFT: u64 = 24;

/* ##########################  System Register Functions  ######################### */

/// Get MPIDR EL1
///
/// Returns Multiprocessor Affinity Register value.
#[inline(always)]
pub unsafe fn __get_MPIDR_EL1() -> u64 {
    let result: u64;
    asm!("mrs {}, mpidr_el1", out(reg) result);
    result
}

/// Get MAIR EL3
///
/// Returns MAIR value.
#[inline(always)]
pub unsafe fn __get_MAIR_EL3() -> u64 {
    let result: u64;
    asm!("mrs {}, mair_el3", out(reg) result);
    result
}

/// Set MAIR EL3
///
/// Writes the given value to MAIR EL3.
#[inline(always)]
pub unsafe fn __set_MAIR_EL3(mair: u64) {
    asm!("msr mair_el3, {}", in(reg) mair);
}

/// Get TCR EL3
///
/// Returns TCR value.
#[inline(always)]
pub unsafe fn __get_TCR_EL3() -> u64 {
    let result: u64;
    asm!("mrs {}, tcr_el3", out(reg) result);
    result
}

/// Set TCR EL3
///
/// Writes the given value to TCR EL3.
#[inline(always)]
pub unsafe fn __set_TCR_EL3(tcr: u64) {
    asm!("msr tcr_el3, {}", in(reg) tcr);
}

/// Get TTBR0 EL3
///
/// Returns Translation Table Base Register 0 value.
#[inline(always)]
pub unsafe fn __get_TTBR0_EL3() -> u64 {
    let result: u64;
    asm!("mrs {}, ttbr0_el3", out(reg) result);
    result
}

/// Set TTBR0 EL3
///
/// Writes the given value to Translation Table Base Register 0.
#[inline(always)]
pub unsafe fn __set_TTBR0_EL3(ttbr0: u64) {
    asm!("msr ttbr0_el3, {}", in(reg) ttbr0);
}

/// Get SCTLR EL3
///
/// Returns SCTLR EL3 value.
#[inline(always)]
pub unsafe fn __get_SCTLR_EL3() -> u64 {
    let result: u64;
    asm!("mrs {}, sctlr_el3", out(reg) result);
    result
}

/// Set SCTLR EL3
///
/// Writes the given value to SCTLR EL3.
#[inline(always)]
pub unsafe fn __set_SCTLR_EL3(sctlr: u64) {
    asm!("msr sctlr_el3, {}", in(reg) sctlr);
}

/// Set VBAR EL3
///
/// Writes the given value to VBAR EL3.
#[inline(always)]
pub unsafe fn __set_VBAR_EL3(vbar: u64) {
    asm!("msr vbar_el3, {}", in(reg) vbar);
}

/// Set VBAR EL2
///
/// Writes the given value to VBAR EL2.
#[inline(always)]
pub unsafe fn __set_VBAR_EL2(vbar: u64) {
    asm!("msr vbar_el2, {}", in(reg) vbar);
}

/// Set VBAR EL1
///
/// Writes the given value to VBAR EL1.
#[inline(always)]
pub unsafe fn __set_VBAR_EL1(vbar: u64) {
    asm!("msr vbar_el1, {}", in(reg) vbar);
}

/// Set ICC_IGRPEN0 EL1
///
/// Writes the given value to ICC_IGRPEN0 EL1.
#[inline(always)]
pub unsafe fn __set_ICC_IGRPEN0_EL1(igrpen0: u64) {
    asm!("msr icc_igrpen0_el1, {}", in(reg) igrpen0);
}

/// Set ICC_SGI1R EL1
///
/// Writes the given value to ICC_SGI1R EL1.
#[inline(always)]
pub unsafe fn __set_ICC_SGI1R_EL1(sgi1r: u64) {
    asm!("msr icc_sgi1r_el1, {}", in(reg) sgi1r);
}
