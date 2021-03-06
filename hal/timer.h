#ifndef __TIMER_H__
#define __TIMER_H__


#include	"common.h"


typedef enum{

	TIMER_0 = 0,
	TIMER_1,
	TIMER_2,
	TIMER_3,
	TIMER_4
	
}TIME_X;

typedef void (*timerEvnCbFun_t)(TIME_X);

int8 timerCbFunQueEmpty();
int8 timerCbFunQueFull();
int8 timerCbFunExce(TIME_X timerx);

int8 registTimerCbFun(TIME_X timerx, uint32 timeoutExc, timerEvnCbFun_t cb);
int8 unregistTimerCbFun(int8 cb_FunID);
uint8 timerRegist(TIME_X timerx, uint32 timeoutExc, timerEvnCbFun_t cb);

void timerxStart(TIME_X timerx);
void timerxReload(TIME_X timerx);

#endif
