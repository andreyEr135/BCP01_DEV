/*
 * Analog Devices SN65DSI84 HDMI transmitter driver
 *
 * Copyright 2012 Analog Devices Inc.
 *
 * Licensed under the GPL-2.
 */

#include <linux/device.h>
#include <linux/gpio/consumer.h>
#include <linux/module.h>
#include <linux/of_device.h>
#include <linux/slab.h>

#include <drm/drmP.h>
#include <drm/drm_atomic.h>
#include <drm/drm_atomic_helper.h>
#include <drm/drm_edid.h>
#include <linux/of_graph.h>
#include <linux/of_gpio.h>
#include <video/videomode.h>
#include <drm/drm_panel.h>

#include "sn65dsi84.h"
#include "sn65dsi84_edid.h"


/* -----------------------------------------------------------------------------
 * Register access
 */

static const uint8_t sn65dsi84_register_defaults[] = { };

static bool sn65dsi84_register_volatile(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case	SN65DSI84_REG_CHIP_REVISION:
	case	SN65DSI84_REG_RESET:
	case	SN65DSI84_REG_LVDS_CLK:
	case	SN65DSI84_REG_CLK_DIV_MUL:
	case	SN65DSI84_REG_I2S_CONFG:
	case	SN65DSI84_REG_PLL_EN:
	case	SN65DSI84_REG_DSI_LANES:
	case	SN65DSI84_REG_DSI_EQ:
	case	SN65DSI84_REG_DSI_CLK_RANGE:
	case	SN65DSI84_REG_LVDS_PARAMETER:
	case	SN65DSI84_REG_LVDS_STRENGTH:
	case	SN65DSI84_REG_LVDS_SWAP:
	case	SN65DSI84_REG_LVDS_COMMON_MODE:
	case	SN65DSI84_REG_CHA_ACTIVE_LINE_LENGTH_LOW:
	case	SN65DSI84_REG_CHA_ACTIVE_LINE_LENGTH_HIGH:
	case	SN65DSI84_REG_CHA_VERTICAL_DISPLAY_SIZE_LOW:
	case	SN65DSI84_REG_CHA_VERTICAL_DISPLAY_SIZE_HIGH:
	case	SN65DSI84_REG_CHA_SYNC_DELAY_LOW:
	case	SN65DSI84_REG_CHA_SYNC_DELAY_HIGH:
	case	SN65DSI84_REG_CHA_HSYNC_PULSE_WIDTH_LOW:
	case	SN65DSI84_REG_CHA_HSYNC_PULSE_WIDTH_HIGH:
	case	SN65DSI84_REG_CHA_VSYNC_PULSE_WIDTH_LOW:
	case	SN65DSI84_REG_CHA_VSYNC_PULSE_WIDTH_HIGH:
	case	SN65DSI84_REG_CHA_HORIZONTAL_BACK_PORCH:
	case	SN65DSI84_REG_CHA_VERTICAL_BACK_PORCH:
	case	SN65DSI84_REG_CHA_HORIZONTAL_FRONT_PORCH:
	case	SN65DSI84_REG_CHA_VERTICAL_FRONT_PORCH:
	case	SN65DSI84_REG_CHA_TEST_PATTERN:
	case	SN65DSI84_REG_IRQ_EN:
	case	SN65DSI84_REG_ERR_EN:
	case	SN65DSI84_REG_DSI_PROTOCOL_ERR:
		return true;
	}

	return false;
}

static const struct regmap_config sn65dsi84_regmap_config = {
	.reg_bits = 8,
	.val_bits = 8,

	.max_register = 0xff,
	.cache_type = REGCACHE_RBTREE,
	.reg_defaults_raw = sn65dsi84_register_defaults,
	.num_reg_defaults_raw = ARRAY_SIZE(sn65dsi84_register_defaults),

	.volatile_reg = sn65dsi84_register_volatile,
};
/* -----------------------------------------------------------------------------
 * Retrieve videomode
 */

