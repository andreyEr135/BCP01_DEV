cmd_drivers/net/macvtap.ko := aarch64-poky-linux-ld -EL -r  -maarch64linux -T ./scripts/module-common.lds --build-id  -o drivers/net/macvtap.ko drivers/net/macvtap.o drivers/net/macvtap.mod.o ;  true
