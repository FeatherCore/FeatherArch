/********************************************************************************
 * @file        arm_v7m_cm4_core.h
 * @brief       ARM Cortex-M4 Processor Register Definitions
 * @details     基于 Cortex-M4 Devices Generic User Guide (ARM DUI 0553B)
 *              和 Cortex-M4 Processor Technical Reference Manual (100166_0001_04_en)
 *              文档路径：
 *              - g:\develop\FeatherCore\FeatherArch\docs\arm\Arm® Cortex™-M4 Devices Generic User Guide.txt
 *              - g:\develop\FeatherCore\FeatherArch\docs\arm\Arm® Cortex™-M4 Processor Technical Reference Manual.txt
 * @author      FeatherCore
 * @version     1.0.0
 * @date        2026-03-29
 * @note        本文件仅包含寄存器定义和描述，位域定义在单独的头文件中
 *              通用寄存器引用自 arm_v7m_core.h
 *
 * 寄存器覆盖清单：
 * - Cortex-M4 特定 SCS 寄存器 (偏移 0xE000E008)
 *   - ACTLR (Auxiliary Control Register) - 0xE000E008
 *     参考：4.2 Auxiliary Control Register, ACTLR on page 4-53 (DUI 0553B)
 *           Table 4-1 System control registers (100166_0001_04_en)
 * - Cortex-M4 特定 SCB 寄存器 (偏移 0xE000ED00)
 *   - CPUID (CPUID Base Register) - 0xE000ED00, Reset 0x410FC241
 *     参考：4.3 CPUID Base Register, CPUID on page 4-54 (DUI 0553B)
 *           Table 4-1 System control registers (100166_0001_04_en)
 *   - CPACR (Coprocessor Access Control Register) - 0xE000ED88
 *     参考：4.6.1 Coprocessor Access Control Register on page 4-48 (DUI 0553B)
 *           Table 4-1 System control registers (100166_0001_04_en)
 *   - AFSR (Auxiliary Fault Status Register) - 0xE000ED3C
 *     参考：4.4 Auxiliary Fault Status Register, AFSR on page 4-55 (DUI 0553B)
 *           Table 4-1 System control registers (100166_0001_04_en)
 * - Cortex-M4F FPU 寄存器 (基地址 0xE000EF30)
 *   - FPCCR, FPCAR, FPDSCR, MVFR0, MVFR1
 *     参考：4.6 Floating Point Unit (FPU) on page 4-48 (DUI 0553B)
 *           Table 7-4 Cortex-M4 Floating Point system registers (100166_0001_04_en)
 * - Cortex-M4 可选调试组件寄存器
 *   - DWT: CTRL, CYCCNT, CPICNT, EXCCNT, SLEEPCNT, LSUCNT, FOLDCNT, PCSR,
 *          COMP(n), MASK(n), FUNCTION(n), LAR, LSR (基地址 0xE0001000)
 *     参考：9.2 DWT Programmers' model on page 9-85 (100166_0001_04_en)
 *           Table 9-1 DWT register summary (100166_0001_04_en)
 *   - ITM: STIM(n), TER(n), TPR, TCR, LAR, LSR (基地址 0xE0000000)
 *     参考：10.2 ITM programmers model on page 10-89 (100166_0001_04_en)
 *           Table 10-1 ITM register summary (100166_0001_04_en)
 *   - FPB: CTRL, REMAP, COMP(n), LAR, LSR (基地址 0xE0002000)
 *     参考：8.3 Flash Patch and Breakpoint Unit (FPB) on page 8-81 (100166_0001_04_en)
 *   - TPIU: SSPSR, CSPSR, ACPR, SPPR, TYPE, LAR, LSR (基地址 0xE0040000)
 *     参考：11.3 TPIU programmers model on page 11-95 (100166_0001_04_en)
 *           Table 11-1 TPIU register summary (100166_0001_04_en)
 *   - ETM: (基地址 0xE0041000) - 详见 ETM-M4 Technical Reference Manual
 *     参考：Table 8-2 Cortex-M4 ROM table components (100166_0001_04_en)
 * - Cortex-M4 ROM 表基地址
 *   - ROM_TABLE_BASE
 *     参考：Table 8-1 Cortex-M4 ROM table identification values (100166_0001_04_en)
 *
 * 与通用 arm_v7m_core.h 的主要差异：
 * 1. ACTLR 寄存器：Cortex-M4 定义了具体的位域 (DISMCYCINT, DISDEFWBUF, DISFOLD, DISFPCA, DISOOFP)，
 *    而通用 arm_v7m_core.h 中 ACTLR 为 IMPLEMENTATION DEFINED
 * 2. CPUID 寄存器：Cortex-M4 的复位值为 0x410FC241，其中 PARTNO=0xC24, REVISION=0x1
 * 3. FPU 寄存器：Cortex-M4F 实现 FPv4-SP，仅支持单精度浮点，MVFR2 读取为 0
 * 4. ETM 基地址：Cortex-M4 定义了 ETM 基地址 0xE0041000
 *
 * 通用寄存器 (引用 arm_v7m_core.h):
 *   - SCS: ICTR (0xE000E004) - 通用
 *   - SCB: ICSR, VTOR, AIRCR, SCR, CCR, SHPR1-3, SHCSR, CFSR, HFSR, DFSR,
 *          MMFSR, BFSR, UFSR, MMFAR, BFAR (0xE000ED00 范围)
 *   - FPU: FPCCR, FPCAR, FPDSCR, MVFR0, MVFR1, MVFR2 (0xE000EF30 范围)
 *   - SysTick: SYST_CSR, SYST_RVR, SYST_CVR, SYST_CALIB (0xE000E010)
 *   - NVIC: ISER, ICER, ISPR, ICPR, IABR, IPR (0xE000E100)
 *   - MPU: MPU_TYPE, MPU_CTRL, MPU_RNR, MPU_RBAR, MPU_RASR 等 (0xE000ED90)
 *   - Cache 维护，STIR, 调试寄存器等
 *   参考：arm_v7m_core.h 和 B3.2 System Control Space (SCS) on page B3-595
 ********************************************************************************/

