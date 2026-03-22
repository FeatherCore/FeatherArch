/*
 * ARM Cortex-M33 Core Peripheral Access Layer
 * ARM Cortex-M33 核心外设访问层
 *
 * ============================================================================
 * File: core_cm33.h
 * Description: ARM Cortex-M33 core peripheral access layer definitions
 * 描述: ARM Cortex-M33 核心外设访问层定义
 *
 * This file defines all NVIC, SysTick, SCB, FPU, MPU, TrustZone functions for ARM Cortex-M33.
 * 本文件定义了 ARM Cortex-M33 的所有 NVIC、SysTick、SCB、FPU、MPU、TrustZone 函数。
 *
 * Reference Documents / 参考文档:
 *   1. ARMv8-M Architecture Reference Manual (ARM DDI 0553B)
 *      - Chapter B2: Programmer's Model (Special Registers)
 *      - Chapter B3: System Control Registers
 *      - Chapter B4: Memory Protection Unit (MPU)
 *      - Chapter B5: Security Attribution Unit (SAU)
 *      - Chapter B6: Debug and Trace
 *
 *   2. ARM Cortex-M33 Devices Generic User Guide (DUI 0552A)
 *      - Chapter 4.2: System Control Block (SCB)
 *      - Chapter 4.3: Nested Vectored Interrupt Controller (NVIC)
 *      - Chapter 4.4: System Timer (SysTick)
 *      - Chapter 4.5: Memory Protection Unit (MPU)
 *      - Chapter 5: Floating-Point Unit (FPU)
 *      - Chapter 6: Security Attribution Unit (SAU)
 *      - Chapter 7: Instrumentation Trace Macrocell (ITM)
 *
 *   3. ARM Cortex-M33 Processor Technical Reference Manual (ARM DDI 0550A)
 *      - Chapter 4: Processor Registers
 *      - Chapter 11: Performance Monitor Unit (PMU)
 *
 *   4. ARM Cortex-M33 Processor Datasheet (V2)
 *      - Feature configuration
 *      - Memory map
 *
 * Note:
 *   This file depends on armv8m.h for architecture abstraction.
 *   本文件依赖于 armv8m.h 提供架构抽象层。
 *
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 ARM Architecture Team. All rights reserved.
 */

#ifndef __CORE_CM33_H_GENERIC
#define __CORE_CM33_H_GENERIC

#include "armv8m.h"
#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif

/*
 * ============================================================================
 * CMSIS Defines
 * ============================================================================
 */

#define __CM33_REV                 0x0000U
#define __MPU_PRESENT             1U
#define __VTOR_PRESENT            1U
#define __NVIC_PRIO_BITS          3U
#define __Vendor_SysTickConfig    0U
#define __FPU_PRESENT             1U
#define __FPU_DP                 0U
#define __MPU_PRESENT             1U
#define __PMU_PRESENT             1U

/*
 * ============================================================================
 * Interrupt Number Definition
 * ============================================================================
 */

