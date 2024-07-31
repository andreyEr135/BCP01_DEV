cmd_u-boot-dtb.imx := ./tools/mkimage -n arch/arm/mach-imx/spl_sd.cfg.cfgtmp -T imximage -e 0x40200000 -d u-boot-dtb.bin u-boot-dtb.imx  >u-boot-dtb.imx.log
