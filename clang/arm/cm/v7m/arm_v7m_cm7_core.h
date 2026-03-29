/********************************************************************************
 * @file        arm_v7m_cm7_core.h
 * @brief       ARM Cortex-M7 Processor Register Definitions
 * @details     基于 Arm® Cortex™-M7 Devices Generic User Guide (ARM DUI 0646C)
 *              和 Arm® Cortex™-M7 Processor Technical Reference Manual (ARM DDI 0489F)
 *              文档路径：
 *              - g:\develop\FeatherCore\FeatherArch\docs\arm\Arm® Cortex™-M7 Devices Generic User Guide.txt
 *              - g:\develop\FeatherCore\FeatherArch\docs\arm\Arm® Cortex™-M7 Processor Technical Reference Manual.txt
 * @author      FeatherCore
 * @version     1.0.0
 * @date        2026-03-29
 * @note        本文件仅包含寄存器定义和描述，位域定义在单独的头文件中
 *              通用寄存器引用自 arm_v7m_core.h
 *
 * 寄存器覆盖清单：
 * - Cortex-M7 特定 SCS 寄存器 (偏移 0xE000E008)
 *   - ACTLR (Auxiliary Control Register) - 0xE000E008
 *     参考：3.3.1 Auxiliary Control Register on page 3-6 (DDI 0489F)
 *           Table 3-1 System control registers (DDI 0489F)
 * - Cortex-M7 特定 SCB 寄存器 (偏移 0xE000ED00)
 *   - CPUID (CPUID Base Register) - 0xE000ED00, Reset 0x411FC272 (r1p2)
 *     参考：3.3.2 CPUID Base Register on page 3-8 (DDI 0489F)
 *           Table 3-1 System control registers (DDI 0489F)
 * - Cortex-M7 特定 TCM 控制寄存器 (偏移 0xE000EF90)
 *   - ITCMCR (Instruction TCM Control Register) - 0xE000EF90
 *   - DTCMCR (Data TCM Control Register) - 0xE000EF94
 *     参考：3.3.6 Instruction and Data Tightly-Coupled Memory Control Registers on page 3-13 (DDI 0489F)
 * - Cortex-M7 特定 AHB 外设控制寄存器 (偏移 0xE000EF98)
 *   - AHBPCR (AHBP Control Register) - 0xE000EF98
 *     参考：3.3.7 AHBP Control Register on page 3-14 (DDI 0489F)
 * - Cortex-M7 特定缓存控制寄存器 (偏移 0xE000EF9C)
 *   - CACR (L1 Cache Control Register) - 0xE000EF9C
 *     参考：3.3.8 L1 Cache Control Register on page 3-15 (DDI 0489F)
 * - Cortex-M7 特定 AHB 从机控制寄存器 (偏移 0xE000EFA0)
 *   - AHBSCR (AHB Slave Control Register) - 0xE000EFA0
 *     参考：3.3.12 AHB Slave Control Register on page 3-20 (DDI 0489F)
 * - Cortex-M7 特定辅助总线故障状态寄存器 (偏移 0xE000EFA8)
 *   - ABFSR (Auxiliary Bus Fault Status Register) - 0xE000EFA8
 *     参考：3.3.9 Auxiliary Bus Fault Status Register on page 3-16 (DDI 0489F)
 * - Cortex-M7 特定指令和数据错误银行寄存器 (偏移 0xE000EFB0)
 *   - IEBR0 (Instruction Error bank Register 0) - 0xE000EFB0
 *   - IEBR1 (Instruction Error bank Register 1) - 0xE000EFB4
 *   - DEBR0 (Data Error bank Register 0) - 0xE000EFB8
 *   - DEBR1 (Data Error bank Register 1) - 0xE000EFBC
 *     参考：3.3.10 Instruction Error bank Register 0-1 on page 3-17 (DDI 0489F)
 *           3.3.11 Data Error bank Register 0-1 on page 3-18 (DDI 0489F)
 * - Cortex-M7 缓存维护操作寄存器 (偏移 0xE000EF50)
 *   - ICIALLU, ICIMVAU, DCIMVAC, DCISW, DCCMVAU, DCCMVAC, DCCSW, DCCIMVAC, DCCISW, BPIALL
 *     参考：Table 3-1 System control registers (DDI 0489F)
 * - Cortex-M7 可选调试组件寄存器
 *   - DWT: CTRL, CYCCNT, CPICNT, EXCCNT, SLEEPCNT, LSUCNT, FOLDCNT, PCSR,
 *          COMP(n), MASK(n), FUNCTION(n), LAR, LSR (基地址 0xE0001000)
 *   - ITM: STIM(n), TER(n), TPR, TCR, LAR, LSR (基地址 0xE0000000)
 *   - FPB: CTRL, REMAP, COMP(n), LAR, LSR (基地址 0xE0002000)
 *   - TPIU: SSPSR, CSPSR, ACPR, SPPR, TYPE, LAR, LSR (基地址 0xE0040000)
 *   - ETM: (基地址 0xE0041000) - 详见 ETM-M7 Technical Reference Manual
 *     参考：Table 8-2 Cortex-M7 ROM table components (DDI 0489F)
 * - Cortex-M7 ROM 表基地址
 *   - ROM_TABLE_BASE
 *     参考：Table 8-1 Cortex-M7 ROM table identification values (DDI 0489F)
 *
 * 与通用 arm_v7m_core.h 的主要差异：
 * 1. ACTLR 寄存器：Cortex-M7 定义了详细的位域，而通用 arm_v7m_core.h 中 ACTLR 为 IMPLEMENTATION DEFINED
 * 2. CPUID 寄存器：Cortex-M7 的复位值为 0x410FC270/0x410FC271/0x410FC272/0x411FC270/0x411FC272，其中 PARTNO=0xC27
 * 3. 新增 TCM 控制寄存器：ITCMCR、DTCMCR
 * 4. 新增 AHB 外设控制寄存器：AHBPCR
 * 5. 新增 L1 缓存控制寄存器：CACR
 * 6. 新增 AHB 从机控制寄存器：AHBSCR
 * 7. 新增辅助总线故障状态寄存器：ABFSR
 * 8. 新增指令和数据错误银行寄存器：IEBR0-1、DEBR0-1
 * 9. ETM 基地址：Cortex-M7 定义了 ETM 基地址 0xE0041000
 *
 * 通用寄存器 (引用 arm_v7m_core.h):
 *   - SCS: ICTR (0xE000E004) - 通用
 *   - SCB: ICSR, VTOR, AIRCR, SCR, CCR, SHPR1-3, SHCSR, CFSR, HFSR, DFSR,
 *          MMFSR, BFSR, UFSR, MMFAR, BFAR, AFSR, CPACR, ID_PFR0-1, ID_DFR0, ID_AFR0,
 *          ID_MMFR0-3, ID_ISAR0-5, CLIDR, CTR, CCSIDR, CSSELR (0xE000ED00 范围)
 *   - FPU: FPCCR, FPCAR, FPDSCR, MVFR0, MVFR1, MVFR2 (0xE000EF30 范围)
 *   - SysTick: SYST_CSR, SYST_RVR, SYST_CVR, SYST_CALIB (0xE000E010)
 *   - NVIC: ISER, ICER, ISPR, ICPR, IABR, IPR (0xE000E100)
 *   - MPU: MPU_TYPE, MPU_CTRL, MPU_RNR, MPU_RBAR, MPU_RASR 等 (0xE000ED90)
 *   - STIR, 调试寄存器等
 *   参考：arm_v7m_core.h 和 B3.2 System Control Space (SCS) on page B3-595
 ********************************************************************************/

