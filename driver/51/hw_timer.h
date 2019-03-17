#ifndef __HW_TIMER_H__
#define __HW_TIMER_H__


#include	"common.h"

#define	Timer0						0
#define	Timer1						1
#define	Timer2						2
#define	Timer3						3
#define	Timer4						4


#define	TIM_16BitAutoReload			0
#define	TIM_16Bit					1
#define	TIM_8BitAutoReload			2
#define	TIM_16BitAutoReloadNoMask	3

#define	TIM_CLOCK_1T				0
#define	TIM_CLOCK_12T				1
#define	TIM_CLOCK_Ext				2



uint8 HW_Timer_config(TIME_X timerx, uint32 timeout);

void HW_Time0Start();
void HW_Time0Reload();
void HW_Time1Start();
void HW_Time1Reload();
//void HW_TimexStart(TIME_X timerx);
//void HW_TimexReload(TIME_X timerx);

#endif
