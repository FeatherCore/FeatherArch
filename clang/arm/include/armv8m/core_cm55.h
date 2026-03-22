/*
 * ARM Cortex-M55 Core Peripheral Access Layer
 * ARM Cortex-M55 核心外设访问层
 *
 * ============================================================================
 * File: core_cm55.h
 * Description: ARM Cortex-M55 core peripheral access layer definitions
 * 描述: ARM Cortex-M55 核心外设访问层定义
 *
 * This file defines all NVIC, SysTick, SCB, FPU, MPU, PMU, TrustZone, DSP functions for ARM Cortex-M55.
 * 本文件定义了 ARM Cortex-M55 的所有 NVIC、SysTick、SCB、FPU、MPU、PMU、TrustZone、DSP 函数。
 *
 * Documentation:
 *   ARM Cortex-M55 Devices Generic User Guide
 *   ARMv8.1-M Architecture Reference Manual
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

#ifndef __CORE_CM55_H_GENERIC
#define __CORE_CM55_H_GENERIC

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

#define __CM55_REV                 0x0001U
#define __MPU_PRESENT             1U
#define __VTOR_PRESENT            1U
#define __NVIC_PRIO_BITS          3U
#define __Vendor_SysTickConfig    0U
#define __FPU_PRESENT             1U
#define __FPU_DP                 1U
#define __PMU_PRESENT            1U
#define __DSP_PRESENT            1U

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
 * NVIC Functions (与 Cortex-M33 相同)
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
 * @brief 获取目标状态
 */
__STATIC_INLINE uint32_t NVIC_GetTargetState(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        return((uint32_t)(((NVIC->ITNS[tmp] >> (((uint32_t)(int32_t)IRQn) & 0x1FUL)) & 1U)));
    } else {
        return(0U);
    }
}

/**
 * @brief 设置目标状态
 */
__STATIC_INLINE uint32_t NVIC_SetTargetState(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        NVIC->ITNS[tmp] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
        return((uint32_t)(1UL));
    } else {
        return(0U);
    }
}

/**
 * @brief 清除目标状态
 */
__STATIC_INLINE uint32_t NVIC_ClearTargetState(IRQn_Type IRQn) {
    if ((int32_t)(IRQn) >= 0) {
        uint32_t tmp = (uint32_t)(((uint32_t)(int32_t)IRQn) >> 5UL);
        NVIC->ITNS[tmp] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
        return((uint32_t)(1UL));
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
 * PMU (Performance Monitor Unit) Functions - Cortex-M55 特有
 * ============================================================================
 */

/**
 * @brief PMU 初始化
 */
__STATIC_INLINE void __PMU_Enable(void) {
    PMU->CTRL |= (1UL << 0);
}

/**
 * @brief PMU 禁用
 */
__STATIC_INLINE void __PMU_Disable(void) {
    PMU->CTRL &= ~(1UL << 0);
}

/**
 * @brief 复位 cycle 计数器
 */
__STATIC_INLINE void __PMU_Cycle_Reset(void) {
    PMU->CTRL |= (1UL << 3);
}

/**
 * @brief 复位所有事件计数器
 */
__STATIC_INLINE void __PMU_CNTR_ALL_Reset(void) {
    PMU->CTRL |= (1UL << 4);
}

/**
 * @brief 使能计数器
 */
__STATIC_INLINE void __PMU_CNTR_Enable(uint32_t mask) {
    PMU->INTENSET = mask;
}

/**
 * @brief 禁用计数器
 */
__STATIC_INLINE void __PMU_CNTR_Disable(uint32_t mask) {
    PMU->INTENCLR = mask;
}

/**
 * @brief 获取 cycle 计数器值
 */
__STATIC_INLINE uint64_t __PMU_Get_CCNTR(void) {
    return PMU->CYCNT;
}

/**
 * @brief 获取事件计数器值
 */
__STATIC_INLINE uint32_t __PMU_Get_EVCNTR(uint32_t num) {
    return PMU->EVCNTR[num];
}

/**
 * @brief 设置事件类型
 */
__STATIC_INLINE void __PMU_Set_EVTYPER(uint32_t num, uint32_t type) {
    PMU->EVTYPER[num] = type;
}

/**
 * @brief 获取溢出状态
 */
__STATIC_INLINE uint32_t __PMU_Get_CNTR_OVS(void) {
    return (PMU->CTRL >> 24) & 0xFFUL;
}

#ifdef __cplusplus
}
#endif

#endif
