/********************************************************************************
 * @file        arm_v8m_cm33_macro.h
 * @brief       ARM Cortex-M33 Processor Register Bit-field Macros
 * @details     基于 Arm® Cortex™-M33 Devices Generic User Guide (ARM DUI 100235)
 *              和 Arm® Cortex™-M33 Processor Technical Reference Manual (ARM DDI 100230)
 *              和 Arm® v8-M Architecture Reference Manual (ARM DDI 0553)
 *              文档路径：
 *              - d:\BaiduSyncdisk\来自：本地电脑\sync\code\Feather\FeatherArch\docs\arm\Arm® Cortex™-M33 Devices Generic User Guide.txt
 *              - d:\BaiduSyncdisk\来自：本地电脑\sync\code\Feather\FeatherArch\docs\arm\Arm® Cortex™-M33 Processor Technical Reference Manual.txt
 *              - d:\BaiduSyncdisk\来自：本地电脑\sync\code\Feather\FeatherArch\docs\arm\Arm® v8-M Architecture Reference Manual.txt
 * @author      FeatherCore
 * @version     1.0.0
 * @date        2026-03-31
 * @note        本文件仅包含 Cortex-M33 特定寄存器的位域宏定义
 *              代码风格严格对齐 arm_v7m_cm7_macro.h
 *
 * 寄存器位域覆盖清单：
 * - ACTLR (Auxiliary Control Register)
 *   参考：Table 3-4 ACTLR bit assignments (DDI 100230)
 * - CPUID (CPUID Base Register)
 *   参考：Table 3-5 CPUID bit assignments (DDI 100230)
 * - ID_AFR0 (Auxiliary Feature Register 0)
 *   参考：Table 3-6 ID_AFR0 bit assignments (DDI 100230)
 * - CCR (Configuration and Control Register)
 *   参考：Table 4-13 CCR bit assignments without Security Extension (DUI 100235)
 *        Table 4-14 CCR bit assignments with Security Extension (DUI 100235)
 *
 * 与通用 arm_v8m_macro.h 的主要差异：
 * 1. ACTLR 寄存器位域：
 *    - 通用 arm_v8m_macro.h 中 ACTLR 为 IMPLEMENTATION DEFINED，未定义具体位域
 *    - Cortex-M33 定义了完整的位域，包括 EXTEXCLALL, SBIST, DISITMATBFLUSH,
 *      FPEXCODIS, DISOOFP, DISFOLD, DISMCYCINT
 * 2. CPUID 寄存器：
 *    - 位域定义与通用 arm_v8m_macro.h 中的 CPUID 位域相同
 *    - Cortex-M33 定义了具体的 PARTNO=0xD21 和多个 REVISION 的值定义
 *    - 复位值：0x411FD210 (r1p0), 0x410FD211 (r0p1), 0x410FD212 (r0p2),
 *             0x410FD213 (r0p3), 0x410FD214 (r0p4)
 * 3. ID_AFR0 寄存器：
 *    - 通用 arm_v8m_macro.h 中 ID_AFR0 为 IMPLEMENTATION DEFINED
 *    - Cortex-M33 定义了 CDECP 和 CDERTLID 位域，用于 CDE (Custom Datapath Extension) 支持
 * 4. CCR 寄存器：
 *    - Cortex-M33 定义了 STKOFHFNMIGN 位域，用于栈溢出故障控制
 *    - Cortex-M33 定义了 BP, IC, DC 位 (bits[18:16])，但这些位为 RAZ/WI
 *    - UNALIGN_TRP 固定为 1
 *
 * 通用寄存器位域（引用 arm_v8m_macro.h）：
 *   - 所有其他 Armv8-M 寄存器位域定义请参考 arm_v8m_macro.h
 ********************************************************************************/

