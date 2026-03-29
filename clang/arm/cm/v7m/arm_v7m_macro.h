/********************************************************************************
 * @file        arm_v7m_macro.h
 * @brief       ARMv7-M Architecture Register Bit-field Macros
 * @details     基于 ARMv7-M Architecture Reference Manual (ARM DDI 0403E.e)
 *              所有位域定义严格参考手册章节位置
 *              文档路径：g:\develop\FeatherCore\FeatherArch\docs\arm\Arm® v7-M Architecture Reference Manual.txt
 * @author      FeatherCore
 * @version     1.0.0
 * @date        2026-03-28
 * @note        本文件仅包含寄存器位域宏定义
 *
 * 寄存器位域覆盖清单：
 * - Arm Core Registers (APSR, IPSR, EPSR, xPSR, PRIMASK, BASEPRI, FAULTMASK, CONTROL)
 *   参考: D8.1 Arm core registers on page D8-842
 * - Floating-point Extension Registers
 *   - FPSCR (Floating-point Status and Control Register)
 *   参考: A2.5.2 Floating-point Status and Control Register, FPSCR on page A2-37
 * - System Control Space (SCS) Registers
 *   - ICTR, ACTLR, STIR
 *   - SCB: CPUID, ICSR, VTOR, AIRCR, SCR, CCR, SHPR1-3, SHCSR, CFSR (MMFSR+BFSR+UFSR),
 *          HFSR, DFSR, MMFAR, BFAR, AFSR, CPACR, ID_PFR0-1, ID_DFR0, ID_AFR0, ID_MMFR0-3,
 *          ID_ISAR0-5, CLIDR, CTR, CCSIDR, CSSELR
 *   - FPU: FPCCR, FPCAR, FPDSCR, MVFR0-2
 *   - SysTick: SYST_CSR, SYST_RVR, SYST_CVR, SYST_CALIB
 *   - NVIC: NVIC_ISER, NVIC_ICER, NVIC_ISPR, NVIC_ICPR, NVIC_IABR, NVIC_IPR
 *   - MPU: MPU_TYPE, MPU_CTRL, MPU_RNR, MPU_RBAR, MPU_RASR
 *   - Debug: DHCSR, DCRSR, DCRDR, DEMCR
 *   - DWT: DWT_CTRL, DWT_CYCCNT, DWT_CPICNT, DWT_EXCCNT, DWT_SLEEPCNT, DWT_LSUCNT,
 *          DWT_FOLDCNT, DWT_PCSR, DWT_COMP, DWT_MASK, DWT_FUNCTION, DWT_LAR, DWT_LSR
 *   - ITM: ITM_STIM, ITM_TER, ITM_TPR, ITM_TCR, ITM_LAR, ITM_LSR
 *   - FPB: FP_CTRL, FP_REMAP, FP_COMP, FPB_LAR, FPB_LSR
 *   - TPIU: TPIU_SSPSR, TPIU_CSPSR, TPIU_ACPR, TPIU_SPPR, TPIU_TYPE, TPIU_LAR, TPIU_LSR
 *   - ROM Table: ROM_MEMTYPE
 *   - Peripheral/Component ID: PID0-7, CID0-3
 *   参考: B3.2 System Control Space (SCS) on page B3-595
 ********************************************************************************/

#ifndef __ARM_V7M_MACRO_H__
#define __ARM_V7M_MACRO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* ==============================================================================
 * 一、Arm 核心寄存器位域 (Arm Core Registers Bit-fields)
 * 参考: B1.4 Registers on page B1-516
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 1.1 APSR 寄存器位域 (ARM_V7M_REG_APSR)
 * 参考: B1.4.2 The special-purpose Program Status Registers, xPSR on page B1-516
 * -----------------------------------------------------------------------------
 */
/* N - Negative condition code flag, bit[31] */
#define ARM_V7M_APSR_N_Pos          31U
#define ARM_V7M_APSR_N_Msk          (1UL << ARM_V7M_APSR_N_Pos)
/* Z - Zero condition code flag, bit[30] */
#define ARM_V7M_APSR_Z_Pos          30U
#define ARM_V7M_APSR_Z_Msk          (1UL << ARM_V7M_APSR_Z_Pos)
/* C - Carry condition code flag, bit[29] */
#define ARM_V7M_APSR_C_Pos          29U
#define ARM_V7M_APSR_C_Msk          (1UL << ARM_V7M_APSR_C_Pos)
/* V - Overflow condition code flag, bit[28] */
#define ARM_V7M_APSR_V_Pos          28U
#define ARM_V7M_APSR_V_Msk          (1UL << ARM_V7M_APSR_V_Pos)
/* Q - DSP overflow and saturation flag, bit[27] */
#define ARM_V7M_APSR_Q_Pos          27U
#define ARM_V7M_APSR_Q_Msk          (1UL << ARM_V7M_APSR_Q_Pos)
/* GE[3:0] - Greater than or Equal flags for DSP operations, bits[19:16] */
#define ARM_V7M_APSR_GE_Pos         16U
#define ARM_V7M_APSR_GE_Msk         (0xFUL << ARM_V7M_APSR_GE_Pos)
/* GE0 - Greater than or Equal flag 0 for DSP operations, bit[16] */
#define ARM_V7M_APSR_GE0_Pos        16U
#define ARM_V7M_APSR_GE0_Msk        (1UL << ARM_V7M_APSR_GE0_Pos)
/* GE1 - Greater than or Equal flag 1 for DSP operations, bit[17] */
#define ARM_V7M_APSR_GE1_Pos        17U
#define ARM_V7M_APSR_GE1_Msk        (1UL << ARM_V7M_APSR_GE1_Pos)
/* GE2 - Greater than or Equal flag 2 for DSP operations, bit[18] */
#define ARM_V7M_APSR_GE2_Pos        18U
#define ARM_V7M_APSR_GE2_Msk        (1UL << ARM_V7M_APSR_GE2_Pos)
/* GE3 - Greater than or Equal flag 3 for DSP operations, bit[19] */
#define ARM_V7M_APSR_GE3_Pos        19U
#define ARM_V7M_APSR_GE3_Msk        (1UL << ARM_V7M_APSR_GE3_Pos)

/* -----------------------------------------------------------------------------
 * 1.2 IPSR 寄存器位域 (ARM_V7M_REG_IPSR)
 * 参考: B1.4.2 The special-purpose Program Status Registers, xPSR on page B1-516
 * -----------------------------------------------------------------------------
 */
/* ISR[8:0] - Exception number of the currently executing exception, bits[8:0] */
#define ARM_V7M_IPSR_ISR_Pos        0U
#define ARM_V7M_IPSR_ISR_Msk        (0x1FFUL << ARM_V7M_IPSR_ISR_Pos)

/* -----------------------------------------------------------------------------
 * 1.3 EPSR 寄存器位域 (ARM_V7M_REG_EPSR)
 * 参考: B1.4.2 The special-purpose Program Status Registers, xPSR on page B1-516
 *      Table B1-2 ICI/IT bit allocation in the EPSR on page B1-517
 * -----------------------------------------------------------------------------
 */
/* ICI/IT-1 (IT[1:0] / ICI[7:6]) - If-Then execution state bits and Interruptible-Continuable Instruction bits (part 1), bits[26:25] */
#define ARM_V7M_EPSR_ICI_IT_1_Pos   25U
#define ARM_V7M_EPSR_ICI_IT_1_Msk   (0x3UL << ARM_V7M_EPSR_ICI_IT_1_Pos)
/* IT[1:0] - If-Then execution state bits (part 1), bits[26:25] */
#define ARM_V7M_EPSR_IT_1_0_Pos     25U
#define ARM_V7M_EPSR_IT_1_0_Msk     (0x3UL << ARM_V7M_EPSR_IT_1_0_Pos)
/* T - Thumb state bit, bit[24] */
#define ARM_V7M_EPSR_T_Pos          24U
#define ARM_V7M_EPSR_T_Msk          (1UL << ARM_V7M_EPSR_T_Pos)
/* ICI/IT-2 - If-Then execution state bits and Interruptible-Continuable Instruction bits (part 2), bits[15:10] */
#define ARM_V7M_EPSR_ICI_IT_2_Pos   10U
#define ARM_V7M_EPSR_ICI_IT_2_Msk   (0x3FUL << ARM_V7M_EPSR_ICI_IT_2_Pos)
/* IT[7:4] - If-Then execution state bits (part 2), bits[15:12] */
#define ARM_V7M_EPSR_IT_7_4_Pos     12U
#define ARM_V7M_EPSR_IT_7_4_Msk     (0xFUL << ARM_V7M_EPSR_IT_7_4_Pos)
/* IT[3:2] - If-Then execution state bits (part 3), bits[11:10] */
#define ARM_V7M_EPSR_IT_3_2_Pos     10U
#define ARM_V7M_EPSR_IT_3_2_Msk     (0x3UL << ARM_V7M_EPSR_IT_3_2_Pos)
/* ICI[5:2] - Interruptible-Continuable Instruction bits (part 2), bits[15:12] */
#define ARM_V7M_EPSR_ICI_5_2_Pos    12U
#define ARM_V7M_EPSR_ICI_5_2_Msk    (0xFUL << ARM_V7M_EPSR_ICI_5_2_Pos)
/* ICI[1:0] - Interruptible-Continuable Instruction bits (part 3), bits[11:10] */
#define ARM_V7M_EPSR_ICI_1_0_Pos    10U
#define ARM_V7M_EPSR_ICI_1_0_Msk    (0x3UL << ARM_V7M_EPSR_ICI_1_0_Pos)

/* -----------------------------------------------------------------------------
 * 1.4 PRIMASK 寄存器位域 (ARM_V7M_REG_PRIMASK)
 * 参考: B1.4.3 The special-purpose mask registers on page B1-519
 * -----------------------------------------------------------------------------
 */
/* PM - The exception mask bit, bit[0] */
#define ARM_V7M_PRIMASK_PM_Pos      0U
#define ARM_V7M_PRIMASK_PM_Msk      (1UL << ARM_V7M_PRIMASK_PM_Pos)

/* -----------------------------------------------------------------------------
 * 1.5 BASEPRI 寄存器位域 (ARM_V7M_REG_BASEPRI)
 * 参考: B1.4.3 The special-purpose mask registers on page B1-519
 * -----------------------------------------------------------------------------
 */
/* PRI[7:0] - Base priority mask value, bits[7:0] */
#define ARM_V7M_BASEPRI_PRI_Pos     0U
#define ARM_V7M_BASEPRI_PRI_Msk     (0xFFUL << ARM_V7M_BASEPRI_PRI_Pos)

/* -----------------------------------------------------------------------------
 * 1.6 FAULTMASK 寄存器位域 (ARM_V7M_REG_FAULTMASK)
 * 参考: B1.4.3 The special-purpose mask registers on page B1-519
 * -----------------------------------------------------------------------------
 */
/* FM - The fault mask bit, bit[0] */
#define ARM_V7M_FAULTMASK_FM_Pos    0U
#define ARM_V7M_FAULTMASK_FM_Msk    (1UL << ARM_V7M_FAULTMASK_FM_Pos)

/* -----------------------------------------------------------------------------
 * 1.7 CONTROL 寄存器位域 (ARM_V7M_REG_CONTROL)
 * 参考: B1.4.4 The special-purpose CONTROL register on page B1-519
 * -----------------------------------------------------------------------------
 */
/* nPRIV - Thread mode privilege level, bit[0] */
#define ARM_V7M_CONTROL_nPRIV_Pos   0U
#define ARM_V7M_CONTROL_nPRIV_Msk   (1UL << ARM_V7M_CONTROL_nPRIV_Pos)
/* SPSEL - Stack pointer selection, bit[1] */
#define ARM_V7M_CONTROL_SPSEL_Pos   1U
#define ARM_V7M_CONTROL_SPSEL_Msk   (1UL << ARM_V7M_CONTROL_SPSEL_Pos)
/* FPCA - Floating-point context active, bit[2] */
#define ARM_V7M_CONTROL_FPCA_Pos    2U
#define ARM_V7M_CONTROL_FPCA_Msk    (1UL << ARM_V7M_CONTROL_FPCA_Pos)

/* ==============================================================================
 * 二、系统控制空间位域 (System Control Space Bit-fields)
 * 参考: B3.2 System Control Space (SCS) on page B3-595
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 2.1 ICTR 寄存器位域 (ARM_V7M_SCS_ICTR)
 * 参考: B3.2.24 Interrupt Controller Type Register, ICTR on page B3-618
 * -----------------------------------------------------------------------------
 */
/* INTLINESNUM - Indicates the number of interrupt lines supported, bits[3:0] */
#define ARM_V7M_ICTR_INTLINESNUM_Pos    0U
#define ARM_V7M_ICTR_INTLINESNUM_Msk    (0xFUL << ARM_V7M_ICTR_INTLINESNUM_Pos)

/* -----------------------------------------------------------------------------
 * 2.2 ACTLR 寄存器位域 (ARM_V7M_SCS_ACTLR)
 * 参考: B3.2.25 Auxiliary Control Register, ACTLR on page B3-618
 *
 * 注意: ACTLR 寄存器为 IMPLEMENTATION DEFINED，架构手册未定义具体位域
 *       不同处理器实现有不同的位域定义，具体请参考处理器厂商的技术参考手册
 *       例如: Cortex-M7 参考 Arm Cortex-M7 Processor TRM, Table 3-3
 *             Cortex-M4 参考 Arm Cortex-M4 Processor TRM
 * -----------------------------------------------------------------------------
 */

/* -----------------------------------------------------------------------------
 * 2.3 CPUID 寄存器位域 (ARM_V7M_SCB_CPUID)
 * 参考: B3.2.3 CPUID Base Register on page B3-598
 * -----------------------------------------------------------------------------
 */
/* IMPLEMENTER - Implementer code assigned by Arm, bits[31:24] */
#define ARM_V7M_CPUID_IMPLEMENTER_Pos   24U
#define ARM_V7M_CPUID_IMPLEMENTER_Msk   (0xFFUL << ARM_V7M_CPUID_IMPLEMENTER_Pos)
/* VARIANT - IMPLEMENTATION DEFINED variant number, bits[23:20] */
#define ARM_V7M_CPUID_VARIANT_Pos       20U
#define ARM_V7M_CPUID_VARIANT_Msk       (0xFUL << ARM_V7M_CPUID_VARIANT_Pos)
/* ARCHITECTURE - Architecture identifier, bits[19:16] */
#define ARM_V7M_CPUID_ARCHITECTURE_Pos  16U
#define ARM_V7M_CPUID_ARCHITECTURE_Msk  (0xFUL << ARM_V7M_CPUID_ARCHITECTURE_Pos)
/* PARTNO - IMPLEMENTATION DEFINED part number, bits[15:4] */
#define ARM_V7M_CPUID_PARTNO_Pos        4U
#define ARM_V7M_CPUID_PARTNO_Msk        (0xFFFUL << ARM_V7M_CPUID_PARTNO_Pos)
/* REVISION - IMPLEMENTATION DEFINED revision number, bits[3:0] */
#define ARM_V7M_CPUID_REVISION_Pos      0U
#define ARM_V7M_CPUID_REVISION_Msk      (0xFUL << ARM_V7M_CPUID_REVISION_Pos)

/* -----------------------------------------------------------------------------
 * 2.4 ICSR 寄存器位域 (ARM_V7M_SCB_ICSR)
 * 参考: B3.2.4 Interrupt Control and State Register, ICSR on page B3-599
 * -----------------------------------------------------------------------------
 */
/* NMIPENDSET - NMI exception pending set, bit[31] */
#define ARM_V7M_ICSR_NMIPENDSET_Pos     31U
#define ARM_V7M_ICSR_NMIPENDSET_Msk     (1UL << ARM_V7M_ICSR_NMIPENDSET_Pos)
/* PENDSVSET - PendSV exception pending set, bit[28] */
#define ARM_V7M_ICSR_PENDSVSET_Pos      28U
#define ARM_V7M_ICSR_PENDSVSET_Msk      (1UL << ARM_V7M_ICSR_PENDSVSET_Pos)
/* PENDSVCLR - PendSV exception pending clear, bit[27] */
#define ARM_V7M_ICSR_PENDSVCLR_Pos      27U
#define ARM_V7M_ICSR_PENDSVCLR_Msk      (1UL << ARM_V7M_ICSR_PENDSVCLR_Pos)
/* PENDSTSET - SysTick exception pending set, bit[26] */
#define ARM_V7M_ICSR_PENDSTSET_Pos      26U
#define ARM_V7M_ICSR_PENDSTSET_Msk      (1UL << ARM_V7M_ICSR_PENDSTSET_Pos)
/* PENDSTCLR - SysTick exception pending clear, bit[25] */
#define ARM_V7M_ICSR_PENDSTCLR_Pos      25U
#define ARM_V7M_ICSR_PENDSTCLR_Msk      (1UL << ARM_V7M_ICSR_PENDSTCLR_Pos)
/* ISRPREEMPT - Indicates pending exception will be serviced on exit from debug halt, bit[23] */
#define ARM_V7M_ICSR_ISRPREEMPT_Pos     23U
#define ARM_V7M_ICSR_ISRPREEMPT_Msk     (1UL << ARM_V7M_ICSR_ISRPREEMPT_Pos)
/* ISRPENDING - Indicates external interrupt pending, bit[22] */
#define ARM_V7M_ICSR_ISRPENDING_Pos     22U
#define ARM_V7M_ICSR_ISRPENDING_Msk     (1UL << ARM_V7M_ICSR_ISRPENDING_Pos)
/* VECTPENDING - Exception number of highest priority pending and enabled interrupt, bits[20:12] */
#define ARM_V7M_ICSR_VECTPENDING_Pos    12U
#define ARM_V7M_ICSR_VECTPENDING_Msk    (0x1FFUL << ARM_V7M_ICSR_VECTPENDING_Pos)
/* RETTOBASE - Indicates no active exception other than current one (Handler mode only), bit[11] */
#define ARM_V7M_ICSR_RETTOBASE_Pos      11U
#define ARM_V7M_ICSR_RETTOBASE_Msk      (1UL << ARM_V7M_ICSR_RETTOBASE_Pos)
/* VECTACTIVE - Exception number of current executing exception, bits[8:0] */
#define ARM_V7M_ICSR_VECTACTIVE_Pos     0U
#define ARM_V7M_ICSR_VECTACTIVE_Msk     (0x1FFUL << ARM_V7M_ICSR_VECTACTIVE_Pos)

/* -----------------------------------------------------------------------------
 * 2.5 VTOR 寄存器位域 (ARM_V7M_SCB_VTOR)
 * 参考: B3.2.5 Vector Table Offset Register, VTOR on page B3-601
 * -----------------------------------------------------------------------------
 */
/* TBLOFF - Vector table base address offset, bits[31:7] of the vector table address */
#define ARM_V7M_VTOR_TBLOFF_Pos         7U
#define ARM_V7M_VTOR_TBLOFF_Msk         (0x1FFFFFFUL << ARM_V7M_VTOR_TBLOFF_Pos)

/* -----------------------------------------------------------------------------
 * 2.6 AIRCR 寄存器位域 (ARM_V7M_SCB_AIRCR)
 * 参考: B3.2.6 Application Interrupt and Reset Control Register, AIRCR on page B3-601
 * -----------------------------------------------------------------------------
 */
