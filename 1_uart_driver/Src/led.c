#include "led.h"

/*
 * Set up the led pin as output
 */
void configure_mode(const LED_Typedef* led)
{
//	Configure the led pin of port D for output by setting bits of GPIOD Moder registers to 01
	GPIOD->MODER &= ~led->MODER_1;
	GPIOD->MODER |= led->MODER_2;
}

/*
 * Configure led pin and mode for output
*/
LED_Typedef* led_init(LED led)
{
//	Enable clock access to port D setting bit 3 of RCC_AHB1ENR register
	RCC->AHB1ENR |= GPIOD_EN;

	LED_Typedef* led_config = malloc(sizeof(led_config));;

	if(led == LED_3){
		led_config->PIN = LED_3_PIN;
		led_config->MODER_1 = LED_3_MODER_1;
		led_config->MODER_2 = LED_3_MODER_2;
		configure_mode(led_config);
	}
	else if(led == LED_4){
		led_config->PIN = LED_4_PIN;
		led_config->MODER_1 = LED_4_MODER_1;
		led_config->MODER_2 = LED_4_MODER_2;
		configure_mode(led_config);
	}
	else if(led == LED_5){
		led_config->PIN = LED_5_PIN;
		led_config->MODER_1 = LED_5_MODER_1;
		led_config->MODER_2 = LED_5_MODER_2;
		configure_mode(led_config);
	}
	else if(led == LED_6){
		led_config->PIN = LED_6_PIN;
		led_config->MODER_1 = LED_6_MODER_1;
		led_config->MODER_2 = LED_6_MODER_2;
		configure_mode(led_config);
	}

	return led_config;
}

/*
 * Turn LED on by setting PD13 to true
*/

void led_on(LED_Typedef* led)
{
// 	Turn on led by setting led pin of GPIOD ODR(output data register) to true
	GPIOD->ODR |= led->PIN;
}

/*
 * Turn LED off by setting PD13 to false
*/

void led_off(LED_Typedef* led)
{
	// 	Turn off led by setting led pin of GPIOD ODR(output data register) to false
		GPIOD->ODR &= ~led->PIN;
}
