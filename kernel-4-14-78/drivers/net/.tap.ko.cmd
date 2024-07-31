cmd_drivers/net/tap.ko := aarch64-poky-linux-ld -EL -r  -maarch64linux -T ./scripts/module-common.lds --build-id  -o drivers/net/tap.ko drivers/net/tap.o drivers/net/tap.mod.o ;  true
