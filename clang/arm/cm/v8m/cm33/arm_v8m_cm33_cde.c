/*
 * arm_v8m_cm33_cde.c
 * Cortex-M33 Custom Datapath Extension (CDE) Implementation
 * Reference: Cortex-M33 Devices Generic User Guide, Chapter 3.6
 *            Cortex-M33 Technical Reference Manual, Chapter 8
 */

#include "arm_v8m_cm33_cde.h"

/*============================================================================*
 * CDE Implementation
 *============================================================================*/

uint32_t arm_v8m_cm33_cde_is_present(void)
{
    /* TODO: Check ID_ISAR for CDE support */
    return 0;
}

void arm_v8m_cm33_cde_enable_coprocessor(uint32_t cp_num)
{
    /* TODO: Set CP access in CPACR */
    (void)cp_num;
}

void arm_v8m_cm33_cde_disable_coprocessor(uint32_t cp_num)
{
    /* TODO: Clear CP access in CPACR */
    (void)cp_num;
}

uint32_t arm_v8m_cm33_cde_is_coprocessor_enabled(uint32_t cp_num)
{
    /* TODO: Check CP access in CPACR */
    (void)cp_num;
    return 0;
}

/*============================================================================*
 * CDE Instructions
 *============================================================================*/

uint32_t arm_v8m_cm33_cde_cx1(uint32_t cp_num, uint32_t imm)
{
    /* TODO: Execute CX1 instruction */
    (void)cp_num;
    (void)imm;
    return 0;
}

uint64_t arm_v8m_cm33_cde_cx1d(uint32_t cp_num, uint32_t imm)
{
    /* TODO: Execute CX1D instruction */
    (void)cp_num;
    (void)imm;
    return 0;
}

uint32_t arm_v8m_cm33_cde_cx2(uint32_t cp_num, uint32_t imm, uint32_t val)
{
    /* TODO: Execute CX2 instruction */
    (void)cp_num;
    (void)imm;
    (void)val;
    return 0;
}

uint64_t arm_v8m_cm33_cde_cx2d(uint32_t cp_num, uint32_t imm, uint32_t val)
{
    /* TODO: Execute CX2D instruction */
    (void)cp_num;
    (void)imm;
    (void)val;
    return 0;
}

uint32_t arm_v8m_cm33_cde_cx3(uint32_t cp_num, uint32_t imm, uint32_t val1, uint32_t val2)
{
    /* TODO: Execute CX3 instruction */
    (void)cp_num;
    (void)imm;
    (void)val1;
    (void)val2;
    return 0;
}

uint64_t arm_v8m_cm33_cde_cx3d(uint32_t cp_num, uint32_t imm, uint32_t val1, uint32_t val2)
{
    /* TODO: Execute CX3D instruction */
    (void)cp_num;
    (void)imm;
    (void)val1;
    (void)val2;
    return 0;
}

/*============================================================================*
 * CDE with Accumulate
 *============================================================================*/

uint32_t arm_v8m_cm33_cde_cx1a(uint32_t cp_num, uint32_t imm, uint32_t acc)
{
    /* TODO: Execute CX1A instruction */
    (void)cp_num;
    (void)imm;
    (void)acc;
    return 0;
}

uint64_t arm_v8m_cm33_cde_cx1da(uint32_t cp_num, uint32_t imm, uint64_t acc)
{
    /* TODO: Execute CX1DA instruction */
    (void)cp_num;
    (void)imm;
    (void)acc;
    return 0;
}

uint32_t arm_v8m_cm33_cde_cx2a(uint32_t cp_num, uint32_t imm, uint32_t val, uint32_t acc)
{
    /* TODO: Execute CX2A instruction */
    (void)cp_num;
    (void)imm;
    (void)val;
    (void)acc;
    return 0;
}

uint64_t arm_v8m_cm33_cde_cx2da(uint32_t cp_num, uint32_t imm, uint32_t val, uint64_t acc)
{
    /* TODO: Execute CX2DA instruction */
    (void)cp_num;
    (void)imm;
    (void)val;
    (void)acc;
    return 0;
}

uint32_t arm_v8m_cm33_cde_cx3a(uint32_t cp_num, uint32_t imm, uint32_t val1, uint32_t val2, uint32_t acc)
{
    /* TODO: Execute CX3A instruction */
    (void)cp_num;
    (void)imm;
    (void)val1;
    (void)val2;
    (void)acc;
    return 0;
}

uint64_t arm_v8m_cm33_cde_cx3da(uint32_t cp_num, uint32_t imm, uint32_t val1, uint32_t val2, uint64_t acc)
{
    /* TODO: Execute CX3DA instruction */
    (void)cp_num;
    (void)imm;
    (void)val1;
    (void)val2;
    (void)acc;
    return 0;
}

/*============================================================================*
 * Security Configuration
 *============================================================================*/

void arm_v8m_cm33_cde_set_ns_access(uint32_t cp_num, uint32_t enable)
{
    /* TODO: Configure NSACR for Non-secure access */
    (void)cp_num;
    (void)enable;
}

uint32_t arm_v8m_cm33_cde_get_ns_access(uint32_t cp_num)
{
    /* TODO: Read NSACR for Non-secure access */
    (void)cp_num;
    return 0;
}
