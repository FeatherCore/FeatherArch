/*
 * Copyright (c) 2017-2022 Arm Limited. All rights reserved.
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
 * CMSIS-Core(M) MPU API for Armv8-M and Armv8.1-M MPU
 */

#![allow(non_snake_case)]
#![allow(non_upper_case_globals)]

use core::ptr;
use crate::intrinsics;

const MPU_BASE: usize = 0xE000ED90;

#[repr(C)]
pub struct Mpu {
    pub TYPE: u32,
    _reserved0: [u32; 3],
    pub CTRL: u32,
    _reserved1: [u32; 3],
    pub RNR: u32,
    _reserved2: [u32; 3],
    pub RBAR: u32,
    _reserved3: [u32; 3],
    pub RLAR: u32,
    _reserved4: [u32; 27],
    pub MAIR: [u32; 2],
}

#[inline(always)]
fn MPU() -> *mut Mpu {
    MPU_BASE as *mut Mpu
}

/** \brief Attribute for device memory (outer only) */
pub const ARM_MPU_ATTR_DEVICE: u32 = 0;

/** \brief Attribute for non-cacheable, normal memory */
pub const ARM_MPU_ATTR_NON_CACHEABLE: u32 = 4;

/** \brief Attribute for Normal memory, Outer and Inner cacheability.
* \param NT Non-Transient: Set to 1 for Non-transient data. Set to 0 for Transient data.
* \param WB Write-Back: Set to 1 to use a Write-Back policy. Set to 0 to use a Write-Through policy.
* \param RA Read Allocation: Set to 1 to enable cache allocation on read miss. Set to 0 to disable cache allocation on read miss.
* \param WA Write Allocation: Set to 1 to enable cache allocation on write miss. Set to 0 to disable cache allocation on write miss.
*/
#[inline(always)]
pub const fn ARM_MPU_ATTR_MEMORY_(NT: u32, WB: u32, RA: u32, WA: u32) -> u32 {
    (((NT & 1) << 3) | ((WB & 1) << 2) | ((RA & 1) << 1) | (WA & 1))
}

/** \brief Device memory type non Gathering, non Re-ordering, non Early Write Acknowledgement */
pub const ARM_MPU_ATTR_DEVICE_nGnRnE: u32 = 0;

/** \brief Device memory type non Gathering, non Re-ordering, Early Write Acknowledgement */
pub const ARM_MPU_ATTR_DEVICE_nGnRE: u32 = 1;

/** \brief Device memory type non Gathering, Re-ordering, Early Write Acknowledgement */
pub const ARM_MPU_ATTR_DEVICE_nGRE: u32 = 2;

/** \brief Device memory type Gathering, Re-ordering, Early Write Acknowledgement */
pub const ARM_MPU_ATTR_DEVICE_GRE: u32 = 3;

