#![allow(non_snake_case)]

use core::ptr;

/* GICDistributor CTLR Register */

/// GICDistributor CTLR: EnableGrp0 Position
pub const GICDistributor_CTLR_EnableGrp0_Pos: u32 = 0;
/// GICDistributor CTLR: EnableGrp0 Mask
pub const GICDistributor_CTLR_EnableGrp0_Msk: u32 = 1 << GICDistributor_CTLR_EnableGrp0_Pos;

/// GICDistributor CTLR: EnableGrp1 Position
pub const GICDistributor_CTLR_EnableGrp1_Pos: u32 = 1;
/// GICDistributor CTLR: EnableGrp1 Mask
pub const GICDistributor_CTLR_EnableGrp1_Msk: u32 = 1 << GICDistributor_CTLR_EnableGrp1_Pos;

/// GICDistributor CTLR: ARE Position
pub const GICDistributor_CTLR_ARE_Pos: u32 = 4;
/// GICDistributor CTLR: ARE Mask
pub const GICDistributor_CTLR_ARE_Msk: u32 = 1 << GICDistributor_CTLR_ARE_Pos;

/// GICDistributor CTLR: DC Position
pub const GICDistributor_CTLR_DC_Pos: u32 = 6;
/// GICDistributor CTLR: DC Mask
pub const GICDistributor_CTLR_DC_Msk: u32 = 1 << GICDistributor_CTLR_DC_Pos;

/// GICDistributor CTLR: EINWF Position
pub const GICDistributor_CTLR_EINWF_Pos: u32 = 7;
/// GICDistributor CTLR: EINWF Mask
pub const GICDistributor_CTLR_EINWF_Msk: u32 = 1 << GICDistributor_CTLR_EINWF_Pos;

/// GICDistributor CTLR: RWP Position
pub const GICDistributor_CTLR_RWP_Pos: u32 = 31;
/// GICDistributor CTLR: RWP Mask
pub const GICDistributor_CTLR_RWP_Msk: u32 = 1 << GICDistributor_CTLR_RWP_Pos;

/* GICDistributor TYPER Register */

/// GICDistributor TYPER: ITLinesNumber Position
pub const GICDistributor_TYPER_ITLinesNumber_Pos: u32 = 0;
/// GICDistributor TYPER: ITLinesNumber Mask
pub const GICDistributor_TYPER_ITLinesNumber_Msk: u32 = 0x1F << GICDistributor_TYPER_ITLinesNumber_Pos;

/// GICDistributor TYPER: CPUNumber Position
pub const GICDistributor_TYPER_CPUNumber_Pos: u32 = 5;
/// GICDistributor TYPER: CPUNumber Mask
pub const GICDistributor_TYPER_CPUNumber_Msk: u32 = 0x7 << GICDistributor_TYPER_CPUNumber_Pos;

/// GICDistributor TYPER: SecurityExtn Position
pub const GICDistributor_TYPER_SecurityExtn_Pos: u32 = 10;
/// GICDistributor TYPER: SecurityExtn Mask
pub const GICDistributor_TYPER_SecurityExtn_Msk: u32 = 1 << GICDistributor_TYPER_SecurityExtn_Pos;

/// GICDistributor TYPER: LSPI Position
pub const GICDistributor_TYPER_LSPI_Pos: u32 = 11;
/// GICDistributor TYPER: LSPI Mask
pub const GICDistributor_TYPER_LSPI_Msk: u32 = 0x1F << GICDistributor_TYPER_LSPI_Pos;

/* GICDistributor IIDR Register */

/// GICDistributor IIDR: Implementer Position
pub const GICDistributor_IIDR_Implementer_Pos: u32 = 0;
/// GICDistributor IIDR: Implementer Mask
pub const GICDistributor_IIDR_Implementer_Msk: u32 = 0xFFF << GICDistributor_IIDR_Implementer_Pos;

/// GICDistributor IIDR: Revision Position
pub const GICDistributor_IIDR_Revision_Pos: u32 = 12;
/// GICDistributor IIDR: Revision Mask
pub const GICDistributor_IIDR_Revision_Msk: u32 = 0xF << GICDistributor_IIDR_Revision_Pos;

/// GICDistributor IIDR: Variant Position
pub const GICDistributor_IIDR_Variant_Pos: u32 = 16;
/// GICDistributor IIDR: Variant Mask
pub const GICDistributor_IIDR_Variant_Msk: u32 = 0xF << GICDistributor_IIDR_Variant_Pos;

