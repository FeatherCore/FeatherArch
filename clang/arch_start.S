/**
 * @file arch_start.S
 * @brief Architecture selection entry point
 *
 * This is the very first entry point of the firmware. It selects
 * the appropriate architecture-specific startup code based on
 * compiler definitions.
 *
 * The hierarchy is:
 *   arch_start.S -> arm_start.S / riscv_start.S
 */

#ifndef ARCH_START_S
#define ARCH_START_S

/* ============================================================================
 * Architecture Selection
 * ============================================================================
 *
 * The architecture is determined by compiler predefined macros:
 * - __arm__ or __aarch64__ : ARM architecture
 * - __riscv : RISC-V architecture
 */

#if defined(__arm__) || defined(__aarch64__)
    /* ARM Architecture selected */
    #include "arm/arm_start.S"
#elif defined(__riscv)
    /* RISC-V Architecture selected */
    #include "riscv/riscv_start.S"
#else
    #error "Unknown architecture. Supported: ARM, RISC-V"
#endif

#endif /* ARCH_START_S */
