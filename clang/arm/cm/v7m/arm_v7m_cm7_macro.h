/********************************************************************************
 * @file        arm_v7m_cm7_macro.h
 * @brief       ARM Cortex-M7 Processor Register Bit-field Macros
 * @details     基于 Arm® Cortex™-M7 Devices Generic User Guide (ARM DUI 0646C)
 *              和 Arm® Cortex™-M7 Processor Technical Reference Manual (ARM DDI 0489F)
 *              文档路径：
 *              - g:\develop\FeatherCore\FeatherArch\docs\arm\Arm® Cortex™-M7 Devices Generic User Guide.txt
 *              - g:\develop\FeatherCore\FeatherArch\docs\arm\Arm® Cortex™-M7 Processor Technical Reference Manual.txt
 * @author      FeatherCore
 * @version     1.0.0
 * @date        2026-03-29
 * @note        本文件仅包含 Cortex-M7 特定寄存器的位域宏定义
 *              代码风格严格对齐 arm_v7m_macro.h
 *
 * 寄存器位域覆盖清单：
 * - ACTLR (Auxiliary Control Register)
 *   参考：Table 3-3 ACTLR bit assignments (DDI 0489F)
 * - CPUID (CPUID Base Register)
 *   参考：Table 3-4 CPUID register bit assignments (DDI 0489F)
 * - ITCMCR (Instruction TCM Control Register)
 *   参考：Table 3-5 ITCMCR bit assignments (DDI 0489F)
 * - DTCMCR (Data TCM Control Register)
 *   参考：Table 3-6 DTCMCR bit assignments (DDI 0489F)
 * - AHBPCR (AHB Peripheral Control Register)
 *   参考：Table 3-7 AHBPCR bit assignments (DDI 0489F)
 * - CACR (L1 Cache Control Register)
 *   参考：Table 3-8 CACR bit assignments (DDI 0489F)
 * - AHBSCR (AHB Slave Control Register)
 *   参考：Table 3-9 AHBSCR bit assignments (DDI 0489F)
 * - ABFSR (Auxiliary Bus Fault Status Register)
 *   参考：Table 3-10 ABFSR bit assignments (DDI 0489F)
 * - IEBR0-1 (Instruction Error bank Register 0-1)
 *   参考：Table 3-13 IEBR0-1 bit assignments (DDI 0489F)
 * - DEBR0-1 (Data Error bank Register 0-1)
 *   参考：Table 3-14 DEBR0-1 bit assignments (DDI 0489F)
 *
 * 与通用 arm_v7m_macro.h 的主要差异：
 * 1. ACTLR 寄存器位域：
 *    - 通用 arm_v7m_macro.h 中 ACTLR 为 IMPLEMENTATION DEFINED，未定义具体位域
 *    - Cortex-M7 定义了完整的位域，包括 DISFPUISSOPT, DISCRITAXIRUW, DISDYNADD, 
 *      DISISSCH1, DISDI, DISCRITAXIRUR, DISBTACALLOC, DISBTACREAD, DISITMATBFLUSH,
 *      DISRAMODE, FPEXCODIS, DISFOLD 等位
 * 2. CPUID 寄存器：
 *    - 位域定义与通用 arm_v7m_macro.h 中的 CPUID 位域相同
 *    - Cortex-M7 定义了具体的 PARTNO=0xC27 和多个 REVISION 的值定义
 *    - 复位值：0x410FC270 (r0p0), 0x410FC271 (r0p1), 0x410FC272 (r0p2),
 *             0x411FC270 (r1p0), 0x411FC272 (r1p2)
 * 3. 新增 TCM 控制寄存器：
 *    - ITCMCR (Instruction TCM Control Register)
 *    - DTCMCR (Data TCM Control Register)
 * 4. 新增 AHB 外设控制寄存器：
 *    - AHBPCR (AHB Peripheral Control Register)
 * 5. 新增 L1 缓存控制寄存器：
 *    - CACR (L1 Cache Control Register)
 * 6. 新增 AHB 从机控制寄存器：
 *    - AHBSCR (AHB Slave Control Register)
 * 7. 新增辅助总线故障状态寄存器：
 *    - ABFSR (Auxiliary Bus Fault Status Register)
 * 8. 新增指令和数据错误银行寄存器：
 *    - IEBR0-1 (Instruction Error bank Register 0-1)
 *    - DEBR0-1 (Data Error bank Register 0-1)
 *
 * 通用寄存器位域（引用 arm_v7m_macro.h）：
 *   - 所有其他 Armv7-M 寄存器位域定义请参考 arm_v7m_macro.h
 ********************************************************************************/

