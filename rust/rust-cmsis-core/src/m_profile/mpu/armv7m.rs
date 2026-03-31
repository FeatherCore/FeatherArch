/*
 * Copyright (c) 2017-2020 Arm Limited. All rights reserved.
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
 * CMSIS-Core(M) MPU API for Armv7-M MPU
 */

#![allow(non_snake_case)]

use crate::intrinsics;

/// MPU Type Register
pub const MPU_TYPE: *mut u32 = 0xE000ED90 as *mut u32;
/// MPU Control Register
pub const MPU_CTRL: *mut u32 = 0xE000ED94 as *mut u32;
/// MPU Region Number Register
pub const MPU_RNR: *mut u32 = 0xE000ED98 as *mut u32;
/// MPU Region Base Address Register
pub const MPU_RBAR: *mut u32 = 0xE000ED9C as *mut u32;
/// MPU Region Attribute and Size Register
pub const MPU_RASR: *mut u32 = 0xE000EDA0 as *mut u32;

/// MPU Control Register: Enable MPU
pub const MPU_CTRL_ENABLE_Pos: u32 = 0;
pub const MPU_CTRL_ENABLE_Msk: u32 = 1 << MPU_CTRL_ENABLE_Pos;
/// MPU Control Register: Enable MPU during HardFault and NMI
pub const MPU_CTRL_HFNMIENA_Pos: u32 = 1;
pub const MPU_CTRL_HFNMIENA_Msk: u32 = 1 << MPU_CTRL_HFNMIENA_Pos;
/// MPU Control Register: Enable privileged software access to default memory map
pub const MPU_CTRL_PRIVDEFENA_Pos: u32 = 2;
pub const MPU_CTRL_PRIVDEFENA_Msk: u32 = 1 << MPU_CTRL_PRIVDEFENA_Pos;

/// MPU Region Number Register: Region
pub const MPU_RNR_REGION_Pos: u32 = 0;
pub const MPU_RNR_REGION_Msk: u32 = 0xFF << MPU_RNR_REGION_Pos;

/// MPU Region Base Address Register: Region
pub const MPU_RBAR_REGION_Pos: u32 = 0;
pub const MPU_RBAR_REGION_Msk: u32 = 0xF << MPU_RBAR_REGION_Pos;
/// MPU Region Base Address Register: Valid
pub const MPU_RBAR_VALID_Pos: u32 = 4;
pub const MPU_RBAR_VALID_Msk: u32 = 1 << MPU_RBAR_VALID_Pos;
/// MPU Region Base Address Register: Address
pub const MPU_RBAR_ADDR_Pos: u32 = 5;
pub const MPU_RBAR_ADDR_Msk: u32 = 0x1FFFFFFF << MPU_RBAR_ADDR_Pos;

/// MPU Region Attribute and Size Register: Enable
pub const MPU_RASR_ENABLE_Pos: u32 = 0;
pub const MPU_RASR_ENABLE_Msk: u32 = 1 << MPU_RASR_ENABLE_Pos;
/// MPU Region Attribute and Size Register: Size
pub const MPU_RASR_SIZE_Pos: u32 = 1;
pub const MPU_RASR_SIZE_Msk: u32 = 0x1F << MPU_RASR_SIZE_Pos;
/// MPU Region Attribute and Size Register: Sub-Region Disable
pub const MPU_RASR_SRD_Pos: u32 = 8;
pub const MPU_RASR_SRD_Msk: u32 = 0xFF << MPU_RASR_SRD_Pos;
/// MPU Region Attribute and Size Register: Bufferable
pub const MPU_RASR_B_Pos: u32 = 16;
pub const MPU_RASR_B_Msk: u32 = 1 << MPU_RASR_B_Pos;
/// MPU Region Attribute and Size Register: Cacheable
pub const MPU_RASR_C_Pos: u32 = 17;
pub const MPU_RASR_C_Msk: u32 = 1 << MPU_RASR_C_Pos;
/// MPU Region Attribute and Size Register: Shareable
pub const MPU_RASR_S_Pos: u32 = 18;
pub const MPU_RASR_S_Msk: u32 = 1 << MPU_RASR_S_Pos;
/// MPU Region Attribute and Size Register: Type Extension
pub const MPU_RASR_TEX_Pos: u32 = 19;
pub const MPU_RASR_TEX_Msk: u32 = 0x7 << MPU_RASR_TEX_Pos;
/// MPU Region Attribute and Size Register: Access Permission
pub const MPU_RASR_AP_Pos: u32 = 24;
pub const MPU_RASR_AP_Msk: u32 = 0x7 << MPU_RASR_AP_Pos;
/// MPU Region Attribute and Size Register: Execute Never
pub const MPU_RASR_XN_Pos: u32 = 28;
pub const MPU_RASR_XN_Msk: u32 = 1 << MPU_RASR_XN_Pos;

