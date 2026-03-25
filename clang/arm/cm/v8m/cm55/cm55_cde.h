/*
 * cm55_cde.h
 * Cortex-M55 Custom Datapath Extension (CDE) Definitions
 * Reference: Cortex-M55 Devices Generic User Guide, Chapter 4.16
 *            Cortex-M55 Technical Reference Manual, Chapter 17
 */

#ifndef CM55_CDE_H
#define CM55_CDE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * CDE Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t CPACR;
    volatile uint32_t NSACR;
} cm55_cde_regs_t;

/*============================================================================*
 * CDE Coprocessor Numbers
 *============================================================================*/

#define CM55_CDE_CP0        0
#define CM55_CDE_CP1        1
#define CM55_CDE_CP2        2
#define CM55_CDE_CP3        3
#define CM55_CDE_CP4        4
#define CM55_CDE_CP5        5
#define CM55_CDE_CP6        6
#define CM55_CDE_CP7        7

/*============================================================================*
 * CDE API Functions (Template)
 *============================================================================*/

uint32_t cm55_cde_is_present(void);
void cm55_cde_enable_coprocessor(uint32_t cp_num);
void cm55_cde_disable_coprocessor(uint32_t cp_num);
uint32_t cm55_cde_is_coprocessor_enabled(uint32_t cp_num);

/* CDE Instructions */
uint32_t cm55_cde_cx1(uint32_t cp_num, uint32_t imm);
uint64_t cm55_cde_cx1d(uint32_t cp_num, uint32_t imm);
uint32_t cm55_cde_cx2(uint32_t cp_num, uint32_t imm, uint32_t val);
uint64_t cm55_cde_cx2d(uint32_t cp_num, uint32_t imm, uint32_t val);
uint32_t cm55_cde_cx3(uint32_t cp_num, uint32_t imm, uint32_t val1, uint32_t val2);
uint64_t cm55_cde_cx3d(uint32_t cp_num, uint32_t imm, uint32_t val1, uint32_t val2);

/* CDE with Accumulate */
uint32_t cm55_cde_cx1a(uint32_t cp_num, uint32_t imm, uint32_t acc);
uint64_t cm55_cde_cx1da(uint32_t cp_num, uint32_t imm, uint64_t acc);
uint32_t cm55_cde_cx2a(uint32_t cp_num, uint32_t imm, uint32_t val, uint32_t acc);
uint64_t cm55_cde_cx2da(uint32_t cp_num, uint32_t imm, uint32_t val, uint64_t acc);
uint32_t cm55_cde_cx3a(uint32_t cp_num, uint32_t imm, uint32_t val1, uint32_t val2, uint32_t acc);
uint64_t cm55_cde_cx3da(uint32_t cp_num, uint32_t imm, uint32_t val1, uint32_t val2, uint64_t acc);

/* Vector CDE Instructions */
uint32_t cm55_cde_vcx1(uint32_t cp_num, uint32_t imm);
uint32_t cm55_cde_vcx2(uint32_t cp_num, uint32_t imm, uint32_t val);
uint32_t cm55_cde_vcx3(uint32_t cp_num, uint32_t imm, uint32_t val1, uint32_t val2);

/* Security Configuration */
void cm55_cde_set_ns_access(uint32_t cp_num, uint32_t enable);
uint32_t cm55_cde_get_ns_access(uint32_t cp_num);

#ifdef __cplusplus
}
#endif

#endif /* CM55_CDE_H */
