/*
 * ARM Architecture - ARMv7-M SCS Debug Registers
 *
 * ============================================================================
 * File: armv7-m_scs_debug.h
 * Description: ARMv7-M System Control Space (SCS) Debug Register definitions
 * 描述: ARMv7-M 系统控制空间 (SCS) 调试寄存器定义
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter C1.6: Debug system registers (page C1-699)
 *     * Table C1-10 Debug register summary (page C1-699)
 *       - DHCSR: Debug Halting Control and Status Register (0xE000EDF0)
 *       - DCRSR: Debug Core Register Selector Register (0xE000EDF4)
 *       - DCRDR: Debug Core Register Data Register (0xE000EDF8)
 *       - DEMCR: Debug Exception and Monitor Control Register (0xE000EDFC)
 *     * C1.6.1 Debug Fault Status Register, DFSR (page C1-699)
 *       - EXTERNAL: External debug request
 *       - VCATCH: Vector catch triggered
 *       - DWTTRAP: DWT debug event
 *       - BKPT: Breakpoint debug event
 *       - HALTED: Halt request debug event
 *     * C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 *       - DBGKEY: Debug key (0xA05F)
 *       - S_RESET_ST: Reset sticky flag
 *       - S_RETIRE_ST: Instruction retire sticky flag
 *       - S_LOCKUP: Lockup status
 *       - S_SLEEP: Sleep status
 *       - S_HALT: Halt status
 *       - S_REGRDY: Register ready flag
 *       - C_MASKINTS: Mask interrupts control
 *       - C_STEP: Step control
 *       - C_HALT: Halt control
 *       - C_DEBUGEN: Debug enable
 *     * C1.6.3 Debug Core Register Selector Register, DCRSR (page C1-703)
 *       - REGWnR: Register write/not-read
 *       - REGSEL: Register selector (R0-R12, SP, LR, xPSR, MSP, PSP, CONTROL)
 *     * C1.6.4 Debug Core Register Data Register, DCRDR (page C1-704)
 *       - Data register for reading/writing core registers
 *     * C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 *       - TRCENA: Trace enable
 *       - MON_REQ: Monitor request
 *       - MON_STEP: Monitor step
 *       - MON_PEND: Monitor pending
 *       - MON_EN: Monitor enable
 *       - VC_*: Vector catch controls
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

/*
 * ============================================================================
 * Debug Control Block (DCB) Base Address
 * 调试控制块基地址
 * Reference: Table C1-10 Debug register summary (page C1-699)
 * ============================================================================
 */

#define SCS_DEBUG_BASE_ADDR       0xE000EDF0UL

/*
 * ============================================================================
 * Debug Register Definitions
 * 调试寄存器定义
 * Reference: Table C1-10 Debug register summary (page C1-699)
 * ============================================================================
 */

/**
 * Debug Halting Control and Status Register (DHCSR)
 * Address: 0xE000EDF0
 * Type: RW
 * Reference: Arm(R) v7-M ARM, C1.6.2 Debug Halting Control and Status Register (page C1-700)
 *
 * Purpose: Controls Halting debug and provides processor status.
 * Write access requires DBGKEY (0xA05F) in bits[31:16].
 */
#define DHCSR                     (*(volatile uint32_t *)(SCS_DEBUG_BASE_ADDR + 0x00))

/**
 * Debug Core Register Selector Register (DCRSR)
 * Address: 0xE000EDF4
 * Type: WO
 * Reference: Arm(R) v7-M ARM, C1.6.3 Debug Core Register Selector Register (page C1-703)
 *
 * Purpose: Selects the processor register for read/write through DCRDR.
 * Write to this register initiates the register transfer.
 */
#define DCRSR                     (*(volatile uint32_t *)(SCS_DEBUG_BASE_ADDR + 0x04))

