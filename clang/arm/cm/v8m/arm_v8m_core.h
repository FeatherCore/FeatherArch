/********************************************************************************
 * @file        arm_v8m_core.h
 * @brief       ARMv8-M Architecture Register Definitions
 * @details     基于 ARMv8-M Architecture Reference Manual (ARM DDI 0553B.z)
 *              所有寄存器定义严格参考手册章节位置
 *              文档路径：d:\BaiduSyncdisk\来自：本地电脑\sync\code\Feather\FeatherArch\docs\arm\Arm® v8-M Architecture Reference Manual.txt
 * @author      FeatherCore
 * @version     1.0.0
 * @date        2026-03-30
 * @note        本文件仅包含寄存器定义和描述，位域定义在单独的头文件中
 *
 * 寄存器覆盖清单：
 * - Arm Core Registers (R0-R15, xPSR, PRIMASK, BASEPRI, FAULTMASK, CONTROL, MSPLIM, PSPLIM)
 *   参考: D1.2 寄存器描述 (Alphabetical list of registers)
 * - Floating-point Extension Registers (S0-S31, D0-D15, FPSCR, FPCCR, FPCAR, FPDSCR, FPCXT, MVFR0-2)
 *   参考: D1.2 寄存器描述
 * - System Control Space (SCS) Registers
 *   - SCS: ICTR, ACTLR, CPPWR (基地址 0xE000E000)
 *   - SCB: CPUID, ICSR, VTOR, AIRCR, SCR, CCR, SHPR1-3, SHCSR, CFSR, HFSR, DFSR,
 *          MMFAR, BFAR, AFSR, CPACR, NSACR, ID_PFR0-1, ID_DFR0, ID_AFR0, ID_MMFR0-3,
 *          ID_ISAR0-5, CLIDR, CTR, CCSIDR, CSSELR, REVIDR (基地址 0xE000ED00)
 *   - FPU: FPCCR, FPCAR, FPDSCR, FPCXT, MVFR0-2 (基地址 0xE000EF34)
 *   - SysTick: SYST_CSR, SYST_RVR, SYST_CVR, SYST_CALIB (基地址 0xE000E010)
 *   - NVIC: NVIC_ISER, NVIC_ICER, NVIC_ISPR, NVIC_ICPR, NVIC_IABR, NVIC_IPR, NVIC_ITNS (基地址 0xE000E100)
 *   - MPU: MPU_TYPE, MPU_CTRL, MPU_RNR, MPU_RBAR, MPU_RLAR, MPU_RBAR_A1-A3, MPU_RLAR_A1-A3, MPU_MAIR0-1 (基地址 0xE000ED90)
 *   - Cache Maintenance: ICIALLU, ICIMVAU, DCIMVAC, DCISW, DCCMVAU, DCCMVAC, DCCSW, DCCIMVAC, DCCISW, BPIALL (基地址 0xE000EF50)
 *   - STIR: 软件触发中断寄存器 (基地址 0xE000EF00)
 *   - Peripheral/Component ID: PID0-7, CID0-3 (基地址 0xE000E000, 偏移 0xEFB0-0xEFFC)
 *   参考: D1.2 寄存器描述
 * - Debug Registers
 *   - Debug Core: DHCSR, DCRSR, DCRDR, DEMCR, DSCEMCR, DAUTHCTRL, DSCSR (基地址 0xE000EDF0)
 *   - DWT: DWT_CTRL, DWT_CYCCNT, DWT_CPICNT, DWT_EXCCNT, DWT_SLEEPCNT, DWT_LSUCNT,
 *          DWT_FOLDCNT, DWT_PCSR, DWT_COMPn, DWT_MASKn, DWT_FUNCTIONn, DWT_LAR, DWT_LSR (基地址 0xE0001000)
 *   - ITM: ITM_STIMn, ITM_TERn, ITM_TPR, ITM_TCR, ITM_LAR, ITM_LSR (基地址 0xE0000000)
 *   - TPIU: TPIU_SSPSR, TPIU_CSPSR, TPIU_ACPR, TPIU_SPPR, TPIU_TYPE, TPIU_LAR, TPIU_LSR (基地址 0xE0040000)
 *   - FPB: FP_CTRL, FP_REMAP, FP_COMPn, FPB_LAR, FPB_LSR (基地址 0xE0002000)
 *   参考: D1.2 寄存器描述
 * - Security Extension Registers
 *   - SAU: SAU_CTRL, SAU_TYPE, SAU_RNR, SAU_RBAR, SAU_RLAR (基地址 0xE000EDD0)
 *   - Secure Fault: SFSR, SFAR (基地址 0xE000EDE4)
 *   参考: D1.2 寄存器描述
 * - Performance Monitor Unit (PMU)
 *   - PMU: PMU_EVCNTRn, PMU_CCNTR, PMU_EVTYPERn, PMU_CCFILTR, PMU_CNTENSET, PMU_CNTENCLR,
 *          PMU_INTENSET, PMU_INTENCLR, PMU_OVSCLR, PMU_OVSSET, PMU_SWINC, PMU_TYPE, PMU_CTRL,
 *          PMU_AUTHSTATUS (基地址 0xE0003000)
 *   参考: D1.2 寄存器描述
 * - Reliability, Availability and Serviceability (RAS)
 *   - RAS: ERRFRn, ERRCTRLn, ERRSTATUSn, ERRADDRn, ERRADDR2n, ERRMISC0-7n, ERRGSRn, ERRIIDR, ERRDEVID (基地址 0xE0005000, 0xE000EF04)
 *   参考: D1.2 寄存器描述
 * - M-Profile Vector Extension (MVE)
 *   - Q0-Q7, VPR, LO_BRANCH_INFO
 *   参考: D1.2 寄存器描述
 * - Pointer Authentication and Branch Target Identification (PACBTI)
 *   - PAC_KEY_P_0-3, PAC_KEY_U_0-3
 *   参考: D1.2 寄存器描述
 *
 * 关于 NS 别名说明：
 *
 * NS 别名（Non-secure Alias）是安全状态访问非安全寄存器的机制：
 * - 地址映射：Secure 基地址 0xE000_xxxx 对应 Non-secure 别名地址 0xE002_xxxx
 * - 工作原理：银行化寄存器有 Secure 和 Non-secure 两个物理副本
 *   - Secure 状态访问 0xE000_xxxx → Secure 版本
 *   - Secure 状态访问 0xE002_xxxx → Non-secure 版本（通过 NS 别名）
 *   - Non-secure 状态无论访问哪个地址，都只能访问 Non-secure 版本
 * - 用途：Secure 软件可直接管理 Non-secure 系统资源，无需状态切换
 * - 访问规则：
 *   - 仅 Secure 状态可通过 NS 别名访问 Non-secure 版本寄存器
 *   - Non-secure 状态访问 NS 别名地址（0xE002_xxxx）为 RES0（读取为0，写入忽略）
 *
 * 寄存器分类：
 * 1. 有 NS 别名：SCS(ICTR/ACTLR/CPPWR), SCB, MPU, SysTick, NVIC, 缓存维护, 组件识别, DCB
 * 2. 无 NS 别名：仅 Secure 访问寄存器, DWT/ITM/FPB/TPIU, PMU(除 PMU_AUTHSTATUS), RAS, MVE, PACBTI
 *
 * 【v8m 新增功能说明】
 * 以下功能仅在 ARMv8-M 中可用，在 ARMv7-M 中不存在：
 * 1. Security Extension - SAU 寄存器、Secure Fault (SFSR/SFAR)、NS 别名机制 (0xE002_xxxx)
 * 2. Stack Pointer Limit - MSPLIM/PSPLIM 寄存器，用于栈溢出检测
 * 3. 协处理器电源控制 - CPPWR 寄存器
 * 4. 版本 ID - REVIDR 寄存器
 * 5. Non-secure 访问控制 - NSACR 寄存器
 * 6. NVIC ITNS - 中断目标 Non-secure 寄存器
 * 7. 调试扩展 - DSCEMCR, DAUTHCTRL, DSCSR 寄存器
 * 8. PMU - 性能监控单元 (0xE0003000)
 * 9. RAS - 可靠性、可用性和可服务性扩展 (0xE0005000)
 * 10. MVE - M-Profile 向量扩展 (Q0-Q7, VPR, LO_BRANCH_INFO)
 * 11. PACBTI - 指针认证和分支目标识别 (PAC_KEY_P_0-3, PAC_KEY_U_0-3)
 * 12. DWT/ITM/FPB/TPIU 完整的 PIDR/CIDR/DEVARCH/DEVTYPE 寄存器
 * 13. MPU 使用 RLAR 替代 RASR，新增 MAIR0/1 寄存器
 *
 * 【v7m 独有功能（v8m 已移除）】
 * 1. MPU_RASR 寄存器 - v8m 中使用 MPU_RLAR 替代
 * 2. ROM Table 寄存器 - v8m 中已移除
 ********************************************************************************/

#ifndef __ARM_V8M_CORE_H__
#define __ARM_V8M_CORE_H__

