/*
 * TM1637.h
 *
 *  Created on: Jul 27, 2019
 *      Author: XuanHung
 */

#ifndef TM1637_H_
#define TM1637_H_

#include "MCU.h"

#define TM1637_DELTA_T	10
#define TM1637_MAX_LEDSEGMENT	6
#define TM1637_MAX_KEYSEGMENT	2

typedef struct
{
	GPIO_TypeDef* ClockPort;
	uint16_t ClockPin;
	GPIO_TypeDef* DataPort;
	uint16_t DataPin;
	uint8_t Brightness;
	uint8_t ShowDot;
	uint8_t LedSegment[TM1637_MAX_LEDSEGMENT];
	uint8_t KeySegment;
}TM1637_Control_Block_t;


void TM1637_SetBrightness(TM1637_Control_Block_t* p_cb,uint8_t brightness, uint8_t on);
void TM1637_Display(TM1637_Control_Block_t* p_cb,uint8_t PosDigit,uint8_t NumDigit);
void TM1637_Clear(TM1637_Control_Block_t* p_cb);
void TM1637_Ini(TM1637_Control_Block_t* p_cb);
#endif /* TM1637_H_ */
