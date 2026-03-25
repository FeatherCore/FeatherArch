/*
 * armv7m_debug.h
 * Debug Support Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Part C
 */

#ifndef ARMV7M_DEBUG_H
#define ARMV7M_DEBUG_H

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
} armv7m_debug_regs_t;

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
} armv7m_dwt_regs_t;

/*============================================================================*
 * Debug API Functions (Template)
 *============================================================================*/

void armv7m_debug_enable_trace(void);
void armv7m_debug_disable_trace(void);
uint32_t armv7m_debug_is_halted(void);
void armv7m_debug_halt(void);
void armv7m_debug_resume(void);
void armv7m_dwt_enable_cyccnt(void);
uint32_t armv7m_dwt_get_cyccnt(void);
void armv7m_dwt_set_cyccnt(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* ARMV7M_DEBUG_H */
