/********************************************************************************
 * @file        arm_v7m_cm4_macro.h
 * @brief       ARM Cortex-M4 Processor Register Bit-field Macros
 * @details     基于 Cortex-M4 Devices Generic User Guide (ARM DUI 0553B)
 *              和 Cortex-M4 Processor Technical Reference Manual (100166_0001_04_en)
 *              文档路径：
 *              - g:\develop\FeatherCore\FeatherArch\docs\arm\Arm® Cortex™-M4 Devices Generic User Guide.txt
 *              - g:\develop\FeatherCore\FeatherArch\docs\arm\Arm® Cortex™-M4 Processor Technical Reference Manual.txt
 * @author      FeatherCore
 * @version     1.0.0
 * @date        2026-03-29
 * @note        本文件仅包含 Cortex-M4 特定寄存器的位域宏定义
 *              代码风格严格对齐 arm_v7m_macro.h
 *
 * 寄存器位域覆盖清单：
 * - ACTLR (Auxiliary Control Register)
 *   参考：Table 4-13 ACTLR bit assignments (DUI 0553B)
 *         Figure 4-1 ACTLR bit assignments (100166_0001_04_en)
 * - CPUID (CPUID Base Register)
 *   参考：Table 4-14 CPUID register bit assignments (DUI 0553B)
 *         Figure 4-2 CPUID bit assignments (100166_0001_04_en)
 * - CPACR (Coprocessor Access Control Register)
 *   参考：Table 4-50 CPACR register bit assignments (DUI 0553B)
 * - AFSR (Auxiliary Fault Status Register)
 *   参考：Table 4-31 AFSR bit assignments (DUI 0553B)
 *         Figure 4-3 AFSR bit assignments (100166_0001_04_en)
 * - FPCCR (Floating-point Context Control Register)
 *   参考：Table 4-51 FPCCR register bit assignments (DUI 0553B)
 * - FPCAR (Floating-point Context Address Register)
 *   参考：Table 4-52 FPCAR register bit assignments (DUI 0553B)
 * - FPDSCR (Floating-point Default Status Control Register)
 *   参考：Table 4-54 FPDSCR register bit assignments (DUI 0553B)
 * - MVFR0/MVFR1 (Media and FP Feature Registers)
 *   参考：Table 7-4 Cortex-M4 Floating Point system registers (100166_0001_04_en)
 *         Armv7-M Architecture Reference Manual (ARM DDI 0403E.e)
 *         B4.7 Media and FP Feature Registers on page B4-662
 *
 * 与通用 arm_v7m_macro.h 的主要差异：
 * 1. ACTLR 寄存器位域：
 *    - 通用 arm_v7m_macro.h 中 ACTLR 为 IMPLEMENTATION DEFINED，未定义具体位域
 *    - Cortex-M4 定义了具体位域：DISMCYCINT(bit[0]), DISDEFWBUF(bit[1]), DISFOLD(bit[2]), 
 *      DISFPCA(bit[8]), DISOOFP(bit[9])
 * 2. CPUID 寄存器：
 *    - Cortex-M4 定义了具体的 PARTNO=0xC24 和 REVISION=0x0/0x1 的值定义
 *    - 复位值：0x410FC240 (r0p0) 或 0x410FC241 (r0p1)
 * 3. CPACR 寄存器：
 *    - Cortex-M4 定义了 CP10/CP11 访问控制的具体值定义
 * 4. FPU 寄存器：
 *    - Cortex-M4F 实现 FPv4-SP，仅支持单精度浮点
 *    - MVFR0 复位值：0x10110021 (Cortex-M4F)
 *    - MVFR1 复位值：0x11000011 (Cortex-M4F)
 *    - 未包含 MVFR2 位域定义（Cortex-M4 中 MVFR2 读取为 0）
 *
 * 通用寄存器位域（引用 arm_v7m_macro.h）：
 *   - 所有其他 Armv7-M 寄存器位域定义请参考 arm_v7m_macro.h
 ********************************************************************************/

