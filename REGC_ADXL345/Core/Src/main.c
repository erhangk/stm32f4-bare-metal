#include "system_stm32f4xx_clk.h"
#include "uart.h"
#include "i2c.h"
#include "onboard_led.h"

// these should go to cs43l22 related headers
#define CS43L22_ADDRESS 0x94U
#define CS43L22_REG_ID  0x01
#define CS43L22_CHIP_ID 0x1C // first 5 bits of reg

volatile uint8_t DeviceAddr = CS43L22_ADDRESS;

int main()
{
	UART_Init();
	I2C_Init();
	LedInit();
	set_sysclk_to_168();

    //*******************************
    // setup reset pin for CS43L22 - GPIOD 4
    //*******************************
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    GPIOD->MODER &= ~GPIO_MODER_MODE4;
    GPIOD->MODER |= GPIO_MODER_MODE4_0;

    // activate CS43L22
    GPIOD->ODR |= GPIO_ODR_OD4;

    // read Chip ID - first 5 bits of CHIP_ID_ADDR
    uint8_t ret = i2c_read(CS43L22_REG_ID, DeviceAddr);

    if ((ret >> 3) != CS43L22_CHIP_ID) {
        EnableLed(LD_Orange); // orange led on error
    }

	while(1)
	{
        EnableLed(LD_Green); // green led on completetion
	}
	return 0;
}

void I2C1_ER_IRQHandler(){
    // error handler
    EnableLed(LD_Red);
}




