/*
 * cm55_mpu.h
 * Cortex-M55 Memory Protection Unit (MPU) Definitions
 * Reference: Cortex-M55 Technical Reference Manual, Chapter 9, 13
 */

#ifndef CM55_MPU_H
#define CM55_MPU_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * MPU Type Definitions
 *============================================================================*/

typedef struct {
    volatile const uint32_t TYPE;
    volatile uint32_t CTRL;
    volatile uint32_t RNR;
    volatile uint32_t RBAR;
    volatile uint32_t RLAR;
    volatile uint32_t RBAR_A1;
    volatile uint32_t RLAR_A1;
    volatile uint32_t RBAR_A2;
    volatile uint32_t RLAR_A2;
    volatile uint32_t RBAR_A3;
    volatile uint32_t RLAR_A3;
    uint32_t RESERVED0[1];
    volatile uint32_t MAIR0;
    volatile uint32_t MAIR1;
} cm55_mpu_regs_t;

/*============================================================================*
 * MPU Region Size Definitions
 *============================================================================*/

#define CM55_MPU_REGION_SIZE_32B        0x04
#define CM55_MPU_REGION_SIZE_64B        0x05
#define CM55_MPU_REGION_SIZE_128B       0x06
#define CM55_MPU_REGION_SIZE_256B       0x07
#define CM55_MPU_REGION_SIZE_512B       0x08
#define CM55_MPU_REGION_SIZE_1KB        0x09
#define CM55_MPU_REGION_SIZE_2KB        0x0A
#define CM55_MPU_REGION_SIZE_4KB        0x0B
#define CM55_MPU_REGION_SIZE_8KB        0x0C
#define CM55_MPU_REGION_SIZE_16KB       0x0D
#define CM55_MPU_REGION_SIZE_32KB       0x0E
#define CM55_MPU_REGION_SIZE_64KB       0x0F
#define CM55_MPU_REGION_SIZE_128KB      0x10
#define CM55_MPU_REGION_SIZE_256KB      0x11
#define CM55_MPU_REGION_SIZE_512KB      0x12
#define CM55_MPU_REGION_SIZE_1MB        0x13
#define CM55_MPU_REGION_SIZE_2MB        0x14
#define CM55_MPU_REGION_SIZE_4MB        0x15
#define CM55_MPU_REGION_SIZE_8MB        0x16
#define CM55_MPU_REGION_SIZE_16MB       0x17
#define CM55_MPU_REGION_SIZE_32MB       0x18
#define CM55_MPU_REGION_SIZE_64MB       0x19
#define CM55_MPU_REGION_SIZE_128MB      0x1A
#define CM55_MPU_REGION_SIZE_256MB      0x1B
#define CM55_MPU_REGION_SIZE_512MB      0x1C
#define CM55_MPU_REGION_SIZE_1GB        0x1D
#define CM55_MPU_REGION_SIZE_2GB        0x1E
#define CM55_MPU_REGION_SIZE_4GB        0x1F

/*============================================================================*
 * MPU API Functions (Template)
 *============================================================================*/

void cm55_mpu_enable(void);
void cm55_mpu_disable(void);
uint32_t cm55_mpu_get_region_count(void);
void cm55_mpu_select_region(uint32_t region_num);
void cm55_mpu_set_region(uint32_t base_addr, uint32_t limit_addr, uint32_t attrs);
void cm55_mpu_disable_region(uint32_t region_num);
void cm55_mpu_set_mair(uint32_t attr_idx, uint32_t attr);
uint32_t cm55_mpu_get_mair(uint32_t attr_idx);

/*============================================================================*
 * MPU Security Functions (Template) - TrustZone
 *============================================================================*/

void cm55_mpu_enable_s(void);
void cm55_mpu_disable_s(void);
void cm55_mpu_set_region_s(uint32_t base_addr, uint32_t limit_addr, uint32_t attrs);

#ifdef __cplusplus
}
#endif

#endif /* CM55_MPU_H */
