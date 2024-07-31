cmd_drivers/net/veth.ko := aarch64-poky-linux-ld -EL -r  -maarch64linux -T ./scripts/module-common.lds --build-id  -o drivers/net/veth.ko drivers/net/veth.o drivers/net/veth.mod.o ;  true
