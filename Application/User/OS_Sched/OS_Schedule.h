/*
 * OS_Schedule.h
 *
 *  Created on: Aug 10, 2019
 *      Author: XuanHung
 */

#ifndef OS_SCHEDULE_H_
#define OS_SCHEDULE_H_

#define SCHED_PROC_10MS		10
#define SCHED_PROC_100MS	100


void OS_Sched_Proc_Ini();
void OS_Sched_Proc_10ms();
void OS_Sched_Proc_100ms();
void OS_Sched_Tick_Increase();

#endif /* OS_SCHEDULE_H_ */
