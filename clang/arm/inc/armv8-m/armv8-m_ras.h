/*
 * ARM Architecture - ARMv8-M RAS (Reliability, Availability, and Serviceability)
 *
 * ============================================================================
 * File: armv8-m_ras.h
 * Description: ARMv8-M RAS extension definitions
 * 描述: ARMv8-M RAS 扩展定义
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter D1.1.7 Reliability, Availability and Serviceability Extension Fault Status Register
 *   - Chapter D1.1.16 Reliability, Availability and Serviceability Extension Fault Status Register
 *   - Chapter D1.2.80 - D1.2.95 RAS register definitions
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V8M_RAS_H__
#define __ARCH_ARM_V8M_RAS_H__

#include <stdint.h>
#include "armv8-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * RAS Base Addresses
 * RAS 基地址
 * ============================================================================
 */

#define RAS_BASE_ADDR             0xE0005000UL
#define RAS_NS_BASE_ADDR          0xE000EF04UL

/*
 * ============================================================================
 * RAS Register Definitions
 * RAS 寄存器定义
 * ============================================================================
 */

/**
 * Error Record Feature Register n (ERRFRn)
 * 错误记录特性寄存器n
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.7, D1.2.84
 */
#define ERRFR(n)                  (*(volatile uint32_t *)(RAS_BASE_ADDR + 0x000 + ((n) * 0x40)))

/**
 * Error Record Control Register n (ERRCTRLn)
 * 错误记录控制寄存器n
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.7, D1.2.82
 */
#define ERRCTRL(n)                (*(volatile uint32_t *)(RAS_BASE_ADDR + 0x008 + ((n) * 0x40)))

/**
 * Error Record Primary Status Register n (ERRSTATUSn)
 * 错误记录主状态寄存器n
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.7, D1.2.95
 */
#define ERRSTATUS(n)              (*(volatile uint32_t *)(RAS_BASE_ADDR + 0x010 + ((n) * 0x40)))

/**
 * Error Record Address Register n (ERRADDRn)
 * 错误记录地址寄存器n
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.7, D1.2.80
 */
#define ERRADDR(n)                (*(volatile uint32_t *)(RAS_BASE_ADDR + 0x018 + ((n) * 0x40)))

/**
 * Error Record Address 2 Register n (ERRADDR2n)
 * 错误记录地址2寄存器n
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.7, D1.2.81
 */
#define ERRADDR2(n)               (*(volatile uint32_t *)(RAS_BASE_ADDR + 0x01C + ((n) * 0x40)))

/**
 * Error Record Miscellaneous 0 Register n (ERRMISC0n)
 * 错误记录杂项0寄存器n
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.7, D1.2.87
 */
#define ERRMISC0(n)               (*(volatile uint32_t *)(RAS_BASE_ADDR + 0x020 + ((n) * 0x40)))

/**
 * Error Record Miscellaneous 1 Register n (ERRMISC1n)
 * 错误记录杂项1寄存器n
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.7, D1.2.88
 */
#define ERRMISC1(n)               (*(volatile uint32_t *)(RAS_BASE_ADDR + 0x024 + ((n) * 0x40)))

/**
 * Error Record Miscellaneous 2 Register n (ERRMISC2n)
 * 错误记录杂项2寄存器n
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.7, D1.2.89
 */
#define ERRMISC2(n)               (*(volatile uint32_t *)(RAS_BASE_ADDR + 0x028 + ((n) * 0x40)))

/**
 * Error Record Miscellaneous 3 Register n (ERRMISC3n)
 * 错误记录杂项3寄存器n
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.7, D1.2.90
 */
#define ERRMISC3(n)               (*(volatile uint32_t *)(RAS_BASE_ADDR + 0x02C + ((n) * 0x40)))

/**
 * Error Record Miscellaneous 4 Register n (ERRMISC4n)
 * 错误记录杂项4寄存器n
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.7, D1.2.91
 */
#define ERRMISC4(n)               (*(volatile uint32_t *)(RAS_BASE_ADDR + 0x030 + ((n) * 0x40)))

/**
 * Error Record Miscellaneous 5 Register n (ERRMISC5n)
 * 错误记录杂项5寄存器n
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.7, D1.2.92
 */
#define ERRMISC5(n)               (*(volatile uint32_t *)(RAS_BASE_ADDR + 0x034 + ((n) * 0x40)))

/**
 * Error Record Miscellaneous 6 Register n (ERRMISC6n)
 * 错误记录杂项6寄存器n
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.7, D1.2.93
 */
#define ERRMISC6(n)               (*(volatile uint32_t *)(RAS_BASE_ADDR + 0x038 + ((n) * 0x40)))

/**
 * Error Record Miscellaneous 7 Register n (ERRMISC7n)
 * 错误记录杂项7寄存器n
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.7, D1.2.94
 */
#define ERRMISC7(n)               (*(volatile uint32_t *)(RAS_BASE_ADDR + 0x03C + ((n) * 0x40)))

