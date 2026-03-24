/*
 * ARM Architecture - ARMv7-M System Control Block (SCB)
 *
 * ============================================================================
 * File: armv7-m_scb.h
 * Description: ARMv7-M System Control Block register definitions
 * 描述: ARMv7-M 系统控制块寄存器定义
 *
 * This file provides definitions for the System Control Block (SCB) registers
 * as described in Chapter B1.4 and B3.2 of the Architecture Reference Manual.
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter B1: System Level Programmers' Model
 *     * B1.4 Registers (page B1-516)
 *       - B1.4.1 The Arm core registers (page B1-516)
 *       - B1.4.2 The special-purpose Program Status Registers, xPSR (page B1-516)
 *   - Chapter B3: System Address Map
 *     * B3.2 System Control Space (SCS) (page B3-595)
 *       - B3.2.1 About the System Control Block (page B3-595)
 *       - B3.2.2 System control and ID registers (page B3-596)
 *       - Table B3-4 Summary of SCB registers (page B3-596)
 *         * CPUID - CPUID Base Register (page B3-598)
 *         * ICSR - Interrupt Control and State Register (page B3-599)
 *         * VTOR - Vector Table Offset Register (page B3-601)
 *         * AIRCR - Application Interrupt and Reset Control Register (page B3-601)
 *         * SCR - System Control Register (page B3-603)
 *         * CCR - Configuration and Control Register (page B3-604)
 *         * SHPR1-3 - System Handler Priority Registers (page B3-606)
 *         * SHCSR - System Handler Control and State Register (page B3-607)
 *         * CFSR - Configurable Fault Status Register (page B3-609)
 *         * HFSR - HardFault Status Register (page B3-612)
 *         * DFSR - Debug Fault Status Register (page C1-699)
 *         * MMFAR - MemManage Fault Address Register (page B3-613)
 *         * BFAR - BusFault Address Register (page B3-614)
 *         * AFSR - Auxiliary Fault Status Register (page B3-614)
 *         * CPACR - Coprocessor Access Control Register (page B3-614)
 *   - Chapter B4: The CPUID Scheme
 *     * B4.1 About the CPUID scheme (page B4-644)
 *       - CPUID scheme provides processor feature description
 *       - Architecture variant 0xF in CPUID indicates CPUID scheme
 *       - Privileged access only, unprivileged access causes BusFault
 *     * B4.1.2 Summary of the CPUID registers (page B4-644)
 *       - Table B4-1 Processor Feature ID register support in the SCS
 *         * ID_PFR0, ID_PFR1 - Processor Feature Registers (page B4-646)
 *         * ID_DFR0 - Debug Feature Register (page B4-648)
 *         * ID_AFR0 - Auxiliary Feature Register (page B4-649)
 *         * ID_MMFR0-3 - Memory Model Feature Registers (page B4-650)
 *         * ID_ISAR0-4 - Instruction Set Attribute Registers (page B4-653)
 *         * CLIDR - Cache Level ID Register (page B4-665)
 *         * CTR - Cache Type Register (page B4-667)
 *         * CCSIDR - Cache Size ID Register (page B4-666)
 *         * CSSELR - Cache Size Selection Register (page B4-667)
 *     * B4.2 Processor Feature ID Registers (page B4-646)
 *       - ID_PFR0: State1[7:4]=3 (Thumb-2 support), State0[3:0]=0 (no Arm)
 *       - ID_PFR1: M-profile[11:8]=2 (two-stack model)
 *     * B4.3 Debug Feature ID register (page B4-648)
 *       - ID_DFR0: Debug model M profile[23:20]
 *     * B4.4 Auxiliary Feature ID register (page B4-649)
 *       - ID_AFR0: IMPLEMENTATION DEFINED
 *     * B4.5 Memory Model Feature Registers (page B4-650)
 *       - ID_MMFR0: PMSA support[7:4]=3, TCM support[19:16]
 *       - ID_MMFR2: WFI stall[27:24]
 *     * B4.8 Cache Control Identification Registers (page B4-665)
 *       - CLIDR, CTR, CCSIDR, CSSELR
 *   - Chapter B5: System Instruction Details
 *     * B5.1 About the Armv7-M system instructions (page B5-670)
 *       - CPS, MRS, MSR instructions
 *     * B5.1.1 Special register encodings (page B5-670)
 *       - Table B5-1 Special register field encoding
 *         * APSR=0, IAPSR=1, EAPSR=2, XPSR=3, IPSR=5, EPSR=6, IEPSR=7
 *         * MSP=8, PSP=9
 *         * PRIMASK=16, BASEPRI=17, BASEPRI_MAX=18, FAULTMASK=19, CONTROL=20
 *       - Table B5-2 <bits> encoding on MSR APSR writes
 *         * _nzcvq=0b10, _g=0b01, _nzcvqg=0b11
 *     * B5.2 Armv7-M system instruction descriptions (page B5-672)
 *       - CPS: Change Processor State (page B5-673)
 *       - MRS: Move to Register from Special Register (page B5-675)
 *       - MSR: Move to Special Register from Register (page B5-677)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V7M_SCB_H__
#define __ARCH_ARM_V7M_SCB_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * SCB Base Address
 * System Control Block 基地址
 *
 * Reference: Chapter B3.2 System Control Space (SCS) (page B3-595)
 *   - SCS is located at 0xE000E000-0xE000EFFF
 *   - SCB is a subregion of SCS at 0xE000ED00-0xE000ED8F
 * ============================================================================
 */
#define SCB_BASE_ADDR           0xE000ED00UL

/*
 * ============================================================================
 * SCB Register Addresses (Table B3-4)
 * SCB 寄存器地址
 * ============================================================================
 */

/**
 * @brief CPUID Base Register
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 * Address: 0xE000ED00
 */
#define SCB_CPUID_ADDR          (SCB_BASE_ADDR + 0x00)

/**
 * @brief Interrupt Control and State Register
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 * Address: 0xE000ED04
 */