/** \brief Normal memory outer-cacheable and inner-cacheable attributes
* WT = Write Through, WB = Write Back, TR = Transient, RA = Read-Allocate, WA = Write Allocate
*/
pub const MPU_ATTR_NORMAL_OUTER_NON_CACHEABLE: u32 = 0b0100;
pub const MPU_ATTR_NORMAL_OUTER_WT_TR_RA: u32 = 0b0010;
pub const MPU_ATTR_NORMAL_OUTER_WT_TR_WA: u32 = 0b0001;
pub const MPU_ATTR_NORMAL_OUTER_WT_TR_RA_WA: u32 = 0b0011;
pub const MPU_ATTR_NORMAL_OUTER_WT_RA: u32 = 0b1010;
pub const MPU_ATTR_NORMAL_OUTER_WT_WA: u32 = 0b1001;
pub const MPU_ATTR_NORMAL_OUTER_WT_RA_WA: u32 = 0b1011;
pub const MPU_ATTR_NORMAL_OUTER_WB_TR_RA: u32 = 0b0110;
pub const MPU_ATTR_NORMAL_OUTER_WB_TR_WA: u32 = 0b0101;
pub const MPU_ATTR_NORMAL_OUTER_WB_TR_RA_WA: u32 = 0b0111;
pub const MPU_ATTR_NORMAL_OUTER_WB_RA: u32 = 0b1110;
pub const MPU_ATTR_NORMAL_OUTER_WB_WA: u32 = 0b1101;
pub const MPU_ATTR_NORMAL_OUTER_WB_RA_WA: u32 = 0b1111;
pub const MPU_ATTR_NORMAL_INNER_NON_CACHEABLE: u32 = 0b0100;
pub const MPU_ATTR_NORMAL_INNER_WT_TR_RA: u32 = 0b0010;
pub const MPU_ATTR_NORMAL_INNER_WT_TR_WA: u32 = 0b0001;
pub const MPU_ATTR_NORMAL_INNER_WT_TR_RA_WA: u32 = 0b0011;
pub const MPU_ATTR_NORMAL_INNER_WT_RA: u32 = 0b1010;
pub const MPU_ATTR_NORMAL_INNER_WT_WA: u32 = 0b1001;
pub const MPU_ATTR_NORMAL_INNER_WT_RA_WA: u32 = 0b1011;
pub const MPU_ATTR_NORMAL_INNER_WB_TR_RA: u32 = 0b0110;
pub const MPU_ATTR_NORMAL_INNER_WB_TR_WA: u32 = 0b0101;
pub const MPU_ATTR_NORMAL_INNER_WB_TR_RA_WA: u32 = 0b0111;
pub const MPU_ATTR_NORMAL_INNER_WB_RA: u32 = 0b1110;
pub const MPU_ATTR_NORMAL_INNER_WB_WA: u32 = 0b1101;
pub const MPU_ATTR_NORMAL_INNER_WB_RA_WA: u32 = 0b1111;

/** \brief Memory Attribute
* \param O Outer memory attributes
* \param I O == ARM_MPU_ATTR_DEVICE: Device memory attributes, else: Inner memory attributes
*/
#[inline(always)]
pub const fn ARM_MPU_ATTR(O: u32, I: u32) -> u32 {
    (((O) & 0xF) << 4) | (if ((O) & 0xF) != 0 { (I) & 0xF } else { ((I) & 0x3) << 2 })
}

/* \brief Specifies MAIR_ATTR number */
#[inline(always)]
pub const fn MAIR_ATTR(x: u32) -> u32 {
    if x > 7 || x < 0 { 0 } else { x }
}

/**
 * Shareability
 */
/** \brief Normal memory, non-shareable  */
pub const ARM_MPU_SH_NON: u32 = 0;

/** \brief Normal memory, outer shareable  */
pub const ARM_MPU_SH_OUTER: u32 = 2;

/** \brief Normal memory, inner shareable  */
pub const ARM_MPU_SH_INNER: u32 = 3;

/**
 * Access permissions
 * AP = Access permission, RO = Read-only, RW = Read/Write, NP = Any privilege, PO = Privileged code only
 */
/** \brief Normal memory, read/write */
pub const ARM_MPU_AP_RW: u32 = 0;

/** \brief Normal memory, read-only */
pub const ARM_MPU_AP_RO: u32 = 1;

/** \brief Normal memory, any privilege level */
pub const ARM_MPU_AP_NP: u32 = 1;

/** \brief Normal memory, privileged access only */
pub const ARM_MPU_AP_PO: u32 = 0;

/*
 * Execute-never
 * XN = Execute-never, EX = Executable
 */
/** \brief Normal memory, Execution not permitted */
pub const ARM_MPU_XN: u32 = 1;

/** \brief Normal memory, Execution only permitted if read permitted */
pub const ARM_MPU_EX: u32 = 0;

/** \brief Memory access permissions
* \param RO Read-Only: Set to 1 for read-only memory. Set to 0 for a read/write memory.
* \param NP Non-Privileged: Set to 1 for non-privileged memory. Set to 0 for privileged memory.
*/
#[inline(always)]
pub const fn ARM_MPU_AP_(RO: u32, NP: u32) -> u32 {
    (((RO) & 1) << 1) | ((NP) & 1)
}