/// GICDistributor IIDR: ProductID Position
pub const GICDistributor_IIDR_ProductID_Pos: u32 = 24;
/// GICDistributor IIDR: ProductID Mask
pub const GICDistributor_IIDR_ProductID_Msk: u32 = 0xFF << GICDistributor_IIDR_ProductID_Pos;

/* GICInterface CTLR Register */

/// GICInterface CTLR: Enable Position
pub const GICInterface_CTLR_Enable_Pos: u32 = 0;
/// GICInterface CTLR: Enable Mask
pub const GICInterface_CTLR_Enable_Msk: u32 = 1 << GICInterface_CTLR_Enable_Pos;

/* GICInterface PMR Register */

/// GICInterface PMR: Priority Position
pub const GICInterface_PMR_Priority_Pos: u32 = 0;
/// GICInterface PMR: Priority Mask
pub const GICInterface_PMR_Priority_Msk: u32 = 0xFF << GICInterface_PMR_Priority_Pos;

/* GICInterface BPR Register */

/// GICInterface BPR: Binary_Point Position
pub const GICInterface_BPR_Binary_Point_Pos: u32 = 0;
/// GICInterface BPR: Binary_Point Mask
pub const GICInterface_BPR_Binary_Point_Msk: u32 = 0x7 << GICInterface_BPR_Binary_Point_Pos;

/* GICInterface IAR Register */

/// GICInterface IAR: INTID Position
pub const GICInterface_IAR_INTID_Pos: u32 = 0;
/// GICInterface IAR: INTID Mask
pub const GICInterface_IAR_INTID_Msk: u32 = 0xFFFFFF << GICInterface_IAR_INTID_Pos;

/* GICInterface EOIR Register */

/// GICInterface EOIR: INTID Position
pub const GICInterface_EOIR_INTID_Pos: u32 = 0;
/// GICInterface EOIR: INTID Mask
pub const GICInterface_EOIR_INTID_Msk: u32 = 0xFFFFFF << GICInterface_EOIR_INTID_Pos;

/* GICInterface RPR Register */

/// GICInterface RPR: INTID Position
pub const GICInterface_RPR_INTID_Pos: u32 = 0;
/// GICInterface RPR: INTID Mask
pub const GICInterface_RPR_INTID_Msk: u32 = 0xFF << GICInterface_RPR_INTID_Pos;

/* GICInterface HPPIR Register */

/// GICInterface HPPIR: INTID Position
pub const GICInterface_HPPIR_INTID_Pos: u32 = 0;
/// GICInterface HPPIR: INTID Mask
pub const GICInterface_HPPIR_INTID_Msk: u32 = 0x3FF << GICInterface_HPPIR_INTID_Pos;

/* GICInterface IIDR Register */

/// GICInterface IIDR: Implementer Position
pub const GICInterface_IIDR_Implementer_Pos: u32 = 0;
/// GICInterface IIDR: Implementer Mask
pub const GICInterface_IIDR_Implementer_Msk: u32 = 0xFFF << GICInterface_IIDR_Implementer_Pos;

/// GICInterface IIDR: Revision Position
pub const GICInterface_IIDR_Revision_Pos: u32 = 12;
/// GICInterface IIDR: Revision Mask
pub const GICInterface_IIDR_Revision_Msk: u32 = 0xF << GICInterface_IIDR_Revision_Pos;

/// GICInterface IIDR: Arch_version Position
pub const GICInterface_IIDR_Arch_version_Pos: u32 = 16;
/// GICInterface IIDR: Arch_version Mask
pub const GICInterface_IIDR_Arch_version_Msk: u32 = 0xF << GICInterface_IIDR_Arch_version_Pos;

/// GICInterface IIDR: ProductID Position
pub const GICInterface_IIDR_ProductID_Pos: u32 = 20;
/// GICInterface IIDR: ProductID Mask
pub const GICInterface_IIDR_ProductID_Msk: u32 = 0xFFF << GICInterface_IIDR_ProductID_Pos;

/* GICInterface DIR Register */

/// GICInterface DIR: INTID Position
pub const GICInterface_DIR_INTID_Pos: u32 = 0;
/// GICInterface DIR: INTID Mask
pub const GICInterface_DIR_INTID_Msk: u32 = 0xFFFFFF << GICInterface_DIR_INTID_Pos;

