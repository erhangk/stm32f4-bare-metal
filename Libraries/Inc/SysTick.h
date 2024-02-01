/*
 * SysTick.h
 *
 *  Created on: Jan 31, 2024
 *      Author: erhangok
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "stm32f4xx.h"

static volatile uint32_t millis;

void SysTickInit(uint32_t s);
void delay_ms(uint32_t delay);
void SysTick_Handler(void);

#endif /* SYSTICK_H_ */