typedef enum {
    NonMaskableInt_IRQn         = -14,
    HardFault_IRQn              = -13,
    MemoryManagement_IRQn       = -12,
    BusFault_IRQn               = -11,
    UsageFault_IRQn             = -10,
    SecureFault_IRQn            = -9,
    SVCall_IRQn                 = -5,
    DebugMonitor_IRQn           = -4,
    PendSV_IRQn                 = -2,
    SysTick_IRQn                = -1,
    IRQ0_IRQn                   = 0,
    IRQ1_IRQn                   = 1,
    IRQ2_IRQn                   = 2,
    IRQ3_IRQn                   = 3,
    IRQ4_IRQn                   = 4,
    IRQ5_IRQn                   = 5,
    IRQ6_IRQn                   = 6,
    IRQ7_IRQn                   = 7,
    IRQ8_IRQn                   = 8,
    IRQ9_IRQn                   = 9,
    IRQ10_IRQn                  = 10,
    IRQ11_IRQn                  = 11,
    IRQ12_IRQn                  = 12,
    IRQ13_IRQn                  = 13,
    IRQ14_IRQn                  = 14,
    IRQ15_IRQn                  = 15,
    IRQ16_IRQn                  = 16,
    IRQ17_IRQn                  = 17,
    IRQ18_IRQn                  = 18,
    IRQ19_IRQn                  = 19,
    IRQ20_IRQn                  = 20,
    IRQ21_IRQn                  = 21,
    IRQ22_IRQn                  = 22,
    IRQ23_IRQn                  = 23,
    IRQ24_IRQn                  = 24,
    IRQ25_IRQn                  = 25,
    IRQ26_IRQn                  = 26,
    IRQ27_IRQn                  = 27,
    IRQ28_IRQn                  = 28,
    IRQ29_IRQn                  = 29,
    IRQ30_IRQn                  = 30,
    IRQ31_IRQn                  = 31,
    IRQ32_IRQn                  = 32,
    IRQ33_IRQn                  = 33,
    IRQ34_IRQn                  = 34,
    IRQ35_IRQn                  = 35,
    IRQ36_IRQn                  = 36,
    IRQ37_IRQn                  = 37,
    IRQ38_IRQn                  = 38,
    IRQ39_IRQn                  = 39,
    IRQ40_IRQn                  = 40,
    IRQ41_IRQn                  = 41,
    IRQ42_IRQn                  = 42,
    IRQ43_IRQn                  = 43,
    IRQ44_IRQn                  = 44,
    IRQ45_IRQn                  = 45,
    IRQ46_IRQn                  = 46,
    IRQ47_IRQn                  = 47,
    IRQ48_IRQn                  = 48,
    IRQ49_IRQn                  = 49,
    IRQ50_IRQn                  = 50,
    IRQ51_IRQn                  = 51,
    IRQ52_IRQn                  = 52,
    IRQ53_IRQn                  = 53,
    IRQ54_IRQn                  = 54,
    IRQ55_IRQn                  = 55,
    IRQ56_IRQn                  = 56,
    IRQ57_IRQn                  = 57,
    IRQ58_IRQn                  = 58,
    IRQ59_IRQn                  = 59,
    IRQ60_IRQn                  = 60,
    IRQ61_IRQn                  = 61,
    IRQ62_IRQn                  = 62,
    IRQ63_IRQn                  = 63,
    IRQ64_IRQn                  = 64,
    IRQ65_IRQn                  = 65,
    IRQ66_IRQn                  = 66,
    IRQ67_IRQn                  = 67,
    IRQ68_IRQn                  = 68,
    IRQ69_IRQn                  = 69,
    IRQ70_IRQn                  = 70,
    IRQ71_IRQn                  = 71,
    IRQ72_IRQn                  = 72,
    IRQ73_IRQn                  = 73,
    IRQ74_IRQn                  = 74,
    IRQ75_IRQn                  = 75,
    IRQ76_IRQn                  = 76,
    IRQ77_IRQn                  = 77,
    IRQ78_IRQn                  = 78,
    IRQ79_IRQn                  = 79,
    IRQ80_IRQn                  = 80,
    IRQ81_IRQn                  = 81,
    IRQ82_IRQn                  = 82,
    IRQ83_IRQn                  = 83,
    IRQ84_IRQn                  = 84,
    IRQ85_IRQn                  = 85,
    IRQ86_IRQn                  = 86,
    IRQ87_IRQn                  = 87,
    IRQ88_IRQn                  = 88,
    IRQ89_IRQn                  = 89,
    IRQ90_IRQn                  = 90,
    IRQ91_IRQn                  = 91,
    IRQ92_IRQn                  = 92,
    IRQ93_IRQn                  = 93,
    IRQ94_IRQn                  = 94,
    IRQ95_IRQn                  = 95,
    IRQ96_IRQn                  = 96,
    IRQ97_IRQn                  = 97,
    IRQ98_IRQn                  = 98,
    IRQ99_IRQn                  = 99,
    IRQ100_IRQn                 = 100,
    IRQ101_IRQn                 = 101,
    IRQ102_IRQn                 = 102,
    IRQ103_IRQn                 = 103,
    IRQ104_IRQn                 = 104,
    IRQ105_IRQn                 = 105,
    IRQ106_IRQn                 = 106,
    IRQ107_IRQn                 = 107,
    IRQ108_IRQn                 = 108,
    IRQ109_IRQn                 = 109,
    IRQ110_IRQn                 = 110,
    IRQ111_IRQn                 = 111,
    IRQ112_IRQn                 = 112,
    IRQ113_IRQn                 = 113,
    IRQ114_IRQn                 = 114,
    IRQ115_IRQn                 = 115,
    IRQ116_IRQn                 = 116,
    IRQ117_IRQn                 = 117,
    IRQ118_IRQn                 = 118,
    IRQ119_IRQn                 = 119,
    IRQ120_IRQn                 = 120,
    IRQ121_IRQn                 = 121,
    IRQ122_IRQn                 = 122,
    IRQ123_IRQn                 = 123,
    IRQ124_IRQn                 = 124,
    IRQ125_IRQn                 = 125,
    IRQ126_IRQn                 = 126,
    IRQ127_IRQn                 = 127,
    IRQ128_IRQn                 = 128,
    IRQ129_IRQn                 = 129,
    IRQ130_IRQn                 = 130,
    IRQ131_IRQn                 = 131,
    IRQ132_IRQn                 = 132,
    IRQ133_IRQn                 = 133,
    IRQ134_IRQn                 = 134,
    IRQ135_IRQn                 = 135,
    IRQ136_IRQn                 = 136,
    IRQ137_IRQn                 = 137,
    IRQ138_IRQn                 = 138,
    IRQ139_IRQn                 = 139,
    IRQ140_IRQn                 = 140,
    IRQ141_IRQn                 = 141,
    IRQ142_IRQn                 = 142,
    IRQ143_IRQn                 = 143,
    IRQ144_IRQn                 = 144,
    IRQ145_IRQn                 = 145,
    IRQ146_IRQn                 = 146,
    IRQ147_IRQn                 = 147,
    IRQ148_IRQn                 = 148,
    IRQ149_IRQn                 = 149,
    IRQ150_IRQn                 = 150,
    IRQ151_IRQn                 = 151,
    IRQ152_IRQn                 = 152,
    IRQ153_IRQn                 = 153,
    IRQ154_IRQn                 = 154,
    IRQ155_IRQn                 = 155,
    IRQ156_IRQn                 = 156,
    IRQ157_IRQn                 = 157,
    IRQ158_IRQn                 = 158,
    IRQ159_IRQn                 = 159,
    IRQ160_IRQn                 = 160,
    IRQ161_IRQn                 = 161,
    IRQ162_IRQn                 = 162,
    IRQ163_IRQn                 = 163,
    IRQ164_IRQn                 = 164,
    IRQ165_IRQn                 = 165,
    IRQ166_IRQn                 = 166,
    IRQ167_IRQn                 = 167,
    IRQ168_IRQn                 = 168,
    IRQ169_IRQn                 = 169,
    IRQ170_IRQn                 = 170,
    IRQ171_IRQn                 = 171,
    IRQ172_IRQn                 = 172,
    IRQ173_IRQn                 = 173,
    IRQ174_IRQn                 = 174,
    IRQ175_IRQn                 = 175,
    IRQ176_IRQn                 = 176,
    IRQ177_IRQn                 = 177,
    IRQ178_IRQn                 = 178,
    IRQ179_IRQn                 = 179,
    IRQ180_IRQn                 = 180,
    IRQ181_IRQn                 = 181,
    IRQ182_IRQn                 = 182,
    IRQ183_IRQn                 = 183,
    IRQ184_IRQn                 = 184,
    IRQ185_IRQn                 = 185,
    IRQ186_IRQn                 = 186,
    IRQ187_IRQn                 = 187,
    IRQ188_IRQn                 = 188,
    IRQ189_IRQn                 = 189,
    IRQ190_IRQn                 = 190,
    IRQ191_IRQn                 = 191,
    IRQ192_IRQn                 = 192,
    IRQ193_IRQn                 = 193,
    IRQ194_IRQn                 = 194,
    IRQ195_IRQn                 = 195,
    IRQ196_IRQn                 = 196,
    IRQ197_IRQn                 = 197,
    IRQ198_IRQn                 = 198,
    IRQ199_IRQn                 = 199,
    IRQ200_IRQn                 = 200,
    IRQ201_IRQn                 = 201,
    IRQ202_IRQn                 = 202,
    IRQ203_IRQn                 = 203,
    IRQ204_IRQn                 = 204,
    IRQ205_IRQn                 = 205,
    IRQ206_IRQn                 = 206,
    IRQ207_IRQn                 = 207,
    IRQ208_IRQn                 = 208,
    IRQ209_IRQn                 = 209,
    IRQ210_IRQn                 = 210,
    IRQ211_IRQn                 = 211,
    IRQ212_IRQn                 = 212,
    IRQ213_IRQn                 = 213,
    IRQ214_IRQn                 = 214,
    IRQ215_IRQn                 = 215,
    IRQ216_IRQn                 = 216,
    IRQ217_IRQn                 = 217,
    IRQ218_IRQn                 = 218,
    IRQ219_IRQn                 = 219,
    IRQ220_IRQn                 = 220,
    IRQ221_IRQn                 = 221,
    IRQ222_IRQn                 = 222,
    IRQ223_IRQn                 = 223,
    IRQ224_IRQn                 = 224,
    IRQ225_IRQn                 = 225,
    IRQ226_IRQn                 = 226,
    IRQ227_IRQn                 = 227,
    IRQ228_IRQn                 = 228,
    IRQ229_IRQn                 = 229,
    IRQ230_IRQn                 = 230,
    IRQ231_IRQn                 = 231,
    IRQ232_IRQn                 = 232,
    IRQ233_IRQn                 = 233,
    IRQ234_IRQn                 = 234,
    IRQ235_IRQn                 = 235,
    IRQ236_IRQn                 = 236,
    IRQ237_IRQn                 = 237,
    IRQ238_IRQn                 = 238,
    IRQ239_IRQn                 = 239,
    IRQ240_IRQn                 = 240,
    IRQ241_IRQn                 = 241,
    IRQ242_IRQn                 = 242,
    IRQ243_IRQn                 = 243,
    IRQ244_IRQn                 = 244,
    IRQ245_IRQn                 = 245,
    IRQ246_IRQn                 = 246,
    IRQ247_IRQn                 = 247,
    IRQ248_IRQn                 = 248,
    IRQ249_IRQn                 = 249,
    IRQ250_IRQn                 = 250,
    IRQ251_IRQn                 = 251,
    IRQ252_IRQn                 = 252,
    IRQ253_IRQn                 = 253,
    IRQ254_IRQn                 = 254
} IRQn_Type;

