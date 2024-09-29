/*
 * LED.c
 *
 *  Created on: Aug 11, 2019
 *      Author: XuanHung
 */

#include "LED.h"


LED_Desc_Block_t LED_Desc_cs;

void LED_Ini()
{
	LED_Desc_cs.LedPos = 0;
	LED_Desc_cs.TM1637_cs = &TM1637;
}

void LED_Display(uint8_t ledPos)
{
	LED_Desc_cs.TM1637_cs->DataBuffer[0] = ledPos;
}

