/*
 * ARM Architecture - ARMv7-M SCS Debug Implementation
 *
 * ============================================================================
 * File: armv7-m_scs_debug.c
 * Description: ARMv7-M System Control Space (SCS) Debug function implementations
 * 描述: ARMv7-M 系统控制空间 (SCS) 调试函数实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter C1.6: Debug system registers (page C1-699)
 *     * C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 *       - Halting debug control (C_DEBUGEN, C_HALT, C_STEP, C_MASKINTS)
 *       - Processor status (S_HALT, S_SLEEP, S_LOCKUP, S_REGRDY)
 *       - Sticky flags (S_RESET_ST, S_RETIRE_ST)
 *       - Debug key (DBGKEY = 0xA05F) for write access
 *     * C1.6.3 Debug Core Register Selector Register, DCRSR (page C1-703)
 *       - Register selection for read/write operations
 *       - REGWnR bit for write vs read
 *     * C1.6.4 Debug Core Register Data Register, DCRDR (page C1-704)
 *       - Data transfer for core register access
 *     * C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 *       - DebugMonitor exception control (MON_EN, MON_PEND, MON_STEP, MON_REQ)
 *       - Trace enable (TRCENA) for DWT and ITM
 *       - Vector catch configuration (VC_* bits)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include "armv7-m/armv7-m_scs_debug.h"

/*
 * ============================================================================
 * DHCSR Helper Functions
 * DHCSR 辅助函数
 * Reference: C1.6.2 Debug Halting Control and Status Register (page C1-700)
 * ============================================================================
 */

/**
 * @brief Write to DHCSR with debug key
 * 使用调试密钥写入DHCSR
 * @param value Value to write (bits[15:0] are the control bits)
 * 
 * DHCSR writes require DBGKEY (0xA05F) in bits[31:16].
 */
static inline void dhcsr_write(uint32_t value)
{
    DHCSR = (DHCSR_DBGKEY_VALUE << DHCSR_DBGKEY_Pos) | (value & 0xFFFFU);
}

/**
 * @brief Read from DHCSR
 * 读取DHCSR
 * @return DHCSR value
 */
static inline uint32_t dhcsr_read(void)
{
    return DHCSR;
}

/*
 * ============================================================================
 * Halting Debug Control Functions
 * 停止调试控制函数
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 * ============================================================================

/**
 * @brief Enable Halting debug
 * 使能停止调试
 * 
 * Sets DHCSR.C_DEBUGEN to enable Halting debug.
 * Requires DBGKEY (0xA05F) for write access.
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
void scs_debug_enable(void)
{
    dhcsr_write(DHCSR_C_DEBUGEN_Msk);
}

/**
 * @brief Disable Halting debug
 * 禁用停止调试
 * 
 * Clears DHCSR.C_DEBUGEN to disable Halting debug.
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
void scs_debug_disable(void)
{
    dhcsr_write(0);
}

/**
 * @brief Halt the processor
 * 停止处理器
 * 
 * Requests the processor to enter Debug state.
 * Waits until the processor is halted.
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
void scs_debug_halt(void)
{
    /* Enable debug and request halt */
    dhcsr_write(DHCSR_C_DEBUGEN_Msk | DHCSR_C_HALT_Msk);
    
    /* Wait until processor is halted */
    while (!scs_debug_is_halted()) {
        __asm__ volatile ("nop");
    }
}

/**
 * @brief Resume processor execution
 * 恢复处理器执行
 * 
 * Releases the processor from Debug state.
 * Clears C_HALT and C_STEP bits while keeping C_DEBUGEN set.
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
void scs_debug_resume(void)
{
    /* Keep debug enabled, clear halt and step */
    dhcsr_write(DHCSR_C_DEBUGEN_Msk);
}

/**
 * @brief Single step the processor
 * 单步执行处理器
 * 
 * Executes a single instruction and returns to Debug state.
 * Sets C_STEP and C_HALT bits with C_DEBUGEN enabled.
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
void scs_debug_step(void)
{
    /* Enable debug, halt, and step */
    dhcsr_write(DHCSR_C_DEBUGEN_Msk | DHCSR_C_HALT_Msk | DHCSR_C_STEP_Msk);
}