#define SCB_ICSR_ADDR           (SCB_BASE_ADDR + 0x04)

/**
 * @brief Vector Table Offset Register
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 * Address: 0xE000ED08
 */
#define SCB_VTOR_ADDR           (SCB_BASE_ADDR + 0x08)

/**
 * @brief Application Interrupt and Reset Control Register
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 * Address: 0xE000ED0C
 */
#define SCB_AIRCR_ADDR          (SCB_BASE_ADDR + 0x0C)

/**
 * @brief System Control Register
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 * Address: 0xE000ED10
 */
#define SCB_SCR_ADDR            (SCB_BASE_ADDR + 0x10)

/**
 * @brief Configuration and Control Register
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 * Address: 0xE000ED14
 */
#define SCB_CCR_ADDR            (SCB_BASE_ADDR + 0x14)

/**
 * @brief System Handler Priority Register 1
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 * Address: 0xE000ED18
 */
#define SCB_SHPR1_ADDR          (SCB_BASE_ADDR + 0x18)

/**
 * @brief System Handler Priority Register 2
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 * Address: 0xE000ED1C
 */
#define SCB_SHPR2_ADDR          (SCB_BASE_ADDR + 0x1C)

/**
 * @brief System Handler Priority Register 3
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 * Address: 0xE000ED20
 */
#define SCB_SHPR3_ADDR          (SCB_BASE_ADDR + 0x20)

/**
 * @brief System Handler Control and State Register
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 * Address: 0xE000ED24
 */
#define SCB_SHCSR_ADDR          (SCB_BASE_ADDR + 0x24)

/**
 * @brief Configurable Fault Status Register
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 * Address: 0xE000ED28
 */
#define SCB_CFSR_ADDR           (SCB_BASE_ADDR + 0x28)

/**
 * @brief HardFault Status Register
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 * Address: 0xE000ED2C
 */
#define SCB_HFSR_ADDR           (SCB_BASE_ADDR + 0x2C)

/**
 * @brief Debug Fault Status Register
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 * Address: 0xE000ED30
 */
#define SCB_DFSR_ADDR           (SCB_BASE_ADDR + 0x30)

/**
 * @brief MemManage Fault Address Register
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 * Address: 0xE000ED34
 */
#define SCB_MMFAR_ADDR          (SCB_BASE_ADDR + 0x34)

/**
 * @brief BusFault Address Register
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 * Address: 0xE000ED38
 */
#define SCB_BFAR_ADDR           (SCB_BASE_ADDR + 0x38)

/**
 * @brief Auxiliary Fault Status Register
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 * Address: 0xE000ED3C
 */
#define SCB_AFSR_ADDR           (SCB_BASE_ADDR + 0x3C)

/**
 * @brief Coprocessor Access Control Register
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 * Address: 0xE000ED88
 */
#define SCB_CPACR_ADDR          (SCB_BASE_ADDR + 0x88)

/*
 * ============================================================================
 * SCB Register Access Macros
 * SCB 寄存器访问宏
 * ============================================================================
 */
#define SCB_CPUID               (*(volatile uint32_t *)SCB_CPUID_ADDR)
#define SCB_ICSR                (*(volatile uint32_t *)SCB_ICSR_ADDR)
#define SCB_VTOR                (*(volatile uint32_t *)SCB_VTOR_ADDR)
#define SCB_AIRCR               (*(volatile uint32_t *)SCB_AIRCR_ADDR)
#define SCB_SCR                 (*(volatile uint32_t *)SCB_SCR_ADDR)
#define SCB_CCR                 (*(volatile uint32_t *)SCB_CCR_ADDR)
#define SCB_SHPR1               (*(volatile uint32_t *)SCB_SHPR1_ADDR)
#define SCB_SHPR2               (*(volatile uint32_t *)SCB_SHPR2_ADDR)
#define SCB_SHPR3               (*(volatile uint32_t *)SCB_SHPR3_ADDR)
#define SCB_SHCSR               (*(volatile uint32_t *)SCB_SHCSR_ADDR)
#define SCB_CFSR                (*(volatile uint32_t *)SCB_CFSR_ADDR)
#define SCB_HFSR                (*(volatile uint32_t *)SCB_HFSR_ADDR)
#define SCB_DFSR                (*(volatile uint32_t *)SCB_DFSR_ADDR)
#define SCB_MMFAR               (*(volatile uint32_t *)SCB_MMFAR_ADDR)
#define SCB_BFAR                (*(volatile uint32_t *)SCB_BFAR_ADDR)
#define SCB_AFSR                (*(volatile uint32_t *)SCB_AFSR_ADDR)
#define SCB_CPACR               (*(volatile uint32_t *)SCB_CPACR_ADDR)

/*
 * ============================================================================
 * CPUID Register Bit Definitions (page B3-598)
 * CPUID 寄存器位定义
 * ============================================================================
 */

/**
 * @brief CPUID Implementer field
 * Bits[31:24]: Implementer code (0x41 = ARM)
 */
#define CPUID_IMPLEMENTER_Pos   24U
#define CPUID_IMPLEMENTER_Msk   (0xFFUL << CPUID_IMPLEMENTER_Pos)

/**
 * @brief CPUID Variant field
 * Bits[23:20]: Variant number
 */
#define CPUID_VARIANT_Pos       20U
#define CPUID_VARIANT_Msk       (0x0FUL << CPUID_VARIANT_Pos)

/**
 * @brief CPUID Architecture field
 * Bits[19:16]: Architecture code (0xF = ARMv7-M)
 */
#define CPUID_ARCHITECTURE_Pos  16U
#define CPUID_ARCHITECTURE_Msk  (0x0FUL << CPUID_ARCHITECTURE_Pos)

/**
 * @brief CPUID PartNo field
 * Bits[15:4]: Part number
 */
#define CPUID_PARTNO_Pos        4U
#define CPUID_PARTNO_Msk        (0x0FFFUL << CPUID_PARTNO_Pos)

/**
 * @brief CPUID Revision field
 * Bits[3:0]: Revision number
 */
