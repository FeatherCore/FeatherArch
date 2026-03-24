/*
 * ARM Architecture - ARMv7-M Debug Architecture Implementation
 *
 * ============================================================================
 * File: armv7-m_debug.c
 * Description: ARMv7-M Debug Architecture function implementations
 * 描述: ARMv7-M 调试架构函数实现
 *
 * Reference: Arm(R) v7-M Architecture Reference Manual (DDI 0403E.e)
 *   - Chapter C1: Debug Architecture
 *     * C1.7 The Instrumentation Trace Macrocell (page C1-709)
 *       - ITM operation, stimulus ports, timestamp support
 *     * C1.8 The Data Watchpoint and Trace unit (page C1-719)
 *       - DWT comparators, cycle counter, profiling counters
 *     * C1.11 Flash Patch and Breakpoint unit (page C1-755)
 *       - FPB remapping and breakpoint functionality
 * ============================================================================
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stddef.h>
#include "armv7-m/armv7-m_debug.h"
#include "armv7-m/armv7-m_scs_debug.h"

/*
 * ============================================================================
 * ITM (Instrumentation Trace Macrocell) Functions
 * ITM 函数实现
 * Reference: C1.7 The Instrumentation Trace Macrocell (page C1-709)
 * ============================================================================
 */

/**
 * @brief Initialize and enable ITM
 * 初始化并使能ITM
 * 
 * Initializes ITM with default settings:
 * - Enables ITM global
 * - Enables stimulus port 0 for printf-style debugging
 * - Enables DWT packet transmission
 * - Enables local timestamps
 * 
 * Reference: C1.7.1 ITM operation (page C1-709)
 */
void itm_init(void)
{
    /* Enable trace in DEMCR first */
    scs_debug_enable_trace();
    
    /* Enable ITM */
    itm_enable();
    
    /* Enable stimulus port 0 for character output */
    itm_enable_stimulus_port(0);
    
    /* Enable DWT packet transmission through ITM */
    itm_enable_dwt_tx();
    
    /* Enable local timestamps */
    itm_enable_local_timestamps();
}

/**
 * @brief Enable ITM
 * 使能ITM
 * 
 * Sets ITM_TCR.ITMENA to enable the ITM.
 * 
 * Reference: C1.7.6 Trace Control Register, ITM_TCR (page C1-716)
 */
void itm_enable(void)
{
    ITM_TCR |= ITM_TCR_ITMENA_Msk;
}

/**
 * @brief Disable ITM
 * 禁用ITM
 * 
 * Clears ITM_TCR.ITMENA to disable the ITM.
 * 
 * Reference: C1.7.6 Trace Control Register, ITM_TCR (page C1-716)
 */
void itm_disable(void)
{
    ITM_TCR &= ~ITM_TCR_ITMENA_Msk;
}

/**
 * @brief Check if ITM is enabled
 * 检查ITM是否使能
 * @return true if ITM_TCR.ITMENA is set
 */
bool itm_is_enabled(void)
{
    return (ITM_TCR & ITM_TCR_ITMENA_Msk) != 0U;
}

/**
 * @brief Send character via ITM (port 0)
 * 通过ITM发送字符(端口0)
 * @param ch Character to send
 * @return Character sent or -1 if port not ready
 * 
 * Reference: C1.7.1 ITM operation (page C1-709)
 */
int32_t itm_send_char(int32_t ch)
{
    /* Check if ITM is enabled and port 0 is ready */
    if ((ITM_TCR & ITM_TCR_ITMENA_Msk) == 0U) {
        return -1;
    }
    
    if ((ITM_TER(0) & 0x1U) == 0U) {
        return -1;
    }
    
    /* Wait for stimulus port to be ready (FIFO not full) */
    if (!itm_stimulus_port_ready(0)) {
        return -1;
    }
    
    ITM_STIM(0) = (uint8_t)ch;
    return ch;
}

/**
 * @brief Send string via ITM (port 0)
 * 通过ITM发送字符串(端口0)
 * @param str String to send
 * @return Number of characters sent
 */
