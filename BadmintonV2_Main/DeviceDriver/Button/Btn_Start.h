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

void BtnStart_Ini(void);
void BtnStart_Proc(void);
uint8_t BtnStart_Pressed(void);
#endif /* BTN_START_H */
