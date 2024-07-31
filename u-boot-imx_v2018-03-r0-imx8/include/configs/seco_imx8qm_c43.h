/*
 * Copyright 2017-2018 NXP
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __SECO_IMX8QM_C43_H
#define __SECO_IMX8QM_C43_H

#include <linux/sizes.h>
#include <asm/arch/imx-regs.h>
#include "imx_env.h"
#include "seco_imx8qm_common.h"

#ifdef CONFIG_SPL_BUILD

#ifdef CONFIG_QSPI_BOOT
#define CONFIG_SPL_SPI_LOAD
#endif

#define CONFIG_PARSE_CONTAINER
#define CONFIG_SPL_TEXT_BASE           0x0
#define CONFIG_SPL_MAX_SIZE            (124 * 1024)
#define CONFIG_SYS_MONITOR_LEN         (1024 * 1024)
#define CONFIG_SYS_MMCSD_RAW_MODE_U_BOOT_USE_SECTOR
#define CONFIG_SYS_MMCSD_RAW_MODE_U_BOOT_SECTOR                0x1040 /* (flash.bin_offset + 2Mb)/sector_size */
#define CONFIG_SYS_MMCSD_FS_BOOT_PARTITION             0


#define CONFIG_SPL_WATCHDOG_SUPPORT
#define CONFIG_SPL_DRIVERS_MISC_SUPPORT
#define CONFIG_SPL_LDSCRIPT            "arch/arm/cpu/armv8/u-boot-spl.lds"
#define CONFIG_SPL_STACK               0x013E000
#define CONFIG_SPL_LIBCOMMON_SUPPORT
#define CONFIG_SPL_LIBGENERIC_SUPPORT
#define CONFIG_SPL_SERIAL_SUPPORT
#define CONFIG_SPL_BSS_START_ADDR      0x00128000
#define CONFIG_SPL_BSS_MAX_SIZE        0x1000  /* 4 KB */
#define CONFIG_SYS_SPL_MALLOC_START    0x00120000
#define CONFIG_SYS_SPL_MALLOC_SIZE     0x3000  /* 12 KB */
#define CONFIG_SERIAL_LPUART_BASE      0x5a060000
#define CONFIG_SYS_ICACHE_OFF
#define CONFIG_SYS_DCACHE_OFF
#define CONFIG_MALLOC_F_ADDR           0x00120000 /* malloc f used before GD_FLG_FULL_MALLOC_INIT set */

#define CONFIG_SPL_RAW_IMAGE_ARM_TRUSTED_FIRMWARE

#define CONFIG_SPL_ABORT_ON_RAW_IMAGE /* For RAW image gives a error info not panic */

#define CONFIG_OF_EMBED
#define CONFIG_ATF_TEXT_BASE 0x80000000
#define CONFIG_SYS_ATF_START 0x80000000
/* #define CONFIG_FIT */

/* Since the SPL runs before ATF, MU1 will not be started yet, so use MU0 */
#define SC_IPC_CH                      SC_IPC_AP_CH0

#endif


#define CONFIG_REMAKE_ELF

#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_ARCH_MISC_INIT

#define CONFIG_CMD_READ

/* Flat Device Tree Definitions */
#define CONFIG_OF_BOARD_SETUP

#undef CONFIG_CMD_EXPORTENV
#undef CONFIG_CMD_IMPORTENV
#undef CONFIG_CMD_IMLS

#undef CONFIG_CMD_CRC32
#undef CONFIG_BOOTM_NETBSD

#define CONFIG_FSL_ESDHC
#define CONFIG_FSL_USDHC
#define CONFIG_SYS_FSL_ESDHC_ADDR       0
#define USDHC1_BASE_ADDR                0x5B010000
#define USDHC2_BASE_ADDR                0x5B020000
#define CONFIG_SUPPORT_EMMC_BOOT	/* eMMC specific */

#define CONFIG_ENV_OVERWRITE