/**
 * @brief Check if processor is halted
 * 检查处理器是否停止
 * @return true if processor is in Debug state (DHCSR.S_HALT == 1)
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
bool scs_debug_is_halted(void)
{
    return (DHCSR & DHCSR_S_HALT_Msk) != 0U;
}

/**
 * @brief Check if processor is in lockup
 * 检查处理器是否处于锁定状态
 * @return true if processor is locked up (DHCSR.S_LOCKUP == 1)
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
bool scs_debug_is_lockup(void)
{
    return (DHCSR & DHCSR_S_LOCKUP_Msk) != 0U;
}

/**
 * @brief Check if processor is sleeping
 * 检查处理器是否处于睡眠状态
 * @return true if processor is sleeping (DHCSR.S_SLEEP == 1)
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
bool scs_debug_is_sleeping(void)
{
    return (DHCSR & DHCSR_S_SLEEP_Msk) != 0U;
}

/**
 * @brief Check if reset has occurred
 * 检查是否发生复位
 * @return true if reset occurred since last DHCSR read (DHCSR.S_RESET_ST == 1)
 * 
 * Note: This is a sticky bit that is cleared on read.
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
bool scs_debug_reset_occurred(void)
{
    return (DHCSR & DHCSR_S_RESET_ST_Msk) != 0U;
}

/**
 * @brief Check if instructions have retired
 * 检查是否有指令退役
 * @return true if instructions retired since last DHCSR read (DHCSR.S_RETIRE_ST == 1)
 * 
 * Note: This is a sticky bit that is cleared on read.
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
bool scs_debug_instructions_retired(void)
{
    return (DHCSR & DHCSR_S_RETIRE_ST_Msk) != 0U;
}

/*
 * ============================================================================
 * DebugMonitor Exception Functions
 * 调试监视器异常函数
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 * ============================================================================

/**
 * @brief Enable DebugMonitor exception
 * 使能调试监视器异常
 * 
 * Sets DEMCR.MON_EN to enable DebugMonitor exception.
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_enable_monitor(void)
{
    DEMCR |= DEMCR_MON_EN_Msk;
}

/**
 * @brief Disable DebugMonitor exception
 * 禁用调试监视器异常
 * 
 * Clears DEMCR.MON_EN to disable DebugMonitor exception.
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_disable_monitor(void)
{
    DEMCR &= ~DEMCR_MON_EN_Msk;
}

/**
 * @brief Pend DebugMonitor exception
 * 挂起调试监视器异常
 * 
 * Sets DEMCR.MON_PEND to pend DebugMonitor exception.
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_pend_monitor(void)
{
    DEMCR |= DEMCR_MON_PEND_Msk;
}

/*
 * ============================================================================
 * Trace Enable Functions
 * 跟踪使能函数
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 * ============================================================================

/**
 * @brief Enable trace (DWT and ITM)
 * 使能跟踪(DWT和ITM)
 * 
 * Sets DEMCR.TRCENA to enable DWT and ITM.
 * Required before using DWT or ITM features.
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_enable_trace(void)
{
    DEMCR |= DEMCR_TRCENA_Msk;
}

/**
 * @brief Disable trace (DWT and ITM)
 * 禁用跟踪(DWT和ITM)
 * 
 * Clears DEMCR.TRCENA to disable DWT and ITM.
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_disable_trace(void)
{
    DEMCR &= ~DEMCR_TRCENA_Msk;
}

/*
 * ============================================================================
 * Vector Catch Functions
 * 向量捕获函数
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 * ============================================================================

/**
 * @brief Enable vector catch for HardFault
 * 使能HardFault向量捕获
 * 
 * Sets DEMCR.VC_HARDERR to catch HardFault exceptions.
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_enable_vc_hardfault(void)
{
    DEMCR |= DEMCR_VC_HARDERR_Msk;
}

/**
 * @brief Disable vector catch for HardFault
 * 禁用HardFault向量捕获
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_disable_vc_hardfault(void)
{
    DEMCR &= ~DEMCR_VC_HARDERR_Msk;
}

/**
 * @brief Enable vector catch for reset
 * 使能复位向量捕获
 * 
 * Sets DEMCR.VC_CORERESET to catch core reset.
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_enable_vc_reset(void)
{
    DEMCR |= DEMCR_VC_CORERESET_Msk;
}

/**
 * @brief Disable vector catch for reset
 * 禁用复位向量捕获
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_disable_vc_reset(void)
{
    DEMCR &= ~DEMCR_VC_CORERESET_Msk;
}

/**
 * @brief Enable all vector catches
 * 使能所有向量捕获
 * 
 * Sets all DEMCR vector catch enable bits.
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_enable_all_vc(void)
{
    DEMCR |= (DEMCR_VC_HARDERR_Msk |
              DEMCR_VC_INTERR_Msk |
              DEMCR_VC_BUSERR_Msk |
              DEMCR_VC_STATERR_Msk |
              DEMCR_VC_CHKERR_Msk |
              DEMCR_VC_NOCPERR_Msk |
              DEMCR_VC_MMERR_Msk |
              DEMCR_VC_CORERESET_Msk);
}

/**
 * @brief Disable all vector catches
 * 禁用所有向量捕获
 * 
 * Clears all DEMCR vector catch enable bits.
 * 
 * Reference: C1.6.5 Debug Exception and Monitor Control Register, DEMCR (page C1-706)
 */
void scs_debug_disable_all_vc(void)
{
    DEMCR &= ~(DEMCR_VC_HARDERR_Msk |
               DEMCR_VC_INTERR_Msk |
               DEMCR_VC_BUSERR_Msk |
               DEMCR_VC_STATERR_Msk |
               DEMCR_VC_CHKERR_Msk |
               DEMCR_VC_NOCPERR_Msk |
               DEMCR_VC_MMERR_Msk |
               DEMCR_VC_CORERESET_Msk);
}

/*
 * ============================================================================
 * Core Register Access Functions
 * 核心寄存器访问函数
 * Reference: C1.6.3 DCRSR, C1.6.4 DCRDR (pages C1-703 to C1-704)
 * ============================================================================

/**
 * @brief Wait for register transfer to complete
 * 等待寄存器传输完成
 * 
 * Polls DHCSR.S_REGRDY until the transfer is complete.
 * 
 * Reference: C1.6.2 Debug Halting Control and Status Register, DHCSR (page C1-700)
 */
void scs_debug_wait_reg_ready(void)
{
    /* Wait for S_REGRDY to be set */
    while (!scs_debug_is_reg_ready()) {
        __asm__ volatile ("nop");
    }
}

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
uint32_t scs_debug_read_register(uint32_t regsel)
{
    /* Select register for read (REGWnR = 0) */
    DCRSR = (regsel & DCRSR_REGSEL_Msk);
    
    /* Wait for transfer to complete */
    scs_debug_wait_reg_ready();
    
    /* Read the data */
    return DCRDR;
}

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
void scs_debug_write_register(uint32_t regsel, uint32_t value)
{
    /* Write data to DCRDR first */
    DCRDR = value;
    
    /* Select register for write (REGWnR = 1) */
    DCRSR = DCRSR_REGWnR_Msk | (regsel & DCRSR_REGSEL_Msk);
    
    /* Wait for transfer to complete */
    scs_debug_wait_reg_ready();
}
