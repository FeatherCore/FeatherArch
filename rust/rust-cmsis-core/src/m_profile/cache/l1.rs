/*
 * Copyright (c) 2020-2021 Arm Limited. All rights reserved.
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
 * CMSIS-Core(M) Level 1 Cache API for Armv7-M and later
 */

use crate::intrinsics::{__dsb, __isb};

/// Cortex-M7 cache line size is fixed to 32 bytes (8 words). See also register SCB_CCSIDR
#[cfg(not(feature = "__SCB_DCACHE_LINE_SIZE"))]
pub const __SCB_DCACHE_LINE_SIZE: u32 = 32;

/// Cortex-M7 cache line size is fixed to 32 bytes (8 words). See also register SCB_CCSIDR
#[cfg(not(feature = "__SCB_ICACHE_LINE_SIZE"))]
pub const __SCB_ICACHE_LINE_SIZE: u32 = 32;

/// Cache Functions
///
/// Functions that configure Instruction and Data cache.

/// SCB CCR Register Definitions
pub const SCB_CCR_IC_Pos: u32 = 17;
pub const SCB_CCR_IC_Msk: u32 = (1 << SCB_CCR_IC_Pos);
pub const SCB_CCR_DC_Pos: u32 = 16;
pub const SCB_CCR_DC_Msk: u32 = (1 << SCB_CCR_DC_Pos);

/// SCB CCSIDR Register Definitions
pub const SCB_CCSIDR_ASSOCIATIVITY_Pos: u32 = 3;
pub const SCB_CCSIDR_ASSOCIATIVITY_Msk: u32 = (0x3FF << SCB_CCSIDR_ASSOCIATIVITY_Pos);
pub const SCB_CCSIDR_NUMSETS_Pos: u32 = 13;
pub const SCB_CCSIDR_NUMSETS_Msk: u32 = (0x7FFF << SCB_CCSIDR_NUMSETS_Pos);

/// SCB CSSELR Register Definitions
pub const SCB_CSSELR_LEVEL_Pos: u32 = 1;
pub const SCB_CSSELR_LEVEL_Msk: u32 = (7 << SCB_CSSELR_LEVEL_Pos);
pub const SCB_CSSELR_IND_Pos: u32 = 0;
pub const SCB_CSSELR_IND_Msk: u32 = (1 << SCB_CSSELR_IND_Pos);

/// SCB DCISW Register Definitions
pub const SCB_DCISW_WAY_Pos: u32 = 30;
pub const SCB_DCISW_WAY_Msk: u32 = (0x3 << SCB_DCISW_WAY_Pos);
pub const SCB_DCISW_SET_Pos: u32 = 5;
pub const SCB_DCISW_SET_Msk: u32 = (0x1FF << SCB_DCISW_SET_Pos);

/// SCB DCCSW Register Definitions
pub const SCB_DCCSW_WAY_Pos: u32 = 30;
pub const SCB_DCCSW_WAY_Msk: u32 = (0x3 << SCB_DCCSW_WAY_Pos);
pub const SCB_DCCSW_SET_Pos: u32 = 5;
pub const SCB_DCCSW_SET_Msk: u32 = (0x1FF << SCB_DCCSW_SET_Pos);

/// SCB DCCISW Register Definitions
pub const SCB_DCCISW_WAY_Pos: u32 = 30;
pub const SCB_DCCISW_WAY_Msk: u32 = (0x3 << SCB_DCCISW_WAY_Pos);
pub const SCB_DCCISW_SET_Pos: u32 = 5;
pub const SCB_DCCISW_SET_Msk: u32 = (0x1FF << SCB_DCCISW_SET_Pos);

/// Cache Size ID Register Macros
#[inline(always)]
pub const fn CCSIDR_WAYS(x: u32) -> u32 {
    ((x & SCB_CCSIDR_ASSOCIATIVITY_Msk) >> SCB_CCSIDR_ASSOCIATIVITY_Pos)
}

#[inline(always)]
pub const fn CCSIDR_SETS(x: u32) -> u32 {
    ((x & SCB_CCSIDR_NUMSETS_Msk) >> SCB_CCSIDR_NUMSETS_Pos)
}

