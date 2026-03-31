#![allow(non_snake_case)]
#![allow(asm_sub_register)]

use core::arch::asm;

/* Core Register CPSR */

/// CPSR: N Position
pub const CPSR_N_Pos: u32 = 31;
/// CPSR: N Mask
pub const CPSR_N_Msk: u32 = 1 << CPSR_N_Pos;

/// CPSR: Z Position
pub const CPSR_Z_Pos: u32 = 30;
/// CPSR: Z Mask
pub const CPSR_Z_Msk: u32 = 1 << CPSR_Z_Pos;

/// CPSR: C Position
pub const CPSR_C_Pos: u32 = 29;
/// CPSR: C Mask
pub const CPSR_C_Msk: u32 = 1 << CPSR_C_Pos;

/// CPSR: V Position
pub const CPSR_V_Pos: u32 = 28;
/// CPSR: V Mask
pub const CPSR_V_Msk: u32 = 1 << CPSR_V_Pos;

/// CPSR: Q Position
pub const CPSR_Q_Pos: u32 = 27;
/// CPSR: Q Mask
pub const CPSR_Q_Msk: u32 = 1 << CPSR_Q_Pos;

/// CPSR: IT0 Position
pub const CPSR_IT0_Pos: u32 = 25;
/// CPSR: IT0 Mask
pub const CPSR_IT0_Msk: u32 = 3 << CPSR_IT0_Pos;

/// CPSR: J Position
pub const CPSR_J_Pos: u32 = 24;
/// CPSR: J Mask
pub const CPSR_J_Msk: u32 = 1 << CPSR_J_Pos;

/// CPSR: GE Position
pub const CPSR_GE_Pos: u32 = 16;
/// CPSR: GE Mask
pub const CPSR_GE_Msk: u32 = 0xF << CPSR_GE_Pos;

/// CPSR: IT1 Position
pub const CPSR_IT1_Pos: u32 = 10;
/// CPSR: IT1 Mask
pub const CPSR_IT1_Msk: u32 = 0x3F << CPSR_IT1_Pos;

/// CPSR: E Position
pub const CPSR_E_Pos: u32 = 9;
/// CPSR: E Mask
pub const CPSR_E_Msk: u32 = 1 << CPSR_E_Pos;

/// CPSR: A Position
pub const CPSR_A_Pos: u32 = 8;
/// CPSR: A Mask
pub const CPSR_A_Msk: u32 = 1 << CPSR_A_Pos;

/// CPSR: I Position
pub const CPSR_I_Pos: u32 = 7;
/// CPSR: I Mask
pub const CPSR_I_Msk: u32 = 1 << CPSR_I_Pos;

/// CPSR: F Position
pub const CPSR_F_Pos: u32 = 6;
/// CPSR: F Mask
pub const CPSR_F_Msk: u32 = 1 << CPSR_F_Pos;

/// CPSR: T Position
pub const CPSR_T_Pos: u32 = 5;
/// CPSR: T Mask
pub const CPSR_T_Msk: u32 = 1 << CPSR_T_Pos;

/// CPSR: M Position
pub const CPSR_M_Pos: u32 = 0;
/// CPSR: M Mask
pub const CPSR_M_Msk: u32 = 0x1F << CPSR_M_Pos;

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

/* CP15 Register SCTLR */

/// SCTLR: TE Position
pub const SCTLR_TE_Pos: u32 = 30;
/// SCTLR: TE Mask
pub const SCTLR_TE_Msk: u32 = 1 << SCTLR_TE_Pos;

/// SCTLR: AFE Position
pub const SCTLR_AFE_Pos: u32 = 29;
/// SCTLR: AFE Mask
pub const SCTLR_AFE_Msk: u32 = 1 << SCTLR_AFE_Pos;

/// SCTLR: TRE Position
pub const SCTLR_TRE_Pos: u32 = 28;
/// SCTLR: TRE Mask
pub const SCTLR_TRE_Msk: u32 = 1 << SCTLR_TRE_Pos;

/// SCTLR: NMFI Position
pub const SCTLR_NMFI_Pos: u32 = 27;
/// SCTLR: NMFI Mask
pub const SCTLR_NMFI_Msk: u32 = 1 << SCTLR_NMFI_Pos;

/// SCTLR: EE Position
pub const SCTLR_EE_Pos: u32 = 25;
/// SCTLR: EE Mask
pub const SCTLR_EE_Msk: u32 = 1 << SCTLR_EE_Pos;

/// SCTLR: VE Position
pub const SCTLR_VE_Pos: u32 = 24;
/// SCTLR: VE Mask
pub const SCTLR_VE_Msk: u32 = 1 << SCTLR_VE_Pos;

