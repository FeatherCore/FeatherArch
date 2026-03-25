/**
 * @file cm85_core.h
 * @brief Cortex-M85 core registers and special register access
 *
 * @note Reference: Arm Cortex-M85 Devices Generic User Guide, Chapter 3
 * @note Reference: Arm Cortex-M85 Processor TRM, Chapter 4
 */

#ifndef CM85_CORE_H
#define CM85_CORE_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Core register type definitions */
typedef struct {
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r4;
    uint32_t r5;
    uint32_t r6;
    uint32_t r7;
    uint32_t r8;
    uint32_t r9;
    uint32_t r10;
    uint32_t r11;
    uint32_t r12;
    uint32_t sp;
    uint32_t lr;
    uint32_t pc;
    uint32_t xpsr;
} cm85_core_regs_t;

/* Special register access functions - TODO: Implement using CMSIS intrinsics or assembly */

/* Stack Pointer (MSP/PSP) */
uint32_t cm85_get_msp(void);
void cm85_set_msp(uint32_t msp);
uint32_t cm85_get_psp(void);
void cm85_set_psp(uint32_t psp);

/* Stack Pointer Limit (MSPLIM/PSPLIM) - Armv8-M feature */
uint32_t cm85_get_msplim(void);
void cm85_set_msplim(uint32_t msplim);
uint32_t cm85_get_psplim(void);
void cm85_set_psplim(uint32_t psplim);

/* Priority Mask Registers */
uint32_t cm85_get_primask(void);
void cm85_set_primask(uint32_t primask);
uint32_t cm85_get_basepri(void);
void cm85_set_basepri(uint32_t basepri);
void cm85_set_basepri_max(uint32_t basepri);
uint32_t cm85_get_faultmask(void);
void cm85_set_faultmask(uint32_t faultmask);

/* CONTROL Register */
uint32_t cm85_get_control(void);
void cm85_set_control(uint32_t control);

/* CONTROL Register bit definitions */
#define CM85_CONTROL_SPSEL_Pos      1U
#define CM85_CONTROL_SPSEL_Msk      (1UL << CM85_CONTROL_SPSEL_Pos)
#define CM85_CONTROL_FPCA_Pos       2U
#define CM85_CONTROL_FPCA_Msk       (1UL << CM85_CONTROL_FPCA_Pos)
#define CM85_CONTROL_SFPA_Pos       3U
#define CM85_CONTROL_SFPA_Msk       (1UL << CM85_CONTROL_SFPA_Pos)
#define CM85_CONTROL_nPRIV_Pos      0U
#define CM85_CONTROL_nPRIV_Msk      (1UL << CM85_CONTROL_nPRIV_Pos)

/* APSR (Application Program Status Register) */
uint32_t cm85_get_apsr(void);

/* IPSR (Interrupt Program Status Register) */
uint32_t cm85_get_ipsr(void);

/* EPSR (Execution Program Status Register) */
uint32_t cm85_get_epsr(void);

/* XPSR (Combined Program Status Register) */
uint32_t cm85_get_xpsr(void);

/* EPSR bit fields - Armv8.1-M MVE ECI/ICI bits */
#define CM85_EPSR_ECI_Pos           10U
#define CM85_EPSR_ECI_Msk           (0x3FUL << CM85_EPSR_ECI_Pos)
#define CM85_EPSR_ICI_IT_Pos        10U
#define CM85_EPSR_ICI_IT_Msk        (0x3FUL << CM85_EPSR_ICI_IT_Pos)
#define CM85_EPSR_T_Pos             24U
#define CM85_EPSR_T_Msk             (1UL << CM85_EPSR_T_Pos)

/* APSR bit fields */
#define CM85_APSR_N_Pos             31U
#define CM85_APSR_N_Msk             (1UL << CM85_APSR_N_Pos)
#define CM85_APSR_Z_Pos             30U
#define CM85_APSR_Z_Msk             (1UL << CM85_APSR_Z_Pos)
#define CM85_APSR_C_Pos             29U
#define CM85_APSR_C_Msk             (1UL << CM85_APSR_C_Pos)
#define CM85_APSR_V_Pos             28U
#define CM85_APSR_V_Msk             (1UL << CM85_APSR_V_Pos)
#define CM85_APSR_Q_Pos             27U
#define CM85_APSR_Q_Msk             (1UL << CM85_APSR_Q_Pos)
#define CM85_APSR_GE_Pos            16U
#define CM85_APSR_GE_Msk            (0xFUL << CM85_APSR_GE_Pos)

/* Security state management */
typedef enum {
    CM85_CORE_STATE_NON_SECURE = 0,
    CM85_CORE_STATE_SECURE = 1
} cm85_core_security_state_t;

cm85_core_security_state_t cm85_core_get_security_state(void);

/* Processor mode */
typedef enum {
    CM85_CORE_MODE_THREAD = 0,
    CM85_CORE_MODE_HANDLER = 1
} cm85_core_mode_t;

cm85_core_mode_t cm85_core_get_mode(void);