/** \brief MPU Type Register Definitions */
pub const MPU_TYPE_RALIASES: u32 = 4;
pub const MPU_TYPE_IREGION_Pos: u32 = 16;
pub const MPU_TYPE_IREGION_Msk: u32 = (0xFF << MPU_TYPE_IREGION_Pos);
pub const MPU_TYPE_DREGION_Pos: u32 = 8;
pub const MPU_TYPE_DREGION_Msk: u32 = (0xFF << MPU_TYPE_DREGION_Pos);
pub const MPU_TYPE_SEPARATE_Pos: u32 = 0;
pub const MPU_TYPE_SEPARATE_Msk: u32 = (1 << MPU_TYPE_SEPARATE_Pos);

/** \brief MPU Control Register Definitions */
pub const MPU_CTRL_PRIVDEFENA_Pos: u32 = 2;
pub const MPU_CTRL_PRIVDEFENA_Msk: u32 = (1 << MPU_CTRL_PRIVDEFENA_Pos);
pub const MPU_CTRL_HFNMIENA_Pos: u32 = 1;
pub const MPU_CTRL_HFNMIENA_Msk: u32 = (1 << MPU_CTRL_HFNMIENA_Pos);
pub const MPU_CTRL_ENABLE_Pos: u32 = 0;
pub const MPU_CTRL_ENABLE_Msk: u32 = (1 << MPU_CTRL_ENABLE_Pos);

/** \brief MPU Region Base Address Register Definitions */
pub const MPU_RBAR_BASE_Pos: u32 = 5;
pub const MPU_RBAR_BASE_Msk: u32 = (0x7FFFFFF << MPU_RBAR_BASE_Pos);
pub const MPU_RBAR_SH_Pos: u32 = 3;
pub const MPU_RBAR_SH_Msk: u32 = (0x3 << MPU_RBAR_SH_Pos);
pub const MPU_RBAR_AP_Pos: u32 = 1;
pub const MPU_RBAR_AP_Msk: u32 = (0x3 << MPU_RBAR_AP_Pos);
pub const MPU_RBAR_XN_Pos: u32 = 0;
pub const MPU_RBAR_XN_Msk: u32 = (1 << MPU_RBAR_XN_Pos);

/** \brief MPU Region Limit Address Register Definitions */
pub const MPU_RLAR_LIMIT_Pos: u32 = 5;
pub const MPU_RLAR_LIMIT_Msk: u32 = (0x7FFFFFF << MPU_RLAR_LIMIT_Pos);
pub const MPU_RLAR_PXN_Pos: u32 = 4;
pub const MPU_RLAR_PXN_Msk: u32 = (1 << MPU_RLAR_PXN_Pos);
pub const MPU_RLAR_AttrIndx_Pos: u32 = 1;
pub const MPU_RLAR_AttrIndx_Msk: u32 = (0x7 << MPU_RLAR_AttrIndx_Pos);
pub const MPU_RLAR_EN_Pos: u32 = 0;
pub const MPU_RLAR_EN_Msk: u32 = (1 << MPU_RLAR_EN_Pos);

/** \brief Region Base Address Register value
* \param BASE The base address bits [31:5] of a memory region. The value is zero extended. Effective address gets 32 byte aligned.
* \param SH Defines the Shareability domain for this memory region.
* \param RO Read-Only: Set to 1 for a read-only memory region. Set to 0 for a read/write memory region.
* \param NP Non-Privileged: Set to 1 for a non-privileged memory region. Set to 0 for privileged memory region.
* \param XN eXecute Never: Set to 1 for a non-executable memory region. Set to 0 for an executable memory region.
*/
#[inline(always)]
pub const fn ARM_MPU_RBAR(BASE: u32, SH: u32, RO: u32, NP: u32, XN: u32) -> u32 {
    ((BASE & MPU_RBAR_BASE_Msk) |
     ((SH << MPU_RBAR_SH_Pos) & MPU_RBAR_SH_Msk) |
     ((ARM_MPU_AP_(RO, NP) << MPU_RBAR_AP_Pos) & MPU_RBAR_AP_Msk) |
     ((XN << MPU_RBAR_XN_Pos) & MPU_RBAR_XN_Msk))
}

