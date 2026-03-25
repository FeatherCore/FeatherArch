/*
 * armv8m_pmu.h
 * Armv8-M Performance Monitors Extension Definitions
 * Reference: Armv8-M Architecture Reference Manual, Chapter B15
 */

#ifndef ARMV8M_PMU_H
#define ARMV8M_PMU_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * PMU Type Definitions
 *============================================================================*/

typedef struct {
    volatile uint32_t EVCNTR[31];
    uint32_t RESERVED0[1];
    volatile uint32_t CCNTR;
    uint32_t RESERVED1[15];
    volatile uint32_t EVTYPER[31];
    uint32_t RESERVED2[1];
    volatile uint32_t CCFILTR;
    uint32_t RESERVED3[15];
    volatile uint32_t PMCNTENSET;
    volatile uint32_t PMCNTENCLR;
    volatile uint32_t PMINTENSET;
    volatile uint32_t PMINTENCLR;
    volatile uint32_t PMOVSCLR;
    uint32_t RESERVED4[1];
    volatile uint32_t PMSWINC;
    volatile uint32_t PMOVSSET;
    uint32_t RESERVED5[29];
    volatile uint32_t PMCFGR;
    volatile uint32_t PMCR;
    volatile uint32_t PMCEID0;
    volatile uint32_t PMCEID1;
    volatile uint32_t PMCEID2;
    volatile uint32_t PMCEID3;
} armv8m_pmu_regs_t;

/*============================================================================*
 * PMU Event Types
 *============================================================================*/

#define ARMV8M_PMU_EVENT_SW_INCR        0x00
#define ARMV8M_PMU_EVENT_L1I_CACHE_REFILL 0x01
#define ARMV8M_PMU_EVENT_L1D_CACHE_REFILL 0x03
#define ARMV8M_PMU_EVENT_L1D_CACHE      0x04
#define ARMV8M_PMU_EVENT_LD_RETIRED     0x06
#define ARMV8M_PMU_EVENT_ST_RETIRED     0x07
#define ARMV8M_PMU_EVENT_INST_RETIRED   0x08
#define ARMV8M_PMU_EVENT_EXC_TAKEN      0x09
#define ARMV8M_PMU_EVENT_EXC_RETURN     0x0A
#define ARMV8M_PMU_EVENT_CID_WRITE_RETIRED 0x0B
#define ARMV8M_PMU_EVENT_PC_WRITE_RETIRED 0x0C
#define ARMV8M_PMU_EVENT_BR_IMMED_RETIRED 0x0D
#define ARMV8M_PMU_EVENT_BR_RETURN_RETIRED 0x0E
#define ARMV8M_PMU_EVENT_UNALIGNED_LDST_RETIRED 0x0F
#define ARMV8M_PMU_EVENT_BR_MIS_PRED    0x10
#define ARMV8M_PMU_EVENT_CPU_CYCLES     0x11
#define ARMV8M_PMU_EVENT_BR_PRED        0x12

/*============================================================================*
 * PMU API Functions (Template)
 *============================================================================*/

uint32_t armv8m_pmu_is_present(void);
void armv8m_pmu_enable(void);
void armv8m_pmu_disable(void);
void armv8m_pmu_reset_counters(void);
uint32_t armv8m_pmu_get_counter_count(void);

/* Event Counter Functions */
void armv8m_pmu_enable_counter(uint32_t counter);
void armv8m_pmu_disable_counter(uint32_t counter);
void armv8m_pmu_set_event_type(uint32_t counter, uint32_t event);
uint32_t armv8m_pmu_get_event_count(uint32_t counter);
void armv8m_pmu_set_event_count(uint32_t counter, uint32_t value);

/* Cycle Counter Functions */
void armv8m_pmu_enable_cycle_counter(void);
void armv8m_pmu_disable_cycle_counter(void);
uint64_t armv8m_pmu_get_cycle_count(void);
void armv8m_pmu_set_cycle_count(uint64_t value);

/* Overflow Functions */
uint32_t armv8m_pmu_get_overflow_status(void);
void armv8m_pmu_clear_overflow(uint32_t mask);

#ifdef __cplusplus
}
#endif

#endif /* ARMV8M_PMU_H */
