/********************************************************************************
 * @file        arm_v8m_core_safe.h
 * @brief       ARMv8-M Architecture Secure State Register Definitions
 * @details     基于 ARMv8-M Architecture Reference Manual (ARM DDI 0553B.z)
 *              所有寄存器定义严格参考手册章节位置
 *              文档路径：g:\develop\FeatherCore\FeatherArch\docs\arm\Arm® v8-M Architecture Reference Manual.txt
 * @author      FeatherCore
 * @version     1.0.0
 * @date        2026-03-29
 * @note        本文件包含安全状态寄存器完整定义
 *              包括基地址和每个寄存器的详细描述
 *              位域定义在单独的头文件中
 *
 * 安全状态寄存器清单（基于 D1.1 Register index）：
 * - Secure SCS Base: 0xE000E000
 *   - ICB (ICTR, ACTLR, CPPWR): 基地址 0xE000E004
 *     参考: D1.1.8 Implementation Control Block on page D1-1447
 *   - SysTick (SYST_CSR, SYST_RVR, SYST_CVR, SYST_CALIB): 基地址 0xE000E010
 *     参考: D1.1.9 SysTick Timer on page D1-1447
 *   - NVIC (NVIC_ISER, NVIC_ICER, NVIC_ISPR, NVIC_ICPR, NVIC_IABR, NVIC_ITNS, NVIC_IPR): 基地址 0xE000E100
 *     参考: D1.1.10 Nested Vectored Interrupt Controller on page D1-1447
 *   - SCB (CPUID, ICSR, VTOR, AIRCR, SCR, CCR, SHPR1-3, SHCSR, CFSR, HFSR, DFSR,
 *          MMFAR, BFAR, AFSR, ID_PFR0-1, ID_DFR0, ID_AFR0, ID_MMFR0-3, ID_ISAR0-5,
 *          CLIDR, CTR, CCSIDR, CSSELR, CPACR, NSACR): 基地址 0xE000ED00
 *     参考: D1.1.11 System Control Block on page D1-1447
 *   - REVIDR: 绝对地址 0xE000ECFC (位于 SCB 基地址之前)
 *     参考: D1.1.11 System Control Block on page D1-1447
 *   - MPU (MPU_TYPE, MPU_CTRL, MPU_RNR, MPU_RBAR, MPU_RLAR, MPU_RBAR_A1-A3, MPU_RLAR_A1-A3,
 *          MPU_MAIR0-1): 基地址 0xE000ED90
 *     参考: D1.1.12 Memory Protection Unit on page D1-1448
 *   - SAU (SAU_CTRL, SAU_TYPE, SAU_RNR, SAU_RBAR, SAU_RLAR, SFSR, SFAR): 基地址 0xE000EDD0
 *     参考: D1.1.13 Security Attribution Unit on page D1-1448
 *     备注: SAU 仅在安全状态下可访问，非安全状态下访问为 RAZ/WI
 *   - Debug (DHCSR, DCRSR, DCRDR, DEMCR, DSCEMCR, DAUTHCTRL, DSCSR): 基地址 0xE000EDF0
 *     参考: D1.1.14 Debug Control Block on page D1-1449
 *     备注: DCRSR 和 DSCSR 仅在安全状态下可访问
 *   - Debug Identification (DLAR, DLSR, DAUTHSTATUS, DDEVARCH, DDEVTYPE, DPIDR0-7, DCIDR0-3): 基地址 0xE000EFB0
 *     参考: D1.1.19 Debug Identification Block on page D1-1449
 *   - STIR: 基地址 0xE000EF00
 *     参考: D1.1.15 Software Interrupt Generation on page D1-1449
 *   - RFSR: 基地址 0xE000EF04
 *     参考: D1.1.16 RAS Extension Fault Status Register on page D1-1449
 *   - FPU (FPCCR, FPCAR, FPDSCR, MVFR0-2): 基地址 0xE000EF34
 *     参考: D1.1.17 Floating-Point Extension on page D1-1449
 *   - Cache Maintenance (ICIALLU, ICIMVAU, DCIMVAC, DCISW, DCCMVAU, DCCMVAC, DCCSW,
 *                       DCCIMVAC, DCCISW, BPIALL): 基地址 0xE000EF50
 *     参考: D1.1.18 Cache Maintenance Operations on page D1-1449
 * - Secure ITM (ITM_STIMn, ITM_TERn, ITM_TPR, ITM_TCR, ITM_LAR, ITM_LSR, ITM_DEVARCH,
 *               ITM_DEVTYPE, ITM_PIDRn, ITM_CIDRn): 基地址 0xE0000000
 *   参考: D1.1.3 Instrumentation Macrocell on page D1-1444
 * - Secure DWT (DWT_CTRL, DWT_CYCCNT, DWT_CPICNT, DWT_EXCCNT, DWT_SLEEPCNT, DWT_LSUCNT,
 *               DWT_FOLDCNT, DWT_PCSR, DWT_COMPn, DWT_FUNCTIONn, DWT_VMASKn, DWT_LAR, DWT_LSR,
 *               DWT_DEVARCH, DWT_DEVTYPE, DWT_PIDRn, DWT_CIDRn): 基地址 0xE0001000
 *   参考: D1.1.4 Data Watchpoint and Trace on page D1-1444
 * - Secure FPB (FP_CTRL, FP_REMAP, FP_COMPn, FP_LAR, FP_LSR, FP_DEVARCH, FP_DEVTYPE,
 *               FP_PIDRn, FP_CIDRn): 基地址 0xE0002000
 *   参考: D1.1.5 Flash Patch and Breakpoint on page D1-1445
 * - Secure PMU (PMU_EVCNTRn, PMU_CCNT, PMU_EVTYPERn, PMU_CCFILTR, PMU_CNTENSET, PMU_CNTENCLR,
 *               PMU_INTENSET, PMU_INTENCLR, PMU_OVSCLR, PMU_SWINC, PMU_OVSSET, PMU_TYPE, PMU_CTRL,
 *               PMU_AUTHSTATUS, PMU_DEVARCH, PMU_DEVTYPE, PMU_PIDRn, PMU_CIDRn): 基地址 0xE0003000
 *   参考: D1.1.6 Performance Monitoring Unit on page D1-1445
 * - Secure RAS (ERRFRn, ERRCTRLn, ERRSTATUSn, ERRADDRn, ERRADDR2n, ERRMISCn, ERRGSRn,
 *               ERRIIDR, ERRDEVID): 基地址 0xE0005000
 *   参考: D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446
 * 参考: D1.1 Register index on page D1-1442
 ********************************************************************************/

#ifndef __ARM_V8M_CORE_SAFE_H__
#define __ARM_V8M_CORE_SAFE_H__

