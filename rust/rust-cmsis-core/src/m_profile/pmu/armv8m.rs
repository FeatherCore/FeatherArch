/*
 * Copyright (c) 2020 Arm Limited. All rights reserved.
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
 * CMSIS-Core(M) PMU API for Armv8.1-M PMU
 */

#![allow(non_snake_case)]
#![allow(non_upper_case_globals)]

use core::ptr;

const PMU_NUM_EVENTCNT: usize = 31;

const PMU_BASE: usize = 0xE0003000;

#[repr(C)]
pub struct Pmu {
    pub EVCNTR: [u32; PMU_NUM_EVENTCNT],
    pub CCNTR: u32,
    _reserved1: [u32; 224],
    pub EVTYPER: [u32; PMU_NUM_EVENTCNT],
    pub CCFILTR: u32,
    _reserved2: [u32; 480],
    pub CNTENSET: u32,
    _reserved3: [u32; 7],
    pub CNTENCLR: u32,
    _reserved4: [u32; 7],
    pub INTENSET: u32,
    _reserved5: [u32; 7],
    pub INTENCLR: u32,
    _reserved6: [u32; 7],
    pub OVSCLR: u32,
    _reserved7: [u32; 7],
    pub SWINC: u32,
    _reserved8: [u32; 7],
    pub OVSSET: u32,
    _reserved9: [u32; 79],
    pub TYPE: u32,
    pub CTRL: u32,
    _reserved10: [u32; 108],
    pub AUTHSTATUS: u32,
    pub DEVARCH: u32,
    _reserved11: [u32; 3],
    pub DEVTYPE: u32,
}

pub const PMU_EVCNTR_CNT_Pos: u32 = 0;
pub const PMU_EVCNTR_CNT_Msk: u32 = 0xFFFF << PMU_EVCNTR_CNT_Pos;

pub const PMU_CTRL_ENABLE_Pos: u32 = 0;
pub const PMU_CTRL_ENABLE_Msk: u32 = 1 << PMU_CTRL_ENABLE_Pos;

pub const PMU_CTRL_EVENTCNT_RESET_Pos: u32 = 1;
pub const PMU_CTRL_EVENTCNT_RESET_Msk: u32 = 1 << PMU_CTRL_EVENTCNT_RESET_Pos;

pub const PMU_CTRL_CYCCNT_RESET_Pos: u32 = 2;
pub const PMU_CTRL_CYCCNT_RESET_Msk: u32 = 1 << PMU_CTRL_CYCCNT_RESET_Pos;

pub const PMU_CTRL_CYCCNT_DISABLE_Pos: u32 = 5;
pub const PMU_CTRL_CYCCNT_DISABLE_Msk: u32 = 1 << PMU_CTRL_CYCCNT_DISABLE_Pos;

pub const PMU_CTRL_FRZ_ON_OV_Pos: u32 = 9;
pub const PMU_CTRL_FRZ_ON_OV_Msk: u32 = 1 << PMU_CTRL_FRZ_ON_OV_Pos;

pub const PMU_CTRL_TRACE_ON_OV_Pos: u32 = 11;
pub const PMU_CTRL_TRACE_ON_OV_Msk: u32 = 1 << PMU_CTRL_TRACE_ON_OV_Pos;

#[inline(always)]
fn PMU() -> *mut Pmu {
    PMU_BASE as *mut Pmu
}

