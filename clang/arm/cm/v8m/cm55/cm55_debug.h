/*
 * cm55_debug.h
 * Cortex-M55 Debug Support Definitions
 * Reference: Cortex-M55 Technical Reference Manual, Chapter 18
 */

#ifndef CM55_DEBUG_H
#define CM55_DEBUG_H

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
} cm55_debug_regs_t;

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
} cm55_dwt_regs_t;

/*============================================================================*
 * BPU Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t REMAP;
    volatile uint32_t COMP[6];
} cm55_bpu_regs_t;

/*============================================================================*
 * Debug API Functions (Template)
 *============================================================================*/

void cm55_debug_enable_trace(void);
void cm55_debug_disable_trace(void);
uint32_t cm55_debug_is_halted(void);
void cm55_debug_halt(void);
void cm55_debug_resume(void);
void cm55_debug_step(void);

/* DWT Functions */
void cm55_dwt_enable_cyccnt(void);
void cm55_dwt_disable_cyccnt(void);
uint32_t cm55_dwt_get_cyccnt(void);
void cm55_dwt_set_cyccnt(uint32_t value);
void cm55_dwt_enable_exception_trace(void);
void cm55_dwt_enable_pc_sampling(uint32_t interval);

/* BPU Functions */
void cm55_bpu_enable(void);
void cm55_bpu_disable(void);
void cm55_bpu_set_breakpoint(uint32_t comp_id, uint32_t addr);
void cm55_bpu_clear_breakpoint(uint32_t comp_id);

/* Debug Authentication */
uint32_t cm55_debug_get_auth_status(void);
void cm55_debug_set_auth(uint32_t dbgen, uint32_t spiden);

#ifdef __cplusplus
}
#endif

#endif /* CM55_DEBUG_H */
