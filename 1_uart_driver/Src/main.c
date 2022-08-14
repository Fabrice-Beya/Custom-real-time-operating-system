#include "led.h"
#include "uart.h"

LED_Typedef* orange;
LED_Typedef* green;
LED_Typedef* red;
LED_Typedef* blue;

void delay(uint32_t val)
{
	for(int i = 0; i < val; i++)
	{

	}
}

void short_delay()
{
	delay(1000000);
}

void long_delay()
{
	delay(5000000);
}

void init_leds()
{
	orange = led_init(LED_3);
	green = led_init(LED_4);
	red = led_init(LED_5);
	blue = led_init(LED_6);
}

void cycle_leds()
{
	led_on(orange);
	short_delay();
	led_on(green);
	short_delay();
	led_on(red);
	short_delay();
	led_on(blue);

	long_delay();

	led_off(orange);
	short_delay();
	led_off(green);
	short_delay();
	led_off(red);
	short_delay();
	led_off(blue);
	short_delay();
}

int main(void)
{
	uart_init();

	while(1)
	{
		printf("Hello from the world of bits.....\n\r");
		long_delay();
	}
}
