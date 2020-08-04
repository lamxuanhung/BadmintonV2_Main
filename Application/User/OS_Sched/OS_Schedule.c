/*
 * OS_Schedule.c
 *
 *  Created on: Aug 10, 2019
 *      Author: XuanHung
 */

#include "stm32f0xx_hal.h"
#include "OS_Schedule.h"

uint8_t OS_Sched_Tick_10ms = 0;
uint8_t OS_Sched_Tick_100ms = 0;

void OS_Sched_Proc_Ini()
{
	OS_Sched_Tick_10ms = 1;
	OS_Sched_Tick_100ms = 0;
}

void OS_Sched_Proc_10ms()
{
	if (OS_Sched_Tick_10ms >= SCHED_PROC_10MS)
	{
		OS_Sched_Tick_10ms = 0;
	}

}
void OS_Sched_Proc_100ms()
{
	if (OS_Sched_Tick_100ms >= SCHED_PROC_100MS)
	{
		LED7_Display(100);
		OS_Sched_Tick_100ms = 0;
	}
}

void OS_Sched_Tick_Increase()
{
	OS_Sched_Tick_10ms++;
	OS_Sched_Tick_100ms++;
}