#ifndef __ARM_V7M_CM4_MACRO_H__
#define __ARM_V7M_CM4_MACRO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* ==============================================================================
 * 一、Cortex-M4 特定寄存器位域 (Cortex-M4 Specific Register Bit-fields)
 * 参考：Table 4-1 System control registers (100166_0001_04_en)
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 1.1 ACTLR 寄存器位域 (ARM_V7M_CM4_SCS_ACTLR)
 * 参考：Table 4-13 ACTLR bit assignments (DUI 0553B)
 *       Figure 4-1 ACTLR bit assignments (100166_0001_04_en)
 *       4.3.1 Auxiliary Control Register on page 4-11 (DUI 0553B)
 * 地址：0xE000E008
 * 复位值：0x00000000
 * 与通用 v7m 的差异：
 *   - 通用 arm_v7m_macro.h 中 ACTLR 为 IMPLEMENTATION DEFINED，未定义具体位域
 *   - Cortex-M4 定义了具体的位域：DISMCYCINT(bit[0]), DISDEFWBUF(bit[1]), 
 *     DISFOLD(bit[2]), DISFPCA(bit[8]), DISOOFP(bit[9])
 * -----------------------------------------------------------------------------
 */
/* DISMCYCINT - Disable multi-cycle interrupt, bit[0] */
#define ARM_V7M_CM4_ACTLR_DISMCYCINT_Pos    0U
#define ARM_V7M_CM4_ACTLR_DISMCYCINT_Msk    (1UL << ARM_V7M_CM4_ACTLR_DISMCYCINT_Pos)
/* DISDEFWBUF - Disable default memory map write buffer, bit[1] */
#define ARM_V7M_CM4_ACTLR_DISDEFWBUF_Pos    1U
#define ARM_V7M_CM4_ACTLR_DISDEFWBUF_Msk    (1UL << ARM_V7M_CM4_ACTLR_DISDEFWBUF_Pos)
/* DISFOLD - Disable IT folding, bit[2] */
#define ARM_V7M_CM4_ACTLR_DISFOLD_Pos       2U
#define ARM_V7M_CM4_ACTLR_DISFOLD_Msk       (1UL << ARM_V7M_CM4_ACTLR_DISFOLD_Pos)
/* DISFPCA - Disable automatic CONTROL.FPCA update, bit[8] */
#define ARM_V7M_CM4_ACTLR_DISFPCA_Pos       8U
#define ARM_V7M_CM4_ACTLR_DISFPCA_Msk       (1UL << ARM_V7M_CM4_ACTLR_DISFPCA_Pos)
/* DISOOFP - Disable out-of-order floating-point completion, bit[9] */
#define ARM_V7M_CM4_ACTLR_DISOOFP_Pos       9U
#define ARM_V7M_CM4_ACTLR_DISOOFP_Msk       (1UL << ARM_V7M_CM4_ACTLR_DISOOFP_Pos)

/* -----------------------------------------------------------------------------
 * 1.2 CPUID 寄存器位域 (ARM_V7M_CM4_SCB_CPUID)
 * 参考：Table 4-14 CPUID register bit assignments (DUI 0553B)
 *       Figure 4-2 CPUID bit assignments (100166_0001_04_en)
 *       4.3.2 CPUID Base Register on page 4-13 (DUI 0553B)
 * 地址：0xE000ED00
 * 复位值：0x410FC240 (r0p0) 或 0x410FC241 (r0p1)
 * 与通用 v7m 的差异：
 *   - 位域定义与通用 arm_v7m_macro.h 中的 CPUID 位域相同
 *   - Cortex-M4 定义了具体的 PARTNO=0xC24 和 REVISION=0x0/0x1 的值定义
 *   - 通用 arm_v7m_macro.h 中未定义具体的 PARTNO 和 REVISION 值
 * -----------------------------------------------------------------------------
 */
