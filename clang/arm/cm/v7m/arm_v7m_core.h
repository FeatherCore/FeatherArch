/********************************************************************************
 * @file        arm_v7m_core.h
 * @brief       ARMv7-M Architecture Register Definitions
 * @details     基于 ARMv7-M Architecture Reference Manual (ARM DDI 0403E.e)
 *              所有寄存器定义严格参考手册章节位置
 *              文档路径：g:\develop\FeatherCore\FeatherArch\docs\arm\Arm® v7-M Architecture Reference Manual.txt
 * @author      FeatherCore
 * @version     1.0.0
 * @date        2026-03-28
 * @note        本文件仅包含寄存器定义和描述，位域定义在单独的头文件中
 *
 * 寄存器覆盖清单：
 * - Arm Core Registers (R0-R15, xPSR, PRIMASK, BASEPRI, FAULTMASK, CONTROL)
 *   参考: D8.1 Arm core registers on page D8-842
 * - Floating-point Extension Registers (S0-S31, D0-D15, FPSCR)
 *   参考: D8.2 Floating-point Extension registers on page D8-843
 * - System Control Space (SCS) Registers
 *   - SCS: ICTR, ACTLR (基地址 0xE000E000)
 *   - SCB: CPUID, ICSR, VTOR, AIRCR, SCR, CCR, SHPR1-3, SHCSR, CFSR, HFSR, DFSR,
 *          MMFAR, BFAR, AFSR, CPACR, ID_PFR0-1, ID_DFR0, ID_AFR0, ID_MMFR0-3,
 *          ID_ISAR0-5, CLIDR, CTR, CCSIDR, CSSELR (基地址 0xE000ED00)
 *   - FPU: FPCCR, FPCAR, FPDSCR, MVFR0-2 (基地址 0xE000EF30)
 *   - SysTick: SYST_CSR, SYST_RVR, SYST_CVR, SYST_CALIB (基地址 0xE000E010)
 *   - NVIC: NVIC_ISER, NVIC_ICER, NVIC_ISPR, NVIC_ICPR, NVIC_IABR, NVIC_IPR (基地址 0xE000E100)
 *   - MPU: MPU_TYPE, MPU_CTRL, MPU_RNR, MPU_RBAR, MPU_RASR, MPU_RBAR_A1-A3, MPU_RASR_A1-A3 (基地址 0xE000ED90)
 *   - Cache Maintenance: ICIALLU, ICIMVAU, DCIMVAC, DCISW, DCCMVAU, DCCMVAC, DCCSW, DCCIMVAC, DCCISW, BPIALL (基地址 0xE000EF50)
 *   - STIR: 软件触发中断寄存器 (基地址 0xE000EF00)
 *   - Peripheral/Component ID: PID0-7, CID0-3 (基地址 0xE000E000, 偏移 0xFD0-0xFFC)
 *   参考: B3.2 System Control Space (SCS) on page B3-595
 * - Debug Registers
 *   - Debug Core: DHCSR, DCRSR, DCRDR, DEMCR (基地址 0xE000EDF0)
 *   - DWT: DWT_CTRL, DWT_CYCCNT, DWT_CPICNT, DWT_EXCCNT, DWT_SLEEPCNT, DWT_LSUCNT,
 *          DWT_FOLDCNT, DWT_PCSR, DWT_COMPn, DWT_MASKn, DWT_FUNCTIONn, DWT_LAR, DWT_LSR (基地址 0xE0001000)
 *   - ITM: ITM_STIMn, ITM_TERn, ITM_TPR, ITM_TCR, ITM_LAR, ITM_LSR (基地址 0xE0000000)
 *   - TPIU: TPIU_SSPSR, TPIU_CSPSR, TPIU_ACPR, TPIU_SPPR, TPIU_TYPE, TPIU_LAR, TPIU_LSR (基地址 0xE0040000)
 *   - FPB: FP_CTRL, FP_REMAP, FP_COMPn, FPB_LAR, FPB_LSR (基地址 0xE0002000)
 *   参考: Chapter C1 Armv7-M Debug
 * - ROM Table: ROM_SCS, ROM_DWT, ROM_FPB, ROM_ITM, ROM_TPIU, ROM_ETM, ROM_END,
 *             ROM_MEMTYPE, ROM_PID0-7, ROM_CID0-3 (基地址 0xE00FF000)
 *   参考: Table C1-3 Armv7-M DAP accessible ROM table on page C1-686
 *
 * 【v7m 独有功能说明】
 * 以下功能仅在 ARMv7-M 中可用，在 ARMv8-M 中已被移除或替代：
 * 1. MPU_RASR 寄存器 - v8m 中使用 MPU_RLAR 替代，并新增 MPU_MAIR0/1 寄存器
 * 2. ROM Table 寄存器 - v8m 中移除了 ROM Table 支持
 * 3. FPU 基地址 - v7m 为 0xE000EF30，v8m 改为 0xE000EF34
 * 4. 组件 ID 寄存器偏移 - v7m 为 0xFD0-0xFFC，v8m 改为 0xEFB0-0xEFFC
 *
 * 【v8m 新增功能（v7m 不支持）】
 * 1. Security Extension - SAU 寄存器、Secure Fault (SFSR/SFAR)、NS 别名机制
 * 2. Stack Pointer Limit - MSPLIM/PSPLIM 寄存器
 * 3. 协处理器电源控制 - CPPWR 寄存器
 * 4. 版本 ID - REVIDR 寄存器
 * 5. Non-secure 访问控制 - NSACR 寄存器
 * 6. NVIC ITNS - 中断目标 Non-secure 寄存器
 * 7. 调试扩展 - DSCEMCR, DAUTHCTRL, DSCSR 寄存器
 * 8. PMU - 性能监控单元
 * 9. RAS - 可靠性、可用性和可服务性扩展
 * 10. MVE - M-Profile 向量扩展 (Q0-Q7, VPR)
 * 11. PACBTI - 指针认证和分支目标识别
 * 12. DWT/ITM/FPB/TPIU 完整的 PIDR/CIDR/DEVARCH/DEVTYPE 寄存器
 ********************************************************************************/

#ifndef __ARM_V7M_CORE_H__
#define __ARM_V7M_CORE_H__