int32_t itm_send_string(const char *str)
{
    int32_t count = 0;
    
    if (str == NULL) {
        return 0;
    }
    
    while (*str != '\0') {
        if (itm_send_char(*str) < 0) {
            break;
        }
        str++;
        count++;
    }
    
    return count;
}

/**
 * @brief Receive character via ITM
 * 通过ITM接收字符
 * @return Character received or -1 if no data
 * 
 * Note: ITM is primarily for output. Reception is not typically supported
 * in basic implementations.
 */
int32_t itm_receive_char(void)
{
    /* ITM reception is not typically implemented */
    return -1;
}

/**
 * @brief Enable ITM stimulus port
 * 使能ITM刺激端口
 * @param port Port number (0-255)
 * 
 * Sets the corresponding bit in ITM_TER to enable the stimulus port.
 * 
 * Reference: C1.7.4 Trace Enable Registers, ITM_TER0-ITM_TER7 (page C1-714)
 */
void itm_enable_stimulus_port(uint32_t port)
{
    if (port < 256) {
        ITM_TER(port / 32) |= (1UL << (port % 32));
    }
}

/**
 * @brief Disable ITM stimulus port
 * 禁用ITM刺激端口
 * @param port Port number (0-255)
 * 
 * Clears the corresponding bit in ITM_TER to disable the stimulus port.
 * 
 * Reference: C1.7.4 Trace Enable Registers, ITM_TER0-ITM_TER7 (page C1-714)
 */
void itm_disable_stimulus_port(uint32_t port)
{
    if (port < 256) {
        ITM_TER(port / 32) &= ~(1UL << (port % 32));
    }
}

/**
 * @brief Check if ITM stimulus port is enabled
 * 检查ITM刺激端口是否使能
 * @param port Port number (0-255)
 * @return true if enabled
 */
bool itm_is_stimulus_port_enabled(uint32_t port)
{
    if (port < 256) {
        return (ITM_TER(port / 32) & (1UL << (port % 32))) != 0U;
    }
    return false;
}

/**
 * @brief Enable local timestamp generation
 * 使能本地时间戳生成
 * 
 * Sets ITM_TCR.TSENA to enable local timestamp packets.
 * 
 * Reference: C1.7.1 ITM operation - Local timestamping (page C1-710)
 */
void itm_enable_local_timestamps(void)
{
    ITM_TCR |= ITM_TCR_TSENA_Msk;
}

/**
 * @brief Disable local timestamp generation
 * 禁用本地时间戳生成
 */
void itm_disable_local_timestamps(void)
{
    ITM_TCR &= ~ITM_TCR_TSENA_Msk;
}

/**
 * @brief Set local timestamp prescaler
 * 设置本地时间戳预分频器
 * @param prescale Prescaler value (0=div1, 1=div4, 2=div16, 3=div64)
 * 
 * Reference: C1.7.6 Trace Control Register, ITM_TCR (page C1-716)
 */
void itm_set_timestamp_prescaler(uint32_t prescale)
{
    uint32_t tcr = ITM_TCR;
    tcr &= ~ITM_TCR_TSPRESCALE_Msk;
    tcr |= (prescale << ITM_TCR_TSPRESCALE_Pos) & ITM_TCR_TSPRESCALE_Msk;
    ITM_TCR = tcr;
}

/**
 * @brief Enable DWT packet transmission through ITM
 * 使能通过ITM传输DWT数据包
 * 
 * Sets ITM_TCR.TXENA to enable DWT packet forwarding to ITM.
 * 
 * Reference: C1.7.6 Trace Control Register, ITM_TCR (page C1-716)
 */
void itm_enable_dwt_tx(void)
{
    ITM_TCR |= ITM_TCR_TXENA_Msk;
}

/**
 * @brief Disable DWT packet transmission through ITM
 * 禁用通过ITM传输DWT数据包
 */
void itm_disable_dwt_tx(void)
{
    ITM_TCR &= ~ITM_TCR_TXENA_Msk;
}

/*
 * ============================================================================
 * DWT (Data Watchpoint and Trace) Functions
 * DWT 函数实现
 * Reference: C1.8 The Data Watchpoint and Trace unit (page C1-719)
 * ============================================================================
 */