#define CONFIG_SCSI
#define CONFIG_SCSI_AHCI
#define CONFIG_SCSI_AHCI_PLAT
#define CONFIG_SYS_SCSI_MAX_SCSI_ID 1
#define CONFIG_CMD_SCSI
#define CONFIG_LIBATA
#define CONFIG_SYS_SCSI_MAX_LUN 1
#define CONFIG_SYS_SCSI_MAX_DEVICE      (CONFIG_SYS_SCSI_MAX_SCSI_ID * CONFIG_SYS_SCSI_MAX_LUN)
#define CONFIG_SYS_SCSI_MAXDEVICE       CONFIG_SYS_SCSI_MAX_DEVICE
#define CONFIG_SYS_SATA_MAX_DEVICE	1
#define CONFIG_SATA_IMX

#define CONFIG_FSL_HSIO
#define CONFIG_PCIE_IMX8X
#define CONFIG_CMD_PCI
#define CONFIG_PCI
#define CONFIG_PCI_PNP
#define CONFIG_PCI_SCAN_SHOW

#define CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
/* FUSE command */
#define CONFIG_CMD_FUSE

/* GPIO configs */
#define CONFIG_MXC_GPIO

/* eMMC uSD Configuration */
#define BOOT_ID_EMMC 0
#define ROOT_ID_EMMC 0
#define BOOT_ID_USD  1
#define ROOT_ID_USD  1

/* ENET Config */
#define CONFIG_MII

#define CONFIG_FEC_MXC
#define CONFIG_FEC_XCV_TYPE             RGMII
#define FEC_QUIRK_ENET_MAC

#define CONFIG_PHY_GIGE /* Support for 1000BASE-X */
#define CONFIG_PHYLIB
#define CONFIG_PHY_TI

/* ENET0 connects AR8031 on CPU board, ENET1 connects to base board */
#define CONFIG_FEC_ENET_DEV 0

#if (CONFIG_FEC_ENET_DEV == 0)
#define IMX_FEC_BASE			0x5B040000
#define CONFIG_FEC_MXC_PHYADDR          0x9
#define CONFIG_ETHPRIME                 "eth1"
#elif (CONFIG_FEC_ENET_DEV == 1)
#define IMX_FEC_BASE                    0x5B050000
#define CONFIG_FEC_MXC_PHYADDR          0x9
#define CONFIG_ETHPRIME                 "eth0"
#endif


#define CONFIG_LIB_RAND
#define CONFIG_NET_RANDOM_ETHADDR

#ifdef CONFIG_AHAB_BOOT
#define AHAB_ENV "sec_boot=yes\0"
#else
#define AHAB_ENV "sec_boot=no\0"
#endif

#define JAILHOUSE_ENV \
	"jh_mmcboot=" \
		"setenv fdt_file fsl-imx8qm-mek-root.dtb;"\
		"setenv boot_os 'scu_rm dtb ${fdt_addr}; booti ${loadaddr} - ${fdt_addr};'; " \
		"run mmcboot; \0" \
	"jh_netboot=" \
		"setenv fdt_file fsl-imx8qm-mek-root.dtb;"\
		"setenv boot_os 'scu_rm dtb ${fdt_addr}; booti ${loadaddr} - ${fdt_addr};'; " \
		"run netboot; \0"