/* VECTKEY - Vector key for write access (must write 0x05FA), bits[31:16] */
#define ARM_V7M_AIRCR_VECTKEY_Pos       16U
#define ARM_V7M_AIRCR_VECTKEY_Msk       (0xFFFFUL << ARM_V7M_AIRCR_VECTKEY_Pos)
/* VECTKEYSTAT - Vector key status (reads as 0xFA05), bits[31:16] */
#define ARM_V7M_AIRCR_VECTKEYSTAT_Pos   16U
#define ARM_V7M_AIRCR_VECTKEYSTAT_Msk   (0xFFFFUL << ARM_V7M_AIRCR_VECTKEYSTAT_Pos)
/* ENDIANNESS - Data endianness indicator, bit[15] */
#define ARM_V7M_AIRCR_ENDIANNESS_Pos    15U
#define ARM_V7M_AIRCR_ENDIANNESS_Msk    (1UL << ARM_V7M_AIRCR_ENDIANNESS_Pos)
/* PRIGROUP - Priority grouping field, bits[10:8] */
#define ARM_V7M_AIRCR_PRIGROUP_Pos      8U
#define ARM_V7M_AIRCR_PRIGROUP_Msk      (7UL << ARM_V7M_AIRCR_PRIGROUP_Pos)
/* SYSRESETREQ - System reset request, bit[2] */
#define ARM_V7M_AIRCR_SYSRESETREQ_Pos   2U
#define ARM_V7M_AIRCR_SYSRESETREQ_Msk   (1UL << ARM_V7M_AIRCR_SYSRESETREQ_Pos)
/* VECTCLRACTIVE - Clear active vector, bit[1] */
#define ARM_V7M_AIRCR_VECTCLRACTIVE_Pos 1U
#define ARM_V7M_AIRCR_VECTCLRACTIVE_Msk (1UL << ARM_V7M_AIRCR_VECTCLRACTIVE_Pos)
/* VECTRESET - System reset (write-only), bit[0] */
#define ARM_V7M_AIRCR_VECTRESET_Pos     0U
#define ARM_V7M_AIRCR_VECTRESET_Msk     (1UL << ARM_V7M_AIRCR_VECTRESET_Pos)

/* ==============================================================================
 * 2.6.1 AIRCR 值定义宏 (AIRCR Value Definition Macros)
 * 非寄存器位域宏，用于定义 AIRCR 寄存器的具体值
 * ==============================================================================
 */
/* VECTKEY_VALUE - Vector key value (0x05FA) */
#define ARM_V7M_AIRCR_VECTKEY_VALUE     (0x05FAUL << ARM_V7M_AIRCR_VECTKEY_Pos)

/* -----------------------------------------------------------------------------
 * 2.7 SCR 寄存器位域 (ARM_V7M_SCB_SCR)
 * 参考: B3.2.7 System Control Register, SCR on page B3-603
 * -----------------------------------------------------------------------------
 */
/* SEVONPEND - Send Event on Pending interrupt, bit[4] */
#define ARM_V7M_SCR_SEVONPEND_Pos       4U
#define ARM_V7M_SCR_SEVONPEND_Msk       (1UL << ARM_V7M_SCR_SEVONPEND_Pos)
/* SLEEPDEEP - Deep sleep, bit[2] */
#define ARM_V7M_SCR_SLEEPDEEP_Pos       2U
#define ARM_V7M_SCR_SLEEPDEEP_Msk       (1UL << ARM_V7M_SCR_SLEEPDEEP_Pos)
/* SLEEPONEXIT - Sleep on exception return, bit[1] */
#define ARM_V7M_SCR_SLEEPONEXIT_Pos     1U
#define ARM_V7M_SCR_SLEEPONEXIT_Msk     (1UL << ARM_V7M_SCR_SLEEPONEXIT_Pos)

/* -----------------------------------------------------------------------------
 * 2.8 CCR 寄存器位域 (ARM_V7M_SCB_CCR)
 * 参考: B3.2.8 Configuration and Control Register, CCR on page B3-604
 * -----------------------------------------------------------------------------
 */
/* BP - Branch prediction, bit[18] */
#define ARM_V7M_CCR_BP_Pos              18U
#define ARM_V7M_CCR_BP_Msk              (1UL << ARM_V7M_CCR_BP_Pos)
/* IC - Instruction cache, bit[17] */
#define ARM_V7M_CCR_IC_Pos              17U
#define ARM_V7M_CCR_IC_Msk              (1UL << ARM_V7M_CCR_IC_Pos)
/* DC - Data cache, bit[16] */
#define ARM_V7M_CCR_DC_Pos              16U
#define ARM_V7M_CCR_DC_Msk              (1UL << ARM_V7M_CCR_DC_Pos)
/* STKALIGN - Stack alignment, bit[9] */
#define ARM_V7M_CCR_STKALIGN_Pos        9U
#define ARM_V7M_CCR_STKALIGN_Msk        (1UL << ARM_V7M_CCR_STKALIGN_Pos)
/* BFHFNMIGN - BusFault, HardFault, and NMI ignore, bit[8] */
#define ARM_V7M_CCR_BFHFNMIGN_Pos       8U
#define ARM_V7M_CCR_BFHFNMIGN_Msk       (1UL << ARM_V7M_CCR_BFHFNMIGN_Pos)
/* DIV_0_TRP - Divide by zero trap, bit[4] */
#define ARM_V7M_CCR_DIV_0_TRP_Pos       4U
#define ARM_V7M_CCR_DIV_0_TRP_Msk       (1UL << ARM_V7M_CCR_DIV_0_TRP_Pos)
/* UNALIGN_TRP - Unaligned access trap, bit[3] */
#define ARM_V7M_CCR_UNALIGN_TRP_Pos     3U
#define ARM_V7M_CCR_UNALIGN_TRP_Msk     (1UL << ARM_V7M_CCR_UNALIGN_TRP_Pos)
/* USERSETMPEND - User mode set pending, bit[1] */
#define ARM_V7M_CCR_USERSETMPEND_Pos    1U
#define ARM_V7M_CCR_USERSETMPEND_Msk    (1UL << ARM_V7M_CCR_USERSETMPEND_Pos)
/* NONBASETHRDENA - Non-base thread enable, bit[0] */
#define ARM_V7M_CCR_NONBASETHRDENA_Pos  0U
#define ARM_V7M_CCR_NONBASETHRDENA_Msk  (1UL << ARM_V7M_CCR_NONBASETHRDENA_Pos)

/* -----------------------------------------------------------------------------
 * 2.8a FPSCR 寄存器位域 (ARM_V7M_REG_FPSCR)
 * 参考: A2.5.3 Floating-point Status and Control Register, FPSCR on page A2-37
 *
 * 注意: ARMv7-M 的 FPSCR 不包含异常陷阱使能位 (IDE, IXE, UFE, OFE, DZE, IOE)
 *       这些位是 FPv5 架构 FPEXC 寄存器的一部分,不是 FPSCR 的组成部分
 * -----------------------------------------------------------------------------
 */
/* N - Negative condition code flag, bit[31] */
#define ARM_V7M_FPSCR_N_Pos             31U
#define ARM_V7M_FPSCR_N_Msk             (1UL << ARM_V7M_FPSCR_N_Pos)
/* Z - Zero condition code flag, bit[30] */
#define ARM_V7M_FPSCR_Z_Pos             30U
#define ARM_V7M_FPSCR_Z_Msk             (1UL << ARM_V7M_FPSCR_Z_Pos)
/* C - Carry condition code flag, bit[29] */
#define ARM_V7M_FPSCR_C_Pos             29U
#define ARM_V7M_FPSCR_C_Msk             (1UL << ARM_V7M_FPSCR_C_Pos)
/* V - Overflow condition code flag, bit[28] */
#define ARM_V7M_FPSCR_V_Pos             28U
#define ARM_V7M_FPSCR_V_Msk             (1UL << ARM_V7M_FPSCR_V_Pos)
/* AHP - Alternative half-precision control bit, bit[26] */
#define ARM_V7M_FPSCR_AHP_Pos           26U
#define ARM_V7M_FPSCR_AHP_Msk           (1UL << ARM_V7M_FPSCR_AHP_Pos)
/* DN - Default NaN mode control bit, bit[25] */
#define ARM_V7M_FPSCR_DN_Pos            25U
#define ARM_V7M_FPSCR_DN_Msk            (1UL << ARM_V7M_FPSCR_DN_Pos)
/* FZ - Flush-to-zero mode control bit, bit[24] */
#define ARM_V7M_FPSCR_FZ_Pos            24U
#define ARM_V7M_FPSCR_FZ_Msk            (1UL << ARM_V7M_FPSCR_FZ_Pos)
/* RMode - Rounding mode control field, bits[23:22] */
#define ARM_V7M_FPSCR_RMode_Pos         22U
#define ARM_V7M_FPSCR_RMode_Msk         (3UL << ARM_V7M_FPSCR_RMode_Pos)
/* IDC - Input Denormal cumulative exception, bit[7] */
#define ARM_V7M_FPSCR_IDC_Pos           7U
#define ARM_V7M_FPSCR_IDC_Msk           (1UL << ARM_V7M_FPSCR_IDC_Pos)
/* IXC - Inexact cumulative exception, bit[4] */
#define ARM_V7M_FPSCR_IXC_Pos           4U
#define ARM_V7M_FPSCR_IXC_Msk           (1UL << ARM_V7M_FPSCR_IXC_Pos)
/* UFC - Underflow cumulative exception, bit[3] */
#define ARM_V7M_FPSCR_UFC_Pos           3U
#define ARM_V7M_FPSCR_UFC_Msk           (1UL << ARM_V7M_FPSCR_UFC_Pos)
/* OFC - Overflow cumulative exception, bit[2] */
#define ARM_V7M_FPSCR_OFC_Pos           2U
#define ARM_V7M_FPSCR_OFC_Msk           (1UL << ARM_V7M_FPSCR_OFC_Pos)
/* DZC - Divide by Zero cumulative exception, bit[1] */
#define ARM_V7M_FPSCR_DZC_Pos           1U
#define ARM_V7M_FPSCR_DZC_Msk           (1UL << ARM_V7M_FPSCR_DZC_Pos)
/* IOC - Invalid Operation cumulative exception, bit[0] */
#define ARM_V7M_FPSCR_IOC_Pos           0U
#define ARM_V7M_FPSCR_IOC_Msk           (1UL << ARM_V7M_FPSCR_IOC_Pos)

/* -----------------------------------------------------------------------------
 * 2.9 SHPR1 寄存器位域 (ARM_V7M_SCB_SHPR1)
 * 参考: B3.2.10 System Handler Priority Register 1, SHPR1 on page B3-606
 * ----------------------------------------------------------------------------- */
/* PRI_4 - Priority of system handler 4 (MemManage), bits[7:0] */
#define ARM_V7M_SHPR1_PRI_4_Pos         0U
#define ARM_V7M_SHPR1_PRI_4_Msk         (0xFFUL << ARM_V7M_SHPR1_PRI_4_Pos)
/* PRI_5 - Priority of system handler 5 (BusFault), bits[15:8] */
#define ARM_V7M_SHPR1_PRI_5_Pos         8U
#define ARM_V7M_SHPR1_PRI_5_Msk         (0xFFUL << ARM_V7M_SHPR1_PRI_5_Pos)
/* PRI_6 - Priority of system handler 6 (UsageFault), bits[23:16] */
#define ARM_V7M_SHPR1_PRI_6_Pos         16U
#define ARM_V7M_SHPR1_PRI_6_Msk         (0xFFUL << ARM_V7M_SHPR1_PRI_6_Pos)
/* PRI_7 - Priority of system handler 7 (Reserved), bits[31:24] */
#define ARM_V7M_SHPR1_PRI_7_Pos         24U
#define ARM_V7M_SHPR1_PRI_7_Msk         (0xFFUL << ARM_V7M_SHPR1_PRI_7_Pos)

/* -----------------------------------------------------------------------------
 * 2.10 SHPR2 寄存器位域 (ARM_V7M_SCB_SHPR2)
 * 参考: B3.2.11 System Handler Priority Register 2, SHPR2 on page B3-606
 * -----------------------------------------------------------------------------
 */
/* PRI_8 - Priority of system handler 8 (Reserved), bits[7:0] */
#define ARM_V7M_SHPR2_PRI_8_Pos         0U
#define ARM_V7M_SHPR2_PRI_8_Msk         (0xFFUL << ARM_V7M_SHPR2_PRI_8_Pos)
/* PRI_9 - Priority of system handler 9 (Reserved), bits[15:8] */
#define ARM_V7M_SHPR2_PRI_9_Pos         8U
#define ARM_V7M_SHPR2_PRI_9_Msk         (0xFFUL << ARM_V7M_SHPR2_PRI_9_Pos)
/* PRI_10 - Priority of system handler 10 (Reserved), bits[23:16] */
#define ARM_V7M_SHPR2_PRI_10_Pos        16U
#define ARM_V7M_SHPR2_PRI_10_Msk        (0xFFUL << ARM_V7M_SHPR2_PRI_10_Pos)
/* PRI_11 - Priority of system handler 11 (SVCall), bits[31:24] */
#define ARM_V7M_SHPR2_PRI_11_Pos        24U
#define ARM_V7M_SHPR2_PRI_11_Msk        (0xFFUL << ARM_V7M_SHPR2_PRI_11_Pos)

/* -----------------------------------------------------------------------------
 * 2.11 SHPR3 寄存器位域 (ARM_V7M_SCB_SHPR3)
 * 参考: B3.2.12 System Handler Priority Register 3, SHPR3 on page B3-607
 * -----------------------------------------------------------------------------
 */
/* PRI_12 - Priority of system handler 12 (DebugMonitor), bits[7:0] */
#define ARM_V7M_SHPR3_PRI_12_Pos        0U
#define ARM_V7M_SHPR3_PRI_12_Msk        (0xFFUL << ARM_V7M_SHPR3_PRI_12_Pos)
/* PRI_13 - Priority of system handler 13 (Reserved), bits[15:8] */
#define ARM_V7M_SHPR3_PRI_13_Pos        8U
#define ARM_V7M_SHPR3_PRI_13_Msk        (0xFFUL << ARM_V7M_SHPR3_PRI_13_Pos)
/* PRI_14 - Priority of system handler 14 (PendSV), bits[23:16] */
#define ARM_V7M_SHPR3_PRI_14_Pos        16U
#define ARM_V7M_SHPR3_PRI_14_Msk        (0xFFUL << ARM_V7M_SHPR3_PRI_14_Pos)
/* PRI_15 - Priority of system handler 15 (SysTick), bits[31:24] */
#define ARM_V7M_SHPR3_PRI_15_Pos        24U
#define ARM_V7M_SHPR3_PRI_15_Msk        (0xFFUL << ARM_V7M_SHPR3_PRI_15_Pos)

/* -----------------------------------------------------------------------------
 * 2.12 SHCSR 寄存器位域 (ARM_V7M_SCB_SHCSR)
 * 参考: B3.2.13 System Handler Control and State Register, SHCSR on page B3-607
 * -----------------------------------------------------------------------------
 */
/* USGFAULTENA - UsageFault enable, bit[18] */
#define ARM_V7M_SHCSR_USGFAULTENA_Pos   18U
#define ARM_V7M_SHCSR_USGFAULTENA_Msk   (1UL << ARM_V7M_SHCSR_USGFAULTENA_Pos)
/* BUSFAULTENA - BusFault enable, bit[17] */
#define ARM_V7M_SHCSR_BUSFAULTENA_Pos   17U
#define ARM_V7M_SHCSR_BUSFAULTENA_Msk   (1UL << ARM_V7M_SHCSR_BUSFAULTENA_Pos)
/* MEMFAULTENA - MemManage enable, bit[16] */
#define ARM_V7M_SHCSR_MEMFAULTENA_Pos   16U
#define ARM_V7M_SHCSR_MEMFAULTENA_Msk   (1UL << ARM_V7M_SHCSR_MEMFAULTENA_Pos)
/* SVCALLPENDED - SVCall pending, bit[15] */
#define ARM_V7M_SHCSR_SVCALLPENDED_Pos  15U
#define ARM_V7M_SHCSR_SVCALLPENDED_Msk  (1UL << ARM_V7M_SHCSR_SVCALLPENDED_Pos)
/* BUSFAULTPENDED - BusFault pending, bit[14] */
#define ARM_V7M_SHCSR_BUSFAULTPENDED_Pos 14U
#define ARM_V7M_SHCSR_BUSFAULTPENDED_Msk (1UL << ARM_V7M_SHCSR_BUSFAULTPENDED_Pos)
/* MEMFAULTPENDED - MemManage pending, bit[13] */
#define ARM_V7M_SHCSR_MEMFAULTPENDED_Pos 13U
#define ARM_V7M_SHCSR_MEMFAULTPENDED_Msk (1UL << ARM_V7M_SHCSR_MEMFAULTPENDED_Pos)
/* USGFAULTPENDED - UsageFault pending, bit[12] */
#define ARM_V7M_SHCSR_USGFAULTPENDED_Pos 12U
#define ARM_V7M_SHCSR_USGFAULTPENDED_Msk (1UL << ARM_V7M_SHCSR_USGFAULTPENDED_Pos)
/* SYSTICKACT - SysTick active, bit[11] */
#define ARM_V7M_SHCSR_SYSTICKACT_Pos    11U
#define ARM_V7M_SHCSR_SYSTICKACT_Msk    (1UL << ARM_V7M_SHCSR_SYSTICKACT_Pos)
/* PENDSVACT - PendSV active, bit[10] */
#define ARM_V7M_SHCSR_PENDSVACT_Pos     10U
#define ARM_V7M_SHCSR_PENDSVACT_Msk     (1UL << ARM_V7M_SHCSR_PENDSVACT_Pos)
/* MONITORACT - DebugMonitor active, bit[8] */
#define ARM_V7M_SHCSR_MONITORACT_Pos    8U
#define ARM_V7M_SHCSR_MONITORACT_Msk    (1UL << ARM_V7M_SHCSR_MONITORACT_Pos)
/* SVCALLACT - SVCall active, bit[7] */
#define ARM_V7M_SHCSR_SVCALLACT_Pos     7U
#define ARM_V7M_SHCSR_SVCALLACT_Msk     (1UL << ARM_V7M_SHCSR_SVCALLACT_Pos)
/* USGFAULTACT - UsageFault active, bit[3] */
#define ARM_V7M_SHCSR_USGFAULTACT_Pos   3U
#define ARM_V7M_SHCSR_USGFAULTACT_Msk   (1UL << ARM_V7M_SHCSR_USGFAULTACT_Pos)
/* BUSFAULTACT - BusFault active, bit[1] */
#define ARM_V7M_SHCSR_BUSFAULTACT_Pos   1U
#define ARM_V7M_SHCSR_BUSFAULTACT_Msk   (1UL << ARM_V7M_SHCSR_BUSFAULTACT_Pos)
/* MEMFAULTACT - MemManage active, bit[0] */
#define ARM_V7M_SHCSR_MEMFAULTACT_Pos   0U
#define ARM_V7M_SHCSR_MEMFAULTACT_Msk   (1UL << ARM_V7M_SHCSR_MEMFAULTACT_Pos)

/* -----------------------------------------------------------------------------
 * 2.13 MMFSR 寄存器位域 (CFSR 子寄存器, ARM_V7M_SCB_CFSR)
 * 参考: B3.2.15 Configurable Fault Status Register, CFSR on page B3-609
 * -----------------------------------------------------------------------------
 */
/* MMARVALID - MemManage Fault Address Register valid, bit[7] */
#define ARM_V7M_MMFSR_MMARVALID_Pos     7U
#define ARM_V7M_MMFSR_MMARVALID_Msk     (1UL << ARM_V7M_MMFSR_MMARVALID_Pos)
/* MLSPERR - MemManage Fault during lazy state preservation, bit[5] */
#define ARM_V7M_MMFSR_MLSPERR_Pos       5U
#define ARM_V7M_MMFSR_MLSPERR_Msk       (1UL << ARM_V7M_MMFSR_MLSPERR_Pos)
/* MSTKERR - MemManage Fault on stacking for exception entry, bit[4] */
#define ARM_V7M_MMFSR_MSTKERR_Pos       4U
#define ARM_V7M_MMFSR_MSTKERR_Msk       (1UL << ARM_V7M_MMFSR_MSTKERR_Pos)
/* MUNSTKERR - MemManage Fault on unstacking for exception return, bit[3] */
#define ARM_V7M_MMFSR_MUNSTKERR_Pos     3U
#define ARM_V7M_MMFSR_MUNSTKERR_Msk     (1UL << ARM_V7M_MMFSR_MUNSTKERR_Pos)
/* DACCVIOL - Data access violation, bit[1] */
#define ARM_V7M_MMFSR_DACCVIOL_Pos      1U
#define ARM_V7M_MMFSR_DACCVIOL_Msk      (1UL << ARM_V7M_MMFSR_DACCVIOL_Pos)
/* IACCVIOL - Instruction access violation, bit[0] */
#define ARM_V7M_MMFSR_IACCVIOL_Pos      0U
#define ARM_V7M_MMFSR_IACCVIOL_Msk      (1UL << ARM_V7M_MMFSR_IACCVIOL_Pos)