/// Enable I-Cache
///
/// Turns on I-Cache
#[inline(always)]
pub unsafe fn SCB_EnableICache() {
    #[cfg(feature = "__ICACHE_PRESENT")]
    {
        let scb_ccr = unsafe { (*(0xE000ED14 as *const u32)).read_volatile() };
        if scb_ccr & SCB_CCR_IC_Msk != 0 {
            return;
        }
        __dsb();
        __isb();
        unsafe {
            (0xE000EF50 as *mut u32).write_volatile(0);
        }
        __dsb();
        __isb();
        unsafe {
            let mut scb_ccr = (*(0xE000ED14 as *const u32)).read_volatile();
            scb_ccr |= SCB_CCR_IC_Msk;
            (0xE000ED14 as *mut u32).write_volatile(scb_ccr);
        }
        __dsb();
        __isb();
    }
}

/// Disable I-Cache
///
/// Turns off I-Cache
#[inline(always)]
pub unsafe fn SCB_DisableICache() {
    #[cfg(feature = "__ICACHE_PRESENT")]
    {
        __dsb();
        __isb();
        unsafe {
            let mut scb_ccr = (*(0xE000ED14 as *const u32)).read_volatile();
            scb_ccr &= !SCB_CCR_IC_Msk;
            (0xE000ED14 as *mut u32).write_volatile(scb_ccr);
        }
        unsafe {
            (0xE000EF50 as *mut u32).write_volatile(0);
        }
        __dsb();
        __isb();
    }
}

/// Invalidate I-Cache
///
/// Invalidates I-Cache
#[inline(always)]
pub unsafe fn SCB_InvalidateICache() {
    #[cfg(feature = "__ICACHE_PRESENT")]
    {
        __dsb();
        __isb();
        unsafe {
            (0xE000EF50 as *mut u32).write_volatile(0);
        }
        __dsb();
        __isb();
    }
}

/// I-Cache Invalidate by address
///
/// Invalidates I-Cache for the given address.
/// I-Cache is invalidated starting from a 32 byte aligned address in 32 byte granularity.
/// I-Cache memory blocks which are part of given address + given size are invalidated.
///
/// # Arguments
///
/// * `addr` - address
/// * `isize` - size of memory block (in number of bytes)
#[inline(always)]
pub unsafe fn SCB_InvalidateICache_by_Addr(_addr: *mut (), _isize: i32) {
    #[cfg(feature = "__ICACHE_PRESENT")]
    {
        if _isize > 0 {
            let mut op_size = _isize as u32 + ((_addr as u32) & (__SCB_ICACHE_LINE_SIZE - 1));
            let mut op_addr = _addr as u32;
            __dsb();
            loop {
                unsafe {
                    (0xE000EF58 as *mut u32).write_volatile(op_addr);
                }
                op_addr += __SCB_ICACHE_LINE_SIZE;
                op_size -= __SCB_ICACHE_LINE_SIZE;
                if op_size <= 0 {
                    break;
                }
            }
            __dsb();
            __isb();
        }
    }
}

/// Enable D-Cache
///
/// Turns on D-Cache
#[inline(always)]
pub unsafe fn SCB_EnableDCache() {
    #[cfg(feature = "__DCACHE_PRESENT")]
    {
        let scb_ccr = unsafe { (*(0xE000ED14 as *const u32)).read_volatile() };
        if scb_ccr & SCB_CCR_DC_Msk != 0 {
            return;
        }
        unsafe {
            (0xE000ED84 as *mut u32).write_volatile(0);
        }
        __dsb();
        let ccsidr = unsafe { (*(0xE000ED80 as *const u32)).read_volatile() };
        let mut sets = CCSIDR_SETS(ccsidr);
        loop {
            let mut ways = CCSIDR_WAYS(ccsidr);
            loop {
                let dcisw_val = ((sets << SCB_DCISW_SET_Pos) & SCB_DCISW_SET_Msk) |
                    ((ways << SCB_DCISW_WAY_Pos) & SCB_DCISW_WAY_Msk);
                unsafe {
                    (0xE000EF60 as *mut u32).write_volatile(dcisw_val);
                }
                if ways == 0 {
                    break;
                }
                ways -= 1;
            }
            if sets == 0 {
                break;
            }
            sets -= 1;
        }
        __dsb();
        unsafe {
            let mut scb_ccr = (*(0xE000ED14 as *const u32)).read_volatile();
            scb_ccr |= SCB_CCR_DC_Msk;
            (0xE000ED14 as *mut u32).write_volatile(scb_ccr);
        }
        __dsb();
        __isb();
    }
}

