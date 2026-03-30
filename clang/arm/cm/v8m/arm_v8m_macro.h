/********************************************************************************
 * @file    arm_v8m_macro.h
 * @brief   ARMv8-M 架构寄存器位域宏定义头文件
 * @author  Auto-generated based on ARMv8-M Architecture Reference Manual
 * @date    2026-03-30
 * @version V1.0.0
 * @note    此文件定义了 ARMv8-M 架构中所有系统控制寄存器的位域宏
 *          参考文档: Arm® v8-M Architecture Reference Manual
 *          代码风格对齐: arm_v7m_macro.h
 ********************************************************************************/

#ifndef __ARM_V8M_MACRO_H__
#define __ARM_V8M_MACRO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* ==============================================================================
 * 一、Arm 核心寄存器位域 (Arm Core Registers Bit-fields)
 * 参考: D1.2 Alphabetical list of registers
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 1.1 APSR 寄存器位域 (ARM_V8M_REG_APSR)
 * 参考: D1.2.4 APSR, Application Program Status Register
 * -----------------------------------------------------------------------------
 */
/* N - Negative condition code flag, bit[31]
   负数条件码标志 */
#define ARM_V8M_APSR_N_Pos            31U
#define ARM_V8M_APSR_N_Msk            (1UL << ARM_V8M_APSR_N_Pos)
/* Z - Zero condition code flag, bit[30]
   零条件码标志 */
#define ARM_V8M_APSR_Z_Pos            30U
#define ARM_V8M_APSR_Z_Msk            (1UL << ARM_V8M_APSR_Z_Pos)
/* C - Carry condition code flag, bit[29]
   进位条件码标志 */
#define ARM_V8M_APSR_C_Pos            29U
#define ARM_V8M_APSR_C_Msk            (1UL << ARM_V8M_APSR_C_Pos)
/* V - Overflow condition code flag, bit[28]
   溢出条件码标志 */
#define ARM_V8M_APSR_V_Pos            28U
#define ARM_V8M_APSR_V_Msk            (1UL << ARM_V8M_APSR_V_Pos)
/* Q - DSP overflow and saturation flag, bit[27]
   DSP 溢出和饱和标志 */
#define ARM_V8M_APSR_Q_Pos            27U
#define ARM_V8M_APSR_Q_Msk            (1UL << ARM_V8M_APSR_Q_Pos)
/* GE[3:0] - Greater than or Equal flags for DSP operations, bits[19:16]
   DSP 操作的大于等于标志 */
#define ARM_V8M_APSR_GE_Pos           16U
#define ARM_V8M_APSR_GE_Msk           (0xFUL << ARM_V8M_APSR_GE_Pos)
/* GE0 - Greater than or Equal flag 0 for DSP operations, bit[16] */
#define ARM_V8M_APSR_GE0_Pos          16U
#define ARM_V8M_APSR_GE0_Msk          (1UL << ARM_V8M_APSR_GE0_Pos)
/* GE1 - Greater than or Equal flag 1 for DSP operations, bit[17] */
#define ARM_V8M_APSR_GE1_Pos          17U
#define ARM_V8M_APSR_GE1_Msk          (1UL << ARM_V8M_APSR_GE1_Pos)
/* GE2 - Greater than or Equal flag 2 for DSP operations, bit[18] */
#define ARM_V8M_APSR_GE2_Pos          18U
#define ARM_V8M_APSR_GE2_Msk          (1UL << ARM_V8M_APSR_GE2_Pos)
/* GE3 - Greater than or Equal flag 3 for DSP operations, bit[19] */
#define ARM_V8M_APSR_GE3_Pos          19U
#define ARM_V8M_APSR_GE3_Msk          (1UL << ARM_V8M_APSR_GE3_Pos)

/* -----------------------------------------------------------------------------
 * 1.2 IPSR 寄存器位域 (ARM_V8M_REG_IPSR)
 * 参考: D1.2.142 IPSR, Interrupt Program Status Register
 * -----------------------------------------------------------------------------
 */
/* ISR[8:0] - Exception number of the currently executing exception, bits[8:0]
   当前执行异常的异常编号 */
#define ARM_V8M_IPSR_ISR_Pos          0U
#define ARM_V8M_IPSR_ISR_Msk          (0x1FFUL << ARM_V8M_IPSR_ISR_Pos)

/* -----------------------------------------------------------------------------
 * 1.3 EPSR 寄存器位域 (ARM_V8M_REG_EPSR)
 * 参考: D1.2.79 EPSR, Execution Program Status Register
 * -----------------------------------------------------------------------------
 */
/* ICI/IT-1 (IT[1:0] / ICI[7:6]) - If-Then execution state bits and Interruptible-Continuable Instruction bits (part 1), bits[26:25]
   If-Then 执行状态位和可中断可继续指令位 (第1部分) */
#define ARM_V8M_EPSR_ICI_IT_1_Pos     25U
#define ARM_V8M_EPSR_ICI_IT_1_Msk     (0x3UL << ARM_V8M_EPSR_ICI_IT_1_Pos)
/* IT[1:0] - If-Then execution state bits (part 1), bits[26:25] */
#define ARM_V8M_EPSR_IT_1_0_Pos       25U
#define ARM_V8M_EPSR_IT_1_0_Msk       (0x3UL << ARM_V8M_EPSR_IT_1_0_Pos)
/* T - Thumb state bit, bit[24]
   Thumb 状态位，必须为1 */
#define ARM_V8M_EPSR_T_Pos            24U
#define ARM_V8M_EPSR_T_Msk            (1UL << ARM_V8M_EPSR_T_Pos)
/* ICI/IT-2 - If-Then execution state bits and Interruptible-Continuable Instruction bits (part 2), bits[15:10]
   If-Then 执行状态位和可中断可继续指令位 (第2部分) */
#define ARM_V8M_EPSR_ICI_IT_2_Pos     10U
#define ARM_V8M_EPSR_ICI_IT_2_Msk     (0x3FUL << ARM_V8M_EPSR_ICI_IT_2_Pos)
/* IT[7:4] - If-Then execution state bits (part 2), bits[15:12] */
#define ARM_V8M_EPSR_IT_7_4_Pos       12U
#define ARM_V8M_EPSR_IT_7_4_Msk       (0xFUL << ARM_V8M_EPSR_IT_7_4_Pos)
/* IT[3:2] - If-Then execution state bits (part 3), bits[11:10] */
#define ARM_V8M_EPSR_IT_3_2_Pos       10U
#define ARM_V8M_EPSR_IT_3_2_Msk       (0x3UL << ARM_V8M_EPSR_IT_3_2_Pos)
/* ICI[5:2] - Interruptible-Continuable Instruction bits (part 2), bits[15:12] */
#define ARM_V8M_EPSR_ICI_5_2_Pos      12U
#define ARM_V8M_EPSR_ICI_5_2_Msk      (0xFUL << ARM_V8M_EPSR_ICI_5_2_Pos)
/* ICI[1:0] - Interruptible-Continuable Instruction bits (part 3), bits[11:10] */
#define ARM_V8M_EPSR_ICI_1_0_Pos      10U
#define ARM_V8M_EPSR_ICI_1_0_Msk      (0x3UL << ARM_V8M_EPSR_ICI_1_0_Pos)

/* -----------------------------------------------------------------------------
 * 1.4 PRIMASK 寄存器位域 (ARM_V8M_REG_PRIMASK)
 * 参考: D1.2.217 PRIMASK, Exception Mask Register
 * -----------------------------------------------------------------------------
 */
/* PM - The exception mask bit, bit[0]
   异常屏蔽位: 1=屏蔽可配置优先级异常 */
#define ARM_V8M_PRIMASK_PM_Pos        0U
#define ARM_V8M_PRIMASK_PM_Msk        (1UL << ARM_V8M_PRIMASK_PM_Pos)

/* -----------------------------------------------------------------------------
 * 1.5 BASEPRI 寄存器位域 (ARM_V8M_REG_BASEPRI)
 * 参考: D1.2.5 BASEPRI, Base Priority Mask Register
 * -----------------------------------------------------------------------------
 */
/* PRI[7:0] - Base priority mask value, bits[7:0]
   基础优先级屏蔽值 */
#define ARM_V8M_BASEPRI_PRI_Pos       0U
#define ARM_V8M_BASEPRI_PRI_Msk       (0xFFUL << ARM_V8M_BASEPRI_PRI_Pos)

/* -----------------------------------------------------------------------------
 * 1.6 FAULTMASK 寄存器位域 (ARM_V8M_REG_FAULTMASK)
 * 参考: D1.2.97 FAULTMASK, Fault Mask Register
 * -----------------------------------------------------------------------------
 */
/* FM - The fault mask bit, bit[0]
   故障屏蔽位: 1=屏蔽所有异常 (除NMI) */
#define ARM_V8M_FAULTMASK_FM_Pos      0U
#define ARM_V8M_FAULTMASK_FM_Msk      (1UL << ARM_V8M_FAULTMASK_FM_Pos)

/* -----------------------------------------------------------------------------
 * 1.7 CONTROL 寄存器位域 (ARM_V8M_REG_CONTROL)
 * 参考: D1.2.13 CONTROL, Control Register
 * -----------------------------------------------------------------------------
 */
/* nPRIV - Thread mode privilege level, bit[0]
   Thread 模式特权级: 0=特权级, 1=非特权级 */
#define ARM_V8M_CONTROL_nPRIV_Pos     0U
#define ARM_V8M_CONTROL_nPRIV_Msk     (1UL << ARM_V8M_CONTROL_nPRIV_Pos)
/* SPSEL - Stack pointer selection, bit[1]
   栈指针选择: 0=MSP, 1=PSP (仅Thread模式) */
#define ARM_V8M_CONTROL_SPSEL_Pos     1U
#define ARM_V8M_CONTROL_SPSEL_Msk     (1UL << ARM_V8M_CONTROL_SPSEL_Pos)
/* FPCA - Floating-point context active, bit[2]
   浮点上下文激活 */
#define ARM_V8M_CONTROL_FPCA_Pos      2U
#define ARM_V8M_CONTROL_FPCA_Msk      (1UL << ARM_V8M_CONTROL_FPCA_Pos)
/* SFPA - Secure floating-point active, bit[3]
   【v8m 独有】安全浮点激活 */
#define ARM_V8M_CONTROL_SFPA_Pos      3U
#define ARM_V8M_CONTROL_SFPA_Msk      (1UL << ARM_V8M_CONTROL_SFPA_Pos)

/* -----------------------------------------------------------------------------
 * 1.8 MSPLIM 寄存器位域 (ARM_V8M_REG_MSPLIM)
 * 参考: D1.2.177 MSPLIM, Main Stack Pointer Limit Register
 * 【v8m 独有】
 * -----------------------------------------------------------------------------
 */
/* LIMIT - Stack limit, bits[31:3]
   主栈指针限制地址的高29位，bits[2:0]保留为0 */
#define ARM_V8M_MSPLIM_LIMIT_Pos      3U
#define ARM_V8M_MSPLIM_LIMIT_Msk      (0x1FFFFFFFUL << ARM_V8M_MSPLIM_LIMIT_Pos)

/* -----------------------------------------------------------------------------
 * 1.9 PSPLIM 寄存器位域 (ARM_V8M_REG_PSPLIM)
 * 参考: D1.2.218 PSPLIM, Process Stack Pointer Limit Register
 * 【v8m 独有】
 * -----------------------------------------------------------------------------
 */
/* LIMIT - Stack limit, bits[31:3]
   进程栈指针限制地址的高29位，bits[2:0]保留为0 */
#define ARM_V8M_PSPLIM_LIMIT_Pos      3U
#define ARM_V8M_PSPLIM_LIMIT_Msk      (0x1FFFFFFFUL << ARM_V8M_PSPLIM_LIMIT_Pos)

/* ==============================================================================
 * 二、系统控制空间 (SCS) 寄存器位域
 * 地址范围: 0xE000E000 - 0xE000EFFF (Secure), 0xE002E000 - 0xE002EFFF (Non-secure 别名)
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 1.1 ICTR 寄存器位域 (ARM_V8M_SCS_ICTR)
 * 参考: D1.2.111 ICTR, Interrupt Controller Type Register
 * -----------------------------------------------------------------------------
 */
/* INTLINESNUM - Interrupt lines number, bits[3:0]
   指示中断线数量: 0=32, 1=64, 2=96, 3=128, 4=160, 5=192, 6=224, 7=256 */
#define ARM_V8M_ICTR_INTLINESNUM_Pos    0U
#define ARM_V8M_ICTR_INTLINESNUM_Msk    (0xFUL << ARM_V8M_ICTR_INTLINESNUM_Pos)

/* -----------------------------------------------------------------------------
 * 1.2 ACTLR 寄存器位域 (ARM_V8M_SCS_ACTLR)
 * 参考: D1.2.1 ACTLR, Auxiliary Control Register
 * -----------------------------------------------------------------------------
 */
/* DISMCYCINT - Disable multi-cycle interrupt, bit[0]
   1=禁用多周期中断延迟 */
#define ARM_V8M_ACTLR_DISMCYCINT_Pos    0U
#define ARM_V8M_ACTLR_DISMCYCINT_Msk    (1UL << ARM_V8M_ACTLR_DISMCYCINT_Pos)
/* DISDEFWBUF - Disable write buffer, bit[1]
   1=禁用默认内存映射访问的写缓冲 */
#define ARM_V8M_ACTLR_DISDEFWBUF_Pos    1U
#define ARM_V8M_ACTLR_DISDEFWBUF_Msk    (1UL << ARM_V8M_ACTLR_DISDEFWBUF_Pos)
/* DISFOLD - Disable instruction folding, bit[2]
   1=禁用指令折叠 */
#define ARM_V8M_ACTLR_DISFOLD_Pos       2U
#define ARM_V8M_ACTLR_DISFOLD_Msk       (1UL << ARM_V8M_ACTLR_DISFOLD_Pos)
/* DISFPCA - Disable automatic FP context, bit[8]
   1=禁用自动浮点上下文保存 */
#define ARM_V8M_ACTLR_DISFPCA_Pos       8U
#define ARM_V8M_ACTLR_DISFPCA_Msk       (1UL << ARM_V8M_ACTLR_DISFPCA_Pos)
/* DISOOFP - Disable out-of-order FP, bit[9]
   1=禁用乱序浮点指令完成 */
#define ARM_V8M_ACTLR_DISOOFP_Pos       9U
#define ARM_V8M_ACTLR_DISOOFP_Msk       (1UL << ARM_V8M_ACTLR_DISOOFP_Pos)

/* -----------------------------------------------------------------------------
 * 1.3 CPPWR 寄存器位域 (ARM_V8M_SCS_CPPWR)
 * 参考: D1.2.15 CPPWR, Coprocessor Power Control Register
 * 【v8m 独有】
 * -----------------------------------------------------------------------------
 */
/* SUS10 - Suspend coprocessor 10, bit[0]
   1=请求暂停协处理器10 */
#define ARM_V8M_CPPWR_SUS10_Pos         0U
#define ARM_V8M_CPPWR_SUS10_Msk         (1UL << ARM_V8M_CPPWR_SUS10_Pos)
/* SUS11 - Suspend coprocessor 11, bit[1]
   1=请求暂停协处理器11 */
#define ARM_V8M_CPPWR_SUS11_Pos         1U
#define ARM_V8M_CPPWR_SUS11_Msk         (1UL << ARM_V8M_CPPWR_SUS11_Pos)
/* SU10 - State unknown coprocessor 10, bit[16]
   1=协处理器10状态未知 */
#define ARM_V8M_CPPWR_SU10_Pos          16U
#define ARM_V8M_CPPWR_SU10_Msk          (1UL << ARM_V8M_CPPWR_SU10_Pos)
/* SU11 - State unknown coprocessor 11, bit[17]
   1=协处理器11状态未知 */
#define ARM_V8M_CPPWR_SU11_Pos          17U
#define ARM_V8M_CPPWR_SU11_Msk          (1UL << ARM_V8M_CPPWR_SU11_Pos)

/* ==============================================================================
 * 二、系统控制块 (SCB) 寄存器位域
 * 地址范围: 0xE000ED00 - 0xE000ED3F (Secure), 0xE002ED00 - 0xE002ED3F (Non-secure 别名)
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 2.1 CPUID 寄存器位域 (ARM_V8M_SCB_CPUID)
 * 参考: D1.2.34 CPUID, CPUID Base Register
 * -----------------------------------------------------------------------------
 */
/* Revision - Revision number, bits[3:0]
   实现定义的修订版本号 */
#define ARM_V8M_CPUID_REVISION_Pos      0U
#define ARM_V8M_CPUID_REVISION_Msk      (0xFUL << ARM_V8M_CPUID_REVISION_Pos)
/* PartNo - Part number, bits[15:4]
   处理器部件号: 0xD20=Cortex-M23, 0xD21=Cortex-M33 */
#define ARM_V8M_CPUID_PARTNO_Pos        4U
#define ARM_V8M_CPUID_PARTNO_Msk        (0xFFFUL << ARM_V8M_CPUID_PARTNO_Pos)
/* Architecture - Architecture, bits[19:16]
   架构版本: 0xC=ARMv8-M */
#define ARM_V8M_CPUID_ARCHITECTURE_Pos  16U
#define ARM_V8M_CPUID_ARCHITECTURE_Msk  (0xFUL << ARM_V8M_CPUID_ARCHITECTURE_Pos)
/* Variant - Variant number, bits[23:20]
   实现定义的变体号 */
#define ARM_V8M_CPUID_VARIANT_Pos       20U
#define ARM_V8M_CPUID_VARIANT_Msk       (0xFUL << ARM_V8M_CPUID_VARIANT_Pos)
/* Implementer - Implementer code, bits[31:24]
   实现者代码: 0x41=ARM */
#define ARM_V8M_CPUID_IMPLEMENTER_Pos   24U
#define ARM_V8M_CPUID_IMPLEMENTER_Msk   (0xFFUL << ARM_V8M_CPUID_IMPLEMENTER_Pos)

/* -----------------------------------------------------------------------------
 * 2.2 ICSR 寄存器位域 (ARM_V8M_SCB_ICSR)
 * 参考: D1.2.112 ICSR, Interrupt Control and State Register
 * -----------------------------------------------------------------------------
 */
/* VECTACTIVE - Active exception number, bits[8:0]
   当前活动的异常编号: 0=Thread, 1=NMI, 2=HardFault, ... */
#define ARM_V8M_ICSR_VECTACTIVE_Pos     0U
#define ARM_V8M_ICSR_VECTACTIVE_Msk     (0x1FFUL << ARM_V8M_ICSR_VECTACTIVE_Pos)
/* VECTPENDING - Pending exception number, bits[20:12]
   最高优先级待处理异常编号 */
#define ARM_V8M_ICSR_VECTPENDING_Pos    12U
#define ARM_V8M_ICSR_VECTPENDING_Msk    (0x1FFUL << ARM_V8M_ICSR_VECTPENDING_Pos)
/* ISRPENDING - Interrupt pending flag, bit[22]
   1=有外部中断待处理 */
#define ARM_V8M_ICSR_ISRPENDING_Pos     22U
#define ARM_V8M_ICSR_ISRPENDING_Msk     (1UL << ARM_V8M_ICSR_ISRPENDING_Pos)
/* ISRPREEMPT - Interrupt preempt flag, bit[23]
   1=有更高优先级中断可抢占 */
#define ARM_V8M_ICSR_ISRPREEMPT_Pos     23U
#define ARM_V8M_ICSR_ISRPREEMPT_Msk     (1UL << ARM_V8M_ICSR_ISRPREEMPT_Pos)
/* PENDSTCLR - SysTick clear pending, bit[25]
   1=清除SysTick待处理状态 */
#define ARM_V8M_ICSR_PENDSTCLR_Pos      25U
#define ARM_V8M_ICSR_PENDSTCLR_Msk      (1UL << ARM_V8M_ICSR_PENDSTCLR_Pos)
/* PENDSTSET - SysTick set pending, bit[26]
   1=设置SysTick待处理状态 */
#define ARM_V8M_ICSR_PENDSTSET_Pos      26U
#define ARM_V8M_ICSR_PENDSTSET_Msk      (1UL << ARM_V8M_ICSR_PENDSTSET_Pos)
/* PENDSVCLR - PendSV clear pending, bit[27]
   1=清除PendSV待处理状态 */
#define ARM_V8M_ICSR_PENDSVCLR_Pos      27U
#define ARM_V8M_ICSR_PENDSVCLR_Msk      (1UL << ARM_V8M_ICSR_PENDSVCLR_Pos)
/* PENDSVSET - PendSV set pending, bit[28]
   1=设置PendSV待处理状态 */
#define ARM_V8M_ICSR_PENDSVSET_Pos      28U
#define ARM_V8M_ICSR_PENDSVSET_Msk      (1UL << ARM_V8M_ICSR_PENDSVSET_Pos)
/* NMIPENDSET - NMI set pending, bit[31]
   1=设置NMI待处理状态 */
#define ARM_V8M_ICSR_NMIPENDSET_Pos     31U
#define ARM_V8M_ICSR_NMIPENDSET_Msk     (1UL << ARM_V8M_ICSR_NMIPENDSET_Pos)

/* -----------------------------------------------------------------------------
 * 2.3 VTOR 寄存器位域 (ARM_V8M_SCB_VTOR)
 * 参考: D1.2.241 VTOR, Vector Table Offset Register
 * -----------------------------------------------------------------------------
 */
/* TBLOFF - Vector table base offset, bits[31:7]
   向量表基地址偏移，必须128字节对齐 */
#define ARM_V8M_VTOR_TBLOFF_Pos         7U
#define ARM_V8M_VTOR_TBLOFF_Msk         (0x1FFFFFFUL << ARM_V8M_VTOR_TBLOFF_Pos)

/* -----------------------------------------------------------------------------
 * 2.4 AIRCR 寄存器位域 (ARM_V8M_SCB_AIRCR)
 * 参考: D1.2.9 AIRCR, Application Interrupt and Reset Control Register
 * -----------------------------------------------------------------------------
 */
/* VECTRESET - Vector reset, bit[0]
   1=请求本地复位，写1自清除 */
#define ARM_V8M_AIRCR_VECTRESET_Pos     0U
#define ARM_V8M_AIRCR_VECTRESET_Msk     (1UL << ARM_V8M_AIRCR_VECTRESET_Pos)
/* VECTCLRACTIVE - Clear active vector, bit[1]
   1=清除所有活动异常状态 */
#define ARM_V8M_AIRCR_VECTCLRACTIVE_Pos 1U
#define ARM_V8M_AIRCR_VECTCLRACTIVE_Msk (1UL << ARM_V8M_AIRCR_VECTCLRACTIVE_Pos)
/* SYSRESETREQ - System reset request, bit[2]
   1=请求系统复位 */
#define ARM_V8M_AIRCR_SYSRESETREQ_Pos   2U
#define ARM_V8M_AIRCR_SYSRESETREQ_Msk   (1UL << ARM_V8M_AIRCR_SYSRESETREQ_Pos)
/* SYSRESETREQS - System reset request secure, bit[3]
   【v8m 独有】1=SYSRESETREQ仅Secure状态可写 */
#define ARM_V8M_AIRCR_SYSRESETREQS_Pos  3U
#define ARM_V8M_AIRCR_SYSRESETREQS_Msk  (1UL << ARM_V8M_AIRCR_SYSRESETREQS_Pos)
/* PRIGROUP - Priority group, bits[10:8]
   优先级分组: 0-7，定义抢占优先级和子优先级的划分 */
#define ARM_V8M_AIRCR_PRIGROUP_Pos      8U
#define ARM_V8M_AIRCR_PRIGROUP_Msk      (0x7UL << ARM_V8M_AIRCR_PRIGROUP_Pos)
/* BFHFNMINS - BusFault/HardFault NMI secure, bit[13]
   【v8m 独有】1=BusFault和HardFault在Non-secure状态处理 */
#define ARM_V8M_AIRCR_BFHFNMINS_Pos     13U
#define ARM_V8M_AIRCR_BFHFNMINS_Msk     (1UL << ARM_V8M_AIRCR_BFHFNMINS_Pos)
/* PRIS - Prioritize Secure exceptions, bit[14]
   【v8m 独有】1=Secure异常优先级提升 */
#define ARM_V8M_AIRCR_PRIS_Pos          14U
#define ARM_V8M_AIRCR_PRIS_Msk          (1UL << ARM_V8M_AIRCR_PRIS_Pos)
/* ENDIANNESS - Data endianness, bit[15]
   0=小端，1=大端 */
#define ARM_V8M_AIRCR_ENDIANNESS_Pos    15U
#define ARM_V8M_AIRCR_ENDIANNESS_Msk    (1UL << ARM_V8M_AIRCR_ENDIANNESS_Pos)
/* VECTKEYSTAT - Vector key status, bits[31:16]
   读取返回0x05FA，写入需要0x05FA解锁 */
#define ARM_V8M_AIRCR_VECTKEYSTAT_Pos   16U
#define ARM_V8M_AIRCR_VECTKEYSTAT_Msk   (0xFFFFUL << ARM_V8M_AIRCR_VECTKEYSTAT_Pos)

/* VECTKEY - Register key for write, bits[31:16]
   写入时必须为0x05FA */
#define ARM_V8M_AIRCR_VECTKEY_Pos       16U
#define ARM_V8M_AIRCR_VECTKEY_Msk       (0xFFFFUL << ARM_V8M_AIRCR_VECTKEY_Pos)
#define ARM_V8M_AIRCR_VECTKEY_VALUE     (0x05FAUL << ARM_V8M_AIRCR_VECTKEY_Pos)

/* -----------------------------------------------------------------------------
 * 2.5 SCR 寄存器位域 (ARM_V8M_SCB_SCR)
 * 参考: D1.2.208 SCR, System Control Register
 * -----------------------------------------------------------------------------
 */
/* SLEEPONEXIT - Sleep on exit, bit[1]
   1=退出异常处理时进入睡眠模式 */
#define ARM_V8M_SCR_SLEEPONEXIT_Pos     1U
#define ARM_V8M_SCR_SLEEPONEXIT_Msk     (1UL << ARM_V8M_SCR_SLEEPONEXIT_Pos)
/* SLEEPDEEP - Deep sleep, bit[2]
   1=选择深度睡眠模式 */
#define ARM_V8M_SCR_SLEEPDEEP_Pos       2U
#define ARM_V8M_SCR_SLEEPDEEP_Msk       (1UL << ARM_V8M_SCR_SLEEPDEEP_Pos)
/* SLEEPDEEPS - Deep sleep secure, bit[3]
   【v8m 独有】1=SLEEPDEEP仅Secure状态可写 */
#define ARM_V8M_SCR_SLEEPDEEPS_Pos      3U
#define ARM_V8M_SCR_SLEEPDEEPS_Msk      (1UL << ARM_V8M_SCR_SLEEPDEEPS_Pos)
/* SEVONPEND - Send Event on pending, bit[4]
   1=使能待处理中断触发WFE唤醒 */
