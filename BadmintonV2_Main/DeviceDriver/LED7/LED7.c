/*
 * LED7.c
 *
 *  Created on: Aug 11, 2019
 *      Author: XuanHung
 *  This LED7 function use with TM1637
 */

#include "LED7.h"

static void LED7_PrintNumber(LED7_Desc_Block_t* p_cb,uint16_t number);

LED7_Desc_Block_t LED7_Desc_cs;
/*
uint8_t SegmentMap[17] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
    0x7D, 0x6D, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71,
    0x00
};
*/
uint8_t SegmentMap[17] = {
    0x3F, // 0
	0x06, // 1
	0x5B, // 2
	0x4F, // 3
	0x66, // 4
	0x6D, // 5
	0x7D, // 6
	0x07, // 7
    0x7F, // 8
	0x6F, // 9
	0x77, // A
	0x7C, // B
	0x39, // C
	0x5E, // D
	0x79, // E
	0x71, // F
    0x00  // 0ff
};


void LED7_PrintNumber(LED7_Desc_Block_t* p_cb,uint16_t number)
{
	if (number > 999)
	{
		p_cb->TM1637_cs->DataBuffer[4] =  p_cb->DefSegment[number%10];
		p_cb->TM1637_cs->DataBuffer[3] =  p_cb->DefSegment[(number/10)%10];
		p_cb->TM1637_cs->DataBuffer[2] =  p_cb->DefSegment[(number/100)%10];
		p_cb->TM1637_cs->DataBuffer[1] =  p_cb->DefSegment[(number/1000)%10];
	}
	else if (number > 99)
	{
		p_cb->TM1637_cs->DataBuffer[4] =  p_cb->DefSegment[number%10];
		p_cb->TM1637_cs->DataBuffer[3] =  p_cb->DefSegment[(number/10)%10];
		p_cb->TM1637_cs->DataBuffer[2] =  p_cb->DefSegment[(number/100)%10];
		p_cb->TM1637_cs->DataBuffer[1] =  p_cb->DefSegment[16];
	}
	else if (number > 9)
	{
		p_cb->TM1637_cs->DataBuffer[4] =  p_cb->DefSegment[number%10];
		p_cb->TM1637_cs->DataBuffer[3] =  p_cb->DefSegment[(number/10)%10];
		p_cb->TM1637_cs->DataBuffer[2] =  p_cb->DefSegment[16];
		p_cb->TM1637_cs->DataBuffer[1] =  p_cb->DefSegment[16];
	}
	else
	{
		p_cb->TM1637_cs->DataBuffer[4] =  p_cb->DefSegment[number%10];
		p_cb->TM1637_cs->DataBuffer[3] =  p_cb->DefSegment[16];
		p_cb->TM1637_cs->DataBuffer[2] =  p_cb->DefSegment[16];
		p_cb->TM1637_cs->DataBuffer[1] =  p_cb->DefSegment[16];
	}
}

void LED7_Display(uint16_t number)
{
	LED7_PrintNumber(&LED7_Desc_cs,number);
}

void LED7_PrintSpeed(LED7_Desc_Block_t* p_cb,uint16_t speed)
{
	if (speed > 99)
	{
		p_cb->TM1637_cs->DataBuffer[4] =  p_cb->DefSegment[speed%10];
		p_cb->TM1637_cs->DataBuffer[3] =  p_cb->DefSegment[(speed/10)%10]| 0x80;
		p_cb->TM1637_cs->DataBuffer[2] =  p_cb->DefSegment[(speed/100)%10];
		p_cb->TM1637_cs->DataBuffer[1] =  p_cb->DefSegment[16];
	}
	else {
		p_cb->TM1637_cs->DataBuffer[4] =  p_cb->DefSegment[speed%10];
		p_cb->TM1637_cs->DataBuffer[3] =  p_cb->DefSegment[(speed/10)%10] | 0x80;
		p_cb->TM1637_cs->DataBuffer[2] =  p_cb->DefSegment[16] ;
		p_cb->TM1637_cs->DataBuffer[1] =  p_cb->DefSegment[16];
	}
}
/* Training speed from 1s to 10s, with stepping 0.5*/
void LED7_DisplaySpeed(uint8_t speed)
{
	LED7_PrintSpeed(&LED7_Desc_cs,speed);

}
void LED7_Ini()
{
	LED7_Desc_cs.TM1637_cs = &TM1637;
	LED7_Desc_cs.DefSegment = SegmentMap;
	TM1637_Ini(&LED7_Desc_cs.TM1637_cs);
	LED7_PrintNumber(&LED7_Desc_cs,0);
}



