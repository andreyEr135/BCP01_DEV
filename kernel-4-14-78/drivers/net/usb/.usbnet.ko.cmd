cmd_drivers/net/usb/usbnet.ko := aarch64-poky-linux-ld -EL -r  -maarch64linux -T ./scripts/module-common.lds --build-id  -o drivers/net/usb/usbnet.ko drivers/net/usb/usbnet.o drivers/net/usb/usbnet.mod.o ;  true