#define ARM_V8M_SCR_SEVONPEND_Pos       4U
#define ARM_V8M_SCR_SEVONPEND_Msk       (1UL << ARM_V8M_SCR_SEVONPEND_Pos)

/* -----------------------------------------------------------------------------
 * 2.6 CCR 寄存器位域 (ARM_V8M_SCB_CCR)
 * 参考: D1.2.24 CCR, Configuration and Control Register
 * -----------------------------------------------------------------------------
 */
/* NONBASETHRDENA - Non-base thread enable, bit[0]
   1=允许在异常激活时从Thread模式切换到Thread模式 */
#define ARM_V8M_CCR_NONBASETHRDENA_Pos  0U
#define ARM_V8M_CCR_NONBASETHRDENA_Msk  (1UL << ARM_V8M_CCR_NONBASETHRDENA_Pos)
/* USERSETMPEND - User set main pending, bit[1]
   1=允许非特权软件写入STIR */
#define ARM_V8M_CCR_USERSETMPEND_Pos    1U
#define ARM_V8M_CCR_USERSETMPEND_Msk    (1UL << ARM_V8M_CCR_USERSETMPEND_Pos)
/* UNALIGN_TRP - Unaligned trap, bit[3]
   1=未对齐访问产生UsageFault */
#define ARM_V8M_CCR_UNALIGN_TRP_Pos     3U
#define ARM_V8M_CCR_UNALIGN_TRP_Msk     (1UL << ARM_V8M_CCR_UNALIGN_TRP_Pos)
/* DIV_0_TRP - Divide by zero trap, bit[4]
   1=除零产生UsageFault */
#define ARM_V8M_CCR_DIV_0_TRP_Pos       4U
#define ARM_V8M_CCR_DIV_0_TRP_Msk       (1UL << ARM_V8M_CCR_DIV_0_TRP_Pos)
/* BFHFNMIGN - BusFault/HardFault ignore NMI, bit[5]
   1=忽略BusFault/HardFault的NMI */
#define ARM_V8M_CCR_BFHFNMIGN_Pos       5U
#define ARM_V8M_CCR_BFHFNMIGN_Msk       (1UL << ARM_V8M_CCR_BFHFNMIGN_Pos)
/* STKALIGN - Stack alignment, bit[9]
   1=强制8字节栈对齐 */
#define ARM_V8M_CCR_STKALIGN_Pos        9U
#define ARM_V8M_CCR_STKALIGN_Msk        (1UL << ARM_V8M_CCR_STKALIGN_Pos)
/* DC - Data cache, bit[16]
   【v8m 独有】1=使能数据缓存 */
#define ARM_V8M_CCR_DC_Pos              16U
#define ARM_V8M_CCR_DC_Msk              (1UL << ARM_V8M_CCR_DC_Pos)
/* IC - Instruction cache, bit[17]
   【v8m 独有】1=使能指令缓存 */
#define ARM_V8M_CCR_IC_Pos              17U
#define ARM_V8M_CCR_IC_Msk              (1UL << ARM_V8M_CCR_IC_Pos)
/* BP - Branch prediction, bit[18]
   【v8m 独有】1=使能分支预测 */
#define ARM_V8M_CCR_BP_Pos              18U
#define ARM_V8M_CCR_BP_Msk              (1UL << ARM_V8M_CCR_BP_Pos)

/* -----------------------------------------------------------------------------
 * 2.7 SHPR1 寄存器位域 (ARM_V8M_SCB_SHPR1)
 * 参考: D1.2.211 SHPR1, System Handler Priority Register 1
 * -----------------------------------------------------------------------------
 */
/* PRI_4 - Priority of system handler 4 (MemManage), bits[7:0] */
#define ARM_V8M_SHPR1_PRI_4_Pos         0U
#define ARM_V8M_SHPR1_PRI_4_Msk         (0xFFUL << ARM_V8M_SHPR1_PRI_4_Pos)
/* PRI_5 - Priority of system handler 5 (BusFault), bits[15:8] */
#define ARM_V8M_SHPR1_PRI_5_Pos         8U
#define ARM_V8M_SHPR1_PRI_5_Msk         (0xFFUL << ARM_V8M_SHPR1_PRI_5_Pos)
/* PRI_6 - Priority of system handler 6 (UsageFault), bits[23:16] */
#define ARM_V8M_SHPR1_PRI_6_Pos         16U
#define ARM_V8M_SHPR1_PRI_6_Msk         (0xFFUL << ARM_V8M_SHPR1_PRI_6_Pos)
/* PRI_7 - Priority of system handler 7 (SecureFault), bits[31:24] */
#define ARM_V8M_SHPR1_PRI_7_Pos         24U
#define ARM_V8M_SHPR1_PRI_7_Msk         (0xFFUL << ARM_V8M_SHPR1_PRI_7_Pos)

/* -----------------------------------------------------------------------------
 * 2.8 SHPR2 寄存器位域 (ARM_V8M_SCB_SHPR2)
 * 参考: D1.2.212 SHPR2, System Handler Priority Register 2
 * -----------------------------------------------------------------------------
 */
/* PRI_8 - Priority of system handler 8 (Reserved), bits[7:0] */
#define ARM_V8M_SHPR2_PRI_8_Pos         0U
#define ARM_V8M_SHPR2_PRI_8_Msk         (0xFFUL << ARM_V8M_SHPR2_PRI_8_Pos)
/* PRI_9 - Priority of system handler 9 (Reserved), bits[15:8] */
#define ARM_V8M_SHPR2_PRI_9_Pos         8U
#define ARM_V8M_SHPR2_PRI_9_Msk         (0xFFUL << ARM_V8M_SHPR2_PRI_9_Pos)
/* PRI_10 - Priority of system handler 10 (Reserved), bits[23:16] */
#define ARM_V8M_SHPR2_PRI_10_Pos        16U
#define ARM_V8M_SHPR2_PRI_10_Msk        (0xFFUL << ARM_V8M_SHPR2_PRI_10_Pos)
/* PRI_11 - Priority of system handler 11 (SVCall), bits[31:24] */
#define ARM_V8M_SHPR2_PRI_11_Pos        24U
#define ARM_V8M_SHPR2_PRI_11_Msk        (0xFFUL << ARM_V8M_SHPR2_PRI_11_Pos)

/* -----------------------------------------------------------------------------
 * 2.9 SHPR3 寄存器位域 (ARM_V8M_SCB_SHPR3)
 * 参考: D1.2.213 SHPR3, System Handler Priority Register 3
 * -----------------------------------------------------------------------------
 */
/* PRI_12 - Priority of system handler 12 (DebugMonitor), bits[7:0] */
#define ARM_V8M_SHPR3_PRI_12_Pos        0U
#define ARM_V8M_SHPR3_PRI_12_Msk        (0xFFUL << ARM_V8M_SHPR3_PRI_12_Pos)
/* PRI_13 - Priority of system handler 13 (Reserved), bits[15:8] */
#define ARM_V8M_SHPR3_PRI_13_Pos        8U
#define ARM_V8M_SHPR3_PRI_13_Msk        (0xFFUL << ARM_V8M_SHPR3_PRI_13_Pos)
/* PRI_14 - Priority of system handler 14 (PendSV), bits[23:16] */
#define ARM_V8M_SHPR3_PRI_14_Pos        16U
#define ARM_V8M_SHPR3_PRI_14_Msk        (0xFFUL << ARM_V8M_SHPR3_PRI_14_Pos)
/* PRI_15 - Priority of system handler 15 (SysTick), bits[31:24] */
#define ARM_V8M_SHPR3_PRI_15_Pos        24U
#define ARM_V8M_SHPR3_PRI_15_Msk        (0xFFUL << ARM_V8M_SHPR3_PRI_15_Pos)

/* -----------------------------------------------------------------------------
 * 2.10 SHCSR 寄存器位域 (ARM_V8M_SCB_SHCSR)
 * 参考: D1.2.209 SHCSR, System Handler Control and State Register
 * -----------------------------------------------------------------------------
 */
/* MEMFAULTACT - MemManage active, bit[0] */
#define ARM_V8M_SHCSR_MEMFAULTACT_Pos   0U
#define ARM_V8M_SHCSR_MEMFAULTACT_Msk   (1UL << ARM_V8M_SHCSR_MEMFAULTACT_Pos)
/* BUSFAULTACT - BusFault active, bit[1] */
#define ARM_V8M_SHCSR_BUSFAULTACT_Pos   1U
#define ARM_V8M_SHCSR_BUSFAULTACT_Msk   (1UL << ARM_V8M_SHCSR_BUSFAULTACT_Pos)
/* HARDFAULTACT - HardFault active, bit[2] */
#define ARM_V8M_SHCSR_HARDFAULTACT_Pos  2U
#define ARM_V8M_SHCSR_HARDFAULTACT_Msk  (1UL << ARM_V8M_SHCSR_HARDFAULTACT_Pos)
/* USGFAULTACT - UsageFault active, bit[3] */
#define ARM_V8M_SHCSR_USGFAULTACT_Pos   3U
#define ARM_V8M_SHCSR_USGFAULTACT_Msk   (1UL << ARM_V8M_SHCSR_USGFAULTACT_Pos)
/* SECUREFAULTACT - SecureFault active, bit[4]
   【v8m 独有】 */
#define ARM_V8M_SHCSR_SECUREFAULTACT_Pos 4U
#define ARM_V8M_SHCSR_SECUREFAULTACT_Msk (1UL << ARM_V8M_SHCSR_SECUREFAULTACT_Pos)
/* NMIACT - NMI active, bit[5] */
#define ARM_V8M_SHCSR_NMIACT_Pos        5U
#define ARM_V8M_SHCSR_NMIACT_Msk        (1UL << ARM_V8M_SHCSR_NMIACT_Pos)
/* SVCALLACT - SVCall active, bit[7] */
#define ARM_V8M_SHCSR_SVCALLACT_Pos     7U
#define ARM_V8M_SHCSR_SVCALLACT_Msk     (1UL << ARM_V8M_SHCSR_SVCALLACT_Pos)
/* MONITORACT - DebugMonitor active, bit[8] */
#define ARM_V8M_SHCSR_MONITORACT_Pos    8U
#define ARM_V8M_SHCSR_MONITORACT_Msk    (1UL << ARM_V8M_SHCSR_MONITORACT_Pos)
/* PENDSVACT - PendSV active, bit[10] */
#define ARM_V8M_SHCSR_PENDSVACT_Pos     10U
#define ARM_V8M_SHCSR_PENDSVACT_Msk     (1UL << ARM_V8M_SHCSR_PENDSVACT_Pos)
/* SYSTICKACT - SysTick active, bit[11] */
#define ARM_V8M_SHCSR_SYSTICKACT_Pos    11U
#define ARM_V8M_SHCSR_SYSTICKACT_Msk    (1UL << ARM_V8M_SHCSR_SYSTICKACT_Pos)
/* USGFAULTPENDED - UsageFault pending, bit[12] */
#define ARM_V8M_SHCSR_USGFAULTPENDED_Pos 12U
#define ARM_V8M_SHCSR_USGFAULTPENDED_Msk (1UL << ARM_V8M_SHCSR_USGFAULTPENDED_Pos)
/* MEMFAULTPENDED - MemManage pending, bit[13] */
#define ARM_V8M_SHCSR_MEMFAULTPENDED_Pos 13U
#define ARM_V8M_SHCSR_MEMFAULTPENDED_Msk (1UL << ARM_V8M_SHCSR_MEMFAULTPENDED_Pos)
/* BUSFAULTPENDED - BusFault pending, bit[14] */
#define ARM_V8M_SHCSR_BUSFAULTPENDED_Pos 14U
#define ARM_V8M_SHCSR_BUSFAULTPENDED_Msk (1UL << ARM_V8M_SHCSR_BUSFAULTPENDED_Pos)
/* SVCALLPENDED - SVCall pending, bit[15] */
#define ARM_V8M_SHCSR_SVCALLPENDED_Pos  15U
#define ARM_V8M_SHCSR_SVCALLPENDED_Msk  (1UL << ARM_V8M_SHCSR_SVCALLPENDED_Pos)
/* MEMFAULTENA - MemManage enable, bit[16] */
#define ARM_V8M_SHCSR_MEMFAULTENA_Pos   16U
#define ARM_V8M_SHCSR_MEMFAULTENA_Msk   (1UL << ARM_V8M_SHCSR_MEMFAULTENA_Pos)
/* BUSFAULTENA - BusFault enable, bit[17] */
#define ARM_V8M_SHCSR_BUSFAULTENA_Pos   17U
#define ARM_V8M_SHCSR_BUSFAULTENA_Msk   (1UL << ARM_V8M_SHCSR_BUSFAULTENA_Pos)
/* USGFAULTENA - UsageFault enable, bit[18] */
#define ARM_V8M_SHCSR_USGFAULTENA_Pos   18U
#define ARM_V8M_SHCSR_USGFAULTENA_Msk   (1UL << ARM_V8M_SHCSR_USGFAULTENA_Pos)
/* SECUREFAULTENA - SecureFault enable, bit[19]
   【v8m 独有】 */
#define ARM_V8M_SHCSR_SECUREFAULTENA_Pos 19U
#define ARM_V8M_SHCSR_SECUREFAULTENA_Msk (1UL << ARM_V8M_SHCSR_SECUREFAULTENA_Pos)
/* HARDFAULTPENDED - HardFault pending, bit[21] */
#define ARM_V8M_SHCSR_HARDFAULTPENDED_Pos 21U
#define ARM_V8M_SHCSR_HARDFAULTPENDED_Msk (1UL << ARM_V8M_SHCSR_HARDFAULTPENDED_Pos)
/* SECUREFAULTPENDED - SecureFault pending, bit[22]
   【v8m 独有】 */
#define ARM_V8M_SHCSR_SECUREFAULTPENDED_Pos 22U
#define ARM_V8M_SHCSR_SECUREFAULTPENDED_Msk (1UL << ARM_V8M_SHCSR_SECUREFAULTPENDED_Pos)

/* -----------------------------------------------------------------------------
 * 2.11 CFSR 寄存器位域 (ARM_V8M_SCB_CFSR)
 * 参考: D1.2.23 CFSR, Configurable Fault Status Register
 * -----------------------------------------------------------------------------
 */

/* MMFSR - MemManage Fault Status Register, bits[7:0] */
/* IACCVIOL - Instruction access violation, bit[0] */
#define ARM_V8M_MMFSR_IACCVIOL_Pos      0U
#define ARM_V8M_MMFSR_IACCVIOL_Msk      (1UL << ARM_V8M_MMFSR_IACCVIOL_Pos)
/* DACCVIOL - Data access violation, bit[1] */
#define ARM_V8M_MMFSR_DACCVIOL_Pos      1U
#define ARM_V8M_MMFSR_DACCVIOL_Msk      (1UL << ARM_V8M_MMFSR_DACCVIOL_Pos)
/* MUNSTKERR - MemManage on unstacking, bit[3] */
#define ARM_V8M_MMFSR_MUNSTKERR_Pos     3U
#define ARM_V8M_MMFSR_MUNSTKERR_Msk     (1UL << ARM_V8M_MMFSR_MUNSTKERR_Pos)
/* MSTKERR - MemManage on stacking, bit[4] */
#define ARM_V8M_MMFSR_MSTKERR_Pos       4U
#define ARM_V8M_MMFSR_MSTKERR_Msk       (1UL << ARM_V8M_MMFSR_MSTKERR_Pos)
/* MLSPERR - MemManage during lazy FP, bit[5] */
#define ARM_V8M_MMFSR_MLSPERR_Pos       5U
#define ARM_V8M_MMFSR_MLSPERR_Msk       (1UL << ARM_V8M_MMFSR_MLSPERR_Pos)
/* MMARVALID - MMFAR valid, bit[7] */
#define ARM_V8M_MMFSR_MMARVALID_Pos     7U
#define ARM_V8M_MMFSR_MMARVALID_Msk     (1UL << ARM_V8M_MMFSR_MMARVALID_Pos)

/* BFSR - BusFault Status Register, bits[15:8] */
/* IBUSERR - Instruction bus error, bit[0] */
#define ARM_V8M_BFSR_IBUSERR_Pos        8U
#define ARM_V8M_BFSR_IBUSERR_Msk        (1UL << ARM_V8M_BFSR_IBUSERR_Pos)
/* PRECISERR - Precise data bus error, bit[1] */
#define ARM_V8M_BFSR_PRECISERR_Pos      9U
#define ARM_V8M_BFSR_PRECISERR_Msk      (1UL << ARM_V8M_BFSR_PRECISERR_Pos)
/* IMPRECISERR - Imprecise data bus error, bit[2] */
#define ARM_V8M_BFSR_IMPRECISERR_Pos    10U
#define ARM_V8M_BFSR_IMPRECISERR_Msk    (1UL << ARM_V8M_BFSR_IMPRECISERR_Pos)
/* UNSTKERR - BusFault on unstacking, bit[3] */
#define ARM_V8M_BFSR_UNSTKERR_Pos       11U
#define ARM_V8M_BFSR_UNSTKERR_Msk       (1UL << ARM_V8M_BFSR_UNSTKERR_Pos)
/* STKERR - BusFault on stacking, bit[4] */
#define ARM_V8M_BFSR_STKERR_Pos         12U
#define ARM_V8M_BFSR_STKERR_Msk         (1UL << ARM_V8M_BFSR_STKERR_Pos)
/* LSPERR - BusFault during lazy FP, bit[5] */
#define ARM_V8M_BFSR_LSPERR_Pos         13U
#define ARM_V8M_BFSR_LSPERR_Msk         (1UL << ARM_V8M_BFSR_LSPERR_Pos)
/* BFARVALID - BFAR valid, bit[7] */
#define ARM_V8M_BFSR_BFARVALID_Pos      15U
#define ARM_V8M_BFSR_BFARVALID_Msk      (1UL << ARM_V8M_BFSR_BFARVALID_Pos)

/* UFSR - UsageFault Status Register, bits[31:16] */
/* UNDEFINSTR - Undefined instruction, bit[0] */
#define ARM_V8M_UFSR_UNDEFINSTR_Pos     16U
#define ARM_V8M_UFSR_UNDEFINSTR_Msk     (1UL << ARM_V8M_UFSR_UNDEFINSTR_Pos)
/* INVSTATE - Invalid state, bit[1] */
#define ARM_V8M_UFSR_INVSTATE_Pos       17U
#define ARM_V8M_UFSR_INVSTATE_Msk       (1UL << ARM_V8M_UFSR_INVSTATE_Pos)
/* INVPC - Invalid PC load, bit[2] */
#define ARM_V8M_UFSR_INVPC_Pos          18U
#define ARM_V8M_UFSR_INVPC_Msk          (1UL << ARM_V8M_UFSR_INVPC_Pos)
/* NOCP - No coprocessor, bit[3] */
#define ARM_V8M_UFSR_NOCP_Pos           19U
#define ARM_V8M_UFSR_NOCP_Msk           (1UL << ARM_V8M_UFSR_NOCP_Pos)
/* STKOF - Stack overflow, bit[4]
   【v8m 独有】 */
#define ARM_V8M_UFSR_STKOF_Pos          20U
#define ARM_V8M_UFSR_STKOF_Msk          (1UL << ARM_V8M_UFSR_STKOF_Pos)
/* UNALIGNED - Unaligned access, bit[8] */
#define ARM_V8M_UFSR_UNALIGNED_Pos      24U
#define ARM_V8M_UFSR_UNALIGNED_Msk      (1UL << ARM_V8M_UFSR_UNALIGNED_Pos)
/* DIVBYZERO - Divide by zero, bit[9] */
#define ARM_V8M_UFSR_DIVBYZERO_Pos      25U
#define ARM_V8M_UFSR_DIVBYZERO_Msk      (1UL << ARM_V8M_UFSR_DIVBYZERO_Pos)

/* -----------------------------------------------------------------------------
 * 2.12 HFSR 寄存器位域 (ARM_V8M_SCB_HFSR)
 * 参考: D1.2.107 HFSR, HardFault Status Register
 * -----------------------------------------------------------------------------
 */
/* VECTTBL - Vector table HardFault, bit[1] */
#define ARM_V8M_HFSR_VECTTBL_Pos        1U
#define ARM_V8M_HFSR_VECTTBL_Msk        (1UL << ARM_V8M_HFSR_VECTTBL_Pos)
/* FORCED - Forced HardFault, bit[30] */
#define ARM_V8M_HFSR_FORCED_Pos         30U
#define ARM_V8M_HFSR_FORCED_Msk         (1UL << ARM_V8M_HFSR_FORCED_Pos)
/* DEBUGEVT - Debug event HardFault, bit[31] */
#define ARM_V8M_HFSR_DEBUGEVT_Pos       31U
#define ARM_V8M_HFSR_DEBUGEVT_Msk       (1UL << ARM_V8M_HFSR_DEBUGEVT_Pos)

/* -----------------------------------------------------------------------------
 * 2.12.1 MMFAR 寄存器位域 (ARM_V8M_SCB_MMFAR)
 * 参考: D1.2.166 MMFAR, MemManage Fault Address Register
 * -----------------------------------------------------------------------------
 */
/* ADDRESS - MemManage fault address, bits[31:0]
   MemManage故障地址，仅当 MMFSR.MMFARVALID 置位时有效 */
#define ARM_V8M_MMFAR_ADDRESS_Pos       0U
#define ARM_V8M_MMFAR_ADDRESS_Msk       (0xFFFFFFFFUL << ARM_V8M_MMFAR_ADDRESS_Pos)

/* -----------------------------------------------------------------------------
 * 2.12.2 BFAR 寄存器位域 (ARM_V8M_SCB_BFAR)
 * 参考: D1.2.6 BFAR, BusFault Address Register
 * -----------------------------------------------------------------------------
 */
/* ADDRESS - BusFault address, bits[31:0]
   BusFault地址，仅当 BFSR.BFARVALID 置位时有效 */
#define ARM_V8M_BFAR_ADDRESS_Pos        0U
#define ARM_V8M_BFAR_ADDRESS_Msk        (0xFFFFFFFFUL << ARM_V8M_BFAR_ADDRESS_Pos)

/* -----------------------------------------------------------------------------
 * 2.13 DFSR 寄存器位域 (ARM_V8M_SCB_DFSR)
 * 参考: D1.2.52 DFSR, Debug Fault Status Register
 * -----------------------------------------------------------------------------
 */
/* HALTED - Halt request debug event, bit[0] */
#define ARM_V8M_DFSR_HALTED_Pos         0U
#define ARM_V8M_DFSR_HALTED_Msk         (1UL << ARM_V8M_DFSR_HALTED_Pos)
/* BKPT - Breakpoint debug event, bit[1] */
#define ARM_V8M_DFSR_BKPT_Pos           1U
#define ARM_V8M_DFSR_BKPT_Msk           (1UL << ARM_V8M_DFSR_BKPT_Pos)
/* DWTTRAP - DWT debug event, bit[2] */
#define ARM_V8M_DFSR_DWTTRAP_Pos        2U
#define ARM_V8M_DFSR_DWTTRAP_Msk        (1UL << ARM_V8M_DFSR_DWTTRAP_Pos)
/* VCATCH - Vector catch debug event, bit[3] */
#define ARM_V8M_DFSR_VCATCH_Pos         3U
#define ARM_V8M_DFSR_VCATCH_Msk         (1UL << ARM_V8M_DFSR_VCATCH_Pos)
/* EXTERNAL - External debug request, bit[4] */
#define ARM_V8M_DFSR_EXTERNAL_Pos       4U
#define ARM_V8M_DFSR_EXTERNAL_Msk       (1UL << ARM_V8M_DFSR_EXTERNAL_Pos)

/* -----------------------------------------------------------------------------
 * 2.14 CPACR 寄存器位域 (ARM_V8M_SCB_CPACR)
 * 参考: D1.2.26 CPACR, Coprocessor Access Control Register
 * -----------------------------------------------------------------------------
 */
/* CP10 - Coprocessor 10 access, bits[21:20]
   0b00=拒绝访问, 0b01=特权访问, 0b10=保留, 0b11=完全访问 */
#define ARM_V8M_CPACR_CP10_Pos          20U
#define ARM_V8M_CPACR_CP10_Msk          (0x3UL << ARM_V8M_CPACR_CP10_Pos)
/* CP11 - Coprocessor 11 access, bits[23:22]
   必须与CP10相同 */
#define ARM_V8M_CPACR_CP11_Pos          22U
#define ARM_V8M_CPACR_CP11_Msk          (0x3UL << ARM_V8M_CPACR_CP11_Pos)

/* -----------------------------------------------------------------------------
 * 2.15 NSACR 寄存器位域 (ARM_V8M_SCB_NSACR)
 * 参考: D1.2.181 NSACR, Non-secure Access Control Register
 * 【v8m 独有】
 * -----------------------------------------------------------------------------
 */
/* CP10 - Non-secure coprocessor 10 access, bit[10]
   1=允许Non-secure访问CP10 */
#define ARM_V8M_NSACR_CP10_Pos          10U
#define ARM_V8M_NSACR_CP10_Msk          (1UL << ARM_V8M_NSACR_CP10_Pos)
/* CP11 - Non-secure coprocessor 11 access, bit[11]
   1=允许Non-secure访问CP11 */
#define ARM_V8M_NSACR_CP11_Pos          11U
#define ARM_V8M_NSACR_CP11_Msk          (1UL << ARM_V8M_NSACR_CP11_Pos)

/* -----------------------------------------------------------------------------
 * 2.16 SFSR 寄存器位域 (ARM_V8M_SCB_SFSR)
 * 参考: D1.2.210 SFSR, Secure Fault Status Register
 * 【v8m 独有】
 * -----------------------------------------------------------------------------
 */
/* INVEP - Invalid entry point, bit[0] */
#define ARM_V8M_SFSR_INVEP_Pos          0U
#define ARM_V8M_SFSR_INVEP_Msk          (1UL << ARM_V8M_SFSR_INVEP_Pos)
/* INVIS - Invalid integrity signature, bit[1] */
#define ARM_V8M_SFSR_INVIS_Pos          1U
#define ARM_V8M_SFSR_INVIS_Msk          (1UL << ARM_V8M_SFSR_INVIS_Pos)
/* INVER - Invalid exception return, bit[2] */
#define ARM_V8M_SFSR_INVER_Pos          2U
#define ARM_V8M_SFSR_INVER_Msk          (1UL << ARM_V8M_SFSR_INVER_Pos)
/* AUVIOL - Attribution unit violation, bit[3] */
#define ARM_V8M_SFSR_AUVIOL_Pos         3U
#define ARM_V8M_SFSR_AUVIOL_Msk         (1UL << ARM_V8M_SFSR_AUVIOL_Pos)
/* INVTRAN - Invalid transition, bit[4] */
#define ARM_V8M_SFSR_INVTRAN_Pos        4U
#define ARM_V8M_SFSR_INVTRAN_Msk        (1UL << ARM_V8M_SFSR_INVTRAN_Pos)
/* LSPERR - Lazy state preservation error, bit[5] */
#define ARM_V8M_SFSR_LSPERR_Pos         5U
#define ARM_V8M_SFSR_LSPERR_Msk         (1UL << ARM_V8M_SFSR_LSPERR_Pos)
/* SFARVALID - SFAR valid, bit[6] */
#define ARM_V8M_SFSR_SFARVALID_Pos      6U
#define ARM_V8M_SFSR_SFARVALID_Msk      (1UL << ARM_V8M_SFSR_SFARVALID_Pos)
/* LSERR - Lazy state error, bit[7] */
#define ARM_V8M_SFSR_LSERR_Pos          7U
#define ARM_V8M_SFSR_LSERR_Msk          (1UL << ARM_V8M_SFSR_LSERR_Pos)