#ifndef __ARM_V8M_CM33_MACRO_H__
#define __ARM_V8M_CM33_MACRO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* ==============================================================================
 * 一、Cortex-M33 特定寄存器位域 (Cortex-M33 Specific Register Bit-fields)
 * 参考：Table 3-2 System control registers (DDI 100230)
 *       Table 4-13 CCR bit assignments without Security Extension (DUI 100235)
 *       Table 4-14 CCR bit assignments with Security Extension (DUI 100235)
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 1.1 ACTLR 寄存器位域 (ARM_V8M_CM33_SCS_ACTLR)
 * 参考：Table 3-4 ACTLR bit assignments (DDI 100230)
 *       3.4 Auxiliary Control Register on page 39 (DDI 100230)
 * 地址：0xE000E008
 * 复位值：0x00000000
 * 与通用 v8m 的差异：
 *   - 通用 arm_v8m_macro.h 中 ACTLR 为 IMPLEMENTATION DEFINED，未定义具体位域
 *   - Cortex-M33 定义了完整的位域，包括 EXTEXCLALL, SBIST, DISITMATBFLUSH,
 *     FPEXCODIS, DISOOFP, DISFOLD, DISMCYCINT
 *   - 该寄存器在安全状态和非安全状态之间有银行化，非安全别名位于 0xE002E008
 * -----------------------------------------------------------------------------
 */
/* DISMCYCINT - Disable multi-cycle interrupt, bit[0]
   0=正常操作;
   1=禁用多周期指令的中断。这会增加处理器的中断延迟，因为加载/存储和乘法/除法操作
   会在中断堆叠之前完成。 */
#define ARM_V8M_CM33_ACTLR_DISMCYCINT_Pos    0U
#define ARM_V8M_CM33_ACTLR_DISMCYCINT_Msk    (1UL << ARM_V8M_CM33_ACTLR_DISMCYCINT_Pos)
/* Reserved, bit[1] */
#define ARM_V8M_CM33_ACTLR_RES1_Pos          1U
#define ARM_V8M_CM33_ACTLR_RES1_Msk          (1UL << ARM_V8M_CM33_ACTLR_RES1_Pos)
/* DISFOLD - Disable dual-issue, bit[2]
   0=正常操作;
   1=禁用双发射功能。
   注意：设置此位会降低性能。 */
#define ARM_V8M_CM33_ACTLR_DISFOLD_Pos       2U
#define ARM_V8M_CM33_ACTLR_DISFOLD_Msk       (1UL << ARM_V8M_CM33_ACTLR_DISFOLD_Pos)
/* Reserved, bits[8:3] */
#define ARM_V8M_CM33_ACTLR_RES8_3_Pos        3U
#define ARM_V8M_CM33_ACTLR_RES8_3_Msk        (0x3FUL << ARM_V8M_CM33_ACTLR_RES8_3_Pos)
/* DISOOFP - Disable out-of-order floating-point, bit[9]
   0=正常操作;
   1=禁用浮点指令相对于非浮点指令乱序完成。 */
#define ARM_V8M_CM33_ACTLR_DISOOFP_Pos       9U
#define ARM_V8M_CM33_ACTLR_DISOOFP_Msk       (1UL << ARM_V8M_CM33_ACTLR_DISOOFP_Pos)
/* FPEXCODIS - Disable FPU exception outputs, bit[10]
   0=正常操作;
   1=禁用 FPU 异常输出。
   有关 FPU 异常输出的更多信息，请参见浮点单元章节。 */
#define ARM_V8M_CM33_ACTLR_FPEXCODIS_Pos     10U
#define ARM_V8M_CM33_ACTLR_FPEXCODIS_Msk     (1UL << ARM_V8M_CM33_ACTLR_FPEXCODIS_Pos)
/* Reserved, bit[11] */
#define ARM_V8M_CM33_ACTLR_RES11_Pos         11U
#define ARM_V8M_CM33_ACTLR_RES11_Msk         (1UL << ARM_V8M_CM33_ACTLR_RES11_Pos)
/* DISITMATBFLUSH - Disable ITM and DWT ATB flush, bit[12]
   0=正常操作;
   1=禁用 ITM/DWT ATB 刷新。
   禁用时，AFVALID 被忽略，AFREADY 保持高电平。 */
