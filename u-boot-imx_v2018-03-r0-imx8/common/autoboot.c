/*
 * (C) Copyright 2000
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <autoboot.h>
#include <bootretry.h>
#include <cli.h>
#include <console.h>
#include <fdtdec.h>
#include <menu.h>
#include <post.h>
#include <u-boot/sha256.h>

#ifdef is_boot_from_usb
#include <environment.h>
#endif

DECLARE_GLOBAL_DATA_PTR;

#define MAX_DELAY_STOP_STR 32

#ifndef DEBUG_BOOTKEYS
#define DEBUG_BOOTKEYS 0
#endif
#define debug_bootkeys(fmt, args...)		\
	debug_cond(DEBUG_BOOTKEYS, fmt, ##args)

/* Stored value of bootdelay, used by autoboot_command() */
static int stored_bootdelay;

#if defined(CONFIG_AUTOBOOT_KEYED)
#if defined(CONFIG_AUTOBOOT_STOP_STR_SHA256)

/*
 * Use a "constant-length" time compare function for this
 * hash compare:
 *
 * https://crackstation.net/hashing-security.htm
 */
static int slow_equals(u8 *a, u8 *b, int len)
{
	int diff = 0;
	int i;

	for (i = 0; i < len; i++)
		diff |= a[i] ^ b[i];

	return diff == 0;
}

static int passwd_abort(uint64_t etime)
{
	const char *sha_env_str = env_get("bootstopkeysha256");
	u8 sha_env[SHA256_SUM_LEN];
	u8 sha[SHA256_SUM_LEN];
	char presskey[MAX_DELAY_STOP_STR];
	const char *algo_name = "sha256";
	u_int presskey_len = 0;
	int abort = 0;
	int size = sizeof(sha);
	int ret;

	if (sha_env_str == NULL)
		sha_env_str = CONFIG_AUTOBOOT_STOP_STR_SHA256;

	/*
	 * Generate the binary value from the environment hash value
	 * so that we can compare this value with the computed hash
	 * from the user input
	 */
	ret = hash_parse_string(algo_name, sha_env_str, sha_env);
	if (ret) {
		printf("Hash %s not supported!\n", algo_name);
		return 0;
	}

	/*
	 * We don't know how long the stop-string is, so we need to
	 * generate the sha256 hash upon each input character and
	 * compare the value with the one saved in the environment
	 */
	do {
		if (tstc()) {
			/* Check for input string overflow */
			if (presskey_len >= MAX_DELAY_STOP_STR)
				return 0;

			presskey[presskey_len++] = getc();

			/* Calculate sha256 upon each new char */
			hash_block(algo_name, (const void *)presskey,
				   presskey_len, sha, &size);

			/* And check if sha matches saved value in env */
			if (slow_equals(sha, sha_env, SHA256_SUM_LEN))
				abort = 1;
		}
	} while (!abort && get_ticks() <= etime);

	return abort;
}
#else
static int passwd_abort(uint64_t etime)
{
	int abort = 0;
	struct {
		char *str;
		u_int len;
		int retry;
	}
	delaykey[] = {
		{ .str = env_get("bootdelaykey"),  .retry = 1 },
		{ .str = env_get("bootstopkey"),   .retry = 0 },
	};

	char presskey[MAX_DELAY_STOP_STR];
	u_int presskey_len = 0;
	u_int presskey_max = 0;
	u_int i;

#  ifdef CONFIG_AUTOBOOT_DELAY_STR
	if (delaykey[0].str == NULL)
		delaykey[0].str = CONFIG_AUTOBOOT_DELAY_STR;
#  endif
#  ifdef CONFIG_AUTOBOOT_STOP_STR
	if (delaykey[1].str == NULL)
		delaykey[1].str = CONFIG_AUTOBOOT_STOP_STR;
#  endif

	for (i = 0; i < sizeof(delaykey) / sizeof(delaykey[0]); i++) {
		delaykey[i].len = delaykey[i].str == NULL ?
				    0 : strlen(delaykey[i].str);
		delaykey[i].len = delaykey[i].len > MAX_DELAY_STOP_STR ?
				    MAX_DELAY_STOP_STR : delaykey[i].len;

		presskey_max = presskey_max > delaykey[i].len ?
				    presskey_max : delaykey[i].len;

		debug_bootkeys("%s key:<%s>\n",
			       delaykey[i].retry ? "delay" : "stop",
			       delaykey[i].str ? delaykey[i].str : "NULL");
	}

	/* In order to keep up with incoming data, check timeout only
	 * when catch up.
	 */
	do {
		if (tstc()) {
			if (presskey_len < presskey_max) {
				presskey[presskey_len++] = getc();
			} else {
				for (i = 0; i < presskey_max - 1; i++)
					presskey[i] = presskey[i + 1];

				presskey[i] = getc();
			}
		}

		for (i = 0; i < sizeof(delaykey) / sizeof(delaykey[0]); i++) {
			if (delaykey[i].len > 0 &&
			    presskey_len >= delaykey[i].len &&
				memcmp(presskey + presskey_len -
					delaykey[i].len, delaykey[i].str,
					delaykey[i].len) == 0) {
					debug_bootkeys("got %skey\n",
						delaykey[i].retry ? "delay" :
						"stop");

				/* don't retry auto boot */
				if (!delaykey[i].retry)
					bootretry_dont_retry();
				abort = 1;
			}
		}
	} while (!abort && get_ticks() <= etime);

	return abort;
}
#endif

