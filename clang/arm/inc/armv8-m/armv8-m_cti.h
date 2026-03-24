/*
 * ARM Architecture - ARMv8-M CTI (Cross-trigger Interface)
 *
 * ============================================================================
 * File: armv8-m_cti.h
 * Description: ARMv8-M CTI register definitions and function declarations
 * 描述: ARMv8-M CTI 寄存器定义和函数声明
 *
 * The CTI provides a mechanism for debug components to trigger each other.
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B13.4: Cross-trigger Interface
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V8M_CTI_H__
#define __ARCH_ARM_V8M_CTI_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv8-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CTI_BASE_ADDR             0xE0042000UL

#define CTI_CONTROL               (*(volatile uint32_t *)(CTI_BASE_ADDR + 0x000))
#define CTI_INTACK                (*(volatile uint32_t *)(CTI_BASE_ADDR + 0x010))
#define CTI_APPSET                (*(volatile uint32_t *)(CTI_BASE_ADDR + 0x014))
#define CTI_APPCLEAR              (*(volatile uint32_t *)(CTI_BASE_ADDR + 0x018))
#define CTI_APPPULSE              (*(volatile uint32_t *)(CTI_BASE_ADDR + 0x01C))
#define CTI_INEN(n)               (*(volatile uint32_t *)(CTI_BASE_ADDR + 0x020 + ((n) * 4)))
#define CTI_OUTEN(n)              (*(volatile uint32_t *)(CTI_BASE_ADDR + 0x0A0 + ((n) * 4)))
#define CTI_TRISTATE              (*(volatile uint32_t *)(CTI_BASE_ADDR + 0x130))
#define CTI_INSTATUS              (*(volatile uint32_t *)(CTI_BASE_ADDR + 0x138))
#define CTI_OUTSTATUS             (*(volatile uint32_t *)(CTI_BASE_ADDR + 0x13C))
#define CTI_CHANNEL_INSTATUS      (*(volatile uint32_t *)(CTI_BASE_ADDR + 0x140))
#define CTI_CHANNEL_OUTSTATUS     (*(volatile uint32_t *)(CTI_BASE_ADDR + 0x144))
#define CTI_GATE                  (*(volatile uint32_t *)(CTI_BASE_ADDR + 0x150))

#define CTI_CONTROL_ENABLE_Pos    0U
#define CTI_CONTROL_ENABLE_Msk    (1UL << CTI_CONTROL_ENABLE_Pos)

void cti_init(void);
void cti_enable(void);
void cti_disable(void);
void cti_pulse_channel(uint32_t channel);
void cti_map_trigger_to_channel(uint32_t trigger, uint32_t channel);
void cti_map_channel_to_trigger(uint32_t channel, uint32_t trigger);
bool cti_is_present(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V8M_CTI_H__ */