#ifndef __ARM_V7M_CM7_MACRO_H__
#define __ARM_V7M_CM7_MACRO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* ==============================================================================
 * 一、Cortex-M7 特定寄存器位域 (Cortex-M7 Specific Register Bit-fields)
 * 参考：Table 3-2 Cortex-M7 system control registers (DDI 0489F)
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 1.1 ACTLR 寄存器位域 (ARM_V7M_CM7_SCS_ACTLR)
 * 参考：Table 3-3 ACTLR bit assignments (DDI 0489F)
 *       3.3.1 Auxiliary Control Register on page 3-6 (DDI 0489F)
 * 地址：0xE000E008
 * 复位值：0x00000000
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_macro.h 中 ACTLR 为 IMPLEMENTATION DEFINED，未定义具体位域
 *   - Cortex-M7 定义了完整的位域，包括 DISFPUISSOPT, DISCRITAXIRUW, DISDYNADD, 
 *     DISISSCH1, DISDI, DISCRITAXIRUR, DISBTACALLOC, DISBTACREAD, DISITMATBFLUSH,
 *     DISRAMODE, FPEXCODIS, DISFOLD 等位
 * -----------------------------------------------------------------------------
 */
/* DISFPUISSOPT - Disable FPU issue optimization, bit[28] */
#define ARM_V7M_CM7_ACTLR_DISFPUISSOPT_Pos    28U
#define ARM_V7M_CM7_ACTLR_DISFPUISSOPT_Msk    (1UL << ARM_V7M_CM7_ACTLR_DISFPUISSOPT_Pos)
/* DISCRITAXIRUW - Disable critical AXI read-under-write, bit[27] */
#define ARM_V7M_CM7_ACTLR_DISCRITAXIRUW_Pos   27U
#define ARM_V7M_CM7_ACTLR_DISCRITAXIRUW_Msk   (1UL << ARM_V7M_CM7_ACTLR_DISCRITAXIRUW_Pos)
/* DISDYNADD - Disables dynamic allocation of ADD and SUB instructions, bit[26] */
#define ARM_V7M_CM7_ACTLR_DISDYNADD_Pos        26U
#define ARM_V7M_CM7_ACTLR_DISDYNADD_Msk        (1UL << ARM_V7M_CM7_ACTLR_DISDYNADD_Pos)
/* DISISSCH1 - Instruction issue channel 1 disable, bits[25:21] */
#define ARM_V7M_CM7_ACTLR_DISISSCH1_Pos        21U
#define ARM_V7M_CM7_ACTLR_DISISSCH1_Msk        (0x1FUL << ARM_V7M_CM7_ACTLR_DISISSCH1_Pos)
/* DISDI - Dual-issue disable, bits[20:16] */
#define ARM_V7M_CM7_ACTLR_DISDI_Pos            16U
#define ARM_V7M_CM7_ACTLR_DISDI_Msk            (0x1FUL << ARM_V7M_CM7_ACTLR_DISDI_Pos)
/* DISCRITAXIRUR - Disable critical AXI read-under-read, bit[15] */
#define ARM_V7M_CM7_ACTLR_DISCRITAXIRUR_Pos   15U
#define ARM_V7M_CM7_ACTLR_DISCRITAXIRUR_Msk   (1UL << ARM_V7M_CM7_ACTLR_DISCRITAXIRUR_Pos)
/* DISBTACALLOC - Disable BTAC allocation, bit[14] */
#define ARM_V7M_CM7_ACTLR_DISBTACALLOC_Pos     14U
#define ARM_V7M_CM7_ACTLR_DISBTACALLOC_Msk     (1UL << ARM_V7M_CM7_ACTLR_DISBTACALLOC_Pos)
/* DISBTACREAD - Disable BTAC read, bit[13] */
#define ARM_V7M_CM7_ACTLR_DISBTACREAD_Pos      13U
#define ARM_V7M_CM7_ACTLR_DISBTACREAD_Msk      (1UL << ARM_V7M_CM7_ACTLR_DISBTACREAD_Pos)
/* DISITMATBFLUSH - Disable ITM and DWT ATB flush, bit[12] */
#define ARM_V7M_CM7_ACTLR_DISITMATBFLUSH_Pos   12U
#define ARM_V7M_CM7_ACTLR_DISITMATBFLUSH_Msk   (1UL << ARM_V7M_CM7_ACTLR_DISITMATBFLUSH_Pos)
/* DISRAMODE - Disable dynamic read allocate mode, bit[11] */
#define ARM_V7M_CM7_ACTLR_DISRAMODE_Pos        11U
#define ARM_V7M_CM7_ACTLR_DISRAMODE_Msk        (1UL << ARM_V7M_CM7_ACTLR_DISRAMODE_Pos)
/* FPEXCODIS - Disable FPU exception outputs, bit[10] */
#define ARM_V7M_CM7_ACTLR_FPEXCODIS_Pos        10U
#define ARM_V7M_CM7_ACTLR_FPEXCODIS_Msk        (1UL << ARM_V7M_CM7_ACTLR_FPEXCODIS_Pos)
/* DISFOLD - Disable IT folding, bit[2] */
#define ARM_V7M_CM7_ACTLR_DISFOLD_Pos          2U
#define ARM_V7M_CM7_ACTLR_DISFOLD_Msk          (1UL << ARM_V7M_CM7_ACTLR_DISFOLD_Pos)

