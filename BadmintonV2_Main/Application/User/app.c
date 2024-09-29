/*
 * App.c
 *
 *  Created on: Dec 25, 2021
 *      Author: XuanHung
 */

#include "stm32f0xx_hal.h"
#include <stdlib.h>
#include "app.h"
#include "adc.h"
#include "Uart.h"
#include "LED.h"
#include "LED7.h"
#include "Buzzer.h"
#include "Btn_Mode.h"
#include "Btn_Start.h"
#include "Btn_Train.h"

#define TRAIN_POS_1		0x01
#define TRAIN_POS_2		0x02
#define TRAIN_POS_3		0x04
#define TRAIN_POS_4		0x08
#define TRAIN_POS_5		0x10
#define TRAIN_POS_6		0x20
#define TRAIN_POS_7		0x40
#define TRAIN_POS_8		0x80
#define TRAIN_POS_OFF	0x00

#define SM_SETUP_INIT		0
#define SM_SETUP_TRAIN_POS	1
#define SM_SETUP_SPEED		2
#define SM_SETUP_TIME		3
#define SM_PRERUN			4
#define SM_READY			5
#define SM_RUN				6
#define SM_STOP				7

static void SetupTraniningPos();
void SetCountDownSecond(uint16_t time_second);
void SetCountDownHalfSecond(uint16_t time_halfsecond);
void SetCountDown100ms(uint8_t time_100ms);
void TrainingBegin();
uint16_t CalculateStepTime(uint32_t adcValue);
uint16_t ConvertADCToSpeed(uint32_t adcValue);
uint16_t ConvertADCToTime(uint32_t adcValue);
uint8_t ProcessTrainingPosition(uint8_t TrainPosSetting);
uint8_t appState = 0;

uint8_t appMode;
uint8_t BtnTrain_isLock;

uint16_t countHalfSecond;
uint16_t countSecond;

#define TRANINIG_MAX_POSITION	8
uint8_t Training_Setting_Position = 0;
uint8_t Training_Setting_Speed;
uint8_t Training_Setting_Time;
uint8_t Training_Countdown_Time;
uint8_t Traninig_Start_Flag;
uint8_t Traning_Court_Count;
uint8_t Training_Running_Position[TRANINIG_MAX_POSITION];

#define TOTAL_SPEED_STEP	20
uint8_t ConvertSpeedToSecond[TOTAL_SPEED_STEP];
#define TOTAL_TIME_STEP		59
uint16_t ConvertTimeToSecond[TOTAL_TIME_STEP];


void Application_Ini()
{
	uint8_t i;
	LED7_Display(0);
	LED_Display(0);
	appMode = 0;
	appState = SM_SETUP_INIT;
	Training_Setting_Position = TRAIN_POS_1|TRAIN_POS_3|TRAIN_POS_6|TRAIN_POS_8;
	Traning_Court_Count = ProcessTrainingPosition(Training_Setting_Position);
	BtnTrain_isLock = 0;
	Training_Setting_Speed = 2;
	Training_Setting_Time = 60;
	Training_Countdown_Time = 0;
	for (i=0; i < TOTAL_SPEED_STEP;i++)
	{
		ConvertSpeedToSecond[i] = 5 + i*5;
	}
	for (i=0; i < TOTAL_TIME_STEP;i++)
	{
		ConvertTimeToSecond[i] = 10 + i*5;
	}
	countHalfSecond = 0;
}

void Application_Proc()
{
	switch (appState)
	{
		case SM_SETUP_INIT:
			LED_Display(Training_Setting_Position);

			appState = SM_SETUP_SPEED;
			break;
		case SM_SETUP_TRAIN_POS:
			SetupTraniningPos();
			if (BtnMode_Pressed())
			{
				appState = SM_SETUP_SPEED;
			}
			else if (BtnStart_Pressed())
			{
				appState = SM_PRERUN;
			}
			break;
		case SM_SETUP_SPEED:
			SetupTraniningPos();
			if (BtnMode_Pressed())
			{
				appState = SM_SETUP_TIME;
			}
			else if (BtnStart_Pressed())
			{
				appState = SM_PRERUN;
			}
			Training_Setting_Speed = CalculateStepTime(GetAdcValue());
			LED7_DisplaySpeed(Training_Setting_Speed);
			break;
		case SM_SETUP_TIME:
			SetupTraniningPos();

			if (BtnMode_Pressed())
			{
				appState = SM_SETUP_SPEED;
			}
			else if (BtnStart_Pressed())
			{
				appState = SM_PRERUN;
			}
			Training_Setting_Time = ConvertADCToTime(GetAdcValue());
			LED7_Display(Training_Setting_Time);
			break;
		case SM_PRERUN:
			Training_Countdown_Time = Training_Setting_Time;
			Traning_Court_Count = ProcessTrainingPosition(Training_Setting_Position);
			Uart_SendByte(Traning_Court_Count);
			SetCountDownSecond(3);
			LED_Display(0);
			appState = SM_READY;
			break;
		case SM_READY:
			LED7_Display(countSecond/10);
			if (countSecond == 0)
			{
				Buzzer_Sound(50,50,3);
				SetCountDownHalfSecond(Training_Setting_Speed);
				LED_Display(Training_Running_Position[rand()%Traning_Court_Count]);
				appState = SM_RUN;
			}
			break;
		case SM_RUN:
			if (BtnStart_Pressed())
			{
				appState = SM_STOP;
			}
			TrainingBegin();
			break;
		case SM_STOP:
			appState = SM_SETUP_SPEED;
			break;
		default:
			break;

	}
}

