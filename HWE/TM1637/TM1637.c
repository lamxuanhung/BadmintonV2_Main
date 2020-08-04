/*
 * TM1637.c
 *
 *  Created on: Jul 27, 2019
 *      Author: XuanHung
 */


#include "TM1637.h"
#include "Srv_Delay.h"
#include "DIO.h"
#include "Uart.h"


#define TM1637_CMD_DATA_MSK		0x40
#define TM1637_CMD_READKEY_MSK	0x42

#define TM1637_CTL_CMD_MSK		0x80
#define TM1637_ADDR_CMD_MSK		0xC0


void TM1637_BitDelay()
{
	Srv_DelayUs(10);
}

void TM16377_Start(TM1637_Control_Block_t* p_cb)
{
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_SET);
	HAL_GPIO_WritePin(p_cb->DataPort, p_cb->DataPin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_RESET);
}

void TM1637_Stop(TM1637_Control_Block_t* p_cb)
{
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_SET);
	HAL_GPIO_WritePin(p_cb->ClockPort, p_cb->ClockPin,GPIO_PIN_RESET);
	TM1637_BitDelay();
	HAL_GPIO_WritePin(p_cb->ClockPort, p_cb->ClockPin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(p_cb->DataPort, p_cb->DataPin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_RESET);
}

void TM1637_WriteByte(TM1637_Control_Block_t* p_cb,uint8_t Data)
{
	uint8_t data_temp = Data;
	uint8_t i;

	HAL_GPIO_WritePin(p_cb->ClockPort, p_cb->ClockPin,GPIO_PIN_RESET);
	// 8 Data Bits
	for(i = 0; i < 8; i++)
	{
		if (data_temp & 0x01)
		{
			HAL_GPIO_WritePin(p_cb->DataPort, p_cb->DataPin,GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(p_cb->DataPort, p_cb->DataPin,GPIO_PIN_RESET);
		}
		TM1637_BitDelay();
		HAL_GPIO_WritePin(p_cb->ClockPort, p_cb->ClockPin,GPIO_PIN_SET);
		TM1637_BitDelay();
		HAL_GPIO_WritePin(p_cb->ClockPort, p_cb->ClockPin,GPIO_PIN_RESET);
		data_temp = data_temp >> 1;
	}
	HAL_GPIO_WritePin(p_cb->DataPort, p_cb->DataPin,GPIO_PIN_RESET);
	TM1637_BitDelay();
	HAL_GPIO_WritePin(p_cb->ClockPort, p_cb->ClockPin,GPIO_PIN_SET);
	TM1637_BitDelay();
}

void TM1637_SetBrightness(TM1637_Control_Block_t* p_cb,uint8_t brightness, uint8_t on)
{
	p_cb->Brightness = (brightness & 0x7) | (on? 0x08 : 0x00);
}

void TM1637_Display(TM1637_Control_Block_t* p_cb,uint8_t PosDigit,uint8_t NumDigit)
{
	uint8_t i;
    // Write COMM1
	TM16377_Start(p_cb);
	TM1637_WriteByte(p_cb,TM1637_CMD_DATA_MSK);
	TM1637_Stop(p_cb);

	// Write COMM2 + first digit address
	TM16377_Start(p_cb);
	TM1637_WriteByte(p_cb,TM1637_ADDR_CMD_MSK + (PosDigit & 0x07));
	// Write the data bytes
	for (i=0; i < NumDigit; i++)
	{
		TM1637_WriteByte(p_cb,p_cb->LedSegment[i+PosDigit]);

	}
	TM1637_Stop(p_cb);

	// Write COMM3 + brightness
	TM16377_Start(p_cb);
	TM1637_WriteByte(p_cb,((TM1637_CTL_CMD_MSK | 0x08) + (p_cb->Brightness & 0x0f)));
	TM1637_Stop(p_cb);

}

void TM1637_ReadKey(TM1637_Control_Block_t* p_cb)
{
	uint8_t data_temp = 0;
    // Write COMMAND
	TM16377_Start(p_cb);
	TM1637_WriteByte(p_cb,TM1637_CMD_READKEY_MSK);

	DIO_Config_Input(p_cb->DataPort,p_cb->DataPin);
	for(uint8_t i = 0; i < 8; i++)
	{
		data_temp = data_temp << 1 ;
		HAL_GPIO_WritePin(p_cb->ClockPort, p_cb->ClockPin,GPIO_PIN_RESET);
		if (HAL_GPIO_ReadPin(p_cb->DataPort,p_cb->DataPin) == GPIO_PIN_SET)
		{
			data_temp |= 0x01;
		}
		TM1637_BitDelay();
		HAL_GPIO_WritePin(p_cb->ClockPort, p_cb->ClockPin,GPIO_PIN_SET);
		TM1637_BitDelay();
	}
	HAL_GPIO_WritePin(p_cb->ClockPort, p_cb->ClockPin,GPIO_PIN_RESET);
	DIO_Config_Output(p_cb->DataPort,p_cb->DataPin);
	HAL_GPIO_WritePin(p_cb->DataPort, p_cb->DataPin,GPIO_PIN_RESET);
	TM1637_BitDelay();
	HAL_GPIO_WritePin(p_cb->ClockPort, p_cb->ClockPin,GPIO_PIN_SET);
	TM1637_BitDelay();
	TM1637_Stop(p_cb);
	p_cb->KeySegment = data_temp;
}

void TM1637_Clear(TM1637_Control_Block_t* p_cb)
{
	for (uint8_t i=0; i<TM1637_MAX_LEDSEGMENT ; i++)
	{
		p_cb->LedSegment[i] = 0;
	}
}

void TTM1637_ShowDots(TM1637_Control_Block_t* p_cb,uint8_t Index)
{
	p_cb->LedSegment[Index] |= 0x80;
}


void TM1637_Ini(TM1637_Control_Block_t* p_cb)
{
	uint8_t i=0;
	p_cb->Brightness = 5;
	p_cb->ShowDot = 0;
	for (i=0; i<TM1637_MAX_LEDSEGMENT ; i++)
	{
		p_cb->LedSegment[i] = 0x00;
	}
	p_cb->KeySegment = 0;

	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

	GPIO_InitStruct.Pin = p_cb->ClockPin;
	HAL_GPIO_Init(p_cb->ClockPort, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = p_cb->DataPin;
	HAL_GPIO_Init(p_cb->DataPort, &GPIO_InitStruct);

	TM1637_Display(p_cb,0,TM1637_MAX_LEDSEGMENT);
}

void TM1637_Proc()
{

}
