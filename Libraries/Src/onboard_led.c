/*
 * onboard_led.c
 *
 *  Created on: Jan 31, 2024
 *      Author: erhangok
 */

#include "onboard_led.h"

/*
 * LD3 -> PD13
 * LD4 -> PD12
 * LD5 -> PD14
 * LD6 -> PD15
*/
void LedInit(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

	GPIOD->MODER &= ~(GPIO_MODER_MODE12|
					  GPIO_MODER_MODE13|
					  GPIO_MODER_MODE14|
					  GPIO_MODER_MODE15);

	GPIOD->MODER |= GPIO_MODER_MODE12_0|
					GPIO_MODER_MODE13_0|
					GPIO_MODER_MODE14_0|
					GPIO_MODER_MODE15_0;


}

void DisableLed(uint16_t LD)
{
	GPIOD->ODR &= ~LD;
}

void EnableLed(uint16_t LD)
{
	GPIOD->ODR |= LD;
}
void ToggleLed(uint16_t LD)
{
	GPIOD->ODR ^= LD;
}