static bool sn65dsi84_videomode_parse_dt(struct device_node *np, struct sn65dsi84 *adv)
{
	

	u32 value;

	if(of_property_read_u32(np, "lvds,pixelclock", &value))  return false;
	adv->lvds_timing->pixelclock = value;

	/* Horizonatal parameters */
	if(of_property_read_u32(np, "lvds,hactive", &value)) return false;	
	adv->lvds_timing->hactive = value;
	if(of_property_read_u32(np, "lvds,hfront_porch", &value)) return false;
	adv->lvds_timing->hfront_porch = value;
	if(of_property_read_u32(np, "lvds,hback_porch", &value)) return false;
	adv->lvds_timing->hback_porch = value;
	if(of_property_read_u32(np, "lvds,hsync_len", &value)) return false;
	adv->lvds_timing->hsync_len = value;
	/* Vertical parameters */
	if(of_property_read_u32(np, "lvds,vactive", &value)) return false;
	adv->lvds_timing->vactive = value;
	if(of_property_read_u32(np, "lvds,vfront_porch", &value)) return false;
	adv->lvds_timing->vfront_porch = value;
	if(of_property_read_u32(np, "lvds,vback_porch", &value)) return false;
	adv->lvds_timing->vback_porch = value;
	if(of_property_read_u32(np, "lvds,vsync_len", &value)) return false;
	adv->lvds_timing->vsync_len = value;
	if(of_property_read_string(np, "lvds,color_depth", &(adv->lvds_color_depth))) return false;
	if(of_property_read_string(np, "lvds,datamap", &(adv->lvds_datamap))) return false;
	adv->lvds_dual_channel = of_property_read_bool(np, "lvds,dual-channel");
	adv->lvds_channel_reverse = of_property_read_bool(np, "lvds,channel-reverse");
	adv->lvds_channel_swap = of_property_read_bool(np, "lvds,channel-swap");
	adv->lvds_test_mode = of_property_read_bool(np, "lvds,test-mode");
	return true;
}


/* -----------------------------------------------------------------------------
 * Hardware configuration
 */

static void sn65dsi84_set_link_config(struct sn65dsi84 *sn65dsi84,
				    const struct sn65dsi84_link_config *config)
{

}

static void sn65dsi84_power_on(struct sn65dsi84 *sn65dsi84)
{

	if (sn65dsi84->gpio_pd)
                gpio_set_value(sn65dsi84->gpio_pd, 1);

        return;

}

static void sn65dsi84_power_off(struct sn65dsi84 *sn65dsi84)
{
	if (sn65dsi84->gpio_pd)
                gpio_set_value(sn65dsi84->gpio_pd, 0);

	return;
}

/* -----------------------------------------------------------------------------
 * ADV75xx helpers
 */

static int sn65dsi84_get_valid_edid(struct sn65dsi84 *adv, int *edid) 
{

	int hactive,vactive;
	char edid_dts[20];
	
	if(of_property_read_u32(adv->bridge.of_node, "lvds,hactive", &hactive)) return -EINVAL;
	if(of_property_read_u32(adv->bridge.of_node, "lvds,vactive", &vactive)) return -EINVAL;
	
	sprintf(edid_dts,"SN65DSI84_EDID_%dx%d",hactive,vactive);

	DRM_DEBUG("Searching for %s\n",edid_dts);
	
	for(*edid=0;*edid<sizeof(sn65dsi84_edid_id_list)/sizeof(sn65dsi84_edid_id_list[0]);(*edid)++ ) {
	
		if(!strcmp(edid_dts,sn65dsi84_edid_id_list[*edid]))
			return 0;

	}
	if((*edid) >= sizeof(sn65dsi84_edid_id_list)/sizeof(sn65dsi84_edid_id_list[0])) {
		DRM_ERROR("LVDS Resolution %dx%d not found\n",hactive,vactive);
		DRM_ERROR("Selecting default resolution %s",sn65dsi84_edid_id_list[0]);
		return -EINVAL;

	}

	return 0;	

}

