dtbo-$(CONFIG_ARCH_FSL_IMX8MQ) += seco-imx8mq-c12-wilink.dtbo \
				seco-imx8mq-c12-lcdif-sn65dsi84.dtbo \
				seco-imx8mq-c12-dcss-sn65dsi84.dtbo \
				seco-imx8mq-c12-can-rtc.dtbo \
				seco-imx8mq-c12-dual-display.dtbo \
				seco-imx8mq-c25-dcss-sn65dsi84.dtbo \
				seco-imx8mq-c25-dcss-sn65dsi86.dtbo \
				seco-imx8mq-c25-lcdif-sn65dsi84.dtbo \
				seco-imx8mq-c25-dual-display.dtbo \
				seco-imx8mq-c25-uart4.dtbo \
				seco-imx8mq-c25-can-rtc.dtbo \
				seco-imx8mq-c25-q7-spi.dtbo \
				seco-imx8mq-c25-dp.dtbo \
				seco-imx8mq-c20-wilink.dtbo \
				seco-imx8mq-c20-dcss-sn65dsi84.dtbo 

dtbo-$(CONFIG_ARCH_FSL_IMX8QM) +=  seco-imx8qm-c26-hdmi.dtbo\
					seco-imx8qm-c26-lvds1.dtbo\
					seco-imx8qm-c26-lvds2.dtbo\
					seco-imx8qm-c26-dp.dtbo\
					seco-imx8qm-c26-ov5640-csi0.dtbo\
					seco-imx8qm-c26-ov5640-csi1.dtbo\
					seco-imx8qm-c43-hdmi.dtbo\
					seco-imx8qm-c43-sn65dsi86.dtbo\
					seco-imx8qm-c43-ov5640-csi0.dtbo\
					seco-imx8qm-c43-ov5640-csi1.dtbo\
					seco-imx8qm-c43-lvds1.dtbo\
					seco-imx8qm-c43-hdmi-in.dtbo

targets += dtbs dtbs_install
targets += $(dtbo-y)

always		:= $(dtbo-y)
clean-files	:= *.dtbo