/// SCTLR: U Position
pub const SCTLR_U_Pos: u32 = 22;
/// SCTLR: U Mask
pub const SCTLR_U_Msk: u32 = 1 << SCTLR_U_Pos;

/// SCTLR: FI Position
pub const SCTLR_FI_Pos: u32 = 21;
/// SCTLR: FI Mask
pub const SCTLR_FI_Msk: u32 = 1 << SCTLR_FI_Pos;

/// SCTLR: UWXN Position
pub const SCTLR_UWXN_Pos: u32 = 20;
/// SCTLR: UWXN Mask
pub const SCTLR_UWXN_Msk: u32 = 1 << SCTLR_UWXN_Pos;

/// SCTLR: WXN Position
pub const SCTLR_WXN_Pos: u32 = 19;
/// SCTLR: WXN Mask
pub const SCTLR_WXN_Msk: u32 = 1 << SCTLR_WXN_Pos;

/// SCTLR: HA Position
pub const SCTLR_HA_Pos: u32 = 17;
/// SCTLR: HA Mask
pub const SCTLR_HA_Msk: u32 = 1 << SCTLR_HA_Pos;

/// SCTLR: RR Position
pub const SCTLR_RR_Pos: u32 = 14;
/// SCTLR: RR Mask
pub const SCTLR_RR_Msk: u32 = 1 << SCTLR_RR_Pos;

/// SCTLR: V Position
pub const SCTLR_V_Pos: u32 = 13;
/// SCTLR: V Mask
pub const SCTLR_V_Msk: u32 = 1 << SCTLR_V_Pos;

/// SCTLR: I Position
pub const SCTLR_I_Pos: u32 = 12;
/// SCTLR: I Mask
pub const SCTLR_I_Msk: u32 = 1 << SCTLR_I_Pos;

/// SCTLR: Z Position
pub const SCTLR_Z_Pos: u32 = 11;
/// SCTLR: Z Mask
pub const SCTLR_Z_Msk: u32 = 1 << SCTLR_Z_Pos;

/// SCTLR: SW Position
pub const SCTLR_SW_Pos: u32 = 10;
/// SCTLR: SW Mask
pub const SCTLR_SW_Msk: u32 = 1 << SCTLR_SW_Pos;

/// SCTLR: B Position
pub const SCTLR_B_Pos: u32 = 7;
/// SCTLR: B Mask
pub const SCTLR_B_Msk: u32 = 1 << SCTLR_B_Pos;

/// SCTLR: CP15BEN Position
pub const SCTLR_CP15BEN_Pos: u32 = 5;
/// SCTLR: CP15BEN Mask
pub const SCTLR_CP15BEN_Msk: u32 = 1 << SCTLR_CP15BEN_Pos;

/// SCTLR: C Position
pub const SCTLR_C_Pos: u32 = 2;
/// SCTLR: C Mask
pub const SCTLR_C_Msk: u32 = 1 << SCTLR_C_Pos;

/// SCTLR: A Position
pub const SCTLR_A_Pos: u32 = 1;
/// SCTLR: A Mask
pub const SCTLR_A_Msk: u32 = 1 << SCTLR_A_Pos;

/// SCTLR: M Position
pub const SCTLR_M_Pos: u32 = 0;
/// SCTLR: M Mask
pub const SCTLR_M_Msk: u32 = 1 << SCTLR_M_Pos;

/* CP15 Register CPACR */

/// CPACR: ASEDIS Position
pub const CPACR_ASEDIS_Pos: u32 = 31;
/// CPACR: ASEDIS Mask
pub const CPACR_ASEDIS_Msk: u32 = 1 << CPACR_ASEDIS_Pos;

/// CPACR: D32DIS Position
pub const CPACR_D32DIS_Pos: u32 = 30;
/// CPACR: D32DIS Mask
pub const CPACR_D32DIS_Msk: u32 = 1 << CPACR_D32DIS_Pos;

/// CPACR: TRCDIS Position
pub const CPACR_TRCDIS_Pos: u32 = 28;
/// CPACR: TRCDIS Mask
pub const CPACR_TRCDIS_Msk: u32 = 1 << CPACR_TRCDIS_Pos;

/// CPACR CPn field: Access denied
pub const CPACR_CP_NA: u32 = 0;
/// CPACR CPn field: Accessible from PL1 only
pub const CPACR_CP_PL1: u32 = 1;
/// CPACR CPn field: Full access
pub const CPACR_CP_FA: u32 = 3;

/* DACR Register */

