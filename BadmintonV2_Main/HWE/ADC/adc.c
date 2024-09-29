/*
 * adc.c
 *
 *  Created on: Dec 25, 2021
 *      Author: XuanHung
 */

#include "adc.h"

#define COMPUTATION_DIGITAL_12BITS_TO_VOLTAGE(ADC_DATA) ( ((ADC_DATA) * VDDA_APPLI) / RANGE_12BITS)
extern ADC_HandleTypeDef hadc;
static uint32_t adcValue;
void ADC_Ini()
{
	/* ADC Channel GPIO pin configuration */
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	if (HAL_ADC_Start_IT(&hadc) != HAL_OK)
	{
	  //Error_Handler();
	}
}


void ADC_Proc()
{

}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	adcValue = HAL_ADC_GetValue(hadc);
}
uint32_t GetAdcValue()
{
	return adcValue;
}
