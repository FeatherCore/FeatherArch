/*
 * cm7_mpu.h
 * Cortex-M7 Memory Protection Unit (MPU) Definitions
 * Reference: Cortex-M7 Devices Generic User Guide, Chapter 4.6
 *            Cortex-M7 Technical Reference Manual, Chapter 6
 */

#ifndef CM7_MPU_H
#define CM7_MPU_H

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
    volatile uint32_t RASR;
} cm7_mpu_regs_t;

/*============================================================================*
 * MPU Region Size Definitions
 *============================================================================*/

#define CM7_MPU_REGION_SIZE_32B     0x04
#define CM7_MPU_REGION_SIZE_64B     0x05
#define CM7_MPU_REGION_SIZE_128B    0x06
#define CM7_MPU_REGION_SIZE_256B    0x07
#define CM7_MPU_REGION_SIZE_512B    0x08
#define CM7_MPU_REGION_SIZE_1KB     0x09
#define CM7_MPU_REGION_SIZE_2KB     0x0A
#define CM7_MPU_REGION_SIZE_4KB     0x0B
#define CM7_MPU_REGION_SIZE_8KB     0x0C
#define CM7_MPU_REGION_SIZE_16KB    0x0D
#define CM7_MPU_REGION_SIZE_32KB    0x0E
#define CM7_MPU_REGION_SIZE_64KB    0x0F
#define CM7_MPU_REGION_SIZE_128KB   0x10
#define CM7_MPU_REGION_SIZE_256KB   0x11
#define CM7_MPU_REGION_SIZE_512KB   0x12
#define CM7_MPU_REGION_SIZE_1MB     0x13
#define CM7_MPU_REGION_SIZE_2MB     0x14
#define CM7_MPU_REGION_SIZE_4MB     0x15
#define CM7_MPU_REGION_SIZE_8MB     0x16
#define CM7_MPU_REGION_SIZE_16MB    0x17
#define CM7_MPU_REGION_SIZE_32MB    0x18
#define CM7_MPU_REGION_SIZE_64MB    0x19
#define CM7_MPU_REGION_SIZE_128MB   0x1A
#define CM7_MPU_REGION_SIZE_256MB   0x1B
#define CM7_MPU_REGION_SIZE_512MB   0x1C
#define CM7_MPU_REGION_SIZE_1GB     0x1D
#define CM7_MPU_REGION_SIZE_2GB     0x1E
#define CM7_MPU_REGION_SIZE_4GB     0x1F

/*============================================================================*
 * MPU Access Permission Definitions
 *============================================================================*/

#define CM7_MPU_AP_NONE             0x00
#define CM7_MPU_AP_PRIV_RW          0x01
#define CM7_MPU_AP_PRIV_RW_USER_RO  0x02
#define CM7_MPU_AP_FULL_ACCESS      0x03
#define CM7_MPU_AP_PRIV_RO          0x05
#define CM7_MPU_AP_RO               0x06

/*============================================================================*
 * MPU API Functions (Template)
 *============================================================================*/

void cm7_mpu_enable(void);
void cm7_mpu_disable(void);
uint32_t cm7_mpu_get_region_count(void);
void cm7_mpu_select_region(uint32_t region_num);
void cm7_mpu_set_region(uint32_t base_addr, uint32_t size, uint32_t attrs);
void cm7_mpu_disable_region(uint32_t region_num);

#ifdef __cplusplus
}
#endif

#endif /* CM7_MPU_H */
