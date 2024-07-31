#ifndef _C20_REVISION_H_
#define _C20_REVISION_H_

#include <asm/arch/imx-regs.h>
#include <asm/arch/crm_regs.h>
#include <asm/gpio.h>
#include <common.h>
#include <malloc.h>
#include <errno.h>
#include <asm/io.h>
#include <miiphy.h>
#include <netdev.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm-generic/gpio.h>

#include <linux/libfdt.h>

void c20_fdt_ram_setup(void *blob, bd_t *bdev);
void c20_fdt_vpu_setup(void *blob, bd_t *bdev);
int c20_get_board_configuration (void);


#define C20_IS_1GB	(!(c20_get_board_configuration() & 0x1) & !(c20_get_board_configuration() & 0x2))
#define C20_IS_2GB	(c20_get_board_configuration() & 0x1)
#define C20_IS_4GB      (c20_get_board_configuration() & 0x2)

#endif
