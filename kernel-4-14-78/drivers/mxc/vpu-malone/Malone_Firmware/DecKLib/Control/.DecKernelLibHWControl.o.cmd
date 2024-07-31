cmd_drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/Control/DecKernelLibHWControl.o := aarch64-linux-gnu-gcc -Wp,-MD,drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/Control/.DecKernelLibHWControl.o.d  -nostdinc -isystem /usr/lib/gcc-cross/aarch64-linux-gnu/7/include -I./arch/arm64/include -I./arch/arm64/include/generated  -I./include -I./arch/arm64/include/uapi -I./arch/arm64/include/generated/uapi -I./include/uapi -I./include/generated/uapi -include ./include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -fshort-wchar -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-PIE -mgeneral-regs-only -DCONFIG_AS_LSE=1 -fno-asynchronous-unwind-tables -mpc-relative-literal-loads -mabi=lp64 -fno-delete-null-pointer-checks -Wno-frame-address -Wno-format-truncation -Wno-format-overflow -Wno-int-in-bool-context -Os -Wno-maybe-uninitialized --param=allow-store-data-races=0 -DCC_HAVE_ASM_GOTO -Wframe-larger-than=2048 -fno-stack-protector -Wno-unused-but-set-variable -Wno-unused-const-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-var-tracking-assignments -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fno-merge-all-constants -fmerge-constants -fno-stack-check -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -DDTV_GATHER_PERF_METRICS -DMVD_DTV_USERDATA -DMVD_WAIT_BOB_INACTIVE -DDECLIB_FORCE_HW_STOP -DMVD_NO_BSDMA_SAFETY_MARGIN -DMVD_CQ_ENABLE_REFILL -DMVD_SPP_HW_GOULOMB -DSVC_SFA_ADD_ERROR_CHECKING -DMVC_SFA_ADD_ERROR_CHECKING -DSVC_SPP_SAVE_CTX_PER_VCL_NAL -DMVD_CQ_CQSR -DAVC_SUPPORT_THRU_MVC -DMVC_ERROR_CONTROL_INSERT_SKIP_START_CONTROLS -DDECLIB_CTX_FLUSH_AFTER_SAVE -DDECLIB_SERVICE_EOS -DMVD_PERF_MEASURE -DVC1_ENABLED -DHEVC_ENABLED -DHEVC_CM_WORKAROUND -DHEVC_NEW_OUTPUT_TRIGGER -DHEVC_ALL_PICS_REF -DHEVC_SCAL_LIST_USE_YCRCB_XREF -DHEVC_SFA_ADD_ERROR_CHECKING -DMVD_DFE_DBG -DHEVC_JVT_MODEL=100 -DPAL_CLOCK_API -DSVC_ADDITIONAL_DEBUG -DDIAG_SUPPORT_ENABLED -DENABLE_PERF_TIMER -DFW_API_VERSION=19 -DGLOBAL_USE_RUN_TIME_CFG -DENABLE_TRACE_IN_RELEASE=0 -DYES=1 -DNO=0 -DNONE=0 -DNUP=1 -DUCOS=2 -DUCOS3=3 -DRTOS=0 -DUSE_DECODER -DARM=0 -DMIPS=1 -DX86=2 -DOR1K=3 -DCPU=0 -DNO_AL=0 -DCNXT_KAL=1 -DNXP_OSAL=2 -DOSAL=0 -DARM926=0 -DARMR5=1 -DARMA53=2 -DARM_CPU_TYPE=2 -DADS=0 -DRVDS=1 -DGNU_MIPS=2 -DGNU_MIPS_LNX=3 -DGNU_ARM=4 -DGNU_ARM_SOURCERY=5 -DGNU_X86=6 -DWIN_X86=7 -DDS5=8 -DGNU_OR32=9 -DGNU_ARM_LINARO=10 -DGNU_OR1K=11 -DTOOLSET=10 -DNO_DEBUG=0 -DBUILD_DEBUG=1 -DARRAY_DEBUG=2 -DFULL_DEBUG=3 -DDEBUG_CAPS=0 -DGENTB_PLATFORM=0 -DWIN_LIB=1 -DGEN_TB_ENC=2 -DTARGET_PLATFORM=0 -DVIDEO_TRANS=0 -DGTB_TRANS=1 -DGTB_DEC=2 -DWINDSOR_LIB=3 -DGTB_ENC=4 -DMEDIA_DEC=5 -DMEDIA_LIB=6 -DVPU_TEST_APP=7 -DTARGET_APP=7 -DPAL_CLOCK_API -DSVC_ADDITIONAL_DEBUG -DDIAG_SUPPORT_ENABLED -DENABLE_PERF_TIMER -DFW_API_VERSION=19 -DGLOBAL_USE_RUN_TIME_CFG -DDISABLE_TRACE -DENABLE_TRACE_IN_RELEASE=0 -DYES=1 -DNO=0 -DNONE=0 -DNUP=1 -DUCOS=2 -DUCOS3=3 -DRTOS=0 -DUSE_DECODER -DCHIP=0 -DEMULATION=1 -DHAPS=2 -DSIMULATION=3 -DCMODEL=4 -DTARGET_LEVEL=0 -DSVC_DISABLED=0 -DSVC_ENABLED=1 -DSVC_SUPPORT=0 -DMVC_DISABLED=0 -DMVC_ENABLED=1 -DMVC_SUPPORT=1 -DSFA_DISABLED=0 -DSFA_ENABLED=1 -DSFA_SUPPORT=1 -DCNXT_HW=0 -DNXP_HW=1 -DHWLIB=1 -DDTV=0 -DSTB=1 -DPLAYMODE=0 -DSTANDARD=0 -DREBOOT=1 -DBOOT_ARCH=0 -DTBPLAYER_FLOW_CHANGE_ON_REF_FRMS -DPULSAR_MERGE -DFSLCACHE_ENABLED -DDECLIB_ENABLE_DFE -DDECLIB_ENABLE_DBE -DDECLIB_ENABLE_DCP -DMVD_DCP_DYNAMIC_CONFIG -DDECLIB_4K_SUPPORTED -DHEVC_LEVEL_5PT0_SUPPORT -DPLAYER_LOCAL_THREAD -DDECLIB_ISR_IN_THREAD_CTX -DJPG_ENABLED -DJPGD_AUTO_DOWN_SCALE -DSPARK_ENABLED -DRV_ENABLED -DVP6_ENABLED -DVP8_ENABLED -DJPG_DPV_ENABLED -DMALONE_64BIT_ADDR -DDISABLE_TRACE -DVPU_KERNEL_BUILD -I./drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/KernelIF -I./drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/Control -I./drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/Incl -I./drivers/mxc/vpu-malone/Malone_Firmware/Incl -I./drivers/mxc/vpu-malone/Malone_Firmware/PAL/Incl -I./drivers/mxc/vpu-malone    -DKBUILD_BASENAME='"DecKernelLibHWControl"'  -DKBUILD_MODNAME='"decoder"' -c -o drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/Control/DecKernelLibHWControl.o drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/Control/DecKernelLibHWControl.c

