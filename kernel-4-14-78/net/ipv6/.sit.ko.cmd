cmd_net/ipv6/sit.ko := aarch64-poky-linux-ld -EL -r  -maarch64linux -T ./scripts/module-common.lds --build-id  -o net/ipv6/sit.ko net/ipv6/sit.o net/ipv6/sit.mod.o ;  true