pub const ARM_PMU_SW_INCR: u16 = 0x0000;
pub const ARM_PMU_L1I_CACHE_REFILL: u16 = 0x0001;
pub const ARM_PMU_L1D_CACHE_REFILL: u16 = 0x0003;
pub const ARM_PMU_L1D_CACHE: u16 = 0x0004;
pub const ARM_PMU_LD_RETIRED: u16 = 0x0006;
pub const ARM_PMU_ST_RETIRED: u16 = 0x0007;
pub const ARM_PMU_INST_RETIRED: u16 = 0x0008;
pub const ARM_PMU_EXC_TAKEN: u16 = 0x0009;
pub const ARM_PMU_EXC_RETURN: u16 = 0x000A;
pub const ARM_PMU_PC_WRITE_RETIRED: u16 = 0x000C;
pub const ARM_PMU_BR_IMMED_RETIRED: u16 = 0x000D;
pub const ARM_PMU_BR_RETURN_RETIRED: u16 = 0x000E;
pub const ARM_PMU_UNALIGNED_LDST_RETIRED: u16 = 0x000F;
pub const ARM_PMU_BR_MIS_PRED: u16 = 0x0010;
pub const ARM_PMU_CPU_CYCLES: u16 = 0x0011;
pub const ARM_PMU_BR_PRED: u16 = 0x0012;
pub const ARM_PMU_MEM_ACCESS: u16 = 0x0013;
pub const ARM_PMU_L1I_CACHE_ACCESS: u16 = 0x0014;
pub const ARM_PMU_L1D_CACHE_WB: u16 = 0x0015;
pub const ARM_PMU_L2D_CACHE: u16 = 0x0016;
pub const ARM_PMU_L2D_CACHE_REFILL: u16 = 0x0017;
pub const ARM_PMU_L2D_CACHE_WB: u16 = 0x0018;
pub const ARM_PMU_BUS_ACCESS: u16 = 0x0019;
pub const ARM_PMU_MEMORY_ERROR: u16 = 0x001A;
pub const ARM_PMU_INST_SPEC: u16 = 0x001B;
pub const ARM_PMU_BUS_CYCLES: u16 = 0x001D;
pub const ARM_PMU_CHAIN: u16 = 0x001E;
pub const ARM_PMU_L1D_CACHE_ALLOCATE: u16 = 0x001F;
pub const ARM_PMU_L2D_CACHE_ALLOCATE: u16 = 0x0020;
pub const ARM_PMU_BR_RETIRED: u16 = 0x0021;
pub const ARM_PMU_BR_MIS_PRED_RETIRED: u16 = 0x0022;
pub const ARM_PMU_STALL_FRONTEND: u16 = 0x0023;
pub const ARM_PMU_STALL_BACKEND: u16 = 0x0024;
pub const ARM_PMU_L2I_CACHE: u16 = 0x0027;
pub const ARM_PMU_L2I_CACHE_REFILL: u16 = 0x0028;
pub const ARM_PMU_L3D_CACHE_ALLOCATE: u16 = 0x0029;
pub const ARM_PMU_L3D_CACHE_REFILL: u16 = 0x002A;
pub const ARM_PMU_L3D_CACHE: u16 = 0x002B;
pub const ARM_PMU_L3D_CACHE_WB: u16 = 0x002C;
pub const ARM_PMU_LL_CACHE_RD: u16 = 0x0036;
pub const ARM_PMU_LL_CACHE_MISS_RD: u16 = 0x0037;
pub const ARM_PMU_L1D_CACHE_MISS_RD: u16 = 0x0039;
pub const ARM_PMU_OP_COMPLETE: u16 = 0x003A;
pub const ARM_PMU_OP_SPEC: u16 = 0x003B;
pub const ARM_PMU_STALL: u16 = 0x003C;
pub const ARM_PMU_STALL_OP_BACKEND: u16 = 0x003D;
pub const ARM_PMU_STALL_OP_FRONTEND: u16 = 0x003E;
pub const ARM_PMU_STALL_OP: u16 = 0x003F;
pub const ARM_PMU_L1D_CACHE_RD: u16 = 0x0040;
pub const ARM_PMU_LE_RETIRED: u16 = 0x0100;
pub const ARM_PMU_LE_SPEC: u16 = 0x0101;
pub const ARM_PMU_BF_RETIRED: u16 = 0x0104;
pub const ARM_PMU_BF_SPEC: u16 = 0x0105;
pub const ARM_PMU_LE_CANCEL: u16 = 0x0108;
pub const ARM_PMU_BF_CANCEL: u16 = 0x0109;
pub const ARM_PMU_SE_CALL_S: u16 = 0x0114;
pub const ARM_PMU_SE_CALL_NS: u16 = 0x0115;
pub const ARM_PMU_DWT_CMPMATCH0: u16 = 0x0118;
pub const ARM_PMU_DWT_CMPMATCH1: u16 = 0x0119;
pub const ARM_PMU_DWT_CMPMATCH2: u16 = 0x011A;
pub const ARM_PMU_DWT_CMPMATCH3: u16 = 0x011B;
pub const ARM_PMU_MVE_INST_RETIRED: u16 = 0x0200;
pub const ARM_PMU_MVE_INST_SPEC: u16 = 0x0201;
pub const ARM_PMU_MVE_FP_RETIRED: u16 = 0x0204;
pub const ARM_PMU_MVE_FP_SPEC: u16 = 0x0205;
pub const ARM_PMU_MVE_FP_HP_RETIRED: u16 = 0x0208;
pub const ARM_PMU_MVE_FP_HP_SPEC: u16 = 0x0209;
pub const ARM_PMU_MVE_FP_SP_RETIRED: u16 = 0x020C;
pub const ARM_PMU_MVE_FP_SP_SPEC: u16 = 0x020D;
pub const ARM_PMU_MVE_FP_MAC_RETIRED: u16 = 0x0214;
pub const ARM_PMU_MVE_FP_MAC_SPEC: u16 = 0x0215;
pub const ARM_PMU_MVE_INT_RETIRED: u16 = 0x0224;
pub const ARM_PMU_MVE_INT_SPEC: u16 = 0x0225;
pub const ARM_PMU_MVE_INT_MAC_RETIRED: u16 = 0x0228;
pub const ARM_PMU_MVE_INT_MAC_SPEC: u16 = 0x0229;
pub const ARM_PMU_MVE_LDST_RETIRED: u16 = 0x0238;
pub const ARM_PMU_MVE_LDST_SPEC: u16 = 0x0239;
pub const ARM_PMU_MVE_LD_RETIRED: u16 = 0x023C;
pub const ARM_PMU_MVE_LD_SPEC: u16 = 0x023D;
pub const ARM_PMU_MVE_ST_RETIRED: u16 = 0x0240;
pub const ARM_PMU_MVE_ST_SPEC: u16 = 0x0241;
pub const ARM_PMU_MVE_LDST_CONTIG_RETIRED: u16 = 0x0244;
pub const ARM_PMU_MVE_LDST_CONTIG_SPEC: u16 = 0x0245;
pub const ARM_PMU_MVE_LD_CONTIG_RETIRED: u16 = 0x0248;
pub const ARM_PMU_MVE_LD_CONTIG_SPEC: u16 = 0x0249;
pub const ARM_PMU_MVE_ST_CONTIG_RETIRED: u16 = 0x024C;
pub const ARM_PMU_MVE_ST_CONTIG_SPEC: u16 = 0x024D;
pub const ARM_PMU_MVE_LDST_NONCONTIG_RETIRED: u16 = 0x0250;
pub const ARM_PMU_MVE_LDST_NONCONTIG_SPEC: u16 = 0x0251;
pub const ARM_PMU_MVE_LD_NONCONTIG_RETIRED: u16 = 0x0254;
pub const ARM_PMU_MVE_LD_NONCONTIG_SPEC: u16 = 0x0255;
pub const ARM_PMU_MVE_ST_NONCONTIG_RETIRED: u16 = 0x0258;
pub const ARM_PMU_MVE_ST_NONCONTIG_SPEC: u16 = 0x0259;
pub const ARM_PMU_MVE_LDST_MULTI_RETIRED: u16 = 0x025C;
pub const ARM_PMU_MVE_LDST_MULTI_SPEC: u16 = 0x025D;
pub const ARM_PMU_MVE_LD_MULTI_RETIRED: u16 = 0x0260;
pub const ARM_PMU_MVE_LD_MULTI_SPEC: u16 = 0x0261;
pub const ARM_PMU_MVE_ST_MULTI_RETIRED: u16 = 0x0261;
pub const ARM_PMU_MVE_ST_MULTI_SPEC: u16 = 0x0265;
pub const ARM_PMU_MVE_LDST_UNALIGNED_RETIRED: u16 = 0x028C;
pub const ARM_PMU_MVE_LDST_UNALIGNED_SPEC: u16 = 0x028D;
pub const ARM_PMU_MVE_LD_UNALIGNED_RETIRED: u16 = 0x0290;
pub const ARM_PMU_MVE_LD_UNALIGNED_SPEC: u16 = 0x0291;
pub const ARM_PMU_MVE_ST_UNALIGNED_RETIRED: u16 = 0x0294;
pub const ARM_PMU_MVE_ST_UNALIGNED_SPEC: u16 = 0x0295;
pub const ARM_PMU_MVE_LDST_UNALIGNED_NONCONTIG_RETIRED: u16 = 0x0298;
pub const ARM_PMU_MVE_LDST_UNALIGNED_NONCONTIG_SPEC: u16 = 0x0299;
pub const ARM_PMU_MVE_VREDUCE_RETIRED: u16 = 0x02A0;
pub const ARM_PMU_MVE_VREDUCE_SPEC: u16 = 0x02A1;
pub const ARM_PMU_MVE_VREDUCE_FP_RETIRED: u16 = 0x02A4;
pub const ARM_PMU_MVE_VREDUCE_FP_SPEC: u16 = 0x02A5;
pub const ARM_PMU_MVE_VREDUCE_INT_RETIRED: u16 = 0x02A8;
pub const ARM_PMU_MVE_VREDUCE_INT_SPEC: u16 = 0x02A9;
pub const ARM_PMU_MVE_PRED: u16 = 0x02B8;
pub const ARM_PMU_MVE_STALL: u16 = 0x02CC;
pub const ARM_PMU_MVE_STALL_RESOURCE: u16 = 0x02CD;
pub const ARM_PMU_MVE_STALL_RESOURCE_MEM: u16 = 0x02CE;
pub const ARM_PMU_MVE_STALL_RESOURCE_FP: u16 = 0x02CF;
pub const ARM_PMU_MVE_STALL_RESOURCE_INT: u16 = 0x02D0;
pub const ARM_PMU_MVE_STALL_BREAK: u16 = 0x02D3;
pub const ARM_PMU_MVE_STALL_DEPENDENCY: u16 = 0x02D4;
pub const ARM_PMU_ITCM_ACCESS: u16 = 0x4007;
pub const ARM_PMU_DTCM_ACCESS: u16 = 0x4008;
pub const ARM_PMU_TRCEXTOUT0: u16 = 0x4010;
pub const ARM_PMU_TRCEXTOUT1: u16 = 0x4011;
pub const ARM_PMU_TRCEXTOUT2: u16 = 0x4012;
pub const ARM_PMU_TRCEXTOUT3: u16 = 0x4013;
pub const ARM_PMU_CTI_TRIGOUT4: u16 = 0x4018;
pub const ARM_PMU_CTI_TRIGOUT5: u16 = 0x4019;
pub const ARM_PMU_CTI_TRIGOUT6: u16 = 0x401A;
pub const ARM_PMU_CTI_TRIGOUT7: u16 = 0x401B;

