/**
 * @file cm85_mve.h
 * @brief Cortex-M85 MVE (Helium) Vector Extension
 *
 * @note Reference: Arm Cortex-M85 Devices Generic User Guide, Chapter 3.7, 4.24-4.32
 * @note Reference: Arm Cortex-M85 Processor TRM, Chapter 15
 */

#ifndef CM85_MVE_H
#define CM85_MVE_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Vector register type (128-bit) */
typedef struct {
    uint32_t val[4];
} cm85_vec128_t;

/* VPR (Vector Predication Register) */
#define CM85_VPR_BASE       (0xE000EF38UL)
#define CM85_VPR            (*(volatile uint32_t *)CM85_VPR_BASE)

/* VPR bit definitions */
#define CM85_VPR_P0_Pos             0U
#define CM85_VPR_P0_Msk             (0xFFFFUL << CM85_VPR_P0_Pos)
#define CM85_VPR_MASK_Pos           16U
#define CM85_VPR_MASK_Msk           (0xFUL << CM85_VPR_MASK_Pos)

/* MVE feature types */
typedef enum {
    CM85_MVE_TYPE_NONE = 0,
    CM85_MVE_TYPE_INTEGER = 1,
    CM85_MVE_TYPE_FLOAT = 2
} cm85_mve_type_t;

/* MVE initialization and control */
int cm85_mve_init(void);
void cm85_mve_deinit(void);
void cm85_mve_enable(void);
void cm85_mve_disable(void);
bool cm85_mve_is_enabled(void);

/* MVE feature detection */
bool cm85_mve_is_present(void);
cm85_mve_type_t cm85_mve_get_type(void);
bool cm85_mve_has_int(void);
bool cm85_mve_has_fp(void);

/* Vector predication */
uint32_t cm85_mve_get_vpr(void);
void cm85_mve_set_vpr(uint32_t vpr);
void cm85_mve_set_predication(uint16_t mask);
uint16_t cm85_mve_get_predication(void);

/* Low Overhead Loop (LOL) registers */
void cm85_mve_set_lpstart(uint32_t addr);
uint32_t cm85_mve_get_lpstart(void);
void cm85_mve_set_lpend(uint32_t addr);
uint32_t cm85_mve_get_lpend(void);
void cm85_mve_set_lpcnt(uint32_t count);
uint32_t cm85_mve_get_lpcnt(void);

/* Tail predication */
void cm85_mve_set_tail_predication(uint32_t elements);
uint32_t cm85_mve_get_tail_predication(void);

/* ECI (Exception Continuation Information) handling */
uint32_t cm85_mve_get_eci(void);
void cm85_mve_set_eci(uint32_t eci);

/* Vector load/store with predication */
void cm85_mve_vldrb(uint8_t *dst, const uint8_t *src, uint32_t count);
void cm85_mve_vldrh(uint16_t *dst, const uint16_t *src, uint32_t count);
void cm85_mve_vldrw(uint32_t *dst, const uint32_t *src, uint32_t count);
void cm85_mve_vstrb(uint8_t *dst, const uint8_t *src, uint32_t count);
void cm85_mve_vstrh(uint16_t *dst, const uint16_t *src, uint32_t count);
void cm85_mve_vstrw(uint32_t *dst, const uint32_t *src, uint32_t count);

#ifdef __cplusplus
}
#endif

#endif /* CM85_MVE_H */