/// Disable D-Cache
///
/// Turns off D-Cache
#[inline(always)]
pub unsafe fn SCB_DisableDCache() {
    #[cfg(feature = "__DCACHE_PRESENT")]
    {
        unsafe {
            (0xE000ED84 as *mut u32).write_volatile(0);
        }
        __dsb();
        unsafe {
            let mut scb_ccr = (*(0xE000ED14 as *const u32)).read_volatile();
            scb_ccr &= !SCB_CCR_DC_Msk;
            (0xE000ED14 as *mut u32).write_volatile(scb_ccr);
        }
        __dsb();
        let ccsidr = unsafe { (*(0xE000ED80 as *const u32)).read_volatile() };
        let mut sets = CCSIDR_SETS(ccsidr);
        loop {
            let mut ways = CCSIDR_WAYS(ccsidr);
            loop {
                let dccisw_val = ((sets << SCB_DCCISW_SET_Pos) & SCB_DCCISW_SET_Msk) |
                    ((ways << SCB_DCCISW_WAY_Pos) & SCB_DCCISW_WAY_Msk);
                unsafe {
                    (0xE000EF74 as *mut u32).write_volatile(dccisw_val);
                }
                if ways == 0 {
                    break;
                }
                ways -= 1;
            }
            if sets == 0 {
                break;
            }
            sets -= 1;
        }
        __dsb();
        __isb();
    }
}

/// Invalidate D-Cache
///
/// Invalidates D-Cache
#[inline(always)]
pub unsafe fn SCB_InvalidateDCache() {
    #[cfg(feature = "__DCACHE_PRESENT")]
    {
        unsafe {
            (0xE000ED84 as *mut u32).write_volatile(0);
        }
        __dsb();
        let ccsidr = unsafe { (*(0xE000ED80 as *const u32)).read_volatile() };
        let mut sets = CCSIDR_SETS(ccsidr);
        loop {
            let mut ways = CCSIDR_WAYS(ccsidr);
            loop {
                let dcisw_val = ((sets << SCB_DCISW_SET_Pos) & SCB_DCISW_SET_Msk) |
                    ((ways << SCB_DCISW_WAY_Pos) & SCB_DCISW_WAY_Msk);
                unsafe {
                    (0xE000EF60 as *mut u32).write_volatile(dcisw_val);
                }
                if ways == 0 {
                    break;
                }
                ways -= 1;
            }
            if sets == 0 {
                break;
            }
            sets -= 1;
        }
        __dsb();
        __isb();
    }
}

/// Clean D-Cache
///
/// Cleans D-Cache
#[inline(always)]
pub unsafe fn SCB_CleanDCache() {
    #[cfg(feature = "__DCACHE_PRESENT")]
    {
        unsafe {
            (0xE000ED84 as *mut u32).write_volatile(0);
        }
        __dsb();
        let ccsidr = unsafe { (*(0xE000ED80 as *const u32)).read_volatile() };
        let mut sets = CCSIDR_SETS(ccsidr);
        loop {
            let mut ways = CCSIDR_WAYS(ccsidr);
            loop {
                let dccsw_val = ((sets << SCB_DCCSW_SET_Pos) & SCB_DCCSW_SET_Msk) |
                    ((ways << SCB_DCCSW_WAY_Pos) & SCB_DCCSW_WAY_Msk);
                unsafe {
                    (0xE000EF6C as *mut u32).write_volatile(dccsw_val);
                }
                if ways == 0 {
                    break;
                }
                ways -= 1;
            }
            if sets == 0 {
                break;
            }
            sets -= 1;
        }
        __dsb();
        __isb();
    }
}

