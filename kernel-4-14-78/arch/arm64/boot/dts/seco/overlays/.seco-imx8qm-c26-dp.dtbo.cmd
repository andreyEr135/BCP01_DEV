cmd_arch/arm64/boot/dts/seco/overlays/seco-imx8qm-c26-dp.dtbo := mkdir -p arch/arm64/boot/dts/seco/overlays/ ; aarch64-linux-gnu-gcc -E -Wp,-MD,arch/arm64/boot/dts/seco/overlays/.seco-imx8qm-c26-dp.dtbo.d.pre.tmp -nostdinc -I./scripts/dtc/include-prefixes -undef -D__DTS__ -x assembler-with-cpp -o arch/arm64/boot/dts/seco/overlays/.seco-imx8qm-c26-dp.dtbo.dts.tmp arch/arm64/boot/dts/seco/overlays/seco-imx8qm-c26-dp-overlay.dts ; ./scripts/dtc/dtc -@ -H epapr -O dtb -o arch/arm64/boot/dts/seco/overlays/seco-imx8qm-c26-dp.dtbo -b 0 -i arch/arm64/boot/dts/seco/overlays/ -Wno-unit_address_vs_reg -Wno-simple_bus_reg -Wno-unit_address_format -Wno-pci_bridge -Wno-pci_device_bus_num -Wno-pci_device_reg  -d arch/arm64/boot/dts/seco/overlays/.seco-imx8qm-c26-dp.dtbo.d.dtc.tmp arch/arm64/boot/dts/seco/overlays/.seco-imx8qm-c26-dp.dtbo.dts.tmp ; cat arch/arm64/boot/dts/seco/overlays/.seco-imx8qm-c26-dp.dtbo.d.pre.tmp arch/arm64/boot/dts/seco/overlays/.seco-imx8qm-c26-dp.dtbo.d.dtc.tmp > arch/arm64/boot/dts/seco/overlays/.seco-imx8qm-c26-dp.dtbo.d

source_arch/arm64/boot/dts/seco/overlays/seco-imx8qm-c26-dp.dtbo := arch/arm64/boot/dts/seco/overlays/seco-imx8qm-c26-dp-overlay.dts

deps_arch/arm64/boot/dts/seco/overlays/seco-imx8qm-c26-dp.dtbo := \
  scripts/dtc/include-prefixes/dt-bindings/clock/imx8qm-clock.h \

arch/arm64/boot/dts/seco/overlays/seco-imx8qm-c26-dp.dtbo: $(deps_arch/arm64/boot/dts/seco/overlays/seco-imx8qm-c26-dp.dtbo)

$(deps_arch/arm64/boot/dts/seco/overlays/seco-imx8qm-c26-dp.dtbo):