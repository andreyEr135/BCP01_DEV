cmd_arch/arm64/boot/dts/freescale/fsl-imx8qm-mek-hdmi.dtb := mkdir -p arch/arm64/boot/dts/freescale/ ; aarch64-linux-gnu-gcc -E -Wp,-MD,arch/arm64/boot/dts/freescale/.fsl-imx8qm-mek-hdmi.dtb.d.pre.tmp -nostdinc -I./scripts/dtc/include-prefixes -undef -D__DTS__ -x assembler-with-cpp -o arch/arm64/boot/dts/freescale/.fsl-imx8qm-mek-hdmi.dtb.dts.tmp arch/arm64/boot/dts/freescale/fsl-imx8qm-mek-hdmi.dts ; ./scripts/dtc/dtc -@ -O dtb -o arch/arm64/boot/dts/freescale/fsl-imx8qm-mek-hdmi.dtb -b 0 -iarch/arm64/boot/dts/freescale/ -i./scripts/dtc/include-prefixes -Wno-unit_address_vs_reg -Wno-simple_bus_reg -Wno-unit_address_format -Wno-pci_bridge -Wno-pci_device_bus_num -Wno-pci_device_reg  -d arch/arm64/boot/dts/freescale/.fsl-imx8qm-mek-hdmi.dtb.d.dtc.tmp arch/arm64/boot/dts/freescale/.fsl-imx8qm-mek-hdmi.dtb.dts.tmp ; cat arch/arm64/boot/dts/freescale/.fsl-imx8qm-mek-hdmi.dtb.d.pre.tmp arch/arm64/boot/dts/freescale/.fsl-imx8qm-mek-hdmi.dtb.d.dtc.tmp > arch/arm64/boot/dts/freescale/.fsl-imx8qm-mek-hdmi.dtb.d

source_arch/arm64/boot/dts/freescale/fsl-imx8qm-mek-hdmi.dtb := arch/arm64/boot/dts/freescale/fsl-imx8qm-mek-hdmi.dts

deps_arch/arm64/boot/dts/freescale/fsl-imx8qm-mek-hdmi.dtb := \
  arch/arm64/boot/dts/freescale/fsl-imx8qm-mek.dts \
  arch/arm64/boot/dts/freescale/fsl-imx8qm-mek.dtsi \
  arch/arm64/boot/dts/freescale/fsl-imx8qm.dtsi \
  scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/arm-gic.h \
  scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/irq.h \
  arch/arm64/boot/dts/freescale/fsl-imx8-ca53.dtsi \
  arch/arm64/boot/dts/freescale/fsl-imx8-ca72.dtsi \
  scripts/dtc/include-prefixes/dt-bindings/clock/imx8qm-clock.h \
  scripts/dtc/include-prefixes/dt-bindings/input/input.h \
  scripts/dtc/include-prefixes/dt-bindings/input/linux-event-codes.h \
  scripts/dtc/include-prefixes/dt-bindings/soc/imx_rsrc.h \
  scripts/dtc/include-prefixes/dt-bindings/soc/imx8_hsio.h \
  scripts/dtc/include-prefixes/dt-bindings/soc/imx8_pd.h \
  scripts/dtc/include-prefixes/dt-bindings/pinctrl/pads-imx8qm.h \
  scripts/dtc/include-prefixes/dt-bindings/gpio/gpio.h \
  scripts/dtc/include-prefixes/dt-bindings/thermal/thermal.h \
  arch/arm64/boot/dts/freescale/fsl-imx8qm-device.dtsi \

arch/arm64/boot/dts/freescale/fsl-imx8qm-mek-hdmi.dtb: $(deps_arch/arm64/boot/dts/freescale/fsl-imx8qm-mek-hdmi.dtb)

$(deps_arch/arm64/boot/dts/freescale/fsl-imx8qm-mek-hdmi.dtb):
