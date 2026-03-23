/*
 * ARM Architecture - ARMv8-M PMU (Performance Monitor Unit)
 *
 * ============================================================================
 * File: armv8m_pmu.h
 * Description: ARMv8-M PMU definitions
 * 描述: ARMv8-M PMU 定义
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B15: The Performance Monitors Extension
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V8M_PMU_H__
#define __ARCH_ARM_V8M_PMU_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv8m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * PMU Base Address
 * PMU 基地址
 * ============================================================================
 */

#define PMU_BASE_ADDR             0xE0003000UL

/*
 * ============================================================================
 * PMU Register Definitions
 * PMU 寄存器定义
 * ============================================================================
 */

/**
 * PMU Event Counter Register (PMU_EVCNTRn)
 * PMU 事件计数器寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.204
 */
#define PMU_EVCNTR(n)             (*(volatile uint32_t *)(PMU_BASE_ADDR + 0x000 + ((n) * 4)))

/**
 * PMU Cycle Counter Register (PMU_CCNTR)
 * PMU 周期计数器寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.194
 */
#define PMU_CCNTR                 (*(volatile uint32_t *)(PMU_BASE_ADDR + 0x07C))

/**
 * PMU Event Type and Filter Register (PMU_EVTYPERn)
 * PMU 事件类型和过滤器寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.205
 */
#define PMU_EVTYPER(n)            (*(volatile uint32_t *)(PMU_BASE_ADDR + 0x400 + ((n) * 4)))

/**
 * PMU Cycle Counter Filter Register (PMU_CCFILTR)
 * PMU 周期计数器过滤器寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.193
 */
#define PMU_CCFILTR               (*(volatile uint32_t *)(PMU_BASE_ADDR + 0x47C))

/**
 * PMU Count Enable Set Register (PMU_CNTENSET)
 * PMU 计数使能设置寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.200
 */
#define PMU_CNTENSET              (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xC00))

/**
 * PMU Count Enable Clear Register (PMU_CNTENCLR)
 * PMU 计数使能清除寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.199
 */
#define PMU_CNTENCLR              (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xC20))

/**
 * PMU Interrupt Enable Set Register (PMU_INTENSET)
 * PMU 中断使能设置寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.207
 */
#define PMU_INTENSET              (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xC40))

/**
 * PMU Interrupt Enable Clear Register (PMU_INTENCLR)
 * PMU 中断使能清除寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.206
 */
#define PMU_INTENCLR              (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xC60))

/**
 * PMU Overflow Flag Status Clear Register (PMU_OVSCLR)
 * PMU 溢出标志状态清除寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.213
 */
#define PMU_OVSCLR                (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xC80))

/**
 * PMU Software Increment Register (PMU_SWINC)
 * PMU 软件递增寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.215
 */
#define PMU_SWINC                 (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xCA0))

/**
 * PMU Overflow Flag Status Set Register (PMU_OVSSET)
 * PMU 溢出标志状态设置寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.214
 */
#define PMU_OVSSET                (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xCC0))

/**
 * PMU Type Register (PMU_TYPE)
 * PMU 类型寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.216
 */
#define PMU_TYPE                  (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xE00))

/**
 * PMU Control Register (PMU_CTRL)
 * PMU 控制寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.201
 */
#define PMU_CTRL                  (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xE04))

/**
 * PMU Authentication Status Register (PMU_AUTHSTATUS)
 * PMU 认证状态寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.192
 */
#define PMU_AUTHSTATUS            (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xFB8))

/**
 * PMU Device Architecture Register (PMU_DEVARCH)
 * PMU 设备架构寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.202
 */
#define PMU_DEVARCH               (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xFBC))

/**
 * PMU Device Type Register (PMU_DEVTYPE)
 * PMU 设备类型寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.203
 */
#define PMU_DEVTYPE               (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xFCC))

/**
 * PMU Peripheral Identification Register 4 (PMU_PIDR4)
 * PMU 外设标识寄存器 4
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.212
 */
#define PMU_PIDR4                 (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xFD0))

/**
 * PMU Peripheral Identification Register 0 (PMU_PIDR0)
 * PMU 外设标识寄存器 0
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.208
 */
#define PMU_PIDR0                 (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xFE0))

/**
 * PMU Peripheral Identification Register 1 (PMU_PIDR1)
 * PMU 外设标识寄存器 1
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.209
 */
#define PMU_PIDR1                 (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xFE4))

/**
 * PMU Peripheral Identification Register 2 (PMU_PIDR2)
 * PMU 外设标识寄存器 2
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.210
 */
#define PMU_PIDR2                 (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xFE8))

/**
 * PMU Peripheral Identification Register 3 (PMU_PIDR3)
 * PMU 外设标识寄存器 3
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.211
 */
#define PMU_PIDR3                 (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xFEC))

/**
 * PMU Component Identification Register 0 (PMU_CIDR0)
 * PMU 组件标识寄存器 0
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.195
 */
#define PMU_CIDR0                 (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xFF0))

/**
 * PMU Component Identification Register 1 (PMU_CIDR1)
 * PMU 组件标识寄存器 1
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.196
 */
