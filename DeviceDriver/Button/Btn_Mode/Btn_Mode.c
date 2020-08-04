/*
 * Btn_Mode.c
 *
 *  Created on: Jul 21, 2019
 *      Author: XuanHung
 */

#include "Btn_Mode.h"

static uint8_t Btn_stMode = RELEASED;

void Btn_Mode_Ini()
{
	Btn_stMode = RELEASED;
}

void Btn_Mode_Proc()
{
#if (BTN_MODE_ACTIVE_STATE == ACTIVE_LOW)
	if (HAL_GPIO_ReadPin(BTN_MODE_GPIO_PORT,BTN_MODE_GPIO_PIN) == GPIO_PIN_RESET){
		Btn_stMode	= PRESSED;
	}
	else
	{
		Btn_stMode	= RELEASED;
	}
#elif
	if (HAL_GPIO_ReadPin(BTN_MODE_GPIO_PORT,BTN_MODE_GPIO_PIN) == GPIO_PIN_SET){
			Btn_stMode	= PRESSED;
		}
		else
		{
			Btn_stMode	= RELEASED;
		}
#endif
}

uint8_t Btn_Mode_GetState(){
	return Btn_stMode;
}