/* -----------------------------------------------------------------------------
 * 1.2 CPUID 寄存器位域 (ARM_V7M_CM7_SCB_CPUID)
 * 参考：Table 3-4 CPUID register bit assignments (DDI 0489F)
 *       3.3.2 CPUID Base Register on page 3-8 (DDI 0489F)
 * 地址：0xE000ED00
 * 复位值：0x410FC270 (r0p0), 0x410FC271 (r0p1), 0x410FC272 (r0p2),
 *          0x411FC270 (r1p0), 0x411FC272 (r1p2)
 * 与通用 v7m 的差异：
 *   - 位域定义与通用 arm_v7m_macro.h 中的 CPUID 位域相同
 *   - Cortex-M7 定义了具体的 PARTNO=0xC27 和多个 REVISION 的值定义
 *   - 通用 arm_v7m_macro.h 中未定义具体的 PARTNO 和 REVISION 值
 * -----------------------------------------------------------------------------
 */
/* REVISION - 修订版本号 (p value), bits[3:0] */
#define ARM_V7M_CM7_CPUID_REVISION_Pos      0U
#define ARM_V7M_CM7_CPUID_REVISION_Msk      (0xFUL << ARM_V7M_CM7_CPUID_REVISION_Pos)
/* PARTNO - 部件编号, bits[15:4] */
#define ARM_V7M_CM7_CPUID_PARTNO_Pos        4U
#define ARM_V7M_CM7_CPUID_PARTNO_Msk        (0xFFFUL << ARM_V7M_CM7_CPUID_PARTNO_Pos)
/* CONSTANT - 常量值 (0xF), bits[19:16] */
#define ARM_V7M_CM7_CPUID_CONSTANT_Pos      16U
#define ARM_V7M_CM7_CPUID_CONSTANT_Msk      (0xFUL << ARM_V7M_CM7_CPUID_CONSTANT_Pos)
/* VARIANT - 变体版本号 (r value), bits[23:20] */
#define ARM_V7M_CM7_CPUID_VARIANT_Pos       20U
#define ARM_V7M_CM7_CPUID_VARIANT_Msk       (0xFUL << ARM_V7M_CM7_CPUID_VARIANT_Pos)
/* IMPLEMENTER - 实现者代码 (0x41 表示 ARM), bits[31:24] */
#define ARM_V7M_CM7_CPUID_IMPLEMENTER_Pos   24U
#define ARM_V7M_CM7_CPUID_IMPLEMENTER_Msk   (0xFFUL << ARM_V7M_CM7_CPUID_IMPLEMENTER_Pos)

/* ==============================================================================
 * 1.2.1 CPUID 值定义宏 (CPUID Value Definition Macros)
 * 非寄存器位域宏，用于定义 CPUID 寄存器的具体值
 * ==============================================================================
 */