static int sn65dsi84_get_modes(struct sn65dsi84 *sn65dsi84,
			     struct drm_connector *connector)
{
	unsigned int count,edid_id = SN65DSI84_EDID_800x600;
	u32 bus_format = MEDIA_BUS_FMT_RGB888_1X24;
	int ret;

	ret = sn65dsi84_get_valid_edid(sn65dsi84,&edid_id);
	if(ret < 0 ) {
		DRM_ERROR("No resolution found from dts!\n");
          	DRM_ERROR("Select default resolution %s\n",sn65dsi84_edid_id_list[SN65DSI84_EDID_800x600]);
		edid_id = SN65DSI84_EDID_800x600;
	}
		
	sn65dsi84->edid = (struct edid *) (sn65dsi84_edid_dsi_list[edid_id]);

	DRM_DEBUG("EDID sn65dsi84 is valid return = %d\n",drm_edid_header_is_valid((u8 *)(sn65dsi84->edid)));


	drm_mode_connector_update_edid_property(connector, (sn65dsi84->edid));
	count = drm_add_edid_modes(connector, (sn65dsi84->edid));

	connector->display_info.bus_flags = DRM_BUS_FLAG_DE_LOW |
					    DRM_BUS_FLAG_PIXDATA_NEGEDGE;

	ret = drm_display_info_set_bus_formats(&connector->display_info,
					       &bus_format, 1);
	if (ret)
                return ret;

//	drm_kms_helper_hotplug_event(sn65dsi84->connector.dev);

	return count;
}

static enum drm_connector_status
sn65dsi84_detect(struct sn65dsi84 *sn65dsi84, struct drm_connector *connector)
{
	enum drm_connector_status status;

	status = connector_status_connected;
	sn65dsi84->status = status;
	return connector_status_connected;
}

static int sn65dsi84_mode_valid(struct sn65dsi84 *sn65dsi84,
			      struct drm_display_mode *mode)
{
	DRM_DEBUG("sn65dsi84_mode_valid\n");
	if (mode->clock > 165000)
		return MODE_CLOCK_HIGH;

	return MODE_OK;
}

static void sn65dsi84_mipi_dsi_set(struct sn65dsi84 *adv, struct drm_display_mode *mode)
{
        struct mipi_dsi_device *dsi = adv->dsi;
        int lanes, ret;

        if (adv->num_dsi_lanes != 4)
                return;

        if (mode->clock > 80000)
                lanes = 4;
        else
                lanes = 3;

        if (lanes != dsi->lanes) {
                mipi_dsi_detach(dsi);
                dsi->lanes = lanes;
                ret = mipi_dsi_attach(dsi);
                if (ret)
                        dev_err(&dsi->dev, "failed to change host lanes\n");
        }
}

static int sn65dsi84_attach_dsi(struct sn65dsi84 *adv)
{
        struct device *dev = &adv->i2c_main->dev;
        struct mipi_dsi_host *host;
        struct mipi_dsi_device *dsi;
        int ret = 0;
        const struct mipi_dsi_device_info info = { .type = "sn65dsi84",
                                                   .channel = 0,
                                                   .node = NULL,
                                                 };

        host = of_find_mipi_dsi_host_by_node(adv->host_node);
        if (!host) {
                dev_err(dev, "failed to find dsi host\n");
                return -EPROBE_DEFER;
        }

        dsi = mipi_dsi_device_register_full(host, &info);
        if (IS_ERR(dsi)) {
                dev_err(dev, "failed to create dsi device\n");
                ret = PTR_ERR(dsi);
                goto err_dsi_device;
        }

        adv->dsi = dsi;

        dsi->lanes = adv->num_dsi_lanes;
        dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO |  MIPI_DSI_MODE_LPM | MIPI_DSI_MODE_VIDEO_SYNC_PULSE;
        ret = mipi_dsi_attach(dsi);
        if (ret < 0) {
                dev_err(dev, "failed to attach dsi to host\n");
                goto err_dsi_attach;
        }

        return 0;

err_dsi_attach:
        mipi_dsi_device_unregister(dsi);
err_dsi_device:
        return ret;
}

