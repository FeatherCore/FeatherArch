/********************************************************************************
 * @file        arm_v8m_core_unsafe.h
 * @brief       ARMv8-M Architecture Non-secure State Register Definitions
 * @details     基于 ARMv8-M Architecture Reference Manual (ARM DDI 0553B.z)
 *              所有寄存器定义严格参考手册章节位置
 *              文档路径：g:\develop\FeatherCore\FeatherArch\docs\arm\Arm® v8-M Architecture Reference Manual.txt
 * @author      FeatherCore
 * @version     1.0.0
 * @date        2026-03-29
 * @note        本文件包含非安全状态基地址和寄存器偏移定义
 *              所有寄存器偏移使用 _NS 后缀
 *              非安全状态没有特有的寄存器，但基地址不同（0xE002E000 vs 0xE000E000）
 *
 * 非安全状态基地址清单（基于 D1.1 Register index）：
 * - Non-secure SCS Base: 0xE002E000
 *   - ICB (ICTR, ACTLR, CPPWR): 基地址 0xE002E004
 *     参考: D1.1.20 Implementation Control Block (NS alias) on page D1-1450
 *   - SysTick (SYST_CSR, SYST_RVR, SYST_CVR, SYST_CALIB): 基地址 0xE002E010
 *     参考: D1.1.21 SysTick Timer (NS alias) on page D1-1450
 *   - NVIC (NVIC_ISER, NVIC_ICER, NVIC_ISPR, NVIC_ICPR, NVIC_IABR, NVIC_IPR): 基地址 0xE002E100
 *     参考: D1.1.22 Nested Vectored Interrupt Controller (NS alias) on page D1-1451
 *     备注: ITNS 寄存器仅在安全 NVIC 中存在
 *   - SCB (CPUID, ICSR, VTOR, AIRCR, SCR, CCR, SHPR1-3, SHCSR, CFSR, HFSR, DFSR,
 *          MMFAR, BFAR, AFSR, ID_PFR0-1, ID_DFR0, ID_AFR0, ID_MMFR0-3, ID_ISAR0-5,
 *          CLIDR, CTR, CCSIDR, CSSELR): 基地址 0xE002ED00
 *     参考: D1.1.23 System Control Block (NS alias) on page D1-1451
 *     备注: CPACR 和 NSACR 不在 NS alias 中，仅在安全状态 SCB 中可访问
 *   - REVIDR: 绝对地址 0xE002ECFC (位于 SCB 基地址之前)
 *     参考: D1.1.23 System Control Block (NS alias) on page D1-1451
 *   - MPU (MPU_TYPE, MPU_CTRL, MPU_RNR, MPU_RBAR, MPU_RLAR, MPU_RBAR_A1-A3, MPU_RLAR_A1-A3,
 *          MPU_MAIR0-1): 基地址 0xE002ED90
 *     参考: D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
 *   - Debug (DHCSR, DCRDR, DEMCR, DSCEMCR, DAUTHCTRL): 基地址 0xE002EDF0
 *     参考: D1.1.25 Debug Control Block (NS alias) on page D1-1451
 *     备注: DCRSR (0xE000EDF4) 和 DSCSR (0xE000EE08) 仅在安全调试控制块中存在
 *   - Debug Identification (DLAR, DLSR, DAUTHSTATUS, DDEVARCH, DDEVTYPE, DPIDR0-7, DCIDR0-3): 基地址 0xE002EFB0
 *     参考: D1.1.30 Debug Identification Block (NS alias) on page D1-1453
 *   - STIR: 基地址 0xE002EF00
 *     参考: D1.1.26 Software Interrupt Generation (NS alias) on page D1-1452
 *   - RFSR: 基地址 0xE002EF04
 *     参考: D1.1.27 RAS Extension Fault Status Register (NS Alias) on page D1-1452
 *   - FPU (FPCCR, FPCAR, FPDSCR, MVFR0-2): 基地址 0xE002EF34
 *     参考: D1.1.28 Floating-Point Extension (NS alias) on page D1-1452
 *   - Cache Maintenance (ICIALLU, ICIMVAU, DCIMVAC, DCISW, DCCMVAU, DCCMVAC, DCCSW,
 *                       DCCIMVAC, DCCISW, BPIALL): 基地址 0xE002EF50
 *     参考: D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
 * - Non-secure ITM (ITM_STIMn, ITM_TERn, ITM_TPR, ITM_TCR, ITM_LAR, ITM_LSR): 基地址 0xE0020000
 *   参考: D1.1.3 Instrumentation Macrocell on page D1-1444
 * - Non-secure DWT (DWT_CTRL, DWT_CYCCNT, DWT_CPICNT, DWT_EXCCNT, DWT_SLEEPCNT, DWT_LSUCNT,
 *               DWT_FOLDCNT, DWT_PCSR, DWT_COMPn, DWT_FUNCTIONn, DWT_VMASKn, DWT_LAR, DWT_LSR): 基地址 0xE0021000
 *   参考: D1.1.4 Data Watchpoint and Trace on page D1-1445
 * - Non-secure FPB (FP_CTRL, FP_REMAP, FP_COMPn, FP_LAR, FP_LSR): 基地址 0xE0022000
 *   参考: D1.1.5 Flash Patch and Breakpoint on page D1-1445
 * - Non-secure PMU (PMU_EVCNTRn, PMU_CCNT, PMU_EVTYPERn, PMU_CCFILTR, PMU_CNTENSET, PMU_CNTENCLR,
 *               PMU_INTENSET, PMU_INTENCLR, PMU_OVSCLR, PMU_SWINC, PMU_OVSSET, PMU_TYPE, PMU_CTRL): 基地址 0xE0023000
 *   参考: D1.1.6 Performance Monitoring Unit on page D1-1445
 * - Non-secure RAS (ERRFRn, ERRCTRLn, ERRSTATUSn, ERRADDRn, ERRADDR2n, ERRMISCn, ERRGSRn, ERRIIDR, ERRDEVID): 基地址 0xE0025000
 *   参考: D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446
 * - Non-secure TPIU (TPIU_SSPSR, TPIU_CSPSR, TPIU_ACPR, TPIU_SPPR, TPIU_FFSR, TPIU_FFCR, TPIU_PSCR,
 *                TPIU_CLAIMSET, TPIU_CLAIMCLR, TPIU_LAR, TPIU_LSR, TPIU_DEVID, TPIU_DEVTYPE): 基地址 0xE0040000
 *   参考: D1.1.31 Trace Port Interface Unit on page D1-1453
 *   备注: TPIU 在安全和非安全状态下共享同一物理寄存器
 * 注意: 非安全状态没有 SAU（安全归属单元仅在安全状态下可访问）
 * 参考: D1.1 Register index on page D1-1442
 ********************************************************************************/