/* CPUID 值定义 - Cortex-M7 特定值 */
#define ARM_V7M_CM7_CPUID_IMPLEMENTER_ARM   (0x41UL << ARM_V7M_CM7_CPUID_IMPLEMENTER_Pos)
#define ARM_V7M_CM7_CPUID_PARTNO_CM7        (0xC27UL << ARM_V7M_CM7_CPUID_PARTNO_Pos)
#define ARM_V7M_CM7_CPUID_CONSTANT_VAL      (0xFUL << ARM_V7M_CM7_CPUID_CONSTANT_Pos)

/* CPUID 复位值定义 - Cortex-M7 不同版本 */
#define ARM_V7M_CM7_CPUID_RESET_R0P0        0x410FC270UL
#define ARM_V7M_CM7_CPUID_RESET_R0P1        0x410FC271UL
#define ARM_V7M_CM7_CPUID_RESET_R0P2        0x410FC272UL
#define ARM_V7M_CM7_CPUID_RESET_R1P0        0x411FC270UL
#define ARM_V7M_CM7_CPUID_RESET_R1P2        0x411FC272UL

/* -----------------------------------------------------------------------------
 * 1.3 ITCMCR 寄存器位域 (ARM_V7M_CM7_SCS_ITCMCR)
 * 参考：Table 3-9 ITCMCR bit assignments (DDI 0489F)
 *       3.3.6 Instruction and Data TCM Control Registers on page 3-13 (DDI 0489F)
 * 地址：0xE000EF90
 * 复位值：0x00000000
 * 与通用 v7m 的差异：
 *   - 此寄存器为 Cortex-M7 特有
 *   - 通用 arm_v7m_macro.h 中无此寄存器位域定义
 * -----------------------------------------------------------------------------
 */
/* EN - Enable, bit[0] */
#define ARM_V7M_CM7_ITCMCR_EN_Pos              0U
#define ARM_V7M_CM7_ITCMCR_EN_Msk              (1UL << ARM_V7M_CM7_ITCMCR_EN_Pos)
/* RMW - Read-Modify-Write, bit[1] */
#define ARM_V7M_CM7_ITCMCR_RMW_Pos             1U
#define ARM_V7M_CM7_ITCMCR_RMW_Msk             (1UL << ARM_V7M_CM7_ITCMCR_RMW_Pos)
/* RETEN - Retention enable, bit[2] */
#define ARM_V7M_CM7_ITCMCR_RETEN_Pos           2U
#define ARM_V7M_CM7_ITCMCR_RETEN_Msk           (1UL << ARM_V7M_CM7_ITCMCR_RETEN_Pos)
/* SZ - Size, bits[6:3] */
#define ARM_V7M_CM7_ITCMCR_SZ_Pos              3U
#define ARM_V7M_CM7_ITCMCR_SZ_Msk              (0xFUL << ARM_V7M_CM7_ITCMCR_SZ_Pos)

/* -----------------------------------------------------------------------------
 * 1.4 DTCMCR 寄存器位域 (ARM_V7M_CM7_SCS_DTCMCR)
 * 参考：Table 3-9 DTCMCR bit assignments (DDI 0489F)
 *       3.3.6 Instruction and Data TCM Control Registers on page 3-13 (DDI 0489F)
 * 地址：0xE000EF94
 * 复位值：0x00000000
 * 与通用 v7m 的差异：
 *   - 此寄存器为 Cortex-M7 特有
 *   - 通用 arm_v7m_macro.h 中无此寄存器位域定义
 * -----------------------------------------------------------------------------
 */
/* EN - Enable, bit[0] */
#define ARM_V7M_CM7_DTCMCR_EN_Pos              0U
#define ARM_V7M_CM7_DTCMCR_EN_Msk              (1UL << ARM_V7M_CM7_DTCMCR_EN_Pos)
/* RMW - Read-Modify-Write, bit[1] */
#define ARM_V7M_CM7_DTCMCR_RMW_Pos             1U
#define ARM_V7M_CM7_DTCMCR_RMW_Msk             (1UL << ARM_V7M_CM7_DTCMCR_RMW_Pos)
/* RETEN - Retention enable, bit[2] */
#define ARM_V7M_CM7_DTCMCR_RETEN_Pos           2U
#define ARM_V7M_CM7_DTCMCR_RETEN_Msk           (1UL << ARM_V7M_CM7_DTCMCR_RETEN_Pos)
/* SZ - Size, bits[6:3] */
#define ARM_V7M_CM7_DTCMCR_SZ_Pos              3U
#define ARM_V7M_CM7_DTCMCR_SZ_Msk              (0xFUL << ARM_V7M_CM7_DTCMCR_SZ_Pos)

