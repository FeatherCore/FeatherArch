/*
 * cm7_debug.h
 * Cortex-M7 Debug Support Definitions
 * Reference: Cortex-M7 Technical Reference Manual, Chapters 9-13
 */

#ifndef CM7_DEBUG_H
#define CM7_DEBUG_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Debug Core Register Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t DHCSR;
    volatile uint32_t DCRSR;
    volatile uint32_t DCRDR;
    volatile uint32_t DEMCR;
} cm7_debug_regs_t;

/*============================================================================*
 * DWT Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t CYCCNT;
    volatile uint32_t CPICNT;
    volatile uint32_t EXCCNT;
    volatile uint32_t SLEEPCNT;
    volatile uint32_t LSUCNT;
    volatile uint32_t FOLDCNT;
    volatile uint32_t PCSR;
    volatile uint32_t COMP[4];
    volatile uint32_t MASK[4];
    volatile uint32_t FUNCTION[4];
} cm7_dwt_regs_t;

/*============================================================================*
 * FPB Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t REMAP;
    volatile uint32_t COMP[6];
    uint32_t RESERVED0[2];
    volatile uint32_t COMP15[2];
} cm7_fpb_regs_t;

/*============================================================================*
 * CTI Type Definitions (Cross Trigger Interface)
 *============================================================================*/

typedef struct {
    volatile uint32_t CTICONTROL;
    uint32_t RESERVED0[3];
    volatile uint32_t CTIINTACK;
    volatile uint32_t CTIAPPSET;
    volatile uint32_t CTIAPPCLEAR;
    volatile uint32_t CTIAPPPULSE;
    volatile uint32_t CTIINEN[8];
    uint32_t RESERVED1[24];
    volatile uint32_t CTIOUTEN[8];
    uint32_t RESERVED2[28];
    volatile uint32_t CTITRIGINSTATUS;
    volatile uint32_t CTITRIGOUTSTATUS;
    volatile uint32_t CTICHINSTATUS;
    volatile uint32_t CTICHOUTSTATUS;
    volatile uint32_t CTIGATE;
    uint32_t RESERVED3[963];
    volatile uint32_t CTILAR;
    volatile uint32_t CTILSR;
    volatile const uint32_t CTIAUTHSTATUS;
    uint32_t RESERVED4[3];
    volatile const uint32_t CTIDEVTYPE;
} cm7_cti_regs_t;

/*============================================================================*
 * Debug API Functions (Template)
 *============================================================================*/

void cm7_debug_enable_trace(void);
void cm7_debug_disable_trace(void);
uint32_t cm7_debug_is_halted(void);
void cm7_debug_halt(void);
void cm7_debug_resume(void);
void cm7_debug_step(void);

/* DWT Functions */
void cm7_dwt_enable_cyccnt(void);
void cm7_dwt_disable_cyccnt(void);
uint32_t cm7_dwt_get_cyccnt(void);
void cm7_dwt_set_cyccnt(uint32_t value);
void cm7_dwt_enable_exception_trace(void);
void cm7_dwt_enable_pc_sampling(uint32_t interval);

/* FPB Functions */
void cm7_fpb_enable(void);
void cm7_fpb_disable(void);
void cm7_fpb_set_breakpoint(uint32_t comp_id, uint32_t addr);
void cm7_fpb_clear_breakpoint(uint32_t comp_id);

/* CTI Functions */
void cm7_cti_enable(void);
void cm7_cti_disable(void);
void cm7_cti_trigger_output(uint32_t channel);
void cm7_cti_clear_trigger(uint32_t channel);

#ifdef __cplusplus
}
#endif

#endif /* CM7_DEBUG_H */
