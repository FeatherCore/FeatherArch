/********************************************************************************
 * @file        arm_v8m_cm33_core.h
 * @brief       ARM Cortex-M33 Processor Register Definitions
 * @details     基于 Arm® Cortex™-M33 Devices Generic User Guide (ARM DUI 100235)
 *              和 Arm® Cortex™-M33 Processor Technical Reference Manual (ARM DDI 100230)
 *              和 Arm® v8-M Architecture Reference Manual (ARM DDI 0553)
 *              文档路径：
 *              - g:\develop\FeatherCore\FeatherArch\docs\arm\Arm® Cortex™-M33 Devices Generic User Guide.txt
 *              - g:\develop\FeatherCore\FeatherArch\docs\arm\Arm® Cortex™-M33 Processor Technical Reference Manual.txt
 *              - g:\develop\FeatherCore\FeatherArch\docs\arm\Arm® v8-M Architecture Reference Manual.txt
 * @author      FeatherCore
 * @version     1.0.0
 * @date        2026-03-30
 * @note        本文件仅包含寄存器定义和描述，位域定义在单独的头文件中
 *              通用寄存器引用自 arm_v8m_core.h
 *
 * 寄存器覆盖清单：
 * - Cortex-M33 特定 SCS 寄存器 (基地址 0xE000E000)
 *   - ACTLR (Auxiliary Control Register) - 偏移 0x008, Reset 0x00000000
 *     参考：Table 4-2 Summary of the system control block registers (DUI 100235)
 *           3.4 Auxiliary Control Register on page 39 (DDI 100230)
 * - Cortex-M33 特定 SCB 寄存器 (基地址 0xE000ED00)
 *   - CPUID (CPUID Base Register) - 偏移 0x000, Reset 0x411FD210 (r1p0)
 *     参考：Table 4-2 Summary of the system control block registers (DUI 100235)
 *           3.5 CPUID Base Register on page 41 (DDI 100230)
 *   - ID_AFR0 (Auxiliary Feature Register 0) - 偏移 0x04C
 *     参考：Table 4-2 Summary of the system control block registers (DUI 100235)
 *           3.6 Auxiliary Feature Register 0 on page 42 (DDI 100230)
 * - Cortex-M33 特定 CCR 寄存器 (基地址 0xE000ED00)
 *   - CCR (Configuration and Control Register) - 偏移 0x014, Reset 0x00000201
 *     参考：Table 4-2 Summary of the system control block registers (DUI 100235)
 *           3.3 Configuration and Control Register on page 38 (DDI 100230)
 * - Cortex-M33 NVIC 寄存器 (基地址 0xE000E000)
 *   - ICTR (Interrupt Controller Type Register) - 偏移 0x004
 *     参考：Table 5-1 NVIC register summary (DDI 100230)
 * - Cortex-M33 SAU 寄存器 (基地址 0xE000EDD0)
 *   - SAU_CTRL, SAU_TYPE, SAU_RNR, SAU_RBAR, SAU_RLAR
 *     参考：Table 4-2 SAU register summary (DDI 100230)
 * - Cortex-M33 MPU 寄存器 (基地址 0xE000ED90)
 *   - MPU_TYPE, MPU_CTRL, MPU_RNR, MPU_RBAR, MPU_RLAR, MPU_MAIR0, MPU_MAIR1
 *     参考：Table 4-3 MPU register summary (DDI 100230)
 * - Cortex-M33 FPU 寄存器 (基地址 0xE000EF34)
 *   - FPCCR, FPCAR, FPDSCR, MVFR0, MVFR1, MVFR2
 *     参考：Table 6-1 FPU register summary (DDI 100230)
 * - Cortex-M33 可选调试组件
 *   - DWT: 数据观察点和跟踪单元 (基地址 0xE0001000)
 *   - ITM: 指令跟踪宏单元 (基地址 0xE0000000)
 *   - FPB: Flash Patch 和断点单元 (基地址 0xE0002000)
 *   - TPIU: 跟踪端口接口单元 (基地址 0xE0040000)
 *   - DCB: 调试控制块 (基地址 0xE000EDF0)
 *     参考：Table 9-2 Cortex-M33 Processor ROM table components (DDI 100230)
 * - Cortex-M33 可选 ETM (基地址 0xE0041000)
 *   - ETM: 嵌入式跟踪宏单元
 *     参考：Table 9-2 Cortex-M33 Processor ROM table components (DDI 100230)
 * - Cortex-M33 可选 CTI (基地址 0xE0042000)
 *   - CTI: 交叉触发接口
 *     参考：Table 12-3 CTI register summary (DDI 100230)
 * - Cortex-M33 可选 MTB (基地址 0xE0043000)
 *   - MTB: 微跟踪缓冲器
 *     参考：Table 9-2 Cortex-M33 Processor ROM table components (DDI 100230)
 * - Cortex-M33 ROM 表 (基地址 0xE00FF000)
 *   - ROM_TABLE_BASE
 *     参考：Table 9-1 Cortex-M33 Processor ROM table identification values (DDI 100230)
 * - 注意：Cortex-M33 不支持 PMU (性能监控单元) 和 RAS (可靠性扩展)
 *         这些是 ARMv8-M 架构的可选扩展，但 M33 未实现
 *
 * 与通用 arm_v8m_core.h 的主要差异：
 * 1. ACTLR 寄存器：Cortex-M33 定义了详细的位域 (EXTEXCLALL, SBIST, DISITMATBFLUSH, FPEXCODIS, DISOOFP, DISFOLD, DISMCYCINT)
 * 2. CPUID 寄存器：Cortex-M33 的复位值为 0x411FD210，其中 PARTNO=0xD21 (Cortex-M33)
 * 3. ID_AFR0 寄存器：Cortex-M33 定义了 CDECP 和 CDERTLID 位域，用于 CDE (Custom Datapath Extension) 支持
 * 4. CCR 寄存器：Cortex-M33 定义了 STKOFHFNMIGN 位域，用于栈溢出故障控制
 * 5. 【CM33 特有】新增 ETM 基地址 0xE0041000
 * 6. 【CM33 特有】新增 CTI 基地址 0xE0042000
 * 7. 【CM33 特有】新增 MTB 基地址 0xE0043000
 * 8. 【CM33 特有】新增 ROM 表基地址 0xE00FF000
 * 9. 【CM33 特有】不支持 PMU 和 RAS 扩展（这些是 ARMv8-M 可选扩展，M33 未实现）
 *
 * 通用寄存器 (引用 arm_v8m_core.h):
 *   - SCS: ICTR (0xE000E004) - 通用
 *   - SCB: ICSR, VTOR, AIRCR, SCR, CCR, SHPR1-3, SHCSR, CFSR, HFSR, DFSR,
 *          MMFSR, BFSR, UFSR, MMFAR, BFAR, AFSR, CPACR, NSACR, ID_PFR0-1, ID_DFR0,
 *          ID_MMFR0-3, ID_ISAR0-4, CLIDR, CTR, MVFR0-2 (0xE000ED00 范围)
 *   - FPU: FPCCR, FPCAR, FPDSCR (0xE000EF34 范围)
 *   - SysTick: SYST_CSR, SYST_RVR, SYST_CVR, SYST_CALIB (0xE000E010)
 *   - NVIC: ISER, ICER, ISPR, ICPR, IABR, ITNS, IPR (0xE000E100)
 *   - MPU: MPU_TYPE, MPU_CTRL, MPU_RNR, MPU_RBAR, MPU_RLAR, MPU_MAIR0, MPU_MAIR1 (0xE000ED90)
 *   - SAU: SAU_CTRL, SAU_TYPE, SAU_RNR, SAU_RBAR, SAU_RLAR (0xE000EDD0)
 *   - STIR, 调试寄存器等
 *   参考：arm_v8m_core.h 和 D1.2 System Control Space (SCS)
 ********************************************************************************/