/* -----------------------------------------------------------------------------
 * 1.5 AHBPCR 寄存器位域 (ARM_V7M_CM7_SCS_AHBPCR)
 * 参考：Table 3-10 AHBPCR bit assignments (DDI 0489F)
 *       3.3.7 AHBP Control Register on page 3-14 (DDI 0489F)
 * 地址：0xE000EF98
 * 复位值：0x00000000
 * 与通用 v7m 的差异：
 *   - 此寄存器为 Cortex-M7 特有
 *   - 通用 arm_v7m_macro.h 中无此寄存器位域定义
 * -----------------------------------------------------------------------------
 */
/* EN - Enable, bit[0] */
#define ARM_V7M_CM7_AHBPCR_EN_Pos              0U
#define ARM_V7M_CM7_AHBPCR_EN_Msk              (1UL << ARM_V7M_CM7_AHBPCR_EN_Pos)
/* SZ - Size, bits[3:1] */
#define ARM_V7M_CM7_AHBPCR_SZ_Pos              1U
#define ARM_V7M_CM7_AHBPCR_SZ_Msk              (0x7UL << ARM_V7M_CM7_AHBPCR_SZ_Pos)

/* -----------------------------------------------------------------------------
 * 1.6 CACR 寄存器位域 (ARM_V7M_CM7_SCS_CACR)
 * 参考：Table 3-11 CACR bit assignments (DDI 0489F)
 *       3.3.8 L1 Cache Control Register on page 3-15 (DDI 0489F)
 * 地址：0xE000EF9C
 * 复位值：0x00000000
 * 与通用 v7m 的差异：
 *   - 此寄存器为 Cortex-M7 特有
 *   - 通用 arm_v7m_macro.h 中无此寄存器位域定义
 * -----------------------------------------------------------------------------
 */
/* SIWT - Shared cacheable-is-WT for data cache, bit[0] */
#define ARM_V7M_CM7_CACR_SIWT_Pos              0U
#define ARM_V7M_CM7_CACR_SIWT_Msk              (1UL << ARM_V7M_CM7_CACR_SIWT_Pos)
/* ECCDIS - ECC disable, bit[1] */
#define ARM_V7M_CM7_CACR_ECCDIS_Pos            1U
#define ARM_V7M_CM7_CACR_ECCDIS_Msk            (1UL << ARM_V7M_CM7_CACR_ECCDIS_Pos)
/* FORCEWT - Force Write Through, bit[2] */
#define ARM_V7M_CM7_CACR_FORCEWT_Pos           2U
#define ARM_V7M_CM7_CACR_FORCEWT_Msk           (1UL << ARM_V7M_CM7_CACR_FORCEWT_Pos)

/* -----------------------------------------------------------------------------
 * 1.7 AHBSCR 寄存器位域 (ARM_V7M_CM7_SCS_AHBSCR)
 * 参考：Table 3-15 AHBSCR bit assignments (DDI 0489F)
 *       3.3.12 AHB Slave Control Register on page 3-20 (DDI 0489F)
 * 地址：0xE000EFA0
 * 复位值：0x00000001
 * 与通用 v7m 的差异：
 *   - 此寄存器为 Cortex-M7 特有
 *   - 通用 arm_v7m_macro.h 中无此寄存器位域定义
 * -----------------------------------------------------------------------------
 */
/* CTL - AHBS prioritization control, bits[1:0] */
#define ARM_V7M_CM7_AHBSCR_CTL_Pos             0U
#define ARM_V7M_CM7_AHBSCR_CTL_Msk             (0x3UL << ARM_V7M_CM7_AHBSCR_CTL_Pos)
/* TPRI - Threshold execution priority for AHBS traffic demotion, bits[10:2] */
#define ARM_V7M_CM7_AHBSCR_TPRI_Pos            2U
#define ARM_V7M_CM7_AHBSCR_TPRI_Msk            (0x1FFUL << ARM_V7M_CM7_AHBSCR_TPRI_Pos)
/* INITCOUNT - Fairness counter initialization value, bits[15:11] */
#define ARM_V7M_CM7_AHBSCR_INITCOUNT_Pos       11U
#define ARM_V7M_CM7_AHBSCR_INITCOUNT_Msk       (0x1FUL << ARM_V7M_CM7_AHBSCR_INITCOUNT_Pos)

