/*
 * LED7.c
 *
 *  Created on: Aug 11, 2019
 *      Author: XuanHung
 *  This LED7 function use with TM1637
 */

#include "LED7.h"
#include "TM1637.h"

#define TM1367_DATA_PORT	GPIOA
#define TM1367_DATA_PIN		GPIO_PIN_2

#define TM1367_CLK_PORT		GPIOA
#define TM1367_CLK_PIN		GPIO_PIN_1


#define LED7_INDEX		1
#define LED7_NUMSEGMENT	4

typedef struct
{
	uint8_t NumSegment;
	uint8_t* DisplayData;
	uint8_t* DefSegment;
	TM1637_Control_Block_t LED7_TM1637_cs;
}LED7_Desc_Block_t;

LED7_Desc_Block_t LED7_Desc_cs;
uint8_t Led7_Display_Buffer[LED7_NUMSEGMENT];

uint8_t NumberToSegmentMap[17] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, // 0-7
    0x7D, 0x6D, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, // 8-9, A-F
    0x00
};

void LED7_PrintNumber(LED7_Desc_Block_t* p_cb,uint16_t number)
{
	p_cb->DisplayData[3] =  p_cb->DefSegment[number%10];
	p_cb->DisplayData[2] =  p_cb->DefSegment[(number/10)%10];
	p_cb->DisplayData[1] =  p_cb->DefSegment[(number/100)%10];
	p_cb->DisplayData[0] =  p_cb->DefSegment[(number/1000)%10];
}

void LED7_Display(uint16_t number)
{
	LED7_PrintNumber(&LED7_Desc_cs,number);
	//TM1637_Display(&LED7_TM1637_cs,LED7_INDEX,LED7_Desc_cs.NumSegment);
}

void LED7_Proc_Ini()
{
	LED7_Desc_cs.LED7_TM1637_cs.ClockPort = TM1367_CLK_PORT;
	LED7_Desc_cs.LED7_TM1637_cs.ClockPin = TM1367_CLK_PIN;
	LED7_Desc_cs.LED7_TM1637_cs.DataPort = TM1367_DATA_PORT;
	LED7_Desc_cs.LED7_TM1637_cs.DataPin = TM1367_DATA_PIN;
	TM1637_Ini(&LED7_Desc_cs.LED7_TM1637_cs);

	LED7_Desc_cs.DefSegment = NumberToSegmentMap;
	LED7_Desc_cs.DisplayData = Led7_Display_Buffer;
	LED7_Desc_cs.NumSegment = LED7_NUMSEGMENT;

	LED7_PrintNumber(&LED7_Desc_cs,0);
}



