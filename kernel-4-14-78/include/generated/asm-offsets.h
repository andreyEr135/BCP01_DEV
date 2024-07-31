#ifndef __ASM_OFFSETS_H__
#define __ASM_OFFSETS_H__
/*
 * DO NOT MODIFY.
 *
 * This file was generated by Kbuild
 */

#define TSK_ACTIVE_MM 1000 /* offsetof(struct task_struct, active_mm) */

#define TSK_TI_FLAGS 0 /* offsetof(struct task_struct, thread_info.flags) */
#define TSK_TI_PREEMPT 16 /* offsetof(struct task_struct, thread_info.preempt_count) */
#define TSK_TI_ADDR_LIMIT 8 /* offsetof(struct task_struct, thread_info.addr_limit) */
#define TSK_STACK 32 /* offsetof(struct task_struct, stack) */

#define THREAD_CPU_CONTEXT 2288 /* offsetof(struct task_struct, thread.cpu_context) */

#define S_X0 0 /* offsetof(struct pt_regs, regs[0]) */
#define S_X1 8 /* offsetof(struct pt_regs, regs[1]) */
#define S_X2 16 /* offsetof(struct pt_regs, regs[2]) */
#define S_X3 24 /* offsetof(struct pt_regs, regs[3]) */
#define S_X4 32 /* offsetof(struct pt_regs, regs[4]) */
#define S_X5 40 /* offsetof(struct pt_regs, regs[5]) */
#define S_X6 48 /* offsetof(struct pt_regs, regs[6]) */
#define S_X7 56 /* offsetof(struct pt_regs, regs[7]) */
#define S_X8 64 /* offsetof(struct pt_regs, regs[8]) */
#define S_X10 80 /* offsetof(struct pt_regs, regs[10]) */
#define S_X12 96 /* offsetof(struct pt_regs, regs[12]) */
#define S_X14 112 /* offsetof(struct pt_regs, regs[14]) */
#define S_X16 128 /* offsetof(struct pt_regs, regs[16]) */
#define S_X18 144 /* offsetof(struct pt_regs, regs[18]) */
#define S_X20 160 /* offsetof(struct pt_regs, regs[20]) */
#define S_X22 176 /* offsetof(struct pt_regs, regs[22]) */
#define S_X24 192 /* offsetof(struct pt_regs, regs[24]) */
#define S_X26 208 /* offsetof(struct pt_regs, regs[26]) */
#define S_X28 224 /* offsetof(struct pt_regs, regs[28]) */
#define S_LR 240 /* offsetof(struct pt_regs, regs[30]) */
#define S_SP 248 /* offsetof(struct pt_regs, sp) */
#define S_COMPAT_SP 104 /* offsetof(struct pt_regs, compat_sp) */
#define S_PSTATE 264 /* offsetof(struct pt_regs, pstate) */
#define S_PC 256 /* offsetof(struct pt_regs, pc) */
#define S_ORIG_X0 272 /* offsetof(struct pt_regs, orig_x0) */
#define S_SYSCALLNO 280 /* offsetof(struct pt_regs, syscallno) */
#define S_ORIG_ADDR_LIMIT 288 /* offsetof(struct pt_regs, orig_addr_limit) */
#define S_STACKFRAME 304 /* offsetof(struct pt_regs, stackframe) */
#define S_FRAME_SIZE 320 /* sizeof(struct pt_regs) */

#define MM_CONTEXT_ID 720 /* offsetof(struct mm_struct, context.id.counter) */

#define VMA_VM_MM 64 /* offsetof(struct vm_area_struct, vm_mm) */
#define VMA_VM_FLAGS 80 /* offsetof(struct vm_area_struct, vm_flags) */

#define VM_EXEC 4 /* VM_EXEC */

#define PAGE_SZ 4096 /* PAGE_SIZE */

#define DMA_BIDIRECTIONAL 0 /* DMA_BIDIRECTIONAL */
#define DMA_TO_DEVICE 1 /* DMA_TO_DEVICE */
#define DMA_FROM_DEVICE 2 /* DMA_FROM_DEVICE */

#define CLOCK_REALTIME 0 /* CLOCK_REALTIME */
#define CLOCK_MONOTONIC 1 /* CLOCK_MONOTONIC */
#define CLOCK_MONOTONIC_RAW 4 /* CLOCK_MONOTONIC_RAW */
#define CLOCK_REALTIME_RES 1 /* MONOTONIC_RES_NSEC */
#define CLOCK_REALTIME_COARSE 5 /* CLOCK_REALTIME_COARSE */
#define CLOCK_MONOTONIC_COARSE 6 /* CLOCK_MONOTONIC_COARSE */
#define CLOCK_COARSE_RES 4000000 /* LOW_RES_NSEC */
#define NSEC_PER_SEC 1000000000 /* NSEC_PER_SEC */