/**
  \brief   Enable the PMU
*/
#[inline(always)]
pub unsafe fn ARM_PMU_Enable() {
    let pmu = PMU();
    let ctrl = ptr::read_volatile(&(*pmu).CTRL);
    ptr::write_volatile(&mut (*pmu).CTRL, ctrl | PMU_CTRL_ENABLE_Msk);
}

/**
  \brief   Disable the PMU
*/
#[inline(always)]
pub unsafe fn ARM_PMU_Disable() {
    let pmu = PMU();
    let ctrl = ptr::read_volatile(&(*pmu).CTRL);
    ptr::write_volatile(&mut (*pmu).CTRL, ctrl & !PMU_CTRL_ENABLE_Msk);
}

/**
  \brief   Set event to count for PMU eventer counter
  \param [in]    num     Event counter (0-30) to configure
  \param [in]    type    Event to count
*/
#[inline(always)]
pub unsafe fn ARM_PMU_Set_EVTYPER(num: u32, type_: u32) {
    let pmu = PMU();
    ptr::write_volatile(&mut (*pmu).EVTYPER[num as usize], type_);
}

/**
  \brief  Reset cycle counter
*/
#[inline(always)]
pub unsafe fn ARM_PMU_CYCCNT_Reset() {
    let pmu = PMU();
    let ctrl = ptr::read_volatile(&(*pmu).CTRL);
    ptr::write_volatile(&mut (*pmu).CTRL, ctrl | PMU_CTRL_CYCCNT_RESET_Msk);
}

