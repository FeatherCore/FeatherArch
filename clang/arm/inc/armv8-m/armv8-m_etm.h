/*
 * ARM Architecture - ARMv8-M ETMv4 (Embedded Trace Macrocell)
 *
 * ============================================================================
 * File: armv8-m_etm.h
 * Description: ARMv8-M ETMv4 register definitions and function declarations
 * 描述: ARMv8-M ETMv4 寄存器定义和函数声明
 *
 * The ETM provides real-time instruction trace and data trace capabilities.
 * ETMv4 is the version used in ARMv8-M architecture.
 *
 * Reference: Arm(R) v8-M Architecture Reference Manual
 *   - Chapter B13.5: Embedded Trace Macrocell
 *   - Chapter D1.2: ETM Register Definitions
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ARCH_ARM_V8M_ETM_H__
#define __ARCH_ARM_V8M_ETM_H__

#include <stdint.h>
#include <stdbool.h>
#include "armv8-m_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ============================================================================
 * ETM Base Address
 * ETM 基地址
 * ============================================================================
 */

#define ETM_BASE_ADDR             0xE0041000UL

/*
 * ============================================================================
 * ETM Register Definitions
 * ETM 寄存器定义
 * ============================================================================
 */

/* ETM Main Control Register (ETM_CR) */
#define ETM_CR                    (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x004))

/* ETM Status Register (ETM_SR) */
#define ETM_SR                    (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x00C))

/* ETM Configuration Code Register (ETM_CCR) */
#define ETM_CCR                   (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x014))

/* ETM Trace Enable Register (ETM_TEEVR) */
#define ETM_TEEVR                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x020))

/* ETM Trace Enable Control 1 (ETM_TECR1) */
#define ETM_TECR1                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x024))

/* ETM FIFO Full Level (ETM_FFLR) */
#define ETM_FFLR                  (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x02C))

/* ETM ViewInst Main Control (ETM_VICTLR) */
#define ETM_VICTLR                (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x080))

/* ETM ViewInst Status (ETM_VIIECTLR) */
#define ETM_VIIECTLR              (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x084))

/* ETM ViewInst Include-Exclude Control (ETM_VISSCTLR) */
#define ETM_VISSCTLR              (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x088))

/* ETM ViewInst Start-Stop Control (ETM_VIPCSSCTLR) */
#define ETM_VIPCSSCTLR            (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x08C))

/* ETM Trace ID (ETM_TRCTRACEIDR) */
#define ETM_TRCTRACEIDR           (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x200))

/* ETM CoreSight Trace ID (ETM_TRCCIDR) */
#define ETM_TRCCIDR               (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x204))

/* ETM Programming Control (ETM_PRSR) */
#define ETM_PRSR                  (*(volatile uint32_t *)(ETM_BASE_ADDR + 0x314))

/* ETM Authentication Status (ETM_AUTHSTAT) */
#define ETM_AUTHSTAT              (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFB8))

/* ETM Device Architecture (ETM_DEVARCH) */
#define ETM_DEVARCH               (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFBC))

/* ETM Device Configuration (ETM_DEVID) */
#define ETM_DEVID                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFC8))

/* ETM Device Type (ETM_DEVTYPE) */
#define ETM_DEVTYPE               (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFCC))

/* ETM Peripheral ID Registers */
#define ETM_PIDR4                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFD0))
#define ETM_PIDR5                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFD4))
#define ETM_PIDR6                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFD8))
#define ETM_PIDR7                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFDC))
#define ETM_PIDR0                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFE0))
#define ETM_PIDR1                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFE4))
#define ETM_PIDR2                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFE8))
#define ETM_PIDR3                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFEC))

/* ETM Component ID Registers */
#define ETM_CIDR0                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFF0))
#define ETM_CIDR1                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFF4))
#define ETM_CIDR2                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFF8))
#define ETM_CIDR3                 (*(volatile uint32_t *)(ETM_BASE_ADDR + 0xFFC))

/*
 * ============================================================================
 * ETM Register Bit Definitions
 * ETM 寄存器位定义
 * ============================================================================
 */

