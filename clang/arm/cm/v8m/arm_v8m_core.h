/********************************************************************************
 * @file        arm_v8m_core.h
 * @brief       ARMv8-M Architecture Register Definitions
 * @details     基于 ARMv8-M Architecture Reference Manual (ARM DDI 0553B.z)
 *              所有寄存器定义严格参考手册章节位置
 *              文档路径：g:\develop\FeatherCore\FeatherArch\docs\arm\Arm® v8-M Architecture Reference Manual.txt
 * @author      FeatherCore
 * @version     1.0.0
 * @date        2026-03-29
 * @note        本文件包含 ARMv8-M 公共寄存器偏移定义（与安全/非安全状态无关）
 *              安全状态基地址定义在 arm_v8m_core_safe.h 中
 *              非安全状态基地址定义在 arm_v8m_core_unsafe.h 中
 *              位域定义在单独的头文件中
 *
 * 寄存器覆盖清单（基于 D1.1 Register index）：
 * - Arm Core Registers (R0-R15, xPSR, PRIMASK, BASEPRI, FAULTMASK, CONTROL, MSPLIM, PSPLIM)
 *   参考: D1.1.1 Special and general-purpose registers on page D1-1443
 * - Floating-point Extension Registers (S0-S31, D0-D15, FPSCR)
 *   参考: D1.1.1 Special and general-purpose registers on page D1-1443
 * - System Control Space (SCS) Registers - 寄存器偏移定义（公共部分）
 *   参考: D1.1 Register index on page D1-1442
 *   - SCS: ICTR, ACTLR, CPPWR (基地址 0xE000E004 / 0xE002E004 for NS)
 *   - SysTick: SYST_CSR, SYST_RVR, SYST_CVR, SYST_CALIB (基地址 0xE000E010 / 0xE002E010 for NS)
 *   - NVIC: NVIC_ISER, NVIC_ICER, NVIC_ISPR, NVIC_ICPR, NVIC_IABR, NVIC_IPR
 *           (基地址 0xE000E100 / 0xE002E100 for NS)
 *   - SCB: REVIDR (0xE000ECFC), CPUID, ICSR, VTOR, AIRCR, SCR, CCR, SHPR1-3, SHCSR,
 *          CFSR, HFSR, DFSR, MMFAR, BFAR, AFSR, ID_PFR0-1, ID_DFR0, ID_AFR0, ID_MMFR0-3,
 *          ID_ISAR0-5, CLIDR, CTR, CCSIDR, CSSELR (基地址 0xE000ED00 / 0xE002ED00 for NS)
 *          注意: CPACR, NSACR 仅在安全状态下可访问，定义在 arm_v8m_core_safe.h
 *   - MPU: MPU_TYPE, MPU_CTRL, MPU_RNR, MPU_RBAR, MPU_RLAR, MPU_RBAR_A1-A3, MPU_RLAR_A1-A3,
 *          MPU_MAIR0-1 (基地址 0xE000ED90 / 0xE002ED90 for NS)
 *   - SAU: SAU_CTRL, SAU_TYPE, SAU_RNR, SAU_RBAR, SAU_RLAR, SFSR, SFAR
 *          (基地址 0xE000EDD0, Secure only, 定义在 arm_v8m_core_safe.h)
 *   - Debug: DHCSR, DCRDR, DEMCR, DSCEMCR, DAUTHCTRL
 *            (基地址 0xE000EDF0 / 0xE002EDF0 for NS)
 *            注意: DCRSR, DSCSR 仅在安全状态下可访问，定义在 arm_v8m_core_safe.h
 *   - STIR: 软件触发中断寄存器 (基地址 0xE000EF00 / 0xE002EF00 for NS)
 *   - RFSR: RAS 故障状态寄存器 (基地址 0xE000EF04 / 0xE002EF04 for NS)
 *   - FPU: FPCCR, FPCAR, FPDSCR, MVFR0-2 (基地址 0xE000EF34 / 0xE002EF34 for NS)
 *   - Cache Maintenance: ICIALLU, ICIMVAU, DCIMVAC, DCISW, DCCMVAU, DCCMVAC, DCCSW,
 *                       DCCIMVAC, DCCISW, BPIALL (基地址 0xE000EF50 / 0xE002EF50 for NS)
 *   - Debug Identification: DLAR, DLSR, DAUTHSTATUS, DDEVARCH, DDEVTYPE, DPIDR0-7, DCIDR0-3
 *                           (基地址 0xE000EFB0 / 0xE002EFB0 for NS)
 *   参考: D1.1.8 - D1.1.19, D1.1.20 - D1.1.30 (NS alias)
 * - ITM Registers: ITM_STIMn, ITM_TERn, ITM_TPR, ITM_TCR, ITM_LAR, ITM_LSR
 *                  (基地址 0xE0000000 / 0xE0020000 for NS)
 *   参考: D1.1.3 Instrumentation Macrocell on page D1-1444
 * - DWT Registers: DWT_CTRL, DWT_CYCCNT, DWT_CPICNT, DWT_EXCCNT, DWT_SLEEPCNT, DWT_LSUCNT,
 *                  DWT_FOLDCNT, DWT_PCSR, DWT_COMPn, DWT_FUNCTIONn, DWT_VMASKn, DWT_LAR, DWT_LSR
 *                  (基地址 0xE0001000 / 0xE0021000 for NS)
 *   参考: D1.1.4 Data Watchpoint and Trace on page D1-1444
 * - FPB Registers: FP_CTRL, FP_REMAP, FP_COMPn, FP_LAR, FP_LSR
 *                  (基地址 0xE0002000 / 0xE0022000 for NS)
 *   参考: D1.1.5 Flash Patch and Breakpoint on page D1-1445
 * - PMU Registers: PMU_EVCNTRn, PMU_CCNT, PMU_EVTYPERn, PMU_CCFILTR, PMU_CNTENSET, PMU_CNTENCLR,
 *                  PMU_INTENSET, PMU_INTENCLR, PMU_OVSCLR, PMU_SWINC, PMU_OVSSET, PMU_TYPE, PMU_CTRL
 *                  (基地址 0xE0003000 / 0xE0023000 for NS)
 *   参考: D1.1.6 Performance Monitoring Unit on page D1-1445
 * - RAS Registers: ERRFRn, ERRCTRLn, ERRSTATUSn, ERRADDRn, ERRADDR2n, ERRMISCn, ERRGSRn, ERRIIDR, ERRDEVID
 *                  (基地址 0xE0005000 / 0xE0025000 for NS)
 *   参考: D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446
 * - TPIU Registers: TPIU_SSPSR, TPIU_CSPSR, TPIU_ACPR, TPIU_SPPR, TPIU_FFSR, TPIU_FFCR, TPIU_PSCR,
 *                   TPIU_CLAIMSET, TPIU_CLAIMCLR, TPIU_LAR, TPIU_LSR, TPIU_DEVID, TPIU_DEVTYPE
 *                   (基地址 0xE0040000, 安全和非安全共享)
 *   参考: D1.1.31 Trace Port Interface Unit on page D1-1453
 *
 * 文件组织结构：
 * - arm_v8m_core.h: 公共寄存器偏移定义（与安全/非安全状态无关）
 * - arm_v8m_core_safe.h: 安全状态基地址 + 安全特有寄存器偏移（SAU, CPACR, NSACR, DCRSR, DSCSR）
 * - arm_v8m_core_unsafe.h: 非安全状态基地址（非安全状态没有特有寄存器）
 ********************************************************************************/

#ifndef __ARM_V8M_CORE_H__
#define __ARM_V8M_CORE_H__

