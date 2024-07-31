cmd_crypto/tcrypt.ko := aarch64-poky-linux-ld -EL -r  -maarch64linux -T ./scripts/module-common.lds --build-id  -o crypto/tcrypt.ko crypto/tcrypt.o crypto/tcrypt.mod.o ;  true