#define CPUID_REVISION_Pos      0U
#define CPUID_REVISION_Msk      (0x0FUL << CPUID_REVISION_Pos)

/*
 * ============================================================================
 * ICSR Register Bit Definitions (page B3-599)
 * ICSR 寄存器位定义
 * ============================================================================
 */

/**
 * @brief ICSR NMIPENDSET bit
 * Bit[31]: NMI set-pending bit
 */
#define ICSR_NMIPENDSET_Pos     31U
#define ICSR_NMIPENDSET_Msk     (1UL << ICSR_NMIPENDSET_Pos)

/**
 * @brief ICSR PENDSVSET bit
 * Bit[28]: PendSV set-pending bit
 */
#define ICSR_PENDSVSET_Pos      28U
#define ICSR_PENDSVSET_Msk      (1UL << ICSR_PENDSVSET_Pos)

/**
 * @brief ICSR PENDSVCLR bit
 * Bit[27]: PendSV clear-pending bit
 */
#define ICSR_PENDSVCLR_Pos      27U
#define ICSR_PENDSVCLR_Msk      (1UL << ICSR_PENDSVCLR_Pos)

/**
 * @brief ICSR PENDSTSET bit
 * Bit[26]: SysTick exception set-pending bit
 */
#define ICSR_PENDSTSET_Pos      26U
#define ICSR_PENDSTSET_Msk      (1UL << ICSR_PENDSTSET_Pos)

/**
 * @brief ICSR PENDSTCLR bit
 * Bit[25]: SysTick exception clear-pending bit
 */
#define ICSR_PENDSTCLR_Pos      25U
#define ICSR_PENDSTCLR_Msk      (1UL << ICSR_PENDSTCLR_Pos)

/**
 * @brief ICSR ISRPREEMPT bit
 * Bit[23]: Interrupt preempt bit
 */
#define ICSR_ISRPREEMPT_Pos     23U
#define ICSR_ISRPREEMPT_Msk     (1UL << ICSR_ISRPREEMPT_Pos)

/**
 * @brief ICSR ISRPENDING bit
 * Bit[22]: Interrupt pending flag
 */
#define ICSR_ISRPENDING_Pos     22U
#define ICSR_ISRPENDING_Msk     (1UL << ICSR_ISRPENDING_Pos)

/**
 * @brief ICSR VECTPENDING field
 * Bits[20:12]: Pending exception number
 */
#define ICSR_VECTPENDING_Pos    12U
#define ICSR_VECTPENDING_Msk    (0x1FFUL << ICSR_VECTPENDING_Pos)

/**
 * @brief ICSR RETTOBASE bit
 * Bit[11]: Return to base level
 */
#define ICSR_RETTOBASE_Pos      11U
#define ICSR_RETTOBASE_Msk      (1UL << ICSR_RETTOBASE_Pos)

/**
 * @brief ICSR VECTACTIVE field
 * Bits[8:0]: Active exception number
 */
#define ICSR_VECTACTIVE_Pos     0U
#define ICSR_VECTACTIVE_Msk     (0x1FFUL << ICSR_VECTACTIVE_Pos)

/*
 * ============================================================================
 * VTOR Register Bit Definitions (page B3-601)
 * VTOR 寄存器位定义
 * ============================================================================
 */

/**
 * @brief VTOR TBLOFF field
 * Bits[31:7]: Vector table base offset field
 */
#define VTOR_TBLOFF_Pos         7U
#define VTOR_TBLOFF_Msk         (0x1FFFFFFUL << VTOR_TBLOFF_Pos)

/*
 * ============================================================================
 * AIRCR Register Bit Definitions (page B3-601)
 * AIRCR 寄存器位定义
 * ============================================================================
 */

/**
 * @brief AIRCR VECTKEY field
 * Bits[31:16]: Register key
 */
#define AIRCR_VECTKEY_Pos       16U
#define AIRCR_VECTKEY_Msk       (0xFFFFUL << AIRCR_VECTKEY_Pos)
#define AIRCR_VECTKEY_VALUE     0x05FAUL

/**
 * @brief AIRCR ENDIANNESS bit
 * Bit[15]: Data endianness bit
 */
#define AIRCR_ENDIANNESS_Pos    15U
#define AIRCR_ENDIANNESS_Msk    (1UL << AIRCR_ENDIANNESS_Pos)

/**
 * @brief AIRCR PRIGROUP field
 * Bits[10:8]: Interrupt priority grouping field
 */
#define AIRCR_PRIGROUP_Pos      8U
#define AIRCR_PRIGROUP_Msk      (7UL << AIRCR_PRIGROUP_Pos)

/**
 * @brief AIRCR SYSRESETREQ bit
 * Bit[2]: System reset request
 */
#define AIRCR_SYSRESETREQ_Pos   2U
#define AIRCR_SYSRESETREQ_Msk   (1UL << AIRCR_SYSRESETREQ_Pos)

/**
 * @brief AIRCR VECTCLRACTIVE bit
 * Bit[1]: Clear active vector bit
 */
#define AIRCR_VECTCLRACTIVE_Pos 1U
#define AIRCR_VECTCLRACTIVE_Msk (1UL << AIRCR_VECTCLRACTIVE_Pos)

/**
 * @brief AIRCR VECTRESET bit
 * Bit[0]: Vector reset bit
 */
#define AIRCR_VECTRESET_Pos     0U
#define AIRCR_VECTRESET_Msk     (1UL << AIRCR_VECTRESET_Pos)

/*
 * ============================================================================
 * SCR Register Bit Definitions (page B3-603)
 * SCR 寄存器位定义
 * ============================================================================
 */

/**
 * @brief SCR SEVONPEND bit
 * Bit[4]: Send Event on Pending bit
 */
#define SCR_SEVONPEND_Pos       4U
#define SCR_SEVONPEND_Msk       (1UL << SCR_SEVONPEND_Pos)

/**
 * @brief SCR SLEEPDEEP bit
 * Bit[2]: Deep sleep mode enable
 */
