/*
 * cm55_cache.h
 * Cortex-M55 Cache Maintenance Operations Definitions
 * Reference: Cortex-M55 Technical Reference Manual, Chapter 5, 10
 */

#ifndef CM55_CACHE_H
#define CM55_CACHE_H

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
} cm55_cache_regs_t;

/*============================================================================*
 * Cache Size ID Register Type
 *============================================================================*/

typedef struct {
    volatile const uint32_t CCSIDR;
    volatile uint32_t CSSELR;
} cm55_cache_id_regs_t;

/*============================================================================*
 * Cache API Functions (Template)
 *============================================================================*/

/* I-Cache Operations */
void cm55_iciallu(void);
void cm55_icimvau(uint32_t addr);
void cm55_icache_enable(void);
void cm55_icache_disable(void);
void cm55_icache_invalidate_all(void);
void cm55_icache_invalidate_line(uint32_t addr);

/* D-Cache Operations */
void cm55_dcimvac(uint32_t addr);
void cm55_dcisw(uint32_t set_way);
void cm55_dccmvau(uint32_t addr);
void cm55_dccmvac(uint32_t addr);
void cm55_dccsw(uint32_t set_way);
void cm55_dccimvac(uint32_t addr);
void cm55_dccisw(uint32_t set_way);
void cm55_dcache_enable(void);
void cm55_dcache_disable(void);
void cm55_dcache_invalidate_all(void);
void cm55_dcache_clean_all(void);
void cm55_dcache_clean_invalidate_all(void);
void cm55_dcache_invalidate_line(uint32_t addr);
void cm55_dcache_clean_line(uint32_t addr);
void cm55_dcache_clean_invalidate_line(uint32_t addr);

/* Cache ID Functions */
uint32_t cm55_cache_get_ccsidr(void);
void cm55_cache_set_csselr(uint32_t level);
uint32_t cm55_cache_get_csselr(void);

/* Branch Cache Operations */
void cm55_bpiall(void);
void cm55_bpimva(uint32_t addr);

#ifdef __cplusplus
}
#endif

#endif /* CM55_CACHE_H */
