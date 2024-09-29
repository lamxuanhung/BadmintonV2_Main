/*
 * Btn_Start.c
 *
 *  Created on: Jul 21, 2019
 *      Author: XuanHung
 */


#include "Btn_Start.h"
#include "Buzzer.h"
#include "DIO.h"
static uint8_t BtnStart_st;
static uint8_t BtnStart_Lock;

void BtnStart_Ini()
{
	DIO_Config_Input(BTN_START_GPIO_PORT,BTN_START_GPIO_PIN);
	BtnStart_st = RELEASED;
	BtnStart_Lock = 0;
}

void BtnStart_Proc()
{
#if (BTN_START_ACTIVE_STATE == ACTIVE_LOW)
	if (HAL_GPIO_ReadPin(BTN_START_GPIO_PORT,BTN_START_GPIO_PIN) == GPIO_PIN_RESET){
		BtnStart_st	= PRESSED;
	}
	else
	{
		BtnStart_st	= RELEASED;
	}
#elif
	if (HAL_GPIO_ReadPin(BTN_START_GPIO_PORT,BTN_START_GPIO_PIN) == GPIO_PIN_SET){
			BtnStart_st	= PRESSED;
		}
		else
		{
			BtnStart_st	= RELEASED;
		}
#endif
}

uint8_t BtnStart_Pressed()
{
	if (BtnStart_Lock == 0)
	{
		if (BtnStart_st == PRESSED)
		{
			Buzzer_Sound(100,100,1);
			BtnStart_Lock = 1;
			return 1;
		}
	}
	else
	{
		if (BtnStart_st == RELEASED)
		{
			BtnStart_Lock = 0;
		}
	}
	return 0;
}