/// Clean & Invalidate D-Cache
///
/// Cleans and Invalidates D-Cache
#[inline(always)]
pub unsafe fn SCB_CleanInvalidateDCache() {
    #[cfg(feature = "__DCACHE_PRESENT")]
    {
        unsafe {
            (0xE000ED84 as *mut u32).write_volatile(0);
        }
        __dsb();
        let ccsidr = unsafe { (*(0xE000ED80 as *const u32)).read_volatile() };
        let mut sets = CCSIDR_SETS(ccsidr);
        loop {
            let mut ways = CCSIDR_WAYS(ccsidr);
            loop {
                let dccisw_val = ((sets << SCB_DCCISW_SET_Pos) & SCB_DCCISW_SET_Msk) |
                    ((ways << SCB_DCCISW_WAY_Pos) & SCB_DCCISW_WAY_Msk);
                unsafe {
                    (0xE000EF74 as *mut u32).write_volatile(dccisw_val);
                }
                if ways == 0 {
                    break;
                }
                ways -= 1;
            }
            if sets == 0 {
                break;
            }
            sets -= 1;
        }
        __dsb();
        __isb();
    }
}

/// D-Cache Invalidate by address
///
/// Invalidates D-Cache for the given address.
/// D-Cache is invalidated starting from a 32 byte aligned address in 32 byte granularity.
/// D-Cache memory blocks which are part of given address + given size are invalidated.
///
/// # Arguments
///
/// * `addr` - address
/// * `dsize` - size of memory block (in number of bytes)
#[inline(always)]
pub unsafe fn SCB_InvalidateDCache_by_Addr(_addr: *mut (), _dsize: i32) {
    #[cfg(feature = "__DCACHE_PRESENT")]
    {
        if _dsize > 0 {
            let mut op_size = _dsize as u32 + ((_addr as u32) & (__SCB_DCACHE_LINE_SIZE - 1));
            let mut op_addr = _addr as u32;
            __dsb();
            loop {
                unsafe {
                    (0xE000EF5C as *mut u32).write_volatile(op_addr);
                }
                op_addr += __SCB_DCACHE_LINE_SIZE;
                op_size -= __SCB_DCACHE_LINE_SIZE;
                if op_size <= 0 {
                    break;
                }
            }
            __dsb();
            __isb();
        }
    }
}

/// D-Cache Clean by address
///
/// Cleans D-Cache for the given address
/// D-Cache is cleaned starting from a 32 byte aligned address in 32 byte granularity.
/// D-Cache memory blocks which are part of given address + given size are cleaned.
///
/// # Arguments
///
/// * `addr` - address
/// * `dsize` - size of memory block (in number of bytes)
#[inline(always)]
pub unsafe fn SCB_CleanDCache_by_Addr(_addr: *mut (), _dsize: i32) {
    #[cfg(feature = "__DCACHE_PRESENT")]
    {
        if _dsize > 0 {
            let mut op_size = _dsize as u32 + ((_addr as u32) & (__SCB_DCACHE_LINE_SIZE - 1));
            let mut op_addr = _addr as u32;
            __dsb();
            loop {
                unsafe {
                    (0xE000EF68 as *mut u32).write_volatile(op_addr);
                }
                op_addr += __SCB_DCACHE_LINE_SIZE;
                op_size -= __SCB_DCACHE_LINE_SIZE;
                if op_size <= 0 {
                    break;
                }
            }
            __dsb();
            __isb();
        }
    }
}

/// D-Cache Clean and Invalidate by address
///
/// Cleans and invalidates D_Cache for the given address
/// D-Cache is cleaned and invalidated starting from a 32 byte aligned address in 32 byte granularity.
/// D-Cache memory blocks which are part of given address + given size are cleaned and invalidated.
///
/// # Arguments
///
/// * `addr` - address (aligned to 32-byte boundary)
/// * `dsize` - size of memory block (in number of bytes)
#[inline(always)]
pub unsafe fn SCB_CleanInvalidateDCache_by_Addr(_addr: *mut (), _dsize: i32) {
    #[cfg(feature = "__DCACHE_PRESENT")]
    {
        if _dsize > 0 {
            let mut op_size = _dsize as u32 + ((_addr as u32) & (__SCB_DCACHE_LINE_SIZE - 1));
            let mut op_addr = _addr as u32;
            __dsb();
            loop {
                unsafe {
                    (0xE000EF70 as *mut u32).write_volatile(op_addr);
                }
                op_addr += __SCB_DCACHE_LINE_SIZE;
                op_size -= __SCB_DCACHE_LINE_SIZE;
                if op_size <= 0 {
                    break;
                }
            }
            __dsb();
            __isb();
        }
    }
}
