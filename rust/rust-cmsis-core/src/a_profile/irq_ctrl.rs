#![allow(non_snake_case)]

use core::ptr;

/// Interrupt handler data type
pub type IRQHandler_t = unsafe extern "C" fn();

/// Interrupt ID number data type
pub type IRQn_ID_t = i32;

/* Interrupt mode bit-masks */

/// IRQ_MODE_TRIG Position
pub const IRQ_MODE_TRIG_Pos: u32 = 0;
/// IRQ_MODE_TRIG Mask
pub const IRQ_MODE_TRIG_Msk: u32 = 0x07 << IRQ_MODE_TRIG_Pos;
/// Trigger: level triggered interrupt
pub const IRQ_MODE_TRIG_LEVEL: u32 = 0x00 << IRQ_MODE_TRIG_Pos;
/// Trigger: low level triggered interrupt
pub const IRQ_MODE_TRIG_LEVEL_LOW: u32 = 0x01 << IRQ_MODE_TRIG_Pos;
/// Trigger: high level triggered interrupt
pub const IRQ_MODE_TRIG_LEVEL_HIGH: u32 = 0x02 << IRQ_MODE_TRIG_Pos;
/// Trigger: edge triggered interrupt
pub const IRQ_MODE_TRIG_EDGE: u32 = 0x04 << IRQ_MODE_TRIG_Pos;
/// Trigger: rising edge triggered interrupt
pub const IRQ_MODE_TRIG_EDGE_RISING: u32 = 0x05 << IRQ_MODE_TRIG_Pos;
/// Trigger: falling edge triggered interrupt
pub const IRQ_MODE_TRIG_EDGE_FALLING: u32 = 0x06 << IRQ_MODE_TRIG_Pos;
/// Trigger: rising and falling edge triggered interrupt
pub const IRQ_MODE_TRIG_EDGE_BOTH: u32 = 0x07 << IRQ_MODE_TRIG_Pos;

/// IRQ_MODE_TYPE Position
pub const IRQ_MODE_TYPE_Pos: u32 = 3;
/// IRQ_MODE_TYPE Mask
pub const IRQ_MODE_TYPE_Msk: u32 = 0x01 << IRQ_MODE_TYPE_Pos;
/// Type: interrupt source triggers CPU IRQ line
pub const IRQ_MODE_TYPE_IRQ: u32 = 0x00 << IRQ_MODE_TYPE_Pos;
/// Type: interrupt source triggers CPU FIQ line
pub const IRQ_MODE_TYPE_FIQ: u32 = 0x01 << IRQ_MODE_TYPE_Pos;

/// IRQ_MODE_DOMAIN Position
pub const IRQ_MODE_DOMAIN_Pos: u32 = 4;
/// IRQ_MODE_DOMAIN Mask
pub const IRQ_MODE_DOMAIN_Msk: u32 = 0x01 << IRQ_MODE_DOMAIN_Pos;
/// Domain: interrupt is targeting non-secure domain
pub const IRQ_MODE_DOMAIN_NONSECURE: u32 = 0x00 << IRQ_MODE_DOMAIN_Pos;
/// Domain: interrupt is targeting secure domain
pub const IRQ_MODE_DOMAIN_SECURE: u32 = 0x01 << IRQ_MODE_DOMAIN_Pos;

/// IRQ_MODE_CPU Position
pub const IRQ_MODE_CPU_Pos: u32 = 5;
/// IRQ_MODE_CPU Mask
pub const IRQ_MODE_CPU_Msk: u32 = 0xFF << IRQ_MODE_CPU_Pos;
/// CPU: interrupt targets all CPUs
pub const IRQ_MODE_CPU_ALL: u32 = 0x00 << IRQ_MODE_CPU_Pos;
/// CPU: interrupt targets CPU 0
pub const IRQ_MODE_CPU_0: u32 = 0x01 << IRQ_MODE_CPU_Pos;
/// CPU: interrupt targets CPU 1
pub const IRQ_MODE_CPU_1: u32 = 0x02 << IRQ_MODE_CPU_Pos;
/// CPU: interrupt targets CPU 2
pub const IRQ_MODE_CPU_2: u32 = 0x04 << IRQ_MODE_CPU_Pos;
/// CPU: interrupt targets CPU 3
pub const IRQ_MODE_CPU_3: u32 = 0x08 << IRQ_MODE_CPU_Pos;
/// CPU: interrupt targets CPU 4
pub const IRQ_MODE_CPU_4: u32 = 0x10 << IRQ_MODE_CPU_Pos;
/// CPU: interrupt targets CPU 5
pub const IRQ_MODE_CPU_5: u32 = 0x20 << IRQ_MODE_CPU_Pos;
/// CPU: interrupt targets CPU 6
pub const IRQ_MODE_CPU_6: u32 = 0x40 << IRQ_MODE_CPU_Pos;
/// CPU: interrupt targets CPU 7
pub const IRQ_MODE_CPU_7: u32 = 0x80 << IRQ_MODE_CPU_Pos;

/// Encoding in some early GIC implementations
pub const IRQ_MODE_MODEL_Pos: u32 = 13;
pub const IRQ_MODE_MODEL_Msk: u32 = 0x01 << IRQ_MODE_MODEL_Pos;
pub const IRQ_MODE_MODEL_NN: u32 = 0x0 << IRQ_MODE_MODEL_Pos;
pub const IRQ_MODE_MODEL_1N: u32 = 0x1 << IRQ_MODE_MODEL_Pos;

pub const IRQ_MODE_ERROR: u32 = 0x80000000;

/* Interrupt priority bit-masks */

pub const IRQ_PRIORITY_Msk: u32 = 0x0000FFFF;
pub const IRQ_PRIORITY_ERROR: u32 = 0x80000000;

