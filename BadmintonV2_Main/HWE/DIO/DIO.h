/*
 * DIO.h
 *
 *  Created on: Jul 27, 2019
 *      Author: XuanHung
 */

#ifndef DIO_H_
#define DIO_H_

void DIO_Config_Input(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void DIO_Config_Output(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif /* DIO_H_ */
