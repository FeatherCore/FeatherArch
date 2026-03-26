/*
 * arm_v8m_cm55_cache.h
 * Cortex-M55 Cache Control Definitions
 * Reference: Cortex-M55 Technical Reference Manual, Chapter 4
 *
 * @note Cortex-M55 has I-Cache and optional D-Cache.
 *       This is CM55 specific, not part of generic Armv8-M.
 */

#ifndef ARM_V8M_CM55_CACHE_H
#define ARM_V8M_CM55_CACHE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Cache Type Register (CTR) Definitions
 *============================================================================*/

#define ARM_V8M_CM55_CTR_DMINLINE_Pos       16U
#define ARM_V8M_CM55_CTR_DMINLINE_Msk       (0xFUL << ARM_V8M_CM55_CTR_DMINLINE_Pos)

#define ARM_V8M_CM55_CTR_IMINLINE_Pos       0U
#define ARM_V8M_CM55_CTR_IMINLINE_Msk       (0xFUL << ARM_V8M_CM55_CTR_IMINLINE_Pos)

/*============================================================================*
 * Cache Control Register (CCR) Definitions
 *============================================================================*/

#define ARM_V8M_CM55_CCR_DC_Pos             16U
#define ARM_V8M_CM55_CCR_DC_Msk             (1UL << ARM_V8M_CM55_CCR_DC_Pos)

#define ARM_V8M_CM55_CCR_IC_Pos             0U
#define ARM_V8M_CM55_CCR_IC_Msk             (1UL << ARM_V8M_CM55_CCR_IC_Pos)

/*============================================================================*
 * Cache Maintenance Operations
 *============================================================================*/

void arm_v8m_cm55_icache_enable(void);
void arm_v8m_cm55_icache_disable(void);
void arm_v8m_cm55_icache_invalidate_all(void);
void arm_v8m_cm55_icache_invalidate_range(uint32_t start_addr, uint32_t size);

void arm_v8m_cm55_dcache_enable(void);
void arm_v8m_cm55_dcache_disable(void);
void arm_v8m_cm55_dcache_invalidate_all(void);
void arm_v8m_cm55_dcache_invalidate_range(uint32_t start_addr, uint32_t size);
void arm_v8m_cm55_dcache_clean_all(void);
void arm_v8m_cm55_dcache_clean_range(uint32_t start_addr, uint32_t size);
void arm_v8m_cm55_dcache_clean_invalidate_all(void);
void arm_v8m_cm55_dcache_clean_invalidate_range(uint32_t start_addr, uint32_t size);

/*============================================================================*
 * Cache Information
 *============================================================================*/

uint32_t arm_v8m_cm55_cache_get_icache_line_size(void);
uint32_t arm_v8m_cm55_cache_get_dcache_line_size(void);
uint32_t arm_v8m_cm55_cache_has_dcache(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM55_CACHE_H */
