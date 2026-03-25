/*
 * armv8m_pacbti.h
 * Armv8-M Pointer Authentication and Branch Target Identification Extension
 * Reference: Armv8-M Architecture Reference Manual, Chapter B6
 */

#ifndef ARMV8M_PACBTI_H
#define ARMV8M_PACBTI_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * PACBTI Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t PAC_KEY_P_0;
    volatile uint32_t PAC_KEY_P_1;
    volatile uint32_t PAC_KEY_P_2;
    volatile uint32_t PAC_KEY_P_3;
    volatile uint32_t PAC_KEY_U_0;
    volatile uint32_t PAC_KEY_U_1;
    volatile uint32_t PAC_KEY_U_2;
    volatile uint32_t PAC_KEY_U_3;
} armv8m_pacbti_regs_t;

/*============================================================================*
 * PACBTI API Functions (Template)
 *============================================================================*/

uint32_t armv8m_pacbti_is_present(void);
void armv8m_pacbti_enable(void);
void armv8m_pacbti_disable(void);

/* Pointer Authentication Key Management */
void armv8m_pacbti_set_key_p(uint32_t key[4]);
void armv8m_pacbti_set_key_u(uint32_t key[4]);
void armv8m_pacbti_get_key_p(uint32_t key[4]);
void armv8m_pacbti_get_key_u(uint32_t key[4]);

/* Pointer Authentication Operations */
uint32_t armv8m_pacbti_pac(uint32_t ptr, uint32_t modifier);
uint32_t armv8m_pacbti_aut(uint32_t ptr, uint32_t modifier);
uint32_t armv8m_pacbti_xpac(uint32_t ptr);

/* Branch Target Identification */
void armv8m_pacbti_enable_bti(void);
void armv8m_pacbti_disable_bti(void);

#ifdef __cplusplus
}
#endif

#endif /* ARMV8M_PACBTI_H */
