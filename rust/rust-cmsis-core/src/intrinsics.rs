#![allow(non_snake_case)]
#![allow(asm_sub_register)]

use core::arch::asm;

/* ##########################  Core Instruction Access  ######################### */

/// No Operation
///
/// No Operation does nothing. This instruction can be used for code alignment purposes.
#[inline(always)]
pub fn __nop() {
    unsafe {
        asm!("nop", options(nostack, preserves_flags));
    }
}

/// Wait For Interrupt
///
/// Wait For Interrupt is a hint instruction that suspends execution until one of a number of events occurs.
#[inline(always)]
pub unsafe fn __wfi() {
    asm!("wfi", options(nostack, preserves_flags));
}

/// Wait For Event
///
/// Wait For Event is a hint instruction that permits the processor to enter
/// a low-power state until one of a number of events occurs.
#[inline(always)]
pub unsafe fn __wfe() {
    asm!("wfe", options(nostack, preserves_flags));
}

/// Send Event
///
/// Send Event is a hint instruction. It causes an event to be signaled to the CPU.
#[inline(always)]
pub unsafe fn __sev() {
    asm!("sev", options(nostack, preserves_flags));
}

/// Instruction Synchronization Barrier
///
/// Instruction Synchronization Barrier flushes the pipeline in the processor,
/// so that all instructions following the ISB are fetched from cache or memory,
/// after the instruction has been completed.
#[inline(always)]
pub unsafe fn __isb() {
    asm!("isb sy", options(nostack, preserves_flags));
}

/// Data Synchronization Barrier
///
/// Acts as a special kind of Data Memory Barrier.
/// It completes when all explicit memory accesses before this instruction complete.
#[inline(always)]
pub unsafe fn __dsb() {
    asm!("dsb sy", options(nostack, preserves_flags));
}

/// Data Memory Barrier
///
/// Ensures the apparent order of the explicit memory operations before
/// and after the instruction, without ensuring their completion.
#[inline(always)]
pub unsafe fn __dmb() {
    asm!("dmb sy", options(nostack, preserves_flags));
}

/// Reverse byte order (32 bit)
///
/// Reverses the byte order in unsigned integer value. For example, 0x12345678 becomes 0x78563412.
///
/// # Arguments
///
/// * `value` - Value to reverse
///
/// # Returns
///
/// Reversed value
#[inline(always)]
pub unsafe fn __rev(value: u32) -> u32 {
    let result: u32;
    asm!("rev {}, {}", out(reg) result, in(reg) value);
    result
}

/// Reverse byte order (16 bit)
///
/// Reverses the byte order within each halfword of a word. For example, 0x12345678 becomes 0x34127856.
///
/// # Arguments
///
/// * `value` - Value to reverse
///
/// # Returns
///
/// Reversed value
#[inline(always)]
pub unsafe fn __rev16(value: u32) -> u32 {
    let result: u32;
    asm!("rev16 {}, {}", out(reg) result, in(reg) value);
    result
}

/// Reverse byte order (16 bit)
///
/// Reverses the byte order in a 16-bit value and returns the signed 16-bit result. For example, 0x0080 becomes 0x8000.
///
/// # Arguments
///
/// * `value` - Value to reverse
///
/// # Returns
///
/// Reversed value
#[inline(always)]
pub unsafe fn __revsh(value: i32) -> i32 {
    let result: i32;
    asm!("revsh {}, {}", out(reg) result, in(reg) value);
    result
}