#ifndef __ARM_V8M_CORE_UNSAFE_H__
#define ARM_V8M_PMU_CNTENCLR_NS     0xC20           /* PMU Count Enable Clear Register - PMU 计数使能清除寄存器 [RW]
                                                          禁用事件计数器，写 1 禁用对应计数器
                                                          偏移：0xC20 (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_PMU_INTENSET_NS     0xC40           /* PMU Interrupt Enable Set Register - PMU 中断使能设置寄存器 [RW]
                                                          使能计数器溢出中断，写 1 使能对应中断
                                                          偏移：0xC40 (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_PMU_INTENCLR_NS     0xC60           /* PMU Interrupt Enable Clear Register - PMU 中断使能清除寄存器 [RW]
                                                          禁用计数器溢出中断，写 1 禁用对应中断
                                                          偏移：0xC60 (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_PMU_OVSCLR_NS       0xC80           /* PMU Overflow Flag Status Clear Register - PMU 溢出标志状态清除寄存器 [RW]
                                                          清除计数器溢出标志，写 1 清除对应标志
                                                          偏移：0xC80 (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_PMU_SWINC_NS        0xCA0           /* PMU Software Increment Register - PMU 软件递增寄存器 [WO]
                                                          软件递增计数器，用于测试
                                                          偏移：0xCA0 (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_PMU_OVSSET_NS       0xCC0           /* PMU Overflow Flag Status Set Register - PMU 溢出标志状态设置寄存器 [RW]
                                                          设置计数器溢出标志，用于测试
                                                          偏移：0xCC0 (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_PMU_TYPE_NS         0xE00           /* PMU Type Register - PMU 类型寄存器 [RO]
                                                          提供 PMU 的配置信息，如计数器数量、支持的特性等
                                                          偏移：0xE00 (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_PMU_CTRL_NS         0xE04           /* PMU Control Register - PMU 控制寄存器 [RW]
                                                          控制 PMU 的全局行为，如使能 PMU、设置计数器复位等
                                                          偏移：0xE04 (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_PMU_AUTHSTATUS_NS   0xFB8           /* PMU Authentication Status Register - PMU 认证状态寄存器 [RO]
                                                          显示 PMU 的认证状态
                                                          偏移：0xFB8 (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_PMU_LAR_NS          0xFB0           /* PMU Lock Access Register - PMU 锁定访问寄存器 [WO]
                                                          用于锁定或解锁 PMU 寄存器的访问
                                                          偏移：0xFB0 (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_PMU_LSR_NS          0xFB4           /* PMU Lock Status Register - PMU 锁定状态寄存器 [RO]
                                                          显示 PMU 寄存器的锁定状态
                                                          偏移：0xFB4 (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* ==============================================================================
 * 十八、非安全状态 RAS 寄存器偏移定义
 * 参考: D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446
 * ==============================================================================
 */

#define ARM_V8M_RAS_ERRFR0_NS       0x000           /* RAS Error Feature Register 0 - RAS 错误特性寄存器 0 [RO]
                                                          提供错误记录 0 的特性信息
                                                          偏移：0x000 (相对于 ARM_V8M_RAS_BASE_NS)
                                                          参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_RAS_ERRCTRL0_NS     0x008           /* RAS Error Control Register 0 - RAS 错误控制寄存器 0 [RW]
                                                          控制错误记录 0 的行为
                                                          偏移：0x008 (相对于 ARM_V8M_RAS_BASE_NS)
                                                          参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_RAS_ERRSTATUS0_NS   0x010           /* RAS Error Status Register 0 - RAS 错误状态寄存器 0 [RW]
                                                          记录错误记录 0 的状态信息
                                                          偏移：0x010 (相对于 ARM_V8M_RAS_BASE_NS)
                                                          参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_RAS_ERRADDR0_NS     0x018           /* RAS Error Address Register 0 - RAS 错误地址寄存器 0 [RW]
                                                          记录错误记录 0 的地址信息
                                                          偏移：0x018 (相对于 ARM_V8M_RAS_BASE_NS)
                                                          参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_RAS_ERRADDR20_NS    0x020           /* RAS Error Address 2 Register 0 - RAS 错误地址 2 寄存器 0 [RW]
                                                          记录错误记录 0 的附加地址信息
                                                          偏移：0x020 (相对于 ARM_V8M_RAS_BASE_NS)
                                                          参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_RAS_ERRMISC0_NS     0x028           /* RAS Error Miscellaneous Register 0 - RAS 错误杂项寄存器 0 [RW]
                                                          记录错误记录 0 的杂项信息
                                                          偏移：0x028 (相对于 ARM_V8M_RAS_BASE_NS)
                                                          参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_RAS_ERRGSR0_NS      0x030           /* RAS Error Group Status Register 0 - RAS 错误组状态寄存器 0 [RO]
                                                          显示错误记录 0 的组状态
                                                          偏移：0x030 (相对于 ARM_V8M_RAS_BASE_NS)
                                                          参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_RAS_ERRIIDR_NS      0xE00           /* RAS Error Implementation Identification Register - RAS 错误实现标识寄存器 [RO]
                                                          提供 RAS 实现的标识信息
                                                          偏移：0xE00 (相对于 ARM_V8M_RAS_BASE_NS)
                                                          参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_RAS_ERRDEVID_NS     0xE08           /* RAS Error Device ID Register - RAS 错误设备 ID 寄存器 [RO]
                                                          提供 RAS 设备的标识信息
                                                          偏移：0xE08 (相对于 ARM_V8M_RAS_BASE_NS)
                                                          参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446
                                                          备注：与 Secure 实例银行化 */

/* ==============================================================================
 * 十九、非安全状态 TPIU 寄存器偏移定义
 * 参考: D1.1.31 Trace Port Interface Unit on page D1-1453
 * ==============================================================================
 */

#define ARM_V8M_TPIU_SSPSR_NS       0x000           /* TPIU Supported Port Size Register - TPIU 支持端口大小寄存器 [RO]
                                                          显示 TPIU 支持的端口大小
                                                          偏移：0x000 (相对于 ARM_V8M_TPIU_BASE_NS)
                                                          参考：D1.1.31 Trace Port Interface Unit on page D1-1453
                                                          备注：TPIU 在安全和非安全状态下共享同一物理寄存器 */

#define ARM_V8M_TPIU_CSPSR_NS       0x004           /* TPIU Current Port Size Register - TPIU 当前端口大小寄存器 [RW]
                                                          设置 TPIU 当前的端口大小
                                                          偏移：0x004 (相对于 ARM_V8M_TPIU_BASE_NS)
                                                          参考：D1.1.31 Trace Port Interface Unit on page D1-1453
                                                          备注：TPIU 在安全和非安全状态下共享同一物理寄存器 */

#define ARM_V8M_TPIU_ACPR_NS        0x010           /* TPIU Asynchronous Clock Prescaler Register - TPIU 异步时钟预分频寄存器 [RW]
                                                          设置异步跟踪的时钟预分频值
                                                          偏移：0x010 (相对于 ARM_V8M_TPIU_BASE_NS)
                                                          参考：D1.1.31 Trace Port Interface Unit on page D1-1453
                                                          备注：TPIU 在安全和非安全状态下共享同一物理寄存器 */

#define ARM_V8M_TPIU_SPPR_NS        0x0F0           /* TPIU Selected Pin Protocol Register - TPIU 选择引脚协议寄存器 [RW]
                                                          选择跟踪端口的引脚协议
                                                          偏移：0x0F0 (相对于 ARM_V8M_TPIU_BASE_NS)
                                                          参考：D1.1.31 Trace Port Interface Unit on page D1-1453
                                                          备注：TPIU 在安全和非安全状态下共享同一物理寄存器 */

#define ARM_V8M_TPIU_FFSR_NS        0x300           /* TPIU Formatter and Flush Status Register - TPIU 格式化器和刷新状态寄存器 [RO]
                                                          显示格式化器和刷新的状态
                                                          偏移：0x300 (相对于 ARM_V8M_TPIU_BASE_NS)
                                                          参考：D1.1.31 Trace Port Interface Unit on page D1-1453
                                                          备注：TPIU 在安全和非安全状态下共享同一物理寄存器 */

#define ARM_V8M_TPIU_FFCR_NS        0x304           /* TPIU Formatter and Flush Control Register - TPIU 格式化器和刷新控制寄存器 [RW]
                                                          控制格式化器和刷新的行为
                                                          偏移：0x304 (相对于 ARM_V8M_TPIU_BASE_NS)
                                                          参考：D1.1.31 Trace Port Interface Unit on page D1-1453
                                                          备注：TPIU 在安全和非安全状态下共享同一物理寄存器 */

#define ARM_V8M_TPIU_PSCR_NS        0x308           /* TPIU Periodic Synchronization Counter Register - TPIU 周期同步计数器寄存器 [RW]
                                                          设置周期同步计数器的值
                                                          偏移：0x308 (相对于 ARM_V8M_TPIU_BASE_NS)
                                                          参考：D1.1.31 Trace Port Interface Unit on page D1-1453
                                                          备注：TPIU 在安全和非安全状态下共享同一物理寄存器 */

#define ARM_V8M_TPIU_CLAIMSET_NS    0xFA0           /* TPIU Claim Tag Set Register - TPIU 声明标签设置寄存器 [RW]
                                                          设置声明标签，用于调试工具声明对 TPIU 的所有权
                                                          偏移：0xFA0 (相对于 ARM_V8M_TPIU_BASE_NS)
                                                          参考：D1.1.31 Trace Port Interface Unit on page D1-1453
                                                          备注：TPIU 在安全和非安全状态下共享同一物理寄存器 */

#define ARM_V8M_TPIU_CLAIMCLR_NS    0xFA4           /* TPIU Claim Tag Clear Register - TPIU 声明标签清除寄存器 [RW]
                                                          清除声明标签
                                                          偏移：0xFA4 (相对于 ARM_V8M_TPIU_BASE_NS)
                                                          参考：D1.1.31 Trace Port Interface Unit on page D1-1453
                                                          备注：TPIU 在安全和非安全状态下共享同一物理寄存器 */

#define ARM_V8M_TPIU_LAR_NS         0xFB0           /* TPIU Lock Access Register - TPIU 锁定访问寄存器 [WO]
                                                          用于锁定或解锁 TPIU 寄存器的访问
                                                          偏移：0xFB0 (相对于 ARM_V8M_TPIU_BASE_NS)
                                                          参考：D1.1.31 Trace Port Interface Unit on page D1-1453
                                                          备注：TPIU 在安全和非安全状态下共享同一物理寄存器 */

#define ARM_V8M_TPIU_LSR_NS         0xFB4           /* TPIU Lock Status Register - TPIU 锁定状态寄存器 [RO]
                                                          显示 TPIU 寄存器的锁定状态
                                                          偏移：0xFB4 (相对于 ARM_V8M_TPIU_BASE_NS)
                                                          参考：D1.1.31 Trace Port Interface Unit on page D1-1453
                                                          备注：TPIU 在安全和非安全状态下共享同一物理寄存器 */

#define ARM_V8M_TPIU_DEVID_NS       0xFC8           /* TPIU Device ID Register - TPIU 设备 ID 寄存器 [RO]
                                                          提供 TPIU 的设备标识信息
                                                          偏移：0xFC8 (相对于 ARM_V8M_TPIU_BASE_NS)
                                                          参考：D1.1.31 Trace Port Interface Unit on page D1-1453
                                                          备注：TPIU 在安全和非安全状态下共享同一物理寄存器 */

#define ARM_V8M_TPIU_DEVTYPE_NS     0xFCC           /* TPIU Device Type Register - TPIU 设备类型寄存器 [RO]
                                                          提供 TPIU 的设备类型信息
                                                          偏移：0xFCC (相对于 ARM_V8M_TPIU_BASE_NS)
                                                          参考：D1.1.31 Trace Port Interface Unit on page D1-1453
                                                          备注：TPIU 在安全和非安全状态下共享同一物理寄存器 */

#ifdef __cplusplus
}
#endif

#define __ARM_V8M_CORE_UNSAFE_H__

