#include <stdio.h>
#include <pico/stdlib.h>

int main()
{
	stdio_init_all();
	
	while(true)
	{
		printf("Hello world\n\Rapibarry PI PICO ;)");
		sleep_ms(1000);
	}
}
