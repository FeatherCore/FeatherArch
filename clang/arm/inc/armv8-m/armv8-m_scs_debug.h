/*
 * ARM Architecture - ARMv8-M SCS Debug Registers
 *
 * ============================================================================
 * File: armv8-m_scs_debug.h
 * Description: ARMv8-M System Control Space (SCS) Debug Register definitions
 * 描述: ARMv8-M 系统控制空间 (SCS) 调试寄存器定义
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter D1.2: SCS Register Descriptions
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V8M_SCS_DEBUG_H__
#define __ARCH_ARM_V8M_SCS_DEBUG_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv8-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * SCS Debug Base Address
 * SCS 调试基地址
 * ============================================================================
 */

#define SCS_DEBUG_BASE_ADDR       0xE000EDF0UL

/*
 * ============================================================================
 * SCS Debug Register Definitions
 * SCS 调试寄存器定义
 * ============================================================================
 */

/**
 * Debug Halting Control and Status Register (DHCSR)
 * 调试停止控制和状态寄存器
 * Reference: Arm(R) v8-M ARM, D1.2.39
 */
#define DHCSR                     (*(volatile uint32_t *)(SCS_DEBUG_BASE_ADDR + 0x00))

/**
 * Debug Core Register Selector Register (DCRSR)
 * 调试核心寄存器选择寄存器
 * Reference: Arm(R) v8-M ARM, D1.2.34
 */
#define DCRSR                     (*(volatile uint32_t *)(SCS_DEBUG_BASE_ADDR + 0x04))

/**
 * Debug Core Register Data Register (DCRDR)
 * 调试核心寄存器数据寄存器
 * Reference: Arm(R) v8-M ARM, D1.2.33
 */
#define DCRDR                     (*(volatile uint32_t *)(SCS_DEBUG_BASE_ADDR + 0x08))

/**
 * Debug Exception and Monitor Control Register (DEMCR)
 * 调试异常和监视器控制寄存器
 * Reference: Arm(R) v8-M ARM, D1.2.37
 */
#define DEMCR                     (*(volatile uint32_t *)(SCS_DEBUG_BASE_ADDR + 0x0C))

/**
 * Debug Set Clear Exception and Monitor Control Register (DSCEMCR)
 * 调试设置清除异常和监视器控制寄存器
 * Reference: Arm(R) v8-M ARM, D1.2.50
 */
#define DSCEMCR                   (*(volatile uint32_t *)(SCS_DEBUG_BASE_ADDR + 0x10))

/**
 * Debug Authentication Control Register (DAUTHCTRL)
 * 调试认证控制寄存器
 * Reference: Arm(R) v8-M ARM, D1.2.20
 */
#define DAUTHCTRL                 (*(volatile uint32_t *)(SCS_DEBUG_BASE_ADDR + 0x14))

/**
 * Debug Authentication Status Register (DAUTHSTATUS)
 * 调试认证状态寄存器
 * Reference: Arm(R) v8-M ARM, D1.2.21
 */
#define DAUTHSTATUS               (*(volatile uint32_t *)(SCS_DEBUG_BASE_ADDR + 0x18))

/**
 * Debug Security Control and Status Register (DSCSR)
 * 调试安全控制和状态寄存器
 * Reference: Arm(R) v8-M ARM, D1.2.51
 */
#define DSCSR                     (*(volatile uint32_t *)(SCS_DEBUG_BASE_ADDR + 0x1C))

/*
 * ============================================================================
 * DHCSR Bit Definitions
 * DHCSR 位定义
 * ============================================================================
 */

#define DHCSR_DBGKEY_Pos          16U
#define DHCSR_DBGKEY_Msk          (0xFFFFUL << DHCSR_DBGKEY_Pos)
#define DHCSR_DBGKEY_VALUE        0xA05FUL

#define DHCSR_S_RESTART_ST_Pos    26U
#define DHCSR_S_RESTART_ST_Msk    (1UL << DHCSR_S_RESTART_ST_Pos)
#define DHCSR_S_RESET_ST_Pos      25U
#define DHCSR_S_RESET_ST_Msk      (1UL << DHCSR_S_RESET_ST_Pos)
#define DHCSR_S_RETIRE_ST_Pos     24U
#define DHCSR_S_RETIRE_ST_Msk     (1UL << DHCSR_S_RETIRE_ST_Pos)
#define DHCSR_S_SDE_Pos           20U
#define DHCSR_S_SDE_Msk           (1UL << DHCSR_S_SDE_Pos)
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

/*
 * ============================================================================
 * DCRSR Bit Definitions
 * DCRSR 位定义
 * ============================================================================
 */

