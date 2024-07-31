cmd_arch/arm64/crypto/chacha20-neon-core.o := aarch64-linux-gnu-gcc -Wp,-MD,arch/arm64/crypto/.chacha20-neon-core.o.d  -nostdinc -isystem /usr/lib/gcc-cross/aarch64-linux-gnu/7/include -I./arch/arm64/include -I./arch/arm64/include/generated  -I./include -I./arch/arm64/include/uapi -I./arch/arm64/include/generated/uapi -I./include/uapi -I./include/generated/uapi -include ./include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -D__ASSEMBLY__ -fno-PIE -DCONFIG_AS_LSE=1 -mabi=lp64 -DCC_HAVE_ASM_GOTO -DMODULE  -c -o arch/arm64/crypto/chacha20-neon-core.o arch/arm64/crypto/chacha20-neon-core.S

source_arch/arm64/crypto/chacha20-neon-core.o := arch/arm64/crypto/chacha20-neon-core.S

deps_arch/arm64/crypto/chacha20-neon-core.o := \
  include/linux/compiler_types.h \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
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

arch/arm64/crypto/chacha20-neon-core.o: $(deps_arch/arm64/crypto/chacha20-neon-core.o)

$(deps_arch/arm64/crypto/chacha20-neon-core.o):
