#ifndef __LED_H__
#define __LED_H__

#include "stm32f4xx.h"

 /* PORT D is configured on bit 3 of RCC AHB1 register
  * 0000 0000 0000 0000 | 0000 0000 000 1000
 */
#define GPIOD_EN (1U << 3)

#define LED_3_PIN (1U << 13)
#define LED_4_PIN (1U << 12)
#define LED_5_PIN (1U << 14)
#define LED_6_PIN (1U << 15)

#define LED_3_MODER_1 (1U << 27)
#define LED_4_MODER_1 (1U << 25)
#define LED_5_MODER_1 (1U << 29)
#define LED_6_MODER_1 (1U << 31)

#define LED_3_MODER_2 (LED_3_MODER_1 >> 1)
#define LED_4_MODER_2 (LED_4_MODER_1 >> 1)
#define LED_5_MODER_2 (LED_5_MODER_1 >> 1)
#define LED_6_MODER_2 (LED_6_MODER_1 >> 1)

typedef struct
{
	__IO uint32_t PIN;
	__IO uint32_t MODER_1;
	__IO uint32_t MODER_2;
} LED_Typedef;

typedef enum {
	LED_3,
	LED_4,
	LED_5,
	LED_6
} LED;


LED_Typedef* led_init(LED led);
void led_on(LED_Typedef* led);
void led_off(LED_Typedef* led);

#endif
