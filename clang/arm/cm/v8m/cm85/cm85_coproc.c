/**
 * @file cm85_coproc.c
 * @brief Cortex-M85 Coprocessor implementation
 */

#include "cm85_coproc.h"
#include "cm85_scb.h"

/* TODO: Implement Coprocessor functions */

int cm85_coproc_init(void)
{
    /* TODO: Initialize coprocessor interface */
    return 0;
}

void cm85_coproc_deinit(void)
{
    /* TODO: Deinitialize coprocessor interface */
}

void cm85_coproc_set_access(uint32_t cp, cm85_coproc_access_t access)
{
    /* TODO: Set coprocessor access via CPACR */
    (void)cp;
    (void)access;
}

cm85_coproc_access_t cm85_coproc_get_access(uint32_t cp)
{
    /* TODO: Get coprocessor access from CPACR */
    (void)cp;
    return CM85_COPROC_ACCESS_DENIED;
}

void cm85_coproc_enable(uint32_t cp)
{
    /* TODO: Enable coprocessor */
    (void)cp;
}

void cm85_coproc_disable(uint32_t cp)
{
    /* TODO: Disable coprocessor */
    (void)cp;
}

bool cm85_coproc_is_enabled(uint32_t cp)
{
    /* TODO: Check if coprocessor is enabled */
    (void)cp;
    return false;
}

uint32_t cm85_coproc_cdp(uint32_t cp, uint32_t opc1, uint32_t opc2, uint32_t crn, uint32_t crm)
{
    /* TODO: Coprocessor data processing */
    (void)cp;
    (void)opc1;
    (void)opc2;
    (void)crn;
    (void)crm;
    return 0;
}

void cm85_coproc_cdp2(uint32_t cp, uint32_t opc1, uint32_t opc2, uint32_t crn, uint32_t crm, uint32_t data)
{
    /* TODO: Coprocessor data processing (32-bit) */
    (void)cp;
    (void)opc1;
    (void)opc2;
    (void)crn;
    (void)crm;
    (void)data;
}

void cm85_coproc_mcr(uint32_t cp, uint32_t opc1, uint32_t opc2, uint32_t crn, uint32_t crm, uint32_t value)
{
    /* TODO: Move to coprocessor */
    (void)cp;
    (void)opc1;
    (void)opc2;
    (void)crn;
    (void)crm;
    (void)value;
}

void cm85_coproc_mcr2(uint32_t cp, uint32_t opc1, uint32_t opc2, uint32_t crn, uint32_t crm, uint32_t value)
{
    /* TODO: Move to coprocessor (32-bit) */
    (void)cp;
    (void)opc1;
    (void)opc2;
    (void)crn;
    (void)crm;
    (void)value;
}

uint32_t cm85_coproc_mrc(uint32_t cp, uint32_t opc1, uint32_t opc2, uint32_t crn, uint32_t crm)
{
    /* TODO: Move from coprocessor */
    (void)cp;
    (void)opc1;
    (void)opc2;
    (void)crn;
    (void)crm;
    return 0;
}

uint32_t cm85_coproc_mrc2(uint32_t cp, uint32_t opc1, uint32_t opc2, uint32_t crn, uint32_t crm)
{
    /* TODO: Move from coprocessor (32-bit) */
    (void)cp;
    (void)opc1;
    (void)opc2;
    (void)crn;
    (void)crm;
    return 0;
}

void cm85_coproc_ldc(uint32_t cp, uint32_t crd, const void *addr)
{
    /* TODO: Load coprocessor */
    (void)cp;
    (void)crd;
    (void)addr;
}

void cm85_coproc_ldc2(uint32_t cp, uint32_t crd, const void *addr)
{
    /* TODO: Load coprocessor (32-bit) */
    (void)cp;
    (void)crd;
    (void)addr;
}

void cm85_coproc_stc(uint32_t cp, uint32_t crd, void *addr)
{
    /* TODO: Store coprocessor */
    (void)cp;
    (void)crd;
    (void)addr;
}

void cm85_coproc_stc2(uint32_t cp, uint32_t crd, void *addr)
{
    /* TODO: Store coprocessor (32-bit) */
    (void)cp;
    (void)crd;
    (void)addr;
}

bool cm85_coproc_is_present(uint32_t cp)
{
    /* TODO: Check if coprocessor is present */
    (void)cp;
    return false;
}