#ifdef __cplusplus
extern "C" {
#endif

/* ==============================================================================
 * 一、Arm 核心寄存器 (Arm Core Registers)
 * 参考: D1.2 Alphabetical list of registers
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 1.1 通用寄存器 R0-R12
 * 参考: D1.2.220 Rn, General-Purpose Register n
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_R0              0x00    /* General-purpose register R0 - 通用目的寄存器 0 [RW]
                                               用于函数参数传递 (第 1 个参数)、返回值、临时数据存储
                                               在 AAPCS 调用约定中，R0-R3 用于传递前 4 个参数
                                               参考：D1.2.220 Rn, General-Purpose Register n
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_R1              0x01    /* General-purpose register R1 - 通用目的寄存器 1 [RW]
                                               用于函数参数传递 (第 2 个参数)、返回值 (64 位返回值的高 32 位)
                                               参考：D1.2.220 Rn, General-Purpose Register n
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_R2              0x02    /* General-purpose register R2 - 通用目的寄存器 2 [RW]
                                               用于函数参数传递 (第 3 个参数)、临时数据存储
                                               参考：D1.2.220 Rn, General-Purpose Register n
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_R3              0x03    /* General-purpose register R3 - 通用目的寄存器 3 [RW]
                                               用于函数参数传递 (第 4 个参数)、临时数据存储
                                               参考：D1.2.220 Rn, General-Purpose Register n
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_R4              0x04    /* General-purpose register R4 - 通用目的寄存器 4 [RW]
                                               被调用者保存寄存器 (callee-save),用于存储局部变量或需要长期保存的数据
                                               参考：D1.2.220 Rn, General-Purpose Register n
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_R5              0x05    /* General-purpose register R5 - 通用目的寄存器 5 [RW]
                                               被调用者保存寄存器 (callee-save),用于存储局部变量或需要长期保存的数据
                                               参考：D1.2.220 Rn, General-Purpose Register n
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_R6              0x06    /* General-purpose register R6 - 通用目的寄存器 6 [RW]
                                               被调用者保存寄存器 (callee-save),用于存储局部变量或需要长期保存的数据
                                               参考：D1.2.220 Rn, General-Purpose Register n
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_R7              0x07    /* General-purpose register R7 - 通用目的寄存器 7 [RW]
                                               被调用者保存寄存器 (callee-save),常用于帧指针 (frame pointer)
                                               参考：D1.2.220 Rn, General-Purpose Register n
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_R8              0x08    /* General-purpose register R8 - 通用目的寄存器 8 [RW]
                                               被调用者保存寄存器 (callee-save),在 Thumb 模式下有特殊用途
                                               参考：D1.2.220 Rn, General-Purpose Register n
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_R9              0x09    /* General-purpose register R9 - 通用目的寄存器 9 [RW]
                                               被调用者保存寄存器 (callee-save),传统上用作静态基址寄存器 (SB)
                                               参考：D1.2.220 Rn, General-Purpose Register n
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_R10             0x0A    /* General-purpose register R10 - 通用目的寄存器 10 [RW]
                                               被调用者保存寄存器 (callee-save),传统上用作栈限制寄存器 (SL)
                                               参考：D1.2.220 Rn, General-Purpose Register n
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_R11             0x0B    /* General-purpose register R11 - 通用目的寄存器 11 [RW]
                                               被调用者保存寄存器 (callee-save),传统上用作帧指针 (FP)
                                               参考：D1.2.220 Rn, General-Purpose Register n
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_R12             0x0C    /* General-purpose register R12 - 通用目的寄存器 12 [RW]
                                               调用者保存寄存器，用于过程调用中的临时数据存储
                                               在 AAPCS 中也称为 IP (Intra-Procedure-call scratch register)
                                               参考：D1.2.220 Rn, General-Purpose Register n
                                               备注：适用于所有 Armv8-M 实现 */

/* -----------------------------------------------------------------------------
 * 1.2 栈指针寄存器
 * 参考: D1.2.237 SP, Current Stack Pointer Register
 *      D1.2.238 SP_NS, Current Stack Pointer register (Non-secure)
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_SP_MAIN         0x08    /* Main Stack Pointer - 主栈指针 (MSP) [RW]
                                               SYSm = 0b00001:000,用于 Handler 模式和 Thread 模式的特权级
                                               复位后默认使用的栈指针，用于操作系统内核和中断服务程序
                                               实现 Security Extension 时，有 MSP_S 和 MSP_NS 两个银行化版本
                                               参考：D1.2.237 SP, Current Stack Pointer Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_SP_PROCESS      0x09    /* Process Stack Pointer - 进程栈指针 (PSP) [RW]
                                               SYSm = 0b00001:001,仅用于 Thread 模式的非特权级
                                               通常用于用户应用程序，与操作系统栈分离以提高安全性
                                               实现 Security Extension 时，有 PSP_S 和 PSP_NS 两个银行化版本
                                               参考：D1.2.237 SP, Current Stack Pointer Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_SP              0x0D    /* Stack Pointer - 栈指针 (R13) [RW]
                                               SP_main 和 SP_process 的银行寄存器，根据处理器模式自动选择
                                               在 MRS/MSR 指令中用作 SYSm 编码，实际访问取决于当前模式
                                               实现 Security Extension 时，有 SP_S 和 SP_NS 两个银行化版本
                                               参考：D1.2.237 SP, Current Stack Pointer Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_SP_NS           0x0D    /* Stack Pointer (Non-secure) - 栈指针 (Non-secure 版本) [RW]
                                               SYSm = 0b10001:101,仅用于访问 Non-secure 状态的当前栈指针
                                               仅 Secure 状态可访问此寄存器，Non-secure 状态访问为 UNPREDICTABLE
                                               参考：D1.2.238 SP_NS, Current Stack Pointer register (Non-secure)
                                               备注：仅实现 Security Extension 时可用
                                               【v8m 独有】v7m 中不存在此寄存器 */

#define ARM_V8M_REG_MSPLIM          0x0A    /* Main Stack Pointer Limit Register - 主栈指针限制寄存器 [RW]
                                               SYSm = 0b00001:010,用于栈溢出检测
                                               当 MSP 写入值小于等于 MSPLIM 时触发 UsageFault
                                               实现 Security Extension 时，有 MSPLIM_S 和 MSPLIM_NS 两个银行化版本
                                               参考：D1.2.177 MSPLIM, Main Stack Pointer Limit Register
                                               备注：Armv8.1-M 及更高版本可选
                                               【v8m 独有】v7m 中不存在此寄存器 */

#define ARM_V8M_REG_PSPLIM          0x0B    /* Process Stack Pointer Limit Register - 进程栈指针限制寄存器 [RW]
                                               SYSm = 0b00001:011,用于栈溢出检测
                                               当 PSP 写入值小于等于 PSPLIM 时触发 UsageFault
                                               实现 Security Extension 时，有 PSPLIM_S 和 PSPLIM_NS 两个银行化版本
                                               参考：D1.2.218 PSPLIM, Process Stack Pointer Limit Register
                                               备注：Armv8.1-M 及更高版本可选
                                               【v8m 独有】v7m 中不存在此寄存器 */

/* -----------------------------------------------------------------------------
 * 1.3 链接寄存器
 * 参考: D1.2.164 LR, Link Register
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_LR              0x0E    /* Link Register - 链接寄存器 (R14) [RW]
                                               存储子程序调用的返回地址，由 BL/BLX 指令自动设置
                                               在异常入口时也用于保存返回地址和异常相关信息 (EXC_RETURN)
                                               EXC_RETURN 值指示返回时的模式切换和栈选择
                                               参考：D1.2.164 LR, Link Register
                                               备注：适用于所有 Armv8-M 实现 */

/* -----------------------------------------------------------------------------
 * 1.4 程序计数器
 * 参考: D1.2.191 PC, Program Counter
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_PC              0x0F    /* Program Counter - 程序计数器 (R15) [RW]
                                               存储下一条要执行指令的地址，读取时返回当前指令地址 +4
                                               写入 PC 会触发分支操作，bit[0] 决定 Thumb 状态 (必须为 1)
                                               写入奇数地址保持 Thumb 状态，写入偶数地址触发 UsageFault
                                               参考：D1.2.191 PC, Program Counter
                                               备注：适用于所有 Armv8-M 实现 */

/* -----------------------------------------------------------------------------
 * 1.5 程序状态寄存器
 * 参考: D1.2.4 APSR, Application Program Status Register
 *      D1.2.79 EPSR, Execution Program Status Register
 *      D1.2.142 IPSR, Interrupt Program Status Register
 *      D1.2.273 XPSR, Combined Program Status Registers
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_APSR            0x00    /* Application Program Status Register - 应用程序状态寄存器 [RW]
                                               SYSm = 0b00000:000,包含条件标志位 N,Z,C,V,Q 标志和 GE[3:0] 标志
                                               N (Negative, bit[31]): 结果为负时置 1
                                               Z (Zero, bit[30]): 结果为零时置 1
                                               C (Carry, bit[29]): 进位/借位时置 1
                                               V (Overflow, bit[28]): 溢出时置 1
                                               Q (Saturation, bit[27]): 饱和运算溢出时置 1 (DSP 扩展)
                                               GE[3:0] (Greater than or Equal, bits[19:16]): DSP 运算的大于等于标志 (DSP 扩展)
                                               应用程序可通过 MSR/MRS 指令读写这些标志位
                                               参考：D1.2.4 APSR, Application Program Status Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_IAPSR           0x01    /* IPSR and APSR - 中断状态和应用程序状态寄存器组合 [RW]
                                               SYSm = 0b00000:001,同时访问 IPSR 和 APSR 的组合视图
                                               用于保存/恢复完整的异常和状态信息
                                               参考：D1.2.4 APSR, Application Program Status Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_EAPSR           0x02    /* EPSR and APSR - 执行状态和应用程序状态寄存器组合 [RW]
                                               SYSm = 0b00000:010,同时访问 EPSR 和 APSR 的组合视图
                                               包含执行状态位 (IT,ICI) 和条件标志位
                                               IT 位：If-Then 块条件执行状态
                                               ICI 位：中断可继续指令状态
                                               参考：D1.2.79 EPSR, Execution Program Status Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_XPSR            0x03    /* Full Program Status Register - 完整程序状态寄存器 [RW]
                                               SYSm = 0b00000:011,访问所有 xPSR 位 (APSR+IPSR+EPSR)
                                               用于异常入口/出口时完整保存程序状态
                                               异常入口时硬件自动压栈，异常返回时自动恢复
                                               参考：D1.2.273 XPSR, Combined Program Status Registers
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_IPSR            0x05    /* Interrupt Program Status Register - 中断程序状态寄存器 [RO]
                                               SYSm = 0b00000:101,包含当前异常编号 (Exception Number[8:0])
                                               只读寄存器，硬件在异常入口时自动设置，指示当前执行的异常
                                               异常编号：1=Reset, 2=NMI, 3=HardFault, 4-15=系统异常，16+=外部中断
                                               参考：D1.2.142 IPSR, Interrupt Program Status Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_EPSR            0x06    /* Execution Program Status Register - 执行程序状态寄存器 [RW]
                                               SYSm = 0b00000:110,包含执行状态位 (T,ICI/IT)
                                               T 位 (bit[24]) 必须为 1 以支持 Thumb 指令集，为 0 会触发 UsageFault
                                               IT 块：If-Then 条件执行指令块状态
                                               ICI/IT 位：中断继续/条件执行状态信息
                                               参考：D1.2.79 EPSR, Execution Program Status Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_IEPSR           0x07    /* IPSR and EPSR - 中断状态和执行状态寄存器组合 [RW]
                                               SYSm = 0b00000:111,同时访问 IPSR 和 EPSR 的组合视图
                                               用于保存/恢复中断和执行状态信息
                                               参考：D1.2.142 IPSR, Interrupt Program Status Register
                                               备注：适用于所有 Armv8-M 实现 */

/* -----------------------------------------------------------------------------
 * 1.6 特殊用途掩码寄存器
 * 参考: D1.2.217 PRIMASK, Exception Mask Register
 *      D1.2.5 BASEPRI, Base Priority Mask Register
 *      D1.2.97 FAULTMASK, Fault Mask Register
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_PRIMASK         0x10    /* Priority Mask Register - 优先级屏蔽寄存器 [RW]
                                               SYSm = 0b00010:000,1 位寄存器，用于屏蔽所有可配置优先级的异常
                                               PRIMASK[0]=1: 屏蔽优先级为 0 的异常 (除 NMI 和 HardFault)
                                               PRIMASK[0]=0: 正常中断处理
                                               可通过 CPSID i 指令设置，CPSIE i 指令清除
                                               访问权限：仅特权级可访问，非特权级访问为 RAZ/WI
                                               实现 Security Extension 时，有 PRIMASK_S 和 PRIMASK_NS 两个银行化版本
                                               参考：D1.2.217 PRIMASK, Exception Mask Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_REG_BASEPRI         0x11    /* Base Priority Mask Register - 基础优先级屏蔽寄存器 [RW]
                                               SYSm = 0b00010:001,8 位寄存器，用于屏蔽指定优先级以下的异常
                                               BASEPRI=0: 禁用 BASEPRI 屏蔽
                                               BASEPRI=n: 屏蔽优先级>=n 的所有异常
                                               实现的位数取决于处理器的优先级位数 (通常 3-8 位)
                                               可通过 MSR 指令写入，MRS 指令读取
                                               访问权限：仅特权级可访问，非特权级访问为 RAZ/WI
                                               实现 Security Extension 时，有 BASEPRI_S 和 BASEPRI_NS 两个银行化版本
                                               参考：D1.2.5 BASEPRI, Base Priority Mask Register
                                               备注：仅 Main Extension 时可用 */

#define ARM_V8M_REG_BASEPRI_MAX     0x12    /* Base Priority Mask (Conditional Update) - 基础优先级屏蔽寄存器 (条件更新) [WO]
                                               SYSm = 0b00010:010,MSR 指令的特殊掩码参数
                                               仅当新值>当前 BASEPRI 值时才更新 BASEPRI
                                               用于实现临界区的优先级保护，防止高优先级代码降低屏蔽级别
                                               只能通过 MSR 指令写入，不能读取
                                               参考：D1.2.5 BASEPRI, Base Priority Mask Register
                                               备注：仅 Main Extension 时可用 */

#define ARM_V8M_REG_FAULTMASK       0x13    /* Fault Mask Register - 故障屏蔽寄存器 [RW]
                                               SYSm = 0b00010:011,1 位寄存器，用于屏蔽所有异常 (包括 Fault)
                                               FAULTMASK[0]=1: 屏蔽所有异常 (除 NMI),执行优先级提升到 -1
                                               FAULTMASK[0]=0: 正常中断处理
                                               可通过 CPSID f 指令设置，CPSIE f 指令清除
                                               异常返回时自动清零 (除 NMI 返回)
                                               访问权限：仅特权级可访问，非特权级访问为 RAZ/WI
                                               实现 Security Extension 时，有 FAULTMASK_S 和 FAULTMASK_NS 两个银行化版本
                                               参考：D1.2.97 FAULTMASK, Fault Mask Register
                                               备注：仅 Main Extension 时可用 */

/* -----------------------------------------------------------------------------
 * 1.7 控制寄存器
 * 参考: D1.2.13 CONTROL, Control Register
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_CONTROL         0x14    /* Control Register - 控制寄存器 [RW]
                                               SYSm = 0b00010:100,控制 Thread 模式的特权级和栈选择
                                               CONTROL[0] (nPRIV): 0=Thread 模式特权级，1=Thread 模式非特权级
                                               CONTROL[1] (SPSEL): 0=使用 SP_main, 1=使用 SP_process (仅 Thread 模式)
                                               CONTROL[2] (FPCA): 0=FP 扩展未激活，1=FP 扩展激活 (仅 FP 扩展)
                                               CONTROL[3] (SFPA): 0=安全浮点未激活，1=安全浮点激活 (仅 Security Extension 且 FP 扩展)
                                               写入 CONTROL 后需要执行 ISB 指令保证同步
                                               访问权限：仅特权级可自由访问，非特权级只能读 nPRIV 位
                                               实现 Security Extension 时，CONTROL 部分位银行化
                                               参考：D1.2.13 CONTROL, Control Register
                                               备注：适用于所有 Armv8-M 实现 */

/* ==============================================================================
 * 二、浮点扩展寄存器 (Floating-point Extension Registers)
 * 参考: D1.2 寄存器描述
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 2.1 浮点状态控制寄存器
 * 参考: D1.2.103 FPSCR, Floating-point Status and Control Register
 *      D1.2.100 FPCCR, Floating-Point Context Control Register
 *      D1.2.99 FPCAR, Floating-Point Context Address Register
 *      D1.2.102 FPDSCR, Floating-Point Default Status Control Register
 *      D1.2.101 FPCXT, Floating-point context payload
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_FPSCR           0x01    /* Floating-point Status and Control Register - 浮点状态和控制寄存器 [RW]
                                               FP 扩展系统寄存器，位于 CP10 和 CP11 协处理器空间
                                               包含浮点运算状态标志 (IOC, DZC, OFC, UFC, IXC, FPSID)
                                               包含舍入模式控制 (RMode) 和默认 NaN 控制 (DN)
                                               包含浮点异常使能位 (IOE, DZE, OFE, UFE, IXE)
                                               可通过 VMRS/VMSR 指令访问
                                               参考：D1.2.103 FPSCR, Floating-point Status and Control Register
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_FPCCR           0x000   /* Floating-Point Context Control Register - 浮点上下文控制寄存器 [RW]
                                               地址: 0xE000EF34
                                               控制浮点上下文的保存和恢复
                                               包含 LSPEN、ASPEN、TS、_monitor 等位
                                               参考：D1.2.100 FPCCR, Floating-Point Context Control Register
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_FPCAR           0x004   /* Floating-Point Context Address Register - 浮点上下文地址寄存器 [RW]
                                               地址: 0xE000EF38
                                               保存浮点上下文的存储地址
                                               参考：D1.2.99 FPCAR, Floating-Point Context Address Register
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_FPDSCR          0x008   /* Floating-Point Default Status Control Register - 浮点默认状态控制寄存器 [RW]
                                               地址: 0xE000EF3C
                                               保存默认的 FPSCR 值
                                               参考：D1.2.102 FPDSCR, Floating-Point Default Status Control Register
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_FPCXT           0x00C   /* Floating-point context payload - 浮点上下文负载 [RW]
                                               地址: 0xE000EF40
                                               用于存储额外的浮点上下文信息
                                               参考：D1.2.101 FPCXT, Floating-point context payload
                                               备注：仅 FP 扩展时可用 */

/* -----------------------------------------------------------------------------
 * 2.2 浮点数据寄存器
 * 参考: D1.2.224 Sn, Floating-point Single-precision register n
 *      D1.2.19 Dn, Floating-point Double-precision register n
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_S0              0x00    /* Single-precision floating-point register S0 - 单精度浮点寄存器 S0 [RW]
                                               32 位浮点数据寄存器，可存储单精度浮点数
                                               也可作为 32 位整数寄存器使用
                                               在 VFP 指令中用于浮点运算，在 M 寄存器传输指令中用于整数操作
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S1              0x01    /* Single-precision floating-point register S1 - 单精度浮点寄存器 S1 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S2              0x02    /* Single-precision floating-point register S2 - 单精度浮点寄存器 S2 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S3              0x03    /* Single-precision floating-point register S3 - 单精度浮点寄存器 S3 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S4              0x04    /* Single-precision floating-point register S4 - 单精度浮点寄存器 S4 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S5              0x05    /* Single-precision floating-point register S5 - 单精度浮点寄存器 S5 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S6              0x06    /* Single-precision floating-point register S6 - 单精度浮点寄存器 S6 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S7              0x07    /* Single-precision floating-point register S7 - 单精度浮点寄存器 S7 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S8              0x08    /* Single-precision floating-point register S8 - 单精度浮点寄存器 S8 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S9              0x09    /* Single-precision floating-point register S9 - 单精度浮点寄存器 S9 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S10             0x0A    /* Single-precision floating-point register S10 - 单精度浮点寄存器 S10 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S11             0x0B    /* Single-precision floating-point register S11 - 单精度浮点寄存器 S11 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S12             0x0C    /* Single-precision floating-point register S12 - 单精度浮点寄存器 S12 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S13             0x0D    /* Single-precision floating-point register S13 - 单精度浮点寄存器 S13 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S14             0x0E    /* Single-precision floating-point register S14 - 单精度浮点寄存器 S14 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S15             0x0F    /* Single-precision floating-point register S15 - 单精度浮点寄存器 S15 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S16             0x10    /* Single-precision floating-point register S16 - 单精度浮点寄存器 S16 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S17             0x11    /* Single-precision floating-point register S17 - 单精度浮点寄存器 S17 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S18             0x12    /* Single-precision floating-point register S18 - 单精度浮点寄存器 S18 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S19             0x13    /* Single-precision floating-point register S19 - 单精度浮点寄存器 S19 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S20             0x14    /* Single-precision floating-point register S20 - 单精度浮点寄存器 S20 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S21             0x15    /* Single-precision floating-point register S21 - 单精度浮点寄存器 S21 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S22             0x16    /* Single-precision floating-point register S22 - 单精度浮点寄存器 S22 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S23             0x17    /* Single-precision floating-point register S23 - 单精度浮点寄存器 S23 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S24             0x18    /* Single-precision floating-point register S24 - 单精度浮点寄存器 S24 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S25             0x19    /* Single-precision floating-point register S25 - 单精度浮点寄存器 S25 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S26             0x1A    /* Single-precision floating-point register S26 - 单精度浮点寄存器 S26 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S27             0x1B    /* Single-precision floating-point register S27 - 单精度浮点寄存器 S27 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S28             0x1C    /* Single-precision floating-point register S28 - 单精度浮点寄存器 S28 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S29             0x1D    /* Single-precision floating-point register S29 - 单精度浮点寄存器 S29 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S30             0x1E    /* Single-precision floating-point register S30 - 单精度浮点寄存器 S30 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_S31             0x1F    /* Single-precision floating-point register S31 - 单精度浮点寄存器 S31 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               参考：D1.2.224 Sn, Floating-point Single-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_D0              0x00    /* Doubleword floating-point register D0 - 双字浮点寄存器 D0 [RW]
                                               64 位浮点数据寄存器，S0 和 S1 的组合视图
                                               D0[31:0] = S0, D0[63:32] = S1
                                               用于双精度浮点运算 (如果实现 FPv5 扩展)
                                               也可作为两个 32 位寄存器或一个 64 位整数寄存器使用
                                               参考：D1.2.19 Dn, Floating-point Double-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_D1              0x01    /* Doubleword floating-point register D1 - 双字浮点寄存器 D1 [RW]
                                               64 位浮点数据寄存器，S2 和 S3 的组合视图
                                               D1[31:0] = S2, D1[63:32] = S3
                                               参考：D1.2.19 Dn, Floating-point Double-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_D2              0x02    /* Doubleword floating-point register D2 - 双字浮点寄存器 D2 [RW]
                                               64 位浮点数据寄存器，S4 和 S5 的组合视图
                                               D2[31:0] = S4, D2[63:32] = S5
                                               参考：D1.2.19 Dn, Floating-point Double-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_D3              0x03    /* Doubleword floating-point register D3 - 双字浮点寄存器 D3 [RW]
                                               64 位浮点数据寄存器，S6 和 S7 的组合视图
                                               D3[31:0] = S6, D3[63:32] = S7
                                               参考：D1.2.19 Dn, Floating-point Double-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_D4              0x04    /* Doubleword floating-point register D4 - 双字浮点寄存器 D4 [RW]
                                               64 位浮点数据寄存器，S8 和 S9 的组合视图
                                               D4[31:0] = S8, D4[63:32] = S9
                                               参考：D1.2.19 Dn, Floating-point Double-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_D5              0x05    /* Doubleword floating-point register D5 - 双字浮点寄存器 D5 [RW]
                                               64 位浮点数据寄存器，S10 和 S11 的组合视图
                                               D5[31:0] = S10, D5[63:32] = S11
                                               参考：D1.2.19 Dn, Floating-point Double-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_D6              0x06    /* Doubleword floating-point register D6 - 双字浮点寄存器 D6 [RW]
                                               64 位浮点数据寄存器，S12 和 S13 的组合视图
                                               D6[31:0] = S12, D6[63:32] = S13
                                               参考：D1.2.19 Dn, Floating-point Double-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_D7              0x07    /* Doubleword floating-point register D7 - 双字浮点寄存器 D7 [RW]
                                               64 位浮点数据寄存器，S14 和 S15 的组合视图
                                               D7[31:0] = S14, D7[63:32] = S15
                                               参考：D1.2.19 Dn, Floating-point Double-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_D8              0x08    /* Doubleword floating-point register D8 - 双字浮点寄存器 D8 [RW]
                                               64 位浮点数据寄存器，S16 和 S17 的组合视图
                                               D8[31:0] = S16, D8[63:32] = S17
                                               参考：D1.2.19 Dn, Floating-point Double-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_D9              0x09    /* Doubleword floating-point register D9 - 双字浮点寄存器 D9 [RW]
                                               64 位浮点数据寄存器，S18 和 S19 的组合视图
                                               D9[31:0] = S18, D9[63:32] = S19
                                               参考：D1.2.19 Dn, Floating-point Double-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_D10             0x0A    /* Doubleword floating-point register D10 - 双字浮点寄存器 D10 [RW]
                                               64 位浮点数据寄存器，S20 和 S21 的组合视图
                                               D10[31:0] = S20, D10[63:32] = S21
                                               参考：D1.2.19 Dn, Floating-point Double-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_D11             0x0B    /* Doubleword floating-point register D11 - 双字浮点寄存器 D11 [RW]
                                               64 位浮点数据寄存器，S22 和 S23 的组合视图
                                               D11[31:0] = S22, D11[63:32] = S23
                                               参考：D1.2.19 Dn, Floating-point Double-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_D12             0x0C    /* Doubleword floating-point register D12 - 双字浮点寄存器 D12 [RW]
                                               64 位浮点数据寄存器，S24 和 S25 的组合视图
                                               D12[31:0] = S24, D12[63:32] = S25
                                               参考：D1.2.19 Dn, Floating-point Double-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_D13             0x0D    /* Doubleword floating-point register D13 - 双字浮点寄存器 D13 [RW]
                                               64 位浮点数据寄存器，S26 和 S27 的组合视图
                                               D13[31:0] = S26, D13[63:32] = S27
                                               参考：D1.2.19 Dn, Floating-point Double-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_D14             0x0E    /* Doubleword floating-point register D14 - 双字浮点寄存器 D14 [RW]
                                               64 位浮点数据寄存器，S28 和 S29 的组合视图
                                               D14[31:0] = S28, D14[63:32] = S29
                                               参考：D1.2.19 Dn, Floating-point Double-precision register n
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_D15             0x0F    /* Doubleword floating-point register D15 - 双字浮点寄存器 D15 [RW]
                                               64 位浮点数据寄存器，S30 和 S31 的组合视图
                                               D15[31:0] = S30, D15[63:32] = S31
                                               参考：D1.2.19 Dn, Floating-point Double-precision register n
                                               备注：仅 FP 扩展时可用 */

/* -----------------------------------------------------------------------------
 * 2.3 浮点特性寄存器
 * 参考: D1.2.178 MVFR0, Media and VFP Feature Register 0
 *      D1.2.179 MVFR1, Media and VFP Feature Register 1
 *      D1.2.180 MVFR2, Media and VFP Feature Register 2
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_MVFR0           0x000   /* Media and VFP Feature Register 0 - 媒体和 VFP 特性寄存器 0 [RO]
                                               地址: 0xE000EF40
                                               只读寄存器，提供浮点扩展的特性信息
                                               参考：D1.2.178 MVFR0, Media and VFP Feature Register 0
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_MVFR1           0x004   /* Media and VFP Feature Register 1 - 媒体和 VFP 特性寄存器 1 [RO]
                                               地址: 0xE000EF44
                                               只读寄存器，提供浮点扩展的特性信息
                                               参考：D1.2.179 MVFR1, Media and VFP Feature Register 1
                                               备注：仅 FP 扩展时可用 */

#define ARM_V8M_REG_MVFR2           0x008   /* Media and VFP Feature Register 2 - 媒体和 VFP 特性寄存器 2 [RO]
                                               地址: 0xE000EF48
                                               只读寄存器，提供浮点扩展的特性信息
                                               参考：D1.2.180 MVFR2, Media and VFP Feature Register 2
                                               备注：仅 FP 扩展时可用 */

/* ==============================================================================
 * 三、系统控制空间 (SCS) - System Control Space
 * 参考: D1.2 Alphabetical list of registers
 * 基地址: 0xE000E000 (Secure), 0xE002E000 (Non-secure 别名)
 * NS 别名说明: Secure 状态可通过 NS 别名访问 Non-secure 状态的 SCS 寄存器
 * ==============================================================================
 */
#define ARM_V8M_SCS_BASE            0xE000E000UL  /* SCS Secure 基地址 */
#define ARM_V8M_SCS_NS_BASE         0xE002E000UL  /* SCS Non-secure 别名基地址 - 仅 Secure 状态可通过此地址访问 Non-secure 寄存器 */

/* -----------------------------------------------------------------------------
 * 3.0 SCS 系统控制寄存器 (不在 SCB 中的寄存器)
 * 参考: D1.2.127 ICTR, Interrupt Controller Type Register
 *      D1.2.1 ACTLR, Auxiliary Control Register
 *      D1.2.15 CPPWR, Coprocessor Power Control Register
 * 地址范围: 0xE000E004 - 0xE000E00C
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCS_ICTR            0x004   /* Interrupt Controller Type Register - 中断控制器类型寄存器 [RO]
                                               地址: 0xE000E004
                                               提供中断控制器的信息
                                               指示实现的外部中断线数量 (INTLINESNUM)
                                               INTLINESNUM = 支持的外部中断数 / 32 - 1
                                               只读寄存器，硬件实现时确定
                                               软件可以读取以确定 NVIC 的大小
                                               实现 Security Extension 时，Secure 软件可通过 ICTR_NS 访问 Non-secure 版本 (地址 0xE002E004)
                                               参考：D1.2.127 ICTR, Interrupt Controller Type Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCS_ACTLR           0x008   /* Auxiliary Control Register - 辅助控制寄存器 [RW]
                                               地址: 0xE000E008
                                               提供 IMPLEMENTATION DEFINED 辅助控制特性
                                               位域定义取决于具体的处理器实现，架构手册未定义具体位域
                                               具体请参考处理器厂商的技术参考手册
                                               实现 Security Extension 时，Secure 软件可通过 ACTLR_NS 访问 Non-secure 版本 (地址 0xE002E008)
                                               参考：D1.2.1 ACTLR, Auxiliary Control Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCS_CPPWR           0x00C   /* Coprocessor Power Control Register - 协处理器电源控制寄存器 [RW]
                                               地址: 0xE000E00C
                                               控制协处理器的电源管理
                                               实现 Security Extension 时，Secure 软件可通过 CPPWR_NS 访问 Non-secure 版本 (地址 0xE002E00C)
                                               参考：D1.2.15 CPPWR, Coprocessor Power Control Register
                                               备注：Armv8.1-M 及更高版本可选
                                               【v8m 独有】v7m 中不存在此寄存器 */

/* -----------------------------------------------------------------------------
 * 3.1 系统控制块 (SCB) - System Control Block
 * 参考: D1.2 寄存器描述
 * 地址范围: 0xE000ED00 - 0xE000ED8F (Secure), 0xE002ED00 - 0xE002ED8F (Non-secure 别名)
 * NS 别名说明: Secure 状态可通过 NS 别名访问 Non-secure 状态的 SCB 寄存器
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCB_BASE            0xE000ED00UL  /* SCB Secure 基地址 */
#define ARM_V8M_SCB_NS_BASE         0xE002ED00UL  /* SCB Non-secure 别名基地址 - 仅 Secure 状态可通过此地址访问 Non-secure 寄存器 */

#define ARM_V8M_SCB_REVIDR          0x0FC   /* Revision ID Register - 版本 ID 寄存器 [RO]
                                               地址: 0xE000ECFC
                                               提供实现的修订版本信息
                                               只读寄存器，硬件实现时确定
                                               实现 Security Extension 时，Secure 软件可通过 REVIDR_NS 访问 Non-secure 版本 (地址 0xE002ECFC)
                                               参考：D1.2.222 REVIDR, Revision ID Register
                                               备注：Armv8.1-M 及更高版本可选
                                               【v8m 独有】v7m 中不存在此寄存器 */

#define ARM_V8M_SCB_CPUID           0x000   /* CPUID Base Register - CPUID 基寄存器 [RO]
                                               地址: 0xE000ED00
                                               提供处理器标识信息，包含架构版本、实现者ID、零件号、修订版本等
                                               只读寄存器，上电复位时由硬件设置
                                               用于操作系统和调试器识别处理器类型和特性
                                               实现 Security Extension 时，Secure 软件可通过 CPUID_NS 访问 Non-secure 版本 (地址 0xE002ED00)
                                               参考：D1.2.16 CPUID, CPUID Base Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_ICSR            0x004   /* Interrupt Control and State Register - 中断控制和状态寄存器 [RW]
                                               地址: 0xE000ED04
                                               提供 NMI、PendSV 和 SysTick 异常的软件控制
                                               提供中断状态信息，包括当前活跃的异常编号
                                               可通过软件触发 PendSV 和 SysTick 异常
                                               包含中断挂起和活跃标志
                                               实现 Security Extension 时，Secure 软件可通过 ICSR_NS 访问 Non-secure 版本 (地址 0xE002ED04)
                                               参考：D1.2.126 ICSR, Interrupt Control and State Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_VTOR            0x008   /* Vector Table Offset Register - 向量表偏移寄存器 [RW]
                                               地址: 0xE000ED08
                                               保存向量表的基地址
                                               向量表包含所有异常处理程序的入口地址
                                               软件可在运行时重新定位向量表
                                               复位时默认值为 0x00000000
                                               实现 Security Extension 时，Secure 软件可通过 VTOR_NS 访问 Non-secure 版本 (地址 0xE002ED08)
                                               参考：D1.2.272 VTOR, Vector Table Offset Register
                                               备注：仅 Main Extension 时可用 */

#define ARM_V8M_SCB_AIRCR           0x00C   /* Application Interrupt and Reset Control Register - 应用程序中断和复位控制寄存器 [RW]
                                               地址: 0xE000ED0C
                                               设置或返回中断控制和复位配置
                                               包含 VECTKEY、PRIGROUP、SYSRESETREQ、VECTCLRACTIVE 等位
                                               实现 Security Extension 时，Secure 软件可通过 AIRCR_NS 访问 Non-secure 版本 (地址 0xE002ED0C)
                                               参考：D1.2.3 AIRCR, Application Interrupt and Reset Control Register
                                               备注：仅 Main Extension 时可用 */

#define ARM_V8M_SCB_SCR             0x010   /* System Control Register - 系统控制寄存器 [RW]
                                               地址: 0xE000ED10
                                               控制系统的低功耗特性
                                               包含 SLEEPONEXIT、SLEEPDEEP、SEVONPEND 等位
                                               实现 Security Extension 时，Secure 软件可通过 SCR_NS 访问 Non-secure 版本 (地址 0xE002ED10)
                                               参考：D1.2.230 SCR, System Control Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_CCR             0x014   /* Configuration and Control Register - 配置和控制寄存器 [RW]
                                               地址: 0xE000ED14
                                               控制处理器的配置特性
                                               包含 NONBASETHRDENA、USERSETMPEND、UNALIGN_TRP、DIV_0_TRP、BFHFNMINS、STKALIGN、DC、IC、BP、STKOFHFNMIGN 等位
                                               实现 Security Extension 时，Secure 软件可通过 CCR_NS 访问 Non-secure 版本 (地址 0xE002ED14)
                                               参考：D1.2.9 CCR, Configuration and Control Register
                                               备注：仅 Main Extension 时可用 */

#define ARM_V8M_SCB_SHPR1           0x018   /* System Handler Priority Register 1 - 系统处理器优先级寄存器 1 [RW]
                                               地址: 0xE000ED18
                                               设置系统异常 4-7 的优先级 (MemoryManagement、BusFault、UsageFault、SecureFault)
                                               实现 Security Extension 时，Secure 软件可通过 SHPR1_NS 访问 Non-secure 版本 (地址 0xE002ED18)
                                               参考：D1.2.234 SHPR1, System Handler Priority Register 1
                                               备注：仅 Main Extension 时可用 */

#define ARM_V8M_SCB_SHPR2           0x01C   /* System Handler Priority Register 2 - 系统处理器优先级寄存器 2 [RW]
                                               地址: 0xE000ED1C
                                               设置系统异常 8-11 的优先级 (SVCall)
                                               实现 Security Extension 时，Secure 软件可通过 SHPR2_NS 访问 Non-secure 版本 (地址 0xE002ED1C)
                                               参考：D1.2.235 SHPR2, System Handler Priority Register 2
                                               备注：仅 Main Extension 时可用 */

#define ARM_V8M_SCB_SHPR3           0x020   /* System Handler Priority Register 3 - 系统处理器优先级寄存器 3 [RW]
                                               地址: 0xE000ED20
                                               设置系统异常 12-15 的优先级 (PendSV、SysTick)
                                               实现 Security Extension 时，Secure 软件可通过 SHPR3_NS 访问 Non-secure 版本 (地址 0xE002ED20)
                                               参考：D1.2.236 SHPR3, System Handler Priority Register 3
                                               备注：仅 Main Extension 时可用 */

#define ARM_V8M_SCB_SHCSR           0x024   /* System Handler Control and State Register - 系统处理器控制和状态寄存器 [RW]
                                               地址: 0xE000ED24
                                               控制系统异常的使能和挂起状态
                                               包含 MEMFAULTENA、BUSFAULTENA、USGFAULTENA、SECUREFAULTENA、MEMFAULTACT、BUSFAULTACT、USGFAULTACT、SECUREFAULTACT、SVCALLACT、MONITORACT、PENDSVACT、SYSTICKACT、USGFAULTPENDED、MEMFAULTPENDED、BUSFAULTPENDED、SECUREFAULTPENDED、SVCALLPENDED、MONITORPENDED、PENDSVPENDED、SYSTICKPENDED 等位
                                               实现 Security Extension 时，Secure 软件可通过 SHCSR_NS 访问 Non-secure 版本 (地址 0xE002ED24)
                                               参考：D1.2.233 SHCSR, System Handler Control and State Register
                                               备注：仅 Main Extension 时可用 */

#define ARM_V8M_SCB_CFSR            0x028   /* Configurable Fault Status Register - 可配置故障状态寄存器 [RW]
                                               地址: 0xE000ED28
                                               包含 MemManage、BusFault 和 UsageFault 的状态
                                               实现 Security Extension 时，Secure 软件可通过 CFSR_NS 访问 Non-secure 版本 (地址 0xE002ED28)
                                               参考：D1.2.11 CFSR, Configurable Fault Status Register
                                               备注：仅 Main Extension 时可用 */

#define ARM_V8M_SCB_MMFSR           0x028   /* MemManage Fault Status Register - MemManage 故障状态寄存器 [RW]
                                               地址: 0xE000ED28 (CFSR 的低 8 位)
                                               包含 MemManage 故障的状态
                                               实现 Security Extension 时，Secure 软件可通过 MMFSR_NS 访问 Non-secure 版本 (地址 0xE002ED28)
                                               参考：D1.2.167 MMFSR, MemManage Fault Status Register
                                               备注：仅 Main Extension 时可用 */

#define ARM_V8M_SCB_BFSR            0x029   /* BusFault Status Register - BusFault 状态寄存器 [RW]
                                               地址: 0xE000ED29 (CFSR 的中 8 位)
                                               包含 BusFault 故障的状态
                                               实现 Security Extension 时，Secure 软件可通过 BFSR_NS 访问 Non-secure 版本 (地址 0xE002ED29)
                                               参考：D1.2.7 BFSR, BusFault Status Register
                                               备注：仅 Main Extension 时可用 */

#define ARM_V8M_SCB_UFSR            0x02A   /* UsageFault Status Register - UsageFault 状态寄存器 [RW]
                                               地址: 0xE000ED2A (CFSR 的高 16 位)
                                               包含 UsageFault 故障的状态
                                               实现 Security Extension 时，Secure 软件可通过 UFSR_NS 访问 Non-secure 版本 (地址 0xE002ED2A)
                                               参考：D1.2.270 UFSR, UsageFault Status Register
                                               备注：仅 Main Extension 时可用 */

#define ARM_V8M_SCB_HFSR            0x02C   /* HardFault Status Register - HardFault 状态寄存器 [RW]
                                               地址: 0xE000ED2C
                                               包含 HardFault 的状态
                                               实现 Security Extension 时，Secure 软件可通过 HFSR_NS 访问 Non-secure 版本 (地址 0xE002ED2C)
                                               参考：D1.2.123 HFSR, HardFault Status Register
                                               备注：仅 Main Extension 时可用 */

#define ARM_V8M_SCB_DFSR            0x030   /* Debug Fault Status Register - 调试故障状态寄存器 [RW]
                                               地址: 0xE000ED30
                                               包含调试故障的状态
                                               实现 Security Extension 时，Secure 软件可通过 DFSR_NS 访问 Non-secure 版本 (地址 0xE002ED30)
                                               参考：D1.2.38 DFSR, Debug Fault Status Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_SCB_MMFAR           0x034   /* MemManage Fault Address Register - MemManage 故障地址寄存器 [RW]
                                               地址: 0xE000ED34
                                               保存导致 MemManage 故障的地址
                                               实现 Security Extension 时，Secure 软件可通过 MMFAR_NS 访问 Non-secure 版本 (地址 0xE002ED34)
                                               参考：D1.2.166 MMFAR, MemManage Fault Address Register
                                               备注：仅 Main Extension 时可用 */

#define ARM_V8M_SCB_BFAR            0x038   /* BusFault Address Register - BusFault 地址寄存器 [RW]
                                               地址: 0xE000ED38
                                               保存导致 BusFault 故障的地址
                                               实现 Security Extension 时，Secure 软件可通过 BFAR_NS 访问 Non-secure 版本 (地址 0xE002ED38)
                                               参考：D1.2.6 BFAR, BusFault Address Register
                                               备注：仅 Main Extension 时可用 */

#define ARM_V8M_SCB_AFSR            0x03C   /* Auxiliary Fault Status Register - 辅助故障状态寄存器 [RW]
                                               地址: 0xE000ED3C
                                               提供 IMPLEMENTATION DEFINED 故障状态信息
                                               实现 Security Extension 时，Secure 软件可通过 AFSR_NS 访问 Non-secure 版本 (地址 0xE002ED3C)
                                               参考：D1.2.2 AFSR, Auxiliary Fault Status Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_CPACR           0x088   /* Coprocessor Access Control Register - 协处理器访问控制寄存器 [RW]
                                               地址: 0xE000ED88
                                               控制协处理器的访问权限
                                               实现 Security Extension 时，Secure 软件可通过 CPACR_NS 访问 Non-secure 版本 (地址 0xE002ED88)
                                               参考：D1.2.14 CPACR, Coprocessor Access Control Register
                                               备注：仅 Main Extension 时可用 */

#define ARM_V8M_SCB_NSACR           0x08C   /* Non-secure Access Control Register - Non-secure 访问控制寄存器 [RW]
                                               地址: 0xE000ED8C
                                               控制 Non-secure 状态对协处理器等的访问
                                               仅实现 Security Extension 时可用
                                               参考：D1.2.181 NSACR, Non-secure Access Control Register
                                               备注：仅 Security Extension 时可用
                                               【v8m 独有】v7m 中不存在此寄存器 */

/* -----------------------------------------------------------------------------
 * 3.2 特性识别寄存器
 * 参考: D1.2 寄存器描述
 * 地址范围: 0xE000ED40 - 0xE000ED7C
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCB_ID_PFR0         0x040   /* Processor Feature Register 0 - 处理器特性寄存器 0 [RO]
                                               地址: 0xE000ED40
                                               只读寄存器，提供处理器特性信息
                                               实现 Security Extension 时，Secure 软件可通过 ID_PFR0_NS 访问 Non-secure 版本 (地址 0xE002ED40)
                                               参考：D1.2.140 ID_PFR0, Processor Feature Register 0
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_ID_PFR1         0x044   /* Processor Feature Register 1 - 处理器特性寄存器 1 [RO]
                                               地址: 0xE000ED44
                                               只读寄存器，提供处理器特性信息
                                               实现 Security Extension 时，Secure 软件可通过 ID_PFR1_NS 访问 Non-secure 版本 (地址 0xE002ED44)
                                               参考：D1.2.141 ID_PFR1, Processor Feature Register 1
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_ID_DFR0         0x048   /* Debug Feature Register 0 - 调试特性寄存器 0 [RO]
                                               地址: 0xE000ED48
                                               只读寄存器，提供调试特性信息
                                               实现 Security Extension 时，Secure 软件可通过 ID_DFR0_NS 访问 Non-secure 版本 (地址 0xE002ED48)
                                               参考：D1.2.129 ID_DFR0, Debug Feature Register 0
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_SCB_ID_AFR0         0x04C   /* Auxiliary Feature Register 0 - 辅助特性寄存器 0 [RO]
                                               地址: 0xE000ED4C
                                               只读寄存器，提供辅助特性信息
                                               实现 Security Extension 时，Secure 软件可通过 ID_AFR0_NS 访问 Non-secure 版本 (地址 0xE002ED4C)
                                               参考：D1.2.128 ID_AFR0, Auxiliary Feature Register 0
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_ID_MMFR0        0x050   /* Memory Model Feature Register 0 - 内存模型特性寄存器 0 [RO]
                                               地址: 0xE000ED50
                                               只读寄存器，提供内存模型特性信息
                                               实现 Security Extension 时，Secure 软件可通过 ID_MMFR0_NS 访问 Non-secure 版本 (地址 0xE002ED50)
                                               参考：D1.2.136 ID_MMFR0, Memory Model Feature Register 0
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_ID_MMFR1        0x054   /* Memory Model Feature Register 1 - 内存模型特性寄存器 1 [RO]
                                               地址: 0xE000ED54
                                               只读寄存器，提供内存模型特性信息
                                               实现 Security Extension 时，Secure 软件可通过 ID_MMFR1_NS 访问 Non-secure 版本 (地址 0xE002ED54)
                                               参考：D1.2.137 ID_MMFR1, Memory Model Feature Register 1
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_ID_MMFR2        0x058   /* Memory Model Feature Register 2 - 内存模型特性寄存器 2 [RO]
                                               地址: 0xE000ED58
                                               只读寄存器，提供内存模型特性信息
                                               实现 Security Extension 时，Secure 软件可通过 ID_MMFR2_NS 访问 Non-secure 版本 (地址 0xE002ED58)
                                               参考：D1.2.138 ID_MMFR2, Memory Model Feature Register 2
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_ID_MMFR3        0x05C   /* Memory Model Feature Register 3 - 内存模型特性寄存器 3 [RO]
                                               地址: 0xE000ED5C
                                               只读寄存器，提供内存模型特性信息
                                               实现 Security Extension 时，Secure 软件可通过 ID_MMFR3_NS 访问 Non-secure 版本 (地址 0xE002ED5C)
                                               参考：D1.2.139 ID_MMFR3, Memory Model Feature Register 3
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_ID_ISAR0        0x060   /* Instruction Set Attribute Register 0 - 指令集属性寄存器 0 [RO]
                                               地址: 0xE000ED60
                                               只读寄存器，提供指令集属性信息
                                               实现 Security Extension 时，Secure 软件可通过 ID_ISAR0_NS 访问 Non-secure 版本 (地址 0xE002ED60)
                                               参考：D1.2.130 ID_ISAR0, Instruction Set Attribute Register 0
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_ID_ISAR1        0x064   /* Instruction Set Attribute Register 1 - 指令集属性寄存器 1 [RO]
                                               地址: 0xE000ED64
                                               只读寄存器，提供指令集属性信息
                                               实现 Security Extension 时，Secure 软件可通过 ID_ISAR1_NS 访问 Non-secure 版本 (地址 0xE002ED64)
                                               参考：D1.2.131 ID_ISAR1, Instruction Set Attribute Register 1
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_ID_ISAR2        0x068   /* Instruction Set Attribute Register 2 - 指令集属性寄存器 2 [RO]
                                               地址: 0xE000ED68
                                               只读寄存器，提供指令集属性信息
                                               实现 Security Extension 时，Secure 软件可通过 ID_ISAR2_NS 访问 Non-secure 版本 (地址 0xE002ED68)
                                               参考：D1.2.132 ID_ISAR2, Instruction Set Attribute Register 2
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_ID_ISAR3        0x06C   /* Instruction Set Attribute Register 3 - 指令集属性寄存器 3 [RO]
                                               地址: 0xE000ED6C
                                               只读寄存器，提供指令集属性信息
                                               实现 Security Extension 时，Secure 软件可通过 ID_ISAR3_NS 访问 Non-secure 版本 (地址 0xE002ED6C)
                                               参考：D1.2.133 ID_ISAR3, Instruction Set Attribute Register 3
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_ID_ISAR4        0x070   /* Instruction Set Attribute Register 4 - 指令集属性寄存器 4 [RO]
                                               地址: 0xE000ED70
                                               只读寄存器，提供指令集属性信息
                                               实现 Security Extension 时，Secure 软件可通过 ID_ISAR4_NS 访问 Non-secure 版本 (地址 0xE002ED70)
                                               参考：D1.2.134 ID_ISAR4, Instruction Set Attribute Register 4
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_ID_ISAR5        0x074   /* Instruction Set Attribute Register 5 - 指令集属性寄存器 5 [RO]
                                               地址: 0xE000ED74
                                               只读寄存器，提供指令集属性信息
                                               实现 Security Extension 时，Secure 软件可通过 ID_ISAR5_NS 访问 Non-secure 版本 (地址 0xE002ED74)
                                               参考：D1.2.135 ID_ISAR5, Instruction Set Attribute Register 5
                                               备注：适用于所有 Armv8-M 实现 */

/* -----------------------------------------------------------------------------
 * 3.3 缓存识别寄存器
 * 参考: D1.2 寄存器描述
 * 地址范围: 0xE000ED78 - 0xE000ED84
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCB_CLIDR           0x078   /* Cache Level ID Register - 缓存级别 ID 寄存器 [RO]
                                               地址: 0xE000ED78
                                               只读寄存器，提供缓存层次结构信息
                                               实现 Security Extension 时，Secure 软件可通过 CLIDR_NS 访问 Non-secure 版本 (地址 0xE002ED78)
                                               参考：D1.2.12 CLIDR, Cache Level ID Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_CTR             0x07C   /* Cache Type Register - 缓存类型寄存器 [RO]
                                               地址: 0xE000ED7C
                                               只读寄存器，提供缓存类型信息
                                               实现 Security Extension 时，Secure 软件可通过 CTR_NS 访问 Non-secure 版本 (地址 0xE002ED7C)
                                               参考：D1.2.18 CTR, Cache Type Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_CCSIDR          0x080   /* Current Cache Size ID register - 当前缓存大小 ID 寄存器 [RO]
                                               地址: 0xE000ED80
                                               只读寄存器，提供当前选中缓存的大小信息
                                               实现 Security Extension 时，Secure 软件可通过 CCSIDR_NS 访问 Non-secure 版本 (地址 0xE002ED80)
                                               参考：D1.2.10 CCSIDR, Current Cache Size ID register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_CSSELR          0x084   /* Cache Size Selection Register - 缓存大小选择寄存器 [RW]
                                               地址: 0xE000ED84
                                               选择要访问的缓存级别和类型
                                               实现 Security Extension 时，Secure 软件可通过 CSSELR_NS 访问 Non-secure 版本 (地址 0xE002ED84)
                                               参考：D1.2.17 CSSELR, Cache Size Selection Register
                                               备注：适用于所有 Armv8-M 实现 */

/* -----------------------------------------------------------------------------
 * 3.4 内存保护单元 (MPU)
 * 参考: D1.2 寄存器描述
 * 地址范围: 0xE000ED90 - 0xE000EDC4 (Secure), 0xE002ED90 - 0xE002EDC4 (Non-secure 别名)
 * NS 别名说明: Secure 状态可通过 NS 别名访问 Non-secure 状态的 MPU 寄存器
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_MPU_BASE            0xE000ED90UL  /* MPU Secure 基地址 */
#define ARM_V8M_MPU_NS_BASE         0xE002ED90UL  /* MPU Non-secure 别名基地址 - 仅 Secure 状态可通过此地址访问 Non-secure 寄存器 */

#define ARM_V8M_MPU_TYPE            0x000   /* MPU Type Register - MPU 类型寄存器 [RO]
                                               地址: 0xE000ED90
                                               只读寄存器，提供 MPU 的特性信息
                                               实现 Security Extension 时，Secure 软件可通过 MPU_TYPE_NS 访问 Non-secure 版本 (地址 0xE002ED90)
                                               参考：D1.2.176 MPU_TYPE, MPU Type Register
                                               备注：仅 MPU 扩展时可用 */

#define ARM_V8M_MPU_CTRL            0x004   /* MPU Control Register - MPU 控制寄存器 [RW]
                                               地址: 0xE000ED94
                                               控制 MPU 的使能和配置
                                               实现 Security Extension 时，Secure 软件可通过 MPU_CTRL_NS 访问 Non-secure 版本 (地址 0xE002ED94)
                                               参考：D1.2.168 MPU_CTRL, MPU Control Register
                                               备注：仅 MPU 扩展时可用 */

#define ARM_V8M_MPU_RNR             0x008   /* MPU Region Number Register - MPU 区域编号寄存器 [RW]
                                               地址: 0xE000ED98
                                               选择要配置的 MPU 区域
                                               实现 Security Extension 时，Secure 软件可通过 MPU_RNR_NS 访问 Non-secure 版本 (地址 0xE002ED98)
                                               参考：D1.2.175 MPU_RNR, MPU Region Number Register
                                               备注：仅 MPU 扩展时可用 */

#define ARM_V8M_MPU_RBAR            0x00C   /* MPU Region Base Address Register - MPU 区域基址寄存器 [RW]
                                               地址: 0xE000ED9C
                                               存储 MPU 区域的基地址
                                               实现 Security Extension 时，Secure 软件可通过 MPU_RBAR_NS 访问 Non-secure 版本 (地址 0xE002ED9C)
                                               参考：D1.2.171 MPU_RBAR, MPU Region Base Address Register
                                               备注：仅 MPU 扩展时可用 */

#define ARM_V8M_MPU_RLAR            0x010   /* MPU Region Limit Address Register - MPU 区域限制地址寄存器 [RW]
                                               地址: 0xE000EDA0
                                               存储 MPU 区域的限制地址和属性
                                               实现 Security Extension 时，Secure 软件可通过 MPU_RLAR_NS 访问 Non-secure 版本 (地址 0xE002EDA0)
                                               参考：D1.2.173 MPU_RLAR, MPU Region Limit Address Register
                                               备注：仅 MPU 扩展时可用
                                               【v8m 独有】v7m 中使用 MPU_RASR 替代此寄存器 */

#define ARM_V8M_MPU_RBAR_A1         0x014   /* MPU Region Base Address Register Alias 1 - MPU 区域基址寄存器别名 1 [RW]
                                               地址: 0xE000EDA4
                                               MPU_RBAR 的别名寄存器，用于快速配置多个区域
                                               实现 Security Extension 时，Secure 软件可通过 MPU_RBAR_A1_NS 访问 Non-secure 版本 (地址 0xE002EDA4)
                                               参考：D1.2.172 MPU_RBAR_An, MPU Region Base Address Register Alias n
                                               备注：仅 MPU 扩展时可用 */

#define ARM_V8M_MPU_RLAR_A1         0x018   /* MPU Region Limit Address Register Alias 1 - MPU 区域限制地址寄存器别名 1 [RW]
                                               地址: 0xE000EDA8
                                               MPU_RLAR 的别名寄存器，用于快速配置多个区域
                                               实现 Security Extension 时，Secure 软件可通过 MPU_RLAR_A1_NS 访问 Non-secure 版本 (地址 0xE002EDA8)
                                               参考：D1.2.174 MPU_RLAR_An, MPU Region Limit Address Register Alias n
                                               备注：仅 MPU 扩展时可用 */

#define ARM_V8M_MPU_RBAR_A2         0x01C   /* MPU Region Base Address Register Alias 2 - MPU 区域基址寄存器别名 2 [RW]
                                               地址: 0xE000EDAC
                                               MPU_RBAR 的别名寄存器，用于快速配置多个区域
                                               实现 Security Extension 时，Secure 软件可通过 MPU_RBAR_A2_NS 访问 Non-secure 版本 (地址 0xE002EDAC)
                                               参考：D1.2.172 MPU_RBAR_An, MPU Region Base Address Register Alias n
                                               备注：仅 MPU 扩展时可用 */

#define ARM_V8M_MPU_RLAR_A2         0x020   /* MPU Region Limit Address Register Alias 2 - MPU 区域限制地址寄存器别名 2 [RW]
                                               地址: 0xE000EDB0
                                               MPU_RLAR 的别名寄存器，用于快速配置多个区域
                                               实现 Security Extension 时，Secure 软件可通过 MPU_RLAR_A2_NS 访问 Non-secure 版本 (地址 0xE002EDB0)
                                               参考：D1.2.174 MPU_RLAR_An, MPU Region Limit Address Register Alias n
                                               备注：仅 MPU 扩展时可用 */

#define ARM_V8M_MPU_RBAR_A3         0x024   /* MPU Region Base Address Register Alias 3 - MPU 区域基址寄存器别名 3 [RW]
                                               地址: 0xE000EDB4
                                               MPU_RBAR 的别名寄存器，用于快速配置多个区域
                                               实现 Security Extension 时，Secure 软件可通过 MPU_RBAR_A3_NS 访问 Non-secure 版本 (地址 0xE002EDB4)
                                               参考：D1.2.172 MPU_RBAR_An, MPU Region Base Address Register Alias n
                                               备注：仅 MPU 扩展时可用 */

#define ARM_V8M_MPU_RLAR_A3         0x028   /* MPU Region Limit Address Register Alias 3 - MPU 区域限制地址寄存器别名 3 [RW]
                                               地址: 0xE000EDB8
                                               MPU_RLAR 的别名寄存器，用于快速配置多个区域
                                               实现 Security Extension 时，Secure 软件可通过 MPU_RLAR_A3_NS 访问 Non-secure 版本 (地址 0xE002EDB8)
                                               参考：D1.2.174 MPU_RLAR_An, MPU Region Limit Address Register Alias n
                                               备注：仅 MPU 扩展时可用 */

#define ARM_V8M_MPU_MAIR0           0x030   /* MPU Memory Attribute Indirection Register 0 - MPU 内存属性间接寄存器 0 [RW]
                                               地址: 0xE000EDC0
                                               存储内存属性编码 (Attr0-Atty3)
                                               实现 Security Extension 时，Secure 软件可通过 MPU_MAIR0_NS 访问 Non-secure 版本 (地址 0xE002EDC0)
                                               参考：D1.2.169 MPU_MAIR0, MPU Memory Attribute Indirection Register 0
                                               备注：仅 MPU 扩展时可用
                                               【v8m 独有】v7m 中不存在此寄存器 */

#define ARM_V8M_MPU_MAIR1           0x034   /* MPU Memory Attribute Indirection Register 1 - MPU 内存属性间接寄存器 1 [RW]
                                               地址: 0xE000EDC4
                                               存储内存属性编码 (Attr4-Atty7)
                                               实现 Security Extension 时，Secure 软件可通过 MPU_MAIR1_NS 访问 Non-secure 版本 (地址 0xE002EDC4)
                                               参考：D1.2.170 MPU_MAIR1, MPU Memory Attribute Indirection Register 1
                                               备注：仅 MPU 扩展时可用
                                               【v8m 独有】v7m 中不存在此寄存器 */

/* -----------------------------------------------------------------------------
 * 3.5 安全属性单元 (SAU) 和安全故障寄存器
 * 参考: D1.2 寄存器描述
 * 地址范围: 0xE000EDD0 - 0xE000EDE8
 * 注意: SAU 和安全故障寄存器仅 Secure 状态可访问，没有 NS 别名
 * 【v8m 独有】v7m 中不存在 Security Extension 和 SAU 寄存器
 * ----------------------------------------------------------------------------- */
#define ARM_V8M_SAU_BASE            0xE000EDD0UL  /* SAU 基地址 - 仅 Secure 状态可访问，无 NS 别名 */

#define ARM_V8M_SAU_CTRL            0x000   /* SAU Control Register - SAU 控制寄存器 [RW]
                                               地址: 0xE000EDD0
                                               控制 SAU 的使能和配置
                                               仅 Secure 状态可访问
                                               参考：D1.2.225 SAU_CTRL, SAU Control Register
                                               备注：仅 Security Extension 时可用 */

#define ARM_V8M_SAU_TYPE            0x004   /* SAU Type Register - SAU 类型寄存器 [RO]
                                               地址: 0xE000EDD4
                                               只读寄存器，提供 SAU 的特性信息
                                               仅 Secure 状态可访问
                                               参考：D1.2.229 SAU_TYPE, SAU Type Register
                                               备注：仅 Security Extension 时可用 */

#define ARM_V8M_SAU_RNR             0x008   /* SAU Region Number Register - SAU 区域编号寄存器 [RW]
                                               地址: 0xE000EDD8
                                               选择要配置的 SAU 区域
                                               仅 Secure 状态可访问
                                               参考：D1.2.228 SAU_RNR, SAU Region Number Register
                                               备注：仅 Security Extension 时可用 */

#define ARM_V8M_SAU_RBAR            0x00C   /* SAU Region Base Address Register - SAU 区域基址寄存器 [RW]
                                               地址: 0xE000EDDC
                                               存储 SAU 区域的基地址
                                               仅 Secure 状态可访问
                                               参考：D1.2.226 SAU_RBAR, SAU Region Base Address Register
                                               备注：仅 Security Extension 时可用 */

#define ARM_V8M_SAU_RLAR            0x010   /* SAU Region Limit Address Register - SAU 区域限制地址寄存器 [RW]
                                               地址: 0xE000EDE0
                                               存储 SAU 区域的限制地址和属性
                                               仅 Secure 状态可访问
                                               参考：D1.2.227 SAU_RLAR, SAU Region Limit Address Register
                                               备注：仅 Security Extension 时可用 */

#define ARM_V8M_SCB_SFSR            0x0E4   /* Secure Fault Status Register - 安全故障状态寄存器 [RW]
                                               地址: 0xE000EDE4
                                               包含安全故障的状态
                                               仅 Secure 状态可访问
                                               参考：D1.2.232 SFSR, Secure Fault Status Register
                                               备注：仅 Security Extension 时可用 */

#define ARM_V8M_SCB_SFAR            0x0E8   /* Secure Fault Address Register - 安全故障地址寄存器 [RW]
                                               地址: 0xE000EDE8
                                               保存导致安全故障的地址
                                               仅 Secure 状态可访问
                                               参考：D1.2.231 SFAR, Secure Fault Address Register
                                               备注：仅 Security Extension 时可用 */

/* -----------------------------------------------------------------------------
 * 3.6 SysTick 定时器
 * 参考: D1.2 寄存器描述
 * 地址范围: 0xE000E010 - 0xE000E01C (Secure), 0xE002E010 - 0xE002E01C (Non-secure 别名)
 * NS 别名说明: Secure 状态可通过 NS 别名访问 Non-secure 状态的 SysTick 寄存器
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SYST_BASE           0xE000E010UL  /* SysTick Secure 基地址 */
#define ARM_V8M_SYST_NS_BASE        0xE002E010UL  /* SysTick Non-secure 别名基地址 - 仅 Secure 状态可通过此地址访问 Non-secure 寄存器 */

#define ARM_V8M_SYST_CSR            0x000   /* SysTick Control and Status Register - SysTick 控制和状态寄存器 [RW]
                                               地址: 0xE000E010
                                               控制 SysTick 定时器的使能和配置
                                               实现 Security Extension 时，Secure 软件可通过 SYST_CSR_NS 访问 Non-secure 版本 (地址 0xE002E010)
                                               参考：D1.2.241 SYST_CSR, SysTick Control and Status Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SYST_RVR            0x004   /* SysTick Reload Value Register - SysTick 重装载值寄存器 [RW]
                                               地址: 0xE000E014
                                               存储 SysTick 定时器的重装载值
                                               实现 Security Extension 时，Secure 软件可通过 SYST_RVR_NS 访问 Non-secure 版本 (地址 0xE002E014)
                                               参考：D1.2.243 SYST_RVR, SysTick Reload Value Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SYST_CVR            0x008   /* SysTick Current Value Register - SysTick 当前值寄存器 [RW]
                                               地址: 0xE000E018
                                               存储 SysTick 定时器的当前值
                                               实现 Security Extension 时，Secure 软件可通过 SYST_CVR_NS 访问 Non-secure 版本 (地址 0xE002E018)
                                               参考：D1.2.242 SYST_CVR, SysTick Current Value Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SYST_CALIB          0x00C   /* SysTick Calibration Value Register - SysTick 校准值寄存器 [RO]
                                               地址: 0xE000E01C
                                               只读寄存器，提供 SysTick 校准信息
                                               实现 Security Extension 时，Secure 软件可通过 SYST_CALIB_NS 访问 Non-secure 版本 (地址 0xE002E01C)
                                               参考：D1.2.240 SYST_CALIB, SysTick Calibration Value Register
                                               备注：适用于所有 Armv8-M 实现 */

/* -----------------------------------------------------------------------------
 * 3.7 嵌套向量中断控制器 (NVIC)
 * 参考: D1.2 寄存器描述
 * 地址范围: 0xE000E100 - 0xE000E4FF (Secure), 0xE002E100 - 0xE002E4FF (Non-secure 别名)
 * NS 别名说明: Secure 状态可通过 NS 别名访问 Non-secure 状态的 NVIC 寄存器
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_NVIC_BASE           0xE000E100UL  /* NVIC Secure 基地址 */
#define ARM_V8M_NVIC_NS_BASE        0xE002E100UL  /* NVIC Non-secure 别名基地址 - 仅 Secure 状态可通过此地址访问 Non-secure 寄存器 */

#define ARM_V8M_NVIC_ISERn          0x000   /* Interrupt Set Enable Register n - 中断设置使能寄存器 n [RW]
                                               地址: 0xE000E100 + 0x20 * n
                                               使能外部中断
                                               实现 Security Extension 时，Secure 软件可通过 NVIC_ISERn_NS 访问 Non-secure 版本 (地址 0xE002E100 + 0x20 * n)
                                               参考：D1.2.186 NVIC_ISERn, Interrupt Set Enable Register n
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_NVIC_ICERn          0x080   /* Interrupt Clear Enable Register n - 中断清除使能寄存器 n [RW]
                                               地址: 0xE000E180 + 0x20 * n
                                               清除外部中断使能
                                               实现 Security Extension 时，Secure 软件可通过 NVIC_ICERn_NS 访问 Non-secure 版本 (地址 0xE002E180 + 0x20 * n)
                                               参考：D1.2.183 NVIC_ICERn, Interrupt Clear Enable Register n
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_NVIC_ISPRn          0x100   /* Interrupt Set Pending Register n - 中断设置待处理寄存器 n [RW]
                                               地址: 0xE000E200 + 0x20 * n
                                               设置外部中断挂起
                                               实现 Security Extension 时，Secure 软件可通过 NVIC_ISPRn_NS 访问 Non-secure 版本 (地址 0xE002E200 + 0x20 * n)
                                               参考：D1.2.187 NVIC_ISPRn, Interrupt Set Pending Register n
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_NVIC_ICPRn          0x180   /* Interrupt Clear Pending Register n - 中断清除待处理寄存器 n [RW]
                                               地址: 0xE000E280 + 0x20 * n
                                               清除外部中断挂起
                                               实现 Security Extension 时，Secure 软件可通过 NVIC_ICPRn_NS 访问 Non-secure 版本 (地址 0xE002E280 + 0x20 * n)
                                               参考：D1.2.184 NVIC_ICPRn, Interrupt Clear Pending Register n
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_NVIC_IABRn          0x200   /* Interrupt Active Bit Register n - 中断活动位寄存器 n [RO]
                                               地址: 0xE000E300 + 0x20 * n
                                               指示外部中断是否活跃
                                               实现 Security Extension 时，Secure 软件可通过 NVIC_IABRn_NS 访问 Non-secure 版本 (地址 0xE002E300 + 0x20 * n)
                                               参考：D1.2.182 NVIC_IABRn, Interrupt Active Bit Register n
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_NVIC_ITNSn          0x280   /* Interrupt Target Non-secure Register n - 中断目标 Non-secure 寄存器 n [RW]
                                               地址: 0xE000E380 + 0x20 * n
                                               配置中断目标为 Non-secure 状态
                                               仅实现 Security Extension 时可用
                                               参考：D1.2.188 NVIC_ITNSn, Interrupt Target Non-secure Register n
                                               备注：仅 Security Extension 时可用
                                               【v8m 独有】v7m 中不存在此寄存器 */

#define ARM_V8M_NVIC_IPRn           0x300   /* Interrupt Priority Register n - 中断优先级寄存器 n [RW]
                                               地址: 0xE000E400 + 0x04 * n
                                               设置外部中断的优先级
                                               实现 Security Extension 时，Secure 软件可通过 NVIC_IPRn_NS 访问 Non-secure 版本 (地址 0xE002E400 + 0x04 * n)
                                               参考：D1.2.185 NVIC_IPRn, Interrupt Priority Register n
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_SCB_STIR            0x100   /* Software Triggered Interrupt Register - 软件触发中断寄存器 [WO]
                                               地址: 0xE000EF00
                                               软件触发外部中断
                                               实现 Security Extension 时，Secure 软件可通过 STIR_NS 访问 Non-secure 版本 (地址 0xE002EF00)
                                               参考：D1.2.239 STIR, Software Triggered Interrupt Register
                                               备注：仅 Main Extension 时可用 */

/* -----------------------------------------------------------------------------
 * 3.8 缓存维护操作
 * 参考: D1.2 寄存器描述
 * 地址范围: 0xE000EF50 - 0xE000EF78 (Secure), 0xE002EF50 - 0xE002EF78 (Non-secure 别名)
 * NS 别名说明: Secure 状态可通过 NS 别名访问 Non-secure 状态的缓存维护操作
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_CACHE_BASE          0xE000EF50UL  /* 缓存维护操作 Secure 基地址 */
#define ARM_V8M_CACHE_NS_BASE       0xE002EF50UL  /* 缓存维护操作 Non-secure 别名基地址 - 仅 Secure 状态可通过此地址访问 Non-secure 寄存器 */

#define ARM_V8M_CACHE_ICIALLU       0x000   /* Instruction Cache Invalidate All to PoU - 指令缓存全部无效到 PoU [WO]
                                               地址: 0xE000EF50
                                               使整个指令缓存无效到 PoU
                                               实现 Security Extension 时，Secure 软件可通过 ICIALLU_NS 访问 Non-secure 版本 (地址 0xE002EF50)
                                               参考：D1.2.124 ICIALLU, Instruction Cache Invalidate All to PoU
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_CACHE_ICIMVAU       0x008   /* Instruction Cache line Invalidate by Address to PoU - 指令缓存行无效（按地址到 PoU）[WO]
                                               地址: 0xE000EF58
                                               按地址使指令缓存行无效到 PoU
                                               实现 Security Extension 时，Secure 软件可通过 ICIMVAU_NS 访问 Non-secure 版本 (地址 0xE002EF58)
                                               参考：D1.2.125 ICIMVAU, Instruction Cache line Invalidate by Address
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_CACHE_DCIMVAC       0x00C   /* Data Cache line Invalidate by Address to PoC - 数据缓存行无效（按地址到 PoC）[WO]
                                               地址: 0xE000EF5C
                                               按地址使数据缓存行无效到 PoC
                                               实现 Security Extension 时，Secure 软件可通过 DCIMVAC_NS 访问 Non-secure 版本 (地址 0xE002EF5C)
                                               参考：D1.2.31 DCIMVAC, Data Cache line Invalidate by Address to PoC
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_CACHE_DCISW         0x010   /* Data Cache line Invalidate by Set/Way - 数据缓存行无效（按组/路）[WO]
                                               地址: 0xE000EF60
                                               按组/路使数据缓存行无效
                                               实现 Security Extension 时，Secure 软件可通过 DCISW_NS 访问 Non-secure 版本 (地址 0xE002EF60)
                                               参考：D1.2.32 DCISW, Data Cache line Invalidate by Set/Way
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_CACHE_DCCMVAU       0x014   /* Data Cache line Clean by address to PoU - 数据缓存行清理（按地址到 PoU）[WO]
                                               地址: 0xE000EF64
                                               按地址清理数据缓存行到 PoU
                                               实现 Security Extension 时，Secure 软件可通过 DCCMVAU_NS 访问 Non-secure 版本 (地址 0xE002EF64)
                                               参考：D1.2.25 DCCMVAU, Data Cache line Clean by address to PoU
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_CACHE_DCCMVAC       0x018   /* Data Cache line Clean by Address to PoC - 数据缓存行清理（按地址到 PoC）[WO]
                                               地址: 0xE000EF68
                                               按地址清理数据缓存行到 PoC
                                               实现 Security Extension 时，Secure 软件可通过 DCCMVAC_NS 访问 Non-secure 版本 (地址 0xE002EF68)
                                               参考：D1.2.24 DCCMVAC, Data Cache line Clean by Address to PoC
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_CACHE_DCCSW         0x01C   /* Data Cache Clean line by Set/Way - 数据缓存清理行（按组/路）[WO]
                                               地址: 0xE000EF6C
                                               按组/路清理数据缓存行
                                               实现 Security Extension 时，Secure 软件可通过 DCCSW_NS 访问 Non-secure 版本 (地址 0xE002EF6C)
                                               参考：D1.2.26 DCCSW, Data Cache Clean line by Set/Way
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_CACHE_DCCIMVAC      0x020   /* Data Cache line Clean and Invalidate by Address to PoC - 数据缓存行清理和无效（按地址到 PoC）[WO]
                                               地址: 0xE000EF70
                                               按地址清理和使数据缓存行无效到 PoC
                                               实现 Security Extension 时，Secure 软件可通过 DCCIMVAC_NS 访问 Non-secure 版本 (地址 0xE002EF70)
                                               参考：D1.2.22 DCCIMVAC, Data Cache line Clean and Invalidate by Address to PoC
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_CACHE_DCCISW        0x024   /* Data Cache line Clean and Invalidate by Set/Way - 数据缓存行清理和无效（按组/路）[WO]
                                               地址: 0xE000EF74
                                               按组/路清理和使数据缓存行无效
                                               实现 Security Extension 时，Secure 软件可通过 DCCISW_NS 访问 Non-secure 版本 (地址 0xE002EF74)
                                               参考：D1.2.23 DCCISW, Data Cache line Clean and Invalidate by Set/Way
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_CACHE_BPIALL        0x028   /* Branch Predictor Invalidate All - 分支预测器全部无效 [WO]
                                               地址: 0xE000EF78
                                               使整个分支预测器无效
                                               实现 Security Extension 时，Secure 软件可通过 BPIALL_NS 访问 Non-secure 版本 (地址 0xE002EF78)
                                               参考：D1.2.8 BPIALL, Branch Predictor Invalidate All
                                               备注：适用于所有 Armv8-M 实现 */

/* -----------------------------------------------------------------------------
 * 3.9 组件识别寄存器
 * 参考: D1.2 寄存器描述
 * 地址范围: 0xE000EFB0 - 0xE000EFFC (Secure), 0xE002EFB0 - 0xE002EFFC (Non-secure 别名)
 * NS 别名说明: Secure 状态可通过 NS 别名访问 Non-secure 状态的组件识别寄存器
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DID_BASE            0xE000EFB0UL  /* 组件识别寄存器 Secure 基地址 */
#define ARM_V8M_DID_NS_BASE         0xE002EFB0UL  /* 组件识别寄存器 Non-secure 别名基地址 - 仅 Secure 状态可通过此地址访问 Non-secure 寄存器 */

#define ARM_V8M_DID_DLAR            0x000   /* SCS Software Lock Access Register - SCS 软件锁访问寄存器 [RW]
                                               地址: 0xE000EFB0
                                               控制软件锁的访问
                                               实现 Security Extension 时，Secure 软件可通过 DLAR_NS 访问 Non-secure 版本 (地址 0xE002EFB0)
                                               参考：D1.2.40 DLAR, SCS Software Lock Access Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DID_DLSR            0x004   /* SCS Software Lock Status Register - SCS 软件锁状态寄存器 [RO]
                                               地址: 0xE000EFB4
                                               只读寄存器，提供软件锁状态
                                               实现 Security Extension 时，Secure 软件可通过 DLSR_NS 访问 Non-secure 版本 (地址 0xE002EFB4)
                                               参考：D1.2.41 DLSR, SCS Software Lock Status Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DID_DAUTHSTATUS     0x008   /* Debug Authentication Status Register - 调试认证状态寄存器 [RO]
                                               地址: 0xE000EFB8
                                               只读寄存器，提供调试认证状态
                                               仅 Secure 状态可访问
                                               参考：D1.2.21 DAUTHSTATUS, Debug Authentication Status Register
                                               备注：仅 Security Extension 和 Debug Extension 时可用 */

#define ARM_V8M_DID_DDEVARCH        0x00C   /* SCS Device Architecture Register - SCS 设备架构寄存器 [RO]
                                               地址: 0xE000EFBC
                                               只读寄存器，提供设备架构信息
                                               实现 Security Extension 时，Secure 软件可通过 DDEVARCH_NS 访问 Non-secure 版本 (地址 0xE002EFBC)
                                               参考：D1.2.35 DDEVARCH, SCS Device Architecture Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_DID_DDEVTYPE        0x010   /* SCS Device Type Register - SCS 设备类型寄存器 [RO]
                                               地址: 0xE000EFCC
                                               只读寄存器，提供设备类型信息
                                               实现 Security Extension 时，Secure 软件可通过 DDEVTYPE_NS 访问 Non-secure 版本 (地址 0xE002EFCC)
                                               参考：D1.2.36 DDEVTYPE, SCS Device Type Register
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_DID_DPIDR4          0x020   /* SCS Peripheral Identification Register 4 - SCS 外设识别寄存器 4 [RO]
                                               地址: 0xE000EFD0
                                               只读寄存器，提供外设识别信息
                                               实现 Security Extension 时，Secure 软件可通过 DPIDR4_NS 访问 Non-secure 版本 (地址 0xE002EFD0)
                                               参考：D1.2.46 DPIDR4, SCS Peripheral Identification Register 4
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_DID_DPIDR5          0x024   /* SCS Peripheral Identification Register 5 - SCS 外设识别寄存器 5 [RO]
                                               地址: 0xE000EFD4
                                               只读寄存器，提供外设识别信息
                                               实现 Security Extension 时，Secure 软件可通过 DPIDR5_NS 访问 Non-secure 版本 (地址 0xE002EFD4)
                                               参考：D1.2.47 DPIDR5, SCS Peripheral Identification Register 5
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_DID_DPIDR6          0x028   /* SCS Peripheral Identification Register 6 - SCS 外设识别寄存器 6 [RO]
                                               地址: 0xE000EFD8
                                               只读寄存器，提供外设识别信息
                                               实现 Security Extension 时，Secure 软件可通过 DPIDR6_NS 访问 Non-secure 版本 (地址 0xE002EFD8)
                                               参考：D1.2.48 DPIDR6, SCS Peripheral Identification Register 6
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_DID_DPIDR7          0x02C   /* SCS Peripheral Identification Register 7 - SCS 外设识别寄存器 7 [RO]
                                               地址: 0xE000EFDC
                                               只读寄存器，提供外设识别信息
                                               实现 Security Extension 时，Secure 软件可通过 DPIDR7_NS 访问 Non-secure 版本 (地址 0xE002EFDC)
                                               参考：D1.2.49 DPIDR7, SCS Peripheral Identification Register 7
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_DID_DPIDR0          0x030   /* SCS Peripheral Identification Register 0 - SCS 外设识别寄存器 0 [RO]
                                               地址: 0xE000EFE0
                                               只读寄存器，提供外设识别信息
                                               实现 Security Extension 时，Secure 软件可通过 DPIDR0_NS 访问 Non-secure 版本 (地址 0xE002EFE0)
                                               参考：D1.2.42 DPIDR0, SCS Peripheral Identification Register 0
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_DID_DPIDR1          0x034   /* SCS Peripheral Identification Register 1 - SCS 外设识别寄存器 1 [RO]
                                               地址: 0xE000EFE4
                                               只读寄存器，提供外设识别信息
                                               实现 Security Extension 时，Secure 软件可通过 DPIDR1_NS 访问 Non-secure 版本 (地址 0xE002EFE4)
                                               参考：D1.2.43 DPIDR1, SCS Peripheral Identification Register 1
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_DID_DPIDR2          0x038   /* SCS Peripheral Identification Register 2 - SCS 外设识别寄存器 2 [RO]
                                               地址: 0xE000EFE8
                                               只读寄存器，提供外设识别信息
                                               实现 Security Extension 时，Secure 软件可通过 DPIDR2_NS 访问 Non-secure 版本 (地址 0xE002EFE8)
                                               参考：D1.2.44 DPIDR2, SCS Peripheral Identification Register 2
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_DID_DPIDR3          0x03C   /* SCS Peripheral Identification Register 3 - SCS 外设识别寄存器 3 [RO]
                                               地址: 0xE000EFEC
                                               只读寄存器，提供外设识别信息
                                               实现 Security Extension 时，Secure 软件可通过 DPIDR3_NS 访问 Non-secure 版本 (地址 0xE002EFEC)
                                               参考：D1.2.45 DPIDR3, SCS Peripheral Identification Register 3
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_DID_DCIDR0          0x040   /* SCS Component Identification Register 0 - SCS 组件识别寄存器 0 [RO]
                                               地址: 0xE000EFF0
                                               只读寄存器，提供组件识别信息
                                               实现 Security Extension 时，Secure 软件可通过 DCIDR0_NS 访问 Non-secure 版本 (地址 0xE002EFF0)
                                               参考：D1.2.27 DCIDR0, SCS Component Identification Register 0
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_DID_DCIDR1          0x044   /* SCS Component Identification Register 1 - SCS 组件识别寄存器 1 [RO]
                                               地址: 0xE000EFF4
                                               只读寄存器，提供组件识别信息
                                               实现 Security Extension 时，Secure 软件可通过 DCIDR1_NS 访问 Non-secure 版本 (地址 0xE002EFF4)
                                               参考：D1.2.28 DCIDR1, SCS Component Identification Register 1
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_DID_DCIDR2          0x048   /* SCS Component Identification Register 2 - SCS 组件识别寄存器 2 [RO]
                                               地址: 0xE000EFF8
                                               只读寄存器，提供组件识别信息
                                               实现 Security Extension 时，Secure 软件可通过 DCIDR2_NS 访问 Non-secure 版本 (地址 0xE002EFF8)
                                               参考：D1.2.29 DCIDR2, SCS Component Identification Register 2
                                               备注：适用于所有 Armv8-M 实现 */

#define ARM_V8M_DID_DCIDR3          0x04C   /* SCS Component Identification Register 3 - SCS 组件识别寄存器 3 [RO]
                                               地址: 0xE000EFFC
                                               只读寄存器，提供组件识别信息
                                               实现 Security Extension 时，Secure 软件可通过 DCIDR3_NS 访问 Non-secure 版本 (地址 0xE002EFFC)
                                               参考：D1.2.30 DCIDR3, SCS Component Identification Register 3
                                               备注：适用于所有 Armv8-M 实现 */

/* -----------------------------------------------------------------------------
 * 3.10 调试控制块 (DCB)
 * 参考: D1.2 寄存器描述
 * 地址范围: 0xE000EDF0 - 0xE000EE0C (Secure), 0xE002EDF0 - 0xE002EE0C (Non-secure 别名)
 * NS 别名说明: Secure 状态可通过 NS 别名访问 Non-secure 状态的 DCB 寄存器
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DCB_BASE            0xE000EDF0UL  /* DCB Secure 基地址 */
#define ARM_V8M_DCB_NS_BASE         0xE002EDF0UL  /* DCB Non-secure 别名基地址 - 仅 Secure 状态可通过此地址访问 Non-secure 寄存器 */

#define ARM_V8M_DCB_DHCSR           0x000   /* Debug Halting Control and Status Register - 调试暂停控制和状态寄存器 [RW]
                                               地址: 0xE000EDF0
                                               控制调试暂停和提供状态
                                               实现 Security Extension 时，Secure 软件可通过 DHCSR_NS 访问 Non-secure 版本 (地址 0xE002EDF0)
                                               参考：D1.2.39 DHCSR, Debug Halting Control and Status Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DCB_DCRSR           0x004   /* Debug Core Register Select Register - 调试核心寄存器选择寄存器 [WO]
                                               地址: 0xE000EDF4
                                               选择要访问的调试核心寄存器
                                               实现 Security Extension 时，Secure 软件可通过 DCRSR_NS 访问 Non-secure 版本 (地址 0xE002EDF4)
                                               参考：D1.2.34 DCRSR, Debug Core Register Select Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DCB_DCRDR           0x008   /* Debug Core Register Data Register - 调试核心寄存器数据寄存器 [RW]
                                               地址: 0xE000EDF8
                                               存储调试核心寄存器的数据
                                               实现 Security Extension 时，Secure 软件可通过 DCRDR_NS 访问 Non-secure 版本 (地址 0xE002EDF8)
                                               参考：D1.2.33 DCRDR, Debug Core Register Data Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DCB_DEMCR           0x00C   /* Debug Exception and Monitor Control Register - 调试异常和监控控制寄存器 [RW]
                                               地址: 0xE000EDFC
                                               控制调试异常和监控
                                               实现 Security Extension 时，Secure 软件可通过 DEMCR_NS 访问 Non-secure 版本 (地址 0xE002EDFC)
                                               参考：D1.2.37 DEMCR, Debug Exception and Monitor Control Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DCB_DSCEMCR         0x010   /* Debug Set Clear Exception and Monitor Control - 调试设置清除异常和监控控制寄存器 [RW]
                                               地址: 0xE000EE00
                                               位设置和清除寄存器
                                               实现 Security Extension 时，Secure 软件可通过 DSCEMCR_NS 访问 Non-secure 版本 (地址 0xE002EE00)
                                               参考：D1.2.50 DSCEMCR, Debug Set Clear Exception and Monitor Control
                                               备注：Armv8.1-M 及更高版本可选
                                               【v8m 独有】v7m 中不存在此寄存器 */

#define ARM_V8M_DCB_DAUTHCTRL       0x014   /* Debug Authentication Control Register - 调试认证控制寄存器 [RW]
                                               地址: 0xE000EE04
                                               控制调试认证
                                               仅 Secure 状态可访问
                                               参考：D1.2.20 DAUTHCTRL, Debug Authentication Control Register
                                               备注：仅 Security Extension 和 Debug Extension 时可用
                                               【v8m 独有】v7m 中不存在此寄存器 */

#define ARM_V8M_DCB_DSCSR           0x018   /* Debug Security Control and Status Register - 调试安全控制和状态寄存器 [RW]
                                               地址: 0xE000EE08
                                               控制调试安全和提供状态
                                               仅 Secure 状态可访问
                                               参考：D1.2.51 DSCSR, Debug Security Control and Status Register
                                               备注：仅 Security Extension 和 Debug Extension 时可用
                                               【v8m 独有】v7m 中不存在此寄存器 */

/* ==============================================================================
 * 四、调试寄存器 (Debug Registers)
 * 参考: D1.2 Alphabetical list of registers
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 4.1 数据观察点和跟踪 (DWT - Data Watchpoint and Trace)
 * 参考: D1.2 寄存器描述
 * 地址范围: 0xE0001000 - 0xE0001FFF
 * 注意: DWT 寄存器没有 NS 别名
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DWT_BASE            0xE0001000UL  /* DWT 基地址 - 无 NS 别名 */

#define ARM_V8M_DWT_CTRL            0x000   /* DWT Control Register - DWT 控制寄存器 [RW]
                                               地址: 0xE0001000
                                               控制 DWT 的使能和配置
                                               参考：D1.2.57 DWT_CTRL, DWT Control Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_CYCCNT          0x004   /* DWT Cycle Count Register - DWT 周期计数寄存器 [RW]
                                               地址: 0xE0001004
                                               存储 CPU 周期计数
                                               参考：D1.2.56 DWT_CYCCNT, DWT Cycle Count Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_CPICNT          0x008   /* DWT CPI Count Register - DWT CPI 计数寄存器 [RW]
                                               地址: 0xE0001008
                                               存储 CPI (Cycles Per Instruction) 计数
                                               参考：D1.2.55 DWT_CPICNT, DWT CPI Count Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_EXCCNT          0x00C   /* DWT Exception Overhead Count Register - DWT 异常开销计数寄存器 [RW]
                                               地址: 0xE000100C
                                               存储异常开销计数
                                               参考：D1.2.58 DWT_EXCCNT, DWT Exception Overhead Count Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_SLEEPCNT        0x010   /* DWT Sleep Count Register - DWT 睡眠计数寄存器 [RW]
                                               地址: 0xE0001010
                                               存储睡眠模式周期计数
                                               参考：D1.2.65 DWT_SLEEPCNT, DWT Sleep Count Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_LSUCNT          0x014   /* DWT LSU Count Register - DWT 加载/存储单元计数寄存器 [RW]
                                               地址: 0xE0001014
                                               存储加载/存储操作计数
                                               参考：D1.2.63 DWT_LSUCNT, DWT LSU Count Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_FOLDCNT         0x018   /* DWT Folded Instruction Count Register - DWT 折叠指令计数寄存器 [RW]
                                               地址: 0xE0001018
                                               存储折叠指令计数
                                               参考：D1.2.60 DWT_FOLDCNT, DWT Folded Instruction Count Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_PCSR            0x01C   /* DWT Program Counter Sample Register - DWT 程序计数器采样寄存器 [RO]
                                               地址: 0xE000101C
                                               只读寄存器，提供程序计数器采样值
                                               参考：D1.2.64 DWT_PCSR, DWT Program Counter Sample Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_COMPn           0x020   /* DWT Comparator Register n - DWT 比较器寄存器 n [RW]
                                               地址: 0xE0001020 + 0x08 * n
                                               存储比较器地址值
                                               参考：D1.2.53 DWT_COMPn, DWT Comparator Register n
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_FUNCTIONn       0x028   /* DWT Comparator Function Register n - DWT 比较器功能寄存器 n [RW]
                                               地址: 0xE0001028 + 0x08 * n
                                               配置比较器功能
                                               参考：D1.2.59 DWT_FUNCTIONn, DWT Comparator Function Register n
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_MASKn           0x02C   /* DWT Comparator Value Mask Register n - DWT 比较器值掩码寄存器 n [RW]
                                               地址: 0xE000102C + 0x08 * n
                                               配置比较器掩码 (DWT v2.0 及之前)
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_VMASKn          0x02C   /* DWT Comparator Value Mask Register n - DWT 比较器值掩码寄存器 n [RW]
                                               地址: 0xE000102C + 0x10 * n
                                               为数据值比较器 n 提供掩码值 (DWT v2.1 及之后)
                                               参考：D1.2.78 DWT_VMASKn, DWT Comparator Value Mask Register, n = 0 - 14
                                               备注：仅 Debug Extension 且 DWT v2.1 及之后可用
                                               【v8m 独有】v7m 中不存在此寄存器 */

#define ARM_V8M_DWT_LAR             0xFB0   /* DWT Software Lock Access Register - DWT 软件锁访问寄存器 [RW]
                                               地址: 0xE0001FB0
                                               控制软件锁的访问
                                               参考：D1.2.61 DWT_LAR, DWT Software Lock Access Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_LSR             0xFB4   /* DWT Software Lock Status Register - DWT 软件锁状态寄存器 [RO]
                                               地址: 0xE0001FB4
                                               只读寄存器，提供软件锁状态
                                               参考：D1.2.66 DWT_LSR, DWT Software Lock Status Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_DEVARCH         0xFBC   /* DWT Device Architecture Register - DWT 设备架构寄存器 [RO]
                                               地址: 0xE0001FBC
                                               只读寄存器，提供设备架构信息
                                               参考：D1.2.54 DWT_DEVARCH, DWT Device Architecture Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_DEVTYPE         0xFCC   /* DWT Device Type Register - DWT 设备类型寄存器 [RO]
                                               地址: 0xE0001FCC
                                               只读寄存器，提供设备类型信息
                                               参考：D1.2.52 DWT_DEVTYPE, DWT Device Type Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_PIDR4           0xFD0   /* DWT Peripheral Identification Register 4 - DWT 外设识别寄存器 4 [RO]
                                               地址: 0xE0001FD0
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_PIDR5           0xFD4   /* DWT Peripheral Identification Register 5 - DWT 外设识别寄存器 5 [RO]
                                               地址: 0xE0001FD4
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_PIDR6           0xFD8   /* DWT Peripheral Identification Register 6 - DWT 外设识别寄存器 6 [RO]
                                               地址: 0xE0001FD8
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_PIDR7           0xFDC   /* DWT Peripheral Identification Register 7 - DWT 外设识别寄存器 7 [RO]
                                               地址: 0xE0001FDC
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_PIDR0           0xFE0   /* DWT Peripheral Identification Register 0 - DWT 外设识别寄存器 0 [RO]
                                               地址: 0xE0001FE0
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_PIDR1           0xFE4   /* DWT Peripheral Identification Register 1 - DWT 外设识别寄存器 1 [RO]
                                               地址: 0xE0001FE4
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_PIDR2           0xFE8   /* DWT Peripheral Identification Register 2 - DWT 外设识别寄存器 2 [RO]
                                               地址: 0xE0001FE8
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_PIDR3           0xFEC   /* DWT Peripheral Identification Register 3 - DWT 外设识别寄存器 3 [RO]
                                               地址: 0xE0001FEC
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_CIDR0           0xFF0   /* DWT Component Identification Register 0 - DWT 组件识别寄存器 0 [RO]
                                               地址: 0xE0001FF0
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_CIDR1           0xFF4   /* DWT Component Identification Register 1 - DWT 组件识别寄存器 1 [RO]
                                               地址: 0xE0001FF4
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_CIDR2           0xFF8   /* DWT Component Identification Register 2 - DWT 组件识别寄存器 2 [RO]
                                               地址: 0xE0001FF8
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_DWT_CIDR3           0xFFC   /* DWT Component Identification Register 3 - DWT 组件识别寄存器 3 [RO]
                                               地址: 0xE0001FFC
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

/* -----------------------------------------------------------------------------
 * 4.2 仪器化宏单元 (ITM - Instrumentation Macrocell)
 * 参考: D1.2 寄存器描述
 * 地址范围: 0xE0000000 - 0xE0000FFF
 * 注意: ITM 寄存器没有 NS 别名
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_ITM_BASE            0xE0000000UL  /* ITM 基地址 - 无 NS 别名 */

#define ARM_V8M_ITM_STIMn           0x000   /* ITM Stimulus Port Register n - ITM 激励端口寄存器 n [RW]
                                               地址: 0xE0000000 + 0x04 * n
                                               用于软件写激励数据
                                               参考：D1.2.159 ITM_STIMn, ITM Stimulus Port Register n
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_ITM_TERn            0xE00   /* ITM Trace Enable Register n - ITM 跟踪使能寄存器 n [RW]
                                               地址: 0xE0000E00 + 0x04 * n
                                               使能激励端口跟踪
                                               参考：D1.2.163 ITM_TERn, ITM Trace Enable Register n
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_ITM_TPR             0xE40   /* ITM Trace Privilege Register - ITM 跟踪特权寄存器 [RW]
                                               地址: 0xE0000E40
                                               控制激励端口的特权访问
                                               参考：D1.2.162 ITM_TPR, ITM Trace Privilege Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_ITM_TCR             0xE80   /* ITM Trace Control Register - ITM 跟踪控制寄存器 [RW]
                                               地址: 0xE0000E80
                                               控制 ITM 的使能和配置
                                               参考：D1.2.161 ITM_TCR, ITM Trace Control Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_ITM_LAR             0xFB0   /* ITM Software Lock Access Register - ITM 软件锁访问寄存器 [RW]
                                               地址: 0xE0000FB0
                                               控制软件锁的访问
                                               参考：D1.2.158 ITM_LAR, ITM Software Lock Access Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_ITM_LSR             0xFB4   /* ITM Software Lock Status Register - ITM 软件锁状态寄存器 [RO]
                                               地址: 0xE0000FB4
                                               只读寄存器，提供软件锁状态
                                               参考：D1.2.160 ITM_LSR, ITM Software Lock Status Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_ITM_DEVARCH         0xFBC   /* ITM Device Architecture Register - ITM 设备架构寄存器 [RO]
                                               地址: 0xE0000FBC
                                               只读寄存器，提供设备架构信息
                                               参考：D1.2.155 ITM_DEVARCH, ITM Device Architecture Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_ITM_DEVTYPE         0xFCC   /* ITM Device Type Register - ITM 设备类型寄存器 [RO]
                                               地址: 0xE0000FCC
                                               只读寄存器，提供设备类型信息
                                               参考：D1.2.156 ITM_DEVTYPE, ITM Device Type Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_ITM_PIDR4           0xFD0   /* ITM Peripheral Identification Register 4 - ITM 外设识别寄存器 4 [RO]
                                               地址: 0xE0000FD0
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_ITM_PIDR5           0xFD4   /* ITM Peripheral Identification Register 5 - ITM 外设识别寄存器 5 [RO]
                                               地址: 0xE0000FD4
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_ITM_PIDR6           0xFD8   /* ITM Peripheral Identification Register 6 - ITM 外设识别寄存器 6 [RO]
                                               地址: 0xE0000FD8
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_ITM_PIDR7           0xFDC   /* ITM Peripheral Identification Register 7 - ITM 外设识别寄存器 7 [RO]
                                               地址: 0xE0000FDC
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_ITM_PIDR0           0xFE0   /* ITM Peripheral Identification Register 0 - ITM 外设识别寄存器 0 [RO]
                                               地址: 0xE0000FE0
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_ITM_PIDR1           0xFE4   /* ITM Peripheral Identification Register 1 - ITM 外设识别寄存器 1 [RO]
                                               地址: 0xE0000FE4
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_ITM_PIDR2           0xFE8   /* ITM Peripheral Identification Register 2 - ITM 外设识别寄存器 2 [RO]
                                               地址: 0xE0000FE8
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_ITM_PIDR3           0xFEC   /* ITM Peripheral Identification Register 3 - ITM 外设识别寄存器 3 [RO]
                                               地址: 0xE0000FEC
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_ITM_CIDR0           0xFF0   /* ITM Component Identification Register 0 - ITM 组件识别寄存器 0 [RO]
                                               地址: 0xE0000FF0
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_ITM_CIDR1           0xFF4   /* ITM Component Identification Register 1 - ITM 组件识别寄存器 1 [RO]
                                               地址: 0xE0000FF4
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_ITM_CIDR2           0xFF8   /* ITM Component Identification Register 2 - ITM 组件识别寄存器 2 [RO]
                                               地址: 0xE0000FF8
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_ITM_CIDR3           0xFFC   /* ITM Component Identification Register 3 - ITM 组件识别寄存器 3 [RO]
                                               地址: 0xE0000FFC
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

/* -----------------------------------------------------------------------------
 * 4.3 闪存补丁和断点 (FPB - Flash Patch and Breakpoint)
 * 参考: D1.2 寄存器描述
 * 地址范围: 0xE0002000 - 0xE0002FFF
 * 注意: FPB 寄存器没有 NS 别名
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_FPB_BASE            0xE0002000UL  /* FPB 基地址 - 无 NS 别名 */

#define ARM_V8M_FPB_CTRL            0x000   /* Flash Patch Control Register - 闪存补丁控制寄存器 [RW]
                                               地址: 0xE0002000
                                               控制 FPB 的使能和配置
                                               参考：D1.2.92 FP_CTRL, Flash Patch Control Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_FPB_REMAP           0x004   /* Flash Patch Remap Register - 闪存补丁重映射寄存器 [RW]
                                               地址: 0xE0002004
                                               重映射闪存补丁地址
                                               参考：D1.2.94 FP_REMAP, Flash Patch Remap Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_FPB_COMPn           0x008   /* Flash Patch Comparator Register n - 闪存补丁比较器寄存器 n [RW]
                                               地址: 0xE0002008 + 0x04 * n
                                               存储比较器地址值
                                               参考：D1.2.93 FP_COMPn, Flash Patch Comparator Register n
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_FPB_LAR             0xFB0   /* FPB Software Lock Access Register - FPB 软件锁访问寄存器 [RW]
                                               地址: 0xE0002FB0
                                               控制软件锁的访问
                                               参考：D1.2.91 FP_LAR, FPB Software Lock Access Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_FPB_LSR             0xFB4   /* FPB Software Lock Status Register - FPB 软件锁状态寄存器 [RO]
                                               地址: 0xE0002FB4
                                               只读寄存器，提供软件锁状态
                                               参考：D1.2.95 FP_LSR, FPB Software Lock Status Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_FPB_DEVARCH         0xFBC   /* FPB Device Architecture Register - FPB 设备架构寄存器 [RO]
                                               地址: 0xE0002FBC
                                               只读寄存器，提供设备架构信息
                                               参考：D1.2.89 FP_DEVARCH, FPB Device Architecture Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_FPB_DEVTYPE         0xFCC   /* FPB Device Type Register - FPB 设备类型寄存器 [RO]
                                               地址: 0xE0002FCC
                                               只读寄存器，提供设备类型信息
                                               参考：D1.2.90 FP_DEVTYPE, FPB Device Type Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_FPB_PIDR4           0xFD0   /* FPB Peripheral Identification Register 4 - FPB 外设识别寄存器 4 [RO]
                                               地址: 0xE0002FD0
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_FPB_PIDR5           0xFD4   /* FPB Peripheral Identification Register 5 - FPB 外设识别寄存器 5 [RO]
                                               地址: 0xE0002FD4
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_FPB_PIDR6           0xFD8   /* FPB Peripheral Identification Register 6 - FPB 外设识别寄存器 6 [RO]
                                               地址: 0xE0002FD8
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_FPB_PIDR7           0xFDC   /* FPB Peripheral Identification Register 7 - FPB 外设识别寄存器 7 [RO]
                                               地址: 0xE0002FDC
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_FPB_PIDR0           0xFE0   /* FPB Peripheral Identification Register 0 - FPB 外设识别寄存器 0 [RO]
                                               地址: 0xE0002FE0
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_FPB_PIDR1           0xFE4   /* FPB Peripheral Identification Register 1 - FPB 外设识别寄存器 1 [RO]
                                               地址: 0xE0002FE4
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_FPB_PIDR2           0xFE8   /* FPB Peripheral Identification Register 2 - FPB 外设识别寄存器 2 [RO]
                                               地址: 0xE0002FE8
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_FPB_PIDR3           0xFEC   /* FPB Peripheral Identification Register 3 - FPB 外设识别寄存器 3 [RO]
                                               地址: 0xE0002FEC
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_FPB_CIDR0           0xFF0   /* FPB Component Identification Register 0 - FPB 组件识别寄存器 0 [RO]
                                               地址: 0xE0002FF0
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_FPB_CIDR1           0xFF4   /* FPB Component Identification Register 1 - FPB 组件识别寄存器 1 [RO]
                                               地址: 0xE0002FF4
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_FPB_CIDR2           0xFF8   /* FPB Component Identification Register 2 - FPB 组件识别寄存器 2 [RO]
                                               地址: 0xE0002FF8
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_FPB_CIDR3           0xFFC   /* FPB Component Identification Register 3 - FPB 组件识别寄存器 3 [RO]
                                               地址: 0xE0002FFC
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

/* -----------------------------------------------------------------------------
 * 4.4 跟踪端口接口单元 (TPIU - Trace Port Interface Unit)
 * 参考: D1.2 寄存器描述
 * 地址范围: 0xE0040000 - 0xE0040FFF
 * 注意: TPIU 寄存器没有 NS 别名
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_TPIU_BASE           0xE0040000UL  /* TPIU 基地址 - 无 NS 别名 */

#define ARM_V8M_TPIU_SSPSR          0x000   /* TPIU Supported Parallel Port Sizes Register - TPIU 支持的并行端口大小寄存器 [RO]
                                               地址: 0xE0040000
                                               只读寄存器，指示支持的并行端口大小
                                               参考：D1.2.256 TPIU_SSPSR, TPIU Supported Parallel Port Sizes Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_CSPSR          0x004   /* TPIU Current Parallel Port Sizes Register - TPIU 当前并行端口大小寄存器 [RW]
                                               地址: 0xE0040004
                                               选择当前并行端口大小
                                               参考：D1.2.249 TPIU_CSPSR, TPIU Current Parallel Port Sizes Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_ACPR           0x010   /* TPIU Asynchronous Clock Prescaler Register - TPIU 异步时钟预分频寄存器 [RW]
                                               地址: 0xE0040010
                                               配置异步时钟预分频器
                                               参考：D1.2.244 TPIU_ACPR, TPIU Asynchronous Clock Prescaler Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_SPPR           0x0F0   /* TPIU Selected Pin Protocol Register - TPIU 选择引脚协议寄存器 [RW]
                                               地址: 0xE00400F0
                                               选择跟踪引脚协议
                                               参考：D1.2.255 TPIU_SPPR, TPIU Selected Pin Protocol Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_FFSR           0x300   /* TPIU Formatter and Flush Status Register - TPIU 格式化器和刷新状态寄存器 [RO]
                                               地址: 0xE0040300
                                               只读寄存器，提供格式化器和刷新状态
                                               参考：D1.2.248 TPIU_FFSR, TPIU Formatter and Flush Status Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_FFCR           0x304   /* TPIU Formatter and Flush Control Register - TPIU 格式化器和刷新控制寄存器 [RW]
                                               地址: 0xE0040304
                                               控制格式化器和刷新
                                               参考：D1.2.247 TPIU_FFCR, TPIU Formatter and Flush Control Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_PSCR           0x308   /* TPIU Periodic Synchronization Control Register - TPIU 周期同步控制寄存器 [RW]
                                               地址: 0xE0040308
                                               控制周期同步
                                               参考：D1.2.254 TPIU_PSCR, TPIU Periodic Synchronization Control Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_CLAIMSET       0xFA0   /* TPIU Claim Tag Set Register - TPIU 声明标签设置寄存器 [RW]
                                               地址: 0xE0040FA0
                                               设置声明标签
                                               参考：D1.2.245 TPIU_CLAIMSET, TPIU Claim Tag Set Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_CLAIMCLR       0xFA4   /* TPIU Claim Tag Clear Register - TPIU 声明标签清除寄存器 [RW]
                                               地址: 0xE0040FA4
                                               清除声明标签
                                               参考：D1.2.246 TPIU_CLAIMCLR, TPIU Claim Tag Clear Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_LAR            0xFB0   /* TPIU Software Lock Access Register - TPIU 软件锁访问寄存器 [RW]
                                               地址: 0xE0040FB0
                                               控制软件锁的访问
                                               参考：D1.2.252 TPIU_LAR, TPIU Software Lock Access Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_LSR            0xFB4   /* TPIU Software Lock Status Register - TPIU 软件锁状态寄存器 [RO]
                                               地址: 0xE0040FB4
                                               只读寄存器，提供软件锁状态
                                               参考：D1.2.253 TPIU_LSR, TPIU Software Lock Status Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_DEVID          0xFC8   /* TPIU Device Identifier Register - TPIU 设备标识符寄存器 [RO]
                                               地址: 0xE0040FC8
                                               只读寄存器，提供设备标识符
                                               参考：D1.2.250 TPIU_DEVID, TPIU Device Identifier Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_DEVTYPE        0xFCC   /* TPIU Device Type Register - TPIU 设备类型寄存器 [RO]
                                               地址: 0xE0040FCC
                                               只读寄存器，提供设备类型信息
                                               参考：D1.2.251 TPIU_DEVTYPE, TPIU Device Type Register
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_PIDR4          0xFD0   /* TPIU Peripheral Identification Register 4 - TPIU 外设识别寄存器 4 [RO]
                                               地址: 0xE0040FD0
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_PIDR5          0xFD4   /* TPIU Peripheral Identification Register 5 - TPIU 外设识别寄存器 5 [RO]
                                               地址: 0xE0040FD4
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_PIDR6          0xFD8   /* TPIU Peripheral Identification Register 6 - TPIU 外设识别寄存器 6 [RO]
                                               地址: 0xE0040FD8
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_PIDR7          0xFDC   /* TPIU Peripheral Identification Register 7 - TPIU 外设识别寄存器 7 [RO]
                                               地址: 0xE0040FDC
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_PIDR0          0xFE0   /* TPIU Peripheral Identification Register 0 - TPIU 外设识别寄存器 0 [RO]
                                               地址: 0xE0040FE0
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_PIDR1          0xFE4   /* TPIU Peripheral Identification Register 1 - TPIU 外设识别寄存器 1 [RO]
                                               地址: 0xE0040FE4
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_PIDR2          0xFE8   /* TPIU Peripheral Identification Register 2 - TPIU 外设识别寄存器 2 [RO]
                                               地址: 0xE0040FE8
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_PIDR3          0xFEC   /* TPIU Peripheral Identification Register 3 - TPIU 外设识别寄存器 3 [RO]
                                               地址: 0xE0040FEC
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_CIDR0          0xFF0   /* TPIU Component Identification Register 0 - TPIU 组件识别寄存器 0 [RO]
                                               地址: 0xE0040FF0
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_CIDR1          0xFF4   /* TPIU Component Identification Register 1 - TPIU 组件识别寄存器 1 [RO]
                                               地址: 0xE0040FF4
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_CIDR2          0xFF8   /* TPIU Component Identification Register 2 - TPIU 组件识别寄存器 2 [RO]
                                               地址: 0xE0040FF8
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

#define ARM_V8M_TPIU_CIDR3          0xFFC   /* TPIU Component Identification Register 3 - TPIU 组件识别寄存器 3 [RO]
                                               地址: 0xE0040FFC
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 Debug Extension 时可用 */

/* ==============================================================================
 * 五、性能监控单元 (PMU - Performance Monitoring Unit)
 * 参考: D1.2 Alphabetical list of registers
 * 地址范围: 0xE0003000 - 0xE0003FFF
 * 注意: PMU 寄存器没有 NS 别名
 * 【v8m 独有】v7m 中不存在 PMU 功能
 * ============================================================================== */
#define ARM_V8M_PMU_BASE            0xE0003000UL  /* PMU 基地址 - 无 NS 别名 */

#define ARM_V8M_PMU_EVCNTRn         0x000   /* Performance Monitoring Unit Event Counter Register - PMU 事件计数器寄存器 [RW]
                                               地址: 0xE0003000 + 0x04 * n
                                               存储性能事件计数
                                               参考：D1.2.212 PMU_EVCNTRn, Performance Monitoring Unit Event Counter Register
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_CCNTR           0x07C   /* Performance Monitoring Unit Cycle Counter Register - PMU 周期计数器寄存器 [RW]
                                               地址: 0xE000307C
                                               存储周期计数
                                               参考：D1.2.207 PMU_CCNTR, Performance Monitoring Unit Cycle Counter Register
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_EVTYPERn        0x400   /* Performance Monitoring Unit Event Type and Filter Register - PMU 事件类型和过滤寄存器 [RW]
                                               地址: 0xE0003400 + 0x04 * n
                                               配置事件类型和过滤
                                               参考：D1.2.213 PMU_EVTYPERn, Performance Monitoring Unit Event Type and Filter Register
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_CCFILTR         0x47C   /* Performance Monitoring Unit Cycle Counter Filter Register - PMU 周期计数器过滤寄存器 [RW]
                                               地址: 0xE000347C
                                               过滤周期计数器
                                               参考：D1.2.206 PMU_CCFILTR, Performance Monitoring Unit Cycle Counter Filter Register
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_CNTENSET        0xC00   /* Performance Monitoring Unit Count Enable Set Register - PMU 计数使能设置寄存器 [RW]
                                               地址: 0xE0003C00
                                               设置计数器使能
                                               参考：D1.2.208 PMU_CNTENSET, Performance Monitoring Unit Count Enable Set Register
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_CNTENCLR        0xC20   /* Performance Monitoring Unit Count Enable Clear Register - PMU 计数使能清除寄存器 [RW]
                                               地址: 0xE0003C20
                                               清除计数器使能
                                               参考：D1.2.209 PMU_CNTENCLR, Performance Monitoring Unit Count Enable Clear Register
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_INTENSET        0xC40   /* Performance Monitoring Unit Interrupt Enable Set Register - PMU 中断使能设置寄存器 [RW]
                                               地址: 0xE0003C40
                                               设置中断使能
                                               参考：D1.2.211 PMU_INTENSET, Performance Monitoring Unit Interrupt Enable Set Register
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_INTENCLR        0xC60   /* Performance Monitoring Unit Interrupt Enable Clear Register - PMU 中断使能清除寄存器 [RW]
                                               地址: 0xE0003C60
                                               清除中断使能
                                               参考：D1.2.210 PMU_INTENCLR, Performance Monitoring Unit Interrupt Enable Clear Register
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_OVSCLR          0xC80   /* Performance Monitoring Unit Overflow Flag Status Clear Register - PMU 溢出标志状态清除寄存器 [WO]
                                               地址: 0xE0003C80
                                               清除溢出标志
                                               参考：D1.2.215 PMU_OVSCLR, Performance Monitoring Unit Overflow Flag Status Clear Register
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_OVSSET          0xCC0   /* Performance Monitoring Unit Overflow Flag Status Set Register - PMU 溢出标志状态设置寄存器 [WO]
                                               地址: 0xE0003CC0
                                               设置溢出标志
                                               参考：D1.2.216 PMU_OVSSET, Performance Monitoring Unit Overflow Flag Status Set Register
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_SWINC           0xCA0   /* Performance Monitoring Unit Software Increment Register - PMU 软件增量寄存器 [WO]
                                               地址: 0xE0003CA0
                                               软件增量计数器
                                               参考：D1.2.214 PMU_SWINC, Performance Monitoring Unit Software Increment Register
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_TYPE            0xE00   /* Performance Monitoring Unit Type Register - PMU 类型寄存器 [RO]
                                               地址: 0xE0003E00
                                               只读寄存器，提供 PMU 特性信息
                                               参考：D1.2.221 PMU_TYPE, Performance Monitoring Unit Type Register
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_CTRL            0xE04   /* Performance Monitoring Unit Control Register - PMU 控制寄存器 [RW]
                                               地址: 0xE0003E04
                                               控制 PMU 的使能和配置
                                               参考：D1.2.205 PMU_CTRL, Performance Monitoring Unit Control Register
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_AUTHSTATUS      0xFB8   /* Performance Monitoring Unit Authentication Status Register - PMU 认证状态寄存器 [RO]
                                               地址: 0xE0003FB8
                                               只读寄存器，提供认证状态
                                               仅 Secure 状态可访问
                                               参考：D1.2.204 PMU_AUTHSTATUS, Performance Monitoring Unit Authentication Status Register
                                               备注：仅 Security Extension 和 PMU 扩展时可用 */

#define ARM_V8M_PMU_DEVARCH         0xFBC   /* Performance Monitoring Unit Device Architecture Register - PMU 设备架构寄存器 [RO]
                                               地址: 0xE0003FBC
                                               只读寄存器，提供设备架构信息
                                               参考：D1.2.寄存器描述
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_DEVTYPE         0xFCC   /* Performance Monitoring Unit Device Type Register - PMU 设备类型寄存器 [RO]
                                               地址: 0xE0003FCC
                                               只读寄存器，提供设备类型信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_PIDR4           0xFD0   /* Performance Monitoring Unit Peripheral Identification Register 4 - PMU 外设识别寄存器 4 [RO]
                                               地址: 0xE0003FD0
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_PIDR0           0xFE0   /* Performance Monitoring Unit Peripheral Identification Register 0 - PMU 外设识别寄存器 0 [RO]
                                               地址: 0xE0003FE0
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_PIDR1           0xFE4   /* Performance Monitoring Unit Peripheral Identification Register 1 - PMU 外设识别寄存器 1 [RO]
                                               地址: 0xE0003FE4
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_PIDR2           0xFE8   /* Performance Monitoring Unit Peripheral Identification Register 2 - PMU 外设识别寄存器 2 [RO]
                                               地址: 0xE0003FE8
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_PIDR3           0xFEC   /* Performance Monitoring Unit Peripheral Identification Register 3 - PMU 外设识别寄存器 3 [RO]
                                               地址: 0xE0003FEC
                                               只读寄存器，提供外设识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_CIDR0           0xFF0   /* Performance Monitoring Unit Component Identification Register 0 - PMU 组件识别寄存器 0 [RO]
                                               地址: 0xE0003FF0
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_CIDR1           0xFF4   /* Performance Monitoring Unit Component Identification Register 1 - PMU 组件识别寄存器 1 [RO]
                                               地址: 0xE0003FF4
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_CIDR2           0xFF8   /* Performance Monitoring Unit Component Identification Register 2 - PMU 组件识别寄存器 2 [RO]
                                               地址: 0xE0003FF8
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 PMU 扩展时可用 */

#define ARM_V8M_PMU_CIDR3           0xFFC   /* Performance Monitoring Unit Component Identification Register 3 - PMU 组件识别寄存器 3 [RO]
                                               地址: 0xE0003FFC
                                               只读寄存器，提供组件识别信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 PMU 扩展时可用 */

/* ==============================================================================
 * 六、可靠性、可用性和可服务性扩展 (RAS - Reliability, Availability and Serviceability)
 * 参考: D1.2 Alphabetical list of registers
 * 地址范围: 0xE0005000 - 0xE0005FFF, 0xE000EF04
 * 注意: RAS 寄存器没有 NS 别名
 * 【v8m 独有】v7m 中不存在 RAS 功能
 * ============================================================================== */
#define ARM_V8M_RAS_BASE            0xE0005000UL  /* RAS 基地址 - 无 NS 别名 */

#define ARM_V8M_RAS_ERRFRn          0x000   /* Error Record Feature Register n - 错误记录特性寄存器 n [RO]
                                               地址: 0xE0005000 + 0x40 * n
                                               只读寄存器，提供错误记录特性信息
                                               参考：D1.2.73 ERRFRn, Error Record Feature Register n
                                               备注：仅 RAS 扩展时可用 */

#define ARM_V8M_RAS_ERRCTRLn        0x008   /* Error Record Control Register n - 错误记录控制寄存器 n [RW]
                                               地址: 0xE0005008 + 0x40 * n
                                               控制错误记录
                                               参考：D1.2.72 ERRCTRLn, Error Record Control Register n
                                               备注：仅 RAS 扩展时可用 */

#define ARM_V8M_RAS_ERRSTATUSn      0x010   /* Error Record Primary Status Register n - 错误记录主状态寄存器 n [RW]
                                               地址: 0xE0005010 + 0x40 * n
                                               存储错误记录主状态
                                               参考：D1.2.76 ERRSTATUSn, Error Record Primary Status Register n
                                               备注：仅 RAS 扩展时可用 */

#define ARM_V8M_RAS_ERRADDRn        0x018   /* Error Record Address Register n - 错误记录地址寄存器 n [RW]
                                               地址: 0xE0005018 + 0x40 * n
                                               存储错误记录地址
                                               参考：D1.2.70 ERRADDRn, Error Record Address Register n
                                               备注：仅 RAS 扩展时可用 */

#define ARM_V8M_RAS_ERRADDR2n       0x01C   /* Error Record Address 2 Register n - 错误记录地址 2 寄存器 n [RW]
                                               地址: 0xE000501C + 0x40 * n
                                               存储错误记录第二个地址
                                               参考：D1.2.71 ERRADDR2n, Error Record Address 2 Register n
                                               备注：仅 RAS 扩展时可用 */

#define ARM_V8M_RAS_ERRMISC0n       0x020   /* Error Record Miscellaneous 0 Register n - 错误记录杂项 0 寄存器 n [RW]
                                               地址: 0xE0005020 + 0x40 * n
                                               存储杂项错误信息
                                               参考：D1.2.77 ERRMSC0n, Error Record Miscellaneous 0 Register n
                                               备注：仅 RAS 扩展时可用 */

#define ARM_V8M_RAS_ERRMISC1n       0x024   /* Error Record Miscellaneous 1 Register n - 错误记录杂项 1 寄存器 n [RW]
                                               地址: 0xE0005024 + 0x40 * n
                                               存储杂项错误信息
                                               参考：D1.2.78 ERRMSC1n, Error Record Miscellaneous 1 Register n
                                               备注：仅 RAS 扩展时可用 */

#define ARM_V8M_RAS_ERRMISC2n       0x028   /* Error Record Miscellaneous 2 Register n - 错误记录杂项 2 寄存器 n [RW]
                                               地址: 0xE0005028 + 0x40 * n
                                               存储杂项错误信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 RAS 扩展时可用 */

#define ARM_V8M_RAS_ERRMISC3n       0x02C   /* Error Record Miscellaneous 3 Register n - 错误记录杂项 3 寄存器 n [RW]
                                               地址: 0xE000502C + 0x40 * n
                                               存储杂项错误信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 RAS 扩展时可用 */

#define ARM_V8M_RAS_ERRMISC4n       0x030   /* Error Record Miscellaneous 4 Register n - 错误记录杂项 4 寄存器 n [RW]
                                               地址: 0xE0005030 + 0x40 * n
                                               存储杂项错误信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 RAS 扩展时可用 */

#define ARM_V8M_RAS_ERRMISC5n       0x034   /* Error Record Miscellaneous 5 Register n - 错误记录杂项 5 寄存器 n [RW]
                                               地址: 0xE0005034 + 0x40 * n
                                               存储杂项错误信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 RAS 扩展时可用 */

#define ARM_V8M_RAS_ERRMISC6n       0x038   /* Error Record Miscellaneous 6 Register n - 错误记录杂项 6 寄存器 n [RW]
                                               地址: 0xE0005038 + 0x40 * n
                                               存储杂项错误信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 RAS 扩展时可用 */

#define ARM_V8M_RAS_ERRMISC7n       0x03C   /* Error Record Miscellaneous 7 Register n - 错误记录杂项 7 寄存器 n [RW]
                                               地址: 0xE000503C + 0x40 * n
                                               存储杂项错误信息
                                               参考：D1.2 寄存器描述
                                               备注：仅 RAS 扩展时可用 */

#define ARM_V8M_RAS_ERRGSRn         0xE00   /* RAS Fault Group Status Register - RAS 故障组状态寄存器 [RO]
                                               地址: 0xE0005E00 + 0x04 * n
                                               只读寄存器，提供故障组状态
                                               参考：D1.2.75 ERRGSRn, RAS Fault Group Status Register
                                               备注：仅 RAS 扩展时可用 */

#define ARM_V8M_RAS_ERRIIDR         0xE10   /* Error Implementer ID Register - 错误实现者 ID 寄存器 [RO]
                                               地址: 0xE0005E10
                                               只读寄存器，提供错误实现者 ID
                                               参考：D1.2.74 ERRIIDR, Error Implementer ID Register
                                               备注：仅 RAS 扩展时可用 */

#define ARM_V8M_RAS_ERRDEVID        0xFC8   /* Error Record Device ID Register - 错误记录设备 ID 寄存器 [RO]
                                               地址: 0xE0005FC8
                                               只读寄存器，提供错误记录设备 ID
                                               参考：D1.2.69 ERRDEVID, Error Record Device ID Register
                                               备注：仅 RAS 扩展时可用 */

#define ARM_V8M_SCB_RFSR            0x104   /* RAS Fault Status Register - RAS 故障状态寄存器 [RW]
                                               地址: 0xE000EF04
                                               存储 RAS 故障状态
                                               参考：D1.2.219 RFSR, RAS Fault Status Register
                                               备注：仅 RAS 扩展时可用 */

/* ==============================================================================
 * 七、M-Profile Vector Extension (MVE)
 * 参考: D1.2 Alphabetical list of registers
 * 注意: MVE 寄存器没有 NS 别名
 * 【v8m 独有】v7m 中不存在 MVE 功能
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 7.1 MVE 向量寄存器
 * 参考: D1.2 寄存器描述
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_Q0              0x00    /* Vector register Q0 - 向量寄存器 Q0 [RW]
                                               128 位向量数据寄存器
                                               用于向量运算
                                               参考：D1.2.203 Qn, Vector register n
                                               备注：仅 MVE 扩展时可用 */

#define ARM_V8M_REG_Q1              0x01    /* Vector register Q1 - 向量寄存器 Q1 [RW]
                                               128 位向量数据寄存器
                                               参考：D1.2.203 Qn, Vector register n
                                               备注：仅 MVE 扩展时可用 */

#define ARM_V8M_REG_Q2              0x02    /* Vector register Q2 - 向量寄存器 Q2 [RW]
                                               128 位向量数据寄存器
                                               参考：D1.2.203 Qn, Vector register n
                                               备注：仅 MVE 扩展时可用 */

#define ARM_V8M_REG_Q3              0x03    /* Vector register Q3 - 向量寄存器 Q3 [RW]
                                               128 位向量数据寄存器
                                               参考：D1.2.203 Qn, Vector register n
                                               备注：仅 MVE 扩展时可用 */

#define ARM_V8M_REG_Q4              0x04    /* Vector register Q4 - 向量寄存器 Q4 [RW]
                                               128 位向量数据寄存器
                                               参考：D1.2.203 Qn, Vector register n
                                               备注：仅 MVE 扩展时可用 */

#define ARM_V8M_REG_Q5              0x05    /* Vector register Q5 - 向量寄存器 Q5 [RW]
                                               128 位向量数据寄存器
                                               参考：D1.2.203 Qn, Vector register n
                                               备注：仅 MVE 扩展时可用 */

#define ARM_V8M_REG_Q6              0x06    /* Vector register Q6 - 向量寄存器 Q6 [RW]
                                               128 位向量数据寄存器
                                               参考：D1.2.203 Qn, Vector register n
                                               备注：仅 MVE 扩展时可用 */

#define ARM_V8M_REG_Q7              0x07    /* Vector register Q7 - 向量寄存器 Q7 [RW]
                                               128 位向量数据寄存器
                                               参考：D1.2.203 Qn, Vector register n
                                               备注：仅 MVE 扩展时可用 */

#define ARM_V8M_REG_VPR             0x00    /* Vector Predication Status and Control Register - 向量谓词状态和控制寄存器 [RW]
                                               控制向量谓词和状态
                                               参考：D1.2.269 VPR, Vector Predication Status and Control Register
                                               备注：仅 MVE 扩展时可用 */

#define ARM_V8M_REG_LO_BRANCH_INFO  0x00    /* Loop and branch tracking information - 循环和分支跟踪信息 [RO]
                                               只读寄存器，提供循环和分支跟踪信息
                                               参考：D1.2.165 LO_BRANCH_INFO, Loop and branch tracking information
                                               备注：仅 MVE 扩展时可用 */

/* ==============================================================================
 * 八、指针认证和分支目标识别 (PACBTI - Pointer Authentication and Branch Target Identification)
 * 参考: D1.2 Alphabetical list of registers
 * 注意: PACBTI 寄存器没有 NS 别名，且仅 Secure 状态可访问
 * 【v8m 独有】v7m 中不存在 PACBTI 功能
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 8.1 PACBTI 密钥寄存器
 * 参考: D1.2 寄存器描述
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_REG_PAC_KEY_P_0     0x00    /* Pointer Authentication Key Privileged 0 - 指针认证特权密钥 0 [RW]
                                               存储指针认证密钥 (特权级)
                                               仅 Secure 状态可访问
                                               参考：D1.2.195 PAC_KEY_P_n, Pointer Authentication Key Privileged n
                                               备注：仅 PACBTI 和 Security Extension 时可用 */

#define ARM_V8M_REG_PAC_KEY_P_1     0x01    /* Pointer Authentication Key Privileged 1 - 指针认证特权密钥 1 [RW]
                                               存储指针认证密钥 (特权级)
                                               仅 Secure 状态可访问
                                               参考：D1.2.195 PAC_KEY_P_n, Pointer Authentication Key Privileged n
                                               备注：仅 PACBTI 和 Security Extension 时可用 */

#define ARM_V8M_REG_PAC_KEY_P_2     0x02    /* Pointer Authentication Key Privileged 2 - 指针认证特权密钥 2 [RW]
                                               存储指针认证密钥 (特权级)
                                               仅 Secure 状态可访问
                                               参考：D1.2.195 PAC_KEY_P_n, Pointer Authentication Key Privileged n
                                               备注：仅 PACBTI 和 Security Extension 时可用 */

#define ARM_V8M_REG_PAC_KEY_P_3     0x03    /* Pointer Authentication Key Privileged 3 - 指针认证特权密钥 3 [RW]
                                               存储指针认证密钥 (特权级)
                                               仅 Secure 状态可访问
                                               参考：D1.2.195 PAC_KEY_P_n, Pointer Authentication Key Privileged n
                                               备注：仅 PACBTI 和 Security Extension 时可用 */

#define ARM_V8M_REG_PAC_KEY_U_0     0x00    /* Pointer Authentication Key Unprivileged 0 - 指针认证非特权密钥 0 [RW]
                                               存储指针认证密钥 (非特权级)
                                               仅 Secure 状态可访问
                                               参考：D1.2.196 PAC_KEY_U_n, Pointer Authentication Key Unprivileged n
                                               备注：仅 PACBTI 和 Security Extension 时可用 */

#define ARM_V8M_REG_PAC_KEY_U_1     0x01    /* Pointer Authentication Key Unprivileged 1 - 指针认证非特权密钥 1 [RW]
                                               存储指针认证密钥 (非特权级)
                                               仅 Secure 状态可访问
                                               参考：D1.2.196 PAC_KEY_U_n, Pointer Authentication Key Unprivileged n
                                               备注：仅 PACBTI 和 Security Extension 时可用 */

#define ARM_V8M_REG_PAC_KEY_U_2     0x02    /* Pointer Authentication Key Unprivileged 2 - 指针认证非特权密钥 2 [RW]
                                               存储指针认证密钥 (非特权级)
                                               仅 Secure 状态可访问
                                               参考：D1.2.196 PAC_KEY_U_n, Pointer Authentication Key Unprivileged n
                                               备注：仅 PACBTI 和 Security Extension 时可用 */

#define ARM_V8M_REG_PAC_KEY_U_3     0x03    /* Pointer Authentication Key Unprivileged 3 - 指针认证非特权密钥 3 [RW]
                                               存储指针认证密钥 (非特权级)
                                               仅 Secure 状态可访问
                                               参考：D1.2.196 PAC_KEY_U_n, Pointer Authentication Key Unprivileged n
                                               备注：仅 PACBTI 和 Security Extension 时可用 */

#ifdef __cplusplus
}
#endif

#endif /* __ARM_V8M_CORE_H__ */