/*
 * Btn_Train.h
 *
 *  Created on: Dec 25, 2021
 *      Author: XuanHung
 */

#ifndef BTN_TRAIN_H_
#define BTN_TRAIN_H_

#include "TM1637.h"

/*
#define BTN_RELEASE		0x00
#define BTN_1_PRESSED	0x01
#define BTN_2_PRESSED	0x02
#define BTN_3_PRESSED	0x04
#define BTN_4_PRESSED	0x08
#define BTN_5_PRESSED	0x10
#define BTN_6_PRESSED	0x20
#define BTN_7_PRESSED	0x40
#define BTN_8_PRESSED	0x80
*/
#define BTN_RELEASE		0x00
#define BTN_1_PRESSED	0x01
#define BTN_2_PRESSED	0x02
#define BTN_3_PRESSED	0x03
#define BTN_4_PRESSED	0x04
#define BTN_5_PRESSED	0x5
#define BTN_6_PRESSED	0x6
#define BTN_7_PRESSED	0x7
#define BTN_8_PRESSED	0x8

#define BTN_TRAIN_NONE	0xFF	// 1111_1111
#define BTN_TRAIN_1		0xEF	// 1110_1111
#define BTN_TRAIN_2		0x6F	// 0110_1111
#define BTN_TRAIN_3		0xAF	// 1010_1111
#define BTN_TRAIN_4		0x2F	// 0010_1111
#define BTN_TRAIN_5		0xCF	// 1100_1111
#define BTN_TRAIN_6		0x4F	// 0100_1111
#define BTN_TRAIN_7		0x8F	// 1000_1111
#define BTN_TRAIN_8		0x0F	// 0000_1111

typedef struct
{
	uint8_t BtnPos;
	TM1637_Control_Block_t* TM1637_cs;
}BtnTrain_Desc_Block_t;

typedef struct
{

}BtnnTrain_t;

void BtnTrain_Ini(void);
void BtnTrain_Proc(void);
uint8_t GetBtnTrain(void);
#endif /* BTN_TRAIN_H_ */
