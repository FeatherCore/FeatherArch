/*
 * armv8m_debug.h
 * Armv8-M Debug Support Definitions
 * Reference: Armv8-M Architecture Reference Manual, Chapters B13-B14
 */

#ifndef ARMV8M_DEBUG_H
#define ARMV8M_DEBUG_H

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
} armv8m_debug_regs_t;

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
} armv8m_dwt_regs_t;

/*============================================================================*
 * FPB Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t REMAP;
    volatile uint32_t COMP[6];
    uint32_t RESERVED0[2];
    volatile uint32_t COMP15[2];
} armv8m_fpb_regs_t;

/*============================================================================*
 * Debug API Functions (Template)
 *============================================================================*/

void armv8m_debug_enable_trace(void);
void armv8m_debug_disable_trace(void);
uint32_t armv8m_debug_is_halted(void);
void armv8m_debug_halt(void);
void armv8m_debug_resume(void);
void armv8m_debug_step(void);

/* DWT Functions */
void armv8m_dwt_enable_cyccnt(void);
void armv8m_dwt_disable_cyccnt(void);
uint32_t armv8m_dwt_get_cyccnt(void);
void armv8m_dwt_set_cyccnt(uint32_t value);
void armv8m_dwt_enable_exception_trace(void);
void armv8m_dwt_enable_pc_sampling(uint32_t interval);

/* FPB Functions */
void armv8m_fpb_enable(void);
void armv8m_fpb_disable(void);
void armv8m_fpb_set_breakpoint(uint32_t comp_id, uint32_t addr);
void armv8m_fpb_clear_breakpoint(uint32_t comp_id);

/* Debug Authentication */
uint32_t armv8m_debug_get_auth_status(void);
void armv8m_debug_set_auth(uint32_t dbgen, uint32_t spiden);

#ifdef __cplusplus
}
#endif

#endif /* ARMV8M_DEBUG_H */