/** \brief Region Limit Address Register value
* \param LIMIT The limit address bits [31:5] for this memory region. The value is one extended.
* \param IDX The attribute index to be associated with this memory region.
*/
#[inline(always)]
pub const fn ARM_MPU_RLAR(LIMIT: u32, IDX: u32) -> u32 {
    ((LIMIT & MPU_RLAR_LIMIT_Msk) |
     ((IDX << MPU_RLAR_AttrIndx_Pos) & MPU_RLAR_AttrIndx_Msk) |
     MPU_RLAR_EN_Msk)
}

/** \brief Region Limit Address Register with PXN value
* \param LIMIT The limit address bits [31:5] for this memory region. The value is one extended.
* \param PXN Privileged execute never. Defines whether code can be executed from this privileged region.
* \param IDX The attribute index to be associated with this memory region.
*/
#[inline(always)]
pub const fn ARM_MPU_RLAR_PXN(LIMIT: u32, PXN: u32, IDX: u32) -> u32 {
    ((LIMIT & MPU_RLAR_LIMIT_Msk) |
     ((PXN << MPU_RLAR_PXN_Pos) & MPU_RLAR_PXN_Msk) |
     ((IDX << MPU_RLAR_AttrIndx_Pos) & MPU_RLAR_AttrIndx_Msk) |
     MPU_RLAR_EN_Msk)
}

/**
* Struct for a single MPU Region
*/
#[repr(C)]
pub struct ARM_MPU_Region_t {
    pub RBAR: u32,
    pub RLAR: u32,
}

/**
  \brief  Read MPU Type Register
  \return Number of MPU regions
*/
#[inline(always)]
pub unsafe fn ARM_MPU_TYPE() -> u32 {
    let pmu = MPU();
    ptr::read_volatile(&(*pmu).TYPE) >> 8
}

/** Enable the MPU.
* \param MPU_Control Default access permissions for unconfigured regions.
*/
#[inline(always)]
pub unsafe fn ARM_MPU_Enable(MPU_Control: u32) {
    intrinsics::__dmb();
    let pmu = MPU();
    ptr::write_volatile(&mut (*pmu).CTRL, MPU_Control | MPU_CTRL_ENABLE_Msk);
    intrinsics::__dsb();
    intrinsics::__isb();
}

/** Disable the MPU.
*/
#[inline(always)]
pub unsafe fn ARM_MPU_Disable() {
    intrinsics::__dmb();
    let pmu = MPU();
    let ctrl = ptr::read_volatile(&(*pmu).CTRL);
    ptr::write_volatile(&mut (*pmu).CTRL, ctrl & !MPU_CTRL_ENABLE_Msk);
    intrinsics::__dsb();
    intrinsics::__isb();
}

/** Set the memory attribute encoding to the given MPU.
* \param mpu Pointer to the MPU to be configured.
* \param idx The attribute index to be set [0-7]
* \param attr The attribute value to be set.
*/
#[inline(always)]
pub unsafe fn ARM_MPU_SetMemAttrEx(mpu: *mut Mpu, idx: u8, attr: u8) {
    let reg = idx / 4;
    let pos = ((idx % 4) as u32) * 8;
    let mask: u32 = 0xFF << pos;

    if (reg as usize) >= 2 {
        return;
    }

    let mair = ptr::read_volatile(&(*mpu).MAIR[reg as usize]);
    ptr::write_volatile(&mut (*mpu).MAIR[reg as usize], (mair & !mask) | (((attr as u32) << pos) & mask));
}

/** Set the memory attribute encoding.
* \param idx The attribute index to be set [0-7]
* \param attr The attribute value to be set.
*/
#[inline(always)]
pub unsafe fn ARM_MPU_SetMemAttr(idx: u8, attr: u8) {
    ARM_MPU_SetMemAttrEx(MPU(), idx, attr);
}

/** Clear and disable the given MPU region of the given MPU.
* \param mpu Pointer to MPU to be used.
* \param rnr Region number to be cleared.
*/
#[inline(always)]
pub unsafe fn ARM_MPU_ClrRegionEx(mpu: *mut Mpu, rnr: u32) {
    ptr::write_volatile(&mut (*mpu).RNR, rnr);
    ptr::write_volatile(&mut (*mpu).RLAR, 0);
}