#define XEN_BOOT_ENV \
            "xenhyper_bootargs=console=dtuart dtuart=/serial@5a060000 dom0_mem=2048M dom0_max_vcpus=2 dom0_vcpus_pin=true hmp-unsafe=true\0" \
            "xenlinux_bootargs= \0" \
            "xenlinux_console=hvc0 earlycon=xen\0" \
            "xenlinux_addr=0x85000000\0" \
	    "dom0fdt_file=fsl-imx8qm-mek-dom0.dtb\0" \
            "xenboot_common=" \
                "${get_cmd} ${loadaddr} xen;" \
                "${get_cmd} ${fdt_addr} ${dom0fdt_file};" \
		"scu_rm dtb ${fdt_addr};" \
                "if ${get_cmd} ${hdp_addr} ${hdp_file}; then; hdp load ${hdp_addr}; fi;" \
				"if ${get_cmd} ${hdprx_addr} ${hdprx_file}; then; hdprx load ${hdprx_addr}; fi;" \
                "${get_cmd} ${xenlinux_addr} ${image};" \
                "fdt addr ${fdt_addr};" \
                "fdt resize 256;" \
                "fdt set /chosen/module@0 reg <0x00000000 ${xenlinux_addr} 0x00000000 0x${filesize}>; " \
                "fdt set /chosen/module@0 bootargs \"${bootargs} ${xenlinux_bootargs}\"; " \
                "setenv bootargs ${xenhyper_bootargs};" \
                "booti ${loadaddr} - ${fdt_addr};" \
            "\0" \
            "xennetboot=" \
                "setenv get_cmd dhcp;" \
                "setenv console ${xenlinux_console};" \
                "run netargs;" \
                "run xenboot_common;" \
            "\0" \
            "xenmmcboot=" \
                "setenv get_cmd \"fatload mmc ${mmcdev}:${mmcpart}\";" \
                "setenv console ${xenlinux_console};" \
                "run mmcargs;" \
                "run xenboot_common;" \
            "\0" \
/* Boot M4 */
#define M4_BOOT_ENV \
	"m4_0_image=m4_0.bin\0" \
	"m4_1_image=m4_1.bin\0" \
	"loadm4image_0=fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${m4_0_image}\0" \
	"loadm4image_1=fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${m4_1_image}\0" \
	"m4boot_0=run loadm4image_0; dcache flush; bootaux ${loadaddr} 0\0" \
	"m4boot_1=run loadm4image_1; dcache flush; bootaux ${loadaddr} 1\0" \

#ifdef CONFIG_NAND_BOOT
#define MFG_NAND_PARTITION "mtdparts=gpmi-nand:128m(boot),32m(kernel),16m(dtb),8m(misc),-(rootfs) "
#else
#define MFG_NAND_PARTITION ""
#endif

#define CONFIG_MFG_ENV_SETTINGS \
	CONFIG_MFG_ENV_SETTINGS_DEFAULT \
	"initrd_addr=0x83100000\0" \
	"initrd_high=0xffffffffffffffff\0" \
	"emmc_dev=0\0" \
	"sd_dev=1\0" \


/* Link Definitions */
#define CONFIG_LOADADDR			0x80280000

#define CONFIG_SYS_LOAD_ADDR           CONFIG_LOADADDR

#define CONFIG_SYS_INIT_SP_ADDR         0x80200000


/* Default environment is in SD */
#define CONFIG_ENV_SIZE			0x2000

#ifdef CONFIG_QSPI_BOOT
#define CONFIG_ENV_OFFSET       (4 * 1024 * 1024)
#define CONFIG_ENV_SECT_SIZE	(128 * 1024)
#define CONFIG_ENV_SPI_BUS	CONFIG_SF_DEFAULT_BUS
#define CONFIG_ENV_SPI_CS	CONFIG_SF_DEFAULT_CS
#define CONFIG_ENV_SPI_MODE	CONFIG_SF_DEFAULT_MODE
#define CONFIG_ENV_SPI_MAX_HZ	CONFIG_SF_DEFAULT_SPEED
#else
#define CONFIG_ENV_OFFSET       (64 * SZ_64K)
#define CONFIG_SYS_MMC_ENV_PART		0	/* user area */
#endif

#define CONFIG_SYS_MMC_IMG_LOAD_PART	1

#define CONFIG_SYS_MMC_ENV_DEV		1   /* USDHC2 */
#define CONFIG_MMCROOT			"/dev/mmcblk1p2"  /* USDHC2 */
#define CONFIG_SYS_FSL_USDHC_NUM	2


/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		((CONFIG_ENV_SIZE + (32*1024)) * 1024)

#define CONFIG_SYS_SDRAM_BASE		0x80000000
#define CONFIG_NR_DRAM_BANKS		2
#define PHYS_SDRAM_1			0x80000000
#define PHYS_SDRAM_2			0x880000000
#define PHYS_SDRAM_1_SIZE		0x80000000	/* 2 GB */
#define PHYS_SDRAM_2_SIZE		0x0
#define PHYS_DRAM_IS_1GB                0x40000000
#define PHYS_DRAM_IS_2GB                0x80000000
#define PHYS_DRAM_IS_3GB                0xc0000000
#define PHYS_DRAM_IS_4GB                0x100000000