#define PMU_CIDR1                 (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xFF4))

/**
 * PMU Component Identification Register 2 (PMU_CIDR2)
 * PMU 组件标识寄存器 2
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.197
 */
#define PMU_CIDR2                 (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xFF8))

/**
 * PMU Component Identification Register 3 (PMU_CIDR3)
 * PMU 组件标识寄存器 3
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.2.198
 */
#define PMU_CIDR3                 (*(volatile uint32_t *)(PMU_BASE_ADDR + 0xFFC))

/*
 * ============================================================================
 * PMU Register Bit Definitions
 * PMU 寄存器位定义
 * ============================================================================
 */

/**
 * PMU_CTRL Register Bits
 * PMU_CTRL 寄存器位
 */
#define PMU_CTRL_IMP_Pos          24U
#define PMU_CTRL_IMP_Msk          (0xFFUL << PMU_CTRL_IMP_Pos)
#define PMU_CTRL_IDCODE_Pos       16U
#define PMU_CTRL_IDCODE_Msk       (0xFFUL << PMU_CTRL_IDCODE_Pos)
#define PMU_CTRL_N_Pos            11U
#define PMU_CTRL_N_Msk            (0x1FUL << PMU_CTRL_N_Pos)
#define PMU_CTRL_LC_Pos           6U
#define PMU_CTRL_LC_Msk           (1UL << PMU_CTRL_LC_Pos)
#define PMU_CTRL_CCD_Pos          5U
#define PMU_CTRL_CCD_Msk          (1UL << PMU_CTRL_CCD_Pos)
#define PMU_CTRL_CCDIS_Pos        4U
#define PMU_CTRL_CCDIS_Msk        (1UL << PMU_CTRL_CCDIS_Pos)
#define PMU_CTRL_X_Pos            3U
#define PMU_CTRL_X_Msk            (1UL << PMU_CTRL_X_Pos)
#define PMU_CTRL_D_Pos            2U
#define PMU_CTRL_D_Msk            (1UL << PMU_CTRL_D_Pos)
#define PMU_CTRL_C_Pos            1U
#define PMU_CTRL_C_Msk            (1UL << PMU_CTRL_C_Pos)
#define PMU_CTRL_E_Pos            0U
#define PMU_CTRL_E_Msk            (1UL << PMU_CTRL_E_Pos)

/**
 * PMU_TYPE Register Bits
 * PMU_TYPE 寄存器位
 */
#define PMU_TYPE_NCNTR_Pos        0U
#define PMU_TYPE_NCNTR_Msk        (0xFFUL << PMU_TYPE_NCNTR_Pos)

/*
 * ============================================================================
 * PMU Event Types
 * PMU 事件类型
 * ============================================================================
 */