/**
  \brief  Reset all event counters
*/
#[inline(always)]
pub unsafe fn ARM_PMU_EVCNTR_ALL_Reset() {
    let pmu = PMU();
    let ctrl = ptr::read_volatile(&(*pmu).CTRL);
    ptr::write_volatile(&mut (*pmu).CTRL, ctrl | PMU_CTRL_EVENTCNT_RESET_Msk);
}

/**
  \brief  Enable counters
  \param [in]     mask    Counters to enable
  \note   Enables one or more of the following:
          - event counters (0-30)
          - cycle counter
*/
#[inline(always)]
pub unsafe fn ARM_PMU_CNTR_Enable(mask: u32) {
    let pmu = PMU();
    ptr::write_volatile(&mut (*pmu).CNTENSET, mask);
}

/**
  \brief  Disable counters
  \param [in]     mask    Counters to enable
  \note   Disables one or more of the following:
          - event counters (0-30)
          - cycle counter
*/
#[inline(always)]
pub unsafe fn ARM_PMU_CNTR_Disable(mask: u32) {
    let pmu = PMU();
    ptr::write_volatile(&mut (*pmu).CNTENCLR, mask);
}

/**
  \brief  Read cycle counter
  \return                 Cycle count
*/
#[inline(always)]
pub unsafe fn ARM_PMU_Get_CCNTR() -> u32 {
    let pmu = PMU();
    ptr::read_volatile(&(*pmu).CCNTR)
}