/*
 * ============================================================================
 * NVIC Functions
 * ============================================================================
 */

/**
 * @brief 设置优先级分组
 */
__STATIC_INLINE void __NVIC_SetPriorityGrouping(uint32_t PriorityGroup) {
    uint32_t reg_value;
    uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);

    reg_value  =  SCB->AIRCR;
    reg_value &= ~((uint32_t)((0x07UL << 8U) | (uint32_t)0x07UL));
    reg_value  = (reg_value                                   |
                  ((uint32_t)0x5FAUL << 16U)                  |
                  (PriorityGroupTmp << 8U)                     );
    SCB->AIRCR = reg_value;
}

/**
 * @brief 获取优先级分组
 */
__STATIC_INLINE uint32_t __NVIC_GetPriorityGrouping(void) {
    return ((uint32_t)((SCB->AIRCR >> 8U) & (uint32_t)0x07UL));
}

/**
 * @brief 使能指定中断
 */
__STATIC_INLINE void __NVIC_EnableIRQ(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        NVIC->ISER[tmp] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
    }
}

/**
 * @brief 获取中断使能状态
 */
__STATIC_INLINE uint32_t __NVIC_GetEnableIRQ(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        return((uint32_t)(((NVIC->ISER[tmp] >> (((uint32_t)(int32_t)IRQn) & 0x1FUL)) & 1U)));
    } else {
        return(0U);
    }
}