/* -----------------------------------------------------------------------------
 * 2.14 BFSR 寄存器位域 (CFSR 子寄存器, ARM_V7M_SCB_CFSR)
 * 参考: B3.2.15 Configurable Fault Status Register, CFSR on page B3-609
 * -----------------------------------------------------------------------------
 */
/* BFARVALID - BusFault Address Register valid, bit[7] */
#define ARM_V7M_BFSR_BFARVALID_Pos      7U
#define ARM_V7M_BFSR_BFARVALID_Msk      (1UL << ARM_V7M_BFSR_BFARVALID_Pos)
/* LSPERR - BusFault during lazy state preservation, bit[5] */
#define ARM_V7M_BFSR_LSPERR_Pos         5U
#define ARM_V7M_BFSR_LSPERR_Msk         (1UL << ARM_V7M_BFSR_LSPERR_Pos)
/* STKERR - BusFault on stacking for exception entry, bit[4] */
#define ARM_V7M_BFSR_STKERR_Pos         4U
#define ARM_V7M_BFSR_STKERR_Msk         (1UL << ARM_V7M_BFSR_STKERR_Pos)
/* UNSTKERR - BusFault on unstacking for exception return, bit[3] */
#define ARM_V7M_BFSR_UNSTKERR_Pos       3U
#define ARM_V7M_BFSR_UNSTKERR_Msk       (1UL << ARM_V7M_BFSR_UNSTKERR_Pos)
/* IMPRECISERR - Imprecise data bus error, bit[2] */
#define ARM_V7M_BFSR_IMPRECISERR_Pos    2U
#define ARM_V7M_BFSR_IMPRECISERR_Msk    (1UL << ARM_V7M_BFSR_IMPRECISERR_Pos)
/* PRECISERR - Precise data bus error, bit[1] */
#define ARM_V7M_BFSR_PRECISERR_Pos      1U
#define ARM_V7M_BFSR_PRECISERR_Msk      (1UL << ARM_V7M_BFSR_PRECISERR_Pos)
/* IBUSERR - Instruction bus error, bit[0] */
#define ARM_V7M_BFSR_IBUSERR_Pos        0U
#define ARM_V7M_BFSR_IBUSERR_Msk        (1UL << ARM_V7M_BFSR_IBUSERR_Pos)

/* -----------------------------------------------------------------------------
 * 2.15 UFSR 寄存器位域 (CFSR 子寄存器, ARM_V7M_SCB_CFSR)
 * 参考: B3.2.15 Configurable Fault Status Register, CFSR on page B3-609
 * -----------------------------------------------------------------------------
 */
/* DIVBYZERO - Divide by zero usage fault, bit[9] */
#define ARM_V7M_UFSR_DIVBYZERO_Pos      9U
#define ARM_V7M_UFSR_DIVBYZERO_Msk      (1UL << ARM_V7M_UFSR_DIVBYZERO_Pos)
/* UNALIGNED - Unaligned access usage fault, bit[8] */
#define ARM_V7M_UFSR_UNALIGNED_Pos      8U
#define ARM_V7M_UFSR_UNALIGNED_Msk      (1UL << ARM_V7M_UFSR_UNALIGNED_Pos)
/* NOCP - No coprocessor usage fault, bit[3] */
#define ARM_V7M_UFSR_NOCP_Pos           3U
#define ARM_V7M_UFSR_NOCP_Msk           (1UL << ARM_V7M_UFSR_NOCP_Pos)
/* INVPC - Invalid PC load usage fault, bit[2] */
#define ARM_V7M_UFSR_INVPC_Pos          2U
#define ARM_V7M_UFSR_INVPC_Msk          (1UL << ARM_V7M_UFSR_INVPC_Pos)
/* INVSTATE - Invalid state usage fault, bit[1] */
#define ARM_V7M_UFSR_INVSTATE_Pos       1U
#define ARM_V7M_UFSR_INVSTATE_Msk       (1UL << ARM_V7M_UFSR_INVSTATE_Pos)
/* UNDEFINSTR - Undefined instruction usage fault, bit[0] */
#define ARM_V7M_UFSR_UNDEFINSTR_Pos     0U
#define ARM_V7M_UFSR_UNDEFINSTR_Msk     (1UL << ARM_V7M_UFSR_UNDEFINSTR_Pos)

/* -----------------------------------------------------------------------------
 * 2.16 HFSR 寄存器位域 (ARM_V7M_SCB_HFSR)
 * 参考: B3.2.16 HardFault Status Register, HFSR on page B3-612
 * -----------------------------------------------------------------------------
 */
/* DEBUGEVT - Debug event hard fault, bit[31] */
#define ARM_V7M_HFSR_DEBUGEVT_Pos       31U
#define ARM_V7M_HFSR_DEBUGEVT_Msk       (1UL << ARM_V7M_HFSR_DEBUGEVT_Pos)
/* FORCED - Forced hard fault, bit[30] */
#define ARM_V7M_HFSR_FORCED_Pos         30U
#define ARM_V7M_HFSR_FORCED_Msk         (1UL << ARM_V7M_HFSR_FORCED_Pos)
/* VECTTBL - Vector table hard fault, bit[1] */
#define ARM_V7M_HFSR_VECTTBL_Pos        1U
#define ARM_V7M_HFSR_VECTTBL_Msk        (1UL << ARM_V7M_HFSR_VECTTBL_Pos)

/* -----------------------------------------------------------------------------
 * 2.17 DFSR 寄存器位域 (ARM_V7M_SCB_DFSR)
 * 参考: C1.6.1 Debug Fault Status Register, DFSR on page C1-699
 * -----------------------------------------------------------------------------
 */
/* EXTERNAL - External debug request, bit[4] */
#define ARM_V7M_DFSR_EXTERNAL_Pos       4U
#define ARM_V7M_DFSR_EXTERNAL_Msk       (1UL << ARM_V7M_DFSR_EXTERNAL_Pos)
/* VCATCH - Vector catch, bit[3] */
#define ARM_V7M_DFSR_VCATCH_Pos         3U
#define ARM_V7M_DFSR_VCATCH_Msk         (1UL << ARM_V7M_DFSR_VCATCH_Pos)
/* DWTTRAP - DWT debug event, bit[2] */
#define ARM_V7M_DFSR_DWTTRAP_Pos        2U
#define ARM_V7M_DFSR_DWTTRAP_Msk        (1UL << ARM_V7M_DFSR_DWTTRAP_Pos)
/* BKPT - Breakpoint debug event, bit[1] */
#define ARM_V7M_DFSR_BKPT_Pos           1U
#define ARM_V7M_DFSR_BKPT_Msk           (1UL << ARM_V7M_DFSR_BKPT_Pos)
/* HALTED - Halt debug event, bit[0] */
#define ARM_V7M_DFSR_HALTED_Pos         0U
#define ARM_V7M_DFSR_HALTED_Msk         (1UL << ARM_V7M_DFSR_HALTED_Pos)

/* -----------------------------------------------------------------------------
 * 2.18 CPACR 寄存器位域 (ARM_V7M_SCB_CPACR)
 * 参考: B3.2.20 Coprocessor Access Control Register, CPACR on page B3-614
 * -----------------------------------------------------------------------------
 */
/* CP10 - Coprocessor 10 access, bits[21:20] */
#define ARM_V7M_CPACR_CP10_Pos          20U
#define ARM_V7M_CPACR_CP10_Msk          (3UL << ARM_V7M_CPACR_CP10_Pos)
/* CP11 - Coprocessor 11 access, bits[23:22] */
#define ARM_V7M_CPACR_CP11_Pos          22U
#define ARM_V7M_CPACR_CP11_Msk          (3UL << ARM_V7M_CPACR_CP11_Pos)

/* -----------------------------------------------------------------------------
 * 2.19 STIR 寄存器位域 (ARM_V7M_SCS_STIR)
 * 参考: B3.2.26 Software Triggered Interrupt Register, STIR on page B3-619
 * -----------------------------------------------------------------------------
 */
/* INTID - Interrupt ID to trigger, bits[8:0] */
#define ARM_V7M_STIR_INTID_Pos          0U
#define ARM_V7M_STIR_INTID_Msk          (0x1FFUL << ARM_V7M_STIR_INTID_Pos)

/* -----------------------------------------------------------------------------
 * 2.20 ID_PFR0 寄存器位域 (ARM_V7M_SCB_ID_PFR0)
 * 参考: B4.2.1 Processor Feature Register 0, ID_PFR0 on page B4-646
 * -----------------------------------------------------------------------------
 */
/* STATE0 - State 0 feature, bits[3:0] */
#define ARM_V7M_PFR0_STATE0_Pos         0U
#define ARM_V7M_PFR0_STATE0_Msk         (0xFUL << ARM_V7M_PFR0_STATE0_Pos)
/* STATE1 - State 1 feature, bits[7:4] */
#define ARM_V7M_PFR0_STATE1_Pos         4U
#define ARM_V7M_PFR0_STATE1_Msk         (0xFUL << ARM_V7M_PFR0_STATE1_Pos)
/* STATE2 - State 2 feature, bits[11:8] */
#define ARM_V7M_PFR0_STATE2_Pos         8U
#define ARM_V7M_PFR0_STATE2_Msk         (0xFUL << ARM_V7M_PFR0_STATE2_Pos)
/* STATE3 - State 3 feature, bits[15:12] */
#define ARM_V7M_PFR0_STATE3_Pos         12U
#define ARM_V7M_PFR0_STATE3_Msk         (0xFUL << ARM_V7M_PFR0_STATE3_Pos)

/* -----------------------------------------------------------------------------
 * 2.21 ID_PFR1 寄存器位域 (ARM_V7M_SCB_ID_PFR1)
 * 参考: B4.2.2 Processor Feature Register 1, ID_PFR1 on page B4-646
 * -----------------------------------------------------------------------------
 */
/* PROGMOD - Programmer's model feature, bits[3:0] */
#define ARM_V7M_PFR1_PROGMOD_Pos        0U
#define ARM_V7M_PFR1_PROGMOD_Msk        (0xFUL << ARM_V7M_PFR1_PROGMOD_Pos)
/* SECURITY - Security feature, bits[7:4] */
#define ARM_V7M_PFR1_SECURITY_Pos       4U
#define ARM_V7M_PFR1_SECURITY_Msk       (0xFUL << ARM_V7M_PFR1_SECURITY_Pos)
/* MPROGMOD - Memory programmer's model feature, bits[11:8] */
#define ARM_V7M_PFR1_MPROGMOD_Pos       8U
#define ARM_V7M_PFR1_MPROGMOD_Msk       (0xFUL << ARM_V7M_PFR1_MPROGMOD_Pos)

/* -----------------------------------------------------------------------------
 * 2.22 ID_DFR0 寄存器位域 (ARM_V7M_SCB_ID_DFR0)
 * 参考: B4.3.1 Debug Feature Register 0, ID_DFR0 on page B4-648
 * -----------------------------------------------------------------------------
 */
/* COPDBG - Coprocessor debug feature, bits[3:0] */
#define ARM_V7M_DFR0_COPDBG_Pos         0U
#define ARM_V7M_DFR0_COPDBG_Msk         (0xFUL << ARM_V7M_DFR0_COPDBG_Pos)
/* COPSDBG - Coprocessor secure debug feature, bits[7:4] */
#define ARM_V7M_DFR0_COPSDBG_Pos        4U
#define ARM_V7M_DFR0_COPSDBG_Msk        (0xFUL << ARM_V7M_DFR0_COPSDBG_Pos)
/* MMAPDBG - Memory map debug feature, bits[11:8] */
#define ARM_V7M_DFR0_MMAPDBG_Pos        8U
#define ARM_V7M_DFR0_MMAPDBG_Msk        (0xFUL << ARM_V7M_DFR0_MMAPDBG_Pos)
/* COPTRC - Coprocessor trace feature, bits[15:12] */
#define ARM_V7M_DFR0_COPTRC_Pos         12U
#define ARM_V7M_DFR0_COPTRC_Msk         (0xFUL << ARM_V7M_DFR0_COPTRC_Pos)
/* MMAPTRC - Memory map trace feature, bits[19:16] */
#define ARM_V7M_DFR0_MMAPTRC_Pos        16U
#define ARM_V7M_DFR0_MMAPTRC_Msk        (0xFUL << ARM_V7M_DFR0_MMAPTRC_Pos)

/* -----------------------------------------------------------------------------
 * 2.23 ID_AFR0 寄存器位域 (ARM_V7M_SCB_ID_AFR0)
 * 参考: B4.4.1 Auxiliary Feature Register 0, ID_AFR0 on page B4-649
 * -----------------------------------------------------------------------------
 */
/* ID_AFR0 - 辅助特性寄存器，位域定义参考手册，内容为 IMPLEMENTATION DEFINED */

/* -----------------------------------------------------------------------------
 * 2.24 ID_MMFR0 寄存器位域 (ARM_V7M_SCB_ID_MMFR0)
 * 参考: B4.5 Memory Model Feature Registers on page B4-650
 * -----------------------------------------------------------------------------
 */
/* VMSA - Virtual Memory System Architecture feature, bits[3:0] */
#define ARM_V7M_MMFR0_VMSA_Pos          0U
#define ARM_V7M_MMFR0_VMSA_Msk          (0xFUL << ARM_V7M_MMFR0_VMSA_Pos)
/* PMSA - Physical Memory System Architecture feature, bits[7:4] */
#define ARM_V7M_MMFR0_PMSA_Pos          4U
#define ARM_V7M_MMFR0_PMSA_Msk          (0xFUL << ARM_V7M_MMFR0_PMSA_Pos)
/* OUTERSHR - Outer shareability feature, bits[11:8] */
#define ARM_V7M_MMFR0_OUTERSHR_Pos      8U
#define ARM_V7M_MMFR0_OUTERSHR_Msk      (0xFUL << ARM_V7M_MMFR0_OUTERSHR_Pos)
/* SHARELVL - Shareability level feature, bits[15:12] */
#define ARM_V7M_MMFR0_SHARELVL_Pos      12U
#define ARM_V7M_MMFR0_SHARELVL_Msk      (0xFUL << ARM_V7M_MMFR0_SHARELVL_Pos)
/* TCM - Tightly Coupled Memory feature, bits[19:16] */
#define ARM_V7M_MMFR0_TCM_Pos           16U
#define ARM_V7M_MMFR0_TCM_Msk           (0xFUL << ARM_V7M_MMFR0_TCM_Pos)
/* AUXREG - Auxiliary register feature, bits[23:20] */
#define ARM_V7M_MMFR0_AUXREG_Pos        20U
#define ARM_V7M_MMFR0_AUXREG_Msk        (0xFUL << ARM_V7M_MMFR0_AUXREG_Pos)
/* FCSE - Fast Context Switch Extension feature, bits[27:24] */
#define ARM_V7M_MMFR0_FCSE_Pos          24U
#define ARM_V7M_MMFR0_FCSE_Msk          (0xFUL << ARM_V7M_MMFR0_FCSE_Pos)
/* INNERSHR - Inner shareability feature, bits[31:28] */
#define ARM_V7M_MMFR0_INNERSHR_Pos      28U
#define ARM_V7M_MMFR0_INNERSHR_Msk      (0xFUL << ARM_V7M_MMFR0_INNERSHR_Pos)

/* -----------------------------------------------------------------------------
 * 2.25 ID_MMFR1 寄存器位域 (ARM_V7M_SCB_ID_MMFR1)
 * 参考: B4.5 Memory Model Feature Registers on page B4-650
 * -----------------------------------------------------------------------------
 */
/* AUXFR - Auxiliary features, bits[3:0] */
#define ARM_V7M_MMFR1_AUXFR_Pos         0U
#define ARM_V7M_MMFR1_AUXFR_Msk         (0xFUL << ARM_V7M_MMFR1_AUXFR_Pos)
/* FCSE - Fast Context Switch Extension, bits[7:4] */
#define ARM_V7M_MMFR1_FCSE_Pos          4U
#define ARM_V7M_MMFR1_FCSE_Msk          (0xFUL << ARM_V7M_MMFR1_FCSE_Pos)
/* UNIFIED - Unified memory system, bits[11:8] */
#define ARM_V7M_MMFR1_UNIFIED_Pos        8U
#define ARM_V7M_MMFR1_UNIFIED_Msk        (0xFUL << ARM_V7M_MMFR1_UNIFIED_Pos)
/* BTB - Branch target buffer, bits[15:12] */
#define ARM_V7M_MMFR1_BTB_Pos            12U
#define ARM_V7M_MMFR1_BTB_Msk            (0xFUL << ARM_V7M_MMFR1_BTB_Pos)
/* HIPT - Harvard instruction and TLB, bits[19:16] */
#define ARM_V7M_MMFR1_HIPT_Pos           16U
#define ARM_V7M_MMFR1_HIPT_Msk           (0xFUL << ARM_V7M_MMFR1_HIPT_Pos)
/* SMP - Symmetric Multi-Processing, bits[23:20] */
#define ARM_V7M_MMFR1_SMP_Pos            20U
#define ARM_V7M_MMFR1_SMP_Msk            (0xFUL << ARM_V7M_MMFR1_SMP_Pos)
/* PMSA - Physical Memory System Architecture, bits[27:24] */
#define ARM_V7M_MMFR1_PMSA_Pos           24U
#define ARM_V7M_MMFR1_PMSA_Msk           (0xFUL << ARM_V7M_MMFR1_PMSA_Pos)
/* VMSA - Virtual Memory System Architecture, bits[31:28] */
#define ARM_V7M_MMFR1_VMSA_Pos           28U
#define ARM_V7M_MMFR1_VMSA_Msk           (0xFUL << ARM_V7M_MMFR1_VMSA_Pos)

/* -----------------------------------------------------------------------------
 * 2.26 ID_MMFR2 寄存器位域 (ARM_V7M_SCB_ID_MMFR2)
 * 参考: B4.5 Memory Model Feature Registers on page B4-650
 * -----------------------------------------------------------------------------
 */
/* WFI - Wait For Interrupt, bits[3:0] */
#define ARM_V7M_MMFR2_WFI_Pos            0U
#define ARM_V7M_MMFR2_WFI_Msk            (0xFUL << ARM_V7M_MMFR2_WFI_Pos)
/* WFE - Wait For Event, bits[7:4] */
#define ARM_V7M_MMFR2_WFE_Pos            4U
#define ARM_V7M_MMFR2_WFE_Msk            (0xFUL << ARM_V7M_MMFR2_WFE_Pos)
/* SEV - Send Event, bits[11:8] */
#define ARM_V7M_MMFR2_SEV_Pos            8U
#define ARM_V7M_MMFR2_SEV_Msk            (0xFUL << ARM_V7M_MMFR2_SEV_Pos)
/* WB - Write-back, bits[15:12] */
#define ARM_V7M_MMFR2_WB_Pos             12U
#define ARM_V7M_MMFR2_WB_Msk             (0xFUL << ARM_V7M_MMFR2_WB_Pos)
/* SW - Store write-back, bits[19:16] */
#define ARM_V7M_MMFR2_SW_Pos             16U
#define ARM_V7M_MMFR2_SW_Msk             (0xFUL << ARM_V7M_MMFR2_SW_Pos)
/* HINT - Hint instructions, bits[23:20] */
#define ARM_V7M_MMFR2_HINT_Pos           20U
#define ARM_V7M_MMFR2_HINT_Msk           (0xFUL << ARM_V7M_MMFR2_HINT_Pos)
/* DIV0 - Divide by zero, bits[27:24] */
#define ARM_V7M_MMFR2_DIV0_Pos           24U
#define ARM_V7M_MMFR2_DIV0_Msk           (0xFUL << ARM_V7M_MMFR2_DIV0_Pos)
/* UNALIGN - Unaligned access, bits[31:28] */
#define ARM_V7M_MMFR2_UNALIGN_Pos        28U
#define ARM_V7M_MMFR2_UNALIGN_Msk        (0xFUL << ARM_V7M_MMFR2_UNALIGN_Pos)