/**
 * Debug Core Register Data Register (DCRDR)
 * Address: 0xE000EDF8
 * Type: RW
 * Reference: Arm(R) v7-M ARM, C1.6.4 Debug Core Register Data Register (page C1-704)
 *
 * Purpose: Data register for reading/writing core registers.
 * Used in conjunction with DCRSR for register access.
 */
#define DCRDR                     (*(volatile uint32_t *)(SCS_DEBUG_BASE_ADDR + 0x08))

/**
 * Debug Exception and Monitor Control Register (DEMCR)
 * Address: 0xE000EDFC
 * Type: RW
 * Reference: Arm(R) v7-M ARM, C1.6.5 Debug Exception and Monitor Control Register (page C1-706)
 *
 * Purpose: Controls debug monitor exceptions and vector catch features.
 */
#define DEMCR                     (*(volatile uint32_t *)(SCS_DEBUG_BASE_ADDR + 0x0C))

/*
 * ============================================================================
 * DHCSR Bit Definitions
 * DHCSR 位定义
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 * ============================================================================
 */

/* Write-only debug key field */
#define DHCSR_DBGKEY_Pos          16U
#define DHCSR_DBGKEY_Msk          (0xFFFFUL << DHCSR_DBGKEY_Pos)      /*!< Debug key mask */
#define DHCSR_DBGKEY_VALUE        0xA05FUL                            /*!< Debug key value for write access */

/* Read-only status bits */
#define DHCSR_S_RESET_ST_Pos      25U
#define DHCSR_S_RESET_ST_Msk      (1UL << DHCSR_S_RESET_ST_Pos)       /*!< Reset sticky flag - set on reset, cleared on read */
#define DHCSR_S_RETIRE_ST_Pos     24U
#define DHCSR_S_RETIRE_ST_Msk     (1UL << DHCSR_S_RETIRE_ST_Pos)      /*!< Instruction retire sticky flag */
#define DHCSR_S_LOCKUP_Pos        19U
#define DHCSR_S_LOCKUP_Msk        (1UL << DHCSR_S_LOCKUP_Pos)         /*!< Lockup status - 1 if processor is locked up */
#define DHCSR_S_SLEEP_Pos         18U
#define DHCSR_S_SLEEP_Msk         (1UL << DHCSR_S_SLEEP_Pos)          /*!< Sleep status - 1 if processor is sleeping */
#define DHCSR_S_HALT_Pos          17U
#define DHCSR_S_HALT_Msk          (1UL << DHCSR_S_HALT_Pos)           /*!< Halt status - 1 if processor is halted (Debug state) */
#define DHCSR_S_REGRDY_Pos        16U
#define DHCSR_S_REGRDY_Msk        (1UL << DHCSR_S_REGRDY_Pos)         /*!< Register ready - 1 if DCRDR transfer complete */

/* Read/Write control bits */
#define DHCSR_C_SNAPSTALL_Pos     5U
#define DHCSR_C_SNAPSTALL_Msk     (1UL << DHCSR_C_SNAPSTALL_Pos)      /*!< Snap stall - break stalled load/store */
#define DHCSR_C_MASKINTS_Pos      3U
#define DHCSR_C_MASKINTS_Msk      (1UL << DHCSR_C_MASKINTS_Pos)       /*!< Mask interrupts - mask PendSV, SysTick and external interrupts */
#define DHCSR_C_STEP_Pos          2U
#define DHCSR_C_STEP_Msk          (1UL << DHCSR_C_STEP_Pos)           /*!< Step - single step the processor */
#define DHCSR_C_HALT_Pos          1U
#define DHCSR_C_HALT_Msk          (1UL << DHCSR_C_HALT_Pos)           /*!< Halt - request processor halt */
#define DHCSR_C_DEBUGEN_Pos       0U
#define DHCSR_C_DEBUGEN_Msk       (1UL << DHCSR_C_DEBUGEN_Pos)        /*!< Debug enable - enable Halting debug */