/**
  \brief   Read event counter
  \param [in]     num     Event counter (0-30) to read
  \return                 Event count
*/
#[inline(always)]
pub unsafe fn ARM_PMU_Get_EVCNTR(num: u32) -> u32 {
    let pmu = PMU();
    PMU_EVCNTR_CNT_Msk & ptr::read_volatile(&(*pmu).EVCNTR[num as usize])
}

/**
  \brief   Read counter overflow status
  \return  Counter overflow status bits for the following:
          - event counters (0-30)
          - cycle counter
*/
#[inline(always)]
pub unsafe fn ARM_PMU_Get_CNTR_OVS() -> u32 {
    let pmu = PMU();
    ptr::read_volatile(&(*pmu).OVSSET)
}

/**
  \brief   Clear counter overflow status
  \param [in]     mask    Counter overflow status bits to clear
  \note    Clears overflow status bits for one or more of the following:
           - event counters (0-30)
           - cycle counter
*/
#[inline(always)]
pub unsafe fn ARM_PMU_Set_CNTR_OVS(mask: u32) {
    let pmu = PMU();
    ptr::write_volatile(&mut (*pmu).OVSCLR, mask);
}

/**
  \brief   Enable counter overflow interrupt request
  \param [in]     mask    Counter overflow interrupt request bits to set
  \note    Sets overflow interrupt request bits for one or more of the following:
           - event counters (0-30)
           - cycle counter
*/
#[inline(always)]
pub unsafe fn ARM_PMU_Set_CNTR_IRQ_Enable(mask: u32) {
    let pmu = PMU();
    ptr::write_volatile(&mut (*pmu).INTENSET, mask);
}

/**
  \brief   Disable counter overflow interrupt request
  \param [in]     mask    Counter overflow interrupt request bits to clear
  \note    Clears overflow interrupt request bits for one or more of the following:
           - event counters (0-30)
           - cycle counter
*/
#[inline(always)]
pub unsafe fn ARM_PMU_Set_CNTR_IRQ_Disable(mask: u32) {
    let pmu = PMU();
    ptr::write_volatile(&mut (*pmu).INTENCLR, mask);
}

/**
  \brief   Software increment event counter
  \param [in]     mask    Counters to increment
  \note    Software increment bits for one or more event counters (0-30)
*/
#[inline(always)]
pub unsafe fn ARM_PMU_CNTR_Increment(mask: u32) {
    let pmu = PMU();
    ptr::write_volatile(&mut (*pmu).SWINC, mask);
}