#ifdef __cplusplus
extern "C" {
#endif

/* ==============================================================================
 * 一、非安全状态系统控制空间 (Non-secure SCS) 基地址
 * 参考: D1.1 Register index on page D1-1443
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 1.1 Non-secure System Control Space Base Address
 * 参考: D1.1 Register index on page D1-1443
 *      Non-secure SCS 基地址，所有非安全状态 SCS 寄存器在此地址开始
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCS_BASE_NS         0xE002E000UL    /* Non-secure System Control Space Base - 非安全系统控制空间基地址 [RO]
                                                          非安全状态下 SCS 的起始地址，所有非安全状态系统控制寄存器在此基地址上偏移分布
                                                          包括 ICTR, ACTLR, CPUID, ICSR, VTOR, AIRCR, SCR, CCR, SHPR1-3, SHCSR,
                                                          CFSR, HFSR, DFSR, MMFAR, BFAR, AFSR
                                                          参考：D1.1 Register index on page D1-1443
                                                          备注：CPACR 不在 NS alias 中，仅在安全状态 SCB 中可访问 (0xE000ED88)
                                                          参考：D1.2 Summary of register mapping on page D1-1454 */

#define ARM_V8M_ICB_BASE_NS         0xE002E004UL    /* Non-secure Implementation Control Block Base - 非安全实现控制块基地址 [RO]
                                                          非安全状态实现控制块的基地址
                                                          参考：D1.1.20 Implementation Control Block (NS alias) on page D1-1450 */

#define ARM_V8M_SYST_BASE_NS        0xE002E010UL    /* Non-secure SysTick Timer Base - 非安全 SysTick 定时器基地址 [RO]
                                                          非安全状态下 SysTick 定时器寄存器基地址
                                                          包括 SYST_CSR, SYST_RVR, SYST_CVR, SYST_CALIB
                                                          参考：D1.1.21 SysTick Timer (NS alias) on page D1-1450
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_NVIC_BASE_NS        0xE002E100UL    /* Non-secure Nested Vectored Interrupt Controller Base - 非安全 NVIC 基地址 [RO]
                                                          非安全状态下 NVIC 寄存器基地址
                                                          包括 NVIC_ISER, NVIC_ICER, NVIC_ISPR, NVIC_ICPR, NVIC_IABR, NVIC_IPR0-7
                                                          注意：ITNS 寄存器位于安全 NVIC 中，非安全 NVIC 中不存在
                                                          参考：D1.1.22 Nested Vectored Interrupt Controller (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_REVIDR_BASE_NS  0xE002ECFCUL    /* Non-secure Revision ID Register Base - 非安全修订 ID 寄存器基地址 [RO]
                                                          REVIDR 寄存器的绝对地址 (NS alias)，位于 SCB 基地址之前
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451 */

#define ARM_V8M_SCB_BASE_NS         0xE002ED00UL    /* Non-secure System Control Block Base - 非安全 SCB 基地址 [RO]
                                                          非安全状态下 SCB 寄存器基地址
                                                          包括 CPUID, ICSR, VTOR, AIRCR, SCR, CCR, SHPR1-3, SHCSR,
                                                          CFSR, HFSR, DFSR, MMFAR, BFAR, AFSR
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：CPACR 不在 NS alias 中，仅在安全状态 SCB 中可访问 (0xE000ED88)
                                                          备注：NS SCB 范围结束于 0xE002ED88 */

#define ARM_V8M_MPU_BASE_NS         0xE002ED90UL    /* Non-secure Memory Protection Unit Base - 非安全 MPU 基地址 [RO]
                                                          非安全状态下 MPU 寄存器基地址
                                                          包括 MPU_TYPE, MPU_CTRL, MPU_RNR, MPU_RBAR, MPU_RLAR, MPU_MAIR0-1
                                                          参考：D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_STIR_BASE_NS        0xE002EF00UL    /* Non-secure Software Triggered Interrupt Base - 非安全 STIR 基地址 [WO]
                                                          非安全状态下 STIR 寄存器基地址
                                                          包括 STIR (Software Triggered Interrupt Register)
                                                          参考：D1.1.26 Software Interrupt Generation (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_RFSR_BASE_NS        0xE002EF04UL    /* Non-secure RAS Fault Status Register Base - 非安全 RFSR 基地址 [RO]
                                                          非安全状态下 RFSR 寄存器基地址
                                                          包括 RFSR (RAS Fault Status Register)
                                                          参考：D1.1.27 RAS Extension Fault Status Register (NS Alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_FPU_BASE_NS         0xE002EF34UL    /* Non-secure Floating-point Unit Base - 非安全 FPU 基地址 [RO]
                                                          非安全状态下 FPU 寄存器基地址
                                                          包括 FPCCR, FPCAR, FPDSCR, MVFR0, MVFR1, MVFR2
                                                          参考：D1.1.28 Floating-Point Extension (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_CACHE_BASE_NS       0xE002EF50UL    /* Non-secure Cache Maintenance Operations Base - 非安全缓存维护操作基地址 [WO]
                                                          非安全状态下缓存维护操作寄存器基地址
                                                          包括 ICIALLU, ICIMVAU, DCIMVAC, DCISW, DCCMVAU, DCCMVAC, DCCSW, DCCIMVAC, DCCISW, BPIALL
                                                          参考：D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DEBUG_BASE_NS       0xE002EDF0UL    /* Non-secure Debug Control Block Base - 非安全调试控制块基地址 [RO]
                                                          非安全状态下调试控制块基地址
                                                          此为独立于安全调试控制块的 NS alias
                                                          包括 DHCSR, DCRDR, DEMCR, DSCEMCR, DAUTHCTRL
                                                          参考：D1.1.25 Debug Control Block (NS alias) on page D1-1451
                                                          备注：DCRSR (0xE000EDF4) 和 DSCSR (0xE000EE08) 仅在安全调试控制块中存在
                                                          备注：NS Debug Control Block 范围为 0xE002EDF0-0xE002EE04 */

#define ARM_V8M_DEBUG_ID_BASE_NS    0xE002EFB0UL    /* Non-secure Debug Identification Block Base - 非安全调试标识块基地址 [RO]
                                                          非安全状态下调试标识块基地址
                                                          包括 DLAR, DLSR, DAUTHSTATUS, DDEVARCH, DDEVTYPE, DPIDR0-7, DCIDR0-3
                                                          参考：D1.1.30 Debug Identification Block (NS alias) on page D1-1453 */

/* ==============================================================================
 * 二、非安全状态调试/跟踪单元基地址
 * 参考: D1.1 Register index on page D1-1443
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 2.1 Non-secure Instrumentation Macrocell Base
 * 参考: D1.1.3 Instrumentation Macrocell on page D1-1444
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_ITM_BASE_NS         0xE0020000UL    /* Non-secure Instrumentation Macrocell Base - 非安全 ITM 基地址 [RO]
                                                          非安全状态下 ITM 寄存器基地址
                                                          包括 ITM_STIM0-31, ITM_TER, ITM_TPR, ITM_TCR, ITM_LAR, ITM_LSR
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 2.2 Non-secure Data Watchpoint and Trace Base
 * 参考: D1.1.4 Data Watchpoint and Trace on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DWT_BASE_NS         0xE0021000UL    /* Non-secure Data Watchpoint and Trace Base - 非安全 DWT 基地址 [RO]
                                                          非安全状态下 DWT 寄存器基地址
                                                          包括 DWT_CTRL, DWT_CYCCNT, DWT_CPICNT, DWT_EXCCNT, DWT_SLEEPCNT,
                                                          DWT_LSUCNT, DWT_FOLDCNT, DWT_PCSR, DWT_COMP0-3, DWT_MASK0-3,
                                                          DWT_FUNCTION0-3, DWT_LAR, DWT_LSR
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 2.3 Non-secure Flash Patch and Breakpoint Base
 * 参考: D1.1.5 Flash Patch and Breakpoint on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_FPB_BASE_NS         0xE0022000UL    /* Non-secure Flash Patch and Breakpoint Base - 非安全 FPB 基地址 [RO]
                                                          非安全状态下 FPB 寄存器基地址
                                                          包括 FP_CTRL, FP_REMAP, FP_COMP0-7, FPB_LAR, FPB_LSR
                                                          参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 2.4 Non-secure Performance Monitoring Unit Base
 * 参考: D1.1.6 Performance Monitoring Unit on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_PMU_BASE_NS         0xE0023000UL    /* Non-secure Performance Monitoring Unit Base - 非安全 PMU 基地址 [RO]
                                                          非安全状态下 PMU 寄存器基地址
                                                          包括 PMU_CCNT, PMU_EVCNTR0-3, PMU_EVTYPER, PMU_CCFILTR,
                                                          PMU_CNTENSET, PMU_CNTENCLR, PMU_INTENSET, PMU_INTENCLR,
                                                          PMU_OVSCLR, PMU_SWINC, PMU_OVSSET, PMU_TYPE, PMU_CTRL,
                                                          PMU_AUTHSTATUS, PMU_LAR, PMU_LSR
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 2.5 Non-secure Reliability, Availability and Serviceability Extension Base
 * 参考: D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_RAS_BASE_NS         0xE0025000UL    /* Non-secure RAS Extension Base - 非安全 RAS 基地址 [RO]
                                                          非安全状态下 RAS 寄存器基地址
                                                          包括 ERRFR, ERRCTRL, ERRSTATUS, ERRADDR, ERRADDR2,
                                                          ERRMISC, ERRGSR, ERRIIDR, ERRDEVID
                                                          参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446
                                                          备注：RAS 功能主要在安全状态下配置和管理 */

/* -----------------------------------------------------------------------------
 * 2.6 Non-secure Trace Port Interface Unit Base
 * 参考: D1.1.31 Trace Port Interface Unit on page D1-1453
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_TPIU_BASE_NS        0xE0040000UL    /* Non-secure Trace Port Interface Unit Base - 非安全 TPIU 基地址 [RO]
                                                          非安全状态下 TPIU 寄存器基地址
                                                          包括 TPIU_SSPSR, TPIU_CSPSR, TPIU_ACPR, TPIU_SPPR, TPIU_FFSR,
                                                          TPIU_FFCR, TPIU_PSCR, TPIU_CLAIMSET, TPIU_CLAIMCLR,
                                                          TPIU_LAR, TPIU_LSR, TPIU_DEVID, TPIU_DEVTYPE
                                                          参考：D1.1.31 Trace Port Interface Unit on page D1-1453
                                                          备注：TPIU 在安全和非安全状态下共享同一物理寄存器 */

/* ==============================================================================
 * 三、非安全状态 SCS 寄存器偏移定义
 * 参考: D1.1.20 Implementation Control Block (NS alias) on page D1-1450
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 3.1 Non-secure Implementation Control Block Registers
 * 基地址: 0xE002E004 (ARM_V8M_ICB_BASE_NS)
 * 参考: D1.1.20 Implementation Control Block (NS alias) on page D1-1450
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCS_ICTR_NS         0x004           /* SCS Interrupt Controller Type Register - 中断控制器类型寄存器 [RO]
                                                          提供关于 NVIC 配置的信息，包括中断优先级位数和外部中断数量
                                                          偏移：0x004 (相对于 ARM_V8M_ICB_BASE_NS)
                                                          参考：D1.1.20 Implementation Control Block (NS alias) on page D1-1450
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCS_ACTLR_NS        0x008           /* SCS Auxiliary Control Register - 辅助控制寄存器 [RW]
                                                          提供对处理器功能的额外控制，如禁用写缓冲、禁用 IT 折叠等
                                                          偏移：0x008 (相对于 ARM_V8M_ICB_BASE_NS)
                                                          参考：D1.1.20 Implementation Control Block (NS alias) on page D1-1450
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCS_CPPWR_NS        0x00C           /* SCS Coprocessor Power Control Register - 协处理器电源控制寄存器 [RW]
                                                          控制协处理器的电源状态，用于电源管理
                                                          偏移：0x00C (相对于 ARM_V8M_ICB_BASE_NS)
                                                          参考：D1.1.20 Implementation Control Block (NS alias) on page D1-1450
                                                          备注：与 Secure 实例银行化 */

/* ==============================================================================
 * 四、非安全状态 SysTick 寄存器偏移定义
 * 参考: D1.1.21 SysTick Timer (NS alias) on page D1-1450
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 4.1 Non-secure SysTick Timer Registers
 * 基地址: 0xE002E010 (ARM_V8M_SYST_BASE_NS)
 * 参考: D1.1.21 SysTick Timer (NS alias) on page D1-1450
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SYST_CSR_NS         0x000           /* SysTick Control and Status Register - SysTick 控制和状态寄存器 [RW]
                                                          控制 SysTick 定时器的使能、时钟源选择和中断使能
                                                          偏移：0x000 (相对于 ARM_V8M_SYST_BASE_NS)
                                                          参考：D1.1.21 SysTick Timer (NS alias) on page D1-1450
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SYST_RVR_NS         0x004           /* SysTick Reload Value Register - SysTick 重载值寄存器 [RW]
                                                          设置 SysTick 定时器的重载值，当计数器递减到 0 时重新加载
                                                          偏移：0x004 (相对于 ARM_V8M_SYST_BASE_NS)
                                                          参考：D1.1.21 SysTick Timer (NS alias) on page D1-1450
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SYST_CVR_NS         0x008           /* SysTick Current Value Register - SysTick 当前值寄存器 [RW]
                                                          读取当前计数值，写入任何值都会清零计数器
                                                          偏移：0x008 (相对于 ARM_V8M_SYST_BASE_NS)
                                                          参考：D1.1.21 SysTick Timer (NS alias) on page D1-1450
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SYST_CALIB_NS       0x00C           /* SysTick Calibration Value Register - SysTick 校准值寄存器 [RO]
                                                          提供 SysTick 定时器的校准信息，包括 10ms 计数值和参考时钟存在标志
                                                          偏移：0x00C (相对于 ARM_V8M_SYST_BASE_NS)
                                                          参考：D1.1.21 SysTick Timer (NS alias) on page D1-1450
                                                          备注：与 Secure 实例银行化 */

/* ==============================================================================
 * 五、非安全状态 NVIC 寄存器偏移定义
 * 参考: D1.1.22 Nested Vectored Interrupt Controller (NS alias) on page D1-1451
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 5.1 Non-secure NVIC Interrupt Set/Clear Enable Registers
 * 基地址: 0xE002E100 (ARM_V8M_NVIC_BASE_NS)
 * 参考: D1.1.22 Nested Vectored Interrupt Controller (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_NVIC_ISER_NS        0x000           /* NVIC Interrupt Set-Enable Register - 中断使能设置寄存器 [RW]
                                                          用于使能中断，写 1 使能对应中断
                                                          偏移：0x000 (相对于 ARM_V8M_NVIC_BASE_NS)
                                                          参考：D1.1.22 Nested Vectored Interrupt Controller (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_NVIC_ICER_NS        0x080           /* NVIC Interrupt Clear-Enable Register - 中断使能清除寄存器 [RW]
                                                          用于禁用中断，写 1 禁用对应中断
                                                          偏移：0x080 (相对于 ARM_V8M_NVIC_BASE_NS)
                                                          参考：D1.1.22 Nested Vectored Interrupt Controller (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_NVIC_ISPR_NS        0x100           /* NVIC Interrupt Set-Pending Register - 中断挂起设置寄存器 [RW]
                                                          用于设置中断挂起状态，写 1 设置挂起
                                                          偏移：0x100 (相对于 ARM_V8M_NVIC_BASE_NS)
                                                          参考：D1.1.22 Nested Vectored Interrupt Controller (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_NVIC_ICPR_NS        0x180           /* NVIC Interrupt Clear-Pending Register - 中断挂起清除寄存器 [RW]
                                                          用于清除中断挂起状态，写 1 清除挂起
                                                          偏移：0x180 (相对于 ARM_V8M_NVIC_BASE_NS)
                                                          参考：D1.1.22 Nested Vectored Interrupt Controller (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_NVIC_IABR_NS        0x200           /* NVIC Interrupt Active Bit Register - 中断活动位寄存器 [RO]
                                                          显示中断当前是否正在处理中
                                                          偏移：0x200 (相对于 ARM_V8M_NVIC_BASE_NS)
                                                          参考：D1.1.22 Nested Vectored Interrupt Controller (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 5.2 Non-secure NVIC 注意：ITNS 寄存器仅在安全 NVIC 中存在
 * 参考: D1.1.22 Nested Vectored Interrupt Controller (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
/* 注意：ARM_V8M_NVIC_ITNS_NS 不存在，因为 ITNS 寄存器仅在安全 NVIC 中
 * 参考：D1.1.22 Nested Vectored Interrupt Controller (NS alias) on page D1-1451
 * 非安全状态无法访问中断目标非安全状态寄存器 */

/* -----------------------------------------------------------------------------
 * 5.3 Non-secure NVIC Interrupt Priority Registers
 * 基地址: 0xE002E100 (ARM_V8M_NVIC_BASE_NS)
 * 参考: D1.1.22 Nested Vectored Interrupt Controller (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_NVIC_IPR_NS         0x300           /* NVIC Interrupt Priority Register - 中断优先级寄存器 [RW]
                                                          设置中断优先级，每个寄存器包含 4 个中断的优先级
                                                          偏移：0x300 (相对于 ARM_V8M_NVIC_BASE_NS)
                                                          参考：D1.1.22 Nested Vectored Interrupt Controller (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* ==============================================================================
 * 六、非安全状态 SCB 寄存器偏移定义
 * 参考: D1.1.23 System Control Block (NS alias) on page D1-1451
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 6.1 Non-secure SCB CPUID and Control Registers
 * 基地址: 0xE002ED00 (ARM_V8M_SCB_BASE_NS)
 * 参考: D1.1.23 System Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCB_CPUID_NS        0x000           /* SCB CPUID Base Register - CPUID 基址寄存器 [RO]
                                                          提供处理器的实现信息和架构版本
                                                          偏移：0x000 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_ICSR_NS         0x004           /* SCB Interrupt Control and State Register - 中断控制和状态寄存器 [RW]
                                                          控制 NMI、PendSV、SysTick 的挂起和清除，以及获取当前异常编号
                                                          偏移：0x004 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_VTOR_NS         0x008           /* SCB Vector Table Offset Register - 向量表偏移寄存器 [RW]
                                                          设置向量表的起始地址
                                                          偏移：0x008 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_AIRCR_NS        0x00C           /* SCB Application Interrupt and Reset Control Register - 应用中断和复位控制寄存器 [RW]
                                                          控制优先级分组、系统复位请求、数据字节序
                                                          偏移：0x00C (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_SCR_NS          0x010           /* SCB System Control Register - 系统控制寄存器 [RW]
                                                          控制系统电源管理功能，如睡眠深度和唤醒行为
                                                          偏移：0x010 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_CCR_NS          0x014           /* SCB Configuration and Control Register - 配置和控制寄存器 [RW]
                                                          控制各种处理器行为，如除零捕获、非对齐访问捕获等
                                                          偏移：0x014 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 6.2 Non-secure SCB System Handler Priority Registers
 * 基地址: 0xE002ED00 (ARM_V8M_SCB_BASE_NS)
 * 参考: D1.1.23 System Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCB_SHPR1_NS        0x018           /* SCB System Handler Priority Register 1 - 系统处理程序优先级寄存器 1 [RW]
                                                          设置 MemManage、BusFault、UsageFault 的优先级
                                                          偏移：0x018 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_SHPR2_NS        0x01C           /* SCB System Handler Priority Register 2 - 系统处理程序优先级寄存器 2 [RW]
                                                          设置 SVCall 的优先级
                                                          偏移：0x01C (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_SHPR3_NS        0x020           /* SCB System Handler Priority Register 3 - 系统处理程序优先级寄存器 3 [RW]
                                                          设置 DebugMonitor、PendSV、SysTick 的优先级
                                                          偏移：0x020 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 6.3 Non-secure SCB System Handler Control and Fault Status Registers
 * 基地址: 0xE002ED00 (ARM_V8M_SCB_BASE_NS)
 * 参考: D1.1.23 System Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCB_SHCSR_NS        0x024           /* SCB System Handler Control and State Register - 系统处理程序控制和状态寄存器 [RW]
                                                          控制系统处理程序的使能状态和活动状态，以及故障状态
                                                          偏移：0x024 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_CFSR_NS         0x028           /* SCB Configurable Fault Status Register - 可配置故障状态寄存器 [RW]
                                                          包含 UsageFault、BusFault、MemManage 的状态位
                                                          偏移：0x028 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_HFSR_NS         0x02C           /* SCB HardFault Status Register - HardFault 状态寄存器 [RW]
                                                          记录 HardFault 的原因，如向量表读取错误、强制 HardFault 等
                                                          偏移：0x02C (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_DFSR_NS         0x030           /* SCB Debug Fault Status Register - 调试故障状态寄存器 [RW]
                                                          记录调试事件，如断点、数据观察点、外部调试请求等
                                                          偏移：0x030 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 6.4 Non-secure SCB Memory Management Fault Address Register
 * 基地址: 0xE002ED00 (ARM_V8M_SCB_BASE_NS)
 * 参考: D1.1.23 System Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCB_MMFAR_NS        0x034           /* SCB MemManage Fault Address Register - MemManage 故障地址寄存器 [RW]
                                                          记录触发 MemManage 故障的地址
                                                          偏移：0x034 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 6.5 Non-secure SCB BusFault Address Register
 * 基地址: 0xE002ED00 (ARM_V8M_SCB_BASE_NS)
 * 参考: D1.1.23 System Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCB_BFAR_NS         0x038           /* SCB BusFault Address Register - BusFault 地址寄存器 [RW]
                                                          记录触发 BusFault 的地址
                                                          偏移：0x038 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 6.6 Non-secure SCB Auxiliary Fault Status Register
 * 基地址: 0xE002ED00 (ARM_V8M_SCB_BASE_NS)
 * 参考: D1.1.23 System Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCB_AFSR_NS         0x03C           /* SCB Auxiliary Fault Status Register - 辅助故障状态寄存器 [RW]
                                                          实现定义的附加故障状态信息
                                                          偏移：0x03C (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 6.7 Non-secure SCB Processor Feature Registers
 * 基地址: 0xE002ED00 (ARM_V8M_SCB_BASE_NS)
 * 参考: D1.1.23 System Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCB_ID_PFR0_NS      0x040           /* SCB Processor Feature Register 0 - 处理器特性寄存器 0 [RO]
                                                          提供处理器特性信息，如安全扩展、物理安全扩展等
                                                          偏移：0x040 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_ID_PFR1_NS      0x044           /* SCB Processor Feature Register 1 - 处理器特性寄存器 1 [RO]
                                                          提供处理器特性信息，如 M-profile 程序员模型
                                                          偏移：0x044 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_ID_DFR0_NS      0x048           /* SCB Debug Feature Register 0 - 调试特性寄存器 0 [RO]
                                                          提供调试特性信息，如调试模型、断点数量等
                                                          偏移：0x048 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_ID_AFR0_NS      0x04C           /* SCB Auxiliary Feature Register 0 - 辅助特性寄存器 0 [RO]
                                                          实现定义的附加特性信息
                                                          偏移：0x04C (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 6.8 Non-secure SCB Memory Model Feature Registers
 * 基地址: 0xE002ED00 (ARM_V8M_SCB_BASE_NS)
 * 参考: D1.1.23 System Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCB_ID_MMFR0_NS     0x050           /* SCB Memory Model Feature Register 0 - 内存模型特性寄存器 0 [RO]
                                                          提供内存模型特性信息，如 VMSA 支持、缓存支持等
                                                          偏移：0x050 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_ID_MMFR1_NS     0x054           /* SCB Memory Model Feature Register 1 - 内存模型特性寄存器 1 [RO]
                                                          提供内存模型特性信息
                                                          偏移：0x054 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_ID_MMFR2_NS     0x058           /* SCB Memory Model Feature Register 2 - 内存模型特性寄存器 2 [RO]
                                                          提供内存模型特性信息，如等待状态支持等
                                                          偏移：0x058 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_ID_MMFR3_NS     0x05C           /* SCB Memory Model Feature Register 3 - 内存模型特性寄存器 3 [RO]
                                                          提供内存模型特性信息，如缓存维护支持等
                                                          偏移：0x05C (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 6.9 Non-secure SCB Instruction Set Attribute Registers
 * 基地址: 0xE002ED00 (ARM_V8M_SCB_BASE_NS)
 * 参考: D1.1.23 System Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCB_ID_ISAR0_NS     0x060           /* SCB Instruction Set Attribute Register 0 - 指令集属性寄存器 0 [RO]
                                                          提供指令集特性信息，如除法指令支持等
                                                          偏移：0x060 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_ID_ISAR1_NS     0x064           /* SCB Instruction Set Attribute Register 1 - 指令集属性寄存器 1 [RO]
                                                          提供指令集特性信息，如调试支持等
                                                          偏移：0x064 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_ID_ISAR2_NS     0x068           /* SCB Instruction Set Attribute Register 2 - 指令集属性寄存器 2 [RO]
                                                          提供指令集特性信息，如乘累加支持等
                                                          偏移：0x068 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_ID_ISAR3_NS     0x06C           /* SCB Instruction Set Attribute Register 3 - 指令集属性寄存器 3 [RO]
                                                          提供指令集特性信息，如饱和运算支持等
                                                          偏移：0x06C (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_ID_ISAR4_NS     0x070           /* SCB Instruction Set Attribute Register 4 - 指令集属性寄存器 4 [RO]
                                                          提供指令集特性信息，如 SIMD 支持等
                                                          偏移：0x070 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_SCB_ID_ISAR5_NS     0x074           /* SCB Instruction Set Attribute Register 5 - 指令集属性寄存器 5 [RO]
                                                          提供指令集特性信息
                                                          偏移：0x074 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 6.10 Non-secure SCB Cache Level ID Register
 * 基地址: 0xE002ED00 (ARM_V8M_SCB_BASE_NS)
 * 参考: D1.1.23 System Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCB_CLIDR_NS        0x078           /* SCB Cache Level ID Register - 缓存级别 ID 寄存器 [RO]
                                                          提供缓存层次结构信息，包括统一缓存/独立缓存、缓存级别数等
                                                          偏移：0x078 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 6.11 Non-secure SCB Cache Type Register
 * 基地址: 0xE002ED00 (ARM_V8M_SCB_BASE_NS)
 * 参考: D1.1.23 System Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCB_CTR_NS          0x07C           /* SCB Cache Type Register - 缓存类型寄存器 [RO]
                                                          提供缓存特性信息，如缓存行大小、关联性等
                                                          偏移：0x07C (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 6.12 Non-secure SCB Cache Size Selection Register
 * 基地址: 0xE002ED00 (ARM_V8M_SCB_BASE_NS)
 * 参考: D1.1.23 System Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCB_CSSELR_NS       0x080           /* SCB Cache Size Selection Register - 缓存大小选择寄存器 [RW]
                                                          选择要访问的缓存级别和缓存类型（指令/数据）
                                                          偏移：0x080 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 6.13 Non-secure SCB Cache Size ID Register
 * 基地址: 0xE002ED00 (ARM_V8M_SCB_BASE_NS)
 * 参考: D1.1.23 System Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCB_CCSIDR_NS       0x084           /* SCB Current Cache Size ID Register - 当前缓存大小 ID 寄存器 [RO]
                                                          提供由 CSSELR 选择的缓存的详细信息
                                                          偏移：0x084 (相对于 ARM_V8M_SCB_BASE_NS)
                                                          参考：D1.1.23 System Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 6.14 Non-secure SCB 注意：CPACR 和 NSACR 不在 NS alias 中
 * 参考: D1.1.23 System Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
/* 注意：ARM_V8M_SCB_CPACR_NS 和 ARM_V8M_SCB_NSACR_NS 不存在
 * CPACR (0xE000ED88) 和 NSACR (0xE000ED8C) 仅在安全状态 SCB 中可访问
 * 参考：D1.1.23 System Control Block (NS alias) on page D1-1451
 * 非安全状态无法访问协处理器访问控制寄存器和安全状态控制寄存器 */

/* ==============================================================================
 * 七、非安全状态 MPU 寄存器偏移定义
 * 参考: D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 7.1 Non-secure MPU Type Register
 * 基地址: 0xE002ED90 (ARM_V8M_MPU_BASE_NS)
 * 参考: D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_MPU_TYPE_NS         0x000           /* MPU Type Register - MPU 类型寄存器 [RO]
                                                          提供 MPU 配置信息，包括区域数量和是否支持分离的指令/数据区域
                                                          偏移：0x000 (相对于 ARM_V8M_MPU_BASE_NS)
                                                          参考：D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 7.2 Non-secure MPU Control Register
 * 基地址: 0xE002ED90 (ARM_V8M_MPU_BASE_NS)
 * 参考: D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_MPU_CTRL_NS         0x004           /* MPU Control Register - MPU 控制寄存器 [RW]
                                                          使能/禁用 MPU，控制默认内存映射行为，以及是否在 HardFault 和 NMI 中使能 MPU
                                                          偏移：0x004 (相对于 ARM_V8M_MPU_BASE_NS)
                                                          参考：D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 7.3 Non-secure MPU Region Number Register
 * 基地址: 0xE002ED90 (ARM_V8M_MPU_BASE_NS)
 * 参考: D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_MPU_RNR_NS          0x008           /* MPU Region Number Register - MPU 区域编号寄存器 [RW]
                                                          选择要配置的 MPU 区域（0-7 或 0-15，取决于实现）
                                                          偏移：0x008 (相对于 ARM_V8M_MPU_BASE_NS)
                                                          参考：D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 7.4 Non-secure MPU Region Base Address Register
 * 基地址: 0xE002ED90 (ARM_V8M_MPU_BASE_NS)
 * 参考: D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_MPU_RBAR_NS         0x00C           /* MPU Region Base Address Register - MPU 区域基址寄存器 [RW]
                                                          定义选定 MPU 区域的基地址和区域属性
                                                          偏移：0x00C (相对于 ARM_V8M_MPU_BASE_NS)
                                                          参考：D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 7.5 Non-secure MPU Region Limit Address Register
 * 基地址: 0xE002ED90 (ARM_V8M_MPU_BASE_NS)
 * 参考: D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_MPU_RLAR_NS         0x010           /* MPU Region Limit Address Register - MPU 区域限制地址寄存器 [RW]
                                                          定义选定 MPU 区域的限制地址和属性索引
                                                          偏移：0x010 (相对于 ARM_V8M_MPU_BASE_NS)
                                                          参考：D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 7.6 Non-secure MPU Region Base Address Register Alias
 * 基地址: 0xE002ED90 (ARM_V8M_MPU_BASE_NS)
 * 参考: D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_MPU_RBAR_A1_NS      0x014           /* MPU Region Base Address Register Alias 1 - MPU 区域基址寄存器别名 1 [RW]
                                                          RBAR 的别名，用于快速配置多个区域
                                                          偏移：0x014 (相对于 ARM_V8M_MPU_BASE_NS)
                                                          参考：D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_MPU_RBAR_A2_NS      0x018           /* MPU Region Base Address Register Alias 2 - MPU 区域基址寄存器别名 2 [RW]
                                                          RBAR 的别名，用于快速配置多个区域
                                                          偏移：0x018 (相对于 ARM_V8M_MPU_BASE_NS)
                                                          参考：D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_MPU_RBAR_A3_NS      0x01C           /* MPU Region Base Address Register Alias 3 - MPU 区域基址寄存器别名 3 [RW]
                                                          RBAR 的别名，用于快速配置多个区域
                                                          偏移：0x01C (相对于 ARM_V8M_MPU_BASE_NS)
                                                          参考：D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 7.7 Non-secure MPU Region Limit Address Register Alias
 * 基地址: 0xE002ED90 (ARM_V8M_MPU_BASE_NS)
 * 参考: D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_MPU_RLAR_A1_NS      0x020           /* MPU Region Limit Address Register Alias 1 - MPU 区域限制地址寄存器别名 1 [RW]
                                                          RLAR 的别名，用于快速配置多个区域
                                                          偏移：0x020 (相对于 ARM_V8M_MPU_BASE_NS)
                                                          参考：D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_MPU_RLAR_A2_NS      0x024           /* MPU Region Limit Address Register Alias 2 - MPU 区域限制地址寄存器别名 2 [RW]
                                                          RLAR 的别名，用于快速配置多个区域
                                                          偏移：0x024 (相对于 ARM_V8M_MPU_BASE_NS)
                                                          参考：D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_MPU_RLAR_A3_NS      0x028           /* MPU Region Limit Address Register Alias 3 - MPU 区域限制地址寄存器别名 3 [RW]
                                                          RLAR 的别名，用于快速配置多个区域
                                                          偏移：0x028 (相对于 ARM_V8M_MPU_BASE_NS)
                                                          参考：D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 7.8 Non-secure MPU Memory Attribute Indirection Registers
 * 基地址: 0xE002ED90 (ARM_V8M_MPU_BASE_NS)
 * 参考: D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_MPU_MAIR0_NS        0x030           /* MPU Memory Attribute Indirection Register 0 - MPU 内存属性间接寄存器 0 [RW]
                                                          定义内存区域属性 0-3，用于映射到 MPU_RLAR 中的 AttrIndx 字段
                                                          偏移：0x030 (相对于 ARM_V8M_MPU_BASE_NS)
                                                          参考：D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_MPU_MAIR1_NS        0x034           /* MPU Memory Attribute Indirection Register 1 - MPU 内存属性间接寄存器 1 [RW]
                                                          定义内存区域属性 4-7，用于映射到 MPU_RLAR 中的 AttrIndx 字段
                                                          偏移：0x034 (相对于 ARM_V8M_MPU_BASE_NS)
                                                          参考：D1.1.24 Memory Protection Unit (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* ==============================================================================
 * 八、非安全状态 注意：SAU 寄存器仅在安全状态下可访问
 * 参考: D1.1.19 Security Attribution Unit on page D1-1449
 * ==============================================================================
 */
/* 注意：非安全状态没有 SAU 寄存器
 * SAU（Security Attribution Unit）仅在安全状态下可访问
 * 以下寄存器仅在安全状态下存在：
 * - SAU_CTRL, SAU_TYPE, SAU_RNR, SAU_RBAR, SAU_RLAR
 * - SCB_SFSR, SCB_SFAR
 * 参考：D1.1.19 Security Attribution Unit on page D1-1449
 * 非安全状态无法访问安全归属单元寄存器 */

/* ==============================================================================
 * 九、非安全状态 STIR 和 RFSR 寄存器偏移定义
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 9.1 Non-secure Software Triggered Interrupt Register
 * 基地址: 0xE002EF00 (ARM_V8M_STIR_BASE_NS)
 * 参考: D1.1.26 Software Interrupt Generation (NS alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_STIR_NS             0x000           /* Software Triggered Interrupt Register - 软件触发中断寄存器 [WO]
                                                          软件生成中断请求，写中断号触发对应中断
                                                          偏移：0x000 (相对于 ARM_V8M_STIR_BASE_NS)
                                                          参考：D1.1.26 Software Interrupt Generation (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 9.2 Non-secure RAS Fault Status Register
 * 基地址: 0xE002EF04 (ARM_V8M_RFSR_BASE_NS)
 * 参考: D1.1.27 RAS Extension Fault Status Register (NS Alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_RFSR_NS             0x000           /* RAS Fault Status Register - RAS 故障状态寄存器 [RW]
                                                          RAS（可靠性、可用性和可服务性）扩展的故障状态寄存器
                                                          偏移：0x000 (相对于 ARM_V8M_RFSR_BASE_NS)
                                                          参考：D1.1.27 RAS Extension Fault Status Register (NS Alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

/* ==============================================================================
 * 十、非安全状态 FPU 寄存器偏移定义
 * 参考: D1.1.28 Floating-Point Extension (NS alias) on page D1-1452
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 10.1 Non-secure Floating-Point Context Control Register
 * 基地址: 0xE002EF34 (ARM_V8M_FPU_BASE_NS)
 * 参考: D1.1.28 Floating-Point Extension (NS alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_FPU_FPCCR_NS        0x000           /* Floating-Point Context Control Register - 浮点上下文控制寄存器 [RW]
                                                          控制浮点上下文保存行为，包括延迟保存和自动保存
                                                          偏移：0x000 (相对于 ARM_V8M_FPU_BASE_NS)
                                                          参考：D1.1.28 Floating-Point Extension (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 10.2 Non-secure Floating-Point Context Address Register
 * 基地址: 0xE002EF34 (ARM_V8M_FPU_BASE_NS)
 * 参考: D1.1.28 Floating-Point Extension (NS alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_FPU_FPCAR_NS        0x004           /* Floating-Point Context Address Register - 浮点上下文地址寄存器 [RW]
                                                          保存浮点上下文保存的内存地址
                                                          偏移：0x004 (相对于 ARM_V8M_FPU_BASE_NS)
                                                          参考：D1.1.28 Floating-Point Extension (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 10.3 Non-secure Floating-Point Default Status Control Register
 * 基地址: 0xE002EF34 (ARM_V8M_FPU_BASE_NS)
 * 参考: D1.1.28 Floating-Point Extension (NS alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_FPU_FPDSCR_NS       0x008           /* Floating-Point Default Status Control Register - 浮点默认状态控制寄存器 [RW]
                                                          定义浮点运算的默认状态，包括舍入模式和异常陷阱使能
                                                          偏移：0x008 (相对于 ARM_V8M_FPU_BASE_NS)
                                                          参考：D1.1.28 Floating-Point Extension (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 10.4 Non-secure Media and VFP Feature Registers
 * 基地址: 0xE002EF34 (ARM_V8M_FPU_BASE_NS)
 * 参考: D1.1.28 Floating-Point Extension (NS alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_FPU_MVFR0_NS        0x00C           /* Media and VFP Feature Register 0 - 媒体和 VFP 特性寄存器 0 [RO]
                                                          提供 VFP 特性信息，如单精度/双精度支持、SIMD 支持等
                                                          偏移：0x00C (相对于 ARM_V8M_FPU_BASE_NS)
                                                          参考：D1.1.28 Floating-Point Extension (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_FPU_MVFR1_NS        0x010           /* Media and VFP Feature Register 1 - 媒体和 VFP 特性寄存器 1 [RO]
                                                          提供 VFP 特性信息，如半精度转换支持、NaN 处理等
                                                          偏移：0x010 (相对于 ARM_V8M_FPU_BASE_NS)
                                                          参考：D1.1.28 Floating-Point Extension (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_FPU_MVFR2_NS        0x014           /* Media and VFP Feature Register 2 - 媒体和 VFP 特性寄存器 2 [RO]
                                                          提供 VFP 特性信息，如杂项特性
                                                          偏移：0x014 (相对于 ARM_V8M_FPU_BASE_NS)
                                                          参考：D1.1.28 Floating-Point Extension (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

/* ==============================================================================
 * 十一、非安全状态 Cache Maintenance 寄存器偏移定义
 * 参考: D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 11.1 Non-secure Instruction Cache Invalidate All to Point of Unification
 * 基地址: 0xE002EF50 (ARM_V8M_CACHE_BASE_NS)
 * 参考: D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_ICIALLU_NS          0x000           /* I-Cache Invalidate All to PoU - 指令缓存全部无效化到统一点 [WO]
                                                          使指令缓存中的所有条目无效
                                                          偏移：0x000 (相对于 ARM_V8M_CACHE_BASE_NS)
                                                          参考：D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 11.2 Non-secure Instruction Cache Invalidate by MVA to Point of Unification
 * 基地址: 0xE002EF50 (ARM_V8M_CACHE_BASE_NS)
 * 参考: D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_ICIMVAU_NS          0x004           /* I-Cache Invalidate by MVA to PoU - 按 MVA 指令缓存无效化到统一点 [WO]
                                                          使与指定虚拟地址关联的指令缓存行无效
                                                          偏移：0x004 (相对于 ARM_V8M_CACHE_BASE_NS)
                                                          参考：D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 11.3 Non-secure Data Cache Invalidate by MVA to Point of Coherency
 * 基地址: 0xE002EF50 (ARM_V8M_CACHE_BASE_NS)
 * 参考: D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DCIMVAC_NS          0x008           /* D-Cache Invalidate by MVA to PoC - 按 MVA 数据缓存无效化到一致点 [WO]
                                                          使与指定虚拟地址关联的数据缓存行无效
                                                          偏移：0x008 (相对于 ARM_V8M_CACHE_BASE_NS)
                                                          参考：D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 11.4 Non-secure Data Cache Invalidate by Set/Way
 * 基地址: 0xE002EF50 (ARM_V8M_CACHE_BASE_NS)
 * 参考: D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DCISW_NS            0x00C           /* D-Cache Invalidate by Set/Way - 按 Set/Way 数据缓存无效化 [WO]
                                                          使由 set/way 指定的数据缓存行无效
                                                          偏移：0x00C (相对于 ARM_V8M_CACHE_BASE_NS)
                                                          参考：D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 11.5 Non-secure Data Cache Clean by MVA to Point of Unification
 * 基地址: 0xE002EF50 (ARM_V8M_CACHE_BASE_NS)
 * 参考: D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DCCMVAU_NS          0x010           /* D-Cache Clean by MVA to PoU - 按 MVA 数据缓存清理到统一点 [WO]
                                                          将与指定虚拟地址关联的数据缓存行清理到统一点
                                                          偏移：0x010 (相对于 ARM_V8M_CACHE_BASE_NS)
                                                          参考：D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 11.6 Non-secure Data Cache Clean by MVA to Point of Coherency
 * 基地址: 0xE002EF50 (ARM_V8M_CACHE_BASE_NS)
 * 参考: D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DCCMVAC_NS          0x014           /* D-Cache Clean by MVA to PoC - 按 MVA 数据缓存清理到一致点 [WO]
                                                          将与指定虚拟地址关联的数据缓存行清理到一致点
                                                          偏移：0x014 (相对于 ARM_V8M_CACHE_BASE_NS)
                                                          参考：D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 11.7 Non-secure Data Cache Clean by Set/Way
 * 基地址: 0xE002EF50 (ARM_V8M_CACHE_BASE_NS)
 * 参考: D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DCCSW_NS            0x018           /* D-Cache Clean by Set/Way - 按 Set/Way 数据缓存清理 [WO]
                                                          将由 set/way 指定的数据缓存行清理
                                                          偏移：0x018 (相对于 ARM_V8M_CACHE_BASE_NS)
                                                          参考：D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 11.8 Non-secure Data Cache Clean and Invalidate by MVA to Point of Coherency
 * 基地址: 0xE002EF50 (ARM_V8M_CACHE_BASE_NS)
 * 参考: D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DCCIMVAC_NS         0x01C           /* D-Cache Clean and Invalidate by MVA to PoC - 按 MVA 数据缓存清理并无效化到一致点 [WO]
                                                          将与指定虚拟地址关联的数据缓存行清理并无效化到一致点
                                                          偏移：0x01C (相对于 ARM_V8M_CACHE_BASE_NS)
                                                          参考：D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 11.9 Non-secure Data Cache Clean and Invalidate by Set/Way
 * 基地址: 0xE002EF50 (ARM_V8M_CACHE_BASE_NS)
 * 参考: D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DCCISW_NS           0x020           /* D-Cache Clean and Invalidate by Set/Way - 按 Set/Way 数据缓存清理并无效化 [WO]
                                                          将由 set/way 指定的数据缓存行清理并无效化
                                                          偏移：0x020 (相对于 ARM_V8M_CACHE_BASE_NS)
                                                          参考：D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 11.10 Non-secure Branch Predictor Invalidate All
 * 基地址: 0xE002EF50 (ARM_V8M_CACHE_BASE_NS)
 * 参考: D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_BPIALL_NS           0x024           /* Branch Predictor Invalidate All - 分支预测器全部无效化 [WO]
                                                          使分支预测器中的所有条目无效
                                                          偏移：0x024 (相对于 ARM_V8M_CACHE_BASE_NS)
                                                          参考：D1.1.29 Cache Maintenance Operations (NS alias) on page D1-1452
                                                          备注：与 Secure 实例银行化 */

/* ==============================================================================
 * 十二、非安全状态 Debug Identification 寄存器偏移定义
 * 参考: D1.1.30 Debug Identification Block (NS alias) on page D1-1453
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 12.1 Non-secure Debug Lock Access Register
 * 基地址: 0xE002EFB0 (ARM_V8M_DEBUG_ID_BASE_NS)
 * 参考: D1.1.30 Debug Identification Block (NS alias) on page D1-1453
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DEBUG_DLAR_NS       0x000           /* Debug Lock Access Register - 调试锁定访问寄存器 [WO]
                                                          用于锁定或解锁调试寄存器的访问
                                                          偏移：0x000 (相对于 ARM_V8M_DEBUG_ID_BASE_NS)
                                                          参考：D1.1.30 Debug Identification Block (NS alias) on page D1-1453
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 12.2 Non-secure Debug Lock Status Register
 * 基地址: 0xE002EFB0 (ARM_V8M_DEBUG_ID_BASE_NS)
 * 参考: D1.1.30 Debug Identification Block (NS alias) on page D1-1453
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DEBUG_DLSR_NS       0x004           /* Debug Lock Status Register - 调试锁定状态寄存器 [RO]
                                                          显示调试寄存器的锁定状态
                                                          偏移：0x004 (相对于 ARM_V8M_DEBUG_ID_BASE_NS)
                                                          参考：D1.1.30 Debug Identification Block (NS alias) on page D1-1453
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 12.3 Non-secure Debug Authentication Status Register
 * 基地址: 0xE002EFB0 (ARM_V8M_DEBUG_ID_BASE_NS)
 * 参考: D1.1.30 Debug Identification Block (NS alias) on page D1-1453
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DEBUG_DAUTHSTATUS_NS 0x008          /* Debug Authentication Status Register - 调试认证状态寄存器 [RO]
                                                          显示调试认证接口的状态
                                                          偏移：0x008 (相对于 ARM_V8M_DEBUG_ID_BASE_NS)
                                                          参考：D1.1.30 Debug Identification Block (NS alias) on page D1-1453
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 12.4 Non-secure Debug Device Architecture Register
 * 基地址: 0xE002EFB0 (ARM_V8M_DEBUG_ID_BASE_NS)
 * 参考: D1.1.30 Debug Identification Block (NS alias) on page D1-1453
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DEBUG_DDEVARCH_NS   0x00C           /* Debug Device Architecture Register - 调试设备架构寄存器 [RO]
                                                          标识调试组件的架构
                                                          偏移：0x00C (相对于 ARM_V8M_DEBUG_ID_BASE_NS)
                                                          参考：D1.1.30 Debug Identification Block (NS alias) on page D1-1453
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 12.5 Non-secure Debug Device Type Register
 * 基地址: 0xE002EFB0 (ARM_V8M_DEBUG_ID_BASE_NS)
 * 参考: D1.1.30 Debug Identification Block (NS alias) on page D1-1453
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DEBUG_DDEVTYPE_NS   0x010           /* Debug Device Type Register - 调试设备类型寄存器 [RO]
                                                          标识调试组件的类型
                                                          偏移：0x010 (相对于 ARM_V8M_DEBUG_ID_BASE_NS)
                                                          参考：D1.1.30 Debug Identification Block (NS alias) on page D1-1453
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 12.6 Non-secure Debug Peripheral Identification Registers
 * 基地址: 0xE002EFB0 (ARM_V8M_DEBUG_ID_BASE_NS)
 * 参考: D1.1.30 Debug Identification Block (NS alias) on page D1-1453
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DEBUG_DPIDR0_NS     0x014           /* Debug Peripheral ID Register 0 - 调试外设 ID 寄存器 0 [RO]
                                                          调试组件外设标识的一部分
                                                          偏移：0x014 (相对于 ARM_V8M_DEBUG_ID_BASE_NS)
                                                          参考：D1.1.30 Debug Identification Block (NS alias) on page D1-1453
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DEBUG_DPIDR1_NS     0x018           /* Debug Peripheral ID Register 1 - 调试外设 ID 寄存器 1 [RO]
                                                          调试组件外设标识的一部分
                                                          偏移：0x018 (相对于 ARM_V8M_DEBUG_ID_BASE_NS)
                                                          参考：D1.1.30 Debug Identification Block (NS alias) on page D1-1453
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DEBUG_DPIDR2_NS     0x01C           /* Debug Peripheral ID Register 2 - 调试外设 ID 寄存器 2 [RO]
                                                          调试组件外设标识的一部分
                                                          偏移：0x01C (相对于 ARM_V8M_DEBUG_ID_BASE_NS)
                                                          参考：D1.1.30 Debug Identification Block (NS alias) on page D1-1453
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DEBUG_DPIDR3_NS     0x020           /* Debug Peripheral ID Register 3 - 调试外设 ID 寄存器 3 [RO]
                                                          调试组件外设标识的一部分
                                                          偏移：0x020 (相对于 ARM_V8M_DEBUG_ID_BASE_NS)
                                                          参考：D1.1.30 Debug Identification Block (NS alias) on page D1-1453
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DEBUG_DPIDR4_NS     0x024           /* Debug Peripheral ID Register 4 - 调试外设 ID 寄存器 4 [RO]
                                                          调试组件外设标识的一部分
                                                          偏移：0x024 (相对于 ARM_V8M_DEBUG_ID_BASE_NS)
                                                          参考：D1.1.30 Debug Identification Block (NS alias) on page D1-1453
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DEBUG_DPIDR5_NS     0x028           /* Debug Peripheral ID Register 5 - 调试外设 ID 寄存器 5 [RO]
                                                          调试组件外设标识的一部分
                                                          偏移：0x028 (相对于 ARM_V8M_DEBUG_ID_BASE_NS)
                                                          参考：D1.1.30 Debug Identification Block (NS alias) on page D1-1453
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DEBUG_DPIDR6_NS     0x02C           /* Debug Peripheral ID Register 6 - 调试外设 ID 寄存器 6 [RO]
                                                          调试组件外设标识的一部分
                                                          偏移：0x02C (相对于 ARM_V8M_DEBUG_ID_BASE_NS)
                                                          参考：D1.1.30 Debug Identification Block (NS alias) on page D1-1453
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DEBUG_DPIDR7_NS     0x030           /* Debug Peripheral ID Register 7 - 调试外设 ID 寄存器 7 [RO]
                                                          调试组件外设标识的一部分
                                                          偏移：0x030 (相对于 ARM_V8M_DEBUG_ID_BASE_NS)
                                                          参考：D1.1.30 Debug Identification Block (NS alias) on page D1-1453
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 12.7 Non-secure Debug Component Identification Registers
 * 基地址: 0xE002EFB0 (ARM_V8M_DEBUG_ID_BASE_NS)
 * 参考: D1.1.30 Debug Identification Block (NS alias) on page D1-1453
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DEBUG_DCIDR0_NS     0x034           /* Debug Component ID Register 0 - 调试组件 ID 寄存器 0 [RO]
                                                          调试组件标识的一部分
                                                          偏移：0x034 (相对于 ARM_V8M_DEBUG_ID_BASE_NS)
                                                          参考：D1.1.30 Debug Identification Block (NS alias) on page D1-1453
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DEBUG_DCIDR1_NS     0x038           /* Debug Component ID Register 1 - 调试组件 ID 寄存器 1 [RO]
                                                          调试组件标识的一部分
                                                          偏移：0x038 (相对于 ARM_V8M_DEBUG_ID_BASE_NS)
                                                          参考：D1.1.30 Debug Identification Block (NS alias) on page D1-1453
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DEBUG_DCIDR2_NS     0x03C           /* Debug Component ID Register 2 - 调试组件 ID 寄存器 2 [RO]
                                                          调试组件标识的一部分
                                                          偏移：0x03C (相对于 ARM_V8M_DEBUG_ID_BASE_NS)
                                                          参考：D1.1.30 Debug Identification Block (NS alias) on page D1-1453
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DEBUG_DCIDR3_NS     0x040           /* Debug Component ID Register 3 - 调试组件 ID 寄存器 3 [RO]
                                                          调试组件标识的一部分
                                                          偏移：0x040 (相对于 ARM_V8M_DEBUG_ID_BASE_NS)
                                                          参考：D1.1.30 Debug Identification Block (NS alias) on page D1-1453
                                                          备注：与 Secure 实例银行化 */

/* ==============================================================================
 * 十三、非安全状态 Debug Control Block 寄存器偏移定义
 * 参考: D1.1.25 Debug Control Block (NS alias) on page D1-1451
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 13.1 Non-secure Debug Halting Control and Status Register
 * 基地址: 0xE002EDF0 (ARM_V8M_DEBUG_BASE_NS)
 * 参考: D1.1.25 Debug Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DHCSR_NS            0x000           /* Debug Halting Control and Status Register - 调试停止控制和状态寄存器 [RW]
                                                          控制调试停止模式和查看处理器状态
                                                          偏移：0x000 (相对于 ARM_V8M_DEBUG_BASE_NS)
                                                          参考：D1.1.25 Debug Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 13.2 Non-secure Debug Core Register Data Register
 * 基地址: 0xE002EDF0 (ARM_V8M_DEBUG_BASE_NS)
 * 参考: D1.1.25 Debug Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DCRDR_NS            0x004           /* Debug Core Register Data Register - 调试核心寄存器数据寄存器 [RW]
                                                          用于读写处理器核心寄存器的数据
                                                          偏移：0x004 (相对于 ARM_V8M_DEBUG_BASE_NS)
                                                          参考：D1.1.25 Debug Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 13.3 Non-secure Debug Exception and Monitor Control Register
 * 基地址: 0xE002EDF0 (ARM_V8M_DEBUG_BASE_NS)
 * 参考: D1.1.25 Debug Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DEMCR_NS            0x008           /* Debug Exception and Monitor Control Register - 调试异常和监视器控制寄存器 [RW]
                                                          控制调试异常行为和监视器模式
                                                          偏移：0x008 (相对于 ARM_V8M_DEBUG_BASE_NS)
                                                          参考：D1.1.25 Debug Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 13.4 Non-secure Debug Set Clear Exception and Monitor Control Register
 * 基地址: 0xE002EDF0 (ARM_V8M_DEBUG_BASE_NS)
 * 参考: D1.1.25 Debug Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DSCEMCR_NS          0x00C           /* Debug Set Clear Exception and Monitor Control Register - 调试设置清除异常和监视器控制寄存器 [RW]
                                                          用于设置和清除调试异常和监视器控制位
                                                          偏移：0x00C (相对于 ARM_V8M_DEBUG_BASE_NS)
                                                          参考：D1.1.25 Debug Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 13.5 Non-secure Debug Authentication Control Register
 * 基地址: 0xE002EDF0 (ARM_V8M_DEBUG_BASE_NS)
 * 参考: D1.1.25 Debug Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DAUTHCTRL_NS        0x010           /* Debug Authentication Control Register - 调试认证控制寄存器 [RW]
                                                          控制调试认证行为
                                                          偏移：0x010 (相对于 ARM_V8M_DEBUG_BASE_NS)
                                                          参考：D1.1.25 Debug Control Block (NS alias) on page D1-1451
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 13.6 Non-secure Debug 注意：DCRSR 和 DSCSR 仅在安全调试控制块中存在
 * 参考: D1.1.25 Debug Control Block (NS alias) on page D1-1451
 * -----------------------------------------------------------------------------
 */
/* 注意：ARM_V8M_DCRSR_NS 和 ARM_V8M_DSCSR_NS 不存在
 * DCRSR (0xE000EDF4) 和 DSCSR (0xE000EE08) 仅在安全调试控制块中存在
 * 参考：D1.1.25 Debug Control Block (NS alias) on page D1-1451
 * 非安全状态无法访问调试核心寄存器选择寄存器和调试安全和核心状态寄存器 */

/* ==============================================================================
 * 十四、非安全状态 ITM 寄存器偏移定义
 * 参考: D1.1.3 Instrumentation Macrocell on page D1-1444
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 14.1 Non-secure ITM Stimulus Port Registers
 * 基地址: 0xE0020000 (ARM_V8M_ITM_BASE_NS)
 * 参考: D1.1.3 Instrumentation Macrocell on page D1-1444
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_ITM_STIM0_NS        0x000           /* ITM Stimulus Port Register 0 - ITM 激励端口寄存器 0 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x000 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM1_NS        0x004           /* ITM Stimulus Port Register 1 - ITM 激励端口寄存器 1 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x004 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM2_NS        0x008           /* ITM Stimulus Port Register 2 - ITM 激励端口寄存器 2 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x008 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM3_NS        0x00C           /* ITM Stimulus Port Register 3 - ITM 激励端口寄存器 3 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x00C (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM4_NS        0x010           /* ITM Stimulus Port Register 4 - ITM 激励端口寄存器 4 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x010 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM5_NS        0x014           /* ITM Stimulus Port Register 5 - ITM 激励端口寄存器 5 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x014 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM6_NS        0x018           /* ITM Stimulus Port Register 6 - ITM 激励端口寄存器 6 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x018 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM7_NS        0x01C           /* ITM Stimulus Port Register 7 - ITM 激励端口寄存器 7 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x01C (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM8_NS        0x020           /* ITM Stimulus Port Register 8 - ITM 激励端口寄存器 8 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x020 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM9_NS        0x024           /* ITM Stimulus Port Register 9 - ITM 激励端口寄存器 9 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x024 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM10_NS       0x028           /* ITM Stimulus Port Register 10 - ITM 激励端口寄存器 10 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x028 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM11_NS       0x02C           /* ITM Stimulus Port Register 11 - ITM 激励端口寄存器 11 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x02C (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM12_NS       0x030           /* ITM Stimulus Port Register 12 - ITM 激励端口寄存器 12 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x030 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM13_NS       0x034           /* ITM Stimulus Port Register 13 - ITM 激励端口寄存器 13 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x034 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM14_NS       0x038           /* ITM Stimulus Port Register 14 - ITM 激励端口寄存器 14 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x038 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM15_NS       0x03C           /* ITM Stimulus Port Register 15 - ITM 激励端口寄存器 15 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x03C (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM16_NS       0x040           /* ITM Stimulus Port Register 16 - ITM 激励端口寄存器 16 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x040 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM17_NS       0x044           /* ITM Stimulus Port Register 17 - ITM 激励端口寄存器 17 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x044 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM18_NS       0x048           /* ITM Stimulus Port Register 18 - ITM 激励端口寄存器 18 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x048 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM19_NS       0x04C           /* ITM Stimulus Port Register 19 - ITM 激励端口寄存器 19 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x04C (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM20_NS       0x050           /* ITM Stimulus Port Register 20 - ITM 激励端口寄存器 20 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x050 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM21_NS       0x054           /* ITM Stimulus Port Register 21 - ITM 激励端口寄存器 21 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x054 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM22_NS       0x058           /* ITM Stimulus Port Register 22 - ITM 激励端口寄存器 22 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x058 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM23_NS       0x05C           /* ITM Stimulus Port Register 23 - ITM 激励端口寄存器 23 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x05C (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM24_NS       0x060           /* ITM Stimulus Port Register 24 - ITM 激励端口寄存器 24 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x060 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM25_NS       0x064           /* ITM Stimulus Port Register 25 - ITM 激励端口寄存器 25 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x064 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM26_NS       0x068           /* ITM Stimulus Port Register 26 - ITM 激励端口寄存器 26 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x068 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM27_NS       0x06C           /* ITM Stimulus Port Register 27 - ITM 激励端口寄存器 27 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x06C (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM28_NS       0x070           /* ITM Stimulus Port Register 28 - ITM 激励端口寄存器 28 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x070 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM29_NS       0x074           /* ITM Stimulus Port Register 29 - ITM 激励端口寄存器 29 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x074 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM30_NS       0x078           /* ITM Stimulus Port Register 30 - ITM 激励端口寄存器 30 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x078 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_ITM_STIM31_NS       0x07C           /* ITM Stimulus Port Register 31 - ITM 激励端口寄存器 31 [RW]
                                                          用于软件生成跟踪数据的激励端口
                                                          偏移：0x07C (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 14.2 Non-secure ITM Trace Enable Registers
 * 基地址: 0xE0020000 (ARM_V8M_ITM_BASE_NS)
 * 参考: D1.1.3 Instrumentation Macrocell on page D1-1444
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_ITM_TER_NS          0xE00           /* ITM Trace Enable Register - ITM 跟踪使能寄存器 [RW]
                                                          控制哪些激励端口可以生成跟踪数据
                                                          偏移：0xE00 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 14.3 Non-secure ITM Trace Privilege Register
 * 基地址: 0xE0020000 (ARM_V8M_ITM_BASE_NS)
 * 参考: D1.1.3 Instrumentation Macrocell on page D1-1444
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_ITM_TPR_NS          0xE40           /* ITM Trace Privilege Register - ITM 跟踪特权寄存器 [RW]
                                                          控制激励端口的特权访问级别
                                                          偏移：0xE40 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 14.4 Non-secure ITM Trace Control Register
 * 基地址: 0xE0020000 (ARM_V8M_ITM_BASE_NS)
 * 参考: D1.1.3 Instrumentation Macrocell on page D1-1444
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_ITM_TCR_NS          0xE80           /* ITM Trace Control Register - ITM 跟踪控制寄存器 [RW]
                                                          控制 ITM 的全局行为，如使能 ITM、设置时间戳预分频等
                                                          偏移：0xE80 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 14.5 Non-secure ITM Lock Access Register
 * 基地址: 0xE0020000 (ARM_V8M_ITM_BASE_NS)
 * 参考: D1.1.3 Instrumentation Macrocell on page D1-1444
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_ITM_LAR_NS          0xFB0           /* ITM Lock Access Register - ITM 锁定访问寄存器 [WO]
                                                          用于锁定或解锁 ITM 寄存器的访问
                                                          偏移：0xFB0 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 14.6 Non-secure ITM Lock Status Register
 * 基地址: 0xE0020000 (ARM_V8M_ITM_BASE_NS)
 * 参考: D1.1.3 Instrumentation Macrocell on page D1-1444
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_ITM_LSR_NS          0xFB4           /* ITM Lock Status Register - ITM 锁定状态寄存器 [RO]
                                                          显示 ITM 寄存器的锁定状态
                                                          偏移：0xFB4 (相对于 ARM_V8M_ITM_BASE_NS)
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Secure 实例银行化 */

/* ==============================================================================
 * 十五、非安全状态 DWT 寄存器偏移定义
 * 参考: D1.1.4 Data Watchpoint and Trace on page D1-1445
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 15.1 Non-secure DWT Control Register
 * 基地址: 0xE0021000 (ARM_V8M_DWT_BASE_NS)
 * 参考: D1.1.4 Data Watchpoint and Trace on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DWT_CTRL_NS         0x000           /* DWT Control Register - DWT 控制寄存器 [RW]
                                                          控制 DWT 的全局行为，如使能 DWT、设置周期计数器等
                                                          偏移：0x000 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 15.2 Non-secure DWT Cycle Count Register
 * 基地址: 0xE0021000 (ARM_V8M_DWT_BASE_NS)
 * 参考: D1.1.4 Data Watchpoint and Trace on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DWT_CYCCNT_NS       0x004           /* DWT Cycle Count Register - DWT 周期计数寄存器 [RW]
                                                          记录处理器执行的周期数
                                                          偏移：0x004 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 15.3 Non-secure DWT CPI Count Register
 * 基地址: 0xE0021000 (ARM_V8M_DWT_BASE_NS)
 * 参考: D1.1.4 Data Watchpoint and Trace on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DWT_CPICNT_NS       0x008           /* DWT CPI Count Register - DWT CPI 计数寄存器 [RW]
                                                          记录额外周期数（CPI - Cycles Per Instruction）
                                                          偏移：0x008 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 15.4 Non-secure DWT Exception Overhead Count Register
 * 基地址: 0xE0021000 (ARM_V8M_DWT_BASE_NS)
 * 参考: D1.1.4 Data Watchpoint and Trace on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DWT_EXCCNT_NS       0x00C           /* DWT Exception Overhead Count Register - DWT 异常开销计数寄存器 [RW]
                                                          记录异常处理的开销周期数
                                                          偏移：0x00C (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 15.5 Non-secure DWT Sleep Count Register
 * 基地址: 0xE0021000 (ARM_V8M_DWT_BASE_NS)
 * 参考: D1.1.4 Data Watchpoint and Trace on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DWT_SLEEPCNT_NS     0x010           /* DWT Sleep Count Register - DWT 睡眠计数寄存器 [RW]
                                                          记录处理器处于睡眠状态的周期数
                                                          偏移：0x010 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 15.6 Non-secure DWT LSU Count Register
 * 基地址: 0xE0021000 (ARM_V8M_DWT_BASE_NS)
 * 参考: D1.1.4 Data Watchpoint and Trace on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DWT_LSUCNT_NS       0x014           /* DWT LSU Count Register - DWT LSU 计数寄存器 [RW]
                                                          记录加载存储单元（LSU）的额外周期数
                                                          偏移：0x014 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 15.7 Non-secure DWT Fold Count Register
 * 基地址: 0xE0021000 (ARM_V8M_DWT_BASE_NS)
 * 参考: D1.1.4 Data Watchpoint and Trace on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DWT_FOLDCNT_NS      0x018           /* DWT Fold Count Register - DWT 折叠计数寄存器 [RW]
                                                          记录折叠指令的周期数
                                                          偏移：0x018 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 15.8 Non-secure DWT Program Counter Sample Register
 * 基地址: 0xE0021000 (ARM_V8M_DWT_BASE_NS)
 * 参考: D1.1.4 Data Watchpoint and Trace on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DWT_PCSR_NS         0x01C           /* DWT Program Counter Sample Register - DWT 程序计数器采样寄存器 [RO]
                                                          记录程序计数器的采样值，用于性能分析
                                                          偏移：0x01C (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 15.9 Non-secure DWT Comparator Registers
 * 基地址: 0xE0021000 (ARM_V8M_DWT_BASE_NS)
 * 参考: D1.1.4 Data Watchpoint and Trace on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DWT_COMP0_NS        0x020           /* DWT Comparator Register 0 - DWT 比较器寄存器 0 [RW]
                                                          数据观察点比较器的比较值
                                                          偏移：0x020 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DWT_MASK0_NS        0x024           /* DWT Mask Register 0 - DWT 掩码寄存器 0 [RW]
                                                          数据观察点比较器的地址掩码
                                                          偏移：0x024 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DWT_FUNCTION0_NS    0x028           /* DWT Function Register 0 - DWT 功能寄存器 0 [RW]
                                                          控制比较器的行为，如比较类型、操作等
                                                          偏移：0x028 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DWT_COMP1_NS        0x030           /* DWT Comparator Register 1 - DWT 比较器寄存器 1 [RW]
                                                          数据观察点比较器的比较值
                                                          偏移：0x030 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DWT_MASK1_NS        0x034           /* DWT Mask Register 1 - DWT 掩码寄存器 1 [RW]
                                                          数据观察点比较器的地址掩码
                                                          偏移：0x034 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DWT_FUNCTION1_NS    0x038           /* DWT Function Register 1 - DWT 功能寄存器 1 [RW]
                                                          控制比较器的行为，如比较类型、操作等
                                                          偏移：0x038 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DWT_COMP2_NS        0x040           /* DWT Comparator Register 2 - DWT 比较器寄存器 2 [RW]
                                                          数据观察点比较器的比较值
                                                          偏移：0x040 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DWT_MASK2_NS        0x044           /* DWT Mask Register 2 - DWT 掩码寄存器 2 [RW]
                                                          数据观察点比较器的地址掩码
                                                          偏移：0x044 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DWT_FUNCTION2_NS    0x048           /* DWT Function Register 2 - DWT 功能寄存器 2 [RW]
                                                          控制比较器的行为，如比较类型、操作等
                                                          偏移：0x048 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DWT_COMP3_NS        0x050           /* DWT Comparator Register 3 - DWT 比较器寄存器 3 [RW]
                                                          数据观察点比较器的比较值
                                                          偏移：0x050 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DWT_MASK3_NS        0x054           /* DWT Mask Register 3 - DWT 掩码寄存器 3 [RW]
                                                          数据观察点比较器的地址掩码
                                                          偏移：0x054 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DWT_FUNCTION3_NS    0x058           /* DWT Function Register 3 - DWT 功能寄存器 3 [RW]
                                                          控制比较器的行为，如比较类型、操作等
                                                          偏移：0x058 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 15.10 Non-secure DVT Comparator Value Mask Registers
 * 基地址: 0xE0021000 (ARM_V8M_DWT_BASE_NS)
 * 参考: D1.1.4 Data Watchpoint and Trace on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DWT_VMASK0_NS       0x060           /* DWT Comparator Value Mask Register 0 - DWT 比较器值掩码寄存器 0 [RW]
                                                          数据值比较掩码
                                                          偏移：0x060 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DWT_VMASK1_NS       0x064           /* DWT Comparator Value Mask Register 1 - DWT 比较器值掩码寄存器 1 [RW]
                                                          数据值比较掩码
                                                          偏移：0x064 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DWT_VMASK2_NS       0x068           /* DWT Comparator Value Mask Register 2 - DWT 比较器值掩码寄存器 2 [RW]
                                                          数据值比较掩码
                                                          偏移：0x068 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_DWT_VMASK3_NS       0x06C           /* DWT Comparator Value Mask Register 3 - DWT 比较器值掩码寄存器 3 [RW]
                                                          数据值比较掩码
                                                          偏移：0x06C (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 15.11 Non-secure DWT Lock Access Register
 * 基地址: 0xE0021000 (ARM_V8M_DWT_BASE_NS)
 * 参考: D1.1.4 Data Watchpoint and Trace on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DWT_LAR_NS          0xFB0           /* DWT Lock Access Register - DWT 锁定访问寄存器 [WO]
                                                          用于锁定或解锁 DWT 寄存器的访问
                                                          偏移：0xFB0 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 15.12 Non-secure DWT Lock Status Register
 * 基地址: 0xE0021000 (ARM_V8M_DWT_BASE_NS)
 * 参考: D1.1.4 Data Watchpoint and Trace on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DWT_LSR_NS          0xFB4           /* DWT Lock Status Register - DWT 锁定状态寄存器 [RO]
                                                          显示 DWT 寄存器的锁定状态
                                                          偏移：0xFB4 (相对于 ARM_V8M_DWT_BASE_NS)
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* ==============================================================================
 * 十六、非安全状态 FPB 寄存器偏移定义
 * 参考: D1.1.5 Flash Patch and Breakpoint on page D1-1445
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 16.1 Non-secure FPB Control Register
 * 基地址: 0xE0022000 (ARM_V8M_FPB_BASE_NS)
 * 参考: D1.1.5 Flash Patch and Breakpoint on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_FP_CTRL_NS          0x000           /* Flash Patch Control Register - Flash Patch 控制寄存器 [RW]
                                                          控制 FPB 的全局行为，如使能 FPB、设置断点数量等
                                                          偏移：0x000 (相对于 ARM_V8M_FPB_BASE_NS)
                                                          参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 16.2 Non-secure FPB Remap Register
 * 基地址: 0xE0022000 (ARM_V8M_FPB_BASE_NS)
 * 参考: D1.1.5 Flash Patch and Breakpoint on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_FP_REMAP_NS         0x004           /* Flash Patch Remap Register - Flash Patch 重映射寄存器 [RW]
                                                          定义重映射区域的基地址
                                                          偏移：0x004 (相对于 ARM_V8M_FPB_BASE_NS)
                                                          参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 16.3 Non-secure FPB Comparator Registers
 * 基地址: 0xE0022000 (ARM_V8M_FPB_BASE_NS)
 * 参考: D1.1.5 Flash Patch and Breakpoint on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_FP_COMP0_NS         0x008           /* Flash Patch Comparator Register 0 - Flash Patch 比较器寄存器 0 [RW]
                                                          定义断点或重映射的地址
                                                          偏移：0x008 (相对于 ARM_V8M_FPB_BASE_NS)
                                                          参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_FP_COMP1_NS         0x00C           /* Flash Patch Comparator Register 1 - Flash Patch 比较器寄存器 1 [RW]
                                                          定义断点或重映射的地址
                                                          偏移：0x00C (相对于 ARM_V8M_FPB_BASE_NS)
                                                          参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_FP_COMP2_NS         0x010           /* Flash Patch Comparator Register 2 - Flash Patch 比较器寄存器 2 [RW]
                                                          定义断点或重映射的地址
                                                          偏移：0x010 (相对于 ARM_V8M_FPB_BASE_NS)
                                                          参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_FP_COMP3_NS         0x014           /* Flash Patch Comparator Register 3 - Flash Patch 比较器寄存器 3 [RW]
                                                          定义断点或重映射的地址
                                                          偏移：0x014 (相对于 ARM_V8M_FPB_BASE_NS)
                                                          参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_FP_COMP4_NS         0x018           /* Flash Patch Comparator Register 4 - Flash Patch 比较器寄存器 4 [RW]
                                                          定义断点或重映射的地址
                                                          偏移：0x018 (相对于 ARM_V8M_FPB_BASE_NS)
                                                          参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_FP_COMP5_NS         0x01C           /* Flash Patch Comparator Register 5 - Flash Patch 比较器寄存器 5 [RW]
                                                          定义断点或重映射的地址
                                                          偏移：0x01C (相对于 ARM_V8M_FPB_BASE_NS)
                                                          参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_FP_COMP6_NS         0x020           /* Flash Patch Comparator Register 6 - Flash Patch 比较器寄存器 6 [RW]
                                                          定义断点或重映射的地址
                                                          偏移：0x020 (相对于 ARM_V8M_FPB_BASE_NS)
                                                          参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_FP_COMP7_NS         0x024           /* Flash Patch Comparator Register 7 - Flash Patch 比较器寄存器 7 [RW]
                                                          定义断点或重映射的地址
                                                          偏移：0x024 (相对于 ARM_V8M_FPB_BASE_NS)
                                                          参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 16.4 Non-secure FPB Lock Access Register
 * 基地址: 0xE0022000 (ARM_V8M_FPB_BASE_NS)
 * 参考: D1.1.5 Flash Patch and Breakpoint on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_FP_LAR_NS           0xFB0           /* FPB Lock Access Register - FPB 锁定访问寄存器 [WO]
                                                          用于锁定或解锁 FPB 寄存器的访问
                                                          偏移：0xFB0 (相对于 ARM_V8M_FPB_BASE_NS)
                                                          参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 16.5 Non-secure FPB Lock Status Register
 * 基地址: 0xE0022000 (ARM_V8M_FPB_BASE_NS)
 * 参考: D1.1.5 Flash Patch and Breakpoint on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_FP_LSR_NS           0xFB4           /* FPB Lock Status Register - FPB 锁定状态寄存器 [RO]
                                                          显示 FPB 寄存器的锁定状态
                                                          偏移：0xFB4 (相对于 ARM_V8M_FPB_BASE_NS)
                                                          参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* ==============================================================================
 * 十七、非安全状态 PMU 寄存器偏移定义
 * 参考: D1.1.6 Performance Monitoring Unit on page D1-1445
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 17.1 Non-secure PMU Event Counter Registers
 * 基地址: 0xE0023000 (ARM_V8M_PMU_BASE_NS)
 * 参考: D1.1.6 Performance Monitoring Unit on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_PMU_EVCNTR0_NS      0x000           /* PMU Event Counter Register 0 - PMU 事件计数器寄存器 0 [RW]
                                                          记录特定事件的计数
                                                          偏移：0x000 (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_PMU_EVCNTR1_NS      0x004           /* PMU Event Counter Register 1 - PMU 事件计数器寄存器 1 [RW]
                                                          记录特定事件的计数
                                                          偏移：0x004 (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_PMU_EVCNTR2_NS      0x008           /* PMU Event Counter Register 2 - PMU 事件计数器寄存器 2 [RW]
                                                          记录特定事件的计数
                                                          偏移：0x008 (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_PMU_EVCNTR3_NS      0x00C           /* PMU Event Counter Register 3 - PMU 事件计数器寄存器 3 [RW]
                                                          记录特定事件的计数
                                                          偏移：0x00C (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 17.2 Non-secure PMU Cycle Counter Register
 * 基地址: 0xE0023000 (ARM_V8M_PMU_BASE_NS)
 * 参考: D1.1.6 Performance Monitoring Unit on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_PMU_CCNT_NS         0x07C           /* PMU Cycle Counter Register - PMU 周期计数寄存器 [RW]
                                                          记录处理器周期数
                                                          偏移：0x07C (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 17.3 Non-secure PMU Event Type Selection Registers
 * 基地址: 0xE0023000 (ARM_V8M_PMU_BASE_NS)
 * 参考: D1.1.6 Performance Monitoring Unit on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_PMU_EVTYPER0_NS     0x400           /* PMU Event Type Select Register 0 - PMU 事件类型选择寄存器 0 [RW]
                                                          选择事件计数器 0 要计数的事件类型
                                                          偏移：0x400 (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_PMU_EVTYPER1_NS     0x404           /* PMU Event Type Select Register 1 - PMU 事件类型选择寄存器 1 [RW]
                                                          选择事件计数器 1 要计数的事件类型
                                                          偏移：0x404 (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_PMU_EVTYPER2_NS     0x408           /* PMU Event Type Select Register 2 - PMU 事件类型选择寄存器 2 [RW]
                                                          选择事件计数器 2 要计数的事件类型
                                                          偏移：0x408 (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

#define ARM_V8M_PMU_EVTYPER3_NS     0x40C           /* PMU Event Type Select Register 3 - PMU 事件类型选择寄存器 3 [RW]
                                                          选择事件计数器 3 要计数的事件类型
                                                          偏移：0x40C (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 17.4 Non-secure PMU Cycle Counter Filter Register
 * 基地址: 0xE0023000 (ARM_V8M_PMU_BASE_NS)
 * 参考: D1.1.6 Performance Monitoring Unit on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_PMU_CCFILTR_NS      0x47C           /* PMU Cycle Counter Filter Register - PMU 周期计数器过滤器寄存器 [RW]
                                                          控制周期计数器的增量过滤
                                                          偏移：0x47C (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 17.5 Non-secure PMU Count Enable Set Register
 * 基地址: 0xE0023000 (ARM_V8M_PMU_BASE_NS)
 * 参考: D1.1.6 Performance Monitoring Unit on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_PMU_CNTENSET_NS     0xC00           /* PMU Count Enable Set Register - PMU 计数使能设置寄存器 [RW]
                                                          使能事件计数器，写 1 使能对应计数器
                                                          偏移：0xC00 (相对于 ARM_V8M_PMU_BASE_NS)
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Secure 实例银行化 */

/* -----------------------------------------------------------------------------
 * 17.6 Non-secure PMU Count Enable Clear Register
 * 基地址: 0xE0023000 (ARM_V8M_PMU_BASE_NS)
 * 参考: D1.1.6 Performance Monitoring Unit on page D1-1445
 * -----------------------------------------------------------------------------
 */
#define