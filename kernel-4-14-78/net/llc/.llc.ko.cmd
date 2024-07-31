cmd_net/llc/llc.ko := aarch64-linux-gnu-ld -EL -r  -maarch64linux -T ./scripts/module-common.lds --build-id  -o net/llc/llc.ko net/llc/llc.o net/llc/llc.mod.o ;  true
