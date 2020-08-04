/*
 * Btn_Start.c
 *
 *  Created on: Jul 21, 2019
 *      Author: XuanHung
 */


#include "Btn_Start.h"

static uint8_t Btn_stStart = RELEASED;

void Btn_Start_Ini()
{
	Btn_stStart = RELEASED;
}

void Btn_Start_Proc()
{
#if (BTN_START_ACTIVE_STATE == ACTIVE_LOW)
	if (HAL_GPIO_ReadPin(BTN_START_GPIO_PORT,BTN_START_GPIO_PIN) == GPIO_PIN_RESET){
		Btn_stStart	= PRESSED;
	}
	else
	{
		Btn_stStart	= RELEASED;
	}
#elif
	if (HAL_GPIO_ReadPin(BTN_START_GPIO_PORT,BTN_START_GPIO_PIN) == GPIO_PIN_SET){
			Btn_stStart	= PRESSED;
		}
		else
		{
			Btn_stStart	= RELEASED;
		}
#endif
}

uint8_t Btn_Start_GetState(){
	return Btn_stStart;
}