/* Revision - IMPLEMENTATION DEFINED revision number (p value), bits[3:0] */
#define ARM_V7M_CM4_CPUID_REVISION_Pos      0U
#define ARM_V7M_CM4_CPUID_REVISION_Msk      (0xFUL << ARM_V7M_CM4_CPUID_REVISION_Pos)
/* PartNo - IMPLEMENTATION DEFINED part number, bits[15:4] */
#define ARM_V7M_CM4_CPUID_PARTNO_Pos        4U
#define ARM_V7M_CM4_CPUID_PARTNO_Msk        (0xFFFUL << ARM_V7M_CM4_CPUID_PARTNO_Pos)
/* Constant - Constant value (0xF), bits[19:16] */
#define ARM_V7M_CM4_CPUID_CONSTANT_Pos      16U
#define ARM_V7M_CM4_CPUID_CONSTANT_Msk      (0xFUL << ARM_V7M_CM4_CPUID_CONSTANT_Pos)
/* Variant - IMPLEMENTATION DEFINED variant number (r value), bits[23:20] */
#define ARM_V7M_CM4_CPUID_VARIANT_Pos       20U
#define ARM_V7M_CM4_CPUID_VARIANT_Msk       (0xFUL << ARM_V7M_CM4_CPUID_VARIANT_Pos)
/* Implementer - Implementer code (0x41 for ARM), bits[31:24] */
#define ARM_V7M_CM4_CPUID_IMPLEMENTER_Pos   24U
#define ARM_V7M_CM4_CPUID_IMPLEMENTER_Msk   (0xFFUL << ARM_V7M_CM4_CPUID_IMPLEMENTER_Pos)

/* ==============================================================================
 * 1.2.1 CPUID 值定义宏 (CPUID Value Definition Macros)
 * 非寄存器位域宏，用于定义 CPUID 寄存器的具体值
 * ==============================================================================
 */
/* CPUID 值定义 - Cortex-M4 特定值 */
#define ARM_V7M_CM4_CPUID_IMPLEMENTER_ARM   (0x41UL << ARM_V7M_CM4_CPUID_IMPLEMENTER_Pos)
#define ARM_V7M_CM4_CPUID_PARTNO_CM4        (0xC24UL << ARM_V7M_CM4_CPUID_PARTNO_Pos)
#define ARM_V7M_CM4_CPUID_CONSTANT_VAL      (0xFUL << ARM_V7M_CM4_CPUID_CONSTANT_Pos)

/* CPUID 复位值定义 - Cortex-M4 不同版本 */
#define ARM_V7M_CM4_CPUID_RESET_R0P0        0x410FC240UL
#define ARM_V7M_CM4_CPUID_RESET_R0P1        0x410FC241UL

/* -----------------------------------------------------------------------------
 * 1.3 CPACR 寄存器位域 (ARM_V7M_CM4_SCB_CPACR)
 * 参考：Table 4-50 CPACR register bit assignments (DUI 0553B)
 *       4.6.1 Coprocessor Access Control Register on page 4-48 (DUI 0553B)
 * 地址：0xE000ED88
 * 复位值：0x00000000
 * 与通用 v7m 的差异：
 *   - 位域定义与通用 arm_v7m_macro.h 中的 CPACR 位域相同
 *   - Cortex-M4 定义了 CP10/CP11 访问控制的具体值定义
 *   - 通用 arm_v7m_macro.h 中未定义具体的访问控制值
 * -----------------------------------------------------------------------------
 */
/* CP10 - Coprocessor 10 access control, bits[21:20] */
#define ARM_V7M_CM4_CPACR_CP10_Pos          20U
#define ARM_V7M_CM4_CPACR_CP10_Msk          (3UL << ARM_V7M_CM4_CPACR_CP10_Pos)
/* CP11 - Coprocessor 11 access control, bits[23:22] */
#define ARM_V7M_CM4_CPACR_CP11_Pos          22U
#define ARM_V7M_CM4_CPACR_CP11_Msk          (3UL << ARM_V7M_CM4_CPACR_CP11_Pos)

/* ==============================================================================
 * 1.3.1 CPACR 值定义宏 (CPACR Value Definition Macros)
 * 非寄存器位域宏，用于定义 CPACR 寄存器的访问控制值
 * ==============================================================================
 */
/* CP10/CP11 访问控制值定义 */
#define ARM_V7M_CM4_CPACR_CP_ACCESS_DENIED      (0x0UL)   /* 0b00: Access denied, generates NOCP UsageFault */
#define ARM_V7M_CM4_CPACR_CP_PRIVILEGED_ONLY    (0x1UL)   /* 0b01: Privileged access only */
#define ARM_V7M_CM4_CPACR_CP_RESERVED           (0x2UL)   /* 0b10: Reserved, unpredictable */
#define ARM_V7M_CM4_CPACR_CP_FULL_ACCESS        (0x3UL)   /* 0b11: Full access */

