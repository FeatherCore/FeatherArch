/*
 * cm4_debug.h
 * Cortex-M4 Debug Support Definitions
 * Reference: Cortex-M4 Technical Reference Manual, Chapters 8-11
 */

#ifndef CM4_DEBUG_H
#define CM4_DEBUG_H

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
} cm4_debug_regs_t;

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
} cm4_dwt_regs_t;

/*============================================================================*
 * FPB Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t REMAP;
    volatile uint32_t COMP[6];
    uint32_t RESERVED0[2];
    volatile uint32_t COMP15[2];
} cm4_fpb_regs_t;

/*============================================================================*
 * Debug API Functions (Template)
 *============================================================================*/

void cm4_debug_enable_trace(void);
void cm4_debug_disable_trace(void);
uint32_t cm4_debug_is_halted(void);
void cm4_debug_halt(void);
void cm4_debug_resume(void);
void cm4_debug_step(void);

/* DWT Functions */
void cm4_dwt_enable_cyccnt(void);
void cm4_dwt_disable_cyccnt(void);
uint32_t cm4_dwt_get_cyccnt(void);
void cm4_dwt_set_cyccnt(uint32_t value);
void cm4_dwt_enable_exception_trace(void);
void cm4_dwt_enable_pc_sampling(uint32_t interval);

/* FPB Functions */
void cm4_fpb_enable(void);
void cm4_fpb_disable(void);
void cm4_fpb_set_breakpoint(uint32_t comp_id, uint32_t addr);
void cm4_fpb_clear_breakpoint(uint32_t comp_id);

#ifdef __cplusplus
}
#endif

#endif /* CM4_DEBUG_H */