#ifndef __ARM_V7M_CM4_CORE_H__
#define __ARM_V7M_CM4_CORE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "arm_v7m_core.h"

/* ==============================================================================
 * 一、Cortex-M4 特定 SCS 寄存器 (System Control Space)
 * 参考：Table 4-1 System control registers (100166_0001_04_en)
 *       4.2 Auxiliary Control Register, ACTLR on page 4-53 (DUI 0553B)
 * 基地址：0xE000E000
 * 注意：以下寄存器偏移与 arm_v7m_core.h 中定义相同，但描述为 Cortex-M4 特定
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 1.1 辅助控制寄存器 (ACTLR - Auxiliary Control Register)
 * 参考：4.2 Auxiliary Control Register, ACTLR on page 4-53 (DUI 0553B)
 *       Table 4-2 ACTLR bit assignments (DUI 0553B)
 *       Table 4-1 System control registers (100166_0001_04_en)
 * 地址：0xE000E008
 * 复位值：0x00000000
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_core.h 中 ACTLR 为 IMPLEMENTATION DEFINED，未定义具体位域
 *   - Cortex-M4 定义了具体的位域：DISMCYCINT, DISDEFWBUF, DISFOLD, DISFPCA, DISOOFP
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM4_SCS_ACTLR           ARM_V7M_SCS_ACTLR

/* ==============================================================================
 * 二、Cortex-M4 特定 SCB 寄存器 (System Control Block)
 * 参考：Table 4-1 System control registers (100166_0001_04_en)
 *       4.3 CPUID Base Register, CPUID on page 4-54 (DUI 0553B)
 *       4.4 Auxiliary Fault Status Register, AFSR on page 4-55 (DUI 0553B)
 * 基地址：0xE000ED00
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 2.1 CPUID 基寄存器 (CPUID - CPUID Base Register)
 * 参考：4.3 CPUID Base Register, CPUID on page 4-54 (DUI 0553B)
 *       Table 4-3 CPUID bit assignments (DUI 0553B)
 *       Table 4-1 System control registers (100166_0001_04_en)
 * 地址：0xE000ED00
 * 复位值：0x410FC241
 * 与通用 v7m 的差异：
 *   - Cortex-M4 的复位值为 0x410FC241，其中：
 *     - IMPLEMENTER = 0x41 (ARM)
 *     - VARIANT = 0x0
 *     - ARCHITECTURE = 0xF
 *     - PARTNO = 0xC24 (Cortex-M4)
 *     - REVISION = 0x1
 *   - 通用 arm_v7m_core.h 中 CPUID 位域定义相同，但复位值取决于具体处理器实现
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM4_SCB_CPUID           ARM_V7M_SCB_CPUID

/* -----------------------------------------------------------------------------
 * 2.2 辅助故障状态寄存器 (AFSR - Auxiliary Fault Status Register)
 * 参考：4.4 Auxiliary Fault Status Register, AFSR on page 4-55 (DUI 0553B)
 *       Table 4-4 AFSR bit assignments (DUI 0553B)
 *       Table 4-1 System control registers (100166_0001_04_en)
 * 地址：0xE000ED3C
 * 复位值：0x00000000
 * 与通用 v7m 的差异：
 *   - Cortex-M4 中 AFSR 为 32 位 IMPLEMENTATION DEFINED 寄存器
 *   - 每位对应一个 AUXFAULT 输入信号
 *   - 写 1 清除，写 0 无影响
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM4_SCB_AFSR            ARM_V7M_SCB_AFSR

/* -----------------------------------------------------------------------------
 * 2.3 协处理器访问控制寄存器 (CPACR - Coprocessor Access Control Register)
 * 参考：4.6.1 Coprocessor Access Control Register on page 4-48 (DUI 0553B)
 *       Table 4-1 System control registers (100166_0001_04_en)
 * 地址：0xE000ED88
 * 复位值：0x00000000
 * 与通用 v7m 的差异：
 *   - Cortex-M4F 中 CPACR 用于控制 FPU (CP10/CP11) 的访问权限
 *   - 通用 arm_v7m_core.h 中定义相同，但实际使用取决于处理器是否实现 FPU
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM4_SCB_CPACR           ARM_V7M_SCB_CPACR

/* ==============================================================================
 * 三、Cortex-M4F 浮点单元 (FPU) 寄存器
 * 参考：4.6 Floating Point Unit (FPU) on page 4-48 (DUI 0553B)
 *       Chapter 7 Floating-Point Unit (100166_0001_04_en)
 *       7.3 FPU programmers model on page 7-71 (100166_0001_04_en)
 *       Table 7-4 Cortex-M4 Floating Point system registers (100166_0001_04_en)
 * 基地址：0xE000EF30
 * 与通用 v7m 的差异：
 *   - Cortex-M4 实现 FPv4-SP 扩展，仅支持单精度浮点运算
 *   - MVFR2 寄存器在 Cortex-M4 中读取为 0 (不支持 FPv5)
 *   - 通用 arm_v7m_core.h 中定义相同，但实际可用性取决于处理器是否实现 FPU
 * 注意：这些寄存器仅在实现了 FPU (Cortex-M4F) 的处理器中存在
 *       偏移和定义引用自 arm_v7m_core.h
 * ==============================================================================
 */
