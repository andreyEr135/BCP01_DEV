cmd_drivers/spi/spidev.ko := aarch64-poky-linux-ld -EL -r  -maarch64linux -T ./scripts/module-common.lds --build-id  -o drivers/spi/spidev.ko drivers/spi/spidev.o drivers/spi/spidev.mod.o ;  true