/***************************************************************************
 * Watch for 'delay' seconds for autoboot stop or autoboot delay string.
 * returns: 0 -  no key string, allow autoboot 1 - got key string, abort
 */
static int __abortboot(int bootdelay)
{
	int abort;
	uint64_t etime = endtick(bootdelay);

#  ifdef CONFIG_AUTOBOOT_PROMPT
	/*
	 * CONFIG_AUTOBOOT_PROMPT includes the %d for all boards.
	 * To print the bootdelay value upon bootup.
	 */
	printf(CONFIG_AUTOBOOT_PROMPT, bootdelay);
#  endif

	abort = passwd_abort(etime);
	if (!abort)
		debug_bootkeys("key timeout\n");

	return abort;
}

# else	/* !defined(CONFIG_AUTOBOOT_KEYED) */

#ifdef CONFIG_MENUKEY
static int menukey;
#endif

static int __abortboot(int bootdelay)
{
	int abort = 0;
	unsigned long ts;

#ifdef CONFIG_MENUPROMPT
	printf(CONFIG_MENUPROMPT);
#else
	printf("Hit any key to stop autoboot: %2d ", bootdelay);
#endif

	/*
	 * Check if key already pressed
	 */
	if (tstc()) {	/* we got a key press	*/
		(void) getc();  /* consume input	*/
		puts("\b\b\b 0");
		abort = 1;	/* don't auto boot	*/
	}

	while ((bootdelay > 0) && (!abort)) {
		--bootdelay;
		/* delay 1000 ms */
		ts = get_timer(0);
		do {
			if (tstc()) {	/* we got a key press	*/
				abort  = 1;	/* don't auto boot	*/
				bootdelay = 0;	/* no more delay	*/
# ifdef CONFIG_MENUKEY
				menukey = getc();
# else
				(void) getc();  /* consume input	*/
# endif
				break;
			}
			udelay(10000);
		} while (!abort && get_timer(ts) < 1000);

		printf("\b\b\b%2d ", bootdelay);
	}

	putc('\n');

	return abort;
}
# endif	/* CONFIG_AUTOBOOT_KEYED */

static int abortboot(int bootdelay)
{
	int abort = 0;

	if (bootdelay >= 0)
		abort = __abortboot(bootdelay);

#ifdef CONFIG_SILENT_CONSOLE
	if (abort)
		gd->flags &= ~GD_FLG_SILENT;
#endif

	return abort;
}

static void process_fdt_options(const void *blob)
{
#if defined(CONFIG_OF_CONTROL) && defined(CONFIG_SYS_TEXT_BASE)
	ulong addr;

	/* Add an env variable to point to a kernel payload, if available */
	addr = fdtdec_get_config_int(gd->fdt_blob, "kernel-offset", 0);
	if (addr)
		env_set_addr("kernaddr", (void *)(CONFIG_SYS_TEXT_BASE + addr));

	/* Add an env variable to point to a root disk, if available */
	addr = fdtdec_get_config_int(gd->fdt_blob, "rootdisk-offset", 0);
	if (addr)
		env_set_addr("rootaddr", (void *)(CONFIG_SYS_TEXT_BASE + addr));
#endif /* CONFIG_OF_CONTROL && CONFIG_SYS_TEXT_BASE */
}

