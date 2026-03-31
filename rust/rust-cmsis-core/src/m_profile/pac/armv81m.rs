/*
 * Copyright (c) 2022 Arm Limited. All rights reserved.
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
 * CMSIS-Core(M) PAC key functions for Armv8.1-M PAC extension
 */

use core::arch::asm;

/// PAC Key functions
///
/// Functions that access the PAC keys.

/// read the PAC key used for privileged mode
///
/// Reads the PAC key stored in the PAC_KEY_P registers.
///
/// # Arguments
///
/// * `pPacKey` - 128bit PAC key
#[cfg(feature = "__ARM_FEATURE_PAUTH")]
#[inline(always)]
pub unsafe fn __get_PAC_KEY_P(pPacKey: &mut [u32; 4]) {
    asm!(
        "mrs   r1, pac_key_p_0",
        "str   r1,[{0},#0]",
        "mrs   r1, pac_key_p_1",
        "str   r1,[{0},#4]",
        "mrs   r1, pac_key_p_2",
        "str   r1,[{0},#8]",
        "mrs   r1, pac_key_p_3",
        "str   r1,[{0},#12]",
        in(reg) pPacKey.as_ptr(),
        out("r1") _,
        options(nostack, preserves_flags),
    );
}

/// write the PAC key used for privileged mode
///
/// writes the given PAC key to the PAC_KEY_P registers.
///
/// # Arguments
///
/// * `pPacKey` - 128bit PAC key
#[cfg(feature = "__ARM_FEATURE_PAUTH")]
#[inline(always)]
pub unsafe fn __set_PAC_KEY_P(pPacKey: &[u32; 4]) {
    asm!(
        "ldr   r1,[{0},#0]",
        "msr   pac_key_p_0, r1",
        "ldr   r1,[{0},#4]",
        "msr   pac_key_p_1, r1",
        "ldr   r1,[{0},#8]",
        "msr   pac_key_p_2, r1",
        "ldr   r1,[{0},#12]",
        "msr   pac_key_p_3, r1",
        in(reg) pPacKey.as_ptr(),
        out("r1") _,
        options(nostack, preserves_flags),
    );
}

/// read the PAC key used for unprivileged mode
///
/// Reads the PAC key stored in the PAC_KEY_U registers.
///
/// # Arguments
///
/// * `pPacKey` - 128bit PAC key
#[cfg(feature = "__ARM_FEATURE_PAUTH")]
#[inline(always)]
pub unsafe fn __get_PAC_KEY_U(pPacKey: &mut [u32; 4]) {
    asm!(
        "mrs   r1, pac_key_u_0",
        "str   r1,[{0},#0]",
        "mrs   r1, pac_key_u_1",
        "str   r1,[{0},#4]",
        "mrs   r1, pac_key_u_2",
        "str   r1,[{0},#8]",
        "mrs   r1, pac_key_u_3",
        "str   r1,[{0},#12]",
        in(reg) pPacKey.as_ptr(),
        out("r1") _,
        options(nostack, preserves_flags),
    );
}

/// write the PAC key used for unprivileged mode
///
/// writes the given PAC key to the PAC_KEY_U registers.
///
/// # Arguments
///
/// * `pPacKey` - 128bit PAC key
#[cfg(feature = "__ARM_FEATURE_PAUTH")]
#[inline(always)]
pub unsafe fn __set_PAC_KEY_U(pPacKey: &[u32; 4]) {
    asm!(
        "ldr   r1,[{0},#0]",
        "msr   pac_key_u_0, r1",
        "ldr   r1,[{0},#4]",
        "msr   pac_key_u_1, r1",
        "ldr   r1,[{0},#8]",
        "msr   pac_key_u_2, r1",
        "ldr   r1,[{0},#12]",
        "msr   pac_key_u_3, r1",
        in(reg) pPacKey.as_ptr(),
        out("r1") _,
        options(nostack, preserves_flags),
    );
}

