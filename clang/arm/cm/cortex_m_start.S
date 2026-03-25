/**
 * @file cortex_m_start.S
 * @brief Cortex-M Profile startup entry point
 *
 * This file selects the appropriate Cortex-M architecture version:
 * - ARMv6-M (v6m/armv6m_start.S)
 * - ARMv7-M (v7m/armv7m_start.S)
 * - ARMv8-M (v8m/armv8m_start.S)
 */

#ifndef CORTEX_M_START_S
#define CORTEX_M_START_S

/* ============================================================================
 * Cortex-M Architecture Version Selection
 * ============================================================================
 *
 * The architecture version is determined by compiler predefined macros:
 * - __ARM_ARCH = 6 : ARMv6-M (Cortex-M0, M0+, M1)
 * - __ARM_ARCH = 7 && __ARM_ARCH_PROFILE = 'M' : ARMv7-M (Cortex-M3, M4, M7)
 * - __ARM_ARCH = 8 && __ARM_ARCH_PROFILE = 'M' : ARMv8-M (Cortex-M23, M33, M55, M85)
 */

#if defined(__ARM_ARCH)
    #if __ARM_ARCH == 6
        /* ARMv6-M selected (Cortex-M0/M0+/M1) */
        #include "v6m/armv6m_start.S"
    #elif __ARM_ARCH == 7
        /* ARMv7-M selected (Cortex-M3/M4/M7) */
        #include "v7m/armv7m_start.S"
    #elif __ARM_ARCH == 8
        /* ARMv8-M selected (Cortex-M23/M33/M55/M85) */
        #include "v8m/armv8m_start.S"
    #else
        #error "Unsupported ARM architecture version for Cortex-M"
    #endif
#else
    #error "Cannot determine ARM architecture version"
#endif

#endif /* CORTEX_M_START_S */
