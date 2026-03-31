#![no_std]

pub mod version;
pub mod intrinsics;

#[cfg(feature = "m-profile")]
pub mod m_profile;

#[cfg(feature = "a-profile")]
pub mod a_profile;

#[cfg(feature = "r-profile")]
pub mod r_profile;

#[cfg(feature = "trustzone")]
pub mod trustzone;

#[cfg(any(feature = "a-profile", feature = "r-profile"))]
pub mod source;

pub use version::*;
pub use intrinsics::*;