#ifdef __cplusplus
extern "C" {
#endif

/* ==============================================================================
 * 一、Arm 核心寄存器 (Arm Core Registers)
 * 参考: D8.1 Arm core registers on page D8-842
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 1.1 通用寄存器 R0-R12
 * 参考: Table D8-1 Arm core register index on page D8-842
 *      Registers on page B1-516
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_REG_R0              0x00    /* General-purpose register R0 - 通用目的寄存器 0 [RW]
                                               用于函数参数传递 (第 1 个参数)、返回值、临时数据存储
                                               在 AAPCS 调用约定中，R0-R3 用于传递前 4 个参数
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：Registers on page B1-516, A2.3 Registers and Execution state on page A2-30 */

#define ARM_V7M_REG_R1              0x01    /* General-purpose register R1 - 通用目的寄存器 1 [RW]
                                               用于函数参数传递 (第 2 个参数)、返回值 (64 位返回值的高 32 位)
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：Registers on page B1-516, A2.3 Registers and Execution state on page A2-30 */

#define ARM_V7M_REG_R2              0x02    /* General-purpose register R2 - 通用目的寄存器 2 [RW]
                                               用于函数参数传递 (第 3 个参数)、临时数据存储
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：Registers on page B1-516, A2.3 Registers and Execution state on page A2-30 */

#define ARM_V7M_REG_R3              0x03    /* General-purpose register R3 - 通用目的寄存器 3 [RW]
                                               用于函数参数传递 (第 4 个参数)、临时数据存储
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：Registers on page B1-516, A2.3 Registers and Execution state on page A2-30 */

#define ARM_V7M_REG_R4              0x04    /* General-purpose register R4 - 通用目的寄存器 4 [RW]
                                               被调用者保存寄存器 (callee-save),用于存储局部变量或需要长期保存的数据
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：Registers on page B1-516, A2.3 Registers and Execution state on page A2-30 */

#define ARM_V7M_REG_R5              0x05    /* General-purpose register R5 - 通用目的寄存器 5 [RW]
                                               被调用者保存寄存器 (callee-save),用于存储局部变量或需要长期保存的数据
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：Registers on page B1-516, A2.3 Registers and Execution state on page A2-30 */

#define ARM_V7M_REG_R6              0x06    /* General-purpose register R6 - 通用目的寄存器 6 [RW]
                                               被调用者保存寄存器 (callee-save),用于存储局部变量或需要长期保存的数据
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：Registers on page B1-516, A2.3 Registers and Execution state on page A2-30 */

#define ARM_V7M_REG_R7              0x07    /* General-purpose register R7 - 通用目的寄存器 7 [RW]
                                               被调用者保存寄存器 (callee-save),常用于帧指针 (frame pointer)
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：Registers on page B1-516, A2.3 Registers and Execution state on page A2-30 */

#define ARM_V7M_REG_R8              0x08    /* General-purpose register R8 - 通用目的寄存器 8 [RW]
                                               被调用者保存寄存器 (callee-save),在 Thumb 模式下有特殊用途
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：Registers on page B1-516, A2.3 Registers and Execution state on page A2-30 */

#define ARM_V7M_REG_R9              0x09    /* General-purpose register R9 - 通用目的寄存器 9 [RW]
                                               被调用者保存寄存器 (callee-save),传统上用作静态基址寄存器 (SB)
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：Registers on page B1-516, A2.3 Registers and Execution state on page A2-30 */

#define ARM_V7M_REG_R10             0x0A    /* General-purpose register R10 - 通用目的寄存器 10 [RW]
                                               被调用者保存寄存器 (callee-save),传统上用作栈限制寄存器 (SL)
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：Registers on page B1-516, A2.3 Registers and Execution state on page A2-30 */

#define ARM_V7M_REG_R11             0x0B    /* General-purpose register R11 - 通用目的寄存器 11 [RW]
                                               被调用者保存寄存器 (callee-save),传统上用作帧指针 (FP)
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：Registers on page B1-516, A2.3 Registers and Execution state on page A2-30 */

#define ARM_V7M_REG_R12             0x0C    /* General-purpose register R12 - 通用目的寄存器 12 [RW]
                                               调用者保存寄存器，用于过程调用中的临时数据存储
                                               在 AAPCS 中也称为 IP (Intra-Procedure-call scratch register)
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：Registers on page B1-516, A2.3 Registers and Execution state on page A2-30 */

/* -----------------------------------------------------------------------------
 * 1.2 栈指针寄存器
 * 参考: Table D8-1 Arm core register index on page D8-842
 *      The SP registers on page B1-516
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_REG_SP_MAIN         0x08    /* Main Stack Pointer - 主栈指针 (MSP) [RW]
                                               SYSm = 0b00001:000,用于 Handler 模式和 Thread 模式的特权级
                                               复位后默认使用的栈指针，用于操作系统内核和中断服务程序
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：The SP registers on page B1-516, B1.4.1 The Arm core registers on page B1-516 */

#define ARM_V7M_REG_SP_PROCESS      0x09    /* Process Stack Pointer - 进程栈指针 (PSP) [RW]
                                               SYSm = 0b00001:001,仅用于 Thread 模式的非特权级
                                               通常用于用户应用程序，与操作系统栈分离以提高安全性
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：The SP registers on page B1-516, B1.4.1 The Arm core registers on page B1-516 */

#define ARM_V7M_REG_SP              0x0D    /* Stack Pointer - 栈指针 (R13) [RW]
                                               SP_main 和 SP_process 的银行寄存器，根据处理器模式自动选择
                                               在 MRS/MSR 指令中用作 SYSm 编码，实际访问取决于当前模式
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：The SP registers on page B1-516, B1.4.1 The Arm core registers on page B1-516 */

/* -----------------------------------------------------------------------------
 * 1.3 链接寄存器
 * 参考: Table D8-1 Arm core register index on page D8-842
 *      Registers on page B1-516
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_REG_LR              0x0E    /* Link Register - 链接寄存器 (R14) [RW]
                                               存储子程序调用的返回地址，由 BL/BLX 指令自动设置
                                               在异常入口时也用于保存返回地址和异常相关信息 (EXC_RETURN)
                                               EXC_RETURN 值指示返回时的模式切换和栈选择
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：Registers on page B1-516, B1.4.1 The Arm core registers on page B1-516 */

/* -----------------------------------------------------------------------------
 * 1.4 程序计数器
 * 参考: Table D8-1 Arm core register index on page D8-842
 *      Registers on page B1-516
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_REG_PC              0x0F    /* Program Counter - 程序计数器 (R15) [RW]
                                               存储下一条要执行指令的地址，读取时返回当前指令地址 +4
                                               写入 PC 会触发分支操作，bit[0] 决定 Thumb 状态 (必须为 1)
                                               写入奇数地址保持 Thumb 状态，写入偶数地址触发 UsageFault
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：Registers on page B1-516, B1.4.1 The Arm core registers on page B1-516 */

/* -----------------------------------------------------------------------------
 * 1.5 程序状态寄存器
 * 参考: Table D8-1 Arm core register index on page D8-842
 *      The special-purpose Program Status Registers, xPSR on page B1-516
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_REG_APSR            0x00    /* Application Program Status Register - 应用程序状态寄存器 [RW]
                                               SYSm = 0b00000:000,包含条件标志位 N,Z,C,V,Q 标志和 GE[3:0] 标志
                                               N (Negative, bit[31]): 结果为负时置 1
                                               Z (Zero, bit[30]): 结果为零时置 1
                                               C (Carry, bit[29]): 进位/借位时置 1
                                               V (Overflow, bit[28]): 溢出时置 1
                                               Q (Saturation, bit[27]): 饱和运算溢出时置 1 (DSP 扩展)
                                               GE[3:0] (Greater than or Equal, bits[19:16]): DSP 运算的大于等于标志 (DSP 扩展)
                                               应用程序可通过 MSR/MRS 指令读写这些标志位
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：The special-purpose Program Status Registers, xPSR on page B1-516, B1.4.2 on page B1-516, Figure B1-1 on page B1-517 */

#define ARM_V7M_REG_IAPSR           0x01    /* IPSR and APSR - 中断状态和应用程序状态寄存器组合 [RW]
                                               SYSm = 0b00000:001,同时访问 IPSR 和 APSR 的组合视图
                                               用于保存/恢复完整的异常和状态信息
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：The special-purpose Program Status Registers, xPSR on page B1-516, B1.4.2 on page B1-516 */

#define ARM_V7M_REG_EAPSR           0x02    /* EPSR and APSR - 执行状态和应用程序状态寄存器组合 [RW]
                                               SYSm = 0b00000:010,同时访问 EPSR 和 APSR 的组合视图
                                               包含执行状态位 (IT,ICI) 和条件标志位
                                               IT 位：If-Then 块条件执行状态
                                               ICI 位：中断可继续指令状态
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：The special-purpose Program Status Registers, xPSR on page B1-516, B1.4.2 on page B1-516 */

#define ARM_V7M_REG_XPSR            0x03    /* Full Program Status Register - 完整程序状态寄存器 [RW]
                                               SYSm = 0b00000:011,访问所有 xPSR 位 (APSR+IPSR+EPSR)
                                               用于异常入口/出口时完整保存程序状态
                                               异常入口时硬件自动压栈，异常返回时自动恢复
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：The special-purpose Program Status Registers, xPSR on page B1-516, B1.4.2 on page B1-516 */

#define ARM_V7M_REG_IPSR            0x05    /* Interrupt Program Status Register - 中断程序状态寄存器 [RO]
                                               SYSm = 0b00000:101,包含当前异常编号 (Exception Number[8:0])
                                               只读寄存器，硬件在异常入口时自动设置，指示当前执行的异常
                                               异常编号：1=Reset, 2=NMI, 3=HardFault, 4-15=系统异常，16+=外部中断
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：The special-purpose Program Status Registers, xPSR on page B1-516, B1.4.2 on page B1-516 */

#define ARM_V7M_REG_EPSR            0x06    /* Execution Program Status Register - 执行程序状态寄存器 [RW]
                                               SYSm = 0b00000:110,包含执行状态位 (T,ICI/IT)
                                               T 位 (bit[24]) 必须为 1 以支持 Thumb 指令集，为 0 会触发 UsageFault
                                               IT 块：If-Then 条件执行指令块状态
                                               ICI/IT 位：中断继续/条件执行状态信息
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：The special-purpose Program Status Registers, xPSR on page B1-516, B1.4.2 on page B1-516 */

#define ARM_V7M_REG_IEPSR           0x07    /* IPSR and EPSR - 中断状态和执行状态寄存器组合 [RW]
                                               SYSm = 0b00000:111,同时访问 IPSR 和 EPSR 的组合视图
                                               用于保存/恢复中断和执行状态信息
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：The special-purpose Program Status Registers, xPSR on page B1-516, B1.4.2 on page B1-516 */

/* -----------------------------------------------------------------------------
 * 1.6 特殊用途掩码寄存器
 * 参考: Table D8-1 Arm core register index on page D8-842
 *      The special-purpose mask registers on page B1-519
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_REG_PRIMASK         0x10    /* Priority Mask Register - 优先级屏蔽寄存器 [RW]
                                               SYSm = 0b00010:000,1 位寄存器，用于屏蔽所有可配置优先级的异常
                                               PRIMASK[0]=1: 屏蔽优先级为 0 的异常 (除 NMI 和 HardFault)
                                               PRIMASK[0]=0: 正常中断处理
                                               可通过 CPSID i 指令设置，CPSIE i 指令清除
                                               访问权限：仅特权级可访问，非特权级访问为 RAZ/WI
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：The special-purpose mask registers on page B1-519, B1.4.3 on page B1-519 */

#define ARM_V7M_REG_BASEPRI         0x11    /* Base Priority Mask Register - 基础优先级屏蔽寄存器 [RW]
                                               SYSm = 0b00010:001,8 位寄存器，用于屏蔽指定优先级以下的异常
                                               BASEPRI=0: 禁用 BASEPRI 屏蔽
                                               BASEPRI=n: 屏蔽优先级>=n 的所有异常
                                               实现的位数取决于处理器的优先级位数 (通常 3-8 位)
                                               可通过 MSR 指令写入，MRS 指令读取
                                               访问权限：仅特权级可访问，非特权级访问为 RAZ/WI
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：The special-purpose mask registers on page B1-519, B1.4.3 on page B1-519 */

#define ARM_V7M_REG_BASEPRI_MAX     0x12    /* Base Priority Mask (Conditional Update) - 基础优先级屏蔽寄存器 (条件更新) [WO]
                                               SYSm = 0b00010:010,MSR 指令的特殊掩码参数
                                               仅当新值>当前 BASEPRI 值时才更新 BASEPRI
                                               用于实现临界区的优先级保护，防止高优先级代码降低屏蔽级别
                                               只能通过 MSR 指令写入，不能读取
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：The special-purpose mask registers on page B1-519, B1.4.3 on page B1-519 */

#define ARM_V7M_REG_FAULTMASK       0x13    /* Fault Mask Register - 故障屏蔽寄存器 [RW]
                                               SYSm = 0b00010:011,1 位寄存器，用于屏蔽所有异常 (包括 Fault)
                                               FAULTMASK[0]=1: 屏蔽所有异常 (除 NMI),执行优先级提升到 -1
                                               FAULTMASK[0]=0: 正常中断处理
                                               可通过 CPSID f 指令设置，CPSIE f 指令清除
                                               异常返回时自动清零 (除 NMI 返回)
                                               访问权限：仅特权级可访问，非特权级访问为 RAZ/WI
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：The special-purpose mask registers on page B1-519, B1.4.3 on page B1-519 */

/* -----------------------------------------------------------------------------
 * 1.7 控制寄存器
 * 参考: Table D8-1 Arm core register index on page D8-842
 *      The special-purpose CONTROL register on page B1-519
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_REG_CONTROL         0x14    /* Control Register - 控制寄存器 [RW]
                                               SYSm = 0b00010:100,控制 Thread 模式的特权级和栈选择
                                               CONTROL[0] (nPRIV): 0=Thread 模式特权级，1=Thread 模式非特权级
                                               CONTROL[1] (SPSEL): 0=使用 SP_main, 1=使用 SP_process (仅 Thread 模式)
                                               CONTROL[2] (FPCA): 0=FP 扩展未激活，1=FP 扩展激活 (仅 FP 扩展)
                                               写入 CONTROL 后需要执行 ISB 指令保证同步
                                               访问权限：仅特权级可自由访问，非特权级只能读 nPRIV 位
                                               参考：Table D8-1 Arm core register index on page D8-842
                                               备注：The special-purpose CONTROL register on page B1-519, B1.4.4 on page B1-519 */

/* ==============================================================================
 * 二、浮点扩展寄存器 (Floating-point Extension Registers)
 * 参考: D8.2 Floating-point Extension registers on page D8-843
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 2.1 浮点状态控制寄存器
 * 参考: D8.2.1 Floating-point Extension System register on page D8-843
 *      Floating-point Status and Control Register, FPSCR on page A2-37
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_REG_FPSCR           0x01    /* Floating-point Status and Control Register - 浮点状态和控制寄存器 [RW]
                                               FP 扩展系统寄存器，位于 CP10 和 CP11 协处理器空间
                                               包含浮点运算状态标志 (IOC, DZC, OFC, UFC, IXC, FPSID)
                                               包含舍入模式控制 (RMode) 和默认 NaN 控制 (DN)
                                               包含浮点异常使能位 (IOE, DZE, OFE, UFE, IXE)
                                               可通过 VMRS/VMSR 指令访问
                                               备注：FP extension, D8.2.1 Floating-point Extension System register on page D8-843, A2.5 on page A2-37 */

/* -----------------------------------------------------------------------------
 * 2.2 浮点数据寄存器
 * 参考: D8.2.2 Floating-point Extension registers on page D8-843
 *      The FP extension registers on page A2-35
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_REG_S0              0x00    /* Single-precision floating-point register S0 - 单精度浮点寄存器 S0 [RW]
                                               32 位浮点数据寄存器，可存储单精度浮点数
                                               也可作为 32 位整数寄存器使用
                                               在 VFP 指令中用于浮点运算，在 M 寄存器传输指令中用于整数操作
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S1              0x01    /* Single-precision floating-point register S1 - 单精度浮点寄存器 S1 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S2              0x02    /* Single-precision floating-point register S2 - 单精度浮点寄存器 S2 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S3              0x03    /* Single-precision floating-point register S3 - 单精度浮点寄存器 S3 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S4              0x04    /* Single-precision floating-point register S4 - 单精度浮点寄存器 S4 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S5              0x05    /* Single-precision floating-point register S5 - 单精度浮点寄存器 S5 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S6              0x06    /* Single-precision floating-point register S6 - 单精度浮点寄存器 S6 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S7              0x07    /* Single-precision floating-point register S7 - 单精度浮点寄存器 S7 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */
#define ARM_V7M_REG_S8              0x08    /* Single-precision floating-point register S8 - 单精度浮点寄存器 S8 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S9              0x09    /* Single-precision floating-point register S9 - 单精度浮点寄存器 S9 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S10             0x0A    /* Single-precision floating-point register S10 - 单精度浮点寄存器 S10 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S11             0x0B    /* Single-precision floating-point register S11 - 单精度浮点寄存器 S11 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S12             0x0C    /* Single-precision floating-point register S12 - 单精度浮点寄存器 S12 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S13             0x0D    /* Single-precision floating-point register S13 - 单精度浮点寄存器 S13 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S14             0x0E    /* Single-precision floating-point register S14 - 单精度浮点寄存器 S14 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S15             0x0F    /* Single-precision floating-point register S15 - 单精度浮点寄存器 S15 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S16             0x10    /* Single-precision floating-point register S16 - 单精度浮点寄存器 S16 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S17             0x11    /* Single-precision floating-point register S17 - 单精度浮点寄存器 S17 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S18             0x12    /* Single-precision floating-point register S18 - 单精度浮点寄存器 S18 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S19             0x13    /* Single-precision floating-point register S19 - 单精度浮点寄存器 S19 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S20             0x14    /* Single-precision floating-point register S20 - 单精度浮点寄存器 S20 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S21             0x15    /* Single-precision floating-point register S21 - 单精度浮点寄存器 S21 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S22             0x16    /* Single-precision floating-point register S22 - 单精度浮点寄存器 S22 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S23             0x17    /* Single-precision floating-point register S23 - 单精度浮点寄存器 S23 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S24             0x18    /* Single-precision floating-point register S24 - 单精度浮点寄存器 S24 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S25             0x19    /* Single-precision floating-point register S25 - 单精度浮点寄存器 S25 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S26             0x1A    /* Single-precision floating-point register S26 - 单精度浮点寄存器 S26 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S27             0x1B    /* Single-precision floating-point register S27 - 单精度浮点寄存器 S27 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S28             0x1C    /* Single-precision floating-point register S28 - 单精度浮点寄存器 S28 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S29             0x1D    /* Single-precision floating-point register S29 - 单精度浮点寄存器 S29 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S30             0x1E    /* Single-precision floating-point register S30 - 单精度浮点寄存器 S30 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_S31             0x1F    /* Single-precision floating-point register S31 - 单精度浮点寄存器 S31 [RW]
                                               32 位浮点数据寄存器，功能同 S0
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_D0              0x00    /* Doubleword floating-point register D0 - 双字浮点寄存器 D0 [RW]
                                               64 位浮点数据寄存器，S0 和 S1 的组合视图
                                               D0[31:0] = S0, D0[63:32] = S1
                                               用于双精度浮点运算 (如果实现 FPv5 扩展)
                                               也可作为两个 32 位寄存器或一个 64 位整数寄存器使用
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_D1              0x01    /* Doubleword floating-point register D1 - 双字浮点寄存器 D1 [RW]
                                               64 位浮点数据寄存器，S2 和 S3 的组合视图
                                               D1[31:0] = S2, D1[63:32] = S3
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_D2              0x02    /* Doubleword floating-point register D2 - 双字浮点寄存器 D2 [RW]
                                               64 位浮点数据寄存器，S4 和 S5 的组合视图
                                               D2[31:0] = S4, D2[63:32] = S5
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_D3              0x03    /* Doubleword floating-point register D3 - 双字浮点寄存器 D3 [RW]
                                               64 位浮点数据寄存器，S6 和 S7 的组合视图
                                               D3[31:0] = S6, D3[63:32] = S7
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_D4              0x04    /* Doubleword floating-point register D4 - 双字浮点寄存器 D4 [RW]
                                               64 位浮点数据寄存器，S8 和 S9 的组合视图
                                               D4[31:0] = S8, D4[63:32] = S9
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_D5              0x05    /* Doubleword floating-point register D5 - 双字浮点寄存器 D5 [RW]
                                               64 位浮点数据寄存器，S10 和 S11 的组合视图
                                               D5[31:0] = S10, D5[63:32] = S11
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_D6              0x06    /* Doubleword floating-point register D6 - 双字浮点寄存器 D6 [RW]
                                               64 位浮点数据寄存器，S12 和 S13 的组合视图
                                               D6[31:0] = S12, D6[63:32] = S13
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_D7              0x07    /* Doubleword floating-point register D7 - 双字浮点寄存器 D7 [RW]
                                               64 位浮点数据寄存器，S14 和 S15 的组合视图
                                               D7[31:0] = S14, D7[63:32] = S15
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_D8              0x08    /* Doubleword floating-point register D8 - 双字浮点寄存器 D8 [RW]
                                               64 位浮点数据寄存器，S16 和 S17 的组合视图
                                               D8[31:0] = S16, D8[63:32] = S17
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_D9              0x09    /* Doubleword floating-point register D9 - 双字浮点寄存器 D9 [RW]
                                               64 位浮点数据寄存器，S18 和 S19 的组合视图
                                               D9[31:0] = S18, D9[63:32] = S19
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_D10             0x0A    /* Doubleword floating-point register D10 - 双字浮点寄存器 D10 [RW]
                                               64 位浮点数据寄存器，S20 和 S21 的组合视图
                                               D10[31:0] = S20, D10[63:32] = S21
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_D11             0x0B    /* Doubleword floating-point register D11 - 双字浮点寄存器 D11 [RW]
                                               64 位浮点数据寄存器，S22 和 S23 的组合视图
                                               D11[31:0] = S22, D11[63:32] = S23
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_D12             0x0C    /* Doubleword floating-point register D12 - 双字浮点寄存器 D12 [RW]
                                               64 位浮点数据寄存器，S24 和 S25 的组合视图
                                               D12[31:0] = S24, D12[63:32] = S25
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_D13             0x0D    /* Doubleword floating-point register D13 - 双字浮点寄存器 D13 [RW]
                                               64 位浮点数据寄存器，S26 和 S27 的组合视图
                                               D13[31:0] = S26, D13[63:32] = S27
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_D14             0x0E    /* Doubleword floating-point register D14 - 双字浮点寄存器 D14 [RW]
                                               64 位浮点数据寄存器，S28 和 S29 的组合视图
                                               D14[31:0] = S28, D14[63:32] = S29
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

#define ARM_V7M_REG_D15             0x0F    /* Doubleword floating-point register D15 - 双字浮点寄存器 D15 [RW]
                                               64 位浮点数据寄存器，S30 和 S31 的组合视图
                                               D15[31:0] = S30, D15[63:32] = S31
                                               备注：FP extension, D8.2.2 Floating-point Extension registers on page D8-843, A2.5 on page A2-35 */

/* ==============================================================================
 * 三、系统控制空间 (SCS) - System Control Space
 * 参考: B3.2 System Control Space (SCS) on page B3-595
 * 基地址: 0xE000E000
 * ==============================================================================
 */
#define ARM_V7M_SCS_BASE            0xE000E000UL

/* -----------------------------------------------------------------------------
 * 3.0 SCS 系统控制寄存器 (不在 SCB 中的寄存器)
 * 参考: Table B3-6 Summary of system control and ID registers not in the SCB
 * 地址范围: 0xE000E000 - 0xE000E00F
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_SCS_ICTR            0x004   /* Interrupt Controller Type Register - 中断控制器类型寄存器 [RO]
                                               地址: 0xE000E004
                                               提供中断控制器的信息
                                               指示实现的外部中断线数量 (INTLINESNUM)
                                               INTLINESNUM = 支持的外部中断数 / 32 - 1
                                               只读寄存器，硬件实现时确定
                                               软件可以读取以确定 NVIC 的大小
                                               参考：Interrupt Controller Type Register, ICTR on page B3-618
                                               备注：Table B3-6 on page B3-597 */

#define ARM_V7M_SCS_ACTLR           0x008   /* Auxiliary Control Register - 辅助控制寄存器 [RW]
                                               地址: 0xE000E008
                                               提供 IMPLEMENTATION DEFINED 辅助控制特性
                                               位域定义取决于具体的处理器实现，架构手册未定义具体位域
                                               具体请参考处理器厂商的技术参考手册
                                               例如: Cortex-M7 参考 Arm Cortex-M7 Processor TRM, Table 3-3
                                                     Cortex-M4 参考 Arm Cortex-M4 Processor TRM
                                               参考：Auxiliary Control Register, ACTLR on page B3-618
                                               备注：Table B3-6 on page B3-597, IMPLEMENTATION DEFINED */

/* -----------------------------------------------------------------------------
 * 3.1 系统控制块 (SCB) - System Control Block
 * 参考: Table D8-2 Memory-mapped System register index on page D8-844
 * 地址范围: 0xE000ED00 - 0xE000ED8F
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_SCB_BASE            0xE000ED00UL

#define ARM_V7M_SCB_CPUID           0x000   /* CPUID Base Register - CPUID 基寄存器 [RO]
                                               提供处理器标识信息，包含架构版本、实现者ID、零件号、修订版本等
                                               只读寄存器，上电复位时由硬件设置
                                               用于操作系统和调试器识别处理器类型和特性
                                               参考：CPUID Base Register on page B3-598
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_ICSR            0x004   /* Interrupt Control and State Register - 中断控制和状态寄存器 [RW]
                                               提供 NMI、PendSV 和 SysTick 异常的软件控制
                                               提供中断状态信息，包括当前活跃的异常编号
                                               可通过软件触发 PendSV 和 SysTick 异常
                                               包含中断挂起和活跃标志
                                               参考：Interrupt Control and State Register, ICSR on page B3-599
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_VTOR            0x008   /* Vector Table Offset Register - 向量表偏移寄存器 [RW]
                                               保存向量表的基地址
                                               向量表包含所有异常处理程序的入口地址
                                               软件可在运行时重新定位向量表
                                               复位时默认值为 0x00000000
                                               参考：Vector Table Offset Register, VTOR on page B3-601
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_AIRCR           0x00C   /* Application Interrupt and Reset Control Register - 应用程序中断和复位控制寄存器 [RW]
                                               设置或返回中断控制数据
                                               提供系统复位功能（需要写入 VECTKEY 密钥 0x05FA）
                                               包含数据端序指示位 (ENDIANNESS)
                                               提供中断优先级分组控制 (PRIGROUP)
                                               可用于清除所有挂起的异常状态
                                               参考：Application Interrupt and Reset Control Register, AIRCR on page B3-601
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_SCR             0x010   /* System Control Register - 系统控制寄存器 [RW]
                                               设置或返回系统控制数据
                                               控制低功耗模式（SLEEPDEEP 位）
                                               控制睡眠进入行为（SLEEPONEXIT 位）
                                               控制异常唤醒行为（SEVONPEND 位）
                                               用于管理处理器的电源和睡眠状态
                                               参考：System Control Register, SCR on page B3-603
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_CCR             0x014   /* Configuration and Control Register - 配置和控制寄存器 [RW]
                                               设置或返回配置和控制数据
                                               提供缓存和分支预测控制
                                               控制未对齐访问陷阱 (UNALIGN_TRP)
                                               控制除零陷阱 (DIV_0_TRP)
                                               控制线程模式和 Handler 模式栈对齐 (STKALIGN)
                                               控制基准优先级行为 (BFHFNMIGN)
                                               控制非特权访问 (USERSETMPEND)
                                               参考：Configuration and Control Register, CCR on page B3-604
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_SHPR1           0x018   /* System Handler Priority Register 1 - 系统处理程序优先级寄存器 1 [RW]
                                               设置或返回系统处理程序 4-7 的优先级
                                               系统处理程序 4-7: 4=MemManage, 5=BusFault, 6=UsageFault, 7=SecureFault (可选)
                                               每个处理程序占 8 位，优先级值越小优先级越高
                                               实现的优先级位数取决于处理器 (通常 3-8 位)
                                               参考：System Handler Priority Register 1, SHPR1 on page B3-606
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_SHPR2           0x01C   /* System Handler Priority Register 2 - 系统处理程序优先级寄存器 2 [RW]
                                               设置或返回系统处理程序 8-11 的优先级
                                               系统处理程序 8-11: 8=Reserved, 9=Reserved, 10=Reserved, 11=SVCall
                                               每个处理程序占 8 位，优先级值越小优先级越高
                                               SVCall 通常设置为高优先级用于系统调用
                                               参考：System Handler Priority Register 2, SHPR2 on page B3-606
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_SHPR3           0x020   /* System Handler Priority Register 3 - 系统处理程序优先级寄存器 3 [RW]
                                               设置或返回系统处理程序 12-15 的优先级
                                               系统处理程序 12-15: 12=DebugMonitor, 13=Reserved, 14=PendSV, 15=SysTick
                                               每个处理程序占 8 位，优先级值越小优先级越高
                                               DebugMonitor 通常设置为中等优先级用于调试
                                               PendSV 通常设置为最低优先级用于上下文切换
                                               SysTick 通常设置为中等优先级用于系统滴答
                                               参考：System Handler Priority Register 3, SHPR3 on page B3-607
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_SHCSR           0x024   /* System Handler Control and State Register - 系统处理程序控制和状态寄存器 [RW]
                                               控制并提供系统异常的活跃和挂起状态
                                               包含 MemManage、BusFault、UsageFault 异常的使能位
                                               包含 SVC 调用挂起标志 (SVCALLPENDED)
                                               包含总线故障挂起标志 (BUSFAULT PENDING)
                                               包含 MemManage 故障挂起标志 (MEMFAULT PENDING)
                                               包含 UsageFault 故障挂起标志 (USGFAULT PENDING)
                                               包含系统处理程序的活跃标志
                                               参考：System Handler Control and State Register, SHCSR on page B3-607
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_CFSR            0x028   /* Configurable Fault Status Register - 可配置故障状态寄存器 [RW]
                                               包含三个可配置故障状态寄存器 (MMFSR, BFSR, UFSR)
                                               MMFSR (byte[0]): MemManage 故障状态
                                               BFSR (byte[1]): BusFault 故障状态
                                               UFSR (halfword[2]): UsageFault 故障状态
                                               所有状态位都是写一清零 (W1C)
                                               用于诊断和处理故障异常
                                               参考：Configurable Fault Status Register, CFSR on page B3-609
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_HFSR            0x02C   /* HardFault Status Register - HardFault 状态寄存器 [RW]
                                               显示任何 HardFault 异常的原因
                                               包含调试事件标志 (DEBUGEVT)
                                               包含向量表读取错误标志 (VECTTBL)
                                               包含强制硬故障标志 (FORCED)
                                               所有状态位都是写一清零 (W1C)
                                               用于诊断不可恢复的系统错误
                                               参考：HardFault Status Register, HFSR on page B3-612
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_DFSR            0x030   /* Debug Fault Status Register - 调试故障状态寄存器 [RW]
                                               提供调试事件的信息
                                               包含外部调试请求标志 (EXTERNAL)
                                               包含向量捕获标志 (VCATCH)
                                               包含 DWT 陷阱标志 (DWTTRAP)
                                               包含断点标志 (BKPT)
                                               包含停止标志 (HALTED)
                                               所有状态位都是写一清零 (W1C)
                                               参考：Debug Fault Status Register, DFSR on page C1-699
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_MMFSR           0x028   /* MemManage Status Register - MemManage 状态寄存器 [RW]
                                               包含 MemManage 故障状态信息 (字节访问)
                                               CFSR 的 byte[0]，可单独字节访问
                                               包含指令访问违例标志 (IACCVIOL)
                                               包含数据访问违例标志 (DACCVIOL)
                                               包含 MPU 违例时的地址有效标志 (MMARVALID)
                                               包含栈指针无效标志 (MLSPERR)
                                               所有状态位都是写一清零 (W1C)
                                               参考：MemManage Status Register, MMFSR on page B3-609
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_BFSR            0x029   /* BusFault Status Register - BusFault 状态寄存器 [RW]
                                               包含 BusFault 故障状态信息 (字节访问)
                                               CFSR 的 byte[1]，可单独字节访问
                                               包含指令总线错误标志 (IBUSERR)
                                               包含精确数据总线错误标志 (PRECISERR)
                                               包含不精确数据总线错误标志 (IMPRECISERR)
                                               包含总线错误时的地址有效标志 (BFARVALID)
                                               所有状态位都是写一清零 (W1C)
                                               参考：BusFault Status Register, BFSR on page B3-610
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_UFSR            0x02A   /* UsageFault Status Register - UsageFault 状态寄存器 [RW]
                                               包含 UsageFault 故障状态信息 (半字访问)
                                               CFSR 的 halfword[2]，可单独半字访问
                                               包含未定义指令标志 (UNDEFINSTR)
                                               包含无效状态标志 (INVSTATE)
                                               包含无效 PC 标志 (INVPC)
                                               包含协处理器访问标志 (NOCP)
                                               包含未对齐访问标志 (UNALIGNED)
                                               包含除零标志 (DIVBYZERO)
                                               所有状态位都是写一清零 (W1C)
                                               参考：UsageFault Status Register, UFSR on page B3-611
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_MMFAR           0x034   /* MemManage Fault Address Register - MemManage 故障地址寄存器 [RW]
                                               保存导致 MemManage 故障的位置地址
                                               仅当 MMFSR.MMARVALID 置 1 时有效
                                               精确故障时保存触发故障的地址
                                               软件可以读取此地址进行故障诊断
                                               故障处理程序返回时通常不需要清除
                                               参考：MemManage Fault Address Register, MMFAR on page B3-613
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_BFAR            0x038   /* BusFault Address Register - BusFault 故障地址寄存器 [RW]
                                               保存导致精确 BusFault 的位置地址
                                               仅当 BFSR.BFARVALID 置 1 时有效
                                               精确故障时保存触发故障的地址
                                               不精确故障时地址无效，不更新此寄存器
                                               软件可以读取此地址进行故障诊断
                                               参考：BusFault Address Register, BFAR on page B3-614
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_AFSR            0x03C   /* Auxiliary Fault Status Register - 辅助故障状态寄存器 [RW]
                                               提供 IMPLEMENTATION DEFINED 故障状态信息
                                               字段定义取决于具体的处理器实现
                                               用于扩展故障诊断能力
                                               通常由芯片厂商用于提供额外的故障信息
                                               参考：Auxiliary Fault Status Register, AFSR on page B3-614
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_PACR            0x040   /* Coprocessor Access Control Register - 协处理器访问控制寄存器 [RW]
                                               控制对协处理器的访问权限
                                               也称为 CPACR (Coprocessor Access Control Register)
                                               每个协处理器占用 2 位，控制访问级别
                                               位[21:20] 控制 CP10 (浮点)，位[23:22] 控制 CP11 (浮点)
                                               00: 无访问权限，01: 特权级访问，10: 保留，11: 全访问
                                               用于启用/禁用浮点单元 (FPU)
                                               参考：Coprocessor Access Control Register, CPACR on page B3-614
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SCB_CPACR           ARM_V7M_SCB_PACR  /* Alias for CPACR - CPACR 的别名 */

/* -----------------------------------------------------------------------------
 * 3.1a 浮点扩展寄存器 (FP Extension Registers)
 * 参考: Table B3-5 Summary of additional SCB registers for the FP extension
 * 基地址: 0xE000EF30
 * 地址范围: 0xE000EF34 - 0xE000EF48
 * 注意: 这些寄存器不在 SCB 基地址范围内，需要独立的基地址
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_FPU_BASE            0xE000EF30UL

#define ARM_V7M_FPU_FPCCR           0x004   /* Floating Point Context Control Register - 浮点上下文控制寄存器 [RW]
                                               地址: 0xE000EF34
                                               控制浮点上下文 (仅 FP 扩展)
                                               控制浮点上下文的自动保存和恢复
                                               包含延迟状态保存控制 (LSPEN)
                                               包含用户模式访问控制 (USER)
                                               包含线程模式特权访问控制 (THREAD)
                                               包含监控模式访问控制 (MONITOR)
                                               包含总线故障时的行为控制 (BUSFAULT)
                                               参考：Floating Point Context Control Register, FPCCR on page B3-615
                                               备注：Table B3-5 on page B3-597 */

#define ARM_V7M_FPU_FPCAR           0x008   /* Floating Point Context Address Register - 浮点上下文地址寄存器 [RW]
                                               地址: 0xE000EF38
                                               保存内存中浮点上下文的位置 (仅 FP 扩展)
                                               指向浮点寄存器在栈上的保存位置
                                               异常入口时硬件自动设置，异常返回时使用
                                               软件可以读取以定位浮点上下文
                                               用于调试和上下文管理
                                               参考：Floating Point Context Address Register, FPCAR on page B3-617
                                               备注：Table B3-5 on page B3-597 */

#define ARM_V7M_FPU_FPDSCR          0x00C   /* Floating Point Default Status Control Register - 浮点默认状态控制寄存器 [RW]
                                               地址: 0xE000EF3C
                                               保存 FPSCR 的默认值 (仅 FP 扩展)
                                               异常入口时 FPSCR 的默认值来源于此寄存器
                                               用于初始化浮点运算的舍入模式和异常使能
                                               软件可配置默认的浮点行为
                                               复位值为标准的 Arm 浮点配置
                                               参考：Floating Point Default Status Control Register, FPDSCR on page B3-617
                                               备注：Table B3-5 on page B3-597 */

#define ARM_V7M_FPU_MVFR0           0x010   /* Media and FP Feature Register 0 - 媒体和浮点特性寄存器 0 [RO]
                                               地址: 0xE000EF40
                                               提供浮点单元特性信息 (仅 FP 扩展)
                                               指示支持的浮点运算类型 (单精度/双精度)
                                               指示支持的向量运算能力
                                               指示支持的 SIMD 操作
                                               只读寄存器，用于软件检测 FPU 能力
                                               参考：Media and FP Feature Register 0, MVFR0 on page B4-662
                                               备注：Table B3-5 on page B3-597 */

#define ARM_V7M_FPU_MVFR1           0x014   /* Media and FP Feature Register 1 - 媒体和浮点特性寄存器 1 [RO]
                                               地址: 0xE000EF44
                                               提供额外的浮点特性信息 (仅 FP 扩展)
                                               位[3:0]: 浮点融合乘加 (0001=支持浮点融合乘加)
                                               只读寄存器，用于识别高级浮点特性
                                               参考：Media and FP Feature Register 1, MVFR1 on page B4-663
                                               备注：Table B3-5 on page B3-597 */

#define ARM_V7M_FPU_MVFR2           0x018   /* Media and FP Feature Register 2 - 媒体和浮点特性寄存器 2 [RO]
                                               地址: 0xE000EF48
                                               提供 FPv5 扩展的特性信息 (仅 FP 扩展)
                                               位[7:4]: 浮点舍入模式 (0001=支持所有舍入模式)
                                               位[3:0]: 向量浮点 (0000=不支持向量，0001=支持向量)
                                               复位值: 0x00000040 (如果实现 FPv5)，否则 0x00000000
                                               参考：Media and FP Feature Register 2, MVFR2 on page B4-664
                                               备注：Table B3-5 on page B3-597 */

/* 为向后兼容保留的旧名称别名 */
#define ARM_V7M_SCB_FPCCR           ARM_V7M_FPU_FPCCR
#define ARM_V7M_SCB_FPCAR           ARM_V7M_FPU_FPCAR
#define ARM_V7M_SCB_FPDSCR          ARM_V7M_FPU_FPDSCR
#define ARM_V7M_SCB_MVFR0           ARM_V7M_FPU_MVFR0
#define ARM_V7M_SCB_MVFR1           ARM_V7M_FPU_MVFR1
#define ARM_V7M_SCB_MVFR2           ARM_V7M_FPU_MVFR2

/* -----------------------------------------------------------------------------
 * 3.2 软件触发中断寄存器 (STIR)
 * 参考: Table D8-2 Memory-mapped System register index on page D8-844
 * 地址: 0xE000EF00
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_STIR_BASE           0xE000EF00UL
#define ARM_V7M_STIR                0x000   /* Software Triggered Interrupt Register - 软件触发中断寄存器 [WO]
                                               写入此寄存器会触发中断
                                               仅特权级可访问，非特权级访问触发 UsageFault
                                               写入中断编号到低 9 位 ([8:0]) 触发对应中断
                                               写入 0-15 触发系统异常，写入 16+ 触发外部中断
                                               仅支持写入已实现的中断编号
                                               参考：Software Triggered Interrupt Register, STIR on page B3-619
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

/* -----------------------------------------------------------------------------
 * 3.3 SysTick 定时器寄存器
 * 参考: Table D8-2 Memory-mapped System register index on page D8-844
 * 地址范围: 0xE000E010 - 0xE000E01F
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_SYST_BASE           0xE000E010UL

#define ARM_V7M_SYST_CSR            0x000   /* SysTick Control and Status Register - SysTick 控制和状态寄存器 [RW]
                                               控制 SysTick 定时器的操作
                                               包含使能位 (ENABLE): 1=使能计数，0=禁用计数
                                               包含中断使能位 (TICKINT): 1=计数到 0 时触发 SysTick 异常
                                               包含时钟源选择位 (CLKSOURCE): 1=处理器时钟，0=外部时钟
                                               包含计数标志位 (COUNTFLAG): 计数到 0 时硬件置 1，读取时清零
                                               用于操作系统的系统滴答时钟
                                               参考：SysTick Control and Status Register, SYST_CSR on page B3-621
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SYST_RVR            0x004   /* SysTick Reload Value Register - SysTick 重装载值寄存器 [RW]
                                               保存 SysTick 计数器的重装载值
                                               计数器计数到 0 时，下一个时钟周期将此值加载到 CVR
                                               有效值为 0x00000001 - 0x00FFFFFF (24 位)
                                               设置为 0 时计数器不工作
                                               用于配置 SysTick 的周期
                                               参考：SysTick Reload Value Register, SYST_RVR on page B3-622
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SYST_CVR            0x008   /* SysTick Current Value Register - SysTick 当前值寄存器 [RW]
                                               保存 SysTick 计数器的当前值
                                               每个时钟周期递减 1
                                               写入任何值都会清除计数器为 0，并清除 CSR.COUNTFLAG
                                               读取返回当前计数值，写入清零
                                               24 位有效位，位[31:24] RAZ
                                               参考：SysTick Current Value Register, SYST_CVR on page B3-622
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_SYST_CALIB          0x00C   /* SysTick Calibration value Register - SysTick 校准值寄存器 [RO]
                                               指示 SysTick 的校准属性
                                               包含 10ms 校准值 (TENMS): 10ms 所需的时钟数
                                               包含精确标志 (SKEW): 0=TENMS 精确，1=TENMS 不精确
                                               包含无参考时钟标志 (NOREF): 1=无外部参考时钟
                                               只读寄存器，用于确定系统时钟频率
                                               位[31:24] 和位[29:24] 保留
                                               参考：SysTick Calibration value Register, SYST_CALIB on page B3-623
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

/* -----------------------------------------------------------------------------
 * 3.4 嵌套向量中断控制器 (NVIC) 寄存器
 * 参考: Table D8-2 Memory-mapped System register index on page D8-844
 * 地址范围: 0xE000E100 - 0xE000E4FF
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_NVIC_BASE           0xE000E100UL

/* -----------------------------------------------------------------------------
 * NVIC 寄存器组通用宏 (使用示例: ARM_V7M_NVIC_ISER(n), n = 0-15)
 * 说明: 对于连续编号的寄存器，n 表示寄存器编号，通过公式计算偏移量
 * 基地址 + (起始偏移 + n * 步长)
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_NVIC_ISER(n)        (0x000 + (n) * 0x04)  /* Interrupt Set-Enable Register n (n=0-15)
                                                               中断使能置位寄存器 n [RW]
                                                               用于启用外部中断，写入 1 置位对应中断使能
                                                               每个位控制一个外部中断的使能
                                                               位 m=1: 中断 m 使能；位 m=0: 中断 m 使能状态不变
                                                               读取返回当前使能状态
                                                               参考：Interrupt Set-Enable Registers, NVIC_ISER0-NVIC_ISER15 on page B3-628
                                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_NVIC_ICER(n)        (0x080 + (n) * 0x04)  /* Interrupt Clear-Enable Register n (n=0-15)
                                                               中断使能清零寄存器 n [RW]
                                                               用于禁用外部中断，写入 1 清零对应中断使能
                                                               每个位控制一个外部中断的使能
                                                               位 m=1: 中断 m 禁用；位 m=0: 中断 m 使能状态不变
                                                               读取返回当前使能状态
                                                               参考：Interrupt Clear-Enable Registers, NVIC_ICER0-NVIC_ICER15 on page B3-628
                                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_NVIC_ISPR(n)        (0x100 + (n) * 0x04)  /* Interrupt Set-Pending Register n (n=0-15)
                                                               中断挂起置位寄存器 n [RW]
                                                               用于挂起外部中断，写入 1 置位对应中断挂起标志
                                                               每个位控制一个外部中断的挂起状态
                                                               位 m=1: 中断 m 挂起；位 m=0: 中断 m 挂起状态不变
                                                               读取返回当前挂起状态
                                                               参考：Interrupt Set-Pending Registers, NVIC_ISPR0-NVIC_ISPR15 on page B3-629
                                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_NVIC_ICPR(n)        (0x180 + (n) * 0x04)  /* Interrupt Clear-Pending Register n (n=0-15)
                                                               中断挂起清零寄存器 n [RW]
                                                               用于清除中断挂起状态，写入 1 清零对应中断挂起标志
                                                               每个位控制一个外部中断的挂起状态
                                                               位 m=1: 清除中断 m 挂起；位 m=0: 中断 m 挂起状态不变
                                                               读取返回当前挂起状态
                                                               参考：Interrupt Clear-Pending Registers, NVIC_ICPR0-NVIC_ICPR15 on page B3-629
                                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_NVIC_IABR(n)        (0x200 + (n) * 0x04)  /* Interrupt Active Bit Register n (n=0-15)
                                                               中断活跃位寄存器 n [RO]
                                                               指示当前正在服务的中断
                                                               只读寄存器，硬件在中断入口时置位，中断返回时清零
                                                               位 m=1: 中断 m 正在活跃；位 m=0: 中断 m 不活跃
                                                               用于调试和多中断优先级管理
                                                               参考：Interrupt Active Bit Registers, NVIC_IABR0-NVIC_IABR15 on page B3-630
                                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_NVIC_IPR(n)         (0x300 + (n) * 0x04)  /* Interrupt Priority Register n (n=0-123)
                                                               中断优先级寄存器 n [RW]
                                                               每个 IPR 寄存器包含 4 个中断的优先级
                                                               优先级 n: 位[7:0] = 中断 4n，位[15:8] = 中断 4n+1
                                                               位[23:16] = 中断 4n+2，位[31:24] = 中断 4n+3
                                                               优先级值越小优先级越高
                                                               实现的优先级位数取决于处理器 (通常 3-8 位)
                                                               参考：Interrupt Priority Registers, NVIC_IPR0-NVIC_IPR123 on page B3-630
                                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

/* -----------------------------------------------------------------------------
 * 3.5 内存保护单元 (MPU) 寄存器
 * 参考: Table D8-2 Memory-mapped System register index on page D8-844
 * 地址范围: 0xE000ED90 - 0xE000ED9F
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_MPU_BASE            0xE000ED90UL

#define ARM_V7M_MPU_TYPE            0x000   /* MPU Type Register - MPU 类型寄存器 [RO]
                                               提供 MPU 的信息
                                               包含指令区域数量 (IREGION): RAZ，Armv7-M 仅支持统一 MPU
                                               包含数据区域数量 (DREGION): 支持的 MPU 区域数，0=无 MPU
                                               包含分离标志 (SEPARATE): RAZ，Armv7-M 仅支持统一 MPU
                                               只读寄存器，用于确定是否实现了 MPU 及支持的区域数
                                               参考：MPU Type Register, MPU_TYPE on page B3-636
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_MPU_CTRL            0x004   /* MPU Control Register - MPU 控制寄存器 [RW]
                                               控制 MPU 的操作
                                               包含特权默认使能位 (PRIVDEFENA): 1=启用默认内存映射为特权级背景区域
                                               包含硬故障和 NMI 使能位 (HFNMIENA): 1=在 HardFault/NMI 中启用 MPU
                                               包含使能位 (ENABLE): 1=MPU 启用，0=MPU 禁用
                                               禁用 MPU 时使用默认内存映射
                                               参考：MPU Control Register, MPU_CTRL on page B3-637
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_MPU_RNR             0x008   /* MPU Region Number Register - MPU 区域编号寄存器 [RW]
                                               选择由 MPU_RBAR 和 MPU_RASR 引用的 MPU 区域
                                               位[7:0] 选择当前区域号 0-(N-1)，N 是 MPU_TYPE.DREGION
                                               配合 MPU_RBAR 和 MPU_RASR 使用
                                               也可通过 MPU_RBAR.VALID 位在写入 RBAR 时更新区域号
                                               参考：MPU Region Number Register, MPU_RNR on page B3-638
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_MPU_RBAR            0x00C   /* MPU Region Base Address Register - MPU 区域基地址寄存器 [RW]
                                               定义 MPU_RNR 选择的 MPU 区域的基地址
                                               位[31:5] 是区域基地址，必须按区域大小对齐
                                               位[4] 是有效标志 (VALID): 1=使用本寄存器的区域号，0=使用 MPU_RNR
                                               位[3:0] 是区域号 (当 VALID=1 时)
                                               可用于查询最小支持的区域大小
                                               参考：MPU Region Base Address Register, MPU_RBAR on page B3-639
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_MPU_RASR            0x010   /* MPU Region Attribute and Size Register - MPU 区域属性和大小寄存器 [RW]
                                               定义 MPU_RNR 选择的 MPU 区域的属性和大小
                                               位[31:16] 是属性字段 (ATTRS): 包含 XN、AP、TEX、S、C、B 子字段
                                               位[15:8] 是子区域禁用 (SRD): 每一位控制一个 1/8 子区域的启用
                                               位[5:1] 是大小 (SIZE): 区域大小 = 2^(SIZE+1) 字节
                                               位[0] 是使能 (ENABLE): 1=区域启用
                                               用于配置内存保护区域的访问权限和属性
                                               参考：MPU Region Attribute and Size Register, MPU_RASR on page B3-640
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844
                                               【v7m 独有】v8m 中使用 MPU_RLAR 替代此寄存器 */

/*
 * MPU 别名寄存器 (Alias Registers)
 * 参考: Table B3-11 MPU register summary on page B3-635
 * 这些别名允许在单次写操作中同时更新区域号和基地址/属性
 */
#define ARM_V7M_MPU_RBAR_A1         0x014   /* MPU Region Base Address Register Alias 1 - MPU 区域基地址寄存器别名 1 [RW]
                                               地址: 0xE000EDA4
                                               MPU_RBAR 的别名，用于快速切换区域
                                               写入时可直接指定区域号，无需先写 MPU_RNR
                                               参考：MPU alias register support on page B3-642
                                               备注：Table B3-11 MPU register summary on page B3-635 */

#define ARM_V7M_MPU_RASR_A1         0x018   /* MPU Region Attribute and Size Register Alias 1 - MPU 区域属性和大小寄存器别名 1 [RW]
                                               地址: 0xE000EDA8
                                               MPU_RASR 的别名
                                               参考：MPU alias register support on page B3-642
                                               备注：Table B3-11 MPU register summary on page B3-635
                                               【v7m 独有】v8m 中使用 MPU_RLAR_A1 替代 */

#define ARM_V7M_MPU_RBAR_A2         0x01C   /* MPU Region Base Address Register Alias 2 - MPU 区域基地址寄存器别名 2 [RW]
                                               地址: 0xE000EDAC
                                               MPU_RBAR 的别名，用于快速切换区域
                                               参考：MPU alias register support on page B3-642
                                               备注：Table B3-11 MPU register summary on page B3-635 */

#define ARM_V7M_MPU_RASR_A2         0x020   /* MPU Region Attribute and Size Register Alias 2 - MPU 区域属性和大小寄存器别名 2 [RW]
                                               地址: 0xE000EDB0
                                               MPU_RASR 的别名
                                               参考：MPU alias register support on page B3-642
                                               备注：Table B3-11 MPU register summary on page B3-635
                                               【v7m 独有】v8m 中使用 MPU_RLAR_A2 替代 */

#define ARM_V7M_MPU_RBAR_A3         0x024   /* MPU Region Base Address Register Alias 3 - MPU 区域基地址寄存器别名 3 [RW]
                                               地址: 0xE000EDB4
                                               MPU_RBAR 的别名，用于快速切换区域
                                               参考：MPU alias register support on page B3-642
                                               备注：Table B3-11 MPU register summary on page B3-635 */

#define ARM_V7M_MPU_RASR_A3         0x028   /* MPU Region Attribute and Size Register Alias 3 - MPU 区域属性和大小寄存器别名 3 [RW]
                                               地址: 0xE000EDB8
                                               MPU_RASR 的别名
                                               参考：MPU alias register support on page B3-642
                                               备注：Table B3-11 MPU register summary on page B3-635
                                               【v7m 独有】v8m 中使用 MPU_RLAR_A3 替代 */

/* -----------------------------------------------------------------------------
 * 3.6 缓存和分支预测维护操作寄存器
 * 参考: Table D8-2 Memory-mapped System register index on page D8-844
 * 地址范围: 0xE000EF50 - 0xE000EFFF
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CACHE_BASE          0xE000EF50UL

#define ARM_V7M_ICIALLU             0x000   /* Instruction Cache Invalidate All to PoU - 指令缓存全部无效化到 PoU [WO]
                                               地址: 0xE000EF50
                                               将所有指令缓存无效化到统一点 (PoU)
                                               仅写操作，写入值被忽略
                                               确保指令流与内存一致
                                               必须在修改指令内存后执行
                                               参考：Cache and branch predictor maintenance operations on page B2-577
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_ICIMVAU             0x008   /* Instruction Cache Invalidate by MVA to PoU - 按 MVA 指令缓存无效化到 PoU [WO]
                                               地址: 0xE000EF58
                                               按修改虚拟地址 (MVA) 将指令缓存行无效化到统一点 (PoU)
                                               仅写操作，写入地址
                                               用于精确无效化特定地址的指令缓存
                                               参考：Cache and branch predictor maintenance operations on page B2-577
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_DCIMVAC             0x00C   /* Data Cache Invalidate by MVA to PoC - 按 MVA 数据缓存无效化到 PoC [WO]
                                               地址: 0xE000EF5C
                                               按修改虚拟地址 (MVA) 将数据缓存行无效化到一致点 (PoC)
                                               仅写操作，写入地址
                                               用于在外部代理修改内存后使缓存无效
                                               参考：Cache and branch predictor maintenance operations on page B2-577
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_DCISW               0x010   /* Data Cache Invalidate by Set/Way - 按组/路数据缓存无效化 [WO]
                                               地址: 0xE000EF60
                                               按组/路方式将数据缓存行无效化
                                               仅写操作，写入组/路标识符
                                               用于低级缓存管理
                                               参考：Cache and branch predictor maintenance operations on page B2-577
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_DCCMVAU             0x014   /* Data Cache Clean by MVA to PoU - 按 MVA 数据缓存清理到 PoU [WO]
                                               地址: 0xE000EF64
                                               按修改虚拟地址 (MVA) 将数据缓存行清理到统一点 (PoU)
                                               仅写操作，写入地址
                                               清理操作将脏数据写回到统一点
                                               用于确保数据写入到统一点
                                               参考：Cache and branch predictor maintenance operations on page B2-577
                                               备注：Table B2-1 on page B2-579 */

#define ARM_V7M_DCCMVAC             0x018   /* Data Cache Clean by MVA to PoC - 按 MVA 数据缓存清理到 PoC [WO]
                                               地址: 0xE000EF68
                                               按修改虚拟地址 (MVA) 将数据缓存行清理到一致点 (PoC)
                                               仅写操作，写入地址
                                               清理操作将脏数据写回内存
                                               用于确保数据写入内存后再修改
                                               参考：Cache and branch predictor maintenance operations on page B2-577
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_DCCSW               0x01C   /* Data Cache Clean by Set/Way - 按组/路数据缓存清理 [WO]
                                               地址: 0xE000EF6C
                                               按组/路方式将数据缓存行清理
                                               仅写操作，写入组/路标识符
                                               用于低级缓存管理
                                               参考：Cache and branch predictor maintenance operations on page B2-577
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_DCCIMVAC            0x020   /* Data Cache Clean and Invalidate by MVA to PoC - 按 MVA 数据缓存清理并无效化到 PoC [WO]
                                               地址: 0xE000EF70
                                               按修改虚拟地址 (MVA) 将数据缓存行清理并无效化到一致点 (PoC)
                                               仅写操作，写入地址
                                               同时执行清理和无效化操作
                                               用于 DMA 操作前的准备
                                               参考：Cache and branch predictor maintenance operations on page B2-577
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_DCCISW              0x024   /* Data Cache Clean and Invalidate by Set/Way - 按组/路数据缓存清理并无效化 [WO]
                                               地址: 0xE000EF74
                                               按组/路方式将数据缓存行清理并无效化
                                               仅写操作，写入组/路标识符
                                               用于低级缓存管理
                                               参考：Cache and branch predictor maintenance operations on page B2-577
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

#define ARM_V7M_BPIALL              0x028   /* Branch Predictor Invalidate All - 分支预测器全部无效化 [WO]
                                               地址: 0xE000EF78
                                               将所有分支预测器条目无效化
                                               仅写操作，写入值被忽略
                                               确保分支预测器与新的指令流一致
                                               必须在修改指令内存后执行
                                               参考：Cache and branch predictor maintenance operations on page B2-577
                                               备注：Table D8-2 Memory-mapped System register index on page D8-844 */

/* ==============================================================================
 * 四、内存映射调试寄存器 (Memory-mapped Debug Registers)
 * 参考：D8.4 Memory-mapped debug registers on page D8-846
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 4.0 CPUID 方案寄存器补充 (CPUID Scheme Registers - Continued)
 * 参考：Chapter B4 The CPUID Scheme on page B4-644
 *       Table D8-2 Memory-mapped System register index on page D8-844
 * 这些寄存器位于 SCB 空间，但在上面的 3.1 节之后列出以保持组织清晰
 * -----------------------------------------------------------------------------
 */

/* 处理器特性标识寄存器 (Processor Feature ID Registers)
 * 参考：B4.2 Processor Feature ID Registers on page B4-646
 * 地址：0xE000ED40 - 0xE000ED44 (SCB 基地址 + 0x040 - 0x044)
 */
#define ARM_V7M_SCB_ID_PFR0         0x040   /* Processor Feature Register 0 - 处理器特性寄存器 0 [RO]
                                               提供处理器特性信息，包括架构版本和指令集支持
                                               位[7:4]: ARM 架构版本 (0001=Armv6, 0010=Armv7)
                                               位[3:0]: Thumb 支持 (0010=支持 Thumb-2 和 16 位编码)
                                               只读寄存器，用于识别处理器架构能力
                                               参考：Processor Feature Register 0, ID_PFR0 on page B4-646
                                               备注：D8.3 Memory mapped System registers on page D8-844, B4.2 on page B4-646 */

#define ARM_V7M_SCB_ID_PFR1         0x044   /* Processor Feature Register 1 - 处理器特性寄存器 1 [RO]
                                               提供额外的处理器特性信息
                                               位[3:0]: 通用定时器支持
                                               只读寄存器，用于识别高级特性
                                               参考：Processor Feature Register 1, ID_PFR1 on page B4-646
                                               备注：D8.3 Memory mapped System registers on page D8-844, B4.2 on page B4-646 */

/* 调试特性标识寄存器 (Debug Feature ID Register)
 * 参考：B4.3 Debug Feature ID register on page B4-648
 * 地址：0xE000ED48 (SCB 基地址 + 0x048)
 */
#define ARM_V7M_SCB_ID_DFR0         0x048   /* Debug Feature Register 0 - 调试特性寄存器 0 [RO]
                                               提供调试系统的特性信息
                                               位[31:28]: 协处理器调试
                                               位[27:24]: 安全/非安全调试
                                               位[23:20]: 外部调试
                                               只读寄存器，用于识别调试能力
                                               参考：Debug Feature Register 0, ID_DFR0 on page B4-648
                                               备注：D8.3 Memory mapped System registers on page D8-844, B4.3 on page B4-648 */

/* 辅助特性标识寄存器 (Auxiliary Feature ID Register)
 * 参考：B4.4 Auxiliary Feature ID register on page B4-649
 * 地址：0xE000ED4C (SCB 基地址 + 0x04C)
 */
#define ARM_V7M_SCB_ID_AFR0         0x04C   /* Auxiliary Feature Register 0 - 辅助特性寄存器 0 [RO]
                                               提供额外的特性信息
                                               位[3:0]: 内存保护 (0000=无 MPU, 0001=实现了 MPU)
                                               只读寄存器，用于识别可选特性
                                               参考：Auxiliary Feature Register 0, ID_AFR0 on page B4-649
                                               备注：D8.3 Memory mapped System registers on page D8-844, B4.4 on page B4-649 */

/* 内存模型特性标识寄存器 (Memory Model Feature Registers)
 * 参考：B4.5 Memory Model Feature Registers on page B4-650
 * 地址：0xE000ED50 - 0xE000ED5C (SCB 基地址 + 0x050 - 0x05C)
 */
#define ARM_V7M_SCB_ID_MMFR0        0x050   /* Memory Model Feature Register 0 - 内存模型特性寄存器 0 [RO]
                                               提供内存模型的特性信息
                                               位[7:4]: TCM (0000=无 TCM, 0001=实现了 TCM)
                                               位[3:0]: 共享性 (0000=不支持共享, 0001=支持共享)
                                               只读寄存器，用于识别内存系统能力
                                               参考：Memory Model Feature Register 0, ID_MMFR0 on page B4-650
                                               备注：D8.3 Memory mapped System registers on page D8-844, B4.5 on page B4-650 */

#define ARM_V7M_SCB_ID_MMFR1        0x054   /* Memory Model Feature Register 1 - 内存模型特性寄存器 1 [RO]
                                               提供缓存系统的特性信息
                                               位[7:4]: L1 统一缓存 (0000=无 L1 统一缓存, 0001=有 L1 统一缓存)
                                               位[3:0]: L1 哈佛架构 (0000=无 L1 哈佛, 0001=有 L1 哈佛)
                                               只读寄存器，用于识别缓存配置
                                               参考：Memory Model Feature Register 1, ID_MMFR1 on page B4-651
                                               备注：D8.3 Memory mapped System registers on page D8-844, B4.5 on page B4-650 */

#define ARM_V7M_SCB_ID_MMFR2        0x058   /* Memory Model Feature Register 2 - 内存模型特性寄存器 2 [RO]
                                               提供分支预测和缓存维护的特性信息
                                               位[7:4]: 分支预测 (0000=无分支预测, 0001=实现了分支预测)
                                               位[3:0]: 缓存维护 (0000=无缓存维护, 0001=有缓存维护)
                                               只读寄存器，用于识别高级内存特性
                                               参考：Memory Model Feature Register 2, ID_MMFR2 on page B4-651
                                               备注：D8.3 Memory mapped System registers on page D8-844, B4.5 on page B4-650 */

#define ARM_V7M_SCB_ID_MMFR3        0x05C   /* Memory Model Feature Register 3 - 内存模型特性寄存器 3 [RO]
                                               提供额外的内存模型特性信息
                                               位[3:0]: CMOW (0000=不支持 CMOW, 0001=支持 CMOW)
                                               只读寄存器，用于识别特殊内存特性
                                               参考：Memory Model Feature Register 3, ID_MMFR3 on page B4-652
                                               备注：D8.3 Memory mapped System registers on page D8-844, B4.5 on page B4-650 */

/* 指令集属性标识寄存器 (Instruction Set Attribute Registers)
 * 参考：B4.6 Instruction Set Attribute Registers on page B4-653
 * 地址：0xE000ED60 - 0xE000ED70 (SCB 基地址 + 0x060 - 0x070)
 */
#define ARM_V7M_SCB_ID_ISAR0        0x060   /* Instruction Set Attribute Register 0 - 指令集属性寄存器 0 [RO]
                                               提供指令集特性信息
                                               位[31:28]: 除法指令 (0000=无除法, 0001=Thumb 中有除法)
                                               位[27:24]: 乘法指令 (0001=Thumb 中有乘法)
                                               位[7:4]: 位域指令 (0001=Thumb 中有位域)
                                               只读寄存器，用于识别指令集能力
                                               参考：Instruction Set Attribute Register 0, ID_ISAR0 on page B4-654
                                               备注：D8.3 Memory mapped System registers on page D8-844, B4.6 on page B4-653 */

#define ARM_V7M_SCB_ID_ISAR1        0x064   /* Instruction Set Attribute Register 1 - 指令集属性寄存器 1 [RO]
                                               提供额外的指令集特性信息
                                               位[7:4]: 16 位乘法 (0001=Thumb 中有 16 位乘法)
                                               位[3:0]: 位域 (0001=Thumb 中有位域)
                                               只读寄存器，用于识别更多指令集特性
                                               参考：Instruction Set Attribute Register 1, ID_ISAR1 on page B4-655
                                               备注：D8.3 Memory mapped System registers on page D8-844, B4.6 on page B4-653 */

#define ARM_V7M_SCB_ID_ISAR2        0x068   /* Instruction Set Attribute Register 2 - 指令集属性寄存器 2 [RO]
                                               提供协处理器和加载/存储指令的特性信息
                                               位[11:8]: 协处理器 (0000=无协处理器, 0010=有协处理器指令)
                                               位[7:4]: 加载/存储 (0001=有加载/存储独占)
                                               只读寄存器，用于识别高级内存访问指令
                                               参考：Instruction Set Attribute Register 2, ID_ISAR2 on page B4-657
                                               备注：D8.3 Memory mapped System registers on page D8-844, B4.6 on page B4-653 */

#define ARM_V7M_SCB_ID_ISAR3        0x06C   /* Instruction Set Attribute Register 3 - 指令集属性寄存器 3 [RO]
                                               提供多加载/存储和饱和指令的特性信息
                                               位[11:8]: 多加载/存储 (0001=有多加载/存储)
                                               位[7:4]: 饱和 (0001=有饱和指令)
                                               只读寄存器，用于识别特殊指令集特性
                                               参考：Instruction Set Attribute Register 3, ID_ISAR3 on page B4-658
                                               备注：D8.3 Memory mapped System registers on page D8-844, B4.6 on page B4-653 */

#define ARM_V7M_SCB_ID_ISAR4        0x070   /* Instruction Set Attribute Register 4 - 指令集属性寄存器 4 [RO]
                                               提供屏障和同步指令的特性信息
                                               位[11:8]: 屏障指令 (0001=有屏障指令)
                                               位[3:0]: 同步 (0001=有同步原语)
                                               只读寄存器，用于识别多处理器支持指令
                                               参考：Instruction Set Attribute Register 4, ID_ISAR4 on page B4-659
                                               备注：D8.3 Memory mapped System registers on page D8-844, B4.6 on page B4-653 */

#define ARM_V7M_SCB_ID_ISAR5        0x074   /* Instruction Set Attribute Register 5 - 指令集属性寄存器 5 [RO]
                                               地址: 0xE000ED74
                                               保留寄存器，读取为 0 (RAZ)
                                               用于未来扩展指令集属性
                                               只读寄存器
                                               参考：ID_ISAR5: Reserved, RAZ on page B4-644
                                               备注：Table B4-1 Processor Feature ID register support in the SCS on page B4-644 */

/* 缓存控制标识寄存器 (Cache Control Identification Registers)
 * 参考：B4.8 Cache Control Identification Registers on page B4-665
 * 地址：0xE000ED78 - 0xE000ED84 (SCB 基地址 + 0x078 - 0x084)
 * 备注：仅当实现缓存控制时存在
 */
#define ARM_V7M_SCB_CLIDR           0x078   /* Cache Level ID Register - 缓存级别标识寄存器 [RO]
                                               地址: 0xE000ED78
                                               提供缓存层次结构信息
                                               位[6:4]: L1 缓存类型 (000=无缓存, 001=仅指令, 010=仅数据, 011=统一)
                                               位[3:1]: L0 缓存类型
                                               只读寄存器，用于识别缓存架构
                                               参考：Cache Level ID Register, CLIDR on page B4-665
                                               备注：Table B4-1 on page B4-644 */

#define ARM_V7M_SCB_CTR             0x07C   /* Cache Type Register - 缓存类型寄存器 [RO]
                                               地址: 0xE000ED7C
                                               提供缓存策略和行大小信息
                                               位[31:28]: 格式 (0000=Armv8 缓存类型信息)
                                               位[19:16]: DminLine (数据缓存最小行大小，以字为单位)
                                               位[15:12]: IminLine (指令缓存最小行大小，以字为单位)
                                               只读寄存器，用于确定缓存参数
                                               参考：Cache Type Register, CTR on page B4-666
                                               备注：Table B4-1 on page B4-644 */

#define ARM_V7M_SCB_CCSIDR          0x080   /* Current Cache Size ID Register - 当前缓存大小标识寄存器 [RO]
                                               地址: 0xE000ED80
                                               提供当前选择缓存的大小信息
                                               位[31:28]: NumSets (缓存中的组数)
                                               位[27:13]: 相联度 (缓存的相联度)
                                               位[12:3]: 行大小 (行大小以字为单位，2^(行大小+2))
                                               只读寄存器，与 CSSELR 配合使用
                                               参考：Current Cache Size ID Register, CCSIDR on page B4-667
                                               备注：Table B4-1 on page B4-644 */

#define ARM_V7M_SCB_CSSELR          0x084   /* Cache Size Selection Register - 缓存大小选择寄存器 [RW]
                                               地址: 0xE000ED84
                                               选择 CCSIDR 访问的缓存级别
                                               位[2:1]: 缓存级别 (00=L0, 01=L1, 等)
                                               位[0]: 缓存类型 (0=数据缓存, 1=指令缓存)
                                               用于选择要查询的缓存
                                               参考：Cache Size Selection Register, CSSELR on page B4-668
                                               备注：Table B4-1 on page B4-644 */

/* -----------------------------------------------------------------------------
 * 4.0a 外设和组件标识寄存器 (Peripheral and Component ID Registers)
 * 参考：Table B3-6 Summary of system control and ID registers not in the SCB
 * 地址范围: 0xE000EFD0 - 0xE000EFFF
 * -----------------------------------------------------------------------------
 */

/* Peripheral Identification Registers */
#define ARM_V7M_SCB_PID4            0xFD0   /* Peripheral ID Register 4 - 外设标识寄存器 4 [RO]
                                               地址: 0xE000EFD0
                                               包含外设标识信息，用于 CoreSight 组件识别
                                               位[7:4]: 4KB 计数 (0x4=16KB 地址空间)
                                               位[3:0]: JEP106 继续代码
                                               只读寄存器，复位值由实现定义
                                               参考：Peripheral Identification Registers on page B4-669
                                               备注：Table B3-6 on page B3-597 */

#define ARM_V7M_SCB_PID5            0xFD4   /* Peripheral ID Register 5 - 外设标识寄存器 5 [RO]
                                               地址: 0xE000EFD4
                                               保留用于未来扩展
                                               只读寄存器
                                               参考：Peripheral Identification Registers on page B4-669
                                               备注：Table B3-6 on page B3-597 */

#define ARM_V7M_SCB_PID6            0xFD8   /* Peripheral ID Register 6 - 外设标识寄存器 6 [RO]
                                               地址: 0xE000EFD8
                                               保留用于未来扩展
                                               只读寄存器
                                               参考：Peripheral Identification Registers on page B4-669
                                               备注：Table B3-6 on page B3-597 */

#define ARM_V7M_SCB_PID7            0xFDC   /* Peripheral ID Register 7 - 外设标识寄存器 7 [RO]
                                               地址: 0xE000EFDC
                                               保留用于未来扩展
                                               只读寄存器
                                               参考：Peripheral Identification Registers on page B4-669
                                               备注：Table B3-6 on page B3-597 */

#define ARM_V7M_SCB_PID0            0xFE0   /* Peripheral ID Register 0 - 外设标识寄存器 0 [RO]
                                               地址: 0xE000EFE0
                                               位[7:0]: 零件号 [7:0]
                                               用于标识组件类型
                                               只读寄存器，复位值由实现定义
                                               参考：Peripheral Identification Registers on page B4-669
                                               备注：Table B3-6 on page B3-597 */

#define ARM_V7M_SCB_PID1            0xFE4   /* Peripheral ID Register 1 - 外设标识寄存器 1 [RO]
                                               地址: 0xE000EFE4
                                               位[7:4]: JEP106 ID 代码 [3:0]
                                               位[3:0]: 零件号 [11:8]
                                               只读寄存器，复位值由实现定义
                                               参考：Peripheral Identification Registers on page B4-669
                                               备注：Table B3-6 on page B3-597 */

#define ARM_V7M_SCB_PID2            0xFE8   /* Peripheral ID Register 2 - 外设标识寄存器 2 [RO]
                                               地址: 0xE000EFE8
                                               位[7:4]: 修订版本号
                                               位[3]: JEP106 代码使用标志 (1=使用 JEP106)
                                               位[2:0]: JEP106 ID 代码 [6:4]
                                               只读寄存器，复位值由实现定义
                                               参考：Peripheral Identification Registers on page B4-669
                                               备注：Table B3-6 on page B3-597 */

#define ARM_V7M_SCB_PID3            0xFEC   /* Peripheral ID Register 3 - 外设标识寄存器 3 [RO]
                                               地址: 0xE000EFEC
                                               位[7:4]: 工程变更 (ECO) 编号
                                               位[3:0]: 客户修改编号
                                               只读寄存器，复位值由实现定义
                                               参考：Peripheral Identification Registers on page B4-669
                                               备注：Table B3-6 on page B3-597 */

/* Component Identification Registers */
#define ARM_V7M_SCB_CID0            0xFF0   /* Component ID Register 0 - 组件标识寄存器 0 [RO]
                                               地址: 0xE000EFF0
                                               位[7:0]: 固定值 0x0D，标识组件类型为 SCS
                                               只读寄存器
                                               参考：Component Identification Registers on page B4-670
                                               备注：Table B3-6 on page B3-597 */

#define ARM_V7M_SCB_CID1            0xFF4   /* Component ID Register 1 - 组件标识寄存器 1 [RO]
                                               地址: 0xE000EFF4
                                               位[7:4]: 组件类 (0x1=ARM 组件)
                                               位[3:0]: 固定值 0x00
                                               只读寄存器
                                               参考：Component Identification Registers on page B4-670
                                               备注：Table B3-6 on page B3-597 */

#define ARM_V7M_SCB_CID2            0xFF8   /* Component ID Register 2 - 组件标识寄存器 2 [RO]
                                               地址: 0xE000EFF8
                                               位[7:0]: 固定值 0x05
                                               只读寄存器
                                               参考：Component Identification Registers on page B4-670
                                               备注：Table B3-6 on page B3-597 */

#define ARM_V7M_SCB_CID3            0xFFC   /* Component ID Register 3 - 组件标识寄存器 3 [RO]
                                               地址: 0xE000EFFC
                                               位[7:0]: 固定值 0xB1
                                               只读寄存器
                                               参考：Component Identification Registers on page B4-670
                                               备注：Table B3-6 on page B3-597 */

/* -----------------------------------------------------------------------------
 * 4.1 调试硬件 (DHCSR, DCRSR, DCRDR, DEMCR)
 * 参考: Table D8-3 Memory-mapped debug register index on page D8-847
 * 地址范围: 0xE000EDF0 - 0xE000EDFF
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_DEBUG_BASE          0xE000EDF0UL

#define ARM_V7M_DEBUG_DHCSR         0x000   /* Debug Halting Control and Status Register - 调试暂停控制和状态寄存器 [RW]
                                               控制并提供暂停调试的状态
                                               包含调试使能位 (C_DEBUGEN): 1=使能调试
                                               包含暂停位 (C_HALT): 1=请求暂停
                                               包含单步位 (C_STEP): 1=单步执行
                                               包含状态位 (S_HALT, S_REGRDY, S_RESET_ST)
                                               仅调试器可访问，用于控制处理器暂停调试
                                               参考: Debug Halting Control and Status Register, DHCSR on page C1-700
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

#define ARM_V7M_DEBUG_DCRSR         0x004   /* Debug Core Register Selector Register - 调试核心寄存器选择寄存器 [WO]
                                               选择通过 DCRDR 传输的寄存器
                                               位[16]: REGWnR: 0=读, 1=写
                                               位[6:0]: REGSEL: 寄存器选择编码
                                               配合 DCRDR 用于读写核心寄存器
                                               仅调试器可访问
                                               参考: Debug Core Register Selector Register, DCRSR on page C1-703
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

#define ARM_V7M_DEBUG_DCRDR         0x008   /* Debug Core Register Data Register - 调试核心寄存器数据寄存器 [RW]
                                               保存与核心寄存器传输的数据
                                               通过 DCRSR 选择要访问的寄存器
                                               写入数据用于寄存器写操作
                                               读取数据用于寄存器读操作
                                               仅调试器可访问，用于核心寄存器访问
                                               参考: Debug Core Register Data Register, DCRDR on page C1-704
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

#define ARM_V7M_DEBUG_DEMCR         0x00C   /* Debug Exception and Monitor Control Register - 调试异常和监视器控制寄存器 [RW]
                                               使能或禁用暂停调试特性
                                               包含 DWT 使能位 (TRCENA): 1=使能 DWT 和 ITM
                                               包含监视点使能位 (MON_EN)
                                               包含异常调试使能位 (VC_HARDERR, VC_INTERR, 等)
                                               用于配置调试异常行为
                                               参考: Debug Exception and Monitor Control Register, DEMCR on page C1-706
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

/* -----------------------------------------------------------------------------
 * 4.2 数据观察点和跟踪单元 (DWT)
 * 参考: Table D8-3 Memory-mapped debug register index on page D8-847
 * 地址范围: 0xE0001000 - 0xE0001FFF
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_DWT_BASE            0xE0001000UL

/* -----------------------------------------------------------------------------
 * DWT 寄存器组通用宏 (使用示例: ARM_V7M_DWT_COMP(n), n = 0-3)
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_DWT_COMP(n)      (0x020 + (n) * 0x10)  /* Comparator Register n (n=0-3) - 比较器寄存器 n [RW]
                                                           保存比较器 n 的比较值
                                                           用于数据观察点和地址比较
                                                           配合 MASK 和 FUNCTION 寄存器使用
                                                           参考: Comparator registers, DWT_COMPn on page C1-745
                                                           备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

#define ARM_V7M_DWT_MASK(n)      (0x024 + (n) * 0x10)  /* Comparator Mask Register n (n=0-3) - 比较器掩码寄存器 n [RW]
                                                           保存比较器 n 的地址掩码
                                                           控制比较时忽略的地址位
                                                           位[4:0]: MASK: 0=无掩码, 1-31=掩码位数
                                                           参考: Comparator Mask registers, DWT_MASKn on page C1-745
                                                           备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

#define ARM_V7M_DWT_FUNCTION(n)  (0x028 + (n) * 0x10)  /* Comparator Function Register n (n=0-3) - 比较器功能寄存器 n [RW]
                                                           配置比较器 n 的功能
                                                           位[24:16]: DATAVADDR: 数据访问地址匹配
                                                           位[11:8]: DATAVSIZE: 数据访问大小匹配
                                                           位[5:4]: EMITRANGE: 发出范围事件
                                                           位[3:0]: FUNCTION: 比较器功能选择
                                                           用于配置数据观察点行为
                                                           参考: Comparator Function registers, DWT_FUNCTIONn on page C1-746
                                                           备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

#define ARM_V7M_DWT_CTRL            0x000   /* Control Register - 控制寄存器 [RW]
                                               使能或禁用 DWT 特性
                                               位[28]: NOPRFCNT: 禁用性能计数器
                                               位[25]: CYCCNTENA: 使能周期计数器
                                               位[24]: EXCTRCENA: 使能异常跟踪
                                               位[22]: PCSAMPLENA: 使能 PC 采样
                                               位[21]: SYNCTAP: 同步数据包选择
                                               位[20]: POSTINIT: 后分频计数器初始化值
                                               位[19:16]: POSTPRESET: 后分频计数器预设值
                                               位[11:8]: CYCTAP: 周期计数器选择
                                               用于配置 DWT 的主要功能
                                               参考: Control register, DWT_CTRL on page C1-737
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

#define ARM_V7M_DWT_CYCCNT          0x004   /* Cycle Count register - 周期计数寄存器 [RW]
                                               统计执行的周期数
                                               32 位自由运行计数器
                                               每个周期递增 1
                                               可用于性能测量和时间统计
                                               需要在 CTRL 中使能 CYCCNTENA
                                               参考: Cycle Count register, DWT_CYCCNT on page C1-741
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

#define ARM_V7M_DWT_CPICNT          0x008   /* CPI Count register - CPI 计数寄存器 [RW]
                                               统计多周期指令的执行次数
                                               8 位计数器，溢出时回绕
                                               每个多周期指令执行时递增
                                               用于性能分析
                                               参考: CPI Count register, DWT_CPICNT on page C1-741
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

#define ARM_V7M_DWT_EXCCNT          0x00C   /* Exception Overhead Count register - 异常开销计数寄存器 [RW]
                                               统计异常开销的周期数
                                               8 位计数器，溢出时回绕
                                               统计进入和退出异常的周期数
                                               用于分析异常处理开销
                                               参考: Exception Overhead Count register, DWT_EXCCNT on page C1-742
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

#define ARM_V7M_DWT_SLEEPCNT        0x010   /* Sleep Count register - 睡眠计数寄存器 [RW]
                                               统计处理器处于睡眠状态的周期数
                                               8 位计数器，溢出时回绕
                                               每个睡眠周期递增
                                               用于电源管理分析
                                               参考: Sleep Count register, DWT_SLEEPCNT on page C1-742
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

#define ARM_V7M_DWT_LSUCNT          0x014   /* LSU Count register - LSU 计数寄存器 [RW]
                                               统计加载/存储指令的执行次数
                                               8 位计数器，溢出时回绕
                                               每个加载或存储指令执行时递增
                                               用于内存访问分析
                                               参考: LSU Count register, DWT_LSUCNT on page C1-743
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

#define ARM_V7M_DWT_FOLDCNT         0x018   /* Folded-instruction Count register - 折叠指令计数寄存器 [RW]
                                               统计折叠指令的执行次数
                                               8 位计数器，溢出时回绕
                                               每个折叠指令执行时递增
                                               用于流水线效率分析
                                               参考: Folded-instruction Count register, DWT_FOLDCNT on page C1-744
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

#define ARM_V7M_DWT_PCSR            0x01C   /* Program Counter Sample Register - 程序计数器采样寄存器 [RO]
                                               保存采样的 PC 值
                                               定期采样当前 PC 值
                                               用于程序执行分析
                                               需要在 CTRL 中使能 PCSAMPLENA
                                               参考: Program Counter Sample Register, DWT_PCSR on page C1-745
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

/* DWT CoreSight 软件锁定寄存器 (可选)
 * 参考: Table D1-2 CoreSight Software Lock registers on page D1-767
 * 地址范围: 0xE0001FB0 - 0xE0001FB4
 */
#define ARM_V7M_DWT_LAR             0xFB0   /* DWT Lock Access Register - DWT 锁定访问寄存器 [WO]
                                               地址: 0xE0001FB0
                                               CoreSight 软件锁定访问寄存器
                                               写入 0xC5ACCE55 解锁寄存器访问
                                               读取返回 UNKNOWN
                                               用于保护 DWT 寄存器不被意外修改
                                               参考: Table D1-2 CoreSight Software Lock registers on page D1-767
                                               备注: 可选实现，未实现时读取为 UNKNOWN */

#define ARM_V7M_DWT_LSR             0xFB4   /* DWT Lock Status Register - DWT 锁定状态寄存器 [RO]
                                               地址: 0xE0001FB4
                                               CoreSight 软件锁定状态寄存器
                                               指示当前锁定状态
                                               位[1]: LOCKED: 1=已锁定, 0=未锁定
                                               位[0]: PRESENT: 1=实现锁定功能, 0=未实现
                                               未实现时读取为 0 (RAZ)
                                               参考: Table D1-2 CoreSight Software Lock registers on page D1-767
                                               备注: 可选实现，未实现时读取为 RAZ */

/* -----------------------------------------------------------------------------
 * 4.3 仪器化跟踪宏单元 (ITM)
 * 参考: Table D8-3 Memory-mapped debug register index on page D8-847
 * 地址范围: 0xE0000000 - 0xE0000FFF
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_ITM_BASE            0xE0000000UL

/* -----------------------------------------------------------------------------
 * ITM 寄存器组通用宏 (使用示例: ARM_V7M_ITM_STIM(n), n = 0-255; ARM_V7M_ITM_TER(n), n = 0-7)
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_ITM_STIM(n)      ((n) * 0x04)  /* Stimulus Port Register n (n=0-255) - 激励端口寄存器 n [RW]
                                                                   用于向 ITM 发送跟踪数据
                                                                   256 个激励端口，每端口 4 字节
                                                                   写入数据到激励端口生成 ITM 数据包
                                                                   读取返回 FIFO 状态：0=满，非0=空
                                                                   用于 printf 风格的调试输出
                                                                   参考: Stimulus Port registers, ITM_STIM0-ITM_STIM255 on page C1-714
                                                                   备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

#define ARM_V7M_ITM_TER(n)       (0xE00 + (n) * 0x04)  /* Trace Enable Register n (n=0-7) - 跟踪使能寄存器 n [RW]
                                                                    控制激励端口的使能状态
                                                                    8 个 TER 寄存器，每个控制 32 个激励端口
                                                                    位 m=1: 使能激励端口 32n+m
                                                                    位 m=0: 禁用激励端口 32n+m
                                                                    配合 TPR 一起控制端口访问权限
                                                                    参考: Trace Enable Registers, ITM_TER0-ITM_TER7 on page C1-714
                                                                    备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

#define ARM_V7M_ITM_TPR             0xE40   /* Trace Privilege Register - 跟踪特权寄存器 [RW]
                                               控制激励端口所需的特权级别
                                               8 个 4 位字段，每个控制 32 个激励端口组
                                               字段 n 控制激励端口 32n-32(n+1)-1
                                               字段值 00: 用户和特权模式都可访问
                                               字段值 01: 仅特权模式可访问
                                               与 TER 一起配合使用
                                               参考: Trace Privilege Register, ITM_TPR on page C1-715
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

#define ARM_V7M_ITM_TCR             0xE80   /* Trace Control Register - 跟踪控制寄存器 [RW]
                                               使能或禁用 ITM 特性并选择 ITM 模式
                                               位[23:16]: TSPrescale: 时间戳预分频
                                               位[11:8]: GTSFREQ: 全局时间戳频率
                                               位[4]: TSEnable: 使能时间戳
                                               位[3]: SWOENA: 使能串行线输出
                                               位[2]: DWTENA: 使能 DWT 跟踪
                                               位[1]: SYNCENA: 使能同步包
                                               位[0]: ITMENA: 使能 ITM
                                               用于配置 ITM 的主要功能
                                               参考: Trace Control Register, ITM_TCR on page C1-716
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

/* ITM CoreSight 软件锁定寄存器 (可选)
 * 参考: Table D1-2 CoreSight Software Lock registers on page D1-767
 * 地址范围: 0xE0000FB0 - 0xE0000FB4
 */
#define ARM_V7M_ITM_LAR             0xFB0   /* ITM Lock Access Register - ITM 锁定访问寄存器 [WO]
                                               地址: 0xE0000FB0
                                               CoreSight 软件锁定访问寄存器
                                               写入 0xC5ACCE55 解锁寄存器访问
                                               读取返回 UNKNOWN
                                               用于保护 ITM 寄存器不被意外修改
                                               参考: Table D1-2 CoreSight Software Lock registers on page D1-767
                                               备注: 可选实现，未实现时读取为 UNKNOWN */

#define ARM_V7M_ITM_LSR             0xFB4   /* ITM Lock Status Register - ITM 锁定状态寄存器 [RO]
                                               地址: 0xE0000FB4
                                               CoreSight 软件锁定状态寄存器
                                               指示当前锁定状态
                                               位[1]: LOCKED: 1=已锁定, 0=未锁定
                                               位[0]: PRESENT: 1=实现锁定功能, 0=未实现
                                               未实现时读取为 0 (RAZ)
                                               参考: Table D1-2 CoreSight Software Lock registers on page D1-767
                                               备注: 可选实现，未实现时读取为 RAZ */

/* -----------------------------------------------------------------------------
 * 4.4 跟踪端口接口单元 (TPIU)
 * 参考: Table D8-3 Memory-mapped debug register index on page D8-848
 * 地址范围: 0xE0040000 - 0xE0040FFF
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_TPIU_BASE           0xE0040000UL

#define ARM_V7M_TPIU_SSPSR          0x000   /* Supported Parallel Port Sizes Register - 支持的并行端口大小寄存器 [RO]
                                               指示支持哪些并行端口大小
                                               只读寄存器，位 n=1 表示支持 2^n 位端口宽度
                                               位 0: 1 位，位 1: 2 位，位 2: 4 位，位 3: 8 位，位 4: 16 位，位 5: 32 位
                                               用于查询 TPIU 的硬件能力
                                               参考: Supported Parallel Port Sizes Register, TPIU_SSPSR on page C1-751
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-848 */

#define ARM_V7M_TPIU_CSPSR          0x004   /* Current Parallel Port Size Register - 当前并行端口大小寄存器 [RW]
                                               选择跟踪输出的并行端口大小
                                               写入 1<<n 选择 2^n 位端口宽度
                                               仅能写入 SSPSR 中支持的值
                                               用于配置跟踪端口宽度
                                               参考: Current Parallel Port Size Register, TPIU_CSPSR on page C1-751
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-848 */

#define ARM_V7M_TPIU_ACPR           0x010   /* Asynchronous Clock Prescaler Register - 异步时钟预分频寄存器 [RW]
                                               设置异步跟踪输出的预分频器
                                               位[15:0]: SWOSCALER: 预分频值
                                               跟踪时钟 = 参考时钟 / (SWOSCALER + 1)
                                               用于配置异步跟踪的波特率
                                               参考: Asynchronous Clock Prescaler Register, TPIU_ACPR on page C1-752
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-848 */

#define ARM_V7M_TPIU_SPPR           0x0F0   /* Selected Pin Protocol Register - 选择的引脚协议寄存器 [RW]
                                               选择跟踪端口协议
                                               位[1:0]: PROTOCOL: 协议选择
                                               00: 并行端口协议
                                               01: 曼彻斯特编码
                                               10: NRZ (不归零) 编码 (SWO)
                                               11: 保留
                                               用于配置跟踪输出协议
                                               参考: Selected Pin Protocol Register, TPIU_SPPR on page C1-752
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-848 */

#define ARM_V7M_TPIU_TYPE           0xFCC   /* TPIU Type register - TPIU 类型寄存器 [RO]
                                               提供 TPIU 实现的信息
                                               只读寄存器，标识 TPIU 类型
                                               用于识别 TPIU 硬件版本
                                               参考: TPIU Type register, TPIU_TYPE on page C1-753
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-848 */

/* TPIU CoreSight 软件锁定寄存器 (可选)
 * 参考: Table D1-2 CoreSight Software Lock registers on page D1-767
 * 地址范围: 0xE0040FB0 - 0xE0040FB4
 */
#define ARM_V7M_TPIU_LAR            0xFB0   /* TPIU Lock Access Register - TPIU 锁定访问寄存器 [WO]
                                               地址: 0xE0040FB0
                                               CoreSight 软件锁定访问寄存器
                                               写入 0xC5ACCE55 解锁寄存器访问
                                               读取返回 UNKNOWN
                                               用于保护 TPIU 寄存器不被意外修改
                                               参考: Table D1-2 CoreSight Software Lock registers on page D1-767
                                               备注: 可选实现，未实现时读取为 UNKNOWN */

#define ARM_V7M_TPIU_LSR            0xFB4   /* TPIU Lock Status Register - TPIU 锁定状态寄存器 [RO]
                                               地址: 0xE0040FB4
                                               CoreSight 软件锁定状态寄存器
                                               指示当前锁定状态
                                               位[1]: LOCKED: 1=已锁定, 0=未锁定
                                               位[0]: PRESENT: 1=实现锁定功能, 0=未实现
                                               未实现时读取为 0 (RAZ)
                                               参考: Table D1-2 CoreSight Software Lock registers on page D1-767
                                               备注: 可选实现，未实现时读取为 RAZ */

/* -----------------------------------------------------------------------------
 * 4.5 闪存补丁和断点单元 (FPB)
 * 参考: Table D8-3 Memory-mapped debug register index on page D8-847
 * 地址范围: 0xE0002000 - 0xE0002FFF
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_FPB_BASE            0xE0002000UL

/* -----------------------------------------------------------------------------
 * FPB 寄存器组通用宏 (使用示例: ARM_V7M_FPB_COMP(n), n = 0-7)
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_FPB_COMP(n)      (0x008 + (n) * 0x04)  /* Flash Patch Comparator register n (n=0-7) - 闪存补丁比较器寄存器 n [RW]
                                                           保存比较器 n 的比较值
                                                           用于指令断点和闪存补丁
                                                           位[31:1]: COMPADDR: 比较地址
                                                           位[0]: ENABLE: 1=使能此比较器
                                                           配合 CTRL 和 REMAP 使用
                                                           参考: Flash Patch Comparator register, FP_COMPn on page C1-758
                                                           备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

#define ARM_V7M_FPB_CTRL            0x000   /* Flash Patch Control Register - 闪存补丁控制寄存器 [RW]
                                               使能或禁用 FPB 并指示比较器数量
                                               位[15:12]: NUM_CODE2: 代码比较器数量的低 2 位
                                               位[9:8]: NUM_LIT: 文字比较器数量
                                               位[7:4]: NUM_CODE: 代码比较器数量的高 4 位
                                               位[1]: KEY: 必须写入 1 来修改除 ENABLE 外的位
                                               位[0]: ENABLE: 1=使能 FPB
                                               用于配置和查询 FPB 能力
                                               参考: Flash Patch Control Register, FP_CTRL on page C1-756
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

#define ARM_V7M_FPB_REMAP           0x004   /* Flash Patch Remap register - 闪存补丁重映射寄存器 [RW]
                                               保存重映射的基地址
                                               位[31:5]: REMAP: 重映射基地址
                                               闪存补丁时将匹配地址重映射到此基地址 + 偏移
                                               用于配置闪存补丁的目标地址
                                               参考: Flash Patch Remap register, FP_REMAP on page C1-758
                                               备注: Table D8-3 Memory-mapped debug register index on page D8-847 */

/* FPB CoreSight 软件锁定寄存器 (可选)
 * 参考: Table D1-2 CoreSight Software Lock registers on page D1-767
 * 地址范围: 0xE0002FB0 - 0xE0002FB4
 */
#define ARM_V7M_FPB_LAR             0xFB0   /* FPB Lock Access Register - FPB 锁定访问寄存器 [WO]
                                               地址: 0xE0002FB0
                                               CoreSight 软件锁定访问寄存器
                                               写入 0xC5ACCE55 解锁寄存器访问
                                               读取返回 UNKNOWN
                                               用于保护 FPB 寄存器不被意外修改
                                               参考: Table D1-2 CoreSight Software Lock registers on page D1-767
                                               备注: 可选实现，未实现时读取为 UNKNOWN */

#define ARM_V7M_FPB_LSR             0xFB4   /* FPB Lock Status Register - FPB 锁定状态寄存器 [RO]
                                               地址: 0xE0002FB4
                                               CoreSight 软件锁定状态寄存器
                                               指示当前锁定状态
                                               位[1]: LOCKED: 1=已锁定, 0=未锁定
                                               位[0]: PRESENT: 1=实现锁定功能, 0=未实现
                                               未实现时读取为 0 (RAZ)
                                               参考: Table D1-2 CoreSight Software Lock registers on page D1-767
                                               备注: 可选实现，未实现时读取为 RAZ */

/* -----------------------------------------------------------------------------
 * 4.6 ROM 表寄存器 (ROM Table Registers)
 * 参考: Table C1-3 Armv7-M DAP accessible ROM table on page C1-686
 * 地址范围: 0xE00FF000 - 0xE00FFFFF
 * 说明: ROM表用于调试器发现系统中的组件，指向各个调试组件的基地址
 * 【v7m 独有】v8m 中已移除 ROM Table 支持
 * ----------------------------------------------------------------------------- */
#define ARM_V7M_ROMTABLE_BASE       0xE00FF000UL

#define ARM_V7M_ROM_SCS             0x000   /* ROM SCS Entry - ROM SCS 条目 [RO]
                                               地址: 0xE00FF000
                                               值: 0xFFF0F003
                                               指向 SCS (System Control Space) 的基地址 0xE000E000
                                               用于调试器发现系统控制空间的位置
                                               参考: Table C1-3 Armv7-M DAP accessible ROM table on page C1-686 */

#define ARM_V7M_ROM_DWT             0x004   /* ROM DWT Entry - ROM DWT 条目 [RO]
                                               地址: 0xE00FF004
                                               值: 0xFFF02002 或 0xFFF02003
                                               指向 DWT (Data Watchpoint and Trace) 的基地址 0xE0001000
                                               bit[0]=1 表示实现了 DWT
                                               用于调试器发现 DWT 单元
                                               参考: Table C1-3 Armv7-M DAP accessible ROM table on page C1-686 */

#define ARM_V7M_ROM_FPB             0x008   /* ROM FPB Entry - ROM FPB 条目 [RO]
                                               地址: 0xE00FF008
                                               值: 0xFFF03002 或 0xFFF03003
                                               指向 FPB (Flash Patch and Breakpoint) 的基地址 0xE0002000
                                               bit[0]=1 表示实现了 FPB
                                               用于调试器发现 FPB 单元
                                               参考: Table C1-3 Armv7-M DAP accessible ROM table on page C1-686 */

#define ARM_V7M_ROM_ITM             0x00C   /* ROM ITM Entry - ROM ITM 条目 [RO]
                                               地址: 0xE00FF00C
                                               值: 0xFFF01002 或 0xFFF01003
                                               指向 ITM (Instrumentation Trace Macrocell) 的基地址 0xE0000000
                                               bit[0]=1 表示实现了 ITM
                                               用于调试器发现 ITM 单元
                                               参考: Table C1-3 Armv7-M DAP accessible ROM table on page C1-686 */

#define ARM_V7M_ROM_TPIU            0x010   /* ROM TPIU Entry - ROM TPIU 条目 [RO]
                                               地址: 0xE00FF010
                                               值: 0xFFF41002 或 0xFFF41003
                                               指向 TPIU (Trace Port Interface Unit)
                                               bit[0]=1 表示实现了 TPIU 且处理器可通过 PPB 访问
                                               用于调试器发现 TPIU 单元
                                               参考: Table C1-3 Armv7-M DAP accessible ROM table on page C1-686 */

#define ARM_V7M_ROM_ETM             0x014   /* ROM ETM Entry - ROM ETM 条目 [RO]
                                               地址: 0xE00FF014
                                               值: 0xFFF42002 或 0xFFF42003
                                               指向 ETM (Embedded Trace Macrocell)
                                               bit[0]=1 表示实现了 ETM 且处理器可通过 PPB 访问
                                               用于调试器发现 ETM 单元
                                               参考: Table C1-3 Armv7-M DAP accessible ROM table on page C1-686 */

#define ARM_V7M_ROM_END             0x018   /* ROM End of Table - ROM 表结束标记 [RO]
                                               地址: 0xE00FF018
                                               值: 0x00000000
                                               ROM 表的结束标记
                                               表示表项到此结束
                                               参考: Table C1-3 Armv7-M DAP accessible ROM table on page C1-686 */

/* ROM表组件标识寄存器 (ROM Table Component ID Registers)
 * 参考: Table C1-3 Armv7-M DAP accessible ROM table on page C1-686
 * 地址范围: 0xE00FDFCC - 0xE00FDFFC
 */
#define ARM_V7M_ROM_MEMTYPE         0xFCC   /* ROM MEMTYPE Register - ROM MEMTYPE 寄存器 [RO]
                                               地址: 0xE00FDFCC
                                               值: 0x00000001
                                               bit[0] 置 1 表示 ROM 表外还有其他资源可通过 DAP 访问
                                               位[31:1] 为 UNKNOWN
                                               用于指示系统中存在其他调试组件
                                               参考: Table C1-3 Armv7-M DAP accessible ROM table on page C1-686 */

/* ROM表外设标识寄存器 (ROM Table Peripheral ID Registers)
 * 参考: Peripheral Identification Registers on page B4-669
 * 地址范围: 0xE00FDFD0 - 0xE00FDFEC
 */
#define ARM_V7M_ROM_PID4            0xFD0   /* ROM Peripheral ID Register 4 - ROM 外设标识寄存器 4 [RO]
                                               地址: 0xE00FDFD0
                                               包含 ROM 表外设标识信息
                                               位[7:4]: 4KB 计数
                                               位[3:0]: JEP106 继续代码
                                               只读寄存器，复位值由实现定义
                                               参考: Peripheral Identification Registers on page B4-669
                                               备注: Table C1-3 on page C1-686 */

#define ARM_V7M_ROM_PID5            0xFD4   /* ROM Peripheral ID Register 5 - ROM 外设标识寄存器 5 [RO]
                                               地址: 0xE00FDFD4
                                               保留用于未来扩展
                                               只读寄存器
                                               参考: Peripheral Identification Registers on page B4-669
                                               备注: Table C1-3 on page C1-686 */

#define ARM_V7M_ROM_PID6            0xFD8   /* ROM Peripheral ID Register 6 - ROM 外设标识寄存器 6 [RO]
                                               地址: 0xE00FDFD8
                                               保留用于未来扩展
                                               只读寄存器
                                               参考: Peripheral Identification Registers on page B4-669
                                               备注: Table C1-3 on page C1-686 */

#define ARM_V7M_ROM_PID7            0xFDC   /* ROM Peripheral ID Register 7 - ROM 外设标识寄存器 7 [RO]
                                               地址: 0xE00FDFDC
                                               保留用于未来扩展
                                               只读寄存器
                                               参考: Peripheral Identification Registers on page B4-669
                                               备注: Table C1-3 on page C1-686 */

#define ARM_V7M_ROM_PID0            0xFE0   /* ROM Peripheral ID Register 0 - ROM 外设标识寄存器 0 [RO]
                                               地址: 0xE00FDFE0
                                               位[7:0]: 零件号 [7:0]
                                               用于标识 ROM 表组件类型
                                               只读寄存器，复位值由实现定义
                                               参考: Peripheral Identification Registers on page B4-669
                                               备注: Table C1-3 on page C1-686 */

#define ARM_V7M_ROM_PID1            0xFE4   /* ROM Peripheral ID Register 1 - ROM 外设标识寄存器 1 [RO]
                                               地址: 0xE00FDFE4
                                               位[7:4]: JEP106 ID 代码 [3:0]
                                               位[3:0]: 零件号 [11:8]
                                               只读寄存器，复位值由实现定义
                                               参考: Peripheral Identification Registers on page B4-669
                                               备注: Table C1-3 on page C1-686 */

#define ARM_V7M_ROM_PID2            0xFE8   /* ROM Peripheral ID Register 2 - ROM 外设标识寄存器 2 [RO]
                                               地址: 0xE00FDFE8
                                               位[7:4]: 修订版本号
                                               位[3]: JEP106 代码使用标志 (1=使用 JEP106)
                                               位[2:0]: JEP106 ID 代码 [6:4]
                                               只读寄存器，复位值由实现定义
                                               参考: Peripheral Identification Registers on page B4-669
                                               备注: Table C1-3 on page C1-686 */

#define ARM_V7M_ROM_PID3            0xFEC   /* ROM Peripheral ID Register 3 - ROM 外设标识寄存器 3 [RO]
                                               地址: 0xE00FDFEC
                                               位[7:4]: 工程变更 (ECO) 编号
                                               位[3:0]: 客户修改编号
                                               只读寄存器，复位值由实现定义
                                               参考: Peripheral Identification Registers on page B4-669
                                               备注: Table C1-3 on page C1-686 */

/* ROM表组件标识寄存器 (ROM Table Component ID Registers)
 * 参考: Component Identification Registers on page B4-670
 * 地址范围: 0xE00FDFF0 - 0xE00FDFFC
 */
#define ARM_V7M_ROM_CID0            0xFF0   /* ROM Component ID Register 0 - ROM 组件标识寄存器 0 [RO]
                                               地址: 0xE00FDFF0
                                               位[7:0]: 固定值 0x0D，标识组件类型为 ROM 表
                                               只读寄存器
                                               参考: Component Identification Registers on page B4-670
                                               备注: Table C1-3 on page C1-686 */

#define ARM_V7M_ROM_CID1            0xFF4   /* ROM Component ID Register 1 - ROM 组件标识寄存器 1 [RO]
                                               地址: 0xE00FDFF4
                                               位[7:4]: 组件类 (0x1=ARM 组件)
                                               位[3:0]: 固定值 0x00
                                               只读寄存器
                                               参考: Component Identification Registers on page B4-670
                                               备注: Table C1-3 on page C1-686 */

#define ARM_V7M_ROM_CID2            0xFF8   /* ROM Component ID Register 2 - ROM 组件标识寄存器 2 [RO]
                                               地址: 0xE00FDFF8
                                               位[7:0]: 固定值 0x05
                                               只读寄存器
                                               参考: Component Identification Registers on page B4-670
                                               备注: Table C1-3 on page C1-686 */

#define ARM_V7M_ROM_CID3            0xFFC   /* ROM Component ID Register 3 - ROM 组件标识寄存器 3 [RO]
                                               地址: 0xE00FDFFC
                                               位[7:0]: 固定值 0xB1
                                               只读寄存器
                                               参考: Component Identification Registers on page B4-670
                                               备注: Table C1-3 on page C1-686 */

#ifdef __cplusplus
}
#endif

#endif /* __ARM_V7M_CORE_H__ */