#define CONFIG_SYS_MEMTEST_START    0xA0000000
#define CONFIG_SYS_MEMTEST_END      (CONFIG_SYS_MEMTEST_START + (PHYS_SDRAM_1_SIZE >> 2))

/* Serial */
#define CONFIG_BAUDRATE			115200

#define CONSOLE_DEV                     "ttyLP0"
#define DEFAULT_FDT_FILE                "seco-imx8qm-c43.dtb"
#define DEFAULT_OVERLAY_FILE            "seco-imx8qm-c43-wilink.dtbo"
#define DEFAULT_HDPTX_FILE                "hdmitxfw.bin"
#define DEFAULT_HDPRX_FILE                "hdmirxfw.bin"
/* Monitor Command Prompt */
#undef  CONFIG_SYS_PROMPT
#define CONFIG_SYS_PROMPT	       "u-boot seco c43=> "
#define CONFIG_HUSH_PARSER
#define CONFIG_SYS_PROMPT_HUSH_PS2     "u-boot seco c43=> "
#define CONFIG_SYS_CBSIZE              2048
#define CONFIG_SYS_MAXARGS             64
#define CONFIG_SYS_BARGSIZE CONFIG_SYS_CBSIZE
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + \
					sizeof(CONFIG_SYS_PROMPT) + 16)

/* Generic Timer Definitions */
#define COUNTER_FREQUENCY		8000000	/* 8MHz */

#define CONFIG_IMX_SMMU

/* MT35XU512ABA1G12 has only one Die, so QSPI0 B won't work */
#ifdef CONFIG_FSL_FSPI
#define CONFIG_SF_DEFAULT_BUS		0
#define CONFIG_SF_DEFAULT_CS		0
#define CONFIG_SF_DEFAULT_SPEED	40000000
#define CONFIG_SF_DEFAULT_MODE		SPI_MODE_0
#define FSL_FSPI_FLASH_SIZE		SZ_64M
#define FSL_FSPI_FLASH_NUM		1
#define FSPI0_BASE_ADDR			0x5d120000
#define FSPI0_AMBA_BASE			0
#define CONFIG_SYS_FSL_FSPI_AHB
#endif

#define CONFIG_SERIAL_TAG

/* USB Config */
#ifdef CONFIG_CMD_USB
#define CONFIG_USB_MAX_CONTROLLER_COUNT 2

/* USB OTG controller configs */
#ifdef CONFIG_USB_EHCI_HCD
#define CONFIG_USB_HOST_ETHER
#define CONFIG_USB_ETHER_ASIX
#define CONFIG_MXC_USB_PORTSC		(PORT_PTS_UTMI | PORT_PTS_PTW)
#endif
#endif /* CONFIG_CMD_USB */

#ifdef CONFIG_USB_GADGET
#define CONFIG_USBD_HS
#endif

/* Framebuffer */
#ifdef CONFIG_VIDEO
#define CONFIG_VIDEO_IMXDPUV1
#define CONFIG_VIDEO_BMP_RLE8
#define CONFIG_SPLASH_SCREEN
#define CONFIG_SPLASH_SCREEN_ALIGN
#define CONFIG_BMP_16BPP
#define CONFIG_VIDEO_LOGO
#define CONFIG_VIDEO_BMP_LOGO
#define CONFIG_IMX_VIDEO_SKIP
#endif

#define CONFIG_OF_SYSTEM_SETUP
#define BOOTAUX_RESERVED_MEM_BASE 0x88000000
#define BOOTAUX_RESERVED_MEM_SIZE 0x08000000 /* Reserve from second 128MB */

#if defined(CONFIG_ANDROID_SUPPORT)
#include "seco_imx8qm_c43_android.h"
#elif defined (CONFIG_ANDROID_AUTO_SUPPORT)
#include "seco_imx8qm_c43_android_auto.h"
#endif

#endif /* __SECO_IMX8QM_C43_H */
