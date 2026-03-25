/*
 * cm4_mpu.h
 * Cortex-M4 Memory Protection Unit (MPU) Definitions
 * Reference: Cortex-M4 Devices Generic User Guide, Chapter 4.5
 *            Cortex-M4 Technical Reference Manual, Chapter 5
 */

#ifndef CM4_MPU_H
#define CM4_MPU_H

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
} cm4_mpu_regs_t;

/*============================================================================*
 * MPU Region Size Definitions
 *============================================================================*/

#define CM4_MPU_REGION_SIZE_32B     0x04
#define CM4_MPU_REGION_SIZE_64B     0x05
#define CM4_MPU_REGION_SIZE_128B    0x06
#define CM4_MPU_REGION_SIZE_256B    0x07
#define CM4_MPU_REGION_SIZE_512B    0x08
#define CM4_MPU_REGION_SIZE_1KB     0x09
#define CM4_MPU_REGION_SIZE_2KB     0x0A
#define CM4_MPU_REGION_SIZE_4KB     0x0B
#define CM4_MPU_REGION_SIZE_8KB     0x0C
#define CM4_MPU_REGION_SIZE_16KB    0x0D
#define CM4_MPU_REGION_SIZE_32KB    0x0E
#define CM4_MPU_REGION_SIZE_64KB    0x0F
#define CM4_MPU_REGION_SIZE_128KB   0x10
#define CM4_MPU_REGION_SIZE_256KB   0x11
#define CM4_MPU_REGION_SIZE_512KB   0x12
#define CM4_MPU_REGION_SIZE_1MB     0x13
#define CM4_MPU_REGION_SIZE_2MB     0x14
#define CM4_MPU_REGION_SIZE_4MB     0x15
#define CM4_MPU_REGION_SIZE_8MB     0x16
#define CM4_MPU_REGION_SIZE_16MB    0x17
#define CM4_MPU_REGION_SIZE_32MB    0x18
#define CM4_MPU_REGION_SIZE_64MB    0x19
#define CM4_MPU_REGION_SIZE_128MB   0x1A
#define CM4_MPU_REGION_SIZE_256MB   0x1B
#define CM4_MPU_REGION_SIZE_512MB   0x1C
#define CM4_MPU_REGION_SIZE_1GB     0x1D
#define CM4_MPU_REGION_SIZE_2GB     0x1E
#define CM4_MPU_REGION_SIZE_4GB     0x1F

/*============================================================================*
 * MPU Access Permission Definitions
 *============================================================================*/

#define CM4_MPU_AP_NONE             0x00
#define CM4_MPU_AP_PRIV_RW          0x01
#define CM4_MPU_AP_PRIV_RW_USER_RO 0x02
#define CM4_MPU_AP_FULL_ACCESS      0x03
#define CM4_MPU_AP_PRIV_RO          0x05
#define CM4_MPU_AP_RO               0x06

/*============================================================================*
 * MPU API Functions (Template)
 *============================================================================*/

void cm4_mpu_enable(void);
void cm4_mpu_disable(void);
uint32_t cm4_mpu_get_region_count(void);
void cm4_mpu_select_region(uint32_t region_num);
void cm4_mpu_set_region(uint32_t base_addr, uint32_t size, uint32_t attrs);
void cm4_mpu_disable_region(uint32_t region_num);

#ifdef __cplusplus
}
#endif

#endif /* CM4_MPU_H */