#define DCRSR_REGWnR_Pos          16U
#define DCRSR_REGWnR_Msk          (1UL << DCRSR_REGWnR_Pos)
#define DCRSR_REGSEL_Pos          0U
#define DCRSR_REGSEL_Msk          (0x7FUL << DCRSR_REGSEL_Pos)

/* DCRSR Register Select Values */
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
#define DCRSR_REGSEL_DebugReturn  0x0FU
#define DCRSR_REGSEL_xPSR         0x10U
#define DCRSR_REGSEL_MSP          0x11U
#define DCRSR_REGSEL_PSP          0x12U
#define DCRSR_REGSEL_CONTROL      0x14U

/*
 * ============================================================================
 * DEMCR Bit Definitions
 * DEMCR 位定义
 * ============================================================================
 */

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

/*
 * ============================================================================
 * DAUTHSTATUS Bit Definitions
 * DAUTHSTATUS 位定义
 * ============================================================================
 */

#define DAUTHSTATUS_SNID_Pos      6U
#define DAUTHSTATUS_SNID_Msk      (0x3UL << DAUTHSTATUS_SNID_Pos)
#define DAUTHSTATUS_SID_Pos       4U
#define DAUTHSTATUS_SID_Msk       (0x3UL << DAUTHSTATUS_SID_Pos)
#define DAUTHSTATUS_NSNID_Pos     2U
#define DAUTHSTATUS_NSNID_Msk     (0x3UL << DAUTHSTATUS_NSNID_Pos)
#define DAUTHSTATUS_NSID_Pos      0U
#define DAUTHSTATUS_NSID_Msk      (0x3UL << DAUTHSTATUS_NSID_Pos)

#define DAUTHSTATUS_DISABLE       0x0U
#define DAUTHSTATUS_ENABLE        0x3U

/*
 * ============================================================================
 * DSCSR Bit Definitions
 * DSCSR 位定义
 * ============================================================================
 */

#define DSCSR_CDS_Pos             16U
#define DSCSR_CDS_Msk             (0xFUL << DSCSR_CDS_Pos)
#define DSCSR_CDSKEY_Pos          17U
#define DSCSR_CDSKEY_Msk          (1UL << DSCSR_CDSKEY_Pos)
#define DSCSR_SBRSEL_Pos          1U
#define DSCSR_SBRSEL_Msk          (0x3UL << DSCSR_SBRSEL_Pos)
#define DSCSR_SBRSELEN_Pos        0U
#define DSCSR_SBRSELEN_Msk        (1UL << DSCSR_SBRSELEN_Pos)

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Enable debug
 * 启用调试
 */
void scs_debug_enable(void);

/**
 * @brief Disable debug
 * 禁用调试
 */
void scs_debug_disable(void);

/**
 * @brief Halt the processor
 * 停止处理器
 */
void scs_debug_halt(void);

/**
 * @brief Resume the processor
 * 恢复处理器
 */
void scs_debug_resume(void);

/**
 * @brief Step instruction
 * 单步执行
 */
void scs_debug_step(void);

/**
 * @brief Check if processor is halted
 * 检查处理器是否停止
 * @return true if halted
 */
bool scs_debug_is_halted(void);

/**
 * @brief Check if processor is in lockup
 * 检查处理器是否处于锁定状态
 * @return true if in lockup
 */
bool scs_debug_is_lockup(void);

/**
 * @brief Check if processor is sleeping
 * 检查处理器是否处于睡眠状态
 * @return true if sleeping
 */
bool scs_debug_is_sleeping(void);

/**
 * @brief Enable monitor mode debugging
 * 启用监视器模式调试
 */
void scs_debug_enable_monitor(void);

/**
 * @brief Disable monitor mode debugging
 * 禁用监视器模式调试
 */
void scs_debug_disable_monitor(void);

/**
 * @brief Enable trace
 * 启用跟踪
 */
void scs_debug_enable_trace(void);

/**
 * @brief Disable trace
 * 禁用跟踪
 */
void scs_debug_disable_trace(void);

/**
 * @brief Read core register
 * 读取核心寄存器
 * @param regsel Register selector (DCRSR_REGSEL_*)
 * @return Register value
 */
uint32_t scs_debug_read_register(uint32_t regsel);

/**
 * @brief Write core register
 * 写入核心寄存器
 * @param regsel Register selector (DCRSR_REGSEL_*)
 * @param value Value to write
 */
void scs_debug_write_register(uint32_t regsel, uint32_t value);

/**
 * @brief Check debug authentication status
 * 检查调试认证状态
 * @return true if debug is enabled
 */
bool scs_debug_check_auth(void);

/**
 * @brief Configure vector catch
 * 配置向量捕获
 * @param mask Vector catch mask (combination of DEMCR_VC_* bits)
 */
void scs_debug_config_vector_catch(uint32_t mask);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V8M_SCS_DEBUG_H__ */