/**
 * @brief 禁用指定中断
 */
__STATIC_INLINE void __NVIC_DisableIRQ(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        NVIC->ICER[tmp] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
    }
}

/**
 * @brief 获取中断挂起状态
 */
__STATIC_INLINE uint32_t __NVIC_GetPendingIRQ(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        return((uint32_t)(((NVIC->ISPR[tmp] >> (((uint32_t)(int32_t)IRQn) & 0x1FUL)) & 1U)));
    } else {
        return(0U);
    }
}

/**
 * @brief 设置中断挂起状态
 */
__STATIC_INLINE void __NVIC_SetPendingIRQ(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        NVIC->ISPR[tmp] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
    }
}

/**
 * @brief 清除中断挂起状态
 */
__STATIC_INLINE void __NVIC_ClearPendingIRQ(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        NVIC->ICPR[tmp] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
    }
}

/**
 * @brief 获取当前正在执行的中断
 */
__STATIC_INLINE uint32_t __NVIC_GetActive(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        return((uint32_t)(((NVIC->IABR[tmp] >> (((uint32_t)(int32_t)IRQn) & 0x1FUL)) & 1U)));
    } else {
        return(0U);
    }
}

/**
 * @brief 设置中断优先级
 */
__STATIC_INLINE void __NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority) {
    if ((int32_t)(IRQn) >= 0) {
        NVIC->IP[(uint32_t)(IRQn)] =
            (uint8_t)((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL);
    }
}

/**
 * @brief 获取中断优先级
 */
__STATIC_INLINE uint32_t __NVIC_GetPriority(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        return(((uint32_t)(NVIC->IP[(uint32_t)(IRQn)] >> (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL));
    } else {
        return(0U);
    }
}

/**
 * @brief 编码优先级
 */
__STATIC_INLINE uint32_t __NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority) {
    uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);
    uint32_t PreemptPriorityBits;
    uint32_t SubPriorityBits;

    PreemptPriorityBits = ((7UL - PriorityGroupTmp) < (uint32_t)(__NVIC_PRIO_BITS)) ?
                          (uint32_t)(7UL - PriorityGroupTmp) : (uint32_t)(__NVIC_PRIO_BITS);
    SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(__NVIC_PRIO_BITS)) < (uint32_t)7UL) ?
                          (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + __NVIC_PRIO_BITS);

    return (
           ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
           ((SubPriority & (uint32_t)((1UL << (SubPriorityBits)) - 1UL))
          );
}

/**
 * @brief 解码优先级
 */