void SetupTraniningPos()
{
	if (BtnTrain_isLock == 0)
	{
		if (GetBtnTrain() == BTN_1_PRESSED)
		{
			Training_Setting_Position ^= TRAIN_POS_1;
			Buzzer_Sound(50,50,1);
		}
		else if (GetBtnTrain() == BTN_2_PRESSED)
		{
			Training_Setting_Position ^= TRAIN_POS_2;
			Buzzer_Sound(50,50,1);
		}
		else if (GetBtnTrain() == BTN_3_PRESSED)
		{
			Training_Setting_Position ^= TRAIN_POS_3;
			Buzzer_Sound(50,50,1);
		}
		else if (GetBtnTrain() == BTN_4_PRESSED)
		{
			Training_Setting_Position ^= TRAIN_POS_4;
			Buzzer_Sound(50,50,1);
		}
		else if (GetBtnTrain() == BTN_5_PRESSED)
		{
			Training_Setting_Position ^= TRAIN_POS_5;
			Buzzer_Sound(50,50,1);
		}
		else if (GetBtnTrain() == BTN_6_PRESSED)
		{
			Training_Setting_Position ^= TRAIN_POS_6;
			Buzzer_Sound(50,50,1);
		}
		else if (GetBtnTrain() == BTN_7_PRESSED)
		{
			Training_Setting_Position ^= TRAIN_POS_7;
			Buzzer_Sound(50,50,1);
		}
		else if (GetBtnTrain() == BTN_8_PRESSED)
		{
			Training_Setting_Position ^= TRAIN_POS_8;
			Buzzer_Sound(50,50,1);
		}
		BtnTrain_isLock = 1;
	}
	else
	{
		if (GetBtnTrain() == BTN_RELEASE)
		{
			BtnTrain_isLock = 0;
		}
	}
	LED_Display(Training_Setting_Position);
}


#define SPEED_STEP	205
#define TIME_STEP	70

/* Convert 20 steps, then each step = 205 */
uint16_t ConvertADCToSpeed(uint32_t adcValue)
{
	return (adcValue / (SPEED_STEP));
}

uint16_t ConvertADCToTime(uint32_t adcValue)
{
	/* Convert 59 steps, then each step = 70*/
	return (adcValue / (TIME_STEP));
}

/* ADC value -> chia ra cac muc tu 0-> 19 tuong ung  1s -> 10s voi moi buoc tang 0.5s -> quy doi ra 10 -> 100 */
uint16_t CalculateStepTime(uint32_t adcValue)
{
	uint16_t temp;
	temp = ConvertADCToSpeed(adcValue);
	return ConvertSpeedToSecond[temp];
}

uint8_t ProcessTrainingPosition(uint8_t TrainPosSetting)
{
	uint8_t i;
	uint8_t posIdx = 0;
	uint8_t temp;
	memset(Training_Running_Position,0,TRANINIG_MAX_POSITION);
	for (i=0;i<TRANINIG_MAX_POSITION;i++)
	{
		temp = TrainPosSetting & (1<<i);
		if (temp == (1<<i))
		{
			Training_Running_Position[posIdx] = temp;
			posIdx++;
		}
	}
	return posIdx;
}

void DecreaseCountHalfSecond()
{
	if (countHalfSecond > 0)
	{
		countHalfSecond--;
	}
}
void DecreaseCountSecond()
{
	if (countSecond > 0)
	{
		countSecond--;
	}
}
void SetCountDownSecond(uint16_t time_second)
{
	/* Increase 100ms per raster, then input value need multiple 10  */
	countSecond = time_second*10;
}
void SetCountDownHalfSecond(uint16_t time_halfsecond)
{
	/* Increase 100ms per raster, then input value need multiple 5  */
	countHalfSecond = time_halfsecond;
}
void SetCountDown100ms(uint8_t time_100ms)
{

}

uint8_t check = 0;
uint8_t randomValue;
void TrainingBegin()
{
	LED7_DisplaySpeed(countHalfSecond);

	/* Display led off soon 200ms*/
	if (countHalfSecond <2 && countHalfSecond>0)
	{
		LED_Display(0);
	}
	else if (countHalfSecond == 0)
	{
		LED_Display(Training_Running_Position[rand()%Traning_Court_Count]);
		SetCountDownHalfSecond(Training_Setting_Speed);
		Buzzer_Sound(50,50,2);
	}
}



