cmd_arch/arm64/boot/dts/freescale/fsl-imx8mq-ddr4-arm2-gpmi-nand.dtb := mkdir -p arch/arm64/boot/dts/freescale/ ; aarch64-linux-gnu-gcc -E -Wp,-MD,arch/arm64/boot/dts/freescale/.fsl-imx8mq-ddr4-arm2-gpmi-nand.dtb.d.pre.tmp -nostdinc -I./scripts/dtc/include-prefixes -undef -D__DTS__ -x assembler-with-cpp -o arch/arm64/boot/dts/freescale/.fsl-imx8mq-ddr4-arm2-gpmi-nand.dtb.dts.tmp arch/arm64/boot/dts/freescale/fsl-imx8mq-ddr4-arm2-gpmi-nand.dts ; ./scripts/dtc/dtc -@ -O dtb -o arch/arm64/boot/dts/freescale/fsl-imx8mq-ddr4-arm2-gpmi-nand.dtb -b 0 -iarch/arm64/boot/dts/freescale/ -i./scripts/dtc/include-prefixes -Wno-unit_address_vs_reg -Wno-simple_bus_reg -Wno-unit_address_format -Wno-pci_bridge -Wno-pci_device_bus_num -Wno-pci_device_reg  -d arch/arm64/boot/dts/freescale/.fsl-imx8mq-ddr4-arm2-gpmi-nand.dtb.d.dtc.tmp arch/arm64/boot/dts/freescale/.fsl-imx8mq-ddr4-arm2-gpmi-nand.dtb.dts.tmp ; cat arch/arm64/boot/dts/freescale/.fsl-imx8mq-ddr4-arm2-gpmi-nand.dtb.d.pre.tmp arch/arm64/boot/dts/freescale/.fsl-imx8mq-ddr4-arm2-gpmi-nand.dtb.d.dtc.tmp > arch/arm64/boot/dts/freescale/.fsl-imx8mq-ddr4-arm2-gpmi-nand.dtb.d

source_arch/arm64/boot/dts/freescale/fsl-imx8mq-ddr4-arm2-gpmi-nand.dtb := arch/arm64/boot/dts/freescale/fsl-imx8mq-ddr4-arm2-gpmi-nand.dts

deps_arch/arm64/boot/dts/freescale/fsl-imx8mq-ddr4-arm2-gpmi-nand.dtb := \
  arch/arm64/boot/dts/freescale/fsl-imx8mq-ddr4-arm2.dts \
  arch/arm64/boot/dts/freescale/fsl-imx8mq.dtsi \
  arch/arm64/boot/dts/freescale/fsl-imx8-ca53.dtsi \
  scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/arm-gic.h \
  scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/irq.h \
  scripts/dtc/include-prefixes/dt-bindings/clock/imx8mq-clock.h \
  scripts/dtc/include-prefixes/dt-bindings/gpio/gpio.h \
  scripts/dtc/include-prefixes/dt-bindings/input/input.h \
  scripts/dtc/include-prefixes/dt-bindings/input/linux-event-codes.h \
  scripts/dtc/include-prefixes/dt-bindings/pinctrl/pins-imx8mq.h \
  scripts/dtc/include-prefixes/dt-bindings/thermal/thermal.h \

arch/arm64/boot/dts/freescale/fsl-imx8mq-ddr4-arm2-gpmi-nand.dtb: $(deps_arch/arm64/boot/dts/freescale/fsl-imx8mq-ddr4-arm2-gpmi-nand.dtb)

$(deps_arch/arm64/boot/dts/freescale/fsl-imx8mq-ddr4-arm2-gpmi-nand.dtb):