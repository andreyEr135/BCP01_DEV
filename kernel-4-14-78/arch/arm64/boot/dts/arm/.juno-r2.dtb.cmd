cmd_arch/arm64/boot/dts/arm/juno-r2.dtb := mkdir -p arch/arm64/boot/dts/arm/ ; aarch64-linux-gnu-gcc -E -Wp,-MD,arch/arm64/boot/dts/arm/.juno-r2.dtb.d.pre.tmp -nostdinc -I./scripts/dtc/include-prefixes -undef -D__DTS__ -x assembler-with-cpp -o arch/arm64/boot/dts/arm/.juno-r2.dtb.dts.tmp arch/arm64/boot/dts/arm/juno-r2.dts ; ./scripts/dtc/dtc -@ -O dtb -o arch/arm64/boot/dts/arm/juno-r2.dtb -b 0 -iarch/arm64/boot/dts/arm/ -i./scripts/dtc/include-prefixes -Wno-unit_address_vs_reg -Wno-simple_bus_reg -Wno-unit_address_format -Wno-pci_bridge -Wno-pci_device_bus_num -Wno-pci_device_reg  -d arch/arm64/boot/dts/arm/.juno-r2.dtb.d.dtc.tmp arch/arm64/boot/dts/arm/.juno-r2.dtb.dts.tmp ; cat arch/arm64/boot/dts/arm/.juno-r2.dtb.d.pre.tmp arch/arm64/boot/dts/arm/.juno-r2.dtb.d.dtc.tmp > arch/arm64/boot/dts/arm/.juno-r2.dtb.d

source_arch/arm64/boot/dts/arm/juno-r2.dtb := arch/arm64/boot/dts/arm/juno-r2.dts

deps_arch/arm64/boot/dts/arm/juno-r2.dtb := \
  scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/arm-gic.h \
  scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/irq.h \
  arch/arm64/boot/dts/arm/juno-base.dtsi \
  arch/arm64/boot/dts/arm/juno-clocks.dtsi \
  arch/arm64/boot/dts/arm/juno-cs-r1r2.dtsi \
  arch/arm64/boot/dts/arm/juno-motherboard.dtsi \

arch/arm64/boot/dts/arm/juno-r2.dtb: $(deps_arch/arm64/boot/dts/arm/juno-r2.dtb)

$(deps_arch/arm64/boot/dts/arm/juno-r2.dtb):