/*
 * ============================================================================
 * DCRSR Bit Definitions
 * DCRSR 位定义
 * Reference: C1.6.3 Debug Core Register Selector Register, DCRSR (page C1-703)
 * ============================================================================
 */

#define DCRSR_REGWnR_Pos          16U
#define DCRSR_REGWnR_Msk          (1UL << DCRSR_REGWnR_Pos)           /*!< Register write/not-read: 1=write, 0=read */
#define DCRSR_REGSEL_Pos          0U
#define DCRSR_REGSEL_Msk          (0x1FUL << DCRSR_REGSEL_Pos)        /*!< Register selector mask */

/* Register selector values - Table C1-12 (page C1-704) */
#define DCRSR_REGSEL_R0           0x00U                               /*!< R0 */
#define DCRSR_REGSEL_R1           0x01U                               /*!< R1 */
#define DCRSR_REGSEL_R2           0x02U                               /*!< R2 */
#define DCRSR_REGSEL_R3           0x03U                               /*!< R3 */
#define DCRSR_REGSEL_R4           0x04U                               /*!< R4 */
#define DCRSR_REGSEL_R5           0x05U                               /*!< R5 */
#define DCRSR_REGSEL_R6           0x06U                               /*!< R6 */
#define DCRSR_REGSEL_R7           0x07U                               /*!< R7 */
#define DCRSR_REGSEL_R8           0x08U                               /*!< R8 */
#define DCRSR_REGSEL_R9           0x09U                               /*!< R9 */
#define DCRSR_REGSEL_R10          0x0AU                               /*!< R10 */
#define DCRSR_REGSEL_R11          0x0BU                               /*!< R11 */
#define DCRSR_REGSEL_R12          0x0CU                               /*!< R12 */
#define DCRSR_REGSEL_SP           0x0DU                               /*!< Current SP (R13) */
#define DCRSR_REGSEL_LR           0x0EU                               /*!< LR (R14) */
#define DCRSR_REGSEL_DEBUGRET     0x0FU                               /*!< DebugReturnAddress */
#define DCRSR_REGSEL_xPSR         0x10U                               /*!< xPSR */
#define DCRSR_REGSEL_MSP          0x11U                               /*!< MSP */
#define DCRSR_REGSEL_PSP          0x12U                               /*!< PSP */
#define DCRSR_REGSEL_CONTROL      0x14U                               /*!< CONTROL */
#define DCRSR_REGSEL_FPSCR        0x21U                               /*!< FPSCR (if FPU implemented) */
#define DCRSR_REGSEL_S0           0x40U                               /*!< S0 (if FPU implemented) */
#define DCRSR_REGSEL_S31          0x5FU                               /*!< S31 (if FPU implemented) */

/*
 * ============================================================================
 * DEMCR Bit Definitions
 * DEMCR 位定义
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 * ============================================================================
 */

#define DEMCR_TRCENA_Pos          24U
#define DEMCR_TRCENA_Msk          (1UL << DEMCR_TRCENA_Pos)           /*!< Trace enable - enable DWT and ITM */
#define DEMCR_MON_REQ_Pos         19U
#define DEMCR_MON_REQ_Msk         (1UL << DEMCR_MON_REQ_Pos)          /*!< Monitor request - request DebugMonitor exception */
#define DEMCR_MON_STEP_Pos        18U
#define DEMCR_MON_STEP_Msk        (1UL << DEMCR_MON_STEP_Pos)         /*!< Monitor step - step the processor in DebugMonitor */
#define DEMCR_MON_PEND_Pos        17U
#define DEMCR_MON_PEND_Msk        (1UL << DEMCR_MON_PEND_Pos)         /*!< Monitor pending - pend DebugMonitor exception */
#define DEMCR_MON_EN_Pos          16U
#define DEMCR_MON_EN_Msk          (1UL << DEMCR_MON_EN_Pos)           /*!< Monitor enable - enable DebugMonitor exception */