/// Maximum number of interrupt handlers
const MAX_IRQ_HANDLERS: usize = 1024;

/// Interrupt handler table
static mut IRQ_HANDLERS: [Option<IRQHandler_t>; MAX_IRQ_HANDLERS] = [None; MAX_IRQ_HANDLERS];

/// Initialize interrupt controller.
/// \return 0 on success, -1 on error.
pub fn IRQ_Initialize() -> i32 {
    unsafe {
        for i in 0..MAX_IRQ_HANDLERS {
            IRQ_HANDLERS[i] = None;
        }
    }
    0
}

/// Register interrupt handler.
/// \param[in]     irqn          interrupt ID number
/// \param[in]     handler       interrupt handler function address
/// \return 0 on success, -1 on error.
pub fn IRQ_SetHandler(irqn: IRQn_ID_t, handler: IRQHandler_t) -> i32 {
    if irqn < 0 || irqn as usize >= MAX_IRQ_HANDLERS {
        return -1;
    }
    unsafe {
        IRQ_HANDLERS[irqn as usize] = Some(handler);
    }
    0
}

/// Get the registered interrupt handler.
/// \param[in]     irqn          interrupt ID number
/// \return registered interrupt handler function address.
pub fn IRQ_GetHandler(irqn: IRQn_ID_t) -> Option<IRQHandler_t> {
    if irqn < 0 || irqn as usize >= MAX_IRQ_HANDLERS {
        return None;
    }
    unsafe { IRQ_HANDLERS[irqn as usize] }
}

/// Enable interrupt.
/// \param[in]     irqn          interrupt ID number
/// \return 0 on success, -1 on error.
pub fn IRQ_Enable(_irqn: IRQn_ID_t) -> i32 {
    todo!()
}

/// Disable interrupt.
/// \param[in]     irqn          interrupt ID number
/// \return 0 on success, -1 on error.
pub fn IRQ_Disable(_irqn: IRQn_ID_t) -> i32 {
    todo!()
}

/// Get interrupt enable state.
/// \param[in]     irqn          interrupt ID number
/// \return 0 - interrupt is disabled, 1 - interrupt is enabled.
pub fn IRQ_GetEnableState(_irqn: IRQn_ID_t) -> u32 {
    todo!()
}

/// Configure interrupt request mode.
/// \param[in]     irqn          interrupt ID number
/// \param[in]     mode          mode configuration
/// \return 0 on success, -1 on error.
pub fn IRQ_SetMode(_irqn: IRQn_ID_t, _mode: u32) -> i32 {
    todo!()
}

/// Get interrupt mode configuration.
/// \param[in]     irqn          interrupt ID number
/// \return current interrupt mode configuration with optional IRQ_MODE_ERROR bit set.
pub fn IRQ_GetMode(_irqn: IRQn_ID_t) -> u32 {
    todo!()
}

/// Get ID number of current interrupt request (IRQ).
/// \return interrupt ID number.
pub fn IRQ_GetActiveIRQ() -> IRQn_ID_t {
    todo!()
}

/// Get ID number of current fast interrupt request (FIQ).
/// \return interrupt ID number.
pub fn IRQ_GetActiveFIQ() -> IRQn_ID_t {
    todo!()
}

/// Signal end of interrupt processing.
/// \param[in]     irqn          interrupt ID number
/// \return 0 on success, -1 on error.
pub fn IRQ_EndOfInterrupt(_irqn: IRQn_ID_t) -> i32 {
    todo!()
}

/// Set interrupt pending flag.
/// \param[in]     irqn          interrupt ID number
/// \return 0 on success, -1 on error.
pub fn IRQ_SetPending(_irqn: IRQn_ID_t) -> i32 {
    todo!()
}

/// Get interrupt pending flag.
/// \param[in]     irqn          interrupt ID number
/// \return 0 - interrupt is not pending, 1 - interrupt is pending.
pub fn IRQ_GetPending(_irqn: IRQn_ID_t) -> u32 {
    todo!()
}

/// Clear interrupt pending flag.
/// \param[in]     irqn          interrupt ID number
/// \return 0 on success, -1 on error.
pub fn IRQ_ClearPending(_irqn: IRQn_ID_t) -> i32 {
    todo!()
}

/// Set interrupt priority value.
/// \param[in]     irqn          interrupt ID number
/// \param[in]     priority      interrupt priority value
/// \return 0 on success, -1 on error.
pub fn IRQ_SetPriority(_irqn: IRQn_ID_t, _priority: u32) -> i32 {
    todo!()
}

/// Get interrupt priority.
/// \param[in]     irqn          interrupt ID number
/// \return current interrupt priority value with optional IRQ_PRIORITY_ERROR bit set.
pub fn IRQ_GetPriority(_irqn: IRQn_ID_t) -> u32 {
    todo!()
}

/// Set priority masking threshold.
/// \param[in]     priority      priority masking threshold value
/// \return 0 on success, -1 on error.
pub fn IRQ_SetPriorityMask(_priority: u32) -> i32 {
    todo!()
}

/// Get priority masking threshold
/// \return current priority masking threshold value with optional IRQ_PRIORITY_ERROR bit set.
pub fn IRQ_GetPriorityMask() -> u32 {
    todo!()
}

/// Set priority grouping field split point
/// \param[in]     bits          number of MSB bits included in the group priority field comparison
/// \return 0 on success, -1 on error.
pub fn IRQ_SetPriorityGroupBits(_bits: u32) -> i32 {
    todo!()
}

/// Get priority grouping field split point
/// \return current number of MSB bits included in the group priority field comparison with
///         optional IRQ_PRIORITY_ERROR bit set.
pub fn IRQ_GetPriorityGroupBits() -> u32 {
    todo!()
}