/* -----------------------------------------------------------------------------
 * 2.17 SFAR 寄存器位域 (ARM_V8M_SCB_SFAR)
 * 参考: D1.2.231 SFAR, Secure Fault Address Register
 * 【v8m 独有】
 * -----------------------------------------------------------------------------
 */
/* ADDRESS - Secure fault address, bits[31:0]
   安全故障地址，仅当 SFSR.SFARVALID 置位时有效 */
#define ARM_V8M_SFAR_ADDRESS_Pos        0U
#define ARM_V8M_SFAR_ADDRESS_Msk        (0xFFFFFFFFUL << ARM_V8M_SFAR_ADDRESS_Pos)

/* ==============================================================================
 * 三、MPU 寄存器位域
 * 地址范围: 0xE000ED90 - 0xE000EDBF (Secure), 0xE002ED90 - 0xE002EDBF (Non-secure 别名)
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 3.1 MPU_TYPE 寄存器位域 (ARM_V8M_MPU_TYPE)
 * 参考: D1.2.175 MPU_TYPE, MPU Type Register
 * -----------------------------------------------------------------------------
 */
/* SEPARATE - Separate or unified MPU, bit[0]
   0=统一MPU */
#define ARM_V8M_MPU_TYPE_SEPARATE_Pos   0U
#define ARM_V8M_MPU_TYPE_SEPARATE_Msk   (1UL << ARM_V8M_MPU_TYPE_SEPARATE_Pos)
/* DREGION - Number of data regions, bits[15:8]
   数据区域数量 */
#define ARM_V8M_MPU_TYPE_DREGION_Pos    8U
#define ARM_V8M_MPU_TYPE_DREGION_Msk    (0xFFUL << ARM_V8M_MPU_TYPE_DREGION_Pos)

/* -----------------------------------------------------------------------------
 * 3.2 MPU_CTRL 寄存器位域 (ARM_V8M_MPU_CTRL)
 * 参考: D1.2.174 MPU_CTRL, MPU Control Register
 * -----------------------------------------------------------------------------
 */
/* ENABLE - MPU enable, bit[0]
   1=使能MPU */
#define ARM_V8M_MPU_CTRL_ENABLE_Pos     0U
#define ARM_V8M_MPU_CTRL_ENABLE_Msk     (1UL << ARM_V8M_MPU_CTRL_ENABLE_Pos)
/* HFNMIENA - MPU enable for HardFault/NMI, bit[1]
   1=HardFault和NMI处理程序使用MPU */
#define ARM_V8M_MPU_CTRL_HFNMIENA_Pos   1U
#define ARM_V8M_MPU_CTRL_HFNMIENA_Msk   (1UL << ARM_V8M_MPU_CTRL_HFNMIENA_Pos)
/* PRIVDEFENA - Privileged default enable, bit[2]
   1=启用默认内存映射作为背景区域 */
#define ARM_V8M_MPU_CTRL_PRIVDEFENA_Pos 2U
#define ARM_V8M_MPU_CTRL_PRIVDEFENA_Msk (1UL << ARM_V8M_MPU_CTRL_PRIVDEFENA_Pos)

/* -----------------------------------------------------------------------------
 * 3.3 MPU_RNR 寄存器位域 (ARM_V8M_MPU_RNR)
 * 参考: D1.2.172 MPU_RNR, MPU Region Number Register
 * -----------------------------------------------------------------------------
 */
/* REGION - Region number, bits[7:0]
   选择当前配置的MPU区域 */
#define ARM_V8M_MPU_RNR_REGION_Pos      0U
#define ARM_V8M_MPU_RNR_REGION_Msk      (0xFFUL << ARM_V8M_MPU_RNR_REGION_Pos)

/* -----------------------------------------------------------------------------
 * 3.4 MPU_RBAR 寄存器位域 (ARM_V8M_MPU_RBAR)
 * 参考: D1.2.171 MPU_RBAR, MPU Region Base Address Register
 * -----------------------------------------------------------------------------
 */
/* XN - Execute never, bit[0]
   1=禁止执行 */
#define ARM_V8M_MPU_RBAR_XN_Pos         0U
#define ARM_V8M_MPU_RBAR_XN_Msk         (1UL << ARM_V8M_MPU_RBAR_XN_Pos)
/* AP - Access permissions, bits[2:1]
   访问权限: 0b00=特权RW, 0b01=RW, 0b10=特权RO, 0b11=RO */
#define ARM_V8M_MPU_RBAR_AP_Pos         1U
#define ARM_V8M_MPU_RBAR_AP_Msk         (0x3UL << ARM_V8M_MPU_RBAR_AP_Pos)
/* SH - Shareability, bits[4:3]
   共享属性: 0b00=Non-shareable, 0b01=保留, 0b10=Outer, 0b11=Inner */
#define ARM_V8M_MPU_RBAR_SH_Pos         3U
#define ARM_V8M_MPU_RBAR_SH_Msk         (0x3UL << ARM_V8M_MPU_RBAR_SH_Pos)
/* BASE - Region base address, bits[31:5]
   区域基地址，32字节对齐 */
#define ARM_V8M_MPU_RBAR_BASE_Pos       5U
#define ARM_V8M_MPU_RBAR_BASE_Msk       (0x7FFFFFFUL << ARM_V8M_MPU_RBAR_BASE_Pos)

/* -----------------------------------------------------------------------------
 * 3.5 MPU_RLAR 寄存器位域 (ARM_V8M_MPU_RLAR)
 * 参考: D1.2.173 MPU_RLAR, MPU Region Limit Address Register
 * 【v8m 独有】v7m 中使用 MPU_RASR
 * -----------------------------------------------------------------------------
 */
/* EN - Region enable, bit[0]
   1=使能区域 */
#define ARM_V8M_MPU_RLAR_EN_Pos         0U
#define ARM_V8M_MPU_RLAR_EN_Msk         (1UL << ARM_V8M_MPU_RLAR_EN_Pos)
/* ATTRINDX - Attribute index, bits[2:1]
   选择MAIR中的属性: 0-3 */
#define ARM_V8M_MPU_RLAR_ATTRINDX_Pos   1U
#define ARM_V8M_MPU_RLAR_ATTRINDX_Msk   (0x3UL << ARM_V8M_MPU_RLAR_ATTRINDX_Pos)
/* LIMIT - Region limit address, bits[31:5]
   区域限制地址，32字节对齐 */
#define ARM_V8M_MPU_RLAR_LIMIT_Pos      5U
#define ARM_V8M_MPU_RLAR_LIMIT_Msk      (0x7FFFFFFUL << ARM_V8M_MPU_RLAR_LIMIT_Pos)

/* -----------------------------------------------------------------------------
 * 3.6 MPU_MAIR 寄存器位域 (ARM_V8M_MPU_MAIR0/MAIR1)
 * 参考: D1.2.169 MPU_MAIR0, D1.2.170 MPU_MAIR1
 * 【v8m 独有】
 * -----------------------------------------------------------------------------
 */
/* Attr0 - Attribute 0, bits[7:0] */
#define ARM_V8M_MPU_MAIR0_ATTR0_Pos     0U
#define ARM_V8M_MPU_MAIR0_ATTR0_Msk     (0xFFUL << ARM_V8M_MPU_MAIR0_ATTR0_Pos)
/* Attr1 - Attribute 1, bits[15:8] */
#define ARM_V8M_MPU_MAIR0_ATTR1_Pos     8U
#define ARM_V8M_MPU_MAIR0_ATTR1_Msk     (0xFFUL << ARM_V8M_MPU_MAIR0_ATTR1_Pos)
/* Attr2 - Attribute 2, bits[23:16] */
#define ARM_V8M_MPU_MAIR0_ATTR2_Pos     16U
#define ARM_V8M_MPU_MAIR0_ATTR2_Msk     (0xFFUL << ARM_V8M_MPU_MAIR0_ATTR2_Pos)
/* Attr3 - Attribute 3, bits[31:24] */
#define ARM_V8M_MPU_MAIR0_ATTR3_Pos     24U
#define ARM_V8M_MPU_MAIR0_ATTR3_Msk     (0xFFUL << ARM_V8M_MPU_MAIR0_ATTR3_Pos)

/* Attr4 - Attribute 4, bits[7:0] */
#define ARM_V8M_MPU_MAIR1_ATTR4_Pos     0U
#define ARM_V8M_MPU_MAIR1_ATTR4_Msk     (0xFFUL << ARM_V8M_MPU_MAIR1_ATTR4_Pos)
/* Attr5 - Attribute 5, bits[15:8] */
#define ARM_V8M_MPU_MAIR1_ATTR5_Pos     8U
#define ARM_V8M_MPU_MAIR1_ATTR5_Msk     (0xFFUL << ARM_V8M_MPU_MAIR1_ATTR5_Pos)
/* Attr6 - Attribute 6, bits[23:16] */
#define ARM_V8M_MPU_MAIR1_ATTR6_Pos     16U
#define ARM_V8M_MPU_MAIR1_ATTR6_Msk     (0xFFUL << ARM_V8M_MPU_MAIR1_ATTR6_Pos)
/* Attr7 - Attribute 7, bits[31:24] */
#define ARM_V8M_MPU_MAIR1_ATTR7_Pos     24U
#define ARM_V8M_MPU_MAIR1_ATTR7_Msk     (0xFFUL << ARM_V8M_MPU_MAIR1_ATTR7_Pos)

/* ==============================================================================
 * 四、SAU 寄存器位域
 * 地址范围: 0xE000EDD0 - 0xE000EDDC
 * 【v8m 独有】v7m 中不存在 Security Extension
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 4.1 SAU_CTRL 寄存器位域 (ARM_V8M_SAU_CTRL)
 * 参考: D1.2.202 SAU_CTRL, SAU Control Register
 * -----------------------------------------------------------------------------
 */
/* ENABLE - SAU enable, bit[0]
   1=使能SAU */
#define ARM_V8M_SAU_CTRL_ENABLE_Pos     0U
#define ARM_V8M_SAU_CTRL_ENABLE_Msk     (1UL << ARM_V8M_SAU_CTRL_ENABLE_Pos)
/* ALLNS - All Non-secure, bit[1]
   1=所有内存区域都是Non-secure */
#define ARM_V8M_SAU_CTRL_ALLNS_Pos      1U
#define ARM_V8M_SAU_CTRL_ALLNS_Msk      (1UL << ARM_V8M_SAU_CTRL_ALLNS_Pos)

/* -----------------------------------------------------------------------------
 * 4.2 SAU_TYPE 寄存器位域 (ARM_V8M_SAU_TYPE)
 * 参考: D1.2.206 SAU_TYPE, SAU Type Register
 * -----------------------------------------------------------------------------
 */
/* SREGION - Number of SAU regions, bits[7:0]
   SAU区域数量 */
#define ARM_V8M_SAU_TYPE_SREGION_Pos    0U
#define ARM_V8M_SAU_TYPE_SREGION_Msk    (0xFFUL << ARM_V8M_SAU_TYPE_SREGION_Pos)

/* -----------------------------------------------------------------------------
 * 4.3 SAU_RNR 寄存器位域 (ARM_V8M_SAU_RNR)
 * 参考: D1.2.204 SAU_RNR, SAU Region Number Register
 * -----------------------------------------------------------------------------
 */
/* REGION - SAU region number, bits[7:0]
   选择当前配置的SAU区域 */
#define ARM_V8M_SAU_RNR_REGION_Pos      0U
#define ARM_V8M_SAU_RNR_REGION_Msk      (0xFFUL << ARM_V8M_SAU_RNR_REGION_Pos)

/* -----------------------------------------------------------------------------
 * 4.4 SAU_RBAR 寄存器位域 (ARM_V8M_SAU_RBAR)
 * 参考: D1.2.203 SAU_RBAR, SAU Region Base Address Register
 * -----------------------------------------------------------------------------
 */
/* BASE - Region base address, bits[31:5]
   区域基地址，32字节对齐 */
#define ARM_V8M_SAU_RBAR_BASE_Pos       5U
#define ARM_V8M_SAU_RBAR_BASE_Msk       (0x7FFFFFFUL << ARM_V8M_SAU_RBAR_BASE_Pos)

/* -----------------------------------------------------------------------------
 * 4.5 SAU_RLAR 寄存器位域 (ARM_V8M_SAU_RLAR)
 * 参考: D1.2.205 SAU_RLAR, SAU Region Limit Address Register
 * -----------------------------------------------------------------------------
 */
/* EN - Region enable, bit[0]
   1=使能区域 */
#define ARM_V8M_SAU_RLAR_EN_Pos         0U
#define ARM_V8M_SAU_RLAR_EN_Msk         (1UL << ARM_V8M_SAU_RLAR_EN_Pos)
/* NSC - Non-secure callable, bit[1]
   1=区域包含SG指令 */
#define ARM_V8M_SAU_RLAR_NSC_Pos        1U
#define ARM_V8M_SAU_RLAR_NSC_Msk        (1UL << ARM_V8M_SAU_RLAR_NSC_Pos)
/* LIMIT - Region limit address, bits[31:5]
   区域限制地址，32字节对齐 */
#define ARM_V8M_SAU_RLAR_LIMIT_Pos      5U
#define ARM_V8M_SAU_RLAR_LIMIT_Msk      (0x7FFFFFFUL << ARM_V8M_SAU_RLAR_LIMIT_Pos)

/* ==============================================================================
 * 五、SysTick 寄存器位域
 * 地址范围: 0xE000E010 - 0xE000E01F (Secure), 0xE002E010 - 0xE002E01F (Non-secure 别名)
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 5.1 SYST_CSR 寄存器位域 (ARM_V8M_SYST_CSR)
 * 参考: D1.2.236 SYST_CSR, SysTick Control and Status Register
 * -----------------------------------------------------------------------------
 */
/* ENABLE - Counter enable, bit[0]
   1=使能计数器 */
#define ARM_V8M_SYST_CSR_ENABLE_Pos     0U
#define ARM_V8M_SYST_CSR_ENABLE_Msk     (1UL << ARM_V8M_SYST_CSR_ENABLE_Pos)
/* TICKINT - Tick interrupt enable, bit[1]
   1=计数到0时产生中断 */
#define ARM_V8M_SYST_CSR_TICKINT_Pos    1U
#define ARM_V8M_SYST_CSR_TICKINT_Msk    (1UL << ARM_V8M_SYST_CSR_TICKINT_Pos)
/* CLKSOURCE - Clock source, bit[2]
   0=外部参考时钟, 1=处理器时钟 */
#define ARM_V8M_SYST_CSR_CLKSOURCE_Pos  2U
#define ARM_V8M_SYST_CSR_CLKSOURCE_Msk  (1UL << ARM_V8M_SYST_CSR_CLKSOURCE_Pos)
/* COUNTFLAG - Count flag, bit[16]
   1=计数器已计数到0 */
#define ARM_V8M_SYST_CSR_COUNTFLAG_Pos  16U
#define ARM_V8M_SYST_CSR_COUNTFLAG_Msk  (1UL << ARM_V8M_SYST_CSR_COUNTFLAG_Pos)

/* -----------------------------------------------------------------------------
 * 5.2 SYST_RVR 寄存器位域 (ARM_V8M_SYST_RVR)
 * 参考: D1.2.237 SYST_RVR, SysTick Reload Value Register
 * -----------------------------------------------------------------------------
 */
/* RELOAD - Value to load into the SYST_CVR register when the counter reaches 0, bits[23:0]
   计数器重载值: 当计数器计数到0时加载到SYST_CVR的值 */
#define ARM_V8M_SYST_RVR_RELOAD_Pos     0U
#define ARM_V8M_SYST_RVR_RELOAD_Msk     (0xFFFFFFUL << ARM_V8M_SYST_RVR_RELOAD_Pos)

/* -----------------------------------------------------------------------------
 * 5.3 SYST_CVR 寄存器位域 (ARM_V8M_SYST_CVR)
 * 参考: D1.2.234 SYST_CVR, SysTick Current Value Register
 * -----------------------------------------------------------------------------
 */
/* CURRENT - Current counter value, bits[23:0]
   当前计数值 */
#define ARM_V8M_SYST_CVR_CURRENT_Pos    0U
#define ARM_V8M_SYST_CVR_CURRENT_Msk    (0xFFFFFFUL << ARM_V8M_SYST_CVR_CURRENT_Pos)

/* -----------------------------------------------------------------------------
 * 5.4 SYST_CALIB 寄存器位域 (ARM_V8M_SYST_CALIB)
 * 参考: D1.2.235 SYST_CALIB, SysTick Calibration Value Register
 * -----------------------------------------------------------------------------
 */
/* TENMS - Calibration value, bits[23:0]
   10ms计数值 */
#define ARM_V8M_SYST_CALIB_TENMS_Pos    0U
#define ARM_V8M_SYST_CALIB_TENMS_Msk    (0xFFFFFFUL << ARM_V8M_SYST_CALIB_TENMS_Pos)
/* SKEW - Skew flag, bit[30]
   1=校准值不精确 */
#define ARM_V8M_SYST_CALIB_SKEW_Pos     30U
#define ARM_V8M_SYST_CALIB_SKEW_Msk     (1UL << ARM_V8M_SYST_CALIB_SKEW_Pos)
/* NOREF - No reference flag, bit[31]
   1=没有外部参考时钟 */
#define ARM_V8M_SYST_CALIB_NOREF_Pos    31U
#define ARM_V8M_SYST_CALIB_NOREF_Msk    (1UL << ARM_V8M_SYST_CALIB_NOREF_Pos)

/* ==============================================================================
 * 六、NVIC 寄存器位域
 * 地址范围: 0xE000E100 - 0xE000E4EF (Secure), 0xE002E100 - 0xE002E4EF (Non-secure 别名)
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 6.1 NVIC_IPR 寄存器位域 (ARM_V8M_NVIC_IPR)
 * 参考: D1.2.157 NVIC_IPR0-NVIC_IPR123, Interrupt Priority Registers 0-123
 * -----------------------------------------------------------------------------
 */
/* PRI_N3 - Priority of interrupt 4n+3, bits[31:24]
   中断4n+3的优先级 */
#define ARM_V8M_NVIC_IPR_PRI_N3_Pos     31U
#define ARM_V8M_NVIC_IPR_PRI_N3_Msk     (0xFFUL << ARM_V8M_NVIC_IPR_PRI_N3_Pos)
/* PRI_N2 - Priority of interrupt 4n+2, bits[23:16]
   中断4n+2的优先级 */
#define ARM_V8M_NVIC_IPR_PRI_N2_Pos     23U
#define ARM_V8M_NVIC_IPR_PRI_N2_Msk     (0xFFUL << ARM_V8M_NVIC_IPR_PRI_N2_Pos)
/* PRI_N1 - Priority of interrupt 4n+1, bits[15:8]
   中断4n+1的优先级 */
#define ARM_V8M_NVIC_IPR_PRI_N1_Pos     15U
#define ARM_V8M_NVIC_IPR_PRI_N1_Msk     (0xFFUL << ARM_V8M_NVIC_IPR_PRI_N1_Pos)
/* PRI_N0 - Priority of interrupt 4n, bits[7:0]
   中断4n的优先级 */
#define ARM_V8M_NVIC_IPR_PRI_N0_Pos     7U
#define ARM_V8M_NVIC_IPR_PRI_N0_Msk     (0xFFUL << ARM_V8M_NVIC_IPR_PRI_N0_Pos)

/* -----------------------------------------------------------------------------
 * 6.2 NVIC_ISER 寄存器位域 (ARM_V8M_NVIC_ISER)
 * 参考: D1.2.160 NVIC_ISER0-NVIC_ISER7, Interrupt Set-Enable Registers 0-7
 * -----------------------------------------------------------------------------
 */
/* SETENA - Interrupt set-enable, bits[31:0]
   写1使能对应中断，读返回当前使能状态 */
#define ARM_V8M_NVIC_ISER_SETENA_Pos    0U
#define ARM_V8M_NVIC_ISER_SETENA_Msk    (0xFFFFFFFFUL << ARM_V8M_NVIC_ISER_SETENA_Pos)

/* -----------------------------------------------------------------------------
 * 6.3 NVIC_ICER 寄存器位域 (ARM_V8M_NVIC_ICER)
 * 参考: D1.2.154 NVIC_ICER0-NVIC_ICER7, Interrupt Clear-Enable Registers 0-7
 * -----------------------------------------------------------------------------
 */
/* CLRENA - Interrupt clear-enable, bits[31:0]
   写1禁用对应中断，读返回当前使能状态 */
#define ARM_V8M_NVIC_ICER_CLRENA_Pos    0U
#define ARM_V8M_NVIC_ICER_CLRENA_Msk    (0xFFFFFFFFUL << ARM_V8M_NVIC_ICER_CLRENA_Pos)

/* -----------------------------------------------------------------------------
 * 6.4 NVIC_ISPR 寄存器位域 (ARM_V8M_NVIC_ISPR)
 * 参考: D1.2.159 NVIC_ISPR0-NVIC_ISPR7, Interrupt Set-Pending Registers 0-7
 * -----------------------------------------------------------------------------
 */
/* SETPEND - Interrupt set-pending, bits[31:0]
   写1设置对应中断为待处理，读返回当前待处理状态 */
#define ARM_V8M_NVIC_ISPR_SETPEND_Pos   0U
#define ARM_V8M_NVIC_ISPR_SETPEND_Msk   (0xFFFFFFFFUL << ARM_V8M_NVIC_ISPR_SETPEND_Pos)

/* -----------------------------------------------------------------------------
 * 6.5 NVIC_ICPR 寄存器位域 (ARM_V8M_NVIC_ICPR)
 * 参考: D1.2.153 NVIC_ICPR0-NVIC_ICPR7, Interrupt Clear-Pending Registers 0-7
 * -----------------------------------------------------------------------------
 */
/* CLRPEND - Interrupt clear-pending, bits[31:0]
   写1清除对应中断的待处理状态，读返回当前待处理状态 */
#define ARM_V8M_NVIC_ICPR_CLRPEND_Pos   0U
#define ARM_V8M_NVIC_ICPR_CLRPEND_Msk   (0xFFFFFFFFUL << ARM_V8M_NVIC_ICPR_CLRPEND_Pos)

/* -----------------------------------------------------------------------------
 * 6.6 NVIC_IABR 寄存器位域 (ARM_V8M_NVIC_IABR)
 * 参考: D1.2.152 NVIC_IABR0-NVIC_IABR7, Interrupt Active Bit Registers 0-7
 * -----------------------------------------------------------------------------
 */
/* ACTIVE - Interrupt active, bits[31:0]
   读返回对应中断的活动状态 */
#define ARM_V8M_NVIC_IABR_ACTIVE_Pos    0U
#define ARM_V8M_NVIC_IABR_ACTIVE_Msk    (0xFFFFFFFFUL << ARM_V8M_NVIC_IABR_ACTIVE_Pos)

/* -----------------------------------------------------------------------------
 * 6.7 NVIC_ITNS 寄存器位域 (ARM_V8M_NVIC_ITNS)
 * 参考: D1.2.156 NVIC_ITNS0-NVIC_ITNS7, Interrupt Target Non-secure Registers 0-7
 * 【v8m 独有】
 * -----------------------------------------------------------------------------
 */
/* ITNS - Interrupt target Non-secure, bits[31:0]
   每一位设置对应中断的目标安全状态: 0=Secure, 1=Non-secure */
#define ARM_V8M_NVIC_ITNS_ITNS_Pos      0U
#define ARM_V8M_NVIC_ITNS_ITNS_Msk      (0xFFFFFFFFUL << ARM_V8M_NVIC_ITNS_ITNS_Pos)

/* -----------------------------------------------------------------------------
 * 6.8 STIR 寄存器位域 (ARM_V8M_NVIC_STIR)
 * 参考: D1.2.239 STIR, Software Triggered Interrupt Register
 * -----------------------------------------------------------------------------
 */
/* INTID - Interrupt ID, bits[8:0]
   中断ID，写入的值为 (ExceptionNumber - 16) */
#define ARM_V8M_STIR_INTID_Pos          0U
#define ARM_V8M_STIR_INTID_Msk          (0x1FFUL << ARM_V8M_STIR_INTID_Pos)

/* ==============================================================================
 * 七、DCB 寄存器位域
 * 地址范围: 0xE000EDF0 - 0xE000EFFC (Secure), 0xE002EDF0 - 0xE002EFFC (Non-secure 别名)
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 7.1 DHCSR 寄存器位域 (ARM_V8M_DCB_DHCSR)
 * 参考: D1.2.47 DHCSR, Debug Halting Control and Status Register
 * -----------------------------------------------------------------------------
 */
/* C_DEBUGEN - Debug enable, bit[0]
   1=使能调试 */
#define ARM_V8M_DHCSR_C_DEBUGEN_Pos     0U
#define ARM_V8M_DHCSR_C_DEBUGEN_Msk     (1UL << ARM_V8M_DHCSR_C_DEBUGEN_Pos)
/* C_HALT - Halt, bit[1]
   1=请求暂停处理器 */
#define ARM_V8M_DHCSR_C_HALT_Pos        1U
#define ARM_V8M_DHCSR_C_HALT_Msk        (1UL << ARM_V8M_DHCSR_C_HALT_Pos)
/* C_STEP - Step, bit[2]
   1=单步执行 */
#define ARM_V8M_DHCSR_C_STEP_Pos        2U
#define ARM_V8M_DHCSR_C_STEP_Msk        (1UL << ARM_V8M_DHCSR_C_STEP_Pos)
/* C_MASKINTS - Mask interrupts, bit[3]
   1=屏蔽中断 */
#define ARM_V8M_DHCSR_C_MASKINTS_Pos    3U
#define ARM_V8M_DHCSR_C_MASKINTS_Msk    (1UL << ARM_V8M_DHCSR_C_MASKINTS_Pos)
/* C_SNAPSTALL - Snap stall, bit[5]
   1=捕获stall状态 */