/* -----------------------------------------------------------------------------
 * 1.4 AFSR 寄存器位域 (ARM_V7M_CM4_SCB_AFSR)
 * 参考：Table 4-31 AFSR bit assignments (DUI 0553B)
 *       Figure 4-3 AFSR bit assignments (100166_0001_04_en)
 *       4.3.14 Auxiliary Fault Status Register on page 4-31 (DUI 0553B)
 * 地址：0xE000ED3C
 * 复位值：0x00000000
 * 与通用 v7m 的差异：
 *   - Cortex-M4 中 AFSR 为 32 位 IMPLEMENTATION DEFINED 寄存器
 *   - 每位对应一个 AUXFAULT 输入信号
 *   - 写 1 清除，写 0 无影响
 * -----------------------------------------------------------------------------
 */
/* IMPDEF - Implementation defined. The bits map to the AUXFAULT input signals, bits[31:0] */
#define ARM_V7M_CM4_AFSR_IMPDEF_Pos         0U
#define ARM_V7M_CM4_AFSR_IMPDEF_Msk         (0xFFFFFFFFUL << ARM_V7M_CM4_AFSR_IMPDEF_Pos)

/* ==============================================================================
 * 二、Cortex-M4F 浮点单元寄存器位域 (Cortex-M4F FPU Register Bit-fields)
 * 参考：4.6 Floating Point Unit (FPU) on page 4-48 (DUI 0553B)
 *       Chapter 7 Floating-Point Unit (100166_0001_04_en)
 *       Table 7-4 Cortex-M4 Floating Point system registers (100166_0001_04_en)
 * 与通用 v7m 的差异：
 *   - 这些位域定义与通用 arm_v7m_macro.h 中的 FPU 寄存器位域相同
 *   - Cortex-M4 实现 FPv4-SP，仅支持单精度浮点运算
 *   - Cortex-M4 定义了 MVFR0 和 MVFR1 的 Cortex-M4F 具体值定义
 *   - 未包含 MVFR2 位域定义（Cortex-M4 中 MVFR2 读取为 0，不支持 FPv5）
 * 注意：这些寄存器仅在实现了 FPU (Cortex-M4F) 的处理器中存在
 *       Cortex-M4 实现 FPv4-SP 扩展，仅支持单精度浮点运算
 * ==============================================================================
 */

/* -----------------------------------------------------------------------------
 * 2.1 FPCCR 寄存器位域 (ARM_V7M_CM4_FPU_FPCCR)
 * 参考：Table 4-51 FPCCR register bit assignments (DUI 0553B)
 *       4.6.2 Floating-point Context Control Register on page 4-49 (DUI 0553B)
 * 地址：0xE000EF34
 * 复位值：0xC0000000
 * -----------------------------------------------------------------------------
 */
/* LSPACT - Lazy state preservation active, bit[0] */
#define ARM_V7M_CM4_FPCCR_LSPACT_Pos        0U
#define ARM_V7M_CM4_FPCCR_LSPACT_Msk        (1UL << ARM_V7M_CM4_FPCCR_LSPACT_Pos)
/* USER - User mode flag, bit[1] */
#define ARM_V7M_CM4_FPCCR_USER_Pos          1U
#define ARM_V7M_CM4_FPCCR_USER_Msk          (1UL << ARM_V7M_CM4_FPCCR_USER_Pos)
/* THREAD - Thread mode flag, bit[3] */
#define ARM_V7M_CM4_FPCCR_THREAD_Pos        3U
#define ARM_V7M_CM4_FPCCR_THREAD_Msk        (1UL << ARM_V7M_CM4_FPCCR_THREAD_Pos)
/* HFRDY - HardFault ready, bit[4] */
#define ARM_V7M_CM4_FPCCR_HFRDY_Pos         4U
#define ARM_V7M_CM4_FPCCR_HFRDY_Msk         (1UL << ARM_V7M_CM4_FPCCR_HFRDY_Pos)
/* MMRDY - MemManage ready, bit[5] */
#define ARM_V7M_CM4_FPCCR_MMRDY_Pos         5U
#define ARM_V7M_CM4_FPCCR_MMRDY_Msk         (1UL << ARM_V7M_CM4_FPCCR_MMRDY_Pos)
/* BFRDY - BusFault ready, bit[6] */
#define ARM_V7M_CM4_FPCCR_BFRDY_Pos         6U
#define ARM_V7M_CM4_FPCCR_BFRDY_Msk         (1UL << ARM_V7M_CM4_FPCCR_BFRDY_Pos)
/* MONRDY - DebugMonitor ready, bit[8] */
#define ARM_V7M_CM4_FPCCR_MONRDY_Pos        8U
#define ARM_V7M_CM4_FPCCR_MONRDY_Msk        (1UL << ARM_V7M_CM4_FPCCR_MONRDY_Pos)
/* LSPEN - Lazy state preservation enable, bit[30] */
#define ARM_V7M_CM4_FPCCR_LSPEN_Pos         30U
#define ARM_V7M_CM4_FPCCR_LSPEN_Msk         (1UL << ARM_V7M_CM4_FPCCR_LSPEN_Pos)
/* ASPEN - Automatic state preservation enable, bit[31] */
#define ARM_V7M_CM4_FPCCR_ASPEN_Pos         31U
#define ARM_V7M_CM4_FPCCR_ASPEN_Msk         (1UL << ARM_V7M_CM4_FPCCR_ASPEN_Pos)