/* -----------------------------------------------------------------------------
 * 1.8 ABFSR 寄存器位域 (ARM_V7M_CM7_SCS_ABFSR)
 * 参考：Table 3-12 ABFSR bit assignments (DDI 0489F)
 *       3.3.9 Auxiliary Bus Fault Status Register on page 3-16 (DDI 0489F)
 * 地址：0xE000EFA8
 * 复位值：0x00000000
 * 与通用 v7m 的差异：
 *   - 此寄存器为 Cortex-M7 特有
 *   - 通用 arm_v7m_macro.h 中无此寄存器位域定义
 * -----------------------------------------------------------------------------
 */
/* ITCM - ITCM fault, bit[0] */
#define ARM_V7M_CM7_ABFSR_ITCM_Pos             0U
#define ARM_V7M_CM7_ABFSR_ITCM_Msk             (1UL << ARM_V7M_CM7_ABFSR_ITCM_Pos)
/* DTCM - DTCM fault, bit[1] */
#define ARM_V7M_CM7_ABFSR_DTCM_Pos             1U
#define ARM_V7M_CM7_ABFSR_DTCM_Msk             (1UL << ARM_V7M_CM7_ABFSR_DTCM_Pos)
/* AHBP - AHBP fault, bit[2] */
#define ARM_V7M_CM7_ABFSR_AHBP_Pos             2U
#define ARM_V7M_CM7_ABFSR_AHBP_Msk             (1UL << ARM_V7M_CM7_ABFSR_AHBP_Pos)
/* AXIM - AXIM fault, bit[3] */
#define ARM_V7M_CM7_ABFSR_AXIM_Pos             3U
#define ARM_V7M_CM7_ABFSR_AXIM_Msk             (1UL << ARM_V7M_CM7_ABFSR_AXIM_Pos)
/* EPPB - EPPB fault, bit[4] */
#define ARM_V7M_CM7_ABFSR_EPPB_Pos             4U
#define ARM_V7M_CM7_ABFSR_EPPB_Msk             (1UL << ARM_V7M_CM7_ABFSR_EPPB_Pos)
/* AXIMTYPE - Type of fault on the AXIM interface, bits[9:8] */
#define ARM_V7M_CM7_ABFSR_AXIMTYPE_Pos         8U
#define ARM_V7M_CM7_ABFSR_AXIMTYPE_Msk         (0x3UL << ARM_V7M_CM7_ABFSR_AXIMTYPE_Pos)

/* -----------------------------------------------------------------------------
 * 1.9 IEBR0-1 寄存器位域 (ARM_V7M_CM7_SCS_IEBR0/1)
 * 参考：Table 3-13 IEBR0-1 bit assignments (DDI 0489F)
 *       3.3.10 Instruction Error bank Register 0-1 on page 3-17 (DDI 0489F)
 * 地址：0xE000EFB0 (IEBR0), 0xE000EFB4 (IEBR1)
 * 复位值：- (未定义)
 * 与通用 v7m 的差异：
 *   - 此寄存器为 Cortex-M7 特有
 *   - 通用 arm_v7m_macro.h 中无此寄存器位域定义
 *   - 仅在 ECC 可配置选项实现时可用
 * -----------------------------------------------------------------------------
 */