/* ETM_CR - Main Control Register */
#define ETM_CR_TRACESTART_Pos     0U
#define ETM_CR_TRACESTART_Msk     (1UL << ETM_CR_TRACESTART_Pos)
#define ETM_CR_TRACESTOP_Pos      1U
#define ETM_CR_TRACESTOP_Msk      (1UL << ETM_CR_TRACESTOP_Pos)
#define ETM_CR_STALL_Pos          2U
#define ETM_CR_STALL_Msk          (1UL << ETM_CR_STALL_Pos)
#define ETM_CR_VMIDOPT_Pos        3U
#define ETM_CR_VMIDOPT_Msk        (1UL << ETM_CR_VMIDOPT_Pos)
#define ETM_CR_CCIEN_Pos          4U
#define ETM_CR_CCIEN_Msk          (1UL << ETM_CR_CCIEN_Pos)
#define ETM_CR_TSEN_Pos           5U
#define ETM_CR_TSEN_Msk           (1UL << ETM_CR_TSEN_Pos)
#define ETM_CR_CONDTYPE_Pos       6U
#define ETM_CR_CONDTYPE_Msk       (0x3UL << ETM_CR_CONDTYPE_Pos)
#define ETM_CR_VMIDTRACE_Pos      9U
#define ETM_CR_VMIDTRACE_Msk      (1UL << ETM_CR_VMIDTRACE_Pos)
#define ETM_CR_CIDTRACE_Pos       10U
#define ETM_CR_CIDTRACE_Msk       (1UL << ETM_CR_CIDTRACE_Pos)
#define ETM_CR_TSTAMPEN_Pos       11U
#define ETM_CR_TSTAMPEN_Msk       (1UL << ETM_CR_TSTAMPEN_Pos)
#define ETM_CR_TSTAMPDEC_Pos      12U
#define ETM_CR_TSTAMPDEC_Msk      (1UL << ETM_CR_TSTAMPDEC_Pos)
#define ETM_CR_TSTAMPBTM_Pos      13U
#define ETM_CR_TSTAMPBTM_Msk      (1UL << ETM_CR_TSTAMPBTM_Pos)
#define ETM_CR_TSTAMPOV_Pos       14U
#define ETM_CR_TSTAMPOV_Msk       (1UL << ETM_CR_TSTAMPOV_Pos)
#define ETM_CR_EXLEVEL_S_Pos      16U
#define ETM_CR_EXLEVEL_S_Msk      (0xFUL << ETM_CR_EXLEVEL_S_Pos)
#define ETM_CR_EXLEVEL_NS_Pos     20U
#define ETM_CR_EXLEVEL_NS_Msk     (0xFUL << ETM_CR_EXLEVEL_NS_Pos)
#define ETM_CR_INSTP0_Pos         32U
#define ETM_CR_INSTP0_Msk         (0x3UL << ETM_CR_INSTP0_Pos)
#define ETM_CR_INSTP1_Pos         34U
#define ETM_CR_INSTP1_Msk         (0x3UL << ETM_CR_INSTP1_Pos)
#define ETM_CR_INSTP2_Pos         36U
#define ETM_CR_INSTP2_Msk         (0x3UL << ETM_CR_INSTP2_Pos)
#define ETM_CR_INSTP3_Pos         38U
#define ETM_CR_INSTP3_Msk         (0x3UL << ETM_CR_INSTP3_Pos)
#define ETM_CR_INSTP4_Pos         40U
#define ETM_CR_INSTP4_Msk         (0x3UL << ETM_CR_INSTP4_Pos)
#define ETM_CR_INSTP5_Pos         42U
#define ETM_CR_INSTP5_Msk         (0x3UL << ETM_CR_INSTP5_Pos)
#define ETM_CR_INSTP6_Pos         44U
#define ETM_CR_INSTP6_Msk         (0x3UL << ETM_CR_INSTP6_Pos)
#define ETM_CR_INSTP7_Pos         46U
#define ETM_CR_INSTP7_Msk         (0x3UL << ETM_CR_INSTP7_Pos)
#define ETM_CR_INSTP8_Pos         48U
#define ETM_CR_INSTP8_Msk         (0x3UL << ETM_CR_INSTP8_Pos)
#define ETM_CR_INSTP9_Pos         50U
#define ETM_CR_INSTP9_Msk         (0x3UL << ETM_CR_INSTP9_Pos)
#define ETM_CR_INSTP10_Pos        52U
#define ETM_CR_INSTP10_Msk        (0x3UL << ETM_CR_INSTP10_Pos)
#define ETM_CR_INSTP11_Pos        54U
#define ETM_CR_INSTP11_Msk        (0x3UL << ETM_CR_INSTP11_Pos)
#define ETM_CR_INSTP12_Pos        56U
#define ETM_CR_INSTP12_Msk        (0x3UL << ETM_CR_INSTP12_Pos)
#define ETM_CR_INSTP13_Pos        58U
#define ETM_CR_INSTP13_Msk        (0x3UL << ETM_CR_INSTP13_Pos)