#ifndef __ARM_V7M_CM7_CORE_H__
#define __ARM_V7M_CM7_CORE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "arm_v7m_core.h"

/* ==============================================================================
 * 一、Cortex-M7 特定 SCS 寄存器 (System Control Space)
 * 参考：Table 3-1 System control registers (DDI 0489F)
 *       3.3.1 Auxiliary Control Register on page 3-6 (DDI 0489F)
 * 基地址：0xE000E000
 * 注意：以下寄存器偏移与 arm_v7m_core.h 中定义相同，但描述为 Cortex-M7 特定
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 1.1 辅助控制寄存器 (ACTLR - Auxiliary Control Register)
 * 参考：3.3.1 Auxiliary Control Register on page 3-6 (DDI 0489F)
 *       Table 3-3 ACTLR bit assignments (DDI 0489F)
 *       Table 3-1 System control registers (DDI 0489F)
 * 地址：0xE000E008
 * 复位值：0x00000000
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_core.h 中 ACTLR 为 IMPLEMENTATION DEFINED，未定义具体位域
 *   - Cortex-M7 定义了详细的位域：DISFPUISSOPT, DISCRITAXIRUW, DISDYNADD,
 *     DISISSCH1, DISDI, DISCRITAXIRUR, DISBTACALLOC, DISBTACREAD,
 *     DISITMATBFLUSH, DISRAMODE, FPEXCODIS, DISFOLD
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_SCS_ACTLR           ARM_V7M_SCS_ACTLR

/* ==============================================================================
 * 二、Cortex-M7 特定 SCB 寄存器 (System Control Block)
 * 参考：Table 3-1 System control registers (DDI 0489F)
 *       3.3.2 CPUID Base Register on page 3-8 (DDI 0489F)
 * 基地址：0xE000ED00
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 2.1 CPUID 基寄存器 (CPUID - CPUID Base Register)
 * 参考：3.3.2 CPUID Base Register on page 3-8 (DDI 0489F)
 *       Table 3-4 CPUID bit assignments (DDI 0489F)
 *       Table 3-1 System control registers (DDI 0489F)
 * 地址：0xE000ED00
 * 复位值：0x410FC270 (r0p0), 0x410FC271 (r0p1), 0x410FC272 (r0p2), 0x411FC270 (r1p0), 0x411FC272 (r1p2)
 * 与通用 v7m 的差异：
 *   - Cortex-M7 的复位值取决于具体修订版本
 *   - 其中：
 *     - IMPLEMENTER = 0x41 (ARM)
 *     - VARIANT = 0x0 或 0x1
 *     - ARCHITECTURE = 0xF
 *     - PARTNO = 0xC27 (Cortex-M7)
 *     - REVISION = 0x0 或 0x1 或 0x2
 *   - 通用 arm_v7m_core.h 中 CPUID 位域定义相同，但复位值取决于具体处理器实现
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_SCB_CPUID           ARM_V7M_SCB_CPUID

/* ==============================================================================
 * 三、Cortex-M7 特定 TCM 控制寄存器
 * 参考：3.3.6 Instruction and Data Tightly-Coupled Memory Control Registers on page 3-13 (DDI 0489F)
 * 基地址：0xE000EF90
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_core.h 中无此寄存器定义
 *   - Cortex-M7 新增 TCM 控制寄存器用于控制指令和数据 TCM
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 3.1 指令 TCM 控制寄存器 (ITCMCR - Instruction TCM Control Register)
 * 参考：3.3.6 Instruction and Data Tightly-Coupled Memory Control Registers on page 3-13 (DDI 0489F)
 *       Table 3-1 System control registers (DDI 0489F)
 * 地址：0xE000EF90
 * 复位值：Unknown
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_core.h 中无此寄存器
 *   - Cortex-M7 新增此寄存器用于控制指令 TCM
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_SCS_ITCMCR          0x0000EF90UL

/* -----------------------------------------------------------------------------
 * 3.2 数据 TCM 控制寄存器 (DTCMCR - Data TCM Control Register)
 * 参考：3.3.6 Instruction and Data Tightly-Coupled Memory Control Registers on page 3-13 (DDI 0489F)
 *       Table 3-1 System control registers (DDI 0489F)
 * 地址：0xE000EF94
 * 复位值：Unknown
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_core.h 中无此寄存器
 *   - Cortex-M7 新增此寄存器用于控制数据 TCM
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_SCS_DTCMCR          0x0000EF94UL

/* ==============================================================================
 * 四、Cortex-M7 特定 AHB 外设控制寄存器
 * 参考：3.3.7 AHBP Control Register on page 3-14 (DDI 0489F)
 * 基地址：0xE000EF98
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_core.h 中无此寄存器定义
 *   - Cortex-M7 新增此寄存器用于控制 AHB 外设接口
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 4.1 AHB 外设控制寄存器 (AHBPCR - AHBP Control Register)
 * 参考：3.3.7 AHBP Control Register on page 3-14 (DDI 0489F)
 *       Table 3-1 System control registers (DDI 0489F)
 * 地址：0xE000EF98
 * 复位值：Unknown
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_core.h 中无此寄存器
 *   - Cortex-M7 新增此寄存器用于控制 AHB 外设接口
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_SCS_AHBPCR          0x0000EF98UL

/* ==============================================================================
 * 五、Cortex-M7 特定 L1 缓存控制寄存器
 * 参考：3.3.8 L1 Cache Control Register on page 3-15 (DDI 0489F)
 * 基地址：0xE000EF9C
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_core.h 中无此寄存器定义
 *   - Cortex-M7 新增此寄存器用于控制 L1 指令和数据缓存
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 5.1 L1 缓存控制寄存器 (CACR - L1 Cache Control Register)
 * 参考：3.3.8 L1 Cache Control Register on page 3-15 (DDI 0489F)
 *       Table 3-1 System control registers (DDI 0489F)
 * 地址：0xE000EF9C
 * 复位值：Unknown
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_core.h 中无此寄存器
 *   - Cortex-M7 新增此寄存器用于控制 L1 指令和数据缓存
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_SCS_CACR            0x0000EF9CUL

/* ==============================================================================
 * 六、Cortex-M7 特定 AHB 从机控制寄存器
 * 参考：3.3.12 AHB Slave Control Register on page 3-20 (DDI 0489F)
 * 基地址：0xE000EFA0
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_core.h 中无此寄存器定义
 *   - Cortex-M7 新增此寄存器用于控制 AHB 从机接口
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 6.1 AHB 从机控制寄存器 (AHBSCR - AHB Slave Control Register)
 * 参考：3.3.12 AHB Slave Control Register on page 3-20 (DDI 0489F)
 *       Table 3-1 System control registers (DDI 0489F)
 * 地址：0xE000EFA0
 * 复位值：Unknown
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_core.h 中无此寄存器
 *   - Cortex-M7 新增此寄存器用于控制 AHB 从机接口
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_SCS_AHBSCR          0x0000EFA0UL

/* ==============================================================================
 * 七、Cortex-M7 特定辅助总线故障状态寄存器
 * 参考：3.3.9 Auxiliary Bus Fault Status Register on page 3-16 (DDI 0489F)
 * 基地址：0xE000EFA8
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_core.h 中无此寄存器定义
 *   - Cortex-M7 新增此寄存器用于提供 AXI 总线故障的额外信息
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 7.1 辅助总线故障状态寄存器 (ABFSR - Auxiliary Bus Fault Status Register)
 * 参考：3.3.9 Auxiliary Bus Fault Status Register on page 3-16 (DDI 0489F)
 *       Table 3-1 System control registers (DDI 0489F)
 * 地址：0xE000EFA8
 * 复位值：Unknown
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_core.h 中无此寄存器
 *   - Cortex-M7 新增此寄存器用于提供 AXI 总线故障的额外信息
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_SCS_ABFSR           0x0000EFA8UL

/* ==============================================================================
 * 八、Cortex-M7 特定指令和数据错误银行寄存器
 * 参考：3.3.10 Instruction Error bank Register 0-1 on page 3-17 (DDI 0489F)
 *       3.3.11 Data Error bank Register 0-1 on page 3-18 (DDI 0489F)
 * 基地址：0xE000EFB0
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_core.h 中无此寄存器定义
 *   - Cortex-M7 新增此寄存器用于在 ECC 配置选项实现时存储缓存错误信息
 * 注意：这些寄存器仅在 ECC 可配置选项实现时可用
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 8.1 指令错误银行寄存器 0 (IEBR0 - Instruction Error bank Register 0)
 * 参考：3.3.10 Instruction Error bank Register 0-1 on page 3-17 (DDI 0489F)
 *       Table 3-13 IEBR0-1 bit assignments (DDI 0489F)
 *       Table 3-1 System control registers (DDI 0489F)
 * 地址：0xE000EFB0
 * 复位值：- (未定义)
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_core.h 中无此寄存器
 *   - Cortex-M7 新增此寄存器用于存储指令缓存错误信息
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_SCS_IEBR0           0x0000EFB0UL

/* -----------------------------------------------------------------------------
 * 8.2 指令错误银行寄存器 1 (IEBR1 - Instruction Error bank Register 1)
 * 参考：3.3.10 Instruction Error bank Register 0-1 on page 3-17 (DDI 0489F)
 *       Table 3-13 IEBR0-1 bit assignments (DDI 0489F)
 *       Table 3-1 System control registers (DDI 0489F)
 * 地址：0xE000EFB4
 * 复位值：- (未定义)
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_core.h 中无此寄存器
 *   - Cortex-M7 新增此寄存器用于存储指令缓存错误信息
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_SCS_IEBR1           0x0000EFB4UL

/* -----------------------------------------------------------------------------
 * 8.3 数据错误银行寄存器 0 (DEBR0 - Data Error bank Register 0)
 * 参考：3.3.11 Data Error bank Register 0-1 on page 3-18 (DDI 0489F)
 *       Table 3-14 DEBR0-1 bit assignments (DDI 0489F)
 *       Table 3-1 System control registers (DDI 0489F)
 * 地址：0xE000EFB8
 * 复位值：- (未定义)
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_core.h 中无此寄存器
 *   - Cortex-M7 新增此寄存器用于存储数据缓存错误信息
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_SCS_DEBR0           0x0000EFB8UL

/* -----------------------------------------------------------------------------
 * 8.4 数据错误银行寄存器 1 (DEBR1 - Data Error bank Register 1)
 * 参考：3.3.11 Data Error bank Register 0-1 on page 3-18 (DDI 0489F)
 *       Table 3-14 DEBR0-1 bit assignments (DDI 0489F)
 *       Table 3-1 System control registers (DDI 0489F)
 * 地址：0xE000EFBC
 * 复位值：- (未定义)
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_core.h 中无此寄存器
 *   - Cortex-M7 新增此寄存器用于存储数据缓存错误信息
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_SCS_DEBR1           0x0000EFBCUL

/* ==============================================================================
 * 九、Cortex-M7 缓存维护操作寄存器
 * 参考：Table 3-1 System control registers (DDI 0489F)
 * 与通用 v7m 的差异：
 *   - 与通用 arm_v7m_core.h 定义相同
 *   - BPIALL 在 Cortex-M7 中未实现，读取为 0，写入忽略
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 9.1 缓存维护操作寄存器 (引用)
 * ----------------------------------------------------------------------------- */