/// read the PAC key used for privileged mode (non-secure)
///
/// Reads the PAC key stored in the non-secure PAC_KEY_P registers when in secure mode.
///
/// # Arguments
///
/// * `pPacKey` - 128bit PAC key
#[cfg(all(feature = "__ARM_FEATURE_PAUTH", feature = "__ARM_FEATURE_CMSE"))]
#[inline(always)]
pub unsafe fn __TZ_get_PAC_KEY_P_NS(pPacKey: &mut [u32; 4]) {
    asm!(
        "mrs   r1, pac_key_p_0_ns",
        "str   r1,[{0},#0]",
        "mrs   r1, pac_key_p_1_ns",
        "str   r1,[{0},#4]",
        "mrs   r1, pac_key_p_2_ns",
        "str   r1,[{0},#8]",
        "mrs   r1, pac_key_p_3_ns",
        "str   r1,[{0},#12]",
        in(reg) pPacKey.as_ptr(),
        out("r1") _,
        options(nostack, preserves_flags),
    );
}

/// write the PAC key used for privileged mode (non-secure)
///
/// writes the given PAC key to the non-secure PAC_KEY_P registers when in secure mode.
///
/// # Arguments
///
/// * `pPacKey` - 128bit PAC key
#[cfg(all(feature = "__ARM_FEATURE_PAUTH", feature = "__ARM_FEATURE_CMSE"))]
#[inline(always)]
pub unsafe fn __TZ_set_PAC_KEY_P_NS(pPacKey: &[u32; 4]) {
    asm!(
        "ldr   r1,[{0},#0]",
        "msr   pac_key_p_0_ns, r1",
        "ldr   r1,[{0},#4]",
        "msr   pac_key_p_1_ns, r1",
        "ldr   r1,[{0},#8]",
        "msr   pac_key_p_2_ns, r1",
        "ldr   r1,[{0},#12]",
        "msr   pac_key_p_3_ns, r1",
        in(reg) pPacKey.as_ptr(),
        out("r1") _,
        options(nostack, preserves_flags),
    );
}

/// read the PAC key used for unprivileged mode (non-secure)
///
/// Reads the PAC key stored in the non-secure PAC_KEY_U registers when in secure mode.
///
/// # Arguments
///
/// * `pPacKey` - 128bit PAC key
#[cfg(all(feature = "__ARM_FEATURE_PAUTH", feature = "__ARM_FEATURE_CMSE"))]
#[inline(always)]
pub unsafe fn __TZ_get_PAC_KEY_U_NS(pPacKey: &mut [u32; 4]) {
    asm!(
        "mrs   r1, pac_key_u_0_ns",
        "str   r1,[{0},#0]",
        "mrs   r1, pac_key_u_1_ns",
        "str   r1,[{0},#4]",
        "mrs   r1, pac_key_u_2_ns",
        "str   r1,[{0},#8]",
        "mrs   r1, pac_key_u_3_ns",
        "str   r1,[{0},#12]",
        in(reg) pPacKey.as_ptr(),
        out("r1") _,
        options(nostack, preserves_flags),
    );
}

/// write the PAC key used for unprivileged mode (non-secure)
///
/// writes the given PAC key to the non-secure PAC_KEY_U registers when in secure mode.
///
/// # Arguments
///
/// * `pPacKey` - 128bit PAC key
#[cfg(all(feature = "__ARM_FEATURE_PAUTH", feature = "__ARM_FEATURE_CMSE"))]
#[inline(always)]
pub unsafe fn __TZ_set_PAC_KEY_U_NS(pPacKey: &[u32; 4]) {
    asm!(
        "ldr   r1,[{0},#0]",
        "msr   pac_key_u_0_ns, r1",
        "ldr   r1,[{0},#4]",
        "msr   pac_key_u_1_ns, r1",
        "ldr   r1,[{0},#8]",
        "msr   pac_key_u_2_ns, r1",
        "ldr   r1,[{0},#12]",
        "msr   pac_key_u_3_ns, r1",
        in(reg) pPacKey.as_ptr(),
        out("r1") _,
        options(nostack, preserves_flags),
    );
}