static void sn65dsi84_mode_set(struct sn65dsi84 *sn65dsi84,
			     struct drm_display_mode *mode,
			     struct drm_display_mode *adj_mode)
{
	struct device *dev = &sn65dsi84->i2c_main->dev;
	struct videomode *vmode = sn65dsi84->lvds_timing;
	u32 bporch,pix;
	DRM_INFO("LVDS sn65dsi84_mode_set IN\n");
	/* Retrieve mode from DTS */
	if (!(sn65dsi84->bridge.of_node)){
		DRM_INFO("LVDS sn65dsi84 no device node\n");
                return;
	}
	if(!sn65dsi84_videomode_parse_dt((sn65dsi84->bridge.of_node), sn65dsi84))
			dev_err(dev,"error parsing lvds timing!\n");	

	DRM_INFO("LVDS sn65dsi84_mode_set IN 2\n");
	bporch = vmode->hback_porch;
	pix = vmode->pixelclock;
	DRM_INFO("LVDS from DTS backporch=%u pixelclock=%u\n",bporch,pix);

	sn65dsi84_mipi_dsi_set(sn65dsi84, adj_mode);

	drm_mode_copy(&sn65dsi84->curr_mode, adj_mode);

	/*
	 * TODO Test first order 4:2:2 to 4:4:4 up conversion method, which is
	 * supposed to give better results.
	 */

	sn65dsi84->f_tmds = mode->clock;
}

/* Connector funcs */
static struct sn65dsi84 *connector_to_sn65dsi84(struct drm_connector *connector)
{
	return container_of(connector, struct sn65dsi84, connector);
}

static int sn65dsi84_connector_get_modes(struct drm_connector *connector)
{
	struct sn65dsi84 *adv = connector_to_sn65dsi84(connector);
	DRM_DEBUG("sn65dsi84_connector_get_modes\n");
	return sn65dsi84_get_modes(adv, connector);
}

static enum drm_mode_status
sn65dsi84_connector_mode_valid(struct drm_connector *connector,
			     struct drm_display_mode *mode)
{
	struct sn65dsi84 *adv = connector_to_sn65dsi84(connector);
	DRM_DEBUG("sn65dsi84_connector_mode_valid\n");
	return sn65dsi84_mode_valid(adv, mode);
}

static struct drm_connector_helper_funcs sn65dsi84_connector_helper_funcs = {
	.get_modes = sn65dsi84_connector_get_modes,
	.mode_valid = sn65dsi84_connector_mode_valid,
};

static enum drm_connector_status
sn65dsi84_connector_detect(struct drm_connector *connector, bool force)
{
	struct sn65dsi84 *adv = connector_to_sn65dsi84(connector);
	DRM_DEBUG("sn65dsi84_connector_detect\n");
	return sn65dsi84_detect(adv, connector);
}

static struct drm_connector_funcs sn65dsi84_connector_funcs = {
	//.dpms = drm_atomic_helper_connector_dpms,
	.fill_modes = drm_helper_probe_single_connector_modes,
	.detect = sn65dsi84_connector_detect,
	.destroy = drm_connector_cleanup,
	.reset = drm_atomic_helper_connector_reset,
	.atomic_duplicate_state = drm_atomic_helper_connector_duplicate_state,
	.atomic_destroy_state = drm_atomic_helper_connector_destroy_state,
};

/* Bridge funcs */
static struct sn65dsi84 *bridge_to_sn65dsi84(struct drm_bridge *bridge)
{
	return container_of(bridge, struct sn65dsi84, bridge);
}


static void sn65dsi84_calculate_clk_div_mul( u8 *clk_div_mul, unsigned int dsi_clk, unsigned int pixclk )
{
	int i;
	if(pixclk == 0) {
		DRM_INFO("sn65dsi84_calculate_clk_div_mul: pixclk is 0, can't divide by zero\n");
		return;
	}
	
	i = (dsi_clk) / ((pixclk));

	if( i != 0 && i <= 24 )
		*clk_div_mul = (i<<3);
	
	return;	
}

