/*
 * OS_Schedule.h
 *
 *  Created on: Aug 10, 2019
 *      Author: XuanHung
 */

#ifndef OS_SCHEDULE_H_
#define OS_SCHEDULE_H_

#include "app.h"
#include "adc.h"
#include "LED.h"
#include "LED7.h"
#include "Btn_Mode.h"
#include "Btn_Start.h"
#include "Btn_Train.h"
#include "Buzzer.h"
#include "TM1637.h"

#define SCHED_PROC_10MS		10
#define SCHED_PROC_100MS	100


void OS_Sched_Proc_Ini(void);
void OS_Sched_Proc_10ms(void);
void OS_Sched_Proc_100ms(void);
void OS_Sched_Tick_Increase(void);

#endif /* OS_SCHEDULE_H_ */
