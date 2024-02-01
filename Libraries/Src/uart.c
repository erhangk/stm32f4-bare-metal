/*
 * uart.c
 *
 *   Created on: Jan 31, 2024
 *   Author: erhangok
 *   UART functions uses USART2 PA2/PA3 pins to transmit data
 *   connect a Serial to USB adapter to see the data on PC
 *
 * setup:
 *   1. enable usart clock from RCC
 *   2. enable gpioa clock
 *   3. set PA2 and PA3 as af7
 *   4. set uart word length and parity
 *   5. enable transmit and receive (TE/RE bits)
 *   6. calculate baud rate and set BRR
 *   7. enable uart
 */

#include "uart.h"

void UART_Init()
{
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER &= ~(GPIO_MODER_MODE2_Msk|
					  GPIO_MODER_MODE3_Msk);
	GPIOA->MODER |= GPIO_MODER_MODE2_1|
					GPIO_MODER_MODE3_1;

    GPIOA->AFR[0] |= (0x7 << GPIO_AFRL_AFSEL2_Pos); // for pin A2
    GPIOA->AFR[0] |= (0x7 << GPIO_AFRL_AFSEL3_Pos); // for pin A3

    GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR2_1|
    				  GPIO_OSPEEDER_OSPEEDR3_1;

    USART2->CR1 &= ~USART_CR1_M;   //1 Start bit, 8 Data bits
    USART2->CR1 &= ~USART_CR1_PCE; //No parity control
    USART2->CR1 |= USART_CR1_TE;   //Transmitter enable
    USART2->CR1 |= USART_CR1_RE;   //Receiver enable

    // baud rate = fCK / (8 * (2 - OVER8) * USARTDIV)
    //   for fCK = 16 Mhz, baud = 115200, OVER8 = 0
    //   USARTDIV = 16Mhz / (115200 * 16) ~= 8.6875
    //   we can also look at the table in RM0090 TABLE 138.
    //   for 16 Mhz PCLK, OVER8 = 0 and 115.2 KBps baud
    //   we need to program 8.6875
    // Fraction : 16*0.6875 = 10 (multiply fraction with 16)
    // Mantissa : 8
    // 12-bit mantissa and 4-bit fraction

    USART2->BRR |= 8<<4;
    USART2->BRR |= 10;


    USART2->CR1 |= USART_CR1_UE; //USART Enable
}

void printChar(uint8_t c)
{
	USART2->DR = c;
	while(!(USART2->SR & USART_SR_TC));
}

int _print(int f,char *ptr, int len)
{
	(void)f;
	for(int i=0; i<len; i++)
	{
		printChar(ptr[i]);
	}
	return len; // return length
}


void print(char *s)
{
	// count number of characters in s string until a null byte comes `\0`
	int length = 0;
	while(s[length]!='\0')
	{
		length++;
	}
	_print(0, s, length);
}

void println(char *s)
{
	print(s);
	print("\n\r");
}

void uart_tx(uint8_t c)
{
	printChar(c);
}

uint32_t uart_rx(void)
{
	while(!(USART2->SR & USART_SR_RXNE));
	return USART2->DR;
}
