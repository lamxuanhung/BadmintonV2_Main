/*
 * adc.h
 *
 *  Created on: Dec 25, 2021
 *      Author: XuanHung
 */

#ifndef ADC_H_
#define ADC_H_

#include "stm32f0xx_hal.h"

#define VDDA_APPLI                     ((uint32_t) 3300)    /* Value of analog voltage supply Vdda (unit: mV) */
#define RANGE_12BITS                   ((uint32_t) 4095)    /* Max digital value with a full range of 12 bits */

void ADC_Ini(void);
void ADC_Proc(void);
uint32_t GetAdcValue();

#endif /* ADC_H_ */