/// MPU Region Size 32 Bytes
pub const ARM_MPU_REGION_SIZE_32B: u8 = 0x04;
/// MPU Region Size 64 Bytes
pub const ARM_MPU_REGION_SIZE_64B: u8 = 0x05;
/// MPU Region Size 128 Bytes
pub const ARM_MPU_REGION_SIZE_128B: u8 = 0x06;
/// MPU Region Size 256 Bytes
pub const ARM_MPU_REGION_SIZE_256B: u8 = 0x07;
/// MPU Region Size 512 Bytes
pub const ARM_MPU_REGION_SIZE_512B: u8 = 0x08;
/// MPU Region Size 1 KByte
pub const ARM_MPU_REGION_SIZE_1KB: u8 = 0x09;
/// MPU Region Size 2 KBytes
pub const ARM_MPU_REGION_SIZE_2KB: u8 = 0x0A;
/// MPU Region Size 4 KBytes
pub const ARM_MPU_REGION_SIZE_4KB: u8 = 0x0B;
/// MPU Region Size 8 KBytes
pub const ARM_MPU_REGION_SIZE_8KB: u8 = 0x0C;
/// MPU Region Size 16 KBytes
pub const ARM_MPU_REGION_SIZE_16KB: u8 = 0x0D;
/// MPU Region Size 32 KBytes
pub const ARM_MPU_REGION_SIZE_32KB: u8 = 0x0E;
/// MPU Region Size 64 KBytes
pub const ARM_MPU_REGION_SIZE_64KB: u8 = 0x0F;
/// MPU Region Size 128 KBytes
pub const ARM_MPU_REGION_SIZE_128KB: u8 = 0x10;
/// MPU Region Size 256 KBytes
pub const ARM_MPU_REGION_SIZE_256KB: u8 = 0x11;
/// MPU Region Size 512 KBytes
pub const ARM_MPU_REGION_SIZE_512KB: u8 = 0x12;
/// MPU Region Size 1 MByte
pub const ARM_MPU_REGION_SIZE_1MB: u8 = 0x13;
/// MPU Region Size 2 MBytes
pub const ARM_MPU_REGION_SIZE_2MB: u8 = 0x14;
/// MPU Region Size 4 MBytes
pub const ARM_MPU_REGION_SIZE_4MB: u8 = 0x15;
/// MPU Region Size 8 MBytes
pub const ARM_MPU_REGION_SIZE_8MB: u8 = 0x16;
/// MPU Region Size 16 MBytes
pub const ARM_MPU_REGION_SIZE_16MB: u8 = 0x17;
/// MPU Region Size 32 MBytes
pub const ARM_MPU_REGION_SIZE_32MB: u8 = 0x18;
/// MPU Region Size 64 MBytes
pub const ARM_MPU_REGION_SIZE_64MB: u8 = 0x19;
/// MPU Region Size 128 MBytes
pub const ARM_MPU_REGION_SIZE_128MB: u8 = 0x1A;
/// MPU Region Size 256 MBytes
pub const ARM_MPU_REGION_SIZE_256MB: u8 = 0x1B;
/// MPU Region Size 512 MBytes
pub const ARM_MPU_REGION_SIZE_512MB: u8 = 0x1C;
/// MPU Region Size 1 GByte
pub const ARM_MPU_REGION_SIZE_1GB: u8 = 0x1D;
/// MPU Region Size 2 GBytes
pub const ARM_MPU_REGION_SIZE_2GB: u8 = 0x1E;
/// MPU Region Size 4 GBytes
pub const ARM_MPU_REGION_SIZE_4GB: u8 = 0x1F;

/// MPU Access Permission no access
pub const ARM_MPU_AP_NONE: u32 = 0;
/// MPU Access Permission privileged access only
pub const ARM_MPU_AP_PRIV: u32 = 1;
/// MPU Access Permission unprivileged access read-only
pub const ARM_MPU_AP_URO: u32 = 2;
/// MPU Access Permission full access
pub const ARM_MPU_AP_FULL: u32 = 3;
/// MPU Access Permission privileged access read-only
pub const ARM_MPU_AP_PRO: u32 = 5;
/// MPU Access Permission read-only access
pub const ARM_MPU_AP_RO: u32 = 6;

/// MPU Memory Access Attribute non-cacheable policy.
pub const ARM_MPU_CACHEP_NOCACHE: u32 = 0;
/// MPU Memory Access Attribute write-back, write and read allocate policy.
pub const ARM_MPU_CACHEP_WB_WRA: u32 = 1;
/// MPU Memory Access Attribute write-through, no write allocate policy.
pub const ARM_MPU_CACHEP_WT_NWA: u32 = 2;
/// MPU Memory Access Attribute write-back, no write allocate policy.
pub const ARM_MPU_CACHEP_WB_NWA: u32 = 3;

