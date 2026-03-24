/*
 * ARM Architecture - ARMv7-M MTB (Micro Trace Buffer)
 *
 * ============================================================================
 * File: armv7-m_mtb.h
 * Description: ARMv7-M MTB register definitions
 * 描述: ARMv7-M MTB 寄存器定义
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual
 *   - Appendix D: Micro Trace Buffer
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_MTB_H__
#define __ARCH_ARM_V7M_MTB_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv7-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MTB_BASE_ADDR             0xE0043000UL

#define MTB_POSITION              (*(volatile uint32_t *)(MTB_BASE_ADDR + 0x000))
#define MTB_MASTER                (*(volatile uint32_t *)(MTB_BASE_ADDR + 0x004))
#define MTB_FLOW                  (*(volatile uint32_t *)(MTB_BASE_ADDR + 0x008))
#define MTB_BASE                  (*(volatile uint32_t *)(MTB_BASE_ADDR + 0x00C))

#define MTB_MASTER_EN_Pos         31U
#define MTB_MASTER_EN_Msk         (1UL << MTB_MASTER_EN_Pos)
#define MTB_MASTER_HALTREQ_Pos    30U
#define MTB_MASTER_HALTREQ_Msk    (1UL << MTB_MASTER_HALTREQ_Pos)
#define MTB_MASTER_WRAP_Pos       29U
#define MTB_MASTER_WRAP_Msk       (1UL << MTB_MASTER_WRAP_Pos)
#define MTB_MASTER_MASK_Pos       0U
#define MTB_MASTER_MASK_Msk       (0x1FUL << MTB_MASTER_MASK_Pos)

void mtb_init(uint32_t base_addr, uint32_t buffer_size);
void mtb_enable(void);
void mtb_disable(void);
bool mtb_is_present(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_MTB_H__ */
