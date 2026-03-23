/*
 * ARM Architecture - ARMv8-M TrustZone Security Extension
 *
 * ============================================================================
 * File: armv8m_trustzone.h
 * Description: ARMv8-M TrustZone security extension definitions
 * 描述: ARMv8-M TrustZone 安全扩展定义
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B10: The Armv8-M Protected Memory System Architecture (SAU)
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V8M_TRUSTZONE_H__
#define __ARCH_ARM_V8M_TRUSTZONE_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv8m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * SAU Base Addresses
 * SAU 基地址
 * ============================================================================
 */

#define SAU_BASE_ADDR             0xE000EDD0UL
#define SCS_S_BASE_ADDR           0xE002E000UL

/*
 * ============================================================================
 * SAU Register Definitions
 * SAU 寄存器定义
 * ============================================================================
 */

/**
 * SAU Control Register (SAU_CTRL)
 * SAU 控制寄存器
 */
#define SAU_CTRL                  (*(volatile uint32_t *)(SAU_BASE_ADDR + 0x00))

/**
 * SAU Type Register (SAU_TYPE)
 * SAU 类型寄存器
 */
#define SAU_TYPE                  (*(volatile uint32_t *)(SAU_BASE_ADDR + 0x04))

/**
 * SAU Region Number Register (SAU_RNR)
 * SAU 区域编号寄存器
 */
#define SAU_RNR                   (*(volatile uint32_t *)(SAU_BASE_ADDR + 0x08))

/**
 * SAU Region Base Address Register (SAU_RBAR)
 * SAU 区域基地址寄存器
 */
#define SAU_RBAR                  (*(volatile uint32_t *)(SAU_BASE_ADDR + 0x0C))

/**
 * SAU Region Limit Address Register (SAU_RLAR)
 * SAU 区域限制地址寄存器
 */
#define SAU_RLAR                  (*(volatile uint32_t *)(SAU_BASE_ADDR + 0x10))

/**
 * Secure Fault Status Register (SFSR)
 * 安全故障状态寄存器
 */
#define SFSR                      (*(volatile uint32_t *)(SAU_BASE_ADDR + 0x14))

/**
 * Secure Fault Address Register (SFAR)
 * 安全故障地址寄存器
 */
#define SFAR                      (*(volatile uint32_t *)(SAU_BASE_ADDR + 0x18))

/*
 * ============================================================================
 * Non-Secure SCB Register Definitions
 * 非安全 SCB 寄存器定义
 * ============================================================================
 */

#define SCB_NS_CPUID              (*(volatile uint32_t *)(SCB_NS_BASE_ADDR + 0xD00))
#define SCB_NS_ICSR               (*(volatile uint32_t *)(SCB_NS_BASE_ADDR + 0xD04))
#define SCB_NS_VTOR               (*(volatile uint32_t *)(SCB_NS_BASE_ADDR + 0xD08))
#define SCB_NS_AIRCR              (*(volatile uint32_t *)(SCB_NS_BASE_ADDR + 0xD0C))
#define SCB_NS_SCR                (*(volatile uint32_t *)(SCB_NS_BASE_ADDR + 0xD10))
#define SCB_NS_CCR                (*(volatile uint32_t *)(SCB_NS_BASE_ADDR + 0xD14))
#define SCB_NS_SHPR1              (*(volatile uint32_t *)(SCB_NS_BASE_ADDR + 0xD18))
#define SCB_NS_SHPR2              (*(volatile uint32_t *)(SCB_NS_BASE_ADDR + 0xD1C))
#define SCB_NS_SHPR3              (*(volatile uint32_t *)(SCB_NS_BASE_ADDR + 0xD20))
#define SCB_NS_SHCSR              (*(volatile uint32_t *)(SCB_NS_BASE_ADDR + 0xD24))
#define SCB_NS_CFSR               (*(volatile uint32_t *)(SCB_NS_BASE_ADDR + 0xD28))
#define SCB_NS_HFSR               (*(volatile uint32_t *)(SCB_NS_BASE_ADDR + 0xD2C))
#define SCB_NS_DFSR               (*(volatile uint32_t *)(SCB_NS_BASE_ADDR + 0xD30))
#define SCB_NS_MMFAR              (*(volatile uint32_t *)(SCB_NS_BASE_ADDR + 0xD34))
#define SCB_NS_BFAR               (*(volatile uint32_t *)(SCB_NS_BASE_ADDR + 0xD38))
#define SCB_NS_AFSR               (*(volatile uint32_t *)(SCB_NS_BASE_ADDR + 0xD3C))

/*
 * ============================================================================
 * SAU Register Bit Definitions
 * SAU 寄存器位定义
 * ============================================================================
 */

/**
 * SAU_CTRL Register Bits
 * SAU_CTRL 寄存器位
 */
#define SAU_CTRL_ALLNS_Pos        1U
#define SAU_CTRL_ALLNS_Msk        (1UL << SAU_CTRL_ALLNS_Pos)
#define SAU_CTRL_ENABLE_Pos       0U
#define SAU_CTRL_ENABLE_Msk       (1UL << SAU_CTRL_ENABLE_Pos)

/**
 * SAU_TYPE Register Bits
 * SAU_TYPE 寄存器位
 */
#define SAU_TYPE_SREGION_Pos      0U
#define SAU_TYPE_SREGION_Msk      (0xFFUL << SAU_TYPE_SREGION_Pos)

/**
 * SAU_RBAR Register Bits
 * SAU_RBAR 寄存器位
 */
