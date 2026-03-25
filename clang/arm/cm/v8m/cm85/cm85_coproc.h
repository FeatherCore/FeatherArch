/**
 * @file cm85_coproc.h
 * @brief Cortex-M85 External Coprocessor Interface
 *
 * @note Reference: Arm Cortex-M85 Devices Generic User Guide, Chapter 4.15
 * @note Reference: Arm Cortex-M85 Processor TRM, Chapter 13
 */

#ifndef CM85_COPROC_H
#define CM85_COPROC_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Coprocessor Access Control Register (CPACR) bits */
#define CM85_CPACR_CP0_Pos      0U
#define CM85_CPACR_CP0_Msk      (0x3UL << CM85_CPACR_CP0_Pos)
#define CM85_CPACR_CP1_Pos      2U
#define CM85_CPACR_CP1_Msk      (0x3UL << CM85_CPACR_CP1_Pos)
#define CM85_CPACR_CP2_Pos      4U
#define CM85_CPACR_CP2_Msk      (0x3UL << CM85_CPACR_CP2_Pos)
#define CM85_CPACR_CP3_Pos      6U
#define CM85_CPACR_CP3_Msk      (0x3UL << CM85_CPACR_CP3_Pos)
#define CM85_CPACR_CP4_Pos      8U
#define CM85_CPACR_CP4_Msk      (0x3UL << CM85_CPACR_CP4_Pos)
#define CM85_CPACR_CP5_Pos      10U
#define CM85_CPACR_CP5_Msk      (0x3UL << CM85_CPACR_CP5_Pos)
#define CM85_CPACR_CP6_Pos      12U
#define CM85_CPACR_CP6_Msk      (0x3UL << CM85_CPACR_CP6_Pos)
#define CM85_CPACR_CP7_Pos      14U
#define CM85_CPACR_CP7_Msk      (0x3UL << CM85_CPACR_CP7_Pos)
#define CM85_CPACR_CP10_Pos     20U
#define CM85_CPACR_CP10_Msk     (0x3UL << CM85_CPACR_CP10_Pos)
#define CM85_CPACR_CP11_Pos     22U
#define CM85_CPACR_CP11_Msk     (0x3UL << CM85_CPACR_CP11_Pos)

/* Coprocessor access permissions */
typedef enum {
    CM85_COPROC_ACCESS_DENIED = 0,
    CM85_COPROC_ACCESS_PRIV = 1,
    CM85_COPROC_ACCESS_RESERVED = 2,
    CM85_COPROC_ACCESS_FULL = 3
} cm85_coproc_access_t;

/* Coprocessor initialization */
int cm85_coproc_init(void);
void cm85_coproc_deinit(void);

/* Coprocessor access control */
void cm85_coproc_set_access(uint32_t cp, cm85_coproc_access_t access);
cm85_coproc_access_t cm85_coproc_get_access(uint32_t cp);
void cm85_coproc_enable(uint32_t cp);
void cm85_coproc_disable(uint32_t cp);
bool cm85_coproc_is_enabled(uint32_t cp);

/* Coprocessor data transfer (CDP/CDP2) */
uint32_t cm85_coproc_cdp(uint32_t cp, uint32_t opc1, uint32_t opc2, uint32_t crn, uint32_t crm);
void cm85_coproc_cdp2(uint32_t cp, uint32_t opc1, uint32_t opc2, uint32_t crn, uint32_t crm, uint32_t data);

/* Move to coprocessor (MCR/MCR2) */
void cm85_coproc_mcr(uint32_t cp, uint32_t opc1, uint32_t opc2, uint32_t crn, uint32_t crm, uint32_t value);
void cm85_coproc_mcr2(uint32_t cp, uint32_t opc1, uint32_t opc2, uint32_t crn, uint32_t crm, uint32_t value);

/* Move from coprocessor (MRC/MRC2) */
uint32_t cm85_coproc_mrc(uint32_t cp, uint32_t opc1, uint32_t opc2, uint32_t crn, uint32_t crm);
uint32_t cm85_coproc_mrc2(uint32_t cp, uint32_t opc1, uint32_t opc2, uint32_t crn, uint32_t crm);

/* Load coprocessor (LDC/LDC2) */
void cm85_coproc_ldc(uint32_t cp, uint32_t crd, const void *addr);
void cm85_coproc_ldc2(uint32_t cp, uint32_t crd, const void *addr);

/* Store coprocessor (STC/STC2) */
void cm85_coproc_stc(uint32_t cp, uint32_t crd, void *addr);
void cm85_coproc_stc2(uint32_t cp, uint32_t crd, void *addr);

/* Feature detection */
bool cm85_coproc_is_present(uint32_t cp);

#ifdef __cplusplus
}
#endif

#endif /* CM85_COPROC_H */
