/**
 * @file cm85_debug.h
 * @brief Cortex-M85 Debug Components (DWT, ITM, CTI)
 *
 * @note Reference: Arm Cortex-M85 Processor TRM, Chapters 16-20
 */

#ifndef CM85_DEBUG_H
#define CM85_DEBUG_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* DWT (Data Watchpoint and Trace) */
typedef struct {
    volatile uint32_t CTRL;         /* Control Register */
    volatile uint32_t CYCCNT;       /* Cycle Count Register */
    volatile uint32_t CPICNT;       /* CPI Count Register */
    volatile uint32_t EXCCNT;       /* Exception Overhead Count Register */
    volatile uint32_t SLEEPCNT;     /* Sleep Count Register */
    volatile uint32_t LSUCNT;       /* LSU Count Register */
    volatile uint32_t FOLDCNT;      /* Folded-instruction Count Register */
    volatile uint32_t PCSR;         /* Program Counter Sample Register */
    volatile uint32_t COMP[4];      /* Comparator Registers */
    volatile uint32_t MASK[4];      /* Mask Registers */
    volatile uint32_t FUNCTION[4];  /* Function Registers */
} cm85_dwt_reg_t;

#define CM85_DWT_BASE       (0xE0001000UL)
#define CM85_DWT            ((cm85_dwt_reg_t *)CM85_DWT_BASE)

/* ITM (Instrumentation Trace Macrocell) */
typedef struct {
    volatile uint32_t STIM[256];    /* Stimulus Port Registers */
    volatile uint32_t RESERVED0[640];
    volatile uint32_t TER[8];       /* Trace Enable Registers */
    volatile uint32_t RESERVED1[8];
    volatile uint32_t TPR;          /* Trace Privilege Register */
    volatile uint32_t RESERVED2[15];
    volatile uint32_t TCR;          /* Trace Control Register */
} cm85_itm_reg_t;

#define CM85_ITM_BASE       (0xE0000000UL)
#define CM85_ITM            ((cm85_itm_reg_t *)CM85_ITM_BASE)

/* CTI (Cross Trigger Interface) */
typedef struct {
    volatile uint32_t CTICONTROL;   /* CTI Control Register */
    uint32_t RESERVED0[3];
    volatile uint32_t CTIINTACK;    /* CTI Interrupt Acknowledge Register */
    volatile uint32_t CTIAPPSET;    /* CTI Application Trigger Set Register */
    volatile uint32_t CTIAPPCLEAR;  /* CTI Application Trigger Clear Register */
    volatile uint32_t CTIAPPPULSE;  /* CTI Application Pulse Register */
    volatile uint32_t CTIINEN[8];   /* CTI Trigger to Channel Enable Registers */
    uint32_t RESERVED1[24];
    volatile uint32_t CTIOUTEN[8];  /* CTI Channel to Trigger Enable Registers */
    uint32_t RESERVED2[28];
    volatile uint32_t CTITRIGINSTATUS;  /* CTI Trigger In Status Register */
    volatile uint32_t CTITRIGOUTSTATUS; /* CTI Trigger Out Status Register */
    volatile uint32_t CTICHINSTATUS;    /* CTI Channel In Status Register */
    volatile uint32_t CTICHOUTSTATUS;   /* CTI Channel Out Status Register */
    volatile uint32_t CTIGATE;      /* CTI Channel Gate Enable Register */
} cm85_cti_reg_t;

#define CM85_CTI_BASE       (0xE0042000UL)
#define CM85_CTI            ((cm85_cti_reg_t *)CM85_CTI_BASE)

/* Debug initialization */
int cm85_debug_init(void);
void cm85_debug_deinit(void);

/* DWT functions */
void cm85_dwt_enable(void);
void cm85_dwt_disable(void);
void cm85_dwt_enable_cyccnt(void);
void cm85_dwt_disable_cyccnt(void);
uint32_t cm85_dwt_get_cyccnt(void);
void cm85_dwt_set_cyccnt(uint32_t value);

/* DWT comparators */
void cm85_dwt_set_comparator(uint32_t comp, uint32_t value);
uint32_t cm85_dwt_get_comparator(uint32_t comp);
void cm85_dwt_set_mask(uint32_t comp, uint32_t mask);
void cm85_dwt_set_function(uint32_t comp, uint32_t func);

/* ITM functions */
void cm85_itm_enable(void);
void cm85_itm_disable(void);
bool cm85_itm_is_enabled(void);
void cm85_itm_enable_port(uint32_t port);
void cm85_itm_disable_port(uint32_t port);
void cm85_itm_send(uint32_t port, uint32_t data);
bool cm85_itm_ready(uint32_t port);
void cm85_itm_print(const char *str);
void cm85_itm_printf(uint32_t port, const char *fmt, ...);

/* CTI functions */
void cm85_cti_enable(void);
void cm85_cti_disable(void);
void cm85_cti_trigger(uint32_t trigger);
void cm85_cti_clear_trigger(uint32_t trigger);
void cm85_cti_pulse_trigger(uint32_t trigger);
void cm85_cti_connect_trigger_to_channel(uint32_t trigger, uint32_t channel);
void cm85_cti_connect_channel_to_trigger(uint32_t channel, uint32_t trigger);

/* Debug authentication */
bool cm85_debug_is_enabled(void);
bool cm85_debug_is_secure_enabled(void);
bool cm85_debug_is_noninvasive_enabled(void);

/* CoreSight ROM table */
uint32_t cm85_debug_get_periph_id(void);
uint32_t cm85_debug_get_component_id(void);

/* Breakpoint and watchpoint */
void cm85_debug_set_breakpoint(uint32_t id, uint32_t addr);
void cm85_debug_clear_breakpoint(uint32_t id);
void cm85_debug_set_watchpoint(uint32_t id, uint32_t addr, uint32_t size);
void cm85_debug_clear_watchpoint(uint32_t id);

#ifdef __cplusplus
}
#endif

#endif /* CM85_DEBUG_H */
