/*
 * arm_v8m_cm33_mpu.h
 * Cortex-M33 Memory Protection Unit (MPU) Definitions
 * Reference: Cortex-M33 Technical Reference Manual, Chapter 4
 *
 * @note This file reuses Armv8-M generic MPU definitions.
 */

#ifndef ARM_V8M_CM33_MPU_H
#define ARM_V8M_CM33_MPU_H

#include <stdint.h>
#include "../armv8m_mpu.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Type Aliases
 *============================================================================*/

typedef arm_v8m_mpu_regs_t      arm_v8m_cm33_mpu_regs_t;

/*============================================================================*
 * Constant Aliases - Region Size Definitions
 *============================================================================*/

#define ARM_V8M_CM33_MPU_REGION_SIZE_32B        ARM_V8M_MPU_REGION_SIZE_32B
#define ARM_V8M_CM33_MPU_REGION_SIZE_64B        ARM_V8M_MPU_REGION_SIZE_64B
#define ARM_V8M_CM33_MPU_REGION_SIZE_128B       ARM_V8M_MPU_REGION_SIZE_128B
#define ARM_V8M_CM33_MPU_REGION_SIZE_256B       ARM_V8M_MPU_REGION_SIZE_256B
#define ARM_V8M_CM33_MPU_REGION_SIZE_512B       ARM_V8M_MPU_REGION_SIZE_512B
#define ARM_V8M_CM33_MPU_REGION_SIZE_1KB        ARM_V8M_MPU_REGION_SIZE_1KB
#define ARM_V8M_CM33_MPU_REGION_SIZE_2KB        ARM_V8M_MPU_REGION_SIZE_2KB
#define ARM_V8M_CM33_MPU_REGION_SIZE_4KB        ARM_V8M_MPU_REGION_SIZE_4KB
#define ARM_V8M_CM33_MPU_REGION_SIZE_8KB        ARM_V8M_MPU_REGION_SIZE_8KB
#define ARM_V8M_CM33_MPU_REGION_SIZE_16KB       ARM_V8M_MPU_REGION_SIZE_16KB
#define ARM_V8M_CM33_MPU_REGION_SIZE_32KB       ARM_V8M_MPU_REGION_SIZE_32KB
#define ARM_V8M_CM33_MPU_REGION_SIZE_64KB       ARM_V8M_MPU_REGION_SIZE_64KB
#define ARM_V8M_CM33_MPU_REGION_SIZE_128KB      ARM_V8M_MPU_REGION_SIZE_128KB
#define ARM_V8M_CM33_MPU_REGION_SIZE_256KB      ARM_V8M_MPU_REGION_SIZE_256KB
#define ARM_V8M_CM33_MPU_REGION_SIZE_512KB      ARM_V8M_MPU_REGION_SIZE_512KB
#define ARM_V8M_CM33_MPU_REGION_SIZE_1MB        ARM_V8M_MPU_REGION_SIZE_1MB
#define ARM_V8M_CM33_MPU_REGION_SIZE_2MB        ARM_V8M_MPU_REGION_SIZE_2MB
#define ARM_V8M_CM33_MPU_REGION_SIZE_4MB        ARM_V8M_MPU_REGION_SIZE_4MB
#define ARM_V8M_CM33_MPU_REGION_SIZE_8MB        ARM_V8M_MPU_REGION_SIZE_8MB
#define ARM_V8M_CM33_MPU_REGION_SIZE_16MB       ARM_V8M_MPU_REGION_SIZE_16MB
#define ARM_V8M_CM33_MPU_REGION_SIZE_32MB       ARM_V8M_MPU_REGION_SIZE_32MB
#define ARM_V8M_CM33_MPU_REGION_SIZE_64MB       ARM_V8M_MPU_REGION_SIZE_64MB
#define ARM_V8M_CM33_MPU_REGION_SIZE_128MB      ARM_V8M_MPU_REGION_SIZE_128MB
#define ARM_V8M_CM33_MPU_REGION_SIZE_256MB      ARM_V8M_MPU_REGION_SIZE_256MB
#define ARM_V8M_CM33_MPU_REGION_SIZE_512MB      ARM_V8M_MPU_REGION_SIZE_512MB
#define ARM_V8M_CM33_MPU_REGION_SIZE_1GB        ARM_V8M_MPU_REGION_SIZE_1GB
#define ARM_V8M_CM33_MPU_REGION_SIZE_2GB        ARM_V8M_MPU_REGION_SIZE_2GB
#define ARM_V8M_CM33_MPU_REGION_SIZE_4GB        ARM_V8M_MPU_REGION_SIZE_4GB

/*============================================================================*
 * Inline Function Wrappers - MPU Operations
 *============================================================================*/

static inline void arm_v8m_cm33_mpu_enable(void) {
    arm_v8m_mpu_enable();
}

static inline void arm_v8m_cm33_mpu_disable(void) {
    arm_v8m_mpu_disable();
}

static inline uint32_t arm_v8m_cm33_mpu_get_region_count(void) {
    return arm_v8m_mpu_get_region_count();
}

static inline void arm_v8m_cm33_mpu_select_region(uint32_t region_num) {
    arm_v8m_mpu_select_region(region_num);
}

static inline void arm_v8m_cm33_mpu_set_region(uint32_t base_addr, uint32_t limit_addr, uint32_t attrs) {
    arm_v8m_mpu_set_region(base_addr, limit_addr, attrs);
}

static inline void arm_v8m_cm33_mpu_disable_region(uint32_t region_num) {
    arm_v8m_mpu_disable_region(region_num);
}

static inline void arm_v8m_cm33_mpu_set_mair(uint32_t attr_idx, uint32_t attr) {
    arm_v8m_mpu_set_mair(attr_idx, attr);
}

static inline uint32_t arm_v8m_cm33_mpu_get_mair(uint32_t attr_idx) {
    return arm_v8m_mpu_get_mair(attr_idx);
}

/*============================================================================*
 * Security Functions - TrustZone
 *============================================================================*/

static inline void arm_v8m_cm33_mpu_enable_s(void) {
    arm_v8m_mpu_enable_s();
}

static inline void arm_v8m_cm33_mpu_disable_s(void) {
    arm_v8m_mpu_disable_s();
}

static inline void arm_v8m_cm33_mpu_set_region_s(uint32_t base_addr, uint32_t limit_addr, uint32_t attrs) {
    arm_v8m_mpu_set_region_s(base_addr, limit_addr, attrs);
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM33_MPU_H */
