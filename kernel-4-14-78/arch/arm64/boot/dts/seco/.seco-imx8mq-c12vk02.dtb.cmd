cmd_arch/arm64/boot/dts/seco/seco-imx8mq-c12vk02.dtb := mkdir -p arch/arm64/boot/dts/seco/ ; aarch64-linux-gnu-gcc -E -Wp,-MD,arch/arm64/boot/dts/seco/.seco-imx8mq-c12vk02.dtb.d.pre.tmp -nostdinc -I./scripts/dtc/include-prefixes -undef -D__DTS__ -x assembler-with-cpp -o arch/arm64/boot/dts/seco/.seco-imx8mq-c12vk02.dtb.dts.tmp arch/arm64/boot/dts/seco/seco-imx8mq-c12vk02.dts ; ./scripts/dtc/dtc -@ -O dtb -o arch/arm64/boot/dts/seco/seco-imx8mq-c12vk02.dtb -b 0 -iarch/arm64/boot/dts/seco/ -i./scripts/dtc/include-prefixes -@ -H epapr -Wno-unit_address_vs_reg -Wno-simple_bus_reg -Wno-unit_address_format -Wno-pci_bridge -Wno-pci_device_bus_num -Wno-pci_device_reg  -d arch/arm64/boot/dts/seco/.seco-imx8mq-c12vk02.dtb.d.dtc.tmp arch/arm64/boot/dts/seco/.seco-imx8mq-c12vk02.dtb.dts.tmp ; cat arch/arm64/boot/dts/seco/.seco-imx8mq-c12vk02.dtb.d.pre.tmp arch/arm64/boot/dts/seco/.seco-imx8mq-c12vk02.dtb.d.dtc.tmp > arch/arm64/boot/dts/seco/.seco-imx8mq-c12vk02.dtb.d

source_arch/arm64/boot/dts/seco/seco-imx8mq-c12vk02.dtb := arch/arm64/boot/dts/seco/seco-imx8mq-c12vk02.dts

deps_arch/arm64/boot/dts/seco/seco-imx8mq-c12vk02.dtb := \
  arch/arm64/boot/dts/seco/fsl-imx8mq.dtsi \
  arch/arm64/boot/dts/seco/fsl-imx8-ca53.dtsi \
  scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/arm-gic.h \
  scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/irq.h \
  scripts/dtc/include-prefixes/dt-bindings/clock/imx8mq-clock.h \
  scripts/dtc/include-prefixes/dt-bindings/gpio/gpio.h \
  scripts/dtc/include-prefixes/dt-bindings/input/input.h \
  scripts/dtc/include-prefixes/dt-bindings/input/linux-event-codes.h \
  scripts/dtc/include-prefixes/dt-bindings/pinctrl/pins-imx8mq.h \
  scripts/dtc/include-prefixes/dt-bindings/thermal/thermal.h \
  scripts/dtc/include-prefixes/dt-bindings/net/ti-dp83867.h \
  scripts/dtc/include-prefixes/dt-bindings/seco/ectrl.h \

arch/arm64/boot/dts/seco/seco-imx8mq-c12vk02.dtb: $(deps_arch/arm64/boot/dts/seco/seco-imx8mq-c12vk02.dtb)

$(deps_arch/arm64/boot/dts/seco/seco-imx8mq-c12vk02.dtb):
