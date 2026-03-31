/*
 * Copyright (c) 2017-2022 ARM Limited. All rights reserved.
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
 * @file     irq_ctrl_gic.c
 * @brief    Interrupt controller handling implementation for GIC
 * @version  V1.2.0
 * @date     30. October 2022
 */

/// Number of implemented interrupt lines
#[cfg(not(feature = "IRQ_GIC_LINE_COUNT"))]
pub const IRQ_GIC_LINE_COUNT: u32 = 1020;

#[cfg(not(feature = "IRQ_GIC_EXTERN_IRQ_TABLE"))]
static mut IRQ_TABLE: [Option<fn()>; IRQ_GIC_LINE_COUNT as usize] = [None; IRQ_GIC_LINE_COUNT as usize];

#[cfg(feature = "IRQ_GIC_EXTERN_IRQ_TABLE")]
extern "C" {
    static IRQ_TABLE: [Option<fn()>; IRQ_GIC_LINE_COUNT as usize];
}

static mut IRQ_ID0: u32 = 0;