#define ARM_V7M_CM4_FPU_BASE            ARM_V7M_FPU_BASE

#define ARM_V7M_CM4_FPU_FPCCR          ARM_V7M_FPU_FPCCR
#define ARM_V7M_CM4_FPU_FPCAR          ARM_V7M_FPU_FPCAR
#define ARM_V7M_CM4_FPU_FPDSCR         ARM_V7M_FPU_FPDSCR
#define ARM_V7M_CM4_FPU_MVFR0          ARM_V7M_FPU_MVFR0
#define ARM_V7M_CM4_FPU_MVFR1          ARM_V7M_FPU_MVFR1
#define ARM_V7M_CM4_FPU_MVFR2          ARM_V7M_FPU_MVFR2

/* ==============================================================================
 * 四、Cortex-M4 通用寄存器 (引用 arm_v7m_core.h)
 * 以下寄存器在 Cortex-M4 和其他 Armv7-M 处理器之间通用
 * 直接引用 arm_v7m_core.h 中定义的宏
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 4.1 SCS 通用寄存器 (引用)
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM4_SCS_BASE            ARM_V7M_SCS_BASE
#define ARM_V7M_CM4_SCS_ICTR            ARM_V7M_SCS_ICTR

/* -----------------------------------------------------------------------------
 * 4.2 SCB 通用寄存器 (引用)
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM4_SCB_BASE            ARM_V7M_SCB_BASE
#define ARM_V7M_CM4_SCB_ICSR            ARM_V7M_SCB_ICSR
#define ARM_V7M_CM4_SCB_VTOR            ARM_V7M_SCB_VTOR
#define ARM_V7M_CM4_SCB_AIRCR           ARM_V7M_SCB_AIRCR
#define ARM_V7M_CM4_SCB_SCR             ARM_V7M_SCB_SCR
#define ARM_V7M_CM4_SCB_CCR             ARM_V7M_SCB_CCR
#define ARM_V7M_CM4_SCB_SHPR1           ARM_V7M_SCB_SHPR1
#define ARM_V7M_CM4_SCB_SHPR2           ARM_V7M_SCB_SHPR2
#define ARM_V7M_CM4_SCB_SHPR3           ARM_V7M_SCB_SHPR3
#define ARM_V7M_CM4_SCB_SHCSR           ARM_V7M_SCB_SHCSR
#define ARM_V7M_CM4_SCB_CFSR            ARM_V7M_SCB_CFSR
#define ARM_V7M_CM4_SCB_HFSR            ARM_V7M_SCB_HFSR
#define ARM_V7M_CM4_SCB_DFSR            ARM_V7M_SCB_DFSR
#define ARM_V7M_CM4_SCB_MMFSR           ARM_V7M_SCB_MMFSR
#define ARM_V7M_CM4_SCB_BFSR            ARM_V7M_SCB_BFSR
#define ARM_V7M_CM4_SCB_UFSR            ARM_V7M_SCB_UFSR
#define ARM_V7M_CM4_SCB_MMFAR           ARM_V7M_SCB_MMFAR
#define ARM_V7M_CM4_SCB_BFAR            ARM_V7M_SCB_BFAR

/* SCB ID 寄存器 */
#define ARM_V7M_CM4_SCB_ID_PFR0         ARM_V7M_SCB_ID_PFR0
#define ARM_V7M_CM4_SCB_ID_PFR1         ARM_V7M_SCB_ID_PFR1
#define ARM_V7M_CM4_SCB_ID_DFR0         ARM_V7M_SCB_ID_DFR0
#define ARM_V7M_CM4_SCB_ID_AFR0         ARM_V7M_SCB_ID_AFR0
#define ARM_V7M_CM4_SCB_ID_MMFR0        ARM_V7M_SCB_ID_MMFR0
#define ARM_V7M_CM4_SCB_ID_MMFR1        ARM_V7M_SCB_ID_MMFR1
#define ARM_V7M_CM4_SCB_ID_MMFR2        ARM_V7M_SCB_ID_MMFR2
#define ARM_V7M_CM4_SCB_ID_MMFR3        ARM_V7M_SCB_ID_MMFR3
#define ARM_V7M_CM4_SCB_ID_ISAR0        ARM_V7M_SCB_ID_ISAR0
#define ARM_V7M_CM4_SCB_ID_ISAR1        ARM_V7M_SCB_ID_ISAR1
#define ARM_V7M_CM4_SCB_ID_ISAR2        ARM_V7M_SCB_ID_ISAR2
#define ARM_V7M_CM4_SCB_ID_ISAR3        ARM_V7M_SCB_ID_ISAR3
#define ARM_V7M_CM4_SCB_ID_ISAR4        ARM_V7M_SCB_ID_ISAR4
#define ARM_V7M_CM4_SCB_ID_ISAR5        ARM_V7M_SCB_ID_ISAR5

