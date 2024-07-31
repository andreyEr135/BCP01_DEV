cmd_SPL := ./tools/mkimage -n arch/arm/mach-imx/spl_sd.cfg.cfgtmp -T imximage -e 0x7E1000 -d spl/u-boot-spl.bin SPL  >SPL.log
