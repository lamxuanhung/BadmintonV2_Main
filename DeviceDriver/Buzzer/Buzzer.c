/*
 * Buzzer.c
 *
 *  Created on: Jul 31, 2019
 *      Author: XuanHung
 */

#include "Buzzer.h"
typedef struct
{
	GPIO_TypeDef* BuzzerPort;
	uint16_t BuzzerPin;
	uint32_t Buzzer_Period;
	uint8_t Buzzer_DutyCycle;
	uint8_t Buzzer_stActive;
}Buzzer_Control_Block_t;

void Buzzer_Ini(Buzzer_Control_Block_t* p_cb)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	p_cb->Buzzer_Period = 0;
	p_cb->Buzzer_DutyCycle = 0;
	p_cb->Buzzer_stActive = 0;

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = p_cb->BuzzerPin;
	HAL_GPIO_Init(p_cb->BuzzerPort, &GPIO_InitStruct);
}

void Buzzer_Proc()
{

}

void Buzzer_Config(Buzzer_Control_Block_t* p_cb,uint32_t Period,uint8_t DutyCycle)
{
	p_cb->Buzzer_Period = Period;
	p_cb->Buzzer_DutyCycle = DutyCycle;
}

void Buzzer_Sound(Buzzer_Control_Block_t* p_cb,uint8_t Times)
{

}
void Buzzer_Off(Buzzer_Control_Block_t* p_cb,uint32_t Period,uint8_t DutyCycle)
{
}