/* ETM_SR - Status Register */
#define ETM_SR_IDLE_Pos           0U
#define ETM_SR_IDLE_Msk           (1UL << ETM_SR_IDLE_Pos)
#define ETM_SR_PMSTABLE_Pos       1U
#define ETM_SR_PMSTABLE_Msk       (1UL << ETM_SR_PMSTABLE_Pos)
#define ETM_SR_TRIGBIT_Pos        2U
#define ETM_SR_TRIGBIT_Msk        (1UL << ETM_SR_TRIGBIT_Pos)
#define ETM_SR_STARTSTOP_Pos      3U
#define ETM_SR_STARTSTOP_Msk      (1UL << ETM_SR_STARTSTOP_Pos)
#define ETM_SR_AFREADY_Pos        4U
#define ETM_SR_AFREADY_Msk        (1UL << ETM_SR_AFREADY_Pos)
#define ETM_SR_BUFFNE_Pos         5U
#define ETM_SR_BUFFNE_Msk         (1UL << ETM_SR_BUFFNE_Pos)
#define ETM_SR_FUNC_Pos           6U
#define ETM_SR_FUNC_Msk           (1UL << ETM_SR_FUNC_Pos)
#define ETM_SR_ERR_Pos            7U
#define ETM_SR_ERR_Msk            (1UL << ETM_SR_ERR_Pos)

/* ETM_AUTHSTAT - Authentication Status */
#define ETM_AUTHSTAT_NSID_Pos     0U
#define ETM_AUTHSTAT_NSID_Msk     (0x3UL << ETM_AUTHSTAT_NSID_Pos)
#define ETM_AUTHSTAT_NSNID_Pos    2U
#define ETM_AUTHSTAT_NSNID_Msk    (0x3UL << ETM_AUTHSTAT_NSNID_Pos)
#define ETM_AUTHSTAT_SID_Pos      4U
#define ETM_AUTHSTAT_SID_Msk      (0x3UL << ETM_AUTHSTAT_SID_Pos)
#define ETM_AUTHSTAT_SNID_Pos     6U
#define ETM_AUTHSTAT_SNID_Msk     (0x3UL << ETM_AUTHSTAT_SNID_Pos)

#define ETM_AUTH_DISABLE          0x0U
#define ETM_AUTH_ENABLE           0x3U

/*
 * ============================================================================
 * Function Declarations
 * 函数声明
 * ============================================================================
 */

/**
 * @brief Initialize ETM
 * 初始化 ETM
 */
void etm_init(void);

/**
 * @brief Enable ETM tracing
 * 启用 ETM 跟踪
 */
void etm_enable(void);

/**
 * @brief Disable ETM tracing
 * 禁用 ETM 跟踪
 */
void etm_disable(void);

/**
 * @brief Check if ETM is present
 * 检查 ETM 是否存在
 * @return true if ETM is present
 */
bool etm_is_present(void);

/**
 * @brief Check if ETM is enabled
 * 检查 ETM 是否启用
 * @return true if ETM is enabled
 */
bool etm_is_enabled(void);

/**
 * @brief Set trace ID
 * 设置跟踪 ID
 * @param id Trace ID (1-127)
 */
void etm_set_trace_id(uint8_t id);

/**
 * @brief Get trace ID
 * 获取跟踪 ID
 * @return Current trace ID
 */
uint8_t etm_get_trace_id(void);

/**
 * @brief Configure instruction tracing
 * 配置指令跟踪
 * @param enable true to enable instruction tracing
 */
void etm_configure_instruction_trace(bool enable);

/**
 * @brief Configure exception level tracing
 * 配置异常级别跟踪
 * @param secure_mask Secure state exception level mask (bits 0-3 for EL0-EL3)
 * @param nonsecure_mask Non-secure state exception level mask
 */
void etm_configure_exception_level(uint8_t secure_mask, uint8_t nonsecure_mask);

/**
 * @brief Enable timestamping
 * 启用时间戳
 * @param enable true to enable timestamping
 */
void etm_enable_timestamp(bool enable);

/**
 * @brief Check authentication status
 * 检查认证状态
 * @return true if trace is enabled
 */
bool etm_check_auth(void);

/**
 * @brief Wait for ETM idle
 * 等待 ETM 空闲
 */
void etm_wait_for_idle(void);

/**
 * @brief Software trigger
 * 软件触发
 * Generates a trace trigger event.
 */
void etm_software_trigger(void);

#ifdef __cplusplus
}
#endif

#endif /* __ARCH_ARM_V8M_ETM_H__ */