/// DACR Dn field: No access
pub const DACR_Dn_NOACCESS: u32 = 0;
/// DACR Dn field: Client
pub const DACR_Dn_CLIENT: u32 = 1;
/// DACR Dn field: Manager
pub const DACR_Dn_MANAGER: u32 = 3;

/* ##########################  CP15 Register Functions  ######################### */

/// Get ACTLR
///
/// Returns the Auxiliary Control register value.
#[inline(always)]
pub unsafe fn __get_ACTLR() -> u32 {
    let result: u32;
    asm!("mrc p15, 0, {}, c1, c0, 1", out(reg) result);
    result
}

/// Set ACTLR
///
/// Writes the given value to the Auxiliary Control register.
#[inline(always)]
pub unsafe fn __set_ACTLR(actlr: u32) {
    asm!("mcr p15, 0, {}, c1, c0, 1", in(reg) actlr);
}

/// Get CPACR
///
/// Returns the Coprocessor Access Control register value.
#[inline(always)]
pub unsafe fn __get_CPACR() -> u32 {
    let result: u32;
    asm!("mrc p15, 0, {}, c1, c0, 2", out(reg) result);
    result
}

/// Set CPACR
///
/// Writes the given value to the Coprocessor Access Control register.
#[inline(always)]
pub unsafe fn __set_CPACR(cpacr: u32) {
    asm!("mcr p15, 0, {}, c1, c0, 2", in(reg) cpacr);
}

/// Get DFSR
///
/// Returns the Data Fault Status Register value.
#[inline(always)]
pub unsafe fn __get_DFSR() -> u32 {
    let result: u32;
    asm!("mrc p15, 0, {}, c5, c0, 0", out(reg) result);
    result
}

/// Set DFSR
///
/// Writes the given value to the Data Fault Status register.
#[inline(always)]
pub unsafe fn __set_DFSR(dfsr: u32) {
    asm!("mcr p15, 0, {}, c5, c0, 0", in(reg) dfsr);
}

/// Get IFSR
///
/// Returns the Instruction Fault Status Register value.
#[inline(always)]
pub unsafe fn __get_IFSR() -> u32 {
    let result: u32;
    asm!("mrc p15, 0, {}, c5, c0, 1", out(reg) result);
    result
}

/// Set IFSR
///
/// Writes the given value to the Instruction Fault Status register.
#[inline(always)]
pub unsafe fn __set_IFSR(ifsr: u32) {
    asm!("mcr p15, 0, {}, c5, c0, 1", in(reg) ifsr);
}

/// Get ISR
///
/// Returns the Interrupt Status Register value.
#[inline(always)]
pub unsafe fn __get_ISR() -> u32 {
    let result: u32;
    asm!("mrc p15, 0, {}, c12, c1, 0", out(reg) result);
    result
}

/// Get CBAR
///
/// Returns the Configuration Base Address register value.
#[inline(always)]
pub unsafe fn __get_CBAR() -> u32 {
    let result: u32;
    asm!("mrc p15, 4, {}, c15, c0, 0", out(reg) result);
    result
}

/// Get TTBR0
///
/// Returns the Translation Table Base Register 0 value.
#[inline(always)]
pub unsafe fn __get_TTBR0() -> u32 {
    let result: u32;
    asm!("mrc p15, 0, {}, c2, c0, 0", out(reg) result);
    result
}

/// Set TTBR0
///
/// Writes the given value to the Translation Table Base Register 0.
#[inline(always)]
pub unsafe fn __set_TTBR0(ttbr0: u32) {
    asm!("mcr p15, 0, {}, c2, c0, 0", in(reg) ttbr0);
}

/// Get DACR
///
/// Returns the Domain Access Control Register value.
#[inline(always)]
pub unsafe fn __get_DACR() -> u32 {
    let result: u32;
    asm!("mrc p15, 0, {}, c3, c0, 0", out(reg) result);
    result
}

/// Set DACR
///
/// Writes the given value to the Domain Access Control Register.
#[inline(always)]
pub unsafe fn __set_DACR(dacr: u32) {
    asm!("mcr p15, 0, {}, c3, c0, 0", in(reg) dacr);
}

/// Set SCTLR
///
/// Writes the given value to the System Control Register.
#[inline(always)]
pub unsafe fn __set_SCTLR(sctlr: u32) {
    asm!("mcr p15, 0, {}, c1, c0, 0", in(reg) sctlr);
}

/// Get SCTLR
///
/// Returns the System Control Register value.
#[inline(always)]
pub unsafe fn __get_SCTLR() -> u32 {
    let result: u32;
    asm!("mrc p15, 0, {}, c1, c0, 0", out(reg) result);
    result
}

