/*
 *
 *	@file main.c
 *	@author Lucas Gabriel Cardoso
 *	@brief Example of two core
 *	@version 0.1
 *	@date 2022-10-03
 *
 *	@copyrigh CopyRigh (c) 2022
 *
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/adc.h"

//Core 1
void core1_entry(void)
{
	while(true)
	{
		
	}
}

//Core 0
int main(void)
{
	stdio_init_all();
	multicore_lauch_core1(core1_entry);	//initialize core 1
	
	adc_init();
	
	adc_gpio_init(26);
	adc_select_input(0);

	adc_set_temp_sensor_enabled(true);
	adc_select_input(4);
	
	gpio_init(0);
	gpio_set_dir(0, false);
	gpio_pull_up(0);

	gpio_ini(1);
	gpio_set_dir(1, false);
	gpio_pull_up(1);

	gpio_init(2);
	gpio_set_dir(2, false);
	gpio_pull_up(2);

	gpio_init(3);
	gpio_set_dir(3, false);
	gpio_pull_up(3);

	gpio_init(4);
	gpio_set_dir(4, false);
	gpio_pull_up(4);
	
	

	while(1)
	{
		
	}
}
