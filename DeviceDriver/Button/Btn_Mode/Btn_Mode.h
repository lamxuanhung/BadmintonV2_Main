#ifndef BTN_MODE_H
#define BTN_MODE_H

#include "stm32f0xx_hal.h"
#include "BtnGlb_def.h"

#define BTN_MODE_ACTIVE_STATE	ACTIVE_LOW

#define BTN_MODE_GPIO_PORT	GPIOF
#define BTN_MODE_GPIO_PIN	GPIO_PIN_1

void Btn_Mode_Ini(void);
void Btn_Mode_Proc(void);
uint8_t Btn_Mode_GetState(void);

#endif