/// Struct for a single MPU Region
#[repr(C)]
pub struct ARM_MPU_Region_t {
    /// The region base address register value (RBAR)
    pub RBAR: u32,
    /// The region attribute and size register value (RASR)
    pub RASR: u32,
}

/// MPU Region Base Address Register Value
///
/// \param Region The region to be configured, number 0 to 15.
/// \param BaseAddress The base address for the region.
#[inline(always)]
pub const fn ARM_MPU_RBAR(Region: u32, BaseAddress: u32) -> u32 {
    ((BaseAddress) & MPU_RBAR_ADDR_Msk) | ((Region) & MPU_RBAR_REGION_Msk) | (MPU_RBAR_VALID_Msk)
}

/// MPU Memory Access Attributes
///
/// \param TypeExtField      Type extension field, allows you to configure memory access type, for example strongly ordered, peripheral.
/// \param IsShareable       Region is shareable between multiple bus masters.
/// \param IsCacheable       Region is cacheable, i.e. its value may be kept in cache.
/// \param IsBufferable      Region is bufferable, i.e. using write-back caching. Cacheable but non-bufferable regions use write-through policy.
#[inline(always)]
pub const fn ARM_MPU_ACCESS_(TypeExtField: u32, IsShareable: u32, IsCacheable: u32, IsBufferable: u32) -> u32 {
    (((TypeExtField) << MPU_RASR_TEX_Pos) & MPU_RASR_TEX_Msk) |
    (((IsShareable) << MPU_RASR_S_Pos) & MPU_RASR_S_Msk) |
    (((IsCacheable) << MPU_RASR_C_Pos) & MPU_RASR_C_Msk) |
    (((IsBufferable) << MPU_RASR_B_Pos) & MPU_RASR_B_Msk)
}

/// MPU Region Attribute and Size Register Value
///
/// \param DisableExec       Instruction access disable bit, 1= disable instruction fetches.
/// \param AccessPermission  Data access permissions, allows you to configure read/write access for User and Privileged mode.
/// \param AccessAttributes  Memory access attribution, see \ref ARM_MPU_ACCESS_.
/// \param SubRegionDisable  Sub-region disable field.
/// \param Size              Region size of the region to be configured, for example 4K, 8K.
#[inline(always)]
pub const fn ARM_MPU_RASR_EX(DisableExec: u32, AccessPermission: u32, AccessAttributes: u32, SubRegionDisable: u32, Size: u8) -> u32 {
    (((DisableExec) << MPU_RASR_XN_Pos) & MPU_RASR_XN_Msk) |
    (((AccessPermission) << MPU_RASR_AP_Pos) & MPU_RASR_AP_Msk) |
    (((AccessAttributes) & (MPU_RASR_TEX_Msk | MPU_RASR_S_Msk | MPU_RASR_C_Msk | MPU_RASR_B_Msk))) |
    (((SubRegionDisable) << MPU_RASR_SRD_Pos) & MPU_RASR_SRD_Msk) |
    (((Size as u32) << MPU_RASR_SIZE_Pos) & MPU_RASR_SIZE_Msk) |
    (MPU_RASR_ENABLE_Msk)
}

/// MPU Region Attribute and Size Register Value
///
/// \param DisableExec       Instruction access disable bit, 1= disable instruction fetches.
/// \param AccessPermission  Data access permissions, allows you to configure read/write access for User and Privileged mode.
/// \param TypeExtField      Type extension field, allows you to configure memory access type, for example strongly ordered, peripheral.
/// \param IsShareable       Region is shareable between multiple bus masters.
/// \param IsCacheable       Region is cacheable, i.e. its value may be kept in cache.
/// \param IsBufferable      Region is bufferable, i.e. using write-back caching. Cacheable but non-bufferable regions use write-through policy.
/// \param SubRegionDisable  Sub-region disable field.
/// \param Size              Region size of the region to be configured, for example 4K, 8K.
#[inline(always)]
pub const fn ARM_MPU_RASR(DisableExec: u32, AccessPermission: u32, TypeExtField: u32, IsShareable: u32, IsCacheable: u32, IsBufferable: u32, SubRegionDisable: u32, Size: u8) -> u32 {
    ARM_MPU_RASR_EX(DisableExec, AccessPermission, ARM_MPU_ACCESS_(TypeExtField, IsShareable, IsCacheable, IsBufferable), SubRegionDisable, Size)
}

/// MPU Memory Access Attribute for strongly ordered memory.
///  - TEX: 000b
///  - Shareable
///  - Non-cacheable
///  - Non-bufferable
pub const ARM_MPU_ACCESS_ORDERED: u32 = ARM_MPU_ACCESS_(0, 1, 0, 0);

