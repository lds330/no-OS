#include <common.h>
#include <sys/platform.h>
#include <drivers/pwr/adi_pwr.h>
#include "adi_initialize.h"
#include "wifi.h"
#include "error.h"
#include "uart.h"
#include "uart_extra.h"

void at_test();

void initPower()
{
	if (ADI_PWR_SUCCESS != adi_pwr_Init())
		goto error;

	if (ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_HCLK, 1u))
		goto error;

	if (ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_PCLK, 1u))
		goto error;

	return;
error:
	printf("ERROR INITIALIZING POWER\n");
	exit(1);
}

int main(int argc, char *argv[])
{
	/**
	 * Initialize managed drivers and/or services that have been added to
	 * the project.
	 * @return zero on success
	 */
	adi_initComponents();
	initPower();

	at_test();

	return 0;
}