#ifndef __ARM_V8M_CM33_CORE_H__
#define __ARM_V8M_CM33_CORE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "arm_v8m_core.h"

/* ==============================================================================
 * 一、Cortex-M33 特定 SCS 寄存器 (System Control Space)
 * 参考：Table 4-2 Summary of the system control block registers (DUI 100235)
 *       3.4 Auxiliary Control Register on page 39 (DDI 100230)
 * 基地址：0xE000E000
 * 注意：以下寄存器偏移与 arm_v8m_core.h 中定义相同，但描述为 Cortex-M33 特定
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 1.1 辅助控制寄存器 (ACTLR - Auxiliary Control Register)
 * 参考：3.4 Auxiliary Control Register on page 39 (DDI 100230)
 *       Table 3-4 ACTLR bit assignments (DDI 100230)
 *       Table 4-2 Summary of the system control block registers (DUI 100235)
 * 偏移：0x008
 * 复位值：0x00000000
 * 与通用 v8m 的差异：
 *   - 通用 arm_v8m_core.h 中 ACTLR 为 IMPLEMENTATION DEFINED，未定义具体位域
 *   - Cortex-M33 定义了详细的位域：EXTEXCLALL, SBIST, DISITMATBFLUSH, FPEXCODIS,
 *     DISOOFP, DISFOLD, DISMCYCINT
 *   - 该寄存器在安全状态和非安全状态之间有银行化，非安全别名位于 0xE002E008
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_CM33_SCS_ACTLR           ARM_V8M_SCS_ACTLR

/* ==============================================================================
 * 二、Cortex-M33 特定 SCB 寄存器 (System Control Block)
 * 参考：Table 4-2 Summary of the system control block registers (DUI 100235)
 *       3.5 CPUID Base Register on page 41 (DDI 100230)
 * 基地址：0xE000ED00
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 2.1 CPUID 基寄存器 (CPUID - CPUID Base Register)
 * 参考：3.5 CPUID Base Register on page 41 (DDI 100230)
 *       Table 3-5 CPUID bit assignments (DDI 100230)
 *       Table 4-2 Summary of the system control block registers (DUI 100235)
 * 偏移：0x000
 * 复位值：0x411FD210 (r1p0), 0x410FD211 (r0p1), 0x410FD212 (r0p2), 0x410FD213 (r0p3), 0x410FD214 (r0p4)
 * 与通用 v8m 的差异：
 *   - Cortex-M33 的复位值取决于具体修订版本
 *   - 其中：
 *     - IMPLEMENTER = 0x41 (ARM)
 *     - VARIANT = 0x0 或 0x1
 *     - ARCHITECTURE = 0xF
 *     - PARTNO = 0xD21 (Cortex-M33)
 *     - REVISION = 0x0 或 0x1
 *   - 通用 arm_v8m_core.h 中 CPUID 位域定义相同，但复位值取决于具体处理器实现
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_CM33_SCB_CPUID           ARM_V8M_SCB_CPUID

/* -----------------------------------------------------------------------------
 * 2.2 辅助特性寄存器 0 (ID_AFR0 - Auxiliary Feature Register 0)
 * 参考：3.6 Auxiliary Feature Register 0 on page 42 (DDI 100230)
 *       Table 3-6 ID_AFR0 bit assignments (DDI 100230)
 *       Table 4-2 Summary of the system control block registers (DUI 100235)
 * 偏移：0x04C
 * 复位值：取决于 CDEMAPPEDONCP 和 CFGNOCDECP 参数
 * 与通用 v8m 的差异：
 *   - 通用 arm_v8m_core.h 中 ID_AFR0 为 IMPLEMENTATION DEFINED
 *   - Cortex-M33 定义了 CDECP 和 CDERTLID 位域
 *   - CDECP[15:8]: 指示每个协处理器是否被 CDE 模块使用
 *   - CDERTLID[7:0]: 用于读取 CDERTLID 参数值，用于多 Cortex-M33 系统中的 CDE 定制
 *   - 非安全别名位于 0xE002ED4C，在非安全状态下为 RAZ/WI
 *   - 该寄存器不在安全状态之间银行化
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_CM33_SCB_ID_AFR0         ARM_V8M_SCB_ID_AFR0

/* ==============================================================================
 * 三、Cortex-M33 特定配置和控制寄存器
 * 参考：3.3 Configuration and Control Register on page 38 (DDI 100230)
 * 基地址：0xE000ED00
 * 与通用 v8m 的差异：
 *   - Cortex-M33 定义了 STKOFHFNMIGN 位域
 *   - UNALIGN_TRP 固定为 1
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 3.1 配置和控制寄存器 (CCR - Configuration and Control Register)
 * 参考：3.3 Configuration and Control Register on page 38 (DDI 100230)
 *       Table 3-3 CCR bit assignments (DDI 100230)
 *       Table 4-2 Summary of the system control block registers (DUI 100235)
 * 偏移：0x014
 * 复位值：0x00000201
 * 与通用 v8m 的差异：
 *   - Cortex-M33 定义了 STKOFHFNMIGN 位域 (bit[10])
 *   - UNALIGN_TRP 固定为 1
 *   - 该寄存器在安全状态和非安全状态之间有银行化
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_CM33_SCB_CCR             ARM_V8M_SCB_CCR

/* ==============================================================================
 * 四、Cortex-M33 通用寄存器 (引用 arm_v8m_core.h)
 * 以下寄存器在 Cortex-M33 和其他 Armv8-M 处理器之间通用
 * 直接引用 arm_v8m_core.h 中定义的宏
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 4.1 SCS 通用寄存器 (引用)
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_CM33_SCS_BASE            ARM_V8M_SCS_BASE
#define ARM_V8M_CM33_SCS_NS_BASE         ARM_V8M_SCS_NS_BASE
#define ARM_V8M_CM33_SCS_ICTR            ARM_V8M_SCS_ICTR
#define ARM_V8M_CM33_SCS_CPPWR           ARM_V8M_SCS_CPPWR

/* -----------------------------------------------------------------------------
 * 4.2 SCB 通用寄存器 (引用)
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_CM33_SCB_BASE            ARM_V8M_SCB_BASE
#define ARM_V8M_CM33_SCB_NS_BASE         ARM_V8M_SCB_NS_BASE
#define ARM_V8M_CM33_SCB_REVIDR          ARM_V8M_SCB_REVIDR
#define ARM_V8M_CM33_SCB_ICSR            ARM_V8M_SCB_ICSR
#define ARM_V8M_CM33_SCB_VTOR            ARM_V8M_SCB_VTOR
#define ARM_V8M_CM33_SCB_AIRCR           ARM_V8M_SCB_AIRCR
#define ARM_V8M_CM33_SCB_SCR             ARM_V8M_SCB_SCR
#define ARM_V8M_CM33_SCB_SHPR1           ARM_V8M_SCB_SHPR1
#define ARM_V8M_CM33_SCB_SHPR2           ARM_V8M_SCB_SHPR2
#define ARM_V8M_CM33_SCB_SHPR3           ARM_V8M_SCB_SHPR3
#define ARM_V8M_CM33_SCB_SHCSR           ARM_V8M_SCB_SHCSR
#define ARM_V8M_CM33_SCB_CFSR            ARM_V8M_SCB_CFSR
#define ARM_V8M_CM33_SCB_HFSR            ARM_V8M_SCB_HFSR
#define ARM_V8M_CM33_SCB_DFSR            ARM_V8M_SCB_DFSR
#define ARM_V8M_CM33_SCB_MMFSR           ARM_V8M_SCB_MMFSR
#define ARM_V8M_CM33_SCB_BFSR            ARM_V8M_SCB_BFSR
#define ARM_V8M_CM33_SCB_UFSR            ARM_V8M_SCB_UFSR
#define ARM_V8M_CM33_SCB_MMFAR           ARM_V8M_SCB_MMFAR
#define ARM_V8M_CM33_SCB_BFAR            ARM_V8M_SCB_BFAR
#define ARM_V8M_CM33_SCB_AFSR            ARM_V8M_SCB_AFSR
#define ARM_V8M_CM33_SCB_CPACR           ARM_V8M_SCB_CPACR
#define ARM_V8M_CM33_SCB_NSACR           ARM_V8M_SCB_NSACR

/* SCB ID 寄存器 */
#define ARM_V8M_CM33_SCB_ID_PFR0         ARM_V8M_SCB_ID_PFR0
#define ARM_V8M_CM33_SCB_ID_PFR1         ARM_V8M_SCB_ID_PFR1
#define ARM_V8M_CM33_SCB_ID_DFR0         ARM_V8M_SCB_ID_DFR0
#define ARM_V8M_CM33_SCB_ID_MMFR0        ARM_V8M_SCB_ID_MMFR0
#define ARM_V8M_CM33_SCB_ID_MMFR1        ARM_V8M_SCB_ID_MMFR1
#define ARM_V8M_CM33_SCB_ID_MMFR2        ARM_V8M_SCB_ID_MMFR2
#define ARM_V8M_CM33_SCB_ID_MMFR3        ARM_V8M_SCB_ID_MMFR3
#define ARM_V8M_CM33_SCB_ID_ISAR0        ARM_V8M_SCB_ID_ISAR0
#define ARM_V8M_CM33_SCB_ID_ISAR1        ARM_V8M_SCB_ID_ISAR1
#define ARM_V8M_CM33_SCB_ID_ISAR2        ARM_V8M_SCB_ID_ISAR2
#define ARM_V8M_CM33_SCB_ID_ISAR3        ARM_V8M_SCB_ID_ISAR3
#define ARM_V8M_CM33_SCB_ID_ISAR4        ARM_V8M_SCB_ID_ISAR4
#define ARM_V8M_CM33_SCB_ID_ISAR5        ARM_V8M_SCB_ID_ISAR5
#define ARM_V8M_CM33_SCB_CLIDR           ARM_V8M_SCB_CLIDR
#define ARM_V8M_CM33_SCB_CTR             ARM_V8M_SCB_CTR
#define ARM_V8M_CM33_SCB_CCSIDR          ARM_V8M_SCB_CCSIDR
#define ARM_V8M_CM33_SCB_CSSELR          ARM_V8M_SCB_CSSELR