/* -----------------------------------------------------------------------------
 * 2.2 FPCAR 寄存器位域 (ARM_V7M_CM4_FPU_FPCAR)
 * 参考：Table 4-52 FPCAR register bit assignments (DUI 0553B)
 *       4.6.3 Floating-point Context Address Register on page 4-50 (DUI 0553B)
 * 地址：0xE000EF38
 * 复位值：Unknown
 * -----------------------------------------------------------------------------
 */
/* ADDRESS - The location of the unpopulated floating-point register space allocated on an exception stack frame, bits[31:3] */
#define ARM_V7M_CM4_FPCAR_ADDRESS_Pos       3U
#define ARM_V7M_CM4_FPCAR_ADDRESS_Msk       (0x1FFFFFFFUL << ARM_V7M_CM4_FPCAR_ADDRESS_Pos)

/* -----------------------------------------------------------------------------
 * 2.3 FPDSCR 寄存器位域 (ARM_V7M_CM4_FPU_FPDSCR)
 * 参考：Table 4-54 FPDSCR register bit assignments (DUI 0553B)
 *       4.6.5 Floating-point Default Status Control Register on page 4-52 (DUI 0553B)
 * 地址：0xE000EF3C
 * 复位值：0x00000000
 * -----------------------------------------------------------------------------
 */
/* RMode - Rounding mode control, bits[23:22] */
#define ARM_V7M_CM4_FPDSCR_RMODE_Pos        22U
#define ARM_V7M_CM4_FPDSCR_RMODE_Msk        (3UL << ARM_V7M_CM4_FPDSCR_RMODE_Pos)
/* FZ - Flush-to-zero mode, bit[24] */
#define ARM_V7M_CM4_FPDSCR_FZ_Pos           24U
#define ARM_V7M_CM4_FPDSCR_FZ_Msk           (1UL << ARM_V7M_CM4_FPDSCR_FZ_Pos)
/* DN - Default NaN mode, bit[25] */
#define ARM_V7M_CM4_FPDSCR_DN_Pos           25U
#define ARM_V7M_CM4_FPDSCR_DN_Msk           (1UL << ARM_V7M_CM4_FPDSCR_DN_Pos)
/* AHP - Alternative half-precision control, bit[26] */
#define ARM_V7M_CM4_FPDSCR_AHP_Pos          26U
#define ARM_V7M_CM4_FPDSCR_AHP_Msk          (1UL << ARM_V7M_CM4_FPDSCR_AHP_Pos)

/* ==============================================================================
 * 2.3.1 FPDSCR 值定义宏 (FPDSCR Value Definition Macros)
 * 非寄存器位域宏，用于定义 FPDSCR 寄存器的舍入模式值
 * ==============================================================================
 */