#define ARM_V8M_CM33_ACTLR_DISITMATBFLUSH_Pos 12U
#define ARM_V8M_CM33_ACTLR_DISITMATBFLUSH_Msk (1UL << ARM_V8M_CM33_ACTLR_DISITMATBFLUSH_Pos)
/* SBIST - Software Test Library enable, bit[13]
   0=复位和推荐值;
   1=由软件测试库 (STL) 内部启用的功能。当 STL 存在时，这会被恢复到原始值。
   有关 STL 的更多信息，请参见 Arm Cortex-M33 STL 用户指南。 */
#define ARM_V8M_CM33_ACTLR_SBIST_Pos         13U
#define ARM_V8M_CM33_ACTLR_SBIST_Msk         (1UL << ARM_V8M_CM33_ACTLR_SBIST_Pos)
/* Reserved, bits[28:14] */
#define ARM_V8M_CM33_ACTLR_RES28_14_Pos      14U
#define ARM_V8M_CM33_ACTLR_RES28_14_Msk      (0x7FFFUL << ARM_V8M_CM33_ACTLR_RES28_14_Pos)
/* EXTEXCLALL - External exclusive operations enable for all memory, bit[29]
   0=正常操作；与 LDREX、STREX、LDAEX 和 STLEX 指令关联的 C-AHB 或 S-AHB 接口上的内存请求
   仅在地址与可共享属性相关联时才断言 HEXCL 并响应 HEXOKAY。
   1=所有与 LDREX、STREX、LDAEX 和 STLEX 指令关联的 C-AHB 或 S-AHB 接口上的内存请求
   无论与地址关联的可共享属性如何，都会断言 HEXCL 并响应 HEXOKAY。
   设置 EXTEXCLALL 允许在没有 MPU 的配置中使用外部独占操作。这是因为默认内存映射
   不包含任何可共享的普通内存。 */
#define ARM_V8M_CM33_ACTLR_EXTEXCLALL_Pos    29U
#define ARM_V8M_CM33_ACTLR_EXTEXCLALL_Msk    (1UL << ARM_V8M_CM33_ACTLR_EXTEXCLALL_Pos)
/* Reserved for software testing purposes only, bits[31:30] */
#define ARM_V8M_CM33_ACTLR_RES31_30_Pos      30U
#define ARM_V8M_CM33_ACTLR_RES31_30_Msk      (0x3UL << ARM_V8M_CM33_ACTLR_RES31_30_Pos)

/* -----------------------------------------------------------------------------
 * 1.2 CPUID 寄存器位域 (ARM_V8M_CM33_SCB_CPUID)
 * 参考：Table 3-5 CPUID bit assignments (DDI 100230)
 *       3.5 CPUID Base Register on page 41 (DDI 100230)
 * 地址：0xE000ED00
 * 复位值：0x411FD210 (r1p0), 0x410FD211 (r0p1), 0x410FD212 (r0p2),
 *          0x410FD213 (r0p3), 0x410FD214 (r0p4)
 * 与通用 v8m 的差异：
 *   - 位域定义与通用 arm_v8m_macro.h 中的 CPUID 位域相同
 *   - Cortex-M33 定义了具体的 PARTNO=0xD21 和多个 REVISION 的值定义
 *   - 通用 arm_v8m_macro.h 中未定义具体的 PARTNO 和 REVISION 值
 * -----------------------------------------------------------------------------
 */
