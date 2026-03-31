pub mod gic;
pub mod cp15;
pub mod processors;

#[cfg(feature = "irq-ctrl")]
pub mod irq_ctrl;