#define ARM_V7M_CM7_SCS_ICIALLU         ARM_V7M_SCS_ICIALLU
#define ARM_V7M_CM7_SCS_ICIMVAU         ARM_V7M_SCS_ICIMVAU
#define ARM_V7M_CM7_SCS_DCIMVAC         ARM_V7M_SCS_DCIMVAC
#define ARM_V7M_CM7_SCS_DCISW           ARM_V7M_SCS_DCISW
#define ARM_V7M_CM7_SCS_DCCMVAU         ARM_V7M_SCS_DCCMVAU
#define ARM_V7M_CM7_SCS_DCCMVAC         ARM_V7M_SCS_DCCMVAC
#define ARM_V7M_CM7_SCS_DCCSW           ARM_V7M_SCS_DCCSW
#define ARM_V7M_CM7_SCS_DCCIMVAC        ARM_V7M_SCS_DCCIMVAC
#define ARM_V7M_CM7_SCS_DCCISW          ARM_V7M_SCS_DCCISW

/* -----------------------------------------------------------------------------
 * 9.2 分支预测器失效全部寄存器 (BPIALL - Branch Predictor Invalidate All)
 * 参考：Table 3-1 System control registers (DDI 0489F)
 * 地址：0xE000EF78
 * 复位值：0x00000000
 * 与通用 v7m 的差异：
 *   - 在 Cortex-M7 中未实现，读取为 0，写入忽略
 *   - 通用 v7m 可能有实现
 * ----------------------------------------------------------------------------- */
