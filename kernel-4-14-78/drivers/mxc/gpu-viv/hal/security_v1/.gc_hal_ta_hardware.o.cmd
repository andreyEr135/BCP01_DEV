cmd_drivers/mxc/gpu-viv/hal/security_v1/gc_hal_ta_hardware.o := aarch64-linux-gnu-gcc -Wp,-MD,drivers/mxc/gpu-viv/hal/security_v1/.gc_hal_ta_hardware.o.d  -nostdinc -isystem /usr/lib/gcc-cross/aarch64-linux-gnu/7/include -I./arch/arm64/include -I./arch/arm64/include/generated  -I./include -I./arch/arm64/include/uapi -I./arch/arm64/include/generated/uapi -I./include/uapi -I./include/generated/uapi -include ./include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -fshort-wchar -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-PIE -mgeneral-regs-only -DCONFIG_AS_LSE=1 -fno-asynchronous-unwind-tables -mpc-relative-literal-loads -mabi=lp64 -fno-delete-null-pointer-checks -Wno-frame-address -Wno-format-truncation -Wno-format-overflow -Wno-int-in-bool-context -Os -Wno-maybe-uninitialized --param=allow-store-data-races=0 -DCC_HAVE_ASM_GOTO -Wframe-larger-than=2048 -fno-stack-protector -Wno-unused-but-set-variable -Wno-unused-const-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-var-tracking-assignments -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fno-merge-all-constants -fmerge-constants -fno-stack-check -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -DgcdDEFAULT_CONTIGUOUS_SIZE=~0U -DgcdFSL_CONTIGUOUS_SIZE=134217728 -DgcdANDROID_NATIVE_FENCE_SYNC=2 -DIMX8_SCU_CONTROL=1 -DIMX8_PHYS_BASE=0x80000000 -DIMX8_PHYS_SIZE=0x80000000 -DLINUX_CMA_FSL=1 -DCLASS_NAME=\"gpu_class\" -DgcdGPU_2D_TIMEOUT=20000 -DNO_DMA_COHERENT=1 -DgcdSYS_FREE_MEMORY_LIMIT=51200 -Werror -DLINUX -DDRIVER -DDBG=0 -DUSE_PLATFORM_DRIVER=1 -DVIVANTE_PROFILER=1 -DVIVANTE_PROFILER_CONTEXT=1 -DENABLE_GPU_CLOCK_BY_DRIVER=0 -DUSE_NEW_LINUX_SIGNAL=0 -DUSE_LINUX_PCIE=0 -DgcdPAGED_MEMORY_CACHEABLE=0 -DgcdNONPAGED_MEMORY_CACHEABLE=0 -DgcdNONPAGED_MEMORY_BUFFERABLE=1 -DgcdCACHE_FUNCTION_UNIMPLEMENTED=0 -DgcdENABLE_3D=1 -DgcdENABLE_2D=1 -DgcdENABLE_VG=0 -DgcdENABLE_BANK_ALIGNMENT=1 -DgcdBANK_BIT_START=13 -DgcdBANK_BIT_END=15 -DgcdBANK_CHANNEL_BIT=12 -DgcdFPGA_BUILD=0 -DgcdENABLE_DRM=0 -I./drivers/mxc/gpu-viv/hal/kernel/inc -I./drivers/mxc/gpu-viv/hal/kernel -I./drivers/mxc/gpu-viv/hal/kernel/arch -I./drivers/mxc/gpu-viv/hal/kernel/inc -I./drivers/mxc/gpu-viv/hal/os/linux/kernel -I./drivers/mxc/gpu-viv/hal/os/linux/kernel/allocator/freescale -I./drivers/mxc/gpu-viv/hal/security_v1/ -DHOST=\"user-VirtualBox\" -DgcdENABLE_TRUST_APPLICATION=1    -DKBUILD_BASENAME='"gc_hal_ta_hardware"'  -DKBUILD_MODNAME='"galcore"' -c -o drivers/mxc/gpu-viv/hal/security_v1/gc_hal_ta_hardware.o drivers/mxc/gpu-viv/hal/security_v1/gc_hal_ta_hardware.c

source_drivers/mxc/gpu-viv/hal/security_v1/gc_hal_ta_hardware.o := drivers/mxc/gpu-viv/hal/security_v1/gc_hal_ta_hardware.c

deps_drivers/mxc/gpu-viv/hal/security_v1/gc_hal_ta_hardware.o := \
  include/linux/compiler_types.h \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
    $(wildcard include/config/gcov/kernel.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  drivers/mxc/gpu-viv/hal/kernel/inc/gc_hal_types.h \
  drivers/mxc/gpu-viv/hal/kernel/inc/gc_hal_version.h \
  drivers/mxc/gpu-viv/hal/kernel/inc/gc_hal_options.h \
    $(wildcard include/config/sync.h) \
  include/generated/uapi/linux/version.h \
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
  drivers/mxc/gpu-viv/hal/kernel/inc/gc_hal_base.h \
    $(wildcard include/config/format/info.h) \
  drivers/mxc/gpu-viv/hal/kernel/inc/gc_hal_enum.h \
  drivers/mxc/gpu-viv/hal/kernel/inc/gc_hal_types.h \
  drivers/mxc/gpu-viv/hal/kernel/inc/gc_hal_dump.h \
  drivers/mxc/gpu-viv/hal/kernel/inc/gc_hal_security_interface.h \
  drivers/mxc/gpu-viv/hal/security_v1/gc_hal_ta.h \
  drivers/mxc/gpu-viv/hal/security_v1/gc_hal_ta_hardware.h \
  drivers/mxc/gpu-viv/hal/kernel/inc/gc_hal.h \
  drivers/mxc/gpu-viv/hal/kernel/inc/gc_hal_rename.h \
  drivers/mxc/gpu-viv/hal/kernel/inc/gc_hal_base.h \
  drivers/mxc/gpu-viv/hal/kernel/inc/gc_hal_profiler.h \
  drivers/mxc/gpu-viv/hal/kernel/inc/gc_hal_driver.h \
    $(wildcard include/config/android/reserved/memory/account.h) \
    $(wildcard include/config/power/management.h) \
  drivers/mxc/gpu-viv/hal/kernel/inc/gc_hal_statistics.h \
  drivers/mxc/gpu-viv/hal/kernel/inc/gc_feature_database.h \

drivers/mxc/gpu-viv/hal/security_v1/gc_hal_ta_hardware.o: $(deps_drivers/mxc/gpu-viv/hal/security_v1/gc_hal_ta_hardware.o)

$(deps_drivers/mxc/gpu-viv/hal/security_v1/gc_hal_ta_hardware.o):
