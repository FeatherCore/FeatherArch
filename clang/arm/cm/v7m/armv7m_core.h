/*
 * armv7m_core.h
 * Armv7-M Core Register Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B1.4
 */

#ifndef ARMV7M_CORE_H
#define ARMV7M_CORE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Core Register Type Definitions
 *============================================================================*/

typedef struct {
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r4;
    uint32_t r5;
    uint32_t r6;
    uint32_t r7;
    uint32_t r8;
    uint32_t r9;
    uint32_t r10;
    uint32_t r11;
    uint32_t r12;
    uint32_t sp;
    uint32_t lr;
    uint32_t pc;
    uint32_t xpsr;
} armv7m_core_regs_t;

/*============================================================================*
 * Special-Purpose Register Access Functions (Template)
 *============================================================================*/

uint32_t armv7m_get_msp(void);
void armv7m_set_msp(uint32_t value);
uint32_t armv7m_get_psp(void);
void armv7m_set_psp(uint32_t value);
uint32_t armv7m_get_primask(void);
void armv7m_set_primask(uint32_t value);
uint32_t armv7m_get_control(void);
void armv7m_set_control(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* ARMV7M_CORE_H */
