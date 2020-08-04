/*
 * Src_VirTimer.c
 *
 *  Created on: Aug 10, 2019
 *      Author: XuanHung
 */

#include "stm32f0xx_hal.h"

typedef struct
{
	uint32_t Period;
	uint8_t Status;
}VirTimer_Control_Block_t;

void Srv_VirTimer_Ini(VirTimer_Control_Block_t* p_cb)
{
	p_cb->Period = 0;
	p_cb->Status = 0;
}

void Srv_VirTimer_Proc()
{

}

void Srv_VirTimer_Set(VirTimer_Control_Block_t* p_cb,uint32_t Period)
{
	p_cb->Period = Period;
}