/* SCB 安全扩展寄存器 */
#define ARM_V8M_CM33_SCB_SFSR            ARM_V8M_SCB_SFSR
#define ARM_V8M_CM33_SCB_SFAR            ARM_V8M_SCB_SFAR

/* SCB STIR 寄存器 */
#define ARM_V8M_CM33_SCB_STIR            ARM_V8M_SCB_STIR

/* -----------------------------------------------------------------------------
 * 4.3 SysTick 寄存器 (引用)
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_CM33_SYST_BASE           ARM_V8M_SYST_BASE
#define ARM_V8M_CM33_SYST_NS_BASE        ARM_V8M_SYST_NS_BASE
#define ARM_V8M_CM33_SYST_CSR            ARM_V8M_SYST_CSR
#define ARM_V8M_CM33_SYST_RVR            ARM_V8M_SYST_RVR
#define ARM_V8M_CM33_SYST_CVR            ARM_V8M_SYST_CVR
#define ARM_V8M_CM33_SYST_CALIB          ARM_V8M_SYST_CALIB

/* -----------------------------------------------------------------------------
 * 4.4 NVIC 寄存器 (引用)
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_CM33_NVIC_BASE           ARM_V8M_NVIC_BASE
#define ARM_V8M_CM33_NVIC_NS_BASE        ARM_V8M_NVIC_NS_BASE
#define ARM_V8M_CM33_NVIC_ISERn          ARM_V8M_NVIC_ISERn
#define ARM_V8M_CM33_NVIC_ICERn          ARM_V8M_NVIC_ICERn
#define ARM_V8M_CM33_NVIC_ISPRn          ARM_V8M_NVIC_ISPRn
#define ARM_V8M_CM33_NVIC_ICPRn          ARM_V8M_NVIC_ICPRn
#define ARM_V8M_CM33_NVIC_IABRn          ARM_V8M_NVIC_IABRn
#define ARM_V8M_CM33_NVIC_ITNSn          ARM_V8M_NVIC_ITNSn
#define ARM_V8M_CM33_NVIC_IPRn           ARM_V8M_NVIC_IPRn

/* -----------------------------------------------------------------------------
 * 4.5 MPU 寄存器 (引用)
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_CM33_MPU_BASE            ARM_V8M_MPU_BASE
#define ARM_V8M_CM33_MPU_NS_BASE         ARM_V8M_MPU_NS_BASE
#define ARM_V8M_CM33_MPU_TYPE            ARM_V8M_MPU_TYPE
#define ARM_V8M_CM33_MPU_CTRL            ARM_V8M_MPU_CTRL
#define ARM_V8M_CM33_MPU_RNR             ARM_V8M_MPU_RNR
#define ARM_V8M_CM33_MPU_RBAR            ARM_V8M_MPU_RBAR
#define ARM_V8M_CM33_MPU_RLAR            ARM_V8M_MPU_RLAR
#define ARM_V8M_CM33_MPU_RBAR_A1         ARM_V8M_MPU_RBAR_A1
#define ARM_V8M_CM33_MPU_RLAR_A1         ARM_V8M_MPU_RLAR_A1
#define ARM_V8M_CM33_MPU_RBAR_A2         ARM_V8M_MPU_RBAR_A2
#define ARM_V8M_CM33_MPU_RLAR_A2         ARM_V8M_MPU_RLAR_A2
#define ARM_V8M_CM33_MPU_RBAR_A3         ARM_V8M_MPU_RBAR_A3
#define ARM_V8M_CM33_MPU_RLAR_A3         ARM_V8M_MPU_RLAR_A3
#define ARM_V8M_CM33_MPU_MAIR0           ARM_V8M_MPU_MAIR0
#define ARM_V8M_CM33_MPU_MAIR1           ARM_V8M_MPU_MAIR1

/* -----------------------------------------------------------------------------
 * 4.6 SAU 寄存器 (引用)
 * 注意：SAU 寄存器仅 Secure 状态可访问，无 NS 别名
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_CM33_SAU_BASE            ARM_V8M_SAU_BASE
#define ARM_V8M_CM33_SAU_CTRL            ARM_V8M_SAU_CTRL
#define ARM_V8M_CM33_SAU_TYPE            ARM_V8M_SAU_TYPE
#define ARM_V8M_CM33_SAU_RNR             ARM_V8M_SAU_RNR
#define ARM_V8M_CM33_SAU_RBAR            ARM_V8M_SAU_RBAR
#define ARM_V8M_CM33_SAU_RLAR            ARM_V8M_SAU_RLAR

/* -----------------------------------------------------------------------------
 * 4.7 FPU 寄存器 (引用)
 * 注意：arm_v8m_core.h 中使用 ARM_V8M_REG_ 前缀定义 FPU 寄存器偏移
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_CM33_REG_FPCCR           ARM_V8M_REG_FPCCR
#define ARM_V8M_CM33_REG_FPCAR           ARM_V8M_REG_FPCAR
#define ARM_V8M_CM33_REG_FPDSCR          ARM_V8M_REG_FPDSCR
#define ARM_V8M_CM33_REG_MVFR0           ARM_V8M_REG_MVFR0
#define ARM_V8M_CM33_REG_MVFR1           ARM_V8M_REG_MVFR1
#define ARM_V8M_CM33_REG_MVFR2           ARM_V8M_REG_MVFR2

/* -----------------------------------------------------------------------------
 * 4.8 缓存维护操作寄存器 (引用)
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_CM33_CACHE_BASE          ARM_V8M_CACHE_BASE
#define ARM_V8M_CM33_CACHE_NS_BASE       ARM_V8M_CACHE_NS_BASE
#define ARM_V8M_CM33_CACHE_ICIALLU       ARM_V8M_CACHE_ICIALLU
#define ARM_V8M_CM33_CACHE_ICIMVAU       ARM_V8M_CACHE_ICIMVAU
#define ARM_V8M_CM33_CACHE_DCIMVAC       ARM_V8M_CACHE_DCIMVAC
#define ARM_V8M_CM33_CACHE_DCISW         ARM_V8M_CACHE_DCISW
#define ARM_V8M_CM33_CACHE_DCCMVAU       ARM_V8M_CACHE_DCCMVAU
#define ARM_V8M_CM33_CACHE_DCCMVAC       ARM_V8M_CACHE_DCCMVAC
#define ARM_V8M_CM33_CACHE_DCCSW         ARM_V8M_CACHE_DCCSW
#define ARM_V8M_CM33_CACHE_DCCIMVAC      ARM_V8M_CACHE_DCCIMVAC
#define ARM_V8M_CM33_CACHE_DCCISW        ARM_V8M_CACHE_DCCISW
#define ARM_V8M_CM33_CACHE_BPIALL        ARM_V8M_CACHE_BPIALL

/* ==============================================================================
 * 五、Cortex-M33 可选调试组件基地址
 * 参考：Table 5-1 NVIC register summary (DDI 100230)
 *       Table 6-1 FPU register summary (DDI 100230)
 * 注意：这些组件是可选的，根据具体实现可能不存在
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 5.1 数据观察点和跟踪单元 (DWT - Data Watchpoint and Trace Unit)
 * 参考：DWT register summary (DDI 100230)
 * 地址：0xE0001000
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_CM33_DWT_BASE            ARM_V8M_DWT_BASE
#define ARM_V8M_CM33_DWT_CTRL            ARM_V8M_DWT_CTRL
#define ARM_V8M_CM33_DWT_CYCCNT          ARM_V8M_DWT_CYCCNT
#define ARM_V8M_CM33_DWT_CPICNT          ARM_V8M_DWT_CPICNT
#define ARM_V8M_CM33_DWT_EXCCNT          ARM_V8M_DWT_EXCCNT
#define ARM_V8M_CM33_DWT_SLEEPCNT        ARM_V8M_DWT_SLEEPCNT
#define ARM_V8M_CM33_DWT_LSUCNT          ARM_V8M_DWT_LSUCNT
#define ARM_V8M_CM33_DWT_FOLDCNT         ARM_V8M_DWT_FOLDCNT
#define ARM_V8M_CM33_DWT_PCSR            ARM_V8M_DWT_PCSR
#define ARM_V8M_CM33_DWT_COMPn           ARM_V8M_DWT_COMPn
#define ARM_V8M_CM33_DWT_MASKn           ARM_V8M_DWT_MASKn
#define ARM_V8M_CM33_DWT_FUNCTIONn       ARM_V8M_DWT_FUNCTIONn
#define ARM_V8M_CM33_DWT_LAR             ARM_V8M_DWT_LAR
#define ARM_V8M_CM33_DWT_LSR             ARM_V8M_DWT_LSR
#define ARM_V8M_CM33_DWT_DEVARCH         ARM_V8M_DWT_DEVARCH
#define ARM_V8M_CM33_DWT_DEVTYPE         ARM_V8M_DWT_DEVTYPE

/* -----------------------------------------------------------------------------
 * 5.2 指令跟踪宏单元 (ITM - Instrumentation Trace Macrocell)
 * 参考：ITM register summary (DDI 100230)
 * 地址：0xE0000000
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_CM33_ITM_BASE            ARM_V8M_ITM_BASE
#define ARM_V8M_CM33_ITM_STIMn           ARM_V8M_ITM_STIMn
#define ARM_V8M_CM33_ITM_TERn            ARM_V8M_ITM_TERn
#define ARM_V8M_CM33_ITM_TPR             ARM_V8M_ITM_TPR
#define ARM_V8M_CM33_ITM_TCR             ARM_V8M_ITM_TCR
#define ARM_V8M_CM33_ITM_LAR             ARM_V8M_ITM_LAR
#define ARM_V8M_CM33_ITM_LSR             ARM_V8M_ITM_LSR
#define ARM_V8M_CM33_ITM_DEVARCH         ARM_V8M_ITM_DEVARCH
#define ARM_V8M_CM33_ITM_DEVTYPE         ARM_V8M_ITM_DEVTYPE

/* -----------------------------------------------------------------------------
 * 5.3 Flash Patch 和断点单元 (FPB - Flash Patch and Breakpoint Unit)
 * 参考：FPB register summary (DDI 100230)
 * 地址：0xE0002000
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_CM33_FPB_BASE            ARM_V8M_FPB_BASE
#define ARM_V8M_CM33_FPB_CTRL            ARM_V8M_FPB_CTRL
#define ARM_V8M_CM33_FPB_REMAP           ARM_V8M_FPB_REMAP
#define ARM_V8M_CM33_FPB_COMPn           ARM_V8M_FPB_COMPn
#define ARM_V8M_CM33_FPB_LAR             ARM_V8M_FPB_LAR
#define ARM_V8M_CM33_FPB_LSR             ARM_V8M_FPB_LSR
#define ARM_V8M_CM33_FPB_DEVARCH         ARM_V8M_FPB_DEVARCH
#define ARM_V8M_CM33_FPB_DEVTYPE         ARM_V8M_FPB_DEVTYPE

/* -----------------------------------------------------------------------------
 * 5.4 跟踪端口接口单元 (TPIU - Trace Port Interface Unit)
 * 参考：TPIU register summary (DDI 100230)
 * 地址：0xE0040000
 * 注意：TPIU 寄存器没有 NS 别名
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_CM33_TPIU_BASE           ARM_V8M_TPIU_BASE
#define ARM_V8M_CM33_TPIU_SSPSR          ARM_V8M_TPIU_SSPSR
#define ARM_V8M_CM33_TPIU_CSPSR          ARM_V8M_TPIU_CSPSR
#define ARM_V8M_CM33_TPIU_ACPR           ARM_V8M_TPIU_ACPR
#define ARM_V8M_CM33_TPIU_SPPR           ARM_V8M_TPIU_SPPR
#define ARM_V8M_CM33_TPIU_FFSR           ARM_V8M_TPIU_FFSR
#define ARM_V8M_CM33_TPIU_FFCR           ARM_V8M_TPIU_FFCR
#define ARM_V8M_CM33_TPIU_PSCR           ARM_V8M_TPIU_PSCR
#define ARM_V8M_CM33_TPIU_CLAIMSET       ARM_V8M_TPIU_CLAIMSET
#define ARM_V8M_CM33_TPIU_CLAIMCLR       ARM_V8M_TPIU_CLAIMCLR
#define ARM_V8M_CM33_TPIU_LAR            ARM_V8M_TPIU_LAR
#define ARM_V8M_CM33_TPIU_LSR            ARM_V8M_TPIU_LSR
#define ARM_V8M_CM33_TPIU_DEVID          ARM_V8M_TPIU_DEVID
#define ARM_V8M_CM33_TPIU_DEVTYPE        ARM_V8M_TPIU_DEVTYPE

/* -----------------------------------------------------------------------------
 * 5.5 调试控制块 (DCB - Debug Control Block)
 * 参考：Debug register summary (DDI 100230)
 * 地址：0xE000EDF0
 * -----------------------------------------------------------------------------
 */