const char *bootdelay_process(void)
{
	char *s;
	int bootdelay;
#ifdef CONFIG_BOOTCOUNT_LIMIT
	unsigned long bootcount = 0;
	unsigned long bootlimit = 0;
#endif /* CONFIG_BOOTCOUNT_LIMIT */

#ifdef CONFIG_BOOTCOUNT_LIMIT
	bootcount = bootcount_load();
	bootcount++;
	bootcount_store(bootcount);
	env_set_ulong("bootcount", bootcount);
	bootlimit = env_get_ulong("bootlimit", 10, 0);
#endif /* CONFIG_BOOTCOUNT_LIMIT */
	env_set("bootdelay", "1");

	s = env_get("bootdelay");
	bootdelay = s ? (int)simple_strtol(s, NULL, 10) : CONFIG_BOOTDELAY;

#if defined(is_boot_from_usb)
	if (is_boot_from_usb() && env_get("bootcmd_mfg")) {
		disconnect_from_pc();
		printf("Boot from USB for mfgtools\n");
		bootdelay = 0;
		set_default_env("Use default environment for \
				 mfgtools\n");
	} else if (is_boot_from_usb()) {
		printf("Boot from USB for uuu\n");
		env_set("bootcmd", "fastboot 0");
	} else {
		printf("Normal Boot\n");
	}
#endif

#ifdef CONFIG_OF_CONTROL
	bootdelay = fdtdec_get_config_int(gd->fdt_blob, "bootdelay",
			bootdelay);
#endif

	debug("### main_loop entered: bootdelay=%d\n\n", bootdelay);

#if defined(CONFIG_MENU_SHOW)
/*	env_set("bootmenu_1", "Internal eMMC=setenv root_dev root=/dev/mmcblk0p2 rootwait rw; setenv root_set_dev rw;"\
			"setenv kernel_load \"mmc dev 0; fatload mmc 0:1 ${kernel_loadaddr} ${kernel_file};\";"\
			"setenv fdt_load \"mmc dev 0; fatload mmc 0:1 ${fdt_loadaddr} ${fdt_file};\";" \
			"setenv console_interface console=ttymxc2,115200; run bootargs_base; " \
			"boot") ;*/
	env_set("bootmenu_0", "Internal eMMC System=setenv root_dev root=LABEL=System rootwait rw quiet; setenv root_set_dev rw;"\
			"setenv console_interface \"console=/dev/ttymxc1,115200 console=tty1\";"\
			"setenv kernel_load \"mmc dev 0; ext4load mmc 0:1 ${kernel_loadaddr} ${kernel_file};\";"\
			"setenv fdt_load \"mmc dev 0; ext4load mmc 0:1 ${fdt_loadaddr} ${fdt_file};\";" \
			"setenv initrd_load \"mmc dev 0; ext4load mmc 0:1 0x43100000 initrd.gz;\";" \
			"setenv console_interface \"console=ttymxc1,115200  console=tty1\";" \
			"run bootargs_base; run kernel_load; run fdt_load; run initrd_load;" \
			"booti ${kernel_loadaddr} 0x43100000 ${fdt_loadaddr}") ;

	env_set("bootmenu_1", "Reserve eMMC=run bootmenuemmc_reserve");

	env_set("bootmenu_2", "External USB=setenv root_dev root=/dev/sda1 rootwait rw quiet; setenv root_set_dev rw;"\
			"setenv console_interface \"console=/dev/ttymxc1,115200\";"\
			"setenv kernel_load \"usb start; ext4load usb 0:1 ${kernel_loadaddr} ${kernel_file};\";"\
			"setenv fdt_load \"ext4load usb 0:1 ${fdt_loadaddr} ${fdt_file};\";" \
			"setenv initrd_load \"ext4load usb 0:1 0x43100000 initrd.gz;\";" \
			"setenv console_interface console=ttymxc1,115200; run bootargs_base; " \
			"run kernel_load; run fdt_load; run initrd_load; booti ${kernel_loadaddr} 0x43100000 ${fdt_loadaddr}") ;

	env_set("bootmenu_3", "External SD=setenv root_dev root=/dev/mmcblk1p1 rootwait rw quiet; setenv root_set_dev ro;"\
			"setenv console_interface \"console=/dev/ttymxc1,115200 console=tty1\";"\
			"setenv kernel_load \"mmc dev 1; ext4load mmc 1:1 ${kernel_loadaddr} ${kernel_file};\";"\
			"setenv fdt_load \"mmc dev 1; ext4load mmc 1:1 ${fdt_loadaddr} ${fdt_file};\";" \
			"setenv initrd_load \"mmc dev 1; ext4load mmc 1:1 0x43100000 initrd.gz;\";" \
			"setenv console_interface console=ttymxc1,115200 console=tty1;" \
			"run bootargs_base; run kernel_load; run fdt_load; run initrd_load;" \
			"booti ${kernel_loadaddr} 0x43100000 ${fdt_loadaddr}") ;

	env_set("bootmenu_4", "External Reserve SD=run bootmenusd_reserve");

/*	env_set("bootmenu_5", "LZMA Reserve=setenv root_dev root=/dev/mmcblk0p1 rw; setenv root_set_dev rw;"\
			"setenv console_interface \"console=/dev/ttymxc1,115200\";"\
			"setenv kernel_load \"mmc dev 0; ext4load mmc 0:2 0x40080000 Image.lzma;\";"\
			"setenv fdt_load \"ext4load mmc 0:2 ${fdt_loadaddr} ${fdt_file};\";" \
			"setenv initrd_load \"ext4load mmc 0:2 0x43100000 initrd.lzma;\";" \
			"setenv console_interface console=ttymxc1,115200;" \
			"run bootargs_base; run kernel_load; run fdt_load; run initrd_load;" \
			"bootm 0x40080000 0x43100000 ${fdt_loadaddr}") ;

	env_set("bootmenu_5", "LZMA QSPI=setenv root_dev root=/dev/mmcblk0p1 rw; setenv root_set_dev rw;"\
			"setenv console_interface \"console=/dev/ttymxc1,115200\";"\
			"setenv kernel_load \"sf probe; sf read 0x40080000 0x10000 3d0000;\";"\
			"setenv fdt_load \"sf read ${fdt_loadaddr} 0x0 10000;\";" \
			"setenv initrd_load \"sf read 0x43100000 0x3e0000 370000;\";" \
			"setenv console_interface console=ttymxc1,115200;" \
			"run bootargs_base; run kernel_load; run fdt_load; run initrd_load;" \
			"bootm 0x40080000 0x43100000 0x43000100") ;
*/
	env_set("bootmenu_5", "Internal eMMC System debug=setenv root_dev root=LABEL=System rootwait rw; setenv root_set_dev rw;"\
			"setenv console_interface \"console=/dev/ttymxc1,115200\";"\
			"setenv kernel_load \"mmc dev 0; ext4load mmc 0:1 ${kernel_loadaddr} ${kernel_file};\";"\
			"setenv fdt_load \"mmc dev 0; ext4load mmc 0:1 ${fdt_loadaddr} ${fdt_file};\";" \
			"setenv initrd_load \"mmc dev 0; ext4load mmc 0:1 0x43100000 initrd.gz;\";" \
			"setenv console_interface console=ttymxc1,115200;" \
			"run bootargs_base; run kernel_load; run fdt_load; run initrd_load;" \
			"booti ${kernel_loadaddr} 0x43100000 ${fdt_loadaddr}") ;

/*	env_set("bootmenu_7", "External SD=setenv root_dev root=/dev/mmcblk1p2 rootwait rw ; setenv root_set_dev ro;"\
			"setenv console_interface \"console=/dev/ttymxc1,115200,earlycon=ec_imx6q,0x30890000,115200\";"\
			"setenv kernel_load \"mmc dev 1; fatload mmc 1:1 ${kernel_loadaddr} ${kernel_file};\";"\
			"setenv fdt_load \"mmc dev 1; fatload mmc 1:1 ${fdt_loadaddr} ${fdt_file};\";" \
			"setenv console_interface console=ttymxc1,115200,earlycon=ec_imx6q,0x30890000,115200;" \
			"run bootargs_base; run kernel_load; run fdt_load;" \
			"booti ${kernel_loadaddr} - ${fdt_loadaddr}") ;
*/
	env_set("bootmenu_6", "External USB_fat=setenv root_dev root=/dev/sda2 rootwait rw quiet; setenv root_set_dev rw;"\
			"setenv console_interface \"console=/dev/ttymxc1,115200\";"\
			"setenv kernel_load \"usb start; fatload usb 0:1 ${kernel_loadaddr} ${kernel_file};\";"\
			"setenv fdt_load \"fatload usb 0:1 ${fdt_loadaddr} ${fdt_file};\";" \
			"setenv console_interface console=ttymxc1,115200; run bootargs_base; " \
			"run kernel_load; run fdt_load; booti ${kernel_loadaddr} - ${fdt_loadaddr}") ;

	env_set("bootmenu_7", "Internal eMMC_fat=setenv root_dev root=/dev/mmcblk0p2 rootwait rw quiet; setenv root_set_dev rw;"\
			"setenv console_interface \"console=/dev/ttymxc1,115200\";"\
			"setenv kernel_load \"mmc dev 0; fatload mmc 0:1 ${kernel_loadaddr} ${kernel_file};\";"\
			"setenv fdt_load \"fatload mmc 0:1 ${fdt_loadaddr} ${fdt_file};\";" \
			"setenv console_interface console=ttymxc1,115200; run bootargs_base; " \
			"run kernel_load; run fdt_load; booti ${kernel_loadaddr} - ${fdt_loadaddr}") ;

	env_set("bootmenusd_reserve", "setenv root_dev root=LABEL=Reservesd rootwait ro; setenv root_set_dev ro;"\
			"setenv kernel_load \"mmc dev 1; ext4load mmc 1:2 ${kernel_loadaddr} ${kernel_file};\";"\
			"setenv fdt_load \"mmc dev 1; ext4load mmc 1:2 ${fdt_loadaddr} ${fdt_file};\";" \
			"setenv initrd_load \"mmc dev 1; ext4load mmc 1:2 0x43100000 initrd.gz;\";" \
			"setenv console_interface console=ttymxc2,115200;" \
			"run bootargs_base; run kernel_load; run fdt_load; run initrd_load;" \
			"booti ${kernel_loadaddr} 0x43100000 ${fdt_loadaddr}") ;

	env_set("bootmenuemmc_reserve", "setenv root_dev root=LABEL=Reserve rootwait ro; setenv root_set_dev ro;"\
			"setenv kernel_load \"mmc dev 0; ext4load mmc 0:2 ${kernel_loadaddr} ${kernel_file};\";"\
			"setenv fdt_load \"mmc dev 0; ext4load mmc 0:2 ${fdt_loadaddr} ${fdt_file};\";" \
			"setenv initrd_load \"mmc dev 0; ext4load mmc 0:2 0x43100000 initrd.gz;\";" \
			"setenv console_interface console=ttymxc1,115200;" \
			"run bootargs_base; run kernel_load; run fdt_load; run initrd_load;" \
			"booti ${kernel_loadaddr} 0x43100000 ${fdt_loadaddr}") ;

//	"setenv options ectrl=prog;"
//	env_set("stdout", "serial,vga");
//	env_set("stdin", "serial,vga");

	env_set("bootmenu_delay", "1");
	env_set("bootmenu_default", "1");

	bootdelay = menu_show(bootdelay);
#endif
	bootretry_init_cmd_timeout();

#ifdef CONFIG_POST
	if (gd->flags & GD_FLG_POSTFAIL) {
		s = env_get("failbootcmd");
	} else
#endif /* CONFIG_POST */
#ifdef CONFIG_BOOTCOUNT_LIMIT
	if (bootlimit && (bootcount > bootlimit)) {
		printf("Warning: Bootlimit (%u) exceeded. Using altbootcmd.\n",
		       (unsigned)bootlimit);
		s = env_get("altbootcmd");
	} else
#endif /* CONFIG_BOOTCOUNT_LIMIT */
		s = env_get("bootcmd");

#if defined(is_boot_from_usb)
	if (is_boot_from_usb() && env_get("bootcmd_mfg")) {
		s = env_get("bootcmd_mfg");
		printf("Run bootcmd_mfg: %s\n", s);
	}
#endif

	process_fdt_options(gd->fdt_blob);
	stored_bootdelay = bootdelay;

	return s;
}

void autoboot_command(const char *s)
{
	debug("### main_loop: bootcmd=\"%s\"\n", s ? s : "<UNDEFINED>");

	if (stored_bootdelay != -1 && s && !abortboot(stored_bootdelay)) {
#if defined(CONFIG_AUTOBOOT_KEYED) && !defined(CONFIG_AUTOBOOT_KEYED_CTRLC)
		int prev = disable_ctrlc(1);	/* disable Control C checking */
#endif

		run_command_list(s, -1, 0);

#if defined(CONFIG_AUTOBOOT_KEYED) && !defined(CONFIG_AUTOBOOT_KEYED_CTRLC)
		disable_ctrlc(prev);	/* restore Control C checking */
#endif
	}

#ifdef CONFIG_MENUKEY
	if (menukey == CONFIG_MENUKEY) {
		s = env_get("menucmd");
		if (s)
			run_command_list(s, -1, 0);
	}
#endif /* CONFIG_MENUKEY */
}