#define SCR_SLEEPDEEP_Pos       2U
#define SCR_SLEEPDEEP_Msk       (1UL << SCR_SLEEPDEEP_Pos)

/**
 * @brief SCR SLEEPONEXIT bit
 * Bit[1]: Sleep-on-exit when returning from Handler mode
 */
#define SCR_SLEEPONEXIT_Pos     1U
#define SCR_SLEEPONEXIT_Msk     (1UL << SCR_SLEEPONEXIT_Pos)

/*
 * ============================================================================
 * CCR Register Bit Definitions (page B3-604)
 * CCR 寄存器位定义
 * ============================================================================
 */

/**
 * @brief CCR STKALIGN bit
 * Bit[9]: Stack alignment on exception entry
 */
#define CCR_STKALIGN_Pos        9U
#define CCR_STKALIGN_Msk        (1UL << CCR_STKALIGN_Pos)

/**
 * @brief CCR BFHFNMIGN bit
 * Bit[8]: BusFault hardens NMI and Fault
 */
#define CCR_BFHFNMIGN_Pos       8U
#define CCR_BFHFNMIGN_Msk       (1UL << CCR_BFHFNMIGN_Pos)

/**
 * @brief CCR DIV_0_TRP bit
 * Bit[4]: Trap on divide by 0
 */
#define CCR_DIV_0_TRP_Pos       4U
#define CCR_DIV_0_TRP_Msk       (1UL << CCR_DIV_0_TRP_Pos)

/**
 * @brief CCR UNALIGN_TRP bit
 * Bit[3]: Trap on unaligned access
 */
#define CCR_UNALIGN_TRP_Pos     3U
#define CCR_UNALIGN_TRP_Msk     (1UL << CCR_UNALIGN_TRP_Pos)

/**
 * @brief CCR USERSETMPEND bit
 * Bit[1]: User set Main Pend
 */
#define CCR_USERSETMPEND_Pos    1U
#define CCR_USERSETMPEND_Msk    (1UL << CCR_USERSETMPEND_Pos)

/**
 * @brief CCR NONBASETHRDENA bit
 * Bit[0]: Thread mode can be entered from any level
 */
#define CCR_NONBASETHRDENA_Pos  0U
#define CCR_NONBASETHRDENA_Msk  (1UL << CCR_NONBASETHRDENA_Pos)

/*
 * ============================================================================
 * SHCSR Register Bit Definitions (page B3-607)
 * SHCSR 寄存器位定义
 * ============================================================================
 */

/**
 * @brief SHCSR USGFAULTENA bit
 * Bit[18]: UsageFault enable
 */
#define SHCSR_USGFAULTENA_Pos   18U
#define SHCSR_USGFAULTENA_Msk   (1UL << SHCSR_USGFAULTENA_Pos)

/**
 * @brief SHCSR BUSFAULTENA bit
 * Bit[17]: BusFault enable
 */
#define SHCSR_BUSFAULTENA_Pos   17U
#define SHCSR_BUSFAULTENA_Msk   (1UL << SHCSR_BUSFAULTENA_Pos)

/**
 * @brief SHCSR MEMFAULTENA bit
 * Bit[16]: MemManage enable
 */
#define SHCSR_MEMFAULTENA_Pos   16U
#define SHCSR_MEMFAULTENA_Msk   (1UL << SHCSR_MEMFAULTENA_Pos)

/**
 * @brief SHCSR SVCALLPENDED bit
 * Bit[15]: SVC call pending
 */
#define SHCSR_SVCALLPENDED_Pos  15U
#define SHCSR_SVCALLPENDED_Msk  (1UL << SHCSR_SVCALLPENDED_Pos)

/**
 * @brief SHCSR BUSFAULTPENDED bit
 * Bit[14]: BusFault pending
 */
#define SHCSR_BUSFAULTPENDED_Pos 14U
#define SHCSR_BUSFAULTPENDED_Msk (1UL << SHCSR_BUSFAULTPENDED_Pos)

/**
 * @brief SHCSR MEMFAULTPENDED bit
 * Bit[13]: MemManage pending
 */
#define SHCSR_MEMFAULTPENDED_Pos 13U
#define SHCSR_MEMFAULTPENDED_Msk (1UL << SHCSR_MEMFAULTPENDED_Pos)

/**
 * @brief SHCSR USGFAULTPENDED bit
 * Bit[12]: UsageFault pending
 */
#define SHCSR_USGFAULTPENDED_Pos 12U
#define SHCSR_USGFAULTPENDED_Msk (1UL << SHCSR_USGFAULTPENDED_Pos)

/**
 * @brief SHCSR SYSTICKACT bit
 * Bit[11]: SysTick active
 */
#define SHCSR_SYSTICKACT_Pos    11U
#define SHCSR_SYSTICKACT_Msk    (1UL << SHCSR_SYSTICKACT_Pos)

/**
 * @brief SHCSR PENDSVACT bit
 * Bit[10]: PendSV active
 */
#define SHCSR_PENDSVACT_Pos     10U
#define SHCSR_PENDSVACT_Msk     (1UL << SHCSR_PENDSVACT_Pos)

/**
 * @brief SHCSR MONITORACT bit
 * Bit[8]: Monitor active
 */
#define SHCSR_MONITORACT_Pos    8U
#define SHCSR_MONITORACT_Msk    (1UL << SHCSR_MONITORACT_Pos)

/**
 * @brief SHCSR SVCALLACT bit
 * Bit[7]: SVC call active
 */
#define SHCSR_SVCALLACT_Pos     7U
#define SHCSR_SVCALLACT_Msk     (1UL << SHCSR_SVCALLACT_Pos)

/**
 * @brief SHCSR USGFAULTACT bit
 * Bit[3]: UsageFault active
 */
#define SHCSR_USGFAULTACT_Pos   3U
#define SHCSR_USGFAULTACT_Msk   (1UL << SHCSR_USGFAULTACT_Pos)