#define ARM_V7M_CM7_SCS_BPIALL          ARM_V7M_SCS_BPIALL

/* ==============================================================================
 * 九、Cortex-M7 通用寄存器 (引用 arm_v7m_core.h)
 * 以下寄存器在 Cortex-M7 和其他 Armv7-M 处理器之间通用
 * 直接引用 arm_v7m_core.h 中定义的宏
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 9.1 SCS 通用寄存器 (引用)
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_SCS_BASE            ARM_V7M_SCS_BASE
#define ARM_V7M_CM7_SCS_ICTR            ARM_V7M_SCS_ICTR

/* -----------------------------------------------------------------------------
 * 9.2 SCB 通用寄存器 (引用)
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_SCB_BASE            ARM_V7M_SCB_BASE
#define ARM_V7M_CM7_SCB_ICSR            ARM_V7M_SCB_ICSR
#define ARM_V7M_CM7_SCB_VTOR            ARM_V7M_SCB_VTOR
#define ARM_V7M_CM7_SCB_AIRCR           ARM_V7M_SCB_AIRCR
#define ARM_V7M_CM7_SCB_SCR             ARM_V7M_SCB_SCR
#define ARM_V7M_CM7_SCB_CCR             ARM_V7M_SCB_CCR
#define ARM_V7M_CM7_SCB_SHPR1           ARM_V7M_SCB_SHPR1
#define ARM_V7M_CM7_SCB_SHPR2           ARM_V7M_SCB_SHPR2
#define ARM_V7M_CM7_SCB_SHPR3           ARM_V7M_SCB_SHPR3
#define ARM_V7M_CM7_SCB_SHCSR           ARM_V7M_SCB_SHCSR
#define ARM_V7M_CM7_SCB_CFSR            ARM_V7M_SCB_CFSR
#define ARM_V7M_CM7_SCB_HFSR            ARM_V7M_SCB_HFSR
#define ARM_V7M_CM7_SCB_DFSR            ARM_V7M_SCB_DFSR
#define ARM_V7M_CM7_SCB_MMFSR           ARM_V7M_SCB_MMFSR
#define ARM_V7M_CM7_SCB_BFSR            ARM_V7M_SCB_BFSR
#define ARM_V7M_CM7_SCB_UFSR            ARM_V7M_SCB_UFSR
#define ARM_V7M_CM7_SCB_MMFAR           ARM_V7M_SCB_MMFAR
#define ARM_V7M_CM7_SCB_BFAR            ARM_V7M_SCB_BFAR
#define ARM_V7M_CM7_SCB_AFSR            ARM_V7M_SCB_AFSR
#define ARM_V7M_CM7_SCB_CPACR           ARM_V7M_SCB_CPACR

/* SCB ID 寄存器 */
#define ARM_V7M_CM7_SCB_ID_PFR0         ARM_V7M_SCB_ID_PFR0
#define ARM_V7M_CM7_SCB_ID_PFR1         ARM_V7M_SCB_ID_PFR1
#define ARM_V7M_CM7_SCB_ID_DFR0         ARM_V7M_SCB_ID_DFR0
#define ARM_V7M_CM7_SCB_ID_AFR0         ARM_V7M_SCB_ID_AFR0
#define ARM_V7M_CM7_SCB_ID_MMFR0        ARM_V7M_SCB_ID_MMFR0
#define ARM_V7M_CM7_SCB_ID_MMFR1        ARM_V7M_SCB_ID_MMFR1
#define ARM_V7M_CM7_SCB_ID_MMFR2        ARM_V7M_SCB_ID_MMFR2
#define ARM_V7M_CM7_SCB_ID_MMFR3        ARM_V7M_SCB_ID_MMFR3
#define ARM_V7M_CM7_SCB_ID_ISAR0        ARM_V7M_SCB_ID_ISAR0
#define ARM_V7M_CM7_SCB_ID_ISAR1        ARM_V7M_SCB_ID_ISAR1
#define ARM_V7M_CM7_SCB_ID_ISAR2        ARM_V7M_SCB_ID_ISAR2
#define ARM_V7M_CM7_SCB_ID_ISAR3        ARM_V7M_SCB_ID_ISAR3
#define ARM_V7M_CM7_SCB_ID_ISAR4        ARM_V7M_SCB_ID_ISAR4
#define ARM_V7M_CM7_SCB_ID_ISAR5        ARM_V7M_SCB_ID_ISAR5
#define ARM_V7M_CM7_SCB_CLIDR           ARM_V7M_SCB_CLIDR
#define ARM_V7M_CM7_SCB_CTR             ARM_V7M_SCB_CTR
#define ARM_V7M_CM7_SCB_CCSIDR          ARM_V7M_SCB_CCSIDR
#define ARM_V7M_CM7_SCB_CSSELR          ARM_V7M_SCB_CSSELR