#define ARM_V8M_CM33_DCB_BASE            ARM_V8M_DCB_BASE
#define ARM_V8M_CM33_DCB_NS_BASE         ARM_V8M_DCB_NS_BASE
#define ARM_V8M_CM33_DCB_DHCSR           ARM_V8M_DCB_DHCSR
#define ARM_V8M_CM33_DCB_DCRSR           ARM_V8M_DCB_DCRSR
#define ARM_V8M_CM33_DCB_DCRDR           ARM_V8M_DCB_DCRDR
#define ARM_V8M_CM33_DCB_DEMCR           ARM_V8M_DCB_DEMCR
#define ARM_V8M_CM33_DCB_DSCEMCR         ARM_V8M_DCB_DSCEMCR
#define ARM_V8M_CM33_DCB_DAUTHCTRL       ARM_V8M_DCB_DAUTHCTRL
#define ARM_V8M_CM33_DCB_DSCSR           ARM_V8M_DCB_DSCSR

/* ==============================================================================
 * 六、Cortex-M33 组件识别寄存器
 * 参考：Table 3-2 System control registers (DDI 100230)
 * 地址范围：0xE000EFB0 - 0xE000EFFC
 * ==============================================================================
 */
#define ARM_V8M_CM33_DID_BASE            ARM_V8M_DID_BASE
#define ARM_V8M_CM33_DID_NS_BASE         ARM_V8M_DID_NS_BASE
#define ARM_V8M_CM33_DID_DLAR            ARM_V8M_DID_DLAR
#define ARM_V8M_CM33_DID_DLSR            ARM_V8M_DID_DLSR
#define ARM_V8M_CM33_DID_DAUTHSTATUS     ARM_V8M_DID_DAUTHSTATUS
#define ARM_V8M_CM33_DID_DDEVARCH        ARM_V8M_DID_DDEVARCH
#define ARM_V8M_CM33_DID_DDEVTYPE        ARM_V8M_DID_DDEVTYPE
#define ARM_V8M_CM33_DID_DPIDR4          ARM_V8M_DID_DPIDR4
#define ARM_V8M_CM33_DID_DPIDR5          ARM_V8M_DID_DPIDR5
#define ARM_V8M_CM33_DID_DPIDR6          ARM_V8M_DID_DPIDR6
#define ARM_V8M_CM33_DID_DPIDR7          ARM_V8M_DID_DPIDR7
#define ARM_V8M_CM33_DID_DPIDR0          ARM_V8M_DID_DPIDR0
#define ARM_V8M_CM33_DID_DPIDR1          ARM_V8M_DID_DPIDR1
#define ARM_V8M_CM33_DID_DPIDR2          ARM_V8M_DID_DPIDR2
#define ARM_V8M_CM33_DID_DPIDR3          ARM_V8M_DID_DPIDR3
#define ARM_V8M_CM33_DID_DCIDR0          ARM_V8M_DID_DCIDR0
#define ARM_V8M_CM33_DID_DCIDR1          ARM_V8M_DID_DCIDR1
#define ARM_V8M_CM33_DID_DCIDR2          ARM_V8M_DID_DCIDR2
#define ARM_V8M_CM33_DID_DCIDR3          ARM_V8M_DID_DCIDR3

