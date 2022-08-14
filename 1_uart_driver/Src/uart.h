#ifndef __UART_H__
#define __UART_H__

#include "stm32f4xx.h"
#include <stdio.h>
#include <stdint.h>

#define GPIOA_CLOCK_EN 				(1U)
#define UART2_CLOCK_EN 				(1U << 17)

#define UART2_TX_PIN 				(1U << 2)
#define UART2_RX_PIN 				(1U << 3)

#define UART2_TX_MODER_0 			(1U << 5)
#define UART2_TX_MODER_1 			(UART2_TX_MODER_0 >> 1)

#define UART2_RX_MODER_0 			(1U << 7)
#define UART2_RX_MODER_1 			(UART2_RX_MODER_0 >> 1)

#define UART2_TX_AF_0 				(1U << 11)
#define UART2_TX_AF_1 				(UART2_TX_AF_0 >> 1)
#define UART2_TX_AF_2 				(UART2_TX_AF_0 >> 2)
#define UART2_TX_AF_3 				(UART2_TX_AF_0 >> 3)

#define UART2_RX_AF_0 				(1U << 15)
#define UART2_RX_AF_1 				(UART2_RX_AF_0 >> 1)
#define UART2_RX_AF_2 				(UART2_RX_AF_0 >> 2)
#define UART2_RX_AF_3 				(UART2_RX_AF_0 >> 3)

#define SYS_FREQ					16000000
#define APB1_CLOCK					SYS_FREQ
#define	UART_BAUDRATE				115200

#define UART2_TX_EN					(1U << 3)
#define UART2_RX_EN					(1U << 2)
#define UART2_EN					(1U << 13)

#define UART_TX_EMPTY				(1U << 7)

void write(int character);
void uart_init();

#endif
