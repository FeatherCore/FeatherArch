/*
 * Copyright (c) 2017-2023 Arm Limited. All rights reserved.
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
 * CMSIS Core(M) Context Management for Armv8-M TrustZone
 */

use crate::intrinsics::{__get_IPSR, __get_PSP, __get_CONTROL, __set_PSP, __set_PSPLIM, __set_CONTROL};

/// Data type that identifies secure software modules called by a process.
pub type TZ_ModuleId_t = u32;

/// TZ Memory ID identifies an allocated memory slot.
pub type TZ_MemoryId_t = u32;

/// Number of process slots (threads may call secure library code)
#[cfg(not(feature = "TZ_PROCESS_STACK_SLOTS"))]
pub const TZ_PROCESS_STACK_SLOTS: usize = 8;

#[cfg(feature = "TZ_PROCESS_STACK_SLOTS")]
pub const TZ_PROCESS_STACK_SLOTS: usize = 8;

/// Stack size of the secure library code
#[cfg(not(feature = "TZ_PROCESS_STACK_SIZE"))]
pub const TZ_PROCESS_STACK_SIZE: usize = 256;

#[cfg(feature = "TZ_PROCESS_STACK_SIZE")]
pub const TZ_PROCESS_STACK_SIZE: usize = 256;

#[repr(C)]
#[derive(Copy, Clone)]
struct StackInfo {
    sp_top: u32,
    sp_limit: u32,
    sp: u32,
}

static mut PROCESS_STACK_INFO: [StackInfo; TZ_PROCESS_STACK_SLOTS] = [
    StackInfo {
        sp_top: 0,
        sp_limit: 0,
        sp: 0,
    };
    TZ_PROCESS_STACK_SLOTS
];

static mut PROCESS_STACK_MEMORY: [[u64; TZ_PROCESS_STACK_SIZE / 8]; TZ_PROCESS_STACK_SLOTS] =
    [[0; TZ_PROCESS_STACK_SIZE / 8]; TZ_PROCESS_STACK_SLOTS];

static mut PROCESS_STACK_FREE_SLOT: u32 = 0xFFFFFFFF;

/// Initialize secure context memory system
///
/// # Returns
///
/// execution status (1: success, 0: error)
pub unsafe fn TZ_InitContextSystem_S() -> u32 {
    let ipsr = __get_IPSR();
    if ipsr == 0 {
        return 0;
    }

    let mut n: usize = 0;
    while n < TZ_PROCESS_STACK_SLOTS {
        PROCESS_STACK_INFO[n].sp = 0;
        PROCESS_STACK_INFO[n].sp_limit = PROCESS_STACK_MEMORY[n].as_ptr() as u32;
        PROCESS_STACK_INFO[n].sp_top = PROCESS_STACK_MEMORY[n].as_ptr() as u32 + TZ_PROCESS_STACK_SIZE as u32;
        *(PROCESS_STACK_MEMORY[n].as_ptr() as *mut u32) = (n + 1) as u32;
        n += 1;
    }
    n -= 1;
    *(PROCESS_STACK_MEMORY[n].as_ptr() as *mut u32) = 0xFFFFFFFF;

    PROCESS_STACK_FREE_SLOT = 0;

    __set_PSPLIM(PROCESS_STACK_MEMORY[0].as_ptr() as u32);
    __set_PSP(PROCESS_STACK_MEMORY[0].as_ptr() as u32);

    __set_CONTROL(0x02);

    1
}

/// Allocate context memory for calling secure software modules in TrustZone
///
/// # Arguments
///
/// * `module` - identifies software modules called from non-secure mode
///
/// # Returns
///
/// * value != 0 - TrustZone memory slot identifier
/// * value 0 - no memory available or internal error
pub unsafe fn TZ_AllocModuleContext_S(_module: TZ_ModuleId_t) -> TZ_MemoryId_t {
    let ipsr = __get_IPSR();
    if ipsr == 0 {
        return 0;
    }

    if PROCESS_STACK_FREE_SLOT == 0xFFFFFFFF {
        return 0;
    }

    let slot = PROCESS_STACK_FREE_SLOT as usize;
    PROCESS_STACK_FREE_SLOT = *(PROCESS_STACK_MEMORY[slot].as_ptr() as *const u32);

    PROCESS_STACK_INFO[slot].sp = PROCESS_STACK_INFO[slot].sp_top;

    (slot as u32) + 1
}

/// Free context memory that was previously allocated with `TZ_AllocModuleContext_S`
///
/// # Arguments
///
/// * `id` - TrustZone memory slot identifier
///
/// # Returns
///
/// execution status (1: success, 0: error)
pub unsafe fn TZ_FreeModuleContext_S(id: TZ_MemoryId_t) -> u32 {
    let ipsr = __get_IPSR();
    if ipsr == 0 {
        return 0;
    }

    if id == 0 || id > TZ_PROCESS_STACK_SLOTS as u32 {
        return 0;
    }

    let slot = (id - 1) as usize;

    if PROCESS_STACK_INFO[slot].sp == 0 {
        return 0;
    }
    PROCESS_STACK_INFO[slot].sp = 0;

    *(PROCESS_STACK_MEMORY[slot].as_ptr() as *mut u32) = PROCESS_STACK_FREE_SLOT;
    PROCESS_STACK_FREE_SLOT = slot as u32;

    1
}

/// Load secure context (called on RTOS thread context switch)
///
/// # Arguments
///
/// * `id` - TrustZone memory slot identifier
///
/// # Returns
///
/// execution status (1: success, 0: error)
pub unsafe fn TZ_LoadContext_S(id: TZ_MemoryId_t) -> u32 {
    let ipsr = __get_IPSR();
    let control = __get_CONTROL();
    if ipsr == 0 || (control & 2) == 0 {
        return 0;
    }

    if id == 0 || id > TZ_PROCESS_STACK_SLOTS as u32 {
        return 0;
    }

    let slot = (id - 1) as usize;

    if PROCESS_STACK_INFO[slot].sp == 0 {
        return 0;
    }

    __set_PSPLIM(PROCESS_STACK_INFO[slot].sp_limit);
    __set_PSP(PROCESS_STACK_INFO[slot].sp);

    1
}

/// Store secure context (called on RTOS thread context switch)
///
/// # Arguments
///
/// * `id` - TrustZone memory slot identifier
///
/// # Returns
///
/// execution status (1: success, 0: error)
pub unsafe fn TZ_StoreContext_S(id: TZ_MemoryId_t) -> u32 {
    let ipsr = __get_IPSR();
    let control = __get_CONTROL();
    if ipsr == 0 || (control & 2) == 0 {
        return 0;
    }

    if id == 0 || id > TZ_PROCESS_STACK_SLOTS as u32 {
        return 0;
    }

    let slot = (id - 1) as usize;

    if PROCESS_STACK_INFO[slot].sp == 0 {
        return 0;
    }

    let sp = __get_PSP();
    if sp < PROCESS_STACK_INFO[slot].sp_limit || sp > PROCESS_STACK_INFO[slot].sp_top {
        return 0;
    }
    PROCESS_STACK_INFO[slot].sp = sp;

    __set_PSPLIM(PROCESS_STACK_MEMORY[0].as_ptr() as u32);
    __set_PSP(PROCESS_STACK_MEMORY[0].as_ptr() as u32);

    1
}
