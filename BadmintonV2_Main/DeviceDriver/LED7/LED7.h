/*
 * LED7.h
 *
 *  Created on: Aug 11, 2019
 *      Author: XuanHung
 */

#ifndef LED7_H_
#define LED7_H_

#include "TM1637.h"

typedef struct
{
	uint8_t NumSegment;
	uint8_t* DefSegment;
	TM1637_Control_Block_t* TM1637_cs;
}LED7_Desc_Block_t;

void LED7_Ini();
void LED7_Display(uint16_t number);
void LED7_DisplaySpeed(uint8_t speed);
#endif /* LED7_H_ */
