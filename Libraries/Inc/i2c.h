/*
 * i2c.h
 *
 *  Created on: Jan 30, 2024
 *      Author: erhangok
 */

#ifndef I2C_H_
#define I2C_H_


#include "stm32f4xx.h"

void I2C_GPIO_Init(void);
void I2C_Init(void);
uint8_t i2c_read(uint8_t regaddr, uint8_t DeviceAddr);
void i2c_write(uint8_t regaddr, uint8_t data, uint8_t DeviceAddr);
void __i2c_start();
void __i2c_stop();

#endif /* I2C_H_ */