/* -----------------------------------------------------------------------------
 * 2.27 ID_MMFR3 寄存器位域 (ARM_V7M_SCB_ID_MMFR3)
 * 参考: B4.5 Memory Model Feature Registers on page B4-650
 * -----------------------------------------------------------------------------
 */
/* CMO - Cache maintenance operations, bits[3:0] */
#define ARM_V7M_MMFR3_CMO_Pos            0U
#define ARM_V7M_MMFR3_CMO_Msk            (0xFUL << ARM_V7M_MMFR3_CMO_Pos)
/* SB - Store barrier, bits[7:4] */
#define ARM_V7M_MMFR3_SB_Pos             4U
#define ARM_V7M_MMFR3_SB_Msk             (0xFUL << ARM_V7M_MMFR3_SB_Pos)
/* SBZH - Store barrier zeroing hint, bits[11:8] */
#define ARM_V7M_MMFR3_SBZH_Pos           8U
#define ARM_V7M_MMFR3_SBZH_Msk           (0xFUL << ARM_V7M_MMFR3_SBZH_Pos)
/* INVARIANT - Invariant support, bits[15:12] */
#define ARM_V7M_MMFR3_INVARIANT_Pos      12U
#define ARM_V7M_MMFR3_INVARIANT_Msk      (0xFUL << ARM_V7M_MMFR3_INVARIANT_Pos)
/* BARRIER - Barrier instructions, bits[19:16] */
#define ARM_V7M_MMFR3_BARRIER_Pos        16U
#define ARM_V7M_MMFR3_BARRIER_Msk        (0xFUL << ARM_V7M_MMFR3_BARRIER_Pos)
/* COHERENT - Coherent support, bits[23:20] */
#define ARM_V7M_MMFR3_COHERENT_Pos       20U
#define ARM_V7M_MMFR3_COHERENT_Msk       (0xFUL << ARM_V7M_MMFR3_COHERENT_Pos)
/* BCAST - Broadcast support, bits[27:24] */
#define ARM_V7M_MMFR3_BCAST_Pos          24U
#define ARM_V7M_MMFR3_BCAST_Msk          (0xFUL << ARM_V7M_MMFR3_BCAST_Pos)
/* L1I - Level 1 instruction cache, bits[31:28] */
#define ARM_V7M_MMFR3_L1I_Pos            28U
#define ARM_V7M_MMFR3_L1I_Msk            (0xFUL << ARM_V7M_MMFR3_L1I_Pos)

/* -----------------------------------------------------------------------------
 * 2.28 ID_ISAR0 寄存器位域 (ARM_V7M_SCB_ID_ISAR0)
 * 参考: B4.6 Instruction Set Attribute Registers on page B4-653
 * -----------------------------------------------------------------------------
 */
/* DIVIDE - Divide instructions, bits[3:0] */
#define ARM_V7M_ISAR0_DIVIDE_Pos         0U
#define ARM_V7M_ISAR0_DIVIDE_Msk         (0xFUL << ARM_V7M_ISAR0_DIVIDE_Pos)
/* DEBUGEX - Debug extensions, bits[7:4] */
#define ARM_V7M_ISAR0_DEBUGEX_Pos        4U
#define ARM_V7M_ISAR0_DEBUGEX_Msk        (0xFUL << ARM_V7M_ISAR0_DEBUGEX_Pos)
/* CP15BAR - CP15 barrier, bits[11:8] */
#define ARM_V7M_ISAR0_CP15BAR_Pos        8U
#define ARM_V7M_ISAR0_CP15BAR_Msk        (0xFUL << ARM_V7M_ISAR0_CP15BAR_Pos)
/* JAZELLE - Jazelle extension, bits[15:12] */
#define ARM_V7M_ISAR0_JAZELLE_Pos        12U
#define ARM_V7M_ISAR0_JAZELLE_Msk        (0xFUL << ARM_V7M_ISAR0_JAZELLE_Pos)
/* THUMBEE - ThumbEE extension, bits[19:16] */
#define ARM_V7M_ISAR0_THUMBEE_Pos        16U
#define ARM_V7M_ISAR0_THUMBEE_Msk        (0xFUL << ARM_V7M_ISAR0_THUMBEE_Pos)
/* THUMB - Thumb instructions, bits[23:20] */
#define ARM_V7M_ISAR0_THUMB_Pos          20U
#define ARM_V7M_ISAR0_THUMB_Msk          (0xFUL << ARM_V7M_ISAR0_THUMB_Pos)
/* ARM - ARM instructions, bits[27:24] */
#define ARM_V7M_ISAR0_ARM_Pos            24U
#define ARM_V7M_ISAR0_ARM_Msk            (0xFUL << ARM_V7M_ISAR0_ARM_Pos)
/* ENDIAN - Endian support, bits[31:28] */
#define ARM_V7M_ISAR0_ENDIAN_Pos         28U
#define ARM_V7M_ISAR0_ENDIAN_Msk         (0xFUL << ARM_V7M_ISAR0_ENDIAN_Pos)

/* -----------------------------------------------------------------------------
 * 2.29 ID_ISAR1 寄存器位域 (ARM_V7M_SCB_ID_ISAR1)
 * 参考: B4.6 Instruction Set Attribute Registers on page B4-653
 * -----------------------------------------------------------------------------
 */
/* BFEXTEND - Bit field extend instructions, bits[3:0] */
#define ARM_V7M_ISAR1_BFEXTEND_Pos       0U
#define ARM_V7M_ISAR1_BFEXTEND_Msk       (0xFUL << ARM_V7M_ISAR1_BFEXTEND_Pos)
/* IFTHEN - If-Then instructions, bits[7:4] */
#define ARM_V7M_ISAR1_IFTHEN_Pos         4U
#define ARM_V7M_ISAR1_IFTHEN_Msk         (0xFUL << ARM_V7M_ISAR1_IFTHEN_Pos)
/* LDRDC - LDRDC instruction, bits[11:8] */
#define ARM_V7M_ISAR1_LDRDC_Pos          8U
#define ARM_V7M_ISAR1_LDRDC_Msk          (0xFUL << ARM_V7M_ISAR1_LDRDC_Pos)
/* LDMSTM - LDM/STM instructions, bits[15:12] */
#define ARM_V7M_ISAR1_LDMSTM_Pos         12U
#define ARM_V7M_ISAR1_LDMSTM_Msk         (0xFUL << ARM_V7M_ISAR1_LDMSTM_Pos)
/* EXCEPTION - Exception instructions, bits[19:16] */
#define ARM_V7M_ISAR1_EXCEPTION_Pos      16U
#define ARM_V7M_ISAR1_EXCEPTION_Msk      (0xFUL << ARM_V7M_ISAR1_EXCEPTION_Pos)
/* BXJ - BXJ instruction, bits[23:20] */
#define ARM_V7M_ISAR1_BXJ_Pos            20U
#define ARM_V7M_ISAR1_BXJ_Msk            (0xFUL << ARM_V7M_ISAR1_BXJ_Pos)
/* BX - BX instruction, bits[27:24] */
#define ARM_V7M_ISAR1_BX_Pos             24U
#define ARM_V7M_ISAR1_BX_Msk             (0xFUL << ARM_V7M_ISAR1_BX_Pos)
/* THUMBCOPY - Thumb copy instructions, bits[31:28] */
#define ARM_V7M_ISAR1_THUMBCOPY_Pos      28U
#define ARM_V7M_ISAR1_THUMBCOPY_Msk      (0xFUL << ARM_V7M_ISAR1_THUMBCOPY_Pos)

/* -----------------------------------------------------------------------------
 * 2.30 ID_ISAR2 寄存器位域 (ARM_V7M_SCB_ID_ISAR2)
 * 参考: B4.6 Instruction Set Attribute Registers on page B4-653
 * -----------------------------------------------------------------------------
 */
/* PLD - PLD instructions, bits[3:0] */
#define ARM_V7M_ISAR2_PLD_Pos            0U
#define ARM_V7M_ISAR2_PLD_Msk            (0xFUL << ARM_V7M_ISAR2_PLD_Pos)
/* PLI - PLI instructions, bits[7:4] */
#define ARM_V7M_ISAR2_PLI_Pos            4U
#define ARM_V7M_ISAR2_PLI_Msk            (0xFUL << ARM_V7M_ISAR2_PLI_Pos)
/* BARRIER - Barrier instructions, bits[11:8] */
#define ARM_V7M_ISAR2_BARRIER_Pos        8U
#define ARM_V7M_ISAR2_BARRIER_Msk        (0xFUL << ARM_V7M_ISAR2_BARRIER_Pos)
/* MSR_MREG - MSR to special registers, bits[15:12] */
#define ARM_V7M_ISAR2_MSR_MREG_Pos       12U
#define ARM_V7M_ISAR2_MSR_MREG_Msk       (0xFUL << ARM_V7M_ISAR2_MSR_MREG_Pos)
/* MOVT - MOVT instruction, bits[19:16] */
#define ARM_V7M_ISAR2_MOVT_Pos           16U
#define ARM_V7M_ISAR2_MOVT_Msk           (0xFUL << ARM_V7M_ISAR2_MOVT_Pos)
/* MOVW - MOVW instruction, bits[23:20] */
#define ARM_V7M_ISAR2_MOVW_Pos           20U
#define ARM_V7M_ISAR2_MOVW_Msk           (0xFUL << ARM_V7M_ISAR2_MOVW_Pos)
/* TBB - TBB instruction, bits[27:24] */
#define ARM_V7M_ISAR2_TBB_Pos            24U
#define ARM_V7M_ISAR2_TBB_Msk            (0xFUL << ARM_V7M_ISAR2_TBB_Pos)
/* TBH - TBH instruction, bits[31:28] */
#define ARM_V7M_ISAR2_TBH_Pos            28U
#define ARM_V7M_ISAR2_TBH_Msk            (0xFUL << ARM_V7M_ISAR2_TBH_Pos)

/* -----------------------------------------------------------------------------
 * 2.31 ID_ISAR3 寄存器位域 (ARM_V7M_SCB_ID_ISAR3)
 * 参考: B4.6 Instruction Set Attribute Registers on page B4-653
 * -----------------------------------------------------------------------------
 */
/* SBFX - SBFX instruction, bits[3:0] */
#define ARM_V7M_ISAR3_SBFX_Pos           0U
#define ARM_V7M_ISAR3_SBFX_Msk           (0xFUL << ARM_V7M_ISAR3_SBFX_Pos)
/* UBFX - UBFX instruction, bits[7:4] */
#define ARM_V7M_ISAR3_UBFX_Pos           4U
#define ARM_V7M_ISAR3_UBFX_Msk           (0xFUL << ARM_V7M_ISAR3_UBFX_Pos)
/* SBFX16 - SBFX16 instruction, bits[11:8] */
#define ARM_V7M_ISAR3_SBFX16_Pos         8U
#define ARM_V7M_ISAR3_SBFX16_Msk         (0xFUL << ARM_V7M_ISAR3_SBFX16_Pos)
/* UBFX16 - UBFX16 instruction, bits[15:12] */
#define ARM_V7M_ISAR3_UBFX16_Pos         12U
#define ARM_V7M_ISAR3_UBFX16_Msk         (0xFUL << ARM_V7M_ISAR3_UBFX16_Pos)
/* SBFX32 - SBFX32 instruction, bits[19:16] */
#define ARM_V7M_ISAR3_SBFX32_Pos         16U
#define ARM_V7M_ISAR3_SBFX32_Msk         (0xFUL << ARM_V7M_ISAR3_SBFX32_Pos)
/* UBFX32 - UBFX32 instruction, bits[23:20] */
#define ARM_V7M_ISAR3_UBFX32_Pos         20U
#define ARM_V7M_ISAR3_UBFX32_Msk         (0xFUL << ARM_V7M_ISAR3_UBFX32_Pos)
/* BFC - BFC instruction, bits[27:24] */
#define ARM_V7M_ISAR3_BFC_Pos            24U
#define ARM_V7M_ISAR3_BFC_Msk            (0xFUL << ARM_V7M_ISAR3_BFC_Pos)
/* BFI - BFI instruction, bits[31:28] */
#define ARM_V7M_ISAR3_BFI_Pos            28U
#define ARM_V7M_ISAR3_BFI_Msk            (0xFUL << ARM_V7M_ISAR3_BFI_Pos)

/* -----------------------------------------------------------------------------
 * 2.32 ID_ISAR4 寄存器位域 (ARM_V7M_SCB_ID_ISAR4)
 * 参考: B4.6 Instruction Set Attribute Registers on page B4-653
 * -----------------------------------------------------------------------------
 */
/* WFE - WFE instruction, bits[3:0] */
#define ARM_V7M_ISAR4_WFE_Pos            0U
#define ARM_V7M_ISAR4_WFE_Msk            (0xFUL << ARM_V7M_ISAR4_WFE_Pos)
/* WFI - WFI instruction, bits[7:4] */
#define ARM_V7M_ISAR4_WFI_Pos            4U
#define ARM_V7M_ISAR4_WFI_Msk            (0xFUL << ARM_V7M_ISAR4_WFI_Pos)
/* SEV - SEV instruction, bits[11:8] */
#define ARM_V7M_ISAR4_SEV_Pos            8U
#define ARM_V7M_ISAR4_SEV_Msk            (0xFUL << ARM_V7M_ISAR4_SEV_Pos)
/* CLZ - CLZ instruction, bits[15:12] */
#define ARM_V7M_ISAR4_CLZ_Pos            12U
#define ARM_V7M_ISAR4_CLZ_Msk            (0xFUL << ARM_V7M_ISAR4_CLZ_Pos)
/* QADD - QADD instruction, bits[19:16] */
#define ARM_V7M_ISAR4_QADD_Pos           16U
#define ARM_V7M_ISAR4_QADD_Msk           (0xFUL << ARM_V7M_ISAR4_QADD_Pos)
/* QDADD - QDADD instruction, bits[23:20] */
#define ARM_V7M_ISAR4_QDADD_Pos          20U
#define ARM_V7M_ISAR4_QDADD_Msk          (0xFUL << ARM_V7M_ISAR4_QDADD_Pos)
/* QDSUB - QDSUB instruction, bits[27:24] */
#define ARM_V7M_ISAR4_QDSUB_Pos          24U
#define ARM_V7M_ISAR4_QDSUB_Msk          (0xFUL << ARM_V7M_ISAR4_QDSUB_Pos)
/* QSUB - QSUB instruction, bits[31:28] */
#define ARM_V7M_ISAR4_QSUB_Pos           28U
#define ARM_V7M_ISAR4_QSUB_Msk           (0xFUL << ARM_V7M_ISAR4_QSUB_Pos)

/* -----------------------------------------------------------------------------
 * 2.33 ID_ISAR5 寄存器位域 (ARM_V7M_SCB_ID_ISAR5)
 * 参考: B4.6 Instruction Set Attribute Registers on page B4-653
 * -----------------------------------------------------------------------------
 */
/* RBIT - RBIT instruction, bits[3:0] */
#define ARM_V7M_ISAR5_RBIT_Pos           0U
#define ARM_V7M_ISAR5_RBIT_Msk           (0xFUL << ARM_V7M_ISAR5_RBIT_Pos)
/* REV - REV instruction, bits[7:4] */
#define ARM_V7M_ISAR5_REV_Pos            4U
#define ARM_V7M_ISAR5_REV_Msk            (0xFUL << ARM_V7M_ISAR5_REV_Pos)
/* REV16 - REV16 instruction, bits[11:8] */
#define ARM_V7M_ISAR5_REV16_Pos          8U
#define ARM_V7M_ISAR5_REV16_Msk          (0xFUL << ARM_V7M_ISAR5_REV16_Pos)
/* REVSH - REVSH instruction, bits[15:12] */
#define ARM_V7M_ISAR5_REVSH_Pos          12U
#define ARM_V7M_ISAR5_REVSH_Msk          (0xFUL << ARM_V7M_ISAR5_REVSH_Pos)
/* SEL - SEL instruction, bits[19:16] */
#define ARM_V7M_ISAR5_SEL_Pos            16U
#define ARM_V7M_ISAR5_SEL_Msk            (0xFUL << ARM_V7M_ISAR5_SEL_Pos)
/* SXTB - SXTB instruction, bits[23:20] */
#define ARM_V7M_ISAR5_SXTB_Pos           20U
#define ARM_V7M_ISAR5_SXTB_Msk           (0xFUL << ARM_V7M_ISAR5_SXTB_Pos)
/* SXTH - SXTH instruction, bits[27:24] */
#define ARM_V7M_ISAR5_SXTH_Pos           24U
#define ARM_V7M_ISAR5_SXTH_Msk           (0xFUL << ARM_V7M_ISAR5_SXTH_Pos)
/* UXTB - UXTB instruction, bits[31:28] */
#define ARM_V7M_ISAR5_UXTB_Pos           28U
#define ARM_V7M_ISAR5_UXTB_Msk           (0xFUL << ARM_V7M_ISAR5_UXTB_Pos)

/* -----------------------------------------------------------------------------
 * 2.34 CLIDR 寄存器位域 (ARM_V7M_SCB_CLIDR)
 * 参考: B4.8.1 Cache Level ID Register, CLIDR on page B4-665
 * -----------------------------------------------------------------------------
 */
/* LOUU - Level of Unification Uniprocessor, bits[29:27] */
#define ARM_V7M_CLIDR_LOUU_Pos        27U
#define ARM_V7M_CLIDR_LOUU_Msk        (7UL << ARM_V7M_CLIDR_LOUU_Pos)
/* LOC - Level of Coherency, bits[26:24] */
#define ARM_V7M_CLIDR_LOC_Pos          24U
#define ARM_V7M_CLIDR_LOC_Msk          (7UL << ARM_V7M_CLIDR_LOC_Pos)
/* CTYPE7 - Cache Type 7, bits[23:21] */
#define ARM_V7M_CLIDR_CTYPE7_Pos        21U
#define ARM_V7M_CLIDR_CTYPE7_Msk        (7UL << ARM_V7M_CLIDR_CTYPE7_Pos)
/* CTYPE6 - Cache Type 6, bits[20:18] */
#define ARM_V7M_CLIDR_CTYPE6_Pos        18U
#define ARM_V7M_CLIDR_CTYPE6_Msk        (7UL << ARM_V7M_CLIDR_CTYPE6_Pos)
/* CTYPE5 - Cache Type 5, bits[17:15] */
#define ARM_V7M_CLIDR_CTYPE5_Pos        15U
#define ARM_V7M_CLIDR_CTYPE5_Msk        (7UL << ARM_V7M_CLIDR_CTYPE5_Pos)
/* CTYPE4 - Cache Type 4, bits[14:12] */
#define ARM_V7M_CLIDR_CTYPE4_Pos        12U
#define ARM_V7M_CLIDR_CTYPE4_Msk        (7UL << ARM_V7M_CLIDR_CTYPE4_Pos)
/* CTYPE3 - Cache Type 3, bits[11:9] */
#define ARM_V7M_CLIDR_CTYPE3_Pos        9U
#define ARM_V7M_CLIDR_CTYPE3_Msk        (7UL << ARM_V7M_CLIDR_CTYPE3_Pos)
/* CTYPE2 - Cache Type 2, bits[8:6] */
#define ARM_V7M_CLIDR_CTYPE2_Pos        6U
#define ARM_V7M_CLIDR_CTYPE2_Msk        (7UL << ARM_V7M_CLIDR_CTYPE2_Pos)
/* CTYPE1 - Cache Type 1, bits[5:3] */
#define ARM_V7M_CLIDR_CTYPE1_Pos        3U
#define ARM_V7M_CLIDR_CTYPE1_Msk        (7UL << ARM_V7M_CLIDR_CTYPE1_Pos)
/* CTYPE0 - Cache Type 0, bits[2:0] */
#define ARM_V7M_CLIDR_CTYPE0_Pos        0U
#define ARM_V7M_CLIDR_CTYPE0_Msk        (7UL << ARM_V7M_CLIDR_CTYPE0_Pos)

