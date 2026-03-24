/*
 * ARM Architecture - ARMv7-M ETM (Embedded Trace Macrocell)
 *
 * ============================================================================
 * File: armv7-m_etm.h
 * Description: ARMv7-M ETMv3 register definitions
 * 描述: ARMv7-M ETMv3 寄存器定义
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual
 *   - Chapter C1.10: Embedded Trace Macrocell
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_ETM_H__
#define __ARCH_ARM_V7M_ETM_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv7-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ETM_BASE_ADDR             0xE0041000UL

#define ETM_CR                    (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x000))
#define ETM_CCR                   (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x004))
#define ETM_TRIGGER               (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x008))
#define ETM_SR                    (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x010))
#define ETM_SCR                   (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x014))
#define ETM_TSSCR                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x018))
#define ETM_TEEVR                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x020))
#define ETM_TECR1                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x024))
#define ETM_TECR2                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x028))
#define ETM_IDR2                  (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x02C))
#define ETM_IDR                   (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x1E4))
#define ETM_CIDR0                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFF0))
#define ETM_CIDR1                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFF4))
#define ETM_CIDR2                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFF8))
#define ETM_CIDR3                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFFC))

#define ETM_CR_ETMEN_Pos          0U
#define ETM_CR_ETMEN_Msk          (1UL << ETM_CR_ETMEN_Pos)
#define ETM_CR_STALL_Pos          7U
#define ETM_CR_STALL_Msk          (1UL << ETM_CR_STALL_Pos)
#define ETM_CR_BRANCH_OUTPUT_Pos  8U
#define ETM_CR_BRANCH_OUTPUT_Msk  (1UL << ETM_CR_BRANCH_OUTPUT_Pos)
#define ETM_CR_DEBUGREQ_Pos       9U
#define ETM_CR_DEBUGREQ_Msk       (1UL << ETM_CR_DEBUGREQ_Pos)
#define ETM_CR_POWERDOWN_Pos      0U
#define ETM_CR_POWERDOWN_Msk      (1UL << ETM_CR_POWERDOWN_Pos)

#define ETM_SR_ETH_Pos            3U
#define ETM_SR_ETH_Msk            (1UL << ETM_SR_ETH_Pos)
#define ETM_SR_PMSTANDBY_Pos      1U
#define ETM_SR_PMSTANDBY_Msk      (1UL << ETM_SR_PMSTANDBY_Pos)
#define ETM_SR_PMDEBUG_Pos        0U
#define ETM_SR_PMDEBUG_Msk        (1UL << ETM_SR_PMDEBUG_Pos)

void etm_init(void);
void etm_enable(void);
void etm_disable(void);
bool etm_is_present(void);
bool etm_is_enabled(void);
void etm_software_trigger(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_ETM_H__ */
