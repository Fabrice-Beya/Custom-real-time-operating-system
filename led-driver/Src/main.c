#include "led.h"

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

int main(void)
{
	LED_Typedef* orange = led_init(LED_3);
	LED_Typedef* green = led_init(LED_4);
	LED_Typedef* red = led_init(LED_5);
	LED_Typedef* blue = led_init(LED_6);

	while(1)
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
}
