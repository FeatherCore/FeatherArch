/**
 * @file cm85_cache.h
 * @brief Cortex-M85 Cache maintenance operations
 *
 * @note Reference: Arm Cortex-M85 Devices Generic User Guide, Chapter 5.5
 * @note Reference: Arm Cortex-M85 Processor TRM, Chapter 10.9
 */

#ifndef CM85_CACHE_H
#define CM85_CACHE_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Cache maintenance register structure */
typedef struct {
    volatile uint32_t ICIALLU;      /* I-Cache Invalidate All to PoU */
    uint32_t RESERVED0;
    volatile uint32_t ICIMVAU;      /* I-Cache line Invalidate by Address to PoU */
    uint32_t RESERVED1[2];
    volatile uint32_t DCIMVAC;      /* D-Cache line Invalidate by Address to PoC */
    volatile uint32_t DCISW;        /* D-Cache line Invalidate by Set/Way */
    uint32_t RESERVED2[2];
    volatile uint32_t DCCMVAU;      /* D-Cache Clean line by Address to PoU */
    volatile uint32_t DCCMVAC;      /* D-Cache Clean line by Address to PoC */
    volatile uint32_t DCCSW;        /* D-Cache Clean line by Set/Way */
    volatile uint32_t DCCIMVAC;     /* D-Cache Clean and Invalidate line by Address to PoC */
    volatile uint32_t DCCISW;       /* D-Cache Clean and Invalidate line by Set/Way */
    uint32_t RESERVED3[6];
    volatile uint32_t BPIALL;       /* Branch Predictor Invalidate All */
} cm85_cache_reg_t;

#define CM85_CACHE_BASE     (0xE000EF50UL)
#define CM85_CACHE          ((cm85_cache_reg_t *)CM85_CACHE_BASE)

/* Cache Size Selection Register (CSSELR) */
#define CM85_CSSELR_BASE    (0xE000ED84UL)
#define CM85_CSSELR         (*(volatile uint32_t *)CM85_CSSELR_BASE)

/* Cache Size ID Register (CCSIDR) */
#define CM85_CCSIDR_BASE    (0xE000ED80UL)
#define CM85_CCSIDR         (*(volatile uint32_t *)CM85_CCSIDR_BASE)

/* Cache Level ID Register (CLIDR) */
#define CM85_CLIDR_BASE     (0xE000ED78UL)
#define CM85_CLIDR          (*(volatile uint32_t *)CM85_CLIDR_BASE)

/* Cache Type Register (CTR) */
#define CM85_CTR_BASE       (0xE000ED7CUL)
#define CM85_CTR            (*(volatile uint32_t *)CM85_CTR_BASE)

/* Cache enable/disable via SCB CCR */
void cm85_cache_enable_icache(void);
void cm85_cache_disable_icache(void);
bool cm85_cache_icache_enabled(void);

void cm85_cache_enable_dcache(void);
void cm85_cache_disable_dcache(void);
bool cm85_cache_dcache_enabled(void);

/* I-Cache maintenance */
void cm85_cache_iciallu(void);              /* Invalidate all I-cache */
void cm85_cache_icimvau(uint32_t addr);     /* Invalidate I-cache line by address */

/* D-Cache maintenance - Invalidate */
void cm85_cache_dcimvac(uint32_t addr);     /* Invalidate D-cache line by address to PoC */
void cm85_cache_dcisw(uint32_t setway);     /* Invalidate D-cache line by set/way */

/* D-Cache maintenance - Clean */
void cm85_cache_dccmvau(uint32_t addr);     /* Clean D-cache line by address to PoU */
void cm85_cache_dccmvac(uint32_t addr);     /* Clean D-cache line by address to PoC */
void cm85_cache_dccsw(uint32_t setway);     /* Clean D-cache line by set/way */

/* D-Cache maintenance - Clean and Invalidate */
void cm85_cache_dccimvac(uint32_t addr);    /* Clean and Invalidate D-cache line by address to PoC */
void cm85_cache_dccisw(uint32_t setway);    /* Clean and Invalidate D-cache line by set/way */

/* Cache maintenance by range */
void cm85_cache_invalidate_dcache_range(uint32_t addr, uint32_t size);
void cm85_cache_clean_dcache_range(uint32_t addr, uint32_t size);
void cm85_cache_clean_invalidate_dcache_range(uint32_t addr, uint32_t size);

/* Branch predictor maintenance */
void cm85_cache_bpiall(void);               /* Invalidate all branch predictors */
void cm85_cache_enable_branch_prediction(void);
void cm85_cache_disable_branch_prediction(void);

/* Cache information */
typedef struct {
    uint32_t linesize;
    uint32_t ways;
    uint32_t sets;
    uint32_t size;
} cm85_cache_info_t;

void cm85_cache_get_icache_info(cm85_cache_info_t *info);
void cm85_cache_get_dcache_info(cm85_cache_info_t *info);

/* Cache level information */
uint32_t cm85_cache_get_clidr(void);
uint32_t cm85_cache_get_ccsidr(uint32_t level, bool icache);
uint32_t cm85_cache_get_ctr(void);

/* Direct Cache Access (DCA) - Cortex-M85 specific */
void cm85_cache_dca_icache(uint32_t addr);
void cm85_cache_dca_dcache(uint32_t addr);

#ifdef __cplusplus
}
#endif

#endif /* CM85_CACHE_H */