#define ARM_V8M_DHCSR_C_SNAPSTALL_Pos   5U
#define ARM_V8M_DHCSR_C_SNAPSTALL_Msk   (1UL << ARM_V8M_DHCSR_C_SNAPSTALL_Pos)
/* S_REGRDY - Register ready, bit[16]
   1=寄存器读/写完成 */
#define ARM_V8M_DHCSR_S_REGRDY_Pos      16U
#define ARM_V8M_DHCSR_S_REGRDY_Msk      (1UL << ARM_V8M_DHCSR_S_REGRDY_Pos)
/* S_HALT - Halted, bit[17]
   1=处理器已暂停 */
#define ARM_V8M_DHCSR_S_HALT_Pos        17U
#define ARM_V8M_DHCSR_S_HALT_Msk        (1UL << ARM_V8M_DHCSR_S_HALT_Pos)
/* S_SLEEP - Sleeping, bit[18]
   1=处理器正在睡眠 */
#define ARM_V8M_DHCSR_S_SLEEP_Pos       18U
#define ARM_V8M_DHCSR_S_SLEEP_Msk       (1UL << ARM_V8M_DHCSR_S_SLEEP_Pos)
/* S_LOCKUP - Lockup, bit[19]
   1=处理器处于锁定状态 */
#define ARM_V8M_DHCSR_S_LOCKUP_Pos      19U
#define ARM_V8M_DHCSR_S_LOCKUP_Msk      (1UL << ARM_V8M_DHCSR_S_LOCKUP_Pos)
/* S_RETIRE_ST - Retire status, bit[24]
   1=自上次读取以来已退役指令 */
#define ARM_V8M_DHCSR_S_RETIRE_ST_Pos   24U
#define ARM_V8M_DHCSR_S_RETIRE_ST_Msk   (1UL << ARM_V8M_DHCSR_S_RETIRE_ST_Pos)
/* S_RESET_ST - Reset status, bit[25]
   1=自上次读取以来已复位 */
#define ARM_V8M_DHCSR_S_RESET_ST_Pos    25U
#define ARM_V8M_DHCSR_S_RESET_ST_Msk    (1UL << ARM_V8M_DHCSR_S_RESET_ST_Pos)
/* DBGKEY - Debug key, bits[31:16]
   写入时必须为0xA05F */
#define ARM_V8M_DHCSR_DBGKEY_Pos        16U
#define ARM_V8M_DHCSR_DBGKEY_Msk        (0xFFFFUL << ARM_V8M_DHCSR_DBGKEY_Pos)
#define ARM_V8M_DHCSR_DBGKEY_VALUE      (0xA05FUL << ARM_V8M_DHCSR_DBGKEY_Pos)

/* -----------------------------------------------------------------------------
 * 7.2 DCRSR 寄存器位域 (ARM_V8M_DCB_DCRSR)
 * 参考: D1.2.48 DCRSR, Debug Core Register Select Register
 * -----------------------------------------------------------------------------
 */
/* REGSEL - Register select, bits[6:0]
   选择要读/写的寄存器 */
#define ARM_V8M_DCRSR_REGSEL_Pos        0U
#define ARM_V8M_DCRSR_REGSEL_Msk        (0x7FUL << ARM_V8M_DCRSR_REGSEL_Pos)
/* REGWnR - Register write not read, bit[16]
   1=写操作, 0=读操作 */
#define ARM_V8M_DCRSR_REGWnR_Pos        16U
#define ARM_V8M_DCRSR_REGWnR_Msk        (1UL << ARM_V8M_DCRSR_REGWnR_Pos)

/* -----------------------------------------------------------------------------
 * 7.3 DCRDR 寄存器位域 (ARM_V8M_DCB_DCRDR)
 * 参考: D1.2.46 DCRDR, Debug Core Register Data Register
 * -----------------------------------------------------------------------------
 */
/* DBGTMP - Debug temporary data, bits[31:0]
   调试临时数据 */
#define ARM_V8M_DCRDR_DBGTMP_Pos        0U
#define ARM_V8M_DCRDR_DBGTMP_Msk        (0xFFFFFFFFUL << ARM_V8M_DCRDR_DBGTMP_Pos)

/* -----------------------------------------------------------------------------
 * 7.4 DEMCR 寄存器位域 (ARM_V8M_DCB_DEMCR)
 * 参考: D1.2.49 DEMCR, Debug Exception and Monitor Control Register
 * -----------------------------------------------------------------------------
 */
/* VC_CORERESET - Reset vector catch, bit[0]
   1=捕获复位向量 */
#define ARM_V8M_DEMCR_VC_CORERESET_Pos  0U
#define ARM_V8M_DEMCR_VC_CORERESET_Msk  (1UL << ARM_V8M_DEMCR_VC_CORERESET_Pos)
/* VC_MMERR - MemManage vector catch, bit[4]
   1=捕获MemManage异常 */
#define ARM_V8M_DEMCR_VC_MMERR_Pos      4U
#define ARM_V8M_DEMCR_VC_MMERR_Msk      (1UL << ARM_V8M_DEMCR_VC_MMERR_Pos)
/* VC_NOCPERR - No coprocessor vector catch, bit[5]
   1=捕获NoCoprocessor异常 */
#define ARM_V8M_DEMCR_VC_NOCPERR_Pos    5U
#define ARM_V8M_DEMCR_VC_NOCPERR_Msk    (1UL << ARM_V8M_DEMCR_VC_NOCPERR_Pos)
/* VC_CHKERR - Checking error vector catch, bit[6]
   1=捕获检查错误异常 */
#define ARM_V8M_DEMCR_VC_CHKERR_Pos     6U
#define ARM_V8M_DEMCR_VC_CHKERR_Msk     (1UL << ARM_V8M_DEMCR_VC_CHKERR_Pos)
/* VC_STATERR - State error vector catch, bit[7]
   1=捕获状态错误异常 */
#define ARM_V8M_DEMCR_VC_STATERR_Pos    7U
#define ARM_V8M_DEMCR_VC_STATERR_Msk    (1UL << ARM_V8M_DEMCR_VC_STATERR_Pos)
/* VC_BUSERR - BusFault vector catch, bit[8]
   1=捕获BusFault异常 */
#define ARM_V8M_DEMCR_VC_BUSERR_Pos     8U
#define ARM_V8M_DEMCR_VC_BUSERR_Msk     (1UL << ARM_V8M_DEMCR_VC_BUSERR_Pos)
/* VC_INTERR - Interrupt error vector catch, bit[9]
   1=捕获中断错误异常 */
#define ARM_V8M_DEMCR_VC_INTERR_Pos     9U
#define ARM_V8M_DEMCR_VC_INTERR_Msk     (1UL << ARM_V8M_DEMCR_VC_INTERR_Pos)
/* VC_HARDERR - HardFault vector catch, bit[10]
   1=捕获HardFault异常 */
#define ARM_V8M_DEMCR_VC_HARDERR_Pos    10U
#define ARM_V8M_DEMCR_VC_HARDERR_Msk    (1UL << ARM_V8M_DEMCR_VC_HARDERR_Pos)
/* VC_SFERR - SecureFault vector catch, bit[11]
   【v8m 独有】1=捕获SecureFault异常 */
#define ARM_V8M_DEMCR_VC_SFERR_Pos      11U
#define ARM_V8M_DEMCR_VC_SFERR_Msk      (1UL << ARM_V8M_DEMCR_VC_SFERR_Pos)
/* MON_EN - Monitor enable, bit[16]
   1=使能DebugMonitor异常 */
#define ARM_V8M_DEMCR_MON_EN_Pos        16U
#define ARM_V8M_DEMCR_MON_EN_Msk        (1UL << ARM_V8M_DEMCR_MON_EN_Pos)
/* MON_PEND - Monitor pending, bit[17]
   1=设置DebugMonitor待处理 */
#define ARM_V8M_DEMCR_MON_PEND_Pos      17U
#define ARM_V8M_DEMCR_MON_PEND_Msk      (1UL << ARM_V8M_DEMCR_MON_PEND_Pos)
/* MON_STEP - Monitor step, bit[18]
   1=单步执行 */
#define ARM_V8M_DEMCR_MON_STEP_Pos      18U
#define ARM_V8M_DEMCR_MON_STEP_Msk      (1UL << ARM_V8M_DEMCR_MON_STEP_Pos)
/* TRCENA - Trace enable, bit[24]
   1=使能DWT和ITM */
#define ARM_V8M_DEMCR_TRCENA_Pos        24U
#define ARM_V8M_DEMCR_TRCENA_Msk        (1UL << ARM_V8M_DEMCR_TRCENA_Pos)

/* -----------------------------------------------------------------------------
 * 7.5 DAUTHCTRL 寄存器位域 (ARM_V8M_DCB_DAUTHCTRL)
 * 参考: D1.2.20 DAUTHCTRL, Debug Authentication Control Register
 * 【v8m 独有】
 * -----------------------------------------------------------------------------
 */
/* SPIDENSEL - Secure invasive debug enable select, bit[0]
   选择SPIDEN信号 */
#define ARM_V8M_DAUTHCTRL_SPIDENSEL_Pos 0U
#define ARM_V8M_DAUTHCTRL_SPIDENSEL_Msk (1UL << ARM_V8M_DAUTHCTRL_SPIDENSEL_Pos)
/* SPNIDENSEL - Secure non-invasive debug enable select, bit[1]
   选择SPNIDEN信号 */
#define ARM_V8M_DAUTHCTRL_SPNIDENSEL_Pos 1U
#define ARM_V8M_DAUTHCTRL_SPNIDENSEL_Msk (1UL << ARM_V8M_DAUTHCTRL_SPNIDENSEL_Pos)

/* -----------------------------------------------------------------------------
 * 7.6 DSCSR 寄存器位域 (ARM_V8M_DCB_DSCSR)
 * 参考: D1.2.51 DSCSR, Debug Security Control and Status Register
 * 【v8m 独有】
 * -----------------------------------------------------------------------------
 */
/* CDS - Current debug state, bit[0]
   0=Non-secure, 1=Secure */
#define ARM_V8M_DSCSR_CDS_Pos           0U
#define ARM_V8M_DSCSR_CDS_Msk           (1UL << ARM_V8M_DSCSR_CDS_Pos)
/* CDSKEY - CDS write key, bit[1]
   写入CDS时必须同时写1 */
#define ARM_V8M_DSCSR_CDSKEY_Pos        1U
#define ARM_V8M_DSCSR_CDSKEY_Msk        (1UL << ARM_V8M_DSCSR_CDSKEY_Pos)
/* CDSEN - CDS enable, bit[2]
   1=允许调试器修改CDS */
#define ARM_V8M_DSCSR_CDSEN_Pos         2U
#define ARM_V8M_DSCSR_CDSEN_Msk         (1UL << ARM_V8M_DSCSR_CDSEN_Pos)

/* ==============================================================================
 * 七、DWT 寄存器位域
 * 地址范围: 0xE0001000 - 0xE0001FFF
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 7.1 DWT_CTRL 寄存器位域 (ARM_V8M_DWT_CTRL)
 * 参考: D1.2.69 DWT_CTRL, DWT Control Register
 * -----------------------------------------------------------------------------
 */
/* NUMCOMP - Number of comparators, bits[3:0]
   实现的比较器数量 */
#define ARM_V8M_DWT_CTRL_NUMCOMP_Pos    0U
#define ARM_V8M_DWT_CTRL_NUMCOMP_Msk    (0xFUL << ARM_V8M_DWT_CTRL_NUMCOMP_Pos)
/* NOTRCPKT - No trace packet, bit[27]
   1=不支持跟踪数据包 */
#define ARM_V8M_DWT_CTRL_NOTRCPKT_Pos   27U
#define ARM_V8M_DWT_CTRL_NOTRCPKT_Msk   (1UL << ARM_V8M_DWT_CTRL_NOTRCPKT_Pos)
/* NOEXTTRIG - No external trigger, bit[26]
   1=不支持外部触发 */
#define ARM_V8M_DWT_CTRL_NOEXTTRIG_Pos  26U
#define ARM_V8M_DWT_CTRL_NOEXTTRIG_Msk  (1UL << ARM_V8M_DWT_CTRL_NOEXTTRIG_Pos)
/* NOCYCCNT - No cycle counter, bit[25]
   1=不支持周期计数器 */
#define ARM_V8M_DWT_CTRL_NOCYCCNT_Pos   25U
#define ARM_V8M_DWT_CTRL_NOCYCCNT_Msk   (1UL << ARM_V8M_DWT_CTRL_NOCYCCNT_Pos)
/* NOPRFCNT - No profile counters, bit[24]
   1=不支持性能分析计数器 */
#define ARM_V8M_DWT_CTRL_NOPRFCNT_Pos   24U
#define ARM_V8M_DWT_CTRL_NOPRFCNT_Msk   (1UL << ARM_V8M_DWT_CTRL_NOPRFCNT_Pos)
/* CYCDISS - Cycle counter disabled secure, bit[23]
   【v8m 独有】1=Secure状态禁用周期计数器 */
#define ARM_V8M_DWT_CTRL_CYCDISS_Pos    23U
#define ARM_V8M_DWT_CTRL_CYCDISS_Msk    (1UL << ARM_V8M_DWT_CTRL_CYCDISS_Pos)
/* CYCEVTENA - Cycle count event enable, bit[22]
   1=使能周期计数事件 */
#define ARM_V8M_DWT_CTRL_CYCEVTENA_Pos  22U
#define ARM_V8M_DWT_CTRL_CYCEVTENA_Msk  (1UL << ARM_V8M_DWT_CTRL_CYCEVTENA_Pos)
/* FOLDEVTENA - Folded instruction event enable, bit[21]
   1=使能折叠指令事件 */
#define ARM_V8M_DWT_CTRL_FOLDEVTENA_Pos 21U
#define ARM_V8M_DWT_CTRL_FOLDEVTENA_Msk (1UL << ARM_V8M_DWT_CTRL_FOLDEVTENA_Pos)
/* LSUEVTENA - LSU event enable, bit[20]
   1=使能LSU事件 */
#define ARM_V8M_DWT_CTRL_LSUEVTENA_Pos  20U
#define ARM_V8M_DWT_CTRL_LSUEVTENA_Msk  (1UL << ARM_V8M_DWT_CTRL_LSUEVTENA_Pos)
/* SLEEPEVTENA - Sleep event enable, bit[19]
   1=使能睡眠事件 */
#define ARM_V8M_DWT_CTRL_SLEEPEVTENA_Pos 19U
#define ARM_V8M_DWT_CTRL_SLEEPEVTENA_Msk (1UL << ARM_V8M_DWT_CTRL_SLEEPEVTENA_Pos)
/* EXCEVTENA - Exception event enable, bit[18]
   1=使能异常事件 */
#define ARM_V8M_DWT_CTRL_EXCEVTENA_Pos  18U
#define ARM_V8M_DWT_CTRL_EXCEVTENA_Msk  (1UL << ARM_V8M_DWT_CTRL_EXCEVTENA_Pos)
/* CPIEVTENA - CPI event enable, bit[17]
   1=使能CPI事件 */
#define ARM_V8M_DWT_CTRL_CPIEVTENA_Pos  17U
#define ARM_V8M_DWT_CTRL_CPIEVTENA_Msk  (1UL << ARM_V8M_DWT_CTRL_CPIEVTENA_Pos)
/* EXCTRCENA - Exception trace enable, bit[16]
   1=使能异常跟踪 */
#define ARM_V8M_DWT_CTRL_EXCTRCENA_Pos  16U
#define ARM_V8M_DWT_CTRL_EXCTRCENA_Msk  (1UL << ARM_V8M_DWT_CTRL_EXCTRCENA_Pos)
/* PCSAMPLEENA - PC sample enable, bit[12]
   1=使能PC采样 */
#define ARM_V8M_DWT_CTRL_PCSAMPLEENA_Pos 12U
#define ARM_V8M_DWT_CTRL_PCSAMPLEENA_Msk (1UL << ARM_V8M_DWT_CTRL_PCSAMPLEENA_Pos)
/* SYNCTAP - Synchronization packet rate, bits[11:10]
   同步包速率: 0=禁用, 1=每2^24个周期, 2=每2^25个周期, 3=每2^26个周期 */
#define ARM_V8M_DWT_CTRL_SYNCTAP_Pos    10U
#define ARM_V8M_DWT_CTRL_SYNCTAP_Msk    (0x3UL << ARM_V8M_DWT_CTRL_SYNCTAP_Pos)
/* CYCTAP - Cycle count tap, bit[9]
   周期计数器位选择: 0=位6, 1=位10 */
#define ARM_V8M_DWT_CTRL_CYCTAP_Pos     9U
#define ARM_V8M_DWT_CTRL_CYCTAP_Msk     (1UL << ARM_V8M_DWT_CTRL_CYCTAP_Pos)
/* POSTINIT - Post init, bits[8:5]
   初始化后周期计数器值 */
#define ARM_V8M_DWT_CTRL_POSTINIT_Pos   5U
#define ARM_V8M_DWT_CTRL_POSTINIT_Msk   (0xFUL << ARM_V8M_DWT_CTRL_POSTINIT_Pos)
/* POSTPRESET - Post preset, bits[4:1]
   周期计数器预设值 */
#define ARM_V8M_DWT_CTRL_POSTPRESET_Pos 1U
#define ARM_V8M_DWT_CTRL_POSTPRESET_Msk (0xFUL << ARM_V8M_DWT_CTRL_POSTPRESET_Pos)
/* CYCCNTENA - Cycle counter enable, bit[0]
   1=使能周期计数器 */
#define ARM_V8M_DWT_CTRL_CYCCNTENA_Pos  0U
#define ARM_V8M_DWT_CTRL_CYCCNTENA_Msk  (1UL << ARM_V8M_DWT_CTRL_CYCCNTENA_Pos)

/* -----------------------------------------------------------------------------
 * 7.2 DWT_FUNCTIONn 寄存器位域 (ARM_V8M_DWT_FUNCTIONn)
 * 参考: D1.2.76 DWT_FUNCTIONn, DWT Comparator Function Register
 * -----------------------------------------------------------------------------
 */
/* FUNCTION - Comparator function, bits[3:0]
   比较器功能: 0=禁用, 1=指令地址, 2=数据地址, 3=数据地址(范围), 
   4=数据值, 5=数据值(范围), 6=数据地址+值, 7=数据地址+值(范围), 
   8=指令地址(限制), 9=数据地址(限制), 14=数据值(采样), 15=数据值(采样范围) */
#define ARM_V8M_DWT_FUNCTION_FUNCTION_Pos 0U
#define ARM_V8M_DWT_FUNCTION_FUNCTION_Msk (0xFUL << ARM_V8M_DWT_FUNCTION_FUNCTION_Pos)
/* EMITRANGE - Emit range, bit[5]
   1=发送范围数据包 */
#define ARM_V8M_DWT_FUNCTION_EMITRANGE_Pos 5U
#define ARM_V8M_DWT_FUNCTION_EMITRANGE_Msk (1UL << ARM_V8M_DWT_FUNCTION_EMITRANGE_Pos)
/* CYCMATCH - Cycle count match, bit[7]
   1=匹配周期计数器 */
#define ARM_V8M_DWT_FUNCTION_CYCMATCH_Pos 7U
#define ARM_V8M_DWT_FUNCTION_CYCMATCH_Msk (1UL << ARM_V8M_DWT_FUNCTION_CYCMATCH_Pos)
/* MATCHED - Comparator matched, bit[24]
   1=比较器已匹配 */
#define ARM_V8M_DWT_FUNCTION_MATCHED_Pos 24U
#define ARM_V8M_DWT_FUNCTION_MATCHED_Msk (1UL << ARM_V8M_DWT_FUNCTION_MATCHED_Pos)

/* ==============================================================================
 * 八、ITM 寄存器位域
 * 地址范围: 0xE0000000 - 0xE0000FFF
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 8.1 ITM_TCR 寄存器位域 (ARM_V8M_ITM_TCR)
 * 参考: D1.2.132 ITM_TCR, ITM Trace Control Register
 * -----------------------------------------------------------------------------
 */
/* ITMENA - ITM enable, bit[0]
   1=使能ITM */
#define ARM_V8M_ITM_TCR_ITMENA_Pos      0U
#define ARM_V8M_ITM_TCR_ITMENA_Msk      (1UL << ARM_V8M_ITM_TCR_ITMENA_Pos)
/* TSENA - Timestamp enable, bit[1]
   1=使能时间戳 */
#define ARM_V8M_ITM_TCR_TSENA_Pos       1U
#define ARM_V8M_ITM_TCR_TSENA_Msk       (1UL << ARM_V8M_ITM_TCR_TSENA_Pos)
/* SYNCENA - Sync enable, bit[2]
   1=使能同步包 */
#define ARM_V8M_ITM_TCR_SYNCENA_Pos     2U
#define ARM_V8M_ITM_TCR_SYNCENA_Msk     (1UL << ARM_V8M_ITM_TCR_SYNCENA_Pos)
/* TXENA - Transmit enable, bit[3]
   1=使能DWT触发 */
#define ARM_V8M_ITM_TCR_TXENA_Pos       3U
#define ARM_V8M_ITM_TCR_TXENA_Msk       (1UL << ARM_V8M_ITM_TCR_TXENA_Pos)
/* SWOENA - SWO enable, bit[4]
   1=使能SWO输出 */
#define ARM_V8M_ITM_TCR_SWOENA_Pos      4U
#define ARM_V8M_ITM_TCR_SWOENA_Msk      (1UL << ARM_V8M_ITM_TCR_SWOENA_Pos)
/* TSPRESCALE - Timestamp prescale, bits[9:8]
   时间戳预分频: 0=无, 1=/4, 2=/16, 3=/64 */
#define ARM_V8M_ITM_TCR_TSPRESCALE_Pos  8U
#define ARM_V8M_ITM_TCR_TSPRESCALE_Msk  (0x3UL << ARM_V8M_ITM_TCR_TSPRESCALE_Pos)
/* STALLENA - Stall enable, bit[12]
   1=ITM FIFO满时暂停处理器 */
#define ARM_V8M_ITM_TCR_STALLENA_Pos    12U
#define ARM_V8M_ITM_TCR_STALLENA_Msk    (1UL << ARM_V8M_ITM_TCR_STALLENA_Pos)
/* BUSY - ITM busy, bit[23]
   1=ITM正在处理数据 */
#define ARM_V8M_ITM_TCR_BUSY_Pos        23U
#define ARM_V8M_ITM_TCR_BUSY_Msk        (1UL << ARM_V8M_ITM_TCR_BUSY_Pos)
/* TraceBusID - Trace bus ID, bits[22:16]
   跟踪总线标识符 */
#define ARM_V8M_ITM_TCR_TRACEBUSID_Pos  16U
#define ARM_V8M_ITM_TCR_TRACEBUSID_Msk  (0x7FUL << ARM_V8M_ITM_TCR_TRACEBUSID_Pos)
/* GTSFREQ - Global timestamp frequency, bits[11:10]
   全局时间戳频率: 0=禁用, 1=每128字节, 2=每8KB, 3=每64KB */
#define ARM_V8M_ITM_TCR_GTSFREQ_Pos     10U
#define ARM_V8M_ITM_TCR_GTSFREQ_Msk     (0x3UL << ARM_V8M_ITM_TCR_GTSFREQ_Pos)

/* -----------------------------------------------------------------------------
 * 8.2 ITM_TPR 寄存器位域 (ARM_V8M_ITM_TPR)
 * 参考: D1.2.131 ITM_TPR, ITM Trace Privilege Register
 * -----------------------------------------------------------------------------
 */
/* PRIVMASK - Privilege mask, bits[7:0]
   每一位控制对应8个激励端口的特权访问 */
#define ARM_V8M_ITM_TPR_PRIVMASK_Pos    0U
#define ARM_V8M_ITM_TPR_PRIVMASK_Msk    (0xFFUL << ARM_V8M_ITM_TPR_PRIVMASK_Pos)

/* ==============================================================================
 * 九、FPB 寄存器位域
 * 地址范围: 0xE0002000 - 0xE0002FFF
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 9.1 FP_CTRL 寄存器位域 (ARM_V8M_FP_CTRL)
 * 参考: D1.2.91 FP_CTRL, Flash Patch Control Register
 * -----------------------------------------------------------------------------
 */
/* ENABLE - FPB enable, bit[0]
   1=使能FPB */
#define ARM_V8M_FP_CTRL_ENABLE_Pos      0U
#define ARM_V8M_FP_CTRL_ENABLE_Msk      (1UL << ARM_V8M_FP_CTRL_ENABLE_Pos)
/* KEY - FPB key, bit[1]
   写入ENABLE时必须同时写1 */
#define ARM_V8M_FP_CTRL_KEY_Pos         1U
#define ARM_V8M_FP_CTRL_KEY_Msk         (1UL << ARM_V8M_FP_CTRL_KEY_Pos)
/* NUM_CODE - Number of code comparators, bits[11:8]
   代码比较器数量 */
#define ARM_V8M_FP_CTRL_NUM_CODE_Pos    8U
#define ARM_V8M_FP_CTRL_NUM_CODE_Msk    (0xFUL << ARM_V8M_FP_CTRL_NUM_CODE_Pos)
/* NUM_CODE1 - Number of code comparators upper, bits[14:12]
   代码比较器数量高位 */
#define ARM_V8M_FP_CTRL_NUM_CODE1_Pos   12U
#define ARM_V8M_FP_CTRL_NUM_CODE1_Msk   (0x7UL << ARM_V8M_FP_CTRL_NUM_CODE1_Pos)
/* NUM_LIT - Number of literal comparators, bits[7:4]
   文字池比较器数量 */
#define ARM_V8M_FP_CTRL_NUM_LIT_Pos     4U
#define ARM_V8M_FP_CTRL_NUM_LIT_Msk     (0xFUL << ARM_V8M_FP_CTRL_NUM_LIT_Pos)

/* -----------------------------------------------------------------------------
 * 9.2 FP_REMAP 寄存器位域 (ARM_V8M_FPB_REMAP)
 * 参考: D1.2.92 FP_REMAP, Flash Patch Remap register
 * -----------------------------------------------------------------------------
 */
/* RMPSPT - Remap supported, bit[29]
   重映射支持 */
#define ARM_V8M_FPB_REMAP_RMPSPT_Pos    29U
#define ARM_V8M_FPB_REMAP_RMPSPT_Msk    (1UL << ARM_V8M_FPB_REMAP_RMPSPT_Pos)
/* REMAP - Remap, bits[28:5]
   重映射地址 */
#define ARM_V8M_FPB_REMAP_REMAP_Pos     5U
#define ARM_V8M_FPB_REMAP_REMAP_Msk     (0x00FFFFFFUL << ARM_V8M_FPB_REMAP_REMAP_Pos)

/* -----------------------------------------------------------------------------
 * 9.3 FP_COMPn 寄存器位域 (ARM_V8M_FP_COMPn)
 * 参考: D1.2.90 FP_COMPn, Flash Patch Comparator Register
 * -----------------------------------------------------------------------------
 */
