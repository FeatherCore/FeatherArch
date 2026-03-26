/*
 * arm_v7m_cm7_cache.h
 * Cortex-M7 Cache Maintenance Operations Definitions
 * Reference: Cortex-M7 Devices Generic User Guide, Chapter 4.8
 *            Cortex-M7 Technical Reference Manual, Chapter 5.9
 */

#ifndef ARM_V7M_CM7_CACHE_H
#define ARM_V7M_CM7_CACHE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Cache Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t ICIALLU;
    volatile uint32_t ICIMVAU;
    volatile uint32_t DCIMVAC;
    volatile uint32_t DCISW;
    volatile uint32_t DCCMVAU;
    volatile uint32_t DCCMVAC;
    volatile uint32_t DCCSW;
    volatile uint32_t DCCIMVAC;
    volatile uint32_t DCCISW;
} arm_v7m_cm7_cache_regs_t;

/*============================================================================*
 * Cache Size ID Register Type
 *============================================================================*/

typedef struct {
    volatile const uint32_t CCSIDR;
    volatile uint32_t CSSELR;
} arm_v7m_cm7_cache_id_regs_t;

/*============================================================================*
 * Cache API Functions (Template)
 *============================================================================*/

/* I-Cache Operations */
void arm_v7m_cm7_iciallu(void);
void arm_v7m_cm7_icimvau(uint32_t addr);
void arm_v7m_cm7_icache_enable(void);
void arm_v7m_cm7_icache_disable(void);
void arm_v7m_cm7_icache_invalidate_all(void);
void arm_v7m_cm7_icache_invalidate_line(uint32_t addr);

/* D-Cache Operations */
void arm_v7m_cm7_dcimvac(uint32_t addr);
void arm_v7m_cm7_dcisw(uint32_t set_way);
void arm_v7m_cm7_dccmvau(uint32_t addr);
void arm_v7m_cm7_dccmvac(uint32_t addr);
void arm_v7m_cm7_dccsw(uint32_t set_way);
void arm_v7m_cm7_dccimvac(uint32_t addr);
void arm_v7m_cm7_dccisw(uint32_t set_way);
void arm_v7m_cm7_dcache_enable(void);
void arm_v7m_cm7_dcache_disable(void);
void arm_v7m_cm7_dcache_invalidate_all(void);
void arm_v7m_cm7_dcache_clean_all(void);
void arm_v7m_cm7_dcache_clean_invalidate_all(void);
void arm_v7m_cm7_dcache_invalidate_line(uint32_t addr);
void arm_v7m_cm7_dcache_clean_line(uint32_t addr);
void arm_v7m_cm7_dcache_clean_invalidate_line(uint32_t addr);

/* Cache ID Functions */
uint32_t arm_v7m_cm7_cache_get_ccsidr(void);
void arm_v7m_cm7_cache_set_csselr(uint32_t level);
uint32_t arm_v7m_cm7_cache_get_csselr(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V7M_CM7_CACHE_H */