/* ==============================================================================
 * 七、Cortex-M33 可选嵌入式跟踪宏单元 (ETM - Embedded Trace Macrocell)
 * 参考：Table 9-2 Cortex-M33 Processor ROM table components (DDI 100230)
 *       See the Arm® CoreSight™ ETM-M33 Technical Reference Manual
 * 基地址：0xE0041000
 * 注意：ETM 寄存器没有 NS 别名
 *       此组件是可选的，如果未实现则 ROM 表中对应条目读取为 0xFFF42002
 * 【CM33 特有】ETM 基地址和寄存器在 arm_v8m_core.h 中未定义，此处新增
 *       详细的寄存器定义请参考 ETM-M33 Technical Reference Manual
 * ==============================================================================
 */
#define ARM_V8M_CM33_ETM_BASE            0xE0041000UL

/* ==============================================================================
 * 八、Cortex-M33 可选交叉触发接口 (CTI - Cross Trigger Interface)
 * 参考：Table 9-2 Cortex-M33 Processor ROM table components (DDI 100230)
 *       Table 12-3 CTI register summary (DDI 100230)
 * 基地址：0xE0042000
 * 注意：CTI 寄存器没有 NS 别名
 *       此组件是可选的，如果未实现则 ROM 表中对应条目读取为 0xFFF43002
 * 【CM33 特有】CTI 基地址和寄存器在 arm_v8m_core.h 中未定义，此处新增
 *       CTI 使能调试逻辑、MTB 和 ETM 之间相互交互
 *       详细的寄存器定义请参考 Arm® CoreSight™ SoC-400 Technical Reference Manual
 * 注意：ROM 表中 CTI 条目值为 0xFFF43003，按 CoreSight 规范计算出的基地址为
 *       0xE0043000，但 Table 12-3 中 CTI 寄存器地址从 0xE0042000 开始。
 *       此处采用 Table 12-3 中的地址 0xE0042000 作为 CTI 基地址。
 * ==============================================================================
 */
