ifeq ($(CONFIG_ARCH_MXC_ARM64),y)
        DTC_FLAGS ?= -@ -H epapr
endif


dtb-$(CONFIG_ARCH_FSL_IMX8MQ) += seco-imx8mq-c12.dtb \
				seco-imx8mq-c12new.dtb \
				seco-imx8mq-c12vk02.dtb \
				seco-imx8mq-c25.dtb \
				seco-imx8mq-c20.dtb

dtb-$(CONFIG_ARCH_FSL_IMX8QM) += seco-imx8qm-c26.dtb \
				seco-imx8qm-c43.dtb 

dtb-$(CONFIG_ARCH_FSL_IMX8MM) += seco-imx8mm-c61.dtb

dts-dirs += overlays
  
always		:= $(dtb-y)
subdir-y	:= $(dts-dirs)
clean-files	:= *.dtb
