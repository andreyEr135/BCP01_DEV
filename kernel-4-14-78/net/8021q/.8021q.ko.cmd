cmd_net/8021q/8021q.ko := aarch64-poky-linux-ld -EL -r  -maarch64linux -T ./scripts/module-common.lds --build-id  -o net/8021q/8021q.ko net/8021q/8021q.o net/8021q/8021q.mod.o ;  true