#define PMU_EVT_SW_INCR           0x00U  /* Software increment */
#define PMU_EVT_L1I_CACHE_REFILL  0x01U  /* L1 I-Cache refill */
#define PMU_EVT_L1I_TLB_REFILL    0x02U  /* L1 I-TLB refill */
#define PMU_EVT_L1D_CACHE_REFILL  0x03U  /* L1 D-Cache refill */
#define PMU_EVT_L1D_CACHE         0x04U  /* L1 D-Cache access */
#define PMU_EVT_L1D_TLB_REFILL    0x05U  /* L1 D-TLB refill */
#define PMU_EVT_LD_RETIRED        0x06U  /* Load retired */
#define PMU_EVT_ST_RETIRED        0x07U  /* Store retired */
#define PMU_EVT_INST_RETIRED      0x08U  /* Instruction retired */
#define PMU_EVT_EXC_TAKEN         0x09U  /* Exception taken */
#define PMU_EVT_EXC_RETURN        0x0AU  /* Exception return */
#define PMU_EVT_CID_WRITE_RETIRED 0x0BU  /* Context ID write retired */
#define PMU_EVT_PC_WRITE_RETIRED  0x0CU  /* PC write retired */
#define PMU_EVT_BR_IMMED_RETIRED  0x0DU  /* Immediate branch retired */
#define PMU_EVT_BR_RETURN_RETIRED 0x0EU  /* Return branch retired */
#define PMU_EVT_UNALIGNED_LDST_RETIRED 0x0FU  /* Unaligned load/store retired */
#define PMU_EVT_BR_MIS_PRED       0x10U  /* Branch mispredicted */
#define PMU_EVT_CPU_CYCLES        0x11U  /* CPU cycles */
#define PMU_EVT_BR_PRED           0x12U  /* Branch predicted */
#define PMU_EVT_MEM_ACCESS        0x13U  /* Data memory access */
#define PMU_EVT_L1I_CACHE         0x14U  /* L1 I-Cache access */
#define PMU_EVT_L1D_CACHE_WB      0x15U  /* L1 D-Cache write-back */
#define PMU_EVT_L2D_CACHE         0x16U  /* L2 D-Cache access */
#define PMU_EVT_L2D_CACHE_REFILL  0x17U  /* L2 D-Cache refill */
#define PMU_EVT_L2D_CACHE_WB      0x18U  /* L2 D-Cache write-back */
#define PMU_EVT_BUS_ACCESS        0x19U  /* Bus access */
#define PMU_EVT_MEMORY_ERROR      0x1AU  /* Local memory error */
#define PMU_EVT_INST_SPEC         0x1BU  /* Instruction speculatively executed */
#define PMU_EVT_TTBR_WRITE_RETIRED 0x1CU /* TTBR write retired */
#define PMU_EVT_BUS_CYCLES        0x1DU  /* Bus cycles */
#define PMU_EVT_CHAIN             0x1EU  /* Chain (for 64-bit counters) */
#define PMU_EVT_L1D_CACHE_ALLOCATE 0x1FU /* L1 D-Cache allocate */
#define PMU_EVT_L2D_CACHE_ALLOCATE 0x20U /* L2 D-Cache allocate */
#define PMU_EVT_BR_RETIRED        0x21U  /* Branch retired */
#define PMU_EVT_BR_MIS_PRED_RETIRED 0x22U /* Branch mispredict retired */
#define PMU_EVT_STALL_FRONTEND    0x23U  /* Stall frontend */
#define PMU_EVT_STALL_BACKEND     0x24U  /* Stall backend */
#define PMU_EVT_L1D_TLB           0x25U  /* L1 D-TLB access */
#define PMU_EVT_L1I_TLB           0x26U  /* L1 I-TLB access */
#define PMU_EVT_L2I_CACHE         0x27U  /* L2 I-Cache access */
#define PMU_EVT_L2I_CACHE_REFILL  0x28U  /* L2 I-Cache refill */
#define PMU_EVT_L3D_CACHE_ALLOCATE 0x29U /* L3 D-Cache allocate */
#define PMU_EVT_L3D_CACHE_REFILL  0x2AU  /* L3 D-Cache refill */
#define PMU_EVT_L3D_CACHE         0x2BU  /* L3 D-Cache access */
#define PMU_EVT_L3D_CACHE_WB      0x2CU  /* L3 D-Cache write-back */
#define PMU_EVT_L2D_TLB_REFILL    0x2DU  /* L2 D-TLB refill */
#define PMU_EVT_L2I_TLB_REFILL    0x2EU  /* L2 I-TLB refill */
#define PMU_EVT_L2D_TLB           0x2FU  /* L2 D-TLB access */
#define PMU_EVT_L2I_TLB           0x30U  /* L2 I-TLB access */

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Enable PMU
 */
void pmu_enable(void);

/**
 * @brief Disable PMU
 */
void pmu_disable(void);

/**
 * @brief Reset all PMU counters
 */
void pmu_reset_counters(void);

/**
 * @brief Reset PMU cycle counter
 */
void pmu_reset_cycle_counter(void);

/**
 * @brief Get number of PMU counters
 * @return Number of event counters
 */
uint32_t pmu_get_num_counters(void);

/**
 * @brief Configure PMU counter
 * @param counter Counter number (0 to pmu_get_num_counters()-1)
 * @param event Event type to count
 */
void pmu_configure_counter(uint32_t counter, uint32_t event);

/**
 * @brief Enable PMU counter
 * @param counter Counter number
 */
void pmu_enable_counter(uint32_t counter);

/**
 * @brief Disable PMU counter
 * @param counter Counter number
 */
void pmu_disable_counter(uint32_t counter);

/**
 * @brief Get PMU counter value
 * @param counter Counter number
 * @return Counter value
 */
uint32_t pmu_get_counter_value(uint32_t counter);

/**
 * @brief Set PMU counter value
 * @param counter Counter number
 * @param value Value to set
 */
void pmu_set_counter_value(uint32_t counter, uint32_t value);

/**
 * @brief Enable PMU cycle counter
 */
void pmu_enable_cycle_counter(void);

/**
 * @brief Disable PMU cycle counter
 */
void pmu_disable_cycle_counter(void);

/**
 * @brief Get PMU cycle counter value
 * @return Cycle counter value
 */
uint32_t pmu_get_cycle_counter(void);

/**
 * @brief Set PMU cycle counter value
 * @param value Value to set
 */
void pmu_set_cycle_counter(uint32_t value);

/**
 * @brief Get PMU overflow status
 * @return Overflow flags (bit n = counter n overflow)
 */
uint32_t pmu_get_overflow_status(void);

/**
 * @brief Clear PMU overflow status
 * @param flags Overflow flags to clear
 */
void pmu_clear_overflow(uint32_t flags);

/**
 * @brief Enable PMU counter overflow interrupt
 * @param counter Counter number
 */
void pmu_enable_overflow_interrupt(uint32_t counter);

/**
 * @brief Disable PMU counter overflow interrupt
 * @param counter Counter number
 */
void pmu_disable_overflow_interrupt(uint32_t counter);

/**
 * @brief Check if PMU event is supported
 * @param event Event type
 * @return true if supported, false otherwise
 */
bool pmu_is_event_supported(uint32_t event);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V8M_PMU_H__ */