/// Structure type to access the Generic Interrupt Controller Distributor (GICD)
#[repr(C)]
pub struct GICDistributor_Type {
    pub CTLR: u32,
    pub TYPER: u32,
    pub IIDR: u32,
    _reserved0: u32,
    pub STATUSR: u32,
    _reserved1: [u32; 11],
    pub SETSPI_NSR: u32,
    _reserved2: u32,
    pub CLRSPI_NSR: u32,
    _reserved3: u32,
    pub SETSPI_SR: u32,
    _reserved4: u32,
    pub CLRSPI_SR: u32,
    _reserved5: [u32; 9],
    pub IGROUPR: [u32; 32],
    pub ISENABLER: [u32; 32],
    pub ICENABLER: [u32; 32],
    pub ISPENDR: [u32; 32],
    pub ICPENDR: [u32; 32],
    pub ISACTIVER: [u32; 32],
    pub ICACTIVER: [u32; 32],
    pub IPRIORITYR: [u32; 255],
    _reserved6: u32,
    pub ITARGETSR: [u32; 255],
    _reserved7: u32,
    pub ICFGR: [u32; 64],
    pub IGRPMODR: [u32; 32],
    _reserved8: [u32; 32],
    pub NSACR: [u32; 64],
    pub SGIR: u32,
    _reserved9: [u32; 3],
    pub CPENDSGIR: [u32; 4],
    pub SPENDSGIR: [u32; 4],
    _reserved10: [u32; 5236],
    pub IROUTER: [u64; 988],
}

/// Structure type to access the Generic Interrupt Controller Interface (GICC)
#[repr(C)]
pub struct GICInterface_Type {
    pub CTLR: u32,
    pub PMR: u32,
    pub BPR: u32,
    pub IAR: u32,
    pub EOIR: u32,
    pub RPR: u32,
    pub HPPIR: u32,
    pub ABPR: u32,
    pub AIAR: u32,
    pub AEOIR: u32,
    pub AHPPIR: u32,
    pub STATUSR: u32,
    _reserved1: [u32; 40],
    pub APR: [u32; 4],
    pub NSAPR: [u32; 4],
    _reserved2: [u32; 3],
    pub IIDR: u32,
    _reserved3: [u32; 960],
    pub DIR: u32,
}

/// GIC Distributor register set access pointer
pub static mut GICDistributor: *mut GICDistributor_Type = ptr::null_mut();

/// GIC Interface register set access pointer
pub static mut GICInterface: *mut GICInterface_Type = ptr::null_mut();

/* ##########################  GIC Functions  ###################################### */

/// Enable the interrupt distributor using the GIC's CTLR register.
pub unsafe fn GIC_EnableDistributor() {
    if !GICDistributor.is_null() {
        (*GICDistributor).CTLR |= 1;
    }
}

/// Disable the interrupt distributor using the GIC's CTLR register.
pub unsafe fn GIC_DisableDistributor() {
    if !GICDistributor.is_null() {
        (*GICDistributor).CTLR &= !1;
    }
}

/// Read the GIC's TYPER register.
/// \return GICDistributor_Type::TYPER
pub unsafe fn GIC_DistributorInfo() -> u32 {
    if GICDistributor.is_null() {
        0
    } else {
        (*GICDistributor).TYPER
    }
}

/// Reads the GIC's IIDR register.
/// \return GICDistributor_Type::IIDR
pub unsafe fn GIC_DistributorImplementer() -> u32 {
    if GICDistributor.is_null() {
        0
    } else {
        (*GICDistributor).IIDR
    }
}

/// Enable the CPU's interrupt interface.
pub unsafe fn GIC_EnableInterface() {
    if !GICInterface.is_null() {
        (*GICInterface).CTLR |= 1;
    }
}

/// Disable the CPU's interrupt interface.
pub unsafe fn GIC_DisableInterface() {
    if !GICInterface.is_null() {
        (*GICInterface).CTLR &= !1;
    }
}

/// Read the CPU's IAR register.
/// \return GICInterface_Type::IAR
pub unsafe fn GIC_AcknowledgePending() -> i32 {
    if GICInterface.is_null() {
        0
    } else {
        (*GICInterface).IAR as i32
    }
}

/// Writes the given interrupt number to the CPU's EOIR register.
/// \param [in] IRQn The interrupt to be signaled as finished.
pub unsafe fn GIC_EndInterrupt(IRQn: i32) {
    if !GICInterface.is_null() {
        (*GICInterface).EOIR = IRQn as u32;
    }
}

/// Provides information about the implementer and revision of the CPU interface.
/// \return GICInterface_Type::IIDR
pub unsafe fn GIC_GetInterfaceId() -> u32 {
    if GICInterface.is_null() {
        0
    } else {
        (*GICInterface).IIDR
    }
}