/* Vector catch enable bits */
#define DEMCR_VC_HARDERR_Pos      10U
#define DEMCR_VC_HARDERR_Msk      (1UL << DEMCR_VC_HARDERR_Pos)       /*!< Vector catch HardFault */
#define DEMCR_VC_INTERR_Pos       9U
#define DEMCR_VC_INTERR_Msk       (1UL << DEMCR_VC_INTERR_Pos)        /*!< Vector catch interrupt/exception service errors */
#define DEMCR_VC_BUSERR_Pos       8U
#define DEMCR_VC_BUSERR_Msk       (1UL << DEMCR_VC_BUSERR_Pos)        /*!< Vector catch BusFault */
#define DEMCR_VC_STATERR_Pos      7U
#define DEMCR_VC_STATERR_Msk      (1UL << DEMCR_VC_STATERR_Pos)       /*!< Vector catch UsageFault state errors */
#define DEMCR_VC_CHKERR_Pos       6U
#define DEMCR_VC_CHKERR_Msk       (1UL << DEMCR_VC_CHKERR_Pos)        /*!< Vector catch UsageFault check errors */
#define DEMCR_VC_NOCPERR_Pos      5U
#define DEMCR_VC_NOCPERR_Msk      (1UL << DEMCR_VC_NOCPERR_Pos)       /*!< Vector catch No coprocessor UsageFault */
#define DEMCR_VC_MMERR_Pos        4U
#define DEMCR_VC_MMERR_Msk        (1UL << DEMCR_VC_MMERR_Pos)         /*!< Vector catch MemManage */
#define DEMCR_VC_CORERESET_Pos    0U
#define DEMCR_VC_CORERESET_Msk    (1UL << DEMCR_VC_CORERESET_Pos)     /*!< Vector catch Core reset */

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Enable Halting debug
 * 使能停止调试
 * 
 * Sets DHCSR.C_DEBUGEN to enable Halting debug.
 * Requires DBGKEY (0xA05F) for write access.
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
void scs_debug_enable(void);