/* -----------------------------------------------------------------------------
 * 2.35 CTR 寄存器位域 (ARM_V7M_SCB_CTR)
 * 参考: B4.8.4 Cache Type Register, CTR on page B4-667
 * -----------------------------------------------------------------------------
 */
/* IMINLINE - Instruction cache minimum line size, bits[3:0] */
#define ARM_V7M_CTR_IMINLINE_Pos        0U
#define ARM_V7M_CTR_IMINLINE_Msk        (0xFUL << ARM_V7M_CTR_IMINLINE_Pos)
/* L1IP - Level 1 instruction cache policy, bits[15:14] */
#define ARM_V7M_CTR_L1IP_Pos            14U
#define ARM_V7M_CTR_L1IP_Msk            (3UL << ARM_V7M_CTR_L1IP_Pos)
/* DMINLINE - Data cache minimum line size, bits[19:16] */
#define ARM_V7M_CTR_DMINLINE_Pos        16U
#define ARM_V7M_CTR_DMINLINE_Msk        (0xFUL << ARM_V7M_CTR_DMINLINE_Pos)
/* ERG - Exclusive reservation grain, bits[23:20] */
#define ARM_V7M_CTR_ERG_Pos             20U
#define ARM_V7M_CTR_ERG_Msk             (0xFUL << ARM_V7M_CTR_ERG_Pos)
/* CWG - Cache write-back granule, bits[27:24] */
#define ARM_V7M_CTR_CWG_Pos             24U
#define ARM_V7M_CTR_CWG_Msk             (0xFUL << ARM_V7M_CTR_CWG_Pos)
/* FORMAT - Format field, bits[31:29] */
#define ARM_V7M_CTR_FORMAT_Pos          29U
#define ARM_V7M_CTR_FORMAT_Msk          (7UL << ARM_V7M_CTR_FORMAT_Pos)

/* -----------------------------------------------------------------------------
 * 2.36 CCSIDR 寄存器位域 (ARM_V7M_SCB_CCSIDR)
 * 参考: B4.8.2 Cache Size ID Registers, CCSIDR on page B4-666
 * -----------------------------------------------------------------------------
 */
/* WT - Write-through support, bit[31] */
#define ARM_V7M_CCSIDR_WT_Pos         31U
#define ARM_V7M_CCSIDR_WT_Msk         (1UL << ARM_V7M_CCSIDR_WT_Pos)
/* WB - Write-back support, bit[30] */
#define ARM_V7M_CCSIDR_WB_Pos         30U
#define ARM_V7M_CCSIDR_WB_Msk         (1UL << ARM_V7M_CCSIDR_WB_Pos)
/* RA - Read-allocation support, bit[29] */
#define ARM_V7M_CCSIDR_RA_Pos         29U
#define ARM_V7M_CCSIDR_RA_Msk         (1UL << ARM_V7M_CCSIDR_RA_Pos)
/* WA - Write-allocation support, bit[28] */
#define ARM_V7M_CCSIDR_WA_Pos         28U
#define ARM_V7M_CCSIDR_WA_Msk         (1UL << ARM_V7M_CCSIDR_WA_Pos)
/* NumSets - Number of sets, bits[27:13] */
#define ARM_V7M_CCSIDR_NumSets_Pos      13U
#define ARM_V7M_CCSIDR_NumSets_Msk      (0x7FFFUL << ARM_V7M_CCSIDR_NumSets_Pos)
/* Associativity - Associativity, bits[12:3] */
#define ARM_V7M_CCSIDR_Associativity_Pos 3U
#define ARM_V7M_CCSIDR_Associativity_Msk (0x3FFUL << ARM_V7M_CCSIDR_Associativity_Pos)
/* LineSize - Line size, bits[2:0] */
#define ARM_V7M_CCSIDR_LineSize_Pos     0U
#define ARM_V7M_CCSIDR_LineSize_Msk     (7UL << ARM_V7M_CCSIDR_LineSize_Pos)

/* -----------------------------------------------------------------------------
 * 2.37 CSSELR 寄存器位域 (ARM_V7M_SCB_CSSELR)
 * 参考: B4.8.3 Cache Size Selection Register, CSSELR on page B4-667
 * -----------------------------------------------------------------------------
 */
/* LEVEL - Cache level, bits[3:1] */
#define ARM_V7M_CSSELR_LEVEL_Pos        1U
#define ARM_V7M_CSSELR_LEVEL_Msk        (7UL << ARM_V7M_CSSELR_LEVEL_Pos)
/* InD - Instruction or Data cache, bit[0] */
#define ARM_V7M_CSSELR_InD_Pos          0U
#define ARM_V7M_CSSELR_InD_Msk          (1UL << ARM_V7M_CSSELR_InD_Pos)

/* -----------------------------------------------------------------------------
 * 2.38 PID 寄存器位域 (ARM_V7M_SCS_PID0-PID7, ARM_V7M_SCS_CID0-CID3)
 * 参考: B4.1 About the CPUID scheme on page B4-644
 * -----------------------------------------------------------------------------
 */
/* PID0 - PARTNUM - Part number, bits[7:0] */
#define ARM_V7M_PID0_PARTNUM_Pos        0U
#define ARM_V7M_PID0_PARTNUM_Msk        (0xFFUL << ARM_V7M_PID0_PARTNUM_Pos)

/* PID1 - PARTNUM - Part number, bits[3:0] */
#define ARM_V7M_PID1_PARTNUM_Pos        0U
#define ARM_V7M_PID1_PARTNUM_Msk        (0xFUL << ARM_V7M_PID1_PARTNUM_Pos)
/* PID1 - JEPID - JEP106 ID, bits[7:4] */
#define ARM_V7M_PID1_JEPID_Pos          4U
#define ARM_V7M_PID1_JEPID_Msk          (0xFUL << ARM_V7M_PID1_JEPID_Pos)

/* PID2 - JEPID - JEP106 ID, bits[2:0] */
#define ARM_V7M_PID2_JEPID_Pos          0U
#define ARM_V7M_PID2_JEPID_Msk          (7UL << ARM_V7M_PID2_JEPID_Pos)
/* PID2 - JEPIDCN - JEP106 ID continuation, bit[3] */
#define ARM_V7M_PID2_JEPIDCN_Pos        3U
#define ARM_V7M_PID2_JEPIDCN_Msk        (1UL << ARM_V7M_PID2_JEPIDCN_Pos)
/* PID2 - REVISION - Revision, bits[7:4] */
#define ARM_V7M_PID2_REVISION_Pos       4U
#define ARM_V7M_PID2_REVISION_Msk       (0xFUL << ARM_V7M_PID2_REVISION_Pos)

/* PID3 - CMOD - Component modification, bits[3:0] */
#define ARM_V7M_PID3_CMOD_Pos           0U
#define ARM_V7M_PID3_CMOD_Msk           (0xFUL << ARM_V7M_PID3_CMOD_Pos)
/* PID3 - REVAND - Revision and, bits[7:4] */
#define ARM_V7M_PID3_REVAND_Pos         4U
#define ARM_V7M_PID3_REVAND_Msk         (0xFUL << ARM_V7M_PID3_REVAND_Pos)

/* PID4 - JEP106C - JEP106 continuation code, bits[3:0] */
#define ARM_V7M_PID4_JEP106C_Pos        0U
#define ARM_V7M_PID4_JEP106C_Msk        (0xFUL << ARM_V7M_PID4_JEP106C_Pos)
/* PID4 - SIZE - Size, bits[7:4] */
#define ARM_V7M_PID4_SIZE_Pos           4U
#define ARM_V7M_PID4_SIZE_Msk           (0xFUL << ARM_V7M_PID4_SIZE_Pos)

/* PID5 - Reserved, reads as zero (RAZ) */
/* PID6 - Reserved, reads as zero (RAZ) */
/* PID7 - Reserved, reads as zero (RAZ) */

/* -----------------------------------------------------------------------------
 * 2.39 CID 寄存器位域 (ARM_V7M_SCS_CID0-CID3)
 * 参考: D1.1 CoreSight infrastructure IDs for an Armv7-M implementation on page D1-766
 * -----------------------------------------------------------------------------
 */
/* CID0 - PREAMBLE - Preamble, bits[7:0] (fixed value 0x0D) */
#define ARM_V7M_CID0_PREAMBLE_Pos       0U
#define ARM_V7M_CID0_PREAMBLE_Msk       (0xFFUL << ARM_V7M_CID0_PREAMBLE_Pos)

/* CID1 - PREAMBLE - Preamble, bits[3:0] (fixed value 0x00) */
#define ARM_V7M_CID1_PREAMBLE_Pos       0U
#define ARM_V7M_CID1_PREAMBLE_Msk       (0xFUL << ARM_V7M_CID1_PREAMBLE_Pos)
/* CID1 - CLASS - Component class, bits[7:4] (0x1=ARM component) */
#define ARM_V7M_CID1_CLASS_Pos          4U
#define ARM_V7M_CID1_CLASS_Msk          (0xFUL << ARM_V7M_CID1_CLASS_Pos)

/* CID2 - PREAMBLE - Preamble, bits[7:0] (fixed value 0x05) */
#define ARM_V7M_CID2_PREAMBLE_Pos       0U
#define ARM_V7M_CID2_PREAMBLE_Msk       (0xFFUL << ARM_V7M_CID2_PREAMBLE_Pos)

/* CID3 - PREAMBLE - Preamble, bits[7:0] (fixed value 0xB1) */
#define ARM_V7M_CID3_PREAMBLE_Pos       0U
#define ARM_V7M_CID3_PREAMBLE_Msk       (0xFFUL << ARM_V7M_CID3_PREAMBLE_Pos)

/* ==============================================================================
 * 三、SysTick 定时器位域 (SysTick Timer Bit-fields)
 * 参考: B3.3 The system timer, SysTick on page B3-620
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 3.1 SYST_CSR 寄存器位域 (ARM_V7M_SYST_CSR)
 * 参考: B3.3.3 SysTick Control and Status Register, SYST_CSR on page B3-621
 * -----------------------------------------------------------------------------
 */
/* COUNTFLAG - Returns 1 if timer counted to 0 since last time this was read, bit[16] */
#define ARM_V7M_SYST_CSR_COUNTFLAG_Pos   16U
#define ARM_V7M_SYST_CSR_COUNTFLAG_Msk   (1UL << ARM_V7M_SYST_CSR_COUNTFLAG_Pos)
/* CLKSOURCE - Clock source selection, bit[2] */
#define ARM_V7M_SYST_CSR_CLKSOURCE_Pos   2U
#define ARM_V7M_SYST_CSR_CLKSOURCE_Msk   (1UL << ARM_V7M_SYST_CSR_CLKSOURCE_Pos)
/* TICKINT - SysTick exception request enable, bit[1] */
#define ARM_V7M_SYST_CSR_TICKINT_Pos     1U
#define ARM_V7M_SYST_CSR_TICKINT_Msk     (1UL << ARM_V7M_SYST_CSR_TICKINT_Pos)
/* ENABLE - Enables the counter, bit[0] */
#define ARM_V7M_SYST_CSR_ENABLE_Pos      0U
#define ARM_V7M_SYST_CSR_ENABLE_Msk      (1UL << ARM_V7M_SYST_CSR_ENABLE_Pos)

/* -----------------------------------------------------------------------------
 * 3.2 SYST_RVR 寄存器位域 (ARM_V7M_SYST_RVR)
 * 参考: B3.3.4 SysTick Reload Value Register, SYST_RVR on page B3-622
 * -----------------------------------------------------------------------------
 */
/* RELOAD - Value to load into the SYST_CVR register when the counter reaches 0, bits[23:0] */
#define ARM_V7M_SYST_RVR_RELOAD_Pos      0U
#define ARM_V7M_SYST_RVR_RELOAD_Msk      (0xFFFFFFUL << ARM_V7M_SYST_RVR_RELOAD_Pos)

/* -----------------------------------------------------------------------------
 * 3.3 SYST_CVR 寄存器位域 (ARM_V7M_SYST_CVR)
 * 参考: B3.3.5 SysTick Current Value Register, SYST_CVR on page B3-622
 * -----------------------------------------------------------------------------
 */
/* CURRENT - Current counter value, bits[23:0] */
#define ARM_V7M_SYST_CVR_CURRENT_Pos     0U
#define ARM_V7M_SYST_CVR_CURRENT_Msk     (0xFFFFFFUL << ARM_V7M_SYST_CVR_CURRENT_Pos)

/* -----------------------------------------------------------------------------
 * 3.4 SYST_CALIB 寄存器位域 (ARM_V7M_SYST_CALIB)
 * 参考: B3.3.6 SysTick Calibration value Register, SYST_CALIB on page B3-623
 * -----------------------------------------------------------------------------
 */
/* NOREF - No reference clock, bit[31] */
#define ARM_V7M_SYST_CALIB_NOREF_Pos     31U
#define ARM_V7M_SYST_CALIB_NOREF_Msk     (1UL << ARM_V7M_SYST_CALIB_NOREF_Pos)
/* SKEW - Calibration value is not exactly 10ms, bit[30] */
#define ARM_V7M_SYST_CALIB_SKEW_Pos      30U
#define ARM_V7M_SYST_CALIB_SKEW_Msk      (1UL << ARM_V7M_SYST_CALIB_SKEW_Pos)
/* TENMS - Reload value for 10ms (100Hz) timing, bits[23:0] */
#define ARM_V7M_SYST_CALIB_TENMS_Pos     0U
#define ARM_V7M_SYST_CALIB_TENMS_Msk     (0xFFFFFFUL << ARM_V7M_SYST_CALIB_TENMS_Pos)

/* ==============================================================================
 * 四、NVIC 寄存器位域 (NVIC Registers Bit-fields)
 * 参考: B3.4 Nested Vectored Interrupt Controller, NVIC on page B3-624
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 4.1 NVIC 寄存器位域说明
 * 参考: B3.4 Nested Vectored Interrupt Controller, NVIC on page B3-624
 *
 * NVIC 寄存器使用索引访问模式，例如：
 *   ARM_V7M_NVIC_ISER(n)  - Interrupt Set-Enable Register n
 *   ARM_V7M_NVIC_ICER(n)  - Interrupt Clear-Enable Register n
 *   ARM_V7M_NVIC_ISPR(n)  - Interrupt Set-Pending Register n
 *   ARM_V7M_NVIC_ICPR(n)  - Interrupt Clear-Pending Register n
 *   ARM_V7M_NVIC_IABR(n)  - Interrupt Active Bit Register n
 *   ARM_V7M_NVIC_IPR(n)   - Interrupt Priority Register n
 *
 * 位域说明：
 *   对于 ISER, ICER, ISPR, ICPR, IABR: 每个位对应一个中断
 *   对于 IPR: 每个寄存器包含 4 个中断的优先级，每个 8 位
 * -----------------------------------------------------------------------------
 */

/* -----------------------------------------------------------------------------
 * 4.2 NVIC_IPR 寄存器位域 (ARM_V7M_NVIC_IPR)
 * 参考: B3.4.9 Interrupt Priority Registers, NVIC_IPR0-NVIC_IPR123 on page B3-630
 * -----------------------------------------------------------------------------
 */
/* PRI_N3 - Priority of interrupt 4n+3, bits[31:24] */
#define ARM_V7M_NVIC_IPR_PRI_N3_Pos      31U
#define ARM_V7M_NVIC_IPR_PRI_N3_Msk      (0xFFUL << ARM_V7M_NVIC_IPR_PRI_N3_Pos)
/* PRI_N2 - Priority of interrupt 4n+2, bits[23:16] */
#define ARM_V7M_NVIC_IPR_PRI_N2_Pos      23U
#define ARM_V7M_NVIC_IPR_PRI_N2_Msk      (0xFFUL << ARM_V7M_NVIC_IPR_PRI_N2_Pos)
/* PRI_N1 - Priority of interrupt 4n+1, bits[15:8] */
#define ARM_V7M_NVIC_IPR_PRI_N1_Pos      15U
#define ARM_V7M_NVIC_IPR_PRI_N1_Msk      (0xFFUL << ARM_V7M_NVIC_IPR_PRI_N1_Pos)
/* PRI_N0 - Priority of interrupt 4n, bits[7:0] */
#define ARM_V7M_NVIC_IPR_PRI_N0_Pos      7U
#define ARM_V7M_NVIC_IPR_PRI_N0_Msk      (0xFFUL << ARM_V7M_NVIC_IPR_PRI_N0_Pos)

/* ==============================================================================
 * 五、MPU 寄存器位域 (MPU Registers Bit-fields)
 * 参考: B3.5 Protected Memory System Architecture, PMSAv7 on page B3-632
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 5.1 MPU_TYPE 寄存器位域 (ARM_V7M_MPU_TYPE)
 * 参考: B3.5.5 MPU Type Register, MPU_TYPE on page B3-636
 * -----------------------------------------------------------------------------
 */
/* IREGION - Number of instruction regions (RAZ for ARMv7-M), bits[23:16] */
#define ARM_V7M_MPU_TYPE_IREGION_Pos    16U
#define ARM_V7M_MPU_TYPE_IREGION_Msk    (0xFFUL << ARM_V7M_MPU_TYPE_IREGION_Pos)
/* DREGION - Number of data regions, bits[15:8] */
#define ARM_V7M_MPU_TYPE_DREGION_Pos    8U
#define ARM_V7M_MPU_TYPE_DREGION_Msk    (0xFFUL << ARM_V7M_MPU_TYPE_DREGION_Pos)
/* SEPARATE - Separate or unified MPU (RAZ for ARMv7-M), bit[0] */
#define ARM_V7M_MPU_TYPE_SEPARATE_Pos   0U
#define ARM_V7M_MPU_TYPE_SEPARATE_Msk   (1UL << ARM_V7M_MPU_TYPE_SEPARATE_Pos)

/* -----------------------------------------------------------------------------
 * 5.2 MPU_CTRL 寄存器位域 (ARM_V7M_MPU_CTRL)
 * 参考: B3.5.6 MPU Control Register, MPU_CTRL on page B3-637
 * -----------------------------------------------------------------------------
 */
/* PRIVDEFENA - Enables the default memory map as a background region, bit[2] */
#define ARM_V7M_MPU_CTRL_PRIVDEFENA_Pos 2U
#define ARM_V7M_MPU_CTRL_PRIVDEFENA_Msk (1UL << ARM_V7M_MPU_CTRL_PRIVDEFENA_Pos)
/* HFNMIENA - Enables the MPU during HardFault and NMI handlers, bit[1] */
#define ARM_V7M_MPU_CTRL_HFNMIENA_Pos   1U
#define ARM_V7M_MPU_CTRL_HFNMIENA_Msk   (1UL << ARM_V7M_MPU_CTRL_HFNMIENA_Pos)
/* ENABLE - Enables the MPU, bit[0] */
#define ARM_V7M_MPU_CTRL_ENABLE_Pos     0U
#define ARM_V7M_MPU_CTRL_ENABLE_Msk     (1UL << ARM_V7M_MPU_CTRL_ENABLE_Pos)

/* -----------------------------------------------------------------------------
 * 5.3 MPU_RNR 寄存器位域 (ARM_V7M_MPU_RNR)
 * 参考: B3.5.7 MPU Region Number Register, MPU_RNR on page B3-638
 * -----------------------------------------------------------------------------
 */
/* REGION - Region number, bits[7:0] */
#define ARM_V7M_MPU_RNR_REGION_Pos      0U
#define ARM_V7M_MPU_RNR_REGION_Msk      (0xFFUL << ARM_V7M_MPU_RNR_REGION_Pos)

