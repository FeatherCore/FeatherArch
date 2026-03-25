/**
 * @file cm85.h
 * @brief Cortex-M85 processor abstraction layer main header
 *
 * @note Reference: Arm Cortex-M85 Devices Generic User Guide (101928_0101_07_en)
 * @note Reference: Arm Cortex-M85 Processor Technical Reference Manual (101924_0101_07_en)
 * @note Architecture: Armv8.1-M with MVE (Helium), RAS, PMU, PACBTI extensions
 */

#ifndef CM85_H
#define CM85_H

#include <stdint.h>
#include <stdbool.h>

/* Core component headers */
#include "cm85_core.h"
#include "cm85_nvic.h"
#include "cm85_systick.h"
#include "cm85_scb.h"
#include "cm85_mpu.h"
#include "cm85_sau.h"
#include "cm85_cache.h"
#include "cm85_tcm.h"
#include "cm85_fpu.h"
#include "cm85_epu.h"
#include "cm85_mve.h"
#include "cm85_ras.h"
#include "cm85_pmu.h"
#include "cm85_pacbti.h"
#include "cm85_pwr.h"
#include "cm85_debug.h"
#include "cm85_coproc.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Cortex-M85 processor initialization */
int cm85_init(void);

/* Processor feature detection */
bool cm85_has_mve(void);
bool cm85_has_mve_fp(void);
bool cm85_has_mve_int(void);
bool cm85_has_fpu(void);
bool cm85_has_ras(void);
bool cm85_has_pmu(void);
bool cm85_has_pacbti(void);
bool cm85_has_cache(void);
bool cm85_has_itcm(void);
bool cm85_has_dtcm(void);

/* Security state management */
typedef enum {
    CM85_SECURITY_NON_SECURE = 0,
    CM85_SECURITY_SECURE = 1
} cm85_security_state_t;

cm85_security_state_t cm85_get_security_state(void);
bool cm85_is_secure(void);

/* Processor reset and system control */
void cm85_system_reset(void);
void cm85_system_reset_secure(void);

/* Wait for interrupt/event */
void cm85_wfi(void);
void cm85_wfe(void);
void cm85_sev(void);

/* Data and instruction barriers */
void cm85_dmb(void);
void cm85_dsb(void);
void cm85_isb(void);

/* Memory attribute helpers */
#define CM85_MEMORY_DEVICE        0x00
#define CM85_MEMORY_NORMAL        0x01
#define CM85_MEMORY_NORMAL_WT     0x02
#define CM85_MEMORY_NORMAL_WB     0x03

/* Cacheability attributes */
#define CM85_CACHE_NON_CACHEABLE  0x00
#define CM85_CACHE_WT             0x01
#define CM85_CACHE_WB             0x02

/* Shareability attributes */
#define CM85_SHARE_NON_SHAREABLE  0x00
#define CM85_SHARE_OUTER          0x01
#define CM85_SHARE_INNER          0x02

#ifdef __cplusplus
}
#endif

#endif /* CM85_H */
