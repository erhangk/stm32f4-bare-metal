/*
 * SysTick.c
 *
 *  Created on: Jan 31, 2024
 *      Author: erhangok
 */

#include "SysTick.h"

void SysTickInit(uint32_t s) {
    SysTick->LOAD = (uint32_t)(s-1);
    SysTick->VAL = 0;                           // Reset SysTick
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;  // SysTick Enable Interrupt
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk; // SysTick clock source = AHB
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;   // Enable SysTick

    NVIC_EnableIRQ(SysTick_IRQn);
    NVIC_SetPriority(SysTick_IRQn, 0);
}

void delay_ms(uint32_t delay) {
    millis = 0;
    while (millis < delay) {
        // Wait for the specified duration
    }
}

void SysTick_Handler(void) {
    millis++; // Increment millis value
}
