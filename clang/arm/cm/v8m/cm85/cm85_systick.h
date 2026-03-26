/**
 * @file arm_v8m_cm85_systick.h
 * @brief Cortex-M85 SysTick Timer
 *
 * @note Reference: Arm Cortex-M85 Devices Generic User Guide, Chapter 5.4
 * @note Reference: Arm Cortex-M85 Processor TRM, Chapter 5 (SysTick Timer register summary)
 */

#ifndef ARM_V8M_CM85_SYSTICK_H
#define ARM_V8M_CM85_SYSTICK_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SysTick register structure */
typedef struct {
    volatile uint32_t CTRL;      /* Control and Status Register */
    volatile uint32_t LOAD;      /* Reload Value Register */
    volatile uint32_t VAL;       /* Current Value Register */
    volatile uint32_t CALIB;     /* Calibration Value Register */
} arm_v8m_cm85_systick_reg_t;

#define ARM_V8M_CM85_SYSTICK_BASE       (0xE000E010UL)
#define ARM_V8M_CM85_SYSTICK            ((arm_v8m_cm85_systick_reg_t *)ARM_V8M_CM85_SYSTICK_BASE)

/* CTRL register bit definitions */
#define ARM_V8M_CM85_SYSTICK_CTRL_ENABLE_Pos        0U
#define ARM_V8M_CM85_SYSTICK_CTRL_ENABLE_Msk        (1UL << ARM_V8M_CM85_SYSTICK_CTRL_ENABLE_Pos)
#define ARM_V8M_CM85_SYSTICK_CTRL_TICKINT_Pos       1U
#define ARM_V8M_CM85_SYSTICK_CTRL_TICKINT_Msk       (1UL << ARM_V8M_CM85_SYSTICK_CTRL_TICKINT_Pos)
#define ARM_V8M_CM85_SYSTICK_CTRL_CLKSOURCE_Pos     2U
#define ARM_V8M_CM85_SYSTICK_CTRL_CLKSOURCE_Msk     (1UL << ARM_V8M_CM85_SYSTICK_CTRL_CLKSOURCE_Pos)
#define ARM_V8M_CM85_SYSTICK_CTRL_COUNTFLAG_Pos     16U
#define ARM_V8M_CM85_SYSTICK_CTRL_COUNTFLAG_Msk     (1UL << ARM_V8M_CM85_SYSTICK_CTRL_COUNTFLAG_Pos)

/* Clock source selection */
typedef enum {
    ARM_V8M_CM85_SYSTICK_CLKSOURCE_EXTERNAL = 0,  /* External reference clock */
    ARM_V8M_CM85_SYSTICK_CLKSOURCE_PROCESSOR = 1  /* Processor clock */
} arm_v8m_cm85_systick_clksrc_t;

/* SysTick configuration structure */
typedef struct {
    uint32_t reload;             /* Reload value (24-bit) */
    arm_v8m_cm85_systick_clksrc_t clk_src;
    bool enable_interrupt;
    bool enable;
} arm_v8m_cm85_systick_config_t;

/* SysTick initialization */
int arm_v8m_cm85_systick_init(const arm_v8m_cm85_systick_config_t *config);
void arm_v8m_cm85_systick_deinit(void);

/* SysTick control */
void arm_v8m_cm85_systick_enable(void);
void arm_v8m_cm85_systick_disable(void);
bool arm_v8m_cm85_systick_is_enabled(void);

/* Interrupt control */
void arm_v8m_cm85_systick_enable_interrupt(void);
void arm_v8m_cm85_systick_disable_interrupt(void);
bool arm_v8m_cm85_systick_interrupt_enabled(void);

/* Clock source */
void arm_v8m_cm85_systick_set_clock_source(arm_v8m_cm85_systick_clksrc_t src);
arm_v8m_cm85_systick_clksrc_t arm_v8m_cm85_systick_get_clock_source(void);

/* Reload value */
void arm_v8m_cm85_systick_set_reload(uint32_t reload);
uint32_t arm_v8m_cm85_systick_get_reload(void);

/* Current value */
void arm_v8m_cm85_systick_set_value(uint32_t value);
uint32_t arm_v8m_cm85_systick_get_value(void);

/* Status */
bool arm_v8m_cm85_systick_has_counted_to_zero(void);

/* Calibration value */
uint32_t arm_v8m_cm85_systick_get_calib_tenms(void);
bool arm_v8m_cm85_systick_calib_skew(void);
bool arm_v8m_cm85_systick_calib_noref(void);

/* Utility functions */
uint32_t arm_v8m_cm85_systick_calc_reload(uint32_t freq_hz, uint32_t period_us);
void arm_v8m_cm85_systick_delay_us(uint32_t us);
void arm_v8m_cm85_systick_delay_ms(uint32_t ms);

/* Non-secure SysTick access (when TrustZone is implemented) */
#ifdef __ARM_FEATURE_CMSE
#define ARM_V8M_CM85_SYSTICK_NS_BASE    (0xE002E010UL)
#define ARM_V8M_CM85_SYSTICK_NS         ((arm_v8m_cm85_systick_reg_t *)ARM_V8M_CM85_SYSTICK_NS_BASE)

int arm_v8m_cm85_systick_init_ns(const arm_v8m_cm85_systick_config_t *config);
void arm_v8m_cm85_systick_enable_ns(void);
void arm_v8m_cm85_systick_disable_ns(void);
void arm_v8m_cm85_systick_set_reload_ns(uint32_t reload);
uint32_t arm_v8m_cm85_systick_get_reload_ns(void);
void arm_v8m_cm85_systick_set_value_ns(uint32_t value);
uint32_t arm_v8m_cm85_systick_get_value_ns(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM85_SYSTICK_H */
