cmd_drivers/video/imx/hdp/vic_table.o := aarch64-linux-gnu-gcc -Wp,-MD,drivers/video/imx/hdp/.vic_table.o.d  -nostdinc -isystem /usr/lib/gcc-cross/aarch64-linux-gnu/7/include -Iinclude   -I./arch/arm/include -include ./include/linux/kconfig.h -I./drivers/video/imx/hdp -D__KERNEL__ -D__UBOOT__ -Wall -Wstrict-prototypes -Wno-format-security -fno-builtin -ffreestanding -fshort-wchar -Os -fno-stack-protector -fno-delete-null-pointer-checks -g -fstack-usage -Wno-format-nonliteral -Werror=date-time -D__ARM__ -fno-pic -mstrict-align -ffunction-sections -fdata-sections -fno-common -ffixed-r9 -fno-common -ffixed-x18 -pipe -march=armv8-a -D__LINUX_ARM_ARCH__=8    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(vic_table)"  -D"KBUILD_MODNAME=KBUILD_STR(vic_table)" -c -o drivers/video/imx/hdp/vic_table.o drivers/video/imx/hdp/vic_table.c

source_drivers/video/imx/hdp/vic_table.o := drivers/video/imx/hdp/vic_table.c

deps_drivers/video/imx/hdp/vic_table.o := \
  drivers/video/imx/hdp/vic_table.h \

drivers/video/imx/hdp/vic_table.o: $(deps_drivers/video/imx/hdp/vic_table.o)

$(deps_drivers/video/imx/hdp/vic_table.o):