source_drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/Control/DecKernelLibHWControl.o := drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/Control/DecKernelLibHWControl.c

deps_drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/Control/DecKernelLibHWControl.o := \
  include/linux/compiler_types.h \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
    $(wildcard include/config/gcov/kernel.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  drivers/mxc/vpu-malone/Malone_Firmware/Incl/basetype.h \
  include/linux/types.h \
    $(wildcard include/config/have/uid16.h) \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  include/uapi/linux/types.h \
  arch/arm64/include/generated/uapi/asm/types.h \
  include/uapi/asm-generic/types.h \
  include/asm-generic/int-ll64.h \
  include/uapi/asm-generic/int-ll64.h \
  arch/arm64/include/uapi/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
  include/uapi/asm-generic/bitsperlong.h \
  include/uapi/linux/posix_types.h \
  include/linux/stddef.h \
  include/uapi/linux/stddef.h \
  arch/arm64/include/uapi/asm/posix_types.h \
  include/uapi/asm-generic/posix_types.h \
  include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/arch/has/refcount.h) \
    $(wildcard include/config/panic/timeout.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
  /usr/lib/gcc-cross/aarch64-linux-gnu/7/include/stdarg.h \
  include/linux/linkage.h \
  include/linux/stringify.h \
  include/linux/export.h \
    $(wildcard include/config/have/underscore/symbol/prefix.h) \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/module/rel/crcs.h) \
    $(wildcard include/config/trim/unused/ksyms.h) \
    $(wildcard include/config/unused/symbols.h) \
  arch/arm64/include/asm/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/stack/validation.h) \
    $(wildcard include/config/kasan.h) \
  arch/arm64/include/asm/barrier.h \
  include/asm-generic/barrier.h \
    $(wildcard include/config/smp.h) \
  include/linux/bitops.h \
  arch/arm64/include/asm/bitops.h \
  include/asm-generic/bitops/builtin-__ffs.h \
  include/asm-generic/bitops/builtin-ffs.h \
  include/asm-generic/bitops/builtin-__fls.h \
  include/asm-generic/bitops/builtin-fls.h \
  include/asm-generic/bitops/ffz.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/find.h \
    $(wildcard include/config/generic/find/first/bit.h) \
  include/asm-generic/bitops/sched.h \
  include/asm-generic/bitops/hweight.h \
  include/asm-generic/bitops/arch_hweight.h \
  include/asm-generic/bitops/const_hweight.h \
  include/asm-generic/bitops/lock.h \
  include/asm-generic/bitops/non-atomic.h \
  include/asm-generic/bitops/le.h \
  arch/arm64/include/uapi/asm/byteorder.h \
  include/linux/byteorder/little_endian.h \
    $(wildcard include/config/cpu/big/endian.h) \
  include/uapi/linux/byteorder/little_endian.h \
  include/linux/swab.h \
  include/uapi/linux/swab.h \
  arch/arm64/include/generated/uapi/asm/swab.h \
  include/uapi/asm-generic/swab.h \
  include/linux/byteorder/generic.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  include/linux/typecheck.h \
  include/linux/printk.h \
    $(wildcard include/config/message/loglevel/default.h) \
    $(wildcard include/config/console/loglevel/default.h) \
    $(wildcard include/config/early/printk.h) \
    $(wildcard include/config/printk/nmi.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
  include/linux/init.h \
    $(wildcard include/config/strict/kernel/rwx.h) \
    $(wildcard include/config/strict/module/rwx.h) \
  include/linux/kern_levels.h \
  include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  include/uapi/linux/kernel.h \
  include/uapi/linux/sysinfo.h \
  arch/arm64/include/asm/cache.h \
  arch/arm64/include/asm/cputype.h \
  arch/arm64/include/asm/sysreg.h \
    $(wildcard include/config/broken/gas/inst.h) \
    $(wildcard include/config/arm64/4k/pages.h) \
    $(wildcard include/config/arm64/16k/pages.h) \
    $(wildcard include/config/arm64/64k/pages.h) \
  include/linux/build_bug.h \
  drivers/mxc/vpu-malone/Malone_Firmware/Incl/mediaip_fw_types.h \
    $(wildcard include/config/codec/parameter.h) \
    $(wildcard include/config/params.h) \
  drivers/mxc/vpu-malone/Malone_Firmware/Incl/basetype.h \
  drivers/mxc/vpu-malone/Malone_Firmware/Incl/mediaip_fw_defines.h \
  drivers/mxc/vpu-malone/Malone_Firmware/Incl/pal.h \
  drivers/mxc/vpu-malone/Malone_Firmware/PAL/Incl/pal_types.h \
    $(wildcard include/config/magic.h) \
    $(wildcard include/config/max/irqs.h) \
    $(wildcard include/config/max/malones.h) \
    $(wildcard include/config/max/windsors.h) \
    $(wildcard include/config/max/timer/irqs.h) \
    $(wildcard include/config/max/timer/slots.h) \
    $(wildcard include/config/max/inits.h) \
  drivers/mxc/vpu-malone/Malone_Firmware/Incl/status_codes.h \
  drivers/mxc/vpu-malone/Malone_Firmware/Incl/trace_types.h \
  drivers/mxc/vpu-malone/Malone_Firmware/PAL/Incl/pal_linux_map.h \
  drivers/mxc/vpu-malone/Malone_Firmware/Incl/mediaip_fw_types.h \
  drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/Incl/mvd_types.h \
  drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/Incl/mvd_reg_map.h \
    $(wildcard include/config/opts/addr.h) \
  drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/Incl/mvd_sif_control.h \
    $(wildcard include/config/addr.h) \
    $(wildcard include/config/pd/mask.h) \
    $(wildcard include/config/pd/cche0/pos.h) \
    $(wildcard include/config/pd/rsb/pos.h) \
    $(wildcard include/config/pd/avsd/pos.h) \
    $(wildcard include/config/pd/mpgd/pos.h) \
    $(wildcard include/config/pd/vc1d/pos.h) \
    $(wildcard include/config/pd/avcd/pos.h) \
    $(wildcard include/config/pd/comm/pos.h) \
    $(wildcard include/config/pd/rpr/pos.h) \
    $(wildcard include/config/pd/cche1/pos.h) \
    $(wildcard include/config/pd/hevd/pos.h) \
    $(wildcard include/config/pd/vmif/pos.h) \
    $(wildcard include/config/set/pd/cche0.h) \
    $(wildcard include/config/set/pd/rsb.h) \
    $(wildcard include/config/set/pd/avsd.h) \
    $(wildcard include/config/set/pd/mpgd.h) \
    $(wildcard include/config/set/pd/vc1d.h) \
    $(wildcard include/config/set/pd/avcd.h) \
    $(wildcard include/config/set/pd/comm.h) \
    $(wildcard include/config/set/pd/rpr.h) \
    $(wildcard include/config/set/pd/cche1.h) \
    $(wildcard include/config/set/pd/hevd.h) \
    $(wildcard include/config/set/pd/vmif.h) \
    $(wildcard include/config/reset/pd/cche0.h) \
    $(wildcard include/config/reset/pd/rsb.h) \
    $(wildcard include/config/reset/pd/avsd.h) \
    $(wildcard include/config/reset/pd/mpgd.h) \
    $(wildcard include/config/reset/pd/vc1d.h) \
    $(wildcard include/config/reset/pd/avcd.h) \
    $(wildcard include/config/reset/pd/comm.h) \
    $(wildcard include/config/reset/pd/rpr.h) \
    $(wildcard include/config/reset/pd/cche1.h) \
    $(wildcard include/config/reset/pd/hevd.h) \
    $(wildcard include/config/reset/pd/vmif.h) \
    $(wildcard include/config/pos.h) \
  drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/KernelIF/DecKernelLibPrivate.h \
  drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/Incl/DecKernelLib.h \
  drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/KernelIF/DecKernelLibCfg.h \
  drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/Control/DecKernelLibHWControl.h \

drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/Control/DecKernelLibHWControl.o: $(deps_drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/Control/DecKernelLibHWControl.o)

$(deps_drivers/mxc/vpu-malone/Malone_Firmware/DecKLib/Control/DecKernelLibHWControl.o):