/* REPLACE - Replace, bits[31:30]
   替换行为: 0=断点, 1=文字池重映射, 2=指令重映射 */
#define ARM_V8M_FP_COMP_REPLACE_Pos     30U
#define ARM_V8M_FP_COMP_REPLACE_Msk     (0x3UL << ARM_V8M_FP_COMP_REPLACE_Pos)
/* COMP - Comparator address, bits[28:2]
   比较器地址 */
#define ARM_V8M_FP_COMP_COMP_Pos        2U
#define ARM_V8M_FP_COMP_COMP_Msk        (0x7FFFFFFUL << ARM_V8M_FP_COMP_COMP_Pos)
/* BE - Breakpoint enable, bit[0]
   1=使能断点 */
#define ARM_V8M_FP_COMP_BE_Pos          0U
#define ARM_V8M_FP_COMP_BE_Msk          (1UL << ARM_V8M_FP_COMP_BE_Pos)

/* ==============================================================================
 * 十、TPIU 寄存器位域
 * 地址范围: 0xE0040000 - 0xE0040FFF
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 10.1 TPIU_SSPSR 寄存器位域 (ARM_V8M_TPIU_SSPSR)
 * 参考: D1.2.233 TPIU_SSPSR, Supported Parallel Port Sizes Register
 * -----------------------------------------------------------------------------
 */
/* SWIDTH - Supported width, bits[31:0]
   每一位表示支持的端口宽度: 位n=2^(n+1)位 */
#define ARM_V8M_TPIU_SSPSR_SWIDTH_Pos   0U
#define ARM_V8M_TPIU_SSPSR_SWIDTH_Msk   (0xFFFFFFFFUL << ARM_V8M_TPIU_SSPSR_SWIDTH_Pos)

/* -----------------------------------------------------------------------------
 * 10.2 TPIU_CSPSR 寄存器位域 (ARM_V8M_TPIU_CSPSR)
 * 参考: D1.2.227 TPIU_CSPSR, Current Parallel Port Size Register
 * -----------------------------------------------------------------------------
 */
/* CWIDTH - Current width, bits[31:0]
   当前端口宽度选择 */
#define ARM_V8M_TPIU_CSPSR_CWIDTH_Pos   0U
#define ARM_V8M_TPIU_CSPSR_CWIDTH_Msk   (0xFFFFFFFFUL << ARM_V8M_TPIU_CSPSR_CWIDTH_Pos)

/* -----------------------------------------------------------------------------
 * 10.3 TPIU_ACPR 寄存器位域 (ARM_V8M_TPIU_ACPR)
 * 参考: D1.2.225 TPIU_ACPR, Asynchronous Clock Prescaler Register
 * -----------------------------------------------------------------------------
 */
/* SWOSCALER - SWO prescaler, bits[12:0]
   SWO输出预分频值 */
#define ARM_V8M_TPIU_ACPR_SWOSCALER_Pos 0U
#define ARM_V8M_TPIU_ACPR_SWOSCALER_Msk (0x1FFFUL << ARM_V8M_TPIU_ACPR_SWOSCALER_Pos)

/* -----------------------------------------------------------------------------
 * 10.4 TPIU_SPPR 寄存器位域 (ARM_V8M_TPIU_SPPR)
 * 参考: D1.2.232 TPIU_SPPR, Selected Pin Protocol Register
 * -----------------------------------------------------------------------------
 */
/* TXMODE - Transmit mode, bits[1:0]
   传输模式: 0=并行跟踪, 1=SWO曼彻斯特, 2=SWO NRZ */
#define ARM_V8M_TPIU_SPPR_TXMODE_Pos    0U
#define ARM_V8M_TPIU_SPPR_TXMODE_Msk    (0x3UL << ARM_V8M_TPIU_SPPR_TXMODE_Pos)

/* -----------------------------------------------------------------------------
 * 10.5 TPIU_TYPE 寄存器位域 (ARM_V8M_TPIU_TYPE)
 * 参考: D1.2.234 TPIU_TYPE, TPIU Type register
 * -----------------------------------------------------------------------------
 */
/* FIFOSZ - FIFO size, bits[8:6]
   FIFO大小 */
#define ARM_V8M_TPIU_TYPE_FIFOSZ_Pos    6U
#define ARM_V8M_TPIU_TYPE_FIFOSZ_Msk    (0x7UL << ARM_V8M_TPIU_TYPE_FIFOSZ_Pos)
/* PTINVALID - Parallel trace invalid, bit[9]
   并行跟踪无效 */
#define ARM_V8M_TPIU_TYPE_PTINVALID_Pos 9U
#define ARM_V8M_TPIU_TYPE_PTINVALID_Msk (1UL << ARM_V8M_TPIU_TYPE_PTINVALID_Pos)
/* MANCVALID - Manchester valid, bit[10]
   曼彻斯特有效 */
#define ARM_V8M_TPIU_TYPE_MANCVALID_Pos 10U
#define ARM_V8M_TPIU_TYPE_MANCVALID_Msk (1UL << ARM_V8M_TPIU_TYPE_MANCVALID_Pos)
/* NRZVALID - NRZ valid, bit[11]
   NRZ有效 */
#define ARM_V8M_TPIU_TYPE_NRZVALID_Pos  11U
#define ARM_V8M_TPIU_TYPE_NRZVALID_Msk  (1UL << ARM_V8M_TPIU_TYPE_NRZVALID_Pos)

/* -----------------------------------------------------------------------------
 * 10.6 TPIU_FFCR 寄存器位域 (ARM_V8M_TPIU_FFCR)
 * 参考: D1.2.229 TPIU_FFCR, Formatter and Flush Control Register
 * -----------------------------------------------------------------------------
 */
/* ENFCONT - Enable continuous formatting, bit[1]
   1=使能连续格式化 */
#define ARM_V8M_TPIU_FFCR_ENFCONT_Pos   1U
#define ARM_V8M_TPIU_FFCR_ENFCONT_Msk   (1UL << ARM_V8M_TPIU_FFCR_ENFCONT_Pos)
/* TRIGIN - Trigger input, bit[8]
   1=使能触发输入 */
#define ARM_V8M_TPIU_FFCR_TRIGIN_Pos    8U
#define ARM_V8M_TPIU_FFCR_TRIGIN_Msk    (1UL << ARM_V8M_TPIU_FFCR_TRIGIN_Pos)
/* FONMAN - Flush on manual, bit[6]
   1=手动刷新 */
#define ARM_V8M_TPIU_FFCR_FONMAN_Pos    6U
#define ARM_V8M_TPIU_FFCR_FONMAN_Msk    (1UL << ARM_V8M_TPIU_FFCR_FONMAN_Pos)
/* FONTRIG - Flush on trigger, bit[5]
   1=触发时刷新 */
#define ARM_V8M_TPIU_FFCR_FONTRIG_Pos   5U
#define ARM_V8M_TPIU_FFCR_FONTRIG_Msk   (1UL << ARM_V8M_TPIU_FFCR_FONTRIG_Pos)
/* FONFLIN - Flush on FLUSHIN, bit[4]
   1=FLUSHIN时刷新 */
#define ARM_V8M_TPIU_FFCR_FONFLIN_Pos   4U
#define ARM_V8M_TPIU_FFCR_FONFLIN_Msk   (1UL << ARM_V8M_TPIU_FFCR_FONFLIN_Pos)

/* -----------------------------------------------------------------------------
 * 10.7 TPIU_FFSR 寄存器位域 (ARM_V8M_TPIU_FFSR)
 * 参考: D1.2.230 TPIU_FFSR, Formatter and Flush Status Register
 * -----------------------------------------------------------------------------
 */
/* FLINPROG - Flush in progress, bit[0]
   1=刷新正在进行 */
#define ARM_V8M_TPIU_FFSR_FLINPROG_Pos  0U
#define ARM_V8M_TPIU_FFSR_FLINPROG_Msk  (1UL << ARM_V8M_TPIU_FFSR_FLINPROG_Pos)
/* FTSTOPPED - Formatter stopped, bit[1]
   1=格式化器已停止 */
#define ARM_V8M_TPIU_FFSR_FTSTOPPED_Pos 1U
#define ARM_V8M_TPIU_FFSR_FTSTOPPED_Msk (1UL << ARM_V8M_TPIU_FFSR_FTSTOPPED_Pos)
/* TCPRESENT - Trace clock present, bit[2]
   1=跟踪时钟存在 */
#define ARM_V8M_TPIU_FFSR_TCPRESENT_Pos 2U
#define ARM_V8M_TPIU_FFSR_TCPRESENT_Msk (1UL << ARM_V8M_TPIU_FFSR_TCPRESENT_Pos)
/* FTNONSTOP - Formatter non-stop, bit[3]
   1=格式化器非停止模式 */
#define ARM_V8M_TPIU_FFSR_FTNONSTOP_Pos 3U
#define ARM_V8M_TPIU_FFSR_FTNONSTOP_Msk (1UL << ARM_V8M_TPIU_FFSR_FTNONSTOP_Pos)

/* ==============================================================================
 * 十一、PMU 寄存器位域
 * 地址范围: 0xE0003000 - 0xE0003FFF
 * 【v8m 独有】v7m 中不存在 PMU
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 11.1 PMU_TYPE 寄存器位域 (ARM_V8M_PMU_TYPE)
 * 参考: D1.2.199 PMU_TYPE, PMU Type Register
 * -----------------------------------------------------------------------------
 */
/* NUM_CNTS - Number of counters, bits[7:0]
   事件计数器数量 */
#define ARM_V8M_PMU_TYPE_NUM_CNTS_Pos   0U
#define ARM_V8M_PMU_TYPE_NUM_CNTS_Msk   (0xFFUL << ARM_V8M_PMU_TYPE_NUM_CNTS_Pos)
/* SIZE - Counter size, bits[13:8]
   计数器位宽: 0=32位, 1=64位 */
#define ARM_V8M_PMU_TYPE_SIZE_Pos       8U
#define ARM_V8M_PMU_TYPE_SIZE_Msk       (0x3FUL << ARM_V8M_PMU_TYPE_SIZE_Pos)
/* CYCCNT_PRESENT - Cycle counter present, bit[14]
   1=存在周期计数器 */
#define ARM_V8M_PMU_TYPE_CYCCNT_PRESENT_Pos 14U
#define ARM_V8M_PMU_TYPE_CYCCNT_PRESENT_Msk (1UL << ARM_V8M_PMU_TYPE_CYCCNT_PRESENT_Pos)
/* FRZ_OVFL - Freeze on overflow, bit[15]
   1=溢出时冻结 */
#define ARM_V8M_PMU_TYPE_FRZ_OVFL_Pos   15U
#define ARM_V8M_PMU_TYPE_FRZ_OVFL_Msk   (1UL << ARM_V8M_PMU_TYPE_FRZ_OVFL_Pos)

/* -----------------------------------------------------------------------------
 * 11.2 PMU_CTRL 寄存器位域 (ARM_V8M_PMU_CTRL)
 * 参考: D1.2.197 PMU_CTRL, PMU Control Register
 * -----------------------------------------------------------------------------
 */
/* ENABLE - PMU enable, bit[0]
   1=使能PMU */
#define ARM_V8M_PMU_CTRL_ENABLE_Pos     0U
#define ARM_V8M_PMU_CTRL_ENABLE_Msk     (1UL << ARM_V8M_PMU_CTRL_ENABLE_Pos)
/* CYCCNT_RESET - Cycle counter reset, bit[2]
   1=复位周期计数器 */
#define ARM_V8M_PMU_CTRL_CYCCNT_RESET_Pos 2U
#define ARM_V8M_PMU_CTRL_CYCCNT_RESET_Msk (1UL << ARM_V8M_PMU_CTRL_CYCCNT_RESET_Pos)
/* EVENTCNT_RESET - Event counter reset, bit[1]
   1=复位事件计数器 */
#define ARM_V8M_PMU_CTRL_EVENTCNT_RESET_Pos 1U
#define ARM_V8M_PMU_CTRL_EVENTCNT_RESET_Msk (1UL << ARM_V8M_PMU_CTRL_EVENTCNT_RESET_Pos)
/* CYCCNT_DISABLE_OV - Cycle counter disable overflow, bit[3]
   1=禁用周期计数器溢出 */
#define ARM_V8M_PMU_CTRL_CYCCNT_DISABLE_OV_Pos 3U
#define ARM_V8M_PMU_CTRL_CYCCNT_DISABLE_OV_Msk (1UL << ARM_V8M_PMU_CTRL_CYCCNT_DISABLE_OV_Pos)

/* -----------------------------------------------------------------------------
 * 11.3 PMU_CNTENSET/CNTENCLR 寄存器位域
 * 参考: D1.2.195 PMU_CNTENSET, D1.2.194 PMU_CNTENCLR
 * -----------------------------------------------------------------------------
 */
/* CEN0 - Counter 0 enable, bit[0]
   1=使能计数器0(周期计数器) */
#define ARM_V8M_PMU_CNTEN_CEN0_Pos      0U
#define ARM_V8M_PMU_CNTEN_CEN0_Msk      (1UL << ARM_V8M_PMU_CNTEN_CEN0_Pos)
/* CENn - Counter n enable, bits[31:1]
   每一位使能对应的事件计数器 */
#define ARM_V8M_PMU_CNTEN_CENn_Pos      1U
#define ARM_V8M_PMU_CNTEN_CENn_Msk      (0x7FFFFFFFUL << ARM_V8M_PMU_CNTEN_CENn_Pos)

/* -----------------------------------------------------------------------------
 * 11.4 PMU_INTENSET/INTENCLR 寄存器位域
 * 参考: D1.2.196 PMU_INTENSET, D1.2.193 PMU_INTENCLR
 * -----------------------------------------------------------------------------
 */
/* INTEN0 - Interrupt enable for counter 0, bit[0]
   1=使能计数器0中断 */
#define ARM_V8M_PMU_INTEN_INTEN0_Pos    0U
#define ARM_V8M_PMU_INTEN_INTEN0_Msk    (1UL << ARM_V8M_PMU_INTEN_INTEN0_Pos)
/* INTENn - Interrupt enable for counter n, bits[31:1]
   每一位使能对应的事件计数器中断 */
#define ARM_V8M_PMU_INTEN_INTENn_Pos    1U
#define ARM_V8M_PMU_INTEN_INTENn_Msk    (0x7FFFFFFFUL << ARM_V8M_PMU_INTEN_INTENn_Pos)

/* -----------------------------------------------------------------------------
 * 11.5 PMU_OVSSET/OVSCLR 寄存器位域
 * 参考: D1.2.201 PMU_OVSSET, D1.2.200 PMU_OVSCLR
 * -----------------------------------------------------------------------------
 */
/* OVS0 - Overflow for counter 0, bit[0]
   1=计数器0溢出 */
#define ARM_V8M_PMU_OVS_OVS0_Pos        0U
#define ARM_V8M_PMU_OVS_OVS0_Msk        (1UL << ARM_V8M_PMU_OVS_OVS0_Pos)
/* OVSn - Overflow for counter n, bits[31:1]
   每一位表示对应的事件计数器溢出 */
#define ARM_V8M_PMU_OVS_OVSn_Pos        1U
#define ARM_V8M_PMU_OVS_OVSn_Msk        (0x7FFFFFFFUL << ARM_V8M_PMU_OVS_OVSn_Pos)

/* -----------------------------------------------------------------------------
 * 11.6 PMU_EVTYPERn 寄存器位域 (ARM_V8M_PMU_EVTYPERn)
 * 参考: D1.2.192 PMU_EVTYPERn, PMU Event Type and Filter Register
 * -----------------------------------------------------------------------------
 */
/* EVENT_TYPE - Event type, bits[15:0]
   事件类型选择 */
#define ARM_V8M_PMU_EVTYPER_EVENT_TYPE_Pos 0U
#define ARM_V8M_PMU_EVTYPER_EVENT_TYPE_Msk (0xFFFFUL << ARM_V8M_PMU_EVTYPER_EVENT_TYPE_Pos)
/* TH - Threshold, bits[23:16]
   事件阈值 */
#define ARM_V8M_PMU_EVTYPER_TH_Pos      16U
#define ARM_V8M_PMU_EVTYPER_TH_Msk      (0xFFUL << ARM_V8M_PMU_EVTYPER_TH_Pos)

/* -----------------------------------------------------------------------------
 * 11.7 PMU_CCFILTR 寄存器位域 (ARM_V8M_PMU_CCFILTR)
 * 参考: D1.2.189 PMU_CCFILTR, PMU Cycle Counter Filter Register
 * -----------------------------------------------------------------------------
 */
/* TH - Threshold, bits[7:0]
   周期计数器阈值 */
#define ARM_V8M_PMU_CCFILTR_TH_Pos      0U
#define ARM_V8M_PMU_CCFILTR_TH_Msk      (0xFFUL << ARM_V8M_PMU_CCFILTR_TH_Pos)

/* ==============================================================================
 * 十二、RAS 寄存器位域
 * 地址范围: 0xE0005000 - 0xE0005FFF, 0xE000EF04
 * 【v8m 独有】v7m 中不存在 RAS
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 12.1 ERRFRn 寄存器位域 (ARM_V8M_ERRFRn)
 * 参考: D1.2.82 ERRFRn, Error Feature Register
 * -----------------------------------------------------------------------------
 */
/* ED - Error detection, bits[1:0]
   错误检测能力: 0=无, 1=单次, 2=多次 */
#define ARM_V8M_ERRFR_ED_Pos            0U
#define ARM_V8M_ERRFR_ED_Msk            (0x3UL << ARM_V8M_ERRFR_ED_Pos)
/* DE - Deferred error, bit[2]
   1=支持延迟错误 */
#define ARM_V8M_ERRFR_DE_Pos            2U
#define ARM_V8M_ERRFR_DE_Msk            (1UL << ARM_V8M_ERRFR_DE_Pos)
/* UI - Uncorrected error interrupt, bits[5:4]
   不可纠正错误中断: 0=无, 1=边缘, 2=水平 */
#define ARM_V8M_ERRFR_UI_Pos            4U
#define ARM_V8M_ERRFR_UI_Msk            (0x3UL << ARM_V8M_ERRFR_UI_Pos)
/* FI - Corrected error interrupt, bits[7:6]
   可纠正错误中断: 0=无, 1=边缘, 2=水平 */
#define ARM_V8M_ERRFR_FI_Pos            6U
#define ARM_V8M_ERRFR_FI_Msk            (0x3UL << ARM_V8M_ERRFR_FI_Pos)

/* -----------------------------------------------------------------------------
 * 12.2 ERRCTRLn 寄存器位域 (ARM_V8M_ERRCTRLn)
 * 参考: D1.2.79 ERRCTRLn, Error Control Register
 * -----------------------------------------------------------------------------
 */
/* ED - Error detection enable, bit[0]
   1=使能错误检测 */
#define ARM_V8M_ERRCTRL_ED_Pos          0U
#define ARM_V8M_ERRCTRL_ED_Msk          (1UL << ARM_V8M_ERRCTRL_ED_Pos)
/* UI - Uncorrected error interrupt enable, bit[2]
   1=使能不可纠正错误中断 */
#define ARM_V8M_ERRCTRL_UI_Pos          2U
#define ARM_V8M_ERRCTRL_UI_Msk          (1UL << ARM_V8M_ERRCTRL_UI_Pos)
/* FI - Corrected error interrupt enable, bit[3]
   1=使能可纠正错误中断 */
#define ARM_V8M_ERRCTRL_FI_Pos          3U
#define ARM_V8M_ERRCTRL_FI_Msk          (1UL << ARM_V8M_ERRCTRL_FI_Pos)

/* -----------------------------------------------------------------------------
 * 12.3 ERRSTATUSn 寄存器位域 (ARM_V8M_ERRSTATUSn)
 * 参考: D1.2.81 ERRSTATUSn, Error Status Register
 * -----------------------------------------------------------------------------
 */
/* SERR - Error status, bits[2:0]
   错误状态: 0=无, 1=溢出, 2=可纠正, 3=不可纠正 */
#define ARM_V8M_ERRSTATUS_SERR_Pos      0U
#define ARM_V8M_ERRSTATUS_SERR_Msk      (0x7UL << ARM_V8M_ERRSTATUS_SERR_Pos)
/* IERR - Implementation defined error, bits[6:4]
   实现定义的错误 */
#define ARM_V8M_ERRSTATUS_IERR_Pos      4U
#define ARM_V8M_ERRSTATUS_IERR_Msk      (0x7UL << ARM_V8M_ERRSTATUS_IERR_Pos)
/* CE - Corrected error, bits[9:8]
   可纠正错误计数 */
#define ARM_V8M_ERRSTATUS_CE_Pos        8U
#define ARM_V8M_ERRSTATUS_CE_Msk        (0x3UL << ARM_V8M_ERRSTATUS_CE_Pos)
/* MV - Miscellaneous registers valid, bit[10]
   1=杂项寄存器有效 */
#define ARM_V8M_ERRSTATUS_MV_Pos        10U
#define ARM_V8M_ERRSTATUS_MV_Msk        (1UL << ARM_V8M_ERRSTATUS_MV_Pos)
/* AV - Address register valid, bit[11]
   1=地址寄存器有效 */
#define ARM_V8M_ERRSTATUS_AV_Pos        11U
#define ARM_V8M_ERRSTATUS_AV_Msk        (1UL << ARM_V8M_ERRSTATUS_AV_Pos)
/* V - Status register valid, bit[12]
   1=状态寄存器有效 */
#define ARM_V8M_ERRSTATUS_V_Pos         12U
#define ARM_V8M_ERRSTATUS_V_Msk         (1UL << ARM_V8M_ERRSTATUS_V_Pos)
/* OF - Overflow, bit[13]
   1=错误溢出 */
#define ARM_V8M_ERRSTATUS_OF_Pos        13U
#define ARM_V8M_ERRSTATUS_OF_Msk        (1UL << ARM_V8M_ERRSTATUS_OF_Pos)
/* ER - Error Reported, bit[14]
   1=错误已报告 */
#define ARM_V8M_ERRSTATUS_ER_Pos        14U
#define ARM_V8M_ERRSTATUS_ER_Msk        (1UL << ARM_V8M_ERRSTATUS_ER_Pos)
/* UE - Uncorrected error, bit[15]
   1=不可纠正错误 */
#define ARM_V8M_ERRSTATUS_UE_Pos        15U
#define ARM_V8M_ERRSTATUS_UE_Msk        (1UL << ARM_V8M_ERRSTATUS_UE_Pos)
/* OFR - Overflow reported, bit[16]
   1=溢出已报告 */
#define ARM_V8M_ERRSTATUS_OFR_Pos       16U
#define ARM_V8M_ERRSTATUS_OFR_Msk       (1UL << ARM_V8M_ERRSTATUS_OFR_Pos)
/* CLEAR - Clear status, bit[31]
   1=清除错误状态 */
#define ARM_V8M_ERRSTATUS_CLEAR_Pos     31U
#define ARM_V8M_ERRSTATUS_CLEAR_Msk     (1UL << ARM_V8M_ERRSTATUS_CLEAR_Pos)

/* -----------------------------------------------------------------------------
 * 12.4 RFSR 寄存器位域 (ARM_V8M_RFSR)
 * 参考: D1.2.221 RFSR, RAS Fault Status Register
 * -----------------------------------------------------------------------------
 */
/* RAS - RAS error, bit[0]
   1=发生RAS错误 */
#define ARM_V8M_RFSR_RAS_Pos            0U
#define ARM_V8M_RFSR_RAS_Msk            (1UL << ARM_V8M_RFSR_RAS_Pos)
/* ISV - RAS error is valid, bit[1]
   1=RAS错误有效 */
#define ARM_V8M_RFSR_ISV_Pos            1U
#define ARM_V8M_RFSR_ISV_Msk            (1UL << ARM_V8M_RFSR_ISV_Pos)
/* V - RFSR valid, bit[31]
   1=RFSR有效 */
#define ARM_V8M_RFSR_V_Pos              31U
#define ARM_V8M_RFSR_V_Msk              (1UL << ARM_V8M_RFSR_V_Pos)

/* ==============================================================================
 * 十三、浮点扩展寄存器位域
 * 地址范围: 0xE000EF34 - 0xE000EF3F
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 13.1 FPCCR 寄存器位域 (ARM_V8M_FPCCR)
 * 参考: D1.2.94 FPCCR, Floating-point Context Control Register
 * -----------------------------------------------------------------------------
 */
/* LSPACT - Lazy state preservation active, bit[0]
   1=延迟状态保存激活 */
#define ARM_V8M_FPCCR_LSPACT_Pos        0U
#define ARM_V8M_FPCCR_LSPACT_Msk        (1UL << ARM_V8M_FPCCR_LSPACT_Pos)
/* USER - User mode, bit[1]
   1=特权级为User */
#define ARM_V8M_FPCCR_USER_Pos          1U
#define ARM_V8M_FPCCR_USER_Msk          (1UL << ARM_V8M_FPCCR_USER_Pos)
/* THREAD - Thread mode, bit[3]
   1=模式为Thread */
#define ARM_V8M_FPCCR_THREAD_Pos        3U
#define ARM_V8M_FPCCR_THREAD_Msk        (1UL << ARM_V8M_FPCCR_THREAD_Pos)
/* HFRDY - HardFault ready, bit[4]
   1=HardFault处理程序已设置 */
#define ARM_V8M_FPCCR_HFRDY_Pos         4U
#define ARM_V8M_FPCCR_HFRDY_Msk         (1UL << ARM_V8M_FPCCR_HFRDY_Pos)
/* MMRDY - MemManage ready, bit[5]
   1=MemManage处理程序已设置 */
#define ARM_V8M_FPCCR_MMRDY_Pos         5U
#define ARM_V8M_FPCCR_MMRDY_Msk         (1UL << ARM_V8M_FPCCR_MMRDY_Pos)
/* BFRDY - BusFault ready, bit[6]
   1=BusFault处理程序已设置 */
#define ARM_V8M_FPCCR_BFRDY_Pos         6U
#define ARM_V8M_FPCCR_BFRDY_Msk         (1UL << ARM_V8M_FPCCR_BFRDY_Pos)
/* SFRDY - SecureFault ready, bit[7]
   【v8m 独有】1=SecureFault处理程序已设置 */
#define ARM_V8M_FPCCR_SFRDY_Pos         7U
#define ARM_V8M_FPCCR_SFRDY_Msk         (1UL << ARM_V8M_FPCCR_SFRDY_Pos)
/* MONRDY - DebugMonitor ready, bit[8]
   1=DebugMonitor处理程序已设置 */
#define ARM_V8M_FPCCR_MONRDY_Pos        8U
#define ARM_V8M_FPCCR_MONRDY_Msk        (1UL << ARM_V8M_FPCCR_MONRDY_Pos)
/* SPLIMVIOL - Stack pointer limit violation, bit[9]
   【v8m 独有】栈指针限制违规标志 */