#define VDSO_CS_CYCLE_LAST 0 /* offsetof(struct vdso_data, cs_cycle_last) */
#define VDSO_RAW_TIME_SEC 8 /* offsetof(struct vdso_data, raw_time_sec) */
#define VDSO_RAW_TIME_NSEC 16 /* offsetof(struct vdso_data, raw_time_nsec) */
#define VDSO_XTIME_CLK_SEC 24 /* offsetof(struct vdso_data, xtime_clock_sec) */
#define VDSO_XTIME_CLK_NSEC 32 /* offsetof(struct vdso_data, xtime_clock_nsec) */
#define VDSO_XTIME_CRS_SEC 40 /* offsetof(struct vdso_data, xtime_coarse_sec) */
#define VDSO_XTIME_CRS_NSEC 48 /* offsetof(struct vdso_data, xtime_coarse_nsec) */
#define VDSO_WTM_CLK_SEC 56 /* offsetof(struct vdso_data, wtm_clock_sec) */
#define VDSO_WTM_CLK_NSEC 64 /* offsetof(struct vdso_data, wtm_clock_nsec) */
#define VDSO_TB_SEQ_COUNT 72 /* offsetof(struct vdso_data, tb_seq_count) */
#define VDSO_CS_MONO_MULT 76 /* offsetof(struct vdso_data, cs_mono_mult) */
#define VDSO_CS_RAW_MULT 84 /* offsetof(struct vdso_data, cs_raw_mult) */
#define VDSO_CS_SHIFT 80 /* offsetof(struct vdso_data, cs_shift) */
#define VDSO_TZ_MINWEST 88 /* offsetof(struct vdso_data, tz_minuteswest) */
#define VDSO_TZ_DSTTIME 92 /* offsetof(struct vdso_data, tz_dsttime) */
#define VDSO_USE_SYSCALL 96 /* offsetof(struct vdso_data, use_syscall) */

#define TVAL_TV_SEC 0 /* offsetof(struct timeval, tv_sec) */
#define TVAL_TV_USEC 8 /* offsetof(struct timeval, tv_usec) */
#define TSPEC_TV_SEC 0 /* offsetof(struct timespec, tv_sec) */
#define TSPEC_TV_NSEC 8 /* offsetof(struct timespec, tv_nsec) */

#define TZ_MINWEST 0 /* offsetof(struct timezone, tz_minuteswest) */
#define TZ_DSTTIME 4 /* offsetof(struct timezone, tz_dsttime) */

#define CPU_BOOT_STACK 0 /* offsetof(struct secondary_data, stack) */
#define CPU_BOOT_TASK 8 /* offsetof(struct secondary_data, task) */

#define CPU_SUSPEND_SZ 112 /* sizeof(struct cpu_suspend_ctx) */
#define CPU_CTX_SP 96 /* offsetof(struct cpu_suspend_ctx, sp) */
#define MPIDR_HASH_MASK 0 /* offsetof(struct mpidr_hash, mask) */
#define MPIDR_HASH_SHIFTS 8 /* offsetof(struct mpidr_hash, shift_aff) */
#define SLEEP_STACK_DATA_SYSTEM_REGS 0 /* offsetof(struct sleep_stack_data, system_regs) */
#define SLEEP_STACK_DATA_CALLEE_REGS 112 /* offsetof(struct sleep_stack_data, callee_saved_regs) */
#define ARM_SMCCC_RES_X0_OFFS 0 /* offsetof(struct arm_smccc_res, a0) */
#define ARM_SMCCC_RES_X2_OFFS 16 /* offsetof(struct arm_smccc_res, a2) */
#define ARM_SMCCC_QUIRK_ID_OFFS 0 /* offsetof(struct arm_smccc_quirk, id) */
#define ARM_SMCCC_QUIRK_STATE_OFFS 8 /* offsetof(struct arm_smccc_quirk, state) */

#define HIBERN_PBE_ORIG 8 /* offsetof(struct pbe, orig_address) */
#define HIBERN_PBE_ADDR 0 /* offsetof(struct pbe, address) */
#define HIBERN_PBE_NEXT 16 /* offsetof(struct pbe, next) */
#define ARM64_FTR_SYSVAL 24 /* offsetof(struct arm64_ftr_reg, sys_val) */

#define TRAMP_VALIAS -142936536793088 /* TRAMP_VALIAS */

#endif