/**
 * @brief Initialize DWT
 * 初始化DWT
 * 
 * Initializes DWT with default settings:
 * - Enables trace in DEMCR
 * - Enables cycle counter if available
 * 
 * Reference: C1.8 The Data Watchpoint and Trace unit (page C1-719)
 */
void dwt_init(void)
{
    /* Enable trace in DEMCR */
    scs_debug_enable_trace();
    
    /* Enable cycle counter if available */
    if (dwt_has_cycle_counter()) {
        dwt_enable_cycle_counter();
    }
}

/**
 * @brief Enable DWT
 * 使能DWT
 * 
 * Note: DWT is enabled by setting DEMCR.TRCENA=1
 */
void dwt_enable(void)
{
    scs_debug_enable_trace();
}

/**
 * @brief Disable DWT
 * 禁用DWT
 */
void dwt_disable(void)
{
    scs_debug_disable_trace();
}

/**
 * @brief Check if DWT is available
 * 检查DWT是否可用
 * @return true if DWT is implemented
 * 
 * Checks ROM table entry for DWT presence.
 * 
 * Reference: C1.1.1 Debug support in Armv7-M (page C1-683)
 */
bool dwt_is_available(void)
{
    return (ROM_DWT & ROM_ENTRY_PRESENT_Msk) != 0U;
}

/**
 * @brief Enable DWT cycle counter
 * 使能DWT周期计数器
 * 
 * Sets DWT_CTRL.CYCCNTENA to enable the cycle counter.
 * 
 * Reference: C1.8.9 Cycle Count register, DWT_CYCCNT (page C1-741)
 */
