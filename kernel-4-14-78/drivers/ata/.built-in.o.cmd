cmd_drivers/ata/built-in.o :=  rm -f drivers/ata/built-in.o; aarch64-linux-gnu-ar rcSTPD drivers/ata/built-in.o drivers/ata/libata.o drivers/ata/ahci.o drivers/ata/libahci.o drivers/ata/ahci_platform.o drivers/ata/libahci_platform.o drivers/ata/ahci_imx.o 