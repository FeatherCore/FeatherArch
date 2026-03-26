/*
 * arm_v8m_cache.h
 * Armv8-M Cache Maintenance Operations Definitions
 * Reference: Armv8-M Architecture Reference Manual, Chapter B7
 */

#ifndef ARM_V8M_CACHE_H
#define ARM_V8M_CACHE_H

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
} arm_v8m_cache_regs_t;

/*============================================================================*
 * Cache Size ID Register Type
 *============================================================================*/

typedef struct {
    volatile const uint32_t CCSIDR;
    volatile uint32_t CSSELR;
} arm_v8m_cache_id_regs_t;

/*============================================================================*
 * Cache API Functions (Template)
 *============================================================================*/

/* I-Cache Operations */
void arm_v8m_iciallu(void);
void arm_v8m_icimvau(uint32_t addr);
void arm_v8m_icache_enable(void);
void arm_v8m_icache_disable(void);
void arm_v8m_icache_invalidate_all(void);
void arm_v8m_icache_invalidate_line(uint32_t addr);

/* D-Cache Operations */
void arm_v8m_dcimvac(uint32_t addr);
void arm_v8m_dcisw(uint32_t set_way);
void arm_v8m_dccmvau(uint32_t addr);
void arm_v8m_dccmvac(uint32_t addr);
void arm_v8m_dccsw(uint32_t set_way);
void arm_v8m_dccimvac(uint32_t addr);
void arm_v8m_dccisw(uint32_t set_way);
void arm_v8m_dcache_enable(void);
void arm_v8m_dcache_disable(void);
void arm_v8m_dcache_invalidate_all(void);
void arm_v8m_dcache_clean_all(void);
void arm_v8m_dcache_clean_invalidate_all(void);
void arm_v8m_dcache_invalidate_line(uint32_t addr);
void arm_v8m_dcache_clean_line(uint32_t addr);
void arm_v8m_dcache_clean_invalidate_line(uint32_t addr);

/* Cache ID Functions */
uint32_t arm_v8m_cache_get_ccsidr(void);
void arm_v8m_cache_set_csselr(uint32_t level);
uint32_t arm_v8m_cache_get_csselr(void);

/* Branch Predictor Operations */
void arm_v8m_bpiall(void);
void arm_v8m_bpimva(uint32_t addr);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CACHE_H */