/**
 * @brief Disable Halting debug
 * 禁用停止调试
 * 
 * Clears DHCSR.C_DEBUGEN to disable Halting debug.
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
void scs_debug_disable(void);

/**
 * @brief Halt the processor
 * 停止处理器
 * 
 * Requests the processor to enter Debug state.
 * Waits until the processor is halted.
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
void scs_debug_halt(void);

/**
 * @brief Resume processor execution
 * 恢复处理器执行
 * 
 * Releases the processor from Debug state.
 * Clears C_HALT and C_STEP bits.
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
void scs_debug_resume(void);

/**
 * @brief Single step the processor
 * 单步执行处理器
 * 
 * Executes a single instruction and returns to Debug state.
 * Sets C_STEP and C_HALT bits.
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
void scs_debug_step(void);

/**
 * @brief Check if processor is halted
 * 检查处理器是否停止
 * @return true if processor is in Debug state (DHCSR.S_HALT == 1)
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
bool scs_debug_is_halted(void);

/**
 * @brief Check if processor is in lockup
 * 检查处理器是否处于锁定状态
 * @return true if processor is locked up (DHCSR.S_LOCKUP == 1)
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
bool scs_debug_is_lockup(void);

/**
 * @brief Check if processor is sleeping
 * 检查处理器是否处于睡眠状态
 * @return true if processor is sleeping (DHCSR.S_SLEEP == 1)
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
bool scs_debug_is_sleeping(void);

/**
 * @brief Check if reset has occurred
 * 检查是否发生复位
 * @return true if reset occurred since last DHCSR read (DHCSR.S_RESET_ST == 1)
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
bool scs_debug_reset_occurred(void);

/**
 * @brief Check if instructions have retired
 * 检查是否有指令退役
 * @return true if instructions retired since last DHCSR read (DHCSR.S_RETIRE_ST == 1)
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
bool scs_debug_instructions_retired(void);

/**
 * @brief Enable DebugMonitor exception
 * 使能调试监视器异常
 * 
 * Sets DEMCR.MON_EN to enable DebugMonitor exception.
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_enable_monitor(void);

/**
 * @brief Disable DebugMonitor exception
 * 禁用调试监视器异常
 * 
 * Clears DEMCR.MON_EN to disable DebugMonitor exception.
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_disable_monitor(void);

/**
 * @brief Pend DebugMonitor exception
 * 挂起调试监视器异常
 * 
 * Sets DEMCR.MON_PEND to pend DebugMonitor exception.
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_pend_monitor(void);

/**
 * @brief Enable trace (DWT and ITM)
 * 使能跟踪(DWT和ITM)
 * 
 * Sets DEMCR.TRCENA to enable DWT and ITM.
 * Required before using DWT or ITM features.
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_enable_trace(void);

/**
 * @brief Disable trace (DWT and ITM)
 * 禁用跟踪(DWT和ITM)
 * 
 * Clears DEMCR.TRCENA to disable DWT and ITM.
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_disable_trace(void);

/**
 * @brief Enable vector catch for HardFault
 * 使能HardFault向量捕获
 * 
 * Sets DEMCR.VC_HARDERR to catch HardFault exceptions.
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_enable_vc_hardfault(void);

/**
 * @brief Disable vector catch for HardFault
 * 禁用HardFault向量捕获
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_disable_vc_hardfault(void);

/**
 * @brief Enable vector catch for reset
 * 使能复位向量捕获
 * 
 * Sets DEMCR.VC_CORERESET to catch core reset.
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_enable_vc_reset(void);

/**
 * @brief Disable vector catch for reset
 * 禁用复位向量捕获
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_disable_vc_reset(void);

/**
 * @brief Enable all vector catches
 * 使能所有向量捕获
 * 
 * Sets all DEMCR vector catch enable bits.
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_enable_all_vc(void);

/**
 * @brief Disable all vector catches
 * 禁用所有向量捕获
 * 
 * Clears all DEMCR vector catch enable bits.
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_disable_all_vc(void);

/**
 * @brief Read core register through debug interface
 * 通过调试接口读取核心寄存器
 * @param regsel Register selector (DCRSR_REGSEL_*)
 * @return Register value
 * 
 * Uses DCRSR and DCRDR to read a core register.
 * This function blocks until the transfer is complete.
 * 
 * Reference: C1.6.3 Debug Core Register Selector Register, DCRSR (page C1-703)
 *            C1.6.4 Debug Core Register Data Register, DCRDR (page C1-704)
 */
uint32_t scs_debug_read_register(uint32_t regsel);

/**
 * @brief Write core register through debug interface
 * 通过调试接口写入核心寄存器
 * @param regsel Register selector (DCRSR_REGSEL_*)
 * @param value Value to write
 * 
 * Uses DCRSR and DCRDR to write a core register.
 * This function blocks until the transfer is complete.
 * 
 * Reference: C1.6.3 Debug Core Register Selector Register, DCRSR (page C1-703)
 *            C1.6.4 Debug Core Register Data Register, DCRDR (page C1-704)
 */
void scs_debug_write_register(uint32_t regsel, uint32_t value);

/**
 * @brief Check if register transfer is complete
 * 检查寄存器传输是否完成
 * @return true if transfer complete (DHCSR.S_REGRDY == 1)
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
static inline bool scs_debug_is_reg_ready(void) {
    return (DHCSR & DHCSR_S_REGRDY_Msk) != 0U;
}

/**
 * @brief Wait for register transfer to complete
 * 等待寄存器传输完成
 * 
 * Polls DHCSR.S_REGRDY until the transfer is complete.
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
void scs_debug_wait_reg_ready(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_SCS_DEBUG_H__ */
