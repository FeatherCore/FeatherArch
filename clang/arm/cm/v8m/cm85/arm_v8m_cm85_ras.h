/**
 * @file arm_v8m_cm85_ras.h
 * @brief Cortex-M85 RAS (Reliability, Availability, Serviceability)
 *
 * @note Reference: Arm Cortex-M85 Devices Generic User Guide, Chapter 6
 * @note Reference: Arm Cortex-M85 Processor TRM, Chapter 11
 */

#ifndef ARM_V8M_CM85_RAS_H
#define ARM_V8M_CM85_RAS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RAS Error Record Registers */
typedef struct {
    volatile uint32_t ERRFR;        /* Error Record Feature Register */
    volatile uint32_t ERRCTRL;      /* Error Record Control Register */
    volatile uint32_t ERRSTATUS;    /* Error Record Primary Status Register */
    volatile uint32_t ERRADDR;      /* Error Record Address Register */
    volatile uint32_t ERRADDR2;     /* Error Record Address Register 2 */
    volatile uint32_t ERRMISC0;     /* Error Record Miscellaneous Register 0 */
    volatile uint32_t ERRMISC1;     /* Error Record Miscellaneous Register 1 */
    volatile uint32_t ERRMISC2;     /* Error Record Miscellaneous Register 2 */
    volatile uint32_t ERRMISC3;     /* Error Record Miscellaneous Register 3 */
} arm_v8m_cm85_ras_err_record_t;

#define ARM_V8M_CM85_RAS_ERR_BASE   (0xE0005000UL)
#define ARM_V8M_CM85_RAS_ERR        ((arm_v8m_cm85_ras_err_record_t *)ARM_V8M_CM85_RAS_ERR_BASE)

/* RAS Fault Status Register (RFSR) */
#define ARM_V8M_CM85_RFSR_BASE      (0xE000EF04UL)
#define ARM_V8M_CM85_RFSR           (*(volatile uint32_t *)ARM_V8M_CM85_RFSR_BASE)

/* RFSR bit definitions */
#define ARM_V8M_CM85_RFSR_IERR_Pos          0U
#define ARM_V8M_CM85_RFSR_IERR_Msk          (1UL << ARM_V8M_CM85_RFSR_IERR_Pos)
#define ARM_V8M_CM85_RFSR_DERR_Pos          1U
#define ARM_V8M_CM85_RFSR_DERR_Msk          (1UL << ARM_V8M_CM85_RFSR_DERR_Pos)
#define ARM_V8M_CM85_RFSR_TERR_Pos          2U
#define ARM_V8M_CM85_RFSR_TERR_Msk          (1UL << ARM_V8M_CM85_RFSR_TERR_Pos)
#define ARM_V8M_CM85_RFSR_PERR_Pos          3U
#define ARM_V8M_CM85_RFSR_PERR_Msk          (1UL << ARM_V8M_CM85_RFSR_PERR_Pos)
#define ARM_V8M_CM85_RFSR_EPUERR_Pos        4U
#define ARM_V8M_CM85_RFSR_EPUERR_Msk        (1UL << ARM_V8M_CM85_RFSR_EPUERR_Pos)

/* RAS initialization */
int arm_v8m_cm85_ras_init(void);
void arm_v8m_cm85_ras_deinit(void);
bool arm_v8m_cm85_ras_is_present(void);

/* Error record access */
uint32_t arm_v8m_cm85_ras_get_errfr(void);
uint32_t arm_v8m_cm85_ras_get_errstatus(void);
void arm_v8m_cm85_ras_clear_errstatus(uint32_t mask);
uint32_t arm_v8m_cm85_ras_get_erraddr(void);
uint32_t arm_v8m_cm85_ras_get_erraddr2(void);

/* Fault status */
uint32_t arm_v8m_cm85_ras_get_rfsr(void);
void arm_v8m_cm85_ras_clear_rfsr(uint32_t mask);

/* Error injection (for testing) */
void arm_v8m_cm85_ras_inject_icache_error(void);
void arm_v8m_cm85_ras_inject_dcache_error(void);
void arm_v8m_cm85_ras_inject_tcm_error(void);

/* Error Synchronization Barrier */
void arm_v8m_cm85_ras_esb(void);

/* Data Synchronization Barrier for RAS */
void arm_v8m_cm85_ras_dsb(void);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM85_RAS_H */