#define ARM_V8M_CM33_CTI_BASE            0xE0042000UL

/* CTI 寄存器偏移定义 (参考 Table 12-3 CTI register summary) */
#define ARM_V8M_CM33_CTI_CONTROL         0x000   /* CTI Control Register [RW] */
#define ARM_V8M_CM33_CTI_INTACK          0x010   /* CTI Interrupt Acknowledge Register [WO] */
#define ARM_V8M_CM33_CTI_APPSET          0x014   /* CTI Application Trigger Set Register [RW] */
#define ARM_V8M_CM33_CTI_APPCLEAR        0x018   /* CTI Application Trigger Clear Register [RW] */
#define ARM_V8M_CM33_CTI_APPPULSE        0x01C   /* CTI Application Pulse Register [WO] */
#define ARM_V8M_CM33_CTI_INEN0           0x020   /* CTI Trigger to Channel Enable Register 0 [RW] */
#define ARM_V8M_CM33_CTI_INEN1           0x024   /* CTI Trigger to Channel Enable Register 1 [RW] */
#define ARM_V8M_CM33_CTI_INEN2           0x028   /* CTI Trigger to Channel Enable Register 2 [RW] */
#define ARM_V8M_CM33_CTI_INEN3           0x02C   /* CTI Trigger to Channel Enable Register 3 [RW] */
#define ARM_V8M_CM33_CTI_INEN4           0x030   /* CTI Trigger to Channel Enable Register 4 [RW] */
#define ARM_V8M_CM33_CTI_INEN5           0x034   /* CTI Trigger to Channel Enable Register 5 [RW] */
#define ARM_V8M_CM33_CTI_INEN6           0x038   /* CTI Trigger to Channel Enable Register 6 [RW] */
#define ARM_V8M_CM33_CTI_INEN7           0x03C   /* CTI Trigger to Channel Enable Register 7 [RW] */
#define ARM_V8M_CM33_CTI_OUTEN0          0x0A0   /* CTI Channel to Trigger Enable Register 0 [RW] */
#define ARM_V8M_CM33_CTI_OUTEN1          0x0A4   /* CTI Channel to Trigger Enable Register 1 [RW] */
#define ARM_V8M_CM33_CTI_OUTEN2          0x0A8   /* CTI Channel to Trigger Enable Register 2 [RW] */
#define ARM_V8M_CM33_CTI_OUTEN3          0x0AC   /* CTI Channel to Trigger Enable Register 3 [RW] */
#define ARM_V8M_CM33_CTI_OUTEN4          0x0B0   /* CTI Channel to Trigger Enable Register 4 [RW] */
#define ARM_V8M_CM33_CTI_OUTEN5          0x0B4   /* CTI Channel to Trigger Enable Register 5 [RW] */
#define ARM_V8M_CM33_CTI_OUTEN6          0x0B8   /* CTI Channel to Trigger Enable Register 6 [RW] */
#define ARM_V8M_CM33_CTI_OUTEN7          0x0BC   /* CTI Channel to Trigger Enable Register 7 [RW] */
#define ARM_V8M_CM33_CTI_TRIGINSTATUS    0x130   /* CTI Trigger In Status Register [RO] */
#define ARM_V8M_CM33_CTI_TRIGOUTSTATUS   0x134   /* CTI Trigger Out Status Register [RO] */
#define ARM_V8M_CM33_CTI_CHINSTATUS      0x138   /* CTI Channel In Status Register [RO] */
#define ARM_V8M_CM33_CTI_GATE            0x140   /* Enable CTI Channel Gate Register [RW] */
#define ARM_V8M_CM33_CTI_ASICCTL         0x144   /* External Multiplexer Control Register [RO] */
#define ARM_V8M_CM33_CTI_ITCHOUT         0x2E4   /* Integration Test Channel Output Register [WO] */
#define ARM_V8M_CM33_CTI_ITTRIGOUT       0x2E8   /* Integration Test Trigger Output Register [WO] */
#define ARM_V8M_CM33_CTI_ITCHIN          0x2F4   /* Integration Test Channel Input Register [RO] */
#define ARM_V8M_CM33_CTI_ITCTRL          0x300   /* Integration Mode Control Register [RW] */
#define ARM_V8M_CM33_CTI_DEVARCH         0x3BC   /* Device Architecture Register [RO] */
#define ARM_V8M_CM33_CTI_DEVID           0x3C8   /* Device Configuration Register [RO] */
#define ARM_V8M_CM33_CTI_DEVTYPE         0x3CC   /* Device Type Identifier Register [RO] */
#define ARM_V8M_CM33_CTI_PIDR4           0x3D0   /* Peripheral ID4 Register [RO] */
#define ARM_V8M_CM33_CTI_PIDR5           0x3D4   /* Peripheral ID5 Register [RO] */
#define ARM_V8M_CM33_CTI_PIDR6           0x3D8   /* Peripheral ID6 Register [RO] */
#define ARM_V8M_CM33_CTI_PIDR7           0x3DC   /* Peripheral ID7 Register [RO] */
#define ARM_V8M_CM33_CTI_PIDR0           0x3E0   /* Peripheral ID0 Register [RO] */
#define ARM_V8M_CM33_CTI_PIDR1           0x3E4   /* Peripheral ID1 Register [RO] */
#define ARM_V8M_CM33_CTI_PIDR2           0x3E8   /* Peripheral ID2 Register [RO] */
#define ARM_V8M_CM33_CTI_PIDR3           0x3EC   /* Peripheral ID3 Register [RO] */
#define ARM_V8M_CM33_CTI_CIDR0           0x3F0   /* Component ID0 Register [RO] */
#define ARM_V8M_CM33_CTI_CIDR1           0x3F4   /* Component ID1 Register [RO] */
#define ARM_V8M_CM33_CTI_CIDR2           0x3F8   /* Component ID2 Register [RO] */
#define ARM_V8M_CM33_CTI_CIDR3           0x3FC   /* Component ID3 Register [RO] */

