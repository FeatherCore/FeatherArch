/*
 * cm55_pwr.h
 * Cortex-M55 Power Management Definitions
 * Reference: Cortex-M55 Technical Reference Manual, Chapter 7
 */

#ifndef CM55_PWR_H
#define CM55_PWR_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Power Mode Definitions
 *============================================================================*/

typedef enum {
    CM55_PWR_MODE_RUN = 0,
    CM55_PWR_MODE_SLEEP,
    CM55_PWR_MODE_DEEPSLEEP,
    CM55_PWR_MODE_SHUTDOWN
} cm55_pwr_mode_t;

/*============================================================================*
 * Power Control Register Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t CPDLPSTATE;
    volatile uint32_t DPDLPSTATE;
} cm55_pwr_regs_t;

/*============================================================================*
 * CPDLPSTATE Bit Definitions
 *============================================================================*/

#define CM55_PWR_CPDLPSTATE_LP_Pos      0
#define CM55_PWR_CPDLPSTATE_LP_Msk      (0x3UL << CM55_PWR_CPDLPSTATE_LP_Pos)
#define CM55_PWR_CPDLPSTATE_EPU_Pos     2
#define CM55_PWR_CPDLPSTATE_EPU_Msk     (0x3UL << CM55_PWR_CPDLPSTATE_EPU_Pos)
#define CM55_PWR_CPDLPSTATE_RAM_Pos     4
#define CM55_PWR_CPDLPSTATE_RAM_Msk     (0x3UL << CM55_PWR_CPDLPSTATE_RAM_Pos)

/*============================================================================*
 * Power API Functions (Template)
 *============================================================================*/

void cm55_pwr_set_mode(cm55_pwr_mode_t mode);
cm55_pwr_mode_t cm55_pwr_get_mode(void);
void cm55_pwr_enable_wfi(void);
void cm55_pwr_enable_wfe(void);
void cm55_pwr_set_epu_low_power(uint32_t mode);
void cm55_pwr_set_ram_low_power(uint32_t mode);

/* P-Channel Interface */
void cm55_pwr_pchannel_request(uint32_t state);
uint32_t cm55_pwr_pchannel_get_state(void);

/* Q-Channel Interface */
void cm55_pwr_qchannel_request(uint32_t state);
uint32_t cm55_pwr_qchannel_get_state(void);

#ifdef __cplusplus
}
#endif

#endif /* CM55_PWR_H */
