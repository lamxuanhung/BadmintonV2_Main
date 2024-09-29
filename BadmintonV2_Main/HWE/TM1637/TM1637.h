/*
 * TM1637.h
 *
 *  Created on: Jul 27, 2019
 *      Author: XuanHung
 */

#ifndef TM1637_H_
#define TM1637_H_

#include "stm32f0xx_hal.h"

#define TM1367_CLK_PORT		GPIOA
#define TM1367_CLK_PIN		GPIO_PIN_1

#define TM1367_DATA_PORT	GPIOA
#define TM1367_DATA_PIN		GPIO_PIN_2

#define TM1637_DELTA_T	10

#define TM1637_LED_SEGMENT	5
#define TM1637_KEY_SEGMENT	1
typedef struct
{
	uint8_t Brightness;
	uint8_t DataBuffer[TM1637_LED_SEGMENT+TM1637_KEY_SEGMENT];
}TM1637_Control_Block_t;


void TM1637_SetBrightness(uint8_t brightness, uint8_t on);
void TM1637_Display();
void TM1637_Clear();
void TM1637_Ini();
void TM1637_Proc();

extern TM1637_Control_Block_t TM1637;
#endif /* TM1637_H_ */