/* -----------------------------------------------------------------------------
 * 5.4 MPU_RBAR 寄存器位域 (ARM_V7M_MPU_RBAR)
 * 参考: B3.5.8 MPU Region Base Address Register, MPU_RBAR on page B3-639
 * -----------------------------------------------------------------------------
 */
/* ADDR - Region base address, bits[31:5] */
#define ARM_V7M_MPU_RBAR_ADDR_Pos       5U
#define ARM_V7M_MPU_RBAR_ADDR_Msk       (0x7FFFFFFUL << ARM_V7M_MPU_RBAR_ADDR_Pos)
/* VALID - MPU region number valid, bit[4] */
#define ARM_V7M_MPU_RBAR_VALID_Pos      4U
#define ARM_V7M_MPU_RBAR_VALID_Msk      (1UL << ARM_V7M_MPU_RBAR_VALID_Pos)
/* REGION - MPU region number (when VALID=1), bits[3:0] */
#define ARM_V7M_MPU_RBAR_REGION_Pos     0U
#define ARM_V7M_MPU_RBAR_REGION_Msk     (0xFUL << ARM_V7M_MPU_RBAR_REGION_Pos)

/* -----------------------------------------------------------------------------
 * 5.5 MPU_RASR 寄存器位域 (ARM_V7M_MPU_RASR)
 * 参考: B3.5.9 MPU Region Attribute and Size Register, MPU_RASR on page B3-640
 * -----------------------------------------------------------------------------
 */
/* ATTRS - Region attributes field, bits[31:16] */
/* XN - Execute Never, bit[28] */
#define ARM_V7M_MPU_RASR_XN_Pos         28U
#define ARM_V7M_MPU_RASR_XN_Msk         (1UL << ARM_V7M_MPU_RASR_XN_Pos)
/* AP - Access permissions, bits[26:24] */
#define ARM_V7M_MPU_RASR_AP_Pos         24U
#define ARM_V7M_MPU_RASR_AP_Msk         (7UL << ARM_V7M_MPU_RASR_AP_Pos)
/* TEX - Type Extension field, bits[21:19] */
#define ARM_V7M_MPU_RASR_TEX_Pos        19U
#define ARM_V7M_MPU_RASR_TEX_Msk        (7UL << ARM_V7M_MPU_RASR_TEX_Pos)
/* S - Shareable, bit[18] */
#define ARM_V7M_MPU_RASR_S_Pos          18U
#define ARM_V7M_MPU_RASR_S_Msk          (1UL << ARM_V7M_MPU_RASR_S_Pos)
/* C - Cacheable, bit[17] */
#define ARM_V7M_MPU_RASR_C_Pos          17U
#define ARM_V7M_MPU_RASR_C_Msk          (1UL << ARM_V7M_MPU_RASR_C_Pos)
/* B - Bufferable, bit[16] */
#define ARM_V7M_MPU_RASR_B_Pos          16U
#define ARM_V7M_MPU_RASR_B_Msk          (1UL << ARM_V7M_MPU_RASR_B_Pos)
/* SRD - Subregion disable, bits[15:8] */
#define ARM_V7M_MPU_RASR_SRD_Pos        8U
#define ARM_V7M_MPU_RASR_SRD_Msk        (0xFFUL << ARM_V7M_MPU_RASR_SRD_Pos)
/* SIZE - Size of the MPU region, bits[5:1]. Region size = 2^(SIZE+1) bytes */
#define ARM_V7M_MPU_RASR_SIZE_Pos       1U
#define ARM_V7M_MPU_RASR_SIZE_Msk       (0x1FUL << ARM_V7M_MPU_RASR_SIZE_Pos)
/* ENABLE - Region enable, bit[0] */
#define ARM_V7M_MPU_RASR_ENABLE_Pos     0U
#define ARM_V7M_MPU_RASR_ENABLE_Msk     (1UL << ARM_V7M_MPU_RASR_ENABLE_Pos)

/* ==============================================================================
 * 六、浮点扩展寄存器位域 (Floating-Point Extension Bit-fields)
 * 参考: B3.2.21 Floating Point Context Control Register, FPCCR on page B3-615
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 6.1 FPCCR 寄存器位域 (ARM_V7M_FPU_FPCCR)
 * 参考: B3.2.21 Floating Point Context Control Register, FPCCR on page B3-615
 * -----------------------------------------------------------------------------
 */
/* ASPEN - Automatic state preservation enable, bit[31] */
#define ARM_V7M_FPCCR_ASPEN_Pos         31U
#define ARM_V7M_FPCCR_ASPEN_Msk         (1UL << ARM_V7M_FPCCR_ASPEN_Pos)
/* LSPEN - Lazy state preservation enable, bit[30] */
#define ARM_V7M_FPCCR_LSPEN_Pos         30U
#define ARM_V7M_FPCCR_LSPEN_Msk         (1UL << ARM_V7M_FPCCR_LSPEN_Pos)
/* MONRDY - Debug monitor ready, bit[8] */
#define ARM_V7M_FPCCR_MONRDY_Pos        8U
#define ARM_V7M_FPCCR_MONRDY_Msk        (1UL << ARM_V7M_FPCCR_MONRDY_Pos)
/* BFRDY - BusFault ready, bit[6] */
#define ARM_V7M_FPCCR_BFRDY_Pos         6U
#define ARM_V7M_FPCCR_BFRDY_Msk         (1UL << ARM_V7M_FPCCR_BFRDY_Pos)
/* MMRDY - MemManage ready, bit[5] */
#define ARM_V7M_FPCCR_MMRDY_Pos         5U
#define ARM_V7M_FPCCR_MMRDY_Msk         (1UL << ARM_V7M_FPCCR_MMRDY_Pos)
/* HFRDY - HardFault ready, bit[4] */
#define ARM_V7M_FPCCR_HFRDY_Pos         4U
#define ARM_V7M_FPCCR_HFRDY_Msk         (1UL << ARM_V7M_FPCCR_HFRDY_Pos)
/* THREAD - Thread mode, bit[3] */
#define ARM_V7M_FPCCR_THREAD_Pos        3U
#define ARM_V7M_FPCCR_THREAD_Msk        (1UL << ARM_V7M_FPCCR_THREAD_Pos)
/* USER - User mode, bit[1] */
#define ARM_V7M_FPCCR_USER_Pos          1U
#define ARM_V7M_FPCCR_USER_Msk          (1UL << ARM_V7M_FPCCR_USER_Pos)
/* LSPACT - Lazy state preservation active, bit[0] */
#define ARM_V7M_FPCCR_LSPACT_Pos        0U
#define ARM_V7M_FPCCR_LSPACT_Msk        (1UL << ARM_V7M_FPCCR_LSPACT_Pos)

/* -----------------------------------------------------------------------------
 * 6.2 FPCAR 寄存器位域 (ARM_V7M_FPU_FPCAR)
 * 参考: B3.2.22 Floating Point Context Address Register, FPCAR on page B3-617
 * -----------------------------------------------------------------------------
 */
/* ADDRESS - Floating-point context address, bits[31:3] */
#define ARM_V7M_FPCAR_ADDRESS_Pos       3U
#define ARM_V7M_FPCAR_ADDRESS_Msk       (0x1FFFFFFFUL << ARM_V7M_FPCAR_ADDRESS_Pos)

/* -----------------------------------------------------------------------------
 * 6.3 FPDSCR 寄存器位域 (ARM_V7M_FPU_FPDSCR)
 * 参考: B3.2.23 Floating Point Default Status Control Register, FPDSCR on page B3-617
 * -----------------------------------------------------------------------------
 */
/* AHP - Alternative half-precision control bit, bit[26] */
#define ARM_V7M_FPDSCR_AHP_Pos          26U
#define ARM_V7M_FPDSCR_AHP_Msk          (1UL << ARM_V7M_FPDSCR_AHP_Pos)
/* DN - Default NaN mode control bit, bit[25] */
#define ARM_V7M_FPDSCR_DN_Pos           25U
#define ARM_V7M_FPDSCR_DN_Msk           (1UL << ARM_V7M_FPDSCR_DN_Pos)
/* FZ - Flush-to-zero mode control bit, bit[24] */
#define ARM_V7M_FPDSCR_FZ_Pos           24U
#define ARM_V7M_FPDSCR_FZ_Msk           (1UL << ARM_V7M_FPDSCR_FZ_Pos)
/* RMode - Rounding Mode control field, bits[23:22] */
#define ARM_V7M_FPDSCR_RMode_Pos        22U
#define ARM_V7M_FPDSCR_RMode_Msk        (3UL << ARM_V7M_FPDSCR_RMode_Pos)

/* -----------------------------------------------------------------------------
 * 6.4 MVFR0 寄存器位域 (ARM_V7M_FPU_MVFR0)
 * 参考: B4.7.1 Media and FP Feature Register 0, MVFR0 on page B4-662
 * -----------------------------------------------------------------------------
 */
/* FPROUND - Floating-point rounding modes, bits[31:28] */
#define ARM_V7M_MVFR0_FPROUND_Pos       28U
#define ARM_V7M_MVFR0_FPROUND_Msk       (0xFUL << ARM_V7M_MVFR0_FPROUND_Pos)
/* SHORTVEC - Short vectors, bits[27:24] */
#define ARM_V7M_MVFR0_SHORTVEC_Pos       24U
#define ARM_V7M_MVFR0_SHORTVEC_Msk       (0xFUL << ARM_V7M_MVFR0_SHORTVEC_Pos)
/* SQRT - Square root, bits[23:20] */
#define ARM_V7M_MVFR0_SQRT_Pos        20U
#define ARM_V7M_MVFR0_SQRT_Msk        (0xFUL << ARM_V7M_MVFR0_SQRT_Pos)
/* DIVIDE - Divide, bits[19:16] */
#define ARM_V7M_MVFR0_DIVIDE_Pos      16U
#define ARM_V7M_MVFR0_DIVIDE_Msk      (0xFUL << ARM_V7M_MVFR0_DIVIDE_Pos)
/* FPEXC_TRP - Floating-point exception trapping, bits[15:12] */
#define ARM_V7M_MVFR0_FPEXC_TRP_Pos      12U
#define ARM_V7M_MVFR0_FPEXC_TRP_Msk      (0xFUL << ARM_V7M_MVFR0_FPEXC_TRP_Pos)
/* DP - Double-precision, bits[11:8] */
#define ARM_V7M_MVFR0_DP_Pos          8U
#define ARM_V7M_MVFR0_DP_Msk          (0xFUL << ARM_V7M_MVFR0_DP_Pos)
/* SP - Single-precision, bits[7:4] */
#define ARM_V7M_MVFR0_SP_Pos          4U
#define ARM_V7M_MVFR0_SP_Msk          (0xFUL << ARM_V7M_MVFR0_SP_Pos)
/* SIMDREG - SIMD registers, bits[3:0] */
#define ARM_V7M_MVFR0_SIMDREG_Pos       0U
#define ARM_V7M_MVFR0_SIMDREG_Msk       (0xFUL << ARM_V7M_MVFR0_SIMDREG_Pos)

/* -----------------------------------------------------------------------------
 * 6.5 MVFR1 寄存器位域 (ARM_V7M_FPU_MVFR1)
 * 参考: B4.7.3 Media and FP Feature Register 1, MVFR1 on page B4-663
 * -----------------------------------------------------------------------------
 */
/* FMAC - Fused multiply accumulate, bits[31:28] */
#define ARM_V7M_MVFR1_FMAC_Pos          28U
#define ARM_V7M_MVFR1_FMAC_Msk          (0xFUL << ARM_V7M_MVFR1_FMAC_Pos)
/* HPFP - Half-precision floating-point, bits[27:24] */
#define ARM_V7M_MVFR1_HPFP_Pos          24U
#define ARM_V7M_MVFR1_HPFP_Msk          (0xFUL << ARM_V7M_MVFR1_HPFP_Pos)
/* DNAN - Double-precision NaN, bits[7:4] */
#define ARM_V7M_MVFR1_DNAN_Pos          4U
#define ARM_V7M_MVFR1_DNAN_Msk          (0xFUL << ARM_V7M_MVFR1_DNAN_Pos)
/* FTZ - Flush-to-zero, bits[3:0] */
#define ARM_V7M_MVFR1_FTZ_Pos            0U
#define ARM_V7M_MVFR1_FTZ_Msk            (0xFUL << ARM_V7M_MVFR1_FTZ_Pos)

/* -----------------------------------------------------------------------------
 * 6.6 MVFR2 寄存器位域 (ARM_V7M_FPU_MVFR2)
 * 参考: B4.7.4 Media and FP Feature Register 2, MVFR2 on page B4-664
 * -----------------------------------------------------------------------------
 */
/* VFP_MISC - Miscellaneous VFP features, bits[7:4] */
#define ARM_V7M_MVFR2_VFP_MISC_Pos        4U
#define ARM_V7M_MVFR2_VFP_MISC_Msk        (0xFUL << ARM_V7M_MVFR2_VFP_MISC_Pos)

/* ==============================================================================
 * 七、调试寄存器位域 (Debug Registers Bit-fields)
 * 参考: C1.6 Debug system registers on page C1-699
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 7.1 DHCSR 寄存器位域 (ARM_V7M_DBG_DHCSR)
 * 参考: C1.6.2 Debug Halting Control and Status Register, DHCSR on page C1-700
 * -----------------------------------------------------------------------------
 */
/* DBGKEY - Debug key (must write 0xA05F for write access), bits[31:16] */
#define ARM_V7M_DHCSR_DBGKEY_Pos        16U
#define ARM_V7M_DHCSR_DBGKEY_Msk        (0xFFFFUL << ARM_V7M_DHCSR_DBGKEY_Pos)
/* S_RESET_ST - Reset status sticky bit, bit[25] */
#define ARM_V7M_DHCSR_S_RESET_ST_Pos    25U
#define ARM_V7M_DHCSR_S_RESET_ST_Msk    (1UL << ARM_V7M_DHCSR_S_RESET_ST_Pos)
/* S_RETIRE_ST - Retire status sticky bit, bit[24] */
#define ARM_V7M_DHCSR_S_RETIRE_ST_Pos   24U
#define ARM_V7M_DHCSR_S_RETIRE_ST_Msk   (1UL << ARM_V7M_DHCSR_S_RETIRE_ST_Pos)
/* S_LOCKUP - Lockup status, bit[19] */
#define ARM_V7M_DHCSR_S_LOCKUP_Pos      19U
#define ARM_V7M_DHCSR_S_LOCKUP_Msk      (1UL << ARM_V7M_DHCSR_S_LOCKUP_Pos)
/* S_SLEEP - Sleep status, bit[18] */
#define ARM_V7M_DHCSR_S_SLEEP_Pos       18U
#define ARM_V7M_DHCSR_S_SLEEP_Msk       (1UL << ARM_V7M_DHCSR_S_SLEEP_Pos)
/* S_HALT - Halt status, bit[17] */
#define ARM_V7M_DHCSR_S_HALT_Pos        17U
#define ARM_V7M_DHCSR_S_HALT_Msk        (1UL << ARM_V7M_DHCSR_S_HALT_Pos)
/* S_REGRDY - Register ready, bit[16] */
#define ARM_V7M_DHCSR_S_REGRDY_Pos      16U
#define ARM_V7M_DHCSR_S_REGRDY_Msk      (1UL << ARM_V7M_DHCSR_S_REGRDY_Pos)
/* C_SNAPSTALL - Snap stall, bit[5] */
#define ARM_V7M_DHCSR_C_SNAPSTALL_Pos   5U
#define ARM_V7M_DHCSR_C_SNAPSTALL_Msk   (1UL << ARM_V7M_DHCSR_C_SNAPSTALL_Pos)
/* C_MASKINTS - Mask interrupts, bit[3] */
#define ARM_V7M_DHCSR_C_MASKINTS_Pos    3U
#define ARM_V7M_DHCSR_C_MASKINTS_Msk    (1UL << ARM_V7M_DHCSR_C_MASKINTS_Pos)
/* C_STEP - Step, bit[2] */
#define ARM_V7M_DHCSR_C_STEP_Pos        2U
#define ARM_V7M_DHCSR_C_STEP_Msk        (1UL << ARM_V7M_DHCSR_C_STEP_Pos)
/* C_HALT - Halt, bit[1] */
#define ARM_V7M_DHCSR_C_HALT_Pos        1U
#define ARM_V7M_DHCSR_C_HALT_Msk        (1UL << ARM_V7M_DHCSR_C_HALT_Pos)
/* C_DEBUGEN - Debug enable, bit[0] */
#define ARM_V7M_DHCSR_C_DEBUGEN_Pos     0U
#define ARM_V7M_DHCSR_C_DEBUGEN_Msk     (1UL << ARM_V7M_DHCSR_C_DEBUGEN_Pos)

/* ==============================================================================
 * 7.1.1 DHCSR 值定义宏 (DHCSR Value Definition Macros)
 * 非寄存器位域宏，用于定义 DHCSR 寄存器的具体值
 * ==============================================================================
 */
/* DBGKEY_VALUE - Debug key value (0xA05F) */
#define ARM_V7M_DHCSR_DBGKEY_VALUE      (0xA05FUL << ARM_V7M_DHCSR_DBGKEY_Pos)

/* -----------------------------------------------------------------------------
 * 7.2 DCRSR 寄存器位域 (ARM_V7M_DBG_DCRSR)
 * 参考: C1.6.3 Debug Core Register Selector Register, DCRSR on page C1-703
 * -----------------------------------------------------------------------------
 */
/* REGWnR - Register write not read, bit[16] */
#define ARM_V7M_DCRSR_REGWnR_Pos        16U
#define ARM_V7M_DCRSR_REGWnR_Msk        (1UL << ARM_V7M_DCRSR_REGWnR_Pos)
/* REGSEL - Register select, bits[6:0] */
#define ARM_V7M_DCRSR_REGSEL_Pos        0U
#define ARM_V7M_DCRSR_REGSEL_Msk        (0x7FUL << ARM_V7M_DCRSR_REGSEL_Pos)

/* -----------------------------------------------------------------------------
 * 7.3 DCRDR 寄存器位域 (ARM_V7M_DBG_DCRDR)
 * 参考: C1.6.4 Debug Core Register Data Register, DCRDR on page C1-704
 * -----------------------------------------------------------------------------
 */
/* DBGTMP - Debug temporary data, bits[31:0] */
#define ARM_V7M_DCRDR_DBGTMP_Pos        0U
#define ARM_V7M_DCRDR_DBGTMP_Msk        (0xFFFFFFFFUL << ARM_V7M_DCRDR_DBGTMP_Pos)

/* -----------------------------------------------------------------------------
 * 7.4 DEMCR 寄存器位域 (ARM_V7M_DBG_DEMCR)
 * 参考: C1.6.5 Debug Exception and Monitor Control Register, DEMCR on page C1-706
 * -----------------------------------------------------------------------------
 */
