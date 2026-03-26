/**
 * @file arm_v8m_cm85_mve.h
 * @brief Cortex-M85 MVE (Helium) Vector Extension
 *
 * @note Reference: Arm Cortex-M85 Devices Generic User Guide, Chapter 3.7, 4.24-4.32
 * @note Reference: Arm Cortex-M85 Processor TRM, Chapter 15
 */

#ifndef ARM_V8M_CM85_MVE_H
#define ARM_V8M_CM85_MVE_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Vector register type (128-bit) */
typedef struct {
    uint32_t val[4];
} arm_v8m_cm85_vec128_t;

/* VPR (Vector Predication Register) */
#define ARM_V8M_CM85_VPR_BASE       (0xE000EF38UL)
#define ARM_V8M_CM85_VPR            (*(volatile uint32_t *)ARM_V8M_CM85_VPR_BASE)

/* VPR bit definitions */
#define ARM_V8M_CM85_VPR_P0_Pos             0U
#define ARM_V8M_CM85_VPR_P0_Msk             (0xFFFFUL << ARM_V8M_CM85_VPR_P0_Pos)
#define ARM_V8M_CM85_VPR_MASK_Pos           16U
#define ARM_V8M_CM85_VPR_MASK_Msk           (0xFUL << ARM_V8M_CM85_VPR_MASK_Pos)

/* MVE feature types */
typedef enum {
    ARM_V8M_CM85_MVE_TYPE_NONE = 0,
    ARM_V8M_CM85_MVE_TYPE_INTEGER = 1,
    ARM_V8M_CM85_MVE_TYPE_FLOAT = 2
} arm_v8m_cm85_mve_type_t;

/* MVE initialization and control */
int arm_v8m_cm85_mve_init(void);
void arm_v8m_cm85_mve_deinit(void);
void arm_v8m_cm85_mve_enable(void);
void arm_v8m_cm85_mve_disable(void);
bool arm_v8m_cm85_mve_is_enabled(void);

/* MVE feature detection */
bool arm_v8m_cm85_mve_is_present(void);
arm_v8m_cm85_mve_type_t arm_v8m_cm85_mve_get_type(void);
bool arm_v8m_cm85_mve_has_int(void);
bool arm_v8m_cm85_mve_has_fp(void);

/* Vector predication */
uint32_t arm_v8m_cm85_mve_get_vpr(void);
void arm_v8m_cm85_mve_set_vpr(uint32_t vpr);
void arm_v8m_cm85_mve_set_predication(uint16_t mask);
uint16_t arm_v8m_cm85_mve_get_predication(void);

/* Low Overhead Loop (LOL) registers */
void arm_v8m_cm85_mve_set_lpstart(uint32_t addr);
uint32_t arm_v8m_cm85_mve_get_lpstart(void);
void arm_v8m_cm85_mve_set_lpend(uint32_t addr);
uint32_t arm_v8m_cm85_mve_get_lpend(void);
void arm_v8m_cm85_mve_set_lpcnt(uint32_t count);
uint32_t arm_v8m_cm85_mve_get_lpcnt(void);

/* Tail predication */
void arm_v8m_cm85_mve_set_tail_predication(uint32_t elements);
uint32_t arm_v8m_cm85_mve_get_tail_predication(void);

/* ECI (Exception Continuation Information) handling */
uint32_t arm_v8m_cm85_mve_get_eci(void);
void arm_v8m_cm85_mve_set_eci(uint32_t eci);

/* Vector load/store with predication */
void arm_v8m_cm85_mve_vldrb(uint8_t *dst, const uint8_t *src, uint32_t count);
void arm_v8m_cm85_mve_vldrh(uint16_t *dst, const uint16_t *src, uint32_t count);
void arm_v8m_cm85_mve_vldrw(uint32_t *dst, const uint32_t *src, uint32_t count);
void arm_v8m_cm85_mve_vstrb(uint8_t *dst, const uint8_t *src, uint32_t count);
void arm_v8m_cm85_mve_vstrh(uint16_t *dst, const uint16_t *src, uint32_t count);
void arm_v8m_cm85_mve_vstrw(uint32_t *dst, const uint32_t *src, uint32_t count);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM85_MVE_H */