/** Clear and disable the given MPU region.
* \param rnr Region number to be cleared.
*/
#[inline(always)]
pub unsafe fn ARM_MPU_ClrRegion(rnr: u32) {
    ARM_MPU_ClrRegionEx(MPU(), rnr);
}

/** Configure the given MPU region of the given MPU.
* \param mpu Pointer to MPU to be used.
* \param rnr Region number to be configured.
* \param rbar Value for RBAR register.
* \param rlar Value for RLAR register.
*/
#[inline(always)]
pub unsafe fn ARM_MPU_SetRegionEx(mpu: *mut Mpu, rnr: u32, rbar: u32, rlar: u32) {
    ptr::write_volatile(&mut (*mpu).RNR, rnr);
    ptr::write_volatile(&mut (*mpu).RBAR, rbar);
    ptr::write_volatile(&mut (*mpu).RLAR, rlar);
}

/** Configure the given MPU region.
* \param rnr Region number to be configured.
* \param rbar Value for RBAR register.
* \param rlar Value for RLAR register.
*/
#[inline(always)]
pub unsafe fn ARM_MPU_SetRegion(rnr: u32, rbar: u32, rlar: u32) {
    ARM_MPU_SetRegionEx(MPU(), rnr, rbar, rlar);
}

/** Memcpy with strictly ordered memory access, e.g. used by code in ARM_MPU_LoadEx()
* \param dst Destination data is copied to.
* \param src Source data is copied from.
* \param len Amount of data words to be copied.
*/
#[inline(always)]
pub unsafe fn ARM_MPU_OrderedMemcpy(dst: *mut u32, src: *const u32, len: u32) {
    let mut i = 0;
    while i < len {
        *dst.offset(i as isize) = *src.offset(i as isize);
        i += 1;
    }
}

/** Load the given number of MPU regions from a table to the given MPU.
* \param mpu Pointer to the MPU registers to be used.
* \param rnr First region number to be configured.
* \param table Pointer to the MPU configuration table.
* \param cnt Amount of regions to be configured.
*/
#[inline(always)]
pub unsafe fn ARM_MPU_LoadEx(mpu: *mut Mpu, rnr: u32, table: *const ARM_MPU_Region_t, mut cnt: u32) {
    let row_word_size = core::mem::size_of::<ARM_MPU_Region_t>() / 4;
    if cnt == 1 {
        ptr::write_volatile(&mut (*mpu).RNR, rnr);
        ARM_MPU_OrderedMemcpy(&mut (*mpu).RBAR, &(*table).RBAR as *const u32, row_word_size as u32);
    } else {
        let mut rnr_base = rnr & !(MPU_TYPE_RALIASES - 1);
        let mut rnr_offset = rnr % MPU_TYPE_RALIASES;
        let mut table_ptr = table;

        ptr::write_volatile(&mut (*mpu).RNR, rnr_base);
        while (rnr_offset + cnt) > MPU_TYPE_RALIASES {
            let c = MPU_TYPE_RALIASES - rnr_offset;
            ARM_MPU_OrderedMemcpy(
                (&mut (*mpu).RBAR as *mut u32).offset((rnr_offset * 2) as isize),
                &(*table_ptr).RBAR as *const u32,
                c * row_word_size as u32
            );
            table_ptr = table_ptr.offset(c as isize);
            cnt -= c;
            rnr_offset = 0;
            rnr_base += MPU_TYPE_RALIASES;
            ptr::write_volatile(&mut (*mpu).RNR, rnr_base);
        }

        ARM_MPU_OrderedMemcpy(
            (&mut (*mpu).RBAR as *mut u32).offset((rnr_offset * 2) as isize),
            &(*table_ptr).RBAR as *const u32,
            cnt * row_word_size as u32
        );
    }
}

/** Load the given number of MPU regions from a table.
* \param rnr First region number to be configured.
* \param table Pointer to the MPU configuration table.
* \param cnt Amount of regions to be configured.
*/
#[inline(always)]
pub unsafe fn ARM_MPU_Load(rnr: u32, table: *const ARM_MPU_Region_t, cnt: u32) {
    ARM_MPU_LoadEx(MPU(), rnr, table, cnt);
}
