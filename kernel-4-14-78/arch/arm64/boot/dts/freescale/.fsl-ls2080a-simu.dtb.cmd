cmd_arch/arm64/boot/dts/freescale/fsl-ls2080a-simu.dtb := mkdir -p arch/arm64/boot/dts/freescale/ ; aarch64-linux-gnu-gcc -E -Wp,-MD,arch/arm64/boot/dts/freescale/.fsl-ls2080a-simu.dtb.d.pre.tmp -nostdinc -I./scripts/dtc/include-prefixes -undef -D__DTS__ -x assembler-with-cpp -o arch/arm64/boot/dts/freescale/.fsl-ls2080a-simu.dtb.dts.tmp arch/arm64/boot/dts/freescale/fsl-ls2080a-simu.dts ; ./scripts/dtc/dtc -@ -O dtb -o arch/arm64/boot/dts/freescale/fsl-ls2080a-simu.dtb -b 0 -iarch/arm64/boot/dts/freescale/ -i./scripts/dtc/include-prefixes -Wno-unit_address_vs_reg -Wno-simple_bus_reg -Wno-unit_address_format -Wno-pci_bridge -Wno-pci_device_bus_num -Wno-pci_device_reg  -d arch/arm64/boot/dts/freescale/.fsl-ls2080a-simu.dtb.d.dtc.tmp arch/arm64/boot/dts/freescale/.fsl-ls2080a-simu.dtb.dts.tmp ; cat arch/arm64/boot/dts/freescale/.fsl-ls2080a-simu.dtb.d.pre.tmp arch/arm64/boot/dts/freescale/.fsl-ls2080a-simu.dtb.d.dtc.tmp > arch/arm64/boot/dts/freescale/.fsl-ls2080a-simu.dtb.d

source_arch/arm64/boot/dts/freescale/fsl-ls2080a-simu.dtb := arch/arm64/boot/dts/freescale/fsl-ls2080a-simu.dts

deps_arch/arm64/boot/dts/freescale/fsl-ls2080a-simu.dtb := \
  arch/arm64/boot/dts/freescale/fsl-ls2080a.dtsi \
  arch/arm64/boot/dts/freescale/fsl-ls208xa.dtsi \
  scripts/dtc/include-prefixes/dt-bindings/thermal/thermal.h \
  scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/arm-gic.h \
  scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/irq.h \

arch/arm64/boot/dts/freescale/fsl-ls2080a-simu.dtb: $(deps_arch/arm64/boot/dts/freescale/fsl-ls2080a-simu.dtb)

$(deps_arch/arm64/boot/dts/freescale/fsl-ls2080a-simu.dtb):