void dwt_enable_cycle_counter(void)
{
    DWT_CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

/**
 * @brief Disable DWT cycle counter
 * 禁用DWT周期计数器
 * 
 * Clears DWT_CTRL.CYCCNTENA to disable the cycle counter.
 * 
 * Reference: C1.8.9 Cycle Count register, DWT_CYCCNT (page C1-741)
 */
void dwt_disable_cycle_counter(void)
{
    DWT_CTRL &= ~DWT_CTRL_CYCCNTENA_Msk;
}

/**
 * @brief Configure DWT comparator for address matching
 * 配置DWT比较器进行地址匹配
 * @param comp Comparator number (0-14)
 * @param addr Address to compare
 * @param mask Address mask (0-31, number of bits to mask)
 * @param function Function to perform on match
 * 
 * Configures a DWT comparator for address-based watchpoint or tracing.
 * 
 * Reference: C1.8.1 The DWT comparators (page C1-720)
 */
void dwt_configure_comparator(uint32_t comp, uint32_t addr, uint32_t mask, uint32_t function)
{
    if (comp >= dwt_get_num_comparators()) {
        return;
    }
    
    /* Disable comparator first */
    DWT_FUNCTION(comp) = DWT_FUNCTION_FUNCTION_DISABLED;
    
    /* Set comparison value */
    DWT_COMP(comp) = addr;
    
    /* Set mask (limited to 0-31) */
    if (mask > 31) {
        mask = 31;
    }
    DWT_MASK(comp) = mask;
    
    /* Set function (enable comparator) */
    DWT_FUNCTION(comp) = function & DWT_FUNCTION_FUNCTION_Msk;
}

/**
 * @brief Configure DWT comparator for data value matching
 * 配置DWT比较器进行数据值匹配
 * @param comp Comparator number
 * @param addr Data address
 * @param value Data value to match
 * @param size Data size (0=byte, 1=half, 2=word)
 * @param rw Read/write access type
 * 
 * Reference: C1.8.1 The DWT comparators (page C1-720)
 */
void dwt_configure_data_value_match(uint32_t comp, uint32_t addr, uint32_t value, 
                                     uint32_t size, uint32_t rw)
{
    if (comp >= dwt_get_num_comparators()) {
        return;
    }
    
    /* Disable comparator first */
    DWT_FUNCTION(comp) = DWT_FUNCTION_FUNCTION_DISABLED;
    
    /* Set data address */
    DWT_COMP(comp) = addr;
    
    /* Set data value in comparator (implementation dependent) */
    /* Note: Some implementations use linked comparators for data value matching */
    
    /* Configure function with data value match */
    uint32_t function = DWT_FUNCTION_DATAVMATCH_Msk;
    function |= (size << DWT_FUNCTION_DATAVSIZE_Pos) & DWT_FUNCTION_DATAVSIZE_Msk;
    function |= rw & DWT_FUNCTION_FUNCTION_Msk;
    
    DWT_FUNCTION(comp) = function;
}

/**
 * @brief Enable DWT comparator
 * 使能DWT比较器
 * @param comp Comparator number
 */
void dwt_enable_comparator(uint32_t comp)
{
    if (comp < dwt_get_num_comparators()) {
        uint32_t function = DWT_FUNCTION(comp);
        if ((function & DWT_FUNCTION_FUNCTION_Msk) == DWT_FUNCTION_FUNCTION_DISABLED) {
            /* Default to instruction address match if not configured */
            function |= DWT_FUNCTION_FUNCTION_INSTR_ADDR;
        }
        DWT_FUNCTION(comp) = function;
    }
}

/**
 * @brief Disable DWT comparator
 * 禁用DWT比较器
 * @param comp Comparator number
 */
void dwt_disable_comparator(uint32_t comp)
{
    if (comp < dwt_get_num_comparators()) {
        DWT_FUNCTION(comp) = DWT_FUNCTION_FUNCTION_DISABLED;
    }
}

/**
 * @brief Check if DWT comparator is matched
 * 检查DWT比较器是否匹配
 * @param comp Comparator number
 * @return true if matched
 */
bool dwt_is_comparator_matched(uint32_t comp)
{
    if (comp < dwt_get_num_comparators()) {
        return (DWT_FUNCTION(comp) & DWT_FUNCTION_MATCHED_Msk) != 0U;
    }
    return false;
}

/**
 * @brief Enable exception trace
 * 使能异常跟踪
 * 
 * Sets DWT_CTRL.EXCTRCENA to enable exception entry/exit trace packets.
 * 
 * Reference: C1.8.2 Exception trace support (page C1-731)
 */
void dwt_enable_exception_trace(void)
{
    DWT_CTRL |= DWT_CTRL_EXCTRCENA_Msk;
}

/**
 * @brief Disable exception trace
 * 禁用异常跟踪
 */
void dwt_disable_exception_trace(void)
{
    DWT_CTRL &= ~DWT_CTRL_EXCTRCENA_Msk;
}

/**
 * @brief Enable PC sampling
 * 使能PC采样
 * 
 * Sets DWT_CTRL.PCSAMPLENA to enable periodic PC sampling.
 * 
 * Reference: C1.8.6 Profiling counter support (page C1-734)
 */
void dwt_enable_pc_sampling(void)
{
    DWT_CTRL |= DWT_CTRL_PCSAMPLENA_Msk;
}

/**
 * @brief Disable PC sampling
 * 禁用PC采样
 */
void dwt_disable_pc_sampling(void)
{
    DWT_CTRL &= ~DWT_CTRL_PCSAMPLENA_Msk;
}

/**
 * @brief Enable profiling counters
 * 使能性能分析计数器
 * 
 * Enables CPI, exception, sleep, LSU, and folded instruction counters.
 * 
 * Reference: C1.8.6 Profiling counter support (page C1-734)
 */
void dwt_enable_profiling_counters(void)
{
    DWT_CTRL |= (DWT_CTRL_CPIEVTENA_Msk |
                 DWT_CTRL_EXCEVTENA_Msk |
                 DWT_CTRL_SLEEPEVTENA_Msk |
                 DWT_CTRL_LSUEVTENA_Msk |
                 DWT_CTRL_FOLDEVTENA_Msk);
}

/**
 * @brief Disable profiling counters
 * 禁用性能分析计数器
 */
void dwt_disable_profiling_counters(void)
{
    DWT_CTRL &= ~(DWT_CTRL_CPIEVTENA_Msk |
                  DWT_CTRL_EXCEVTENA_Msk |
                  DWT_CTRL_SLEEPEVTENA_Msk |
                  DWT_CTRL_LSUEVTENA_Msk |
                  DWT_CTRL_FOLDEVTENA_Msk);
}

/*
 * ============================================================================
 * FPB (Flash Patch and Breakpoint) Functions
 * FPB 函数实现
 * Reference: C1.11 Flash Patch and Breakpoint unit (page C1-755)
 * ============================================================================
 */

/**
 * @brief Initialize FPB
 * 初始化FPB
 * 
 * Disables all comparators and clears FPB settings.
 * 
 * Reference: C1.11 Flash Patch and Breakpoint unit (page C1-755)
 */
void fpb_init(void)
{
    /* Disable FPB first */
    fpb_disable();
    
    /* Clear all comparators */
    fpb_clear_all();
}

/**
 * @brief Enable FPB
 * 使能FPB
 * 
 * Sets FP_CTRL.ENABLE with the required key.
 * 
 * Reference: C1.11.3 Flash Patch Control Register, FP_CTRL (page C1-756)
 */
void fpb_enable(void)
{
    FP_CTRL = FP_CTRL_KEY_Msk | FP_CTRL_ENABLE_Msk;
}

/**
 * @brief Disable FPB
 * 禁用FPB
 * 
 * Clears FP_CTRL.ENABLE while maintaining the key.
 * 
 * Reference: C1.11.3 Flash Patch Control Register, FP_CTRL (page C1-756)
 */
void fpb_disable(void)
{
    FP_CTRL = FP_CTRL_KEY_Msk;
}

/**
 * @brief Check if FPB is available
 * 检查FPB是否可用
 * @return true if FPB is implemented
 * 
 * Checks ROM table entry for FPB presence.
 * 
 * Reference: C1.1.1 Debug support in Armv7-M (page C1-683)
 */
bool fpb_is_available(void)
{
    return (ROM_FPB & ROM_ENTRY_PRESENT_Msk) != 0U;
}

/**
 * @brief Check if FPB remapping is supported
 * 检查FPB是否支持重映射
 * @return true if remapping is supported
 * 
 * Checks FP_REMAP.RMPSPT bit.
 * 
 * Reference: C1.11.4 Flash Patch Remap register, FP_REMAP (page C1-758)
 */
bool fpb_has_remap_support(void)
{
    return (FP_REMAP & FP_REMAP_RMPSPT_Msk) != 0U;
}

/**
 * @brief Get number of FPB instruction address comparators
 * 获取FPB指令地址比较器数量
 * @return Number of instruction address comparators (0-127)
 * 
 * Reference: C1.11.3 Flash Patch Control Register, FP_CTRL (page C1-756)
 */
uint32_t fpb_get_num_code_comparators(void)
{
    uint32_t num_code = (FP_CTRL & FP_CTRL_NUM_CODE_Msk) >> FP_CTRL_NUM_CODE_Pos;
    uint32_t num_code2 = (FP_CTRL & FP_CTRL_NUM_CODE2_Msk) >> FP_CTRL_NUM_CODE2_Pos;
    return num_code | (num_code2 << 4);
}

/**
 * @brief Get number of FPB literal address comparators
 * 获取FPB文字地址比较器数量
 * @return Number of literal address comparators (0-15)
 * 
 * Reference: C1.11.3 Flash Patch Control Register, FP_CTRL (page C1-756)
 */
uint32_t fpb_get_num_literal_comparators(void)
{
    return (FP_CTRL & FP_CTRL_NUM_LIT_Msk) >> FP_CTRL_NUM_LIT_Pos;
}

/**
 * @brief Set FPB breakpoint
 * 设置FPB断点
 * @param bp Breakpoint number (0 to NUM_CODE-1)
 * @param addr Address (must be in Code region, first 0.5GB)
 * @param replace Replace control (which halfword to break on)
 * @return 0 on success, -1 on error
 * 
 * Configures an instruction address comparator for breakpoint generation.
 * 
 * Reference: C1.11.5 Flash Patch Comparator register, FP_COMPn (page C1-758)
 */
int32_t fpb_set_breakpoint(uint32_t bp, uint32_t addr, uint32_t replace)
{
    if (bp >= fpb_get_num_code_comparators()) {
        return -1;
    }
    
    if (replace > 3) {
        replace = 3;
    }
    
    /* Address must be word-aligned for instruction breakpoints */
    uint32_t comp_value = (addr & FP_COMP_COMP_Msk) | 
                          ((replace << FP_COMP_REPLACE_Pos) & FP_COMP_REPLACE_Msk) |
                          FP_COMP_ENABLE_Msk;
    
    FP_COMP(bp) = comp_value;
    return 0;
}

/**
 * @brief Clear FPB breakpoint
 * 清除FPB断点
 * @param bp Breakpoint number
 * 
 * Disables the specified breakpoint comparator.
 * 
 * Reference: C1.11.5 Flash Patch Comparator register, FP_COMPn (page C1-758)
 */
void fpb_clear_breakpoint(uint32_t bp)
{
    if (bp < fpb_get_num_code_comparators()) {
        FP_COMP(bp) = 0;
    }
}

/**
 * @brief Set FPB literal remap
 * 设置FPB文字重映射
 * @param lit Literal comparator number (starts at NUM_CODE)
 * @param literal_addr Literal address in Code region
 * @param remap_addr Remap address in SRAM region
 * @return 0 on success, -1 on error
 * 
 * Reference: C1.11.1 FPB unit operation (page C1-755)
 */
int32_t fpb_set_literal_remap(uint32_t lit, uint32_t literal_addr, uint32_t remap_addr)
{
    uint32_t num_code = fpb_get_num_code_comparators();
    uint32_t num_lit = fpb_get_num_literal_comparators();
    
    /* Literal comparators start after instruction comparators */
    if ((lit < num_code) || (lit >= (num_code + num_lit))) {
        return -1;
    }
    
    if (!fpb_has_remap_support()) {
        return -1;
    }
    
    /* Set remap base address if not already set */
    if ((FP_REMAP & FP_REMAP_REMAP_Msk) == 0) {
        /* Default remap base - must be 32-byte aligned */
        fpb_set_remap_base(0x20000000U);
    }
    
    /* Configure literal comparator */
    FP_COMP(lit) = (literal_addr & FP_COMP_COMP_Msk) | FP_COMP_ENABLE_Msk;
    
    return 0;
}

/**
 * @brief Set FPB instruction remap
 * 设置FPB指令重映射
 * @param bp Breakpoint number
 * @param instr_addr Instruction address in Code region
 * @param remap_addr Remap address in SRAM region
 * @return 0 on success, -1 on error
 * 
 * Reference: C1.11.1 FPB unit operation (page C1-755)
 */
int32_t fpb_set_instruction_remap(uint32_t bp, uint32_t instr_addr, uint32_t remap_addr)
{
    if (bp >= fpb_get_num_code_comparators()) {
        return -1;
    }
    
    if (!fpb_has_remap_support()) {
        return -1;
    }
    
    /* Set remap base address */
    fpb_set_remap_base(remap_addr);
    
    /* Configure instruction comparator for remapping */
    /* REPLACE field is 0 for remapping */
    FP_COMP(bp) = (instr_addr & FP_COMP_COMP_Msk) | FP_COMP_ENABLE_Msk;
    
    return 0;
}

/**
 * @brief Set FPB remap base address
 * 设置FPB重映射基地址
 * @param base_addr Base address for remapped code (must be 32-byte aligned)
 * 
 * Sets the base address for remapped instructions/literals.
 * 
 * Reference: C1.11.4 Flash Patch Remap register, FP_REMAP (page C1-758)
 */
void fpb_set_remap_base(uint32_t base_addr)
{
    /* Address must be 32-byte aligned */
    FP_REMAP = (base_addr & FP_REMAP_REMAP_Msk);
}

/**
 * @brief Get FPB remap base address
 * 获取FPB重映射基地址
 * @return Remap base address
 */
uint32_t fpb_get_remap_base(void)
{
    return FP_REMAP & FP_REMAP_REMAP_Msk;
}

/**
 * @brief Clear all FPB comparators
 * 清除所有FPB比较器
 * 
 * Disables all instruction and literal comparators.
 */
void fpb_clear_all(void)
{
    uint32_t num_comps = fpb_get_num_comparators();
    
    for (uint32_t i = 0; i < num_comps; i++) {
        FP_COMP(i) = 0;
    }
}
