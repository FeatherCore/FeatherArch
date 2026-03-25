/**
 * @file cm85_pmu.h
 * @brief Cortex-M85 Performance Monitoring Unit (PMU)
 *
 * @note Reference: Arm Cortex-M85 Devices Generic User Guide, Chapter 7
 * @note Reference: Arm Cortex-M85 Processor TRM, Chapter 17
 */

#ifndef CM85_PMU_H
#define CM85_PMU_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* PMU register structure */
typedef struct {
    volatile uint32_t EVCNTR[8];    /* Event Counter Registers */
    volatile uint32_t CCNTR;        /* Cycle Counter Register */
    uint32_t RESERVED0[2];
    volatile uint32_t EVTYPER[8];   /* Event Type and Filter Registers */
    volatile uint32_t CCFILTR;      /* Cycle Counter Filter Register */
    uint32_t RESERVED1[2];
    volatile uint32_t CNTENSET;     /* Count Enable Set Register */
    volatile uint32_t CNTENCLR;     /* Count Enable Clear Register */
    volatile uint32_t INTENSET;     /* Interrupt Enable Set Register */
    volatile uint32_t INTENCLR;     /* Interrupt Enable Clear Register */
    volatile uint32_t OVSCLR;       /* Overflow Flag Status Clear Register */
    volatile uint32_t OVSSET;       /* Overflow Flag Status Set Register */
    uint32_t RESERVED2[4];
    volatile uint32_t SWINC;        /* Software Increment Register */
    volatile uint32_t CTRL;         /* Control Register */
    volatile uint32_t TYPE;         /* Type Register */
} cm85_pmu_reg_t;

#define CM85_PMU_BASE       (0xE0003000UL)
#define CM85_PMU            ((cm85_pmu_reg_t *)CM85_PMU_BASE)