/* FPDSCR RMode 值定义 */
#define ARM_V7M_CM4_FPDSCR_RMODE_RN         (0x0UL << ARM_V7M_CM4_FPDSCR_RMODE_Pos)   /* Round to Nearest (RN) */
#define ARM_V7M_CM4_FPDSCR_RMODE_RP         (0x1UL << ARM_V7M_CM4_FPDSCR_RMODE_Pos)   /* Round towards Plus Infinity (RP) */
#define ARM_V7M_CM4_FPDSCR_RMODE_RM         (0x2UL << ARM_V7M_CM4_FPDSCR_RMODE_Pos)   /* Round towards Minus Infinity (RM) */
#define ARM_V7M_CM4_FPDSCR_RMODE_RZ         (0x3UL << ARM_V7M_CM4_FPDSCR_RMODE_Pos)   /* Round towards Zero (RZ) */

/* -----------------------------------------------------------------------------
 * 2.4 MVFR0 寄存器位域 (ARM_V7M_CM4_FPU_MVFR0)
 * 参考: B4.7.1 Media and FP Feature Register 0, MVFR0 on page B4-662
 *       Table 7-4 Cortex-M4 Floating Point system registers (100166_0001_04_en)
 * 地址：0xE000EF40
 * 复位值：0x10110021 (Cortex-M4F)
 * 与通用 v7m 的差异：
 *   - 位域定义与通用 arm_v7m_macro.h 中的 MVFR0 位域相同
 *   - Cortex-M4 实现 FPv4-SP，仅支持单精度浮点
 *   - 通用 arm_v7m_macro.h 中 MVFR0 定义适用于所有 ARMv7-M 处理器
 * -----------------------------------------------------------------------------
 */
/* FPROUND - Floating-point rounding modes, bits[31:28] */
#define ARM_V7M_CM4_MVFR0_FPROUND_Pos       28U
#define ARM_V7M_CM4_MVFR0_FPROUND_Msk       (0xFUL << ARM_V7M_CM4_MVFR0_FPROUND_Pos)
/* SHORTVEC - Short vectors, bits[27:24] */
#define ARM_V7M_CM4_MVFR0_SHORTVEC_Pos       24U
#define ARM_V7M_CM4_MVFR0_SHORTVEC_Msk       (0xFUL << ARM_V7M_CM4_MVFR0_SHORTVEC_Pos)
/* SQRT - Square root, bits[23:20] */
#define ARM_V7M_CM4_MVFR0_SQRT_Pos           20U
#define ARM_V7M_CM4_MVFR0_SQRT_Msk           (0xFUL << ARM_V7M_CM4_MVFR0_SQRT_Pos)
/* DIVIDE - Divide, bits[19:16] */
#define ARM_V7M_CM4_MVFR0_DIVIDE_Pos         16U
#define ARM_V7M_CM4_MVFR0_DIVIDE_Msk         (0xFUL << ARM_V7M_CM4_MVFR0_DIVIDE_Pos)
/* FPEXC_TRP - Floating-point exception trapping, bits[15:12] */
#define ARM_V7M_CM4_MVFR0_FPEXC_TRP_Pos     12U
#define ARM_V7M_CM4_MVFR0_FPEXC_TRP_Msk     (0xFUL << ARM_V7M_CM4_MVFR0_FPEXC_TRP_Pos)
/* DP - Double-precision, bits[11:8] */
#define ARM_V7M_CM4_MVFR0_DP_Pos             8U
#define ARM_V7M_CM4_MVFR0_DP_Msk             (0xFUL << ARM_V7M_CM4_MVFR0_DP_Pos)
/* SP - Single-precision, bits[7:4] */
#define ARM_V7M_CM4_MVFR0_SP_Pos             4U
#define ARM_V7M_CM4_MVFR0_SP_Msk             (0xFUL << ARM_V7M_CM4_MVFR0_SP_Pos)
/* SIMDREG - SIMD registers, bits[3:0] */
#define ARM_V7M_CM4_MVFR0_SIMDREG_Pos        0U
#define ARM_V7M_CM4_MVFR0_SIMDREG_Msk        (0xFUL << ARM_V7M_CM4_MVFR0_SIMDREG_Pos)

/* ==============================================================================
 * 2.4.1 MVFR0 值定义宏 (MVFR0 Value Definition Macros)
 * 非寄存器位域宏，用于定义 MVFR0 寄存器的特征值
 * ==============================================================================
 */