#ifdef __cplusplus
extern "C" {
#endif

/* ==============================================================================
 * 一、Arm 核心寄存器 (Arm Core Registers)
 * 参考: D1.1.1 Special and general-purpose registers on page D1-1443
 * 说明: 这些寄存器在安全状态和非安全状态下是独立的银行寄存器
 *       但功能描述相同，通过 _S 和 _NS 后缀访问不同实例
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 1.1 通用寄存器 R0-R12
 * 参考: Table D1-1 Arm core register index on page D1-1443
 *      Registers on page B3-69
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_R0              0x00    /* General-purpose register R0 - 通用目的寄存器 0 [RW]
                                               用于函数参数传递 (第 1 个参数)、返回值、临时数据存储
                                               在 AAPCS 调用约定中，R0-R3 用于传递前 4 个参数
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.220 Rn, General-Purpose Register, n = 0 - 12, Registers on page B3-69 */

#define ARM_V8M_REG_R1              0x01    /* General-purpose register R1 - 通用目的寄存器 1 [RW]
                                               用于函数参数传递 (第 2 个参数)、返回值 (64 位返回值的高 32 位)
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.220 Rn, General-Purpose Register, n = 0 - 12, Registers on page B3-69 */

#define ARM_V8M_REG_R2              0x02    /* General-purpose register R2 - 通用目的寄存器 2 [RW]
                                               用于函数参数传递 (第 3 个参数)、临时数据存储
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.220 Rn, General-Purpose Register, n = 0 - 12, Registers on page B3-69 */

#define ARM_V8M_REG_R3              0x03    /* General-purpose register R3 - 通用目的寄存器 3 [RW]
                                               用于函数参数传递 (第 4 个参数)、临时数据存储
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.220 Rn, General-Purpose Register, n = 0 - 12, Registers on page B3-69 */

#define ARM_V8M_REG_R4              0x04    /* General-purpose register R4 - 通用目的寄存器 4 [RW]
                                               被调用者保存寄存器 (callee-save)，用于存储局部变量或需要长期保存的数据
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.220 Rn, General-Purpose Register, n = 0 - 12, Registers on page B3-69 */

#define ARM_V8M_REG_R5              0x05    /* General-purpose register R5 - 通用目的寄存器 5 [RW]
                                               被调用者保存寄存器 (callee-save)，用于存储局部变量或需要长期保存的数据
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.220 Rn, General-Purpose Register, n = 0 - 12, Registers on page B3-69 */

#define ARM_V8M_REG_R6              0x06    /* General-purpose register R6 - 通用目的寄存器 6 [RW]
                                               被调用者保存寄存器 (callee-save)，用于存储局部变量或需要长期保存的数据
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.220 Rn, General-Purpose Register, n = 0 - 12, Registers on page B3-69 */

#define ARM_V8M_REG_R7              0x07    /* General-purpose register R7 - 通用目的寄存器 7 [RW]
                                               被调用者保存寄存器 (callee-save)，常用于帧指针 (frame pointer)
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.220 Rn, General-Purpose Register, n = 0 - 12, Registers on page B3-69 */

#define ARM_V8M_REG_R8              0x08    /* General-purpose register R8 - 通用目的寄存器 8 [RW]
                                               被调用者保存寄存器 (callee-save)，在 Thumb 模式下有特殊用途
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.220 Rn, General-Purpose Register, n = 0 - 12, Registers on page B3-69 */

#define ARM_V8M_REG_R9              0x09    /* General-purpose register R9 - 通用目的寄存器 9 [RW]
                                               被调用者保存寄存器 (callee-save)，传统上用作静态基址寄存器 (SB)
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.220 Rn, General-Purpose Register, n = 0 - 12, Registers on page B3-69 */

#define ARM_V8M_REG_R10             0x0A    /* General-purpose register R10 - 通用目的寄存器 10 [RW]
                                               被调用者保存寄存器 (callee-save)，传统上用作栈限制寄存器 (SL)
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.220 Rn, General-Purpose Register, n = 0 - 12, Registers on page B3-69 */

#define ARM_V8M_REG_R11             0x0B    /* General-purpose register R11 - 通用目的寄存器 11 [RW]
                                               被调用者保存寄存器 (callee-save)，传统上用作帧指针 (FP)
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.220 Rn, General-Purpose Register, n = 0 - 12, Registers on page B3-69 */

#define ARM_V8M_REG_R12             0x0C    /* General-purpose register R12 - 通用目的寄存器 12 [RW]
                                               调用者保存寄存器，用于过程调用中的临时数据存储
                                               在 AAPCS 中也称为 IP (Intra-Procedure-call scratch register)
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.220 Rn, General-Purpose Register, n = 0 - 12, Registers on page B3-69 */

/* -----------------------------------------------------------------------------
 * 1.2 栈指针寄存器
 * 参考: Table D1-1 Arm core register index on page D1-1443
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_SP              0x0D    /* Stack Pointer - 栈指针 (R13) [RW]
                                               SP_main 和 SP_process 的银行寄存器，根据处理器模式自动选择
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.212 SP, Stack Pointer, B3.8 Stack pointer on page B3-77 */

#define ARM_V8M_REG_SP_MAIN         0x08    /* Main Stack Pointer - 主栈指针 (MSP) [RW]
                                               SYSm = 0b00001:000 (Secure) / 0b00011:000 (Non-secure)
                                               用于 Handler 模式和特权 Thread 模式
                                               复位后默认使用的栈指针，用于操作系统内核和中断服务程序
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.175 MSP, Main Stack Pointer, B3.8 Stack pointer on page B3-77 */

#define ARM_V8M_REG_SP_PROCESS      0x09    /* Process Stack Pointer - 进程栈指针 (PSP) [RW]
                                               SYSm = 0b00001:001 (Secure) / 0b00011:001 (Non-secure)
                                               仅用于 Thread 模式的非特权级
                                               通常用于用户应用程序，与操作系统栈分离以提高安全性
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.203 PSP, Process Stack Pointer, B3.8 Stack pointer on page B3-77 */

#define ARM_V8M_REG_MSPLIM          0x0A    /* Main Stack Pointer Limit - 主栈指针限制寄存器 [RW]
                                               SYSm = 0b00001:010 (Secure) / 0b00011:010 (Non-secure)
                                               主栈的下限地址，用于栈溢出检测
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.177 MSPLIM, Main Stack Pointer Limit, B3.21 Stack limit checks on page B3-88 */

#define ARM_V8M_REG_PSPLIM          0x0B    /* Process Stack Pointer Limit - 进程栈指针限制寄存器 [RW]
                                               SYSm = 0b00001:011 (Secure) / 0b00011:011 (Non-secure)
                                               进程栈的下限地址，用于栈溢出检测
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.218 PSPLIM, Process Stack Pointer Limit, B3.21 Stack limit checks on page B3-88 */

/* -----------------------------------------------------------------------------
 * 1.3 链接寄存器
 * 参考: Table D1-1 Arm core register index on page D1-1443
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_LR              0x0E    /* Link Register - 链接寄存器 (R14) [RW]
                                               存储子程序调用的返回地址，由 BL/BLX 指令自动设置
                                               在异常入口时也用于保存返回地址和异常相关信息 (EXC_RETURN)
                                               EXC_RETURN 值指示返回时的模式切换和栈选择
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.164 LR, Link Register, B3.3 Registers on page B3-69 */

/* -----------------------------------------------------------------------------
 * 1.4 程序计数器
 * 参考: Table D1-1 Arm core register index on page D1-1443
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_PC              0x0F    /* Program Counter - 程序计数器 (R15) [RW]
                                               保存当前指令的地址
                                               软件可以将 PC 称为 R15
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.191 PC, Program Counter, B3.3 Registers on page B3-69 */

/* -----------------------------------------------------------------------------
 * 1.5 程序状态寄存器
 * 参考: Table D1-1 Arm core register index on page D1-1443
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_APSR            0x00    /* Application Program Status Register - 应用程序状态寄存器 [RW]
                                               SYSm = 0b00000:000
                                               提供对 PE 执行状态字段的特权和非特权访问
                                               N, bit[31]: Negative condition flag
                                               Z, bit[30]: Zero condition flag
                                               C, bit[29]: Carry condition flag
                                               V, bit[28]: Overflow condition flag
                                               Q, bit[27]: Sticky saturation flag
                                               GE, bits[19:16]: Greater than or equal flags
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.4 APSR, Application Program Status Register, B3.5 XPSR, APSR, IPSR, and EPSR on page B3-71 */

#define ARM_V8M_REG_IAPSR           0x01    /* IPSR and APSR - 中断状态和应用程序状态寄存器组合 [RW]
                                               SYSm = 0b00000:001
                                               同时访问 IPSR 和 APSR 的组合视图
                                               用于保存/恢复完整的异常和状态信息
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.273 XPSR, Program Status Register, B3.5 XPSR, APSR, IPSR, and EPSR on page B3-71 */

#define ARM_V8M_REG_EAPSR           0x02    /* EPSR and APSR - 执行状态和应用程序状态寄存器组合 [RW]
                                               SYSm = 0b00000:010
                                               同时访问 EPSR 和 APSR 的组合视图
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.273 XPSR, Program Status Register, B3.5 XPSR, APSR, IPSR, and EPSR on page B3-71 */

#define ARM_V8M_REG_XPSR            0x03    /* Full Program Status Register - 完整程序状态寄存器 [RW]
                                               SYSm = 0b00000:011
                                               同时访问 APSR、EPSR 和 IPSR 的组合视图
                                               用于保存/恢复完整的处理器状态
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.273 XPSR, Program Status Register, B3.5 XPSR, APSR, IPSR, and EPSR on page B3-71 */

#define ARM_V8M_REG_IPSR            0x05    /* Interrupt Program Status Register - 中断程序状态寄存器 [RO]
                                               SYSm = 0b00000:101
                                               保存当前异常编号字段
                                               Exception, bits[8:0]: 保存当前正在执行的异常的异常编号，Thread 模式为零
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.142 IPSR, Interrupt Program Status Register, B3.5.1 Interrupt Program Status Register (IPSR) on page B3-74 */

#define ARM_V8M_REG_EPSR            0x06    /* Execution Program Status Register - 执行程序状态寄存器 [RW]
                                               SYSm = 0b00000:110
                                               保存执行状态位
                                               IT: If-then flags, bits[15:10, 26:25]
                                               ICI: Interrupt continuation flags, bits[26:25, 15:10]
                                               ECI: Exception continuation flags, bits[26:25, 11:10, 15:12]
                                               T: T32 state bit, bit[24]
                                               B: Branch target identification active, bit[21]
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.79 EPSR, Execution Program Status Register, B3.5.2 Execution Program Status Register (EPSR) on page B3-75 */

#define ARM_V8M_REG_IEPSR           0x07    /* IPSR and EPSR - 中断状态和执行状态寄存器组合 [RW]
                                               SYSm = 0b00000:111
                                               同时访问 IPSR 和 EPSR 的组合视图
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.273 XPSR, Program Status Register, B3.5 XPSR, APSR, IPSR, and EPSR on page B3-71 */

/* -----------------------------------------------------------------------------
 * 1.6 特殊用途掩码寄存器
 * 参考: Table D1-1 Arm core register index on page D1-1443
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_PRIMASK         0x10    /* Priority Mask Register - 优先级屏蔽寄存器 [RW]
                                               SYSm = 0b00010:000 (Secure) / 0b00011:100 (Non-secure)
                                               用于屏蔽可配置优先级异常
                                               写入 1 屏蔽所有可配置优先级异常
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.199 PRIMASK, Priority Mask Register, B3.32 Special-purpose mask registers on page B3-93 */

#define ARM_V8M_REG_BASEPRI         0x11    /* Base Priority Mask Register - 基础优先级屏蔽寄存器 [RW]
                                               SYSm = 0b00010:001 (Secure) / 0b00011:101 (Non-secure)
                                               用于屏蔽指定优先级以下的异常
                                               写入非零值屏蔽该优先级及更低优先级的异常
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.32 BASEPRI, Base Priority Mask Register, B3.32 Special-purpose mask registers on page B3-93 */

#define ARM_V8M_REG_BASEPRI_MAX     0x12    /* Base Priority Mask (Conditional Update) - 基础优先级屏蔽寄存器 (条件更新) [WO]
                                               SYSm = 0b00010:010 (Secure) / 0b00011:110 (Non-secure)
                                               仅当新值高于当前值时才更新 BASEPRI
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：BASEPRI_MAX, Base Priority Mask (Conditional Update), B3.32 Special-purpose mask registers on page B3-93 */

#define ARM_V8M_REG_FAULTMASK       0x13    /* Fault Mask Register - 故障屏蔽寄存器 [RW]
                                               SYSm = 0b00010:011 (Secure) / 0b00011:111 (Non-secure)
                                               用于屏蔽所有异常，包括 HardFault，但不包括 NMI
                                               写入 1 屏蔽所有异常 (NMI 除外)
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.97 FAULTMASK, Fault Mask Register, B3.32 Special-purpose mask registers on page B3-93 */

/* -----------------------------------------------------------------------------
 * 1.7 控制寄存器
 * 参考: Table D1-1 Arm core register index on page D1-1443
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_CONTROL         0x14    /* Control Register - 控制寄存器 [RW]
                                               SYSm = 0b00010:100 (Secure) / 0b00100:100 (Non-secure)
                                               控制 Thread 模式的特权级和栈选择
                                               nPRIV (bit[0]): 0=特权级 Thread 模式，1=非特权级 Thread 模式
                                               SPSEL (bit[1]): 0=使用 MSP，1=使用 PSP
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.13 CONTROL, Control Register, B3.4 Special-purpose CONTROL register on page B3-73 */

/* -----------------------------------------------------------------------------
 * 1.8 浮点寄存器
 * 参考: Table D1-1 Arm core register index on page D1-1443
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_FPSCR           0x01    /* Floating-point Status and Control Register - 浮点状态和控制寄存器 [RW]
                                               包含浮点运算的状态和配置
                                               包含条件标志位 (N,Z,C,V)
                                               包含累积饱和标志 (QC)
                                               包含舍入模式位 (RMode[1:0])
                                               包含浮点异常标志位
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：D1.2.103 FPSCR, Floating-point Status and Control Register, B4.2 About the Floating-point Status and Control Registers on page B4-162 */

#define ARM_V8M_REG_S0              0x00    /* Single-precision floating-point register S0 - 单精度浮点寄存器 S0 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S1              0x01    /* Single-precision floating-point register S1 - 单精度浮点寄存器 S1 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S2              0x02    /* Single-precision floating-point register S2 - 单精度浮点寄存器 S2 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S3              0x03    /* Single-precision floating-point register S3 - 单精度浮点寄存器 S3 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S4              0x04    /* Single-precision floating-point register S4 - 单精度浮点寄存器 S4 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S5              0x05    /* Single-precision floating-point register S5 - 单精度浮点寄存器 S5 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S6              0x06    /* Single-precision floating-point register S6 - 单精度浮点寄存器 S6 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S7              0x07    /* Single-precision floating-point register S7 - 单精度浮点寄存器 S7 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S8              0x08    /* Single-precision floating-point register S8 - 单精度浮点寄存器 S8 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S9              0x09    /* Single-precision floating-point register S9 - 单精度浮点寄存器 S9 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S10             0x0A    /* Single-precision floating-point register S10 - 单精度浮点寄存器 S10 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S11             0x0B    /* Single-precision floating-point register S11 - 单精度浮点寄存器 S11 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S12             0x0C    /* Single-precision floating-point register S12 - 单精度浮点寄存器 S12 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S13             0x0D    /* Single-precision floating-point register S13 - 单精度浮点寄存器 S13 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S14             0x0E    /* Single-precision floating-point register S14 - 单精度浮点寄存器 S14 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S15             0x0F    /* Single-precision floating-point register S15 - 单精度浮点寄存器 S15 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S16             0x10    /* Single-precision floating-point register S16 - 单精度浮点寄存器 S16 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S17             0x11    /* Single-precision floating-point register S17 - 单精度浮点寄存器 S17 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S18             0x12    /* Single-precision floating-point register S18 - 单精度浮点寄存器 S18 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S19             0x13    /* Single-precision floating-point register S19 - 单精度浮点寄存器 S19 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S20             0x14    /* Single-precision floating-point register S20 - 单精度浮点寄存器 S20 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S21             0x15    /* Single-precision floating-point register S21 - 单精度浮点寄存器 S21 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S22             0x16    /* Single-precision floating-point register S22 - 单精度浮点寄存器 S22 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S23             0x17    /* Single-precision floating-point register S23 - 单精度浮点寄存器 S23 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S24             0x18    /* Single-precision floating-point register S24 - 单精度浮点寄存器 S24 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S25             0x19    /* Single-precision floating-point register S25 - 单精度浮点寄存器 S25 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S26             0x1A    /* Single-precision floating-point register S26 - 单精度浮点寄存器 S26 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S27             0x1B    /* Single-precision floating-point register S27 - 单精度浮点寄存器 S27 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S28             0x1C    /* Single-precision floating-point register S28 - 单精度浮点寄存器 S28 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S29             0x1D    /* Single-precision floating-point register S29 - 单精度浮点寄存器 S29 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S30             0x1E    /* Single-precision floating-point register S30 - 单精度浮点寄存器 S30 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_S31             0x1F    /* Single-precision floating-point register S31 - 单精度浮点寄存器 S31 [RW]
                                               32 位浮点数据寄存器
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Single-precision floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_D0              0x00    /* Doubleword floating-point register D0 - 双字浮点寄存器 D0 [RW]
                                               64 位浮点数据寄存器，S0 和 S1 的组合视图
                                               D0[31:0] = S0, D0[63:32] = S1
                                               用于双精度浮点运算 (如果实现 FPv5 扩展)
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Doubleword floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_D1              0x01    /* Doubleword floating-point register D1 - 双字浮点寄存器 D1 [RW]
                                               64 位浮点数据寄存器，S2 和 S3 的组合视图
                                               D1[31:0] = S2, D1[63:32] = S3
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Doubleword floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_D2              0x02    /* Doubleword floating-point register D2 - 双字浮点寄存器 D2 [RW]
                                               64 位浮点数据寄存器，S4 和 S5 的组合视图
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Doubleword floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_D3              0x03    /* Doubleword floating-point register D3 - 双字浮点寄存器 D3 [RW]
                                               64 位浮点数据寄存器，S6 和 S7 的组合视图
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Doubleword floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_D4              0x04    /* Doubleword floating-point register D4 - 双字浮点寄存器 D4 [RW]
                                               64 位浮点数据寄存器，S8 和 S9 的组合视图
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Doubleword floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_D5              0x05    /* Doubleword floating-point register D5 - 双字浮点寄存器 D5 [RW]
                                               64 位浮点数据寄存器，S10 和 S11 的组合视图
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Doubleword floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_D6              0x06    /* Doubleword floating-point register D6 - 双字浮点寄存器 D6 [RW]
                                               64 位浮点数据寄存器，S12 和 S13 的组合视图
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Doubleword floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_D7              0x07    /* Doubleword floating-point register D7 - 双字浮点寄存器 D7 [RW]
                                               64 位浮点数据寄存器，S14 和 S15 的组合视图
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Doubleword floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_D8              0x08    /* Doubleword floating-point register D8 - 双字浮点寄存器 D8 [RW]
                                               64 位浮点数据寄存器，S16 和 S17 的组合视图
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Doubleword floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_D9              0x09    /* Doubleword floating-point register D9 - 双字浮点寄存器 D9 [RW]
                                               64 位浮点数据寄存器，S18 和 S19 的组合视图
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Doubleword floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_D10             0x0A    /* Doubleword floating-point register D10 - 双字浮点寄存器 D10 [RW]
                                               64 位浮点数据寄存器，S20 和 S21 的组合视图
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Doubleword floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_D11             0x0B    /* Doubleword floating-point register D11 - 双字浮点寄存器 D11 [RW]
                                               64 位浮点数据寄存器，S22 和 S23 的组合视图
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Doubleword floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_D12             0x0C    /* Doubleword floating-point register D12 - 双字浮点寄存器 D12 [RW]
                                               64 位浮点数据寄存器，S24 和 S25 的组合视图
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Doubleword floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_D13             0x0D    /* Doubleword floating-point register D13 - 双字浮点寄存器 D13 [RW]
                                               64 位浮点数据寄存器，S26 和 S27 的组合视图
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Doubleword floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_D14             0x0E    /* Doubleword floating-point register D14 - 双字浮点寄存器 D14 [RW]
                                               64 位浮点数据寄存器，S28 和 S29 的组合视图
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Doubleword floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

#define ARM_V8M_REG_D15             0x0F    /* Doubleword floating-point register D15 - 双字浮点寄存器 D15 [RW]
                                               64 位浮点数据寄存器，S30 和 S31 的组合视图
                                               参考：Table D1-1 Arm core register index on page D1-1443
                                               备注：Doubleword floating-point register, B4.3 Registers for Floating-point data processing on page B4-164 */

/* ==============================================================================
 * 二、系统控制空间 (SCS) 寄存器偏移定义
 * 参考: D1.1 Register index on page D1-1442
 * 说明: 这些寄存器在安全状态和非安全状态下有独立的地址映射
 *       基地址在 arm_v8m_core_safe.h 和 arm_v8m_core_unsafe.h 中定义
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 2.0 SCS 系统控制寄存器 (不在 SCB 中的寄存器)
 * 参考: D1.1.8 Implementation Control Block on page D1-1446
 *      D1.1.20 Implementation Control Block (NS alias) on page D1-1450
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCS_ICTR            0x004   /* Interrupt Controller Type Register - 中断控制器类型寄存器 [RO]
                                               提供 NVIC 的信息，指示实现的外部中断线数量
                                               只读寄存器，上电复位时由硬件设置
                                               参考：D1.1.8 Implementation Control Block on page D1-1446 */

#define ARM_V8M_SCS_ACTLR           0x008   /* Auxiliary Control Register - 辅助控制寄存器 [RW]
                                               提供 IMPLEMENTATION DEFINED 辅助控制特性
                                               位域定义取决于具体的处理器实现
                                               参考：D1.1.8 Implementation Control Block on page D1-1446 */

#define ARM_V8M_SCS_CPPWR           0x00C   /* Coprocessor Power Control Register - 协处理器电源控制寄存器 [RW]
                                               控制协处理器的电源状态
                                               参考：D1.1.8 Implementation Control Block on page D1-1446 */

/* -----------------------------------------------------------------------------
 * 2.1 SysTick 定时器寄存器偏移
 * 参考: D1.1.9 SysTick Timer on page D1-1446
 *      D1.1.21 SysTick Timer (NS alias) on page D1-1450
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SYST_CSR            0x000   /* SysTick Control and Status Register - SysTick 控制和状态寄存器 [RW]
                                               控制 SysTick 定时器的操作
                                               包含使能位 (ENABLE)、中断使能位 (TICKINT)、时钟源选择 (CLKSOURCE)
                                               包含计数标志位 (COUNTFLAG)
                                               参考：D1.1.9 SysTick Timer on page D1-1446 */

#define ARM_V8M_SYST_RVR            0x004   /* SysTick Reload Value Register - SysTick 重装载值寄存器 [RW]
                                               保存 SysTick 计数器的重装载值
                                               有效值为 0x00000001 - 0x00FFFFFF (24 位)
                                               参考：D1.1.9 SysTick Timer on page D1-1446 */

#define ARM_V8M_SYST_CVR            0x008   /* SysTick Current Value Register - SysTick 当前值寄存器 [RW]
                                               保存 SysTick 计数器的当前值
                                               每个时钟周期递减 1，写入任何值都会清除计数器
                                               参考：D1.1.9 SysTick Timer on page D1-1446 */

#define ARM_V8M_SYST_CALIB          0x00C   /* SysTick Calibration Value Register - SysTick 校准值寄存器 [RO]
                                               指示 SysTick 的校准属性
                                               包含 10ms 校准值 (TENMS)、精确标志 (SKEW)、无参考时钟标志 (NOREF)
                                               参考：D1.1.9 SysTick Timer on page D1-1446 */

/* -----------------------------------------------------------------------------
 * 2.2 嵌套向量中断控制器 (NVIC) 寄存器偏移
 * 参考: D1.1.10 Nested Vectored Interrupt Controller on page D1-1446
 *      D1.1.22 Nested Vectored Interrupt Controller (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_NVIC_ISER(n)        (0x000 + (n) * 0x04)  /* Interrupt Set-Enable Register n (n=0-15)
                                                               中断使能置位寄存器 n [RW]
                                                               用于启用外部中断，写入 1 置位对应中断使能
                                                               参考：D1.1.10 Nested Vectored Interrupt Controller on page D1-1446 */

#define ARM_V8M_NVIC_ICER(n)        (0x080 + (n) * 0x04)  /* Interrupt Clear-Enable Register n (n=0-15)
                                                               中断使能清零寄存器 n [RW]
                                                               用于禁用外部中断，写入 1 清零对应中断使能
                                                               参考：D1.1.10 Nested Vectored Interrupt Controller on page D1-1446 */

#define ARM_V8M_NVIC_ISPR(n)        (0x100 + (n) * 0x04)  /* Interrupt Set-Pending Register n (n=0-15)
                                                               中断挂起置位寄存器 n [RW]
                                                               用于挂起外部中断，写入 1 置位对应中断挂起标志
                                                               参考：D1.1.10 Nested Vectored Interrupt Controller on page D1-1446 */

#define ARM_V8M_NVIC_ICPR(n)        (0x180 + (n) * 0x04)  /* Interrupt Clear-Pending Register n (n=0-15)
                                                               中断挂起清零寄存器 n [RW]
                                                               用于清除中断挂起状态，写入 1 清零对应中断挂起标志
                                                               参考：D1.1.10 Nested Vectored Interrupt Controller on page D1-1446 */

#define ARM_V8M_NVIC_IABR(n)        (0x200 + (n) * 0x04)  /* Interrupt Active Bit Register n (n=0-15)
                                                               中断活跃位寄存器 n [RO]
                                                               指示当前正在服务的中断
                                                               只读寄存器，硬件在中断入口时置位，中断返回时清零
                                                               参考：D1.1.10 Nested Vectored Interrupt Controller on page D1-1446 */

#define ARM_V8M_NVIC_ITNS(n)        (0x380 + (n) * 0x04)  /* Interrupt Target Non-secure Register n (n=0-15)
                                                               中断目标非安全寄存器 n [RW]
                                                               控制中断的目标安全状态
                                                               位[31:0] 对应中断 32n 到 32n+31
                                                               参考：D1.1.10 Nested Vectored Interrupt Controller on page D1-1446 */

#define ARM_V8M_NVIC_IPR(n)         (0x300 + (n) * 0x04)  /* Interrupt Priority Register n (n=0-123)
                                                               中断优先级寄存器 n [RW]
                                                               每个 IPR 寄存器包含 4 个中断的优先级
                                                               优先级值越小优先级越高
                                                               参考：D1.1.10 Nested Vectored Interrupt Controller on page D1-1446 */

/* -----------------------------------------------------------------------------
 * 2.3 系统控制块 (SCB) 寄存器偏移
 * 参考: D1.1.11 System Control Block on page D1-1447
 *      D1.1.23 System Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
/* 注意: REVIDR 位于 0xE000ECFC，在 SCB 基地址 0xE000ED00 之前
 * 使用 ARM_V8M_SCB_REVIDR_BASE_S 或 ARM_V8M_SCB_REVIDR_BASE_NS 作为基地址
 * 参考：D1.1.11 System Control Block on page D1-1447 */
#define ARM_V8M_SCB_REVIDR          0x000   /* Revision ID Register - 修订 ID 寄存器 [RO]
                                                提供处理器修订版本信息
                                                只读寄存器，上电复位时由硬件设置
                                                参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_CPUID           0x004   /* CPUID Base Register - CPUID 基寄存器 [RO]
                                               提供处理器标识信息，包含架构版本、实现者ID、零件号、修订版本
                                               只读寄存器，上电复位时由硬件设置
                                               用于操作系统和调试器识别处理器类型和特性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ICSR            0x008   /* Interrupt Control and State Register - 中断控制和状态寄存器 [RW]
                                               提供 NMI、PendSV 和 SysTick 异常的软件控制
                                               提供中断状态信息，包括当前活跃的异常编号
                                               可通过软件触发 PendSV 和 SysTick 异常
                                               包含中断挂起和活跃标志
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_VTOR            0x00C   /* Vector Table Offset Register - 向量表偏移寄存器 [RW]
                                               保存向量表的基地址
                                               向量表包含所有异常处理程序的入口地址
                                               软件可在运行时重新定位向量表
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_AIRCR           0x010   /* Application Interrupt and Reset Control Register - 应用程序中断和复位控制寄存器 [RW]
                                               设置或返回中断控制数据
                                               提供系统复位功能（需要写入 VECTKEY 密钥 0x05FA）
                                               包含数据端序指示位 (ENDIANNESS)
                                               提供中断优先级分组控制 (PRIGROUP)
                                               可用于清除所有挂起的异常状态
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_SCR             0x014   /* System Control Register - 系统控制寄存器 [RW]
                                               设置或返回系统控制数据
                                               控制低功耗模式（SLEEPDEEP 位）
                                               控制睡眠进入行为（SLEEPONEXIT 位）
                                               控制异常唤醒行为（SEVONPEND 位）
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_CCR             0x018   /* Configuration and Control Register - 配置和控制寄存器 [RW]
                                               设置或返回配置和控制数据
                                               提供缓存和分支预测控制
                                               控制未对齐访问陷阱 (UNALIGN_TRP)
                                               控制除零陷阱 (DIV_0_TRP)
                                               控制线程模式和 Handler 模式栈对齐 (STKALIGN)
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_SHPR1           0x01C   /* System Handler Priority Register 1 - 系统处理程序优先级寄存器 1 [RW]
                                               设置或返回系统处理程序 4-7 的优先级
                                               系统处理程序 4-7: 4=MemManage, 5=BusFault, 6=UsageFault, 7=SecureFault
                                               每个处理程序占 8 位，优先级值越小优先级越高
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_SHPR2           0x020   /* System Handler Priority Register 2 - 系统处理程序优先级寄存器 2 [RW]
                                               设置或返回系统处理程序 8-11 的优先级
                                               系统处理程序 8-11: 8=Reserved, 9=Reserved, 10=Reserved, 11=SVCall
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_SHPR3           0x024   /* System Handler Priority Register 3 - 系统处理程序优先级寄存器 3 [RW]
                                               设置或返回系统处理程序 12-15 的优先级
                                               系统处理程序 12-15: 12=DebugMonitor, 13=Reserved, 14=PendSV, 15=SysTick
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_SHCSR           0x028   /* System Handler Control and State Register - 系统处理程序控制和状态寄存器 [RW]
                                               控制并提供系统异常的活跃和挂起状态
                                               包含 MemManage、BusFault、UsageFault 异常的使能位
                                               包含各系统异常的挂起和活跃标志
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_CFSR            0x02C   /* Configurable Fault Status Register - 可配置故障状态寄存器 [RW]
                                               包含三个可配置故障状态寄存器 (MMFSR, BFSR, UFSR)
                                               MMFSR (byte[0]): MemManage 故障状态
                                               BFSR (byte[1]): BusFault 故障状态
                                               UFSR (halfword[2]): UsageFault 故障状态
                                               所有状态位都是写一清零 (W1C)
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_MMFSR           0x02C   /* MemManage Status Register - MemManage 状态寄存器 [RW]
                                               包含 MemManage 故障状态信息 (字节访问)
                                               CFSR 的 byte[0]，可单独字节访问
                                               所有状态位都是写一清零 (W1C)
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_BFSR            0x02D   /* BusFault Status Register - BusFault 状态寄存器 [RW]
                                               包含 BusFault 故障状态信息 (字节访问)
                                               CFSR 的 byte[1]，可单独字节访问
                                               所有状态位都是写一清零 (W1C)
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_UFSR            0x02E   /* UsageFault Status Register - UsageFault 状态寄存器 [RW]
                                               包含 UsageFault 故障状态信息 (半字访问)
                                               CFSR 的 halfword[2]，可单独半字访问
                                               所有状态位都是写一清零 (W1C)
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_HFSR            0x030   /* HardFault Status Register - HardFault 状态寄存器 [RW]
                                               显示任何 HardFault 异常的原因
                                               包含调试事件标志 (DEBUGEVT)
                                               包含向量表读取错误标志 (VECTTBL)
                                               包含强制硬故障标志 (FORCED)
                                               所有状态位都是写一清零 (W1C)
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_DFSR            0x034   /* Debug Fault Status Register - 调试故障状态寄存器 [RW]
                                               提供调试事件的信息
                                               所有状态位都是写一清零 (W1C)
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_MMFAR           0x038   /* MemManage Fault Address Register - MemManage 故障地址寄存器 [RW]
                                               保存导致 MemManage 故障的位置地址
                                               仅当 MMFSR.MMARVALID 置 1 时有效
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_BFAR            0x03C   /* BusFault Address Register - BusFault 故障地址寄存器 [RW]
                                               保存导致精确 BusFault 的位置地址
                                               仅当 BFSR.BFARVALID 置 1 时有效
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_AFSR            0x040   /* Auxiliary Fault Status Register - 辅助故障状态寄存器 [RW]
                                               提供 IMPLEMENTATION DEFINED 故障状态信息
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_PFR0         0x044   /* Processor Feature Register 0 - 处理器特性寄存器 0 [RO]
                                               指示处理器支持的指令集特性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_PFR1         0x048   /* Processor Feature Register 1 - 处理器特性寄存器 1 [RO]
                                               指示处理器支持的指令集特性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_DFR0         0x04C   /* Debug Feature Register 0 - 调试特性寄存器 0 [RO]
                                               指示处理器支持的调试特性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_AFR0         0x050   /* Auxiliary Feature Register 0 - 辅助特性寄存器 0 [RO]
                                               指示处理器支持的辅助特性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_MMFR0        0x054   /* Memory Model Feature Register 0 - 内存模型特性寄存器 0 [RO]
                                               描述处理器支持的内存模型和内存管理特性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_MMFR1        0x058   /* Memory Model Feature Register 1 - 内存模型特性寄存器 1 [RO]
                                               描述处理器支持的内存模型和内存管理特性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_MMFR2        0x05C   /* Memory Model Feature Register 2 - 内存模型特性寄存器 2 [RO]
                                               描述处理器支持的内存模型和内存管理特性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_MMFR3        0x060   /* Memory Model Feature Register 3 - 内存模型特性寄存器 3 [RO]
                                               描述处理器支持的内存模型和内存管理特性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_ISAR0        0x064   /* Instruction Set Attribute Register 0 - 指令集属性寄存器 0 [RO]
                                               描述处理器支持的指令集属性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_ISAR1        0x068   /* Instruction Set Attribute Register 1 - 指令集属性寄存器 1 [RO]
                                               描述处理器支持的指令集属性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_ISAR2        0x06C   /* Instruction Set Attribute Register 2 - 指令集属性寄存器 2 [RO]
                                               描述处理器支持的指令集属性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_ISAR3        0x070   /* Instruction Set Attribute Register 3 - 指令集属性寄存器 3 [RO]
                                               描述处理器支持的指令集属性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_ISAR4        0x074   /* Instruction Set Attribute Register 4 - 指令集属性寄存器 4 [RO]
                                               描述处理器支持的指令集属性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_ISAR5        0x078   /* Instruction Set Attribute Register 5 - 指令集属性寄存器 5 [RO]
                                               描述处理器支持的指令集属性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_CLIDR           0x07C   /* Cache Level ID Register - 缓存级别标识寄存器 [RO]
                                               指示实现的缓存级别和类型
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_CTR             0x080   /* Cache Type Register - 缓存类型寄存器 [RO]
                                               描述实现的缓存类型和特性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_CCSIDR          0x084   /* Current Cache Size ID Register - 当前缓存大小标识寄存器 [RO]
                                               提供当前选中缓存的尺寸信息
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_CSSELR          0x084   /* Cache Size Selection Register - 缓存大小选择寄存器 [RW]
                                               选择要访问的缓存
                                               参考：D1.1.11 System Control Block on page D1-1447 */

/* 注意: CPACR (0x088) 和 NSACR (0x08C) 仅在安全状态下可访问
 * 定义在 arm_v8m_core_safe.h 中
 * 参考：D1.1.11 System Control Block on page D1-1447 */

/* -----------------------------------------------------------------------------
 * 2.4 内存保护单元 (MPU) 寄存器偏移
 * 参考: D1.1.12 Memory Protection Unit on page D1-1448
 *      D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_MPU_TYPE            0x000   /* MPU Type Register - MPU 类型寄存器 [RO]
                                               提供 MPU 的信息，包含数据区域数量
                                               只读寄存器，用于确定是否实现了 MPU 及支持的区域数
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_CTRL            0x004   /* MPU Control Register - MPU 控制寄存器 [RW]
                                               控制 MPU 的操作
                                               包含特权默认使能位 (PRIVDEFENA)
                                               包含硬故障和 NMI 使能位 (HFNMIENA)
                                               包含使能位 (ENABLE)
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_RNR             0x008   /* MPU Region Number Register - MPU 区域编号寄存器 [RW]
                                               选择由 MPU_RBAR 和 MPU_RLAR 引用的 MPU 区域
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_RBAR            0x00C   /* MPU Region Base Address Register - MPU 区域基地址寄存器 [RW]
                                               定义 MPU_RNR 选择的 MPU 区域的基地址
                                               位[31:5] 是区域基地址，必须按区域大小对齐
                                               位[4] 是有效标志 (VALID)
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_RLAR            0x010   /* MPU Region Limit Address Register - MPU 区域限制地址寄存器 [RW]
                                               定义 MPU_RNR 选择的 MPU 区域的限制地址和属性
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_RBAR_A1         0x014   /* MPU Region Base Address Register Alias 1 - MPU 区域基地址寄存器别名 1 [RW]
                                               写入时可直接指定区域号，无需先写 MPU_RNR
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_RLAR_A1         0x018   /* MPU Region Limit Address Register Alias 1 - MPU 区域限制地址寄存器别名 1 [RW]
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_RBAR_A2         0x01C   /* MPU Region Base Address Register Alias 2 - MPU 区域基地址寄存器别名 2 [RW]
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_RLAR_A2         0x020   /* MPU Region Limit Address Register Alias 2 - MPU 区域限制地址寄存器别名 2 [RW]
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_RBAR_A3         0x024   /* MPU Region Base Address Register Alias 3 - MPU 区域基地址寄存器别名 3 [RW]
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_RLAR_A3         0x028   /* MPU Region Limit Address Register Alias 3 - MPU 区域限制地址寄存器别名 3 [RW]
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_MAIR0           0x030   /* MPU Memory Attribute Indirection Register 0 - MPU 内存属性间接寄存器 0 [RW]
                                               定义内存属性编码
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_MAIR1           0x034   /* MPU Memory Attribute Indirection Register 1 - MPU 内存属性间接寄存器 1 [RW]
                                               定义内存属性编码
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

/* 注意: SAU 寄存器 (SAU_CTRL, SAU_TYPE, SAU_RNR, SAU_RBAR, SAU_RLAR, SFSR, SFAR)
 * 仅在安全状态下可访问，定义在 arm_v8m_core_safe.h 中
 * 参考：D1.1.13 Security Attribution Unit on page D1-1448 */

/* -----------------------------------------------------------------------------
 * 2.5 软件触发中断寄存器 (STIR) 偏移
 * 参考: D1.1.15 Software Interrupt Generation on page D1-1449
 *      D1.1.26 Software Interrupt Generation (NS alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_STIR                0x000   /* Software Triggered Interrupt Register - 软件触发中断寄存器 [WO]
                                               写入此寄存器会触发中断
                                               仅特权级可访问，写入中断编号到低 9 位触发对应中断
                                               参考：D1.1.15 Software Interrupt Generation on page D1-1449 */

/* -----------------------------------------------------------------------------
 * 2.6 RAS 扩展故障状态寄存器 (RFSR) 偏移
 * 参考: D1.1.16 RAS Extension Fault Status Register on page D1-1449
 *      D1.1.27 RAS Extension Fault Status Register (NS Alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCB_RFSR            0x004   /* RAS Fault Status Register - RAS 故障状态寄存器 [RW]
                                               提供 RAS 故障状态信息
                                               参考：D1.1.16 RAS Extension Fault Status Register on page D1-1449 */

/* -----------------------------------------------------------------------------
 * 2.7 浮点扩展寄存器 (FP Extension) 偏移
 * 参考: D1.1.17 Floating-Point Extension on page D1-1449
 *      D1.1.28 Floating-Point Extension (NS alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_FPU_FPCCR           0x000   /* Floating Point Context Control Register - 浮点上下文控制寄存器 [RW]
                                               控制浮点上下文
                                               包含延迟状态保存控制 (LSPEN)
                                               包含用户模式访问控制 (USER)
                                               参考：D1.1.17 Floating-Point Extension on page D1-1449 */

#define ARM_V8M_FPU_FPCAR           0x004   /* Floating Point Context Address Register - 浮点上下文地址寄存器 [RW]
                                               保存内存中浮点上下文的位置
                                               指向浮点寄存器在栈上的保存位置
                                               参考：D1.1.17 Floating-Point Extension on page D1-1449 */

#define ARM_V8M_FPU_FPDSCR          0x008   /* Floating Point Default Status Control Register - 浮点默认状态控制寄存器 [RW]
                                               保存 FPSCR 的默认值
                                               异常入口时 FPSCR 的默认值来源于此寄存器
                                               参考：D1.1.17 Floating-Point Extension on page D1-1449 */

#define ARM_V8M_FPU_MVFR0           0x00C   /* Media and VFP Feature Register 0 - 媒体和 VFP 特性寄存器 0 [RO]
                                               提供浮点单元特性信息
                                               只读寄存器，用于软件检测 FPU 能力
                                               参考：D1.1.17 Floating-Point Extension on page D1-1449 */

#define ARM_V8M_FPU_MVFR1           0x010   /* Media and VFP Feature Register 1 - 媒体和 VFP 特性寄存器 1 [RO]
                                               提供额外的浮点特性信息
                                               只读寄存器，用于识别高级浮点特性
                                               参考：D1.1.17 Floating-Point Extension on page D1-1449 */

#define ARM_V8M_FPU_MVFR2           0x014   /* Media and VFP Feature Register 2 - 媒体和 VFP 特性寄存器 2 [RO]
                                               提供 FPv5 扩展的特性信息
                                               只读寄存器
                                               参考：D1.1.17 Floating-Point Extension on page D1-1449 */

/* -----------------------------------------------------------------------------
 * 2.8 缓存维护操作寄存器 (Cache Maintenance) 偏移
 * 参考: D1.1.18 Cache Maintenance Operations on page D1-1449
 *      D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_ICIALLU             0x000   /* Instruction Cache Invalidate All to PoU - 指令缓存全部无效化到 PoU [WO]
                                               将所有指令缓存无效化到统一点 (PoU)
                                               仅写操作，写入值被忽略
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

#define ARM_V8M_ICIMVAU             0x008   /* Instruction Cache line Invalidate by Address to PoU - 按地址指令缓存行无效化到 PoU [WO]
                                               按修改虚拟地址将指令缓存行无效化到统一点
                                               仅写操作，写入地址
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

#define ARM_V8M_DCIMVAC             0x00C   /* Data Cache line Invalidate by Address to PoC - 按地址数据缓存行无效化到 PoC [WO]
                                               按修改虚拟地址将数据缓存行无效化到一致点
                                               仅写操作，写入地址
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

#define ARM_V8M_DCISW               0x010   /* Data Cache line Invalidate by Set/Way - 按组/路数据缓存行无效化 [WO]
                                               按组/路方式将数据缓存行无效化
                                               仅写操作，写入组/路标识符
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

#define ARM_V8M_DCCMVAU             0x014   /* Data Cache line Clean by address to PoU - 按地址数据缓存行清理到 PoU [WO]
                                               按修改虚拟地址将数据缓存行清理到统一点
                                               清理操作将脏数据写回到统一点
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

#define ARM_V8M_DCCMVAC             0x018   /* Data Cache line Clean by Address to PoC - 按地址数据缓存行清理到 PoC [WO]
                                               按修改虚拟地址将数据缓存行清理到一致点
                                               仅写操作，写入地址
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

#define ARM_V8M_DCCSW               0x01C   /* Data Cache Clean line by Set/Way - 按组/路数据缓存行清理 [WO]
                                               按组/路方式将数据缓存行清理
                                               仅写操作，写入组/路标识符
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

#define ARM_V8M_DCCIMVAC            0x020   /* Data Cache line Clean and Invalidate by Address to PoC - 按地址数据缓存行清理并无效化到 PoC [WO]
                                               按修改虚拟地址将数据缓存行清理并无效化到一致点
                                               仅写操作，写入地址
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

#define ARM_V8M_DCCISW              0x024   /* Data Cache line Clean and Invalidate by Set/Way - 按组/路数据缓存行清理并无效化 [WO]
                                               按组/路方式将数据缓存行清理并无效化
                                               仅写操作，写入组/路标识符
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

#define ARM_V8M_BPIALL              0x028   /* Branch Predictor Invalidate All - 分支预测器全部无效化 [WO]
                                               将所有分支预测器条目无效化
                                               仅写操作，写入值被忽略
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

/* -----------------------------------------------------------------------------
 * 2.9 调试标识块 (Debug Identification Block) 寄存器偏移
 * 参考: D1.1.19 Debug Identification Block on page D1-1449
 *      D1.1.30 Debug Identification Block (NS alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DEBUG_DLAR          0x0B0   /* Software Lock Access Register - 软件锁访问寄存器 [WO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DLSR          0x0B4   /* Software Lock Status Register - 软件锁状态寄存器 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DAUTHSTATUS   0x0B8   /* Debug Authentication Status Register - 调试认证状态寄存器 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DDEVARCH      0x0BC   /* SCS Device Architecture Register - SCS 设备架构寄存器 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DDEVTYPE      0x0CC   /* SCS Device Type Register - SCS 设备类型寄存器 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DPIDR4        0x0D0   /* SCS Peripheral Identification Register 4 - SCS 外设标识寄存器 4 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DPIDR5        0x0D4   /* SCS Peripheral Identification Register 5 - SCS 外设标识寄存器 5 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DPIDR6        0x0D8   /* SCS Peripheral Identification Register 6 - SCS 外设标识寄存器 6 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DPIDR7        0x0DC   /* SCS Peripheral Identification Register 7 - SCS 外设标识寄存器 7 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DPIDR0        0x0E0   /* SCS Peripheral Identification Register 0 - SCS 外设标识寄存器 0 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DPIDR1        0x0E4   /* SCS Peripheral Identification Register 1 - SCS 外设标识寄存器 1 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DPIDR2        0x0E8   /* SCS Peripheral Identification Register 2 - SCS 外设标识寄存器 2 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DPIDR3        0x0EC   /* SCS Peripheral Identification Register 3 - SCS 外设标识寄存器 3 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DCIDR0        0x0F0   /* SCS Component Identification Register 0 - SCS 组件标识寄存器 0 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DCIDR1        0x0F4   /* SCS Component Identification Register 1 - SCS 组件标识寄存器 1 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DCIDR2        0x0F8   /* SCS Component Identification Register 2 - SCS 组件标识寄存器 2 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DCIDR3        0x0FC   /* SCS Component Identification Register 3 - SCS 组件标识寄存器 3 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

/* -----------------------------------------------------------------------------
 * 2.10 调试控制块 (Debug Control Block) 寄存器偏移
 * 参考: D1.1.14 Debug Control Block on page D1-1449
 *      D1.1.25 Debug Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DEBUG_DHCSR         0x000   /* Debug Halting Control and Status Register - 调试暂停控制和状态寄存器 [RW]
                                               控制处理器调试暂停状态
                                               参考：D1.1.14 Debug Control Block on page D1-1449 */

/* 注意: DCRSR (0x004) 仅在安全状态下可访问，定义在 arm_v8m_core_safe.h 中
 * 参考：D1.1.14 Debug Control Block on page D1-1449 */

#define ARM_V8M_DEBUG_DCRDR         0x008   /* Debug Core Register Data Register - 调试核心寄存器数据寄存器 [RW]
                                               提供对核心寄存器的读写数据
                                               参考：D1.1.14 Debug Control Block on page D1-1449 */

#define ARM_V8M_DEBUG_DEMCR         0x00C   /* Debug Exception and Monitor Control Register - 调试异常和监视器控制寄存器 [RW]
                                               控制调试异常和监视器
                                               参考：D1.1.14 Debug Control Block on page D1-1449 */

#define ARM_V8M_DEBUG_DSCEMCR       0x010   /* Debug Set Clear Exception and Monitor Control Register - 调试设置清除异常和监视器控制寄存器 [RW]
                                               参考：D1.1.14 Debug Control Block on page D1-1449 */

#define ARM_V8M_DEBUG_DAUTHCTRL     0x014   /* Debug Authentication Control Register - 调试认证控制寄存器 [RW]
                                               控制调试认证
                                               参考：D1.1.14 Debug Control Block on page D1-1449 */

/* 注意: DSCSR (0x018) 仅在安全状态下可访问，定义在 arm_v8m_core_safe.h 中
 * 参考：D1.1.14 Debug Control Block on page D1-1449 */

/* ==============================================================================
 * 三、仪器化跟踪宏单元 (ITM) 寄存器偏移定义
 * 参考: D1.1.3 Instrumentation Macrocell on page D1-1444
 * ==============================================================================
 */
#define ARM_V8M_ITM_STIM(n)         ((n) * 0x04)  /* Stimulus Port Register n (n=0-255)
                                                       激励端口寄存器 n [RW]
                                                       用于输出软件生成的跟踪数据
                                                       参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_TER(n)          (0xE00 + (n) * 0x04)  /* Trace Enable Register n (n=0-7)
                                                               跟踪使能寄存器 n [RW]
                                                               控制哪些激励端口启用跟踪
                                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_TPR             0xE40   /* Trace Privilege Register - 跟踪特权寄存器 [RW]
                                               控制跟踪的特权级别
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_TCR             0xE80   /* Trace Control Register - 跟踪控制寄存器 [RW]
                                               控制 ITM 的整体操作
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_LAR             0xFB0   /* Software Lock Access Register - 软件锁访问寄存器 [WO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_LSR             0xFB4   /* Software Lock Status Register - 软件锁状态寄存器 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_DEVARCH         0xFBC   /* Device Architecture Register - 设备架构寄存器 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_DEVTYPE         0xFCC   /* Device Type Register - 设备类型寄存器 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_PIDR4           0xFD0   /* Peripheral Identification Register 4 - 外设标识寄存器 4 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_PIDR5           0xFD4   /* Peripheral Identification Register 5 - 外设标识寄存器 5 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_PIDR6           0xFD8   /* Peripheral Identification Register 6 - 外设标识寄存器 6 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_PIDR7           0xFDC   /* Peripheral Identification Register 7 - 外设标识寄存器 7 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_PIDR0           0xFE0   /* Peripheral Identification Register 0 - 外设标识寄存器 0 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_PIDR1           0xFE4   /* Peripheral Identification Register 1 - 外设标识寄存器 1 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_PIDR2           0xFE8   /* Peripheral Identification Register 2 - 外设标识寄存器 2 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_PIDR3           0xFEC   /* Peripheral Identification Register 3 - 外设标识寄存器 3 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_CIDR0           0xFF0   /* Component Identification Register 0 - 组件标识寄存器 0 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_CIDR1           0xFF4   /* Component Identification Register 1 - 组件标识寄存器 1 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_CIDR2           0xFF8   /* Component Identification Register 2 - 组件标识寄存器 2 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_CIDR3           0xFFC   /* Component Identification Register 3 - 组件标识寄存器 3 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

/* ==============================================================================
 * 四、数据观察点和跟踪单元 (DWT) 寄存器偏移定义
 * 参考: D1.1.4 Data Watchpoint and Trace on page D1-1444
 * ==============================================================================
 */
#define ARM_V8M_DWT_CTRL            0x000   /* Control Register - 控制寄存器 [RW]
                                               控制 DWT 功能
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_CYCCNT           0x004   /* Cycle Count Register - 周期计数寄存器 [RW]
                                               跟踪执行的周期数
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_CPICNT           0x008   /* CPI Count Register - CPI 计数寄存器 [RW]
                                               跟踪 CPI 计数
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_EXCCNT           0x00C   /* Exception Overhead Count Register - 异常开销计数寄存器 [RW]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_SLEEPCNT         0x010   /* Sleep Count Register - 睡眠计数寄存器 [RW]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_LSUCNT           0x014   /* LSU Count Register - LSU 计数寄存器 [RW]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_FOLDCNT          0x018   /* Folded Instruction Count Register - 折叠指令计数寄存器 [RW]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_PCSR             0x01C   /* Program Counter Sample Register - 程序计数器采样寄存器 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_COMP(n)          (0x020 + (n) * 0x10)  /* Comparator Register n (n=0-3) - 比较器寄存器 n [RW]
                                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_FUNCTION(n)      (0x028 + (n) * 0x10)  /* Comparator Function Register n (n=0-3) - 比较器功能寄存器 n [RW]
                                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_VMASK(n)         (0x02C + (n) * 0x10)  /* Comparator Value Mask Register n (n=0-3) - 比较器值掩码寄存器 n [RW]
                                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_LAR              0xFB0   /* Software Lock Access Register - 软件锁访问寄存器 [WO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_LSR              0xFB4   /* Software Lock Status Register - 软件锁状态寄存器 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_DEVARCH          0xFBC   /* Device Architecture Register - 设备架构寄存器 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_DEVTYPE          0xFCC   /* Device Type Register - 设备类型寄存器 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_PIDR4            0xFD0   /* Peripheral Identification Register 4 - 外设标识寄存器 4 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_PIDR5            0xFD4   /* Peripheral Identification Register 5 - 外设标识寄存器 5 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_PIDR6            0xFD8   /* Peripheral Identification Register 6 - 外设标识寄存器 6 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_PIDR7            0xFDC   /* Peripheral Identification Register 7 - 外设标识寄存器 7 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_PIDR0            0xFE0   /* Peripheral Identification Register 0 - 外设标识寄存器 0 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_PIDR1            0xFE4   /* Peripheral Identification Register 1 - 外设标识寄存器 1 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_PIDR2            0xFE8   /* Peripheral Identification Register 2 - 外设标识寄存器 2 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_PIDR3            0xFEC   /* Peripheral Identification Register 3 - 外设标识寄存器 3 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_CIDR0            0xFF0   /* Component Identification Register 0 - 组件标识寄存器 0 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_CIDR1            0xFF4   /* Component Identification Register 1 - 组件标识寄存器 1 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_CIDR2            0xFF8   /* Component Identification Register 2 - 组件标识寄存器 2 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

#define ARM_V8M_DWT_CIDR3            0xFFC   /* Component Identification Register 3 - 组件标识寄存器 3 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1444 */

/* ==============================================================================
 * 五、闪存补丁和断点单元 (FPB) 寄存器偏移定义
 * 参考: D1.1.5 Flash Patch and Breakpoint on page D1-1445
 * ==============================================================================
 */
#define ARM_V8M_FPB_CTRL             0x000   /* Flash Patch Control Register - 闪存补丁控制寄存器 [RW]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_REMAP            0x004   /* Flash Patch Remap Register - 闪存补丁重映射寄存器 [RW]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_COMP(n)          (0x008 + (n) * 0x04)  /* Flash Patch Comparator Register n (n=0-7) - 闪存补丁比较器寄存器 n [RW]
                                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_LAR              0xFB0   /* Software Lock Access Register - 软件锁访问寄存器 [WO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_LSR              0xFB4   /* Software Lock Status Register - 软件锁状态寄存器 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_DEVARCH          0xFBC   /* Device Architecture Register - 设备架构寄存器 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_DEVTYPE          0xFCC   /* Device Type Register - 设备类型寄存器 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_PIDR4            0xFD0   /* Peripheral Identification Register 4 - 外设标识寄存器 4 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_PIDR5            0xFD4   /* Peripheral Identification Register 5 - 外设标识寄存器 5 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_PIDR6            0xFD8   /* Peripheral Identification Register 6 - 外设标识寄存器 6 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_PIDR7            0xFDC   /* Peripheral Identification Register 7 - 外设标识寄存器 7 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_PIDR0            0xFE0   /* Peripheral Identification Register 0 - 外设标识寄存器 0 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_PIDR1            0xFE4   /* Peripheral Identification Register 1 - 外设标识寄存器 1 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_PIDR2            0xFE8   /* Peripheral Identification Register 2 - 外设标识寄存器 2 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_PIDR3            0xFEC   /* Peripheral Identification Register 3 - 外设标识寄存器 3 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_CIDR0            0xFF0   /* Component Identification Register 0 - 组件标识寄存器 0 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_CIDR1            0xFF4   /* Component Identification Register 1 - 组件标识寄存器 1 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_CIDR2            0xFF8   /* Component Identification Register 2 - 组件标识寄存器 2 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_CIDR3            0xFFC   /* Component Identification Register 3 - 组件标识寄存器 3 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

/* ==============================================================================
 * 六、性能监控单元 (PMU) 寄存器偏移定义
 * 参考: D1.1.6 Performance Monitoring Unit on page D1-1445
 * ==============================================================================
 */
#define ARM_V8M_PMU_EVCNTR(n)        ((n) * 0x04)  /* Event Counter Register n (n=0-30) - 事件计数器寄存器 n [RW]
                                                       参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_CCNT             0x07C   /* Cycle Counter Register - 周期计数器寄存器 [RW]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_EVTYPER(n)       (0x400 + (n) * 0x04)  /* Event Type and Filter Register n (n=0-30) - 事件类型和过滤器寄存器 n [RW]
                                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_CCFILTR          0x47C   /* Cycle Counter Filter Register - 周期计数器过滤器寄存器 [RW]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_CNTENSET         0xC00   /* Count Enable Set Register - 计数使能置位寄存器 [RW]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_CNTENCLR         0xC20   /* Count Enable Clear Register - 计数使能清零寄存器 [RW]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_INTENSET         0xC40   /* Interrupt Enable Set Register - 中断使能置位寄存器 [RW]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_INTENCLR         0xC60   /* Interrupt Enable Clear Register - 中断使能清零寄存器 [RW]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_OVSCLR           0xC80   /* Overflow Flag Status Clear Register - 溢出标志状态清零寄存器 [RW]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_SWINC            0xCA0   /* Software Increment Register - 软件增量寄存器 [WO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_OVSSET           0xCC0   /* Overflow Flag Status Set Register - 溢出标志状态置位寄存器 [RW]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_TYPE             0xE00   /* Type Register - 类型寄存器 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_CTRL             0xE04   /* Control Register - 控制寄存器 [RW]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_AUTHSTATUS       0xFB8   /* Authentication Status Register - 认证状态寄存器 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_DEVARCH         0xFBC   /* Device Architecture Register - 设备架构寄存器 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_DEVTYPE          0xFCC   /* Device Type Register - 设备类型寄存器 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_PIDR4            0xFD0   /* Peripheral Identification Register 4 - 外设标识寄存器 4 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_PIDR5            0xFD4   /* Peripheral Identification Register 5 - 外设标识寄存器 5 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_PIDR6            0xFD8   /* Peripheral Identification Register 6 - 外设标识寄存器 6 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_PIDR7            0xFDC   /* Peripheral Identification Register 7 - 外设标识寄存器 7 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_PIDR0            0xFE0   /* Peripheral Identification Register 0 - 外设标识寄存器 0 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_PIDR1            0xFE4   /* Peripheral Identification Register 1 - 外设标识寄存器 1 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_PIDR2            0xFE8   /* Peripheral Identification Register 2 - 外设标识寄存器 2 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_PIDR3            0xFEC   /* Peripheral Identification Register 3 - 外设标识寄存器 3 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_CIDR0            0xFF0   /* Component Identification Register 0 - 组件标识寄存器 0 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_CIDR1            0xFF4   /* Component Identification Register 1 - 组件标识寄存器 1 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_CIDR2            0xFF8   /* Component Identification Register 2 - 组件标识寄存器 2 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_CIDR3            0xFFC   /* Component Identification Register 3 - 组件标识寄存器 3 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

/* ==============================================================================
 * 七、可靠性、可用性和可服务性扩展 (RAS) 寄存器偏移定义
 * 参考: D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446
 * ==============================================================================
 */
#define ARM_V8M_RAS_ERRFR(n)          ((n) * 0x40)  /* Error Record Feature Register n (n=0-3) - 错误记录特性寄存器 n [RO]
                                                       参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446 */

#define ARM_V8M_RAS_ERRCTRL(n)        (0x008 + (n) * 0x40)  /* Error Record Control Register n (n=0-3) - 错误记录控制寄存器 n [RW]
                                                               参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446 */

#define ARM_V8M_RAS_ERRSTATUS(n)       (0x010 + (n) * 0x40)  /* Error Record Primary Status Register n (n=0-3) - 错误记录主状态寄存器 n [RW]
                                                               参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446 */

#define ARM_V8M_RAS_ERRADDR(n)         (0x018 + (n) * 0x40)  /* Error Record Address Register n (n=0-3) - 错误记录地址寄存器 n [RW]
                                                               参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446 */

#define ARM_V8M_RAS_ERRADDR2(n)        (0x01C + (n) * 0x40)  /* Error Record Address 2 Register n (n=0-3) - 错误记录地址 2 寄存器 n [RW]
                                                               参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446 */

#define ARM_V8M_RAS_ERRMISC(n, m)      (0x020 + (n) * 0x40 + (m) * 0x04)  /* Error Record Miscellaneous Register n,m (n=0-3, m=0-7) - 错误记录杂项寄存器 n,m [RW]
                                                                              参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446 */

#define ARM_V8M_RAS_ERRGSR(n)          (0xE00 + (n) * 0x04)  /* Error Record Group Status Register n (n=0-3) - 错误记录组状态寄存器 n [RO]
                                                               参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446 */

#define ARM_V8M_RAS_ERRIIDR            0xE10   /* Error Implementer ID Register - 错误实现者 ID 寄存器 [RO]
                                               参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446 */

#define ARM_V8M_RAS_ERRDEVID           0xFC8   /* Error Record Device ID Register - 错误记录设备 ID 寄存器 [RO]
                                               参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446 */

/* ==============================================================================
 * 八、跟踪端口接口单元 (TPIU) 寄存器偏移定义
 * 参考: D1.1.31 Trace Port Interface Unit on page D1-1453
 * ==============================================================================
 */
#define ARM_V8M_TPIU_SSPSR            0x000   /* Supported Parallel Port Sizes Register - 支持的并行端口大小寄存器 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_CSPSR            0x004   /* Current Parallel Port Size Register - 当前并行端口大小寄存器 [RW]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_ACPR             0x010   /* Asynchronous Clock Prescaler Register - 异步时钟预分频寄存器 [RW]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_SPPR             0x0F0   /* Selected Pin Protocol Register - 选择的引脚协议寄存器 [RW]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_FFSR             0x300   /* Formatter and Flush Status Register - 格式化器和刷新状态寄存器 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_FFCR             0x304   /* Formatter and Flush Control Register - 格式化器和刷新控制寄存器 [RW]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_PSCR             0x308   /* Periodic Synchronization Control Register - 周期同步控制寄存器 [RW]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_CLAIMSET         0xFA0   /* Claim Tag Set Register - 声明标签设置寄存器 [WO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_CLAIMCLR         0xFA4   /* Claim Tag Clear Register - 声明标签清除寄存器 [WO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_LAR              0xFB0   /* Software Lock Access Register - 软件锁访问寄存器 [WO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_LSR              0xFB4   /* Software Lock Status Register - 软件锁状态寄存器 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_DEVID            0xFC8   /* Device Identifier Register - 设备标识寄存器 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_DEVTYPE          0xFCC   /* Device Type Register - 设备类型寄存器 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_PIDR4            0xFD0   /* Peripheral Identification Register 4 - 外设标识寄存器 4 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_PIDR5            0xFD4   /* Peripheral Identification Register 5 - 外设标识寄存器 5 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_PIDR6            0xFD8   /* Peripheral Identification Register 6 - 外设标识寄存器 6 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_PIDR7            0xFDC   /* Peripheral Identification Register 7 - 外设标识寄存器 7 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_PIDR0            0xFE0   /* Peripheral Identification Register 0 - 外设标识寄存器 0 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_PIDR1            0xFE4   /* Peripheral Identification Register 1 - 外设标识寄存器 1 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_PIDR2            0xFE8   /* Peripheral Identification Register 2 - 外设标识寄存器 2 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_PIDR3            0xFEC   /* Peripheral Identification Register 3 - 外设标识寄存器 3 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_CIDR0            0xFF0   /* Component Identification Register 0 - 组件标识寄存器 0 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_CIDR1            0xFF4   /* Component Identification Register 1 - 组件标识寄存器 1 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_CIDR2            0xFF8   /* Component Identification Register 2 - 组件标识寄存器 2 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_CIDR3            0xFFC   /* Component Identification Register 3 - 组件标识寄存器 3 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#include "arm_v8m_core_safe.h"
#include "arm_v8m_core_unsafe.h"

#ifdef __cplusplus
}
#endif

#endif /* __ARM_V8M_CORE_H__ */