__STATIC_INLINE void __NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* const pPreemptPriority, uint32_t* const pSubPriority) {
    uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);
    uint32_t PreemptPriorityBits;
    uint32_t SubPriorityBits;

    PreemptPriorityBits = ((7UL - PriorityGroupTmp) < (uint32_t)(__NVIC_PRIO_BITS)) ?
                          (uint32_t)(7UL - PriorityGroupTmp) : (uint32_t)(__NVIC_PRIO_BITS);
    SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(__NVIC_PRIO_BITS)) < (uint32_t)7UL) ?
                          (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + __NVIC_PRIO_BITS);

    *pPreemptPriority = (Priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
    *pSubPriority     = (Priority & (uint32_t)((1UL << (SubPriorityBits)) - 1UL));
}

/**
 * @brief 设置中断向量
 */
__STATIC_INLINE void __NVIC_SetVector(IRQn_Type IRQn, uint32_t vector) {
    uint32_t *vectors = (uint32_t *)SCB->VTOR;
    vectors[(int16_t)IRQn + 16] = vector;
}

/**
 * @brief 获取中断向量
 */
__STATIC_INLINE uint32_t __NVIC_GetVector(IRQn_Type IRQn) {
    uint32_t *vectors = (uint32_t *)SCB->VTOR;
    return vectors[(int16_t)IRQn + 16];
}

/**
 * @brief 复位系统
 */
__STATIC_INLINE void __NVIC_SystemReset(void) {
    SCB->AIRCR  = ((0x5FAUL << 16U) | (SCB->AIRCR & (7UL << 8U)) | (1UL << 2U));
    __DSB();
    for(;;) {
        __NOP();
    }
}

/**
 * @brief 获取 FPU 类型
 */
__STATIC_INLINE uint32_t SCB_GetFPUType(void) {
    uint32_t mvfr0 = SCB->MVFR0;
    if      ((mvfr0 & (0xFUL << 0U)) == 0x220U) {
        return(2U);
    }
    else if ((mvfr0 & (0xFUL << 0U)) == 0x020U) {
        return(1U);
    }
    else {
        return(0U);
    }
}

/**
 * @brief SysTick 配置
 */
__STATIC_INLINE uint32_t SysTick_Config(uint32_t ticks) {
    if ((ticks - 1UL) > 0xFFFFFFUL) {
        return (1UL);
    }
    SysTick->LOAD = (uint32_t)(ticks - 1UL);
    __NVIC_SetPriority(SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL);
    SysTick->VAL  = 0UL;
    SysTick->CTRL = 0x07UL;
    return (0UL);
}

/**
 * @brief ITM 发送字符
 */
__STATIC_INLINE uint32_t ITM_SendChar (uint32_t ch) {
    if (((ITM->TCR & ITM_TCR_ITMENA_Msk) != 0UL) &&
        ((ITM->TER & (1UL << 0UL)          ) != 0UL)   ) {
        while (ITM->PORT[0U].u32 == 0UL) {
            __NOP();
        }
        ITM->PORT[0U].u8 = (uint8_t)ch;
    }
    return (ch);
}

/**
 * @brief ITM 接收字符
 */
__STATIC_INLINE int32_t ITM_ReceiveChar (void) {
    int32_t ch = -1;
    if (ITM->RXR != 0UL) {
        ch = (int32_t)ITM->RXR;
    }
    return (ch);
}

/**
 * @brief ITM 检查是否有字符
 */
__STATIC_INLINE int32_t ITM_CheckChar (void) {
    if (ITM->RXR != 0UL) {
        return(1);
    } else {
        return(0);
    }
}

/**
 * @brief 使能 FPU
 */
__STATIC_INLINE void __FPU_Enable(void) {
    uint32_t cpacr = __FPU_GetCPACR();
    cpacr |= ((3UL << 10U*2U) | (3UL << 11U*2U));
    __FPU_SetCPACR(cpacr);
}

/**
 * @brief 禁用 FPU
 */
__STATIC_INLINE void __FPU_Disable(void) {
    uint32_t cpacr = __FPU_GetCPACR();
    cpacr &= ~((3UL << 10U*2U) | (3UL << 11U*2U));
    __FPU_SetCPACR(cpacr);
}

/**
 * @brief 使能 MPU
 */
__STATIC_INLINE void MPU_Enable(bool enable_default_map_forPrivileged) {
    __DMB();
    MPU->CTRL = MPU_CTRL_ENABLE_Msk;
    if (enable_default_map_forPrivileged) {
        MPU->CTRL |= MPU_CTRL_PRIVDEFENA_Msk;
    }
    __DSB();
    __ISB();
}

/**
 * @brief 禁用 MPU
 */