#define ARM_V8M_FPCCR_SPLIMVIOL_Pos     9U
#define ARM_V8M_FPCCR_SPLIMVIOL_Msk     (1UL << ARM_V8M_FPCCR_SPLIMVIOL_Pos)
/* UFRDY - UsageFault ready, bit[10]
   UsageFault处理程序就绪标志 */
#define ARM_V8M_FPCCR_UFRDY_Pos         10U
#define ARM_V8M_FPCCR_UFRDY_Msk         (1UL << ARM_V8M_FPCCR_UFRDY_Pos)
/* S - Security status, bit[2]
   【v8m 独有】浮点上下文的安全状态: 0=Non-secure, 1=Secure */
#define ARM_V8M_FPCCR_S_Pos             2U
#define ARM_V8M_FPCCR_S_Msk             (1UL << ARM_V8M_FPCCR_S_Pos)
/* LSPEN - Lazy state preservation enable, bit[30]
   1=使能延迟状态保存 */
#define ARM_V8M_FPCCR_LSPEN_Pos         30U
#define ARM_V8M_FPCCR_LSPEN_Msk         (1UL << ARM_V8M_FPCCR_LSPEN_Pos)
/* LSPENS - Lazy state preservation enable Secure, bit[29]
   【v8m 独有】控制LSPEN是否可从Non-secure状态写入 */
#define ARM_V8M_FPCCR_LSPENS_Pos        29U
#define ARM_V8M_FPCCR_LSPENS_Msk        (1UL << ARM_V8M_FPCCR_LSPENS_Pos)
/* ASPEN - Automatic state preservation enable, bit[31]
   1=使能自动状态保存 */
#define ARM_V8M_FPCCR_ASPEN_Pos         31U
#define ARM_V8M_FPCCR_ASPEN_Msk         (1UL << ARM_V8M_FPCCR_ASPEN_Pos)
/* TS - Treat FP instructions as Secure, bit[26]
   【v8m 独有】1=将FP指令视为Secure */
#define ARM_V8M_FPCCR_TS_Pos            26U
#define ARM_V8M_FPCCR_TS_Msk            (1UL << ARM_V8M_FPCCR_TS_Pos)
/* CLRONRET - Clear on return, bit[28]
   【v8m 独有】1=返回时清除浮点状态 */
#define ARM_V8M_FPCCR_CLRONRET_Pos      28U
#define ARM_V8M_FPCCR_CLRONRET_Msk      (1UL << ARM_V8M_FPCCR_CLRONRET_Pos)
/* CLRONRETS - Clear on return secure, bit[27]
   【v8m 独有】1=返回时清除Secure浮点状态 */
#define ARM_V8M_FPCCR_CLRONRETS_Pos     27U
#define ARM_V8M_FPCCR_CLRONRETS_Msk     (1UL << ARM_V8M_FPCCR_CLRONRETS_Pos)

/* -----------------------------------------------------------------------------
 * 13.2 FPCAR 寄存器位域 (ARM_V8M_FPCAR)
 * 参考: D1.2.99 FPCAR, Floating-point Context Address Register
 * -----------------------------------------------------------------------------
 */
/* ADDRESS - Floating-point context address, bits[31:3]
   浮点上下文地址的高29位，bits[2:0]保留为0 */
#define ARM_V8M_FPCAR_ADDRESS_Pos       3U
#define ARM_V8M_FPCAR_ADDRESS_Msk       (0x1FFFFFFFUL << ARM_V8M_FPCAR_ADDRESS_Pos)

/* -----------------------------------------------------------------------------
 * 13.3 FPDSCR 寄存器位域 (ARM_V8M_FPDSCR)
 * 参考: D1.2.96 FPDSCR, Floating-point Default Status Control Register
 * -----------------------------------------------------------------------------
 */
/* IOC - Invalid operation cumulative exception, bit[0] */
#define ARM_V8M_FPDSCR_IOC_Pos          0U
#define ARM_V8M_FPDSCR_IOC_Msk          (1UL << ARM_V8M_FPDSCR_IOC_Pos)
/* DZC - Division by zero cumulative exception, bit[1] */
#define ARM_V8M_FPDSCR_DZC_Pos          1U
#define ARM_V8M_FPDSCR_DZC_Msk          (1UL << ARM_V8M_FPDSCR_DZC_Pos)
/* OFC - Overflow cumulative exception, bit[2] */
#define ARM_V8M_FPDSCR_OFC_Pos          2U
#define ARM_V8M_FPDSCR_OFC_Msk          (1UL << ARM_V8M_FPDSCR_OFC_Pos)
/* UFC - Underflow cumulative exception, bit[3] */
#define ARM_V8M_FPDSCR_UFC_Pos          3U
#define ARM_V8M_FPDSCR_UFC_Msk          (1UL << ARM_V8M_FPDSCR_UFC_Pos)
/* IXC - Inexact cumulative exception, bit[4] */
#define ARM_V8M_FPDSCR_IXC_Pos          4U
#define ARM_V8M_FPDSCR_IXC_Msk          (1UL << ARM_V8M_FPDSCR_IXC_Pos)
/* IDC - Input denormal cumulative exception, bit[7] */
#define ARM_V8M_FPDSCR_IDC_Pos          7U
#define ARM_V8M_FPDSCR_IDC_Msk          (1UL << ARM_V8M_FPDSCR_IDC_Pos)
/* RMode - Rounding mode, bits[23:22]
   舍入模式: 0=就近, 1=正无穷, 2=负无穷, 3=向零 */
#define ARM_V8M_FPDSCR_RMODE_Pos        22U
#define ARM_V8M_FPDSCR_RMODE_Msk        (0x3UL << ARM_V8M_FPDSCR_RMODE_Pos)
/* FZ - Flush to zero, bit[24]
   1=刷新到零 */
#define ARM_V8M_FPDSCR_FZ_Pos           24U
#define ARM_V8M_FPDSCR_FZ_Msk           (1UL << ARM_V8M_FPDSCR_FZ_Pos)
/* DN - Default NaN, bit[25]
   1=默认NaN */
#define ARM_V8M_FPDSCR_DN_Pos           25U
#define ARM_V8M_FPDSCR_DN_Msk           (1UL << ARM_V8M_FPDSCR_DN_Pos)
/* AHP - Alternative half-precision, bit[26]
   1=替代半精度格式 */
#define ARM_V8M_FPDSCR_AHP_Pos          26U
#define ARM_V8M_FPDSCR_AHP_Msk          (1UL << ARM_V8M_FPDSCR_AHP_Pos)

/* -----------------------------------------------------------------------------
 * 13.3 MVFR0/MVFR1/MVFR2 寄存器位域
 * 参考: D1.2.163 MVFR0, D1.2.164 MVFR1, D1.2.165 MVFR2
 * -----------------------------------------------------------------------------
 */
/* SIMD registers - bits[3:0] in MVFR0 */
#define ARM_V8M_MVFR0_SIMDMREG_Pos      0U
#define ARM_V8M_MVFR0_SIMDMREG_Msk      (0xFUL << ARM_V8M_MVFR0_SIMDMREG_Pos)
/* Single-precision - bits[7:4] in MVFR0 */
#define ARM_V8M_MVFR0_SINGLEM_Pos       4U
#define ARM_V8M_MVFR0_SINGLEM_Msk       (0xFUL << ARM_V8M_MVFR0_SINGLEM_Pos)
/* Double-precision - bits[11:8] in MVFR0 */
#define ARM_V8M_MVFR0_DOUBLEM_Pos       8U
#define ARM_V8M_MVFR0_DOUBLEM_Msk       (0xFUL << ARM_V8M_MVFR0_DOUBLEM_Pos)
/* FP exception trapping - bits[7:4] in MVFR1 */
#define ARM_V8M_MVFR1_FPEXCEPT_Pos      4U
#define ARM_V8M_MVFR1_FPEXCEPT_Msk      (0xFUL << ARM_V8M_MVFR1_FPEXCEPT_Pos)
/* FP half-precision - bits[7:4] in MVFR1 */
#define ARM_V8M_MVFR1_FPHP_Pos          4U
#define ARM_V8M_MVFR1_FPHP_Msk          (0xFUL << ARM_V8M_MVFR1_FPHP_Pos)
/* MVE - bits[7:4] in MVFR1 */
#define ARM_V8M_MVFR1_MVE_Pos           4U
#define ARM_V8M_MVFR1_MVE_Msk           (0xFUL << ARM_V8M_MVFR1_MVE_Pos)
/* FP16 half-precision - bits[3:0] in MVFR2 */
#define ARM_V8M_MVFR2_FPMISC_Pos        0U
#define ARM_V8M_MVFR2_FPMISC_Msk        (0xFUL << ARM_V8M_MVFR2_FPMISC_Pos)

/* ==============================================================================
 * 十四、MVE 寄存器位域
 * 地址范围: 0xE000EF40 - 0xE000EF44
 * 【v8m 独有】v7m 中不存在 MVE
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 14.1 VPR 寄存器位域 (ARM_V8M_VPR)
 * 参考: D1.2.244 VPR, Vector Predication Register
 * -----------------------------------------------------------------------------
 */
/* P0 - Predication bits, bits[15:0]
   每位控制一个8位通道的预测 */
#define ARM_V8M_VPR_P0_Pos              0U
#define ARM_V8M_VPR_P0_Msk              (0xFFFFUL << ARM_V8M_VPR_P0_Pos)
/* MASK01 - Mask for lanes 0-1, bits[19:16]
   影响VPR.P0的bits[7:0] */
#define ARM_V8M_VPR_MASK01_Pos          16U
#define ARM_V8M_VPR_MASK01_Msk          (0xFUL << ARM_V8M_VPR_MASK01_Pos)
/* MASK23 - Mask for lanes 2-3, bits[23:20]
   影响VPR.P0的bits[15:8] */
#define ARM_V8M_VPR_MASK23_Pos          20U
#define ARM_V8M_VPR_MASK23_Msk          (0xFUL << ARM_V8M_VPR_MASK23_Pos)
/* VPT - VPT state, bits[27:24]
   VPT块状态 */
#define ARM_V8M_VPR_VPT_Pos             24U
#define ARM_V8M_VPR_VPT_Msk             (0xFUL << ARM_V8M_VPR_VPT_Pos)
/* VPTT - VPT tail, bits[31:28]
   VPT尾状态 */
#define ARM_V8M_VPR_VPTT_Pos            28U
#define ARM_V8M_VPR_VPTT_Msk            (0xFUL << ARM_V8M_VPR_VPTT_Pos)

/* -----------------------------------------------------------------------------
 * 14.2 FPSCR 寄存器位域 (ARM_V8M_FPSCR)
 * 参考: D1.2.95 FPSCR, Floating-point Status and Control Register
 * -----------------------------------------------------------------------------
 */
/* IOC - Invalid operation cumulative exception, bit[0] */
#define ARM_V8M_FPSCR_IOC_Pos           0U
#define ARM_V8M_FPSCR_IOC_Msk           (1UL << ARM_V8M_FPSCR_IOC_Pos)
/* DZC - Division by zero cumulative exception, bit[1] */
#define ARM_V8M_FPSCR_DZC_Pos           1U
#define ARM_V8M_FPSCR_DZC_Msk           (1UL << ARM_V8M_FPSCR_DZC_Pos)
/* OFC - Overflow cumulative exception, bit[2] */
#define ARM_V8M_FPSCR_OFC_Pos           2U
#define ARM_V8M_FPSCR_OFC_Msk           (1UL << ARM_V8M_FPSCR_OFC_Pos)
/* UFC - Underflow cumulative exception, bit[3] */
#define ARM_V8M_FPSCR_UFC_Pos           3U
#define ARM_V8M_FPSCR_UFC_Msk           (1UL << ARM_V8M_FPSCR_UFC_Pos)
/* IXC - Inexact cumulative exception, bit[4] */
#define ARM_V8M_FPSCR_IXC_Pos           4U
#define ARM_V8M_FPSCR_IXC_Msk           (1UL << ARM_V8M_FPSCR_IXC_Pos)
/* IDC - Input denormal cumulative exception, bit[7] */
#define ARM_V8M_FPSCR_IDC_Pos           7U
#define ARM_V8M_FPSCR_IDC_Msk           (1UL << ARM_V8M_FPSCR_IDC_Pos)
/* IOE - Invalid operation exception enable, bit[8] */
#define ARM_V8M_FPSCR_IOE_Pos           8U
#define ARM_V8M_FPSCR_IOE_Msk           (1UL << ARM_V8M_FPSCR_IOE_Pos)
/* DZE - Division by zero exception enable, bit[9] */
#define ARM_V8M_FPSCR_DZE_Pos           9U
#define ARM_V8M_FPSCR_DZE_Msk           (1UL << ARM_V8M_FPSCR_DZE_Pos)
/* OFE - Overflow exception enable, bit[10] */
#define ARM_V8M_FPSCR_OFE_Pos           10U
#define ARM_V8M_FPSCR_OFE_Msk           (1UL << ARM_V8M_FPSCR_OFE_Pos)
/* UFE - Underflow exception enable, bit[11] */
#define ARM_V8M_FPSCR_UFE_Pos           11U
#define ARM_V8M_FPSCR_UFE_Msk           (1UL << ARM_V8M_FPSCR_UFE_Pos)
/* IXE - Inexact exception enable, bit[12] */
#define ARM_V8M_FPSCR_IXE_Pos           12U
#define ARM_V8M_FPSCR_IXE_Msk           (1UL << ARM_V8M_FPSCR_IXE_Pos)
/* IDE - Input denormal exception enable, bit[15] */
#define ARM_V8M_FPSCR_IDE_Pos           15U
#define ARM_V8M_FPSCR_IDE_Msk           (1UL << ARM_V8M_FPSCR_IDE_Pos)
/* RMode - Rounding mode, bits[23:22]
   舍入模式: 0=就近, 1=正无穷, 2=负无穷, 3=向零 */
#define ARM_V8M_FPSCR_RMODE_Pos         22U
#define ARM_V8M_FPSCR_RMODE_Msk         (0x3UL << ARM_V8M_FPSCR_RMODE_Pos)
/* FZ - Flush to zero, bit[24]
   1=刷新到零 */
#define ARM_V8M_FPSCR_FZ_Pos            24U
#define ARM_V8M_FPSCR_FZ_Msk            (1UL << ARM_V8M_FPSCR_FZ_Pos)
/* DN - Default NaN, bit[25]
   1=默认NaN */
#define ARM_V8M_FPSCR_DN_Pos            25U
#define ARM_V8M_FPSCR_DN_Msk            (1UL << ARM_V8M_FPSCR_DN_Pos)
/* AHP - Alternative half-precision, bit[26]
   1=替代半精度格式 */
#define ARM_V8M_FPSCR_AHP_Pos           26U
#define ARM_V8M_FPSCR_AHP_Msk           (1UL << ARM_V8M_FPSCR_AHP_Pos)
/* QC - Saturation cumulative, bit[27]
   1=发生饱和 */
#define ARM_V8M_FPSCR_QC_Pos            27U
#define ARM_V8M_FPSCR_QC_Msk            (1UL << ARM_V8M_FPSCR_QC_Pos)
/* V - Overflow condition flag, bit[28] */
#define ARM_V8M_FPSCR_V_Pos             28U
#define ARM_V8M_FPSCR_V_Msk             (1UL << ARM_V8M_FPSCR_V_Pos)
/* C - Carry condition flag, bit[29] */
#define ARM_V8M_FPSCR_C_Pos             29U
#define ARM_V8M_FPSCR_C_Msk             (1UL << ARM_V8M_FPSCR_C_Pos)
/* Z - Zero condition flag, bit[30] */
#define ARM_V8M_FPSCR_Z_Pos             30U
#define ARM_V8M_FPSCR_Z_Msk             (1UL << ARM_V8M_FPSCR_Z_Pos)
/* N - Negative condition flag, bit[31] */
#define ARM_V8M_FPSCR_N_Pos             31U
#define ARM_V8M_FPSCR_N_Msk             (1UL << ARM_V8M_FPSCR_N_Pos)
/* LTPSIZE - Last beat element size, bits[18:16]
   【v8m 独有】上次节拍元素大小 */
#define ARM_V8M_FPSCR_LTPSIZE_Pos       16U
#define ARM_V8M_FPSCR_LTPSIZE_Msk       (0x7UL << ARM_V8M_FPSCR_LTPSIZE_Pos)
/* STRIDE - Vector stride, bits[21:20]
   【v8m 独有】向量步幅 */
#define ARM_V8M_FPSCR_STRIDE_Pos        20U
#define ARM_V8M_FPSCR_STRIDE_Msk        (0x3UL << ARM_V8M_FPSCR_STRIDE_Pos)

/* ==============================================================================
 * 十五、缓存识别寄存器位域
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 15.1 CLIDR 寄存器位域 (ARM_V8M_SCB_CLIDR)
 * 参考: D1.2.28 CLIDR, Cache Level ID Register
 * -----------------------------------------------------------------------------
 */
/* Ctype1 - Cache type level 1, bits[2:0]
   一级缓存类型: 0=无, 1=指令, 2=数据, 3=统一, 4=独立指令/数据 */
#define ARM_V8M_CLIDR_CTYPE1_Pos        0U
#define ARM_V8M_CLIDR_CTYPE1_Msk        (0x7UL << ARM_V8M_CLIDR_CTYPE1_Pos)
/* Ctype2 - Cache type level 2, bits[5:3]
   二级缓存类型 */
#define ARM_V8M_CLIDR_CTYPE2_Pos        3U
#define ARM_V8M_CLIDR_CTYPE2_Msk        (0x7UL << ARM_V8M_CLIDR_CTYPE2_Pos)
/* Ctype3 - Cache type level 3, bits[8:6]
   三级缓存类型 */
#define ARM_V8M_CLIDR_CTYPE3_Pos        6U
#define ARM_V8M_CLIDR_CTYPE3_Msk        (0x7UL << ARM_V8M_CLIDR_CTYPE3_Pos)
/* LoC - Level of coherence, bits[26:24]
   一致性级别 */
#define ARM_V8M_CLIDR_LOC_Pos           24U
#define ARM_V8M_CLIDR_LOC_Msk           (0x7UL << ARM_V8M_CLIDR_LOC_Pos)
/* LoUIS - Level of unification inner shareable, bits[29:27]
   内部可共享统一级别 */
#define ARM_V8M_CLIDR_LOUIS_Pos         27U
#define ARM_V8M_CLIDR_LOUIS_Msk         (0x7UL << ARM_V8M_CLIDR_LOUIS_Pos)
/* LoUU - Level of unification uniprocessor, bits[32:30]
   单处理器统一级别 */
#define ARM_V8M_CLIDR_LOUU_Pos          30U
#define ARM_V8M_CLIDR_LOUU_Msk          (0x7UL << ARM_V8M_CLIDR_LOUU_Pos)

/* -----------------------------------------------------------------------------
 * 15.2 CTR 寄存器位域 (ARM_V8M_SCB_CTR)
 * 参考: D1.2.40 CTR, Cache Type Register
 * -----------------------------------------------------------------------------
 */
/* IminLine - Instruction cache minimum line size, bits[3:0]
   指令缓存最小行大小: 2^(4+n)字节 */
#define ARM_V8M_CTR_IMINLINE_Pos        0U
#define ARM_V8M_CTR_IMINLINE_Msk        (0xFUL << ARM_V8M_CTR_IMINLINE_Pos)
/* DminLine - Data cache minimum line size, bits[19:16]
   数据缓存最小行大小: 2^(4+n)字节 */
#define ARM_V8M_CTR_DMINLINE_Pos        16U
#define ARM_V8M_CTR_DMINLINE_Msk        (0xFUL << ARM_V8M_CTR_DMINLINE_Pos)
/* ERG - Exclusives reservation granule, bits[23:20]
   独占保留粒度: 2^(4+n)字节 */
#define ARM_V8M_CTR_ERG_Pos             20U
#define ARM_V8M_CTR_ERG_Msk             (0xFUL << ARM_V8M_CTR_ERG_Pos)
/* CWG - Cache writeback granule, bits[27:24]
   缓存写回粒度: 2^(4+n)字节 */
#define ARM_V8M_CTR_CWG_Pos             24U
#define ARM_V8M_CTR_CWG_Msk             (0xFUL << ARM_V8M_CTR_CWG_Pos)
/* Format - CTR format, bit[31]
   CTR格式: 0=32位格式 */
#define ARM_V8M_CTR_FORMAT_Pos          31U
#define ARM_V8M_CTR_FORMAT_Msk          (1UL << ARM_V8M_CTR_FORMAT_Pos)

/* -----------------------------------------------------------------------------
 * 15.3 CCSIDR 寄存器位域 (ARM_V8M_SCB_CCSIDR)
 * 参考: D1.2.25 CCSIDR, Current Cache Size ID Register
 * -----------------------------------------------------------------------------
 */
/* LineSize - Line size, bits[2:0]
   缓存行大小: 2^(n+4)字节 */
#define ARM_V8M_CCSIDR_LINESIZE_Pos     0U
#define ARM_V8M_CCSIDR_LINESIZE_Msk     (0x7UL << ARM_V8M_CCSIDR_LINESIZE_Pos)
/* Associativity - Associativity, bits[12:3]
   关联度: (Associativity+1)路 */
#define ARM_V8M_CCSIDR_ASSOCIATIVITY_Pos 3U
#define ARM_V8M_CCSIDR_ASSOCIATIVITY_Msk (0x3FFUL << ARM_V8M_CCSIDR_ASSOCIATIVITY_Pos)
/* NumSets - Number of sets, bits[27:13]
   组数: (NumSets+1) */
#define ARM_V8M_CCSIDR_NUMSETS_Pos      13U
#define ARM_V8M_CCSIDR_NUMSETS_Msk      (0x7FFFUL << ARM_V8M_CCSIDR_NUMSETS_Pos)
/* WA - Write-allocate, bit[28]
   1=支持写分配 */
#define ARM_V8M_CCSIDR_WA_Pos           28U
#define ARM_V8M_CCSIDR_WA_Msk           (1UL << ARM_V8M_CCSIDR_WA_Pos)
/* RA - Read-allocate, bit[29]
   1=支持读分配 */
#define ARM_V8M_CCSIDR_RA_Pos           29U
#define ARM_V8M_CCSIDR_RA_Msk           (1UL << ARM_V8M_CCSIDR_RA_Pos)
/* WB - Write-back, bit[30]
   1=支持写回 */
#define ARM_V8M_CCSIDR_WB_Pos           30U
#define ARM_V8M_CCSIDR_WB_Msk           (1UL << ARM_V8M_CCSIDR_WB_Pos)
/* WT - Write-through, bit[31]
   1=支持写通 */
#define ARM_V8M_CCSIDR_WT_Pos           31U
#define ARM_V8M_CCSIDR_WT_Msk           (1UL << ARM_V8M_CCSIDR_WT_Pos)

/* -----------------------------------------------------------------------------
 * 15.4 CSSELR 寄存器位域 (ARM_V8M_SCB_CSSELR)
 * 参考: D1.2.41 CSSELR, Cache Size Selection Register
 * -----------------------------------------------------------------------------
 */
/* IND - Instruction not data, bit[0]
   0=数据缓存, 1=指令缓存 */
#define ARM_V8M_CSSELR_IND_Pos          0U
#define ARM_V8M_CSSELR_IND_Msk          (1UL << ARM_V8M_CSSELR_IND_Pos)
/* LEVEL - Cache level, bits[3:1]
   缓存级别: 0=Level 1, 1=Level 2 */
#define ARM_V8M_CSSELR_LEVEL_Pos        1U
#define ARM_V8M_CSSELR_LEVEL_Msk        (0x7UL << ARM_V8M_CSSELR_LEVEL_Pos)

/* ==============================================================================
 * 十六、特性识别寄存器位域
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 16.1 ID_PFR0 寄存器位域 (ARM_V8M_SCB_ID_PFR0)
 * 参考: D1.2.114 ID_PFR0, Processor Feature Register 0
 * -----------------------------------------------------------------------------
 */
/* State0 - ARM instruction set support, bits[3:0]
   0=不支持, 1=支持ARM指令集 */
#define ARM_V8M_ID_PFR0_STATE0_Pos      0U
#define ARM_V8M_ID_PFR0_STATE0_Msk      (0xFUL << ARM_V8M_ID_PFR0_STATE0_Pos)
/* State1 - Thumb instruction set support, bits[7:4]
   0=不支持, 1=支持Thumb指令集, 3=支持Thumb-2 */
#define ARM_V8M_ID_PFR0_STATE1_Pos      4U
#define ARM_V8M_ID_PFR0_STATE1_Msk      (0xFUL << ARM_V8M_ID_PFR0_STATE1_Pos)
/* State2 - Jazelle instruction set support, bits[11:8]
   0=不支持, 1=支持Jazelle */
#define ARM_V8M_ID_PFR0_STATE2_Pos      8U
#define ARM_V8M_ID_PFR0_STATE2_Msk      (0xFUL << ARM_V8M_ID_PFR0_STATE2_Pos)
/* State3 - ThumbEE instruction set support, bits[15:12]
   0=不支持, 1=支持ThumbEE */
#define ARM_V8M_ID_PFR0_STATE3_Pos      12U
#define ARM_V8M_ID_PFR0_STATE3_Msk      (0xFUL << ARM_V8M_ID_PFR0_STATE3_Pos)

/* -----------------------------------------------------------------------------
 * 16.2 ID_PFR1 寄存器位域 (ARM_V8M_SCB_ID_PFR1)
 * 参考: D1.2.115 ID_PFR1, Processor Feature Register 1
 * -----------------------------------------------------------------------------
 */
/* MProgMod - M-profile programmers' model, bits[3:0]
   0=不支持, 2=支持M-profile */
#define ARM_V8M_ID_PFR1_MPROGMOD_Pos    0U
#define ARM_V8M_ID_PFR1_MPROGMOD_Msk    (0xFUL << ARM_V8M_ID_PFR1_MPROGMOD_Pos)
/* Security - Security extension, bits[7:4]
   0=不支持, 1=支持Security扩展 */
#define ARM_V8M_ID_PFR1_SECURITY_Pos    4U
#define ARM_V8M_ID_PFR1_SECURITY_Msk    (0xFUL << ARM_V8M_ID_PFR1_SECURITY_Pos)
/* MProgMod2 - M-profile programmers' model 2, bits[11:8]
   【v8m 独有】0=不支持, 1=支持M-profile 2 */
#define ARM_V8M_ID_PFR1_MPROGMOD2_Pos   8U
#define ARM_V8M_ID_PFR1_MPROGMOD2_Msk   (0xFUL << ARM_V8M_ID_PFR1_MPROGMOD2_Pos)