/* Privilege level */
typedef enum {
    CM85_CORE_PRIV_UNPRIVILEGED = 0,
    CM85_CORE_PRIV_PRIVILEGED = 1
} cm85_core_privilege_t;

cm85_core_privilege_t cm85_core_get_privilege(void);

/* Secure/Non-secure special register access */
#ifdef __ARM_FEATURE_CMSE
uint32_t cm85_get_msp_ns(void);
void cm85_set_msp_ns(uint32_t msp);
uint32_t cm85_get_psp_ns(void);
void cm85_set_psp_ns(uint32_t psp);
uint32_t cm85_get_msplim_ns(void);
void cm85_set_msplim_ns(uint32_t msplim);
uint32_t cm85_get_psplim_ns(void);
void cm85_set_psplim_ns(uint32_t psplim);
uint32_t cm85_get_primask_ns(void);
void cm85_set_primask_ns(uint32_t primask);
uint32_t cm85_get_faultmask_ns(void);
void cm85_set_faultmask_ns(uint32_t faultmask);
uint32_t cm85_get_control_ns(void);
void cm85_set_control_ns(uint32_t control);
uint32_t cm85_get_sp_ns(void);
#endif

/* Test Target (TT) instruction for address checking */
typedef struct {
    uint32_t value;
} cm85_tt_resp_t;

cm85_tt_resp_t cm85_tt(const volatile void *addr);
cm85_tt_resp_t cm85_ttt(const volatile void *addr);
cm85_tt_resp_t cm85_tta(const volatile void *addr);
cm85_tt_resp_t cm85_ttat(const volatile void *addr);

/* TT response bit fields */
#define CM85_TT_RESP_MREGION_Pos    0U
#define CM85_TT_RESP_MREGION_Msk    (0xFFUL << CM85_TT_RESP_MREGION_Pos)
#define CM85_TT_RESP_MRVALID_Pos    8U
#define CM85_TT_RESP_MRVALID_Msk    (1UL << CM85_TT_RESP_MRVALID_Pos)
#define CM85_TT_RESP_S_Pos          22U
#define CM85_TT_RESP_S_Msk          (1UL << CM85_TT_RESP_S_Pos)
#define CM85_TT_RESP_NSREAD_Pos     23U
#define CM85_TT_RESP_NSREAD_Msk     (1UL << CM85_TT_RESP_NSREAD_Pos)
#define CM85_TT_RESP_IRVALID_Pos    24U
#define CM85_TT_RESP_IRVALID_Msk    (1UL << CM85_TT_RESP_IRVALID_Pos)
#define CM85_TT_RESP_IREGION_Pos    25U
#define CM85_TT_RESP_IREGION_Msk    (0x7UL << CM85_TT_RESP_IREGION_Pos)

/* Exclusive access instructions */
uint32_t cm85_ldrex(const volatile uint32_t *addr);
uint16_t cm85_ldrexh(const volatile uint16_t *addr);
uint8_t cm85_ldrexb(const volatile uint8_t *addr);
uint32_t cm85_strex(uint32_t value, volatile uint32_t *addr);
uint32_t cm85_strexh(uint16_t value, volatile uint16_t *addr);
uint32_t cm85_strexb(uint8_t value, volatile uint8_t *addr);
void cm85_clrex(void);

/* Load-Acquire/Store-Release instructions - Armv8-M */
uint32_t cm85_lda(const volatile uint32_t *addr);
uint16_t cm85_ldah(const volatile uint16_t *addr);
uint8_t cm85_ldab(const volatile uint8_t *addr);
void cm85_stl(uint32_t value, volatile uint32_t *addr);
void cm85_stlh(uint16_t value, volatile uint16_t *addr);
void cm85_stlb(uint8_t value, volatile uint8_t *addr);

/* Load-Acquire Exclusive/Store-Release Exclusive - Armv8-M */
uint32_t cm85_ldaex(const volatile uint32_t *addr);
uint16_t cm85_ldaexh(const volatile uint16_t *addr);
uint8_t cm85_ldaexb(const volatile uint8_t *addr);
uint32_t cm85_stlex(uint32_t value, volatile uint32_t *addr);
uint32_t cm85_stlexh(uint16_t value, volatile uint16_t *addr);
uint32_t cm85_stlexb(uint8_t value, volatile uint8_t *addr);

/* Reverse bit/byte order */
uint32_t cm85_rbit(uint32_t value);
uint32_t cm85_rev(uint32_t value);
uint32_t cm85_rev16(uint32_t value);
int32_t cm85_revsh(int32_t value);

/* Count leading zeros */
uint32_t cm85_clz(uint32_t value);

/* Saturation operations */
int32_t cm85_ssat(int32_t value, uint32_t sat);
uint32_t cm85_usat(int32_t value, uint32_t sat);

/* Rotate right with extend */
uint32_t cm85_rrx(uint32_t value);

/* BKPT instruction */
void cm85_bkpt(uint8_t imm);

#ifdef __cplusplus
}
#endif

#endif /* CM85_CORE_H */
