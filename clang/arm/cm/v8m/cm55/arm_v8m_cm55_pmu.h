/*
 * arm_v8m_cm55_pmu.h
 * Cortex-M55 Performance Monitoring Unit (PMU) Definitions
 * Reference: Cortex-M55 Technical Reference Manual, Chapter 4
 *
 * @note This file reuses Armv8-M generic PMU definitions.
 */

#ifndef ARM_V8M_CM55_PMU_H
#define ARM_V8M_CM55_PMU_H

#include <stdint.h>
#include "../arm_v8m_pmu.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 * Type Aliases
 *============================================================================*/

typedef arm_v8m_pmu_regs_t      arm_v8m_cm55_pmu_regs_t;
typedef arm_v8m_pmu_event_t     arm_v8m_cm55_pmu_event_t;

/*============================================================================*
 * Constant Aliases - Event Types
 *============================================================================*/

#define ARM_V8M_CM55_PMU_EVENT_SW_INCR              ARM_V8M_PMU_EVENT_SW_INCR
#define ARM_V8M_CM55_PMU_EVENT_L1I_CACHE_REFILL     ARM_V8M_PMU_EVENT_L1I_CACHE_REFILL
#define ARM_V8M_CM55_PMU_EVENT_L1D_CACHE_REFILL     ARM_V8M_PMU_EVENT_L1D_CACHE_REFILL
#define ARM_V8M_CM55_PMU_EVENT_L1D_CACHE            ARM_V8M_PMU_EVENT_L1D_CACHE
#define ARM_V8M_CM55_PMU_EVENT_LD_RETIRED           ARM_V8M_PMU_EVENT_LD_RETIRED
#define ARM_V8M_CM55_PMU_EVENT_ST_RETIRED           ARM_V8M_PMU_EVENT_ST_RETIRED
#define ARM_V8M_CM55_PMU_EVENT_INST_RETIRED         ARM_V8M_PMU_EVENT_INST_RETIRED
#define ARM_V8M_CM55_PMU_EVENT_EXC_TAKEN            ARM_V8M_PMU_EVENT_EXC_TAKEN
#define ARM_V8M_CM55_PMU_EVENT_EXC_RETURN           ARM_V8M_PMU_EVENT_EXC_RETURN
#define ARM_V8M_CM55_PMU_EVENT_CID_WRITE_RETIRED    ARM_V8M_PMU_EVENT_CID_WRITE_RETIRED
#define ARM_V8M_CM55_PMU_EVENT_PC_WRITE_RETIRED     ARM_V8M_PMU_EVENT_PC_WRITE_RETIRED
#define ARM_V8M_CM55_PMU_EVENT_BR_IMMED_RETIRED     ARM_V8M_PMU_EVENT_BR_IMMED_RETIRED
#define ARM_V8M_CM55_PMU_EVENT_BR_RETURN_RETIRED    ARM_V8M_PMU_EVENT_BR_RETURN_RETIRED
#define ARM_V8M_CM55_PMU_EVENT_UNALIGNED_LDST_RETIRED   ARM_V8M_PMU_EVENT_UNALIGNED_LDST_RETIRED
#define ARM_V8M_CM55_PMU_EVENT_BR_MIS_PRED          ARM_V8M_PMU_EVENT_BR_MIS_PRED
#define ARM_V8M_CM55_PMU_EVENT_CPU_CYCLES           ARM_V8M_PMU_EVENT_CPU_CYCLES
#define ARM_V8M_CM55_PMU_EVENT_BR_PRED              ARM_V8M_PMU_EVENT_BR_PRED
#define ARM_V8M_CM55_PMU_EVENT_MEM_ACCESS           ARM_V8M_PMU_EVENT_MEM_ACCESS
#define ARM_V8M_CM55_PMU_EVENT_L1I_CACHE            ARM_V8M_PMU_EVENT_L1I_CACHE
#define ARM_V8M_CM55_PMU_EVENT_L1D_CACHE_WB         ARM_V8M_PMU_EVENT_L1D_CACHE_WB
#define ARM_V8M_CM55_PMU_EVENT_L2D_CACHE            ARM_V8M_PMU_EVENT_L2D_CACHE
#define ARM_V8M_CM55_PMU_EVENT_L2D_CACHE_REFILL     ARM_V8M_PMU_EVENT_L2D_CACHE_REFILL
#define ARM_V8M_CM55_PMU_EVENT_L2D_CACHE_WB         ARM_V8M_PMU_EVENT_L2D_CACHE_WB
#define ARM_V8M_CM55_PMU_EVENT_BUS_ACCESS           ARM_V8M_PMU_EVENT_BUS_ACCESS
#define ARM_V8M_CM55_PMU_EVENT_MEMORY_ERROR         ARM_V8M_PMU_EVENT_MEMORY_ERROR
#define ARM_V8M_CM55_PMU_EVENT_INST_SPEC            ARM_V8M_PMU_EVENT_INST_SPEC
#define ARM_V8M_CM55_PMU_EVENT_TTBR_WRITE_RETIRED   ARM_V8M_PMU_EVENT_TTBR_WRITE_RETIRED
#define ARM_V8M_CM55_PMU_EVENT_CHAIN                ARM_V8M_PMU_EVENT_CHAIN

/*============================================================================*
 * Inline Function Wrappers - PMU Operations
 *============================================================================*/

static inline void arm_v8m_cm55_pmu_enable(void) {
    arm_v8m_pmu_enable();
}

static inline void arm_v8m_cm55_pmu_disable(void) {
    arm_v8m_pmu_disable();
}

static inline void arm_v8m_cm55_pmu_reset_counters(void) {
    arm_v8m_pmu_reset_counters();
}

static inline void arm_v8m_cm55_pmu_reset_cycle_counter(void) {
    arm_v8m_pmu_reset_cycle_counter();
}

static inline void arm_v8m_cm55_pmu_select_event_counter(uint32_t counter_num) {
    arm_v8m_pmu_select_event_counter(counter_num);
}

static inline void arm_v8m_cm55_pmu_configure_event(uint32_t counter_num, arm_v8m_cm55_pmu_event_t event) {
    arm_v8m_pmu_configure_event(counter_num, (arm_v8m_pmu_event_t)event);
}

static inline void arm_v8m_cm55_pmu_enable_event_counter(uint32_t counter_num) {
    arm_v8m_pmu_enable_event_counter(counter_num);
}

static inline void arm_v8m_cm55_pmu_disable_event_counter(uint32_t counter_num) {
    arm_v8m_pmu_disable_event_counter(counter_num);
}

static inline uint32_t arm_v8m_cm55_pmu_get_event_count(uint32_t counter_num) {
    return arm_v8m_pmu_get_event_count(counter_num);
}

static inline void arm_v8m_cm55_pmu_set_event_count(uint32_t counter_num, uint32_t value) {
    arm_v8m_pmu_set_event_count(counter_num, value);
}

static inline uint32_t arm_v8m_cm55_pmu_get_cycle_count(void) {
    return arm_v8m_pmu_get_cycle_count();
}

static inline void arm_v8m_cm55_pmu_set_cycle_count(uint32_t value) {
    arm_v8m_pmu_set_cycle_count(value);
}

static inline uint32_t arm_v8m_cm55_pmu_get_counter_count(void) {
    return arm_v8m_pmu_get_counter_count();
}

static inline uint32_t arm_v8m_cm55_pmu_get_version(void) {
    return arm_v8m_pmu_get_version();
}

#ifdef __cplusplus
}
#endif

#endif /* ARM_V8M_CM55_PMU_H */
