cmd_vmlinux := /bin/bash scripts/link-vmlinux.sh aarch64-linux-gnu-ld -EL  -maarch64linux -p --no-undefined -X --fix-cortex-a53-843419 --build-id ;  true