/**
 * @brief SHCSR BUSFAULTACT bit
 * Bit[1]: BusFault active
 */
#define SHCSR_BUSFAULTACT_Pos   1U
#define SHCSR_BUSFAULTACT_Msk   (1UL << SHCSR_BUSFAULTACT_Pos)

/**
 * @brief SHCSR MEMFAULTACT bit
 * Bit[0]: MemManage active
 */
#define SHCSR_MEMFAULTACT_Pos   0U
#define SHCSR_MEMFAULTACT_Msk   (1UL << SHCSR_MEMFAULTACT_Pos)

/*
 * ============================================================================
 * CFSR Register Bit Definitions (page B3-609)
 * CFSR 寄存器位定义
 * ============================================================================
 */

/**
 * @brief CFSR subregisters
 * CFSR is a 32-bit register composed of three subregisters:
 * - MMFSR (MemManage Fault Status Register) at bits[7:0]
 * - BFSR (BusFault Status Register) at bits[15:8]
 * - UFSR (UsageFault Status Register) at bits[31:16]
 */
#define CFSR_MMFSR_ADDR         SCB_CFSR_ADDR
#define CFSR_BFSR_ADDR          (SCB_CFSR_ADDR + 1)
#define CFSR_UFSR_ADDR          (SCB_CFSR_ADDR + 2)

#define CFSR_MMFSR              (*(volatile uint8_t *)CFSR_MMFSR_ADDR)
#define CFSR_BFSR               (*(volatile uint8_t *)CFSR_BFSR_ADDR)
#define CFSR_UFSR               (*(volatile uint16_t *)CFSR_UFSR_ADDR)

/* MMFSR bits */
#define MMFSR_MMARVALID_Pos     7U
#define MMFSR_MMARVALID_Msk     (1U << MMFSR_MMARVALID_Pos)
#define MMFSR_MLSPERR_Pos       5U
#define MMFSR_MLSPERR_Msk       (1U << MMFSR_MLSPERR_Pos)
#define MMFSR_MSTKERR_Pos       4U
#define MMFSR_MSTKERR_Msk       (1U << MMFSR_MSTKERR_Pos)
#define MMFSR_MUNSTKERR_Pos     3U
#define MMFSR_MUNSTKERR_Msk     (1U << MMFSR_MUNSTKERR_Pos)
#define MMFSR_DACCVIOL_Pos      1U
#define MMFSR_DACCVIOL_Msk      (1U << MMFSR_DACCVIOL_Pos)
#define MMFSR_IACCVIOL_Pos      0U
#define MMFSR_IACCVIOL_Msk      (1U << MMFSR_IACCVIOL_Pos)

/* BFSR bits */
#define BFSR_BFARVALID_Pos      7U
#define BFSR_BFARVALID_Msk      (1U << BFSR_BFARVALID_Pos)
#define BFSR_LSPERR_Pos         5U
#define BFSR_LSPERR_Msk         (1U << BFSR_LSPERR_Pos)
#define BFSR_STKERR_Pos         4U
#define BFSR_STKERR_Msk         (1U << BFSR_STKERR_Pos)
#define BFSR_UNSTKERR_Pos       3U
#define BFSR_UNSTKERR_Msk       (1U << BFSR_UNSTKERR_Pos)
#define BFSR_IMPRECISERR_Pos    2U
#define BFSR_IMPRECISERR_Msk    (1U << BFSR_IMPRECISERR_Pos)
#define BFSR_PRECISERR_Pos      1U
#define BFSR_PRECISERR_Msk      (1U << BFSR_PRECISERR_Pos)
#define BFSR_IBUSERR_Pos        0U
#define BFSR_IBUSERR_Msk        (1U << BFSR_IBUSERR_Pos)

/* UFSR bits */
#define UFSR_DIVBYZERO_Pos      9U
#define UFSR_DIVBYZERO_Msk      (1U << UFSR_DIVBYZERO_Pos)
#define UFSR_UNALIGNED_Pos      8U
#define UFSR_UNALIGNED_Msk      (1U << UFSR_UNALIGNED_Pos)
#define UFSR_NOCP_Pos           3U
#define UFSR_NOCP_Msk           (1U << UFSR_NOCP_Pos)
#define UFSR_INVPC_Pos          2U
#define UFSR_INVPC_Msk          (1U << UFSR_INVPC_Pos)
#define UFSR_INVSTATE_Pos       1U
#define UFSR_INVSTATE_Msk       (1U << UFSR_INVSTATE_Pos)
#define UFSR_UNDEFINSTR_Pos     0U
#define UFSR_UNDEFINSTR_Msk     (1U << UFSR_UNDEFINSTR_Pos)

/*
 * ============================================================================
 * HFSR Register Bit Definitions (page B3-612)
 * HFSR 寄存器位定义
 * ============================================================================
 */

/**
 * @brief HFSR DEBUGEVT bit
 * Bit[31]: Debug event
 */
#define HFSR_DEBUGEVT_Pos       31U
#define HFSR_DEBUGEVT_Msk       (1UL << HFSR_DEBUGEVT_Pos)

/**
 * @brief HFSR FORCED bit
 * Bit[30]: Forced HardFault
 */
#define HFSR_FORCED_Pos         30U
#define HFSR_FORCED_Msk         (1UL << HFSR_FORCED_Pos)

/**
 * @brief HFSR VECTTBL bit
 * Bit[1]: Vector table read fault
 */
#define HFSR_VECTTBL_Pos        1U
#define HFSR_VECTTBL_Msk        (1UL << HFSR_VECTTBL_Pos)

/*
 * ============================================================================
 * DFSR Register Bit Definitions (page C1-699)
 * DFSR 寄存器位定义
 * ============================================================================
 */

/**
 * @brief DFSR EXTERNAL bit
 * Bit[4]: External debug request
 */
#define DFSR_EXTERNAL_Pos       4U
#define DFSR_EXTERNAL_Msk       (1UL << DFSR_EXTERNAL_Pos)

