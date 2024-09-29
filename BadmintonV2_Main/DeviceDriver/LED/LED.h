/*
 * LED.h
 *
 *  Created on: Aug 11, 2019
 *      Author: XuanHung
 */

#ifndef LED_H_
#define LED_H_

#include "TM1637.h"

#define LED_1_POS	0x01
#define LED_2_POS	0x02
#define LED_3_POS	0x04
#define LED_4_POS	0x08
#define LED_5_POS	0x10
#define LED_6_POS	0x20
#define LED_7_POS	0x40
#define LED_8_POS	0x80

typedef struct
{
	uint8_t LedPos;
	TM1637_Control_Block_t* TM1637_cs;
}LED_Desc_Block_t;

void LED_Ini();
void LED_Display(uint8_t ledPos);

#endif /* LED_H_ */
