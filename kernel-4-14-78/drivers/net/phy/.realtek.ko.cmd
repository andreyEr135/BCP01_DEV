cmd_drivers/net/phy/realtek.ko := aarch64-poky-linux-ld -EL -r  -maarch64linux -T ./scripts/module-common.lds --build-id  -o drivers/net/phy/realtek.ko drivers/net/phy/realtek.o drivers/net/phy/realtek.mod.o ;  true