static void sn65dsi84_bridge_enable(struct drm_bridge *bridge)
{
	struct sn65dsi84 *adv = bridge_to_sn65dsi84(bridge);
	u8 val = 0;
	unsigned int dsi_clock = 450*1000*1000; /* DSI clock for 1920x1080 is 450MHz */

	DRM_INFO("sn65dsi84_bridge_enable configuring bridge\n");

	/* Enable the chip power */
	sn65dsi84_power_on(adv);
	/* PLL Enable - Stop PLL */
	regmap_write(adv->regmap, SN65DSI84_REG_PLL_EN, 0x0);
	if(!adv->ext_refclk) {

		if( adv->lvds_timing->pixelclock >= 37500*1000  && adv->lvds_timing->pixelclock < 62500*1000) val |= (0x01 << 1);
		else if( adv->lvds_timing->pixelclock >= 62500*1000 && adv->lvds_timing->pixelclock < 87500*1000 ) val |= (0x02 << 1);
		else if( adv->lvds_timing->pixelclock >= 87500*1000  && (adv->lvds_timing->pixelclock) < 112500*1000 ) val |= (0x03 << 1);
		else if( adv->lvds_timing->pixelclock >= 112500*1000 && (adv->lvds_timing->pixelclock) < 137500*1000 ) val |= (0x04 << 1);
		else val |= (0x05 << 1);
	
		/* LVDS pixel clock derived from MIPI D-PHY channel A HS continuous */
		val |= 0x1;	 	

		regmap_write(adv->regmap,SN65DSI84_REG_LVDS_CLK, val);

		val = 0;
		/* Calculate Multiplier and Divider for generate LVDS Clock from DSI Clock */
		sn65dsi84_calculate_clk_div_mul(&val,dsi_clock, adv->lvds_timing->pixelclock);

	} else
		val = 0x2;
	regmap_write(adv->regmap,SN65DSI84_REG_CLK_DIV_MUL, val);	
	
	/* Enable DSI Lanes */
	if(adv->num_dsi_lanes == 1) regmap_write(adv->regmap, SN65DSI84_REG_DSI_LANES, (0x1 << 5) | (0x3 << 3));
	if(adv->num_dsi_lanes == 2) regmap_write(adv->regmap, SN65DSI84_REG_DSI_LANES, (0x1 << 5) | (0x2 << 3));
	if(adv->num_dsi_lanes == 3) regmap_write(adv->regmap, SN65DSI84_REG_DSI_LANES, (0x1 << 5) | (0x1 << 3));
	if(adv->num_dsi_lanes == 4) regmap_write(adv->regmap, SN65DSI84_REG_DSI_LANES, (0x1 << 5) | (0x0 << 3));
		
	/* DSI equalization */
	regmap_write(adv->regmap,SN65DSI84_REG_DSI_EQ, 0x00);

	/* TODO: Find a way to catch the DSI clock frequency from 8M register */
	regmap_write(adv->regmap, SN65DSI84_REG_DSI_CLK_RANGE, (dsi_clock/(5*1000*1000)));
	
	val = 0;

	/* set LVDS for single channel, 24 bit mode, HS/VS low, DE high */
	
	if(!strcmp("rgb24",adv->lvds_color_depth))
		val |= 0x3 << 2;	
	else
		DRM_INFO("LVDS color depth RGB24\n");

	if(!strcmp("spwg",adv->lvds_datamap)) 
                val |= 0x3;
        else
                DRM_INFO("LVDS data mapping jeida\n");
	
	if(adv->lvds_dual_channel)
		val |= 0x0;
	else
		val |= (0x1 << 4);
	
	/* VS_NEG_POLARITY HS_NEG_POLARITY */
	val |= (0x3 << 5);
	
	regmap_write(adv->regmap, SN65DSI84_REG_LVDS_PARAMETER,val);

	/*Channel Swap and Reverse options */
	val = 0;
	if(adv->lvds_channel_reverse)
		val |= (0x3 << 4);		
	if(adv->lvds_channel_swap)   
                val |= (0x1 << 6);
	val |= 0x3; /* set termination to 200ohm (default) */
	regmap_write(adv->regmap, SN65DSI84_REG_LVDS_SWAP,val);

	/* X resolution high/low */
	regmap_write(adv->regmap, SN65DSI84_REG_CHA_ACTIVE_LINE_LENGTH_LOW, adv->lvds_timing->hactive & 0x00ff );
	regmap_write(adv->regmap, SN65DSI84_REG_CHA_ACTIVE_LINE_LENGTH_HIGH, (adv->lvds_timing->hactive & 0xff00 )>>8 );
	/* Y resolution high/low */
	regmap_write(adv->regmap, SN65DSI84_REG_CHA_VERTICAL_DISPLAY_SIZE_LOW, adv->lvds_timing->vactive & 0x00ff );
	regmap_write(adv->regmap, SN65DSI84_REG_CHA_VERTICAL_DISPLAY_SIZE_HIGH,(adv->lvds_timing->vactive & 0xff00 )>>8);

	/* SYNC delay high/low */
	regmap_write(adv->regmap, SN65DSI84_REG_CHA_SYNC_DELAY_LOW, 0x0);
	regmap_write(adv->regmap, SN65DSI84_REG_CHA_SYNC_DELAY_HIGH, 0x2);

	/* HSYNC VSYNC width high/low */
	regmap_write(adv->regmap, SN65DSI84_REG_CHA_HSYNC_PULSE_WIDTH_LOW,adv->lvds_timing->hsync_len & 0x00ff);
	regmap_write(adv->regmap, SN65DSI84_REG_CHA_HSYNC_PULSE_WIDTH_HIGH,(adv->lvds_timing->hsync_len & 0xff00)>>8);
	
	regmap_write(adv->regmap, SN65DSI84_REG_CHA_VSYNC_PULSE_WIDTH_LOW,adv->lvds_timing->vsync_len & 0x00ff);
	regmap_write(adv->regmap, SN65DSI84_REG_CHA_VSYNC_PULSE_WIDTH_HIGH, (adv->lvds_timing->vsync_len & 0xff00)>>8);	

		
	regmap_write(adv->regmap, SN65DSI84_REG_CHA_HORIZONTAL_BACK_PORCH, adv->lvds_timing->hback_porch);
	regmap_write(adv->regmap, SN65DSI84_REG_CHA_VERTICAL_BACK_PORCH, adv->lvds_timing->vback_porch);
	regmap_write(adv->regmap, SN65DSI84_REG_CHA_HORIZONTAL_FRONT_PORCH, adv->lvds_timing->hfront_porch);
	regmap_write(adv->regmap, SN65DSI84_REG_CHA_VERTICAL_FRONT_PORCH, adv->lvds_timing->vfront_porch);

	/* Test Mode */
	if(adv->lvds_test_mode)
		regmap_write(adv->regmap, SN65DSI84_REG_CHA_TEST_PATTERN,0x10);
	else
		regmap_write(adv->regmap, SN65DSI84_REG_CHA_TEST_PATTERN,0x0);

	/* Reset the controller */
	regmap_write(adv->regmap, SN65DSI84_REG_RESET, 0x1);
	/* PLL Enable - Start PLL */    
	regmap_write(adv->regmap, SN65DSI84_REG_PLL_EN, 0x1);
	
	return;
	
}

