cmd_drivers/net/wireless/marvell/sd8997/mlan/mlan_11n.o := aarch64-poky-linux-gcc -Wp,-MD,drivers/net/wireless/marvell/sd8997/mlan/.mlan_11n.o.d  -nostdinc -isystem /opt/fsl-imx-wayland/4.14-sumo/sysroots/x86_64-pokysdk-linux/usr/lib/aarch64-poky-linux/gcc/aarch64-poky-linux/7.3.0/include -I./arch/arm64/include -I./arch/arm64/include/generated  -I./include -I./arch/arm64/include/uapi -I./arch/arm64/include/generated/uapi -I./include/uapi -I./include/generated/uapi -include ./include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -fshort-wchar -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-PIE -mgeneral-regs-only -DCONFIG_AS_LSE=1 -fno-asynchronous-unwind-tables -mpc-relative-literal-loads -mabi=lp64 -fno-delete-null-pointer-checks -Wno-frame-address -Wno-format-truncation -Wno-format-overflow -Wno-int-in-bool-context -Os -Wno-maybe-uninitialized --param=allow-store-data-races=0 -DCC_HAVE_ASM_GOTO -Wframe-larger-than=2048 -fno-stack-protector -Wno-unused-but-set-variable -Wno-unused-const-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-var-tracking-assignments -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fno-merge-all-constants -fmerge-constants -fno-stack-check -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init --sysroot=/opt/fsl-imx-wayland/4.14-sumo/sysroots/aarch64-poky-linux -I/include -Idrivers/net/wireless/sd8997/mlan -DLINUX -DFPNUM='"68"' -DDEBUG_LEVEL1 -DPROC_DEBUG -DSDIO_MULTI_PORT_TX_AGGR -DSDIO_MULTI_PORT_RX_AGGR -DSDIO_SUSPEND_RESUME -DMFG_CMD_SUPPORT -DMLAN_64BIT -DSTA_SUPPORT -DREASSOCIATION -DUAP_SUPPORT -DWIFI_DIRECT_SUPPORT -DMFG_CMD_SUPPORT -DDFS_TESTING_SUPPORT -DSTA_CFG80211 -DUAP_CFG80211  -DMODULE -mcmodel=large  -DKBUILD_BASENAME='"mlan_11n"'  -DKBUILD_MODNAME='"sd8997mlan"' -c -o drivers/net/wireless/marvell/sd8997/mlan/mlan_11n.o drivers/net/wireless/marvell/sd8997/mlan/mlan_11n.c

source_drivers/net/wireless/marvell/sd8997/mlan/mlan_11n.o := drivers/net/wireless/marvell/sd8997/mlan/mlan_11n.c

deps_drivers/net/wireless/marvell/sd8997/mlan/mlan_11n.o := \
  include/linux/compiler_types.h \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
    $(wildcard include/config/gcov/kernel.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  drivers/net/wireless/marvell/sd8997/mlan/mlan.h \
  drivers/net/wireless/marvell/sd8997/mlan/mlan_decl.h \
    $(wildcard include/config/change.h) \
    $(wildcard include/config/action/get.h) \
    $(wildcard include/config/action/set.h) \
    $(wildcard include/config/action/default.h) \
    $(wildcard include/config/action/max.h) \
  drivers/net/wireless/marvell/sd8997/mlan/mlan_ioctl.h \
    $(wildcard include/config/5g.h) \
    $(wildcard include/config/2g.h) \
    $(wildcard include/config/link.h) \
  drivers/net/wireless/marvell/sd8997/mlan/mlan_ieee.h \
  drivers/net/wireless/marvell/sd8997/mlan/mlan_join.h \
  drivers/net/wireless/marvell/sd8997/mlan/mlan_util.h \
  drivers/net/wireless/marvell/sd8997/mlan/mlan_fw.h \
    $(wildcard include/config/extra/tlv/bytes.h) \
  drivers/net/wireless/marvell/sd8997/mlan/mlan_main.h \
  drivers/net/wireless/marvell/sd8997/mlan/mlan_diag.h \
  drivers/net/wireless/marvell/sd8997/mlan/mlan_wmm.h \
  drivers/net/wireless/marvell/sd8997/mlan/mlan_11n.h \
  drivers/net/wireless/marvell/sd8997/mlan/mlan_11n_aggr.h \
  drivers/net/wireless/marvell/sd8997/mlan/mlan_11n_rxreorder.h \
  drivers/net/wireless/marvell/sd8997/mlan/mlan_11ac.h \

drivers/net/wireless/marvell/sd8997/mlan/mlan_11n.o: $(deps_drivers/net/wireless/marvell/sd8997/mlan/mlan_11n.o)

$(deps_drivers/net/wireless/marvell/sd8997/mlan/mlan_11n.o):
