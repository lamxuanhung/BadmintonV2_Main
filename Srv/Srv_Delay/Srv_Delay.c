/*
 * Srv_DelayMs.c
 *
 *  Created on: Jul 27, 2019
 *      Author: XuanHung
 */

#include "stm32f0xx_hal.h"
#include "stm32f0xx_hal_tim.h"
#include "main.h"

extern TIM_HandleTypeDef htim3;

void Srv_DelayMs(uint32_t Time_Ms)
{
	HAL_Delay(Time_Ms);
}

void Srv_DelayUs(uint32_t Time_Us)
{
	uint32_t calib;
	if (Time_Us < 10)
	{
		Time_Us = 10;
	}
	calib = Time_Us-2;
	__HAL_TIM_SET_COUNTER(&htim3, 0);
	HAL_TIM_Base_Start(&htim3);
	__disable_irq();
	while (__HAL_TIM_GET_COUNTER(&htim3) < calib);
	__enable_irq();
	HAL_TIM_Base_Stop(&htim3);
}