static void sn65dsi84_bridge_disable(struct drm_bridge *bridge)
{

	struct sn65dsi84 *adv = bridge_to_sn65dsi84(bridge);

	sn65dsi84_power_off(adv);

	return;
}

static void sn65dsi84_bridge_mode_set(struct drm_bridge *bridge,
				    struct drm_display_mode *mode,
				    struct drm_display_mode *adj_mode)
{
	struct sn65dsi84 *adv = bridge_to_sn65dsi84(bridge);
	DRM_INFO("sn65dsi84_bridge_mode_set\n");
	sn65dsi84_mode_set(adv, mode, adj_mode);
}

static int sn65dsi84_bridge_attach(struct drm_bridge *bridge)
{
	struct sn65dsi84 *adv = bridge_to_sn65dsi84(bridge);
	int ret;
	DRM_INFO("sn65dsi84_bridge_attach\n");
	if (!bridge->encoder) {
		DRM_ERROR("Parent encoder object not found");
		return -ENODEV;
	}

	adv->connector.polled = DRM_CONNECTOR_POLL_HPD;

	ret = drm_connector_init(bridge->dev, &adv->connector,
				 &sn65dsi84_connector_funcs,
				 DRM_MODE_CONNECTOR_HDMIA);
	if (ret) {
		DRM_ERROR("Failed to initialize connector with drm\n");
		return ret;
	}
	drm_connector_helper_add(&adv->connector,
				 &sn65dsi84_connector_helper_funcs);
	drm_mode_connector_attach_encoder(&adv->connector, bridge->encoder);

	ret = sn65dsi84_attach_dsi(adv);

	return ret;
}