/* REVISION - 修订版本号 (p value), bits[3:0] */
#define ARM_V8M_CM33_CPUID_REVISION_Pos      0U
#define ARM_V8M_CM33_CPUID_REVISION_Msk      (0xFUL << ARM_V8M_CM33_CPUID_REVISION_Pos)
/* PARTNO - 部件编号, bits[15:4] */
#define ARM_V8M_CM33_CPUID_PARTNO_Pos        4U
#define ARM_V8M_CM33_CPUID_PARTNO_Msk        (0xFFFUL << ARM_V8M_CM33_CPUID_PARTNO_Pos)
/* ARCHITECTURE - 架构版本 (0xF 表示 ARMv8-M), bits[19:16] */
#define ARM_V8M_CM33_CPUID_ARCHITECTURE_Pos  16U
#define ARM_V8M_CM33_CPUID_ARCHITECTURE_Msk  (0xFUL << ARM_V8M_CM33_CPUID_ARCHITECTURE_Pos)
/* VARIANT - 变体版本号 (r value), bits[23:20] */
#define ARM_V8M_CM33_CPUID_VARIANT_Pos       20U
#define ARM_V8M_CM33_CPUID_VARIANT_Msk       (0xFUL << ARM_V8M_CM33_CPUID_VARIANT_Pos)
/* IMPLEMENTER - 实现者代码 (0x41 表示 ARM), bits[31:24] */
#define ARM_V8M_CM33_CPUID_IMPLEMENTER_Pos   24U
#define ARM_V8M_CM33_CPUID_IMPLEMENTER_Msk   (0xFFUL << ARM_V8M_CM33_CPUID_IMPLEMENTER_Pos)

/* ==============================================================================
 * 1.2.1 CPUID 值定义宏 (CPUID Value Definition Macros)
 * 非寄存器位域宏，用于定义 CPUID 寄存器的具体值
 * ==============================================================================
 */
/* CPUID 值定义 - Cortex-M33 特定值 */
#define ARM_V8M_CM33_CPUID_IMPLEMENTER_ARM  (0x41UL << ARM_V8M_CM33_CPUID_IMPLEMENTER_Pos)
#define ARM_V8M_CM33_CPUID_PARTNO_CM33      (0xD21UL << ARM_V8M_CM33_CPUID_PARTNO_Pos)
#define ARM_V8M_CM33_CPUID_ARCHITECTURE_VAL (0xFUL << ARM_V8M_CM33_CPUID_ARCHITECTURE_Pos)

/* CPUID 复位值定义 - Cortex-M33 不同版本 */
#define ARM_V8M_CM33_CPUID_RESET_R1P0       0x411FD210UL
#define ARM_V8M_CM33_CPUID_RESET_R0P1       0x410FD211UL
#define ARM_V8M_CM33_CPUID_RESET_R0P2       0x410FD212UL
#define ARM_V8M_CM33_CPUID_RESET_R0P3       0x410FD213UL
#define ARM_V8M_CM33_CPUID_RESET_R0P4       0x410FD214UL

/* -----------------------------------------------------------------------------
 * 1.3 ID_AFR0 寄存器位域 (ARM_V8M_CM33_SCB_ID_AFR0)
 * 参考：Table 3-6 ID_AFR0 bit assignments (DDI 100230)
 *       3.6 Auxiliary Feature Register 0 on page 42 (DDI 100230)
 * 地址：0xE000ED4C
 * 复位值：取决于 CDEMAPPEDONCP 和 CFGNOCDECP 参数
 * 与通用 v8m 的差异：
 *   - 通用 arm_v8m_macro.h 中 ID_AFR0 为 IMPLEMENTATION DEFINED
 *   - Cortex-M33 定义了 CDECP 和 CDERTLID 位域
 *   - CDECP[15:8]: 指示每个协处理器是否被 CDE 模块使用
 *   - CDERTLID[7:0]: 用于读取 CDERTLID 参数值，用于多 Cortex-M33 系统中的 CDE 定制
 *   - 非安全别名位于 0xE002ED4C，在非安全状态下为 RAZ/WI
 *   - 该寄存器不在安全状态之间银行化
 * -----------------------------------------------------------------------------
 */