#define SAU_RBAR_BADDR_Pos        5U
#define SAU_RBAR_BADDR_Msk        (0x7FFFFFFUL << SAU_RBAR_BADDR_Pos)

/**
 * SAU_RLAR Register Bits
 * SAU_RLAR 寄存器位
 */
#define SAU_RLAR_LADDR_Pos        5U
#define SAU_RLAR_LADDR_Msk        (0x7FFFFFFUL << SAU_RLAR_LADDR_Pos)
#define SAU_RLAR_NSC_Pos          1U
#define SAU_RLAR_NSC_Msk          (1UL << SAU_RLAR_NSC_Pos)
#define SAU_RLAR_ENABLE_Pos       0U
#define SAU_RLAR_ENABLE_Msk       (1UL << SAU_RLAR_ENABLE_Pos)

/**
 * SFSR Register Bits
 * SFSR 寄存器位
 */
#define SFSR_LSERR_Pos            7U
#define SFSR_LSERR_Msk            (1UL << SFSR_LSERR_Pos)
#define SFSR_SFARVALID_Pos        6U
#define SFSR_SFARVALID_Msk        (1UL << SFSR_SFARVALID_Pos)
#define SFSR_LSPERR_Pos           5U
#define SFSR_LSPERR_Msk           (1UL << SFSR_LSPERR_Pos)
#define SFSR_INVTRAN_Pos          4U
#define SFSR_INVTRAN_Msk          (1UL << SFSR_INVTRAN_Pos)
#define SFSR_AUVIOL_Pos           3U
#define SFSR_AUVIOL_Msk           (1UL << SFSR_AUVIOL_Pos)
#define SFSR_INVER_Pos            2U
#define SFSR_INVER_Msk            (1UL << SFSR_INVER_Pos)
#define SFSR_INVIS_Pos            1U
#define SFSR_INVIS_Msk            (1UL << SFSR_INVIS_Pos)
#define SFSR_INVEP_Pos            0U
#define SFSR_INVEP_Msk            (1UL << SFSR_INVEP_Pos)

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Enable SAU
 */
void sau_enable(void);

/**
 * @brief Disable SAU
 */
void sau_disable(void);

/**
 * @brief Set all memory as non-secure
 * @param all_ns true = all memory is non-secure, false = use SAU regions
 */
void sau_set_all_nonsecure(bool all_ns);

/**
 * @brief Get number of SAU regions
 * @return Number of SAU regions
 */
uint32_t sau_get_region_count(void);

/**
 * @brief Configure SAU region
 * @param rnr Region number
 * @param base Base address
 * @param limit Limit address
 * @param nsc Non-secure callable flag
 * @param enable Enable flag
 */
void sau_configure_region(uint32_t rnr, uint32_t base, uint32_t limit, bool nsc, bool enable);

/**
 * @brief Clear SAU region
 * @param rnr Region number
 */
void sau_clear_region(uint32_t rnr);

/**
 * @brief Get secure fault status
 * @return SFSR value
 */
uint32_t sau_get_fault_status(void);

/**
 * @brief Clear secure fault status
 */
void sau_clear_fault_status(void);

/**
 * @brief Get secure fault address
 * @return SFAR value
 */
uint32_t sau_get_fault_address(void);

/**
 * @brief Get current security state
 * @return 0 = Non-secure, 1 = Secure
 */
static inline uint32_t trustzone_get_state(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, control" : "=r" (result));
    return (result >> 0) & 0x1U;  /* nPRIV bit indicates security state context */
}

/**
 * @brief Get secure MSP
 * @return Secure MSP value
 */
static inline uint32_t __get_MSP_S(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, msp_s" : "=r" (result));
    return result;
}

/**
 * @brief Set secure MSP
 * @param topOfStack New MSP_S value
 */
static inline void __set_MSP_S(uint32_t topOfStack) {
    __asm__ volatile ("MSR msp_s, %0" : : "r" (topOfStack) : "memory");
}

/**
 * @brief Get secure PSP
 * @return Secure PSP value
 */
static inline uint32_t __get_PSP_S(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, psp_s" : "=r" (result));
    return result;
}

/**
 * @brief Set secure PSP
 * @param topOfStack New PSP_S value
 */
static inline void __set_PSP_S(uint32_t topOfStack) {
    __asm__ volatile ("MSR psp_s, %0" : : "r" (topOfStack) : "memory");
}

/**
 * @brief Get non-secure MSP
 * @return Non-secure MSP value
 */
static inline uint32_t __get_MSP_NS(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, msp_ns" : "=r" (result));
    return result;
}

/**
 * @brief Set non-secure MSP
 * @param topOfStack New MSP_NS value
 */
static inline void __set_MSP_NS(uint32_t topOfStack) {
    __asm__ volatile ("MSR msp_ns, %0" : : "r" (topOfStack) : "memory");
}

/**
 * @brief Get non-secure PSP
 * @return Non-secure PSP value
 */
static inline uint32_t __get_PSP_NS(void) {
    uint32_t result;
    __asm__ volatile ("MRS %0, psp_ns" : "=r" (result));
    return result;
}

/**
 * @brief Set non-secure PSP
 * @param topOfStack New PSP_NS value
 */
static inline void __set_PSP_NS(uint32_t topOfStack) {
    __asm__ volatile ("MSR psp_ns, %0" : : "r" (topOfStack) : "memory");
}

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V8M_TRUSTZONE_H__ */