/* TRCENA - Global trace enable, bit[24] */
#define ARM_V7M_DEMCR_TRCENA_Pos        24U
#define ARM_V7M_DEMCR_TRCENA_Msk        (1UL << ARM_V7M_DEMCR_TRCENA_Pos)
/* MON_REQ - Monitor request, bit[19] */
#define ARM_V7M_DEMCR_MON_REQ_Pos       19U
#define ARM_V7M_DEMCR_MON_REQ_Msk       (1UL << ARM_V7M_DEMCR_MON_REQ_Pos)
/* MON_STEP - Monitor step, bit[18] */
#define ARM_V7M_DEMCR_MON_STEP_Pos      18U
#define ARM_V7M_DEMCR_MON_STEP_Msk      (1UL << ARM_V7M_DEMCR_MON_STEP_Pos)
/* MON_PEND - Monitor pending, bit[17] */
#define ARM_V7M_DEMCR_MON_PEND_Pos      17U
#define ARM_V7M_DEMCR_MON_PEND_Msk      (1UL << ARM_V7M_DEMCR_MON_PEND_Pos)
/* MON_EN - Monitor enable, bit[16] */
#define ARM_V7M_DEMCR_MON_EN_Pos        16U
#define ARM_V7M_DEMCR_MON_EN_Msk        (1UL << ARM_V7M_DEMCR_MON_EN_Pos)
/* VC_HARDERR - Vector catch HardFault, bit[10] */
#define ARM_V7M_DEMCR_VC_HARDERR_Pos    10U
#define ARM_V7M_DEMCR_VC_HARDERR_Msk    (1UL << ARM_V7M_DEMCR_VC_HARDERR_Pos)
/* VC_INTERR - Vector catch interrupt, bit[9] */
#define ARM_V7M_DEMCR_VC_INTERR_Pos     9U
#define ARM_V7M_DEMCR_VC_INTERR_Msk     (1UL << ARM_V7M_DEMCR_VC_INTERR_Pos)
/* VC_BUSERR - Vector catch BusFault, bit[8] */
#define ARM_V7M_DEMCR_VC_BUSERR_Pos     8U
#define ARM_V7M_DEMCR_VC_BUSERR_Msk     (1UL << ARM_V7M_DEMCR_VC_BUSERR_Pos)
/* VC_STATERR - Vector catch state error, bit[7] */
#define ARM_V7M_DEMCR_VC_STATERR_Pos    7U
#define ARM_V7M_DEMCR_VC_STATERR_Msk    (1UL << ARM_V7M_DEMCR_VC_STATERR_Pos)
/* VC_CHKERR - Vector catch check error, bit[6] */
#define ARM_V7M_DEMCR_VC_CHKERR_Pos     6U
#define ARM_V7M_DEMCR_VC_CHKERR_Msk     (1UL << ARM_V7M_DEMCR_VC_CHKERR_Pos)
/* VC_NOCPERR - Vector catch No Coprocessor error, bit[5] */
#define ARM_V7M_DEMCR_VC_NOCPERR_Pos    5U
#define ARM_V7M_DEMCR_VC_NOCPERR_Msk    (1UL << ARM_V7M_DEMCR_VC_NOCPERR_Pos)
/* VC_MMERR - Vector catch MemManage error, bit[4] */
#define ARM_V7M_DEMCR_VC_MMERR_Pos      4U
#define ARM_V7M_DEMCR_VC_MMERR_Msk      (1UL << ARM_V7M_DEMCR_VC_MMERR_Pos)
/* VC_CORERESET - Vector catch core reset, bit[0] */
#define ARM_V7M_DEMCR_VC_CORERESET_Pos  0U
#define ARM_V7M_DEMCR_VC_CORERESET_Msk  (1UL << ARM_V7M_DEMCR_VC_CORERESET_Pos)

/* ==============================================================================
 * 八、ITM 寄存器位域 (Instrumentation Trace Macrocell Bit-fields)
 * 参考: C1.7 The Instrumentation Trace Macrocell on page C1-709
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 8.1 ITM_STIM 寄存器位域 (ARM_V7M_ITM_STIM)
 * 参考: C1.7.3 Stimulus Port registers, ITM_STIM0-ITM_STIM255 on page C1-714
 * -----------------------------------------------------------------------------
 */
/* FIFOREADY - FIFO ready, bit[0] */
#define ARM_V7M_ITM_STIM_FIFOREADY_Pos  0U
#define ARM_V7M_ITM_STIM_FIFOREADY_Msk  (1UL << ARM_V7M_ITM_STIM_FIFOREADY_Pos)
/* STIMULUS - Stimulus port data, bits[31:1] */
#define ARM_V7M_ITM_STIM_STIMULUS_Pos   1U
#define ARM_V7M_ITM_STIM_STIMULUS_Msk   (0x7FFFFFFFUL << ARM_V7M_ITM_STIM_STIMULUS_Pos)

/* -----------------------------------------------------------------------------
 * 8.2 ITM_TPR 寄存器位域 (ARM_V7M_ITM_TPR)
 * 参考: C1.7.5 Trace Privilege Register, ITM_TPR on page C1-715
 * -----------------------------------------------------------------------------
 */
/* PRIVMASK - Privilege mask, bits[3:0] */
#define ARM_V7M_ITM_TPR_PRIVMASK_Pos    0U
#define ARM_V7M_ITM_TPR_PRIVMASK_Msk    (0xFUL << ARM_V7M_ITM_TPR_PRIVMASK_Pos)

/* -----------------------------------------------------------------------------
 * 8.3 ITM_TCR 寄存器位域 (ARM_V7M_ITM_TCR)
 * 参考: C1.7.6 Trace Control Register, ITM_TCR on page C1-716
 * -----------------------------------------------------------------------------
 */
/* BUSY - Busy flag, bit[23] */
#define ARM_V7M_ITM_TCR_BUSY_Pos        23U
#define ARM_V7M_ITM_TCR_BUSY_Msk        (1UL << ARM_V7M_ITM_TCR_BUSY_Pos)
/* TRACE_BUS_ID - Trace bus ID, bits[22:16] */
#define ARM_V7M_ITM_TCR_TRACE_BUS_ID_Pos 16U
#define ARM_V7M_ITM_TCR_TRACE_BUS_ID_Msk (0x7FUL << ARM_V7M_ITM_TCR_TRACE_BUS_ID_Pos)
/* GTSFREQ - Global timestamp frequency, bits[11:10] */
#define ARM_V7M_ITM_TCR_GTSFREQ_Pos     10U
#define ARM_V7M_ITM_TCR_GTSFREQ_Msk     (3UL << ARM_V7M_ITM_TCR_GTSFREQ_Pos)
/* TSPRESCALE - Timestamp prescaler, bits[9:8] */
#define ARM_V7M_ITM_TCR_TSPRESCALE_Pos  8U
#define ARM_V7M_ITM_TCR_TSPRESCALE_Msk  (3UL << ARM_V7M_ITM_TCR_TSPRESCALE_Pos)
/* SWOENA - Single wire output enable, bit[4] */
#define ARM_V7M_ITM_TCR_SWOENA_Pos      4U
#define ARM_V7M_ITM_TCR_SWOENA_Msk      (1UL << ARM_V7M_ITM_TCR_SWOENA_Pos)
/* TXENA - Transmit enable, bit[3] */
#define ARM_V7M_ITM_TCR_TXENA_Pos       3U
#define ARM_V7M_ITM_TCR_TXENA_Msk       (1UL << ARM_V7M_ITM_TCR_TXENA_Pos)
/* SYNCENA - Synchronization packet enable, bit[2] */
#define ARM_V7M_ITM_TCR_SYNCENA_Pos     2U
#define ARM_V7M_ITM_TCR_SYNCENA_Msk     (1UL << ARM_V7M_ITM_TCR_SYNCENA_Pos)
/* TSENA - Local timestamp enable, bit[1] */
#define ARM_V7M_ITM_TCR_TSENA_Pos       1U
#define ARM_V7M_ITM_TCR_TSENA_Msk       (1UL << ARM_V7M_ITM_TCR_TSENA_Pos)
/* ITMENA - ITM enable, bit[0] */
#define ARM_V7M_ITM_TCR_ITMENA_Pos      0U
#define ARM_V7M_ITM_TCR_ITMENA_Msk      (1UL << ARM_V7M_ITM_TCR_ITMENA_Pos)

/* ==============================================================================
 * 九、DWT 寄存器位域 (Data Watchpoint and Trace Bit-fields)
 * 参考: C1.8 The Data Watchpoint and Trace unit on page C1-719
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 9.1 DWT_CTRL 寄存器位域 (ARM_V7M_DWT_CTRL)
 * 参考: C1.8.4 Control register, DWT_CTRL on page C1-737
 * -----------------------------------------------------------------------------
 */
/* NUMCOMP - Number of comparators, bits[31:28] */
#define ARM_V7M_DWT_CTRL_NUMCOMP_Pos    28U
#define ARM_V7M_DWT_CTRL_NUMCOMP_Msk    (0xFUL << ARM_V7M_DWT_CTRL_NUMCOMP_Pos)
/* NOTRCPKT - No trace packets, bit[27] */
#define ARM_V7M_DWT_CTRL_NOTRCPKT_Pos   27U
#define ARM_V7M_DWT_CTRL_NOTRCPKT_Msk   (1UL << ARM_V7M_DWT_CTRL_NOTRCPKT_Pos)
/* NOEXTTRIG - No external trigger, bit[26] */
#define ARM_V7M_DWT_CTRL_NOEXTTRIG_Pos  26U
#define ARM_V7M_DWT_CTRL_NOEXTTRIG_Msk  (1UL << ARM_V7M_DWT_CTRL_NOEXTTRIG_Pos)
/* NOCYCCNT - No cycle counter, bit[25] */
#define ARM_V7M_DWT_CTRL_NOCYCCNT_Pos   25U
#define ARM_V7M_DWT_CTRL_NOCYCCNT_Msk   (1UL << ARM_V7M_DWT_CTRL_NOCYCCNT_Pos)
/* NOPRFCNT - No profiling counters, bit[24] */
#define ARM_V7M_DWT_CTRL_NOPRFCNT_Pos   24U
#define ARM_V7M_DWT_CTRL_NOPRFCNT_Msk   (1UL << ARM_V7M_DWT_CTRL_NOPRFCNT_Pos)
/* CYCEVTENA - Cycle counter event enable, bit[22] */
#define ARM_V7M_DWT_CTRL_CYCEVTENA_Pos  22U
#define ARM_V7M_DWT_CTRL_CYCEVTENA_Msk  (1UL << ARM_V7M_DWT_CTRL_CYCEVTENA_Pos)
/* FOLDEVTENA - Folded instruction event enable, bit[21] */
#define ARM_V7M_DWT_CTRL_FOLDEVTENA_Pos 21U
#define ARM_V7M_DWT_CTRL_FOLDEVTENA_Msk (1UL << ARM_V7M_DWT_CTRL_FOLDEVTENA_Pos)
/* LSUEVTENA - Load/store event enable, bit[20] */
#define ARM_V7M_DWT_CTRL_LSUEVTENA_Pos  20U
#define ARM_V7M_DWT_CTRL_LSUEVTENA_Msk  (1UL << ARM_V7M_DWT_CTRL_LSUEVTENA_Pos)
/* SLEEPEVTENA - Sleep event enable, bit[19] */
#define ARM_V7M_DWT_CTRL_SLEEPEVTENA_Pos 19U
#define ARM_V7M_DWT_CTRL_SLEEPEVTENA_Msk (1UL << ARM_V7M_DWT_CTRL_SLEEPEVTENA_Pos)
/* EXCEVTENA - Exception overhead event enable, bit[18] */
#define ARM_V7M_DWT_CTRL_EXCEVTENA_Pos  18U
#define ARM_V7M_DWT_CTRL_EXCEVTENA_Msk  (1UL << ARM_V7M_DWT_CTRL_EXCEVTENA_Pos)
/* CPIEVTENA - CPI counter overflow event enable, bit[17] */
#define ARM_V7M_DWT_CTRL_CPIEVTENA_Pos  17U
#define ARM_V7M_DWT_CTRL_CPIEVTENA_Msk  (1UL << ARM_V7M_DWT_CTRL_CPIEVTENA_Pos)
/* EXCTRCENA - Exception trace enable, bit[16] */
#define ARM_V7M_DWT_CTRL_EXCTRCENA_Pos  16U
#define ARM_V7M_DWT_CTRL_EXCTRCENA_Msk  (1UL << ARM_V7M_DWT_CTRL_EXCTRCENA_Pos)
/* PCSAMPLENA - PC sample event enable, bit[12] */
#define ARM_V7M_DWT_CTRL_PCSAMPLENA_Pos 12U
#define ARM_V7M_DWT_CTRL_PCSAMPLENA_Msk (1UL << ARM_V7M_DWT_CTRL_PCSAMPLENA_Pos)
/* SYNCTAP - Synchronization tap, bits[11:10] */
#define ARM_V7M_DWT_CTRL_SYNCTAP_Pos     10U
#define ARM_V7M_DWT_CTRL_SYNCTAP_Msk     (3UL << ARM_V7M_DWT_CTRL_SYNCTAP_Pos)
/* CYCTAP - Cycle counter tap, bit[9] */
#define ARM_V7M_DWT_CTRL_CYCTAP_Pos      9U
#define ARM_V7M_DWT_CTRL_CYCTAP_Msk      (1UL << ARM_V7M_DWT_CTRL_CYCTAP_Pos)
/* POSTINIT - Post counter initialization, bits[8:5] */
#define ARM_V7M_DWT_CTRL_POSTINIT_Pos    5U
#define ARM_V7M_DWT_CTRL_POSTINIT_Msk    (0xFUL << ARM_V7M_DWT_CTRL_POSTINIT_Pos)
/* POSTPRESET - Post counter preset, bits[4:1] */
#define ARM_V7M_DWT_CTRL_POSTPRESET_Pos  1U
#define ARM_V7M_DWT_CTRL_POSTPRESET_Msk  (0xFUL << ARM_V7M_DWT_CTRL_POSTPRESET_Pos)
/* CYCCNTENA - Cycle counter enable, bit[0] */
#define ARM_V7M_DWT_CTRL_CYCCNTENA_Pos   0U
#define ARM_V7M_DWT_CTRL_CYCCNTENA_Msk   (1UL << ARM_V7M_DWT_CTRL_CYCCNTENA_Pos)

/* -----------------------------------------------------------------------------
 * 9.2 DWT_MASK 寄存器位域 (ARM_V7M_DWT_MASK)
 * 参考: C1.8.16 Comparator Mask registers, DWT_MASKn on page C1-745
 * -----------------------------------------------------------------------------
 */
/* MASK - Comparator mask, bits[4:0] */
#define ARM_V7M_DWT_MASK_MASK_Pos       0U
#define ARM_V7M_DWT_MASK_MASK_Msk       (0x1FUL << ARM_V7M_DWT_MASK_MASK_Pos)

/* -----------------------------------------------------------------------------
 * 9.3 DWT_FUNCTION 寄存器位域 (ARM_V7M_DWT_FUNCTION)
 * 参考: C1.8.17 Comparator Function registers, DWT_FUNCTIONn on page C1-746
 * -----------------------------------------------------------------------------
 */
/* MATCHED - Comparator matched, bit[24] */
#define ARM_V7M_DWT_FUNCTION_MATCHED_Pos 24U
#define ARM_V7M_DWT_FUNCTION_MATCHED_Msk (1UL << ARM_V7M_DWT_FUNCTION_MATCHED_Pos)
/* DATAVADDR1 - Data value address 1, bits[19:16] */
#define ARM_V7M_DWT_FUNCTION_DATAVADDR1_Pos 16U
#define ARM_V7M_DWT_FUNCTION_DATAVADDR1_Msk (0xFUL << ARM_V7M_DWT_FUNCTION_DATAVADDR1_Pos)
/* DATAVADDR0 - Data value address 0, bits[15:12] */
#define ARM_V7M_DWT_FUNCTION_DATAVADDR0_Pos 12U
#define ARM_V7M_DWT_FUNCTION_DATAVADDR0_Msk (0xFUL << ARM_V7M_DWT_FUNCTION_DATAVADDR0_Pos)
/* DATAVSIZE - Data value size, bits[11:10] */
#define ARM_V7M_DWT_FUNCTION_DATAVSIZE_Pos 10U
#define ARM_V7M_DWT_FUNCTION_DATAVSIZE_Msk (3UL << ARM_V7M_DWT_FUNCTION_DATAVSIZE_Pos)
/* LNK1ENA - Link 1 enable, bit[9] */
#define ARM_V7M_DWT_FUNCTION_LNK1ENA_Pos 9U
#define ARM_V7M_DWT_FUNCTION_LNK1ENA_Msk (1UL << ARM_V7M_DWT_FUNCTION_LNK1ENA_Pos)
/* DATAVMATCH - Data value match, bit[8] */
#define ARM_V7M_DWT_FUNCTION_DATAVMATCH_Pos 8U
#define ARM_V7M_DWT_FUNCTION_DATAVMATCH_Msk (1UL << ARM_V7M_DWT_FUNCTION_DATAVMATCH_Pos)
/* CYCMATCH - Cycle count match, bit[7] */
#define ARM_V7M_DWT_FUNCTION_CYCMATCH_Pos 7U
#define ARM_V7M_DWT_FUNCTION_CYCMATCH_Msk (1UL << ARM_V7M_DWT_FUNCTION_CYCMATCH_Pos)
/* EMITRANGE - Emit range information, bit[5] */
#define ARM_V7M_DWT_FUNCTION_EMITRANGE_Pos 5U
#define ARM_V7M_DWT_FUNCTION_EMITRANGE_Msk (1UL << ARM_V7M_DWT_FUNCTION_EMITRANGE_Pos)
/* FUNCTION - Function, bits[3:0] */
#define ARM_V7M_DWT_FUNCTION_FUNCTION_Pos 0U
#define ARM_V7M_DWT_FUNCTION_FUNCTION_Msk (0xFUL << ARM_V7M_DWT_FUNCTION_FUNCTION_Pos)

/* ==============================================================================
 * 十、FPB 寄存器位域 (Flash Patch and Breakpoint Bit-fields)
 * 参考: C1.11 Flash Patch and Breakpoint unit on page C1-755
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 10.1 FP_CTRL 寄存器位域 (ARM_V7M_FPB_CTRL)
 * 参考: C1.11.3 Flash Patch Control Register, FP_CTRL on page C1-756
 * -----------------------------------------------------------------------------
 */
/* REV - Revision, bits[31:28] */
#define ARM_V7M_FPB_CTRL_REV_Pos            28U
#define ARM_V7M_FPB_CTRL_REV_Msk            (0xFUL << ARM_V7M_FPB_CTRL_REV_Pos)
/* NUM_CODE_H - Number of code comparators (high), bits[14:12] */
#define ARM_V7M_FPB_CTRL_NUM_CODE_H_Pos     12U
#define ARM_V7M_FPB_CTRL_NUM_CODE_H_Msk     (7UL << ARM_V7M_FPB_CTRL_NUM_CODE_H_Pos)
/* NUM_LIT - Number of literal comparators, bits[11:8] */
#define ARM_V7M_FPB_CTRL_NUM_LIT_Pos        8U
#define ARM_V7M_FPB_CTRL_NUM_LIT_Msk        (0xFUL << ARM_V7M_FPB_CTRL_NUM_LIT_Pos)
/* NUM_CODE_L - Number of code comparators (low), bits[7:4] */
#define ARM_V7M_FPB_CTRL_NUM_CODE_L_Pos     4U
#define ARM_V7M_FPB_CTRL_NUM_CODE_L_Msk     (0xFUL << ARM_V7M_FPB_CTRL_NUM_CODE_L_Pos)
/* KEY - Key, bit[1] */
#define ARM_V7M_FPB_CTRL_KEY_Pos            1U
#define ARM_V7M_FPB_CTRL_KEY_Msk            (1UL << ARM_V7M_FPB_CTRL_KEY_Pos)
/* ENABLE - Enable, bit[0] */
#define ARM_V7M_FPB_CTRL_ENABLE_Pos         0U
#define ARM_V7M_FPB_CTRL_ENABLE_Msk         (1UL << ARM_V7M_FPB_CTRL_ENABLE_Pos)

/* -----------------------------------------------------------------------------
 * 10.2 FP_REMAP 寄存器位域 (ARM_V7M_FPB_REMAP)
 * 参考: C1.11.4 Flash Patch Remap register, FP_REMAP on page C1-758
 * -----------------------------------------------------------------------------
 */
/* RMPSPT - Remap supported, bit[29] */
#define ARM_V7M_FPB_REMAP_RMPSPT_Pos        29U
#define ARM_V7M_FPB_REMAP_RMPSPT_Msk        (1UL << ARM_V7M_FPB_REMAP_RMPSPT_Pos)
/* REMAP - Remap, bits[28:5] */
#define ARM_V7M_FPB_REMAP_REMAP_Pos         5U
#define ARM_V7M_FPB_REMAP_REMAP_Msk         (0x00FFFFFFUL << ARM_V7M_FPB_REMAP_REMAP_Pos)

