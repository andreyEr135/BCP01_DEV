cmd_u-boot-dtb.img := ./tools/mkimage -f auto -A arm -T firmware -C none -O u-boot -a 0x40200000 -e 0 -n "U-Boot 2018.03""-g2e9e498-dirty for seco_imx8mq_c12 board" -E -b arch/arm/dts/seco-imx8mq-c12.dtb -d u-boot-nodtb.bin u-boot-dtb.img  >/dev/null