__STATIC_INLINE void MPU_Disable(void) {
    __DMB();
    MPU->CTRL  &= ~MPU_CTRL_ENABLE_Msk;
    __DSB();
    __ISB();
}

/**
 * @brief 设置 MPU 区域
 */
__STATIC_INLINE void MPU_SetRegion(uint32_t rnr, uint32_t rbar, uint32_t rlar) {
    MPU->RNR  = rnr;
    MPU->RBAR = rbar;
    MPU->RLAR = rlar;
}

/**
 * @brief 清除 MPU 区域
 */
__STATIC_INLINE void MPU_ClearRegion(uint32_t rnr) {
    MPU->RNR  = rnr;
    MPU->RBAR = 0U;
    MPU->RLAR = 0U;
}

/**
 * @brief 使能 SAU (Security Attribution Unit)
 */
__STATIC_INLINE void __SAU_Enable(void) {
    SAU->CTRL |= (1UL << 0);
}

/**
 * @brief 禁用 SAU
 */
__STATIC_INLINE void __SAU_Disable(void) {
    SAU->CTRL &= ~(1UL << 0);
}

/**
 * @brief 设置 SAU 区域
 */
__STATIC_INLINE void __SAU_SetRegion(uint32_t rnr, uint32_t rbar, uint32_t rlar) {
    SAU->RNR  = rnr;
    SAU->RBAR = rbar;
    SAU->RLAR = rlar;
}

/*
 * ============================================================================
 * SCB (System Control Block) Functions
 * SCB (系统控制块) 函数
 * Reference: ARM Cortex-M33 GUG Chapter 4.2
 * 参考: ARM Cortex-M33 GUG 第 4.2 章
 * ============================================================================
 */

/**
 * @brief Get CPU ID
 * @brief 获取 CPU ID
 *
 * Reference: ARM Cortex-M33 GUG 4.2.1 (CPUID Register)
 * 参考: ARM Cortex-M33 GUG 4.2.1 (CPUID 寄存器)
 */
__STATIC_INLINE uint32_t SCB_GetCPUID(void) {
    return SCB->CPUID;
}

/**
 * @brief Get ICSR value
 * @brief 获取 ICSR 值
 *
 * Reference: ARM Cortex-M33 GUG 4.2.3 (ICSR)
 * 参考: ARM Cortex-M33 GUG 4.2.3 (ICSR)
 */
__STATIC_INLINE uint32_t SCB_GetICSR(void) {
    return SCB->ICSR;
}

/**
 * @brief Get VTOR value
 * @brief 获取 VTOR 值
 *
 * Reference: ARM Cortex-M33 GUG 4.2.18 (VTOR)
 * 参考: ARM Cortex-M33 GUG 4.2.18 (VTOR)
 */
__STATIC_INLINE uint32_t SCB_GetVTOR(void) {
    return SCB->VTOR;
}

/**
 * @brief Set VTOR value
 * @brief 设置 VTOR 值
 *
 * Reference: ARM Cortex-M33 GUG 4.2.18 (VTOR)
 * 参考: ARM Cortex-M33 GUG 4.2.18 (VTOR)
 */
__STATIC_INLINE void SCB_SetVTOR(uint32_t vtors) {
    SCB->VTOR = vtors;
}

/**
 * @brief Get SCR value
 * @brief 获取 SCR 值
 *
 * Reference: ARM Cortex-M33 GUG 4.2.11 (SCR)
 * 参考: ARM Cortex-M33 GUG 4.2.11 (SCR)
 */
__STATIC_INLINE uint32_t SCB_GetSCR(void) {
    return SCB->SCR;
}

/**
 * @brief Set SCR value
 * @brief 设置 SCR 值
 *
 * Reference: ARM Cortex-M33 GUG 4.2.11 (SCR)
 * 参考: ARM Cortex-M33 GUG 4.2.11 (SCR)
 */
__STATIC_INLINE void SCB_SetSCR(uint32_t scr) {
    SCB->SCR = scr;
}

/**
 * @brief Get CCR value
 * @brief 获取 CCR 值
 *
 * Reference: ARM Cortex-M33 GUG 4.2.12 (CCR)
 * 参考: ARM Cortex-M33 GUG 4.2.12 (CCR)
 */
__STATIC_INLINE uint32_t SCB_GetCCR(void) {
    return SCB->CCR;
}

/**
 * @brief Get CFSR value
 * @brief 获取 CFSR 值
 *
 * Reference: ARM Cortex-M33 GUG 4.3.8 (CFSR)
 * 参考: ARM Cortex-M33 GUG 4.3.8 (CFSR)
 */
__STATIC_INLINE uint32_t SCB_GetCFSR(void) {
    return SCB->CFSR;
}