/* MVFR0 Cortex-M4F (FPv4-SP) 特征值定义 */
#define ARM_V7M_CM4_MVFR0_SIMDREG_VAL        (0x1UL)   /* 0x1: 16 single-precision registers (S0-S15) or 32 double-precision registers (D0-D15) */
#define ARM_V7M_CM4_MVFR0_SP_VAL              (0x2UL)   /* 0x2: Single-precision supported */
#define ARM_V7M_CM4_MVFR0_DP_VAL              (0x0UL)   /* 0x0: Double-precision not supported (FPv4-SP) */
#define ARM_V7M_CM4_MVFR0_FPROUND_VAL         (0x1UL)   /* 0x1: All rounding modes supported */
#define ARM_V7M_CM4_MVFR0_DIVIDE_VAL          (0x1UL)   /* 0x1: Hardware divide supported */
#define ARM_V7M_CM4_MVFR0_SQRT_VAL            (0x1UL)   /* 0x1: Square root supported */
#define ARM_V7M_CM4_MVFR0_SHORTVEC_VAL        (0x0UL)  /* 0x0: Short vectors not supported (FPv4-SP) */
#define ARM_V7M_CM4_MVFR0_FPEXC_TRP_VAL       (0x0UL)  /* 0x0: No exception trapping (FPv4-SP) */

/* -----------------------------------------------------------------------------
 * 2.5 MVFR1 寄存器位域 (ARM_V7M_CM4_FPU_MVFR1)
 * 参考: B4.7.3 Media and FP Feature Register 1, MVFR1 on page B4-663
 *       Table 7-4 Cortex-M4 Floating Point system registers (100166_0001_04_en)
 * 地址：0xE000EF44
 * 复位值：0x11000011 (Cortex-M4F)
 * 与通用 v7m 的差异：
 *   - 位域定义与通用 arm_v7m_macro.h 中的 MVFR1 位域相同
 *   - Cortex-M4 实现 FPv4-SP，仅支持单精度浮点
 *   - 通用 arm_v7m_macro.h 中 MVFR1 定义适用于所有 ARMv7-M 处理器
 * -----------------------------------------------------------------------------
 */
/* FMAC - Fused multiply accumulate, bits[31:28] */
#define ARM_V7M_CM4_MVFR1_FMAC_Pos           28U
#define ARM_V7M_CM4_MVFR1_FMAC_Msk           (0xFUL << ARM_V7M_CM4_MVFR1_FMAC_Pos)
/* HPFP - Half-precision floating-point, bits[27:24] */
#define ARM_V7M_CM4_MVFR1_HPFP_Pos           24U
#define ARM_V7M_CM4_MVFR1_HPFP_Msk           (0xFUL << ARM_V7M_CM4_MVFR1_HPFP_Pos)
/* DNAN - Double-precision NaN, bits[7:4] */
#define ARM_V7M_CM4_MVFR1_DNAN_Pos            4U
#define ARM_V7M_CM4_MVFR1_DNAN_Msk           (0xFUL << ARM_V7M_CM4_MVFR1_DNAN_Pos)
/* FTZ - Flush-to-zero, bits[3:0] */
#define ARM_V7M_CM4_MVFR1_FTZ_Pos             0U
#define ARM_V7M_CM4_MVFR1_FTZ_Msk             (0xFUL << ARM_V7M_CM4_MVFR1_FTZ_Pos)

/* ==============================================================================
 * 2.5.1 MVFR1 值定义宏 (MVFR1 Value Definition Macros)
 * 非寄存器位域宏，用于定义 MVFR1 寄存器的特征值
 * ==============================================================================
 */
/* MVFR1 Cortex-M4F (FPv4-SP) 特征值定义 */
#define ARM_V7M_CM4_MVFR1_FTZ_VAL             (0x1UL)   /* 0x1: Flush-to-zero mode supported */
#define ARM_V7M_CM4_MVFR1_DNAN_VAL            (0x1UL)   /* 0x1: Default NaN mode supported */
#define ARM_V7M_CM4_MVFR1_HPFP_VAL            (0x1UL)   /* 0x1: Half-precision floating-point not supported (FPv4-SP) */
#define ARM_V7M_CM4_MVFR1_FMAC_VAL             (0x1UL)   /* 0x1: Fused multiply accumulate not supported (FPv4-SP) */

#ifdef __cplusplus
}
#endif

#endif /* __ARM_V7M_CM4_MACRO_H__ */