/* -----------------------------------------------------------------------------
 * 16.3 ID_DFR0 寄存器位域 (ARM_V8M_SCB_ID_DFR0)
 * 参考: D1.2.113 ID_DFR0, Debug Feature Register 0
 * -----------------------------------------------------------------------------
 */
/* CopDbg - Coprocessor debug, bits[3:0]
   协处理器调试支持 */
#define ARM_V8M_ID_DFR0_COPDBG_Pos      0U
#define ARM_V8M_ID_DFR0_COPDBG_Msk      (0xFUL << ARM_V8M_ID_DFR0_COPDBG_Pos)
/* CopSDbg - Coprocessor secure debug, bits[7:4]
   协处理器安全调试支持 */
#define ARM_V8M_ID_DFR0_COPSDGB_Pos     4U
#define ARM_V8M_ID_DFR0_COPSDGB_Msk     (0xFUL << ARM_V8M_ID_DFR0_COPSDGB_Pos)
/* MMapDbg - Memory-mapped debug, bits[11:8]
   内存映射调试支持 */
#define ARM_V8M_ID_DFR0_MMAPDBG_Pos     8U
#define ARM_V8M_ID_DFR0_MMAPDBG_Msk     (0xFUL << ARM_V8M_ID_DFR0_MMAPDBG_Pos)
/* MProfDbg - M-profile debug, bits[15:12]
   M-profile调试支持 */
#define ARM_V8M_ID_DFR0_MPROFDBG_Pos    12U
#define ARM_V8M_ID_DFR0_MPROFDBG_Msk    (0xFUL << ARM_V8M_ID_DFR0_MPROFDBG_Pos)

/* -----------------------------------------------------------------------------
 * 16.4 ID_MMFR0 寄存器位域 (ARM_V8M_SCB_ID_MMFR0)
 * 参考: D1.2.117 ID_MMFR0, Memory Model Feature Register 0
 * -----------------------------------------------------------------------------
 */
/* VMSA - VMSA support, bits[3:0]
   0=不支持, 1=支持PMSA */
#define ARM_V8M_ID_MMFR0_VMSA_Pos       0U
#define ARM_V8M_ID_MMFR0_VMSA_Msk       (0xFUL << ARM_V8M_ID_MMFR0_VMSA_Pos)
/* PMSA - PMSA support, bits[7:4]
   0=不支持, 1=支持PMSA, 3=支持PMSAv7 */
#define ARM_V8M_ID_MMFR0_PMSA_Pos       4U
#define ARM_V8M_ID_MMFR0_PMSA_Msk       (0xFUL << ARM_V8M_ID_MMFR0_PMSA_Pos)
/* Cache coherence - Outer shareable, bits[11:8]
   外部可共享缓存一致性 */
#define ARM_V8M_ID_MMFR0_OUTERSHARE_Pos 8U
#define ARM_V8M_ID_MMFR0_OUTERSHARE_Msk (0xFUL << ARM_V8M_ID_MMFR0_OUTERSHARE_Pos)
/* Inner shareable - Inner shareable, bits[15:12]
   内部可共享 */
#define ARM_V8M_ID_MMFR0_INNERSHARE_Pos 12U
#define ARM_V8M_ID_MMFR0_INNERSHARE_Msk (0xFUL << ARM_V8M_ID_MMFR0_INNERSHARE_Pos)
/* FCSE - FCSE support, bits[19:16]
   FCSE支持 */
#define ARM_V8M_ID_MMFR0_FCSE_Pos       16U
#define ARM_V8M_ID_MMFR0_FCSE_Msk       (0xFUL << ARM_V8M_ID_MMFR0_FCSE_Pos)
/* AuxReg - Auxiliary registers, bits[23:20]
   辅助寄存器 */
#define ARM_V8M_ID_MMFR0_AUXREG_Pos     20U
#define ARM_V8M_ID_MMFR0_AUXREG_Msk     (0xFUL << ARM_V8M_ID_MMFR0_AUXREG_Pos)
/* TCM - TCM support, bits[27:24]
   TCM支持 */
#define ARM_V8M_ID_MMFR0_TCM_Pos        24U
#define ARM_V8M_ID_MMFR0_TCM_Msk        (0xFUL << ARM_V8M_ID_MMFR0_TCM_Pos)

/* -----------------------------------------------------------------------------
 * 16.5 ID_MMFR1 寄存器位域 (ARM_V8M_SCB_ID_MMFR1)
 * 参考: D1.2.118 ID_MMFR1, Memory Model Feature Register 1
 * -----------------------------------------------------------------------------
 */
/* AuxFr - Auxiliary features, bits[3:0]
   辅助特性 */
#define ARM_V8M_ID_MMFR1_AUXFR_Pos       0U
#define ARM_V8M_ID_MMFR1_AUXFR_Msk       (0xFUL << ARM_V8M_ID_MMFR1_AUXFR_Pos)
/* FCSE - Fast Context Switch Extension, bits[7:4]
   FCSE支持 */
#define ARM_V8M_ID_MMFR1_FCSE_Pos        4U
#define ARM_V8M_ID_MMFR1_FCSE_Msk        (0xFUL << ARM_V8M_ID_MMFR1_FCSE_Pos)
/* Unified - Unified memory system, bits[11:8]
   统一内存系统 */
#define ARM_V8M_ID_MMFR1_UNIFIED_Pos     8U
#define ARM_V8M_ID_MMFR1_UNIFIED_Msk     (0xFUL << ARM_V8M_ID_MMFR1_UNIFIED_Pos)
/* BTB - Branch target buffer, bits[15:12]
   分支目标缓冲 */
#define ARM_V8M_ID_MMFR1_BTB_Pos         12U
#define ARM_V8M_ID_MMFR1_BTB_Msk         (0xFUL << ARM_V8M_ID_MMFR1_BTB_Pos)
/* HIPT - Harvard instruction and TLB, bits[19:16]
   哈佛指令和TLB */
#define ARM_V8M_ID_MMFR1_HIPT_Pos        16U
#define ARM_V8M_ID_MMFR1_HIPT_Msk        (0xFUL << ARM_V8M_ID_MMFR1_HIPT_Pos)
/* SMP - Symmetric Multi-Processing, bits[23:20]
   对称多处理 */
#define ARM_V8M_ID_MMFR1_SMP_Pos         20U
#define ARM_V8M_ID_MMFR1_SMP_Msk         (0xFUL << ARM_V8M_ID_MMFR1_SMP_Pos)
/* PMSA - Physical Memory System Architecture, bits[27:24]
   PMSA支持 */
#define ARM_V8M_ID_MMFR1_PMSA_Pos        24U
#define ARM_V8M_ID_MMFR1_PMSA_Msk        (0xFUL << ARM_V8M_ID_MMFR1_PMSA_Pos)
/* VMSA - Virtual Memory System Architecture, bits[31:28]
   VMSA支持 */
#define ARM_V8M_ID_MMFR1_VMSA_Pos        28U
#define ARM_V8M_ID_MMFR1_VMSA_Msk        (0xFUL << ARM_V8M_ID_MMFR1_VMSA_Pos)

/* -----------------------------------------------------------------------------
 * 16.6 ID_MMFR2 寄存器位域 (ARM_V8M_SCB_ID_MMFR2)
 * 参考: D1.2.119 ID_MMFR2, Memory Model Feature Register 2
 * -----------------------------------------------------------------------------
 */
/* WFI - Wait For Interrupt, bits[3:0]
   WFI指令支持 */
#define ARM_V8M_ID_MMFR2_WFI_Pos         0U
#define ARM_V8M_ID_MMFR2_WFI_Msk         (0xFUL << ARM_V8M_ID_MMFR2_WFI_Pos)
/* WFE - Wait For Event, bits[7:4]
   WFE指令支持 */
#define ARM_V8M_ID_MMFR2_WFE_Pos         4U
#define ARM_V8M_ID_MMFR2_WFE_Msk         (0xFUL << ARM_V8M_ID_MMFR2_WFE_Pos)
/* SEV - Send Event, bits[11:8]
   SEV指令支持 */
#define ARM_V8M_ID_MMFR2_SEV_Pos         8U
#define ARM_V8M_ID_MMFR2_SEV_Msk         (0xFUL << ARM_V8M_ID_MMFR2_SEV_Pos)
/* WB - Write-back, bits[15:12]
   写回支持 */
#define ARM_V8M_ID_MMFR2_WB_Pos          12U
#define ARM_V8M_ID_MMFR2_WB_Msk          (0xFUL << ARM_V8M_ID_MMFR2_WB_Pos)
/* SW - Store write-back, bits[19:16]
   存储写回 */
#define ARM_V8M_ID_MMFR2_SW_Pos          16U
#define ARM_V8M_ID_MMFR2_SW_Msk          (0xFUL << ARM_V8M_ID_MMFR2_SW_Pos)
/* HINT - Hint instructions, bits[23:20]
   Hint指令 */
#define ARM_V8M_ID_MMFR2_HINT_Pos        20U
#define ARM_V8M_ID_MMFR2_HINT_Msk        (0xFUL << ARM_V8M_ID_MMFR2_HINT_Pos)
/* DIV0 - Divide by zero, bits[27:24]
   除零 */
#define ARM_V8M_ID_MMFR2_DIV0_Pos        24U
#define ARM_V8M_ID_MMFR2_DIV0_Msk        (0xFUL << ARM_V8M_ID_MMFR2_DIV0_Pos)
/* UNALIGN - Unaligned access, bits[31:28]
   未对齐访问 */
#define ARM_V8M_ID_MMFR2_UNALIGN_Pos     28U
#define ARM_V8M_ID_MMFR2_UNALIGN_Msk     (0xFUL << ARM_V8M_ID_MMFR2_UNALIGN_Pos)

/* -----------------------------------------------------------------------------
 * 16.7 ID_MMFR3 寄存器位域 (ARM_V8M_SCB_ID_MMFR3)
 * 参考: D1.2.120 ID_MMFR3, Memory Model Feature Register 3
 * -----------------------------------------------------------------------------
 */
/* CMO - Cache maintenance operations, bits[3:0]
   缓存维护操作 */
#define ARM_V8M_ID_MMFR3_CMO_Pos         0U
#define ARM_V8M_ID_MMFR3_CMO_Msk         (0xFUL << ARM_V8M_ID_MMFR3_CMO_Pos)
/* SB - Store barrier, bits[7:4]
   存储屏障 */
#define ARM_V8M_ID_MMFR3_SB_Pos          4U
#define ARM_V8M_ID_MMFR3_SB_Msk          (0xFUL << ARM_V8M_ID_MMFR3_SB_Pos)
/* SBZH - Store barrier zeroing hint, bits[11:8]
   存储屏障清零提示 */
#define ARM_V8M_ID_MMFR3_SBZH_Pos        8U
#define ARM_V8M_ID_MMFR3_SBZH_Msk        (0xFUL << ARM_V8M_ID_MMFR3_SBZH_Pos)
/* INVARIANT - Invariant support, bits[15:12]
   不变性支持 */
#define ARM_V8M_ID_MMFR3_INVARIANT_Pos   12U
#define ARM_V8M_ID_MMFR3_INVARIANT_Msk   (0xFUL << ARM_V8M_ID_MMFR3_INVARIANT_Pos)
/* BARRIER - Barrier instructions, bits[19:16]
   屏障指令 */
#define ARM_V8M_ID_MMFR3_BARRIER_Pos     16U
#define ARM_V8M_ID_MMFR3_BARRIER_Msk     (0xFUL << ARM_V8M_ID_MMFR3_BARRIER_Pos)
/* COHERENT - Coherent support, bits[23:20]
   一致性支持 */
#define ARM_V8M_ID_MMFR3_COHERENT_Pos    20U
#define ARM_V8M_ID_MMFR3_COHERENT_Msk    (0xFUL << ARM_V8M_ID_MMFR3_COHERENT_Pos)
/* BCAST - Broadcast support, bits[27:24]
   广播支持 */
#define ARM_V8M_ID_MMFR3_BCAST_Pos       24U
#define ARM_V8M_ID_MMFR3_BCAST_Msk       (0xFUL << ARM_V8M_ID_MMFR3_BCAST_Pos)
/* L1I - Level 1 instruction cache, bits[31:28]
   一级指令缓存 */
#define ARM_V8M_ID_MMFR3_L1I_Pos         28U
#define ARM_V8M_ID_MMFR3_L1I_Msk         (0xFUL << ARM_V8M_ID_MMFR3_L1I_Pos)

/* -----------------------------------------------------------------------------
 * 16.8 ID_ISAR1 寄存器位域 (ARM_V8M_SCB_ID_ISAR1)
 * 参考: D1.2.122 ID_ISAR1, Instruction Set Attribute Register 1
 * -----------------------------------------------------------------------------
 */
/* BFExtend - Bit field extend instructions, bits[3:0]
   位域扩展指令 */
#define ARM_V8M_ID_ISAR1_BFEXTEND_Pos    0U
#define ARM_V8M_ID_ISAR1_BFEXTEND_Msk    (0xFUL << ARM_V8M_ID_ISAR1_BFEXTEND_Pos)
/* IfThen - If-Then instructions, bits[7:4]
   If-Then指令 */
#define ARM_V8M_ID_ISAR1_IFTHEN_Pos      4U
#define ARM_V8M_ID_ISAR1_IFTHEN_Msk      (0xFUL << ARM_V8M_ID_ISAR1_IFTHEN_Pos)
/* LDRDC - LDRDC instruction, bits[11:8]
   LDRDC指令 */
#define ARM_V8M_ID_ISAR1_LDRDC_Pos       8U
#define ARM_V8M_ID_ISAR1_LDRDC_Msk       (0xFUL << ARM_V8M_ID_ISAR1_LDRDC_Pos)
/* LDMSTM - LDM/STM instructions, bits[15:12]
   LDM/STM指令 */
#define ARM_V8M_ID_ISAR1_LDMSTM_Pos      12U
#define ARM_V8M_ID_ISAR1_LDMSTM_Msk      (0xFUL << ARM_V8M_ID_ISAR1_LDMSTM_Pos)
/* Exception - Exception instructions, bits[19:16]
   异常指令 */
#define ARM_V8M_ID_ISAR1_EXCEPTION_Pos   16U
#define ARM_V8M_ID_ISAR1_EXCEPTION_Msk   (0xFUL << ARM_V8M_ID_ISAR1_EXCEPTION_Pos)
/* BXJ - BXJ instruction, bits[23:20]
   BXJ指令 */
#define ARM_V8M_ID_ISAR1_BXJ_Pos         20U
#define ARM_V8M_ID_ISAR1_BXJ_Msk         (0xFUL << ARM_V8M_ID_ISAR1_BXJ_Pos)
/* BX - BX instruction, bits[27:24]
   BX指令 */
#define ARM_V8M_ID_ISAR1_BX_Pos          24U
#define ARM_V8M_ID_ISAR1_BX_Msk          (0xFUL << ARM_V8M_ID_ISAR1_BX_Pos)
/* ThumbCopy - Thumb copy instructions, bits[31:28]
   Thumb复制指令 */
#define ARM_V8M_ID_ISAR1_THUMBCOPY_Pos   28U
#define ARM_V8M_ID_ISAR1_THUMBCOPY_Msk   (0xFUL << ARM_V8M_ID_ISAR1_THUMBCOPY_Pos)

/* -----------------------------------------------------------------------------
 * 16.9 ID_ISAR2 寄存器位域 (ARM_V8M_SCB_ID_ISAR2)
 * 参考: D1.2.123 ID_ISAR2, Instruction Set Attribute Register 2
 * -----------------------------------------------------------------------------
 */
/* PLD - PLD instructions, bits[3:0]
   PLD指令 */
#define ARM_V8M_ID_ISAR2_PLD_Pos         0U
#define ARM_V8M_ID_ISAR2_PLD_Msk         (0xFUL << ARM_V8M_ID_ISAR2_PLD_Pos)
/* PLI - PLI instructions, bits[7:4]
   PLI指令 */
#define ARM_V8M_ID_ISAR2_PLI_Pos         4U
#define ARM_V8M_ID_ISAR2_PLI_Msk         (0xFUL << ARM_V8M_ID_ISAR2_PLI_Pos)
/* Barrier - Barrier instructions, bits[11:8]
   屏障指令 */
#define ARM_V8M_ID_ISAR2_BARRIER_Pos     8U
#define ARM_V8M_ID_ISAR2_BARRIER_Msk     (0xFUL << ARM_V8M_ID_ISAR2_BARRIER_Pos)
/* MSR_MREG - MSR to special registers, bits[15:12]
   MSR到特殊寄存器 */
#define ARM_V8M_ID_ISAR2_MSR_MREG_Pos    12U
#define ARM_V8M_ID_ISAR2_MSR_MREG_Msk    (0xFUL << ARM_V8M_ID_ISAR2_MSR_MREG_Pos)
/* MOVT - MOVT instruction, bits[19:16]
   MOVT指令 */
#define ARM_V8M_ID_ISAR2_MOVT_Pos        16U
#define ARM_V8M_ID_ISAR2_MOVT_Msk        (0xFUL << ARM_V8M_ID_ISAR2_MOVT_Pos)
/* MOVW - MOVW instruction, bits[23:20]
   MOVW指令 */
#define ARM_V8M_ID_ISAR2_MOVW_Pos        20U
#define ARM_V8M_ID_ISAR2_MOVW_Msk        (0xFUL << ARM_V8M_ID_ISAR2_MOVW_Pos)
/* TBB - TBB instruction, bits[27:24]
   TBB指令 */
#define ARM_V8M_ID_ISAR2_TBB_Pos         24U
#define ARM_V8M_ID_ISAR2_TBB_Msk         (0xFUL << ARM_V8M_ID_ISAR2_TBB_Pos)
/* TBH - TBH instruction, bits[31:28]
   TBH指令 */
#define ARM_V8M_ID_ISAR2_TBH_Pos         28U
#define ARM_V8M_ID_ISAR2_TBH_Msk         (0xFUL << ARM_V8M_ID_ISAR2_TBH_Pos)

/* -----------------------------------------------------------------------------
 * 16.10 ID_ISAR3 寄存器位域 (ARM_V8M_SCB_ID_ISAR3)
 * 参考: D1.2.124 ID_ISAR3, Instruction Set Attribute Register 3
 * -----------------------------------------------------------------------------
 */
/* SBFX - SBFX instruction, bits[3:0]
   SBFX指令 */
#define ARM_V8M_ID_ISAR3_SBFX_Pos        0U
#define ARM_V8M_ID_ISAR3_SBFX_Msk        (0xFUL << ARM_V8M_ID_ISAR3_SBFX_Pos)
/* UBFX - UBFX instruction, bits[7:4]
   UBFX指令 */
#define ARM_V8M_ID_ISAR3_UBFX_Pos        4U
#define ARM_V8M_ID_ISAR3_UBFX_Msk        (0xFUL << ARM_V8M_ID_ISAR3_UBFX_Pos)
/* SBFX16 - SBFX16 instruction, bits[11:8]
   SBFX16指令 */
#define ARM_V8M_ID_ISAR3_SBFX16_Pos      8U
#define ARM_V8M_ID_ISAR3_SBFX16_Msk      (0xFUL << ARM_V8M_ID_ISAR3_SBFX16_Pos)
/* UBFX16 - UBFX16 instruction, bits[15:12]
   UBFX16指令 */
#define ARM_V8M_ID_ISAR3_UBFX16_Pos      12U
#define ARM_V8M_ID_ISAR3_UBFX16_Msk      (0xFUL << ARM_V8M_ID_ISAR3_UBFX16_Pos)
/* SBFX32 - SBFX32 instruction, bits[19:16]
   SBFX32指令 */
#define ARM_V8M_ID_ISAR3_SBFX32_Pos      16U
#define ARM_V8M_ID_ISAR3_SBFX32_Msk      (0xFUL << ARM_V8M_ID_ISAR3_SBFX32_Pos)
/* UBFX32 - UBFX32 instruction, bits[23:20]
   UBFX32指令 */
#define ARM_V8M_ID_ISAR3_UBFX32_Pos      20U
#define ARM_V8M_ID_ISAR3_UBFX32_Msk      (0xFUL << ARM_V8M_ID_ISAR3_UBFX32_Pos)
/* BFC - BFC instruction, bits[27:24]
   BFC指令 */
#define ARM_V8M_ID_ISAR3_BFC_Pos         24U
#define ARM_V8M_ID_ISAR3_BFC_Msk         (0xFUL << ARM_V8M_ID_ISAR3_BFC_Pos)
/* BFI - BFI instruction, bits[31:28]
   BFI指令 */
#define ARM_V8M_ID_ISAR3_BFI_Pos         28U
#define ARM_V8M_ID_ISAR3_BFI_Msk         (0xFUL << ARM_V8M_ID_ISAR3_BFI_Pos)

/* -----------------------------------------------------------------------------
 * 16.11 ID_ISAR4 寄存器位域 (ARM_V8M_SCB_ID_ISAR4)
 * 参考: D1.2.125 ID_ISAR4, Instruction Set Attribute Register 4
 * -----------------------------------------------------------------------------
 */
/* WFE - WFE instruction, bits[3:0]
   WFE指令 */
#define ARM_V8M_ID_ISAR4_WFE_Pos         0U
#define ARM_V8M_ID_ISAR4_WFE_Msk         (0xFUL << ARM_V8M_ID_ISAR4_WFE_Pos)
/* WFI - WFI instruction, bits[7:4]
   WFI指令 */
#define ARM_V8M_ID_ISAR4_WFI_Pos         4U
#define ARM_V8M_ID_ISAR4_WFI_Msk         (0xFUL << ARM_V8M_ID_ISAR4_WFI_Pos)
/* SEV - SEV instruction, bits[11:8]
   SEV指令 */
#define ARM_V8M_ID_ISAR4_SEV_Pos         8U
#define ARM_V8M_ID_ISAR4_SEV_Msk         (0xFUL << ARM_V8M_ID_ISAR4_SEV_Pos)
/* CLZ - CLZ instruction, bits[15:12]
   CLZ指令 */
#define ARM_V8M_ID_ISAR4_CLZ_Pos         12U
#define ARM_V8M_ID_ISAR4_CLZ_Msk         (0xFUL << ARM_V8M_ID_ISAR4_CLZ_Pos)
/* QADD - QADD instruction, bits[19:16]
   QADD指令 */
#define ARM_V8M_ID_ISAR4_QADD_Pos        16U
#define ARM_V8M_ID_ISAR4_QADD_Msk        (0xFUL << ARM_V8M_ID_ISAR4_QADD_Pos)
/* QDADD - QDADD instruction, bits[23:20]
   QDADD指令 */
#define ARM_V8M_ID_ISAR4_QDADD_Pos       20U
#define ARM_V8M_ID_ISAR4_QDADD_Msk       (0xFUL << ARM_V8M_ID_ISAR4_QDADD_Pos)
/* QDSUB - QDSUB instruction, bits[27:24]
   QDSUB指令 */
#define ARM_V8M_ID_ISAR4_QDSUB_Pos       24U
#define ARM_V8M_ID_ISAR4_QDSUB_Msk       (0xFUL << ARM_V8M_ID_ISAR4_QDSUB_Pos)
/* QSUB - QSUB instruction, bits[31:28]
   QSUB指令 */
#define ARM_V8M_ID_ISAR4_QSUB_Pos        28U
#define ARM_V8M_ID_ISAR4_QSUB_Msk        (0xFUL << ARM_V8M_ID_ISAR4_QSUB_Pos)

/* -----------------------------------------------------------------------------
 * 16.12 ID_ISAR5 寄存器位域 (ARM_V8M_SCB_ID_ISAR5)
 * 参考: D1.2.126 ID_ISAR5, Instruction Set Attribute Register 5
 * -----------------------------------------------------------------------------
 */
/* RBIT - RBIT instruction, bits[3:0]
   RBIT指令 */
#define ARM_V8M_ID_ISAR5_RBIT_Pos        0U
#define ARM_V8M_ID_ISAR5_RBIT_Msk        (0xFUL << ARM_V8M_ID_ISAR5_RBIT_Pos)
/* REV - REV instruction, bits[7:4]
   REV指令 */
#define ARM_V8M_ID_ISAR5_REV_Pos         4U
#define ARM_V8M_ID_ISAR5_REV_Msk         (0xFUL << ARM_V8M_ID_ISAR5_REV_Pos)
/* REV16 - REV16 instruction, bits[11:8]
   REV16指令 */
#define ARM_V8M_ID_ISAR5_REV16_Pos       8U
#define ARM_V8M_ID_ISAR5_REV16_Msk       (0xFUL << ARM_V8M_ID_ISAR5_REV16_Pos)
/* REVSH - REVSH instruction, bits[15:12]
   REVSH指令 */
#define ARM_V8M_ID_ISAR5_REVSH_Pos       12U
#define ARM_V8M_ID_ISAR5_REVSH_Msk       (0xFUL << ARM_V8M_ID_ISAR5_REVSH_Pos)
/* SEL - SEL instruction, bits[19:16]
   SEL指令 */
#define ARM_V8M_ID_ISAR5_SEL_Pos         16U
#define ARM_V8M_ID_ISAR5_SEL_Msk         (0xFUL << ARM_V8M_ID_ISAR5_SEL_Pos)
/* SXTB - SXTB instruction, bits[23:20]
   SXTB指令 */
#define ARM_V8M_ID_ISAR5_SXTB_Pos        20U
#define ARM_V8M_ID_ISAR5_SXTB_Msk        (0xFUL << ARM_V8M_ID_ISAR5_SXTB_Pos)
/* SXTH - SXTH instruction, bits[27:24]
   SXTH指令 */
#define ARM_V8M_ID_ISAR5_SXTH_Pos        24U
#define ARM_V8M_ID_ISAR5_SXTH_Msk        (0xFUL << ARM_V8M_ID_ISAR5_SXTH_Pos)
/* UXTB - UXTB instruction, bits[31:28]
   UXTB指令 */
#define ARM_V8M_ID_ISAR5_UXTB_Pos        28U
#define ARM_V8M_ID_ISAR5_UXTB_Msk        (0xFUL << ARM_V8M_ID_ISAR5_UXTB_Pos)

/* -----------------------------------------------------------------------------
 * 16.13 ID_AFR0 寄存器位域 (ARM_V8M_SCB_ID_AFR0)
 * 参考: D1.2.110 ID_AFR0, Auxiliary Feature Register 0
 * -----------------------------------------------------------------------------
 */
/* ID_AFR0 - 辅助特性寄存器，内容为 IMPLEMENTATION DEFINED */

/* ==============================================================================
 * 十七、PID/CID 寄存器位域
 * 地址范围: 0xE000E000 偏移 0xEFB0-0xEFFC
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 17.1 PID 寄存器位域
 * 参考: D1.2 寄存器描述
 * -----------------------------------------------------------------------------
 */
/* PID0 - PARTNUM - Part number, bits[7:0]
   部件号 */