/* CDERTLID - CDE RTL ID, bits[7:0]
   软件可以使用此字段读取 CDERTLID 参数的值。此参数管理可能需要在
   具有多个 Cortex-M33 处理器的系统中进行的 CDE 定制。 */
#define ARM_V8M_CM33_ID_AFR0_CDERTLID_Pos    0U
#define ARM_V8M_CM33_ID_AFR0_CDERTLID_Msk    (0xFFUL << ARM_V8M_CM33_ID_AFR0_CDERTLID_Pos)
/* CDECP - CDE Coprocessor, bits[15:8]
   指示每个协处理器是被 CDE 模块使用还是被协处理器接口使用：
   0=协处理器被协处理器接口使用
   1=协处理器被 CDE 模块使用 */
#define ARM_V8M_CM33_ID_AFR0_CDECP_Pos       8U
#define ARM_V8M_CM33_ID_AFR0_CDECP_Msk       (0xFFUL << ARM_V8M_CM33_ID_AFR0_CDECP_Pos)
/* Reserved, bits[31:16] - RES0 */
#define ARM_V8M_CM33_ID_AFR0_RES31_16_Pos    16U
#define ARM_V8M_CM33_ID_AFR0_RES31_16_Msk    (0xFFFFUL << ARM_V8M_CM33_ID_AFR0_RES31_16_Pos)

/* -----------------------------------------------------------------------------
 * 1.4 CCR 寄存器位域 (ARM_V8M_CM33_SCB_CCR)
 * 参考：Table 4-13 CCR bit assignments without Security Extension (DUI 100235)
 *       Table 4-14 CCR bit assignments with Security Extension (DUI 100235)
 *       3.3 Configuration and Control Register on page 38 (DDI 100230)
 * 地址：0xE000ED14
 * 复位值：0x00000201
 * 与通用 v8m 的差异：
 *   - Cortex-M33 定义了 STKOFHFNMIGN 位域 (bit[10])
 *   - Cortex-M33 定义了 BP, IC, DC 位 (bits[18:16])，但这些位为 RAZ/WI
 *   - UNALIGN_TRP 固定为 1
 *   - 该寄存器在安全状态和非安全状态之间有银行化
 * -----------------------------------------------------------------------------
 */
/* Reserved, bit[0] - RES1 */
#define ARM_V8M_CM33_CCR_RES0_Pos            0U
#define ARM_V8M_CM33_CCR_RES0_Msk            (1UL << ARM_V8M_CM33_CCR_RES0_Pos)
/* USERSETMPEND - User set main pending, bit[1]
   确定是否允许非特权访问从 STIR 挂起中断。
   0=对 STIR 的非特权访问会产生故障。
   1=允许对 STIR 的非特权访问。 */
#define ARM_V8M_CM33_CCR_USERSETMPEND_Pos    1U
#define ARM_V8M_CM33_CCR_USERSETMPEND_Msk    (1UL << ARM_V8M_CM33_CCR_USERSETMPEND_Pos)
/* Reserved, bit[2] - RES0 */
#define ARM_V8M_CM33_CCR_RES2_Pos             2U
#define ARM_V8M_CM33_CCR_RES2_Msk             (1UL << ARM_V8M_CM33_CCR_RES2_Pos)
/* UNALIGN_TRP - Unaligned access trap, bit[3]
   控制未对齐的字或半字访问的捕获。
   0=禁用未对齐捕获。
   1=启用未对齐捕获。
   注意：Cortex-M33 中此位固定为 1。 */
#define ARM_V8M_CM33_CCR_UNALIGN_TRP_Pos     3U
#define ARM_V8M_CM33_CCR_UNALIGN_TRP_Msk     (1UL << ARM_V8M_CM33_CCR_UNALIGN_TRP_Pos)
/* DIV_0_TRP - Divide by zero trap, bit[4]
   控制尝试执行整数除以零时生成 DIVBYZERO UsageFault。
   0=DIVBYZERO UsageFault 生成禁用。
   1=DIVBYZERO UsageFault 生成启用。
   此位在安全状态之间银行化。 */
