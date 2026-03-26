/**
 * @file arm_v8m_cm85_sau.h
 * @brief Cortex-M85 Security Attribution Unit (SAU)
 *
 * @note Reference: Arm Cortex-M85 Devices Generic User Guide, Chapter 5.6.1
 * @note Reference: Arm Cortex-M85 Processor TRM, Chapter 9.2
 */

#ifndef ARM_V8M_CM85_SAU_H
#define ARM_V8M_CM85_SAU_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SAU register structure */
typedef struct {
    volatile uint32_t CTRL;         /* SAU Control Register */
    volatile uint32_t TYPE;         /* SAU Type Register */
    volatile uint32_t RNR;          /* SAU Region Number Register */
    volatile uint32_t RBAR;         /* SAU Region Base Address Register */
    volatile uint32_t RLAR;         /* SAU Region Limit Address Register */
    volatile uint32_t SFSR;         /* Secure Fault Status Register */
    volatile uint32_t SFAR;         /* Secure Fault Address Register */
} arm_v8m_cm85_sau_reg_t;

#define ARM_V8M_CM85_SAU_BASE       (0xE000EDD0UL)
#define ARM_V8M_CM85_SAU            ((arm_v8m_cm85_sau_reg_t *)ARM_V8M_CM85_SAU_BASE)

/* SAU CTRL register bit definitions */
#define ARM_V8M_CM85_SAU_CTRL_ENABLE_Pos        0U
#define ARM_V8M_CM85_SAU_CTRL_ENABLE_Msk        (1UL << ARM_V8M_CM85_SAU_CTRL_ENABLE_Pos)
#define ARM_V8M_CM85_SAU_CTRL_ALLNS_Pos         1U
#define ARM_V8M_CM85_SAU_CTRL_ALLNS_Msk         (1UL << ARM_V8M_CM85_SAU_CTRL_ALLNS_Pos)

/* SAU TYPE register */
#define ARM_V8M_CM85_SAU_TYPE_SREGION_Pos       0U
#define ARM_V8M_CM85_SAU_TYPE_SREGION_Msk       (0xFFUL << ARM_V8M_CM85_SAU_TYPE_SREGION_Pos)

/* SAU RBAR register */
#define ARM_V8M_CM85_SAU_RBAR_BASE_Pos          5U
#define ARM_V8M_CM85_SAU_RBAR_BASE_Msk          (0x7FFFFFFUL << ARM_V8M_CM85_SAU_RBAR_BASE_Pos)

/* SAU RLAR register */
#define ARM_V8M_CM85_SAU_RLAR_LIMIT_Pos         5U
#define ARM_V8M_CM85_SAU_RLAR_LIMIT_Msk         (0x7FFFFFFUL << ARM_V8M_CM85_SAU_RLAR_LIMIT_Pos)
#define ARM_V8M_CM85_SAU_RLAR_NSC_Pos           1U
#define ARM_V8M_CM85_SAU_RLAR_NSC_Msk           (1UL << ARM_V8M_CM85_SAU_RLAR_NSC_Pos)
#define ARM_V8M_CM85_SAU_RLAR_ENABLE_Pos        0U
#define ARM_V8M_CM85_SAU_RLAR_ENABLE_Msk        (1UL << ARM_V8M_CM85_SAU_RLAR_ENABLE_Pos)

/* SAU SFSR register bit definitions */
#define ARM_V8M_CM85_SAU_SFSR_INVEP_Pos         0U
#define ARM_V8M_CM85_SAU_SFSR_INVEP_Msk         (1UL << ARM_V8M_CM85_SAU_SFSR_INVEP_Pos)
#define ARM_V8M_CM85_SAU_SFSR_INVIS_Pos         1U
#define ARM_V8M_CM85_SAU_SFSR_INVIS_Msk         (1UL << ARM_V8M_CM85_SAU_SFSR_INVIS_Pos)
#define ARM_V8M_CM85_SAU_SFSR_INVER_Pos         2U
#define ARM_V8M_CM85_SAU_SFSR_INVER_Msk         (1UL << ARM_V8M_CM85_SAU_SFSR_INVER_Pos)
#define ARM_V8M_CM85_SAU_SFSR_AUVIOL_Pos        3U
#define ARM_V8M_CM85_SAU_SFSR_AUVIOL_Msk        (1UL << ARM_V8M_CM85_SAU_SFSR_AUVIOL_Pos)
#define ARM_V8M_CM85_SAU_SFSR_INVTRAN_Pos       4U
#define ARM_V8M_CM85_SAU_SFSR_INVTRAN_Msk       (1UL << ARM_V8M_CM85_SAU_SFSR_INVTRAN_Pos)
#define ARM_V8M_CM85_SAU_SFSR_LSPERR_Pos        5U
#define ARM_V8M_CM85_SAU_SFSR_LSPERR_Msk        (1UL << ARM_V8M_CM85_SAU_SFSR_LSPERR_Pos)
#define ARM_V8M_CM85_SAU_SFSR_SFARVALID_Pos     6U
#define ARM_V8M_CM85_SAU_SFSR_SFARVALID_Msk     (1UL << ARM_V8M_CM85_SAU_SFSR_SFARVALID_Pos)
#define ARM_V8M_CM85_SAU_SFSR_LSERR_Pos         7U
#define ARM_V8M_CM85_SAU_SFSR_LSERR_Msk         (1UL << ARM_V8M_CM85_SAU_SFSR_LSERR_Pos)

/* Security region configuration */
typedef struct {
    uint32_t base_addr;
    uint32_t limit_addr;
    bool nsc;               /* Non-secure callable */
    bool enable;
} arm_v8m_cm85_sau_region_config_t;

/* SAU initialization and control */
int arm_v8m_cm85_sau_init(void);
void arm_v8m_cm85_sau_deinit(void);
void arm_v8m_cm85_sau_enable(void);
void arm_v8m_cm85_sau_disable(void);
bool arm_v8m_cm85_sau_is_enabled(void);
void arm_v8m_cm85_sau_set_allns(bool allns);

/* Region configuration */
uint32_t arm_v8m_cm85_sau_get_num_regions(void);
void arm_v8m_cm85_sau_select_region(uint32_t region);
uint32_t arm_v8m_cm85_sau_get_selected_region(void);
int arm_v8m_cm85_sau_configure_region(uint32_t region, const arm_v8m_cm85_sau_region_config_t *config);
void arm_v8m_cm85_sau_enable_region(uint32_t region);
void arm_v8m_cm85_sau_disable_region(uint32_t region);

/* Secure fault handling */
uint32_t arm_v8m_cm85_sau_get_fault_status(void);
void arm_v8m_cm85_sau_clear_fault_status(uint32_t mask);
uint32_t arm_v8m_cm85_sau_get_fault_address(void);
bool arm_v8m_cm85_sau_is_fault_address_valid(void);

/* Security state transitions */
void arm_v8m_cm85_sau_sg(void);     /* Secure Gateway instruction */

/* IDAU (Implementation Defined Attribution Unit) check */
typedef enum {
    ARM_V8M_CM85_SAU_ATTR_SECURE = 0,
    ARM_V8M_CM85_SAU_ATTR_NONSECURE = 1,
    ARM_V8M_CM85_SAU_ATTR_NSC = 2
} arm_v8m_cm85_sau_attr_t;

arm_v8m_cm85_sau_attr_t arm_v8m_cm85_sau_check_address(uint32_t addr);

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM85_SAU_H */
