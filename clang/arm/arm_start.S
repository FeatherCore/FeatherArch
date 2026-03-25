/**
 * @file arm_start.S
 * @brief ARM Architecture startup entry point
 *
 * This file selects the appropriate ARM profile startup code:
 * - Cortex-M (cm/cortex_m_start.S)
 * - Cortex-A (ca/cortex_a_start.S)
 * - Cortex-R (cr/cortex_r_start.S)
 */

#ifndef ARM_START_S
#define ARM_START_S

/* ============================================================================
 * ARM Profile Selection
 * ============================================================================
 *
 * The ARM profile is determined by compiler predefined macros:
 * - __ARM_ARCH_PROFILE = 'M' : Cortex-M profile (Microcontroller)
 * - __ARM_ARCH_PROFILE = 'A' : Cortex-A profile (Application)
 * - __ARM_ARCH_PROFILE = 'R' : Cortex-R profile (Real-time)
 *
 * Alternatively, architecture version can be used:
 * - __ARM_ARCH >= 8 && defined(__ARM_ARCH_PROFILE) : ARMv8-M/A/R
 * - __ARM_ARCH == 7 && defined(__ARM_ARCH_PROFILE) : ARMv7-M/A/R
 * - __ARM_ARCH == 6 && defined(__ARM_ARCH_PROFILE) : ARMv6-M
 */

#if defined(__ARM_ARCH_PROFILE)
    #if __ARM_ARCH_PROFILE == 'M'
        /* Cortex-M Profile selected */
        #include "cm/cortex_m_start.S"
    #elif __ARM_ARCH_PROFILE == 'A'
        /* Cortex-A Profile selected */
        #include "ca/cortex_a_start.S"
    #elif __ARM_ARCH_PROFILE == 'R'
        /* Cortex-R Profile selected */
        #include "cr/cortex_r_start.S"
    #else
        #error "Unknown ARM profile"
    #endif
#else
    /* Fallback: Use architecture version to determine profile */
    #if defined(__ARM_ARCH) && (__ARM_ARCH >= 6)
        /* Default to Cortex-M for ARMv6-M and ARMv7-M/ARMv8-M */
        #include "cm/cortex_m_start.S"
    #else
        #error "Cannot determine ARM profile"
    #endif
#endif

#endif /* ARM_START_S */