#define ARM_V8M_PID0_PARTNUM_Pos        0U
#define ARM_V8M_PID0_PARTNUM_Msk        (0xFFUL << ARM_V8M_PID0_PARTNUM_Pos)

/* PID1 - PARTNUM - Part number, bits[3:0]
   部件号高位 */
#define ARM_V8M_PID1_PARTNUM_Pos        0U
#define ARM_V8M_PID1_PARTNUM_Msk        (0xFUL << ARM_V8M_PID1_PARTNUM_Pos)
/* PID1 - JEPID - JEP106 ID, bits[7:4]
   JEP106 ID */
#define ARM_V8M_PID1_JEPID_Pos          4U
#define ARM_V8M_PID1_JEPID_Msk          (0xFUL << ARM_V8M_PID1_JEPID_Pos)

/* PID2 - JEPID - JEP106 ID, bits[2:0]
   JEP106 ID */
#define ARM_V8M_PID2_JEPID_Pos          0U
#define ARM_V8M_PID2_JEPID_Msk          (0x7UL << ARM_V8M_PID2_JEPID_Pos)
/* PID2 - JEPIDCN - JEP106 ID continuation, bit[3]
   JEP106 ID连续码 */
#define ARM_V8M_PID2_JEPIDCN_Pos        3U
#define ARM_V8M_PID2_JEPIDCN_Msk        (1UL << ARM_V8M_PID2_JEPIDCN_Pos)
/* PID2 - REVISION - Revision, bits[7:4]
   修订版本号 */
#define ARM_V8M_PID2_REVISION_Pos       4U
#define ARM_V8M_PID2_REVISION_Msk       (0xFUL << ARM_V8M_PID2_REVISION_Pos)

/* PID3 - CMOD - Component modification, bits[3:0]
   组件修改 */
#define ARM_V8M_PID3_CMOD_Pos           0U
#define ARM_V8M_PID3_CMOD_Msk           (0xFUL << ARM_V8M_PID3_CMOD_Pos)
/* PID3 - REVAND - Revision and, bits[7:4]
   修订和 */
#define ARM_V8M_PID3_REVAND_Pos         4U
#define ARM_V8M_PID3_REVAND_Msk         (0xFUL << ARM_V8M_PID3_REVAND_Pos)

/* PID4 - JEP106C - JEP106 continuation code, bits[3:0]
   JEP106连续码 */
#define ARM_V8M_PID4_JEP106C_Pos        0U
#define ARM_V8M_PID4_JEP106C_Msk        (0xFUL << ARM_V8M_PID4_JEP106C_Pos)
/* PID4 - SIZE - Size, bits[7:4]
   大小 */
#define ARM_V8M_PID4_SIZE_Pos           4U
#define ARM_V8M_PID4_SIZE_Msk           (0xFUL << ARM_V8M_PID4_SIZE_Pos)

/* PID5-7 - Reserved, reads as zero (RAZ) */

/* -----------------------------------------------------------------------------
 * 17.2 CID 寄存器位域
 * 参考: D1.2 寄存器描述
 * -----------------------------------------------------------------------------
 */
/* CID0 - PREAMBLE - Preamble, bits[7:0] (fixed value 0x0D)
   序言字节 */
#define ARM_V8M_CID0_PREAMBLE_Pos       0U
#define ARM_V8M_CID0_PREAMBLE_Msk       (0xFFUL << ARM_V8M_CID0_PREAMBLE_Pos)

/* CID1 - PREAMBLE - Preamble, bits[3:0] (fixed value 0x00)
   序言字节 */
#define ARM_V8M_CID1_PREAMBLE_Pos       0U
#define ARM_V8M_CID1_PREAMBLE_Msk       (0xFUL << ARM_V8M_CID1_PREAMBLE_Pos)
/* CID1 - CLASS - Component class, bits[7:4] (0x1=ARM component)
   组件类 */
#define ARM_V8M_CID1_CLASS_Pos          4U
#define ARM_V8M_CID1_CLASS_Msk          (0xFUL << ARM_V8M_CID1_CLASS_Pos)

/* CID2 - PREAMBLE - Preamble, bits[7:0] (fixed value 0x05)
   序言字节 */
#define ARM_V8M_CID2_PREAMBLE_Pos       0U
#define ARM_V8M_CID2_PREAMBLE_Msk       (0xFFUL << ARM_V8M_CID2_PREAMBLE_Pos)

/* CID3 - PREAMBLE - Preamble, bits[7:0] (fixed value 0xB1)
   序言字节 */
#define ARM_V8M_CID3_PREAMBLE_Pos       0U
#define ARM_V8M_CID3_PREAMBLE_Msk       (0xFFUL << ARM_V8M_CID3_PREAMBLE_Pos)

/* ==============================================================================
 * 十八、ITM 补充寄存器位域
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 18.1 ITM_STIM 寄存器位域 (ARM_V8M_ITM_STIM)
 * 参考: D1.2.130 ITM_STIM0-ITM_STIM255, Stimulus Port Registers 0-255
 * -----------------------------------------------------------------------------
 */
/* FIFOREADY - FIFO ready, bit[0]
   FIFO就绪标志 */
#define ARM_V8M_ITM_STIM_FIFOREADY_Pos  0U
#define ARM_V8M_ITM_STIM_FIFOREADY_Msk  (1UL << ARM_V8M_ITM_STIM_FIFOREADY_Pos)
/* STIMULUS - Stimulus port data, bits[31:1]
   激励端口数据 */
#define ARM_V8M_ITM_STIM_STIMULUS_Pos   1U
#define ARM_V8M_ITM_STIM_STIMULUS_Msk   (0x7FFFFFFUL << ARM_V8M_ITM_STIM_STIMULUS_Pos)

/* -----------------------------------------------------------------------------
 * 18.2 ITM_TER 寄存器位域 (ARM_V8M_ITM_TER)
 * 参考: D1.2.133 ITM_TER0-ITM_TER7, Trace Enable Registers 0-7
 * -----------------------------------------------------------------------------
 */
/* 对于 ITM_TER(n)，每个位的宏定义 (n=0-7, bit=0-31)
   示例：ARM_V8M_ITM_TER_EN(0, 5) 表示 ITM_TER0 的位 5，控制 STIM5 */
#define ARM_V8M_ITM_TER_EN(n, bit)        (1UL << (bit))  /* Stimulus port 32n+bit enable */

/* ==============================================================================
 * 十九、DWT 补充寄存器位域
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 19.1 DWT_CYCCNT 寄存器位域 (ARM_V8M_DWT_CYCCNT)
 * 参考: D1.2.67 DWT_CYCCNT, DWT Cycle Count Register
 * -----------------------------------------------------------------------------
 */
/* CYCCNT - Cycle count, bits[31:0]
   周期计数 */
#define ARM_V8M_DWT_CYCCNT_CYCCNT_Pos   0U
#define ARM_V8M_DWT_CYCCNT_CYCCNT_Msk   (0xFFFFFFFFUL << ARM_V8M_DWT_CYCCNT_CYCCNT_Pos)

/* -----------------------------------------------------------------------------
 * 19.2 DWT_CPICNT 寄存器位域 (ARM_V8M_DWT_CPICNT)
 * 参考: D1.2.66 DWT_CPICNT, DWT CPI Count Register
 * -----------------------------------------------------------------------------
 */
/* CPICNT - CPI count, bits[7:0]
   CPI计数 */
#define ARM_V8M_DWT_CPICNT_CPICNT_Pos   0U
#define ARM_V8M_DWT_CPICNT_CPICNT_Msk   (0xFFUL << ARM_V8M_DWT_CPICNT_CPICNT_Pos)

/* -----------------------------------------------------------------------------
 * 19.3 DWT_EXCCNT 寄存器位域 (ARM_V8M_DWT_EXCCNT)
 * 参考: D1.2.68 DWT_EXCCNT, DWT Exception Overhead Count Register
 * -----------------------------------------------------------------------------
 */
/* EXCCNT - Exception overhead count, bits[7:0]
   异常开销计数 */
#define ARM_V8M_DWT_EXCCNT_EXCCNT_Pos   0U
#define ARM_V8M_DWT_EXCCNT_EXCCNT_Msk   (0xFFUL << ARM_V8M_DWT_EXCCNT_EXCCNT_Pos)

/* -----------------------------------------------------------------------------
 * 19.4 DWT_SLEEPCNT 寄存器位域 (ARM_V8M_DWT_SLEEPCNT)
 * 参考: D1.2.77 DWT_SLEEPCNT, DWT Sleep Count Register
 * -----------------------------------------------------------------------------
 */
/* SLEEPCNT - Sleep count, bits[7:0]
   睡眠计数 */
#define ARM_V8M_DWT_SLEEPCNT_SLEEPCNT_Pos 0U
#define ARM_V8M_DWT_SLEEPCNT_SLEEPCNT_Msk (0xFFUL << ARM_V8M_DWT_SLEEPCNT_SLEEPCNT_Pos)

/* -----------------------------------------------------------------------------
 * 19.5 DWT_LSUCNT 寄存器位域 (ARM_V8M_DWT_LSUCNT)
 * 参考: D1.2.72 DWT_LSUCNT, DWT LSU Count Register
 * -----------------------------------------------------------------------------
 */
/* LSUCNT - LSU count, bits[7:0]
   LSU计数 */
#define ARM_V8M_DWT_LSUCNT_LSUCNT_Pos   0U
#define ARM_V8M_DWT_LSUCNT_LSUCNT_Msk   (0xFFUL << ARM_V8M_DWT_LSUCNT_LSUCNT_Pos)

/* -----------------------------------------------------------------------------
 * 19.6 DWT_FOLDCNT 寄存器位域 (ARM_V8M_DWT_FOLDCNT)
 * 参考: D1.2.70 DWT_FOLDCNT, DWT Folded-instruction Count Register
 * -----------------------------------------------------------------------------
 */
/* FOLDCNT - Folded-instruction count, bits[7:0]
   折叠指令计数 */
#define ARM_V8M_DWT_FOLDCNT_FOLDCNT_Pos 0U
#define ARM_V8M_DWT_FOLDCNT_FOLDCNT_Msk (0xFFUL << ARM_V8M_DWT_FOLDCNT_FOLDCNT_Pos)

/* -----------------------------------------------------------------------------
 * 19.7 DWT_PCSR 寄存器位域 (ARM_V8M_DWT_PCSR)
 * 参考: D1.2.75 DWT_PCSR, DWT Program Counter Sample Register
 * -----------------------------------------------------------------------------
 */
/* PCSAMPLE - PC sample, bits[31:0]
   PC采样值 */
#define ARM_V8M_DWT_PCSR_PCSAMPLE_Pos   0U
#define ARM_V8M_DWT_PCSR_PCSAMPLE_Msk   (0xFFFFFFFFUL << ARM_V8M_DWT_PCSR_PCSAMPLE_Pos)

/* -----------------------------------------------------------------------------
 * 19.8 DWT_COMPn 寄存器位域 (ARM_V8M_DWT_COMPn)
 * 参考: D1.2.65 DWT_COMPn, DWT Comparator Register n
 * -----------------------------------------------------------------------------
 */
/* COMP - Comparator, bits[31:0]
   比较器值 */
#define ARM_V8M_DWT_COMP_COMP_Pos       0U
#define ARM_V8M_DWT_COMP_COMP_Msk       (0xFFFFFFFFUL << ARM_V8M_DWT_COMP_COMP_Pos)

/* -----------------------------------------------------------------------------
 * 19.9 DWT_MASKn 寄存器位域 (ARM_V8M_DWT_MASKn)
 * 参考: D1.2.73 DWT_MASKn, DWT Comparator Mask Register n
 * -----------------------------------------------------------------------------
 */
/* MASK - Comparator mask, bits[4:0]
   比较器掩码 */
#define ARM_V8M_DWT_MASK_MASK_Pos       0U
#define ARM_V8M_DWT_MASK_MASK_Msk       (0x1FUL << ARM_V8M_DWT_MASK_MASK_Pos)

/* ==============================================================================
 * 二十、调试锁定寄存器位域 (LAR/LSR)
 * ============================================================================== */

/* -----------------------------------------------------------------------------
 * 20.1 DWT_LAR 寄存器位域 (ARM_V8M_DWT_LAR)
 * 参考: D1.2.71 DWT_LAR, DWT Lock Access Register
 * -----------------------------------------------------------------------------
 */
/* LOCK - Lock value (write 0xC5ACCE55 to unlock), bits[31:0]
   锁定值：写入0xC5ACCE55解锁 */
#define ARM_V8M_DWT_LAR_LOCK_Pos        0U
#define ARM_V8M_DWT_LAR_LOCK_Msk        (0xFFFFFFFFUL << ARM_V8M_DWT_LAR_LOCK_Pos)

/* -----------------------------------------------------------------------------
 * 20.2 DWT_LSR 寄存器位域 (ARM_V8M_DWT_LSR)
 * 参考: D1.2.74 DWT_LSR, DWT Lock Status Register
 * -----------------------------------------------------------------------------
 */
/* LOCKED - Locked status, bit[1]
   锁定状态 */
#define ARM_V8M_DWT_LSR_LOCKED_Pos      1U
#define ARM_V8M_DWT_LSR_LOCKED_Msk      (1UL << ARM_V8M_DWT_LSR_LOCKED_Pos)
/* PRESENT - Present status, bit[0]
   存在状态 */
#define ARM_V8M_DWT_LSR_PRESENT_Pos     0U
#define ARM_V8M_DWT_LSR_PRESENT_Msk     (1UL << ARM_V8M_DWT_LSR_PRESENT_Pos)

/* -----------------------------------------------------------------------------
 * 20.3 ITM_LAR 寄存器位域 (ARM_V8M_ITM_LAR)
 * 参考: D1.2.128 ITM_LAR, ITM Lock Access Register
 * -----------------------------------------------------------------------------
 */
/* LOCK - Lock value (write 0xC5ACCE55 to unlock), bits[31:0]
   锁定值：写入0xC5ACCE55解锁 */
#define ARM_V8M_ITM_LAR_LOCK_Pos        0U
#define ARM_V8M_ITM_LAR_LOCK_Msk        (0xFFFFFFFFUL << ARM_V8M_ITM_LAR_LOCK_Pos)

/* -----------------------------------------------------------------------------
 * 20.4 ITM_LSR 寄存器位域 (ARM_V8M_ITM_LSR)
 * 参考: D1.2.129 ITM_LSR, ITM Lock Status Register
 * -----------------------------------------------------------------------------
 */
/* LOCKED - Locked status, bit[1]
   锁定状态 */
#define ARM_V8M_ITM_LSR_LOCKED_Pos      1U
#define ARM_V8M_ITM_LSR_LOCKED_Msk      (1UL << ARM_V8M_ITM_LSR_LOCKED_Pos)
/* PRESENT - Present status, bit[0]
   存在状态 */
#define ARM_V8M_ITM_LSR_PRESENT_Pos     0U
#define ARM_V8M_ITM_LSR_PRESENT_Msk     (1UL << ARM_V8M_ITM_LSR_PRESENT_Pos)

/* -----------------------------------------------------------------------------
 * 20.5 FPB_LAR 寄存器位域 (ARM_V8M_FPB_LAR)
 * 参考: D1.2.87 FPB_LAR, FPB Lock Access Register
 * -----------------------------------------------------------------------------
 */
/* LOCK - Lock value (write 0xC5ACCE55 to unlock), bits[31:0]
   锁定值：写入0xC5ACCE55解锁 */
#define ARM_V8M_FPB_LAR_LOCK_Pos        0U
#define ARM_V8M_FPB_LAR_LOCK_Msk        (0xFFFFFFFFUL << ARM_V8M_FPB_LAR_LOCK_Pos)

/* -----------------------------------------------------------------------------
 * 20.6 FPB_LSR 寄存器位域 (ARM_V8M_FPB_LSR)
 * 参考: D1.2.88 FPB_LSR, FPB Lock Status Register
 * -----------------------------------------------------------------------------
 */
/* LOCKED - Locked status, bit[1]
   锁定状态 */
#define ARM_V8M_FPB_LSR_LOCKED_Pos      1U
#define ARM_V8M_FPB_LSR_LOCKED_Msk      (1UL << ARM_V8M_FPB_LSR_LOCKED_Pos)
/* PRESENT - Present status, bit[0]
   存在状态 */
#define ARM_V8M_FPB_LSR_PRESENT_Pos     0U
#define ARM_V8M_FPB_LSR_PRESENT_Msk     (1UL << ARM_V8M_FPB_LSR_PRESENT_Pos)

/* -----------------------------------------------------------------------------
 * 20.7 TPIU_LAR 寄存器位域 (ARM_V8M_TPIU_LAR)
 * 参考: D1.2.228 TPIU_LAR, TPIU Lock Access Register
 * -----------------------------------------------------------------------------
 */
/* LOCK - Lock value (write 0xC5ACCE55 to unlock), bits[31:0]
   锁定值：写入0xC5ACCE55解锁 */
#define ARM_V8M_TPIU_LAR_LOCK_Pos       0U
#define ARM_V8M_TPIU_LAR_LOCK_Msk       (0xFFFFFFFFUL << ARM_V8M_TPIU_LAR_LOCK_Pos)

/* -----------------------------------------------------------------------------
 * 20.8 TPIU_LSR 寄存器位域 (ARM_V8M_TPIU_LSR)
 * 参考: D1.2.231 TPIU_LSR, TPIU Lock Status Register
 * -----------------------------------------------------------------------------
 */
/* LOCKED - Locked status, bit[1]
   锁定状态 */
#define ARM_V8M_TPIU_LSR_LOCKED_Pos     1U
#define ARM_V8M_TPIU_LSR_LOCKED_Msk     (1UL << ARM_V8M_TPIU_LSR_LOCKED_Pos)
/* PRESENT - Present status, bit[0]
   存在状态 */
#define ARM_V8M_TPIU_LSR_PRESENT_Pos    0U
#define ARM_V8M_TPIU_LSR_PRESENT_Msk    (1UL << ARM_V8M_TPIU_LSR_PRESENT_Pos)

/* ==============================================================================
 * 二十.1 调试锁定寄存器值定义宏
 * 非寄存器位域宏，用于定义 LAR 寄存器的解锁值
 * ==============================================================================
 */
#define ARM_V8M_DWT_LAR_LOCK_VALUE        0xC5ACCE55UL
#define ARM_V8M_ITM_LAR_LOCK_VALUE        0xC5ACCE55UL
#define ARM_V8M_FPB_LAR_LOCK_VALUE        0xC5ACCE55UL
#define ARM_V8M_TPIU_LAR_LOCK_VALUE       0xC5ACCE55UL

/* ==============================================================================
 * 二十一、异常返回负载 (Exception Return Payload)
 * 参考: D1.2.96 EXC_RETURN, D1.2.98 FNC_RETURN
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 21.1 EXC_RETURN 位域定义
 * 参考: D1.2.96 EXC_RETURN, Exception Return Payload
 * EXC_RETURN 是异常返回时 LR 中的特殊值，用于指示返回行为
 * -----------------------------------------------------------------------------
 */
/* PREFIX - EXC_RETURN prefix, bits[31:24]
   前缀，固定为 0xFF，用于识别 EXC_RETURN 值 */
#define ARM_V8M_EXC_RETURN_PREFIX_Pos      24U
#define ARM_V8M_EXC_RETURN_PREFIX_Msk      (0xFFUL << ARM_V8M_EXC_RETURN_PREFIX_Pos)
#define ARM_V8M_EXC_RETURN_PREFIX_VALUE    (0xFFUL << ARM_V8M_EXC_RETURN_PREFIX_Pos)

/* RES1 - Reserved bits, bits[23:7]
   保留位，固定为 1 */
#define ARM_V8M_EXC_RETURN_RES1_Pos        7U
#define ARM_V8M_EXC_RETURN_RES1_Msk        (0x1FFFFUL << ARM_V8M_EXC_RETURN_RES1_Pos)

/* S - Secure stack, bit[6]
   【v8m 独有】指示使用 Secure 还是 Non-secure 栈: 0=Non-secure, 1=Secure */
#define ARM_V8M_EXC_RETURN_S_Pos           6U
#define ARM_V8M_EXC_RETURN_S_Msk           (1UL << ARM_V8M_EXC_RETURN_S_Pos)

/* DCRS - Default callee register stacking, bit[5]
   【v8m 独有】默认被调用者寄存器压栈: 0=跳过, 1=默认规则 */
#define ARM_V8M_EXC_RETURN_DCRS_Pos        5U
#define ARM_V8M_EXC_RETURN_DCRS_Msk        (1UL << ARM_V8M_EXC_RETURN_DCRS_Pos)

/* FType - Stack frame type, bit[4]
   栈帧类型: 0=扩展栈帧(含浮点), 1=标准栈帧(仅整数) */
#define ARM_V8M_EXC_RETURN_FTYPE_Pos       4U
#define ARM_V8M_EXC_RETURN_FTYPE_Msk       (1UL << ARM_V8M_EXC_RETURN_FTYPE_Pos)

/* Mode - Processor mode, bit[3]
   处理器模式: 0=Handler mode, 1=Thread mode */
#define ARM_V8M_EXC_RETURN_MODE_Pos        3U
#define ARM_V8M_EXC_RETURN_MODE_Msk        (1UL << ARM_V8M_EXC_RETURN_MODE_Pos)

/* SPSEL - Stack pointer selection, bit[2]
   栈指针选择: 0=Main stack (MSP), 1=Process stack (PSP) */
#define ARM_V8M_EXC_RETURN_SPSEL_Pos       2U
#define ARM_V8M_EXC_RETURN_SPSEL_Msk       (1UL << ARM_V8M_EXC_RETURN_SPSEL_Pos)

/* RES0 - Reserved bit, bit[1]
   保留位，固定为 0 */

/* ES - Exception Secure, bit[0]
   【v8m 独有】异常安全状态: 0=Non-secure, 1=Secure */
#define ARM_V8M_EXC_RETURN_ES_Pos          0U
#define ARM_V8M_EXC_RETURN_ES_Msk          (1UL << ARM_V8M_EXC_RETURN_ES_Pos)

/* EXC_RETURN 常用值定义 */
#define ARM_V8M_EXC_RETURN_HANDLER_MSP     0xFFFFFFF1UL  /* 返回 Handler mode, 使用 MSP */
#define ARM_V8M_EXC_RETURN_THREAD_MSP      0xFFFFFFF9UL  /* 返回 Thread mode, 使用 MSP */
#define ARM_V8M_EXC_RETURN_THREAD_PSP      0xFFFFFFFDUL  /* 返回 Thread mode, 使用 PSP */
#define ARM_V8M_EXC_RETURN_HANDLER_MSP_S   0xFFFFFFE1UL  /* 返回 Secure Handler mode, 使用 MSP_S */
#define ARM_V8M_EXC_RETURN_THREAD_MSP_S    0xFFFFFFE9UL  /* 返回 Secure Thread mode, 使用 MSP_S */
#define ARM_V8M_EXC_RETURN_THREAD_PSP_S    0xFFFFFFEDUL  /* 返回 Secure Thread mode, 使用 PSP_S */
#define ARM_V8M_EXC_RETURN_THREAD_MSP_NS   0xFFFFFFE5UL  /* 返回 Non-secure Thread mode, 使用 MSP_NS */
#define ARM_V8M_EXC_RETURN_THREAD_PSP_NS   0xFFFFFFEDUL  /* 返回 Non-secure Thread mode, 使用 PSP_NS */

/* -----------------------------------------------------------------------------
 * 21.2 FNC_RETURN 位域定义
 * 参考: D1.2.98 FNC_RETURN, Function Return Payload
 * FNC_RETURN 是从 Secure BLXNS 调用 Non-secure 函数时 LR 中的特殊值
 * 【v8m 独有】
 * -----------------------------------------------------------------------------
 */
/* PREFIX - FNC_RETURN prefix, bits[31:24]
   前缀，固定为 0xFE，用于识别 FNC_RETURN 值 */
#define ARM_V8M_FNC_RETURN_PREFIX_Pos      24U
#define ARM_V8M_FNC_RETURN_PREFIX_Msk      (0xFFUL << ARM_V8M_FNC_RETURN_PREFIX_Pos)
#define ARM_V8M_FNC_RETURN_PREFIX_VALUE    (0xFEUL << ARM_V8M_FNC_RETURN_PREFIX_Pos)

/* ONES - Reserved bits (ones), bits[23:1]
   保留位，固定为 1 */
#define ARM_V8M_FNC_RETURN_ONES_Pos        1U
#define ARM_V8M_FNC_RETURN_ONES_Msk        (0x7FFFFFUL << ARM_V8M_FNC_RETURN_ONES_Pos)

/* S - Secure, bit[0]
   安全状态: 0=从 Non-secure 调用, 1=从 Secure 调用 */
#define ARM_V8M_FNC_RETURN_S_Pos           0U
#define ARM_V8M_FNC_RETURN_S_Msk           (1UL << ARM_V8M_FNC_RETURN_S_Pos)

/* FNC_RETURN 常用值定义 */
#define ARM_V8M_FNC_RETURN_VALUE           0xFEFFFFFFUL  /* FNC_RETURN 标准值 */

/* ==============================================================================
 * 二十二、指针认证密钥寄存器位域 (PACBTI Extension)
 * 参考: D1.2.189 PAC_KEY_P_n, D1.2.190 PAC_KEY_U_n
 * 【v8m 独有】仅当 PACBTI Extension 实现时存在
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 22.1 PAC_KEY_P_n 寄存器位域 (ARM_V8M_PAC_KEY_P_n)
 * 参考: D1.2.189 PAC_KEY_P_n, Pointer Authentication Key Privileged, n = 0 - 3
 * -----------------------------------------------------------------------------
 */
/* VALUE - Pointer authentication key, bits[31:0]
   指针认证密钥，第n个字，保存128位密钥的 bits[31 + 32n:32n] */
#define ARM_V8M_PAC_KEY_P_VALUE_Pos        0U
#define ARM_V8M_PAC_KEY_P_VALUE_Msk        (0xFFFFFFFFUL << ARM_V8M_PAC_KEY_P_VALUE_Pos)

/* -----------------------------------------------------------------------------
 * 22.2 PAC_KEY_U_n 寄存器位域 (ARM_V8M_PAC_KEY_U_n)
 * 参考: D1.2.190 PAC_KEY_U_n, Pointer Authentication Key Unprivileged, n = 0 - 3
 * -----------------------------------------------------------------------------
 */
/* VALUE - Pointer authentication key, bits[31:0]
   指针认证密钥，第n个字，保存128位密钥的 bits[31 + 32n:32n] */
#define ARM_V8M_PAC_KEY_U_VALUE_Pos        0U
#define ARM_V8M_PAC_KEY_U_VALUE_Msk        (0xFFFFFFFFUL << ARM_V8M_PAC_KEY_U_VALUE_Pos)

#ifdef __cplusplus
}
#endif

#endif /* __ARM_V8M_MACRO_H__ */