/* -----------------------------------------------------------------------------
 * 4.3 SysTick 寄存器 (引用)
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM4_SYST_BASE           ARM_V7M_SYST_BASE
#define ARM_V7M_CM4_SYST_CSR            ARM_V7M_SYST_CSR
#define ARM_V7M_CM4_SYST_RVR            ARM_V7M_SYST_RVR
#define ARM_V7M_CM4_SYST_CVR            ARM_V7M_SYST_CVR
#define ARM_V7M_CM4_SYST_CALIB          ARM_V7M_SYST_CALIB

/* -----------------------------------------------------------------------------
 * 4.4 NVIC 寄存器 (引用)
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM4_NVIC_BASE           ARM_V7M_NVIC_BASE
#define ARM_V7M_CM4_NVIC_ISER(n)       ARM_V7M_NVIC_ISER(n)
#define ARM_V7M_CM4_NVIC_ICER(n)       ARM_V7M_NVIC_ICER(n)
#define ARM_V7M_CM4_NVIC_ISPR(n)       ARM_V7M_NVIC_ISPR(n)
#define ARM_V7M_CM4_NVIC_ICPR(n)       ARM_V7M_NVIC_ICPR(n)
#define ARM_V7M_CM4_NVIC_IABR(n)       ARM_V7M_NVIC_IABR(n)
#define ARM_V7M_CM4_NVIC_IPR(n)        ARM_V7M_NVIC_IPR(n)

/* -----------------------------------------------------------------------------
 * 4.5 MPU 寄存器 (引用)
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM4_MPU_BASE            ARM_V7M_MPU_BASE
#define ARM_V7M_CM4_MPU_TYPE           ARM_V7M_MPU_TYPE
#define ARM_V7M_CM4_MPU_CTRL           ARM_V7M_MPU_CTRL
#define ARM_V7M_CM4_MPU_RNR            ARM_V7M_MPU_RNR
#define ARM_V7M_CM4_MPU_RBAR           ARM_V7M_MPU_RBAR
#define ARM_V7M_CM4_MPU_RASR           ARM_V7M_MPU_RASR
#define ARM_V7M_CM4_MPU_RBAR_A1        ARM_V7M_MPU_RBAR_A1
#define ARM_V7M_CM4_MPU_RASR_A1        ARM_V7M_MPU_RASR_A1
#define ARM_V7M_CM4_MPU_RBAR_A2        ARM_V7M_MPU_RBAR_A2
#define ARM_V7M_CM4_MPU_RASR_A2        ARM_V7M_MPU_RASR_A2
#define ARM_V7M_CM4_MPU_RBAR_A3        ARM_V7M_MPU_RBAR_A3
#define ARM_V7M_CM4_MPU_RASR_A3        ARM_V7M_MPU_RASR_A3

/* -----------------------------------------------------------------------------
 * 4.6 STIR 寄存器 (引用)
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM4_STIR_BASE           ARM_V7M_STIR_BASE
#define ARM_V7M_CM4_STIR                ARM_V7M_STIR

/* ==============================================================================
 * 五、Cortex-M4 可选调试组件基地址
 * 参考：8.1 Debug configuration on page 8-73 (100166_0001_04_en)
 *       Table 8-2 Cortex-M4 ROM table components (100166_0001_04_en)
 *       Table 8-4 Debug registers (100166_0001_04_en)
 * 注意：这些组件是可选的，根据具体实现可能不存在
 *       如果未实现则 ROM 表中对应条目读取为 0
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 5.1 数据观察点和跟踪单元 (DWT - Data Watchpoint and Trace Unit)
 * 参考：9.2 DWT Programmers' model on page 9-85 (100166_0001_04_en)
 *       Table 9-1 DWT register summary (100166_0001_04_en)
 *       Table 8-2 Cortex-M4 ROM table components (100166_0001_04_en)
 * 地址：0xE0001000
 * 注意：此组件是可选的，如果未实现则 ROM 表中对应条目读取为 0xFFF02002
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM4_DWT_BASE            ARM_V7M_DWT_BASE
#define ARM_V7M_CM4_DWT_CTRL            ARM_V7M_DWT_CTRL
#define ARM_V7M_CM4_DWT_CYCCNT          ARM_V7M_DWT_CYCCNT
#define ARM_V7M_CM4_DWT_CPICNT          ARM_V7M_DWT_CPICNT
#define ARM_V7M_CM4_DWT_EXCCNT          ARM_V7M_DWT_EXCCNT
#define ARM_V7M_CM4_DWT_SLEEPCNT        ARM_V7M_DWT_SLEEPCNT
#define ARM_V7M_CM4_DWT_LSUCNT          ARM_V7M_DWT_LSUCNT
#define ARM_V7M_CM4_DWT_FOLDCNT         ARM_V7M_DWT_FOLDCNT
#define ARM_V7M_CM4_DWT_PCSR            ARM_V7M_DWT_PCSR
#define ARM_V7M_CM4_DWT_COMP(n)        ARM_V7M_DWT_COMP(n)
#define ARM_V7M_CM4_DWT_MASK(n)        ARM_V7M_DWT_MASK(n)
#define ARM_V7M_CM4_DWT_FUNCTION(n)    ARM_V7M_DWT_FUNCTION(n)
#define ARM_V7M_CM4_DWT_LAR             ARM_V7M_DWT_LAR
#define ARM_V7M_CM4_DWT_LSR             ARM_V7M_DWT_LSR

/* -----------------------------------------------------------------------------
 * 5.2 指令跟踪宏单元 (ITM - Instrumentation Trace Macrocell)
 * 参考：10.2 ITM programmers model on page 10-89 (100166_0001_04_en)
 *       Table 10-1 ITM register summary (100166_0001_04_en)
 *       Table 8-2 Cortex-M4 ROM table components (100166_0001_04_en)
 * 地址：0xE0000000
 * 注意：此组件是可选的，如果未实现则 ROM 表中对应条目读取为 0xFFF01002
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM4_ITM_BASE            ARM_V7M_ITM_BASE
#define ARM_V7M_CM4_ITM_STIM(n)        ARM_V7M_ITM_STIM(n)
#define ARM_V7M_CM4_ITM_TER(n)         ARM_V7M_ITM_TER(n)
#define ARM_V7M_CM4_ITM_TPR             ARM_V7M_ITM_TPR
#define ARM_V7M_CM4_ITM_TCR             ARM_V7M_ITM_TCR
#define ARM_V7M_CM4_ITM_LAR             ARM_V7M_ITM_LAR
#define ARM_V7M_CM4_ITM_LSR             ARM_V7M_ITM_LSR

/* -----------------------------------------------------------------------------
 * 5.3 Flash Patch 和断点单元 (FPB - Flash Patch and Breakpoint Unit)
 * 参考：8.3 Flash Patch and Breakpoint Unit (FPB) on page 8-81 (100166_0001_04_en)
 *       Table 8-2 Cortex-M4 ROM table components (100166_0001_04_en)
 * 地址：0xE0002000
 * 注意：此组件是可选的，如果未实现则 ROM 表中对应条目读取为 0xFFF03002
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM4_FPB_BASE            ARM_V7M_FPB_BASE
#define ARM_V7M_CM4_FPB_CTRL           ARM_V7M_FPB_CTRL
#define ARM_V7M_CM4_FPB_REMAP          ARM_V7M_FPB_REMAP
#define ARM_V7M_CM4_FPB_COMP(n)       ARM_V7M_FPB_COMP(n)
#define ARM_V7M_CM4_FPB_LAR            ARM_V7M_FPB_LAR
#define ARM_V7M_CM4_FPB_LSR            ARM_V7M_FPB_LSR

/* -----------------------------------------------------------------------------
 * 5.4 跟踪端口接口单元 (TPIU - Trace Port Interface Unit)
 * 参考：11.3 TPIU programmers model on page 11-95 (100166_0001_04_en)
 *       Table 11-1 TPIU register summary (100166_0001_04_en)
 *       Table 8-2 Cortex-M4 ROM table components (100166_0001_04_en)
 * 地址：0xE0040000
 * 注意：此组件是可选的，如果未实现则 ROM 表中对应条目读取为 0xFFF41002
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM4_TPIU_BASE           ARM_V7M_TPIU_BASE
#define ARM_V7M_CM4_TPIU_SSPSR         ARM_V7M_TPIU_SSPSR
#define ARM_V7M_CM4_TPIU_CSPSR         ARM_V7M_TPIU_CSPSR
#define ARM_V7M_CM4_TPIU_ACPR          ARM_V7M_TPIU_ACPR
#define ARM_V7M_CM4_TPIU_SPPR          ARM_V7M_TPIU_SPPR
#define ARM_V7M_CM4_TPIU_TYPE          ARM_V7M_TPIU_TYPE
#define ARM_V7M_CM4_TPIU_LAR           ARM_V7M_TPIU_LAR
#define ARM_V7M_CM4_TPIU_LSR           ARM_V7M_TPIU_LSR

/* -----------------------------------------------------------------------------
 * 5.5 嵌入式跟踪宏单元 (ETM - Embedded Trace Macrocell)
 * 参考：Table 8-2 Cortex-M4 ROM table components (100166_0001_04_en)
 *       See the ETM-M4 Technical Reference Manual
 * 地址：0xE0041000
 * 与通用 v7m 的差异：
 *   - Cortex-M4 定义了 ETM 基地址 0xE0041000
 *   - 通用 arm_v7m_core.h 中未定义 ETM 基地址
 * 注意：此组件是可选的，如果未实现则 ROM 表中对应条目读取为 0xFFF42002
 *       详细的寄存器定义请参考 ETM-M4 Technical Reference Manual
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM4_ETM_BASE            0xE0041000UL

/* ==============================================================================
 * 六、Cortex-M4 ROM 表
 * 参考：Table 8-1 Cortex-M4 ROM table identification values (100166_0001_04_en)
 *       Table 8-2 Cortex-M4 ROM table components (100166_0001_04_en)
 *       8.1.3 ROM table identification and entries on page 8-74 (100166_0001_04_en)
 * 基地址：0xE00FF000
 * ==============================================================================
 */
#define ARM_V7M_CM4_ROM_TABLE_BASE      0xE00FF000UL

#ifdef __cplusplus
}
#endif

#endif /* __ARM_V7M_CM4_CORE_H__ */
