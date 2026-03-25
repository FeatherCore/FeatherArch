/*
 * armv7m_mpu.h
 * Memory Protection Unit (MPU) Definitions
 * Reference: ARMv7-M Architecture Reference Manual, Section B3.5 (PMSAv7)
 */

#ifndef ARMV7M_MPU_H
#define ARMV7M_MPU_H

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
} armv7m_mpu_regs_t;

/*============================================================================*
 * MPU Region Attribute Definitions
 *============================================================================*/

#define ARMV7M_MPU_AP_NONE          0x00
#define ARMV7M_MPU_AP_PRIV_RW       0x01
#define ARMV7M_MPU_AP_PRIV_RW_USER_RO 0x02
#define ARMV7M_MPU_AP_FULL_ACCESS   0x03
#define ARMV7M_MPU_AP_PRIV_RO       0x05
#define ARMV7M_MPU_AP_RO            0x06

#define ARMV7M_MPU_ATTR_STRONGLY_ORDERED 0x00
#define ARMV7M_MPU_ATTR_DEVICE_SHARED    0x01
#define ARMV7M_MPU_ATTR_DEVICE           0x02
#define ARMV7M_MPU_ATTR_NORMAL           0x04

/*============================================================================*
 * MPU API Functions (Template)
 *============================================================================*/

void armv7m_mpu_enable(void);
void armv7m_mpu_disable(void);
uint32_t armv7m_mpu_get_region_count(void);
void armv7m_mpu_select_region(uint32_t region_num);
void armv7m_mpu_set_region(uint32_t base_addr, uint32_t size, uint32_t attrs);
void armv7m_mpu_disable_region(uint32_t region_num);

#ifdef __cplusplus
}
#endif

#endif /* ARMV7M_MPU_H */
