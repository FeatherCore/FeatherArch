/*
 * ARM Architecture - ARMv7-M SCS Debug Registers
 *
 * ============================================================================
 * File: armv7-m_scs_debug.h
 * Description: ARMv7-M System Control Space (SCS) Debug Register definitions
 * 描述: ARMv7-M 系统控制空间 (SCS) 调试寄存器定义
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual
 *   - Chapter C1.6: Debug register summary
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_SCS_DEBUG_H__
#define __ARCH_ARM_V7M_SCS_DEBUG_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv7-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SCS_DEBUG_BASE_ADDR       0xE000EDF0UL

#define DHCSR                     (*(volatile uint32_t *)(SCS_DEBUG_BASE_ADDR + 0x00))
#define DCRSR                     (*(volatile uint32_t *)(SCS_DEBUG_BASE_ADDR + 0x04))
#define DCRDR                     (*(volatile uint32_t *)(SCS_DEBUG_BASE_ADDR + 0x08))
#define DEMCR                     (*(volatile uint32_t *)(SCS_DEBUG_BASE_ADDR + 0x0C))

#define DHCSR_DBGKEY_Pos          16U
#define DHCSR_DBGKEY_Msk          (0xFFFFUL << DHCSR_DBGKEY_Pos)
#define DHCSR_DBGKEY_VALUE        0xA05FUL
#define DHCSR_S_RESET_ST_Pos      25U
#define DHCSR_S_RESET_ST_Msk      (1UL << DHCSR_S_RESET_ST_Pos)
#define DHCSR_S_RETIRE_ST_Pos     24U
#define DHCSR_S_RETIRE_ST_Msk     (1UL << DHCSR_S_RETIRE_ST_Pos)
#define DHCSR_S_LOCKUP_Pos        19U
#define DHCSR_S_LOCKUP_Msk        (1UL << DHCSR_S_LOCKUP_Pos)
#define DHCSR_S_SLEEP_Pos         18U
#define DHCSR_S_SLEEP_Msk         (1UL << DHCSR_S_SLEEP_Pos)
#define DHCSR_S_HALT_Pos          17U
#define DHCSR_S_HALT_Msk          (1UL << DHCSR_S_HALT_Pos)
#define DHCSR_S_REGRDY_Pos        16U
#define DHCSR_S_REGRDY_Msk        (1UL << DHCSR_S_REGRDY_Pos)
#define DHCSR_C_SNAPSTALL_Pos     5U
#define DHCSR_C_SNAPSTALL_Msk     (1UL << DHCSR_C_SNAPSTALL_Pos)
#define DHCSR_C_MASKINTS_Pos      3U
#define DHCSR_C_MASKINTS_Msk      (1UL << DHCSR_C_MASKINTS_Pos)
#define DHCSR_C_STEP_Pos          2U
#define DHCSR_C_STEP_Msk          (1UL << DHCSR_C_STEP_Pos)
#define DHCSR_C_HALT_Pos          1U
#define DHCSR_C_HALT_Msk          (1UL << DHCSR_C_HALT_Pos)
#define DHCSR_C_DEBUGEN_Pos       0U
#define DHCSR_C_DEBUGEN_Msk       (1UL << DHCSR_C_DEBUGEN_Pos)

#define DCRSR_REGWnR_Pos          16U
#define DCRSR_REGWnR_Msk          (1UL << DCRSR_REGWnR_Pos)
#define DCRSR_REGSEL_Pos          0U
#define DCRSR_REGSEL_Msk          (0x1FUL << DCRSR_REGSEL_Pos)

#define DCRSR_REGSEL_R0           0x00U
#define DCRSR_REGSEL_R1           0x01U
#define DCRSR_REGSEL_R2           0x02U
#define DCRSR_REGSEL_R3           0x03U
#define DCRSR_REGSEL_R4           0x04U
#define DCRSR_REGSEL_R5           0x05U
#define DCRSR_REGSEL_R6           0x06U
#define DCRSR_REGSEL_R7           0x07U
#define DCRSR_REGSEL_R8           0x08U
#define DCRSR_REGSEL_R9           0x09U
#define DCRSR_REGSEL_R10          0x0AU
#define DCRSR_REGSEL_R11          0x0BU
#define DCRSR_REGSEL_R12          0x0CU
#define DCRSR_REGSEL_SP           0x0DU
#define DCRSR_REGSEL_LR           0x0EU
#define DCRSR_REGSEL_xPSR         0x10U
#define DCRSR_REGSEL_MSP          0x11U
#define DCRSR_REGSEL_PSP          0x12U
#define DCRSR_REGSEL_CONTROL      0x14U

#define DEMCR_TRCENA_Pos          24U
#define DEMCR_TRCENA_Msk          (1UL << DEMCR_TRCENA_Pos)
#define DEMCR_MON_REQ_Pos         19U
#define DEMCR_MON_REQ_Msk         (1UL << DEMCR_MON_REQ_Pos)
#define DEMCR_MON_STEP_Pos        18U
#define DEMCR_MON_STEP_Msk        (1UL << DEMCR_MON_STEP_Pos)
#define DEMCR_MON_PEND_Pos        17U
#define DEMCR_MON_PEND_Msk        (1UL << DEMCR_MON_PEND_Pos)
#define DEMCR_MON_EN_Pos          16U
#define DEMCR_MON_EN_Msk          (1UL << DEMCR_MON_EN_Pos)
#define DEMCR_VC_HARDERR_Pos      10U
#define DEMCR_VC_HARDERR_Msk      (1UL << DEMCR_VC_HARDERR_Pos)
#define DEMCR_VC_INTERR_Pos       9U
#define DEMCR_VC_INTERR_Msk       (1UL << DEMCR_VC_INTERR_Pos)
#define DEMCR_VC_BUSERR_Pos       8U
#define DEMCR_VC_BUSERR_Msk       (1UL << DEMCR_VC_BUSERR_Pos)
#define DEMCR_VC_STATERR_Pos      7U
#define DEMCR_VC_STATERR_Msk      (1UL << DEMCR_VC_STATERR_Pos)
#define DEMCR_VC_CHKERR_Pos       6U
#define DEMCR_VC_CHKERR_Msk       (1UL << DEMCR_VC_CHKERR_Pos)
#define DEMCR_VC_NOCPERR_Pos      5U
#define DEMCR_VC_NOCPERR_Msk      (1UL << DEMCR_VC_NOCPERR_Pos)
#define DEMCR_VC_MMERR_Pos        4U
#define DEMCR_VC_MMERR_Msk        (1UL << DEMCR_VC_MMERR_Pos)
#define DEMCR_VC_CORERESET_Pos    0U
#define DEMCR_VC_CORERESET_Msk    (1UL << DEMCR_VC_CORERESET_Pos)

void scs_debug_enable(void);
void scs_debug_disable(void);
void scs_debug_halt(void);
void scs_debug_resume(void);
void scs_debug_step(void);
bool scs_debug_is_halted(void);
bool scs_debug_is_lockup(void);
bool scs_debug_is_sleeping(void);
void scs_debug_enable_monitor(void);
void scs_debug_disable_monitor(void);
void scs_debug_enable_trace(void);
void scs_debug_disable_trace(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_SCS_DEBUG_H__ */