/**
 * @brief DFSR VCATCH bit
 * Bit[3]: Vector catch
 */
#define DFSR_VCATCH_Pos         3U
#define DFSR_VCATCH_Msk         (1UL << DFSR_VCATCH_Pos)

/**
 * @brief DFSR DWTTRAP bit
 * Bit[2]: DWT match
 */
#define DFSR_DWTTRAP_Pos        2U
#define DFSR_DWTTRAP_Msk        (1UL << DFSR_DWTTRAP_Pos)

/**
 * @brief DFSR BKPT bit
 * Bit[1]: Breakpoint instruction
 */
#define DFSR_BKPT_Pos           1U
#define DFSR_BKPT_Msk           (1UL << DFSR_BKPT_Pos)

/**
 * @brief DFSR HALTED bit
 * Bit[0]: Halt request
 */
#define DFSR_HALTED_Pos         0U
#define DFSR_HALTED_Msk         (1UL << DFSR_HALTED_Pos)

/*
 * ============================================================================
 * CPACR Register Bit Definitions (page B3-614)
 * CPACR 寄存器位定义
 * ============================================================================
 */

/**
 * @brief CPACR CP11 access privileges
 * Bits[23:22]: CP11 coprocessor access
 */
#define CPACR_CP11_Pos          22U
#define CPACR_CP11_Msk          (3UL << CPACR_CP11_Pos)

/**
 * @brief CPACR CP10 access privileges
 * Bits[21:20]: CP10 coprocessor access
 */
#define CPACR_CP10_Pos          20U
#define CPACR_CP10_Msk          (3UL << CPACR_CP10_Pos)

/**
 * @brief CPACR access values
 */
#define CPACR_ACCESS_DENIED     0x0U
#define CPACR_ACCESS_PRIV       0x1U
#define CPACR_ACCESS_RESERVED   0x2U
#define CPACR_ACCESS_FULL       0x3U

/*
 * ============================================================================
 * CPUID Feature Registers (Chapter B4)
 * CPUID 特性寄存器 (B4章节)
 * ============================================================================
 */

/*
 * ============================================================================
 * ID_PFR0 - Processor Feature Register 0 (page B4-646)
 * ============================================================================
 */
#define SCB_ID_PFR0_ADDR        (SCB_BASE_ADDR + 0x40)
#define SCB_ID_PFR0             (*(volatile uint32_t *)SCB_ID_PFR0_ADDR)

/**
 * @brief ID_PFR0 State1 field
 * Bits[7:4]: Thumb instruction set support
 * 0x3 = Processor supports Thumb encoding including Thumb-2 technology,
 *       with all basic 16-bit and 32-bit instructions
 */
#define ID_PFR0_STATE1_Pos      4U
#define ID_PFR0_STATE1_Msk      (0x0FUL << ID_PFR0_STATE1_Pos)
#define ID_PFR0_STATE1_THUMB2   0x3U

/**
 * @brief ID_PFR0 State0 field
 * Bits[3:0]: Arm instruction set support
 * 0x0 = Processor does not support the Arm instruction set
 */
#define ID_PFR0_STATE0_Pos      0U
#define ID_PFR0_STATE0_Msk      (0x0FUL << ID_PFR0_STATE0_Pos)

/*
 * ============================================================================
 * ID_PFR1 - Processor Feature Register 1 (page B4-646)
 * ============================================================================
 */
#define SCB_ID_PFR1_ADDR        (SCB_BASE_ADDR + 0x44)
#define SCB_ID_PFR1             (*(volatile uint32_t *)SCB_ID_PFR1_ADDR)

/**
 * @brief ID_PFR1 M-profile programmers' model field
 * Bits[11:8]: M-profile programmers' model support
 * 0x2 = Support for two-stack programmers' model
 */
#define ID_PFR1_MPROFILE_Pos    8U
#define ID_PFR1_MPROFILE_Msk    (0x0FUL << ID_PFR1_MPROFILE_Pos)
#define ID_PFR1_MPROFILE_TWO_STACK 0x2U

/*
 * ============================================================================
 * ID_DFR0 - Debug Feature Register 0 (page B4-648)
 * ============================================================================
 */
#define SCB_ID_DFR0_ADDR        (SCB_BASE_ADDR + 0x48)
#define SCB_ID_DFR0             (*(volatile uint32_t *)SCB_ID_DFR0_ADDR)

/**
 * @brief ID_DFR0 Debug model M profile field
 * Bits[23:20]: Debug model, M profile
 * 0x0 = Not supported
 * 0x1 = Support for M profile Debug architecture, with memory-mapped access
 */
#define ID_DFR0_MPROFILEDBG_Pos 20U
#define ID_DFR0_MPROFILEDBG_Msk (0x0FUL << ID_DFR0_MPROFILEDBG_Pos)

/*
 * ============================================================================
 * ID_AFR0 - Auxiliary Feature Register 0 (page B4-649)
 * ============================================================================
 */
#define SCB_ID_AFR0_ADDR        (SCB_BASE_ADDR + 0x4C)
#define SCB_ID_AFR0             (*(volatile uint32_t *)SCB_ID_AFR0_ADDR)

/*
 * ============================================================================
 * ID_MMFR0 - Memory Model Feature Register 0 (page B4-650)
 * ============================================================================
 */
#define SCB_ID_MMFR0_ADDR       (SCB_BASE_ADDR + 0x50)
#define SCB_ID_MMFR0            (*(volatile uint32_t *)SCB_ID_MMFR0_ADDR)

/**
 * @brief ID_MMFR0 PMSA support field
 * Bits[7:4]: PMSA support
 * 0x3 = PMSAv7, providing support for a protected memory system architecture
 */
#define ID_MMFR0_PMSA_Pos       4U
#define ID_MMFR0_PMSA_Msk       (0x0FUL << ID_MMFR0_PMSA_Pos)
#define ID_MMFR0_PMSA_V7        0x3U

/**
 * @brief ID_MMFR0 TCM support field
 * Bits[19:16]: TCM support
 */
