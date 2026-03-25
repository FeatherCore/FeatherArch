/*
 * cm55_epu.h
 * Cortex-M55 Extension Processing Unit (EPU) Definitions
 * Reference: Cortex-M55 Technical Reference Manual, Chapter 11
 */

#ifndef CM55_EPU_H
#define CM55_EPU_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * EPU Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t EPUCR;
    volatile uint32_t EPUIR;
    volatile const uint32_t EPUSR;
} cm55_epu_regs_t;

/*============================================================================*
 * EPU Control Register Bit Definitions
 *============================================================================*/

#define CM55_EPU_EPUCR_EN_Pos           0
#define CM55_EPU_EPUCR_EN_Msk           (1UL << CM55_EPU_EPUCR_EN_Pos)

/*============================================================================*
 * EPU API Functions (Template)
 *============================================================================*/

uint32_t cm55_epu_is_present(void);
void cm55_epu_enable(void);
void cm55_epu_disable(void);
uint32_t cm55_epu_get_status(void);
void cm55_epu_send_command(uint32_t cmd);
uint32_t cm55_epu_get_response(void);

#ifdef __cplusplus
}
#endif

#endif /* CM55_EPU_H */
