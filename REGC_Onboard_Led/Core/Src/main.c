#include "stm32f4xx.h"
#include "onboard_led.h"

int main()
{
	LedInit();
	EnableLed(LD3);
	EnableLed(LD4);
	EnableLed(LD5);
	EnableLed(LD6);
	while(1)
	{
	}
	return 0;
}