#define ID_MMFR0_TCM_Pos        16U
#define ID_MMFR0_TCM_Msk        (0x0FUL << ID_MMFR0_TCM_Pos)

/*
 * ============================================================================
 * ID_MMFR1 - Memory Model Feature Register 1 (page B4-652)
 * ============================================================================
 */
#define SCB_ID_MMFR1_ADDR       (SCB_BASE_ADDR + 0x54)
#define SCB_ID_MMFR1            (*(volatile uint32_t *)SCB_ID_MMFR1_ADDR)

/*
 * ============================================================================
 * ID_MMFR2 - Memory Model Feature Register 2 (page B4-652)
 * ============================================================================
 */
#define SCB_ID_MMFR2_ADDR       (SCB_BASE_ADDR + 0x58)
#define SCB_ID_MMFR2            (*(volatile uint32_t *)SCB_ID_MMFR2_ADDR)

/**
 * @brief ID_MMFR2 WFI stall field
 * Bits[27:24]: WFI stall support
 */
#define ID_MMFR2_WFISTALL_Pos   24U
#define ID_MMFR2_WFISTALL_Msk   (0x0FUL << ID_MMFR2_WFISTALL_Pos)

/*
 * ============================================================================
 * ID_MMFR3 - Memory Model Feature Register 3 (page B4-653)
 * ============================================================================
 */
#define SCB_ID_MMFR3_ADDR       (SCB_BASE_ADDR + 0x5C)
#define SCB_ID_MMFR3            (*(volatile uint32_t *)SCB_ID_MMFR3_ADDR)

/*
 * ============================================================================
 * ID_ISAR0-4 - Instruction Set Attribute Registers (page B4-653)
 * ============================================================================
 */
#define SCB_ID_ISAR0_ADDR       (SCB_BASE_ADDR + 0x60)
#define SCB_ID_ISAR1_ADDR       (SCB_BASE_ADDR + 0x64)
#define SCB_ID_ISAR2_ADDR       (SCB_BASE_ADDR + 0x68)
#define SCB_ID_ISAR3_ADDR       (SCB_BASE_ADDR + 0x6C)
#define SCB_ID_ISAR4_ADDR       (SCB_BASE_ADDR + 0x70)

#define SCB_ID_ISAR0            (*(volatile uint32_t *)SCB_ID_ISAR0_ADDR)
#define SCB_ID_ISAR1            (*(volatile uint32_t *)SCB_ID_ISAR1_ADDR)
#define SCB_ID_ISAR2            (*(volatile uint32_t *)SCB_ID_ISAR2_ADDR)
#define SCB_ID_ISAR3            (*(volatile uint32_t *)SCB_ID_ISAR3_ADDR)
#define SCB_ID_ISAR4            (*(volatile uint32_t *)SCB_ID_ISAR4_ADDR)

/*
 * ============================================================================
 * Cache Control Identification Registers (page B4-665)
 * 缓存控制识别寄存器
 * ============================================================================
 */

/**
 * @brief CLIDR - Cache Level ID Register
 * Address: 0xE000ED78
 */
#define SCB_CLIDR_ADDR          (SCB_BASE_ADDR + 0x78)
#define SCB_CLIDR               (*(volatile uint32_t *)SCB_CLIDR_ADDR)

/**
 * @brief CTR - Cache Type Register
 * Address: 0xE000ED7C
 */
#define SCB_CTR_ADDR            (SCB_BASE_ADDR + 0x7C)
#define SCB_CTR                 (*(volatile uint32_t *)SCB_CTR_ADDR)

/**
 * @brief CCSIDR - Cache Size ID Register
 * Address: 0xE000ED80
 */
#define SCB_CCSIDR_ADDR         (SCB_BASE_ADDR + 0x80)
#define SCB_CCSIDR              (*(volatile uint32_t *)SCB_CCSIDR_ADDR)

/**
 * @brief CSSELR - Cache Size Selection Register
 * Address: 0xE000ED84
 */
#define SCB_CSSELR_ADDR         (SCB_BASE_ADDR + 0x84)
#define SCB_CSSELR              (*(volatile uint32_t *)SCB_CSSELR_ADDR)

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Get CPUID register value
 * @return CPUID value
 *
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 *   - CPUID Base Register identifies the processor
 */
uint32_t scb_get_cpuid(void);

/**
 * @brief Get implementer code from CPUID
 * @return Implementer code (0x41 = ARM)
 */
uint8_t scb_get_implementer(void);

/**
 * @brief Get variant number from CPUID
 * @return Variant number
 */
uint8_t scb_get_variant(void);

/**
 * @brief Get architecture code from CPUID
 * @return Architecture code (0xF = ARMv7-M)
 */
uint8_t scb_get_architecture(void);

/**
 * @brief Get part number from CPUID
 * @return Part number
 */
uint16_t scb_get_partno(void);

/**
 * @brief Get revision number from CPUID
 * @return Revision number
 */
uint8_t scb_get_revision(void);

/**
 * @brief Set vector table offset
 * @param offset Vector table base offset (must be aligned to 256 bytes)
 *
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 *   - VTOR sets the vector table base address
 */
void scb_set_vtor(uint32_t offset);

/**
 * @brief Get vector table offset
 * @return Current vector table offset
 */
uint32_t scb_get_vtor(void);

/**
 * @brief Request system reset
 *
 * Reference: Chapter B3.2.2, Table B3-4 (page B3-596)
 *   - AIRCR.SYSRESETREQ requests a system reset
 */
void scb_system_reset(void);

/**
 * @brief Set priority grouping
 * @param group Priority grouping value (0-7)
 *
 * Reference: Chapter B1.5.4 Priority grouping (page B1-527)
 */
void scb_set_priority_grouping(uint32_t group);

/**
 * @brief Get priority grouping
 * @return Current priority grouping value
 */
uint32_t scb_get_priority_grouping(void);

/**
 * @brief Enable UsageFault
 */
void scb_enable_usage_fault(void);

