CONFIG_SYS_MMCSD_FS_BOOT_PARTITION=y
CONFIG_VIDEO_BMP_LOGO=y
CONFIG_BOARD_EARLY_INIT_F=y
CONFIG_IMX_CONFIG="arch/arm/mach-imx/spl_sd.cfg"
CONFIG_SYS_FSL_ESDHC_ADDR=0
CONFIG_BOOTM_VXWORKS=y
CONFIG_IS_MODULE(option)="config_enabled(CONFIG_VAL(option ##_MODULE))"
CONFIG_SYS_LOAD_ADDR=$(CONFIG_LOADADDR)
CONFIG_SYS_FSL_MAX_NUM_OF_SEC=y
CONFIG_SPI_FLASH=y
CONFIG_SYS_INIT_RAM_ADDR=0x40000000
CONFIG_SYS_HELP_CMD_WIDTH=8
CONFIG_NR_DRAM_BANKS=2
CONFIG_IMX_VIDEO_SKIP=y
CONFIG_BOOTM_RTEMS=y
CONFIG_SYS_CBSIZE=2048
CONFIG_SYS_SPL_MALLOC_SIZE=0x80000
CONFIG_SYS_MONITOR_LEN="(512 * 1024)"
CONFIG_SYS_MMCSD_RAW_MODE_U_BOOT_SECTOR=0x300
CONFIG_BOOTM_LINUX=y
CONFIG_BOARD_LATE_INIT=y
CONFIG_MII=y
CONFIG_SPI_FLASH_MACRONIX=y
CONFIG_SYS_MMCSD_RAW_MODE_U_BOOT_USE_SECTOR=y
CONFIG_SYS_FSL_SEC_ADDR="(CAAM_IPS_BASE_ADDR + CONFIG_SYS_FSL_SEC_OFFSET)"
CONFIG_CMD_FUSE=y
CONFIG_OF_SYSTEM_SETUP=y
CONFIG_SPL_LIBCOMMON_SUPPORT=y
CONFIG_PHY_GIGE=y
CONFIG_ENV_OFFSET="(64 * SZ_64K)"
CONFIG_MXC_OCOTP=y
CONFIG_ENV_OVERWRITE=y
CONFIG_ENV_SIZE=0x1800
CONFIG_CMD_PING=y
CONFIG_SPL_BUILD=y
CONFIG_SYS_MALLOC_LEN="((CONFIG_ENV_SIZE + (2*1024) + (16*1024)) * 1024)"
CONFIG_VIDEO_IMXDCSS=y
CONFIG_SYS_MMC_ENV_DEV=0
CONFIG_SYS_I2C_SPEED=100000
CONFIG_SYS_BOOTM_LEN=0x01000000
CONFIG_SYS_DEF_EEPROM_ADDR=0
CONFIG_IMX_BOOTAUX=y
CONFIG_MXC_UART=y
CONFIG_SPLASH_SCREEN=y
CONFIG_SYS_BARGSIZE=$(CONFIG_SYS_CBSIZE)
CONFIG_BOOTM_PLAN9=y
CONFIG_IS_BUILTIN(option)="config_enabled(CONFIG_VAL(option))"
CONFIG_SPL_TEXT_BASE=0x7E1000
CONFIG_VIDEO_BMP_RLE8=y
CONFIG_SYS_FSL_JR0_ADDR="(CONFIG_SYS_FSL_SEC_ADDR + CONFIG_SYS_FSL_JR0_OFFSET)"
CONFIG_POWER_I2C=y
CONFIG_SF_DEFAULT_BUS=0
CONFIG_SYS_MAXARGS=64
CONFIG_BMP_16BPP=y
CONFIG_REMAKE_ELF=y
CONFIG_SYS_PBSIZE="(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)"
CONFIG_MXC_GPIO=y
CONFIG_BOARDDIR="board/seco/seco_imx8mq_c12"
CONFIG_POWER=y
CONFIG_POWER_PFUZE100_I2C_ADDR=0x08
CONFIG_SPL_STACK=0x187FF0
CONFIG_SPI_FLASH_STMICRO=y
CONFIG_SYS_MAX_FLASH_SECT=512
CONFIG_PHYLIB=y
CONFIG_SPL_ABORT_ON_RAW_IMAGE=y
CONFIG_BOARD_POSTCLK_INIT=y
CONFIG_VIDEO_LOGO=y
CONFIG_VIDEO_IMXDCSS_1080P=y
CONFIG_SPL_I2C_SUPPORT=y
CONFIG_SYS_BOOT_RAMDISK_HIGH=y
CONFIG_SPL_GPIO_SUPPORT=y
CONFIG_SYS_MMC_MAX_BLK_COUNT=65535
CONFIG_ZLIB=y
CONFIG_LOADADDR=0x40480000
CONFIG_ETHPRIME="FEC"
CONFIG_FSL_QSPI=y
CONFIG_FSL_USDHC=y
CONFIG_SYS_MMC_IMG_LOAD_PART=y
CONFIG_SYS_FSL_SEC_OFFSET="(0)"
CONFIG_GZIP=y
CONFIG_CMD_SF=y
CONFIG_SYS_INIT_RAM_SIZE=0x80000
CONFIG_FEC_MXC_PHYADDR=9
CONFIG_SYS_BAUDRATE_TABLE="{ 9600, 19200, 38400, 57600, 115200 }"
CONFIG_VAL(option)="config_val(option)"
CONFIG_SPL_LIBGENERIC_SUPPORT=y
CONFIG_SYS_DCACHE_OFF=y
CONFIG_SPL_MMC_SUPPORT=y
CONFIG_SYS_SDRAM_BASE=0x40000000
CONFIG_IMAGE_FORMAT_LEGACY=y
CONFIG_CMD_DHCP=y
CONFIG_SPL_SERIAL_SUPPORT=y
CONFIG_SYS_PROMPT_HUSH_PS2="> "
CONFIG_SYS_FSL_USDHC_NUM=2
CONFIG_SYS_INIT_SP_OFFSET="(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)"
CONFIG_SF_DEFAULT_MODE="SPI_MODE_0"
CONFIG_SYS_SPL_MALLOC_START=0x42200000
CONFIG_SYS_I2C_MXC_I2C2=y
CONFIG_SPL_WATCHDOG_SUPPORT=y
CONFIG_SPI_FLASH_BAR=y
CONFIG_SYS_I2C=y
CONFIG_SPL_DRIVERS_MISC_SUPPORT=y
CONFIG_PHY_TI=y
CONFIG_SPL_BSS_MAX_SIZE=0x2000
CONFIG_SPL_BSS_START_ADDR=0x00180000
CONFIG_SPL_PAD_TO=$(CONFIG_SPL_MAX_SIZE)
CONFIG_EXTRA_ENV_SETTINGS="ENV_COMMON ENV_BOOTARG_BASE ENV_KERNEL ENV_FDT ENV_OVERLAY ENV_ROOT "bootcmd= CMD_SET_BOOT "0"
CONFIG_SYS_INIT_SP_ADDR="(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)"
CONFIG_FSL_ESDHC=y
CONFIG_MENU_SHOW=y
CONFIG_POWER_PFUZE100=y
CONFIG_SUPPORT_EMMC_BOOT=y
CONFIG_MXC_UART_BASE="UART2_BASE_ADDR"
CONFIG_SPLASH_SCREEN_ALIGN=y
CONFIG_OF_BOARD_SETUP=y
CONFIG_SYS_SUPPORT_64BIT_DATA=y
CONFIG_SYS_SPL_PTE_RAM_BASE=0x41580000
CONFIG_FEC_MXC=y
CONFIG_USBD_HS=y
CONFIG_USB_MAX_CONTROLLER_COUNT=2
CONFIG_SPL_MAX_SIZE="(148 * 1024)"
CONFIG_SYS_PROMPT="u-boot seco c12=> "
CONFIG_SYS_MEMTEST_END="(CONFIG_SYS_MEMTEST_START + (PHYS_SDRAM_SIZE >> 1))"
CONFIG_MMCROOT="/dev/mmcblk0p1"
CONFIG_SYS_MEMTEST_START="PHYS_SDRAM"
CONFIG_SF_DEFAULT_SPEED=40000000
CONFIG_LMB=y
CONFIG_SYS_ICACHE_OFF=y
CONFIG_FEC_XCV_TYPE="RGMII"
CONFIG_IS_ENABLED(option)="(config_enabled(CONFIG_VAL(option)) || config_enabled(CONFIG_VAL(option ##_MODULE)))"
CONFIG_SERIAL_TAG=y
CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG=y
CONFIG_SYS_I2C_MXC_I2C1=y
CONFIG_SYS_I2C_MXC_I2C3=y
CONFIG_SYS_FSL_JR0_OFFSET="(0x1000)"
CONFIG_CMD_MII=y
CONFIG_CMD_MMC=y
CONFIG_SPL_POWER_SUPPORT=y
CONFIG_SF_DEFAULT_CS=0
CONFIG_MALLOC_F_ADDR=0x182000
