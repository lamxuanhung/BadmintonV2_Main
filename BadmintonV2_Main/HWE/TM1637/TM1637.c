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

#define TM1367_CLK_PORT		GPIOA
#define TM1367_CLK_PIN		GPIO_PIN_1

#define TM1367_DATA_PORT	GPIOA
#define TM1367_DATA_PIN		GPIO_PIN_2

#define TM1637_CMD_DATA_MSK		0x40
#define TM1637_CMD_READKEY_MSK	0x42

#define TM1637_CTL_CMD_MSK		0x80
#define TM1637_ADDR_CMD_MSK		0xC0

TM1637_Control_Block_t TM1637;

void TM1637_BitDelay()
{
	Srv_DelayUs(1);
}

void TM16377_Start()
{
	/* When CLK is a high level and DIO changes from high to low level, data input starts */
	HAL_GPIO_WritePin(TM1367_DATA_PORT,TM1367_DATA_PIN,GPIO_PIN_SET);
	HAL_GPIO_WritePin(TM1367_CLK_PORT, TM1367_CLK_PIN,GPIO_PIN_SET);
	TM1637_BitDelay();
	HAL_GPIO_WritePin(TM1367_DATA_PORT,TM1367_DATA_PIN,GPIO_PIN_RESET);
}

void TM1637_Stop()
{
	/* When CLK is a high level and DIO changes from low level to high level, data input ends */
	HAL_GPIO_WritePin(TM1367_DATA_PORT,TM1367_DATA_PIN,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(TM1367_CLK_PORT, TM1367_CLK_PIN,GPIO_PIN_SET);
	TM1637_BitDelay();
	HAL_GPIO_WritePin(TM1367_DATA_PORT,TM1367_DATA_PIN,GPIO_PIN_SET);
}

void TM1637_Ack()
{
	/*  an answering signal ACK is generated inside the chip to lower the DIO pin at the failing edge of the 8th clock */
	/* Change data pin to  INPUT mode */
	DIO_Config_Input(TM1367_DATA_PORT, TM1367_DATA_PIN);
	if ((HAL_GPIO_ReadPin(TM1367_DATA_PORT,TM1367_DATA_PIN) == GPIO_PIN_RESET))
	{
		/* Set clock to LOW*/
		HAL_GPIO_WritePin(TM1367_CLK_PORT, TM1367_CLK_PIN,GPIO_PIN_SET);
		TM1637_BitDelay();
		/* Set clock to HIGH*/
		HAL_GPIO_WritePin(TM1367_CLK_PORT, TM1367_CLK_PIN,GPIO_PIN_RESET);
		TM1637_BitDelay();
	}
	DIO_Config_Output(TM1367_DATA_PORT, TM1367_DATA_PIN);
}
void TM1637_WriteByte(uint8_t Data)
{
	uint8_t data_temp = Data;
	uint8_t i;

	HAL_GPIO_WritePin(TM1367_CLK_PORT, TM1367_CLK_PIN,GPIO_PIN_RESET);
	/* 8 Data Bits */
	for(i = 0; i < 8; i++)
	{
		if (data_temp & 0x01)
		{
			HAL_GPIO_WritePin(TM1367_DATA_PORT,TM1367_DATA_PIN,GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(TM1367_DATA_PORT,TM1367_DATA_PIN,GPIO_PIN_RESET);
		}

		HAL_GPIO_WritePin(TM1367_CLK_PORT, TM1367_CLK_PIN,GPIO_PIN_SET);
		TM1637_BitDelay();
		HAL_GPIO_WritePin(TM1367_CLK_PORT, TM1367_CLK_PIN,GPIO_PIN_RESET);
		data_temp = data_temp >> 1;
	}
}

void TM1637_SetBrightness(uint8_t brightness, uint8_t on)
{
	TM1637.Brightness = (brightness & 0x7) | (on? 0x08 : 0x00);
}


/*
    SEG1 SEG2 SEG3 SEG4	SEG5 SEG6 SEG7 SEG8
	xxHL（low four bits） 	xxHU(high four bits)
	B0 B1 B2 B3 		B4 B5 B6 B7
	C0HL 				C0HU 					GRID1
	C1HL 				C1HU 					GRID2
	C2HL 				C2HU 					GRID3
	C3HL 				C3HU 					GRID4
	C4HL 				C4HU 					GRID5
	C5HL 				C5HU 					GRID6
 	PosDigit : Start register, which will be write
 	NumDigit : Number of led7 digit will be dispaly
 */
void TM1637_Display()
{
	uint8_t i;
    /* Write COMM1	*/
	TM16377_Start();
	/* Write data to display regiter with auto address adding*/
	TM1637_WriteByte(TM1637_CMD_DATA_MSK);
	TM1637_Ack();
	TM1637_Stop();

	/* Write COMM2 + first digit address */
	TM16377_Start();
	/* Write the data to display */
	TM1637_WriteByte(TM1637_ADDR_CMD_MSK);
	TM1637_Ack();
	for (i=0; i < 5; i++)
	{
		/* Write address command, start from CH */
		TM1637_WriteByte(TM1637.DataBuffer[i]);
		TM1637_Ack();
	}
	TM1637_Stop();

	/* Write COMM3 + brightness	*/
	TM16377_Start();
	TM1637_WriteByte((TM1637_CTL_CMD_MSK | 0x08) + (TM1637.Brightness & 0x07));
	TM1637_Ack();
	TM1637_Stop();

}

void TM1637_ReadKey()
{
	uint8_t data_temp = 0;
    /* Write Read key command */
	TM16377_Start();
	TM1637_WriteByte(TM1637_CMD_READKEY_MSK);
	DIO_Config_Input(TM1367_DATA_PORT, TM1367_DATA_PIN);
	for(uint8_t i = 0; i < 8; i++)
	{
		data_temp = data_temp << 1 ;
		HAL_GPIO_WritePin(TM1367_CLK_PORT, TM1367_CLK_PIN,GPIO_PIN_RESET);
		if (HAL_GPIO_ReadPin(TM1367_DATA_PORT,TM1367_DATA_PIN) == GPIO_PIN_SET)
		{
			data_temp |= 0x01;
		}
		TM1637_BitDelay();
		HAL_GPIO_WritePin(TM1367_CLK_PORT, TM1367_CLK_PIN,GPIO_PIN_SET);
		TM1637_BitDelay();
	}
	HAL_GPIO_WritePin(TM1367_CLK_PORT, TM1367_CLK_PIN,GPIO_PIN_RESET);
	DIO_Config_Output(TM1367_DATA_PORT,TM1367_DATA_PIN);
	HAL_GPIO_WritePin(TM1367_DATA_PORT,TM1367_DATA_PIN,GPIO_PIN_RESET);
	TM1637_BitDelay();
	HAL_GPIO_WritePin(TM1367_CLK_PORT, TM1367_CLK_PIN,GPIO_PIN_SET);
	TM1637_BitDelay();
	TM1637_Stop();
}

void TM1637_Clear()
{
	uint8_t i;
	for (i=0; i < (TM1637_LED_SEGMENT +TM1637_KEY_SEGMENT); i++)
	{
		TM1637.DataBuffer[i] = 0;
	}
}

void TM1637_Ini()
{
	uint8_t i=0;
	TM1637.Brightness = 5;
	for (i=0; i< (TM1637_LED_SEGMENT +TM1637_KEY_SEGMENT) ; i++)
	{
		TM1637.DataBuffer[i] = 0x00;
	}

	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

	GPIO_InitStruct.Pin = TM1367_CLK_PIN;
	HAL_GPIO_Init(TM1367_CLK_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin =TM1367_DATA_PIN;
	HAL_GPIO_Init(TM1367_DATA_PORT, &GPIO_InitStruct);

	HAL_GPIO_WritePin(TM1367_CLK_PORT, TM1367_CLK_PIN,GPIO_PIN_SET);
	HAL_GPIO_WritePin(TM1367_DATA_PORT,TM1367_DATA_PIN,GPIO_PIN_SET);
}

void TM1637_Proc()
{
	uint8_t i;
	/* Write COMM1	*/
	TM16377_Start();
	/* Write data to display regiter with auto address adding*/
	TM1637_WriteByte(TM1637_CMD_DATA_MSK);
	TM1637_Ack();
	TM1637_Stop();

	/* Write COMM2 + first digit address */
	TM16377_Start();
	/* Write the data to display */
	TM1637_WriteByte(TM1637_ADDR_CMD_MSK);
	TM1637_Ack();
	for (i=0; i < TM1637_LED_SEGMENT; i++)
	{
		/* Write address command, start from CH */
		TM1637_WriteByte(TM1637.DataBuffer[i]);
		TM1637_Ack();
	}
	TM1637_Stop();

	/* Write COMM3 + brightness	*/
	TM16377_Start();
	TM1637_WriteByte((TM1637_CTL_CMD_MSK | 0x08) + (TM1637.Brightness & 0x07));
	TM1637_Ack();
	TM1637_Stop();

	/* Send read key command */
	TM16377_Start();
	TM1637_WriteByte(TM1637_CMD_READKEY_MSK);
	TM1637_Ack();
	DIO_Config_Input(TM1367_DATA_PORT, TM1367_DATA_PIN);
	for(i = 0; i < 8; i++)
	{
		TM1637.DataBuffer[5] = TM1637.DataBuffer[5] << 1 ;
		HAL_GPIO_WritePin(TM1367_CLK_PORT, TM1367_CLK_PIN,GPIO_PIN_RESET);
		if (HAL_GPIO_ReadPin(TM1367_DATA_PORT,TM1367_DATA_PIN) == GPIO_PIN_SET)
		{
			TM1637.DataBuffer[5] |= 0x01;
		}
		TM1637_BitDelay();
		HAL_GPIO_WritePin(TM1367_CLK_PORT, TM1367_CLK_PIN,GPIO_PIN_SET);
		TM1637_BitDelay();
	}
	TM1637_Ack();
	HAL_GPIO_WritePin(TM1367_CLK_PORT, TM1367_CLK_PIN,GPIO_PIN_SET);
	TM1637_Stop();
}
