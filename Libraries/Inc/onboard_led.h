/*
 * onboard_led.h
 *
 *  Created on: Jan 31, 2024
 *      Author: erhangok
 */

#ifndef ONBOARD_LED_H_
#define ONBOARD_LED_H_


#include "stm32f4xx.h"

#define LD3 GPIO_ODR_OD13 //PD13
#define LD4 GPIO_ODR_OD12 //PD12
#define LD5 GPIO_ODR_OD14 //PD14
#define LD6 GPIO_ODR_OD15 //PD15
#define LD_Green LD4
#define LD_Orange LD3
#define LD_Red LD5
#define LD_Blue LD6

#define AllLeds LD3|LD4|LD5|LD6 //Single mask for all onboard leds

void LedInit(void);
void ToggleLed(uint16_t LD);
void EnableLed(uint16_t LD);
void DisableLed(uint16_t LD);

#endif /* ONBOARD_LED_H_ */
