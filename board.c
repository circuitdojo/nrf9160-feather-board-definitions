/*
 * Copyright (c) 2020 Circuit Dojo LLC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <init.h>
#include <drivers/gpio.h>

#define GPIO0 DT_GPIO_P0_DEV_NAME
#define POWER_LATCH_PIN 31

static int board_circuitdojo_feather_nrf9160_init(struct device *dev)
{
	ARG_UNUSED(dev);

	/* Get the device binding */
	struct device *gpio = device_get_binding(GPIO0);
	if (gpio == NULL) {
		return -ENODEV;
	}

	/* Configure latch pin as output. */
	gpio_pin_configure(gpio, POWER_LATCH_PIN, GPIO_DIR_OUT);
	gpio_pin_write(gpio, POWER_LATCH_PIN, 1);

	return 0;
}

/* needs to be done after GPIO driver init */
SYS_INIT(board_circuitdojo_feather_nrf9160_init, POST_KERNEL,
	 CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
