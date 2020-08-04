/*
 * Btn_Start.h
 *
 *  Created on: Jul 21, 2019
 *      Author: XuanHung
 */

#ifndef BTN_START_H
#define BTN_START_H

#include "stm32f0xx_hal.h"
#include "BtnGlb_def.h"

#define BTN_START_ACTIVE_STATE	ACTIVE_LOW

#define BTN_START_GPIO_PORT	GPIOF
#define BTN_START_GPIO_PIN	GPIO_PIN_0

void Btn_Start_Ini(void);
void Btn_Start_Proc(void);
uint8_t Btn_Start_GetState(void);

#endif /* BTN_START_H */
