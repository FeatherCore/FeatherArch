/*
 * Copyright (c) 2009-2023 ARM Limited. All rights reserved.
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
 * CMSIS Core Version Definitions
 */

/*  CMSIS-Core(M) Version definitions */
/// [31:16] CMSIS-Core(M) main version
pub const CM_CMSIS_VERSION_MAIN: u32 = 6;
/// [15:0] CMSIS-Core(M) sub version
pub const CM_CMSIS_VERSION_SUB: u32 = 1;
/// CMSIS Core(M) version number
pub const CM_CMSIS_VERSION: u32 = (CM_CMSIS_VERSION_MAIN << 16) | CM_CMSIS_VERSION_SUB;

/*  CMSIS-Core(A) Version definitions */
/// [31:16] CMSIS-Core(A) main version
pub const CA_CMSIS_VERSION_MAIN: u32 = 6;
/// [15:0] CMSIS-Core(A) sub version
pub const CA_CMSIS_VERSION_SUB: u32 = 1;
/// CMSIS-Core(A) version number
pub const CA_CMSIS_VERSION: u32 = (CA_CMSIS_VERSION_MAIN << 16) | CA_CMSIS_VERSION_SUB;

/// [31:16] CMSIS-Core(R) main version
pub const CR_CMSIS_VERSION_MAIN: u32 = 6;
/// [15:0] CMSIS-Core(R) sub version
pub const CR_CMSIS_VERSION_SUB: u32 = 0;
/// CMSIS-Core(R) version number
pub const CR_CMSIS_VERSION: u32 = (CR_CMSIS_VERSION_MAIN << 16) | CR_CMSIS_VERSION_SUB;
