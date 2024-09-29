/*
 * Buzzer.c
 *
 *  Created on: Jul 31, 2019
 *      Author: XuanHung
 */

#include "Buzzer.h"


uint16_t currentBuzzerOnPeriod;
uint16_t currentBuzzerOffPeriod;
uint16_t BuzzerOnPeriod;
uint16_t BuzzerOffPeriod;
uint8_t NumberOfBuzzerCycle;
uint8_t  BuzzerState;
static void Buzzer_On();
static void Buzzer_Off();

void Buzzer_Ini()
{
	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = BUZZER_PIN;
	HAL_GPIO_Init(BUZZER_PORT, &GPIO_InitStruct);

	Buzzer_Off();
	Buzzer_Sound(0,0,0);
}

void Buzzer_Proc()
{
	if (NumberOfBuzzerCycle == 0)
	{
		Buzzer_Off();
	}
	else
	{
		if (BuzzerState == BUZZER_ON)
		{
			Buzzer_On();
			if (currentBuzzerOnPeriod>0)
			{
				currentBuzzerOnPeriod--;
			}
			else if (currentBuzzerOnPeriod == 0)
			{
				NumberOfBuzzerCycle--;
				currentBuzzerOnPeriod = BuzzerOnPeriod;
				Buzzer_Off();
			}
		}
		else
		{
			Buzzer_Off();
			if (currentBuzzerOffPeriod>0)
			{
				currentBuzzerOffPeriod--;
			}
			else if (currentBuzzerOffPeriod == 0)
			{
				currentBuzzerOffPeriod = BuzzerOffPeriod;
				Buzzer_On();
			}
		}
	}
}

void Buzzer_Sound(uint16_t OnPeriod, uint16_t OffPeriod, uint8_t Time)
{
	BuzzerOnPeriod = OnPeriod/10;
	currentBuzzerOnPeriod =  OnPeriod/10;
	BuzzerOffPeriod = OffPeriod/10;
	currentBuzzerOffPeriod = OffPeriod/10;
	NumberOfBuzzerCycle = Time;
	BuzzerState = BUZZER_ON;
}

void Buzzer_On()
{
	HAL_GPIO_WritePin(BUZZER_PORT,BUZZER_PIN,GPIO_PIN_SET);
	BuzzerState = BUZZER_ON;
}

void Buzzer_Off()
{
	HAL_GPIO_WritePin(BUZZER_PORT,BUZZER_PIN,GPIO_PIN_RESET);
	BuzzerState = BUZZER_OFF;
}
void Buzzer_Toggle()
{
	HAL_GPIO_TogglePin(BUZZER_PORT,BUZZER_PIN);
}
