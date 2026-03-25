/**
 * @file cm85_pacbti.h
 * @brief Cortex-M85 PACBTI (Pointer Authentication and Branch Target Identification)
 *
 * @note Reference: Arm Cortex-M85 Devices Generic User Guide, Chapter 4.34
 * @note Reference: Arm Cortex-M85 Processor TRM, Chapter 4.5
 */

#ifndef CM85_PACBTI_H
#define CM85_PACBTI_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* PAC Key Registers */
#define CM85_PAC_KEY_P0     (0xE000EF90UL)
#define CM85_PAC_KEY_P1     (0xE000EF94UL)
#define CM85_PAC_KEY_P2     (0xE000EF98UL)
#define CM85_PAC_KEY_P3     (0xE000EF9CUL)
#define CM85_PAC_KEY_U0     (0xE000EFA0UL)
#define CM85_PAC_KEY_U1     (0xE000EFA4UL)
#define CM85_PAC_KEY_U2     (0xE000EFA8UL)
#define CM85_PAC_KEY_U3     (0xE000EFACUL)

/* PACBTI initialization */
int cm85_pacbti_init(void);
void cm85_pacbti_deinit(void);
bool cm85_pacbti_is_present(void);

/* PAC Key management */
void cm85_pacbti_set_priv_key(const uint32_t key[4]);
void cm85_pacbti_get_priv_key(uint32_t key[4]);
void cm85_pacbti_set_unpriv_key(const uint32_t key[4]);
void cm85_pacbti_get_unpriv_key(uint32_t key[4]);
void cm85_pacbti_clear_keys(void);

/* Pointer Authentication */
uint32_t cm85_pacbti_pac(uint32_t ptr, uint32_t modifier);
uint32_t cm85_pacbti_aut(uint32_t ptr, uint32_t modifier);
uint32_t cm85_pacbti_pacga(uint32_t ptr, uint32_t modifier);
uint32_t cm85_pacbti_xpac(uint32_t ptr);

/* BTI (Branch Target Identification) */
void cm85_pacbti_bti(void);
void cm85_pacbti_btic(void);

/* BTI enabling */
void cm85_pacbti_enable_bti(void);
void cm85_pacbti_disable_bti(void);
bool cm85_pacbti_bti_enabled(void);

/* PAC enabling */
void cm85_pacbti_enable_pac(void);
void cm85_pacbti_disable_pac(void);
bool cm85_pacbti_pac_enabled(void);

/* Secure/Non-secure PAC key access */
#ifdef __ARM_FEATURE_CMSE
void cm85_pacbti_set_priv_key_ns(const uint32_t key[4]);
void cm85_pacbti_get_priv_key_ns(uint32_t key[4]);
#endif

#ifdef __cplusplus
}
#endif

#endif /* CM85_PACBTI_H */
