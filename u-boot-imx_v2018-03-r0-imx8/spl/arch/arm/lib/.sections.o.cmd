cmd_spl/arch/arm/lib/sections.o := aarch64-linux-gnu-gcc -Wp,-MD,spl/arch/arm/lib/.sections.o.d  -nostdinc -isystem /usr/lib/gcc-cross/aarch64-linux-gnu/7/include -Iinclude   -I./arch/arm/include -include ./include/linux/kconfig.h -D__KERNEL__ -D__UBOOT__ -DCONFIG_SPL_BUILD -Wall -Wstrict-prototypes -Wno-format-security -fno-builtin -ffreestanding -fshort-wchar -Os -fno-stack-protector -fno-delete-null-pointer-checks -g -fstack-usage -Wno-format-nonliteral -Werror=date-time -ffunction-sections -fdata-sections -D__ARM__ -mstrict-align -ffunction-sections -fdata-sections -fno-common -ffixed-r9 -fno-common -ffixed-x18 -pipe -march=armv8-a -D__LINUX_ARM_ARCH__=8    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(sections)"  -D"KBUILD_MODNAME=KBUILD_STR(sections)" -c -o spl/arch/arm/lib/sections.o arch/arm/lib/sections.c

source_spl/arch/arm/lib/sections.o := arch/arm/lib/sections.c

deps_spl/arch/arm/lib/sections.o := \

spl/arch/arm/lib/sections.o: $(deps_spl/arch/arm/lib/sections.o)

$(deps_spl/arch/arm/lib/sections.o):