cmd_drivers/block/nbd.ko := aarch64-poky-linux-ld -EL -r  -maarch64linux -T ./scripts/module-common.lds --build-id  -o drivers/block/nbd.ko drivers/block/nbd.o drivers/block/nbd.mod.o ;  true
