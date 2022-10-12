/*
 *
 *	@file watchdogdemo.c
 *	@author Daniel Quadros
 *	@brief Example of using the watchdog
 *	@version 0.1
 *	@date 2022-07-14
 *
 *	@copyright Copyright (c) 2022, Daniel Quadros 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/watchdog.h"

int main()
{
	//Init stdio
	stdio_init_all();
	while(!stdio_usb_connected())
	{
		sleep_ms(100);
	}	
	
	printf("Watchdog Example\n\n");
	if(watchdog_caused_reboot())
	{
		printf("Rebooted by Watchdog!\n");
		sleep_ms(500);
	}
	else
	{
		printf("Clear boot \n");
	}

	//Enable the watchdog with a 100 ms timeout
	watchdog_enable(100, false);

	//Lets play watchdog roulet!
	while(true)
	{
		printf(".");
		sleep_ms(rand() % 101);	//0 to 100 ms
		watchdog_update();
	}

	return 0;
}
