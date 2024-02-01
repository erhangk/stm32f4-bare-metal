#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "uart.h"
#include "SysTick.h"
#include "onboard_led.h"

int main(void)
{
	LedInit();
	UART_Init();
	SysTickInit(SystemCoreClock/1000);

	while(1)
	{
        println("Hello World!");
		//uart_tx(uart_rx());
        ToggleLed(AllLeds);
        delay_ms(1000);
	}
}