/// Rotate Right in unsigned value (32 bit)
///
/// Rotate Right (immediate) provides the value of the contents of a register rotated by a variable number of bits.
///
/// # Arguments
///
/// * `op1` - Value to rotate
/// * `op2` - Number of Bits to rotate
///
/// # Returns
///
/// Rotated value
#[inline(always)]
pub unsafe fn __ror(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("ror {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Reverse bit order of value
///
/// Reverses the bit order of the given value.
///
/// # Arguments
///
/// * `value` - Value to reverse
///
/// # Returns
///
/// Reversed value
#[inline(always)]
pub unsafe fn __rbit(value: u32) -> u32 {
    let result: u32;
    asm!("rbit {}, {}", out(reg) result, in(reg) value);
    result
}

/// Signed Saturate
///
/// Saturates a signed value.
///
/// # Arguments
///
/// * `value` - Value to be saturated
/// * `sat` - Bit position to saturate to (1..32)
///
/// # Returns
///
/// Saturated value
#[inline(always)]
pub unsafe fn __SSAT(value: i32, sat: u32) -> i32 {
    if (sat >= 1u32) && (sat <= 32u32) {
        let max = ((1u32 << (sat - 1u32)) - 1u32) as i32;
        let min = -1 - max;
        if value > max {
            return max;
        } else if value < min {
            return min;
        }
    }
    value
}

/// Unsigned Saturate
///
/// Saturates an unsigned value.
///
/// # Arguments
///
/// * `value` - Value to be saturated
/// * `sat` - Bit position to saturate to (0..31)
///
/// # Returns
///
/// Saturated value
#[inline(always)]
pub unsafe fn __USAT(value: i32, sat: u32) -> u32 {
    if sat <= 31u32 {
        let max = (1u32 << sat) - 1u32;
        if value > (max as i32) {
            return max;
        } else if value < 0 {
            return 0u32;
        }
    }
    value as u32
}

/// Remove the exclusive lock
///
/// Removes the exclusive lock which is created by LDREX.
#[inline(always)]
pub unsafe fn __CLREX() {
    asm!("clrex", options(nostack, preserves_flags));
}

/// LDR Exclusive (8 bit)
///
/// Executes a exclusive LDR instruction for 8 bit value.
///
/// # Arguments
///
/// * `ptr` - Pointer to data
///
/// # Returns
///
/// value of type uint8_t at (*ptr)
#[inline(always)]
pub unsafe fn __LDREXB(ptr: *const u8) -> u8 {
    let result: u32;
    asm!("ldrexb {}, [{}]", out(reg) result, in(reg) ptr);
    result as u8
}

/// STR Exclusive (8 bit)
///
/// Executes a exclusive STR instruction for 8 bit values.
///
/// # Arguments
///
/// * `value` - Value to store
/// * `ptr` - Pointer to location
///
/// # Returns
///
/// 0 - Function succeeded
/// 1 - Function failed
#[inline(always)]
pub unsafe fn __STREXB(value: u8, ptr: *mut u8) -> u32 {
    let result: u32;
    asm!("strexb {}, {}, [{}]", out(reg) result, in(reg) value as u32, in(reg) ptr);
    result
}

/// LDR Exclusive (16 bit)
///
/// Executes a exclusive LDR instruction for 16 bit values.
///
/// # Arguments
///
/// * `ptr` - Pointer to data
///
/// # Returns
///
/// value of type uint16_t at (*ptr)
#[inline(always)]
pub unsafe fn __LDREXH(ptr: *const u16) -> u16 {
    let result: u16;
    asm!("ldrexh {}, [{}]", out(reg) result, in(reg) ptr);
    result
}

/// STR Exclusive (16 bit)
///
/// Executes a exclusive STR instruction for 16 bit values.
///
/// # Arguments
///
/// * `value` - Value to store
/// * `ptr` - Pointer to location
///
/// # Returns
///
/// 0 - Function succeeded
/// 1 - Function failed
#[inline(always)]
pub unsafe fn __STREXH(value: u16, ptr: *mut u16) -> u32 {
    let result: u32;
    asm!("strexh {}, {}, [{}]", out(reg) result, in(reg) value, in(reg) ptr);
    result
}

/// LDR Exclusive (32 bit)
///
/// Executes a exclusive LDR instruction for 32 bit values.
///
/// # Arguments
///
/// * `ptr` - Pointer to data
///
/// # Returns
///
/// value of type uint32_t at (*ptr)
#[inline(always)]
pub unsafe fn __LDREXW(ptr: *const u32) -> u32 {
    let result: u32;
    asm!("ldrex {}, [{}]", out(reg) result, in(reg) ptr);
    result
}

/// STR Exclusive (32 bit)
///
/// Executes a exclusive STR instruction for 32 bit values.
///
/// # Arguments
///
/// * `value` - Value to store
/// * `ptr` - Pointer to location
///
/// # Returns
///
/// 0 - Function succeeded
/// 1 - Function failed
#[inline(always)]
pub unsafe fn __STREXW(value: u32, ptr: *mut u32) -> u32 {
    let result: u32;
    asm!("strex {}, {}, [{}]", out(reg) result, in(reg) value, in(reg) ptr);
    result
}

/// Rotate Right with Extend (32 bit)
///
/// Moves each bit of a bitstring right by one bit.
/// The carry input is shifted in at the left end of the bitstring.
///
/// # Arguments
///
/// * `value` - Value to rotate
///
/// # Returns
///
/// Rotated value
#[inline(always)]
pub unsafe fn __RRX(value: u32) -> u32 {
    let result: u32;
    asm!("rrx {}, {}", out(reg) result, in(reg) value);
    result
}

/// Count leading zeros
///
/// Counts the number of leading zeros of a data value.
///
/// # Arguments
///
/// * `value` - Value to count the leading zeros
///
/// # Returns
///
/// number of leading zeros in value
#[inline(always)]
pub unsafe fn __clz(value: u32) -> u32 {
    let result: u32;
    asm!("clz {}, {}", out(reg) result, in(reg) value);
    result
}

/// Breakpoint
///
/// Causes the processor to enter Debug state.
/// Debug tools can use this to investigate system state when the instruction at a particular address is reached.
///
/// # Arguments
///
/// * `imm` - is ignored by the processor.
///          If required, a debugger can use it to store additional information about the breakpoint.
#[inline(always)]
pub unsafe fn __bkpt(imm: u8) {
    match imm {
        0 => asm!("bkpt #0", options(nostack, preserves_flags)),
        1 => asm!("bkpt #1", options(nostack, preserves_flags)),
        2 => asm!("bkpt #2", options(nostack, preserves_flags)),
        3 => asm!("bkpt #3", options(nostack, preserves_flags)),
        4 => asm!("bkpt #4", options(nostack, preserves_flags)),
        5 => asm!("bkpt #5", options(nostack, preserves_flags)),
        6 => asm!("bkpt #6", options(nostack, preserves_flags)),
        7 => asm!("bkpt #7", options(nostack, preserves_flags)),
        8 => asm!("bkpt #8", options(nostack, preserves_flags)),
        9 => asm!("bkpt #9", options(nostack, preserves_flags)),
        10 => asm!("bkpt #10", options(nostack, preserves_flags)),
        11 => asm!("bkpt #11", options(nostack, preserves_flags)),
        12 => asm!("bkpt #12", options(nostack, preserves_flags)),
        13 => asm!("bkpt #13", options(nostack, preserves_flags)),
        14 => asm!("bkpt #14", options(nostack, preserves_flags)),
        15 => asm!("bkpt #15", options(nostack, preserves_flags)),
        _ => asm!("bkpt #0", options(nostack, preserves_flags)),
    }
}

/// STRT Unprivileged (8 bit)
///
/// Executes a Unprivileged STRT instruction for 8 bit values.
///
/// # Arguments
///
/// * `value` - Value to store
/// * `ptr` - Pointer to location
#[inline(always)]
pub unsafe fn __STRBT(value: u8, ptr: *mut u8) {
    asm!("strbt {}, [{1}]", in(reg) value as u32, in(reg) ptr);
}

/// STRT Unprivileged (16 bit)
///
/// Executes a Unprivileged STRT instruction for 16 bit values.
///
/// # Arguments
///
/// * `value` - Value to store
/// * `ptr` - Pointer to location
#[inline(always)]
pub unsafe fn __STRHT(value: u16, ptr: *mut u16) {
    asm!("strht {}, [{1}]", in(reg) value as u32, in(reg) ptr);
}

/// STRT Unprivileged (32 bit)
///
/// Executes a Unprivileged STRT instruction for 32 bit values.
///
/// # Arguments
///
/// * `value` - Value to store
/// * `ptr` - Pointer to location
#[inline(always)]
pub unsafe fn __STRT(value: u32, ptr: *mut u32) {
    asm!("strt {}, [{1}]", in(reg) value, in(reg) ptr);
}

/// LDRT Unprivileged (8 bit)
///
/// Executes a Unprivileged LDRT instruction for 8 bit value.
///
/// # Arguments
///
/// * `ptr` - Pointer to data
///
/// # Returns
///
/// value of type uint8_t at (*ptr)
#[inline(always)]
pub unsafe fn __LDRBT(ptr: *const u8) -> u8 {
    let result: u32;
    asm!("ldrbt {}, [{}]", out(reg) result, in(reg) ptr);
    result as u8
}

/// LDRT Unprivileged (16 bit)
///
/// Executes a Unprivileged LDRT instruction for 16 bit values.
///
/// # Arguments
///
/// * `ptr` - Pointer to data
///
/// # Returns
///
/// value of type uint16_t at (*ptr)
#[inline(always)]
pub unsafe fn __LDRHT(ptr: *const u16) -> u16 {
    let result: u32;
    asm!("ldrht {}, [{}]", out(reg) result, in(reg) ptr);
    result as u16
}

/// LDRT Unprivileged (32 bit)
///
/// Executes a Unprivileged LDRT instruction for 32 bit values.
///
/// # Arguments
///
/// * `ptr` - Pointer to data
///
/// # Returns
///
/// value of type uint32_t at (*ptr)
#[inline(always)]
pub unsafe fn __LDRT(ptr: *const u32) -> u32 {
    let result: u32;
    asm!("ldrt {}, [{}]", out(reg) result, in(reg) ptr);
    result
}

/// Load-Acquire (8 bit)
///
/// Executes a LDAB instruction for 8 bit value.
///
/// # Arguments
///
/// * `ptr` - Pointer to data
///
/// # Returns
///
/// value of type uint8_t at (*ptr)
#[inline(always)]
pub unsafe fn __LDAB(ptr: *const u8) -> u8 {
    let result: u32;
    asm!("ldab {}, [{}]", out(reg) result, in(reg) ptr);
    result as u8
}

/// Load-Acquire (16 bit)
///
/// Executes a LDAH instruction for 16 bit values.
///
/// # Arguments
///
/// * `ptr` - Pointer to data
///
/// # Returns
///
/// value of type uint16_t at (*ptr)
#[inline(always)]
pub unsafe fn __LDAH(ptr: *const u16) -> u16 {
    let result: u32;
    asm!("ldah {}, [{}]", out(reg) result, in(reg) ptr);
    result as u16
}

/// Load-Acquire (32 bit)
///
/// Executes a LDA instruction for 32 bit values.
///
/// # Arguments
///
/// * `ptr` - Pointer to data
///
/// # Returns
///
/// value of type uint32_t at (*ptr)
#[inline(always)]
pub unsafe fn __LDA(ptr: *const u32) -> u32 {
    let result: u32;
    asm!("lda {}, [{}]", out(reg) result, in(reg) ptr);
    result
}

/// Store-Release (8 bit)
///
/// Executes a STLB instruction for 8 bit values.
///
/// # Arguments
///
/// * `value` - Value to store
/// * `ptr` - Pointer to location
#[inline(always)]
pub unsafe fn __STLB(value: u8, ptr: *mut u8) {
    asm!("stlb {}, [{}]", in(reg) value as u32, in(reg) ptr);
}

/// Store-Release (16 bit)
///
/// Executes a STLH instruction for 16 bit values.
///
/// # Arguments
///
/// * `value` - Value to store
/// * `ptr` - Pointer to location
#[inline(always)]
pub unsafe fn __STLH(value: u16, ptr: *mut u16) {
    asm!("stlh {}, [{}]", in(reg) value as u32, in(reg) ptr);
}

/// Store-Release (32 bit)
///
/// Executes a STL instruction for 32 bit values.
///
/// # Arguments
///
/// * `value` - Value to store
/// * `ptr` - Pointer to location
#[inline(always)]
pub unsafe fn __STL(value: u32, ptr: *mut u32) {
    asm!("stl {}, [{}]", in(reg) value, in(reg) ptr);
}

/// Load-Acquire Exclusive (8 bit)
///
/// Executes a LDAB exclusive instruction for 8 bit value.
///
/// # Arguments
///
/// * `ptr` - Pointer to data
///
/// # Returns
///
/// value of type uint8_t at (*ptr)
#[inline(always)]
pub unsafe fn __LDAEXB(ptr: *const u8) -> u8 {
    let result: u32;
    asm!("ldaexb {}, [{}]", out(reg) result, in(reg) ptr);
    result as u8
}

/// Load-Acquire Exclusive (16 bit)
///
/// Executes a LDAH exclusive instruction for 16 bit values.
///
/// # Arguments
///
/// * `ptr` - Pointer to data
///
/// # Returns
///
/// value of type uint16_t at (*ptr)
#[inline(always)]
pub unsafe fn __LDAEXH(ptr: *const u16) -> u16 {
    let result: u16;
    asm!("ldaexh {}, [{}]", out(reg) result, in(reg) ptr);
    result
}

/// Load-Acquire Exclusive (32 bit)
///
/// Executes a LDA exclusive instruction for 32 bit values.
///
/// # Arguments
///
/// * `ptr` - Pointer to data
///
/// # Returns
///
/// value of type uint32_t at (*ptr)
#[inline(always)]
pub unsafe fn __LDAEX(ptr: *const u32) -> u32 {
    let result: u32;
    asm!("ldaex {}, [{}]", out(reg) result, in(reg) ptr);
    result
}

/// Store-Release Exclusive (8 bit)
///
/// Executes a STLB exclusive instruction for 8 bit values.
///
/// # Arguments
///
/// * `value` - Value to store
/// * `ptr` - Pointer to location
///
/// # Returns
///
/// 0 - Function succeeded
/// 1 - Function failed
#[inline(always)]
pub unsafe fn __STLEXB(value: u8, ptr: *mut u8) -> u32 {
    let result: u32;
    asm!("stlexb {}, {}, [{}]", out(reg) result, in(reg) value as u32, in(reg) ptr);
    result
}

/// Store-Release Exclusive (16 bit)
///
/// Executes a STLH exclusive instruction for 16 bit values.
///
/// # Arguments
///
/// * `value` - Value to store
/// * `ptr` - Pointer to location
///
/// # Returns
///
/// 0 - Function succeeded
/// 1 - Function failed
#[inline(always)]
pub unsafe fn __STLEXH(value: u16, ptr: *mut u16) -> u32 {
    let result: u32;
    asm!("stlexh {}, {}, [{}]", out(reg) result, in(reg) value, in(reg) ptr);
    result
}

/// Store-Release Exclusive (32 bit)
///
/// Executes a STL exclusive instruction for 32 bit values.
///
/// # Arguments
///
/// * `value` - Value to store
/// * `ptr` - Pointer to location
///
/// # Returns
///
/// 0 - Function succeeded
/// 1 - Function failed
#[inline(always)]
pub unsafe fn __STLEX(value: u32, ptr: *mut u32) -> u32 {
    let result: u32;
    asm!("stlex {}, {}, [{}]", out(reg) result, in(reg) value, in(reg) ptr);
    result
}

/* ###########################  Core Function Access  ########################### */

/// Get Control Register
///
/// Returns the content of the Control Register.
///
/// # Returns
///
/// Control Register value
#[inline(always)]
pub unsafe fn __get_CONTROL() -> u32 {
    let result: u32;
    asm!("MRS {}, control", out(reg) result);
    result
}

/// Get Control Register (non-secure)
///
/// Returns the content of the non-secure Control Register when in secure mode.
///
/// # Returns
///
/// non-secure Control Register value
#[inline(always)]
pub unsafe fn __TZ_get_CONTROL_NS() -> u32 {
    let result: u32;
    asm!("MRS {}, control_ns", out(reg) result);
    result
}

/// Set Control Register
///
/// Writes the given value to the Control Register.
///
/// # Arguments
///
/// * `control` - Control Register value to set
#[inline(always)]
pub unsafe fn __set_CONTROL(control: u32) {
    asm!("MSR control, {}", in(reg) control);
    __isb();
}

/// Set Control Register (non-secure)
///
/// Writes the given value to the non-secure Control Register when in secure state.
///
/// # Arguments
///
/// * `control` - Control Register value to set
#[inline(always)]
pub unsafe fn __TZ_set_CONTROL_NS(control: u32) {
    asm!("MSR control_ns, {}", in(reg) control);
    __isb();
}

/// Get IPSR Register
///
/// Returns the content of the IPSR Register.
///
/// # Returns
///
/// IPSR Register value
#[inline(always)]
pub unsafe fn __get_IPSR() -> u32 {
    let result: u32;
    asm!("MRS {}, ipsr", out(reg) result);
    result
}

/// Get APSR Register
///
/// Returns the content of the APSR Register.
///
/// # Returns
///
/// APSR Register value
#[inline(always)]
pub unsafe fn __get_APSR() -> u32 {
    let result: u32;
    asm!("MRS {}, apsr", out(reg) result);
    result
}

/// Get xPSR Register
///
/// Returns the content of the xPSR Register.
///
/// # Returns
///
/// xPSR Register value
#[inline(always)]
pub unsafe fn __get_xPSR() -> u32 {
    let result: u32;
    asm!("MRS {}, xpsr", out(reg) result);
    result
}

/// Get Process Stack Pointer
///
/// Returns the current value of the Process Stack Pointer (PSP).
///
/// # Returns
///
/// PSP Register value
#[inline(always)]
pub unsafe fn __get_PSP() -> u32 {
    let result: u32;
    asm!("MRS {}, psp", out(reg) result);
    result
}

/// Get Process Stack Pointer (non-secure)
///
/// Returns the current value of the non-secure Process Stack Pointer (PSP) when in secure state.
///
/// # Returns
///
/// PSP Register value
#[inline(always)]
pub unsafe fn __TZ_get_PSP_NS() -> u32 {
    let result: u32;
    asm!("MRS {}, psp_ns", out(reg) result);
    result
}

/// Set Process Stack Pointer
///
/// Assigns the given value to the Process Stack Pointer (PSP).
///
/// # Arguments
///
/// * `topOfProcStack` - Process Stack Pointer value to set
#[inline(always)]
pub unsafe fn __set_PSP(topOfProcStack: u32) {
    asm!("MSR psp, {}", in(reg) topOfProcStack);
}

/// Set Process Stack Pointer (non-secure)
///
/// Assigns the given value to the non-secure Process Stack Pointer (PSP) when in secure state.
///
/// # Arguments
///
/// * `topOfProcStack` - Process Stack Pointer value to set
#[inline(always)]
pub unsafe fn __TZ_set_PSP_NS(topOfProcStack: u32) {
    asm!("MSR psp_ns, {}", in(reg) topOfProcStack);
}

/// Get Main Stack Pointer
///
/// Returns the current value of the Main Stack Pointer (MSP).
///
/// # Returns
///
/// MSP Register value
#[inline(always)]
pub unsafe fn __get_MSP() -> u32 {
    let result: u32;
    asm!("MRS {}, msp", out(reg) result);
    result
}

/// Get Main Stack Pointer (non-secure)
///
/// Returns the current value of the non-secure Main Stack Pointer (MSP) when in secure state.
///
/// # Returns
///
/// MSP Register value
#[inline(always)]
pub unsafe fn __TZ_get_MSP_NS() -> u32 {
    let result: u32;
    asm!("MRS {}, msp_ns", out(reg) result);
    result
}

/// Set Main Stack Pointer
///
/// Assigns the given value to the Main Stack Pointer (MSP).
///
/// # Arguments
///
/// * `topOfMainStack` - Main Stack Pointer value to set
#[inline(always)]
pub unsafe fn __set_MSP(topOfMainStack: u32) {
    asm!("MSR msp, {}", in(reg) topOfMainStack);
}

/// Set Main Stack Pointer (non-secure)
///
/// Assigns the given value to the non-secure Main Stack Pointer (MSP) when in secure state.
///
/// # Arguments
///
/// * `topOfMainStack` - Main Stack Pointer value to set
#[inline(always)]
pub unsafe fn __TZ_set_MSP_NS(topOfMainStack: u32) {
    asm!("MSR msp_ns, {}", in(reg) topOfMainStack);
}

/// Get Stack Pointer (non-secure)
///
/// Returns the current value of the non-secure Stack Pointer (SP) when in secure state.
///
/// # Returns
///
/// SP Register value
#[inline(always)]
pub unsafe fn __TZ_get_SP_NS() -> u32 {
    let result: u32;
    asm!("MRS {}, sp_ns", out(reg) result);
    result
}

/// Set Stack Pointer (non-secure)
///
/// Assigns the given value to the non-secure Stack Pointer (SP) when in secure state.
///
/// # Arguments
///
/// * `topOfStack` - Stack Pointer value to set
#[inline(always)]
pub unsafe fn __TZ_set_SP_NS(topOfStack: u32) {
    asm!("MSR sp_ns, {}", in(reg) topOfStack);
}

/// Get Priority Mask
///
/// Returns the current state of the priority mask bit from the Priority Mask Register.
///
/// # Returns
///
/// Priority Mask value
#[inline(always)]
pub unsafe fn __get_PRIMASK() -> u32 {
    let result: u32;
    asm!("MRS {}, primask", out(reg) result);
    result
}

/// Get Priority Mask (non-secure)
///
/// Returns the current state of the non-secure priority mask bit from the Priority Mask Register when in secure state.
///
/// # Returns
///
/// Priority Mask value
#[inline(always)]
pub unsafe fn __TZ_get_PRIMASK_NS() -> u32 {
    let result: u32;
    asm!("MRS {}, primask_ns", out(reg) result);
    result
}

/// Set Priority Mask
///
/// Assigns the given value to the Priority Mask Register.
///
/// # Arguments
///
/// * `priMask` - Priority Mask
#[inline(always)]
pub unsafe fn __set_PRIMASK(priMask: u32) {
    asm!("MSR primask, {}", in(reg) priMask);
}

/// Set Priority Mask (non-secure)
///
/// Assigns the given value to the non-secure Priority Mask Register when in secure state.
///
/// # Arguments
///
/// * `priMask` - Priority Mask
#[inline(always)]
pub unsafe fn __TZ_set_PRIMASK_NS(priMask: u32) {
    asm!("MSR primask_ns, {}", in(reg) priMask);
}

/// Enable IRQ Interrupts
///
/// Enables IRQ interrupts by clearing special-purpose register PRIMASK.
/// Can only be executed in Privileged modes.
#[inline(always)]
pub unsafe fn __enable_irq() {
    asm!("cpsie i", options(nostack, preserves_flags));
}

/// Disable IRQ Interrupts
///
/// Disables IRQ interrupts by setting special-purpose register PRIMASK.
/// Can only be executed in Privileged modes.
#[inline(always)]
pub unsafe fn __disable_irq() {
    asm!("cpsid i", options(nostack, preserves_flags));
}

/// Get Base Priority
///
/// Returns the current value of the Base Priority register.
///
/// # Returns
///
/// Base Priority register value
#[inline(always)]
pub unsafe fn __get_BASEPRI() -> u32 {
    let result: u32;
    asm!("MRS {}, basepri", out(reg) result);
    result
}

/// Get Base Priority (non-secure)
///
/// Returns the current value of the non-secure Base Priority register when in secure state.
///
/// # Returns
///
/// Base Priority register value
#[inline(always)]
pub unsafe fn __TZ_get_BASEPRI_NS() -> u32 {
    let result: u32;
    asm!("MRS {}, basepri_ns", out(reg) result);
    result
}

/// Set Base Priority
///
/// Assigns the given value to the Base Priority register.
///
/// # Arguments
///
/// * `basePri` - Base Priority value to set
#[inline(always)]
pub unsafe fn __set_BASEPRI(basePri: u32) {
    asm!("MSR basepri, {}", in(reg) basePri);
}

/// Set Base Priority (non-secure)
///
/// Assigns the given value to the non-secure Base Priority register when in secure state.
///
/// # Arguments
///
/// * `basePri` - Base Priority value to set
#[inline(always)]
pub unsafe fn __TZ_set_BASEPRI_NS(basePri: u32) {
    asm!("MSR basepri_ns, {}", in(reg) basePri);
}

/// Set Base Priority with condition
///
/// Assigns the given value to the Base Priority register only if BASEPRI masking is disabled,
/// or the new value increases the BASEPRI priority level.
///
/// # Arguments
///
/// * `basePri` - Base Priority value to set
#[inline(always)]
pub unsafe fn __set_BASEPRI_MAX(basePri: u32) {
    asm!("MSR basepri_max, {}", in(reg) basePri);
}

/// Get Fault Mask
///
/// Returns the current value of the Fault Mask register.
///
/// # Returns
///
/// Fault Mask register value
#[inline(always)]
pub unsafe fn __get_FAULTMASK() -> u32 {
    let result: u32;
    asm!("MRS {}, faultmask", out(reg) result);
    result
}

/// Get Fault Mask (non-secure)
///
/// Returns the current value of the non-secure Fault Mask register when in secure state.
///
/// # Returns
///
/// Fault Mask register value
#[inline(always)]
pub unsafe fn __TZ_get_FAULTMASK_NS() -> u32 {
    let result: u32;
    asm!("MRS {}, faultmask_ns", out(reg) result);
    result
}

/// Set Fault Mask
///
/// Assigns the given value to the Fault Mask register.
///
/// # Arguments
///
/// * `faultMask` - Fault Mask value to set
#[inline(always)]
pub unsafe fn __set_FAULTMASK(faultMask: u32) {
    asm!("MSR faultmask, {}", in(reg) faultMask);
}

/// Set Fault Mask (non-secure)
///
/// Assigns the given value to the non-secure Fault Mask register when in secure state.
///
/// # Arguments
///
/// * `faultMask` - Fault Mask value to set
#[inline(always)]
pub unsafe fn __TZ_set_FAULTMASK_NS(faultMask: u32) {
    asm!("MSR faultmask_ns, {}", in(reg) faultMask);
}

/// Enable FIQ
///
/// Enables FIQ interrupts by clearing special-purpose register FAULTMASK.
/// Can only be executed in Privileged modes.
#[inline(always)]
pub unsafe fn __enable_fault_irq() {
    asm!("cpsie f", options(nostack, preserves_flags));
}

/// Disable FIQ
///
/// Disables FIQ interrupts by setting special-purpose register FAULTMASK.
/// Can only be executed in Privileged modes.
#[inline(always)]
pub unsafe fn __disable_fault_irq() {
    asm!("cpsid f", options(nostack, preserves_flags));
}

/// Get Process Stack Pointer Limit
///
/// Returns the current value of the Process Stack Pointer Limit (PSPLIM).
///
/// # Returns
///
/// PSPLIM Register value
#[inline(always)]
pub unsafe fn __get_PSPLIM() -> u32 {
    let result: u32;
    asm!("MRS {}, psplim", out(reg) result);
    result
}

/// Get Process Stack Pointer Limit (non-secure)
///
/// Returns the current value of the non-secure Process Stack Pointer Limit (PSPLIM) when in secure state.
///
/// # Returns
///
/// PSPLIM Register value
#[inline(always)]
pub unsafe fn __TZ_get_PSPLIM_NS() -> u32 {
    let result: u32;
    asm!("MRS {}, psplim_ns", out(reg) result);
    result
}

/// Set Process Stack Pointer Limit
///
/// Assigns the given value to the Process Stack Pointer Limit (PSPLIM).
///
/// # Arguments
///
/// * `ProcStackPtrLimit` - Process Stack Pointer Limit value to set
#[inline(always)]
pub unsafe fn __set_PSPLIM(ProcStackPtrLimit: u32) {
    asm!("MSR psplim, {}", in(reg) ProcStackPtrLimit);
}

/// Set Process Stack Pointer Limit (non-secure)
///
/// Assigns the given value to the non-secure Process Stack Pointer Limit (PSPLIM) when in secure state.
///
/// # Arguments
///
/// * `ProcStackPtrLimit` - Process Stack Pointer Limit value to set
#[inline(always)]
pub unsafe fn __TZ_set_PSPLIM_NS(ProcStackPtrLimit: u32) {
    asm!("MSR psplim_ns, {}", in(reg) ProcStackPtrLimit);
}

/// Get Main Stack Pointer Limit
///
/// Returns the current value of the Main Stack Pointer Limit (MSPLIM).
///
/// # Returns
///
/// MSPLIM Register value
#[inline(always)]
pub unsafe fn __get_MSPLIM() -> u32 {
    let result: u32;
    asm!("MRS {}, msplim", out(reg) result);
    result
}

/// Get Main Stack Pointer Limit (non-secure)
///
/// Returns the current value of the non-secure Main Stack Pointer Limit(MSPLIM) when in secure state.
///
/// # Returns
///
/// MSPLIM Register value
#[inline(always)]
pub unsafe fn __TZ_get_MSPLIM_NS() -> u32 {
    let result: u32;
    asm!("MRS {}, msplim_ns", out(reg) result);
    result
}

/// Set Main Stack Pointer Limit
///
/// Assigns the given value to the Main Stack Pointer Limit (MSPLIM).
///
/// # Arguments
///
/// * `MainStackPtrLimit` - Main Stack Pointer Limit value to set
#[inline(always)]
pub unsafe fn __set_MSPLIM(MainStackPtrLimit: u32) {
    asm!("MSR msplim, {}", in(reg) MainStackPtrLimit);
}

/// Set Main Stack Pointer Limit (non-secure)
///
/// Assigns the given value to the non-secure Main Stack Pointer Limit (MSPLIM) when in secure state.
///
/// # Arguments
///
/// * `MainStackPtrLimit` - Main Stack Pointer value to set
#[inline(always)]
pub unsafe fn __TZ_set_MSPLIM_NS(MainStackPtrLimit: u32) {
    asm!("MSR msplim_ns, {}", in(reg) MainStackPtrLimit);
}

/// Get FPSCR
///
/// Returns the current value of the Floating Point Status/Control register.
///
/// # Returns
///
/// Floating Point Status/Control register value
#[inline(always)]
pub unsafe fn __get_FPSCR() -> u32 {
    let result: u32;
    asm!("MRS {}, fpscr", out(reg) result);
    result
}

/// Set FPSCR
///
/// Assigns the given value to the Floating Point Status/Control register.
///
/// # Arguments
///
/// * `fpscr` - Floating Point Status/Control value to set
#[inline(always)]
pub unsafe fn __set_FPSCR(fpscr: u32) {
    asm!("MSR fpscr, {}", in(reg) fpscr);
}

/* ###################  Compiler specific Intrinsics  ########################### */

/// Signed Add 8
#[inline(always)]
pub unsafe fn __SADD8(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("sadd8 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Q-Add 8
#[inline(always)]
pub unsafe fn __QADD8(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("qadd8 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Signed Halving Add 8
#[inline(always)]
pub unsafe fn __SHADD8(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("shadd8 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Add 8
#[inline(always)]
pub unsafe fn __UADD8(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("uadd8 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Q-Add 8
#[inline(always)]
pub unsafe fn __UQADD8(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("uqadd8 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Halving Add 8
#[inline(always)]
pub unsafe fn __UHADD8(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("uhadd8 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Signed Sub 8
#[inline(always)]
pub unsafe fn __SSUB8(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("ssub8 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Q-Sub 8
#[inline(always)]
pub unsafe fn __QSUB8(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("qsub8 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Signed Halving Sub 8
#[inline(always)]
pub unsafe fn __SHSUB8(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("shsub8 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Sub 8
#[inline(always)]
pub unsafe fn __USUB8(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("usub8 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Q-Sub 8
#[inline(always)]
pub unsafe fn __UQSUB8(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("uqsub8 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Halving Sub 8
#[inline(always)]
pub unsafe fn __UHSUB8(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("uhsub8 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Signed Add 16
#[inline(always)]
pub unsafe fn __SADD16(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("sadd16 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Q-Add 16
#[inline(always)]
pub unsafe fn __QADD16(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("qadd16 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Signed Halving Add 16
#[inline(always)]
pub unsafe fn __SHADD16(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("shadd16 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Add 16
#[inline(always)]
pub unsafe fn __UADD16(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("uadd16 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Q-Add 16
#[inline(always)]
pub unsafe fn __UQADD16(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("uqadd16 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Halving Add 16
#[inline(always)]
pub unsafe fn __UHADD16(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("uhadd16 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Signed Sub 16
#[inline(always)]
pub unsafe fn __SSUB16(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("ssub16 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Q-Sub 16
#[inline(always)]
pub unsafe fn __QSUB16(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("qsub16 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Signed Halving Sub 16
#[inline(always)]
pub unsafe fn __SHSUB16(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("shsub16 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Sub 16
#[inline(always)]
pub unsafe fn __USUB16(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("usub16 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Q-Sub 16
#[inline(always)]
pub unsafe fn __UQSUB16(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("uqsub16 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Halving Sub 16
#[inline(always)]
pub unsafe fn __UHSUB16(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("uhsub16 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Signed Add and Subtract with Exchange
#[inline(always)]
pub unsafe fn __SASX(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("sasx {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Q-Add and Subtract with Exchange
#[inline(always)]
pub unsafe fn __QASX(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("qasx {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Signed Halving Add and Subtract with Exchange
#[inline(always)]
pub unsafe fn __SHASX(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("shasx {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Add and Subtract with Exchange
#[inline(always)]
pub unsafe fn __UASX(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("uasx {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Q-Add and Subtract with Exchange
#[inline(always)]
pub unsafe fn __UQASX(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("uqasx {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Halving Add and Subtract with Exchange
#[inline(always)]
pub unsafe fn __UHASX(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("uhasx {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Signed Subtract and Add with Exchange
#[inline(always)]
pub unsafe fn __SSAX(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("ssax {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Q-Subtract and Add with Exchange
#[inline(always)]
pub unsafe fn __QSAX(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("qsax {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Signed Halving Subtract and Add with Exchange
#[inline(always)]
pub unsafe fn __SHSAX(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("shsax {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Subtract and Add with Exchange
#[inline(always)]
pub unsafe fn __USAX(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("usax {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Q-Subtract and Add with Exchange
#[inline(always)]
pub unsafe fn __UQSAX(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("uqsax {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Halving Subtract and Add with Exchange
#[inline(always)]
pub unsafe fn __UHSAX(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("uhsax {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Sum of Absolute Differences 8
#[inline(always)]
pub unsafe fn __USAD8(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("usad8 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Unsigned Sum of Absolute Differences 8 with Accumulate
#[inline(always)]
pub unsafe fn __USADA8(op1: u32, op2: u32, op3: u32) -> u32 {
    let result: u32;
    asm!("usada8 {}, {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2, in(reg) op3);
    result
}

/// Signed Saturate 16
#[inline(always)]
pub unsafe fn __SSAT16(value: u32, sat: u32) -> u32 {
    let result: u32;
    asm!("ssat16 {}, #{}, {}", out(reg) result, in(reg) sat, in(reg) value);
    result
}

/// Unsigned Saturate 16
#[inline(always)]
pub unsafe fn __USAT16(value: u32, sat: u32) -> u32 {
    let result: u32;
    asm!("usat16 {}, #{}, {}", out(reg) result, in(reg) sat, in(reg) value);
    result
}

/// Unsigned Extract Byte 16
#[inline(always)]
pub unsafe fn __UXTB16(value: u32) -> u32 {
    let result: u32;
    asm!("uxtb16 {}, {}", out(reg) result, in(reg) value);
    result
}

/// Unsigned Extract and Add Byte 16
#[inline(always)]
pub unsafe fn __UXTAB16(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("uxtab16 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Signed Extract Byte 16
#[inline(always)]
pub unsafe fn __SXTB16(value: u32) -> u32 {
    let result: u32;
    asm!("sxtb16 {}, {}", out(reg) result, in(reg) value);
    result
}

/// Signed Extract and Add Byte 16
#[inline(always)]
pub unsafe fn __SXTAB16(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("sxtab16 {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Signed Multiply Add Dual
#[inline(always)]
pub unsafe fn __SMUAD(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("smuad {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Signed Multiply Add Dual Reverse
#[inline(always)]
pub unsafe fn __SMUADX(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("smuadx {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Signed Multiply Accumulate Dual
#[inline(always)]
pub unsafe fn __SMLAD(op1: u32, op2: u32, op3: u32) -> u32 {
    let result: u32;
    asm!("smlad {}, {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2, in(reg) op3);
    result
}

/// Signed Multiply Accumulate Dual Reverse
#[inline(always)]
pub unsafe fn __SMLADX(op1: u32, op2: u32, op3: u32) -> u32 {
    let result: u32;
    asm!("smladx {}, {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2, in(reg) op3);
    result
}

/// Signed Multiply Accumulate Long Dual
#[inline(always)]
pub unsafe fn __SMLALD(op1: u32, op2: u32, acc: u64) -> u64 {
    let result: u64;
    asm!("smlald {}, {}, {}, {}", out(reg) result, in(reg) acc, in(reg) op1, in(reg) op2);
    result
}

/// Signed Multiply Accumulate Long Dual Reverse
#[inline(always)]
pub unsafe fn __SMLALDX(op1: u32, op2: u32, acc: u64) -> u64 {
    let result: u64;
    asm!("smlaldx {}, {}, {}, {}", out(reg) result, in(reg) acc, in(reg) op1, in(reg) op2);
    result
}

/// Signed Multiply Subtract Dual
#[inline(always)]
pub unsafe fn __SMUSD(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("smusd {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Signed Multiply Subtract Dual Reverse
#[inline(always)]
pub unsafe fn __SMUSDX(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("smusdx {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Signed Multiply Subtract Dual
#[inline(always)]
pub unsafe fn __SMLSD(op1: u32, op2: u32, op3: u32) -> u32 {
    let result: u32;
    asm!("smlsd {}, {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2, in(reg) op3);
    result
}

/// Signed Multiply Subtract Dual Reverse
#[inline(always)]
pub unsafe fn __SMLSDX(op1: u32, op2: u32, op3: u32) -> u32 {
    let result: u32;
    asm!("smlsdx {}, {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2, in(reg) op3);
    result
}

/// Signed Multiply Subtract Long Dual
#[inline(always)]
pub unsafe fn __SMLSLD(op1: u32, op2: u32, acc: u64) -> u64 {
    let result: u64;
    asm!("smlsld {}, {}, {}, {}", out(reg) result, in(reg) acc, in(reg) op1, in(reg) op2);
    result
}

/// Signed Multiply Subtract Long Dual Reverse
#[inline(always)]
pub unsafe fn __SMLSLDX(op1: u32, op2: u32, acc: u64) -> u64 {
    let result: u64;
    asm!("smlsldx {}, {}, {}, {}", out(reg) result, in(reg) acc, in(reg) op1, in(reg) op2);
    result
}

/// Select Bytes
#[inline(always)]
pub unsafe fn __SEL(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("sel {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Q-Add
#[inline(always)]
pub unsafe fn __QADD(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("qadd {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Q-Sub
#[inline(always)]
pub unsafe fn __QSUB(op1: u32, op2: u32) -> u32 {
    let result: u32;
    asm!("qsub {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2);
    result
}

/// Pack Halfword Bottom Top
#[inline(always)]
pub unsafe fn __PKHBT(arg1: u32, arg2: u32, arg3: u32) -> u32 {
    let result: u32;
    asm!("pkhbt {}, {}, {}, lsl {}", out(reg) result, in(reg) arg1, in(reg) arg2, in(reg) arg3);
    result
}

/// Pack Halfword Top Bottom
#[inline(always)]
pub unsafe fn __PKHTB(arg1: u32, arg2: u32, arg3: u32) -> u32 {
    let result: u32;
    if arg3 == 0 {
        asm!("pkhtb {}, {}, {}", out(reg) result, in(reg) arg1, in(reg) arg2);
    } else {
        asm!("pkhtb {}, {}, {}, asr {}", out(reg) result, in(reg) arg1, in(reg) arg2, in(reg) arg3);
    }
    result
}

/// Signed Multiply Most Significant
#[inline(always)]
pub unsafe fn __SMMLA(op1: i32, op2: i32, op3: i32) -> i32 {
    let result: i32;
    asm!("smmla {}, {}, {}, {}", out(reg) result, in(reg) op1, in(reg) op2, in(reg) op3);
    result
}
