#ifndef BTN_MODE_H
#define BTN_MODE_H

#include "stm32f0xx_hal.h"
#include "BtnGlb_def.h"

#define BTN_MODE_ACTIVE_STATE	ACTIVE_LOW

#define BTN_MODE_GPIO_PORT	GPIOF
#define BTN_MODE_GPIO_PIN	GPIO_PIN_1

void BtnMode_Ini(void);
void BtnMode_Proc(void);
uint8_t BtnMode_Pressed();
#endif