/* -----------------------------------------------------------------------------
 * 9.3 SysTick 寄存器 (引用)
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_SYST_BASE           ARM_V7M_SYST_BASE
#define ARM_V7M_CM7_SYST_CSR            ARM_V7M_SYST_CSR
#define ARM_V7M_CM7_SYST_RVR            ARM_V7M_SYST_RVR
#define ARM_V7M_CM7_SYST_CVR            ARM_V7M_SYST_CVR
#define ARM_V7M_CM7_SYST_CALIB          ARM_V7M_SYST_CALIB

/* -----------------------------------------------------------------------------
 * 9.4 NVIC 寄存器 (引用)
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_NVIC_BASE           ARM_V7M_NVIC_BASE
#define ARM_V7M_CM7_NVIC_ISER(n)       ARM_V7M_NVIC_ISER(n)
#define ARM_V7M_CM7_NVIC_ICER(n)       ARM_V7M_NVIC_ICER(n)
#define ARM_V7M_CM7_NVIC_ISPR(n)       ARM_V7M_NVIC_ISPR(n)
#define ARM_V7M_CM7_NVIC_ICPR(n)       ARM_V7M_NVIC_ICPR(n)
#define ARM_V7M_CM7_NVIC_IABR(n)       ARM_V7M_NVIC_IABR(n)
#define ARM_V7M_CM7_NVIC_IPR(n)        ARM_V7M_NVIC_IPR(n)

/* -----------------------------------------------------------------------------
 * 9.5 MPU 寄存器 (引用)
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_MPU_BASE            ARM_V7M_MPU_BASE
#define ARM_V7M_CM7_MPU_TYPE           ARM_V7M_MPU_TYPE
#define ARM_V7M_CM7_MPU_CTRL           ARM_V7M_MPU_CTRL
#define ARM_V7M_CM7_MPU_RNR            ARM_V7M_MPU_RNR
#define ARM_V7M_CM7_MPU_RBAR           ARM_V7M_MPU_RBAR
#define ARM_V7M_CM7_MPU_RASR           ARM_V7M_MPU_RASR
#define ARM_V7M_CM7_MPU_RBAR_A1        ARM_V7M_MPU_RBAR_A1
#define ARM_V7M_CM7_MPU_RASR_A1        ARM_V7M_MPU_RASR_A1
#define ARM_V7M_CM7_MPU_RBAR_A2        ARM_V7M_MPU_RBAR_A2
#define ARM_V7M_CM7_MPU_RASR_A2        ARM_V7M_MPU_RASR_A2
#define ARM_V7M_CM7_MPU_RBAR_A3        ARM_V7M_MPU_RBAR_A3
#define ARM_V7M_CM7_MPU_RASR_A3        ARM_V7M_MPU_RASR_A3

/* -----------------------------------------------------------------------------
 * 9.6 STIR 寄存器 (引用)
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_STIR_BASE           ARM_V7M_STIR_BASE
#define ARM_V7M_CM7_STIR                ARM_V7M_STIR

/* -----------------------------------------------------------------------------
 * 9.7 FPU 寄存器 (引用)
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_FPU_BASE            ARM_V7M_FPU_BASE
#define ARM_V7M_CM7_FPU_FPCCR          ARM_V7M_FPU_FPCCR
#define ARM_V7M_CM7_FPU_FPCAR          ARM_V7M_FPU_FPCAR
#define ARM_V7M_CM7_FPU_FPDSCR         ARM_V7M_FPU_FPDSCR
#define ARM_V7M_CM7_FPU_MVFR0          ARM_V7M_FPU_MVFR0
#define ARM_V7M_CM7_FPU_MVFR1          ARM_V7M_FPU_MVFR1
#define ARM_V7M_CM7_FPU_MVFR2          ARM_V7M_FPU_MVFR2

/* ==============================================================================
 * 十、Cortex-M7 可选调试组件基地址
 * 参考：Table 8-2 Cortex-M7 ROM table components (DDI 0489F)
 *       Table 8-4 Debug registers (DDI 0489F)
 * 注意：这些组件是可选的，根据具体实现可能不存在
 *       如果未实现则 ROM 表中对应条目读取为 0
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 10.1 数据观察点和跟踪单元 (DWT - Data Watchpoint and Trace Unit)
 * 参考：Table 8-2 Cortex-M7 ROM table components (DDI 0489F)
 * 地址：0xE0001000
 * 注意：此组件是可选的，如果未实现则 ROM 表中对应条目读取为 0xFFF02002
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_DWT_BASE            ARM_V7M_DWT_BASE
#define ARM_V7M_CM7_DWT_CTRL            ARM_V7M_DWT_CTRL
#define ARM_V7M_CM7_DWT_CYCCNT          ARM_V7M_DWT_CYCCNT
#define ARM_V7M_CM7_DWT_CPICNT          ARM_V7M_DWT_CPICNT
#define ARM_V7M_CM7_DWT_EXCCNT          ARM_V7M_DWT_EXCCNT
#define ARM_V7M_CM7_DWT_SLEEPCNT        ARM_V7M_DWT_SLEEPCNT
#define ARM_V7M_CM7_DWT_LSUCNT          ARM_V7M_DWT_LSUCNT
#define ARM_V7M_CM7_DWT_FOLDCNT         ARM_V7M_DWT_FOLDCNT
#define ARM_V7M_CM7_DWT_PCSR            ARM_V7M_DWT_PCSR
#define ARM_V7M_CM7_DWT_COMP(n)        ARM_V7M_DWT_COMP(n)
#define ARM_V7M_CM7_DWT_MASK(n)        ARM_V7M_DWT_MASK(n)
#define ARM_V7M_CM7_DWT_FUNCTION(n)    ARM_V7M_DWT_FUNCTION(n)
#define ARM_V7M_CM7_DWT_LAR             ARM_V7M_DWT_LAR
#define ARM_V7M_CM7_DWT_LSR             ARM_V7M_DWT_LSR

/* -----------------------------------------------------------------------------
 * 10.2 指令跟踪宏单元 (ITM - Instrumentation Trace Macrocell)
 * 参考：Table 8-2 Cortex-M7 ROM table components (DDI 0489F)
 * 地址：0xE0000000
 * 注意：此组件是可选的，如果未实现则 ROM 表中对应条目读取为 0xFFF01002
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_ITM_BASE            ARM_V7M_ITM_BASE
#define ARM_V7M_CM7_ITM_STIM(n)        ARM_V7M_ITM_STIM(n)
#define ARM_V7M_CM7_ITM_TER(n)         ARM_V7M_ITM_TER(n)
#define ARM_V7M_CM7_ITM_TPR             ARM_V7M_ITM_TPR
#define ARM_V7M_CM7_ITM_TCR             ARM_V7M_ITM_TCR
#define ARM_V7M_CM7_ITM_LAR             ARM_V7M_ITM_LAR
#define ARM_V7M_CM7_ITM_LSR             ARM_V7M_ITM_LSR

/* -----------------------------------------------------------------------------
 * 10.3 Flash Patch 和断点单元 (FPB - Flash Patch and Breakpoint Unit)
 * 参考：Table 8-2 Cortex-M7 ROM table components (DDI 0489F)
 * 地址：0xE0002000
 * 注意：此组件是可选的，如果未实现则 ROM 表中对应条目读取为 0xFFF03002
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_FPB_BASE            ARM_V7M_FPB_BASE
#define ARM_V7M_CM7_FPB_CTRL           ARM_V7M_FPB_CTRL
#define ARM_V7M_CM7_FPB_REMAP          ARM_V7M_FPB_REMAP
#define ARM_V7M_CM7_FPB_COMP(n)       ARM_V7M_FPB_COMP(n)
#define ARM_V7M_CM7_FPB_LAR            ARM_V7M_FPB_LAR
#define ARM_V7M_CM7_FPB_LSR            ARM_V7M_FPB_LSR

/* -----------------------------------------------------------------------------
 * 10.4 跟踪端口接口单元 (TPIU - Trace Port Interface Unit)
 * 参考：Table 8-2 Cortex-M7 ROM table components (DDI 0489F)
 * 地址：0xE0040000
 * 注意：此组件是可选的，如果未实现则 ROM 表中对应条目读取为 0xFFF41002
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_TPIU_BASE           ARM_V7M_TPIU_BASE
#define ARM_V7M_CM7_TPIU_SSPSR         ARM_V7M_TPIU_SSPSR
#define ARM_V7M_CM7_TPIU_CSPSR         ARM_V7M_TPIU_CSPSR
#define ARM_V7M_CM7_TPIU_ACPR          ARM_V7M_TPIU_ACPR
#define ARM_V7M_CM7_TPIU_SPPR          ARM_V7M_TPIU_SPPR
#define ARM_V7M_CM7_TPIU_TYPE          ARM_V7M_TPIU_TYPE
#define ARM_V7M_CM7_TPIU_LAR           ARM_V7M_TPIU_LAR
#define ARM_V7M_CM7_TPIU_LSR           ARM_V7M_TPIU_LSR

/* -----------------------------------------------------------------------------
 * 10.5 嵌入式跟踪宏单元 (ETM - Embedded Trace Macrocell)
 * 参考：Table 8-2 Cortex-M7 ROM table components (DDI 0489F)
 *       See the ETM-M7 Technical Reference Manual
 * 地址：0xE0041000
 * 与通用 v7m 的差异：
 *   - Cortex-M7 定义了 ETM 基地址 0xE0041000
 *   - 通用 arm_v7m_core.h 中未定义 ETM 基地址
 * 注意：此组件是可选的，如果未实现则 ROM 表中对应条目读取为 0xFFF42002
 *       详细的寄存器定义请参考 ETM-M7 Technical Reference Manual
 * -----------------------------------------------------------------------------
 */
#define ARM_V7M_CM7_ETM_BASE            0xE0041000UL

/* ==============================================================================
 * 十一、Cortex-M7 ROM 表
 * 参考：Table 8-1 Cortex-M7 ROM table identification values (DDI 0489F)
 *       Table 8-2 Cortex-M7 ROM table components (DDI 0489F)
 * 基地址：0xE00FF000
 * ==============================================================================
 */
#define ARM_V7M_CM7_ROM_TABLE_BASE      0xE00FF000UL

#ifdef __cplusplus
}
#endif

#endif /* __ARM_V7M_CM7_CORE_H__ */