#define ARM_V8M_CM33_CCR_DIV_0_TRP_Pos       4U
#define ARM_V8M_CM33_CCR_DIV_0_TRP_Msk       (1UL << ARM_V8M_CM33_CCR_DIV_0_TRP_Pos)
/* Reserved, bits[7:5] - RES0 */
#define ARM_V8M_CM33_CCR_RES7_5_Pos          5U
#define ARM_V8M_CM33_CCR_RES7_5_Msk          (0x7UL << ARM_V8M_CM33_CCR_RES7_5_Pos)
/* BFHFNMIGN - Bus fault hard fault ignore, bit[8]
   确定精确总线 faults 对在请求优先级小于 0 时运行的处理程序的影响。
   0=精确总线 faults 不会被忽略。
   1=在请求优先级小于 0 时，精确总线 faults 会被忽略。
   此位不在安全状态之间银行化。 */
#define ARM_V8M_CM33_CCR_BFHFNMIGN_Pos       8U
#define ARM_V8M_CM33_CCR_BFHFNMIGN_Msk       (1UL << ARM_V8M_CM33_CCR_BFHFNMIGN_Pos)
/* Reserved, bit[9] - RES1 */
#define ARM_V8M_CM33_CCR_RES9_Pos            9U
#define ARM_V8M_CM33_CCR_RES9_Msk            (1UL << ARM_V8M_CM33_CCR_RES9_Pos)
/* STKOFHFNMIGN - Stack overflow hard fault ignore, bit[10]
   控制在请求优先级小于 0 时执行时栈限制违规的影响。
   0=栈限制 faults 不会被忽略。
   1=在请求优先级小于 0 时，栈限制 faults 被忽略。
   此位在安全状态之间银行化。 */
#define ARM_V8M_CM33_CCR_STKOFHFNMIGN_Pos    10U
#define ARM_V8M_CM33_CCR_STKOFHFNMIGN_Msk    (1UL << ARM_V8M_CM33_CCR_STKOFHFNMIGN_Pos)
/* Reserved, bits[15:11] - RES0 */
#define ARM_V8M_CM33_CCR_RES15_11_Pos        11U
#define ARM_V8M_CM33_CCR_RES15_11_Msk        (0x1FUL << ARM_V8M_CM33_CCR_RES15_11_Pos)
/* DC - Data cache, bit[16]
   读为零，写为零。 */
#define ARM_V8M_CM33_CCR_DC_Pos              16U
#define ARM_V8M_CM33_CCR_DC_Msk              (1UL << ARM_V8M_CM33_CCR_DC_Pos)
/* IC - Instruction cache, bit[17]
   读为零，写为零。 */
#define ARM_V8M_CM33_CCR_IC_Pos              17U
#define ARM_V8M_CM33_CCR_IC_Msk              (1UL << ARM_V8M_CM33_CCR_IC_Pos)
/* BP - Branch predictor, bit[18]
   读为零，写为零。 */
#define ARM_V8M_CM33_CCR_BP_Pos              18U
#define ARM_V8M_CM33_CCR_BP_Msk              (1UL << ARM_V8M_CM33_CCR_BP_Pos)
/* Reserved, bits[31:19] - RES0 */
#define ARM_V8M_CM33_CCR_RES31_19_Pos        19U
#define ARM_V8M_CM33_CCR_RES31_19_Msk        (0x1FFFUL << ARM_V8M_CM33_CCR_RES31_19_Pos)

/* ==============================================================================
 * CCR 复位值定义
 * ==============================================================================
 */
#define ARM_V8M_CM33_CCR_RESET_VALUE        0x00000201UL

#ifdef __cplusplus
}
#endif

#endif /* __ARM_V8M_CM33_MACRO_H__ */