/* -----------------------------------------------------------------------------
 * 10.3 FP_COMP 寄存器位域 (ARM_V7M_FPB_COMP)
 * 参考: C1.11.5 Flash Patch Comparator register, FP_COMPn on page C1-758
 *
 * 注意: FP_COMP 寄存器有两种版本：
 * - FPB Version 1: REPLACE bits[31:30], COMP bits[28:2], ENABLE bit[0]
 * - FPB Version 2: BPADDR bits[31:1] (breakpoint address), BE bit[0] (breakpoint enable)
 * -----------------------------------------------------------------------------
 */
/* FPB Version 1 位域定义 */
/* REPLACE - Replace, bits[31:30] */
#define ARM_V7M_FPB_COMP_REPLACE_Pos        30U
#define ARM_V7M_FPB_COMP_REPLACE_Msk        (3UL << ARM_V7M_FPB_COMP_REPLACE_Pos)
/* COMP - Comparator address, bits[28:2] */
#define ARM_V7M_FPB_COMP_COMP_Pos           2U
#define ARM_V7M_FPB_COMP_COMP_Msk           (0x07FFFFFFUL << ARM_V7M_FPB_COMP_COMP_Pos)

/* FPB Version 2 位域定义 */
/* BPADDR - Breakpoint address, bits[31:1] */
#define ARM_V7M_FPB_COMP_BPADDR_Pos         1U
#define ARM_V7M_FPB_COMP_BPADDR_Msk         (0x7FFFFFFFUL << ARM_V7M_FPB_COMP_BPADDR_Pos)
/* FPADDR - Flash Patch address, bits[28:2] (when BE=0) */
#define ARM_V7M_FPB_COMP_FPADDR_Pos         2U
#define ARM_V7M_FPB_COMP_FPADDR_Msk         (0x07FFFFFFUL << ARM_V7M_FPB_COMP_FPADDR_Pos)
/* FE - Flash Patch enable, bit[1] (when BE=0) */
#define ARM_V7M_FPB_COMP_FE_Pos             1U
#define ARM_V7M_FPB_COMP_FE_Msk             (1UL << ARM_V7M_FPB_COMP_FE_Pos)

/* 通用位域定义 (适用于所有版本) */
/* ENABLE/BE - Enable/Breakpoint enable, bit[0] */
#define ARM_V7M_FPB_COMP_ENABLE_Pos         0U
#define ARM_V7M_FPB_COMP_ENABLE_Msk         (1UL << ARM_V7M_FPB_COMP_ENABLE_Pos)
#define ARM_V7M_FPB_COMP_BE_Pos             0U
#define ARM_V7M_FPB_COMP_BE_Msk             (1UL << ARM_V7M_FPB_COMP_BE_Pos)

/* ==============================================================================
 * 十一、TPIU 寄存器位域 (Trace Port Interface Unit Bit-fields)
 * 参考: C1.10 Trace Port Interface Unit on page C1-750
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 11.1 TPIU_SSPSR 寄存器位域 (ARM_V7M_TPIU_SSPSR)
 * 参考: C1.10.2 Supported Parallel Port Sizes Register, TPIU_SSPSR on page C1-751
 * -----------------------------------------------------------------------------
 */
/* SWIDTH - Supported width, bits[31:0] */
#define ARM_V7M_TPIU_SSPSR_SWIDTH_Pos   0U
#define ARM_V7M_TPIU_SSPSR_SWIDTH_Msk   (0xFFFFFFFFUL << ARM_V7M_TPIU_SSPSR_SWIDTH_Pos)

/* -----------------------------------------------------------------------------
 * 11.2 TPIU_CSPSR 寄存器位域 (ARM_V7M_TPIU_CSPSR)
 * 参考: C1.10.3 Current Parallel Port Size Register, TPIU_CSPSR on page C1-751
 * -----------------------------------------------------------------------------
 */
/* CWIDTH - Current width, bits[31:0] */
#define ARM_V7M_TPIU_CSPSR_CWIDTH_Pos   0U
#define ARM_V7M_TPIU_CSPSR_CWIDTH_Msk   (0xFFFFFFFFUL << ARM_V7M_TPIU_CSPSR_CWIDTH_Pos)

/* -----------------------------------------------------------------------------
 * 11.3 TPIU_ACPR 寄存器位域 (ARM_V7M_TPIU_ACPR)
 * 参考: C1.10.4 Asynchronous Clock Prescaler Register, TPIU_ACPR on page C1-752
 * -----------------------------------------------------------------------------
 */
/* SWOSCALER - Serial wire output prescaler, bits[15:0] */
#define ARM_V7M_TPIU_ACPR_SWOSCALER_Pos  0U
#define ARM_V7M_TPIU_ACPR_SWOSCALER_Msk  (0xFFFFUL << ARM_V7M_TPIU_ACPR_SWOSCALER_Pos)

/* -----------------------------------------------------------------------------
 * 11.4 TPIU_SPPR 寄存器位域 (ARM_V7M_TPIU_SPPR)
 * 参考: C1.10.5 Selected Pin Protocol Register, TPIU_SPPR on page C1-752
 * -----------------------------------------------------------------------------
 */
/* TXMODE - Trace output mode, bits[1:0] */
#define ARM_V7M_TPIU_SPPR_TXMODE_Pos    0U
#define ARM_V7M_TPIU_SPPR_TXMODE_Msk    (3UL << ARM_V7M_TPIU_SPPR_TXMODE_Pos)

/* -----------------------------------------------------------------------------
 * 11.5 TPIU_TYPE 寄存器位域 (ARM_V7M_TPIU_TYPE)
 * 参考: C1.10.6 TPIU Type register, TPIU_TYPE on page C1-753
 * -----------------------------------------------------------------------------
 */
/* FIFOSZ - FIFO size, bits[8:6] */
#define ARM_V7M_TPIU_TYPE_FIFOSZ_Pos        6U
#define ARM_V7M_TPIU_TYPE_FIFOSZ_Msk        (7UL << ARM_V7M_TPIU_TYPE_FIFOSZ_Pos)
/* PTINVALID - Parallel trace invalid, bit[9] */
#define ARM_V7M_TPIU_TYPE_PTINVALID_Pos     9U
#define ARM_V7M_TPIU_TYPE_PTINVALID_Msk     (1UL << ARM_V7M_TPIU_TYPE_PTINVALID_Pos)
/* MANCVALID - Manchester valid, bit[10] */
#define ARM_V7M_TPIU_TYPE_MANCVALID_Pos     10U
#define ARM_V7M_TPIU_TYPE_MANCVALID_Msk     (1UL << ARM_V7M_TPIU_TYPE_MANCVALID_Pos)
/* NRZVALID - NRZ valid, bit[11] */
#define ARM_V7M_TPIU_TYPE_NRZVALID_Pos      11U
#define ARM_V7M_TPIU_TYPE_NRZVALID_Msk      (1UL << ARM_V7M_TPIU_TYPE_NRZVALID_Pos)

/* ==============================================================================
 * 十二、DWT 性能计数器位域 (DWT Performance Counter Bit-fields)
 * 参考：C1.8 The Data Watchpoint and Trace unit on page C1-719
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 12.1 DWT_CYCCNT 寄存器位域 (ARM_V7M_DWT_CYCCNT)
 * 参考：C1.8.5 Cycle Count register, DWT_CYCCNT on page C1-741
 * -----------------------------------------------------------------------------
 */
/* CYCCNT - Cycle count, bits[31:0] */
#define ARM_V7M_DWT_CYCCNT_CYCCNT_Pos       0U
#define ARM_V7M_DWT_CYCCNT_CYCCNT_Msk       (0xFFFFFFFFUL << ARM_V7M_DWT_CYCCNT_CYCCNT_Pos)

/* -----------------------------------------------------------------------------
 * 12.2 DWT_CPICNT 寄存器位域 (ARM_V7M_DWT_CPICNT)
 * 参考：C1.8.6 CPI Count register, DWT_CPICNT on page C1-741
 * -----------------------------------------------------------------------------
 */
/* CPICNT - CPI count, bits[7:0] */
#define ARM_V7M_DWT_CPICNT_CPICNT_Pos       0U
#define ARM_V7M_DWT_CPICNT_CPICNT_Msk       (0xFFUL << ARM_V7M_DWT_CPICNT_CPICNT_Pos)

/* -----------------------------------------------------------------------------
 * 12.3 DWT_EXCCNT 寄存器位域 (ARM_V7M_DWT_EXCCNT)
 * 参考：C1.8.7 Exception Overhead Count register, DWT_EXCCNT on page C1-742
 * -----------------------------------------------------------------------------
 */
/* EXCCNT - Exception overhead count, bits[7:0] */
#define ARM_V7M_DWT_EXCCNT_EXCCNT_Pos       0U
#define ARM_V7M_DWT_EXCCNT_EXCCNT_Msk       (0xFFUL << ARM_V7M_DWT_EXCCNT_EXCCNT_Pos)

/* -----------------------------------------------------------------------------
 * 12.4 DWT_SLEEPCNT 寄存器位域 (ARM_V7M_DWT_SLEEPCNT)
 * 参考：C1.8.8 Sleep Count register, DWT_SLEEPCNT on page C1-742
 * -----------------------------------------------------------------------------
 */
/* SLEEPCNT - Sleep count, bits[7:0] */
#define ARM_V7M_DWT_SLEEPCNT_SLEEPCNT_Pos   0U
#define ARM_V7M_DWT_SLEEPCNT_SLEEPCNT_Msk   (0xFFUL << ARM_V7M_DWT_SLEEPCNT_SLEEPCNT_Pos)

/* -----------------------------------------------------------------------------
 * 12.5 DWT_LSUCNT 寄存器位域 (ARM_V7M_DWT_LSUCNT)
 * 参考：C1.8.9 LSU Count register, DWT_LSUCNT on page C1-743
 * -----------------------------------------------------------------------------
 */
/* LSUCNT - LSU count, bits[7:0] */
#define ARM_V7M_DWT_LSUCNT_LSUCNT_Pos       0U
#define ARM_V7M_DWT_LSUCNT_LSUCNT_Msk       (0xFFUL << ARM_V7M_DWT_LSUCNT_LSUCNT_Pos)

/* -----------------------------------------------------------------------------
 * 12.6 DWT_FOLDCNT 寄存器位域 (ARM_V7M_DWT_FOLDCNT)
 * 参考：C1.8.10 Folded-instruction Count register, DWT_FOLDCNT on page C1-744
 * -----------------------------------------------------------------------------
 */
/* FOLDCNT - Folded-instruction count, bits[7:0] */
#define ARM_V7M_DWT_FOLDCNT_FOLDCNT_Pos     0U
#define ARM_V7M_DWT_FOLDCNT_FOLDCNT_Msk     (0xFFUL << ARM_V7M_DWT_FOLDCNT_FOLDCNT_Pos)

/* -----------------------------------------------------------------------------
 * 12.7 DWT_PCSR 寄存器位域 (ARM_V7M_DWT_PCSR)
 * 参考：C1.8.11 Program Counter Sample Register, DWT_PCSR on page C1-745
 * -----------------------------------------------------------------------------
 */
/* PCSAMPLE - PC sample, bits[31:0] */
#define ARM_V7M_DWT_PCSR_PCSAMPLE_Pos       0U
#define ARM_V7M_DWT_PCSR_PCSAMPLE_Msk       (0xFFFFFFFFUL << ARM_V7M_DWT_PCSR_PCSAMPLE_Pos)

/* ==============================================================================
 * 十三、ITM TER 寄存器位域 (ITM Trace Enable Register Bit-fields)
 * 参考：C1.7.4 Trace Enable registers, ITM_TER0-ITM_TER7 on page C1-714
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 13.1 ITM_TER 寄存器位域说明
 * 参考：C1.7.4 Trace Enable registers, ITM_TER0-ITM_TER7 on page C1-714
 *
 * ITM_TER 寄存器使用索引访问模式，例如：
 *   ARM_V7M_ITM_TER(n)  - Trace Enable Register n (n=0-7)
 *
 * 位域说明：
 *   每个 TER 寄存器包含 32 位，每一位控制一个激励端口的使能
 *   位 m=1: 使能激励端口 32n+m
 *   位 m=0: 禁用激励端口 32n+m
 * -----------------------------------------------------------------------------
 */

/* 对于 ITM_TER(n)，每个位的宏定义 (n=0-7, bit=0-31)
 * 示例：ARM_V7M_ITM_TER_EN(0, 5) 表示 ITM_TER0 的位 5，控制 STIM5
 */
#define ARM_V7M_ITM_TER_EN(n, bit)        (1UL << (bit))  /* Stimulus port 32n+bit enable */

/* ==============================================================================
 * 十四、ROM 表寄存器位域 (ROM Table Register Bit-fields)
 * 参考：Table C1-3 Armv7-M DAP accessible ROM table on page C1-686
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 14.1 ROM_MEMTYPE 寄存器位域 (ARM_V7M_ROM_MEMTYPE)
 * 参考：Table C1-3 Armv7-M DAP accessible ROM table on page C1-686
 * -----------------------------------------------------------------------------
 */
/* SYSM - System present, bit[0] */
#define ARM_V7M_ROM_MEMTYPE_SYSM_Pos      0U
#define ARM_V7M_ROM_MEMTYPE_SYSM_Msk      (1UL << ARM_V7M_ROM_MEMTYPE_SYSM_Pos)

/* ==============================================================================
 * 十五、调试锁定寄存器位域 (Debug Lock Register Bit-fields)
 * 参考：Table D1-2 CoreSight Software Lock registers on page D1-767
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 15.1 DWT_LAR 寄存器位域 (ARM_V7M_DWT_LAR)
 * 参考：Table D1-2 CoreSight Software Lock registers on page D1-767
 * -----------------------------------------------------------------------------
 */
/* LOCK - Lock value (write 0xC5ACCE55 to unlock), bits[31:0] */
#define ARM_V7M_DWT_LAR_LOCK_Pos          0U
#define ARM_V7M_DWT_LAR_LOCK_Msk          (0xFFFFFFFFUL << ARM_V7M_DWT_LAR_LOCK_Pos)

/* -----------------------------------------------------------------------------
 * 15.2 DWT_LSR 寄存器位域 (ARM_V7M_DWT_LSR)
 * 参考：Table D1-2 CoreSight Software Lock registers on page D1-767
 * -----------------------------------------------------------------------------
 */
/* LOCKED - Locked status, bit[1] */
#define ARM_V7M_DWT_LSR_LOCKED_Pos        1U
#define ARM_V7M_DWT_LSR_LOCKED_Msk        (1UL << ARM_V7M_DWT_LSR_LOCKED_Pos)
/* PRESENT - Present status, bit[0] */
#define ARM_V7M_DWT_LSR_PRESENT_Pos       0U
#define ARM_V7M_DWT_LSR_PRESENT_Msk       (1UL << ARM_V7M_DWT_LSR_PRESENT_Pos)

/* -----------------------------------------------------------------------------
 * 15.3 ITM_LAR 寄存器位域 (ARM_V7M_ITM_LAR)
 * 参考：Table D1-2 CoreSight Software Lock registers on page D1-767
 * -----------------------------------------------------------------------------
 */
/* LOCK - Lock value (write 0xC5ACCE55 to unlock), bits[31:0] */
#define ARM_V7M_ITM_LAR_LOCK_Pos          0U
#define ARM_V7M_ITM_LAR_LOCK_Msk          (0xFFFFFFFFUL << ARM_V7M_ITM_LAR_LOCK_Pos)

/* -----------------------------------------------------------------------------
 * 15.4 ITM_LSR 寄存器位域 (ARM_V7M_ITM_LSR)
 * 参考：Table D1-2 CoreSight Software Lock registers on page D1-767
 * -----------------------------------------------------------------------------
 */
/* LOCKED - Locked status, bit[1] */
#define ARM_V7M_ITM_LSR_LOCKED_Pos        1U
#define ARM_V7M_ITM_LSR_LOCKED_Msk        (1UL << ARM_V7M_ITM_LSR_LOCKED_Pos)
/* PRESENT - Present status, bit[0] */
#define ARM_V7M_ITM_LSR_PRESENT_Pos       0U
#define ARM_V7M_ITM_LSR_PRESENT_Msk       (1UL << ARM_V7M_ITM_LSR_PRESENT_Pos)

/* -----------------------------------------------------------------------------
 * 15.5 FPB_LAR 寄存器位域 (ARM_V7M_FPB_LAR)
 * 参考：Table D1-2 CoreSight Software Lock registers on page D1-767
 * -----------------------------------------------------------------------------
 */
/* LOCK - Lock value (write 0xC5ACCE55 to unlock), bits[31:0] */
#define ARM_V7M_FPB_LAR_LOCK_Pos          0U
#define ARM_V7M_FPB_LAR_LOCK_Msk          (0xFFFFFFFFUL << ARM_V7M_FPB_LAR_LOCK_Pos)

/* -----------------------------------------------------------------------------
 * 15.6 FPB_LSR 寄存器位域 (ARM_V7M_FPB_LSR)
 * 参考：Table D1-2 CoreSight Software Lock registers on page D1-767
 * -----------------------------------------------------------------------------
 */
/* LOCKED - Locked status, bit[1] */
#define ARM_V7M_FPB_LSR_LOCKED_Pos        1U
#define ARM_V7M_FPB_LSR_LOCKED_Msk        (1UL << ARM_V7M_FPB_LSR_LOCKED_Pos)
/* PRESENT - Present status, bit[0] */
#define ARM_V7M_FPB_LSR_PRESENT_Pos       0U
#define ARM_V7M_FPB_LSR_PRESENT_Msk       (1UL << ARM_V7M_FPB_LSR_PRESENT_Pos)

/* -----------------------------------------------------------------------------
 * 15.7 TPIU_LAR 寄存器位域 (ARM_V7M_TPIU_LAR)
 * 参考：Table D1-2 CoreSight Software Lock registers on page D1-767
 * -----------------------------------------------------------------------------
 */
/* LOCK - Lock value (write 0xC5ACCE55 to unlock), bits[31:0] */
#define ARM_V7M_TPIU_LAR_LOCK_Pos         0U
#define ARM_V7M_TPIU_LAR_LOCK_Msk         (0xFFFFFFFFUL << ARM_V7M_TPIU_LAR_LOCK_Pos)

/* -----------------------------------------------------------------------------
 * 15.8 TPIU_LSR 寄存器位域 (ARM_V7M_TPIU_LSR)
 * 参考：Table D1-2 CoreSight Software Lock registers on page D1-767
 * -----------------------------------------------------------------------------
 */
/* LOCKED - Locked status, bit[1] */
#define ARM_V7M_TPIU_LSR_LOCKED_Pos       1U
#define ARM_V7M_TPIU_LSR_LOCKED_Msk       (1UL << ARM_V7M_TPIU_LSR_LOCKED_Pos)
/* PRESENT - Present status, bit[0] */
#define ARM_V7M_TPIU_LSR_PRESENT_Pos      0U
#define ARM_V7M_TPIU_LSR_PRESENT_Msk      (1UL << ARM_V7M_TPIU_LSR_PRESENT_Pos)

/* ==============================================================================
 * 15.8.1 调试锁定寄存器值定义宏 (Debug Lock Register Value Definition Macros)
 * 非寄存器位域宏，用于定义 LAR 寄存器的解锁值
 * ==============================================================================
 */
#define ARM_V7M_DWT_LAR_LOCK_VALUE        0xC5ACCE55UL
#define ARM_V7M_ITM_LAR_LOCK_VALUE        0xC5ACCE55UL
#define ARM_V7M_FPB_LAR_LOCK_VALUE        0xC5ACCE55UL
#define ARM_V7M_TPIU_LAR_LOCK_VALUE       0xC5ACCE55UL

#ifdef __cplusplus
}
#endif

#endif /* __ARM_V7M_MACRO_H__ */
