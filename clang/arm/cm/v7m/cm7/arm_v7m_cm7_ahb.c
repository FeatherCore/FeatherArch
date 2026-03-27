/*
 * arm_v7m_cm7_ahb.c
 * Cortex-M7 AHB Interface Control Implementation
 * 
 * Reference: Cortex-M7 Devices Generic User Guide
 *            - Chapter 4.9: Access control on page 4-66
 *            - Section 4.9.2: AHBP Control Register on page 4-69
 *              * AHBPCR at address 0xE000EF98
 *            - Section 4.9.3: L1 Cache Control Register on page 4-70
 *              * CACR at address 0xE000EF9C
 *            - Section 4.9.4: AHB Slave Control Register on page 4-72
 *              * AHBSCR at address 0xE000EFA0
 *            - Section 4.9.5: Auxiliary Bus Fault Status register on page 4-73
 *              * ABFSR at address 0xE000EFA8
 * 
 *            Cortex-M7 Technical Reference Manual
 *            - Chapter 3: System Control on page 3-1
 *            - Section 3.2: Register summary on page 3-3
 *            - Section 3.3: Register descriptions on page 3-6
 *            - Chapter 5.6: AHB peripheral interface on page 5-25
 *            - Chapter 5.7: AHB slave interface on page 5-33
 * 
 *            ARMv7-M Architecture Reference Manual
 *            - Section A3.7.3: Memory barriers on page A3-81
 *            - Table B3-4: SCB registers summary (0xE000EF90-0xE000EFCF marked as IMPLEMENTATION DEFINED)
 * 
 * @note AHB interface control registers are Cortex-M7 specific and not part of 
 *       the base ARMv7-M architecture. The address range 0xE000EF98-0xE000EFA8 
 *       is IMPLEMENTATION DEFINED in ARMv7-M.
 * 
 * @note This file implements non-inline functions for Cortex-M7 AHB interface control.
 *       Simple register access functions are implemented as static inline in the header.
 */

#include "arm_v7m_cm7_ahb.h"

/*============================================================================*
 * AHBP Size Conversion
 *============================================================================*/

/**
 * @brief Get AHBP region size in MB
 * @return AHBP size in MB (0, 64, 128, 256, or 512)
 * @note Converts the SZ field value to actual size in MB.
 *       0 -> 0MB (disabled)
 *       1 -> 64MB
 *       2 -> 128MB
 *       3 -> 256MB
 *       4 -> 512MB
 *       Other values -> 0MB (reserved)
 * 
 * Reference: Cortex-M7 Devices Generic User Guide, Section 4.9.2 on page 4-69
 *            Table 4-70: AHBPCR bit assignments
 */
uint32_t arm_v7m_cm7_ahb_get_ahbp_size_mb(void)
{
    uint32_t sz = arm_v7m_cm7_ahb_get_ahbp_size();
    
    switch (sz) {
        case ARM_V7M_CM7_AHBPCR_SZ_0MB:
            return 0U;
        case ARM_V7M_CM7_AHBPCR_SZ_64MB:
            return 64U;
        case ARM_V7M_CM7_AHBPCR_SZ_128MB:
            return 128U;
        case ARM_V7M_CM7_AHBPCR_SZ_256MB:
            return 256U;
        case ARM_V7M_CM7_AHBPCR_SZ_512MB:
            return 512U;
        default:
            /* Reserved values - treat as disabled */
            return 0U;
    }
}
