#ifndef __PWM_H__
#define __PWM_H__


#include	"common.h"
#include  "hal/timer.h"

void ServoPwmInterruptProc(TIME_X timerx);
void resetServoPulCnt();
void setServoPulseWidth(uint16 cnt);
void setServoCtlPin(uint8 pin);
void uartCmdProc(void *uartData);

#endif
