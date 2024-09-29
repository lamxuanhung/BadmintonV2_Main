/*
 * BtnTrain.c
 *
 *  Created on: Dec 25, 2021
 *      Author: XuanHung
 */

#include "TM1637.h"
#include "Btn_Train.h"

static uint8_t BtnTrain_Value = 0;
BtnTrain_Desc_Block_t BtnTrain_Desc_cs;

void BtnTrain_Ini(void)
{
	BtnTrain_Desc_cs.BtnPos = BTN_TRAIN_NONE;
	BtnTrain_Desc_cs.TM1637_cs = &TM1637;
}
void BtnTrain_Proc(void)
{
	BtnTrain_Desc_cs.BtnPos = BtnTrain_Desc_cs.TM1637_cs->DataBuffer[5];
	switch (BtnTrain_Desc_cs.BtnPos)
	{
		case BTN_TRAIN_1:
			BtnTrain_Value = BTN_1_PRESSED;
			break;
		case BTN_TRAIN_2:
			BtnTrain_Value = BTN_2_PRESSED;
			break;
		case BTN_TRAIN_3:
			BtnTrain_Value = BTN_3_PRESSED;
			break;
		case BTN_TRAIN_4:
			BtnTrain_Value = BTN_4_PRESSED;
			break;
		case BTN_TRAIN_5:
			BtnTrain_Value = BTN_5_PRESSED;
			break;
		case BTN_TRAIN_6:
			BtnTrain_Value = BTN_6_PRESSED;
			break;
		case BTN_TRAIN_7:
			BtnTrain_Value = BTN_7_PRESSED;
			break;
		case BTN_TRAIN_8:
			BtnTrain_Value = BTN_8_PRESSED;
			break;
		case BTN_TRAIN_NONE:
			BtnTrain_Value = BTN_RELEASE;
			break;
		default:
			break;
	}
}

uint8_t GetBtnTrain()
{
	return BtnTrain_Value;
}