/**
 * @brief Get HFSR value
 * @brief 获取 HFSR 值
 *
 * Reference: ARM Cortex-M33 GUG 4.3.9 (HFSR)
 * 参考: ARM Cortex-M33 GUG 4.3.9 (HFSR)
 */
__STATIC_INLINE uint32_t SCB_GetHFSR(void) {
    return SCB->HFSR;
}

/**
 * @brief Get MMFAR value
 * @brief 获取 MMFAR 值
 *
 * Reference: ARM Cortex-M33 GUG 4.3.10 (MMFAR)
 * 参考: ARM Cortex-M33 GUG 4.3.10 (MMFAR)
 */
__STATIC_INLINE uint32_t SCB_GetMMFAR(void) {
    return SCB->MMFAR;
}

/**
 * @brief Get BFAR value
 * @brief 获取 BFAR 值
 *
 * Reference: ARM Cortex-M33 GUG 4.3.11 (BFAR)
 * 参考: ARM Cortex-M33 GUG 4.3.11 (BFAR)
 */
__STATIC_INLINE uint32_t SCB_GetBFAR(void) {
    return SCB->BFAR;
}

/**
 * @brief Get SHCSR value
 * @brief 获取 SHCSR 值
 *
 * Reference: ARM Cortex-M33 GUG 4.3.6 (SHCSR)
 * 参考: ARM Cortex-M33 GUG 4.3.6 (SHCSR)
 */
__STATIC_INLINE uint32_t SCB_GetSHCSR(void) {
    return SCB->SHCSR;
}

/**
 * @brief Get CPACR value
 * @brief 获取 CPACR 值
 *
 * Reference: ARM Cortex-M33 GUG 4.2.14 (CPACR)
 * 参考: ARM Cortex-M33 GUG 4.2.14 (CPACR)
 */
__STATIC_INLINE uint32_t SCB_GetCPACR(void) {
    return SCB->CPACR;
}

/**
 * @brief Set CPACR value
 * @brief 设置 CPACR 值
 *
 * Reference: ARM Cortex-M33 GUG 4.2.14 (CPACR)
 * 参考: ARM Cortex-M33 GUG 4.2.14 (CPACR)
 */
__STATIC_INLINE void SCB_SetCPACR(uint32_t cpacr) {
    SCB->CPACR = cpacr;
}

/**
 * @brief Get MPU TYPE
 * @brief 获取 MPU 类型
 *
 * Reference: ARM Cortex-M33 GUG 4.5.1 (MPU_TYPE)
 * 参考: ARM Cortex-M33 GUG 4.5.1 (MPU_TYPE)
 */
__STATIC_INLINE uint32_t MPU_GetType(void) {
    return MPU->TYPE;
}

/**
 * @brief Get MPU region count
 * @brief 获取 MPU 区域数量
 *
 * Reference: ARM Cortex-M33 GUG 4.5.1 (MPU_TYPE)
 * 参考: ARM Cortex-M33 GUG 4.5.1 (MPU_TYPE)
 */
__STATIC_INLINE uint32_t MPU_GetNumRegions(void) {
    return ((MPU->TYPE >> 8) & 0xFFUL);
}

/**
 * @brief Set MPU memory attribute index
 * @brief 设置 MPU 内存属性索引
 *
 * Reference: ARM Cortex-M33 GUG 4.5.7 (MPU_MAIR0/MAIR1)
 * 参考: ARM Cortex-M33 GUG 4.5.7 (MPU_MAIR0/MAIR1)
 *
 * @param idx: Attribute index (0-7)
 * @param idx: 属性索引 (0-7)
 * @param attr: Memory attribute
 * @param attr: 内存属性
 */
__STATIC_INLINE void MPU_SetMemoryAttribute(uint8_t idx, uint8_t attr) {
    if (idx < 4) {
        MPU->MAIR0 = (MPU->MAIR0 & ~(0xFFUL << (idx * 8))) | ((uint32_t)attr << (idx * 8));
    } else {
        MPU->MAIR1 = (MPU->MAIR1 & ~(0xFFUL << ((idx - 4) * 8))) | ((uint32_t)attr << ((idx - 4) * 8));
    }
}

/**
 * @brief Get SAU type
 * @brief 获取 SAU 类型
 *
 * Reference: ARM Cortex-M33 GUG 6.3.2 (SAU_TYPE)
 * 参考: ARM Cortex-M33 GUG 6.3.2 (SAU_TYPE)
 */
__STATIC_INLINE uint32_t __SAU_GetType(void) {
    return SAU->TYPE;
}

/*
 * ============================================================================
 * Non-inline Function Declarations
 * 非内联函数声明
 * ============================================================================
 */