/* VALID - 条目有效标志, bit[0] */
#define ARM_V7M_CM7_IEBR_VALID_Pos              0U
#define ARM_V7M_CM7_IEBR_VALID_Msk              (1UL << ARM_V7M_CM7_IEBR_VALID_Pos)
/* LOCKED - 位置锁定标志, bit[1] */
#define ARM_V7M_CM7_IEBR_LOCKED_Pos             1U
#define ARM_V7M_CM7_IEBR_LOCKED_Msk             (1UL << ARM_V7M_CM7_IEBR_LOCKED_Pos)
/* RAM_LOCATION - 指令缓存 RAM 位置, bits[15:2] */
#define ARM_V7M_CM7_IEBR_RAM_LOCATION_Pos       2U
#define ARM_V7M_CM7_IEBR_RAM_LOCATION_Msk       (0x3FFFUL << ARM_V7M_CM7_IEBR_RAM_LOCATION_Pos)
/* RAM_BANK - RAM 存储体选择, bit[16] */
#define ARM_V7M_CM7_IEBR_RAM_BANK_Pos           16U
#define ARM_V7M_CM7_IEBR_RAM_BANK_Msk           (1UL << ARM_V7M_CM7_IEBR_RAM_BANK_Pos)
/* TYPE_OF_ERROR - 错误类型, bit[17] */
#define ARM_V7M_CM7_IEBR_TYPE_OF_ERROR_Pos      17U
#define ARM_V7M_CM7_IEBR_TYPE_OF_ERROR_Msk      (1UL << ARM_V7M_CM7_IEBR_TYPE_OF_ERROR_Pos)
/* RESERVED_29_18 - 保留位, bits[29:18] */
#define ARM_V7M_CM7_IEBR_RESERVED_29_18_Pos     18U
#define ARM_V7M_CM7_IEBR_RESERVED_29_18_Msk     (0xFFFUL << ARM_V7M_CM7_IEBR_RESERVED_29_18_Pos)
/* USER_DEFINED - 用户定义位, bits[31:30] */
#define ARM_V7M_CM7_IEBR_USER_DEFINED_Pos       30U
#define ARM_V7M_CM7_IEBR_USER_DEFINED_Msk       (0x3UL << ARM_V7M_CM7_IEBR_USER_DEFINED_Pos)

/* -----------------------------------------------------------------------------
 * 1.10 DEBR0-1 寄存器位域 (ARM_V7M_CM7_SCS_DEBR0/1)
 * 参考：Table 3-14 DEBR0-1 bit assignments (DDI 0489F)
 *       3.3.11 Data Error bank Register 0-1 on page 3-18 (DDI 0489F)
 * 地址：0xE000EFB8 (DEBR0), 0xE000EFBC (DEBR1)
 * 复位值：- (未定义)
 * 与通用 v7m 的差异：
 *   - 此寄存器为 Cortex-M7 特有
 *   - 通用 arm_v7m_macro.h 中无此寄存器位域定义
 *   - 仅在 ECC 可配置选项实现时可用
 * -----------------------------------------------------------------------------
 */
/* VALID - 条目有效标志, bit[0] */
#define ARM_V7M_CM7_DEBR_VALID_Pos              0U
#define ARM_V7M_CM7_DEBR_VALID_Msk              (1UL << ARM_V7M_CM7_DEBR_VALID_Pos)
/* LOCKED - 位置锁定标志, bit[1] */
#define ARM_V7M_CM7_DEBR_LOCKED_Pos             1U
#define ARM_V7M_CM7_DEBR_LOCKED_Msk             (1UL << ARM_V7M_CM7_DEBR_LOCKED_Pos)
/* RAM_LOCATION - 数据缓存 RAM 位置, bits[15:2] */
#define ARM_V7M_CM7_DEBR_RAM_LOCATION_Pos       2U
#define ARM_V7M_CM7_DEBR_RAM_LOCATION_Msk       (0x3FFFUL << ARM_V7M_CM7_DEBR_RAM_LOCATION_Pos)
/* RAM_BANK - RAM 存储体选择, bit[16] */
#define ARM_V7M_CM7_DEBR_RAM_BANK_Pos           16U
#define ARM_V7M_CM7_DEBR_RAM_BANK_Msk           (1UL << ARM_V7M_CM7_DEBR_RAM_BANK_Pos)
/* TYPE_OF_ERROR - 错误类型, bit[17] */
#define ARM_V7M_CM7_DEBR_TYPE_OF_ERROR_Pos      17U
#define ARM_V7M_CM7_DEBR_TYPE_OF_ERROR_Msk      (1UL << ARM_V7M_CM7_DEBR_TYPE_OF_ERROR_Pos)
/* RESERVED_29_18 - 保留位, bits[29:18] */
#define ARM_V7M_CM7_DEBR_RESERVED_29_18_Pos     18U
#define ARM_V7M_CM7_DEBR_RESERVED_29_18_Msk     (0xFFFUL << ARM_V7M_CM7_DEBR_RESERVED_29_18_Pos)
/* USER_DEFINED - 用户定义位, bits[31:30] */
#define ARM_V7M_CM7_DEBR_USER_DEFINED_Pos       30U
#define ARM_V7M_CM7_DEBR_USER_DEFINED_Msk       (0x3UL << ARM_V7M_CM7_DEBR_USER_DEFINED_Pos)

#ifdef __cplusplus
}
#endif

#endif /* __ARM_V7M_CM7_MACRO_H__ */
