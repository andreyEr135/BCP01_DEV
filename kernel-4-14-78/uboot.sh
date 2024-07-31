lzma -f -k -9 arch/arm64/boot/Image
mkimage -A arm64 -O linux -T kernel -n "Kernel 4.14.78" -C lzma -e 0x40480000 -a 0x40480000 -d arch/arm64/boot/Image.lzma arch/arm64/boot/Image.lzma.uboot
