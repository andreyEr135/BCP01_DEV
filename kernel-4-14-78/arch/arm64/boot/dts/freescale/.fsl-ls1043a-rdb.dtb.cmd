cmd_arch/arm64/boot/dts/freescale/fsl-ls1043a-rdb.dtb := mkdir -p arch/arm64/boot/dts/freescale/ ; aarch64-linux-gnu-gcc -E -Wp,-MD,arch/arm64/boot/dts/freescale/.fsl-ls1043a-rdb.dtb.d.pre.tmp -nostdinc -I./scripts/dtc/include-prefixes -undef -D__DTS__ -x assembler-with-cpp -o arch/arm64/boot/dts/freescale/.fsl-ls1043a-rdb.dtb.dts.tmp arch/arm64/boot/dts/freescale/fsl-ls1043a-rdb.dts ; ./scripts/dtc/dtc -@ -O dtb -o arch/arm64/boot/dts/freescale/fsl-ls1043a-rdb.dtb -b 0 -iarch/arm64/boot/dts/freescale/ -i./scripts/dtc/include-prefixes -Wno-unit_address_vs_reg -Wno-simple_bus_reg -Wno-unit_address_format -Wno-pci_bridge -Wno-pci_device_bus_num -Wno-pci_device_reg  -d arch/arm64/boot/dts/freescale/.fsl-ls1043a-rdb.dtb.d.dtc.tmp arch/arm64/boot/dts/freescale/.fsl-ls1043a-rdb.dtb.dts.tmp ; cat arch/arm64/boot/dts/freescale/.fsl-ls1043a-rdb.dtb.d.pre.tmp arch/arm64/boot/dts/freescale/.fsl-ls1043a-rdb.dtb.d.dtc.tmp > arch/arm64/boot/dts/freescale/.fsl-ls1043a-rdb.dtb.d

source_arch/arm64/boot/dts/freescale/fsl-ls1043a-rdb.dtb := arch/arm64/boot/dts/freescale/fsl-ls1043a-rdb.dts

deps_arch/arm64/boot/dts/freescale/fsl-ls1043a-rdb.dtb := \
  arch/arm64/boot/dts/freescale/fsl-ls1043a.dtsi \
  scripts/dtc/include-prefixes/dt-bindings/thermal/thermal.h \
  scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/arm-gic.h \
  scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/irq.h \
  arch/arm64/boot/dts/freescale/qoriq-qman-portals.dtsi \
  arch/arm64/boot/dts/freescale/qoriq-bman-portals.dtsi \
  arch/arm64/boot/dts/freescale/fsl-ls1043-post.dtsi \
  arch/arm64/boot/dts/freescale/qoriq-fman3-0.dtsi \
  arch/arm64/boot/dts/freescale/qoriq-fman3-0-1g-0.dtsi \
  arch/arm64/boot/dts/freescale/qoriq-fman3-0-1g-1.dtsi \
  arch/arm64/boot/dts/freescale/qoriq-fman3-0-1g-2.dtsi \
  arch/arm64/boot/dts/freescale/qoriq-fman3-0-1g-3.dtsi \
  arch/arm64/boot/dts/freescale/qoriq-fman3-0-1g-4.dtsi \
  arch/arm64/boot/dts/freescale/qoriq-fman3-0-1g-5.dtsi \
  arch/arm64/boot/dts/freescale/qoriq-fman3-0-10g-0.dtsi \

arch/arm64/boot/dts/freescale/fsl-ls1043a-rdb.dtb: $(deps_arch/arm64/boot/dts/freescale/fsl-ls1043a-rdb.dtb)

$(deps_arch/arm64/boot/dts/freescale/fsl-ls1043a-rdb.dtb):
