# CMSIS Core Rust Implementation Plan

## 目标
从顶层目录开始逐个文件实现 rust-cmsis-core，严格对齐 CMSIS_6\CMSIS\Core 的具体实现。

## 文件映射关系

### 顶层文件 (Include/)
| CMSIS C Header | Rust Module | Status |
|----------------|-------------|--------|
| cmsis_version.h | src/version.rs | ✅ Done |
| cmsis_clang.h | src/intrinsics.rs | 🔄 In Progress |
| cmsis_compiler.h | (Rust 不需要) | ❌ Skip |
| cmsis_gcc.h | (Rust 不需要) | ❌ Skip |
| cmsis_iccarm.h | (Rust 不需要) | ❌ Skip |
| cmsis_armclang.h | (Rust 不需要) | ❌ Skip |
| core_cm*.h | src/m_profile/processors/cm*.rs | 🔄 To Do |
| core_ca*.h | src/a_profile/processors/ca*.rs | 🔄 To Do |
| core_cr*.h | src/r_profile/processors/cr*.rs | 🔄 To Do |
| tz_context.h | src/trustzone/context.rs | 🔄 To Do |

### M-Profile (Include/m-profile/)
| CMSIS C Header | Rust Module | Status |
|----------------|-------------|--------|
| cmsis_clang_m.h | src/m_profile/mod.rs + intrinsics | 🔄 To Do |
| armv7m_mpu.h | src/m_profile/mpu/armv7m.rs | 🔄 To Do |
| armv8m_mpu.h | src/m_profile/mpu/armv8m.rs | 🔄 To Do |
| armv7m_cachel1.h | src/m_profile/cache/l1.rs | 🔄 To Do |
| armv8m_pmu.h | src/m_profile/pmu/armv8m.rs | 🔄 To Do |
| armv81m_pac.h | src/m_profile/pac/armv81m.rs | 🔄 To Do |

### A-Profile (Include/a-profile/)
| CMSIS C Header | Rust Module | Status |
|----------------|-------------|--------|
| cmsis_clang_a.h | src/a_profile/mod.rs + intrinsics | 🔄 To Do |
| armv7a.h | src/a_profile/cp15/armv7a.rs | 🔄 To Do |
| armv8a.h | src/a_profile/cp15/armv8a.rs | 🔄 To Do |
| armv7a_cp15.h | src/a_profile/cp15/armv7a.rs | 🔄 To Do |
| armv8a_cp15.h | src/a_profile/cp15/armv8a.rs | 🔄 To Do |
| gicv2.h | src/a_profile/gic/v2.rs | 🔄 To Do |
| irq_ctrl.h | src/a_profile/irq_ctrl.rs | 🔄 To Do |

### R-Profile (Include/r-profile/)
| CMSIS C Header | Rust Module | Status |
|----------------|-------------|--------|
| cmsis_clang_r.h | src/r_profile/mod.rs + intrinsics | 🔄 To Do |
| armv7r.h | src/r_profile/cp15/armv7r.rs | 🔄 To Do |
| armv8r.h | src/r_profile/cp15/armv8r.rs | 🔄 To Do |
| armv7r_cp15.h | src/r_profile/cp15/armv7r.rs | 🔄 To Do |
| armv8r_cp15.h.h | src/r_profile/cp15/armv8r.rs | 🔄 To Do |
| gicv2.h | src/r_profile/gic/v2.rs | 🔄 To Do |

### Source/
| CMSIS C Source | Rust Module | Status |
|----------------|-------------|--------|
| irq_ctrl_gic.c | src/source/irq_ctrl_gic.rs | 🔄 To Do |

## 实现优先级

1. **P0 - 核心基础** (立即实现)
   - ✅ version.rs - CMSIS 版本定义
   - 🔄 intrinsics.rs - 所有 intrinsic 函数
   - 🔄 m_profile 基础 intrinsics

2. **P1 - M-Profile** (优先实现，因为是主要的 MCU 目标)
   - processors: cm0, cm0plus, cm3, cm4, cm7, cm23, cm33, cm35p, cm52, cm55, cm85
   - mpu: armv7m, armv8m
   - cache: l1 cache
   - pmu: armv8m
   - pac: armv81m

3. **P2 - A-Profile** (Cortex-A 系列)
   - processors: ca5, ca7, ca9, ca35, ca53, ca55, ca57
   - cp15: armv7a, armv8a
   - gic: v2
   - irq_ctrl

4. **P3 - R-Profile** (Cortex-R 系列)
   - processors: cr4, cr5, cr7, cr8
   - cp15: armv7r, armv8r
   - gic: v2

5. **P4 - TrustZone**
   - trustzone/context.rs

## 实现原则

1. **严格对齐**: 所有函数定义、注释、常量定义必须与 CMSIS_6 完全对齐
2. **Clang/LLVM only**: 只关注 clang/llvm 相关的实现分支
3. **注释对齐**: Rust 注释要与 C 头文件的注释保持一致
4. **优先未实现**: 优先实现未实现的功能，然后检查已实现的内容
