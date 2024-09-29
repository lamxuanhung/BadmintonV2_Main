/*
 * Buzzer.h
 *
 *  Created on: Jul 31, 2019
 *      Author: XuanHung
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "stm32f0xx_hal.h"

#define BUZZER_PORT	GPIOB
#define BUZZER_PIN	GPIO_PIN_1

#define BUZZER_ON	1
#define BUZZER_OFF	0

void Buzzer_Ini(void);
void Buzzer_Proc(void);
void Buzzer_Sound(uint16_t OnPeriod, uint16_t OffPeriod, uint8_t Time);
void Buzzer_Toggle();
#endif /* BUZZER_H_ */