#ifdef __cplusplus
extern "C" {
#endif

/* ==============================================================================
 * 一、安全状态系统控制空间 (Secure SCS) 基地址定义
 * 参考: D1.1 Register index on page D1-1442
 * 基地址: 0xE000E000 (SCS), 各子模块有独立基地址
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 1.1 Secure SCS 基地址定义
 * 参考: D1.1 Register index on page D1-1442
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCS_BASE_S          0xE000E000UL    /* Secure System Control Space Base - 安全系统控制空间基地址 [RO]
                                                          地址: 0xE000E000
                                                          安全状态下 SCS 的起始地址，所有安全状态系统控制寄存器在此基地址上偏移分布
                                                          包括 ICTR, ACTLR, CPUID, ICSR, VTOR, AIRCR, SCR, CCR, SHPR1-3, SHCSR,
                                                          CFSR, HFSR, DFSR, MMFAR, BFAR, AFSR, CPACR, NSACR 等
                                                          参考：D1.1 Register index on page D1-1443
                                                          备注：D1.2 Summary of register mapping on page D1-1454 */

#define ARM_V8M_ICB_BASE_S          0xE000E004UL    /* Secure Implementation Control Block Base - 安全实现控制块基地址 [RO]
                                                          地址: 0xE000E004
                                                          安全状态实现控制块的基地址
                                                          包括 ICTR, ACTLR, CPPWR
                                                          参考：D1.1.8 Implementation Control Block on page D1-1447 */

#define ARM_V8M_SYST_BASE_S         0xE000E010UL    /* Secure SysTick Timer Base - 安全 SysTick 定时器基地址 [RO]
                                                          地址: 0xE000E010
                                                          安全状态下 SysTick 定时器寄存器基地址
                                                          包括 SYST_CSR, SYST_RVR, SYST_CVR, SYST_CALIB
                                                          参考：D1.1.9 SysTick Timer on page D1-1447
                                                          备注：与 Non-secure 实例银行化 (banked) */

#define ARM_V8M_NVIC_BASE_S         0xE000E100UL    /* Secure Nested Vectored Interrupt Controller Base - 安全 NVIC 基地址 [RO]
                                                          地址: 0xE000E100
                                                          安全状态下 NVIC 寄存器基地址
                                                          包括 NVIC_ISER, NVIC_ICER, NVIC_ISPR, NVIC_ICPR, NVIC_IABR, NVIC_IPR0-7, ITNS
                                                          参考：D1.1.10 Nested Vectored Interrupt Controller on page D1-1447
                                                          备注：与 Non-secure 实例银行化 (banked) */

#define ARM_V8M_SCB_REVIDR_BASE_S   0xE000ECFCUL    /* Secure Revision ID Register Base - 安全修订 ID 寄存器基地址 [RO]
                                                          地址: 0xE000ECFC
                                                          REVIDR 寄存器的绝对地址，位于 SCB 基地址 (0xE000ED00) 之前
                                                          参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_BASE_S          0xE000ED00UL    /* Secure System Control Block Base - 安全 SCB 基地址 [RO]
                                                          地址: 0xE000ED00
                                                          安全状态下 SCB 寄存器基地址
                                                          包括 CPUID, ICSR, VTOR, AIRCR, SCR, CCR, SHPR1-3, SHCSR,
                                                          CFSR, HFSR, DFSR, MMFAR, BFAR, AFSR, ID_PFR0-1, ID_DFR0, ID_AFR0,
                                                          ID_MMFR0-3, ID_ISAR0-5, CLIDR, CTR, CCSIDR, CSSELR, CPACR, NSACR
                                                          参考：D1.1.11 System Control Block on page D1-1447
                                                          备注：CPACR (偏移 0x088) 和 NSACR (偏移 0x08C) 仅在安全状态下可访问 */

#define ARM_V8M_MPU_BASE_S          0xE000ED90UL    /* Secure Memory Protection Unit Base - 安全 MPU 基地址 [RO]
                                                          地址: 0xE000ED90
                                                          安全状态下 MPU 寄存器基地址
                                                          包括 MPU_TYPE, MPU_CTRL, MPU_RNR, MPU_RBAR, MPU_RLAR, MPU_RBAR_A1-A3,
                                                          MPU_RLAR_A1-A3, MPU_MAIR0-1
                                                          参考：D1.1.12 Memory Protection Unit on page D1-1448
                                                          备注：与 Non-secure 实例银行化 (banked) */

#define ARM_V8M_SAU_BASE_S          0xE000EDD0UL    /* Secure Security Attribution Unit Base - 安全 SAU 基地址 [RO]
                                                          地址: 0xE000EDD0
                                                          安全归属单元基地址，仅在安全状态下可访问
                                                          包括 SAU_CTRL, SAU_TYPE, SAU_RNR, SAU_RBAR, SAU_RLAR, SFSR, SFAR
                                                          参考：D1.1.13 Security Attribution Unit on page D1-1448
                                                          备注：SAU 仅存在于安全状态，非安全状态下访问为 RAZ/WI */

#define ARM_V8M_DEBUG_BASE_S        0xE000EDF0UL    /* Secure Debug Control Block Base - 安全调试控制块基地址 [RO]
                                                          地址: 0xE000EDF0
                                                          安全状态下调试控制块基地址
                                                          包括 DHCSR, DCRSR, DCRDR, DEMCR, DSCEMCR, DAUTHCTRL, DSCSR
                                                          参考：D1.1.14 Debug Control Block on page D1-1449
                                                          备注：DCRSR (偏移 0x004) 和 DSCSR (偏移 0x018) 仅在安全状态下可访问 */

#define ARM_V8M_DEBUG_ID_BASE_S     0xE000EFB0UL    /* Secure Debug Identification Block Base - 安全调试标识块基地址 [RO]
                                                          地址: 0xE000EFB0
                                                          安全状态下调试标识块基地址
                                                          包括 DLAR, DLSR, DAUTHSTATUS, DDEVARCH, DDEVTYPE, DPIDR0-7, DCIDR0-3
                                                          参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_STIR_BASE_S         0xE000EF00UL    /* Secure Software Triggered Interrupt Base - 安全 STIR 基地址 [WO]
                                                          地址: 0xE000EF00
                                                          安全状态下 STIR 寄存器基地址
                                                          包括 STIR (Software Triggered Interrupt Register)
                                                          参考：D1.1.15 Software Triggered Interrupt Generation on page D1-1449
                                                          备注：与 Non-secure 实例银行化 (banked) */

#define ARM_V8M_RFSR_BASE_S         0xE000EF04UL    /* Secure RAS Fault Status Register - 安全 RAS 故障状态寄存器 [RO]
                                                          地址: 0xE000EF04
                                                          安全状态下 RAS 故障状态寄存器基地址
                                                          参考：D1.1.16 RAS Extension Fault Status Register on page D1-1449
                                                          备注：与 Non-secure 实例银行化 (banked) */

#define ARM_V8M_FPU_BASE_S          0xE000EF34UL    /* Secure Floating-point Unit Base - 安全 FPU 基地址 [RO]
                                                          地址: 0xE000EF34
                                                          安全状态下 FPU 寄存器基地址
                                                          包括 FPCCR, FPCAR, FPDSCR, MVFR0, MVFR1, MVFR2
                                                          参考：D1.1.17 Floating-Point Extension on page D1-1449
                                                          备注：与 Non-secure 实例银行化 (banked) */

#define ARM_V8M_CACHE_BASE_S        0xE000EF50UL    /* Secure Cache Maintenance Operations Base - 安全缓存维护操作基地址 [WO]
                                                          地址: 0xE000EF50
                                                          安全状态下缓存维护操作寄存器基地址
                                                          包括 ICIALLU, ICIMVAU, DCIMVAC, DCISW, DCCMVAU, DCCMVAC, DCCSW, DCCIMVAC, DCCISW, BPIALL
                                                          参考：D1.1.18 Cache Maintenance Operations on page D1-1449
                                                          备注：与 Non-secure 实例银行化 (banked) */

/* ==============================================================================
 * 二、安全状态调试/跟踪单元基地址
 * 参考: D1.1 Register index on page D1-1443
 * ==============================================================================
 */

#define ARM_V8M_ITM_BASE_S          0xE0000000UL    /* Secure Instrumentation Macrocell Base - 安全 ITM 基地址 [RO]
                                                          地址: 0xE0000000
                                                          安全状态下 ITM 寄存器基地址
                                                          包括 ITM_STIM0-31, ITM_TER, ITM_TPR, ITM_TCR, ITM_LAR, ITM_LSR
                                                          参考：D1.1.3 Instrumentation Macrocell on page D1-1444
                                                          备注：与 Non-secure 实例银行化 (banked) */

#define ARM_V8M_DWT_BASE_S          0xE0001000UL    /* Secure Data Watchpoint and Trace Base - 安全 DWT 基地址 [RO]
                                                          地址: 0xE0001000
                                                          安全状态下 DWT 寄存器基地址
                                                          包括 DWT_CTRL, DWT_CYCCNT, DWT_CPICNT, DWT_EXCCNT, DWT_SLEEPCNT,
                                                          DWT_LSUCNT, DWT_FOLDCNT, DWT_PCSR, DWT_COMP0-3, DWT_MASK0-3,
                                                          DWT_FUNCTION0-3, DWT_LAR, DWT_LSR
                                                          参考：D1.1.4 Data Watchpoint and Trace on page D1-1445
                                                          备注：与 Non-secure 实例银行化 (banked) */

#define ARM_V8M_FPB_BASE_S          0xE0002000UL    /* Secure Flash Patch and Breakpoint Base - 安全 FPB 基地址 [RO]
                                                          地址: 0xE0002000
                                                          安全状态下 FPB 寄存器基地址
                                                          包括 FP_CTRL, FP_REMAP, FP_COMP0-7, FPB_LAR, FPB_LSR
                                                          参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445
                                                          备注：与 Non-secure 实例银行化 (banked) */

#define ARM_V8M_PMU_BASE_S          0xE0003000UL    /* Secure Performance Monitoring Unit Base - 安全 PMU 基地址 [RO]
                                                          地址: 0xE0003000
                                                          安全状态下 PMU 寄存器基地址
                                                          包括 PMU_CCNT, PMU_EVCNTR0-3, PMU_EVTYPER, PMU_CCFILTR,
                                                          PMU_CNTENSET, PMU_CNTENCLR, PMU_INTENSET, PMU_INTENCLR,
                                                          PMU_OVSCLR, PMU_SWINC, PMU_OVSSET, PMU_TYPE, PMU_CTRL,
                                                          PMU_AUTHSTATUS, PMU_LAR, PMU_LSR
                                                          参考：D1.1.6 Performance Monitoring Unit on page D1-1445
                                                          备注：与 Non-secure 实例银行化 (banked) */

#define ARM_V8M_RAS_BASE_S          0xE0005000UL    /* Secure RAS Extension Base - 安全 RAS 基地址 [RO]
                                                          地址: 0xE0005000
                                                          安全状态下 RAS 寄存器基地址
                                                          包括 ERRFR, ERRCTRL, ERRSTATUS, ERRADDR, ERRADDR2,
                                                          ERRMISC, ERRGSR, ERRIIDR, ERRDEVID
                                                          参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446
                                                          备注：与 Non-secure 实例银行化 (banked) */

#define ARM_V8M_TPIU_BASE_S         0xE0040000UL    /* Secure Trace Port Interface Unit Base - 安全 TPIU 基地址 [RO]
                                                          地址: 0xE0040000
                                                          安全状态下 TPIU 寄存器基地址
                                                          包括 TPIU_SSPSR, TPIU_CSPSR, TPIU_ACPR, TPIU_SPPR, TPIU_FFSR,
                                                          TPIU_FFCR, TPIU_PSCR, TPIU_CLAIMSET, TPIU_CLAIMCLR,
                                                          TPIU_LAR, TPIU_LSR, TPIU_DEVID, TPIU_DEVTYPE
                                                          参考：D1.1.31 Trace Port Interface Unit on page D1-1453
                                                          备注：TPIU 在安全和非安全状态下共享同一物理寄存器 */

/* ==============================================================================
 * 三、安全状态 SCS 寄存器偏移定义（带 _S 后缀）
 * 参考: D1.1 Register index on page D1-1442
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 3.1 SCS 系统控制寄存器偏移 (Secure)
 * 参考: D1.1.8 Implementation Control Block on page D1-1447
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCS_ICTR_S          0x004   /* Interrupt Controller Type Register - 中断控制器类型寄存器 [RO]
                                               提供 NVIC 的信息，指示实现的外部中断线数量
                                               参考：D1.1.8 Implementation Control Block on page D1-1447 */

#define ARM_V8M_SCS_ACTLR_S         0x008   /* Auxiliary Control Register - 辅助控制寄存器 [RW]
                                               提供 IMPLEMENTATION DEFINED 辅助控制特性
                                               参考：D1.1.8 Implementation Control Block on page D1-1447 */

#define ARM_V8M_SCS_CPPWR_S         0x00C   /* Coprocessor Power Control Register - 协处理器电源控制寄存器 [RW]
                                               控制协处理器的电源状态
                                               参考：D1.1.8 Implementation Control Block on page D1-1447 */

/* -----------------------------------------------------------------------------
 * 3.2 SysTick 定时器寄存器偏移 (Secure)
 * 参考: D1.1.9 SysTick Timer on page D1-1447
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SYST_CSR_S          0x000   /* SysTick Control and Status Register - SysTick 控制和状态寄存器 [RW]
                                               控制 SysTick 定时器的操作
                                               参考：D1.1.9 SysTick Timer on page D1-1447 */

#define ARM_V8M_SYST_RVR_S          0x004   /* SysTick Reload Value Register - SysTick 重装载值寄存器 [RW]
                                               保存 SysTick 计数器的重装载值
                                               参考：D1.1.9 SysTick Timer on page D1-1447 */

#define ARM_V8M_SYST_CVR_S          0x008   /* SysTick Current Value Register - SysTick 当前值寄存器 [RW]
                                               保存 SysTick 计数器的当前值
                                               参考：D1.1.9 SysTick Timer on page D1-1447 */

#define ARM_V8M_SYST_CALIB_S        0x00C   /* SysTick Calibration Value Register - SysTick 校准值寄存器 [RO]
                                               指示 SysTick 的校准属性
                                               参考：D1.1.9 SysTick Timer on page D1-1447 */

/* -----------------------------------------------------------------------------
 * 3.3 NVIC 寄存器偏移 (Secure)
 * 参考: D1.1.10 Nested Vectored Interrupt Controller on page D1-1447
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_NVIC_ISER_S(n)      (0x000 + (n) * 0x04)  /* Interrupt Set-Enable Register n (n=0-15) [RW]
                                                               参考：D1.1.10 Nested Vectored Interrupt Controller on page D1-1447 */

#define ARM_V8M_NVIC_ICER_S(n)      (0x080 + (n) * 0x04)  /* Interrupt Clear-Enable Register n (n=0-15) [RW]
                                                               参考：D1.1.10 Nested Vectored Interrupt Controller on page D1-1447 */

#define ARM_V8M_NVIC_ISPR_S(n)      (0x100 + (n) * 0x04)  /* Interrupt Set-Pending Register n (n=0-15) [RW]
                                                               参考：D1.1.10 Nested Vectored Interrupt Controller on page D1-1447 */

#define ARM_V8M_NVIC_ICPR_S(n)      (0x180 + (n) * 0x04)  /* Interrupt Clear-Pending Register n (n=0-15) [RW]
                                                               参考：D1.1.10 Nested Vectored Interrupt Controller on page D1-1447 */

#define ARM_V8M_NVIC_IABR_S(n)      (0x200 + (n) * 0x04)  /* Interrupt Active Bit Register n (n=0-15) [RO]
                                                               参考：D1.1.10 Nested Vectored Interrupt Controller on page D1-1447 */

#define ARM_V8M_NVIC_ITNS_S(n)      (0x380 + (n) * 0x04)  /* Interrupt Target Non-secure Register n (n=0-15) [RW]
                                                               控制中断的目标安全状态
                                                               参考：D1.1.10 Nested Vectored Interrupt Controller on page D1-1447
                                                               备注：仅在安全 NVIC 中存在 */

#define ARM_V8M_NVIC_IPR_S(n)       (0x300 + (n) * 0x04)  /* Interrupt Priority Register n (n=0-123) [RW]
                                                               参考：D1.1.10 Nested Vectored Interrupt Controller on page D1-1447 */

/* -----------------------------------------------------------------------------
 * 3.4 SCB 寄存器偏移 (Secure)
 * 参考: D1.1.11 System Control Block on page D1-1447
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCB_REVIDR_S        0x000   /* Revision ID Register - 修订 ID 寄存器 [RO]
                                               提供处理器修订版本信息
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_CPUID_S         0x004   /* CPUID Base Register - CPUID 基寄存器 [RO]
                                               提供处理器标识信息
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ICSR_S          0x008   /* Interrupt Control and State Register - 中断控制和状态寄存器 [RW]
                                               提供 NMI、PendSV 和 SysTick 异常的软件控制
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_VTOR_S          0x00C   /* Vector Table Offset Register - 向量表偏移寄存器 [RW]
                                               保存向量表的基地址
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_AIRCR_S         0x010   /* Application Interrupt and Reset Control Register [RW]
                                               设置或返回中断控制数据
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_SCR_S           0x014   /* System Control Register - 系统控制寄存器 [RW]
                                               设置或返回系统控制数据
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_CCR_S           0x018   /* Configuration and Control Register - 配置和控制寄存器 [RW]
                                               设置或返回配置和控制数据
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_SHPR1_S         0x01C   /* System Handler Priority Register 1 - 系统处理程序优先级寄存器 1 [RW]
                                               设置或返回系统处理程序 4-7 的优先级
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_SHPR2_S         0x020   /* System Handler Priority Register 2 - 系统处理程序优先级寄存器 2 [RW]
                                               设置或返回系统处理程序 8-11 的优先级
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_SHPR3_S         0x024   /* System Handler Priority Register 3 - 系统处理程序优先级寄存器 3 [RW]
                                               设置或返回系统处理程序 12-15 的优先级
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_SHCSR_S         0x028   /* System Handler Control and State Register [RW]
                                               控制并提供系统异常的活跃和挂起状态
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_CFSR_S          0x02C   /* Configurable Fault Status Register - 可配置故障状态寄存器 [RW]
                                               包含三个可配置故障状态寄存器
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_HFSR_S          0x030   /* HardFault Status Register - HardFault 状态寄存器 [RW]
                                               显示任何 HardFault 异常的原因
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_DFSR_S          0x034   /* Debug Fault Status Register - 调试故障状态寄存器 [RW]
                                               提供调试事件的信息
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_MMFAR_S         0x038   /* MemManage Fault Address Register [RW]
                                               保存导致 MemManage 故障的位置地址
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_BFAR_S          0x03C   /* BusFault Address Register - BusFault 故障地址寄存器 [RW]
                                               保存导致精确 BusFault 的位置地址
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_AFSR_S          0x040   /* Auxiliary Fault Status Register [RW]
                                               提供 IMPLEMENTATION DEFINED 故障状态信息
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_PFR0_S       0x044   /* Processor Feature Register 0 [RO]
                                               指示处理器支持的指令集特性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_PFR1_S       0x048   /* Processor Feature Register 1 [RO]
                                               指示处理器支持的指令集特性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_DFR0_S       0x04C   /* Debug Feature Register 0 [RO]
                                               指示处理器支持的调试特性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_AFR0_S       0x050   /* Auxiliary Feature Register 0 [RO]
                                               指示处理器支持的辅助特性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_MMFR0_S      0x054   /* Memory Model Feature Register 0 [RO]
                                               描述处理器支持的内存模型和内存管理特性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_MMFR1_S      0x058   /* Memory Model Feature Register 1 [RO]
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_MMFR2_S      0x05C   /* Memory Model Feature Register 2 [RO]
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_MMFR3_S      0x060   /* Memory Model Feature Register 3 [RO]
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_ISAR0_S      0x064   /* Instruction Set Attribute Register 0 [RO]
                                               描述处理器支持的指令集属性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_ISAR1_S      0x068   /* Instruction Set Attribute Register 1 [RO]
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_ISAR2_S      0x06C   /* Instruction Set Attribute Register 2 [RO]
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_ISAR3_S      0x070   /* Instruction Set Attribute Register 3 [RO]
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_ISAR4_S      0x074   /* Instruction Set Attribute Register 4 [RO]
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_ID_ISAR5_S      0x078   /* Instruction Set Attribute Register 5 [RO]
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_CLIDR_S         0x07C   /* Cache Level ID Register - 缓存级别标识寄存器 [RO]
                                               指示实现的缓存级别和类型
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_CTR_S           0x080   /* Cache Type Register - 缓存类型寄存器 [RO]
                                               描述实现的缓存类型和特性
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_CCSIDR_S        0x084   /* Current Cache Size ID Register [RO]
                                               提供当前选中缓存的尺寸信息
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_CSSELR_S        0x084   /* Cache Size Selection Register [RW]
                                               选择要访问的缓存
                                               参考：D1.1.11 System Control Block on page D1-1447 */

#define ARM_V8M_SCB_CPACR_S         0x088   /* Coprocessor Access Control Register [RW]
                                               控制对协处理器的访问权限
                                               参考：D1.1.11 System Control Block on page D1-1447
                                               备注：仅在安全状态下可访问 */

#define ARM_V8M_SCB_NSACR_S         0x08C   /* Non-secure Access Control Register [RW]
                                               控制非安全状态对协处理器的访问
                                               参考：D1.1.11 System Control Block on page D1-1447
                                               备注：仅在安全状态下可访问 */

/* -----------------------------------------------------------------------------
 * 3.5 MPU 寄存器偏移 (Secure)
 * 参考: D1.1.12 Memory Protection Unit on page D1-1448
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_MPU_TYPE_S          0x000   /* MPU Type Register - MPU 类型寄存器 [RO]
                                               提供 MPU 的信息，包含数据区域数量
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_CTRL_S          0x004   /* MPU Control Register - MPU 控制寄存器 [RW]
                                               控制 MPU 的操作
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_RNR_S           0x008   /* MPU Region Number Register - MPU 区域编号寄存器 [RW]
                                               选择由 MPU_RBAR 和 MPU_RLAR 引用的 MPU 区域
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_RBAR_S          0x00C   /* MPU Region Base Address Register [RW]
                                               定义 MPU_RNR 选择的 MPU 区域的基地址
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_RLAR_S          0x010   /* MPU Region Limit Address Register [RW]
                                               定义 MPU_RNR 选择的 MPU 区域的限制地址和属性
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_RBAR_A1_S       0x014   /* MPU Region Base Address Register Alias 1 [RW]
                                               写入时可直接指定区域号，无需先写 MPU_RNR
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_RLAR_A1_S       0x018   /* MPU Region Limit Address Register Alias 1 [RW]
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_RBAR_A2_S       0x01C   /* MPU Region Base Address Register Alias 2 [RW]
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_RLAR_A2_S       0x020   /* MPU Region Limit Address Register Alias 2 [RW]
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_RBAR_A3_S       0x024   /* MPU Region Base Address Register Alias 3 [RW]
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_RLAR_A3_S       0x028   /* MPU Region Limit Address Register Alias 3 [RW]
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_MAIR0_S         0x030   /* MPU Memory Attribute Indirection Register 0 [RW]
                                               定义内存属性编码
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

#define ARM_V8M_MPU_MAIR1_S         0x034   /* MPU Memory Attribute Indirection Register 1 [RW]
                                               定义内存属性编码
                                               参考：D1.1.12 Memory Protection Unit on page D1-1448 */

/* -----------------------------------------------------------------------------
 * 3.6 SAU 寄存器偏移 (Secure Only)
 * 参考: D1.1.13 Security Attribution Unit on page D1-1448
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SAU_CTRL_S          0x000   /* SAU Control Register - SAU 控制寄存器 [RW]
                                               控制 SAU 的操作
                                               参考：D1.1.13 Security Attribution Unit on page D1-1448
                                               备注：仅在安全状态下可访问 */

#define ARM_V8M_SAU_TYPE_S          0x004   /* SAU Type Register - SAU 类型寄存器 [RO]
                                               指示实现的 SAU 区域数量
                                               参考：D1.1.13 Security Attribution Unit on page D1-1448
                                               备注：仅在安全状态下可访问 */

#define ARM_V8M_SAU_RNR_S           0x008   /* SAU Region Number Register - SAU 区域编号寄存器 [RW]
                                               选择由 SAU_RBAR 和 SAU_RLAR 引用的 SAU 区域
                                               参考：D1.1.13 Security Attribution Unit on page D1-1448
                                               备注：仅在安全状态下可访问 */

#define ARM_V8M_SAU_RBAR_S          0x00C   /* SAU Region Base Address Register [RW]
                                               定义 SAU_RNR 选择的 SAU 区域的基地址
                                               参考：D1.1.13 Security Attribution Unit on page D1-1448
                                               备注：仅在安全状态下可访问 */

#define ARM_V8M_SAU_RLAR_S          0x010   /* SAU Region Limit Address Register [RW]
                                               定义 SAU_RNR 选择的 SAU 区域的限制地址和属性
                                               参考：D1.1.13 Security Attribution Unit on page D1-1448
                                               备注：仅在安全状态下可访问 */

#define ARM_V8M_SCB_SFSR_S          0x014   /* Secure Fault Status Register - 安全故障状态寄存器 [RW]
                                               提供安全故障状态信息
                                               参考：D1.1.13 Security Attribution Unit on page D1-1448
                                               备注：仅在安全状态下可访问 */

#define ARM_V8M_SCB_SFAR_S          0x018   /* Secure Fault Address Register - 安全故障地址寄存器 [RW]
                                               保存导致安全故障的地址
                                               参考：D1.1.13 Security Attribution Unit on page D1-1448
                                               备注：仅在安全状态下可访问 */

/* -----------------------------------------------------------------------------
 * 3.7 STIR 寄存器偏移 (Secure)
 * 参考: D1.1.15 Software Interrupt Generation on page D1-1449
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_STIR_S              0x000   /* Software Triggered Interrupt Register [WO]
                                               写入此寄存器会触发中断
                                               参考：D1.1.15 Software Interrupt Generation on page D1-1449 */

/* -----------------------------------------------------------------------------
 * 3.8 RFSR 寄存器偏移 (Secure)
 * 参考: D1.1.16 RAS Extension Fault Status Register on page D1-1449
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_SCB_RFSR_S          0x004   /* RAS Fault Status Register - RAS 故障状态寄存器 [RW]
                                               提供 RAS 故障状态信息
                                               参考：D1.1.16 RAS Extension Fault Status Register on page D1-1449 */

/* -----------------------------------------------------------------------------
 * 3.9 FPU 寄存器偏移 (Secure)
 * 参考: D1.1.17 Floating-Point Extension on page D1-1449
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_FPU_FPCCR_S         0x000   /* Floating Point Context Control Register [RW]
                                               控制浮点上下文
                                               参考：D1.1.17 Floating-Point Extension on page D1-1449 */

#define ARM_V8M_FPU_FPCAR_S         0x004   /* Floating Point Context Address Register [RW]
                                               保存内存中浮点上下文的位置
                                               参考：D1.1.17 Floating-Point Extension on page D1-1449 */

#define ARM_V8M_FPU_FPDSCR_S        0x008   /* Floating Point Default Status Control Register [RW]
                                               保存 FPSCR 的默认值
                                               参考：D1.1.17 Floating-Point Extension on page D1-1449 */

#define ARM_V8M_FPU_MVFR0_S         0x00C   /* Media and VFP Feature Register 0 [RO]
                                               提供浮点单元特性信息
                                               参考：D1.1.17 Floating-Point Extension on page D1-1449 */

#define ARM_V8M_FPU_MVFR1_S         0x010   /* Media and VFP Feature Register 1 [RO]
                                               提供额外的浮点特性信息
                                               参考：D1.1.17 Floating-Point Extension on page D1-1449 */

#define ARM_V8M_FPU_MVFR2_S         0x014   /* Media and VFP Feature Register 2 [RO]
                                               提供 FPv5 扩展的特性信息
                                               参考：D1.1.17 Floating-Point Extension on page D1-1449 */

/* -----------------------------------------------------------------------------
 * 3.10 Cache Maintenance 寄存器偏移 (Secure)
 * 参考: D1.1.18 Cache Maintenance Operations on page D1-1449
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_ICIALLU_S           0x000   /* Instruction Cache Invalidate All to PoU [WO]
                                               将所有指令缓存无效化到统一点 (PoU)
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

#define ARM_V8M_ICIMVAU_S           0x008   /* Instruction Cache line Invalidate by Address to PoU [WO]
                                               按修改虚拟地址将指令缓存行无效化到统一点
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

#define ARM_V8M_DCIMVAC_S           0x00C   /* Data Cache line Invalidate by Address to PoC [WO]
                                               按修改虚拟地址将数据缓存行无效化到一致点
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

#define ARM_V8M_DCISW_S             0x010   /* Data Cache line Invalidate by Set/Way [WO]
                                               按组/路方式将数据缓存行无效化
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

#define ARM_V8M_DCCMVAU_S           0x014   /* Data Cache line Clean by address to PoU [WO]
                                               按修改虚拟地址将数据缓存行清理到统一点
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

#define ARM_V8M_DCCMVAC_S           0x018   /* Data Cache line Clean by Address to PoC [WO]
                                               按修改虚拟地址将数据缓存行清理到一致点
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

#define ARM_V8M_DCCSW_S             0x01C   /* Data Cache Clean line by Set/Way [WO]
                                               按组/路方式将数据缓存行清理
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

#define ARM_V8M_DCCIMVAC_S          0x020   /* Data Cache line Clean and Invalidate by Address to PoC [WO]
                                               按修改虚拟地址将数据缓存行清理并无效化到一致点
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

#define ARM_V8M_DCCISW_S            0x024   /* Data Cache line Clean and Invalidate by Set/Way [WO]
                                               按组/路方式将数据缓存行清理并无效化
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

#define ARM_V8M_BPIALL_S            0x028   /* Branch Predictor Invalidate All [WO]
                                               将所有分支预测器条目无效化
                                               参考：D1.1.18 Cache Maintenance Operations on page D1-1449 */

/* -----------------------------------------------------------------------------
 * 3.11 Debug Identification 寄存器偏移 (Secure)
 * 参考: D1.1.19 Debug Identification Block on page D1-1449
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DEBUG_DLAR_S        0x0B0   /* Software Lock Access Register [WO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DLSR_S        0x0B4   /* Software Lock Status Register [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DAUTHSTATUS_S 0x0B8   /* Debug Authentication Status Register [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DDEVARCH_S    0x0BC   /* SCS Device Architecture Register [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DDEVTYPE_S    0x0CC   /* SCS Device Type Register [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DPIDR4_S      0x0D0   /* SCS Peripheral Identification Register 4 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DPIDR5_S      0x0D4   /* SCS Peripheral Identification Register 5 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DPIDR6_S      0x0D8   /* SCS Peripheral Identification Register 6 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DPIDR7_S      0x0DC   /* SCS Peripheral Identification Register 7 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DPIDR0_S      0x0E0   /* SCS Peripheral Identification Register 0 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DPIDR1_S      0x0E4   /* SCS Peripheral Identification Register 1 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DPIDR2_S      0x0E8   /* SCS Peripheral Identification Register 2 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DPIDR3_S      0x0EC   /* SCS Peripheral Identification Register 3 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DCIDR0_S      0x0F0   /* SCS Component Identification Register 0 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DCIDR1_S      0x0F4   /* SCS Component Identification Register 1 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DCIDR2_S      0x0F8   /* SCS Component Identification Register 2 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

#define ARM_V8M_DEBUG_DCIDR3_S      0x0FC   /* SCS Component Identification Register 3 [RO]
                                               参考：D1.1.19 Debug Identification Block on page D1-1449 */

/* -----------------------------------------------------------------------------
 * 3.12 Debug Control Block 寄存器偏移 (Secure)
 * 参考: D1.1.14 Debug Control Block on page D1-1449
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_DEBUG_DHCSR_S       0x000   /* Debug Halting Control and Status Register [RW]
                                               控制处理器调试暂停状态
                                               参考：D1.1.14 Debug Control Block on page D1-1449 */

#define ARM_V8M_DEBUG_DCRSR_S       0x004   /* Debug Core Register Select Register [WO]
                                               选择要读写的核心寄存器
                                               参考：D1.1.14 Debug Control Block on page D1-1449
                                               备注：仅在安全状态下可访问 */

#define ARM_V8M_DEBUG_DCRDR_S       0x008   /* Debug Core Register Data Register [RW]
                                               提供对核心寄存器的读写数据
                                               参考：D1.1.14 Debug Control Block on page D1-1449 */

#define ARM_V8M_DEBUG_DEMCR_S       0x00C   /* Debug Exception and Monitor Control Register [RW]
                                               控制调试异常和监视器
                                               参考：D1.1.14 Debug Control Block on page D1-1449 */

#define ARM_V8M_DEBUG_DSCEMCR_S     0x010   /* Debug Set Clear Exception and Monitor Control Register [RW]
                                               参考：D1.1.14 Debug Control Block on page D1-1449 */

#define ARM_V8M_DEBUG_DAUTHCTRL_S   0x014   /* Debug Authentication Control Register [RW]
                                               控制调试认证
                                               参考：D1.1.14 Debug Control Block on page D1-1449 */

#define ARM_V8M_DEBUG_DSCSR_S       0x018   /* Debug Security Control and Status Register [RW]
                                               参考：D1.1.14 Debug Control Block on page D1-1449
                                               备注：仅在安全状态下可访问 */

/* ==============================================================================
 * 四、安全状态 ITM 寄存器偏移定义（带 _S 后缀）
 * 参考: D1.1.3 Instrumentation Macrocell on page D1-1444
 * ==============================================================================
 */
#define ARM_V8M_ITM_STIM_S(n)       ((n) * 0x04)  /* Stimulus Port Register n (n=0-255) [RW]
                                                       参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_TER_S(n)        (0xE00 + (n) * 0x04)  /* Trace Enable Register n (n=0-7) [RW]
                                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_TPR_S           0xE40   /* Trace Privilege Register [RW]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_TCR_S           0xE80   /* Trace Control Register [RW]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_LAR_S           0xFB0   /* Software Lock Access Register [WO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_LSR_S           0xFB4   /* Software Lock Status Register [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_DEVARCH_S       0xFBC   /* Device Architecture Register [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_DEVTYPE_S       0xFCC   /* Device Type Register [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_PIDR4_S         0xFD0   /* Peripheral Identification Register 4 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_PIDR5_S         0xFD4   /* Peripheral Identification Register 5 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_PIDR6_S         0xFD8   /* Peripheral Identification Register 6 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_PIDR7_S         0xFDC   /* Peripheral Identification Register 7 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_PIDR0_S         0xFE0   /* Peripheral Identification Register 0 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_PIDR1_S         0xFE4   /* Peripheral Identification Register 1 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_PIDR2_S         0xFE8   /* Peripheral Identification Register 2 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_PIDR3_S         0xFEC   /* Peripheral Identification Register 3 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_CIDR0_S         0xFF0   /* Component Identification Register 0 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_CIDR1_S         0xFF4   /* Component Identification Register 1 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_CIDR2_S         0xFF8   /* Component Identification Register 2 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

#define ARM_V8M_ITM_CIDR3_S         0xFFC   /* Component Identification Register 3 [RO]
                                               参考：D1.1.3 Instrumentation Macrocell on page D1-1444 */

/* ==============================================================================
 * 五、安全状态 DWT 寄存器偏移定义（带 _S 后缀）
 * 参考: D1.1.4 Data Watchpoint and Trace on page D1-1445
 * ==============================================================================
 */
#define ARM_V8M_DWT_CTRL_S          0x000   /* Control Register [RW]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_CYCCNT_S        0x004   /* Cycle Count Register [RW]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_CPICNT_S        0x008   /* CPI Count Register [RW]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_EXCCNT_S        0x00C   /* Exception Overhead Count Register [RW]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_SLEEPCNT_S      0x010   /* Sleep Count Register [RW]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_LSUCNT_S        0x014   /* LSU Count Register [RW]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_FOLDCNT_S       0x018   /* Folded Instruction Count Register [RW]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_PCSR_S          0x01C   /* Program Counter Sample Register [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_COMP_S(n)       (0x020 + (n) * 0x10)  /* Comparator Register n (n=0-3) [RW]
                                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_FUNCTION_S(n)   (0x028 + (n) * 0x10)  /* Comparator Function Register n (n=0-3) [RW]
                                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_VMASK_S(n)      (0x02C + (n) * 0x10)  /* Comparator Value Mask Register n (n=0-3) [RW]
                                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_LAR_S           0xFB0   /* Software Lock Access Register [WO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_LSR_S           0xFB4   /* Software Lock Status Register [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_DEVARCH_S       0xFBC   /* Device Architecture Register [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_DEVTYPE_S       0xFCC   /* Device Type Register [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_PIDR4_S         0xFD0   /* Peripheral Identification Register 4 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_PIDR5_S         0xFD4   /* Peripheral Identification Register 5 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_PIDR6_S         0xFD8   /* Peripheral Identification Register 6 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_PIDR7_S         0xFDC   /* Peripheral Identification Register 7 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_PIDR0_S         0xFE0   /* Peripheral Identification Register 0 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_PIDR1_S         0xFE4   /* Peripheral Identification Register 1 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_PIDR2_S         0xFE8   /* Peripheral Identification Register 2 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_PIDR3_S         0xFEC   /* Peripheral Identification Register 3 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_CIDR0_S         0xFF0   /* Component Identification Register 0 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_CIDR1_S         0xFF4   /* Component Identification Register 1 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_CIDR2_S         0xFF8   /* Component Identification Register 2 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

#define ARM_V8M_DWT_CIDR3_S         0xFFC   /* Component Identification Register 3 [RO]
                                               参考：D1.1.4 Data Watchpoint and Trace on page D1-1445 */

/* ==============================================================================
 * 六、安全状态 FPB 寄存器偏移定义（带 _S 后缀）
 * 参考: D1.1.5 Flash Patch and Breakpoint on page D1-1445
 * ==============================================================================
 */
#define ARM_V8M_FPB_CTRL_S          0x000   /* Flash Patch Control Register [RW]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_REMAP_S         0x004   /* Flash Patch Remap Register [RW]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_COMP_S(n)       (0x008 + (n) * 0x04)  /* Flash Patch Comparator Register n (n=0-7) [RW]
                                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_LAR_S           0xFB0   /* Software Lock Access Register [WO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_LSR_S           0xFB4   /* Software Lock Status Register [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_DEVARCH_S       0xFBC   /* Device Architecture Register [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_DEVTYPE_S       0xFCC   /* Device Type Register [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_PIDR4_S         0xFD0   /* Peripheral Identification Register 4 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_PIDR5_S         0xFD4   /* Peripheral Identification Register 5 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_PIDR6_S         0xFD8   /* Peripheral Identification Register 6 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_PIDR7_S         0xFDC   /* Peripheral Identification Register 7 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_PIDR0_S         0xFE0   /* Peripheral Identification Register 0 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_PIDR1_S         0xFE4   /* Peripheral Identification Register 1 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_PIDR2_S         0xFE8   /* Peripheral Identification Register 2 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_PIDR3_S         0xFEC   /* Peripheral Identification Register 3 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_CIDR0_S         0xFF0   /* Component Identification Register 0 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_CIDR1_S         0xFF4   /* Component Identification Register 1 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_CIDR2_S         0xFF8   /* Component Identification Register 2 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

#define ARM_V8M_FPB_CIDR3_S         0xFFC   /* Component Identification Register 3 [RO]
                                               参考：D1.1.5 Flash Patch and Breakpoint on page D1-1445 */

/* ==============================================================================
 * 七、安全状态 PMU 寄存器偏移定义（带 _S 后缀）
 * 参考: D1.1.6 Performance Monitoring Unit on page D1-1445
 * ==============================================================================
 */
#define ARM_V8M_PMU_EVCNTR_S(n)     ((n) * 0x04)  /* Event Counter Register n (n=0-30) [RW]
                                                       参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_CCNT_S          0x07C   /* Cycle Counter Register [RW]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_EVTYPER_S(n)    (0x400 + (n) * 0x04)  /* Event Type and Filter Register n (n=0-30) [RW]
                                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_CCFILTR_S       0x47C   /* Cycle Counter Filter Register [RW]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_CNTENSET_S      0xC00   /* Count Enable Set Register [RW]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_CNTENCLR_S      0xC20   /* Count Enable Clear Register [RW]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_INTENSET_S      0xC40   /* Interrupt Enable Set Register [RW]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_INTENCLR_S      0xC60   /* Interrupt Enable Clear Register [RW]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_OVSCLR_S        0xC80   /* Overflow Flag Status Clear Register [RW]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_SWINC_S         0xCA0   /* Software Increment Register [WO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_OVSSET_S        0xCC0   /* Overflow Flag Status Set Register [RW]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_TYPE_S          0xE00   /* Type Register [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_CTRL_S          0xE04   /* Control Register [RW]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_AUTHSTATUS_S    0xFB8   /* Authentication Status Register [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_DEVARCH_S       0xFBC   /* Device Architecture Register [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_DEVTYPE_S       0xFCC   /* Device Type Register [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_PIDR4_S         0xFD0   /* Peripheral Identification Register 4 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_PIDR5_S         0xFD4   /* Peripheral Identification Register 5 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_PIDR6_S         0xFD8   /* Peripheral Identification Register 6 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_PIDR7_S         0xFDC   /* Peripheral Identification Register 7 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_PIDR0_S         0xFE0   /* Peripheral Identification Register 0 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_PIDR1_S         0xFE4   /* Peripheral Identification Register 1 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_PIDR2_S         0xFE8   /* Peripheral Identification Register 2 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_PIDR3_S         0xFEC   /* Peripheral Identification Register 3 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_CIDR0_S         0xFF0   /* Component Identification Register 0 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_CIDR1_S         0xFF4   /* Component Identification Register 1 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_CIDR2_S         0xFF8   /* Component Identification Register 2 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

#define ARM_V8M_PMU_CIDR3_S         0xFFC   /* Component Identification Register 3 [RO]
                                               参考：D1.1.6 Performance Monitoring Unit on page D1-1445 */

/* ==============================================================================
 * 八、安全状态 RAS 寄存器偏移定义（带 _S 后缀）
 * 参考: D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446
 * ==============================================================================
 */
#define ARM_V8M_RAS_ERRFR_S(n)      ((n) * 0x40)  /* Error Record Feature Register n (n=0-3) [RO]
                                                       参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446 */

#define ARM_V8M_RAS_ERRCTRL_S(n)    (0x008 + (n) * 0x40)  /* Error Record Control Register n (n=0-3) [RW]
                                                               参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446 */

#define ARM_V8M_RAS_ERRSTATUS_S(n)  (0x010 + (n) * 0x40)  /* Error Record Primary Status Register n (n=0-3) [RW]
                                                               参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446 */

#define ARM_V8M_RAS_ERRADDR_S(n)    (0x018 + (n) * 0x40)  /* Error Record Address Register n (n=0-3) [RW]
                                                               参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446 */

#define ARM_V8M_RAS_ERRADDR2_S(n)   (0x01C + (n) * 0x40)  /* Error Record Address 2 Register n (n=0-3) [RW]
                                                               参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446 */

#define ARM_V8M_RAS_ERRMISC_S(n, m) (0x020 + (n) * 0x40 + (m) * 0x04)  /* Error Record Miscellaneous Register n,m (n=0-3, m=0-7) [RW]
                                                                          参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446 */

#define ARM_V8M_RAS_ERRGSR_S(n)     (0xE00 + (n) * 0x04)  /* Error Record Group Status Register n (n=0-3) [RO]
                                                               参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446 */

#define ARM_V8M_RAS_ERRIIDR_S       0xE10   /* Error Implementer ID Register [RO]
                                               参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446 */

#define ARM_V8M_RAS_ERRDEVID_S      0xFC8   /* Error Record Device ID Register [RO]
                                               参考：D1.1.7 Reliability, Availability and Serviceability Extension on page D1-1446 */

/* ==============================================================================
 * 九、安全状态 TPIU 寄存器偏移定义（带 _S 后缀）
 * 参考: D1.1.31 Trace Port Interface Unit on page D1-1453
 * ==============================================================================
 */
#define ARM_V8M_TPIU_SSPSR_S        0x000   /* Supported Parallel Port Sizes Register [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_CSPSR_S        0x004   /* Current Parallel Port Size Register [RW]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_ACPR_S         0x010   /* Asynchronous Clock Prescaler Register [RW]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_SPPR_S         0x0F0   /* Selected Pin Protocol Register [RW]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_FFSR_S         0x300   /* Formatter and Flush Status Register [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_FFCR_S         0x304   /* Formatter and Flush Control Register [RW]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_PSCR_S         0x308   /* Periodic Synchronization Control Register [RW]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_CLAIMSET_S     0xFA0   /* Claim Tag Set Register [WO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_CLAIMCLR_S     0xFA4   /* Claim Tag Clear Register [WO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_LAR_S          0xFB0   /* Software Lock Access Register [WO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_LSR_S          0xFB4   /* Software Lock Status Register [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_DEVID_S        0xFC8   /* Device Identifier Register [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_DEVTYPE_S      0xFCC   /* Device Type Register [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_PIDR4_S        0xFD0   /* Peripheral Identification Register 4 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_PIDR5_S        0xFD4   /* Peripheral Identification Register 5 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_PIDR6_S        0xFD8   /* Peripheral Identification Register 6 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_PIDR7_S        0xFDC   /* Peripheral Identification Register 7 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_PIDR0_S        0xFE0   /* Peripheral Identification Register 0 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_PIDR1_S        0xFE4   /* Peripheral Identification Register 1 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_PIDR2_S        0xFE8   /* Peripheral Identification Register 2 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_PIDR3_S        0xFEC   /* Peripheral Identification Register 3 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_CIDR0_S        0xFF0   /* Component Identification Register 0 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_CIDR1_S        0xFF4   /* Component Identification Register 1 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_CIDR2_S        0xFF8   /* Component Identification Register 2 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#define ARM_V8M_TPIU_CIDR3_S        0xFFC   /* Component Identification Register 3 [RO]
                                               参考：D1.1.31 Trace Port Interface Unit on page D1-1453 */

#ifdef __cplusplus
}
#endif

#endif /* __ARM_V8M_CORE_SAFE_H__ */