/* ==============================================================================
 * 九、Cortex-M33 可选微跟踪缓冲器 (MTB - Micro Trace Buffer)
 * 参考：Table 9-2 Cortex-M33 Processor ROM table components (DDI 100230)
 * 基地址：0xE0043000
 * 注意：MTB 寄存器没有 NS 别名
 *       此组件是可选的，如果未实现则 ROM 表中对应条目读取为 0xFFF44002
 * 【CM33 特有】MTB 基地址和寄存器在 arm_v8m_core.h 中未定义，此处新增
 *       MTB 提供简单的指令跟踪功能
 *       详细的寄存器定义请参考 MTB-M33 Technical Reference Manual
 * ==============================================================================
 */
#define ARM_V8M_CM33_MTB_BASE            0xE0043000UL

/* ==============================================================================
 * 十、Cortex-M33 ROM 表
 * 参考：Table 9-1 Cortex-M33 Processor ROM table identification values (DDI 100230)
 *       Table 9-2 Cortex-M33 Processor ROM table components (DDI 100230)
 * 地址：0xE00FF000
 * 【CM33 特有】ROM 表基地址在 arm_v8m_core.h 中未定义，此处新增
 *       ROM 表用于发现调试组件
 * ==============================================================================
 */
#define ARM_V8M_CM33_ROM_TABLE_BASE      0xE00FF000UL

