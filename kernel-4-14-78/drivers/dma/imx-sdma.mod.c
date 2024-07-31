#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("of:N*T*Cfsl,imx6ul-sdma");
MODULE_ALIAS("of:N*T*Cfsl,imx6ul-sdmaC*");
MODULE_ALIAS("of:N*T*Cfsl,imx6sx-sdma");
MODULE_ALIAS("of:N*T*Cfsl,imx6sx-sdmaC*");
MODULE_ALIAS("of:N*T*Cfsl,imx6q-sdma");
MODULE_ALIAS("of:N*T*Cfsl,imx6q-sdmaC*");
MODULE_ALIAS("of:N*T*Cfsl,imx53-sdma");
MODULE_ALIAS("of:N*T*Cfsl,imx53-sdmaC*");
MODULE_ALIAS("of:N*T*Cfsl,imx51-sdma");
MODULE_ALIAS("of:N*T*Cfsl,imx51-sdmaC*");
MODULE_ALIAS("of:N*T*Cfsl,imx35-sdma");
MODULE_ALIAS("of:N*T*Cfsl,imx35-sdmaC*");
MODULE_ALIAS("of:N*T*Cfsl,imx31-sdma");
MODULE_ALIAS("of:N*T*Cfsl,imx31-sdmaC*");
MODULE_ALIAS("of:N*T*Cfsl,imx25-sdma");
MODULE_ALIAS("of:N*T*Cfsl,imx25-sdmaC*");
MODULE_ALIAS("of:N*T*Cfsl,imx7d-sdma");
MODULE_ALIAS("of:N*T*Cfsl,imx7d-sdmaC*");
MODULE_ALIAS("of:N*T*Cfsl,imx8mq-sdma");
MODULE_ALIAS("of:N*T*Cfsl,imx8mq-sdmaC*");
MODULE_ALIAS("platform:imx25-sdma");
MODULE_ALIAS("platform:imx31-sdma");
MODULE_ALIAS("platform:imx35-sdma");
MODULE_ALIAS("platform:imx51-sdma");
MODULE_ALIAS("platform:imx53-sdma");
MODULE_ALIAS("platform:imx6q-sdma");
MODULE_ALIAS("platform:imx6sx-sdma");
MODULE_ALIAS("platform:imx7d-sdma");
MODULE_ALIAS("platform:imx8mq-sdma");