/* PMU event types */
typedef enum {
    CM85_PMU_EVENT_SWINCR = 0x00,
    CM85_PMU_EVENT_L1I_CACHE_REFILL = 0x01,
    CM85_PMU_EVENT_L1D_CACHE_REFILL = 0x03,
    CM85_PMU_EVENT_L1D_CACHE = 0x04,
    CM85_PMU_EVENT_LD_RETIRED = 0x06,
    CM85_PMU_EVENT_ST_RETIRED = 0x07,
    CM85_PMU_EVENT_INST_RETIRED = 0x08,
    CM85_PMU_EVENT_EXC_TAKEN = 0x09,
    CM85_PMU_EVENT_EXC_RETURN = 0x0A,
    CM85_PMU_EVENT_CID_WRITE_RETIRED = 0x0B,
    CM85_PMU_EVENT_PC_WRITE_RETIRED = 0x0C,
    CM85_PMU_EVENT_BR_IMMED_RETIRED = 0x0D,
    CM85_PMU_EVENT_BR_RETURN_RETIRED = 0x0E,
    CM85_PMU_EVENT_UNALIGNED_LDST_RETIRED = 0x0F,
    CM85_PMU_EVENT_BR_MIS_PRED = 0x10,
    CM85_PMU_EVENT_CPU_CYCLES = 0x11,
    CM85_PMU_EVENT_BR_PRED = 0x12,
    CM85_PMU_EVENT_MEM_ACCESS = 0x13,
    CM85_PMU_EVENT_L1I_CACHE = 0x14,
    CM85_PMU_EVENT_L1D_CACHE_WB = 0x15,
    CM85_PMU_EVENT_L2D_CACHE = 0x16,
    CM85_PMU_EVENT_L2D_CACHE_REFILL = 0x17,
    CM85_PMU_EVENT_L2D_CACHE_WB = 0x18,
    CM85_PMU_EVENT_BUS_ACCESS = 0x19,
    CM85_PMU_EVENT_MEMORY_ERROR = 0x1A,
    CM85_PMU_EVENT_INST_SPEC = 0x1B,
    CM85_PMU_EVENT_TTBR_WRITE_RETIRED = 0x1C,
    CM85_PMU_EVENT_BUS_CYCLES = 0x1D,
    CM85_PMU_EVENT_CHAIN = 0x1E,
    CM85_PMU_EVENT_L1D_CACHE_ALLOCATE = 0x1F,
    CM85_PMU_EVENT_L2D_CACHE_ALLOCATE = 0x20,
    CM85_PMU_EVENT_BR_RETIRED = 0x21,
    CM85_PMU_EVENT_BR_MIS_PRED_RETIRED = 0x22,
    CM85_PMU_EVENT_STALL_FRONTEND = 0x23,
    CM85_PMU_EVENT_STALL_BACKEND = 0x24,
    CM85_PMU_EVENT_L1I_TLB = 0x26,
    CM85_PMU_EVENT_L1D_TLB = 0x27,
    CM85_PMU_EVENT_L1I_TLB_REFILL = 0x28,
    CM85_PMU_EVENT_L1D_TLB_REFILL = 0x29,
    CM85_PMU_EVENT_L2D_TLB = 0x2A,
    CM85_PMU_EVENT_L2D_TLB_REFILL = 0x2B,
    CM85_PMU_EVENT_MVE_INST_RETIRED = 0x80,
    CM85_PMU_EVENT_MVE_FP_RETIRED = 0x81,
    CM85_PMU_EVENT_MVE_FP_SPEC = 0x82,
    CM85_PMU_EVENT_MVE_INST_SPEC = 0x83,
    CM85_PMU_EVENT_MVE_LD_ST_RETIRED = 0x84,
    CM85_PMU_EVENT_MVE_LD_ST_SPEC = 0x85,
    CM85_PMU_EVENT_MVE_INTEGER_RETIRED = 0x86,
    CM85_PMU_EVENT_MVE_INTEGER_SPEC = 0x87,
    CM85_PMU_EVENT_MVE_PREDICATE_RETIRED = 0x88,
    CM85_PMU_EVENT_MVE_PREDICATE_SPEC = 0x89,
    CM85_PMU_EVENT_ITCM_ACCESS = 0xA0,
    CM85_PMU_EVENT_DTCM_ACCESS = 0xA1,
    CM85_PMU_EVENT_ITGU_ERR = 0xA2,
    CM85_PMU_EVENT_DTGU_ERR = 0xA3,
    CM85_PMU_EVENT_ICACHE_ERR = 0xA4,
    CM85_PMU_EVENT_DCACHE_ERR = 0xA5,
    CM85_PMU_EVENT_TCM_ERR = 0xA6,
    CM85_PMU_EVENT_ITGU_ERR_MAYBE = 0xA7,
    CM85_PMU_EVENT_DTGU_ERR_MAYBE = 0xA8,
    CM85_PMU_EVENT_ICACHE_ERR_MAYBE = 0xA9,
    CM85_PMU_EVENT_DCACHE_ERR_MAYBE = 0xAA,
    CM85_PMU_EVENT_TCM_ERR_MAYBE = 0xAB
} cm85_pmu_event_t;

/* PMU initialization */
int cm85_pmu_init(void);
void cm85_pmu_deinit(void);
void cm85_pmu_enable(void);
void cm85_pmu_disable(void);
bool cm85_pmu_is_enabled(void);

/* Event counter configuration */
void cm85_pmu_configure_event(uint32_t counter, cm85_pmu_event_t event);
void cm85_pmu_enable_counter(uint32_t counter);
void cm85_pmu_disable_counter(uint32_t counter);
uint32_t cm85_pmu_get_counter(uint32_t counter);
void cm85_pmu_set_counter(uint32_t counter, uint32_t value);
void cm85_pmu_reset_counter(uint32_t counter);

/* Cycle counter */
void cm85_pmu_enable_cycle_counter(void);
void cm85_pmu_disable_cycle_counter(void);
uint32_t cm85_pmu_get_cycle_count(void);
void cm85_pmu_set_cycle_count(uint32_t value);
void cm85_pmu_reset_cycle_count(void);

/* Counter chaining */
void cm85_pmu_chain_counters(uint32_t even_counter);
void cm85_pmu_unchain_counters(uint32_t even_counter);

/* Overflow handling */
uint32_t cm85_pmu_get_overflow_status(void);
void cm85_pmu_clear_overflow(uint32_t mask);
void cm85_pmu_enable_overflow_interrupt(uint32_t counter);
void cm85_pmu_disable_overflow_interrupt(uint32_t counter);

/* Software increment */
void cm85_pmu_software_increment(uint32_t counter);

/* Feature detection */
uint32_t cm85_pmu_get_num_counters(void);
bool cm85_pmu_has_cycle_counter(void);

#ifdef __cplusplus
}
#endif

#endif /* CM85_PMU_H */