static struct drm_bridge_funcs sn65dsi84_bridge_funcs = {
	.enable = sn65dsi84_bridge_enable,
	.disable = sn65dsi84_bridge_disable,
	.mode_set = sn65dsi84_bridge_mode_set,
	.attach = sn65dsi84_bridge_attach,
};

/* -----------------------------------------------------------------------------
 * Probe & remove
 */

int sn65dsi84_parse_dt(struct device_node *np, struct sn65dsi84 *adv)
{
        u32 num_lanes;
        struct device_node *endpoint;
	int ret;

        of_property_read_u32(np, "adi,dsi-lanes", &num_lanes);

        if (num_lanes < 1 || num_lanes > 4)
                return -EINVAL;

        adv->num_dsi_lanes = num_lanes;

	adv->gpio_pd = of_get_named_gpio(np, "pd", 0); 
     	if (!gpio_is_valid(adv->gpio_pd))
             DRM_INFO("No valid Power Gpio Found\n");
	else {
		ret = gpio_request(adv->gpio_pd, "sn65dsi84_pwr");  
     			if (ret < 0)           
             			return -EINVAL;
		ret = gpio_direction_output(adv->gpio_pd, 0);
                        if (ret < 0)
                                return -EINVAL;
     	} 

        endpoint = of_graph_get_next_endpoint(np, NULL);
        if (!endpoint)
                return -ENODEV;

        adv->host_node = of_graph_get_remote_port_parent(endpoint);
        if (!adv->host_node) {
                of_node_put(endpoint);
                return -ENODEV;
        }

        of_node_put(endpoint);
        of_node_put(adv->host_node);

        adv->use_timing_gen = !of_property_read_bool(np,
                                                "adi,disable-timing-generator");

        /* TODO: Check if these need to be parsed by DT or not */
        adv->rgb = true;
        adv->embedded_sync = false;
	
	adv->ext_refclk = of_property_read_bool(np,"ext-refclk");

        return 0;
}