/// Get MPIDR
///
/// Returns the Multiprocessor Affinity Register value.
#[inline(always)]
pub unsafe fn __get_MPIDR() -> u32 {
    let result: u32;
    asm!("mrc p15, 0, {}, c0, c0, 5", out(reg) result);
    result
}

/// Get VBAR
///
/// Returns the Vector Base Address Register value.
#[inline(always)]
pub unsafe fn __get_VBAR() -> u32 {
    let result: u32;
    asm!("mrc p15, 0, {}, c12, c0, 0", out(reg) result);
    result
}

/// Set VBAR
///
/// Writes the given value to the Vector Base Address Register.
#[inline(always)]
pub unsafe fn __set_VBAR(vbar: u32) {
    asm!("mcr p15, 0, {}, c12, c0, 0", in(reg) vbar);
}

/// Get MVBAR
///
/// Returns the Monitor Vector Base Address Register value.
#[inline(always)]
pub unsafe fn __get_MVBAR() -> u32 {
    let result: u32;
    asm!("mrc p15, 0, {}, c12, c0, 1", out(reg) result);
    result
}

/// Set MVBAR
///
/// Writes the given value to the Monitor Vector Base Address Register.
#[inline(always)]
pub unsafe fn __set_MVBAR(mvbar: u32) {
    asm!("mcr p15, 0, {}, c12, c0, 1", in(reg) mvbar);
}

/// Set TLBIALL
///
/// TLB Invalidate All
#[inline(always)]
pub unsafe fn __set_TLBIALL(value: u32) {
    asm!("mcr p15, 0, {}, c8, c7, 0", in(reg) value);
}

/// Set BPIALL
///
/// Branch Predictor Invalidate All
#[inline(always)]
pub unsafe fn __set_BPIALL(value: u32) {
    asm!("mcr p15, 0, {}, c7, c5, 6", in(reg) value);
}

/// Set ICIALLU
///
/// Instruction Cache Invalidate All
#[inline(always)]
pub unsafe fn __set_ICIALLU(value: u32) {
    asm!("mcr p15, 0, {}, c7, c5, 0", in(reg) value);
}

/// Set ICIMVAC
///
/// Instruction Cache Invalidate
#[inline(always)]
pub unsafe fn __set_ICIMVAC(value: u32) {
    asm!("mcr p15, 0, {}, c7, c5, 1", in(reg) value);
}

/// Set DCCMVAC
///
/// Data cache clean
#[inline(always)]
pub unsafe fn __set_DCCMVAC(value: u32) {
    asm!("mcr p15, 0, {}, c7, c10, 1", in(reg) value);
}

/// Set DCIMVAC
///
/// Data cache invalidate
#[inline(always)]
pub unsafe fn __set_DCIMVAC(value: u32) {
    asm!("mcr p15, 0, {}, c7, c6, 1", in(reg) value);
}

/// Set DCCIMVAC
///
/// Data cache clean and invalidate
#[inline(always)]
pub unsafe fn __set_DCCIMVAC(value: u32) {
    asm!("mcr p15, 0, {}, c7, c14, 1", in(reg) value);
}

/// Set CSSELR
#[inline(always)]
pub unsafe fn __set_CSSELR(value: u32) {
    asm!("mcr p15, 2, {}, c0, c0, 0", in(reg) value);
}

/// Get CSSELR
///
/// Returns CSSELR Register value.
#[inline(always)]
pub unsafe fn __get_CSSELR() -> u32 {
    let result: u32;
    asm!("mrc p15, 2, {}, c0, c0, 0", out(reg) result);
    result
}

/// Get CCSIDR
///
/// Returns CCSIDR Register value.
#[inline(always)]
pub unsafe fn __get_CCSIDR() -> u32 {
    let result: u32;
    asm!("mrc p15, 1, {}, c0, c0, 0", out(reg) result);
    result
}

/// Get CLIDR
///
/// Returns CLIDR Register value.
#[inline(always)]
pub unsafe fn __get_CLIDR() -> u32 {
    let result: u32;
    asm!("mrc p15, 1, {}, c0, c0, 1", out(reg) result);
    result
}

/// Set DCISW
#[inline(always)]
pub unsafe fn __set_DCISW(value: u32) {
    asm!("mcr p15, 0, {}, c7, c6, 2", in(reg) value);
}

/// Set DCCSW
#[inline(always)]
pub unsafe fn __set_DCCSW(value: u32) {
    asm!("mcr p15, 0, {}, c7, c10, 2", in(reg) value);
}

/// Set DCCISW
#[inline(always)]
pub unsafe fn __set_DCCISW(value: u32) {
    asm!("mcr p15, 0, {}, c7, c14, 2", in(reg) value);
}
