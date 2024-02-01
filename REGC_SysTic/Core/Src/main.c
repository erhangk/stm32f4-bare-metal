#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "SysTick.h"
#include "onboard_led.h"

int main()
{

    // generate a tick every clock_speed/1000 cycles,
    // we can generate, a 1 ms tick speed.
	SysTickInit(SystemCoreClock/1000);
	LedInit();

	while(1)
	{
		ToggleLed(LD4);
		delay_ms(500);
		ToggleLed(LD3);
		delay_ms(500);
		ToggleLed(LD5);
		delay_ms(500);
		ToggleLed(LD6);
		delay_ms(500);
	}
	return 0;
}