/* ==============================================================================
 * 十一、Cortex-M33 特性值定义
 * 参考：Table 4-2 Summary of the system control block registers (DUI 100235)
 * 说明：这些值用于识别 Cortex-M33 处理器特性
 * ==============================================================================
 */

/* CPUID 寄存器值 */
#define ARM_V8M_CM33_CPUID_IMPLEMENTER   0x41UL   /* ARM Limited */
#define ARM_V8M_CM33_CPUID_PARTNO        0xD21UL  /* Cortex-M33 */
#define ARM_V8M_CM33_CPUID_ARCHITECTURE  0xFUL    /* ARMv8-M */

/* CCR 寄存器复位值 */
#define ARM_V8M_CM33_CCR_RESET_VALUE     0x00000201UL

/* ID_AFR0 寄存器位域掩码 */
#define ARM_V8M_CM33_ID_AFR0_CDECP_MASK      0x0000FF00UL  /* CDE Coprocessor mask */
#define ARM_V8M_CM33_ID_AFR0_CDERTLID_MASK   0x000000FFUL  /* CDE RTL ID mask */

/* ACTLR 寄存器位域掩码 */
#define ARM_V8M_CM33_ACTLR_EXTEXCLALL_MASK   0x20000000UL  /* External Exclusive All */
#define ARM_V8M_CM33_ACTLR_SBIST_MASK        0x00002000UL  /* Software Test Library */
#define ARM_V8M_CM33_ACTLR_DISITMATBFLUSH_MASK 0x00001000UL  /* ITM/DWT ATB Flush Disable */
#define ARM_V8M_CM33_ACTLR_FPEXCODIS_MASK    0x00000400UL  /* FPU Exception Output Disable */
#define ARM_V8M_CM33_ACTLR_DISOOFP_MASK      0x00000200UL  /* Disable Out-of-order FP */
#define ARM_V8M_CM33_ACTLR_DISFOLD_MASK      0x00000004UL  /* Disable Dual-issue */
#define ARM_V8M_CM33_ACTLR_DISMCYCINT_MASK   0x00000001UL  /* Disable Multi-cycle Interrupt */

#ifdef __cplusplus
}
#endif

#endif /* __ARM_V8M_CM33_CORE_H__ */