/**
 * @brief Disable UsageFault
 */
void scb_disable_usage_fault(void);

/**
 * @brief Enable BusFault
 */
void scb_enable_bus_fault(void);

/**
 * @brief Disable BusFault
 */
void scb_disable_bus_fault(void);

/**
 * @brief Enable MemManage
 */
void scb_enable_memmanage(void);

/**
 * @brief Disable MemManage
 */
void scb_disable_memmanage(void);

/**
 * @brief Get active exception number
 * @return Active exception number (0 = Thread mode)
 *
 * Reference: Chapter B1.4.2 The IPSR (page B1-516)
 */
uint32_t scb_get_active_exception(void);

/**
 * @brief Get pending exception number
 * @return Pending exception number (0 = no pending exception)
 */
uint32_t scb_get_pending_exception(void);

/**
 * @brief Check if in Handler mode
 * @return 1 if in Handler mode, 0 if in Thread mode
 */
int scb_in_handler_mode(void);

/**
 * @brief Get the number of implemented priority bits
 * @return Number of priority bits (3-8)
 */
uint32_t scb_get_priority_bits(void);

/**
 * @brief Clear all fault status registers
 */
void scb_clear_fault_status(void);

/**
 * @brief Get MemManage fault address
 * @return MemManage fault address (valid only if MMARVALID is set)
 */
uint32_t scb_get_mmfar(void);

/**
 * @brief Get BusFault address
 * @return BusFault address (valid only if BFARVALID is set)
 */
uint32_t scb_get_bfar(void);

/**
 * @brief Check if MMFAR is valid
 * @return 1 if valid, 0 if not valid
 */
int scb_mmfar_valid(void);

/**
 * @brief Check if BFAR is valid
 * @return 1 if valid, 0 if not valid
 */
int scb_bfar_valid(void);

/**
 * @brief Trigger a PendSV exception
 */
void scb_trigger_pendsv(void);

/**
 * @brief Clear PendSV pending status
 */
void scb_clear_pendsv(void);

/**
 * @brief Trigger a SysTick exception
 */
void scb_trigger_systick(void);

/**
 * @brief Clear SysTick pending status
 */
void scb_clear_systick(void);

/**
 * @brief Check if there are any pending interrupts
 * @return 1 if pending interrupts exist, 0 otherwise
 */
int scb_interrupt_pending(void);

/**
 * @brief Check if returning to base level (no preempted exceptions)
 * @return 1 if returning to base, 0 otherwise
 */
int scb_return_to_base(void);

/*
 * ============================================================================
 * CPUID Feature Register Functions (Chapter B4)
 * CPUID 特性寄存器函数 (B4章节)
 * ============================================================================
 */

/**
 * @brief Get ID_PFR0 register value
 * @return ID_PFR0 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 */
uint32_t scb_get_id_pfr0(void);

/**
 * @brief Get ID_PFR1 register value
 * @return ID_PFR1 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 */
uint32_t scb_get_id_pfr1(void);

/**
 * @brief Check if processor supports Thumb-2
 * @return 1 if supported, 0 otherwise
 *
 * Reference: Chapter B4.2.1 ID_PFR0 (page B4-646)
 */
int scb_has_thumb2_support(void);

/**
 * @brief Check if processor supports two-stack model
 * @return 1 if supported, 0 otherwise
 *
 * Reference: Chapter B4.2.2 ID_PFR1 (page B4-646)
 */
int scb_has_two_stack_support(void);

/**
 * @brief Get ID_DFR0 register value
 * @return ID_DFR0 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 */
uint32_t scb_get_id_dfr0(void);

/**
 * @brief Get ID_AFR0 register value
 * @return ID_AFR0 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 */
uint32_t scb_get_id_afr0(void);

/**
 * @brief Get ID_MMFR0 register value
 * @return ID_MMFR0 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 */
uint32_t scb_get_id_mmfr0(void);

/**
 * @brief Check if processor supports PMSAv7
 * @return 1 if supported, 0 otherwise
 *
 * Reference: Chapter B4.5.1 ID_MMFR0 (page B4-650)
 */
int scb_has_pmsa_v7(void);

/**
 * @brief Get ID_MMFR1 register value
 * @return ID_MMFR1 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 */
uint32_t scb_get_id_mmfr1(void);

/**
 * @brief Get ID_MMFR2 register value
 * @return ID_MMFR2 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 */
uint32_t scb_get_id_mmfr2(void);

/**
 * @brief Get ID_MMFR3 register value
 * @return ID_MMFR3 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 */
uint32_t scb_get_id_mmfr3(void);

/**
 * @brief Get ID_ISAR0 register value
 * @return ID_ISAR0 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 */
uint32_t scb_get_id_isar0(void);

/**
 * @brief Get ID_ISAR1 register value
 * @return ID_ISAR1 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 */
uint32_t scb_get_id_isar1(void);

/**
 * @brief Get ID_ISAR2 register value
 * @return ID_ISAR2 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 */
uint32_t scb_get_id_isar2(void);

/**
 * @brief Get ID_ISAR3 register value
 * @return ID_ISAR3 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 */
uint32_t scb_get_id_isar3(void);

/**
 * @brief Get ID_ISAR4 register value
 * @return ID_ISAR4 value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 */
uint32_t scb_get_id_isar4(void);

/**
 * @brief Get CLIDR register value
 * @return CLIDR value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 */
uint32_t scb_get_clidr(void);

/**
 * @brief Get CTR register value
 * @return CTR value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 */
uint32_t scb_get_ctr(void);

/**
 * @brief Get CCSIDR register value
 * @return CCSIDR value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 */
uint32_t scb_get_ccsidr(void);

/**
 * @brief Get CSSELR register value
 * @return CSSELR value
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 */
uint32_t scb_get_csselr(void);

/**
 * @brief Set CSSELR register value
 * @param value Value to write
 *
 * Reference: Chapter B4.1.2, Table B4-1 (page B4-644)
 */
void scb_set_csselr(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V7M_SCB_H__ */