/**
 * RAS Fault Group Status Register n (ERRGSRn)
 * RAS 错误组状态寄存器n
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.7, D1.2.85
 */
#define ERRGSR(n)                 (*(volatile uint32_t *)(RAS_BASE_ADDR + 0xE00 + ((n) * 4)))

/**
 * Error Implementer ID Register (ERRIIDR)
 * 错误实现者ID寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.7, D1.2.86
 */
#define ERRIIDR                   (*(volatile uint32_t *)(RAS_BASE_ADDR + 0xE10))

/**
 * Error Record Device ID Register (ERRDEVID)
 * 错误记录设备ID寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.7, D1.2.83
 */
#define ERRDEVID                  (*(volatile uint32_t *)(RAS_BASE_ADDR + 0xFC8))

/**
 * RAS Fault Status Register (RFSR)
 * RAS 错误状态寄存器
 * Reference: Arm(R) v8-M Architecture Reference Manual, D1.1.16
 */
#define RFSR                      (*(volatile uint32_t *)(RAS_NS_BASE_ADDR))

/*
 * ============================================================================
 * RAS Register Bit Definitions
 * RAS 寄存器位定义
 * ============================================================================
 */

/* ERRFR Register Bits */
#define ERRFR_CI_Pos              16U
#define ERRFR_CI_Msk              (0x3UL << ERRFR_CI_Pos)
#define ERRFR_CEO_Pos             0U
#define ERRFR_CEO_Msk             (0x1UL << ERRFR_CEO_Pos)

/* ERRCTRL Register Bits */
#define ERRCTRL_CI_Pos            0U
#define ERRCTRL_CI_Msk            (0x1UL << ERRCTRL_CI_Pos)

/* ERRSTATUS Register Bits */
#define ERRSTATUS_V_Pos           31U
#define ERRSTATUS_V_Msk           (0x1UL << ERRSTATUS_V_Pos)
#define ERRSTATUS_OF_Pos          30U
#define ERRSTATUS_OF_Msk          (0x1UL << ERRSTATUS_OF_Pos)
#define ERRSTATUS_UC_Pos          23U
#define ERRSTATUS_UC_Msk          (0x1UL << ERRSTATUS_UC_Pos)
#define ERRSTATUS_UEU_Pos         22U
#define ERRSTATUS_UEU_Msk         (0x1UL << ERRSTATUS_UEU_Pos)
#define ERRSTATUS_UER_Pos         21U
#define ERRSTATUS_UER_Msk         (0x1UL << ERRSTATUS_UER_Pos)
#define ERRSTATUS_UEO_Pos         20U
#define ERRSTATUS_UEO_Msk         (0x1UL << ERRSTATUS_UEO_Pos)
#define ERRSTATUS_DE_Pos          19U
#define ERRSTATUS_DE_Msk          (0x1UL << ERRSTATUS_DE_Pos)
#define ERRSTATUS_CI_Pos          18U
#define ERRSTATUS_CI_Msk          (0x1UL << ERRSTATUS_CI_Pos)
#define ERRSTATUS_UE_Pos          17U
#define ERRSTATUS_UE_Msk          (0x1UL << ERRSTATUS_UE_Pos)
#define ERRSTATUS_UET_Pos         16U
#define ERRSTATUS_UET_Msk         (0x1UL << ERRSTATUS_UET_Pos)
#define ERRSTATUS_CE_Pos          0U
#define ERRSTATUS_CE_Msk          (0x1UL << ERRSTATUS_CE_Pos)

/* ERRIIDR Register Bits */
#define ERRIIDR_ARCHID_Pos        16U
#define ERRIIDR_ARCHID_Msk        (0xFFFFUL << ERRIIDR_ARCHID_Pos)
#define ERRIIDR_REVISION_Pos      12U
#define ERRIIDR_REVISION_Msk      (0xFUL << ERRIIDR_REVISION_Pos)
#define ERRIIDR_JEP106_Pos        4U
#define ERRIIDR_JEP106_Msk        (0xFFUL << ERRIIDR_JEP106_Pos)
#define ERRIIDR_JEP106C_Pos       0U
#define ERRIIDR_JEP106C_Msk       (0xFUL << ERRIIDR_JEP106C_Pos)

/* ERRDEVID Register Bits */
#define ERRDEVID_NUM_Pos          0U
#define ERRDEVID_NUM_Msk          (0x3FUL << ERRDEVID_NUM_Pos)

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Enable RAS extension
 */
void ras_enable(void);

/**
 * @brief Disable RAS extension
 */
void ras_disable(void);

/**
 * @brief Check if RAS is present
 * @return true if present
 */
bool ras_is_present(void);

/**
 * @brief Get number of error records
 * @return Number of error records
 */
uint32_t ras_get_num_error_records(void);

/**
 * @brief Check if error record is valid
 * @param index Error record index
 * @return true if valid
 */
bool ras_is_error_record_valid(uint32_t index);

/**
 * @brief Clear error record
 * @param index Error record index
 */
void ras_clear_error_record(uint32_t index);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V8M_RAS_H__ */