/// MPU Memory Access Attribute for device memory.
///  - TEX: 000b (if shareable) or 010b (if non-shareable)
///  - Shareable or non-shareable
///  - Non-cacheable
///  - Bufferable (if shareable) or non-bufferable (if non-shareable)
///
/// \param IsShareable Configures the device memory as shareable or non-shareable.
#[inline(always)]
pub const fn ARM_MPU_ACCESS_DEVICE(IsShareable: u32) -> u32 {
    if IsShareable != 0 {
        ARM_MPU_ACCESS_(0, 1, 0, 1)
    } else {
        ARM_MPU_ACCESS_(2, 0, 0, 0)
    }
}

/// MPU Memory Access Attribute for normal memory.
///  - TEX: 1BBb (reflecting outer cacheability rules)
///  - Shareable or non-shareable
///  - Cacheable or non-cacheable (reflecting inner cacheability rules)
///  - Bufferable or non-bufferable (reflecting inner cacheability rules)
///
/// \param OuterCp Configures the outer cache policy.
/// \param InnerCp Configures the inner cache policy.
/// \param IsShareable Configures the memory as shareable or non-shareable.
#[inline(always)]
pub const fn ARM_MPU_ACCESS_NORMAL(OuterCp: u32, InnerCp: u32, IsShareable: u32) -> u32 {
    ARM_MPU_ACCESS_((4 | (OuterCp)), IsShareable, ((InnerCp) >> 1), ((InnerCp) & 1))
}

/// Enable the MPU.
///
/// \param MPU_Control Default access permissions for unconfigured regions.
#[inline(always)]
pub unsafe fn ARM_MPU_Enable(MPU_Control: u32) {
    intrinsics::__dmb();
    MPU_CTRL.write_volatile(MPU_Control | MPU_CTRL_ENABLE_Msk);
    intrinsics::__dsb();
    intrinsics::__isb();
}

/// Disable the MPU.
#[inline(always)]
pub unsafe fn ARM_MPU_Disable() {
    intrinsics::__dmb();
    MPU_CTRL.write_volatile(MPU_CTRL.read_volatile() & !MPU_CTRL_ENABLE_Msk);
    intrinsics::__dsb();
    intrinsics::__isb();
}

/// Clear and disable the given MPU region.
///
/// \param rnr Region number to be cleared.
#[inline(always)]
pub unsafe fn ARM_MPU_ClrRegion(rnr: u32) {
    MPU_RNR.write_volatile(rnr);
    MPU_RASR.write_volatile(0);
}

/// Configure an MPU region.
///
/// \param rbar Value for RBAR register.
/// \param rasr Value for RASR register.
#[inline(always)]
pub unsafe fn ARM_MPU_SetRegion(rbar: u32, rasr: u32) {
    MPU_RBAR.write_volatile(rbar);
    MPU_RASR.write_volatile(rasr);
}

/// Configure the given MPU region.
///
/// \param rnr Region number to be configured.
/// \param rbar Value for RBAR register.
/// \param rasr Value for RASR register.
#[inline(always)]
pub unsafe fn ARM_MPU_SetRegionEx(rnr: u32, rbar: u32, rasr: u32) {
    MPU_RNR.write_volatile(rnr);
    MPU_RBAR.write_volatile(rbar);
    MPU_RASR.write_volatile(rasr);
}

/// Memcpy with strictly ordered memory access, e.g. used by code in ARM_MPU_Load().
///
/// \param dst Destination data is copied to.
/// \param src Source data is copied from.
/// \param len Amount of data words to be copied.
#[inline(always)]
pub unsafe fn ARM_MPU_OrderedMemcpy(dst: *mut u32, src: *const u32, len: u32) {
    let mut i = 0;
    while i < len {
        *dst.offset(i as isize) = *src.offset(i as isize);
        i += 1;
    }
}

/// Load the given number of MPU regions from a table.
///
/// \param table Pointer to the MPU configuration table.
/// \param cnt Amount of regions to be configured.
#[inline(always)]
pub unsafe fn ARM_MPU_Load(table: *const ARM_MPU_Region_t, mut cnt: u32) {
    let rowWordSize = (core::mem::size_of::<ARM_MPU_Region_t>() / 4) as u32;
    let mut table_ptr = table;
    while cnt > 1 {
        ARM_MPU_OrderedMemcpy(MPU_RBAR, &(*table_ptr).RBAR as *const u32, 1 * rowWordSize);
        table_ptr = table_ptr.offset(1);
        cnt -= 1;
    }
    ARM_MPU_OrderedMemcpy(MPU_RBAR, &(*table_ptr).RBAR as *const u32, cnt * rowWordSize);
}
