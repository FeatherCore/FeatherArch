/**
 * @file arm_v8m_cm85_pwr.h
 * @brief Cortex-M85 Power Management
 *
 * @note Reference: Arm Cortex-M85 Devices Generic User Guide, Chapter 3.6
 * @note Reference: Arm Cortex-M85 Processor TRM, Chapter 7
 */

#ifndef ARM_V8M_CM85_PWR_H
#define ARM_V8M_CM85_PWR_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Power Mode Control Registers */
#define ARM_V8M_CM85_CPDLPSTATE_BASE    (0xE000E280UL)
#define ARM_V8M_CM85_CPDLPSTATE         (*(volatile uint32_t *)ARM_V8M_CM85_CPDLPSTATE_BASE)

#define ARM_V8M_CM85_DPDLPSTATE_BASE    (0xE000E284UL)
#define ARM_V8M_CM85_DPDLPSTATE         (*(volatile uint32_t *)ARM_V8M_CM85_DPDLPSTATE_BASE)

/* MSCR (Memory System Control Register) - for cache power */
#define ARM_V8M_CM85_MSCR_BASE          (0xE001E000UL)
#define ARM_V8M_CM85_MSCR               (*(volatile uint32_t *)ARM_V8M_CM85_MSCR_BASE)

/* CPDLPSTATE bit definitions */
#define ARM_V8M_CM85_CPDLPSTATE_CLPSTATE_Pos    0U
#define ARM_V8M_CM85_CPDLPSTATE_CLPSTATE_Msk    (0x3UL << ARM_V8M_CM85_CPDLPSTATE_CLPSTATE_Pos)
#define ARM_V8M_CM85_CPDLPSTATE_ELPSTATE_Pos    2U
#define ARM_V8M_CM85_CPDLPSTATE_ELPSTATE_Msk    (0x3UL << ARM_V8M_CM85_CPDLPSTATE_ELPSTATE_Pos)
#define ARM_V8M_CM85_CPDLPSTATE_RLPSTATE_Pos    4U
#define ARM_V8M_CM85_CPDLPSTATE_RLPSTATE_Msk    (0x3UL << ARM_V8M_CM85_CPDLPSTATE_RLPSTATE_Pos)

/* Power states */
typedef enum {
    ARM_V8M_CM85_PWR_MODE_ON = 0,
    ARM_V8M_CM85_PWR_MODE_RET = 1,
    ARM_V8M_CM85_PWR_MODE_OFF = 2
} arm_v8m_cm85_pwr_mode_t;

/* Core power modes */
typedef enum {
    ARM_V8M_CM85_PWR_CORE_RUN = 0,
    ARM_V8M_CM85_PWR_CORE_SLEEP = 1,
    ARM_V8M_CM85_PWR_CORE_DEEPSLEEP = 2
} arm_v8m_cm85_pwr_core_mode_t;

/* Power management initialization */
int arm_v8m_cm85_pwr_init(void);
void arm_v8m_cm85_pwr_deinit(void);

/* Core power mode control */
void arm_v8m_cm85_pwr_set_core_mode(arm_v8m_cm85_pwr_core_mode_t mode);
arm_v8m_cm85_pwr_core_mode_t arm_v8m_cm85_pwr_get_core_mode(void);

/* Sleep mode entry */
void arm_v8m_cm85_pwr_enter_sleep(void);
void arm_v8m_cm85_pwr_enter_deepsleep(void);

/* Wakeup configuration */
void arm_v8m_cm85_pwr_enable_wakeup(uint32_t sources);
void arm_v8m_cm85_pwr_disable_wakeup(uint32_t sources);
uint32_t arm_v8m_cm85_pwr_get_wakeup_status(void);
void arm_v8m_cm85_pwr_clear_wakeup_status(uint32_t sources);

/* EPU power control */
void arm_v8m_cm85_pwr_epu_power_down(void);
void arm_v8m_cm85_pwr_epu_power_up(void);
bool arm_v8m_cm85_pwr_epu_is_powered(void);

/* Cache power control */
void arm_v8m_cm85_pwr_icache_power_down(void);
void arm_v8m_cm85_pwr_icache_power_up(void);
void arm_v8m_cm85_pwr_dcache_power_down(void);
void arm_v8m_cm85_pwr_dcache_power_up(void);

/* RAM retention */
void arm_v8m_cm85_pwr_enable_ram_retention(uint32_t regions);
void arm_v8m_cm85_pwr_disable_ram_retention(uint32_t regions);

/* P-Channel interface (if implemented) */
void arm_v8m_cm85_pwr_pchannel_request(arm_v8m_cm85_pwr_mode_t mode);
arm_v8m_cm85_pwr_mode_t arm_v8m_cm85_pwr_pchannel_get_state(void);

/* Q-Channel interface (if implemented) */
void arm_v8m_cm85_pwr_qchannel_clock_on(void);
void arm_v8m_cm85_pwr_qchannel_clock_off(void);
bool arm_v8m_cm85_pwr_qchannel_clock_is_on(void);

/* Wait For Interrupt/Event */
void arm_v8m_cm85_pwr_wfi(void);
void arm_v8m_cm85_pwr_wfe(void);
void arm_v8m_cm85_pwr_sev(void);

/* SEVONPEND control */
void arm_v8m_cm85_pwr_enable_sevonpend(void);
void arm_v8m_cm85_pwr_disable_sevonpend(void);

/* Sleep-on-exit control */
void arm_v8m_cm85_pwr_enable_sleeponexit(void);
void arm_v8m_cm85_pwr_disable_sleeponexit(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM85_PWR_H */
