cmd_drivers/mxc/gpu-viv/hal/os/linux/kernel/gc_hal_kernel_drm.o := aarch64-linux-gnu-gcc -Wp,-MD,drivers/mxc/gpu-viv/hal/os/linux/kernel/.gc_hal_kernel_drm.o.d  -nostdinc -isystem /usr/lib/gcc-cross/aarch64-linux-gnu/7/include -I./arch/arm64/include -I./arch/arm64/include/generated  -I./include -I./arch/arm64/include/uapi -I./arch/arm64/include/generated/uapi -I./include/uapi -I./include/generated/uapi -include ./include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -fshort-wchar -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-PIE -mgeneral-regs-only -DCONFIG_AS_LSE=1 -fno-asynchronous-unwind-tables -mpc-relative-literal-loads -mabi=lp64 -fno-delete-null-pointer-checks -Wno-frame-address -Wno-format-truncation -Wno-format-overflow -Wno-int-in-bool-context -Os -Wno-maybe-uninitialized --param=allow-store-data-races=0 -DCC_HAVE_ASM_GOTO -Wframe-larger-than=2048 -fno-stack-protector -Wno-unused-but-set-variable -Wno-unused-const-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-var-tracking-assignments -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fno-merge-all-constants -fmerge-constants -fno-stack-check -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -DgcdDEFAULT_CONTIGUOUS_SIZE=~0U -DgcdFSL_CONTIGUOUS_SIZE=134217728 -DgcdANDROID_NATIVE_FENCE_SYNC=2 -DIMX8_SCU_CONTROL=1 -DIMX8_PHYS_BASE=0x80000000 -DIMX8_PHYS_SIZE=0x80000000 -DLINUX_CMA_FSL=1 -DCLASS_NAME=\"gpu_class\" -DgcdGPU_2D_TIMEOUT=20000 -DNO_DMA_COHERENT=1 -DgcdSYS_FREE_MEMORY_LIMIT=51200 -Werror -DLINUX -DDRIVER -DDBG=0 -DUSE_PLATFORM_DRIVER=1 -DVIVANTE_PROFILER=1 -DVIVANTE_PROFILER_CONTEXT=1 -DENABLE_GPU_CLOCK_BY_DRIVER=0 -DUSE_NEW_LINUX_SIGNAL=0 -DUSE_LINUX_PCIE=0 -DgcdPAGED_MEMORY_CACHEABLE=0 -DgcdNONPAGED_MEMORY_CACHEABLE=0 -DgcdNONPAGED_MEMORY_BUFFERABLE=1 -DgcdCACHE_FUNCTION_UNIMPLEMENTED=0 -DgcdENABLE_3D=1 -DgcdENABLE_2D=1 -DgcdENABLE_VG=0 -DgcdENABLE_BANK_ALIGNMENT=1 -DgcdBANK_BIT_START=13 -DgcdBANK_BIT_END=15 -DgcdBANK_CHANNEL_BIT=12 -DgcdFPGA_BUILD=0 -DgcdENABLE_DRM=0 -I./drivers/mxc/gpu-viv/hal/kernel/inc -I./drivers/mxc/gpu-viv/hal/kernel -I./drivers/mxc/gpu-viv/hal/kernel/arch -I./drivers/mxc/gpu-viv/hal/kernel/inc -I./drivers/mxc/gpu-viv/hal/os/linux/kernel -I./drivers/mxc/gpu-viv/hal/os/linux/kernel/allocator/freescale -I./drivers/mxc/gpu-viv/hal/security_v1/ -DHOST=\"user-VirtualBox\" -DgcdENABLE_TRUST_APPLICATION=1    -DKBUILD_BASENAME='"gc_hal_kernel_drm"'  -DKBUILD_MODNAME='"galcore"' -c -o drivers/mxc/gpu-viv/hal/os/linux/kernel/gc_hal_kernel_drm.o drivers/mxc/gpu-viv/hal/os/linux/kernel/gc_hal_kernel_drm.c

source_drivers/mxc/gpu-viv/hal/os/linux/kernel/gc_hal_kernel_drm.o := drivers/mxc/gpu-viv/hal/os/linux/kernel/gc_hal_kernel_drm.c

deps_drivers/mxc/gpu-viv/hal/os/linux/kernel/gc_hal_kernel_drm.o := \
    $(wildcard include/config/compat.h) \
  include/linux/compiler_types.h \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
    $(wildcard include/config/gcov/kernel.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \

drivers/mxc/gpu-viv/hal/os/linux/kernel/gc_hal_kernel_drm.o: $(deps_drivers/mxc/gpu-viv/hal/os/linux/kernel/gc_hal_kernel_drm.o)

$(deps_drivers/mxc/gpu-viv/hal/os/linux/kernel/gc_hal_kernel_drm.o):