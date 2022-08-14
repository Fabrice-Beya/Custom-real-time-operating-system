#include "uart.h"

void enable_pins_clock_access();
void enable_uart_clock_access();

void configure_pins();
void configure_uart();

static uint16_t compute_baud_rate(uint32_t peripheral_clock, uint32_t baudrate);
static void configure_uart_baudrate(uint32_t peripheral_clock, uint32_t baudrate);

void write(int character);

void uart_init()
{
	enable_pins_clock_access();
	enable_uart_clock_access();

	configure_pins();
	configure_uart();
}

__io_putchar(int ch)
{
	write(ch);
	return ch;
}

void write(int character)
{
//	Ensure the transmit data register is empty: check the status register
	while(!(USART2->SR & UART_TX_EMPTY)){}

//	Write data to transmit data register. Ensure that only 8 bits is transmitted.
	USART2->DR = (character & 0xFF);
}

void enable_pins_clock_access()
{
//	Enable clock access to PART A set bit 1 RCC_AHB1 clock enable register
	RCC->AHB1ENR |= GPIOA_CLOCK_EN;
}

void enable_uart_clock_access()
{
//	Enable clock access to uart 2 set bit 17 of RCC_APB1 clock enable register
	RCC->APB1ENR |= UART2_CLOCK_EN;
}

void configure_pins()
{
//	Set Port A2 and A3 to alternative function mode 10
	GPIOA->MODER |= UART2_TX_MODER_0;
	GPIOA->MODER &= ~UART2_TX_MODER_1;

//	Set the alternative function type for PA2 and PA3 to AF7(uart2 tx and rx) 0111
	GPIOA->AFR[0] &= ~UART2_TX_AF_0;
	GPIOA->AFR[0] |= UART2_TX_AF_1;
	GPIOA->AFR[0] |= UART2_TX_AF_2;
	GPIOA->AFR[0] |= UART2_TX_AF_3;

	GPIOA->AFR[0] &= ~UART2_RX_AF_0;
	GPIOA->AFR[0] |= UART2_RX_AF_1;
	GPIOA->AFR[0] |= UART2_RX_AF_2;
	GPIOA->AFR[0] |= UART2_RX_AF_3;
}

void configure_uart()
{

//	Configure the baud rate
	configure_uart_baudrate(APB1_CLOCK, UART_BAUDRATE);

//	Enable both transmission and reception on UART2 disable all other functions
	USART2->CR1 = UART2_TX_EN && UART2_RX_EN;

//	Enable the uart module
	USART2->CR1 |= UART2_EN;
}

static void configure_uart_baudrate(uint32_t peripheral_clock, uint32_t baudrate)
{
	USART2->BRR = compute_baud_rate(peripheral_clock, baudrate);
}

static uint16_t compute_baud_rate(uint32_t peripheral_clock, uint32_t baudrate)
{
	return ((peripheral_clock + (baudrate / 2)) / baudrate);
}


