/*
 * arm_v7m_cm7_ahb.c
 * Cortex-M7 AHB Interface Control Implementation
 * Reference: Cortex-M7 Processor Technical Reference Manual, Chapter 3.3
 *            - Section 3.3.7: AHBP Control Register (CM7_AHBPCR)
 *            - Section 3.3.9: Auxiliary Bus Fault Status Register (CM7_ABFSR)
 *            - Section 3.3.10: AHB Slave Control Register (CM7_AHBSCR)
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
