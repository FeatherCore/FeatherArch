/*
 * arm_v8m_cm55_pwr.h
 * Cortex-M55 Power Management Definitions
 * Reference: Cortex-M55 Technical Reference Manual, Chapter 7
 */

#ifndef ARM_V8M_CM55_PWR_H
#define ARM_V8M_CM55_PWR_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Power Mode Definitions
 *============================================================================*/

typedef enum {
    ARM_V8M_CM55_PWR_MODE_RUN = 0,
    ARM_V8M_CM55_PWR_MODE_SLEEP,
    ARM_V8M_CM55_PWR_MODE_DEEPSLEEP,
    ARM_V8M_CM55_PWR_MODE_SHUTDOWN
} arm_v8m_cm55_pwr_mode_t;

/*============================================================================*
 * Power Control Register Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t CPDLPSTATE;
    volatile uint32_t DPDLPSTATE;
} arm_v8m_cm55_pwr_regs_t;

/*============================================================================*
 * CPDLPSTATE Bit Definitions
 *============================================================================*/

#define ARM_V8M_CM55_PWR_CPDLPSTATE_LP_Pos      0
#define ARM_V8M_CM55_PWR_CPDLPSTATE_LP_Msk      (0x3UL << ARM_V8M_CM55_PWR_CPDLPSTATE_LP_Pos)
#define ARM_V8M_CM55_PWR_CPDLPSTATE_EPU_Pos     2
#define ARM_V8M_CM55_PWR_CPDLPSTATE_EPU_Msk     (0x3UL << ARM_V8M_CM55_PWR_CPDLPSTATE_EPU_Pos)
#define ARM_V8M_CM55_PWR_CPDLPSTATE_RAM_Pos     4
#define ARM_V8M_CM55_PWR_CPDLPSTATE_RAM_Msk     (0x3UL << ARM_V8M_CM55_PWR_CPDLPSTATE_RAM_Pos)

/*============================================================================*
 * Power API Functions (Template)
 *============================================================================*/

void arm_v8m_cm55_pwr_set_mode(arm_v8m_cm55_pwr_mode_t mode);
arm_v8m_cm55_pwr_mode_t arm_v8m_cm55_pwr_get_mode(void);
void arm_v8m_cm55_pwr_enable_wfi(void);
void arm_v8m_cm55_pwr_enable_wfe(void);
void arm_v8m_cm55_pwr_set_epu_low_power(uint32_t mode);
void arm_v8m_cm55_pwr_set_ram_low_power(uint32_t mode);

/* P-Channel Interface */
void arm_v8m_cm55_pwr_pchannel_request(uint32_t state);
uint32_t arm_v8m_cm55_pwr_pchannel_get_state(void);

/* Q-Channel Interface */
void arm_v8m_cm55_pwr_qchannel_request(uint32_t state);
uint32_t arm_v8m_cm55_pwr_qchannel_get_state(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM55_PWR_H */