static int sn65dsi84_probe(struct i2c_client *i2c, const struct i2c_device_id *id)
{
	struct sn65dsi84_link_config link_config;
	struct sn65dsi84 *sn65dsi84;
	struct videomode *vmode;
	struct device *dev = &i2c->dev;
	unsigned int val;
	int ret;

	if (!dev->of_node)
		return -EINVAL;

	sn65dsi84 = devm_kzalloc(dev, sizeof(*sn65dsi84), GFP_KERNEL);
	if (!sn65dsi84)
		return -ENOMEM;

	vmode = devm_kzalloc(dev, sizeof(*vmode), GFP_KERNEL);
        if (!vmode)
                return -ENOMEM;

	sn65dsi84->powered = false;
	sn65dsi84->status = connector_status_disconnected;

//	if (dev->of_node)
//		sn65dsi84->type = (enum sn65dsi84_type)of_device_get_match_data(dev);
//	else
//		sn65dsi84->type = id->driver_data;

	memset(&link_config, 0, sizeof(link_config));

	ret = sn65dsi84_parse_dt(dev->of_node, sn65dsi84);
	if (ret) {
		dev_info(dev,"error parsing DT\n");
		return ret;
	}

	/*
	 * The power down GPIO is optional. If present, toggle it from active to
	 * inactive to wake up the encoder.
	 */
	
	sn65dsi84_power_on(sn65dsi84);

	sn65dsi84->regmap = devm_regmap_init_i2c(i2c, &sn65dsi84_regmap_config);
	if (IS_ERR(sn65dsi84->regmap))
		return PTR_ERR(sn65dsi84->regmap);

	ret = regmap_read(sn65dsi84->regmap, SN65DSI84_REG_DSI_PROTOCOL_ERR, &val);
	if (ret) {
		dev_info(dev, "physical bridge not found\n");
		return -ENODEV;
	}
	if (val)
		dev_info(dev, "physical bridge found\n");
	else
		return -ENODEV;
	
	sn65dsi84_power_off(sn65dsi84);

	i2c_set_clientdata(i2c, sn65dsi84);

	sn65dsi84_set_link_config(sn65dsi84, &link_config);

	sn65dsi84->bridge.funcs = &sn65dsi84_bridge_funcs;
	sn65dsi84->bridge.of_node = dev->of_node;
	sn65dsi84->lvds_timing = vmode;

	ret = drm_bridge_add(&sn65dsi84->bridge);
	if (ret) {
		dev_err(dev, "failed to add sn65dsi84 bridge\n");
		goto err_i2c_unregister_edid;
	}

	return 0;

err_i2c_unregister_edid:
	return ret;
}

static int sn65dsi84_remove(struct i2c_client *i2c)
{
	struct sn65dsi84 *sn65dsi84 = i2c_get_clientdata(i2c);


	drm_bridge_remove(&sn65dsi84->bridge);

	i2c_unregister_device(sn65dsi84->i2c_edid);

	kfree(sn65dsi84->edid);

	return 0;
}

static const struct i2c_device_id sn65dsi84_i2c_ids[] = {
	{ "sn65dsi84", SN65DSI84 },
	{ }
};
MODULE_DEVICE_TABLE(i2c, sn65dsi84_i2c_ids);

static const struct of_device_id sn65dsi84_of_ids[] = {
	{ .compatible = "ti,sn65dsi84", .data = (void *)SN65DSI84 },
	{ }
};
MODULE_DEVICE_TABLE(of, sn65dsi84_of_ids);

static struct mipi_dsi_driver adv7533_dsi_driver = {
	.driver.name = "sn65dsi84",
};

static struct i2c_driver sn65dsi84_driver = {
	.driver = {
		.name = "sn65dsi84",
		.of_match_table = sn65dsi84_of_ids,
	},
	.id_table = sn65dsi84_i2c_ids,
	.probe = sn65dsi84_probe,
	.remove = sn65dsi84_remove,
};

static int __init sn65dsi84_init(void)
{
	if (IS_ENABLED(CONFIG_DRM_MIPI_DSI))
		mipi_dsi_driver_register(&adv7533_dsi_driver);

	return i2c_add_driver(&sn65dsi84_driver);
}
module_init(sn65dsi84_init);

static void __exit sn65dsi84_exit(void)
{
	i2c_del_driver(&sn65dsi84_driver);

	if (IS_ENABLED(CONFIG_DRM_MIPI_DSI))
		mipi_dsi_driver_unregister(&adv7533_dsi_driver);
}
module_exit(sn65dsi84_exit);

MODULE_AUTHOR("Marco Sandrelli <marco.sandrelli@seco.com>");
MODULE_DESCRIPTION("SN65DSI84 LVDS transmitter driver");
MODULE_LICENSE("GPL");