extern void NVIC_EnableIRQ(IRQn_Type IRQn);
extern void NVIC_DisableIRQ(IRQn_Type IRQn);
extern uint32_t NVIC_GetEnabledIRQ(IRQn_Type IRQn);
extern uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn);
extern void NVIC_SetPendingIRQ(IRQn_Type IRQn);
extern void NVIC_ClearPendingIRQ(IRQn_Type IRQn);
extern uint32_t NVIC_GetActive(IRQn_Type IRQn);
extern void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority);
extern uint32_t NVIC_GetPriority(IRQn_Type IRQn);
extern uint32_t NVIC_EncodePriority(uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority);
extern void NVIC_DecodePriority(uint32_t Priority, uint32_t PriorityGroup, uint32_t *pPreemptPriority, uint32_t *pSubPriority);
extern void NVIC_SetVector(IRQn_Type IRQn, uint32_t vector);
extern uint32_t NVIC_GetVector(IRQn_Type IRQn);
extern void NVIC_SystemReset(void);
extern void NVIC_SetPriorityGrouping(uint32_t PriorityGroup);
extern uint32_t NVIC_GetPriorityGrouping(void);

extern uint32_t SysTick_Config(uint32_t ticks);
extern uint32_t SysTick_GetValue(void);
extern void SysTick_SetReload(uint32_t value);
extern uint32_t SysTick_GetReload(void);
extern void SysTick_EnableIRQ(void);
extern void SysTick_DisableIRQ(void);
extern void SysTick_Enable(void);
extern void SysTick_Disable(void);
extern uint32_t SysTick_GetCalib(void);

extern uint32_t SCB_GetICSR(void);
extern void SCB_SetVTOR(uint32_t vtors);
extern uint32_t SCB_GetSCR(void);
extern void SCB_SetSCR(uint32_t scr);
extern uint32_t SCB_GetCCR(void);
extern uint32_t SCB_GetCFSR(void);
extern uint32_t SCB_GetHFSR(void);
extern uint32_t SCB_GetMMFAR(void);
extern uint32_t SCB_GetBFAR(void);
extern uint32_t SCB_GetSHCSR(void);
extern uint32_t SCB_GetCPACR(void);
extern void SCB_SetCPACR(uint32_t cpacr);

extern void MPU_Initialize(void);
extern void MPU_SetRegion(uint32_t rnr, uint32_t rbar, uint32_t rlar);
extern void MPU_ClearRegion(uint32_t rnr);

extern void SAU_Enable(void);
extern void SAU_Disable(void);
extern void SAU_SetRegion(uint32_t rnr, uint32_t rbar, uint32_t rlar);
extern uint32_t SAU_GetType(void);

extern void FPU_Enable(void);
extern void FPU_Disable(void);

extern uint32_t ITM_SendChar(uint32_t ch);
extern int32_t ITM_ReceiveChar(void);
extern int32_t ITM_CheckChar(void);
extern void ITM_Enable(uint32_t enable);

extern void PMU_Enable(void);
extern void PMU_Disable(void);
extern void PMU_ResetCycleCounter(void);
extern void PMU_ResetEventCounters(void);
extern void PMU_EnableCounter(uint32_t mask);
extern void PMU_DisableCounter(uint32_t mask);
extern uint32_t PMU_GetCycleCount(void);
extern uint32_t PMU_GetEventCounter(uint32_t counter);
extern void PMU_SetEventType(uint32_t counter, uint32_t type);
extern uint32_t PMU_GetOverflowStatus(void);
extern void PMU_EnableOverflowIRQ(uint32_t mask);
extern void PMU_DisableOverflowIRQ(uint32_t mask);

extern uint32_t TZ_GetControl_NS(void);
extern void TZ_SetControl_NS(uint32_t control);
extern uint32_t TZ_GetPSP_NS(void);
extern void TZ_SetPSP_NS(uint32_t psp);
extern uint32_t TZ_GetMSP_NS(void);
extern void TZ_SetMSP_NS(uint32_t msp);
extern uint32_t TZ_GetPRIMASK_NS(void);
extern void TZ_SetPRIMASK_NS(uint32_t primask);
extern uint32_t TZ_GetBASEPRI_NS(void);
extern void TZ_SetBASEPRI_NS(uint32_t basepri);
extern uint32_t TZ_GetFAULTMASK_NS(void);
extern void TZ_SetFAULTMASK_NS(uint32_t faultmask);
extern uint32_t TZ_GetPSPLIM_NS(void);
extern void TZ_SetPSPLIM_NS(uint32_t psplim);
extern uint32_t TZ_GetMSPLIM_NS(void);
extern void TZ_SetMSPLIM_NS(uint32_t msplim);

extern void Core_Init(void);
extern void Core_SetupVectorTable(void);

#ifdef __cplusplus
}
#endif

#endif
